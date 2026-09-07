// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmetrackgroup.cpp
// Functions: 22
// ============================================================

#include "movieobjects\dmetrackgroup.h"

//------------------------------------------------------------------------------
// Address: 0x004B8CC0
// Name: public: void CDmeTrackGroup::SetMaxTrackCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::SetMaxTrackCount(CDmeTrackGroup *this, int nCount)
{
  this->m_nMaxTrackCount = nCount;
}

//------------------------------------------------------------------------------
// Address: 0x004B8D80
// Name: protected: void CDmeTrackGroup::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::OnConstruction(CDmeTrackGroup *this)
{
  CDmaElementArray<CDmeTrack> *p_m_Tracks; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  float v8; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  p_m_Tracks = &this->m_Tracks;
  this->m_Tracks.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "tracks",
                                  type: AT_FIRST_ARRAY_TYPE,
                                  pMemory: &this->m_Tracks);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Tracks->m_pAttribute, typeSymbol: CDmeTrack::m_classType);
  p_m_Tracks->m_pAttribute->m_nFlags |= 0x900u;
  value = true;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_bIsVisible);
  this->m_bIsVisible.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_bMute.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "mute",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bMute);
  v8 = 1.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "displayScale",
         type: AT_FLOAT,
         pMemory: &this->m_flDisplayScale);
  this->m_flDisplayScale.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, value: &v8);
  value = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "minimized", type: AT_BOOL, pMemory: &this->m_bMinimized);
  this->m_bMinimized.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  this->m_nMaxTrackCount = 0x7FFFFFFF;
  v8 = 1.0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "volume", type: AT_FLOAT, pMemory: &this->m_Volume);
  this->m_Volume.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: &v8);
  value = false;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "forcemultitrack",
         type: AT_BOOL,
         pMemory: &this->m_bForceMultiTrack);
  this->m_bForceMultiTrack.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004B8F40
// Name: public: class CDmeTrack __near * CDmeTrackGroup::AddTrack(char const __near *,enum DmeClipType_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::AddTrack(CDmeTrackGroup *this, int pTrackName, DmeClipType_t trackType)
{
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmeTrack *v6; // esi

  v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeTrack::m_classType.u.m_Id,
         a3: (const char *)pTrackName,
         a4: this->m_fileId,
         a5: nullptr);
  v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
  v6 = (CDmeTrack *)v5;
  if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeTrack::m_classType) )
    v6 = nullptr;
  CDmeTrack::SetClipType(this: v6, type: trackType);
  CDmeTrack::SetCollapsed(this: v6, state: false);
  if ( v6 != nullptr )
  {
    pTrackName = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v6);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Tracks,
      src: (DmElementHandle_t *)&pTrackName);
    return v6;
  }
  else
  {
    pTrackName = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Tracks,
      src: (DmElementHandle_t *)&pTrackName);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B8FF0
// Name: public: class CDmeTrack __near * CDmeTrackGroup::CreateFilmTrack(void)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::CreateFilmTrack(CDmeTrackGroup *this)
{
  return CDmeTrackGroup::AddTrack(this, pTrackName: (int)"Film", trackType: DMECLIP_FILM);
}

//------------------------------------------------------------------------------
// Address: 0x004B9000
// Name: public: bool CDmeTrackGroup::FindTrackForClip(class CDmeClip __near *,int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeTrackGroup::FindTrackForClip(
        CDmeTrackGroup *this,
        CDmeClip *pClip,
        int *pTrackIndex,
        int *pClipIndex)
{
  CDmeTrackGroup *v4; // ebx
  int v5; // edi
  CDmElement *v6; // eax
  CDmeVertexDataBase *v7; // esi
  int ClipCount; // ebx
  int v9; // edi
  int c; // [esp+Ch] [ebp-10h]
  DmeClipType_t type; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  v4 = this;
  type = pClip->GetClipType(this: pClip);
  v5 = 0;
  c = v4->m_Tracks.m_Storage.m_Size;
  i = 0;
  if ( c <= 0 )
    return 0;
  while ( 1 )
  {
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4->m_Tracks.m_Storage.m_Memory.m_pMemory[v5]);
    v7 = (CDmeVertexDataBase *)v6;
    if ( v6 != nullptr
      && v6->IsA(this: v6, a2: CDmeTrack::m_classType)
      && CDmeTrack::GetClipType(this: (CDmeTrack *)v7) == type )
    {
      ClipCount = CDmeTrack::GetClipCount(this: v7);
      v9 = 0;
      if ( ClipCount > 0 )
        break;
LABEL_8:
      v4 = this;
      v5 = i;
    }
    i = ++v5;
    if ( v5 >= c )
      return 0;
  }
  while ( CDmeTrack::GetClip(this: (CDmeTrack *)v7, i: v9) != pClip )
  {
    if ( ++v9 >= ClipCount )
      goto LABEL_8;
  }
  if ( pTrackIndex != nullptr )
    *pTrackIndex = i;
  if ( pClipIndex != nullptr )
    *pClipIndex = v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B90D0
// Name: public: void CDmeTrackGroup::FindClipsAtTime(enum DmeClipType_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsAtTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t time,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v6; // edi
  CDmElement *v7; // eax
  CDmeTrack *v8; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v6 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v6]);
        v8 = (CDmeTrack *)v7;
        if ( v7 != nullptr
          && v7->IsA(this: v7, a2: CDmeTrack::m_classType)
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v8) == clipType) )
        {
          CDmeTrack::FindClipsAtTime(this: v8, time, flags, clips);
        }
        ++v6;
      }
      while ( v6 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9170
// Name: public: void CDmeTrackGroup::FindClipsIntersectingTime(enum DmeClipType_t,class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsIntersectingTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t startTime,
        DmeTime_t endTime,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v7; // edi
  CDmElement *v8; // eax
  CDmeTrack *v9; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v7 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = (CDmeTrack *)v8;
        if ( v8 != nullptr
          && v8->IsA(this: v8, a2: CDmeTrack::m_classType)
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v9) == clipType) )
        {
          CDmeTrack::FindClipsIntersectingTime(
            this: v9,
            startTime,
            endTime,
            flags,
            (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)clips);
        }
        ++v7;
      }
      while ( v7 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9210
// Name: public: void CDmeTrackGroup::FindClipsWithinTime(enum DmeClipType_t,class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsWithinTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t startTime,
        DmeTime_t endTime,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v7; // edi
  CDmElement *v8; // eax
  CDmeTrack *v9; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v7 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = (CDmeTrack *)v8;
        if ( v8 != nullptr
          && v8->IsA(this: v8, a2: CDmeTrack::m_classType)
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v9) == clipType) )
        {
          CDmeTrack::FindClipsWithinTime(
            this: v9,
            startTime,
            endTime,
            flags,
            (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)clips);
        }
        ++v7;
      }
      while ( v7 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B92B0
// Name: public: class CDmeClip __near * CDmeTrackGroup::GetOwnerClip(void)
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeTrackGroup::GetOwnerClip(CDmeTrackGroup *this)
{
  CUtlSymbolLarge *v2; // eax
  CDmeClip *result; // eax
  CUtlSymbolLarge *v4; // eax
  _BYTE v5[4]; // [esp+4h] [ebp-4h] BYREF

  v2 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v5, a3: "subClipTrackGroup");
  result = FindReferringElement<CDmeClip>(
             pElement: this,
             symAttrName: (CUtlSymbolLarge)v2->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  if ( result == nullptr )
  {
    v4 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v5, a3: "trackGroups");
    return FindReferringElement<CDmeClip>(
             pElement: this,
             symAttrName: (CUtlSymbolLarge)v4->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B9320
// Name: public: class CDmeTrack __near * CDmeTrackGroup::GetFilmTrack(void)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::GetFilmTrack(CDmeTrackGroup *this)
{
  CDmeClip *OwnerClip; // eax
  bool v3; // zf
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  OwnerClip = CDmeTrackGroup::GetOwnerClip(this);
  if ( OwnerClip != nullptr )
    v3 = OwnerClip->GetFilmTrackGroup(this: OwnerClip) == this;
  else
    v3 = this->m_nMaxTrackCount == 1;
  if ( v3
    && this->m_Tracks.m_Storage.m_Size > 0
    && (v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Tracks.m_Storage.m_Memory.m_pMemory),
        v5 = v4,
        v4 != nullptr)
    && v4->IsA(this: v4, a2: CDmeTrack::m_classType) )
  {
    return (CDmeTrack *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9390
// Name: public: class CDmeTrack __near * CDmeTrackGroup::FindTrackForClip(class CDmeClip __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::FindTrackForClip(CDmeTrackGroup *this, CDmeClip *pClip)
{
  CDmElement *v3; // eax
  CDmElement *v4; // esi
  int nTrackIndex; // [esp+4h] [ebp-4h] BYREF

  nTrackIndex = -1;
  if ( CDmeTrackGroup::FindTrackForClip(this, pClip, pTrackIndex: &nTrackIndex, pClipIndex: nullptr) != 0
    && (v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[nTrackIndex]),
        v4 = v3,
        v3 != nullptr)
    && v3->IsA(this: v3, a2: CDmeTrack::m_classType) )
  {
    return (CDmeTrack *)v4;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9460
// Name: protected: CDmeTrackGroup::CDmeTrackGroup(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrackGroup *__thiscall CDmeTrackGroup::CDmeTrackGroup(
        CDmeTrackGroup *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTrackGroup_vtbl *)&CDmeTrackGroup::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Tracks);
  this->m_bIsVisible.m_pAttribute = nullptr;
  this->m_bIsVisible.m_Storage = false;
  this->m_bMinimized.m_pAttribute = nullptr;
  this->m_bMinimized.m_Storage = false;
  this->m_bMute.m_pAttribute = nullptr;
  this->m_bMute.m_Storage = false;
  this->m_Volume = 0;
  this->m_flDisplayScale = 0;
  this->m_bForceMultiTrack.m_pAttribute = nullptr;
  this->m_bForceMultiTrack.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B94D0
// Name: public: virtual bool CDmeTrackGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTrackGroup::IsA(CDmeTrackGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTrackGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B9500
// Name: public: virtual int CDmeTrackGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrackGroup::GetInheritanceDepth(CDmeTrackGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTrackGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B9540
// Name: protected: virtual int CDmeTrackGroup::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrackGroup::AllocatedSize(CDmeTrackGroup *this)
{
  return 148;
}

//------------------------------------------------------------------------------
// Address: 0x004B9550
// Name: protected: virtual void CDmeTrackGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::PerformConstruction(CDmeTrackGroup *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTrackGroup::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005AC780
// Name: _dynamic_initializer_for__CDmeTrackGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTrackGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTrackGroup::s_Allocator,
    blockSize: 148,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTrackGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AFE60
// Name: _dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTrackGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x004B8EB0
// Name: class CDmeClip __near * FindReferringElement<class CDmeClip>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeClip *__cdecl FindReferringElement<CDmeClip>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeClip *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v5);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeClip>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AC7B0
// Name: _dynamic_initializer_for__g_CDmeTrackGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTrackGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AC7C0
// Name: _dynamic_initializer_for__g_CDmeTrackGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTrackGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTrackGroup_Helper,
           classname: "DmeTrackGroup",
           pFactory: &g_CDmeTrackGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AFE70
// Name: _dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTrackGroup_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x0050F1D0
// Name: protected: void CDmeTrackGroup::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::OnConstruction(CDmeTrackGroup *this)
{
  CDmaElementArray<CDmeTrack> *p_m_Tracks; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  float v8; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  p_m_Tracks = &this->m_Tracks;
  this->m_Tracks.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "tracks",
                                  type: AT_FIRST_ARRAY_TYPE,
                                  pMemory: &this->m_Tracks);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Tracks->m_pAttribute, typeSymbol: CDmeTrack::m_classType);
  p_m_Tracks->m_pAttribute->m_nFlags |= 0x900u;
  value = true;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_bIsVisible);
  this->m_bIsVisible.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_bMute.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "mute",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bMute);
  v8 = 1.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "displayScale",
         type: AT_FLOAT,
         pMemory: &this->m_flDisplayScale);
  this->m_flDisplayScale.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, value: &v8);
  value = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "minimized", type: AT_BOOL, pMemory: &this->m_bMinimized);
  this->m_bMinimized.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  this->m_nMaxTrackCount = 0x7FFFFFFF;
  v8 = 1.0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "volume", type: AT_FLOAT, pMemory: &this->m_Volume);
  this->m_Volume.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: &v8);
  value = false;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "forcemultitrack",
         type: AT_BOOL,
         pMemory: &this->m_bForceMultiTrack);
  this->m_bForceMultiTrack.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0050F390
// Name: public: class CDmeTrack __near * CDmeTrackGroup::AddTrack(char const __near *,enum DmeClipType_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::AddTrack(CDmeTrackGroup *this, int pTrackName, DmeClipType_t trackType)
{
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmeTrack *v6; // esi

  v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeTrack::m_classType.u.m_Id,
         a3: (const char *)pTrackName,
         a4: this->m_fileId,
         a5: nullptr);
  v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
  v6 = (CDmeTrack *)v5;
  if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeTrack::m_classType) )
    v6 = nullptr;
  CDmeTrack::SetClipType(this: v6, type: trackType);
  CDmeTrack::SetCollapsed(this: v6, state: false);
  if ( v6 != nullptr )
  {
    pTrackName = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v6);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Tracks,
      src: (DmElementHandle_t *)&pTrackName);
    return v6;
  }
  else
  {
    pTrackName = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Tracks,
      src: (DmElementHandle_t *)&pTrackName);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050F440
// Name: public: class CDmeTrack __near * CDmeTrackGroup::CreateFilmTrack(void)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::CreateFilmTrack(CDmeTrackGroup *this)
{
  return CDmeTrackGroup::AddTrack(this, pTrackName: (int)"Film", trackType: DMECLIP_FILM);
}

//------------------------------------------------------------------------------
// Address: 0x0050F450
// Name: public: bool CDmeTrackGroup::FindTrackForClip(class CDmeClip __near *,int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeTrackGroup::FindTrackForClip(
        CDmeTrackGroup *this,
        CDmeClip *pClip,
        int *pTrackIndex,
        int *pClipIndex)
{
  CDmeTrackGroup *v4; // ebx
  int v5; // edi
  CDmElement *v6; // eax
  CDmeTransform *v7; // esi
  CDmAttribute *ClipCount; // ebx
  int v9; // edi
  int c; // [esp+Ch] [ebp-10h]
  DmeClipType_t type; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  v4 = this;
  type = pClip->GetClipType(this: pClip);
  v5 = 0;
  c = v4->m_Tracks.m_Storage.m_Size;
  i = 0;
  if ( c <= 0 )
    return 0;
  while ( 1 )
  {
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4->m_Tracks.m_Storage.m_Memory.m_pMemory[v5]);
    v7 = (CDmeTransform *)v6;
    if ( v6 != nullptr
      && v6->IsA(this: v6, a2: CDmeTrack::m_classType)
      && CDmeTrack::GetClipType(this: (CDmeTrack *)v7) == type )
    {
      ClipCount = CDmeTrack::GetClipCount(this: v7);
      v9 = 0;
      if ( (int)ClipCount > 0 )
        break;
LABEL_8:
      v4 = this;
      v5 = i;
    }
    i = ++v5;
    if ( v5 >= c )
      return 0;
  }
  while ( CDmeTrack::GetClip(this: (CDmeTrack *)v7, i: v9) != pClip )
  {
    if ( ++v9 >= (int)ClipCount )
      goto LABEL_8;
  }
  if ( pTrackIndex != nullptr )
    *pTrackIndex = i;
  if ( pClipIndex != nullptr )
    *pClipIndex = v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0050F520
// Name: public: void CDmeTrackGroup::FindClipsAtTime(enum DmeClipType_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsAtTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t time,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v6; // edi
  CDmElement *v7; // eax
  CDmeTrack *v8; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v6 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v6]);
        v8 = (CDmeTrack *)v7;
        if ( v7 != nullptr
          && v7->IsA(this: v7, a2: CDmeTrack::m_classType)
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v8) == clipType) )
        {
          CDmeTrack::FindClipsAtTime(this: v8, time, flags, clips);
        }
        ++v6;
      }
      while ( v6 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050F5C0
// Name: public: void CDmeTrackGroup::FindClipsIntersectingTime(enum DmeClipType_t,class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsIntersectingTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t startTime,
        DmeTime_t endTime,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v7; // edi
  CDmElement *v8; // eax
  CDmeTrack *v9; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v7 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = (CDmeTrack *)v8;
        if ( v8 != nullptr
          && v8->IsA(this: v8, a2: CDmeTrack::m_classType)
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v9) == clipType) )
        {
          CDmeTrack::FindClipsIntersectingTime(this: v9, startTime, endTime, flags, clips);
        }
        ++v7;
      }
      while ( v7 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050F660
// Name: public: void CDmeTrackGroup::FindClipsWithinTime(enum DmeClipType_t,class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsWithinTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t startTime,
        DmeTime_t endTime,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v7; // edi
  CDmElement *v8; // eax
  CDmeTrack *v9; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v7 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = (CDmeTrack *)v8;
        if ( v8 != nullptr
          && v8->IsA(this: v8, a2: CDmeTrack::m_classType)
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v9) == clipType) )
        {
          CDmeTrack::FindClipsWithinTime(this: v9, startTime, endTime, flags, clips);
        }
        ++v7;
      }
      while ( v7 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050F700
// Name: public: class CDmeClip __near * CDmeTrackGroup::GetOwnerClip(void)
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeTrackGroup::GetOwnerClip(CDmeTrackGroup *this)
{
  CUtlSymbolLarge *v2; // eax
  CDmeClip *result; // eax
  CUtlSymbolLarge *v4; // eax
  _BYTE v5[4]; // [esp+4h] [ebp-4h] BYREF

  v2 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v5, a3: "subClipTrackGroup");
  result = FindReferringElement<CDmeClip>(
             pElement: this,
             symAttrName: (CUtlSymbolLarge)v2->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  if ( result == nullptr )
  {
    v4 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v5, a3: "trackGroups");
    return FindReferringElement<CDmeClip>(
             pElement: this,
             symAttrName: (CUtlSymbolLarge)v4->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0050F770
// Name: public: class CDmeTrack __near * CDmeTrackGroup::GetFilmTrack(void)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::GetFilmTrack(CDmeTrackGroup *this)
{
  CDmeClip *OwnerClip; // eax
  bool v3; // zf
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  OwnerClip = CDmeTrackGroup::GetOwnerClip(this);
  if ( OwnerClip != nullptr )
    v3 = OwnerClip->GetFilmTrackGroup(this: OwnerClip) == this;
  else
    v3 = this->m_nMaxTrackCount == 1;
  if ( v3
    && this->m_Tracks.m_Storage.m_Size > 0
    && (v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Tracks.m_Storage.m_Memory.m_pMemory),
        v5 = v4,
        v4 != nullptr)
    && v4->IsA(this: v4, a2: CDmeTrack::m_classType) )
  {
    return (CDmeTrack *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050F7E0
// Name: public: class CDmeTrack __near * CDmeTrackGroup::FindTrackForClip(class CDmeClip __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::FindTrackForClip(CDmeTrackGroup *this, CDmeClip *pClip)
{
  CDmElement *v3; // eax
  CDmElement *v4; // esi
  int nTrackIndex; // [esp+4h] [ebp-4h] BYREF

  nTrackIndex = -1;
  if ( CDmeTrackGroup::FindTrackForClip(this, pClip, pTrackIndex: &nTrackIndex, pClipIndex: nullptr) != 0
    && (v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[nTrackIndex]),
        v4 = v3,
        v3 != nullptr)
    && v3->IsA(this: v3, a2: CDmeTrack::m_classType) )
  {
    return (CDmeTrack *)v4;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050F8B0
// Name: protected: CDmeTrackGroup::CDmeTrackGroup(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrackGroup *__thiscall CDmeTrackGroup::CDmeTrackGroup(
        CDmeTrackGroup *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTrackGroup_vtbl *)&CDmeTrackGroup::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Tracks);
  this->m_bIsVisible.m_pAttribute = nullptr;
  this->m_bIsVisible.m_Storage = false;
  this->m_bMinimized.m_pAttribute = nullptr;
  this->m_bMinimized.m_Storage = false;
  this->m_bMute.m_pAttribute = nullptr;
  this->m_bMute.m_Storage = false;
  this->m_Volume = 0;
  this->m_flDisplayScale = 0;
  this->m_bForceMultiTrack.m_pAttribute = nullptr;
  this->m_bForceMultiTrack.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0050F920
// Name: public: virtual bool CDmeTrackGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTrackGroup::IsA(CDmeTrackGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTrackGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050F950
// Name: public: virtual int CDmeTrackGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrackGroup::GetInheritanceDepth(CDmeTrackGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTrackGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050F990
// Name: protected: virtual int CDmeTrackGroup::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrackGroup::AllocatedSize(CDmeTrackGroup *this)
{
  return 148;
}

//------------------------------------------------------------------------------
// Address: 0x0050F9A0
// Name: protected: virtual void CDmeTrackGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::PerformConstruction(CDmeTrackGroup *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeTrackGroup::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005DE350
// Name: public: void CDmeTrackGroup::SetMaxTrackCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::SetMaxTrackCount(vgui::Panel *this, Color color)
{
  this->_bgColor = color;
}

//------------------------------------------------------------------------------
// Address: 0x0067DEB0
// Name: _dynamic_initializer_for__CDmeTrackGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTrackGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTrackGroup::s_Allocator,
    blockSize: 148,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTrackGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00682330
// Name: _dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTrackGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0050F300
// Name: class CDmeClip __near * FindReferringElement<class CDmeClip>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeClip *__cdecl FindReferringElement<CDmeClip>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeClip *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeClip>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0067DEE0
// Name: _dynamic_initializer_for__g_CDmeTrackGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTrackGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067DEF0
// Name: _dynamic_initializer_for__g_CDmeTrackGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTrackGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTrackGroup_Helper,
           classname: "DmeTrackGroup",
           pFactory: &g_CDmeTrackGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00682340
// Name: _dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeTrackGroup_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102C5FE0
// Name: public: void CDmeTrackGroup::SetMaxTrackCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::SetMaxTrackCount(vgui::Panel *this, Color color)
{
  this->_bgColor = color;
}

//------------------------------------------------------------------------------
// Address: 0x10596710
// Name: protected: void CDmeTrackGroup::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::OnConstruction(CDmeTrackGroup *this)
{
  CDmaElementArray<CDmeTrack> *p_m_Tracks; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  float v8; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  p_m_Tracks = &this->m_Tracks;
  this->m_Tracks.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "tracks",
                                  type: AT_FIRST_ARRAY_TYPE,
                                  pMemory: &this->m_Tracks);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Tracks->m_pAttribute, typeSymbol: CDmeTrack::m_classType);
  p_m_Tracks->m_pAttribute->m_nFlags |= 0x900u;
  value = true;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_bIsVisible);
  this->m_bIsVisible.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_bMute.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "mute",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bMute);
  v8 = 1.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "displayScale",
         type: AT_FLOAT,
         pMemory: &this->m_flDisplayScale);
  this->m_flDisplayScale.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, value: &v8);
  value = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "minimized", type: AT_BOOL, pMemory: &this->m_bMinimized);
  this->m_bMinimized.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  this->m_nMaxTrackCount = 0x7FFFFFFF;
  v8 = 1.0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "volume", type: AT_FLOAT, pMemory: &this->m_Volume);
  this->m_Volume.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: &v8);
  value = false;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "forcemultitrack",
         type: AT_BOOL,
         pMemory: &this->m_bForceMultiTrack);
  this->m_bForceMultiTrack.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, &value);
}

//------------------------------------------------------------------------------
// Address: 0x105968D0
// Name: public: class CDmeTrack __near * CDmeTrackGroup::AddTrack(char const __near *,enum DmeClipType_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::AddTrack(CDmeTrackGroup *this, int pTrackName, DmeClipType_t trackType)
{
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmeTrack *v6; // esi

  v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeTrack::m_classType.u.m_Id,
         a3: (const char *)pTrackName,
         a4: this->m_fileId,
         a5: nullptr);
  v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
  v6 = (CDmeTrack *)v5;
  if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeTrack::m_classType) )
    v6 = nullptr;
  CDmeTrack::SetClipType(this: v6, type: trackType);
  CDmeTrack::SetCollapsed(this: v6, state: false);
  if ( v6 != nullptr )
  {
    pTrackName = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v6);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Tracks,
      src: (DmElementHandle_t *)&pTrackName);
    return v6;
  }
  else
  {
    pTrackName = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Tracks,
      src: (DmElementHandle_t *)&pTrackName);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10596980
// Name: public: class CDmeTrack __near * CDmeTrackGroup::CreateFilmTrack(void)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::CreateFilmTrack(CDmeTrackGroup *this)
{
  return CDmeTrackGroup::AddTrack(this, pTrackName: (int)"Film", trackType: DMECLIP_FILM);
}

//------------------------------------------------------------------------------
// Address: 0x10596990
// Name: public: bool CDmeTrackGroup::FindTrackForClip(class CDmeClip __near *,int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeTrackGroup::FindTrackForClip(
        CDmeTrackGroup *this,
        CDmeClip *pClip,
        int *pTrackIndex,
        int *pClipIndex)
{
  CDmeTrackGroup *v4; // ebx
  int v5; // edi
  CDmElement *v6; // eax
  CDmeTransform *v7; // esi
  CDmAttribute *ClipCount; // ebx
  int v9; // edi
  int c; // [esp+Ch] [ebp-10h]
  DmeClipType_t type; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  v4 = this;
  type = pClip->GetClipType(this: pClip);
  v5 = 0;
  c = v4->m_Tracks.m_Storage.m_Size;
  i = 0;
  if ( c <= 0 )
    return 0;
  while ( 1 )
  {
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4->m_Tracks.m_Storage.m_Memory.m_pMemory[v5]);
    v7 = (CDmeTransform *)v6;
    if ( v6 != nullptr
      && v6->IsA(this: v6, a2: CDmeTrack::m_classType)
      && CDmeTrack::GetClipType(this: (CDmeTrack *)v7) == type )
    {
      ClipCount = CDmeTrack::GetClipCount(this: v7);
      v9 = 0;
      if ( (int)ClipCount > 0 )
        break;
LABEL_8:
      v4 = this;
      v5 = i;
    }
    i = ++v5;
    if ( v5 >= c )
      return 0;
  }
  while ( CDmeTrack::GetClip(this: (CDmeTrack *)v7, i: v9) != pClip )
  {
    if ( ++v9 >= (int)ClipCount )
      goto LABEL_8;
  }
  if ( pTrackIndex != nullptr )
    *pTrackIndex = i;
  if ( pClipIndex != nullptr )
    *pClipIndex = v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10596A60
// Name: public: void CDmeTrackGroup::FindClipsAtTime(enum DmeClipType_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsAtTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t time,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v6; // edi
  CDmElement *v7; // eax
  CDmeTrack *v8; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v6 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v6]);
        v8 = (CDmeTrack *)v7;
        if ( v7 != nullptr
          && v7->IsA(this: v7, a2: CDmeTrack::m_classType)
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v8) == clipType) )
        {
          CDmeTrack::FindClipsAtTime(this: v8, time, flags, clips);
        }
        ++v6;
      }
      while ( v6 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10596B00
// Name: public: void CDmeTrackGroup::FindClipsIntersectingTime(enum DmeClipType_t,class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsIntersectingTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t startTime,
        DmeTime_t endTime,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v7; // edi
  CDmElement *v8; // eax
  CDmeTrack *v9; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v7 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = (CDmeTrack *)v8;
        if ( v8 != nullptr
          && v8->IsA(this: v8, a2: CDmeTrack::m_classType)
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v9) == clipType) )
        {
          CDmeTrack::FindClipsIntersectingTime(this: v9, startTime, endTime, flags, clips);
        }
        ++v7;
      }
      while ( v7 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10596BA0
// Name: public: void CDmeTrackGroup::FindClipsWithinTime(enum DmeClipType_t,class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsWithinTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t startTime,
        DmeTime_t endTime,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v7; // edi
  CDmElement *v8; // eax
  CDmeTrack *v9; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v7 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = (CDmeTrack *)v8;
        if ( v8 != nullptr
          && v8->IsA(this: v8, a2: CDmeTrack::m_classType)
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v9) == clipType) )
        {
          CDmeTrack::FindClipsWithinTime(this: v9, startTime, endTime, flags, clips);
        }
        ++v7;
      }
      while ( v7 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10596C40
// Name: public: class CDmeClip __near * CDmeTrackGroup::GetOwnerClip(void)
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeTrackGroup::GetOwnerClip(CDmeTrackGroup *this)
{
  CUtlSymbolLarge *v2; // eax
  CDmeClip *result; // eax
  CUtlSymbolLarge *v4; // eax
  _BYTE v5[4]; // [esp+4h] [ebp-4h] BYREF

  v2 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v5, a3: "subClipTrackGroup");
  result = FindReferringElement<CDmeClip>(
             pElement: this,
             symAttrName: (CUtlSymbolLarge)v2->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  if ( result == nullptr )
  {
    v4 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v5, a3: "trackGroups");
    return FindReferringElement<CDmeClip>(
             pElement: this,
             symAttrName: (CUtlSymbolLarge)v4->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10596CB0
// Name: public: class CDmeTrack __near * CDmeTrackGroup::GetFilmTrack(void)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::GetFilmTrack(CDmeTrackGroup *this)
{
  CDmeClip *OwnerClip; // eax
  bool v3; // zf
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  OwnerClip = CDmeTrackGroup::GetOwnerClip(this);
  if ( OwnerClip != nullptr )
    v3 = OwnerClip->GetFilmTrackGroup(this: OwnerClip) == this;
  else
    v3 = this->m_nMaxTrackCount == 1;
  if ( v3
    && this->m_Tracks.m_Storage.m_Size > 0
    && (v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Tracks.m_Storage.m_Memory.m_pMemory),
        v5 = v4,
        v4 != nullptr)
    && v4->IsA(this: v4, a2: CDmeTrack::m_classType) )
  {
    return (CDmeTrack *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10596D20
// Name: public: class CDmeTrack __near * CDmeTrackGroup::FindTrackForClip(class CDmeClip __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::FindTrackForClip(CDmeTrackGroup *this, CDmeClip *pClip)
{
  CDmElement *v3; // eax
  CDmElement *v4; // esi
  int nTrackIndex; // [esp+4h] [ebp-4h] BYREF

  nTrackIndex = -1;
  if ( CDmeTrackGroup::FindTrackForClip(this, pClip, pTrackIndex: &nTrackIndex, pClipIndex: nullptr) != 0
    && (v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[nTrackIndex]),
        v4 = v3,
        v3 != nullptr)
    && v3->IsA(this: v3, a2: CDmeTrack::m_classType) )
  {
    return (CDmeTrack *)v4;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10596DF0
// Name: protected: CDmeTrackGroup::CDmeTrackGroup(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrackGroup *__thiscall CDmeTrackGroup::CDmeTrackGroup(
        CDmeTrackGroup *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTrackGroup_vtbl *)&CDmeTrackGroup::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Tracks);
  this->m_bIsVisible.m_pAttribute = nullptr;
  this->m_bIsVisible.m_Storage = false;
  this->m_bMinimized.m_pAttribute = nullptr;
  this->m_bMinimized.m_Storage = false;
  this->m_bMute.m_pAttribute = nullptr;
  this->m_bMute.m_Storage = false;
  this->m_Volume = 0;
  this->m_flDisplayScale = 0;
  this->m_bForceMultiTrack.m_pAttribute = nullptr;
  this->m_bForceMultiTrack.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10596E60
// Name: public: virtual bool CDmeTrackGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTrackGroup::IsA(CDmeTrackGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTrackGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10596E90
// Name: public: virtual int CDmeTrackGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrackGroup::GetInheritanceDepth(CDmeTrackGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTrackGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10596ED0
// Name: protected: virtual int CDmeTrackGroup::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrackGroup::AllocatedSize(CDmeTrackGroup *this)
{
  return 148;
}

//------------------------------------------------------------------------------
// Address: 0x10596EE0
// Name: protected: virtual void CDmeTrackGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::PerformConstruction(CDmeTrackGroup *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeTrackGroup::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x105C9950
// Name: _dynamic_initializer_for__CDmeTrackGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTrackGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTrackGroup::s_Allocator,
    blockSize: 0x94u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTrackGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CDB30
// Name: _dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTrackGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x10596840
// Name: class CDmeClip __near * FindReferringElement<class CDmeClip>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeClip *__cdecl FindReferringElement<CDmeClip>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeClip *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeClip>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C9980
// Name: _dynamic_initializer_for__g_CDmeTrackGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTrackGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9990
// Name: _dynamic_initializer_for__g_CDmeTrackGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTrackGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTrackGroup_Helper,
           classname: "DmeTrackGroup",
           pFactory: &g_CDmeTrackGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CDB40
// Name: _dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeTrackGroup_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x004C1410
// Name: public: void CDmeTrackGroup::SetMaxTrackCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::SetMaxTrackCount(CDmeTrackGroup *this, int nCount)
{
  this->m_nMaxTrackCount = nCount;
}

//------------------------------------------------------------------------------
// Address: 0x004C14D0
// Name: protected: void CDmeTrackGroup::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::OnConstruction(CDmeTrackGroup *this)
{
  CDmaElementArray<CDmeTrack> *p_m_Tracks; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  float v8; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  p_m_Tracks = &this->m_Tracks;
  this->m_Tracks.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "tracks",
                                  type: AT_FIRST_ARRAY_TYPE,
                                  pMemory: &this->m_Tracks);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Tracks->m_pAttribute, typeSymbol: CDmeTrack::m_classType);
  p_m_Tracks->m_pAttribute->m_nFlags |= 0x900u;
  value = true;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_bIsVisible);
  this->m_bIsVisible.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_bMute.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "mute",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bMute);
  v8 = 1.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "displayScale",
         type: AT_FLOAT,
         pMemory: &this->m_flDisplayScale);
  this->m_flDisplayScale.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, value: &v8);
  value = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "minimized", type: AT_BOOL, pMemory: &this->m_bMinimized);
  this->m_bMinimized.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  this->m_nMaxTrackCount = 0x7FFFFFFF;
  v8 = 1.0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "volume", type: AT_FLOAT, pMemory: &this->m_Volume);
  this->m_Volume.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: &v8);
  value = false;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "forcemultitrack",
         type: AT_BOOL,
         pMemory: &this->m_bForceMultiTrack);
  this->m_bForceMultiTrack.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004C1690
// Name: public: class CDmeTrack __near * CDmeTrackGroup::AddTrack(char const __near *,enum DmeClipType_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::AddTrack(
        CDmeTrackGroup *this,
        DmElementHandle_t pTrackName,
        DmeClipType_t trackType)
{
  int v4; // eax
  int v5; // eax
  CDmeTrack *v6; // esi

  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeTrack::m_classType.u,
         a3: pTrackName,
         a4: this->m_fileId,
         a5: 0);
  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v4);
  v6 = (CDmeTrack *)v5;
  if ( v5 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
         a1: v5,
         a2: CDmeTrack::m_classType.u) == 0 )
  {
    v6 = nullptr;
  }
  CDmeTrack::SetClipType(this: v6, type: trackType);
  CDmeTrack::SetCollapsed(this: v6, state: false);
  if ( v6 != nullptr )
  {
    pTrackName = CDmElement::GetHandle(this: v6);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Tracks,
      src: &pTrackName);
    return v6;
  }
  else
  {
    pTrackName = DMELEMENT_HANDLE_INVALID;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Tracks,
      src: &pTrackName);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C1740
// Name: public: class CDmeTrack __near * CDmeTrackGroup::CreateFilmTrack(void)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::CreateFilmTrack(CDmeTrackGroup *this)
{
  return CDmeTrackGroup::AddTrack(this, pTrackName: (DmElementHandle_t)"Film", trackType: DMECLIP_FILM);
}

//------------------------------------------------------------------------------
// Address: 0x004C1750
// Name: public: bool CDmeTrackGroup::FindTrackForClip(class CDmeClip __near *,int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeTrackGroup::FindTrackForClip(
        CDmeTrackGroup *this,
        CDmeClip *pClip,
        int *pTrackIndex,
        int *pClipIndex)
{
  CDmeTrackGroup *v4; // ebx
  int v5; // edi
  int v6; // eax
  CDmeTransform *v7; // esi
  CDmAttribute *ClipCount; // ebx
  int v9; // edi
  int c; // [esp+Ch] [ebp-10h]
  DmeClipType_t type; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  v4 = this;
  type = pClip->GetClipType(this: pClip);
  v5 = 0;
  c = v4->m_Tracks.m_Storage.m_Size;
  i = 0;
  if ( c <= 0 )
    return 0;
  while ( 1 )
  {
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: v4->m_Tracks.m_Storage.m_Memory.m_pMemory[v5]);
    v7 = (CDmeTransform *)v6;
    if ( v6 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
           a1: v6,
           a2: CDmeTrack::m_classType.u) != 0
      && CDmeTrack::GetClipType(this: (CDmeTrack *)v7) == type )
    {
      ClipCount = CDmeTrack::GetClipCount(this: v7);
      v9 = 0;
      if ( (int)ClipCount > 0 )
        break;
LABEL_8:
      v4 = this;
      v5 = i;
    }
    i = ++v5;
    if ( v5 >= c )
      return 0;
  }
  while ( CDmeTrack::GetClip(this: (CDmeTrack *)v7, i: v9) != pClip )
  {
    if ( ++v9 >= (int)ClipCount )
      goto LABEL_8;
  }
  if ( pTrackIndex != nullptr )
    *pTrackIndex = i;
  if ( pClipIndex != nullptr )
    *pClipIndex = v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004C1820
// Name: public: void CDmeTrackGroup::FindClipsAtTime(enum DmeClipType_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsAtTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t time,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v6; // edi
  int v7; // eax
  CDmeTrack *v8; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v6 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v6]);
        v8 = (CDmeTrack *)v7;
        if ( v7 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
               a1: v7,
               a2: CDmeTrack::m_classType.u) != 0
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v8) == clipType) )
        {
          CDmeTrack::FindClipsAtTime(this: v8, time, flags, clips);
        }
        ++v6;
      }
      while ( v6 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C18C0
// Name: public: void CDmeTrackGroup::FindClipsIntersectingTime(enum DmeClipType_t,class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsIntersectingTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t startTime,
        DmeTime_t endTime,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v7; // edi
  int v8; // eax
  CDmeTrack *v9; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v7 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = (CDmeTrack *)v8;
        if ( v8 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
               a1: v8,
               a2: CDmeTrack::m_classType.u) != 0
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v9) == clipType) )
        {
          CDmeTrack::FindClipsIntersectingTime(this: v9, startTime, endTime, flags, clips);
        }
        ++v7;
      }
      while ( v7 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C1960
// Name: public: void CDmeTrackGroup::FindClipsWithinTime(enum DmeClipType_t,class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsWithinTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t startTime,
        DmeTime_t endTime,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v7; // edi
  int v8; // eax
  CDmeTrack *v9; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v7 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = (CDmeTrack *)v8;
        if ( v8 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
               a1: v8,
               a2: CDmeTrack::m_classType.u) != 0
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v9) == clipType) )
        {
          CDmeTrack::FindClipsWithinTime(this: v9, startTime, endTime, flags, clips);
        }
        ++v7;
      }
      while ( v7 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C1A00
// Name: public: class CDmeClip __near * CDmeTrackGroup::GetOwnerClip(void)
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeTrackGroup::GetOwnerClip(CDmeTrackGroup *this)
{
  CUtlSymbolLarge *v2; // eax
  CDmeClip *result; // eax
  CUtlSymbolLarge *v4; // eax
  _BYTE v5[4]; // [esp+4h] [ebp-4h] BYREF

  v2 = (CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                            a1: g_pDataModel.u,
                            a2: v5,
                            a3: "subClipTrackGroup");
  result = FindReferringElement<CDmeClip>(
             pElement: this,
             symAttrName: (CUtlSymbolLarge)v2->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  if ( result == nullptr )
  {
    v4 = (CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                              a1: g_pDataModel.u,
                              a2: v5,
                              a3: "trackGroups");
    return FindReferringElement<CDmeClip>(
             pElement: this,
             symAttrName: (CUtlSymbolLarge)v4->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C1A70
// Name: public: class CDmeTrack __near * CDmeTrackGroup::GetFilmTrack(void)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::GetFilmTrack(CDmeTrackGroup *this)
{
  CDmeClip *OwnerClip; // eax
  bool v3; // zf
  int v4; // eax
  int v5; // esi

  OwnerClip = CDmeTrackGroup::GetOwnerClip(this);
  if ( OwnerClip != nullptr )
    v3 = OwnerClip->GetFilmTrackGroup(this: OwnerClip) == this;
  else
    v3 = this->m_nMaxTrackCount == 1;
  if ( v3
    && this->m_Tracks.m_Storage.m_Size > 0
    && (v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: *this->m_Tracks.m_Storage.m_Memory.m_pMemory),
        v5 = v4,
        v4 != 0)
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeTrack::m_classType.u) != 0 )
  {
    return (CDmeTrack *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C1AE0
// Name: public: class CDmeTrack __near * CDmeTrackGroup::FindTrackForClip(class CDmeClip __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::FindTrackForClip(CDmeTrackGroup *this, CDmeClip *pClip)
{
  int v3; // eax
  int v4; // esi
  int nTrackIndex; // [esp+4h] [ebp-4h] BYREF

  nTrackIndex = -1;
  if ( CDmeTrackGroup::FindTrackForClip(this, pClip, pTrackIndex: &nTrackIndex, pClipIndex: nullptr) != 0
    && (v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[nTrackIndex]),
        v4 = v3,
        v3 != 0)
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
         a1: v3,
         a2: CDmeTrack::m_classType.u) != 0 )
  {
    return (CDmeTrack *)v4;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C1BB0
// Name: protected: CDmeTrackGroup::CDmeTrackGroup(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrackGroup *__thiscall CDmeTrackGroup::CDmeTrackGroup(
        CDmeTrackGroup *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTrackGroup_vtbl *)&CDmeTrackGroup::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Tracks);
  this->m_bIsVisible.m_pAttribute = nullptr;
  this->m_bIsVisible.m_Storage = false;
  this->m_bMinimized.m_pAttribute = nullptr;
  this->m_bMinimized.m_Storage = false;
  this->m_bMute.m_pAttribute = nullptr;
  this->m_bMute.m_Storage = false;
  this->m_Volume = 0;
  this->m_flDisplayScale = 0;
  this->m_bForceMultiTrack.m_pAttribute = nullptr;
  this->m_bForceMultiTrack.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C1C20
// Name: public: virtual bool CDmeTrackGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTrackGroup::IsA(CDmeTrackGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTrackGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004C1C50
// Name: public: virtual int CDmeTrackGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrackGroup::GetInheritanceDepth(CDmeTrackGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTrackGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004C1C90
// Name: protected: virtual void CDmeTrackGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::PerformConstruction(CDmeTrackGroup *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTrackGroup::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0059B8E0
// Name: _dynamic_initializer_for__CDmeTrackGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTrackGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTrackGroup::s_Allocator,
    blockSize: 148,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTrackGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059F010
// Name: _dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTrackGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x004C1600
// Name: class CDmeClip __near * FindReferringElement<class CDmeClip>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeClip *__cdecl FindReferringElement<CDmeClip>(
        CDmElement *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v4; // esi
  DmElementHandle_t Handle; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_fileId; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeClip *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = *(_DWORD *)g_pDataModel.u.m_Id;
    Handle = CDmElement::GetHandle(this: pElement);
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(v4 + 436))(
           a1: g_pDataModel.u,
           a2: Handle);
    m_fileId = pElement->m_fileId;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_fileId = DMFILEID_INVALID;
  }
  it.m_fileid = m_fileId;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeClip>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( result != nullptr )
      break;
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 440))(
           a1: g_pDataModel.u,
           a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0059B910
// Name: _dynamic_initializer_for__g_CDmeTrackGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTrackGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059B920
// Name: _dynamic_initializer_for__g_CDmeTrackGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTrackGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTrackGroup_Helper,
           classname: "DmeTrackGroup",
           pFactory: &g_CDmeTrackGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059F020
// Name: _dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTrackGroup_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x0050F1E0
// Name: public: void CDmeTrackGroup::SetMaxTrackCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::SetMaxTrackCount(CDmeTrackGroup *this, int nCount)
{
  this->m_nMaxTrackCount = nCount;
}

//------------------------------------------------------------------------------
// Address: 0x0050F2A0
// Name: protected: void CDmeTrackGroup::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::OnConstruction(CDmeTrackGroup *this)
{
  CDmaElementArray<CDmeTrack> *p_m_Tracks; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  float v8; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  p_m_Tracks = &this->m_Tracks;
  this->m_Tracks.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "tracks",
                                  type: AT_FIRST_ARRAY_TYPE,
                                  pMemory: &this->m_Tracks);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Tracks->m_pAttribute, typeSymbol: CDmeTrack::m_classType);
  p_m_Tracks->m_pAttribute->m_nFlags |= 0x900u;
  value = true;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_bIsVisible);
  this->m_bIsVisible.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_bMute.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "mute",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bMute);
  v8 = 1.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "displayScale",
         type: AT_FLOAT,
         pMemory: &this->m_flDisplayScale);
  this->m_flDisplayScale.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, value: &v8);
  value = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "minimized", type: AT_BOOL, pMemory: &this->m_bMinimized);
  this->m_bMinimized.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  this->m_nMaxTrackCount = 0x7FFFFFFF;
  v8 = 1.0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "volume", type: AT_FLOAT, pMemory: &this->m_Volume);
  this->m_Volume.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: &v8);
  value = false;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "forcemultitrack",
         type: AT_BOOL,
         pMemory: &this->m_bForceMultiTrack);
  this->m_bForceMultiTrack.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0050F460
// Name: public: class CDmeTrack __near * CDmeTrackGroup::AddTrack(char const __near *,enum DmeClipType_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::AddTrack(CDmeTrackGroup *this, int pTrackName, DmeClipType_t trackType)
{
  int v4; // eax
  int v5; // eax
  CDmeTrack *v6; // esi

  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, int, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeTrack::m_classType.u,
         a3: pTrackName,
         a4: this->m_fileId,
         a5: 0);
  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v4);
  v6 = (CDmeTrack *)v5;
  if ( v5 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
         a1: v5,
         a2: CDmeTrack::m_classType.u) == 0 )
  {
    v6 = nullptr;
  }
  CDmeTrack::SetClipType(this: v6, type: trackType);
  CDmeTrack::SetCollapsed(this: v6, state: false);
  if ( v6 != nullptr )
  {
    pTrackName = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v6);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Tracks,
      src: (DmElementHandle_t *)&pTrackName);
    return v6;
  }
  else
  {
    pTrackName = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Tracks,
      src: (DmElementHandle_t *)&pTrackName);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050F510
// Name: public: class CDmeTrack __near * CDmeTrackGroup::CreateFilmTrack(void)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::CreateFilmTrack(CDmeTrackGroup *this)
{
  return CDmeTrackGroup::AddTrack(this, pTrackName: (int)"Film", trackType: DMECLIP_FILM);
}

//------------------------------------------------------------------------------
// Address: 0x0050F5F0
// Name: public: void CDmeTrackGroup::FindClipsAtTime(enum DmeClipType_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsAtTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t time,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v6; // edi
  int v7; // eax
  CDmeTrack *v8; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v6 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v6]);
        v8 = (CDmeTrack *)v7;
        if ( v7 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
               a1: v7,
               a2: CDmeTrack::m_classType.u) != 0
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v8) == clipType) )
        {
          CDmeTrack::FindClipsAtTime(this: v8, time, flags, clips);
        }
        ++v6;
      }
      while ( v6 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050F690
// Name: public: void CDmeTrackGroup::FindClipsIntersectingTime(enum DmeClipType_t,class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsIntersectingTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t startTime,
        DmeTime_t endTime,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v7; // edi
  int v8; // eax
  CDmeTrack *v9; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v7 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = (CDmeTrack *)v8;
        if ( v8 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
               a1: v8,
               a2: CDmeTrack::m_classType.u) != 0
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v9) == clipType) )
        {
          CDmeTrack::FindClipsIntersectingTime(this: v9, startTime, endTime, flags, clips);
        }
        ++v7;
      }
      while ( v7 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050F730
// Name: public: void CDmeTrackGroup::FindClipsWithinTime(enum DmeClipType_t,class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsWithinTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t startTime,
        DmeTime_t endTime,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v7; // edi
  int v8; // eax
  CDmeTrack *v9; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v7 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = (CDmeTrack *)v8;
        if ( v8 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
               a1: v8,
               a2: CDmeTrack::m_classType.u) != 0
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v9) == clipType) )
        {
          CDmeTrack::FindClipsWithinTime(this: v9, startTime, endTime, flags, clips);
        }
        ++v7;
      }
      while ( v7 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050F7D0
// Name: public: class CDmeClip __near * CDmeTrackGroup::GetOwnerClip(void)
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeTrackGroup::GetOwnerClip(CDmeTrackGroup *this)
{
  CUtlSymbolLarge *v2; // eax
  CDmeClip *result; // eax
  CUtlSymbolLarge *v4; // eax
  _BYTE v5[4]; // [esp+4h] [ebp-4h] BYREF

  v2 = (CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                            a1: g_pDataModel.u,
                            a2: v5,
                            a3: "subClipTrackGroup");
  result = FindReferringElement<CDmeClip>(
             pElement: this,
             symAttrName: (CUtlSymbolLarge)v2->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  if ( result == nullptr )
  {
    v4 = (CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                              a1: g_pDataModel.u,
                              a2: v5,
                              a3: "trackGroups");
    return FindReferringElement<CDmeClip>(
             pElement: this,
             symAttrName: (CUtlSymbolLarge)v4->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0050F840
// Name: public: class CDmeTrack __near * CDmeTrackGroup::GetFilmTrack(void)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::GetFilmTrack(CDmeTrackGroup *this)
{
  CDmeClip *OwnerClip; // eax
  bool v3; // zf
  int v4; // eax
  int v5; // esi

  OwnerClip = CDmeTrackGroup::GetOwnerClip(this);
  if ( OwnerClip != nullptr )
    v3 = OwnerClip->GetFilmTrackGroup(this: OwnerClip) == this;
  else
    v3 = this->m_nMaxTrackCount == 1;
  if ( v3
    && this->m_Tracks.m_Storage.m_Size > 0
    && (v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: *this->m_Tracks.m_Storage.m_Memory.m_pMemory),
        v5 = v4,
        v4 != 0)
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeTrack::m_classType.u) != 0 )
  {
    return (CDmeTrack *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050F980
// Name: protected: CDmeTrackGroup::CDmeTrackGroup(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrackGroup *__thiscall CDmeTrackGroup::CDmeTrackGroup(
        CDmeTrackGroup *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTrackGroup_vtbl *)&CDmeTrackGroup::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Tracks);
  this->m_bIsVisible.m_pAttribute = nullptr;
  this->m_bIsVisible.m_Storage = false;
  this->m_bMinimized.m_pAttribute = nullptr;
  this->m_bMinimized.m_Storage = false;
  this->m_bMute.m_pAttribute = nullptr;
  this->m_bMute.m_Storage = false;
  this->m_Volume = 0;
  this->m_flDisplayScale = 0;
  this->m_bForceMultiTrack.m_pAttribute = nullptr;
  this->m_bForceMultiTrack.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0050F9F0
// Name: public: virtual bool CDmeTrackGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTrackGroup::IsA(CDmeTrackGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTrackGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050FA20
// Name: public: virtual int CDmeTrackGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrackGroup::GetInheritanceDepth(CDmeTrackGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTrackGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050FA70
// Name: protected: virtual void CDmeTrackGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::PerformConstruction(CDmeTrackGroup *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTrackGroup::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005F0930
// Name: _dynamic_initializer_for__CDmeTrackGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTrackGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTrackGroup::s_Allocator,
    blockSize: 148,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTrackGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F4460
// Name: _dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTrackGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0050F3D0
// Name: class CDmeClip __near * FindReferringElement<class CDmeClip>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeClip *__cdecl FindReferringElement<CDmeClip>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeClip *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = *(_DWORD *)g_pDataModel.u.m_Id;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v4 + 436))(a1: g_pDataModel.u, a2: v5);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeClip>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( result != nullptr )
      break;
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 440))(
           a1: g_pDataModel.u,
           a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005F0960
// Name: _dynamic_initializer_for__g_CDmeTrackGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTrackGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0970
// Name: _dynamic_initializer_for__g_CDmeTrackGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTrackGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTrackGroup_Helper,
           classname: "DmeTrackGroup",
           pFactory: &g_CDmeTrackGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F4470
// Name: _dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTrackGroup_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0047A060
// Name: public: void CDmeTrackGroup::SetMaxTrackCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::SetMaxTrackCount(CDmeTrackGroup *this, int nCount)
{
  this->m_nMaxTrackCount = nCount;
}

//------------------------------------------------------------------------------
// Address: 0x0047A120
// Name: protected: void CDmeTrackGroup::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::OnConstruction(CDmeTrackGroup *this)
{
  CDmaElementArray<CDmeTrack> *p_m_Tracks; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  float v8; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  p_m_Tracks = &this->m_Tracks;
  this->m_Tracks.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "tracks",
                                  type: AT_FIRST_ARRAY_TYPE,
                                  pMemory: &this->m_Tracks);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Tracks->m_pAttribute, typeSymbol: CDmeTrack::m_classType);
  p_m_Tracks->m_pAttribute->m_nFlags |= 0x900u;
  value = true;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_bIsVisible);
  this->m_bIsVisible.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_bMute.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "mute",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bMute);
  v8 = 1.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "displayScale",
         type: AT_FLOAT,
         pMemory: &this->m_flDisplayScale);
  this->m_flDisplayScale.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, value: &v8);
  value = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "minimized", type: AT_BOOL, pMemory: &this->m_bMinimized);
  this->m_bMinimized.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  this->m_nMaxTrackCount = 0x7FFFFFFF;
  v8 = 1.0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "volume", type: AT_FLOAT, pMemory: &this->m_Volume);
  this->m_Volume.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: &v8);
  value = false;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "forcemultitrack",
         type: AT_BOOL,
         pMemory: &this->m_bForceMultiTrack);
  this->m_bForceMultiTrack.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0047A2E0
// Name: public: class CDmeTrack __near * CDmeTrackGroup::AddTrack(char const __near *,enum DmeClipType_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::AddTrack(CDmeTrackGroup *this, int pTrackName, DmeClipType_t trackType)
{
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmeTrack *v6; // esi

  v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeTrack::m_classType.u.m_Id,
         a3: (const char *)pTrackName,
         a4: this->m_fileId,
         a5: nullptr);
  v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
  v6 = (CDmeTrack *)v5;
  if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeTrack::m_classType) )
    v6 = nullptr;
  CDmeTrack::SetClipType(this: v6, type: trackType);
  CDmeTrack::SetCollapsed(this: v6, state: false);
  if ( v6 != nullptr )
  {
    pTrackName = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v6);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Tracks,
      src: (DmElementHandle_t *)&pTrackName);
    return v6;
  }
  else
  {
    pTrackName = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Tracks,
      src: (DmElementHandle_t *)&pTrackName);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047A390
// Name: public: class CDmeTrack __near * CDmeTrackGroup::CreateFilmTrack(void)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::CreateFilmTrack(CDmeTrackGroup *this)
{
  return CDmeTrackGroup::AddTrack(this, pTrackName: (int)"Film", trackType: DMECLIP_FILM);
}

//------------------------------------------------------------------------------
// Address: 0x0047A3A0
// Name: public: bool CDmeTrackGroup::FindTrackForClip(class CDmeClip __near *,int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeTrackGroup::FindTrackForClip(
        CDmeTrackGroup *this,
        CDmeClip *pClip,
        int *pTrackIndex,
        int *pClipIndex)
{
  CDmeTrackGroup *v4; // ebx
  int v5; // edi
  CDmElement *v6; // eax
  CDmeTransform *v7; // esi
  CDmAttribute *ClipCount; // ebx
  int v9; // edi
  int c; // [esp+Ch] [ebp-10h]
  DmeClipType_t type; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  v4 = this;
  type = pClip->GetClipType(this: pClip);
  v5 = 0;
  c = v4->m_Tracks.m_Storage.m_Size;
  i = 0;
  if ( c <= 0 )
    return 0;
  while ( 1 )
  {
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4->m_Tracks.m_Storage.m_Memory.m_pMemory[v5]);
    v7 = (CDmeTransform *)v6;
    if ( v6 != nullptr
      && v6->IsA(this: v6, a2: CDmeTrack::m_classType)
      && CDmeTrack::GetClipType(this: (CDmeTrack *)v7) == type )
    {
      ClipCount = CDmeTrack::GetClipCount(this: v7);
      v9 = 0;
      if ( (int)ClipCount > 0 )
        break;
LABEL_8:
      v4 = this;
      v5 = i;
    }
    i = ++v5;
    if ( v5 >= c )
      return 0;
  }
  while ( CDmeTrack::GetClip(this: (CDmeTrack *)v7, i: v9) != pClip )
  {
    if ( ++v9 >= (int)ClipCount )
      goto LABEL_8;
  }
  if ( pTrackIndex != nullptr )
    *pTrackIndex = i;
  if ( pClipIndex != nullptr )
    *pClipIndex = v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047A470
// Name: public: void CDmeTrackGroup::FindClipsAtTime(enum DmeClipType_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsAtTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t time,
        DmeClipSkipFlag_t flags,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *clips)
{
  int v6; // edi
  CDmElement *v7; // eax
  CDmeTrack *v8; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v6 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v6]);
        v8 = (CDmeTrack *)v7;
        if ( v7 != nullptr
          && v7->IsA(this: v7, a2: CDmeTrack::m_classType)
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v8) == clipType) )
        {
          CDmeTrack::FindClipsAtTime(this: v8, time, flags, clips);
        }
        ++v6;
      }
      while ( v6 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047A510
// Name: public: void CDmeTrackGroup::FindClipsIntersectingTime(enum DmeClipType_t,class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsIntersectingTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t startTime,
        DmeTime_t endTime,
        DmeClipSkipFlag_t flags,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *clips)
{
  int v7; // edi
  CDmElement *v8; // eax
  CDmeTrack *v9; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v7 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = (CDmeTrack *)v8;
        if ( v8 != nullptr
          && v8->IsA(this: v8, a2: CDmeTrack::m_classType)
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v9) == clipType) )
        {
          CDmeTrack::FindClipsIntersectingTime(this: v9, startTime, endTime, flags, clips);
        }
        ++v7;
      }
      while ( v7 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047A5B0
// Name: public: void CDmeTrackGroup::FindClipsWithinTime(enum DmeClipType_t,class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsWithinTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t startTime,
        DmeTime_t endTime,
        DmeClipSkipFlag_t flags,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *clips)
{
  int v7; // edi
  CDmElement *v8; // eax
  CDmeTrack *v9; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v7 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = (CDmeTrack *)v8;
        if ( v8 != nullptr
          && v8->IsA(this: v8, a2: CDmeTrack::m_classType)
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v9) == clipType) )
        {
          CDmeTrack::FindClipsWithinTime(this: v9, startTime, endTime, flags, clips);
        }
        ++v7;
      }
      while ( v7 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047A650
// Name: public: class CDmeClip __near * CDmeTrackGroup::GetOwnerClip(void)
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeTrackGroup::GetOwnerClip(CDmeTrackGroup *this)
{
  CUtlSymbolLarge *v2; // eax
  CDmeClip *result; // eax
  CUtlSymbolLarge *v4; // eax
  _BYTE v5[4]; // [esp+4h] [ebp-4h] BYREF

  v2 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v5, a3: "subClipTrackGroup");
  result = FindReferringElement<CDmeClip>(
             pElement: this,
             symAttrName: (CUtlSymbolLarge)v2->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  if ( result == nullptr )
  {
    v4 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v5, a3: "trackGroups");
    return FindReferringElement<CDmeClip>(
             pElement: this,
             symAttrName: (CUtlSymbolLarge)v4->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047A6C0
// Name: public: class CDmeTrack __near * CDmeTrackGroup::GetFilmTrack(void)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::GetFilmTrack(CDmeTrackGroup *this)
{
  CDmeClip *OwnerClip; // eax
  bool v3; // zf
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  OwnerClip = CDmeTrackGroup::GetOwnerClip(this);
  if ( OwnerClip != nullptr )
    v3 = OwnerClip->GetFilmTrackGroup(this: OwnerClip) == this;
  else
    v3 = this->m_nMaxTrackCount == 1;
  if ( v3
    && this->m_Tracks.m_Storage.m_Size > 0
    && (v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Tracks.m_Storage.m_Memory.m_pMemory),
        v5 = v4,
        v4 != nullptr)
    && v4->IsA(this: v4, a2: CDmeTrack::m_classType) )
  {
    return (CDmeTrack *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047A730
// Name: public: class CDmeTrack __near * CDmeTrackGroup::FindTrackForClip(class CDmeClip __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::FindTrackForClip(CDmeTrackGroup *this, CDmeClip *pClip)
{
  CDmElement *v3; // eax
  CDmElement *v4; // esi
  int nTrackIndex; // [esp+4h] [ebp-4h] BYREF

  nTrackIndex = -1;
  if ( CDmeTrackGroup::FindTrackForClip(this, pClip, pTrackIndex: &nTrackIndex, pClipIndex: nullptr) != 0
    && (v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[nTrackIndex]),
        v4 = v3,
        v3 != nullptr)
    && v3->IsA(this: v3, a2: CDmeTrack::m_classType) )
  {
    return (CDmeTrack *)v4;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047A800
// Name: protected: CDmeTrackGroup::CDmeTrackGroup(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrackGroup *__thiscall CDmeTrackGroup::CDmeTrackGroup(
        CDmeTrackGroup *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTrackGroup_vtbl *)&CDmeTrackGroup::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Tracks);
  this->m_bIsVisible.m_pAttribute = nullptr;
  this->m_bIsVisible.m_Storage = false;
  this->m_bMinimized.m_pAttribute = nullptr;
  this->m_bMinimized.m_Storage = false;
  this->m_bMute.m_pAttribute = nullptr;
  this->m_bMute.m_Storage = false;
  this->m_Volume = 0;
  this->m_flDisplayScale = 0;
  this->m_bForceMultiTrack.m_pAttribute = nullptr;
  this->m_bForceMultiTrack.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0047A870
// Name: public: virtual bool CDmeTrackGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTrackGroup::IsA(CDmeTrackGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTrackGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047A8A0
// Name: public: virtual int CDmeTrackGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrackGroup::GetInheritanceDepth(CDmeTrackGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTrackGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047A8E0
// Name: protected: virtual int CDmeTrackGroup::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrackGroup::AllocatedSize(CDmeTrackGroup *this)
{
  return 148;
}

//------------------------------------------------------------------------------
// Address: 0x0047A8F0
// Name: protected: virtual void CDmeTrackGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::PerformConstruction(CDmeTrackGroup *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTrackGroup::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0056AA90
// Name: _dynamic_initializer_for__CDmeTrackGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTrackGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTrackGroup::s_Allocator,
    blockSize: 148,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTrackGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056E510
// Name: _dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTrackGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0047A250
// Name: class CDmeClip __near * FindReferringElement<class CDmeClip>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeClip *__cdecl FindReferringElement<CDmeClip>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeClip *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v5);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeClip>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0056AAC0
// Name: _dynamic_initializer_for__g_CDmeTrackGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTrackGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056AAD0
// Name: _dynamic_initializer_for__g_CDmeTrackGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTrackGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTrackGroup_Helper,
           classname: "DmeTrackGroup",
           pFactory: &g_CDmeTrackGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056E520
// Name: _dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTrackGroup_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0047F170
// Name: public: void CDmeTrackGroup::SetMaxTrackCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::SetMaxTrackCount(CDmeTrackGroup *this, int nCount)
{
  this->m_nMaxTrackCount = nCount;
}

//------------------------------------------------------------------------------
// Address: 0x0047F180
// Name: class CDmeFilmClip __near * GetParentClip(class CDmeTrackGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeFilmClip *__cdecl GetParentClip(CDmeTrackGroup *pTrackGroup)
{
  IDataModel_vtbl *v1; // esi
  int v2; // eax
  DmAttributeReferenceIterator_t v3; // edi
  CDmAttribute *v4; // eax
  CDmElement *m_pOwner; // esi

  v1 = g_pDataModel->__vftable;
  v2 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pTrackGroup);
  v3 = v1->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v2);
  if ( v3 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v3);
    if ( v4 != nullptr )
    {
      m_pOwner = v4->m_pOwner;
      if ( m_pOwner != nullptr && m_pOwner->IsA(this: m_pOwner, a2: CDmeFilmClip::m_classType) )
        break;
    }
    v3 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v3);
    if ( v3 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return (CDmeFilmClip *)m_pOwner;
}

//------------------------------------------------------------------------------
// Address: 0x0047F2C0
// Name: protected: void CDmeTrackGroup::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::OnConstruction(CDmeTrackGroup *this)
{
  CDmaElementArray<CDmeTrack> *p_m_Tracks; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  float v8; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  p_m_Tracks = &this->m_Tracks;
  this->m_Tracks.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "tracks",
                                  type: AT_FIRST_ARRAY_TYPE,
                                  pMemory: &this->m_Tracks);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Tracks->m_pAttribute, typeSymbol: CDmeTrack::m_classType);
  p_m_Tracks->m_pAttribute->m_nFlags |= 0x900u;
  value = true;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_bIsVisible);
  this->m_bIsVisible.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_bMute.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "mute",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bMute);
  v8 = 1.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "displayScale",
         type: AT_FLOAT,
         pMemory: &this->m_flDisplayScale);
  this->m_flDisplayScale.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, value: &v8);
  value = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "minimized", type: AT_BOOL, pMemory: &this->m_bMinimized);
  this->m_bMinimized.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  this->m_nMaxTrackCount = 0x7FFFFFFF;
  v8 = 1.0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "volume", type: AT_FLOAT, pMemory: &this->m_Volume);
  this->m_Volume.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: &v8);
  value = false;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "forcemultitrack",
         type: AT_BOOL,
         pMemory: &this->m_bForceMultiTrack);
  this->m_bForceMultiTrack.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0047F480
// Name: public: class CDmeTrack __near * CDmeTrackGroup::AddTrack(char const __near *,enum DmeClipType_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::AddTrack(CDmeTrackGroup *this, int pTrackName, DmeClipType_t trackType)
{
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmeTrack *v6; // esi

  v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeTrack::m_classType.u.m_Id,
         a3: (const char *)pTrackName,
         a4: this->m_fileId,
         a5: nullptr);
  v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
  v6 = (CDmeTrack *)v5;
  if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeTrack::m_classType) )
    v6 = nullptr;
  CDmeTrack::SetClipType(this: v6, type: trackType);
  CDmeTrack::SetCollapsed(this: v6, state: false);
  if ( v6 != nullptr )
  {
    pTrackName = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v6);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Tracks,
      src: (DmElementHandle_t *)&pTrackName);
    return v6;
  }
  else
  {
    pTrackName = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Tracks,
      src: (DmElementHandle_t *)&pTrackName);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F530
// Name: public: class CDmeTrack __near * CDmeTrackGroup::FindTrack(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::FindTrack(CDmeTrackGroup *this, const char *pTrackName)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  const char *m_pAsString; // eax
  int c; // [esp+Ch] [ebp-4h]

  if ( pTrackName == nullptr )
    pTrackName = "default";
  v3 = 0;
  c = this->m_Tracks.m_Storage.m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeTrack::m_classType) )
    {
      m_pAsString = v5->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &pParentName;
      if ( _V_strcmp(s1: m_pAsString, s2: pTrackName) == 0 )
        break;
    }
    if ( ++v3 >= c )
      return nullptr;
  }
  return (CDmeTrack *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x0047F5C0
// Name: public: int CDmeTrackGroup::GetTrackIndex(class CDmeTrack __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrackGroup::GetTrackIndex(CDmeTrackGroup *this, CDmeTrack *pTrack)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmeTrack *v5; // esi
  int nTracks; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nTracks = this->m_Tracks.m_Storage.m_Size;
  if ( nTracks <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = (CDmeTrack *)v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeTrack::m_classType) )
      v5 = nullptr;
    if ( pTrack == v5 )
      break;
    if ( ++v3 >= nTracks )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0047F640
// Name: public: class CDmeTrack __near * CDmeTrackGroup::CreateFilmTrack(void)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::CreateFilmTrack(CDmeTrackGroup *this)
{
  return CDmeTrackGroup::AddTrack(this, pTrackName: (int)"Film", trackType: DMECLIP_FILM);
}

//------------------------------------------------------------------------------
// Address: 0x0047F650
// Name: public: bool CDmeTrackGroup::FindTrackForClip(class CDmeClip __near *,int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeTrackGroup::FindTrackForClip(
        CDmeTrackGroup *this,
        CDmeClip *pClip,
        int *pTrackIndex,
        int *pClipIndex)
{
  CDmeTrackGroup *v4; // ebx
  int v5; // edi
  CDmElement *v6; // eax
  CDmeTransform *v7; // esi
  CDmAttribute *ClipCount; // ebx
  int v9; // edi
  int c; // [esp+Ch] [ebp-10h]
  DmeClipType_t type; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  v4 = this;
  type = pClip->GetClipType(this: pClip);
  v5 = 0;
  c = v4->m_Tracks.m_Storage.m_Size;
  i = 0;
  if ( c <= 0 )
    return 0;
  while ( 1 )
  {
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4->m_Tracks.m_Storage.m_Memory.m_pMemory[v5]);
    v7 = (CDmeTransform *)v6;
    if ( v6 != nullptr
      && v6->IsA(this: v6, a2: CDmeTrack::m_classType)
      && CDmeTrack::GetClipType(this: (CDmeTrack *)v7) == type )
    {
      ClipCount = CDmeTrack::GetClipCount(this: v7);
      v9 = 0;
      if ( (int)ClipCount > 0 )
        break;
LABEL_8:
      v4 = this;
      v5 = i;
    }
    i = ++v5;
    if ( v5 >= c )
      return 0;
  }
  while ( CDmeTrack::GetClip(this: (CDmeTrack *)v7, i: v9) != pClip )
  {
    if ( ++v9 >= (int)ClipCount )
      goto LABEL_8;
  }
  if ( pTrackIndex != nullptr )
    *pTrackIndex = i;
  if ( pClipIndex != nullptr )
    *pClipIndex = v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047F720
// Name: public: void CDmeTrackGroup::FindClipsAtTime(enum DmeClipType_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsAtTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t time,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v6; // edi
  CDmElement *v7; // eax
  CDmeTrack *v8; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v6 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v6]);
        v8 = (CDmeTrack *)v7;
        if ( v7 != nullptr
          && v7->IsA(this: v7, a2: CDmeTrack::m_classType)
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v8) == clipType) )
        {
          CDmeTrack::FindClipsAtTime(this: v8, time, flags, clips);
        }
        ++v6;
      }
      while ( v6 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F7C0
// Name: public: void CDmeTrackGroup::FindClipsIntersectingTime(enum DmeClipType_t,class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsIntersectingTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t startTime,
        DmeTime_t endTime,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v7; // edi
  CDmElement *v8; // eax
  CDmeTrack *v9; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v7 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = (CDmeTrack *)v8;
        if ( v8 != nullptr
          && v8->IsA(this: v8, a2: CDmeTrack::m_classType)
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v9) == clipType) )
        {
          CDmeTrack::FindClipsIntersectingTime(
            this: v9,
            startTime,
            endTime,
            flags,
            (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)clips);
        }
        ++v7;
      }
      while ( v7 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F860
// Name: public: void CDmeTrackGroup::FindClipsWithinTime(enum DmeClipType_t,class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsWithinTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t startTime,
        DmeTime_t endTime,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v7; // edi
  CDmElement *v8; // eax
  CDmeTrack *v9; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v7 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = (CDmeTrack *)v8;
        if ( v8 != nullptr
          && v8->IsA(this: v8, a2: CDmeTrack::m_classType)
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v9) == clipType) )
        {
          CDmeTrack::FindClipsWithinTime(
            this: v9,
            startTime,
            endTime,
            flags,
            (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)clips);
        }
        ++v7;
      }
      while ( v7 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F900
// Name: public: class CDmeClip __near * CDmeTrackGroup::GetOwnerClip(void)
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeTrackGroup::GetOwnerClip(CDmeTrackGroup *this)
{
  CUtlSymbolLarge *v2; // eax
  CDmeClip *result; // eax
  CUtlSymbolLarge *v4; // eax
  _BYTE v5[4]; // [esp+4h] [ebp-4h] BYREF

  v2 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v5, a3: "subClipTrackGroup");
  result = FindReferringElement<CDmeClip>(
             pElement: this,
             symAttrName: (CUtlSymbolLarge)v2->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  if ( result == nullptr )
  {
    v4 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v5, a3: "trackGroups");
    return FindReferringElement<CDmeClip>(
             pElement: this,
             symAttrName: (CUtlSymbolLarge)v4->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047F970
// Name: public: class CDmeTrack __near * CDmeTrackGroup::FindOrAddTrack(char const __near *,enum DmeClipType_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::FindOrAddTrack(
        CDmeTrackGroup *this,
        const char *pTrackName,
        DmeClipType_t trackType)
{
  CDmeTrack *Track; // eax
  CDmeTrack *v5; // esi

  Track = CDmeTrackGroup::FindTrack(this, pTrackName);
  v5 = Track;
  if ( Track == nullptr )
    return CDmeTrackGroup::AddTrack(this, (int)pTrackName, trackType);
  if ( CDmeTrack::GetClipType(this: Track) != trackType )
    return nullptr;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0047F9C0
// Name: public: void CDmeTrackGroup::RemoveTrack(class CDmeTrack __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::RemoveTrack(CDmeTrackGroup *this, CDmeTrack *pTrack)
{
  int TrackIndex; // eax

  TrackIndex = CDmeTrackGroup::GetTrackIndex(this, pTrack);
  if ( TrackIndex >= 0 )
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
      this: &this->m_Tracks,
      elem: TrackIndex);
}

//------------------------------------------------------------------------------
// Address: 0x0047F9F0
// Name: public: class CDmeTrack __near * CDmeTrackGroup::GetFilmTrack(void)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::GetFilmTrack(CDmeTrackGroup *this)
{
  CDmeClip *OwnerClip; // eax
  bool v3; // zf
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  OwnerClip = CDmeTrackGroup::GetOwnerClip(this);
  if ( OwnerClip != nullptr )
    v3 = OwnerClip->GetFilmTrackGroup(this: OwnerClip) == this;
  else
    v3 = this->m_nMaxTrackCount == 1;
  if ( v3
    && this->m_Tracks.m_Storage.m_Size > 0
    && (v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Tracks.m_Storage.m_Memory.m_pMemory),
        v5 = v4,
        v4 != nullptr)
    && v4->IsA(this: v4, a2: CDmeTrack::m_classType) )
  {
    return (CDmeTrack *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047FA60
// Name: public: class CDmeTrack __near * CDmeTrackGroup::FindTrackForClip(class CDmeClip __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::FindTrackForClip(CDmeTrackGroup *this, CDmeClip *pClip)
{
  CDmElement *v3; // eax
  CDmElement *v4; // esi
  int nTrackIndex; // [esp+4h] [ebp-4h] BYREF

  nTrackIndex = -1;
  if ( CDmeTrackGroup::FindTrackForClip(this, pClip, pTrackIndex: &nTrackIndex, pClipIndex: nullptr) != 0
    && (v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[nTrackIndex]),
        v4 = v3,
        v3 != nullptr)
    && v3->IsA(this: v3, a2: CDmeTrack::m_classType) )
  {
    return (CDmeTrack *)v4;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047FB30
// Name: protected: CDmeTrackGroup::CDmeTrackGroup(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrackGroup *__thiscall CDmeTrackGroup::CDmeTrackGroup(
        CDmeTrackGroup *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTrackGroup_vtbl *)&CDmeTrackGroup::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Tracks);
  this->m_bIsVisible.m_pAttribute = nullptr;
  this->m_bIsVisible.m_Storage = false;
  this->m_bMinimized.m_pAttribute = nullptr;
  this->m_bMinimized.m_Storage = false;
  this->m_bMute.m_pAttribute = nullptr;
  this->m_bMute.m_Storage = false;
  this->m_Volume = 0;
  this->m_flDisplayScale = 0;
  this->m_bForceMultiTrack.m_pAttribute = nullptr;
  this->m_bForceMultiTrack.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0047FBA0
// Name: public: virtual bool CDmeTrackGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTrackGroup::IsA(CDmeTrackGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTrackGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047FBD0
// Name: public: virtual int CDmeTrackGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrackGroup::GetInheritanceDepth(CDmeTrackGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTrackGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047FC10
// Name: protected: virtual int CDmeTrackGroup::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrackGroup::AllocatedSize(CDmeTrackGroup *this)
{
  return 148;
}

//------------------------------------------------------------------------------
// Address: 0x0047FC20
// Name: protected: virtual void CDmeTrackGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::PerformConstruction(CDmeTrackGroup *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTrackGroup::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057AB90
// Name: _dynamic_initializer_for__CDmeTrackGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTrackGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTrackGroup::s_Allocator,
    blockSize: 148,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTrackGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E640
// Name: _dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTrackGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0047F3F0
// Name: class CDmeClip __near * FindReferringElement<class CDmeClip>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeClip *__cdecl FindReferringElement<CDmeClip>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeClip *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v5);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeClip>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0057ABC0
// Name: _dynamic_initializer_for__g_CDmeTrackGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTrackGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057ABD0
// Name: _dynamic_initializer_for__g_CDmeTrackGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTrackGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTrackGroup_Helper,
           classname: "DmeTrackGroup",
           pFactory: &g_CDmeTrackGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E650
// Name: _dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTrackGroup_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005D8740
// Name: public: void CDmeTrackGroup::SetMaxTrackCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::SetMaxTrackCount(vgui::Panel *this, Color color)
{
  this->_bgColor = color;
}

//------------------------------------------------------------------------------
// Address: 0x005D8800
// Name: protected: void CDmeTrackGroup::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::OnConstruction(CDmeTrackGroup *this)
{
  CDmaElementArray<CDmeTrack> *p_m_Tracks; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  float v8; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  p_m_Tracks = &this->m_Tracks;
  this->m_Tracks.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "tracks",
                                  type: AT_FIRST_ARRAY_TYPE,
                                  pMemory: &this->m_Tracks);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Tracks->m_pAttribute, typeSymbol: CDmeTrack::m_classType);
  p_m_Tracks->m_pAttribute->m_nFlags |= 0x900u;
  value = true;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_bIsVisible);
  this->m_bIsVisible.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_bMute.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "mute",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bMute);
  v8 = 1.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "displayScale",
         type: AT_FLOAT,
         pMemory: &this->m_flDisplayScale);
  this->m_flDisplayScale.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, value: &v8);
  value = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "minimized", type: AT_BOOL, pMemory: &this->m_bMinimized);
  this->m_bMinimized.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  this->m_nMaxTrackCount = 0x7FFFFFFF;
  v8 = 1.0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "volume", type: AT_FLOAT, pMemory: &this->m_Volume);
  this->m_Volume.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: &v8);
  value = false;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "forcemultitrack",
         type: AT_BOOL,
         pMemory: &this->m_bForceMultiTrack);
  this->m_bForceMultiTrack.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005D89C0
// Name: public: class CDmeTrack __near * CDmeTrackGroup::AddTrack(char const __near *,enum DmeClipType_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::AddTrack(CDmeTrackGroup *this, int pTrackName, DmeClipType_t trackType)
{
  int v4; // eax
  int v5; // eax
  CDmeTrack *v6; // esi

  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, int, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeTrack::m_classType.u,
         a3: pTrackName,
         a4: this->m_fileId,
         a5: 0);
  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v4);
  v6 = (CDmeTrack *)v5;
  if ( v5 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
         a1: v5,
         a2: CDmeTrack::m_classType.u) == 0 )
  {
    v6 = nullptr;
  }
  CDmeTrack::SetClipType(this: v6, type: trackType);
  CDmeTrack::SetCollapsed(this: v6, state: false);
  if ( v6 != nullptr )
  {
    pTrackName = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v6);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Tracks,
      src: (const DmElementHandle_t *)&pTrackName);
    return v6;
  }
  else
  {
    pTrackName = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Tracks,
      src: (const DmElementHandle_t *)&pTrackName);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D8A70
// Name: public: class CDmeTrack __near * CDmeTrackGroup::CreateFilmTrack(void)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::CreateFilmTrack(CDmeTrackGroup *this)
{
  return CDmeTrackGroup::AddTrack(this, pTrackName: (int)"Film", trackType: DMECLIP_FILM);
}

//------------------------------------------------------------------------------
// Address: 0x005D8A80
// Name: public: bool CDmeTrackGroup::FindTrackForClip(class CDmeClip __near *,int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeTrackGroup::FindTrackForClip(
        CDmeTrackGroup *this,
        CDmeClip *pClip,
        int *pTrackIndex,
        int *pClipIndex)
{
  CDmeTrackGroup *v4; // ebx
  int v5; // edi
  int v6; // eax
  CDmeTransform *v7; // esi
  CDmAttribute *ClipCount; // ebx
  int v9; // edi
  int c; // [esp+Ch] [ebp-10h]
  DmeClipType_t type; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  v4 = this;
  type = pClip->GetClipType(this: pClip);
  v5 = 0;
  c = v4->m_Tracks.m_Storage.m_Size;
  i = 0;
  if ( c <= 0 )
    return 0;
  while ( 1 )
  {
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: v4->m_Tracks.m_Storage.m_Memory.m_pMemory[v5]);
    v7 = (CDmeTransform *)v6;
    if ( v6 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
           a1: v6,
           a2: CDmeTrack::m_classType.u) != 0
      && CDmeTrack::GetClipType(this: (CDmeTrack *)v7) == type )
    {
      ClipCount = CDmeTrack::GetClipCount(this: v7);
      v9 = 0;
      if ( (int)ClipCount > 0 )
        break;
LABEL_8:
      v4 = this;
      v5 = i;
    }
    i = ++v5;
    if ( v5 >= c )
      return 0;
  }
  while ( CDmeTrack::GetClip(this: (CDmeTrack *)v7, i: v9) != pClip )
  {
    if ( ++v9 >= (int)ClipCount )
      goto LABEL_8;
  }
  if ( pTrackIndex != nullptr )
    *pTrackIndex = i;
  if ( pClipIndex != nullptr )
    *pClipIndex = v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005D8B50
// Name: public: void CDmeTrackGroup::FindClipsAtTime(enum DmeClipType_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsAtTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t time,
        DmeClipSkipFlag_t flags,
        CUtlMemory<vgui::TreeNode *,int> *clips)
{
  int v6; // edi
  int v7; // eax
  CDmeTrack *v8; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v6 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v6]);
        v8 = (CDmeTrack *)v7;
        if ( v7 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
               a1: v7,
               a2: CDmeTrack::m_classType.u) != 0
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v8) == clipType) )
        {
          CDmeTrack::FindClipsAtTime(this: v8, time, flags, clips);
        }
        ++v6;
      }
      while ( v6 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D8BF0
// Name: public: void CDmeTrackGroup::FindClipsIntersectingTime(enum DmeClipType_t,class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsIntersectingTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t startTime,
        DmeTime_t endTime,
        DmeClipSkipFlag_t flags,
        CUtlMemory<vgui::TreeNode *,int> *clips)
{
  int v7; // edi
  int v8; // eax
  CDmeTrack *v9; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v7 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = (CDmeTrack *)v8;
        if ( v8 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
               a1: v8,
               a2: CDmeTrack::m_classType.u) != 0
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v9) == clipType) )
        {
          CDmeTrack::FindClipsIntersectingTime(this: v9, startTime, endTime, flags, clips);
        }
        ++v7;
      }
      while ( v7 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D8C90
// Name: public: void CDmeTrackGroup::FindClipsWithinTime(enum DmeClipType_t,class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsWithinTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t startTime,
        DmeTime_t endTime,
        DmeClipSkipFlag_t flags,
        CUtlMemory<vgui::TreeNode *,int> *clips)
{
  int v7; // edi
  int v8; // eax
  CDmeTrack *v9; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v7 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = (CDmeTrack *)v8;
        if ( v8 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
               a1: v8,
               a2: CDmeTrack::m_classType.u) != 0
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v9) == clipType) )
        {
          CDmeTrack::FindClipsWithinTime(this: v9, startTime, endTime, flags, clips);
        }
        ++v7;
      }
      while ( v7 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D8D30
// Name: public: class CDmeClip __near * CDmeTrackGroup::GetOwnerClip(void)
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeTrackGroup::GetOwnerClip(CDmeTrackGroup *this)
{
  CUtlSymbolLarge *v2; // eax
  CDmeClip *result; // eax
  CUtlSymbolLarge *v4; // eax
  _BYTE v5[4]; // [esp+4h] [ebp-4h] BYREF

  v2 = (CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                            a1: g_pDataModel.u,
                            a2: v5,
                            a3: "subClipTrackGroup");
  result = FindReferringElement<CDmeClip>(
             pElement: this,
             symAttrName: (CUtlSymbolLarge)v2->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  if ( result == nullptr )
  {
    v4 = (CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                              a1: g_pDataModel.u,
                              a2: v5,
                              a3: "trackGroups");
    return FindReferringElement<CDmeClip>(
             pElement: this,
             symAttrName: (CUtlSymbolLarge)v4->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005D8DA0
// Name: public: class CDmeTrack __near * CDmeTrackGroup::GetFilmTrack(void)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::GetFilmTrack(CDmeTrackGroup *this)
{
  CDmeClip *OwnerClip; // eax
  bool v3; // zf
  int v4; // eax
  int v5; // esi

  OwnerClip = CDmeTrackGroup::GetOwnerClip(this);
  if ( OwnerClip != nullptr )
    v3 = OwnerClip->GetFilmTrackGroup(this: OwnerClip) == this;
  else
    v3 = this->m_nMaxTrackCount == 1;
  if ( v3
    && this->m_Tracks.m_Storage.m_Size > 0
    && (v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: *this->m_Tracks.m_Storage.m_Memory.m_pMemory),
        v5 = v4,
        v4 != 0)
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeTrack::m_classType.u) != 0 )
  {
    return (CDmeTrack *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D8E10
// Name: public: class CDmeTrack __near * CDmeTrackGroup::FindTrackForClip(class CDmeClip __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::FindTrackForClip(CDmeTrackGroup *this, CDmeClip *pClip)
{
  int v3; // eax
  int v4; // esi
  int nTrackIndex; // [esp+4h] [ebp-4h] BYREF

  nTrackIndex = -1;
  if ( CDmeTrackGroup::FindTrackForClip(this, pClip, pTrackIndex: &nTrackIndex, pClipIndex: nullptr) != 0
    && (v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[nTrackIndex]),
        v4 = v3,
        v3 != 0)
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
         a1: v3,
         a2: CDmeTrack::m_classType.u) != 0 )
  {
    return (CDmeTrack *)v4;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D8EE0
// Name: protected: CDmeTrackGroup::CDmeTrackGroup(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrackGroup *__thiscall CDmeTrackGroup::CDmeTrackGroup(
        CDmeTrackGroup *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTrackGroup_vtbl *)&CDmeTrackGroup::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Tracks);
  this->m_bIsVisible.m_pAttribute = nullptr;
  this->m_bIsVisible.m_Storage = false;
  this->m_bMinimized.m_pAttribute = nullptr;
  this->m_bMinimized.m_Storage = false;
  this->m_bMute.m_pAttribute = nullptr;
  this->m_bMute.m_Storage = false;
  this->m_Volume = 0;
  this->m_flDisplayScale = 0;
  this->m_bForceMultiTrack.m_pAttribute = nullptr;
  this->m_bForceMultiTrack.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005D8F50
// Name: public: virtual bool CDmeTrackGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTrackGroup::IsA(CDmeTrackGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTrackGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D8F80
// Name: public: virtual int CDmeTrackGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrackGroup::GetInheritanceDepth(CDmeTrackGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTrackGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D8FC0
// Name: protected: virtual void CDmeTrackGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::PerformConstruction(CDmeTrackGroup *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeTrackGroup::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B0BF0
// Name: _dynamic_initializer_for__CDmeTrackGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTrackGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTrackGroup::s_Allocator,
    blockSize: 148,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTrackGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5330
// Name: _dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTrackGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005D8930
// Name: class CDmeClip __near * FindReferringElement<class CDmeClip>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeClip *__cdecl FindReferringElement<CDmeClip>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v4; // esi
  int BufferType; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeClip *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = *(_DWORD *)g_pDataModel.u.m_Id;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v4 + 436))(a1: g_pDataModel.u, a2: BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeClip>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( result != nullptr )
      break;
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 440))(
           a1: g_pDataModel.u,
           a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006B0C20
// Name: _dynamic_initializer_for__g_CDmeTrackGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTrackGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0C30
// Name: _dynamic_initializer_for__g_CDmeTrackGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTrackGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTrackGroup_Helper,
           classname: "DmeTrackGroup",
           pFactory: &g_CDmeTrackGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5340
// Name: _dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeTrackGroup_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00480120
// Name: public: void CDmeTrackGroup::SetMaxTrackCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::SetMaxTrackCount(CDmeTrackGroup *this, int nCount)
{
  this->m_nMaxTrackCount = nCount;
}

//------------------------------------------------------------------------------
// Address: 0x00480130
// Name: class CDmeFilmClip __near * GetParentClip(class CDmeTrackGroup __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeFilmClip *__cdecl GetParentClip(CDmeTrackGroup *pTrackGroup)
{
  IDataModel_vtbl *v1; // esi
  int v2; // eax
  DmAttributeReferenceIterator_t v3; // edi
  CDmAttribute *v4; // eax
  CDmElement *m_pOwner; // esi

  v1 = g_pDataModel->__vftable;
  v2 = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pTrackGroup);
  v3 = v1->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v2);
  if ( v3 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v3);
    if ( v4 != nullptr )
    {
      m_pOwner = v4->m_pOwner;
      if ( m_pOwner != nullptr && m_pOwner->IsA(this: m_pOwner, a2: CDmeFilmClip::m_classType) )
        break;
    }
    v3 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v3);
    if ( v3 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return (CDmeFilmClip *)m_pOwner;
}

//------------------------------------------------------------------------------
// Address: 0x00480270
// Name: protected: void CDmeTrackGroup::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::OnConstruction(CDmeTrackGroup *this)
{
  CDmaElementArray<CDmeTrack> *p_m_Tracks; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  float v8; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  p_m_Tracks = &this->m_Tracks;
  this->m_Tracks.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "tracks",
                                  type: AT_FIRST_ARRAY_TYPE,
                                  pMemory: &this->m_Tracks);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Tracks->m_pAttribute, typeSymbol: CDmeTrack::m_classType);
  p_m_Tracks->m_pAttribute->m_nFlags |= 0x900u;
  value = true;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_bIsVisible);
  this->m_bIsVisible.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_bMute.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "mute",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bMute);
  v8 = 1.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "displayScale",
         type: AT_FLOAT,
         pMemory: &this->m_flDisplayScale);
  this->m_flDisplayScale.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, value: &v8);
  value = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "minimized", type: AT_BOOL, pMemory: &this->m_bMinimized);
  this->m_bMinimized.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  this->m_nMaxTrackCount = 0x7FFFFFFF;
  v8 = 1.0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "volume", type: AT_FLOAT, pMemory: &this->m_Volume);
  this->m_Volume.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: &v8);
  value = false;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "forcemultitrack",
         type: AT_BOOL,
         pMemory: &this->m_bForceMultiTrack);
  this->m_bForceMultiTrack.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00480430
// Name: public: class CDmeTrack __near * CDmeTrackGroup::AddTrack(char const __near *,enum DmeClipType_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::AddTrack(CDmeTrackGroup *this, int pTrackName, DmeClipType_t trackType)
{
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmeTrack *v6; // esi

  v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeTrack::m_classType.u.m_Id,
         a3: (const char *)pTrackName,
         a4: this->m_fileId,
         a5: nullptr);
  v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
  v6 = (CDmeTrack *)v5;
  if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeTrack::m_classType) )
    v6 = nullptr;
  CDmeTrack::SetClipType(this: v6, type: trackType);
  CDmeTrack::SetCollapsed(this: v6, state: false);
  if ( v6 != nullptr )
  {
    pTrackName = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v6);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Tracks,
      src: (const DmElementHandle_t *)&pTrackName);
    return v6;
  }
  else
  {
    pTrackName = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Tracks,
      src: (const DmElementHandle_t *)&pTrackName);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004804E0
// Name: public: class CDmeTrack __near * CDmeTrackGroup::FindTrack(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::FindTrack(CDmeTrackGroup *this, const char *pTrackName)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  const char *m_pAsString; // eax
  int c; // [esp+Ch] [ebp-4h]

  if ( pTrackName == nullptr )
    pTrackName = "default";
  v3 = 0;
  c = this->m_Tracks.m_Storage.m_Size;
  if ( c <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeTrack::m_classType) )
    {
      m_pAsString = v5->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &pch;
      if ( _V_strcmp(s1: m_pAsString, s2: pTrackName) == 0 )
        break;
    }
    if ( ++v3 >= c )
      return nullptr;
  }
  return (CDmeTrack *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x00480570
// Name: public: int CDmeTrackGroup::GetTrackIndex(class CDmeTrack __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrackGroup::GetTrackIndex(CDmeTrackGroup *this, CDmeTrack *pTrack)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmeTrack *v5; // esi
  int nTracks; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nTracks = this->m_Tracks.m_Storage.m_Size;
  if ( nTracks <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = (CDmeTrack *)v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeTrack::m_classType) )
      v5 = nullptr;
    if ( pTrack == v5 )
      break;
    if ( ++v3 >= nTracks )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004805F0
// Name: public: class CDmeTrack __near * CDmeTrackGroup::CreateFilmTrack(void)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::CreateFilmTrack(CDmeTrackGroup *this)
{
  return CDmeTrackGroup::AddTrack(this, pTrackName: (int)"Film", trackType: DMECLIP_FILM);
}

//------------------------------------------------------------------------------
// Address: 0x00480600
// Name: public: bool CDmeTrackGroup::FindTrackForClip(class CDmeClip __near *,int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeTrackGroup::FindTrackForClip(
        CDmeTrackGroup *this,
        CDmeClip *pClip,
        int *pTrackIndex,
        int *pClipIndex)
{
  CDmeTrackGroup *v4; // ebx
  int v5; // edi
  CDmElement *v6; // eax
  CDmeTransform *v7; // esi
  CDmAttribute *ClipCount; // ebx
  int v9; // edi
  int c; // [esp+Ch] [ebp-10h]
  DmeClipType_t type; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  v4 = this;
  type = pClip->GetClipType(this: pClip);
  v5 = 0;
  c = v4->m_Tracks.m_Storage.m_Size;
  i = 0;
  if ( c <= 0 )
    return 0;
  while ( 1 )
  {
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4->m_Tracks.m_Storage.m_Memory.m_pMemory[v5]);
    v7 = (CDmeTransform *)v6;
    if ( v6 != nullptr
      && v6->IsA(this: v6, a2: CDmeTrack::m_classType)
      && CDmeTrack::GetClipType(this: (CDmeTrack *)v7) == type )
    {
      ClipCount = CDmeTrack::GetClipCount(this: v7);
      v9 = 0;
      if ( (int)ClipCount > 0 )
        break;
LABEL_8:
      v4 = this;
      v5 = i;
    }
    i = ++v5;
    if ( v5 >= c )
      return 0;
  }
  while ( CDmeTrack::GetClip(this: (CDmeTrack *)v7, i: v9) != pClip )
  {
    if ( ++v9 >= (int)ClipCount )
      goto LABEL_8;
  }
  if ( pTrackIndex != nullptr )
    *pTrackIndex = i;
  if ( pClipIndex != nullptr )
    *pClipIndex = v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004806D0
// Name: public: void CDmeTrackGroup::FindClipsAtTime(enum DmeClipType_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsAtTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t time,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v6; // edi
  CDmElement *v7; // eax
  CDmeTrack *v8; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v6 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v6]);
        v8 = (CDmeTrack *)v7;
        if ( v7 != nullptr
          && v7->IsA(this: v7, a2: CDmeTrack::m_classType)
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v8) == clipType) )
        {
          CDmeTrack::FindClipsAtTime(this: v8, time, flags, clips);
        }
        ++v6;
      }
      while ( v6 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480770
// Name: public: void CDmeTrackGroup::FindClipsIntersectingTime(enum DmeClipType_t,class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsIntersectingTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t startTime,
        DmeTime_t endTime,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v7; // edi
  CDmElement *v8; // eax
  CDmeTrack *v9; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v7 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = (CDmeTrack *)v8;
        if ( v8 != nullptr
          && v8->IsA(this: v8, a2: CDmeTrack::m_classType)
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v9) == clipType) )
        {
          CDmeTrack::FindClipsIntersectingTime(
            this: v9,
            startTime,
            endTime,
            flags,
            (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)clips);
        }
        ++v7;
      }
      while ( v7 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480810
// Name: public: void CDmeTrackGroup::FindClipsWithinTime(enum DmeClipType_t,class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsWithinTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t startTime,
        DmeTime_t endTime,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v7; // edi
  CDmElement *v8; // eax
  CDmeTrack *v9; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v7 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = (CDmeTrack *)v8;
        if ( v8 != nullptr
          && v8->IsA(this: v8, a2: CDmeTrack::m_classType)
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v9) == clipType) )
        {
          CDmeTrack::FindClipsWithinTime(
            this: v9,
            startTime,
            endTime,
            flags,
            (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)clips);
        }
        ++v7;
      }
      while ( v7 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004808B0
// Name: public: class CDmeClip __near * CDmeTrackGroup::GetOwnerClip(void)
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeTrackGroup::GetOwnerClip(CDmeTrackGroup *this)
{
  CUtlSymbolLarge *v2; // eax
  CDmeClip *result; // eax
  CUtlSymbolLarge *v4; // eax
  _BYTE v5[4]; // [esp+4h] [ebp-4h] BYREF

  v2 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v5, a3: "subClipTrackGroup");
  result = FindReferringElement<CDmeClip>(
             pElement: this,
             symAttrName: (CUtlSymbolLarge)v2->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  if ( result == nullptr )
  {
    v4 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v5, a3: "trackGroups");
    return FindReferringElement<CDmeClip>(
             pElement: this,
             symAttrName: (CUtlSymbolLarge)v4->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00480920
// Name: public: class CDmeTrack __near * CDmeTrackGroup::FindOrAddTrack(char const __near *,enum DmeClipType_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::FindOrAddTrack(
        CDmeTrackGroup *this,
        const char *pTrackName,
        DmeClipType_t trackType)
{
  CDmeTrack *Track; // eax
  CDmeTrack *v5; // esi

  Track = CDmeTrackGroup::FindTrack(this, pTrackName);
  v5 = Track;
  if ( Track == nullptr )
    return CDmeTrackGroup::AddTrack(this, (int)pTrackName, trackType);
  if ( CDmeTrack::GetClipType(this: Track) != trackType )
    return nullptr;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00480970
// Name: public: void CDmeTrackGroup::RemoveTrack(class CDmeTrack __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::RemoveTrack(CDmeTrackGroup *this, CDmeTrack *pTrack)
{
  int TrackIndex; // eax

  TrackIndex = CDmeTrackGroup::GetTrackIndex(this, pTrack);
  if ( TrackIndex >= 0 )
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
      this: &this->m_Tracks,
      elem: TrackIndex);
}

//------------------------------------------------------------------------------
// Address: 0x004809A0
// Name: public: class CDmeTrack __near * CDmeTrackGroup::GetFilmTrack(void)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::GetFilmTrack(CDmeTrackGroup *this)
{
  CDmeClip *OwnerClip; // eax
  bool v3; // zf
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  OwnerClip = CDmeTrackGroup::GetOwnerClip(this);
  if ( OwnerClip != nullptr )
    v3 = OwnerClip->GetFilmTrackGroup(this: OwnerClip) == this;
  else
    v3 = this->m_nMaxTrackCount == 1;
  if ( v3
    && this->m_Tracks.m_Storage.m_Size > 0
    && (v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Tracks.m_Storage.m_Memory.m_pMemory),
        v5 = v4,
        v4 != nullptr)
    && v4->IsA(this: v4, a2: CDmeTrack::m_classType) )
  {
    return (CDmeTrack *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480A10
// Name: public: class CDmeTrack __near * CDmeTrackGroup::FindTrackForClip(class CDmeClip __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::FindTrackForClip(CDmeTrackGroup *this, CDmeClip *pClip)
{
  CDmElement *v3; // eax
  CDmElement *v4; // esi
  int nTrackIndex; // [esp+4h] [ebp-4h] BYREF

  nTrackIndex = -1;
  if ( CDmeTrackGroup::FindTrackForClip(this, pClip, pTrackIndex: &nTrackIndex, pClipIndex: nullptr) != 0
    && (v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[nTrackIndex]),
        v4 = v3,
        v3 != nullptr)
    && v3->IsA(this: v3, a2: CDmeTrack::m_classType) )
  {
    return (CDmeTrack *)v4;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480AE0
// Name: protected: CDmeTrackGroup::CDmeTrackGroup(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrackGroup *__thiscall CDmeTrackGroup::CDmeTrackGroup(
        CDmeTrackGroup *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTrackGroup_vtbl *)&CDmeTrackGroup::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Tracks);
  this->m_bIsVisible.m_pAttribute = nullptr;
  this->m_bIsVisible.m_Storage = false;
  this->m_bMinimized.m_pAttribute = nullptr;
  this->m_bMinimized.m_Storage = false;
  this->m_bMute.m_pAttribute = nullptr;
  this->m_bMute.m_Storage = false;
  this->m_Volume = 0;
  this->m_flDisplayScale = 0;
  this->m_bForceMultiTrack.m_pAttribute = nullptr;
  this->m_bForceMultiTrack.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00480B50
// Name: public: virtual bool CDmeTrackGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTrackGroup::IsA(CDmeTrackGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTrackGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00480B80
// Name: public: virtual int CDmeTrackGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrackGroup::GetInheritanceDepth(CDmeTrackGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTrackGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00480BC0
// Name: protected: virtual int CDmeTrackGroup::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrackGroup::AllocatedSize(CDmeTrackGroup *this)
{
  return 148;
}

//------------------------------------------------------------------------------
// Address: 0x00480BD0
// Name: protected: virtual void CDmeTrackGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::PerformConstruction(CDmeTrackGroup *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTrackGroup::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057CB80
// Name: _dynamic_initializer_for__CDmeTrackGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTrackGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTrackGroup::s_Allocator,
    blockSize: 148,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTrackGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580620
// Name: _dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTrackGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x004803A0
// Name: class CDmeClip __near * FindReferringElement<class CDmeClip>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeClip *__cdecl FindReferringElement<CDmeClip>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeClip *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v5);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeClip>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0057CBB0
// Name: _dynamic_initializer_for__g_CDmeTrackGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTrackGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CBC0
// Name: _dynamic_initializer_for__g_CDmeTrackGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTrackGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTrackGroup_Helper,
           classname: "DmeTrackGroup",
           pFactory: &g_CDmeTrackGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00580630
// Name: _dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTrackGroup_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x00508230
// Name: public: void CDmeTrackGroup::SetMaxTrackCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::SetMaxTrackCount(CDmeTrackGroup *this, int nCount)
{
  this->m_nMaxTrackCount = nCount;
}

//------------------------------------------------------------------------------
// Address: 0x005082F0
// Name: protected: void CDmeTrackGroup::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::OnConstruction(CDmeTrackGroup *this)
{
  CDmaElementArray<CDmeTrack> *p_m_Tracks; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  float v8; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  p_m_Tracks = &this->m_Tracks;
  this->m_Tracks.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "tracks",
                                  type: AT_FIRST_ARRAY_TYPE,
                                  pMemory: &this->m_Tracks);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Tracks->m_pAttribute, typeSymbol: CDmeTrack::m_classType);
  p_m_Tracks->m_pAttribute->m_nFlags |= 0x900u;
  value = true;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_bIsVisible);
  this->m_bIsVisible.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_bMute.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "mute",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bMute);
  v8 = 1.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "displayScale",
         type: AT_FLOAT,
         pMemory: &this->m_flDisplayScale);
  this->m_flDisplayScale.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, value: &v8);
  value = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "minimized", type: AT_BOOL, pMemory: &this->m_bMinimized);
  this->m_bMinimized.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  this->m_nMaxTrackCount = 0x7FFFFFFF;
  v8 = 1.0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "volume", type: AT_FLOAT, pMemory: &this->m_Volume);
  this->m_Volume.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: &v8);
  value = false;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "forcemultitrack",
         type: AT_BOOL,
         pMemory: &this->m_bForceMultiTrack);
  this->m_bForceMultiTrack.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005084B0
// Name: public: class CDmeTrack __near * CDmeTrackGroup::AddTrack(char const __near *,enum DmeClipType_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::AddTrack(CDmeTrackGroup *this, int pTrackName, DmeClipType_t trackType)
{
  int v4; // eax
  int v5; // eax
  CDmeTrack *v6; // esi

  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, int, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeTrack::m_classType.u,
         a3: pTrackName,
         a4: this->m_fileId,
         a5: 0);
  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v4);
  v6 = (CDmeTrack *)v5;
  if ( v5 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
         a1: v5,
         a2: CDmeTrack::m_classType.u) == 0 )
  {
    v6 = nullptr;
  }
  CDmeTrack::SetClipType(this: v6, type: trackType);
  CDmeTrack::SetCollapsed(this: v6, state: false);
  if ( v6 != nullptr )
  {
    pTrackName = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v6);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Tracks,
      src: (DmElementHandle_t *)&pTrackName);
    return v6;
  }
  else
  {
    pTrackName = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Tracks,
      src: (DmElementHandle_t *)&pTrackName);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00508560
// Name: public: class CDmeTrack __near * CDmeTrackGroup::CreateFilmTrack(void)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::CreateFilmTrack(CDmeTrackGroup *this)
{
  return CDmeTrackGroup::AddTrack(this, pTrackName: (int)"Film", trackType: DMECLIP_FILM);
}

//------------------------------------------------------------------------------
// Address: 0x00508570
// Name: public: bool CDmeTrackGroup::FindTrackForClip(class CDmeClip __near *,int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeTrackGroup::FindTrackForClip(
        CDmeTrackGroup *this,
        CDmeClip *pClip,
        int *pTrackIndex,
        int *pClipIndex)
{
  CDmeTrackGroup *v4; // ebx
  int v5; // edi
  int v6; // eax
  CDmeTransform *v7; // esi
  CDmAttribute *ClipCount; // ebx
  int v9; // edi
  int c; // [esp+Ch] [ebp-10h]
  DmeClipType_t type; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  v4 = this;
  type = pClip->GetClipType(this: pClip);
  v5 = 0;
  c = v4->m_Tracks.m_Storage.m_Size;
  i = 0;
  if ( c <= 0 )
    return 0;
  while ( 1 )
  {
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: v4->m_Tracks.m_Storage.m_Memory.m_pMemory[v5]);
    v7 = (CDmeTransform *)v6;
    if ( v6 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
           a1: v6,
           a2: CDmeTrack::m_classType.u) != 0
      && CDmeTrack::GetClipType(this: (CDmeTrack *)v7) == type )
    {
      ClipCount = CDmeTrack::GetClipCount(this: v7);
      v9 = 0;
      if ( (int)ClipCount > 0 )
        break;
LABEL_8:
      v4 = this;
      v5 = i;
    }
    i = ++v5;
    if ( v5 >= c )
      return 0;
  }
  while ( CDmeTrack::GetClip(this: (CDmeTrack *)v7, i: v9) != pClip )
  {
    if ( ++v9 >= (int)ClipCount )
      goto LABEL_8;
  }
  if ( pTrackIndex != nullptr )
    *pTrackIndex = i;
  if ( pClipIndex != nullptr )
    *pClipIndex = v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00508640
// Name: public: void CDmeTrackGroup::FindClipsAtTime(enum DmeClipType_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsAtTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t time,
        DmeClipSkipFlag_t flags,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *clips)
{
  int v6; // edi
  int v7; // eax
  CDmeTrack *v8; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v6 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v6]);
        v8 = (CDmeTrack *)v7;
        if ( v7 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
               a1: v7,
               a2: CDmeTrack::m_classType.u) != 0
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v8) == clipType) )
        {
          CDmeTrack::FindClipsAtTime(this: v8, time, flags, clips);
        }
        ++v6;
      }
      while ( v6 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005086E0
// Name: public: void CDmeTrackGroup::FindClipsIntersectingTime(enum DmeClipType_t,class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsIntersectingTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t startTime,
        DmeTime_t endTime,
        DmeClipSkipFlag_t flags,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *clips)
{
  int v7; // edi
  int v8; // eax
  CDmeTrack *v9; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v7 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = (CDmeTrack *)v8;
        if ( v8 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
               a1: v8,
               a2: CDmeTrack::m_classType.u) != 0
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v9) == clipType) )
        {
          CDmeTrack::FindClipsIntersectingTime(this: v9, startTime, endTime, flags, clips);
        }
        ++v7;
      }
      while ( v7 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00508780
// Name: public: void CDmeTrackGroup::FindClipsWithinTime(enum DmeClipType_t,class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsWithinTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t startTime,
        DmeTime_t endTime,
        DmeClipSkipFlag_t flags,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *clips)
{
  int v7; // edi
  int v8; // eax
  CDmeTrack *v9; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v7 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = (CDmeTrack *)v8;
        if ( v8 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
               a1: v8,
               a2: CDmeTrack::m_classType.u) != 0
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v9) == clipType) )
        {
          CDmeTrack::FindClipsWithinTime(this: v9, startTime, endTime, flags, clips);
        }
        ++v7;
      }
      while ( v7 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00508820
// Name: public: class CDmeClip __near * CDmeTrackGroup::GetOwnerClip(void)
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeTrackGroup::GetOwnerClip(CDmeTrackGroup *this)
{
  CUtlSymbolLarge *v2; // eax
  CDmeClip *result; // eax
  CUtlSymbolLarge *v4; // eax
  _BYTE v5[4]; // [esp+4h] [ebp-4h] BYREF

  v2 = (CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                            a1: g_pDataModel.u,
                            a2: v5,
                            a3: "subClipTrackGroup");
  result = FindReferringElement<CDmeClip>(
             pElement: this,
             symAttrName: (CUtlSymbolLarge)v2->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  if ( result == nullptr )
  {
    v4 = (CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                              a1: g_pDataModel.u,
                              a2: v5,
                              a3: "trackGroups");
    return FindReferringElement<CDmeClip>(
             pElement: this,
             symAttrName: (CUtlSymbolLarge)v4->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00508890
// Name: public: class CDmeTrack __near * CDmeTrackGroup::GetFilmTrack(void)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::GetFilmTrack(CDmeTrackGroup *this)
{
  CDmeClip *OwnerClip; // eax
  bool v3; // zf
  int v4; // eax
  int v5; // esi

  OwnerClip = CDmeTrackGroup::GetOwnerClip(this);
  if ( OwnerClip != nullptr )
    v3 = OwnerClip->GetFilmTrackGroup(this: OwnerClip) == this;
  else
    v3 = this->m_nMaxTrackCount == 1;
  if ( v3
    && this->m_Tracks.m_Storage.m_Size > 0
    && (v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: *this->m_Tracks.m_Storage.m_Memory.m_pMemory),
        v5 = v4,
        v4 != 0)
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeTrack::m_classType.u) != 0 )
  {
    return (CDmeTrack *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00508900
// Name: public: class CDmeTrack __near * CDmeTrackGroup::FindTrackForClip(class CDmeClip __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::FindTrackForClip(CDmeTrackGroup *this, CDmeClip *pClip)
{
  int v3; // eax
  int v4; // esi
  int nTrackIndex; // [esp+4h] [ebp-4h] BYREF

  nTrackIndex = -1;
  if ( CDmeTrackGroup::FindTrackForClip(this, pClip, pTrackIndex: &nTrackIndex, pClipIndex: nullptr) != 0
    && (v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[nTrackIndex]),
        v4 = v3,
        v3 != 0)
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
         a1: v3,
         a2: CDmeTrack::m_classType.u) != 0 )
  {
    return (CDmeTrack *)v4;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005089D0
// Name: protected: CDmeTrackGroup::CDmeTrackGroup(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrackGroup *__thiscall CDmeTrackGroup::CDmeTrackGroup(
        CDmeTrackGroup *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTrackGroup_vtbl *)&CDmeTrackGroup::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Tracks);
  this->m_bIsVisible.m_pAttribute = nullptr;
  this->m_bIsVisible.m_Storage = false;
  this->m_bMinimized.m_pAttribute = nullptr;
  this->m_bMinimized.m_Storage = false;
  this->m_bMute.m_pAttribute = nullptr;
  this->m_bMute.m_Storage = false;
  this->m_Volume = 0;
  this->m_flDisplayScale = 0;
  this->m_bForceMultiTrack.m_pAttribute = nullptr;
  this->m_bForceMultiTrack.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00508A40
// Name: public: virtual bool CDmeTrackGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTrackGroup::IsA(CDmeTrackGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTrackGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00508A70
// Name: public: virtual int CDmeTrackGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrackGroup::GetInheritanceDepth(CDmeTrackGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTrackGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00508AB0
// Name: protected: virtual void CDmeTrackGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::PerformConstruction(CDmeTrackGroup *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTrackGroup::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005E97D0
// Name: _dynamic_initializer_for__CDmeTrackGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTrackGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTrackGroup::s_Allocator,
    blockSize: 148,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTrackGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED300
// Name: _dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTrackGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00508420
// Name: class CDmeClip __near * FindReferringElement<class CDmeClip>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeClip *__cdecl FindReferringElement<CDmeClip>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeClip *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = *(_DWORD *)g_pDataModel.u.m_Id;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v4 + 436))(a1: g_pDataModel.u, a2: v5);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeClip>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( result != nullptr )
      break;
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 440))(
           a1: g_pDataModel.u,
           a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005E9800
// Name: _dynamic_initializer_for__g_CDmeTrackGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTrackGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E9810
// Name: _dynamic_initializer_for__g_CDmeTrackGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTrackGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTrackGroup_Helper,
           classname: "DmeTrackGroup",
           pFactory: &g_CDmeTrackGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED310
// Name: _dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTrackGroup_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00488C20
// Name: public: void CDmeTrackGroup::SetMaxTrackCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::SetMaxTrackCount(CDmeTrackGroup *this, int nCount)
{
  this->m_nMaxTrackCount = nCount;
}

//------------------------------------------------------------------------------
// Address: 0x00488CE0
// Name: protected: void CDmeTrackGroup::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::OnConstruction(CDmeTrackGroup *this)
{
  CDmaElementArray<CDmeTrack> *p_m_Tracks; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  float v8; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  p_m_Tracks = &this->m_Tracks;
  this->m_Tracks.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "tracks",
                                  type: AT_FIRST_ARRAY_TYPE,
                                  pMemory: &this->m_Tracks);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Tracks->m_pAttribute, typeSymbol: CDmeTrack::m_classType);
  p_m_Tracks->m_pAttribute->m_nFlags |= 0x900u;
  value = true;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_bIsVisible);
  this->m_bIsVisible.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_bMute.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "mute",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bMute);
  v8 = 1.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "displayScale",
         type: AT_FLOAT,
         pMemory: &this->m_flDisplayScale);
  this->m_flDisplayScale.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, value: &v8);
  value = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "minimized", type: AT_BOOL, pMemory: &this->m_bMinimized);
  this->m_bMinimized.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  this->m_nMaxTrackCount = 0x7FFFFFFF;
  v8 = 1.0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "volume", type: AT_FLOAT, pMemory: &this->m_Volume);
  this->m_Volume.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: &v8);
  value = false;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "forcemultitrack",
         type: AT_BOOL,
         pMemory: &this->m_bForceMultiTrack);
  this->m_bForceMultiTrack.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00488EA0
// Name: public: class CDmeTrack __near * CDmeTrackGroup::AddTrack(char const __near *,enum DmeClipType_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::AddTrack(CDmeTrackGroup *this, int pTrackName, DmeClipType_t trackType)
{
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmeTrack *v6; // esi

  v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeTrack::m_classType.u.m_Id,
         a3: (const char *)pTrackName,
         a4: this->m_fileId,
         a5: nullptr);
  v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
  v6 = (CDmeTrack *)v5;
  if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeTrack::m_classType) )
    v6 = nullptr;
  CDmeTrack::SetClipType(this: v6, type: trackType);
  CDmeTrack::SetCollapsed(this: v6, state: false);
  if ( v6 != nullptr )
  {
    pTrackName = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v6);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Tracks,
      src: (const DmElementHandle_t *)&pTrackName);
    return v6;
  }
  else
  {
    pTrackName = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Tracks,
      src: (const DmElementHandle_t *)&pTrackName);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00488F50
// Name: public: class CDmeTrack __near * CDmeTrackGroup::CreateFilmTrack(void)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::CreateFilmTrack(CDmeTrackGroup *this)
{
  return CDmeTrackGroup::AddTrack(this, pTrackName: (int)"Film", trackType: DMECLIP_FILM);
}

//------------------------------------------------------------------------------
// Address: 0x00488F60
// Name: public: bool CDmeTrackGroup::FindTrackForClip(class CDmeClip __near *,int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeTrackGroup::FindTrackForClip(
        CDmeTrackGroup *this,
        CDmeClip *pClip,
        int *pTrackIndex,
        int *pClipIndex)
{
  CDmeTrackGroup *v4; // ebx
  int v5; // edi
  CDmElement *v6; // eax
  CDmeTransform *v7; // esi
  CDmAttribute *ClipCount; // ebx
  int v9; // edi
  int c; // [esp+Ch] [ebp-10h]
  DmeClipType_t type; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  v4 = this;
  type = pClip->GetClipType(this: pClip);
  v5 = 0;
  c = v4->m_Tracks.m_Storage.m_Size;
  i = 0;
  if ( c <= 0 )
    return 0;
  while ( 1 )
  {
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4->m_Tracks.m_Storage.m_Memory.m_pMemory[v5]);
    v7 = (CDmeTransform *)v6;
    if ( v6 != nullptr
      && v6->IsA(this: v6, a2: CDmeTrack::m_classType)
      && CDmeTrack::GetClipType(this: (CDmeTrack *)v7) == type )
    {
      ClipCount = CDmeTrack::GetClipCount(this: v7);
      v9 = 0;
      if ( (int)ClipCount > 0 )
        break;
LABEL_8:
      v4 = this;
      v5 = i;
    }
    i = ++v5;
    if ( v5 >= c )
      return 0;
  }
  while ( CDmeTrack::GetClip(this: (CDmeTrack *)v7, i: v9) != pClip )
  {
    if ( ++v9 >= (int)ClipCount )
      goto LABEL_8;
  }
  if ( pTrackIndex != nullptr )
    *pTrackIndex = i;
  if ( pClipIndex != nullptr )
    *pClipIndex = v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00489030
// Name: public: void CDmeTrackGroup::FindClipsAtTime(enum DmeClipType_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsAtTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t time,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v6; // edi
  CDmElement *v7; // eax
  CDmeTrack *v8; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v6 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v6]);
        v8 = (CDmeTrack *)v7;
        if ( v7 != nullptr
          && v7->IsA(this: v7, a2: CDmeTrack::m_classType)
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v8) == clipType) )
        {
          CDmeTrack::FindClipsAtTime(this: v8, time, flags, clips);
        }
        ++v6;
      }
      while ( v6 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004890D0
// Name: public: void CDmeTrackGroup::FindClipsIntersectingTime(enum DmeClipType_t,class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsIntersectingTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t startTime,
        DmeTime_t endTime,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v7; // edi
  CDmElement *v8; // eax
  CDmeTrack *v9; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v7 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = (CDmeTrack *)v8;
        if ( v8 != nullptr
          && v8->IsA(this: v8, a2: CDmeTrack::m_classType)
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v9) == clipType) )
        {
          CDmeTrack::FindClipsIntersectingTime(this: v9, startTime, endTime, flags, clips);
        }
        ++v7;
      }
      while ( v7 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00489170
// Name: public: void CDmeTrackGroup::FindClipsWithinTime(enum DmeClipType_t,class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsWithinTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t startTime,
        DmeTime_t endTime,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v7; // edi
  CDmElement *v8; // eax
  CDmeTrack *v9; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v7 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = (CDmeTrack *)v8;
        if ( v8 != nullptr
          && v8->IsA(this: v8, a2: CDmeTrack::m_classType)
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v9) == clipType) )
        {
          CDmeTrack::FindClipsWithinTime(this: v9, startTime, endTime, flags, clips);
        }
        ++v7;
      }
      while ( v7 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00489210
// Name: public: class CDmeClip __near * CDmeTrackGroup::GetOwnerClip(void)
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeTrackGroup::GetOwnerClip(CDmeTrackGroup *this)
{
  CUtlSymbolLarge *v2; // eax
  CDmeClip *result; // eax
  CUtlSymbolLarge *v4; // eax
  _BYTE v5[4]; // [esp+4h] [ebp-4h] BYREF

  v2 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v5, a3: "subClipTrackGroup");
  result = FindReferringElement<CDmeClip>(
             pElement: this,
             symAttrName: (CUtlSymbolLarge)v2->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  if ( result == nullptr )
  {
    v4 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v5, a3: "trackGroups");
    return FindReferringElement<CDmeClip>(
             pElement: this,
             symAttrName: (CUtlSymbolLarge)v4->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00489280
// Name: public: class CDmeTrack __near * CDmeTrackGroup::GetFilmTrack(void)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::GetFilmTrack(CDmeTrackGroup *this)
{
  CDmeClip *OwnerClip; // eax
  bool v3; // zf
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  OwnerClip = CDmeTrackGroup::GetOwnerClip(this);
  if ( OwnerClip != nullptr )
    v3 = OwnerClip->GetFilmTrackGroup(this: OwnerClip) == this;
  else
    v3 = this->m_nMaxTrackCount == 1;
  if ( v3
    && this->m_Tracks.m_Storage.m_Size > 0
    && (v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Tracks.m_Storage.m_Memory.m_pMemory),
        v5 = v4,
        v4 != nullptr)
    && v4->IsA(this: v4, a2: CDmeTrack::m_classType) )
  {
    return (CDmeTrack *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004892F0
// Name: public: class CDmeTrack __near * CDmeTrackGroup::FindTrackForClip(class CDmeClip __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::FindTrackForClip(CDmeTrackGroup *this, CDmeClip *pClip)
{
  CDmElement *v3; // eax
  CDmElement *v4; // esi
  int nTrackIndex; // [esp+4h] [ebp-4h] BYREF

  nTrackIndex = -1;
  if ( CDmeTrackGroup::FindTrackForClip(this, pClip, pTrackIndex: &nTrackIndex, pClipIndex: nullptr) != 0
    && (v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[nTrackIndex]),
        v4 = v3,
        v3 != nullptr)
    && v3->IsA(this: v3, a2: CDmeTrack::m_classType) )
  {
    return (CDmeTrack *)v4;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004893C0
// Name: protected: CDmeTrackGroup::CDmeTrackGroup(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrackGroup *__thiscall CDmeTrackGroup::CDmeTrackGroup(
        CDmeTrackGroup *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTrackGroup_vtbl *)&CDmeTrackGroup::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Tracks);
  this->m_bIsVisible.m_pAttribute = nullptr;
  this->m_bIsVisible.m_Storage = false;
  this->m_bMinimized.m_pAttribute = nullptr;
  this->m_bMinimized.m_Storage = false;
  this->m_bMute.m_pAttribute = nullptr;
  this->m_bMute.m_Storage = false;
  this->m_Volume = 0;
  this->m_flDisplayScale = 0;
  this->m_bForceMultiTrack.m_pAttribute = nullptr;
  this->m_bForceMultiTrack.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00489430
// Name: public: virtual bool CDmeTrackGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTrackGroup::IsA(CDmeTrackGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTrackGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00489460
// Name: public: virtual int CDmeTrackGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrackGroup::GetInheritanceDepth(CDmeTrackGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTrackGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004894A0
// Name: protected: virtual int CDmeTrackGroup::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrackGroup::AllocatedSize(CDmeTrackGroup *this)
{
  return 148;
}

//------------------------------------------------------------------------------
// Address: 0x004894B0
// Name: protected: virtual void CDmeTrackGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::PerformConstruction(CDmeTrackGroup *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeTrackGroup::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057A430
// Name: _dynamic_initializer_for__CDmeTrackGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTrackGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTrackGroup::s_Allocator,
    blockSize: 148,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTrackGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DD30
// Name: _dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTrackGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00488E10
// Name: class CDmeClip __near * FindReferringElement<class CDmeClip>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeClip *__cdecl FindReferringElement<CDmeClip>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeClip *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v5);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeClip>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0057A460
// Name: _dynamic_initializer_for__g_CDmeTrackGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTrackGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A470
// Name: _dynamic_initializer_for__g_CDmeTrackGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTrackGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTrackGroup_Helper,
           classname: "DmeTrackGroup",
           pFactory: &g_CDmeTrackGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057DD40
// Name: _dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTrackGroup_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0058B8B0
// Name: public: void CDmeTrackGroup::SetMaxTrackCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::SetMaxTrackCount(CDmeTrackGroup *this, int nCount)
{
  this->m_nMaxTrackCount = nCount;
}

//------------------------------------------------------------------------------
// Address: 0x0058B970
// Name: protected: void CDmeTrackGroup::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::OnConstruction(CDmeTrackGroup *this)
{
  CDmaElementArray<CDmeTrack> *p_m_Tracks; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  float v8; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  p_m_Tracks = &this->m_Tracks;
  this->m_Tracks.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "tracks",
                                  type: AT_FIRST_ARRAY_TYPE,
                                  pMemory: &this->m_Tracks);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Tracks->m_pAttribute, typeSymbol: CDmeTrack::m_classType);
  p_m_Tracks->m_pAttribute->m_nFlags |= 0x900u;
  value = true;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_bIsVisible);
  this->m_bIsVisible.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
  this->m_bMute.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "mute",
                                 type: AT_BOOL,
                                 pMemory: &this->m_bMute);
  v8 = 1.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "displayScale",
         type: AT_FLOAT,
         pMemory: &this->m_flDisplayScale);
  this->m_flDisplayScale.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, value: &v8);
  value = true;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "minimized", type: AT_BOOL, pMemory: &this->m_bMinimized);
  this->m_bMinimized.m_pAttribute = v5;
  CDmAttribute::SetValue<bool>(this: v5, &value);
  this->m_nMaxTrackCount = 0x7FFFFFFF;
  v8 = 1.0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "volume", type: AT_FLOAT, pMemory: &this->m_Volume);
  this->m_Volume.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: &v8);
  value = false;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "forcemultitrack",
         type: AT_BOOL,
         pMemory: &this->m_bForceMultiTrack);
  this->m_bForceMultiTrack.m_pAttribute = v7;
  CDmAttribute::SetValue<bool>(this: v7, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0058BB30
// Name: public: class CDmeTrack __near * CDmeTrackGroup::AddTrack(char const __near *,enum DmeClipType_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::AddTrack(CDmeTrackGroup *this, int pTrackName, DmeClipType_t trackType)
{
  DmElementHandle_t v4; // eax
  CDmElement *v5; // eax
  CDmeTrack *v6; // esi

  v4 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeTrack::m_classType.u.m_Id,
         a3: (const char *)pTrackName,
         a4: this->m_fileId,
         a5: nullptr);
  v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
  v6 = (CDmeTrack *)v5;
  if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeTrack::m_classType) )
    v6 = nullptr;
  CDmeTrack::SetClipType(this: v6, type: trackType);
  CDmeTrack::SetCollapsed(this: v6, state: false);
  if ( v6 != nullptr )
  {
    pTrackName = CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)v6);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Tracks,
      src: (DmElementHandle_t *)&pTrackName);
    return v6;
  }
  else
  {
    pTrackName = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Tracks,
      src: (DmElementHandle_t *)&pTrackName);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058BBE0
// Name: public: class CDmeTrack __near * CDmeTrackGroup::CreateFilmTrack(void)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::CreateFilmTrack(CDmeTrackGroup *this)
{
  return CDmeTrackGroup::AddTrack(this, pTrackName: (int)"Film", trackType: DMECLIP_FILM);
}

//------------------------------------------------------------------------------
// Address: 0x0058BBF0
// Name: public: bool CDmeTrackGroup::FindTrackForClip(class CDmeClip __near *,int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeTrackGroup::FindTrackForClip(
        CDmeTrackGroup *this,
        CDmeClip *pClip,
        int *pTrackIndex,
        int *pClipIndex)
{
  CDmeTrackGroup *v4; // ebx
  int v5; // edi
  CDmElement *v6; // eax
  CVTFTexture *v7; // esi
  int ClipCount; // ebx
  int v9; // edi
  int c; // [esp+Ch] [ebp-10h]
  DmeClipType_t type; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  v4 = this;
  type = pClip->GetClipType(this: pClip);
  v5 = 0;
  c = v4->m_Tracks.m_Storage.m_Size;
  i = 0;
  if ( c <= 0 )
    return 0;
  while ( 1 )
  {
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4->m_Tracks.m_Storage.m_Memory.m_pMemory[v5]);
    v7 = (CVTFTexture *)v6;
    if ( v6 != nullptr
      && v6->IsA(this: v6, a2: CDmeTrack::m_classType)
      && CDmeTrack::GetClipType(this: (CDmeTrack *)v7) == type )
    {
      ClipCount = CDmeTrack::GetClipCount(this: v7);
      v9 = 0;
      if ( ClipCount > 0 )
        break;
LABEL_8:
      v4 = this;
      v5 = i;
    }
    i = ++v5;
    if ( v5 >= c )
      return 0;
  }
  while ( CDmeTrack::GetClip(this: (CDmeTrack *)v7, i: v9) != pClip )
  {
    if ( ++v9 >= ClipCount )
      goto LABEL_8;
  }
  if ( pTrackIndex != nullptr )
    *pTrackIndex = i;
  if ( pClipIndex != nullptr )
    *pClipIndex = v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0058BCC0
// Name: public: void CDmeTrackGroup::FindClipsAtTime(enum DmeClipType_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsAtTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t time,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v6; // edi
  CDmElement *v7; // eax
  CDmeTrack *v8; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v6 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v6]);
        v8 = (CDmeTrack *)v7;
        if ( v7 != nullptr
          && v7->IsA(this: v7, a2: CDmeTrack::m_classType)
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v8) == clipType) )
        {
          CDmeTrack::FindClipsAtTime(this: v8, time, flags, clips);
        }
        ++v6;
      }
      while ( v6 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058BD60
// Name: public: void CDmeTrackGroup::FindClipsIntersectingTime(enum DmeClipType_t,class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsIntersectingTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t startTime,
        DmeTime_t endTime,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v7; // edi
  CDmElement *v8; // eax
  CDmeTrack *v9; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v7 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = (CDmeTrack *)v8;
        if ( v8 != nullptr
          && v8->IsA(this: v8, a2: CDmeTrack::m_classType)
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v9) == clipType) )
        {
          CDmeTrack::FindClipsIntersectingTime(this: v9, startTime, endTime, flags, clips);
        }
        ++v7;
      }
      while ( v7 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058BE00
// Name: public: void CDmeTrackGroup::FindClipsWithinTime(enum DmeClipType_t,class DmeTime_t,class DmeTime_t,enum DmeClipSkipFlag_t,class CUtlVector<class CDmeClip __near *,class CUtlMemory<class CDmeClip __near *,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::FindClipsWithinTime(
        CDmeTrackGroup *this,
        DmeClipType_t clipType,
        DmeTime_t startTime,
        DmeTime_t endTime,
        DmeClipSkipFlag_t flags,
        CUtlVector<CDmeClip *,CUtlMemory<CDmeClip *,int> > *clips)
{
  int v7; // edi
  CDmElement *v8; // eax
  CDmeTrack *v9; // esi
  int c; // [esp+Ch] [ebp-4h]

  if ( ((flags & 2) == 0 || this->m_bIsVisible.m_Storage && !this->m_bMinimized.m_Storage)
    && ((flags & 1) == 0 || !this->m_bMute.m_Storage) )
  {
    v7 = 0;
    c = this->m_Tracks.m_Storage.m_Size;
    if ( c > 0 )
    {
      do
      {
        v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[v7]);
        v9 = (CDmeTrack *)v8;
        if ( v8 != nullptr
          && v8->IsA(this: v8, a2: CDmeTrack::m_classType)
          && (clipType == DMECLIP_UNKNOWN || CDmeTrack::GetClipType(this: v9) == clipType) )
        {
          CDmeTrack::FindClipsWithinTime(this: v9, startTime, endTime, flags, clips);
        }
        ++v7;
      }
      while ( v7 < c );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058BEA0
// Name: public: class CDmeClip __near * CDmeTrackGroup::GetOwnerClip(void)
// Source: json
//------------------------------------------------------------------------------
CDmeClip *__thiscall CDmeTrackGroup::GetOwnerClip(CDmeTrackGroup *this)
{
  CUtlSymbolLarge *v2; // eax
  CDmeClip *result; // eax
  CUtlSymbolLarge *v4; // eax
  _BYTE v5[4]; // [esp+4h] [ebp-4h] BYREF

  v2 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v5, a3: "subClipTrackGroup");
  result = FindReferringElement<CDmeClip>(
             pElement: this,
             symAttrName: (CUtlSymbolLarge)v2->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  if ( result == nullptr )
  {
    v4 = g_pDataModel->GetSymbol(this: g_pDataModel, result: v5, a3: "trackGroups");
    return FindReferringElement<CDmeClip>(
             pElement: this,
             symAttrName: (CUtlSymbolLarge)v4->u.m_Id,
             bMustBeInSameFile: true,
             depth: TD_ALL);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0058BF10
// Name: public: class CDmeTrack __near * CDmeTrackGroup::GetFilmTrack(void)
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::GetFilmTrack(CDmeTrackGroup *this)
{
  CDmeClip *OwnerClip; // eax
  bool v3; // zf
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  OwnerClip = CDmeTrackGroup::GetOwnerClip(this);
  if ( OwnerClip != nullptr )
    v3 = OwnerClip->GetFilmTrackGroup(this: OwnerClip) == this;
  else
    v3 = this->m_nMaxTrackCount == 1;
  if ( v3
    && this->m_Tracks.m_Storage.m_Size > 0
    && (v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Tracks.m_Storage.m_Memory.m_pMemory),
        v5 = v4,
        v4 != nullptr)
    && v4->IsA(this: v4, a2: CDmeTrack::m_classType) )
  {
    return (CDmeTrack *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058BF80
// Name: public: class CDmeTrack __near * CDmeTrackGroup::FindTrackForClip(class CDmeClip __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeTrack *__thiscall CDmeTrackGroup::FindTrackForClip(CDmeTrackGroup *this, CDmeClip *pClip)
{
  CDmElement *v3; // eax
  CDmElement *v4; // esi
  int nTrackIndex; // [esp+4h] [ebp-4h] BYREF

  nTrackIndex = -1;
  if ( CDmeTrackGroup::FindTrackForClip(this, pClip, pTrackIndex: &nTrackIndex, pClipIndex: nullptr) != 0
    && (v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Tracks.m_Storage.m_Memory.m_pMemory[nTrackIndex]),
        v4 = v3,
        v3 != nullptr)
    && v3->IsA(this: v3, a2: CDmeTrack::m_classType) )
  {
    return (CDmeTrack *)v4;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058C050
// Name: protected: CDmeTrackGroup::CDmeTrackGroup(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTrackGroup *__thiscall CDmeTrackGroup::CDmeTrackGroup(
        CDmeTrackGroup *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTrackGroup_vtbl *)&CDmeTrackGroup::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Tracks);
  this->m_bIsVisible.m_pAttribute = nullptr;
  this->m_bIsVisible.m_Storage = false;
  this->m_bMinimized.m_pAttribute = nullptr;
  this->m_bMinimized.m_Storage = false;
  this->m_bMute.m_pAttribute = nullptr;
  this->m_bMute.m_Storage = false;
  this->m_Volume = 0;
  this->m_flDisplayScale = 0;
  this->m_bForceMultiTrack.m_pAttribute = nullptr;
  this->m_bForceMultiTrack.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0058C0C0
// Name: public: virtual bool CDmeTrackGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTrackGroup::IsA(CDmeTrackGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTrackGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0058C0F0
// Name: public: virtual int CDmeTrackGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrackGroup::GetInheritanceDepth(CDmeTrackGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTrackGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0058C130
// Name: protected: virtual int CDmeTrackGroup::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTrackGroup::AllocatedSize(CDmeTrackGroup *this)
{
  return 148;
}

//------------------------------------------------------------------------------
// Address: 0x0058C140
// Name: protected: virtual void CDmeTrackGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTrackGroup::PerformConstruction(CDmeTrackGroup *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeTrackGroup::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B8340
// Name: _dynamic_initializer_for__CDmeTrackGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTrackGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTrackGroup::s_Allocator,
    blockSize: 0x94u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTrackGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BCB30
// Name: _dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTrackGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTrackGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0058BAA0
// Name: class CDmeClip __near * FindReferringElement<class CDmeClip>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeClip *__cdecl FindReferringElement<CDmeClip>(
        CVTFTexture *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  IDataModel_vtbl *v4; // esi
  int CenterVertIndex; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t y_low; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmeClip *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = g_pDataModel->__vftable;
    CenterVertIndex = CCoreDispNode::GetCenterVertIndex(this: pElement);
    v6 = v4->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)CenterVertIndex);
    y_low = LODWORD(pElement->m_vecReflectivity.y);
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    y_low = DMFILEID_INVALID;
  }
  it.m_fileid = y_low;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmeClip>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( result != nullptr )
      break;
    v8 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006B8370
// Name: _dynamic_initializer_for__g_CDmeTrackGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTrackGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B8380
// Name: _dynamic_initializer_for__g_CDmeTrackGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTrackGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTrackGroup_Helper,
           classname: "DmeTrackGroup",
           pFactory: &g_CDmeTrackGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BCB40
// Name: _dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTrackGroup_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeTrackGroup_Factory.m_CallBackList);
}

} // namespace vmap
