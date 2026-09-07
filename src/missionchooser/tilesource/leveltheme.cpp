// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/tilesource/leveltheme.cpp
// Functions: 25
// ============================================================

#include "missionchooser\tilesource\leveltheme.h"

//------------------------------------------------------------------------------
// Address: 0x1000E830
// Name: public: int CUtlSortVector<class CKV_Editor_Base_Panel __near *,class FitChildrenLessFunc>::Find(class CKV_Editor_Base_Panel __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc>::Find(
        CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc> *this,
        CKV_Editor_Base_Panel *const *src)
{
  CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc> *v2; // edi
  int v3; // eax
  int v4; // ecx
  int v5; // esi
  CKV_Editor_Base_Panel *v6; // edi
  CKV_Editor_Base_Panel *const *v7; // eax
  vgui::Panel *v8; // edx
  CKV_Editor_Base_Panel *v9; // ecx
  CKV_Editor_Base_Panel *v10; // eax
  vgui::Panel **v11; // edi
  int v13; // ebx
  int ZPos; // [esp+Ch] [ebp-10h]
  int start; // [esp+14h] [ebp-8h]
  int end; // [esp+18h] [ebp-4h]

  v2 = this;
  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
         215,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/utlsortvector.h",
                            a2: 215,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
      a2: 215);
  }
  v3 = 0;
  v4 = v2->m_Size - 1;
  start = 0;
  end = v4;
  if ( v4 >= 0 )
  {
    while ( 1 )
    {
      v5 = (v4 + v3) >> 1;
      v6 = v2->m_Memory.m_pMemory[v5];
      v7 = src;
      v8 = *src;
      if ( v6 != nullptr && v8 != nullptr )
      {
        if ( *(float *)&v8[1].m_hKeyBindingsContext > v6->m_flSortOrder )
          goto LABEL_14;
      }
      else
      {
        ZPos = vgui::Panel::GetZPos(this: *(vgui::Panel **)src);
        if ( vgui::Panel::GetZPos(this: v6) < ZPos )
        {
          v4 = end;
LABEL_14:
          start = v5 + 1;
          goto LABEL_22;
        }
        v7 = src;
      }
      v9 = *v7;
      v10 = this->m_Memory.m_pMemory[v5];
      v11 = &this->m_Memory.m_pMemory[v5];
      if ( v9 != nullptr && v10 != nullptr )
      {
        if ( v10->m_flSortOrder <= v9->m_flSortOrder )
          return v5;
      }
      else
      {
        v13 = vgui::Panel::GetZPos(this: v9);
        if ( v13 >= vgui::Panel::GetZPos(this: *v11) )
          return v5;
      }
      end = v5 - 1;
      v4 = v5 - 1;
LABEL_22:
      v3 = start;
      if ( start > v4 )
        return -1;
      v2 = this;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1000E980
// Name: public: int CUtlSortVector<class CKV_Editor_Base_Panel __near *,class FitChildrenLessFunc>::FindLessOrEqual(class CKV_Editor_Base_Panel __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc>::FindLessOrEqual(
        CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc> *this,
        CKV_Editor_Base_Panel *const *src)
{
  CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc> *v2; // edi
  int v3; // eax
  int v4; // ecx
  int v5; // esi
  CKV_Editor_Base_Panel *v6; // edi
  CKV_Editor_Base_Panel *const *v7; // eax
  vgui::Panel *v8; // edx
  CKV_Editor_Base_Panel *v9; // ecx
  CKV_Editor_Base_Panel *v10; // eax
  vgui::Panel **v11; // edi
  int v13; // ebx
  int ZPos; // [esp+Ch] [ebp-10h]
  int start; // [esp+14h] [ebp-8h]
  int end; // [esp+18h] [ebp-4h]

  v2 = this;
  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
         277,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/utlsortvector.h",
                            a2: 277,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
      a2: 277);
  }
  v3 = 0;
  v4 = v2->m_Size - 1;
  start = 0;
  end = v4;
  if ( v4 >= 0 )
  {
    while ( 1 )
    {
      v5 = (v4 + v3) >> 1;
      v6 = v2->m_Memory.m_pMemory[v5];
      v7 = src;
      v8 = *src;
      if ( v6 != nullptr && v8 != nullptr )
      {
        if ( *(float *)&v8[1].m_hKeyBindingsContext > v6->m_flSortOrder )
          goto LABEL_14;
      }
      else
      {
        ZPos = vgui::Panel::GetZPos(this: *(vgui::Panel **)src);
        if ( vgui::Panel::GetZPos(this: v6) < ZPos )
        {
          v4 = end;
LABEL_14:
          start = v5 + 1;
          goto LABEL_22;
        }
        v7 = src;
      }
      v9 = *v7;
      v10 = this->m_Memory.m_pMemory[v5];
      v11 = &this->m_Memory.m_pMemory[v5];
      if ( v9 != nullptr && v10 != nullptr )
      {
        if ( v10->m_flSortOrder <= v9->m_flSortOrder )
          return v5;
      }
      else
      {
        v13 = vgui::Panel::GetZPos(this: v9);
        if ( v13 >= vgui::Panel::GetZPos(this: *v11) )
          return v5;
      }
      end = v5 - 1;
      v4 = v5 - 1;
LABEL_22:
      v3 = start;
      if ( start > v4 )
        return v4;
      v2 = this;
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1000EAD0
// Name: public: void CUtlSortVector<class CKV_Editor_Base_Panel __near *,class FitChildrenLessFunc>::Remove(class CKV_Editor_Base_Panel __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc>::Remove(
        CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc> *this,
        CKV_Editor_Base_Panel *const *search)
{
  int v3; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
         329,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/utlsortvector.h",
                            a2: 329,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
      a2: 329);
  }
  v3 = CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc>::Find(this, src: search);
  if ( v3 != -1 )
  {
    if ( this->m_Size - v3 - 1 > 0 )
      _V_memmove(
        dest: &this->m_Memory.m_pMemory[v3],
        src: &this->m_Memory.m_pMemory[v3 + 1],
        count: 4 * (this->m_Size - v3 - 1));
    --this->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EC30
// Name: public: int CUtlSortVector<class CKV_Editor_Base_Panel __near *,class FitChildrenLessFunc>::Insert(class CKV_Editor_Base_Panel __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc>::Insert(
        CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc> *this,
        CKV_Editor_Base_Panel *const *src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // edi
  int m_Size; // eax
  CKV_Editor_Base_Panel **m_pMemory; // ecx
  int v8; // eax
  CKV_Editor_Base_Panel **v9; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
         150,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/utlsortvector.h",
                            a2: 150,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
      a2: 150);
  }
  LessOrEqual = CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc>::FindLessOrEqual(this, src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual + 1;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - v5 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 4 * v8);
  v9 = &this->m_Memory.m_pMemory[v5];
  if ( v9 != nullptr )
    *v9 = *src;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10024430
// Name: public: static void CLevelTheme::SetCurrentTheme(class CLevelTheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CLevelTheme::SetCurrentTheme(CLevelTheme *pTheme)
{
  if ( CLevelTheme::s_pCurrentTheme != nullptr )
    CLevelTheme::s_pPreviousTheme = CLevelTheme::s_pCurrentTheme;
  CLevelTheme::s_pCurrentTheme = pTheme;
  ConVar::SetValue(this: (ConVar *)&asw_tilegen_theme.IConVar, value: pTheme->m_szName);
}

//------------------------------------------------------------------------------
// Address: 0x10024460
// Name: public: bool CLevelTheme::SaveTheme(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLevelTheme::SaveTheme(CLevelTheme *this, const char *pszThemeName)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  IBaseFileSystem *v5; // eax
  char pDest[8]; // [esp+8h] [ebp-184h] BYREF
  char szFullFileName[260]; // [esp+20h] [ebp-16Ch] BYREF

  V_snprintf(pDest, maxLen: 260, pFormat: "tilegen/themes/%s.theme", pszThemeName);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: pszThemeName);
  else
    v4 = nullptr;
  KeyValues::SetString(this: v4, keyName: "ThemeName", value: this->m_szName);
  KeyValues::SetString(this: v4, keyName: "ThemeDescription", value: this->m_szDescription);
  KeyValues::SetInt(this: v4, keyName: "VMFTweak", value: this->m_bRequiresVMFTweak);
  KeyValues::SetInt(this: v4, keyName: "SkipErrorCheck", value: this->m_bSkipErrorCheck);
  V_snprintf(
    pDest: &szFullFileName[236],
    maxLen: 128,
    pFormat: "%f %f %f",
    this->m_vecAmbientLight.x,
    this->m_vecAmbientLight.y,
    this->m_vecAmbientLight.z);
  KeyValues::SetString(this: v4, keyName: "AmbientLight", value: &szFullFileName[236]);
  if ( g_pFullFileSystem != nullptr )
    v5 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v5 = nullptr;
  if ( KeyValues::SaveToFile(this: v4, filesystem: v5, resourceName: pDest, pathID: "GAME") )
    return 1;
  _Msg(a1: "Error: Failed to save theme %s\n", pDest);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100245A0
// Name: public: static bool CLevelTheme::SplitThemeAndRoom(char const __near *,char __near *,int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CLevelTheme::SplitThemeAndRoom(
        const char *pszFullName,
        char *szThemeOut,
        int nThemeOutSize,
        char *szRoomOut,
        int nRoomOutSize)
{
  int v5; // eax
  const char *v6; // edi
  int v7; // eax
  const char *v8; // eax

  v5 = _V_strlen(str: pszFullName);
  v6 = V_strnchr(pStr: pszFullName, c: 47, n: v5);
  v7 = _V_strlen(str: pszFullName);
  v8 = V_strnchr(pStr: pszFullName, c: 92, n: v7);
  if ( v8 != nullptr )
  {
    if ( v6 == nullptr || v6 >= v8 )
      v6 = v8;
  }
  else if ( v6 == nullptr )
  {
    return 0;
  }
  V_strncpy(pDest: szThemeOut, pSrc: pszFullName, maxLen: nThemeOutSize);
  if ( v6 - pszFullName < nThemeOutSize )
    szThemeOut[v6 - pszFullName] = 0;
  V_strncpy(pDest: szRoomOut, pSrc: v6 + 1, maxLen: nRoomOutSize);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10024620
// Name: public: class CRoomTemplate __near * CLevelTheme::FindRoom(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CRoomTemplate *__thiscall CLevelTheme::FindRoom(CLevelTheme *this, const char *szRoomTemplate)
{
  int v3; // esi
  int v4; // esi
  CRoomTemplate *v5; // edi

  V_snprintf(pDest: buffer, maxLen: 256, pFormat: "%s", szRoomTemplate);
  v3 = _V_strlen(str: buffer);
  if ( v3 >= 4 && _V_stricmp(s1: &buffer[-4], s2: ".vmf") == 0 )
    byte_1019B90C[v3] = 0;
  V_FixSlashes(pname: buffer, separator: 92);
  v4 = 0;
  if ( this->m_RoomTemplates.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v5 = this->m_RoomTemplates.m_Memory.m_pMemory[v4];
    if ( v5 != nullptr && _V_stricmp(s1: v5->m_FullName, s2: buffer) == 0 )
      break;
    if ( ++v4 >= this->m_RoomTemplates.m_Size )
      return nullptr;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100246D0
// Name: public: int CUtlSortVector<class CRoomTemplate __near *,class CRoomTemplateLessFunc>::FindLessOrEqual(class CRoomTemplate __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CRoomTemplate *,CRoomTemplateLessFunc>::FindLessOrEqual(
        CUtlSortVector<CRoomTemplate *,CRoomTemplateLessFunc> *this,
        CRoomTemplate *const *src)
{
  int v3; // eax
  int v4; // edi
  int v5; // esi
  int start; // [esp+Ch] [ebp-4h]

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
         277,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/UtlSortVector.h",
                            a2: 277,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
      a2: 277);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  start = 0;
  if ( v4 < 0 )
    return v4;
  while ( 1 )
  {
    v5 = (v4 + v3) >> 1;
    if ( this->m_Memory.m_pMemory[v5] == (CRoomTemplate *)-568
      || *src != (CRoomTemplate *const)-568
      && _V_stricmp(s1: this->m_Memory.m_pMemory[v5]->m_FullName, s2: (*src)->m_FullName) >= 0 )
    {
      break;
    }
    start = v5 + 1;
LABEL_16:
    v3 = start;
    if ( start > v4 )
      return v4;
  }
  if ( *src != (CRoomTemplate *const)-568
    && (this->m_Memory.m_pMemory[v5] == (CRoomTemplate *)-568
     || _V_stricmp(s1: (*src)->m_FullName, s2: this->m_Memory.m_pMemory[v5]->m_FullName) < 0) )
  {
    v4 = v5 - 1;
    goto LABEL_16;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10024840
// Name: public: int CUtlSortVector<class CRoomTemplate __near *,class CRoomTemplateLessFunc>::Insert(class CRoomTemplate __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CRoomTemplate *,CRoomTemplateLessFunc>::Insert(
        CUtlSortVector<CRoomTemplate *,CRoomTemplateLessFunc> *this,
        CRoomTemplate *const *src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // edi
  int m_Size; // eax
  CRoomTemplate **m_pMemory; // ecx
  int v8; // eax
  CRoomTemplate **v9; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
         150,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/UtlSortVector.h",
                            a2: 150,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
      a2: 150);
  }
  LessOrEqual = CUtlSortVector<CRoomTemplate *,CRoomTemplateLessFunc>::FindLessOrEqual(this, src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual + 1;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - v5 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 4 * v8);
  v9 = &this->m_Memory.m_pMemory[v5];
  if ( v9 != nullptr )
    *v9 = *src;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10024910
// Name: public: CLevelTheme::~CLevelTheme(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLevelTheme::~CLevelTheme(CLevelTheme *this)
{
  CUtlSortVector<CRoomTemplate *,CRoomTemplateLessFunc> *p_m_RoomTemplates; // esi

  p_m_RoomTemplates = &this->m_RoomTemplates;
  CUtlVector<CRoomTemplate *,CUtlMemory<CRoomTemplate *,int>>::PurgeAndDeleteElements(this: &this->m_RoomTemplates);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)p_m_RoomTemplates);
}

//------------------------------------------------------------------------------
// Address: 0x10024930
// Name: private: void CLevelTheme::LoadRoomTemplatesInFolder(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLevelTheme::LoadRoomTemplatesInFolder(CLevelTheme *this, const char *szPath)
{
  const char *v2; // edi
  CLevelTheme *v3; // ebx
  const char *i; // esi
  const char *FileExtension; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  IBaseFileSystem *v8; // eax
  CRoomTemplate *v9; // eax
  CRoomTemplate *v10; // esi
  int v11; // eax
  char mapwild[260]; // [esp+Ch] [ebp-218h] BYREF
  char szFullFileName[260]; // [esp+110h] [ebp-114h] BYREF
  CLevelTheme *v14; // [esp+214h] [ebp-10h]
  int v15; // [esp+218h] [ebp-Ch]
  CRoomTemplate *pRoomTemplate; // [esp+21Ch] [ebp-8h] BYREF
  int hRoomfind; // [esp+220h] [ebp-4h] BYREF

  v2 = szPath;
  v3 = this;
  v14 = this;
  V_snprintf(pDest: mapwild, maxLen: 260, pFormat: "%s/*", szPath);
  hRoomfind = -1;
  for ( i = Sys_FindFirst(searchhandle: &hRoomfind, path: mapwild, basename: nullptr, namelength: 0);
        i != nullptr;
        i = Sys_FindNext(searchhandle: &hRoomfind, basename: nullptr, namelength: 0) )
  {
    if ( g_pFullFileSystem->FindIsDirectory(this: g_pFullFileSystem, a2: hRoomfind) )
    {
      if ( _V_strcmp(s1: i, s2: ".") != 0 && _V_strcmp(s1: i, s2: "..") != 0 )
      {
        V_snprintf(pDest: szFullFileName, maxLen: 260, pFormat: "%s/%s", v2, i);
        CLevelTheme::LoadRoomTemplatesInFolder(this: v3, szPath: szFullFileName);
      }
    }
    else
    {
      FileExtension = V_GetFileExtension(path: i);
      if ( FileExtension != nullptr && _V_stricmp(s1: FileExtension, s2: "roomtemplate") == 0 )
      {
        V_snprintf(pDest: &szFullFileName[4], maxLen: 256, pFormat: "%s/%s", v2, i);
        v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v6 != nullptr )
          v7 = KeyValues::KeyValues(this: v6, setName: i);
        else
          v7 = nullptr;
        if ( g_pFullFileSystem != nullptr )
          v8 = &g_pFullFileSystem->IBaseFileSystem;
        else
          v8 = nullptr;
        if ( KeyValues::LoadFromFile(
               this: v7,
               filesystem: v8,
               resourceName: &szFullFileName[4],
               pathID: "GAME",
               pfnEvaluateSymbolProc: nullptr) )
        {
          v9 = (CRoomTemplate *)operator new(nSize: 0x588u);
          if ( v9 != nullptr )
            v10 = CRoomTemplate::CRoomTemplate(this: v9, pLevelTheme: v3);
          else
            v10 = nullptr;
          pRoomTemplate = v10;
          v15 = _V_strlen(str: "tilegen/roomtemplates/");
          v11 = _V_strlen(str: v3->m_szName);
          CRoomTemplate::LoadFromKeyValues(this: v10, pRoomName: &szFullFileName[v11 + 5 + v15], pKeyValues: v7);
          v3 = v14;
          CUtlSortVector<CRoomTemplate *,CRoomTemplateLessFunc>::Insert(
            this: &v14->m_RoomTemplates,
            src: &pRoomTemplate);
        }
        else
        {
          _Msg(a1: "Error: failed to load room template %s\n", &szFullFileName[4]);
        }
        KeyValues::deleteThis(this: v7);
        v2 = szPath;
      }
    }
  }
  Sys_FindClose(searchhandle: &hRoomfind);
}

//------------------------------------------------------------------------------
// Address: 0x10024B30
// Name: public: CLevelTheme::CLevelTheme(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CLevelTheme *__thiscall CLevelTheme::CLevelTheme(
        CLevelTheme *this,
        const char *szName,
        const char *szDescription,
        bool bRequiresVMFTweak)
{
  char *m_szDescription; // edi

  this->m_RoomTemplates.m_Memory.m_pMemory = nullptr;
  this->m_RoomTemplates.m_Memory.m_nAllocationCount = 0;
  this->m_RoomTemplates.m_Memory.m_nGrowSize = 0;
  this->m_RoomTemplates.m_Size = 0;
  this->m_RoomTemplates.m_pElements = nullptr;
  this->m_RoomTemplates.m_pLessContext = nullptr;
  this->m_RoomTemplates.m_bNeedsSort = false;
  this->m_bRequiresVMFTweak = bRequiresVMFTweak;
  this->m_szName[0] = 0;
  this->m_szDescription[0] = 0;
  m_szDescription = this->m_szDescription;
  this->m_vecAmbientLight = vec3_origin;
  if ( szName != nullptr )
    _V_strcpy(dest: this->m_szName, src: szName);
  if ( szDescription != nullptr )
    _V_strcpy(dest: m_szDescription, src: szDescription);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10024BD0
// Name: public: void CLevelTheme::LoadRoomTemplates(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLevelTheme::LoadRoomTemplates(CLevelTheme *this)
{
  char szPath[260]; // [esp+4h] [ebp-104h] BYREF

  CUtlVector<CRoomTemplate *,CUtlMemory<CRoomTemplate *,int>>::PurgeAndDeleteElements(this: &this->m_RoomTemplates);
  V_snprintf(pDest: szPath, maxLen: 260, pFormat: "tilegen/roomtemplates/%s", this->m_szName);
  CLevelTheme::LoadRoomTemplatesInFolder(this, szPath);
}

//------------------------------------------------------------------------------
// Address: 0x10024D20
// Name: public: static void CLevelTheme::LoadLevelThemes(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CLevelTheme::LoadLevelThemes()
{
  const char *i; // esi
  KeyValues *v1; // eax
  KeyValues *v2; // ebx
  IBaseFileSystem *v3; // eax
  CLevelTheme *v4; // esi
  const char *v5; // eax
  CLevelTheme *v6; // esi
  const char *v7; // eax
  int m_Size; // eax
  int v9; // edi
  CLevelTheme **m_pMemory; // ecx
  int v11; // eax
  CLevelTheme **v12; // edi
  char *m_pszString; // eax
  const char *String; // [esp-14h] [ebp-31Ch]
  bool v15; // [esp-10h] [ebp-318h]
  char pDest[260]; // [esp+0h] [ebp-308h] BYREF
  char mapwild[260]; // [esp+104h] [ebp-204h] BYREF
  char szFullFileName[256]; // [esp+208h] [ebp-100h] BYREF

  if ( !CLevelTheme::s_bLoadedThemes )
  {
    CLevelTheme::s_pCurrentTheme = nullptr;
    CUtlVector<CLevelTheme *,CUtlMemory<CLevelTheme *,int>>::PurgeAndDeleteElements(this: &CLevelTheme::s_LevelThemes);
    CLevelTheme::s_bLoadedThemes = true;
    V_strncpy(pDest: mapwild, pSrc: "tilegen/themes/*.theme", maxLen: 260);
    for ( i = Sys_FindFirst(searchhandle: &g_hthemefind, path: mapwild, basename: nullptr, namelength: 0);
          i != nullptr;
          i = Sys_FindNext(searchhandle: &g_hthemefind, basename: nullptr, namelength: 0) )
    {
      V_snprintf(pDest: szFullFileName, maxLen: 256, pFormat: "tilegen/themes/%s", i);
      v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v1 != nullptr )
        v2 = KeyValues::KeyValues(this: v1, setName: i);
      else
        v2 = nullptr;
      if ( g_pFullFileSystem != nullptr )
        v3 = &g_pFullFileSystem->IBaseFileSystem;
      else
        v3 = nullptr;
      if ( KeyValues::LoadFromFile(
             this: v2,
             filesystem: v3,
             resourceName: szFullFileName,
             pathID: "GAME",
             pfnEvaluateSymbolProc: nullptr) )
      {
        v4 = (CLevelTheme *)operator new(nSize: 0x26Cu);
        if ( v4 != nullptr )
        {
          v15 = KeyValues::GetInt(this: v2, keyName: "VMFTweak", defaultValue: 0) > 0;
          String = KeyValues::GetString(this: v2, keyName: "ThemeDescription", defaultValue: szDescription);
          v5 = KeyValues::GetString(this: v2, keyName: "ThemeName", defaultValue: szDescription);
          v6 = CLevelTheme::CLevelTheme(this: v4, szName: v5, szDescription: String, bRequiresVMFTweak: v15);
        }
        else
        {
          v6 = nullptr;
        }
        v6->m_bSkipErrorCheck = KeyValues::GetInt(this: v2, keyName: "SkipErrorCheck", defaultValue: 0) > 0;
        v7 = KeyValues::GetString(this: v2, keyName: "AmbientLight", defaultValue: szDescription);
        sscanf(
          string: v7,
          format: "%f %f %f",
          &v6->m_vecAmbientLight,
          &v6->m_vecAmbientLight.y,
          &v6->m_vecAmbientLight.z);
        if ( vec3_origin.x == v6->m_vecAmbientLight.x
          && vec3_origin.y == v6->m_vecAmbientLight.y
          && vec3_origin.z == v6->m_vecAmbientLight.z )
        {
          v6->m_vecAmbientLight.x = 1.0;
          v6->m_vecAmbientLight.y = 1.0;
          v6->m_vecAmbientLight.z = 1.0;
        }
        CUtlVector<CRoomTemplate *,CUtlMemory<CRoomTemplate *,int>>::PurgeAndDeleteElements(this: &v6->m_RoomTemplates);
        V_snprintf(pDest, maxLen: 260, pFormat: "tilegen/roomtemplates/%s", v6->m_szName);
        CLevelTheme::LoadRoomTemplatesInFolder(this: v6, szPath: pDest);
        m_Size = CLevelTheme::s_LevelThemes.m_Size;
        v9 = CLevelTheme::s_LevelThemes.m_Size;
        if ( CLevelTheme::s_LevelThemes.m_Size + 1 > CLevelTheme::s_LevelThemes.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&CLevelTheme::s_LevelThemes,
            num: CLevelTheme::s_LevelThemes.m_Size - CLevelTheme::s_LevelThemes.m_Memory.m_nAllocationCount + 1);
          m_Size = CLevelTheme::s_LevelThemes.m_Size;
        }
        m_pMemory = CLevelTheme::s_LevelThemes.m_Memory.m_pMemory;
        CLevelTheme::s_LevelThemes.m_Size = m_Size + 1;
        v11 = m_Size - v9;
        CLevelTheme::s_LevelThemes.m_pElements = CLevelTheme::s_LevelThemes.m_Memory.m_pMemory;
        if ( v11 > 0 )
        {
          _V_memmove(
            dest: &CLevelTheme::s_LevelThemes.m_Memory.m_pMemory[v9 + 1],
            src: &CLevelTheme::s_LevelThemes.m_Memory.m_pMemory[v9],
            count: 4 * v11);
          m_pMemory = CLevelTheme::s_LevelThemes.m_Memory.m_pMemory;
        }
        v12 = &m_pMemory[v9];
        if ( v12 != nullptr )
          *v12 = v6;
        if ( (asw_tilegen_theme.m_nFlags & 0x1000) != 0 )
        {
          m_pszString = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          m_pszString = asw_tilegen_theme.m_pParent->m_Value.m_pszString;
          if ( m_pszString == nullptr )
            m_pszString = (char *)szDescription;
        }
        if ( _V_stricmp(s1: v6->m_szName, s2: m_pszString) == 0 )
        {
          if ( CLevelTheme::s_pCurrentTheme != nullptr )
            CLevelTheme::s_pPreviousTheme = CLevelTheme::s_pCurrentTheme;
          CLevelTheme::s_pCurrentTheme = v6;
          ConVar::SetValue(this: (ConVar *)&asw_tilegen_theme.IConVar, value: v6->m_szName);
        }
      }
      else
      {
        _Msg(a1: "Error: failed to load theme %s\n", szFullFileName);
      }
      KeyValues::deleteThis(this: v2);
    }
    if ( CLevelTheme::s_pCurrentTheme == nullptr && CLevelTheme::s_LevelThemes.m_Size > 0 )
    {
      CLevelTheme::s_pCurrentTheme = *CLevelTheme::s_LevelThemes.m_Memory.m_pMemory;
      ConVar::SetValue(this: (ConVar *)&asw_tilegen_theme.IConVar, value: CLevelTheme::s_pCurrentTheme->m_szName);
    }
    Sys_FindClose(searchhandle: &g_hthemefind);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025050
// Name: public: static class CLevelTheme __near * CLevelTheme::FindTheme(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CLevelTheme *__cdecl CLevelTheme::FindTheme(const char *szThemeName)
{
  int m_Size; // ebx
  int v2; // edi
  CLevelTheme *v3; // esi

  if ( !CLevelTheme::s_bLoadedThemes )
    CLevelTheme::LoadLevelThemes();
  m_Size = CLevelTheme::s_LevelThemes.m_Size;
  v2 = 0;
  if ( CLevelTheme::s_LevelThemes.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v3 = CLevelTheme::s_LevelThemes.m_Memory.m_pMemory[v2];
    if ( v3 != nullptr && _V_stricmp(s1: v3->m_szName, s2: szThemeName) == 0 )
      break;
    if ( ++v2 >= m_Size )
      return nullptr;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100FD060
// Name: _dynamic_initializer_for__CLevelTheme::s_LevelThemes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CLevelTheme::s_LevelThemes__()
{
  return atexit(func: dynamic_atexit_destructor_for__CLevelTheme::s_LevelThemes__);
}

//------------------------------------------------------------------------------
// Address: 0x100FDFF0
// Name: _dynamic_atexit_destructor_for__CLevelTheme::s_LevelThemes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CLevelTheme::s_LevelThemes__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CLevelTheme::s_LevelThemes);
}

//------------------------------------------------------------------------------
// Address: 0x100FD070
// Name: _dynamic_initializer_for__asw_tilegen_theme__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__asw_tilegen_theme__()
{
  ConVar::ConVar(
    this: &asw_tilegen_theme,
    pName: "asw_tilegen_theme",
    pDefaultValue: "Rydberg",
    flags: 128,
    pHelpString: "Default theme selected in TileGen");
  return atexit(func: dynamic_atexit_destructor_for__asw_tilegen_theme__);
}

//------------------------------------------------------------------------------
// Address: 0x100FD0A0
// Name: _dynamic_initializer_for__g_LoadedTGAs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_LoadedTGAs__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_LoadedTGAs__);
}

//------------------------------------------------------------------------------
// Address: 0x100FD0B0
// Name: _dynamic_initializer_for__asw_encounter_display__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__asw_encounter_display__()
{
  ConVar::ConVar(this: &asw_encounter_display, pName: "asw_encounter_display", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__asw_encounter_display__);
}

//------------------------------------------------------------------------------
// Address: 0x100FD0E0
// Name: _dynamic_initializer_for__g_pRoomTemplatePanels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_pRoomTemplatePanels__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_pRoomTemplatePanels__);
}

//------------------------------------------------------------------------------
// Address: 0x100FE000
// Name: _dynamic_atexit_destructor_for__g_LoadedTGAs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_LoadedTGAs__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_LoadedTGAs);
}

//------------------------------------------------------------------------------
// Address: 0x100FE010
// Name: _dynamic_atexit_destructor_for__asw_encounter_display__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__asw_encounter_display__()
{
  ConVar::~ConVar(this: &asw_encounter_display);
}

//------------------------------------------------------------------------------
// Address: 0x100FE020
// Name: _dynamic_atexit_destructor_for__g_pRoomTemplatePanels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_pRoomTemplatePanels__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_pRoomTemplatePanels);
}
