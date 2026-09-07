// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tracker/adminserver/serverinfopanel.cpp
// Functions: 52
// ============================================================

#include "tracker\adminserver\serverinfopanel.h"

//------------------------------------------------------------------------------
// Address: 0x10001240
// Name: public: int CUtlVector<struct vgui::PropertySheet::Page_t,class CUtlMemory<struct vgui::PropertySheet::Page_t,int>>::InsertBefore(int,struct vgui::PropertySheet::Page_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int>>::InsertBefore(
        CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *this,
        int elem,
        const vgui::PropertySheet::Page_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::PropertySheet::Page_t *m_pMemory; // ecx
  int v7; // eax
  vgui::PropertySheet::Page_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CAdminServer::OpenedManageDialog_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100015A0
// Name: public: int CUtlVector<struct vgui::MessageMapItem_t,class CUtlMemory<struct vgui::MessageMapItem_t,int>>::InsertBefore(int,struct vgui::MessageMapItem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
        CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int> > *this,
        int elem,
        const vgui::MessageMapItem_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::MessageMapItem_t *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::MessageMapItem_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: v7 << 6);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005000
// Name: public: void CUtlMemory<class CBudgetGroupInfo,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CBudgetGroupInfo,int>::Grow(CUtlMemory<CBudgetGroupInfo,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CBudgetGroupInfo *m_pMemory; // edx
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
      this->m_pMemory = (CBudgetGroupInfo *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CBudgetGroupInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005A10
// Name: public: int CUtlVector<class vgui::Label __near *,class CUtlMemory<class vgui::Label __near *,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::Label *,CUtlMemory<vgui::Label *,int>>::InsertMultipleBefore(
        CUtlVector<float,CUtlMemory<float,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  float *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10005A80
// Name: public: int CUtlVector<struct CBaseBudgetPanel::BudgetGroupTimeData_t,class CUtlMemory<struct CBaseBudgetPanel::BudgetGroupTimeData_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CBaseBudgetPanel::BudgetGroupTimeData_t,CUtlMemory<CBaseBudgetPanel::BudgetGroupTimeData_t,int>>::InsertMultipleBefore(
        CUtlVector<CBaseBudgetPanel::BudgetGroupTimeData_t,CUtlMemory<CBaseBudgetPanel::BudgetGroupTimeData_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CBaseBudgetPanel::BudgetGroupTimeData_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CBaseBudgetPanel::BudgetGroupTimeData_t,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: v9 << 13);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10005AF0
// Name: public: int CUtlVector<class CBudgetGroupInfo,class CUtlMemory<class CBudgetGroupInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CBudgetGroupInfo,CUtlMemory<CBudgetGroupInfo,int>>::InsertMultipleBefore(
        CUtlVector<CBudgetGroupInfo,CUtlMemory<CBudgetGroupInfo,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CBudgetGroupInfo *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CBudgetGroupInfo *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CBudgetGroupInfo,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 6 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_Name.m_Id = -1;
          v11->m_Color = 0;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10005F30
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> __near & CUtlVector<float,class CUtlMemory<float,int>>::operator=(class CUtlVector<float,class CUtlMemory<float,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<float,CUtlMemory<float,int> > *__thiscall CUtlVector<float,CUtlMemory<float,int>>::operator=(
        CUtlVector<float,CUtlMemory<float,int> > *this,
        const CUtlVector<float,CUtlMemory<float,int> > *other)
{
  int m_Size; // ebx
  int v4; // eax

  m_Size = other->m_Size;
  this->m_Size = 0;
  CUtlVector<vgui::Label *,CUtlMemory<vgui::Label *,int>>::InsertMultipleBefore(this, elem: 0, num: m_Size);
  v4 = 0;
  if ( m_Size >= 4 )
  {
    do
    {
      this->m_Memory.m_pMemory[v4] = other->m_Memory.m_pMemory[v4];
      this->m_Memory.m_pMemory[v4 + 1] = other->m_Memory.m_pMemory[v4 + 1];
      this->m_Memory.m_pMemory[v4 + 2] = other->m_Memory.m_pMemory[v4 + 2];
      this->m_Memory.m_pMemory[v4 + 3] = other->m_Memory.m_pMemory[v4 + 3];
      v4 += 4;
    }
    while ( v4 < m_Size - 3 );
  }
  for ( ; v4 < m_Size; ++v4 )
    this->m_Memory.m_pMemory[v4] = other->m_Memory.m_pMemory[v4];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10007300
// Name: public: int CUtlVector<struct vgui::IntRect,class CUtlMemory<struct vgui::IntRect,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::IntRect,CUtlMemory<vgui::IntRect,int>>::InsertMultipleBefore(
        CUtlVector<vgui::IntRect,CUtlMemory<vgui::IntRect,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::IntRect *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 16 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10007910
// Name: public: int CUtlVector<class IVProfExport::CExportedBudgetGroupInfo,class CUtlMemory<class IVProfExport::CExportedBudgetGroupInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<IVProfExport::CExportedBudgetGroupInfo,CUtlMemory<IVProfExport::CExportedBudgetGroupInfo,int>>::InsertMultipleBefore(
        CUtlVector<IVProfExport::CExportedBudgetGroupInfo,CUtlMemory<IVProfExport::CExportedBudgetGroupInfo,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  IVProfExport::CExportedBudgetGroupInfo *m_pMemory; // ecx
  int v9; // eax
  int v10; // eax
  IVProfExport::CExportedBudgetGroupInfo *v11; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
  if ( num > 0 )
  {
    v10 = elem;
    do
    {
      v11 = &this->m_Memory.m_pMemory[v10];
      if ( v11 != nullptr )
        v11->m_Color = 0;
      ++v10;
      --v3;
    }
    while ( v3 != 0 );
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1000B3C0
// Name: public: int CUtlVector<struct CGraphPanel::Points_t,class CUtlMemory<struct CGraphPanel::Points_t,int>>::InsertBefore(int,struct CGraphPanel::Points_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CGraphPanel::Points_t,CUtlMemory<CGraphPanel::Points_t,int>>::InsertBefore(
        CUtlVector<CGraphPanel::Points_t,CUtlMemory<CGraphPanel::Points_t,int> > *this,
        int elem,
        const CGraphPanel::Points_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CGraphPanel::Points_t *m_pMemory; // ecx
  int v7; // eax
  CGraphPanel::Points_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CGraphPanel::Points_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1000D590
// Name: public: char const __near * CServerInfoPanel::GetHostname(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CServerInfoPanel::GetHostname(CServerInfoPanel *this)
{
  return CVarListPropertyPage::GetVarString(this, varName: "hostname");
}

//------------------------------------------------------------------------------
// Address: 0x1000D5A0
// Name: protected: virtual void CServerInfoPanel::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerInfoPanel::OnThink(CServerInfoPanel *this)
{
  vgui::ISystem_vtbl *v2; // eax
  int v3; // ecx
  char timeText[64]; // [esp+4h] [ebp-48h] BYREF
  long double m_flUpdateTime; // [esp+44h] [ebp-8h]

  v2 = g_pVGuiSystem->__vftable;
  m_flUpdateTime = this->m_flUpdateTime;
  if ( v2->GetFrameTime(this: g_pVGuiSystem) > m_flUpdateTime )
    this->OnResetData(this);
  v3 = this->m_iLastUptimeReceived
     + (int)(g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem) - this->m_flLastUptimeReceiveTime);
  if ( v3 != this->m_iLastUptimeDisplayed )
  {
    this->m_iLastUptimeDisplayed = v3;
    _snprintf(
      string: timeText,
      count: 0x40u,
      format: "%0.1i:%0.2i:%0.2i:%0.2i",
      v3 / 3600 / 24,
      v3 / 3600,
      v3 / 60 % 60,
      v3 % 60);
    this->SetControlString_2(this, a2: "UpTimeText", a3: timeText);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D690
// Name: public: virtual void CServerInfoPanel::OnResetData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerInfoPanel::OnResetData(CServerInfoPanel *this)
{
  CRemoteServer *v2; // eax
  CRemoteServer *v3; // eax
  CRemoteServer *v4; // eax
  CRemoteServer *v5; // eax
  CRemoteServer *v6; // eax
  CRemoteServer *v7; // eax
  IServerDataResponse *v8; // [esp-8h] [ebp-10h]

  if ( !this->m_bMapListRetrieved )
  {
    v8 = &this->IServerDataResponse;
    v2 = RemoteServer();
    CRemoteServer::RequestValue(this: v2, requester: v8, variable: "maplist");
    this->m_bMapListRetrieved = true;
  }
  this->RefreshVarList(this);
  v3 = RemoteServer();
  CRemoteServer::RequestValue(this: v3, requester: &this->IServerDataResponse, variable: "playercount");
  v4 = RemoteServer();
  CRemoteServer::RequestValue(this: v4, requester: &this->IServerDataResponse, variable: "maxplayers");
  v5 = RemoteServer();
  CRemoteServer::RequestValue(this: v5, requester: &this->IServerDataResponse, variable: "gamedescription");
  v6 = RemoteServer();
  CRemoteServer::RequestValue(this: v6, requester: &this->IServerDataResponse, variable: "uptime");
  v7 = RemoteServer();
  CRemoteServer::RequestValue(this: v7, requester: &this->IServerDataResponse, variable: "ipaddress");
  this->m_flUpdateTime = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem) + 60.0;
}

//------------------------------------------------------------------------------
// Address: 0x1000D750
// Name: protected: virtual void CServerInfoPanel::OnEditVariable(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerInfoPanel::OnEditVariable(CServerInfoPanel *this, KeyValues *rule)
{
  const char *Name; // eax
  CMapCycleEditDialog *v4; // eax
  CMapCycleEditDialog *v5; // eax

  Name = KeyValues::GetName(this: rule);
  if ( _V_stricmp(s1: Name, s2: "mapcycle") != 0 )
  {
    CVarListPropertyPage::OnEditVariable(this, rule);
  }
  else
  {
    v4 = (CMapCycleEditDialog *)operator new(nSize: 0x22Cu);
    if ( v4 != nullptr )
      v5 = CMapCycleEditDialog::CMapCycleEditDialog(this: v4, parent: this, name: "MapCycleEditDialog");
    else
      v5 = nullptr;
    v5->Activate_2(this: v5, a2: this, a3: &this->m_AvailableMaps, a4: &this->m_MapCycle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D860
// Name: private: void CServerInfoPanel::UpdateMapCycleValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerInfoPanel::UpdateMapCycleValue(CServerInfoPanel *this)
{
  CServerInfoPanel *v1; // edi
  const char *VarString; // eax
  int v3; // esi
  int v4; // ebx
  CUtlSymbol *v5; // edi
  const char *v6; // eax
  char v7; // dl
  int v8; // ebx
  int m_Size; // eax
  int v10; // ecx
  char *v11; // eax
  char v12; // dl
  const char *v13; // ecx
  unsigned int v14; // eax
  const char *v15; // esi
  char *v16; // edi
  char v17; // cl
  char *v18; // eax
  char v19; // cl
  char *v20; // edi
  char v21; // al
  CVarListPropertyPage *v22; // ecx
  const char *v23; // [esp-Ch] [ebp-21Ch]
  char v24; // [esp+3h] [ebp-20Dh] BYREF
  char nextMaps[512]; // [esp+4h] [ebp-20Ch] BYREF
  int i; // [esp+204h] [ebp-Ch]
  CUtlSymbol currentMap; // [esp+208h] [ebp-8h] BYREF
  CVarListPropertyPage *v28; // [esp+20Ch] [ebp-4h]

  v1 = this;
  v28 = this;
  VarString = CVarListPropertyPage::GetVarString(this, varName: "map");
  CUtlSymbol::CUtlSymbol(this: &currentMap, pStr: VarString);
  if ( currentMap.m_Id != 0xFFFF )
  {
    v3 = 0;
    v4 = -1;
    if ( v1->m_MapCycle.m_Size > 0 )
    {
      do
      {
        v5 = &v1->m_MapCycle.m_Memory.m_pMemory[v3];
        v23 = CUtlSymbol::String(this: &currentMap);
        v6 = CUtlSymbol::String(this: v5);
        if ( _V_stricmp(s1: v6, s2: v23) == 0 )
          v4 = v3;
        ++v3;
        v1 = (CServerInfoPanel *)v28;
      }
      while ( v3 < v28[1].m_lLastDoublePressTime );
    }
    v7 = 0;
    nextMaps[0] = 0;
    v8 = v4 + 1;
    for ( i = 2; i != 0; --i )
    {
      m_Size = v1->m_MapCycle.m_Size;
      v10 = v8;
      if ( v8 >= m_Size )
        v10 = v8 - m_Size;
      if ( v10 >= 0 && v10 < m_Size )
      {
        if ( v7 != 0 )
        {
          v11 = &v24;
          do
            v12 = *++v11;
          while ( v12 != 0 );
          strcpy(v11, ", ");
        }
        v13 = CUtlSymbol::String(this: &v1->m_MapCycle.m_Memory.m_pMemory[v10]);
        v14 = strlen(v13) + 1;
        v15 = v13;
        v16 = &v24;
        do
          v17 = *++v16;
        while ( v17 != 0 );
        qmemcpy(v16, v15, v14);
        v1 = (CServerInfoPanel *)v28;
        v7 = 1;
      }
      ++v8;
    }
    if ( v7 != 0 )
    {
      v18 = &v24;
      do
        v19 = *++v18;
      while ( v19 != 0 );
      strcpy(v18, ", ");
    }
    v20 = &v24;
    do
      v21 = *++v20;
    while ( v21 != 0 );
    v22 = v28;
    strcpy(v20, "...");
    CVarListPropertyPage::SetVarString(this: v22, varName: "mapcycle", value: nextMaps);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D9C0
// Name: public: CServerInfoPanel::CServerInfoPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerInfoPanel *__thiscall CServerInfoPanel::CServerInfoPanel(
        CServerInfoPanel *this,
        vgui::Panel *parent,
        const char *name)
{
  CRemoteServer *v4; // eax
  CRemoteServer *v5; // eax

  CVarListPropertyPage::CVarListPropertyPage(this, parent, name);
  this->CVarListPropertyPage::vgui::PropertyPage::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CServerInfoPanel_vtbl *)&CServerInfoPanel::`vftable'{for `vgui::PropertyPage'};
  this->CVarListPropertyPage::IServerDataResponse::__vftable = (IServerDataResponse_vtbl *)&CServerInfoPanel::`vftable'{for `IServerDataResponse'};
  this->m_AvailableMaps.m_Memory.m_pMemory = nullptr;
  this->m_AvailableMaps.m_Memory.m_nAllocationCount = 0;
  this->m_AvailableMaps.m_Memory.m_nGrowSize = 0;
  this->m_AvailableMaps.m_Size = 0;
  this->m_AvailableMaps.m_pElements = nullptr;
  this->m_MapCycle.m_Memory.m_pMemory = nullptr;
  this->m_MapCycle.m_Memory.m_nAllocationCount = 0;
  this->m_MapCycle.m_Memory.m_nGrowSize = 0;
  this->m_MapCycle.m_Size = 0;
  this->m_MapCycle.m_pElements = nullptr;
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Admin/GamePanelInfo.res",
    pathID: "PLATFORM",
    pKeyValues: nullptr,
    pConditions: nullptr);
  CVarListPropertyPage::LoadVarList(this, varfile: "Admin/MainServerConfig.vdf");
  this->m_iLastUptimeDisplayed = 0;
  this->m_flUpdateTime = 0.0;
  this->m_bMapListRetrieved = false;
  v4 = RemoteServer();
  CRemoteServer::AddServerMessageHandler(this: v4, handler: &this->IServerDataResponse, watch: "UpdatePlayers");
  v5 = RemoteServer();
  CRemoteServer::AddServerMessageHandler(this: v5, handler: &this->IServerDataResponse, watch: "UpdateMap");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000DAF0
// Name: private: void CServerInfoPanel::ParseIntoMapList(char const __near *,class CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerInfoPanel::ParseIntoMapList(
        CServerInfoPanel *this,
        char *maplist,
        CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *mapArray)
{
  CUtlMemory<wchar_t,int> *v3; // esi
  unsigned __int8 *v4; // edi
  const char *v5; // eax
  const char *v6; // ebx
  const char *v7; // eax
  signed int v8; // edi
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  wchar_t *v11; // ecx
  int v12; // eax
  int v13; // edi
  wchar_t *v14; // eax
  char customString[64]; // [esp+8h] [ebp-40h] BYREF

  v3 = (CUtlMemory<wchar_t,int> *)mapArray;
  v4 = (unsigned __int8 *)maplist;
  mapArray->m_Size = 0;
  if ( *maplist != 0 )
  {
    do
    {
      if ( isspace(c: (char)*v4) != 0 )
      {
        maplist = (char *)++v4;
      }
      else
      {
        strstr(str1: v4, str2: "\n");
        v6 = v5;
        strstr(str1: v4, str2: "\r");
        if ( v6 == nullptr )
          return;
        if ( v7 != nullptr && v7 < v6 )
          v6 = v7;
        v8 = v6 - maplist;
        if ( (unsigned int)(v6 - maplist) >= 0x40 )
          v8 = 63;
        strncpy(dest: (unsigned __int8 *)customString, source: (unsigned __int8 *)maplist, count: v8);
        customString[v8] = 0;
        maplist = (char *)v6;
        if ( v8 > 0 && (customString[0] != 47 || customString[1] != 47) )
        {
          m_pMemory = (int)v3[1].m_pMemory;
          m_nAllocationCount = v3->m_nAllocationCount;
          if ( m_pMemory + 1 > m_nAllocationCount )
            CUtlMemory<wchar_t,int>::Grow(this: v3, num: m_pMemory - m_nAllocationCount + 1);
          ++v3[1].m_pMemory;
          v11 = v3->m_pMemory;
          v12 = (int)v3[1].m_pMemory - m_pMemory - 1;
          v3[1].m_nAllocationCount = (int)v3->m_pMemory;
          if ( v12 > 0 )
            _V_memmove(dest: &v11[m_pMemory + 1], src: &v11[m_pMemory], count: 2 * v12);
          v13 = m_pMemory;
          v14 = &v3->m_pMemory[v13];
          if ( v14 != nullptr )
            *v14 = -1;
          CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&mapArray + 1, pStr: customString);
          v3->m_pMemory[v13] = HIWORD(mapArray);
        }
        v4 = (unsigned __int8 *)v6;
      }
    }
    while ( *v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DC20
// Name: protected: virtual void CServerInfoPanel::OnServerDataResponse(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerInfoPanel::OnServerDataResponse(CServerInfoPanel *this, const char *value, char *response)
{
  int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  char buf[128]; // [esp+Ch] [ebp-80h] BYREF

  if ( _V_stricmp(s1: value, s2: "playercount") != 0 )
  {
    if ( _V_stricmp(s1: value, s2: "maxplayers") != 0 )
    {
      if ( _V_stricmp(s1: value, s2: "gamedescription") != 0 )
      {
        if ( _V_stricmp(s1: value, s2: "hostname") != 0 )
        {
          if ( _V_stricmp(s1: value, s2: "UpdateMap") != 0 && _V_stricmp(s1: value, s2: "UpdatePlayers") != 0 )
          {
            if ( _V_stricmp(s1: value, s2: "maplist") == 0 )
            {
              CVarListPropertyPage::SetCustomStringList(
                this: (CServerInfoPanel *)((char *)this - 392),
                varName: "map",
                stringList: response);
              CServerInfoPanel::ParseIntoMapList(
                this: (CServerInfoPanel *)((char *)this - 392),
                maplist: response,
                mapArray: (CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *)&this->m_clrDropFrame);
              return;
            }
            if ( _V_stricmp(s1: value, s2: "uptime") != 0 )
            {
              if ( _V_stricmp(s1: value, s2: "ipaddress") != 0 )
              {
                if ( _V_stricmp(s1: value, s2: "mapcycle") == 0 )
                {
                  CServerInfoPanel::ParseIntoMapList(
                    this: (CServerInfoPanel *)((char *)this - 392),
                    maplist: response,
                    mapArray: (CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *)&this->m_hKeyBindingsContext);
                  CServerInfoPanel::UpdateMapCycleValue(this: (CServerInfoPanel *)((char *)this - 392));
                  return;
                }
              }
              else
              {
                (*(void (__thiscall **)(char *, const char *, char *))(*((_DWORD *)this - 98) + 876))(
                  a1: (char *)this - 392,
                  a2: "ServerIPText",
                  a3: response);
              }
            }
            else
            {
              *(_DWORD *)&this->m_InternalKeyFocusTicked_register = atoi(nptr: response);
              *(float *)&this->m_InternalKeyCodePressed_register = g_pVGuiSystem->GetFrameTime(this: g_pVGuiSystem);
            }
          }
          else
          {
            this->m_LastNavDirection = ND_UP;
          }
        }
        else
        {
          v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v5 != nullptr )
            v6 = KeyValues::KeyValues(this: v5, setName: "UpdateTitle");
          else
            v6 = nullptr;
          (*(void (__thiscall **)(char *, KeyValues *))(*((_DWORD *)this - 98) + 196))(a1: (char *)this - 392, a2: v6);
        }
      }
      else
      {
        (*(void (__thiscall **)(char *, const char *, char *))(*((_DWORD *)this - 98) + 876))(
          a1: (char *)this - 392,
          a2: "GameText",
          a3: response);
      }
    }
    else
    {
      v4 = atoi(nptr: response);
      *(_DWORD *)&this->m_InternalMouseDoublePressed_register = v4;
      buf[0] = 0;
      if ( v4 > 0 )
        sprintf(string: buf, format: "%d / %d", *(_DWORD *)&this->m_InternalCursorMoved_register, v4);
      (*(void (__thiscall **)(char *, const char *, char *))(*((_DWORD *)this - 98) + 876))(
        a1: (char *)this - 392,
        a2: "PlayersText",
        a3: buf);
    }
  }
  else
  {
    *(_DWORD *)&this->m_InternalCursorMoved_register = atoi(nptr: response);
  }
  CVarListPropertyPage::OnServerDataResponse(this, value, response);
  if ( _V_stricmp(s1: value, s2: "map") == 0 )
    CServerInfoPanel::UpdateMapCycleValue(this: (CServerInfoPanel *)((char *)this - 392));
}

//------------------------------------------------------------------------------
// Address: 0x100237A0
// Name: public: int CUtlVector<struct vgui::BoundKey_t,class CUtlMemory<struct vgui::BoundKey_t,int>>::InsertBefore(int,struct vgui::BoundKey_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
        CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int> > *this,
        int elem,
        const vgui::BoundKey_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::BoundKey_t *m_pMemory; // ecx
  int v7; // eax
  vgui::BoundKey_t *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    vgui::BoundKey_t::BoundKey_t(this: v8, src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10023810
// Name: public: int CUtlVector<struct PanelAnimationMapEntry,class CUtlMemory<struct PanelAnimationMapEntry,int>>::InsertBefore(int,struct PanelAnimationMapEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
        CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int> > *this,
        int elem,
        const PanelAnimationMapEntry *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  PanelAnimationMapEntry *m_pMemory; // ecx
  int v7; // eax
  PanelAnimationMapEntry *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100238A0
// Name: public: int CUtlVector<struct vgui::OverridableColorEntry,class CUtlMemory<struct vgui::OverridableColorEntry,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
        CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::OverridableColorEntry *m_pMemory; // ecx
  int v6; // eax
  vgui::OverridableColorEntry *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    v7->m_colFromScript = 0;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1002C440
// Name: public: int CUtlVector<struct vgui::AnimationController::ActiveAnimation_t,class CUtlMemory<struct vgui::AnimationController::ActiveAnimation_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::AnimationController::ActiveAnimation_t,CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int>>::InsertBefore(
        CUtlVector<vgui::AnimationController::ActiveAnimation_t,CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::AnimationController::ActiveAnimation_t *m_pMemory; // ecx
  int v6; // eax
  vgui::AnimationController::ActiveAnimation_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 68 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    v7->panel.m_iPanelID = -1;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1002D6D0
// Name: public: void CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this)
{
  int v1; // ebx
  int v2; // edx
  char *v3; // esi
  void *v4; // eax
  CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *v5; // [esp+4h] [ebp-8h]
  int v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 28 * v1;
    v6 = 28 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 5) = 0;
      if ( *((int *)v3 + 4) >= 0 )
      {
        if ( *((_DWORD *)v3 + 2) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 2));
          v2 = v6;
          this = v5;
          *((_DWORD *)v3 + 2) = 0;
        }
        *((_DWORD *)v3 + 3) = 0;
      }
      v4 = *((void **)v3 + 2);
      *((_DWORD *)v3 + 6) = v4;
      if ( *((int *)v3 + 4) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          v2 = v6;
          this = v5;
          *((_DWORD *)v3 + 2) = 0;
        }
        *((_DWORD *)v3 + 3) = 0;
      }
      --v1;
      v2 -= 28;
      v6 = v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D9D0
// Name: public: CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::~CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::~CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this)
{
  bool v2; // sf
  vgui::AnimationController::AnimSequence_t *m_pMemory; // eax

  CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
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
// Address: 0x10036DB0
// Name: public: void CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::RemoveMultiple(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::RemoveMultiple(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int elem,
        int num)
{
  if ( this->m_Size - elem - num > 0 && num > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + num],
      count: 2 * (this->m_Size - elem - num));
  this->m_Size -= num;
}

//------------------------------------------------------------------------------
// Address: 0x10038780
// Name: public: void CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::EnsureCapacity(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int num)
{
  wchar_t *m_pMemory; // edx
  unsigned int v4; // eax
  wchar_t *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 2 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (wchar_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (wchar_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038DE0
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
// Address: 0x1003FFE0
// Name: public: void CUtlVector<struct vgui::PropertySheet::Page_t,class CUtlMemory<struct vgui::PropertySheet::Page_t,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int>>::Remove(
        CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *this,
        int elem)
{
  int v3; // eax

  v3 = this->m_Size - elem - 1;
  if ( v3 > 0 )
    _V_memmove(dest: &this->m_Memory.m_pMemory[elem], src: &this->m_Memory.m_pMemory[elem + 1], count: 8 * v3);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10040020
// Name: public: int CUtlVector<class vgui::PageTab __near *,class CUtlMemory<class vgui::PageTab __near *,int>>::Find(class vgui::PageTab __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int>>::Find(
        CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *this,
        vgui::PageTab **src)
{
  int m_Size; // edx
  int result; // eax
  vgui::PageTab **i; // ecx

  m_Size = this->m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10040050
// Name: public: void CUtlVector<class vgui::PageTab __near *,class CUtlMemory<class vgui::PageTab __near *,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int>>::Remove(
        CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *this,
        int elem)
{
  int v3; // eax

  v3 = this->m_Size - elem - 1;
  if ( v3 > 0 )
    _V_memmove(dest: &this->m_Memory.m_pMemory[elem], src: &this->m_Memory.m_pMemory[elem + 1], count: 4 * v3);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10040510
// Name: public: int CUtlVector<class vgui::PageTab __near *,class CUtlMemory<class vgui::PageTab __near *,int>>::InsertBefore(int,class vgui::PageTab __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int>>::InsertBefore(
        CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *this,
        int elem,
        vgui::PageTab **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::PageTab **m_pMemory; // ecx
  int v7; // eax
  vgui::PageTab **v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10047B00
// Name: public: int CUtlVector<int,class CUtlMemory<int,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemory<int,int>>::AddToTail(CUtlVector<int,CUtlMemory<int,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  int *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100580E0
// Name: public: int CUtlVector<struct vgui::RichText::TFormatStream,class CUtlMemory<struct vgui::RichText::TFormatStream,int>>::InsertBefore(int,struct vgui::RichText::TFormatStream const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::RichText::TFormatStream,CUtlMemory<vgui::RichText::TFormatStream,int>>::InsertBefore(
        CUtlVector<vgui::RichText::TFormatStream,CUtlMemory<vgui::RichText::TFormatStream,int> > *this,
        int elem,
        const vgui::RichText::TFormatStream *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::RichText::TFormatStream *m_pMemory; // ecx
  int v7; // eax
  vgui::RichText::TFormatStream *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::RichText::TFormatStream,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 32 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1005F500
// Name: public: int CUtlVector<class vgui::TreeNode __near *,class CUtlMemory<class vgui::TreeNode __near *,int>>::AddToHead(class vgui::TreeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int>>::AddToHead(
        CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *this,
        vgui::TreeNode **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::TreeNode **m_pMemory; // eax
  int v6; // ecx
  vgui::TreeNode **v7; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: m_pMemory + 1, src: m_pMemory, count: 4 * v6);
  v7 = this->m_Memory.m_pMemory;
  if ( v7 != nullptr )
    *v7 = *src;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10061B30
// Name: public: int CUtlVector<class vgui::CTreeViewListControl::CColumnInfo,class CUtlMemory<class vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
        CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  vgui::CTreeViewListControl::CColumnInfo *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_Title.m_Id = -1;
          v11->m_ciFlags = 0;
          v11->m_Right = 0;
          v11->m_Left = 0;
          v11->m_Width = 0;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10063CA0
// Name: public: CUtlVector<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,int>>::~CUtlVector<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(
        CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *this)
{
  bool v2; // sf
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // eax

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
// Address: 0x10064D60
// Name: public: void CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CUtlString *v3; // esi
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_Storage.m_nActualLength = 0;
      if ( v3->m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10064DD0
// Name: public: int CUtlVector<struct vgui::FileData_t,class CUtlMemory<struct vgui::FileData_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::FileData_t,CUtlMemory<vgui::FileData_t,int>>::InsertBefore(
        CUtlVector<vgui::FileData_t,CUtlMemory<vgui::FileData_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::FileData_t *m_pMemory; // ecx
  int v6; // eax
  vgui::FileData_t *v7; // edi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::FileData_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 288 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    CUtlString::CUtlString(this: &this->m_Memory.m_pMemory[elem].m_FileAttributes);
    CUtlString::CUtlString(this: &v7->m_CreationTime);
    CUtlString::CUtlString(this: &v7->m_LastAccessTime);
    CUtlString::CUtlString(this: &v7->m_LastWriteTime);
    CUtlString::CUtlString(this: &v7->m_FileName);
    CUtlString::CUtlString(this: &v7->m_FullPath);
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10065D30
// Name: public: CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::~CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  bool v2; // sf
  CUtlString *m_pMemory; // eax

  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
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
// Address: 0x10065D90
// Name: public: void CUtlVector<struct vgui::FileData_t,class CUtlMemory<struct vgui::FileData_t,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::FileData_t,CUtlMemory<vgui::FileData_t,int>>::Purge(
        CUtlVector<vgui::FileData_t,CUtlMemory<vgui::FileData_t,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  vgui::FileData_t *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      vgui::FileData_t::~FileData_t(this: &this->m_Memory.m_pMemory[v3--]);
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067490
// Name: public: void CUtlVector<class vgui::CHistoryItem,class CUtlMemory<class vgui::CHistoryItem,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::RemoveAll(
        CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  vgui::CHistoryItem *m_pMemory; // esi
  CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      free(pMem: this->m_Memory.m_pMemory[v2].m_text);
      free(pMem: m_pMemory[v2].m_extraText);
      m_pMemory[v2--].m_text = nullptr;
      if ( --v1 < 0 )
        break;
      this = v4;
    }
    v4->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067970
// Name: public: void CUtlVector<class vgui::CConsolePanel::CompletionItem __near *,class CUtlMemory<class vgui::CConsolePanel::CompletionItem __near *,int>>::Sort(int (*)(class vgui::CConsolePanel::CompletionItem __near * const __near *,class vgui::CConsolePanel::CompletionItem __near * const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::CConsolePanel::CompletionItem *,CUtlMemory<vgui::CConsolePanel::CompletionItem *,int>>::Sort(
        CUtlVector<vgui::CConsolePanel::CompletionItem *,CUtlMemory<vgui::CConsolePanel::CompletionItem *,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  signed int m_Size; // ebx
  int i; // ebx
  int j; // esi
  vgui::CConsolePanel::CompletionItem *v6; // ecx
  vgui::CConsolePanel::CompletionItem **v7; // eax

  m_Size = this->m_Size;
  if ( m_Size > 1 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: this->m_Memory.m_pMemory, num: m_Size, width: 4u, comp: pfnCompare);
    }
    else
    {
      for ( i = m_Size - 1; i >= 0; --i )
      {
        for ( j = 1; j <= i; ++j )
        {
          if ( pfnCompare(a1: &this->m_Memory.m_pMemory[j - 1], a2: &this->m_Memory.m_pMemory[j]) < 0 )
          {
            v6 = this->m_Memory.m_pMemory[j - 1];
            v7 = &this->m_Memory.m_pMemory[j];
            *(v7 - 1) = *v7;
            *v7 = v6;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100679F0
// Name: public: void CUtlVector<class vgui::CHistoryItem,class CUtlMemory<class vgui::CHistoryItem,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::Remove(
        CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int> > *this,
        int elem)
{
  vgui::CHistoryItem *m_pMemory; // esi

  m_pMemory = this->m_Memory.m_pMemory;
  free(pMem: this->m_Memory.m_pMemory[elem].m_text);
  free(pMem: m_pMemory[elem].m_extraText);
  m_pMemory[elem].m_text = nullptr;
  if ( this->m_Size - elem - 1 > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + 1],
      count: 12 * (this->m_Size - elem - 1));
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10067B20
// Name: public: CUtlVector<class vgui::CHistoryItem,class CUtlMemory<class vgui::CHistoryItem,int>>::~CUtlVector<class vgui::CHistoryItem,class CUtlMemory<class vgui::CHistoryItem,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::~CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>(
        CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int> > *this)
{
  bool v2; // sf
  vgui::CHistoryItem *m_pMemory; // eax

  CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
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
// Address: 0x1006A8C0
// Name: public: virtual class CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>> __near * vgui::BuildGroup::GetControlGroup(void)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *__thiscall vgui::BuildGroup::GetControlGroup(
        vgui::BuildGroup *this)
{
  return &this->_controlGroup;
}

//------------------------------------------------------------------------------
// Address: 0x1006BEA0
// Name: public: int CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int>>::InsertMultipleBefore(
        CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::PHandle *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  vgui::PHandle *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->m_iPanelID = -1;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1006C480
// Name: public: bool CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>>::FindAndRemove(class vgui::PHandle const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int>>::FindAndRemove(
        CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *this,
        vgui::TreeNode **src)
{
  int m_Size; // edx
  int v4; // eax
  vgui::TreeNode **m_pMemory; // ebx
  vgui::TreeNode **i; // ecx
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
// Address: 0x1006C4F0
// Name: public: int CUtlVector<struct CUtlHandleTable<class vgui::BuildGroup,20>::EntryType_t,class CUtlMemory<struct CUtlHandleTable<class vgui::BuildGroup,20>::EntryType_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int>>::InsertBefore(
        CUtlVector<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *m_pMemory; // ecx
  int v6; // eax
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CAdminServer::OpenedManageDialog_t,int>::Grow(
      (CUtlMemory<vgui::PropertySheet::Page_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    *(_DWORD *)v7 = 0;
    v7->m_pData = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1006E710
// Name: public: void CUtlMemory<struct PanelItem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<PanelItem_t,int>::Grow(CUtlMemory<PanelItem_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  PanelItem_t *m_pMemory; // edx
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
    v7 = 84 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (PanelItem_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (PanelItem_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006E7A0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>::Grow(
        CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // edx
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
    v7 = 20 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::CTreeViewListControl::CColumnInfo *)_g_pMemAlloc->Realloc_2(
                                                                     this: _g_pMemAlloc,
                                                                     a2: m_pMemory,
                                                                     a3: v7);
    else
      this->m_pMemory = (vgui::CTreeViewListControl::CColumnInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10092FF0
// Name: _dynamic_initializer_for__panel_test_title_safe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__panel_test_title_safe__()
{
  ConVar::ConVar(
    this: &panel_test_title_safe,
    pName: "panel_test_title_safe",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Test vgui panel positioning with title safe indentation");
  return atexit(func: dynamic_atexit_destructor_for__panel_test_title_safe__);
}

//------------------------------------------------------------------------------
// Address: 0x10093860
// Name: _dynamic_atexit_destructor_for__panel_test_title_safe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__panel_test_title_safe__()
{
  ConVar::~ConVar(this: &panel_test_title_safe);
}
