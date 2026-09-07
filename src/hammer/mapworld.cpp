// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapworld.cpp
// Functions: 69
// ============================================================

#include "hammer\mapworld.h"

//------------------------------------------------------------------------------
// Address: 0x10017C70
// Name: public: void CUtlReferenceVector<class CMapClass>::FastRemove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlReferenceVector<CMapClass>::FastRemove(CUtlReferenceVector<CMapClass> *this, int elem)
{
  int m_Size; // eax
  int v4; // esi
  int v5; // ecx
  int v6; // eax
  CMapClass *m_pObject; // ebx
  CUtlReference<CSheet> *v8; // esi
  CUtlIntrusiveDList<CUtlReference<CSheet> > *p_m_References; // eax
  CUtlReference<CMapClass> *m_pHead; // eax
  CUtlReference<CSheet> *v11; // esi
  CUtlIntrusiveDList<CUtlReference<CSheet> > *v12; // eax

  m_Size = this->m_Size;
  if ( m_Size > 0 )
  {
    v4 = m_Size - 1;
    if ( elem != m_Size - 1 )
    {
      v5 = *((_DWORD *)&this->m_Memory + 2);
      v6 = (32 * v5) >> 5;
      v5 >>= 27;
      m_pObject = this->m_Memory.m_pMemory[v4 >> v5][v4 & v6].m_pObject;
      v8 = (CUtlReference<CSheet> *)&this->m_Memory.m_pMemory[elem >> v5][elem & v6];
      p_m_References = &v8->m_pObject->m_References;
      if ( p_m_References != (CUtlIntrusiveDList<CUtlReference<CSheet> > *)m_pObject )
      {
        if ( p_m_References != nullptr )
        {
          CUtlIntrusiveDList<CUtlReference<CMapClass>>::RemoveNode(this: p_m_References + 8, which: v8);
          v8->m_pObject = nullptr;
        }
        v8->m_pObject = (CSheet *)m_pObject;
        if ( m_pObject != nullptr )
        {
          v8->m_pNext = (CUtlReference<CSheet> *)m_pObject->m_References.m_pHead;
          m_pHead = m_pObject->m_References.m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = (CUtlReference<CMapClass> *)v8;
          v8->m_pPrev = nullptr;
          m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)v8;
        }
      }
    }
    v11 = (CUtlReference<CSheet> *)&this->m_Memory.m_pMemory[(this->m_Size - 1) >> (*((int *)&this->m_Memory + 2) >> 27)][(this->m_Size - 1) & ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5)];
    v12 = &v11->m_pObject->m_References;
    if ( v12 != nullptr )
    {
      CUtlIntrusiveDList<CUtlReference<CMapClass>>::RemoveNode(this: v12 + 8, which: v11);
      v11->m_pObject = nullptr;
    }
    --this->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017EC0
// Name: public: void CUtlReferenceVector<class CMapClass>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlReferenceVector<CMapClass>::RemoveAll(CUtlReferenceVector<CMapClass> *this)
{
  int i; // esi
  CUtlReference<CMapClass> *v3; // eax
  CMapClass *m_pObject; // ecx
  CUtlReference<CMapClass> *m_pPrev; // edx
  CUtlReference<CMapClass> *m_pNext; // edx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = &this->m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Memory + 2) >> 27)][i
                                                                                               & ((32
                                                                                                 * *((_DWORD *)&this->m_Memory + 2)) >> 5)];
    m_pObject = v3->m_pObject;
    if ( m_pObject != nullptr )
    {
      m_pPrev = v3->m_pPrev;
      if ( m_pPrev != nullptr )
      {
        m_pPrev->m_pNext = v3->m_pNext;
        if ( v3->m_pNext != nullptr )
          v3->m_pNext->m_pPrev = v3->m_pPrev;
      }
      else if ( m_pObject->m_References.m_pHead == v3 )
      {
        m_pNext = v3->m_pNext;
        m_pObject->m_References.m_pHead = v3->m_pNext;
        if ( m_pNext != nullptr )
          m_pNext->m_pPrev = nullptr;
      }
      v3->m_pPrev = nullptr;
      v3->m_pNext = nullptr;
      v3->m_pObject = nullptr;
    }
  }
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::RemoveAll(this);
}

//------------------------------------------------------------------------------
// Address: 0x10018380
// Name: public: CUtlReferenceVector<class CMapClass>::CUtlReferenceVector<class CMapClass>(void)
// Source: json
//------------------------------------------------------------------------------
CUtlReferenceVector<CMapClass> *__thiscall CUtlReferenceVector<CMapClass>::CUtlReferenceVector<CMapClass>(
        CUtlReferenceVector<CMapClass> *this)
{
  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nBlocks = 0;
  *((_DWORD *)&this->m_Memory + 2) = 0;
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &this->m_Memory, nGrowSize: 0, nInitSize: 0);
  this->m_Size = 0;
  this->m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100183E0
// Name: public: CUtlReferenceVector<class CMapClass>::~CUtlReferenceVector<class CMapClass>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlReferenceVector<CMapClass>::~CUtlReferenceVector<CMapClass>(CUtlReferenceVector<CMapClass> *this)
{
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this);
}

//------------------------------------------------------------------------------
// Address: 0x10019FF0
// Name: public: CUtlReferenceVector<class CMapEntity>::CUtlReferenceVector<class CMapEntity>(void)
// Source: json
//------------------------------------------------------------------------------
CUtlReferenceVector<CMapEntity> *__thiscall CUtlReferenceVector<CMapEntity>::CUtlReferenceVector<CMapEntity>(
        CUtlReferenceVector<CMapEntity> *this)
{
  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nBlocks = 0;
  *((_DWORD *)&this->m_Memory + 2) = 0;
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
    (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)this,
    nGrowSize: 0,
    nInitSize: 0);
  this->m_Size = 0;
  this->m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001A050
// Name: public: CUtlReferenceVector<class CMapEntity>::~CUtlReferenceVector<class CMapEntity>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlReferenceVector<CMapEntity>::~CUtlReferenceVector<CMapEntity>(
        CUtlReferenceVector<CMapEntity> *this)
{
  CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(this);
}

//------------------------------------------------------------------------------
// Address: 0x10030EF0
// Name: public: void CUtlReferenceVector<class CMapEntity>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlReferenceVector<CMapEntity>::RemoveAll(CUtlReferenceVector<CMapEntity> *this)
{
  int i; // esi
  CUtlReference<CMapEntity> *v3; // eax
  CMapEntity *m_pObject; // ecx
  CUtlReference<CMapEntity> *m_pPrev; // edx
  CUtlReference<CMapEntity> *m_pNext; // edx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = &this->m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Memory + 2) >> 27)][i
                                                                                               & ((32
                                                                                                 * *((_DWORD *)&this->m_Memory + 2)) >> 5)];
    m_pObject = v3->m_pObject;
    if ( m_pObject != nullptr )
    {
      m_pPrev = v3->m_pPrev;
      if ( m_pPrev != nullptr )
      {
        m_pPrev->m_pNext = v3->m_pNext;
        if ( v3->m_pNext != nullptr )
          v3->m_pNext->m_pPrev = v3->m_pPrev;
      }
      else if ( m_pObject->m_References.m_pHead == v3 )
      {
        m_pNext = v3->m_pNext;
        m_pObject->m_References.m_pHead = v3->m_pNext;
        if ( m_pNext != nullptr )
          m_pNext->m_pPrev = nullptr;
      }
      v3->m_pPrev = nullptr;
      v3->m_pNext = nullptr;
      v3->m_pObject = nullptr;
    }
  }
  CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::RemoveAll(this);
}

//------------------------------------------------------------------------------
// Address: 0x10049010
// Name: public: class CUtlReferenceVector<class CMapClass> const __near * CMapClass::GetChildren(void)
// Source: json
//------------------------------------------------------------------------------
const CUtlReferenceVector<CMapClass> *__thiscall CMapClass::GetChildren(CMapClass *this)
{
  return &this->m_Children;
}

//------------------------------------------------------------------------------
// Address: 0x100A27A0
// Name: public: class CUtlReferenceVector<class CMapClass> const __near * CSelection::GetList(void)
// Source: json
//------------------------------------------------------------------------------
const CUtlReferenceVector<CMapClass> *__thiscall CSelection::GetList(CSelection *this)
{
  return &this->m_SelectionList;
}

//------------------------------------------------------------------------------
// Address: 0x100A27B0
// Name: public: class CUtlReferenceVector<class CMapClass> const __near * CSelection::GetHitList(void)
// Source: json
//------------------------------------------------------------------------------
const CUtlReferenceVector<CMapClass> *__thiscall CSelection::GetHitList(CSelection *this)
{
  return &this->m_HitList;
}

//------------------------------------------------------------------------------
// Address: 0x100B47E0
// Name: public: class CUtlReferenceVector<class CMapEntity> __near * CTargetNameComboBox::GetSubEntityList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlReferenceVector<CMapEntity> *__thiscall CTargetNameComboBox::GetSubEntityList(
        CTargetNameComboBox *this,
        const char *pName)
{
  int v3; // eax
  CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  if ( pName == nullptr )
    return nullptr;
  search.key = pName;
  v3 = CUtlRBTree<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int,CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int>,int>>::Find(
         this: &this->m_EntityLists.m_Elements.m_Tree,
         &search);
  if ( v3 == -1 )
    return nullptr;
  else
    return this->m_EntityLists.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x101494C0
// Name: public: virtual char const __near * CMapWorld::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapWorld::GetType(CMapWorld *this)
{
  return CMapWorld::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x101494D0
// Name: public: virtual int CMapWorld::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapWorld::IsMapClass(CMapWorld *this, const char *Type)
{
  return Type == CMapWorld::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x101494F0
// Name: bool BoxesIntersect(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl BoxesIntersect(const Vector *mins1, const Vector *maxs1, const Vector *mins2, const Vector *maxs2)
{
  return mins2->x <= maxs1->x
      && mins1->x <= maxs2->x
      && mins2->y <= maxs1->y
      && mins1->y <= maxs2->y
      && mins2->z <= maxs1->z
      && mins1->z <= maxs2->z;
}

//------------------------------------------------------------------------------
// Address: 0x10149550
// Name: public: void CMapWorld::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapWorld::Init(CMapWorld *this)
{
  Vector pt; // [esp+8h] [ebp-Ch] BYREF

  BoundBox::ResetBounds(this: &this->m_Render2DBox);
  memset(&pt, 0, sizeof(pt));
  BoundBox::UpdateBounds(this: &this->m_Render2DBox, &pt);
  this->SetClass(this: &this->CEditGameClass, a2: "worldspawn", a3: false);
  this->m_pCullTree = nullptr;
  this->m_nNextFaceID = 1;
  this->m_pWorldDispMgr = CreateWorldEditDispMgr();
}

//------------------------------------------------------------------------------
// Address: 0x101495C0
// Name: public: virtual void CMapWorld::AddChild(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapWorld::AddChild(CMapWorld *this, CMapClass *pChild)
{
  CCullTreeNode *m_pCullTree; // ecx

  CMapClass::AddChild(this, pChild);
  m_pCullTree = this->m_pCullTree;
  if ( m_pCullTree != nullptr )
    CCullTreeNode::AddCullTreeObjectRecurse(this: m_pCullTree, pObject: pChild);
}

//------------------------------------------------------------------------------
// Address: 0x101495F0
// Name: public: virtual void CMapWorld::RemoveChild(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapWorld::RemoveChild(CMapWorld *this, CMapClass *pChild, bool bUpdateBounds)
{
  CCullTreeNode *m_pCullTree; // ecx

  CMapClass::RemoveChild(this, pChild, bUpdateBounds);
  m_pCullTree = this->m_pCullTree;
  if ( m_pCullTree != nullptr )
    CCullTreeNode::RemoveCullTreeObjectRecurse(this: m_pCullTree, pObject: pChild);
}

//------------------------------------------------------------------------------
// Address: 0x10149620
// Name: public: virtual class CMapEntity __near * CMapWorld::FindChildByKeyValue(char const __near *,char const __near *,bool __near *,class VMatrix __near *)
// Source: json
//------------------------------------------------------------------------------
CMapEntity *__thiscall CMapWorld::FindChildByKeyValue(
        CMapWorld *this,
        const char *key,
        const char *value,
        bool *bIsInInstance,
        VMatrix *InstanceMatrix)
{
  if ( bIsInInstance != nullptr )
    *bIsInInstance = false;
  return CMapClass::FindChildByKeyValue(this, key, value, bIsInInstance, InstanceMatrix);
}

//------------------------------------------------------------------------------
// Address: 0x10149650
// Name: protected: static enum ChunkFileResult_t CMapWorld::LoadGroupCallback(class CChunkFile __near *,class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapWorld::LoadGroupCallback(CChunkFile *pFile, CMapWorld *pWorld)
{
  CMapClass *v2; // eax
  CMapClass *v3; // esi
  ChunkFileResult_t VMF; // edi

  v2 = (CMapClass *)operator new(nSize: 0xE0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CMapClass::CMapClass(this: v2);
    v3->__vftable = (CMapClass_vtbl *)&CMapGroup::`vftable';
    v3[1].__vftable = (CMapClass_vtbl *)1203982208;
    v3[1].m_nObjectID = 1203982208;
  }
  else
  {
    v3 = nullptr;
  }
  VMF = CMapGroup::LoadVMF(this: (CMapGroup *)v3, pFile);
  if ( VMF == ChunkFile_Ok )
    pWorld->AddChild(this: pWorld, a2: v3);
  return VMF;
}

//------------------------------------------------------------------------------
// Address: 0x101496F0
// Name: protected: static enum ChunkFileResult_t CMapWorld::LoadKeyCallback(char const __near *,char const __near *,class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapWorld::LoadKeyCallback(const char *szKey, const char *szValue, CMapWorld *pWorld)
{
  if ( _V_stricmp(s1: szKey, s2: "id") != 0 )
  {
    if ( _V_stricmp(s1: szKey, s2: "mapversion") != 0 )
      pWorld->SetKeyValue(this: &pWorld->CEditGameClass, a2: szKey, a3: szValue);
    return ChunkFile_Ok;
  }
  else
  {
    pWorld->m_nID = atoi(nptr: szValue);
    return ChunkFile_Ok;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10149760
// Name: protected: static enum ChunkFileResult_t CMapWorld::LoadSolidCallback(class CChunkFile __near *,class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapWorld::LoadSolidCallback(CChunkFile *pFile, CMapWorld *pWorld)
{
  CMapSolid *v2; // eax
  CMapSolid *v3; // esi
  ChunkFileResult_t v4; // edi
  bool bValid; // [esp+Fh] [ebp-Dh] BYREF
  int v7; // [esp+18h] [ebp-4h]

  v2 = (CMapSolid *)operator new(nSize: 0x240u);
  v7 = 0;
  if ( v2 != nullptr )
    v3 = CMapSolid::CMapSolid(this: v2, Parent0: nullptr);
  else
    v3 = nullptr;
  v7 = -1;
  v4 = CMapSolid::LoadVMF(this: v3, pFile, &bValid);
  if ( v4 != ChunkFile_Ok || !bValid )
  {
    if ( v3 != nullptr )
      ((void (__thiscall *)(CMapSolid *, int))v3->~CMapClass)(a1: v3, a2: 1);
  }
  else if ( CMapClass::GetEditorKeyValue(this: v3, szKey: "cordonsolid") == nullptr )
  {
    pWorld->AddChild(this: pWorld, a2: v3);
    return ChunkFile_Ok;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10149820
// Name: public: virtual void CMapWorld::PresaveWorld(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapWorld::PresaveWorld(CMapWorld *this)
{
  CMapClass *i; // eax
  EnumChildrenPos_t pos; // [esp+4h] [ebp-84h] BYREF

  for ( i = CMapClass::GetFirstDescendent(this, &pos); i != nullptr; i = CMapClass::GetNextDescendent(this, &pos) )
    i->PresaveWorld(this: i);
}

//------------------------------------------------------------------------------
// Address: 0x10149870
// Name: AppendString
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall AppendString@<eax>(char *szSrc@<eax>, int nDestSize@<ecx>, char *szDest)
{
  unsigned int v4; // eax
  int v5; // ecx
  char *v6; // edi
  char *i; // eax

  v4 = strlen(szDest);
  v5 = nDestSize - v4 - 1;
  v6 = &szDest[v4];
  for ( i = &szDest[v4]; v5 > 0; ++szSrc )
  {
    if ( *szSrc == 0 )
      break;
    *i = *szSrc;
    --v5;
    ++i;
  }
  *i = 0;
  if ( *szSrc != 0 )
    *v6 = 0;
  return *szSrc == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101498C0
// Name: IncrementStringName
// Source: json
//------------------------------------------------------------------------------
void __usercall IncrementStringName(char *str@<edi>, int nMaxLength)
{
  int v2; // ebx
  int v3; // esi
  const char *v4; // esi
  int v5; // eax
  const char *v6; // [esp+0h] [ebp-Ch]

  v2 = std::char_traits<char>::length(str: v6);
  v3 = v2;
  if ( v2 <= 0 )
    goto LABEL_5;
  do
  {
    if ( isdigit(c: str[v3 - 1]) == 0 )
      break;
    --v3;
  }
  while ( v3 > 0 );
  if ( v3 == v2 )
  {
LABEL_5:
    V_strncat(pDest: str, pSrc: "1", destBufferSize: nMaxLength, max_chars_to_copy: -1);
  }
  else
  {
    v4 = &str[v3];
    v5 = V_atoi(str: v4);
    *v4 = 0;
    V_snprintf(pDest: str, maxLen: nMaxLength, pFormat: "%s%d", str, v5 + 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10149940
// Name: public: virtual bool CMapWorld::IsEditable(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapWorld::IsEditable(CMapWorld *this)
{
  CMapDoc *m_pOwningDocument; // eax

  m_pOwningDocument = this->m_pOwningDocument;
  return m_pOwningDocument == nullptr || m_pOwningDocument->m_bIsEditable;
}

//------------------------------------------------------------------------------
// Address: 0x10149960
// Name: public: virtual void CMapWorld::UpdateChild(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapWorld::UpdateChild(CMapWorld *this, CMapClass *pChild)
{
  CCullTreeNode *m_pCullTree; // ecx
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v5; // eax

  if ( !CMapClass::s_bLoadingVMF )
  {
    pChild->CalcBounds(this: pChild, a2: 1);
    this->CalcBounds(this, a2: 0);
    m_pCullTree = this->m_pCullTree;
    if ( m_pCullTree != nullptr )
      CCullTreeNode::UpdateCullTreeObjectRecurse(this: m_pCullTree, pObject: pChild);
    if ( !this->m_bTemporary && CMapDoc::m_pMapDoc != nullptr )
      CMapDoc::UpdateObject(this: CMapDoc::m_pMapDoc, pObject: pChild);
    if ( CMapDoc::m_nInLevelLoad == 0 )
    {
      ModuleState = AfxGetModuleState();
      CHammerDocTemplate::UpdateInstanceMap(
        this: (CHammerDocTemplate *)ModuleState->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl,
        pInstanceMapDoc: this->m_pOwningDocument);
      v5 = AfxGetModuleState();
      CHammerDocTemplate::UpdateInstanceMap(
        this: (CHammerDocTemplate *)v5->m_pCurrentWinApp[1].m_pModuleState,
        pInstanceMapDoc: this->m_pOwningDocument);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10149A00
// Name: protected: static enum ChunkFileResult_t CMapWorld::LoadHiddenCallback(class CChunkFile __near *,class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CMapWorld::LoadHiddenCallback(CChunkFile *pFile, CMapWorld *pWorld)
{
  ChunkFileResult_t Chunk; // edi
  CChunkHandlerMap Handlers; // [esp+8h] [ebp-18h] BYREF
  int v5; // [esp+1Ch] [ebp-4h]

  CTextureReference::CTextureReference(this: (CTextureReference *)&Handlers);
  v5 = 0;
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "solid",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapWorld::LoadSolidCallback,
    pData: pWorld);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &Handlers);
  Chunk = CChunkFile::ReadChunk(this: pFile, pfnKeyHandler: nullptr, pData: nullptr);
  CChunkFile::PopHandlers(this: pFile);
  v5 = -1;
  CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  return Chunk;
}

//------------------------------------------------------------------------------
// Address: 0x10149A90
// Name: public: enum ChunkFileResult_t CMapWorld::LoadVMF(class CChunkFile __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CMapWorld::LoadVMF(CMapWorld *this, CChunkFile *pFile)
{
  CEditGameClass *v3; // eax
  WCKeyValuesT<WCKVBase_Dict> *p_m_KeyValues; // esi
  const char *Value; // eax
  const char *v6; // eax
  const char *v7; // eax
  int v8; // ebx
  const char *v9; // eax
  int v10; // edi
  const char *v11; // eax
  int v12; // ebx
  void *v13; // esp
  int i; // edi
  const char *v15; // eax
  float v17[3]; // [esp+0h] [ebp-C4h] BYREF
  char temp[128]; // [esp+Ch] [ebp-B8h] BYREF
  Vector vWorldMins; // [esp+8Ch] [ebp-38h] BYREF
  Vector vWorldMaxs; // [esp+98h] [ebp-2Ch] BYREF
  ChunkFileResult_t eResult; // [esp+A4h] [ebp-20h]
  CChunkHandlerMap Handlers; // [esp+A8h] [ebp-1Ch] BYREF
  CFoW *pFoW; // [esp+B4h] [ebp-10h]
  int v24; // [esp+C0h] [ebp-4h]

  CTextureReference::CTextureReference(this: (CTextureReference *)&Handlers);
  v24 = 0;
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "solid",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapWorld::LoadSolidCallback,
    pData: this);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "hidden",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapWorld::LoadHiddenCallback,
    pData: this);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "group",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CMapWorld::LoadGroupCallback,
    pData: this);
  if ( this != nullptr )
    v3 = &this->CEditGameClass;
  else
    v3 = nullptr;
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "connections",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CEditGameClass::LoadConnectionsCallback,
    pData: v3);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &Handlers);
  eResult = CChunkFile::ReadChunk(
              this: pFile,
              pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CMapWorld::LoadKeyCallback,
              pData: this);
  CChunkFile::PopHandlers(this: pFile);
  p_m_KeyValues = &this->m_KeyValues;
  if ( WCKeyValuesT<WCKVBase_Dict>::GetValue(this: p_m_KeyValues, pszKey: "fow", piIndex: nullptr) != nullptr )
  {
    pFoW = CMapDoc::m_pMapDoc->m_pFoW;
    if ( pFoW != nullptr )
    {
      Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: p_m_KeyValues, pszKey: "m_vWorldMins", piIndex: nullptr);
      sscanf(string: Value, format: "%g %g %g", &vWorldMins, &vWorldMins.y, &vWorldMins.z);
      v6 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: p_m_KeyValues, pszKey: "m_vWorldMaxs", piIndex: nullptr);
      sscanf(string: v6, format: "%g %g %g", &vWorldMaxs, &vWorldMaxs.y, &vWorldMaxs.z);
      v7 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: p_m_KeyValues, pszKey: "m_nHorizontalGridSize", piIndex: nullptr);
      v8 = atoi(nptr: v7);
      v9 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: p_m_KeyValues, pszKey: "m_nVerticalGridSize", piIndex: nullptr);
      v10 = atoi(nptr: v9);
      CFoW::SetSize(this: pFoW, &vWorldMins, &vWorldMaxs, nHorizontalGridSize: v8, nVerticalGridSize: v10);
      if ( v10 == -1 )
      {
        v11 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: p_m_KeyValues, pszKey: "m_nGridZUnits", piIndex: nullptr);
        v12 = atoi(nptr: v11);
        v13 = alloca(4 * v12);
        for ( i = 0; i < v12; ++i )
        {
          sprintf(string: temp, format: "m_pVerticalLevels_%d", i);
          v15 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: p_m_KeyValues, pszKey: temp, piIndex: nullptr);
          v17[i] = atof(nptr: v15);
        }
        CFoW::SetCustomVerticalLevels(this: pFoW, pflHeightLevels: v17, nCount: v12);
      }
    }
  }
  v24 = -1;
  CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  return eResult;
}

//------------------------------------------------------------------------------
// Address: 0x10149CC0
// Name: int SortFuncCompareSaveOrder(class CUtlReference<class CMapClass> const __near *,class CUtlReference<class CMapClass> const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SortFuncCompareSaveOrder(const CUtlReference<CMapClass> *pClass1, const CUtlReference<CMapClass> *pClass2)
{
  CMapClass *m_pObject; // eax
  CMapClass *v3; // ecx
  int m_nLoadID; // edx
  int v5; // esi
  int m_nID; // eax
  int v8; // ecx

  m_pObject = pClass1->m_pObject;
  v3 = pClass2->m_pObject;
  m_nLoadID = m_pObject->m_nLoadID;
  v5 = v3->m_nLoadID;
  if ( m_nLoadID > v5 )
    return 1;
  if ( m_nLoadID < v5 )
    return -1;
  m_nID = m_pObject->m_nID;
  v8 = v3->m_nID;
  if ( m_nID > v8 )
    return 1;
  return (m_nID >= v8) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x10149D10
// Name: protected: void CMapWorld::CullTree_FreeNode(class CCullTreeNode __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapWorld::CullTree_FreeNode(CMapWorld *this, CCullTreeNode *pNode)
{
  int m_Size; // edi
  int i; // esi

  if ( pNode != nullptr )
  {
    m_Size = pNode->m_Children.m_Size;
    if ( m_Size != 0 )
    {
      for ( i = 0; i < m_Size; ++i )
        CMapWorld::CullTree_FreeNode(this, pNode: pNode->m_Children.m_Memory.m_pMemory[i]);
    }
    CCullTreeNode::~CCullTreeNode(this: pNode);
    operator delete(p: pNode);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10149D60
// Name: public: static bool CMapWorld::FaceID_FaceIDListsToString(char __near *,int,class CMapFaceIDList __near *,class CMapFaceIDList __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMapWorld::FaceID_FaceIDListsToString(
        char *pszList,
        int nSize,
        CMapFaceIDList *pFullFaceIDList,
        CMapFaceIDList *pPartialFaceIDList)
{
  int v5; // edi
  signed int v6; // eax
  signed int v7; // eax
  int v8; // edi
  char v9; // bl
  signed int v10; // eax
  char szID[64]; // [esp+4h] [ebp-40h] BYREF

  if ( pszList == nullptr )
    return 0;
  *pszList = 0;
  if ( pFullFaceIDList != nullptr )
  {
    v5 = 0;
    if ( pFullFaceIDList->m_Size > 0 )
    {
      do
      {
        itoa(val: pFullFaceIDList->m_Memory.m_pMemory[v5], buf: szID, radix: 10);
        v6 = strlen(pszList);
        if ( *pszList != 0 && pszList[v6 - 1] != 32 )
        {
          if ( v6 >= nSize - 1 )
            return 0;
          *(_WORD *)&pszList[v6] = 32;
        }
        if ( !AppendString(szSrc: szID, nDestSize: nSize, szDest: pszList) )
          return 0;
      }
      while ( ++v5 < pFullFaceIDList->m_Size );
    }
  }
  if ( pPartialFaceIDList == nullptr || pPartialFaceIDList->m_Size <= 0 )
    return 1;
  v7 = strlen(pszList);
  if ( *pszList != 0 && pszList[v7 - 1] != 32 )
  {
    if ( v7 >= nSize - 1 )
      return 0;
    *(_WORD *)&pszList[v7] = 32;
  }
  if ( AppendString(szSrc: "(", nDestSize: nSize, szDest: pszList) )
  {
    v8 = 0;
    v9 = 1;
    if ( pPartialFaceIDList->m_Size > 0 )
    {
      do
      {
        itoa(val: pPartialFaceIDList->m_Memory.m_pMemory[v8], buf: szID, radix: 10);
        if ( v9 == 0 )
        {
          v10 = strlen(pszList);
          if ( *pszList != 0 && pszList[v10 - 1] != 32 )
          {
            if ( v10 >= nSize - 1 )
              return 0;
            *(_WORD *)&pszList[v10] = 32;
          }
        }
        v9 = 0;
        if ( !AppendString(szSrc: szID, nDestSize: nSize, szDest: pszList) )
          return 0;
      }
      while ( ++v8 < pPartialFaceIDList->m_Size );
    }
    AppendString(szSrc: ")", nDestSize: nSize, szDest: pszList);
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10149EE0
// Name: public: static bool CMapWorld::FaceID_FaceListsToString(char __near *,int,class CMapFaceList __near *,class CMapFaceList __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CMapWorld::FaceID_FaceListsToString(
        char *pszList,
        int nSize,
        CMapFaceList *pFullFaceList,
        CMapFaceList *pPartialFaceList)
{
  int v5; // edi
  signed int v6; // eax
  signed int v7; // eax
  int v8; // edi
  char v9; // bl
  signed int v10; // eax
  char szID[64]; // [esp+4h] [ebp-40h] BYREF

  if ( pszList == nullptr )
    return 0;
  *pszList = 0;
  if ( pFullFaceList != nullptr )
  {
    v5 = 0;
    if ( pFullFaceList->m_Size > 0 )
    {
      do
      {
        itoa(val: pFullFaceList->m_Memory.m_pMemory[v5]->m_nFaceID, buf: szID, radix: 10);
        v6 = strlen(pszList);
        if ( *pszList != 0 && pszList[v6 - 1] != 32 )
        {
          if ( v6 >= nSize - 1 )
            return 0;
          *(_WORD *)&pszList[v6] = 32;
        }
        if ( !AppendString(szSrc: szID, nDestSize: nSize, szDest: pszList) )
          return 0;
      }
      while ( ++v5 < pFullFaceList->m_Size );
    }
  }
  if ( pPartialFaceList == nullptr || pPartialFaceList->m_Size <= 0 )
    return 1;
  v7 = strlen(pszList);
  if ( *pszList != 0 && pszList[v7 - 1] != 32 )
  {
    if ( v7 >= nSize - 1 )
      return 0;
    *(_WORD *)&pszList[v7] = 32;
  }
  if ( AppendString(szSrc: "(", nDestSize: nSize, szDest: pszList) )
  {
    v8 = 0;
    v9 = 1;
    if ( pPartialFaceList->m_Size > 0 )
    {
      do
      {
        itoa(val: pPartialFaceList->m_Memory.m_pMemory[v8]->m_nFaceID, buf: szID, radix: 10);
        if ( v9 == 0 )
        {
          v10 = strlen(pszList);
          if ( *pszList != 0 && pszList[v10 - 1] != 32 )
          {
            if ( v10 >= nSize - 1 )
              return 0;
            *(_WORD *)&pszList[v10] = 32;
          }
        }
        v9 = 0;
        if ( !AppendString(szSrc: szID, nDestSize: nSize, szDest: pszList) )
          return 0;
      }
      while ( ++v8 < pPartialFaceList->m_Size );
    }
    AppendString(szSrc: ")", nDestSize: nSize, szDest: pszList);
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1014A060
// Name: protected: void CMapWorld::CullTree_SplitNode(class CCullTreeNode __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapWorld::CullTree_SplitNode(CMapWorld *this, CCullTreeNode *pNode)
{
  float x; // xmm0_4
  float v4; // xmm4_4
  float z; // xmm3_4
  float y; // xmm5_4
  float v7; // xmm6_4
  float v8; // xmm3_4
  CCullTreeNode *v9; // eax
  int v10; // edi
  CCullTreeNode *v11; // esi
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  int m_Size; // eax
  int v16; // edi
  int i; // esi
  CCullTreeNode **m_pMemory; // edx
  Vector maxs2; // [esp+0h] [ebp-84h] BYREF
  Vector mins2; // [esp+Ch] [ebp-78h] BYREF
  Vector mins1; // [esp+18h] [ebp-6Ch]
  Vector maxs1; // [esp+24h] [ebp-60h]
  Vector Mins; // [esp+30h] [ebp-54h]
  Vector ChildMins; // [esp+3Ch] [ebp-48h] BYREF
  Vector ChildMaxs; // [esp+48h] [ebp-3Ch] BYREF
  Vector Maxs; // [esp+54h] [ebp-30h]
  Vector Mids; // [esp+60h] [ebp-24h]
  CMapWorld *v28; // [esp+6Ch] [ebp-18h]
  int nObjectCount; // [esp+70h] [ebp-14h]
  CMapClass *pObject; // [esp+74h] [ebp-10h]
  int v31; // [esp+80h] [ebp-4h]
  int nChild; // [esp+8Ch] [ebp+8h]

  x = pNode->bmaxs.x;
  v4 = pNode->bmins.x;
  z = pNode->bmaxs.z;
  y = pNode->bmins.y;
  v7 = pNode->bmins.z;
  Maxs.y = pNode->bmaxs.y;
  Maxs.z = z;
  v28 = this;
  Mins.x = v4;
  Mins.y = y;
  Mins.z = v7;
  Maxs.x = x;
  v8 = z - v7;
  if ( (float)(x - v4) > 1024.0 && (float)(Maxs.y - y) > 1024.0 && v8 > 1024.0 )
  {
    Mids.x = (float)(x + v4) * 0.5;
    Mids.y = (float)(Maxs.y + y) * 0.5;
    Mids.z = (float)(Maxs.z + v7) * 0.5;
    for ( nChild = 0; nChild < 8; ++nChild )
    {
      v9 = (CCullTreeNode *)operator new(nSize: 0x44u);
      nObjectCount = (int)v9;
      v10 = 0;
      v31 = 0;
      if ( v9 != nullptr )
        v11 = CCullTreeNode::CCullTreeNode(this: v9);
      else
        v11 = nullptr;
      v31 = -1;
      if ( (nChild & 1) != 0 )
      {
        ChildMins.x = Mins.x;
        v12 = Mids.x;
      }
      else
      {
        ChildMins.x = Mids.x;
        v12 = Maxs.x;
      }
      ChildMaxs.x = v12;
      if ( (nChild & 2) != 0 )
      {
        ChildMins.y = Mins.y;
        v13 = Mids.y;
      }
      else
      {
        ChildMins.y = Mids.y;
        v13 = Maxs.y;
      }
      ChildMaxs.y = v13;
      if ( (nChild & 4) != 0 )
      {
        ChildMins.z = Mins.z;
        v14 = Mids.z;
      }
      else
      {
        ChildMins.z = Mids.z;
        v14 = Maxs.z;
      }
      ChildMaxs.z = v14;
      BoundBox::UpdateBounds(this: v11, mins: &ChildMins, maxs: &ChildMaxs);
      CCullTreeNode::AddCullTreeChild(this: pNode, pChild: v11);
      m_Size = pNode->m_Objects.m_Size;
      mins1 = v11->bmins;
      maxs1 = v11->bmaxs;
      nObjectCount = m_Size;
      if ( m_Size > 0 )
      {
        do
        {
          pObject = pNode->m_Objects.m_Memory.m_pMemory[v10 >> ((unsigned __int64)*((int *)&pNode->m_Objects.m_Memory + 2) >> 27)][v10 & ((32 * *((_DWORD *)&pNode->m_Objects.m_Memory + 2)) >> 5)].m_pObject;
          CMapClass::GetCullBox(this: pObject, mins: &mins2, maxs: &maxs2);
          if ( mins2.x <= maxs1.x
            && mins1.x <= maxs2.x
            && mins2.y <= maxs1.y
            && mins1.y <= maxs2.y
            && mins2.z <= maxs1.z
            && mins1.z <= maxs2.z )
          {
            CCullTreeNode::AddCullTreeObject(this: v11, pObject);
          }
          ++v10;
        }
        while ( v10 < nObjectCount );
      }
    }
    CCullTreeNode::RemoveAllCullTreeObjects(this: pNode);
    v16 = pNode->m_Children.m_Size;
    for ( i = 0; i < v16; ++i )
    {
      m_pMemory = pNode->m_Children.m_Memory.m_pMemory;
      if ( m_pMemory[i]->m_Objects.m_Size >= 2 )
        CMapWorld::CullTree_SplitNode(this: v28, pNode: m_pMemory[i]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014A320
// Name: public: void CMapWorld::CullTree_Build(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapWorld::CullTree_Build(CMapWorld *this)
{
  int v2; // edi
  CCullTreeNode *v3; // eax
  CCullTreeNode *v4; // eax
  Vector BoxMins; // [esp+8h] [ebp-28h] BYREF
  Vector BoxMaxs; // [esp+14h] [ebp-1Ch] BYREF
  CCullTreeNode *v7; // [esp+20h] [ebp-10h]
  int v8; // [esp+2Ch] [ebp-4h]

  v2 = 0;
  if ( this->m_pCullTree != nullptr )
  {
    CMapWorld::CullTree_FreeNode(this, pNode: this->m_pCullTree);
    this->m_pCullTree = nullptr;
  }
  v3 = (CCullTreeNode *)operator new(nSize: 0x44u);
  v7 = v3;
  v8 = 0;
  if ( v3 != nullptr )
    v4 = CCullTreeNode::CCullTreeNode(this: v3);
  else
    v4 = nullptr;
  v8 = -1;
  this->m_pCullTree = v4;
  BoxMins.x = g_MIN_MAP_COORD;
  BoxMins.y = g_MIN_MAP_COORD;
  BoxMins.z = g_MIN_MAP_COORD;
  BoxMaxs.x = g_MAX_MAP_COORD;
  BoxMaxs.y = g_MAX_MAP_COORD;
  BoxMaxs.z = g_MAX_MAP_COORD;
  BoundBox::UpdateBounds(this: v4, mins: &BoxMins, maxs: &BoxMaxs);
  if ( this->m_Children.m_Size > 0 )
  {
    do
    {
      CCullTreeNode::AddCullTreeObject(
        this: this->m_pCullTree,
        pObject: this->m_Children.m_Memory.m_pMemory[v2 >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][v2 & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject);
      ++v2;
    }
    while ( v2 < this->m_Children.m_Size );
  }
  CMapWorld::CullTree_SplitNode(this, pNode: this->m_pCullTree);
}

//------------------------------------------------------------------------------
// Address: 0x1014A4A0
// Name: public: virtual void CMapWorld::OnUndoRedo(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CMapWorld::OnUndoRedo(CMapWorld *this)
{
  CMapWorld::CullTree_Build(this);
}

//------------------------------------------------------------------------------
// Address: 0x1014A4B0
// Name: public: class CMapFace __near * CMapWorld::FaceID_FaceForID(int)
// Source: json
//------------------------------------------------------------------------------
CMapFace *__thiscall CMapWorld::FaceID_FaceForID(CMapWorld *this, int nFaceID)
{
  CMapWorld *v2; // edi
  CMapClass *FirstDescendent; // eax
  __int16 *v4; // eax
  int v5; // esi
  BlockArray<CMapFace,6,86> *v6; // edi
  int v7; // ebx
  unsigned int v8; // edi
  BlockArray<CMapFace,6,86> *v9; // edx
  CMapFace *result; // eax
  EnumChildrenPos_t pos; // [esp+Ch] [ebp-94h] BYREF
  int v12; // [esp+90h] [ebp-10h]
  int nFaceCount; // [esp+94h] [ebp-Ch]
  CMapWorld *v14; // [esp+98h] [ebp-8h]
  BlockArray<CMapFace,6,86> *v15; // [esp+9Ch] [ebp-4h]

  v2 = this;
  v14 = this;
  FirstDescendent = CMapClass::GetFirstDescendent(this, &pos);
  if ( FirstDescendent == nullptr )
    return nullptr;
  while ( 1 )
  {
    v4 = (__int16 *)__RTDynamicCast(
                      inptr: FirstDescendent,
                      VfDelta: 0,
                      SrcType: &CMapClass `RTTI Type Descriptor',
                      TargetType: &CMapSolid `RTTI Type Descriptor',
                      isReference: 0);
    if ( v4 != nullptr )
    {
      v5 = 0;
      nFaceCount = v4[282];
      if ( nFaceCount > 0 )
        break;
    }
LABEL_17:
    FirstDescendent = CMapClass::GetNextDescendent(this: v2, &pos);
    if ( FirstDescendent == nullptr )
      return nullptr;
  }
  v6 = (BlockArray<CMapFace,6,86> *)(v4 + 108);
  v15 = (BlockArray<CMapFace,6,86> *)(v4 + 108);
  while ( 1 )
  {
    if ( v5 >= v6->nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v5, v6->nCount);
      v7 = v5 + 1;
      if ( v5 + 1 != v6->nCount )
      {
        v8 = v7 / 6;
        if ( 6 * (v7 / 6) < v7 )
          ++v8;
        if ( v8 != v15->nBlocks )
        {
          if ( v8 > 0x57 )
            _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
          BlockArray<CMapFace,6,86>::GetBlocks(this: v15, nNewBlocks: v8);
        }
        v9 = v15;
        v15->nCount = v7;
        v6 = v9;
      }
    }
    result = &v6->Blocks[v5 / 6][v5 % 6];
    if ( result->m_nFaceID == nFaceID )
      return result;
    v12 = ++v5;
    if ( v5 >= nFaceCount )
    {
      v2 = v14;
      goto LABEL_17;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014A600
// Name: protected: int CMapWorld::FindEntityBucket(class CMapEntity __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapWorld::FindEntityBucket(CMapWorld *this, CMapEntity *pEntity, int *pnIndex)
{
  int v3; // ebx
  CUtlReferenceVector<CMapEntity> *i; // edi
  CUtlReference<CMapClass> *m_pHead; // eax
  int result; // eax
  CUtlReference<CMapClass> src; // [esp+Ch] [ebp-18h] BYREF
  int v8; // [esp+20h] [ebp-4h]

  v3 = 0;
  for ( i = this->m_EntityListByName; ; ++i )
  {
    src.m_pPrev = nullptr;
    src.m_pNext = nullptr;
    src.m_pObject = pEntity;
    if ( pEntity != nullptr )
    {
      m_pHead = (CUtlReference<CMapClass> *)pEntity->m_References.m_pHead;
      src.m_pNext = m_pHead;
      if ( m_pHead != nullptr )
        m_pHead->m_pPrev = &src;
      src.m_pPrev = nullptr;
      pEntity->m_References.m_pHead = (CUtlReference<CMapEntity> *)&src;
    }
    v8 = 0;
    result = CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::Find(
               this: (CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *)i,
               &src);
    v8 = -1;
    if ( src.m_pObject != nullptr )
    {
      if ( src.m_pPrev != nullptr )
      {
        src.m_pPrev->m_pNext = src.m_pNext;
        if ( src.m_pNext != nullptr )
          src.m_pNext->m_pPrev = src.m_pPrev;
      }
      else if ( (CUtlReference<CMapClass> *)src.m_pObject[1].m_Dependents.m_Memory.m_pMemory == &src )
      {
        src.m_pObject[1].m_Dependents.m_Memory.m_pMemory = &src.m_pNext->m_pNext;
        if ( src.m_pNext != nullptr )
          src.m_pNext->m_pPrev = nullptr;
      }
      memset(&src, 0, sizeof(src));
    }
    if ( result != -1 )
      break;
    if ( ++v3 >= 200 )
      return result;
  }
  if ( pnIndex != nullptr )
    *pnIndex = result;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1014A710
// Name: public: void CMapWorld::FaceID_StringToFaceIDLists(class CMapFaceIDList __near *,class CMapFaceIDList __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapWorld::FaceID_StringToFaceIDLists(
        CMapWorld *this,
        CUtlMemory<vgui::TreeNode *,int> *pFullFaceList,
        CUtlMemory<vgui::TreeNode *,int> *pPartialFaceList,
        const char *pszValue)
{
  int v4; // esi
  const char *v6; // eax
  char v7; // cl
  char *i; // eax
  char v9; // bl
  char *v10; // ecx
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  int *v13; // ecx
  int v14; // eax
  int *v15; // ecx
  int v16; // eax
  int *v17; // ecx
  int v18; // eax
  int *v19; // eax
  char szVal[512]; // [esp+8h] [ebp-204h] BYREF
  int nFaceID; // [esp+208h] [ebp-4h]
  bool bInParens_3; // [esp+21Bh] [ebp+Fh]
  int nParens; // [esp+21Ch] [ebp+10h]

  v4 = 0;
  if ( pFullFaceList != nullptr )
    pFullFaceList[1].m_pMemory = nullptr;
  if ( pPartialFaceList != nullptr )
    pPartialFaceList[1].m_pMemory = nullptr;
  v6 = pszValue;
  if ( pszValue != nullptr )
  {
    do
    {
      v7 = *v6;
      v6[szVal - pszValue] = *v6;
      ++v6;
    }
    while ( v7 != 0 );
    nParens = 0;
    bInParens_3 = false;
    for ( i = strtok(string: szVal, control: " "); i != nullptr; i = strtok(string: nullptr, control: " ") )
    {
      v9 = 1;
      v10 = i;
      if ( *i != 0 )
      {
        do
        {
          if ( *v10 == 40 )
          {
            ++v4;
            *v10 = 0;
          }
          else if ( *v10 == 41 )
          {
            --v4;
            *v10 = 0;
          }
          else if ( v9 != 0 )
          {
            bInParens_3 = v4 > 0;
            i = v10;
            v9 = 0;
          }
          ++v10;
        }
        while ( *v10 != 0 );
        nParens = v4;
      }
      nFaceID = atoi(nptr: i);
      if ( bInParens_3 )
      {
        if ( pPartialFaceList != nullptr )
        {
          m_pMemory = (int)pPartialFaceList[1].m_pMemory;
          m_nAllocationCount = pPartialFaceList->m_nAllocationCount;
          if ( m_pMemory + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: pPartialFaceList, num: m_pMemory - m_nAllocationCount + 1);
          ++pPartialFaceList[1].m_pMemory;
          v13 = (int *)pPartialFaceList->m_pMemory;
          v14 = (int)pPartialFaceList[1].m_pMemory - m_pMemory - 1;
          pPartialFaceList[1].m_nAllocationCount = (int)pPartialFaceList->m_pMemory;
          if ( v14 > 0 )
            _V_memmove(dest: &v13[m_pMemory + 1], src: &v13[m_pMemory], count: 4 * v14);
          v15 = (int *)pPartialFaceList->m_pMemory;
LABEL_30:
          v19 = &v15[m_pMemory];
          if ( v19 != nullptr )
            *v19 = nFaceID;
          v4 = nParens;
        }
      }
      else if ( pFullFaceList != nullptr )
      {
        m_pMemory = (int)pFullFaceList[1].m_pMemory;
        v16 = pFullFaceList->m_nAllocationCount;
        if ( m_pMemory + 1 > v16 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: pFullFaceList, num: m_pMemory - v16 + 1);
        ++pFullFaceList[1].m_pMemory;
        v17 = (int *)pFullFaceList->m_pMemory;
        v18 = (int)pFullFaceList[1].m_pMemory - m_pMemory - 1;
        pFullFaceList[1].m_nAllocationCount = (int)pFullFaceList->m_pMemory;
        if ( v18 > 0 )
          _V_memmove(dest: &v17[m_pMemory + 1], src: &v17[m_pMemory], count: 4 * v18);
        v15 = (int *)pFullFaceList->m_pMemory;
        goto LABEL_30;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014A890
// Name: public: void CMapWorld::FaceID_StringToFaceLists(class CMapFaceList __near *,class CMapFaceList __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapWorld::FaceID_StringToFaceLists(
        CMapWorld *this,
        CUtlMemory<CCullTreeNode *,int> *pFullFaceList,
        CUtlMemory<CCullTreeNode *,int> *pPartialFaceList,
        const char *pszValue)
{
  int v5; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CMapFace **v8; // ecx
  int v9; // eax
  CMapFace **v10; // eax
  int v11; // eax
  int v12; // edi
  int v13; // eax
  CMapFace **v14; // ecx
  int v15; // eax
  CMapFace **v16; // eax
  int m_nGrowSize; // esi
  int v18; // esi
  CMapFaceIDList FullFaceIDList; // [esp+Ch] [ebp-38h] BYREF
  CMapFaceIDList PartialFaceIDList; // [esp+20h] [ebp-24h] BYREF
  CMapWorld *v21; // [esp+34h] [ebp-10h]
  int v22; // [esp+40h] [ebp-4h]
  CMapFace *pFace; // [esp+4Ch] [ebp+8h]
  CMapFace *pFacea; // [esp+4Ch] [ebp+8h]
  int i; // [esp+54h] [ebp+10h]
  int ia; // [esp+54h] [ebp+10h]

  v21 = this;
  memset(&FullFaceIDList, 0, sizeof(FullFaceIDList));
  v22 = 5;
  memset(&PartialFaceIDList, 0, sizeof(PartialFaceIDList));
  CMapWorld::FaceID_StringToFaceIDLists(
    this,
    pFullFaceList: (CUtlMemory<vgui::TreeNode *,int> *)&FullFaceIDList,
    pPartialFaceList: (CUtlMemory<vgui::TreeNode *,int> *)&PartialFaceIDList,
    pszValue);
  if ( pFullFaceList != nullptr )
  {
    v5 = 0;
    pFullFaceList[1].m_pMemory = nullptr;
    for ( i = 0; v5 < FullFaceIDList.m_Size; i = v5 )
    {
      pFace = CMapWorld::FaceID_FaceForID(this: v21, nFaceID: FullFaceIDList.m_Memory.m_pMemory[v5]);
      if ( pFace != nullptr )
      {
        m_pMemory = (int)pFullFaceList[1].m_pMemory;
        m_nAllocationCount = pFullFaceList->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<CVisGroup *,int>::Grow(this: pFullFaceList, num: m_pMemory - m_nAllocationCount + 1);
        ++pFullFaceList[1].m_pMemory;
        v8 = (CMapFace **)pFullFaceList->m_pMemory;
        v9 = (int)pFullFaceList[1].m_pMemory - m_pMemory - 1;
        pFullFaceList[1].m_nAllocationCount = (int)pFullFaceList->m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &v8[m_pMemory + 1], src: &v8[m_pMemory], count: 4 * v9);
        v10 = (CMapFace **)&pFullFaceList->m_pMemory[m_pMemory];
        if ( v10 != nullptr )
          *v10 = pFace;
      }
      v5 = i + 1;
    }
  }
  if ( pPartialFaceList != nullptr )
  {
    v11 = 0;
    pPartialFaceList[1].m_pMemory = nullptr;
    for ( ia = 0; v11 < PartialFaceIDList.m_Size; ia = v11 )
    {
      pFacea = CMapWorld::FaceID_FaceForID(this: v21, nFaceID: PartialFaceIDList.m_Memory.m_pMemory[v11]);
      if ( pFacea != nullptr )
      {
        v12 = (int)pPartialFaceList[1].m_pMemory;
        v13 = pPartialFaceList->m_nAllocationCount;
        if ( v12 + 1 > v13 )
          CUtlMemory<CVisGroup *,int>::Grow(this: pPartialFaceList, num: v12 - v13 + 1);
        ++pPartialFaceList[1].m_pMemory;
        v14 = (CMapFace **)pPartialFaceList->m_pMemory;
        v15 = (int)pPartialFaceList[1].m_pMemory - v12 - 1;
        pPartialFaceList[1].m_nAllocationCount = (int)pPartialFaceList->m_pMemory;
        if ( v15 > 0 )
          _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 4 * v15);
        v16 = (CMapFace **)&pPartialFaceList->m_pMemory[v12];
        if ( v16 != nullptr )
          *v16 = pFacea;
      }
      v11 = ia + 1;
    }
  }
  LOBYTE(v22) = 7;
  m_nGrowSize = PartialFaceIDList.m_Memory.m_nGrowSize;
  PartialFaceIDList.m_Size = 0;
  if ( PartialFaceIDList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( PartialFaceIDList.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: PartialFaceIDList.m_Memory.m_pMemory);
      PartialFaceIDList.m_Memory.m_pMemory = nullptr;
    }
    PartialFaceIDList.m_Memory.m_nAllocationCount = 0;
  }
  PartialFaceIDList.m_pElements = PartialFaceIDList.m_Memory.m_pMemory;
  LOBYTE(v22) = 2;
  if ( m_nGrowSize >= 0 )
  {
    if ( PartialFaceIDList.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: PartialFaceIDList.m_Memory.m_pMemory);
      PartialFaceIDList.m_Memory.m_pMemory = nullptr;
    }
    PartialFaceIDList.m_Memory.m_nAllocationCount = 0;
  }
  v22 = 9;
  v18 = FullFaceIDList.m_Memory.m_nGrowSize;
  FullFaceIDList.m_Size = 0;
  if ( FullFaceIDList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( FullFaceIDList.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: FullFaceIDList.m_Memory.m_pMemory);
      FullFaceIDList.m_Memory.m_pMemory = nullptr;
    }
    FullFaceIDList.m_Memory.m_nAllocationCount = 0;
  }
  FullFaceIDList.m_pElements = FullFaceIDList.m_Memory.m_pMemory;
  v22 = -1;
  if ( v18 >= 0 && FullFaceIDList.m_Memory.m_pMemory != nullptr )
    free(pMem: FullFaceIDList.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1014AAC0
// Name: AddUsedTextures
// Source: json
//------------------------------------------------------------------------------
int __cdecl AddUsedTextures(CMapSolid *pSolid, CUsedTextureList *pList)
{
  int v2; // ebx
  BlockArray<CMapFace,6,86> *p_Faces; // esi
  int v4; // edi
  unsigned int v5; // esi
  IEditorTexture *m_pTexture; // esi
  int m_Size; // ecx
  int v8; // eax
  UsedTexture_t *m_pMemory; // edx
  UsedTexture_t Tex; // [esp+0h] [ebp-18h] BYREF
  int v12; // [esp+8h] [ebp-10h]
  int nFaces; // [esp+Ch] [ebp-Ch]
  int nLastElement; // [esp+10h] [ebp-8h]
  IEditorTexture *pLastTex; // [esp+14h] [ebp-4h]
  BlockArray<CMapFace,6,86> *pSolida; // [esp+20h] [ebp+8h]

  if ( (*((_BYTE *)&pSolid->CMapClass + 180) & 2) != 0 )
  {
    v2 = 0;
    nFaces = pSolid->Faces.nCount;
    pLastTex = nullptr;
    nLastElement = 0;
    if ( nFaces > 0 )
    {
      p_Faces = &pSolid->Faces;
      pSolida = &pSolid->Faces;
      Tex.nUsageCount = 0;
      while ( 1 )
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
            if ( v5 != pSolida->nBlocks )
            {
              if ( v5 > 0x57 )
                _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
              BlockArray<CMapFace,6,86>::GetBlocks(this: pSolida, nNewBlocks: v5);
            }
            pSolida->nCount = v4;
            p_Faces = pSolida;
          }
        }
        m_pTexture = p_Faces->Blocks[v2 / 6u][v2 % 6u].m_pTexture;
        Tex.pTex = m_pTexture;
        if ( m_pTexture != nullptr )
        {
          if ( m_pTexture != pLastTex )
          {
            m_Size = pList->m_Size;
            v8 = 0;
            if ( m_Size <= 0 )
              goto LABEL_22;
            m_pMemory = pList->m_Memory.m_pMemory;
            while ( m_pMemory->pTex != m_pTexture )
            {
              ++v8;
              ++m_pMemory;
              if ( v8 >= m_Size )
                goto LABEL_22;
            }
            if ( v8 == -1 )
LABEL_22:
              v8 = CUtlVector<UsedTexture_t,CUtlMemory<UsedTexture_t,int>>::InsertBefore(
                     this: (CUtlVector<MCMSTRUCT,CUtlMemory<MCMSTRUCT,int> > *)pList,
                     elem: m_Size,
                     src: (const MCMSTRUCT *)&Tex);
            nLastElement = v8;
            pLastTex = m_pTexture;
          }
          ++pList->m_Memory.m_pMemory[nLastElement].nUsageCount;
        }
        v12 = ++v2;
        if ( v2 >= nFaces )
          break;
        p_Faces = pSolida;
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014AC10
// Name: AddOverlayTextures
// Source: json
//------------------------------------------------------------------------------
int __cdecl AddOverlayTextures(CMapOverlay *pOverlay, CUsedTextureList *pList)
{
  IEditorTexture *m_pTexture; // edi
  int v3; // eax
  int m_Size; // ecx
  UsedTexture_t *m_pMemory; // edx
  UsedTexture_t Tex; // [esp+0h] [ebp-8h] BYREF

  if ( (*((_BYTE *)&pOverlay->CMapClass + 180) & 2) != 0 )
  {
    m_pTexture = pOverlay->m_Material.m_pTexture;
    v3 = 0;
    Tex.pTex = m_pTexture;
    Tex.nUsageCount = 0;
    if ( m_pTexture != nullptr )
    {
      m_Size = pList->m_Size;
      if ( m_Size <= 0 )
        goto LABEL_9;
      m_pMemory = pList->m_Memory.m_pMemory;
      while ( m_pMemory->pTex != m_pTexture )
      {
        ++v3;
        ++m_pMemory;
        if ( v3 >= m_Size )
          goto LABEL_9;
      }
      if ( v3 == -1 )
LABEL_9:
        v3 = CUtlVector<UsedTexture_t,CUtlMemory<UsedTexture_t,int>>::InsertBefore(
               this: (CUtlVector<MCMSTRUCT,CUtlMemory<MCMSTRUCT,int> > *)pList,
               elem: m_Size,
               src: (const MCMSTRUCT *)&Tex);
      ++pList->m_Memory.m_pMemory[v3].nUsageCount;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014AC80
// Name: public: void CMapWorld::GetUsedTextures(class CUsedTextureList __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapWorld::GetUsedTextures(CMapWorld *this, CUsedTextureList *List)
{
  List->m_Size = 0;
  CMapClass::EnumChildren(
    this,
    pfn: (int (__cdecl *)(CMapClass *, unsigned int))AddUsedTextures,
    dwParam: (unsigned int)List,
    Type: CMapSolid::__Type);
  CMapClass::EnumChildren(
    this,
    pfn: (int (__cdecl *)(CMapClass *, unsigned int))AddOverlayTextures,
    dwParam: (unsigned int)List,
    Type: CMapOverlay::__Type);
}

//------------------------------------------------------------------------------
// Address: 0x1014ACC0
// Name: public: int CMapWorld::GetGroupList(class CUtlVector<class CMapGroup __near *,class CUtlMemory<class CMapGroup __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
CCullTreeNode **__thiscall CMapWorld::GetGroupList(CMapWorld *this, CUtlMemory<CCullTreeNode *,int> *GroupList)
{
  CMapClass *i; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CMapGroup **v5; // ecx
  int v6; // eax
  CMapGroup **v7; // eax
  EnumChildrenPos_t pos; // [esp+8h] [ebp-88h] BYREF
  CMapClass *v10; // [esp+8Ch] [ebp-4h]

  v10 = this;
  GroupList[1].m_pMemory = nullptr;
  for ( i = CMapClass::GetFirstDescendent(this, &pos); i != nullptr; i = CMapClass::GetNextDescendent(this: v10, &pos) )
  {
    if ( i->IsGroup(this: i) )
    {
      m_pMemory = (int)GroupList[1].m_pMemory;
      m_nAllocationCount = GroupList->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CVisGroup *,int>::Grow(this: GroupList, num: m_pMemory - m_nAllocationCount + 1);
      ++GroupList[1].m_pMemory;
      v5 = (CMapGroup **)GroupList->m_pMemory;
      v6 = (int)GroupList[1].m_pMemory - m_pMemory - 1;
      GroupList[1].m_nAllocationCount = (int)GroupList->m_pMemory;
      if ( v6 > 0 )
        _V_memmove(dest: &v5[m_pMemory + 1], src: &v5[m_pMemory], count: 4 * v6);
      v7 = (CMapGroup **)&GroupList->m_pMemory[m_pMemory];
      if ( v7 != nullptr )
        *v7 = (CMapGroup *)i;
    }
  }
  return GroupList[1].m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x1014AD70
// Name: protected: enum ChunkFileResult_t CMapWorld::SaveObjectListVMF(class CChunkFile __near *,class CSaveInfo __near *,class CUtlReferenceVector<class CMapClass> const __near *,int)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CMapWorld::SaveObjectListVMF(
        CMapWorld *this,
        CChunkFile *pFile,
        CSaveInfo *pSaveInfo,
        const CUtlReferenceVector<CMapClass> *pList,
        char saveFlags)
{
  const CUtlReferenceVector<CMapClass> *v5; // edx
  int v6; // edi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v8; // ecx
  void *v9; // esi
  const char *v10; // eax
  ChunkFileResult_t result; // eax
  CUtlReference<CMapClass> *m_pHead; // [esp+Ch] [ebp-18h] BYREF
  CUtlReference<CMapClass> *v13; // [esp+10h] [ebp-14h]
  void *inptr; // [esp+14h] [ebp-10h]
  int v15; // [esp+20h] [ebp-4h]
  int saveFlagsa; // [esp+38h] [ebp+14h]

  v5 = pList;
  v6 = 0;
  if ( pList->m_Size > 0 )
  {
    saveFlagsa = saveFlags & 1;
    do
    {
      m_pObject = v5->m_Memory.m_pMemory[v6 >> (*((int *)&v5->m_Memory + 2) >> 27)][v6
                                                                                  & ((32 * *((_DWORD *)&v5->m_Memory + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr )
      {
        inptr = v5->m_Memory.m_pMemory[v6 >> (*((int *)&v5->m_Memory + 2) >> 27)][v6
                                                                                & ((32 * *((_DWORD *)&v5->m_Memory + 2)) >> 5)].m_pObject;
        m_pHead = m_pObject->m_References.m_pHead;
        v8 = m_pObject->m_References.m_pHead;
        if ( v8 != nullptr )
          v8->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
        v13 = nullptr;
        m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
      }
      v9 = inptr;
      v15 = -1;
      if ( inptr != nullptr )
      {
        if ( v13 != nullptr )
        {
          v13->m_pNext = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = v13;
        }
        else if ( *((CUtlReference<CMapClass> ***)inptr + 8) == &m_pHead )
        {
          *((_DWORD *)inptr + 8) = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = nullptr;
        }
        v13 = nullptr;
        m_pHead = nullptr;
        inptr = nullptr;
      }
      if ( saveFlagsa != 0 )
      {
        v10 = (const char *)__RTDynamicCast(
                              inptr: v9,
                              VfDelta: 0,
                              SrcType: &CMapClass `RTTI Type Descriptor',
                              TargetType: &CMapEntity `RTTI Type Descriptor',
                              isReference: 0);
        if ( v10 == nullptr || strncmp(first: v10 + 252, last: "light", count: 5u) != 0 )
          goto LABEL_21;
        v5 = pList;
      }
      if ( v9 != nullptr )
      {
        result = (*(int (__thiscall **)(void *, CChunkFile *, CSaveInfo *))(*(_DWORD *)v9 + 232))(
                   a1: v9,
                   a2: pFile,
                   a3: pSaveInfo);
        if ( result != ChunkFile_Ok )
          return result;
LABEL_21:
        v5 = pList;
      }
      ++v6;
    }
    while ( v6 < v5->m_Size );
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x1014AEC0
// Name: public: class CMapEntity __near * CMapWorld::FindEntityByName(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
CMapEntity *__thiscall CMapWorld::FindEntityByName(
        CMapWorld *this,
        char *pszName,
        bool bVisiblesOnly,
        bool bSearchInstanceParms)
{
  CUtlReferenceVector<CMapEntity> *p_m_EntityList; // ebx
  int v7; // eax
  int m_Size; // edx
  int v9; // esi
  CMapEntity *m_pObject; // edi
  CUtlReferenceVector<CMapEntity> *v11; // esi
  int v12; // edi
  CMapEntity *v13; // eax
  CUtlReference<CMapEntity> *v14; // ecx
  CMapEntity *v15; // ebx
  unsigned __int16 Inorder; // si
  UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  int v18; // edx
  unsigned __int8 *szValue; // edi
  int v20; // eax
  CUtlReference<CMapEntity> *m_pHead; // [esp+8h] [ebp-20h] BYREF
  CUtlReference<CMapEntity> *v22; // [esp+Ch] [ebp-1Ch]
  CMapEntity *v23; // [esp+10h] [ebp-18h]
  int nCount; // [esp+14h] [ebp-14h]
  CUtlReferenceVector<CMapEntity> *v25; // [esp+18h] [ebp-10h]
  int v26; // [esp+24h] [ebp-4h]
  int pos; // [esp+34h] [ebp+Ch]

  if ( pszName == nullptr )
    return nullptr;
  p_m_EntityList = &this->m_EntityList;
  v25 = &this->m_EntityList;
  strchr(string: (unsigned __int8 *)pszName, chr: 0x2Au);
  if ( v7 == 0 )
    p_m_EntityList = &this->m_EntityListByName[HashStringCaseless(pszKey: pszName) % 0xC8];
  m_Size = p_m_EntityList->m_Size;
  v9 = 0;
  for ( nCount = m_Size; v9 < m_Size; ++v9 )
  {
    m_pObject = p_m_EntityList->m_Memory.m_pMemory[v9 >> ((unsigned __int64)*((int *)&p_m_EntityList->m_Memory + 2) >> 27)][v9 & ((32 * *((_DWORD *)&p_m_EntityList->m_Memory + 2)) >> 5)].m_pObject;
    if ( m_pObject != nullptr && ((*((_BYTE *)&m_pObject->CMapClass + 180) & 2) != 0 || !bVisiblesOnly) )
    {
      if ( CMapEntity::NameMatches(this: m_pObject, szName: pszName) )
        return m_pObject;
      m_Size = nCount;
    }
  }
  if ( !bSearchInstanceParms )
    return nullptr;
  v11 = v25;
  v12 = 0;
  pos = 0;
  if ( v25->m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v13 = v11->m_Memory.m_pMemory[v12 >> (*((int *)&v11->m_Memory + 2) >> 27)][v12
                                                                             & ((32 * *((_DWORD *)&v11->m_Memory + 2)) >> 5)].m_pObject;
    if ( v13 != nullptr )
    {
      v23 = v11->m_Memory.m_pMemory[v12 >> (*((int *)&v11->m_Memory + 2) >> 27)][v12
                                                                               & ((32 * *((_DWORD *)&v11->m_Memory + 2)) >> 5)].m_pObject;
      m_pHead = v13->m_References.m_pHead;
      v14 = v13->m_References.m_pHead;
      if ( v14 != nullptr )
        v14->m_pPrev = (CUtlReference<CMapEntity> *)&m_pHead;
      v22 = nullptr;
      v13->m_References.m_pHead = (CUtlReference<CMapEntity> *)&m_pHead;
    }
    v15 = v23;
    v26 = -1;
    if ( v23 != nullptr )
    {
      if ( v22 != nullptr )
      {
        v22->m_pNext = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = v22;
      }
      else if ( (CUtlReference<CMapEntity> **)v23->m_References.m_pHead == &m_pHead )
      {
        v23->m_References.m_pHead = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = nullptr;
      }
      v22 = nullptr;
      m_pHead = nullptr;
      v23 = nullptr;
    }
    if ( v15 != nullptr && CMapEntity::ClassNameMatches(this: v15, szName: "func_instance") )
    {
      Inorder = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &v15->m_KeyValues.m_KeyValues.m_Elements.m_Tree);
      if ( Inorder != 0xFFFF )
        break;
LABEL_35:
      v11 = v25;
    }
    pos = ++v12;
    if ( v12 >= v11->m_Size )
      return nullptr;
  }
  while ( 1 )
  {
    m_pMemory = v15->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory;
    v18 = Inorder;
    szValue = (unsigned __int8 *)m_pMemory[v18].m_Data.elem.szValue;
    if ( V_strncasecmp(s1: m_pMemory[v18].m_Data.elem.szKey, s2: "replace", n: 7) == 0 )
    {
      strchr(string: szValue, chr: 0x20u);
      if ( v20 != 0 && _V_stricmp(s1: pszName, s2: (const char *)(v20 + 1)) == 0 )
        return v15;
    }
    Inorder = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                this: &v15->m_KeyValues.m_KeyValues.m_Elements.m_Tree,
                i: Inorder);
    if ( Inorder == 0xFFFF )
    {
      v12 = pos;
      goto LABEL_35;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014B150
// Name: public: void CUtlReferenceVector<class CMapEntity>::FastRemove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlReferenceVector<CMapEntity>::FastRemove(CUtlReferenceVector<CMapEntity> *this, int elem)
{
  int m_Size; // eax
  int v4; // esi
  int v5; // ecx
  int v6; // eax
  CMapEntity *m_pObject; // ebx
  CUtlReference<CSheet> *v8; // esi
  CUtlIntrusiveDList<CUtlReference<CSheet> > *p_m_References; // eax
  CUtlReference<CMapEntity> *m_pHead; // eax
  CUtlReference<CSheet> *v11; // esi
  CUtlIntrusiveDList<CUtlReference<CSheet> > *v12; // eax

  m_Size = this->m_Size;
  if ( m_Size > 0 )
  {
    v4 = m_Size - 1;
    if ( elem != m_Size - 1 )
    {
      v5 = *((_DWORD *)&this->m_Memory + 2);
      v6 = (32 * v5) >> 5;
      v5 >>= 27;
      m_pObject = this->m_Memory.m_pMemory[v4 >> v5][v4 & v6].m_pObject;
      v8 = (CUtlReference<CSheet> *)&this->m_Memory.m_pMemory[elem >> v5][elem & v6];
      p_m_References = &v8->m_pObject->m_References;
      if ( p_m_References != (CUtlIntrusiveDList<CUtlReference<CSheet> > *)m_pObject )
      {
        if ( p_m_References != nullptr )
        {
          CUtlIntrusiveDList<CUtlReference<CMapClass>>::RemoveNode(this: p_m_References + 90, which: v8);
          v8->m_pObject = nullptr;
        }
        v8->m_pObject = (CSheet *)m_pObject;
        if ( m_pObject != nullptr )
        {
          v8->m_pNext = (CUtlReference<CSheet> *)m_pObject->m_References.m_pHead;
          m_pHead = m_pObject->m_References.m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = (CUtlReference<CMapEntity> *)v8;
          v8->m_pPrev = nullptr;
          m_pObject->m_References.m_pHead = (CUtlReference<CMapEntity> *)v8;
        }
      }
    }
    v11 = (CUtlReference<CSheet> *)&this->m_Memory.m_pMemory[(this->m_Size - 1) >> (*((int *)&this->m_Memory + 2) >> 27)][(this->m_Size - 1) & ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5)];
    v12 = &v11->m_pObject->m_References;
    if ( v12 != nullptr )
    {
      CUtlIntrusiveDList<CUtlReference<CMapClass>>::RemoveNode(this: v12 + 90, which: v11);
      v11->m_pObject = nullptr;
    }
    --this->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014B5F0
// Name: protected: void CMapWorld::EntityList_Remove(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapWorld::EntityList_Remove(CMapWorld *this, CMapClass *pObject, bool bRemoveChildren)
{
  CMapWorld *v3; // edi
  void *v4; // eax
  CMapEntity *v5; // esi
  CUtlReference<CMapClass> *v6; // eax
  int v7; // eax
  int EntityBucket; // eax
  CMapClass *i; // eax
  CMapClass *v10; // eax
  CUtlReference<CMapClass> *m_pMemory; // ecx
  int v12; // eax
  EnumChildrenPos_t pos; // [esp+Ch] [ebp-A4h] BYREF
  int nIndex; // [esp+90h] [ebp-20h] BYREF
  CMapWorld *v15; // [esp+94h] [ebp-1Ch]
  CUtlReference<CMapClass> src; // [esp+98h] [ebp-18h] BYREF
  int v17; // [esp+ACh] [ebp-4h]

  v3 = this;
  v15 = this;
  v4 = __RTDynamicCast(
         inptr: pObject,
         VfDelta: 0,
         SrcType: &CMapClass `RTTI Type Descriptor',
         TargetType: &CMapEntity `RTTI Type Descriptor',
         isReference: 0);
  v5 = (CMapEntity *)v4;
  if ( v4 != nullptr )
  {
    v6 = *((CUtlReference<CMapClass> **)v4 + 90);
    src.m_pPrev = nullptr;
    src.m_pObject = v5;
    src.m_pNext = v6;
    if ( v6 != nullptr )
      v6->m_pPrev = &src;
    src.m_pPrev = nullptr;
    v5->m_References.m_pHead = (CUtlReference<CMapEntity> *)&src;
    v17 = 0;
    v7 = CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::Find(
           this: (CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *)&v3->m_EntityList,
           &src);
    nIndex = v7;
    v17 = -1;
    if ( src.m_pObject != nullptr )
    {
      if ( src.m_pPrev != nullptr )
      {
        src.m_pPrev->m_pNext = src.m_pNext;
        if ( src.m_pNext != nullptr )
          src.m_pNext->m_pPrev = src.m_pPrev;
      }
      else if ( (CUtlReference<CMapClass> *)src.m_pObject[1].m_Dependents.m_Memory.m_pMemory == &src )
      {
        src.m_pObject[1].m_Dependents.m_Memory.m_pMemory = &src.m_pNext->m_pNext;
        if ( src.m_pNext != nullptr )
          src.m_pNext->m_pPrev = nullptr;
      }
      memset(&src, 0, sizeof(src));
    }
    if ( v7 != -1 )
      CUtlReferenceVector<CMapEntity>::FastRemove(this: &v3->m_EntityList, elem: v7);
    EntityBucket = CMapWorld::FindEntityBucket(this: v15, pEntity: v5, pnIndex: &nIndex);
    if ( EntityBucket != -1 )
      CUtlReferenceVector<CMapEntity>::FastRemove(this: &v15->m_EntityListByName[EntityBucket], elem: nIndex);
    v3 = v15;
  }
  if ( bRemoveChildren )
  {
    for ( i = CMapClass::GetFirstDescendent(this: pObject, &pos);
          i != nullptr;
          i = CMapClass::GetNextDescendent(this: pObject, &pos) )
    {
      v10 = (CMapClass *)__RTDynamicCast(
                           inptr: i,
                           VfDelta: 0,
                           SrcType: &CMapClass `RTTI Type Descriptor',
                           TargetType: &CMapEntity `RTTI Type Descriptor',
                           isReference: 0);
      if ( v10 != nullptr )
      {
        m_pMemory = (CUtlReference<CMapClass> *)v10[1].m_Dependents.m_Memory.m_pMemory;
        src.m_pPrev = nullptr;
        src.m_pObject = v10;
        src.m_pNext = m_pMemory;
        if ( m_pMemory != nullptr )
          m_pMemory->m_pPrev = &src;
        src.m_pPrev = nullptr;
        v10[1].m_Dependents.m_Memory.m_pMemory = (CUtlReference<CMapClass> **)&src;
        v17 = 1;
        v12 = CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::Find(
                this: (CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *)&v3->m_EntityList,
                &src);
        if ( v12 != -1 )
          CUtlReferenceVector<CMapEntity>::FastRemove(this: &v3->m_EntityList, elem: v12);
        v17 = -1;
        if ( src.m_pObject != nullptr )
        {
          if ( src.m_pPrev != nullptr )
          {
            src.m_pPrev->m_pNext = src.m_pNext;
            if ( src.m_pNext != nullptr )
              src.m_pNext->m_pPrev = src.m_pPrev;
          }
          else if ( (CUtlReference<CMapClass> *)src.m_pObject[1].m_Dependents.m_Memory.m_pMemory == &src )
          {
            src.m_pObject[1].m_Dependents.m_Memory.m_pMemory = &src.m_pNext->m_pNext;
            if ( src.m_pNext != nullptr )
              src.m_pNext->m_pPrev = nullptr;
          }
          memset(&src, 0, sizeof(src));
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014B810
// Name: public: void CMapWorld::RemoveObjectFromWorld(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapWorld::RemoveObjectFromWorld(CMapWorld *this, CMapClass *pObject, BOOL bRemoveChildren)
{
  CMapClass *v4; // eax

  if ( pObject != nullptr )
  {
    v4 = pObject->GetParent(this: pObject);
    if ( v4 != nullptr )
      v4->RemoveChild(this: v4, a2: pObject, a3: true);
    CMapWorld::EntityList_Remove(this, pObject, bRemoveChildren);
    pObject->OnRemoveFromWorld(this: pObject, a2: this, a3: bRemoveChildren);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014B860
// Name: public: bool CMapWorld::GenerateNewTargetname(char const __near *,char __near *,int,bool,char const __near *,class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapWorld::GenerateNewTargetname(
        CMapWorld *this,
        const char *startName,
        char *outputName,
        int newNameBufferSize,
        bool bMakeUnique,
        const char *szPrefix,
        CMapClass *pRoot)
{
  *outputName = 0;
  if ( szPrefix != nullptr )
    V_strncpy(pDest: outputName, pSrc: szPrefix, maxLen: newNameBufferSize);
  V_strncat(pDest: outputName, pSrc: startName, destBufferSize: newNameBufferSize, max_chars_to_copy: -1);
  if ( std::char_traits<char>::length(str: outputName) == 0 )
    V_strncpy(pDest: outputName, pSrc: "entity", maxLen: newNameBufferSize);
  if ( bMakeUnique
    && CMapWorld::FindEntityByName(this, pszName: outputName, bVisiblesOnly: false, bSearchInstanceParms: true) != nullptr )
  {
    do
    {
      do
        IncrementStringName(str: outputName, nMaxLength: newNameBufferSize);
      while ( CMapWorld::FindEntityByName(this, pszName: outputName, bVisiblesOnly: false, bSearchInstanceParms: true) != nullptr );
    }
    while ( pRoot != nullptr
         && pRoot->FindChildByKeyValue(this: pRoot, a2: "targetname", a3: outputName, a4: 0, a5: 0) != nullptr );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014B910
// Name: protected: static int CMapWorld::BuildSaveListsCallback(class CMapClass __near *,struct SaveLists_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CMapWorld::BuildSaveListsCallback(CMapClass *pObject, SaveLists_t *pSaveLists)
{
  CMapClass *v2; // eax
  CUtlReference<CMapClass> *m_pHead; // ecx
  SaveLists_t *p_Entities; // ecx
  CMapClass *v5; // eax
  CUtlReference<CMapClass> *v6; // ecx
  CMapClass *v7; // eax
  CUtlReference<CMapClass> *v8; // ecx
  CUtlReference<CMapClass> src; // [esp+8h] [ebp-18h] BYREF
  int v11; // [esp+1Ch] [ebp-4h]

  v2 = (CMapClass *)__RTDynamicCast(
                      inptr: pObject,
                      VfDelta: 0,
                      SrcType: &CMapClass `RTTI Type Descriptor',
                      TargetType: &CMapEntity `RTTI Type Descriptor',
                      isReference: 0);
  if ( v2 != nullptr )
  {
    m_pHead = v2->m_References.m_pHead;
    src.m_pPrev = nullptr;
    src.m_pObject = v2;
    src.m_pNext = m_pHead;
    if ( m_pHead != nullptr )
      m_pHead->m_pPrev = &src;
    src.m_pPrev = nullptr;
    v2->m_References.m_pHead = &src;
    v11 = 0;
    p_Entities = (SaveLists_t *)&pSaveLists->Entities;
  }
  else
  {
    v5 = (CMapClass *)__RTDynamicCast(
                        inptr: pObject,
                        VfDelta: 0,
                        SrcType: &CMapClass `RTTI Type Descriptor',
                        TargetType: &CMapSolid `RTTI Type Descriptor',
                        isReference: 0);
    if ( v5 != nullptr )
    {
      v6 = v5->m_References.m_pHead;
      src.m_pPrev = nullptr;
      src.m_pObject = v5;
      src.m_pNext = v6;
      if ( v6 != nullptr )
        v6->m_pPrev = &src;
      src.m_pPrev = nullptr;
      v5->m_References.m_pHead = &src;
      v11 = 1;
      p_Entities = pSaveLists;
    }
    else
    {
      v7 = (CMapClass *)__RTDynamicCast(
                          inptr: pObject,
                          VfDelta: 0,
                          SrcType: &CMapClass `RTTI Type Descriptor',
                          TargetType: &CMapGroup `RTTI Type Descriptor',
                          isReference: 0);
      if ( v7 == nullptr )
        return 1;
      v8 = v7->m_References.m_pHead;
      src.m_pPrev = nullptr;
      src.m_pObject = v7;
      src.m_pNext = v8;
      if ( v8 != nullptr )
        v8->m_pPrev = &src;
      src.m_pPrev = nullptr;
      v7->m_References.m_pHead = &src;
      v11 = 2;
      p_Entities = (SaveLists_t *)&pSaveLists->Groups;
    }
  }
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
    this: &p_Entities->Solids,
    elem: p_Entities->Solids.m_Size,
    &src);
  v11 = -1;
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
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014BA80
// Name: protected: void CMapWorld::AddEntity(class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapWorld::AddEntity(CMapWorld *this, CMapEntity *pEntity)
{
  CUtlReference<CMapClass> *m_pHead; // eax
  CUtlReferenceVector<CMapEntity> *p_m_EntityList; // edi
  bool v4; // dl
  CUtlReference<CMapClass> *v5; // eax
  const char *Value; // eax
  unsigned int v7; // ecx
  CUtlReference<CMapClass> *v8; // eax
  CUtlReference<CMapClass> src; // [esp+Ch] [ebp-1Ch] BYREF
  CMapWorld *v10; // [esp+18h] [ebp-10h]
  int v11; // [esp+24h] [ebp-4h]

  v10 = this;
  src.m_pPrev = nullptr;
  src.m_pNext = nullptr;
  src.m_pObject = pEntity;
  if ( pEntity != nullptr )
  {
    m_pHead = (CUtlReference<CMapClass> *)pEntity->m_References.m_pHead;
    src.m_pNext = m_pHead;
    if ( m_pHead != nullptr )
      m_pHead->m_pPrev = &src;
    src.m_pPrev = nullptr;
    pEntity->m_References.m_pHead = (CUtlReference<CMapEntity> *)&src;
  }
  v11 = 0;
  p_m_EntityList = &this->m_EntityList;
  v4 = CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::Find(
         this: (CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *)&this->m_EntityList,
         &src) != -1;
  v11 = -1;
  if ( src.m_pObject != nullptr )
  {
    if ( src.m_pPrev != nullptr )
    {
      src.m_pPrev->m_pNext = src.m_pNext;
      if ( src.m_pNext != nullptr )
        src.m_pNext->m_pPrev = src.m_pPrev;
    }
    else if ( (CUtlReference<CMapClass> *)src.m_pObject[1].m_Dependents.m_Memory.m_pMemory == &src )
    {
      src.m_pObject[1].m_Dependents.m_Memory.m_pMemory = &src.m_pNext->m_pNext;
      if ( src.m_pNext != nullptr )
        src.m_pNext->m_pPrev = nullptr;
    }
    memset(&src, 0, sizeof(src));
  }
  if ( !v4 )
  {
    src.m_pPrev = nullptr;
    src.m_pNext = nullptr;
    src.m_pObject = pEntity;
    if ( pEntity != nullptr )
    {
      v5 = (CUtlReference<CMapClass> *)pEntity->m_References.m_pHead;
      src.m_pNext = v5;
      if ( v5 != nullptr )
        v5->m_pPrev = &src;
      src.m_pPrev = nullptr;
      pEntity->m_References.m_pHead = (CUtlReference<CMapEntity> *)&src;
    }
    v11 = 1;
    CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::InsertBefore(
      this: p_m_EntityList,
      elem: p_m_EntityList->m_Size,
      (const CUtlReference<CMapEntity> *)&src);
    v11 = -1;
    if ( src.m_pObject != nullptr )
    {
      if ( src.m_pPrev != nullptr )
      {
        src.m_pPrev->m_pNext = src.m_pNext;
        if ( src.m_pNext != nullptr )
          src.m_pNext->m_pPrev = src.m_pPrev;
      }
      else if ( (CUtlReference<CMapClass> *)src.m_pObject[1].m_Dependents.m_Memory.m_pMemory == &src )
      {
        src.m_pObject[1].m_Dependents.m_Memory.m_pMemory = &src.m_pNext->m_pNext;
        if ( src.m_pNext != nullptr )
          src.m_pNext->m_pPrev = nullptr;
      }
      memset(&src, 0, sizeof(src));
    }
    Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &pEntity->m_KeyValues, pszKey: "targetname", piIndex: nullptr);
    if ( Value != nullptr )
    {
      v7 = HashStringCaseless(pszKey: Value) % 0xC8;
      src.m_pPrev = nullptr;
      src.m_pNext = nullptr;
      src.m_pObject = pEntity;
      if ( pEntity != nullptr )
      {
        v8 = (CUtlReference<CMapClass> *)pEntity->m_References.m_pHead;
        src.m_pNext = v8;
        if ( v8 != nullptr )
          v8->m_pPrev = &src;
        src.m_pPrev = nullptr;
        pEntity->m_References.m_pHead = (CUtlReference<CMapEntity> *)&src;
      }
      v11 = 2;
      CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::InsertBefore(
        this: &v10->m_EntityListByName[v7],
        elem: v10->m_EntityListByName[v7].m_Size,
        (const CUtlReference<CMapEntity> *)&src);
      v11 = -1;
      if ( src.m_pObject != nullptr )
      {
        if ( src.m_pPrev != nullptr )
        {
          src.m_pPrev->m_pNext = src.m_pNext;
          if ( src.m_pNext != nullptr )
            src.m_pNext->m_pPrev = src.m_pPrev;
        }
        else if ( (CUtlReference<CMapClass> *)src.m_pObject[1].m_Dependents.m_Memory.m_pMemory == &src )
        {
          src.m_pObject[1].m_Dependents.m_Memory.m_pMemory = &src.m_pNext->m_pNext;
          if ( src.m_pNext != nullptr )
            src.m_pNext->m_pPrev = nullptr;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014BCC0
// Name: protected: void CMapWorld::EntityList_Add(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapWorld::EntityList_Add(CMapWorld *this, CMapClass *pObject)
{
  CMapEntity *v3; // eax
  CMapClass *i; // eax
  void *v5; // eax
  CMapEntity *v6; // esi
  CUtlReference<CMapClass> *v7; // eax
  char v8; // dl
  EnumChildrenPos_t pos; // [esp+Ch] [ebp-A0h] BYREF
  int v10; // [esp+90h] [ebp-1Ch]
  CUtlReference<CMapClass> src; // [esp+94h] [ebp-18h] BYREF
  int v12; // [esp+A8h] [ebp-4h]

  v10 = 0;
  v3 = (CMapEntity *)__RTDynamicCast(
                       inptr: pObject,
                       VfDelta: 0,
                       SrcType: &CMapClass `RTTI Type Descriptor',
                       TargetType: &CMapEntity `RTTI Type Descriptor',
                       isReference: 0);
  if ( v3 != nullptr )
    CMapWorld::AddEntity(this, pEntity: v3);
  for ( i = CMapClass::GetFirstDescendent(this: pObject, &pos);
        i != nullptr;
        i = CMapClass::GetNextDescendent(this: pObject, &pos) )
  {
    v5 = __RTDynamicCast(
           inptr: i,
           VfDelta: 0,
           SrcType: &CMapClass `RTTI Type Descriptor',
           TargetType: &CMapEntity `RTTI Type Descriptor',
           isReference: 0);
    v6 = (CMapEntity *)v5;
    if ( v5 == nullptr )
      goto LABEL_9;
    v7 = *((CUtlReference<CMapClass> **)v5 + 90);
    src.m_pPrev = nullptr;
    src.m_pObject = v6;
    src.m_pNext = v7;
    if ( v7 != nullptr )
      v7->m_pPrev = &src;
    src.m_pPrev = nullptr;
    v6->m_References.m_pHead = (CUtlReference<CMapEntity> *)&src;
    v12 = 0;
    v10 |= 1u;
    if ( CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::Find(
           this: (CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > *)&this->m_EntityList,
           &src) == -1 )
      v8 = 1;
    else
LABEL_9:
      v8 = 0;
    v12 = -1;
    if ( (v10 & 1) != 0 )
    {
      v10 &= ~1u;
      if ( src.m_pObject != nullptr )
      {
        if ( src.m_pPrev != nullptr )
        {
          src.m_pPrev->m_pNext = src.m_pNext;
          if ( src.m_pNext != nullptr )
            src.m_pNext->m_pPrev = src.m_pPrev;
        }
        else if ( (CUtlReference<CMapClass> *)src.m_pObject[1].m_Dependents.m_Memory.m_pMemory == &src )
        {
          src.m_pObject[1].m_Dependents.m_Memory.m_pMemory = &src.m_pNext->m_pNext;
          if ( src.m_pNext != nullptr )
            src.m_pNext->m_pPrev = nullptr;
        }
        memset(&src, 0, sizeof(src));
      }
    }
    if ( v8 != 0 )
      CMapWorld::AddEntity(this, pEntity: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014BE20
// Name: public: void CMapWorld::PostloadWorld(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapWorld::PostloadWorld(CMapWorld *this)
{
  const char *Value; // eax
  int i; // edi
  CMapClass *m_pObject; // ebx
  int v5; // ebx
  CMapClass *v6; // edi
  CCullTreeNode *m_pCullTree; // ecx
  int nIndex; // [esp+Ch] [ebp-4h] BYREF

  CMapClass::s_bLoadingVMF = true;
  Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_KeyValues, pszKey: "classname", piIndex: &nIndex);
  if ( Value != nullptr )
  {
    this->SetClass(this: &this->CEditGameClass, a2: Value, a3: false);
    WCKVBase_Dict::RemoveKeyAt(this: &this->m_KeyValues, nIndex);
  }
  for ( i = 0; i < this->m_Children.m_Size; ++i )
  {
    m_pObject = this->m_Children.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
    m_pObject->PostloadWorld(this: m_pObject, a2: this);
    CMapWorld::EntityList_Add(this, pObject: m_pObject);
  }
  v5 = 0;
  for ( CMapClass::s_bLoadingVMF = false; v5 < this->m_Children.m_Size; ++v5 )
  {
    v6 = this->m_Children.m_Memory.m_pMemory[v5 >> ((unsigned __int64)*((int *)&this->m_Children.m_Memory + 2) >> 27)][v5 & ((32 * *((_DWORD *)&this->m_Children.m_Memory + 2)) >> 5)].m_pObject;
    v6->CalcBounds(this: v6, a2: 1);
    m_pCullTree = this->m_pCullTree;
    if ( m_pCullTree != nullptr )
      CCullTreeNode::UpdateCullTreeObjectRecurse(this: m_pCullTree, pObject: v6);
    v6->PostUpdate(this: v6, a2: Notify_Changed);
    v6->SignalChanged(this: v6);
  }
  this->CalcBounds(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1014BF50
// Name: public: bool CMapWorld::FindEntitiesByClassName(class CUtlReferenceVector<class CMapEntity> __near &,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapWorld::FindEntitiesByClassName(
        CMapWorld *this,
        CUtlReferenceVector<CMapEntity> *Found,
        const char *pszClassName,
        bool bVisiblesOnly)
{
  int v5; // edi
  CMapEntity *m_pObject; // esi
  CUtlReference<CMapEntity> *m_pHead; // eax
  CUtlReference<CMapEntity> src; // [esp+8h] [ebp-1Ch] BYREF
  int nCount; // [esp+14h] [ebp-10h]
  int v11; // [esp+20h] [ebp-4h]

  CUtlReferenceVector<CMapEntity>::RemoveAll(this: Found);
  v5 = 0;
  nCount = this->m_EntityList.m_Size;
  if ( nCount > 0 )
  {
    do
    {
      m_pObject = this->m_EntityList.m_Memory.m_pMemory[v5 >> (*((int *)&this->m_EntityList.m_Memory + 2) >> 27)][v5 & ((32 * *((_DWORD *)&this->m_EntityList.m_Memory + 2)) >> 5)].m_pObject;
      if ( ((*((_BYTE *)&m_pObject->CMapClass + 180) & 2) != 0 || !bVisiblesOnly)
        && CMapEntity::ClassNameMatches(this: m_pObject, szName: pszClassName) )
      {
        m_pHead = m_pObject->m_References.m_pHead;
        src.m_pPrev = nullptr;
        src.m_pObject = m_pObject;
        src.m_pNext = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = &src;
        src.m_pPrev = nullptr;
        m_pObject->m_References.m_pHead = &src;
        v11 = 0;
        CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::InsertBefore(
          this: Found,
          elem: Found->m_Size,
          &src);
        v11 = -1;
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
      ++v5;
    }
    while ( v5 < nCount );
  }
  return Found->m_Size != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1014C0A0
// Name: public: bool CMapWorld::FindEntitiesByKeyValue(class CUtlReferenceVector<class CMapEntity> __near &,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapWorld::FindEntitiesByKeyValue(
        CMapWorld *this,
        CUtlReferenceVector<CMapEntity> *Found,
        const char *pszKey,
        const char *pszValue,
        bool bVisiblesOnly)
{
  CMapWorld *v6; // esi
  int v7; // edx
  CMapEntity *m_pObject; // esi
  const char *Value; // eax
  CUtlReference<CMapEntity> *m_pHead; // eax
  CUtlReference<CMapEntity> *v11; // eax
  CUtlReference<CMapEntity> v13; // [esp+Ch] [ebp-2Ch] BYREF
  CUtlReference<CMapEntity> src; // [esp+18h] [ebp-20h] BYREF
  int nCount; // [esp+24h] [ebp-14h]
  CMapWorld *v16; // [esp+28h] [ebp-10h]
  int v17; // [esp+34h] [ebp-4h]
  int i; // [esp+40h] [ebp+8h]

  v6 = this;
  v16 = this;
  CUtlReferenceVector<CMapEntity>::RemoveAll(this: Found);
  v7 = 0;
  nCount = v6->m_EntityList.m_Size;
  i = 0;
  if ( nCount > 0 )
  {
    while ( 1 )
    {
      m_pObject = v6->m_EntityList.m_Memory.m_pMemory[v7 >> (*((int *)&v6->m_EntityList.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&v6->m_EntityList.m_Memory + 2)) >> 5)].m_pObject;
      if ( (*((_BYTE *)&m_pObject->CMapClass + 180) & 2) != 0 || !bVisiblesOnly )
      {
        Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &m_pObject->m_KeyValues, pszKey, piIndex: nullptr);
        if ( Value != nullptr )
        {
          if ( pszValue != nullptr && _V_stricmp(s1: pszValue, s2: Value) == 0 )
          {
            m_pHead = m_pObject->m_References.m_pHead;
            src.m_pPrev = nullptr;
            src.m_pObject = m_pObject;
            src.m_pNext = m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = &src;
            src.m_pPrev = nullptr;
            m_pObject->m_References.m_pHead = &src;
            v17 = 0;
            CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::InsertBefore(
              this: Found,
              elem: Found->m_Size,
              &src);
            v17 = -1;
            if ( src.m_pObject != nullptr )
            {
              if ( src.m_pPrev != nullptr )
              {
                src.m_pPrev->m_pNext = src.m_pNext;
                if ( src.m_pNext != nullptr )
                {
                  src.m_pNext->m_pPrev = src.m_pPrev;
                  memset(&src, 0, sizeof(src));
                  goto LABEL_30;
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
        }
        else if ( pszValue == nullptr )
        {
          v11 = m_pObject->m_References.m_pHead;
          v13.m_pPrev = nullptr;
          v13.m_pObject = m_pObject;
          v13.m_pNext = v11;
          if ( v11 != nullptr )
            v11->m_pPrev = &v13;
          v13.m_pPrev = nullptr;
          m_pObject->m_References.m_pHead = &v13;
          v17 = 1;
          CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::InsertBefore(
            this: Found,
            elem: Found->m_Size,
            src: &v13);
          v17 = -1;
          if ( v13.m_pObject != nullptr )
          {
            if ( v13.m_pPrev != nullptr )
            {
              v13.m_pPrev->m_pNext = v13.m_pNext;
              if ( v13.m_pNext != nullptr )
                v13.m_pNext->m_pPrev = v13.m_pPrev;
            }
            else if ( v13.m_pObject->m_References.m_pHead == &v13 )
            {
              v13.m_pObject->m_References.m_pHead = v13.m_pNext;
              if ( v13.m_pNext != nullptr )
                v13.m_pNext->m_pPrev = nullptr;
            }
            memset(&v13, 0, sizeof(v13));
          }
        }
      }
LABEL_30:
      v7 = i + 1;
      i = v7;
      if ( v7 >= nCount )
        return Found->m_Size != 0;
      v6 = v16;
    }
  }
  return Found->m_Size != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1014C2C0
// Name: public: bool CMapWorld::FindEntitiesByName(class CUtlReferenceVector<class CMapEntity> __near &,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMapWorld::FindEntitiesByName(
        CMapWorld *this,
        CUtlReferenceVector<CMapEntity> *Found,
        char *pszName,
        bool bVisiblesOnly)
{
  CUtlReferenceVector<CMapEntity> *p_m_EntityList; // ebx
  int v7; // eax
  int v8; // edi
  CMapEntity *m_pObject; // esi
  CUtlReference<CMapEntity> *m_pHead; // eax
  CUtlReference<CMapEntity> src; // [esp+8h] [ebp-1Ch] BYREF
  int nCount; // [esp+14h] [ebp-10h]
  int v13; // [esp+20h] [ebp-4h]

  CUtlReferenceVector<CMapEntity>::RemoveAll(this: Found);
  if ( pszName == nullptr )
    return false;
  p_m_EntityList = &this->m_EntityList;
  strchr(string: (unsigned __int8 *)pszName, chr: 0x2Au);
  if ( v7 == 0 )
    p_m_EntityList = &this->m_EntityListByName[HashStringCaseless(pszKey: pszName) % 0xC8];
  v8 = 0;
  nCount = p_m_EntityList->m_Size;
  if ( nCount > 0 )
  {
    do
    {
      m_pObject = p_m_EntityList->m_Memory.m_pMemory[v8 >> (*((int *)&p_m_EntityList->m_Memory + 2) >> 27)][v8 & ((32 * *((_DWORD *)&p_m_EntityList->m_Memory + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr
        && ((*((_BYTE *)&m_pObject->CMapClass + 180) & 2) != 0 || !bVisiblesOnly)
        && CMapEntity::NameMatches(this: m_pObject, szName: pszName) )
      {
        m_pHead = m_pObject->m_References.m_pHead;
        src.m_pPrev = nullptr;
        src.m_pObject = m_pObject;
        src.m_pNext = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = &src;
        src.m_pPrev = nullptr;
        m_pObject->m_References.m_pHead = &src;
        v13 = 0;
        CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::InsertBefore(
          this: Found,
          elem: Found->m_Size,
          &src);
        v13 = -1;
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
      ++v8;
    }
    while ( v8 < nCount );
  }
  return Found->m_Size != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1014C460
// Name: public: void CMapWorld::UpdateAllDependencies(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapWorld::UpdateAllDependencies(CMapWorld *this, CMapClass *pObject)
{
  CMapEntity *v3; // eax
  CMapEntity *v4; // edi
  unsigned int v5; // esi
  const char *Value; // eax
  int EntityBucket; // eax
  CUtlReference<CMapEntity> *m_pHead; // eax
  CUtlReference<CMapEntity> src; // [esp+8h] [ebp-18h] BYREF
  int v10; // [esp+1Ch] [ebp-4h]

  v3 = (CMapEntity *)__RTDynamicCast(
                       inptr: pObject,
                       VfDelta: 0,
                       SrcType: &CMapClass `RTTI Type Descriptor',
                       TargetType: &CMapEntity `RTTI Type Descriptor',
                       isReference: 0);
  v4 = v3;
  if ( v3 != nullptr )
  {
    v5 = -1;
    Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &v3->m_KeyValues, pszKey: "targetname", piIndex: nullptr);
    if ( Value != nullptr )
      v5 = HashStringCaseless(pszKey: Value) % 0xC8;
    EntityBucket = CMapWorld::FindEntityBucket(this, pEntity: v4, pnIndex: (int *)&pObject);
    if ( EntityBucket != v5 )
    {
      if ( EntityBucket != -1 )
        CUtlReferenceVector<CMapEntity>::FastRemove(this: &this->m_EntityListByName[EntityBucket], elem: (int)pObject);
      if ( v5 != -1 )
      {
        m_pHead = v4->m_References.m_pHead;
        src.m_pPrev = nullptr;
        src.m_pObject = v4;
        src.m_pNext = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = &src;
        src.m_pPrev = nullptr;
        v4->m_References.m_pHead = &src;
        v10 = 0;
        CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::InsertBefore(
          this: &this->m_EntityListByName[v5],
          elem: this->m_EntityListByName[v5].m_Size,
          &src);
        v10 = -1;
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
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014C5C0
// Name: public: CMapWorld::CMapWorld(class CMapDoc __near *)
// Source: json
//------------------------------------------------------------------------------
CMapWorld *__thiscall CMapWorld::CMapWorld(CMapWorld *this, CMapDoc *pOwningDocument)
{
  CMapPath **m_pMemory; // ecx

  CMapClass::CMapClass(this);
  CEditGameClass::CEditGameClass(this: &this->CEditGameClass);
  this->CMapClass::CMapPoint::CMapAtom::__vftable = (CMapWorld_vtbl *)&CMapWorld::`vftable'{for `CMapClass'};
  this->CEditGameClass::__vftable = (CEditGameClass_vtbl *)&CMapWorld::`vftable'{for `CEditGameClass'};
  this->m_Paths.m_Memory.m_pMemory = nullptr;
  this->m_Paths.m_Memory.m_nAllocationCount = 0;
  this->m_Paths.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_Paths.m_Memory.m_pMemory;
  this->m_Paths.m_Size = 0;
  this->m_Paths.m_pElements = m_pMemory;
  this->m_EntityList.m_Memory.m_pMemory = nullptr;
  this->m_EntityList.m_Memory.m_nBlocks = 0;
  *((_DWORD *)&this->m_EntityList.m_Memory + 2) = 0;
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
    this: (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)&this->m_EntityList,
    nGrowSize: 0,
    nInitSize: 0);
  this->m_EntityList.m_Size = 0;
  this->m_EntityList.m_pElements = nullptr;
  `eh vector constructor iterator'(
    ptr: this->m_EntityListByName,
    size: 0x14u,
    count: 200,
    pCtor: (void (__thiscall *)(void *))CUtlReferenceVector<CMapEntity>::CUtlReferenceVector<CMapEntity>,
    pDtor: (void (__thiscall *)(void *))CUtlReferenceVector<CMapEntity>::~CUtlReferenceVector<CMapEntity>);
  CMapWorld::Init(this);
  this->m_pOwningDocument = pOwningDocument;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014C6B0
// Name: public: virtual CMapWorld::~CMapWorld(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapWorld::~CMapWorld(CMapWorld *this)
{
  CUtlVector<CMapPath *,CUtlMemory<CMapPath *,int> > *p_m_Paths; // esi

  this->CMapClass::CMapPoint::CMapAtom::__vftable = (CMapWorld_vtbl *)&CMapWorld::`vftable'{for `CMapClass'};
  this->CEditGameClass::__vftable = (CEditGameClass_vtbl *)&CMapWorld::`vftable'{for `CEditGameClass'};
  p_m_Paths = &this->m_Paths;
  CUtlVector<CMapPath *,CUtlMemory<CMapPath *,int>>::PurgeAndDeleteElements(this: &this->m_Paths);
  if ( this->m_pCullTree != nullptr )
  {
    CMapWorld::CullTree_FreeNode(this, pNode: this->m_pCullTree);
    this->m_pCullTree = nullptr;
  }
  DestroyWorldEditDispMgr(pDispMgr: &this->m_pWorldDispMgr);
  `eh vector destructor iterator'(
    ptr: this->m_EntityListByName,
    size: 0x14u,
    count: 200,
    pDtor: (void (__thiscall *)(void *))CUtlReferenceVector<CMapEntity>::~CUtlReferenceVector<CMapEntity>);
  CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(this: &this->m_EntityList);
  p_m_Paths->m_Size = 0;
  if ( p_m_Paths->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Paths->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Paths->m_Memory.m_pMemory);
      p_m_Paths->m_Memory.m_pMemory = nullptr;
    }
    p_m_Paths->m_Memory.m_nAllocationCount = 0;
  }
  p_m_Paths->m_pElements = p_m_Paths->m_Memory.m_pMemory;
  if ( p_m_Paths->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Paths->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Paths->m_Memory.m_pMemory);
      p_m_Paths->m_Memory.m_pMemory = nullptr;
    }
    p_m_Paths->m_Memory.m_nAllocationCount = 0;
  }
  CEditGameClass::~CEditGameClass(this: &this->CEditGameClass);
  CMapClass::~CMapClass(this);
}

//------------------------------------------------------------------------------
// Address: 0x1014C7D0
// Name: public: void CMapWorld::AddObjectToWorld(class CMapClass __near *,class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapWorld::AddObjectToWorld(CMapWorld *this, CMapClass *pObject, CMapWorld *pParent)
{
  CMapWorld *v4; // ecx

  if ( pObject != nullptr )
  {
    v4 = pParent;
    if ( pParent == nullptr )
      v4 = this;
    v4->AddChild(this: v4, a2: pObject);
    CMapWorld::EntityList_Add(this, pObject);
    pObject->OnAddToWorld(this: pObject, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014C810
// Name: public: virtual class CMapClass __near * CMapWorld::CopyFrom(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMapWorld *__thiscall CMapWorld::CopyFrom(CMapWorld *this, CMapClass *pobj, bool bUpdateDependencies)
{
  char *Value; // eax
  char *v5; // edx
  char v6; // cl
  CEditGameClass *v7; // eax
  const char *v8; // eax
  char szOldTargetName[256]; // [esp+Ch] [ebp-100h] BYREF

  CMapClass::CopyFrom(this, pFrom: pobj, bUpdateDependencies);
  Value = (char *)WCKeyValuesT<WCKVBase_Dict>::GetValue(
                    this: &this->m_KeyValues,
                    pszKey: "targetname",
                    piIndex: nullptr);
  if ( Value != nullptr )
  {
    v5 = (char *)(szOldTargetName - Value);
    do
    {
      v6 = *Value;
      Value[(_DWORD)v5] = *Value;
      ++Value;
    }
    while ( v6 != 0 );
  }
  if ( pobj != nullptr )
    v7 = (CEditGameClass *)&pobj[1];
  else
    v7 = nullptr;
  CEditGameClass::CopyFrom(this: &this->CEditGameClass, pFrom: v7);
  v8 = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_KeyValues, pszKey: "targetname", piIndex: nullptr);
  if ( bUpdateDependencies && v8 != nullptr && _V_stricmp(s1: szOldTargetName, s2: v8) != 0 )
    CMapWorld::UpdateAllDependencies(this, pObject: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014C8C0
// Name: public: CMapWorld::CMapWorld(void)
// Source: json
//------------------------------------------------------------------------------
CMapWorld *__thiscall CMapWorld::CMapWorld(CMapWorld *this)
{
  CMapPath **m_pMemory; // ecx

  CMapClass::CMapClass(this);
  CEditGameClass::CEditGameClass(this: &this->CEditGameClass);
  this->CMapClass::CMapPoint::CMapAtom::__vftable = (CMapWorld_vtbl *)&CMapWorld::`vftable'{for `CMapClass'};
  this->CEditGameClass::__vftable = (CEditGameClass_vtbl *)&CMapWorld::`vftable'{for `CEditGameClass'};
  this->m_Paths.m_Memory.m_pMemory = nullptr;
  this->m_Paths.m_Memory.m_nAllocationCount = 0;
  this->m_Paths.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_Paths.m_Memory.m_pMemory;
  this->m_Paths.m_Size = 0;
  this->m_Paths.m_pElements = m_pMemory;
  this->m_EntityList.m_Memory.m_pMemory = nullptr;
  this->m_EntityList.m_Memory.m_nBlocks = 0;
  *((_DWORD *)&this->m_EntityList.m_Memory + 2) = 0;
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
    this: (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)&this->m_EntityList,
    nGrowSize: 0,
    nInitSize: 0);
  this->m_EntityList.m_Size = 0;
  this->m_EntityList.m_pElements = nullptr;
  `eh vector constructor iterator'(
    ptr: this->m_EntityListByName,
    size: 0x14u,
    count: 200,
    pCtor: (void (__thiscall *)(void *))CUtlReferenceVector<CMapEntity>::CUtlReferenceVector<CMapEntity>,
    pDtor: (void (__thiscall *)(void *))CUtlReferenceVector<CMapEntity>::~CUtlReferenceVector<CMapEntity>);
  CMapWorld::Init(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014C9D0
// Name: public: virtual class CMapClass __near * CMapWorld::Copy(bool)
// Source: json
//------------------------------------------------------------------------------
CMapWorld *__thiscall CMapWorld::Copy(CMapWorld *this, BOOL bUpdateDependencies)
{
  CMapWorld *v3; // eax
  CMapWorld *v4; // esi

  v3 = (CMapWorld *)operator new(nSize: 0x1140u);
  v4 = nullptr;
  if ( v3 != nullptr )
    v4 = CMapWorld::CMapWorld(this: v3);
  v4->CopyFrom(this: v4, a2: this, a3: bUpdateDependencies);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1014CA40
// Name: public: void CMapWorld::PostloadVisGroups(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapWorld::PostloadVisGroups(CMapWorld *this)
{
  CMapWorld *v1; // edi
  int v2; // edx
  CMapClass *m_pObject; // esi
  CUtlReference<CMapClass> *m_pHead; // eax
  CMainFrame *MainWnd; // eax
  int v6; // edx
  CMapEntity *v7; // eax
  CUtlReference<CMapEntity> *v8; // ecx
  CMapEntity *v9; // esi
  CUtlReference<CMapClass> *v10; // eax
  CEntityConnection *v11; // edi
  int i; // esi
  CUtlReferenceVector<CMapClass> orphans; // [esp+Ch] [ebp-4Ch] BYREF
  CUtlReference<CMapEntity> *v14; // [esp+20h] [ebp-38h] BYREF
  CUtlReference<CMapEntity> *v15; // [esp+24h] [ebp-34h]
  CMapEntity *v16; // [esp+28h] [ebp-30h]
  CUtlReference<CMapClass> src; // [esp+2Ch] [ebp-2Ch] BYREF
  CMapWorld *v18; // [esp+38h] [ebp-20h]
  CMapDoc *pDoc; // [esp+3Ch] [ebp-1Ch]
  int nConnections; // [esp+40h] [ebp-18h]
  int pos2; // [esp+44h] [ebp-14h]
  bool bFoundOrphans; // [esp+4Bh] [ebp-Dh]
  int v23; // [esp+54h] [ebp-4h]

  v1 = this;
  v18 = this;
  bFoundOrphans = false;
  memset(&orphans, 0, 12);
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &orphans.m_Memory, nGrowSize: 0, nInitSize: 0);
  orphans.m_Size = 0;
  orphans.m_pElements = nullptr;
  v23 = 3;
  v2 = 0;
  pDoc = CMapDoc::m_pMapDoc;
  pos2 = 0;
  if ( v1->m_Children.m_Size > 0 )
  {
    while ( 1 )
    {
      m_pObject = v1->m_Children.m_Memory.m_pMemory[v2 >> (*((int *)&v1->m_Children.m_Memory + 2) >> 27)][v2 & ((32 * *((_DWORD *)&v1->m_Children.m_Memory + 2)) >> 5)].m_pObject;
      if ( CMapClass::PostloadVisGroups(this: m_pObject, bLoading: true) )
      {
        src.m_pPrev = nullptr;
        src.m_pNext = nullptr;
        src.m_pObject = m_pObject;
        if ( m_pObject != nullptr )
        {
          m_pHead = m_pObject->m_References.m_pHead;
          src.m_pNext = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = &src;
          src.m_pPrev = nullptr;
          m_pObject->m_References.m_pHead = &src;
        }
        LOBYTE(v23) = 4;
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
          this: &orphans,
          elem: orphans.m_Size,
          &src);
        LOBYTE(v23) = 3;
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
        bFoundOrphans = true;
      }
      if ( ++pos2 >= v1->m_Children.m_Size )
        break;
      v2 = pos2;
    }
    if ( bFoundOrphans )
    {
      CMapDoc::VisGroups_CreateNamedVisGroup(
        this: pDoc,
        Objects: &orphans,
        szName: "_orphaned hidden",
        bHide: true,
        bRemoveFromOtherVisGroups: false);
      MainWnd = GetMainWnd();
      CWnd::MessageBoxA(
        this: MainWnd,
        lpszText: "Orphaned objects were found and placed into the \"_orphaned hidden\" visgroup.",
        lpszCaption: "Orphaned Objects Found",
        nType: 0x30u);
    }
  }
  v6 = 0;
  for ( pDoc = nullptr; v6 < v1->m_EntityList.m_Size; pDoc = (CMapDoc *)v6 )
  {
    v7 = v1->m_EntityList.m_Memory.m_pMemory[v6 >> (*((int *)&v1->m_EntityList.m_Memory + 2) >> 27)][v6 & ((32 * *((_DWORD *)&v1->m_EntityList.m_Memory + 2)) >> 5)].m_pObject;
    if ( v7 != nullptr )
    {
      v16 = v1->m_EntityList.m_Memory.m_pMemory[v6 >> (*((int *)&v1->m_EntityList.m_Memory + 2) >> 27)][v6 & ((32 * *((_DWORD *)&v1->m_EntityList.m_Memory + 2)) >> 5)].m_pObject;
      v14 = v7->m_References.m_pHead;
      v8 = v7->m_References.m_pHead;
      if ( v8 != nullptr )
        v8->m_pPrev = (CUtlReference<CMapEntity> *)&v14;
      v15 = nullptr;
      v7->m_References.m_pHead = (CUtlReference<CMapEntity> *)&v14;
    }
    v9 = v16;
    LOBYTE(v23) = 3;
    if ( v16 != nullptr )
    {
      if ( v15 != nullptr )
      {
        v15->m_pNext = v14;
        if ( v14 != nullptr )
          v14->m_pPrev = v15;
      }
      else if ( (CUtlReference<CMapEntity> **)v16->m_References.m_pHead == &v14 )
      {
        v16->m_References.m_pHead = v14;
        if ( v14 != nullptr )
          v14->m_pPrev = nullptr;
      }
      v15 = nullptr;
      v14 = nullptr;
      v16 = nullptr;
    }
    if ( v9 != nullptr )
      nConnections = v9->m_Connections.m_Size;
    else
      nConnections = 0;
    pos2 = 0;
    if ( nConnections > 0 )
    {
      do
      {
        v10 = (CUtlReference<CMapClass> *)v9->m_References.m_pHead;
        v11 = v9->m_Connections.m_Memory.m_pMemory[pos2];
        src.m_pPrev = nullptr;
        src.m_pObject = v9;
        src.m_pNext = v10;
        if ( v10 != nullptr )
          v10->m_pPrev = &src;
        src.m_pPrev = nullptr;
        v9->m_References.m_pHead = (CUtlReference<CMapEntity> *)&src;
        LOBYTE(v23) = 6;
        CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::InsertBefore(
          this: v11->m_pSourceEntityList,
          elem: v11->m_pSourceEntityList->m_Size,
          (const CUtlReference<CMapEntity> *)&src);
        LOBYTE(v23) = 3;
        if ( src.m_pObject != nullptr )
        {
          if ( src.m_pPrev != nullptr )
          {
            src.m_pPrev->m_pNext = src.m_pNext;
            if ( src.m_pNext != nullptr )
              src.m_pNext->m_pPrev = src.m_pPrev;
          }
          else if ( (CUtlReference<CMapClass> *)src.m_pObject[1].m_Dependents.m_Memory.m_pMemory == &src )
          {
            src.m_pObject[1].m_Dependents.m_Memory.m_pMemory = &src.m_pNext->m_pNext;
            if ( src.m_pNext != nullptr )
              src.m_pNext->m_pPrev = nullptr;
          }
          memset(&src, 0, sizeof(src));
        }
        CEntityConnection::LinkTargetEntities(this: v11);
        ++pos2;
      }
      while ( pos2 < nConnections );
      v6 = (int)pDoc;
      v1 = v18;
    }
    ++v6;
  }
  v23 = 9;
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::RemoveAll(this: &orphans);
  if ( orphans.m_Memory.m_pMemory != nullptr )
  {
    for ( i = 0; i < orphans.m_Memory.m_nBlocks; ++i )
      free(pMem: orphans.m_Memory.m_pMemory[i]);
    orphans.m_Memory.m_nBlocks = 0;
    free(pMem: orphans.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014CDF0
// Name: class CMapClass __near * CMapWorld_CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapWorld *__cdecl CMapWorld_CreateObject()
{
  CMapWorld *v0; // eax

  v0 = (CMapWorld *)operator new(nSize: 0x1140u);
  if ( v0 != nullptr )
    return CMapWorld::CMapWorld(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1014CE50
// Name: public: SaveLists_t::SaveLists_t(void)
// Source: json
//------------------------------------------------------------------------------
SaveLists_t *__thiscall SaveLists_t::SaveLists_t(SaveLists_t *this)
{
  this->Solids.m_Memory.m_pMemory = nullptr;
  this->Solids.m_Memory.m_nBlocks = 0;
  *((_DWORD *)&this->Solids.m_Memory + 2) = 0;
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &this->Solids.m_Memory, nGrowSize: 0, nInitSize: 0);
  this->Solids.m_Size = 0;
  this->Solids.m_pElements = nullptr;
  this->Entities.m_Memory.m_pMemory = nullptr;
  this->Entities.m_Memory.m_nBlocks = 0;
  *((_DWORD *)&this->Entities.m_Memory + 2) = 0;
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &this->Entities.m_Memory, nGrowSize: 0, nInitSize: 0);
  this->Entities.m_Size = 0;
  this->Entities.m_pElements = nullptr;
  this->Groups.m_Memory.m_pMemory = nullptr;
  this->Groups.m_Memory.m_nBlocks = 0;
  *((_DWORD *)&this->Groups.m_Memory + 2) = 0;
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &this->Groups.m_Memory, nGrowSize: 0, nInitSize: 0);
  this->Groups.m_Size = 0;
  this->Groups.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014CF00
// Name: public: SaveLists_t::~SaveLists_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SaveLists_t::~SaveLists_t(SaveLists_t *this)
{
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &this->Groups);
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &this->Entities);
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &this->Solids);
}

//------------------------------------------------------------------------------
// Address: 0x1014CF70
// Name: public: enum ChunkFileResult_t CMapWorld::SaveVMF(class CChunkFile __near *,class CSaveInfo __near *,int)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CMapWorld::SaveVMF(
        CMapWorld *this,
        CChunkFile *pFile,
        CSaveInfo *pSaveInfo,
        char saveFlags)
{
  ChunkFileResult_t v5; // edi
  SaveLists_t SaveLists; // [esp+Ch] [ebp-48h] BYREF
  int v8; // [esp+50h] [ebp-4h]

  this->PresaveWorld(this);
  SaveLists_t::SaveLists_t(this: &SaveLists);
  v8 = 0;
  CMapClass::EnumChildrenRecurseGroupsOnly(
    this,
    pfn: (int (__cdecl *)(CMapClass *, unsigned int))CMapWorld::BuildSaveListsCallback,
    dwParam: (unsigned int)&SaveLists,
    Type: nullptr);
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InPlaceQuickSort_r(
    this: &SaveLists.Entities,
    pfnCompare: SortFuncCompareSaveOrder,
    nLeft: 0,
    nRight: SaveLists.Entities.m_Size - 1);
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InPlaceQuickSort_r(
    this: &SaveLists.Groups,
    pfnCompare: SortFuncCompareSaveOrder,
    nLeft: 0,
    nRight: SaveLists.Groups.m_Size - 1);
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InPlaceQuickSort_r(
    this: &SaveLists.Solids,
    pfnCompare: SortFuncCompareSaveOrder,
    nLeft: 0,
    nRight: SaveLists.Solids.m_Size - 1);
  if ( (saveFlags & 1) != 0 )
    goto LABEL_8;
  v5 = CChunkFile::BeginChunk(this: pFile, pszChunkName: "world");
  if ( v5 == ChunkFile_Ok )
  {
    v5 = CChunkFile::WriteKeyValueInt(this: pFile, pszKey: "id", nValue: this->m_nID);
    if ( v5 == ChunkFile_Ok )
    {
      v5 = CChunkFile::WriteKeyValueInt(this: pFile, pszKey: "mapversion", nValue: CMapDoc::m_pMapDoc->m_nDocVersion);
      if ( v5 == ChunkFile_Ok )
      {
        CEditGameClass::SaveVMF(this: &this->CEditGameClass, pFile, pSaveInfo);
        v5 = CMapWorld::SaveObjectListVMF(this, pFile, pSaveInfo, pList: &SaveLists.Solids, saveFlags);
        if ( v5 == ChunkFile_Ok )
        {
          v5 = CMapWorld::SaveObjectListVMF(this, pFile, pSaveInfo, pList: &SaveLists.Groups, saveFlags);
          if ( v5 == ChunkFile_Ok )
          {
            CChunkFile::EndChunk(this: pFile);
LABEL_8:
            v5 = CMapWorld::SaveObjectListVMF(this, pFile, pSaveInfo, pList: &SaveLists.Entities, saveFlags);
          }
        }
      }
    }
  }
  v8 = 2;
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &SaveLists.Groups);
  LOBYTE(v8) = 1;
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &SaveLists.Entities);
  v8 = -1;
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &SaveLists.Solids);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1014D100
// Name: public: enum ChunkFileResult_t CMapWorld::SaveSolids(class CChunkFile __near *,class CSaveInfo __near *,int)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CMapWorld::SaveSolids(
        CMapWorld *this,
        CChunkFile *pFile,
        CSaveInfo *pSaveInfo,
        char saveFlags)
{
  ChunkFileResult_t v5; // esi
  SaveLists_t SaveLists; // [esp+4h] [ebp-48h] BYREF
  int v8; // [esp+48h] [ebp-4h]

  this->PresaveWorld(this);
  SaveLists_t::SaveLists_t(this: &SaveLists);
  v8 = 0;
  CMapClass::EnumChildrenRecurseGroupsOnly(
    this,
    pfn: (int (__cdecl *)(CMapClass *, unsigned int))CMapWorld::BuildSaveListsCallback,
    dwParam: (unsigned int)&SaveLists,
    Type: nullptr);
  v5 = CMapWorld::SaveObjectListVMF(this, pFile, pSaveInfo, pList: &SaveLists.Solids, saveFlags);
  v8 = 2;
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &SaveLists.Groups);
  LOBYTE(v8) = 1;
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &SaveLists.Entities);
  v8 = -1;
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &SaveLists.Solids);
  return v5;
}
