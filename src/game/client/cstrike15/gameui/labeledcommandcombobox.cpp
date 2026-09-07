// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/labeledcommandcombobox.cpp
// Functions: 19
// ============================================================

#include "game\client\cstrike15\gameui\labeledcommandcombobox.h"

//------------------------------------------------------------------------------
// Address: 0x101D68E0
// Name: public: static char const __near * CLabeledCommandComboBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CLabeledCommandComboBox::GetPanelClassName()
{
  return "CLabeledCommandComboBox";
}

//------------------------------------------------------------------------------
// Address: 0x101D68F0
// Name: public: void CLabeledCommandComboBox::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLabeledCommandComboBox::Reset(CLabeledCommandComboBox *this)
{
  if ( this->m_iStartSelection != -1 )
    this->ActivateItem(this, a2: this->m_iStartSelection);
}

//------------------------------------------------------------------------------
// Address: 0x101D6920
// Name: public: void CUtlMemory<struct CLabeledCommandComboBox::COMMANDITEM,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CLabeledCommandComboBox::COMMANDITEM,int>::Grow(
        CUtlMemory<CLabeledCommandComboBox::COMMANDITEM,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CLabeledCommandComboBox::COMMANDITEM *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 516 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CLabeledCommandComboBox::COMMANDITEM *)_g_pMemAlloc->Realloc_2(
                                                                  this: _g_pMemAlloc,
                                                                  a2: m_pMemory,
                                                                  a3: v7);
    else
      this->m_pMemory = (CLabeledCommandComboBox::COMMANDITEM *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D69C0
// Name: public: virtual void CLabeledCommandComboBox::ActivateItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLabeledCommandComboBox::ActivateItem(CLabeledCommandComboBox *this, int index)
{
  if ( index < this->m_Items.m_Size )
  {
    vgui::ComboBox::ActivateItem(this, itemID: this->m_Items.m_Memory.m_pMemory[index].comboBoxID);
    this->m_iCurrentSelection = index;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6A00
// Name: public: void CLabeledCommandComboBox::SetInitialItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLabeledCommandComboBox::SetInitialItem(CLabeledCommandComboBox *this, int index)
{
  void (__thiscall *ActivateItem)(vgui::ComboBox *, int); // edx

  if ( index < this->m_Items.m_Size )
  {
    ActivateItem = this->ActivateItem;
    this->m_iStartSelection = index;
    ((void (__stdcall *)(int))ActivateItem)(a1: this->m_Items.m_Memory.m_pMemory[index].comboBoxID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6A40
// Name: private: virtual void CLabeledCommandComboBox::OnTextChanged(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLabeledCommandComboBox::OnTextChanged(CLabeledCommandComboBox *this, const char *text)
{
  int v3; // edi
  int v4; // ebx
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v3 = 0;
  if ( this->m_Items.m_Size > 0 )
  {
    v4 = 0;
    while ( _V_stricmp(s1: this->m_Items.m_Memory.m_pMemory[v4].name, s2: text) != 0 )
    {
      ++v3;
      ++v4;
      if ( v3 >= this->m_Items.m_Size )
        goto LABEL_7;
    }
    this->m_iCurrentSelection = v3;
  }
LABEL_7:
  if ( this->m_iStartSelection != this->m_iCurrentSelection )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
    {
      v6 = KeyValues::KeyValues(this: v5, setName: "ControlModified");
      this->PostActionSignal(this, a2: v6);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6AE0
// Name: public: char const __near * CLabeledCommandComboBox::GetActiveItemCommand(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CLabeledCommandComboBox::GetActiveItemCommand(CLabeledCommandComboBox *this)
{
  int m_iCurrentSelection; // eax

  m_iCurrentSelection = this->m_iCurrentSelection;
  if ( m_iCurrentSelection == -1 )
    return nullptr;
  else
    return this->m_Items.m_Memory.m_pMemory[m_iCurrentSelection].command;
}

//------------------------------------------------------------------------------
// Address: 0x101D6B10
// Name: public: void CLabeledCommandComboBox::ApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLabeledCommandComboBox::ApplyChanges(CLabeledCommandComboBox *this)
{
  int m_iCurrentSelection; // eax

  m_iCurrentSelection = this->m_iCurrentSelection;
  if ( m_iCurrentSelection != -1 && this->m_Items.m_Size >= 1 )
  {
    engine->ClientCmd_Unrestricted(this: engine, a2: this->m_Items.m_Memory.m_pMemory[m_iCurrentSelection].command);
    this->m_iStartSelection = this->m_iCurrentSelection;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6B60
// Name: public: virtual void CLabeledCommandComboBox::DeleteAllItems(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLabeledCommandComboBox::DeleteAllItems(CLabeledCommandComboBox *this)
{
  vgui::ComboBox::RemoveAll(this);
  this->m_Items.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D6B80
// Name: public: virtual class vgui::Menu __near * vgui::ComboBox::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::ComboBox::GetMenu(vgui::ComboBox *this)
{
  return this->m_pDropDown;
}

//------------------------------------------------------------------------------
// Address: 0x101D6B90
// Name: public: virtual struct vgui::PanelMessageMap __near * CLabeledCommandComboBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CLabeledCommandComboBox::GetMessageMap(CLabeledCommandComboBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CLabeledCommandComboBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CLabeledCommandComboBox::GetMessageMap'::`2'::s_pMap;
  `CLabeledCommandComboBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CLabeledCommandComboBox");
  `CLabeledCommandComboBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D6BC0
// Name: public: virtual struct PanelAnimationMap __near * CLabeledCommandComboBox::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CLabeledCommandComboBox::GetAnimMap(CLabeledCommandComboBox *this)
{
  return FindOrAddPanelAnimationMap(className: "CLabeledCommandComboBox");
}

//------------------------------------------------------------------------------
// Address: 0x101D6BD0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CLabeledCommandComboBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CLabeledCommandComboBox::GetKBMap(CLabeledCommandComboBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CLabeledCommandComboBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CLabeledCommandComboBox::GetKBMap'::`2'::s_pMap;
  `CLabeledCommandComboBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CLabeledCommandComboBox");
  `CLabeledCommandComboBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D6C00
// Name: public: static void CLabeledCommandComboBox::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CLabeledCommandComboBox::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CLabeledCommandComboBox::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CLabeledCommandComboBox::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CLabeledCommandComboBox::`vcall'{1252,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CLabeledCommandComboBox");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "text";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6CA0
// Name: public: CLabeledCommandComboBox::CLabeledCommandComboBox(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CLabeledCommandComboBox *__thiscall CLabeledCommandComboBox::CLabeledCommandComboBox(
        CLabeledCommandComboBox *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ComboBox::ComboBox(this, parent, panelName, numLines: 6, allowEdit: false);
  this->__vftable = (CLabeledCommandComboBox_vtbl *)&CLabeledCommandComboBox::`vftable';
  if ( `CLabeledCommandComboBox::ChainToMap'::`2'::chained == 0 )
  {
    `CLabeledCommandComboBox::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CLabeledCommandComboBox");
    v4->pfnClassName = CLabeledCommandComboBox::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::ComboBox");
  }
  if ( `CLabeledCommandComboBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CLabeledCommandComboBox::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CLabeledCommandComboBox");
    v5->pfnClassName = CLabeledCommandComboBox::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::ComboBox");
  }
  if ( `CLabeledCommandComboBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CLabeledCommandComboBox::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CLabeledCommandComboBox");
    v6->pfnClassName = CLabeledCommandComboBox::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::ComboBox");
  }
  CLabeledCommandComboBox::PanelMessageFunc_OnTextChanged::InitVar();
  this->m_Items.m_Memory.m_pMemory = nullptr;
  this->m_Items.m_Memory.m_nAllocationCount = 0;
  this->m_Items.m_Memory.m_nGrowSize = 0;
  this->m_Items.m_Size = 0;
  this->m_Items.m_pElements = nullptr;
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  this->m_iCurrentSelection = -1;
  this->m_iStartSelection = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D6DF0
// Name: public: virtual void CLabeledCommandComboBox::AddItem(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLabeledCommandComboBox::AddItem(CLabeledCommandComboBox *this, char *text, char *engineCommand)
{
  int m_nAllocationCount; // eax
  int m_Size; // esi
  CLabeledCommandComboBox::COMMANDITEM *m_pMemory; // ecx
  int v7; // eax
  CLabeledCommandComboBox::COMMANDITEM *v8; // esi
  const wchar_t *v9; // eax

  m_nAllocationCount = this->m_Items.m_Memory.m_nAllocationCount;
  m_Size = this->m_Items.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CLabeledCommandComboBox::COMMANDITEM,int>::Grow(
      this: &this->m_Items.m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Items.m_Size;
  m_pMemory = this->m_Items.m_Memory.m_pMemory;
  v7 = this->m_Items.m_Size - m_Size - 1;
  this->m_Items.m_pElements = m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 516 * v7);
  v8 = &this->m_Items.m_Memory.m_pMemory[m_Size];
  v8->comboBoxID = vgui::ComboBox::AddItem(this, itemText: text, userData: nullptr);
  V_strncpy(pDest: v8->name, pSrc: text, maxLen: 256);
  if ( *text == 35 )
  {
    v9 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: text);
    if ( v9 != nullptr )
      g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v9, a3: (char *)v8, a4: 256);
  }
  V_strncpy(pDest: v8->command, pSrc: engineCommand, maxLen: 256);
}

//------------------------------------------------------------------------------
// Address: 0x103A13E0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ComboBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ComboBox::GetMessageMap(vgui::ComboBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ComboBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetMessageMap'::`2'::s_pMap;
  `vgui::ComboBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
  `vgui::ComboBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A1410
// Name: public: virtual struct PanelAnimationMap __near * vgui::ComboBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ComboBox::GetAnimMap(vgui::ComboBox *this)
{
  return FindOrAddPanelAnimationMap(className: "ComboBox");
}

//------------------------------------------------------------------------------
// Address: 0x103A1420
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ComboBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ComboBox::GetKBMap(vgui::ComboBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ComboBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetKBMap'::`2'::s_pMap;
  `vgui::ComboBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
  `vgui::ComboBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}
