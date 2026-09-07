// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/vgui/toggleexitspanel.cpp
// Functions: 36
// ============================================================

#include "missionchooser\vgui\toggleexitspanel.h"

//------------------------------------------------------------------------------
// Address: 0x10005370
// Name: public: void CUtlMemory<struct MapListName,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<MapListName,int>::Grow(CUtlMemory<MapListName,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  MapListName *m_pMemory; // edx
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
    v7 = m_nAllocationCount << 8;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (MapListName *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (MapListName *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005400
// Name: public: void CUtlMemory<struct ASW_Mission_Chooser_Saved_Campaign,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ASW_Mission_Chooser_Saved_Campaign,int>::Grow(
        CUtlMemory<ASW_Mission_Chooser_Saved_Campaign,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ASW_Mission_Chooser_Saved_Campaign *m_pMemory; // edx
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
    v7 = 968 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ASW_Mission_Chooser_Saved_Campaign *)_g_pMemAlloc->Realloc_2(
                                                                this: _g_pMemAlloc,
                                                                a2: m_pMemory,
                                                                a3: v7);
    else
      this->m_pMemory = (ASW_Mission_Chooser_Saved_Campaign *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007200
// Name: public: void CUtlMemory<class CASW_MissionTextSpec,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CASW_MissionTextSpec,int>::Grow(CUtlMemory<CBSPFace,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CBSPFace *m_pMemory; // edx
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
    v7 = 40 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CBSPFace *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CBSPFace *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012780
// Name: public: void CUtlMemory<class CInstanceSpawn,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CInstanceSpawn,int>::Grow(CUtlMemory<CInstanceSpawn,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CInstanceSpawn *m_pMemory; // edx
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
    v7 = 296 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CInstanceSpawn *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CInstanceSpawn *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012820
// Name: public: void CUtlMemory<class CExit,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CExit,int>::Grow(CUtlMemory<PanelItem_t,int> *this, int num)
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
// Address: 0x100187B0
// Name: public: void CUtlMemory<class ITilegenClassFactory<class ITilegenExpression<class CRoomCandidate const __near *>> __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
        CUtlMemory<vgui::TreeNode *,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::TreeNode **m_pMemory; // edx
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
      this->m_pMemory = (vgui::TreeNode **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (vgui::TreeNode **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DA80
// Name: public: static char const __near * CToggleExitsPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CToggleExitsPanel::GetPanelClassName()
{
  return "CToggleExitsPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1002DA90
// Name: public: static char const __near * CToggleExitButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CToggleExitButton::GetPanelClassName()
{
  return "CToggleExitButton";
}

//------------------------------------------------------------------------------
// Address: 0x1002DAA0
// Name: public: virtual void CToggleExitsPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToggleExitsPanel::PerformLayout(CToggleExitsPanel *this)
{
  CRoomTemplatePanel *m_pRoomTemplatePanel; // ecx
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int t; // [esp+Ch] [ebp-8h] BYREF
  int w; // [esp+10h] [ebp-4h] BYREF

  m_pRoomTemplatePanel = this->m_pRoomTemplatePanel;
  if ( m_pRoomTemplatePanel != nullptr )
  {
    vgui::Panel::GetBounds(this: m_pRoomTemplatePanel, &x, &y, wide: &w, tall: &t);
    vgui::Panel::SetBounds(this, x: x - 16, y: y - 16, wide: w + 32, tall: t + 32);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DB00
// Name: public: virtual void CToggleExitButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToggleExitButton::ApplySchemeSettings(CToggleExitButton *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  this->SetPaintBackgroundEnabled(this, a2: true);
  this->SetPaintBackgroundType(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1002DB30
// Name: public: virtual void CToggleExitButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToggleExitButton::PerformLayout(CToggleExitButton *this)
{
  int m_fTileSize; // eax

  if ( g_pTileGenDialog != nullptr )
  {
    m_fTileSize = (int)g_pTileGenDialog->m_fTileSize;
    switch ( this->m_ExitDirection )
    {
      case EXITDIR_BEGIN:
        vgui::Panel::SetBounds(
          this,
          x: m_fTileSize * this->m_iTileX + 16,
          y: m_fTileSize * this->m_iTileY,
          wide: m_fTileSize - 1,
          tall: 14);
        break;
      case EXITDIR_EAST:
        vgui::Panel::SetBounds(
          this,
          x: m_fTileSize * (this->m_iTileX + 1) + 18,
          y: m_fTileSize * this->m_iTileY + 16,
          wide: 14,
          tall: m_fTileSize - 1);
        break;
      case EXITDIR_SOUTH:
        vgui::Panel::SetBounds(
          this,
          x: m_fTileSize * this->m_iTileX + 16,
          y: m_fTileSize * (this->m_iTileY + 1) + 18,
          wide: m_fTileSize - 1,
          tall: 14);
        break;
      case EXITDIR_WEST:
        vgui::Panel::SetBounds(
          this,
          x: m_fTileSize * this->m_iTileX,
          y: m_fTileSize * this->m_iTileY + 16,
          wide: 14,
          tall: m_fTileSize - 1);
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DC00
// Name: public: virtual struct vgui::PanelMessageMap __near * CToggleExitButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CToggleExitButton::GetMessageMap(CToggleExitButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CToggleExitButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CToggleExitButton::GetMessageMap'::`2'::s_pMap;
  `CToggleExitButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CToggleExitButton");
  `CToggleExitButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002DC30
// Name: public: virtual struct PanelAnimationMap __near * CToggleExitButton::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CToggleExitButton::GetAnimMap(CToggleExitButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CToggleExitButton");
}

//------------------------------------------------------------------------------
// Address: 0x1002DC40
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CToggleExitButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CToggleExitButton::GetKBMap(CToggleExitButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CToggleExitButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CToggleExitButton::GetKBMap'::`2'::s_pMap;
  `CToggleExitButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CToggleExitButton");
  `CToggleExitButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002DC70
// Name: public: CToggleExitButton::CToggleExitButton(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CToggleExitButton *__thiscall CToggleExitButton::CToggleExitButton(
        CToggleExitButton *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (CToggleExitButton_vtbl *)&CToggleExitButton::`vftable';
  if ( `CToggleExitButton::ChainToMap'::`2'::chained == 0 )
  {
    `CToggleExitButton::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CToggleExitButton");
    v4->pfnClassName = CToggleExitButton::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CToggleExitButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CToggleExitButton::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CToggleExitButton");
    v5->pfnClassName = CToggleExitButton::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CToggleExitButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CToggleExitButton::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CToggleExitButton");
    v6->pfnClassName = CToggleExitButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002DD60
// Name: public: virtual void CToggleExitButton::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToggleExitButton::OnMouseReleased(CToggleExitButton *this, ButtonCode_t code)
{
  vgui::Panel *v3; // eax
  void *v4; // eax
  void *v5; // eax
  CRoomTemplateEditDialog *v6; // ecx

  v3 = this->GetParent(this);
  v4 = __RTDynamicCast(
         inptr: v3,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &CToggleExitsPanel `RTTI Type Descriptor',
         isReference: 0);
  if ( v4 != nullptr )
  {
    v5 = (void *)(*(int (__thiscall **)(void *))(*(_DWORD *)v4 + 156))(a1: v4);
    v6 = (CRoomTemplateEditDialog *)__RTDynamicCast(
                                      inptr: v5,
                                      VfDelta: 0,
                                      SrcType: &vgui::Panel `RTTI Type Descriptor',
                                      TargetType: &CRoomTemplateEditDialog `RTTI Type Descriptor',
                                      isReference: 0);
    if ( v6 != nullptr )
    {
      if ( code == MOUSE_RIGHT )
        CRoomTemplateEditDialog::EditExit(
          this: v6,
          iXPos: this->m_iTileX,
          iYPos: this->m_iTileY,
          dir: this->m_ExitDirection);
      else
        CRoomTemplateEditDialog::ToggleExit(
          this: v6,
          iXPos: this->m_iTileX,
          iYPos: this->m_iTileY,
          dir: this->m_ExitDirection);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DE00
// Name: public: virtual void CToggleExitButton::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CToggleExitButton::OnThink(CToggleExitButton *this@<ecx>, int a2@<edi>)
{
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // edi
  int v8; // ecx
  _DWORD **v9; // edx
  _DWORD *v10; // eax
  unsigned int v12; // [esp+4h] [ebp-4h]

  v3 = this->GetParent(this);
  if ( __RTDynamicCast(
         inptr: v3,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &CToggleExitsPanel `RTTI Type Descriptor',
         isReference: 0) != nullptr )
  {
    v4 = this->GetParent(this);
    v5 = *((_DWORD *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &vgui::Panel `RTTI Type Descriptor',
                       TargetType: &CToggleExitsPanel `RTTI Type Descriptor',
                       isReference: 0)
         + 89);
    if ( v5 != 0 )
    {
      v6 = *(_DWORD *)(v5 + 336);
      if ( v6 != 0 )
      {
        v7 = *(_DWORD *)(v6 + 12);
        v8 = 0;
        if ( v7 <= 0 )
        {
LABEL_11:
          v12 = -2143272896;
          if ( ((unsigned __int8 (__thiscall *)(CToggleExitButton *, int))this->IsCursorOver)(a1: this, a2) == 0 )
            v12 = 0x80000000;
          ((void (__thiscall *)(CToggleExitButton *, unsigned int))this->SetBgColor)(a1: this, a2: v12);
        }
        else
        {
          v9 = *(_DWORD ***)v6;
          while ( 1 )
          {
            v10 = *v9;
            if ( *v9 != nullptr && *v10 == this->m_iTileX && v10[1] == this->m_iTileY && v10[2] == this->m_ExitDirection )
              break;
            ++v8;
            ++v9;
            if ( v8 >= v7 )
              goto LABEL_11;
          }
          if ( ((unsigned __int8 (__thiscall *)(CToggleExitButton *, int))this->IsCursorOver)(a1: this, a2) != 0 )
            ((void (__thiscall *)(CToggleExitButton *, int))this->SetBgColor)(a1: this, a2: -49088);
          else
            ((void (__thiscall *)(CToggleExitButton *, int))this->SetBgColor)(a1: this, a2: -65536);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DF10
// Name: public: CToggleExitsPanel::CToggleExitsPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CToggleExitsPanel *__thiscall CToggleExitsPanel::CToggleExitsPanel(
        CToggleExitsPanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (CToggleExitsPanel_vtbl *)&CToggleExitsPanel::`vftable';
  if ( `CToggleExitsPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CToggleExitsPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CToggleExitsPanel");
    v4->pfnClassName = CToggleExitsPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CToggleExitsPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CToggleExitsPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CToggleExitsPanel");
    v5->pfnClassName = CToggleExitsPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CToggleExitsPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CToggleExitsPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CToggleExitsPanel");
    v6->pfnClassName = CToggleExitsPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_ExitButtons.m_Memory.m_pMemory = nullptr;
  this->m_ExitButtons.m_Memory.m_nAllocationCount = 0;
  this->m_ExitButtons.m_Memory.m_nGrowSize = 0;
  this->m_ExitButtons.m_Size = 0;
  this->m_ExitButtons.m_pElements = nullptr;
  this->m_pRoomTemplatePanel = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002E000
// Name: public: virtual struct vgui::PanelMessageMap __near * CToggleExitsPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CToggleExitsPanel::GetMessageMap(CToggleExitsPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CToggleExitsPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CToggleExitsPanel::GetMessageMap'::`2'::s_pMap;
  `CToggleExitsPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CToggleExitsPanel");
  `CToggleExitsPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002E030
// Name: public: virtual struct PanelAnimationMap __near * CToggleExitsPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CToggleExitsPanel::GetAnimMap(CToggleExitsPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CToggleExitsPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1002E040
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CToggleExitsPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CToggleExitsPanel::GetKBMap(CToggleExitsPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CToggleExitsPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CToggleExitsPanel::GetKBMap'::`2'::s_pMap;
  `CToggleExitsPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CToggleExitsPanel");
  `CToggleExitsPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002E070
// Name: public: void CToggleExitsPanel::SetRoomTemplatePanel(class CRoomTemplatePanel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CToggleExitsPanel::SetRoomTemplatePanel(
        CToggleExitsPanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        CRoomTemplatePanel *pPanel,
        bool bForceUpdate)
{
  CToggleExitsPanel *v5; // edi
  const CRoomTemplate *m_pRoomTemplate; // ebx
  int v7; // esi
  CToggleExitButton *v8; // ecx
  CToggleExitButton *v9; // ecx
  CUtlMemory<vgui::TreeNode *,int> *p_m_ExitButtons; // esi
  CToggleExitButton *v11; // eax
  CToggleExitButton *v12; // ebx
  CToggleExitButton_vtbl *v13; // edx
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v16; // ecx
  int v17; // eax
  CToggleExitButton **v18; // edi
  CToggleExitButton *v19; // eax
  CToggleExitButton *v20; // edi
  CToggleExitButton_vtbl *v21; // edx
  int v22; // eax
  void (__thiscall *InvalidateLayout)(vgui::Panel *, bool, bool); // eax
  vgui::TreeNode **v24; // ebx
  int v25; // eax
  vgui::TreeNode **v26; // ecx
  int v27; // eax
  CToggleExitButton **v28; // ebx
  CToggleExitButton *v29; // eax
  CToggleExitButton *v30; // edi
  CToggleExitButton_vtbl *v31; // edx
  void (__thiscall *v32)(vgui::Panel *, bool, bool); // eax
  vgui::TreeNode **v33; // ebx
  int v34; // eax
  vgui::TreeNode **v35; // ecx
  int v36; // eax
  CToggleExitButton **v37; // ebx
  CToggleExitButton *v38; // eax
  CToggleExitButton *v39; // edi
  CToggleExitButton_vtbl *v40; // eax
  void (__thiscall *v41)(vgui::Panel *, bool, bool); // edx
  vgui::TreeNode **v42; // ebx
  int v43; // eax
  vgui::TreeNode **v44; // ecx
  int v45; // eax
  CToggleExitButton **v46; // ebx
  int y; // [esp+10h] [ebp+8h]
  int ya; // [esp+10h] [ebp+8h]
  const CRoomTemplate *pRoomTemplate; // [esp+14h] [ebp+Ch]

  v5 = this;
  if ( this->m_pRoomTemplatePanel != pPanel || bForceUpdate )
  {
    this->m_pRoomTemplatePanel = pPanel;
    if ( pPanel != nullptr )
    {
      m_pRoomTemplate = pPanel->m_pRoomTemplate;
      pRoomTemplate = m_pRoomTemplate;
      if ( m_pRoomTemplate != nullptr )
      {
        v7 = 0;
        if ( this->m_ExitButtons.m_Size > 0 )
        {
          do
          {
            v8 = v5->m_ExitButtons.m_Memory.m_pMemory[v7];
            v8->MarkForDeletion(this: v8);
            v9 = v5->m_ExitButtons.m_Memory.m_pMemory[v7];
            v9->SetVisible(this: v9, a2: false);
            ++v7;
          }
          while ( v7 < v5->m_ExitButtons.m_Size );
        }
        p_m_ExitButtons = (CUtlMemory<vgui::TreeNode *,int> *)&v5->m_ExitButtons;
        v5->m_ExitButtons.m_Size = 0;
        if ( v5->m_ExitButtons.m_Memory.m_nGrowSize >= 0 )
        {
          if ( p_m_ExitButtons->m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_ExitButtons->m_pMemory);
            p_m_ExitButtons->m_pMemory = nullptr;
          }
          v5->m_ExitButtons.m_Memory.m_nAllocationCount = 0;
        }
        v5->m_ExitButtons.m_pElements = v5->m_ExitButtons.m_Memory.m_pMemory;
        y = 0;
        if ( m_pRoomTemplate->m_nTilesX > 0 )
        {
          do
          {
            v11 = (CToggleExitButton *)operator new(nSize: 0x15Cu);
            if ( v11 != nullptr )
              v12 = CToggleExitButton::CToggleExitButton(this: v11, parent: v5, name: "ToggleExitButtonN");
            else
              v12 = nullptr;
            v13 = v12->__vftable;
            v12->m_iTileX = y;
            v12->m_iTileY = 0;
            v12->m_ExitDirection = EXITDIR_BEGIN;
            ((void (__thiscall *)(CToggleExitButton *, _DWORD, _DWORD, int, int))v13->InvalidateLayout)(
              a1: v12,
              a2: 0,
              a3: 0,
              a4: a3,
              a5: a2);
            m_pMemory = p_m_ExitButtons[1].m_pMemory;
            m_nAllocationCount = p_m_ExitButtons->m_nAllocationCount;
            if ( (int)m_pMemory + 1 > m_nAllocationCount )
              CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
                this: p_m_ExitButtons,
                num: (int)m_pMemory - m_nAllocationCount + 1);
            ++p_m_ExitButtons[1].m_pMemory;
            v16 = p_m_ExitButtons->m_pMemory;
            v17 = (char *)p_m_ExitButtons[1].m_pMemory - (char *)m_pMemory - 1;
            p_m_ExitButtons[1].m_nAllocationCount = (int)p_m_ExitButtons->m_pMemory;
            if ( v17 > 0 )
              _V_memmove(dest: &v16[(_DWORD)m_pMemory + 1], src: &v16[(_DWORD)m_pMemory], count: 4 * v17);
            v18 = (CToggleExitButton **)&p_m_ExitButtons->m_pMemory[(_DWORD)m_pMemory];
            if ( v18 != nullptr )
              *v18 = v12;
            v19 = (CToggleExitButton *)operator new(nSize: 0x15Cu);
            if ( v19 != nullptr )
              v20 = CToggleExitButton::CToggleExitButton(this: v19, parent: this, name: "ToggleExitButtonS");
            else
              v20 = nullptr;
            v21 = v20->__vftable;
            v22 = pRoomTemplate->m_nTilesY - 1;
            a2 = 0;
            v20->m_iTileX = y;
            v20->m_iTileY = v22;
            InvalidateLayout = v21->InvalidateLayout;
            a3 = 0;
            v20->m_ExitDirection = EXITDIR_SOUTH;
            ((void (__thiscall *)(CToggleExitButton *))InvalidateLayout)(a1: v20);
            v24 = p_m_ExitButtons[1].m_pMemory;
            v25 = p_m_ExitButtons->m_nAllocationCount;
            if ( (int)v24 + 1 > v25 )
              CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
                this: p_m_ExitButtons,
                num: (int)v24 - v25 + 1);
            ++p_m_ExitButtons[1].m_pMemory;
            v26 = p_m_ExitButtons->m_pMemory;
            v27 = (char *)p_m_ExitButtons[1].m_pMemory - (char *)v24 - 1;
            p_m_ExitButtons[1].m_nAllocationCount = (int)p_m_ExitButtons->m_pMemory;
            if ( v27 > 0 )
              _V_memmove(dest: &v26[(_DWORD)v24 + 1], src: &v26[(_DWORD)v24], count: 4 * v27);
            v28 = (CToggleExitButton **)&p_m_ExitButtons->m_pMemory[(_DWORD)v24];
            if ( v28 != nullptr )
              *v28 = v20;
            v5 = this;
            ++y;
          }
          while ( y < pRoomTemplate->m_nTilesX );
          m_pRoomTemplate = pRoomTemplate;
        }
        ya = 0;
        if ( m_pRoomTemplate->m_nTilesY > 0 )
        {
          do
          {
            v29 = (CToggleExitButton *)operator new(nSize: 0x15Cu);
            if ( v29 != nullptr )
              v30 = CToggleExitButton::CToggleExitButton(this: v29, parent: v5, name: "ToggleExitButtonW");
            else
              v30 = nullptr;
            v31 = v30->__vftable;
            v30->m_iTileY = ya;
            v32 = v31->InvalidateLayout;
            v30->m_iTileX = 0;
            v30->m_ExitDirection = EXITDIR_WEST;
            ((void (__thiscall *)(CToggleExitButton *, _DWORD, _DWORD, int, int))v32)(
              a1: v30,
              a2: 0,
              a3: 0,
              a4: a3,
              a5: a2);
            v33 = p_m_ExitButtons[1].m_pMemory;
            v34 = p_m_ExitButtons->m_nAllocationCount;
            if ( (int)v33 + 1 > v34 )
              CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
                this: p_m_ExitButtons,
                num: (int)v33 - v34 + 1);
            ++p_m_ExitButtons[1].m_pMemory;
            v35 = p_m_ExitButtons->m_pMemory;
            v36 = (char *)p_m_ExitButtons[1].m_pMemory - (char *)v33 - 1;
            p_m_ExitButtons[1].m_nAllocationCount = (int)p_m_ExitButtons->m_pMemory;
            if ( v36 > 0 )
              _V_memmove(dest: &v35[(_DWORD)v33 + 1], src: &v35[(_DWORD)v33], count: 4 * v36);
            v37 = (CToggleExitButton **)&p_m_ExitButtons->m_pMemory[(_DWORD)v33];
            if ( v37 != nullptr )
              *v37 = v30;
            v38 = (CToggleExitButton *)operator new(nSize: 0x15Cu);
            if ( v38 != nullptr )
              v39 = CToggleExitButton::CToggleExitButton(this: v38, parent: this, name: "ToggleExitButtonE");
            else
              v39 = nullptr;
            v40 = v39->__vftable;
            a2 = 0;
            v39->m_iTileX = pRoomTemplate->m_nTilesX - 1;
            v39->m_iTileY = ya;
            v41 = v40->InvalidateLayout;
            a3 = 0;
            v39->m_ExitDirection = EXITDIR_EAST;
            ((void (__thiscall *)(CToggleExitButton *))v41)(a1: v39);
            v42 = p_m_ExitButtons[1].m_pMemory;
            v43 = p_m_ExitButtons->m_nAllocationCount;
            if ( (int)v42 + 1 > v43 )
              CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
                this: p_m_ExitButtons,
                num: (int)v42 - v43 + 1);
            ++p_m_ExitButtons[1].m_pMemory;
            v44 = p_m_ExitButtons->m_pMemory;
            v45 = (char *)p_m_ExitButtons[1].m_pMemory - (char *)v42 - 1;
            p_m_ExitButtons[1].m_nAllocationCount = (int)p_m_ExitButtons->m_pMemory;
            if ( v45 > 0 )
              _V_memmove(dest: &v44[(_DWORD)v42 + 1], src: &v44[(_DWORD)v42], count: 4 * v45);
            v46 = (CToggleExitButton **)&p_m_ExitButtons->m_pMemory[(_DWORD)v42];
            if ( v46 != nullptr )
              *v46 = v39;
            v5 = this;
            ++ya;
          }
          while ( ya < pRoomTemplate->m_nTilesY );
        }
        v5->InvalidateLayout(this: v5, a2: false, a3: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10059E40
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<char const __near *,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<void *,unsigned short> *m_pMemory; // edx
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
        m_nAllocationCount = 3;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<void *,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                    this: _g_pMemAlloc,
                                                                    a2: m_pMemory,
                                                                    a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<void *,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062B40
// Name: public: void CUtlMemory<class CMapDisplacement,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CMapDisplacement,int>::Grow(
        CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::AnimationController::ActiveAnimation_t *m_pMemory; // edx

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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::AnimationController::ActiveAnimation_t *)_g_pMemAlloc->Realloc_2(
                                                                          this: _g_pMemAlloc,
                                                                          a2: m_pMemory,
                                                                          a3: 68 * m_nAllocationCount);
    else
      this->m_pMemory = (vgui::AnimationController::ActiveAnimation_t *)_g_pMemAlloc->Alloc_2(
                                                                          this: _g_pMemAlloc,
                                                                          a2: 68 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062BF0
// Name: public: void CUtlMemory<struct MapBrushSide_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<MapBrushSide_t,int>::Grow(CUtlMemory<MapBrushSide_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  MapBrushSide_t *m_pMemory; // edx
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
    v7 = 44 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (MapBrushSide_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (MapBrushSide_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062C80
// Name: public: void CUtlMemory<struct MapTextureData_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<MapTextureData_t,int>::Grow(CUtlMemory<MapTextureData_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  MapTextureData_t *m_pMemory; // edx
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
    v7 = 148 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (MapTextureData_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (MapTextureData_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068070
// Name: public: void CUtlMemory<struct dface_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<dface_t,int>::Grow(CUtlMemory<dface_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  dface_t *m_pMemory; // edx

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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (dface_t *)_g_pMemAlloc->Realloc_2(
                                     this: _g_pMemAlloc,
                                     a2: m_pMemory,
                                     a3: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (dface_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100681C0
// Name: public: void CUtlMemory<struct EnumEntry_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<EnumEntry_t,int>::Grow(CUtlMemory<vgui::PropertySheet::Page_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::PropertySheet::Page_t *m_pMemory; // edx
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
        m_nAllocationCount = 4;
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
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::PropertySheet::Page_t *)_g_pMemAlloc->Realloc_2(
                                                         this: _g_pMemAlloc,
                                                         a2: m_pMemory,
                                                         a3: v7);
    else
      this->m_pMemory = (vgui::PropertySheet::Page_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068260
// Name: public: void CUtlMemory<struct StaticPropLump_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<StaticPropLump_t,int>::Grow(CUtlMemory<MapTextureInfo_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  MapTextureInfo_t *m_pMemory; // edx
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
    v7 = 72 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (MapTextureInfo_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (MapTextureInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068300
// Name: public: void CUtlMemory<struct dmodel_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<dmodel_t,int>::Grow(CUtlMemory<vgui::AnimationController::AnimCommand_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::AnimationController::AnimCommand_t *m_pMemory; // edx
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
    v7 = 48 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::AnimationController::AnimCommand_t *)_g_pMemAlloc->Realloc_2(
                                                                      this: _g_pMemAlloc,
                                                                      a2: m_pMemory,
                                                                      a3: v7);
    else
      this->m_pMemory = (vgui::AnimationController::AnimCommand_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100683A0
// Name: public: void CUtlMemory<struct MapBrushTexture_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<MapBrushTexture_t,int>::Grow(CUtlMemory<MapBrushTexture_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  MapBrushTexture_t *m_pMemory; // edx
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
    v7 = 176 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (MapBrushTexture_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (MapBrushTexture_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068440
// Name: public: void CUtlMemory<class CRoomCandidate,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CRoomCandidate,int>::Grow(
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
// Address: 0x100684E0
// Name: public: void CUtlMemory<class CDispMultiBlend,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CDispMultiBlend,int>::Grow(CUtlMemory<CDispMultiBlend,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CDispMultiBlend *m_pMemory; // edx
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
    v7 = 80 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CDispMultiBlend *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CDispMultiBlend *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068580
// Name: public: void CUtlMemory<struct StaticPropDictLump_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<StaticPropDictLump_t,int>::Grow(CUtlMemory<StaticPropDictLump_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  StaticPropDictLump_t *m_pMemory; // edx
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
    v7 = m_nAllocationCount << 7;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (StaticPropDictLump_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (StaticPropDictLump_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F5F30
// Name: public: void CUtlMemory<struct FGDMatExlcusions_s,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<FGDMatExlcusions_s,int>::Grow(CUtlMemory<FGDMatExlcusions_s,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  FGDMatExlcusions_s *m_pMemory; // edx
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
    v7 = 261 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (FGDMatExlcusions_s *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (FGDMatExlcusions_s *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F5FD0
// Name: public: void CUtlMemory<struct FGDAutoVisGroups_s,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<FGDAutoVisGroups_s,int>::Grow(CUtlMemory<FGDAutoVisGroups_s,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  FGDAutoVisGroups_s *m_pMemory; // edx
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
    v7 = 280 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (FGDAutoVisGroups_s *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (FGDAutoVisGroups_s *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}
