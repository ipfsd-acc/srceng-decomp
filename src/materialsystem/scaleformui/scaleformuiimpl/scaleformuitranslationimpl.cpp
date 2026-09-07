// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/scaleformui/scaleformuiimpl/scaleformuitranslationimpl.cpp
// Functions: 15
// ============================================================

#include "materialsystem\scaleformui\scaleformuiimpl\scaleformuitranslationimpl.h"

//------------------------------------------------------------------------------
// Address: 0x10014450
// Name: int MapKeywordToTable(wchar_t const __near *,wchar_t const __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl MapKeywordToTable(const wchar_t *keyword, const wchar_t **keywordTable)
{
  const wchar_t **v2; // esi
  const wchar_t *v3; // eax
  int v4; // edi

  v2 = keywordTable;
  v3 = *keywordTable;
  v4 = 0;
  if ( *keywordTable == nullptr )
    return -1;
  while ( *v3 == 0 || _V_wcscmp(s1: keyword, s2: v3) != 0 )
  {
    v3 = v2[1];
    ++v2;
    ++v4;
    if ( v3 == nullptr )
      return -1;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100144A0
// Name: int PlaceStringInOutput(wchar_t const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl PlaceStringInOutput(const wchar_t *theString, int outindex, bool lengthPreChecked)
{
  const wchar_t *v3; // esi
  int v4; // edi
  wchar_t v5; // ax

  v3 = theString;
  if ( theString == nullptr )
    return outindex;
  v4 = outindex;
  if ( lengthPreChecked || G_wcslen(pwch: theString) < 4086 - outindex )
  {
    v5 = *theString;
    if ( *theString != 0 )
    {
      do
      {
        ++v3;
        g_htmlBuffer[v4] = v5;
        v5 = *v3;
        ++v4;
      }
      while ( *v3 != 0 );
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10014500
// Name: int PlaceGlyphHTMLIntoOutput(wchar_t const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl PlaceGlyphHTMLIntoOutput(const wchar_t *buttonName, int fontSize, int outindex)
{
  int v3; // eax
  int v4; // edx

  v3 = 23;
  v4 = -6;
  if ( fontSize != 0 )
  {
    v3 = fontSize + (fontSize >> 2);
    v4 = -fontSize >> 2;
  }
  return outindex
       + V_snwprintf(
           pDest: &g_htmlBuffer[outindex],
           maxLen: 4086 - outindex,
           pFormat: g_htmlReplacementString,
           buttonName,
           v3,
           v3,
           v4);
}

//------------------------------------------------------------------------------
// Address: 0x10014550
// Name: wchar_t const __near * GetSonyGlyph(int)
// Source: json
//------------------------------------------------------------------------------
const wchar_t *__cdecl GetSonyGlyph(unsigned int buttonIndex)
{
  int v1; // eax

  if ( buttonIndex <= 1
    && (v1 = _KeyValuesSystem(),
        (*(unsigned __int8 (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 32))(a1: v1, a2: "INPUTSWAPAB") != 0) )
  {
    return g_controllerButtonImageNamesSony[buttonIndex == 0];
  }
  else
  {
    return g_controllerButtonImageNamesSony[buttonIndex];
  }
}

//------------------------------------------------------------------------------
// Address: 0x100145A0
// Name: public: virtual void ScaleformUIImpl::ShowActionNameWhenActionIsNotBound(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::ShowActionNameWhenActionIsNotBound(ScaleformUIImpl *this, bool value)
{
  this->m_bShowActionNameIfUnbound = value;
}

//------------------------------------------------------------------------------
// Address: 0x100145B0
// Name: public: virtual void ScaleformUIImpl::UpdateBindingForButton(enum ButtonCode_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::UpdateBindingForButton(ScaleformUIImpl *this, ButtonCode_t bt, const char *pbinding)
{
  ButtonCode_t v3; // edi
  int v5; // esi
  const char *v6; // eax
  __int32 v7; // edi
  ButtonCode_t code; // [esp+8h] [ebp-4h] BYREF

  v3 = bt;
  if ( (unsigned int)(bt - 114) <= 0xBF )
  {
    ScaleformUIImpl::DecodeButtonandSlotFromButtonCode(this, inCode: bt, outCode: &code, outSlot: (int *)&bt);
    v5 = 0;
    while ( g_controllerButtonToButtonCodeLookup[v5] != v3 )
    {
      if ( ++v5 >= 27 )
        return;
    }
    v6 = pbinding;
    if ( pbinding == nullptr )
      goto LABEL_12;
    if ( *pbinding == 43 )
      v6 = pbinding + 1;
    if ( v6 != nullptr && *v6 != 0 )
    {
      v7 = 27 * bt;
      _V_UTF8ToUnicode(a1: v6, a2: this->m_wcControllerButtonToBindingTable[bt][v5], a3: 128);
      _V_wcslower(start: &this->m_wcControllerButtonToBindingTable[0][v5][64 * v7]);
    }
    else
    {
LABEL_12:
      this->m_wcControllerButtonToBindingTable[bt][v5][0] = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014670
// Name: protected: enum IScaleformUI::ControllerButton::Enum ScaleformUIImpl::LookupButtonFromBinding(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ScaleformUIImpl::LookupButtonFromBinding(ScaleformUIImpl *this, const wchar_t *binding)
{
  const wchar_t *v2; // ebx
  int v3; // esi
  const wchar_t *i; // edi

  v2 = binding;
  if ( *binding == 43 )
    v2 = binding + 1;
  v3 = 0;
  for ( i = this->m_wcControllerButtonToBindingTable[this->m_pEngine->GetActiveSplitScreenPlayerSlot(this: this->m_pEngine)][0];
        _V_wcscmp(s1: v2, s2: i) != 0;
        i += 64 )
  {
    if ( ++v3 >= 27 )
      return 27;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100146D0
// Name: public: virtual wchar_t const __near * ScaleformUIImpl::ReplaceGlyphKeywordsWithHTML(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const wchar_t *__thiscall ScaleformUIImpl::ReplaceGlyphKeywordsWithHTML(
        ScaleformUIImpl *this,
        const char *text,
        int fontSize)
{
  int v4; // eax

  v4 = 2 * _V_strlen(str: text) + 2;
  if ( v4 > 4086 )
    v4 = 4086;
  _V_UTF8ToUnicode(a1: text, a2: g_wcharBuffer, a3: v4);
  return this->ReplaceGlyphKeywordsWithHTML_2(this, a2: g_wcharBuffer, a3: fontSize);
}

//------------------------------------------------------------------------------
// Address: 0x10014720
// Name: public: virtual wchar_t const __near * ScaleformUIImpl::Translate(char const __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
const wchar_t *__thiscall ScaleformUIImpl::Translate(ScaleformUIImpl *this, const char *key, bool *pIsHTML)
{
  bool *v3; // edi
  const char *v4; // ebx
  int v5; // edi
  void *v6; // esp
  char v7; // dl
  const char *v8; // ecx
  char *v9; // eax
  wchar_t *v10; // eax
  const wchar_t *v11; // esi
  const wchar_t *result; // eax
  _BYTE v13[12]; // [esp+0h] [ebp-14h] BYREF
  ScaleformUIImpl *v14; // [esp+Ch] [ebp-8h]
  int fontSize; // [esp+10h] [ebp-4h]

  v3 = pIsHTML;
  v14 = this;
  fontSize = 0;
  v4 = key;
  if ( pIsHTML != nullptr )
    *pIsHTML = false;
  if ( *key == 35 )
  {
    v5 = _V_strlen(str: key) + 1;
    if ( V_strnchr(pStr: key, c: 64, n: v5) != nullptr )
    {
      v6 = alloca(v5);
      v7 = 0;
      v8 = key;
      v9 = v13;
      if ( *key != 0 )
      {
        do
        {
          if ( v7 != 0 || *v8 != 92 )
          {
            if ( *v8 == 64 )
            {
              if ( v7 == 0 )
                goto LABEL_19;
              *v9 = 64;
            }
            else
            {
              if ( v7 != 0 )
                *v9++ = 92;
              *v9 = *v8;
            }
            ++v9;
            ++v8;
            v7 = 0;
          }
          else
          {
            v7 = 1;
            ++v8;
          }
        }
        while ( *v8 != 0 );
        if ( v7 != 0 )
          *v9++ = 92;
      }
LABEL_19:
      *v9 = 0;
      v4 = v13;
      if ( *v8 == 64 )
        ++v8;
      if ( *v8 != 0 )
      {
        fontSize = atoi(nptr: v8);
        if ( fontSize < 0 )
          fontSize = 0;
      }
    }
    v10 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: v4);
    this = v14;
    v11 = v10;
    if ( v10 != nullptr )
    {
      result = v14->ReplaceGlyphKeywordsWithHTML_2(this: v14, a2: v10, a3: fontSize);
      if ( pIsHTML != nullptr )
        *pIsHTML = result != v11;
      return result;
    }
    v3 = pIsHTML;
  }
  result = this->ReplaceGlyphKeywordsWithHTML(this, a2: v4, a3: fontSize);
  if ( v3 != nullptr )
    *v3 = true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014840
// Name: public: virtual void ScaleformUIImpl::MakeStringSafe(wchar_t const __near *,wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::MakeStringSafe(
        ScaleformUIImpl *this,
        wchar_t *oldName,
        wchar_t *newName,
        int newNameBufSize)
{
  wchar_t *v4; // ebx
  wchar_t *v5; // esi
  int v6; // edi
  unsigned __int16 *v7; // eax
  unsigned int v8; // eax

  v4 = oldName;
  v5 = newName;
  v6 = newNameBufSize - 1;
  if ( *oldName != 0 )
  {
    while ( v6 > 0 )
    {
      v7 = wcschr(string: g_pCharsToBeReplaced, ch: *v4);
      if ( v7 != nullptr )
      {
        V_wcsncpy(pDest: v5, pSrc: g_pReplacementStrings[v7 - g_pCharsToBeReplaced], maxLenInBytes: v6);
        v8 = wcslen(v5);
        v6 -= v8;
        v5 += v8;
      }
      else
      {
        *v5++ = *v4;
        --v6;
      }
      if ( *++v4 == 0 )
      {
        *v5 = 0;
        return;
      }
    }
    *v5 = 0;
  }
  else
  {
    *newName = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100148E0
// Name: public: virtual void ScaleformUIImpl::RefreshKeyBindings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::RefreshKeyBindings(ScaleformUIImpl *this)
{
  ScaleformUIImpl *v1; // esi
  int v2; // ecx
  int i; // ebx
  int j; // edi
  int v5; // edx
  const char *v6; // eax
  wchar_t *v7; // esi
  int slot; // [esp+8h] [ebp-4h]

  v1 = this;
  _V_memset(dest: this->m_wcControllerButtonToBindingTable, fill: 0, count: 6912);
  if ( v1->m_pGameUIFuncs != nullptr )
  {
    v2 = 0;
    slot = 0;
    for ( i = 0; i < 2; ++i )
    {
      for ( j = 0; j < 27; ++j )
      {
        v5 = g_controllerButtonToButtonCodeLookup[j];
        if ( (unsigned int)(v5 - 114) <= 0xBF && v2 != 0 )
        {
          if ( i >= 0 )
          {
            if ( v2 > 3 )
              v2 = 3;
          }
          else
          {
            v2 = 0;
          }
          if ( v5 > 241 )
          {
            if ( (unsigned int)(v5 - 242) > 0xF )
            {
              v1 = this;
              v5 = (v5 - 258) % 12 + 258;
            }
            else
            {
              v5 = (v5 - 242) % 4 + 242;
            }
          }
          else
          {
            v5 = (v5 - 114) % 32 + 114;
          }
          if ( (unsigned int)(v5 - 114) <= 0x7F )
          {
            v5 += 32 * v2;
            goto LABEL_21;
          }
          if ( (unsigned int)(v5 - 242) > 0xF )
          {
            if ( (unsigned int)(v5 - 258) > 0x2F )
              goto LABEL_21;
            v2 *= 3;
          }
          v5 += 4 * v2;
        }
LABEL_21:
        if ( v5 != -1 )
        {
          v6 = v1->m_pGameUIFuncs->GetBindingForButtonCode(this: v1->m_pGameUIFuncs, a2: (ButtonCode_t)v5);
          if ( v6 == nullptr )
            goto LABEL_28;
          if ( *v6 == 43 )
            ++v6;
          if ( v6 != nullptr && *v6 != 0 )
          {
            v7 = v1->m_wcControllerButtonToBindingTable[i][j];
            _V_UTF8ToUnicode(a1: v6, a2: v7, a3: 128);
            _V_wcslower(start: v7);
            v1 = this;
          }
          else
          {
LABEL_28:
            v1->m_wcControllerButtonToBindingTable[i][j][0] = 0;
          }
        }
        v2 = slot;
      }
      v2 = ++slot;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014A50
// Name: protected: wchar_t const __near * ScaleformUIImpl::LocalizeCommand(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__thiscall ScaleformUIImpl::LocalizeCommand(ScaleformUIImpl *this, const wchar_t *command)
{
  int m_Size; // ebx
  int v4; // esi

  m_Size = this->m_LocalizableCommandNames.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return (wchar_t *)command;
  while ( _V_wcscmp(s1: command, s2: this->m_LocalizableCommandNames.m_Memory.m_pMemory[v4]) != 0 )
  {
    if ( ++v4 >= m_Size )
      return (wchar_t *)command;
  }
  return g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: this->m_LocalizableCommandKeys.m_Memory.m_pMemory[v4]);
}

//------------------------------------------------------------------------------
// Address: 0x10014AB0
// Name: public: virtual wchar_t const __near * ScaleformUIImpl::ReplaceGlyphKeywordsWithHTML(wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__thiscall ScaleformUIImpl::ReplaceGlyphKeywordsWithHTML(ScaleformUIImpl *this, wchar_t *pin, int fontSize)
{
  wchar_t *result; // eax
  wchar_t v4; // cx
  const wchar_t *v5; // edx
  int v6; // ecx
  wchar_t *v7; // ebx
  int v8; // eax
  int v9; // esi
  wchar_t *v10; // eax
  int v11; // edx
  int v12; // ecx
  bool v13; // zf
  int v14; // eax
  ScaleformUIImpl *v15; // esi
  unsigned int v16; // eax
  const wchar_t *v17; // eax
  const wchar_t *SonyGlyph; // eax
  wchar_t keywordBuffer[128]; // [esp+0h] [ebp-10Ch] BYREF
  ScaleformUIImpl *v20; // [esp+100h] [ebp-Ch]
  int outindex; // [esp+104h] [ebp-8h]
  bool bEscaping; // [esp+10Bh] [ebp-1h]

  result = pin;
  v20 = this;
  if ( pin != nullptr )
  {
    v4 = *pin;
    v5 = pin;
    if ( *pin != 0 )
    {
      while ( v4 != 36 || v5[1] != 123 )
      {
        v4 = v5[1];
        ++v5;
        if ( v4 == 0 )
          return result;
      }
      v6 = 0;
      v7 = pin;
      outindex = 0;
      bEscaping = false;
      while ( 1 )
      {
        if ( v6 >= 4086 )
        {
LABEL_44:
          g_htmlBuffer[v6] = 0;
          return g_htmlBuffer;
        }
        if ( bEscaping )
        {
LABEL_41:
          g_htmlBuffer[v6] = *v7;
          outindex = v6 + 1;
          bEscaping = false;
          goto LABEL_42;
        }
        v8 = *v7;
        if ( v8 == 92 )
        {
          bEscaping = true;
LABEL_42:
          ++v7;
          goto LABEL_43;
        }
        if ( v8 != 36 )
          goto LABEL_41;
        if ( *++v7 != 123 )
        {
          g_htmlBuffer[v6] = 36;
          outindex = v6 + 1;
          goto LABEL_43;
        }
        v9 = 128;
        v10 = keywordBuffer;
        v11 = 0;
        while ( 1 )
        {
          v12 = *(wchar_t *)((char *)v10 + (char *)(v7 + 1) - (char *)keywordBuffer);
          if ( (_WORD)v12 == 0 || v12 == 125 )
            break;
          *v10++ = v12;
          ++v11;
          if ( --v9 == 0 )
            goto LABEL_21;
        }
        if ( v11 != 0 )
          *v10 = 0;
LABEL_21:
        if ( v11 == 128 || v11 == 0 )
          return pin;
        v13 = v7[v11 + 1] == 125;
        v7 += v11 + 1;
        if ( v13 )
          ++v7;
        if ( keywordBuffer[0] == 42 )
        {
          outindex = PlaceGlyphHTMLIntoOutput(buttonName: &keywordBuffer[1], fontSize, outindex);
        }
        else
        {
          _V_wcslower(start: keywordBuffer);
          v14 = MapKeywordToTable(keyword: keywordBuffer, keywordTable: g_buttonFunctionKeywords);
          v15 = v20;
          if ( v14 == -1 )
            v16 = ScaleformUIImpl::LookupButtonFromBinding(this: v20, binding: keywordBuffer);
          else
            v16 = v14 % 27;
          if ( v16 != 27 )
          {
            if ( ScaleformUIImpl::m_Instance.m_bForcePS3 )
              SonyGlyph = GetSonyGlyph(buttonIndex: v16);
            else
              SonyGlyph = g_controllerButtonImageNames[v16];
            outindex = PlaceGlyphHTMLIntoOutput(buttonName: SonyGlyph, fontSize, outindex);
            goto LABEL_43;
          }
          if ( v15->m_bShowActionNameIfUnbound )
          {
            v17 = ScaleformUIImpl::LocalizeCommand(this: v15, command: keywordBuffer);
            if ( v17 == nullptr )
            {
              outindex = PlaceStringInOutput(theString: keywordBuffer, outindex, lengthPreChecked: false);
              goto LABEL_43;
            }
          }
          else
          {
            v17 = &word_1028F3E0;
          }
          outindex = PlaceStringInOutput(theString: v17, outindex, lengthPreChecked: false);
        }
LABEL_43:
        v6 = outindex;
        if ( *v7 == 0 )
          goto LABEL_44;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014D00
// Name: protected: void ScaleformUIImpl::ShutdownTranslationImpl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::ShutdownTranslationImpl(ScaleformUIImpl *this)
{
  int i; // edi
  wchar_t *v3; // ecx
  const char **m_pMemory; // ecx

  for ( i = this->m_LocalizableCommandNames.m_Size;
        i != 0;
        free(pMem: (void *)this->m_LocalizableCommandKeys.m_Memory.m_pMemory[i]) )
  {
    v3 = (wchar_t *)this->m_LocalizableCommandNames.m_Memory.m_pMemory[--i];
    free(pMem: v3);
  }
  this->m_LocalizableCommandNames.m_Size = 0;
  if ( this->m_LocalizableCommandNames.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_LocalizableCommandNames.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_LocalizableCommandNames.m_Memory.m_pMemory);
      this->m_LocalizableCommandNames.m_Memory.m_pMemory = nullptr;
    }
    this->m_LocalizableCommandNames.m_Memory.m_nAllocationCount = 0;
  }
  this->m_LocalizableCommandNames.m_pElements = this->m_LocalizableCommandNames.m_Memory.m_pMemory;
  this->m_LocalizableCommandKeys.m_Size = 0;
  if ( this->m_LocalizableCommandKeys.m_Memory.m_nGrowSize < 0 )
  {
    this->m_LocalizableCommandKeys.m_pElements = this->m_LocalizableCommandKeys.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_LocalizableCommandKeys.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_LocalizableCommandKeys.m_Memory.m_pMemory);
      this->m_LocalizableCommandKeys.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_LocalizableCommandKeys.m_Memory.m_pMemory;
    this->m_LocalizableCommandKeys.m_Memory.m_nAllocationCount = 0;
    this->m_LocalizableCommandKeys.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014DD0
// Name: protected: void ScaleformUIImpl::InitTranslationImpl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::InitTranslationImpl(ScaleformUIImpl *this)
{
  KeyValues *v1; // eax
  KeyValues *v2; // edi
  IBaseFileSystem *v3; // eax
  KeyValues *FirstTrueSubKey; // esi
  const char *String; // eax
  const char *v6; // edi
  const char *v7; // eax
  int v8; // esi
  wchar_t *v9; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  const wchar_t **m_pMemory; // ecx
  int v13; // eax
  const wchar_t **v14; // edi
  int v15; // eax
  char *v16; // ebx
  int v17; // edi
  int v18; // eax
  const char **v19; // ecx
  int v20; // eax
  const char **v21; // edi
  const char *name; // [esp+0h] [ebp-1Ch]
  KeyValues *v24; // [esp+8h] [ebp-14h]
  KeyValues *piter; // [esp+Ch] [ebp-10h]

  this->m_bShowActionNameIfUnbound = true;
  _V_memset(dest: this->m_wcControllerButtonToBindingTable, fill: 0, count: 6912);
  v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v1 != nullptr )
    v24 = KeyValues::KeyValues(this: v1, setName: "options_x360");
  else
    v24 = nullptr;
  v2 = v24;
  if ( v24 != nullptr )
  {
    if ( g_pFullFileSystem != nullptr )
      v3 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v3 = nullptr;
    KeyValues::LoadFromFile(
      this: v24,
      filesystem: v3,
      resourceName: "scripts/controller_options.360.txt",
      pathID: "game",
      pfnEvaluateSymbolProc: nullptr);
    FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: v24);
    piter = FirstTrueSubKey;
    if ( FirstTrueSubKey != nullptr )
    {
      while ( 1 )
      {
        String = KeyValues::GetString(this: FirstTrueSubKey, keyName: "command", defaultValue: (const char *)&pMem);
        v6 = String;
        if ( String != nullptr && *String != 0 )
        {
          v7 = KeyValues::GetString(this: FirstTrueSubKey, keyName: "name", defaultValue: (const char *)&pMem);
          name = v7;
          if ( v7 != nullptr && *v7 != 0 )
          {
            if ( *v6 == 43 )
              ++v6;
            v8 = _V_strlen(str: v6);
            v9 = (wchar_t *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)(v8 + 1) >> 31 != 0 ? -1 : 2 * (v8 + 1));
            _V_UTF8ToUnicode(a1: v6, a2: v9, a3: 2 * v8 + 2);
            _V_wcslower(start: v9);
            m_Size = this->m_LocalizableCommandNames.m_Size;
            m_nAllocationCount = this->m_LocalizableCommandNames.m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<IMaterialVar *,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)&this->m_LocalizableCommandNames,
                num: m_Size - m_nAllocationCount + 1);
            ++this->m_LocalizableCommandNames.m_Size;
            m_pMemory = this->m_LocalizableCommandNames.m_Memory.m_pMemory;
            v13 = this->m_LocalizableCommandNames.m_Size - m_Size - 1;
            this->m_LocalizableCommandNames.m_pElements = m_pMemory;
            if ( v13 > 0 )
              _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
            v14 = &this->m_LocalizableCommandNames.m_Memory.m_pMemory[m_Size];
            if ( v14 != nullptr )
              *v14 = v9;
            v15 = _V_strlen(str: name);
            v16 = (char *)MemAlloc_Alloc(nSize: v15 + 1);
            _V_strcpy(dest: v16, src: name);
            v17 = this->m_LocalizableCommandKeys.m_Size;
            v18 = this->m_LocalizableCommandKeys.m_Memory.m_nAllocationCount;
            if ( v17 + 1 > v18 )
              CUtlMemory<IMaterialVar *,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)&this->m_LocalizableCommandKeys,
                num: v17 - v18 + 1);
            ++this->m_LocalizableCommandKeys.m_Size;
            v19 = this->m_LocalizableCommandKeys.m_Memory.m_pMemory;
            v20 = this->m_LocalizableCommandKeys.m_Size - v17 - 1;
            this->m_LocalizableCommandKeys.m_pElements = v19;
            if ( v20 > 0 )
              _V_memmove(dest: &v19[v17 + 1], src: &v19[v17], count: 4 * v20);
            FirstTrueSubKey = piter;
            v21 = &this->m_LocalizableCommandKeys.m_Memory.m_pMemory[v17];
            if ( v21 != nullptr )
              *v21 = v16;
          }
        }
        piter = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
        if ( piter == nullptr )
          break;
        FirstTrueSubKey = piter;
      }
      v2 = v24;
    }
    KeyValues::deleteThis(this: v2);
  }
}
