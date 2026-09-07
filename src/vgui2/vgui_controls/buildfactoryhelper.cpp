// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/buildfactoryhelper.cpp
// Functions: 7
// ============================================================

#include "vgui2\vgui_controls\buildfactoryhelper.h"

//------------------------------------------------------------------------------
// Address: 0x102D7060
// Name: public: static class vgui::Panel __near * vgui::CBuildFactoryHelper::InstancePanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__cdecl vgui::CBuildFactoryHelper::InstancePanel(const char *className)
{
  vgui::CBuildFactoryHelper *v1; // esi
  vgui::Panel *(*m_CreateFunc)(void); // esi

  v1 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: className, s2: v1->m_pClassName) != 0 )
  {
    v1 = v1->m_pNext;
    if ( v1 == nullptr )
      return nullptr;
  }
  m_CreateFunc = v1->m_CreateFunc;
  if ( m_CreateFunc != nullptr )
    return m_CreateFunc();
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102D70A0
// Name: public: vgui::CBuildFactoryHelper::CBuildFactoryHelper(char const __near *,class vgui::Panel __near * (*)(void))
// Source: json
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *__thiscall vgui::CBuildFactoryHelper::CBuildFactoryHelper(
        vgui::CBuildFactoryHelper *this,
        const char *className,
        vgui::Panel *(__cdecl *func)())
{
  vgui::CBuildFactoryHelper *v3; // esi

  v3 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers != nullptr )
  {
    while ( _V_stricmp(s1: className, s2: v3->m_pClassName) != 0 )
    {
      v3 = v3->m_pNext;
      if ( v3 == nullptr )
        goto LABEL_6;
    }
    _Error(a1: "CBuildFactoryHelper:  Factory for '%s' already exists!!!!\n", className);
  }
LABEL_6:
  this->m_pNext = vgui::CBuildFactoryHelper::m_sHelpers;
  vgui::CBuildFactoryHelper::m_sHelpers = this;
  this->m_pClassName = className;
  this->m_CreateFunc = func;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102D7100
// Name: public: static void vgui::CBuildFactoryHelper::GetFactoryNames(class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::CBuildFactoryHelper::GetFactoryNames(CUtlVector<char const *,CUtlMemory<char const *,int> > *list)
{
  vgui::CBuildFactoryHelper *i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  const char **m_pMemory; // ecx
  int v6; // eax
  const char **v7; // eax
  CUtlVector<char const *,CUtlMemory<char const *,int> > *lista; // [esp+10h] [ebp+8h]

  list->m_Size = 0;
  for ( i = vgui::CBuildFactoryHelper::m_sHelpers; i != nullptr; i = i->m_pNext )
  {
    m_Size = list->m_Size;
    lista = (CUtlVector<char const *,CUtlMemory<char const *,int> > *)i->m_pClassName;
    m_nAllocationCount = list->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)list, num: m_Size - m_nAllocationCount + 1);
    ++list->m_Size;
    m_pMemory = list->m_Memory.m_pMemory;
    v6 = list->m_Size - m_Size - 1;
    list->m_pElements = list->m_Memory.m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
    v7 = &list->m_Memory.m_pMemory[m_Size];
    if ( v7 != nullptr )
      *v7 = (const char *)lista;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10319570
// Name: _dynamic_initializer_for__help_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__help_command__()
{
  ConCommand::ConCommand(
    this: &help_command,
    pName: "help",
    callback: (void (__cdecl *)())help,
    pHelpString: "Find help about a convar/concommand.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__help_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10324DA0
// Name: _dynamic_atexit_destructor_for__help_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__help_command__()
{
  ConCommand::~ConCommand(this: &help_command);
}

//------------------------------------------------------------------------------
// Address: 0x103195A0
// Name: _dynamic_initializer_for__differences_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__differences_command__()
{
  ConCommand::ConCommand(
    this: &differences_command,
    pName: "differences",
    callback: (void (__cdecl *)())differences,
    pHelpString: "Show all convars which are not at their default values.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__differences_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10324DB0
// Name: _dynamic_atexit_destructor_for__differences_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__differences_command__()
{
  ConCommand::~ConCommand(this: &differences_command);
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x10069DA0
// Name: public: static class vgui::Panel __near * vgui::CBuildFactoryHelper::InstancePanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__cdecl vgui::CBuildFactoryHelper::InstancePanel(const char *className)
{
  vgui::CBuildFactoryHelper *v1; // esi
  vgui::Panel *(*m_CreateFunc)(void); // esi

  v1 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: className, s2: v1->m_pClassName) != 0 )
  {
    v1 = v1->m_pNext;
    if ( v1 == nullptr )
      return nullptr;
  }
  m_CreateFunc = v1->m_CreateFunc;
  if ( m_CreateFunc != nullptr )
    return m_CreateFunc();
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10069DE0
// Name: public: vgui::CBuildFactoryHelper::CBuildFactoryHelper(char const __near *,class vgui::Panel __near * (*)(void))
// Source: json
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *__thiscall vgui::CBuildFactoryHelper::CBuildFactoryHelper(
        vgui::CBuildFactoryHelper *this,
        const char *className,
        vgui::Panel *(__cdecl *func)())
{
  vgui::CBuildFactoryHelper *v3; // esi

  v3 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers != nullptr )
  {
    while ( _V_stricmp(s1: className, s2: v3->m_pClassName) != 0 )
    {
      v3 = v3->m_pNext;
      if ( v3 == nullptr )
        goto LABEL_6;
    }
    _Error(a1: "CBuildFactoryHelper:  Factory for '%s' already exists!!!!\n", className);
  }
LABEL_6:
  this->m_pNext = vgui::CBuildFactoryHelper::m_sHelpers;
  vgui::CBuildFactoryHelper::m_sHelpers = this;
  this->m_pClassName = className;
  this->m_CreateFunc = func;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10069E40
// Name: public: static void vgui::CBuildFactoryHelper::GetFactoryNames(class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::CBuildFactoryHelper::GetFactoryNames(CUtlMemory<vgui::TreeNode *,int> *list)
{
  vgui::CBuildFactoryHelper *i; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  const char **v5; // ecx
  int v6; // eax
  const char **v7; // eax
  CUtlVector<char const *,CUtlMemory<char const *,int> > *lista; // [esp+10h] [ebp+8h]

  list[1].m_pMemory = nullptr;
  for ( i = vgui::CBuildFactoryHelper::m_sHelpers; i != nullptr; i = i->m_pNext )
  {
    m_pMemory = (int)list[1].m_pMemory;
    lista = (CUtlVector<char const *,CUtlMemory<char const *,int> > *)i->m_pClassName;
    m_nAllocationCount = list->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<unsigned long,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
    ++list[1].m_pMemory;
    v5 = (const char **)list->m_pMemory;
    v6 = (int)list[1].m_pMemory - m_pMemory - 1;
    list[1].m_nAllocationCount = (int)list->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v5[m_pMemory + 1], src: (unsigned __int8 *)&v5[m_pMemory], count: 4 * v6);
    v7 = (const char **)&list->m_pMemory[m_pMemory];
    if ( v7 != nullptr )
      *v7 = (const char *)lista;
  }
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x00452500
// Name: public: static class vgui::Panel __near * vgui::CBuildFactoryHelper::InstancePanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__cdecl vgui::CBuildFactoryHelper::InstancePanel(const char *className)
{
  vgui::CBuildFactoryHelper *v1; // esi
  vgui::Panel *(*m_CreateFunc)(void); // esi

  v1 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: className, s2: v1->m_pClassName) != 0 )
  {
    v1 = v1->m_pNext;
    if ( v1 == nullptr )
      return nullptr;
  }
  m_CreateFunc = v1->m_CreateFunc;
  if ( m_CreateFunc != nullptr )
    return m_CreateFunc();
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00452540
// Name: public: vgui::CBuildFactoryHelper::CBuildFactoryHelper(char const __near *,class vgui::Panel __near * (*)(void))
// Source: json
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *__thiscall vgui::CBuildFactoryHelper::CBuildFactoryHelper(
        vgui::CBuildFactoryHelper *this,
        const char *className,
        vgui::Panel *(__cdecl *func)())
{
  vgui::CBuildFactoryHelper *v3; // esi

  v3 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers != nullptr )
  {
    while ( _V_stricmp(s1: className, s2: v3->m_pClassName) != 0 )
    {
      v3 = v3->m_pNext;
      if ( v3 == nullptr )
        goto LABEL_6;
    }
    _Error(a1: "CBuildFactoryHelper:  Factory for '%s' already exists!!!!\n", className);
  }
LABEL_6:
  this->m_pNext = vgui::CBuildFactoryHelper::m_sHelpers;
  vgui::CBuildFactoryHelper::m_sHelpers = this;
  this->m_pClassName = className;
  this->m_CreateFunc = func;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004525A0
// Name: public: static void vgui::CBuildFactoryHelper::GetFactoryNames(class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::CBuildFactoryHelper::GetFactoryNames(CUtlMemory<vgui::TreeNode *,int> *list)
{
  vgui::CBuildFactoryHelper *i; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  const char **v5; // ecx
  int v6; // eax
  const char **v7; // eax
  CUtlVector<char const *,CUtlMemory<char const *,int> > *lista; // [esp+10h] [ebp+8h]

  list[1].m_pMemory = nullptr;
  for ( i = vgui::CBuildFactoryHelper::m_sHelpers; i != nullptr; i = i->m_pNext )
  {
    m_pMemory = (int)list[1].m_pMemory;
    lista = (CUtlVector<char const *,CUtlMemory<char const *,int> > *)i->m_pClassName;
    m_nAllocationCount = list->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<unsigned long,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
    ++list[1].m_pMemory;
    v5 = (const char **)list->m_pMemory;
    v6 = (int)list[1].m_pMemory - m_pMemory - 1;
    list[1].m_nAllocationCount = (int)list->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v5[m_pMemory + 1], src: (unsigned __int8 *)&v5[m_pMemory], count: 4 * v6);
    v7 = (const char **)&list->m_pMemory[m_pMemory];
    if ( v7 != nullptr )
      *v7 = (const char *)lista;
  }
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x1007F590
// Name: public: static class vgui::Panel __near * vgui::CBuildFactoryHelper::InstancePanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__cdecl vgui::CBuildFactoryHelper::InstancePanel(const char *className)
{
  vgui::CBuildFactoryHelper *v1; // esi
  vgui::Panel *(*m_CreateFunc)(void); // esi

  v1 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: className, s2: v1->m_pClassName) != 0 )
  {
    v1 = v1->m_pNext;
    if ( v1 == nullptr )
      return nullptr;
  }
  m_CreateFunc = v1->m_CreateFunc;
  if ( m_CreateFunc != nullptr )
    return m_CreateFunc();
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1007F5D0
// Name: public: vgui::CBuildFactoryHelper::CBuildFactoryHelper(char const __near *,class vgui::Panel __near * (*)(void))
// Source: json
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *__thiscall vgui::CBuildFactoryHelper::CBuildFactoryHelper(
        vgui::CBuildFactoryHelper *this,
        const char *className,
        vgui::Panel *(__cdecl *func)())
{
  vgui::CBuildFactoryHelper *v3; // esi

  v3 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers != nullptr )
  {
    while ( _V_stricmp(s1: className, s2: v3->m_pClassName) != 0 )
    {
      v3 = v3->m_pNext;
      if ( v3 == nullptr )
        goto LABEL_6;
    }
    _Error(a1: "CBuildFactoryHelper:  Factory for '%s' already exists!!!!\n", className);
  }
LABEL_6:
  this->m_pNext = vgui::CBuildFactoryHelper::m_sHelpers;
  vgui::CBuildFactoryHelper::m_sHelpers = this;
  this->m_pClassName = className;
  this->m_CreateFunc = func;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007F630
// Name: public: static void vgui::CBuildFactoryHelper::GetFactoryNames(class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::CBuildFactoryHelper::GetFactoryNames(CUtlMemory<vgui::TreeNode *,int> *list)
{
  vgui::CBuildFactoryHelper *i; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  const char **v5; // ecx
  int v6; // eax
  const char **v7; // eax
  CUtlVector<char const *,CUtlMemory<char const *,int> > *lista; // [esp+10h] [ebp+8h]

  list[1].m_pMemory = nullptr;
  for ( i = vgui::CBuildFactoryHelper::m_sHelpers; i != nullptr; i = i->m_pNext )
  {
    m_pMemory = (int)list[1].m_pMemory;
    lista = (CUtlVector<char const *,CUtlMemory<char const *,int> > *)i->m_pClassName;
    m_nAllocationCount = list->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<CPackedStore *,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
    ++list[1].m_pMemory;
    v5 = (const char **)list->m_pMemory;
    v6 = (int)list[1].m_pMemory - m_pMemory - 1;
    list[1].m_nAllocationCount = (int)list->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v5[m_pMemory + 1], src: (unsigned __int8 *)&v5[m_pMemory], count: 4 * v6);
    v7 = (const char **)&list->m_pMemory[m_pMemory];
    if ( v7 != nullptr )
      *v7 = (const char *)lista;
  }
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x006381C0
// Name: public: static class vgui::Panel __near * vgui::CBuildFactoryHelper::InstancePanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__cdecl vgui::CBuildFactoryHelper::InstancePanel(const char *className)
{
  vgui::CBuildFactoryHelper *v1; // esi
  vgui::Panel *(*m_CreateFunc)(void); // esi

  v1 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: className, s2: v1->m_pClassName) != 0 )
  {
    v1 = v1->m_pNext;
    if ( v1 == nullptr )
      return nullptr;
  }
  m_CreateFunc = v1->m_CreateFunc;
  if ( m_CreateFunc != nullptr )
    return m_CreateFunc();
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00638200
// Name: public: vgui::CBuildFactoryHelper::CBuildFactoryHelper(char const __near *,class vgui::Panel __near * (*)(void))
// Source: json
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *__thiscall vgui::CBuildFactoryHelper::CBuildFactoryHelper(
        vgui::CBuildFactoryHelper *this,
        const char *className,
        vgui::Panel *(__cdecl *func)())
{
  vgui::CBuildFactoryHelper *v3; // esi

  v3 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers != nullptr )
  {
    while ( _V_stricmp(s1: className, s2: v3->m_pClassName) != 0 )
    {
      v3 = v3->m_pNext;
      if ( v3 == nullptr )
        goto LABEL_6;
    }
    _Error(a1: "CBuildFactoryHelper:  Factory for '%s' already exists!!!!\n", className);
  }
LABEL_6:
  this->m_pNext = vgui::CBuildFactoryHelper::m_sHelpers;
  vgui::CBuildFactoryHelper::m_sHelpers = this;
  this->m_pClassName = className;
  this->m_CreateFunc = func;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00638260
// Name: public: static void vgui::CBuildFactoryHelper::GetFactoryNames(class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::CBuildFactoryHelper::GetFactoryNames(CUtlMemory<vgui::TreeNode *,int> *list)
{
  vgui::CBuildFactoryHelper *i; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  const char **v5; // ecx
  int v6; // eax
  const char **v7; // eax
  CUtlVector<char const *,CUtlMemory<char const *,int> > *lista; // [esp+10h] [ebp+8h]

  list[1].m_pMemory = nullptr;
  for ( i = vgui::CBuildFactoryHelper::m_sHelpers; i != nullptr; i = i->m_pNext )
  {
    m_pMemory = (int)list[1].m_pMemory;
    lista = (CUtlVector<char const *,CUtlMemory<char const *,int> > *)i->m_pClassName;
    m_nAllocationCount = list->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
    ++list[1].m_pMemory;
    v5 = (const char **)list->m_pMemory;
    v6 = (int)list[1].m_pMemory - m_pMemory - 1;
    list[1].m_nAllocationCount = (int)list->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v5[m_pMemory + 1], src: (unsigned __int8 *)&v5[m_pMemory], count: 4 * v6);
    v7 = (const char **)&list->m_pMemory[m_pMemory];
    if ( v7 != nullptr )
      *v7 = (const char *)lista;
  }
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102D7110
// Name: public: static class vgui::Panel __near * vgui::CBuildFactoryHelper::InstancePanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__cdecl vgui::CBuildFactoryHelper::InstancePanel(const char *className)
{
  vgui::CBuildFactoryHelper *v1; // esi
  vgui::Panel *(*m_CreateFunc)(void); // esi

  v1 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: className, s2: v1->m_pClassName) != 0 )
  {
    v1 = v1->m_pNext;
    if ( v1 == nullptr )
      return nullptr;
  }
  m_CreateFunc = v1->m_CreateFunc;
  if ( m_CreateFunc != nullptr )
    return m_CreateFunc();
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102D7150
// Name: public: vgui::CBuildFactoryHelper::CBuildFactoryHelper(char const __near *,class vgui::Panel __near * (*)(void))
// Source: json
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *__thiscall vgui::CBuildFactoryHelper::CBuildFactoryHelper(
        vgui::CBuildFactoryHelper *this,
        const char *className,
        vgui::Panel *(__cdecl *func)())
{
  vgui::CBuildFactoryHelper *v3; // esi

  v3 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers != nullptr )
  {
    while ( _V_stricmp(s1: className, s2: v3->m_pClassName) != 0 )
    {
      v3 = v3->m_pNext;
      if ( v3 == nullptr )
        goto LABEL_6;
    }
    _Error(a1: "CBuildFactoryHelper:  Factory for '%s' already exists!!!!\n", className);
  }
LABEL_6:
  this->m_pNext = vgui::CBuildFactoryHelper::m_sHelpers;
  vgui::CBuildFactoryHelper::m_sHelpers = this;
  this->m_pClassName = className;
  this->m_CreateFunc = func;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102D71B0
// Name: public: static void vgui::CBuildFactoryHelper::GetFactoryNames(class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::CBuildFactoryHelper::GetFactoryNames(CUtlVector<char const *,CUtlMemory<char const *,int> > *list)
{
  vgui::CBuildFactoryHelper *i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  const char **m_pMemory; // ecx
  int v6; // eax
  const char **v7; // eax
  CUtlVector<char const *,CUtlMemory<char const *,int> > *lista; // [esp+10h] [ebp+8h]

  list->m_Size = 0;
  for ( i = vgui::CBuildFactoryHelper::m_sHelpers; i != nullptr; i = i->m_pNext )
  {
    m_Size = list->m_Size;
    lista = (CUtlVector<char const *,CUtlMemory<char const *,int> > *)i->m_pClassName;
    m_nAllocationCount = list->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)list, num: m_Size - m_nAllocationCount + 1);
    ++list->m_Size;
    m_pMemory = list->m_Memory.m_pMemory;
    v6 = list->m_Size - m_Size - 1;
    list->m_pElements = list->m_Memory.m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
    v7 = &list->m_Memory.m_pMemory[m_Size];
    if ( v7 != nullptr )
      *v7 = (const char *)lista;
  }
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1031DBF0
// Name: public: static class vgui::Panel __near * vgui::CBuildFactoryHelper::InstancePanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__cdecl vgui::CBuildFactoryHelper::InstancePanel(const char *className)
{
  vgui::CBuildFactoryHelper *v1; // esi
  vgui::Panel *(*m_CreateFunc)(void); // esi

  v1 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: className, s2: v1->m_pClassName) != 0 )
  {
    v1 = v1->m_pNext;
    if ( v1 == nullptr )
      return nullptr;
  }
  m_CreateFunc = v1->m_CreateFunc;
  if ( m_CreateFunc != nullptr )
    return m_CreateFunc();
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1031DC30
// Name: public: vgui::CBuildFactoryHelper::CBuildFactoryHelper(char const __near *,class vgui::Panel __near * (*)(void))
// Source: json
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *__thiscall vgui::CBuildFactoryHelper::CBuildFactoryHelper(
        vgui::CBuildFactoryHelper *this,
        const char *className,
        vgui::Panel *(__cdecl *func)())
{
  vgui::CBuildFactoryHelper *v3; // esi

  v3 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers != nullptr )
  {
    while ( _V_stricmp(s1: className, s2: v3->m_pClassName) != 0 )
    {
      v3 = v3->m_pNext;
      if ( v3 == nullptr )
        goto LABEL_6;
    }
    _Error(this: (ISceneTokenProcessor *)&stru_1066C6B4, a2: className);
  }
LABEL_6:
  this->m_pNext = vgui::CBuildFactoryHelper::m_sHelpers;
  vgui::CBuildFactoryHelper::m_sHelpers = this;
  this->m_pClassName = className;
  this->m_CreateFunc = func;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1031DC90
// Name: public: static void vgui::CBuildFactoryHelper::GetFactoryNames(class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::CBuildFactoryHelper::GetFactoryNames(CUtlVector<char const *,CUtlMemory<char const *,int> > *list)
{
  vgui::CBuildFactoryHelper *i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  const char **m_pMemory; // ecx
  int v6; // eax
  const char **v7; // eax
  CUtlVector<char const *,CUtlMemory<char const *,int> > *lista; // [esp+10h] [ebp+8h]

  list->m_Size = 0;
  for ( i = vgui::CBuildFactoryHelper::m_sHelpers; i != nullptr; i = i->m_pNext )
  {
    m_Size = list->m_Size;
    lista = (CUtlVector<char const *,CUtlMemory<char const *,int> > *)i->m_pClassName;
    m_nAllocationCount = list->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CVisGroup *,int>::Grow(
        this: (CUtlMemory<CCullTreeNode *,int> *)list,
        num: m_Size - m_nAllocationCount + 1);
    ++list->m_Size;
    m_pMemory = list->m_Memory.m_pMemory;
    v6 = list->m_Size - m_Size - 1;
    list->m_pElements = list->m_Memory.m_pMemory;
    if ( v6 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v6);
    v7 = &list->m_Memory.m_pMemory[m_Size];
    if ( v7 != nullptr )
      *v7 = (const char *)lista;
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100A04E0
// Name: public: static class vgui::Panel __near * vgui::CBuildFactoryHelper::InstancePanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__cdecl vgui::CBuildFactoryHelper::InstancePanel(const char *className)
{
  vgui::CBuildFactoryHelper *v1; // esi
  vgui::Panel *(*m_CreateFunc)(void); // esi

  v1 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: className, s2: v1->m_pClassName) != 0 )
  {
    v1 = v1->m_pNext;
    if ( v1 == nullptr )
      return nullptr;
  }
  m_CreateFunc = v1->m_CreateFunc;
  if ( m_CreateFunc != nullptr )
    return m_CreateFunc();
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100A0520
// Name: public: vgui::CBuildFactoryHelper::CBuildFactoryHelper(char const __near *,class vgui::Panel __near * (*)(void))
// Source: json
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *__thiscall vgui::CBuildFactoryHelper::CBuildFactoryHelper(
        vgui::CBuildFactoryHelper *this,
        const char *className,
        vgui::Panel *(__cdecl *func)())
{
  vgui::CBuildFactoryHelper *v3; // esi

  v3 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers != nullptr )
  {
    while ( _V_stricmp(s1: className, s2: v3->m_pClassName) != 0 )
    {
      v3 = v3->m_pNext;
      if ( v3 == nullptr )
        goto LABEL_6;
    }
    _Error(a1: "CBuildFactoryHelper:  Factory for '%s' already exists!!!!\n", className);
  }
LABEL_6:
  this->m_pNext = vgui::CBuildFactoryHelper::m_sHelpers;
  vgui::CBuildFactoryHelper::m_sHelpers = this;
  this->m_pClassName = className;
  this->m_CreateFunc = func;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A0580
// Name: public: static void vgui::CBuildFactoryHelper::GetFactoryNames(class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::CBuildFactoryHelper::GetFactoryNames(CUtlVector<char const *,CUtlMemory<char const *,int> > *list)
{
  vgui::CBuildFactoryHelper *i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  const char **m_pMemory; // ecx
  int v6; // eax
  const char **v7; // eax
  CUtlVector<char const *,CUtlMemory<char const *,int> > *lista; // [esp+10h] [ebp+8h]

  list->m_Size = 0;
  for ( i = vgui::CBuildFactoryHelper::m_sHelpers; i != nullptr; i = i->m_pNext )
  {
    m_Size = list->m_Size;
    lista = (CUtlVector<char const *,CUtlMemory<char const *,int> > *)i->m_pClassName;
    m_nAllocationCount = list->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)list,
        num: m_Size - m_nAllocationCount + 1);
    ++list->m_Size;
    m_pMemory = list->m_Memory.m_pMemory;
    v6 = list->m_Size - m_Size - 1;
    list->m_pElements = list->m_Memory.m_pMemory;
    if ( v6 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v6);
    v7 = &list->m_Memory.m_pMemory[m_Size];
    if ( v7 != nullptr )
      *v7 = (const char *)lista;
  }
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00475BE0
// Name: public: static class vgui::Panel __near * vgui::CBuildFactoryHelper::InstancePanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__cdecl vgui::CBuildFactoryHelper::InstancePanel(const char *className)
{
  vgui::CBuildFactoryHelper *v1; // esi
  vgui::Panel *(*m_CreateFunc)(void); // esi

  v1 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: className, s2: v1->m_pClassName) != 0 )
  {
    v1 = v1->m_pNext;
    if ( v1 == nullptr )
      return nullptr;
  }
  m_CreateFunc = v1->m_CreateFunc;
  if ( m_CreateFunc != nullptr )
    return m_CreateFunc();
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00475C20
// Name: public: vgui::CBuildFactoryHelper::CBuildFactoryHelper(char const __near *,class vgui::Panel __near * (*)(void))
// Source: json
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *__thiscall vgui::CBuildFactoryHelper::CBuildFactoryHelper(
        vgui::CBuildFactoryHelper *this,
        const char *className,
        vgui::Panel *(__cdecl *func)())
{
  vgui::CBuildFactoryHelper *v3; // esi

  v3 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers != nullptr )
  {
    while ( _V_stricmp(s1: className, s2: v3->m_pClassName) != 0 )
    {
      v3 = v3->m_pNext;
      if ( v3 == nullptr )
        goto LABEL_6;
    }
    _Error(a1: "CBuildFactoryHelper:  Factory for '%s' already exists!!!!\n", className);
  }
LABEL_6:
  this->m_pNext = vgui::CBuildFactoryHelper::m_sHelpers;
  vgui::CBuildFactoryHelper::m_sHelpers = this;
  this->m_pClassName = className;
  this->m_CreateFunc = func;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00475C80
// Name: public: static void vgui::CBuildFactoryHelper::GetFactoryNames(class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::CBuildFactoryHelper::GetFactoryNames(CUtlMemory<vgui::TreeNode *,int> *list)
{
  vgui::CBuildFactoryHelper *i; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  const char **v5; // ecx
  int v6; // eax
  const char **v7; // eax
  CUtlVector<char const *,CUtlMemory<char const *,int> > *lista; // [esp+10h] [ebp+8h]

  list[1].m_pMemory = nullptr;
  for ( i = vgui::CBuildFactoryHelper::m_sHelpers; i != nullptr; i = i->m_pNext )
  {
    m_pMemory = (int)list[1].m_pMemory;
    lista = (CUtlVector<char const *,CUtlMemory<char const *,int> > *)i->m_pClassName;
    m_nAllocationCount = list->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<unsigned long,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
    ++list[1].m_pMemory;
    v5 = (const char **)list->m_pMemory;
    v6 = (int)list[1].m_pMemory - m_pMemory - 1;
    list[1].m_nAllocationCount = (int)list->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v5[m_pMemory + 1], src: (unsigned __int8 *)&v5[m_pMemory], count: 4 * v6);
    v7 = (const char **)&list->m_pMemory[m_pMemory];
    if ( v7 != nullptr )
      *v7 = (const char *)lista;
  }
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x00462A50
// Name: private: static bool vgui::CBuildFactoryHelper::HasFactory(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl vgui::CBuildFactoryHelper::HasFactory(const char *className)
{
  vgui::CBuildFactoryHelper *v1; // esi

  v1 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers == nullptr )
    return 0;
  while ( _V_stricmp(s1: className, s2: v1->m_pClassName) != 0 )
  {
    v1 = v1->m_pNext;
    if ( v1 == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00462A90
// Name: public: static class vgui::Panel __near * vgui::CBuildFactoryHelper::InstancePanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__cdecl vgui::CBuildFactoryHelper::InstancePanel(const char *className)
{
  vgui::CBuildFactoryHelper *v1; // esi
  vgui::Panel *(*m_CreateFunc)(void); // esi

  v1 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: className, s2: v1->m_pClassName) != 0 )
  {
    v1 = v1->m_pNext;
    if ( v1 == nullptr )
      return nullptr;
  }
  m_CreateFunc = v1->m_CreateFunc;
  if ( m_CreateFunc != nullptr )
    return m_CreateFunc();
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00462AD0
// Name: public: vgui::CBuildFactoryHelper::CBuildFactoryHelper(char const __near *,class vgui::Panel __near * (*)(void))
// Source: json
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *__thiscall vgui::CBuildFactoryHelper::CBuildFactoryHelper(
        vgui::CBuildFactoryHelper *this,
        const char *className,
        vgui::Panel *(__cdecl *func)())
{
  if ( vgui::CBuildFactoryHelper::HasFactory(className) != 0 )
    _Error(a1: "CBuildFactoryHelper:  Factory for '%s' already exists!!!!\n", className);
  this->m_pNext = vgui::CBuildFactoryHelper::m_sHelpers;
  vgui::CBuildFactoryHelper::m_sHelpers = this;
  this->m_pClassName = className;
  this->m_CreateFunc = func;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00462B20
// Name: public: static void vgui::CBuildFactoryHelper::GetFactoryNames(class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::CBuildFactoryHelper::GetFactoryNames(CUtlMemory<vgui::TreeNode *,int> *list)
{
  vgui::CBuildFactoryHelper *i; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  const char *m_pClassName; // ebp
  const char **v5; // ecx
  int v6; // eax
  bool v7; // zf
  const char **v8; // eax

  list[1].m_pMemory = nullptr;
  for ( i = vgui::CBuildFactoryHelper::m_sHelpers; i != nullptr; i = i->m_pNext )
  {
    m_pMemory = (int)list[1].m_pMemory;
    m_nAllocationCount = list->m_nAllocationCount;
    m_pClassName = i->m_pClassName;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<unsigned long,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
    ++list[1].m_pMemory;
    v5 = (const char **)list->m_pMemory;
    v6 = (int)list[1].m_pMemory - m_pMemory - 1;
    v7 = (vgui::TreeNode **)((char *)list[1].m_pMemory - m_pMemory) == (vgui::TreeNode **)1;
    list[1].m_nAllocationCount = (int)list->m_pMemory;
    if ( v6 >= 0 && !v7 )
      _V_memmove(dest: (unsigned __int8 *)&v5[m_pMemory + 1], src: (unsigned __int8 *)&v5[m_pMemory], count: 4 * v6);
    v8 = (const char **)&list->m_pMemory[m_pMemory];
    if ( v8 != nullptr )
      *v8 = m_pClassName;
  }
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00667DE0
// Name: public: static class vgui::Panel __near * vgui::CBuildFactoryHelper::InstancePanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__cdecl vgui::CBuildFactoryHelper::InstancePanel(const char *className)
{
  vgui::CBuildFactoryHelper *v1; // esi
  vgui::Panel *(*m_CreateFunc)(void); // esi

  v1 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: className, s2: v1->m_pClassName) != 0 )
  {
    v1 = v1->m_pNext;
    if ( v1 == nullptr )
      return nullptr;
  }
  m_CreateFunc = v1->m_CreateFunc;
  if ( m_CreateFunc != nullptr )
    return m_CreateFunc();
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00667E20
// Name: public: vgui::CBuildFactoryHelper::CBuildFactoryHelper(char const __near *,class vgui::Panel __near * (*)(void))
// Source: json
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *__thiscall vgui::CBuildFactoryHelper::CBuildFactoryHelper(
        vgui::CBuildFactoryHelper *this,
        const char *className,
        vgui::Panel *(__cdecl *func)())
{
  vgui::CBuildFactoryHelper *v3; // esi

  v3 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers != nullptr )
  {
    while ( _V_stricmp(s1: className, s2: v3->m_pClassName) != 0 )
    {
      v3 = v3->m_pNext;
      if ( v3 == nullptr )
        goto LABEL_6;
    }
    _Error(a1: "CBuildFactoryHelper:  Factory for '%s' already exists!!!!\n", className);
  }
LABEL_6:
  this->m_pNext = vgui::CBuildFactoryHelper::m_sHelpers;
  vgui::CBuildFactoryHelper::m_sHelpers = this;
  this->m_pClassName = className;
  this->m_CreateFunc = func;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00667E80
// Name: public: static void vgui::CBuildFactoryHelper::GetFactoryNames(class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::CBuildFactoryHelper::GetFactoryNames(CUtlMemory<vgui::TreeNode *,int> *list)
{
  vgui::CBuildFactoryHelper *i; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  const char **v5; // ecx
  int v6; // eax
  const char **v7; // eax
  CUtlVector<char const *,CUtlMemory<char const *,int> > *lista; // [esp+10h] [ebp+8h]

  list[1].m_pMemory = nullptr;
  for ( i = vgui::CBuildFactoryHelper::m_sHelpers; i != nullptr; i = i->m_pNext )
  {
    m_pMemory = (int)list[1].m_pMemory;
    lista = (CUtlVector<char const *,CUtlMemory<char const *,int> > *)i->m_pClassName;
    m_nAllocationCount = list->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
    ++list[1].m_pMemory;
    v5 = (const char **)list->m_pMemory;
    v6 = (int)list[1].m_pMemory - m_pMemory - 1;
    list[1].m_nAllocationCount = (int)list->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v5[m_pMemory + 1], src: (unsigned __int8 *)&v5[m_pMemory], count: 4 * v6);
    v7 = (const char **)&list->m_pMemory[m_pMemory];
    if ( v7 != nullptr )
      *v7 = (const char *)lista;
  }
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x1005C350
// Name: public: static class vgui::Panel __near * vgui::CBuildFactoryHelper::InstancePanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__cdecl vgui::CBuildFactoryHelper::InstancePanel(const char *className)
{
  vgui::CBuildFactoryHelper *v1; // esi
  vgui::Panel *(*m_CreateFunc)(void); // esi

  v1 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: className, s2: v1->m_pClassName) != 0 )
  {
    v1 = v1->m_pNext;
    if ( v1 == nullptr )
      return nullptr;
  }
  m_CreateFunc = v1->m_CreateFunc;
  if ( m_CreateFunc != nullptr )
    return m_CreateFunc();
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1005C390
// Name: public: vgui::CBuildFactoryHelper::CBuildFactoryHelper(char const __near *,class vgui::Panel __near * (*)(void))
// Source: json
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *__thiscall vgui::CBuildFactoryHelper::CBuildFactoryHelper(
        vgui::CBuildFactoryHelper *this,
        const char *className,
        vgui::Panel *(__cdecl *func)())
{
  vgui::CBuildFactoryHelper *v3; // esi

  v3 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers != nullptr )
  {
    while ( _V_stricmp(s1: className, s2: v3->m_pClassName) != 0 )
    {
      v3 = v3->m_pNext;
      if ( v3 == nullptr )
        goto LABEL_6;
    }
    _Error(a1: "CBuildFactoryHelper:  Factory for '%s' already exists!!!!\n", className);
  }
LABEL_6:
  this->m_pNext = vgui::CBuildFactoryHelper::m_sHelpers;
  vgui::CBuildFactoryHelper::m_sHelpers = this;
  this->m_pClassName = className;
  this->m_CreateFunc = func;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005C3F0
// Name: public: static void vgui::CBuildFactoryHelper::GetFactoryNames(class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::CBuildFactoryHelper::GetFactoryNames(CUtlMemory<vgui::TreeNode *,int> *list)
{
  vgui::CBuildFactoryHelper *i; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  const char **v5; // ecx
  int v6; // eax
  const char **v7; // eax
  CUtlVector<char const *,CUtlMemory<char const *,int> > *lista; // [esp+10h] [ebp+8h]

  list[1].m_pMemory = nullptr;
  for ( i = vgui::CBuildFactoryHelper::m_sHelpers; i != nullptr; i = i->m_pNext )
  {
    m_pMemory = (int)list[1].m_pMemory;
    lista = (CUtlVector<char const *,CUtlMemory<char const *,int> > *)i->m_pClassName;
    m_nAllocationCount = list->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<unsigned long,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
    ++list[1].m_pMemory;
    v5 = (const char **)list->m_pMemory;
    v6 = (int)list[1].m_pMemory - m_pMemory - 1;
    list[1].m_nAllocationCount = (int)list->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v5[m_pMemory + 1], src: (unsigned __int8 *)&v5[m_pMemory], count: 4 * v6);
    v7 = (const char **)&list->m_pMemory[m_pMemory];
    if ( v7 != nullptr )
      *v7 = (const char *)lista;
  }
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10091550
// Name: public: static class vgui::Panel __near * vgui::CBuildFactoryHelper::InstancePanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__cdecl vgui::CBuildFactoryHelper::InstancePanel(const char *className)
{
  vgui::CBuildFactoryHelper *v1; // esi
  vgui::Panel *(*m_CreateFunc)(void); // esi

  v1 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: className, s2: v1->m_pClassName) != 0 )
  {
    v1 = v1->m_pNext;
    if ( v1 == nullptr )
      return nullptr;
  }
  m_CreateFunc = v1->m_CreateFunc;
  if ( m_CreateFunc != nullptr )
    return m_CreateFunc();
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10091590
// Name: public: vgui::CBuildFactoryHelper::CBuildFactoryHelper(char const __near *,class vgui::Panel __near * (*)(void))
// Source: json
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *__thiscall vgui::CBuildFactoryHelper::CBuildFactoryHelper(
        vgui::CBuildFactoryHelper *this,
        const char *className,
        vgui::Panel *(__cdecl *func)())
{
  vgui::CBuildFactoryHelper *v3; // esi

  v3 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers != nullptr )
  {
    while ( _V_stricmp(s1: className, s2: v3->m_pClassName) != 0 )
    {
      v3 = v3->m_pNext;
      if ( v3 == nullptr )
        goto LABEL_6;
    }
    _Error(a1: "CBuildFactoryHelper:  Factory for '%s' already exists!!!!\n", className);
  }
LABEL_6:
  this->m_pNext = vgui::CBuildFactoryHelper::m_sHelpers;
  vgui::CBuildFactoryHelper::m_sHelpers = this;
  this->m_pClassName = className;
  this->m_CreateFunc = func;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100915F0
// Name: public: static void vgui::CBuildFactoryHelper::GetFactoryNames(class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::CBuildFactoryHelper::GetFactoryNames(CUtlMemory<vgui::TreeNode *,int> *list)
{
  vgui::CBuildFactoryHelper *i; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  const char **v5; // ecx
  int v6; // eax
  const char **v7; // eax
  CUtlVector<char const *,CUtlMemory<char const *,int> > *lista; // [esp+10h] [ebp+8h]

  list[1].m_pMemory = nullptr;
  for ( i = vgui::CBuildFactoryHelper::m_sHelpers; i != nullptr; i = i->m_pNext )
  {
    m_pMemory = (int)list[1].m_pMemory;
    lista = (CUtlVector<char const *,CUtlMemory<char const *,int> > *)i->m_pClassName;
    m_nAllocationCount = list->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<unsigned long,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
    ++list[1].m_pMemory;
    v5 = (const char **)list->m_pMemory;
    v6 = (int)list[1].m_pMemory - m_pMemory - 1;
    list[1].m_nAllocationCount = (int)list->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v5[m_pMemory + 1], src: (unsigned __int8 *)&v5[m_pMemory], count: 4 * v6);
    v7 = (const char **)&list->m_pMemory[m_pMemory];
    if ( v7 != nullptr )
      *v7 = (const char *)lista;
  }
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x004600D0
// Name: public: static class vgui::Panel __near * vgui::CBuildFactoryHelper::InstancePanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__cdecl vgui::CBuildFactoryHelper::InstancePanel(const char *className)
{
  vgui::CBuildFactoryHelper *v1; // esi
  vgui::Panel *(*m_CreateFunc)(void); // esi

  v1 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: className, s2: v1->m_pClassName) != 0 )
  {
    v1 = v1->m_pNext;
    if ( v1 == nullptr )
      return nullptr;
  }
  m_CreateFunc = v1->m_CreateFunc;
  if ( m_CreateFunc != nullptr )
    return m_CreateFunc();
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00460110
// Name: public: vgui::CBuildFactoryHelper::CBuildFactoryHelper(char const __near *,class vgui::Panel __near * (*)(void))
// Source: json
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *__thiscall vgui::CBuildFactoryHelper::CBuildFactoryHelper(
        vgui::CBuildFactoryHelper *this,
        const char *className,
        vgui::Panel *(__cdecl *func)())
{
  vgui::CBuildFactoryHelper *v3; // esi

  v3 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers != nullptr )
  {
    while ( _V_stricmp(s1: className, s2: v3->m_pClassName) != 0 )
    {
      v3 = v3->m_pNext;
      if ( v3 == nullptr )
        goto LABEL_6;
    }
    _Error(a1: "CBuildFactoryHelper:  Factory for '%s' already exists!!!!\n", className);
  }
LABEL_6:
  this->m_pNext = vgui::CBuildFactoryHelper::m_sHelpers;
  vgui::CBuildFactoryHelper::m_sHelpers = this;
  this->m_pClassName = className;
  this->m_CreateFunc = func;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00460170
// Name: public: static void vgui::CBuildFactoryHelper::GetFactoryNames(class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::CBuildFactoryHelper::GetFactoryNames(CUtlVector<char const *,CUtlMemory<char const *,int> > *list)
{
  vgui::CBuildFactoryHelper *i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  const char **m_pMemory; // ecx
  int v6; // eax
  const char **v7; // eax
  CUtlVector<char const *,CUtlMemory<char const *,int> > *lista; // [esp+10h] [ebp+8h]

  list->m_Size = 0;
  for ( i = vgui::CBuildFactoryHelper::m_sHelpers; i != nullptr; i = i->m_pNext )
  {
    m_Size = list->m_Size;
    lista = (CUtlVector<char const *,CUtlMemory<char const *,int> > *)i->m_pClassName;
    m_nAllocationCount = list->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<unsigned long,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)list,
        num: m_Size - m_nAllocationCount + 1);
    ++list->m_Size;
    m_pMemory = list->m_Memory.m_pMemory;
    v6 = list->m_Size - m_Size - 1;
    list->m_pElements = list->m_Memory.m_pMemory;
    if ( v6 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v6);
    v7 = &list->m_Memory.m_pMemory[m_Size];
    if ( v7 != nullptr )
      *v7 = (const char *)lista;
  }
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x004AA720
// Name: private: static bool vgui::CBuildFactoryHelper::HasFactory(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl vgui::CBuildFactoryHelper::HasFactory(const char *className)
{
  vgui::CBuildFactoryHelper *v1; // esi

  v1 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers == nullptr )
    return 0;
  while ( _V_stricmp(s1: className, s2: v1->m_pClassName) != 0 )
  {
    v1 = v1->m_pNext;
    if ( v1 == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004AA760
// Name: public: static class vgui::Panel __near * vgui::CBuildFactoryHelper::InstancePanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__cdecl vgui::CBuildFactoryHelper::InstancePanel(const char *className)
{
  vgui::CBuildFactoryHelper *v1; // esi
  vgui::Panel *(*m_CreateFunc)(void); // esi

  v1 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: className, s2: v1->m_pClassName) != 0 )
  {
    v1 = v1->m_pNext;
    if ( v1 == nullptr )
      return nullptr;
  }
  m_CreateFunc = v1->m_CreateFunc;
  if ( m_CreateFunc != nullptr )
    return m_CreateFunc();
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004AA7A0
// Name: public: vgui::CBuildFactoryHelper::CBuildFactoryHelper(char const __near *,class vgui::Panel __near * (*)(void))
// Source: json
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *__thiscall vgui::CBuildFactoryHelper::CBuildFactoryHelper(
        vgui::CBuildFactoryHelper *this,
        const char *className,
        vgui::Panel *(__cdecl *func)())
{
  if ( vgui::CBuildFactoryHelper::HasFactory(className) != 0 )
    _Error(a1: "CBuildFactoryHelper:  Factory for '%s' already exists!!!!\n", className);
  this->m_pNext = vgui::CBuildFactoryHelper::m_sHelpers;
  vgui::CBuildFactoryHelper::m_sHelpers = this;
  this->m_pClassName = className;
  this->m_CreateFunc = func;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004AA7F0
// Name: public: static void vgui::CBuildFactoryHelper::GetFactoryNames(class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::CBuildFactoryHelper::GetFactoryNames(CUtlVector<char const *,CUtlMemory<char const *,int> > *list)
{
  vgui::CBuildFactoryHelper *i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  const char *m_pClassName; // ebp
  const char **m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  const char **v8; // eax

  list->m_Size = 0;
  for ( i = vgui::CBuildFactoryHelper::m_sHelpers; i != nullptr; i = i->m_pNext )
  {
    m_Size = list->m_Size;
    m_nAllocationCount = list->m_Memory.m_nAllocationCount;
    m_pClassName = i->m_pClassName;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)list,
        num: m_Size - m_nAllocationCount + 1);
    ++list->m_Size;
    m_pMemory = list->m_Memory.m_pMemory;
    v6 = list->m_Size - m_Size - 1;
    v7 = list->m_Size - m_Size == 1;
    list->m_pElements = list->m_Memory.m_pMemory;
    if ( v6 >= 0 && !v7 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v6);
    v8 = &list->m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      *v8 = m_pClassName;
  }
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x004610A0
// Name: public: static class vgui::Panel __near * vgui::CBuildFactoryHelper::InstancePanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__cdecl vgui::CBuildFactoryHelper::InstancePanel(const char *className)
{
  vgui::CBuildFactoryHelper *v1; // esi
  vgui::Panel *(*m_CreateFunc)(void); // esi

  v1 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: className, s2: v1->m_pClassName) != 0 )
  {
    v1 = v1->m_pNext;
    if ( v1 == nullptr )
      return nullptr;
  }
  m_CreateFunc = v1->m_CreateFunc;
  if ( m_CreateFunc != nullptr )
    return m_CreateFunc();
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004610E0
// Name: public: vgui::CBuildFactoryHelper::CBuildFactoryHelper(char const __near *,class vgui::Panel __near * (*)(void))
// Source: json
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *__thiscall vgui::CBuildFactoryHelper::CBuildFactoryHelper(
        vgui::CBuildFactoryHelper *this,
        const char *className,
        vgui::Panel *(__cdecl *func)())
{
  vgui::CBuildFactoryHelper *v3; // esi

  v3 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers != nullptr )
  {
    while ( _V_stricmp(s1: className, s2: v3->m_pClassName) != 0 )
    {
      v3 = v3->m_pNext;
      if ( v3 == nullptr )
        goto LABEL_6;
    }
    _Error(a1: "CBuildFactoryHelper:  Factory for '%s' already exists!!!!\n", className);
  }
LABEL_6:
  this->m_pNext = vgui::CBuildFactoryHelper::m_sHelpers;
  vgui::CBuildFactoryHelper::m_sHelpers = this;
  this->m_pClassName = className;
  this->m_CreateFunc = func;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00461140
// Name: public: static void vgui::CBuildFactoryHelper::GetFactoryNames(class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::CBuildFactoryHelper::GetFactoryNames(CUtlMemory<vgui::TreeNode *,int> *list)
{
  vgui::CBuildFactoryHelper *i; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  const char **v5; // ecx
  int v6; // eax
  const char **v7; // eax
  CUtlVector<char const *,CUtlMemory<char const *,int> > *lista; // [esp+10h] [ebp+8h]

  list[1].m_pMemory = nullptr;
  for ( i = vgui::CBuildFactoryHelper::m_sHelpers; i != nullptr; i = i->m_pNext )
  {
    m_pMemory = (int)list[1].m_pMemory;
    lista = (CUtlVector<char const *,CUtlMemory<char const *,int> > *)i->m_pClassName;
    m_nAllocationCount = list->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<unsigned long,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
    ++list[1].m_pMemory;
    v5 = (const char **)list->m_pMemory;
    v6 = (int)list[1].m_pMemory - m_pMemory - 1;
    list[1].m_nAllocationCount = (int)list->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &v5[m_pMemory + 1], src: &v5[m_pMemory], count: 4 * v6);
    v7 = (const char **)&list->m_pMemory[m_pMemory];
    if ( v7 != nullptr )
      *v7 = (const char *)lista;
  }
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x00461B20
// Name: public: static class vgui::Panel __near * vgui::CBuildFactoryHelper::InstancePanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__cdecl vgui::CBuildFactoryHelper::InstancePanel(const char *className)
{
  vgui::CBuildFactoryHelper *v1; // esi
  vgui::Panel *(*m_CreateFunc)(void); // esi

  v1 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: className, s2: v1->m_pClassName) != 0 )
  {
    v1 = v1->m_pNext;
    if ( v1 == nullptr )
      return nullptr;
  }
  m_CreateFunc = v1->m_CreateFunc;
  if ( m_CreateFunc != nullptr )
    return m_CreateFunc();
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00461B60
// Name: public: vgui::CBuildFactoryHelper::CBuildFactoryHelper(char const __near *,class vgui::Panel __near * (*)(void))
// Source: json
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *__thiscall vgui::CBuildFactoryHelper::CBuildFactoryHelper(
        vgui::CBuildFactoryHelper *this,
        const char *className,
        vgui::Panel *(__cdecl *func)())
{
  vgui::CBuildFactoryHelper *v3; // esi

  v3 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers != nullptr )
  {
    while ( _V_stricmp(s1: className, s2: v3->m_pClassName) != 0 )
    {
      v3 = v3->m_pNext;
      if ( v3 == nullptr )
        goto LABEL_6;
    }
    _Error(a1: "CBuildFactoryHelper:  Factory for '%s' already exists!!!!\n", className);
  }
LABEL_6:
  this->m_pNext = vgui::CBuildFactoryHelper::m_sHelpers;
  vgui::CBuildFactoryHelper::m_sHelpers = this;
  this->m_pClassName = className;
  this->m_CreateFunc = func;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00461BC0
// Name: public: static void vgui::CBuildFactoryHelper::GetFactoryNames(class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::CBuildFactoryHelper::GetFactoryNames(CUtlMemory<vgui::TreeNode *,int> *list)
{
  vgui::CBuildFactoryHelper *i; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  const char **v5; // ecx
  int v6; // eax
  const char **v7; // eax
  CUtlVector<char const *,CUtlMemory<char const *,int> > *lista; // [esp+10h] [ebp+8h]

  list[1].m_pMemory = nullptr;
  for ( i = vgui::CBuildFactoryHelper::m_sHelpers; i != nullptr; i = i->m_pNext )
  {
    m_pMemory = (int)list[1].m_pMemory;
    lista = (CUtlVector<char const *,CUtlMemory<char const *,int> > *)i->m_pClassName;
    m_nAllocationCount = list->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<unsigned long,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
    ++list[1].m_pMemory;
    v5 = (const char **)list->m_pMemory;
    v6 = (int)list[1].m_pMemory - m_pMemory - 1;
    list[1].m_nAllocationCount = (int)list->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v5[m_pMemory + 1], src: (unsigned __int8 *)&v5[m_pMemory], count: 4 * v6);
    v7 = (const char **)&list->m_pMemory[m_pMemory];
    if ( v7 != nullptr )
      *v7 = (const char *)lista;
  }
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1039F250
// Name: public: static class vgui::Panel __near * vgui::CBuildFactoryHelper::InstancePanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__cdecl vgui::CBuildFactoryHelper::InstancePanel(const char *className)
{
  vgui::CBuildFactoryHelper *v1; // esi
  vgui::Panel *(*m_CreateFunc)(void); // esi

  v1 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: className, s2: v1->m_pClassName) != 0 )
  {
    v1 = v1->m_pNext;
    if ( v1 == nullptr )
      return nullptr;
  }
  m_CreateFunc = v1->m_CreateFunc;
  if ( m_CreateFunc != nullptr )
    return m_CreateFunc();
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1039F290
// Name: public: vgui::CBuildFactoryHelper::CBuildFactoryHelper(char const __near *,class vgui::Panel __near * (*)(void))
// Source: json
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *__thiscall vgui::CBuildFactoryHelper::CBuildFactoryHelper(
        vgui::CBuildFactoryHelper *this,
        const char *className,
        vgui::Panel *(__cdecl *func)())
{
  vgui::CBuildFactoryHelper *v3; // esi

  v3 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers != nullptr )
  {
    while ( _V_stricmp(s1: className, s2: v3->m_pClassName) != 0 )
    {
      v3 = v3->m_pNext;
      if ( v3 == nullptr )
        goto LABEL_6;
    }
    _Error(this: (ISceneTokenProcessor *)&stru_10543694, a2: className);
  }
LABEL_6:
  this->m_pNext = vgui::CBuildFactoryHelper::m_sHelpers;
  vgui::CBuildFactoryHelper::m_sHelpers = this;
  this->m_pClassName = className;
  this->m_CreateFunc = func;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1039F2F0
// Name: public: static void vgui::CBuildFactoryHelper::GetFactoryNames(class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::CBuildFactoryHelper::GetFactoryNames(CUtlVector<char const *,CUtlMemory<char const *,int> > *list)
{
  vgui::CBuildFactoryHelper *i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  const char **m_pMemory; // ecx
  int v6; // eax
  const char **v7; // eax
  CUtlVector<char const *,CUtlMemory<char const *,int> > *lista; // [esp+10h] [ebp+8h]

  list->m_Size = 0;
  for ( i = vgui::CBuildFactoryHelper::m_sHelpers; i != nullptr; i = i->m_pNext )
  {
    m_Size = list->m_Size;
    lista = (CUtlVector<char const *,CUtlMemory<char const *,int> > *)i->m_pClassName;
    m_nAllocationCount = list->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)list,
        num: m_Size - m_nAllocationCount + 1);
    ++list->m_Size;
    m_pMemory = list->m_Memory.m_pMemory;
    v6 = list->m_Size - m_Size - 1;
    list->m_pElements = list->m_Memory.m_pMemory;
    if ( v6 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v6);
    v7 = &list->m_Memory.m_pMemory[m_Size];
    if ( v7 != nullptr )
      *v7 = (const char *)lista;
  }
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x103C28E0
// Name: public: static class vgui::Panel __near * vgui::CBuildFactoryHelper::InstancePanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__cdecl vgui::CBuildFactoryHelper::InstancePanel(const char *className)
{
  vgui::CBuildFactoryHelper *v1; // esi
  vgui::Panel *(*m_CreateFunc)(void); // esi

  v1 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: className, s2: v1->m_pClassName) != 0 )
  {
    v1 = v1->m_pNext;
    if ( v1 == nullptr )
      return nullptr;
  }
  m_CreateFunc = v1->m_CreateFunc;
  if ( m_CreateFunc != nullptr )
    return m_CreateFunc();
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103C2920
// Name: public: vgui::CBuildFactoryHelper::CBuildFactoryHelper(char const __near *,class vgui::Panel __near * (*)(void))
// Source: json
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *__thiscall vgui::CBuildFactoryHelper::CBuildFactoryHelper(
        vgui::CBuildFactoryHelper *this,
        const char *className,
        vgui::Panel *(__cdecl *func)())
{
  vgui::CBuildFactoryHelper *v3; // esi

  v3 = vgui::CBuildFactoryHelper::m_sHelpers;
  if ( vgui::CBuildFactoryHelper::m_sHelpers != nullptr )
  {
    while ( _V_stricmp(s1: className, s2: v3->m_pClassName) != 0 )
    {
      v3 = v3->m_pNext;
      if ( v3 == nullptr )
        goto LABEL_6;
    }
    _Error(this: (ISceneTokenProcessor *)&stru_1051B0F8, a2: className);
  }
LABEL_6:
  this->m_pNext = vgui::CBuildFactoryHelper::m_sHelpers;
  vgui::CBuildFactoryHelper::m_sHelpers = this;
  this->m_pClassName = className;
  this->m_CreateFunc = func;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103C2980
// Name: public: static void vgui::CBuildFactoryHelper::GetFactoryNames(class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::CBuildFactoryHelper::GetFactoryNames(CUtlVector<char const *,CUtlMemory<char const *,int> > *list)
{
  vgui::CBuildFactoryHelper *i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  const char **m_pMemory; // ecx
  int v6; // eax
  const char **v7; // eax
  CUtlVector<char const *,CUtlMemory<char const *,int> > *lista; // [esp+10h] [ebp+8h]

  list->m_Size = 0;
  for ( i = vgui::CBuildFactoryHelper::m_sHelpers; i != nullptr; i = i->m_pNext )
  {
    m_Size = list->m_Size;
    lista = (CUtlVector<char const *,CUtlMemory<char const *,int> > *)i->m_pClassName;
    m_nAllocationCount = list->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)list,
        num: m_Size - m_nAllocationCount + 1);
    ++list->m_Size;
    m_pMemory = list->m_Memory.m_pMemory;
    v6 = list->m_Size - m_Size - 1;
    list->m_pElements = list->m_Memory.m_pMemory;
    if ( v6 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v6);
    v7 = &list->m_Memory.m_pMemory[m_Size];
    if ( v7 != nullptr )
      *v7 = (const char *)lista;
  }
}

} // namespace server
