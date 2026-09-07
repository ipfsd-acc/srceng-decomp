// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vguimatsurface/cursor.cpp
// Functions: 12
// ============================================================

#include "vguimatsurface\cursor.h"

//------------------------------------------------------------------------------
// Address: 0x100024A0
// Name: bool StringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl StringLessThan(const char **lhs, const char **rhs)
{
  int v3; // kr00_4

  if ( *lhs == nullptr )
    return false;
  if ( *rhs == nullptr )
    return true;
  v3 = strcmp(*lhs, *rhs);
  return v3 != 0 && -(v3 < 0) - ((v3 < 0) - 1) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002500
// Name: bool CaselessStringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CaselessStringLessThan(const char **lhs, const char **rhs)
{
  if ( *lhs == nullptr )
    return false;
  if ( *rhs != nullptr )
    return _V_stricmp(s1: *lhs, s2: *rhs) < 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10002530
// Name: void InitCursors(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitCursors()
{
  s_pDefaultCursor[1] = nullptr;
  s_pDefaultCursor[2] = g_pInputSystem->GetStandardCursor(this: g_pInputSystem, a2: 1);
  s_pDefaultCursor[3] = g_pInputSystem->GetStandardCursor(this: g_pInputSystem, a2: 2);
  s_pDefaultCursor[4] = g_pInputSystem->GetStandardCursor(this: g_pInputSystem, a2: 3);
  s_pDefaultCursor[6] = g_pInputSystem->GetStandardCursor(this: g_pInputSystem, a2: 4);
  s_pDefaultCursor[5] = g_pInputSystem->GetStandardCursor(this: g_pInputSystem, a2: 5);
  s_pDefaultCursor[7] = g_pInputSystem->GetStandardCursor(this: g_pInputSystem, a2: 6);
  s_pDefaultCursor[8] = g_pInputSystem->GetStandardCursor(this: g_pInputSystem, a2: 7);
  s_pDefaultCursor[9] = g_pInputSystem->GetStandardCursor(this: g_pInputSystem, a2: 8);
  s_pDefaultCursor[10] = g_pInputSystem->GetStandardCursor(this: g_pInputSystem, a2: 9);
  s_pDefaultCursor[11] = g_pInputSystem->GetStandardCursor(this: g_pInputSystem, a2: 10);
  s_pDefaultCursor[12] = g_pInputSystem->GetStandardCursor(this: g_pInputSystem, a2: 11);
  s_pDefaultCursor[13] = g_pInputSystem->GetStandardCursor(this: g_pInputSystem, a2: 12);
  s_pDefaultCursor[14] = g_pInputSystem->GetStandardCursor(this: g_pInputSystem, a2: 13);
  s_bCursorLocked = false;
  s_bCursorVisible = true;
  s_hCurrentCursor = s_pDefaultCursor[2];
}

//------------------------------------------------------------------------------
// Address: 0x10002680
// Name: void ActivateCurrentCursor(struct InputContextHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ActivateCurrentCursor(InputContextHandle_t__ *hContext)
{
  if ( s_bCursorVisible )
    g_pInputStackSystem->SetCursorIcon(this: g_pInputStackSystem, a2: hContext, a3: s_hCurrentCursor);
  else
    g_pInputStackSystem->SetCursorIcon(this: g_pInputStackSystem, a2: hContext, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100026C0
// Name: void LockCursor(struct InputContextHandle_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LockCursor(InputContextHandle_t__ *hContext, bool bEnable)
{
  s_bCursorLocked = bEnable;
  if ( s_bCursorVisible )
    g_pInputStackSystem->SetCursorIcon(this: g_pInputStackSystem, a2: hContext, a3: s_hCurrentCursor);
  else
    g_pInputStackSystem->SetCursorIcon(this: g_pInputStackSystem, a2: hContext, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10002700
// Name: bool IsCursorLocked(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsCursorLocked()
{
  return s_bCursorLocked;
}

//------------------------------------------------------------------------------
// Address: 0x10002710
// Name: void CursorSetPos(struct InputContextHandle_t__ __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CursorSetPos(InputContextHandle_t__ *hContext, int x, int y)
{
  g_pInputStackSystem->SetCursorPosition(this: g_pInputStackSystem, a2: hContext, a3: x, a4: y);
}

//------------------------------------------------------------------------------
// Address: 0x10002730
// Name: void CursorGetPos(struct InputContextHandle_t__ __near *,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CursorGetPos(InputContextHandle_t__ *hContext, int *x, int *y)
{
  g_pInputSystem->GetCursorPosition(this: g_pInputSystem, a2: x, a3: y);
}

//------------------------------------------------------------------------------
// Address: 0x10003720
// Name: public: bool CUserCursorManager::LookupCursor(unsigned long,struct InputCursorHandle_t__ __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUserCursorManager::LookupCursor(
        CUserCursorManager *this,
        signed int cursor,
        InputCursorHandle_t__ **handle)
{
  signed int v5; // esi

  if ( cursor < 0 )
  {
    v5 = cursor & 0x7FFFFFFF;
    if ( (cursor & 0x7FFFFFFF) >= this->m_UserCursors.m_Elements.m_Tree.m_Elements.m_nAllocationCount
      || v5 > this->m_UserCursors.m_Elements.m_Tree.m_LastAlloc.index
      || CUtlRBTree<CUtlMap<char const *,InputCursorHandle_t__ *,int>::Node_t,int,CUtlMap<char const *,InputCursorHandle_t__ *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,InputCursorHandle_t__ *,int>::Node_t,int>,int>>::LeftChild(
           this: &this->m_UserCursors.m_Elements.m_Tree,
           i: v5) == v5 )
    {
      *handle = nullptr;
      return 0;
    }
    else
    {
      *handle = this->m_UserCursors.m_Elements.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
      return 1;
    }
  }
  else
  {
    *handle = nullptr;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003790
// Name: void CursorSelect(struct InputContextHandle_t__ __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CursorSelect(InputContextHandle_t__ *hContext, unsigned int hCursor)
{
  void (__thiscall *v2)(IInputStackSystem *, InputContextHandle_t__ *, InputCursorHandle_t__ *); // eax
  InputCursorHandle_t__ *v3; // eax
  void (__thiscall *SetCursorIcon)(IInputStackSystem *, InputContextHandle_t__ *, InputCursorHandle_t__ *); // edx
  InputCursorHandle_t__ *custom; // [esp+0h] [ebp-4h] BYREF

  if ( !s_bCursorLocked )
  {
    s_bCursorVisible = true;
    switch ( hCursor )
    {
      case 0u:
      case 1u:
      case 0xFu:
        goto $LN5;
      case 2u:
      case 3u:
      case 4u:
      case 5u:
      case 6u:
      case 7u:
      case 8u:
      case 9u:
      case 0xAu:
      case 0xBu:
      case 0xCu:
      case 0xDu:
      case 0xEu:
        v3 = s_pDefaultCursor[hCursor];
        goto LABEL_7;
      default:
        custom = nullptr;
        if ( CUserCursorManager::LookupCursor(this: &g_UserCursors, cursor: hCursor, handle: &custom) != 0
          && (v3 = custom, custom != nullptr) )
        {
LABEL_7:
          SetCursorIcon = g_pInputStackSystem->SetCursorIcon;
          s_hCurrentCursor = v3;
          SetCursorIcon(this: g_pInputStackSystem, a2: hContext, a3: v3);
        }
        else
        {
$LN5:
          v2 = g_pInputStackSystem->SetCursorIcon;
          s_bCursorVisible = false;
          v2(this: g_pInputStackSystem, a2: hContext, a3: nullptr);
        }
        g_pInputSystem->SetMouseCursorVisible(this: g_pInputSystem, a2: s_bCursorVisible);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003930
// Name: public: unsigned long CUserCursorManager::CreateCursorFromFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUserCursorManager::CreateCursorFromFile(
        CUserCursorManager *this,
        InputCursorHandle_t__ *curOrAniFile,
        const char *pPathID)
{
  int v4; // eax
  char fn[512]; // [esp+4h] [ebp-208h] BYREF
  CUtlMap<char const *,InputCursorHandle_t__ *,int>::Node_t search; // [esp+204h] [ebp-8h] BYREF

  V_strncpy(pDest: fn, pSrc: (const char *)curOrAniFile, maxLen: 512);
  _V_strlower(start: fn);
  V_FixSlashes(pname: fn, separator: 92);
  search.key = fn;
  v4 = CUtlRBTree<CUtlMap<char const *,InputCursorHandle_t__ *,int>::Node_t,int,CUtlMap<char const *,InputCursorHandle_t__ *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,InputCursorHandle_t__ *,int>::Node_t,int>,int>>::Find(
         this: &this->m_UserCursors.m_Elements.m_Tree,
         &search);
  if ( v4 == -1 )
  {
    curOrAniFile = g_pInputSystem->LoadCursorFromFile(this: g_pInputSystem, a2: fn, a3: pPathID);
    v4 = CUtlDict<InputCursorHandle_t__ *,int>::Insert(this: &this->m_UserCursors, pName: fn, element: &curOrAniFile);
  }
  return v4 | 0x80000000;
}

//------------------------------------------------------------------------------
// Address: 0x100039D0
// Name: unsigned long Cursor_CreateCursorFromFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl Cursor_CreateCursorFromFile(char *curOrAniFile, const char *pPathID)
{
  return CUserCursorManager::CreateCursorFromFile(this: &g_UserCursors, (InputCursorHandle_t__ *)curOrAniFile, pPathID);
}
