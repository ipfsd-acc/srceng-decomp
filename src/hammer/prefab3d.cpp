// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/prefab3d.cpp
// Functions: 19
// ============================================================

#include "hammer\prefab3d.h"

//------------------------------------------------------------------------------
// Address: 0x1008D8B0
// Name: public: virtual void CPrefab3D::FreeData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrefab3D::FreeData(CPrefab3D *this)
{
  CMapWorld *m_pWorld; // ecx

  m_pWorld = this->m_pWorld;
  if ( m_pWorld != nullptr )
    ((void (__thiscall *)(CMapWorld *, int))m_pWorld->~CMapClass)(a1: m_pWorld, a2: 1);
  this->m_pWorld = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1008D8E0
// Name: public: virtual bool CPrefab3D::IsLoaded(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPrefab3D::IsLoaded(CPrefab3D *this)
{
  return this->m_pWorld != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1008D8F0
// Name: private: int CPrefabRMF::DoLoad(class std::basic_fstream<char,struct std::char_traits<char>> __near &,unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPrefabRMF::DoLoad(CPrefabRMF *this, std::fstream *file, char dwFlags)
{
  CMapWorld *m_pWorld; // ecx
  CMapWorld *v5; // eax
  CMapWorld *v6; // ecx
  int v7; // eax
  CHistory *History; // eax
  CHistory *v10; // eax

  GetHistory()->bPaused = 1;
  CPrefab::AddMRU(pPrefab: (CObject *)this);
  m_pWorld = this->m_pWorld;
  if ( m_pWorld != nullptr )
    ((void (__thiscall *)(CMapWorld *, int))m_pWorld->~CMapClass)(a1: m_pWorld, a2: 1);
  v5 = (CMapWorld *)operator new(nSize: 0x1140u);
  if ( v5 != nullptr )
    v6 = CMapWorld::CMapWorld(this: v5, pOwningDocument: nullptr);
  else
    v6 = nullptr;
  this->m_pWorld = v6;
  if ( (dwFlags & 1) != 0 )
    v7 = v6->SerializeMAP(this: v6, a2: file, a3: 0, a4: nullptr);
  else
    v7 = v6->SerializeRMF(this: v6, a2: file, a3: 0);
  if ( v7 == -1 )
  {
    History = GetHistory();
    if ( History->bPaused == 1 )
      History->bPaused = 0;
    return -1;
  }
  else
  {
    this->m_pWorld->CalcBounds(this: this->m_pWorld, a2: 1);
    v10 = GetHistory();
    if ( v10->bPaused == 1 )
      v10->bPaused = 0;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008DA00
// Name: public: int CPrefabRMF::Init(class std::basic_fstream<char,struct std::char_traits<char>> __near &,int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPrefabRMF::Init(CPrefabRMF *this, std::fstream *file, int bLoadNow, char dwFlags)
{
  int result; // eax

  result = 1;
  if ( bLoadNow != 0 )
    result = CPrefabRMF::DoLoad(this, file, dwFlags);
  if ( this->szName[0] == 0 )
    strcpy(this->szName, "Prefab");
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008DA50
// Name: public: int CPrefabRMF::Save(class std::basic_fstream<char,struct std::char_traits<char>> __near &,unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPrefabRMF::Save(CPrefabRMF *this, std::fstream *file, char dwFlags)
{
  CMapWorld *m_pWorld; // ecx

  if ( this->IsLoaded(this) || this->Load(this, a2: 0) != -1 )
  {
    m_pWorld = this->m_pWorld;
    if ( (dwFlags & 1) != 0 )
      return m_pWorld->SerializeMAP(this: m_pWorld, a2: file, a3: 1, a4: nullptr);
    else
      return m_pWorld->SerializeRMF(this: m_pWorld, a2: file, a3: 1);
  }
  else
  {
    AfxMessageBox(lpszText: "Couldn't Load prefab to Save it.", nType: 0, nIDHelp: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008DAC0
// Name: public: virtual bool CPrefabVMF::IsLoaded(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPrefabVMF::IsLoaded(CPrefabVMF *this)
{
  _stat64i32 info; // [esp+4h] [ebp-30h] BYREF

  return this->m_pWorld != nullptr
      && (_stat64i32(name: this->m_szFilename, buf: &info) != 0 || info.st_mtime <= this->m_nFileTime);
}

//------------------------------------------------------------------------------
// Address: 0x1008DB10
// Name: protected: static enum ChunkFileResult_t CPrefabVMF::LoadEntityCallback(class CChunkFile __near *,class CPrefabVMF __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CPrefabVMF::LoadEntityCallback(CChunkFile *pFile, CPrefabVMF *pPrefab)
{
  CMapEntity *v2; // eax
  CMapEntity *v3; // esi

  v2 = (CMapEntity *)operator new(nSize: 0x184u);
  v3 = nullptr;
  if ( v2 != nullptr )
    v3 = CMapEntity::CMapEntity(this: v2);
  if ( CMapEntity::LoadVMF(this: v3, pFile) == ChunkFile_Ok )
    pPrefab->m_pWorld->AddChild(this: pPrefab->m_pWorld, a2: v3);
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x1008DB90
// Name: protected: static enum ChunkFileResult_t CPrefabVMF::LoadWorldCallback(class CChunkFile __near *,class CPrefabVMF __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CPrefabVMF::LoadWorldCallback(CChunkFile *pFile, CPrefabVMF *pPrefab)
{
  return CMapWorld::LoadVMF(this: pPrefab->m_pWorld, pFile);
}

//------------------------------------------------------------------------------
// Address: 0x1008DBB0
// Name: public: void CPrefabVMF::SetFilename(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrefabVMF::SetFilename(CPrefabVMF *this, const char *szFilename)
{
  _splitpath(path: szFilename, drive: nullptr, dir: nullptr, fname: this->szName, ext: nullptr);
  strcpy(this->m_szFilename, szFilename);
}

//------------------------------------------------------------------------------
// Address: 0x1008DBF0
// Name: public: virtual CPrefab3D::~CPrefab3D(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrefab3D::~CPrefab3D(CPrefab3D *this)
{
  CMapWorld *m_pWorld; // ecx

  this->__vftable = (CPrefab3D_vtbl *)&CPrefab3D::`vftable';
  m_pWorld = this->m_pWorld;
  if ( m_pWorld != nullptr )
    ((void (__thiscall *)(CMapWorld *, int))m_pWorld->~CMapClass)(a1: m_pWorld, a2: 1);
  this->m_pWorld = nullptr;
  CPrefab::~CPrefab(this);
}

//------------------------------------------------------------------------------
// Address: 0x1008DC60
// Name: public: CPrefabRMF::CPrefabRMF(void)
// Source: json
//------------------------------------------------------------------------------
CPrefabRMF *__thiscall CPrefabRMF::CPrefabRMF(CPrefabRMF *this)
{
  CPrefab::CPrefab(this);
  this->__vftable = (CPrefabRMF_vtbl *)&CPrefab3D::`vftable';
  this->m_pWorld = nullptr;
  this->__vftable = (CPrefabRMF_vtbl *)&CPrefabRMF::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008DCC0
// Name: public: CPrefabVMF::CPrefabVMF(void)
// Source: json
//------------------------------------------------------------------------------
CPrefabVMF *__thiscall CPrefabVMF::CPrefabVMF(CPrefabVMF *this)
{
  CPrefab::CPrefab(this);
  this->__vftable = (CPrefabVMF_vtbl *)&CPrefab3D::`vftable';
  this->m_pWorld = nullptr;
  this->__vftable = (CPrefabVMF_vtbl *)&CPrefabVMF::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008DD20
// Name: public: virtual int CPrefabVMF::Load(unsigned long)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPrefabVMF::Load(CPrefabVMF *this, unsigned int dwFlags)
{
  CMapWorld *m_pWorld; // ecx
  CMapWorld *v4; // eax
  CMapWorld *v5; // eax
  int v6; // esi
  ChunkFileResult_t v7; // eax
  CChunkFile File; // [esp+Ch] [ebp-390h] BYREF
  _stat64i32 info; // [esp+350h] [ebp-4Ch] BYREF
  void *p; // [esp+380h] [ebp-1Ch]
  CChunkHandlerMap Handlers; // [esp+384h] [ebp-18h] BYREF
  int v13; // [esp+398h] [ebp-4h]

  m_pWorld = this->m_pWorld;
  if ( m_pWorld != nullptr )
    ((void (__thiscall *)(CMapWorld *, int))m_pWorld->~CMapClass)(a1: m_pWorld, a2: 1);
  v4 = (CMapWorld *)operator new(nSize: 0x1140u);
  p = v4;
  v13 = 0;
  if ( v4 != nullptr )
    v5 = CMapWorld::CMapWorld(this: v4, pOwningDocument: nullptr);
  else
    v5 = nullptr;
  v13 = -1;
  this->m_pWorld = v5;
  CChunkFile::CChunkFile(this: &File);
  v13 = 1;
  v6 = CChunkFile::Open(this: &File, pszFileName: this->m_szFilename, eMode: ChunkFile_Read);
  if ( v6 == 0 )
  {
    CTextureReference::CTextureReference(this: (CTextureReference *)&Handlers);
    LOBYTE(v13) = 2;
    CChunkHandlerMap::AddHandler(
      this: &Handlers,
      pszChunkName: "world",
      pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CPrefabVMF::LoadWorldCallback,
      pData: this);
    CChunkHandlerMap::AddHandler(
      this: &Handlers,
      pszChunkName: "entity",
      pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CPrefabVMF::LoadEntityCallback,
      pData: this);
    CChunkFile::PushHandlers(this: &File, pHandlerMap: &Handlers);
    do
    {
      v7 = CChunkFile::ReadChunk(this: &File, pfnKeyHandler: nullptr, pData: nullptr);
      v6 = v7;
    }
    while ( v7 == ChunkFile_Ok );
    if ( v7 == ChunkFile_EOF )
      v6 = 0;
    CChunkFile::PopHandlers(this: &File);
    LOBYTE(v13) = 1;
    CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
    if ( v6 == 0 )
    {
      CMapWorld::PostloadWorld(this: this->m_pWorld);
      this->m_pWorld->CalcBounds(this: this->m_pWorld, a2: 0);
      CChunkFile::Close(this: &File);
      if ( _stat64i32(name: this->m_szFilename, buf: &info) == 0 )
        this->m_nFileTime = info.st_mtime;
    }
  }
  v13 = -1;
  CChunkFile::~CChunkFile(this: &File);
  return v6 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008E050
// Name: public: virtual int CPrefabRMF::Load(unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPrefabRMF::Load(CPrefabRMF *this, char dwFlags)
{
  CPrefabLibrary *ID; // eax
  char *v4; // eax
  std::fstream *v6; // edi
  std::fpos<int> v7; // [esp-18h] [ebp-24h] BYREF

  ID = CPrefabLibrary::FindID(dwID: this->dwLibID);
  v4 = (char *)__RTDynamicCast(
                 inptr: ID,
                 VfDelta: 0,
                 SrcType: &CPrefabLibrary `RTTI Type Descriptor',
                 TargetType: &CPrefabLibraryRMF `RTTI Type Descriptor',
                 isReference: 0);
  if ( v4 == nullptr )
    return -1;
  v6 = (std::fstream *)(v4 + 576);
  LODWORD(v7._Myoff) = this->dwFileOffset;
  memset((char *)&v7._Myoff + 4, 0, 16);
  std::istream::seekg(this: (std::istream *)(v4 + 576), _Pos: v7);
  return CPrefabRMF::DoLoad(this, file: v6, dwFlags);
}

//------------------------------------------------------------------------------
// Address: 0x1008E0D0
// Name: public: class CMapClass __near * CPrefab3D::Create(void)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__thiscall CPrefab3D::Create(CPrefab3D *this)
{
  CMapWorld *m_pWorld; // eax
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v5; // ecx
  CMapWorld *v6; // edi
  CMapClass *v7; // esi
  CMapClass *v8; // eax
  CUtlReference<CMapClass> *m_pHead; // [esp+4h] [ebp-1Ch] BYREF
  CUtlReference<CMapClass> *v10; // [esp+8h] [ebp-18h]
  CMapWorld *v11; // [esp+Ch] [ebp-14h]
  void *p; // [esp+10h] [ebp-10h]
  int v13; // [esp+1Ch] [ebp-4h]

  if ( !this->IsLoaded(this) && this->Load(this, a2: 0) == -1 )
    return nullptr;
  m_pWorld = this->m_pWorld;
  if ( m_pWorld->m_Children.m_Size == 1 )
  {
    m_pObject = (*m_pWorld->m_Children.m_Memory.m_pMemory)->m_pObject;
    if ( m_pObject != nullptr )
    {
      v11 = (CMapWorld *)m_pObject;
      m_pHead = m_pObject->m_References.m_pHead;
      v5 = m_pObject->m_References.m_pHead;
      if ( v5 != nullptr )
        v5->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
      v10 = nullptr;
      m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
    }
    v6 = v11;
    v13 = -1;
    if ( v11 != nullptr )
    {
      if ( v10 != nullptr )
      {
        v10->m_pNext = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = v10;
      }
      else if ( (CUtlReference<CMapClass> **)v11->m_References.m_pHead == &m_pHead )
      {
        v11->m_References.m_pHead = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = nullptr;
      }
      v10 = nullptr;
      m_pHead = nullptr;
      v11 = nullptr;
    }
    v7 = v6->Copy(this: v6, a2: false);
  }
  else
  {
    v6 = this->m_pWorld;
    v8 = (CMapClass *)operator new(nSize: 0xE0u);
    v7 = v8;
    p = v8;
    v13 = 1;
    if ( v8 != nullptr )
    {
      CMapClass::CMapClass(this: v8);
      v7->__vftable = (CMapClass_vtbl *)&CMapGroup::`vftable';
      v7[1].__vftable = (CMapClass_vtbl *)1203982208;
      v7[1].m_nObjectID = 1203982208;
      LOBYTE(v13) = 1;
    }
    else
    {
      v7 = nullptr;
    }
    v13 = -1;
  }
  v7->CopyChildrenFrom(this: v7, a2: v6, a3: false);
  v7->CalcBounds(this: v7, a2: 0);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1008E250
// Name: public: class CMapClass __near * CPrefab3D::CreateAtPointAroundOrigin(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__thiscall CPrefab3D::CreateAtPointAroundOrigin(CPrefab3D *this, const Vector *point)
{
  CMapClass *result; // eax
  CMapClass *v3; // esi
  float z; // eax
  SelectionState_t v5; // edi
  void (__thiscall *DoTransform)(CMapAtom *, const VMatrix *); // edx
  VMatrix dst; // [esp+4h] [ebp-4Ch] BYREF
  Vector move; // [esp+44h] [ebp-Ch]

  result = CPrefab3D::Create(this);
  v3 = result;
  if ( result != nullptr )
  {
    z = point->z;
    *(_QWORD *)&move.x = *(_QWORD *)&point->x;
    move.z = z;
    v5 = CMapAtom::SetSelectionState(this: (CMapAtom *)&Options, eSelectionState: SELECT_NORMAL);
    MatrixSetIdentity(&dst);
    DoTransform = v3->DoTransform;
    dst.m[1][3] = move.y;
    dst.m[0][3] = move.x;
    dst.m[2][3] = move.z;
    DoTransform(this: v3, a2: &dst);
    v3->PostUpdate(this: v3, a2: Notify_Transform);
    CMapAtom::SetSelectionState(this: (CMapAtom *)&Options, eSelectionState: v5);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008E2F0
// Name: public: virtual class CMapClass __near * CPrefab3D::CreateInBox(class BoundBox __near *)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__thiscall CPrefab3D::CreateInBox(CPrefab3D *this, BoundBox *pBox)
{
  CMapClass *result; // eax
  CMapClass *v3; // esi
  SelectionState_t v4; // edi
  void (__thiscall *DoTransform)(CMapAtom *, const VMatrix *); // edx
  VMatrix dst; // [esp+4h] [ebp-88h] BYREF
  Vector NewSize; // [esp+44h] [ebp-48h] BYREF
  Vector center; // [esp+50h] [ebp-3Ch] BYREF
  Vector CurSize; // [esp+5Ch] [ebp-30h] BYREF
  Vector zero; // [esp+68h] [ebp-24h] BYREF
  Vector scale; // [esp+74h] [ebp-18h] BYREF
  Vector move; // [esp+80h] [ebp-Ch] BYREF

  result = CPrefab3D::Create(this);
  v3 = result;
  if ( result != nullptr )
  {
    BoundBox::GetBoundsSize(this: pBox, size: &NewSize);
    BoundBox::GetBoundsSize(this: &v3->m_Render2DBox, size: &CurSize);
    scale.x = NewSize.x / CurSize.x;
    scale.y = NewSize.y / CurSize.y;
    scale.z = NewSize.z / CurSize.z;
    memset(&zero, 0, sizeof(zero));
    CMapAtom::TransScale(this: v3, RefPoint: &zero, Scale: &scale);
    BoundBox::GetBoundsCenter(this: pBox, ptdest: &move);
    BoundBox::GetBoundsCenter(this: &v3->m_Render2DBox, ptdest: &center);
    move.x = move.x - center.x;
    move.y = move.y - center.y;
    move.z = move.z - center.z;
    v4 = CMapAtom::SetSelectionState(this: (CMapAtom *)&Options, eSelectionState: SELECT_NORMAL);
    MatrixSetIdentity(&dst);
    DoTransform = v3->DoTransform;
    dst.m[0][3] = move.x;
    dst.m[1][3] = move.y;
    dst.m[2][3] = move.z;
    DoTransform(this: v3, a2: &dst);
    v3->PostUpdate(this: v3, a2: Notify_Transform);
    CMapAtom::SetSelectionState(this: (CMapAtom *)&Options, eSelectionState: v4);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008E430
// Name: public: virtual int CPrefabRMF::Save(char const __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPrefabRMF::Save(CPrefabRMF *this, const char *pszFilename, char dwFlags)
{
  int v4; // esi
  std::fstream file; // [esp+4h] [ebp-C4h] BYREF
  int v7; // [esp+C4h] [ebp-4h]

  std::fstream::fstream(this: &file, _Filename: pszFilename, _Mode: 34, _Prot: 64, a5: 1);
  v7 = 0;
  v4 = CPrefabRMF::Save(this, &file, dwFlags);
  v7 = -1;
  std::fstream::~fstream<char,std::char_traits<char>>(this: (std::fstream *)file.gap70);
  v7 = -1;
  *(_DWORD *)file.gap70 = &std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor(_This: (std::ios_base *)file.gap70);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1008E4D0
// Name: public: int CPrefabRMF::Init(char const __near *,int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPrefabRMF::Init(CPrefabRMF *this, char *pszFilename, int bLoadNow, char dwFlags)
{
  int v5; // ebx
  std::fstream file; // [esp+Ch] [ebp-C4h] BYREF
  int v8; // [esp+CCh] [ebp-4h]

  std::fstream::fstream(this: &file, _Filename: pszFilename, _Mode: 33, _Prot: 64, a5: 1);
  v8 = 0;
  *(_QWORD *)this->szName = 0;
  *(_QWORD *)&this->szName[8] = 0;
  *(_QWORD *)&this->szName[16] = 0;
  *(_DWORD *)&this->szName[24] = 0;
  *(_WORD *)&this->szName[28] = 0;
  this->szName[30] = 0;
  strncpy(dest: (unsigned __int8 *)this->szName, source: (unsigned __int8 *)pszFilename, count: 0x1Eu);
  v5 = 1;
  if ( bLoadNow != 0 )
    v5 = CPrefabRMF::DoLoad(this, &file, dwFlags);
  if ( this->szName[0] == 0 )
    strcpy(this->szName, "Prefab");
  v8 = -1;
  std::fstream::~fstream<char,std::char_traits<char>>(this: (std::fstream *)file.gap70);
  v8 = -1;
  *(_DWORD *)file.gap70 = &std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor(_This: (std::ios_base *)file.gap70);
  return v5;
}
