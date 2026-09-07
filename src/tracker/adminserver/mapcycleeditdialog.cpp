// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tracker/adminserver/mapcycleeditdialog.cpp
// Functions: 15
// ============================================================

#include "tracker\adminserver\mapcycleeditdialog.h"

//------------------------------------------------------------------------------
// Address: 0x10002230
// Name: public: static char const __near * CMapCycleEditDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMapCycleEditDialog::GetPanelClassName()
{
  return "CMapCycleEditDialog";
}

//------------------------------------------------------------------------------
// Address: 0x10002240
// Name: protected: virtual void CMapCycleEditDialog::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapCycleEditDialog::PerformLayout(CMapCycleEditDialog *this)
{
  int v2; // edi

  this->m_LeftArrow->SetEnabled(this: this->m_LeftArrow, a2: false);
  this->m_RightArrow->SetEnabled(this: this->m_RightArrow, a2: false);
  this->m_UpArrow->SetEnabled(this: this->m_UpArrow, a2: false);
  this->m_DownArrow->SetEnabled(this: this->m_DownArrow, a2: false);
  if ( this->m_pMapCycleList->GetSelectedItemsCount(this: this->m_pMapCycleList) <= 0 )
  {
    if ( this->m_pAvailableMapList->GetSelectedItemsCount(this: this->m_pAvailableMapList) > 0 )
    {
      this->m_RightArrow->SetEnabled(this: this->m_RightArrow, a2: true);
      this->m_RightArrow->SetAsDefaultButton(this: this->m_RightArrow, a2: 1);
    }
  }
  else
  {
    this->m_LeftArrow->SetEnabled(this: this->m_LeftArrow, a2: true);
    this->m_LeftArrow->SetAsDefaultButton(this: this->m_LeftArrow, a2: 1);
    if ( this->m_pMapCycleList->GetSelectedItemsCount(this: this->m_pMapCycleList) == 1 )
    {
      v2 = this->m_pMapCycleList->GetSelectedItem(this: this->m_pMapCycleList, a2: 0);
      if ( v2 > 0 )
        this->m_UpArrow->SetEnabled(this: this->m_UpArrow, a2: true);
      if ( v2 + 1 < this->m_pMapCycleList->GetItemCount(this: this->m_pMapCycleList) )
      {
        this->m_DownArrow->SetEnabled(this: this->m_DownArrow, a2: true);
        vgui::Frame::PerformLayout(this);
        return;
      }
    }
  }
  vgui::Frame::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x10002380
// Name: private: virtual void CMapCycleEditDialog::OnItemSelected(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapCycleEditDialog::OnItemSelected(CMapCycleEditDialog *this, vgui::ListPanel *panel)
{
  vgui::ListPanel *m_pMapCycleList; // ecx

  if ( panel == this->m_pAvailableMapList
    && this->m_pAvailableMapList->GetSelectedItemsCount(this: this->m_pAvailableMapList) > 0 )
  {
    m_pMapCycleList = this->m_pMapCycleList;
LABEL_7:
    m_pMapCycleList->ClearSelectedItems(this: m_pMapCycleList);
    goto LABEL_8;
  }
  if ( panel == this->m_pMapCycleList && this->m_pMapCycleList->GetSelectedItemsCount(this: this->m_pMapCycleList) > 0 )
  {
    m_pMapCycleList = this->m_pAvailableMapList;
    goto LABEL_7;
  }
LABEL_8:
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10002400
// Name: public: virtual struct vgui::PanelMessageMap __near * CMapCycleEditDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMapCycleEditDialog::GetMessageMap(CMapCycleEditDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMapCycleEditDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMapCycleEditDialog::GetMessageMap'::`2'::s_pMap;
  `CMapCycleEditDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMapCycleEditDialog");
  `CMapCycleEditDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002430
// Name: public: virtual struct PanelAnimationMap __near * CMapCycleEditDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMapCycleEditDialog::GetAnimMap(CMapCycleEditDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CMapCycleEditDialog");
}

//------------------------------------------------------------------------------
// Address: 0x10002440
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMapCycleEditDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMapCycleEditDialog::GetKBMap(CMapCycleEditDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMapCycleEditDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMapCycleEditDialog::GetKBMap'::`2'::s_pMap;
  `CMapCycleEditDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMapCycleEditDialog");
  `CMapCycleEditDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100024A0
// Name: public: virtual void CMapCycleEditDialog::Activate(class vgui::Panel __near *,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near &,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapCycleEditDialog::Activate(
        CMapCycleEditDialog *this,
        vgui::Panel *updateTarget,
        CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *availableMaps,
        CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *mapCycle)
{
  CMapCycleEditDialog *v4; // edi
  int v5; // esi
  CUtlSymbol *v6; // edi
  const char *v7; // eax
  KeyValues *v8; // esi
  const char *v9; // eax
  KeyValues *v10; // eax
  int j; // esi
  const char *v12; // eax
  KeyValues *v13; // eax
  const char *v14; // [esp-4h] [ebp-14h]
  int i; // [esp+18h] [ebp+8h]
  KeyValues *availableMapsa; // [esp+1Ch] [ebp+Ch]

  v4 = this;
  ((void (__stdcall *)(vgui::Panel *))this->AddActionSignalTarget_2)(a1: updateTarget);
  v4->m_pAvailableMapList->DeleteAllItems(this: v4->m_pAvailableMapList);
  v4->m_pMapCycleList->DeleteAllItems(this: v4->m_pMapCycleList);
  for ( i = 0; i < availableMaps->m_Size; ++i )
  {
    v5 = 0;
    if ( mapCycle->m_Size <= 0 )
    {
LABEL_6:
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v9 = CUtlSymbol::String(this: &availableMaps->m_Memory.m_pMemory[i]);
        v10 = KeyValues::KeyValues(this: v8, setName: "MapItem", firstKey: "Map", firstValue: v9);
      }
      else
      {
        v10 = nullptr;
      }
      v4->m_pAvailableMapList->AddItem(this: v4->m_pAvailableMapList, a2: v10, a3: 0, a4: false, a5: false);
    }
    else
    {
      while ( 1 )
      {
        v6 = &mapCycle->m_Memory.m_pMemory[v5];
        v14 = CUtlSymbol::String(this: &availableMaps->m_Memory.m_pMemory[i]);
        v7 = CUtlSymbol::String(this: v6);
        if ( _V_stricmp(s1: v7, s2: v14) == 0 )
          break;
        if ( ++v5 >= mapCycle->m_Size )
        {
          v4 = this;
          goto LABEL_6;
        }
      }
      v4 = this;
    }
  }
  for ( j = 0; j < mapCycle->m_Size; ++j )
  {
    availableMapsa = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( availableMapsa != nullptr )
    {
      v12 = CUtlSymbol::String(this: &mapCycle->m_Memory.m_pMemory[j]);
      v13 = KeyValues::KeyValues(this: availableMapsa, setName: "MapItem", firstKey: "Map", firstValue: v12);
    }
    else
    {
      v13 = nullptr;
    }
    v4->m_pMapCycleList->AddItem(this: v4->m_pMapCycleList, a2: v13, a3: 0, a4: false, a5: false);
  }
  v4->SetTitle_2(this: v4, a2: "Change Map Cycle", a3: false);
  v4->MoveToCenterOfScreen(this: v4);
  vgui::Frame::Activate(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10002620
// Name: protected: void CUtlBuffer::PutTypeBin<char>(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<char>(CUtlBuffer *this, char src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002660
// Name: protected: void CUtlBuffer::PutTabs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTabs(CUtlBuffer *this)
{
  int m_nTab; // eax
  int i; // ebx

  if ( (this->m_Flags & 0x10) != 0 )
    m_nTab = 0;
  else
    m_nTab = this->m_nTab;
  for ( i = m_nTab - 1; i >= 0; --i )
  {
    if ( CUtlBuffer::CheckPut(this, nSize: 1) )
    {
      this->m_Memory.m_pMemory[this->m_Put++ - this->m_nOffset] = 9;
      CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100026B0
// Name: public: void CUtlBuffer::PutChar(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutChar(CUtlBuffer *this, char c)
{
  int m_Put; // eax

  if ( (this->m_Flags & 1) != 0 )
  {
    m_Put = this->m_Put;
    if ( m_Put != 0 && this->m_Memory.m_pMemory[m_Put - this->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this);
  }
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = c;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002710
// Name: public: CUtlBuffer::~CUtlBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::~CUtlBuffer(CUtlBuffer *this)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002740
// Name: protected: virtual void CMapCycleEditDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapCycleEditDialog::OnCommand(CMapCycleEditDialog *this, const char *command)
{
  const char *v2; // edi
  int v4; // edi
  KeyValues *v5; // eax
  const char *String; // ebx
  KeyValues *v7; // eax
  const KeyValues *v8; // eax
  int v9; // edi
  KeyValues *v10; // eax
  const char *v11; // ebx
  KeyValues *v12; // eax
  const KeyValues *v13; // eax
  int v14; // eax
  vgui::ListPanel *m_pMapCycleList; // ecx
  int v16; // ebx
  int (__thiscall *GetItemCurrentRow)(vgui::ListPanel *, int); // eax
  int v18; // eax
  int v19; // edi
  KeyValues *v20; // ebx
  const char *v21; // eax
  const char *v22; // eax
  const char *v23; // eax
  KeyValues *v24; // eax
  KeyValues *v25; // eax
  int v26; // eax
  vgui::ListPanel *v27; // ecx
  int v28; // ebx
  int (__thiscall *v29)(vgui::ListPanel *, int); // edx
  int v30; // edi
  int v31; // edi
  KeyValues *v32; // ebx
  const char *v33; // eax
  const char *v34; // eax
  const char *v35; // eax
  KeyValues *v36; // eax
  int i; // edi
  int v38; // eax
  KeyValues *v39; // eax
  const char *v40; // eax
  CRemoteServer *v41; // eax
  KeyValues *v42; // eax
  KeyValues *v43; // eax
  unsigned __int8 *m_pMemory; // [esp+1Ch] [ebp-48h]
  CUtlBuffer msg; // [esp+2Ch] [ebp-38h] BYREF
  int itemID; // [esp+5Ch] [ebp-8h]
  KeyValues *d2; // [esp+60h] [ebp-4h]

  v2 = command;
  if ( _V_stricmp(s1: command, s2: "ArrowLeft") == 0 )
  {
    while ( this->m_pMapCycleList->GetSelectedItemsCount(this: this->m_pMapCycleList) > 0 )
    {
      v4 = this->m_pMapCycleList->GetSelectedItem(this: this->m_pMapCycleList, a2: 0);
      v5 = this->m_pMapCycleList->GetItem(this: this->m_pMapCycleList, a2: v4);
      if ( v5 == nullptr )
        break;
      String = KeyValues::GetString(this: v5, keyName: "Map", defaultValue: defaultValue);
      v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      v8 = v7 != nullptr
         ? KeyValues::KeyValues(this: v7, setName: "MapItem", firstKey: "Map", firstValue: String)
         : nullptr;
      this->m_pAvailableMapList->AddItem(this: this->m_pAvailableMapList, a2: v8, a3: 0, a4: true, a5: false);
      this->m_pMapCycleList->RemoveItem(this: this->m_pMapCycleList, a2: v4);
    }
    return;
  }
  if ( _V_stricmp(s1: v2, s2: "ArrowRight") == 0 )
  {
    while ( this->m_pAvailableMapList->GetSelectedItemsCount(this: this->m_pAvailableMapList) > 0 )
    {
      v9 = this->m_pAvailableMapList->GetSelectedItem(this: this->m_pAvailableMapList, a2: 0);
      v10 = this->m_pAvailableMapList->GetItem(this: this->m_pAvailableMapList, a2: v9);
      if ( v10 == nullptr )
        break;
      v11 = KeyValues::GetString(this: v10, keyName: "Map", defaultValue: defaultValue);
      v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      v13 = v12 != nullptr
          ? KeyValues::KeyValues(this: v12, setName: "MapItem", firstKey: "Map", firstValue: v11)
          : nullptr;
      this->m_pMapCycleList->AddItem(this: this->m_pMapCycleList, a2: v13, a3: 0, a4: true, a5: false);
      this->m_pAvailableMapList->RemoveItem(this: this->m_pAvailableMapList, a2: v9);
    }
    return;
  }
  if ( _V_stricmp(s1: v2, s2: "ArrowUp") == 0 )
  {
    v14 = this->m_pMapCycleList->GetSelectedItem(this: this->m_pMapCycleList, a2: 0);
    m_pMapCycleList = this->m_pMapCycleList;
    v16 = v14;
    GetItemCurrentRow = m_pMapCycleList->GetItemCurrentRow;
    itemID = v16;
    v18 = GetItemCurrentRow(this: m_pMapCycleList, a2: v16) - 1;
    if ( v18 < 0 )
      return;
    v19 = this->m_pMapCycleList->GetItemIDFromRow(this: this->m_pMapCycleList, a2: v18);
    v20 = this->m_pMapCycleList->GetItem(this: this->m_pMapCycleList, a2: v16);
    d2 = this->m_pMapCycleList->GetItem(this: this->m_pMapCycleList, a2: v19);
    v21 = KeyValues::GetString(this: v20, keyName: "Map", defaultValue: defaultValue);
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&command, pStr: v21);
    v22 = KeyValues::GetString(this: d2, keyName: "Map", defaultValue: defaultValue);
    KeyValues::SetString(this: v20, keyName: "Map", value: v22);
    v23 = CUtlSymbol::String(this: (CUtlSymbol *)&command);
    KeyValues::SetString(this: d2, keyName: "Map", value: v23);
    this->m_pMapCycleList->ApplyItemChanges(this: this->m_pMapCycleList, a2: itemID);
    this->m_pMapCycleList->ApplyItemChanges(this: this->m_pMapCycleList, a2: v19);
    v24 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v24 != nullptr )
    {
      v25 = KeyValues::KeyValues(this: v24, setName: "KeyCodeTyped", firstKey: "code", firstValue: 88);
LABEL_27:
      ((void (__thiscall *)(CMapCycleEditDialog *, vgui::ListPanel *, KeyValues *, _DWORD))this->PostMessage)(
        a1: this,
        a2: this->m_pMapCycleList,
        a3: v25,
        a4: 0);
      return;
    }
LABEL_26:
    v25 = nullptr;
    goto LABEL_27;
  }
  if ( _V_stricmp(s1: v2, s2: "ArrowDown") == 0 )
  {
    v26 = this->m_pMapCycleList->GetSelectedItem(this: this->m_pMapCycleList, a2: 0);
    v27 = this->m_pMapCycleList;
    v28 = v26;
    v29 = v27->GetItemCurrentRow;
    itemID = v26;
    v30 = v29(this: v27, a2: v26) + 1;
    if ( v30 + 1 > this->m_pMapCycleList->GetItemCount(this: this->m_pMapCycleList) )
      return;
    v31 = this->m_pMapCycleList->GetItemIDFromRow(this: this->m_pMapCycleList, a2: v30);
    v32 = this->m_pMapCycleList->GetItem(this: this->m_pMapCycleList, a2: v28);
    d2 = this->m_pMapCycleList->GetItem(this: this->m_pMapCycleList, a2: v31);
    v33 = KeyValues::GetString(this: v32, keyName: "Map", defaultValue: defaultValue);
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&command, pStr: v33);
    v34 = KeyValues::GetString(this: d2, keyName: "Map", defaultValue: defaultValue);
    KeyValues::SetString(this: v32, keyName: "Map", value: v34);
    v35 = CUtlSymbol::String(this: (CUtlSymbol *)&command);
    KeyValues::SetString(this: d2, keyName: "Map", value: v35);
    this->m_pMapCycleList->ApplyItemChanges(this: this->m_pMapCycleList, a2: itemID);
    this->m_pMapCycleList->ApplyItemChanges(this: this->m_pMapCycleList, a2: v31);
    v36 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v36 != nullptr )
    {
      v25 = KeyValues::KeyValues(this: v36, setName: "KeyCodeTyped", firstKey: "code", firstValue: 90);
      goto LABEL_27;
    }
    goto LABEL_26;
  }
  if ( _V_stricmp(s1: v2, s2: "Cancel") != 0 )
  {
    if ( _V_stricmp(s1: v2, s2: "OK") != 0 )
    {
      vgui::Frame::OnCommand(this, command: v2);
    }
    else
    {
      CUtlBuffer::CUtlBuffer(this: &msg, growSize: 0, initSize: 1024, nFlags: 1);
      for ( i = 0; i < this->m_pMapCycleList->GetItemCount(this: this->m_pMapCycleList); ++i )
      {
        v38 = this->m_pMapCycleList->GetItemIDFromRow(this: this->m_pMapCycleList, a2: i);
        v39 = this->m_pMapCycleList->GetItem(this: this->m_pMapCycleList, a2: v38);
        if ( v39 != nullptr )
        {
          v40 = KeyValues::GetString(this: v39, keyName: "Map", defaultValue: defaultValue);
          CUtlBuffer::PutString(this: &msg, pString: v40);
          CUtlBuffer::PutChar(this: &msg, c: 10);
        }
      }
      CUtlBuffer::PutChar(this: &msg, c: 0);
      m_pMemory = msg.m_Memory.m_pMemory;
      v41 = RemoteServer();
      CRemoteServer::SetValue(this: v41, variable: "mapcycle", value: (const char *)m_pMemory);
      v42 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v42 != nullptr )
        v43 = KeyValues::KeyValues(this: v42, setName: "VarChanged", firstKey: "var", firstValue: "mapcycle");
      else
        v43 = nullptr;
      this->PostActionSignal(this, a2: v43);
      this->Close(this);
      CUtlBuffer::~CUtlBuffer(this: &msg);
    }
  }
  else
  {
    this->Close(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002CC0
// Name: public: static void CMapCycleEditDialog::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CMapCycleEditDialog::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CMapCycleEditDialog::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CMapCycleEditDialog::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CMapCycleEditDialog::`vcall'{1120,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CMapCycleEditDialog");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ItemSelected";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002D60
// Name: public: CMapCycleEditDialog::CMapCycleEditDialog(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMapCycleEditDialog *__thiscall CMapCycleEditDialog::CMapCycleEditDialog(
        CMapCycleEditDialog *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ListPanel *v7; // eax
  vgui::ListPanel *v8; // eax
  vgui::ListPanel *v9; // eax
  vgui::ListPanel *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax
  vgui::Button *v16; // eax
  vgui::Button *v17; // eax
  vgui::Button *v18; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: name, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CMapCycleEditDialog_vtbl *)&CMapCycleEditDialog::`vftable';
  if ( `CMapCycleEditDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CMapCycleEditDialog::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CMapCycleEditDialog");
    v4->pfnClassName = CMapCycleEditDialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CMapCycleEditDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMapCycleEditDialog::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CMapCycleEditDialog");
    v5->pfnClassName = CMapCycleEditDialog::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CMapCycleEditDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMapCycleEditDialog::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CMapCycleEditDialog");
    v6->pfnClassName = CMapCycleEditDialog::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CMapCycleEditDialog::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  vgui::Panel::SetSize(this, wide: 480, tall: 320);
  vgui::Frame::SetSizeable(this, state: false);
  v7 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
  if ( v7 != nullptr )
    v8 = vgui::ListPanel::ListPanel(this: v7, parent: this, panelName: "AvailableMapList");
  else
    v8 = nullptr;
  this->m_pAvailableMapList = v8;
  v8->AddColumnHeader(this: v8, a2: 0, a3: "Map", a4: "#Available_Maps", a5: 128, a6: 0);
  this->m_pAvailableMapList->SetColumnSortable(this: this->m_pAvailableMapList, a2: 0, a3: false);
  v9 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
  if ( v9 != nullptr )
    v10 = vgui::ListPanel::ListPanel(this: v9, parent: this, panelName: "MapCycleList");
  else
    v10 = nullptr;
  this->m_pMapCycleList = v10;
  v10->AddColumnHeader(this: v10, a2: 0, a3: "Map", a4: "#Map_Cycle", a5: 128, a6: 0);
  this->m_pMapCycleList->SetColumnSortable(this: this->m_pMapCycleList, a2: 0, a3: false);
  v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "RightButton",
            text: defaultValue,
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v12 = nullptr;
  this->m_RightArrow = v12;
  v13 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v13 != nullptr )
    v14 = vgui::Button::Button(
            this: v13,
            parent: this,
            panelName: "LeftButton",
            text: defaultValue,
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v14 = nullptr;
  this->m_LeftArrow = v14;
  v15 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v15 != nullptr )
    v16 = vgui::Button::Button(
            this: v15,
            parent: this,
            panelName: "UpButton",
            text: defaultValue,
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v16 = nullptr;
  this->m_UpArrow = v16;
  v17 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v17 != nullptr )
    v18 = vgui::Button::Button(
            this: v17,
            parent: this,
            panelName: "DownButton",
            text: defaultValue,
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v18 = nullptr;
  this->m_DownArrow = v18;
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Admin/MapCycleEditDialog.res",
    pathID: "PLATFORM",
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10002FD0
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}
