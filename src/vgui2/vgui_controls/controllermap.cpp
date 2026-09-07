// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/controllermap.cpp
// Functions: 11
// ============================================================

#include "vgui2\vgui_controls\controllermap.h"

//------------------------------------------------------------------------------
// Address: 0x10080900
// Name: public: virtual struct DmxElementUnpackStructure_t const __near * vgui::Panel::GetUnpackStructure(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
const DmxElementUnpackStructure_t *__thiscall vgui::Panel::GetUnpackStructure(vgui::Panel *this)
{
  return vgui::Panel::s_pUnpackParams;
}

//------------------------------------------------------------------------------
// Address: 0x1023AA40
// Name: bool lessFunc(int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl lessFunc(const CKeyBindingsMgr::KBContext_t *lhs, const CKeyBindingsMgr::KBContext_t *rhs)
{
  return lhs->m_Handle < rhs->m_Handle;
}

//------------------------------------------------------------------------------
// Address: 0x10374BD0
// Name: public: virtual class Color vgui::Panel::GetFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Panel::GetFgColor(vgui::Panel *this, Color *result)
{
  *result = this->_fgColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103DAAA0
// Name: public: static char const __near * CControllerMap::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CControllerMap::GetPanelClassName()
{
  return "CControllerMap";
}

//------------------------------------------------------------------------------
// Address: 0x103DB8A0
// Name: public: virtual void CControllerMap::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CControllerMap::OnKeyCodeTyped(CControllerMap *this, ButtonCode_t code)
{
  unsigned __int16 v3; // ax
  CControllerMap_vtbl *v4; // edx
  int v5; // ebx
  vgui::Panel *v6; // eax
  UtlRBTreeNode_t<CUtlMap<int,CControllerMap::button_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  vgui::Panel *v8; // edi
  vgui::Panel_vtbl *v9; // esi
  char *v10; // eax
  vgui::Panel *v11; // eax
  CUtlMap<int,CControllerMap::button_t,unsigned short>::Node_t search; // [esp+Ch] [ebp-Ch] BYREF

  *(_DWORD *)&search.elem.cmd.m_Id = -1;
  search.elem.icon.m_Id = -1;
  search.key = code;
  v3 = CUtlRBTree<CUtlMap<int,CControllerMap::button_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,CControllerMap::button_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CControllerMap::button_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_buttonMap.m_Tree,
         &search);
  v4 = this->__vftable;
  v5 = v3;
  if ( v3 == 0xFFFF )
  {
    v4->SetKeyBoardInputEnabled(this, a2: false);
    v11 = this->GetParent(this);
    v11->OnKeyCodeTyped(this: v11, a2: code);
    this->SetKeyBoardInputEnabled(this, a2: true);
  }
  else
  {
    v6 = v4->GetParent(this);
    m_pMemory = this->m_buttonMap.m_Tree.m_Elements.m_pMemory;
    v8 = v6;
    v9 = v6->__vftable;
    v10 = CUtlSymbol::String(this: &m_pMemory[v5].m_Data.elem.cmd);
    v9->OnCommand(this: v8, a2: v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DBA40
// Name: public: CControllerMap::CControllerMap(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CControllerMap *__thiscall CControllerMap::CControllerMap(CControllerMap *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  UtlRBTreeNode_t<CUtlMap<int,CControllerMap::button_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  CControllerMap *result; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (CControllerMap_vtbl *)&CControllerMap::`vftable';
  if ( `CControllerMap::ChainToMap'::`2'::chained == 0 )
  {
    `CControllerMap::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CControllerMap");
    v4->pfnClassName = CControllerMap::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CControllerMap::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CControllerMap::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CControllerMap");
    v5->pfnClassName = CControllerMap::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CControllerMap::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CControllerMap::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CControllerMap");
    v6->pfnClassName = CControllerMap::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_buttonMap.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_buttonMap.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_buttonMap.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_buttonMap.m_Tree.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_buttonMap.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_buttonMap.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_buttonMap.m_Tree.m_FirstFree = -1;
  this->m_buttonMap.m_Tree.m_pElements = m_pMemory;
  result = this;
  if ( this->m_buttonMap.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_buttonMap.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const int *, const int *))lessFunc;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103DBB50
// Name: public: virtual struct vgui::PanelMessageMap __near * CControllerMap::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CControllerMap::GetMessageMap(CControllerMap *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CControllerMap::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CControllerMap::GetMessageMap'::`2'::s_pMap;
  `CControllerMap::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CControllerMap");
  `CControllerMap::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103DBB80
// Name: public: virtual struct PanelAnimationMap __near * CControllerMap::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CControllerMap::GetAnimMap(CControllerMap *this)
{
  return FindOrAddPanelAnimationMap(className: "CControllerMap");
}

//------------------------------------------------------------------------------
// Address: 0x103DBB90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CControllerMap::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CControllerMap::GetKBMap(CControllerMap *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CControllerMap::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CControllerMap::GetKBMap'::`2'::s_pMap;
  `CControllerMap::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CControllerMap");
  `CControllerMap::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103DBBF0
// Name: Create_CControllerMap
// Source: json
//------------------------------------------------------------------------------
CControllerMap *__cdecl Create_CControllerMap()
{
  CControllerMap *v0; // eax

  v0 = (CControllerMap *)MemAlloc_Alloc(nSize: 0x16Cu);
  if ( v0 != nullptr )
    return CControllerMap::CControllerMap(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103DBC10
// Name: public: virtual void CControllerMap::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CControllerMap::ApplySettings(
        CControllerMap *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        KeyValues *inResourceData)
{
  KeyValues *v4; // esi
  KeyValues *i; // esi
  const char *Name; // eax
  char *String; // ebx
  int v8; // edi
  int v9; // edi
  unsigned __int16 m_Id; // bx
  char *v11; // eax
  char *v12; // eax
  char *v13; // eax
  CUtlMap<int,CControllerMap::button_t,unsigned short>::Node_t insert; // [esp+4h] [ebp-20h] BYREF
  CControllerMap::button_t b; // [esp+10h] [ebp-14h]
  CControllerMap *v16; // [esp+18h] [ebp-Ch]
  int code; // [esp+1Ch] [ebp-8h]
  CUtlSymbol v18; // [esp+20h] [ebp-4h] BYREF
  CUtlSymbol v19; // [esp+22h] [ebp-2h] BYREF

  v4 = inResourceData;
  v16 = this;
  vgui::Panel::ApplySettings(this, a2, a3, inResourceData);
  for ( i = KeyValues::GetFirstSubKey(this: v4); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    if ( _V_stricmp(s1: Name, s2: "button") == 0 )
    {
      String = KeyValues::GetString(this: i, keyName: "name", defaultValue: prType);
      v8 = 0;
      while ( _V_stricmp(s1: s_ControllerButtons[v8].name, s2: String) != 0 )
      {
        if ( (unsigned int)++v8 >= 0x18 )
          goto LABEL_11;
      }
      code = s_ControllerButtons[v8].code;
      if ( code != -1 )
      {
        v9 = 0xFFFF;
        m_Id = -1;
        v11 = KeyValues::GetString(this: i, keyName: "command", defaultValue: prType);
        b.cmd = (CUtlSymbol)CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&inResourceData + 1, pStr: v11)->m_Id;
        v12 = KeyValues::GetString(this: i, keyName: "text", defaultValue: nullptr);
        if ( v12 != nullptr )
        {
          LOWORD(v9) = (CUtlSymbol)CUtlSymbol::CUtlSymbol(this: &v19, pStr: v12)->m_Id;
          v13 = KeyValues::GetString(this: i, keyName: "icon", defaultValue: nullptr);
          m_Id = CUtlSymbol::CUtlSymbol(this: &v18, pStr: v13)->m_Id;
        }
        insert.key = code;
        insert.elem.cmd.m_Id = b.cmd.m_Id;
        insert.elem.text.m_Id = v9;
        insert.elem.icon.m_Id = m_Id;
        CUtlRBTree<CUtlMap<int,CControllerMap::button_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,CControllerMap::button_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CControllerMap::button_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
          this: &v16->m_buttonMap.m_Tree,
          a2: (const char *)v9,
          &insert);
      }
    }
LABEL_11:
    ;
  }
}
