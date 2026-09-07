// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/layout_system/tilegen_expressions.cpp
// Functions: 30
// ============================================================

#include "missionchooser\layout_system\tilegen_expressions.h"

//------------------------------------------------------------------------------
// Address: 0x1001A620
// Name: char __near * MemAlloc_StrDup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl MemAlloc_StrDup(const char *pString)
{
  char *result; // eax

  if ( pString == nullptr )
    return nullptr;
  result = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pString) + 1);
  if ( result == nullptr )
    return nullptr;
  strcpy(result, pString);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001A670
// Name: public: virtual char const __near * CTilegenExpression_StringConcatenate::DirectEvaluate(class CFreeVariableMap __near *,char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_StringConcatenate::DirectEvaluate(
        CTilegenExpression_StringConcatenate *this,
        CFreeVariableMap *pContext,
        const char **param1,
        const char **param2)
{
  char buf[64]; // [esp+0h] [ebp-40h] BYREF

  V_strncpy(pDest: buf, pSrc: *param1, maxLen: 64);
  V_strncat(pDest: buf, pSrc: *param2, destBufferSize: 0x40u, max_chars_to_copy: -1);
  buf[63] = 0;
  return CStringPool::Allocate(this: &pContext->m_StringPool, pszValue: buf);
}

//------------------------------------------------------------------------------
// Address: 0x1001A6C0
// Name: public: virtual char const __near * CTilegenExpression_RoomName::DirectEvaluate(class CFreeVariableMap __near *,class CRoomTemplate const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CTilegenExpression_RoomName::DirectEvaluate(
        CTilegenExpression_RoomName *this,
        CFreeVariableMap *pContext,
        const CRoomTemplate *const *pRoomTemplate)
{
  if ( *pRoomTemplate != nullptr )
    return (*pRoomTemplate)->m_FullName;
  else
    return (char *)szDescription;
}

//------------------------------------------------------------------------------
// Address: 0x1001A6E0
// Name: public: virtual int CTilegenExpression_RoomArea::DirectEvaluate(class CFreeVariableMap __near *,class CRoomTemplate const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTilegenExpression_RoomArea::DirectEvaluate(
        CTilegenExpression_RoomArea *this,
        CFreeVariableMap *pContext,
        const CRoomTemplate *const *pRoomTemplate)
{
  if ( *pRoomTemplate != nullptr )
    return (*pRoomTemplate)->m_nTilesX * (*pRoomTemplate)->m_nTilesY;
  else
    return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001A710
// Name: public: virtual char const __near * CTilegenExpression_ExtractRoomName::DirectEvaluate(class CFreeVariableMap __near *,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_ExtractRoomName::DirectEvaluate(
        CTilegenExpression_ExtractRoomName *this,
        CFreeVariableMap *pContext,
        const char **pFullRoomName)
{
  char themeName[64]; // [esp+4h] [ebp-80h] BYREF
  char roomName[64]; // [esp+44h] [ebp-40h] BYREF

  if ( CLevelTheme::SplitThemeAndRoom(
         pszFullName: *pFullRoomName,
         szThemeOut: themeName,
         nThemeOutSize: 64,
         szRoomOut: roomName,
         nRoomOutSize: 64) != 0 )
    return CStringPool::Allocate(this: &pContext->m_StringPool, pszValue: roomName);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
    _LoggingSystem_Log(
      a1: LOG_TilegenLayoutSystem,
      a2: 1,
      a3: "Could not split theme name from room (full name: %s).\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001A790
// Name: public: virtual char const __near * CTilegenExpression_ExtractThemeName::DirectEvaluate(class CFreeVariableMap __near *,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTilegenExpression_ExtractThemeName::DirectEvaluate(
        CTilegenExpression_ExtractThemeName *this,
        CFreeVariableMap *pContext,
        const char **pFullRoomName)
{
  char roomName[64]; // [esp+4h] [ebp-80h] BYREF
  char themeName[64]; // [esp+44h] [ebp-40h] BYREF

  if ( CLevelTheme::SplitThemeAndRoom(
         pszFullName: *pFullRoomName,
         szThemeOut: themeName,
         nThemeOutSize: 64,
         szRoomOut: roomName,
         nRoomOutSize: 64) != 0 )
    return CStringPool::Allocate(this: &pContext->m_StringPool, pszValue: themeName);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
    _LoggingSystem_Log(
      a1: LOG_TilegenLayoutSystem,
      a2: 1,
      a3: "Could not split theme name from room (full name: %s).\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001A810
// Name: public: virtual class CRoom const __near * CTilegenExpression_SourceRoomFromExit::DirectEvaluate(class CFreeVariableMap __near *,class CExit const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
const CRoom *__thiscall CTilegenExpression_SourceRoomFromExit::DirectEvaluate(
        CTilegenExpression_SourceRoomFromExit *this,
        CFreeVariableMap *pContext,
        const CExit *const *pExit)
{
  if ( *pExit != nullptr )
    return (*pExit)->pSourceRoom;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001A830
// Name: public: virtual class CRoomTemplate const __near * CTilegenExpression_SourceRoomTemplateFromExit::DirectEvaluate(class CFreeVariableMap __near *,class CExit const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
const CRoomTemplate *__thiscall CTilegenExpression_SourceRoomTemplateFromExit::DirectEvaluate(
        CTilegenExpression_SourceRoomTemplateFromExit *this,
        CFreeVariableMap *pContext,
        const CExit *const *pExit)
{
  if ( *pExit != nullptr )
    return (*pExit)->pSourceRoom->m_pRoomTemplate;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001A850
// Name: public: virtual bool CTilegenExpression_ChokepointGrowSource::DirectEvaluate(class CFreeVariableMap __near *,class CExit const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenExpression_ChokepointGrowSource::DirectEvaluate(
        CTilegenExpression_ChokepointGrowSource *this,
        CFreeVariableMap *pContext,
        const CExit *const *pExit)
{
  return *pExit != nullptr && (*pExit)->m_bChokepointGrowSource;
}

//------------------------------------------------------------------------------
// Address: 0x1001A870
// Name: public: virtual int CTilegenExpression_RoomChildCount::DirectEvaluate(class CFreeVariableMap __near *,class CRoom const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTilegenExpression_RoomChildCount::DirectEvaluate(
        CTilegenExpression_RoomChildCount *this,
        CFreeVariableMap *pContext,
        const CRoom *const *pRoom)
{
  if ( *pRoom != nullptr )
    return (*pRoom)->m_iNumChildren;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001A890
// Name: public: virtual class CRoomTemplate const __near * CTilegenExpression_RoomTemplateFromName::DirectEvaluate(class CFreeVariableMap __near *,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
const CRoomTemplate *__thiscall CTilegenExpression_RoomTemplateFromName::DirectEvaluate(
        CTilegenExpression_RoomTemplateFromName *this,
        CFreeVariableMap *pContext,
        const char **pName)
{
  CLevelTheme *Theme; // eax
  char roomName[64]; // [esp+4h] [ebp-80h] BYREF
  char themeName[64]; // [esp+44h] [ebp-40h] BYREF

  if ( CLevelTheme::SplitThemeAndRoom(
         pszFullName: *pName,
         szThemeOut: themeName,
         nThemeOutSize: 64,
         szRoomOut: roomName,
         nRoomOutSize: 64) == 0 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_TilegenLayoutSystem,
        a2: 1,
        a3: "Could not split theme name from room (full name: %s).\n");
    return nullptr;
  }
  Theme = CLevelTheme::FindTheme(szThemeName: themeName);
  if ( Theme != nullptr )
    return CLevelTheme::FindRoom(this: Theme, szRoomTemplate: roomName);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) == 0 )
    return nullptr;
  _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Could not find theme '%s'.\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001A950
// Name: public: virtual int CTilegenExpression_XPosition::DirectEvaluate(class CFreeVariableMap __near *,class CRoomCandidate const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTilegenExpression_XPosition::DirectEvaluate(
        CTilegenExpression_XPosition *this,
        CFreeVariableMap *pContext,
        const CRoomCandidate *const *pRoomCandidate)
{
  if ( *pRoomCandidate != nullptr )
    return (*pRoomCandidate)->m_iXPos;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1001A970
// Name: public: virtual bool CTilegenExpression_HasTag::Evaluate(class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenExpression_HasTag::Evaluate(CTilegenExpression_HasTag *this, CFreeVariableMap *pContext)
{
  CRoomTemplate *v3; // edi
  const char *v4; // eax

  v3 = (CRoomTemplate *)this->m_pRoomTemplateExpression->Evaluate(this: this->m_pRoomTemplateExpression, a2: pContext);
  if ( v3 == nullptr )
    return false;
  v4 = this->m_pTagExpression->Evaluate(this: this->m_pTagExpression, a2: pContext);
  return CRoomTemplate::HasTag(this: v3, szTag: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1001A9B0
// Name: public: virtual bool CTilegenExpression_CanPlaceRandomly::Evaluate(class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenExpression_CanPlaceRandomly::Evaluate(
        CTilegenExpression_CanPlaceRandomly *this,
        CFreeVariableMap *pContext)
{
  CRoomTemplate *v2; // eax

  v2 = (CRoomTemplate *)this->m_pRoomTemplateExpression->Evaluate(this: this->m_pRoomTemplateExpression, a2: pContext);
  return !CRoomTemplate::ShouldOnlyPlaceByRequest(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1001A9E0
// Name: public: virtual char const __near * CTilegenExpression_ExitTag::DirectEvaluate(class CFreeVariableMap __near *,class CExit const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CTilegenExpression_ExitTag::DirectEvaluate(
        CTilegenExpression_ExitTag *this,
        CFreeVariableMap *pContext,
        const CExit *const *pExit)
{
  if ( *pExit != nullptr )
    return (*pExit)->m_szExitTag;
  else
    return (char *)szDescription;
}

//------------------------------------------------------------------------------
// Address: 0x1001AA00
// Name: public: virtual int CTilegenExpression_ExitDirection::DirectEvaluate(class CFreeVariableMap __near *,class CExit const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
ExitDirection_t __thiscall CTilegenExpression_ExitDirection::DirectEvaluate(
        CTilegenExpression_ExitDirection *this,
        CFreeVariableMap *pContext,
        const CExit *const *pExit)
{
  if ( *pExit != nullptr )
    return (*pExit)->ExitDirection;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1001AA20
// Name: public: virtual class CTilegenState const __near * CTilegenExpression_ParentState::DirectEvaluate(class CFreeVariableMap __near *,class CTilegenState const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
const CTilegenState *__thiscall CTilegenExpression_ParentState::DirectEvaluate(
        CTilegenExpression_ParentState *this,
        CFreeVariableMap *pContext,
        const CTilegenState *const *pState)
{
  return (*pState)->m_pParentState;
}

//------------------------------------------------------------------------------
// Address: 0x1001AA30
// Name: public: virtual char const __near * CTilegenExpression_StateName::DirectEvaluate(class CFreeVariableMap __near *,class CTilegenState const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CTilegenExpression_StateName::DirectEvaluate(
        CTilegenExpression_StateName *this,
        CFreeVariableMap *pContext,
        const CTilegenState *const *pState)
{
  return (*pState)->m_StateName;
}

//------------------------------------------------------------------------------
// Address: 0x1001AA40
// Name: public: CTilegenExpression_HasTag::CTilegenExpression_HasTag(class ITilegenExpression<class CRoomTemplate const __near *> __near *,class ITilegenExpression<char const __near *> __near *)
// Source: json
//------------------------------------------------------------------------------
CTilegenExpression_HasTag *__thiscall CTilegenExpression_HasTag::CTilegenExpression_HasTag(
        CTilegenExpression_HasTag *this,
        ITilegenExpression<CRoomTemplate const *> *pRoomTemplateExpression,
        ITilegenExpression<char const *> *pTagExpression)
{
  this->__vftable = (CTilegenExpression_HasTag_vtbl *)&CTilegenExpression_HasTag::`vftable';
  this->m_pRoomTemplateExpression = pRoomTemplateExpression;
  this->m_pTagExpression = pTagExpression;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001AA60
// Name: public: CTilegenExpression_CanPlaceRandomly::CTilegenExpression_CanPlaceRandomly(class ITilegenExpression<class CRoomTemplate const __near *> __near *)
// Source: json
//------------------------------------------------------------------------------
CTilegenExpression_CanPlaceRandomly *__thiscall CTilegenExpression_CanPlaceRandomly::CTilegenExpression_CanPlaceRandomly(
        CTilegenExpression_CanPlaceRandomly *this,
        ITilegenExpression<CRoomTemplate const *> *pRoomTemplateExpression)
{
  this->__vftable = (CTilegenExpression_CanPlaceRandomly_vtbl *)&CTilegenExpression_CanPlaceRandomly::`vftable';
  this->m_pRoomTemplateExpression = pRoomTemplateExpression;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001B7C0
// Name: public: void __near * CFreeVariableMap::GetFreeVariableOrNULL(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFreeVariableMap::GetFreeVariableOrNULL(CFreeVariableMap *this, const char *pName)
{
  int v3; // eax
  CUtlMap<char const *,void *,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  if ( pName != nullptr
    && (search.key = pName,
        (v3 = CUtlRBTree<CUtlMap<char const *,void *,int>::Node_t,int,CUtlMap<char const *,void *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,void *,int>::Node_t,int>,int>>::Find(
                this: &this->m_Elements.m_Tree,
                &search)) != -1) )
  {
    return this->m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B800
// Name: public: void __near * CFreeVariableMap::GetFreeVariableDisallowNULL(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CFreeVariableMap::GetFreeVariableDisallowNULL(CFreeVariableMap *this, const char *pName)
{
  int v3; // eax
  int v4; // eax
  CLayoutSystem *v5; // ecx
  void *elem; // ebx
  int v8; // eax
  CLayoutSystem *v9; // ecx
  CUtlMap<char const *,void *,int>::Node_t search; // [esp+8h] [ebp-8h] BYREF

  if ( pName != nullptr
    && (search.key = pName,
        (v3 = CUtlRBTree<CUtlMap<char const *,void *,int>::Node_t,int,CUtlMap<char const *,void *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,void *,int>::Node_t,int>,int>>::Find(
                this: &this->m_Elements.m_Tree,
                &search)) != -1) )
  {
    elem = this->m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
    if ( elem == nullptr )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_TilegenLayoutSystem,
          a2: 1,
          a3: "Free variable '%s' found, but value is NULL or 0.\n");
      search.key = "LayoutSystem";
      v8 = CUtlRBTree<CUtlMap<char const *,void *,int>::Node_t,int,CUtlMap<char const *,void *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,void *,int>::Node_t,int>,int>>::Find(
             this: &this->m_Elements.m_Tree,
             &search);
      if ( v8 != -1 )
      {
        v9 = (CLayoutSystem *)this->m_Elements.m_Tree.m_Elements.m_pMemory[v8].m_Data.elem;
        if ( v9 != nullptr )
          CLayoutSystem::OnError(this: v9);
      }
    }
    return elem;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Free variable '%s' not found.\n");
    search.key = "LayoutSystem";
    v4 = CUtlRBTree<CUtlMap<char const *,void *,int>::Node_t,int,CUtlMap<char const *,void *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,void *,int>::Node_t,int>,int>>::Find(
           this: &this->m_Elements.m_Tree,
           &search);
    if ( v4 != -1 )
    {
      v5 = (CLayoutSystem *)this->m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
      if ( v5 != nullptr )
        CLayoutSystem::OnError(this: v5);
    }
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B900
// Name: public: virtual class CRoom const __near * CTilegenExpression_LastPlacedRoom::Evaluate(class CFreeVariableMap __near *)
// Source: json
//------------------------------------------------------------------------------
const CRoom *__thiscall CTilegenExpression_LastPlacedRoom::Evaluate(
        CTilegenExpression_LastPlacedRoom *this,
        CFreeVariableMap *pContext)
{
  _DWORD *FreeVariableDisallowNULL; // eax
  int v3; // ecx

  FreeVariableDisallowNULL = CFreeVariableMap::GetFreeVariableDisallowNULL(this: pContext, pName: "MapLayout");
  v3 = FreeVariableDisallowNULL[9];
  if ( v3 <= 0 )
    return nullptr;
  else
    return *(const CRoom **)(FreeVariableDisallowNULL[6] + 4 * v3 - 4);
}

//------------------------------------------------------------------------------
// Address: 0x1001B930
// Name: public: virtual bool CTilegenExpression_HasTag::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTilegenExpression_HasTag::LoadFromKeyValues(CTilegenExpression_HasTag *this, KeyValues *pKeyValues)
{
  const char *v3; // eax
  char v4; // bl
  const char *v5; // eax

  v3 = this->GetTypeName(this);
  v4 = CreateFromKeyValuesBlock<ITilegenExpression<CRoomTemplate const *>>(
         pParentKV: pKeyValues,
         pKeyName: "room_template",
         pParentClassName: v3,
         ppClass: &this->m_pRoomTemplateExpression,
         bOptional: false,
         bCreateEmptyInstance: false)
     & 1;
  v5 = this->GetTypeName(this);
  return v4
       & CreateFromKeyValuesBlock<ITilegenExpression<char const *>>(
           pParentKV: pKeyValues,
           pKeyName: "tag",
           pParentClassName: v5,
           ppClass: &this->m_pTagExpression,
           bOptional: false,
           bCreateEmptyInstance: false);
}

//------------------------------------------------------------------------------
// Address: 0x1001B990
// Name: public: virtual bool CTilegenExpression_CanPlaceRandomly::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTilegenExpression_CanPlaceRandomly::LoadFromKeyValues(
        CTilegenExpression_CanPlaceRandomly *this,
        KeyValues *pKeyValues)
{
  const char *v3; // eax

  v3 = this->GetTypeName(this);
  return CreateFromKeyValuesBlock<ITilegenExpression<CRoomTemplate const *>>(
           pParentKV: pKeyValues,
           pKeyName: "room_template",
           pParentClassName: v3,
           ppClass: &this->m_pRoomTemplateExpression,
           bOptional: false,
           bCreateEmptyInstance: false);
}

//------------------------------------------------------------------------------
// Address: 0x1001B9C0
// Name: public: virtual int CTilegenExpression_NumTimesPlaced::DirectEvaluate(class CFreeVariableMap __near *,class CRoomTemplate const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTilegenExpression_NumTimesPlaced::DirectEvaluate(
        CTilegenExpression_NumTimesPlaced *this,
        CFreeVariableMap *pContext,
        const CRoomTemplate *const *pRoomTemplate)
{
  _DWORD *FreeVariableDisallowNULL; // ecx
  int v4; // edx
  int result; // eax
  int v6; // ecx

  FreeVariableDisallowNULL = CFreeVariableMap::GetFreeVariableDisallowNULL(this: pContext, pName: "MapLayout");
  v4 = FreeVariableDisallowNULL[9];
  result = 0;
  if ( v4 > 0 )
  {
    v6 = FreeVariableDisallowNULL[6];
    do
    {
      if ( *(const CRoomTemplate *const *)(*(_DWORD *)v6 + 12) == *pRoomTemplate )
        ++result;
      v6 += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001BA00
// Name: public: int CUtlMap<char const __near *,void __near *,int>::Insert(char const __near * const __near &,void __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,void *,int>::Insert(
        CUtlMap<char const *,void *,int> *this,
        const char **key,
        int insert)
{
  void *v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,void *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,void *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(void **)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,void *,int>::Node_t,int,CUtlMap<char const *,void *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,void *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CUtlMap<char const *,void *,int>::Node_t,int,CUtlMap<char const *,void *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,void *,int>::Node_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<CUtlMap<char const *,void *,int>::Node_t,int,CUtlMap<char const *,void *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,void *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,void *,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1001BA80
// Name: public: int CUtlDict<void __near *,int>::Insert(char const __near *,void __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<void *,int>::Insert(CUtlDict<void *,int> *this, char *pName, void *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,void *,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x1001BAE0
// Name: public: void CFreeVariableMap::SetOrCreateFreeVariable(char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFreeVariableMap::SetOrCreateFreeVariable(CFreeVariableMap *this, char *pName, void *pValue)
{
  int v4; // eax
  CUtlMap<char const *,void *,int>::Node_t search; // [esp+8h] [ebp-8h] BYREF

  if ( pName == nullptr
    || (search.key = pName,
        (v4 = CUtlRBTree<CUtlMap<char const *,void *,int>::Node_t,int,CUtlMap<char const *,void *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,void *,int>::Node_t,int>,int>>::Find(
                this: &this->m_Elements.m_Tree,
                &search)) == -1) )
  {
    CUtlDict<void *,int>::Insert(this, pName, element: &pValue);
  }
  else
  {
    this->m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem = pValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084B10
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,void __near *,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,void *,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}
