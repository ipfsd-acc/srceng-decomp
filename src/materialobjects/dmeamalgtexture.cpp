// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialobjects/dmeamalgtexture.cpp
// Functions: 52
// ============================================================

#include "materialobjects\dmeamalgtexture.h"

//------------------------------------------------------------------------------
// Address: 0x0045F520
// Name: public: void FloatBitMap_t::Init(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::Init(FloatBitMap_t *this, int nXSize, int nYSize, int nZSize, char nAttributeMask)
{
  CSOAContainer::PurgeData(this);
  CSOAContainer::SetAttributeType(this, nAttrIdx: 0, nDataType: ATTRDATATYPE_FLOAT, bAllocateMemory: nAttributeMask & 1);
  CSOAContainer::SetAttributeType(
    this,
    nAttrIdx: 1,
    nDataType: ATTRDATATYPE_FLOAT,
    bAllocateMemory: (nAttributeMask & 2) != 0);
  CSOAContainer::SetAttributeType(
    this,
    nAttrIdx: 2,
    nDataType: ATTRDATATYPE_FLOAT,
    bAllocateMemory: (nAttributeMask & 4) != 0);
  CSOAContainer::SetAttributeType(
    this,
    nAttrIdx: 3,
    nDataType: ATTRDATATYPE_FLOAT,
    bAllocateMemory: (nAttributeMask & 8) != 0);
  CSOAContainer::AllocateData(this, nNCols: nXSize, nNRows: nYSize, nSlices: nZSize);
  if ( (nAttributeMask & 8) == 0 )
    CSOAContainer::FillAttr(this, nAttr: 3, flValue: 1.0);
}

//------------------------------------------------------------------------------
// Address: 0x0045F5C0
// Name: public: int FloatBitMap_t::ComputeValidAttributeList(int __near * const)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall FloatBitMap_t::ComputeValidAttributeList(FloatBitMap_t *this, int *pIndex)
{
  int result; // eax

  result = 0;
  if ( (this->m_nFieldPresentMask & 1) != 0 )
  {
    *pIndex = 0;
    result = 1;
  }
  if ( (this->m_nFieldPresentMask & 2) != 0 )
    pIndex[result++] = 1;
  if ( (this->m_nFieldPresentMask & 4) != 0 )
    pIndex[result++] = 2;
  if ( (this->m_nFieldPresentMask & 8) != 0 )
    pIndex[result++] = 3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045F620
// Name: GetChannelIndexFromChar
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetChannelIndexFromChar(char c)
{
  int v1; // eax

  strchr(string: (unsigned __int8 *)s_ChannelIDs, chr: c);
  if ( v1 != 0 )
    return v1 - (_DWORD)s_ChannelIDs;
  _Warning(a1: " bad channel name '%c'\n", c);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0045F660
// Name: void GetFullPathUsingMaterialsrcContent(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetFullPathUsingMaterialsrcContent(const char *fname, char *pFullTGAFileNameDest, int fullPathBufferSize)
{
  char localTexturePath[260]; // [esp+4h] [ebp-104h] BYREF

  V_snprintf(pDest: localTexturePath, maxLen: 260, pFormat: "materialsrc\\%s", fname);
  if ( g_pFullFileSystem->RelativePathToFullPath(
         this: g_pFullFileSystem,
         a2: localTexturePath,
         a3: "CONTENT",
         a4: pFullTGAFileNameDest,
         a5: fullPathBufferSize,
         a6: 0,
         a7: 0) == nullptr )
    _Warning(a1: "CDataModel: Unable to generate full path for file %s\n", fname);
}

//------------------------------------------------------------------------------
// Address: 0x0045F6D0
// Name: ZeroChannel
// Source: json
//------------------------------------------------------------------------------
void __fastcall ZeroChannel(int nDestChannel, FloatBitMap_t *pBitmap, FloatBitMap_t *newBitmap)
{
  FloatBitMap_t *v3; // ebx
  int v4; // edi
  int m_nColumns; // esi
  int v6; // eax

  v3 = newBitmap;
  v4 = 0;
  if ( newBitmap->m_nRows > 0 )
  {
    m_nColumns = newBitmap->m_nColumns;
    do
    {
      v6 = 0;
      if ( m_nColumns > 0 )
      {
        do
        {
          *(_DWORD *)&pBitmap->m_pAttributePtrs[nDestChannel][v6 * pBitmap->m_nStrideInBytes[nDestChannel]
                                                            + v4 * pBitmap->m_nRowStrideInBytes[nDestChannel]] = 0;
          v3 = newBitmap;
          m_nColumns = newBitmap->m_nColumns;
          ++v6;
        }
        while ( v6 < newBitmap->m_nColumns );
      }
      ++v4;
    }
    while ( v4 < v3->m_nRows );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F730
// Name: CopyChannel
// Source: json
//------------------------------------------------------------------------------
void __usercall CopyChannel(FloatBitMap_t *newBitmap@<eax>, FloatBitMap_t *pBitmap, int nSrcChannel, int nDestChannel)
{
  int v4; // edx
  int v5; // esi
  int m_nColumns; // edi
  int v7; // ecx
  double v8; // st7
  unsigned int v9; // ebx
  unsigned int v10; // ecx
  int x; // [esp+4h] [ebp-8h]
  int y; // [esp+8h] [ebp-4h]

  v4 = nSrcChannel;
  v5 = nDestChannel;
  y = 0;
  if ( newBitmap->m_nRows > 0 )
  {
    m_nColumns = newBitmap->m_nColumns;
    do
    {
      v7 = 0;
      x = 0;
      if ( m_nColumns > 0 )
      {
        do
        {
          v8 = *(float *)&newBitmap->m_pAttributePtrs[v4][v7 * newBitmap->m_nStrideInBytes[v4]
                                                        + y * newBitmap->m_nRowStrideInBytes[v4]];
          v9 = v7 * pBitmap->m_nStrideInBytes[v5];
          v10 = y * pBitmap->m_nRowStrideInBytes[v5];
          v5 = nDestChannel;
          v4 = nSrcChannel;
          *(float *)&pBitmap->m_pAttributePtrs[nDestChannel][v10 + v9] = v8;
          m_nColumns = newBitmap->m_nColumns;
          v7 = x + 1;
          x = v7;
        }
        while ( v7 < newBitmap->m_nColumns );
      }
      ++y;
    }
    while ( y < newBitmap->m_nRows );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F7D0
// Name: protected: void CDmeAmalgamatedTexture::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAmalgamatedTexture::OnConstruction(CDmeAmalgamatedTexture *this)
{
  CDmaElementArray<CDmeSheetImage> *p_m_ImageList; // edi
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  p_m_ImageList = &this->m_ImageList;
  this->m_ImageList.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "images",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_ImageList);
  CDmAttribute::SetElementTypeSymbol(this: p_m_ImageList->m_pAttribute, typeSymbol: CDmeSheetImage::m_classType);
  value = 1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "packmode", type: AT_INT, pMemory: &this->m_ePackingMode);
  this->m_ePackingMode.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, &value);
  this->m_Sequences.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "sequences",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_Sequences);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Sequences.m_pAttribute, typeSymbol: CDmeSheetSequence::m_classType);
  this->m_nWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "width",
                                  type: AT_INT,
                                  pMemory: &this->m_nWidth);
  this->m_nHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "height",
                                   type: AT_INT,
                                   pMemory: &this->m_nHeight);
  this->m_pPackedImage.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "packedImage",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_pPackedImage);
  CDmAttribute::SetElementTypeSymbol(this: this->m_pPackedImage.m_pAttribute, typeSymbol: CDmeImage::m_classType);
  this->m_SequenceCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045F8C0
// Name: public: bool CDmeAmalgamatedTexture::WriteTGA(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeAmalgamatedTexture::WriteTGA(CDmeAmalgamatedTexture *this, const char *pFileName)
{
  CDmeImage *v3; // eax
  FloatBitMap_t *v4; // eax

  if ( pFileName != nullptr
    && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_pPackedImage.m_Storage.m_Handle) != nullptr
    && (v3 = (CDmeImage *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_pPackedImage.m_Storage.m_Handle),
        v4 = (FloatBitMap_t *)CDmeImage::FloatBitmap(this: v3),
        FloatBitMap_t::WriteTGAFile(this: v4, filename: pFileName)) )
  {
    _Msg(a1: "Ok: successfully saved TGA \"%s\"\n", pFileName);
    return 1;
  }
  else
  {
    _Msg(a1: "Error: failed to save TGA \"%s\"!\n", pFileName);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F940
// Name: void GetFullPathUsingCurrentDir(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetFullPathUsingCurrentDir(const char *fname, char *pFullTGAFileNameDest, int fullPathBufferSize)
{
  const char *v3; // eax
  char pDir[260]; // [esp+0h] [ebp-114h] BYREF
  CUtlString fullPathName; // [esp+104h] [ebp-10h] BYREF

  if ( g_pFullFileSystem->GetCurrentDirectory(this: g_pFullFileSystem, a2: pDir, a3: 260) )
  {
    CUtlString::CUtlString(this: &fullPathName, pString: pDir);
    CUtlString::operator+=(this: &fullPathName, rhs: "\\");
    CUtlString::operator+=(this: &fullPathName, rhs: fname);
    v3 = CUtlString::Get(this: &fullPathName);
    V_strncpy(pDest: pFullTGAFileNameDest, pSrc: v3, maxLen: fullPathBufferSize);
    fullPathName.m_Storage.m_nActualLength = 0;
    if ( fullPathName.m_Storage.m_Memory.m_nGrowSize >= 0 && fullPathName.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fullPathName.m_Storage.m_Memory.m_pMemory);
  }
  else
  {
    _Warning(a1: "CDataModel: Unable to generate full path for file %s\n", fname);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F9F0
// Name: private: bool CDmeAmalgamatedTexture::PackImagesFlat(bool,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeAmalgamatedTexture::PackImagesFlat(CDmeAmalgamatedTexture *this, bool bGenerateImage, int nWidth)
{
  CDmeAmalgamatedTexture *v3; // ebx
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  CDmeImage *v5; // eax
  FloatBitMap_t *v6; // eax
  FloatBitMap_t *v7; // esi
  int v8; // eax
  int v9; // edx
  CDmElement *v10; // eax
  CDmElement *v11; // edi
  CDmElement_vtbl *v12; // eax
  int v13; // ecx
  CDmElement_vtbl *v14; // eax
  FloatBitMap_t *v15; // ebx
  int valid; // eax
  bool v17; // cc
  int v18; // edx
  int v19; // ecx
  int v20; // eax
  double v21; // st7
  int v22; // ecx
  int v23; // edx
  int v24; // eax
  double v25; // st7
  int v26; // ecx
  int v27; // edx
  int v28; // eax
  double v29; // st7
  int v30; // ecx
  int v31; // edx
  int v32; // eax
  int v33; // edx
  double v34; // st7
  int v35; // ecx
  CDmElement_vtbl *v36; // edi
  int v37; // ebx
  int v38; // edx
  double v39; // st7
  unsigned int v40; // edx
  int *v41; // ecx
  CDmElement_vtbl *v42; // edi
  int v43; // eax
  int v44; // ecx
  int v45; // eax
  CDmeImage *v46; // eax
  const char *m_pAsString; // edi
  const char *v49; // eax
  CDmeImage *v50; // eax
  CDmeImage *v51; // eax
  DmElementHandle_t m_Handle; // [esp-4h] [ebp-5Ch]
  int ic[4]; // [esp+Ch] [ebp-4Ch] BYREF
  int v54; // [esp+1Ch] [ebp-3Ch]
  int v55; // [esp+20h] [ebp-38h]
  int w; // [esp+24h] [ebp-34h] BYREF
  int h; // [esp+28h] [ebp-30h] BYREF
  CDmeAmalgamatedTexture *v58; // [esp+2Ch] [ebp-2Ch]
  int nc; // [esp+30h] [ebp-28h]
  int max_column_written; // [esp+34h] [ebp-24h]
  int i; // [esp+38h] [ebp-20h]
  int next_line; // [esp+3Ch] [ebp-1Ch]
  int c; // [esp+40h] [ebp-18h]
  int x; // [esp+44h] [ebp-14h]
  CDmElement *v65; // [esp+48h] [ebp-10h]
  int cur_line; // [esp+4Ch] [ebp-Ch] BYREF
  int cur_column; // [esp+50h] [ebp-8h] BYREF
  int y; // [esp+54h] [ebp-4h]

  v3 = this;
  GetElement = g_pDataModel->GetElement;
  m_Handle = this->m_pPackedImage.m_Storage.m_Handle;
  v58 = this;
  v5 = (CDmeImage *)GetElement(this: g_pDataModel, a2: m_Handle);
  v6 = CDmeImage::BeginFloatBitmapModification(this: v5);
  v7 = v6;
  if ( bGenerateImage )
    FloatBitMap_t::Init(this: v6, nXSize: nWidth, nYSize: 2048, nZSize: 1, nAttributeMask: 15);
  v8 = 0;
  v9 = 0;
  cur_line = 0;
  cur_column = 0;
  next_line = 0;
  max_column_written = 0;
  i = 0;
  if ( v3->m_ImageList.m_Storage.m_Size <= 0 )
  {
LABEL_30:
    v44 = 1;
    h = 1;
    if ( v8 > 1 )
    {
      do
        v44 *= 2;
      while ( v44 < v8 );
      h = v44;
    }
    v45 = 1;
    w = 1;
    if ( v9 > 1 )
    {
      do
        v45 *= 2;
      while ( v45 < v9 );
      w = v45;
    }
    if ( bGenerateImage )
      FloatBitMap_t::Crop(this: v7, x1: 0, y1: 0, z1: 0, nWidth: v45, nHeight: v44, nDepth: 1);
    CDmAttribute::SetValue<int>(this: v3->m_nHeight.m_pAttribute, value: &h);
    CDmAttribute::SetValue<int>(this: v3->m_nWidth.m_pAttribute, value: &w);
    v46 = (CDmeImage *)g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_pPackedImage.m_Storage.m_Handle);
    CDmeImage::EndFloatBitmapModification(this: v46);
    return 1;
  }
  else
  {
    while ( 1 )
    {
      v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_ImageList.m_Storage.m_Memory.m_pMemory[i]);
      v11 = v10;
      if ( v10 == nullptr || !v10->IsA(this: v10, a2: CDmeSheetImage::m_classType) )
        v11 = nullptr;
      v12 = v11[1].__vftable;
      v65 = v11;
      if ( v12 == nullptr )
        break;
      v13 = cur_column;
      if ( (int)v12->OnAttributeChanged + cur_column > nWidth )
      {
        v13 = 0;
        cur_column = 0;
        cur_line = next_line;
      }
      v14 = v11[1].__vftable;
      if ( (int)v14->OnAttributeChanged + v13 > nWidth || (int)v14->OnAttributeArrayElementAdded + cur_line > 2048 )
      {
        v51 = (CDmeImage *)g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_pPackedImage.m_Storage.m_Handle);
        CDmeImage::EndFloatBitmapModification(this: v51);
        return 0;
      }
      CDmAttribute::SetValue<int>(this: *(CDmAttribute **)&v11[1].m_Id.m_Value[4], value: &cur_column);
      CDmAttribute::SetValue<int>(this: *(CDmAttribute **)&v11[1].m_Id.m_Value[12], value: &cur_line);
      if ( bGenerateImage )
      {
        v15 = (FloatBitMap_t *)v11[1].__vftable;
        valid = FloatBitMap_t::ComputeValidAttributeList(this: v15, pIndex: ic);
        v17 = v15->m_nRows <= 0;
        nc = valid;
        y = 0;
        if ( !v17 )
        {
          do
          {
            v18 = 0;
            x = 0;
            if ( v15->m_nColumns > 0 )
            {
              do
              {
                v19 = 0;
                c = 0;
                if ( valid >= 4 )
                {
                  v54 = valid - 3;
                  do
                  {
                    v20 = ic[v19];
                    v21 = *(float *)(y * *((_DWORD *)&v11[1].__vftable[7].IsA + v20)
                                   + v18 * *((_DWORD *)&v11[1].__vftable[5].OnAttributeChanged + v20)
                                   + *((_DWORD *)&v11[1].OnElementUnserialized + v20));
                    v22 = c;
                    v23 = v7->m_nRowStrideInBytes[v20] * (cur_line + y) + v7->m_nStrideInBytes[v20] * (cur_column + v18);
                    v55 = v20;
                    *(float *)&v7->m_pAttributePtrs[v20][v23] = v21;
                    v24 = ic[v22 + 1];
                    v25 = *(float *)(y * *((_DWORD *)&v65[1].__vftable[7].IsA + v24)
                                   + x * *((_DWORD *)&v65[1].__vftable[5].OnAttributeChanged + v24)
                                   + *((_DWORD *)&v65[1].OnElementUnserialized + v24));
                    v26 = c;
                    v27 = v7->m_nRowStrideInBytes[v24] * (cur_line + y) + v7->m_nStrideInBytes[v24] * (cur_column + x);
                    v55 = v24;
                    *(float *)&v7->m_pAttributePtrs[v24][v27] = v25;
                    v28 = ic[v26 + 2];
                    v29 = *(float *)(y * *((_DWORD *)&v65[1].__vftable[7].IsA + v28)
                                   + x * *((_DWORD *)&v65[1].__vftable[5].OnAttributeChanged + v28)
                                   + *((_DWORD *)&v65[1].OnElementUnserialized + v28));
                    v30 = c;
                    v31 = v7->m_nRowStrideInBytes[v28] * (cur_line + y) + v7->m_nStrideInBytes[v28] * (cur_column + x);
                    v55 = v28;
                    *(float *)&v7->m_pAttributePtrs[v28][v31] = v29;
                    v32 = ic[v30 + 3];
                    v33 = v7->m_nStrideInBytes[v32] * (cur_column + x);
                    v34 = *(float *)(y * *((_DWORD *)&v65[1].__vftable[7].IsA + v32)
                                   + x * *((_DWORD *)&v65[1].__vftable[5].OnAttributeChanged + v32)
                                   + *((_DWORD *)&v65[1].OnElementUnserialized + v32));
                    v55 = v32;
                    *(float *)&v7->m_pAttributePtrs[v32][v7->m_nRowStrideInBytes[v32] * (cur_line + y) + v33] = v34;
                    v11 = v65;
                    v18 = x;
                    v19 = c + 4;
                    c = v19;
                  }
                  while ( v19 < v54 );
                  valid = nc;
                }
                if ( v19 < valid )
                {
                  do
                  {
                    v35 = ic[v19];
                    v36 = v11[1].__vftable;
                    v37 = y * *((_DWORD *)&v36[7].IsA + v35) + v18 * *((_DWORD *)&v36[5].OnAttributeChanged + v35);
                    v38 = v7->m_nStrideInBytes[v35] * (cur_column + v18);
                    v55 = v35;
                    v54 = (int)v36;
                    v39 = *(float *)(v37 + *((_DWORD *)&v36->OnElementUnserialized + v35));
                    v11 = v65;
                    v40 = v7->m_nRowStrideInBytes[v35] * (y + cur_line) + v38;
                    v19 = c + 1;
                    *(float *)&v7->m_pAttributePtrs[v55][v40] = v39;
                    valid = nc;
                    v18 = x;
                    c = v19;
                  }
                  while ( v19 < nc );
                }
                v41 = (int *)v11[1].__vftable;
                x = ++v18;
              }
              while ( v18 < *v41 );
            }
            v15 = (FloatBitMap_t *)v11[1].__vftable;
            ++y;
          }
          while ( y < v15->m_nRows );
        }
        v3 = v58;
      }
      v42 = v11[1].__vftable;
      if ( next_line <= (int)v42->OnAttributeArrayElementAdded + cur_line )
        next_line = (int)v42->OnAttributeArrayElementAdded + cur_line;
      v43 = (int)v42->OnAttributeChanged + cur_column;
      cur_column = v43;
      if ( max_column_written <= v43 )
        max_column_written = v43;
      if ( ++i >= v3->m_ImageList.m_Storage.m_Size )
      {
        v8 = next_line;
        v9 = max_column_written;
        goto LABEL_30;
      }
    }
    m_pAsString = v11->m_Name.m_Storage.u.m_pAsString;
    v49 = defaultValue;
    if ( m_pAsString != (const char *)-1 )
      v49 = m_pAsString;
    _Warning(a1: "CDataModel: Image %s was not loaded! Unable to pack.\n", v49);
    v50 = (CDmeImage *)g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_pPackedImage.m_Storage.m_Handle);
    CDmeImage::EndFloatBitmapModification(this: v50);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045FE60
// Name: private: bool CDmeAmalgamatedTexture::PackImagesRGBA(bool,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeAmalgamatedTexture::PackImagesRGBA(CDmeAmalgamatedTexture *this, bool bGenerateImage, int nWidth)
{
  CDmeAmalgamatedTexture *v3; // edi
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  CDmeImage *v5; // eax
  FloatBitMap_t *v6; // eax
  int v7; // ebx
  CDmElement *v8; // eax
  CDmeSheetImage *v9; // esi
  bool v10; // zf
  CDmeSheetSequence *Sequence; // edi
  int m_Storage; // eax
  int v13; // eax
  int v14; // eax
  int v15; // edx
  int *v16; // ecx
  int v17; // edx
  FloatBitMap_t *m_pImage; // edx
  int *v19; // edi
  FloatBitMap_t *v20; // eax
  int v21; // ebx
  bool v22; // cc
  FloatBitMap_t *v23; // eax
  int v24; // edi
  int v25; // edx
  unsigned int *m_nStrideInBytes; // eax
  double v27; // st7
  FloatBitMap_t *v28; // edx
  FloatBitMap_t *v29; // esi
  int v30; // eax
  int v31; // ecx
  int v32; // edx
  int v33; // ecx
  int *v34; // eax
  int v35; // eax
  int v36; // ecx
  int j; // eax
  int v38; // eax
  int k; // edx
  CDmeImage *v40; // eax
  const char *m_pAsString; // esi
  const char *v43; // eax
  CDmeImage *v44; // eax
  CDmElement *v45; // eax
  CDmeImage *v46; // eax
  CDmElement *v47; // eax
  CDmeImage *v48; // eax
  DmElementHandle_t m_Handle; // [esp-4h] [ebp-68h]
  int max_column_written[2]; // [esp+Ch] [ebp-58h] BYREF
  int cur_line[2]; // [esp+14h] [ebp-50h] BYREF
  int next_line[2]; // [esp+1Ch] [ebp-48h]
  int cur_column[2]; // [esp+24h] [ebp-40h] BYREF
  int v54; // [esp+2Ch] [ebp-38h]
  int v55; // [esp+30h] [ebp-34h]
  int eMode; // [esp+34h] [ebp-30h]
  int w; // [esp+38h] [ebp-2Ch] BYREF
  int h; // [esp+3Ch] [ebp-28h] BYREF
  CDmeSheetImage *v59; // [esp+40h] [ebp-24h]
  FloatBitMap_t *output; // [esp+44h] [ebp-20h]
  int i; // [esp+48h] [ebp-1Ch]
  int y; // [esp+4Ch] [ebp-18h]
  int x; // [esp+50h] [ebp-14h]
  int idxfrm; // [esp+54h] [ebp-10h]
  int c; // [esp+58h] [ebp-Ch]
  CDmeAmalgamatedTexture *v66; // [esp+5Ch] [ebp-8h]
  bool bPackingRGBA; // [esp+63h] [ebp-1h]

  v3 = this;
  GetElement = g_pDataModel->GetElement;
  m_Handle = this->m_pPackedImage.m_Storage.m_Handle;
  v66 = this;
  v5 = (CDmeImage *)GetElement(this: g_pDataModel, a2: m_Handle);
  v6 = CDmeImage::BeginFloatBitmapModification(this: v5);
  v7 = 0;
  output = v6;
  if ( bGenerateImage )
    FloatBitMap_t::Init(this: v6, nXSize: nWidth, nYSize: 2048, nZSize: 1, nAttributeMask: 15);
  cur_line[0] = 0;
  cur_line[1] = 0;
  cur_column[0] = 0;
  cur_column[1] = 0;
  next_line[0] = 0;
  next_line[1] = 0;
  max_column_written[0] = 0;
  max_column_written[1] = 0;
  bPackingRGBA = true;
  i = 0;
  if ( v3->m_ImageList.m_Storage.m_Size <= 0 )
    goto LABEL_45;
  while ( 2 )
  {
    v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_ImageList.m_Storage.m_Memory.m_pMemory[v7]);
    v9 = (CDmeSheetImage *)v8;
    if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmeSheetImage::m_classType) )
      v9 = nullptr;
    v10 = v9->m_pImage == nullptr;
    v59 = v9;
    if ( v10 )
    {
      m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
      v43 = defaultValue;
      if ( m_pAsString != (const char *)-1 )
        v43 = m_pAsString;
      _Warning(a1: "CDataModel: Image %s was not loaded! Unable to pack.\n", v43);
      v44 = (CDmeImage *)g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_pPackedImage.m_Storage.m_Handle);
      CDmeImage::EndFloatBitmapModification(this: v44);
      return 0;
    }
    Sequence = CDmeSheetImage::FindSequence(this: v9, index: 0);
    m_Storage = Sequence->m_eMode.m_Storage;
    eMode = m_Storage;
    if ( m_Storage != 0 )
    {
      v13 = m_Storage - 1;
      if ( v13 != 0 )
      {
        if ( v13 != 1 )
        {
          v45 = g_pDataModel->GetElement(this: g_pDataModel, a2: v66->m_ImageList.m_Storage.m_Memory.m_pMemory[v7]);
          if ( v45 != nullptr )
            v45->IsA(this: v45, a2: CDmeSheetImage::m_classType);
          _Msg(
            a1: "*** error when packing 'rgb+a', bad sequence %d encountered for image '%s'!\n",
            Sequence->m_nSequenceNumber.m_Storage,
            (const char *)Sequence->m_nSequenceNumber.m_pAttribute);
          v46 = (CDmeImage *)g_pDataModel->GetElement(this: g_pDataModel, a2: v66->m_pPackedImage.m_Storage.m_Handle);
          CDmeImage::EndFloatBitmapModification(this: v46);
          return 0;
        }
        v14 = 1;
        bPackingRGBA = false;
      }
      else
      {
        v14 = 0;
        bPackingRGBA = false;
      }
    }
    else
    {
      if ( !bPackingRGBA )
      {
        v47 = g_pDataModel->GetElement(this: g_pDataModel, a2: v66->m_ImageList.m_Storage.m_Memory.m_pMemory[v7]);
        if ( v47 != nullptr )
          v47->IsA(this: v47, a2: CDmeSheetImage::m_classType);
        _Msg(
          a1: "*** error when packing 'rgb+a', bad sequence %d encountered for image '%s' after all rgba frames packed!\n",
          Sequence->m_nSequenceNumber.m_Storage,
          (const char *)Sequence->m_nSequenceNumber.m_pAttribute);
        v48 = (CDmeImage *)g_pDataModel->GetElement(this: g_pDataModel, a2: v66->m_pPackedImage.m_Storage.m_Handle);
        CDmeImage::EndFloatBitmapModification(this: v48);
        return 0;
      }
      v14 = 0;
    }
    v15 = cur_column[v14] + v9->m_pImage->m_nColumns;
    v16 = &cur_column[v14];
    idxfrm = v14;
    if ( v15 > nWidth )
    {
      v17 = next_line[v14];
      *v16 = 0;
      cur_line[v14] = v17;
    }
    m_pImage = v9->m_pImage;
    if ( m_pImage->m_nColumns + *v16 > nWidth )
      return 0;
    v19 = &cur_line[v14];
    if ( *v19 + m_pImage->m_nRows > 2048 )
      return 0;
    CDmAttribute::SetValue<int>(this: v9->m_XCoord.m_pAttribute, value: v16);
    CDmAttribute::SetValue<int>(this: v9->m_YCoord.m_pAttribute, value: v19);
    if ( !bGenerateImage )
      goto LABEL_37;
    v20 = v9->m_pImage;
    v21 = 0;
    y = 0;
    if ( v20->m_nRows <= 0 )
      goto LABEL_37;
    do
    {
      v22 = v20->m_nColumns <= 0;
      x = 0;
      if ( v22 )
        goto LABEL_36;
      v23 = output;
      v24 = 128 - (_DWORD)output;
      v54 = 128 - (_DWORD)output;
      v55 = -256 - (_DWORD)output;
      while ( 2 )
      {
        v25 = 280;
        c = 0;
        m_nStrideInBytes = v23->m_nStrideInBytes;
        do
        {
          if ( eMode == 0 )
          {
            if ( c >= 4 )
              goto LABEL_34;
setpx:
            v27 = *(float *)(x * *(int *)((char *)&v9->m_pImage->m_nColumns + v25)
                           + v21 * *(int *)((char *)&v9->m_pImage->m_nColumns + v24 + (unsigned int)m_nStrideInBytes)
                           + *(int *)((char *)&v9->m_pImage->m_nColumns + v55 + (unsigned int)m_nStrideInBytes));
            v9 = v59;
            v24 = v54;
            *(float *)(*m_nStrideInBytes * (x + cur_column[idxfrm])
                     + m_nStrideInBytes[32] * (y + cur_line[idxfrm])
                     + *(m_nStrideInBytes - 64)) = v27;
            v21 = y;
            goto LABEL_34;
          }
          if ( eMode == 1 )
          {
            if ( c < 3 )
              goto setpx;
          }
          else if ( eMode == 2 && c == 3 )
          {
            goto setpx;
          }
LABEL_34:
          ++c;
          v25 += 4;
          ++m_nStrideInBytes;
        }
        while ( v25 < 296 );
        v28 = v9->m_pImage;
        if ( ++x < v28->m_nColumns )
        {
          v23 = output;
          continue;
        }
        break;
      }
LABEL_36:
      v20 = v9->m_pImage;
      y = ++v21;
    }
    while ( v21 < v20->m_nRows );
LABEL_37:
    v29 = v9->m_pImage;
    v30 = idxfrm;
    v31 = cur_line[idxfrm] + v29->m_nRows;
    if ( next_line[idxfrm] > v31 )
      v31 = next_line[idxfrm];
    v32 = max_column_written[idxfrm];
    next_line[idxfrm] = v31;
    cur_column[v30] += v29->m_nColumns;
    v33 = cur_column[v30];
    v34 = &max_column_written[v30];
    if ( v32 > v33 )
      v33 = v32;
    v10 = !bPackingRGBA;
    *v34 = v33;
    if ( !v10 )
    {
      cur_line[1] = cur_line[0];
      cur_column[1] = cur_column[0];
      next_line[1] = next_line[0];
      max_column_written[1] = max_column_written[0];
    }
    v35 = i + 1;
    i = v35;
    v3 = v66;
    if ( v35 < v66->m_ImageList.m_Storage.m_Size )
    {
      v7 = v35;
      continue;
    }
    break;
  }
LABEL_45:
  v36 = 1;
  h = 1;
  for ( j = 0; j < 2; ++j )
  {
    for ( ; v36 < next_line[j]; v36 *= 2 )
      ;
  }
  v38 = 1;
  h = v36;
  w = 1;
  for ( k = 0; k < 2; ++k )
  {
    for ( ; v38 < max_column_written[k]; v38 *= 2 )
      ;
  }
  w = v38;
  if ( bGenerateImage )
    FloatBitMap_t::Crop(this: output, x1: 0, y1: 0, z1: 0, nWidth: v38, nHeight: v36, nDepth: 1);
  CDmAttribute::SetValue<int>(this: v3->m_nHeight.m_pAttribute, value: &h);
  CDmAttribute::SetValue<int>(this: v3->m_nWidth.m_pAttribute, value: &w);
  v40 = (CDmeImage *)g_pDataModel->GetElement(this: g_pDataModel, a2: v3->m_pPackedImage.m_Storage.m_Handle);
  CDmeImage::EndFloatBitmapModification(this: v40);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00460340
// Name: public: void CDmeAmalgamatedTexture::WriteFile(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAmalgamatedTexture::WriteFile(CDmeAmalgamatedTexture *this, const char *pFileName, bool bVerbose)
{
  void *v4; // esi
  bool v5; // cc
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  int v9; // ebx
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmElement *v12; // eax
  CDmElement *v13; // esi
  CDmElement *v14; // eax
  CDmElement *v15; // esi
  CDmElement *v16; // eax
  CDmElement *v17; // esi
  float v18; // xmm0_4
  int k; // edi
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // eax
  int v21; // eax
  int v22; // esi
  CDmElement *v23; // eax
  CDmElement *v24; // esi
  CDmElement *v25; // eax
  CDmElement *v26; // esi
  _DWORD *v27; // edi
  CDmElement *v28; // eax
  CDmElement *v29; // esi
  CDmElement *v30; // eax
  CDmElement *v31; // esi
  int v32; // esi
  CDmElement *v33; // eax
  CDmElement *v34; // esi
  int v35; // ebx
  CDmElement *v36; // eax
  CDmElement *v37; // esi
  CDmElement *v38; // eax
  CDmElement *v39; // esi
  CDmElement *v40; // eax
  CDmElement *v41; // esi
  CDmElement *v42; // eax
  CDmElement *v43; // esi
  CDmElement *v44; // eax
  CDmElement *v45; // esi
  CDmElement *v46; // eax
  CDmElement *v47; // esi
  CDmElement *v48; // eax
  CDmElement *v49; // esi
  CDmElement *v50; // eax
  CDmElement *v51; // esi
  CDmElement *v52; // eax
  CDmElement *v53; // esi
  CDmElement *v54; // eax
  CDmElement *v55; // esi
  __m128i v56; // xmm1
  double v57; // xmm0_8
  CDmElement *v58; // eax
  CDmElement *v59; // esi
  CDmElement *v60; // eax
  CDmElement *v61; // esi
  CDmElement *v62; // eax
  CDmElement *v63; // esi
  __m128i v64; // xmm1
  double v65; // xmm0_8
  CDmElement *v66; // eax
  CDmElement *v67; // esi
  int v68; // ebx
  CDmElement *v69; // eax
  CDmElement *v70; // esi
  CDmElement *v71; // eax
  CDmElement *v72; // esi
  CDmElement *v73; // edi
  CDmElement *v74; // eax
  CDmElement *v75; // esi
  CDmElement *v76; // eax
  CDmElement *v77; // esi
  CDmElement *v78; // eax
  CDmElement *v79; // esi
  void *m_FileHandle; // ebx
  CDmElement *v81; // eax
  CDmElement *v82; // esi
  CDmElement *v83; // eax
  CDmElement *v84; // esi
  CDmElement *v85; // eax
  CDmElement *v86; // esi
  CDmElement *v87; // edi
  CDmElement *v88; // eax
  CDmElement *v89; // esi
  CDmElement *v90; // eax
  CDmElement *v91; // esi
  CDmElement *v92; // eax
  CDmElement *v93; // esi
  int v94; // ebx
  CDmElement *v95; // eax
  CDmElement *v96; // esi
  CDmElement *v97; // eax
  CDmElement *v98; // esi
  CDmElement *v99; // eax
  CDmElement *v100; // esi
  float v101; // xmm0_4
  CDmElement *v102; // eax
  CDmElement *v103; // esi
  CDmElement *v104; // eax
  CDmElement *v105; // esi
  CDmElement *v106; // eax
  CDmElement *v107; // esi
  float v108; // xmm0_4
  CDmElement *v109; // eax
  CDmElement *v110; // esi
  CDmElement *v111; // eax
  CDmElement *v112; // esi
  CDmElement *v113; // eax
  CDmElement *v114; // esi
  CDmElement *v115; // edi
  CDmElement *v116; // eax
  CDmElement *v117; // esi
  CDmElement *v118; // eax
  CDmElement *v119; // esi
  CDmElement *v120; // eax
  CDmElement *v121; // esi
  CDmElement *v122; // eax
  CDmElement *v123; // esi
  CDmElement *v124; // eax
  CDmElement *v125; // esi
  CDmElement *v126; // eax
  CDmElement *v127; // esi
  CDmElement *v128; // edi
  CDmElement *v129; // eax
  CDmElement *v130; // esi
  CDmElement *v131; // eax
  CDmElement *v132; // esi
  CDmElement *v133; // eax
  CDmElement *v134; // esi
  CDmElement *v135; // eax
  CDmElement *v136; // esi
  CDmElement *v137; // eax
  CDmElement *v138; // esi
  int v139; // eax
  int v140; // esi
  DmElementHandle_t v141; // [esp+228h] [ebp-58h]
  int v142; // [esp+238h] [ebp-48h] BYREF
  int v143; // [esp+23Ch] [ebp-44h] BYREF
  int v144; // [esp+240h] [ebp-40h] BYREF
  int v145; // [esp+244h] [ebp-3Ch] BYREF
  float v146; // [esp+248h] [ebp-38h] BYREF
  float v147; // [esp+24Ch] [ebp-34h] BYREF
  float v148; // [esp+250h] [ebp-30h] BYREF
  float v149; // [esp+254h] [ebp-2Ch] BYREF
  DmElementHandle_t m_hElement; // [esp+258h] [ebp-28h] BYREF
  float v151; // [esp+25Ch] [ebp-24h] BYREF
  int m_Size; // [esp+260h] [ebp-20h] BYREF
  int *v153; // [esp+264h] [ebp-1Ch]
  float fTotal; // [esp+268h] [ebp-18h]
  COutputFile Outfile; // [esp+26Ch] [ebp-14h]
  int t; // [esp+270h] [ebp-10h]
  int i; // [esp+274h] [ebp-Ch]
  int j; // [esp+278h] [ebp-8h]
  CDmeAmalgamatedTexture *v159; // [esp+27Ch] [ebp-4h]

  v159 = this;
  if ( pFileName != nullptr )
  {
    v4 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: pFileName, a3: "wb", a4: 0);
    Outfile.m_FileHandle = v4;
    if ( v4 != nullptr && g_pFullFileSystem->IsOk(this: g_pFullFileSystem, a2: v4) )
    {
      m_Size = 1;
      g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &m_Size, a3: 4, a4: v4);
      m_Size = this->m_Sequences.m_Storage.m_Size;
      g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &m_Size, a3: 4, a4: v4);
      if ( bVerbose )
      {
        _Msg(a1: "1\n");
        _Msg(a1: "m_Sequences.Count() %d\n", this->m_Sequences.m_Storage.m_Size);
      }
      v5 = this->m_Sequences.m_Storage.m_Size <= 0;
      i = 0;
      if ( !v5 )
      {
        do
        {
          v6 = i;
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v159->m_Sequences.m_Storage.m_Memory.m_pMemory[i]);
          v8 = v7;
          if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmeSheetSequence::m_classType) )
            v8 = nullptr;
          m_Size = (int)v8[1].__vftable;
          g_pFullFileSystem->Write(
            this: &g_pFullFileSystem->IBaseFileSystem,
            a2: &m_Size,
            a3: 4,
            a4: Outfile.m_FileHandle);
          v9 = 0;
          v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: v159->m_Sequences.m_Storage.m_Memory.m_pMemory[v6]);
          v11 = v10;
          if ( v10 == nullptr || !v10->IsA(this: v10, a2: CDmeSheetSequence::m_classType) )
            v11 = nullptr;
          if ( v11[1].m_Id.m_Value[4] != 0 )
            v9 = 1;
          v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: v159->m_Sequences.m_Storage.m_Memory.m_pMemory[v6]);
          v13 = v12;
          if ( v12 == nullptr || !v12->IsA(this: v12, a2: CDmeSheetSequence::m_classType) )
            v13 = nullptr;
          if ( *(_DWORD *)&v13[1].m_Id.m_Value[12] == 1 )
          {
            v9 |= 2u;
          }
          else
          {
            v14 = g_pDataModel->GetElement(this: g_pDataModel, a2: v159->m_Sequences.m_Storage.m_Memory.m_pMemory[v6]);
            v15 = v14;
            if ( v14 == nullptr || !v14->IsA(this: v14, a2: CDmeSheetSequence::m_classType) )
              v15 = nullptr;
            if ( *(_DWORD *)&v15[1].m_Id.m_Value[12] == 2 )
              v9 |= 4u;
          }
          m_Size = v9;
          g_pFullFileSystem->Write(
            this: &g_pFullFileSystem->IBaseFileSystem,
            a2: &m_Size,
            a3: 4,
            a4: Outfile.m_FileHandle);
          v16 = g_pDataModel->GetElement(this: g_pDataModel, a2: v159->m_Sequences.m_Storage.m_Memory.m_pMemory[v6]);
          v17 = v16;
          if ( v16 == nullptr || !v16->IsA(this: v16, a2: CDmeSheetSequence::m_classType) )
            v17 = nullptr;
          m_Size = *((_DWORD *)&v17[1].m_ref + 2);
          g_pFullFileSystem->Write(
            this: &g_pFullFileSystem->IBaseFileSystem,
            a2: &m_Size,
            a3: 4,
            a4: Outfile.m_FileHandle);
          v18 = 0.0;
          for ( k = 0; ; ++k )
          {
            v141 = v159->m_Sequences.m_Storage.m_Memory.m_pMemory[i];
            GetElement = g_pDataModel->GetElement;
            fTotal = v18;
            v21 = (int)GetElement(this: g_pDataModel, a2: v141);
            v22 = v21;
            if ( v21 == 0
              || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v21 + 16))(
                   a1: v21,
                   a2: CDmeSheetSequence::m_classType.u) == 0 )
            {
              v22 = 0;
            }
            if ( k >= *(_DWORD *)(v22 + 104) )
              break;
            v23 = g_pDataModel->GetElement(this: g_pDataModel, a2: v159->m_Sequences.m_Storage.m_Memory.m_pMemory[i]);
            v24 = v23;
            if ( v23 == nullptr || !v23->IsA(this: v23, a2: CDmeSheetSequence::m_classType) )
              v24 = nullptr;
            v25 = g_pDataModel->GetElement(
                    this: g_pDataModel,
                    a2: *((_DWORD *)&v24[1].m_Name.m_pAttribute->m_pNext + k));
            v26 = v25;
            if ( v25 == nullptr || !v25->IsA(this: v25, a2: CDmeSheetSequenceFrame::m_classType) )
              v26 = nullptr;
            v18 = *(float *)&v26[1].m_ref.m_hElement + fTotal;
          }
          v151 = fTotal;
          g_pFullFileSystem->Write(
            this: &g_pFullFileSystem->IBaseFileSystem,
            a2: &v151,
            a3: 4,
            a4: Outfile.m_FileHandle);
          v27 = &v159->__vftable;
          if ( bVerbose )
          {
            v28 = g_pDataModel->GetElement(this: g_pDataModel, a2: v159->m_Sequences.m_Storage.m_Memory.m_pMemory[i]);
            v29 = v28;
            if ( v28 == nullptr || !v28->IsA(this: v28, a2: CDmeSheetSequence::m_classType) )
              v29 = nullptr;
            _Msg(a1: "m_Sequences[%d]->m_nSequenceNumber %d\n", i, v29[1].__vftable);
            v30 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v27[26] + 4 * i));
            v31 = v30;
            if ( v30 == nullptr || !v30->IsA(this: v30, a2: CDmeSheetSequence::m_classType) )
              v31 = nullptr;
            _Msg(a1: "m_Sequences[%d]->m_Clamp %d\n", i, v31[1].m_Id.m_Value[4] != 0);
            v32 = i;
            _Msg(a1: "m_Sequences[%d] flags %d\n", i, v9);
            v33 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v27[26] + 4 * v32));
            v34 = v33;
            if ( v33 == nullptr || !v33->IsA(this: v33, a2: CDmeSheetSequence::m_classType) )
              v34 = nullptr;
            _Msg(a1: "m_Sequences[%d]->m_Frames.Count() %d\n", i, *((_DWORD *)&v34[1].m_ref + 2));
            _Msg(a1: "fTotal %f\n", fTotal);
          }
          v35 = i;
          for ( j = 0; ; ++j )
          {
            v36 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v27[26] + 4 * v35));
            v37 = v36;
            if ( v36 == nullptr || !v36->IsA(this: v36, a2: CDmeSheetSequence::m_classType) )
              v37 = nullptr;
            if ( j >= *((_DWORD *)&v37[1].m_ref + 2) )
              break;
            v38 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v27[26] + 4 * v35));
            v39 = v38;
            if ( v38 == nullptr || !v38->IsA(this: v38, a2: CDmeSheetSequence::m_classType) )
              v39 = nullptr;
            v40 = g_pDataModel->GetElement(
                    this: g_pDataModel,
                    a2: *((_DWORD *)&v39[1].m_Name.m_pAttribute->m_pNext + j));
            v41 = v40;
            if ( v40 == nullptr || !v40->IsA(this: v40, a2: CDmeSheetSequenceFrame::m_classType) )
              v41 = nullptr;
            m_hElement = v41[1].m_ref.m_hElement;
            g_pFullFileSystem->Write(
              this: &g_pFullFileSystem->IBaseFileSystem,
              a2: &m_hElement,
              a3: 4,
              a4: Outfile.m_FileHandle);
            if ( bVerbose )
            {
              v42 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v27[26] + 4 * v35));
              v43 = v42;
              if ( v42 == nullptr || !v42->IsA(this: v42, a2: CDmeSheetSequence::m_classType) )
                v43 = nullptr;
              v44 = g_pDataModel->GetElement(
                      this: g_pDataModel,
                      a2: *((_DWORD *)&v43[1].m_Name.m_pAttribute->m_pNext + j));
              v45 = v44;
              if ( v44 == nullptr || !v44->IsA(this: v44, a2: CDmeSheetSequenceFrame::m_classType) )
                v45 = nullptr;
              _Msg(a1: "m_Sequences[%d]->m_Frames[%d]->m_fDisplayTime %f\n", v35, j, *(float *)&v45[1].m_ref.m_hElement);
            }
            t = 0;
            while ( 1 )
            {
              v46 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v27[26] + 4 * v35));
              v47 = v46;
              if ( v46 == nullptr || !v46->IsA(this: v46, a2: CDmeSheetSequence::m_classType) )
                v47 = nullptr;
              v48 = g_pDataModel->GetElement(
                      this: g_pDataModel,
                      a2: *((_DWORD *)&v47[1].m_Name.m_pAttribute->m_pNext + j));
              v49 = v48;
              if ( v48 == nullptr || !v48->IsA(this: v48, a2: CDmeSheetSequenceFrame::m_classType) )
                v49 = nullptr;
              if ( t >= *(_DWORD *)&v49[1].m_Id.m_Value[8] )
                break;
              v50 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v27[26] + 4 * v35));
              v51 = v50;
              if ( v50 == nullptr || !v50->IsA(this: v50, a2: CDmeSheetSequence::m_classType) )
                v51 = nullptr;
              v52 = g_pDataModel->GetElement(
                      this: g_pDataModel,
                      a2: *((_DWORD *)&v51[1].m_Name.m_pAttribute->m_pNext + j));
              v53 = v52;
              if ( v52 == nullptr || !v52->IsA(this: v52, a2: CDmeSheetSequenceFrame::m_classType) )
                v53 = nullptr;
              v54 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&v53[1].OnAttributeChanged + t));
              v55 = v54;
              if ( v54 == nullptr || !v54->IsA(this: v54, a2: CDmeSheetImage::m_classType) )
                v55 = nullptr;
              v56 = _mm_cvtsi32_si128(v27[34]);
              v57 = (double)*(int *)v55[1].m_Id.m_Value + 0.5;
              v153 = v27 + 34;
              *(float *)&v57 = v57;
              v149 = *(float *)&v57 / _mm_cvtepi32_ps(v56).m128_f32[0];
              g_pFullFileSystem->Write(
                this: &g_pFullFileSystem->IBaseFileSystem,
                a2: &v149,
                a3: 4,
                a4: Outfile.m_FileHandle);
              v58 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v27[26] + 4 * v35));
              v59 = v58;
              if ( v58 == nullptr || !v58->IsA(this: v58, a2: CDmeSheetSequence::m_classType) )
                v59 = nullptr;
              v60 = g_pDataModel->GetElement(
                      this: g_pDataModel,
                      a2: *((_DWORD *)&v59[1].m_Name.m_pAttribute->m_pNext + j));
              v61 = v60;
              if ( v60 == nullptr || !v60->IsA(this: v60, a2: CDmeSheetSequenceFrame::m_classType) )
                v61 = nullptr;
              v62 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&v61[1].OnAttributeChanged + t));
              v63 = v62;
              if ( v62 == nullptr || !v62->IsA(this: v62, a2: CDmeSheetImage::m_classType) )
                v63 = nullptr;
              v64 = _mm_cvtsi32_si128(v27[36]);
              v65 = (double)*(int *)&v63[1].m_Id.m_Value[8] + 0.5;
              m_Size = (int)(v27 + 36);
              *(float *)&v65 = v65;
              v148 = *(float *)&v65 / _mm_cvtepi32_ps(v64).m128_f32[0];
              g_pFullFileSystem->Write(
                this: &g_pFullFileSystem->IBaseFileSystem,
                a2: &v148,
                a3: 4,
                a4: Outfile.m_FileHandle);
              v66 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v27[26] + 4 * v35));
              v67 = v66;
              if ( v66 == nullptr || !v66->IsA(this: v66, a2: CDmeSheetSequence::m_classType) )
                v67 = nullptr;
              v68 = j;
              v69 = g_pDataModel->GetElement(
                      this: g_pDataModel,
                      a2: *((_DWORD *)&v67[1].m_Name.m_pAttribute->m_pNext + j));
              v70 = v69;
              if ( v69 == nullptr || !v69->IsA(this: v69, a2: CDmeSheetSequenceFrame::m_classType) )
                v70 = nullptr;
              v71 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&v70[1].OnAttributeChanged + t));
              v72 = v71;
              if ( v71 != nullptr && v71->IsA(this: v71, a2: CDmeSheetImage::m_classType) )
                v73 = v72;
              else
                v73 = nullptr;
              v74 = g_pDataModel->GetElement(this: g_pDataModel, a2: v159->m_Sequences.m_Storage.m_Memory.m_pMemory[i]);
              v75 = v74;
              if ( v74 == nullptr || !v74->IsA(this: v74, a2: CDmeSheetSequence::m_classType) )
                v75 = nullptr;
              v76 = g_pDataModel->GetElement(
                      this: g_pDataModel,
                      a2: *((_DWORD *)&v75[1].m_Name.m_pAttribute->m_pNext + v68));
              v77 = v76;
              if ( v76 == nullptr || !v76->IsA(this: v76, a2: CDmeSheetSequenceFrame::m_classType) )
                v77 = nullptr;
              v78 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&v77[1].OnAttributeChanged + t));
              v79 = v78;
              if ( v78 == nullptr || !v78->IsA(this: v78, a2: CDmeSheetImage::m_classType) )
                v79 = nullptr;
              m_FileHandle = Outfile.m_FileHandle;
              v147 = (float)((double)((unsigned int)v79[1].OnAttributeChanged + *(_DWORD *)v73[1].m_Id.m_Value - 1) + 0.5)
                   / (float)*v153;
              g_pFullFileSystem->Write(
                this: &g_pFullFileSystem->IBaseFileSystem,
                a2: &v147,
                a3: 4,
                a4: Outfile.m_FileHandle);
              v81 = g_pDataModel->GetElement(this: g_pDataModel, a2: v159->m_Sequences.m_Storage.m_Memory.m_pMemory[i]);
              v82 = v81;
              if ( v81 == nullptr || !v81->IsA(this: v81, a2: CDmeSheetSequence::m_classType) )
                v82 = nullptr;
              v83 = g_pDataModel->GetElement(
                      this: g_pDataModel,
                      a2: *((_DWORD *)&v82[1].m_Name.m_pAttribute->m_pNext + j));
              v84 = v83;
              if ( v83 == nullptr || !v83->IsA(this: v83, a2: CDmeSheetSequenceFrame::m_classType) )
                v84 = nullptr;
              v85 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&v84[1].OnAttributeChanged + t));
              v86 = v85;
              if ( v85 != nullptr && v85->IsA(this: v85, a2: CDmeSheetImage::m_classType) )
                v87 = v86;
              else
                v87 = nullptr;
              v88 = g_pDataModel->GetElement(this: g_pDataModel, a2: v159->m_Sequences.m_Storage.m_Memory.m_pMemory[i]);
              v89 = v88;
              if ( v88 == nullptr || !v88->IsA(this: v88, a2: CDmeSheetSequence::m_classType) )
                v89 = nullptr;
              v90 = g_pDataModel->GetElement(
                      this: g_pDataModel,
                      a2: *((_DWORD *)&v89[1].m_Name.m_pAttribute->m_pNext + j));
              v91 = v90;
              if ( v90 == nullptr || !v90->IsA(this: v90, a2: CDmeSheetSequenceFrame::m_classType) )
                v91 = nullptr;
              v92 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&v91[1].OnAttributeChanged + t));
              v93 = v92;
              if ( v92 == nullptr || !v92->IsA(this: v92, a2: CDmeSheetImage::m_classType) )
                v93 = nullptr;
              v146 = (float)((double)((unsigned int)v93[1].OnAttributeArrayElementAdded
                                    + *(_DWORD *)&v87[1].m_Id.m_Value[8]
                                    - 1)
                           + 0.5)
                   / (float)*(int *)m_Size;
              g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &v146, a3: 4, a4: m_FileHandle);
              if ( bVerbose )
              {
                v94 = i;
                v95 = g_pDataModel->GetElement(
                        this: g_pDataModel,
                        a2: v159->m_Sequences.m_Storage.m_Memory.m_pMemory[i]);
                v96 = v95;
                if ( v95 == nullptr || !v95->IsA(this: v95, a2: CDmeSheetSequence::m_classType) )
                  v96 = nullptr;
                v97 = g_pDataModel->GetElement(
                        this: g_pDataModel,
                        a2: *((_DWORD *)&v96[1].m_Name.m_pAttribute->m_pNext + j));
                v98 = v97;
                if ( v97 == nullptr || !v97->IsA(this: v97, a2: CDmeSheetSequenceFrame::m_classType) )
                  v98 = nullptr;
                v99 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&v98[1].OnAttributeChanged + t));
                v100 = v99;
                if ( v99 == nullptr || !v99->IsA(this: v99, a2: CDmeSheetImage::m_classType) )
                  v100 = nullptr;
                v101 = (double)*(int *)v100[1].m_Id.m_Value + 0.5;
                _Msg(a1: "xmin %f\n", (float)(v101 / (float)*v153));
                v102 = g_pDataModel->GetElement(
                         this: g_pDataModel,
                         a2: v159->m_Sequences.m_Storage.m_Memory.m_pMemory[v94]);
                v103 = v102;
                if ( v102 == nullptr || !v102->IsA(this: v102, a2: CDmeSheetSequence::m_classType) )
                  v103 = nullptr;
                v104 = g_pDataModel->GetElement(
                         this: g_pDataModel,
                         a2: *((_DWORD *)&v103[1].m_Name.m_pAttribute->m_pNext + j));
                v105 = v104;
                if ( v104 == nullptr || !v104->IsA(this: v104, a2: CDmeSheetSequenceFrame::m_classType) )
                  v105 = nullptr;
                v106 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&v105[1].OnAttributeChanged + t));
                v107 = v106;
                if ( v106 == nullptr || !v106->IsA(this: v106, a2: CDmeSheetImage::m_classType) )
                  v107 = nullptr;
                v108 = (double)*(int *)&v107[1].m_Id.m_Value[8] + 0.5;
                _Msg(a1: "ymin %f\n", (float)(v108 / (float)*(int *)m_Size));
                v109 = g_pDataModel->GetElement(
                         this: g_pDataModel,
                         a2: v159->m_Sequences.m_Storage.m_Memory.m_pMemory[v94]);
                v110 = v109;
                if ( v109 == nullptr || !v109->IsA(this: v109, a2: CDmeSheetSequence::m_classType) )
                  v110 = nullptr;
                v111 = g_pDataModel->GetElement(
                         this: g_pDataModel,
                         a2: *((_DWORD *)&v110[1].m_Name.m_pAttribute->m_pNext + j));
                v112 = v111;
                if ( v111 == nullptr || !v111->IsA(this: v111, a2: CDmeSheetSequenceFrame::m_classType) )
                  v112 = nullptr;
                v113 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&v112[1].OnAttributeChanged + t));
                v114 = v113;
                if ( v113 != nullptr && v113->IsA(this: v113, a2: CDmeSheetImage::m_classType) )
                  v115 = v114;
                else
                  v115 = nullptr;
                v116 = g_pDataModel->GetElement(
                         this: g_pDataModel,
                         a2: v159->m_Sequences.m_Storage.m_Memory.m_pMemory[v94]);
                v117 = v116;
                if ( v116 == nullptr || !v116->IsA(this: v116, a2: CDmeSheetSequence::m_classType) )
                  v117 = nullptr;
                v118 = g_pDataModel->GetElement(
                         this: g_pDataModel,
                         a2: *((_DWORD *)&v117[1].m_Name.m_pAttribute->m_pNext + j));
                v119 = v118;
                if ( v118 == nullptr || !v118->IsA(this: v118, a2: CDmeSheetSequenceFrame::m_classType) )
                  v119 = nullptr;
                v120 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&v119[1].OnAttributeChanged + t));
                v121 = v120;
                if ( v120 == nullptr || !v120->IsA(this: v120, a2: CDmeSheetImage::m_classType) )
                  v121 = nullptr;
                _Msg(
                  a1: "xmax %f\n",
                  (float)((float)((double)((unsigned int)v121[1].OnAttributeChanged + *(_DWORD *)v115[1].m_Id.m_Value
                                                                                    - 1)
                                + 0.5)
                        / (float)*v153));
                v122 = g_pDataModel->GetElement(
                         this: g_pDataModel,
                         a2: v159->m_Sequences.m_Storage.m_Memory.m_pMemory[v94]);
                v123 = v122;
                if ( v122 == nullptr || !v122->IsA(this: v122, a2: CDmeSheetSequence::m_classType) )
                  v123 = nullptr;
                v124 = g_pDataModel->GetElement(
                         this: g_pDataModel,
                         a2: *((_DWORD *)&v123[1].m_Name.m_pAttribute->m_pNext + j));
                v125 = v124;
                if ( v124 == nullptr || !v124->IsA(this: v124, a2: CDmeSheetSequenceFrame::m_classType) )
                  v125 = nullptr;
                v126 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&v125[1].OnAttributeChanged + t));
                v127 = v126;
                if ( v126 != nullptr && v126->IsA(this: v126, a2: CDmeSheetImage::m_classType) )
                  v128 = v127;
                else
                  v128 = nullptr;
                v129 = g_pDataModel->GetElement(
                         this: g_pDataModel,
                         a2: v159->m_Sequences.m_Storage.m_Memory.m_pMemory[v94]);
                v130 = v129;
                if ( v129 == nullptr || !v129->IsA(this: v129, a2: CDmeSheetSequence::m_classType) )
                  v130 = nullptr;
                v131 = g_pDataModel->GetElement(
                         this: g_pDataModel,
                         a2: *((_DWORD *)&v130[1].m_Name.m_pAttribute->m_pNext + j));
                v132 = v131;
                if ( v131 == nullptr || !v131->IsA(this: v131, a2: CDmeSheetSequenceFrame::m_classType) )
                  v132 = nullptr;
                v133 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&v132[1].OnAttributeChanged + t));
                v134 = v133;
                if ( v133 == nullptr || !v133->IsA(this: v133, a2: CDmeSheetImage::m_classType) )
                  v134 = nullptr;
                _Msg(
                  a1: "ymax %f\n",
                  (float)((float)((double)((unsigned int)v134[1].OnAttributeArrayElementAdded
                                         + *(_DWORD *)&v128[1].m_Id.m_Value[8]
                                         - 1)
                                + 0.5)
                        / (float)*(int *)m_Size));
              }
              ++t;
              v35 = i;
              v27 = &v159->__vftable;
            }
            v135 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(v27[26] + 4 * v35));
            v136 = v135;
            if ( v135 == nullptr || !v135->IsA(this: v135, a2: CDmeSheetSequence::m_classType) )
              v136 = nullptr;
            v137 = g_pDataModel->GetElement(
                     this: g_pDataModel,
                     a2: *((_DWORD *)&v136[1].m_Name.m_pAttribute->m_pNext + j));
            v138 = v137;
            if ( v137 == nullptr || !v137->IsA(this: v137, a2: CDmeSheetSequenceFrame::m_classType) )
              v138 = nullptr;
            v139 = *(_DWORD *)&v138[1].m_Id.m_Value[8];
            if ( v139 < 4 )
            {
              v140 = 4 - v139;
              do
              {
                v145 = 0;
                g_pFullFileSystem->Write(
                  this: &g_pFullFileSystem->IBaseFileSystem,
                  a2: &v145,
                  a3: 4,
                  a4: Outfile.m_FileHandle);
                v144 = 0;
                g_pFullFileSystem->Write(
                  this: &g_pFullFileSystem->IBaseFileSystem,
                  a2: &v144,
                  a3: 4,
                  a4: Outfile.m_FileHandle);
                v143 = 0;
                g_pFullFileSystem->Write(
                  this: &g_pFullFileSystem->IBaseFileSystem,
                  a2: &v143,
                  a3: 4,
                  a4: Outfile.m_FileHandle);
                v142 = 0;
                g_pFullFileSystem->Write(
                  this: &g_pFullFileSystem->IBaseFileSystem,
                  a2: &v142,
                  a3: 4,
                  a4: Outfile.m_FileHandle);
                if ( bVerbose )
                  _Msg(a1: "xmin %f\nymin %f\nxmax %f\nymax %f\n", 0.0, 0.0, 0.0, 0.0);
                --v140;
              }
              while ( v140 != 0 );
            }
          }
          i = v35 + 1;
        }
        while ( v35 + 1 < v27[29] );
      }
      _Msg(a1: "Ok: successfully saved SHT \"%s\"\n", pFileName);
      g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: Outfile.m_FileHandle);
    }
    else
    {
      _Msg(a1: "Error: failed to write SHT \"%s\"!\n", pFileName);
      if ( v4 != nullptr )
        g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v4);
    }
  }
  else
  {
    _Msg(a1: "Error: No output filename set!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00461580
// Name: CreateFloatBitmap
// Source: json
//------------------------------------------------------------------------------
FloatBitMap_t *__usercall CreateFloatBitmap@<eax>(char *pFilename@<eax>, bool bUseCurrentDir)
{
  int v3; // eax
  FloatBitMap_t *v4; // eax
  int v6; // edi
  char *v7; // ecx
  char *v8; // edx
  char v9; // al
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // esi
  int v12; // eax
  FloatBitMap_t *v13; // eax
  int v14; // edi
  int v15; // eax
  int v16; // edi
  char v17; // al
  int ChannelIndexFromChar; // eax
  char **m_pMemory; // eax
  FloatBitMap_t newBitmap; // [esp+8h] [ebp-444h] BYREF
  char fnamebuf[260]; // [esp+32Ch] [ebp-120h] BYREF
  int i; // [esp+430h] [ebp-1Ch]
  CUtlVector<char *,CUtlMemory<char *,int> > Images; // [esp+434h] [ebp-18h] BYREF
  FloatBitMap_t *pBitmap; // [esp+448h] [ebp-4h]

  strchr(string: (unsigned __int8 *)pFilename, chr: 0x2Cu);
  if ( v3 != 0 )
  {
    memset(&Images, 0, sizeof(Images));
    V_SplitString(pString: pFilename, pSeparator: ",", outStrings: &Images);
    v6 = 0;
    pBitmap = nullptr;
    for ( i = 0; v6 < Images.m_Size; i = v6 )
    {
      v7 = Images.m_Memory.m_pMemory[v6];
      v8 = fnamebuf;
      do
      {
        v9 = *v7;
        *v8++ = *v7++;
      }
      while ( v9 != 0 );
      strchr(string: (unsigned __int8 *)fnamebuf, chr: 0x7Bu);
      v11 = v10;
      if ( v10 != nullptr )
      {
        *v10 = 0;
        v11 = v10 + 1;
        strchr(string: v10 + 1, chr: 0x7Du);
        if ( v12 == 0 )
          _Msg(a1: "bad extended bitmap synax (no close brace) - %s \n", Images.m_Memory.m_pMemory[v6]);
      }
      FloatBitMap_t::FloatBitMap_t(this: &newBitmap, tgafilename: fnamebuf);
      if ( pBitmap == nullptr )
      {
        v13 = (FloatBitMap_t *)operator new(size: 0x324u);
        if ( v13 != nullptr )
          pBitmap = FloatBitMap_t::FloatBitMap_t(this: v13, pOrig: &newBitmap);
        else
          pBitmap = nullptr;
      }
      if ( v11 != nullptr && v11[1] == 61 )
      {
        v14 = (char)*v11;
        strchr(string: (unsigned __int8 *)s_ChannelIDs, chr: *v11);
        if ( v15 != 0 )
        {
          v16 = v15 - (_DWORD)s_ChannelIDs;
          if ( v15 - (_DWORD)s_ChannelIDs != -1 )
          {
            v17 = v11[2];
            if ( v17 == 48 )
            {
              ZeroChannel(nDestChannel: v16, pBitmap, &newBitmap);
            }
            else
            {
              ChannelIndexFromChar = GetChannelIndexFromChar(c: v17);
              if ( ChannelIndexFromChar != -1 )
                CopyChannel(&newBitmap, pBitmap, nSrcChannel: ChannelIndexFromChar, nDestChannel: v16);
            }
          }
        }
        else
        {
          _Warning(a1: " bad channel name '%c'\n", v14);
        }
      }
      CSOAContainer::~CSOAContainer(this: &newBitmap);
      v6 = i + 1;
    }
    m_pMemory = Images.m_Memory.m_pMemory;
    Images.m_Size = 0;
    if ( Images.m_Memory.m_nGrowSize >= 0 )
    {
      if ( Images.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: Images.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        Images.m_Memory.m_pMemory = nullptr;
      }
      Images.m_Memory.m_nAllocationCount = 0;
    }
    Images.m_pElements = m_pMemory;
    if ( Images.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return pBitmap;
  }
  else
  {
    if ( V_IsAbsolutePath(pStr: pFilename) )
    {
      V_strncpy(pDest: fnamebuf, pSrc: pFilename, maxLen: 260);
    }
    else if ( bUseCurrentDir )
    {
      GetFullPathUsingCurrentDir(fname: pFilename, pFullTGAFileNameDest: fnamebuf, fullPathBufferSize: 260);
    }
    else
    {
      GetFullPathUsingMaterialsrcContent(fname: pFilename, pFullTGAFileNameDest: fnamebuf, fullPathBufferSize: 260);
    }
    v4 = (FloatBitMap_t *)operator new(size: 0x324u);
    if ( v4 != nullptr )
      return FloatBitMap_t::FloatBitMap_t(this: v4, tgafilename: fnamebuf);
    else
      return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004617D0
// Name: public: void CDmeAmalgamatedTexture::Init(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAmalgamatedTexture::Init(
        CDmeAmalgamatedTexture *this,
        const char *pShtFileName,
        bool bUseCurrentDir)
{
  int v4; // ebx
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  const char *m_pAsString; // esi
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  int v10; // eax
  char pFullPath[260]; // [esp+Ch] [ebp-214h] BYREF
  char pFullDir[260]; // [esp+110h] [ebp-110h] BYREF
  CDisableUndoScopeGuard sg; // [esp+214h] [ebp-Ch]
  const char *pImageName; // [esp+21Ch] [ebp-4h]

  sg.m_bOldValue = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  v4 = 0;
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  this->m_pCurSequence = nullptr;
  V_strncpy(pDest: pFullDir, pSrc: pShtFileName, maxLen: 260);
  V_StripFilename(path: pFullDir);
  if ( this->m_ImageList.m_Storage.m_Size > 0 )
  {
    do
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_ImageList.m_Storage.m_Memory.m_pMemory[v4]);
      v6 = v5;
      if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeSheetImage::m_classType) )
        v6 = nullptr;
      m_pAsString = v6->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      pImageName = m_pAsString;
      if ( bUseCurrentDir && V_IsAbsolutePath(pStr: pShtFileName) )
      {
        V_ComposeFileName(path: pFullDir, filename: m_pAsString, dest: pFullPath, destSize: 260);
        pImageName = pFullPath;
      }
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_ImageList.m_Storage.m_Memory.m_pMemory[v4]);
      v9 = v8;
      if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmeSheetImage::m_classType) )
        v9 = nullptr;
      ++v4;
      v9[1].__vftable = (CDmElement_vtbl *)CreateFloatBitmap(pFilename: (char *)pImageName, bUseCurrentDir);
    }
    while ( v4 < this->m_ImageList.m_Storage.m_Size );
  }
  v10 = *(_DWORD *)&sg.m_bOldValue;
  this->m_SequenceCount = 0;
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: v10);
}

//------------------------------------------------------------------------------
// Address: 0x00461940
// Name: public: bool CDmeAmalgamatedTexture::PackImages(bool,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeAmalgamatedTexture::PackImages(CDmeAmalgamatedTexture *this, bool bGenerateImage, int nWidth)
{
  const char *m_pAsString; // eax
  DmElementHandle_t v5; // eax
  CDmElement *v6; // eax
  CDmElement *v7; // esi
  CDmElement *v8; // ecx
  DmElementHandle_t value; // [esp+8h] [ebp-4h] BYREF

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_pPackedImage.m_Storage.m_Handle) == nullptr )
  {
    m_pAsString = this->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    v5 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
           a1: g_pDataModel,
           a2: (CUtlSymbolLarge)CDmeImage::m_classType.u.m_Id,
           a3: m_pAsString,
           a4: this->m_fileId,
           a5: nullptr);
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5);
    v7 = v6;
    if ( v6 != nullptr && v6->IsA(this: v6, a2: CDmeImage::m_classType) )
      v8 = v7;
    else
      v8 = nullptr;
    if ( v8 != nullptr )
      value = CCodecBuffer_Block::GetBufferType(this: v8);
    else
      value = DMELEMENT_HANDLE_INVALID;
    CDmAttribute::SetValue<enum DmElementHandle_t>(this: this->m_pPackedImage.m_pAttribute, &value);
  }
  if ( this->m_ePackingMode.m_Storage == 1 )
    return CDmeAmalgamatedTexture::PackImagesFlat(this, bGenerateImage, nWidth);
  if ( this->m_ePackingMode.m_Storage == 2 )
    return CDmeAmalgamatedTexture::PackImagesRGBA(this, bGenerateImage, nWidth);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00461A30
// Name: public: bool CDmeAmalgamatedTexture::DetermineBestPacking(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeAmalgamatedTexture::DetermineBestPacking(CDmeAmalgamatedTexture *this)
{
  int v1; // ebx
  int v3; // esi
  int m_Storage; // ecx
  int v5; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // ebx
  int v9; // ecx
  int v10; // eax
  int v11; // ebx
  int i; // eax
  CDmAttribute *m_pAttribute; // ecx
  int thisSize; // [esp+Ch] [ebp-10h] BYREF
  int nBestSquareness; // [esp+10h] [ebp-Ch]
  int nBestSize; // [esp+14h] [ebp-8h]
  int nBestWidth; // [esp+18h] [ebp-4h] BYREF

  v1 = 0x40000000;
  nBestWidth = -1;
  nBestSize = 0x40000000;
  nBestSquareness = 0x40000000;
  v3 = 2048;
  while ( CDmeAmalgamatedTexture::PackImages(this, bGenerateImage: false, nWidth: v3) != 0 )
  {
    m_Storage = this->m_nWidth.m_Storage;
    v5 = this->m_nHeight.m_Storage;
    v6 = v5 * m_Storage;
    thisSize = v5 * m_Storage;
    if ( m_Storage == v5 )
    {
      v7 = 1;
    }
    else
    {
      v8 = m_Storage;
      v9 = m_Storage / v5;
      v10 = this->m_nHeight.m_Storage / v8;
      v1 = nBestSize;
      v6 = thisSize;
      v7 = v10 + v9;
    }
    if ( v6 >= v1 )
    {
      if ( v6 != v1 || v7 >= nBestSquareness )
        goto LABEL_13;
    }
    else
    {
      v11 = this->m_nWidth.m_Storage;
      for ( i = v3 >> 1; i >= v11; i >>= 1 )
        v3 = i;
    }
    v1 = v6;
    nBestWidth = v3;
    nBestSize = v6;
    nBestSquareness = v7;
LABEL_13:
    v3 >>= 1;
    if ( v3 < 64 )
      break;
  }
  if ( nBestWidth >= 0 )
  {
    CDmAttribute::SetValue<int>(this: this->m_nWidth.m_pAttribute, value: &nBestWidth);
    m_pAttribute = this->m_nHeight.m_pAttribute;
    thisSize = v1 / nBestWidth;
    CDmAttribute::SetValue<int>(this: m_pAttribute, value: &thisSize);
    return 1;
  }
  else
  {
    _Warning(a1: "Packing error: failed to pack images!\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00461B90
// Name: protected: CDmeAmalgamatedTexture::CDmeAmalgamatedTexture(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeAmalgamatedTexture *__thiscall CDmeAmalgamatedTexture::CDmeAmalgamatedTexture(
        CDmeAmalgamatedTexture *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeAmalgamatedTexture_vtbl *)&CDmeAmalgamatedTexture::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_ImageList);
  this->m_ePackingMode.m_pAttribute = nullptr;
  this->m_ePackingMode.m_Storage = 0;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Sequences);
  this->m_nWidth.m_pAttribute = nullptr;
  this->m_nWidth.m_Storage = 0;
  this->m_nHeight.m_pAttribute = nullptr;
  this->m_nHeight.m_Storage = 0;
  this->m_pPackedImage.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_pPackedImage.m_pAttribute = nullptr;
  this->m_pPackedImage.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00461C20
// Name: public: virtual bool CDmeAmalgamatedTexture::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAmalgamatedTexture::IsA(CDmeAmalgamatedTexture *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAmalgamatedTexture::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00461C50
// Name: public: virtual int CDmeAmalgamatedTexture::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAmalgamatedTexture::GetInheritanceDepth(CDmeAmalgamatedTexture *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAmalgamatedTexture::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00461C90
// Name: protected: virtual int CDmeAmalgamatedTexture::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAmalgamatedTexture::AllocatedSize(CDmeAmalgamatedTexture *this)
{
  return 168;
}

//------------------------------------------------------------------------------
// Address: 0x00461CA0
// Name: protected: virtual void CDmeAmalgamatedTexture::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAmalgamatedTexture::PerformConstruction(CDmeAmalgamatedTexture *this)
{
  CSteamApplication::PostShutdown();
  CDmeAmalgamatedTexture::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00462870
// Name: public: virtual void CDmeAmalgamatedTexture::OnAttributeArrayElementRemoved(class CDmAttribute __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAmalgamatedTexture::OnAttributeArrayElementRemoved(
        CDmeSheetImage *this,
        CDmAttribute *pAttribute,
        CDmAttribute *nFirstElem,
        int nLastElem)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004656A0
// Name: protected: void FloatBitMap_t::LoadFromBufferRGBA<struct ABGR8888_t>(struct ABGR8888_t const __near *,int,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferRGBA<ABGR8888_t>(
        FloatBitMap_t *this,
        const ABGR8888_t *pBuffer,
        int nPixelCount,
        const float *pGammaTable)
{
  const ABGR8888_t *v4; // esi
  int v5; // ebx
  int m_nColumns; // edx
  int v7; // eax
  unsigned __int8 *p_g; // edi
  double v9; // st7
  unsigned int v10; // edx
  int y; // [esp+0h] [ebp-Ch]
  unsigned __int8 *v12; // [esp+4h] [ebp-8h]
  int z; // [esp+8h] [ebp-4h]

  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v4 = pBuffer;
    do
    {
      v5 = 0;
      y = 0;
      if ( this->m_nRows > 0 )
      {
        m_nColumns = this->m_nColumns;
        do
        {
          v7 = 0;
          if ( m_nColumns > 0 )
          {
            p_g = &v4->g;
            v12 = &v4->g;
            do
            {
              *(float *)&this->m_pAttributePtrs[0][z * this->m_nSliceStrideInBytes[0]
                                                 + v5 * this->m_nRowStrideInBytes[0]
                                                 + v7 * this->m_nStrideInBytes[0]] = pGammaTable[(4 * p_g[1])
                                                                                               | ((int)p_g[1] >> 6)];
              *(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                 + y * this->m_nRowStrideInBytes[1]
                                                 + v7 * this->m_nStrideInBytes[1]] = pGammaTable[(4 * *v12)
                                                                                               | ((int)*v12 >> 6)];
              v9 = pGammaTable[(4 * *(v12 - 1)) | ((int)*(v12 - 1) >> 6)];
              v12 += 4;
              p_g = v12;
              *(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                 + y * this->m_nRowStrideInBytes[2]
                                                 + v7 * this->m_nStrideInBytes[2]] = v9;
              v5 = y;
              v10 = v7 * this->m_nStrideInBytes[3]
                  + z * this->m_nSliceStrideInBytes[3]
                  + y * this->m_nRowStrideInBytes[3];
              ++v7;
              *(float *)&this->m_pAttributePtrs[3][v10] = (float)((4 * *(v12 - 6)) | ((int)*(v12 - 6) >> 6))
                                                        * 0.00097751711;
            }
            while ( v7 < this->m_nColumns );
            v4 = pBuffer;
          }
          m_nColumns = this->m_nColumns;
          ++v5;
          v4 += this->m_nColumns;
          pBuffer = v4;
          y = v5;
        }
        while ( v5 < this->m_nRows );
      }
      ++z;
    }
    while ( z < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00465830
// Name: protected: void FloatBitMap_t::LoadFromBufferRGBA<struct RGBA8888_t>(struct RGBA8888_t const __near *,int,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferRGBA<RGBA8888_t>(
        FloatBitMap_t *this,
        const RGBA8888_t *pBuffer,
        int nPixelCount,
        const float *pGammaTable)
{
  const RGBA8888_t *v4; // esi
  int v5; // ebx
  int m_nColumns; // edx
  int v7; // eax
  unsigned __int8 *p_b; // edi
  double v9; // st7
  unsigned int v10; // edx
  int y; // [esp+0h] [ebp-Ch]
  unsigned __int8 *v12; // [esp+4h] [ebp-8h]
  int z; // [esp+8h] [ebp-4h]

  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v4 = pBuffer;
    do
    {
      v5 = 0;
      y = 0;
      if ( this->m_nRows > 0 )
      {
        m_nColumns = this->m_nColumns;
        do
        {
          v7 = 0;
          if ( m_nColumns > 0 )
          {
            p_b = &v4->b;
            v12 = &v4->b;
            do
            {
              *(float *)&this->m_pAttributePtrs[0][z * this->m_nSliceStrideInBytes[0]
                                                 + v5 * this->m_nRowStrideInBytes[0]
                                                 + v7 * this->m_nStrideInBytes[0]] = pGammaTable[(4 * *(p_b - 2))
                                                                                               | ((int)*(p_b - 2) >> 6)];
              *(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                 + y * this->m_nRowStrideInBytes[1]
                                                 + v7 * this->m_nStrideInBytes[1]] = pGammaTable[(4 * *(v12 - 1))
                                                                                               | ((int)*(v12 - 1) >> 6)];
              v9 = pGammaTable[(4 * *v12) | ((int)*v12 >> 6)];
              v12 += 4;
              p_b = v12;
              *(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                 + y * this->m_nRowStrideInBytes[2]
                                                 + v7 * this->m_nStrideInBytes[2]] = v9;
              v5 = y;
              v10 = v7 * this->m_nStrideInBytes[3]
                  + z * this->m_nSliceStrideInBytes[3]
                  + y * this->m_nRowStrideInBytes[3];
              ++v7;
              *(float *)&this->m_pAttributePtrs[3][v10] = (float)((4 * *(v12 - 3)) | ((int)*(v12 - 3) >> 6))
                                                        * 0.00097751711;
            }
            while ( v7 < this->m_nColumns );
            v4 = pBuffer;
          }
          m_nColumns = this->m_nColumns;
          ++v5;
          v4 += this->m_nColumns;
          pBuffer = v4;
          y = v5;
        }
        while ( v5 < this->m_nRows );
      }
      ++z;
    }
    while ( z < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004659C0
// Name: protected: void FloatBitMap_t::LoadFromBufferRGBA<struct BGRA8888_t>(struct BGRA8888_t const __near *,int,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferRGBA<BGRA8888_t>(
        FloatBitMap_t *this,
        const BGRA8888_t *pBuffer,
        int nPixelCount,
        const float *pGammaTable)
{
  const BGRA8888_t *v4; // esi
  int v5; // ebx
  int m_nColumns; // edx
  int v7; // eax
  unsigned __int8 *p_g; // edi
  double v9; // st7
  unsigned int v10; // edx
  int y; // [esp+0h] [ebp-Ch]
  unsigned __int8 *v12; // [esp+4h] [ebp-8h]
  int z; // [esp+8h] [ebp-4h]

  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v4 = pBuffer;
    do
    {
      v5 = 0;
      y = 0;
      if ( this->m_nRows > 0 )
      {
        m_nColumns = this->m_nColumns;
        do
        {
          v7 = 0;
          if ( m_nColumns > 0 )
          {
            p_g = &v4->g;
            v12 = &v4->g;
            do
            {
              *(float *)&this->m_pAttributePtrs[0][z * this->m_nSliceStrideInBytes[0]
                                                 + v5 * this->m_nRowStrideInBytes[0]
                                                 + v7 * this->m_nStrideInBytes[0]] = pGammaTable[(4 * p_g[1])
                                                                                               | ((int)p_g[1] >> 6)];
              *(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                 + y * this->m_nRowStrideInBytes[1]
                                                 + v7 * this->m_nStrideInBytes[1]] = pGammaTable[(4 * *v12)
                                                                                               | ((int)*v12 >> 6)];
              v9 = pGammaTable[(4 * *(v12 - 1)) | ((int)*(v12 - 1) >> 6)];
              v12 += 4;
              p_g = v12;
              *(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                 + y * this->m_nRowStrideInBytes[2]
                                                 + v7 * this->m_nStrideInBytes[2]] = v9;
              v5 = y;
              v10 = v7 * this->m_nStrideInBytes[3]
                  + z * this->m_nSliceStrideInBytes[3]
                  + y * this->m_nRowStrideInBytes[3];
              ++v7;
              *(float *)&this->m_pAttributePtrs[3][v10] = (float)((4 * *(v12 - 2)) | ((int)*(v12 - 2) >> 6))
                                                        * 0.00097751711;
            }
            while ( v7 < this->m_nColumns );
            v4 = pBuffer;
          }
          m_nColumns = this->m_nColumns;
          ++v5;
          v4 += this->m_nColumns;
          pBuffer = v4;
          y = v5;
        }
        while ( v5 < this->m_nRows );
      }
      ++z;
    }
    while ( z < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00465B50
// Name: protected: void FloatBitMap_t::LoadFromBufferRGB<struct RGB888_t>(struct RGB888_t const __near *,int,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferRGB<RGB888_t>(
        FloatBitMap_t *this,
        const RGB888_t *pBuffer,
        int nPixelCount,
        const float *pGammaTable)
{
  int v4; // edx
  const RGB888_t *v5; // ebx
  int v6; // edi
  int m_nColumns; // esi
  int v8; // eax
  double v9; // st7
  unsigned __int8 *v10; // edx
  unsigned int v11; // esi
  int y; // [esp+0h] [ebp-Ch]
  int z; // [esp+4h] [ebp-8h]
  unsigned __int8 *p_b; // [esp+8h] [ebp-4h]

  v4 = 0;
  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      v6 = 0;
      y = 0;
      if ( this->m_nRows > 0 )
      {
        m_nColumns = this->m_nColumns;
        do
        {
          v8 = 0;
          if ( m_nColumns > 0 )
          {
            p_b = &v5->b;
            do
            {
              *(float *)&this->m_pAttributePtrs[0][z * this->m_nSliceStrideInBytes[0]
                                                 + v6 * this->m_nRowStrideInBytes[0]
                                                 + v8 * this->m_nStrideInBytes[0]] = pGammaTable[(4 * *(p_b - 2))
                                                                                               | ((int)*(p_b - 2) >> 6)];
              v9 = pGammaTable[(4 * *(p_b - 1)) | ((int)*(p_b - 1) >> 6)];
              v10 = p_b;
              p_b += 3;
              *(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                 + y * this->m_nRowStrideInBytes[1]
                                                 + v8 * this->m_nStrideInBytes[1]] = v9;
              v6 = y;
              *(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                 + y * this->m_nRowStrideInBytes[2]
                                                 + v8 * this->m_nStrideInBytes[2]] = pGammaTable[(4 * *v10)
                                                                                               | ((int)*v10 >> 6)];
              v4 = z;
              v11 = z * this->m_nSliceStrideInBytes[3]
                  + y * this->m_nRowStrideInBytes[3]
                  + v8 * this->m_nStrideInBytes[3];
              ++v8;
              *(_DWORD *)&this->m_pAttributePtrs[3][v11] = 1065353216;
            }
            while ( v8 < this->m_nColumns );
            v5 = pBuffer;
          }
          m_nColumns = this->m_nColumns;
          ++v6;
          v5 = (const RGB888_t *)((char *)v5 + 2 * this->m_nColumns + this->m_nColumns);
          pBuffer = v5;
          y = v6;
        }
        while ( v6 < this->m_nRows );
      }
      z = ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00465CC0
// Name: protected: void FloatBitMap_t::LoadFromBufferRGB<struct BGR888_t>(struct BGR888_t const __near *,int,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferRGB<BGR888_t>(
        FloatBitMap_t *this,
        const BGR888_t *pBuffer,
        int nPixelCount,
        const float *pGammaTable)
{
  int v4; // edx
  const BGR888_t *v5; // ebx
  int v6; // edi
  int m_nColumns; // esi
  int v8; // eax
  double v9; // st7
  unsigned __int8 *v10; // edx
  unsigned int v11; // esi
  int y; // [esp+0h] [ebp-Ch]
  int z; // [esp+4h] [ebp-8h]
  unsigned __int8 *p_g; // [esp+8h] [ebp-4h]

  v4 = 0;
  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      v6 = 0;
      y = 0;
      if ( this->m_nRows > 0 )
      {
        m_nColumns = this->m_nColumns;
        do
        {
          v8 = 0;
          if ( m_nColumns > 0 )
          {
            p_g = &v5->g;
            do
            {
              *(float *)&this->m_pAttributePtrs[0][z * this->m_nSliceStrideInBytes[0]
                                                 + v6 * this->m_nRowStrideInBytes[0]
                                                 + v8 * this->m_nStrideInBytes[0]] = pGammaTable[(4 * p_g[1])
                                                                                               | ((int)p_g[1] >> 6)];
              v9 = pGammaTable[(4 * *p_g) | ((int)*p_g >> 6)];
              v10 = p_g;
              p_g += 3;
              *(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                 + y * this->m_nRowStrideInBytes[1]
                                                 + v8 * this->m_nStrideInBytes[1]] = v9;
              v6 = y;
              *(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                 + y * this->m_nRowStrideInBytes[2]
                                                 + v8 * this->m_nStrideInBytes[2]] = pGammaTable[(4 * *(v10 - 1))
                                                                                               | ((int)*(v10 - 1) >> 6)];
              v4 = z;
              v11 = z * this->m_nSliceStrideInBytes[3]
                  + y * this->m_nRowStrideInBytes[3]
                  + v8 * this->m_nStrideInBytes[3];
              ++v8;
              *(_DWORD *)&this->m_pAttributePtrs[3][v11] = 1065353216;
            }
            while ( v8 < this->m_nColumns );
            v5 = pBuffer;
          }
          m_nColumns = this->m_nColumns;
          ++v6;
          v5 = (const BGR888_t *)((char *)v5 + 2 * this->m_nColumns + this->m_nColumns);
          pBuffer = v5;
          y = v6;
        }
        while ( v6 < this->m_nRows );
      }
      z = ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00465E20
// Name: protected: void FloatBitMap_t::LoadFromBufferRGB<struct BGRX8888_t>(struct BGRX8888_t const __near *,int,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferRGB<BGRX8888_t>(
        FloatBitMap_t *this,
        const BGRX8888_t *pBuffer,
        int nPixelCount,
        const float *pGammaTable)
{
  int v4; // edx
  const BGRX8888_t *v5; // ebx
  int v6; // edi
  int m_nColumns; // esi
  int v8; // eax
  double v9; // st7
  unsigned __int8 *v10; // edx
  unsigned int v11; // esi
  int y; // [esp+0h] [ebp-Ch]
  int z; // [esp+4h] [ebp-8h]
  unsigned __int8 *p_g; // [esp+8h] [ebp-4h]

  v4 = 0;
  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      v6 = 0;
      y = 0;
      if ( this->m_nRows > 0 )
      {
        m_nColumns = this->m_nColumns;
        do
        {
          v8 = 0;
          if ( m_nColumns > 0 )
          {
            p_g = &v5->g;
            do
            {
              *(float *)&this->m_pAttributePtrs[0][z * this->m_nSliceStrideInBytes[0]
                                                 + v6 * this->m_nRowStrideInBytes[0]
                                                 + v8 * this->m_nStrideInBytes[0]] = pGammaTable[(4 * p_g[1])
                                                                                               | ((int)p_g[1] >> 6)];
              v9 = pGammaTable[(4 * *p_g) | ((int)*p_g >> 6)];
              v10 = p_g;
              p_g += 4;
              *(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                 + y * this->m_nRowStrideInBytes[1]
                                                 + v8 * this->m_nStrideInBytes[1]] = v9;
              v6 = y;
              *(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                 + y * this->m_nRowStrideInBytes[2]
                                                 + v8 * this->m_nStrideInBytes[2]] = pGammaTable[(4 * *(v10 - 1))
                                                                                               | ((int)*(v10 - 1) >> 6)];
              v4 = z;
              v11 = z * this->m_nSliceStrideInBytes[3]
                  + y * this->m_nRowStrideInBytes[3]
                  + v8 * this->m_nStrideInBytes[3];
              ++v8;
              *(_DWORD *)&this->m_pAttributePtrs[3][v11] = 1065353216;
            }
            while ( v8 < this->m_nColumns );
            v5 = pBuffer;
          }
          m_nColumns = this->m_nColumns;
          ++v6;
          v5 += this->m_nColumns;
          pBuffer = v5;
          y = v6;
        }
        while ( v6 < this->m_nRows );
      }
      z = ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00465F80
// Name: protected: void FloatBitMap_t::LoadFromBufferUV<struct UV88_t>(struct UV88_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferUV<UV88_t>(FloatBitMap_t *this, const UV88_t *pBuffer, int nPixelCount)
{
  int i; // esi
  int v4; // edx
  int m_nColumns; // edi
  int v6; // eax
  unsigned int v7; // edi

  for ( i = 0; i < this->m_nSlices; ++i )
  {
    v4 = 0;
    if ( this->m_nRows > 0 )
    {
      m_nColumns = this->m_nColumns;
      do
      {
        v6 = 0;
        if ( m_nColumns > 0 )
        {
          do
          {
            *(float *)&this->m_pAttributePtrs[0][i * this->m_nSliceStrideInBytes[0]
                                               + v4 * this->m_nRowStrideInBytes[0]
                                               + v6 * this->m_nStrideInBytes[0]] = (float)((float)(pBuffer[v6].u + 128)
                                                                                         * 0.0078431377)
                                                                                 - 1.0;
            *(float *)&this->m_pAttributePtrs[1][v6 * this->m_nStrideInBytes[1]
                                               + i * this->m_nSliceStrideInBytes[1]
                                               + v4 * this->m_nRowStrideInBytes[1]] = (float)((float)(pBuffer[v6].v + 128)
                                                                                            * 0.0078431377)
                                                                                    - 1.0;
            *(_DWORD *)&this->m_pAttributePtrs[2][i * this->m_nSliceStrideInBytes[2]
                                                + v4 * this->m_nRowStrideInBytes[2]
                                                + v6 * this->m_nStrideInBytes[2]] = 0;
            v7 = i * this->m_nSliceStrideInBytes[3] + v4 * this->m_nRowStrideInBytes[3] + v6 * this->m_nStrideInBytes[3];
            ++v6;
            *(_DWORD *)&this->m_pAttributePtrs[3][v7] = 1065353216;
          }
          while ( v6 < this->m_nColumns );
        }
        m_nColumns = this->m_nColumns;
        ++v4;
        pBuffer += this->m_nColumns;
      }
      while ( v4 < this->m_nRows );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004660C0
// Name: protected: void FloatBitMap_t::LoadFromBufferUVWQ<struct UVWQ8888_t>(struct UVWQ8888_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferUVWQ<UVWQ8888_t>(
        FloatBitMap_t *this,
        const UVWQ8888_t *pBuffer,
        int nPixelCount)
{
  int v3; // edi
  const UVWQ8888_t *v4; // edx
  int m_nColumns; // esi
  int v6; // eax
  char *p_w; // edx
  unsigned int v8; // esi
  int z; // [esp+4h] [ebp-8h]
  int y; // [esp+8h] [ebp-4h]

  v3 = 0;
  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v4 = pBuffer;
    do
    {
      y = 0;
      if ( this->m_nRows > 0 )
      {
        m_nColumns = this->m_nColumns;
        do
        {
          v6 = 0;
          if ( m_nColumns > 0 )
          {
            p_w = &v4->w;
            do
            {
              *(float *)&this->m_pAttributePtrs[0][z * this->m_nSliceStrideInBytes[0]
                                                 + y * this->m_nRowStrideInBytes[0]
                                                 + v6 * this->m_nStrideInBytes[0]] = (float)((float)(*(p_w - 2) + 128)
                                                                                           * 0.0078431377)
                                                                                   - 1.0;
              *(float *)&this->m_pAttributePtrs[1][v6 * this->m_nStrideInBytes[1]
                                                 + z * this->m_nSliceStrideInBytes[1]
                                                 + y * this->m_nRowStrideInBytes[1]] = (float)((float)(*(p_w - 1) + 128)
                                                                                             * 0.0078431377)
                                                                                     - 1.0;
              *(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                 + y * this->m_nRowStrideInBytes[2]
                                                 + v6 * this->m_nStrideInBytes[2]] = (float)((float)(*p_w + 128)
                                                                                           * 0.0078431377)
                                                                                   - 1.0;
              v3 = z;
              v8 = z * this->m_nSliceStrideInBytes[3]
                 + y * this->m_nRowStrideInBytes[3]
                 + v6 * this->m_nStrideInBytes[3];
              ++v6;
              *(float *)&this->m_pAttributePtrs[3][v8] = (float)((float)(p_w[1] + 128) * 0.0078431377) - 1.0;
              p_w += 4;
            }
            while ( v6 < this->m_nColumns );
            v4 = pBuffer;
          }
          m_nColumns = this->m_nColumns;
          v4 += this->m_nColumns;
          pBuffer = v4;
          ++y;
        }
        while ( y < this->m_nRows );
      }
      z = ++v3;
    }
    while ( v3 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466250
// Name: protected: void FloatBitMap_t::LoadFromBufferUVLX<struct UVLX8888_t>(struct UVLX8888_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferUVLX<UVLX8888_t>(
        FloatBitMap_t *this,
        const UVLX8888_t *pBuffer,
        int nPixelCount)
{
  int v3; // esi
  const UVLX8888_t *v4; // ebx
  int v5; // edx
  int m_nColumns; // edi
  int v7; // eax
  unsigned int v8; // edi
  unsigned __int8 *p_l; // [esp+4h] [ebp-4h]

  v3 = 0;
  if ( this->m_nSlices > 0 )
  {
    v4 = pBuffer;
    do
    {
      v5 = 0;
      if ( this->m_nRows > 0 )
      {
        m_nColumns = this->m_nColumns;
        do
        {
          v7 = 0;
          if ( m_nColumns > 0 )
          {
            p_l = &v4->l;
            do
            {
              *(float *)&this->m_pAttributePtrs[0][v3 * this->m_nSliceStrideInBytes[0]
                                                 + v5 * this->m_nRowStrideInBytes[0]
                                                 + v7 * this->m_nStrideInBytes[0]] = (float)((float)((float)((char)*(p_l - 2) + 128) * 2.0)
                                                                                           * 0.0039215689)
                                                                                   - 1.0;
              *(float *)&this->m_pAttributePtrs[1][v3 * this->m_nSliceStrideInBytes[1]
                                                 + v5 * this->m_nRowStrideInBytes[1]
                                                 + v7 * this->m_nStrideInBytes[1]] = (float)((float)((float)((char)*(p_l - 1) + 128) * 2.0)
                                                                                           * 0.0039215689)
                                                                                   - 1.0;
              *(float *)&this->m_pAttributePtrs[2][v3 * this->m_nSliceStrideInBytes[2]
                                                 + v5 * this->m_nRowStrideInBytes[2]
                                                 + v7 * this->m_nStrideInBytes[2]] = (float)*p_l * 0.0039215689;
              p_l += 4;
              v8 = v3 * this->m_nSliceStrideInBytes[3]
                 + v5 * this->m_nRowStrideInBytes[3]
                 + v7 * this->m_nStrideInBytes[3];
              ++v7;
              *(_DWORD *)&this->m_pAttributePtrs[3][v8] = 1065353216;
            }
            while ( v7 < this->m_nColumns );
            v4 = pBuffer;
          }
          m_nColumns = this->m_nColumns;
          ++v5;
          v4 += this->m_nColumns;
          pBuffer = v4;
        }
        while ( v5 < this->m_nRows );
      }
      ++v3;
    }
    while ( v3 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004663C0
// Name: protected: void FloatBitMap_t::WriteToBufferRGBA<struct ABGR8888_t>(struct ABGR8888_t __near *,int,unsigned short const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferRGBA<ABGR8888_t>(
        FloatBitMap_t *this,
        ABGR8888_t *pBuffer,
        int nPixelCount,
        const unsigned __int16 *pInvGammaTable)
{
  int v4; // ebx
  ABGR8888_t *v5; // esi
  int v6; // eax
  unsigned __int8 *p_g; // esi
  float v8; // xmm2_4
  int v9; // edi
  float v10; // xmm2_4
  int v11; // edi
  float v12; // xmm2_4
  int v13; // edi
  float v14; // xmm2_4
  int v15; // edi
  int z; // [esp+4h] [ebp-8h]
  int y; // [esp+8h] [ebp-4h]

  v4 = 0;
  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      for ( y = 0; y < this->m_nRows; ++y )
      {
        v6 = 0;
        if ( this->m_nColumns > 0 )
        {
          p_g = &v5->g;
          do
          {
            v8 = (float)(*(float *)&this->m_pAttributePtrs[0][v6 * this->m_nStrideInBytes[0]
                                                            + v4 * this->m_nSliceStrideInBytes[0]
                                                            + y * this->m_nRowStrideInBytes[0]]
                       * 1023.0)
               + 0.5;
            if ( (int)v8 >= 0 )
            {
              v9 = 1023;
              if ( (int)v8 <= 1023 )
                v9 = (int)v8;
            }
            else
            {
              v9 = 0;
            }
            p_g[1] = pInvGammaTable[v9] >> 2;
            v10 = (float)(*(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                             + y * this->m_nRowStrideInBytes[1]
                                                             + v6 * this->m_nStrideInBytes[1]]
                        * 1023.0)
                + 0.5;
            if ( (int)v10 >= 0 )
            {
              v11 = 1023;
              if ( (int)v10 <= 1023 )
                v11 = (int)v10;
            }
            else
            {
              v11 = 0;
            }
            *p_g = pInvGammaTable[v11] >> 2;
            v12 = (float)(*(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                             + y * this->m_nRowStrideInBytes[2]
                                                             + v6 * this->m_nStrideInBytes[2]]
                        * 1023.0)
                + 0.5;
            if ( (int)v12 >= 0 )
            {
              v13 = 1023;
              if ( (int)v12 <= 1023 )
                v13 = (int)v12;
            }
            else
            {
              v13 = 0;
            }
            v4 = z;
            *(p_g - 1) = pInvGammaTable[v13] >> 2;
            v14 = (float)(*(float *)&this->m_pAttributePtrs[3][z * this->m_nSliceStrideInBytes[3]
                                                             + y * this->m_nRowStrideInBytes[3]
                                                             + v6 * this->m_nStrideInBytes[3]]
                        * 1023.0)
                + 0.5;
            if ( (int)v14 >= 0 )
            {
              v15 = 1023;
              if ( (int)v14 <= 1023 )
                v15 = (int)v14;
            }
            else
            {
              v15 = 0;
            }
            *(p_g - 2) = v15 >> 2;
            ++v6;
            p_g += 4;
          }
          while ( v6 < this->m_nColumns );
          v5 = pBuffer;
        }
        v5 += this->m_nColumns;
        pBuffer = v5;
      }
      z = ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004665B0
// Name: protected: void FloatBitMap_t::WriteToBufferRGBA<struct RGBA8888_t>(struct RGBA8888_t __near *,int,unsigned short const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferRGBA<RGBA8888_t>(
        FloatBitMap_t *this,
        RGBA8888_t *pBuffer,
        int nPixelCount,
        const unsigned __int16 *pInvGammaTable)
{
  int v4; // ebx
  RGBA8888_t *v5; // esi
  int v6; // eax
  unsigned __int8 *p_b; // esi
  float v8; // xmm2_4
  int v9; // edi
  float v10; // xmm2_4
  int v11; // edi
  float v12; // xmm2_4
  int v13; // edi
  float v14; // xmm2_4
  int v15; // edi
  int z; // [esp+4h] [ebp-8h]
  int y; // [esp+8h] [ebp-4h]

  v4 = 0;
  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      for ( y = 0; y < this->m_nRows; ++y )
      {
        v6 = 0;
        if ( this->m_nColumns > 0 )
        {
          p_b = &v5->b;
          do
          {
            v8 = (float)(*(float *)&this->m_pAttributePtrs[0][v6 * this->m_nStrideInBytes[0]
                                                            + v4 * this->m_nSliceStrideInBytes[0]
                                                            + y * this->m_nRowStrideInBytes[0]]
                       * 1023.0)
               + 0.5;
            if ( (int)v8 >= 0 )
            {
              v9 = 1023;
              if ( (int)v8 <= 1023 )
                v9 = (int)v8;
            }
            else
            {
              v9 = 0;
            }
            *(p_b - 2) = pInvGammaTable[v9] >> 2;
            v10 = (float)(*(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                             + y * this->m_nRowStrideInBytes[1]
                                                             + v6 * this->m_nStrideInBytes[1]]
                        * 1023.0)
                + 0.5;
            if ( (int)v10 >= 0 )
            {
              v11 = 1023;
              if ( (int)v10 <= 1023 )
                v11 = (int)v10;
            }
            else
            {
              v11 = 0;
            }
            *(p_b - 1) = pInvGammaTable[v11] >> 2;
            v12 = (float)(*(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                             + y * this->m_nRowStrideInBytes[2]
                                                             + v6 * this->m_nStrideInBytes[2]]
                        * 1023.0)
                + 0.5;
            if ( (int)v12 >= 0 )
            {
              v13 = 1023;
              if ( (int)v12 <= 1023 )
                v13 = (int)v12;
            }
            else
            {
              v13 = 0;
            }
            v4 = z;
            *p_b = pInvGammaTable[v13] >> 2;
            v14 = (float)(*(float *)&this->m_pAttributePtrs[3][z * this->m_nSliceStrideInBytes[3]
                                                             + y * this->m_nRowStrideInBytes[3]
                                                             + v6 * this->m_nStrideInBytes[3]]
                        * 1023.0)
                + 0.5;
            if ( (int)v14 >= 0 )
            {
              v15 = 1023;
              if ( (int)v14 <= 1023 )
                v15 = (int)v14;
            }
            else
            {
              v15 = 0;
            }
            p_b[1] = v15 >> 2;
            ++v6;
            p_b += 4;
          }
          while ( v6 < this->m_nColumns );
          v5 = pBuffer;
        }
        v5 += this->m_nColumns;
        pBuffer = v5;
      }
      z = ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004667A0
// Name: protected: void FloatBitMap_t::WriteToBufferRGBA<struct BGRA8888_t>(struct BGRA8888_t __near *,int,unsigned short const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferRGBA<BGRA8888_t>(
        FloatBitMap_t *this,
        BGRA8888_t *pBuffer,
        int nPixelCount,
        const unsigned __int16 *pInvGammaTable)
{
  int v4; // ebx
  BGRA8888_t *v5; // esi
  int v6; // eax
  unsigned __int8 *p_g; // esi
  float v8; // xmm2_4
  int v9; // edi
  float v10; // xmm2_4
  int v11; // edi
  float v12; // xmm2_4
  int v13; // edi
  float v14; // xmm2_4
  int v15; // edi
  int z; // [esp+4h] [ebp-8h]
  int y; // [esp+8h] [ebp-4h]

  v4 = 0;
  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      for ( y = 0; y < this->m_nRows; ++y )
      {
        v6 = 0;
        if ( this->m_nColumns > 0 )
        {
          p_g = &v5->g;
          do
          {
            v8 = (float)(*(float *)&this->m_pAttributePtrs[0][v6 * this->m_nStrideInBytes[0]
                                                            + v4 * this->m_nSliceStrideInBytes[0]
                                                            + y * this->m_nRowStrideInBytes[0]]
                       * 1023.0)
               + 0.5;
            if ( (int)v8 >= 0 )
            {
              v9 = 1023;
              if ( (int)v8 <= 1023 )
                v9 = (int)v8;
            }
            else
            {
              v9 = 0;
            }
            p_g[1] = pInvGammaTable[v9] >> 2;
            v10 = (float)(*(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                             + y * this->m_nRowStrideInBytes[1]
                                                             + v6 * this->m_nStrideInBytes[1]]
                        * 1023.0)
                + 0.5;
            if ( (int)v10 >= 0 )
            {
              v11 = 1023;
              if ( (int)v10 <= 1023 )
                v11 = (int)v10;
            }
            else
            {
              v11 = 0;
            }
            *p_g = pInvGammaTable[v11] >> 2;
            v12 = (float)(*(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                             + y * this->m_nRowStrideInBytes[2]
                                                             + v6 * this->m_nStrideInBytes[2]]
                        * 1023.0)
                + 0.5;
            if ( (int)v12 >= 0 )
            {
              v13 = 1023;
              if ( (int)v12 <= 1023 )
                v13 = (int)v12;
            }
            else
            {
              v13 = 0;
            }
            v4 = z;
            *(p_g - 1) = pInvGammaTable[v13] >> 2;
            v14 = (float)(*(float *)&this->m_pAttributePtrs[3][z * this->m_nSliceStrideInBytes[3]
                                                             + y * this->m_nRowStrideInBytes[3]
                                                             + v6 * this->m_nStrideInBytes[3]]
                        * 1023.0)
                + 0.5;
            if ( (int)v14 >= 0 )
            {
              v15 = 1023;
              if ( (int)v14 <= 1023 )
                v15 = (int)v14;
            }
            else
            {
              v15 = 0;
            }
            p_g[2] = v15 >> 2;
            ++v6;
            p_g += 4;
          }
          while ( v6 < this->m_nColumns );
          v5 = pBuffer;
        }
        v5 += this->m_nColumns;
        pBuffer = v5;
      }
      z = ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466990
// Name: protected: void FloatBitMap_t::WriteToBufferRGB<struct RGB888_t>(struct RGB888_t __near *,int,unsigned short const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferRGB<RGB888_t>(
        FloatBitMap_t *this,
        RGB888_t *pBuffer,
        int nPixelCount,
        const unsigned __int16 *pInvGammaTable)
{
  int v4; // ebx
  RGB888_t *v5; // esi
  int v6; // eax
  unsigned __int8 *p_b; // esi
  float v8; // xmm2_4
  int v9; // edi
  float v10; // xmm2_4
  int v11; // edi
  float v12; // xmm2_4
  int v13; // edi
  int z; // [esp+4h] [ebp-8h]
  int y; // [esp+8h] [ebp-4h]

  v4 = 0;
  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      for ( y = 0; y < this->m_nRows; ++y )
      {
        v6 = 0;
        if ( this->m_nColumns > 0 )
        {
          p_b = &v5->b;
          do
          {
            v8 = (float)(*(float *)&this->m_pAttributePtrs[0][v6 * this->m_nStrideInBytes[0]
                                                            + v4 * this->m_nSliceStrideInBytes[0]
                                                            + y * this->m_nRowStrideInBytes[0]]
                       * 1023.0)
               + 0.5;
            if ( (int)v8 >= 0 )
            {
              v9 = 1023;
              if ( (int)v8 <= 1023 )
                v9 = (int)v8;
            }
            else
            {
              v9 = 0;
            }
            *(p_b - 2) = pInvGammaTable[v9] >> 2;
            v10 = (float)(*(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                             + y * this->m_nRowStrideInBytes[1]
                                                             + v6 * this->m_nStrideInBytes[1]]
                        * 1023.0)
                + 0.5;
            if ( (int)v10 >= 0 )
            {
              v11 = 1023;
              if ( (int)v10 <= 1023 )
                v11 = (int)v10;
            }
            else
            {
              v11 = 0;
            }
            v4 = z;
            *(p_b - 1) = pInvGammaTable[v11] >> 2;
            v12 = (float)(*(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                             + y * this->m_nRowStrideInBytes[2]
                                                             + v6 * this->m_nStrideInBytes[2]]
                        * 1023.0)
                + 0.5;
            if ( (int)v12 >= 0 )
            {
              v13 = 1023;
              if ( (int)v12 <= 1023 )
                v13 = (int)v12;
            }
            else
            {
              v13 = 0;
            }
            *p_b = pInvGammaTable[v13] >> 2;
            ++v6;
            p_b += 3;
          }
          while ( v6 < this->m_nColumns );
          v5 = pBuffer;
        }
        v5 = (RGB888_t *)((char *)v5 + 2 * this->m_nColumns + this->m_nColumns);
        pBuffer = v5;
      }
      z = ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466B30
// Name: protected: void FloatBitMap_t::WriteToBufferRGB<struct BGR888_t>(struct BGR888_t __near *,int,unsigned short const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferRGB<BGR888_t>(
        FloatBitMap_t *this,
        BGR888_t *pBuffer,
        int nPixelCount,
        const unsigned __int16 *pInvGammaTable)
{
  int v4; // ebx
  BGR888_t *v5; // esi
  int v6; // eax
  unsigned __int8 *p_g; // esi
  float v8; // xmm2_4
  int v9; // edi
  float v10; // xmm2_4
  int v11; // edi
  float v12; // xmm2_4
  int v13; // edi
  int z; // [esp+4h] [ebp-8h]
  int y; // [esp+8h] [ebp-4h]

  v4 = 0;
  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      for ( y = 0; y < this->m_nRows; ++y )
      {
        v6 = 0;
        if ( this->m_nColumns > 0 )
        {
          p_g = &v5->g;
          do
          {
            v8 = (float)(*(float *)&this->m_pAttributePtrs[0][v6 * this->m_nStrideInBytes[0]
                                                            + v4 * this->m_nSliceStrideInBytes[0]
                                                            + y * this->m_nRowStrideInBytes[0]]
                       * 1023.0)
               + 0.5;
            if ( (int)v8 >= 0 )
            {
              v9 = 1023;
              if ( (int)v8 <= 1023 )
                v9 = (int)v8;
            }
            else
            {
              v9 = 0;
            }
            p_g[1] = pInvGammaTable[v9] >> 2;
            v10 = (float)(*(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                             + y * this->m_nRowStrideInBytes[1]
                                                             + v6 * this->m_nStrideInBytes[1]]
                        * 1023.0)
                + 0.5;
            if ( (int)v10 >= 0 )
            {
              v11 = 1023;
              if ( (int)v10 <= 1023 )
                v11 = (int)v10;
            }
            else
            {
              v11 = 0;
            }
            v4 = z;
            *p_g = pInvGammaTable[v11] >> 2;
            v12 = (float)(*(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                             + y * this->m_nRowStrideInBytes[2]
                                                             + v6 * this->m_nStrideInBytes[2]]
                        * 1023.0)
                + 0.5;
            if ( (int)v12 >= 0 )
            {
              v13 = 1023;
              if ( (int)v12 <= 1023 )
                v13 = (int)v12;
            }
            else
            {
              v13 = 0;
            }
            *(p_g - 1) = pInvGammaTable[v13] >> 2;
            ++v6;
            p_g += 3;
          }
          while ( v6 < this->m_nColumns );
          v5 = pBuffer;
        }
        v5 = (BGR888_t *)((char *)v5 + 2 * this->m_nColumns + this->m_nColumns);
        pBuffer = v5;
      }
      z = ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466CD0
// Name: protected: void FloatBitMap_t::WriteToBufferRGB<struct BGRX8888_t>(struct BGRX8888_t __near *,int,unsigned short const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferRGB<BGRX8888_t>(
        FloatBitMap_t *this,
        BGRX8888_t *pBuffer,
        int nPixelCount,
        const unsigned __int16 *pInvGammaTable)
{
  int v4; // ebx
  BGRX8888_t *v5; // esi
  int v6; // eax
  unsigned __int8 *p_g; // esi
  float v8; // xmm2_4
  int v9; // edi
  float v10; // xmm2_4
  int v11; // edi
  float v12; // xmm2_4
  int v13; // edi
  int z; // [esp+4h] [ebp-8h]
  int y; // [esp+8h] [ebp-4h]

  v4 = 0;
  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      for ( y = 0; y < this->m_nRows; ++y )
      {
        v6 = 0;
        if ( this->m_nColumns > 0 )
        {
          p_g = &v5->g;
          do
          {
            v8 = (float)(*(float *)&this->m_pAttributePtrs[0][v6 * this->m_nStrideInBytes[0]
                                                            + v4 * this->m_nSliceStrideInBytes[0]
                                                            + y * this->m_nRowStrideInBytes[0]]
                       * 1023.0)
               + 0.5;
            if ( (int)v8 >= 0 )
            {
              v9 = 1023;
              if ( (int)v8 <= 1023 )
                v9 = (int)v8;
            }
            else
            {
              v9 = 0;
            }
            p_g[1] = pInvGammaTable[v9] >> 2;
            v10 = (float)(*(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                             + y * this->m_nRowStrideInBytes[1]
                                                             + v6 * this->m_nStrideInBytes[1]]
                        * 1023.0)
                + 0.5;
            if ( (int)v10 >= 0 )
            {
              v11 = 1023;
              if ( (int)v10 <= 1023 )
                v11 = (int)v10;
            }
            else
            {
              v11 = 0;
            }
            v4 = z;
            *p_g = pInvGammaTable[v11] >> 2;
            v12 = (float)(*(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                             + y * this->m_nRowStrideInBytes[2]
                                                             + v6 * this->m_nStrideInBytes[2]]
                        * 1023.0)
                + 0.5;
            if ( (int)v12 >= 0 )
            {
              v13 = 1023;
              if ( (int)v12 <= 1023 )
                v13 = (int)v12;
            }
            else
            {
              v13 = 0;
            }
            *(p_g - 1) = pInvGammaTable[v13] >> 2;
            ++v6;
            p_g += 4;
          }
          while ( v6 < this->m_nColumns );
          v5 = pBuffer;
        }
        v5 += this->m_nColumns;
        pBuffer = v5;
      }
      z = ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466E70
// Name: protected: void FloatBitMap_t::WriteToBufferUV<struct UV88_t>(struct UV88_t __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferUV<UV88_t>(FloatBitMap_t *this, UV88_t *pBuffer, int nPixelCount)
{
  int v3; // ebx
  UV88_t *v4; // edi
  int i; // esi
  int j; // eax
  int v7; // edx
  int v8; // edx

  v3 = 0;
  if ( this->m_nSlices > 0 )
  {
    v4 = pBuffer;
    do
    {
      for ( i = 0; i < this->m_nRows; pBuffer = v4 )
      {
        for ( j = 0; j < this->m_nColumns; ++j )
        {
          v7 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[0][j * this->m_nStrideInBytes[0]
                                                                       + v3 * this->m_nSliceStrideInBytes[0]
                                                                       + i * this->m_nRowStrideInBytes[0]]
                                  + 1.0)
                          * 127.5);
          if ( v7 >= 0 )
          {
            if ( v7 > 255 )
              LOBYTE(v7) = -1;
          }
          else
          {
            LOBYTE(v7) = 0;
          }
          pBuffer[j].u = v7 + 0x80;
          v8 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[1][v3 * this->m_nSliceStrideInBytes[1]
                                                                       + i * this->m_nRowStrideInBytes[1]
                                                                       + j * this->m_nStrideInBytes[1]]
                                  + 1.0)
                          * 127.5);
          if ( v8 >= 0 )
          {
            if ( v8 > 255 )
              LOBYTE(v8) = -1;
          }
          else
          {
            LOBYTE(v8) = 0;
          }
          v4 = pBuffer;
          pBuffer[j].v = v8 + 0x80;
        }
        ++i;
        v4 += this->m_nColumns;
      }
      ++v3;
    }
    while ( v3 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466F80
// Name: protected: void FloatBitMap_t::WriteToBufferUVWQ<struct UVWQ8888_t>(struct UVWQ8888_t __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferUVWQ<UVWQ8888_t>(FloatBitMap_t *this, UVWQ8888_t *pBuffer, int nPixelCount)
{
  int v3; // edi
  UVWQ8888_t *v4; // esi
  int v5; // edx
  char *p_w; // esi
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int z; // [esp+4h] [ebp-8h]
  int y; // [esp+8h] [ebp-4h]

  v3 = 0;
  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v4 = pBuffer;
    do
    {
      for ( y = 0; y < this->m_nRows; ++y )
      {
        v5 = 0;
        if ( this->m_nColumns > 0 )
        {
          p_w = &v4->w;
          do
          {
            v7 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[0][v5 * this->m_nStrideInBytes[0]
                                                                         + v3 * this->m_nSliceStrideInBytes[0]
                                                                         + y * this->m_nRowStrideInBytes[0]]
                                    + 1.0)
                            * 127.5);
            if ( v7 >= 0 )
            {
              if ( v7 > 255 )
                LOBYTE(v7) = -1;
            }
            else
            {
              LOBYTE(v7) = 0;
            }
            *(p_w - 2) = v7 + 0x80;
            v8 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                                         + y * this->m_nRowStrideInBytes[1]
                                                                         + v5 * this->m_nStrideInBytes[1]]
                                    + 1.0)
                            * 127.5);
            if ( v8 >= 0 )
            {
              if ( v8 > 255 )
                LOBYTE(v8) = -1;
            }
            else
            {
              LOBYTE(v8) = 0;
            }
            *(p_w - 1) = v8 + 0x80;
            v3 = z;
            v9 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                                         + y * this->m_nRowStrideInBytes[2]
                                                                         + v5 * this->m_nStrideInBytes[2]]
                                    + 1.0)
                            * 127.5);
            if ( v9 >= 0 )
            {
              if ( v9 > 255 )
                LOBYTE(v9) = -1;
            }
            else
            {
              LOBYTE(v9) = 0;
            }
            *p_w = v9 + 0x80;
            v10 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[3][v5 * this->m_nStrideInBytes[3]
                                                                          + z * this->m_nSliceStrideInBytes[3]
                                                                          + y * this->m_nRowStrideInBytes[3]]
                                     + 1.0)
                             * 127.5);
            if ( v10 >= 0 )
            {
              if ( v10 > 255 )
                LOBYTE(v10) = -1;
            }
            else
            {
              LOBYTE(v10) = 0;
            }
            p_w[1] = v10 + 0x80;
            ++v5;
            p_w += 4;
          }
          while ( v5 < this->m_nColumns );
          v4 = pBuffer;
        }
        v4 += this->m_nColumns;
        pBuffer = v4;
      }
      z = ++v3;
    }
    while ( v3 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00467150
// Name: protected: void FloatBitMap_t::WriteToBufferUVLX<struct UVLX8888_t>(struct UVLX8888_t __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferUVLX<UVLX8888_t>(FloatBitMap_t *this, UVLX8888_t *pBuffer, int nPixelCount)
{
  int v3; // ebx
  UVLX8888_t *v4; // esi
  int v5; // edx
  unsigned __int8 *p_l; // esi
  int v7; // eax
  int v8; // eax
  float v9; // xmm3_4
  int v10; // eax
  int z; // [esp+4h] [ebp-8h]
  int y; // [esp+8h] [ebp-4h]

  v3 = 0;
  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v4 = pBuffer;
    do
    {
      for ( y = 0; y < this->m_nRows; ++y )
      {
        v5 = 0;
        if ( this->m_nColumns > 0 )
        {
          p_l = &v4->l;
          do
          {
            v7 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[0][v5 * this->m_nStrideInBytes[0]
                                                                         + v3 * this->m_nSliceStrideInBytes[0]
                                                                         + y * this->m_nRowStrideInBytes[0]]
                                    + 1.0)
                            * 127.5);
            if ( v7 >= 0 )
            {
              if ( v7 > 255 )
                LOBYTE(v7) = -1;
            }
            else
            {
              LOBYTE(v7) = 0;
            }
            *(p_l - 2) = v7 + 0x80;
            v8 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                                         + y * this->m_nRowStrideInBytes[1]
                                                                         + v5 * this->m_nStrideInBytes[1]]
                                    + 1.0)
                            * 127.5);
            if ( v8 >= 0 )
            {
              if ( v8 > 255 )
                LOBYTE(v8) = -1;
            }
            else
            {
              LOBYTE(v8) = 0;
            }
            v3 = z;
            *(p_l - 1) = v8 + 0x80;
            v9 = *(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                    + y * this->m_nRowStrideInBytes[2]
                                                    + v5 * this->m_nStrideInBytes[2]]
               * 255.0;
            if ( (int)v9 >= 0 )
            {
              LOBYTE(v10) = -1;
              if ( (int)v9 <= 255 )
                v10 = (int)v9;
            }
            else
            {
              LOBYTE(v10) = 0;
            }
            *p_l = v10;
            p_l[1] = -1;
            ++v5;
            p_l += 4;
          }
          while ( v5 < this->m_nColumns );
          v4 = pBuffer;
        }
        v4 += this->m_nColumns;
        pBuffer = v4;
      }
      z = ++v3;
    }
    while ( v3 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B7300
// Name: _dynamic_initializer_for__CDmeAmalgamatedTexture::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAmalgamatedTexture::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAmalgamatedTexture::s_Allocator,
    blockSize: 168,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAmalgamatedTexture pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAmalgamatedTexture::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x004B79D0
// Name: _dynamic_atexit_destructor_for__CDmeAmalgamatedTexture::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAmalgamatedTexture::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAmalgamatedTexture::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x004B7330
// Name: _dynamic_initializer_for__g_CDmeAmalgamatedTexture_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAmalgamatedTexture_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAmalgamatedTexture_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x004B7340
// Name: _dynamic_initializer_for__g_CDmeAmalgamatedTexture_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAmalgamatedTexture_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAmalgamatedTexture_Helper,
           classname: "DmeAmalgamatedTexture",
           pFactory: &g_CDmeAmalgamatedTexture_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x004B78C0
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: &s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>(this: &s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap.m_Buckets);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_elementsToDelete);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x004B7900
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: &s_DMSerializerKeyValues2.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>(this: &s_DMSerializerKeyValues2.m_ElementDict.m_idmap.m_Buckets);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_elementsToDelete);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues2.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x004B7940
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues.m_ElementList);
}

//------------------------------------------------------------------------------
// Address: 0x004B7950
// Name: _dynamic_atexit_destructor_for__g_DmElementFramework__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DmElementFramework__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_DmElementFramework.m_dirtyElements);
  CDependencyGraph::~CDependencyGraph(this: &g_DmElementFramework.m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x004B7970
// Name: _dynamic_atexit_destructor_for__g_AttrNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AttrNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_AttrNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x004B7980
// Name: _dynamic_atexit_destructor_for__g_OperatorNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_OperatorNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_OperatorNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x004B79C0
// Name: _dynamic_atexit_destructor_for__s_ImportDmxV1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ImportDmxV1__()
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::~CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>(this: &s_ImportDmxV1.m_fixedElements);
}

//------------------------------------------------------------------------------
// Address: 0x004B79E0
// Name: _dynamic_atexit_destructor_for__g_CDmeAmalgamatedTexture_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAmalgamatedTexture_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_CDmeAmalgamatedTexture_Factory.m_CallBackList);
}

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00403640
// Name: public: virtual void CDmeAmalgamatedTexture::OnAttributeArrayElementRemoved(class CDmAttribute __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAmalgamatedTexture::OnAttributeArrayElementRemoved(
        vgui::TreeView *this,
        int itemIndex,
        bool bInsertBefore,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004BA580
// Name: public: void FloatBitMap_t::Init(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::Init(FloatBitMap_t *this, int nXSize, int nYSize, int nZSize, char nAttributeMask)
{
  CSOAContainer::PurgeData(this);
  CSOAContainer::SetAttributeType(this, nAttrIdx: 0, nDataType: ATTRDATATYPE_FLOAT, bAllocateMemory: nAttributeMask & 1);
  CSOAContainer::SetAttributeType(
    this,
    nAttrIdx: 1,
    nDataType: ATTRDATATYPE_FLOAT,
    bAllocateMemory: (nAttributeMask & 2) != 0);
  CSOAContainer::SetAttributeType(
    this,
    nAttrIdx: 2,
    nDataType: ATTRDATATYPE_FLOAT,
    bAllocateMemory: (nAttributeMask & 4) != 0);
  CSOAContainer::SetAttributeType(
    this,
    nAttrIdx: 3,
    nDataType: ATTRDATATYPE_FLOAT,
    bAllocateMemory: (nAttributeMask & 8) != 0);
  CSOAContainer::AllocateData(this, nNCols: nXSize, nNRows: nYSize, nSlices: nZSize);
  if ( (nAttributeMask & 8) == 0 )
    CSOAContainer::FillAttr(this, nAttr: 3, flValue: 1.0);
}

//------------------------------------------------------------------------------
// Address: 0x004BA620
// Name: protected: void CDmeAmalgamatedTexture::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAmalgamatedTexture::OnConstruction(CDmeAmalgamatedTexture *this)
{
  CDmaElementArray<CDmeSheetImage> *p_m_ImageList; // edi
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  p_m_ImageList = &this->m_ImageList;
  this->m_ImageList.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "images",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_ImageList);
  CDmAttribute::SetElementTypeSymbol(this: p_m_ImageList->m_pAttribute, typeSymbol: CDmeSheetImage::m_classType);
  value = 1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "packmode", type: AT_INT, pMemory: &this->m_ePackingMode);
  this->m_ePackingMode.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, &value);
  this->m_Sequences.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "sequences",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_Sequences);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Sequences.m_pAttribute, typeSymbol: CDmeSheetSequence::m_classType);
  this->m_nWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "width",
                                  type: AT_INT,
                                  pMemory: &this->m_nWidth);
  this->m_nHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "height",
                                   type: AT_INT,
                                   pMemory: &this->m_nHeight);
  this->m_pPackedImage.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "packedImage",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_pPackedImage);
  CDmAttribute::SetElementTypeSymbol(this: this->m_pPackedImage.m_pAttribute, typeSymbol: CDmeImage::m_classType);
  this->m_SequenceCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004BA770
// Name: protected: CDmeAmalgamatedTexture::CDmeAmalgamatedTexture(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeAmalgamatedTexture *__thiscall CDmeAmalgamatedTexture::CDmeAmalgamatedTexture(
        CDmeAmalgamatedTexture *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeAmalgamatedTexture_vtbl *)&CDmeAmalgamatedTexture::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_ImageList);
  this->m_ePackingMode.m_pAttribute = nullptr;
  this->m_ePackingMode.m_Storage = 0;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Sequences);
  this->m_nWidth.m_pAttribute = nullptr;
  this->m_nWidth.m_Storage = 0;
  this->m_nHeight.m_pAttribute = nullptr;
  this->m_nHeight.m_Storage = 0;
  this->m_pPackedImage.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_pPackedImage.m_pAttribute = nullptr;
  this->m_pPackedImage.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004BA7F0
// Name: public: virtual bool CDmeAmalgamatedTexture::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAmalgamatedTexture::IsA(CDmeAmalgamatedTexture *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAmalgamatedTexture::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BA820
// Name: public: virtual int CDmeAmalgamatedTexture::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAmalgamatedTexture::GetInheritanceDepth(CDmeAmalgamatedTexture *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAmalgamatedTexture::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BA860
// Name: protected: virtual void CDmeAmalgamatedTexture::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAmalgamatedTexture::PerformConstruction(CDmeAmalgamatedTexture *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeAmalgamatedTexture::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004DA960
// Name: protected: void FloatBitMap_t::LoadFromBufferRGBA<struct ABGR8888_t>(struct ABGR8888_t const __near *,int,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferRGBA<ABGR8888_t>(
        FloatBitMap_t *this,
        const ABGR8888_t *pBuffer,
        int nPixelCount,
        const float *pGammaTable)
{
  const ABGR8888_t *v4; // esi
  int v5; // ebx
  int m_nColumns; // edx
  int v7; // eax
  unsigned __int8 *p_g; // edi
  double v9; // st7
  unsigned int v10; // edx
  int y; // [esp+0h] [ebp-Ch]
  unsigned __int8 *v12; // [esp+4h] [ebp-8h]
  int z; // [esp+8h] [ebp-4h]

  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v4 = pBuffer;
    do
    {
      v5 = 0;
      y = 0;
      if ( this->m_nRows > 0 )
      {
        m_nColumns = this->m_nColumns;
        do
        {
          v7 = 0;
          if ( m_nColumns > 0 )
          {
            p_g = &v4->g;
            v12 = &v4->g;
            do
            {
              *(float *)&this->m_pAttributePtrs[0][z * this->m_nSliceStrideInBytes[0]
                                                 + v5 * this->m_nRowStrideInBytes[0]
                                                 + v7 * this->m_nStrideInBytes[0]] = pGammaTable[(4 * p_g[1])
                                                                                               | ((int)p_g[1] >> 6)];
              *(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                 + y * this->m_nRowStrideInBytes[1]
                                                 + v7 * this->m_nStrideInBytes[1]] = pGammaTable[(4 * *v12)
                                                                                               | ((int)*v12 >> 6)];
              v9 = pGammaTable[(4 * *(v12 - 1)) | ((int)*(v12 - 1) >> 6)];
              v12 += 4;
              p_g = v12;
              *(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                 + y * this->m_nRowStrideInBytes[2]
                                                 + v7 * this->m_nStrideInBytes[2]] = v9;
              v5 = y;
              v10 = v7 * this->m_nStrideInBytes[3]
                  + z * this->m_nSliceStrideInBytes[3]
                  + y * this->m_nRowStrideInBytes[3];
              ++v7;
              *(float *)&this->m_pAttributePtrs[3][v10] = (float)((4 * *(v12 - 6)) | ((int)*(v12 - 6) >> 6))
                                                        * 0.00097751711;
            }
            while ( v7 < this->m_nColumns );
            v4 = pBuffer;
          }
          m_nColumns = this->m_nColumns;
          ++v5;
          v4 += this->m_nColumns;
          pBuffer = v4;
          y = v5;
        }
        while ( v5 < this->m_nRows );
      }
      ++z;
    }
    while ( z < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DAAF0
// Name: protected: void FloatBitMap_t::LoadFromBufferRGBA<struct RGBA8888_t>(struct RGBA8888_t const __near *,int,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferRGBA<RGBA8888_t>(
        FloatBitMap_t *this,
        const RGBA8888_t *pBuffer,
        int nPixelCount,
        const float *pGammaTable)
{
  const RGBA8888_t *v4; // esi
  int v5; // ebx
  int m_nColumns; // edx
  int v7; // eax
  unsigned __int8 *p_b; // edi
  double v9; // st7
  unsigned int v10; // edx
  int y; // [esp+0h] [ebp-Ch]
  unsigned __int8 *v12; // [esp+4h] [ebp-8h]
  int z; // [esp+8h] [ebp-4h]

  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v4 = pBuffer;
    do
    {
      v5 = 0;
      y = 0;
      if ( this->m_nRows > 0 )
      {
        m_nColumns = this->m_nColumns;
        do
        {
          v7 = 0;
          if ( m_nColumns > 0 )
          {
            p_b = &v4->b;
            v12 = &v4->b;
            do
            {
              *(float *)&this->m_pAttributePtrs[0][z * this->m_nSliceStrideInBytes[0]
                                                 + v5 * this->m_nRowStrideInBytes[0]
                                                 + v7 * this->m_nStrideInBytes[0]] = pGammaTable[(4 * *(p_b - 2))
                                                                                               | ((int)*(p_b - 2) >> 6)];
              *(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                 + y * this->m_nRowStrideInBytes[1]
                                                 + v7 * this->m_nStrideInBytes[1]] = pGammaTable[(4 * *(v12 - 1))
                                                                                               | ((int)*(v12 - 1) >> 6)];
              v9 = pGammaTable[(4 * *v12) | ((int)*v12 >> 6)];
              v12 += 4;
              p_b = v12;
              *(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                 + y * this->m_nRowStrideInBytes[2]
                                                 + v7 * this->m_nStrideInBytes[2]] = v9;
              v5 = y;
              v10 = v7 * this->m_nStrideInBytes[3]
                  + z * this->m_nSliceStrideInBytes[3]
                  + y * this->m_nRowStrideInBytes[3];
              ++v7;
              *(float *)&this->m_pAttributePtrs[3][v10] = (float)((4 * *(v12 - 3)) | ((int)*(v12 - 3) >> 6))
                                                        * 0.00097751711;
            }
            while ( v7 < this->m_nColumns );
            v4 = pBuffer;
          }
          m_nColumns = this->m_nColumns;
          ++v5;
          v4 += this->m_nColumns;
          pBuffer = v4;
          y = v5;
        }
        while ( v5 < this->m_nRows );
      }
      ++z;
    }
    while ( z < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DAC80
// Name: protected: void FloatBitMap_t::LoadFromBufferRGBA<struct BGRA8888_t>(struct BGRA8888_t const __near *,int,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferRGBA<BGRA8888_t>(
        FloatBitMap_t *this,
        const BGRA8888_t *pBuffer,
        int nPixelCount,
        const float *pGammaTable)
{
  const BGRA8888_t *v4; // esi
  int v5; // ebx
  int m_nColumns; // edx
  int v7; // eax
  unsigned __int8 *p_g; // edi
  double v9; // st7
  unsigned int v10; // edx
  int y; // [esp+0h] [ebp-Ch]
  unsigned __int8 *v12; // [esp+4h] [ebp-8h]
  int z; // [esp+8h] [ebp-4h]

  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v4 = pBuffer;
    do
    {
      v5 = 0;
      y = 0;
      if ( this->m_nRows > 0 )
      {
        m_nColumns = this->m_nColumns;
        do
        {
          v7 = 0;
          if ( m_nColumns > 0 )
          {
            p_g = &v4->g;
            v12 = &v4->g;
            do
            {
              *(float *)&this->m_pAttributePtrs[0][z * this->m_nSliceStrideInBytes[0]
                                                 + v5 * this->m_nRowStrideInBytes[0]
                                                 + v7 * this->m_nStrideInBytes[0]] = pGammaTable[(4 * p_g[1])
                                                                                               | ((int)p_g[1] >> 6)];
              *(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                 + y * this->m_nRowStrideInBytes[1]
                                                 + v7 * this->m_nStrideInBytes[1]] = pGammaTable[(4 * *v12)
                                                                                               | ((int)*v12 >> 6)];
              v9 = pGammaTable[(4 * *(v12 - 1)) | ((int)*(v12 - 1) >> 6)];
              v12 += 4;
              p_g = v12;
              *(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                 + y * this->m_nRowStrideInBytes[2]
                                                 + v7 * this->m_nStrideInBytes[2]] = v9;
              v5 = y;
              v10 = v7 * this->m_nStrideInBytes[3]
                  + z * this->m_nSliceStrideInBytes[3]
                  + y * this->m_nRowStrideInBytes[3];
              ++v7;
              *(float *)&this->m_pAttributePtrs[3][v10] = (float)((4 * *(v12 - 2)) | ((int)*(v12 - 2) >> 6))
                                                        * 0.00097751711;
            }
            while ( v7 < this->m_nColumns );
            v4 = pBuffer;
          }
          m_nColumns = this->m_nColumns;
          ++v5;
          v4 += this->m_nColumns;
          pBuffer = v4;
          y = v5;
        }
        while ( v5 < this->m_nRows );
      }
      ++z;
    }
    while ( z < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DAE10
// Name: protected: void FloatBitMap_t::LoadFromBufferRGB<struct RGB888_t>(struct RGB888_t const __near *,int,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferRGB<RGB888_t>(
        FloatBitMap_t *this,
        const RGB888_t *pBuffer,
        int nPixelCount,
        const float *pGammaTable)
{
  int v4; // edx
  const RGB888_t *v5; // ebx
  int v6; // edi
  int m_nColumns; // esi
  int v8; // eax
  double v9; // st7
  unsigned __int8 *v10; // edx
  unsigned int v11; // esi
  int y; // [esp+0h] [ebp-Ch]
  int z; // [esp+4h] [ebp-8h]
  unsigned __int8 *p_b; // [esp+8h] [ebp-4h]

  v4 = 0;
  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      v6 = 0;
      y = 0;
      if ( this->m_nRows > 0 )
      {
        m_nColumns = this->m_nColumns;
        do
        {
          v8 = 0;
          if ( m_nColumns > 0 )
          {
            p_b = &v5->b;
            do
            {
              *(float *)&this->m_pAttributePtrs[0][z * this->m_nSliceStrideInBytes[0]
                                                 + v6 * this->m_nRowStrideInBytes[0]
                                                 + v8 * this->m_nStrideInBytes[0]] = pGammaTable[(4 * *(p_b - 2))
                                                                                               | ((int)*(p_b - 2) >> 6)];
              v9 = pGammaTable[(4 * *(p_b - 1)) | ((int)*(p_b - 1) >> 6)];
              v10 = p_b;
              p_b += 3;
              *(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                 + y * this->m_nRowStrideInBytes[1]
                                                 + v8 * this->m_nStrideInBytes[1]] = v9;
              v6 = y;
              *(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                 + y * this->m_nRowStrideInBytes[2]
                                                 + v8 * this->m_nStrideInBytes[2]] = pGammaTable[(4 * *v10)
                                                                                               | ((int)*v10 >> 6)];
              v4 = z;
              v11 = z * this->m_nSliceStrideInBytes[3]
                  + y * this->m_nRowStrideInBytes[3]
                  + v8 * this->m_nStrideInBytes[3];
              ++v8;
              *(_DWORD *)&this->m_pAttributePtrs[3][v11] = 1065353216;
            }
            while ( v8 < this->m_nColumns );
            v5 = pBuffer;
          }
          m_nColumns = this->m_nColumns;
          ++v6;
          v5 = (const RGB888_t *)((char *)v5 + 2 * this->m_nColumns + this->m_nColumns);
          pBuffer = v5;
          y = v6;
        }
        while ( v6 < this->m_nRows );
      }
      z = ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DAF80
// Name: protected: void FloatBitMap_t::LoadFromBufferRGB<struct BGR888_t>(struct BGR888_t const __near *,int,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferRGB<BGR888_t>(
        FloatBitMap_t *this,
        const BGR888_t *pBuffer,
        int nPixelCount,
        const float *pGammaTable)
{
  int v4; // edx
  const BGR888_t *v5; // ebx
  int v6; // edi
  int m_nColumns; // esi
  int v8; // eax
  double v9; // st7
  unsigned __int8 *v10; // edx
  unsigned int v11; // esi
  int y; // [esp+0h] [ebp-Ch]
  int z; // [esp+4h] [ebp-8h]
  unsigned __int8 *p_g; // [esp+8h] [ebp-4h]

  v4 = 0;
  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      v6 = 0;
      y = 0;
      if ( this->m_nRows > 0 )
      {
        m_nColumns = this->m_nColumns;
        do
        {
          v8 = 0;
          if ( m_nColumns > 0 )
          {
            p_g = &v5->g;
            do
            {
              *(float *)&this->m_pAttributePtrs[0][z * this->m_nSliceStrideInBytes[0]
                                                 + v6 * this->m_nRowStrideInBytes[0]
                                                 + v8 * this->m_nStrideInBytes[0]] = pGammaTable[(4 * p_g[1])
                                                                                               | ((int)p_g[1] >> 6)];
              v9 = pGammaTable[(4 * *p_g) | ((int)*p_g >> 6)];
              v10 = p_g;
              p_g += 3;
              *(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                 + y * this->m_nRowStrideInBytes[1]
                                                 + v8 * this->m_nStrideInBytes[1]] = v9;
              v6 = y;
              *(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                 + y * this->m_nRowStrideInBytes[2]
                                                 + v8 * this->m_nStrideInBytes[2]] = pGammaTable[(4 * *(v10 - 1))
                                                                                               | ((int)*(v10 - 1) >> 6)];
              v4 = z;
              v11 = z * this->m_nSliceStrideInBytes[3]
                  + y * this->m_nRowStrideInBytes[3]
                  + v8 * this->m_nStrideInBytes[3];
              ++v8;
              *(_DWORD *)&this->m_pAttributePtrs[3][v11] = 1065353216;
            }
            while ( v8 < this->m_nColumns );
            v5 = pBuffer;
          }
          m_nColumns = this->m_nColumns;
          ++v6;
          v5 = (const BGR888_t *)((char *)v5 + 2 * this->m_nColumns + this->m_nColumns);
          pBuffer = v5;
          y = v6;
        }
        while ( v6 < this->m_nRows );
      }
      z = ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DB0E0
// Name: protected: void FloatBitMap_t::LoadFromBufferRGB<struct BGRX8888_t>(struct BGRX8888_t const __near *,int,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferRGB<BGRX8888_t>(
        FloatBitMap_t *this,
        const BGRX8888_t *pBuffer,
        int nPixelCount,
        const float *pGammaTable)
{
  int v4; // edx
  const BGRX8888_t *v5; // ebx
  int v6; // edi
  int m_nColumns; // esi
  int v8; // eax
  double v9; // st7
  unsigned __int8 *v10; // edx
  unsigned int v11; // esi
  int y; // [esp+0h] [ebp-Ch]
  int z; // [esp+4h] [ebp-8h]
  unsigned __int8 *p_g; // [esp+8h] [ebp-4h]

  v4 = 0;
  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      v6 = 0;
      y = 0;
      if ( this->m_nRows > 0 )
      {
        m_nColumns = this->m_nColumns;
        do
        {
          v8 = 0;
          if ( m_nColumns > 0 )
          {
            p_g = &v5->g;
            do
            {
              *(float *)&this->m_pAttributePtrs[0][z * this->m_nSliceStrideInBytes[0]
                                                 + v6 * this->m_nRowStrideInBytes[0]
                                                 + v8 * this->m_nStrideInBytes[0]] = pGammaTable[(4 * p_g[1])
                                                                                               | ((int)p_g[1] >> 6)];
              v9 = pGammaTable[(4 * *p_g) | ((int)*p_g >> 6)];
              v10 = p_g;
              p_g += 4;
              *(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                 + y * this->m_nRowStrideInBytes[1]
                                                 + v8 * this->m_nStrideInBytes[1]] = v9;
              v6 = y;
              *(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                 + y * this->m_nRowStrideInBytes[2]
                                                 + v8 * this->m_nStrideInBytes[2]] = pGammaTable[(4 * *(v10 - 1))
                                                                                               | ((int)*(v10 - 1) >> 6)];
              v4 = z;
              v11 = z * this->m_nSliceStrideInBytes[3]
                  + y * this->m_nRowStrideInBytes[3]
                  + v8 * this->m_nStrideInBytes[3];
              ++v8;
              *(_DWORD *)&this->m_pAttributePtrs[3][v11] = 1065353216;
            }
            while ( v8 < this->m_nColumns );
            v5 = pBuffer;
          }
          m_nColumns = this->m_nColumns;
          ++v6;
          v5 += this->m_nColumns;
          pBuffer = v5;
          y = v6;
        }
        while ( v6 < this->m_nRows );
      }
      z = ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DB240
// Name: protected: void FloatBitMap_t::LoadFromBufferUV<struct UV88_t>(struct UV88_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferUV<UV88_t>(FloatBitMap_t *this, const UV88_t *pBuffer, int nPixelCount)
{
  int i; // esi
  int v4; // edx
  int m_nColumns; // edi
  int v6; // eax
  unsigned int v7; // edi

  for ( i = 0; i < this->m_nSlices; ++i )
  {
    v4 = 0;
    if ( this->m_nRows > 0 )
    {
      m_nColumns = this->m_nColumns;
      do
      {
        v6 = 0;
        if ( m_nColumns > 0 )
        {
          do
          {
            *(float *)&this->m_pAttributePtrs[0][i * this->m_nSliceStrideInBytes[0]
                                               + v4 * this->m_nRowStrideInBytes[0]
                                               + v6 * this->m_nStrideInBytes[0]] = (float)((float)(pBuffer[v6].u + 128)
                                                                                         * 0.0078431377)
                                                                                 - 1.0;
            *(float *)&this->m_pAttributePtrs[1][v6 * this->m_nStrideInBytes[1]
                                               + i * this->m_nSliceStrideInBytes[1]
                                               + v4 * this->m_nRowStrideInBytes[1]] = (float)((float)(pBuffer[v6].v + 128)
                                                                                            * 0.0078431377)
                                                                                    - 1.0;
            *(_DWORD *)&this->m_pAttributePtrs[2][i * this->m_nSliceStrideInBytes[2]
                                                + v4 * this->m_nRowStrideInBytes[2]
                                                + v6 * this->m_nStrideInBytes[2]] = 0;
            v7 = i * this->m_nSliceStrideInBytes[3] + v4 * this->m_nRowStrideInBytes[3] + v6 * this->m_nStrideInBytes[3];
            ++v6;
            *(_DWORD *)&this->m_pAttributePtrs[3][v7] = 1065353216;
          }
          while ( v6 < this->m_nColumns );
        }
        m_nColumns = this->m_nColumns;
        ++v4;
        pBuffer += this->m_nColumns;
      }
      while ( v4 < this->m_nRows );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DB380
// Name: protected: void FloatBitMap_t::LoadFromBufferUVWQ<struct UVWQ8888_t>(struct UVWQ8888_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferUVWQ<UVWQ8888_t>(
        FloatBitMap_t *this,
        const UVWQ8888_t *pBuffer,
        int nPixelCount)
{
  int v3; // edi
  const UVWQ8888_t *v4; // edx
  int m_nColumns; // esi
  int v6; // eax
  char *p_w; // edx
  unsigned int v8; // esi
  int z; // [esp+4h] [ebp-8h]
  int y; // [esp+8h] [ebp-4h]

  v3 = 0;
  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v4 = pBuffer;
    do
    {
      y = 0;
      if ( this->m_nRows > 0 )
      {
        m_nColumns = this->m_nColumns;
        do
        {
          v6 = 0;
          if ( m_nColumns > 0 )
          {
            p_w = &v4->w;
            do
            {
              *(float *)&this->m_pAttributePtrs[0][z * this->m_nSliceStrideInBytes[0]
                                                 + y * this->m_nRowStrideInBytes[0]
                                                 + v6 * this->m_nStrideInBytes[0]] = (float)((float)(*(p_w - 2) + 128)
                                                                                           * 0.0078431377)
                                                                                   - 1.0;
              *(float *)&this->m_pAttributePtrs[1][v6 * this->m_nStrideInBytes[1]
                                                 + z * this->m_nSliceStrideInBytes[1]
                                                 + y * this->m_nRowStrideInBytes[1]] = (float)((float)(*(p_w - 1) + 128)
                                                                                             * 0.0078431377)
                                                                                     - 1.0;
              *(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                 + y * this->m_nRowStrideInBytes[2]
                                                 + v6 * this->m_nStrideInBytes[2]] = (float)((float)(*p_w + 128)
                                                                                           * 0.0078431377)
                                                                                   - 1.0;
              v3 = z;
              v8 = z * this->m_nSliceStrideInBytes[3]
                 + y * this->m_nRowStrideInBytes[3]
                 + v6 * this->m_nStrideInBytes[3];
              ++v6;
              *(float *)&this->m_pAttributePtrs[3][v8] = (float)((float)(p_w[1] + 128) * 0.0078431377) - 1.0;
              p_w += 4;
            }
            while ( v6 < this->m_nColumns );
            v4 = pBuffer;
          }
          m_nColumns = this->m_nColumns;
          v4 += this->m_nColumns;
          pBuffer = v4;
          ++y;
        }
        while ( y < this->m_nRows );
      }
      z = ++v3;
    }
    while ( v3 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DB510
// Name: protected: void FloatBitMap_t::LoadFromBufferUVLX<struct UVLX8888_t>(struct UVLX8888_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferUVLX<UVLX8888_t>(
        FloatBitMap_t *this,
        const UVLX8888_t *pBuffer,
        int nPixelCount)
{
  int v3; // esi
  const UVLX8888_t *v4; // ebx
  int v5; // edx
  int m_nColumns; // edi
  int v7; // eax
  unsigned int v8; // edi
  unsigned __int8 *p_l; // [esp+4h] [ebp-4h]

  v3 = 0;
  if ( this->m_nSlices > 0 )
  {
    v4 = pBuffer;
    do
    {
      v5 = 0;
      if ( this->m_nRows > 0 )
      {
        m_nColumns = this->m_nColumns;
        do
        {
          v7 = 0;
          if ( m_nColumns > 0 )
          {
            p_l = &v4->l;
            do
            {
              *(float *)&this->m_pAttributePtrs[0][v3 * this->m_nSliceStrideInBytes[0]
                                                 + v5 * this->m_nRowStrideInBytes[0]
                                                 + v7 * this->m_nStrideInBytes[0]] = (float)((float)((float)((char)*(p_l - 2) + 128) * 2.0)
                                                                                           * 0.0039215689)
                                                                                   - 1.0;
              *(float *)&this->m_pAttributePtrs[1][v3 * this->m_nSliceStrideInBytes[1]
                                                 + v5 * this->m_nRowStrideInBytes[1]
                                                 + v7 * this->m_nStrideInBytes[1]] = (float)((float)((float)((char)*(p_l - 1) + 128) * 2.0)
                                                                                           * 0.0039215689)
                                                                                   - 1.0;
              *(float *)&this->m_pAttributePtrs[2][v3 * this->m_nSliceStrideInBytes[2]
                                                 + v5 * this->m_nRowStrideInBytes[2]
                                                 + v7 * this->m_nStrideInBytes[2]] = (float)*p_l * 0.0039215689;
              p_l += 4;
              v8 = v3 * this->m_nSliceStrideInBytes[3]
                 + v5 * this->m_nRowStrideInBytes[3]
                 + v7 * this->m_nStrideInBytes[3];
              ++v7;
              *(_DWORD *)&this->m_pAttributePtrs[3][v8] = 1065353216;
            }
            while ( v7 < this->m_nColumns );
            v4 = pBuffer;
          }
          m_nColumns = this->m_nColumns;
          ++v5;
          v4 += this->m_nColumns;
          pBuffer = v4;
        }
        while ( v5 < this->m_nRows );
      }
      ++v3;
    }
    while ( v3 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DB680
// Name: protected: void FloatBitMap_t::WriteToBufferRGBA<struct ABGR8888_t>(struct ABGR8888_t __near *,int,unsigned short const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferRGBA<ABGR8888_t>(
        FloatBitMap_t *this,
        ABGR8888_t *pBuffer,
        int nPixelCount,
        const unsigned __int16 *pInvGammaTable)
{
  int v4; // ebx
  ABGR8888_t *v5; // esi
  int v6; // eax
  unsigned __int8 *p_g; // esi
  float v8; // xmm2_4
  int v9; // edi
  float v10; // xmm2_4
  int v11; // edi
  float v12; // xmm2_4
  int v13; // edi
  float v14; // xmm2_4
  int v15; // edi
  int z; // [esp+4h] [ebp-8h]
  int y; // [esp+8h] [ebp-4h]

  v4 = 0;
  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      for ( y = 0; y < this->m_nRows; ++y )
      {
        v6 = 0;
        if ( this->m_nColumns > 0 )
        {
          p_g = &v5->g;
          do
          {
            v8 = (float)(*(float *)&this->m_pAttributePtrs[0][v6 * this->m_nStrideInBytes[0]
                                                            + v4 * this->m_nSliceStrideInBytes[0]
                                                            + y * this->m_nRowStrideInBytes[0]]
                       * 1023.0)
               + 0.5;
            if ( (int)v8 >= 0 )
            {
              v9 = 1023;
              if ( (int)v8 <= 1023 )
                v9 = (int)v8;
            }
            else
            {
              v9 = 0;
            }
            p_g[1] = pInvGammaTable[v9] >> 2;
            v10 = (float)(*(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                             + y * this->m_nRowStrideInBytes[1]
                                                             + v6 * this->m_nStrideInBytes[1]]
                        * 1023.0)
                + 0.5;
            if ( (int)v10 >= 0 )
            {
              v11 = 1023;
              if ( (int)v10 <= 1023 )
                v11 = (int)v10;
            }
            else
            {
              v11 = 0;
            }
            *p_g = pInvGammaTable[v11] >> 2;
            v12 = (float)(*(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                             + y * this->m_nRowStrideInBytes[2]
                                                             + v6 * this->m_nStrideInBytes[2]]
                        * 1023.0)
                + 0.5;
            if ( (int)v12 >= 0 )
            {
              v13 = 1023;
              if ( (int)v12 <= 1023 )
                v13 = (int)v12;
            }
            else
            {
              v13 = 0;
            }
            v4 = z;
            *(p_g - 1) = pInvGammaTable[v13] >> 2;
            v14 = (float)(*(float *)&this->m_pAttributePtrs[3][z * this->m_nSliceStrideInBytes[3]
                                                             + y * this->m_nRowStrideInBytes[3]
                                                             + v6 * this->m_nStrideInBytes[3]]
                        * 1023.0)
                + 0.5;
            if ( (int)v14 >= 0 )
            {
              v15 = 1023;
              if ( (int)v14 <= 1023 )
                v15 = (int)v14;
            }
            else
            {
              v15 = 0;
            }
            *(p_g - 2) = v15 >> 2;
            ++v6;
            p_g += 4;
          }
          while ( v6 < this->m_nColumns );
          v5 = pBuffer;
        }
        v5 += this->m_nColumns;
        pBuffer = v5;
      }
      z = ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DB870
// Name: protected: void FloatBitMap_t::WriteToBufferRGBA<struct RGBA8888_t>(struct RGBA8888_t __near *,int,unsigned short const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferRGBA<RGBA8888_t>(
        FloatBitMap_t *this,
        RGBA8888_t *pBuffer,
        int nPixelCount,
        const unsigned __int16 *pInvGammaTable)
{
  int v4; // ebx
  RGBA8888_t *v5; // esi
  int v6; // eax
  unsigned __int8 *p_b; // esi
  float v8; // xmm2_4
  int v9; // edi
  float v10; // xmm2_4
  int v11; // edi
  float v12; // xmm2_4
  int v13; // edi
  float v14; // xmm2_4
  int v15; // edi
  int z; // [esp+4h] [ebp-8h]
  int y; // [esp+8h] [ebp-4h]

  v4 = 0;
  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      for ( y = 0; y < this->m_nRows; ++y )
      {
        v6 = 0;
        if ( this->m_nColumns > 0 )
        {
          p_b = &v5->b;
          do
          {
            v8 = (float)(*(float *)&this->m_pAttributePtrs[0][v6 * this->m_nStrideInBytes[0]
                                                            + v4 * this->m_nSliceStrideInBytes[0]
                                                            + y * this->m_nRowStrideInBytes[0]]
                       * 1023.0)
               + 0.5;
            if ( (int)v8 >= 0 )
            {
              v9 = 1023;
              if ( (int)v8 <= 1023 )
                v9 = (int)v8;
            }
            else
            {
              v9 = 0;
            }
            *(p_b - 2) = pInvGammaTable[v9] >> 2;
            v10 = (float)(*(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                             + y * this->m_nRowStrideInBytes[1]
                                                             + v6 * this->m_nStrideInBytes[1]]
                        * 1023.0)
                + 0.5;
            if ( (int)v10 >= 0 )
            {
              v11 = 1023;
              if ( (int)v10 <= 1023 )
                v11 = (int)v10;
            }
            else
            {
              v11 = 0;
            }
            *(p_b - 1) = pInvGammaTable[v11] >> 2;
            v12 = (float)(*(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                             + y * this->m_nRowStrideInBytes[2]
                                                             + v6 * this->m_nStrideInBytes[2]]
                        * 1023.0)
                + 0.5;
            if ( (int)v12 >= 0 )
            {
              v13 = 1023;
              if ( (int)v12 <= 1023 )
                v13 = (int)v12;
            }
            else
            {
              v13 = 0;
            }
            v4 = z;
            *p_b = pInvGammaTable[v13] >> 2;
            v14 = (float)(*(float *)&this->m_pAttributePtrs[3][z * this->m_nSliceStrideInBytes[3]
                                                             + y * this->m_nRowStrideInBytes[3]
                                                             + v6 * this->m_nStrideInBytes[3]]
                        * 1023.0)
                + 0.5;
            if ( (int)v14 >= 0 )
            {
              v15 = 1023;
              if ( (int)v14 <= 1023 )
                v15 = (int)v14;
            }
            else
            {
              v15 = 0;
            }
            p_b[1] = v15 >> 2;
            ++v6;
            p_b += 4;
          }
          while ( v6 < this->m_nColumns );
          v5 = pBuffer;
        }
        v5 += this->m_nColumns;
        pBuffer = v5;
      }
      z = ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DBA60
// Name: protected: void FloatBitMap_t::WriteToBufferRGBA<struct BGRA8888_t>(struct BGRA8888_t __near *,int,unsigned short const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferRGBA<BGRA8888_t>(
        FloatBitMap_t *this,
        BGRA8888_t *pBuffer,
        int nPixelCount,
        const unsigned __int16 *pInvGammaTable)
{
  int v4; // ebx
  BGRA8888_t *v5; // esi
  int v6; // eax
  unsigned __int8 *p_g; // esi
  float v8; // xmm2_4
  int v9; // edi
  float v10; // xmm2_4
  int v11; // edi
  float v12; // xmm2_4
  int v13; // edi
  float v14; // xmm2_4
  int v15; // edi
  int z; // [esp+4h] [ebp-8h]
  int y; // [esp+8h] [ebp-4h]

  v4 = 0;
  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      for ( y = 0; y < this->m_nRows; ++y )
      {
        v6 = 0;
        if ( this->m_nColumns > 0 )
        {
          p_g = &v5->g;
          do
          {
            v8 = (float)(*(float *)&this->m_pAttributePtrs[0][v6 * this->m_nStrideInBytes[0]
                                                            + v4 * this->m_nSliceStrideInBytes[0]
                                                            + y * this->m_nRowStrideInBytes[0]]
                       * 1023.0)
               + 0.5;
            if ( (int)v8 >= 0 )
            {
              v9 = 1023;
              if ( (int)v8 <= 1023 )
                v9 = (int)v8;
            }
            else
            {
              v9 = 0;
            }
            p_g[1] = pInvGammaTable[v9] >> 2;
            v10 = (float)(*(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                             + y * this->m_nRowStrideInBytes[1]
                                                             + v6 * this->m_nStrideInBytes[1]]
                        * 1023.0)
                + 0.5;
            if ( (int)v10 >= 0 )
            {
              v11 = 1023;
              if ( (int)v10 <= 1023 )
                v11 = (int)v10;
            }
            else
            {
              v11 = 0;
            }
            *p_g = pInvGammaTable[v11] >> 2;
            v12 = (float)(*(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                             + y * this->m_nRowStrideInBytes[2]
                                                             + v6 * this->m_nStrideInBytes[2]]
                        * 1023.0)
                + 0.5;
            if ( (int)v12 >= 0 )
            {
              v13 = 1023;
              if ( (int)v12 <= 1023 )
                v13 = (int)v12;
            }
            else
            {
              v13 = 0;
            }
            v4 = z;
            *(p_g - 1) = pInvGammaTable[v13] >> 2;
            v14 = (float)(*(float *)&this->m_pAttributePtrs[3][z * this->m_nSliceStrideInBytes[3]
                                                             + y * this->m_nRowStrideInBytes[3]
                                                             + v6 * this->m_nStrideInBytes[3]]
                        * 1023.0)
                + 0.5;
            if ( (int)v14 >= 0 )
            {
              v15 = 1023;
              if ( (int)v14 <= 1023 )
                v15 = (int)v14;
            }
            else
            {
              v15 = 0;
            }
            p_g[2] = v15 >> 2;
            ++v6;
            p_g += 4;
          }
          while ( v6 < this->m_nColumns );
          v5 = pBuffer;
        }
        v5 += this->m_nColumns;
        pBuffer = v5;
      }
      z = ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DBC50
// Name: protected: void FloatBitMap_t::WriteToBufferRGB<struct RGB888_t>(struct RGB888_t __near *,int,unsigned short const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferRGB<RGB888_t>(
        FloatBitMap_t *this,
        RGB888_t *pBuffer,
        int nPixelCount,
        const unsigned __int16 *pInvGammaTable)
{
  int v4; // ebx
  RGB888_t *v5; // esi
  int v6; // eax
  unsigned __int8 *p_b; // esi
  float v8; // xmm2_4
  int v9; // edi
  float v10; // xmm2_4
  int v11; // edi
  float v12; // xmm2_4
  int v13; // edi
  int z; // [esp+4h] [ebp-8h]
  int y; // [esp+8h] [ebp-4h]

  v4 = 0;
  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      for ( y = 0; y < this->m_nRows; ++y )
      {
        v6 = 0;
        if ( this->m_nColumns > 0 )
        {
          p_b = &v5->b;
          do
          {
            v8 = (float)(*(float *)&this->m_pAttributePtrs[0][v6 * this->m_nStrideInBytes[0]
                                                            + v4 * this->m_nSliceStrideInBytes[0]
                                                            + y * this->m_nRowStrideInBytes[0]]
                       * 1023.0)
               + 0.5;
            if ( (int)v8 >= 0 )
            {
              v9 = 1023;
              if ( (int)v8 <= 1023 )
                v9 = (int)v8;
            }
            else
            {
              v9 = 0;
            }
            *(p_b - 2) = pInvGammaTable[v9] >> 2;
            v10 = (float)(*(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                             + y * this->m_nRowStrideInBytes[1]
                                                             + v6 * this->m_nStrideInBytes[1]]
                        * 1023.0)
                + 0.5;
            if ( (int)v10 >= 0 )
            {
              v11 = 1023;
              if ( (int)v10 <= 1023 )
                v11 = (int)v10;
            }
            else
            {
              v11 = 0;
            }
            v4 = z;
            *(p_b - 1) = pInvGammaTable[v11] >> 2;
            v12 = (float)(*(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                             + y * this->m_nRowStrideInBytes[2]
                                                             + v6 * this->m_nStrideInBytes[2]]
                        * 1023.0)
                + 0.5;
            if ( (int)v12 >= 0 )
            {
              v13 = 1023;
              if ( (int)v12 <= 1023 )
                v13 = (int)v12;
            }
            else
            {
              v13 = 0;
            }
            *p_b = pInvGammaTable[v13] >> 2;
            ++v6;
            p_b += 3;
          }
          while ( v6 < this->m_nColumns );
          v5 = pBuffer;
        }
        v5 = (RGB888_t *)((char *)v5 + 2 * this->m_nColumns + this->m_nColumns);
        pBuffer = v5;
      }
      z = ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DBDF0
// Name: protected: void FloatBitMap_t::WriteToBufferRGB<struct BGR888_t>(struct BGR888_t __near *,int,unsigned short const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferRGB<BGR888_t>(
        FloatBitMap_t *this,
        BGR888_t *pBuffer,
        int nPixelCount,
        const unsigned __int16 *pInvGammaTable)
{
  int v4; // ebx
  BGR888_t *v5; // esi
  int v6; // eax
  unsigned __int8 *p_g; // esi
  float v8; // xmm2_4
  int v9; // edi
  float v10; // xmm2_4
  int v11; // edi
  float v12; // xmm2_4
  int v13; // edi
  int z; // [esp+4h] [ebp-8h]
  int y; // [esp+8h] [ebp-4h]

  v4 = 0;
  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      for ( y = 0; y < this->m_nRows; ++y )
      {
        v6 = 0;
        if ( this->m_nColumns > 0 )
        {
          p_g = &v5->g;
          do
          {
            v8 = (float)(*(float *)&this->m_pAttributePtrs[0][v6 * this->m_nStrideInBytes[0]
                                                            + v4 * this->m_nSliceStrideInBytes[0]
                                                            + y * this->m_nRowStrideInBytes[0]]
                       * 1023.0)
               + 0.5;
            if ( (int)v8 >= 0 )
            {
              v9 = 1023;
              if ( (int)v8 <= 1023 )
                v9 = (int)v8;
            }
            else
            {
              v9 = 0;
            }
            p_g[1] = pInvGammaTable[v9] >> 2;
            v10 = (float)(*(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                             + y * this->m_nRowStrideInBytes[1]
                                                             + v6 * this->m_nStrideInBytes[1]]
                        * 1023.0)
                + 0.5;
            if ( (int)v10 >= 0 )
            {
              v11 = 1023;
              if ( (int)v10 <= 1023 )
                v11 = (int)v10;
            }
            else
            {
              v11 = 0;
            }
            v4 = z;
            *p_g = pInvGammaTable[v11] >> 2;
            v12 = (float)(*(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                             + y * this->m_nRowStrideInBytes[2]
                                                             + v6 * this->m_nStrideInBytes[2]]
                        * 1023.0)
                + 0.5;
            if ( (int)v12 >= 0 )
            {
              v13 = 1023;
              if ( (int)v12 <= 1023 )
                v13 = (int)v12;
            }
            else
            {
              v13 = 0;
            }
            *(p_g - 1) = pInvGammaTable[v13] >> 2;
            ++v6;
            p_g += 3;
          }
          while ( v6 < this->m_nColumns );
          v5 = pBuffer;
        }
        v5 = (BGR888_t *)((char *)v5 + 2 * this->m_nColumns + this->m_nColumns);
        pBuffer = v5;
      }
      z = ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DBF90
// Name: protected: void FloatBitMap_t::WriteToBufferRGB<struct BGRX8888_t>(struct BGRX8888_t __near *,int,unsigned short const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferRGB<BGRX8888_t>(
        FloatBitMap_t *this,
        BGRX8888_t *pBuffer,
        int nPixelCount,
        const unsigned __int16 *pInvGammaTable)
{
  int v4; // ebx
  BGRX8888_t *v5; // esi
  int v6; // eax
  unsigned __int8 *p_g; // esi
  float v8; // xmm2_4
  int v9; // edi
  float v10; // xmm2_4
  int v11; // edi
  float v12; // xmm2_4
  int v13; // edi
  int z; // [esp+4h] [ebp-8h]
  int y; // [esp+8h] [ebp-4h]

  v4 = 0;
  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      for ( y = 0; y < this->m_nRows; ++y )
      {
        v6 = 0;
        if ( this->m_nColumns > 0 )
        {
          p_g = &v5->g;
          do
          {
            v8 = (float)(*(float *)&this->m_pAttributePtrs[0][v6 * this->m_nStrideInBytes[0]
                                                            + v4 * this->m_nSliceStrideInBytes[0]
                                                            + y * this->m_nRowStrideInBytes[0]]
                       * 1023.0)
               + 0.5;
            if ( (int)v8 >= 0 )
            {
              v9 = 1023;
              if ( (int)v8 <= 1023 )
                v9 = (int)v8;
            }
            else
            {
              v9 = 0;
            }
            p_g[1] = pInvGammaTable[v9] >> 2;
            v10 = (float)(*(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                             + y * this->m_nRowStrideInBytes[1]
                                                             + v6 * this->m_nStrideInBytes[1]]
                        * 1023.0)
                + 0.5;
            if ( (int)v10 >= 0 )
            {
              v11 = 1023;
              if ( (int)v10 <= 1023 )
                v11 = (int)v10;
            }
            else
            {
              v11 = 0;
            }
            v4 = z;
            *p_g = pInvGammaTable[v11] >> 2;
            v12 = (float)(*(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                             + y * this->m_nRowStrideInBytes[2]
                                                             + v6 * this->m_nStrideInBytes[2]]
                        * 1023.0)
                + 0.5;
            if ( (int)v12 >= 0 )
            {
              v13 = 1023;
              if ( (int)v12 <= 1023 )
                v13 = (int)v12;
            }
            else
            {
              v13 = 0;
            }
            *(p_g - 1) = pInvGammaTable[v13] >> 2;
            ++v6;
            p_g += 4;
          }
          while ( v6 < this->m_nColumns );
          v5 = pBuffer;
        }
        v5 += this->m_nColumns;
        pBuffer = v5;
      }
      z = ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DC130
// Name: protected: void FloatBitMap_t::WriteToBufferUV<struct UV88_t>(struct UV88_t __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferUV<UV88_t>(FloatBitMap_t *this, UV88_t *pBuffer, int nPixelCount)
{
  int v3; // ebx
  UV88_t *v4; // edi
  int i; // esi
  int j; // eax
  int v7; // edx
  int v8; // edx

  v3 = 0;
  if ( this->m_nSlices > 0 )
  {
    v4 = pBuffer;
    do
    {
      for ( i = 0; i < this->m_nRows; pBuffer = v4 )
      {
        for ( j = 0; j < this->m_nColumns; ++j )
        {
          v7 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[0][j * this->m_nStrideInBytes[0]
                                                                       + v3 * this->m_nSliceStrideInBytes[0]
                                                                       + i * this->m_nRowStrideInBytes[0]]
                                  + 1.0)
                          * 127.5);
          if ( v7 >= 0 )
          {
            if ( v7 > 255 )
              LOBYTE(v7) = -1;
          }
          else
          {
            LOBYTE(v7) = 0;
          }
          pBuffer[j].u = v7 + 0x80;
          v8 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[1][v3 * this->m_nSliceStrideInBytes[1]
                                                                       + i * this->m_nRowStrideInBytes[1]
                                                                       + j * this->m_nStrideInBytes[1]]
                                  + 1.0)
                          * 127.5);
          if ( v8 >= 0 )
          {
            if ( v8 > 255 )
              LOBYTE(v8) = -1;
          }
          else
          {
            LOBYTE(v8) = 0;
          }
          v4 = pBuffer;
          pBuffer[j].v = v8 + 0x80;
        }
        ++i;
        v4 += this->m_nColumns;
      }
      ++v3;
    }
    while ( v3 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DC240
// Name: protected: void FloatBitMap_t::WriteToBufferUVWQ<struct UVWQ8888_t>(struct UVWQ8888_t __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferUVWQ<UVWQ8888_t>(FloatBitMap_t *this, UVWQ8888_t *pBuffer, int nPixelCount)
{
  int v3; // edi
  UVWQ8888_t *v4; // esi
  int v5; // edx
  char *p_w; // esi
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int z; // [esp+4h] [ebp-8h]
  int y; // [esp+8h] [ebp-4h]

  v3 = 0;
  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v4 = pBuffer;
    do
    {
      for ( y = 0; y < this->m_nRows; ++y )
      {
        v5 = 0;
        if ( this->m_nColumns > 0 )
        {
          p_w = &v4->w;
          do
          {
            v7 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[0][v5 * this->m_nStrideInBytes[0]
                                                                         + v3 * this->m_nSliceStrideInBytes[0]
                                                                         + y * this->m_nRowStrideInBytes[0]]
                                    + 1.0)
                            * 127.5);
            if ( v7 >= 0 )
            {
              if ( v7 > 255 )
                LOBYTE(v7) = -1;
            }
            else
            {
              LOBYTE(v7) = 0;
            }
            *(p_w - 2) = v7 + 0x80;
            v8 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                                         + y * this->m_nRowStrideInBytes[1]
                                                                         + v5 * this->m_nStrideInBytes[1]]
                                    + 1.0)
                            * 127.5);
            if ( v8 >= 0 )
            {
              if ( v8 > 255 )
                LOBYTE(v8) = -1;
            }
            else
            {
              LOBYTE(v8) = 0;
            }
            *(p_w - 1) = v8 + 0x80;
            v3 = z;
            v9 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                                         + y * this->m_nRowStrideInBytes[2]
                                                                         + v5 * this->m_nStrideInBytes[2]]
                                    + 1.0)
                            * 127.5);
            if ( v9 >= 0 )
            {
              if ( v9 > 255 )
                LOBYTE(v9) = -1;
            }
            else
            {
              LOBYTE(v9) = 0;
            }
            *p_w = v9 + 0x80;
            v10 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[3][v5 * this->m_nStrideInBytes[3]
                                                                          + z * this->m_nSliceStrideInBytes[3]
                                                                          + y * this->m_nRowStrideInBytes[3]]
                                     + 1.0)
                             * 127.5);
            if ( v10 >= 0 )
            {
              if ( v10 > 255 )
                LOBYTE(v10) = -1;
            }
            else
            {
              LOBYTE(v10) = 0;
            }
            p_w[1] = v10 + 0x80;
            ++v5;
            p_w += 4;
          }
          while ( v5 < this->m_nColumns );
          v4 = pBuffer;
        }
        v4 += this->m_nColumns;
        pBuffer = v4;
      }
      z = ++v3;
    }
    while ( v3 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DC410
// Name: protected: void FloatBitMap_t::WriteToBufferUVLX<struct UVLX8888_t>(struct UVLX8888_t __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferUVLX<UVLX8888_t>(FloatBitMap_t *this, UVLX8888_t *pBuffer, int nPixelCount)
{
  int v3; // ebx
  UVLX8888_t *v4; // esi
  int v5; // edx
  unsigned __int8 *p_l; // esi
  int v7; // eax
  int v8; // eax
  float v9; // xmm3_4
  int v10; // eax
  int z; // [esp+4h] [ebp-8h]
  int y; // [esp+8h] [ebp-4h]

  v3 = 0;
  z = 0;
  if ( this->m_nSlices > 0 )
  {
    v4 = pBuffer;
    do
    {
      for ( y = 0; y < this->m_nRows; ++y )
      {
        v5 = 0;
        if ( this->m_nColumns > 0 )
        {
          p_l = &v4->l;
          do
          {
            v7 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[0][v5 * this->m_nStrideInBytes[0]
                                                                         + v3 * this->m_nSliceStrideInBytes[0]
                                                                         + y * this->m_nRowStrideInBytes[0]]
                                    + 1.0)
                            * 127.5);
            if ( v7 >= 0 )
            {
              if ( v7 > 255 )
                LOBYTE(v7) = -1;
            }
            else
            {
              LOBYTE(v7) = 0;
            }
            *(p_l - 2) = v7 + 0x80;
            v8 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[1][z * this->m_nSliceStrideInBytes[1]
                                                                         + y * this->m_nRowStrideInBytes[1]
                                                                         + v5 * this->m_nStrideInBytes[1]]
                                    + 1.0)
                            * 127.5);
            if ( v8 >= 0 )
            {
              if ( v8 > 255 )
                LOBYTE(v8) = -1;
            }
            else
            {
              LOBYTE(v8) = 0;
            }
            v3 = z;
            *(p_l - 1) = v8 + 0x80;
            v9 = *(float *)&this->m_pAttributePtrs[2][z * this->m_nSliceStrideInBytes[2]
                                                    + y * this->m_nRowStrideInBytes[2]
                                                    + v5 * this->m_nStrideInBytes[2]]
               * 255.0;
            if ( (int)v9 >= 0 )
            {
              LOBYTE(v10) = -1;
              if ( (int)v9 <= 255 )
                v10 = (int)v9;
            }
            else
            {
              LOBYTE(v10) = 0;
            }
            *p_l = v10;
            p_l[1] = -1;
            ++v5;
            p_l += 4;
          }
          while ( v5 < this->m_nColumns );
          v4 = pBuffer;
        }
        v4 += this->m_nColumns;
        pBuffer = v4;
      }
      z = ++v3;
    }
    while ( v3 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00523130
// Name: protected: virtual int CDmeAmalgamatedTexture::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAmalgamatedTexture::AllocatedSize(CDmeChannelsClip *this)
{
  return 168;
}

//------------------------------------------------------------------------------
// Address: 0x006AC010
// Name: _dynamic_initializer_for__CDmeAmalgamatedTexture::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAmalgamatedTexture::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAmalgamatedTexture::s_Allocator,
    blockSize: 168,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAmalgamatedTexture pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAmalgamatedTexture::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B3900
// Name: _dynamic_atexit_destructor_for__CDmeAmalgamatedTexture::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAmalgamatedTexture::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAmalgamatedTexture::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AC040
// Name: _dynamic_initializer_for__g_CDmeAmalgamatedTexture_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAmalgamatedTexture_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAmalgamatedTexture_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC050
// Name: _dynamic_initializer_for__g_CDmeAmalgamatedTexture_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAmalgamatedTexture_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAmalgamatedTexture_Helper,
           classname: "DmeAmalgamatedTexture",
           pFactory: &g_CDmeAmalgamatedTexture_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006B3910
// Name: _dynamic_atexit_destructor_for__g_CDmeAmalgamatedTexture_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAmalgamatedTexture_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAmalgamatedTexture_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x0042D020
// Name: public: void FloatBitMap_t::Init(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::Init(FloatBitMap_t *this, int nXSize, int nYSize, int nZSize, char nAttributeMask)
{
  CSOAContainer::PurgeData(this);
  CSOAContainer::SetAttributeType(this, nAttrIdx: 0, nDataType: ATTRDATATYPE_FLOAT, bAllocateMemory: nAttributeMask & 1);
  CSOAContainer::SetAttributeType(
    this,
    nAttrIdx: 1,
    nDataType: ATTRDATATYPE_FLOAT,
    bAllocateMemory: (nAttributeMask & 2) != 0);
  CSOAContainer::SetAttributeType(
    this,
    nAttrIdx: 2,
    nDataType: ATTRDATATYPE_FLOAT,
    bAllocateMemory: (nAttributeMask & 4) != 0);
  CSOAContainer::SetAttributeType(
    this,
    nAttrIdx: 3,
    nDataType: ATTRDATATYPE_FLOAT,
    bAllocateMemory: (nAttributeMask & 8) != 0);
  CSOAContainer::AllocateData(this, nNCols: nXSize, nNRows: nYSize, nSlices: nZSize);
  if ( (nAttributeMask & 8) == 0 )
    CSOAContainer::FillAttr(this, nAttr: 3, flValue: 1.0);
}

//------------------------------------------------------------------------------
// Address: 0x0042D0C0
// Name: public: void CChangeUndoScopeGuard::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChangeUndoScopeGuard::Release(CChangeUndoScopeGuard *this)
{
  bool v2; // zf

  if ( !this->m_bReleased )
  {
    ((void (__stdcall *)(bool))g_pDataModel->SetUndoEnabled)(a1: this->m_bOldValue);
    v2 = !this->m_bNotify;
    this->m_bReleased = true;
    if ( !v2 )
    {
      g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
      this->m_bNotify = false;
    }
    if ( this->m_pNotify != nullptr )
    {
      g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: this->m_pNotify);
      this->m_pNotify = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042D120
// Name: public: char const __near * CDmElement::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmElement::GetName(CDmElement *this)
{
  const char *result; // eax

  result = this->m_Name.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042D130
// Name: protected: void CDmeAmalgamatedTexture::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAmalgamatedTexture::OnConstruction(CDmeAmalgamatedTexture *this)
{
  CDmaElementArray<CDmeSheetImage> *p_m_ImageList; // edi
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  p_m_ImageList = &this->m_ImageList;
  this->m_ImageList.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "images",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_ImageList);
  CDmAttribute::SetElementTypeSymbol(this: p_m_ImageList->m_pAttribute, typeSymbol: CDmeSheetImage::m_classType);
  value = 1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "packmode", type: AT_INT, pMemory: &this->m_ePackingMode);
  this->m_ePackingMode.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, &value);
  this->m_Sequences.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "sequences",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_Sequences);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Sequences.m_pAttribute, typeSymbol: CDmeSheetSequence::m_classType);
  this->m_nWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "width",
                                  type: AT_INT,
                                  pMemory: &this->m_nWidth);
  this->m_nHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "height",
                                   type: AT_INT,
                                   pMemory: &this->m_nHeight);
  this->m_pPackedImage.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "packedImage",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_pPackedImage);
  CDmAttribute::SetElementTypeSymbol(this: this->m_pPackedImage.m_pAttribute, typeSymbol: CDmeImage::m_classType);
  this->m_SequenceCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042D2C0
// Name: protected: CDmeAmalgamatedTexture::CDmeAmalgamatedTexture(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeAmalgamatedTexture *__thiscall CDmeAmalgamatedTexture::CDmeAmalgamatedTexture(
        CDmeAmalgamatedTexture *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeAmalgamatedTexture_vtbl *)&CDmeAmalgamatedTexture::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_ImageList);
  this->m_ePackingMode.m_pAttribute = nullptr;
  this->m_ePackingMode.m_Storage = 0;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Sequences);
  this->m_nWidth.m_pAttribute = nullptr;
  this->m_nWidth.m_Storage = 0;
  this->m_nHeight.m_pAttribute = nullptr;
  this->m_nHeight.m_Storage = 0;
  this->m_pPackedImage.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_pPackedImage.m_pAttribute = nullptr;
  this->m_pPackedImage.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042D350
// Name: public: virtual bool CDmeAmalgamatedTexture::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAmalgamatedTexture::IsA(CDmeAmalgamatedTexture *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAmalgamatedTexture::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042D380
// Name: public: virtual int CDmeAmalgamatedTexture::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAmalgamatedTexture::GetInheritanceDepth(CDmeAmalgamatedTexture *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAmalgamatedTexture::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042D3C0
// Name: protected: virtual int CDmeAmalgamatedTexture::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAmalgamatedTexture::AllocatedSize(CDmeAmalgamatedTexture *this)
{
  return 168;
}

//------------------------------------------------------------------------------
// Address: 0x0042D3D0
// Name: protected: virtual void CDmeAmalgamatedTexture::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAmalgamatedTexture::PerformConstruction(CDmeAmalgamatedTexture *this)
{
  CSteamApplication::PostShutdown((CFontManager *)this);
  CDmeAmalgamatedTexture::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042D710
// Name: public: virtual void CDmeAmalgamatedTexture::OnAttributeArrayElementRemoved(class CDmAttribute __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAmalgamatedTexture::OnAttributeArrayElementRemoved(
        CTextureDictionary *this,
        int id,
        int referenceId,
        struct IMaterial2 *pMaterial)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00433C10
// Name: protected: void FloatBitMap_t::LoadFromBufferRGBA<struct ABGR8888_t>(struct ABGR8888_t const __near *,int,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferRGBA<ABGR8888_t>(
        FloatBitMap_t *this,
        const ABGR8888_t *pBuffer,
        int nPixelCount,
        const float *pGammaTable)
{
  int v4; // esi
  const ABGR8888_t *v5; // edx
  int v6; // ebx
  int m_nColumns; // edi
  int v8; // eax
  unsigned __int8 *p_g; // edx
  int v10; // esi
  unsigned int v11; // edi
  int y; // [esp+4h] [ebp-8h]
  int v13; // [esp+8h] [ebp-4h]

  v4 = 0;
  y = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      v6 = 0;
      v13 = 0;
      if ( this->m_nRows > 0 )
      {
        m_nColumns = this->m_nColumns;
        do
        {
          v8 = 0;
          if ( m_nColumns > 0 )
          {
            p_g = &v5->g;
            do
            {
              v10 = (4 * p_g[1]) | ((int)p_g[1] >> 6);
              p_g += 4;
              *(float *)&this->m_pAttributePtrs[0][y * this->m_nSliceStrideInBytes[0]
                                                 + v6 * this->m_nRowStrideInBytes[0]
                                                 + v8 * this->m_nStrideInBytes[0]] = pGammaTable[v10];
              *(float *)&this->m_pAttributePtrs[1][y * this->m_nSliceStrideInBytes[1]
                                                 + v13 * this->m_nRowStrideInBytes[1]
                                                 + v8 * this->m_nStrideInBytes[1]] = pGammaTable[(4 * *(p_g - 4))
                                                                                               | ((int)*(p_g - 4) >> 6)];
              v6 = v13;
              *(float *)&this->m_pAttributePtrs[2][y * this->m_nSliceStrideInBytes[2]
                                                 + v13 * this->m_nRowStrideInBytes[2]
                                                 + v8 * this->m_nStrideInBytes[2]] = pGammaTable[(4 * *(p_g - 5))
                                                                                               | ((int)*(p_g - 5) >> 6)];
              v4 = y;
              v11 = v8 * this->m_nStrideInBytes[3]
                  + y * this->m_nSliceStrideInBytes[3]
                  + v13 * this->m_nRowStrideInBytes[3];
              ++v8;
              *(float *)&this->m_pAttributePtrs[3][v11] = (float)((4 * *(p_g - 6)) | ((int)*(p_g - 6) >> 6))
                                                        * 0.00097751711;
            }
            while ( v8 < this->m_nColumns );
            v5 = pBuffer;
          }
          m_nColumns = this->m_nColumns;
          ++v6;
          v5 += this->m_nColumns;
          pBuffer = v5;
          v13 = v6;
        }
        while ( v6 < this->m_nRows );
      }
      y = ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433D90
// Name: protected: void FloatBitMap_t::LoadFromBufferRGBA<struct RGBA8888_t>(struct RGBA8888_t const __near *,int,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferRGBA<RGBA8888_t>(
        FloatBitMap_t *this,
        const RGBA8888_t *pBuffer,
        int nPixelCount,
        const float *pGammaTable)
{
  int v4; // esi
  const RGBA8888_t *v5; // edx
  int v6; // ebx
  int m_nColumns; // edi
  int v8; // eax
  unsigned __int8 *p_b; // edx
  int v10; // esi
  unsigned int v11; // edi
  int y; // [esp+4h] [ebp-8h]
  int v13; // [esp+8h] [ebp-4h]

  v4 = 0;
  y = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      v6 = 0;
      v13 = 0;
      if ( this->m_nRows > 0 )
      {
        m_nColumns = this->m_nColumns;
        do
        {
          v8 = 0;
          if ( m_nColumns > 0 )
          {
            p_b = &v5->b;
            do
            {
              v10 = (4 * *(p_b - 2)) | ((int)*(p_b - 2) >> 6);
              p_b += 4;
              *(float *)&this->m_pAttributePtrs[0][y * this->m_nSliceStrideInBytes[0]
                                                 + v6 * this->m_nRowStrideInBytes[0]
                                                 + v8 * this->m_nStrideInBytes[0]] = pGammaTable[v10];
              *(float *)&this->m_pAttributePtrs[1][y * this->m_nSliceStrideInBytes[1]
                                                 + v13 * this->m_nRowStrideInBytes[1]
                                                 + v8 * this->m_nStrideInBytes[1]] = pGammaTable[(4 * *(p_b - 5))
                                                                                               | ((int)*(p_b - 5) >> 6)];
              v6 = v13;
              *(float *)&this->m_pAttributePtrs[2][y * this->m_nSliceStrideInBytes[2]
                                                 + v13 * this->m_nRowStrideInBytes[2]
                                                 + v8 * this->m_nStrideInBytes[2]] = pGammaTable[(4 * *(p_b - 4))
                                                                                               | ((int)*(p_b - 4) >> 6)];
              v4 = y;
              v11 = v8 * this->m_nStrideInBytes[3]
                  + y * this->m_nSliceStrideInBytes[3]
                  + v13 * this->m_nRowStrideInBytes[3];
              ++v8;
              *(float *)&this->m_pAttributePtrs[3][v11] = (float)((4 * *(p_b - 3)) | ((int)*(p_b - 3) >> 6))
                                                        * 0.00097751711;
            }
            while ( v8 < this->m_nColumns );
            v5 = pBuffer;
          }
          m_nColumns = this->m_nColumns;
          ++v6;
          v5 += this->m_nColumns;
          pBuffer = v5;
          v13 = v6;
        }
        while ( v6 < this->m_nRows );
      }
      y = ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433F10
// Name: protected: void FloatBitMap_t::LoadFromBufferRGBA<struct BGRA8888_t>(struct BGRA8888_t const __near *,int,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferRGBA<BGRA8888_t>(
        FloatBitMap_t *this,
        const BGRA8888_t *pBuffer,
        int nPixelCount,
        const float *pGammaTable)
{
  int v4; // esi
  const BGRA8888_t *v5; // edx
  int v6; // ebx
  int m_nColumns; // edi
  int v8; // eax
  unsigned __int8 *p_g; // edx
  int v10; // esi
  unsigned int v11; // edi
  int y; // [esp+4h] [ebp-8h]
  int v13; // [esp+8h] [ebp-4h]

  v4 = 0;
  y = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      v6 = 0;
      v13 = 0;
      if ( this->m_nRows > 0 )
      {
        m_nColumns = this->m_nColumns;
        do
        {
          v8 = 0;
          if ( m_nColumns > 0 )
          {
            p_g = &v5->g;
            do
            {
              v10 = (4 * p_g[1]) | ((int)p_g[1] >> 6);
              p_g += 4;
              *(float *)&this->m_pAttributePtrs[0][y * this->m_nSliceStrideInBytes[0]
                                                 + v6 * this->m_nRowStrideInBytes[0]
                                                 + v8 * this->m_nStrideInBytes[0]] = pGammaTable[v10];
              *(float *)&this->m_pAttributePtrs[1][y * this->m_nSliceStrideInBytes[1]
                                                 + v13 * this->m_nRowStrideInBytes[1]
                                                 + v8 * this->m_nStrideInBytes[1]] = pGammaTable[(4 * *(p_g - 4))
                                                                                               | ((int)*(p_g - 4) >> 6)];
              v6 = v13;
              *(float *)&this->m_pAttributePtrs[2][y * this->m_nSliceStrideInBytes[2]
                                                 + v13 * this->m_nRowStrideInBytes[2]
                                                 + v8 * this->m_nStrideInBytes[2]] = pGammaTable[(4 * *(p_g - 5))
                                                                                               | ((int)*(p_g - 5) >> 6)];
              v4 = y;
              v11 = v8 * this->m_nStrideInBytes[3]
                  + y * this->m_nSliceStrideInBytes[3]
                  + v13 * this->m_nRowStrideInBytes[3];
              ++v8;
              *(float *)&this->m_pAttributePtrs[3][v11] = (float)((4 * *(p_g - 2)) | ((int)*(p_g - 2) >> 6))
                                                        * 0.00097751711;
            }
            while ( v8 < this->m_nColumns );
            v5 = pBuffer;
          }
          m_nColumns = this->m_nColumns;
          ++v6;
          v5 += this->m_nColumns;
          pBuffer = v5;
          v13 = v6;
        }
        while ( v6 < this->m_nRows );
      }
      y = ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434090
// Name: protected: void FloatBitMap_t::LoadFromBufferRGB<struct RGB888_t>(struct RGB888_t const __near *,int,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferRGB<RGB888_t>(
        FloatBitMap_t *this,
        const RGB888_t *pBuffer,
        int nPixelCount,
        const float *pGammaTable)
{
  int v4; // ebx
  const RGB888_t *v5; // edi
  int v6; // esi
  int m_nColumns; // edx
  int v8; // eax
  double v9; // st7
  unsigned __int8 *v10; // edx
  unsigned int v11; // edx
  int z; // [esp+4h] [ebp-8h]
  int v13; // [esp+8h] [ebp-4h]

  v4 = 0;
  v13 = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      v6 = 0;
      if ( this->m_nRows > 0 )
      {
        m_nColumns = this->m_nColumns;
        do
        {
          v8 = 0;
          if ( m_nColumns > 0 )
          {
            z = (int)&v5->b;
            do
            {
              *(float *)&this->m_pAttributePtrs[0][v4 * this->m_nSliceStrideInBytes[0]
                                                 + v6 * this->m_nRowStrideInBytes[0]
                                                 + v8 * this->m_nStrideInBytes[0]] = pGammaTable[(4
                                                                                                * *(unsigned __int8 *)(z - 2))
                                                                                               | ((int)*(unsigned __int8 *)(z - 2) >> 6)];
              v9 = pGammaTable[(4 * *(unsigned __int8 *)(z - 1)) | ((int)*(unsigned __int8 *)(z - 1) >> 6)];
              v10 = (unsigned __int8 *)z;
              z += 3;
              *(float *)&this->m_pAttributePtrs[1][v13 * this->m_nSliceStrideInBytes[1]
                                                 + v6 * this->m_nRowStrideInBytes[1]
                                                 + v8 * this->m_nStrideInBytes[1]] = v9;
              *(float *)&this->m_pAttributePtrs[2][v13 * this->m_nSliceStrideInBytes[2]
                                                 + v6 * this->m_nRowStrideInBytes[2]
                                                 + v8 * this->m_nStrideInBytes[2]] = pGammaTable[(4 * *v10)
                                                                                               | ((int)*v10 >> 6)];
              v4 = v13;
              v11 = v13 * this->m_nSliceStrideInBytes[3]
                  + v6 * this->m_nRowStrideInBytes[3]
                  + v8 * this->m_nStrideInBytes[3];
              ++v8;
              *(_DWORD *)&this->m_pAttributePtrs[3][v11] = 1065353216;
            }
            while ( v8 < this->m_nColumns );
            v5 = pBuffer;
          }
          m_nColumns = this->m_nColumns;
          ++v6;
          v5 = (const RGB888_t *)((char *)v5 + 2 * this->m_nColumns + this->m_nColumns);
          pBuffer = v5;
        }
        while ( v6 < this->m_nRows );
      }
      v13 = ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434200
// Name: protected: void FloatBitMap_t::LoadFromBufferRGB<struct BGR888_t>(struct BGR888_t const __near *,int,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferRGB<BGR888_t>(
        FloatBitMap_t *this,
        const BGR888_t *pBuffer,
        int nPixelCount,
        const float *pGammaTable)
{
  int v4; // ebx
  const BGR888_t *v5; // edi
  int v6; // esi
  int m_nColumns; // edx
  int v8; // eax
  double v9; // st7
  unsigned __int8 *v10; // edx
  unsigned int v11; // edx
  unsigned __int8 *z; // [esp+4h] [ebp-8h]
  int v13; // [esp+8h] [ebp-4h]

  v4 = 0;
  v13 = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      v6 = 0;
      if ( this->m_nRows > 0 )
      {
        m_nColumns = this->m_nColumns;
        do
        {
          v8 = 0;
          if ( m_nColumns > 0 )
          {
            z = &v5->g;
            do
            {
              *(float *)&this->m_pAttributePtrs[0][v4 * this->m_nSliceStrideInBytes[0]
                                                 + v6 * this->m_nRowStrideInBytes[0]
                                                 + v8 * this->m_nStrideInBytes[0]] = pGammaTable[(4 * z[1])
                                                                                               | ((int)z[1] >> 6)];
              v9 = pGammaTable[(4 * *z) | ((int)*z >> 6)];
              v10 = z;
              z += 3;
              *(float *)&this->m_pAttributePtrs[1][v13 * this->m_nSliceStrideInBytes[1]
                                                 + v6 * this->m_nRowStrideInBytes[1]
                                                 + v8 * this->m_nStrideInBytes[1]] = v9;
              *(float *)&this->m_pAttributePtrs[2][v13 * this->m_nSliceStrideInBytes[2]
                                                 + v6 * this->m_nRowStrideInBytes[2]
                                                 + v8 * this->m_nStrideInBytes[2]] = pGammaTable[(4 * *(v10 - 1))
                                                                                               | ((int)*(v10 - 1) >> 6)];
              v4 = v13;
              v11 = v13 * this->m_nSliceStrideInBytes[3]
                  + v6 * this->m_nRowStrideInBytes[3]
                  + v8 * this->m_nStrideInBytes[3];
              ++v8;
              *(_DWORD *)&this->m_pAttributePtrs[3][v11] = 1065353216;
            }
            while ( v8 < this->m_nColumns );
            v5 = pBuffer;
          }
          m_nColumns = this->m_nColumns;
          ++v6;
          v5 = (const BGR888_t *)((char *)v5 + 2 * this->m_nColumns + this->m_nColumns);
          pBuffer = v5;
        }
        while ( v6 < this->m_nRows );
      }
      v13 = ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434370
// Name: protected: void FloatBitMap_t::LoadFromBufferRGB<struct BGRX8888_t>(struct BGRX8888_t const __near *,int,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferRGB<BGRX8888_t>(
        FloatBitMap_t *this,
        const BGRX8888_t *pBuffer,
        int nPixelCount,
        const float *pGammaTable)
{
  int v4; // ebx
  const BGRX8888_t *v5; // edi
  int v6; // esi
  int m_nColumns; // edx
  int v8; // eax
  double v9; // st7
  unsigned __int8 *v10; // edx
  unsigned int v11; // edx
  unsigned __int8 *z; // [esp+4h] [ebp-8h]
  int v13; // [esp+8h] [ebp-4h]

  v4 = 0;
  v13 = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      v6 = 0;
      if ( this->m_nRows > 0 )
      {
        m_nColumns = this->m_nColumns;
        do
        {
          v8 = 0;
          if ( m_nColumns > 0 )
          {
            z = &v5->g;
            do
            {
              *(float *)&this->m_pAttributePtrs[0][v4 * this->m_nSliceStrideInBytes[0]
                                                 + v6 * this->m_nRowStrideInBytes[0]
                                                 + v8 * this->m_nStrideInBytes[0]] = pGammaTable[(4 * z[1])
                                                                                               | ((int)z[1] >> 6)];
              v9 = pGammaTable[(4 * *z) | ((int)*z >> 6)];
              v10 = z;
              z += 4;
              *(float *)&this->m_pAttributePtrs[1][v13 * this->m_nSliceStrideInBytes[1]
                                                 + v6 * this->m_nRowStrideInBytes[1]
                                                 + v8 * this->m_nStrideInBytes[1]] = v9;
              *(float *)&this->m_pAttributePtrs[2][v13 * this->m_nSliceStrideInBytes[2]
                                                 + v6 * this->m_nRowStrideInBytes[2]
                                                 + v8 * this->m_nStrideInBytes[2]] = pGammaTable[(4 * *(v10 - 1))
                                                                                               | ((int)*(v10 - 1) >> 6)];
              v4 = v13;
              v11 = v13 * this->m_nSliceStrideInBytes[3]
                  + v6 * this->m_nRowStrideInBytes[3]
                  + v8 * this->m_nStrideInBytes[3];
              ++v8;
              *(_DWORD *)&this->m_pAttributePtrs[3][v11] = 1065353216;
            }
            while ( v8 < this->m_nColumns );
            v5 = pBuffer;
          }
          m_nColumns = this->m_nColumns;
          ++v6;
          v5 += this->m_nColumns;
          pBuffer = v5;
        }
        while ( v6 < this->m_nRows );
      }
      v13 = ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004344E0
// Name: protected: void FloatBitMap_t::LoadFromBufferUV<struct UV88_t>(struct UV88_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferUV<UV88_t>(FloatBitMap_t *this, const UV88_t *pBuffer, int nPixelCount)
{
  int i; // esi
  int v5; // edx
  int m_nColumns; // ebx
  int v7; // eax
  unsigned int v8; // ebx

  for ( i = 0; i < this->m_nSlices; ++i )
  {
    v5 = 0;
    if ( this->m_nRows > 0 )
    {
      m_nColumns = this->m_nColumns;
      do
      {
        v7 = 0;
        if ( m_nColumns > 0 )
        {
          do
          {
            *(float *)&this->m_pAttributePtrs[0][i * this->m_nSliceStrideInBytes[0]
                                               + v5 * this->m_nRowStrideInBytes[0]
                                               + v7 * this->m_nStrideInBytes[0]] = (float)((float)(pBuffer[v7].u + 128)
                                                                                         * 0.0078431377)
                                                                                 - 1.0;
            *(float *)&this->m_pAttributePtrs[1][v7 * this->m_nStrideInBytes[1]
                                               + i * this->m_nSliceStrideInBytes[1]
                                               + v5 * this->m_nRowStrideInBytes[1]] = (float)((float)(pBuffer[v7].v + 128)
                                                                                            * 0.0078431377)
                                                                                    - 1.0;
            *(_DWORD *)&this->m_pAttributePtrs[2][i * this->m_nSliceStrideInBytes[2]
                                                + v5 * this->m_nRowStrideInBytes[2]
                                                + v7 * this->m_nStrideInBytes[2]] = 0;
            v8 = i * this->m_nSliceStrideInBytes[3] + v5 * this->m_nRowStrideInBytes[3] + v7 * this->m_nStrideInBytes[3];
            ++v7;
            *(_DWORD *)&this->m_pAttributePtrs[3][v8] = 1065353216;
          }
          while ( v7 < this->m_nColumns );
        }
        m_nColumns = this->m_nColumns;
        ++v5;
        pBuffer += this->m_nColumns;
      }
      while ( v5 < this->m_nRows );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434630
// Name: protected: void FloatBitMap_t::LoadFromBufferUVWQ<struct UVWQ8888_t>(struct UVWQ8888_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferUVWQ<UVWQ8888_t>(
        FloatBitMap_t *this,
        const UVWQ8888_t *pBuffer,
        int nPixelCount)
{
  int v3; // edi
  const UVWQ8888_t *v4; // edx
  int v5; // esi
  int m_nColumns; // ebx
  int v7; // eax
  char *p_w; // edx
  unsigned int v9; // ebx

  v3 = 0;
  if ( this->m_nSlices > 0 )
  {
    v4 = pBuffer;
    do
    {
      v5 = 0;
      if ( this->m_nRows > 0 )
      {
        m_nColumns = this->m_nColumns;
        do
        {
          v7 = 0;
          if ( m_nColumns > 0 )
          {
            p_w = &v4->w;
            do
            {
              *(float *)&this->m_pAttributePtrs[0][v3 * this->m_nSliceStrideInBytes[0]
                                                 + v5 * this->m_nRowStrideInBytes[0]
                                                 + v7 * this->m_nStrideInBytes[0]] = (float)((float)(*(p_w - 2) + 128)
                                                                                           * 0.0078431377)
                                                                                   - 1.0;
              *(float *)&this->m_pAttributePtrs[1][v7 * this->m_nStrideInBytes[1]
                                                 + v3 * this->m_nSliceStrideInBytes[1]
                                                 + v5 * this->m_nRowStrideInBytes[1]] = (float)((float)(*(p_w - 1) + 128)
                                                                                              * 0.0078431377)
                                                                                      - 1.0;
              *(float *)&this->m_pAttributePtrs[2][v3 * this->m_nSliceStrideInBytes[2]
                                                 + v5 * this->m_nRowStrideInBytes[2]
                                                 + v7 * this->m_nStrideInBytes[2]] = (float)((float)(*p_w + 128)
                                                                                           * 0.0078431377)
                                                                                   - 1.0;
              v9 = v3 * this->m_nSliceStrideInBytes[3]
                 + v5 * this->m_nRowStrideInBytes[3]
                 + v7 * this->m_nStrideInBytes[3];
              ++v7;
              *(float *)&this->m_pAttributePtrs[3][v9] = (float)((float)(p_w[1] + 128) * 0.0078431377) - 1.0;
              p_w += 4;
            }
            while ( v7 < this->m_nColumns );
            v4 = pBuffer;
          }
          m_nColumns = this->m_nColumns;
          ++v5;
          v4 += this->m_nColumns;
          pBuffer = v4;
        }
        while ( v5 < this->m_nRows );
      }
      ++v3;
    }
    while ( v3 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004347A0
// Name: protected: void FloatBitMap_t::LoadFromBufferUVLX<struct UVLX8888_t>(struct UVLX8888_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::LoadFromBufferUVLX<UVLX8888_t>(
        FloatBitMap_t *this,
        const UVLX8888_t *pBuffer,
        int nPixelCount)
{
  int v3; // edi
  const UVLX8888_t *v4; // esi
  int v5; // edx
  int m_nColumns; // ebx
  int v7; // eax
  unsigned __int8 *p_l; // esi
  unsigned int v9; // ebx

  v3 = 0;
  if ( this->m_nSlices > 0 )
  {
    v4 = pBuffer;
    do
    {
      v5 = 0;
      if ( this->m_nRows > 0 )
      {
        m_nColumns = this->m_nColumns;
        do
        {
          v7 = 0;
          if ( m_nColumns > 0 )
          {
            p_l = &v4->l;
            do
            {
              *(float *)&this->m_pAttributePtrs[0][v3 * this->m_nSliceStrideInBytes[0]
                                                 + v5 * this->m_nRowStrideInBytes[0]
                                                 + v7 * this->m_nStrideInBytes[0]] = (float)((float)((char)*(p_l - 2) + 128)
                                                                                           * 0.0078431377)
                                                                                   - 1.0;
              *(float *)&this->m_pAttributePtrs[1][v3 * this->m_nSliceStrideInBytes[1]
                                                 + v5 * this->m_nRowStrideInBytes[1]
                                                 + v7 * this->m_nStrideInBytes[1]] = (float)((float)((char)*(p_l - 1) + 128)
                                                                                           * 0.0078431377)
                                                                                   - 1.0;
              *(float *)&this->m_pAttributePtrs[2][v3 * this->m_nSliceStrideInBytes[2]
                                                 + v5 * this->m_nRowStrideInBytes[2]
                                                 + v7 * this->m_nStrideInBytes[2]] = (float)*p_l * 0.0039215689;
              v9 = v3 * this->m_nSliceStrideInBytes[3]
                 + v5 * this->m_nRowStrideInBytes[3]
                 + v7 * this->m_nStrideInBytes[3];
              ++v7;
              *(_DWORD *)&this->m_pAttributePtrs[3][v9] = 1065353216;
              p_l += 4;
            }
            while ( v7 < this->m_nColumns );
            v4 = pBuffer;
          }
          m_nColumns = this->m_nColumns;
          ++v5;
          v4 += this->m_nColumns;
          pBuffer = v4;
        }
        while ( v5 < this->m_nRows );
      }
      ++v3;
    }
    while ( v3 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434900
// Name: protected: void FloatBitMap_t::WriteToBufferRGBA<struct ABGR8888_t>(struct ABGR8888_t __near *,int,unsigned short const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferRGBA<ABGR8888_t>(
        FloatBitMap_t *this,
        ABGR8888_t *pBuffer,
        int nPixelCount,
        const unsigned __int16 *pInvGammaTable)
{
  int v4; // edx
  ABGR8888_t *v5; // esi
  int i; // ebp
  int v7; // eax
  unsigned __int8 *p_g; // esi
  int v9; // edi
  int v10; // edi
  int v11; // edi
  int v12; // edi
  int v13; // edi
  int v14; // edi
  int v15; // edi
  int v16; // edi

  v4 = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      for ( i = 0; i < this->m_nRows; pBuffer = v5 )
      {
        v7 = 0;
        if ( this->m_nColumns > 0 )
        {
          p_g = &v5->g;
          do
          {
            v9 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[0][v7 * this->m_nStrideInBytes[0]
                                                                         + v4 * this->m_nSliceStrideInBytes[0]
                                                                         + i * this->m_nRowStrideInBytes[0]]
                                    * 1023.0)
                            + 0.5);
            if ( v9 <= 1023 )
              v10 = v9 < 0 ? 0 : v9;
            else
              v10 = 1023;
            p_g[1] = pInvGammaTable[v10] >> 2;
            v11 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[1][v4 * this->m_nSliceStrideInBytes[1]
                                                                          + i * this->m_nRowStrideInBytes[1]
                                                                          + v7 * this->m_nStrideInBytes[1]]
                                     * 1023.0)
                             + 0.5);
            if ( v11 <= 1023 )
              v12 = v11 < 0 ? 0 : v11;
            else
              v12 = 1023;
            *p_g = pInvGammaTable[v12] >> 2;
            v13 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[2][v7 * this->m_nStrideInBytes[2]
                                                                          + v4 * this->m_nSliceStrideInBytes[2]
                                                                          + i * this->m_nRowStrideInBytes[2]]
                                     * 1023.0)
                             + 0.5);
            if ( v13 <= 1023 )
              v14 = v13 < 0 ? 0 : v13;
            else
              v14 = 1023;
            *(p_g - 1) = pInvGammaTable[v14] >> 2;
            v15 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[3][v4 * this->m_nSliceStrideInBytes[3]
                                                                          + i * this->m_nRowStrideInBytes[3]
                                                                          + v7 * this->m_nStrideInBytes[3]]
                                     * 1023.0)
                             + 0.5);
            if ( v15 <= 1023 )
              v16 = v15 < 0 ? 0 : v15;
            else
              v16 = 1023;
            *(p_g - 2) = v16 >> 2;
            ++v7;
            p_g += 4;
          }
          while ( v7 < this->m_nColumns );
          v5 = pBuffer;
        }
        ++i;
        v5 += this->m_nColumns;
      }
      ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434AF0
// Name: protected: void FloatBitMap_t::WriteToBufferRGBA<struct RGBA8888_t>(struct RGBA8888_t __near *,int,unsigned short const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferRGBA<RGBA8888_t>(
        FloatBitMap_t *this,
        RGBA8888_t *pBuffer,
        int nPixelCount,
        const unsigned __int16 *pInvGammaTable)
{
  int v4; // edx
  RGBA8888_t *v5; // esi
  int i; // ebp
  int v7; // eax
  unsigned __int8 *p_b; // esi
  int v9; // edi
  int v10; // edi
  int v11; // edi
  int v12; // edi
  int v13; // edi
  int v14; // edi
  int v15; // edi
  int v16; // edi

  v4 = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      for ( i = 0; i < this->m_nRows; pBuffer = v5 )
      {
        v7 = 0;
        if ( this->m_nColumns > 0 )
        {
          p_b = &v5->b;
          do
          {
            v9 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[0][v7 * this->m_nStrideInBytes[0]
                                                                         + v4 * this->m_nSliceStrideInBytes[0]
                                                                         + i * this->m_nRowStrideInBytes[0]]
                                    * 1023.0)
                            + 0.5);
            if ( v9 <= 1023 )
              v10 = v9 < 0 ? 0 : v9;
            else
              v10 = 1023;
            *(p_b - 2) = pInvGammaTable[v10] >> 2;
            v11 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[1][v4 * this->m_nSliceStrideInBytes[1]
                                                                          + i * this->m_nRowStrideInBytes[1]
                                                                          + v7 * this->m_nStrideInBytes[1]]
                                     * 1023.0)
                             + 0.5);
            if ( v11 <= 1023 )
              v12 = v11 < 0 ? 0 : v11;
            else
              v12 = 1023;
            *(p_b - 1) = pInvGammaTable[v12] >> 2;
            v13 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[2][v4 * this->m_nSliceStrideInBytes[2]
                                                                          + i * this->m_nRowStrideInBytes[2]
                                                                          + v7 * this->m_nStrideInBytes[2]]
                                     * 1023.0)
                             + 0.5);
            if ( v13 <= 1023 )
              v14 = v13 < 0 ? 0 : v13;
            else
              v14 = 1023;
            *p_b = pInvGammaTable[v14] >> 2;
            v15 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[3][v4 * this->m_nSliceStrideInBytes[3]
                                                                          + i * this->m_nRowStrideInBytes[3]
                                                                          + v7 * this->m_nStrideInBytes[3]]
                                     * 1023.0)
                             + 0.5);
            if ( v15 <= 1023 )
              v16 = v15 < 0 ? 0 : v15;
            else
              v16 = 1023;
            p_b[1] = v16 >> 2;
            ++v7;
            p_b += 4;
          }
          while ( v7 < this->m_nColumns );
          v5 = pBuffer;
        }
        ++i;
        v5 += this->m_nColumns;
      }
      ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434CE0
// Name: protected: void FloatBitMap_t::WriteToBufferRGBA<struct BGRA8888_t>(struct BGRA8888_t __near *,int,unsigned short const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferRGBA<BGRA8888_t>(
        FloatBitMap_t *this,
        BGRA8888_t *pBuffer,
        int nPixelCount,
        const unsigned __int16 *pInvGammaTable)
{
  int v4; // edx
  BGRA8888_t *v5; // esi
  int i; // ebp
  int v7; // eax
  unsigned __int8 *p_g; // esi
  int v9; // edi
  int v10; // edi
  int v11; // edi
  int v12; // edi
  int v13; // edi
  int v14; // edi
  int v15; // edi
  int v16; // edi

  v4 = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      for ( i = 0; i < this->m_nRows; pBuffer = v5 )
      {
        v7 = 0;
        if ( this->m_nColumns > 0 )
        {
          p_g = &v5->g;
          do
          {
            v9 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[0][v7 * this->m_nStrideInBytes[0]
                                                                         + v4 * this->m_nSliceStrideInBytes[0]
                                                                         + i * this->m_nRowStrideInBytes[0]]
                                    * 1023.0)
                            + 0.5);
            if ( v9 <= 1023 )
              v10 = v9 < 0 ? 0 : v9;
            else
              v10 = 1023;
            p_g[1] = pInvGammaTable[v10] >> 2;
            v11 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[1][v4 * this->m_nSliceStrideInBytes[1]
                                                                          + i * this->m_nRowStrideInBytes[1]
                                                                          + v7 * this->m_nStrideInBytes[1]]
                                     * 1023.0)
                             + 0.5);
            if ( v11 <= 1023 )
              v12 = v11 < 0 ? 0 : v11;
            else
              v12 = 1023;
            *p_g = pInvGammaTable[v12] >> 2;
            v13 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[2][v7 * this->m_nStrideInBytes[2]
                                                                          + v4 * this->m_nSliceStrideInBytes[2]
                                                                          + i * this->m_nRowStrideInBytes[2]]
                                     * 1023.0)
                             + 0.5);
            if ( v13 <= 1023 )
              v14 = v13 < 0 ? 0 : v13;
            else
              v14 = 1023;
            *(p_g - 1) = pInvGammaTable[v14] >> 2;
            v15 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[3][v4 * this->m_nSliceStrideInBytes[3]
                                                                          + i * this->m_nRowStrideInBytes[3]
                                                                          + v7 * this->m_nStrideInBytes[3]]
                                     * 1023.0)
                             + 0.5);
            if ( v15 <= 1023 )
              v16 = v15 < 0 ? 0 : v15;
            else
              v16 = 1023;
            p_g[2] = v16 >> 2;
            ++v7;
            p_g += 4;
          }
          while ( v7 < this->m_nColumns );
          v5 = pBuffer;
        }
        ++i;
        v5 += this->m_nColumns;
      }
      ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434ED0
// Name: protected: void FloatBitMap_t::WriteToBufferRGB<struct RGB888_t>(struct RGB888_t __near *,int,unsigned short const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferRGB<RGB888_t>(
        FloatBitMap_t *this,
        RGB888_t *pBuffer,
        int nPixelCount,
        const unsigned __int16 *pInvGammaTable)
{
  int v4; // edx
  RGB888_t *v5; // edi
  int i; // ebp
  int v7; // eax
  unsigned __int8 *p_b; // edi
  int v9; // esi
  int v10; // esi
  int v11; // esi
  int v12; // esi
  int v13; // esi
  int v14; // esi

  v4 = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      for ( i = 0; i < this->m_nRows; pBuffer = v5 )
      {
        v7 = 0;
        if ( this->m_nColumns > 0 )
        {
          p_b = &v5->b;
          do
          {
            v9 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[0][v7 * this->m_nStrideInBytes[0]
                                                                         + v4 * this->m_nSliceStrideInBytes[0]
                                                                         + i * this->m_nRowStrideInBytes[0]]
                                    * 1023.0)
                            + 0.5);
            if ( v9 <= 1023 )
              v10 = v9 < 0 ? 0 : v9;
            else
              v10 = 1023;
            *(p_b - 2) = pInvGammaTable[v10] >> 2;
            v11 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[1][v4 * this->m_nSliceStrideInBytes[1]
                                                                          + i * this->m_nRowStrideInBytes[1]
                                                                          + v7 * this->m_nStrideInBytes[1]]
                                     * 1023.0)
                             + 0.5);
            if ( v11 <= 1023 )
              v12 = v11 < 0 ? 0 : v11;
            else
              v12 = 1023;
            *(p_b - 1) = pInvGammaTable[v12] >> 2;
            v13 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[2][v4 * this->m_nSliceStrideInBytes[2]
                                                                          + i * this->m_nRowStrideInBytes[2]
                                                                          + v7 * this->m_nStrideInBytes[2]]
                                     * 1023.0)
                             + 0.5);
            if ( v13 <= 1023 )
              v14 = v13 < 0 ? 0 : v13;
            else
              v14 = 1023;
            *p_b = pInvGammaTable[v14] >> 2;
            ++v7;
            p_b += 3;
          }
          while ( v7 < this->m_nColumns );
          v5 = pBuffer;
        }
        ++i;
        v5 = (RGB888_t *)((char *)v5 + 2 * this->m_nColumns + this->m_nColumns);
      }
      ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00435070
// Name: protected: void FloatBitMap_t::WriteToBufferRGB<struct BGR888_t>(struct BGR888_t __near *,int,unsigned short const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferRGB<BGR888_t>(
        FloatBitMap_t *this,
        BGR888_t *pBuffer,
        int nPixelCount,
        const unsigned __int16 *pInvGammaTable)
{
  int v4; // edx
  BGR888_t *v5; // edi
  int i; // ebp
  int v7; // eax
  unsigned __int8 *p_g; // edi
  int v9; // esi
  int v10; // esi
  int v11; // esi
  int v12; // esi
  int v13; // esi
  int v14; // esi

  v4 = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      for ( i = 0; i < this->m_nRows; pBuffer = v5 )
      {
        v7 = 0;
        if ( this->m_nColumns > 0 )
        {
          p_g = &v5->g;
          do
          {
            v9 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[0][v7 * this->m_nStrideInBytes[0]
                                                                         + v4 * this->m_nSliceStrideInBytes[0]
                                                                         + i * this->m_nRowStrideInBytes[0]]
                                    * 1023.0)
                            + 0.5);
            if ( v9 <= 1023 )
              v10 = v9 < 0 ? 0 : v9;
            else
              v10 = 1023;
            p_g[1] = pInvGammaTable[v10] >> 2;
            v11 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[1][v4 * this->m_nSliceStrideInBytes[1]
                                                                          + i * this->m_nRowStrideInBytes[1]
                                                                          + v7 * this->m_nStrideInBytes[1]]
                                     * 1023.0)
                             + 0.5);
            if ( v11 <= 1023 )
              v12 = v11 < 0 ? 0 : v11;
            else
              v12 = 1023;
            *p_g = pInvGammaTable[v12] >> 2;
            v13 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[2][v7 * this->m_nStrideInBytes[2]
                                                                          + v4 * this->m_nSliceStrideInBytes[2]
                                                                          + i * this->m_nRowStrideInBytes[2]]
                                     * 1023.0)
                             + 0.5);
            if ( v13 <= 1023 )
              v14 = v13 < 0 ? 0 : v13;
            else
              v14 = 1023;
            *(p_g - 1) = pInvGammaTable[v14] >> 2;
            ++v7;
            p_g += 3;
          }
          while ( v7 < this->m_nColumns );
          v5 = pBuffer;
        }
        ++i;
        v5 = (BGR888_t *)((char *)v5 + 2 * this->m_nColumns + this->m_nColumns);
      }
      ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00435210
// Name: protected: void FloatBitMap_t::WriteToBufferRGB<struct BGRX8888_t>(struct BGRX8888_t __near *,int,unsigned short const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferRGB<BGRX8888_t>(
        FloatBitMap_t *this,
        BGRX8888_t *pBuffer,
        int nPixelCount,
        const unsigned __int16 *pInvGammaTable)
{
  int v4; // edx
  BGRX8888_t *v5; // edi
  int i; // ebp
  int v7; // eax
  unsigned __int8 *p_g; // edi
  int v9; // esi
  int v10; // esi
  int v11; // esi
  int v12; // esi
  int v13; // esi
  int v14; // esi

  v4 = 0;
  if ( this->m_nSlices > 0 )
  {
    v5 = pBuffer;
    do
    {
      for ( i = 0; i < this->m_nRows; pBuffer = v5 )
      {
        v7 = 0;
        if ( this->m_nColumns > 0 )
        {
          p_g = &v5->g;
          do
          {
            v9 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[0][v7 * this->m_nStrideInBytes[0]
                                                                         + v4 * this->m_nSliceStrideInBytes[0]
                                                                         + i * this->m_nRowStrideInBytes[0]]
                                    * 1023.0)
                            + 0.5);
            if ( v9 <= 1023 )
              v10 = v9 < 0 ? 0 : v9;
            else
              v10 = 1023;
            p_g[1] = pInvGammaTable[v10] >> 2;
            v11 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[1][v4 * this->m_nSliceStrideInBytes[1]
                                                                          + i * this->m_nRowStrideInBytes[1]
                                                                          + v7 * this->m_nStrideInBytes[1]]
                                     * 1023.0)
                             + 0.5);
            if ( v11 <= 1023 )
              v12 = v11 < 0 ? 0 : v11;
            else
              v12 = 1023;
            *p_g = pInvGammaTable[v12] >> 2;
            v13 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[2][v7 * this->m_nStrideInBytes[2]
                                                                          + v4 * this->m_nSliceStrideInBytes[2]
                                                                          + i * this->m_nRowStrideInBytes[2]]
                                     * 1023.0)
                             + 0.5);
            if ( v13 <= 1023 )
              v14 = v13 < 0 ? 0 : v13;
            else
              v14 = 1023;
            *(p_g - 1) = pInvGammaTable[v14] >> 2;
            ++v7;
            p_g += 4;
          }
          while ( v7 < this->m_nColumns );
          v5 = pBuffer;
        }
        ++i;
        v5 += this->m_nColumns;
      }
      ++v4;
    }
    while ( v4 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004353A0
// Name: protected: void FloatBitMap_t::WriteToBufferUV<struct UV88_t>(struct UV88_t __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferUV<UV88_t>(FloatBitMap_t *this, UV88_t *pBuffer, int nPixelCount)
{
  int i; // ebp
  int j; // edi
  int k; // edx
  int v7; // esi
  char v8; // al
  int v9; // esi
  char v10; // al

  for ( i = 0; i < this->m_nSlices; ++i )
  {
    for ( j = 0; j < this->m_nRows; pBuffer += this->m_nColumns )
    {
      for ( k = 0; k < this->m_nColumns; ++k )
      {
        v7 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[0][k * this->m_nStrideInBytes[0]
                                                                     + i * this->m_nSliceStrideInBytes[0]
                                                                     + j * this->m_nRowStrideInBytes[0]]
                                + 1.0)
                        * 127.5);
        if ( v7 <= 255 )
          v8 = v7 < 0 ? 0 : v7;
        else
          v8 = -1;
        pBuffer[k].u = v8 + 0x80;
        v9 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[1][i * this->m_nSliceStrideInBytes[1]
                                                                     + j * this->m_nRowStrideInBytes[1]
                                                                     + k * this->m_nStrideInBytes[1]]
                                + 1.0)
                        * 127.5);
        if ( v9 <= 255 )
          v10 = v9 < 0 ? 0 : v9;
        else
          v10 = -1;
        pBuffer[k].v = v10 + 0x80;
      }
      ++j;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004354C0
// Name: protected: void FloatBitMap_t::WriteToBufferUVWQ<struct UVWQ8888_t>(struct UVWQ8888_t __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferUVWQ<UVWQ8888_t>(FloatBitMap_t *this, UVWQ8888_t *pBuffer, int nPixelCount)
{
  int v3; // ebp
  UVWQ8888_t *v4; // esi
  int i; // ebx
  int v6; // edx
  char *p_w; // esi
  int v8; // edi
  char v9; // al
  int v10; // edi
  char v11; // al
  int v12; // edi
  char v13; // al
  int v14; // edi
  char v15; // al

  v3 = 0;
  if ( this->m_nSlices > 0 )
  {
    v4 = pBuffer;
    do
    {
      for ( i = 0; i < this->m_nRows; pBuffer = v4 )
      {
        v6 = 0;
        if ( this->m_nColumns > 0 )
        {
          p_w = &v4->w;
          do
          {
            v8 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[0][v6 * this->m_nStrideInBytes[0]
                                                                         + v3 * this->m_nSliceStrideInBytes[0]
                                                                         + i * this->m_nRowStrideInBytes[0]]
                                    + 1.0)
                            * 127.5);
            if ( v8 <= 255 )
              v9 = v8 < 0 ? 0 : v8;
            else
              v9 = -1;
            *(p_w - 2) = v9 + 0x80;
            v10 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[1][v3 * this->m_nSliceStrideInBytes[1]
                                                                          + i * this->m_nRowStrideInBytes[1]
                                                                          + v6 * this->m_nStrideInBytes[1]]
                                     + 1.0)
                             * 127.5);
            if ( v10 <= 255 )
              v11 = v10 < 0 ? 0 : v10;
            else
              v11 = -1;
            *(p_w - 1) = v11 + 0x80;
            v12 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[2][v3 * this->m_nSliceStrideInBytes[2]
                                                                          + i * this->m_nRowStrideInBytes[2]
                                                                          + v6 * this->m_nStrideInBytes[2]]
                                     + 1.0)
                             * 127.5);
            if ( v12 <= 255 )
              v13 = v12 < 0 ? 0 : v12;
            else
              v13 = -1;
            *p_w = v13 + 0x80;
            v14 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[3][v6 * this->m_nStrideInBytes[3]
                                                                          + v3 * this->m_nSliceStrideInBytes[3]
                                                                          + i * this->m_nRowStrideInBytes[3]]
                                     + 1.0)
                             * 127.5);
            if ( v14 <= 255 )
              v15 = v14 < 0 ? 0 : v14;
            else
              v15 = -1;
            p_w[1] = v15 + 0x80;
            ++v6;
            p_w += 4;
          }
          while ( v6 < this->m_nColumns );
          v4 = pBuffer;
        }
        ++i;
        v4 += this->m_nColumns;
      }
      ++v3;
    }
    while ( v3 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00435690
// Name: protected: void FloatBitMap_t::WriteToBufferUVLX<struct UVLX8888_t>(struct UVLX8888_t __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WriteToBufferUVLX<UVLX8888_t>(FloatBitMap_t *this, UVLX8888_t *pBuffer, int nPixelCount)
{
  int v3; // ebx
  UVLX8888_t *v4; // esi
  int i; // ebp
  int v6; // edx
  _BYTE *p_l; // esi
  int v8; // edi
  char v9; // al
  int v10; // edi
  char v11; // al
  int v12; // edi
  char v13; // al

  v3 = 0;
  if ( this->m_nSlices > 0 )
  {
    v4 = pBuffer;
    do
    {
      for ( i = 0; i < this->m_nRows; pBuffer = v4 )
      {
        v6 = 0;
        if ( this->m_nColumns > 0 )
        {
          p_l = &v4->l;
          do
          {
            v8 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[0][v6 * this->m_nStrideInBytes[0]
                                                                         + v3 * this->m_nSliceStrideInBytes[0]
                                                                         + i * this->m_nRowStrideInBytes[0]]
                                    + 1.0)
                            * 127.5);
            if ( v8 <= 255 )
              v9 = v8 < 0 ? 0 : v8;
            else
              v9 = -1;
            *(p_l - 2) = v9 + 0x80;
            v10 = (int)(float)((float)(*(float *)&this->m_pAttributePtrs[1][v3 * this->m_nSliceStrideInBytes[1]
                                                                          + i * this->m_nRowStrideInBytes[1]
                                                                          + v6 * this->m_nStrideInBytes[1]]
                                     + 1.0)
                             * 127.5);
            if ( v10 <= 255 )
              v11 = v10 < 0 ? 0 : v10;
            else
              v11 = -1;
            *(p_l - 1) = v11 + 0x80;
            v12 = (int)(float)(*(float *)&this->m_pAttributePtrs[2][v3 * this->m_nSliceStrideInBytes[2]
                                                                  + i * this->m_nRowStrideInBytes[2]
                                                                  + v6 * this->m_nStrideInBytes[2]]
                             * 255.0);
            if ( v12 <= 255 )
              v13 = v12 < 0 ? 0 : v12;
            else
              v13 = -1;
            *p_l = v13;
            p_l[1] = -1;
            ++v6;
            p_l += 4;
          }
          while ( v6 < this->m_nColumns );
          v4 = pBuffer;
        }
        ++i;
        v4 += this->m_nColumns;
      }
      ++v3;
    }
    while ( v3 < this->m_nSlices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00533760
// Name: _dynamic_initializer_for__CDmeAmalgamatedTexture::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAmalgamatedTexture::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAmalgamatedTexture::s_Allocator,
    blockSize: 168,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAmalgamatedTexture pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAmalgamatedTexture::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00535170
// Name: _dynamic_atexit_destructor_for__CDmeAmalgamatedTexture::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAmalgamatedTexture::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAmalgamatedTexture::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0042D220
// Name: class CDmeImage __near * CreateElement<class CDmeImage>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeImage *__cdecl CreateElement<CDmeImage>(const char *pObjectName, DmFileId_t fileid, const UniqueId_t *pObjectID)
{
  DmElementHandle_t v3; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi

  v3 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmeImage::m_classType.u.m_Id,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v3);
  v5 = v4;
  if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeImage::m_classType) )
    return (CDmeImage *)v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00533790
// Name: _dynamic_initializer_for__g_CDmeAmalgamatedTexture_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAmalgamatedTexture_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAmalgamatedTexture_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005337A0
// Name: _dynamic_initializer_for__g_CDmeAmalgamatedTexture_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAmalgamatedTexture_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAmalgamatedTexture_Helper,
           classname: "DmeAmalgamatedTexture",
           pFactory: &g_CDmeAmalgamatedTexture_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x00535180
// Name: _dynamic_atexit_destructor_for__g_CDmeAmalgamatedTexture_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAmalgamatedTexture_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeAmalgamatedTexture_Factory.m_CallBackList);
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00566F80
// Name: public: void FloatBitMap_t::Init(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::Init(
        FloatBitMap_t *this,
        unsigned __int8 *nXSize,
        unsigned __int8 *nYSize,
        int nZSize,
        char nAttributeMask)
{
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  CSOAContainer::PurgeData(this);
  CSOAContainer::SetAttributeType(this, nAttrIdx: 0, nDataType: ATTRDATATYPE_FLOAT, bAllocateMemory: nAttributeMask & 1);
  CSOAContainer::SetAttributeType(
    this,
    nAttrIdx: 1,
    nDataType: ATTRDATATYPE_FLOAT,
    bAllocateMemory: (nAttributeMask & 2) != 0);
  CSOAContainer::SetAttributeType(
    this,
    nAttrIdx: 2,
    nDataType: ATTRDATATYPE_FLOAT,
    bAllocateMemory: (nAttributeMask & 4) != 0);
  CSOAContainer::SetAttributeType(
    this,
    nAttrIdx: 3,
    nDataType: ATTRDATATYPE_FLOAT,
    bAllocateMemory: (nAttributeMask & 8) != 0);
  CSOAContainer::AllocateData(this, nNCols: nXSize, nNRows: nYSize, nSlices: nZSize);
  if ( (nAttributeMask & 8) == 0 )
    CSOAContainer::FillAttr(this, a2: (int)&savedregs, nAttr: 3, flValue: 0x3F800000u);
}

//------------------------------------------------------------------------------
// Address: 0x00567020
// Name: protected: void CDmeAmalgamatedTexture::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAmalgamatedTexture::OnConstruction(CDmeAmalgamatedTexture *this)
{
  CDmaElementArray<CDmeSheetImage> *p_m_ImageList; // edi
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  p_m_ImageList = &this->m_ImageList;
  this->m_ImageList.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "images",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_ImageList);
  CDmAttribute::SetElementTypeSymbol(this: p_m_ImageList->m_pAttribute, typeSymbol: CDmeSheetImage::m_classType);
  value = 1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "packmode", type: AT_INT, pMemory: &this->m_ePackingMode);
  this->m_ePackingMode.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, &value);
  this->m_Sequences.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "sequences",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_Sequences);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Sequences.m_pAttribute, typeSymbol: CDmeSheetSequence::m_classType);
  this->m_nWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "width",
                                  type: AT_INT,
                                  pMemory: &this->m_nWidth);
  this->m_nHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "height",
                                   type: AT_INT,
                                   pMemory: &this->m_nHeight);
  this->m_pPackedImage.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "packedImage",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_pPackedImage);
  CDmAttribute::SetElementTypeSymbol(this: this->m_pPackedImage.m_pAttribute, typeSymbol: CDmeImage::m_classType);
  this->m_SequenceCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00567170
// Name: protected: CDmeAmalgamatedTexture::CDmeAmalgamatedTexture(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeAmalgamatedTexture *__thiscall CDmeAmalgamatedTexture::CDmeAmalgamatedTexture(
        CDmeAmalgamatedTexture *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeAmalgamatedTexture_vtbl *)&CDmeAmalgamatedTexture::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_ImageList);
  this->m_ePackingMode.m_pAttribute = nullptr;
  this->m_ePackingMode.m_Storage = 0;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Sequences);
  this->m_nWidth.m_pAttribute = nullptr;
  this->m_nWidth.m_Storage = 0;
  this->m_nHeight.m_pAttribute = nullptr;
  this->m_nHeight.m_Storage = 0;
  this->m_pPackedImage.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_pPackedImage.m_pAttribute = nullptr;
  this->m_pPackedImage.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005671F0
// Name: public: virtual void CDmeAmalgamatedTexture::OnAttributeArrayElementRemoved(class CDmAttribute __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAmalgamatedTexture::OnAttributeArrayElementRemoved(
        CDmeSheetImage *this,
        CDmAttribute *pAttribute,
        CDmAttribute *nFirstElem,
        int nLastElem)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00567200
// Name: public: virtual bool CDmeAmalgamatedTexture::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAmalgamatedTexture::IsA(CDmeAmalgamatedTexture *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAmalgamatedTexture::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00567230
// Name: public: virtual int CDmeAmalgamatedTexture::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAmalgamatedTexture::GetInheritanceDepth(CDmeAmalgamatedTexture *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAmalgamatedTexture::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00567270
// Name: protected: virtual int CDmeAmalgamatedTexture::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAmalgamatedTexture::AllocatedSize(CDmeChannelsClip *this)
{
  return 168;
}

//------------------------------------------------------------------------------
// Address: 0x00567280
// Name: protected: virtual void CDmeAmalgamatedTexture::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAmalgamatedTexture::PerformConstruction(CDmeAmalgamatedTexture *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeAmalgamatedTexture::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B6DE0
// Name: _dynamic_initializer_for__CDmeAmalgamatedTexture::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAmalgamatedTexture::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAmalgamatedTexture::s_Allocator,
    blockSize: 0xA8u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAmalgamatedTexture pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAmalgamatedTexture::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BC3F0
// Name: _dynamic_atexit_destructor_for__CDmeAmalgamatedTexture::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAmalgamatedTexture::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAmalgamatedTexture::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B6E10
// Name: _dynamic_initializer_for__g_CDmeAmalgamatedTexture_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAmalgamatedTexture_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAmalgamatedTexture_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B6E20
// Name: _dynamic_initializer_for__g_CDmeAmalgamatedTexture_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAmalgamatedTexture_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAmalgamatedTexture_Helper,
           classname: "DmeAmalgamatedTexture",
           pFactory: &g_CDmeAmalgamatedTexture_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006BC400
// Name: _dynamic_atexit_destructor_for__g_CDmeAmalgamatedTexture_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAmalgamatedTexture_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeAmalgamatedTexture_Factory.m_CallBackList);
}

} // namespace vmap

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x10091F70
// Name: protected: void CDmeAmalgamatedTexture::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAmalgamatedTexture::OnConstruction(CDmeAmalgamatedTexture *this)
{
  CDmaElementArray<CDmeSheetImage> *p_m_ImageList; // edi
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-4h] BYREF

  p_m_ImageList = &this->m_ImageList;
  this->m_ImageList.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "images",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_ImageList);
  CDmAttribute::SetElementTypeSymbol(this: p_m_ImageList->m_pAttribute, typeSymbol: CDmeSheetImage::m_classType);
  value = 1;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "packmode", type: AT_INT, pMemory: &this->m_ePackingMode);
  this->m_ePackingMode.m_pAttribute = v3;
  CDmAttribute::SetValue<int>(this: v3, &value);
  this->m_Sequences.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "sequences",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_Sequences);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Sequences.m_pAttribute, typeSymbol: CDmeSheetSequence::m_classType);
  this->m_nWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "width",
                                  type: AT_INT,
                                  pMemory: &this->m_nWidth);
  this->m_nHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "height",
                                   type: AT_INT,
                                   pMemory: &this->m_nHeight);
  this->m_pPackedImage.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "packedImage",
                                        type: AT_FIRST_VALUE_TYPE,
                                        pMemory: &this->m_pPackedImage);
  CDmAttribute::SetElementTypeSymbol(this: this->m_pPackedImage.m_pAttribute, typeSymbol: CDmeImage::m_classType);
  this->m_SequenceCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100920C0
// Name: protected: CDmeAmalgamatedTexture::CDmeAmalgamatedTexture(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeAmalgamatedTexture *__thiscall CDmeAmalgamatedTexture::CDmeAmalgamatedTexture(
        CDmeAmalgamatedTexture *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeAmalgamatedTexture_vtbl *)&CDmeAmalgamatedTexture::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_ImageList);
  this->m_ePackingMode.m_pAttribute = nullptr;
  this->m_ePackingMode.m_Storage = 0;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Sequences);
  this->m_nWidth.m_pAttribute = nullptr;
  this->m_nWidth.m_Storage = 0;
  this->m_nHeight.m_pAttribute = nullptr;
  this->m_nHeight.m_Storage = 0;
  this->m_pPackedImage.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_pPackedImage.m_pAttribute = nullptr;
  this->m_pPackedImage.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10092140
// Name: public: virtual bool CDmeAmalgamatedTexture::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAmalgamatedTexture::IsA(CDmeAmalgamatedTexture *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAmalgamatedTexture::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10092170
// Name: public: virtual int CDmeAmalgamatedTexture::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAmalgamatedTexture::GetInheritanceDepth(CDmeAmalgamatedTexture *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAmalgamatedTexture::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100921B0
// Name: protected: virtual int CDmeAmalgamatedTexture::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAmalgamatedTexture::AllocatedSize(CDmeAmalgamatedTexture *this)
{
  return 168;
}

//------------------------------------------------------------------------------
// Address: 0x100921C0
// Name: protected: virtual void CDmeAmalgamatedTexture::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAmalgamatedTexture::PerformConstruction(CDmeAmalgamatedTexture *this)
{
  CDmElementFramework::Disconnect((CDmeTexture *)this);
  CDmeAmalgamatedTexture::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x10092520
// Name: public: virtual void CDmeAmalgamatedTexture::OnAttributeArrayElementRemoved(class CDmAttribute __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAmalgamatedTexture::OnAttributeArrayElementRemoved(
        CDmeSheetImage *this,
        CDmAttribute *pAttribute,
        CDmAttribute *nFirstElem,
        int nLastElem)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100C4920
// Name: _dynamic_initializer_for__CDmeAmalgamatedTexture::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAmalgamatedTexture::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAmalgamatedTexture::s_Allocator,
    blockSize: 168,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAmalgamatedTexture pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAmalgamatedTexture::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x100C5270
// Name: _dynamic_atexit_destructor_for__CDmeAmalgamatedTexture::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAmalgamatedTexture::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAmalgamatedTexture::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x100C4950
// Name: _dynamic_initializer_for__g_CDmeAmalgamatedTexture_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAmalgamatedTexture_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAmalgamatedTexture_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4960
// Name: _dynamic_initializer_for__g_CDmeAmalgamatedTexture_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAmalgamatedTexture_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAmalgamatedTexture_Helper,
           classname: "DmeAmalgamatedTexture",
           pFactory: &g_CDmeAmalgamatedTexture_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x100C5280
// Name: _dynamic_atexit_destructor_for__g_CDmeAmalgamatedTexture_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAmalgamatedTexture_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeAmalgamatedTexture_Factory.m_CallBackList);
}

} // namespace vtex_dll
