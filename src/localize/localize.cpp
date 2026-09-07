// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: localize/localize.cpp
// Functions: 105
// ============================================================

#include "localize\localize.h"

//------------------------------------------------------------------------------
// Address: 0x10001010
// Name: public: virtual void CLocalize::SetTextQuery(class ILocalizeTextQuery __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalize::SetTextQuery(CLocalize *this, ILocalizeTextQuery *pQuery)
{
  this->m_pQuery = pQuery;
}

//------------------------------------------------------------------------------
// Address: 0x10001020
// Name: public: virtual char const __near * CLocalize::FindAsUTF8(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CLocalize::FindAsUTF8(CLocalize *this, const char *pchTokenName)
{
  wchar_t *v2; // eax

  v2 = this->Find(this, a2: pchTokenName);
  if ( v2 == nullptr )
    return (char *)pchTokenName;
  _V_UnicodeToUTF8(a1: v2, a2: rgchT, a3: 2048);
  return rgchT;
}

//------------------------------------------------------------------------------
// Address: 0x10001060
// Name: public: virtual wchar_t const __near * CLocalize::FindSafe(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const wchar_t *__thiscall CLocalize::FindSafe(CLocalize *this, const char *pName)
{
  const wchar_t *result; // eax

  result = this->Find(this, a2: pName);
  if ( result == nullptr )
  {
    DevMsg(a1: "CLocalize::FindSafe failed to localize: %s\n", pName);
    return L"#FIXME_LOCALIZATION_FAIL_MISSING_STRING";
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001090
// Name: private: virtual int CLocalize::ConvertANSIToUCS2(char const __near *,wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLocalize::ConvertANSIToUCS2(
        CLocalize *this,
        const char *ansi,
        wchar_t *unicode,
        unsigned int unicodeBufferSizeInBytes)
{
  int result; // eax

  result = MultiByteToWideChar(
             CodePage: 0xFDE9u,
             dwFlags: 0,
             lpMultiByteStr: ansi,
             cbMultiByte: -1,
             lpWideCharStr: unicode,
             cchWideChar: unicodeBufferSizeInBytes >> 1);
  unicode[(unicodeBufferSizeInBytes >> 1) - 1] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100010C0
// Name: public: virtual int CLocalize::ConvertUnicodeToANSI(wchar_t const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLocalize::ConvertUnicodeToANSI(CLocalize *this, const wchar_t *unicode, char *ansi, int ansiBufferSize)
{
  int result; // eax

  result = WideCharToMultiByte(
             CodePage: 0xFDE9u,
             dwFlags: 0,
             lpWideCharStr: unicode,
             cchWideChar: -1,
             lpMultiByteStr: ansi,
             cbMultiByte: ansiBufferSize,
             lpDefaultChar: nullptr,
             lpUsedDefaultChar: nullptr);
  ansi[ansiBufferSize - 1] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100010F0
// Name: public: void CLocalize::ConstructString(wchar_t __near *,int,wchar_t const __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalize::ConstructString(
        CLocalize *this,
        wchar_t *unicodeOutput,
        unsigned int unicodeBufferSizeInBytes,
        wchar_t *formatString,
        int numFormatParameters,
        char *argList)
{
  wchar_t *v6; // ebx
  signed int v7; // edx
  int v9; // eax
  wchar_t *v10; // eax
  _WORD *v11; // esi
  __int16 v12; // cx
  signed int v13; // esi
  unsigned int unicodeBufferSize; // [esp+Ch] [ebp-4h]
  int formatLength; // [esp+1Ch] [ebp+Ch]
  wchar_t *param; // [esp+20h] [ebp+10h]

  v6 = formatString;
  v7 = unicodeBufferSizeInBytes >> 1;
  unicodeBufferSize = unicodeBufferSizeInBytes >> 1;
  formatLength = wcslen(formatString);
  while ( *v6 != 0 )
  {
    if ( v7 <= 0 )
      break;
    if ( formatLength >= 3 && *v6 == 37 && v6[1] == 115 )
    {
      v9 = v6[2] - 49;
      if ( (unsigned int)v9 > 9 )
      {
        _Warning(a1: "Bad format string in CLocalizeStringTable::ConstructString\n");
        *unicodeOutput = 0;
        return;
      }
      if ( v9 < numFormatParameters )
      {
        v10 = *(wchar_t **)&argList[4 * v9];
        param = v10;
        if ( v10 == nullptr )
          *unicodeOutput = 0;
        v11 = v10 + 1;
        do
          v12 = *v10++;
        while ( v12 != 0 );
        v13 = v10 - v11;
        if ( v13 > v7 )
          v13 = v7;
        wcsncpy(dest: unicodeOutput, source: param, count: v13);
        unicodeBufferSize -= v13;
        v7 = unicodeBufferSize;
        v6 += 3;
        formatLength -= 3;
        unicodeOutput += v13;
        continue;
      }
      *unicodeOutput = 37;
    }
    else
    {
      *unicodeOutput = *v6;
    }
    --v7;
    ++unicodeOutput;
    ++v6;
    --formatLength;
    unicodeBufferSize = v7;
  }
  *unicodeOutput = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001200
// Name: public: virtual void CLocalize::ConstructString(wchar_t __near *,int,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalize::ConstructString(
        CLocalize *this,
        wchar_t *unicodeOutput,
        int unicodeBufferSizeInBytes,
        const char *tokenName,
        KeyValues *localizationVariables)
{
  unsigned int v6; // eax

  v6 = this->FindIndex(this, a2: tokenName);
  if ( v6 == -1 )
    this->ConvertANSIToUnicode(this, a2: tokenName, a3: unicodeOutput, a4: unicodeBufferSizeInBytes);
  else
    this->ConstructString(this, a2: unicodeOutput, a3: unicodeBufferSizeInBytes, a4: v6, a5: localizationVariables);
}

//------------------------------------------------------------------------------
// Address: 0x10001250
// Name: public: virtual void CLocalize::ConstructString(wchar_t __near *,int,unsigned int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalize::ConstructString(
        CLocalize *this,
        wchar_t *unicodeOutput,
        unsigned int unicodeBufferSizeInBytes,
        unsigned int unlocalizedTextSymbol,
        KeyValues *localizationVariables)
{
  wchar_t *v5; // eax
  wchar_t *v6; // esi
  wchar_t v7; // ax
  int v8; // ecx
  unsigned int v9; // eax
  unsigned __int16 *v10; // eax
  unsigned __int16 *v11; // edi
  char *v12; // ecx
  char *v13; // eax
  const unsigned __int16 *WString; // eax
  signed int v15; // esi
  char variableName[32]; // [esp+4h] [ebp-20h] BYREF
  signed int unicodeBufferSize; // [esp+30h] [ebp+Ch]

  if ( (int)unicodeBufferSizeInBytes >= 1 )
  {
    *unicodeOutput = 0;
    v5 = this->GetValueByIndex(this, a2: unlocalizedTextSymbol);
    v6 = v5;
    if ( v5 == nullptr )
    {
      wcsncpy(dest: unicodeOutput, source: L"[unknown string]", count: unicodeBufferSizeInBytes >> 1);
      return;
    }
    v7 = *v5;
    unicodeBufferSize = unicodeBufferSizeInBytes >> 1;
    if ( v7 != 0 )
    {
      do
      {
        if ( unicodeBufferSize <= 0 )
          break;
        if ( v7 == 37 )
        {
          v8 = v6[1];
          if ( v8 != 115 || (v9 = v6[2]) < 0x30 || v9 > 0x39 )
          {
            if ( v8 == 37 )
            {
              ++v6;
            }
            else if ( localizationVariables != nullptr )
            {
              v10 = wcschr(string: v6 + 1, ch: 0x25u);
              v11 = v10;
              if ( v10 != nullptr && *v10 == 37 )
              {
                v12 = variableName;
                v13 = (char *)(v6 + 1);
                if ( v6 + 1 < v11 )
                {
                  do
                  {
                    if ( v12 >= &variableName[31] )
                      break;
                    *v12 = *v13;
                    v13 += 2;
                    ++v12;
                  }
                  while ( v13 < (char *)v11 );
                }
                *v12 = 0;
                WString = KeyValues::GetWString(
                            this: localizationVariables,
                            keyName: variableName,
                            defaultValue: L"[unknown]");
                v15 = wcslen(WString);
                if ( v15 > unicodeBufferSize )
                  v15 = unicodeBufferSize;
                wcsncpy(dest: unicodeOutput, source: WString, count: v15);
                unicodeBufferSize -= v15;
                unicodeOutput += v15;
                v6 = v11 + 1;
                goto LABEL_13;
              }
            }
          }
        }
        --unicodeBufferSize;
        *unicodeOutput++ = *v6++;
LABEL_13:
        v7 = *v6;
      }
      while ( *v6 != 0 );
    }
    *unicodeOutput = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001390
// Name: public: void CUtlMemory<wchar_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<wchar_t,int>::Grow(CUtlMemory<wchar_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  wchar_t *m_pMemory; // edx
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
        m_nAllocationCount = 16;
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
    v7 = 2 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (wchar_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (wchar_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001420
// Name: public: void CUtlMemory<struct CLocalize::LocalizationFileInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CLocalize::LocalizationFileInfo_t,int>::Grow(
        CUtlMemory<CLocalize::LocalizationFileInfo_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CLocalize::LocalizationFileInfo_t *m_pMemory; // edx
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
        m_nAllocationCount = 6;
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
    v7 = 6 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CLocalize::LocalizationFileInfo_t *)_g_pMemAlloc->Realloc_2(
                                                               this: _g_pMemAlloc,
                                                               a2: m_pMemory,
                                                               a3: v7);
    else
      this->m_pMemory = (CLocalize::LocalizationFileInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100014C0
// Name: public: virtual int CLocalize::GetLocalizationFileCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLocalize::GetLocalizationFileCount(CLocalize *this)
{
  return this->m_LocalizationFiles.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100014D0
// Name: public: virtual void CLocalize::ConstructString(wchar_t __near *,int,wchar_t const __near *,int,...)
// Source: json
//------------------------------------------------------------------------------
void CLocalize::ConstructString(
        CLocalize *this,
        wchar_t *unicodeOutput,
        unsigned int unicodeBufferSizeInBytes,
        wchar_t *formatString,
        int numFormatParameters,
        ...)
{
  va_list argList; // [esp+1Ch] [ebp+1Ch] BYREF

  va_start(argList, numFormatParameters);
  if ( formatString != nullptr )
    CLocalize::ConstructString(
      this,
      unicodeOutput,
      unicodeBufferSizeInBytes,
      formatString,
      numFormatParameters,
      argList);
  else
    *unicodeOutput = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001500
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned short>(unsigned short __near *,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned short>(
        CByteswap *this,
        unsigned __int8 *outputBuffer,
        unsigned __int8 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int8 *v5; // esi
  int v6; // edi
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl

  v4 = count;
  if ( count > 0 && outputBuffer != nullptr )
  {
    v5 = inputBuffer;
    if ( inputBuffer == nullptr )
      v5 = outputBuffer;
    if ( (*(_BYTE *)this & 1) != 0 )
    {
      v6 = outputBuffer - v5;
      do
      {
        v7 = v5[1];
        count = *(unsigned __int16 *)&v5[v6];
        v8 = *v5;
        LOBYTE(count) = v7;
        BYTE1(count) = v8;
        _V_memcpy(dest: &v5[v6], src: &count, count: 2);
        v5 += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
    else if ( v5 != nullptr && outputBuffer != v5 )
    {
      memcpy(dst: outputBuffer, src: v5, count: 2 * count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001580
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::localizedstring_t,unsigned int>,unsigned int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *m_pMemory; // edx

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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *)_g_pMemAlloc->Realloc_2(
                                                                                        this: _g_pMemAlloc,
                                                                                        a2: m_pMemory,
                                                                                        a3: 28 * m_nAllocationCount);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *)_g_pMemAlloc->Alloc_2(
                                                                                        this: _g_pMemAlloc,
                                                                                        a2: 28 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001630
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::fastvalue_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *m_pMemory; // edx
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
      this->m_pMemory = (UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                         this: _g_pMemAlloc,
                                                                         a2: m_pMemory,
                                                                         a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100016D0
// Name: public: void CUtlMemory<class ILocalizationChangeCallback __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ILocalizationChangeCallback *,int>::Grow(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edx
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
        m_nAllocationCount = 8;
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
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001760
// Name: public: int CUtlRBTree<struct CLocalize::fastvalue_t,int,bool (*)(struct CLocalize::fastvalue_t const __near &,struct CLocalize::fastvalue_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::fastvalue_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Parent(
        CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl*)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1001E6B8 = -1;
    dword_1001E6BC = -1;
    dword_1001E6C0 = 1;
  }
  if ( i == -1 )
    return dword_1001E6BC;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x100017C0
// Name: public: virtual void __near * CBaseAppSystem<class ILocalize>::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CBaseAppSystem<ILocalize>::QueryInterface(CBaseAppSystem<ILocalize> *this, const char *pInterfaceName)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100017D0
// Name: public: virtual void CBaseAppSystem<class ILocalize>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<ILocalize>::Reconnect(
        CBaseAppSystem<ILocalize> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x100017F0
// Name: private: void CLocalize::InvokeChangeCallbacks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalize::InvokeChangeCallbacks(CLocalize *this)
{
  int m_Size; // ebx
  int i; // esi
  ILocalizationChangeCallback *v4; // ecx

  if ( this->m_bSuppressChangeCallbacks )
  {
    this->m_bQueuedChangeCallback = true;
  }
  else
  {
    m_Size = this->m_ChangeCallbacks.m_Size;
    for ( i = 0; i < m_Size; ++i )
    {
      v4 = this->m_ChangeCallbacks.m_Memory.m_pMemory[i];
      v4->OnLocalizationChanged(this: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001830
// Name: private: bool CLocalize::AddAllLanguageFiles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLocalize::AddAllLanguageFiles(CLocalize *this, const char *baseFileName)
{
  const char *v2; // edi
  char v4; // bl
  int v5; // eax
  const char *i; // eax
  bool v7; // zf
  const char *v9; // [esp-8h] [ebp-320h]
  char szFile[260]; // [esp+Ch] [ebp-30Ch] BYREF
  char szSearchPath[260]; // [esp+110h] [ebp-208h] BYREF
  char szFilePath[260]; // [esp+214h] [ebp-104h] BYREF

  v2 = baseFileName;
  v9 = baseFileName;
  v4 = 1;
  this->m_bSuppressChangeCallbacks = true;
  V_strncpy(pDest: szFilePath, pSrc: v9, maxLen: 260);
  strrchr(string: (unsigned __int8 *)szFilePath, chr: 0x5Cu);
  if ( v5 != 0 || (strrchr(string: (unsigned __int8 *)szFilePath, chr: 0x2Fu), v5 != 0) )
    *(_BYTE *)(v5 + 1) = 0;
  else
    szFilePath[0] = 0;
  V_snprintf(pDest: szSearchPath, maxLen: 260, pFormat: "%s*.txt", v2);
  baseFileName = nullptr;
  for ( i = g_pFullFileSystem->FindFirst(this: g_pFullFileSystem, a2: szSearchPath, a3: &baseFileName);
        i != nullptr;
        i = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: baseFileName) )
  {
    V_snprintf(pDest: szFile, maxLen: 260, pFormat: "%s%s", szFilePath, i);
    v4 &= ((int (__thiscall *)(CLocalize *, char *, _DWORD, int))this->AddFile)(a1: this, a2: szFile, a3: 0, a4: 1);
  }
  g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: (int)baseFileName);
  v7 = !this->m_bQueuedChangeCallback;
  this->m_bSuppressChangeCallbacks = false;
  if ( !v7 )
  {
    this->m_bQueuedChangeCallback = false;
    CLocalize::InvokeChangeCallbacks(this);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10001950
// Name: public: virtual void CLocalize::ReloadLocalizationFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalize::ReloadLocalizationFiles(CLocalize *this)
{
  CLocalize::LocalizationFileInfo_t *v2; // esi
  const char *v3; // eax
  CLocalize_vtbl *v4; // edi
  const char *v5; // eax
  const char *v6; // [esp-10h] [ebp-1Ch]
  BOOL bIncludeFallbacks; // [esp-Ch] [ebp-18h]
  int i; // [esp+4h] [ebp-8h]
  int v9; // [esp+8h] [ebp-4h]

  i = 0;
  if ( this->m_LocalizationFiles.m_Size > 0 )
  {
    v9 = 0;
    do
    {
      v2 = &this->m_LocalizationFiles.m_Memory.m_pMemory[v9];
      if ( *CUtlSymbol::String(this: &v2->symPathID) != 0 )
        v3 = CUtlSymbol::String(this: &v2->symPathID);
      else
        v3 = nullptr;
      v4 = this->__vftable;
      bIncludeFallbacks = v2->bIncludeFallbacks;
      v6 = v3;
      v5 = CUtlSymbol::String(this: &v2->symName);
      v4->AddFile(this, a2: v5, a3: v6, a4: bIncludeFallbacks);
      ++v9;
      ++i;
    }
    while ( i < this->m_LocalizationFiles.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100019D0
// Name: private: static bool CLocalize::SymLess(struct CLocalize::localizedstring_t const __near &,struct CLocalize::localizedstring_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CLocalize::SymLess(const CLocalize::localizedstring_t *i1, const CLocalize::localizedstring_t *i2)
{
  const char *pszValueString; // ecx

  if ( i1->nameIndex == -1 )
    pszValueString = i1->pszValueString;
  else
    pszValueString = &s_Localize.m_Names.m_Memory.m_pMemory[i1->nameIndex];
  if ( i2->nameIndex == -1 )
    return _V_stricmp(s1: pszValueString, s2: i2->pszValueString) < 0;
  else
    return _V_stricmp(s1: pszValueString, s2: &s_Localize.m_Names.m_Memory.m_pMemory[i2->nameIndex]) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001A30
// Name: private: static bool CLocalize::FastValueLessFunc(struct CLocalize::fastvalue_t const __near &,struct CLocalize::fastvalue_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CLocalize::FastValueLessFunc(const CLocalize::fastvalue_t *lhs, const CLocalize::fastvalue_t *rhs)
{
  const unsigned __int16 *search; // eax
  const unsigned __int16 *v3; // ecx
  int v4; // kr00_4

  search = lhs->search;
  if ( search == nullptr )
    search = &CLocalize::s_pTable->m_Values.m_Memory.m_pMemory[lhs->valueindex];
  v3 = rhs->search;
  if ( v3 == nullptr )
    v3 = &CLocalize::s_pTable->m_Values.m_Memory.m_pMemory[rhs->valueindex];
  v4 = wcscmp(search, v3);
  return v4 != 0 && -(v4 < 0) - ((v4 < 0) - 1) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001AA0
// Name: public: virtual char const __near * CLocalize::GetLocalizationFileName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CLocalize::GetLocalizationFileName(CLocalize *this, int index)
{
  return CUtlSymbol::String(this: &this->m_LocalizationFiles.m_Memory.m_pMemory[index].symName);
}

//------------------------------------------------------------------------------
// Address: 0x10001AC0
// Name: public: bool CUtlVector<class ILocalizationChangeCallback __near *,class CUtlMemory<class ILocalizationChangeCallback __near *,int>>::FindAndRemove(class ILocalizationChangeCallback __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<ILocalizationChangeCallback *,CUtlMemory<ILocalizationChangeCallback *,int>>::FindAndRemove(
        CUtlVector<ILocalizationChangeCallback *,CUtlMemory<ILocalizationChangeCallback *,int> > *this,
        ILocalizationChangeCallback **src)
{
  int m_Size; // edx
  int v4; // eax
  ILocalizationChangeCallback **m_pMemory; // ebx
  ILocalizationChangeCallback **i; // ecx
  int v8; // edx

  m_Size = this->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  v8 = m_Size - v4 - 1;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 4 * v8);
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001B30
// Name: protected: void CUtlBuffer::PutTypeBin<unsigned short>(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<unsigned short>(CUtlBuffer *this, unsigned __int16 src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 2) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<unsigned short>(
        this: &this->m_Byteswap,
        outputBuffer: &this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: (unsigned __int8 *)&src,
        count: 1);
    else
      *(_WORD *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 2;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001BA0
// Name: public: unsigned int CUtlRBTree<struct CLocalize::localizedstring_t,unsigned int,bool (*)(struct CLocalize::localizedstring_t const __near &,struct CLocalize::localizedstring_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Parent(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Parent(
        CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl*)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int> > *this,
        unsigned int i)
{
  if ( (`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
    dword_1001E6A4 = -1;
    dword_1001E6A8 = -1;
    dword_1001E6AC = 1;
  }
  if ( i == -1 )
    return dword_1001E6A8;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x10001C00
// Name: public: unsigned int CUtlRBTree<struct CLocalize::localizedstring_t,unsigned int,bool (*)(struct CLocalize::localizedstring_t const __near &,struct CLocalize::localizedstring_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::localizedstring_t,unsigned int>,unsigned int>>::LeftChild(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::LeftChild(
        CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl*)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int> > *this,
        unsigned int i)
{
  if ( (`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
    dword_1001E6A4 = -1;
    dword_1001E6A8 = -1;
    dword_1001E6AC = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x10001C60
// Name: public: unsigned int CUtlRBTree<struct CLocalize::localizedstring_t,unsigned int,bool (*)(struct CLocalize::localizedstring_t const __near &,struct CLocalize::localizedstring_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::localizedstring_t,unsigned int>,unsigned int>>::RightChild(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::RightChild(
        CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl*)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int> > *this,
        unsigned int i)
{
  if ( (`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
    dword_1001E6A4 = -1;
    dword_1001E6A8 = -1;
    dword_1001E6AC = 1;
  }
  if ( i == -1 )
    return dword_1001E6A4;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x10001CC0
// Name: public: bool CUtlRBTree<struct CLocalize::localizedstring_t,unsigned int,bool (*)(struct CLocalize::localizedstring_t const __near &,struct CLocalize::localizedstring_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::localizedstring_t,unsigned int>,unsigned int>>::IsRightChild(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::IsRightChild(
        CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl*)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int> > *this,
        unsigned int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *v3; // eax
  unsigned int m_Parent; // eax

  v2 = `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
    dword_1001E6A4 = -1;
    dword_1001E6A8 = -1;
    dword_1001E6AC = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *)&`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
    dword_1001E6A4 = -1;
    dword_1001E6A8 = -1;
    dword_1001E6AC = 1;
  }
  if ( m_Parent == -1 )
    return dword_1001E6A4 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x10001D80
// Name: protected: void CUtlRBTree<struct CLocalize::localizedstring_t,unsigned int,bool (*)(struct CLocalize::localizedstring_t const __near &,struct CLocalize::localizedstring_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::localizedstring_t,unsigned int>,unsigned int>>::FindInsertionPosition(struct CLocalize::localizedstring_t const __near &,unsigned int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::FindInsertionPosition(
        CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl*)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int> > *this,
        const CLocalize::localizedstring_t *insert,
        unsigned int *parent,
        bool *leftchild)
{
  unsigned int m_Root; // edi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
        dword_1001E6A4 = -1;
        dword_1001E6A8 = -1;
        dword_1001E6AC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
        dword_1001E6A4 = -1;
        dword_1001E6A8 = -1;
        dword_1001E6AC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001E80
// Name: public: int CUtlRBTree<struct CLocalize::fastvalue_t,int,bool (*)(struct CLocalize::fastvalue_t const __near &,struct CLocalize::fastvalue_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::fastvalue_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::RightChild(
        CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl*)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1001E6B8 = -1;
    dword_1001E6BC = -1;
    dword_1001E6C0 = 1;
  }
  if ( i == -1 )
    return dword_1001E6B8;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x10001EE0
// Name: protected: void CUtlRBTree<struct CLocalize::fastvalue_t,int,bool (*)(struct CLocalize::fastvalue_t const __near &,struct CLocalize::fastvalue_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::fastvalue_t,int>,int>>::FindInsertionPosition(struct CLocalize::fastvalue_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl*)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int> > *this,
        const CLocalize::fastvalue_t *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1001E6B8 = -1;
        dword_1001E6BC = -1;
        dword_1001E6C0 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1001E6B8 = -1;
        dword_1001E6BC = -1;
        dword_1001E6C0 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001FD0
// Name: public: unsigned int CUtlRBTree<struct CLocalize::localizedstring_t,unsigned int,bool (*)(struct CLocalize::localizedstring_t const __near &,struct CLocalize::localizedstring_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::localizedstring_t,unsigned int>,unsigned int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::NewNode(
        CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl*)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int> > *this)
{
  unsigned int result; // eax
  signed int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned int v6; // edi
  signed int v7; // ecx
  int v8; // eax
  int v9; // ecx

  result = this->m_FirstFree;
  if ( result == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v5 = index + 1;
      if ( v5 < 0 || v5 >= m_nAllocationCount )
        v5 = -1;
    }
    v6 = v5;
    if ( v5 < 0 || v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_LastAlloc.index;
      if ( v7 < 0 || (v8 = this->m_Elements.m_nAllocationCount, v7 >= v8) )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v9 = (v8 > 0) - 1;
      }
      else
      {
        v9 = v7 + 1;
        if ( v9 < 0 || v9 >= v8 )
          v9 = -1;
      }
      v6 = v9;
      if ( v9 < 0 || v9 >= v8 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    this->m_LastAlloc.index = v6;
    result = v6;
  }
  else
  {
    this->m_FirstFree = this->m_Elements.m_pMemory[result].m_Right;
  }
  if ( &this->m_Elements.m_pMemory[result] != (UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *)-16 )
    this->m_Elements.m_pMemory[result].m_Data.filename.m_Id = -1;
  this->m_pElements = this->m_Elements.m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100020B0
// Name: public: int CUtlRBTree<struct CLocalize::fastvalue_t,int,bool (*)(struct CLocalize::fastvalue_t const __near &,struct CLocalize::fastvalue_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::fastvalue_t,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::NewNode(
        CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl*)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int> > *this)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *v11; // edx

  result = this->m_FirstFree;
  if ( result == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v5 = index + 1;
      if ( v5 < 0 || v5 >= m_nAllocationCount )
        v5 = -1;
    }
    v6 = v5;
    if ( v5 < 0 || v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>::Grow(this: &this->m_Elements, num: 1);
      v7 = this->m_LastAlloc.index;
      if ( v7 < 0 || (v8 = this->m_Elements.m_nAllocationCount, v7 >= v8) )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v9 = (v8 > 0) - 1;
      }
      else
      {
        v9 = v7 + 1;
        if ( v9 < 0 || v9 >= v8 )
          v9 = -1;
      }
      v6 = v9;
      if ( v9 < 0 || v9 >= v8 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v11 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v11[result].m_Right;
    this->m_pElements = v11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002170
// Name: public: bool CUtlRBTree<struct CLocalize::localizedstring_t,unsigned int,bool (*)(struct CLocalize::localizedstring_t const __near &,struct CLocalize::localizedstring_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::localizedstring_t,unsigned int>,unsigned int>>::IsLeftChild(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::IsLeftChild(
        CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl*)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int> > *this,
        unsigned int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *v3; // eax
  unsigned int m_Parent; // eax

  v2 = `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
    dword_1001E6A4 = -1;
    dword_1001E6A8 = -1;
    dword_1001E6AC = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *)&`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
    dword_1001E6A4 = -1;
    dword_1001E6A8 = -1;
    dword_1001E6AC = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x10002230
// Name: protected: void CUtlRBTree<struct CLocalize::localizedstring_t,unsigned int,bool (*)(struct CLocalize::localizedstring_t const __near &,struct CLocalize::localizedstring_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::localizedstring_t,unsigned int>,unsigned int>>::RotateLeft(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::RotateLeft(
        CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl*)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int> > *this,
        unsigned int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *v4; // ecx
  unsigned int m_Right; // edi
  UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *v6; // ecx
  unsigned int v7; // eax
  UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *v8; // ecx
  unsigned int v9; // ecx
  unsigned int v10; // ecx

  v2 = `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
    dword_1001E6A4 = -1;
    dword_1001E6A8 = -1;
    dword_1001E6AC = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *)&`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
    dword_1001E6A4 = -1;
    dword_1001E6A8 = -1;
    dword_1001E6AC = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *)&`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  v7 = elem;
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  if ( (`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
    dword_1001E6A4 = -1;
    dword_1001E6A8 = -1;
    dword_1001E6AC = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *)&`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::LeftChild(
                                 this,
                                 i: m_Right)].m_Parent = elem;
    v7 = elem;
  }
  if ( m_Right != -1 )
  {
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Parent(
                                                     this,
                                                     i: elem);
    v7 = elem;
  }
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::IsLeftChild(
              this,
              i: elem) )
  {
    v9 = CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Parent(
           this,
           i: elem);
    v7 = elem;
    this->m_Elements.m_pMemory[v9].m_Left = m_Right;
  }
  else
  {
    v10 = CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Parent(
            this,
            i: elem);
    v7 = elem;
    this->m_Elements.m_pMemory[v10].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[v7].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x100023E0
// Name: protected: void CUtlRBTree<struct CLocalize::localizedstring_t,unsigned int,bool (*)(struct CLocalize::localizedstring_t const __near &,struct CLocalize::localizedstring_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::localizedstring_t,unsigned int>,unsigned int>>::RotateRight(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::RotateRight(
        CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl*)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int> > *this,
        unsigned int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *v4; // ecx
  unsigned int m_Left; // edi
  UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *v6; // ecx
  unsigned int v7; // eax
  UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *v8; // ecx
  unsigned int v9; // ecx
  unsigned int v10; // ecx

  v2 = `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
    dword_1001E6A4 = -1;
    dword_1001E6A8 = -1;
    dword_1001E6AC = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *)&`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
    dword_1001E6A4 = -1;
    dword_1001E6A8 = -1;
    dword_1001E6AC = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *)&`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  v7 = elem;
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
    dword_1001E6A4 = -1;
    dword_1001E6A8 = -1;
    dword_1001E6AC = 1;
  }
  if ( m_Left == -1 )
    v8 = (UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *)&`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Left];
  if ( v8->m_Right != -1 )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
    v7 = elem;
  }
  if ( m_Left != -1 )
  {
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Parent(
                                                    this,
                                                    i: elem);
    v7 = elem;
  }
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::IsRightChild(
              this,
              i: elem) )
  {
    v9 = CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Parent(
           this,
           i: elem);
    v7 = elem;
    this->m_Elements.m_pMemory[v9].m_Right = m_Left;
  }
  else
  {
    v10 = CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Parent(
            this,
            i: elem);
    v7 = elem;
    this->m_Elements.m_pMemory[v10].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[v7].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x10002590
// Name: public: bool CUtlRBTree<struct CLocalize::fastvalue_t,int,bool (*)(struct CLocalize::fastvalue_t const __near &,struct CLocalize::fastvalue_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::fastvalue_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl*)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1001E6B8 = -1;
    dword_1001E6BC = -1;
    dword_1001E6C0 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *)&`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1001E6B8 = -1;
    dword_1001E6BC = -1;
    dword_1001E6C0 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x10002640
// Name: public: bool CUtlRBTree<struct CLocalize::fastvalue_t,int,bool (*)(struct CLocalize::fastvalue_t const __near &,struct CLocalize::fastvalue_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::fastvalue_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::IsRightChild(
        CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl*)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1001E6B8 = -1;
    dword_1001E6BC = -1;
    dword_1001E6C0 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *)&`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1001E6B8 = -1;
    dword_1001E6BC = -1;
    dword_1001E6C0 = 1;
  }
  if ( m_Parent == -1 )
    return dword_1001E6B8 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x100026F0
// Name: protected: void CUtlRBTree<struct CLocalize::fastvalue_t,int,bool (*)(struct CLocalize::fastvalue_t const __near &,struct CLocalize::fastvalue_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::fastvalue_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::RotateLeft(
        CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl*)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *v8; // ecx
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *v9; // eax

  v2 = `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1001E6B8 = -1;
    dword_1001E6BC = -1;
    dword_1001E6C0 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *)&`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1001E6B8 = -1;
    dword_1001E6BC = -1;
    dword_1001E6C0 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *)&`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1001E6B8 = -1;
    dword_1001E6BC = -1;
    dword_1001E6C0 = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *)&`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_1001E6B8 = -1;
      dword_1001E6BC = -1;
      dword_1001E6C0 = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *)&`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x100028A0
// Name: protected: void CUtlRBTree<struct CLocalize::fastvalue_t,int,bool (*)(struct CLocalize::fastvalue_t const __near &,struct CLocalize::fastvalue_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::fastvalue_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::RotateRight(
        CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl*)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *v6; // eax
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *v7; // eax

  v2 = `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1001E6B8 = -1;
    dword_1001E6BC = -1;
    dword_1001E6C0 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *)&`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1001E6B8 = -1;
    dword_1001E6BC = -1;
    dword_1001E6C0 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *)&`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_1001E6B8 = -1;
    dword_1001E6BC = -1;
    dword_1001E6C0 = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *)&`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x10002A10
// Name: public: virtual enum InitReturnVal_t CLocalize::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLocalize::Init(CLocalize *this)
{
  int v2; // eax

  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  v2 = _CommandLine();
  this->m_bUseOnlyLongestLanguageString = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(
                                            a1: v2,
                                            a2: "-all_languages") > 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10002A50
// Name: public: virtual void CLocalize::RemoveChangeCallback(class ILocalizationChangeCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalize::RemoveChangeCallback(CLocalize *this, ILocalizationChangeCallback *pCallback)
{
  CUtlVector<ILocalizationChangeCallback *,CUtlMemory<ILocalizationChangeCallback *,int>>::FindAndRemove(
    this: &this->m_ChangeCallbacks,
    src: &pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x10002A70
// Name: public: virtual bool CLocalize::SaveToFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLocalize::SaveToFile(CLocalize *this, const char *szFileName)
{
  const char *v2; // ebx
  void *v4; // esi
  unsigned int (__thiscall *GetFirstStringIndex)(ILocalize *); // eax
  int v7; // eax
  const char *v8; // ebx
  int v9; // eax
  int unicodeNewline; // [esp+Ch] [ebp-1Ch] BYREF
  int unicodeCR; // [esp+10h] [ebp-18h] BYREF
  wchar_t *value; // [esp+14h] [ebp-14h]
  int marker; // [esp+18h] [ebp-10h] BYREF
  int unicodeTab; // [esp+1Ch] [ebp-Ch] BYREF
  unsigned int idx; // [esp+20h] [ebp-8h]
  int unicodeQuote; // [esp+24h] [ebp-4h] BYREF

  v2 = szFileName;
  v4 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: szFileName, a3: "wb", a4: 0);
  if ( v4 == nullptr )
    return 0;
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&szFileName, pStr: v2);
  marker = 65279;
  g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &marker, a3: 2, a4: v4);
  if ( this->ConvertANSIToUCS2(
         this,
         a2: "\"lang\"\r\n{\r\n\"Language\" \"English\"\r\n\"Tokens\"\r\n{\r\n",
         a3: unicodeString,
         a4: 2048) == 0 )
    return 0;
  g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: unicodeString, a3: 92, a4: v4);
  GetFirstStringIndex = this->GetFirstStringIndex;
  unicodeQuote = 34;
  unicodeCR = 13;
  unicodeNewline = 10;
  unicodeTab = 9;
  v7 = GetFirstStringIndex(this);
  idx = v7;
  if ( v7 != -1 )
  {
    while ( 1 )
    {
      if ( (_WORD)szFileName == this->m_Lookup.m_Elements.m_pMemory[v7].m_Data.filename.m_Id )
      {
        v8 = this->GetNameByIndex(this, a2: v7);
        value = this->GetValueByIndex(this, a2: idx);
        this->ConvertANSIToUCS2(this, a2: v8, a3: unicodeString, a4: 2048);
        g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &unicodeTab, a3: 2, a4: v4);
        g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &unicodeQuote, a3: 2, a4: v4);
        g_pFullFileSystem->Write(
          this: &g_pFullFileSystem->IBaseFileSystem,
          a2: unicodeString,
          a3: 2 * strlen(v8),
          a4: v4);
        g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &unicodeQuote, a3: 2, a4: v4);
        g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &unicodeTab, a3: 2, a4: v4);
        g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &unicodeTab, a3: 2, a4: v4);
        g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &unicodeQuote, a3: 2, a4: v4);
        g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: value, a3: 2 * wcslen(value), a4: v4);
        g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &unicodeQuote, a3: 2, a4: v4);
        g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &unicodeCR, a3: 2, a4: v4);
        g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &unicodeNewline, a3: 2, a4: v4);
        v7 = idx;
      }
      idx = this->GetNextStringIndex(this, a2: v7);
      if ( idx == -1 )
        break;
      v7 = idx;
    }
  }
  v9 = this->ConvertANSIToUCS2(this, a2: "}\r\n}\r\n", a3: unicodeString, a4: 2048);
  g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: unicodeString, a3: 2 * v9, a4: v4);
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10002D30
// Name: public: virtual wchar_t __near * CLocalize::Find(char const __near *)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__thiscall CLocalize::Find(CLocalize *this, const char *pName)
{
  unsigned int v3; // eax

  v3 = this->FindIndex(this, a2: pName);
  if ( v3 == -1 )
    return nullptr;
  else
    return &this->m_Values.m_Memory.m_pMemory[this->m_Lookup.m_Elements.m_pMemory[v3].m_Data.valueIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10002D70
// Name: public: virtual char const __near * CLocalize::GetNameByIndex(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CLocalize::GetNameByIndex(CLocalize *this, unsigned int index)
{
  return &this->m_Names.m_Memory.m_pMemory[this->m_Lookup.m_Elements.m_pMemory[index].m_Data.nameIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10002D90
// Name: public: virtual wchar_t __near * CLocalize::GetValueByIndex(unsigned int)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__thiscall CLocalize::GetValueByIndex(CLocalize *this, unsigned int index)
{
  if ( index == -1 )
    return nullptr;
  else
    return &this->m_Values.m_Memory.m_pMemory[this->m_Lookup.m_Elements.m_pMemory[index].m_Data.valueIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10002DC0
// Name: public: virtual char const __near * CLocalize::GetFileNameByIndex(unsigned int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CLocalize::GetFileNameByIndex(CLocalize *this, unsigned int index)
{
  return CUtlSymbol::String(this: &this->m_Lookup.m_Elements.m_pMemory[index].m_Data.filename);
}

//------------------------------------------------------------------------------
// Address: 0x10002DF0
// Name: public: unsigned int CUtlRBTree<struct CLocalize::localizedstring_t,unsigned int,bool (*)(struct CLocalize::localizedstring_t const __near &,struct CLocalize::localizedstring_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Find(struct CLocalize::localizedstring_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Find(
        CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl*)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int> > *this,
        const CLocalize::localizedstring_t *search)
{
  unsigned int m_Root; // edi
  unsigned int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
        dword_1001E6A4 = -1;
        dword_1001E6A8 = -1;
        dword_1001E6AC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
        dword_1001E6A4 = -1;
        dword_1001E6A8 = -1;
        dword_1001E6AC = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x10002EF0
// Name: public: void CUtlRBTree<struct CLocalize::localizedstring_t,unsigned int,bool (*)(struct CLocalize::localizedstring_t const __near &,struct CLocalize::localizedstring_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::localizedstring_t,unsigned int>,unsigned int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::RemoveAll(
        CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl*)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int> > *this)
{
  unsigned int index; // eax
  BOOL v3; // ecx
  signed int v4; // esi
  signed int v5; // eax

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v3 = this->m_Elements.m_nAllocationCount > 0;
    v4 = v3 - 1;
    if ( v3 )
    {
      do
      {
        if ( v4 >= 0
          && v4 < this->m_Elements.m_nAllocationCount
          && v4 <= index
          && CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::LeftChild(
               this,
               i: v4) != v4 )
        {
          v5 = v4;
          this->m_Elements.m_pMemory[v5].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v5].m_Left = v4;
          this->m_FirstFree = v4;
        }
        index = this->m_LastAlloc.index;
        if ( v4 == index )
          break;
        if ( ++v4 < 0 || v4 >= this->m_Elements.m_nAllocationCount )
          v4 = -1;
      }
      while ( v4 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002F90
// Name: public: unsigned int CUtlRBTree<struct CLocalize::localizedstring_t,unsigned int,bool (*)(struct CLocalize::localizedstring_t const __near &,struct CLocalize::localizedstring_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::localizedstring_t,unsigned int>,unsigned int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::FirstInorder(
        CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl*)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int> > *this)
{
  int v1; // ebx
  unsigned int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
      dword_1001E6A4 = -1;
      dword_1001E6A8 = -1;
      dword_1001E6AC = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
      dword_1001E6A4 = -1;
      dword_1001E6A8 = -1;
      dword_1001E6AC = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10003040
// Name: public: unsigned int CUtlRBTree<struct CLocalize::localizedstring_t,unsigned int,bool (*)(struct CLocalize::localizedstring_t const __near &,struct CLocalize::localizedstring_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::localizedstring_t,unsigned int>,unsigned int>>::NextInorder(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::NextInorder(
        CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl*)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int> > *this,
        unsigned int i)
{
  UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *v3; // eax
  unsigned int result; // eax
  int v5; // edx
  int *v6; // ecx
  unsigned int m_Parent; // esi
  unsigned int v8; // ecx

  if ( (`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
    dword_1001E6A4 = -1;
    dword_1001E6A8 = -1;
    dword_1001E6AC = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *)&`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
          dword_1001E6A4 = -1;
          dword_1001E6A8 = -1;
          dword_1001E6AC = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
        dword_1001E6A4 = -1;
        dword_1001E6A8 = -1;
        dword_1001E6AC = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
        dword_1001E6A4 = -1;
        dword_1001E6A8 = -1;
        dword_1001E6AC = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100031C0
// Name: public: int CUtlRBTree<struct CLocalize::fastvalue_t,int,bool (*)(struct CLocalize::fastvalue_t const __near &,struct CLocalize::fastvalue_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::fastvalue_t,int>,int>>::Find(struct CLocalize::fastvalue_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Find(
        CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl*)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int> > *this,
        const CLocalize::fastvalue_t *search)
{
  int m_Root; // edi
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1001E6B8 = -1;
        dword_1001E6BC = -1;
        dword_1001E6C0 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1001E6B8 = -1;
        dword_1001E6BC = -1;
        dword_1001E6C0 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x100032B0
// Name: public: void CUtlRBTree<struct CLocalize::fastvalue_t,int,bool (*)(struct CLocalize::fastvalue_t const __near &,struct CLocalize::fastvalue_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::fastvalue_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::RemoveAll(
        CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl*)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1001E6B8 = -1;
            dword_1001E6BC = -1;
            dword_1001E6C0 = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003370
// Name: public: int CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::InsertMultipleBefore(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  wchar_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<wchar_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 2 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100033E0
// Name: public: int CUtlVector<struct CLocalize::LocalizationFileInfo_t,class CUtlMemory<struct CLocalize::LocalizationFileInfo_t,int>>::InsertBefore(int,struct CLocalize::LocalizationFileInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CLocalize::LocalizationFileInfo_t,CUtlMemory<CLocalize::LocalizationFileInfo_t,int>>::InsertBefore(
        CUtlVector<CLocalize::LocalizationFileInfo_t,CUtlMemory<CLocalize::LocalizationFileInfo_t,int> > *this,
        int elem,
        const CLocalize::LocalizationFileInfo_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CLocalize::LocalizationFileInfo_t *m_pMemory; // ecx
  int v7; // eax
  CLocalize::LocalizationFileInfo_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CLocalize::LocalizationFileInfo_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 6 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10003460
// Name: protected: void CUtlRBTree<struct CLocalize::localizedstring_t,unsigned int,bool (*)(struct CLocalize::localizedstring_t const __near &,struct CLocalize::localizedstring_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::localizedstring_t,unsigned int>,unsigned int>>::InsertRebalance(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::InsertRebalance(
        CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl*)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int> > *this,
        unsigned int elem)
{
  unsigned int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *v5; // ecx
  unsigned int m_Parent; // ecx
  UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *v7; // ecx
  UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *v8; // ecx
  unsigned int v9; // esi
  UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *v10; // eax
  unsigned int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *v14; // eax
  unsigned int m_Right; // eax
  UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *v18; // ecx
  UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *v19; // eax
  UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *v20; // eax
  UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *v23; // ecx
  UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
        dword_1001E6A4 = -1;
        dword_1001E6A8 = -1;
        dword_1001E6AC = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *)&`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
        dword_1001E6A4 = -1;
        dword_1001E6A8 = -1;
        dword_1001E6AC = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *)&`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
        dword_1001E6A4 = -1;
        dword_1001E6A8 = -1;
        dword_1001E6AC = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *)&`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
        dword_1001E6A4 = -1;
        dword_1001E6A8 = -1;
        dword_1001E6AC = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *)&`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
          dword_1001E6A4 = -1;
          dword_1001E6A8 = -1;
          dword_1001E6AC = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *)&`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
          dword_1001E6A4 = -1;
          dword_1001E6A8 = -1;
          dword_1001E6AC = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *)&`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
            dword_1001E6A4 = -1;
            dword_1001E6A8 = -1;
            dword_1001E6AC = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *)&`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
            dword_1001E6A4 = -1;
            dword_1001E6A8 = -1;
            dword_1001E6AC = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *)&`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
          dword_1001E6A4 = -1;
          dword_1001E6A8 = -1;
          dword_1001E6AC = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *)&`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
          dword_1001E6A4 = -1;
          dword_1001E6A8 = -1;
          dword_1001E6AC = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *)&`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
            dword_1001E6A4 = -1;
            dword_1001E6A8 = -1;
            dword_1001E6AC = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *)&`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel = -1;
            dword_1001E6A4 = -1;
            dword_1001E6A8 = -1;
            dword_1001E6AC = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *)&`CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003930
// Name: protected: void CUtlRBTree<struct CLocalize::fastvalue_t,int,bool (*)(struct CLocalize::fastvalue_t const __near &,struct CLocalize::fastvalue_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::fastvalue_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl*)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *v7; // ecx
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *v18; // ecx
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *v19; // eax
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *v20; // eax
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *v23; // ecx
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1001E6B8 = -1;
        dword_1001E6BC = -1;
        dword_1001E6C0 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *)&`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1001E6B8 = -1;
        dword_1001E6BC = -1;
        dword_1001E6C0 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *)&`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1001E6B8 = -1;
        dword_1001E6BC = -1;
        dword_1001E6C0 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *)&`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_1001E6B8 = -1;
        dword_1001E6BC = -1;
        dword_1001E6C0 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *)&`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1001E6B8 = -1;
          dword_1001E6BC = -1;
          dword_1001E6C0 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *)&`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1001E6B8 = -1;
          dword_1001E6BC = -1;
          dword_1001E6C0 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *)&`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1001E6B8 = -1;
            dword_1001E6BC = -1;
            dword_1001E6C0 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *)&`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1001E6B8 = -1;
            dword_1001E6BC = -1;
            dword_1001E6C0 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *)&`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1001E6B8 = -1;
          dword_1001E6BC = -1;
          dword_1001E6C0 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *)&`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_1001E6B8 = -1;
          dword_1001E6BC = -1;
          dword_1001E6C0 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *)&`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1001E6B8 = -1;
            dword_1001E6BC = -1;
            dword_1001E6C0 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *)&`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_1001E6B8 = -1;
            dword_1001E6BC = -1;
            dword_1001E6C0 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *)&`CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003D90
// Name: public: virtual unsigned int CLocalize::FindIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLocalize::FindIndex(CLocalize *this, const char *pName)
{
  const char *v2; // eax
  CLocalize::localizedstring_t invalidItem; // [esp+0h] [ebp-Ch] BYREF

  v2 = pName;
  if ( pName == nullptr )
    return -1;
  if ( *pName == 35 )
    v2 = pName + 1;
  invalidItem.valueIndex = (unsigned int)v2;
  invalidItem.filename.m_Id = -1;
  invalidItem.nameIndex = -1;
  return CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Find(
           this: &this->m_Lookup,
           search: &invalidItem);
}

//------------------------------------------------------------------------------
// Address: 0x10003DE0
// Name: public: virtual void CLocalize::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalize::RemoveAll(CLocalize *this)
{
  CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::RemoveAll(this: &this->m_Lookup);
  this->m_Names.m_Size = 0;
  this->m_Values.m_Size = 0;
  this->m_LocalizationFiles.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003E00
// Name: public: virtual unsigned int CLocalize::GetFirstStringIndex(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLocalize::GetFirstStringIndex(CLocalize *this)
{
  return CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::FirstInorder(this: &this->m_Lookup);
}

//------------------------------------------------------------------------------
// Address: 0x10003E10
// Name: public: virtual unsigned int CLocalize::GetNextStringIndex(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLocalize::GetNextStringIndex(CLocalize *this, unsigned int index)
{
  return CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::NextInorder(
           this: &this->m_Lookup,
           i: index);
}

//------------------------------------------------------------------------------
// Address: 0x10003E30
// Name: public: virtual wchar_t __near * CLocalize::GetAsianFrequencySequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__thiscall CLocalize::GetAsianFrequencySequence(CLocalize *this, const char *pLanguage)
{
  unsigned int v3; // esi
  unsigned __int8 *m_pMemory; // edi
  unsigned int i; // eax
  wchar_t *result; // eax
  char szFileName[128]; // [esp+4h] [ebp-80h] BYREF

  if ( !this->m_bAsianFrequencySequenceLoaded )
  {
    this->m_bAsianFrequencySequenceLoaded = true;
    V_snprintf(pDest: szFileName, maxLen: 128, pFormat: "resource/%s_frequency.txt", pLanguage);
    g_pFullFileSystem->ReadFile(
      this: &g_pFullFileSystem->IBaseFileSystem,
      a2: szFileName,
      a3: "GAME",
      a4: &this->m_bufAsianFrequencySequence,
      a5: 0,
      a6: 0,
      a7: nullptr);
    v3 = (unsigned int)this->m_bufAsianFrequencySequence.m_Put >> 1;
    if ( (this->m_bufAsianFrequencySequence.m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: &this->m_bufAsianFrequencySequence, pFmt: "%hu", 0);
    else
      CUtlBuffer::PutTypeBin<unsigned short>(this: &this->m_bufAsianFrequencySequence, src: 0);
    m_pMemory = this->m_bufAsianFrequencySequence.m_Memory.m_pMemory;
    if ( *(_WORD *)m_pMemory == 0xFFFE )
    {
      for ( i = 0; i < v3; ++i )
        *(_WORD *)&m_pMemory[2 * i] = __ROL2__(*(_WORD *)&m_pMemory[2 * i], 8);
    }
  }
  if ( this->m_bufAsianFrequencySequence.m_Put <= 2 )
    return nullptr;
  result = (wchar_t *)this->m_bufAsianFrequencySequence.m_Memory.m_pMemory;
  if ( *result == 0xFEFF )
    ++result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10003F10
// Name: public: CUtlRBTree<struct CLocalize::localizedstring_t,unsigned int,bool (*)(struct CLocalize::localizedstring_t const __near &,struct CLocalize::localizedstring_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::localizedstring_t,unsigned int>,unsigned int>>::~CUtlRBTree<struct CLocalize::localizedstring_t,unsigned int,bool (*)(struct CLocalize::localizedstring_t const __near &,struct CLocalize::localizedstring_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::localizedstring_t,unsigned int>,unsigned int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::~CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>(
        CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl*)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int> > *this)
{
  CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003F70
// Name: public: int CUtlVector<char,class CUtlMemory<char,int>>::AddMultipleToTail(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char,CUtlMemory<char,int>>::AddMultipleToTail(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        int num)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v6; // eax

  m_Size = this->m_Size;
  if ( num != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( m_Size + num > m_nAllocationCount )
      CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: num + m_Size - m_nAllocationCount);
    this->m_Size += num;
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = this->m_Size - m_Size - num;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v6 > 0 && num > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + num], src: &m_pMemory[m_Size], count: v6);
  }
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10003FD0
// Name: public: CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>::~CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(
        CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *this)
{
  bool v2; // sf
  CUtlSymbolTable::StringPool_t **m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004040
// Name: public: CUtlRBTree<struct CLocalize::fastvalue_t,int,bool (*)(struct CLocalize::fastvalue_t const __near &,struct CLocalize::fastvalue_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::fastvalue_t,int>,int>>::~CUtlRBTree<struct CLocalize::fastvalue_t,int,bool (*)(struct CLocalize::fastvalue_t const __near &,struct CLocalize::fastvalue_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::fastvalue_t,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::~CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>(
        CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl*)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int> > *this)
{
  CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100040A0
// Name: protected: void CUtlRBTree<struct CLocalize::localizedstring_t,unsigned int,bool (*)(struct CLocalize::localizedstring_t const __near &,struct CLocalize::localizedstring_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::localizedstring_t,unsigned int>,unsigned int>>::LinkToParent(unsigned int,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::LinkToParent(
        CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl*)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int> > *this,
        unsigned int i,
        unsigned int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *v4; // eax
  UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004120
// Name: public: virtual enum AppSystemTier_t CTier2AppSystem<class ILocalize,0>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTier2AppSystem<ILocalize,0>::GetTier(CTier2AppSystem<ILocalize,0> *this)
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x10004130
// Name: public: virtual bool CTier2AppSystem<class ILocalize,0>::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTier2AppSystem<ILocalize,0>::Connect(
        CTier2AppSystem<ILocalize,0> *this,
        void *(__cdecl *factory)(const char *, int *))
{
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+0h] [ebp-4h] BYREF

  pFactoryList = factory;
  ConnectTier1Libraries(&pFactoryList, nFactoryCount: 1);
  ConnectTier2Libraries(pFactoryList: &factory, nFactoryCount: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004160
// Name: public: virtual void CTier2AppSystem<class ILocalize,0>::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTier2AppSystem<ILocalize,0>::Shutdown(CTier2AppSystem<ILocalize,0> *this)
{
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x10004170
// Name: public: virtual void CTier2AppSystem<class ILocalize,0>::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTier2AppSystem<ILocalize,0>::Disconnect(CTier2AppSystem<ILocalize,0> *this)
{
  DisconnectTier2Libraries();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x10004180
// Name: public: virtual CLocalize::~CLocalize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalize::~CLocalize(CLocalize *this)
{
  this->__vftable = (CLocalize_vtbl *)&CLocalize::`vftable';
  this->m_Names.m_Size = 0;
  if ( this->m_Names.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Names.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Names.m_Memory.m_pMemory);
      this->m_Names.m_Memory.m_pMemory = nullptr;
    }
    this->m_Names.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Names.m_pElements = this->m_Names.m_Memory.m_pMemory;
  this->m_Values.m_Size = 0;
  if ( this->m_Values.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Values.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Values.m_Memory.m_pMemory);
      this->m_Values.m_Memory.m_pMemory = nullptr;
    }
    this->m_Values.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Values.m_pElements = this->m_Values.m_Memory.m_pMemory;
  this->m_LocalizationFiles.m_Size = 0;
  if ( this->m_LocalizationFiles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_LocalizationFiles.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_LocalizationFiles.m_Memory.m_pMemory);
      this->m_LocalizationFiles.m_Memory.m_pMemory = nullptr;
    }
    this->m_LocalizationFiles.m_Memory.m_nAllocationCount = 0;
  }
  this->m_LocalizationFiles.m_pElements = this->m_LocalizationFiles.m_Memory.m_pMemory;
  if ( this->m_bufAsianFrequencySequence.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_bufAsianFrequencySequence.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_bufAsianFrequencySequence.m_Memory.m_pMemory);
      this->m_bufAsianFrequencySequence.m_Memory.m_pMemory = nullptr;
    }
    this->m_bufAsianFrequencySequence.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_ChangeCallbacks);
  CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::~CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>(this: &this->m_FastValueLookup);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_LocalizationFiles);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Values);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Names);
  CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::~CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>(this: &this->m_Lookup);
}

//------------------------------------------------------------------------------
// Address: 0x100042C0
// Name: public: virtual void CLocalize::InstallChangeCallback(class ILocalizationChangeCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalize::InstallChangeCallback(CLocalize *this, ILocalizationChangeCallback *pCallback)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_ChangeCallbacks; // esi
  int m_Size; // ecx
  int v4; // eax
  ILocalizationChangeCallback **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax

  p_m_ChangeCallbacks = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_ChangeCallbacks;
  m_Size = this->m_ChangeCallbacks.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_5;
  m_pMemory = (ILocalizationChangeCallback **)p_m_ChangeCallbacks->m_pMemory;
  while ( *m_pMemory != pCallback )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_5;
  }
  if ( v4 == -1 )
  {
LABEL_5:
    m_nAllocationCount = p_m_ChangeCallbacks->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<ILocalizationChangeCallback *,int>::Grow(
        this: p_m_ChangeCallbacks,
        num: m_Size - m_nAllocationCount + 1);
    ++p_m_ChangeCallbacks[1].m_pMemory;
    v8 = p_m_ChangeCallbacks->m_pMemory;
    v9 = (int)p_m_ChangeCallbacks[1].m_pMemory - v7 - 1;
    p_m_ChangeCallbacks[1].m_nAllocationCount = (int)p_m_ChangeCallbacks->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_ChangeCallbacks->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (CUtlSymbolTable::StringPool_t *)pCallback;
  }
  else
  {
    _Warning(a1: "CLocalize::InstallChangeCallback: Attempted to add the same callback twice!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004360
// Name: public: virtual void CLocalize::SetValueByIndex(unsigned int,wchar_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalize::SetValueByIndex(CLocalize *this, unsigned int index, wchar_t *newValue)
{
  const unsigned __int16 *v4; // edx
  signed int v5; // edi
  int inserted; // eax
  wchar_t *v7; // eax
  int v8; // edx
  wchar_t v9; // cx
  int m_Size; // edi
  int i; // esi
  ILocalizationChangeCallback *v12; // ecx
  CLocalize::localizedstring_t *lstr; // [esp+Ch] [ebp-4h]

  lstr = &this->m_Lookup.m_Elements.m_pMemory[index].m_Data;
  v4 = &this->m_Values.m_Memory.m_pMemory[this->m_Lookup.m_Elements.m_pMemory[index].m_Data.valueIndex];
  v5 = wcslen(newValue);
  if ( v5 <= (int)wcslen(v4) )
  {
    v7 = newValue;
    v8 = (char *)v4 - (char *)newValue;
    do
    {
      v9 = *v7;
      *(wchar_t *)((char *)v7 + v8) = *v7;
      ++v7;
    }
    while ( v9 != 0 );
  }
  else
  {
    inserted = CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::InsertMultipleBefore(
                 this: &this->m_Values,
                 elem: this->m_Values.m_Size,
                 num: v5 + 1);
    lstr->valueIndex = inserted;
    memcpy(
      dst: (unsigned __int8 *)&this->m_Values.m_Memory.m_pMemory[inserted],
      src: (unsigned __int8 *)newValue,
      count: 2 * v5 + 2);
  }
  if ( this->m_bSuppressChangeCallbacks )
  {
    this->m_bQueuedChangeCallback = true;
  }
  else
  {
    m_Size = this->m_ChangeCallbacks.m_Size;
    for ( i = 0; i < m_Size; ++i )
    {
      v12 = this->m_ChangeCallbacks.m_Memory.m_pMemory[i];
      v12->OnLocalizationChanged(this: v12);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004450
// Name: public: CLocalize::CLocalize(void)
// Source: json
//------------------------------------------------------------------------------
CLocalize *__thiscall CLocalize::CLocalize(CLocalize *this)
{
  this->__vftable = (CLocalize_vtbl *)&CLocalize::`vftable';
  this->m_Lookup.m_LessFunc = CLocalize::SymLess;
  this->m_Lookup.m_Elements.m_pMemory = nullptr;
  this->m_Lookup.m_Elements.m_nAllocationCount = 0;
  this->m_Lookup.m_Elements.m_nGrowSize = 0;
  this->m_Lookup.m_NumElements = 0;
  this->m_Lookup.m_Root = -1;
  this->m_Lookup.m_FirstFree = -1;
  this->m_Lookup.m_LastAlloc.index = -1;
  this->m_Lookup.m_pElements = this->m_Lookup.m_Elements.m_pMemory;
  this->m_Names.m_Memory.m_pMemory = nullptr;
  this->m_Names.m_Memory.m_nAllocationCount = 0;
  this->m_Names.m_Memory.m_nGrowSize = 1024;
  this->m_Names.m_Size = 0;
  this->m_Names.m_pElements = nullptr;
  this->m_Values.m_Memory.m_pMemory = nullptr;
  this->m_Values.m_Memory.m_nAllocationCount = 0;
  this->m_Values.m_Memory.m_nGrowSize = 2048;
  this->m_Values.m_Size = 0;
  this->m_Values.m_pElements = nullptr;
  this->m_CurrentFile.m_Id = -1;
  this->m_LocalizationFiles.m_Memory.m_pMemory = nullptr;
  this->m_LocalizationFiles.m_Memory.m_nAllocationCount = 0;
  this->m_LocalizationFiles.m_Memory.m_nGrowSize = 0;
  this->m_LocalizationFiles.m_Size = 0;
  this->m_LocalizationFiles.m_pElements = nullptr;
  this->m_FastValueLookup.m_LessFunc = CLocalize::FastValueLessFunc;
  this->m_FastValueLookup.m_Elements.m_pMemory = nullptr;
  this->m_FastValueLookup.m_Elements.m_nAllocationCount = 0;
  this->m_FastValueLookup.m_Elements.m_nGrowSize = 0;
  this->m_FastValueLookup.m_Root = -1;
  this->m_FastValueLookup.m_FirstFree = -1;
  this->m_FastValueLookup.m_NumElements = 0;
  this->m_FastValueLookup.m_LastAlloc.index = -1;
  this->m_FastValueLookup.m_pElements = this->m_FastValueLookup.m_Elements.m_pMemory;
  this->m_ChangeCallbacks.m_Memory.m_pMemory = nullptr;
  this->m_ChangeCallbacks.m_Memory.m_nAllocationCount = 0;
  this->m_ChangeCallbacks.m_Memory.m_nGrowSize = 0;
  this->m_ChangeCallbacks.m_Size = 0;
  this->m_ChangeCallbacks.m_pElements = nullptr;
  CUtlBuffer::CUtlBuffer(this: &this->m_bufAsianFrequencySequence, growSize: 0, initSize: 0, nFlags: 0);
  *(_WORD *)&this->m_bUseOnlyLongestLanguageString = 0;
  this->m_bQueuedChangeCallback = false;
  this->m_pQuery = nullptr;
  this->m_bAsianFrequencySequenceLoaded = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100045A0
// Name: public: unsigned int CUtlRBTree<struct CLocalize::localizedstring_t,unsigned int,bool (*)(struct CLocalize::localizedstring_t const __near &,struct CLocalize::localizedstring_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Insert(struct CLocalize::localizedstring_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Insert(
        CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl*)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int> > *this,
        const CLocalize::localizedstring_t *insert)
{
  unsigned int v3; // edi
  UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *m_pMemory; // edx
  unsigned int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = -1;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::FindInsertionPosition(
    this,
    insert,
    &parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::NewNode(this);
  CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v3] != (UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int> *)-16 )
  {
    m_pMemory[v3].m_Data.nameIndex = insert->nameIndex;
    m_pMemory[v3].m_Data.valueIndex = insert->valueIndex;
    m_pMemory[v3].m_Data.valueIndex = insert->valueIndex;
    m_pMemory[v3].m_Data.filename.m_Id = insert->filename.m_Id;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10004620
// Name: public: virtual void CLocalize::AddString(char const __near *,wchar_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalize::AddString(CLocalize *this, wchar_t *pString, wchar_t *pValue, const char *fileName)
{
  const char *v4; // ebx
  int v6; // eax
  wchar_t *v7; // eax
  __int16 v8; // cx
  int v9; // ebx
  const wchar_t *inserted; // eax
  wchar_t *m_pMemory; // edx
  unsigned int v12; // edi
  unsigned int v13; // kr00_4
  wchar_t *v14; // eax
  CUtlSymbol *v15; // eax
  int v16; // ebx
  char *v17; // ebx
  const char *v18; // eax
  unsigned int nameIndex; // eax
  CUtlSymbol *v20; // ecx
  CLocalize::localizedstring_t *p_m_Data; // ecx
  unsigned __int8 *v22; // [esp-10h] [ebp-2Ch]
  CLocalize::localizedstring_t item; // [esp+8h] [ebp-14h] BYREF
  CLocalize::fastvalue_t search; // [esp+14h] [ebp-8h] BYREF
  wchar_t *oldValue; // [esp+24h] [ebp+8h]

  v4 = (const char *)pString;
  if ( pString != nullptr )
  {
    if ( CLocalize::s_pTable == nullptr
      || (search.valueindex = -1,
          search.search = pValue,
          (v6 = CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::Find(
                  this: &this->m_FastValueLookup,
                  &search)) == -1)
      || (search.search = (const wchar_t *)this->m_FastValueLookup.m_Elements.m_pMemory[v6].m_Data.valueindex,
          search.search == (const wchar_t *)-1) )
    {
      v7 = pValue;
      do
        v8 = *v7++;
      while ( v8 != 0 );
      v9 = v7 - (pValue + 1) + 1;
      inserted = (const wchar_t *)CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::InsertMultipleBefore(
                                    this: &this->m_Values,
                                    elem: this->m_Values.m_Size,
                                    num: v9);
      m_pMemory = this->m_Values.m_Memory.m_pMemory;
      search.search = inserted;
      memcpy(dst: (unsigned __int8 *)&m_pMemory[(_DWORD)inserted], src: (unsigned __int8 *)pValue, count: 2 * v9);
      v4 = (const char *)pString;
    }
    v12 = this->FindIndex(this, a2: v4);
    item.filename.m_Id = -1;
    item.nameIndex = v12;
    if ( v12 == -1 )
    {
      v13 = strlen(v4);
      v14 = (wchar_t *)CUtlVector<char,CUtlMemory<char,int>>::AddMultipleToTail(this: &this->m_Names, num: v13 + 1);
      v22 = (unsigned __int8 *)v14 + (unsigned int)this->m_Names.m_Memory.m_pMemory;
      pValue = v14;
      memcpy(dst: v22, src: (unsigned __int8 *)pString, count: v13 + 1);
      item.valueIndex = (unsigned int)search.search;
      item.nameIndex = (unsigned int)pValue;
      if ( fileName != nullptr )
      {
        v15 = CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&pValue + 1, pStr: fileName);
      }
      else
      {
        HIWORD(pValue) = this->m_CurrentFile.m_Id;
        v15 = (CUtlSymbol *)&pValue + 1;
      }
      item.filename = (CUtlSymbol)v15->m_Id;
      CUtlRBTree<CLocalize::localizedstring_t,unsigned int,bool (__cdecl *)(CLocalize::localizedstring_t const &,CLocalize::localizedstring_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::localizedstring_t,unsigned int>,unsigned int>>::Insert(
        this: &this->m_Lookup,
        insert: &item);
    }
    else if ( !this->m_bUseOnlyLongestLanguageString
           || (oldValue = this->GetValueByIndex(this, a2: v12), this->m_pQuery == nullptr)
           || (v16 = this->m_pQuery->ComputeTextWidth(this: this->m_pQuery, a2: pValue)) >= this->m_pQuery->ComputeTextWidth(
                                                                                              this: this->m_pQuery,
                                                                                              a2: oldValue) )
    {
      v17 = this->m_Names.m_Memory.m_pMemory;
      v18 = this->GetNameByIndex(this, a2: v12);
      item.valueIndex = (unsigned int)search.search;
      nameIndex = v18 - v17;
      item.nameIndex = nameIndex;
      if ( fileName != nullptr )
      {
        v20 = CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&pValue + 1, pStr: fileName);
        nameIndex = item.nameIndex;
      }
      else
      {
        HIWORD(pValue) = this->m_CurrentFile.m_Id;
        v20 = (CUtlSymbol *)&pValue + 1;
      }
      item.filename = (CUtlSymbol)v20->m_Id;
      p_m_Data = &this->m_Lookup.m_Elements.m_pMemory[v12].m_Data;
      p_m_Data->nameIndex = nameIndex;
      p_m_Data->valueIndex = item.valueIndex;
      p_m_Data->valueIndex = item.valueIndex;
      p_m_Data->filename.m_Id = item.filename.m_Id;
      CLocalize::InvokeChangeCallbacks(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004820
// Name: private: void CLocalize::BuildFastValueLookup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalize::BuildFastValueLookup(CLocalize *this)
{
  CLocalize *v1; // edi
  CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl*)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int> > *p_m_FastValueLookup; // esi
  int v3; // ebx
  int v4; // eax
  int v5; // edx
  int v6; // edi
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *v7; // ecx
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *m_pMemory; // ecx
  int v9; // edx
  UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *v10; // edx
  CLocalize::fastvalue_t val; // [esp+8h] [ebp-18h] BYREF
  CLocalize *v12; // [esp+10h] [ebp-10h]
  unsigned int m_NumElements; // [esp+14h] [ebp-Ch]
  int parent; // [esp+18h] [ebp-8h] BYREF
  bool leftchild; // [esp+1Fh] [ebp-1h] BYREF

  v1 = this;
  p_m_FastValueLookup = &this->m_FastValueLookup;
  v12 = this;
  CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::RemoveAll(this: &this->m_FastValueLookup);
  CLocalize::s_pTable = v1;
  if ( (int)v1->m_Lookup.m_NumElements > 0 )
  {
    v3 = 0;
    m_NumElements = v1->m_Lookup.m_NumElements;
    while ( 1 )
    {
      val.valueindex = v1->m_Lookup.m_Elements.m_pMemory[v3].m_Data.valueIndex;
      val.search = nullptr;
      parent = -1;
      leftchild = false;
      CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::FindInsertionPosition(
        this: p_m_FastValueLookup,
        insert: &val,
        &parent,
        &leftchild);
      v4 = CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::NewNode(this: p_m_FastValueLookup);
      v5 = parent;
      v6 = v4;
      v7 = &p_m_FastValueLookup->m_Elements.m_pMemory[v4];
      v7->m_Parent = parent;
      v7->m_Right = -1;
      v7->m_Left = -1;
      v7->m_Tag = 0;
      if ( v5 == -1 )
      {
        p_m_FastValueLookup->m_Root = v4;
      }
      else
      {
        m_pMemory = p_m_FastValueLookup->m_Elements.m_pMemory;
        v9 = v5;
        if ( leftchild )
          m_pMemory[v9].m_Left = v4;
        else
          m_pMemory[v9].m_Right = v4;
      }
      CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::InsertRebalance(
        this: p_m_FastValueLookup,
        elem: v4);
      v10 = p_m_FastValueLookup->m_Elements.m_pMemory;
      ++p_m_FastValueLookup->m_NumElements;
      if ( &v10[v6] != (UtlRBTreeNode_t<CLocalize::fastvalue_t,int> *)-16 )
        v10[v6].m_Data = val;
      ++v3;
      if ( --m_NumElements == 0 )
        break;
      v1 = v12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004910
// Name: private: bool CLocalize::ReadLocalizationFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLocalize::ReadLocalizationFile(CLocalize *this, char *pRelativePath, const char *pPathID)
{
  void *(__thiscall *Open)(IBaseFileSystem *, const char *, const char *, const char *); // eax
  void *v5; // esi
  unsigned int v6; // edi
  unsigned int v7; // ebx
  unsigned __int16 *v8; // eax
  IFileSystem_vtbl *v9; // edx
  bool v10; // bl
  unsigned int v11; // eax
  unsigned __int16 *v12; // edi
  int v13; // eax
  int v14; // eax
  CLocalize *v15; // ebx
  wchar_t *UnicodeToken; // esi
  wchar_t *v17; // edi
  wchar_t v18; // cx
  int v19; // edx
  wchar_t *v20; // eax
  int v21; // ecx
  wchar_t *v22; // esi
  int v23; // eax
  int v24; // eax
  wchar_t v26[4096]; // [esp+Ch] [ebp-622Ch] BYREF
  unsigned __int8 source[4096]; // [esp+200Ch] [ebp-422Ch] BYREF
  wchar_t v28[4096]; // [esp+300Ch] [ebp-322Ch] BYREF
  unsigned __int8 str1[4096]; // [esp+500Ch] [ebp-122Ch] BYREF
  wchar_t token[128]; // [esp+600Ch] [ebp-22Ch] BYREF
  CExpressionEvaluator v31; // [esp+610Ch] [ebp-12Ch] BYREF
  char s1[128]; // [esp+61A8h] [ebp-90h] BYREF
  CLocalize *v33; // [esp+6228h] [ebp-10h]
  unsigned __int16 *outputBuffer; // [esp+622Ch] [ebp-Ch] BYREF
  CByteswap v35; // [esp+6230h] [ebp-8h] BYREF
  CUtlSymbol v36; // [esp+6234h] [ebp-4h] BYREF
  bool bResult; // [esp+6236h] [ebp-2h] BYREF
  bool v38; // [esp+6237h] [ebp-1h]
  bool pStr_3; // [esp+6243h] [ebp+Bh]

  Open = g_pFullFileSystem->Open;
  v33 = this;
  v5 = Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: pRelativePath, a3: "rb", a4: pPathID);
  if ( v5 == nullptr )
    return 0;
  CUtlSymbol::CUtlSymbol(this: &v36, pStr: pRelativePath);
  this->m_CurrentFile = v36;
  v6 = g_pFullFileSystem->Size_2(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5);
  v7 = v6 + 2;
  if ( g_pFullFileSystem->GetOptimalIOConstraints(
         this: g_pFullFileSystem,
         a2: v5,
         a3: (unsigned int *)&outputBuffer,
         a4: nullptr,
         a5: nullptr) )
  {
    v7 = ~((unsigned int)outputBuffer - 1) & ((unsigned int)outputBuffer + v7 - 1);
  }
  v8 = (unsigned __int16 *)g_pFullFileSystem->AllocOptimalReadBuffer(this: g_pFullFileSystem, a2: v5, a3: v7, a4: 0);
  v9 = g_pFullFileSystem->IAppSystem::__vftable;
  outputBuffer = v8;
  v10 = v9->ReadEx(this: g_pFullFileSystem, a2: v8, a3: v7, a4: v6, a5: v5) != 0;
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5);
  v11 = v6;
  v12 = outputBuffer;
  v13 = v11 >> 1;
  outputBuffer[v13] = 0;
  if ( !v10 || *v12 != 0xFEFF )
  {
    _Msg(a1: "Ignoring non-unicode close caption file %s\n", pRelativePath);
    g_pFullFileSystem->FreeOptimalReadBuffer(this: g_pFullFileSystem, a2: v12);
    v33->m_CurrentFile.m_Id = -1;
    return 0;
  }
  v35 = (CByteswap)(*(_DWORD *)&v35 & 0xFFFFFFFC);
  CByteswap::SwapBufferToTargetEndian<unsigned short>(
    this: &v35,
    outputBuffer: (unsigned __int8 *)v12,
    inputBuffer: (unsigned __int8 *)v12,
    count: v13);
  v38 = V_stristr(pStr: pRelativePath, pSearch: "_english.txt") != nullptr;
  v14 = _CommandLine();
  pStr_3 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v14 + 40))(a1: v14, a2: "-ccsyntax") != 0;
  v15 = v33;
  CLocalize::BuildFastValueLookup(this: v33);
  CExpressionEvaluator::CExpressionEvaluator(this: &v31);
  v35 = 0;
  UnicodeToken = ReadUnicodeToken(start: v12 + 1, token, tokenBufferSize: 128, quoted: (bool *)&pPathID + 3);
  if ( token[0] == 0 )
    goto LABEL_43;
  while ( 1 )
  {
    v15->ConvertUCS2ToANSI(this: v15, a2: token, a3: s1, a4: 128);
    if ( V_strncasecmp(s1, s2: "//", n: 2) != 0 )
      break;
    v17 = ReadToEndOfLine(start: UnicodeToken);
LABEL_41:
    UnicodeToken = ReadUnicodeToken(start: v17, token, tokenBufferSize: 128, quoted: (bool *)&pPathID + 3);
    if ( token[0] == 0 )
      goto LABEL_42;
  }
  if ( pStr_3 )
    _Msg(a1: "%s\n", s1);
  v18 = *UnicodeToken;
  v19 = 0;
  HIBYTE(v36.m_Id) = 1;
  v20 = UnicodeToken;
  if ( v18 != 0 )
  {
    while ( v18 != 13 )
    {
      if ( v18 != 10 )
      {
        v18 = v20[1];
        ++v20;
        ++v19;
        if ( v18 != 0 )
          continue;
      }
      goto LABEL_15;
    }
    while ( 2 )
    {
      ++v20;
      ++v19;
LABEL_15:
      v21 = *v20;
      if ( v21 == 13 || v21 == 10 )
        continue;
      break;
    }
    if ( v19 > 4095 )
    {
      _Warning(a1: "Error: Localization key value exceeds MAX_LOCALIZED_CHARS. Problem key: %s\n", s1);
      HIBYTE(v36.m_Id) = 0;
    }
  }
  v17 = ReadUnicodeToken(start: UnicodeToken, token: v28, tokenBufferSize: 4096, quoted: (bool *)&pPathID + 3);
  if ( v28[0] != 0 || HIBYTE(pPathID) != 0 )
  {
    if ( v35 != 0 )
    {
      if ( v35 == 1 )
      {
        if ( _V_stricmp(s1, s2: "}") != 0 )
        {
          if ( v38 || V_strncasecmp(s1, s2: "[english]", n: 9) != 0 )
          {
            bResult = true;
            v22 = ReadUnicodeToken(start: v17, token: v26, tokenBufferSize: 4096, quoted: (bool *)&pPathID + 3);
            _V_UCS2ToUTF8(a1: v26, a2: str1, a3: 4096);
            if ( HIBYTE(pPathID) == 0 )
            {
              strstr(str1, str2: "[$");
              if ( v23 != 0 || (strstr(str1, str2: "[!$"), v24 != 0) )
              {
                v15->ConvertUCS2ToANSI(this: v15, a2: v26, a3: (char *)source, a4: 4096);
                CExpressionEvaluator::Evaluate(
                  this: &v31,
                  &bResult,
                  pInfixExpression: (const char *)source,
                  pGetSymbolProc: nullptr,
                  pSyntaxErrorProc: nullptr);
                v17 = v22;
              }
            }
            if ( bResult && HIBYTE(v36.m_Id) != 0 )
              v15->AddString(this: v15, a2: s1, a3: v28, a4: nullptr);
          }
        }
        else
        {
          v35 = 0;
        }
      }
    }
    else if ( _V_stricmp(s1, s2: "Language") != 0 )
    {
      if ( _V_stricmp(s1, s2: "Tokens") != 0 )
      {
        if ( _V_stricmp(s1, s2: "}") == 0 )
          goto LABEL_42;
      }
      else
      {
        v35 = (CByteswap)1;
      }
    }
    else
    {
      v15->ConvertUCS2ToANSI(this: v15, a2: v28, a3: (char *)source, a4: 4096);
      strncpy(dest: (unsigned __int8 *)v15->m_szLanguage, source, count: 0x3Fu);
    }
    goto LABEL_41;
  }
LABEL_42:
  v12 = outputBuffer;
LABEL_43:
  g_pFullFileSystem->FreeOptimalReadBuffer(this: g_pFullFileSystem, a2: v12);
  v15->m_CurrentFile.m_Id = -1;
  CUtlRBTree<CLocalize::fastvalue_t,int,bool (__cdecl *)(CLocalize::fastvalue_t const &,CLocalize::fastvalue_t const &),CUtlMemory<UtlRBTreeNode_t<CLocalize::fastvalue_t,int>,int>>::RemoveAll(this: &v15->m_FastValueLookup);
  CLocalize::s_pTable = nullptr;
  CExpressionEvaluator::~CExpressionEvaluator(this: &v31);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004E00
// Name: public: virtual bool CLocalize::AddFile(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CLocalize::AddFile@<al>(
        CLocalize *this@<ecx>,
        int a2@<edi>,
        char *szFileName,
        const char *pPathID,
        unsigned int bIncludeFallbackSearchPaths)
{
  char result; // al
  int v8; // eax
  unsigned int v9; // edi
  bool v10; // zf
  int v11; // eax
  int v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  int m_Size; // eax
  int v16; // edi
  const char *v17; // eax
  char fileName[260]; // [esp+8h] [ebp-14Ch] BYREF
  char language[64]; // [esp+10Ch] [ebp-48h] BYREF
  CLocalize::LocalizationFileInfo_t search; // [esp+14Ch] [ebp-8h] BYREF
  int success; // [esp+15Ch] [ebp+8h]
  char success_3; // [esp+15Fh] [ebp+Bh]

  memset(dst: (unsigned __int8 *)language, value: 0, count: sizeof(language));
  if ( V_IsAbsolutePath(pStr: szFileName) )
  {
    _Warning(a1: "Full paths not allowed in localization file specificaton %s\n", szFileName);
    return 0;
  }
  strstr(str1: (unsigned __int8 *)szFileName, str2: "%language%");
  if ( v8 != 0 )
  {
    v9 = v8 - (_DWORD)szFileName;
    strncpy(dest: (unsigned __int8 *)fileName, source: (unsigned __int8 *)szFileName, count: v8 - (_DWORD)szFileName);
    v10 = !this->m_bUseOnlyLongestLanguageString;
    fileName[v9] = 0;
    if ( !v10 )
      return CLocalize::AddAllLanguageFiles(this, baseFileName: fileName);
    V_strncat(pDest: fileName, pSrc: "english", destBufferSize: 0x104u, max_chars_to_copy: -1);
    V_strncat(pDest: fileName, pSrc: &szFileName[v9 + 10], destBufferSize: 0x104u, max_chars_to_copy: -1);
    success_3 = ((int (__thiscall *)(CLocalize *, char *, const char *, unsigned int, int))this->AddFile)(
                  a1: this,
                  a2: fileName,
                  a3: pPathID,
                  a4: bIncludeFallbackSearchPaths,
                  a5: a2);
    v11 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v11 + 12))(a1: v11, a2: "-language", a3: 0) != 0 )
    {
      v12 = _CommandLine();
      v13 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v12 + 32))(a1: v12);
      V_strncpy(pDest: language, pSrc: v13, maxLen: (int)"-language");
    }
    else if ( ((unsigned __int8 (__thiscall *)(vgui::ISystem *, const char *, char *))g_pVGuiSystem->GetRegistryString)(
                a1: g_pVGuiSystem,
                a2: "HKEY_CURRENT_USER\\Software\\Valve\\Steam\\Language",
                a3: language) == 0 )
    {
      return success_3;
    }
    if ( _V_stricmp(s1: language, s2: "unknown") != 0
      && strlen(language) != 0
      && _V_stricmp(s1: language, s2: "english") != 0 )
    {
      strncpy(dest: (unsigned __int8 *)fileName, source: (unsigned __int8 *)szFileName, count: v9);
      fileName[v9] = 0;
      V_strncat(pDest: fileName, pSrc: language, destBufferSize: 0x104u, max_chars_to_copy: -1);
      V_strncat(pDest: fileName, pSrc: &szFileName[v9 + 10], destBufferSize: 0x104u, max_chars_to_copy: -1);
      return ((int (__thiscall *)(CLocalize *, char *, const char *, unsigned int))this->AddFile)(
               a1: this,
               a2: fileName,
               a3: pPathID,
               a4: bIncludeFallbackSearchPaths)
           & success_3;
    }
    return success_3;
  }
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&bIncludeFallbackSearchPaths + 1, pStr: szFileName);
  search.symName.m_Id = HIWORD(bIncludeFallbackSearchPaths);
  v14 = pPathID;
  if ( pPathID == nullptr )
    v14 = (const char *)&unk_1001752C;
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&bIncludeFallbackSearchPaths + 1, pStr: v14);
  m_Size = this->m_LocalizationFiles.m_Size;
  v16 = 0;
  search.symPathID.m_Id = HIWORD(bIncludeFallbackSearchPaths);
  search.bIncludeFallbacks = false;
  success = m_Size;
  if ( m_Size > 0 )
  {
    bIncludeFallbackSearchPaths = 0;
    while ( 1 )
    {
      v17 = CUtlSymbol::String(this: &this->m_LocalizationFiles.m_Memory.m_pMemory[bIncludeFallbackSearchPaths / 6].symName);
      if ( _V_stricmp(s1: v17, s2: szFileName) == 0 )
        break;
      bIncludeFallbackSearchPaths += 6;
      if ( ++v16 >= success )
        goto LABEL_24;
    }
    if ( this->m_LocalizationFiles.m_Size - v16 - 1 > 0 )
      _V_memmove(
        dest: &this->m_LocalizationFiles.m_Memory.m_pMemory[v16],
        src: &this->m_LocalizationFiles.m_Memory.m_pMemory[v16 + 1],
        count: 6 * (this->m_LocalizationFiles.m_Size - v16 - 1));
    --this->m_LocalizationFiles.m_Size;
  }
LABEL_24:
  CUtlVector<CLocalize::LocalizationFileInfo_t,CUtlMemory<CLocalize::LocalizationFileInfo_t,int>>::InsertBefore(
    this: &this->m_LocalizationFiles,
    elem: this->m_LocalizationFiles.m_Size,
    src: &search);
  result = CLocalize::ReadLocalizationFile(this, pRelativePath: szFileName, pPathID);
  if ( result == 0 )
  {
    _Warning(a1: "ILocalize::AddFile() failed to load file \"%s\".\n", szFileName);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10006D60
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v12; // edx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree == 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      index = this->m_LastAlloc.index;
      if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
        v5 = -1;
      else
        v5 = index + 1;
    }
    v6 = v5;
    if ( v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_Elements.m_nAllocationCount;
      if ( this->m_LastAlloc.index >= v7 )
      {
        v7 = this->m_Elements.m_nAllocationCount;
        v9 = (v7 > 0) - 1;
      }
      else
      {
        v8 = this->m_LastAlloc.index;
        if ( (unsigned __int16)(v8 + 1) >= v7 )
          v9 = -1;
        else
          v9 = v8 + 1;
      }
      v6 = v9;
      if ( v9 >= v7 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[m_FirstFree].m_Right;
    this->m_pElements = v12;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006E60
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_1001F9D8 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_1001F9D8;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x10006FF0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_1001F9D8 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x10007050
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_1001F9D8 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x100070C0
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(class CUtlSymbolTable::CStringPoolIndex const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( CUtlSymbolTable::CLess::operator()(
           this: &this->m_LessFunc,
           i1: insert,
           i2: &this->m_Elements.m_pMemory[v6].m_Data) )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1001F9D8 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1001F9D8 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100071B0
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x100072B0
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x100073B0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Find(class CUtlSymbolTable::CStringPoolIndex const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *search)
{
  unsigned __int16 m_Root; // bx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( CUtlSymbolTable::CLess::operator()(
           this: &this->m_LessFunc,
           i1: search,
           i2: &this->m_Elements.m_pMemory[v4].m_Data) )
    {
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1001F9D8 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( !CUtlSymbolTable::CLess::operator()(
              this: &this->m_LessFunc,
              i1: &this->m_Elements.m_pMemory[v4].m_Data,
              i2: search) )
        return m_Root;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1001F9D8 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x100074B0
// Name: public: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 it; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    it = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
               this,
               i: it) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        ++v3;
        if ( (unsigned __int16)(it + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        it = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Root = 0xFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007570
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  int v4; // eax
  int *v5; // ecx
  int v6; // ecx
  int *v7; // ecx
  int *v8; // ecx
  unsigned __int16 v9; // di
  int *v10; // ecx
  int v11; // ecx
  int *v12; // edx
  int v13; // edx
  int *v14; // edx
  int *v15; // edx
  unsigned __int16 v16; // dx
  int *v17; // ebx
  int v18; // eax
  int *v19; // edx
  int v20; // edx
  int *v21; // eax
  int *v22; // edx
  int v23; // edx
  int *v24; // ebx
  int *v25; // edx
  int v26; // edx
  int *v27; // eax

  v2 = elem;
  while ( v2 != this->m_Root )
  {
    v4 = `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      v4 = `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
         | 1;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1001F9D8 = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v5 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v5 = (int *)&this->m_Elements.m_pMemory[v2];
    v6 = *((unsigned __int16 *)v5 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1001F9D8 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v6 == 0xFFFF )
      v7 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v7 = (int *)&this->m_Elements.m_pMemory[v6];
    if ( *((_WORD *)v7 + 3) != 0 )
      break;
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1001F9D8 = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v8 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v8 = (int *)&this->m_Elements.m_pMemory[v2];
    v9 = *((_WORD *)v8 + 2);
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1001F9D8 = 0x1FFFF;
    }
    if ( v9 == 0xFFFF )
      v10 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v10 = (int *)&this->m_Elements.m_pMemory[v9];
    v11 = *((unsigned __int16 *)v10 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1001F9D8 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( v9 == 0xFFFF )
      v12 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v12 = (int *)&this->m_Elements.m_pMemory[v9];
    v13 = *((unsigned __int16 *)v12 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1001F9D8 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v13 == 0xFFFF )
      v14 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v14 = (int *)&this->m_Elements.m_pMemory[v13];
    if ( *(_WORD *)v14 == v9 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1001F9D8 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v15 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v15 = (int *)&this->m_Elements.m_pMemory[v11];
      v16 = *((_WORD *)v15 + 1);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1001F9D8 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v16 == 0xFFFF )
        v17 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v17 = (int *)&this->m_Elements.m_pMemory[v16];
      if ( *((_WORD *)v17 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1001F9D8 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v19 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v19 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v20 = *((unsigned __int16 *)v19 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1001F9D8 = 0x1FFFF;
        }
        if ( (_WORD)v20 == 0xFFFF )
          v21 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v21 = (int *)&this->m_Elements.m_pMemory[v20];
        if ( *((_WORD *)v21 + 1) == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v9 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
        continue;
      }
      this->m_Elements.m_pMemory[v9].m_Tag = 1;
      v18 = v16;
    }
    else
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1001F9D8 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v22 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v22 = (int *)&this->m_Elements.m_pMemory[v11];
      v23 = *(unsigned __int16 *)v22;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1001F9D8 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v23 == 0xFFFF )
        v24 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v24 = (int *)&this->m_Elements.m_pMemory[v23];
      if ( *((_WORD *)v24 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1001F9D8 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v25 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v25 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v26 = *((unsigned __int16 *)v25 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1001F9D8 = 0x1FFFF;
        }
        if ( (_WORD)v26 == 0xFFFF )
          v27 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v27 = (int *)&this->m_Elements.m_pMemory[v26];
        if ( *(_WORD *)v27 == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v9 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v11);
        continue;
      }
      this->m_Elements.m_pMemory[v9].m_Tag = 1;
      v18 = v23;
    }
    this->m_Elements.m_pMemory[v18].m_Tag = 1;
    v2 = v11;
    this->m_Elements.m_pMemory[v11].m_Tag = 0;
    elem = v11;
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10007BA0
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Parent = parent;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007CA0
// Name: public: CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007D10
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert(class CUtlSymbolTable::CStringPoolIndex const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *insert)
{
  unsigned __int16 v3; // ax
  int v4; // edi
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = 0xFFFF;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    (unsigned __int16 *)&parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(this);
  v4 = v3;
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)-8 )
    m_pMemory[v4].m_Data = *insert;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100082C0
// Name: public: void CUtlMemory<char,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<char,int>::Grow(CUtlMemory<unsigned char,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned __int8 *m_pMemory; // edx

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
        m_nAllocationCount = 32;
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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: m_nAllocationCount);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001000
// Name: __CreateCLocalizeILocalize_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CLocalize *__cdecl _CreateCLocalizeILocalize_interface()
{
  return &s_Localize;
}

//------------------------------------------------------------------------------
// Address: 0x100050E0
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x10005100
// Name: __calloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl _calloc_crt(unsigned int count, unsigned int size)
{
  unsigned __int8 *v2; // edi

  v2 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size * count);
  memset(dst: v2, value: 0, count: size * count);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10005130
// Name: __realloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _realloc_crt(void *ptr, unsigned int size)
{
  return _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x10005150
// Name: __recalloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl _recalloc_crt(void *ptr, unsigned int count, unsigned int size)
{
  unsigned __int8 *v3; // edi

  v3 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size * count);
  memset(dst: v3, value: 0, count: size * count);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10005190
// Name: __msize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _msize(void *pMem)
{
  return _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: pMem);
}

//------------------------------------------------------------------------------
// Address: 0x100051B0
// Name: __heap_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _heap_init()
{
  return _g_pMemAlloc != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100051C0
// Name: __heap_term
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _heap_term()
{
  ;
}
