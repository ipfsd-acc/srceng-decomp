// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/scriptobject.cpp
// Functions: 22
// ============================================================

#include "game\client\cstrike15\gameui\scriptobject.h"

//------------------------------------------------------------------------------
// Address: 0x101E6B70
// Name: void StripFloatTrailingZeros(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl StripFloatTrailingZeros(char *str)
{
  unsigned int v1; // eax
  char *i; // ecx

  strchr(string: (unsigned __int8 *)str, chr: 0x2Eu);
  if ( v1 != 0 )
  {
    for ( i = &str[strlen(str) - 1]; (unsigned int)i > v1; *i-- = 0 )
    {
      if ( *i != 48 )
        break;
    }
    if ( *i == 46 )
      *i = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6BC0
// Name: public: mpcontrol_t::mpcontrol_t(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
mpcontrol_t *__thiscall mpcontrol_t::mpcontrol_t(mpcontrol_t *this, vgui::Panel *parent, const char *panelName)
{
  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (mpcontrol_t_vtbl *)&mpcontrol_t::`vftable';
  this->type = O_BADTYPE;
  this->pControl = nullptr;
  this->pPrompt = nullptr;
  this->pScrObj = nullptr;
  this->next = nullptr;
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101E6C10
// Name: public: virtual void mpcontrol_t::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mpcontrol_t::OnSizeChanged(mpcontrol_t *this, int wide, int tall)
{
  bool v4; // zf
  vgui::Panel *pControl; // ecx
  int v6; // esi

  v4 = this->pPrompt == nullptr;
  pControl = this->pControl;
  if ( v4 )
  {
    if ( pControl != nullptr )
      vgui::Panel::SetBounds(this: pControl, x: 0, y: 4, wide, tall: tall - 8);
  }
  else
  {
    v6 = wide / 2;
    if ( pControl != nullptr )
      vgui::Panel::SetBounds(this: pControl, x: v6 + 20, y: 4, wide: v6 - 20, tall: tall - 8);
    vgui::Panel::SetBounds(this: this->pPrompt, x: 0, y: 4, wide: v6 + 20, tall: tall - 8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6C90
// Name: public: CScriptListItem::CScriptListItem(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CScriptListItem *__thiscall CScriptListItem::CScriptListItem(CScriptListItem *this, char *strItem, char *strValue)
{
  this->pNext = nullptr;
  V_strncpy(pDest: this->szItemText, pSrc: strItem, maxLen: 128);
  V_strncpy(pDest: this->szValue, pSrc: strValue, maxLen: 256);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101E6CD0
// Name: public: CScriptObject::CScriptObject(void)
// Source: json
//------------------------------------------------------------------------------
CScriptObject *__thiscall CScriptObject::CScriptObject(CScriptObject *this)
{
  vgui::Panel::Panel(this);
  this->bSetInfo = false;
  this->pNext = nullptr;
  this->pListItems = nullptr;
  this->__vftable = (CScriptObject_vtbl *)&CScriptObject::`vftable';
  this->type = O_BOOL;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101E6D00
// Name: public: void CScriptObject::SetCurValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptObject::SetCurValue(CScriptObject *this, char *strValue)
{
  char *curValue; // edi
  objtype_t type; // esi

  curValue = this->curValue;
  V_strncpy(pDest: this->curValue, pSrc: strValue, maxLen: 128);
  this->fcurValue = atof(nptr: curValue);
  type = this->type;
  if ( type == O_NUMBER || type == O_BOOL )
    StripFloatTrailingZeros(str: curValue);
}

//------------------------------------------------------------------------------
// Address: 0x101E6D50
// Name: public: void CScriptObject::AddItem(class CScriptListItem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScriptObject::AddItem(CScriptObject *this, CScriptListItem *pItem)
{
  CScriptListItem *pListItems; // eax

  pListItems = this->pListItems;
  if ( pListItems != nullptr )
  {
    while ( pListItems->pNext != nullptr )
      pListItems = pListItems->pNext;
    pListItems->pNext = pItem;
    pItem->pNext = nullptr;
  }
  else
  {
    this->pListItems = pItem;
    pItem->pNext = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6DA0
// Name: void UTIL_StripInvalidCharacters(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_StripInvalidCharacters(char *pszInput, int maxlen)
{
  char v2; // al
  char *v3; // ecx
  char *v4; // edx
  char pSrc[4096]; // [esp+4h] [ebp-1000h] BYREF

  v2 = *pszInput;
  v3 = pszInput;
  v4 = pSrc;
  for ( pSrc[0] = 0; v2 != 0; ++v3 )
  {
    if ( v2 != 34 && v2 != 37 )
      *v4++ = v2;
    v2 = v3[1];
  }
  *v4 = 0;
  V_strncpy(pDest: pszInput, pSrc, maxLen: maxlen);
}

//------------------------------------------------------------------------------
// Address: 0x101E6E00
// Name: char __near * CleanFloat(float)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl CleanFloat(float val)
{
  unsigned __int8 *v1; // edi
  unsigned __int8 *v2; // esi
  int v3; // eax
  unsigned __int8 *i; // esi

  curstring_1 = (curstring_1 + 1) % 2;
  V_snprintf(pDest: string_3[curstring_1], maxLen: 32, pFormat: "%f", val);
  v1 = (unsigned __int8 *)string_3[curstring_1];
  v2 = v1;
  if ( v1 != nullptr && *v1 != 0 )
  {
    strchr(string: v1, chr: 0x2Eu);
    if ( v3 != 0 )
    {
      if ( *v1 != 0 )
      {
        do
          ++v2;
        while ( *v2 != 0 );
      }
      for ( i = v2 - 1; *i == 48; *i-- = 0 )
      {
        if ( i <= v1 )
          break;
      }
      if ( *i == 46 )
        *i = 0;
    }
  }
  return (char *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x101E6EA0
// Name: public: enum objtype_t CScriptObject::GetType(char __near *)
// Source: json
//------------------------------------------------------------------------------
objtype_t __thiscall CScriptObject::GetType(CScriptObject *this, char *pszType)
{
  int v2; // edi
  const char *v3; // esi

  v2 = 0;
  v3 = aBool_0;
  while ( _V_stricmp(s1: v3, s2: pszType) != 0 )
  {
    v3 += 36;
    ++v2;
    if ( (int)v3 >= (int)&vec2_invalid_61.y )
      return O_BADTYPE;
  }
  return objtypes[v2].type;
}

//------------------------------------------------------------------------------
// Address: 0x101E6EF0
// Name: public: bool CScriptObject::ReadFromBuffer(char const __near * __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CScriptObject::ReadFromBuffer@<al>(
        CScriptObject *this@<ecx>,
        int a2@<esi>,
        const char **pBuffer,
        bool isNewObject)
{
  const char *(__thiscall *ParseFile)(IVEngineClient *, const char *, char *, int); // eax
  const char *v7; // esi
  char v8; // cl
  const char *v9; // esi
  objtype_t Type; // eax
  const char *v11; // ecx
  char *v12; // eax
  bool v13; // cf
  unsigned __int8 v14; // dl
  int v15; // eax
  char v16; // cl
  char v17; // cl
  const char *v18; // ecx
  char *v19; // eax
  unsigned __int8 v20; // dl
  const char *v21; // ecx
  char *v22; // eax
  unsigned __int8 v23; // dl
  CScriptListItem *v24; // eax
  CScriptListItem *v25; // eax
  const char *v26; // eax
  const char *v27; // eax
  CScriptObject *v28; // ebx
  char *defValue; // esi
  const char *v30; // eax
  const char *v31; // [esp-Ch] [ebp-118h]
  char *v32; // [esp-Ch] [ebp-118h]
  char strItem[128]; // [esp+8h] [ebp-104h] BYREF
  char strValue[128]; // [esp+88h] [ebp-84h] BYREF
  CScriptObject *v36; // [esp+108h] [ebp-4h]

  ParseFile = engine->ParseFile;
  v31 = *pBuffer;
  v36 = this;
  *pBuffer = ParseFile(this: engine, a2: v31, a3: token, a4: 1024);
  if ( strlen(token) == 0 )
    return 0;
  if ( isNewObject )
    V_strncpy(pDest: this->cvarname, pSrc: token, maxLen: 64);
  v7 = engine->ParseFile(this: engine, a2: *pBuffer, a3: token, a4: 1024);
  *pBuffer = v7;
  if ( strlen(token) == 0 )
    return 0;
  if ( strcmp(token, "{") != 0 )
    goto LABEL_47;
  *pBuffer = engine->ParseFile(this: engine, a2: v7, a3: token, a4: 1024);
  if ( strlen(token) == 0 )
    return 0;
  if ( isNewObject != v8 )
    V_strncpy(pDest: this->prompt, pSrc: token, maxLen: 256);
  v9 = engine->ParseFile(this: engine, a2: *pBuffer, a3: token, a4: 1024);
  *pBuffer = v9;
  if ( strlen(token) == 0 )
    return 0;
  if ( strcmp(token, "{") != 0 )
    goto LABEL_47;
  *pBuffer = engine->ParseFile(this: engine, a2: v9, a3: token, a4: 1024);
  if ( strlen(token) == 0 )
    return 0;
  Type = CScriptObject::GetType(this, pszType: token);
  if ( isNewObject )
    this->type = Type;
  if ( Type == O_BADTYPE )
  {
    _Msg(a1: "Type '%s' unknown", token);
    return 0;
  }
  switch ( Type )
  {
    case O_BOOL:
    case O_OBSOLETE:
      *pBuffer = engine->ParseFile(this: engine, a2: *pBuffer, a3: token, a4: 1024);
      if ( strlen(token) == 0 )
        return 0;
      v11 = "}";
      v12 = token;
      do
      {
        v13 = (unsigned __int8)*v12 < (unsigned int)*v11;
        if ( *v12 != *v11 )
          goto LABEL_45;
        if ( *v12 == 0 )
          break;
        v14 = v12[1];
        v13 = v14 < (unsigned int)v11[1];
        if ( v14 != v11[1] )
          goto LABEL_45;
        v12 += 2;
        v11 += 2;
      }
      while ( v14 != 0 );
      v15 = 0;
      goto LABEL_46;
    case O_NUMBER:
      *pBuffer = engine->ParseFile(this: engine, a2: *pBuffer, a3: token, a4: 1024);
      if ( strlen(token) == 0 )
        return 0;
      if ( isNewObject != v16 )
        this->fMin = atof(nptr: token);
      *pBuffer = engine->ParseFile(this: engine, a2: *pBuffer, a3: token, a4: 1024);
      if ( strlen(token) == 0 )
        return 0;
      if ( isNewObject != v17 )
        this->fMax = atof(nptr: token);
      *pBuffer = engine->ParseFile(this: engine, a2: *pBuffer, a3: token, a4: 1024);
      if ( strlen(token) == 0 )
        return 0;
      v18 = "}";
      v19 = token;
      while ( 1 )
      {
        v13 = (unsigned __int8)*v19 < (unsigned int)*v18;
        if ( *v19 != *v18 )
          goto LABEL_45;
        if ( *v19 != 0 )
        {
          v20 = v19[1];
          v13 = v20 < (unsigned int)v18[1];
          if ( v20 != v18[1] )
            goto LABEL_45;
          v19 += 2;
          v18 += 2;
          if ( v20 != 0 )
            continue;
        }
        v15 = 0;
        goto LABEL_46;
      }
    case O_LIST:
      *pBuffer = engine->ParseFile(this: engine, a2: *pBuffer, a3: token, a4: 1024);
      if ( strlen(token) == 0 )
        return 0;
      while ( strcmp(token, "}") != 0 )
      {
        V_strncpy(pDest: strItem, pSrc: token, maxLen: 128);
        *pBuffer = engine->ParseFile(this: engine, a2: *pBuffer, a3: token, a4: 1024);
        if ( strlen(token) == 0 )
          return 0;
        V_strncpy(pDest: strValue, pSrc: token, maxLen: 128);
        if ( isNewObject )
        {
          v24 = (CScriptListItem *)MemAlloc_Alloc(nSize: 0x184u);
          if ( v24 != nullptr )
            v25 = CScriptListItem::CScriptListItem(this: v24, strItem, strValue);
          else
            v25 = nullptr;
          CScriptObject::AddItem(this, pItem: v25);
        }
        *pBuffer = engine->ParseFile(this: engine, a2: *pBuffer, a3: token, a4: 1024);
        if ( strlen(token) == 0 )
          return 0;
      }
      goto LABEL_59;
    case O_STRING:
      *pBuffer = engine->ParseFile(this: engine, a2: *pBuffer, a3: token, a4: 1024);
      if ( strlen(token) == 0 )
        return 0;
      v21 = "}";
      v22 = token;
      break;
    default:
      goto LABEL_59;
  }
  while ( 1 )
  {
    v13 = (unsigned __int8)*v22 < (unsigned int)*v21;
    if ( *v22 != *v21 )
      break;
    if ( *v22 == 0 )
      goto LABEL_44;
    v23 = v22[1];
    v13 = v23 < (unsigned int)v21[1];
    if ( v23 != v21[1] )
      break;
    v22 += 2;
    v21 += 2;
    if ( v23 == 0 )
    {
LABEL_44:
      v15 = 0;
      goto LABEL_46;
    }
  }
LABEL_45:
  v15 = -v13 - (v13 - 1);
LABEL_46:
  if ( v15 != 0 )
    goto LABEL_47;
LABEL_59:
  v26 = engine->ParseFile(this: engine, a2: *pBuffer, a3: token, a4: 1024);
  *pBuffer = v26;
  if ( strlen(token) == 0 )
    return 0;
  if ( strcmp(token, "{") != 0 )
    goto LABEL_47;
  v27 = (const char *)((int (__thiscall *)(IVEngineClient *, const char *, char *, int, int))engine->ParseFile)(
                        a1: engine,
                        a2: v26,
                        a3: token,
                        a4: 1024,
                        a5: a2);
  v28 = v36;
  defValue = v36->defValue;
  v32 = v36->defValue;
  *pBuffer = v27;
  V_strncpy(pDest: v32, pSrc: token, maxLen: 128);
  v28->fdefValue = atof(nptr: token);
  if ( v28->type == O_NUMBER )
    StripFloatTrailingZeros(str: defValue);
  CScriptObject::SetCurValue(this: v28, strValue: defValue);
  v30 = (const char *)((int (__thiscall *)(IVEngineClient *, _DWORD, char *))engine->ParseFile)(
                        a1: engine,
                        a2: *pBuffer,
                        a3: token);
  *pBuffer = v30;
  if ( strlen(token) == 0 )
    return 0;
  if ( strcmp(token, "}") != 0 )
    goto LABEL_47;
  *pBuffer = engine->ParseFile(this: engine, a2: v30, a3: token, a4: 1024);
  if ( strlen(token) == 0 )
    return 0;
  if ( _V_stricmp(s1: token, s2: "SetInfo") == 0 )
  {
    v36->bSetInfo = true;
    *pBuffer = engine->ParseFile(this: engine, a2: *pBuffer, a3: token, a4: 1024);
    if ( strlen(token) == 0 )
      return 0;
  }
  if ( strcmp(token, "}") != 0 )
  {
LABEL_47:
    _Msg(a1: "Expecting '{', got '%s'", token);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E7680
// Name: public: CDescription::CDescription(class CPanelListPanel __near *)
// Source: json
//------------------------------------------------------------------------------
CDescription *__thiscall CDescription::CDescription(CDescription *this, CPanelListPanel *panel)
{
  this->__vftable = (CDescription_vtbl *)&CDescription::`vftable';
  this->pObjList = nullptr;
  this->m_pListPanel = panel;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101E76A0
// Name: public: CDescription::~CDescription(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDescription::~CDescription(CDescription *this)
{
  CScriptObject *pObjList; // ecx
  CScriptObject *pNext; // esi
  void (*MarkForDeletion)(void); // edx
  char *m_pszHintText; // eax
  char *m_pszDescriptionType; // edi

  pObjList = this->pObjList;
  this->__vftable = (CDescription_vtbl *)&CDescription::`vftable';
  if ( pObjList != nullptr )
  {
    do
    {
      pNext = pObjList->pNext;
      MarkForDeletion = (void (*)(void))pObjList->MarkForDeletion;
      pObjList->pNext = nullptr;
      MarkForDeletion();
      pObjList = pNext;
    }
    while ( pNext != nullptr );
  }
  m_pszHintText = this->m_pszHintText;
  this->pObjList = nullptr;
  if ( m_pszHintText != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pszHintText);
  m_pszDescriptionType = this->m_pszDescriptionType;
  if ( m_pszDescriptionType != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pszDescriptionType);
}

//------------------------------------------------------------------------------
// Address: 0x101E7710
// Name: private: class CScriptObject __near * CDescription::FindObject(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CScriptObject *__thiscall CDescription::FindObject(CDescription *this, const char *pszObjectName)
{
  CScriptObject *pObjList; // esi

  if ( pszObjectName == nullptr )
    return nullptr;
  pObjList = this->pObjList;
  if ( pObjList == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: pszObjectName, s2: pObjList->cvarname) != 0 )
  {
    pObjList = pObjList->pNext;
    if ( pObjList == nullptr )
      return nullptr;
  }
  return pObjList;
}

//------------------------------------------------------------------------------
// Address: 0x101E7760
// Name: public: void CDescription::AddObject(class CScriptObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDescription::AddObject(CDescription *this, CScriptObject *pObj)
{
  CScriptObject *pObjList; // eax

  pObjList = this->pObjList;
  if ( pObjList != nullptr )
  {
    while ( pObjList->pNext != nullptr )
      pObjList = pObjList->pNext;
    pObjList->pNext = pObj;
    pObj->pNext = nullptr;
  }
  else
  {
    this->pObjList = pObj;
    pObj->pNext = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E77B0
// Name: public: bool CDescription::ReadFromBuffer(char const __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDescription::ReadFromBuffer(CDescription *this, const char **pBuffer)
{
  long double v4; // st7
  const char *v5; // esi
  const char *(__thiscall *ParseFile)(IVEngineClient *, const char *, char *, int); // eax
  char v7; // bl
  CScriptObject *Object; // eax
  CScriptObject *v9; // esi
  CScriptObject *v10; // eax
  CScriptObject *v11; // eax
  const char *(__thiscall *v12)(IVEngineClient *, const char *, char *, int); // eax
  const char *pStart; // [esp+34h] [ebp-4h] BYREF
  float fVer; // [esp+40h] [ebp+8h]

  *pBuffer = engine->ParseFile(this: engine, a2: *pBuffer, a3: token, a4: 1024);
  if ( strlen(token) == 0 )
    return 0;
  if ( _V_stricmp(s1: token, s2: "VERSION") != 0 )
  {
    _Msg(a1: "Expecting 'VERSION', got '%s'", token);
    return 0;
  }
  *pBuffer = engine->ParseFile(this: engine, a2: *pBuffer, a3: token, a4: 1024);
  if ( strlen(token) == 0 )
  {
    _Msg(a1: "Expecting version #");
    return 0;
  }
  v4 = atof(nptr: token);
  if ( v4 != 1.0 )
  {
    fVer = v4;
    _Msg(a1: "Version mismatch, expecting %f, got %f", 1.0, fVer);
    return 0;
  }
  *pBuffer = engine->ParseFile(this: engine, a2: *pBuffer, a3: token, a4: 1024);
  if ( strlen(token) == 0 )
    return 0;
  if ( _V_stricmp(s1: token, s2: "DESCRIPTION") != 0 )
  {
    _Msg(a1: "Expecting 'DESCRIPTION', got '%s'", token);
    return 0;
  }
  *pBuffer = engine->ParseFile(this: engine, a2: *pBuffer, a3: token, a4: 1024);
  if ( strlen(token) == 0 )
  {
    _Msg(a1: "Expecting '%s'", this->m_pszDescriptionType);
    return 0;
  }
  if ( _V_stricmp(s1: token, s2: this->m_pszDescriptionType) != 0 )
  {
    _Msg(a1: "Expecting %s, got %s", this->m_pszDescriptionType, token);
    return 0;
  }
  v5 = engine->ParseFile(this: engine, a2: *pBuffer, a3: token, a4: 1024);
  *pBuffer = v5;
  if ( strlen(token) == 0 )
    return 0;
  if ( strcmp(token, "{") != 0 )
  {
    _Msg(a1: "Expecting '{', got '%s'", token);
    return 0;
  }
  ParseFile = engine->ParseFile;
  pStart = v5;
  *pBuffer = ParseFile(this: engine, a2: v5, a3: token, a4: 1024);
  if ( strlen(token) == 0 )
    return 0;
  while ( 1 )
  {
    if ( _V_stricmp(s1: token, s2: "}") == 0 )
      return 1;
    *pBuffer = v5;
    v7 = 1;
    Object = CDescription::FindObject(this, pszObjectName: token);
    v9 = Object;
    if ( Object != nullptr )
    {
      CScriptObject::ReadFromBuffer(this: Object, a2: (int)Object, pBuffer: &pStart, isNewObject: false);
      v7 = 0;
      goto LABEL_26;
    }
    v10 = (CScriptObject *)MemAlloc_Alloc(nSize: 0x3ACu);
    if ( v10 == nullptr || (v11 = CScriptObject::CScriptObject(this: v10), v9 = v11, v11 == nullptr) )
    {
      _Msg(a1: "Couldn't create script object");
      return 0;
    }
    if ( CScriptObject::ReadFromBuffer(this: v11, a2: (int)v11, pBuffer: &pStart, isNewObject: true) == 0 )
      break;
LABEL_26:
    *pBuffer = pStart;
    if ( v7 != 0 )
      CDescription::AddObject(this, pObj: v9);
    v5 = *pBuffer;
    v12 = engine->ParseFile;
    pStart = *pBuffer;
    *pBuffer = v12(this: engine, a2: pStart, a3: token, a4: 1024);
    if ( strlen(token) == 0 )
      return 0;
  }
  ((void (__thiscall *)(CScriptObject *, int))v9->dtr_Panel)(a1: v9, a2: 1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E7B80
// Name: public: bool CDescription::InitFromFile(char __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CDescription::InitFromFile@<al>(
        CDescription *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        char *pszFileName)
{
  CDescription *v4; // edi
  unsigned int v6; // ebx
  char *v7; // esi

  v4 = (CDescription *)g_pFullFileSystem->Open(
                         this: &g_pFullFileSystem->IBaseFileSystem,
                         a2: pszFileName,
                         a3: "rb",
                         a4: 0);
  if ( v4 == nullptr )
    return 0;
  v6 = ((int (__thiscall *)(IBaseFileSystem *, CDescription *, int, int))g_pFullFileSystem->Size_2)(
         a1: &g_pFullFileSystem->IBaseFileSystem,
         a2: v4,
         a3,
         a4: a2);
  v7 = (char *)MemAlloc_Alloc(nSize: v6);
  ((void (__thiscall *)(IBaseFileSystem *, char *, unsigned int))g_pFullFileSystem->Read)(
    a1: &g_pFullFileSystem->IBaseFileSystem,
    a2: v7,
    a3: v6);
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v4);
  pszFileName = v7;
  CDescription::ReadFromBuffer(this: v4, pBuffer: (const char **)&pszFileName);
  C_BaseEntity::operator delete(pMem: v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E7C20
// Name: public: void CDescription::WriteToConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDescription::WriteToConfig(CDescription *this)
{
  CScriptObject *pObjList; // esi
  objtype_t type; // eax
  const char *v3; // eax
  float fMin; // xmm1_4
  float fcurValue; // xmm0_4
  float fMax; // xmm1_4
  int v7; // edx
  CScriptListItem *pListItems; // eax
  int v9; // ecx
  char pDest[2048]; // [esp+10h] [ebp-900h] BYREF
  char v11[256]; // [esp+810h] [ebp-100h] BYREF

  pObjList = this->pObjList;
  if ( pObjList != nullptr )
  {
    while ( 1 )
    {
      type = pObjList->type;
      if ( type != O_OBSOLETE )
        break;
LABEL_25:
      pObjList = pObjList->pNext;
      if ( pObjList == nullptr )
        return;
    }
    switch ( type )
    {
      case O_BOOL:
        v3 = "1";
        if ( pObjList->fcurValue == 0.0 )
          v3 = "0";
        V_snprintf(pDest, maxLen: 0x800u, pFormat: "%s", v3);
        goto LABEL_21;
      case O_NUMBER:
        fMin = pObjList->fMin;
        fcurValue = pObjList->fcurValue;
        if ( fMin != -1.0 && fcurValue <= fMin )
          fcurValue = pObjList->fMin;
        fMax = pObjList->fMax;
        if ( fMax != -1.0 && fMax <= fcurValue )
          fcurValue = pObjList->fMax;
        V_snprintf(pDest, maxLen: 0x800u, pFormat: "%f", fcurValue);
        goto LABEL_21;
      case O_LIST:
        v7 = (int)pObjList->fcurValue;
        pListItems = pObjList->pListItems;
        v9 = 0;
        if ( v7 <= 0 )
        {
LABEL_18:
          if ( pListItems != nullptr )
          {
            V_snprintf(pDest, maxLen: 0x800u, pFormat: "%s", pListItems->szValue);
            UTIL_StripInvalidCharacters(pszInput: pDest, maxlen: 2048);
LABEL_21:
            if ( pObjList->bSetInfo )
              V_snprintf(pDest: v11, maxLen: 0x100u, pFormat: "setinfo %s \"%s\"\n", pObjList->cvarname, pDest);
            else
              V_snprintf(pDest: v11, maxLen: 0x100u, pFormat: "%s \"%s\"\n", pObjList->cvarname, pDest);
            engine->ClientCmd_Unrestricted(this: engine, a2: v11);
            goto LABEL_25;
          }
        }
        else
        {
          while ( pListItems != nullptr )
          {
            pListItems = pListItems->pNext;
            if ( ++v9 >= v7 )
              goto LABEL_18;
          }
        }
        V_strncpy(pDest, pSrc: "0.0", maxLen: 2048);
        goto LABEL_21;
      case O_STRING:
        V_snprintf(pDest, maxLen: 0x800u, pFormat: "\"%s\"", pObjList->curValue);
        UTIL_StripInvalidCharacters(pszInput: pDest, maxlen: 2048);
        goto LABEL_21;
      default:
        goto LABEL_21;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E7E40
// Name: public: void CDescription::WriteToScriptFile(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDescription::WriteToScriptFile(CDescription *this, void *fp)
{
  CScriptObject *pObjList; // ebx
  char v5; // al
  char *v6; // edx
  char *v7; // ecx
  char v8; // al
  char *v9; // edx
  char *v10; // ecx
  IFileSystem_vtbl *v11; // esi
  char *v12; // eax
  CScriptListItem *pListItems; // esi
  char v14; // al
  CScriptListItem *v15; // edx
  char *v16; // ecx
  char *szValue; // ecx
  char v18; // al
  char *v19; // edx
  IFileSystem_vtbl *v20; // esi
  char *v21; // eax
  char pDest[4096]; // [esp+18h] [ebp-2000h] BYREF
  char pSrc[4096]; // [esp+1018h] [ebp-1000h] BYREF
  CScriptObject *pNext; // [esp+2020h] [ebp+8h]

  this->WriteScriptHeader(this, a2: fp);
  pObjList = this->pObjList;
  pNext = pObjList;
  if ( pObjList != nullptr )
  {
    while ( 1 )
    {
      if ( pObjList->type != O_OBSOLETE )
      {
        V_strncpy(pDest, pSrc: pObjList->cvarname, maxLen: 4096);
        v5 = pDest[0];
        v6 = pDest;
        v7 = pSrc;
        for ( pSrc[0] = 0; v5 != 0; ++v6 )
        {
          if ( v5 != 34 && v5 != 37 )
            *v7++ = v5;
          v5 = v6[1];
        }
        *v7 = 0;
        V_strncpy(pDest, pSrc, maxLen: 4096);
        V_strncpy(pDest: pObjList->cvarname, pSrc: pDest, maxLen: 64);
        g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "\t\"%s\"\r\n", pObjList->cvarname);
        g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "\t{\r\n");
        V_strncpy(pDest, pSrc: pObjList->prompt, maxLen: 4096);
        v8 = pDest[0];
        v9 = pDest;
        v10 = pSrc;
        for ( pSrc[0] = 0; v8 != 0; ++v9 )
        {
          if ( v8 != 34 && v8 != 37 )
            *v10++ = v8;
          v8 = v9[1];
        }
        *v10 = 0;
        V_strncpy(pDest, pSrc, maxLen: 4096);
        V_strncpy(pDest: pObjList->prompt, pSrc: pDest, maxLen: 256);
        switch ( pObjList->type )
        {
          case O_BOOL:
            g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "\t\t\"%s\"\r\n", pObjList->prompt);
            g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "\t\t{ BOOL }\r\n");
            g_pFullFileSystem->FPrintf(
              this: g_pFullFileSystem,
              a2: fp,
              a3: "\t\t{ \"%i\" }\r\n",
              (int)pObjList->fcurValue != 0);
            break;
          case O_NUMBER:
            g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "\t\t\"%s\"\r\n", pObjList->prompt);
            v11 = g_pFullFileSystem->IAppSystem::__vftable;
            CleanFloat(val: pObjList->fMax);
            v12 = CleanFloat(val: pObjList->fMin);
            v11->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "\t\t{ NUMBER %s %s }\r\n", v12);
            goto LABEL_33;
          case O_LIST:
            g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "\t\t\"%s\"\r\n", pObjList->prompt);
            g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "\t\t{\r\n\t\t\tLIST\r\n");
            pListItems = pObjList->pListItems;
            if ( pListItems != nullptr )
            {
              do
              {
                v14 = pListItems->szItemText[0];
                v15 = pListItems;
                v16 = pSrc;
                for ( pSrc[0] = 0; v14 != 0; v15 = (CScriptListItem *)((char *)v15 + 1) )
                {
                  if ( v14 != 34 && v14 != 37 )
                    *v16++ = v14;
                  v14 = v15->szItemText[1];
                }
                *v16 = 0;
                V_strncpy(pDest: pListItems->szItemText, pSrc, maxLen: 128);
                szValue = pListItems->szValue;
                v18 = pListItems->szValue[0];
                v19 = pSrc;
                for ( pSrc[0] = 0; v18 != 0; ++szValue )
                {
                  if ( v18 != 34 && v18 != 37 )
                    *v19++ = v18;
                  v18 = szValue[1];
                }
                *v19 = 0;
                V_strncpy(pDest: pListItems->szValue, pSrc, maxLen: 256);
                g_pFullFileSystem->FPrintf(
                  this: g_pFullFileSystem,
                  a2: fp,
                  a3: "\t\t\t\"%s\" \"%s\"\r\n",
                  pListItems,
                  pListItems->szValue);
                pListItems = pListItems->pNext;
              }
              while ( pListItems != nullptr );
              pObjList = pNext;
            }
            ((void (__cdecl *)(IFileSystem *, void *))g_pFullFileSystem->FPrintf)(a1: g_pFullFileSystem, a2: fp);
LABEL_33:
            v20 = g_pFullFileSystem->IAppSystem::__vftable;
            v21 = CleanFloat(val: pObjList->fcurValue);
            v20->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "\t\t{ \"%s\" }\r\n", v21);
            break;
          case O_STRING:
            g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "\t\t\"%s\"\r\n", pObjList->prompt);
            g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "\t\t{ STRING }\r\n");
            V_strncpy(pDest: pSrc, pSrc: pObjList->curValue, maxLen: 4096);
            UTIL_StripInvalidCharacters(pszInput: pSrc, maxlen: 4096);
            V_strncpy(pDest: pObjList->curValue, pSrc, maxLen: 128);
            g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "\t\t{ \"%s\" }\r\n", pObjList->curValue);
            break;
          default:
            break;
        }
        if ( pObjList->bSetInfo )
          g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "\t\tSetInfo\r\n");
        g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "\t}\r\n\r\n");
      }
      pNext = pObjList->pNext;
      if ( pNext == nullptr )
        break;
      pObjList = pObjList->pNext;
    }
  }
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "}\r\n");
}

//------------------------------------------------------------------------------
// Address: 0x101E8290
// Name: public: void CDescription::TransferCurrentValues(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDescription::TransferCurrentValues(CDescription *this, const char *pszConfigFile)
{
  CScriptObject *i; // esi
  char *m_pszString; // eax
  char szValue[1024]; // [esp+4h] [ebp-408h] BYREF
  ConVarRef var; // [esp+404h] [ebp-8h] BYREF

  for ( i = this->pObjList; i != nullptr; i = i->pNext )
  {
    ConVarRef::ConVarRef(this: &var, pName: i->cvarname);
    if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&var) )
    {
      m_pszString = var.m_pConVarState->m_Value.m_pszString;
      if ( m_pszString != nullptr && *m_pszString != 0 )
      {
        V_strncpy(pDest: szValue, pSrc: m_pszString, maxLen: 1024);
        V_strncpy(pDest: i->curValue, pSrc: szValue, maxLen: 128);
        i->fcurValue = atof(nptr: szValue);
        V_strncpy(pDest: i->defValue, pSrc: szValue, maxLen: 128);
        i->fdefValue = atof(nptr: szValue);
      }
    }
    else
    {
      DevMsg(a1: "Could not find '%s'\n", i->cvarname);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E8370
// Name: public: void CDescription::setDescription(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDescription::setDescription(CDescription *this, const char *pszDesc)
{
  char *v3; // eax

  if ( pszDesc != nullptr
    && (v3 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pszDesc) + 1)) != nullptr )
  {
    strcpy(v3, pszDesc);
    this->m_pszDescriptionType = v3;
  }
  else
  {
    this->m_pszDescriptionType = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E83D0
// Name: public: void CDescription::setHint(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDescription::setHint(CDescription *this, const char *pszHint)
{
  char *v3; // eax

  if ( pszHint != nullptr
    && (v3 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pszHint) + 1)) != nullptr )
  {
    strcpy(v3, pszHint);
    this->m_pszHintText = v3;
  }
  else
  {
    this->m_pszHintText = nullptr;
  }
}
