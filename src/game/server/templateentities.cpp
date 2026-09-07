// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/templateentities.cpp
// Functions: 24
// ============================================================

#include "game\server\templateentities.h"

//------------------------------------------------------------------------------
// Address: 0x10231A50
// Name: class ISaveRestoreBlockHandler __near * GetTemplateSaveRestoreBlockHandler(void)
// Source: json
//------------------------------------------------------------------------------
CTemplate_SaveRestoreBlockHandler *__cdecl GetTemplateSaveRestoreBlockHandler()
{
  return &g_Template_SaveRestoreBlockHandler;
}

//------------------------------------------------------------------------------
// Address: 0x10231A60
// Name: void Templates_StartUniqueInstance(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Templates_StartUniqueInstance()
{
  unsigned int v0; // kr00_4
  float v1; // xmm1_4
  unsigned int v2; // eax
  float v3; // xmm0_4

  ++g_iCurrentTemplateInstance;
  v0 = strlen(ENTITYIO_FIXUP_STRING);
  v1 = 10.0;
  v2 = v0 - 1;
  if ( (int)(v0 - 1) < 0 )
    v2 = 1 - v0;
  v3 = 1.0;
  while ( 1 )
  {
    if ( (v2 & 1) != 0 )
      v3 = v3 * v1;
    v2 >>= 1;
    if ( v2 == 0 )
      break;
    v1 = v1 * v1;
  }
  if ( (int)(v0 - 1) < 0 )
    v3 = 1.0 / v3;
  if ( g_iCurrentTemplateInstance >= (int)v3 )
    g_iCurrentTemplateInstance = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10231B70
// Name: bool Templates_IndexRequiresEntityIOFixup(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Templates_IndexRequiresEntityIOFixup(int iIndex)
{
  return g_Templates.m_Memory.m_pMemory[iIndex]->bNeedsEntityIOFixup;
}

//------------------------------------------------------------------------------
// Address: 0x10231B90
// Name: struct string_t Templates_FindByIndex(int)
// Source: json
//------------------------------------------------------------------------------
string_t __cdecl Templates_FindByIndex(const char **iIndex, int iIndexa)
{
  int v2; // edi
  TemplateEntityData_t *v3; // ecx
  TemplateEntityData_t **v4; // esi

  v2 = iIndexa;
  v3 = g_Templates.m_Memory.m_pMemory[iIndexa];
  if ( v3->iszMapData.pszValue == nullptr )
  {
    v4 = &g_Templates.m_Memory.m_pMemory[iIndexa];
    (*v4)->iszMapData.pszValue = *(const char **)AllocPooledString(
                                                   pszValue: (char *)&iIndexa,
                                                   pszValuea: v3->pszMapData).pszValue;
  }
  *iIndex = g_Templates.m_Memory.m_pMemory[v2]->iszMapData.pszValue;
  return (string_t)iIndex;
}

//------------------------------------------------------------------------------
// Address: 0x10231BE0
// Name: int Templates_GetStringSize(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Templates_GetStringSize(int iIndex)
{
  return g_Templates.m_Memory.m_pMemory[iIndex]->iMapDataLength;
}

//------------------------------------------------------------------------------
// Address: 0x10231C00
// Name: char __near * Templates_GetEntityIOFixedMapData(int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Templates_GetEntityIOFixedMapData(int iIndex)
{
  TemplateEntityData_t *v1; // ecx
  signed int v2; // edi
  char *v3; // ebx
  unsigned __int8 *pszFixedMapData; // esi
  int v5; // eax
  char v6; // cl

  v1 = g_Templates.m_Memory.m_pMemory[iIndex];
  if ( v1->pszFixedMapData == nullptr )
  {
    g_Templates.m_Memory.m_pMemory[iIndex]->pszFixedMapData = (char *)operator new(nSize: v1->iMapDataLength);
    V_strncpy(
      pDest: g_Templates.m_Memory.m_pMemory[iIndex]->pszFixedMapData,
      pSrc: g_Templates.m_Memory.m_pMemory[iIndex]->pszMapData,
      maxLen: g_Templates.m_Memory.m_pMemory[iIndex]->iMapDataLength);
  }
  v2 = strlen(ENTITYIO_FIXUP_STRING);
  v3 = (char *)operator new(nSize: v2 + 1);
  V_snprintf(pDest: v3, maxLen: v2 + 1, pFormat: "%c%.4d", *ENTITYIO_FIXUP_STRING, g_iCurrentTemplateInstance);
  pszFixedMapData = (unsigned __int8 *)g_Templates.m_Memory.m_pMemory[iIndex]->pszFixedMapData;
  do
  {
    if ( *pszFixedMapData == *ENTITYIO_FIXUP_STRING )
    {
      v5 = 1;
      if ( v2 <= 1 )
      {
LABEL_9:
        memcpy(dst: pszFixedMapData, src: (unsigned __int8 *)v3, count: v2);
        pszFixedMapData += v2;
      }
      else
      {
        while ( 1 )
        {
          v6 = pszFixedMapData[v5];
          if ( v6 < 48 || v6 > 57 )
            break;
          if ( ++v5 >= v2 )
            goto LABEL_9;
        }
      }
    }
    ++pszFixedMapData;
  }
  while ( *pszFixedMapData != 0 );
  free(pMem: v3);
  return g_Templates.m_Memory.m_pMemory[iIndex]->pszFixedMapData;
}

//------------------------------------------------------------------------------
// Address: 0x10231D00
// Name: void Templates_RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall Templates_RemoveAll(TemplateEntityData_t *a1@<esi>)
{
  int v1; // edi
  int m_Size; // ebx
  TemplateEntityData_t *v3; // esi

  v1 = 0;
  m_Size = g_Templates.m_Size;
  if ( g_Templates.m_Size <= 0 )
  {
    g_Templates.m_Size = 0;
  }
  else
  {
    do
    {
      v3 = g_Templates.m_Memory.m_pMemory[v1];
      ((void (__thiscall *)(IMemAlloc *, const char *, TemplateEntityData_t *))_g_pMemAlloc->Free_2)(
        a1: _g_pMemAlloc,
        a2: v3->pszName,
        a3: a1);
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->pszMapData);
      if ( v3->pszFixedMapData != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->pszFixedMapData);
      a1 = v3;
      ((void (__thiscall *)(IMemAlloc *))_g_pMemAlloc->Free_2)(a1: _g_pMemAlloc);
      ++v1;
    }
    while ( v1 < m_Size );
    g_Templates.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10231D80
// Name: public: virtual void CTemplatesHook::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __usercall CTemplatesHook::LevelShutdownPostEntity(CTemplatesHook *this@<ecx>, TemplateEntityData_t *a1@<esi>)
{
  Templates_RemoveAll(a1);
}

//------------------------------------------------------------------------------
// Address: 0x10231D90
// Name: public: virtual char const __near * CTemplate_SaveRestoreBlockHandler::GetBlockName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTemplate_SaveRestoreBlockHandler::GetBlockName(CTemplate_SaveRestoreBlockHandler *this)
{
  return "Templates";
}

//------------------------------------------------------------------------------
// Address: 0x10231DA0
// Name: public: virtual void CTemplate_SaveRestoreBlockHandler::WriteSaveHeaders(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTemplate_SaveRestoreBlockHandler::WriteSaveHeaders(
        CTemplate_SaveRestoreBlockHandler *this,
        ISave *pSave)
{
  pSave->WriteShort_2(this: pSave, a2: &TEMPLATE_SAVE_RESTORE_VERSION, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10231DC0
// Name: public: virtual void CTemplate_SaveRestoreBlockHandler::ReadRestoreHeaders(class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTemplate_SaveRestoreBlockHandler::ReadRestoreHeaders(
        CTemplate_SaveRestoreBlockHandler *this,
        IRestore *pRestore)
{
  pRestore->ReadShort(this: pRestore, a2: (__int16 *)&pRestore, a3: 1, a4: 0);
  this->m_fDoLoad = (_WORD)pRestore == (unsigned __int16)TEMPLATE_SAVE_RESTORE_VERSION;
}

//------------------------------------------------------------------------------
// Address: 0x10231DF0
// Name: public: virtual void CTemplate_SaveRestoreBlockHandler::Save(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTemplate_SaveRestoreBlockHandler::Save(CTemplate_SaveRestoreBlockHandler *this, ISave *pSave)
{
  ISave *v2; // esi
  void (__thiscall *WriteShort_2)(ISave *, const __int16 *, int); // edx
  int i; // ebx
  TemplateEntityData_t *v5; // edi

  v2 = pSave;
  pSave->WriteInt_2(this: pSave, a2: &g_iCurrentTemplateInstance, a3: 1);
  WriteShort_2 = v2->WriteShort_2;
  pSave = (ISave *)LOWORD(g_Templates.m_Size);
  WriteShort_2(this: v2, a2: (const __int16 *)&pSave, a3: 1);
  for ( i = 0; i < (__int16)pSave; ++i )
  {
    v5 = g_Templates.m_Memory.m_pMemory[i];
    v2->WriteAll(this: v2, a2: v5, a3: &TemplateEntityData_t::m_DataMap);
    v2->WriteString_4(this: v2, a2: v5->pszName);
    v2->WriteString_4(this: v2, a2: v5->pszMapData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10231E80
// Name: void Templates_RemoveByHammerID(int)
// Source: json
//------------------------------------------------------------------------------
void __usercall Templates_RemoveByHammerID(TemplateEntityData_t *a1@<esi>, int nHammerID)
{
  int i; // edi
  TemplateEntityData_t *v3; // esi

  for ( i = g_Templates.m_Size - 1; i >= 0; --i )
  {
    v3 = g_Templates.m_Memory.m_pMemory[i];
    if ( v3->m_nHammerID == nHammerID )
    {
      ((void (__thiscall *)(IMemAlloc *, const char *, TemplateEntityData_t *))_g_pMemAlloc->Free_2)(
        a1: _g_pMemAlloc,
        a2: v3->pszName,
        a3: a1);
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->pszMapData);
      if ( v3->pszFixedMapData != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->pszFixedMapData);
      a1 = v3;
      ((void (__thiscall *)(IMemAlloc *))_g_pMemAlloc->Free_2)(a1: _g_pMemAlloc);
      if ( g_Templates.m_Size - i - 1 > 0 )
        _V_memmove(
          dest: &g_Templates.m_Memory.m_pMemory[i],
          src: &g_Templates.m_Memory.m_pMemory[i + 1],
          count: 4 * (g_Templates.m_Size - i - 1));
      --g_Templates.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10231F40
// Name: int Templates_Add(class CBaseEntity __near *,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __usercall Templates_Add@<eax>(int a1@<ebx>, CBaseEntity *pEntity, char *pszMapData, int nLen, int nHammerID)
{
  const char *pszValue; // edi
  int v6; // esi
  unsigned int v7; // eax
  unsigned __int8 *v8; // eax
  int m_Size; // eax
  int v10; // edi
  TemplateEntityData_t **m_pMemory; // ecx
  int v12; // eax
  int *v13; // eax
  const char *v15; // eax

  pszValue = pEntity->m_iName.m_Value.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  if ( strlen(pszValue) != 0 )
  {
    v6 = ((int (__thiscall *)(IMemAlloc *, int, int))_g_pMemAlloc->Alloc_2)(a1: _g_pMemAlloc, a2: 28, a3: a1);
    *(_DWORD *)(v6 + 24) = nHammerID;
    *(_DWORD *)v6 = MemAlloc_StrDup(pString: pszValue);
    v7 = MapEntity_GetNumKeysInEntity(pEntData: pszMapData) * (strlen(ENTITYIO_FIXUP_STRING) + 1) + nLen + 1;
    *(_DWORD *)(v6 + 12) = v7;
    v8 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
    *(_DWORD *)(v6 + 4) = v8;
    memcpy(dst: v8, src: (unsigned __int8 *)pszMapData, count: nLen + 1);
    *(_BYTE *)(nLen + *(_DWORD *)(v6 + 4)) = 0;
    *(_DWORD *)(v6 + 8) = 0;
    *(_BYTE *)(v6 + 16) = 0;
    *(_DWORD *)(v6 + 20) = 0;
    m_Size = g_Templates.m_Size;
    v10 = g_Templates.m_Size;
    if ( g_Templates.m_Size + 1 > g_Templates.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&g_Templates,
        num: g_Templates.m_Size - g_Templates.m_Memory.m_nAllocationCount + 1);
      m_Size = g_Templates.m_Size;
    }
    m_pMemory = g_Templates.m_Memory.m_pMemory;
    g_Templates.m_Size = m_Size + 1;
    v12 = m_Size - v10;
    g_Templates.m_pElements = g_Templates.m_Memory.m_pMemory;
    if ( v12 > 0 )
    {
      _V_memmove(
        dest: &g_Templates.m_Memory.m_pMemory[v10 + 1],
        src: &g_Templates.m_Memory.m_pMemory[v10],
        count: 4 * v12);
      m_pMemory = g_Templates.m_Memory.m_pMemory;
    }
    v13 = (int *)&m_pMemory[v10];
    if ( v13 != nullptr )
      *v13 = v6;
    return v10;
  }
  else
  {
    v15 = pEntity->m_iClassname.pszValue;
    if ( v15 == nullptr )
      v15 = locale;
    _DevWarning(a1: 1, a2: "RegisterTemplateEntity: template entity with no name, class %s\n", v15);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10232080
// Name: public: virtual void CTemplate_SaveRestoreBlockHandler::Restore(class IRestore __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTemplate_SaveRestoreBlockHandler::Restore(
        CTemplate_SaveRestoreBlockHandler *this@<ecx>,
        char *a2@<ebx>,
        int a3@<edi>,
        TemplateEntityData_t *a4@<esi>,
        IRestore *pRestore,
        bool createPlayers)
{
  TemplateEntityData_t **m_pMemory; // eax
  __int16 v8; // ax
  TemplateEntityData_t *v9; // esi
  const char *v10; // eax
  const char *v11; // ebx
  char *v12; // ecx
  int v13; // eax
  char v14; // dl
  const char *v15; // eax
  char *v16; // eax
  int iMapDataLength; // ecx
  int m_Size; // eax
  int v19; // ebx
  TemplateEntityData_t **v20; // ecx
  int v21; // eax
  TemplateEntityData_t **v22; // ebx
  TemplateEntityData_t *v25; // [esp-4h] [ebp-804h]
  char szName[2048]; // [esp+0h] [ebp-800h] BYREF
  int iTemplates; // [esp+808h] [ebp+8h]

  if ( this->m_fDoLoad )
  {
    v25 = a4;
    Templates_RemoveAll(a1: a4);
    m_pMemory = g_Templates.m_Memory.m_pMemory;
    g_Templates.m_Size = 0;
    if ( g_Templates.m_Memory.m_nGrowSize >= 0 )
    {
      if ( g_Templates.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_Templates.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        g_Templates.m_Memory.m_pMemory = nullptr;
      }
      g_Templates.m_Memory.m_nAllocationCount = 0;
    }
    g_Templates.m_pElements = m_pMemory;
    g_iCurrentTemplateInstance = pRestore->ReadInt(this: pRestore);
    v8 = pRestore->ReadShort_2(this: pRestore);
    iTemplates = v8;
    while ( iTemplates != 0 )
    {
      --iTemplates;
      v9 = (TemplateEntityData_t *)((int (__thiscall *)(IMemAlloc *, int, char *, int, TemplateEntityData_t *))_g_pMemAlloc->Alloc_2)(
                                     a1: _g_pMemAlloc,
                                     a2: 28,
                                     a3: a2,
                                     a4: a3,
                                     a5: v25);
      pRestore->ReadAll(this: pRestore, a2: v9, a3: &TemplateEntityData_t::m_DataMap);
      pRestore->ReadString_2(this: pRestore, a2: szName, a3: 2048, a4: 0);
      v10 = (const char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(szName) + 1);
      v11 = v10;
      if ( v10 != nullptr )
      {
        v12 = szName;
        v13 = v10 - szName;
        do
        {
          v14 = *v12;
          v12[v13] = *v12;
          ++v12;
        }
        while ( v14 != 0 );
        v15 = v11;
      }
      else
      {
        v15 = nullptr;
      }
      v9->pszName = v15;
      v16 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v9->iMapDataLength);
      iMapDataLength = v9->iMapDataLength;
      v25 = nullptr;
      v9->pszMapData = v16;
      a3 = iMapDataLength;
      a2 = v16;
      ((void (__thiscall *)(IRestore *))pRestore->ReadString_2)(a1: pRestore);
      v9->pszFixedMapData = nullptr;
      m_Size = g_Templates.m_Size;
      v19 = g_Templates.m_Size;
      if ( g_Templates.m_Size + 1 > g_Templates.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&g_Templates,
          num: g_Templates.m_Size - g_Templates.m_Memory.m_nAllocationCount + 1);
        m_Size = g_Templates.m_Size;
      }
      v20 = g_Templates.m_Memory.m_pMemory;
      g_Templates.m_Size = m_Size + 1;
      v21 = m_Size - v19;
      g_Templates.m_pElements = g_Templates.m_Memory.m_pMemory;
      if ( v21 > 0 )
      {
        _V_memmove(
          dest: &g_Templates.m_Memory.m_pMemory[v19 + 1],
          src: &g_Templates.m_Memory.m_pMemory[v19],
          count: 4 * v21);
        v20 = g_Templates.m_Memory.m_pMemory;
      }
      v22 = &v20[v19];
      if ( v22 != nullptr )
        *v22 = v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102322B0
// Name: void Templates_ReconnectIOForGroup(class CPointTemplate __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Templates_ReconnectIOForGroup(CPointTemplate *pGroup)
{
  int NumTemplates; // eax
  grouptemplate_t *m_pMemory; // edi
  int v3; // ebx
  CEntityMapData *v4; // eax
  TemplateEntityData_t *v5; // ecx
  int iMapDataLength; // edx
  char *pszMapData; // ecx
  int v8; // esi
  grouptemplate_t *v9; // eax
  char *i; // edi
  CEntityMapData *pMapDataParser; // ecx
  int j; // esi
  int v13; // eax
  char *v14; // eax
  int v15; // eax
  int v16; // ecx
  int v17; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v18; // eax
  int v19; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v20; // ecx
  unsigned int v21; // eax
  unsigned __int8 v22; // bl
  int v23; // eax
  char *v24; // eax
  int v25; // ebx
  int v26; // esi
  int v27; // eax
  grouptemplate_t *v28; // ecx
  int v29; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v30; // edi
  grouptemplate_t *v31; // edi
  CEntityMapData *v32; // esi
  char *v33; // edi
  grouptemplate_t *v34; // ebx
  grouptemplate_t *v35; // esi
  char pSrc[2048]; // [esp+4h] [ebp-2074h] BYREF
  char keyName[2048]; // [esp+804h] [ebp-1874h] BYREF
  _DWORD v38[515]; // [esp+1004h] [ebp-1074h] BYREF
  char NewValue[2048]; // [esp+1810h] [ebp-868h] BYREF
  CUtlMap<char const *,int,int>::Node_t search; // [esp+2010h] [ebp-68h] BYREF
  int *p_elem; // [esp+2018h] [ebp-60h]
  CUtlMap<char const *,int,int>::Node_t insert; // [esp+201Ch] [ebp-5Ch] BYREF
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > v43; // [esp+2024h] [ebp-54h] BYREF
  CUtlMemory<grouptemplate_t,int> v44; // [esp+2048h] [ebp-30h] BYREF
  int v45; // [esp+2054h] [ebp-24h]
  grouptemplate_t *v46; // [esp+2058h] [ebp-20h]
  CEntityMapData *v47; // [esp+205Ch] [ebp-1Ch]
  char *k; // [esp+2060h] [ebp-18h]
  grouptemplate_t *v49; // [esp+2064h] [ebp-14h]
  char *v50; // [esp+2068h] [ebp-10h]
  int iTemplate; // [esp+206Ch] [ebp-Ch]
  int parent; // [esp+2070h] [ebp-8h] BYREF
  bool leftchild; // [esp+2077h] [ebp-1h] BYREF

  NumTemplates = CPointTemplate::GetNumTemplates(this: pGroup);
  m_pMemory = nullptr;
  v50 = (char *)NumTemplates;
  if ( NumTemplates != 0 )
  {
    v3 = 0;
    memset(&v44, 0, sizeof(v44));
    v45 = 0;
    v46 = nullptr;
    iTemplate = 0;
    if ( NumTemplates > 0 )
    {
      do
      {
        v38[513] = CPointTemplate::GetTemplateIndexForTemplate(this: pGroup, iTemplate);
        v4 = (CEntityMapData *)operator new(nSize: 0xCu);
        if ( v4 != nullptr )
        {
          v5 = g_Templates.m_Memory.m_pMemory[v38[513]];
          iMapDataLength = v5->iMapDataLength;
          pszMapData = v5->pszMapData;
          v4->m_pEntData = pszMapData;
          v4->m_nEntDataSize = iMapDataLength;
          v4->m_pCurrentKey = pszMapData;
        }
        else
        {
          v4 = nullptr;
        }
        v38[0] = v4;
        CEntityMapData::ExtractValue(this: v4, keyName: "targetname", value: (char *)&v38[1]);
        LOBYTE(v38[514]) = 0;
        v8 = v3;
        if ( v3 + 1 > v44.m_nAllocationCount )
        {
          CUtlMemory<grouptemplate_t,int>::Grow(this: &v44, num: v3 - v44.m_nAllocationCount + 1);
          v3 = v45;
          m_pMemory = v44.m_pMemory;
        }
        v45 = ++v3;
        v46 = m_pMemory;
        if ( v3 - v8 - 1 > 0 )
          _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 2060 * (v3 - v8 - 1));
        v9 = &m_pMemory[v8];
        if ( v9 != nullptr )
        {
          qmemcpy(v9, v38, sizeof(grouptemplate_t));
          m_pMemory = v44.m_pMemory;
        }
        ++iTemplate;
      }
      while ( iTemplate < (int)v50 );
    }
    if ( CPointTemplate::AllowNameFixup(this: pGroup) )
    {
      iTemplate = 0;
      if ( (int)v50 > 0 )
      {
        v49 = v44.m_pMemory;
        for ( i = nullptr; ; i = nullptr )
        {
          pMapDataParser = v49->pMapDataParser;
          memset(&v43.m_Elements, 0, sizeof(v43.m_Elements));
          v43.m_Root = -1;
          v43.m_NumElements = 0;
          v43.m_FirstFree = -1;
          v43.m_LastAlloc.index = -1;
          v43.m_pElements = nullptr;
          v43.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
          v47 = pMapDataParser;
          if ( CEntityMapData::GetFirstKey(this: pMapDataParser, keyName, value: pSrc) != 0 )
          {
            do
            {
              if ( _V_stricmp(s1: keyName, s2: "targetname") != 0 )
              {
                search.key = keyName;
                v13 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                        this: &v43,
                        &search);
                if ( v13 == -1 )
                {
                  v14 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(keyName) + 1);
                  if ( v14 != nullptr )
                    strcpy(v14, keyName);
                  else
                    v14 = nullptr;
                  insert.key = v14;
                  insert.elem = 0;
                  parent = -1;
                  leftchild = false;
                  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FindInsertionPosition(
                    this: &v43,
                    &insert,
                    &parent,
                    &leftchild);
                  v15 = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::NewNode(
                          this: (CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)&v43,
                          a2: i);
                  v16 = parent;
                  v17 = v15;
                  v18 = v43.m_Elements.m_pMemory;
                  v19 = v17;
                  v43.m_Elements.m_pMemory[v19].m_Parent = parent;
                  v18[v19].m_Right = -1;
                  v18[v19].m_Left = -1;
                  v18[v19].m_Tag = 0;
                  if ( v16 == -1 )
                  {
                    v43.m_Root = v17;
                  }
                  else if ( leftchild )
                  {
                    v18[v16].m_Left = v17;
                  }
                  else
                  {
                    v18[v16].m_Right = v17;
                  }
                  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::InsertRebalance(
                    this: &v43,
                    elem: v17);
                  ++v43.m_NumElements;
                  if ( &v43.m_Elements.m_pMemory[v19] != (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)-16 )
                    v43.m_Elements.m_pMemory[v19].m_Data = insert;
                  v13 = v17;
                }
                v20 = v43.m_Elements.m_pMemory;
                v21 = v13;
                ++v43.m_Elements.m_pMemory[v21].m_Data.elem;
                i = pSrc;
                p_elem = &v20[v21].m_Data.elem;
                v22 = 27;
                strchr(string: pSrc, chr: 0x1Bu);
                if ( v23 == 0 )
                  v22 = 44;
                strchr(string: pSrc, chr: v22);
                k = v24;
                if ( v24 != nullptr )
                {
                  V_strncpy(pDest: (char *)&v38[3], pSrc, maxLen: v24 - pSrc + 1);
                  i = (char *)&v38[3];
                }
                v25 = 0;
                parent = (int)&v44.m_pMemory->bChangeTargetname;
                do
                {
                  if ( _V_stricmp(s1: (const char *)(parent - 2052), s2: i) == 0 )
                  {
                    if ( template_debug.m_pParent != nullptr && template_debug.m_pParent->m_Value.m_nValue != 0 )
                      _Msg(
                        a1: "Template Connection Found: Key %s (\"%s\") in entity named \"%s\"(%d) matches entity %d's targetname\n",
                        keyName,
                        i,
                        v49->pszName,
                        iTemplate,
                        v25);
                    v26 = *p_elem - 1;
                    if ( k != nullptr )
                    {
                      V_strncpy(pDest: NewValue, pSrc: (const char *)&v38[3], maxLen: 2048);
                      V_strncat(
                        pDest: NewValue,
                        pSrc: ENTITYIO_FIXUP_STRING,
                        destBufferSize: 0x800u,
                        max_chars_to_copy: -1);
                      V_strncat(pDest: NewValue, pSrc: k, destBufferSize: 0x800u, max_chars_to_copy: -1);
                    }
                    else
                    {
                      V_strncpy(pDest: NewValue, pSrc: i, maxLen: 2048);
                      V_strncat(
                        pDest: NewValue,
                        pSrc: ENTITYIO_FIXUP_STRING,
                        destBufferSize: 0x800u,
                        max_chars_to_copy: -1);
                    }
                    CEntityMapData::SetValue(this: v47, keyName, NewValue, nKeyInstance: v26);
                    v27 = parent;
                    v28 = v49;
                    *(_BYTE *)parent = 1;
                    g_Templates.m_Memory.m_pMemory[v28->iIndex]->bNeedsEntityIOFixup = true;
                    g_Templates.m_Memory.m_pMemory[*(_DWORD *)(v27 - 4)]->bNeedsEntityIOFixup = true;
                  }
                  parent += 2060;
                  ++v25;
                }
                while ( v25 < (int)v50 );
              }
            }
            while ( CEntityMapData::GetNextKey(this: v47, keyName, value: pSrc) != 0 );
            v29 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &v43);
            if ( v29 != -1 )
            {
              v30 = v43.m_Elements.m_pMemory;
              do
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v30[v29].m_Data.key);
                v29 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
                        this: &v43,
                        i: v29);
              }
              while ( v29 != -1 );
            }
            CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &v43);
            CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &v43);
            if ( v43.m_Elements.m_nGrowSize >= 0 && v43.m_Elements.m_pMemory != nullptr )
LABEL_56:
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v43.m_Elements.m_pMemory);
          }
          else
          {
            for ( j = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &v43);
                  j != -1;
                  j = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
                        this: &v43,
                        i: j) )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(24 * j + 0x10));
            }
            CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &v43);
            CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &v43);
            if ( v43.m_Elements.m_nGrowSize >= 0 && v43.m_Elements.m_pMemory != nullptr )
              goto LABEL_56;
          }
          ++v49;
          if ( ++iTemplate >= (int)v50 )
            break;
        }
      }
      if ( (int)v50 > 0 )
      {
        v31 = v44.m_pMemory;
        for ( k = v50; k != nullptr; --k )
        {
          if ( v31->bChangeTargetname )
          {
            v32 = v31->pMapDataParser;
            CEntityMapData::ExtractValue(this: v31->pMapDataParser, keyName: "targetname", value: NewValue);
            V_strncat(pDest: NewValue, pSrc: ENTITYIO_FIXUP_STRING, destBufferSize: 0x800u, max_chars_to_copy: -1);
            CEntityMapData::SetValue(this: v32, keyName: "targetname", NewValue, nKeyInstance: 0);
          }
          ++v31;
        }
      }
    }
    v33 = v50;
    v34 = v44.m_pMemory;
    if ( (int)v50 > 0 )
    {
      v35 = v44.m_pMemory;
      do
      {
        free(pMem: v35->pMapDataParser);
        ++v35;
        --v33;
      }
      while ( v33 != nullptr );
    }
    if ( v44.m_nGrowSize >= 0 && v34 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v34);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040B370
// Name: _dynamic_initializer_for__template_debug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__template_debug__()
{
  ConVar::ConVar(this: &template_debug, pName: "template_debug", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__template_debug__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B3A0
// Name: TemplateEntityData_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *TemplateEntityData_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<TemplateEntityData_t>();
  TemplateEntityData_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041E6D0
// Name: _dynamic_atexit_destructor_for__template_debug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__template_debug__()
{
  ConVar::~ConVar(this: &template_debug);
}

//------------------------------------------------------------------------------
// Address: 0x1040B3B0
// Name: _dynamic_initializer_for__g_Templates__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Templates__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Templates__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B3C0
// Name: _dynamic_initializer_for__g_TemplateEntityHook__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TemplateEntityHook__()
{
  CAutoGameSystem::CAutoGameSystem(this: &g_TemplateEntityHook, name: "CTemplatesHook");
  g_TemplateEntityHook.__vftable = (CTemplatesHook_vtbl *)&CTemplatesHook::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_TemplateEntityHook__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E6E0
// Name: _dynamic_atexit_destructor_for__g_TemplateEntityHook__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TemplateEntityHook__()
{
  IGameSystem::~IGameSystem(this: &g_TemplateEntityHook);
}

//------------------------------------------------------------------------------
// Address: 0x1041E6F0
// Name: _DataMapInit_TemplateEntityData_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_TemplateEntityData_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_415);
}

//------------------------------------------------------------------------------
// Address: 0x1041E700
// Name: _dynamic_atexit_destructor_for__g_Templates__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Templates__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_Templates);
}
