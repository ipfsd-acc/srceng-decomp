// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapgroup.cpp
// Functions: 13
// ============================================================

#include "hammer\mapgroup.h"

//------------------------------------------------------------------------------
// Address: 0x1012E3F0
// Name: public: virtual char const __near * CMapGroup::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapGroup::GetType(CMapGroup *this)
{
  return CMapGroup::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x1012E400
// Name: public: virtual int CMapGroup::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapGroup::IsMapClass(CMapGroup *this, const char *Type)
{
  return Type == CMapGroup::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x1012E420
// Name: class CMapClass __near * CMapGroup_CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__cdecl CMapGroup_CreateObject()
{
  CMapClass *v0; // eax
  _DWORD *v1; // esi

  v0 = (CMapClass *)operator new(nSize: 0xE0u);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CMapClass::CMapClass(this: v0);
  *v1 = &CMapGroup::`vftable';
  v1[54] = 1203982208;
  v1[55] = 1203982208;
  return (CMapClass *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1012E4C0
// Name: public: virtual void CMapGroup::AddChild(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapGroup::AddChild(CMapGroup *this, CMapClass *pChild)
{
  float v3; // xmm1_4
  Vector2D mins; // [esp+8h] [ebp-10h] BYREF
  Vector2D maxs; // [esp+10h] [ebp-8h] BYREF

  pChild->SetRenderColor_2(this: pChild, a2: this->r, a3: this->g, a4: this->b);
  CMapClass::AddChild(this, pChild);
  this->GetRenderLogicalBox(this, a2: &mins, a3: &maxs);
  v3 = (float)(maxs.y + mins.y) * 0.5;
  this->m_vecLogicalPosition.x = (float)(maxs.x + mins.x) * 0.5;
  this->m_vecLogicalPosition.y = v3;
}

//------------------------------------------------------------------------------
// Address: 0x1012E540
// Name: public: virtual class CMapClass __near * CMapGroup::CopyFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__thiscall CMapGroup::CopyFrom(CMapGroup *this, CVisGroup *pobj, bool bUpdateDependencies)
{
  return CMapClass::CopyFrom(this, pFrom: pobj, bUpdateDependencies);
}

//------------------------------------------------------------------------------
// Address: 0x1012E550
// Name: public: virtual class CMapClass __near * CMapGroup::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__thiscall CMapGroup::Copy(CMapGroup *this, int bUpdateDependencies)
{
  CMapClass *v3; // eax
  _DWORD *v4; // esi
  _DWORD *v5; // ecx

  v3 = (CMapClass *)operator new(nSize: 0xE0u);
  v4 = &v3->__vftable;
  if ( v3 != nullptr )
  {
    CMapClass::CMapClass(this: v3);
    *v4 = &CMapGroup::`vftable';
    v4[54] = 1203982208;
    v4[55] = 1203982208;
    v5 = v4;
  }
  else
  {
    v5 = nullptr;
  }
  return (*(CMapClass *(__thiscall **)(_DWORD *, CMapGroup *, int))(*v5 + 216))(
           a1: v5,
           a2: this,
           a3: bUpdateDependencies);
}

//------------------------------------------------------------------------------
// Address: 0x1012E5F0
// Name: public: virtual class Vector2D const __near & CMapGroup::GetLogicalPosition(void)
// Source: json
//------------------------------------------------------------------------------
const Vector2D *__thiscall CMapGroup::GetLogicalPosition(CMapGroup *this)
{
  return &this->m_vecLogicalPosition;
}

//------------------------------------------------------------------------------
// Address: 0x1012E600
// Name: public: enum ChunkFileResult_t CMapGroup::LoadVMF(class CChunkFile __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CMapGroup::LoadVMF(CMapGroup *this, CChunkFile *pFile)
{
  ChunkFileResult_t Chunk; // esi
  CChunkHandlerMap Handlers; // [esp+8h] [ebp-18h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  CTextureReference::CTextureReference(this: (CTextureReference *)&Handlers);
  v6 = 0;
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "editor",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapClass::LoadEditorCallback,
    pData: this);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &Handlers);
  Chunk = CChunkFile::ReadChunk(
            this: pFile,
            pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CMapClass::LoadEditorKeyCallback,
            pData: this);
  CChunkFile::PopHandlers(this: pFile);
  v6 = -1;
  CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  return Chunk;
}

//------------------------------------------------------------------------------
// Address: 0x1012E690
// Name: public: virtual enum ChunkFileResult_t CMapGroup::SaveVMF(class CChunkFile __near *,class CSaveInfo __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CMapGroup::SaveVMF(CMapGroup *this, CChunkFile *pFile, CSaveInfo *pSaveInfo)
{
  ChunkFileResult_t result; // eax

  if ( !CSaveInfo::ShouldSaveObject(this: pSaveInfo, pObject: this) )
    return ChunkFile_Ok;
  result = CChunkFile::BeginChunk(this: pFile, pszChunkName: "group");
  if ( result == ChunkFile_Ok )
  {
    result = CChunkFile::WriteKeyValueInt(this: pFile, pszKey: "id", nValue: this->m_nID);
    if ( result == ChunkFile_Ok )
    {
      result = CMapClass::SaveVMF(this, pFile, pSaveInfo);
      if ( result == ChunkFile_Ok )
        return CChunkFile::EndChunk(this: pFile);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012E700
// Name: public: virtual char const __near * CMapGroup::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapGroup::GetDescription(CMapGroup *this)
{
  sprintf(string: szBuf_0, format: "group of %d objects", this->m_Children.m_Size);
  return szBuf_0;
}

//------------------------------------------------------------------------------
// Address: 0x1012E720
// Name: public: virtual void CMapGroup::SetLogicalPosition(class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapGroup::SetLogicalPosition(CMapGroup *this, const Vector2D *vecPosition)
{
  const Vector2D *v3; // ecx
  float x; // xmm1_4
  int v5; // ebx
  CMapClass *m_pObject; // esi
  float *v7; // eax
  void (__thiscall *SetLogicalPosition)(CMapClass *, const Vector2D *); // edx
  float v9[2]; // [esp+0h] [ebp-10h] BYREF
  float v10; // [esp+8h] [ebp-8h]
  float v11; // [esp+Ch] [ebp-4h]

  if ( this->m_vecLogicalPosition.x == 99999.0 || this->m_vecLogicalPosition.y == 99999.0 )
    goto LABEL_7;
  v3 = vecPosition;
  x = this->m_vecLogicalPosition.x;
  if ( x != vecPosition->x || this->m_vecLogicalPosition.y != vecPosition->y )
  {
    v10 = vecPosition->x - x;
    v5 = 0;
    v11 = vecPosition->y - this->m_vecLogicalPosition.y;
    if ( this->m_Children.m_Size > 0 )
    {
      do
      {
        m_pObject = this->m_Children.m_Memory.m_pMemory[v5 >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][v5 & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
        v7 = (float *)m_pObject->GetLogicalPosition(this: m_pObject);
        SetLogicalPosition = m_pObject->SetLogicalPosition;
        v9[0] = *v7 + v10;
        v9[1] = v7[1] + v11;
        SetLogicalPosition(this: m_pObject, a2: (const Vector2D *)v9);
        ++v5;
      }
      while ( v5 < this->m_Children.m_Size );
LABEL_7:
      v3 = vecPosition;
    }
  }
  this->m_vecLogicalPosition.x = v3->x;
  this->m_vecLogicalPosition.y = v3->y;
}

//------------------------------------------------------------------------------
// Address: 0x1012E840
// Name: public: virtual void CMapGroup::GetRenderLogicalBox(class Vector2D __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapGroup::GetRenderLogicalBox(CMapGroup *this, Vector2D *mins, Vector2D *maxs)
{
  int v4; // esi
  CMapClass *m_pObject; // ecx
  float y; // xmm1_4
  float x; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  Vector2D logicalMaxs; // [esp+0h] [ebp-10h] BYREF
  Vector2D logicalMins; // [esp+8h] [ebp-8h] BYREF

  mins->x = 99999.0;
  mins->y = 99999.0;
  v4 = 0;
  maxs->x = -99999.0;
  for ( maxs->y = -99999.0; v4 < this->m_Children.m_Size; maxs->y = v9 )
  {
    m_pObject = this->m_Children.m_Memory.m_pMemory[v4 >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][v4 & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
    m_pObject->GetRenderLogicalBox(this: m_pObject, a2: &logicalMins, a3: &logicalMaxs);
    y = logicalMins.y;
    if ( logicalMins.y > mins->y )
      y = mins->y;
    x = mins->x;
    if ( logicalMins.x <= mins->x )
      x = logicalMins.x;
    mins->y = y;
    v8 = logicalMaxs.y;
    mins->x = x;
    v9 = maxs->y;
    if ( v9 <= v8 )
      v9 = v8;
    v10 = maxs->x;
    if ( maxs->x <= logicalMaxs.x )
      v10 = logicalMaxs.x;
    ++v4;
    maxs->x = v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012E930
// Name: public: virtual void CMapGroup::AddVisGroup(class CVisGroup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapGroup::AddVisGroup(CMapGroup *this, CVisGroup *pVisGroup)
{
  int i; // esi
  CMapClass *m_pObject; // ecx

  for ( i = 0; i < this->m_Children.m_Size; ++i )
  {
    m_pObject = this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
    m_pObject->AddVisGroup(this: m_pObject, a2: pVisGroup);
  }
}
