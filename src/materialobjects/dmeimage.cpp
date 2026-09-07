// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialobjects/dmeimage.cpp
// Functions: 31
// ============================================================

#include "materialobjects\dmeimage.h"

//------------------------------------------------------------------------------
// Address: 0x00461D30
// Name: public: void CDmeImage::EndFloatBitmapModification(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::EndFloatBitmapModification(CDmeImage *this)
{
  this->m_bInFloatBitmapModification = false;
}

//------------------------------------------------------------------------------
// Address: 0x00461D40
// Name: protected: void CDmeImage::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::OnConstruction(CDmeImage *this)
{
  CDmaVar<int> *p_m_nWidth; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax

  p_m_nWidth = &this->m_nWidth;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "width", type: AT_INT, pMemory: &this->m_nWidth);
  p_m_nWidth->m_pAttribute = v3;
  v3->m_nFlags |= 0x8000u;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "height", type: AT_INT, pMemory: &this->m_nHeight);
  this->m_nHeight.m_pAttribute = v4;
  v4->m_nFlags |= 0x8000u;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "depth", type: AT_INT, pMemory: &this->m_nDepth);
  this->m_nDepth.m_pAttribute = v5;
  v5->m_nFlags |= 0x8000u;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "format", type: AT_INT, pMemory: &this->m_nFormat);
  this->m_nFormat.m_pAttribute = v6;
  v6->m_nFlags |= 0x8000u;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "gamma", type: AT_FLOAT, pMemory: &this->m_flGamma);
  this->m_flGamma.m_pAttribute = v7;
  v7->m_nFlags |= 0x8000u;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "bits", type: AT_VOID, pMemory: &this->m_Bits);
  this->m_Bits.m_pAttribute = v8;
  v8->m_nFlags |= 0x8100u;
  this->m_Mode = DMEIMAGE_STORAGE_NONE;
  *(_WORD *)&this->m_bInModification = 0;
  this->m_bIgnoreChangedBitsAttribute = false;
  this->m_hModify = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00461E20
// Name: public: class CUtlBinaryBlock __near & CDmeImage::BeginModification(void)
// Source: json
//------------------------------------------------------------------------------
CUtlBinaryBlock *__thiscall CDmeImage::BeginModification(CDmeImage *this)
{
  CDmAttribute *m_pAttribute; // ecx

  CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: false, bDiscardContents: false);
  m_pAttribute = this->m_Bits.m_pAttribute;
  this->m_bInModification = true;
  return CDmAttribute::BeginModifyValueInPlace<CUtlBinaryBlock>(this: m_pAttribute, pHandle: &this->m_hModify);
}

//------------------------------------------------------------------------------
// Address: 0x00461E50
// Name: public: void CDmeImage::EndModification(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::EndModification(CDmeImage *this)
{
  char *m_hModify; // eax
  CDmAttribute *m_pAttribute; // ecx

  m_hModify = (char *)this->m_hModify;
  m_pAttribute = this->m_Bits.m_pAttribute;
  this->m_bInModification = false;
  this->m_bIgnoreChangedBitsAttribute = true;
  CDmAttribute::EndModifyValueInPlace<CUtlBinaryBlock>(this: m_pAttribute, handle: m_hModify);
  this->m_bIgnoreChangedBitsAttribute = false;
  this->m_hModify = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00461E90
// Name: public: int CDmeImage::SizeInBytes(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImage::SizeInBytes(CDmeImage *this)
{
  return ImageLoader::GetMemRequired(
           width: this->m_nWidth.m_Storage,
           height: this->m_nHeight.m_Storage,
           depth: this->m_nDepth.m_Storage,
           imageFormat: (ImageFormat)this->m_nFormat.m_Storage,
           mipmap: false,
           pAdjustedHeight: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00461EB0
// Name: public: void CDmeImage::SetFloatBitmapStorageMode(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::SetFloatBitmapStorageMode(CDmeImage *this, int bFloatBitmap, bool bDiscardContents)
{
  CDmeImage::StorageMode_t m_Mode; // ebx
  CDmeImage::StorageMode_t v5; // eax
  __int32 v6; // eax
  int m_nColumns; // eax
  CDmAttribute *v8; // ecx
  CDmAttribute *v9; // ecx
  CUtlBinaryBlock *v10; // edi
  int v11; // eax
  CDmAttribute *m_pAttribute; // ecx
  CUtlBinaryBlock *v13; // edi
  int MemRequired; // eax
  const ImageFormatInfo_t *v15; // eax
  char v16; // cl
  int m_nSlices; // [esp+10h] [ebp-8h] BYREF
  int value; // [esp+14h] [ebp-4h] BYREF

  m_Mode = this->m_Mode;
  v5 = ((_BYTE)bFloatBitmap == 0) + 1;
  if ( v5 != m_Mode )
  {
    this->m_Mode = v5;
    v6 = v5 - 1;
    if ( v6 != 0 )
    {
      if ( v6 == 1 )
      {
        if ( bDiscardContents || m_Mode != DMEIMAGE_STORAGE_FLOAT_BITMAP )
        {
          CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: false, bDiscardContents: false);
          m_pAttribute = this->m_Bits.m_pAttribute;
          this->m_bInModification = true;
          v13 = CDmAttribute::BeginModifyValueInPlace<CUtlBinaryBlock>(this: m_pAttribute, pHandle: &this->m_hModify);
          MemRequired = ImageLoader::GetMemRequired(
                          width: this->m_nWidth.m_Storage,
                          height: this->m_nHeight.m_Storage,
                          depth: this->m_nDepth.m_Storage,
                          imageFormat: (ImageFormat)this->m_nFormat.m_Storage,
                          mipmap: false,
                          pAdjustedHeight: nullptr);
          CUtlBinaryBlock::SetLength(this: v13, nLength: MemRequired);
        }
        else
        {
          m_nColumns = this->m_ComputeBits.m_nColumns;
          v8 = this->m_nWidth.m_pAttribute;
          bFloatBitmap = m_nColumns;
          CDmAttribute::SetValue<int>(this: v8, value: &bFloatBitmap);
          v9 = this->m_nHeight.m_pAttribute;
          value = this->m_ComputeBits.m_nRows;
          CDmAttribute::SetValue<int>(this: v9, &value);
          m_nSlices = this->m_ComputeBits.m_nSlices;
          CDmAttribute::SetValue<int>(this: this->m_nDepth.m_pAttribute, value: &m_nSlices);
          v10 = CDmeImage::BeginModification(this);
          v11 = CDmeImage::SizeInBytes(this);
          CUtlBinaryBlock::SetLength(this: v10, nLength: v11);
          FloatBitMap_t::WriteToBuffer(
            this: &this->m_ComputeBits,
            pBuffer: v10->m_Memory.m_pMemory,
            nBufSize: v10->m_nActualLength,
            fmt: (ImageFormat)this->m_nFormat.m_Storage,
            flGamma: this->m_flGamma.m_Storage);
        }
        CDmeImage::EndModification(this);
        CSOAContainer::~CSOAContainer(this: &this->m_ComputeBits);
      }
    }
    else
    {
      v15 = ImageLoader::ImageFormatInfo(fmt: (ImageFormat)this->m_nFormat.m_Storage);
      v16 = v15->m_nNumRedBits != 0;
      if ( v15->m_nNumGreenBits != 0 )
        v16 |= 2u;
      if ( v15->m_nNumBlueBits != 0 )
        v16 |= 4u;
      if ( v15->m_nNumAlphaBits != 0 )
        v16 |= 8u;
      FloatBitMap_t::Init(
        this: &this->m_ComputeBits,
        nXSize: this->m_nWidth.m_Storage,
        nYSize: this->m_nHeight.m_Storage,
        nZSize: this->m_nDepth.m_Storage,
        nAttributeMask: v16);
      if ( !bDiscardContents && m_Mode == DMEIMAGE_STORAGE_ATTRIBUTE )
        FloatBitMap_t::LoadFromBuffer(
          this: &this->m_ComputeBits,
          pBuffer: this->m_Bits.m_Storage.m_Memory.m_pMemory,
          nBufSize: this->m_Bits.m_Storage.m_nActualLength,
          fmt: (ImageFormat)this->m_nFormat.m_Storage,
          flGamma: this->m_flGamma.m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00462050
// Name: public: class FloatBitMap_t __near & CDmeImage::BeginFloatBitmapModification(void)
// Source: json
//------------------------------------------------------------------------------
FloatBitMap_t *__thiscall CDmeImage::BeginFloatBitmapModification(CDmeImage *this)
{
  CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 1, bDiscardContents: false);
  this->m_bInFloatBitmapModification = true;
  return &this->m_ComputeBits;
}

//------------------------------------------------------------------------------
// Address: 0x00462070
// Name: public: class FloatBitMap_t const __near * CDmeImage::FloatBitmap(void)
// Source: json
//------------------------------------------------------------------------------
const FloatBitMap_t *__thiscall CDmeImage::FloatBitmap(CDmeImage *this)
{
  CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 1, bDiscardContents: false);
  return &this->m_ComputeBits;
}

//------------------------------------------------------------------------------
// Address: 0x00462090
// Name: public: virtual void CDmeImage::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::OnAttributeChanged(CDmeImage *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_Bits.m_pAttribute
    && !this->m_bIgnoreChangedBitsAttribute
    && this->m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
  {
    CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 0, bDiscardContents: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004620C0
// Name: public: virtual void CDmeImage::OnElementUnserialized(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::OnElementUnserialized(CDmeImage *this)
{
  if ( this->m_Mode != DMEIMAGE_STORAGE_ATTRIBUTE )
    CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 0, bDiscardContents: true);
}

//------------------------------------------------------------------------------
// Address: 0x004620E0
// Name: public: virtual void CDmeImage::OnElementSerialized(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::OnElementSerialized(CDmeImage *this)
{
  if ( this->m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 0, bDiscardContents: false);
}

//------------------------------------------------------------------------------
// Address: 0x00462160
// Name: protected: CDmeImage::CDmeImage(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeImage *__thiscall CDmeImage::CDmeImage(
        CDmeImage *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeImage_vtbl *)&CDmeImage::`vftable';
  this->m_nWidth.m_pAttribute = nullptr;
  this->m_nWidth.m_Storage = 0;
  this->m_nHeight.m_pAttribute = nullptr;
  this->m_nHeight.m_Storage = 0;
  this->m_nDepth.m_pAttribute = nullptr;
  this->m_nDepth.m_Storage = 0;
  this->m_nFormat.m_pAttribute = nullptr;
  this->m_nFormat.m_Storage = 0;
  this->m_flGamma = 0;
  CUtlBinaryBlock::CUtlBinaryBlock(this: &this->m_Bits.m_Storage, growSize: 0, initSize: 0);
  this->m_Bits.m_pAttribute = nullptr;
  CUtlBinaryBlock::Set(this: &this->m_Bits.m_Storage, pValue: nullptr, nLen: 0);
  memset(
    dst: (unsigned __int8 *)this->m_ComputeBits.m_nDataType,
    value: 0xFFu,
    count: sizeof(this->m_ComputeBits.m_nDataType));
  memset(
    dst: (unsigned __int8 *)this->m_ComputeBits.m_pSeparateDataMemory,
    value: 0,
    count: sizeof(this->m_ComputeBits.m_pSeparateDataMemory));
  this->m_ComputeBits.m_pConstantDataMemory = nullptr;
  this->m_ComputeBits.m_pDataMemory = nullptr;
  this->m_ComputeBits.m_nNumQuadsPerRow = 0;
  this->m_ComputeBits.m_nSlices = 0;
  this->m_ComputeBits.m_nRows = 0;
  this->m_ComputeBits.m_nPaddedColumns = 0;
  this->m_ComputeBits.m_nColumns = 0;
  this->m_ComputeBits.m_nFieldPresentMask = 0;
  this->m_ComputeBits.m_eThreadMode = SOATHREADMODE_NONE;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00462230
// Name: public: virtual bool CDmeImage::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeImage::IsA(CDmeImage *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeImage::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00462260
// Name: public: virtual int CDmeImage::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImage::GetInheritanceDepth(CDmeImage *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeImage::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004622A0
// Name: protected: virtual int CDmeImage::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImage::AllocatedSize(CDmeImage *this)
{
  return 944;
}

//------------------------------------------------------------------------------
// Address: 0x004622B0
// Name: protected: virtual void CDmeImage::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::PerformConstruction(CDmeImage *this)
{
  CSteamApplication::PostShutdown();
  CDmeImage::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004623E0
// Name: public: virtual bool CDmeImageArray::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeImageArray::IsA(CDmeImageArray *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeImageArray::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00462410
// Name: public: virtual int CDmeImageArray::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImageArray::GetInheritanceDepth(CDmeImageArray *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeImageArray::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00462450
// Name: protected: virtual int CDmeImageArray::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImageArray::AllocatedSize(CDmeImageArray *this)
{
  return 96;
}

//------------------------------------------------------------------------------
// Address: 0x00462460
// Name: protected: virtual void CDmeImageArray::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImageArray::PerformConstruction(CDmeImageArray *this)
{
  CSteamApplication::PostShutdown();
  this->m_Images.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "images",
                                  type: AT_FIRST_ARRAY_TYPE,
                                  pMemory: &this->m_Images);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Images.m_pAttribute, typeSymbol: CDmeImage::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004627C0
// Name: protected: virtual void CDmeImage::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDmeImage::PerformDestruction(CDmeSheetImage *this)
{
  CSteamApplication::PostShutdown();
}

//------------------------------------------------------------------------------
// Address: 0x004B7360
// Name: _dynamic_initializer_for__CDmeImage::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeImage::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeImage::s_Allocator,
    blockSize: 944,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeImage pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeImage::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x004B73C0
// Name: _dynamic_initializer_for__CDmeImageArray::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeImageArray::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeImageArray::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeImageArray pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeImageArray::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x004B79F0
// Name: _dynamic_atexit_destructor_for__CDmeImage::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeImage::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeImage::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x004B7A00
// Name: _dynamic_atexit_destructor_for__CDmeImageArray::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeImageArray::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeImageArray::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x004B7390
// Name: _dynamic_initializer_for__g_CDmeImage_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeImage_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeImage_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x004B73A0
// Name: _dynamic_initializer_for__g_CDmeImage_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeImage_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeImage_Helper,
           classname: "DmeImage",
           pFactory: &g_CDmeImage_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x004B73F0
// Name: _dynamic_initializer_for__g_CDmeImageArray_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeImageArray_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeImageArray_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x004B7400
// Name: _dynamic_initializer_for__g_CDmeImageArray_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeImageArray_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeImageArray_Helper,
           classname: "DmeImageArray",
           pFactory: &g_CDmeImageArray_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x004B7A10
// Name: _dynamic_atexit_destructor_for__g_CDmeImageArray_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeImageArray_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_CDmeImageArray_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x004B7A20
// Name: _dynamic_atexit_destructor_for__g_CDmeImage_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeImage_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_CDmeImage_Factory.m_CallBackList);
}

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004BB880
// Name: protected: void CDmeImage::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::OnConstruction(CDmeImage *this)
{
  CDmaVar<int> *p_m_nWidth; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax

  p_m_nWidth = &this->m_nWidth;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "width", type: AT_INT, pMemory: &this->m_nWidth);
  p_m_nWidth->m_pAttribute = v3;
  v3->m_nFlags |= 0x8000u;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "height", type: AT_INT, pMemory: &this->m_nHeight);
  this->m_nHeight.m_pAttribute = v4;
  v4->m_nFlags |= 0x8000u;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "depth", type: AT_INT, pMemory: &this->m_nDepth);
  this->m_nDepth.m_pAttribute = v5;
  v5->m_nFlags |= 0x8000u;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "format", type: AT_INT, pMemory: &this->m_nFormat);
  this->m_nFormat.m_pAttribute = v6;
  v6->m_nFlags |= 0x8000u;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "gamma", type: AT_FLOAT, pMemory: &this->m_flGamma);
  this->m_flGamma.m_pAttribute = v7;
  v7->m_nFlags |= 0x8000u;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "bits", type: AT_VOID, pMemory: &this->m_Bits);
  this->m_Bits.m_pAttribute = v8;
  v8->m_nFlags |= 0x8100u;
  this->m_Mode = DMEIMAGE_STORAGE_NONE;
  *(_WORD *)&this->m_bInModification = 0;
  this->m_bIgnoreChangedBitsAttribute = false;
  this->m_hModify = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004BB960
// Name: public: class CUtlBinaryBlock __near & CDmeImage::BeginModification(void)
// Source: json
//------------------------------------------------------------------------------
CUtlBinaryBlock *__thiscall CDmeImage::BeginModification(CDmeImage *this)
{
  CDmAttribute *m_pAttribute; // ecx

  CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: false, bDiscardContents: false);
  m_pAttribute = this->m_Bits.m_pAttribute;
  this->m_bInModification = true;
  return CDmAttribute::BeginModifyValueInPlace<CUtlBinaryBlock>(this: m_pAttribute, pHandle: &this->m_hModify);
}

//------------------------------------------------------------------------------
// Address: 0x004BB990
// Name: public: void CDmeImage::EndModification(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::EndModification(CDmeImage *this)
{
  char *m_hModify; // eax
  CDmAttribute *m_pAttribute; // ecx

  m_hModify = (char *)this->m_hModify;
  m_pAttribute = this->m_Bits.m_pAttribute;
  this->m_bInModification = false;
  this->m_bIgnoreChangedBitsAttribute = true;
  CDmAttribute::EndModifyValueInPlace<CUtlBinaryBlock>(this: m_pAttribute, handle: m_hModify);
  this->m_bIgnoreChangedBitsAttribute = false;
  this->m_hModify = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004BB9D0
// Name: public: int CDmeImage::SizeInBytes(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImage::SizeInBytes(CDmeImage *this)
{
  return ImageLoader::GetMemRequired(
           width: this->m_nWidth.m_Storage,
           height: this->m_nHeight.m_Storage,
           depth: this->m_nDepth.m_Storage,
           imageFormat: (ImageFormat)this->m_nFormat.m_Storage,
           mipmap: false,
           pAdjustedHeight: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004BB9F0
// Name: public: void CDmeImage::SetFloatBitmapStorageMode(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::SetFloatBitmapStorageMode(CDmeImage *this, int bFloatBitmap, bool bDiscardContents)
{
  CDmeImage::StorageMode_t m_Mode; // ebx
  CDmeImage::StorageMode_t v5; // eax
  __int32 v6; // eax
  int m_nColumns; // eax
  CDmAttribute *v8; // ecx
  CDmAttribute *v9; // ecx
  CUtlBinaryBlock *v10; // edi
  int v11; // eax
  CDmAttribute *m_pAttribute; // ecx
  CUtlBinaryBlock *v13; // edi
  int MemRequired; // eax
  const ImageFormatInfo_t *v15; // eax
  char v16; // cl
  int m_nSlices; // [esp+10h] [ebp-8h] BYREF
  int value; // [esp+14h] [ebp-4h] BYREF

  m_Mode = this->m_Mode;
  v5 = ((_BYTE)bFloatBitmap == 0) + 1;
  if ( v5 != m_Mode )
  {
    this->m_Mode = v5;
    v6 = v5 - 1;
    if ( v6 != 0 )
    {
      if ( v6 == 1 )
      {
        if ( bDiscardContents || m_Mode != DMEIMAGE_STORAGE_FLOAT_BITMAP )
        {
          CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: false, bDiscardContents: false);
          m_pAttribute = this->m_Bits.m_pAttribute;
          this->m_bInModification = true;
          v13 = CDmAttribute::BeginModifyValueInPlace<CUtlBinaryBlock>(this: m_pAttribute, pHandle: &this->m_hModify);
          MemRequired = ImageLoader::GetMemRequired(
                          width: this->m_nWidth.m_Storage,
                          height: this->m_nHeight.m_Storage,
                          depth: this->m_nDepth.m_Storage,
                          imageFormat: (ImageFormat)this->m_nFormat.m_Storage,
                          mipmap: false,
                          pAdjustedHeight: nullptr);
          CUtlBinaryBlock::SetLength(this: v13, nLength: MemRequired);
        }
        else
        {
          m_nColumns = this->m_ComputeBits.m_nColumns;
          v8 = this->m_nWidth.m_pAttribute;
          bFloatBitmap = m_nColumns;
          CDmAttribute::SetValue<int>(this: v8, value: &bFloatBitmap);
          v9 = this->m_nHeight.m_pAttribute;
          value = this->m_ComputeBits.m_nRows;
          CDmAttribute::SetValue<int>(this: v9, &value);
          m_nSlices = this->m_ComputeBits.m_nSlices;
          CDmAttribute::SetValue<int>(this: this->m_nDepth.m_pAttribute, value: &m_nSlices);
          v10 = CDmeImage::BeginModification(this);
          v11 = CDmeImage::SizeInBytes(this);
          CUtlBinaryBlock::SetLength(this: v10, nLength: v11);
          FloatBitMap_t::WriteToBuffer(
            this: &this->m_ComputeBits,
            pBuffer: v10->m_Memory.m_pMemory,
            nBufSize: v10->m_nActualLength,
            fmt: (ImageFormat)this->m_nFormat.m_Storage,
            flGamma: this->m_flGamma.m_Storage);
        }
        CDmeImage::EndModification(this);
        CSOAContainer::~CSOAContainer(this: &this->m_ComputeBits);
      }
    }
    else
    {
      v15 = ImageLoader::ImageFormatInfo(fmt: (ImageFormat)this->m_nFormat.m_Storage);
      v16 = v15->m_nNumRedBits != 0;
      if ( v15->m_nNumGreenBits != 0 )
        v16 |= 2u;
      if ( v15->m_nNumBlueBits != 0 )
        v16 |= 4u;
      if ( v15->m_nNumAlphaBits != 0 )
        v16 |= 8u;
      FloatBitMap_t::Init(
        this: &this->m_ComputeBits,
        nXSize: this->m_nWidth.m_Storage,
        nYSize: this->m_nHeight.m_Storage,
        nZSize: this->m_nDepth.m_Storage,
        nAttributeMask: v16);
      if ( !bDiscardContents && m_Mode == DMEIMAGE_STORAGE_ATTRIBUTE )
        FloatBitMap_t::LoadFromBuffer(
          this: &this->m_ComputeBits,
          pBuffer: this->m_Bits.m_Storage.m_Memory.m_pMemory,
          nBufSize: this->m_Bits.m_Storage.m_nActualLength,
          fmt: (ImageFormat)this->m_nFormat.m_Storage,
          flGamma: this->m_flGamma.m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BBB90
// Name: public: void CDmeImage::QuarterSize(class CDmeImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::QuarterSize(CDmeImage *this, float pSrcImage)
{
  CDmeImage *v3; // edi
  CDmAttribute *m_pAttribute; // ecx

  CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 1, bDiscardContents: true);
  v3 = (CDmeImage *)LODWORD(pSrcImage);
  CDmeImage::SetFloatBitmapStorageMode(this: (CDmeImage *)LODWORD(pSrcImage), bFloatBitmap: 1, bDiscardContents: false);
  FloatBitMap_t::QuarterSize(this: &v3->m_ComputeBits, pBitmap: &this->m_ComputeBits);
  pSrcImage = *(float *)&v3->m_nFormat.m_Storage;
  CDmAttribute::SetValue<int>(this: this->m_nFormat.m_pAttribute, value: (const int *)&pSrcImage);
  m_pAttribute = this->m_flGamma.m_pAttribute;
  pSrcImage = v3->m_flGamma.m_Storage;
  CDmAttribute::SetValue<float>(this: m_pAttribute, value: &pSrcImage);
}

//------------------------------------------------------------------------------
// Address: 0x004BBBF0
// Name: public: void CDmeImage::DownsampleNiceFiltered(struct DownsampleInfo_t const __near &,class CDmeImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::DownsampleNiceFiltered(CDmeImage *this, const DownsampleInfo_t *info, float pSrcImage)
{
  CDmeImage *v4; // edi
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v6; // ecx

  CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 1, bDiscardContents: true);
  v4 = (CDmeImage *)LODWORD(pSrcImage);
  CDmeImage::SetFloatBitmapStorageMode(this: (CDmeImage *)LODWORD(pSrcImage), bFloatBitmap: 1, bDiscardContents: false);
  FloatBitMap_t::DownsampleNiceFiltered(
    this: &v4->m_ComputeBits,
    downsampleInfo: info,
    pDestBitmap: &this->m_ComputeBits);
  m_pAttribute = this->m_nFormat.m_pAttribute;
  pSrcImage = *(float *)&v4->m_nFormat.m_Storage;
  CDmAttribute::SetValue<int>(this: m_pAttribute, value: (const int *)&pSrcImage);
  v6 = this->m_flGamma.m_pAttribute;
  pSrcImage = v4->m_flGamma.m_Storage;
  CDmAttribute::SetValue<float>(this: v6, value: &pSrcImage);
}

//------------------------------------------------------------------------------
// Address: 0x004BBC60
// Name: public: virtual void CDmeImage::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::OnAttributeChanged(CDmeImage *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_Bits.m_pAttribute
    && !this->m_bIgnoreChangedBitsAttribute
    && this->m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
  {
    CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 0, bDiscardContents: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BBC90
// Name: public: virtual void CDmeImage::OnElementUnserialized(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::OnElementUnserialized(CDmeImage *this)
{
  if ( this->m_Mode != DMEIMAGE_STORAGE_ATTRIBUTE )
    CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 0, bDiscardContents: true);
}

//------------------------------------------------------------------------------
// Address: 0x004BBCB0
// Name: public: virtual void CDmeImage::OnElementSerialized(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::OnElementSerialized(CDmeImage *this)
{
  if ( this->m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 0, bDiscardContents: false);
}

//------------------------------------------------------------------------------
// Address: 0x004BBCD0
// Name: public: void CDmeImage::Init(int,int,int,enum ImageFormat,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::Init(CDmeImage *this, int nWidth, int nHeight, int nDepth, ImageFormat fmt, float flGamma)
{
  CUtlString v7; // [esp+4h] [ebp-10h] BYREF

  if ( this->m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    CSOAContainer::~CSOAContainer(this: &this->m_ComputeBits);
  CUtlString::CUtlString(this: &v7, pMemory: nullptr, nSizeInBytes: 0);
  CDmAttribute::SetValue<CUtlBinaryBlock>(this: this->m_Bits.m_pAttribute, value: &v7.m_Storage);
  v7.m_Storage.m_nActualLength = 0;
  if ( v7.m_Storage.m_Memory.m_nGrowSize >= 0 && v7.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7.m_Storage.m_Memory.m_pMemory);
  CDmAttribute::SetValue<int>(this: this->m_nWidth.m_pAttribute, value: &nWidth);
  CDmAttribute::SetValue<int>(this: this->m_nHeight.m_pAttribute, value: &nHeight);
  CDmAttribute::SetValue<int>(this: this->m_nDepth.m_pAttribute, value: &nDepth);
  CDmAttribute::SetValue<int>(this: this->m_nFormat.m_pAttribute, value: (const int *)&fmt);
  CDmAttribute::SetValue<float>(this: this->m_flGamma.m_pAttribute, value: &flGamma);
  this->m_Mode = DMEIMAGE_STORAGE_NONE;
}

//------------------------------------------------------------------------------
// Address: 0x004BBD80
// Name: public: void CDmeImage::SetImageBits(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::SetImageBits(CDmeImage *this, const void *pBits, int nSize)
{
  CUtlString v4; // [esp+4h] [ebp-10h] BYREF

  CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 0, bDiscardContents: true);
  CUtlString::CUtlString(this: &v4, pMemory: pBits, nSizeInBytes: nSize);
  CDmAttribute::SetValue<CUtlBinaryBlock>(this: this->m_Bits.m_pAttribute, value: &v4.m_Storage);
  v4.m_Storage.m_nActualLength = 0;
  if ( v4.m_Storage.m_Memory.m_nGrowSize >= 0 && v4.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004BBDE0
// Name: public: class CDmeImage __near * CDmeImageArray::GetImage(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeImage *__thiscall CDmeImageArray::GetImage(CDmeImageArray *this, int nIndex)
{
  int v2; // eax
  int v3; // esi

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Images.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeImage::m_classType.u) != 0 )
  {
    return (CDmeImage *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BBE30
// Name: public: bool CDmeImageArray::IsConsistent(int,int,int,enum ImageFormat)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeImageArray::IsConsistent(
        CDmeImageArray *this,
        int nWidth,
        int nHeight,
        int nDepth,
        ImageFormat fmt)
{
  bool result; // al
  int v6; // eax
  _DWORD *v7; // esi
  int v8; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // esi

  if ( this->m_Images.m_Storage.m_Size == 0 )
    return true;
  v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: *this->m_Images.m_Storage.m_Memory.m_pMemory);
  v7 = (_DWORD *)v6;
  if ( v6 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
         a1: v6,
         a2: CDmeImage::m_classType.u) == 0 )
  {
    v7 = nullptr;
  }
  v8 = v7[33];
  if ( v8 == 1 )
    v9 = v7[35];
  else
    v9 = v7[17];
  result = false;
  if ( nWidth == v9 )
  {
    v10 = v8 == 1 ? v7[36] : v7[19];
    if ( nHeight == v10 && fmt == v7[23] )
    {
      v11 = v8 == 1 ? v7[37] : v7[21];
      if ( nDepth == v11 )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BBEE0
// Name: public: void CDmeImageArray::AddImage(class CDmeImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImageArray::AddImage(CDmeImageArray *this, CExpressionCalculator *pImage)
{
  CExpressionCalculator *v2; // esi
  CDmeImage::StorageMode_t m_pElements; // eax
  int m_Size; // edx
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax

  v2 = pImage;
  m_pElements = (CDmeImage::StorageMode_t)pImage[1].m_varValues.m_pElements;
  if ( m_pElements == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    m_Size = pImage[1].m_stack.m_Size;
  else
    m_Size = pImage[1].m_expr.m_Storage.m_Memory.m_nAllocationCount;
  if ( m_pElements == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    m_nGrowSize = pImage[1].m_stack.m_Memory.m_nGrowSize;
  else
    m_nGrowSize = *(_DWORD *)&pImage->m_bIsBuildingArgumentList;
  if ( m_pElements == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    m_nAllocationCount = pImage[1].m_stack.m_Memory.m_nAllocationCount;
  else
    m_nAllocationCount = pImage->m_stack.m_Size;
  if ( CDmeImageArray::IsConsistent(
         this,
         nWidth: m_nAllocationCount,
         nHeight: m_nGrowSize,
         nDepth: m_Size,
         fmt: (ImageFormat)pImage[1].m_expr.m_Storage.m_nActualLength) )
  {
    pImage = (CExpressionCalculator *)CCodecBuffer_Block::GetBufferType(this: v2);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Images,
      src: (const DmElementHandle_t *)&pImage);
  }
  else
  {
    _Warning(a1: "Attempted to add different size/format images to the image array!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BBF70
// Name: public: class CDmeImage __near * CDmeImageArray::AddImage(void)
// Source: json
//------------------------------------------------------------------------------
CDmeImage *__thiscall CDmeImageArray::AddImage(CDmeImageArray *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  float *v5; // edi
  float *v6; // eax
  int v7; // ecx
  float flGamma; // xmm0_4
  ImageFormat v9; // esi
  int v10; // edi
  int v11; // edx
  int v12; // eax
  CDmeImage *pImage; // [esp+2Ch] [ebp-4h]

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeImage::m_classType.u,
         a3: "image",
         a4: this->m_fileId,
         a5: 0);
  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v2);
  if ( v3 == 0
    || (pImage = (CDmeImage *)v3,
        (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
          a1: v3,
          a2: CDmeImage::m_classType.u) == 0) )
  {
    pImage = nullptr;
  }
  if ( this->m_Images.m_Storage.m_Size > 0 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: *this->m_Images.m_Storage.m_Memory.m_pMemory);
    v5 = (float *)v4;
    if ( v4 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeImage::m_classType.u) != 0 )
    {
      v6 = v5;
    }
    else
    {
      v6 = nullptr;
    }
    v7 = *((_DWORD *)v6 + 33);
    flGamma = v6[25];
    v9 = *((_DWORD *)v6 + 23);
    if ( v7 == 1 )
      v10 = *((_DWORD *)v6 + 37);
    else
      v10 = *((_DWORD *)v6 + 21);
    if ( v7 == 1 )
      v11 = *((_DWORD *)v6 + 36);
    else
      v11 = *((_DWORD *)v6 + 19);
    if ( v7 == 1 )
      v12 = *((_DWORD *)v6 + 35);
    else
      v12 = *((_DWORD *)v6 + 17);
    CDmeImage::Init(this: pImage, nWidth: v12, nHeight: v11, nDepth: v10, fmt: v9, flGamma);
  }
  CDmeImageArray::AddImage(this, (CExpressionCalculator *)pImage);
  return pImage;
}

//------------------------------------------------------------------------------
// Address: 0x004BC080
// Name: public: int CDmeImageArray::Width(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImageArray::Width(CDmeImageArray *this)
{
  int v1; // eax
  _DWORD *v2; // esi

  if ( this->m_Images.m_Storage.m_Size <= 0 )
    return -1;
  v1 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: *this->m_Images.m_Storage.m_Memory.m_pMemory);
  v2 = (_DWORD *)v1;
  if ( v1 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v1 + 16))(
         a1: v1,
         a2: CDmeImage::m_classType.u) == 0 )
  {
    v2 = nullptr;
  }
  if ( v2[33] == 1 )
    return v2[35];
  else
    return v2[17];
}

//------------------------------------------------------------------------------
// Address: 0x004BC0E0
// Name: public: int CDmeImageArray::Height(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImageArray::Height(CDmeImageArray *this)
{
  int v1; // eax
  _DWORD *v2; // esi

  if ( this->m_Images.m_Storage.m_Size <= 0 )
    return -1;
  v1 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: *this->m_Images.m_Storage.m_Memory.m_pMemory);
  v2 = (_DWORD *)v1;
  if ( v1 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v1 + 16))(
         a1: v1,
         a2: CDmeImage::m_classType.u) == 0 )
  {
    v2 = nullptr;
  }
  if ( v2[33] == 1 )
    return v2[36];
  else
    return v2[19];
}

//------------------------------------------------------------------------------
// Address: 0x004BC140
// Name: public: int CDmeImageArray::Depth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImageArray::Depth(CDmeImageArray *this)
{
  int v1; // eax
  _DWORD *v2; // esi

  if ( this->m_Images.m_Storage.m_Size <= 0 )
    return -1;
  v1 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: *this->m_Images.m_Storage.m_Memory.m_pMemory);
  v2 = (_DWORD *)v1;
  if ( v1 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v1 + 16))(
         a1: v1,
         a2: CDmeImage::m_classType.u) == 0 )
  {
    v2 = nullptr;
  }
  if ( v2[33] == 1 )
    return v2[37];
  else
    return v2[21];
}

//------------------------------------------------------------------------------
// Address: 0x004BC1A0
// Name: public: void CDmeImage::CopyFrom(class CDmeImage __near *,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::CopyFrom(CDmeImage *this, CDmeImage *pSrcImage, ImageFormat fmt)
{
  ImageFormat m_Storage; // ebx
  CDmeImage::StorageMode_t m_Mode; // eax
  int m_nSlices; // edx
  int m_nRows; // ecx
  int m_nColumns; // eax
  CDmeImage::StorageMode_t v10; // eax
  ImageFormat v11; // eax
  ImageFormat v12; // edx
  int MemRequired; // ebx
  CDmeImage::StorageMode_t v14; // eax
  int v15; // ebx
  int v16; // ecx
  int v17; // eax
  int v18; // ebx
  CDmAttribute *m_pAttribute; // ecx
  CDmeImage::StorageMode_t v20; // eax
  int v21; // ebx
  ImageFormat srcImageFormat; // [esp+10h] [ebp-Ch]
  ImageFormat dstImageFormat; // [esp+14h] [ebp-8h]
  CUtlBinaryBlock *bits; // [esp+18h] [ebp-4h]
  unsigned __int8 *bitsa; // [esp+18h] [ebp-4h]
  CDmeImage *pSrcImagea; // [esp+24h] [ebp+8h]
  ImageFormat fmta; // [esp+28h] [ebp+Ch]

  m_Storage = fmt;
  if ( fmt == IMAGE_FORMAT_UNKNOWN )
    m_Storage = pSrcImage->m_nFormat.m_Storage;
  m_Mode = pSrcImage->m_Mode;
  if ( m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    m_nSlices = pSrcImage->m_ComputeBits.m_nSlices;
  else
    m_nSlices = pSrcImage->m_nDepth.m_Storage;
  if ( m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    m_nRows = pSrcImage->m_ComputeBits.m_nRows;
  else
    m_nRows = pSrcImage->m_nHeight.m_Storage;
  if ( m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    m_nColumns = pSrcImage->m_ComputeBits.m_nColumns;
  else
    m_nColumns = pSrcImage->m_nWidth.m_Storage;
  CDmeImage::Init(
    this,
    nWidth: m_nColumns,
    nHeight: m_nRows,
    nDepth: m_nSlices,
    fmt: m_Storage,
    flGamma: pSrcImage->m_flGamma.m_Storage);
  v10 = pSrcImage->m_Mode;
  if ( v10 != DMEIMAGE_STORAGE_NONE )
  {
    if ( v10 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    {
      CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 1, bDiscardContents: true);
      CDmeImage::SetFloatBitmapStorageMode(this: pSrcImage, bFloatBitmap: 1, bDiscardContents: false);
      FloatBitMap_t::LoadFromFloatBitmap(this: &this->m_ComputeBits, pOrig: &pSrcImage->m_ComputeBits);
    }
    else
    {
      v11 = pSrcImage->m_nFormat.m_Storage;
      v12 = this->m_nFormat.m_Storage;
      if ( v11 == v12 )
      {
        MemRequired = ImageLoader::GetMemRequired(
                        width: pSrcImage->m_nWidth.m_Storage,
                        height: pSrcImage->m_nHeight.m_Storage,
                        depth: pSrcImage->m_nDepth.m_Storage,
                        imageFormat: v11,
                        mipmap: false,
                        pAdjustedHeight: nullptr);
        CDmeImage::SetFloatBitmapStorageMode(this: pSrcImage, bFloatBitmap: 0, bDiscardContents: false);
        CDmeImage::SetImageBits(this, pBits: pSrcImage->m_Bits.m_Storage.m_Memory.m_pMemory, nSize: MemRequired);
      }
      else
      {
        v14 = this->m_Mode;
        if ( v14 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
          v15 = this->m_ComputeBits.m_nSlices;
        else
          v15 = this->m_nDepth.m_Storage;
        if ( v14 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
          v16 = this->m_ComputeBits.m_nRows;
        else
          v16 = this->m_nHeight.m_Storage;
        if ( v14 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
          v17 = this->m_ComputeBits.m_nColumns;
        else
          v17 = this->m_nWidth.m_Storage;
        v18 = ImageLoader::GetMemRequired(
                width: v17,
                height: v16,
                depth: v15,
                nMipmapCount: 1,
                imageFormat: v12,
                pAdjustedHeight: nullptr);
        CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 0, bDiscardContents: false);
        m_pAttribute = this->m_Bits.m_pAttribute;
        this->m_bInModification = true;
        bits = CDmAttribute::BeginModifyValueInPlace<CUtlBinaryBlock>(this: m_pAttribute, pHandle: &this->m_hModify);
        CUtlBinaryBlock::SetLength(this: bits, nLength: v18);
        v20 = this->m_Mode;
        if ( v20 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
          fmta = this->m_ComputeBits.m_nRows;
        else
          fmta = this->m_nHeight.m_Storage;
        if ( v20 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
          v21 = this->m_ComputeBits.m_nSlices;
        else
          v21 = this->m_nDepth.m_Storage;
        if ( v20 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
          pSrcImagea = (CDmeImage *)this->m_ComputeBits.m_nColumns;
        else
          pSrcImagea = (CDmeImage *)this->m_nWidth.m_Storage;
        dstImageFormat = this->m_nFormat.m_Storage;
        bitsa = bits->m_Memory.m_pMemory;
        srcImageFormat = pSrcImage->m_nFormat.m_Storage;
        CDmeImage::SetFloatBitmapStorageMode(this: pSrcImage, bFloatBitmap: 0, bDiscardContents: false);
        ImageLoader::ConvertImageFormat(
          src: pSrcImage->m_Bits.m_Storage.m_Memory.m_pMemory,
          srcImageFormat,
          dst: bitsa,
          dstImageFormat,
          width: (int)pSrcImagea,
          height: fmta * v21,
          srcStride: 0,
          dstStride: 0);
        CDmeImage::EndModification(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BC400
// Name: protected: CDmeImage::CDmeImage(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeImage *__thiscall CDmeImage::CDmeImage(
        CDmeImage *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeImage_vtbl *)&CDmeImage::`vftable';
  this->m_nWidth.m_pAttribute = nullptr;
  this->m_nWidth.m_Storage = 0;
  this->m_nHeight.m_pAttribute = nullptr;
  this->m_nHeight.m_Storage = 0;
  this->m_nDepth.m_pAttribute = nullptr;
  this->m_nDepth.m_Storage = 0;
  this->m_nFormat.m_pAttribute = nullptr;
  this->m_nFormat.m_Storage = 0;
  this->m_flGamma = 0;
  CUtlBinaryBlock::CUtlBinaryBlock(this: &this->m_Bits.m_Storage, growSize: 0, initSize: 0);
  this->m_Bits.m_pAttribute = nullptr;
  CUtlBinaryBlock::Set(this: &this->m_Bits.m_Storage, pValue: nullptr, nLen: 0);
  memset(
    dst: (unsigned __int8 *)this->m_ComputeBits.m_nDataType,
    value: 0xFFu,
    count: sizeof(this->m_ComputeBits.m_nDataType));
  memset(
    dst: (unsigned __int8 *)this->m_ComputeBits.m_pSeparateDataMemory,
    value: 0,
    count: sizeof(this->m_ComputeBits.m_pSeparateDataMemory));
  this->m_ComputeBits.m_pConstantDataMemory = nullptr;
  this->m_ComputeBits.m_pDataMemory = nullptr;
  this->m_ComputeBits.m_nNumQuadsPerRow = 0;
  this->m_ComputeBits.m_nSlices = 0;
  this->m_ComputeBits.m_nRows = 0;
  this->m_ComputeBits.m_nPaddedColumns = 0;
  this->m_ComputeBits.m_nColumns = 0;
  this->m_ComputeBits.m_nFieldPresentMask = 0;
  this->m_ComputeBits.m_eThreadMode = SOATHREADMODE_NONE;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004BC4D0
// Name: public: virtual bool CDmeImage::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeImage::IsA(CDmeImage *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeImage::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BC500
// Name: public: virtual int CDmeImage::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImage::GetInheritanceDepth(CDmeImage *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeImage::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BC540
// Name: protected: virtual int CDmeImage::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImage::AllocatedSize(CDmeImage *this)
{
  return 944;
}

//------------------------------------------------------------------------------
// Address: 0x004BC550
// Name: protected: virtual void CDmeImage::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::PerformConstruction(CDmeImage *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeImage::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004BC670
// Name: public: virtual bool CDmeImageArray::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeImageArray::IsA(CDmeImageArray *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeImageArray::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BC6A0
// Name: public: virtual int CDmeImageArray::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImageArray::GetInheritanceDepth(CDmeImageArray *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeImageArray::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BC6E0
// Name: protected: virtual void CDmeImageArray::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImageArray::PerformConstruction(CDmeImageArray *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_Images.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "images",
                                  type: AT_FIRST_ARRAY_TYPE,
                                  pMemory: &this->m_Images);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Images.m_pAttribute, typeSymbol: CDmeImage::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x006AC250
// Name: _dynamic_initializer_for__CDmeImage::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeImage::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeImage::s_Allocator,
    blockSize: 944,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeImage pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeImage::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC2B0
// Name: _dynamic_initializer_for__CDmeImageArray::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeImageArray::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeImageArray::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeImageArray pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeImageArray::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B39C0
// Name: _dynamic_atexit_destructor_for__CDmeImage::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeImage::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeImage::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B39D0
// Name: _dynamic_atexit_destructor_for__CDmeImageArray::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeImageArray::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeImageArray::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AC280
// Name: _dynamic_initializer_for__g_CDmeImage_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeImage_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeImage_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC290
// Name: _dynamic_initializer_for__g_CDmeImage_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeImage_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeImage_Helper,
           classname: "DmeImage",
           pFactory: &g_CDmeImage_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006AC2E0
// Name: _dynamic_initializer_for__g_CDmeImageArray_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeImageArray_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeImageArray_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC2F0
// Name: _dynamic_initializer_for__g_CDmeImageArray_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeImageArray_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeImageArray_Helper,
           classname: "DmeImageArray",
           pFactory: &g_CDmeImageArray_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006B39E0
// Name: _dynamic_atexit_destructor_for__g_CDmeImageArray_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeImageArray_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeImageArray_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B39F0
// Name: _dynamic_atexit_destructor_for__g_CDmeImage_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeImage_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeImage_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x0042D3B0
// Name: protected: virtual void CDmeImage::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDmeImage::PerformDestruction(vgui::ListViewPanel *this)
{
  CSteamApplication::PostShutdown((CFontManager *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0042E0F0
// Name: protected: virtual int CDmeImageArray::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImageArray::AllocatedSize(CDmeTextureFrame *this)
{
  return 96;
}

//------------------------------------------------------------------------------
// Address: 0x0042E380
// Name: int ImageLoader::SizeInBytes(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ImageLoader::SizeInBytes(ImageFormat fmt)
{
  return ImageLoader::ImageFormatInfo(fmt)->m_nNumBytes;
}

//------------------------------------------------------------------------------
// Address: 0x0042E3A0
// Name: protected: void CDmeImage::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::OnConstruction(CDmeImage *this)
{
  CDmaVar<int> *p_m_nWidth; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax

  p_m_nWidth = &this->m_nWidth;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "width", type: AT_INT, pMemory: &this->m_nWidth);
  p_m_nWidth->m_pAttribute = v3;
  v3->m_nFlags |= 0x8000u;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "height", type: AT_INT, pMemory: &this->m_nHeight);
  this->m_nHeight.m_pAttribute = v4;
  v4->m_nFlags |= 0x8000u;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "depth", type: AT_INT, pMemory: &this->m_nDepth);
  this->m_nDepth.m_pAttribute = v5;
  v5->m_nFlags |= 0x8000u;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "format", type: AT_INT, pMemory: &this->m_nFormat);
  this->m_nFormat.m_pAttribute = v6;
  v6->m_nFlags |= 0x8000u;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "gamma", type: AT_FLOAT, pMemory: &this->m_flGamma);
  this->m_flGamma.m_pAttribute = v7;
  v7->m_nFlags |= 0x8000u;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "bits", type: AT_VOID, pMemory: &this->m_Bits);
  this->m_Bits.m_pAttribute = v8;
  v8->m_nFlags |= 0x8100u;
  this->m_Mode = DMEIMAGE_STORAGE_NONE;
  this->m_bInModification = false;
  this->m_bInFloatBitmapModification = false;
  this->m_bIgnoreChangedBitsAttribute = false;
  this->m_hModify = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0042E470
// Name: public: class CUtlBinaryBlock __near & CDmeImage::BeginModification(void)
// Source: json
//------------------------------------------------------------------------------
CUtlBinaryBlock *__thiscall CDmeImage::BeginModification(CDmeImage *this)
{
  CDmAttribute *m_pAttribute; // ecx

  CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: false, bDiscardContents: false);
  m_pAttribute = this->m_Bits.m_pAttribute;
  this->m_bInModification = true;
  return (CUtlBinaryBlock *)CDmAttribute::BeginModifyValueInPlace<CUtlBinaryBlock>(
                              pAttribute: m_pAttribute,
                              a2: (int)&this->m_hModify);
}

//------------------------------------------------------------------------------
// Address: 0x0042E4A0
// Name: public: void CDmeImage::EndModification(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::EndModification(CDmeImage *this)
{
  void *m_hModify; // [esp-4h] [ebp-8h]

  m_hModify = this->m_hModify;
  this->m_bInModification = false;
  this->m_bIgnoreChangedBitsAttribute = true;
  CDmAttribute::EndModifyValueInPlace<CUtlBinaryBlock>(a1: m_hModify);
  this->m_bIgnoreChangedBitsAttribute = false;
  this->m_hModify = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0042E4E0
// Name: public: int CDmeImage::SizeInBytes(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImage::SizeInBytes(CDmeImage *this)
{
  return ImageLoader::GetMemRequired(
           width: this->m_nWidth.m_Storage,
           height: this->m_nHeight.m_Storage,
           depth: this->m_nDepth.m_Storage,
           imageFormat: (ImageFormat)this->m_nFormat.m_Storage,
           mipmap: false,
           pAdjustedHeight: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0042E500
// Name: public: void CDmeImage::SetFloatBitmapStorageMode(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::SetFloatBitmapStorageMode(CDmeImage *this, int bFloatBitmap, bool bDiscardContents)
{
  CDmeImage::StorageMode_t m_Mode; // ebx
  CDmeImage::StorageMode_t v5; // eax
  __int32 v6; // eax
  int m_nColumns; // eax
  CDmAttribute *v8; // ecx
  CDmAttribute *v9; // ecx
  CUtlBinaryBlock *v10; // edi
  int v11; // eax
  CDmAttribute *m_pAttribute; // ecx
  CUtlBinaryBlock *v13; // edi
  int MemRequired; // eax
  const ImageFormatInfo_t *v15; // eax
  char v16; // cl
  int value; // [esp+10h] [ebp-8h] BYREF
  int m_nSlices; // [esp+14h] [ebp-4h] BYREF

  m_Mode = this->m_Mode;
  v5 = 2 - ((_BYTE)bFloatBitmap != 0);
  if ( v5 != m_Mode )
  {
    this->m_Mode = v5;
    v6 = v5 - 1;
    if ( v6 != 0 )
    {
      if ( v6 == 1 )
      {
        if ( bDiscardContents || m_Mode != DMEIMAGE_STORAGE_FLOAT_BITMAP )
        {
          CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: false, bDiscardContents: false);
          m_pAttribute = this->m_Bits.m_pAttribute;
          this->m_bInModification = true;
          v13 = (CUtlBinaryBlock *)CDmAttribute::BeginModifyValueInPlace<CUtlBinaryBlock>(
                                     pAttribute: m_pAttribute,
                                     a2: (int)&this->m_hModify);
          MemRequired = ImageLoader::GetMemRequired(
                          width: this->m_nWidth.m_Storage,
                          height: this->m_nHeight.m_Storage,
                          depth: this->m_nDepth.m_Storage,
                          imageFormat: (ImageFormat)this->m_nFormat.m_Storage,
                          mipmap: false,
                          pAdjustedHeight: nullptr);
          CUtlBinaryBlock::SetLength(this: v13, nLength: MemRequired);
        }
        else
        {
          m_nColumns = this->m_ComputeBits.m_nColumns;
          v8 = this->m_nWidth.m_pAttribute;
          bFloatBitmap = m_nColumns;
          CDmAttribute::SetValue<int>(this: v8, value: &bFloatBitmap);
          v9 = this->m_nHeight.m_pAttribute;
          value = this->m_ComputeBits.m_nRows;
          CDmAttribute::SetValue<int>(this: v9, &value);
          m_nSlices = this->m_ComputeBits.m_nSlices;
          CDmAttribute::SetValue<int>(this: this->m_nDepth.m_pAttribute, value: &m_nSlices);
          v10 = CDmeImage::BeginModification(this);
          v11 = CDmeImage::SizeInBytes(this);
          CUtlBinaryBlock::SetLength(this: v10, nLength: v11);
          FloatBitMap_t::WriteToBuffer(
            this: &this->m_ComputeBits,
            pBuffer: v10->m_Memory.m_pMemory,
            nBufSize: v10->m_nActualLength,
            fmt: (ImageFormat)this->m_nFormat.m_Storage,
            flGamma: this->m_flGamma.m_Storage);
        }
        CDmeImage::EndModification(this);
        CSOAContainer::~CSOAContainer(this: &this->m_ComputeBits);
      }
    }
    else
    {
      v15 = ImageLoader::ImageFormatInfo(fmt: (ImageFormat)this->m_nFormat.m_Storage);
      v16 = v15->m_nNumRedBits != 0;
      if ( v15->m_nNumGreenBits != 0 )
        v16 |= 2u;
      if ( v15->m_nNumBlueBits != 0 )
        v16 |= 4u;
      if ( v15->m_nNumAlphaBits != 0 )
        v16 |= 8u;
      FloatBitMap_t::Init(
        this: &this->m_ComputeBits,
        nXSize: this->m_nWidth.m_Storage,
        nYSize: this->m_nHeight.m_Storage,
        nZSize: this->m_nDepth.m_Storage,
        nAttributeMask: v16);
      if ( !bDiscardContents && m_Mode == DMEIMAGE_STORAGE_ATTRIBUTE )
        FloatBitMap_t::LoadFromBuffer(
          this: &this->m_ComputeBits,
          pBuffer: this->m_Bits.m_Storage.m_Memory.m_pMemory,
          nBufSize: this->m_Bits.m_Storage.m_nActualLength,
          fmt: (ImageFormat)this->m_nFormat.m_Storage,
          flGamma: this->m_flGamma.m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042E6B0
// Name: public: void CDmeImage::QuarterSize(class CDmeImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::QuarterSize(CDmeImage *this, float pSrcImage)
{
  CDmeImage *v3; // edi
  CDmAttribute *m_pAttribute; // ecx

  CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 1, bDiscardContents: true);
  v3 = (CDmeImage *)LODWORD(pSrcImage);
  CDmeImage::SetFloatBitmapStorageMode(this: (CDmeImage *)LODWORD(pSrcImage), bFloatBitmap: 1, bDiscardContents: false);
  FloatBitMap_t::QuarterSize(this: &v3->m_ComputeBits, pBitmap: &this->m_ComputeBits);
  pSrcImage = *(float *)&v3->m_nFormat.m_Storage;
  CDmAttribute::SetValue<int>(this: this->m_nFormat.m_pAttribute, value: (const int *)&pSrcImage);
  m_pAttribute = this->m_flGamma.m_pAttribute;
  pSrcImage = v3->m_flGamma.m_Storage;
  CDmAttribute::SetValue<float>(this: m_pAttribute, value: &pSrcImage);
}

//------------------------------------------------------------------------------
// Address: 0x0042E710
// Name: public: void CDmeImage::DownsampleNiceFiltered(struct DownsampleInfo_t const __near &,class CDmeImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::DownsampleNiceFiltered(CDmeImage *this, const DownsampleInfo_t *info, float pSrcImage)
{
  CDmeImage *v4; // edi
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v6; // ecx

  CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 1, bDiscardContents: true);
  v4 = (CDmeImage *)LODWORD(pSrcImage);
  CDmeImage::SetFloatBitmapStorageMode(this: (CDmeImage *)LODWORD(pSrcImage), bFloatBitmap: 1, bDiscardContents: false);
  FloatBitMap_t::DownsampleNiceFiltered(
    this: &v4->m_ComputeBits,
    downsampleInfo: info,
    pDestBitmap: &this->m_ComputeBits);
  m_pAttribute = this->m_nFormat.m_pAttribute;
  pSrcImage = *(float *)&v4->m_nFormat.m_Storage;
  CDmAttribute::SetValue<int>(this: m_pAttribute, value: (const int *)&pSrcImage);
  v6 = this->m_flGamma.m_pAttribute;
  pSrcImage = v4->m_flGamma.m_Storage;
  CDmAttribute::SetValue<float>(this: v6, value: &pSrcImage);
}

//------------------------------------------------------------------------------
// Address: 0x0042E780
// Name: public: void CDmaBinaryBlock::Set(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmaBinaryBlock::Set(CDmaBinaryBlock *this, const void *pValue, int nLen)
{
  CUtlBinaryBlock block; // [esp+0h] [ebp-14h] BYREF
  int v5; // [esp+10h] [ebp-4h]

  CUtlBinaryBlock::CUtlBinaryBlock(
    this: (CUtlBinaryBlock *)&block.m_Memory.m_nAllocationCount,
    pMemory: pValue,
    nSizeInBytes: nLen);
  CDmAttribute::SetValue<CUtlBinaryBlock>(
    this: this->m_pAttribute,
    value: (const CUtlBinaryBlock *)&block.m_Memory.m_nAllocationCount);
  v5 = 0;
  if ( block.m_nActualLength >= 0 && block.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)block.m_Memory.m_nAllocationCount);
}

//------------------------------------------------------------------------------
// Address: 0x0042E7E0
// Name: public: virtual void CDmeImage::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::OnAttributeChanged(CDmeImage *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_Bits.m_pAttribute
    && !this->m_bIgnoreChangedBitsAttribute
    && this->m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
  {
    CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 0, bDiscardContents: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042E810
// Name: public: virtual void CDmeImage::OnElementUnserialized(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::OnElementUnserialized(CDmeImage *this)
{
  if ( this->m_Mode != DMEIMAGE_STORAGE_ATTRIBUTE )
    CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 0, bDiscardContents: true);
}

//------------------------------------------------------------------------------
// Address: 0x0042E830
// Name: public: virtual void CDmeImage::OnElementSerialized(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::OnElementSerialized(CDmeImage *this)
{
  if ( this->m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 0, bDiscardContents: false);
}

//------------------------------------------------------------------------------
// Address: 0x0042E850
// Name: public: void CDmeImage::Init(int,int,int,enum ImageFormat,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::Init(CDmeImage *this, int nWidth, int nHeight, int nDepth, ImageFormat fmt, float flGamma)
{
  CUtlBinaryBlock value; // [esp+4h] [ebp-10h] BYREF

  if ( this->m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    CSOAContainer::~CSOAContainer(this: &this->m_ComputeBits);
  CUtlBinaryBlock::CUtlBinaryBlock(this: &value, pMemory: nullptr, nSizeInBytes: 0);
  CDmAttribute::SetValue<CUtlBinaryBlock>(this: this->m_Bits.m_pAttribute, &value);
  value.m_nActualLength = 0;
  if ( value.m_Memory.m_nGrowSize >= 0 && value.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: value.m_Memory.m_pMemory);
  CDmAttribute::SetValue<int>(this: this->m_nWidth.m_pAttribute, value: &nWidth);
  CDmAttribute::SetValue<int>(this: this->m_nHeight.m_pAttribute, value: &nHeight);
  CDmAttribute::SetValue<int>(this: this->m_nDepth.m_pAttribute, value: &nDepth);
  CDmAttribute::SetValue<int>(this: this->m_nFormat.m_pAttribute, value: (const int *)&fmt);
  CDmAttribute::SetValue<float>(this: this->m_flGamma.m_pAttribute, value: &flGamma);
  this->m_Mode = DMEIMAGE_STORAGE_NONE;
}

//------------------------------------------------------------------------------
// Address: 0x0042E910
// Name: public: class CDmeImage __near * CDmeImageArray::GetImage(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeImage *__thiscall CDmeImageArray::GetImage(CDmeImageArray *this, int nIndex)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Images.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeImage::m_classType) )
    return (CDmeImage *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0042E960
// Name: public: bool CDmeImageArray::IsConsistent(int,int,int,enum ImageFormat)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeImageArray::IsConsistent(
        CDmeImageArray *this,
        CDmElement_vtbl *nWidth,
        int nHeight,
        int nDepth,
        CDmAttribute *fmt)
{
  bool result; // al
  CDmElement *v6; // eax
  CDmElement *v7; // esi
  int v8; // ecx
  CDmElement_vtbl *v9; // eax
  int v10; // eax
  int v11; // esi

  if ( this->m_Images.m_Storage.m_Size == 0 )
    return true;
  v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Images.m_Storage.m_Memory.m_pMemory);
  v7 = v6;
  if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeImage::m_classType) )
    v7 = nullptr;
  v8 = *((_DWORD *)&v7[1] + 16);
  if ( v8 == 1 )
    v9 = *(CDmElement_vtbl **)v7[2].m_Id.m_Value;
  else
    v9 = v7[1].__vftable;
  result = false;
  if ( nWidth == v9 )
  {
    v10 = v8 == 1 ? *(_DWORD *)&v7[2].m_Id.m_Value[4] : *(_DWORD *)&v7[1].m_Id.m_Value[4];
    if ( nHeight == v10 && fmt == v7[1].m_Name.m_pAttribute )
    {
      v11 = v8 == 1 ? *(_DWORD *)&v7[2].m_Id.m_Value[8] : *(_DWORD *)&v7[1].m_Id.m_Value[12];
      if ( nDepth == v11 )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042EA00
// Name: public: void CDmeImageArray::AddImage(class CDmeImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImageArray::AddImage(CDmeImageArray *this, CDmeImage *pImage)
{
  CVTFTexture *v2; // esi
  CDmeImage::StorageMode_t m_Mode; // eax
  int m_nSlices; // edx
  int m_nRows; // ecx
  CDmElement_vtbl *m_nColumns; // eax

  v2 = (CVTFTexture *)pImage;
  m_Mode = pImage->m_Mode;
  if ( m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    m_nSlices = pImage->m_ComputeBits.m_nSlices;
  else
    m_nSlices = pImage->m_nDepth.m_Storage;
  if ( m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    m_nRows = pImage->m_ComputeBits.m_nRows;
  else
    m_nRows = pImage->m_nHeight.m_Storage;
  if ( m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    m_nColumns = (CDmElement_vtbl *)pImage->m_ComputeBits.m_nColumns;
  else
    m_nColumns = (CDmElement_vtbl *)pImage->m_nWidth.m_Storage;
  if ( CDmeImageArray::IsConsistent(
         this,
         nWidth: m_nColumns,
         nHeight: m_nRows,
         nDepth: m_nSlices,
         fmt: (CDmAttribute *)pImage->m_nFormat.m_Storage) )
  {
    pImage = (CDmeImage *)CVTFTexture::MipCount(this: v2);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Images,
      src: (const DmElementHandle_t *)&pImage);
  }
  else
  {
    _Warning(a1: "Attempted to add different size/format images to the image array!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042EA90
// Name: public: class CDmeImage __near * CDmeImageArray::AddImage(void)
// Source: json
//------------------------------------------------------------------------------
CDmeImage *__thiscall CDmeImageArray::AddImage(CDmeImageArray *this)
{
  CDmeImage *v2; // ebp
  CDmElement *v3; // eax
  CDmElement *v4; // esi
  float *v5; // eax
  int v6; // ecx
  ImageFormat v7; // ebx
  int v8; // esi
  int v9; // edx
  int v10; // eax
  float flGamma; // [esp+18h] [ebp-4h]

  v2 = CreateElement<CDmeImage>(pObjectName: "image", fileid: this->m_fileId, pObjectID: nullptr);
  if ( this->m_Images.m_Storage.m_Size > 0 )
  {
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Images.m_Storage.m_Memory.m_pMemory);
    v4 = v3;
    if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeImage::m_classType) )
      v5 = (float *)v4;
    else
      v5 = nullptr;
    v6 = *((_DWORD *)v5 + 33);
    v7 = *((_DWORD *)v5 + 23);
    flGamma = v5[25];
    if ( v6 == 1 )
      v8 = *((_DWORD *)v5 + 37);
    else
      v8 = *((_DWORD *)v5 + 21);
    if ( v6 == 1 )
      v9 = *((_DWORD *)v5 + 36);
    else
      v9 = *((_DWORD *)v5 + 19);
    if ( v6 == 1 )
      v10 = *((_DWORD *)v5 + 35);
    else
      v10 = *((_DWORD *)v5 + 17);
    CDmeImage::Init(this: v2, nWidth: v10, nHeight: v9, nDepth: v8, fmt: v7, flGamma);
  }
  CDmeImageArray::AddImage(this, pImage: v2);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0042EB60
// Name: public: int CDmeImageArray::Width(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement_vtbl *__thiscall CDmeImageArray::Width(CDmeImageArray *this)
{
  CDmElement *v1; // eax
  CDmElement *v2; // esi

  if ( this->m_Images.m_Storage.m_Size <= 0 )
    return (CDmElement_vtbl *)-1;
  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Images.m_Storage.m_Memory.m_pMemory);
  v2 = v1;
  if ( v1 == nullptr || !v1->IsA(this: v1, a2: CDmeImage::m_classType) )
    v2 = nullptr;
  if ( *((_DWORD *)&v2[1] + 16) == 1 )
    return *(CDmElement_vtbl **)v2[2].m_Id.m_Value;
  else
    return v2[1].__vftable;
}

//------------------------------------------------------------------------------
// Address: 0x0042EBC0
// Name: public: int CDmeImageArray::Height(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImageArray::Height(CDmeImageArray *this)
{
  CDmElement *v1; // eax
  CDmElement *v2; // esi

  if ( this->m_Images.m_Storage.m_Size <= 0 )
    return -1;
  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Images.m_Storage.m_Memory.m_pMemory);
  v2 = v1;
  if ( v1 == nullptr || !v1->IsA(this: v1, a2: CDmeImage::m_classType) )
    v2 = nullptr;
  if ( *((_DWORD *)&v2[1] + 16) == 1 )
    return *(_DWORD *)&v2[2].m_Id.m_Value[4];
  else
    return *(_DWORD *)&v2[1].m_Id.m_Value[4];
}

//------------------------------------------------------------------------------
// Address: 0x0042EC20
// Name: public: int CDmeImageArray::Depth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImageArray::Depth(CDmeImageArray *this)
{
  CDmElement *v1; // eax
  CDmElement *v2; // esi

  if ( this->m_Images.m_Storage.m_Size <= 0 )
    return -1;
  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Images.m_Storage.m_Memory.m_pMemory);
  v2 = v1;
  if ( v1 == nullptr || !v1->IsA(this: v1, a2: CDmeImage::m_classType) )
    v2 = nullptr;
  if ( *((_DWORD *)&v2[1] + 16) == 1 )
    return *(_DWORD *)&v2[2].m_Id.m_Value[8];
  else
    return *(_DWORD *)&v2[1].m_Id.m_Value[12];
}

//------------------------------------------------------------------------------
// Address: 0x0042EC80
// Name: public: void CDmeImage::CopyFrom(class CDmeImage __near *,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::CopyFrom(CDmeImage *this, CDmeImage *pSrcImage, ImageFormat fmt)
{
  ImageFormat m_Storage; // ebx
  CDmeImage::StorageMode_t m_Mode; // eax
  int m_nSlices; // edx
  int m_nRows; // ecx
  int m_nColumns; // eax
  CDmeImage::StorageMode_t v10; // eax
  ImageFormat v11; // eax
  ImageFormat v12; // edx
  int MemRequired; // ebx
  unsigned __int8 *m_pMemory; // edi
  CDmeImage::StorageMode_t v15; // eax
  int v16; // ebx
  int v17; // ecx
  int v18; // eax
  int v19; // ebx
  CDmAttribute *m_pAttribute; // ecx
  CUtlBinaryBlock *v21; // ebp
  CDmeImage::StorageMode_t v22; // eax
  int v23; // ebx
  unsigned __int8 *v24; // ebp
  ImageFormat dstImageFormat; // [esp+10h] [ebp-8h]
  ImageFormat srcImageFormat; // [esp+14h] [ebp-4h]
  CDmeImage *pSrcImagea; // [esp+1Ch] [ebp+4h]
  ImageFormat fmta; // [esp+20h] [ebp+8h]

  m_Storage = fmt;
  if ( fmt == IMAGE_FORMAT_UNKNOWN )
    m_Storage = pSrcImage->m_nFormat.m_Storage;
  m_Mode = pSrcImage->m_Mode;
  if ( m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    m_nSlices = pSrcImage->m_ComputeBits.m_nSlices;
  else
    m_nSlices = pSrcImage->m_nDepth.m_Storage;
  if ( m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    m_nRows = pSrcImage->m_ComputeBits.m_nRows;
  else
    m_nRows = pSrcImage->m_nHeight.m_Storage;
  if ( m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    m_nColumns = pSrcImage->m_ComputeBits.m_nColumns;
  else
    m_nColumns = pSrcImage->m_nWidth.m_Storage;
  CDmeImage::Init(
    this,
    nWidth: m_nColumns,
    nHeight: m_nRows,
    nDepth: m_nSlices,
    fmt: m_Storage,
    flGamma: pSrcImage->m_flGamma.m_Storage);
  v10 = pSrcImage->m_Mode;
  if ( v10 != DMEIMAGE_STORAGE_NONE )
  {
    if ( v10 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    {
      CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 1, bDiscardContents: true);
      CDmeImage::SetFloatBitmapStorageMode(this: pSrcImage, bFloatBitmap: 1, bDiscardContents: false);
      FloatBitMap_t::LoadFromFloatBitmap(this: &this->m_ComputeBits, pOrig: &pSrcImage->m_ComputeBits);
    }
    else
    {
      v11 = pSrcImage->m_nFormat.m_Storage;
      v12 = this->m_nFormat.m_Storage;
      if ( v11 == v12 )
      {
        MemRequired = ImageLoader::GetMemRequired(
                        width: pSrcImage->m_nWidth.m_Storage,
                        height: pSrcImage->m_nHeight.m_Storage,
                        depth: pSrcImage->m_nDepth.m_Storage,
                        imageFormat: v11,
                        mipmap: false,
                        pAdjustedHeight: nullptr);
        CDmeImage::SetFloatBitmapStorageMode(this: pSrcImage, bFloatBitmap: 0, bDiscardContents: false);
        m_pMemory = pSrcImage->m_Bits.m_Storage.m_Memory.m_pMemory;
        CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 0, bDiscardContents: true);
        CDmaBinaryBlock::Set(this: &this->m_Bits, pValue: m_pMemory, nLen: MemRequired);
      }
      else
      {
        v15 = this->m_Mode;
        if ( v15 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
          v16 = this->m_ComputeBits.m_nSlices;
        else
          v16 = this->m_nDepth.m_Storage;
        if ( v15 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
          v17 = this->m_ComputeBits.m_nRows;
        else
          v17 = this->m_nHeight.m_Storage;
        if ( v15 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
          v18 = this->m_ComputeBits.m_nColumns;
        else
          v18 = this->m_nWidth.m_Storage;
        v19 = ImageLoader::GetMemRequired(
                width: v18,
                height: v17,
                depth: v16,
                nMipmapCount: 1,
                imageFormat: v12,
                pAdjustedHeight: nullptr);
        CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 0, bDiscardContents: false);
        m_pAttribute = this->m_Bits.m_pAttribute;
        this->m_bInModification = true;
        v21 = (CUtlBinaryBlock *)CDmAttribute::BeginModifyValueInPlace<CUtlBinaryBlock>(
                                   pAttribute: m_pAttribute,
                                   a2: (int)&this->m_hModify);
        CUtlBinaryBlock::SetLength(this: v21, nLength: v19);
        v22 = this->m_Mode;
        if ( v22 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
          fmta = this->m_ComputeBits.m_nRows;
        else
          fmta = this->m_nHeight.m_Storage;
        if ( v22 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
          v23 = this->m_ComputeBits.m_nSlices;
        else
          v23 = this->m_nDepth.m_Storage;
        if ( v22 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
          pSrcImagea = (CDmeImage *)this->m_ComputeBits.m_nColumns;
        else
          pSrcImagea = (CDmeImage *)this->m_nWidth.m_Storage;
        v24 = v21->m_Memory.m_pMemory;
        dstImageFormat = this->m_nFormat.m_Storage;
        srcImageFormat = pSrcImage->m_nFormat.m_Storage;
        CDmeImage::SetFloatBitmapStorageMode(this: pSrcImage, bFloatBitmap: 0, bDiscardContents: false);
        ImageLoader::ConvertImageFormat(
          src: pSrcImage->m_Bits.m_Storage.m_Memory.m_pMemory,
          srcImageFormat,
          dst: v24,
          dstImageFormat,
          width: (int)pSrcImagea,
          height: fmta * v23,
          srcStride: 0,
          dstStride: 0);
        CDmeImage::EndModification(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042EE90
// Name: public: FloatBitMap_t::FloatBitMap_t(void)
// Source: json
//------------------------------------------------------------------------------
FloatBitMap_t *__thiscall FloatBitMap_t::FloatBitMap_t(FloatBitMap_t *this)
{
  memset(dst: (int)this->m_nDataType, value: (unsigned __int8 *)0xFF, count: sizeof(this->m_nDataType));
  memset(dst: (int)this->m_pSeparateDataMemory, value: nullptr, count: sizeof(this->m_pSeparateDataMemory));
  this->m_pConstantDataMemory = nullptr;
  this->m_pDataMemory = nullptr;
  this->m_nNumQuadsPerRow = 0;
  this->m_nSlices = 0;
  this->m_nRows = 0;
  this->m_nPaddedColumns = 0;
  this->m_nColumns = 0;
  this->m_nFieldPresentMask = 0;
  this->m_eThreadMode = SOATHREADMODE_NONE;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042EF30
// Name: protected: CDmeImage::CDmeImage(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeImage *__thiscall CDmeImage::CDmeImage(
        CDmeImage *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeImage_vtbl *)&CDmeImage::`vftable';
  this->m_nWidth.m_pAttribute = nullptr;
  this->m_nWidth.m_Storage = 0;
  this->m_nHeight.m_pAttribute = nullptr;
  this->m_nHeight.m_Storage = 0;
  this->m_nDepth.m_pAttribute = nullptr;
  this->m_nDepth.m_Storage = 0;
  this->m_nFormat.m_pAttribute = nullptr;
  this->m_nFormat.m_Storage = 0;
  this->m_flGamma = 0;
  CUtlBinaryBlock::CUtlBinaryBlock(this: &this->m_Bits.m_Storage, growSize: 0, initSize: 0);
  this->m_Bits.m_pAttribute = nullptr;
  CUtlBinaryBlock::Set(this: &this->m_Bits.m_Storage, pValue: nullptr, nLen: 0);
  FloatBitMap_t::FloatBitMap_t(this: &this->m_ComputeBits);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042EFB0
// Name: public: virtual bool CDmeImage::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeImage::IsA(CDmeImage *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeImage::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042EFE0
// Name: public: virtual int CDmeImage::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImage::GetInheritanceDepth(CDmeImage *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeImage::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042F010
// Name: protected: virtual int CDmeImage::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImage::AllocatedSize(CDmeImage *this)
{
  return 944;
}

//------------------------------------------------------------------------------
// Address: 0x0042F020
// Name: protected: virtual void CDmeImage::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::PerformConstruction(CDmeImage *this)
{
  CSteamApplication::PostShutdown((CFontManager *)this);
  CDmeImage::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042F030
// Name: protected: virtual CDmeImage::~CDmeImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::~CDmeImage(CDmeImage *this)
{
  bool v2; // sf

  this->__vftable = (CDmeImage_vtbl *)&CDmeImage::`vftable';
  CSOAContainer::~CSOAContainer(this: &this->m_ComputeBits);
  v2 = this->m_Bits.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_Bits.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_Bits.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Bits.m_Storage.m_Memory.m_pMemory);
      this->m_Bits.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Bits.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CDmElement::~CDmElement(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042F120
// Name: public: virtual bool CDmeImageArray::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeImageArray::IsA(CDmeImageArray *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeImageArray::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042F150
// Name: public: virtual int CDmeImageArray::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImageArray::GetInheritanceDepth(CDmeImageArray *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeImageArray::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042F180
// Name: protected: virtual void CDmeImageArray::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImageArray::PerformConstruction(CDmeImageArray *this)
{
  CSteamApplication::PostShutdown((CFontManager *)this);
  this->m_Images.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "images",
                                  type: AT_FIRST_ARRAY_TYPE,
                                  pMemory: &this->m_Images);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Images.m_pAttribute, typeSymbol: CDmeImage::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00431BC0
// Name: public: FloatBitMap_t::FloatBitMap_t(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
FloatBitMap_t *__thiscall FloatBitMap_t::FloatBitMap_t(
        FloatBitMap_t *this,
        int nWidth,
        int nHeight,
        int nDepth,
        char nAttributeMask)
{
  memset(dst: (int)this->m_nDataType, value: (unsigned __int8 *)0xFF, count: sizeof(this->m_nDataType));
  memset(dst: (int)this->m_pSeparateDataMemory, value: nullptr, count: sizeof(this->m_pSeparateDataMemory));
  this->m_pConstantDataMemory = nullptr;
  this->m_pDataMemory = nullptr;
  this->m_nNumQuadsPerRow = 0;
  this->m_nSlices = 0;
  this->m_nRows = 0;
  this->m_nPaddedColumns = 0;
  this->m_nColumns = 0;
  this->m_nFieldPresentMask = 0;
  this->m_eThreadMode = SOATHREADMODE_NONE;
  FloatBitMap_t::Init(this, nXSize: nWidth, nYSize: nHeight, nZSize: nDepth, nAttributeMask);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005339A0
// Name: _dynamic_initializer_for__CDmeImage::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeImage::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeImage::s_Allocator,
    blockSize: 944,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeImage pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeImage::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00533A00
// Name: _dynamic_initializer_for__CDmeImageArray::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeImageArray::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeImageArray::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeImageArray pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeImageArray::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00535230
// Name: _dynamic_atexit_destructor_for__CDmeImage::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeImage::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeImage::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00535240
// Name: _dynamic_atexit_destructor_for__CDmeImageArray::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeImageArray::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeImageArray::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005339D0
// Name: _dynamic_initializer_for__g_CDmeImage_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeImage_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeImage_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005339E0
// Name: _dynamic_initializer_for__g_CDmeImage_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeImage_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeImage_Helper,
           classname: "DmeImage",
           pFactory: &g_CDmeImage_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x00533A30
// Name: _dynamic_initializer_for__g_CDmeImageArray_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeImageArray_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeImageArray_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00533A40
// Name: _dynamic_initializer_for__g_CDmeImageArray_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeImageArray_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeImageArray_Helper,
           classname: "DmeImageArray",
           pFactory: &g_CDmeImageArray_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x00535250
// Name: _dynamic_atexit_destructor_for__g_CDmeImageArray_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeImageArray_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeImageArray_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00535260
// Name: _dynamic_atexit_destructor_for__g_CDmeImage_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeImage_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeImage_Factory.m_CallBackList);
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x005682A0
// Name: protected: void CDmeImage::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::OnConstruction(CDmeImage *this)
{
  CDmaVar<int> *p_m_nWidth; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax

  p_m_nWidth = &this->m_nWidth;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "width", type: AT_INT, pMemory: &this->m_nWidth);
  p_m_nWidth->m_pAttribute = v3;
  v3->m_nFlags |= 0x8000u;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "height", type: AT_INT, pMemory: &this->m_nHeight);
  this->m_nHeight.m_pAttribute = v4;
  v4->m_nFlags |= 0x8000u;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "depth", type: AT_INT, pMemory: &this->m_nDepth);
  this->m_nDepth.m_pAttribute = v5;
  v5->m_nFlags |= 0x8000u;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "format", type: AT_INT, pMemory: &this->m_nFormat);
  this->m_nFormat.m_pAttribute = v6;
  v6->m_nFlags |= 0x8000u;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "gamma", type: AT_FLOAT, pMemory: &this->m_flGamma);
  this->m_flGamma.m_pAttribute = v7;
  v7->m_nFlags |= 0x8000u;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "bits", type: AT_VOID, pMemory: &this->m_Bits);
  this->m_Bits.m_pAttribute = v8;
  v8->m_nFlags |= 0x8100u;
  this->m_Mode = DMEIMAGE_STORAGE_NONE;
  *(_WORD *)&this->m_bInModification = 0;
  this->m_bIgnoreChangedBitsAttribute = false;
  this->m_hModify = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00568380
// Name: public: class CUtlBinaryBlock __near & CDmeImage::BeginModification(void)
// Source: json
//------------------------------------------------------------------------------
CUtlBinaryBlock *__thiscall CDmeImage::BeginModification(CDmeImage *this)
{
  CDmAttribute *m_pAttribute; // ecx

  CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: false, bDiscardContents: false);
  m_pAttribute = this->m_Bits.m_pAttribute;
  this->m_bInModification = true;
  return CDmAttribute::BeginModifyValueInPlace<CUtlBinaryBlock>(this: m_pAttribute, pHandle: &this->m_hModify);
}

//------------------------------------------------------------------------------
// Address: 0x005683B0
// Name: public: void CDmeImage::EndModification(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::EndModification(CDmeImage *this)
{
  char *m_hModify; // eax
  CDmAttribute *m_pAttribute; // ecx

  m_hModify = (char *)this->m_hModify;
  m_pAttribute = this->m_Bits.m_pAttribute;
  this->m_bInModification = false;
  this->m_bIgnoreChangedBitsAttribute = true;
  CDmAttribute::EndModifyValueInPlace<CUtlBinaryBlock>(this: m_pAttribute, handle: m_hModify);
  this->m_bIgnoreChangedBitsAttribute = false;
  this->m_hModify = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00568400
// Name: public: int CDmeImage::SizeInBytes(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImage::SizeInBytes(CDmeImage *this)
{
  return ImageLoader::GetMemRequired(
           width: this->m_nWidth.m_Storage,
           height: this->m_nHeight.m_Storage,
           depth: this->m_nDepth.m_Storage,
           imageFormat: (ImageFormat)this->m_nFormat.m_Storage,
           mipmap: false,
           pAdjustedHeight: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00568420
// Name: public: void CDmeImage::SetFloatBitmapStorageMode(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::SetFloatBitmapStorageMode(CDmeImage *this, int bFloatBitmap, bool bDiscardContents)
{
  CDmeImage::StorageMode_t m_Mode; // ebx
  CDmeImage::StorageMode_t v5; // eax
  __int32 v6; // eax
  int m_nColumns; // eax
  CDmAttribute *v8; // ecx
  CDmAttribute *v9; // ecx
  CUtlBinaryBlock *v10; // edi
  int v11; // eax
  CDmAttribute *m_pAttribute; // ecx
  CUtlBinaryBlock *v13; // edi
  int MemRequired; // eax
  const ImageFormatInfo_t *v15; // eax
  char v16; // cl
  int m_nSlices; // [esp+10h] [ebp-8h] BYREF
  int value; // [esp+14h] [ebp-4h] BYREF

  m_Mode = this->m_Mode;
  v5 = ((_BYTE)bFloatBitmap == 0) + 1;
  if ( v5 != m_Mode )
  {
    this->m_Mode = v5;
    v6 = v5 - 1;
    if ( v6 != 0 )
    {
      if ( v6 == 1 )
      {
        if ( bDiscardContents || m_Mode != DMEIMAGE_STORAGE_FLOAT_BITMAP )
        {
          CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: false, bDiscardContents: false);
          m_pAttribute = this->m_Bits.m_pAttribute;
          this->m_bInModification = true;
          v13 = CDmAttribute::BeginModifyValueInPlace<CUtlBinaryBlock>(this: m_pAttribute, pHandle: &this->m_hModify);
          MemRequired = ImageLoader::GetMemRequired(
                          width: this->m_nWidth.m_Storage,
                          height: this->m_nHeight.m_Storage,
                          depth: this->m_nDepth.m_Storage,
                          imageFormat: (ImageFormat)this->m_nFormat.m_Storage,
                          mipmap: false,
                          pAdjustedHeight: nullptr);
          CUtlBinaryBlock::SetLength(this: v13, nLength: MemRequired);
        }
        else
        {
          m_nColumns = this->m_ComputeBits.m_nColumns;
          v8 = this->m_nWidth.m_pAttribute;
          bFloatBitmap = m_nColumns;
          CDmAttribute::SetValue<int>(this: v8, value: &bFloatBitmap);
          v9 = this->m_nHeight.m_pAttribute;
          value = this->m_ComputeBits.m_nRows;
          CDmAttribute::SetValue<int>(this: v9, &value);
          m_nSlices = this->m_ComputeBits.m_nSlices;
          CDmAttribute::SetValue<int>(this: this->m_nDepth.m_pAttribute, value: &m_nSlices);
          v10 = CDmeImage::BeginModification(this);
          v11 = CDmeImage::SizeInBytes(this);
          CUtlBinaryBlock::SetLength(this: v10, nLength: v11);
          FloatBitMap_t::WriteToBuffer(
            this: &this->m_ComputeBits,
            pBuffer: v10->m_Memory.m_pMemory,
            nBufSize: v10->m_nActualLength,
            fmt: (ImageFormat)this->m_nFormat.m_Storage,
            flGamma: this->m_flGamma.m_Storage);
        }
        CDmeImage::EndModification(this);
        CSOAContainer::~CSOAContainer(this: &this->m_ComputeBits);
      }
    }
    else
    {
      v15 = ImageLoader::ImageFormatInfo(fmt: (ImageFormat)this->m_nFormat.m_Storage);
      v16 = v15->m_nNumRedBits != 0;
      if ( v15->m_nNumGreenBits != 0 )
        v16 |= 2u;
      if ( v15->m_nNumBlueBits != 0 )
        v16 |= 4u;
      if ( v15->m_nNumAlphaBits != 0 )
        v16 |= 8u;
      FloatBitMap_t::Init(
        this: &this->m_ComputeBits,
        nXSize: (unsigned __int8 *)this->m_nWidth.m_Storage,
        nYSize: (unsigned __int8 *)this->m_nHeight.m_Storage,
        nZSize: this->m_nDepth.m_Storage,
        nAttributeMask: v16);
      if ( !bDiscardContents && m_Mode == DMEIMAGE_STORAGE_ATTRIBUTE )
        FloatBitMap_t::LoadFromBuffer(
          this: &this->m_ComputeBits,
          pBuffer: this->m_Bits.m_Storage.m_Memory.m_pMemory,
          nBufSize: this->m_Bits.m_Storage.m_nActualLength,
          fmt: (ImageFormat)this->m_nFormat.m_Storage,
          flGamma: this->m_flGamma.m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005685C0
// Name: public: void CDmeImage::QuarterSize(class CDmeImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::QuarterSize(CDmeImage *this, float pSrcImage)
{
  CDmeImage *v3; // edi
  CDmAttribute *m_pAttribute; // ecx

  CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 1, bDiscardContents: true);
  v3 = (CDmeImage *)LODWORD(pSrcImage);
  CDmeImage::SetFloatBitmapStorageMode(this: (CDmeImage *)LODWORD(pSrcImage), bFloatBitmap: 1, bDiscardContents: false);
  FloatBitMap_t::QuarterSize(this: &v3->m_ComputeBits, pBitmap: &this->m_ComputeBits);
  pSrcImage = *(float *)&v3->m_nFormat.m_Storage;
  CDmAttribute::SetValue<int>(this: this->m_nFormat.m_pAttribute, value: (int *)&pSrcImage);
  m_pAttribute = this->m_flGamma.m_pAttribute;
  pSrcImage = v3->m_flGamma.m_Storage;
  CDmAttribute::SetValue<float>(this: m_pAttribute, value: &pSrcImage);
}

//------------------------------------------------------------------------------
// Address: 0x00568620
// Name: public: void CDmeImage::DownsampleNiceFiltered(struct DownsampleInfo_t const __near &,class CDmeImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::DownsampleNiceFiltered(CDmeImage *this, const DownsampleInfo_t *info, float pSrcImage)
{
  CDmeImage *v4; // edi
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v6; // ecx

  CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 1, bDiscardContents: true);
  v4 = (CDmeImage *)LODWORD(pSrcImage);
  CDmeImage::SetFloatBitmapStorageMode(this: (CDmeImage *)LODWORD(pSrcImage), bFloatBitmap: 1, bDiscardContents: false);
  FloatBitMap_t::DownsampleNiceFiltered(
    this: &v4->m_ComputeBits,
    downsampleInfo: info,
    pDestBitmap: &this->m_ComputeBits);
  m_pAttribute = this->m_nFormat.m_pAttribute;
  pSrcImage = *(float *)&v4->m_nFormat.m_Storage;
  CDmAttribute::SetValue<int>(this: m_pAttribute, value: (int *)&pSrcImage);
  v6 = this->m_flGamma.m_pAttribute;
  pSrcImage = v4->m_flGamma.m_Storage;
  CDmAttribute::SetValue<float>(this: v6, value: &pSrcImage);
}

//------------------------------------------------------------------------------
// Address: 0x00568690
// Name: public: virtual void CDmeImage::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::OnAttributeChanged(CDmeImage *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_Bits.m_pAttribute
    && !this->m_bIgnoreChangedBitsAttribute
    && this->m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
  {
    CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 0, bDiscardContents: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005686C0
// Name: public: virtual void CDmeImage::OnElementUnserialized(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::OnElementUnserialized(CDmeImage *this)
{
  if ( this->m_Mode != DMEIMAGE_STORAGE_ATTRIBUTE )
    CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 0, bDiscardContents: true);
}

//------------------------------------------------------------------------------
// Address: 0x005686E0
// Name: public: virtual void CDmeImage::OnElementSerialized(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::OnElementSerialized(CDmeImage *this)
{
  if ( this->m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 0, bDiscardContents: false);
}

//------------------------------------------------------------------------------
// Address: 0x00568700
// Name: public: void CDmeImage::Init(int,int,int,enum ImageFormat,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::Init(CDmeImage *this, int nWidth, int nHeight, int nDepth, ImageFormat fmt, float flGamma)
{
  CUtlBinaryBlock value; // [esp+4h] [ebp-10h] BYREF

  if ( this->m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    CSOAContainer::~CSOAContainer(this: &this->m_ComputeBits);
  CUtlBinaryBlock::CUtlBinaryBlock(this: &value, pMemory: nullptr, nSizeInBytes: 0);
  CDmAttribute::SetValue<CUtlBinaryBlock>(this: this->m_Bits.m_pAttribute, (const CUtlString *)&value);
  value.m_nActualLength = 0;
  if ( value.m_Memory.m_nGrowSize >= 0 && value.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: value.m_Memory.m_pMemory);
  CDmAttribute::SetValue<int>(this: this->m_nWidth.m_pAttribute, value: &nWidth);
  CDmAttribute::SetValue<int>(this: this->m_nHeight.m_pAttribute, value: &nHeight);
  CDmAttribute::SetValue<int>(this: this->m_nDepth.m_pAttribute, value: &nDepth);
  CDmAttribute::SetValue<int>(this: this->m_nFormat.m_pAttribute, value: (int *)&fmt);
  CDmAttribute::SetValue<float>(this: this->m_flGamma.m_pAttribute, value: &flGamma);
  this->m_Mode = DMEIMAGE_STORAGE_NONE;
}

//------------------------------------------------------------------------------
// Address: 0x005687B0
// Name: public: void CDmeImage::SetImageBits(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::SetImageBits(CDmeImage *this, const void *pBits, int nSize)
{
  CUtlBinaryBlock value; // [esp+4h] [ebp-10h] BYREF

  CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 0, bDiscardContents: true);
  CUtlBinaryBlock::CUtlBinaryBlock(this: &value, pMemory: pBits, nSizeInBytes: nSize);
  CDmAttribute::SetValue<CUtlBinaryBlock>(this: this->m_Bits.m_pAttribute, (const CUtlString *)&value);
  value.m_nActualLength = 0;
  if ( value.m_Memory.m_nGrowSize >= 0 && value.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: value.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00568810
// Name: public: class CDmeImage __near * CDmeImageArray::GetImage(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeImage *__thiscall CDmeImageArray::GetImage(CDmeImageArray *this, int nIndex)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Images.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeImage::m_classType) )
    return (CDmeImage *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00568860
// Name: public: bool CDmeImageArray::IsConsistent(int,int,int,enum ImageFormat)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeImageArray::IsConsistent(
        CDmeImageArray *this,
        CDmElement_vtbl *nWidth,
        int nHeight,
        int nDepth,
        CDmAttribute *fmt)
{
  bool result; // al
  CDmElement *v6; // eax
  CDmElement *v7; // esi
  int v8; // ecx
  CDmElement_vtbl *v9; // eax
  int v10; // eax
  int v11; // esi

  if ( this->m_Images.m_Storage.m_Size == 0 )
    return true;
  v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Images.m_Storage.m_Memory.m_pMemory);
  v7 = v6;
  if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeImage::m_classType) )
    v7 = nullptr;
  v8 = *((_DWORD *)&v7[1] + 16);
  if ( v8 == 1 )
    v9 = *(CDmElement_vtbl **)v7[2].m_Id.m_Value;
  else
    v9 = v7[1].__vftable;
  result = false;
  if ( nWidth == v9 )
  {
    v10 = v8 == 1 ? *(_DWORD *)&v7[2].m_Id.m_Value[4] : *(_DWORD *)&v7[1].m_Id.m_Value[4];
    if ( nHeight == v10 && fmt == v7[1].m_Name.m_pAttribute )
    {
      v11 = v8 == 1 ? *(_DWORD *)&v7[2].m_Id.m_Value[8] : *(_DWORD *)&v7[1].m_Id.m_Value[12];
      if ( nDepth == v11 )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00568910
// Name: public: void CDmeImageArray::AddImage(class CDmeImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImageArray::AddImage(CDmeImageArray *this, CDmeImage *pImage)
{
  CVTFTexture *v2; // esi
  CDmeImage::StorageMode_t m_Mode; // eax
  int m_nSlices; // edx
  int m_nRows; // ecx
  CDmElement_vtbl *m_nColumns; // eax

  v2 = (CVTFTexture *)pImage;
  m_Mode = pImage->m_Mode;
  if ( m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    m_nSlices = pImage->m_ComputeBits.m_nSlices;
  else
    m_nSlices = pImage->m_nDepth.m_Storage;
  if ( m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    m_nRows = pImage->m_ComputeBits.m_nRows;
  else
    m_nRows = pImage->m_nHeight.m_Storage;
  if ( m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    m_nColumns = (CDmElement_vtbl *)pImage->m_ComputeBits.m_nColumns;
  else
    m_nColumns = (CDmElement_vtbl *)pImage->m_nWidth.m_Storage;
  if ( CDmeImageArray::IsConsistent(
         this,
         nWidth: m_nColumns,
         nHeight: m_nRows,
         nDepth: m_nSlices,
         fmt: (CDmAttribute *)pImage->m_nFormat.m_Storage) )
  {
    pImage = (CDmeImage *)CCoreDispNode::GetCenterVertIndex(this: v2);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Images,
      src: (DmElementHandle_t *)&pImage);
  }
  else
  {
    _Warning(a1: "Attempted to add different size/format images to the image array!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x005689A0
// Name: public: class CDmeImage __near * CDmeImageArray::AddImage(void)
// Source: json
//------------------------------------------------------------------------------
CDmeImage *__thiscall CDmeImageArray::AddImage(CDmeImageArray *this)
{
  DmElementHandle_t v2; // eax
  CDmElement *v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // edi
  float *v6; // eax
  int v7; // ecx
  float flGamma; // xmm0_4
  ImageFormat v9; // esi
  int v10; // edi
  int v11; // edx
  int v12; // eax
  CDmeImage *pImage; // [esp+2Ch] [ebp-4h]

  v2 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeImage::m_classType.u.m_Id,
         a3: "image",
         a4: this->m_fileId,
         a5: nullptr);
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
  if ( v3 == nullptr || (pImage = (CDmeImage *)v3, !v3->IsA(this: v3, a2: CDmeImage::m_classType)) )
    pImage = nullptr;
  if ( this->m_Images.m_Storage.m_Size > 0 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Images.m_Storage.m_Memory.m_pMemory);
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeImage::m_classType) )
      v6 = (float *)v5;
    else
      v6 = nullptr;
    v7 = *((_DWORD *)v6 + 33);
    flGamma = v6[25];
    v9 = *((_DWORD *)v6 + 23);
    if ( v7 == 1 )
      v10 = *((_DWORD *)v6 + 37);
    else
      v10 = *((_DWORD *)v6 + 21);
    if ( v7 == 1 )
      v11 = *((_DWORD *)v6 + 36);
    else
      v11 = *((_DWORD *)v6 + 19);
    if ( v7 == 1 )
      v12 = *((_DWORD *)v6 + 35);
    else
      v12 = *((_DWORD *)v6 + 17);
    CDmeImage::Init(this: pImage, nWidth: v12, nHeight: v11, nDepth: v10, fmt: v9, flGamma);
  }
  CDmeImageArray::AddImage(this, pImage);
  return pImage;
}

//------------------------------------------------------------------------------
// Address: 0x00568AB0
// Name: public: int CDmeImageArray::Width(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement_vtbl *__thiscall CDmeImageArray::Width(CDmeImageArray *this)
{
  CDmElement *v1; // eax
  CDmElement *v2; // esi

  if ( this->m_Images.m_Storage.m_Size <= 0 )
    return (CDmElement_vtbl *)-1;
  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Images.m_Storage.m_Memory.m_pMemory);
  v2 = v1;
  if ( v1 == nullptr || !v1->IsA(this: v1, a2: CDmeImage::m_classType) )
    v2 = nullptr;
  if ( *((_DWORD *)&v2[1] + 16) == 1 )
    return *(CDmElement_vtbl **)v2[2].m_Id.m_Value;
  else
    return v2[1].__vftable;
}

//------------------------------------------------------------------------------
// Address: 0x00568B10
// Name: public: int CDmeImageArray::Height(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImageArray::Height(CDmeImageArray *this)
{
  CDmElement *v1; // eax
  CDmElement *v2; // esi

  if ( this->m_Images.m_Storage.m_Size <= 0 )
    return -1;
  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Images.m_Storage.m_Memory.m_pMemory);
  v2 = v1;
  if ( v1 == nullptr || !v1->IsA(this: v1, a2: CDmeImage::m_classType) )
    v2 = nullptr;
  if ( *((_DWORD *)&v2[1] + 16) == 1 )
    return *(_DWORD *)&v2[2].m_Id.m_Value[4];
  else
    return *(_DWORD *)&v2[1].m_Id.m_Value[4];
}

//------------------------------------------------------------------------------
// Address: 0x00568B70
// Name: public: int CDmeImageArray::Depth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImageArray::Depth(CDmeImageArray *this)
{
  CDmElement *v1; // eax
  CDmElement *v2; // esi

  if ( this->m_Images.m_Storage.m_Size <= 0 )
    return -1;
  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Images.m_Storage.m_Memory.m_pMemory);
  v2 = v1;
  if ( v1 == nullptr || !v1->IsA(this: v1, a2: CDmeImage::m_classType) )
    v2 = nullptr;
  if ( *((_DWORD *)&v2[1] + 16) == 1 )
    return *(_DWORD *)&v2[2].m_Id.m_Value[8];
  else
    return *(_DWORD *)&v2[1].m_Id.m_Value[12];
}

//------------------------------------------------------------------------------
// Address: 0x00568BD0
// Name: public: void CDmeImage::CopyFrom(class CDmeImage __near *,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::CopyFrom(CDmeImage *this, CDmeImage *pSrcImage, ImageFormat fmt)
{
  ImageFormat m_Storage; // ebx
  CDmeImage::StorageMode_t m_Mode; // eax
  int m_nSlices; // edx
  int m_nRows; // ecx
  int m_nColumns; // eax
  CDmeImage::StorageMode_t v10; // eax
  ImageFormat v11; // eax
  ImageFormat v12; // edx
  int MemRequired; // ebx
  CDmeImage::StorageMode_t v14; // eax
  int v15; // ebx
  int v16; // ecx
  int v17; // eax
  int v18; // ebx
  CDmAttribute *m_pAttribute; // ecx
  CDmeImage::StorageMode_t v20; // eax
  int v21; // ebx
  ImageFormat srcImageFormat; // [esp+10h] [ebp-Ch]
  ImageFormat dstImageFormat; // [esp+14h] [ebp-8h]
  CUtlBinaryBlock *bits; // [esp+18h] [ebp-4h]
  unsigned __int8 *bitsa; // [esp+18h] [ebp-4h]
  CDmeImage *pSrcImagea; // [esp+24h] [ebp+8h]
  ImageFormat fmta; // [esp+28h] [ebp+Ch]

  m_Storage = fmt;
  if ( fmt == IMAGE_FORMAT_UNKNOWN )
    m_Storage = pSrcImage->m_nFormat.m_Storage;
  m_Mode = pSrcImage->m_Mode;
  if ( m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    m_nSlices = pSrcImage->m_ComputeBits.m_nSlices;
  else
    m_nSlices = pSrcImage->m_nDepth.m_Storage;
  if ( m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    m_nRows = pSrcImage->m_ComputeBits.m_nRows;
  else
    m_nRows = pSrcImage->m_nHeight.m_Storage;
  if ( m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    m_nColumns = pSrcImage->m_ComputeBits.m_nColumns;
  else
    m_nColumns = pSrcImage->m_nWidth.m_Storage;
  CDmeImage::Init(
    this,
    nWidth: m_nColumns,
    nHeight: m_nRows,
    nDepth: m_nSlices,
    fmt: m_Storage,
    flGamma: pSrcImage->m_flGamma.m_Storage);
  v10 = pSrcImage->m_Mode;
  if ( v10 != DMEIMAGE_STORAGE_NONE )
  {
    if ( v10 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    {
      CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 1, bDiscardContents: true);
      CDmeImage::SetFloatBitmapStorageMode(this: pSrcImage, bFloatBitmap: 1, bDiscardContents: false);
      FloatBitMap_t::LoadFromFloatBitmap(this: &this->m_ComputeBits, pOrig: &pSrcImage->m_ComputeBits);
    }
    else
    {
      v11 = pSrcImage->m_nFormat.m_Storage;
      v12 = this->m_nFormat.m_Storage;
      if ( v11 == v12 )
      {
        MemRequired = ImageLoader::GetMemRequired(
                        width: pSrcImage->m_nWidth.m_Storage,
                        height: pSrcImage->m_nHeight.m_Storage,
                        depth: pSrcImage->m_nDepth.m_Storage,
                        imageFormat: v11,
                        mipmap: false,
                        pAdjustedHeight: nullptr);
        CDmeImage::SetFloatBitmapStorageMode(this: pSrcImage, bFloatBitmap: 0, bDiscardContents: false);
        CDmeImage::SetImageBits(this, pBits: pSrcImage->m_Bits.m_Storage.m_Memory.m_pMemory, nSize: MemRequired);
      }
      else
      {
        v14 = this->m_Mode;
        if ( v14 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
          v15 = this->m_ComputeBits.m_nSlices;
        else
          v15 = this->m_nDepth.m_Storage;
        if ( v14 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
          v16 = this->m_ComputeBits.m_nRows;
        else
          v16 = this->m_nHeight.m_Storage;
        if ( v14 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
          v17 = this->m_ComputeBits.m_nColumns;
        else
          v17 = this->m_nWidth.m_Storage;
        v18 = ImageLoader::GetMemRequired(
                width: v17,
                height: v16,
                depth: v15,
                nMipmapCount: 1,
                imageFormat: v12,
                pAdjustedHeight: nullptr);
        CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 0, bDiscardContents: false);
        m_pAttribute = this->m_Bits.m_pAttribute;
        this->m_bInModification = true;
        bits = CDmAttribute::BeginModifyValueInPlace<CUtlBinaryBlock>(this: m_pAttribute, pHandle: &this->m_hModify);
        CUtlBinaryBlock::SetLength(this: bits, nLength: v18);
        v20 = this->m_Mode;
        if ( v20 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
          fmta = this->m_ComputeBits.m_nRows;
        else
          fmta = this->m_nHeight.m_Storage;
        if ( v20 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
          v21 = this->m_ComputeBits.m_nSlices;
        else
          v21 = this->m_nDepth.m_Storage;
        if ( v20 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
          pSrcImagea = (CDmeImage *)this->m_ComputeBits.m_nColumns;
        else
          pSrcImagea = (CDmeImage *)this->m_nWidth.m_Storage;
        dstImageFormat = this->m_nFormat.m_Storage;
        bitsa = bits->m_Memory.m_pMemory;
        srcImageFormat = pSrcImage->m_nFormat.m_Storage;
        CDmeImage::SetFloatBitmapStorageMode(this: pSrcImage, bFloatBitmap: 0, bDiscardContents: false);
        ImageLoader::ConvertImageFormat(
          src: pSrcImage->m_Bits.m_Storage.m_Memory.m_pMemory,
          srcImageFormat,
          dst: bitsa,
          dstImageFormat,
          width: (int)pSrcImagea,
          height: fmta * v21,
          srcStride: 0,
          dstStride: 0);
        CDmeImage::EndModification(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00568E30
// Name: protected: CDmeImage::CDmeImage(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeImage *__thiscall CDmeImage::CDmeImage(
        CDmeImage *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeImage_vtbl *)&CDmeImage::`vftable';
  this->m_nWidth.m_pAttribute = nullptr;
  this->m_nWidth.m_Storage = 0;
  this->m_nHeight.m_pAttribute = nullptr;
  this->m_nHeight.m_Storage = 0;
  this->m_nDepth.m_pAttribute = nullptr;
  this->m_nDepth.m_Storage = 0;
  this->m_nFormat.m_pAttribute = nullptr;
  this->m_nFormat.m_Storage = 0;
  this->m_flGamma = 0;
  CUtlBinaryBlock::CUtlBinaryBlock(this: &this->m_Bits.m_Storage, growSize: 0, initSize: 0);
  this->m_Bits.m_pAttribute = nullptr;
  CUtlBinaryBlock::Set(this: &this->m_Bits.m_Storage, pValue: nullptr, nLen: 0);
  memset(
    dst: (unsigned __int8 *)this->m_ComputeBits.m_nDataType,
    value: 0xFFu,
    count: sizeof(this->m_ComputeBits.m_nDataType));
  memset(
    dst: (unsigned __int8 *)this->m_ComputeBits.m_pSeparateDataMemory,
    value: 0,
    count: sizeof(this->m_ComputeBits.m_pSeparateDataMemory));
  this->m_ComputeBits.m_pConstantDataMemory = nullptr;
  this->m_ComputeBits.m_pDataMemory = nullptr;
  this->m_ComputeBits.m_nNumQuadsPerRow = 0;
  this->m_ComputeBits.m_nSlices = 0;
  this->m_ComputeBits.m_nRows = 0;
  this->m_ComputeBits.m_nPaddedColumns = 0;
  this->m_ComputeBits.m_nColumns = 0;
  this->m_ComputeBits.m_nFieldPresentMask = 0;
  this->m_ComputeBits.m_eThreadMode = SOATHREADMODE_NONE;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00568F00
// Name: public: virtual bool CDmeImage::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeImage::IsA(CDmeImage *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeImage::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00568F30
// Name: public: virtual int CDmeImage::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImage::GetInheritanceDepth(CDmeImage *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeImage::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00568F70
// Name: protected: virtual int CDmeImage::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImage::AllocatedSize(CDmeImage *this)
{
  return 944;
}

//------------------------------------------------------------------------------
// Address: 0x00568F80
// Name: protected: virtual void CDmeImage::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::PerformConstruction(CDmeImage *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeImage::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005690A0
// Name: public: virtual bool CDmeImageArray::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeImageArray::IsA(CDmeImageArray *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeImageArray::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005690D0
// Name: public: virtual int CDmeImageArray::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImageArray::GetInheritanceDepth(CDmeImageArray *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeImageArray::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00569110
// Name: protected: virtual void CDmeImageArray::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImageArray::PerformConstruction(CDmeImageArray *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  this->m_Images.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "images",
                                  type: AT_FIRST_ARRAY_TYPE,
                                  pMemory: &this->m_Images);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Images.m_pAttribute, typeSymbol: CDmeImage::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00582590
// Name: protected: virtual int CDmeImageArray::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImageArray::AllocatedSize(CDmeTransformList *this)
{
  return 96;
}

//------------------------------------------------------------------------------
// Address: 0x006B7020
// Name: _dynamic_initializer_for__CDmeImage::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeImage::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeImage::s_Allocator,
    blockSize: 0x3B0u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeImage pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeImage::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7080
// Name: _dynamic_initializer_for__CDmeImageArray::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeImageArray::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeImageArray::s_Allocator,
    blockSize: 0x60u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeImageArray pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeImageArray::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BC4B0
// Name: _dynamic_atexit_destructor_for__CDmeImage::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeImage::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeImage::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BC4C0
// Name: _dynamic_atexit_destructor_for__CDmeImageArray::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeImageArray::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeImageArray::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B7050
// Name: _dynamic_initializer_for__g_CDmeImage_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeImage_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeImage_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7060
// Name: _dynamic_initializer_for__g_CDmeImage_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeImage_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeImage_Helper,
           classname: "DmeImage",
           pFactory: &g_CDmeImage_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006B70B0
// Name: _dynamic_initializer_for__g_CDmeImageArray_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeImageArray_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeImageArray_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B70C0
// Name: _dynamic_initializer_for__g_CDmeImageArray_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeImageArray_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeImageArray_Helper,
           classname: "DmeImageArray",
           pFactory: &g_CDmeImageArray_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006BC4D0
// Name: _dynamic_atexit_destructor_for__g_CDmeImageArray_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeImageArray_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeImageArray_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BC4E0
// Name: _dynamic_atexit_destructor_for__g_CDmeImage_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeImage_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeImage_Factory.m_CallBackList);
}

} // namespace vmap

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x100925A0
// Name: protected: virtual void CDmeImage::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDmeImage::PerformDestruction(CDmeTexture *this)
{
  CDmElementFramework::Disconnect(this);
}

//------------------------------------------------------------------------------
// Address: 0x100932C0
// Name: protected: virtual int CDmeImageArray::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImageArray::AllocatedSize(CDmeTextureFrame *this)
{
  return 96;
}

//------------------------------------------------------------------------------
// Address: 0x10093570
// Name: protected: void CDmeImage::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::OnConstruction(CDmeImage *this)
{
  CDmaVar<int> *p_m_nWidth; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax

  p_m_nWidth = &this->m_nWidth;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "width", type: AT_INT, pMemory: &this->m_nWidth);
  p_m_nWidth->m_pAttribute = v3;
  v3->m_nFlags |= 0x8000u;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "height", type: AT_INT, pMemory: &this->m_nHeight);
  this->m_nHeight.m_pAttribute = v4;
  v4->m_nFlags |= 0x8000u;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "depth", type: AT_INT, pMemory: &this->m_nDepth);
  this->m_nDepth.m_pAttribute = v5;
  v5->m_nFlags |= 0x8000u;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "format", type: AT_INT, pMemory: &this->m_nFormat);
  this->m_nFormat.m_pAttribute = v6;
  v6->m_nFlags |= 0x8000u;
  v7 = CDmElement::AddExternalAttribute(this, pAttributeName: "gamma", type: AT_FLOAT, pMemory: &this->m_flGamma);
  this->m_flGamma.m_pAttribute = v7;
  v7->m_nFlags |= 0x8000u;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "bits", type: AT_VOID, pMemory: &this->m_Bits);
  this->m_Bits.m_pAttribute = v8;
  v8->m_nFlags |= 0x8100u;
  this->m_Mode = DMEIMAGE_STORAGE_NONE;
  *(_WORD *)&this->m_bInModification = 0;
  this->m_bIgnoreChangedBitsAttribute = false;
  this->m_hModify = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10093650
// Name: public: class CUtlBinaryBlock __near & CDmeImage::BeginModification(void)
// Source: json
//------------------------------------------------------------------------------
CUtlBinaryBlock *__thiscall CDmeImage::BeginModification(CDmeImage *this)
{
  CDmAttribute *m_pAttribute; // ecx

  CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: false, bDiscardContents: false);
  m_pAttribute = this->m_Bits.m_pAttribute;
  this->m_bInModification = true;
  return CDmAttribute::BeginModifyValueInPlace<CUtlBinaryBlock>(this: m_pAttribute, pHandle: &this->m_hModify);
}

//------------------------------------------------------------------------------
// Address: 0x10093680
// Name: public: void CDmeImage::EndModification(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::EndModification(CDmeImage *this)
{
  char *m_hModify; // eax
  CDmAttribute *m_pAttribute; // ecx

  m_hModify = (char *)this->m_hModify;
  m_pAttribute = this->m_Bits.m_pAttribute;
  this->m_bInModification = false;
  this->m_bIgnoreChangedBitsAttribute = true;
  CDmAttribute::EndModifyValueInPlace<CUtlBinaryBlock>(this: m_pAttribute, handle: m_hModify);
  this->m_bIgnoreChangedBitsAttribute = false;
  this->m_hModify = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100936C0
// Name: public: int CDmeImage::Width(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImage::Width(CDmeImage *this)
{
  if ( this->m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    return this->m_ComputeBits.m_nColumns;
  else
    return this->m_nWidth.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x100936E0
// Name: public: int CDmeImage::Height(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImage::Height(CDmeImage *this)
{
  if ( this->m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    return this->m_ComputeBits.m_nRows;
  else
    return this->m_nHeight.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x10093700
// Name: public: int CDmeImage::Depth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImage::Depth(CDmeImage *this)
{
  if ( this->m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    return this->m_ComputeBits.m_nSlices;
  else
    return this->m_nDepth.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x10093720
// Name: public: enum ImageFormat CDmeImage::Format(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImage::Format(CDmeImage *this)
{
  return this->m_nFormat.m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x10093730
// Name: public: int CDmeImage::ZSliceSizeInBytes(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImage::ZSliceSizeInBytes(CDmeImage *this)
{
  return ImageLoader::GetMemRequired(
           width: this->m_nWidth.m_Storage,
           height: this->m_nHeight.m_Storage,
           depth: 1,
           imageFormat: (ImageFormat)this->m_nFormat.m_Storage,
           mipmap: false,
           pAdjustedHeight: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10093750
// Name: public: int CDmeImage::SizeInBytes(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImage::SizeInBytes(CDmeImage *this)
{
  return ImageLoader::GetMemRequired(
           width: this->m_nWidth.m_Storage,
           height: this->m_nHeight.m_Storage,
           depth: this->m_nDepth.m_Storage,
           imageFormat: (ImageFormat)this->m_nFormat.m_Storage,
           mipmap: false,
           pAdjustedHeight: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10093770
// Name: public: void CDmeImage::SetFloatBitmapStorageMode(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::SetFloatBitmapStorageMode(CDmeImage *this, int bFloatBitmap, bool bDiscardContents)
{
  CDmeImage::StorageMode_t m_Mode; // ebx
  CDmeImage::StorageMode_t v5; // eax
  __int32 v6; // eax
  int m_nColumns; // eax
  CDmAttribute *v8; // ecx
  CDmAttribute *v9; // ecx
  CUtlBinaryBlock *v10; // edi
  int v11; // eax
  CDmAttribute *m_pAttribute; // ecx
  CUtlBinaryBlock *v13; // edi
  int MemRequired; // eax
  const ImageFormatInfo_t *v15; // eax
  char v16; // cl
  int m_nSlices; // [esp+10h] [ebp-8h] BYREF
  int value; // [esp+14h] [ebp-4h] BYREF

  m_Mode = this->m_Mode;
  v5 = ((_BYTE)bFloatBitmap == 0) + 1;
  if ( v5 != m_Mode )
  {
    this->m_Mode = v5;
    v6 = v5 - 1;
    if ( v6 != 0 )
    {
      if ( v6 == 1 )
      {
        if ( bDiscardContents || m_Mode != DMEIMAGE_STORAGE_FLOAT_BITMAP )
        {
          CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: false, bDiscardContents: false);
          m_pAttribute = this->m_Bits.m_pAttribute;
          this->m_bInModification = true;
          v13 = CDmAttribute::BeginModifyValueInPlace<CUtlBinaryBlock>(this: m_pAttribute, pHandle: &this->m_hModify);
          MemRequired = ImageLoader::GetMemRequired(
                          width: this->m_nWidth.m_Storage,
                          height: this->m_nHeight.m_Storage,
                          depth: this->m_nDepth.m_Storage,
                          imageFormat: (ImageFormat)this->m_nFormat.m_Storage,
                          mipmap: false,
                          pAdjustedHeight: nullptr);
          CUtlBinaryBlock::SetLength(this: v13, nLength: MemRequired);
        }
        else
        {
          m_nColumns = this->m_ComputeBits.m_nColumns;
          v8 = this->m_nWidth.m_pAttribute;
          bFloatBitmap = m_nColumns;
          CDmAttribute::SetValue<int>(this: v8, value: &bFloatBitmap);
          v9 = this->m_nHeight.m_pAttribute;
          value = this->m_ComputeBits.m_nRows;
          CDmAttribute::SetValue<int>(this: v9, &value);
          m_nSlices = this->m_ComputeBits.m_nSlices;
          CDmAttribute::SetValue<int>(this: this->m_nDepth.m_pAttribute, value: &m_nSlices);
          v10 = CDmeImage::BeginModification(this);
          v11 = CDmeImage::SizeInBytes(this);
          CUtlBinaryBlock::SetLength(this: v10, nLength: v11);
          FloatBitMap_t::WriteToBuffer(
            this: &this->m_ComputeBits,
            pBuffer: (RGBA8888_t *)v10->m_Memory.m_pMemory,
            nBufSize: v10->m_nActualLength,
            fmt: (ImageFormat)this->m_nFormat.m_Storage,
            flGamma: this->m_flGamma.m_Storage);
        }
        CDmeImage::EndModification(this);
        CSOAContainer::~CSOAContainer(this: &this->m_ComputeBits);
      }
    }
    else
    {
      v15 = ImageLoader::ImageFormatInfo(fmt: (ImageFormat)this->m_nFormat.m_Storage);
      v16 = v15->m_nNumRedBits != 0;
      if ( v15->m_nNumGreenBits != 0 )
        v16 |= 2u;
      if ( v15->m_nNumBlueBits != 0 )
        v16 |= 4u;
      if ( v15->m_nNumAlphaBits != 0 )
        v16 |= 8u;
      FloatBitMap_t::Init(
        this: &this->m_ComputeBits,
        nXSize: this->m_nWidth.m_Storage,
        nYSize: this->m_nHeight.m_Storage,
        nZSize: this->m_nDepth.m_Storage,
        nAttributeMask: v16);
      if ( !bDiscardContents && m_Mode == DMEIMAGE_STORAGE_ATTRIBUTE )
        FloatBitMap_t::LoadFromBuffer(
          this: &this->m_ComputeBits,
          pBuffer: (const RGBA8888_t *)this->m_Bits.m_Storage.m_Memory.m_pMemory,
          nBufSize: this->m_Bits.m_Storage.m_nActualLength,
          fmt: (ImageFormat)this->m_nFormat.m_Storage,
          flGamma: this->m_flGamma.m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093910
// Name: public: void CDmeImage::ConvertFormat(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::ConvertFormat(CDmeImage *this, ImageFormat fmt)
{
  ImageFormat v3; // edi
  CDmAttribute *m_pAttribute; // ecx

  v3 = fmt;
  if ( fmt != this->m_nFormat.m_Storage
    && (*((_BYTE *)ImageLoader::ImageFormatInfo(fmt: (ImageFormat)this->m_nFormat.m_Storage) + 11) & 1) == 0
    && (*((_BYTE *)ImageLoader::ImageFormatInfo(fmt: v3) + 11) & 1) == 0 )
  {
    if ( this->m_Mode == DMEIMAGE_STORAGE_ATTRIBUTE )
      CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 1, bDiscardContents: false);
    m_pAttribute = this->m_nFormat.m_pAttribute;
    fmt = v3;
    CDmAttribute::SetValue<int>(this: m_pAttribute, value: (int *)&fmt);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093970
// Name: public: void CDmeImage::QuarterSize(class CDmeImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::QuarterSize(CDmeImage *this, float pSrcImage)
{
  CDmeImage *v3; // edi
  CDmAttribute *m_pAttribute; // ecx

  CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 1, bDiscardContents: true);
  v3 = (CDmeImage *)LODWORD(pSrcImage);
  CDmeImage::SetFloatBitmapStorageMode(this: (CDmeImage *)LODWORD(pSrcImage), bFloatBitmap: 1, bDiscardContents: false);
  FloatBitMap_t::QuarterSize(this: &v3->m_ComputeBits, pBitmap: &this->m_ComputeBits);
  pSrcImage = *(float *)&v3->m_nFormat.m_Storage;
  CDmAttribute::SetValue<int>(this: this->m_nFormat.m_pAttribute, value: (int *)&pSrcImage);
  m_pAttribute = this->m_flGamma.m_pAttribute;
  pSrcImage = v3->m_flGamma.m_Storage;
  CDmAttribute::SetValue<float>(this: m_pAttribute, value: &pSrcImage);
}

//------------------------------------------------------------------------------
// Address: 0x100939D0
// Name: public: void CDmeImage::DownsampleNiceFiltered(struct DownsampleInfo_t const __near &,class CDmeImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::DownsampleNiceFiltered(CDmeImage *this, const DownsampleInfo_t *info, float pSrcImage)
{
  CDmeImage *v4; // edi
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v6; // ecx

  CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 1, bDiscardContents: true);
  v4 = (CDmeImage *)LODWORD(pSrcImage);
  CDmeImage::SetFloatBitmapStorageMode(this: (CDmeImage *)LODWORD(pSrcImage), bFloatBitmap: 1, bDiscardContents: false);
  FloatBitMap_t::DownsampleNiceFiltered(
    this: &v4->m_ComputeBits,
    downsampleInfo: info,
    pDestBitmap: &this->m_ComputeBits);
  m_pAttribute = this->m_nFormat.m_pAttribute;
  pSrcImage = *(float *)&v4->m_nFormat.m_Storage;
  CDmAttribute::SetValue<int>(this: m_pAttribute, value: (int *)&pSrcImage);
  v6 = this->m_flGamma.m_pAttribute;
  pSrcImage = v4->m_flGamma.m_Storage;
  CDmAttribute::SetValue<float>(this: v6, value: &pSrcImage);
}

//------------------------------------------------------------------------------
// Address: 0x10093A40
// Name: public: virtual void CDmeImage::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::OnAttributeChanged(CDmeImage *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_Bits.m_pAttribute
    && !this->m_bIgnoreChangedBitsAttribute
    && this->m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
  {
    CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 0, bDiscardContents: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093A70
// Name: public: virtual void CDmeImage::OnElementUnserialized(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::OnElementUnserialized(CDmeImage *this)
{
  if ( this->m_Mode != DMEIMAGE_STORAGE_ATTRIBUTE )
    CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 0, bDiscardContents: true);
}

//------------------------------------------------------------------------------
// Address: 0x10093A90
// Name: public: virtual void CDmeImage::OnElementSerialized(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::OnElementSerialized(CDmeImage *this)
{
  if ( this->m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 0, bDiscardContents: false);
}

//------------------------------------------------------------------------------
// Address: 0x10093AB0
// Name: public: void CDmeImage::Init(int,int,int,enum ImageFormat,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::Init(CDmeImage *this, int nWidth, int nHeight, int nDepth, ImageFormat fmt, float flGamma)
{
  CUtlBinaryBlock value; // [esp+4h] [ebp-10h] BYREF

  if ( this->m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    CSOAContainer::~CSOAContainer(this: &this->m_ComputeBits);
  CUtlBinaryBlock::CUtlBinaryBlock(this: &value, pMemory: nullptr, nSizeInBytes: 0);
  CDmAttribute::SetValue<CUtlBinaryBlock>(this: this->m_Bits.m_pAttribute, &value);
  value.m_nActualLength = 0;
  if ( value.m_Memory.m_nGrowSize >= 0 && value.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: value.m_Memory.m_pMemory);
  CDmAttribute::SetValue<int>(this: this->m_nWidth.m_pAttribute, value: &nWidth);
  CDmAttribute::SetValue<int>(this: this->m_nHeight.m_pAttribute, value: &nHeight);
  CDmAttribute::SetValue<int>(this: this->m_nDepth.m_pAttribute, value: &nDepth);
  CDmAttribute::SetValue<int>(this: this->m_nFormat.m_pAttribute, value: (int *)&fmt);
  CDmAttribute::SetValue<float>(this: this->m_flGamma.m_pAttribute, value: &flGamma);
  this->m_Mode = DMEIMAGE_STORAGE_NONE;
}

//------------------------------------------------------------------------------
// Address: 0x10093B60
// Name: public: void CDmeImage::CompressImage(class CDmeImage __near *,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::CompressImage(CDmeImage *this, CDmeImage *pSrcImage, ImageFormat fmt)
{
  CDmeImage::StorageMode_t m_Mode; // eax
  int m_nSlices; // edx
  int m_nRows; // ecx
  int m_nColumns; // eax
  CDmAttribute *m_pAttribute; // ecx
  CUtlBinaryBlock *v10; // ebx
  int MemRequired; // eax
  int i; // ebx
  int v13; // eax
  CDmAttribute *v14; // ecx
  int v15; // [esp-8h] [ebp-24h]
  char *flGamma; // [esp+0h] [ebp-1Ch]
  int nDstFaceStride; // [esp+10h] [ebp-Ch]
  int nSrcFaceStride; // [esp+14h] [ebp-8h]
  float *pDstData; // [esp+18h] [ebp-4h]
  unsigned __int8 *pSrcData; // [esp+24h] [ebp+8h]

  if ( (*((_BYTE *)ImageLoader::ImageFormatInfo(fmt: (ImageFormat)pSrcImage->m_nFormat.m_Storage) + 11) & 1) == 0
    && (*((_BYTE *)ImageLoader::ImageFormatInfo(fmt) + 11) & 1) != 0 )
  {
    m_Mode = pSrcImage->m_Mode;
    if ( m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
      m_nSlices = pSrcImage->m_ComputeBits.m_nSlices;
    else
      m_nSlices = pSrcImage->m_nDepth.m_Storage;
    if ( m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
      m_nRows = pSrcImage->m_ComputeBits.m_nRows;
    else
      m_nRows = pSrcImage->m_nHeight.m_Storage;
    if ( m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
      m_nColumns = pSrcImage->m_ComputeBits.m_nColumns;
    else
      m_nColumns = pSrcImage->m_nWidth.m_Storage;
    CDmeImage::Init(
      this,
      nWidth: m_nColumns,
      nHeight: m_nRows,
      nDepth: m_nSlices,
      fmt,
      flGamma: pSrcImage->m_flGamma.m_Storage);
    CDmeImage::ConvertFormat(this: pSrcImage, fmt: IMAGE_FORMAT_RGBA8888);
    nSrcFaceStride = ImageLoader::GetMemRequired(
                       width: pSrcImage->m_nWidth.m_Storage,
                       height: pSrcImage->m_nHeight.m_Storage,
                       depth: 1,
                       imageFormat: (ImageFormat)pSrcImage->m_nFormat.m_Storage,
                       mipmap: false,
                       pAdjustedHeight: nullptr);
    nDstFaceStride = ImageLoader::GetMemRequired(
                       width: this->m_nWidth.m_Storage,
                       height: this->m_nHeight.m_Storage,
                       depth: 1,
                       imageFormat: (ImageFormat)this->m_nFormat.m_Storage,
                       mipmap: false,
                       pAdjustedHeight: nullptr);
    CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 0, bDiscardContents: false);
    m_pAttribute = this->m_Bits.m_pAttribute;
    this->m_bInModification = true;
    v10 = CDmAttribute::BeginModifyValueInPlace<CUtlBinaryBlock>(this: m_pAttribute, pHandle: &this->m_hModify);
    MemRequired = ImageLoader::GetMemRequired(
                    width: this->m_nWidth.m_Storage,
                    height: this->m_nHeight.m_Storage,
                    depth: this->m_nDepth.m_Storage,
                    imageFormat: (ImageFormat)this->m_nFormat.m_Storage,
                    mipmap: false,
                    pAdjustedHeight: nullptr);
    CUtlBinaryBlock::SetLength(this: v10, nLength: MemRequired);
    CDmeImage::SetFloatBitmapStorageMode(this: pSrcImage, bFloatBitmap: 0, bDiscardContents: false);
    pSrcData = pSrcImage->m_Bits.m_Storage.m_Memory.m_pMemory;
    pDstData = (float *)v10->m_Memory.m_pMemory;
    for ( i = 0; i < CDmeImage::Depth(this); ++i )
    {
      v15 = CDmeImage::Height(this: pSrcImage);
      v13 = CDmeImage::Width(this: pSrcImage);
      ImageLoader::ConvertImageFormat(
        a1: (int)pSrcImage,
        src: (float16 *)pSrcData,
        srcImageFormat: (ImageFormat)pSrcImage->m_nFormat.m_Storage,
        dst: pDstData,
        dstImageFormat: fmt,
        width: v13,
        height: v15,
        srcStride: 0,
        dstStride: 0);
      pSrcData += nSrcFaceStride;
      pDstData = (float *)((char *)pDstData + nDstFaceStride);
    }
    v14 = this->m_Bits.m_pAttribute;
    flGamma = (char *)this->m_hModify;
    this->m_bInModification = false;
    this->m_bIgnoreChangedBitsAttribute = true;
    CDmAttribute::EndModifyValueInPlace<CUtlBinaryBlock>(this: v14, handle: flGamma);
    this->m_bIgnoreChangedBitsAttribute = false;
    this->m_hModify = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093D10
// Name: public: void CDmeImage::SetImageBits(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::SetImageBits(CDmeImage *this, const void *pBits, int nSize)
{
  CUtlBinaryBlock value; // [esp+4h] [ebp-10h] BYREF

  CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 0, bDiscardContents: true);
  CUtlBinaryBlock::CUtlBinaryBlock(this: &value, pMemory: pBits, nSizeInBytes: nSize);
  CDmAttribute::SetValue<CUtlBinaryBlock>(this: this->m_Bits.m_pAttribute, &value);
  value.m_nActualLength = 0;
  if ( value.m_Memory.m_nGrowSize >= 0 && value.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: value.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10093D70
// Name: public: class CDmeImage __near * CDmeImageArray::GetImage(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeImage *__thiscall CDmeImageArray::GetImage(CDmeImageArray *this, int nIndex)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Images.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeImage::m_classType) )
    return (CDmeImage *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10093DC0
// Name: public: bool CDmeImageArray::IsConsistent(int,int,int,enum ImageFormat)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeImageArray::IsConsistent(
        CDmeImageArray *this,
        CDmElement_vtbl *nWidth,
        int nHeight,
        int nDepth,
        CDmAttribute *fmt)
{
  bool result; // al
  CDmElement *v6; // eax
  CDmElement *v7; // esi
  int v8; // ecx
  CDmElement_vtbl *v9; // eax
  int v10; // eax
  int v11; // esi

  if ( this->m_Images.m_Storage.m_Size == 0 )
    return true;
  v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Images.m_Storage.m_Memory.m_pMemory);
  v7 = v6;
  if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeImage::m_classType) )
    v7 = nullptr;
  v8 = *((_DWORD *)&v7[1] + 16);
  if ( v8 == 1 )
    v9 = *(CDmElement_vtbl **)v7[2].m_Id.m_Value;
  else
    v9 = v7[1].__vftable;
  result = false;
  if ( nWidth == v9 )
  {
    v10 = v8 == 1 ? *(_DWORD *)&v7[2].m_Id.m_Value[4] : *(_DWORD *)&v7[1].m_Id.m_Value[4];
    if ( nHeight == v10 && fmt == v7[1].m_Name.m_pAttribute )
    {
      v11 = v8 == 1 ? *(_DWORD *)&v7[2].m_Id.m_Value[8] : *(_DWORD *)&v7[1].m_Id.m_Value[12];
      if ( nDepth == v11 )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10093E70
// Name: public: void CDmeImageArray::AddImage(class CDmeImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImageArray::AddImage(CDmeImageArray *this, CDmeImage *pImage)
{
  CVTFTexture *v2; // esi
  CDmeImage::StorageMode_t m_Mode; // eax
  int m_nSlices; // edx
  int m_nRows; // ecx
  CDmElement_vtbl *m_nColumns; // eax

  v2 = (CVTFTexture *)pImage;
  m_Mode = pImage->m_Mode;
  if ( m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    m_nSlices = pImage->m_ComputeBits.m_nSlices;
  else
    m_nSlices = pImage->m_nDepth.m_Storage;
  if ( m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    m_nRows = pImage->m_ComputeBits.m_nRows;
  else
    m_nRows = pImage->m_nHeight.m_Storage;
  if ( m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    m_nColumns = (CDmElement_vtbl *)pImage->m_ComputeBits.m_nColumns;
  else
    m_nColumns = (CDmElement_vtbl *)pImage->m_nWidth.m_Storage;
  if ( CDmeImageArray::IsConsistent(
         this,
         nWidth: m_nColumns,
         nHeight: m_nRows,
         nDepth: m_nSlices,
         fmt: (CDmAttribute *)pImage->m_nFormat.m_Storage) )
  {
    pImage = (CDmeImage *)CVTFTexture::MipCount(this: v2);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &this->m_Images,
      src: (DmElementHandle_t *)&pImage);
  }
  else
  {
    _Warning(a1: "Attempted to add different size/format images to the image array!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093F00
// Name: public: class CDmeImage __near * CDmeImageArray::AddImage(void)
// Source: json
//------------------------------------------------------------------------------
CDmeImage *__thiscall CDmeImageArray::AddImage(CDmeImageArray *this)
{
  DmElementHandle_t v2; // eax
  CDmElement *v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // edi
  float *v6; // eax
  int v7; // ecx
  float flGamma; // xmm0_4
  ImageFormat v9; // esi
  int v10; // edi
  int v11; // edx
  int v12; // eax
  CDmeImage *pImage; // [esp+2Ch] [ebp-4h]

  v2 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeImage::m_classType.u.m_Id,
         a3: "image",
         a4: this->m_fileId,
         a5: nullptr);
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
  if ( v3 == nullptr || (pImage = (CDmeImage *)v3, !v3->IsA(this: v3, a2: CDmeImage::m_classType)) )
    pImage = nullptr;
  if ( this->m_Images.m_Storage.m_Size > 0 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Images.m_Storage.m_Memory.m_pMemory);
    v5 = v4;
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeImage::m_classType) )
      v6 = (float *)v5;
    else
      v6 = nullptr;
    v7 = *((_DWORD *)v6 + 33);
    flGamma = v6[25];
    v9 = *((_DWORD *)v6 + 23);
    if ( v7 == 1 )
      v10 = *((_DWORD *)v6 + 37);
    else
      v10 = *((_DWORD *)v6 + 21);
    if ( v7 == 1 )
      v11 = *((_DWORD *)v6 + 36);
    else
      v11 = *((_DWORD *)v6 + 19);
    if ( v7 == 1 )
      v12 = *((_DWORD *)v6 + 35);
    else
      v12 = *((_DWORD *)v6 + 17);
    CDmeImage::Init(this: pImage, nWidth: v12, nHeight: v11, nDepth: v10, fmt: v9, flGamma);
  }
  CDmeImageArray::AddImage(this, pImage);
  return pImage;
}

//------------------------------------------------------------------------------
// Address: 0x10094010
// Name: public: int CDmeImageArray::Width(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement_vtbl *__thiscall CDmeImageArray::Width(CDmeImageArray *this)
{
  CDmElement *v1; // eax
  CDmElement *v2; // esi

  if ( this->m_Images.m_Storage.m_Size <= 0 )
    return (CDmElement_vtbl *)-1;
  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Images.m_Storage.m_Memory.m_pMemory);
  v2 = v1;
  if ( v1 == nullptr || !v1->IsA(this: v1, a2: CDmeImage::m_classType) )
    v2 = nullptr;
  if ( *((_DWORD *)&v2[1] + 16) == 1 )
    return *(CDmElement_vtbl **)v2[2].m_Id.m_Value;
  else
    return v2[1].__vftable;
}

//------------------------------------------------------------------------------
// Address: 0x10094070
// Name: public: int CDmeImageArray::Height(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImageArray::Height(CDmeImageArray *this)
{
  CDmElement *v1; // eax
  CDmElement *v2; // esi

  if ( this->m_Images.m_Storage.m_Size <= 0 )
    return -1;
  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Images.m_Storage.m_Memory.m_pMemory);
  v2 = v1;
  if ( v1 == nullptr || !v1->IsA(this: v1, a2: CDmeImage::m_classType) )
    v2 = nullptr;
  if ( *((_DWORD *)&v2[1] + 16) == 1 )
    return *(_DWORD *)&v2[2].m_Id.m_Value[4];
  else
    return *(_DWORD *)&v2[1].m_Id.m_Value[4];
}

//------------------------------------------------------------------------------
// Address: 0x100940D0
// Name: public: int CDmeImageArray::Depth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImageArray::Depth(CDmeImageArray *this)
{
  CDmElement *v1; // eax
  CDmElement *v2; // esi

  if ( this->m_Images.m_Storage.m_Size <= 0 )
    return -1;
  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Images.m_Storage.m_Memory.m_pMemory);
  v2 = v1;
  if ( v1 == nullptr || !v1->IsA(this: v1, a2: CDmeImage::m_classType) )
    v2 = nullptr;
  if ( *((_DWORD *)&v2[1] + 16) == 1 )
    return *(_DWORD *)&v2[2].m_Id.m_Value[8];
  else
    return *(_DWORD *)&v2[1].m_Id.m_Value[12];
}

//------------------------------------------------------------------------------
// Address: 0x10094130
// Name: public: enum ImageFormat CDmeImageArray::Format(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImageArray::Format(CDmeImageArray *this)
{
  CDmElement *v1; // eax
  CDmElement *v2; // esi

  if ( this->m_Images.m_Storage.m_Size <= 0 )
    return -1;
  v1 = g_pDataModel->GetElement(this: g_pDataModel, a2: *this->m_Images.m_Storage.m_Memory.m_pMemory);
  v2 = v1;
  if ( v1 == nullptr || !v1->IsA(this: v1, a2: CDmeImage::m_classType) )
    v2 = nullptr;
  return (int)v2[1].m_Name.m_pAttribute;
}

//------------------------------------------------------------------------------
// Address: 0x10094180
// Name: public: void CDmeImage::CopyFrom(class CDmeImage __near *,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::CopyFrom(CDmeImage *this, CDmeImage *pSrcImage, ImageFormat fmt)
{
  ImageFormat m_Storage; // ebx
  CDmeImage::StorageMode_t m_Mode; // eax
  int m_nSlices; // edx
  int m_nRows; // ecx
  int m_nColumns; // eax
  CDmeImage::StorageMode_t v10; // eax
  ImageFormat v11; // eax
  ImageFormat v12; // edx
  int MemRequired; // ebx
  CDmeImage::StorageMode_t v14; // eax
  int v15; // ebx
  int v16; // ecx
  int v17; // eax
  int v18; // ebx
  CDmAttribute *m_pAttribute; // ecx
  CDmeImage::StorageMode_t v20; // eax
  int v21; // ebx
  ImageFormat srcImageFormat; // [esp+10h] [ebp-Ch]
  ImageFormat dstImageFormat; // [esp+14h] [ebp-8h]
  CUtlBinaryBlock *bits; // [esp+18h] [ebp-4h]
  float *bitsa; // [esp+18h] [ebp-4h]
  CDmeImage *pSrcImagea; // [esp+24h] [ebp+8h]
  ImageFormat fmta; // [esp+28h] [ebp+Ch]

  m_Storage = fmt;
  if ( fmt == IMAGE_FORMAT_UNKNOWN )
    m_Storage = pSrcImage->m_nFormat.m_Storage;
  m_Mode = pSrcImage->m_Mode;
  if ( m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    m_nSlices = pSrcImage->m_ComputeBits.m_nSlices;
  else
    m_nSlices = pSrcImage->m_nDepth.m_Storage;
  if ( m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    m_nRows = pSrcImage->m_ComputeBits.m_nRows;
  else
    m_nRows = pSrcImage->m_nHeight.m_Storage;
  if ( m_Mode == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    m_nColumns = pSrcImage->m_ComputeBits.m_nColumns;
  else
    m_nColumns = pSrcImage->m_nWidth.m_Storage;
  CDmeImage::Init(
    this,
    nWidth: m_nColumns,
    nHeight: m_nRows,
    nDepth: m_nSlices,
    fmt: m_Storage,
    flGamma: pSrcImage->m_flGamma.m_Storage);
  v10 = pSrcImage->m_Mode;
  if ( v10 != DMEIMAGE_STORAGE_NONE )
  {
    if ( v10 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
    {
      CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 1, bDiscardContents: true);
      CDmeImage::SetFloatBitmapStorageMode(this: pSrcImage, bFloatBitmap: 1, bDiscardContents: false);
      FloatBitMap_t::LoadFromFloatBitmap(this: &this->m_ComputeBits, pOrig: &pSrcImage->m_ComputeBits);
    }
    else
    {
      v11 = pSrcImage->m_nFormat.m_Storage;
      v12 = this->m_nFormat.m_Storage;
      if ( v11 == v12 )
      {
        MemRequired = ImageLoader::GetMemRequired(
                        width: pSrcImage->m_nWidth.m_Storage,
                        height: pSrcImage->m_nHeight.m_Storage,
                        depth: pSrcImage->m_nDepth.m_Storage,
                        imageFormat: v11,
                        mipmap: false,
                        pAdjustedHeight: nullptr);
        CDmeImage::SetFloatBitmapStorageMode(this: pSrcImage, bFloatBitmap: 0, bDiscardContents: false);
        CDmeImage::SetImageBits(this, pBits: pSrcImage->m_Bits.m_Storage.m_Memory.m_pMemory, nSize: MemRequired);
      }
      else
      {
        v14 = this->m_Mode;
        if ( v14 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
          v15 = this->m_ComputeBits.m_nSlices;
        else
          v15 = this->m_nDepth.m_Storage;
        if ( v14 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
          v16 = this->m_ComputeBits.m_nRows;
        else
          v16 = this->m_nHeight.m_Storage;
        if ( v14 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
          v17 = this->m_ComputeBits.m_nColumns;
        else
          v17 = this->m_nWidth.m_Storage;
        v18 = ImageLoader::GetMemRequired(
                width: v17,
                height: v16,
                depth: v15,
                nMipmapCount: 1,
                imageFormat: v12,
                pAdjustedHeight: nullptr);
        CDmeImage::SetFloatBitmapStorageMode(this, bFloatBitmap: 0, bDiscardContents: false);
        m_pAttribute = this->m_Bits.m_pAttribute;
        this->m_bInModification = true;
        bits = CDmAttribute::BeginModifyValueInPlace<CUtlBinaryBlock>(this: m_pAttribute, pHandle: &this->m_hModify);
        CUtlBinaryBlock::SetLength(this: bits, nLength: v18);
        v20 = this->m_Mode;
        if ( v20 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
          fmta = this->m_ComputeBits.m_nRows;
        else
          fmta = this->m_nHeight.m_Storage;
        if ( v20 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
          v21 = this->m_ComputeBits.m_nSlices;
        else
          v21 = this->m_nDepth.m_Storage;
        if ( v20 == DMEIMAGE_STORAGE_FLOAT_BITMAP )
          pSrcImagea = (CDmeImage *)this->m_ComputeBits.m_nColumns;
        else
          pSrcImagea = (CDmeImage *)this->m_nWidth.m_Storage;
        dstImageFormat = this->m_nFormat.m_Storage;
        bitsa = (float *)bits->m_Memory.m_pMemory;
        srcImageFormat = pSrcImage->m_nFormat.m_Storage;
        CDmeImage::SetFloatBitmapStorageMode(this: pSrcImage, bFloatBitmap: 0, bDiscardContents: false);
        ImageLoader::ConvertImageFormat(
          a1: (int)pSrcImage,
          src: (float16 *)pSrcImage->m_Bits.m_Storage.m_Memory.m_pMemory,
          srcImageFormat,
          dst: bitsa,
          dstImageFormat,
          width: (int)pSrcImagea,
          height: fmta * v21,
          srcStride: 0,
          dstStride: 0);
        CDmeImage::EndModification(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100943E0
// Name: protected: CDmeImage::CDmeImage(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeImage *__thiscall CDmeImage::CDmeImage(
        CDmeImage *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeImage_vtbl *)&CDmeImage::`vftable';
  this->m_nWidth.m_pAttribute = nullptr;
  this->m_nWidth.m_Storage = 0;
  this->m_nHeight.m_pAttribute = nullptr;
  this->m_nHeight.m_Storage = 0;
  this->m_nDepth.m_pAttribute = nullptr;
  this->m_nDepth.m_Storage = 0;
  this->m_nFormat.m_pAttribute = nullptr;
  this->m_nFormat.m_Storage = 0;
  this->m_flGamma = 0;
  CUtlBinaryBlock::CUtlBinaryBlock(this: &this->m_Bits.m_Storage, growSize: 0, initSize: 0);
  this->m_Bits.m_pAttribute = nullptr;
  CUtlBinaryBlock::Set(this: &this->m_Bits.m_Storage, pValue: nullptr, nLen: 0);
  memset(
    dst: (unsigned __int8 *)this->m_ComputeBits.m_nDataType,
    value: 0xFFu,
    count: sizeof(this->m_ComputeBits.m_nDataType));
  memset(
    dst: (unsigned __int8 *)this->m_ComputeBits.m_pSeparateDataMemory,
    value: 0,
    count: sizeof(this->m_ComputeBits.m_pSeparateDataMemory));
  this->m_ComputeBits.m_pConstantDataMemory = nullptr;
  this->m_ComputeBits.m_pDataMemory = nullptr;
  this->m_ComputeBits.m_nNumQuadsPerRow = 0;
  this->m_ComputeBits.m_nSlices = 0;
  this->m_ComputeBits.m_nRows = 0;
  this->m_ComputeBits.m_nPaddedColumns = 0;
  this->m_ComputeBits.m_nColumns = 0;
  this->m_ComputeBits.m_nFieldPresentMask = 0;
  this->m_ComputeBits.m_eThreadMode = SOATHREADMODE_NONE;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100944B0
// Name: public: virtual bool CDmeImage::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeImage::IsA(CDmeImage *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeImage::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x100944E0
// Name: public: virtual int CDmeImage::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImage::GetInheritanceDepth(CDmeImage *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeImage::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10094520
// Name: protected: virtual int CDmeImage::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImage::AllocatedSize(CDmeImage *this)
{
  return 944;
}

//------------------------------------------------------------------------------
// Address: 0x10094530
// Name: protected: virtual void CDmeImage::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImage::PerformConstruction(CDmeImage *this)
{
  CDmElementFramework::Disconnect((CDmeTexture *)this);
  CDmeImage::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x10094650
// Name: public: virtual bool CDmeImageArray::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeImageArray::IsA(CDmeImageArray *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeImageArray::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10094680
// Name: public: virtual int CDmeImageArray::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeImageArray::GetInheritanceDepth(CDmeImageArray *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeImageArray::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100946C0
// Name: protected: virtual void CDmeImageArray::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeImageArray::PerformConstruction(CDmeImageArray *this)
{
  CDmElementFramework::Disconnect((CDmeTexture *)this);
  this->m_Images.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "images",
                                  type: AT_FIRST_ARRAY_TYPE,
                                  pMemory: &this->m_Images);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Images.m_pAttribute, typeSymbol: CDmeImage::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x100C4B60
// Name: _dynamic_initializer_for__CDmeImage::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeImage::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeImage::s_Allocator,
    blockSize: 944,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeImage pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeImage::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4BC0
// Name: _dynamic_initializer_for__CDmeImageArray::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeImageArray::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeImageArray::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeImageArray pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeImageArray::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x100C5330
// Name: _dynamic_atexit_destructor_for__CDmeImage::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeImage::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeImage::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x100C5340
// Name: _dynamic_atexit_destructor_for__CDmeImageArray::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeImageArray::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeImageArray::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x100C4B90
// Name: _dynamic_initializer_for__g_CDmeImage_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeImage_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeImage_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4BA0
// Name: _dynamic_initializer_for__g_CDmeImage_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeImage_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeImage_Helper,
           classname: "DmeImage",
           pFactory: &g_CDmeImage_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x100C4BF0
// Name: _dynamic_initializer_for__g_CDmeImageArray_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeImageArray_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeImageArray_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4C00
// Name: _dynamic_initializer_for__g_CDmeImageArray_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeImageArray_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeImageArray_Helper,
           classname: "DmeImageArray",
           pFactory: &g_CDmeImageArray_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x100C5350
// Name: _dynamic_atexit_destructor_for__g_CDmeImageArray_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeImageArray_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeImageArray_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x100C5360
// Name: _dynamic_atexit_destructor_for__g_CDmeImage_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeImage_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeImage_Factory.m_CallBackList);
}

} // namespace vtex_dll
