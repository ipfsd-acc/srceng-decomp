// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/networkstringtable.cpp
// Functions: 79
// ============================================================

#include "engine\networkstringtable.h"

//------------------------------------------------------------------------------
// Address: 0x10063210
// Name: public: void (*CNetworkStringTable::GetCallback(void))(void __near *,class INetworkStringTable __near *,int,char const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetworkStringTable::GetCallback(CVTFTexture *this)
{
  return this->m_nFlags;
}

//------------------------------------------------------------------------------
// Address: 0x101C2600
// Name: private: unsigned long CNetworkStringTableDictionaryManager::HashStringCaselessIgnoreSlashes(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CNetworkStringTableDictionaryManager::HashStringCaselessIgnoreSlashes(
        CNetworkStringTableDictionaryManager *this,
        const char *pString)
{
  const char *v2; // ebx
  int v3; // esi
  void *v4; // esp
  char v6[12]; // [esp+0h] [ebp-Ch] BYREF

  v2 = pString;
  if ( pString == nullptr )
    v2 = defaultValue;
  v3 = _V_strlen(str: v2) + 1;
  v4 = alloca(v3);
  V_strncpy(pDest: v6, pSrc: v2, maxLen: v3);
  V_FixSlashes(pname: v6, separator: 92);
  _V_strlower(start: v6);
  CRC32_Init(pulCRC: (unsigned int *)&pString);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&pString, pBuffer: v6, nBuffer: v3);
  CRC32_Final(pulCRC: (unsigned int *)&pString);
  return pString;
}

//------------------------------------------------------------------------------
// Address: 0x101C2670
// Name: private: bool CNetworkStringTableDictionaryManager::LoadDictionaryFile(class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetworkStringTableDictionaryManager::LoadDictionaryFile(
        CNetworkStringTableDictionaryManager *this,
        CUtlBuffer *buf,
        const char *pchMapName)
{
  char szFallback[256]; // [esp+8h] [ebp-100h] BYREF

  this->m_bLoadedFallbacks = false;
  if ( g_pFileSystem->ReadFile(
         this: &g_pFileSystem->IBaseFileSystem,
         a2: "stringtable_dictionary.dct",
         a3: "BSP",
         a4: buf,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    return 1;
  }
  if ( g_pFileSystem->ReadFile(
         this: &g_pFileSystem->IBaseFileSystem,
         a2: "stringtable_dictionary_fallback.dct",
         a3: "BSP",
         a4: buf,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    _Warning(a1: "#######################################\n");
    _Warning(a1: "Map %s using default stringtable dictionary, don't ship this way!!!\n", pchMapName);
    _Warning(a1: "Run with -stringtables on the command line or convar\n");
    _Warning(a1: "stringtable_alwaysrebuilddictionaries enabled to build the string table\n");
    _Warning(a1: "#######################################\n");
    this->m_bLoadedFallbacks = true;
    return 1;
  }
  else
  {
    V_snprintf(pDest: szFallback, maxLen: 256, pFormat: "reslists/%s.dict", pchMapName);
    if ( g_pFileSystem->ReadFile(
           this: &g_pFileSystem->IBaseFileSystem,
           a2: szFallback,
           a3: "GAME",
           a4: buf,
           a5: 0,
           a6: 0,
           a7: nullptr) )
    {
      _Warning(a1: "#######################################\n");
      _Warning(a1: "Map %s using fallback stringtable dictionary, don't ship this way!!!\n", pchMapName);
      _Warning(a1: "Run with -stringtables on the command line or convar\n");
      _Warning(a1: "stringtable_alwaysrebuilddictionaries enabled to build the string table\n");
      _Warning(a1: "#######################################\n");
      this->m_bLoadedFallbacks = true;
      return 1;
    }
    else
    {
      _Warning(a1: "#######################################\n");
      _Warning(a1: "Map %s missing stringtable dictionary, don't ship this way!!!\n", pchMapName);
      _Warning(a1: "Run with -stringtables on the command line or convar\n");
      _Warning(a1: "stringtable_alwaysrebuilddictionaries enabled to build the string table\n");
      _Warning(a1: "#######################################\n");
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C27D0
// Name: public: static bool CNetworkStringDict::CTableItem::Less(class CNetworkStringDict::CTableItem const __near &,class CNetworkStringDict::CTableItem const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CNetworkStringDict::CTableItem::Less(
        const CNetworkStringDict::CTableItem *lhs,
        const CNetworkStringDict::CTableItem *rhs)
{
  return lhs->m_StringHash < rhs->m_StringHash;
}

//------------------------------------------------------------------------------
// Address: 0x101C27F0
// Name: public: bool CNetworkStringTable::IsUsingDictionary(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetworkStringTable::IsUsingDictionary(CNetworkStringTable *this)
{
  return this->m_nFlags & 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C2800
// Name: public: int CNetworkStringTable::GetUserDataSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetworkStringTable::GetUserDataSize(CVTFTexture *this)
{
  return this->m_nFrameCount;
}

//------------------------------------------------------------------------------
// Address: 0x101C2810
// Name: public: int CNetworkStringTable::GetUserDataSizeBits(void)const
// Source: json
//------------------------------------------------------------------------------
vgui::DragDrop_t *__thiscall CNetworkStringTable::GetUserDataSizeBits(vgui::Panel *this)
{
  return this->m_pDragDrop;
}

//------------------------------------------------------------------------------
// Address: 0x101C2830
// Name: public: virtual void CNetworkStringTable::SetTick(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTable::SetTick(bf_write *this, const char *pDebugName)
{
  this->m_pDebugName = pDebugName;
}

//------------------------------------------------------------------------------
// Address: 0x101C2840
// Name: public: virtual void CNetworkStringTable::Lock(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTable::Lock(CNetworkStringTable *this, bool bLock)
{
  *((_BYTE *)this + 28) ^= (*((_BYTE *)this + 28) ^ (2 * bLock)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x101C2860
// Name: public: void CNetworkStringTable::SetMirrorTable(class INetworkStringTable __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTable::SetMirrorTable(CAudioMixerWave *this, int delaySamples)
{
  this->m_delaySamples = delaySamples;
}

//------------------------------------------------------------------------------
// Address: 0x101C2870
// Name: public: void CNetworkStringTable::RestoreTick(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTable::RestoreTick(CNetworkStringTable *this, int tick)
{
  INetworkStringDict *m_pItems; // ecx
  int v4; // edi
  int v5; // ebx
  CNetworkStringTableItem *v6; // eax
  int v7; // eax

  m_pItems = this->m_pItems;
  v4 = 0;
  this->m_nLastChangedTick = 0;
  v5 = m_pItems->Count(this: m_pItems);
  if ( v5 > 0 )
  {
    do
    {
      v6 = this->m_pItems->Element_2(this: this->m_pItems, a2: v4);
      v7 = CNetworkStringTableItem::RestoreTick(this: v6, tick);
      if ( v7 > this->m_nLastChangedTick )
        this->m_nLastChangedTick = v7;
      ++v4;
    }
    while ( v4 < v5 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C28C0
// Name: public: void CNetworkStringTable::UpdateMirrorTable(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CNetworkStringTable::UpdateMirrorTable(
        CNetworkStringTable *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int tick_ack)
{
  int v5; // edi
  CNetworkStringTableItem *v6; // eax
  CNetworkStringTableItem *v7; // ebx
  const void *UserData; // eax
  int m_nUserDataLength; // ebx
  int v10; // eax
  int v13; // [esp+0h] [ebp-10h]
  int count; // [esp+4h] [ebp-Ch]
  const void *pUserData; // [esp+Ch] [ebp-4h]

  if ( this->m_pMirrorTable != nullptr )
  {
    this->m_pMirrorTable->SetTick(this: this->m_pMirrorTable, a2: this->m_nTickCount);
    v5 = 0;
    count = this->m_pItems->Count(this: this->m_pItems);
    if ( count > 0 )
    {
      do
      {
        v6 = this->m_pItems->Element_2(this: this->m_pItems, a2: v5);
        v7 = v6;
        if ( v6->m_nTickChanged > tick_ack )
        {
          UserData = CNetworkStringTableItem::GetUserData(this: v6, length: nullptr);
          m_nUserDataLength = v7->m_nUserDataLength;
          pUserData = UserData;
          if ( m_nUserDataLength == 0 || UserData == nullptr )
          {
            m_nUserDataLength = 0;
            pUserData = nullptr;
          }
          if ( v5 >= ((int (__thiscall *)(INetworkStringTable *, int, int))this->m_pMirrorTable->GetNumStrings)(
                       a1: this->m_pMirrorTable,
                       a2,
                       a3) )
          {
            v10 = ((int (__thiscall *)(INetworkStringDict *, int, int, int))this->m_pItems->String)(
                    a1: this->m_pItems,
                    a2: v5,
                    a3: v13,
                    a4: count);
            count = (int)pUserData;
            v13 = m_nUserDataLength;
            a3 = v10;
            a2 = 1;
            ((void (__thiscall *)(INetworkStringTable *))this->m_pMirrorTable->AddString)(a1: this->m_pMirrorTable);
          }
          else
          {
            a3 = (int)pUserData;
            a2 = m_nUserDataLength;
            ((void (__thiscall *)(INetworkStringTable *, int))this->m_pMirrorTable->SetStringUserData)(
              a1: this->m_pMirrorTable,
              a2: v5);
          }
        }
        ++v5;
      }
      while ( v5 < count );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C2980
// Name: public: void CNetworkStringTable::CopyStringTable(class CNetworkStringTable __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTable::CopyStringTable(CNetworkStringTable *this, CNetworkStringTable *table)
{
  CNetworkStringTable *v2; // ebx
  int v3; // esi
  CNetworkStringTableItem *v4; // eax
  CNetworkStringTable_vtbl *v5; // ebx
  int v6; // eax

  v2 = this;
  v3 = 0;
  if ( table->m_pItems->Count(this: table->m_pItems) != 0 )
  {
    while ( 1 )
    {
      v4 = table->m_pItems->Element_2(this: table->m_pItems, a2: v3);
      v2->m_nTickCount = v4->m_nTickChanged;
      v5 = v2->__vftable;
      v6 = ((int (__thiscall *)(CNetworkStringTable *, int, int, unsigned __int8 *))table->GetString)(
             a1: table,
             a2: v3,
             a3: v4->m_nUserDataLength,
             a4: v4->m_pUserData);
      ((void (__thiscall *)(CNetworkStringTable *, int, int))v5->AddString)(a1: this, a2: 1, a3: v6);
      if ( ++v3 >= table->m_pItems->Count(this: table->m_pItems) )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C29F0
// Name: public: virtual void CNetworkStringTable::SetStringChangedCallback(void __near *,void (*)(void __near *,class INetworkStringTable __near *,int,char const __near *,void const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTable::SetStringChangedCallback(
        CNetworkStringTable *this,
        void *object,
        void (__cdecl *changeFunc)(void *, INetworkStringTable *, int, const char *, const void *))
{
  this->m_changeFunc = changeFunc;
  this->m_pObject = object;
}

//------------------------------------------------------------------------------
// Address: 0x101C2A10
// Name: public: virtual bool CNetworkStringTable::ChangedSinceTick(int)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CNetworkStringTable::ChangedSinceTick(CNetworkStringTable *this, int tick)
{
  return this->m_nLastChangedTick > tick;
}

//------------------------------------------------------------------------------
// Address: 0x101C2A30
// Name: public: virtual char const __near * CNetworkStringTable::GetString(int)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CNetworkStringTable::GetString(CNetworkStringTable *this, int stringNumber)
{
  INetworkStringDict *m_pItems; // esi
  INetworkStringDict *m_pItemsClientSide; // ecx
  int v4; // edi

  m_pItems = this->m_pItems;
  m_pItemsClientSide = this->m_pItemsClientSide;
  v4 = stringNumber;
  if ( m_pItemsClientSide != nullptr && stringNumber < -1 )
  {
    m_pItems = m_pItemsClientSide;
    v4 = -stringNumber;
  }
  if ( m_pItems->IsValidIndex(this: m_pItems, a2: v4) )
    return m_pItems->String(this: m_pItems, a2: v4);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101C2A80
// Name: protected: void CNetworkStringTable::DataChanged(int,class CNetworkStringTableItem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTable::DataChanged(
        CNetworkStringTable *this,
        int stringNumber,
        CNetworkStringTableItem *item)
{
  CNetworkStringTableItem *v4; // ecx
  bool v5; // zf
  const char *v6; // eax

  v4 = item;
  if ( item != nullptr )
  {
    v5 = this->m_changeFunc == nullptr;
    this->m_nLastChangedTick = this->m_nTickCount;
    if ( !v5 )
    {
      CNetworkStringTableItem::GetUserData(this: v4, length: (int *)&item);
      v6 = this->GetString(this, a2: stringNumber);
      ((void (__cdecl *)(void *, CNetworkStringTable *, int, const char *))this->m_changeFunc)(
        a1: this->m_pObject,
        a2: this,
        a3: stringNumber,
        a4: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C2AD0
// Name: public: virtual void const __near * CNetworkStringTable::GetStringUserData(int,int __near *)const
// Source: json
//------------------------------------------------------------------------------
const void *__thiscall CNetworkStringTable::GetStringUserData(CNetworkStringTable *this, int stringNumber, int *length)
{
  INetworkStringDict *m_pItemsClientSide; // edx
  INetworkStringDict *m_pItems; // eax
  int v5; // ecx
  CNetworkStringTableItem *v6; // eax

  m_pItemsClientSide = this->m_pItemsClientSide;
  m_pItems = this->m_pItems;
  v5 = stringNumber;
  if ( m_pItemsClientSide != nullptr && stringNumber < -1 )
  {
    m_pItems = m_pItemsClientSide;
    v5 = -stringNumber;
  }
  v6 = m_pItems->Element_2(this: m_pItems, a2: v5);
  return CNetworkStringTableItem::GetUserData(this: v6, length);
}

//------------------------------------------------------------------------------
// Address: 0x101C2B10
// Name: public: virtual int CNetworkStringTable::GetNumStrings(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CNetworkStringTable::GetNumStrings(CNetworkStringTable *this)
{
  return this->m_pItems->Count(this: this->m_pItems);
}

//------------------------------------------------------------------------------
// Address: 0x101C2B20
// Name: public: virtual int CNetworkStringTable::FindStringIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetworkStringTable::FindStringIndex(CNetworkStringTable *this, const char *string)
{
  int v3; // edi
  int v5; // edi

  v3 = this->m_pItems->Find(this: this->m_pItems, a2: string);
  if ( this->m_pItems->IsValidIndex(this: this->m_pItems, a2: v3) )
    return v3;
  if ( this->m_pItemsClientSide != nullptr )
  {
    v5 = this->m_pItemsClientSide->Find(this: this->m_pItemsClientSide, a2: string);
    if ( this->m_pItemsClientSide->IsValidIndex(this: this->m_pItemsClientSide, a2: v5) )
      return -v5;
  }
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x101C2B90
// Name: public: virtual void CNetworkStringTable::Dump(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTable::Dump(CNetworkStringTable *this)
{
  const char *v2; // eax
  int v3; // eax
  int v4; // eax
  int i; // edi
  INetworkStringDict *m_pItems; // ecx
  int v7; // eax
  INetworkStringDict *v8; // ecx
  const char *v9; // eax
  int j; // edi
  const char *v11; // eax
  int v12; // [esp-4h] [ebp-14h]
  int v13; // [esp-4h] [ebp-14h]
  int v14; // [esp-4h] [ebp-14h]
  int v15; // [esp+0h] [ebp-10h]
  int nCurrentDictionaryIndex; // [esp+Ch] [ebp-4h]

  v2 = this->GetTableName(this);
  ConMsg(a1: "Table %s\n", v2);
  v3 = this->GetMaxStrings(this);
  v4 = ((int (__thiscall *)(CNetworkStringTable *, int))this->GetNumStrings)(a1: this, a2: v3);
  ConMsg(a1: "  %i/%i items\n", v4, v12);
  for ( i = 0; i < this->GetNumStrings(this); ++i )
  {
    m_pItems = this->m_pItems;
    if ( (this->m_nFlags & 1) != 0 )
    {
      v7 = ((int (__thiscall *)(INetworkStringDict *, int, int))m_pItems->DictionaryIndex)(a1: m_pItems, a2: i, a3: v15);
      v8 = this->m_pItems;
      nCurrentDictionaryIndex = v7;
      if ( v7 == -1 )
      {
        v13 = (int)v8->String(this: v8, a2: i);
        ConMsg(a1: "         %i : %s\n", i, v13);
      }
      else
      {
        v9 = v8->String(this: v8, a2: i);
        ConMsg(a1: "d(%05d) %i : %s\n", nCurrentDictionaryIndex, i, v9);
      }
    }
    else
    {
      v14 = (int)m_pItems->String(this: m_pItems, a2: i);
      ConMsg(a1: "   %i : %s\n", i, v14);
    }
  }
  if ( this->m_pItemsClientSide != nullptr )
  {
    for ( j = 0; j < (int)this->m_pItemsClientSide->Count(this: this->m_pItemsClientSide); ++j )
    {
      v11 = this->m_pItemsClientSide->String(this: this->m_pItemsClientSide, a2: j);
      ConMsg(a1: "   (c)%i : %s\n", j, v11);
    }
  }
  ConMsg(a1: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x101C2CB0
// Name: public: void CNetworkStringTableContainer::EnableRollback(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableContainer::EnableRollback(CNetworkStringTableContainer *this, bool bState)
{
  this->m_bEnableRollback = bState;
}

//------------------------------------------------------------------------------
// Address: 0x101C2D70
// Name: public: bool CNetworkStringTableDictionaryManager::ShouldRecreateDictionary(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetworkStringTableDictionaryManager::ShouldRecreateDictionary(
        CNetworkStringTableDictionaryManager *this,
        const char *pchMapName)
{
  V_FileBase(in: com_gamedir, out: gamedir_7, maxlen: 260);
  if ( _V_stricmp(s1: gamedir_7, s2: "infested") != 0 )
  {
    if ( this->m_bForceRebuildDictionaries )
      return this->m_Strings.m_Size == 0 || this->m_bLoadedFallbacks || MapReslistGenerator()->m_bLoggingEnabled;
    if ( MapReslistGenerator()->m_bLoggingEnabled )
    {
      if ( this->m_Strings.m_Size == 0 )
        return 1;
      if ( this->m_bLoadedFallbacks )
        return this->m_Strings.m_Size == 0 || this->m_bLoadedFallbacks || MapReslistGenerator()->m_bLoggingEnabled;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C2DF0
// Name: public: bool CNetworkStringTableDictionaryManager::WriteDictionaryToBSP(char const __near *,class CUtlBuffer __near &,bool)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CNetworkStringTableDictionaryManager::WriteDictionaryToBSP@<al>(
        CNetworkStringTableDictionaryManager *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const char *pchMapName,
        CUtlBuffer *buf,
        bool bCreatingFor360)
{
  bool result; // al
  struct CSysModule *Module; // eax
  struct CSysModule *v9; // edi
  void *(__cdecl *Factory)(const char *, int *); // eax
  void (__thiscall ***v11)(_DWORD, IFileSystem *, char *, int, int, int); // eax
  void (__thiscall ***v12)(_DWORD, IFileSystem *, char *, _DWORD, _DWORD, _DWORD); // esi
  const char *v13; // eax
  void (__thiscall *v14)(_DWORD); // edx
  char mapPath[260]; // [esp+0h] [ebp-104h] BYREF

  V_snprintf(pDest: mapPath, maxLen: 260, pFormat: "maps/%s.bsp", pchMapName);
  result = g_pFileSystem->IsFileWritable(this: &g_pFileSystem->IBaseFileSystem, a2: mapPath, a3: "GAME");
  if ( result )
  {
    Module = FileSystem_LoadModule(path: "bsppack");
    v9 = Module;
    if ( Module == nullptr )
    {
LABEL_6:
      ConMsg(a1: "Can't load bsppack.dll\n");
      return false;
    }
    Factory = Sys_GetFactory(pModule: Module);
    if ( Factory == nullptr
      || (v11 = (void (__thiscall ***)(_DWORD, IFileSystem *, char *, int, int, int))Factory(
                                                                                       a1: "IBSPPACK003",
                                                                                       a2: nullptr),
          v12 = v11,
          v11 == nullptr) )
    {
      Sys_UnloadModule(pModule: v9);
      goto LABEL_6;
    }
    (**v11)(a1: v11, a2: g_pFileSystem, a3: mapPath, a4: a2, a5: a3, a6: a4);
    if ( bCreatingFor360 )
      v13 = "stringtable_dictionary_fallback_xbox.dct";
    else
      v13 = "stringtable_dictionary_fallback.dct";
    ((void (__thiscall *)(void (__thiscall ***)(_DWORD, IFileSystem *, char *, _DWORD, _DWORD, _DWORD), const char *, _DWORD))(*v12)[11])(
      a1: v12,
      a2: v13,
      a3: *(_DWORD *)mapPath);
    v14 = (void (__thiscall *)(_DWORD))(*v12)[4];
    *(_DWORD *)mapPath = 0;
    v14(a1: v12);
    ((void (__thiscall *)(void (__thiscall ***)(_DWORD, IFileSystem *, char *, _DWORD, _DWORD, _DWORD), char *))(*v12)[1])(
      a1: v12,
      a2: mapPath);
    ((void (__thiscall *)(void (__thiscall ***)(_DWORD, IFileSystem *, char *, _DWORD, _DWORD, _DWORD)))(*v12)[2])(a1: v12);
    FileSystem_UnloadModule(pModule: v9);
    _Msg(a1: "Updated stringtable dictionary saved to %s\n", mapPath);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C2F90
// Name: public: virtual int CNetworkStringTable::AddString(bool,char const __near *,int,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CNetworkStringTable::AddString@<eax>(
        CNetworkStringTable *this@<ecx>,
        int a2@<ebx>,
        bool bIsServer,
        const char *string,
        int length,
        const void *userdata)
{
  const char *v7; // eax
  int v9; // ebx
  const char *v10; // eax
  int v11; // edi
  bool v12; // al
  INetworkStringDict *m_pItemsClientSide; // ecx
  unsigned int v14; // edi
  CNetworkStringTableItem *v15; // ebx
  char v16; // al
  INetworkStringDict *m_pItems; // ecx
  unsigned int v18; // ebx
  const char *v19; // eax
  CNetworkStringTableItem *v20; // eax
  CNetworkStringTableItem *v21; // edi
  const char *v22; // [esp-8h] [ebp-10h]
  const char *v23; // [esp-8h] [ebp-10h]
  const char *v24; // [esp-4h] [ebp-Ch]
  bool bHasChanged; // [esp+13h] [ebp+Bh]
  bool bHasChangeda; // [esp+13h] [ebp+Bh]

  if ( string == nullptr )
  {
    v7 = this->GetTableName(this);
    ConMsg(a1: "Warning:  Can't add NULL string to table %s\n", v7);
    return 0xFFFF;
  }
  v9 = ((int (__thiscall *)(INetworkStringDict *, const char *, int))this->m_pItems->Find)(
         a1: this->m_pItems,
         a2: string,
         a3: a2);
  if ( !bIsServer
    && (!this->m_pItems->IsValidIndex(this: this->m_pItems, a2: v9) || this->m_pItemsClientSide != nullptr) )
  {
    if ( this->m_pItemsClientSide != nullptr
      || (v10 = (const char *)((int (__thiscall *)(CNetworkStringTable *, const char *))this->GetTableName)(
                                a1: this,
                                a2: string),
          DevMsg(
            a1: "CNetworkStringTable::AddString:  client added string which server didn't put into table (consider SetAllowCl"
            "ientSideAddString?): %s %s\n",
            v10,
            v24),
          this->m_pItemsClientSide != nullptr) )
    {
      v11 = this->m_pItemsClientSide->Find(this: this->m_pItemsClientSide, a2: string);
      v12 = this->m_pItemsClientSide->IsValidIndex(this: this->m_pItemsClientSide, a2: v11);
      m_pItemsClientSide = this->m_pItemsClientSide;
      if ( v12 )
      {
        v15 = m_pItemsClientSide->Element_2(this: m_pItemsClientSide, a2: v11);
        bHasChanged = false;
LABEL_14:
        if ( (length > -1
           && CNetworkStringTableItem::SetUserData(this: v15, tick: this->m_nTickCount, length, userData: userdata)
           || bHasChanged)
          && (*((_BYTE *)this + 28) & 1) == 0 )
        {
          CNetworkStringTable::DataChanged(this, stringNumber: -v11, item: v15);
        }
        return -v11;
      }
      v14 = m_pItemsClientSide->Count(this: m_pItemsClientSide);
      v22 = string;
      if ( v14 < this->GetMaxStrings(this) )
      {
        v11 = this->m_pItemsClientSide->Insert(this: this->m_pItemsClientSide, a2: string);
        v15 = this->m_pItemsClientSide->Element_2(this: this->m_pItemsClientSide, a2: v11);
        v15->m_nTickChanged = this->m_nTickCount;
        v15->m_nTickCreated = this->m_nTickCount;
        if ( (*((_BYTE *)this + 28) & 1) != 0 )
          CNetworkStringTableItem::EnableChangeHistory(this: v15);
        bHasChanged = true;
        goto LABEL_14;
      }
LABEL_22:
      v19 = (const char *)((int (__thiscall *)(CNetworkStringTable *, const char *))this->GetTableName)(
                            a1: this,
                            a2: v22);
      ConMsg(a1: "Warning:  Table %s is full, can't add %s\n", v19, v23);
      return 0xFFFF;
    }
  }
  v16 = ((int (__thiscall *)(INetworkStringDict *))this->m_pItems->IsValidIndex)(a1: this->m_pItems);
  m_pItems = this->m_pItems;
  if ( v16 != 0 )
  {
    v21 = m_pItems->Element_2(this: m_pItems, a2: v9);
    bHasChangeda = false;
  }
  else
  {
    v18 = m_pItems->Count(this: m_pItems);
    v22 = string;
    if ( v18 >= this->GetMaxStrings(this) )
      goto LABEL_22;
    v9 = this->m_pItems->Insert(this: this->m_pItems, a2: string);
    v20 = this->m_pItems->Element_2(this: this->m_pItems, a2: v9);
    v21 = v20;
    v20->m_nTickChanged = this->m_nTickCount;
    v20->m_nTickCreated = this->m_nTickCount;
    if ( (*((_BYTE *)this + 28) & 1) != 0 )
      CNetworkStringTableItem::EnableChangeHistory(this: v20);
    bHasChangeda = true;
  }
  if ( (length > -1
     && CNetworkStringTableItem::SetUserData(this: v21, tick: this->m_nTickCount, length, userData: userdata)
     || bHasChangeda)
    && (*((_BYTE *)this + 28) & 1) == 0 )
  {
    CNetworkStringTable::DataChanged(this, stringNumber: v9, item: v21);
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x101C31B0
// Name: public: virtual void CNetworkStringTable::SetStringUserData(int,int,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTable::SetStringUserData(
        CNetworkStringTable *this,
        int stringNumber,
        int length,
        const void *userdata)
{
  int v4; // eax
  INetworkStringDict *m_pItemsClientSide; // edx
  INetworkStringDict *m_pItems; // ecx
  int v8; // ebx
  CNetworkStringTableItem *v9; // edi
  bool v10; // zf
  const char *v11; // eax

  v4 = stringNumber;
  m_pItemsClientSide = this->m_pItemsClientSide;
  m_pItems = this->m_pItems;
  v8 = stringNumber;
  if ( m_pItemsClientSide != nullptr && stringNumber < -1 )
  {
    m_pItems = m_pItemsClientSide;
    v4 = -stringNumber;
  }
  v9 = m_pItems->Element_2(this: m_pItems, a2: v4);
  if ( CNetworkStringTableItem::SetUserData(this: v9, tick: this->m_nTickCount, length, userData: userdata)
    && v9 != nullptr )
  {
    v10 = this->m_changeFunc == nullptr;
    this->m_nLastChangedTick = this->m_nTickCount;
    if ( !v10 )
    {
      CNetworkStringTableItem::GetUserData(this: v9, length: &stringNumber);
      v11 = this->GetString(this, a2: v8);
      ((void (__cdecl *)(void *, CNetworkStringTable *, int, const char *))this->m_changeFunc)(
        a1: this->m_pObject,
        a2: this,
        a3: v8,
        a4: v11);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C3230
// Name: public: bool CNetworkStringTableContainer::Lock(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetworkStringTableContainer::Lock(CNetworkStringTableContainer *this, BOOL bLock)
{
  bool result; // al
  int v4; // edi
  INetworkStringTable *v5; // eax
  bool oldLock; // [esp+Fh] [ebp-1h]

  result = this->m_bLocked;
  v4 = 0;
  oldLock = result;
  this->m_bLocked = bLock;
  if ( this->m_Tables.m_Size > 0 )
  {
    do
    {
      v5 = this->GetTable(this, a2: v4);
      ((void (__thiscall *)(INetworkStringTable *, BOOL))v5->__vftable[1].GetTableName)(a1: v5, a2: bLock);
      ++v4;
    }
    while ( v4 < this->m_Tables.m_Size );
    return oldLock;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C3290
// Name: public: void CNetworkStringTableContainer::DirectUpdate(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableContainer::DirectUpdate(CNetworkStringTableContainer *this, int tick_ack)
{
  int i; // ebx
  CNetworkStringTable *v4; // esi

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CNetworkStringTableContainer::DirectUpdate",
    a3: 0,
    a4: "Networking",
    a5: false,
    a6: 4);
  for ( i = 0; i < this->m_Tables.m_Size; ++i )
  {
    v4 = (CNetworkStringTable *)this->GetTable(this, a2: i);
    if ( v4->ChangedSinceTick(this: v4, a2: tick_ack) )
      CNetworkStringTable::UpdateMirrorTable(this: v4, a2: i, a3: (int)this, tick_ack);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x101C3310
// Name: public: void CNetworkStringTableContainer::SetTick(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableContainer::SetTick(CNetworkStringTableContainer *this, int tick_count)
{
  int v3; // edi
  INetworkStringTable *v4; // eax

  v3 = 0;
  for ( this->m_nTickCount = tick_count; v3 < this->m_Tables.m_Size; ++v3 )
  {
    v4 = this->GetTable(this, a2: v3);
    v4->SetTick(this: v4, a2: tick_count);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C3440
// Name: GetBestPreviousString
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetBestPreviousString(const char *newstring, int *substringsize)
{
  CUtlVector<StringHistoryEntry,CUtlMemory<StringHistoryEntry,int> > *history; // ecx
  int v3; // eax
  StringHistoryEntry *m_pMemory; // ecx
  int v5; // edi
  char v6; // dl
  int v7; // esi
  const char *v8; // ecx
  int c; // [esp+8h] [ebp-10h]
  int bestindex; // [esp+Ch] [ebp-Ch]
  StringHistoryEntry *v12; // [esp+10h] [ebp-8h]
  int bestcount; // [esp+14h] [ebp-4h]

  v3 = 0;
  bestindex = -1;
  bestcount = 0;
  c = history->m_Size;
  if ( c <= 0 )
  {
    *substringsize = 0;
    return -1;
  }
  else
  {
    m_pMemory = history->m_Memory.m_pMemory;
    v5 = (char *)m_pMemory - newstring;
    v12 = m_pMemory;
    do
    {
      v6 = m_pMemory->string[0];
      v7 = 0;
      if ( m_pMemory->string[0] != 0 )
      {
        v8 = newstring;
        do
        {
          if ( *v8 == 0 )
            break;
          if ( v6 != *v8 )
            break;
          if ( v7 >= 31 )
            break;
          v6 = (v8++)[v5 + 1];
          ++v7;
        }
        while ( v6 != 0 );
        if ( v7 >= 3 && v7 > bestcount )
        {
          bestcount = v7;
          bestindex = v3;
        }
      }
      ++v3;
      m_pMemory = v12 + 1;
      v5 += 32;
      ++v12;
    }
    while ( v3 < c );
    *substringsize = bestcount;
    return bestindex;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C34E0
// Name: public: virtual void CNetworkStringTableDictionaryManager::OnBSPFullyUnloaded(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableDictionaryManager::OnBSPFullyUnloaded(CNetworkStringTableDictionaryManager *this)
{
  const char *v2; // eax
  CUtlBuffer *p_m_Buffer; // [esp-8h] [ebp-10h]
  bool m_bCreatingForX360; // [esp-4h] [ebp-Ch]

  if ( this->m_BuildStringTableDictionaryCache.m_bActive )
  {
    m_bCreatingForX360 = this->m_BuildStringTableDictionaryCache.m_bCreatingForX360;
    p_m_Buffer = &this->m_BuildStringTableDictionaryCache.m_Buffer;
    v2 = CUtlString::operator char const *(this: &this->m_BuildStringTableDictionaryCache.m_sBSPName);
    CNetworkStringTableDictionaryManager::WriteDictionaryToBSP(
      this,
      pchMapName: v2,
      buf: p_m_Buffer,
      bCreatingFor360: m_bCreatingForX360);
    this->m_BuildStringTableDictionaryCache.m_bActive = false;
    CUtlString::operator=(this: &this->m_BuildStringTableDictionaryCache.m_sBSPName, src: defaultValue);
    this->m_BuildStringTableDictionaryCache.m_bCreatingForX360 = false;
    this->m_BuildStringTableDictionaryCache.m_Buffer.m_Get = 0;
    this->m_BuildStringTableDictionaryCache.m_Buffer.m_Put = 0;
    this->m_BuildStringTableDictionaryCache.m_Buffer.m_nOffset = 0;
    this->m_BuildStringTableDictionaryCache.m_Buffer.m_nMaxPut = 0;
    this->m_BuildStringTableDictionaryCache.m_Buffer.m_Error = 0;
    if ( this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(
          this: _g_pMemAlloc,
          a2: this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_pMemory);
        this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_pMemory = nullptr;
      }
      this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_nAllocationCount = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C3560
// Name: public: virtual class INetworkStringTable __near * CNetworkStringTableContainer::FindTable(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CNetworkStringTable *__thiscall CNetworkStringTableContainer::FindTable(
        CNetworkStringTableContainer *this,
        const char *tableName)
{
  int v3; // esi
  CNetworkStringTable *v4; // ecx
  const char *v5; // eax

  v3 = 0;
  if ( this->m_Tables.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = this->m_Tables.m_Memory.m_pMemory[v3];
    v5 = v4->GetTableName(this: v4);
    if ( _V_stricmp(s1: tableName, s2: v5) == 0 )
      break;
    if ( ++v3 >= this->m_Tables.m_Size )
      return nullptr;
  }
  return this->m_Tables.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x101C35B0
// Name: public: virtual class INetworkStringTable __near * CNetworkStringTableContainer::GetTable(int)const
// Source: json
//------------------------------------------------------------------------------
CNetworkStringTable *__thiscall CNetworkStringTableContainer::GetTable(
        CNetworkStringTableContainer *this,
        int stringTable)
{
  if ( stringTable < 0 || stringTable >= this->m_Tables.m_Size )
    return nullptr;
  else
    return this->m_Tables.m_Memory.m_pMemory[stringTable];
}

//------------------------------------------------------------------------------
// Address: 0x101C35D0
// Name: public: void CNetworkStringTableContainer::WriteStringTables(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableContainer::WriteStringTables(CNetworkStringTableContainer *this, bf_write *buf)
{
  CNetworkStringTableContainer *v3; // edi
  CNetworkStringTable *v4; // edi
  const char *v5; // eax
  int j; // ebx
  const char *v7; // eax
  int v8; // eax
  int m_iCurBit; // ecx
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int *k; // ebx
  const char *v14; // eax
  CNetworkStringTableItem *v15; // eax
  void *UserData; // eax
  int v17; // ecx
  signed int numTables; // [esp+Ch] [ebp-18h]
  void *pBuf; // [esp+10h] [ebp-14h]
  void *pBufa; // [esp+10h] [ebp-14h]
  int i; // [esp+18h] [ebp-Ch]
  int v23; // [esp+1Ch] [ebp-8h] BYREF
  int nBytes; // [esp+20h] [ebp-4h] BYREF
  bf_write *bufa; // [esp+2Ch] [ebp+8h]
  bf_write *bufb; // [esp+2Ch] [ebp+8h]

  v3 = this;
  numTables = this->m_Tables.m_Size;
  bf_write::WriteByte(this: buf, val: numTables);
  i = 0;
  if ( numTables > 0 )
  {
    while ( 1 )
    {
      v4 = v3->m_Tables.m_Memory.m_pMemory[i];
      v5 = v4->GetTableName(this: v4);
      bf_write::WriteString(this: buf, pStr: v5);
      bufa = (bf_write *)v4->m_pItems->Count(this: v4->m_pItems);
      bf_write::WriteWord(this: buf, val: (unsigned int)bufa);
      for ( j = 0; j < (int)bufa; ++j )
      {
        v7 = v4->GetString(this: v4, a2: j);
        bf_write::WriteString(this: buf, pStr: v7);
        v8 = (int)v4->GetStringUserData(this: v4, a2: j, a3: &nBytes);
        m_iCurBit = buf->m_iCurBit;
        pBuf = (void *)v8;
        v10 = m_iCurBit + 1;
        if ( nBytes <= 0 )
        {
          if ( v10 <= buf->m_nDataBits )
          {
            if ( !buf->m_bOverflow )
            {
              buf->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
              ++buf->m_iCurBit;
            }
          }
          else
          {
            buf->m_bOverflow = true;
          }
        }
        else
        {
          if ( v10 <= buf->m_nDataBits )
          {
            if ( !buf->m_bOverflow )
            {
              buf->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
              ++buf->m_iCurBit;
            }
          }
          else
          {
            buf->m_bOverflow = true;
          }
          bf_write::WriteWord(this: buf, val: (__int16)nBytes);
          bf_write::WriteBytes(this: buf, pBuf, nBytes);
        }
      }
      v11 = buf->m_iCurBit;
      v12 = v11 + 1;
      if ( v4->m_pItemsClientSide != nullptr )
      {
        if ( v12 <= buf->m_nDataBits )
        {
          if ( !buf->m_bOverflow )
          {
            buf->m_pData[v11 >> 3] |= 1 << (v11 & 7);
            ++buf->m_iCurBit;
          }
        }
        else
        {
          buf->m_bOverflow = true;
        }
        bufb = (bf_write *)v4->m_pItemsClientSide->Count(this: v4->m_pItemsClientSide);
        bf_write::WriteWord(this: buf, val: (unsigned int)bufb);
        for ( k = nullptr; (int)k < (int)bufb; k = (int *)((char *)k + 1) )
        {
          v14 = (const char *)((int (__thiscall *)(INetworkStringDict_vtbl **))v4->m_pItemsClientSide->String)(a1: &v4->m_pItemsClientSide->__vftable);
          bf_write::WriteString(this: buf, pStr: v14);
          v15 = (CNetworkStringTableItem *)((int (__thiscall *)(INetworkStringDict_vtbl **, int *, int *))v4->m_pItemsClientSide->Element_2)(
                                             a1: &v4->m_pItemsClientSide->__vftable,
                                             a2: k,
                                             a3: &v23);
          UserData = (void *)CNetworkStringTableItem::GetUserData(this: v15, length: k);
          v17 = buf->m_iCurBit;
          pBufa = UserData;
          if ( v23 <= 0 )
          {
            if ( v17 + 1 <= buf->m_nDataBits )
            {
              if ( !buf->m_bOverflow )
              {
                buf->m_pData[v17 >> 3] &= ~(1 << (v17 & 7));
                ++buf->m_iCurBit;
              }
            }
            else
            {
              buf->m_bOverflow = true;
            }
          }
          else
          {
            if ( v17 + 1 <= buf->m_nDataBits )
            {
              if ( !buf->m_bOverflow )
              {
                buf->m_pData[v17 >> 3] |= 1 << (v17 & 7);
                ++buf->m_iCurBit;
              }
            }
            else
            {
              buf->m_bOverflow = true;
            }
            bf_write::WriteWord(this: buf, val: (__int16)v23);
            bf_write::WriteBytes(this: buf, pBuf: pBufa, nBytes: v23);
          }
        }
      }
      else if ( v12 <= buf->m_nDataBits )
      {
        if ( !buf->m_bOverflow )
        {
          buf->m_pData[v11 >> 3] &= ~(1 << (v11 & 7));
          ++buf->m_iCurBit;
        }
      }
      else
      {
        buf->m_bOverflow = true;
      }
      if ( ++i >= numTables )
        break;
      v3 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C3840
// Name: public: void CNetworkStringTableContainer::Dump(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableContainer::Dump(CNetworkStringTableContainer *this)
{
  int i; // esi
  CNetworkStringTable *v3; // ecx

  for ( i = 0; i < this->m_Tables.m_Size; ++i )
  {
    v3 = this->m_Tables.m_Memory.m_pMemory[i];
    v3->Dump(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C3C60
// Name: public: virtual void CNetworkStringTableContainer::RemoveAllTables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableContainer::RemoveAllTables(CNetworkStringTableContainer *this)
{
  CNetworkStringTable *v2; // edi

  while ( this->m_Tables.m_Size > 0 )
  {
    v2 = *this->m_Tables.m_Memory.m_pMemory;
    if ( this->m_Tables.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_Tables.m_Memory.m_pMemory,
        src: this->m_Tables.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_Tables.m_Size - 1));
    --this->m_Tables.m_Size;
    if ( v2 != nullptr )
      ((void (__thiscall *)(CNetworkStringTable *, int))v2->dtr_INetworkStringTable)(a1: v2, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C3CB0
// Name: public: virtual void CNetworkStringTableContainer::CreateDictionary(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableContainer::CreateDictionary(
        CNetworkStringTableContainer *this,
        const char *pchMapName)
{
  const char *v2; // esi
  CNetworkStringTableContainer *v3; // ebx
  int v4; // edi
  int v5; // eax
  CNetworkStringTable *v6; // esi
  int v7; // ebx
  const char *v8; // eax
  CMapReslistGenerator *v9; // eax
  bool IsCreatingForXbox; // bl
  char mapPath[260]; // [esp+8h] [ebp-13Ch] BYREF
  CUtlBuffer buf; // [esp+10Ch] [ebp-38h] BYREF
  CNetworkStringTableContainer *v13; // [esp+13Ch] [ebp-8h]
  int i; // [esp+140h] [ebp-4h]

  v2 = pchMapName;
  v3 = this;
  v13 = this;
  V_snprintf(pDest: mapPath, maxLen: 260, pFormat: "maps/%s.bsp", pchMapName);
  if ( g_pFileSystem->IsFileWritable(this: &g_pFileSystem->IBaseFileSystem, a2: mapPath, a3: "GAME") )
  {
    _Msg(a1: "Creating dictionary %s\n", pchMapName);
    v4 = 0;
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
    v5 = 0;
    i = 0;
    if ( v3->m_Tables.m_Size > 0 )
    {
      do
      {
        v6 = v3->m_Tables.m_Memory.m_pMemory[v5];
        if ( (v6->m_nFlags & 1) != 0 )
        {
          v7 = v6->GetNumStrings(this: v6);
          if ( v7 > 0 )
          {
            do
            {
              v8 = v6->GetString(this: v6, a2: v4);
              if ( *v8 != 0 )
                CUtlBuffer::PutString(this: &buf, pString: v8);
              ++v4;
            }
            while ( v4 < v7 );
          }
          v3 = v13;
          v4 = 0;
        }
        v5 = i + 1;
        i = v5;
      }
      while ( v5 < v3->m_Tables.m_Size );
      v2 = pchMapName;
    }
    v9 = MapReslistGenerator();
    IsCreatingForXbox = CMapReslistGenerator::IsCreatingForXbox(this: v9);
    g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_bActive = true;
    CUtlString::operator=(this: &g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_sBSPName, src: v2);
    g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_Buffer.m_Get = 0;
    g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_Buffer.m_Put = 0;
    g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_Buffer.m_nOffset = 0;
    g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_Buffer.m_nMaxPut = 0;
    g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_Buffer.m_Error = 0;
    if ( g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(
          this: _g_pMemAlloc,
          a2: g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_pMemory);
        g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_pMemory = nullptr;
      }
      g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_nAllocationCount = 0;
    }
    CUtlBuffer::Put(
      this: &g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_Buffer,
      pMem: buf.m_Memory.m_pMemory,
      size: buf.m_Put);
    g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_bCreatingForX360 = IsCreatingForXbox;
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
  else
  {
    _Warning(a1: "#####################################################################################\n");
    _Warning(a1: "Can't recreate dictionary for %s, file must be writable!!!\n", mapPath);
    _Warning(a1: "#####################################################################################\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C45F0
// Name: public: CNetworkStringTableDictionaryManager::CStringTableDictionaryCache::CStringTableDictionaryCache(void)
// Source: json
//------------------------------------------------------------------------------
CNetworkStringTableDictionaryManager::CStringTableDictionaryCache *__thiscall CNetworkStringTableDictionaryManager::CStringTableDictionaryCache::CStringTableDictionaryCache(
        CNetworkStringTableDictionaryManager::CStringTableDictionaryCache *this)
{
  CUtlString::CUtlString(this: &this->m_sBSPName);
  CUtlBuffer::CUtlBuffer(this: &this->m_Buffer, growSize: 0, initSize: 0, nFlags: 0);
  this->m_bActive = false;
  CUtlString::operator=(this: &this->m_sBSPName, src: defaultValue);
  this->m_bCreatingForX360 = false;
  this->m_Buffer.m_Get = 0;
  this->m_Buffer.m_Put = 0;
  this->m_Buffer.m_nOffset = 0;
  this->m_Buffer.m_nMaxPut = 0;
  this->m_Buffer.m_Error = 0;
  if ( this->m_Buffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Buffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Buffer.m_Memory.m_pMemory);
      this->m_Buffer.m_Memory.m_pMemory = nullptr;
    }
    this->m_Buffer.m_Memory.m_nAllocationCount = 0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C4660
// Name: public: CNetworkStringTableContainer::CNetworkStringTableContainer(void)
// Source: json
//------------------------------------------------------------------------------
CNetworkStringTableContainer *__thiscall CNetworkStringTableContainer::CNetworkStringTableContainer(
        CNetworkStringTableContainer *this)
{
  this->__vftable = (CNetworkStringTableContainer_vtbl *)&CNetworkStringTableContainer::`vftable';
  this->m_Tables.m_Memory.m_pMemory = nullptr;
  this->m_Tables.m_Memory.m_nAllocationCount = 0;
  this->m_Tables.m_Memory.m_nGrowSize = 0;
  this->m_Tables.m_Size = 0;
  this->m_Tables.m_pElements = nullptr;
  this->m_bAllowCreation = false;
  this->m_nTickCount = 0;
  *(_WORD *)&this->m_bLocked = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C4690
// Name: public: virtual CNetworkStringTableContainer::~CNetworkStringTableContainer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableContainer::~CNetworkStringTableContainer(CNetworkStringTableContainer *this)
{
  this->__vftable = (CNetworkStringTableContainer_vtbl *)&CNetworkStringTableContainer::`vftable';
  CNetworkStringTableContainer::RemoveAllTables(this);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Tables);
  this->__vftable = (CNetworkStringTableContainer_vtbl *)&INetworkStringTableContainer::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x101C46B0
// Name: public: int CNetworkStringTable::WriteUpdate(class CBaseClient __near *,class bf_write __near &,int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetworkStringTable::WriteUpdate(CNetworkStringTable *this, CBaseClient *client, int buf, int tick_ack)
{
  bool v5; // zf
  int v6; // eax
  int v8; // ecx
  int v9; // esi
  int v10; // edi
  char v11; // cl
  signed int v12; // edi
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  int v16; // edx
  int v17; // eax
  int v18; // edi
  int v19; // ecx
  int v20; // edx
  int v21; // ecx
  int v22; // edx
  unsigned __int8 *v23; // edx
  int v24; // esi
  unsigned int BestPreviousString; // eax
  int v26; // ecx
  int v27; // esi
  CNetworkStringTable *v28; // esi
  const void *v29; // edi
  int v30; // ecx
  int v31; // ecx
  int v32; // esi
  int m_Size; // edi
  int v34; // esi
  int v35; // edi
  StringHistoryEntry *v36; // edi
  CNetworkStringTable *v37; // edi
  int v38; // esi
  int v39; // eax
  const char *v40; // eax
  const char *v41; // eax
  int v43; // [esp-8h] [ebp-78h]
  int v44; // [esp-8h] [ebp-78h]
  const char *v45; // [esp-4h] [ebp-74h]
  const char *v46; // [esp-4h] [ebp-74h]
  int v47; // [esp-4h] [ebp-74h]
  StringHistoryEntry she; // [esp+Ch] [ebp-64h] BYREF
  CUtlVector<StringHistoryEntry,CUtlMemory<StringHistoryEntry,int> > history; // [esp+2Ch] [ebp-44h] BYREF
  int count; // [esp+40h] [ebp-30h]
  int nStartBit; // [esp+44h] [ebp-2Ch]
  int nDictionaryEncodeBits; // [esp+48h] [ebp-28h]
  CNetworkStringTableItem *p; // [esp+4Ch] [ebp-24h]
  int substringsize; // [esp+50h] [ebp-20h] BYREF
  int lastDictionaryIndex; // [esp+54h] [ebp-1Ch]
  int nDictionaryCount; // [esp+58h] [ebp-18h]
  int len; // [esp+5Ch] [ebp-14h] BYREF
  const char *pEntry; // [esp+60h] [ebp-10h]
  int entriesUpdated; // [esp+64h] [ebp-Ch]
  CNetworkStringTable *v60; // [esp+68h] [ebp-8h]
  bool bEncodeUsingDictionaries; // [esp+6Fh] [ebp-1h]
  int i; // [esp+7Ch] [ebp+Ch]

  v5 = (this->m_nFlags & 1) == 0;
  substringsize = -1;
  lastDictionaryIndex = -1;
  v60 = this;
  memset(&history, 0, sizeof(history));
  entriesUpdated = 0;
  nDictionaryEncodeBits = g_StringTableDictionary.m_nEncodeBits;
  if ( v5
    || stringtable_usedictionaries.m_pParent == nullptr
    || stringtable_usedictionaries.m_pParent->m_Value.m_nValue == 0
    || (bEncodeUsingDictionaries = true, g_StringTableDictionary.m_Strings.m_Size <= 0) )
  {
    bEncodeUsingDictionaries = false;
  }
  V_FileBase(in: com_gamedir, out: gamedir_8, maxlen: 260);
  if ( _V_stricmp(s1: gamedir_8, s2: "infested") == 0 )
    bEncodeUsingDictionaries = false;
  v6 = this->m_pItems->Count(this: this->m_pItems);
  v8 = *(_DWORD *)(buf + 12);
  v9 = v6;
  count = v6;
  nDictionaryCount = 0;
  if ( v8 + 1 > *(_DWORD *)(buf + 8) )
    *(_BYTE *)(buf + 16) = 1;
  if ( *(_BYTE *)(buf + 16) == 0 )
  {
    v10 = v8 >> 3;
    v11 = v8 & 7;
    if ( bEncodeUsingDictionaries )
      *(_BYTE *)(v10 + *(_DWORD *)buf) |= 1 << v11;
    else
      *(_BYTE *)(v10 + *(_DWORD *)buf) &= ~(1 << v11);
    ++*(_DWORD *)(buf + 12);
  }
  v12 = 0;
  i = 0;
  if ( v6 > 0 )
  {
    while ( 1 )
    {
      p = v60->m_pItems->Element_2(this: v60->m_pItems, a2: v12);
      if ( p->m_nTickChanged > tick_ack )
        break;
LABEL_95:
      v9 = count;
      v12 = i + 1;
      i = v12;
      if ( v12 >= count )
        goto LABEL_96;
    }
    v13 = *(_DWORD *)(buf + 12);
    nStartBit = v13;
    v14 = v13 + 1;
    if ( substringsize + 1 == v12 )
    {
      if ( v14 <= *(_DWORD *)(buf + 8) )
      {
        if ( *(_BYTE *)(buf + 16) == 0 )
        {
          *(_BYTE *)((v13 >> 3) + *(_DWORD *)buf) |= 1 << (v13 & 7);
          ++*(_DWORD *)(buf + 12);
        }
      }
      else
      {
        *(_BYTE *)(buf + 16) = 1;
      }
    }
    else
    {
      if ( v14 <= *(_DWORD *)(buf + 8) )
      {
        if ( *(_BYTE *)(buf + 16) == 0 )
        {
          *(_BYTE *)((v13 >> 3) + *(_DWORD *)buf) &= ~(1 << (v13 & 7));
          ++*(_DWORD *)(buf + 12);
        }
      }
      else
      {
        *(_BYTE *)(buf + 16) = 1;
      }
      bf_write::WriteUBitLong(this: (bf_write *)buf, curData: v12, numbits: v60->m_nEntryBits, bCheckRange: true);
    }
    pEntry = v60->m_pItems->String(this: v60->m_pItems, a2: v12);
    v15 = *(_DWORD *)(buf + 12);
    v16 = v15 + 1;
    if ( p->m_nTickCreated <= tick_ack )
    {
      if ( v16 <= *(_DWORD *)(buf + 8) )
      {
        if ( *(_BYTE *)(buf + 16) == 0 )
          *(_BYTE *)(((int)(*(_DWORD *)(buf + 12))++ >> 3) + *(_DWORD *)buf) &= ~(1 << (v15 & 7));
      }
      else
      {
        *(_BYTE *)(buf + 16) = 1;
      }
      goto LABEL_68;
    }
    if ( v16 <= *(_DWORD *)(buf + 8) )
    {
      if ( *(_BYTE *)(buf + 16) == 0 )
        *(_BYTE *)(((int)(*(_DWORD *)(buf + 12))++ >> 3) + *(_DWORD *)buf) |= 1 << (v15 & 7);
    }
    else
    {
      *(_BYTE *)(buf + 16) = 1;
    }
    v17 = v60->m_pItems->DictionaryIndex(this: v60->m_pItems, a2: v12);
    v18 = v17;
    if ( bEncodeUsingDictionaries )
    {
      v19 = *(_DWORD *)(buf + 12);
      v20 = v19 + 1;
      if ( v17 != -1 )
      {
        ++nDictionaryCount;
        if ( v20 <= *(_DWORD *)(buf + 8) )
        {
          if ( *(_BYTE *)(buf + 16) == 0 )
          {
            *(_BYTE *)((v19 >> 3) + *(_DWORD *)buf) |= 1 << (v19 & 7);
            ++*(_DWORD *)(buf + 12);
          }
        }
        else
        {
          *(_BYTE *)(buf + 16) = 1;
        }
        v21 = *(_DWORD *)(buf + 12);
        v22 = v21 + 1;
        if ( lastDictionaryIndex + 1 == v17 )
        {
          if ( v22 > *(_DWORD *)(buf + 8) )
          {
            *(_BYTE *)(buf + 16) = 1;
            lastDictionaryIndex = v17;
            goto LABEL_68;
          }
          if ( *(_BYTE *)(buf + 16) == 0 )
          {
            v23 = *(unsigned __int8 **)buf;
            v24 = *(int *)(buf + 12) >> 3;
            lastDictionaryIndex = v17;
            v23[v24] |= 1 << (v21 & 7);
            ++*(_DWORD *)(buf + 12);
            goto LABEL_68;
          }
        }
        else
        {
          if ( v22 <= *(_DWORD *)(buf + 8) )
          {
            if ( *(_BYTE *)(buf + 16) == 0 )
              *(_BYTE *)(((int)(*(_DWORD *)(buf + 12))++ >> 3) + *(_DWORD *)buf) &= ~(1 << (v21 & 7));
          }
          else
          {
            *(_BYTE *)(buf + 16) = 1;
          }
          bf_write::WriteUBitLong(
            this: (bf_write *)buf,
            curData: v17,
            numbits: nDictionaryEncodeBits,
            bCheckRange: true);
        }
        lastDictionaryIndex = v18;
LABEL_68:
        v28 = v60;
        v29 = v60->GetStringUserData(this: v60, a2: i, a3: &len);
        if ( v29 != nullptr && len > 0 )
        {
          v30 = *(_DWORD *)(buf + 12);
          if ( v30 + 1 <= *(_DWORD *)(buf + 8) )
          {
            if ( *(_BYTE *)(buf + 16) == 0 )
            {
              *(_BYTE *)(((int)(*(_DWORD *)(buf + 12))++ >> 3) + *(_DWORD *)buf) |= 1 << (v30 & 7);
              v28 = v60;
            }
          }
          else
          {
            *(_BYTE *)(buf + 16) = 1;
          }
          if ( (*((_BYTE *)v28 + 28) & 8) != 0 )
          {
            bf_write::WriteBits(this: (bf_write *)buf, pInData: v29, nBits: v28->m_nUserDataSizeBits);
          }
          else
          {
            bf_write::WriteUBitLong(this: (bf_write *)buf, curData: len, numbits: 14, bCheckRange: true);
            bf_write::WriteBits(this: (bf_write *)buf, pInData: v29, nBits: 8 * len);
          }
        }
        else
        {
          v31 = *(_DWORD *)(buf + 12);
          if ( v31 + 1 <= *(_DWORD *)(buf + 8) )
          {
            if ( *(_BYTE *)(buf + 16) == 0 )
              *(_BYTE *)(((int)(*(_DWORD *)(buf + 12))++ >> 3) + *(_DWORD *)buf) &= ~(1 << (v31 & 7));
          }
          else
          {
            *(_BYTE *)(buf + 16) = 1;
          }
        }
        if ( history.m_Size <= 31 )
        {
          m_Size = history.m_Size;
        }
        else
        {
          v32 = history.m_Size - 1;
          _V_memmove(dest: history.m_Memory.m_pMemory, src: &history.m_Memory.m_pMemory[1], count: 32 * v32);
          m_Size = v32;
          history.m_Size = v32;
        }
        V_strncpy(pDest: she.string, pSrc: pEntry, maxLen: 32);
        v34 = m_Size;
        if ( m_Size + 1 > history.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>::Grow(
            this: (CUtlMemory<vgui::RichText::TFormatStream,int> *)&history,
            num: m_Size - history.m_Memory.m_nAllocationCount + 1);
          m_Size = history.m_Size;
        }
        v35 = m_Size + 1;
        history.m_pElements = history.m_Memory.m_pMemory;
        history.m_Size = v35;
        if ( v35 - v34 - 1 > 0 )
          _V_memmove(
            dest: &history.m_Memory.m_pMemory[v34 + 1],
            src: &history.m_Memory.m_pMemory[v34],
            count: 32 * (v35 - v34 - 1));
        v36 = &history.m_Memory.m_pMemory[v34];
        if ( v36 != nullptr )
          *v36 = she;
        ++entriesUpdated;
        substringsize = i;
        if ( client != nullptr && CBaseClient::IsTracing(this: client) )
        {
          v37 = v60;
          v38 = *(_DWORD *)(buf + 12);
          v39 = (int)v60->GetString(this: v60, a2: i);
          v40 = (const char *)((int (__thiscall *)(CNetworkStringTable *, int, int))v37->GetTableName)(
                                a1: v37,
                                a2: i,
                                a3: v39);
          CBaseClient::TraceNetworkMsg(this: client, nBits: v38 - nStartBit, fmt: " [%s] %d:%s ", v40, v43, v46);
        }
        goto LABEL_95;
      }
      if ( v20 <= *(_DWORD *)(buf + 8) )
      {
        if ( *(_BYTE *)(buf + 16) == 0 )
          *(_BYTE *)(((int)(*(_DWORD *)(buf + 12))++ >> 3) + *(_DWORD *)buf) &= ~(1 << (v19 & 7));
      }
      else
      {
        *(_BYTE *)(buf + 16) = 1;
      }
    }
    substringsize = 0;
    BestPreviousString = GetBestPreviousString(&history, newstring: pEntry, &substringsize);
    v26 = *(_DWORD *)(buf + 12);
    if ( BestPreviousString == -1 )
    {
      if ( v26 + 1 <= *(_DWORD *)(buf + 8) )
      {
        if ( *(_BYTE *)(buf + 16) == 0 )
          *(_BYTE *)(((int)(*(_DWORD *)(buf + 12))++ >> 3) + *(_DWORD *)buf) &= ~(1 << (v26 & 7));
        bf_write::WriteString(this: (bf_write *)buf, pStr: pEntry);
      }
      else
      {
        v45 = pEntry;
        *(_BYTE *)(buf + 16) = 1;
        bf_write::WriteString(this: (bf_write *)buf, pStr: v45);
      }
    }
    else
    {
      if ( v26 + 1 <= *(_DWORD *)(buf + 8) )
      {
        if ( *(_BYTE *)(buf + 16) == 0 )
          *(_BYTE *)(((int)(*(_DWORD *)(buf + 12))++ >> 3) + *(_DWORD *)buf) |= 1 << (v26 & 7);
      }
      else
      {
        *(_BYTE *)(buf + 16) = 1;
      }
      bf_write::WriteUBitLong(this: (bf_write *)buf, curData: BestPreviousString, numbits: 5, bCheckRange: true);
      v27 = substringsize;
      bf_write::WriteUBitLong(this: (bf_write *)buf, curData: substringsize, numbits: 5, bCheckRange: true);
      bf_write::WriteString(this: (bf_write *)buf, pStr: &pEntry[v27]);
    }
    goto LABEL_68;
  }
LABEL_96:
  if ( tick_ack == -1
    && v9 > 20
    && bEncodeUsingDictionaries
    && (float)((float)v9 * 0.89999998) > (float)nDictionaryCount )
  {
    v41 = (const char *)((int (__thiscall *)(CNetworkStringTable *, int, int))v60->GetTableName)(
                          a1: v60,
                          a2: nDictionaryCount,
                          a3: v9);
    _Warning(
      a1: "String Table dictionary for %s should be rebuilt, only found %d of %d strings in dictionary\n",
      v41,
      v44,
      v47);
  }
  if ( history.m_Memory.m_nGrowSize >= 0 && history.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: history.m_Memory.m_pMemory);
  return entriesUpdated;
}

//------------------------------------------------------------------------------
// Address: 0x101C4C70
// Name: public: void CNetworkStringTable::ParseUpdate(class bf_read __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CNetworkStringTable::ParseUpdate(
        CNetworkStringTable *this@<ecx>,
        unsigned __int8 *a2@<edi>,
        bf_read *buf,
        int entries)
{
  unsigned int m_nInBufWord; // ecx
  int v6; // eax
  bool v7; // zf
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v10; // eax
  int v11; // edi
  int v12; // ecx
  const unsigned int *v13; // eax
  const unsigned int *v14; // edx
  CNetworkStringTable *v15; // esi
  int v16; // eax
  int v17; // ecx
  unsigned int v18; // edx
  unsigned int v19; // edi
  int v20; // ecx
  const unsigned int *v21; // eax
  const unsigned int *v22; // ecx
  const unsigned int *v23; // edx
  unsigned int v24; // edi
  const unsigned int *v25; // ecx
  unsigned int v26; // eax
  const char *v27; // eax
  unsigned int v28; // eax
  int v29; // ecx
  const unsigned int *v30; // eax
  const unsigned int *v31; // edx
  unsigned int v32; // eax
  int v33; // edx
  const unsigned int *v34; // eax
  const unsigned int *v35; // ecx
  unsigned int v36; // eax
  int v37; // edx
  const unsigned int *v38; // eax
  const unsigned int *v39; // ecx
  int v40; // edi
  int m_nBitsAvail; // ecx
  char v42; // dl
  unsigned int v43; // eax
  int v44; // ecx
  const unsigned int *v45; // eax
  const unsigned int *v46; // ecx
  unsigned int v47; // edi
  const unsigned int *v48; // edx
  int v49; // eax
  const unsigned int *v50; // ecx
  unsigned int v51; // edx
  unsigned int v52; // esi
  const char *v53; // eax
  unsigned int v54; // eax
  int v55; // edx
  const unsigned int *v56; // eax
  const unsigned int *v57; // ecx
  int v58; // ecx
  unsigned int v59; // eax
  unsigned int v60; // edi
  int v61; // ecx
  const unsigned int *v62; // eax
  const unsigned int *v63; // ecx
  const unsigned int *v64; // edx
  unsigned int v65; // edi
  int v66; // eax
  const unsigned int *v67; // ecx
  unsigned int v68; // edx
  unsigned int v69; // esi
  int v70; // ecx
  unsigned int v71; // eax
  int v72; // edx
  int v73; // ecx
  int v74; // eax
  const unsigned int *v75; // eax
  const unsigned int *v76; // ecx
  unsigned int v77; // ecx
  const unsigned int *v78; // edx
  unsigned int v79; // esi
  int v80; // eax
  const unsigned int *v81; // ecx
  unsigned int v82; // edx
  unsigned int v83; // edi
  int v84; // esi
  unsigned int v85; // edx
  unsigned int m_nUserDataSize; // esi
  unsigned int v87; // eax
  int v88; // ecx
  const unsigned int *v89; // eax
  const unsigned int *v90; // edx
  CNetworkStringTable *v91; // edi
  int v92; // ecx
  unsigned int v93; // eax
  int v94; // ecx
  unsigned int v95; // edx
  const unsigned int *v96; // eax
  const unsigned int *v97; // ecx
  const unsigned int *v98; // edx
  unsigned int v99; // esi
  int v100; // eax
  const unsigned int *v101; // ecx
  unsigned int v102; // edx
  unsigned int v103; // edi
  int v104; // eax
  const char *v105; // eax
  int v106; // edi
  int v107; // esi
  int v108; // edi
  vgui::RichText::TFormatStream *v109; // edi
  int m_nUserDataSizeBits; // [esp-8h] [ebp-4864h]
  int v112; // [esp-4h] [ebp-4860h]
  unsigned __int8 dst[16384]; // [esp+8h] [ebp-4854h] BYREF
  char pStr[1024]; // [esp+4008h] [ebp-854h] BYREF
  char pDest[1024]; // [esp+4408h] [ebp-454h] BYREF
  char v117[32]; // [esp+4808h] [ebp-54h] BYREF
  int m_nEncodeBits; // [esp+4828h] [ebp-34h]
  int v119; // [esp+482Ch] [ebp-30h]
  int v120; // [esp+4830h] [ebp-2Ch]
  CUtlMemory<vgui::RichText::TFormatStream,int> dest; // [esp+4834h] [ebp-28h] BYREF
  int v122; // [esp+4840h] [ebp-1Ch]
  vgui::RichText::TFormatStream *m_pMemory; // [esp+4844h] [ebp-18h]
  int v124; // [esp+4848h] [ebp-14h]
  unsigned __int8 *v125; // [esp+484Ch] [ebp-10h]
  int v126; // [esp+4850h] [ebp-Ch]
  CNetworkStringTable *v127; // [esp+4854h] [ebp-8h]
  char *pSrc; // [esp+4858h] [ebp-4h]
  bool v129; // [esp+4867h] [ebp+Bh]

  v127 = this;
  m_nInBufWord = buf->m_nInBufWord;
  m_nEncodeBits = g_StringTableDictionary.m_nEncodeBits;
  v6 = m_nInBufWord & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  v119 = -1;
  v124 = -1;
  if ( v7 )
  {
    m_pDataIn = buf->m_pDataIn;
    m_pBufferEnd = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      buf->m_nInBufWord = *m_pDataIn;
      buf->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = m_nInBufWord >> 1;
  }
  v129 = v6 != 0;
  memset(&dest, 0, sizeof(dest));
  v122 = 0;
  m_pMemory = nullptr;
  v120 = 0;
  if ( entries > 0 )
  {
    while ( 1 )
    {
      v10 = buf->m_nInBufWord;
      v11 = v119 + 1;
      v12 = v10 & 1;
      v7 = buf->m_nBitsAvail-- == 1;
      v126 = v11;
      if ( v7 )
      {
        v13 = buf->m_pDataIn;
        v14 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v13 == v14 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v13 + 1;
        }
        else if ( v13 <= v14 )
        {
          buf->m_nInBufWord = *v13;
          buf->m_pDataIn = v13 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
      }
      else
      {
        buf->m_nInBufWord = v10 >> 1;
      }
      v15 = v127;
      if ( v12 == 0 )
        break;
LABEL_36:
      v119 = v11;
      if ( v11 < 0 || v11 >= v15->GetMaxStrings(this: v15) )
      {
        v27 = v15->GetTableName(this: v15);
        Host_Error(error: "Server sent bogus string index %i for table %s\n", v11, v27);
      }
      v28 = buf->m_nInBufWord;
      v29 = v28 & 1;
      v7 = buf->m_nBitsAvail-- == 1;
      pSrc = nullptr;
      if ( v7 )
      {
        v30 = buf->m_pDataIn;
        v31 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v30 == v31 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v30 + 1;
        }
        else if ( v30 <= v31 )
        {
          buf->m_nInBufWord = *v30;
          buf->m_pDataIn = v30 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
      }
      else
      {
        buf->m_nInBufWord = v28 >> 1;
      }
      if ( v29 != 0 )
      {
        if ( v129 )
        {
          v32 = buf->m_nInBufWord;
          v33 = v32 & 1;
          v7 = buf->m_nBitsAvail-- == 1;
          if ( v7 )
          {
            v34 = buf->m_pDataIn;
            v35 = buf->m_pBufferEnd;
            buf->m_nBitsAvail = 32;
            if ( v34 == v35 )
            {
              buf->m_nBitsAvail = 1;
              buf->m_nInBufWord = 0;
              buf->m_pDataIn = v34 + 1;
            }
            else if ( v34 <= v35 )
            {
              buf->m_nInBufWord = *v34;
              buf->m_pDataIn = v34 + 1;
            }
            else
            {
              buf->m_bOverflow = true;
              buf->m_nInBufWord = 0;
            }
          }
          else
          {
            buf->m_nInBufWord = v32 >> 1;
          }
          if ( v33 != 0 )
          {
            v36 = buf->m_nInBufWord;
            v37 = v36 & 1;
            v7 = buf->m_nBitsAvail-- == 1;
            if ( v7 )
            {
              v38 = buf->m_pDataIn;
              v39 = buf->m_pBufferEnd;
              buf->m_nBitsAvail = 32;
              if ( v38 == v39 )
              {
                buf->m_nBitsAvail = 1;
                buf->m_nInBufWord = 0;
                buf->m_pDataIn = v38 + 1;
              }
              else if ( v38 <= v39 )
              {
                buf->m_nInBufWord = *v38;
                buf->m_pDataIn = v38 + 1;
              }
              else
              {
                buf->m_bOverflow = true;
                buf->m_nInBufWord = 0;
              }
            }
            else
            {
              buf->m_nInBufWord = v36 >> 1;
            }
            if ( v37 != 0 )
            {
              v40 = v124 + 1;
              goto LABEL_82;
            }
            m_nBitsAvail = buf->m_nBitsAvail;
            v42 = m_nEncodeBits;
            if ( m_nBitsAvail >= m_nEncodeBits )
            {
              v43 = buf->m_nInBufWord;
              v40 = v43 & CBitBuffer::s_nMaskTable[m_nEncodeBits];
              v44 = m_nBitsAvail - m_nEncodeBits;
              buf->m_nBitsAvail = v44;
              if ( v44 != 0 )
              {
                buf->m_nInBufWord = v43 >> v42;
              }
              else
              {
                v45 = buf->m_pDataIn;
                v46 = buf->m_pBufferEnd;
                buf->m_nBitsAvail = 32;
                if ( v45 == v46 )
                {
                  buf->m_nBitsAvail = 1;
                  buf->m_nInBufWord = 0;
                  buf->m_pDataIn = v45 + 1;
                }
                else if ( v45 <= v46 )
                {
                  buf->m_nInBufWord = *v45;
                  buf->m_pDataIn = v45 + 1;
                }
                else
                {
                  buf->m_bOverflow = true;
                  buf->m_nInBufWord = 0;
                }
              }
              goto LABEL_82;
            }
            v47 = buf->m_nInBufWord;
            v48 = buf->m_pBufferEnd;
            v49 = m_nEncodeBits - m_nBitsAvail;
            v50 = buf->m_pDataIn;
            if ( v50 == v48 )
            {
              buf->m_nBitsAvail = 1;
              buf->m_nInBufWord = 0;
              buf->m_bOverflow = true;
              goto LABEL_78;
            }
            if ( v50 <= v48 )
            {
              buf->m_nInBufWord = *v50;
LABEL_78:
              buf->m_pDataIn = v50 + 1;
            }
            else
            {
              buf->m_bOverflow = true;
              buf->m_nInBufWord = 0;
            }
            if ( buf->m_bOverflow )
            {
              v40 = 0;
            }
            else
            {
              v51 = buf->m_nInBufWord;
              v52 = (v51 & CBitBuffer::s_nMaskTable[v49]) << buf->m_nBitsAvail;
              buf->m_nBitsAvail = 32 - v49;
              v40 = v52 | v47;
              buf->m_nInBufWord = v51 >> v49;
            }
LABEL_82:
            v124 = v40;
            if ( v40 < 0 || v40 >= g_StringTableDictionary.m_Strings.m_Size )
              v53 = defaultValue;
            else
              v53 = CUtlString::operator char const *(this: &g_StringTableDictionary.m_Strings.m_Memory.m_pMemory[v40]);
            V_strncpy(pDest, pSrc: v53, maxLen: 1024);
LABEL_132:
            pSrc = pDest;
            goto LABEL_133;
          }
        }
        v54 = buf->m_nInBufWord;
        v55 = v54 & 1;
        v7 = buf->m_nBitsAvail-- == 1;
        if ( v7 )
        {
          v56 = buf->m_pDataIn;
          v57 = buf->m_pBufferEnd;
          buf->m_nBitsAvail = 32;
          if ( v56 == v57 )
          {
            buf->m_nBitsAvail = 1;
            buf->m_nInBufWord = 0;
            buf->m_pDataIn = v56 + 1;
          }
          else if ( v56 <= v57 )
          {
            buf->m_nInBufWord = *v56;
            buf->m_pDataIn = v56 + 1;
          }
          else
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
          }
        }
        else
        {
          buf->m_nInBufWord = v54 >> 1;
        }
        if ( v55 == 0 )
        {
          CBitRead::ReadString(this: buf, pStr: pDest, maxLen: 1024, bLine: false, pOutNumChars: nullptr);
          goto LABEL_132;
        }
        v58 = buf->m_nBitsAvail;
        if ( v58 >= 5 )
        {
          v59 = buf->m_nInBufWord;
          v60 = v59 & 0x1F;
          v61 = v58 - 5;
          buf->m_nBitsAvail = v61;
          if ( v61 != 0 )
          {
            buf->m_nInBufWord = v59 >> 5;
          }
          else
          {
            v62 = buf->m_pDataIn;
            v63 = buf->m_pBufferEnd;
            buf->m_nBitsAvail = 32;
            if ( v62 == v63 )
            {
              buf->m_nBitsAvail = 1;
              buf->m_nInBufWord = 0;
              buf->m_pDataIn = v62 + 1;
            }
            else if ( v62 <= v63 )
            {
              buf->m_nInBufWord = *v62;
              buf->m_pDataIn = v62 + 1;
            }
            else
            {
              buf->m_bOverflow = true;
              buf->m_nInBufWord = 0;
            }
          }
          goto LABEL_112;
        }
        v64 = buf->m_pBufferEnd;
        v65 = buf->m_nInBufWord;
        v66 = 5 - v58;
        v67 = buf->m_pDataIn;
        if ( v67 == v64 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_bOverflow = true;
          goto LABEL_108;
        }
        if ( v67 <= v64 )
        {
          buf->m_nInBufWord = *v67;
LABEL_108:
          buf->m_pDataIn = v67 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
        if ( buf->m_bOverflow )
        {
          v60 = 0;
        }
        else
        {
          v68 = buf->m_nInBufWord;
          v69 = (v68 & CBitBuffer::s_nMaskTable[v66]) << buf->m_nBitsAvail;
          buf->m_nBitsAvail = 32 - v66;
          v60 = v69 | v65;
          buf->m_nInBufWord = v68 >> v66;
        }
LABEL_112:
        v70 = buf->m_nBitsAvail;
        pSrc = (char *)v60;
        if ( v70 >= 5 )
        {
          v71 = buf->m_nInBufWord;
          v72 = v71 & 0x1F;
          v73 = v70 - 5;
          buf->m_nBitsAvail = v73;
          if ( v73 != 0 )
          {
            buf->m_nInBufWord = v71 >> 5;
            v74 = v71 & 0x1F;
          }
          else
          {
            v75 = buf->m_pDataIn;
            v76 = buf->m_pBufferEnd;
            buf->m_nBitsAvail = 32;
            if ( v75 == v76 )
            {
              buf->m_pDataIn = v75 + 1;
              buf->m_nBitsAvail = 1;
              buf->m_nInBufWord = 0;
              v74 = v72;
            }
            else
            {
              if ( v75 <= v76 )
              {
                v77 = *v75;
                buf->m_pDataIn = v75 + 1;
                buf->m_nInBufWord = v77;
              }
              else
              {
                buf->m_bOverflow = true;
                buf->m_nInBufWord = 0;
              }
              v74 = v72;
            }
          }
          goto LABEL_130;
        }
        v78 = buf->m_pBufferEnd;
        v79 = buf->m_nInBufWord;
        v80 = 5 - v70;
        v81 = buf->m_pDataIn;
        if ( v81 == v78 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_bOverflow = true;
          goto LABEL_126;
        }
        if ( v81 <= v78 )
        {
          buf->m_nInBufWord = *v81;
LABEL_126:
          buf->m_pDataIn = v81 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
        if ( buf->m_bOverflow )
        {
          v74 = 0;
        }
        else
        {
          v82 = buf->m_nInBufWord;
          v83 = (v82 & CBitBuffer::s_nMaskTable[v80]) << buf->m_nBitsAvail;
          buf->m_nBitsAvail = 32 - v80;
          v84 = v83 | v79;
          v60 = (unsigned int)pSrc;
          v85 = v82 >> v80;
          v74 = v84;
          buf->m_nInBufWord = v85;
        }
LABEL_130:
        V_strncpy(pDest, pSrc: (const char *)&dest.m_pMemory[v60], maxLen: v74 + 1);
        CBitRead::ReadString(this: buf, pStr, maxLen: 1024, bLine: false, pOutNumChars: nullptr);
        V_strncat(pDest, pSrc: pStr, destBufferSize: 0x400u, max_chars_to_copy: -1);
        goto LABEL_132;
      }
LABEL_133:
      m_nUserDataSize = 0;
      memset(dst, value: 0, count: sizeof(dst));
      v87 = buf->m_nInBufWord;
      v88 = v87 & 1;
      v7 = buf->m_nBitsAvail-- == 1;
      v125 = nullptr;
      if ( v7 )
      {
        v89 = buf->m_pDataIn;
        v90 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v89 == v90 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v89 + 1;
        }
        else if ( v89 <= v90 )
        {
          buf->m_nInBufWord = *v89;
          buf->m_pDataIn = v89 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
      }
      else
      {
        buf->m_nInBufWord = v87 >> 1;
      }
      v91 = v127;
      if ( v88 == 0 )
        goto LABEL_165;
      if ( (*((_BYTE *)v127 + 28) & 8) == 0 )
      {
        v92 = buf->m_nBitsAvail;
        if ( v92 >= 14 )
        {
          v93 = buf->m_nInBufWord;
          m_nUserDataSize = v93 & 0x3FFF;
          v94 = v92 - 14;
          v95 = 0;
          buf->m_nBitsAvail = v94;
          if ( v94 != 0 )
          {
            buf->m_nInBufWord = v93 >> 14;
LABEL_161:
            if ( m_nUserDataSize > 0x4000 )
            {
              _Error(a1: "CNetworkStringTableClient::ParseUpdate: message too large (%d bytes).", m_nUserDataSize);
              v91 = v127;
            }
            CBitRead::ReadBytes(this: buf, pOut: (char *)dst, nBytes: m_nUserDataSize);
            goto LABEL_164;
          }
          v96 = buf->m_pDataIn;
          v97 = buf->m_pBufferEnd;
          buf->m_nBitsAvail = 32;
          if ( v96 == v97 )
          {
            buf->m_nBitsAvail = 1;
            buf->m_pDataIn = v96 + 1;
          }
          else if ( v96 <= v97 )
          {
            v95 = *v96;
            buf->m_pDataIn = v96 + 1;
          }
          else
          {
            buf->m_bOverflow = true;
          }
          goto LABEL_160;
        }
        v98 = buf->m_pBufferEnd;
        v99 = buf->m_nInBufWord;
        v100 = 14 - v92;
        v101 = buf->m_pDataIn;
        if ( v101 == v98 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_bOverflow = true;
          goto LABEL_156;
        }
        if ( v101 <= v98 )
        {
          buf->m_nInBufWord = *v101;
LABEL_156:
          buf->m_pDataIn = v101 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
        if ( buf->m_bOverflow )
        {
          m_nUserDataSize = 0;
          goto LABEL_161;
        }
        v102 = buf->m_nInBufWord;
        v103 = (v102 & CBitBuffer::s_nMaskTable[v100]) << buf->m_nBitsAvail;
        buf->m_nBitsAvail = 32 - v100;
        m_nUserDataSize = v103 | v99;
        v91 = v127;
        v95 = v102 >> v100;
LABEL_160:
        buf->m_nInBufWord = v95;
        goto LABEL_161;
      }
      m_nUserDataSize = v127->m_nUserDataSize;
      m_nUserDataSizeBits = v127->m_nUserDataSizeBits;
      dst[m_nUserDataSize - 1] = 0;
      CBitRead::ReadBits(this: buf, pOutData: (char *)dst, nBits: m_nUserDataSizeBits);
LABEL_164:
      v125 = dst;
LABEL_165:
      v104 = ((int (__thiscall *)(CNetworkStringTable *, unsigned __int8 *))v91->GetNumStrings)(a1: v91, a2);
      if ( v126 >= v104 )
      {
        if ( pSrc == nullptr )
        {
          v105 = (const char *)((int (__thiscall *)(CNetworkStringTable *, int))v91->GetTableName)(a1: v91, a2: v126);
          _Msg(a1: "CNetworkStringTable::ParseUpdate: NULL pEntry, table %s, index %i\n", v105, v112);
          pSrc = (char *)defaultValue;
        }
        a2 = v125;
        ((void (__thiscall *)(CNetworkStringTable *, int, char *, unsigned int))v91->AddString)(
          a1: v91,
          a2: 1,
          a3: pSrc,
          a4: m_nUserDataSize);
      }
      else
      {
        a2 = v125;
        ((void (__thiscall *)(CNetworkStringTable *, int, unsigned int))v91->SetStringUserData)(
          a1: v91,
          a2: v126,
          a3: m_nUserDataSize);
        pSrc = (char *)v91->GetString(this: v91, a2: v126);
      }
      v106 = v122;
      if ( v122 > 31 )
      {
        v106 = v122 - 1;
        _V_memmove(dest: dest.m_pMemory, src: &dest.m_pMemory[1], count: 32 * (v122 - 1));
        v122 = v106;
      }
      V_strncpy(pDest: v117, pSrc, maxLen: 32);
      v107 = v106;
      if ( v106 + 1 > dest.m_nAllocationCount )
      {
        CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>::Grow(this: &dest, num: v106 - dest.m_nAllocationCount + 1);
        v106 = v122;
      }
      v108 = v106 + 1;
      v122 = v108;
      m_pMemory = dest.m_pMemory;
      if ( v108 - v107 - 1 > 0 )
        _V_memmove(dest: &dest.m_pMemory[v107 + 1], src: &dest.m_pMemory[v107], count: 32 * (v108 - v107 - 1));
      v109 = &dest.m_pMemory[v107];
      if ( v109 != nullptr )
        qmemcpy(v109, v117, sizeof(vgui::RichText::TFormatStream));
      if ( ++v120 >= entries )
        goto LABEL_179;
    }
    v16 = v127->GetEntryBits(this: v127);
    v17 = buf->m_nBitsAvail;
    if ( v17 >= v16 )
    {
      v18 = buf->m_nInBufWord;
      v19 = v18 & CBitBuffer::s_nMaskTable[v16];
      v20 = v17 - v16;
      buf->m_nBitsAvail = v20;
      if ( v20 == 0 )
      {
        v21 = buf->m_pDataIn;
        v22 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v21 == v22 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v21 + 1;
        }
        else if ( v21 <= v22 )
        {
          buf->m_nInBufWord = *v21;
          buf->m_pDataIn = v21 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
        goto LABEL_34;
      }
LABEL_33:
      buf->m_nInBufWord = v18 >> v16;
LABEL_34:
      v26 = v19;
      goto LABEL_35;
    }
    v23 = buf->m_pBufferEnd;
    v24 = buf->m_nInBufWord;
    v16 -= v17;
    v25 = buf->m_pDataIn;
    if ( v25 == v23 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v25 > v23 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
LABEL_30:
        if ( buf->m_bOverflow )
        {
          v26 = 0;
LABEL_35:
          v11 = v26;
          v126 = v26;
          goto LABEL_36;
        }
        v18 = buf->m_nInBufWord;
        v19 = ((v18 & CBitBuffer::s_nMaskTable[v16]) << buf->m_nBitsAvail) | v24;
        v15 = v127;
        buf->m_nBitsAvail = 32 - v16;
        goto LABEL_33;
      }
      buf->m_nInBufWord = *v25;
    }
    buf->m_pDataIn = v25 + 1;
    goto LABEL_30;
  }
LABEL_179:
  if ( dest.m_nGrowSize >= 0 && dest.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dest.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101C5630
// Name: public: void CNetworkStringTableContainer::WriteBaselines(char const __near *,class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableContainer::WriteBaselines(
        CNetworkStringTableContainer *this,
        signed int pchMapName,
        bf_write *buf)
{
  CNetworkStringTableContainer *v3; // esi
  signed int v4; // edi
  char *v5; // eax
  bool v6; // cc
  char *v7; // edi
  CNetworkStringTable *v8; // esi
  int v9; // ebx
  int v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  int v13; // edi
  char *v14; // ecx
  const char *v15; // eax
  const char *v16; // eax
  bf_write *v17; // edi
  const char *v18; // eax
  int m_iCurBit; // ecx
  int v20; // edi
  const char *v21; // eax
  int v22; // [esp-Ch] [ebp-194h]
  int v23; // [esp-8h] [ebp-190h]
  int v24; // [esp-8h] [ebp-190h]
  int v25; // [esp-8h] [ebp-190h]
  SVC_CreateStringTable msg; // [esp+8h] [ebp-180h] BYREF
  CNetworkStringTableContainer *v27; // [esp+178h] [ebp-10h]
  char *compressedData; // [esp+17Ch] [ebp-Ch]
  char *msg_buffer; // [esp+180h] [ebp-8h]
  int i; // [esp+184h] [ebp-4h]

  v3 = this;
  v27 = this;
  if ( stringtable_usedictionaries.m_pParent != nullptr && stringtable_usedictionaries.m_pParent->m_Value.m_nValue != 0 )
  {
    v4 = pchMapName;
    if ( CNetworkStringTableDictionaryManager::ShouldRecreateDictionary(
           this: &g_StringTableDictionary,
           (const char *)pchMapName) )
    {
      v3->CreateDictionary(this: v3, a2: (const char *)v4);
    }
  }
  SVC_CreateStringTable::SVC_CreateStringTable(this: &msg);
  v5 = (char *)MemAlloc_Alloc(nSize: 0x2EE00u);
  v6 = v3->m_Tables.m_Size <= 0;
  v7 = v5;
  msg_buffer = v5;
  i = 0;
  if ( !v6 )
  {
    while ( 1 )
    {
      v8 = (CNetworkStringTable *)v3->GetTable(this: v3, a2: i);
      v9 = (buf->m_iCurBit + 7) >> 3;
      bf_write::StartWriting(this: &msg.m_DataOut, pData: v7, nBytes: 192000, iStartBit: 0, nBits: -1);
      msg.m_nFlags = v8->m_nFlags;
      msg.m_szTableName = v8->GetTableName(this: v8);
      msg.m_nMaxEntries = v8->GetMaxStrings(this: v8);
      msg.m_nNumEntries = v8->GetNumStrings(this: v8);
      msg.m_bUserDataFixedSize = (*((_BYTE *)v8 + 28) & 8) != 0;
      msg.m_nUserDataSize = v8->m_nUserDataSize;
      msg.m_nUserDataSizeBits = v8->m_nUserDataSizeBits;
      v10 = CNetworkStringTable::WriteUpdate(this: v8, client: nullptr, buf: (int)&msg.m_DataOut, tick_ack: -1);
      if ( v10 != msg.m_nNumEntries )
      {
        free(pMem: v7);
        v11 = v8->GetTableName(this: v8);
        Host_Error(error: "Index error writing string table baseline %s\n", v11);
      }
      if ( msg.m_DataOut.m_bOverflow )
      {
        v12 = v8->GetTableName(this: v8);
        _Warning(a1: "Warning:  Overflowed writing uncompressed string table data for %s\n", v12);
      }
      v13 = (msg.m_DataOut.m_iCurBit + 7) >> 3;
      pchMapName = v13;
      v14 = (char *)MemAlloc_Alloc(nSize: v13);
      compressedData = v14;
      if ( stringtable_compress.m_pParent != nullptr
        && stringtable_compress.m_pParent->m_Value.m_nValue != 0
        && NET_BufferToBufferCompress(
             dest: v14,
             destLen: (unsigned int *)&pchMapName,
             source: (char *)msg.m_DataOut.m_pData,
             sourceLen: v13) )
      {
        msg.m_bDataCompressed = true;
        bf_write::Reset(this: &msg.m_DataOut);
        bf_write::WriteLong(this: &msg.m_DataOut, val: v13);
        bf_write::WriteLong(this: &msg.m_DataOut, val: pchMapName);
        bf_write::WriteBits(this: &msg.m_DataOut, pInData: compressedData, nBits: 8 * pchMapName);
        if ( stringtable_showsizes.m_pParent != nullptr && stringtable_showsizes.m_pParent->m_Value.m_nValue != 0 )
        {
          v15 = (const char *)((int (__thiscall *)(CNetworkStringTable *, int, signed int))v8->GetTableName)(
                                a1: v8,
                                a2: v13,
                                a3: pchMapName);
          _Msg(a1: "Stringtable %s compression: %d -> %d bytes\n", v15, v22, v23);
        }
      }
      else
      {
        msg.m_bDataCompressed = false;
        if ( stringtable_showsizes.m_pParent != nullptr && stringtable_showsizes.m_pParent->m_Value.m_nValue != 0 )
        {
          v16 = (const char *)((int (__thiscall *)(CNetworkStringTable *, int))v8->GetTableName)(a1: v8, a2: v13);
          _Msg(a1: "Stringtable %s written %d bytes\n", v16, v24);
        }
      }
      free(pMem: compressedData);
      v17 = buf;
      if ( !SVC_CreateStringTable::WriteToBuffer(this: &msg, buffer: buf) )
      {
        free(pMem: msg_buffer);
        v18 = v8->GetTableName(this: v8);
        Host_Error(error: "Overflow error writing string table baseline %s\n", v18);
      }
      m_iCurBit = v17->m_iCurBit;
      v20 = (m_iCurBit + 7) >> 3;
      if ( sv_dumpstringtables.m_pParent != nullptr && sv_dumpstringtables.m_pParent->m_Value.m_nValue != 0 )
      {
        v21 = (const char *)((int (__thiscall *)(CNetworkStringTable *, int))v8->GetTableName)(
                              a1: v8,
                              a2: (buf->m_nDataBits - m_iCurBit) >> 3);
        DevMsg(
          a1: "CNetworkStringTableContainer::WriteBaselines wrote %d bytes for table %s [space remaining %d bytes]\n",
          v20 - v9,
          v21,
          v25);
      }
      v7 = msg_buffer;
      if ( ++i >= v27->m_Tables.m_Size )
        break;
      v3 = v27;
    }
  }
  free(pMem: v7);
}

//------------------------------------------------------------------------------
// Address: 0x101C5920
// Name: public: void CNetworkStringTableContainer::WriteUpdateMessage(class CBaseClient __near *,int,class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableContainer::WriteUpdateMessage(
        CNetworkStringTableContainer *this,
        CBaseClient *client,
        int tick_ack,
        bf_write *buf)
{
  CNetworkStringTableContainer *v4; // esi
  CNetworkStringTable *v5; // esi
  const char *v6; // eax
  _BYTE pData[96000]; // [esp+8h] [ebp-17760h] BYREF
  SVC_UpdateStringTable v8; // [esp+17708h] [ebp-60h] BYREF
  CNetworkStringTableContainer *v9; // [esp+17760h] [ebp-8h]
  int v10; // [esp+17764h] [ebp-4h]

  v4 = this;
  v9 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CNetworkStringTableContainer::WriteUpdateMessage",
    a3: 0,
    a4: "Networking",
    a5: false,
    a6: 4);
  v10 = 0;
  if ( v4->m_Tables.m_Size > 0 )
  {
    while ( 1 )
    {
      v5 = (CNetworkStringTable *)v4->GetTable(this: v4, a2: v10);
      if ( v5 != nullptr && v5->ChangedSinceTick(this: v5, a2: tick_ack) )
      {
        v8.m_bReliable = true;
        v8.m_NetChannel = nullptr;
        v8.__vftable = (SVC_UpdateStringTable_vtbl *)&SVC_UpdateStringTable::`vftable';
        v8.m_DataIn.m_bOverflow = false;
        v8.m_DataIn.m_pDebugName = nullptr;
        v8.m_DataIn.m_nDataBits = -1;
        v8.m_DataIn.m_nDataBytes = 0;
        bf_write::bf_write(this: &v8.m_DataOut);
        bf_write::StartWriting(this: &v8.m_DataOut, pData, nBytes: 96000, iStartBit: 0, nBits: -1);
        v8.m_nTableID = v5->GetTableId(this: v5);
        v8.m_nChangedEntries = CNetworkStringTable::WriteUpdate(this: v5, client, buf: (int)&v8.m_DataOut, tick_ack);
        SVC_UpdateStringTable::WriteToBuffer(this: &v8, buffer: buf);
        if ( client != nullptr && CBaseClient::IsTracing(this: client) )
        {
          v6 = v5->GetTableName(this: v5);
          CBaseClient::TraceNetworkData(this: client, msg: buf, fmt: "StringTable %s", v6);
        }
      }
      if ( ++v10 >= v9->m_Tables.m_Size )
        break;
      v4 = v9;
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x101C5BE0
// Name: private: void CNetworkStringTableDictionaryManager::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableDictionaryManager::Clear(CNetworkStringTableDictionaryManager *this)
{
  CUtlRBTree<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_StringHashToIndex.m_Tree);
  this->m_StringHashToIndex.m_Tree.m_FirstFree = -1;
  if ( this->m_StringHashToIndex.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_StringHashToIndex.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_StringHashToIndex.m_Tree.m_Elements.m_pMemory);
      this->m_StringHashToIndex.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_StringHashToIndex.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  this->m_StringHashToIndex.m_Tree.m_LastAlloc.index = -1;
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&this->m_Strings);
  if ( this->m_Strings.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Strings.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Strings.m_Memory.m_pMemory);
      this->m_Strings.m_Memory.m_pMemory = nullptr;
    }
    this->m_Strings.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Strings.m_pElements = this->m_Strings.m_Memory.m_pMemory;
  this->m_CRC = 0;
  this->m_nEncodeBits = 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C5CE0
// Name: public: CNetworkStringTableDictionaryManager::~CNetworkStringTableDictionaryManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableDictionaryManager::~CNetworkStringTableDictionaryManager(
        CNetworkStringTableDictionaryManager *this)
{
  if ( this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_pMemory);
      this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_pMemory = nullptr;
    }
    this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_nAllocationCount = 0;
  }
  this->m_BuildStringTableDictionaryCache.m_sBSPName.m_Storage.m_nActualLength = 0;
  if ( this->m_BuildStringTableDictionaryCache.m_sBSPName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_BuildStringTableDictionaryCache.m_sBSPName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: this->m_BuildStringTableDictionaryCache.m_sBSPName.m_Storage.m_Memory.m_pMemory);
      this->m_BuildStringTableDictionaryCache.m_sBSPName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_BuildStringTableDictionaryCache.m_sBSPName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlRBTree<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_StringHashToIndex.m_Tree);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&this->m_Strings);
  this->m_sCurrentMap.m_Storage.m_nActualLength = 0;
  if ( this->m_sCurrentMap.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_sCurrentMap.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_sCurrentMap.m_Storage.m_Memory.m_pMemory);
      this->m_sCurrentMap.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_sCurrentMap.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C5D70
// Name: public: void CNetworkStringTableDictionaryManager::ProcessBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableDictionaryManager::ProcessBuffer(
        CNetworkStringTableDictionaryManager *this,
        CUtlBuffer *buf)
{
  CNetworkStringTableDictionaryManager *v2; // ebx
  CUtlBuffer *v3; // esi
  int m_nMaxPut; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v8; // eax
  CUtlString *v9; // ecx
  const char *v10; // eax
  unsigned __int16 v11; // ax
  unsigned __int16 v12; // dx
  unsigned __int16 v13; // cx
  int v14; // edi
  UtlRBTreeNode_t<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short> *v15; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short> *v16; // eax
  int v17; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short> *v18; // ecx
  CUtlMap<unsigned long,int,unsigned short>::Node_t *p_m_Data; // edi
  char line[260]; // [esp+Ch] [ebp-128h] BYREF
  CUtlString str; // [esp+110h] [ebp-24h] BYREF
  CNetworkStringTableDictionaryManager *v22; // [esp+120h] [ebp-14h]
  CUtlMap<unsigned long,int,unsigned short>::Node_t insert; // [esp+124h] [ebp-10h] BYREF
  unsigned int pulCRC; // [esp+12Ch] [ebp-8h] BYREF
  bool leftchild; // [esp+133h] [ebp-1h] BYREF

  v2 = this;
  v22 = this;
  CNetworkStringTableDictionaryManager::Clear(this);
  v3 = buf;
  m_nMaxPut = buf->m_nMaxPut;
  insert.elem = (int)buf->m_Memory.m_pMemory;
  CRC32_Init(&pulCRC);
  CRC32_ProcessBuffer(&pulCRC, pBuffer: (const void *)insert.elem, nBuffer: m_nMaxPut);
  CRC32_Final(&pulCRC);
  v2->m_CRC = pulCRC;
  while ( v3->m_nMaxPut - v3->m_Get > 0 )
  {
    CUtlBuffer::GetString(this: v3, pString: line, nMaxChars: 260);
    if ( line[0] != 0 )
    {
      CUtlString::CUtlString(this: &str);
      CUtlString::operator=(this: &str, src: line);
      m_Size = v2->m_Strings.m_Size;
      m_nAllocationCount = v2->m_Strings.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CPortalRect,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&v2->m_Strings,
          num: m_Size - m_nAllocationCount + 1);
      ++v2->m_Strings.m_Size;
      m_pMemory = v2->m_Strings.m_Memory.m_pMemory;
      v8 = v2->m_Strings.m_Size - m_Size - 1;
      v2->m_Strings.m_pElements = m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v8);
      v9 = &v2->m_Strings.m_Memory.m_pMemory[m_Size];
      if ( v9 != nullptr )
        CUtlString::CUtlString(this: v9, string: &str);
      v10 = CUtlString::operator char const *(this: &str);
      insert.key = (unsigned int)CNetworkStringTableDictionaryManager::HashStringCaselessIgnoreSlashes(
                                   this: v2,
                                   pString: v10);
      insert.elem = m_Size;
      pulCRC = 0xFFFF;
      leftchild = false;
      CUtlRBTree<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &v2->m_StringHashToIndex.m_Tree,
        &insert,
        parent: (unsigned __int16 *)&pulCRC,
        &leftchild);
      v11 = CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&v2->m_StringHashToIndex);
      v12 = pulCRC;
      v13 = v11;
      v14 = v11;
      v15 = &v2->m_StringHashToIndex.m_Tree.m_Elements.m_pMemory[v14];
      v15->m_Right = -1;
      v15->m_Left = -1;
      v15->m_Parent = v12;
      v15->m_Tag = 0;
      if ( v12 == 0xFFFF )
      {
        v2->m_StringHashToIndex.m_Tree.m_Root = v13;
      }
      else
      {
        v16 = v2->m_StringHashToIndex.m_Tree.m_Elements.m_pMemory;
        v17 = v12;
        if ( leftchild )
          v16[v17].m_Left = v13;
        else
          v16[v17].m_Right = v13;
      }
      CUtlRBTree<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        this: &v2->m_StringHashToIndex.m_Tree,
        elem: v13);
      v18 = v2->m_StringHashToIndex.m_Tree.m_Elements.m_pMemory;
      ++v2->m_StringHashToIndex.m_Tree.m_NumElements;
      p_m_Data = &v18[v14].m_Data;
      if ( p_m_Data != nullptr )
        *p_m_Data = insert;
      str.m_Storage.m_nActualLength = 0;
      if ( str.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( str.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: str.m_Storage.m_Memory.m_pMemory);
          str.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        str.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      v2 = v22;
      v3 = buf;
    }
  }
  v2->m_nEncodeBits = Q_log2(val: v2->m_Strings.m_Size) + 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C5F70
// Name: private: void CNetworkStringTableDictionaryManager::LoadMapStrings(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableDictionaryManager::LoadMapStrings(
        CNetworkStringTableDictionaryManager *this,
        const char *pchMapName,
        int bServer)
{
  unsigned int ActualSize; // eax
  unsigned __int8 *v5; // esi
  unsigned __int8 *v6; // edi
  char szNameOnDisk[260]; // [esp+Ch] [ebp-238h] BYREF
  char szModelName[260]; // [esp+110h] [ebp-134h] BYREF
  CUtlBuffer buf; // [esp+214h] [ebp-30h] BYREF

  if ( !CUtlString::operator==(this: &this->m_sCurrentMap, src: pchMapName) )
  {
    CUtlString::operator=(this: &this->m_sCurrentMap, src: pchMapName);
    CNetworkStringTableDictionaryManager::Clear(this);
    V_snprintf(pDest: szModelName, maxLen: 260, pFormat: "maps/%s.bsp", pchMapName);
    GetMapPathNameOnDisk(pDiskName: szNameOnDisk, pFullMapName: szModelName, nDiskNameSize: 0x104u);
    if ( (_BYTE)bServer == 0 )
      g_pFileSystem->AddSearchPath(this: g_pFileSystem, a2: szNameOnDisk, a3: "GAME", a4: PATH_ADD_TO_HEAD);
    if ( stringtable_usedictionaries.m_pParent != nullptr
      && stringtable_usedictionaries.m_pParent->m_Value.m_nValue != 0 )
    {
      CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
      if ( CNetworkStringTableDictionaryManager::LoadDictionaryFile(this, &buf, pchMapName) != 0 )
      {
        if ( CLZMA::IsCompressed(this: (CLZMA *)&bServer + 3, pInput: buf.m_Memory.m_pMemory) )
        {
          ActualSize = CLZMA::GetActualSize(this: (CLZMA *)&bServer + 3, pInput: buf.m_Memory.m_pMemory);
          v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: ActualSize);
          v6 = CLZMA::Uncompress(
                 this: (CLZMA *)&bServer + 3,
                 pInput: buf.m_Memory.m_pMemory,
                 pOutput: v5,
                 pCallback: nullptr);
          memset(&buf.m_Get, 0, 9);
          buf.m_nOffset = 0;
          buf.m_nMaxPut = -1;
          CUtlBuffer::AddNullTermination(this: &buf, nPut: 0);
          CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: 0);
          CUtlBuffer::Put(this: &buf, pMem: v5, size: (int)v6);
          free(pMem: v5);
        }
        CNetworkStringTableDictionaryManager::ProcessBuffer(this, &buf);
      }
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C60E0
// Name: public: virtual bool CNetworkStringTableDictionaryManager::OnLevelLoadStart(char const __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetworkStringTableDictionaryManager::OnLevelLoadStart(
        CNetworkStringTableDictionaryManager *this,
        const char *pchMapName,
        unsigned int *pStringTableCRC)
{
  int v5; // eax
  int v6; // eax

  this->m_BuildStringTableDictionaryCache.m_bActive = false;
  CUtlString::operator=(this: &this->m_BuildStringTableDictionaryCache.m_sBSPName, src: defaultValue);
  this->m_BuildStringTableDictionaryCache.m_bCreatingForX360 = false;
  this->m_BuildStringTableDictionaryCache.m_Buffer.m_Get = 0;
  this->m_BuildStringTableDictionaryCache.m_Buffer.m_Put = 0;
  this->m_BuildStringTableDictionaryCache.m_Buffer.m_nOffset = 0;
  this->m_BuildStringTableDictionaryCache.m_Buffer.m_nMaxPut = 0;
  this->m_BuildStringTableDictionaryCache.m_Buffer.m_Error = 0;
  if ( this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_pMemory);
      this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_pMemory = nullptr;
    }
    this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_nAllocationCount = 0;
  }
  V_FileBase(in: com_gamedir, out: gamedir_9, maxlen: 260);
  if ( _V_stricmp(s1: gamedir_9, s2: "infested") == 0 )
    return true;
  if ( stringtable_alwaysrebuilddictionaries.m_pParent != nullptr
    && stringtable_alwaysrebuilddictionaries.m_pParent->m_Value.m_nValue != 0
    || (v5 = _CommandLine(),
        (v6 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-stringtables")) != 0) )
  {
    LOBYTE(v6) = 1;
  }
  this->m_bForceRebuildDictionaries = v6;
  CNetworkStringTableDictionaryManager::LoadMapStrings(this, pchMapName, bServer: pStringTableCRC == nullptr);
  return pStringTableCRC == nullptr || *pStringTableCRC == this->m_CRC;
}

//------------------------------------------------------------------------------
// Address: 0x101C61D0
// Name: private: void CNetworkStringDict::CTableItem::ComputeHash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringDict::CTableItem::ComputeHash(CNetworkStringDict::CTableItem *this)
{
  int v2; // esi
  void *v3; // esp
  char v4[12]; // [esp+0h] [ebp-10h] BYREF
  const char *pName; // [esp+Ch] [ebp-4h] BYREF

  pName = CUtlString::operator char const *(this: &this->m_Name);
  v2 = _V_strlen(str: pName) + 1;
  v3 = alloca(v2);
  V_strncpy(pDest: v4, pSrc: pName, maxLen: v2);
  V_FixSlashes(pname: v4, separator: 92);
  _V_strlower(start: v4);
  CRC32_Init(pulCRC: (unsigned int *)&pName);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&pName, pBuffer: v4, nBuffer: v2);
  CRC32_Final(pulCRC: (unsigned int *)&pName);
  this->m_StringHash = (unsigned int)pName;
}

//------------------------------------------------------------------------------
// Address: 0x101C62B0
// Name: public: virtual unsigned int CNetworkStringDict::Count(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CNetworkStringDict::Count(CNetworkStringDict *this)
{
  return this->m_Items.m_Tree.m_NumElements;
}

//------------------------------------------------------------------------------
// Address: 0x101C65F0
// Name: public: virtual char const __near * CNetworkStringDict::String(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CNetworkStringDict::String(CNetworkStringDict *this, unsigned __int16 index)
{
  return CUtlString::operator char const *(this: &this->m_Items.m_Tree.m_Elements.m_pMemory[index].m_Data.key.m_Name);
}

//------------------------------------------------------------------------------
// Address: 0x101C6610
// Name: public: virtual class CNetworkStringTableItem const __near & CNetworkStringDict::Element(int)const
// Source: json
//------------------------------------------------------------------------------
const CNetworkStringTableItem *__thiscall CNetworkStringDict::Element(CNetworkStringDict *this, unsigned __int16 index)
{
  return &this->m_Items.m_Tree.m_Elements.m_pMemory[index].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x101C6630
// Name: public: virtual int CNetworkStringDict::DictionaryIndex(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetworkStringDict::DictionaryIndex(CNetworkStringDict *this, unsigned __int16 index)
{
  if ( this->m_bUseDictionary )
    return this->m_Items.m_Tree.m_Elements.m_pMemory[index].m_Data.key.m_DictionaryIndex;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x101C6F90
// Name: public: virtual bool CNetworkStringDict::IsValidIndex(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetworkStringDict::IsValidIndex(CNetworkStringDict *this, unsigned __int16 index)
{
  CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short> *p_m_Items; // ecx

  p_m_Items = &this->m_Items;
  return index < p_m_Items->m_Tree.m_Elements.m_nAllocationCount
      && index <= p_m_Items->m_Tree.m_LastAlloc.index
      && CUtlRBTree<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short,CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this: &p_m_Items->m_Tree,
           i: index) != index;
}

//------------------------------------------------------------------------------
// Address: 0x101C6FD0
// Name: public: void CNetworkStringDict::CTableItem::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringDict::CTableItem::Update(CNetworkStringDict::CTableItem *this)
{
  const char *v2; // eax
  unsigned __int16 v3; // ax
  CUtlMap<unsigned long,int,unsigned short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  v2 = CUtlString::operator char const *(this: &this->m_Name);
  search.key = CNetworkStringTableDictionaryManager::HashStringCaselessIgnoreSlashes(
                 this: &g_StringTableDictionary,
                 pString: v2);
  v3 = CUtlRBTree<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &g_StringTableDictionary.m_StringHashToIndex.m_Tree,
         &search);
  if ( v3 == 0xFFFF )
    this->m_DictionaryIndex = -1;
  else
    this->m_DictionaryIndex = g_StringTableDictionary.m_StringHashToIndex.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
  CNetworkStringDict::CTableItem::ComputeHash(this);
}

//------------------------------------------------------------------------------
// Address: 0x101C7040
// Name: public: void CNetworkStringDict::CTableItem::SetName(bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringDict::CTableItem::SetName(
        CNetworkStringDict::CTableItem *this,
        bool bUseDictionary,
        const char *pString)
{
  unsigned __int16 v4; // ax
  CUtlMap<unsigned long,int,unsigned short>::Node_t search; // [esp+8h] [ebp-8h] BYREF

  CUtlString::operator=(this: &this->m_Name, src: pString);
  if ( !bUseDictionary
    || (search.key = CNetworkStringTableDictionaryManager::HashStringCaselessIgnoreSlashes(
                       this: &g_StringTableDictionary,
                       pString),
        (v4 = CUtlRBTree<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                this: &g_StringTableDictionary.m_StringHashToIndex.m_Tree,
                &search)) == 0xFFFF) )
  {
    this->m_DictionaryIndex = -1;
    CNetworkStringDict::CTableItem::ComputeHash(this);
  }
  else
  {
    this->m_DictionaryIndex = g_StringTableDictionary.m_StringHashToIndex.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
    CNetworkStringDict::CTableItem::ComputeHash(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C70C0
// Name: public: virtual int CNetworkStringDict::Find(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetworkStringDict::Find(CNetworkStringDict *this, const char *pString)
{
  int v3; // esi
  CNetworkStringDict::CTableItem search; // [esp+4h] [ebp-18h] BYREF

  CUtlString::CUtlString(this: &search.m_Name);
  search.m_StringHash = 0;
  CUtlString::operator=(this: &search.m_Name, src: pString);
  search.m_DictionaryIndex = -1;
  CNetworkStringDict::CTableItem::ComputeHash(this: &search);
  v3 = CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Find(
         this: &this->m_Items,
         key: &search);
  search.m_Name.m_Storage.m_nActualLength = 0;
  if ( v3 == 0xFFFF )
  {
    if ( search.m_Name.m_Storage.m_Memory.m_nGrowSize >= 0 && search.m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.m_Name.m_Storage.m_Memory.m_pMemory);
    return -1;
  }
  else
  {
    if ( search.m_Name.m_Storage.m_Memory.m_nGrowSize >= 0 && search.m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.m_Name.m_Storage.m_Memory.m_pMemory);
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C7170
// Name: public: virtual void CNetworkStringDict::UpdateDictionary(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringDict::UpdateDictionary(CNetworkStringDict *this, unsigned __int16 index)
{
  if ( this->m_bUseDictionary )
    CNetworkStringDict::CTableItem::Update(this: &this->m_Items.m_Tree.m_Elements.m_pMemory[index].m_Data.key);
}

//------------------------------------------------------------------------------
// Address: 0x101C72C0
// Name: public: virtual void CNetworkStringDict::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringDict::Purge(CNetworkStringDict *this)
{
  CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short> *p_m_Items; // esi

  p_m_Items = &this->m_Items;
  CUtlRBTree<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short,CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Items.m_Tree);
  p_m_Items->m_Tree.m_FirstFree = -1;
  if ( p_m_Items->m_Tree.m_Elements.m_nGrowSize < 0 )
  {
    p_m_Items->m_Tree.m_LastAlloc.index = -1;
  }
  else
  {
    if ( p_m_Items->m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Items->m_Tree.m_Elements.m_pMemory);
      p_m_Items->m_Tree.m_Elements.m_pMemory = nullptr;
    }
    p_m_Items->m_Tree.m_Elements.m_nAllocationCount = 0;
    p_m_Items->m_Tree.m_LastAlloc.index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C7320
// Name: public: virtual int CNetworkStringDict::Insert(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetworkStringDict::Insert(CNetworkStringDict *this, const char *pString)
{
  int v3; // esi
  bool m_bUseDictionary; // [esp-8h] [ebp-24h]
  CNetworkStringDict::CTableItem item; // [esp+4h] [ebp-18h] BYREF

  item.m_DictionaryIndex = -1;
  CUtlString::CUtlString(this: &item.m_Name);
  m_bUseDictionary = this->m_bUseDictionary;
  item.m_StringHash = 0;
  CNetworkStringDict::CTableItem::SetName(this: &item, bUseDictionary: m_bUseDictionary, pString);
  v3 = CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Insert(
         this: &this->m_Items,
         key: &item);
  item.m_Name.m_Storage.m_nActualLength = 0;
  if ( item.m_Name.m_Storage.m_Memory.m_nGrowSize >= 0 && item.m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: item.m_Name.m_Storage.m_Memory.m_pMemory);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101C7390
// Name: public: virtual CNetworkStringDict::~CNetworkStringDict(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringDict::~CNetworkStringDict(CNetworkStringDict *this)
{
  this->__vftable = (CNetworkStringDict_vtbl *)&CNetworkStringDict::`vftable';
  CUtlRBTree<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short,CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Items.m_Tree);
  this->m_Items.m_Tree.m_FirstFree = -1;
  if ( this->m_Items.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Items.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Items.m_Tree.m_Elements.m_pMemory);
      this->m_Items.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_Items.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  this->m_Items.m_Tree.m_LastAlloc.index = -1;
  CUtlRBTree<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short,CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short,CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_Items.m_Tree);
  this->__vftable = (CNetworkStringDict_vtbl *)&INetworkStringDict::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x101C7420
// Name: public: CNetworkStringTable::CNetworkStringTable(int,char const __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
CNetworkStringTable *__thiscall CNetworkStringTable::CNetworkStringTable(
        CNetworkStringTable *this,
        int id,
        const char *tableName,
        int maxentries,
        int userdatafixedsize,
        int userdatanetworkbits,
        int flags)
{
  unsigned int v8; // kr00_4
  char *v9; // eax
  char v10; // cl
  INetworkStringDict *v11; // eax
  char m_nFlags; // cl
  INetworkStringDict_vtbl *v13; // ecx

  *((_BYTE *)this + 28) &= ~4u;
  this->m_nFlags = flags;
  this->__vftable = (CNetworkStringTable_vtbl *)&CNetworkStringTable::`vftable';
  this->m_pItemsClientSide = nullptr;
  this->m_id = id;
  v8 = strlen(tableName);
  v9 = (char *)MemAlloc_Alloc(nSize: v8 + 1);
  this->m_pszTableName = v9;
  V_strncpy(pDest: v9, pSrc: tableName, maxLen: v8 + 1);
  *((_BYTE *)this + 28) &= 0xFCu;
  this->m_changeFunc = nullptr;
  this->m_pObject = nullptr;
  this->m_nTickCount = 0;
  this->m_pMirrorTable = nullptr;
  this->m_nLastChangedTick = 0;
  this->m_nMaxEntries = maxentries;
  this->m_nEntryBits = Q_log2(val: maxentries);
  v10 = *((_BYTE *)this + 28) ^ (8 * (userdatafixedsize != 0));
  this->m_nUserDataSize = userdatafixedsize;
  *((_BYTE *)this + 28) ^= v10 & 8;
  this->m_nUserDataSizeBits = userdatanetworkbits;
  if ( userdatanetworkbits > 14 )
    Host_Error(
      error: "String tables user data bits restricted to %i bits, requested %i is too large\n",
      14,
      userdatanetworkbits);
  if ( this->m_nUserDataSize > 0x4000 )
    Host_Error(
      error: "String tables user data size restricted to %i bytes, requested %i is too large\n",
      0x4000,
      this->m_nUserDataSize);
  if ( 1 << this->m_nEntryBits != maxentries )
    Host_Error(
      error: "String tables must be powers of two in size!, %i is not a power of 2 [%s]\n",
      maxentries,
      tableName);
  v11 = (INetworkStringDict *)MemAlloc_Alloc(nSize: 0x24u);
  if ( v11 != nullptr )
  {
    m_nFlags = this->m_nFlags;
    v11->__vftable = (INetworkStringDict_vtbl *)&CNetworkStringDict::`vftable';
    LOBYTE(v11[1].__vftable) = m_nFlags & 1;
    v11[2].__vftable = (INetworkStringDict_vtbl *)CNetworkStringDict::CTableItem::Less;
    v11[3].__vftable = nullptr;
    v11[4].__vftable = nullptr;
    v11[5].__vftable = nullptr;
    v13 = v11[3].__vftable;
    v11[6].__vftable = (INetworkStringDict_vtbl *)0xFFFF;
    v11[7].__vftable = (INetworkStringDict_vtbl *)-1;
    v11[8].__vftable = v13;
    this->m_pItems = v11;
  }
  else
  {
    this->m_pItems = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C7560
// Name: protected: void CNetworkStringTable::DeleteAllStrings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTable::DeleteAllStrings(CNetworkStringTable *this)
{
  INetworkStringDict *m_pItems; // ecx
  INetworkStringDict *v3; // eax
  char m_nFlags; // cl
  INetworkStringDict_vtbl *v5; // ecx
  INetworkStringDict *m_pItemsClientSide; // ecx
  INetworkStringDict *v7; // eax
  INetworkStringDict_vtbl *v8; // ecx

  m_pItems = this->m_pItems;
  if ( m_pItems != nullptr )
    ((void (__thiscall *)(INetworkStringDict *, int))m_pItems->dtr_INetworkStringDict)(a1: m_pItems, a2: 1);
  v3 = (INetworkStringDict *)MemAlloc_Alloc(nSize: 0x24u);
  if ( v3 != nullptr )
  {
    m_nFlags = this->m_nFlags;
    v3->__vftable = (INetworkStringDict_vtbl *)&CNetworkStringDict::`vftable';
    LOBYTE(v3[1].__vftable) = m_nFlags & 1;
    v3[2].__vftable = (INetworkStringDict_vtbl *)CNetworkStringDict::CTableItem::Less;
    v3[3].__vftable = nullptr;
    v3[4].__vftable = nullptr;
    v3[5].__vftable = nullptr;
    v5 = v3[3].__vftable;
    v3[6].__vftable = (INetworkStringDict_vtbl *)0xFFFF;
    v3[7].__vftable = (INetworkStringDict_vtbl *)-1;
    v3[8].__vftable = v5;
  }
  else
  {
    v3 = nullptr;
  }
  m_pItemsClientSide = this->m_pItemsClientSide;
  this->m_pItems = v3;
  if ( m_pItemsClientSide != nullptr )
  {
    ((void (__thiscall *)(INetworkStringDict *, int))m_pItemsClientSide->dtr_INetworkStringDict)(
      a1: m_pItemsClientSide,
      a2: 1);
    v7 = (INetworkStringDict *)MemAlloc_Alloc(nSize: 0x24u);
    if ( v7 != nullptr )
    {
      v7->__vftable = (INetworkStringDict_vtbl *)&CNetworkStringDict::`vftable';
      LOBYTE(v7[1].__vftable) = 0;
      v7[2].__vftable = (INetworkStringDict_vtbl *)CNetworkStringDict::CTableItem::Less;
      v7[3].__vftable = nullptr;
      v7[4].__vftable = nullptr;
      v7[5].__vftable = nullptr;
      v8 = v7[3].__vftable;
      v7[6].__vftable = (INetworkStringDict_vtbl *)0xFFFF;
      v7[7].__vftable = (INetworkStringDict_vtbl *)-1;
      v7[8].__vftable = v8;
    }
    else
    {
      v7 = nullptr;
    }
    this->m_pItemsClientSide = v7;
    v7->Insert(this: v7, a2: "___clientsideitemsplaceholder0___");
    this->m_pItemsClientSide->Insert(this: this->m_pItemsClientSide, a2: "___clientsideitemsplaceholder1___");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C7630
// Name: public: bool CNetworkStringTable::ReadStringTable(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetworkStringTable::ReadStringTable(CNetworkStringTable *this, bf_read *buf)
{
  CNetworkStringTable *v2; // ebx
  int m_nBitsAvail; // ecx
  int m_nInBufWord; // eax
  int v6; // edx
  int v7; // ecx
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  unsigned int v10; // ecx
  const unsigned int *v11; // edx
  unsigned int v12; // ebx
  int v13; // eax
  const unsigned int *v14; // ecx
  unsigned int v15; // edx
  unsigned int v16; // edi
  unsigned int v17; // edx
  unsigned int v18; // eax
  int v19; // ecx
  bool v20; // zf
  const unsigned int *v21; // eax
  const unsigned int *v22; // edx
  int v23; // ecx
  unsigned int v24; // eax
  int v25; // edx
  int v26; // ecx
  int v27; // edi
  const unsigned int *v28; // eax
  const unsigned int *v29; // ecx
  const unsigned int *v30; // edx
  unsigned int v31; // ebx
  int v32; // eax
  const unsigned int *v33; // ecx
  unsigned int v34; // edx
  unsigned int v35; // edi
  char *v36; // ebx
  unsigned int v37; // eax
  int v38; // edx
  const unsigned int *v39; // eax
  const unsigned int *v40; // ecx
  int v41; // ecx
  unsigned int v42; // eax
  int v43; // edx
  int v44; // ecx
  int v45; // edi
  const unsigned int *v46; // eax
  const unsigned int *v47; // ecx
  const unsigned int *v48; // edx
  unsigned int v49; // ebx
  int v50; // eax
  const unsigned int *v51; // ecx
  unsigned int v52; // edx
  unsigned int v53; // edi
  int v54; // ebx
  unsigned int v55; // eax
  int v56; // ecx
  const unsigned int *v57; // eax
  const unsigned int *v58; // edx
  int v59; // ecx
  unsigned int v60; // eax
  int v61; // edx
  int v62; // ecx
  int v63; // edi
  const unsigned int *v64; // eax
  const unsigned int *v65; // ecx
  const unsigned int *v66; // edx
  unsigned int v67; // ebx
  int v68; // eax
  const unsigned int *v69; // ecx
  unsigned int v70; // edx
  unsigned int v71; // edi
  char *v72; // ebx
  char pStr[4096]; // [esp+Ch] [ebp-1008h] BYREF
  int v75; // [esp+100Ch] [ebp-8h]
  CNetworkStringTable *v76; // [esp+1010h] [ebp-4h]
  CBitRead *i; // [esp+101Ch] [ebp+8h]
  int v78; // [esp+101Ch] [ebp+8h]

  v2 = this;
  v76 = this;
  CNetworkStringTable::DeleteAllStrings(this);
  m_nBitsAvail = buf->m_nBitsAvail;
  if ( m_nBitsAvail >= 16 )
  {
    m_nInBufWord = buf->m_nInBufWord;
    v6 = (unsigned __int16)m_nInBufWord;
    v7 = m_nBitsAvail - 16;
    buf->m_nBitsAvail = v7;
    if ( v7 != 0 )
    {
      buf->m_nInBufWord = HIWORD(m_nInBufWord);
      m_nInBufWord = (unsigned __int16)m_nInBufWord;
    }
    else
    {
      m_pDataIn = buf->m_pDataIn;
      m_pBufferEnd = buf->m_pBufferEnd;
      buf->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buf->m_pDataIn = m_pDataIn + 1;
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        m_nInBufWord = v6;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v10 = *m_pDataIn;
          buf->m_pDataIn = m_pDataIn + 1;
          buf->m_nInBufWord = v10;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
        m_nInBufWord = v6;
      }
    }
    goto LABEL_20;
  }
  v11 = buf->m_pBufferEnd;
  v12 = buf->m_nInBufWord;
  v13 = 16 - m_nBitsAvail;
  v14 = buf->m_pDataIn;
  if ( v14 == v11 )
  {
    buf->m_nBitsAvail = 1;
    buf->m_nInBufWord = 0;
    buf->m_bOverflow = true;
LABEL_15:
    buf->m_pDataIn = v14 + 1;
    goto LABEL_16;
  }
  if ( v14 <= v11 )
  {
    buf->m_nInBufWord = *v14;
    goto LABEL_15;
  }
  buf->m_bOverflow = true;
  buf->m_nInBufWord = 0;
LABEL_16:
  if ( buf->m_bOverflow )
  {
    m_nInBufWord = 0;
  }
  else
  {
    v15 = buf->m_nInBufWord;
    v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << buf->m_nBitsAvail;
    buf->m_nBitsAvail = 32 - v13;
    v17 = v15 >> v13;
    m_nInBufWord = v16 | v12;
    buf->m_nInBufWord = v17;
  }
  v2 = v76;
LABEL_20:
  if ( m_nInBufWord > 0 )
  {
    for ( i = (CBitRead *)m_nInBufWord; i != nullptr; i = (CBitRead *)((char *)i - 1) )
    {
      CBitRead::ReadString(this: buf, pStr, maxLen: 4096, bLine: false, pOutNumChars: nullptr);
      v18 = buf->m_nInBufWord;
      v19 = v18 & 1;
      v20 = buf->m_nBitsAvail-- == 1;
      if ( v20 )
      {
        v21 = buf->m_pDataIn;
        v22 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v21 == v22 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v21 + 1;
        }
        else if ( v21 <= v22 )
        {
          buf->m_nInBufWord = *v21;
          buf->m_pDataIn = v21 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
      }
      else
      {
        buf->m_nInBufWord = v18 >> 1;
      }
      if ( v19 != 1 )
      {
        v2->AddString(this: v2, a2: true, a3: pStr, a4: -1, a5: nullptr);
        continue;
      }
      v23 = buf->m_nBitsAvail;
      if ( v23 >= 16 )
      {
        v24 = buf->m_nInBufWord;
        v25 = (unsigned __int16)v24;
        v26 = v23 - 16;
        buf->m_nBitsAvail = v26;
        if ( v26 != 0 )
        {
          buf->m_nInBufWord = HIWORD(v24);
          v27 = (unsigned __int16)v24;
        }
        else
        {
          v28 = buf->m_pDataIn;
          v29 = buf->m_pBufferEnd;
          buf->m_nBitsAvail = 32;
          if ( v28 == v29 )
          {
            buf->m_nInBufWord = 0;
            buf->m_nBitsAvail = 1;
            buf->m_pDataIn = v28 + 1;
            v27 = v25;
          }
          else
          {
            if ( v28 <= v29 )
            {
              buf->m_nInBufWord = *v28;
              buf->m_pDataIn = v28 + 1;
            }
            else
            {
              buf->m_nInBufWord = 0;
              buf->m_bOverflow = true;
            }
            v27 = v25;
          }
        }
        goto LABEL_48;
      }
      v30 = buf->m_pBufferEnd;
      v31 = buf->m_nInBufWord;
      v32 = 16 - v23;
      v33 = buf->m_pDataIn;
      if ( v33 == v30 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_bOverflow = true;
      }
      else
      {
        if ( v33 > v30 )
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
          goto LABEL_45;
        }
        buf->m_nInBufWord = *v33;
      }
      buf->m_pDataIn = v33 + 1;
LABEL_45:
      if ( buf->m_bOverflow )
      {
        v27 = 0;
      }
      else
      {
        v34 = buf->m_nInBufWord;
        v35 = (v34 & CBitBuffer::s_nMaskTable[v32]) << buf->m_nBitsAvail;
        buf->m_nBitsAvail = 32 - v32;
        v27 = v31 | v35;
        buf->m_nInBufWord = v34 >> v32;
      }
LABEL_48:
      v36 = (char *)MemAlloc_Alloc(nSize: v27 + 4);
      CBitRead::ReadBytes(this: buf, pOut: v36, nBytes: v27);
      v76->AddString(this: v76, a2: true, a3: pStr, a4: v27, a5: v36);
      free(pMem: v36);
      v2 = v76;
    }
  }
  v37 = buf->m_nInBufWord;
  v38 = v37 & 1;
  v20 = buf->m_nBitsAvail-- == 1;
  if ( v20 )
  {
    v39 = buf->m_pDataIn;
    v40 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v39 == v40 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v39 + 1;
    }
    else if ( v39 <= v40 )
    {
      buf->m_nInBufWord = *v39;
      buf->m_pDataIn = v39 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v37 >> 1;
  }
  if ( v38 != 1 )
    return 1;
  v41 = buf->m_nBitsAvail;
  if ( v41 < 16 )
  {
    v48 = buf->m_pBufferEnd;
    v49 = buf->m_nInBufWord;
    v50 = 16 - v41;
    v51 = buf->m_pDataIn;
    if ( v51 == v48 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v51 > v48 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_74;
      }
      buf->m_nInBufWord = *v51;
    }
    buf->m_pDataIn = v51 + 1;
LABEL_74:
    if ( buf->m_bOverflow )
    {
      v45 = 0;
      v78 = 0;
    }
    else
    {
      v52 = buf->m_nInBufWord;
      v53 = (v52 & CBitBuffer::s_nMaskTable[v50]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v50;
      v45 = v53 | v49;
      v78 = v45;
      buf->m_nInBufWord = v52 >> v50;
    }
    goto LABEL_77;
  }
  v42 = buf->m_nInBufWord;
  v43 = (unsigned __int16)v42;
  v44 = v41 - 16;
  buf->m_nBitsAvail = v44;
  if ( v44 != 0 )
  {
    v45 = (unsigned __int16)v42;
    buf->m_nInBufWord = HIWORD(v42);
    v78 = (unsigned __int16)v42;
  }
  else
  {
    v46 = buf->m_pDataIn;
    v47 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v46 == v47 )
    {
      buf->m_nInBufWord = 0;
      v45 = v43;
      buf->m_nBitsAvail = 1;
      buf->m_pDataIn = v46 + 1;
      v78 = v43;
    }
    else
    {
      if ( v46 <= v47 )
      {
        v45 = v43;
        buf->m_nInBufWord = *v46;
        buf->m_pDataIn = v46 + 1;
      }
      else
      {
        buf->m_nInBufWord = 0;
        v45 = v43;
        buf->m_bOverflow = true;
      }
      v78 = v43;
    }
  }
LABEL_77:
  v54 = 0;
  v75 = 0;
  if ( v45 > 0 )
  {
    while ( 1 )
    {
      CBitRead::ReadString(this: buf, pStr, maxLen: 4096, bLine: false, pOutNumChars: nullptr);
      v55 = buf->m_nInBufWord;
      v56 = v55 & 1;
      v20 = buf->m_nBitsAvail-- == 1;
      if ( v20 )
      {
        v57 = buf->m_pDataIn;
        v58 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v57 == v58 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v57 + 1;
        }
        else if ( v57 <= v58 )
        {
          buf->m_nInBufWord = *v57;
          buf->m_pDataIn = v57 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
      }
      else
      {
        buf->m_nInBufWord = v55 >> 1;
      }
      if ( v56 != 1 )
      {
        if ( v54 >= 2 )
          v76->AddString(this: v76, a2: false, a3: pStr, a4: -1, a5: nullptr);
        goto LABEL_109;
      }
      v59 = buf->m_nBitsAvail;
      if ( v59 < 16 )
        break;
      v60 = buf->m_nInBufWord;
      v61 = (unsigned __int16)v60;
      v62 = v59 - 16;
      buf->m_nBitsAvail = v62;
      if ( v62 != 0 )
      {
        buf->m_nInBufWord = HIWORD(v60);
        v63 = (unsigned __int16)v60;
      }
      else
      {
        v64 = buf->m_pDataIn;
        v65 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v64 == v65 )
        {
          buf->m_nInBufWord = 0;
          buf->m_nBitsAvail = 1;
          buf->m_pDataIn = v64 + 1;
          v63 = v61;
        }
        else
        {
          if ( v64 <= v65 )
          {
            buf->m_nInBufWord = *v64;
            buf->m_pDataIn = v64 + 1;
          }
          else
          {
            buf->m_nInBufWord = 0;
            buf->m_bOverflow = true;
          }
          v63 = v61;
        }
      }
LABEL_104:
      v72 = (char *)MemAlloc_Alloc(nSize: v63 + 4);
      CBitRead::ReadBytes(this: buf, pOut: v72, nBytes: v63);
      if ( v75 >= 2 )
        v76->AddString(this: v76, a2: false, a3: pStr, a4: v63, a5: v72);
      free(pMem: v72);
      v45 = v78;
      v54 = v75;
LABEL_109:
      v75 = ++v54;
      if ( v54 >= v45 )
        return 1;
    }
    v66 = buf->m_pBufferEnd;
    v67 = buf->m_nInBufWord;
    v68 = 16 - v59;
    v69 = buf->m_pDataIn;
    if ( v69 == v66 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v69 > v66 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_101;
      }
      buf->m_nInBufWord = *v69;
    }
    buf->m_pDataIn = v69 + 1;
LABEL_101:
    if ( buf->m_bOverflow )
    {
      v63 = 0;
    }
    else
    {
      v70 = buf->m_nInBufWord;
      v71 = (v70 & CBitBuffer::s_nMaskTable[v68]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v68;
      v63 = v67 | v71;
      buf->m_nInBufWord = v70 >> v68;
    }
    goto LABEL_104;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C7BF0
// Name: public: virtual void CNetworkStringTableContainer::SetAllowClientSideAddString(class INetworkStringTable __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableContainer::SetAllowClientSideAddString(
        CNetworkStringTableContainer *this,
        INetworkStringTable *table,
        bool bAllowClientSideAddString)
{
  int v4; // ebx
  INetworkStringTable *v5; // esi
  INetworkStringTable_vtbl *v6; // ecx
  INetworkStringTable_vtbl *v7; // eax
  int (__thiscall *GetNumStrings)(INetworkStringTable *); // ecx

  v4 = 0;
  if ( this->m_Tables.m_Size > 0 )
  {
    while ( 1 )
    {
      v5 = this->GetTable(this, a2: v4);
      if ( v5 == table )
        break;
      if ( ++v4 >= this->m_Tables.m_Size )
        return;
    }
    if ( bAllowClientSideAddString != (((int)v5[7].__vftable & 4) != 0) )
    {
      v6 = v5[15].__vftable;
      LOBYTE(v5[7].__vftable) ^= (LOBYTE(v5[7].__vftable) ^ (4 * bAllowClientSideAddString)) & 4;
      if ( v6 != nullptr )
      {
        (*(void (__thiscall **)(INetworkStringTable_vtbl *, int))v6->dtr_INetworkStringTable)(a1: v6, a2: 1);
        v5[15].__vftable = nullptr;
      }
      if ( ((int)v5[7].__vftable & 4) != 0 )
      {
        v7 = (INetworkStringTable_vtbl *)MemAlloc_Alloc(nSize: 0x24u);
        if ( v7 != nullptr )
        {
          v7->dtr_INetworkStringTable = (void (__thiscall *)(INetworkStringTable *))&CNetworkStringDict::`vftable';
          LOBYTE(v7->GetTableName) = 0;
          v7->GetTableId = (int (__thiscall *)(INetworkStringTable *))CNetworkStringDict::CTableItem::Less;
          v7->GetNumStrings = nullptr;
          v7->GetMaxStrings = nullptr;
          v7->GetEntryBits = nullptr;
          GetNumStrings = v7->GetNumStrings;
          v7->SetTick = (void (__thiscall *)(INetworkStringTable *, int))0xFFFF;
          v7->ChangedSinceTick = (bool (__thiscall *)(INetworkStringTable *, int))-1;
          v7->AddString = (int (__thiscall *)(INetworkStringTable *, bool, const char *, int, const void *))GetNumStrings;
        }
        else
        {
          v7 = nullptr;
        }
        v5[15].__vftable = v7;
        (*((void (__thiscall **)(INetworkStringTable_vtbl *, const char *))v7->dtr_INetworkStringTable + 5))(
          a1: v7,
          a2: "___clientsideitemsplaceholder0___");
        (*((void (__thiscall **)(INetworkStringTable_vtbl *, const char *))v5[15].dtr_INetworkStringTable + 5))(
          a1: v5[15].__vftable,
          a2: "___clientsideitemsplaceholder1___");
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C7CD0
// Name: public: virtual class INetworkStringTable __near * CNetworkStringTableContainer::CreateStringTable(char const __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
CNetworkStringTable *__thiscall CNetworkStringTableContainer::CreateStringTable(
        CNetworkStringTableContainer *this,
        const char *tableName,
        int maxentries,
        int userdatafixedsize,
        int userdatanetworkbits,
        int flags)
{
  int m_Size; // edi
  CNetworkStringTable *v9; // eax
  CNetworkStringTable *v10; // ebx
  int v11; // edi
  int m_nAllocationCount; // eax
  CNetworkStringTable **m_pMemory; // ecx
  int v14; // eax
  CNetworkStringTable **v15; // edi

  if ( this->m_bAllowCreation )
  {
    if ( this->FindTable(this, a2: tableName) != nullptr )
    {
      Sys_Error(error: "Tried to create string table '%s' twice\n", tableName);
      return nullptr;
    }
    else
    {
      m_Size = this->m_Tables.m_Size;
      if ( m_Size < 32 )
      {
        v9 = (CNetworkStringTable *)MemAlloc_Alloc(nSize: 0x40u);
        if ( v9 != nullptr )
          v10 = CNetworkStringTable::CNetworkStringTable(
                  this: v9,
                  id: m_Size,
                  tableName,
                  maxentries,
                  userdatafixedsize,
                  userdatanetworkbits,
                  flags);
        else
          v10 = nullptr;
        if ( this->m_bEnableRollback )
          *((_BYTE *)v10 + 28) |= 1u;
        v10->SetTick(this: v10, a2: this->m_nTickCount);
        v11 = this->m_Tables.m_Size;
        m_nAllocationCount = this->m_Tables.m_Memory.m_nAllocationCount;
        if ( v11 + 1 > m_nAllocationCount )
          CUtlMemory<INetMessage *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&this->m_Tables,
            num: v11 - m_nAllocationCount + 1);
        ++this->m_Tables.m_Size;
        m_pMemory = this->m_Tables.m_Memory.m_pMemory;
        v14 = this->m_Tables.m_Size - v11 - 1;
        this->m_Tables.m_pElements = m_pMemory;
        if ( v14 > 0 )
          _V_memmove(dest: &m_pMemory[v11 + 1], src: &m_pMemory[v11], count: 4 * v14);
        v15 = &this->m_Tables.m_Memory.m_pMemory[v11];
        if ( v15 != nullptr )
          *v15 = v10;
        return v10;
      }
      else
      {
        Sys_Error(error: "Only %i string tables allowed, can't create'%s'", 32, tableName);
        return nullptr;
      }
    }
  }
  else
  {
    Sys_Error(error: "Tried to create string table '%s' at wrong time\n", tableName);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C7DE0
// Name: public: bool CNetworkStringTableContainer::ReadStringTables(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetworkStringTableContainer::ReadStringTables(CNetworkStringTableContainer *this, bf_read *buf)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  int v4; // edi
  unsigned int v5; // edx
  const unsigned int *v6; // eax
  const unsigned int *v7; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // edi
  int v10; // eax
  const unsigned int *m_pDataIn; // ecx
  unsigned int v12; // edx
  unsigned int v13; // ebx
  CNetworkStringTable *v14; // eax
  char tablename[256]; // [esp+Ch] [ebp-104h] BYREF
  CNetworkStringTableContainer *v17; // [esp+10Ch] [ebp-4h]

  v17 = this;
  m_nBitsAvail = buf->m_nBitsAvail;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = buf->m_pBufferEnd;
    m_nInBufWord = buf->m_nInBufWord;
    v10 = 8 - m_nBitsAvail;
    m_pDataIn = buf->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
LABEL_15:
        if ( buf->m_bOverflow )
        {
          v4 = 0;
          goto LABEL_19;
        }
        v12 = buf->m_nInBufWord;
        v13 = (v12 & CBitBuffer::s_nMaskTable[v10]) << buf->m_nBitsAvail;
        buf->m_nBitsAvail = 32 - v10;
        v4 = v13 | m_nInBufWord;
        v5 = v12 >> v10;
        goto LABEL_18;
      }
      buf->m_nInBufWord = *m_pDataIn;
    }
    buf->m_pDataIn = m_pDataIn + 1;
    goto LABEL_15;
  }
  v3 = buf->m_nInBufWord;
  v4 = (unsigned __int8)v3;
  buf->m_nBitsAvail = m_nBitsAvail - 8;
  if ( m_nBitsAvail != 8 )
  {
    v5 = v3 >> 8;
LABEL_18:
    buf->m_nInBufWord = v5;
    goto LABEL_19;
  }
  v6 = buf->m_pDataIn;
  v7 = buf->m_pBufferEnd;
  buf->m_nBitsAvail = 32;
  if ( v6 == v7 )
  {
    buf->m_nBitsAvail = 1;
    buf->m_nInBufWord = 0;
    buf->m_pDataIn = v6 + 1;
  }
  else if ( v6 <= v7 )
  {
    buf->m_nInBufWord = *v6;
    buf->m_pDataIn = v6 + 1;
  }
  else
  {
    buf->m_bOverflow = true;
    buf->m_nInBufWord = 0;
  }
LABEL_19:
  if ( v4 > 0 )
  {
    do
    {
      CBitRead::ReadString(this: buf, pStr: tablename, maxLen: 256, bLine: false, pOutNumChars: nullptr);
      v14 = (CNetworkStringTable *)v17->FindTable(this: v17, a2: tablename);
      if ( CNetworkStringTable::ReadStringTable(this: v14, buf) == 0 )
        Host_Error(error: "Error reading string table %s\n", tablename);
      --v4;
    }
    while ( v4 != 0 );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1031D090
// Name: _dynamic_initializer_for__stringtable_usedictionaries__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__stringtable_usedictionaries__()
{
  ConVar::ConVar(
    this: &stringtable_usedictionaries,
    pName: "stringtable_usedictionaries",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Use dictionaries for string table networking\n");
  return atexit(func: dynamic_atexit_destructor_for__stringtable_usedictionaries__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D0C0
// Name: _dynamic_initializer_for__stringtable_alwaysrebuilddictionaries__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__stringtable_alwaysrebuilddictionaries__()
{
  ConVar::ConVar(
    this: &stringtable_alwaysrebuilddictionaries,
    pName: "stringtable_alwaysrebuilddictionaries",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Rebuild dictionary file on every level load\n");
  return atexit(func: dynamic_atexit_destructor_for__stringtable_alwaysrebuilddictionaries__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D0F0
// Name: _dynamic_initializer_for__stringtable_compress__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__stringtable_compress__()
{
  ConVar::ConVar(
    this: &stringtable_compress,
    pName: "stringtable_compress",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Compress string table for networking\n");
  return atexit(func: dynamic_atexit_destructor_for__stringtable_compress__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D120
// Name: _dynamic_initializer_for__stringtable_showsizes__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__stringtable_showsizes__()
{
  ConVar::ConVar(
    this: &stringtable_showsizes,
    pName: "stringtable_showsizes",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show sizes of string tables when building for signon\n");
  return atexit(func: dynamic_atexit_destructor_for__stringtable_showsizes__);
}

//------------------------------------------------------------------------------
// Address: 0x10326530
// Name: _dynamic_atexit_destructor_for__stringtable_usedictionaries__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__stringtable_usedictionaries__()
{
  ConVar::~ConVar(this: &stringtable_usedictionaries);
}

//------------------------------------------------------------------------------
// Address: 0x10326540
// Name: _dynamic_atexit_destructor_for__stringtable_alwaysrebuilddictionaries__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__stringtable_alwaysrebuilddictionaries__()
{
  ConVar::~ConVar(this: &stringtable_alwaysrebuilddictionaries);
}

//------------------------------------------------------------------------------
// Address: 0x10326550
// Name: _dynamic_atexit_destructor_for__stringtable_compress__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__stringtable_compress__()
{
  ConVar::~ConVar(this: &stringtable_compress);
}

//------------------------------------------------------------------------------
// Address: 0x10326560
// Name: _dynamic_atexit_destructor_for__stringtable_showsizes__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__stringtable_showsizes__()
{
  ConVar::~ConVar(this: &stringtable_showsizes);
}

//------------------------------------------------------------------------------
// Address: 0x101C7F20
// Name: __CreateCNetworkStringTableContainerINetworkStringTableContainer_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CNetworkStringTableContainer *__cdecl _CreateCNetworkStringTableContainerINetworkStringTableContainer_interface()
{
  return &s_NetworkStringTableClient;
}

//------------------------------------------------------------------------------
// Address: 0x1031D150
// Name: _dynamic_initializer_for__g_StringTableDictionary__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StringTableDictionary__()
{
  CUtlString::CUtlString(this: &g_StringTableDictionary.m_sCurrentMap);
  g_StringTableDictionary.m_Strings.m_Memory.m_pMemory = nullptr;
  g_StringTableDictionary.m_Strings.m_Memory.m_nAllocationCount = 0;
  g_StringTableDictionary.m_Strings.m_Memory.m_nGrowSize = 0;
  g_StringTableDictionary.m_Strings.m_Size = 0;
  g_StringTableDictionary.m_Strings.m_pElements = nullptr;
  g_StringTableDictionary.m_StringHashToIndex.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const unsigned int *, const unsigned int *))CDmxSerializationDictionary::LessFunc;
  g_StringTableDictionary.m_StringHashToIndex.m_Tree.m_Elements.m_pMemory = nullptr;
  g_StringTableDictionary.m_StringHashToIndex.m_Tree.m_Elements.m_nAllocationCount = 0;
  g_StringTableDictionary.m_StringHashToIndex.m_Tree.m_Elements.m_nGrowSize = 0;
  *(_DWORD *)&g_StringTableDictionary.m_StringHashToIndex.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&g_StringTableDictionary.m_StringHashToIndex.m_Tree.m_FirstFree = -1;
  g_StringTableDictionary.m_StringHashToIndex.m_Tree.m_pElements = nullptr;
  g_StringTableDictionary.m_CRC = 0;
  g_StringTableDictionary.m_nEncodeBits = 1;
  *(_WORD *)&g_StringTableDictionary.m_bForceRebuildDictionaries = 0;
  CNetworkStringTableDictionaryManager::CStringTableDictionaryCache::CStringTableDictionaryCache(this: &g_StringTableDictionary.m_BuildStringTableDictionaryCache);
  return atexit(func: dynamic_atexit_destructor_for__g_StringTableDictionary__);
}

//------------------------------------------------------------------------------
// Address: 0x10326570
// Name: _dynamic_atexit_destructor_for__g_StringTableDictionary__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StringTableDictionary__()
{
  CNetworkStringTableDictionaryManager::~CNetworkStringTableDictionaryManager(this: &g_StringTableDictionary);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1003CD30
// Name: public: void CNetworkStringTable::SetMirrorTable(class INetworkStringTable __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTable::SetMirrorTable(CAudioMixerWave *this, int delaySamples)
{
  this->m_delaySamples = delaySamples;
}

//------------------------------------------------------------------------------
// Address: 0x1003E310
// Name: public: void (*CNetworkStringTable::GetCallback(void))(void __near *,class INetworkStringTable __near *,int,char const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetworkStringTable::GetCallback(CVTFTexture *this)
{
  return this->m_nFlags;
}

//------------------------------------------------------------------------------
// Address: 0x101C2AB0
// Name: private: unsigned long CNetworkStringTableDictionaryManager::HashStringCaselessIgnoreSlashes(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CNetworkStringTableDictionaryManager::HashStringCaselessIgnoreSlashes(
        CNetworkStringTableDictionaryManager *this,
        const char *pString)
{
  const char *v2; // ebx
  int v3; // esi
  void *v4; // esp
  char v6[12]; // [esp+0h] [ebp-Ch] BYREF

  v2 = pString;
  if ( pString == nullptr )
    v2 = defaultValue;
  v3 = _V_strlen(str: v2) + 1;
  v4 = alloca(v3);
  V_strncpy(pDest: v6, pSrc: v2, maxLen: v3);
  V_FixSlashes(pname: v6, separator: 92);
  _V_strlower(start: v6);
  CRC32_Init(pulCRC: (unsigned int *)&pString);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&pString, pBuffer: v6, nBuffer: v3);
  CRC32_Final(pulCRC: (unsigned int *)&pString);
  return pString;
}

//------------------------------------------------------------------------------
// Address: 0x101C2CA0
// Name: public: static bool CNetworkStringDict::CTableItem::Less(class CNetworkStringDict::CTableItem const __near &,class CNetworkStringDict::CTableItem const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CNetworkStringDict::CTableItem::Less(
        const CNetworkStringDict::CTableItem *lhs,
        const CNetworkStringDict::CTableItem *rhs)
{
  return lhs->m_StringHash < rhs->m_StringHash;
}

//------------------------------------------------------------------------------
// Address: 0x101C2CC0
// Name: public: bool CNetworkStringTable::IsUsingDictionary(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetworkStringTable::IsUsingDictionary(CNetworkStringTable *this)
{
  return this->m_nFlags & 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C2CE0
// Name: public: virtual void CNetworkStringTable::Lock(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTable::Lock(CNetworkStringTable *this, bool bLock)
{
  *((_BYTE *)this + 28) ^= (*((_BYTE *)this + 28) ^ (2 * bLock)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x101C2D00
// Name: public: void CNetworkStringTable::RestoreTick(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTable::RestoreTick(CNetworkStringTable *this, int tick)
{
  INetworkStringDict *m_pItems; // ecx
  int v4; // edi
  int v5; // ebx
  CNetworkStringTableItem *v6; // eax
  int v7; // eax

  m_pItems = this->m_pItems;
  v4 = 0;
  this->m_nLastChangedTick = 0;
  v5 = m_pItems->Count(this: m_pItems);
  if ( v5 > 0 )
  {
    do
    {
      v6 = this->m_pItems->Element_2(this: this->m_pItems, a2: v4);
      v7 = CNetworkStringTableItem::RestoreTick(this: v6, tick);
      if ( v7 > this->m_nLastChangedTick )
        this->m_nLastChangedTick = v7;
      ++v4;
    }
    while ( v4 < v5 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C2D50
// Name: public: void CNetworkStringTable::UpdateMirrorTable(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CNetworkStringTable::UpdateMirrorTable(
        CNetworkStringTable *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int tick_ack)
{
  int v5; // edi
  CNetworkStringTableItem *v6; // eax
  CNetworkStringTableItem *v7; // ebx
  const void *UserData; // eax
  int m_nUserDataLength; // ebx
  int v10; // eax
  int v13; // [esp+0h] [ebp-10h]
  int count; // [esp+4h] [ebp-Ch]
  const void *pUserData; // [esp+Ch] [ebp-4h]

  if ( this->m_pMirrorTable != nullptr )
  {
    this->m_pMirrorTable->SetTick(this: this->m_pMirrorTable, a2: this->m_nTickCount);
    v5 = 0;
    count = this->m_pItems->Count(this: this->m_pItems);
    if ( count > 0 )
    {
      do
      {
        v6 = this->m_pItems->Element_2(this: this->m_pItems, a2: v5);
        v7 = v6;
        if ( v6->m_nTickChanged > tick_ack )
        {
          UserData = CNetworkStringTableItem::GetUserData(this: v6, length: nullptr);
          m_nUserDataLength = v7->m_nUserDataLength;
          pUserData = UserData;
          if ( m_nUserDataLength == 0 || UserData == nullptr )
          {
            m_nUserDataLength = 0;
            pUserData = nullptr;
          }
          if ( v5 >= ((int (__thiscall *)(INetworkStringTable *, int, int))this->m_pMirrorTable->GetNumStrings)(
                       a1: this->m_pMirrorTable,
                       a2,
                       a3) )
          {
            v10 = ((int (__thiscall *)(INetworkStringDict *, int, int, int))this->m_pItems->String)(
                    a1: this->m_pItems,
                    a2: v5,
                    a3: v13,
                    a4: count);
            count = (int)pUserData;
            v13 = m_nUserDataLength;
            a3 = v10;
            a2 = 1;
            ((void (__thiscall *)(INetworkStringTable *))this->m_pMirrorTable->AddString)(a1: this->m_pMirrorTable);
          }
          else
          {
            a3 = (int)pUserData;
            a2 = m_nUserDataLength;
            ((void (__thiscall *)(INetworkStringTable *, int))this->m_pMirrorTable->SetStringUserData)(
              a1: this->m_pMirrorTable,
              a2: v5);
          }
        }
        ++v5;
      }
      while ( v5 < count );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C2E10
// Name: public: void CNetworkStringTable::CopyStringTable(class CNetworkStringTable __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTable::CopyStringTable(CNetworkStringTable *this, CNetworkStringTable *table)
{
  CNetworkStringTable *v2; // ebx
  int v3; // esi
  CNetworkStringTableItem *v4; // eax
  CNetworkStringTable_vtbl *v5; // ebx
  int v6; // eax

  v2 = this;
  v3 = 0;
  if ( table->m_pItems->Count(this: table->m_pItems) != 0 )
  {
    while ( 1 )
    {
      v4 = table->m_pItems->Element_2(this: table->m_pItems, a2: v3);
      v2->m_nTickCount = v4->m_nTickChanged;
      v5 = v2->__vftable;
      v6 = ((int (__thiscall *)(CNetworkStringTable *, int, int, unsigned __int8 *))table->GetString)(
             a1: table,
             a2: v3,
             a3: v4->m_nUserDataLength,
             a4: v4->m_pUserData);
      ((void (__thiscall *)(CNetworkStringTable *, int, int))v5->AddString)(a1: this, a2: 1, a3: v6);
      if ( ++v3 >= table->m_pItems->Count(this: table->m_pItems) )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C2E80
// Name: public: virtual void CNetworkStringTable::SetStringChangedCallback(void __near *,void (*)(void __near *,class INetworkStringTable __near *,int,char const __near *,void const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTable::SetStringChangedCallback(
        CNetworkStringTable *this,
        void *object,
        void (__cdecl *changeFunc)(void *, INetworkStringTable *, int, const char *, const void *))
{
  this->m_changeFunc = changeFunc;
  this->m_pObject = object;
}

//------------------------------------------------------------------------------
// Address: 0x101C2EA0
// Name: public: virtual bool CNetworkStringTable::ChangedSinceTick(int)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CNetworkStringTable::ChangedSinceTick(CNetworkStringTable *this, int tick)
{
  return this->m_nLastChangedTick > tick;
}

//------------------------------------------------------------------------------
// Address: 0x101C2EC0
// Name: public: virtual char const __near * CNetworkStringTable::GetString(int)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CNetworkStringTable::GetString(CNetworkStringTable *this, int stringNumber)
{
  INetworkStringDict *m_pItems; // esi
  INetworkStringDict *m_pItemsClientSide; // ecx
  int v4; // edi

  m_pItems = this->m_pItems;
  m_pItemsClientSide = this->m_pItemsClientSide;
  v4 = stringNumber;
  if ( m_pItemsClientSide != nullptr && stringNumber < -1 )
  {
    m_pItems = m_pItemsClientSide;
    v4 = -stringNumber;
  }
  if ( m_pItems->IsValidIndex(this: m_pItems, a2: v4) )
    return m_pItems->String(this: m_pItems, a2: v4);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101C2F10
// Name: protected: void CNetworkStringTable::DataChanged(int,class CNetworkStringTableItem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTable::DataChanged(
        CNetworkStringTable *this,
        int stringNumber,
        CNetworkStringTableItem *item)
{
  CNetworkStringTableItem *v4; // ecx
  bool v5; // zf
  const char *v6; // eax

  v4 = item;
  if ( item != nullptr )
  {
    v5 = this->m_changeFunc == nullptr;
    this->m_nLastChangedTick = this->m_nTickCount;
    if ( !v5 )
    {
      CNetworkStringTableItem::GetUserData(this: v4, length: (int *)&item);
      v6 = this->GetString(this, a2: stringNumber);
      ((void (__cdecl *)(void *, CNetworkStringTable *, int, const char *))this->m_changeFunc)(
        a1: this->m_pObject,
        a2: this,
        a3: stringNumber,
        a4: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C2F60
// Name: public: virtual void const __near * CNetworkStringTable::GetStringUserData(int,int __near *)const
// Source: json
//------------------------------------------------------------------------------
const void *__thiscall CNetworkStringTable::GetStringUserData(CNetworkStringTable *this, int stringNumber, int *length)
{
  INetworkStringDict *m_pItemsClientSide; // edx
  INetworkStringDict *m_pItems; // eax
  int v5; // ecx
  CNetworkStringTableItem *v6; // eax

  m_pItemsClientSide = this->m_pItemsClientSide;
  m_pItems = this->m_pItems;
  v5 = stringNumber;
  if ( m_pItemsClientSide != nullptr && stringNumber < -1 )
  {
    m_pItems = m_pItemsClientSide;
    v5 = -stringNumber;
  }
  v6 = m_pItems->Element_2(this: m_pItems, a2: v5);
  return CNetworkStringTableItem::GetUserData(this: v6, length);
}

//------------------------------------------------------------------------------
// Address: 0x101C2FA0
// Name: public: virtual int CNetworkStringTable::GetNumStrings(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CNetworkStringTable::GetNumStrings(CNetworkStringTable *this)
{
  return this->m_pItems->Count(this: this->m_pItems);
}

//------------------------------------------------------------------------------
// Address: 0x101C2FB0
// Name: public: virtual int CNetworkStringTable::FindStringIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetworkStringTable::FindStringIndex(CNetworkStringTable *this, const char *string)
{
  int v3; // edi
  int v5; // edi

  v3 = this->m_pItems->Find(this: this->m_pItems, a2: string);
  if ( this->m_pItems->IsValidIndex(this: this->m_pItems, a2: v3) )
    return v3;
  if ( this->m_pItemsClientSide != nullptr )
  {
    v5 = this->m_pItemsClientSide->Find(this: this->m_pItemsClientSide, a2: string);
    if ( this->m_pItemsClientSide->IsValidIndex(this: this->m_pItemsClientSide, a2: v5) )
      return -v5;
  }
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x101C3020
// Name: public: virtual void CNetworkStringTable::Dump(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTable::Dump(CNetworkStringTable *this)
{
  const char *v2; // eax
  int v3; // eax
  int v4; // eax
  int i; // edi
  INetworkStringDict *m_pItems; // ecx
  int v7; // eax
  INetworkStringDict *v8; // ecx
  const char *v9; // eax
  int j; // edi
  const char *v11; // eax
  int v12; // [esp-4h] [ebp-14h]
  int v13; // [esp-4h] [ebp-14h]
  int v14; // [esp-4h] [ebp-14h]
  int v15; // [esp+0h] [ebp-10h]
  int nCurrentDictionaryIndex; // [esp+Ch] [ebp-4h]

  v2 = this->GetTableName(this);
  ConMsg(a1: "Table %s\n", v2);
  v3 = this->GetMaxStrings(this);
  v4 = ((int (__thiscall *)(CNetworkStringTable *, int))this->GetNumStrings)(a1: this, a2: v3);
  ConMsg(a1: "  %i/%i items\n", v4, v12);
  for ( i = 0; i < this->GetNumStrings(this); ++i )
  {
    m_pItems = this->m_pItems;
    if ( (this->m_nFlags & 1) != 0 )
    {
      v7 = ((int (__thiscall *)(INetworkStringDict *, int, int))m_pItems->DictionaryIndex)(a1: m_pItems, a2: i, a3: v15);
      v8 = this->m_pItems;
      nCurrentDictionaryIndex = v7;
      if ( v7 == -1 )
      {
        v13 = (int)v8->String(this: v8, a2: i);
        ConMsg(a1: "         %i : %s\n", i, v13);
      }
      else
      {
        v9 = v8->String(this: v8, a2: i);
        ConMsg(a1: "d(%05d) %i : %s\n", nCurrentDictionaryIndex, i, v9);
      }
    }
    else
    {
      v14 = (int)m_pItems->String(this: m_pItems, a2: i);
      ConMsg(a1: "   %i : %s\n", i, v14);
    }
  }
  if ( this->m_pItemsClientSide != nullptr )
  {
    for ( j = 0; j < (int)this->m_pItemsClientSide->Count(this: this->m_pItemsClientSide); ++j )
    {
      v11 = this->m_pItemsClientSide->String(this: this->m_pItemsClientSide, a2: j);
      ConMsg(a1: "   (c)%i : %s\n", j, v11);
    }
  }
  ConMsg(a1: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x101C3140
// Name: public: void CNetworkStringTableContainer::EnableRollback(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableContainer::EnableRollback(CNetworkStringTableContainer *this, bool bState)
{
  this->m_bEnableRollback = bState;
}

//------------------------------------------------------------------------------
// Address: 0x101C3150
// Name: public: bool CNetworkStringTableDictionaryManager::ShouldRecreateDictionary(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetworkStringTableDictionaryManager::ShouldRecreateDictionary(
        CNetworkStringTableDictionaryManager *this,
        const char *pchMapName)
{
  V_FileBase(in: com_gamedir, out: gamedir_7, maxlen: 260);
  if ( _V_stricmp(s1: gamedir_7, s2: "infested") != 0 )
  {
    if ( this->m_bForceRebuildDictionaries )
      return this->m_Strings.m_Size == 0 || this->m_bLoadedFallbacks || MapReslistGenerator()->m_bLoggingEnabled;
    if ( MapReslistGenerator()->m_bLoggingEnabled )
    {
      if ( this->m_Strings.m_Size == 0 )
        return 1;
      if ( this->m_bLoadedFallbacks )
        return this->m_Strings.m_Size == 0 || this->m_bLoadedFallbacks || MapReslistGenerator()->m_bLoggingEnabled;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C31D0
// Name: public: bool CNetworkStringTableDictionaryManager::WriteDictionaryToBSP(char const __near *,class CUtlBuffer __near &,bool)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CNetworkStringTableDictionaryManager::WriteDictionaryToBSP@<al>(
        CNetworkStringTableDictionaryManager *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const char *pchMapName,
        CUtlBuffer *buf,
        bool bCreatingFor360)
{
  bool result; // al
  struct CSysModule *Module; // eax
  struct CSysModule *v9; // edi
  void *(__cdecl *Factory)(const char *, int *); // eax
  void (__thiscall ***v11)(_DWORD, IFileSystem *, char *, int, int, int); // eax
  void (__thiscall ***v12)(_DWORD, IFileSystem *, char *, _DWORD, _DWORD, _DWORD); // esi
  const char *v13; // eax
  void (__thiscall *v14)(_DWORD); // edx
  char mapPath[260]; // [esp+0h] [ebp-104h] BYREF

  V_snprintf(pDest: mapPath, maxLen: 260, pFormat: "maps/%s.bsp", pchMapName);
  result = g_pFileSystem->IsFileWritable(this: &g_pFileSystem->IBaseFileSystem, a2: mapPath, a3: "GAME");
  if ( result )
  {
    Module = FileSystem_LoadModule(path: "bsppack");
    v9 = Module;
    if ( Module == nullptr )
    {
LABEL_6:
      ConMsg(a1: "Can't load bsppack.dll\n");
      return false;
    }
    Factory = Sys_GetFactory(pModule: Module);
    if ( Factory == nullptr
      || (v11 = (void (__thiscall ***)(_DWORD, IFileSystem *, char *, int, int, int))Factory(
                                                                                       a1: "IBSPPACK003",
                                                                                       a2: nullptr),
          v12 = v11,
          v11 == nullptr) )
    {
      Sys_UnloadModule(pModule: v9);
      goto LABEL_6;
    }
    (**v11)(a1: v11, a2: g_pFileSystem, a3: mapPath, a4: a2, a5: a3, a6: a4);
    if ( bCreatingFor360 )
      v13 = "stringtable_dictionary_fallback_xbox.dct";
    else
      v13 = "stringtable_dictionary_fallback.dct";
    ((void (__thiscall *)(void (__thiscall ***)(_DWORD, IFileSystem *, char *, _DWORD, _DWORD, _DWORD), const char *, _DWORD))(*v12)[11])(
      a1: v12,
      a2: v13,
      a3: *(_DWORD *)mapPath);
    v14 = (void (__thiscall *)(_DWORD))(*v12)[4];
    *(_DWORD *)mapPath = 0;
    v14(a1: v12);
    ((void (__thiscall *)(void (__thiscall ***)(_DWORD, IFileSystem *, char *, _DWORD, _DWORD, _DWORD), char *))(*v12)[1])(
      a1: v12,
      a2: mapPath);
    ((void (__thiscall *)(void (__thiscall ***)(_DWORD, IFileSystem *, char *, _DWORD, _DWORD, _DWORD)))(*v12)[2])(a1: v12);
    FileSystem_UnloadModule(pModule: v9);
    _Msg(a1: "Updated stringtable dictionary saved to %s\n", mapPath);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C3370
// Name: public: virtual int CNetworkStringTable::AddString(bool,char const __near *,int,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CNetworkStringTable::AddString@<eax>(
        CNetworkStringTable *this@<ecx>,
        int a2@<ebx>,
        bool bIsServer,
        const char *string,
        int length,
        const void *userdata)
{
  const char *v7; // eax
  int v9; // ebx
  const char *v10; // eax
  int v11; // edi
  bool v12; // al
  INetworkStringDict *m_pItemsClientSide; // ecx
  unsigned int v14; // edi
  CNetworkStringTableItem *v15; // ebx
  char v16; // al
  INetworkStringDict *m_pItems; // ecx
  unsigned int v18; // ebx
  const char *v19; // eax
  CNetworkStringTableItem *v20; // eax
  CNetworkStringTableItem *v21; // edi
  const char *v22; // [esp-8h] [ebp-10h]
  const char *v23; // [esp-8h] [ebp-10h]
  const char *v24; // [esp-4h] [ebp-Ch]
  bool bHasChanged; // [esp+13h] [ebp+Bh]
  bool bHasChangeda; // [esp+13h] [ebp+Bh]

  if ( string == nullptr )
  {
    v7 = this->GetTableName(this);
    ConMsg(a1: "Warning:  Can't add NULL string to table %s\n", v7);
    return 0xFFFF;
  }
  v9 = ((int (__thiscall *)(INetworkStringDict *, const char *, int))this->m_pItems->Find)(
         a1: this->m_pItems,
         a2: string,
         a3: a2);
  if ( !bIsServer
    && (!this->m_pItems->IsValidIndex(this: this->m_pItems, a2: v9) || this->m_pItemsClientSide != nullptr) )
  {
    if ( this->m_pItemsClientSide != nullptr
      || (v10 = (const char *)((int (__thiscall *)(CNetworkStringTable *, const char *))this->GetTableName)(
                                a1: this,
                                a2: string),
          DevMsg(
            a1: "CNetworkStringTable::AddString:  client added string which server didn't put into table (consider SetAllowCl"
            "ientSideAddString?): %s %s\n",
            v10,
            v24),
          this->m_pItemsClientSide != nullptr) )
    {
      v11 = this->m_pItemsClientSide->Find(this: this->m_pItemsClientSide, a2: string);
      v12 = this->m_pItemsClientSide->IsValidIndex(this: this->m_pItemsClientSide, a2: v11);
      m_pItemsClientSide = this->m_pItemsClientSide;
      if ( v12 )
      {
        v15 = m_pItemsClientSide->Element_2(this: m_pItemsClientSide, a2: v11);
        bHasChanged = false;
LABEL_14:
        if ( (length > -1
           && CNetworkStringTableItem::SetUserData(this: v15, tick: this->m_nTickCount, length, userData: userdata)
           || bHasChanged)
          && (*((_BYTE *)this + 28) & 1) == 0 )
        {
          CNetworkStringTable::DataChanged(this, stringNumber: -v11, item: v15);
        }
        return -v11;
      }
      v14 = m_pItemsClientSide->Count(this: m_pItemsClientSide);
      v22 = string;
      if ( v14 < this->GetMaxStrings(this) )
      {
        v11 = this->m_pItemsClientSide->Insert(this: this->m_pItemsClientSide, a2: string);
        v15 = this->m_pItemsClientSide->Element_2(this: this->m_pItemsClientSide, a2: v11);
        v15->m_nTickChanged = this->m_nTickCount;
        v15->m_nTickCreated = this->m_nTickCount;
        if ( (*((_BYTE *)this + 28) & 1) != 0 )
          CNetworkStringTableItem::EnableChangeHistory(this: v15);
        bHasChanged = true;
        goto LABEL_14;
      }
LABEL_22:
      v19 = (const char *)((int (__thiscall *)(CNetworkStringTable *, const char *))this->GetTableName)(
                            a1: this,
                            a2: v22);
      ConMsg(a1: "Warning:  Table %s is full, can't add %s\n", v19, v23);
      return 0xFFFF;
    }
  }
  v16 = ((int (__thiscall *)(INetworkStringDict *))this->m_pItems->IsValidIndex)(a1: this->m_pItems);
  m_pItems = this->m_pItems;
  if ( v16 != 0 )
  {
    v21 = m_pItems->Element_2(this: m_pItems, a2: v9);
    bHasChangeda = false;
  }
  else
  {
    v18 = m_pItems->Count(this: m_pItems);
    v22 = string;
    if ( v18 >= this->GetMaxStrings(this) )
      goto LABEL_22;
    v9 = this->m_pItems->Insert(this: this->m_pItems, a2: string);
    v20 = this->m_pItems->Element_2(this: this->m_pItems, a2: v9);
    v21 = v20;
    v20->m_nTickChanged = this->m_nTickCount;
    v20->m_nTickCreated = this->m_nTickCount;
    if ( (*((_BYTE *)this + 28) & 1) != 0 )
      CNetworkStringTableItem::EnableChangeHistory(this: v20);
    bHasChangeda = true;
  }
  if ( (length > -1
     && CNetworkStringTableItem::SetUserData(this: v21, tick: this->m_nTickCount, length, userData: userdata)
     || bHasChangeda)
    && (*((_BYTE *)this + 28) & 1) == 0 )
  {
    CNetworkStringTable::DataChanged(this, stringNumber: v9, item: v21);
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x101C3590
// Name: public: virtual void CNetworkStringTable::SetStringUserData(int,int,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTable::SetStringUserData(
        CNetworkStringTable *this,
        int stringNumber,
        int length,
        const void *userdata)
{
  int v4; // eax
  INetworkStringDict *m_pItemsClientSide; // edx
  INetworkStringDict *m_pItems; // ecx
  int v8; // ebx
  CNetworkStringTableItem *v9; // edi
  bool v10; // zf
  const char *v11; // eax

  v4 = stringNumber;
  m_pItemsClientSide = this->m_pItemsClientSide;
  m_pItems = this->m_pItems;
  v8 = stringNumber;
  if ( m_pItemsClientSide != nullptr && stringNumber < -1 )
  {
    m_pItems = m_pItemsClientSide;
    v4 = -stringNumber;
  }
  v9 = m_pItems->Element_2(this: m_pItems, a2: v4);
  if ( CNetworkStringTableItem::SetUserData(this: v9, tick: this->m_nTickCount, length, userData: userdata)
    && v9 != nullptr )
  {
    v10 = this->m_changeFunc == nullptr;
    this->m_nLastChangedTick = this->m_nTickCount;
    if ( !v10 )
    {
      CNetworkStringTableItem::GetUserData(this: v9, length: &stringNumber);
      v11 = this->GetString(this, a2: v8);
      ((void (__cdecl *)(void *, CNetworkStringTable *, int, const char *))this->m_changeFunc)(
        a1: this->m_pObject,
        a2: this,
        a3: v8,
        a4: v11);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C3610
// Name: public: bool CNetworkStringTableContainer::Lock(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetworkStringTableContainer::Lock(CNetworkStringTableContainer *this, BOOL bLock)
{
  bool result; // al
  int v4; // edi
  INetworkStringTable *v5; // eax
  bool oldLock; // [esp+Fh] [ebp-1h]

  result = this->m_bLocked;
  v4 = 0;
  oldLock = result;
  this->m_bLocked = bLock;
  if ( this->m_Tables.m_Size > 0 )
  {
    do
    {
      v5 = this->GetTable(this, a2: v4);
      ((void (__thiscall *)(INetworkStringTable *, BOOL))v5->__vftable[1].GetTableName)(a1: v5, a2: bLock);
      ++v4;
    }
    while ( v4 < this->m_Tables.m_Size );
    return oldLock;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C3660
// Name: public: void CNetworkStringTableContainer::DirectUpdate(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableContainer::DirectUpdate(CNetworkStringTableContainer *this, int tick_ack)
{
  int i; // ebx
  CNetworkStringTable *v4; // esi

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CNetworkStringTableContainer::DirectUpdate",
    a3: 0,
    a4: "Networking",
    a5: false,
    a6: 4);
  for ( i = 0; i < this->m_Tables.m_Size; ++i )
  {
    v4 = (CNetworkStringTable *)this->GetTable(this, a2: i);
    if ( v4->ChangedSinceTick(this: v4, a2: tick_ack) )
      CNetworkStringTable::UpdateMirrorTable(this: v4, a2: i, a3: (int)this, tick_ack);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x101C36E0
// Name: public: void CNetworkStringTableContainer::SetTick(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableContainer::SetTick(CNetworkStringTableContainer *this, int tick_count)
{
  int v3; // edi
  INetworkStringTable *v4; // eax

  v3 = 0;
  for ( this->m_nTickCount = tick_count; v3 < this->m_Tables.m_Size; ++v3 )
  {
    v4 = this->GetTable(this, a2: v3);
    v4->SetTick(this: v4, a2: tick_count);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C3880
// Name: GetBestPreviousString
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetBestPreviousString(const char *newstring, int *substringsize)
{
  CUtlVector<StringHistoryEntry,CUtlMemory<StringHistoryEntry,int> > *history; // ecx
  int v3; // eax
  StringHistoryEntry *m_pMemory; // ecx
  int v5; // edi
  char v6; // dl
  int v7; // esi
  const char *v8; // ecx
  int c; // [esp+8h] [ebp-10h]
  int bestindex; // [esp+Ch] [ebp-Ch]
  StringHistoryEntry *v12; // [esp+10h] [ebp-8h]
  int bestcount; // [esp+14h] [ebp-4h]

  v3 = 0;
  bestindex = -1;
  bestcount = 0;
  c = history->m_Size;
  if ( c <= 0 )
  {
    *substringsize = 0;
    return -1;
  }
  else
  {
    m_pMemory = history->m_Memory.m_pMemory;
    v5 = (char *)m_pMemory - newstring;
    v12 = m_pMemory;
    do
    {
      v6 = m_pMemory->string[0];
      v7 = 0;
      if ( m_pMemory->string[0] != 0 )
      {
        v8 = newstring;
        do
        {
          if ( *v8 == 0 )
            break;
          if ( v6 != *v8 )
            break;
          if ( v7 >= 31 )
            break;
          v6 = (v8++)[v5 + 1];
          ++v7;
        }
        while ( v6 != 0 );
        if ( v7 >= 3 && v7 > bestcount )
        {
          bestcount = v7;
          bestindex = v3;
        }
      }
      ++v3;
      m_pMemory = v12 + 1;
      v5 += 32;
      ++v12;
    }
    while ( v3 < c );
    *substringsize = bestcount;
    return bestindex;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C3920
// Name: public: virtual void CNetworkStringTableDictionaryManager::OnBSPFullyUnloaded(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CNetworkStringTableDictionaryManager::OnBSPFullyUnloaded(
        CNetworkStringTableDictionaryManager *this@<ecx>,
        int a2@<edi>)
{
  const char *v3; // eax
  CUtlBuffer *p_m_Buffer; // [esp-8h] [ebp-10h]
  bool m_bCreatingForX360; // [esp-4h] [ebp-Ch]

  if ( this->m_BuildStringTableDictionaryCache.m_bActive )
  {
    m_bCreatingForX360 = this->m_BuildStringTableDictionaryCache.m_bCreatingForX360;
    p_m_Buffer = &this->m_BuildStringTableDictionaryCache.m_Buffer;
    v3 = CUtlString::operator char const *(this: &this->m_BuildStringTableDictionaryCache.m_sBSPName);
    CNetworkStringTableDictionaryManager::WriteDictionaryToBSP(
      this,
      a2: 0,
      a3: a2,
      a4: (int)this,
      pchMapName: v3,
      buf: p_m_Buffer,
      bCreatingFor360: m_bCreatingForX360);
    this->m_BuildStringTableDictionaryCache.m_bActive = false;
    CUtlString::operator=(this: &this->m_BuildStringTableDictionaryCache.m_sBSPName, src: defaultValue);
    this->m_BuildStringTableDictionaryCache.m_bCreatingForX360 = false;
    this->m_BuildStringTableDictionaryCache.m_Buffer.m_Get = 0;
    this->m_BuildStringTableDictionaryCache.m_Buffer.m_Put = 0;
    this->m_BuildStringTableDictionaryCache.m_Buffer.m_nOffset = 0;
    this->m_BuildStringTableDictionaryCache.m_Buffer.m_nMaxPut = 0;
    this->m_BuildStringTableDictionaryCache.m_Buffer.m_Error = 0;
    if ( this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(
          this: _g_pMemAlloc,
          a2: this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_pMemory);
        this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_pMemory = nullptr;
      }
      this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_nAllocationCount = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C39A0
// Name: public: virtual class INetworkStringTable __near * CNetworkStringTableContainer::FindTable(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CNetworkStringTable *__thiscall CNetworkStringTableContainer::FindTable(
        CNetworkStringTableContainer *this,
        const char *tableName)
{
  int v3; // esi
  CNetworkStringTable *v4; // ecx
  const char *v5; // eax

  v3 = 0;
  if ( this->m_Tables.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = this->m_Tables.m_Memory.m_pMemory[v3];
    v5 = v4->GetTableName(this: v4);
    if ( _V_stricmp(s1: tableName, s2: v5) == 0 )
      break;
    if ( ++v3 >= this->m_Tables.m_Size )
      return nullptr;
  }
  return this->m_Tables.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x101C39F0
// Name: public: virtual class INetworkStringTable __near * CNetworkStringTableContainer::GetTable(int)const
// Source: json
//------------------------------------------------------------------------------
CNetworkStringTable *__thiscall CNetworkStringTableContainer::GetTable(
        CNetworkStringTableContainer *this,
        int stringTable)
{
  if ( stringTable < 0 || stringTable >= this->m_Tables.m_Size )
    return nullptr;
  else
    return this->m_Tables.m_Memory.m_pMemory[stringTable];
}

//------------------------------------------------------------------------------
// Address: 0x101C3A10
// Name: public: void CNetworkStringTableContainer::WriteStringTables(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableContainer::WriteStringTables(CNetworkStringTableContainer *this, bf_write *buf)
{
  CNetworkStringTableContainer *v3; // edi
  CNetworkStringTable *v4; // edi
  const char *v5; // eax
  int j; // ebx
  const char *v7; // eax
  int v8; // eax
  int m_iCurBit; // ecx
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int *k; // ebx
  const char *v14; // eax
  CNetworkStringTableItem *v15; // eax
  void *UserData; // eax
  int v17; // ecx
  signed int numTables; // [esp+Ch] [ebp-18h]
  void *pBuf; // [esp+10h] [ebp-14h]
  void *pBufa; // [esp+10h] [ebp-14h]
  int i; // [esp+18h] [ebp-Ch]
  int v23; // [esp+1Ch] [ebp-8h] BYREF
  int nBytes; // [esp+20h] [ebp-4h] BYREF
  bf_write *bufa; // [esp+2Ch] [ebp+8h]
  bf_write *bufb; // [esp+2Ch] [ebp+8h]

  v3 = this;
  numTables = this->m_Tables.m_Size;
  bf_write::WriteByte(this: buf, val: numTables);
  i = 0;
  if ( numTables > 0 )
  {
    while ( 1 )
    {
      v4 = v3->m_Tables.m_Memory.m_pMemory[i];
      v5 = v4->GetTableName(this: v4);
      bf_write::WriteString(this: buf, pStr: v5);
      bufa = (bf_write *)v4->m_pItems->Count(this: v4->m_pItems);
      bf_write::WriteWord(this: buf, val: (unsigned int)bufa);
      for ( j = 0; j < (int)bufa; ++j )
      {
        v7 = v4->GetString(this: v4, a2: j);
        bf_write::WriteString(this: buf, pStr: v7);
        v8 = (int)v4->GetStringUserData(this: v4, a2: j, a3: &nBytes);
        m_iCurBit = buf->m_iCurBit;
        pBuf = (void *)v8;
        v10 = m_iCurBit + 1;
        if ( nBytes <= 0 )
        {
          if ( v10 <= buf->m_nDataBits )
          {
            if ( !buf->m_bOverflow )
            {
              buf->m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
              ++buf->m_iCurBit;
            }
          }
          else
          {
            buf->m_bOverflow = true;
          }
        }
        else
        {
          if ( v10 <= buf->m_nDataBits )
          {
            if ( !buf->m_bOverflow )
            {
              buf->m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
              ++buf->m_iCurBit;
            }
          }
          else
          {
            buf->m_bOverflow = true;
          }
          bf_write::WriteWord(this: buf, val: (__int16)nBytes);
          bf_write::WriteBytes(this: buf, pBuf, nBytes);
        }
      }
      v11 = buf->m_iCurBit;
      v12 = v11 + 1;
      if ( v4->m_pItemsClientSide != nullptr )
      {
        if ( v12 <= buf->m_nDataBits )
        {
          if ( !buf->m_bOverflow )
          {
            buf->m_pData[v11 >> 3] |= 1 << (v11 & 7);
            ++buf->m_iCurBit;
          }
        }
        else
        {
          buf->m_bOverflow = true;
        }
        bufb = (bf_write *)v4->m_pItemsClientSide->Count(this: v4->m_pItemsClientSide);
        bf_write::WriteWord(this: buf, val: (unsigned int)bufb);
        for ( k = nullptr; (int)k < (int)bufb; k = (int *)((char *)k + 1) )
        {
          v14 = (const char *)((int (__thiscall *)(INetworkStringDict_vtbl **))v4->m_pItemsClientSide->String)(a1: &v4->m_pItemsClientSide->__vftable);
          bf_write::WriteString(this: buf, pStr: v14);
          v15 = (CNetworkStringTableItem *)((int (__thiscall *)(INetworkStringDict_vtbl **, int *, int *))v4->m_pItemsClientSide->Element_2)(
                                             a1: &v4->m_pItemsClientSide->__vftable,
                                             a2: k,
                                             a3: &v23);
          UserData = (void *)CNetworkStringTableItem::GetUserData(this: v15, length: k);
          v17 = buf->m_iCurBit;
          pBufa = UserData;
          if ( v23 <= 0 )
          {
            if ( v17 + 1 <= buf->m_nDataBits )
            {
              if ( !buf->m_bOverflow )
              {
                buf->m_pData[v17 >> 3] &= ~(1 << (v17 & 7));
                ++buf->m_iCurBit;
              }
            }
            else
            {
              buf->m_bOverflow = true;
            }
          }
          else
          {
            if ( v17 + 1 <= buf->m_nDataBits )
            {
              if ( !buf->m_bOverflow )
              {
                buf->m_pData[v17 >> 3] |= 1 << (v17 & 7);
                ++buf->m_iCurBit;
              }
            }
            else
            {
              buf->m_bOverflow = true;
            }
            bf_write::WriteWord(this: buf, val: (__int16)v23);
            bf_write::WriteBytes(this: buf, pBuf: pBufa, nBytes: v23);
          }
        }
      }
      else if ( v12 <= buf->m_nDataBits )
      {
        if ( !buf->m_bOverflow )
        {
          buf->m_pData[v11 >> 3] &= ~(1 << (v11 & 7));
          ++buf->m_iCurBit;
        }
      }
      else
      {
        buf->m_bOverflow = true;
      }
      if ( ++i >= numTables )
        break;
      v3 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C3C80
// Name: public: void CNetworkStringTableContainer::Dump(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableContainer::Dump(CNetworkStringTableContainer *this)
{
  int i; // esi
  CNetworkStringTable *v3; // ecx

  for ( i = 0; i < this->m_Tables.m_Size; ++i )
  {
    v3 = this->m_Tables.m_Memory.m_pMemory[i];
    v3->Dump(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C40A0
// Name: public: virtual void CNetworkStringTableContainer::RemoveAllTables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableContainer::RemoveAllTables(CNetworkStringTableContainer *this)
{
  CNetworkStringTable *v2; // edi

  while ( this->m_Tables.m_Size > 0 )
  {
    v2 = *this->m_Tables.m_Memory.m_pMemory;
    if ( this->m_Tables.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_Tables.m_Memory.m_pMemory,
        src: this->m_Tables.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_Tables.m_Size - 1));
    --this->m_Tables.m_Size;
    if ( v2 != nullptr )
      ((void (__thiscall *)(CNetworkStringTable *, int))v2->dtr_INetworkStringTable)(a1: v2, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C40F0
// Name: public: virtual void CNetworkStringTableContainer::CreateDictionary(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableContainer::CreateDictionary(
        CNetworkStringTableContainer *this,
        const char *pchMapName)
{
  const char *v2; // esi
  CNetworkStringTableContainer *v3; // ebx
  int v4; // edi
  int v5; // eax
  CNetworkStringTable *v6; // esi
  int v7; // ebx
  const char *v8; // eax
  CMapReslistGenerator *v9; // eax
  bool IsCreatingForXbox; // bl
  char mapPath[260]; // [esp+8h] [ebp-13Ch] BYREF
  CUtlBuffer buf; // [esp+10Ch] [ebp-38h] BYREF
  CNetworkStringTableContainer *v13; // [esp+13Ch] [ebp-8h]
  int i; // [esp+140h] [ebp-4h]

  v2 = pchMapName;
  v3 = this;
  v13 = this;
  V_snprintf(pDest: mapPath, maxLen: 260, pFormat: "maps/%s.bsp", pchMapName);
  if ( g_pFileSystem->IsFileWritable(this: &g_pFileSystem->IBaseFileSystem, a2: mapPath, a3: "GAME") )
  {
    _Msg(a1: "Creating dictionary %s\n", pchMapName);
    v4 = 0;
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
    v5 = 0;
    i = 0;
    if ( v3->m_Tables.m_Size > 0 )
    {
      do
      {
        v6 = v3->m_Tables.m_Memory.m_pMemory[v5];
        if ( (v6->m_nFlags & 1) != 0 )
        {
          v7 = v6->GetNumStrings(this: v6);
          if ( v7 > 0 )
          {
            do
            {
              v8 = v6->GetString(this: v6, a2: v4);
              if ( *v8 != 0 )
                CUtlBuffer::PutString(this: &buf, pString: v8);
              ++v4;
            }
            while ( v4 < v7 );
          }
          v3 = v13;
          v4 = 0;
        }
        v5 = i + 1;
        i = v5;
      }
      while ( v5 < v3->m_Tables.m_Size );
      v2 = pchMapName;
    }
    v9 = MapReslistGenerator();
    IsCreatingForXbox = CMapReslistGenerator::IsCreatingForXbox(this: v9);
    g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_bActive = true;
    CUtlString::operator=(this: &g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_sBSPName, src: v2);
    g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_Buffer.m_Get = 0;
    g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_Buffer.m_Put = 0;
    g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_Buffer.m_nOffset = 0;
    g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_Buffer.m_nMaxPut = 0;
    g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_Buffer.m_Error = 0;
    if ( g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(
          this: _g_pMemAlloc,
          a2: g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_pMemory);
        g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_pMemory = nullptr;
      }
      g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_nAllocationCount = 0;
    }
    CUtlBuffer::Put(
      this: &g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_Buffer,
      pMem: buf.m_Memory.m_pMemory,
      size: buf.m_Put);
    g_StringTableDictionary.m_BuildStringTableDictionaryCache.m_bCreatingForX360 = IsCreatingForXbox;
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
  else
  {
    _Warning(a1: "#####################################################################################\n");
    _Warning(a1: "Can't recreate dictionary for %s, file must be writable!!!\n", mapPath);
    _Warning(a1: "#####################################################################################\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C4A30
// Name: public: CNetworkStringTableDictionaryManager::CStringTableDictionaryCache::CStringTableDictionaryCache(void)
// Source: json
//------------------------------------------------------------------------------
CNetworkStringTableDictionaryManager::CStringTableDictionaryCache *__thiscall CNetworkStringTableDictionaryManager::CStringTableDictionaryCache::CStringTableDictionaryCache(
        CNetworkStringTableDictionaryManager::CStringTableDictionaryCache *this)
{
  CUtlString::CUtlString(this: &this->m_sBSPName);
  CUtlBuffer::CUtlBuffer(this: &this->m_Buffer, growSize: 0, initSize: 0, nFlags: 0);
  this->m_bActive = false;
  CUtlString::operator=(this: &this->m_sBSPName, src: defaultValue);
  this->m_bCreatingForX360 = false;
  this->m_Buffer.m_Get = 0;
  this->m_Buffer.m_Put = 0;
  this->m_Buffer.m_nOffset = 0;
  this->m_Buffer.m_nMaxPut = 0;
  this->m_Buffer.m_Error = 0;
  if ( this->m_Buffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Buffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Buffer.m_Memory.m_pMemory);
      this->m_Buffer.m_Memory.m_pMemory = nullptr;
    }
    this->m_Buffer.m_Memory.m_nAllocationCount = 0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C4AA0
// Name: public: CNetworkStringTableContainer::CNetworkStringTableContainer(void)
// Source: json
//------------------------------------------------------------------------------
CNetworkStringTableContainer *__thiscall CNetworkStringTableContainer::CNetworkStringTableContainer(
        CNetworkStringTableContainer *this)
{
  this->__vftable = (CNetworkStringTableContainer_vtbl *)&CNetworkStringTableContainer::`vftable';
  this->m_Tables.m_Memory.m_pMemory = nullptr;
  this->m_Tables.m_Memory.m_nAllocationCount = 0;
  this->m_Tables.m_Memory.m_nGrowSize = 0;
  this->m_Tables.m_Size = 0;
  this->m_Tables.m_pElements = nullptr;
  this->m_bAllowCreation = false;
  this->m_nTickCount = 0;
  *(_WORD *)&this->m_bLocked = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C4AD0
// Name: public: virtual CNetworkStringTableContainer::~CNetworkStringTableContainer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableContainer::~CNetworkStringTableContainer(CNetworkStringTableContainer *this)
{
  this->__vftable = (CNetworkStringTableContainer_vtbl *)&CNetworkStringTableContainer::`vftable';
  CNetworkStringTableContainer::RemoveAllTables(this);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Tables);
  this->__vftable = (CNetworkStringTableContainer_vtbl *)&INetworkStringTableContainer::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x101C4AF0
// Name: public: int CNetworkStringTable::WriteUpdate(class CBaseClient __near *,class bf_write __near &,int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetworkStringTable::WriteUpdate(CNetworkStringTable *this, CBaseClient *client, int buf, int tick_ack)
{
  bool v5; // zf
  int v6; // eax
  int v8; // ecx
  int v9; // esi
  int v10; // edi
  char v11; // cl
  signed int v12; // edi
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  int v16; // edx
  int v17; // eax
  int v18; // edi
  int v19; // ecx
  int v20; // edx
  int v21; // ecx
  int v22; // edx
  unsigned __int8 *v23; // edx
  int v24; // esi
  unsigned int BestPreviousString; // eax
  int v26; // ecx
  int v27; // esi
  CNetworkStringTable *v28; // esi
  const void *v29; // edi
  int v30; // ecx
  int v31; // ecx
  int v32; // esi
  int m_Size; // edi
  int v34; // esi
  int v35; // edi
  StringHistoryEntry *v36; // edi
  CNetworkStringTable *v37; // edi
  int v38; // esi
  int v39; // eax
  const char *v40; // eax
  const char *v41; // eax
  int v43; // [esp-8h] [ebp-78h]
  int v44; // [esp-8h] [ebp-78h]
  const char *v45; // [esp-4h] [ebp-74h]
  const char *v46; // [esp-4h] [ebp-74h]
  int v47; // [esp-4h] [ebp-74h]
  StringHistoryEntry she; // [esp+Ch] [ebp-64h] BYREF
  CUtlVector<StringHistoryEntry,CUtlMemory<StringHistoryEntry,int> > history; // [esp+2Ch] [ebp-44h] BYREF
  int count; // [esp+40h] [ebp-30h]
  int nStartBit; // [esp+44h] [ebp-2Ch]
  int nDictionaryEncodeBits; // [esp+48h] [ebp-28h]
  CNetworkStringTableItem *p; // [esp+4Ch] [ebp-24h]
  int substringsize; // [esp+50h] [ebp-20h] BYREF
  int lastDictionaryIndex; // [esp+54h] [ebp-1Ch]
  int nDictionaryCount; // [esp+58h] [ebp-18h]
  int len; // [esp+5Ch] [ebp-14h] BYREF
  const char *pEntry; // [esp+60h] [ebp-10h]
  int entriesUpdated; // [esp+64h] [ebp-Ch]
  CNetworkStringTable *v60; // [esp+68h] [ebp-8h]
  bool bEncodeUsingDictionaries; // [esp+6Fh] [ebp-1h]
  int i; // [esp+7Ch] [ebp+Ch]

  v5 = (this->m_nFlags & 1) == 0;
  substringsize = -1;
  lastDictionaryIndex = -1;
  v60 = this;
  memset(&history, 0, sizeof(history));
  entriesUpdated = 0;
  nDictionaryEncodeBits = g_StringTableDictionary.m_nEncodeBits;
  if ( v5
    || stringtable_usedictionaries.m_pParent == nullptr
    || stringtable_usedictionaries.m_pParent->m_Value.m_nValue == 0
    || (bEncodeUsingDictionaries = true, g_StringTableDictionary.m_Strings.m_Size <= 0) )
  {
    bEncodeUsingDictionaries = false;
  }
  V_FileBase(in: com_gamedir, out: gamedir_8, maxlen: 260);
  if ( _V_stricmp(s1: gamedir_8, s2: "infested") == 0 )
    bEncodeUsingDictionaries = false;
  v6 = this->m_pItems->Count(this: this->m_pItems);
  v8 = *(_DWORD *)(buf + 12);
  v9 = v6;
  count = v6;
  nDictionaryCount = 0;
  if ( v8 + 1 > *(_DWORD *)(buf + 8) )
    *(_BYTE *)(buf + 16) = 1;
  if ( *(_BYTE *)(buf + 16) == 0 )
  {
    v10 = v8 >> 3;
    v11 = v8 & 7;
    if ( bEncodeUsingDictionaries )
      *(_BYTE *)(v10 + *(_DWORD *)buf) |= 1 << v11;
    else
      *(_BYTE *)(v10 + *(_DWORD *)buf) &= ~(1 << v11);
    ++*(_DWORD *)(buf + 12);
  }
  v12 = 0;
  i = 0;
  if ( v6 > 0 )
  {
    while ( 1 )
    {
      p = v60->m_pItems->Element_2(this: v60->m_pItems, a2: v12);
      if ( p->m_nTickChanged > tick_ack )
        break;
LABEL_95:
      v9 = count;
      v12 = i + 1;
      i = v12;
      if ( v12 >= count )
        goto LABEL_96;
    }
    v13 = *(_DWORD *)(buf + 12);
    nStartBit = v13;
    v14 = v13 + 1;
    if ( substringsize + 1 == v12 )
    {
      if ( v14 <= *(_DWORD *)(buf + 8) )
      {
        if ( *(_BYTE *)(buf + 16) == 0 )
        {
          *(_BYTE *)((v13 >> 3) + *(_DWORD *)buf) |= 1 << (v13 & 7);
          ++*(_DWORD *)(buf + 12);
        }
      }
      else
      {
        *(_BYTE *)(buf + 16) = 1;
      }
    }
    else
    {
      if ( v14 <= *(_DWORD *)(buf + 8) )
      {
        if ( *(_BYTE *)(buf + 16) == 0 )
        {
          *(_BYTE *)((v13 >> 3) + *(_DWORD *)buf) &= ~(1 << (v13 & 7));
          ++*(_DWORD *)(buf + 12);
        }
      }
      else
      {
        *(_BYTE *)(buf + 16) = 1;
      }
      bf_write::WriteUBitLong(this: (bf_write *)buf, curData: v12, numbits: v60->m_nEntryBits, bCheckRange: true);
    }
    pEntry = v60->m_pItems->String(this: v60->m_pItems, a2: v12);
    v15 = *(_DWORD *)(buf + 12);
    v16 = v15 + 1;
    if ( p->m_nTickCreated <= tick_ack )
    {
      if ( v16 <= *(_DWORD *)(buf + 8) )
      {
        if ( *(_BYTE *)(buf + 16) == 0 )
          *(_BYTE *)(((int)(*(_DWORD *)(buf + 12))++ >> 3) + *(_DWORD *)buf) &= ~(1 << (v15 & 7));
      }
      else
      {
        *(_BYTE *)(buf + 16) = 1;
      }
      goto LABEL_68;
    }
    if ( v16 <= *(_DWORD *)(buf + 8) )
    {
      if ( *(_BYTE *)(buf + 16) == 0 )
        *(_BYTE *)(((int)(*(_DWORD *)(buf + 12))++ >> 3) + *(_DWORD *)buf) |= 1 << (v15 & 7);
    }
    else
    {
      *(_BYTE *)(buf + 16) = 1;
    }
    v17 = v60->m_pItems->DictionaryIndex(this: v60->m_pItems, a2: v12);
    v18 = v17;
    if ( bEncodeUsingDictionaries )
    {
      v19 = *(_DWORD *)(buf + 12);
      v20 = v19 + 1;
      if ( v17 != -1 )
      {
        ++nDictionaryCount;
        if ( v20 <= *(_DWORD *)(buf + 8) )
        {
          if ( *(_BYTE *)(buf + 16) == 0 )
          {
            *(_BYTE *)((v19 >> 3) + *(_DWORD *)buf) |= 1 << (v19 & 7);
            ++*(_DWORD *)(buf + 12);
          }
        }
        else
        {
          *(_BYTE *)(buf + 16) = 1;
        }
        v21 = *(_DWORD *)(buf + 12);
        v22 = v21 + 1;
        if ( lastDictionaryIndex + 1 == v17 )
        {
          if ( v22 > *(_DWORD *)(buf + 8) )
          {
            *(_BYTE *)(buf + 16) = 1;
            lastDictionaryIndex = v17;
            goto LABEL_68;
          }
          if ( *(_BYTE *)(buf + 16) == 0 )
          {
            v23 = *(unsigned __int8 **)buf;
            v24 = *(int *)(buf + 12) >> 3;
            lastDictionaryIndex = v17;
            v23[v24] |= 1 << (v21 & 7);
            ++*(_DWORD *)(buf + 12);
            goto LABEL_68;
          }
        }
        else
        {
          if ( v22 <= *(_DWORD *)(buf + 8) )
          {
            if ( *(_BYTE *)(buf + 16) == 0 )
              *(_BYTE *)(((int)(*(_DWORD *)(buf + 12))++ >> 3) + *(_DWORD *)buf) &= ~(1 << (v21 & 7));
          }
          else
          {
            *(_BYTE *)(buf + 16) = 1;
          }
          bf_write::WriteUBitLong(
            this: (bf_write *)buf,
            curData: v17,
            numbits: nDictionaryEncodeBits,
            bCheckRange: true);
        }
        lastDictionaryIndex = v18;
LABEL_68:
        v28 = v60;
        v29 = v60->GetStringUserData(this: v60, a2: i, a3: &len);
        if ( v29 != nullptr && len > 0 )
        {
          v30 = *(_DWORD *)(buf + 12);
          if ( v30 + 1 <= *(_DWORD *)(buf + 8) )
          {
            if ( *(_BYTE *)(buf + 16) == 0 )
            {
              *(_BYTE *)(((int)(*(_DWORD *)(buf + 12))++ >> 3) + *(_DWORD *)buf) |= 1 << (v30 & 7);
              v28 = v60;
            }
          }
          else
          {
            *(_BYTE *)(buf + 16) = 1;
          }
          if ( (*((_BYTE *)v28 + 28) & 8) != 0 )
          {
            bf_write::WriteBits(this: (bf_write *)buf, pInData: v29, nBits: v28->m_nUserDataSizeBits);
          }
          else
          {
            bf_write::WriteUBitLong(this: (bf_write *)buf, curData: len, numbits: 14, bCheckRange: true);
            bf_write::WriteBits(this: (bf_write *)buf, pInData: v29, nBits: 8 * len);
          }
        }
        else
        {
          v31 = *(_DWORD *)(buf + 12);
          if ( v31 + 1 <= *(_DWORD *)(buf + 8) )
          {
            if ( *(_BYTE *)(buf + 16) == 0 )
              *(_BYTE *)(((int)(*(_DWORD *)(buf + 12))++ >> 3) + *(_DWORD *)buf) &= ~(1 << (v31 & 7));
          }
          else
          {
            *(_BYTE *)(buf + 16) = 1;
          }
        }
        if ( history.m_Size <= 31 )
        {
          m_Size = history.m_Size;
        }
        else
        {
          v32 = history.m_Size - 1;
          _V_memmove(dest: history.m_Memory.m_pMemory, src: &history.m_Memory.m_pMemory[1], count: 32 * v32);
          m_Size = v32;
          history.m_Size = v32;
        }
        V_strncpy(pDest: she.string, pSrc: pEntry, maxLen: 32);
        v34 = m_Size;
        if ( m_Size + 1 > history.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>::Grow(
            this: (CUtlMemory<vgui::RichText::TFormatStream,int> *)&history,
            num: m_Size - history.m_Memory.m_nAllocationCount + 1);
          m_Size = history.m_Size;
        }
        v35 = m_Size + 1;
        history.m_pElements = history.m_Memory.m_pMemory;
        history.m_Size = v35;
        if ( v35 - v34 - 1 > 0 )
          _V_memmove(
            dest: &history.m_Memory.m_pMemory[v34 + 1],
            src: &history.m_Memory.m_pMemory[v34],
            count: 32 * (v35 - v34 - 1));
        v36 = &history.m_Memory.m_pMemory[v34];
        if ( v36 != nullptr )
          *v36 = she;
        ++entriesUpdated;
        substringsize = i;
        if ( client != nullptr && CBaseClient::IsTracing(this: client) )
        {
          v37 = v60;
          v38 = *(_DWORD *)(buf + 12);
          v39 = (int)v60->GetString(this: v60, a2: i);
          v40 = (const char *)((int (__thiscall *)(CNetworkStringTable *, int, int))v37->GetTableName)(
                                a1: v37,
                                a2: i,
                                a3: v39);
          CBaseClient::TraceNetworkMsg(this: client, nBits: v38 - nStartBit, fmt: " [%s] %d:%s ", v40, v43, v46);
        }
        goto LABEL_95;
      }
      if ( v20 <= *(_DWORD *)(buf + 8) )
      {
        if ( *(_BYTE *)(buf + 16) == 0 )
          *(_BYTE *)(((int)(*(_DWORD *)(buf + 12))++ >> 3) + *(_DWORD *)buf) &= ~(1 << (v19 & 7));
      }
      else
      {
        *(_BYTE *)(buf + 16) = 1;
      }
    }
    substringsize = 0;
    BestPreviousString = GetBestPreviousString(newstring: pEntry, &substringsize);
    v26 = *(_DWORD *)(buf + 12);
    if ( BestPreviousString == -1 )
    {
      if ( v26 + 1 <= *(_DWORD *)(buf + 8) )
      {
        if ( *(_BYTE *)(buf + 16) == 0 )
          *(_BYTE *)(((int)(*(_DWORD *)(buf + 12))++ >> 3) + *(_DWORD *)buf) &= ~(1 << (v26 & 7));
        bf_write::WriteString(this: (bf_write *)buf, pStr: pEntry);
      }
      else
      {
        v45 = pEntry;
        *(_BYTE *)(buf + 16) = 1;
        bf_write::WriteString(this: (bf_write *)buf, pStr: v45);
      }
    }
    else
    {
      if ( v26 + 1 <= *(_DWORD *)(buf + 8) )
      {
        if ( *(_BYTE *)(buf + 16) == 0 )
          *(_BYTE *)(((int)(*(_DWORD *)(buf + 12))++ >> 3) + *(_DWORD *)buf) |= 1 << (v26 & 7);
      }
      else
      {
        *(_BYTE *)(buf + 16) = 1;
      }
      bf_write::WriteUBitLong(this: (bf_write *)buf, curData: BestPreviousString, numbits: 5, bCheckRange: true);
      v27 = substringsize;
      bf_write::WriteUBitLong(this: (bf_write *)buf, curData: substringsize, numbits: 5, bCheckRange: true);
      bf_write::WriteString(this: (bf_write *)buf, pStr: &pEntry[v27]);
    }
    goto LABEL_68;
  }
LABEL_96:
  if ( tick_ack == -1
    && v9 > 20
    && bEncodeUsingDictionaries
    && (float)((float)v9 * 0.89999998) > (float)nDictionaryCount )
  {
    v41 = (const char *)((int (__thiscall *)(CNetworkStringTable *, int, int))v60->GetTableName)(
                          a1: v60,
                          a2: nDictionaryCount,
                          a3: v9);
    _Warning(
      a1: "String Table dictionary for %s should be rebuilt, only found %d of %d strings in dictionary\n",
      v41,
      v44,
      v47);
  }
  if ( history.m_Memory.m_nGrowSize >= 0 && history.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: history.m_Memory.m_pMemory);
  return entriesUpdated;
}

//------------------------------------------------------------------------------
// Address: 0x101C50B0
// Name: public: void CNetworkStringTable::ParseUpdate(class bf_read __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CNetworkStringTable::ParseUpdate(
        CNetworkStringTable *this@<ecx>,
        unsigned __int8 *a2@<edi>,
        bf_read *buf,
        int entries)
{
  unsigned int m_nInBufWord; // ecx
  int v6; // eax
  bool v7; // zf
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int v10; // eax
  int v11; // edi
  int v12; // ecx
  const unsigned int *v13; // eax
  const unsigned int *v14; // edx
  CNetworkStringTable *v15; // esi
  int v16; // eax
  int v17; // ecx
  unsigned int v18; // edx
  unsigned int v19; // edi
  int v20; // ecx
  const unsigned int *v21; // eax
  const unsigned int *v22; // ecx
  const unsigned int *v23; // edx
  unsigned int v24; // edi
  const unsigned int *v25; // ecx
  unsigned int v26; // eax
  const char *v27; // eax
  unsigned int v28; // eax
  int v29; // ecx
  const unsigned int *v30; // eax
  const unsigned int *v31; // edx
  unsigned int v32; // eax
  int v33; // edx
  const unsigned int *v34; // eax
  const unsigned int *v35; // ecx
  unsigned int v36; // eax
  int v37; // edx
  const unsigned int *v38; // eax
  const unsigned int *v39; // ecx
  int v40; // edi
  int m_nBitsAvail; // ecx
  char v42; // dl
  unsigned int v43; // eax
  int v44; // ecx
  const unsigned int *v45; // eax
  const unsigned int *v46; // ecx
  unsigned int v47; // edi
  const unsigned int *v48; // edx
  int v49; // eax
  const unsigned int *v50; // ecx
  unsigned int v51; // edx
  unsigned int v52; // esi
  const char *v53; // eax
  unsigned int v54; // eax
  int v55; // edx
  const unsigned int *v56; // eax
  const unsigned int *v57; // ecx
  int v58; // ecx
  unsigned int v59; // eax
  unsigned int v60; // edi
  int v61; // ecx
  const unsigned int *v62; // eax
  const unsigned int *v63; // ecx
  const unsigned int *v64; // edx
  unsigned int v65; // edi
  int v66; // eax
  const unsigned int *v67; // ecx
  unsigned int v68; // edx
  unsigned int v69; // esi
  int v70; // ecx
  unsigned int v71; // eax
  int v72; // edx
  int v73; // ecx
  int v74; // eax
  const unsigned int *v75; // eax
  const unsigned int *v76; // ecx
  unsigned int v77; // ecx
  const unsigned int *v78; // edx
  unsigned int v79; // esi
  int v80; // eax
  const unsigned int *v81; // ecx
  unsigned int v82; // edx
  unsigned int v83; // edi
  int v84; // esi
  unsigned int v85; // edx
  unsigned int m_nUserDataSize; // esi
  unsigned int v87; // eax
  int v88; // ecx
  const unsigned int *v89; // eax
  const unsigned int *v90; // edx
  CNetworkStringTable *v91; // edi
  int v92; // ecx
  unsigned int v93; // eax
  int v94; // ecx
  unsigned int v95; // edx
  const unsigned int *v96; // eax
  const unsigned int *v97; // ecx
  const unsigned int *v98; // edx
  unsigned int v99; // esi
  int v100; // eax
  const unsigned int *v101; // ecx
  unsigned int v102; // edx
  unsigned int v103; // edi
  int v104; // eax
  const char *v105; // eax
  int v106; // edi
  int v107; // esi
  int v108; // edi
  vgui::RichText::TFormatStream *v109; // edi
  int m_nUserDataSizeBits; // [esp-8h] [ebp-4864h]
  int v112; // [esp-4h] [ebp-4860h]
  unsigned __int8 dst[16384]; // [esp+8h] [ebp-4854h] BYREF
  char pStr[1024]; // [esp+4008h] [ebp-854h] BYREF
  char pDest[1024]; // [esp+4408h] [ebp-454h] BYREF
  char v117[32]; // [esp+4808h] [ebp-54h] BYREF
  int m_nEncodeBits; // [esp+4828h] [ebp-34h]
  int v119; // [esp+482Ch] [ebp-30h]
  int v120; // [esp+4830h] [ebp-2Ch]
  CUtlMemory<vgui::RichText::TFormatStream,int> dest; // [esp+4834h] [ebp-28h] BYREF
  int v122; // [esp+4840h] [ebp-1Ch]
  vgui::RichText::TFormatStream *m_pMemory; // [esp+4844h] [ebp-18h]
  int v124; // [esp+4848h] [ebp-14h]
  unsigned __int8 *v125; // [esp+484Ch] [ebp-10h]
  int v126; // [esp+4850h] [ebp-Ch]
  CNetworkStringTable *v127; // [esp+4854h] [ebp-8h]
  char *pSrc; // [esp+4858h] [ebp-4h]
  bool v129; // [esp+4867h] [ebp+Bh]

  v127 = this;
  m_nInBufWord = buf->m_nInBufWord;
  m_nEncodeBits = g_StringTableDictionary.m_nEncodeBits;
  v6 = m_nInBufWord & 1;
  v7 = buf->m_nBitsAvail-- == 1;
  v119 = -1;
  v124 = -1;
  if ( v7 )
  {
    m_pDataIn = buf->m_pDataIn;
    m_pBufferEnd = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = m_pDataIn + 1;
    }
    else if ( m_pDataIn <= m_pBufferEnd )
    {
      buf->m_nInBufWord = *m_pDataIn;
      buf->m_pDataIn = m_pDataIn + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = m_nInBufWord >> 1;
  }
  v129 = v6 != 0;
  memset(&dest, 0, sizeof(dest));
  v122 = 0;
  m_pMemory = nullptr;
  v120 = 0;
  if ( entries > 0 )
  {
    while ( 1 )
    {
      v10 = buf->m_nInBufWord;
      v11 = v119 + 1;
      v12 = v10 & 1;
      v7 = buf->m_nBitsAvail-- == 1;
      v126 = v11;
      if ( v7 )
      {
        v13 = buf->m_pDataIn;
        v14 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v13 == v14 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v13 + 1;
        }
        else if ( v13 <= v14 )
        {
          buf->m_nInBufWord = *v13;
          buf->m_pDataIn = v13 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
      }
      else
      {
        buf->m_nInBufWord = v10 >> 1;
      }
      v15 = v127;
      if ( v12 == 0 )
        break;
LABEL_36:
      v119 = v11;
      if ( v11 < 0 || v11 >= v15->GetMaxStrings(this: v15) )
      {
        v27 = v15->GetTableName(this: v15);
        Host_Error(error: "Server sent bogus string index %i for table %s\n", v11, v27);
      }
      v28 = buf->m_nInBufWord;
      v29 = v28 & 1;
      v7 = buf->m_nBitsAvail-- == 1;
      pSrc = nullptr;
      if ( v7 )
      {
        v30 = buf->m_pDataIn;
        v31 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v30 == v31 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v30 + 1;
        }
        else if ( v30 <= v31 )
        {
          buf->m_nInBufWord = *v30;
          buf->m_pDataIn = v30 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
      }
      else
      {
        buf->m_nInBufWord = v28 >> 1;
      }
      if ( v29 != 0 )
      {
        if ( v129 )
        {
          v32 = buf->m_nInBufWord;
          v33 = v32 & 1;
          v7 = buf->m_nBitsAvail-- == 1;
          if ( v7 )
          {
            v34 = buf->m_pDataIn;
            v35 = buf->m_pBufferEnd;
            buf->m_nBitsAvail = 32;
            if ( v34 == v35 )
            {
              buf->m_nBitsAvail = 1;
              buf->m_nInBufWord = 0;
              buf->m_pDataIn = v34 + 1;
            }
            else if ( v34 <= v35 )
            {
              buf->m_nInBufWord = *v34;
              buf->m_pDataIn = v34 + 1;
            }
            else
            {
              buf->m_bOverflow = true;
              buf->m_nInBufWord = 0;
            }
          }
          else
          {
            buf->m_nInBufWord = v32 >> 1;
          }
          if ( v33 != 0 )
          {
            v36 = buf->m_nInBufWord;
            v37 = v36 & 1;
            v7 = buf->m_nBitsAvail-- == 1;
            if ( v7 )
            {
              v38 = buf->m_pDataIn;
              v39 = buf->m_pBufferEnd;
              buf->m_nBitsAvail = 32;
              if ( v38 == v39 )
              {
                buf->m_nBitsAvail = 1;
                buf->m_nInBufWord = 0;
                buf->m_pDataIn = v38 + 1;
              }
              else if ( v38 <= v39 )
              {
                buf->m_nInBufWord = *v38;
                buf->m_pDataIn = v38 + 1;
              }
              else
              {
                buf->m_bOverflow = true;
                buf->m_nInBufWord = 0;
              }
            }
            else
            {
              buf->m_nInBufWord = v36 >> 1;
            }
            if ( v37 != 0 )
            {
              v40 = v124 + 1;
              goto LABEL_82;
            }
            m_nBitsAvail = buf->m_nBitsAvail;
            v42 = m_nEncodeBits;
            if ( m_nBitsAvail >= m_nEncodeBits )
            {
              v43 = buf->m_nInBufWord;
              v40 = v43 & CBitBuffer::s_nMaskTable[m_nEncodeBits];
              v44 = m_nBitsAvail - m_nEncodeBits;
              buf->m_nBitsAvail = v44;
              if ( v44 != 0 )
              {
                buf->m_nInBufWord = v43 >> v42;
              }
              else
              {
                v45 = buf->m_pDataIn;
                v46 = buf->m_pBufferEnd;
                buf->m_nBitsAvail = 32;
                if ( v45 == v46 )
                {
                  buf->m_nBitsAvail = 1;
                  buf->m_nInBufWord = 0;
                  buf->m_pDataIn = v45 + 1;
                }
                else if ( v45 <= v46 )
                {
                  buf->m_nInBufWord = *v45;
                  buf->m_pDataIn = v45 + 1;
                }
                else
                {
                  buf->m_bOverflow = true;
                  buf->m_nInBufWord = 0;
                }
              }
              goto LABEL_82;
            }
            v47 = buf->m_nInBufWord;
            v48 = buf->m_pBufferEnd;
            v49 = m_nEncodeBits - m_nBitsAvail;
            v50 = buf->m_pDataIn;
            if ( v50 == v48 )
            {
              buf->m_nBitsAvail = 1;
              buf->m_nInBufWord = 0;
              buf->m_bOverflow = true;
              goto LABEL_78;
            }
            if ( v50 <= v48 )
            {
              buf->m_nInBufWord = *v50;
LABEL_78:
              buf->m_pDataIn = v50 + 1;
            }
            else
            {
              buf->m_bOverflow = true;
              buf->m_nInBufWord = 0;
            }
            if ( buf->m_bOverflow )
            {
              v40 = 0;
            }
            else
            {
              v51 = buf->m_nInBufWord;
              v52 = (v51 & CBitBuffer::s_nMaskTable[v49]) << buf->m_nBitsAvail;
              buf->m_nBitsAvail = 32 - v49;
              v40 = v52 | v47;
              buf->m_nInBufWord = v51 >> v49;
            }
LABEL_82:
            v124 = v40;
            if ( v40 < 0 || v40 >= g_StringTableDictionary.m_Strings.m_Size )
              v53 = defaultValue;
            else
              v53 = CUtlString::operator char const *(this: &g_StringTableDictionary.m_Strings.m_Memory.m_pMemory[v40]);
            V_strncpy(pDest, pSrc: v53, maxLen: 1024);
LABEL_132:
            pSrc = pDest;
            goto LABEL_133;
          }
        }
        v54 = buf->m_nInBufWord;
        v55 = v54 & 1;
        v7 = buf->m_nBitsAvail-- == 1;
        if ( v7 )
        {
          v56 = buf->m_pDataIn;
          v57 = buf->m_pBufferEnd;
          buf->m_nBitsAvail = 32;
          if ( v56 == v57 )
          {
            buf->m_nBitsAvail = 1;
            buf->m_nInBufWord = 0;
            buf->m_pDataIn = v56 + 1;
          }
          else if ( v56 <= v57 )
          {
            buf->m_nInBufWord = *v56;
            buf->m_pDataIn = v56 + 1;
          }
          else
          {
            buf->m_bOverflow = true;
            buf->m_nInBufWord = 0;
          }
        }
        else
        {
          buf->m_nInBufWord = v54 >> 1;
        }
        if ( v55 == 0 )
        {
          CBitRead::ReadString(this: buf, pStr: pDest, maxLen: 1024, bLine: false, pOutNumChars: nullptr);
          goto LABEL_132;
        }
        v58 = buf->m_nBitsAvail;
        if ( v58 >= 5 )
        {
          v59 = buf->m_nInBufWord;
          v60 = v59 & 0x1F;
          v61 = v58 - 5;
          buf->m_nBitsAvail = v61;
          if ( v61 != 0 )
          {
            buf->m_nInBufWord = v59 >> 5;
          }
          else
          {
            v62 = buf->m_pDataIn;
            v63 = buf->m_pBufferEnd;
            buf->m_nBitsAvail = 32;
            if ( v62 == v63 )
            {
              buf->m_nBitsAvail = 1;
              buf->m_nInBufWord = 0;
              buf->m_pDataIn = v62 + 1;
            }
            else if ( v62 <= v63 )
            {
              buf->m_nInBufWord = *v62;
              buf->m_pDataIn = v62 + 1;
            }
            else
            {
              buf->m_bOverflow = true;
              buf->m_nInBufWord = 0;
            }
          }
          goto LABEL_112;
        }
        v64 = buf->m_pBufferEnd;
        v65 = buf->m_nInBufWord;
        v66 = 5 - v58;
        v67 = buf->m_pDataIn;
        if ( v67 == v64 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_bOverflow = true;
          goto LABEL_108;
        }
        if ( v67 <= v64 )
        {
          buf->m_nInBufWord = *v67;
LABEL_108:
          buf->m_pDataIn = v67 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
        if ( buf->m_bOverflow )
        {
          v60 = 0;
        }
        else
        {
          v68 = buf->m_nInBufWord;
          v69 = (v68 & CBitBuffer::s_nMaskTable[v66]) << buf->m_nBitsAvail;
          buf->m_nBitsAvail = 32 - v66;
          v60 = v69 | v65;
          buf->m_nInBufWord = v68 >> v66;
        }
LABEL_112:
        v70 = buf->m_nBitsAvail;
        pSrc = (char *)v60;
        if ( v70 >= 5 )
        {
          v71 = buf->m_nInBufWord;
          v72 = v71 & 0x1F;
          v73 = v70 - 5;
          buf->m_nBitsAvail = v73;
          if ( v73 != 0 )
          {
            buf->m_nInBufWord = v71 >> 5;
            v74 = v71 & 0x1F;
          }
          else
          {
            v75 = buf->m_pDataIn;
            v76 = buf->m_pBufferEnd;
            buf->m_nBitsAvail = 32;
            if ( v75 == v76 )
            {
              buf->m_pDataIn = v75 + 1;
              buf->m_nBitsAvail = 1;
              buf->m_nInBufWord = 0;
              v74 = v72;
            }
            else
            {
              if ( v75 <= v76 )
              {
                v77 = *v75;
                buf->m_pDataIn = v75 + 1;
                buf->m_nInBufWord = v77;
              }
              else
              {
                buf->m_bOverflow = true;
                buf->m_nInBufWord = 0;
              }
              v74 = v72;
            }
          }
          goto LABEL_130;
        }
        v78 = buf->m_pBufferEnd;
        v79 = buf->m_nInBufWord;
        v80 = 5 - v70;
        v81 = buf->m_pDataIn;
        if ( v81 == v78 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_bOverflow = true;
          goto LABEL_126;
        }
        if ( v81 <= v78 )
        {
          buf->m_nInBufWord = *v81;
LABEL_126:
          buf->m_pDataIn = v81 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
        if ( buf->m_bOverflow )
        {
          v74 = 0;
        }
        else
        {
          v82 = buf->m_nInBufWord;
          v83 = (v82 & CBitBuffer::s_nMaskTable[v80]) << buf->m_nBitsAvail;
          buf->m_nBitsAvail = 32 - v80;
          v84 = v83 | v79;
          v60 = (unsigned int)pSrc;
          v85 = v82 >> v80;
          v74 = v84;
          buf->m_nInBufWord = v85;
        }
LABEL_130:
        V_strncpy(pDest, pSrc: (const char *)&dest.m_pMemory[v60], maxLen: v74 + 1);
        CBitRead::ReadString(this: buf, pStr, maxLen: 1024, bLine: false, pOutNumChars: nullptr);
        V_strncat(pDest, pSrc: pStr, destBufferSize: 0x400u, max_chars_to_copy: -1);
        goto LABEL_132;
      }
LABEL_133:
      m_nUserDataSize = 0;
      memset(dst, value: 0, count: sizeof(dst));
      v87 = buf->m_nInBufWord;
      v88 = v87 & 1;
      v7 = buf->m_nBitsAvail-- == 1;
      v125 = nullptr;
      if ( v7 )
      {
        v89 = buf->m_pDataIn;
        v90 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v89 == v90 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v89 + 1;
        }
        else if ( v89 <= v90 )
        {
          buf->m_nInBufWord = *v89;
          buf->m_pDataIn = v89 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
      }
      else
      {
        buf->m_nInBufWord = v87 >> 1;
      }
      v91 = v127;
      if ( v88 == 0 )
        goto LABEL_165;
      if ( (*((_BYTE *)v127 + 28) & 8) == 0 )
      {
        v92 = buf->m_nBitsAvail;
        if ( v92 >= 14 )
        {
          v93 = buf->m_nInBufWord;
          m_nUserDataSize = v93 & 0x3FFF;
          v94 = v92 - 14;
          v95 = 0;
          buf->m_nBitsAvail = v94;
          if ( v94 != 0 )
          {
            buf->m_nInBufWord = v93 >> 14;
LABEL_161:
            if ( m_nUserDataSize > 0x4000 )
            {
              _Error(a1: "CNetworkStringTableClient::ParseUpdate: message too large (%d bytes).", m_nUserDataSize);
              v91 = v127;
            }
            CBitRead::ReadBytes(this: buf, pOut: dst, nBytes: m_nUserDataSize);
            goto LABEL_164;
          }
          v96 = buf->m_pDataIn;
          v97 = buf->m_pBufferEnd;
          buf->m_nBitsAvail = 32;
          if ( v96 == v97 )
          {
            buf->m_nBitsAvail = 1;
            buf->m_pDataIn = v96 + 1;
          }
          else if ( v96 <= v97 )
          {
            v95 = *v96;
            buf->m_pDataIn = v96 + 1;
          }
          else
          {
            buf->m_bOverflow = true;
          }
          goto LABEL_160;
        }
        v98 = buf->m_pBufferEnd;
        v99 = buf->m_nInBufWord;
        v100 = 14 - v92;
        v101 = buf->m_pDataIn;
        if ( v101 == v98 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_bOverflow = true;
          goto LABEL_156;
        }
        if ( v101 <= v98 )
        {
          buf->m_nInBufWord = *v101;
LABEL_156:
          buf->m_pDataIn = v101 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
        if ( buf->m_bOverflow )
        {
          m_nUserDataSize = 0;
          goto LABEL_161;
        }
        v102 = buf->m_nInBufWord;
        v103 = (v102 & CBitBuffer::s_nMaskTable[v100]) << buf->m_nBitsAvail;
        buf->m_nBitsAvail = 32 - v100;
        m_nUserDataSize = v103 | v99;
        v91 = v127;
        v95 = v102 >> v100;
LABEL_160:
        buf->m_nInBufWord = v95;
        goto LABEL_161;
      }
      m_nUserDataSize = v127->m_nUserDataSize;
      m_nUserDataSizeBits = v127->m_nUserDataSizeBits;
      dst[m_nUserDataSize - 1] = 0;
      CBitRead::ReadBits(this: buf, pOutData: dst, nBits: m_nUserDataSizeBits);
LABEL_164:
      v125 = dst;
LABEL_165:
      v104 = ((int (__thiscall *)(CNetworkStringTable *, unsigned __int8 *))v91->GetNumStrings)(a1: v91, a2);
      if ( v126 >= v104 )
      {
        if ( pSrc == nullptr )
        {
          v105 = (const char *)((int (__thiscall *)(CNetworkStringTable *, int))v91->GetTableName)(a1: v91, a2: v126);
          _Msg(a1: "CNetworkStringTable::ParseUpdate: NULL pEntry, table %s, index %i\n", v105, v112);
          pSrc = (char *)defaultValue;
        }
        a2 = v125;
        ((void (__thiscall *)(CNetworkStringTable *, int, char *, unsigned int))v91->AddString)(
          a1: v91,
          a2: 1,
          a3: pSrc,
          a4: m_nUserDataSize);
      }
      else
      {
        a2 = v125;
        ((void (__thiscall *)(CNetworkStringTable *, int, unsigned int))v91->SetStringUserData)(
          a1: v91,
          a2: v126,
          a3: m_nUserDataSize);
        pSrc = (char *)v91->GetString(this: v91, a2: v126);
      }
      v106 = v122;
      if ( v122 > 31 )
      {
        v106 = v122 - 1;
        _V_memmove(dest: dest.m_pMemory, src: &dest.m_pMemory[1], count: 32 * (v122 - 1));
        v122 = v106;
      }
      V_strncpy(pDest: v117, pSrc, maxLen: 32);
      v107 = v106;
      if ( v106 + 1 > dest.m_nAllocationCount )
      {
        CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>::Grow(this: &dest, num: v106 - dest.m_nAllocationCount + 1);
        v106 = v122;
      }
      v108 = v106 + 1;
      v122 = v108;
      m_pMemory = dest.m_pMemory;
      if ( v108 - v107 - 1 > 0 )
        _V_memmove(dest: &dest.m_pMemory[v107 + 1], src: &dest.m_pMemory[v107], count: 32 * (v108 - v107 - 1));
      v109 = &dest.m_pMemory[v107];
      if ( v109 != nullptr )
        qmemcpy(v109, v117, sizeof(vgui::RichText::TFormatStream));
      if ( ++v120 >= entries )
        goto LABEL_179;
    }
    v16 = v127->GetEntryBits(this: v127);
    v17 = buf->m_nBitsAvail;
    if ( v17 >= v16 )
    {
      v18 = buf->m_nInBufWord;
      v19 = v18 & CBitBuffer::s_nMaskTable[v16];
      v20 = v17 - v16;
      buf->m_nBitsAvail = v20;
      if ( v20 == 0 )
      {
        v21 = buf->m_pDataIn;
        v22 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v21 == v22 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v21 + 1;
        }
        else if ( v21 <= v22 )
        {
          buf->m_nInBufWord = *v21;
          buf->m_pDataIn = v21 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
        goto LABEL_34;
      }
LABEL_33:
      buf->m_nInBufWord = v18 >> v16;
LABEL_34:
      v26 = v19;
      goto LABEL_35;
    }
    v23 = buf->m_pBufferEnd;
    v24 = buf->m_nInBufWord;
    v16 -= v17;
    v25 = buf->m_pDataIn;
    if ( v25 == v23 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v25 > v23 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
LABEL_30:
        if ( buf->m_bOverflow )
        {
          v26 = 0;
LABEL_35:
          v11 = v26;
          v126 = v26;
          goto LABEL_36;
        }
        v18 = buf->m_nInBufWord;
        v19 = ((v18 & CBitBuffer::s_nMaskTable[v16]) << buf->m_nBitsAvail) | v24;
        v15 = v127;
        buf->m_nBitsAvail = 32 - v16;
        goto LABEL_33;
      }
      buf->m_nInBufWord = *v25;
    }
    buf->m_pDataIn = v25 + 1;
    goto LABEL_30;
  }
LABEL_179:
  if ( dest.m_nGrowSize >= 0 && dest.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dest.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101C5A70
// Name: public: void CNetworkStringTableContainer::WriteBaselines(char const __near *,class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableContainer::WriteBaselines(
        CNetworkStringTableContainer *this,
        signed int pchMapName,
        bf_write *buf)
{
  CNetworkStringTableContainer *v3; // esi
  signed int v4; // edi
  char *v5; // eax
  bool v6; // cc
  char *v7; // edi
  CNetworkStringTable *v8; // esi
  int v9; // ebx
  int v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  int v13; // edi
  char *v14; // ecx
  const char *v15; // eax
  const char *v16; // eax
  bf_write *v17; // edi
  const char *v18; // eax
  int m_iCurBit; // ecx
  int v20; // edi
  const char *v21; // eax
  int v22; // [esp-Ch] [ebp-194h]
  int v23; // [esp-8h] [ebp-190h]
  int v24; // [esp-8h] [ebp-190h]
  int v25; // [esp-8h] [ebp-190h]
  SVC_CreateStringTable msg; // [esp+8h] [ebp-180h] BYREF
  CNetworkStringTableContainer *v27; // [esp+178h] [ebp-10h]
  char *compressedData; // [esp+17Ch] [ebp-Ch]
  char *msg_buffer; // [esp+180h] [ebp-8h]
  int i; // [esp+184h] [ebp-4h]

  v3 = this;
  v27 = this;
  if ( stringtable_usedictionaries.m_pParent != nullptr && stringtable_usedictionaries.m_pParent->m_Value.m_nValue != 0 )
  {
    v4 = pchMapName;
    if ( CNetworkStringTableDictionaryManager::ShouldRecreateDictionary(
           this: &g_StringTableDictionary,
           (const char *)pchMapName) != 0 )
      v3->CreateDictionary(this: v3, a2: (const char *)v4);
  }
  SVC_CreateStringTable::SVC_CreateStringTable(this: &msg);
  v5 = (char *)MemAlloc_Alloc(nSize: 0x2EE00u);
  v6 = v3->m_Tables.m_Size <= 0;
  v7 = v5;
  msg_buffer = v5;
  i = 0;
  if ( !v6 )
  {
    while ( 1 )
    {
      v8 = (CNetworkStringTable *)v3->GetTable(this: v3, a2: i);
      v9 = (buf->m_iCurBit + 7) >> 3;
      bf_write::StartWriting(this: &msg.m_DataOut, pData: v7, nBytes: 192000, iStartBit: 0, nBits: -1);
      msg.m_nFlags = v8->m_nFlags;
      msg.m_szTableName = v8->GetTableName(this: v8);
      msg.m_nMaxEntries = v8->GetMaxStrings(this: v8);
      msg.m_nNumEntries = v8->GetNumStrings(this: v8);
      msg.m_bUserDataFixedSize = (*((_BYTE *)v8 + 28) & 8) != 0;
      msg.m_nUserDataSize = v8->m_nUserDataSize;
      msg.m_nUserDataSizeBits = v8->m_nUserDataSizeBits;
      v10 = CNetworkStringTable::WriteUpdate(this: v8, client: nullptr, buf: (int)&msg.m_DataOut, tick_ack: -1);
      if ( v10 != msg.m_nNumEntries )
      {
        free(pMem: v7);
        v11 = v8->GetTableName(this: v8);
        Host_Error(error: "Index error writing string table baseline %s\n", v11);
      }
      if ( msg.m_DataOut.m_bOverflow )
      {
        v12 = v8->GetTableName(this: v8);
        _Warning(a1: "Warning:  Overflowed writing uncompressed string table data for %s\n", v12);
      }
      v13 = (msg.m_DataOut.m_iCurBit + 7) >> 3;
      pchMapName = v13;
      v14 = (char *)MemAlloc_Alloc(nSize: v13);
      compressedData = v14;
      if ( stringtable_compress.m_pParent != nullptr
        && stringtable_compress.m_pParent->m_Value.m_nValue != 0
        && NET_BufferToBufferCompress(
             dest: v14,
             destLen: (unsigned int *)&pchMapName,
             source: (char *)msg.m_DataOut.m_pData,
             sourceLen: v13) != 0 )
      {
        msg.m_bDataCompressed = true;
        bf_write::Reset(this: &msg.m_DataOut);
        bf_write::WriteLong(this: &msg.m_DataOut, val: v13);
        bf_write::WriteLong(this: &msg.m_DataOut, val: pchMapName);
        bf_write::WriteBits(this: &msg.m_DataOut, pInData: compressedData, nBits: 8 * pchMapName);
        if ( stringtable_showsizes.m_pParent != nullptr && stringtable_showsizes.m_pParent->m_Value.m_nValue != 0 )
        {
          v15 = (const char *)((int (__thiscall *)(CNetworkStringTable *, int, signed int))v8->GetTableName)(
                                a1: v8,
                                a2: v13,
                                a3: pchMapName);
          _Msg(a1: "Stringtable %s compression: %d -> %d bytes\n", v15, v22, v23);
        }
      }
      else
      {
        msg.m_bDataCompressed = false;
        if ( stringtable_showsizes.m_pParent != nullptr && stringtable_showsizes.m_pParent->m_Value.m_nValue != 0 )
        {
          v16 = (const char *)((int (__thiscall *)(CNetworkStringTable *, int))v8->GetTableName)(a1: v8, a2: v13);
          _Msg(a1: "Stringtable %s written %d bytes\n", v16, v24);
        }
      }
      free(pMem: compressedData);
      v17 = buf;
      if ( !SVC_CreateStringTable::WriteToBuffer(this: &msg, buffer: buf) )
      {
        free(pMem: msg_buffer);
        v18 = v8->GetTableName(this: v8);
        Host_Error(error: "Overflow error writing string table baseline %s\n", v18);
      }
      m_iCurBit = v17->m_iCurBit;
      v20 = (m_iCurBit + 7) >> 3;
      if ( sv_dumpstringtables.m_pParent != nullptr && sv_dumpstringtables.m_pParent->m_Value.m_nValue != 0 )
      {
        v21 = (const char *)((int (__thiscall *)(CNetworkStringTable *, int))v8->GetTableName)(
                              a1: v8,
                              a2: (buf->m_nDataBits - m_iCurBit) >> 3);
        DevMsg(
          a1: "CNetworkStringTableContainer::WriteBaselines wrote %d bytes for table %s [space remaining %d bytes]\n",
          v20 - v9,
          v21,
          v25);
      }
      v7 = msg_buffer;
      if ( ++i >= v27->m_Tables.m_Size )
        break;
      v3 = v27;
    }
  }
  free(pMem: v7);
}

//------------------------------------------------------------------------------
// Address: 0x101C5D60
// Name: public: void CNetworkStringTableContainer::WriteUpdateMessage(class CBaseClient __near *,int,class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableContainer::WriteUpdateMessage(
        CNetworkStringTableContainer *this,
        CBaseClient *client,
        int tick_ack,
        bf_write *buf)
{
  CNetworkStringTableContainer *v4; // esi
  CNetworkStringTable *v5; // esi
  const char *v6; // eax
  _BYTE pData[96000]; // [esp+8h] [ebp-17760h] BYREF
  SVC_UpdateStringTable v8; // [esp+17708h] [ebp-60h] BYREF
  CNetworkStringTableContainer *v9; // [esp+17760h] [ebp-8h]
  int v10; // [esp+17764h] [ebp-4h]

  v4 = this;
  v9 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CNetworkStringTableContainer::WriteUpdateMessage",
    a3: 0,
    a4: "Networking",
    a5: false,
    a6: 4);
  v10 = 0;
  if ( v4->m_Tables.m_Size > 0 )
  {
    while ( 1 )
    {
      v5 = (CNetworkStringTable *)v4->GetTable(this: v4, a2: v10);
      if ( v5 != nullptr && v5->ChangedSinceTick(this: v5, a2: tick_ack) )
      {
        v8.m_bReliable = true;
        v8.m_NetChannel = nullptr;
        v8.__vftable = (SVC_UpdateStringTable_vtbl *)&SVC_UpdateStringTable::`vftable';
        v8.m_DataIn.m_bOverflow = false;
        v8.m_DataIn.m_pDebugName = nullptr;
        v8.m_DataIn.m_nDataBits = -1;
        v8.m_DataIn.m_nDataBytes = 0;
        bf_write::bf_write(this: &v8.m_DataOut);
        bf_write::StartWriting(this: &v8.m_DataOut, pData, nBytes: 96000, iStartBit: 0, nBits: -1);
        v8.m_nTableID = v5->GetTableId(this: v5);
        v8.m_nChangedEntries = CNetworkStringTable::WriteUpdate(this: v5, client, buf: (int)&v8.m_DataOut, tick_ack);
        SVC_UpdateStringTable::WriteToBuffer(this: &v8, buffer: buf);
        if ( client != nullptr && CBaseClient::IsTracing(this: client) )
        {
          v6 = v5->GetTableName(this: v5);
          CBaseClient::TraceNetworkData(this: client, msg: buf, fmt: "StringTable %s", v6);
        }
      }
      if ( ++v10 >= v9->m_Tables.m_Size )
        break;
      v4 = v9;
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x101C6020
// Name: private: void CNetworkStringTableDictionaryManager::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableDictionaryManager::Clear(CNetworkStringTableDictionaryManager *this)
{
  CUtlRBTree<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_StringHashToIndex.m_Tree);
  this->m_StringHashToIndex.m_Tree.m_FirstFree = -1;
  if ( this->m_StringHashToIndex.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_StringHashToIndex.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_StringHashToIndex.m_Tree.m_Elements.m_pMemory);
      this->m_StringHashToIndex.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_StringHashToIndex.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  this->m_StringHashToIndex.m_Tree.m_LastAlloc.index = -1;
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&this->m_Strings);
  if ( this->m_Strings.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Strings.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Strings.m_Memory.m_pMemory);
      this->m_Strings.m_Memory.m_pMemory = nullptr;
    }
    this->m_Strings.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Strings.m_pElements = this->m_Strings.m_Memory.m_pMemory;
  this->m_CRC = 0;
  this->m_nEncodeBits = 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C6120
// Name: public: CNetworkStringTableDictionaryManager::~CNetworkStringTableDictionaryManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableDictionaryManager::~CNetworkStringTableDictionaryManager(
        CNetworkStringTableDictionaryManager *this)
{
  if ( this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_pMemory);
      this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_pMemory = nullptr;
    }
    this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_nAllocationCount = 0;
  }
  this->m_BuildStringTableDictionaryCache.m_sBSPName.m_Storage.m_nActualLength = 0;
  if ( this->m_BuildStringTableDictionaryCache.m_sBSPName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_BuildStringTableDictionaryCache.m_sBSPName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: this->m_BuildStringTableDictionaryCache.m_sBSPName.m_Storage.m_Memory.m_pMemory);
      this->m_BuildStringTableDictionaryCache.m_sBSPName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_BuildStringTableDictionaryCache.m_sBSPName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlRBTree<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_StringHashToIndex.m_Tree);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&this->m_Strings);
  this->m_sCurrentMap.m_Storage.m_nActualLength = 0;
  if ( this->m_sCurrentMap.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_sCurrentMap.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_sCurrentMap.m_Storage.m_Memory.m_pMemory);
      this->m_sCurrentMap.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_sCurrentMap.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C61B0
// Name: public: void CNetworkStringTableDictionaryManager::ProcessBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableDictionaryManager::ProcessBuffer(
        CNetworkStringTableDictionaryManager *this,
        CUtlBuffer *buf)
{
  CNetworkStringTableDictionaryManager *v2; // ebx
  CUtlBuffer *v3; // esi
  int m_nMaxPut; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v8; // eax
  CUtlString *v9; // ecx
  const char *v10; // eax
  unsigned __int16 v11; // ax
  unsigned __int16 v12; // dx
  unsigned __int16 v13; // cx
  int v14; // edi
  UtlRBTreeNode_t<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short> *v15; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short> *v16; // eax
  int v17; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short> *v18; // ecx
  CUtlMap<unsigned long,int,unsigned short>::Node_t *p_m_Data; // edi
  char line[260]; // [esp+Ch] [ebp-128h] BYREF
  CUtlString str; // [esp+110h] [ebp-24h] BYREF
  CNetworkStringTableDictionaryManager *v22; // [esp+120h] [ebp-14h]
  CUtlMap<unsigned long,int,unsigned short>::Node_t insert; // [esp+124h] [ebp-10h] BYREF
  unsigned int pulCRC; // [esp+12Ch] [ebp-8h] BYREF
  bool leftchild; // [esp+133h] [ebp-1h] BYREF

  v2 = this;
  v22 = this;
  CNetworkStringTableDictionaryManager::Clear(this);
  v3 = buf;
  m_nMaxPut = buf->m_nMaxPut;
  insert.elem = (int)buf->m_Memory.m_pMemory;
  CRC32_Init(&pulCRC);
  CRC32_ProcessBuffer(&pulCRC, pBuffer: (const void *)insert.elem, nBuffer: m_nMaxPut);
  CRC32_Final(&pulCRC);
  v2->m_CRC = pulCRC;
  while ( v3->m_nMaxPut - v3->m_Get > 0 )
  {
    CUtlBuffer::GetString(this: v3, pString: line, nMaxChars: 260);
    if ( line[0] != 0 )
    {
      CUtlString::CUtlString(this: &str);
      CUtlString::operator=(this: &str, src: line);
      m_Size = v2->m_Strings.m_Size;
      m_nAllocationCount = v2->m_Strings.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CPortalRect,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&v2->m_Strings,
          num: m_Size - m_nAllocationCount + 1);
      ++v2->m_Strings.m_Size;
      m_pMemory = v2->m_Strings.m_Memory.m_pMemory;
      v8 = v2->m_Strings.m_Size - m_Size - 1;
      v2->m_Strings.m_pElements = m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v8);
      v9 = &v2->m_Strings.m_Memory.m_pMemory[m_Size];
      if ( v9 != nullptr )
        CUtlString::CUtlString(this: v9, string: &str);
      v10 = CUtlString::operator char const *(this: &str);
      insert.key = (unsigned int)CNetworkStringTableDictionaryManager::HashStringCaselessIgnoreSlashes(
                                   this: v2,
                                   pString: v10);
      insert.elem = m_Size;
      pulCRC = 0xFFFF;
      leftchild = false;
      CUtlRBTree<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &v2->m_StringHashToIndex.m_Tree,
        &insert,
        parent: (unsigned __int16 *)&pulCRC,
        &leftchild);
      v11 = CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&v2->m_StringHashToIndex);
      v12 = pulCRC;
      v13 = v11;
      v14 = v11;
      v15 = &v2->m_StringHashToIndex.m_Tree.m_Elements.m_pMemory[v14];
      v15->m_Right = -1;
      v15->m_Left = -1;
      v15->m_Parent = v12;
      v15->m_Tag = 0;
      if ( v12 == 0xFFFF )
      {
        v2->m_StringHashToIndex.m_Tree.m_Root = v13;
      }
      else
      {
        v16 = v2->m_StringHashToIndex.m_Tree.m_Elements.m_pMemory;
        v17 = v12;
        if ( leftchild )
          v16[v17].m_Left = v13;
        else
          v16[v17].m_Right = v13;
      }
      CUtlRBTree<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        this: &v2->m_StringHashToIndex.m_Tree,
        elem: v13);
      v18 = v2->m_StringHashToIndex.m_Tree.m_Elements.m_pMemory;
      ++v2->m_StringHashToIndex.m_Tree.m_NumElements;
      p_m_Data = &v18[v14].m_Data;
      if ( p_m_Data != nullptr )
        *p_m_Data = insert;
      str.m_Storage.m_nActualLength = 0;
      if ( str.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( str.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: str.m_Storage.m_Memory.m_pMemory);
          str.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        str.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      v2 = v22;
      v3 = buf;
    }
  }
  v2->m_nEncodeBits = Q_log2(val: v2->m_Strings.m_Size) + 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C63B0
// Name: private: void CNetworkStringTableDictionaryManager::LoadMapStrings(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableDictionaryManager::LoadMapStrings(
        CNetworkStringTableDictionaryManager *this,
        const char *pchMapName,
        int bServer)
{
  unsigned int ActualSize; // eax
  unsigned __int8 *v5; // esi
  int v6; // edi
  char szNameOnDisk[260]; // [esp+Ch] [ebp-238h] BYREF
  char szModelName[260]; // [esp+110h] [ebp-134h] BYREF
  CUtlBuffer buf; // [esp+214h] [ebp-30h] BYREF

  if ( !CUtlString::operator==(this: &this->m_sCurrentMap, src: pchMapName) )
  {
    CUtlString::operator=(this: &this->m_sCurrentMap, src: pchMapName);
    CNetworkStringTableDictionaryManager::Clear(this);
    V_snprintf(pDest: szModelName, maxLen: 260, pFormat: "maps/%s.bsp", pchMapName);
    GetMapPathNameOnDisk(pDiskName: szNameOnDisk, pFullMapName: szModelName, nDiskNameSize: 0x104u);
    if ( (_BYTE)bServer == 0 )
      g_pFileSystem->AddSearchPath(this: g_pFileSystem, a2: szNameOnDisk, a3: "GAME", a4: PATH_ADD_TO_HEAD);
    if ( stringtable_usedictionaries.m_pParent != nullptr
      && stringtable_usedictionaries.m_pParent->m_Value.m_nValue != 0 )
    {
      CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
      if ( CNetworkStringTableDictionaryManager::LoadDictionaryFile(this, &buf, pchMapName) )
      {
        if ( CLZMA::IsCompressed(this: (CLZMA *)&bServer + 3, pInput: buf.m_Memory.m_pMemory) )
        {
          ActualSize = CLZMA::GetActualSize(this: (CLZMA *)&bServer + 3, pInput: buf.m_Memory.m_pMemory);
          v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: ActualSize);
          v6 = CLZMA::Uncompress(
                 this: (CLZMA *)&bServer + 3,
                 pInput: buf.m_Memory.m_pMemory,
                 pOutput: v5,
                 pCallback: nullptr);
          memset(&buf.m_Get, 0, 9);
          buf.m_nOffset = 0;
          buf.m_nMaxPut = -1;
          CUtlBuffer::AddNullTermination(this: &buf, nPut: 0);
          CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: 0);
          CUtlBuffer::Put(this: &buf, pMem: v5, size: v6);
          free(pMem: v5);
        }
        CNetworkStringTableDictionaryManager::ProcessBuffer(this, &buf);
      }
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C6520
// Name: public: virtual bool CNetworkStringTableDictionaryManager::OnLevelLoadStart(char const __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetworkStringTableDictionaryManager::OnLevelLoadStart(
        CNetworkStringTableDictionaryManager *this,
        const char *pchMapName,
        unsigned int *pStringTableCRC)
{
  int v5; // eax
  int v6; // eax

  this->m_BuildStringTableDictionaryCache.m_bActive = false;
  CUtlString::operator=(this: &this->m_BuildStringTableDictionaryCache.m_sBSPName, src: defaultValue);
  this->m_BuildStringTableDictionaryCache.m_bCreatingForX360 = false;
  this->m_BuildStringTableDictionaryCache.m_Buffer.m_Get = 0;
  this->m_BuildStringTableDictionaryCache.m_Buffer.m_Put = 0;
  this->m_BuildStringTableDictionaryCache.m_Buffer.m_nOffset = 0;
  this->m_BuildStringTableDictionaryCache.m_Buffer.m_nMaxPut = 0;
  this->m_BuildStringTableDictionaryCache.m_Buffer.m_Error = 0;
  if ( this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_pMemory);
      this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_pMemory = nullptr;
    }
    this->m_BuildStringTableDictionaryCache.m_Buffer.m_Memory.m_nAllocationCount = 0;
  }
  V_FileBase(in: com_gamedir, out: gamedir_9, maxlen: 260);
  if ( _V_stricmp(s1: gamedir_9, s2: "infested") == 0 )
    return true;
  if ( stringtable_alwaysrebuilddictionaries.m_pParent != nullptr
    && stringtable_alwaysrebuilddictionaries.m_pParent->m_Value.m_nValue != 0
    || (v5 = _CommandLine(),
        (v6 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-stringtables")) != 0) )
  {
    LOBYTE(v6) = 1;
  }
  this->m_bForceRebuildDictionaries = v6;
  CNetworkStringTableDictionaryManager::LoadMapStrings(this, pchMapName, bServer: pStringTableCRC == nullptr);
  return pStringTableCRC == nullptr || *pStringTableCRC == this->m_CRC;
}

//------------------------------------------------------------------------------
// Address: 0x101C66F0
// Name: public: virtual unsigned int CNetworkStringDict::Count(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CNetworkStringDict::Count(CNetworkStringDict *this)
{
  return this->m_Items.m_Tree.m_NumElements;
}

//------------------------------------------------------------------------------
// Address: 0x101C6A30
// Name: public: virtual char const __near * CNetworkStringDict::String(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CNetworkStringDict::String(CNetworkStringDict *this, unsigned __int16 index)
{
  return CUtlString::operator char const *(this: &this->m_Items.m_Tree.m_Elements.m_pMemory[index].m_Data.key.m_Name);
}

//------------------------------------------------------------------------------
// Address: 0x101C6A50
// Name: public: virtual class CNetworkStringTableItem const __near & CNetworkStringDict::Element(int)const
// Source: json
//------------------------------------------------------------------------------
const CNetworkStringTableItem *__thiscall CNetworkStringDict::Element(CNetworkStringDict *this, unsigned __int16 index)
{
  return &this->m_Items.m_Tree.m_Elements.m_pMemory[index].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x101C6A70
// Name: public: virtual int CNetworkStringDict::DictionaryIndex(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetworkStringDict::DictionaryIndex(CNetworkStringDict *this, unsigned __int16 index)
{
  if ( this->m_bUseDictionary )
    return this->m_Items.m_Tree.m_Elements.m_pMemory[index].m_Data.key.m_DictionaryIndex;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x101C73D0
// Name: public: virtual bool CNetworkStringDict::IsValidIndex(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetworkStringDict::IsValidIndex(CNetworkStringDict *this, unsigned __int16 index)
{
  CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short> *p_m_Items; // ecx

  p_m_Items = &this->m_Items;
  return index < p_m_Items->m_Tree.m_Elements.m_nAllocationCount
      && index <= p_m_Items->m_Tree.m_LastAlloc.index
      && CUtlRBTree<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short,CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this: &p_m_Items->m_Tree,
           i: index) != index;
}

//------------------------------------------------------------------------------
// Address: 0x101C7410
// Name: public: void CNetworkStringDict::CTableItem::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringDict::CTableItem::Update(CNetworkStringDict::CTableItem *this)
{
  const char *v2; // eax
  unsigned __int16 v3; // ax
  CUtlMap<unsigned long,int,unsigned short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  v2 = CUtlString::operator char const *(this: &this->m_Name);
  search.key = (unsigned int)CNetworkStringTableDictionaryManager::HashStringCaselessIgnoreSlashes(
                               this: &g_StringTableDictionary,
                               pString: v2);
  v3 = CUtlRBTree<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &g_StringTableDictionary.m_StringHashToIndex.m_Tree,
         &search);
  if ( v3 == 0xFFFF )
    this->m_DictionaryIndex = -1;
  else
    this->m_DictionaryIndex = g_StringTableDictionary.m_StringHashToIndex.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
  CNetworkStringDict::CTableItem::ComputeHash(this);
}

//------------------------------------------------------------------------------
// Address: 0x101C7480
// Name: public: void CNetworkStringDict::CTableItem::SetName(bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringDict::CTableItem::SetName(
        CNetworkStringDict::CTableItem *this,
        bool bUseDictionary,
        const char *pString)
{
  unsigned __int16 v4; // ax
  CUtlMap<unsigned long,int,unsigned short>::Node_t search; // [esp+8h] [ebp-8h] BYREF

  CUtlString::operator=(this: &this->m_Name, src: pString);
  if ( !bUseDictionary
    || (search.key = (unsigned int)CNetworkStringTableDictionaryManager::HashStringCaselessIgnoreSlashes(
                                     this: &g_StringTableDictionary,
                                     pString),
        (v4 = CUtlRBTree<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned long,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned long,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                this: &g_StringTableDictionary.m_StringHashToIndex.m_Tree,
                &search)) == 0xFFFF) )
  {
    this->m_DictionaryIndex = -1;
    CNetworkStringDict::CTableItem::ComputeHash(this);
  }
  else
  {
    this->m_DictionaryIndex = g_StringTableDictionary.m_StringHashToIndex.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
    CNetworkStringDict::CTableItem::ComputeHash(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C7500
// Name: public: virtual int CNetworkStringDict::Find(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetworkStringDict::Find(CNetworkStringDict *this, const char *pString)
{
  int v3; // esi
  CNetworkStringDict::CTableItem search; // [esp+4h] [ebp-18h] BYREF

  CUtlString::CUtlString(this: &search.m_Name);
  search.m_StringHash = 0;
  CUtlString::operator=(this: &search.m_Name, src: pString);
  search.m_DictionaryIndex = -1;
  CNetworkStringDict::CTableItem::ComputeHash(this: &search);
  v3 = CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Find(
         this: &this->m_Items,
         key: &search);
  search.m_Name.m_Storage.m_nActualLength = 0;
  if ( v3 == 0xFFFF )
  {
    if ( search.m_Name.m_Storage.m_Memory.m_nGrowSize >= 0 && search.m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.m_Name.m_Storage.m_Memory.m_pMemory);
    return -1;
  }
  else
  {
    if ( search.m_Name.m_Storage.m_Memory.m_nGrowSize >= 0 && search.m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.m_Name.m_Storage.m_Memory.m_pMemory);
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C75B0
// Name: public: virtual void CNetworkStringDict::UpdateDictionary(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringDict::UpdateDictionary(CNetworkStringDict *this, unsigned __int16 index)
{
  if ( this->m_bUseDictionary )
    CNetworkStringDict::CTableItem::Update(this: &this->m_Items.m_Tree.m_Elements.m_pMemory[index].m_Data.key);
}

//------------------------------------------------------------------------------
// Address: 0x101C7700
// Name: public: virtual void CNetworkStringDict::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringDict::Purge(CNetworkStringDict *this)
{
  CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short> *p_m_Items; // esi

  p_m_Items = &this->m_Items;
  CUtlRBTree<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short,CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Items.m_Tree);
  p_m_Items->m_Tree.m_FirstFree = -1;
  if ( p_m_Items->m_Tree.m_Elements.m_nGrowSize < 0 )
  {
    p_m_Items->m_Tree.m_LastAlloc.index = -1;
  }
  else
  {
    if ( p_m_Items->m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Items->m_Tree.m_Elements.m_pMemory);
      p_m_Items->m_Tree.m_Elements.m_pMemory = nullptr;
    }
    p_m_Items->m_Tree.m_Elements.m_nAllocationCount = 0;
    p_m_Items->m_Tree.m_LastAlloc.index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C7760
// Name: public: virtual int CNetworkStringDict::Insert(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetworkStringDict::Insert(CNetworkStringDict *this, const char *pString)
{
  int v3; // esi
  bool m_bUseDictionary; // [esp-8h] [ebp-24h]
  CNetworkStringDict::CTableItem item; // [esp+4h] [ebp-18h] BYREF

  item.m_DictionaryIndex = -1;
  CUtlString::CUtlString(this: &item.m_Name);
  m_bUseDictionary = this->m_bUseDictionary;
  item.m_StringHash = 0;
  CNetworkStringDict::CTableItem::SetName(this: &item, bUseDictionary: m_bUseDictionary, pString);
  v3 = CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Insert(
         this: &this->m_Items,
         key: &item);
  item.m_Name.m_Storage.m_nActualLength = 0;
  if ( item.m_Name.m_Storage.m_Memory.m_nGrowSize >= 0 && item.m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: item.m_Name.m_Storage.m_Memory.m_pMemory);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101C77D0
// Name: public: virtual CNetworkStringDict::~CNetworkStringDict(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringDict::~CNetworkStringDict(CNetworkStringDict *this)
{
  this->__vftable = (CNetworkStringDict_vtbl *)&CNetworkStringDict::`vftable';
  CUtlRBTree<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short,CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Items.m_Tree);
  this->m_Items.m_Tree.m_FirstFree = -1;
  if ( this->m_Items.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Items.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Items.m_Tree.m_Elements.m_pMemory);
      this->m_Items.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_Items.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  this->m_Items.m_Tree.m_LastAlloc.index = -1;
  CUtlRBTree<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short,CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short,CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CNetworkStringDict::CTableItem,CNetworkStringTableItem,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_Items.m_Tree);
  this->__vftable = (CNetworkStringDict_vtbl *)&INetworkStringDict::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x101C7860
// Name: public: CNetworkStringTable::CNetworkStringTable(int,char const __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
CNetworkStringTable *__thiscall CNetworkStringTable::CNetworkStringTable(
        CNetworkStringTable *this,
        int id,
        const char *tableName,
        int maxentries,
        int userdatafixedsize,
        int userdatanetworkbits,
        int flags)
{
  unsigned int v8; // kr00_4
  char *v9; // eax
  char v10; // cl
  INetworkStringDict *v11; // eax
  char m_nFlags; // cl
  INetworkStringDict_vtbl *v13; // ecx

  *((_BYTE *)this + 28) &= ~4u;
  this->m_nFlags = flags;
  this->__vftable = (CNetworkStringTable_vtbl *)&CNetworkStringTable::`vftable';
  this->m_pItemsClientSide = nullptr;
  this->m_id = id;
  v8 = strlen(tableName);
  v9 = (char *)MemAlloc_Alloc(nSize: v8 + 1);
  this->m_pszTableName = v9;
  V_strncpy(pDest: v9, pSrc: tableName, maxLen: v8 + 1);
  *((_BYTE *)this + 28) &= 0xFCu;
  this->m_changeFunc = nullptr;
  this->m_pObject = nullptr;
  this->m_nTickCount = 0;
  this->m_pMirrorTable = nullptr;
  this->m_nLastChangedTick = 0;
  this->m_nMaxEntries = maxentries;
  this->m_nEntryBits = Q_log2(val: maxentries);
  v10 = *((_BYTE *)this + 28) ^ (8 * (userdatafixedsize != 0));
  this->m_nUserDataSize = userdatafixedsize;
  *((_BYTE *)this + 28) ^= v10 & 8;
  this->m_nUserDataSizeBits = userdatanetworkbits;
  if ( userdatanetworkbits > 14 )
    Host_Error(
      error: "String tables user data bits restricted to %i bits, requested %i is too large\n",
      14,
      userdatanetworkbits);
  if ( this->m_nUserDataSize > 0x4000 )
    Host_Error(
      error: "String tables user data size restricted to %i bytes, requested %i is too large\n",
      0x4000,
      this->m_nUserDataSize);
  if ( 1 << this->m_nEntryBits != maxentries )
    Host_Error(
      error: "String tables must be powers of two in size!, %i is not a power of 2 [%s]\n",
      maxentries,
      tableName);
  v11 = (INetworkStringDict *)MemAlloc_Alloc(nSize: 0x24u);
  if ( v11 != nullptr )
  {
    m_nFlags = this->m_nFlags;
    v11->__vftable = (INetworkStringDict_vtbl *)&CNetworkStringDict::`vftable';
    LOBYTE(v11[1].__vftable) = m_nFlags & 1;
    v11[2].__vftable = (INetworkStringDict_vtbl *)CNetworkStringDict::CTableItem::Less;
    v11[3].__vftable = nullptr;
    v11[4].__vftable = nullptr;
    v11[5].__vftable = nullptr;
    v13 = v11[3].__vftable;
    v11[6].__vftable = (INetworkStringDict_vtbl *)0xFFFF;
    v11[7].__vftable = (INetworkStringDict_vtbl *)-1;
    v11[8].__vftable = v13;
    this->m_pItems = v11;
  }
  else
  {
    this->m_pItems = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C79A0
// Name: protected: void CNetworkStringTable::DeleteAllStrings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTable::DeleteAllStrings(CNetworkStringTable *this)
{
  INetworkStringDict *m_pItems; // ecx
  INetworkStringDict *v3; // eax
  char m_nFlags; // cl
  INetworkStringDict_vtbl *v5; // ecx
  INetworkStringDict *m_pItemsClientSide; // ecx
  INetworkStringDict *v7; // eax
  INetworkStringDict_vtbl *v8; // ecx

  m_pItems = this->m_pItems;
  if ( m_pItems != nullptr )
    ((void (__thiscall *)(INetworkStringDict *, int))m_pItems->dtr_INetworkStringDict)(a1: m_pItems, a2: 1);
  v3 = (INetworkStringDict *)MemAlloc_Alloc(nSize: 0x24u);
  if ( v3 != nullptr )
  {
    m_nFlags = this->m_nFlags;
    v3->__vftable = (INetworkStringDict_vtbl *)&CNetworkStringDict::`vftable';
    LOBYTE(v3[1].__vftable) = m_nFlags & 1;
    v3[2].__vftable = (INetworkStringDict_vtbl *)CNetworkStringDict::CTableItem::Less;
    v3[3].__vftable = nullptr;
    v3[4].__vftable = nullptr;
    v3[5].__vftable = nullptr;
    v5 = v3[3].__vftable;
    v3[6].__vftable = (INetworkStringDict_vtbl *)0xFFFF;
    v3[7].__vftable = (INetworkStringDict_vtbl *)-1;
    v3[8].__vftable = v5;
  }
  else
  {
    v3 = nullptr;
  }
  m_pItemsClientSide = this->m_pItemsClientSide;
  this->m_pItems = v3;
  if ( m_pItemsClientSide != nullptr )
  {
    ((void (__thiscall *)(INetworkStringDict *, int))m_pItemsClientSide->dtr_INetworkStringDict)(
      a1: m_pItemsClientSide,
      a2: 1);
    v7 = (INetworkStringDict *)MemAlloc_Alloc(nSize: 0x24u);
    if ( v7 != nullptr )
    {
      v7->__vftable = (INetworkStringDict_vtbl *)&CNetworkStringDict::`vftable';
      LOBYTE(v7[1].__vftable) = 0;
      v7[2].__vftable = (INetworkStringDict_vtbl *)CNetworkStringDict::CTableItem::Less;
      v7[3].__vftable = nullptr;
      v7[4].__vftable = nullptr;
      v7[5].__vftable = nullptr;
      v8 = v7[3].__vftable;
      v7[6].__vftable = (INetworkStringDict_vtbl *)0xFFFF;
      v7[7].__vftable = (INetworkStringDict_vtbl *)-1;
      v7[8].__vftable = v8;
    }
    else
    {
      v7 = nullptr;
    }
    this->m_pItemsClientSide = v7;
    v7->Insert(this: v7, a2: "___clientsideitemsplaceholder0___");
    this->m_pItemsClientSide->Insert(this: this->m_pItemsClientSide, a2: "___clientsideitemsplaceholder1___");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C7A70
// Name: public: bool CNetworkStringTable::ReadStringTable(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetworkStringTable::ReadStringTable(CNetworkStringTable *this, bf_read *buf)
{
  CNetworkStringTable *v2; // ebx
  int m_nBitsAvail; // ecx
  int m_nInBufWord; // eax
  int v6; // edx
  int v7; // ecx
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  unsigned int v10; // ecx
  const unsigned int *v11; // edx
  unsigned int v12; // ebx
  int v13; // eax
  const unsigned int *v14; // ecx
  unsigned int v15; // edx
  unsigned int v16; // edi
  unsigned int v17; // edx
  unsigned int v18; // eax
  int v19; // ecx
  bool v20; // zf
  const unsigned int *v21; // eax
  const unsigned int *v22; // edx
  int v23; // ecx
  unsigned int v24; // eax
  int v25; // edx
  int v26; // ecx
  int v27; // edi
  const unsigned int *v28; // eax
  const unsigned int *v29; // ecx
  const unsigned int *v30; // edx
  unsigned int v31; // ebx
  int v32; // eax
  const unsigned int *v33; // ecx
  unsigned int v34; // edx
  unsigned int v35; // edi
  void *v36; // ebx
  unsigned int v37; // eax
  int v38; // edx
  const unsigned int *v39; // eax
  const unsigned int *v40; // ecx
  int v41; // ecx
  unsigned int v42; // eax
  int v43; // edx
  int v44; // ecx
  int v45; // edi
  const unsigned int *v46; // eax
  const unsigned int *v47; // ecx
  const unsigned int *v48; // edx
  unsigned int v49; // ebx
  int v50; // eax
  const unsigned int *v51; // ecx
  unsigned int v52; // edx
  unsigned int v53; // edi
  int v54; // ebx
  unsigned int v55; // eax
  int v56; // ecx
  const unsigned int *v57; // eax
  const unsigned int *v58; // edx
  int v59; // ecx
  unsigned int v60; // eax
  int v61; // edx
  int v62; // ecx
  int v63; // edi
  const unsigned int *v64; // eax
  const unsigned int *v65; // ecx
  const unsigned int *v66; // edx
  unsigned int v67; // ebx
  int v68; // eax
  const unsigned int *v69; // ecx
  unsigned int v70; // edx
  unsigned int v71; // edi
  void *v72; // ebx
  char pStr[4096]; // [esp+Ch] [ebp-1008h] BYREF
  int v75; // [esp+100Ch] [ebp-8h]
  CNetworkStringTable *v76; // [esp+1010h] [ebp-4h]
  CBitRead *i; // [esp+101Ch] [ebp+8h]
  int v78; // [esp+101Ch] [ebp+8h]

  v2 = this;
  v76 = this;
  CNetworkStringTable::DeleteAllStrings(this);
  m_nBitsAvail = buf->m_nBitsAvail;
  if ( m_nBitsAvail >= 16 )
  {
    m_nInBufWord = buf->m_nInBufWord;
    v6 = (unsigned __int16)m_nInBufWord;
    v7 = m_nBitsAvail - 16;
    buf->m_nBitsAvail = v7;
    if ( v7 != 0 )
    {
      buf->m_nInBufWord = HIWORD(m_nInBufWord);
      m_nInBufWord = (unsigned __int16)m_nInBufWord;
    }
    else
    {
      m_pDataIn = buf->m_pDataIn;
      m_pBufferEnd = buf->m_pBufferEnd;
      buf->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        buf->m_pDataIn = m_pDataIn + 1;
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        m_nInBufWord = v6;
      }
      else
      {
        if ( m_pDataIn <= m_pBufferEnd )
        {
          v10 = *m_pDataIn;
          buf->m_pDataIn = m_pDataIn + 1;
          buf->m_nInBufWord = v10;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
        m_nInBufWord = v6;
      }
    }
    goto LABEL_20;
  }
  v11 = buf->m_pBufferEnd;
  v12 = buf->m_nInBufWord;
  v13 = 16 - m_nBitsAvail;
  v14 = buf->m_pDataIn;
  if ( v14 == v11 )
  {
    buf->m_nBitsAvail = 1;
    buf->m_nInBufWord = 0;
    buf->m_bOverflow = true;
LABEL_15:
    buf->m_pDataIn = v14 + 1;
    goto LABEL_16;
  }
  if ( v14 <= v11 )
  {
    buf->m_nInBufWord = *v14;
    goto LABEL_15;
  }
  buf->m_bOverflow = true;
  buf->m_nInBufWord = 0;
LABEL_16:
  if ( buf->m_bOverflow )
  {
    m_nInBufWord = 0;
  }
  else
  {
    v15 = buf->m_nInBufWord;
    v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << buf->m_nBitsAvail;
    buf->m_nBitsAvail = 32 - v13;
    v17 = v15 >> v13;
    m_nInBufWord = v16 | v12;
    buf->m_nInBufWord = v17;
  }
  v2 = v76;
LABEL_20:
  if ( m_nInBufWord > 0 )
  {
    for ( i = (CBitRead *)m_nInBufWord; i != nullptr; i = (CBitRead *)((char *)i - 1) )
    {
      CBitRead::ReadString(this: buf, pStr, maxLen: 4096, bLine: false, pOutNumChars: nullptr);
      v18 = buf->m_nInBufWord;
      v19 = v18 & 1;
      v20 = buf->m_nBitsAvail-- == 1;
      if ( v20 )
      {
        v21 = buf->m_pDataIn;
        v22 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v21 == v22 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v21 + 1;
        }
        else if ( v21 <= v22 )
        {
          buf->m_nInBufWord = *v21;
          buf->m_pDataIn = v21 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
      }
      else
      {
        buf->m_nInBufWord = v18 >> 1;
      }
      if ( v19 != 1 )
      {
        v2->AddString(this: v2, a2: true, a3: pStr, a4: -1, a5: nullptr);
        continue;
      }
      v23 = buf->m_nBitsAvail;
      if ( v23 >= 16 )
      {
        v24 = buf->m_nInBufWord;
        v25 = (unsigned __int16)v24;
        v26 = v23 - 16;
        buf->m_nBitsAvail = v26;
        if ( v26 != 0 )
        {
          buf->m_nInBufWord = HIWORD(v24);
          v27 = (unsigned __int16)v24;
        }
        else
        {
          v28 = buf->m_pDataIn;
          v29 = buf->m_pBufferEnd;
          buf->m_nBitsAvail = 32;
          if ( v28 == v29 )
          {
            buf->m_nInBufWord = 0;
            buf->m_nBitsAvail = 1;
            buf->m_pDataIn = v28 + 1;
            v27 = v25;
          }
          else
          {
            if ( v28 <= v29 )
            {
              buf->m_nInBufWord = *v28;
              buf->m_pDataIn = v28 + 1;
            }
            else
            {
              buf->m_nInBufWord = 0;
              buf->m_bOverflow = true;
            }
            v27 = v25;
          }
        }
        goto LABEL_48;
      }
      v30 = buf->m_pBufferEnd;
      v31 = buf->m_nInBufWord;
      v32 = 16 - v23;
      v33 = buf->m_pDataIn;
      if ( v33 == v30 )
      {
        buf->m_nBitsAvail = 1;
        buf->m_nInBufWord = 0;
        buf->m_bOverflow = true;
      }
      else
      {
        if ( v33 > v30 )
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
          goto LABEL_45;
        }
        buf->m_nInBufWord = *v33;
      }
      buf->m_pDataIn = v33 + 1;
LABEL_45:
      if ( buf->m_bOverflow )
      {
        v27 = 0;
      }
      else
      {
        v34 = buf->m_nInBufWord;
        v35 = (v34 & CBitBuffer::s_nMaskTable[v32]) << buf->m_nBitsAvail;
        buf->m_nBitsAvail = 32 - v32;
        v27 = v31 | v35;
        buf->m_nInBufWord = v34 >> v32;
      }
LABEL_48:
      v36 = MemAlloc_Alloc(nSize: v27 + 4);
      CBitRead::ReadBytes(this: buf, pOut: v36, nBytes: v27);
      v76->AddString(this: v76, a2: true, a3: pStr, a4: v27, a5: v36);
      free(pMem: v36);
      v2 = v76;
    }
  }
  v37 = buf->m_nInBufWord;
  v38 = v37 & 1;
  v20 = buf->m_nBitsAvail-- == 1;
  if ( v20 )
  {
    v39 = buf->m_pDataIn;
    v40 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v39 == v40 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_pDataIn = v39 + 1;
    }
    else if ( v39 <= v40 )
    {
      buf->m_nInBufWord = *v39;
      buf->m_pDataIn = v39 + 1;
    }
    else
    {
      buf->m_bOverflow = true;
      buf->m_nInBufWord = 0;
    }
  }
  else
  {
    buf->m_nInBufWord = v37 >> 1;
  }
  if ( v38 != 1 )
    return 1;
  v41 = buf->m_nBitsAvail;
  if ( v41 < 16 )
  {
    v48 = buf->m_pBufferEnd;
    v49 = buf->m_nInBufWord;
    v50 = 16 - v41;
    v51 = buf->m_pDataIn;
    if ( v51 == v48 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v51 > v48 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_74;
      }
      buf->m_nInBufWord = *v51;
    }
    buf->m_pDataIn = v51 + 1;
LABEL_74:
    if ( buf->m_bOverflow )
    {
      v45 = 0;
      v78 = 0;
    }
    else
    {
      v52 = buf->m_nInBufWord;
      v53 = (v52 & CBitBuffer::s_nMaskTable[v50]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v50;
      v45 = v53 | v49;
      v78 = v45;
      buf->m_nInBufWord = v52 >> v50;
    }
    goto LABEL_77;
  }
  v42 = buf->m_nInBufWord;
  v43 = (unsigned __int16)v42;
  v44 = v41 - 16;
  buf->m_nBitsAvail = v44;
  if ( v44 != 0 )
  {
    v45 = (unsigned __int16)v42;
    buf->m_nInBufWord = HIWORD(v42);
    v78 = (unsigned __int16)v42;
  }
  else
  {
    v46 = buf->m_pDataIn;
    v47 = buf->m_pBufferEnd;
    buf->m_nBitsAvail = 32;
    if ( v46 == v47 )
    {
      buf->m_nInBufWord = 0;
      v45 = v43;
      buf->m_nBitsAvail = 1;
      buf->m_pDataIn = v46 + 1;
      v78 = v43;
    }
    else
    {
      if ( v46 <= v47 )
      {
        v45 = v43;
        buf->m_nInBufWord = *v46;
        buf->m_pDataIn = v46 + 1;
      }
      else
      {
        buf->m_nInBufWord = 0;
        v45 = v43;
        buf->m_bOverflow = true;
      }
      v78 = v43;
    }
  }
LABEL_77:
  v54 = 0;
  v75 = 0;
  if ( v45 > 0 )
  {
    while ( 1 )
    {
      CBitRead::ReadString(this: buf, pStr, maxLen: 4096, bLine: false, pOutNumChars: nullptr);
      v55 = buf->m_nInBufWord;
      v56 = v55 & 1;
      v20 = buf->m_nBitsAvail-- == 1;
      if ( v20 )
      {
        v57 = buf->m_pDataIn;
        v58 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v57 == v58 )
        {
          buf->m_nBitsAvail = 1;
          buf->m_nInBufWord = 0;
          buf->m_pDataIn = v57 + 1;
        }
        else if ( v57 <= v58 )
        {
          buf->m_nInBufWord = *v57;
          buf->m_pDataIn = v57 + 1;
        }
        else
        {
          buf->m_bOverflow = true;
          buf->m_nInBufWord = 0;
        }
      }
      else
      {
        buf->m_nInBufWord = v55 >> 1;
      }
      if ( v56 != 1 )
      {
        if ( v54 >= 2 )
          v76->AddString(this: v76, a2: false, a3: pStr, a4: -1, a5: nullptr);
        goto LABEL_109;
      }
      v59 = buf->m_nBitsAvail;
      if ( v59 < 16 )
        break;
      v60 = buf->m_nInBufWord;
      v61 = (unsigned __int16)v60;
      v62 = v59 - 16;
      buf->m_nBitsAvail = v62;
      if ( v62 != 0 )
      {
        buf->m_nInBufWord = HIWORD(v60);
        v63 = (unsigned __int16)v60;
      }
      else
      {
        v64 = buf->m_pDataIn;
        v65 = buf->m_pBufferEnd;
        buf->m_nBitsAvail = 32;
        if ( v64 == v65 )
        {
          buf->m_nInBufWord = 0;
          buf->m_nBitsAvail = 1;
          buf->m_pDataIn = v64 + 1;
          v63 = v61;
        }
        else
        {
          if ( v64 <= v65 )
          {
            buf->m_nInBufWord = *v64;
            buf->m_pDataIn = v64 + 1;
          }
          else
          {
            buf->m_nInBufWord = 0;
            buf->m_bOverflow = true;
          }
          v63 = v61;
        }
      }
LABEL_104:
      v72 = MemAlloc_Alloc(nSize: v63 + 4);
      CBitRead::ReadBytes(this: buf, pOut: v72, nBytes: v63);
      if ( v75 >= 2 )
        v76->AddString(this: v76, a2: false, a3: pStr, a4: v63, a5: v72);
      free(pMem: v72);
      v45 = v78;
      v54 = v75;
LABEL_109:
      v75 = ++v54;
      if ( v54 >= v45 )
        return 1;
    }
    v66 = buf->m_pBufferEnd;
    v67 = buf->m_nInBufWord;
    v68 = 16 - v59;
    v69 = buf->m_pDataIn;
    if ( v69 == v66 )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( v69 > v66 )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
        goto LABEL_101;
      }
      buf->m_nInBufWord = *v69;
    }
    buf->m_pDataIn = v69 + 1;
LABEL_101:
    if ( buf->m_bOverflow )
    {
      v63 = 0;
    }
    else
    {
      v70 = buf->m_nInBufWord;
      v71 = (v70 & CBitBuffer::s_nMaskTable[v68]) << buf->m_nBitsAvail;
      buf->m_nBitsAvail = 32 - v68;
      v63 = v67 | v71;
      buf->m_nInBufWord = v70 >> v68;
    }
    goto LABEL_104;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C8030
// Name: public: virtual void CNetworkStringTableContainer::SetAllowClientSideAddString(class INetworkStringTable __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTableContainer::SetAllowClientSideAddString(
        CNetworkStringTableContainer *this,
        INetworkStringTable *table,
        bool bAllowClientSideAddString)
{
  int v4; // ebx
  INetworkStringTable *v5; // esi
  INetworkStringTable_vtbl *v6; // ecx
  INetworkStringTable_vtbl *v7; // eax
  int (__thiscall *GetNumStrings)(INetworkStringTable *); // ecx

  v4 = 0;
  if ( this->m_Tables.m_Size > 0 )
  {
    while ( 1 )
    {
      v5 = this->GetTable(this, a2: v4);
      if ( v5 == table )
        break;
      if ( ++v4 >= this->m_Tables.m_Size )
        return;
    }
    if ( bAllowClientSideAddString != (((int)v5[7].__vftable & 4) != 0) )
    {
      v6 = v5[15].__vftable;
      LOBYTE(v5[7].__vftable) ^= (LOBYTE(v5[7].__vftable) ^ (4 * bAllowClientSideAddString)) & 4;
      if ( v6 != nullptr )
      {
        (*(void (__thiscall **)(INetworkStringTable_vtbl *, int))v6->dtr_INetworkStringTable)(a1: v6, a2: 1);
        v5[15].__vftable = nullptr;
      }
      if ( ((int)v5[7].__vftable & 4) != 0 )
      {
        v7 = (INetworkStringTable_vtbl *)MemAlloc_Alloc(nSize: 0x24u);
        if ( v7 != nullptr )
        {
          v7->dtr_INetworkStringTable = (void (__thiscall *)(INetworkStringTable *))&CNetworkStringDict::`vftable';
          LOBYTE(v7->GetTableName) = 0;
          v7->GetTableId = (int (__thiscall *)(INetworkStringTable *))CNetworkStringDict::CTableItem::Less;
          v7->GetNumStrings = nullptr;
          v7->GetMaxStrings = nullptr;
          v7->GetEntryBits = nullptr;
          GetNumStrings = v7->GetNumStrings;
          v7->SetTick = (void (__thiscall *)(INetworkStringTable *, int))0xFFFF;
          v7->ChangedSinceTick = (bool (__thiscall *)(INetworkStringTable *, int))-1;
          v7->AddString = (int (__thiscall *)(INetworkStringTable *, bool, const char *, int, const void *))GetNumStrings;
        }
        else
        {
          v7 = nullptr;
        }
        v5[15].__vftable = v7;
        (*((void (__thiscall **)(INetworkStringTable_vtbl *, const char *))v7->dtr_INetworkStringTable + 5))(
          a1: v7,
          a2: "___clientsideitemsplaceholder0___");
        (*((void (__thiscall **)(INetworkStringTable_vtbl *, const char *))v5[15].dtr_INetworkStringTable + 5))(
          a1: v5[15].__vftable,
          a2: "___clientsideitemsplaceholder1___");
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C8110
// Name: public: virtual class INetworkStringTable __near * CNetworkStringTableContainer::CreateStringTable(char const __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
CNetworkStringTable *__thiscall CNetworkStringTableContainer::CreateStringTable(
        CNetworkStringTableContainer *this,
        const char *tableName,
        int maxentries,
        int userdatafixedsize,
        int userdatanetworkbits,
        int flags)
{
  int m_Size; // edi
  CNetworkStringTable *v9; // eax
  CNetworkStringTable *v10; // ebx
  int v11; // edi
  int m_nAllocationCount; // eax
  CNetworkStringTable **m_pMemory; // ecx
  int v14; // eax
  CNetworkStringTable **v15; // edi

  if ( this->m_bAllowCreation )
  {
    if ( this->FindTable(this, a2: tableName) != nullptr )
    {
      Sys_Error(error: "Tried to create string table '%s' twice\n", tableName);
      return nullptr;
    }
    else
    {
      m_Size = this->m_Tables.m_Size;
      if ( m_Size < 32 )
      {
        v9 = (CNetworkStringTable *)MemAlloc_Alloc(nSize: 0x40u);
        if ( v9 != nullptr )
          v10 = CNetworkStringTable::CNetworkStringTable(
                  this: v9,
                  id: m_Size,
                  tableName,
                  maxentries,
                  userdatafixedsize,
                  userdatanetworkbits,
                  flags);
        else
          v10 = nullptr;
        if ( this->m_bEnableRollback )
          *((_BYTE *)v10 + 28) |= 1u;
        v10->SetTick(this: v10, a2: this->m_nTickCount);
        v11 = this->m_Tables.m_Size;
        m_nAllocationCount = this->m_Tables.m_Memory.m_nAllocationCount;
        if ( v11 + 1 > m_nAllocationCount )
          CUtlMemory<INetMessage *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&this->m_Tables,
            num: v11 - m_nAllocationCount + 1);
        ++this->m_Tables.m_Size;
        m_pMemory = this->m_Tables.m_Memory.m_pMemory;
        v14 = this->m_Tables.m_Size - v11 - 1;
        this->m_Tables.m_pElements = m_pMemory;
        if ( v14 > 0 )
          _V_memmove(dest: &m_pMemory[v11 + 1], src: &m_pMemory[v11], count: 4 * v14);
        v15 = &this->m_Tables.m_Memory.m_pMemory[v11];
        if ( v15 != nullptr )
          *v15 = v10;
        return v10;
      }
      else
      {
        Sys_Error(error: "Only %i string tables allowed, can't create'%s'", 32, tableName);
        return nullptr;
      }
    }
  }
  else
  {
    Sys_Error(error: "Tried to create string table '%s' at wrong time\n", tableName);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C8220
// Name: public: bool CNetworkStringTableContainer::ReadStringTables(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetworkStringTableContainer::ReadStringTables(CNetworkStringTableContainer *this, bf_read *buf)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  int v4; // edi
  unsigned int v5; // edx
  const unsigned int *v6; // eax
  const unsigned int *v7; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // edi
  int v10; // eax
  const unsigned int *m_pDataIn; // ecx
  unsigned int v12; // edx
  unsigned int v13; // ebx
  CNetworkStringTable *v14; // eax
  char tablename[256]; // [esp+Ch] [ebp-104h] BYREF
  CNetworkStringTableContainer *v17; // [esp+10Ch] [ebp-4h]

  v17 = this;
  m_nBitsAvail = buf->m_nBitsAvail;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = buf->m_pBufferEnd;
    m_nInBufWord = buf->m_nInBufWord;
    v10 = 8 - m_nBitsAvail;
    m_pDataIn = buf->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      buf->m_nBitsAvail = 1;
      buf->m_nInBufWord = 0;
      buf->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        buf->m_bOverflow = true;
        buf->m_nInBufWord = 0;
LABEL_15:
        if ( buf->m_bOverflow )
        {
          v4 = 0;
          goto LABEL_19;
        }
        v12 = buf->m_nInBufWord;
        v13 = (v12 & CBitBuffer::s_nMaskTable[v10]) << buf->m_nBitsAvail;
        buf->m_nBitsAvail = 32 - v10;
        v4 = v13 | m_nInBufWord;
        v5 = v12 >> v10;
        goto LABEL_18;
      }
      buf->m_nInBufWord = *m_pDataIn;
    }
    buf->m_pDataIn = m_pDataIn + 1;
    goto LABEL_15;
  }
  v3 = buf->m_nInBufWord;
  v4 = (unsigned __int8)v3;
  buf->m_nBitsAvail = m_nBitsAvail - 8;
  if ( m_nBitsAvail != 8 )
  {
    v5 = v3 >> 8;
LABEL_18:
    buf->m_nInBufWord = v5;
    goto LABEL_19;
  }
  v6 = buf->m_pDataIn;
  v7 = buf->m_pBufferEnd;
  buf->m_nBitsAvail = 32;
  if ( v6 == v7 )
  {
    buf->m_nBitsAvail = 1;
    buf->m_nInBufWord = 0;
    buf->m_pDataIn = v6 + 1;
  }
  else if ( v6 <= v7 )
  {
    buf->m_nInBufWord = *v6;
    buf->m_pDataIn = v6 + 1;
  }
  else
  {
    buf->m_bOverflow = true;
    buf->m_nInBufWord = 0;
  }
LABEL_19:
  if ( v4 > 0 )
  {
    do
    {
      CBitRead::ReadString(this: buf, pStr: tablename, maxLen: 256, bLine: false, pOutNumChars: nullptr);
      v14 = (CNetworkStringTable *)v17->FindTable(this: v17, a2: tablename);
      if ( CNetworkStringTable::ReadStringTable(this: v14, buf) == 0 )
        Host_Error(error: "Error reading string table %s\n", tablename);
      --v4;
    }
    while ( v4 != 0 );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101DED50
// Name: public: int CNetworkStringTable::GetUserDataSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetworkStringTable::GetUserDataSize(CVTFTexture *this)
{
  return this->m_nFrameCount;
}

//------------------------------------------------------------------------------
// Address: 0x10272410
// Name: public: virtual void CNetworkStringTable::SetTick(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkStringTable::SetTick(bf_write *this, const char *pDebugName)
{
  this->m_pDebugName = pDebugName;
}

//------------------------------------------------------------------------------
// Address: 0x10287FD0
// Name: public: int CNetworkStringTable::GetUserDataSizeBits(void)const
// Source: json
//------------------------------------------------------------------------------
vgui::DragDrop_t *__thiscall CNetworkStringTable::GetUserDataSizeBits(vgui::Panel *this)
{
  return this->m_pDragDrop;
}

//------------------------------------------------------------------------------
// Address: 0x101C8360
// Name: __CreateCNetworkStringTableContainerINetworkStringTableContainer_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CNetworkStringTableContainer *__cdecl _CreateCNetworkStringTableContainerINetworkStringTableContainer_interface()
{
  return &s_NetworkStringTableClient;
}

} // namespace engine_xlsp
