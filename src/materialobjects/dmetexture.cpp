// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialobjects/dmetexture.cpp
// Functions: 21
// ============================================================

#include "materialobjects\dmetexture.h"

//------------------------------------------------------------------------------
// Address: 0x004BAEE0
// Name: public: void CDmeTexture::RemoveAllFrames(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTexture::RemoveAllFrames(CDmeTexture *this)
{
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &this->m_Frames);
}

//------------------------------------------------------------------------------
// Address: 0x004BAEF0
// Name: protected: void CDmeTexture::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTexture::OnConstruction(CDmeTexture *this)
{
  this->m_bClampS.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "clampS",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bClampS);
  this->m_bClampT.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "clampT",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bClampT);
  this->m_bClampU.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "clampU",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bClampU);
  this->m_bNoDebugOverride.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "noDebugOverride",
                                            type: AT_BOOL,
                                            pMemory: &this->m_bNoDebugOverride);
  this->m_bNoLod.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "noMipmapLOD",
                                  type: AT_BOOL,
                                  pMemory: &this->m_bNoLod);
  this->m_bNiceFiltered.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "niceFiltered",
                                         type: AT_BOOL,
                                         pMemory: &this->m_bNiceFiltered);
  this->m_bNormalMap.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "normalMap",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bNormalMap);
  this->m_flBumpScale.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "bumpScale",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flBumpScale);
  this->m_nCompressType.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "compressType",
                                         type: AT_INT,
                                         pMemory: &this->m_nCompressType);
  this->m_nFilterType.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "filterType",
                                       type: AT_INT,
                                       pMemory: &this->m_nFilterType);
  this->m_nMipmapType.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "mipmapType",
                                       type: AT_INT,
                                       pMemory: &this->m_nMipmapType);
  this->m_nTextureType.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "textureType",
                                        type: AT_INT,
                                        pMemory: &this->m_nTextureType);
  this->m_Frames.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "frames",
                                  type: AT_FIRST_ARRAY_TYPE,
                                  pMemory: &this->m_Frames);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Frames.m_pAttribute, typeSymbol: CDmeTextureFrame::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004BB030
// Name: public: class CDmeImageArray __near * CDmeTextureFrame::GetMipLevel(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeImageArray *__thiscall CDmeTextureFrame::GetMipLevel(CDmeTextureFrame *this, int nIndex)
{
  int v2; // eax
  int v3; // esi

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_MipLevels.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeImageArray::m_classType.u) != 0 )
  {
    return (CDmeImageArray *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BB080
// Name: public: class CDmeImageArray __near * CDmeTextureFrame::AddMipLevel(void)
// Source: json
//------------------------------------------------------------------------------
CExpressionCalculator *__thiscall CDmeTextureFrame::AddMipLevel(CDmeTextureFrame *this)
{
  int v2; // eax
  int v3; // eax
  CExpressionCalculator *v4; // esi
  DmElementHandle_t src; // [esp+8h] [ebp-4h] BYREF

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeImageArray::m_classType.u,
         a3: "mip",
         a4: this->m_fileId,
         a5: 0);
  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v2);
  v4 = (CExpressionCalculator *)v3;
  if ( v3 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
         a1: v3,
         a2: CDmeImageArray::m_classType.u) != 0 )
  {
    src = CCodecBuffer_Block::GetBufferType(this: v4);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_MipLevels,
      &src);
    return v4;
  }
  else
  {
    src = DMELEMENT_HANDLE_INVALID;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_MipLevels,
      &src);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BB120
// Name: public: int CDmeTextureFrame::ImageCount(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeTextureFrame::ImageCount(CDmeTextureFrame *this)
{
  CDmAttribute *result; // eax
  int v3; // edi
  int v4; // eax
  CDmeTransform *v5; // esi
  int nMipCount; // [esp+Ch] [ebp-8h]
  CDmAttribute *nImageCount; // [esp+10h] [ebp-4h]

  result = nullptr;
  v3 = 0;
  nImageCount = nullptr;
  nMipCount = this->m_MipLevels.m_Storage.m_Size;
  if ( nMipCount > 0 )
  {
    do
    {
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_MipLevels.m_Storage.m_Memory.m_pMemory[v3]);
      v5 = (CDmeTransform *)v4;
      if ( v4 == 0
        || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
             a1: v4,
             a2: CDmeImageArray::m_classType.u) == 0 )
      {
        v5 = nullptr;
      }
      if ( (int)nImageCount <= (int)CDmeTrack::GetClipCount(this: v5) )
        nImageCount = CDmeTrack::GetClipCount(this: v5);
      ++v3;
    }
    while ( v3 < nMipCount );
    return nImageCount;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BB1A0
// Name: public: int CDmeTexture::Width(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTexture::Width(CDmeTexture *this)
{
  int v1; // eax
  int v2; // esi
  int v3; // eax
  CDmeImageArray *v4; // esi

  if ( this->m_Frames.m_Storage.m_Size == 0 )
    return 0;
  v1 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: *this->m_Frames.m_Storage.m_Memory.m_pMemory);
  v2 = v1;
  if ( v1 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v1 + 16))(
         a1: v1,
         a2: CDmeTextureFrame::m_classType.u) == 0 )
  {
    v2 = 0;
  }
  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: **(_DWORD **)(v2 + 68));
  v4 = (CDmeImageArray *)v3;
  if ( v3 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
         a1: v3,
         a2: CDmeImageArray::m_classType.u) != 0 )
  {
    return CDmeImageArray::Width(this: v4);
  }
  else
  {
    return CDmeImageArray::Width(this: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BB230
// Name: public: int CDmeTexture::Height(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTexture::Height(CDmeTexture *this)
{
  int v1; // eax
  int v2; // esi
  int v3; // eax
  CDmeImageArray *v4; // esi

  if ( this->m_Frames.m_Storage.m_Size == 0 )
    return 0;
  v1 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: *this->m_Frames.m_Storage.m_Memory.m_pMemory);
  v2 = v1;
  if ( v1 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v1 + 16))(
         a1: v1,
         a2: CDmeTextureFrame::m_classType.u) == 0 )
  {
    v2 = 0;
  }
  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: **(_DWORD **)(v2 + 68));
  v4 = (CDmeImageArray *)v3;
  if ( v3 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
         a1: v3,
         a2: CDmeImageArray::m_classType.u) != 0 )
  {
    return CDmeImageArray::Height(this: v4);
  }
  else
  {
    return CDmeImageArray::Height(this: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BB2C0
// Name: public: int CDmeTexture::Depth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTexture::Depth(CDmeTexture *this)
{
  int v1; // eax
  int v2; // esi
  int v3; // eax
  CDmeImageArray *v4; // esi

  if ( this->m_Frames.m_Storage.m_Size == 0 )
    return 0;
  v1 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: *this->m_Frames.m_Storage.m_Memory.m_pMemory);
  v2 = v1;
  if ( v1 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v1 + 16))(
         a1: v1,
         a2: CDmeTextureFrame::m_classType.u) == 0 )
  {
    v2 = 0;
  }
  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: **(_DWORD **)(v2 + 68));
  v4 = (CDmeImageArray *)v3;
  if ( v3 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
         a1: v3,
         a2: CDmeImageArray::m_classType.u) != 0 )
  {
    return CDmeImageArray::Depth(this: v4);
  }
  else
  {
    return CDmeImageArray::Depth(this: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BB350
// Name: public: class CDmeTextureFrame __near * CDmeTexture::AddFrame(void)
// Source: json
//------------------------------------------------------------------------------
CExpressionCalculator *__thiscall CDmeTexture::AddFrame(CDmeTexture *this)
{
  int v2; // eax
  int v3; // eax
  CExpressionCalculator *v4; // esi
  DmElementHandle_t src; // [esp+8h] [ebp-4h] BYREF

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeTextureFrame::m_classType.u,
         a3: "frame",
         a4: this->m_fileId,
         a5: 0);
  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v2);
  v4 = (CExpressionCalculator *)v3;
  if ( v3 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
         a1: v3,
         a2: CDmeTextureFrame::m_classType.u) != 0 )
  {
    src = CCodecBuffer_Block::GetBufferType(this: v4);
  }
  else
  {
    v4 = nullptr;
    src = DMELEMENT_HANDLE_INVALID;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &this->m_Frames,
    &src);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004BB3E0
// Name: public: void CDmeTexture::GetImages(int,int,class CDmeImage __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTexture::GetImages(CDmeTexture *this, int nFrame, int nImageIndex, CDmeImage **ppImages, int nSize)
{
  int v7; // eax
  int v8; // ebx
  int i; // edi
  int v10; // eax
  CDmeImageArray *v11; // esi
  int nMipCount; // [esp+20h] [ebp+14h]

  memset(dst: (unsigned __int8 *)ppImages, value: 0, count: 4 * nSize);
  if ( nFrame < this->m_Frames.m_Storage.m_Size )
  {
    v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_Frames.m_Storage.m_Memory.m_pMemory[nFrame]);
    v8 = v7;
    if ( v7 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
           a1: v7,
           a2: CDmeTextureFrame::m_classType.u) != 0 )
    {
      nMipCount = *(_DWORD *)(v8 + 80);
      if ( nMipCount >= nSize )
        nMipCount = nSize;
      for ( i = 0; i < nMipCount; ++i )
      {
        v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                a1: g_pDataModel.u,
                a2: *(_DWORD *)(*(_DWORD *)(v8 + 68) + 4 * i));
        v11 = (CDmeImageArray *)v10;
        if ( v10 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
               a1: v10,
               a2: CDmeImageArray::m_classType.u) != 0
          && nImageIndex < (int)CDmeTrack::GetClipCount(this: (CDmeTransform *)v11) )
        {
          ppImages[i] = CDmeImageArray::GetImage(this: v11, nIndex: nImageIndex);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BB580
// Name: public: virtual bool CDmeTextureFrame::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTextureFrame::IsA(CDmeTextureFrame *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTextureFrame::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BB5B0
// Name: public: virtual int CDmeTextureFrame::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTextureFrame::GetInheritanceDepth(CDmeTextureFrame *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTextureFrame::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BB5F0
// Name: protected: virtual void CDmeTextureFrame::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTextureFrame::PerformConstruction(CDmeTextureFrame *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_MipLevels.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "mipLevels",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_MipLevels);
  CDmAttribute::SetElementTypeSymbol(this: this->m_MipLevels.m_pAttribute, typeSymbol: CDmeImageArray::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004BB670
// Name: protected: CDmeTexture::CDmeTexture(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTexture *__thiscall CDmeTexture::CDmeTexture(
        CDmeTexture *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTexture_vtbl *)&CDmeTexture::`vftable';
  this->m_bClampS.m_pAttribute = nullptr;
  this->m_bClampS.m_Storage = false;
  this->m_bClampT.m_pAttribute = nullptr;
  this->m_bClampT.m_Storage = false;
  this->m_bClampU.m_pAttribute = nullptr;
  this->m_bClampU.m_Storage = false;
  this->m_bNoDebugOverride.m_pAttribute = nullptr;
  this->m_bNoDebugOverride.m_Storage = false;
  this->m_bNoLod.m_pAttribute = nullptr;
  this->m_bNoLod.m_Storage = false;
  this->m_bNiceFiltered.m_pAttribute = nullptr;
  this->m_bNiceFiltered.m_Storage = false;
  this->m_bNormalMap.m_pAttribute = nullptr;
  this->m_bNormalMap.m_Storage = false;
  this->m_flBumpScale = 0;
  this->m_nCompressType.m_pAttribute = nullptr;
  this->m_nCompressType.m_Storage = 0;
  this->m_nFilterType.m_pAttribute = nullptr;
  this->m_nFilterType.m_Storage = 0;
  this->m_nMipmapType.m_pAttribute = nullptr;
  this->m_nMipmapType.m_Storage = 0;
  this->m_nTextureType.m_pAttribute = nullptr;
  this->m_nTextureType.m_Storage = 0;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Frames);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004BB720
// Name: public: virtual bool CDmeTexture::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTexture::IsA(CDmeTexture *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTexture::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BB750
// Name: public: virtual int CDmeTexture::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTexture::GetInheritanceDepth(CDmeTexture *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTexture::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BB790
// Name: protected: virtual void CDmeTexture::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTexture::PerformConstruction(CDmeTexture *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeTexture::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006AC190
// Name: _dynamic_initializer_for__CDmeTextureFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTextureFrame::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTextureFrame::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTextureFrame pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTextureFrame::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B3980
// Name: _dynamic_atexit_destructor_for__CDmeTextureFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTextureFrame::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTextureFrame::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AC1C0
// Name: _dynamic_initializer_for__g_CDmeTextureFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTextureFrame_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTextureFrame_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC1D0
// Name: _dynamic_initializer_for__g_CDmeTextureFrame_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTextureFrame_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTextureFrame_Helper,
           classname: "DmeTextureFrame",
           pFactory: &g_CDmeTextureFrame_Factory,
           bIsStandardFactory: false);
}

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x0042D9C0
// Name: public: void CDmeTexture::RemoveAllFrames(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTexture::RemoveAllFrames(CDmeTexture *this)
{
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &this->m_Frames);
}

//------------------------------------------------------------------------------
// Address: 0x0042D9D0
// Name: protected: void CDmeTexture::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTexture::OnConstruction(CDmeTexture *this)
{
  this->m_bClampS.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "clampS",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bClampS);
  this->m_bClampT.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "clampT",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bClampT);
  this->m_bClampU.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "clampU",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bClampU);
  this->m_bNoDebugOverride.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "noDebugOverride",
                                            type: AT_BOOL,
                                            pMemory: &this->m_bNoDebugOverride);
  this->m_bNoLod.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "noMipmapLOD",
                                  type: AT_BOOL,
                                  pMemory: &this->m_bNoLod);
  this->m_bNiceFiltered.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "niceFiltered",
                                         type: AT_BOOL,
                                         pMemory: &this->m_bNiceFiltered);
  this->m_bNormalMap.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "normalMap",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bNormalMap);
  this->m_flBumpScale.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "bumpScale",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flBumpScale);
  this->m_nCompressType.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "compressType",
                                         type: AT_INT,
                                         pMemory: &this->m_nCompressType);
  this->m_nFilterType.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "filterType",
                                       type: AT_INT,
                                       pMemory: &this->m_nFilterType);
  this->m_nMipmapType.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "mipmapType",
                                       type: AT_INT,
                                       pMemory: &this->m_nMipmapType);
  this->m_nTextureType.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "textureType",
                                        type: AT_INT,
                                        pMemory: &this->m_nTextureType);
  this->m_Frames.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "frames",
                                  type: AT_FIRST_ARRAY_TYPE,
                                  pMemory: &this->m_Frames);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Frames.m_pAttribute, typeSymbol: CDmeTextureFrame::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0042DBD0
// Name: public: class CDmeTextureFrame __near * CDmeTexture::GetFrame(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeTextureFrame *__thiscall CDmeTexture::GetFrame(CDmeTexture *this, int nIndex)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Frames.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeTextureFrame::m_classType) )
    return (CDmeTextureFrame *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0042DC20
// Name: public: class CDmeImageArray __near * CDmeTextureFrame::GetMipLevel(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeImageArray *__thiscall CDmeTextureFrame::GetMipLevel(CDmeTextureFrame *this, int nIndex)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_MipLevels.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeImageArray::m_classType) )
    return (CDmeImageArray *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0042DC70
// Name: public: class CDmeImageArray __near * CDmeTextureFrame::AddMipLevel(void)
// Source: json
//------------------------------------------------------------------------------
CVTFTexture *__thiscall CDmeTextureFrame::AddMipLevel(CDmeTextureFrame *this)
{
  CVTFTexture *v2; // eax
  CVTFTexture *v3; // esi
  DmElementHandle_t src; // [esp+8h] [ebp-4h] BYREF

  v2 = (CVTFTexture *)CreateElement<CDmeImageArray>(pObjectName: "mip", fileid: this->m_fileId, pObjectID: nullptr);
  v3 = v2;
  if ( v2 != nullptr )
  {
    src = CVTFTexture::MipCount(this: v2);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_MipLevels,
      &src);
    return v3;
  }
  else
  {
    src = DMELEMENT_HANDLE_INVALID;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_MipLevels,
      &src);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042DCD0
// Name: public: int CDmeTextureFrame::ImageCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTextureFrame::ImageCount(CDmeTextureFrame *this)
{
  int v2; // ebp
  int v3; // edi
  CDmElement *v4; // eax
  CVTFTexture *v5; // esi
  int m_Size; // [esp+10h] [ebp-4h]

  v2 = 0;
  v3 = 0;
  m_Size = this->m_MipLevels.m_Storage.m_Size;
  if ( m_Size > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_MipLevels.m_Storage.m_Memory.m_pMemory[v3]);
      v5 = (CVTFTexture *)v4;
      if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeImageArray::m_classType) )
        v5 = nullptr;
      if ( v2 <= CVTFTexture::LowResWidth(this: v5) )
        v2 = CVTFTexture::LowResWidth(this: v5);
      ++v3;
    }
    while ( v3 < m_Size );
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0042DD50
// Name: public: int CDmeTexture::Width(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement_vtbl *__thiscall CDmeTexture::Width(CDmeTexture *this)
{
  CDmElement *v1; // eax
  CDmElement *v2; // esi
  CDmElement *v3; // eax
  CDmeImageArray *v4; // esi

  if ( this->m_Frames.m_Storage.m_Size == 0 )
    return nullptr;
  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Frames.m_Storage.m_Memory.m_pMemory);
  v2 = v1;
  if ( v1 == nullptr || !v1->IsA(this: v1, a2: CDmeTextureFrame::m_classType) )
    v2 = nullptr;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2[1].OnAttributeChanged);
  v4 = (CDmeImageArray *)v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeImageArray::m_classType) )
    return CDmeImageArray::Width(this: v4);
  else
    return CDmeImageArray::Width(this: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0042DDE0
// Name: public: int CDmeTexture::Height(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTexture::Height(CDmeTexture *this)
{
  CDmElement *v1; // eax
  CDmElement *v2; // esi
  CDmElement *v3; // eax
  CDmeImageArray *v4; // esi

  if ( this->m_Frames.m_Storage.m_Size == 0 )
    return 0;
  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Frames.m_Storage.m_Memory.m_pMemory);
  v2 = v1;
  if ( v1 == nullptr || !v1->IsA(this: v1, a2: CDmeTextureFrame::m_classType) )
    v2 = nullptr;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2[1].OnAttributeChanged);
  v4 = (CDmeImageArray *)v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeImageArray::m_classType) )
    return CDmeImageArray::Height(this: v4);
  else
    return CDmeImageArray::Height(this: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0042DE70
// Name: public: int CDmeTexture::Depth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTexture::Depth(CDmeTexture *this)
{
  CDmElement *v1; // eax
  CDmElement *v2; // esi
  CDmElement *v3; // eax
  CDmeImageArray *v4; // esi

  if ( this->m_Frames.m_Storage.m_Size == 0 )
    return 0;
  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Frames.m_Storage.m_Memory.m_pMemory);
  v2 = v1;
  if ( v1 == nullptr || !v1->IsA(this: v1, a2: CDmeTextureFrame::m_classType) )
    v2 = nullptr;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2[1].OnAttributeChanged);
  v4 = (CDmeImageArray *)v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeImageArray::m_classType) )
    return CDmeImageArray::Depth(this: v4);
  else
    return CDmeImageArray::Depth(this: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0042DF00
// Name: public: class CDmeTextureFrame __near * CDmeTexture::AddFrame(void)
// Source: json
//------------------------------------------------------------------------------
CVTFTexture *__thiscall CDmeTexture::AddFrame(CDmeTexture *this)
{
  CVTFTexture *v2; // eax
  CVTFTexture *v3; // esi
  DmElementHandle_t src; // [esp+8h] [ebp-4h] BYREF

  v2 = (CVTFTexture *)CreateElement<CDmeTextureFrame>(pObjectName: "frame", fileid: this->m_fileId, pObjectID: nullptr);
  v3 = v2;
  if ( v2 != nullptr )
    src = CVTFTexture::MipCount(this: v2);
  else
    src = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &this->m_Frames,
    &src);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0042DF50
// Name: public: void CDmeTexture::GetImages(int,int,class CDmeImage __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTexture::GetImages(CDmeTexture *this, int nFrame, int nImageIndex, CDmeImage **ppImages, int nSize)
{
  CDmeTextureFrame *Frame; // eax
  CDmeTextureFrame *v8; // ebx
  int i; // edi
  CDmElement *v10; // eax
  CDmeImageArray *v11; // esi
  int nMipCount; // [esp+20h] [ebp+10h]

  memset(dst: (int)ppImages, value: nullptr, count: 4 * nSize);
  if ( nFrame < this->m_Frames.m_Storage.m_Size )
  {
    Frame = CDmeTexture::GetFrame(this, nIndex: nFrame);
    v8 = Frame;
    if ( Frame != nullptr )
    {
      nMipCount = Frame->m_MipLevels.m_Storage.m_Size;
      if ( nMipCount >= nSize )
        nMipCount = nSize;
      for ( i = 0; i < nMipCount; ++i )
      {
        v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: v8->m_MipLevels.m_Storage.m_Memory.m_pMemory[i]);
        v11 = (CDmeImageArray *)v10;
        if ( v10 != nullptr
          && v10->IsA(this: v10, a2: CDmeImageArray::m_classType)
          && nImageIndex < CVTFTexture::LowResWidth(this: (CVTFTexture *)v11) )
        {
          ppImages[i] = CDmeImageArray::GetImage(this: v11, nIndex: nImageIndex);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042E090
// Name: public: virtual bool CDmeTextureFrame::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTextureFrame::IsA(CDmeTextureFrame *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTextureFrame::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042E0C0
// Name: public: virtual int CDmeTextureFrame::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTextureFrame::GetInheritanceDepth(CDmeTextureFrame *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTextureFrame::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042E100
// Name: protected: virtual void CDmeTextureFrame::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTextureFrame::PerformConstruction(CDmeTextureFrame *this)
{
  CSteamApplication::PostShutdown((CFontManager *)this);
  this->m_MipLevels.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "mipLevels",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_MipLevels);
  CDmAttribute::SetElementTypeSymbol(this: this->m_MipLevels.m_pAttribute, typeSymbol: CDmeImageArray::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0042E170
// Name: protected: CDmeTexture::CDmeTexture(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTexture *__thiscall CDmeTexture::CDmeTexture(
        CDmeTexture *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTexture_vtbl *)&CDmeTexture::`vftable';
  this->m_bClampS.m_pAttribute = nullptr;
  this->m_bClampS.m_Storage = false;
  this->m_bClampT.m_pAttribute = nullptr;
  this->m_bClampT.m_Storage = false;
  this->m_bClampU.m_pAttribute = nullptr;
  this->m_bClampU.m_Storage = false;
  this->m_bNoDebugOverride.m_pAttribute = nullptr;
  this->m_bNoDebugOverride.m_Storage = false;
  this->m_bNoLod.m_pAttribute = nullptr;
  this->m_bNoLod.m_Storage = false;
  this->m_bNiceFiltered.m_pAttribute = nullptr;
  this->m_bNiceFiltered.m_Storage = false;
  this->m_bNormalMap.m_pAttribute = nullptr;
  this->m_bNormalMap.m_Storage = false;
  this->m_flBumpScale = 0;
  this->m_nCompressType.m_pAttribute = nullptr;
  this->m_nCompressType.m_Storage = 0;
  this->m_nFilterType.m_pAttribute = nullptr;
  this->m_nFilterType.m_Storage = 0;
  this->m_nMipmapType.m_pAttribute = nullptr;
  this->m_nMipmapType.m_Storage = 0;
  this->m_nTextureType.m_pAttribute = nullptr;
  this->m_nTextureType.m_Storage = 0;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Frames);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042E220
// Name: public: virtual bool CDmeTexture::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTexture::IsA(CDmeTexture *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTexture::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042E250
// Name: public: virtual int CDmeTexture::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTexture::GetInheritanceDepth(CDmeTexture *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTexture::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042E280
// Name: protected: virtual int CDmeTexture::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTexture::AllocatedSize(CDmeTexture *this)
{
  return 204;
}

//------------------------------------------------------------------------------
// Address: 0x0042E290
// Name: protected: virtual void CDmeTexture::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTexture::PerformConstruction(CDmeTexture *this)
{
  CSteamApplication::PostShutdown((CFontManager *)this);
  CDmeTexture::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005338E0
// Name: _dynamic_initializer_for__CDmeTextureFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTextureFrame::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTextureFrame::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTextureFrame pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTextureFrame::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005351F0
// Name: _dynamic_atexit_destructor_for__CDmeTextureFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTextureFrame::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTextureFrame::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0042DB10
// Name: class CDmeImageArray __near * CreateElement<class CDmeImageArray>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeImageArray *__cdecl CreateElement<CDmeImageArray>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeImageArray::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeImageArray::m_classType) )
    return (CDmeImageArray *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0042DB70
// Name: class CDmeTextureFrame __near * CreateElement<class CDmeTextureFrame>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTextureFrame *__cdecl CreateElement<CDmeTextureFrame>(
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeTextureFrame::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeTextureFrame::m_classType) )
    return (CDmeTextureFrame *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00533910
// Name: _dynamic_initializer_for__g_CDmeTextureFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTextureFrame_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTextureFrame_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00533920
// Name: _dynamic_initializer_for__g_CDmeTextureFrame_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTextureFrame_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTextureFrame_Helper,
           classname: "DmeTextureFrame",
           pFactory: &g_CDmeTextureFrame_Factory,
           bIsStandardFactory: false);
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00567900
// Name: public: void CDmeTexture::RemoveAllFrames(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTexture::RemoveAllFrames(CDmeTexture *this)
{
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &this->m_Frames);
}

//------------------------------------------------------------------------------
// Address: 0x00567910
// Name: protected: void CDmeTexture::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTexture::OnConstruction(CDmeTexture *this)
{
  this->m_bClampS.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "clampS",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bClampS);
  this->m_bClampT.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "clampT",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bClampT);
  this->m_bClampU.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "clampU",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bClampU);
  this->m_bNoDebugOverride.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "noDebugOverride",
                                            type: AT_BOOL,
                                            pMemory: &this->m_bNoDebugOverride);
  this->m_bNoLod.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "noMipmapLOD",
                                  type: AT_BOOL,
                                  pMemory: &this->m_bNoLod);
  this->m_bNiceFiltered.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "niceFiltered",
                                         type: AT_BOOL,
                                         pMemory: &this->m_bNiceFiltered);
  this->m_bNormalMap.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "normalMap",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bNormalMap);
  this->m_flBumpScale.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "bumpScale",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flBumpScale);
  this->m_nCompressType.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "compressType",
                                         type: AT_INT,
                                         pMemory: &this->m_nCompressType);
  this->m_nFilterType.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "filterType",
                                       type: AT_INT,
                                       pMemory: &this->m_nFilterType);
  this->m_nMipmapType.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "mipmapType",
                                       type: AT_INT,
                                       pMemory: &this->m_nMipmapType);
  this->m_nTextureType.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "textureType",
                                        type: AT_INT,
                                        pMemory: &this->m_nTextureType);
  this->m_Frames.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "frames",
                                  type: AT_FIRST_ARRAY_TYPE,
                                  pMemory: &this->m_Frames);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Frames.m_pAttribute, typeSymbol: CDmeTextureFrame::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00567A50
// Name: public: class CDmeImageArray __near * CDmeTextureFrame::GetMipLevel(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeImageArray *__thiscall CDmeTextureFrame::GetMipLevel(CDmeTextureFrame *this, int nIndex)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_MipLevels.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeImageArray::m_classType) )
    return (CDmeImageArray *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00567AA0
// Name: public: class CDmeImageArray __near * CDmeTextureFrame::AddMipLevel(void)
// Source: json
//------------------------------------------------------------------------------
CVTFTexture *__thiscall CDmeTextureFrame::AddMipLevel(CDmeTextureFrame *this)
{
  DmElementHandle_t v2; // eax
  CDmElement *v3; // eax
  CVTFTexture *v4; // esi
  DmElementHandle_t src; // [esp+8h] [ebp-4h] BYREF

  v2 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeImageArray::m_classType.u.m_Id,
         a3: "mip",
         a4: this->m_fileId,
         a5: nullptr);
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
  v4 = (CVTFTexture *)v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeImageArray::m_classType) )
  {
    src = CCoreDispNode::GetCenterVertIndex(this: v4);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_MipLevels,
      &src);
    return v4;
  }
  else
  {
    src = DMELEMENT_HANDLE_INVALID;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_MipLevels,
      &src);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00567B40
// Name: public: int CDmeTextureFrame::ImageCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTextureFrame::ImageCount(CDmeTextureFrame *this)
{
  int result; // eax
  int v3; // edi
  CDmElement *v4; // eax
  CVTFTexture *v5; // esi
  int nMipCount; // [esp+Ch] [ebp-8h]
  int nImageCount; // [esp+10h] [ebp-4h]

  result = 0;
  v3 = 0;
  nImageCount = 0;
  nMipCount = this->m_MipLevels.m_Storage.m_Size;
  if ( nMipCount > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_MipLevels.m_Storage.m_Memory.m_pMemory[v3]);
      v5 = (CVTFTexture *)v4;
      if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeImageArray::m_classType) )
        v5 = nullptr;
      if ( nImageCount <= CDmeTrack::GetClipCount(this: v5) )
        nImageCount = CDmeTrack::GetClipCount(this: v5);
      ++v3;
    }
    while ( v3 < nMipCount );
    return nImageCount;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00567BC0
// Name: public: int CDmeTexture::Width(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTexture::Width(CDmeTexture *this)
{
  CDmElement *v1; // eax
  CDmElement *v2; // esi
  CDmElement *v3; // eax
  CDmeImageArray *v4; // esi

  if ( this->m_Frames.m_Storage.m_Size == 0 )
    return 0;
  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Frames.m_Storage.m_Memory.m_pMemory);
  v2 = v1;
  if ( v1 == nullptr || !v1->IsA(this: v1, a2: CDmeTextureFrame::m_classType) )
    v2 = nullptr;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2[1].OnAttributeChanged);
  v4 = (CDmeImageArray *)v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeImageArray::m_classType) )
    return CDmeImageArray::Width(this: v4);
  else
    return CDmeImageArray::Width(this: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00567C50
// Name: public: int CDmeTexture::Height(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTexture::Height(CDmeTexture *this)
{
  CDmElement *v1; // eax
  CDmElement *v2; // esi
  CDmElement *v3; // eax
  CDmeImageArray *v4; // esi

  if ( this->m_Frames.m_Storage.m_Size == 0 )
    return 0;
  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Frames.m_Storage.m_Memory.m_pMemory);
  v2 = v1;
  if ( v1 == nullptr || !v1->IsA(this: v1, a2: CDmeTextureFrame::m_classType) )
    v2 = nullptr;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2[1].OnAttributeChanged);
  v4 = (CDmeImageArray *)v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeImageArray::m_classType) )
    return CDmeImageArray::Height(this: v4);
  else
    return CDmeImageArray::Height(this: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00567CE0
// Name: public: int CDmeTexture::Depth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTexture::Depth(CDmeTexture *this)
{
  CDmElement *v1; // eax
  CDmElement *v2; // esi
  CDmElement *v3; // eax
  CDmeImageArray *v4; // esi

  if ( this->m_Frames.m_Storage.m_Size == 0 )
    return 0;
  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Frames.m_Storage.m_Memory.m_pMemory);
  v2 = v1;
  if ( v1 == nullptr || !v1->IsA(this: v1, a2: CDmeTextureFrame::m_classType) )
    v2 = nullptr;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2[1].OnAttributeChanged);
  v4 = (CDmeImageArray *)v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeImageArray::m_classType) )
    return CDmeImageArray::Depth(this: v4);
  else
    return CDmeImageArray::Depth(this: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00567D70
// Name: public: class CDmeTextureFrame __near * CDmeTexture::AddFrame(void)
// Source: json
//------------------------------------------------------------------------------
CVTFTexture *__thiscall CDmeTexture::AddFrame(CDmeTexture *this)
{
  DmElementHandle_t v2; // eax
  CDmElement *v3; // eax
  CVTFTexture *v4; // esi
  DmElementHandle_t src; // [esp+8h] [ebp-4h] BYREF

  v2 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeTextureFrame::m_classType.u.m_Id,
         a3: "frame",
         a4: this->m_fileId,
         a5: nullptr);
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
  v4 = (CVTFTexture *)v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeTextureFrame::m_classType) )
  {
    src = CCoreDispNode::GetCenterVertIndex(this: v4);
  }
  else
  {
    v4 = nullptr;
    src = DMELEMENT_HANDLE_INVALID;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &this->m_Frames,
    &src);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00567E00
// Name: public: void CDmeTexture::GetImages(int,int,class CDmeImage __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTexture::GetImages(CDmeTexture *this, int nFrame, int nImageIndex, CDmeImage **ppImages, int nSize)
{
  CDmElement *v7; // eax
  CDmElement *v8; // ebx
  int i; // edi
  CDmElement *v10; // eax
  CDmeImageArray *v11; // esi
  int nMipCount; // [esp+20h] [ebp+14h]

  memset(dst: (unsigned __int8 *)ppImages, value: 0, count: 4 * nSize);
  if ( nFrame < this->m_Frames.m_Storage.m_Size )
  {
    v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Frames.m_Storage.m_Memory.m_pMemory[nFrame]);
    v8 = v7;
    if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeTextureFrame::m_classType) )
    {
      nMipCount = *(_DWORD *)&v8[1].m_Id.m_Value[8];
      if ( nMipCount >= nSize )
        nMipCount = nSize;
      for ( i = 0; i < nMipCount; ++i )
      {
        v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&v8[1].OnAttributeChanged + i));
        v11 = (CDmeImageArray *)v10;
        if ( v10 != nullptr
          && v10->IsA(this: v10, a2: CDmeImageArray::m_classType)
          && nImageIndex < CDmeTrack::GetClipCount(this: (CVTFTexture *)v11) )
        {
          ppImages[i] = CDmeImageArray::GetImage(this: v11, nIndex: nImageIndex);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00567FA0
// Name: public: virtual bool CDmeTextureFrame::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTextureFrame::IsA(CDmeTextureFrame *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTextureFrame::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00567FD0
// Name: public: virtual int CDmeTextureFrame::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTextureFrame::GetInheritanceDepth(CDmeTextureFrame *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTextureFrame::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00568010
// Name: protected: virtual void CDmeTextureFrame::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTextureFrame::PerformConstruction(CDmeTextureFrame *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  this->m_MipLevels.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "mipLevels",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_MipLevels);
  CDmAttribute::SetElementTypeSymbol(this: this->m_MipLevels.m_pAttribute, typeSymbol: CDmeImageArray::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00568090
// Name: protected: CDmeTexture::CDmeTexture(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTexture *__thiscall CDmeTexture::CDmeTexture(
        CDmeTexture *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTexture_vtbl *)&CDmeTexture::`vftable';
  this->m_bClampS.m_pAttribute = nullptr;
  this->m_bClampS.m_Storage = false;
  this->m_bClampT.m_pAttribute = nullptr;
  this->m_bClampT.m_Storage = false;
  this->m_bClampU.m_pAttribute = nullptr;
  this->m_bClampU.m_Storage = false;
  this->m_bNoDebugOverride.m_pAttribute = nullptr;
  this->m_bNoDebugOverride.m_Storage = false;
  this->m_bNoLod.m_pAttribute = nullptr;
  this->m_bNoLod.m_Storage = false;
  this->m_bNiceFiltered.m_pAttribute = nullptr;
  this->m_bNiceFiltered.m_Storage = false;
  this->m_bNormalMap.m_pAttribute = nullptr;
  this->m_bNormalMap.m_Storage = false;
  this->m_flBumpScale = 0;
  this->m_nCompressType.m_pAttribute = nullptr;
  this->m_nCompressType.m_Storage = 0;
  this->m_nFilterType.m_pAttribute = nullptr;
  this->m_nFilterType.m_Storage = 0;
  this->m_nMipmapType.m_pAttribute = nullptr;
  this->m_nMipmapType.m_Storage = 0;
  this->m_nTextureType.m_pAttribute = nullptr;
  this->m_nTextureType.m_Storage = 0;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Frames);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00568140
// Name: public: virtual bool CDmeTexture::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTexture::IsA(CDmeTexture *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTexture::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00568170
// Name: public: virtual int CDmeTexture::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTexture::GetInheritanceDepth(CDmeTexture *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTexture::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005681B0
// Name: protected: virtual void CDmeTexture::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTexture::PerformConstruction(CDmeTexture *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeTexture::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B6F60
// Name: _dynamic_initializer_for__CDmeTextureFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTextureFrame::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTextureFrame::s_Allocator,
    blockSize: 0x60u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTextureFrame pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTextureFrame::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BC470
// Name: _dynamic_atexit_destructor_for__CDmeTextureFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTextureFrame::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTextureFrame::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B6F90
// Name: _dynamic_initializer_for__g_CDmeTextureFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTextureFrame_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTextureFrame_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B6FA0
// Name: _dynamic_initializer_for__g_CDmeTextureFrame_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTextureFrame_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTextureFrame_Helper,
           classname: "DmeTextureFrame",
           pFactory: &g_CDmeTextureFrame_Factory,
           bIsStandardFactory: false);
}

} // namespace vmap

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x10092880
// Name: public: void CDmeTexture::RemoveAllFrames(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTexture::RemoveAllFrames(CDmeTexture *this)
{
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &this->m_Frames);
}

//------------------------------------------------------------------------------
// Address: 0x10092890
// Name: public: void CDmeTextureFrame::AddMipLevel(class CDmeImageArray __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTextureFrame::AddMipLevel(CDmeTextureFrame *this, int pImages)
{
  if ( pImages != 0 )
    pImages = CVTFTexture::MipCount(this: (CVTFTexture *)pImages);
  else
    pImages = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &this->m_MipLevels,
    src: (DmElementHandle_t *)&pImages);
}

//------------------------------------------------------------------------------
// Address: 0x100928E0
// Name: protected: void CDmeTexture::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTexture::OnConstruction(CDmeTexture *this)
{
  this->m_bClampS.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "clampS",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bClampS);
  this->m_bClampT.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "clampT",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bClampT);
  this->m_bClampU.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "clampU",
                                   type: AT_BOOL,
                                   pMemory: &this->m_bClampU);
  this->m_bNoDebugOverride.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "noDebugOverride",
                                            type: AT_BOOL,
                                            pMemory: &this->m_bNoDebugOverride);
  this->m_bNoLod.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "noMipmapLOD",
                                  type: AT_BOOL,
                                  pMemory: &this->m_bNoLod);
  this->m_bNiceFiltered.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "niceFiltered",
                                         type: AT_BOOL,
                                         pMemory: &this->m_bNiceFiltered);
  this->m_bNormalMap.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "normalMap",
                                      type: AT_BOOL,
                                      pMemory: &this->m_bNormalMap);
  this->m_flBumpScale.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "bumpScale",
                                       type: AT_FLOAT,
                                       pMemory: &this->m_flBumpScale);
  this->m_nCompressType.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "compressType",
                                         type: AT_INT,
                                         pMemory: &this->m_nCompressType);
  this->m_nFilterType.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "filterType",
                                       type: AT_INT,
                                       pMemory: &this->m_nFilterType);
  this->m_nMipmapType.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "mipmapType",
                                       type: AT_INT,
                                       pMemory: &this->m_nMipmapType);
  this->m_nTextureType.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "textureType",
                                        type: AT_INT,
                                        pMemory: &this->m_nTextureType);
  this->m_Frames.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "frames",
                                  type: AT_FIRST_ARRAY_TYPE,
                                  pMemory: &this->m_Frames);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Frames.m_pAttribute, typeSymbol: CDmeTextureFrame::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x10092A20
// Name: public: class CDmeImageArray __near * CDmeTextureFrame::GetMipLevel(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeImageArray *__thiscall CDmeTextureFrame::GetMipLevel(CDmeTextureFrame *this, int nIndex)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_MipLevels.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeImageArray::m_classType) )
    return (CDmeImageArray *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10092A70
// Name: public: class CDmeImageArray __near * CDmeTextureFrame::AddMipLevel(void)
// Source: json
//------------------------------------------------------------------------------
CVTFTexture *__thiscall CDmeTextureFrame::AddMipLevel(CDmeTextureFrame *this)
{
  DmElementHandle_t v2; // eax
  CDmElement *v3; // eax
  CVTFTexture *v4; // esi
  DmElementHandle_t src; // [esp+8h] [ebp-4h] BYREF

  v2 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeImageArray::m_classType.u.m_Id,
         a3: "mip",
         a4: this->m_fileId,
         a5: nullptr);
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
  v4 = (CVTFTexture *)v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeImageArray::m_classType) )
  {
    src = CVTFTexture::MipCount(this: v4);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_MipLevels,
      &src);
    return v4;
  }
  else
  {
    src = DMELEMENT_HANDLE_INVALID;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_MipLevels,
      &src);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10092B10
// Name: public: int CDmeTextureFrame::ImageCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTextureFrame::ImageCount(CDmeTextureFrame *this)
{
  int result; // eax
  int v3; // edi
  CDmElement *v4; // eax
  CVTFTexture *v5; // esi
  int nMipCount; // [esp+Ch] [ebp-8h]
  int nImageCount; // [esp+10h] [ebp-4h]

  result = 0;
  v3 = 0;
  nImageCount = 0;
  nMipCount = this->m_MipLevels.m_Storage.m_Size;
  if ( nMipCount > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_MipLevels.m_Storage.m_Memory.m_pMemory[v3]);
      v5 = (CVTFTexture *)v4;
      if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeImageArray::m_classType) )
        v5 = nullptr;
      if ( nImageCount <= CVTFTexture::LowResWidth(this: v5) )
        nImageCount = CVTFTexture::LowResWidth(this: v5);
      ++v3;
    }
    while ( v3 < nMipCount );
    return nImageCount;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10092B90
// Name: public: int CDmeTexture::Width(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement_vtbl *__thiscall CDmeTexture::Width(CDmeTexture *this)
{
  CDmElement *v1; // eax
  CDmElement *v2; // esi
  CDmElement *v3; // eax
  CDmeImageArray *v4; // esi

  if ( this->m_Frames.m_Storage.m_Size == 0 )
    return nullptr;
  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Frames.m_Storage.m_Memory.m_pMemory);
  v2 = v1;
  if ( v1 == nullptr || !v1->IsA(this: v1, a2: CDmeTextureFrame::m_classType) )
    v2 = nullptr;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2[1].OnAttributeChanged);
  v4 = (CDmeImageArray *)v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeImageArray::m_classType) )
    return CDmeImageArray::Width(this: v4);
  else
    return CDmeImageArray::Width(this: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10092C20
// Name: public: int CDmeTexture::Height(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTexture::Height(CDmeTexture *this)
{
  CDmElement *v1; // eax
  CDmElement *v2; // esi
  CDmElement *v3; // eax
  CDmeImageArray *v4; // esi

  if ( this->m_Frames.m_Storage.m_Size == 0 )
    return 0;
  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Frames.m_Storage.m_Memory.m_pMemory);
  v2 = v1;
  if ( v1 == nullptr || !v1->IsA(this: v1, a2: CDmeTextureFrame::m_classType) )
    v2 = nullptr;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2[1].OnAttributeChanged);
  v4 = (CDmeImageArray *)v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeImageArray::m_classType) )
    return CDmeImageArray::Height(this: v4);
  else
    return CDmeImageArray::Height(this: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10092CB0
// Name: public: int CDmeTexture::Depth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTexture::Depth(CDmeTexture *this)
{
  CDmElement *v1; // eax
  CDmElement *v2; // esi
  CDmElement *v3; // eax
  CDmeImageArray *v4; // esi

  if ( this->m_Frames.m_Storage.m_Size == 0 )
    return 0;
  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Frames.m_Storage.m_Memory.m_pMemory);
  v2 = v1;
  if ( v1 == nullptr || !v1->IsA(this: v1, a2: CDmeTextureFrame::m_classType) )
    v2 = nullptr;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2[1].OnAttributeChanged);
  v4 = (CDmeImageArray *)v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeImageArray::m_classType) )
    return CDmeImageArray::Depth(this: v4);
  else
    return CDmeImageArray::Depth(this: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10092D40
// Name: public: enum ImageFormat CDmeTexture::Format(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTexture::Format(CDmeTexture *this)
{
  CDmElement *v1; // eax
  CDmElement *v2; // esi
  CDmElement *v3; // eax
  CDmeImageArray *v4; // esi

  if ( this->m_Frames.m_Storage.m_Size == 0 )
    return -1;
  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Frames.m_Storage.m_Memory.m_pMemory);
  v2 = v1;
  if ( v1 == nullptr || !v1->IsA(this: v1, a2: CDmeTextureFrame::m_classType) )
    v2 = nullptr;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2[1].OnAttributeChanged);
  v4 = (CDmeImageArray *)v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeImageArray::m_classType) )
    return CDmeImageArray::Format(this: v4);
  else
    return CDmeImageArray::Format(this: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10092DD0
// Name: public: int CDmeTexture::MipLevelCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTexture::MipLevelCount(CDmeTexture *this)
{
  CDmElement *v1; // eax
  CDmElement *v2; // esi

  if ( this->m_Frames.m_Storage.m_Size == 0 )
    return 0;
  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Frames.m_Storage.m_Memory.m_pMemory);
  v2 = v1;
  if ( v1 == nullptr || !v1->IsA(this: v1, a2: CDmeTextureFrame::m_classType) )
    v2 = nullptr;
  return *(_DWORD *)&v2[1].m_Id.m_Value[8];
}

//------------------------------------------------------------------------------
// Address: 0x10092E20
// Name: public: class CDmeTextureFrame __near * CDmeTexture::AddFrame(void)
// Source: json
//------------------------------------------------------------------------------
CVTFTexture *__thiscall CDmeTexture::AddFrame(CDmeTexture *this)
{
  DmElementHandle_t v2; // eax
  CDmElement *v3; // eax
  CVTFTexture *v4; // esi
  DmElementHandle_t src; // [esp+8h] [ebp-4h] BYREF

  v2 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeTextureFrame::m_classType.u.m_Id,
         a3: "frame",
         a4: this->m_fileId,
         a5: nullptr);
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
  v4 = (CVTFTexture *)v3;
  if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeTextureFrame::m_classType) )
  {
    src = CVTFTexture::MipCount(this: v4);
  }
  else
  {
    v4 = nullptr;
    src = DMELEMENT_HANDLE_INVALID;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &this->m_Frames,
    &src);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10092EB0
// Name: public: void CDmeTexture::GetImages(int,int,class CDmeImage __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTexture::GetImages(CDmeTexture *this, int nFrame, int nImageIndex, CDmeImage **ppImages, int nSize)
{
  CDmElement *v7; // eax
  CDmElement *v8; // ebx
  int i; // edi
  CDmElement *v10; // eax
  CDmeImageArray *v11; // esi
  int nMipCount; // [esp+20h] [ebp+14h]

  memset(dst: (unsigned __int8 *)ppImages, value: 0, count: 4 * nSize);
  if ( nFrame < this->m_Frames.m_Storage.m_Size )
  {
    v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Frames.m_Storage.m_Memory.m_pMemory[nFrame]);
    v8 = v7;
    if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeTextureFrame::m_classType) )
    {
      nMipCount = *(_DWORD *)&v8[1].m_Id.m_Value[8];
      if ( nMipCount >= nSize )
        nMipCount = nSize;
      for ( i = 0; i < nMipCount; ++i )
      {
        v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&v8[1].OnAttributeChanged + i));
        v11 = (CDmeImageArray *)v10;
        if ( v10 != nullptr
          && v10->IsA(this: v10, a2: CDmeImageArray::m_classType)
          && nImageIndex < CVTFTexture::LowResWidth(this: (CVTFTexture *)v11) )
        {
          ppImages[i] = CDmeImageArray::GetImage(this: v11, nIndex: nImageIndex);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093160
// Name: public: void CDmeTexture::CompressTexture(class CDmeTexture __near *,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTexture::CompressTexture(
        CDmeTexture *this,
        CDmeTexture *pSrcTexture,
        CDmeTexture::CompressTexture::__l2::CCompressionFunctor fmt)
{
  Z::ProcessTexture<`CDmeTexture::CompressTexture'::`2'::CCompressionFunctor,unsigned char * const,void,CDmeTexture *,enum ImageFormat>(
    this,
    pSrcTexture,
    func: &fmt);
}

//------------------------------------------------------------------------------
// Address: 0x10093250
// Name: public: virtual bool CDmeTextureFrame::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTextureFrame::IsA(CDmeTextureFrame *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTextureFrame::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10093280
// Name: public: virtual int CDmeTextureFrame::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTextureFrame::GetInheritanceDepth(CDmeTextureFrame *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTextureFrame::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100932D0
// Name: protected: virtual void CDmeTextureFrame::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTextureFrame::PerformConstruction(CDmeTextureFrame *this)
{
  CDmElementFramework::Disconnect((CDmeTexture *)this);
  this->m_MipLevels.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "mipLevels",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_MipLevels);
  CDmAttribute::SetElementTypeSymbol(this: this->m_MipLevels.m_pAttribute, typeSymbol: CDmeImageArray::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x10093350
// Name: protected: CDmeTexture::CDmeTexture(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeTexture *__thiscall CDmeTexture::CDmeTexture(
        CDmeTexture *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeTexture_vtbl *)&CDmeTexture::`vftable';
  this->m_bClampS.m_pAttribute = nullptr;
  this->m_bClampS.m_Storage = false;
  this->m_bClampT.m_pAttribute = nullptr;
  this->m_bClampT.m_Storage = false;
  this->m_bClampU.m_pAttribute = nullptr;
  this->m_bClampU.m_Storage = false;
  this->m_bNoDebugOverride.m_pAttribute = nullptr;
  this->m_bNoDebugOverride.m_Storage = false;
  this->m_bNoLod.m_pAttribute = nullptr;
  this->m_bNoLod.m_Storage = false;
  this->m_bNiceFiltered.m_pAttribute = nullptr;
  this->m_bNiceFiltered.m_Storage = false;
  this->m_bNormalMap.m_pAttribute = nullptr;
  this->m_bNormalMap.m_Storage = false;
  this->m_flBumpScale = 0;
  this->m_nCompressType.m_pAttribute = nullptr;
  this->m_nCompressType.m_Storage = 0;
  this->m_nFilterType.m_pAttribute = nullptr;
  this->m_nFilterType.m_Storage = 0;
  this->m_nMipmapType.m_pAttribute = nullptr;
  this->m_nMipmapType.m_Storage = 0;
  this->m_nTextureType.m_pAttribute = nullptr;
  this->m_nTextureType.m_Storage = 0;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Frames);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10093400
// Name: public: virtual bool CDmeTexture::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTexture::IsA(CDmeTexture *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTexture::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10093430
// Name: public: virtual int CDmeTexture::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTexture::GetInheritanceDepth(CDmeTexture *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTexture::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10093470
// Name: protected: virtual int CDmeTexture::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTexture::AllocatedSize(CDmeTexture *this)
{
  return 204;
}

//------------------------------------------------------------------------------
// Address: 0x10093480
// Name: protected: virtual void CDmeTexture::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTexture::PerformConstruction(CDmeTexture *this)
{
  CDmElementFramework::Disconnect(this);
  CDmeTexture::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C4AA0
// Name: _dynamic_initializer_for__CDmeTextureFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTextureFrame::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTextureFrame::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTextureFrame pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTextureFrame::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x100C52F0
// Name: _dynamic_atexit_destructor_for__CDmeTextureFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTextureFrame::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTextureFrame::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x100C4AD0
// Name: _dynamic_initializer_for__g_CDmeTextureFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTextureFrame_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTextureFrame_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4AE0
// Name: _dynamic_initializer_for__g_CDmeTextureFrame_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTextureFrame_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTextureFrame_Helper,
           classname: "DmeTextureFrame",
           pFactory: &g_CDmeTextureFrame_Factory,
           bIsStandardFactory: false);
}

} // namespace vtex_dll
