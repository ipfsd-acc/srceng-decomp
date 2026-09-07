// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapsolid.cpp
// Functions: 66
// ============================================================

#include "hammer\mapsolid.h"

//------------------------------------------------------------------------------
// Address: 0x10049240
// Name: private: void BlockArray<class CMapFace,6,86>::GetBlocks(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlockArray<CMapFace,6,86>::GetBlocks(BlockArray<CMapFace,6,86> *this, int nNewBlocks)
{
  CMapFace *v2; // [esp+4h] [ebp-2Ch]
  _DWORD *p; // [esp+14h] [ebp-1Ch]
  int j; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]

  for ( i = this->nBlocks; i < nNewBlocks; ++i )
  {
    p = operator new[](nSize: 0xA6Cu);
    if ( p != nullptr )
    {
      *p = 6;
      `eh vector constructor iterator'(
        ptr: p + 1,
        size: 0x1BCu,
        count: 6,
        pCtor: (void (__thiscall *)(void *))CMapFace::CMapFace,
        pDtor: (void (__thiscall *)(void *))CMapFace::~CMapFace);
      v2 = (CMapFace *)(p + 1);
    }
    else
    {
      v2 = nullptr;
    }
    this->Blocks[i] = v2;
  }
  for ( j = nNewBlocks; j < this->nBlocks; ++j )
  {
    if ( this->Blocks[j] != nullptr )
      CMapFace::`vector deleting destructor'(this: this->Blocks[j], a2: 3u);
  }
  this->nBlocks = nNewBlocks;
}

//------------------------------------------------------------------------------
// Address: 0x100493D0
// Name: public: void BlockArray<class CMapFace,6,86>::SetCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlockArray<CMapFace,6,86>::SetCount(BlockArray<CMapFace,6,86> *this, int nObjects)
{
  unsigned int nNewBlocks; // [esp+4h] [ebp-4h]

  if ( nObjects != this->nCount )
  {
    nNewBlocks = nObjects / 6;
    if ( 6 * (nObjects / 6) < nObjects )
      ++nNewBlocks;
    if ( nNewBlocks != this->nBlocks )
    {
      if ( nNewBlocks > 0x57 )
        _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
      BlockArray<CMapFace,6,86>::GetBlocks(this, nNewBlocks);
    }
    this->nCount = nObjects;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049460
// Name: public: class CMapFace __near & BlockArray<class CMapFace,6,86>::operator[](int)
// Source: json
//------------------------------------------------------------------------------
CMapFace *__thiscall BlockArray<CMapFace,6,86>::operator[](BlockArray<CMapFace,6,86> *this, int iIndex)
{
  if ( iIndex >= this->nCount )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)iIndex, this->nCount);
    BlockArray<CMapFace,6,86>::SetCount(this, nObjects: iIndex + 1);
  }
  return &this->Blocks[iIndex / 6][iIndex % 6];
}

//------------------------------------------------------------------------------
// Address: 0x100A8C40
// Name: private: void BlockArray<class CSSVertex,16,32>::GetBlocks(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlockArray<CSSVertex,16,32>::GetBlocks(BlockArray<CSSVertex,16,32> *this, int nNewBlocks)
{
  int v3; // ecx
  int nBlocks; // edi
  _DWORD *v5; // eax
  CSSVertex *v6; // esi
  int i; // esi
  CSSVertex *v8; // eax
  unsigned int *p_id; // edi

  v3 = nNewBlocks;
  nBlocks = this->nBlocks;
  if ( nBlocks < nNewBlocks )
  {
    do
    {
      v5 = operator new[](nSize: 0x304u);
      v6 = nullptr;
      if ( v5 != nullptr )
      {
        v6 = (CSSVertex *)(v5 + 1);
        *v5 = 16;
        `eh vector constructor iterator'(
          ptr: v5 + 1,
          size: 0x30u,
          count: 16,
          pCtor: (void (__thiscall *)(void *))CSSVertex::CSSVertex,
          pDtor: (void (__thiscall *)(void *))CSSVertex::~CSSVertex);
      }
      this->Blocks[nBlocks++] = v6;
    }
    while ( nBlocks < nNewBlocks );
    v3 = nNewBlocks;
  }
  for ( i = v3; i < this->nBlocks; ++i )
  {
    v8 = this->Blocks[i];
    if ( v8 != nullptr )
    {
      p_id = &v8[-1].id;
      `eh vector destructor iterator'(
        ptr: v8,
        size: 0x30u,
        count: v8[-1].id,
        pDtor: (void (__thiscall *)(void *))CSSVertex::~CSSVertex);
      operator delete(p: p_id);
      LOWORD(v3) = nNewBlocks;
    }
  }
  this->nBlocks = v3;
}

//------------------------------------------------------------------------------
// Address: 0x100A8D20
// Name: private: void BlockArray<class CSSEdge,16,32>::GetBlocks(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlockArray<CSSEdge,16,32>::GetBlocks(BlockArray<CSSEdge,16,32> *this, int nNewBlocks)
{
  int v3; // ecx
  int nBlocks; // edi
  _DWORD *v5; // eax
  CSSEdge *v6; // esi
  int i; // esi
  CSSEdge *v8; // eax
  unsigned int *p_id; // edi

  v3 = nNewBlocks;
  nBlocks = this->nBlocks;
  if ( nBlocks < nNewBlocks )
  {
    do
    {
      v5 = operator new[](nSize: 0x404u);
      v6 = nullptr;
      if ( v5 != nullptr )
      {
        v6 = (CSSEdge *)(v5 + 1);
        *v5 = 16;
        `eh vector constructor iterator'(
          ptr: v5 + 1,
          size: 0x40u,
          count: 16,
          pCtor: (void (__thiscall *)(void *))CSSEdge::CSSEdge,
          pDtor: (void (__thiscall *)(void *))CSSEdge::~CSSEdge);
      }
      this->Blocks[nBlocks++] = v6;
    }
    while ( nBlocks < nNewBlocks );
    v3 = nNewBlocks;
  }
  for ( i = v3; i < this->nBlocks; ++i )
  {
    v8 = this->Blocks[i];
    if ( v8 != nullptr )
    {
      p_id = &v8[-1].id;
      `eh vector destructor iterator'(
        ptr: v8,
        size: 0x40u,
        count: v8[-1].id,
        pDtor: (void (__thiscall *)(void *))CSSEdge::~CSSEdge);
      operator delete(p: p_id);
      LOWORD(v3) = nNewBlocks;
    }
  }
  this->nBlocks = v3;
}

//------------------------------------------------------------------------------
// Address: 0x100A8E00
// Name: private: void BlockArray<class CSSFace,16,10>::GetBlocks(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlockArray<CSSFace,16,10>::GetBlocks(BlockArray<CSSFace,16,10> *this, int nNewBlocks)
{
  int v3; // ecx
  int nBlocks; // edi
  _DWORD *v5; // eax
  CSSFace *v6; // esi
  int i; // esi
  CSSFace *v8; // eax
  unsigned int *p_id; // edi

  v3 = nNewBlocks;
  nBlocks = this->nBlocks;
  if ( nBlocks < nNewBlocks )
  {
    do
    {
      v5 = operator new[](nSize: 0x3904u);
      v6 = nullptr;
      if ( v5 != nullptr )
      {
        v6 = (CSSFace *)(v5 + 1);
        *v5 = 16;
        `eh vector constructor iterator'(
          ptr: v5 + 1,
          size: 0x390u,
          count: 16,
          pCtor: (void (__thiscall *)(void *))CSSFace::CSSFace,
          pDtor: (void (__thiscall *)(void *))CSSFace::~CSSFace);
      }
      this->Blocks[nBlocks++] = v6;
    }
    while ( nBlocks < nNewBlocks );
    v3 = nNewBlocks;
  }
  for ( i = v3; i < this->nBlocks; ++i )
  {
    v8 = this->Blocks[i];
    if ( v8 != nullptr )
    {
      p_id = &v8[-1].id;
      `eh vector destructor iterator'(
        ptr: v8,
        size: 0x390u,
        count: v8[-1].id,
        pDtor: (void (__thiscall *)(void *))CSSFace::~CSSFace);
      operator delete(p: p_id);
      LOWORD(v3) = nNewBlocks;
    }
  }
  this->nBlocks = v3;
}

//------------------------------------------------------------------------------
// Address: 0x100A8ED0
// Name: public: BlockArray<class CSSVertex,16,32>::~BlockArray<class CSSVertex,16,32>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlockArray<CSSVertex,16,32>::~BlockArray<CSSVertex,16,32>(BlockArray<CSSVertex,16,32> *this)
{
  BlockArray<CSSVertex,16,32>::GetBlocks(this, nNewBlocks: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100A8EE0
// Name: public: BlockArray<class CSSEdge,16,32>::~BlockArray<class CSSEdge,16,32>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlockArray<CSSEdge,16,32>::~BlockArray<CSSEdge,16,32>(BlockArray<CSSEdge,16,32> *this)
{
  BlockArray<CSSEdge,16,32>::GetBlocks(this, nNewBlocks: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100A8EF0
// Name: public: BlockArray<class CSSFace,16,10>::~BlockArray<class CSSFace,16,10>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlockArray<CSSFace,16,10>::~BlockArray<CSSFace,16,10>(BlockArray<CSSFace,16,10> *this)
{
  BlockArray<CSSFace,16,10>::GetBlocks(this, nNewBlocks: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100A8F00
// Name: public: void BlockArray<class CSSVertex,16,32>::SetCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlockArray<CSSVertex,16,32>::SetCount(BlockArray<CSSVertex,16,32> *this, int nObjects)
{
  unsigned int v3; // esi

  if ( nObjects != this->nCount )
  {
    v3 = nObjects / 16;
    if ( 16 * (nObjects / 16) < nObjects )
      ++v3;
    if ( v3 != this->nBlocks )
    {
      if ( v3 > 0x21 )
        _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
      BlockArray<CSSVertex,16,32>::GetBlocks(this, nNewBlocks: v3);
    }
    this->nCount = nObjects;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A8F70
// Name: public: void BlockArray<class CSSEdge,16,32>::SetCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlockArray<CSSEdge,16,32>::SetCount(BlockArray<CSSEdge,16,32> *this, int nObjects)
{
  unsigned int v3; // esi

  if ( nObjects != this->nCount )
  {
    v3 = nObjects / 16;
    if ( 16 * (nObjects / 16) < nObjects )
      ++v3;
    if ( v3 != this->nBlocks )
    {
      if ( v3 > 0x21 )
        _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
      BlockArray<CSSEdge,16,32>::GetBlocks(this, nNewBlocks: v3);
    }
    this->nCount = nObjects;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A8FE0
// Name: public: void BlockArray<class CSSFace,16,10>::SetCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlockArray<CSSFace,16,10>::SetCount(BlockArray<CSSFace,16,10> *this, int nObjects)
{
  unsigned int v3; // esi

  if ( nObjects != this->nCount )
  {
    v3 = nObjects / 16;
    if ( 16 * (nObjects / 16) < nObjects )
      ++v3;
    if ( v3 != this->nBlocks )
    {
      if ( v3 > 0xB )
        _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 10);
      BlockArray<CSSFace,16,10>::GetBlocks(this, nNewBlocks: v3);
    }
    this->nCount = nObjects;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013F870
// Name: public: virtual char const __near * CMapSolid::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapSolid::GetType(CMapSolid *this)
{
  return CMapSolid::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x1013F880
// Name: public: virtual int CMapSolid::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapSolid::IsMapClass(CMapSolid *this, const char *Type)
{
  return Type == CMapSolid::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x1013F8A0
// Name: protected: void CMapSolid::PickRandomColor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSolid::PickRandomColor(CMapSolid *this)
{
  CMapSolid_vtbl *v2; // edi
  unsigned int v3; // eax
  int v4; // [esp-4h] [ebp-Ch]

  v2 = this->__vftable;
  v4 = (unsigned __int8)(random() % 0x9C + 100);
  v3 = random();
  v2->SetRenderColor_2(this, a2: 0, a3: v3 % 0x9C + 100, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1013F8E0
// Name: public: static void CMapSolid::PreloadWorld(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CMapSolid::PreloadWorld()
{
  CMapSolid::g_nBadSolidCount = 0;
  CMapSolid::g_nRecordedBadSolidCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013F8F0
// Name: public: static int CMapSolid::GetBadSolidCount(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CMapSolid::GetBadSolidCount()
{
  return CMapSolid::g_nBadSolidCount;
}

//------------------------------------------------------------------------------
// Address: 0x1013F900
// Name: public: static int CMapSolid::GetRecordedBadSolidCount(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CMapSolid::GetRecordedBadSolidCount()
{
  return CMapSolid::g_nRecordedBadSolidCount;
}

//------------------------------------------------------------------------------
// Address: 0x1013F910
// Name: public: static int CMapSolid::GetBadSolidId(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CMapSolid::GetBadSolidId(int i)
{
  if ( i < 0 || i >= CMapSolid::g_nRecordedBadSolidCount )
    return -1;
  else
    return CMapSolid::g_nRecordedBadSolidIds[i];
}

//------------------------------------------------------------------------------
// Address: 0x1013F930
// Name: public: virtual class CMapClass __near * CMapSolid::PrepareSelection(enum SelectMode_t)
// Source: json
//------------------------------------------------------------------------------
CMapSolid *__thiscall CMapSolid::PrepareSelection(CMapSolid *this, SelectMode_t eSelectMode)
{
  CMapClass *v3; // eax

  if ( eSelectMode == selectSolids
    || this->m_pParent == nullptr
    || IsWorldObject(pObject: this->m_pParent)
    || eSelectMode != selectGroups
    && __RTDynamicCast(
         inptr: this->m_pParent,
         VfDelta: 0,
         SrcType: &CMapAtom `RTTI Type Descriptor',
         TargetType: &CMapEntity `RTTI Type Descriptor',
         isReference: 0) == nullptr )
  {
    return this;
  }
  v3 = this->GetParent(this);
  return (CMapSolid *)v3->PrepareSelection(this: v3, a2: eSelectMode);
}

//------------------------------------------------------------------------------
// Address: 0x1013F9A0
// Name: public: enum HL1_SolidType_t CMapSolid::HL1SolidTypeFromTextureName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapSolid::HL1SolidTypeFromTextureName(CMapSolid *this, const char *pszTexture)
{
  if ( *pszTexture != 42 )
    return 0;
  if ( strncmp(first: pszTexture + 1, last: "slime", count: 5u) == 0 )
    return 2;
  return strncmp(first: pszTexture + 1, last: "lava", count: 4u) != 0 ? 1 : 3;
}

//------------------------------------------------------------------------------
// Address: 0x1013FA00
// Name: protected: virtual enum ChunkFileResult_t CMapSolid::SaveEditorData(class CChunkFile __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CMapSolid::SaveEditorData(CMapSolid *this, CChunkFile *pFile)
{
  if ( (*((_BYTE *)this + 568) & 2) != 0 )
    return CChunkFile::WriteKeyValueBool(this: pFile, pszKey: "cordonsolid", bValue: true);
  else
    return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x1013FA30
// Name: protected: struct color32_s CMapSolid::GetLineColor(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
color32_s __thiscall CMapSolid::GetLineColor(CMapSolid *this, CRender2D *pRender, CRender2D *pRendera)
{
  CMapClass *v4; // eax
  _DWORD *v5; // eax
  int v6; // eax
  char v8; // ah
  CRender2D_vtbl *clr; // [esp+4h] [ebp-4h]
  CRender2D_vtbl *clra; // [esp+4h] [ebp-4h]

  if ( this->IsSelected(this) )
  {
    v8 = BYTE1(Options.colors.clrSelection);
    LOBYTE(clr) = Options.colors.clrSelection;
    BYTE2(clr) = BYTE2(Options.colors.clrSelection);
LABEL_11:
    BYTE1(clr) = v8;
    HIBYTE(clr) = -1;
    pRender->__vftable = clr;
    return (color32_s)pRender;
  }
  v4 = this->GetParent(this);
  v5 = __RTDynamicCast(
         inptr: v4,
         VfDelta: 0,
         SrcType: &CMapClass `RTTI Type Descriptor',
         TargetType: &CMapEntity `RTTI Type Descriptor',
         isReference: 0);
  if ( v5 != nullptr )
  {
    v6 = v5[62];
    if ( v6 != 0 )
    {
      pRender->__vftable = *(CRender2D_vtbl **)(v6 + 4);
      return (color32_s)pRender;
    }
    v8 = BYTE1(Options.colors.clrEntity);
    LOBYTE(clr) = Options.colors.clrEntity;
    BYTE2(clr) = BYTE2(Options.colors.clrEntity);
    goto LABEL_11;
  }
  if ( Options.view2d.bUsegroupcolors != 0 )
  {
    ((void (__thiscall *)(CMapSolid *, CRender2D *))this->GetRenderColor)(a1: this, a2: pRender);
  }
  else
  {
    LOWORD(clra) = Options.colors.clrBrush;
    BYTE2(clra) = BYTE2(Options.colors.clrBrush);
    HIBYTE(clra) = -1;
    pRender->__vftable = clra;
  }
  return (color32_s)pRender;
}

//------------------------------------------------------------------------------
// Address: 0x1013FB10
// Name: public: virtual char const __near * CMapSolid::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapSolid::GetDescription(CMapSolid *this)
{
  sprintf(string: szBuf_1, format: "solid with %d faces", this->Faces.nCount);
  return szBuf_1;
}

//------------------------------------------------------------------------------
// Address: 0x1013FB30
// Name: public: BlockArray<class CMapFace,6,86>::~BlockArray<class CMapFace,6,86>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BlockArray<CMapFace,6,86>::~BlockArray<CMapFace,6,86>(BlockArray<CMapFace,6,86> *this)
{
  BlockArray<CMapFace,6,86>::GetBlocks(this, nNewBlocks: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1013FB40
// Name: public: CMapSolid::CMapSolid(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
CMapSolid *__thiscall CMapSolid::CMapSolid(CMapSolid *this, CMapClass *Parent0)
{
  CMapSolid_vtbl *v3; // edi
  unsigned int v4; // eax
  int v6; // [esp-4h] [ebp-1Ch]

  CMapClass::CMapClass(this);
  this->__vftable = (CMapSolid_vtbl *)&CMapSolid::`vftable';
  *(_DWORD *)&this->Faces.nCount = 0;
  *((_BYTE *)this + 568) &= 0xFCu;
  v3 = this->__vftable;
  this->m_pParent = Parent0;
  this->m_eSolidType = btSolid;
  v6 = (unsigned __int8)(random() % 0x9C + 100);
  v4 = random();
  v3->SetRenderColor_2(this, a2: 0, a3: v4 % 0x9C + 100, a4: v6);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013FBF0
// Name: public: virtual CMapSolid::~CMapSolid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSolid::~CMapSolid(CMapSolid *this)
{
  this->__vftable = (CMapSolid_vtbl *)&CMapSolid::`vftable';
  BlockArray<CMapFace,6,86>::SetCount(this: &this->Faces, nObjects: 0);
  BlockArray<CMapFace,6,86>::GetBlocks(this: &this->Faces, nNewBlocks: 0);
  CMapClass::~CMapClass(this);
}

//------------------------------------------------------------------------------
// Address: 0x1013FC60
// Name: public: virtual class CMapClass __near * CMapSolid::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapSolid *__thiscall CMapSolid::Copy(CMapSolid *this, BOOL bUpdateDependencies)
{
  CMapSolid *v3; // eax
  CMapSolid *v4; // esi

  v3 = (CMapSolid *)operator new(nSize: 0x240u);
  v4 = nullptr;
  if ( v3 != nullptr )
    v4 = CMapSolid::CMapSolid(this: v3, Parent0: nullptr);
  v4->CopyFrom(this: v4, a2: this, a3: bUpdateDependencies);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1013FCD0
// Name: class CMapClass __near * CMapSolid_CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapSolid *__cdecl CMapSolid_CreateObject()
{
  CMapSolid *v0; // eax

  v0 = (CMapSolid *)operator new(nSize: 0x240u);
  if ( v0 != nullptr )
    return CMapSolid::CMapSolid(this: v0, Parent0: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1013FDB0
// Name: public: class CMapFace __near * CMapSolid::FindFaceID(int)
// Source: json
//------------------------------------------------------------------------------
CMapFace *__thiscall CMapSolid::FindFaceID(CMapSolid *this, int nFaceID)
{
  const char *v2; // edi
  BlockArray<CMapFace,6,86> *p_Faces; // esi
  int v4; // ebx
  unsigned int v5; // esi
  CMapFace *result; // eax
  int nFaceCount; // [esp+10h] [ebp-8h]
  BlockArray<CMapFace,6,86> *v8; // [esp+14h] [ebp-4h]

  v2 = nullptr;
  nFaceCount = this->Faces.nCount;
  if ( nFaceCount <= 0 )
    return nullptr;
  p_Faces = &this->Faces;
  v8 = &this->Faces;
  while ( 1 )
  {
    if ( (int)v2 >= p_Faces->nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v2, p_Faces->nCount);
      v4 = (int)(v2 + 1);
      if ( v2 + 1 != (const char *)p_Faces->nCount )
      {
        v5 = v4 / 6;
        if ( 6 * (v4 / 6) < v4 )
          ++v5;
        if ( v5 != v8->nBlocks )
        {
          if ( v5 > 0x57 )
            _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
          BlockArray<CMapFace,6,86>::GetBlocks(this: v8, nNewBlocks: v5);
        }
        v8->nCount = v4;
        p_Faces = v8;
      }
    }
    result = &p_Faces->Blocks[(int)v2 / 6][(int)v2 % 6];
    if ( result->m_nFaceID == nFaceID )
      break;
    if ( (int)++v2 >= nFaceCount )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013FEA0
// Name: protected: void CMapSolid::GenerateNewFaceIDs(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSolid::GenerateNewFaceIDs(CMapSolid *this, CMapWorld *pWorld)
{
  int v2; // esi
  BlockArray<CMapFace,6,86> *p_Faces; // ebx
  int v4; // ecx
  unsigned int v5; // edi
  unsigned int v6; // eax
  int m_nNextFaceID; // ecx
  int nFaceCount; // [esp+8h] [ebp-4h]

  v2 = 0;
  nFaceCount = this->Faces.nCount;
  if ( nFaceCount > 0 )
  {
    p_Faces = &this->Faces;
    do
    {
      if ( v2 >= p_Faces->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v2, p_Faces->nCount);
        v4 = v2 + 1;
        if ( v2 + 1 != p_Faces->nCount )
        {
          v5 = v4 / 6;
          if ( 6 * (v4 / 6) < v4 )
            ++v5;
          if ( v5 != p_Faces->nBlocks )
          {
            if ( v5 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: p_Faces, nNewBlocks: v5);
          }
          p_Faces->nCount = v2 + 1;
        }
      }
      v6 = (unsigned int)&p_Faces->Blocks[v2 / 6u][v2 % 6u];
      m_nNextFaceID = pWorld->m_nNextFaceID;
      ++v2;
      pWorld->m_nNextFaceID = m_nNextFaceID + 1;
      *(_DWORD *)(v6 + 412) = m_nNextFaceID;
    }
    while ( v2 < nFaceCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013FF90
// Name: public: virtual void CMapSolid::OnPreClone(class CMapClass __near *,class CMapWorld __near *,class CUtlReferenceVector<class CMapClass> const __near &,class CUtlReferenceVector<class CMapClass> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSolid::OnPreClone(
        CMapSolid *this,
        CMapSolid *pClone,
        CMapWorld *pWorld,
        const CUtlReferenceVector<CMapClass> *OriginalList,
        CUtlReferenceVector<CMapClass> *NewList)
{
  CMapSolid::GenerateNewFaceIDs(this: pClone, pWorld);
}

//------------------------------------------------------------------------------
// Address: 0x1013FFB0
// Name: public: virtual void CMapSolid::OnPrePaste(class CMapClass __near *,class CMapWorld __near *,class CMapWorld __near *,class CUtlReferenceVector<class CMapClass> const __near &,class CUtlReferenceVector<class CMapClass> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSolid::OnPrePaste(
        CMapSolid *this,
        CMapSolid *pCopy,
        CMapWorld *pSourceWorld,
        CMapWorld *pDestWorld,
        const CUtlReferenceVector<CMapClass> *OriginalList,
        CUtlReferenceVector<CMapClass> *NewList)
{
  CMapSolid::GenerateNewFaceIDs(this: pCopy, pWorld: pDestWorld);
}

//------------------------------------------------------------------------------
// Address: 0x1013FFD0
// Name: public: int CMapSolid::GetFaceIndex(class CMapFace __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapSolid::GetFaceIndex(CMapSolid *this, CMapFace *pFace)
{
  const char *v2; // edi
  BlockArray<CMapFace,6,86> *p_Faces; // esi
  int v4; // ebx
  unsigned int v5; // esi
  CMapSolid *v7; // [esp+10h] [ebp-4h]

  v2 = nullptr;
  v7 = this;
  if ( this->Faces.nCount <= 0 )
    return -1;
  p_Faces = &this->Faces;
  while ( 1 )
  {
    if ( (int)v2 >= p_Faces->nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v2, p_Faces->nCount);
      v4 = (int)(v2 + 1);
      if ( v2 + 1 == (const char *)p_Faces->nCount )
      {
        this = v7;
      }
      else
      {
        v5 = v4 / 6;
        if ( 6 * (v4 / 6) < v4 )
          ++v5;
        if ( v5 != v7->Faces.nBlocks )
        {
          if ( v5 > 0x57 )
            _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
          BlockArray<CMapFace,6,86>::GetBlocks(this: &v7->Faces, nNewBlocks: v5);
        }
        v7->Faces.nCount = v4;
        this = v7;
      }
    }
    p_Faces = &this->Faces;
    if ( pFace == &this->Faces.Blocks[(int)v2 / 6][(int)v2 + -6 * ((int)v2 / 6)] )
      break;
    if ( (int)++v2 >= this->Faces.nCount )
      return -1;
  }
  return (int)v2;
}

//------------------------------------------------------------------------------
// Address: 0x101400E0
// Name: public: void CMapSolid::AddFace(class CMapFace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSolid::AddFace(CMapSolid *this, CMapFace *pFace)
{
  const char *nCount; // esi
  CMapFace *v4; // esi
  CMapFace_vtbl *v5; // edx

  nCount = (const char *)this->Faces.nCount;
  BlockArray<CMapFace,6,86>::SetCount(this: &this->Faces, nObjects: (int)(nCount + 1));
  if ( (int)nCount >= this->Faces.nCount )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: nCount, this->Faces.nCount);
    BlockArray<CMapFace,6,86>::SetCount(this: &this->Faces, nObjects: (int)(nCount + 1));
  }
  v4 = &this->Faces.Blocks[(int)nCount / 6][(int)nCount % 6];
  CMapFace::CopyFrom(this: v4, pObject: pFace, dwFlags: 2u, bUpdateDependencies: true);
  v4->SetRenderColor_2(this: v4, a2: this->r, a3: this->g, a4: this->b);
  v5 = v4->__vftable;
  *((_BYTE *)v4 + 432) ^= (*((_BYTE *)v4 + 432) ^ (*((_BYTE *)this + 568) >> 1)) & 1;
  v5->SetParent(this: v4, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x101401A0
// Name: public: virtual class CMapClass __near * CMapSolid::CopyFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapSolid *__thiscall CMapSolid::CopyFrom(CMapSolid *this, CMapClass *pobj, bool bUpdateDependencies)
{
  CMapSolid *v3; // ebx
  int v4; // edi
  int v5; // edi
  int v6; // esi
  unsigned int v7; // esi
  unsigned int v8; // esi
  CMapFace *v9; // ebx
  unsigned int v10; // edi
  CMapFace *v11; // ebx
  unsigned int v12; // eax
  const CMapFace *v13; // esi
  int v15; // [esp+Ch] [ebp-10h]
  const char *i; // [esp+14h] [ebp-8h]
  BlockArray<CMapFace,6,86> *v18; // [esp+18h] [ebp-4h]
  int pobja; // [esp+24h] [ebp+8h]

  v3 = this;
  CMapClass::CopyFrom(this, pFrom: (CVisGroup *)pobj, bUpdateDependencies);
  v3->m_eSolidType = (HL1_SolidType_t)pobj[2].m_Children.m_pElements;
  *((_BYTE *)v3 + 568) ^= (*((_BYTE *)v3 + 568) ^ LOBYTE(pobj[2].m_Children.m_Size)) & 2;
  v4 = *((__int16 *)&pobj[2].m_Children.m_Memory + 4);
  BlockArray<CMapFace,6,86>::SetCount(this: &v3->Faces, nObjects: v4);
  v5 = v4 - 1;
  i = (const char *)v5;
  if ( v5 < 0 )
    return v3;
  v18 = (BlockArray<CMapFace,6,86> *)&pobj[1];
  v6 = v5 + 1;
  for ( pobja = v5 + 1; ; v6 = pobja )
  {
    if ( v5 >= v3->Faces.nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v5, v3->Faces.nCount);
      if ( v6 != v3->Faces.nCount )
      {
        v7 = v6 / 6;
        if ( (int)(6 * v7) < pobja )
          ++v7;
        if ( v7 != v3->Faces.nBlocks )
        {
          if ( v7 > 0x57 )
            _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
          BlockArray<CMapFace,6,86>::GetBlocks(this: &v3->Faces, nNewBlocks: v7);
        }
        v3->Faces.nCount = pobja;
      }
    }
    v8 = v5 / 6u;
    v9 = v3->Faces.Blocks[v5 / 6u];
    v10 = v5 % 6u;
    v11 = &v9[v10];
    if ( (int)i >= v18->nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: i, v18->nCount);
      if ( pobja != v18->nCount )
      {
        v12 = pobja / 6;
        v15 = pobja / 6;
        if ( 6 * (pobja / 6) < pobja )
          v15 = ++v12;
        if ( v12 != v18->nBlocks )
        {
          if ( v12 > 0x57 )
          {
            _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            v12 = v15;
          }
          BlockArray<CMapFace,6,86>::GetBlocks(this: v18, nNewBlocks: v12);
        }
        v18->nCount = pobja;
      }
    }
    v13 = &v18->Blocks[v8][v10];
    if ( v11 != nullptr )
    {
      v11->SetParent(this: v11, a2: this);
      CMapFace::CopyFrom(this: v11, pObject: v13, dwFlags: 2u, bUpdateDependencies);
    }
    --pobja;
    if ( (int)--i < 0 )
      break;
    v5 = (int)i;
    v3 = this;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101403A0
// Name: public: void CMapSolid::DeleteFace(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSolid::DeleteFace(CMapSolid *this, const char *iIndex)
{
  int v2; // edi
  BlockArray<CMapFace,6,86> *p_Faces; // ebx
  int nCount; // eax
  int v5; // edi
  int v6; // ecx
  unsigned int v7; // esi
  unsigned int v8; // esi
  const char *v9; // ecx
  const CMapFace *v10; // edi
  __int16 v11; // ax
  BlockArray<CMapFace,6,86> *v12; // ebx
  unsigned int v13; // esi
  CMapSolid *v14; // [esp+Ch] [ebp-Ch]
  int v15; // [esp+10h] [ebp-8h]
  int v16; // [esp+14h] [ebp-4h]

  v2 = this->Faces.nCount - 1;
  v14 = this;
  v15 = v2;
  if ( (int)iIndex < v2 )
  {
    p_Faces = &this->Faces;
    do
    {
      nCount = p_Faces->nCount;
      v5 = (int)(iIndex + 1);
      v16 = (int)(iIndex + 1);
      if ( (int)(iIndex + 1) >= nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: iIndex + 1, nCount);
        v6 = (int)(iIndex + 2);
        if ( iIndex + 2 != (const char *)p_Faces->nCount )
        {
          v7 = v6 / 6;
          if ( 6 * (v6 / 6) < v6 )
            ++v7;
          if ( v7 != p_Faces->nBlocks )
          {
            if ( v7 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: p_Faces, nNewBlocks: v7);
          }
          p_Faces->nCount = (_WORD)iIndex + 2;
        }
      }
      v8 = v5 / 6;
      v9 = iIndex;
      v10 = &p_Faces->Blocks[v5 / 6][v5 % 6];
      if ( (int)iIndex >= p_Faces->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: iIndex, p_Faces->nCount);
        v11 = (_WORD)iIndex + 1;
        if ( v16 != p_Faces->nCount )
        {
          if ( (int)(6 * v8) < v16 )
            ++v8;
          if ( v8 != p_Faces->nBlocks )
          {
            if ( v8 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: p_Faces, nNewBlocks: v8);
            v11 = (_WORD)iIndex + 1;
          }
          p_Faces->nCount = v11;
        }
        v9 = iIndex;
      }
      CMapFace::CopyFrom(
        this: &p_Faces->Blocks[(int)v9 / 6][(int)v9 % 6],
        pObject: v10,
        dwFlags: 2u,
        bUpdateDependencies: true);
      ++iIndex;
    }
    while ( v16 < v15 );
    this = v14;
    v2 = v15;
  }
  v12 = &this->Faces;
  if ( v2 != this->Faces.nCount )
  {
    v13 = v2 / 6;
    if ( 6 * (v2 / 6) < v2 )
      ++v13;
    if ( v13 != this->Faces.nBlocks )
    {
      if ( v13 > 0x57 )
        _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
      BlockArray<CMapFace,6,86>::GetBlocks(this: v12, nNewBlocks: v13);
    }
    v12->nCount = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10140580
// Name: public: virtual void CMapSolid::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSolid::CalcBounds(CMapSolid *this, int bFullUpdate)
{
  CMapSolid *v2; // esi
  unsigned int v3; // edi
  BlockArray<CMapFace,6,86> *p_Faces; // esi
  int v5; // ecx
  unsigned int v6; // ebx
  unsigned int v7; // ebx
  unsigned int v8; // eax
  bool v9; // zf
  int v10; // ecx
  unsigned int v11; // ebx
  int v12; // ecx
  unsigned int v13; // ebx
  Vector mins; // [esp+8h] [ebp-24h] BYREF
  Vector maxs; // [esp+14h] [ebp-18h] BYREF
  int nFaces; // [esp+20h] [ebp-Ch]
  unsigned int v17; // [esp+24h] [ebp-8h]
  CMapSolid *v18; // [esp+28h] [ebp-4h]

  v2 = this;
  v18 = this;
  CMapClass::CalcBounds(this, bFullUpdate);
  v3 = 0;
  nFaces = v2->Faces.nCount;
  if ( nFaces > 0 )
  {
    p_Faces = &v2->Faces;
    do
    {
      if ( (int)v3 >= p_Faces->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v3, p_Faces->nCount);
        v5 = v3 + 1;
        if ( v3 + 1 != p_Faces->nCount )
        {
          v6 = v5 / 6;
          if ( 6 * (v5 / 6) < v5 )
            ++v6;
          if ( v6 != p_Faces->nBlocks )
          {
            if ( v6 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: p_Faces, nNewBlocks: v6);
          }
          p_Faces->nCount = v3 + 1;
        }
      }
      v7 = v3 / 6;
      v8 = v3 % 6;
      v9 = p_Faces->Blocks[v3 / 6][v8].Points == nullptr;
      v17 = v3 / 6;
      if ( !v9 )
      {
        if ( (int)v3 >= p_Faces->nCount )
        {
          _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v3, p_Faces->nCount);
          v10 = v3 + 1;
          if ( v3 + 1 != p_Faces->nCount )
          {
            v11 = v10 / 6;
            if ( 6 * (v10 / 6) < v10 )
              ++v11;
            if ( v11 != p_Faces->nBlocks )
            {
              if ( v11 > 0x57 )
                _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
              BlockArray<CMapFace,6,86>::GetBlocks(this: p_Faces, nNewBlocks: v11);
            }
            v7 = v17;
            p_Faces->nCount = v3 + 1;
          }
          v8 = v3 % 6;
        }
        if ( CMapFace::GetRender2DBox(this: &p_Faces->Blocks[v7][v8], boundMin: &mins, boundMax: &maxs) )
          BoundBox::UpdateBounds(this: &v18->m_Render2DBox, &mins, &maxs);
        if ( (int)v3 >= p_Faces->nCount )
        {
          _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v3, p_Faces->nCount);
          v12 = v3 + 1;
          if ( v3 + 1 != p_Faces->nCount )
          {
            v13 = v12 / 6;
            if ( 6 * (v12 / 6) < v12 )
              ++v13;
            if ( v13 != p_Faces->nBlocks )
            {
              if ( v13 > 0x57 )
                _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
              BlockArray<CMapFace,6,86>::GetBlocks(this: p_Faces, nNewBlocks: v13);
            }
            v7 = v17;
            p_Faces->nCount = v3 + 1;
          }
        }
        if ( CMapFace::GetCullBox(this: &p_Faces->Blocks[v7][v3 % 6], boundMin: &mins, boundMax: &maxs) )
          BoundBox::UpdateBounds(this: &v18->m_CullBox, &mins, &maxs);
      }
      ++v3;
    }
    while ( (int)v3 < nFaces );
    v2 = v18;
  }
  BoundBox::GetBoundsCenter(this: &v2->m_Render2DBox, ptdest: &v2->m_Origin);
  v2->m_BoundingBox.bmins.x = v2->m_CullBox.bmins.x;
  v2->m_BoundingBox.bmins.y = v2->m_CullBox.bmins.y;
  v2->m_BoundingBox.bmins.z = v2->m_CullBox.bmins.z;
  v2->m_BoundingBox.bmaxs.x = v2->m_CullBox.bmaxs.x;
  v2->m_BoundingBox.bmaxs.y = v2->m_CullBox.bmaxs.y;
  v2->m_BoundingBox.bmaxs.z = v2->m_CullBox.bmaxs.z;
}

//------------------------------------------------------------------------------
// Address: 0x101407F0
// Name: protected: virtual void CMapSolid::DoTransform(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSolid::DoTransform(CMapSolid *this, const VMatrix *matrix)
{
  CMapSolid *v2; // ebx
  int v3; // esi
  BlockArray<CMapFace,6,86> *p_Faces; // edi
  int v5; // ebx
  unsigned int v6; // edi
  CMapFace *v7; // edx
  int nFaces; // [esp+Ch] [ebp-8h]

  v2 = this;
  v3 = 0;
  nFaces = this->Faces.nCount;
  if ( nFaces > 0 )
  {
    p_Faces = &this->Faces;
    do
    {
      if ( v3 >= p_Faces->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v3, p_Faces->nCount);
        v5 = v3 + 1;
        if ( v3 + 1 == p_Faces->nCount )
        {
          v2 = this;
        }
        else
        {
          v6 = v5 / 6;
          if ( 6 * (v5 / 6) < v5 )
            ++v6;
          if ( v6 != this->Faces.nBlocks )
          {
            if ( v6 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: &this->Faces, nNewBlocks: v6);
          }
          this->Faces.nCount = v5;
          v2 = this;
        }
      }
      v7 = v2->Faces.Blocks[v3 / 6u];
      p_Faces = &v2->Faces;
      v7[v3 % 6u].DoTransform(this: &v7[v3 % 6u], a2: matrix);
      ++v3;
    }
    while ( v3 < nFaces );
  }
  CMapClass::DoTransform(this: v2, matrix);
}

//------------------------------------------------------------------------------
// Address: 0x10140900
// Name: public: virtual void CMapSolid::SetRenderColor(struct color32_s)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSolid::SetRenderColor(CMapSolid *this, color32_s rgbColor)
{
  int v3; // esi
  BlockArray<CMapFace,6,86> *p_Faces; // edi
  int v5; // ebx
  unsigned int v6; // edi
  int nFaces; // [esp+Ch] [ebp-8h]
  BlockArray<CMapFace,6,86> *v8; // [esp+10h] [ebp-4h]

  CMapClass::SetRenderColor(this, rgbColor);
  v3 = 0;
  nFaces = this->Faces.nCount;
  if ( nFaces > 0 )
  {
    p_Faces = &this->Faces;
    v8 = p_Faces;
    do
    {
      if ( v3 >= p_Faces->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v3, p_Faces->nCount);
        v5 = v3 + 1;
        if ( v3 + 1 != p_Faces->nCount )
        {
          v6 = v5 / 6;
          if ( 6 * (v5 / 6) < v5 )
            ++v6;
          if ( v6 != v8->nBlocks )
          {
            if ( v6 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: v8, nNewBlocks: v6);
          }
          v8->nCount = v5;
          p_Faces = v8;
        }
      }
      p_Faces->Blocks[v3 / 6u][v3 % 6u].SetRenderColor(this: &p_Faces->Blocks[v3 / 6u][v3 % 6u], a2: rgbColor);
      ++v3;
    }
    while ( v3 < nFaces );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101409F0
// Name: public: virtual void CMapSolid::SetRenderColor(unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSolid::SetRenderColor(CMapSolid *this, int uchRed, int uchGreen, int uchBlue)
{
  int nCount; // edi
  int v6; // esi
  int v7; // ecx
  unsigned int v8; // edi
  CMapFace *v9; // ecx
  int nFaces; // [esp+10h] [ebp-4h]

  CMapClass::SetRenderColor(this, uchRed, uchGreen, uchBlue);
  nCount = this->Faces.nCount;
  v6 = 0;
  for ( nFaces = nCount; v6 < nCount; ++v6 )
  {
    if ( v6 >= this->Faces.nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v6, this->Faces.nCount);
      v7 = v6 + 1;
      if ( v6 + 1 != this->Faces.nCount )
      {
        v8 = v7 / 6;
        if ( 6 * (v7 / 6) < v7 )
          ++v8;
        if ( v8 != this->Faces.nBlocks )
        {
          if ( v8 > 0x57 )
            _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
          BlockArray<CMapFace,6,86>::GetBlocks(this: &this->Faces, nNewBlocks: v8);
        }
        nCount = nFaces;
        this->Faces.nCount = v6 + 1;
      }
    }
    v9 = this->Faces.Blocks[v6 / 6u];
    v9[v6 % 6u].SetRenderColor_2(this: &v9[v6 % 6u], a2: uchRed, a3: uchGreen, a4: uchBlue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10140AF0
// Name: public: virtual unsigned int CMapSolid::GetSize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CMapSolid::GetSize(CMapSolid *this)
{
  unsigned int v2; // edi
  const char *v3; // esi
  int v4; // ecx
  unsigned int v5; // edi
  unsigned int DataSize; // eax
  int nFaces; // [esp+10h] [ebp-8h]
  unsigned int size; // [esp+14h] [ebp-4h]

  v2 = CMapClass::GetSize(this) + 576;
  v3 = nullptr;
  size = v2;
  nFaces = this->Faces.nCount;
  if ( nFaces > 0 )
  {
    do
    {
      if ( (int)v3 >= this->Faces.nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v3, this->Faces.nCount);
        v4 = (int)(v3 + 1);
        if ( v3 + 1 != (const char *)this->Faces.nCount )
        {
          v5 = v4 / 6;
          if ( 6 * (v4 / 6) < v4 )
            ++v5;
          if ( v5 != this->Faces.nBlocks )
          {
            if ( v5 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: &this->Faces, nNewBlocks: v5);
          }
          v2 = size;
          this->Faces.nCount = (_WORD)v3 + 1;
        }
      }
      DataSize = CMapFace::GetDataSize(this: &this->Faces.Blocks[(int)v3 / 6][(int)v3 % 6]);
      ++v3;
      v2 += DataSize;
      size = v2;
    }
    while ( (int)v3 < nFaces );
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10140BF0
// Name: public: void CMapSolid::SetTexture(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSolid::SetTexture(CMapSolid *this, const char *pszTex, int iFace)
{
  CMapSolid *v3; // ebx
  int nCount; // eax
  int v5; // esi
  BlockArray<CMapFace,6,86> *p_Faces; // edi
  int v7; // ebx
  unsigned int v8; // edi
  CMapDoc *v9; // esi
  int nFaces; // [esp+20h] [ebp+Ch]

  v3 = this;
  nCount = this->Faces.nCount;
  if ( iFace == -1 )
  {
    v5 = 0;
    nFaces = this->Faces.nCount;
    if ( nCount > 0 )
    {
      p_Faces = &this->Faces;
      do
      {
        if ( v5 >= p_Faces->nCount )
        {
          _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v5, p_Faces->nCount);
          v7 = v5 + 1;
          if ( v5 + 1 == p_Faces->nCount )
          {
            v3 = this;
          }
          else
          {
            v8 = v7 / 6;
            if ( 6 * (v7 / 6) < v7 )
              ++v8;
            if ( v8 != this->Faces.nBlocks )
            {
              if ( v8 > 0x57 )
                _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
              BlockArray<CMapFace,6,86>::GetBlocks(this: &this->Faces, nNewBlocks: v8);
            }
            this->Faces.nCount = v7;
            v3 = this;
          }
        }
        p_Faces = &v3->Faces;
        CMapFace::SetTexture(
          this: &v3->Faces.Blocks[v5 / 6u][v5 % 6u],
          pszNewTex: pszTex,
          bRescaleTextureCoordinates: false);
        ++v5;
      }
      while ( v5 < nFaces );
    }
  }
  else
  {
    if ( iFace >= nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)iFace, nCount);
      BlockArray<CMapFace,6,86>::SetCount(this: &v3->Faces, nObjects: iFace + 1);
    }
    CMapFace::SetTexture(
      this: &v3->Faces.Blocks[iFace / 6][iFace % 6],
      pszNewTex: pszTex,
      bRescaleTextureCoordinates: false);
  }
  v9 = CMapDoc::m_pMapDoc;
  CMapDoc::RemoveFromAutoVisGroups(this: CMapDoc::m_pMapDoc, pObject: v3);
  CMapDoc::AddToAutoVisGroup(this: v9, pObject: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10140D60
// Name: public: void CMapSolid::InitializeTextureAxes(enum TextureAlignment_t,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSolid::InitializeTextureAxes(CMapSolid *this, TextureAlignment_t eAlignment, unsigned int dwFlags)
{
  int v3; // esi
  BlockArray<CMapFace,6,86> *p_Faces; // edi
  int v5; // ebx
  unsigned int v6; // edi
  int nFaces; // [esp+8h] [ebp-8h]
  BlockArray<CMapFace,6,86> *v8; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nFaces = this->Faces.nCount;
  if ( nFaces > 0 )
  {
    p_Faces = &this->Faces;
    v8 = &this->Faces;
    do
    {
      if ( v3 >= p_Faces->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v3, p_Faces->nCount);
        v5 = v3 + 1;
        if ( v3 + 1 != p_Faces->nCount )
        {
          v6 = v5 / 6;
          if ( 6 * (v5 / 6) < v5 )
            ++v6;
          if ( v6 != v8->nBlocks )
          {
            if ( v6 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: v8, nNewBlocks: v6);
          }
          v8->nCount = v5;
          p_Faces = v8;
        }
      }
      CMapFace::InitializeTextureAxes(this: &p_Faces->Blocks[v3 / 6u][v3 % 6u], eAlignment, dwFlags);
      ++v3;
    }
    while ( v3 < nFaces );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10140E50
// Name: protected: static enum ChunkFileResult_t CMapSolid::LoadSideCallback(class CChunkFile __near *,class CMapSolid __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CMapSolid::LoadSideCallback(CChunkFile *pFile, CMapSolid *pSolid)
{
  const char *nCount; // esi
  CMapFace *v3; // esi

  nCount = (const char *)pSolid->Faces.nCount;
  BlockArray<CMapFace,6,86>::SetCount(this: &pSolid->Faces, nObjects: (int)(nCount + 1));
  if ( (int)nCount >= pSolid->Faces.nCount )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: nCount, pSolid->Faces.nCount);
    BlockArray<CMapFace,6,86>::SetCount(this: &pSolid->Faces, nObjects: (int)(nCount + 1));
  }
  v3 = &pSolid->Faces.Blocks[(int)nCount / 6][(int)nCount % 6];
  if ( CMapFace::LoadVMF(this: v3, pFile) != ChunkFile_Ok )
  {
    AfxMessageBox(lpszText: "Out of memory loading solid.", nType: 0, nIDHelp: 0);
    return 7;
  }
  else
  {
    v3->SetRenderColor_2(this: v3, a2: pSolid->r, a3: pSolid->g, a4: pSolid->b);
    v3->SetParent(this: v3, a2: pSolid);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10140F10
// Name: public: virtual void CMapSolid::PostloadWorld(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSolid::PostloadWorld(CMapSolid *this, CMapWorld *pWorld)
{
  int v3; // edi
  BlockArray<CMapFace,6,86> *p_Faces; // esi
  int v5; // ebx
  unsigned int v6; // esi
  unsigned int v7; // eax
  int m_nNextFaceID; // ecx
  int nFaces; // [esp+Ch] [ebp-8h]
  BlockArray<CMapFace,6,86> *v10; // [esp+10h] [ebp-4h]

  CMapClass::PostloadWorld(this, pWorld);
  v3 = 0;
  nFaces = this->Faces.nCount;
  if ( nFaces > 0 )
  {
    p_Faces = &this->Faces;
    v10 = p_Faces;
    do
    {
      if ( v3 >= p_Faces->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v3, p_Faces->nCount);
        v5 = v3 + 1;
        if ( v3 + 1 != p_Faces->nCount )
        {
          v6 = v5 / 6;
          if ( 6 * (v5 / 6) < v5 )
            ++v6;
          if ( v6 != v10->nBlocks )
          {
            if ( v6 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: v10, nNewBlocks: v6);
          }
          v10->nCount = v5;
          p_Faces = v10;
        }
      }
      v7 = (unsigned int)&p_Faces->Blocks[v3 / 6u][v3 % 6u];
      if ( *(_DWORD *)(v7 + 412) == 0 )
      {
        m_nNextFaceID = pWorld->m_nNextFaceID;
        pWorld->m_nNextFaceID = m_nNextFaceID + 1;
        *(_DWORD *)(v7 + 412) = m_nNextFaceID;
      }
      ++v3;
    }
    while ( v3 < nFaces );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10141010
// Name: public: virtual void CMapSolid::OnRemoveFromWorld(class CMapWorld __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSolid::OnRemoveFromWorld(CMapSolid *this, CMapWorld *pWorld, bool bNotifyChildren)
{
  int v4; // esi
  BlockArray<CMapFace,6,86> *p_Faces; // edi
  int v6; // ebx
  unsigned int v7; // edi
  int nFaces; // [esp+14h] [ebp+8h]
  BlockArray<CMapFace,6,86> *bNotifyChildrena; // [esp+18h] [ebp+Ch]

  CMapClass::OnRemoveFromWorld(this, pWorld, bNotifyChildren);
  v4 = 0;
  nFaces = this->Faces.nCount;
  if ( nFaces > 0 )
  {
    p_Faces = &this->Faces;
    bNotifyChildrena = p_Faces;
    do
    {
      if ( v4 >= p_Faces->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v4, p_Faces->nCount);
        v6 = v4 + 1;
        if ( v4 + 1 != p_Faces->nCount )
        {
          v7 = v6 / 6;
          if ( 6 * (v6 / 6) < v6 )
            ++v7;
          if ( v7 != bNotifyChildrena->nBlocks )
          {
            if ( v7 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: bNotifyChildrena, nNewBlocks: v7);
          }
          bNotifyChildrena->nCount = v6;
          p_Faces = bNotifyChildrena;
        }
      }
      CMapFace::OnRemoveFromWorld(this: &p_Faces->Blocks[v4 / 6u][v4 % 6u]);
      ++v4;
    }
    while ( v4 < nFaces );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10141100
// Name: protected: void CMapSolid::RemoveEmptyFaces(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSolid::RemoveEmptyFaces(CMapSolid *this)
{
  int nCount; // edx
  const char *v2; // esi
  BlockArray<CMapFace,6,86> *p_Faces; // edi
  int v4; // ebx
  unsigned int v5; // edi
  BlockArray<CMapFace,6,86> *v6; // edi
  unsigned int v7; // esi
  int nFaces; // [esp+Ch] [ebp-8h]
  CMapSolid *v9; // [esp+10h] [ebp-4h]

  nCount = this->Faces.nCount;
  v2 = nullptr;
  v9 = this;
  nFaces = nCount;
  if ( nCount > 0 )
  {
    p_Faces = &this->Faces;
    v4 = 1;
    do
    {
      if ( (int)v2 >= p_Faces->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v2, p_Faces->nCount);
        if ( v4 == p_Faces->nCount )
        {
          this = v9;
        }
        else
        {
          v5 = v4 / 6;
          if ( 6 * (v4 / 6) < v4 )
            ++v5;
          if ( v5 != v9->Faces.nBlocks )
          {
            if ( v5 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: &v9->Faces, nNewBlocks: v5);
          }
          v9->Faces.nCount = v4;
          this = v9;
        }
      }
      p_Faces = &this->Faces;
      if ( this->Faces.Blocks[(int)v2 / 6][(int)v2 % 6].Points == nullptr )
      {
        CMapSolid::DeleteFace(this, iIndex: v2);
        this = v9;
        --v2;
        --v4;
        --nFaces;
      }
      ++v2;
      ++v4;
    }
    while ( (int)v2 < nFaces );
    nCount = nFaces;
  }
  if ( nCount >= 4 )
  {
    v6 = &this->Faces;
    if ( nCount != this->Faces.nCount )
    {
      v7 = nCount / 6;
      if ( 6 * (nCount / 6) < nFaces )
        ++v7;
      if ( v7 != this->Faces.nBlocks )
      {
        if ( v7 > 0x57 )
          _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
        BlockArray<CMapFace,6,86>::GetBlocks(this: v6, nNewBlocks: v7);
      }
      v6->nCount = nFaces;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10141280
// Name: public: virtual bool CMapSolid::ShouldRenderLast(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapSolid::ShouldRenderLast(CMapSolid *this)
{
  CMapSolid *v1; // ebx
  const char *v2; // edi
  BlockArray<CMapFace,6,86> *p_Faces; // esi
  int v4; // ebx
  unsigned int v5; // esi
  int v6; // ecx

  v1 = this;
  v2 = nullptr;
  if ( this->Faces.nCount <= 0 )
    return 0;
  p_Faces = &this->Faces;
  while ( 1 )
  {
    if ( (int)v2 >= p_Faces->nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v2, p_Faces->nCount);
      v4 = (int)(v2 + 1);
      if ( v2 + 1 == (const char *)p_Faces->nCount )
      {
        v1 = this;
      }
      else
      {
        v5 = v4 / 6;
        if ( 6 * (v4 / 6) < v4 )
          ++v5;
        if ( v5 != this->Faces.nBlocks )
        {
          if ( v5 > 0x57 )
            _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
          BlockArray<CMapFace,6,86>::GetBlocks(this: &this->Faces, nNewBlocks: v5);
        }
        this->Faces.nCount = v4;
        v1 = this;
      }
    }
    v6 = (int)&v1->Faces.Blocks[(int)v2 / 6][(int)v2 % 6];
    p_Faces = &v1->Faces;
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 68))(a1: v6) != 0 )
      break;
    if ( (int)++v2 >= v1->Faces.nCount )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10141390
// Name: public: virtual void CMapSolid::AddShadowingTriangles(class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSolid::AddShadowingTriangles(CMapSolid *this, CUtlVector<Vector,CUtlMemory<Vector,int> > *tri_list)
{
  const char *v2; // edi
  BlockArray<CMapFace,6,86> *p_Faces; // esi
  int v4; // ebx
  unsigned int v5; // esi
  unsigned __int16 *v6; // esi
  int v7; // esi
  CEditDispMgr *v8; // eax
  int v9; // eax
  CMapSolid *i; // [esp+8h] [ebp-4h]

  v2 = nullptr;
  for ( i = this; (int)v2 < i->Faces.nCount; ++v2 )
  {
    p_Faces = &this->Faces;
    if ( (int)v2 >= this->Faces.nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v2, this->Faces.nCount);
      v4 = (int)(v2 + 1);
      if ( v2 + 1 != (const char *)p_Faces->nCount )
      {
        v5 = v4 / 6;
        if ( 6 * (v4 / 6) < v4 )
          ++v5;
        if ( v5 != i->Faces.nBlocks )
        {
          if ( v5 > 0x57 )
            _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
          BlockArray<CMapFace,6,86>::GetBlocks(this: &i->Faces, nNewBlocks: v5);
        }
        i->Faces.nCount = v4;
      }
    }
    v6 = (unsigned __int16 *)&i->Faces.Blocks[(int)v2 / 6][(int)v2 % 6];
    (*(void (__thiscall **)(unsigned __int16 *, CUtlVector<Vector,CUtlMemory<Vector,int> > *))(*(_DWORD *)v6 + 52))(
      a1: v6,
      a2: tri_list);
    if ( v6[210] != 0xFFFF )
    {
      v7 = v6[210];
      v8 = EditDispMgr();
      v9 = (int)v8->GetDisp(this: v8, a2: v7);
      (*(void (__thiscall **)(int, CUtlVector<Vector,CUtlMemory<Vector,int> > *))(*(_DWORD *)v9 + 52))(
        a1: v9,
        a2: tri_list);
    }
    this = i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101414C0
// Name: public: bool CMapSolid::HasDisp(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapSolid::HasDisp(CMapSolid *this)
{
  const char *v1; // edi
  BlockArray<CMapFace,6,86> *p_Faces; // esi
  int v3; // ebx
  unsigned int v4; // esi
  CMapSolid *v6; // [esp+10h] [ebp-4h]

  v1 = nullptr;
  v6 = this;
  if ( this->Faces.nCount <= 0 )
    return 0;
  p_Faces = &this->Faces;
  while ( 1 )
  {
    if ( (int)v1 >= p_Faces->nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v1, p_Faces->nCount);
      v3 = (int)(v1 + 1);
      if ( v1 + 1 == (const char *)p_Faces->nCount )
      {
        this = v6;
      }
      else
      {
        v4 = v3 / 6;
        if ( 6 * (v3 / 6) < v3 )
          ++v4;
        if ( v4 != v6->Faces.nBlocks )
        {
          if ( v4 > 0x57 )
            _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
          BlockArray<CMapFace,6,86>::GetBlocks(this: &v6->Faces, nNewBlocks: v4);
        }
        v6->Faces.nCount = v3;
        this = v6;
      }
    }
    p_Faces = &this->Faces;
    if ( this->Faces.Blocks[(int)v1 / 6][(int)v1 % 6].m_DispHandle != 0xFFFF )
      break;
    if ( (int)++v1 >= this->Faces.nCount )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101415D0
// Name: public: virtual enum ChunkFileResult_t CMapSolid::SaveVMF(class CChunkFile __near *,class CSaveInfo __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CMapSolid::SaveVMF(CMapSolid *this, CChunkFile *pFile, CSaveInfo *pSaveInfo)
{
  ChunkFileResult_t result; // eax
  int v6; // esi
  int nFaceCount; // [esp+10h] [ebp+8h]

  if ( !CSaveInfo::ShouldSaveObject(this: pSaveInfo, pObject: this) )
    return ChunkFile_Ok;
  if ( (*((_BYTE *)&this->CMapClass + 180) & 2) != 0
    || (result = CChunkFile::BeginChunk(this: pFile, pszChunkName: "hidden")) == ChunkFile_Ok )
  {
    result = CChunkFile::BeginChunk(this: pFile, pszChunkName: "solid");
    if ( result == ChunkFile_Ok )
    {
      result = CChunkFile::WriteKeyValueInt(this: pFile, pszKey: "id", nValue: this->m_nID);
      v6 = 0;
      nFaceCount = this->Faces.nCount;
      if ( nFaceCount <= 0 )
      {
        if ( result == ChunkFile_Ok )
        {
LABEL_13:
          result = CMapClass::SaveVMF(this, pFile, pSaveInfo);
          if ( result == ChunkFile_Ok )
            result = CChunkFile::EndChunk(this: pFile);
        }
      }
      else
      {
        while ( 1 )
        {
          if ( v6 >= this->Faces.nCount )
          {
            _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v6, this->Faces.nCount);
            BlockArray<CMapFace,6,86>::SetCount(this: &this->Faces, nObjects: v6 + 1);
          }
          result = CMapFace::SaveVMF(this: &this->Faces.Blocks[v6 / 6u][v6 % 6u], pFile, pSaveInfo);
          if ( result != ChunkFile_Ok )
            break;
          if ( ++v6 >= nFaceCount )
            goto LABEL_13;
        }
      }
    }
  }
  if ( (*((_BYTE *)&this->CMapClass + 180) & 2) == 0 )
    return CChunkFile::EndChunk(this: pFile);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101416F0
// Name: public: void CMapSolid::SetCordonBrush(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSolid::SetCordonBrush(CMapSolid *this, bool bSet)
{
  const char *v2; // esi
  BlockArray<CMapFace,6,86> *p_Faces; // ebx
  int v4; // ecx
  unsigned int v5; // edi
  int v6; // eax

  *((_BYTE *)this + 568) = *((_BYTE *)this + 568) & 0xFD | (2 * bSet);
  v2 = nullptr;
  if ( this->Faces.nCount > 0 )
  {
    p_Faces = &this->Faces;
    do
    {
      if ( (int)v2 >= p_Faces->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v2, p_Faces->nCount);
        v4 = (int)(v2 + 1);
        if ( v2 + 1 != (const char *)p_Faces->nCount )
        {
          v5 = v4 / 6;
          if ( 6 * (v4 / 6) < v4 )
            ++v5;
          if ( v5 != p_Faces->nBlocks )
          {
            if ( v5 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: p_Faces, nNewBlocks: v5);
          }
          p_Faces->nCount = (_WORD)v2 + 1;
        }
      }
      v6 = (int)&p_Faces->Blocks[(int)v2 / 6][(int)v2 % 6];
      ++v2;
      *(_BYTE *)(v6 + 432) = bSet | *(_BYTE *)(v6 + 432) & 0xFE;
    }
    while ( (int)v2 < this->Faces.nCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10141800
// Name: public: virtual void CMapSolid::Render2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSolid::Render2D(CMapSolid *this, CRender2D *pRender)
{
  CRender2D *v2; // edi
  CCamera *Camera; // eax
  int v4; // esi
  int v5; // ebx
  CMapSolid *v6; // esi
  char v7; // bl
  int nCount; // eax
  int v9; // esi
  CMapSolid *v10; // ebx
  int v11; // ecx
  unsigned int v12; // edi
  unsigned int v13; // ecx
  int v14; // esi
  CMapSolid *v15; // ebx
  int v16; // ecx
  unsigned int v17; // edi
  Vector vViewNormal; // [esp+Ch] [ebp-58h] BYREF
  Vector vCenter; // [esp+18h] [ebp-4Ch] BYREF
  Vector vecMins; // [esp+24h] [ebp-40h] BYREF
  Vector vecMaxs; // [esp+30h] [ebp-34h] BYREF
  Vector2D pt; // [esp+3Ch] [ebp-28h] BYREF
  Vector2D pt2; // [esp+44h] [ebp-20h] BYREF
  color32_s rgbLineColor; // [esp+4Ch] [ebp-18h] BYREF
  int v25; // [esp+54h] [ebp-10h]
  int nFaces; // [esp+58h] [ebp-Ch]
  CMapSolid *v27; // [esp+5Ch] [ebp-8h]
  bool bPop; // [esp+62h] [ebp-2h]
  bool bIsTiny; // [esp+63h] [ebp-1h]

  v27 = this;
  CMapClass::GetRender2DBox(this, mins: &vecMins, maxs: &vecMaxs);
  v2 = pRender;
  Camera = CRender::GetCamera(this: pRender);
  CCamera::GetViewForward(this: Camera, ViewForward: &vViewNormal);
  CRender::TransformPoint(this: pRender, vClient: &pt, vWorld: &vecMins);
  CRender::TransformPoint(this: pRender, vClient: &pt2, vWorld: &vecMaxs);
  v4 = (int)(float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(pt2.x - pt.x) & _mask__AbsFloat_) + 1.0);
  v5 = (int)(float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(pt2.y - pt.y) & _mask__AbsFloat_) + 1.0);
  CMapSolid::GetLineColor(this: v27, pRender: (CRender2D *)&rgbLineColor, pRendera: pRender);
  if ( v4 < 8 || (bPop = false, v5 < 8) )
    bPop = true;
  if ( v4 < 2 || (bIsTiny = false, v5 < 2) )
    bIsTiny = true;
  if ( !CRender::IsActiveView(this: pRender) || bPop )
  {
    v6 = v27;
    goto LABEL_12;
  }
  v6 = v27;
  if ( !v27->IsEditable(this: v27) )
  {
LABEL_12:
    v7 = 0;
    goto LABEL_13;
  }
  v7 = 1;
LABEL_13:
  if ( Options.view2d.bDrawVertices == 0 || (bPop = true, bIsTiny) )
    bPop = false;
  CRender::SetDrawColor(this: pRender, r: rgbLineColor.r, g: rgbLineColor.g, b: rgbLineColor.b);
  if ( v7 != 0 )
  {
    CRender::SetHandleStyle(this: pRender, size: 4, type: 4);
    CRender::SetHandleColor(this: pRender, r: rgbLineColor.r, g: rgbLineColor.g, b: rgbLineColor.b);
    vCenter.x = (float)(vecMaxs.x + vecMins.x) * 0.5;
    vCenter.y = (float)(vecMins.y + vecMaxs.y) * 0.5;
    vCenter.z = (float)(vecMaxs.z + vecMins.z) * 0.5;
    CRender::DrawHandle(this: pRender, &vCenter, vOffset: nullptr);
  }
  if ( bPop )
  {
    CRender::SetHandleStyle(this: pRender, size: 2, type: 1);
    CRender::SetHandleColor(
      this: pRender,
      r: Options.colors.clrVertex,
      g: BYTE1(Options.colors.clrVertex),
      b: BYTE2(Options.colors.clrVertex));
  }
  if ( bIsTiny )
  {
    CRender::DrawLine(this: pRender, vStart: &vecMins, vEnd: &vecMaxs);
  }
  else
  {
    nCount = v6->Faces.nCount;
    v9 = 0;
    nFaces = nCount;
    if ( nCount > 0 )
    {
      v10 = v27;
      do
      {
        if ( v9 >= v10->Faces.nCount )
        {
          _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v9, v10->Faces.nCount);
          v11 = v9 + 1;
          if ( v9 + 1 != v10->Faces.nCount )
          {
            v12 = v11 / 6;
            if ( 6 * (v11 / 6) < v11 )
              ++v12;
            if ( v12 != v10->Faces.nBlocks )
            {
              if ( v12 > 0x57 )
                _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
              BlockArray<CMapFace,6,86>::GetBlocks(this: &v10->Faces, nNewBlocks: v12);
            }
            v2 = pRender;
            v10->Faces.nCount = v9 + 1;
          }
        }
        v13 = (unsigned int)&v10->Faces.Blocks[v9 / 6u][v9 % 6u];
        (*(void (__thiscall **)(unsigned int, CRender2D *))(*(_DWORD *)v13 + 48))(a1: v13, a2: v2);
        v25 = ++v9;
      }
      while ( v9 < nFaces );
    }
    if ( bPop )
    {
      v14 = 0;
      bPop = CRender::BeginClientSpace(this: v2);
      if ( nFaces > 0 )
      {
        v15 = v27;
        do
        {
          if ( v14 >= v15->Faces.nCount )
          {
            _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v14, v15->Faces.nCount);
            v16 = v14 + 1;
            if ( v14 + 1 != v15->Faces.nCount )
            {
              v17 = v16 / 6;
              if ( 6 * (v16 / 6) < v16 )
                ++v17;
              if ( v17 != v15->Faces.nBlocks )
              {
                if ( v17 > 0x57 )
                  _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
                BlockArray<CMapFace,6,86>::GetBlocks(this: &v15->Faces, nNewBlocks: v17);
              }
              v2 = pRender;
              v15->Faces.nCount = v14 + 1;
            }
          }
          CMapFace::RenderVertices(this: &v15->Faces.Blocks[v14 / 6u][v14 % 6u], pRender: v2);
          v25 = ++v14;
        }
        while ( v14 < nFaces );
      }
      if ( bPop )
        CRender::EndClientSpace(this: v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10141B80
// Name: public: virtual bool CMapSolid::HitTest2D(class CMapView2D __near *,class Vector2D const __near &,struct HitInfo_s __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapSolid::HitTest2D(CMapSolid *this, CMapView2D *pView, const Vector2D *point, HitInfo_s *HitData)
{
  CMapView *v6; // esi
  double v7; // st7
  int v8; // ecx
  int v9; // edx
  float y; // xmm0_4
  int nCount; // eax
  int v12; // ebx
  BlockArray<CMapFace,6,86> *p_Faces; // edi
  int v14; // eax
  int v15; // edi
  void (__thiscall *WorldToClient)(CMapView *, Vector2D *, const Vector *); // edx
  Vector *v17; // ebx
  Vector vecViewPoint; // [esp+4h] [ebp-4Ch] BYREF
  Vector vecCenter; // [esp+10h] [ebp-40h] BYREF
  Vector2D vecClientCenter; // [esp+1Ch] [ebp-34h] BYREF
  Vector2D vec1; // [esp+24h] [ebp-2Ch] BYREF
  Vector2D vec2; // [esp+2Ch] [ebp-24h] BYREF
  int nFaces; // [esp+34h] [ebp-1Ch]
  int x1; // [esp+38h] [ebp-18h]
  int y1; // [esp+3Ch] [ebp-14h]
  int x2; // [esp+40h] [ebp-10h]
  int y2; // [esp+44h] [ebp-Ch]
  Vector *pPoints; // [esp+48h] [ebp-8h]
  int k; // [esp+4Ch] [ebp-4h]
  int i; // [esp+58h] [ebp+8h]
  int j; // [esp+5Ch] [ebp+Ch]

  if ( (*((_BYTE *)&this->CMapClass + 180) & 2) == 0 )
    return 0;
  BoundBox::GetBoundsCenter(this: &this->m_Render2DBox, ptdest: &vecCenter);
  v6 = &pView->CMapView;
  pView->WorldToClient(this: &pView->CMapView, a2: &vecClientCenter, a3: &vecCenter);
  CCamera::GetViewPoint(this: pView->m_pCamera, ViewPoint: &vecViewPoint);
  HitData->pObject = this;
  v7 = *(&vecViewPoint.x + pView->axThird) - *(&vecCenter.x + pView->axThird);
  k = HIWORD(pView) | 0xC00;
  HitData->uData = 0;
  vec1 = (Vector2D)(__int64)v7;
  HitData->nDepth = (__int64)v7;
  if ( !CMapView2DBase::CheckDistance(this: pView, vecCheck: point, vecRef: &vecClientCenter, nDist: 4) )
  {
    if ( Options.view2d.bSelectbyhandles != 0 && this->IsEditable(this) )
      goto LABEL_18;
    v8 = (int)(float)(point->x - 2.0);
    v9 = (int)(float)(point->x + 2.0);
    y = point->y;
    y1 = (int)(float)(y - 2.0);
    nCount = this->Faces.nCount;
    v12 = 0;
    x1 = v8;
    x2 = v9;
    y2 = (int)(float)(y + 2.0);
    nFaces = nCount;
    i = 0;
    if ( nCount <= 0 )
    {
LABEL_18:
      HitData->pObject = nullptr;
      return 0;
    }
    p_Faces = &this->Faces;
    for ( k = (int)p_Faces; ; p_Faces = (BlockArray<CMapFace,6,86> *)k )
    {
      if ( v12 >= p_Faces->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v12, p_Faces->nCount);
        BlockArray<CMapFace,6,86>::SetCount(this: p_Faces, nObjects: v12 + 1);
      }
      v14 = (int)&p_Faces->Blocks[v12 / 6][v12 % 6];
      v15 = *(_DWORD *)(v14 + 344);
      if ( v15 > 0 )
      {
        WorldToClient = v6->WorldToClient;
        pPoints = *(Vector **)(v14 + 340);
        WorldToClient(this: v6, a2: &vec1, a3: pPoints);
        j = 1;
        if ( v15 > 1 )
          break;
      }
LABEL_17:
      i = ++v12;
      if ( v12 >= nFaces )
        goto LABEL_18;
    }
    v17 = pPoints + 1;
    while ( 1 )
    {
      v6->WorldToClient(this: v6, a2: &vec2, a3: v17);
      if ( IsLineInside(pt1: &vec1, pt2: &vec2, x1, y1, x2, y2) != 0 )
        break;
      vec1 = vec2;
      ++v17;
      if ( ++j >= v15 )
      {
        v12 = i;
        goto LABEL_17;
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10141DC0
// Name: public: bool CMapSolid::SaveDXF(struct ExportDXFInfo_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapSolid::SaveDXF(CMapSolid *this, ExportDXFInfo_s *pInfo)
{
  CMapSolid *v2; // ebx
  CSSolid *v4; // eax
  CChoreoChannel *v5; // esi
  _iobuf *fp; // edx
  const char *v7; // edi
  BlockArray<CMapFace,6,86> *p_Faces; // esi
  int v9; // ebx
  unsigned int v10; // esi
  CEditDispMgr *v11; // eax
  CMapDisp *v12; // eax
  int v13; // [esp-8h] [ebp-24h]
  int hDisp; // [esp+8h] [ebp-14h]

  v2 = this;
  if ( pInfo->bVisOnly && (*((_BYTE *)&this->CMapClass + 180) & 2) == 0 )
    return 1;
  v4 = (CSSolid *)operator new(nSize: 0x15Cu);
  v5 = nullptr;
  if ( v4 != nullptr )
    v5 = (CChoreoChannel *)CSSolid::CSSolid(this: v4);
  CChoreoChannel::SetActor(this: v5, actor: (CChoreoActor *)v2);
  CSSolid::Convert(this: (CSSolid *)v5, bFromMap: 1, bSkipDisplacementFaces: true);
  fp = pInfo->fp;
  v13 = pInfo->nObject++;
  CSSolid::SerializeDXF(this: (CSSolid *)v5, stream: fp, nObject: v13);
  if ( v5 != nullptr )
  {
    CSSolid::~CSSolid(this: (CSSolid *)v5);
    operator delete(p: v5);
  }
  v7 = nullptr;
  if ( v2->Faces.nCount <= 0 )
    return 1;
  p_Faces = &v2->Faces;
  while ( 1 )
  {
    if ( (int)v7 >= p_Faces->nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v7, p_Faces->nCount);
      v9 = (int)(v7 + 1);
      if ( v7 + 1 == (const char *)p_Faces->nCount )
      {
        v2 = this;
      }
      else
      {
        v10 = v9 / 6;
        if ( 6 * (v9 / 6) < v9 )
          ++v10;
        if ( v10 != this->Faces.nBlocks )
        {
          if ( v10 > 0x57 )
            _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
          BlockArray<CMapFace,6,86>::GetBlocks(this: &this->Faces, nNewBlocks: v10);
        }
        this->Faces.nCount = v9;
        v2 = this;
      }
    }
    p_Faces = &v2->Faces;
    if ( v2->Faces.Blocks[(int)v7 / 6][(int)v7 % 6].m_DispHandle != 0xFFFF )
    {
      hDisp = v2->Faces.Blocks[(int)v7 / 6][(int)v7 % 6].m_DispHandle;
      v11 = EditDispMgr();
      v12 = v11->GetDisp(this: v11, a2: hDisp);
      if ( CMapDisp::SaveDXF(this: v12, pInfo) == 0 )
        break;
    }
    if ( (int)++v7 >= v2->Faces.nCount )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10141FB0
// Name: public: virtual void CMapSolid::OnUndoRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSolid::OnUndoRedo(CMapSolid *this)
{
  int v1; // esi
  BlockArray<CMapFace,6,86> *p_Faces; // edi
  int v3; // ebx
  unsigned int v4; // edi
  int nFaces; // [esp+8h] [ebp-8h]
  BlockArray<CMapFace,6,86> *v6; // [esp+Ch] [ebp-4h]

  v1 = 0;
  nFaces = this->Faces.nCount;
  if ( nFaces > 0 )
  {
    p_Faces = &this->Faces;
    v6 = &this->Faces;
    do
    {
      if ( v1 >= p_Faces->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v1, p_Faces->nCount);
        v3 = v1 + 1;
        if ( v1 + 1 != p_Faces->nCount )
        {
          v4 = v3 / 6;
          if ( 6 * (v3 / 6) < v3 )
            ++v4;
          if ( v4 != v6->nBlocks )
          {
            if ( v4 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: v6, nNewBlocks: v4);
          }
          v6->nCount = v3;
          p_Faces = v6;
        }
      }
      CMapFace::OnUndoRedo(this: &p_Faces->Blocks[v1 / 6u][v1 % 6u]);
      ++v1;
    }
    while ( v1 < nFaces );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10142090
// Name: public: virtual void CMapSolid::Render3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSolid::Render3D(CMapSolid *this, CRender3D *pRender)
{
  CMapSolid *v2; // esi
  int v3; // ebx
  int v4; // eax
  CRender3D *v5; // ecx
  signed int v6; // edi
  int v7; // ebx
  unsigned int v8; // esi
  CMapFace *v9; // esi
  int nPass; // [esp+8h] [ebp-10h]
  int nPasses; // [esp+Ch] [ebp-Ch]
  bool bMaskFaces; // [esp+17h] [ebp-1h]

  v2 = this;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    if ( !CMapDoc::m_pMapDoc->m_bDispSolidDrawMask || (bMaskFaces = true, CMapSolid::HasDisp(this) == 0) )
      bMaskFaces = false;
    v3 = 1;
    nPasses = 1;
    v4 = v2->GetSelectionState(this: v2);
    v5 = pRender;
    if ( v4 != 0 && pRender->m_eDefaultRenderMode != RENDER_MODE_WIREFRAME )
      nPasses = 2;
    if ( v4 == 4 )
    {
      nPasses = 2;
      v3 = 2;
    }
    nPass = v3;
    if ( v3 <= nPasses )
    {
      while ( 1 )
      {
        if ( v3 == 1 )
          CRender::PushRenderMode(this: v5, eRenderMode: RENDER_MODE_CURRENT);
        else
          CRender::PushRenderMode(this: v5, eRenderMode: RENDER_MODE_WIREFRAME);
        v6 = 0;
        if ( v2->Faces.nCount > 0 )
          break;
LABEL_36:
        CRender::PopRenderMode(this: pRender);
        nPass = ++v3;
        if ( v3 > nPasses )
          return;
        v5 = pRender;
      }
      while ( 1 )
      {
        if ( v6 >= v2->Faces.nCount )
        {
          _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v6, v2->Faces.nCount);
          v7 = v6 + 1;
          if ( v6 + 1 != v2->Faces.nCount )
          {
            v8 = v7 / 6;
            if ( 6 * (v7 / 6) < v7 )
              ++v8;
            if ( v8 != this->Faces.nBlocks )
            {
              if ( v8 > 0x57 )
                _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
              BlockArray<CMapFace,6,86>::GetBlocks(this: &this->Faces, nNewBlocks: v8);
            }
            this->Faces.nCount = v7;
          }
        }
        v9 = &this->Faces.Blocks[v6 / 6][v6 % 6];
        if ( !bMaskFaces || v9->m_DispHandle != 0xFFFF )
        {
          if ( !pRender->IsInLightingPreview(this: pRender) )
            break;
          if ( nPass == 1 )
          {
            if ( v9->GetSelectionState(this: v9) != SELECT_NONE )
              break;
          }
          else
          {
            v9->Render3D(this: v9, a2: pRender);
          }
        }
LABEL_34:
        ++v6;
        v2 = this;
        if ( v6 >= this->Faces.nCount )
        {
          v3 = nPass;
          goto LABEL_36;
        }
      }
      CRender3D::BeginRenderHitTarget(this: pRender, pObject: this, uHandle: v6);
      v9->Render3D(this: v9, a2: pRender);
      CRender3D::EndRenderHitTarget(this: pRender);
      goto LABEL_34;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10142280
// Name: public: int CMapSolid::CreateFromPlanes(unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapSolid::CreateFromPlanes(CMapSolid *this, char dwFlags)
{
  int v3; // edi
  char *m_pMemory; // ecx
  int nCount; // esi
  unsigned int v6; // esi
  CMapFace *v7; // esi
  CMapSolid *v8; // ebx
  const char *v9; // esi
  int v10; // edi
  unsigned int v11; // esi
  const char *v12; // ecx
  CMapFace *v13; // ebx
  BlockArray<CMapFace,6,86> *p_Faces; // edi
  const char *v15; // esi
  unsigned int v16; // edi
  CMapFace *v17; // eax
  BlockArray<CMapFace,6,86> *j; // ebx
  const char *v19; // edi
  int v20; // edi
  unsigned int v21; // esi
  CMapFace *m_pElements; // ebx
  bool v23; // zf
  winding_t *WindingFromPlane; // edi
  const char *v25; // esi
  int v26; // ebx
  unsigned int v27; // edi
  float *v28; // eax
  int v29; // esi
  int k; // ebx
  CMapSolid *v31; // eax
  int v32; // esi
  bool *v33; // ebx
  BlockArray<CMapFace,6,86> *v34; // edi
  int p_low; // eax
  unsigned int v36; // ebx
  char *v37; // edi
  int v38; // edi
  __int16 *v39; // esi
  int v40; // ebx
  unsigned int v41; // esi
  CMapFace *v42; // esi
  CMapSolid *v43; // ebx
  char *v44; // esi
  BlockArray<CMapFace,6,86> *v45; // ebx
  int v46; // edi
  unsigned int v47; // ebx
  winding_t *v48; // eax
  int v49; // esi
  int m_nGrowSize; // edi
  char *v51; // eax
  PLANE split; // [esp+10h] [ebp-78h] BYREF
  CUtlMemory<char,int> v54; // [esp+44h] [ebp-44h] BYREF
  int v55; // [esp+50h] [ebp-38h]
  char *v56; // [esp+54h] [ebp-34h]
  CUtlVector<bool,CUtlMemory<bool,int> > useplane; // [esp+58h] [ebp-30h]
  int v; // [esp+6Ch] [ebp-1Ch]
  const char *v1; // [esp+70h] [ebp-18h]
  CMapSolid *v60; // [esp+74h] [ebp-14h]
  winding_t *w; // [esp+78h] [ebp-10h]
  int i; // [esp+84h] [ebp-4h]
  int v63; // [esp+90h] [ebp+8h]
  int v64; // [esp+90h] [ebp+8h]

  v3 = 0;
  m_pMemory = nullptr;
  memset(&v54, 0, sizeof(v54));
  v60 = this;
  v55 = 0;
  v56 = nullptr;
  i = 1;
  this->m_Render2DBox.bmins.x = 99999.0;
  this->m_Render2DBox.bmins.y = 99999.0;
  this->m_Render2DBox.bmins.z = 99999.0;
  this->m_Render2DBox.bmaxs.x = -99999.0;
  this->m_Render2DBox.bmaxs.y = -99999.0;
  this->m_Render2DBox.bmaxs.z = -99999.0;
  nCount = this->Faces.nCount;
  *((_BYTE *)this + 568) |= 1u;
  v = nCount;
  v55 = 0;
  if ( nCount != 0 )
  {
    if ( nCount > 0 )
    {
      CUtlMemory<bool,int>::Grow(this: &v54, num: nCount);
      m_pMemory = v54.m_pMemory;
    }
    v55 += nCount;
    v56 = m_pMemory;
    if ( v55 - nCount > 0 )
    {
      if ( nCount <= 0 )
        goto LABEL_18;
      _V_memmove(dest: &m_pMemory[nCount], src: m_pMemory, count: v55 - nCount);
    }
    if ( nCount > 0 )
    {
      do
      {
        if ( v3 >= this->Faces.nCount )
        {
          _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v3, this->Faces.nCount);
          if ( v3 + 1 != this->Faces.nCount )
          {
            v6 = (v3 + 1) / 6;
            if ( (int)(6 * v6) < v3 + 1 )
              ++v6;
            if ( v6 != this->Faces.nBlocks )
            {
              if ( v6 > 0x57 )
                _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
              BlockArray<CMapFace,6,86>::GetBlocks(this: &this->Faces, nNewBlocks: v6);
            }
            this->Faces.nCount = v3 + 1;
          }
        }
        v7 = &this->Faces.Blocks[v3 / 6u][v3 % 6u];
        CMapFace::AllocatePoints(this: v7, _nPoints: 0);
        v7->SetParent(this: v7, a2: this);
        v7->SetRenderColor_2(this: v7, a2: this->r, a3: this->g, a4: this->b);
        v54.m_pMemory[v3++] = 0;
      }
      while ( v3 < v );
    }
  }
LABEL_18:
  v1 = nullptr;
  if ( v > 0 )
  {
    do
    {
      v8 = v60;
      v9 = v1;
      if ( (int)v1 >= v60->Faces.nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v1, v60->Faces.nCount);
        v10 = (int)(v9 + 1);
        if ( v9 + 1 != (const char *)v8->Faces.nCount )
        {
          v11 = v10 / 6;
          if ( 6 * (v10 / 6) < v10 )
            ++v11;
          if ( v11 != v8->Faces.nBlocks )
          {
            if ( v11 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: &v8->Faces, nNewBlocks: v11);
          }
          v8->Faces.nCount = v10;
        }
      }
      v12 = v1;
      v13 = &v60->Faces.Blocks[(unsigned int)v1 / 6][(unsigned int)v1 % 6];
      p_Faces = &v60->Faces;
      if ( vec3_origin.x == v13->plane.normal.x
        && vec3_origin.y == v13->plane.normal.y
        && vec3_origin.z == v13->plane.normal.z )
      {
        v1[(unsigned int)v54.m_pMemory] = 0;
      }
      else
      {
        v15 = nullptr;
        v1[(unsigned int)v54.m_pMemory] = 1;
        if ( (int)v12 > 0 )
        {
          while ( 1 )
          {
            if ( (int)v15 >= p_Faces->nCount )
            {
              _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v15, p_Faces->nCount);
              if ( v15 + 1 != (const char *)p_Faces->nCount )
              {
                v16 = (int)(v15 + 1) / 6;
                if ( (int)(6 * v16) < (int)(v15 + 1) )
                  ++v16;
                if ( v16 != v60->Faces.nBlocks )
                {
                  if ( v16 > 0x57 )
                    _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
                  BlockArray<CMapFace,6,86>::GetBlocks(this: &v60->Faces, nNewBlocks: v16);
                }
                v60->Faces.nCount = (_WORD)v15 + 1;
              }
            }
            v17 = &v60->Faces.Blocks[(int)v15 / 6][(int)v15 % 6];
            p_Faces = &v60->Faces;
            if ( (float)((float)((float)(v17->plane.normal.y * v13->plane.normal.y)
                               + (float)(v17->plane.normal.x * v13->plane.normal.x))
                       + (float)(v17->plane.normal.z * v13->plane.normal.z)) > 0.999
              && fabs(v13->plane.dist - v17->plane.dist) < 0.01 )
            {
              break;
            }
            useplane.m_Memory.m_nGrowSize = (int)++v15;
            if ( (int)v15 >= (int)v1 )
              goto LABEL_47;
          }
          v54.m_pMemory[(unsigned int)v15] = 0;
LABEL_47:
          v12 = v1;
        }
      }
      v1 = v12 + 1;
    }
    while ( (int)(v12 + 1) < v );
  }
  useplane.m_Memory.m_nAllocationCount = 0;
  v1 = nullptr;
  if ( v <= 0 )
    goto LABEL_92;
  w = (winding_t *)&v60->Faces;
  for ( j = &v60->Faces; ; j = (BlockArray<CMapFace,6,86> *)w )
  {
    v19 = v1;
    if ( (int)v1 >= j->nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v1, j->nCount);
      v20 = (int)(v19 + 1);
      if ( v20 != j->nCount )
      {
        v21 = v20 / 6;
        if ( 6 * (v20 / 6) < v20 )
          ++v21;
        if ( v21 != j->nBlocks )
        {
          if ( v21 > 0x57 )
            _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
          BlockArray<CMapFace,6,86>::GetBlocks(this: j, nNewBlocks: v21);
        }
        j->nCount = v20;
      }
    }
    m_pElements = (CMapFace *)(*(&w->numpoints + (unsigned int)v1 / 6) + 444 * ((unsigned int)v1 % 6));
    v23 = v1[(unsigned int)v54.m_pMemory] == 0;
    useplane.m_pElements = (bool *)m_pElements;
    if ( !v23 )
    {
      WindingFromPlane = CreateWindingFromPlane(pPlane: &m_pElements->plane);
      useplane.m_Size = (int)WindingFromPlane;
      v25 = nullptr;
      while ( WindingFromPlane != nullptr )
      {
        if ( (int)v25 >= SLOWORD(w[43].p) )
        {
          _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v25, SLOWORD(w[43].p));
          v26 = (int)(v25 + 1);
          if ( v25 + 1 != (const char *)SLOWORD(w[43].p) )
          {
            v27 = v26 / 6;
            if ( 6 * (v26 / 6) < v26 )
              ++v27;
            if ( v27 != SHIWORD(w[43].p) )
            {
              if ( v27 > 0x57 )
                _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
              BlockArray<CMapFace,6,86>::GetBlocks(this: (BlockArray<CMapFace,6,86> *)w, nNewBlocks: v27);
            }
            WindingFromPlane = (winding_t *)useplane.m_Size;
            LOWORD(w[43].p) = v26;
          }
          m_pElements = (CMapFace *)useplane.m_pElements;
        }
        v28 = (float *)(*(&w->numpoints + (unsigned int)v25 / 6) + 444 * ((unsigned int)v25 % 6));
        if ( v25 != v1 )
        {
          split.normal.x = vec3_origin.x - v28[87];
          split.normal.y = vec3_origin.y - v28[88];
          split.normal.z = vec3_origin.z - v28[89];
          split.dist = -v28[90];
          WindingFromPlane = ClipWinding(in: WindingFromPlane, &split);
          useplane.m_Size = (int)WindingFromPlane;
        }
        useplane.m_Memory.m_nGrowSize = (int)++v25;
        if ( (int)v25 >= v )
        {
          if ( WindingFromPlane != nullptr )
          {
            v29 = 0;
            useplane.m_Size = 0;
            if ( WindingFromPlane->numpoints > 0 )
            {
              do
              {
                for ( k = 3; k != 0; --k )
                {
                  useplane.m_Memory.m_pMemory = *(bool **)((char *)&WindingFromPlane->p->x + v29);
                  *(float *)&useplane.m_Memory.m_nAllocationCount = rint(f: *(float *)&useplane.m_Memory.m_pMemory);
                  if ( *(float *)&useplane.m_Memory.m_pMemory != *(float *)&useplane.m_Memory.m_nAllocationCount
                    && COERCE_FLOAT(
                         COERCE_UNSIGNED_INT(*(float *)&useplane.m_Memory.m_pMemory - *(float *)&useplane.m_Memory.m_nAllocationCount)
                       & _mask__AbsFloat_) < 0.0099999998 )
                  {
                    *(_DWORD *)((char *)&WindingFromPlane->p->x + v29) = useplane.m_Memory.m_nAllocationCount;
                  }
                  v29 += 4;
                }
                useplane.m_Memory.m_nGrowSize = ++useplane.m_Size;
              }
              while ( useplane.m_Size < WindingFromPlane->numpoints );
              m_pElements = (CMapFace *)useplane.m_pElements;
            }
            RemoveDuplicateWindingPoints(pWinding: WindingFromPlane, fMinDist: 0.1);
            useplane.m_Memory.m_nAllocationCount = 1;
            if ( (dwFlags & 2) != 0 )
              CMapFace::CreateFace(this: m_pElements, w: WindingFromPlane, nFlags: 3);
            else
              CMapFace::CreateFace(this: m_pElements, w: WindingFromPlane, nFlags: 1);
            FreeWinding(w: WindingFromPlane);
          }
          break;
        }
      }
    }
    if ( (int)++v1 >= v )
      break;
  }
  if ( useplane.m_Memory.m_nAllocationCount != 0 )
  {
    v32 = v60->Faces.nCount;
    if ( v32 > 0 )
    {
      v33 = (bool *)(v32 + 1);
      do
      {
        v34 = (BlockArray<CMapFace,6,86> *)w;
        p_low = SLOWORD(w[43].p);
        --v32;
        useplane.m_pElements = --v33;
        if ( v32 >= p_low )
        {
          _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v32, p_low);
          if ( v33 != (bool *)v34->nCount )
          {
            v36 = (int)v33 / 6;
            if ( (int)(6 * v36) < (int)useplane.m_pElements )
              ++v36;
            if ( v36 != v34->nBlocks )
            {
              if ( v36 > 0x57 )
                _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
              BlockArray<CMapFace,6,86>::GetBlocks(this: v34, nNewBlocks: v36);
            }
            v33 = useplane.m_pElements;
            v34->nCount = (__int16)useplane.m_pElements;
          }
        }
        v37 = &v54.m_pMemory[(unsigned int)v33 - 1];
        if ( *v37 == 0 || *(_DWORD *)(*(&w->numpoints + v32 / 6) + 444 * (v32 % 6) + 344) == 0 )
        {
          CMapSolid::DeleteFace(this: v60, iIndex: (const char *)v32);
          if ( v55 - v32 - 1 > 0 )
            _V_memmove(dest: v37, src: &v54.m_pMemory[v32 + 1], count: v55 - v32 - 1);
          --v55;
        }
      }
      while ( v32 > 0 );
    }
  }
  else
  {
LABEL_92:
    v31 = v60;
    *((_BYTE *)v60 + 568) &= ~1u;
    v31->m_Render2DBox.bmins = vec3_origin;
    v31->m_Render2DBox.bmaxs = vec3_origin;
  }
  v38 = 0;
  v = v60->Faces.nCount;
  if ( v > 0 )
  {
    v39 = (__int16 *)&v60->Faces;
    w = (winding_t *)&v60->Faces;
    v63 = dwFlags & 1;
    while ( 1 )
    {
      if ( v38 >= v39[174] )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v38, v39[174]);
        v40 = v38 + 1;
        if ( v38 + 1 != v39[174] )
        {
          v41 = v40 / 6;
          if ( 6 * (v40 / 6) < v40 )
            ++v41;
          if ( v41 != SHIWORD(w[43].p) )
          {
            if ( v41 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: (BlockArray<CMapFace,6,86> *)w, nNewBlocks: v41);
          }
          LOWORD(w[43].p) = v40;
        }
      }
      v42 = (CMapFace *)(*(&w->numpoints + v38 / 6u) + 444 * (v38 % 6u));
      if ( v63 != 0 )
        CMapFace::CalcPlaneFromFacePoints(this: v42);
      else
        CMapFace::CalcPlane(this: v42);
      CMapFace::CalcTextureCoords(this: v42);
      if ( CMapFace::CheckFace(this: v42, pInfo: nullptr) == 0 )
        *((_BYTE *)v60 + 568) &= ~1u;
      useplane.m_Memory.m_pMemory = (bool *)++v38;
      if ( v38 >= v )
        break;
      v39 = (__int16 *)w;
    }
  }
  v43 = v60;
  v44 = nullptr;
  v64 = v60->Faces.nCount;
  if ( v64 > 0 )
  {
    v45 = &v60->Faces;
    w = (winding_t *)&v60->Faces;
    v46 = 1;
    do
    {
      if ( (int)v44 >= v45->nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v44, v45->nCount);
        if ( v46 != v45->nCount )
        {
          v47 = v46 / 6;
          if ( 6 * (v46 / 6) < v46 )
            ++v47;
          if ( v47 != SHIWORD(w[43].p) )
          {
            if ( v47 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: (BlockArray<CMapFace,6,86> *)w, nNewBlocks: v47);
          }
          v48 = w;
          LOWORD(w[43].p) = v46;
          v45 = (BlockArray<CMapFace,6,86> *)v48;
        }
      }
      if ( v45->Blocks[(int)v44 / 6][(int)v44 % 6].nPoints == 0 )
      {
        CMapSolid::DeleteFace(this: v60, iIndex: v44--);
        --v46;
        --v64;
      }
      ++v44;
      ++v46;
      useplane.m_Memory.m_pMemory = (bool *)v44;
    }
    while ( (int)v44 < v64 );
    v43 = v60;
  }
  v49 = *((_BYTE *)v43 + 568) & 1;
  i = 2;
  m_nGrowSize = v54.m_nGrowSize;
  v51 = v54.m_pMemory;
  v55 = 0;
  if ( v54.m_nGrowSize >= 0 )
  {
    if ( v54.m_pMemory != nullptr )
    {
      free(pMem: v54.m_pMemory);
      v51 = nullptr;
      v54.m_pMemory = nullptr;
    }
    v54.m_nAllocationCount = 0;
  }
  v56 = v51;
  i = -1;
  if ( m_nGrowSize >= 0 )
  {
    if ( v51 != nullptr )
    {
      free(pMem: v51);
      v54.m_pMemory = nullptr;
    }
    v54.m_nAllocationCount = 0;
  }
  return v49;
}

//------------------------------------------------------------------------------
// Address: 0x10142D40
// Name: public: enum ChunkFileResult_t CMapSolid::LoadVMF(class CChunkFile __near *,bool __near &)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CMapSolid::LoadVMF(CMapSolid *this, CMapDisp *pFile, bool *bValid)
{
  ChunkFileResult_t Chunk; // esi
  CMapFace *v5; // eax
  int v6; // edi
  CMapFace *v7; // esi
  CEditDispMgr *v8; // eax
  CMapSolid_vtbl *v9; // edi
  unsigned int v10; // eax
  int v11; // eax
  int v13; // [esp-4h] [ebp-2Ch]
  CChunkHandlerMap Handlers; // [esp+Ch] [ebp-1Ch] BYREF
  ChunkFileResult_t eResult; // [esp+18h] [ebp-10h]
  int v16; // [esp+24h] [ebp-4h]
  CMapDisp *pMapDisp; // [esp+30h] [ebp+8h]
  CMapDisp *pMapDispa; // [esp+30h] [ebp+8h]
  int faceCount; // [esp+34h] [ebp+Ch]

  CTextureReference::CTextureReference(this: (CTextureReference *)&Handlers);
  v16 = 0;
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "side",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapSolid::LoadSideCallback,
    pData: this);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "editor",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapClass::LoadEditorCallback,
    pData: this);
  CChunkFile::PushHandlers(this: (CChunkFile *)pFile, pHandlerMap: &Handlers);
  Chunk = CChunkFile::ReadChunk(
            this: (CChunkFile *)pFile,
            pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CMapClass::LoadEditorKeyCallback,
            pData: this);
  eResult = Chunk;
  CChunkFile::PopHandlers(this: (CChunkFile *)pFile);
  *bValid = false;
  if ( Chunk == ChunkFile_Ok )
  {
    if ( CMapSolid::CreateFromPlanes(this, dwFlags: 0) != 0 )
    {
      *bValid = true;
      this->CalcBounds(this, a2: 0);
      v5 = BlockArray<CMapFace,6,86>::operator[](this: &this->Faces, iIndex: 0);
      this->m_eSolidType = CMapSolid::HL1SolidTypeFromTextureName(this, pszTexture: v5->texture.texture);
      v6 = 0;
      faceCount = this->Faces.nCount;
      if ( faceCount > 0 )
      {
        do
        {
          if ( v6 >= this->Faces.nCount )
          {
            _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v6, this->Faces.nCount);
            BlockArray<CMapFace,6,86>::SetCount(this: &this->Faces, nObjects: v6 + 1);
          }
          v7 = &this->Faces.Blocks[v6 / 6u][v6 % 6u];
          if ( v7->m_DispHandle != 0xFFFF )
          {
            pMapDisp = (CMapDisp *)v7->m_DispHandle;
            v8 = EditDispMgr();
            pMapDispa = v8->GetDisp(this: v8, a2: (unsigned __int16)pMapDisp);
            CMapDisp::InitDispSurfaceData(this: pMapDispa, pFace: v7, bGenerateStartPoint: false);
            CMapDisp::Create(this: pMapDispa, a2: (int)this);
            CMapDisp::PostLoad(this: pMapDispa);
          }
          ++v6;
        }
        while ( v6 < faceCount );
        Chunk = eResult;
      }
      if ( this->r == 0 && this->g == 0 || this->b == 0 )
      {
        v9 = this->__vftable;
        v13 = (unsigned __int8)(random() % 0x9C + 100);
        v10 = random();
        v9->SetRenderColor_2(this, a2: 0, a3: v10 % 0x9C + 100, a4: v13);
      }
    }
    else
    {
      v11 = CMapSolid::g_nRecordedBadSolidCount;
      ++CMapSolid::g_nBadSolidCount;
      if ( CMapSolid::g_nRecordedBadSolidCount < 10 )
      {
        CMapSolid::g_nRecordedBadSolidIds[CMapSolid::g_nRecordedBadSolidCount] = this->m_nID;
        CMapSolid::g_nRecordedBadSolidCount = v11 + 1;
      }
    }
  }
  v16 = -1;
  CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  return Chunk;
}

//------------------------------------------------------------------------------
// Address: 0x10142F50
// Name: protected: bool CMapSolid::AddPlane(class CMapFace const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMapSolid::AddPlane(CMapSolid *this, const CMapFace *p)
{
  __int16 nCount; // ax
  CMapFace *v4; // edi
  TextureAlignment_t Id; // eax
  void (__thiscall *PostUpdate)(CMapAtom *, Notify_Dependent_t); // eax
  bool v7; // bl
  CMapFace NewFace; // [esp+Ch] [ebp-1C8h] BYREF
  int v10; // [esp+1D0h] [ebp-4h]

  CMapFace::CMapFace(this: &NewFace);
  v10 = 0;
  CMapFace::CopyFrom(this: &NewFace, pObject: p, dwFlags: 1u, bUpdateDependencies: true);
  nCount = this->Faces.nCount;
  if ( nCount <= 0 )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: nullptr, nCount);
    BlockArray<CMapFace,6,86>::SetCount(this: &this->Faces, nObjects: 1);
  }
  v4 = this->Faces.Blocks[0];
  CMapFace::SetTexture(this: &NewFace, pszNewTex: v4->texture.texture, bRescaleTextureCoordinates: false);
  NewFace.texture.q2contents = v4->texture.q2contents;
  NewFace.texture.q2surface = v4->texture.q2surface;
  NewFace.texture.nLightmapScale = v4->texture.nLightmapScale;
  Id = CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId(this: (ConCommandBase *)&Options);
  CMapFace::InitializeTextureAxes(this: &NewFace, eAlignment: Id, dwFlags: 0x1Fu);
  CMapSolid::AddFace(this, pFace: &NewFace);
  CMapSolid::CreateFromPlanes(this, dwFlags: 0);
  PostUpdate = this->PostUpdate;
  *((_BYTE *)this + 568) |= 1u;
  PostUpdate(this, a2: Notify_Changed);
  CMapSolid::RemoveEmptyFaces(this);
  v7 = this->Faces.nCount >= 4;
  v10 = -1;
  CMapFace::~CMapFace(this: &NewFace);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10143080
// Name: protected: void CMapSolid::ClipByFace(class CMapFace const __near *,class CMapSolid __near * __near *,class CMapSolid __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSolid::ClipByFace(CMapSolid *this, const CMapFace *fa, CMapSolid **f, CMapSolid **b)
{
  CMapSolid *v4; // eax
  CMapSolid *v5; // esi
  CMapSolid *v6; // edi
  CMapSolid *v7; // eax
  CMapSolid *v8; // esi
  CMapSolid *v9; // ecx
  CMapFace fb; // [esp+8h] [ebp-1E0h] BYREF
  Vector temp; // [esp+1C4h] [ebp-24h]
  CMapSolid *back; // [esp+1D0h] [ebp-18h]
  CMapSolid *v13; // [esp+1D4h] [ebp-14h]
  CMapSolid *front; // [esp+1D8h] [ebp-10h]
  int v15; // [esp+1E4h] [ebp-4h]

  v13 = this;
  v4 = (CMapSolid *)operator new(nSize: 0x240u);
  front = v4;
  v5 = nullptr;
  v15 = 0;
  if ( v4 != nullptr )
    v6 = CMapSolid::CMapSolid(this: v4, Parent0: nullptr);
  else
    v6 = nullptr;
  front = v6;
  v7 = (CMapSolid *)operator new(nSize: 0x240u);
  back = v7;
  v15 = 1;
  if ( v7 != nullptr )
    v5 = CMapSolid::CMapSolid(this: v7, Parent0: nullptr);
  v15 = -1;
  back = v5;
  CMapFace::CMapFace(this: &fb);
  v15 = 2;
  CMapFace::CopyFrom(this: &fb, pObject: fa, dwFlags: 2u, bUpdateDependencies: true);
  temp = fb.plane.planepts[0];
  fb.plane.planepts[0] = fb.plane.planepts[2];
  fb.plane.planepts[2] = temp;
  CMapFace::CalcPlane(this: &fb);
  v6->CopyFrom(this: v6, a2: v13, a3: false);
  v6->SetParent(this: v6, a2: nullptr);
  v5->CopyFrom(this: v5, a2: v13, a3: false);
  v5->SetParent(this: v5, a2: nullptr);
  if ( CMapSolid::AddPlane(this: v5, p: fa) )
  {
    v8 = back;
  }
  else
  {
    ((void (__thiscall *)(CMapSolid *, int))v5->~CMapClass)(a1: v5, a2: 1);
    v8 = nullptr;
  }
  if ( CMapSolid::AddPlane(this: v6, p: &fb) )
  {
    v9 = front;
  }
  else
  {
    ((void (__thiscall *)(CMapSolid *, int))v6->~CMapClass)(a1: v6, a2: 1);
    v9 = nullptr;
  }
  if ( f != nullptr )
  {
    *f = v9;
  }
  else if ( v9 != nullptr )
  {
    ((void (__thiscall *)(CMapSolid *, int))v9->~CMapClass)(a1: v9, a2: 1);
  }
  if ( b != nullptr )
  {
    *b = v8;
  }
  else if ( v8 != nullptr )
  {
    ((void (__thiscall *)(CMapSolid *, int))v8->~CMapClass)(a1: v8, a2: 1);
  }
  v15 = -1;
  CMapFace::~CMapFace(this: &fb);
}

//------------------------------------------------------------------------------
// Address: 0x10143250
// Name: public: int CMapSolid::Split(struct PLANE __near *,class CMapSolid __near * __near *,class CMapSolid __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapSolid::Split(CMapSolid *this, PLANE *pPlane, CMapSolid **pFront, CMapSolid **pBack)
{
  CMapSolid *v4; // esi
  int v5; // ebx
  __int16 nCount; // ax
  CMapFace *v7; // edi
  int v8; // eax
  int v9; // edi
  int v10; // ebx
  unsigned int v11; // esi
  CMapSolid *v12; // eax
  unsigned int v13; // eax
  int v14; // ecx
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  float dist; // xmm4_4
  float *v19; // eax
  float v20; // xmm0_4
  CMapSolid *v21; // eax
  CMapSolid *v22; // esi
  PLANE *v23; // edi
  float v24; // xmm0_4
  TextureAlignment_t Id; // eax
  CMapSolid *v26; // eax
  CMapSolid *v27; // esi
  TextureAlignment_t v28; // eax
  CMapSolid **v30; // edi
  CMapSolid *v31; // eax
  CMapSolid *v32; // esi
  TextureAlignment_t v33; // eax
  CMapFace face; // [esp+Ch] [ebp-1DCh] BYREF
  int v35; // [esp+1C8h] [ebp-20h]
  int faceCount; // [esp+1CCh] [ebp-1Ch]
  int frontCount; // [esp+1D0h] [ebp-18h]
  int backCount; // [esp+1D4h] [ebp-14h]
  CMapSolid *v39; // [esp+1D8h] [ebp-10h]
  int v40; // [esp+1E4h] [ebp-4h]

  v4 = this;
  v39 = this;
  CMapFace::CMapFace(this: &face);
  v5 = 0;
  v40 = 0;
  nCount = v4->Faces.nCount;
  if ( nCount <= 0 )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: nullptr, nCount);
    BlockArray<CMapFace,6,86>::SetCount(this: &v4->Faces, nObjects: 1);
  }
  v7 = v4->Faces.Blocks[0];
  if ( v7 != nullptr )
    CMapFace::SetTexture(this: &face, pTexture: v7->m_pTexture, bRescaleTextureCoordinates: false);
  v8 = v4->Faces.nCount;
  v9 = 0;
  frontCount = 0;
  backCount = 0;
  faceCount = v8;
  if ( v8 <= 0 )
    goto LABEL_41;
  do
  {
    if ( v9 >= v4->Faces.nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v9, v4->Faces.nCount);
      v10 = v9 + 1;
      if ( v9 + 1 != v4->Faces.nCount )
      {
        v11 = v10 / 6;
        if ( 6 * (v10 / 6) < v10 )
          ++v11;
        if ( v11 != v39->Faces.nBlocks )
        {
          if ( v11 > 0x57 )
            _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
          BlockArray<CMapFace,6,86>::GetBlocks(this: &v39->Faces, nNewBlocks: v11);
        }
        v12 = v39;
        v39->Faces.nCount = v10;
        v4 = v12;
      }
      v5 = frontCount;
    }
    v13 = (unsigned int)&v4->Faces.Blocks[v9 / 6u][v9 % 6u];
    v14 = *(_DWORD *)(v13 + 344);
    if ( v14 > 0 )
    {
      y = pPlane->normal.y;
      x = pPlane->normal.x;
      z = pPlane->normal.z;
      dist = pPlane->dist;
      v19 = *(float **)(v13 + 340);
      do
      {
        v20 = (float)((float)((float)(v19[1] * y) + (float)(x * *v19)) + (float)(v19[2] * z)) - dist;
        if ( v20 <= 0.001 )
        {
          if ( v20 < -0.001 )
            ++backCount;
        }
        else
        {
          ++v5;
        }
        v19 += 3;
        --v14;
      }
      while ( v14 != 0 );
      frontCount = v5;
    }
    v35 = ++v9;
  }
  while ( v9 < faceCount );
  if ( v5 != 0 )
  {
    if ( backCount != 0 )
    {
      if ( pFront != nullptr )
      {
        v21 = (CMapSolid *)operator new(nSize: 0x240u);
        LOBYTE(v40) = 2;
        if ( v21 != nullptr )
          v22 = CMapSolid::CMapSolid(this: v21, Parent0: nullptr);
        else
          v22 = nullptr;
        LOBYTE(v40) = 0;
        v22->CopyFrom(this: v22, a2: v39, a3: false);
        v22->SetParent(this: v22, a2: nullptr);
        v23 = pPlane;
        v22->m_bTemporary = true;
        face.plane.normal = pPlane->normal;
        face.plane.normal.x = -face.plane.normal.x;
        v24 = -pPlane->dist;
        face.plane.normal.y = -face.plane.normal.y;
        face.plane.normal.z = -face.plane.normal.z;
        face.plane.dist = v24;
        CMapSolid::AddFace(this: v22, pFace: &face);
        if ( CMapSolid::CreateFromPlanes(this: v22, dwFlags: 3) != 0 )
        {
          Id = CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId(this: (ConCommandBase *)&Options);
          CMapSolid::InitializeTextureAxes(this: v22, eAlignment: Id, dwFlags: 0x1Eu);
          v22->PostUpdate(this: v22, a2: Notify_Clipped_Intermediate);
          *pFront = v22;
        }
      }
      else
      {
        v23 = pPlane;
      }
      if ( pBack != nullptr )
      {
        v26 = (CMapSolid *)operator new(nSize: 0x240u);
        LOBYTE(v40) = 3;
        if ( v26 != nullptr )
          v27 = CMapSolid::CMapSolid(this: v26, Parent0: nullptr);
        else
          v27 = nullptr;
        LOBYTE(v40) = 0;
        v27->CopyFrom(this: v27, a2: v39, a3: false);
        v27->SetParent(this: v27, a2: nullptr);
        v27->m_bTemporary = true;
        face.plane.normal = v23->normal;
        face.plane.dist = v23->dist;
        CMapSolid::AddFace(this: v27, pFace: &face);
        if ( CMapSolid::CreateFromPlanes(this: v27, dwFlags: 3) != 0 )
        {
          v28 = CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId(this: (ConCommandBase *)&Options);
          CMapSolid::InitializeTextureAxes(this: v27, eAlignment: v28, dwFlags: 0x1Eu);
          v27->PostUpdate(this: v27, a2: Notify_Clipped_Intermediate);
          *pBack = v27;
        }
      }
      v40 = -1;
      CMapFace::~CMapFace(this: &face);
      return 2;
    }
    v30 = pFront;
  }
  else
  {
LABEL_41:
    v30 = pBack;
  }
  if ( v30 != nullptr )
  {
    v31 = (CMapSolid *)operator new(nSize: 0x240u);
    LOBYTE(v40) = 1;
    if ( v31 != nullptr )
      v32 = CMapSolid::CMapSolid(this: v31, Parent0: nullptr);
    else
      v32 = nullptr;
    LOBYTE(v40) = 0;
    v32->CopyFrom(this: v32, a2: v39, a3: false);
    v32->SetParent(this: v32, a2: nullptr);
    v32->m_bTemporary = true;
    if ( CMapSolid::CreateFromPlanes(this: v32, dwFlags: 2) != 0 )
    {
      v33 = CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId(this: (ConCommandBase *)&Options);
      CMapSolid::InitializeTextureAxes(this: v32, eAlignment: v33, dwFlags: 0x1Eu);
      v32->PostUpdate(this: v32, a2: Notify_Changed);
    }
    *v30 = v32;
    v40 = -1;
    CMapFace::~CMapFace(this: &face);
    return 1;
  }
  else
  {
    v40 = -1;
    CMapFace::~CMapFace(this: &face);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101436E0
// Name: public: virtual void CMapSolid::OnAddToWorld(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapSolid::OnAddToWorld(CMapSolid *this, CMapWorld *pWorld)
{
  int v3; // edi
  int v4; // ebx
  unsigned int v5; // esi
  unsigned int v6; // esi
  int m_nNextFaceID; // eax
  int m_Size; // eax
  int v9; // ebx
  int v10; // eax
  CMapFace **v11; // eax
  CMapClass *FirstDescendent; // eax
  CMapSolid *v13; // ebx
  CMapSolid *v14; // eax
  int v15; // edi
  int nCount; // eax
  int v17; // ebx
  unsigned int v18; // esi
  CMapSolid *v19; // eax
  int v20; // eax
  UtlRBTreeNode_t<int,int> *m_pMemory; // ecx
  int v22; // edx
  unsigned int v23; // esi
  int v24; // edx
  int *p_m_Data; // esi
  int v26; // edi
  CMapFace **v27; // ebx
  CMapFace *v28; // esi
  int v29; // eax
  int v30; // ecx
  int v31; // esi
  UtlRBTreeNode_t<int,int> *v32; // eax
  int m_nGrowSize; // esi
  UtlRBTreeNode_t<int,int> *v34; // eax
  int v35; // esi
  CMapSolid *v36; // ebx
  unsigned int v37; // edi
  int v38; // edi
  CMapFace **v39; // eax
  EnumChildrenPos_t pos; // [esp+Ch] [ebp-E0h] BYREF
  int parent; // [esp+90h] [ebp-5Ch] BYREF
  int nFaceCount; // [esp+94h] [ebp-58h]
  int insert; // [esp+98h] [ebp-54h] BYREF
  CUtlRBTree<int,int,bool (__cdecl*)(int const &,int const &),CUtlMemory<UtlRBTreeNode_t<int,int>,int> > faceIDs; // [esp+9Ch] [ebp-50h] BYREF
  int search; // [esp+C0h] [ebp-2Ch] BYREF
  CMapFaceList CheckList; // [esp+C4h] [ebp-28h] BYREF
  bool leftchild; // [esp+DBh] [ebp-11h] BYREF
  CMapSolid *v48; // [esp+DCh] [ebp-10h]
  int v49; // [esp+E8h] [ebp-4h]

  v48 = this;
  CMapClass::OnAddToWorld(this, pWorld);
  v3 = 0;
  memset(&CheckList, 0, sizeof(CheckList));
  v49 = 2;
  nFaceCount = this->Faces.nCount;
  if ( nFaceCount > 0 )
  {
    do
    {
      if ( v3 >= v48->Faces.nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v3, v48->Faces.nCount);
        v4 = v3 + 1;
        if ( v3 + 1 != v48->Faces.nCount )
        {
          v5 = v4 / 6;
          if ( 6 * (v4 / 6) < v4 )
            ++v5;
          if ( v5 != v48->Faces.nBlocks )
          {
            if ( v5 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: &v48->Faces, nNewBlocks: v5);
          }
          v48->Faces.nCount = v4;
        }
      }
      v6 = (unsigned int)&v48->Faces.Blocks[v3 / 6u][v3 % 6u];
      if ( *(_DWORD *)(v6 + 412) != 0 )
      {
        m_Size = CheckList.m_Size;
        v9 = CheckList.m_Size;
        if ( CheckList.m_Size + 1 > CheckList.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CVisGroup *,int>::Grow(
            this: (CUtlMemory<CCullTreeNode *,int> *)&CheckList,
            num: CheckList.m_Size - CheckList.m_Memory.m_nAllocationCount + 1);
          m_Size = CheckList.m_Size;
        }
        CheckList.m_Size = m_Size + 1;
        v10 = m_Size - v9;
        CheckList.m_pElements = CheckList.m_Memory.m_pMemory;
        if ( v10 > 0 )
          _V_memmove(
            dest: &CheckList.m_Memory.m_pMemory[v9 + 1],
            src: &CheckList.m_Memory.m_pMemory[v9],
            count: 4 * v10);
        v11 = &CheckList.m_Memory.m_pMemory[v9];
        if ( v11 != nullptr )
          *v11 = (CMapFace *)v6;
      }
      else
      {
        m_nNextFaceID = pWorld->m_nNextFaceID;
        pWorld->m_nNextFaceID = m_nNextFaceID + 1;
        *(_DWORD *)(v6 + 412) = m_nNextFaceID;
      }
      search = ++v3;
    }
    while ( v3 < nFaceCount );
    if ( CheckList.m_Size > 0 )
    {
      FirstDescendent = CMapClass::GetFirstDescendent(this: pWorld, (CMapClass *)&pos);
      if ( FirstDescendent != nullptr )
      {
        v13 = v48;
        do
        {
          v14 = (CMapSolid *)__RTDynamicCast(
                               inptr: FirstDescendent,
                               VfDelta: 0,
                               SrcType: &CMapClass `RTTI Type Descriptor',
                               TargetType: &CMapSolid `RTTI Type Descriptor',
                               isReference: 0);
          if ( v14 != nullptr && v14 != v13 )
          {
            v15 = 0;
            memset(&faceIDs, 0, 16);
            faceIDs.m_Root = -1;
            faceIDs.m_NumElements = 0;
            faceIDs.m_FirstFree = -1;
            faceIDs.m_LastAlloc.index = -1;
            faceIDs.m_pElements = nullptr;
            LOBYTE(v49) = 4;
            nCount = v13->Faces.nCount;
            faceIDs.m_LessFunc = (bool (__cdecl *)(const int *, const int *))CDefOps<DmeTime_t>::LessFunc;
            search = nCount;
            if ( nCount > 0 )
            {
              do
              {
                if ( v15 >= v13->Faces.nCount )
                {
                  _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v15, v13->Faces.nCount);
                  v17 = v15 + 1;
                  if ( v15 + 1 == v48->Faces.nCount )
                  {
                    v13 = v48;
                  }
                  else
                  {
                    v18 = v17 / 6;
                    if ( 6 * (v17 / 6) < v17 )
                      ++v18;
                    if ( v18 != v48->Faces.nBlocks )
                    {
                      if ( v18 > 0x57 )
                        _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
                      BlockArray<CMapFace,6,86>::GetBlocks(this: &v48->Faces, nNewBlocks: v18);
                    }
                    v19 = v48;
                    v48->Faces.nCount = v17;
                    v13 = v19;
                  }
                }
                insert = v13->Faces.Blocks[v15 / 6u][v15 % 6u].m_nFaceID;
                parent = -1;
                leftchild = false;
                CUtlRBTree<int,int,bool (__cdecl *)(int const &,int const &),CUtlMemory<UtlRBTreeNode_t<int,int>,int>>::FindInsertionPosition(
                  this: &faceIDs,
                  &insert,
                  &parent,
                  &leftchild);
                v20 = CUtlRBTree<int,int,bool (__cdecl *)(int const &,int const &),CUtlMemory<UtlRBTreeNode_t<int,int>,int>>::NewNode(
                        this: &faceIDs,
                        a2: (const char *)v15);
                m_pMemory = faceIDs.m_Elements.m_pMemory;
                v22 = parent;
                v23 = v20;
                faceIDs.m_Elements.m_pMemory[v23].m_Parent = parent;
                m_pMemory[v23].m_Right = -1;
                m_pMemory[v23].m_Left = -1;
                m_pMemory[v23].m_Tag = 0;
                if ( v22 == -1 )
                {
                  faceIDs.m_Root = v20;
                }
                else
                {
                  v24 = v22;
                  if ( leftchild )
                    m_pMemory[v24].m_Left = v20;
                  else
                    m_pMemory[v24].m_Right = v20;
                }
                CUtlRBTree<int,int,bool (__cdecl *)(int const &,int const &),CUtlMemory<UtlRBTreeNode_t<int,int>,int>>::InsertRebalance(
                  this: &faceIDs,
                  elem: v20);
                ++faceIDs.m_NumElements;
                p_m_Data = &faceIDs.m_Elements.m_pMemory[v23].m_Data;
                if ( p_m_Data != nullptr )
                  *p_m_Data = insert;
                insert = ++v15;
              }
              while ( v15 < search );
            }
            v26 = CheckList.m_Size - 1;
            if ( CheckList.m_Size - 1 >= 0 )
            {
              v27 = CheckList.m_Memory.m_pMemory;
              do
              {
                v28 = v27[v26];
                search = v28->m_nFaceID;
                if ( CUtlRBTree<int,int,bool (__cdecl *)(int const &,int const &),CUtlMemory<UtlRBTreeNode_t<int,int>,int>>::Find(
                       this: &faceIDs,
                       &search) != -1 )
                {
                  v29 = pWorld->m_nNextFaceID;
                  pWorld->m_nNextFaceID = v29 + 1;
                  v30 = CheckList.m_Size;
                  v28->m_nFaceID = v29;
                  if ( v30 > 0 )
                  {
                    if ( v26 != v30 - 1 )
                      v27[v26] = v27[v30 - 1];
                    CheckList.m_Size = v30 - 1;
                  }
                }
                --v26;
              }
              while ( v26 >= 0 );
              v13 = v48;
            }
            if ( CheckList.m_Size <= 0 )
            {
              LOBYTE(v49) = 5;
              CUtlRBTree<int,int,bool (__cdecl *)(int const &,int const &),CUtlMemory<UtlRBTreeNode_t<int,int>,int>>::RemoveAll(this: &faceIDs);
              m_nGrowSize = faceIDs.m_Elements.m_nGrowSize;
              v34 = faceIDs.m_Elements.m_pMemory;
              faceIDs.m_FirstFree = -1;
              if ( faceIDs.m_Elements.m_nGrowSize >= 0 )
              {
                if ( faceIDs.m_Elements.m_pMemory != nullptr )
                {
                  free(pMem: faceIDs.m_Elements.m_pMemory);
                  v34 = nullptr;
                  faceIDs.m_Elements.m_pMemory = nullptr;
                }
                faceIDs.m_Elements.m_nAllocationCount = 0;
              }
              faceIDs.m_LastAlloc.index = -1;
              LOBYTE(v49) = 2;
              if ( m_nGrowSize >= 0 )
              {
                if ( v34 != nullptr )
                {
                  free(pMem: v34);
                  faceIDs.m_Elements.m_pMemory = nullptr;
                }
                faceIDs.m_Elements.m_nAllocationCount = 0;
              }
              break;
            }
            LOBYTE(v49) = 6;
            CUtlRBTree<int,int,bool (__cdecl *)(int const &,int const &),CUtlMemory<UtlRBTreeNode_t<int,int>,int>>::RemoveAll(this: &faceIDs);
            v31 = faceIDs.m_Elements.m_nGrowSize;
            v32 = faceIDs.m_Elements.m_pMemory;
            faceIDs.m_FirstFree = -1;
            if ( faceIDs.m_Elements.m_nGrowSize >= 0 )
            {
              if ( faceIDs.m_Elements.m_pMemory != nullptr )
              {
                free(pMem: faceIDs.m_Elements.m_pMemory);
                v32 = nullptr;
                faceIDs.m_Elements.m_pMemory = nullptr;
              }
              faceIDs.m_Elements.m_nAllocationCount = 0;
            }
            faceIDs.m_LastAlloc.index = -1;
            LOBYTE(v49) = 2;
            if ( v31 >= 0 )
            {
              if ( v32 != nullptr )
              {
                free(pMem: v32);
                faceIDs.m_Elements.m_pMemory = nullptr;
              }
              faceIDs.m_Elements.m_nAllocationCount = 0;
            }
          }
          FirstDescendent = CMapClass::GetNextDescendent(this: pWorld, (CMapClass *)&pos);
        }
        while ( FirstDescendent != nullptr );
      }
    }
  }
  v35 = 0;
  if ( nFaceCount > 0 )
  {
    v36 = v48;
    do
    {
      if ( v35 >= v36->Faces.nCount )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v35, v36->Faces.nCount);
        if ( v35 + 1 != v36->Faces.nCount )
        {
          v37 = (v35 + 1) / 6;
          if ( (int)(6 * v37) < v35 + 1 )
            ++v37;
          if ( v37 != v36->Faces.nBlocks )
          {
            if ( v37 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: &v36->Faces, nNewBlocks: v37);
          }
          v36->Faces.nCount = v35 + 1;
        }
      }
      CMapFace::OnAddToWorld(this: &v36->Faces.Blocks[v35 / 6u][v35 % 6u], pWorld);
      search = ++v35;
    }
    while ( v35 < nFaceCount );
  }
  v49 = 8;
  v38 = CheckList.m_Memory.m_nGrowSize;
  v39 = CheckList.m_Memory.m_pMemory;
  CheckList.m_Size = 0;
  if ( CheckList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( CheckList.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: CheckList.m_Memory.m_pMemory);
      v39 = nullptr;
      CheckList.m_Memory.m_pMemory = nullptr;
    }
    CheckList.m_Memory.m_nAllocationCount = 0;
  }
  CheckList.m_pElements = v39;
  v49 = -1;
  if ( v38 >= 0 && v39 != nullptr )
    free(pMem: v39);
}

//------------------------------------------------------------------------------
// Address: 0x10143CA0
// Name: protected: bool CMapSolid::Carve(class CUtlReferenceVector<class CMapClass> __near *,class CUtlReferenceVector<class CMapClass> __near *,class CMapSolid __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapSolid::Carve(
        CMapSolid *this,
        CUtlReferenceVector<CMapClass> *pInside,
        CUtlReferenceVector<CMapClass> *pOutside,
        CMapSolid *pCarver)
{
  const char *v5; // ebx
  int v6; // eax
  unsigned int v7; // eax
  CMapSolid **v8; // esi
  CMapClass *v9; // eax
  CUtlReference<CMapClass> *v10; // ecx
  int v12; // edi
  unsigned int v13; // esi
  CUtlReferenceList<CMapClass> *p_m_References; // eax
  CUtlReference<CMapClass> *m_pHead; // ecx
  CMapSolid *v16; // esi
  CUtlReference<CMapClass> *v17; // eax
  int nCount; // edx
  int v19; // [esp-4h] [ebp-2B4h]
  CMapSolid CarveFrom; // [esp+Ch] [ebp-2A4h] BYREF
  Vector carvemaxs; // [esp+24Ch] [ebp-64h] BYREF
  Vector bmaxs; // [esp+258h] [ebp-58h] BYREF
  Vector carvemins; // [esp+264h] [ebp-4Ch] BYREF
  Vector bmins; // [esp+270h] [ebp-40h] BYREF
  const char *v25; // [esp+27Ch] [ebp-34h]
  CMapSolid *front; // [esp+280h] [ebp-30h] BYREF
  CMapSolid **v27; // [esp+284h] [ebp-2Ch]
  CMapSolid *back; // [esp+288h] [ebp-28h] BYREF
  CUtlReference<CMapClass> v29; // [esp+28Ch] [ebp-24h] BYREF
  CUtlReference<CMapClass> src; // [esp+298h] [ebp-18h] BYREF
  int v31; // [esp+2ACh] [ebp-4h]

  v5 = nullptr;
  front = nullptr;
  back = nullptr;
  CMapClass::GetRender2DBox(this, mins: &bmins, maxs: &bmaxs);
  CMapClass::GetRender2DBox(this: pCarver, mins: &carvemins, maxs: &carvemaxs);
  v6 = 0;
  while ( *(float *)((char *)&bmins.x + v6) < *(float *)((char *)&carvemaxs.x + v6)
       && *(float *)((char *)&carvemins.x + v6) < *(float *)((char *)&bmaxs.x + v6) )
  {
    v6 += 4;
    if ( v6 >= 12 )
    {
      CMapClass::CMapClass(this: &CarveFrom);
      v31 = 2;
      CarveFrom.__vftable = (CMapSolid_vtbl *)&CMapSolid::`vftable';
      *(_DWORD *)&CarveFrom.Faces.nCount = 0;
      *((_BYTE *)&CarveFrom + 568) &= ~1u;
      *((_BYTE *)&CarveFrom + 568) &= ~2u;
      CarveFrom.m_pParent = nullptr;
      CarveFrom.m_eSolidType = btSolid;
      v19 = (unsigned __int8)(random() % 0x9C + 100);
      v7 = random();
      CMapSolid::SetRenderColor(this: &CarveFrom, uchRed: 0, uchGreen: (unsigned __int8)(v7 % 0x9C + 100), uchBlue: v19);
      v31 = 3;
      CMapSolid::CopyFrom(this: &CarveFrom, pobj: this, bUpdateDependencies: false);
      if ( pCarver->Faces.nCount <= 0 )
      {
LABEL_58:
        CarveFrom.__vftable = (CMapSolid_vtbl *)&CMapSolid::`vftable';
        v31 = 9;
        if ( CarveFrom.Faces.nCount != 0 )
        {
          if ( CarveFrom.Faces.nBlocks != 0 )
            BlockArray<CMapFace,6,86>::GetBlocks(this: &CarveFrom.Faces, nNewBlocks: 0);
          CarveFrom.Faces.nCount = 0;
        }
        LOBYTE(v31) = 8;
        BlockArray<CMapFace,6,86>::GetBlocks(this: &CarveFrom.Faces, nNewBlocks: 0);
        v31 = -1;
        CMapClass::~CMapClass(this: &CarveFrom);
        return 1;
      }
      v8 = pOutside != nullptr ? &front : nullptr;
      v27 = v8;
      while ( 2 )
      {
        if ( (int)v5 >= pCarver->Faces.nCount )
        {
          _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v5, pCarver->Faces.nCount);
          v12 = (int)(v5 + 1);
          if ( v5 + 1 != (const char *)pCarver->Faces.nCount )
          {
            v13 = v12 / 6;
            if ( 6 * (v12 / 6) < v12 )
              ++v13;
            if ( v13 != pCarver->Faces.nBlocks )
            {
              if ( v13 > 0x57 )
                _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
              BlockArray<CMapFace,6,86>::GetBlocks(this: &pCarver->Faces, nNewBlocks: v13);
            }
            v8 = v27;
            pCarver->Faces.nCount = v12;
          }
        }
        CMapSolid::ClipByFace(this: &CarveFrom, fa: &pCarver->Faces.Blocks[(int)v5 / 6][(int)v5 % 6], f: v8, b: &back);
        if ( front != nullptr )
        {
          if ( pOutside != nullptr )
          {
            p_m_References = &front->m_References;
            src.m_pNext = nullptr;
            src.m_pPrev = nullptr;
            src.m_pObject = front;
            src.m_pNext = front->m_References.m_pHead;
            m_pHead = front->m_References.m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = &src;
            src.m_pPrev = nullptr;
            p_m_References->m_pHead = &src;
            LOBYTE(v31) = 4;
            CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
              this: pOutside,
              elem: pOutside->m_Size,
              &src);
            LOBYTE(v31) = 3;
            if ( src.m_pObject != nullptr )
            {
              if ( src.m_pPrev != nullptr )
              {
                src.m_pPrev->m_pNext = src.m_pNext;
                if ( src.m_pNext != nullptr )
                {
                  src.m_pNext->m_pPrev = src.m_pPrev;
                  memset(&src, 0, sizeof(src));
                  goto LABEL_44;
                }
              }
              else if ( src.m_pObject->m_References.m_pHead == &src )
              {
                src.m_pObject->m_References.m_pHead = src.m_pNext;
                if ( src.m_pNext != nullptr )
                  src.m_pNext->m_pPrev = nullptr;
              }
              memset(&src, 0, sizeof(src));
            }
          }
          else
          {
            ((void (__stdcall *)(int))front->~CMapClass)(a1: 1);
          }
        }
LABEL_44:
        v16 = back;
        if ( back == nullptr )
        {
          CarveFrom.__vftable = (CMapSolid_vtbl *)&CMapSolid::`vftable';
          v31 = 6;
          if ( CarveFrom.Faces.nCount != 0 )
          {
            if ( CarveFrom.Faces.nBlocks != 0 )
              BlockArray<CMapFace,6,86>::GetBlocks(this: &CarveFrom.Faces, nNewBlocks: 0);
            CarveFrom.Faces.nCount = 0;
          }
          LOBYTE(v31) = 5;
          BlockArray<CMapFace,6,86>::GetBlocks(this: &CarveFrom.Faces, nNewBlocks: 0);
          v31 = -1;
          CMapClass::~CMapClass(this: &CarveFrom);
          return 0;
        }
        CMapSolid::CopyFrom(this: &CarveFrom, pobj: back, bUpdateDependencies: false);
        if ( pInside == nullptr )
        {
          ((void (__thiscall *)(CMapSolid *, int))v16->~CMapClass)(a1: v16, a2: 1);
          goto LABEL_57;
        }
        v29.m_pNext = nullptr;
        v29.m_pPrev = nullptr;
        v29.m_pObject = v16;
        v29.m_pNext = v16->m_References.m_pHead;
        v17 = v16->m_References.m_pHead;
        if ( v17 != nullptr )
          v17->m_pPrev = &v29;
        v29.m_pPrev = nullptr;
        v16->m_References.m_pHead = &v29;
        LOBYTE(v31) = 7;
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
          this: pInside,
          elem: pInside->m_Size,
          src: &v29);
        LOBYTE(v31) = 3;
        if ( v29.m_pObject == nullptr )
          goto LABEL_57;
        if ( v29.m_pPrev != nullptr )
        {
          v29.m_pPrev->m_pNext = v29.m_pNext;
          if ( v29.m_pNext != nullptr )
          {
            v29.m_pNext->m_pPrev = v29.m_pPrev;
            memset(&v29, 0, sizeof(v29));
LABEL_57:
            nCount = pCarver->Faces.nCount;
            v25 = ++v5;
            if ( (int)v5 >= nCount )
              goto LABEL_58;
            v8 = v27;
            continue;
          }
        }
        else if ( v29.m_pObject->m_References.m_pHead == &v29 )
        {
          v29.m_pObject->m_References.m_pHead = v29.m_pNext;
          if ( v29.m_pNext != nullptr )
            v29.m_pNext->m_pPrev = nullptr;
        }
        break;
      }
      memset(&v29, 0, sizeof(v29));
      goto LABEL_57;
    }
  }
  if ( pOutside != nullptr )
  {
    v9 = this->Copy(this, a2: 0);
    src.m_pPrev = nullptr;
    src.m_pNext = nullptr;
    src.m_pObject = v9;
    if ( v9 != nullptr )
    {
      v10 = v9->m_References.m_pHead;
      src.m_pNext = v10;
      if ( v10 != nullptr )
        v10->m_pPrev = &src;
      src.m_pPrev = nullptr;
      v9->m_References.m_pHead = &src;
    }
    v31 = 0;
    CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
      this: pOutside,
      elem: pOutside->m_Size,
      &src);
    v31 = -1;
    if ( src.m_pObject != nullptr )
    {
      if ( src.m_pPrev != nullptr )
      {
        src.m_pPrev->m_pNext = src.m_pNext;
        if ( src.m_pNext != nullptr )
        {
          src.m_pNext->m_pPrev = src.m_pPrev;
          memset(&src, 0, sizeof(src));
          return 0;
        }
      }
      else if ( src.m_pObject->m_References.m_pHead == &src )
      {
        src.m_pObject->m_References.m_pHead = src.m_pNext;
        if ( src.m_pNext != nullptr )
          src.m_pNext->m_pPrev = nullptr;
      }
      memset(&src, 0, sizeof(src));
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101441B0
// Name: public: bool CMapSolid::Subtract(class CUtlReferenceVector<class CMapClass> __near *,class CUtlReferenceVector<class CMapClass> __near *,class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapSolid::Subtract(
        CMapSolid *this,
        CUtlReferenceVector<CMapClass> *pInside,
        CUtlReferenceVector<CMapClass> *pOutside,
        CMapClass *pSubtractWith)
{
  CUtlReference<CMapClass> *m_pHead; // eax
  CMapClass *i; // eax
  CMapClass *v6; // eax
  CUtlReference<CMapClass> *v7; // ecx
  int v8; // edx
  int v9; // ecx
  int v10; // eax
  int v11; // edi
  int v12; // edx
  CUtlReference<CMapClass> *v13; // ecx
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v15; // ecx
  CMapSolid *v16; // edx
  unsigned int v17; // eax
  int v18; // ecx
  unsigned int v19; // eax
  int v20; // ecx
  CUtlReferenceVector<CMapClass> *p_carve_in; // ecx
  CUtlReferenceVector<CMapClass> *p_carve_out; // eax
  CUtlReference<CMapClass> **m_pMemory; // edi
  int k; // esi
  int m; // esi
  CUtlReference<CMapClass> **v26; // edi
  int n; // esi
  int ii; // esi
  CUtlReference<CMapClass> **v29; // edi
  int jj; // esi
  int kk; // esi
  EnumChildrenPos_t pos; // [esp+Ch] [ebp-E8h] BYREF
  int j; // [esp+90h] [ebp-64h]
  int v35; // [esp+94h] [ebp-60h]
  CMapSolid *v36; // [esp+98h] [ebp-5Ch]
  int p; // [esp+9Ch] [ebp-58h]
  CUtlReferenceVector<CMapClass> carve_out; // [esp+A0h] [ebp-54h] BYREF
  CUtlReferenceVector<CMapClass> carve_in; // [esp+B4h] [ebp-40h] BYREF
  CUtlReferenceVector<CMapClass> SubList; // [esp+C8h] [ebp-2Ch] BYREF
  CUtlReference<CMapClass> src; // [esp+DCh] [ebp-18h] BYREF
  int v42; // [esp+F0h] [ebp-4h]
  char bIntersected_3; // [esp+107h] [ebp+13h]

  v36 = this;
  memset(&SubList, 0, 12);
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &SubList.m_Memory, nGrowSize: 0, nInitSize: 0);
  SubList.m_Size = 0;
  SubList.m_pElements = nullptr;
  v42 = 3;
  if ( pSubtractWith->IsMapClass(this: pSubtractWith, a2: CMapSolid::__Type) != 0 )
  {
    m_pHead = pSubtractWith->m_References.m_pHead;
    src.m_pPrev = nullptr;
    src.m_pObject = pSubtractWith;
    src.m_pNext = m_pHead;
    if ( m_pHead != nullptr )
      m_pHead->m_pPrev = &src;
    src.m_pPrev = nullptr;
    pSubtractWith->m_References.m_pHead = &src;
    LOBYTE(v42) = 4;
    CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
      this: &SubList,
      elem: 0,
      &src);
    LOBYTE(v42) = 3;
    if ( src.m_pObject != nullptr )
    {
      if ( src.m_pPrev != nullptr )
      {
        src.m_pPrev->m_pNext = src.m_pNext;
        if ( src.m_pNext != nullptr )
          src.m_pNext->m_pPrev = src.m_pPrev;
      }
      else if ( src.m_pObject->m_References.m_pHead == &src )
      {
        src.m_pObject->m_References.m_pHead = src.m_pNext;
        if ( src.m_pNext != nullptr )
          src.m_pNext->m_pPrev = nullptr;
      }
      memset(&src, 0, sizeof(src));
    }
  }
  for ( i = CMapClass::GetFirstDescendent(this: pSubtractWith, (CMapClass *)&pos);
        i != nullptr;
        i = CMapClass::GetNextDescendent(this: pSubtractWith, (CMapClass *)&pos) )
  {
    v6 = (CMapClass *)__RTDynamicCast(
                        inptr: i,
                        VfDelta: 0,
                        SrcType: &CMapClass `RTTI Type Descriptor',
                        TargetType: &CMapSolid `RTTI Type Descriptor',
                        isReference: 0);
    if ( v6 != nullptr )
    {
      v7 = v6->m_References.m_pHead;
      src.m_pPrev = nullptr;
      src.m_pObject = v6;
      src.m_pNext = v7;
      if ( v7 != nullptr )
        v7->m_pPrev = &src;
      src.m_pPrev = nullptr;
      v6->m_References.m_pHead = &src;
      LOBYTE(v42) = 5;
      CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
        this: &SubList,
        elem: SubList.m_Size,
        &src);
      LOBYTE(v42) = 3;
      if ( src.m_pObject != nullptr )
      {
        if ( src.m_pPrev != nullptr )
        {
          src.m_pPrev->m_pNext = src.m_pNext;
          if ( src.m_pNext != nullptr )
            src.m_pNext->m_pPrev = src.m_pPrev;
        }
        else if ( src.m_pObject->m_References.m_pHead == &src )
        {
          src.m_pObject->m_References.m_pHead = src.m_pNext;
          if ( src.m_pNext != nullptr )
            src.m_pNext->m_pPrev = nullptr;
        }
        memset(&src, 0, sizeof(src));
      }
    }
  }
  v8 = 0;
  bIntersected_3 = 0;
  p = 0;
  if ( SubList.m_Size > 0 )
  {
    v9 = (unsigned __int64)*((int *)&SubList.m_Memory + 2) >> 27;
    v10 = (32 * *((_DWORD *)&SubList.m_Memory + 2)) >> 5;
    v35 = v9;
    for ( j = v10; ; v10 = j )
    {
      v11 = v8 >> v9;
      v12 = v8 & v10;
      v13 = SubList.m_Memory.m_pMemory[v11];
      m_pObject = v13[v12].m_pObject;
      if ( m_pObject != nullptr )
      {
        src.m_pObject = v13[v12].m_pObject;
        src.m_pNext = m_pObject->m_References.m_pHead;
        v15 = m_pObject->m_References.m_pHead;
        if ( v15 != nullptr )
          v15->m_pPrev = &src;
        src.m_pPrev = nullptr;
        m_pObject->m_References.m_pHead = &src;
      }
      v16 = (CMapSolid *)src.m_pObject;
      LOBYTE(v42) = 3;
      if ( src.m_pObject != nullptr )
      {
        if ( src.m_pPrev != nullptr )
        {
          src.m_pPrev->m_pNext = src.m_pNext;
          if ( src.m_pNext != nullptr )
            src.m_pNext->m_pPrev = src.m_pPrev;
        }
        else if ( src.m_pObject->m_References.m_pHead == &src )
        {
          src.m_pObject->m_References.m_pHead = src.m_pNext;
          if ( src.m_pNext != nullptr )
            src.m_pNext->m_pPrev = nullptr;
        }
        memset(&src, 0, sizeof(src));
      }
      v17 = 15;
      carve_in.m_Memory.m_pMemory = nullptr;
      carve_in.m_Memory.m_nBlocks = 0;
      v18 = 16;
      *((_DWORD *)&carve_in.m_Memory + 2) = 15;
      do
      {
        v18 >>= 1;
        v17 = ((v17 & 0xF8000000) + 0x8000000) ^ v17 & 0x7FFFFFF;
        *((_DWORD *)&carve_in.m_Memory + 2) = v17;
      }
      while ( v18 > 1 );
      carve_in.m_Size = 0;
      carve_in.m_pElements = nullptr;
      LOBYTE(v42) = 10;
      v19 = 15;
      carve_out.m_Memory.m_pMemory = nullptr;
      carve_out.m_Memory.m_nBlocks = 0;
      v20 = 16;
      *((_DWORD *)&carve_out.m_Memory + 2) = 15;
      do
      {
        v20 >>= 1;
        v19 = ((v19 & 0xF8000000) + 0x8000000) ^ v19 & 0x7FFFFFF;
        *((_DWORD *)&carve_out.m_Memory + 2) = v19;
      }
      while ( v20 > 1 );
      carve_out.m_Size = 0;
      carve_out.m_pElements = nullptr;
      LOBYTE(v42) = 14;
      p_carve_in = nullptr;
      p_carve_out = nullptr;
      if ( pInside != nullptr )
        p_carve_in = &carve_in;
      if ( pOutside != nullptr )
        p_carve_out = &carve_out;
      bIntersected_3 |= CMapSolid::Carve(this: v36, pInside: p_carve_in, pOutside: p_carve_out, pCarver: v16);
      if ( pInside != nullptr )
      {
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::AddVectorToTail(
          this: pInside,
          src: &carve_in);
        CUtlReferenceVector<CMapClass>::RemoveAll(this: &carve_in);
      }
      if ( pOutside != nullptr )
      {
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::AddVectorToTail(
          this: pOutside,
          src: &carve_out);
        CUtlReferenceVector<CMapClass>::RemoveAll(this: &carve_out);
      }
      LOBYTE(v42) = 17;
      CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::RemoveAll(this: &carve_out);
      m_pMemory = carve_out.m_Memory.m_pMemory;
      if ( carve_out.m_Memory.m_pMemory != nullptr )
      {
        for ( k = 0; k < carve_out.m_Memory.m_nBlocks; ++k )
          free(pMem: m_pMemory[k]);
        carve_out.m_Memory.m_nBlocks = 0;
        free(pMem: m_pMemory);
        m_pMemory = nullptr;
        carve_out.m_Memory.m_pMemory = nullptr;
      }
      carve_out.m_pElements = nullptr;
      LOBYTE(v42) = 10;
      if ( m_pMemory != nullptr )
      {
        for ( m = 0; m < carve_out.m_Memory.m_nBlocks; ++m )
          free(pMem: m_pMemory[m]);
        carve_out.m_Memory.m_nBlocks = 0;
        free(pMem: m_pMemory);
        carve_out.m_Memory.m_pMemory = nullptr;
      }
      LOBYTE(v42) = 20;
      CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::RemoveAll(this: &carve_in);
      v26 = carve_in.m_Memory.m_pMemory;
      if ( carve_in.m_Memory.m_pMemory != nullptr )
      {
        for ( n = 0; n < carve_in.m_Memory.m_nBlocks; ++n )
          free(pMem: v26[n]);
        carve_in.m_Memory.m_nBlocks = 0;
        free(pMem: v26);
        v26 = nullptr;
        carve_in.m_Memory.m_pMemory = nullptr;
      }
      carve_in.m_pElements = nullptr;
      LOBYTE(v42) = 3;
      if ( v26 != nullptr )
      {
        for ( ii = 0; ii < carve_in.m_Memory.m_nBlocks; ++ii )
          free(pMem: v26[ii]);
        carve_in.m_Memory.m_nBlocks = 0;
        free(pMem: v26);
        carve_in.m_Memory.m_pMemory = nullptr;
      }
      v8 = p + 1;
      p = v8;
      if ( v8 >= SubList.m_Size )
        break;
      LOBYTE(v9) = v35;
    }
  }
  v42 = 23;
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::RemoveAll(this: &SubList);
  v29 = SubList.m_Memory.m_pMemory;
  if ( SubList.m_Memory.m_pMemory != nullptr )
  {
    for ( jj = 0; jj < SubList.m_Memory.m_nBlocks; ++jj )
      free(pMem: v29[jj]);
    SubList.m_Memory.m_nBlocks = 0;
    free(pMem: v29);
    v29 = nullptr;
    SubList.m_Memory.m_pMemory = nullptr;
  }
  SubList.m_pElements = nullptr;
  v42 = -1;
  if ( v29 != nullptr )
  {
    for ( kk = 0; kk < SubList.m_Memory.m_nBlocks; ++kk )
      free(pMem: v29[kk]);
    SubList.m_Memory.m_nBlocks = 0;
    free(pMem: v29);
    SubList.m_Memory.m_pMemory = nullptr;
  }
  return bIntersected_3;
}
