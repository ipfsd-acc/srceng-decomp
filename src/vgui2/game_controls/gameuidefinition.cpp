// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/game_controls/gameuidefinition.cpp
// Functions: 31
// ============================================================

#include "vgui2\game_controls\gameuidefinition.h"

//------------------------------------------------------------------------------
// Address: 0x004187B0
// Name: public: char const __near * CDmxAttribute::GetValueString(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxAttribute::GetValueString(CDmxAttribute *this)
{
  if ( this->m_Type == AT_STRING )
    return CUtlString::operator char const *(this: (CUtlString *)this->m_pData);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x004187D0
// Name: public: void CGameUIDefinition::UpdateGeometry(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIDefinition::UpdateGeometry(CGameUIDefinition *this)
{
  this->m_pGameStage->UpdateGeometry(this: this->m_pGameStage);
}

//------------------------------------------------------------------------------
// Address: 0x004187E0
// Name: public: void CGameUIDefinition::UpdateRenderTransforms(struct Rect_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIDefinition::UpdateRenderTransforms(CGameUIDefinition *this, const Rect_t *viewport)
{
  CGameStage::UpdateRenderTransforms(this: this->m_pGameStage, viewport);
}

//------------------------------------------------------------------------------
// Address: 0x004187F0
// Name: public: void CGameUIDefinition::BuildScopedGraphicName(class CUtlString __near &,class CGameGraphic __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIDefinition::BuildScopedGraphicName(
        CGameUIDefinition *this,
        CUtlString *name,
        CGameGraphic *pGraphic)
{
  const char *v4; // eax

  if ( !pGraphic->m_pGroup->IsStageGroup(this: pGraphic->m_pGroup) )
    CGameUIDefinition::BuildScopedGraphicName(this, name, pGraphic: pGraphic->m_pGroup);
  v4 = CUtlString::operator char const *(this: &pGraphic->m_pName);
  CUtlString::operator+=(this: name, rhs: v4);
  if ( pGraphic->IsGroup(this: pGraphic) )
    CUtlString::operator+=(this: name, rhs: ":");
}

//------------------------------------------------------------------------------
// Address: 0x00418850
// Name: public: virtual void CGameUIDefinition::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIDefinition::SetVisible(CGameUIDefinition *this, bool bVisible)
{
  this->m_bVisible = bVisible;
  g_pGameUISystemMgrImpl->m_bForceFocusUpdate = true;
}

//------------------------------------------------------------------------------
// Address: 0x00418870
// Name: public: void CGameUIDefinition::UpdateAspectRatio(struct Rect_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIDefinition::UpdateAspectRatio(CGameUIDefinition *this, const Rect_t *viewport)
{
  CGameStage::UpdateAspectRatio(this: this->m_pGameStage, viewport);
}

//------------------------------------------------------------------------------
// Address: 0x00418880
// Name: public: void CGameUIDefinition::SetStageSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIDefinition::SetStageSize(CGameUIDefinition *this, int nWide, int nTall)
{
  CGameStage::SetStageSize(this: this->m_pGameStage, nWide, nTall);
}

//------------------------------------------------------------------------------
// Address: 0x00418890
// Name: public: void CGameUIDefinition::GetStageSize(class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIDefinition::GetStageSize(CGameUIDefinition *this, Vector2D *stageSize)
{
  *stageSize = this->m_pGameStage->m_StageSize;
}

//------------------------------------------------------------------------------
// Address: 0x004188B0
// Name: public: void CGameUIDefinition::GetMaintainAspectRatioStageSize(class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIDefinition::GetMaintainAspectRatioStageSize(CGameUIDefinition *this, Vector2D *stageSize)
{
  *stageSize = this->m_pGameStage->m_MaintainAspectRatioStageSize;
}

//------------------------------------------------------------------------------
// Address: 0x004188D0
// Name: public: void CGameUIDefinition::GetRenderData(class CUtlVector<struct LayerRenderLists_t,class CUtlMemory<struct LayerRenderLists_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIDefinition::GetRenderData(
        CGameUIDefinition *this,
        CUtlVector<LayerRenderLists_t,CUtlMemory<LayerRenderLists_t,int> > *renderLists)
{
  int m_Size; // ebx
  int i; // edi

  m_Size = this->m_Layers.m_Size;
  for ( i = 0; i < m_Size; ++i )
    CGameLayer::UpdateRenderData(
      this: this->m_Layers.m_Memory.m_pMemory[i],
      gameUIDef: this,
      parentColor: this->m_pGameStage->m_Geometry.m_Color,
      renderLists);
}

//------------------------------------------------------------------------------
// Address: 0x00418910
// Name: public: class CGameGraphic __near * CGameUIDefinition::GetGraphic(int,int)
// Source: json
//------------------------------------------------------------------------------
CGameGraphic *__thiscall CGameUIDefinition::GetGraphic(CGameUIDefinition *this, int x, int y)
{
  int v4; // esi
  CGameGraphic *result; // eax

  v4 = this->m_Layers.m_Size - 1;
  if ( v4 < 0 )
    return nullptr;
  while ( 1 )
  {
    result = CGameLayer::GetGraphic(this: this->m_Layers.m_Memory.m_pMemory[v4], x, y);
    if ( result != nullptr )
      break;
    if ( --v4 < 0 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00418950
// Name: public: class CHitArea __near * CGameUIDefinition::GetMouseFocus(int,int)
// Source: json
//------------------------------------------------------------------------------
CHitArea *__thiscall CGameUIDefinition::GetMouseFocus(CGameUIDefinition *this, int x, int y)
{
  int v4; // esi
  CHitArea *result; // eax

  if ( !this->m_bVisible )
    return nullptr;
  if ( !this->m_bCanAcceptInput )
    return nullptr;
  v4 = this->m_Layers.m_Size - 1;
  if ( v4 < 0 )
    return nullptr;
  while ( 1 )
  {
    result = (CHitArea *)CGameLayer::GetMouseFocus(this: this->m_Layers.m_Memory.m_pMemory[v4], x, y);
    if ( result != nullptr )
      break;
    if ( --v4 < 0 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004189A0
// Name: public: class CHitArea __near * CGameUIDefinition::GetNextFocus(class CHitArea __near *)
// Source: json
//------------------------------------------------------------------------------
CHitArea *__thiscall CGameUIDefinition::GetNextFocus(CGameUIDefinition *this, CHitArea *pCurrentGraphic)
{
  CHitArea *result; // eax
  int m_Size; // ebx
  int v5; // esi
  int v6; // esi
  bool v7; // [esp+7h] [ebp-1h] BYREF

  if ( !this->m_bVisible || !this->m_bCanAcceptInput )
    return nullptr;
  v7 = pCurrentGraphic == nullptr;
  m_Size = this->m_Layers.m_Size;
  v5 = 0;
  if ( m_Size <= 0 )
  {
LABEL_7:
    v6 = 0;
    v7 = true;
    if ( m_Size <= 0 )
    {
      return nullptr;
    }
    else
    {
      while ( 1 )
      {
        result = (CHitArea *)CGameLayer::GetNextFocus(
                               this: this->m_Layers.m_Memory.m_pMemory[v6],
                               bGetNext: &v7,
                               pCurrentGraphic);
        if ( result != nullptr )
          break;
        if ( ++v6 >= m_Size )
          return nullptr;
      }
    }
  }
  else
  {
    while ( 1 )
    {
      result = (CHitArea *)CGameLayer::GetNextFocus(
                             this: this->m_Layers.m_Memory.m_pMemory[v5],
                             bGetNext: &v7,
                             pCurrentGraphic);
      if ( result != nullptr )
        break;
      if ( ++v5 >= m_Size )
        goto LABEL_7;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00418A30
// Name: public: void CGameUIDefinition::StartPlaying(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIDefinition::StartPlaying(CGameUIDefinition *this)
{
  int m_Size; // ebx
  int i; // esi

  this->m_pGameStage->StartPlaying(this: this->m_pGameStage);
  m_Size = this->m_Layers.m_Size;
  for ( i = 0; i < m_Size; ++i )
    CGameLayer::StartPlaying(this: this->m_Layers.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x00418A70
// Name: public: void CGameUIDefinition::StopPlaying(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIDefinition::StopPlaying(CGameUIDefinition *this)
{
  int m_Size; // ebx
  int i; // esi

  this->m_pGameStage->StopPlaying(this: this->m_pGameStage);
  m_Size = this->m_Layers.m_Size;
  for ( i = 0; i < m_Size; ++i )
    CGameLayer::StopPlaying(this: this->m_Layers.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x00418AB0
// Name: public: void CGameUIDefinition::AdvanceState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIDefinition::AdvanceState(CGameUIDefinition *this)
{
  int m_Size; // ebx
  int i; // esi

  this->m_pGameStage->AdvanceState(this: this->m_pGameStage);
  m_Size = this->m_Layers.m_Size;
  for ( i = 0; i < m_Size; ++i )
    CGameLayer::AdvanceState(this: this->m_Layers.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x00418AF0
// Name: public: void CGameUIDefinition::InitAnims(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIDefinition::InitAnims(CGameUIDefinition *this)
{
  int m_Size; // ebx
  int i; // esi

  this->m_pGameStage->SetState_2(this: this->m_pGameStage, a2: "default");
  m_Size = this->m_Layers.m_Size;
  for ( i = 0; i < m_Size; ++i )
    CGameLayer::InitAnims(this: this->m_Layers.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x00418B30
// Name: public: class CGameGraphic __near * CGameUIDefinition::GraphicExists(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CGameStage *__thiscall CGameUIDefinition::GraphicExists(CGameUIDefinition *this, const char *pName)
{
  CGameStage *m_pGameStage; // ecx
  int v5; // esi
  int v6; // edi
  int v7; // eax
  CSplitString nameparts; // [esp+4h] [ebp-1Ch] BYREF

  if ( CGameGraphic::IsGraphicNamed(this: this->m_pGameStage, pName) )
    return this->m_pGameStage;
  CSplitString::CSplitString(
    this: (CSplitString *)&nameparts.m_Memory.m_nAllocationCount,
    pString: pName,
    pSeparator: ":");
  m_pGameStage = this->m_pGameStage;
  v5 = 0;
  v6 = 0;
  if ( (int)nameparts.m_pElements <= 0 )
  {
LABEL_6:
    CSplitString::~CSplitString(this: (CSplitString *)&nameparts.m_Memory.m_nAllocationCount);
    return (CGameStage *)v5;
  }
  else
  {
    while ( 1 )
    {
      v7 = (int)m_pGameStage->FindGraphicByName(
                  this: m_pGameStage,
                  a2: *(const char **)(nameparts.m_Memory.m_nAllocationCount + 4 * v6));
      v5 = v7;
      if ( v7 == 0 )
        break;
      ++v6;
      m_pGameStage = (CGameStage *)v7;
      if ( v6 >= (int)nameparts.m_pElements )
        goto LABEL_6;
    }
    CSplitString::~CSplitString(this: (CSplitString *)&nameparts.m_Memory.m_nAllocationCount);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418BC0
// Name: public: class CGameGraphic __near * CGameUIDefinition::FindGraphicByName(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CGameStage *__thiscall CGameUIDefinition::FindGraphicByName(CGameUIDefinition *this, const char *pName)
{
  CGameStage *result; // eax

  result = CGameUIDefinition::GraphicExists(this, pName);
  if ( result == nullptr )
  {
    _Warning(a1: "FindGraphicByName: Unable to find graphic named %s\n", pName);
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00418BF0
// Name: public: bool CGameUIDefinition::HasGraphic(class CGameGraphic __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameUIDefinition::HasGraphic(CGameUIDefinition *this, CGameGraphic *pGraphic)
{
  int v3; // esi

  v3 = 0;
  if ( this->m_Layers.m_Size <= 0 )
    return 0;
  while ( !CGameLayer::HasGraphic(this: this->m_Layers.m_Memory.m_pMemory[v3], pGraphic) )
  {
    if ( ++v3 >= this->m_Layers.m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00419060
// Name: public: void CGameUIDefinition::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIDefinition::Shutdown(CGameUIDefinition *this)
{
  int m_Size; // ebx
  int i; // edi
  CGraphicGroup **m_pMemory; // eax
  bool v5; // zf
  CGraphicGroup **v6; // eax
  CGraphicGroup *v7; // eax
  int v8; // ebp
  int j; // edi
  CGameLayer **v10; // eax
  CGameLayer *v11; // ebx
  int v12; // edi
  int v13; // ebp
  CGameUIScript **v14; // eax
  CGameUIScript *v15; // ebx

  m_Size = this->m_Groups.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    m_pMemory = this->m_Groups.m_Memory.m_pMemory;
    v5 = m_pMemory[i] == nullptr;
    v6 = &m_pMemory[i];
    if ( !v5 )
    {
      v7 = *v6;
      if ( v7 != nullptr )
        ((void (__thiscall *)(CGraphicGroup *, int))v7->dtr_CGameGraphic)(a1: v7, a2: 1);
      this->m_Groups.m_Memory.m_pMemory[i] = nullptr;
    }
  }
  this->m_Groups.m_Size = 0;
  v8 = this->m_Layers.m_Size;
  for ( j = 0; j < v8; ++j )
  {
    CGameLayer::Shutdown(this: this->m_Layers.m_Memory.m_pMemory[j]);
    v10 = this->m_Layers.m_Memory.m_pMemory;
    v11 = v10[j];
    if ( v11 != nullptr )
    {
      CGameLayer::~CGameLayer(this: v10[j]);
      free(pMem: v11);
    }
    this->m_Layers.m_Memory.m_pMemory[j] = nullptr;
  }
  v12 = 0;
  this->m_Layers.m_Size = 0;
  v13 = this->m_Scripts.m_Size;
  if ( v13 > 0 )
  {
    do
    {
      CGameUIScript::Shutdown(this: this->m_Scripts.m_Memory.m_pMemory[v12]);
      v14 = this->m_Scripts.m_Memory.m_pMemory;
      v15 = v14[v12];
      if ( v15 != nullptr )
      {
        CGameUIScript::~CGameUIScript(this: v14[v12]);
        free(pMem: v15);
      }
      this->m_Scripts.m_Memory.m_pMemory[v12++] = nullptr;
    }
    while ( v12 < v13 );
  }
  this->m_Scripts.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00419140
// Name: public: bool CGameUIDefinition::ExecuteScript(class KeyValues __near *,class KeyValues __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameUIDefinition::ExecuteScript(CGameUIDefinition *this, KeyValues *args, KeyValues **ppResult)
{
  const char *Name; // ebp
  const char *v6; // eax
  CGameStage *GraphicByName; // esi
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  const char *String; // eax
  const char *v11; // eax
  const char *v12; // eax
  bool v13; // bl
  CGameUIScript **m_pMemory; // eax
  const char *v15; // [esp-4h] [ebp-10h]

  Name = KeyValues::GetName(this: args);
  if ( _V_stricmp(s1: "AdvanceState", s2: Name) != 0 )
  {
    if ( _V_stricmp(s1: "StartPlaying", s2: Name) != 0 )
    {
      if ( _V_stricmp(s1: "StopPlaying", s2: Name) != 0 )
      {
        if ( _V_stricmp(s1: "ShowCursorCoords", s2: Name) != 0 )
        {
          if ( _V_stricmp(s1: "ShowGraphicName", s2: Name) != 0 )
          {
            if ( _V_stricmp(s1: "FindGraphic", s2: Name) != 0 )
            {
              if ( _V_stricmp(s1: "SetInput", s2: Name) != 0 )
              {
                if ( _V_stricmp(s1: "InitAnims", s2: Name) != 0 )
                {
                  if ( _V_stricmp(s1: "Sound", s2: Name) == 0 )
                  {
                    if ( KeyValues::GetInt(this: args, keyName: "play", defaultValue: 1) != 0 )
                    {
                      String = KeyValues::GetString(this: args, keyName: "sound", defaultValue: defaultValue);
                      CGameUISystemMgr::PlayMenuSound(this: g_pGameUISystemMgrImpl, pSoundName: String);
                    }
                    else
                    {
                      v11 = KeyValues::GetString(this: args, keyName: "sound", defaultValue: defaultValue);
                      CGameUISystemMgr::StopMenuSound(this: g_pGameUISystemMgrImpl, pSoundName: v11);
                    }
                  }
                  if ( _V_stricmp(s1: "setdynamictexture", s2: Name) == 0 )
                  {
                    v15 = KeyValues::GetString(this: args, keyName: "texturename", defaultValue: defaultValue);
                    v12 = KeyValues::GetString(this: args, keyName: "aliasname", defaultValue: defaultValue);
                    CGameUISystemMgr::LoadImageAliasTexture(
                      this: g_pGameUISystemMgrImpl,
                      pAlias: v12,
                      pBaseTextureName: v15);
                  }
                  v13 = false;
                  if ( this->m_Scripts.m_Size != 0 )
                  {
                    m_pMemory = this->m_Scripts.m_Memory.m_pMemory;
                    if ( *m_pMemory != nullptr )
                    {
                      (*m_pMemory)->m_IsActive = true;
                      v13 = CGameUIScript::Execute(this: *this->m_Scripts.m_Memory.m_pMemory, pData: args, ppResult);
                      (*this->m_Scripts.m_Memory.m_pMemory)->m_IsActive = false;
                      if ( v13 )
                        return v13;
                    }
                  }
                  if ( _V_stricmp(s1: Name, s2: "OnExit") != 0 )
                  {
                    return v13;
                  }
                  else
                  {
                    this->SetVisible(this, a2: false);
                    return 1;
                  }
                }
                else
                {
                  CGameUIDefinition::InitAnims(this);
                  return 1;
                }
              }
              else
              {
                this->m_bCanAcceptInput = KeyValues::GetInt(this: args, keyName: "input", defaultValue: 1) != 0;
                return 1;
              }
            }
            else
            {
              v6 = KeyValues::GetString(this: args, keyName: "graphic", defaultValue: defaultValue);
              GraphicByName = CGameUIDefinition::FindGraphicByName(this, pName: v6);
              if ( GraphicByName != nullptr && ppResult != nullptr )
              {
                v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
                if ( v8 != nullptr )
                  v9 = KeyValues::KeyValues(this: v8, setName: defaultValue);
                else
                  v9 = nullptr;
                *ppResult = v9;
                KeyValues::SetInt(this: v9, keyName: "graphichandle", value: GraphicByName->m_iScriptHandle);
              }
              return 1;
            }
          }
          else
          {
            CGameUISystemMgr::ShowGraphicName(this: g_pGameUISystemMgrImpl);
            return 1;
          }
        }
        else
        {
          CGameUISystemMgr::ShowCursorCoords(this: g_pGameUISystemMgrImpl);
          return 1;
        }
      }
      else
      {
        CGameUIDefinition::StopPlaying(this);
        return 1;
      }
    }
    else
    {
      CGameUIDefinition::StartPlaying(this);
      return 1;
    }
  }
  else
  {
    CGameUIDefinition::AdvanceState(this);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004193C0
// Name: public: bool CGameUIDefinition::AddGraphicToLayer(class CGameGraphic __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameUIDefinition::AddGraphicToLayer(CGameUIDefinition *this, CGameGraphic *pGraphic, int nLayerType)
{
  int v4; // eax
  CGameLayer **m_pMemory; // esi
  CGameLayer **i; // ecx

  pGraphic->m_pGroup = this->m_pGameStage;
  CGraphicGroup::AddToGroup(this: this->m_pGameStage, pGraphic);
  v4 = this->m_Layers.m_Size - 1;
  if ( v4 < 0 )
    return 0;
  m_pMemory = this->m_Layers.m_Memory.m_pMemory;
  for ( i = &m_pMemory[v4]; (*i)->m_LayerType != nLayerType; --i )
  {
    if ( --v4 < 0 )
      return 0;
  }
  CGameLayer::AddGraphic(this: m_pMemory[v4], pGraphic);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00419CC0
// Name: public: CGameUIDefinition::CGameUIDefinition(class IGameUISystem __near *)
// Source: json
//------------------------------------------------------------------------------
CGameUIDefinition *__thiscall CGameUIDefinition::CGameUIDefinition(
        CGameUIDefinition *this,
        IGameUISystem *pGameUISystem)
{
  CUtlString *p_m_pName; // edi

  p_m_pName = &this->m_pName;
  this->__vftable = (CGameUIDefinition_vtbl *)&CGameUIDefinition::`vftable';
  this->m_References.m_pHead = nullptr;
  CUtlString::CUtlString(this: &this->m_pName);
  this->m_Groups.m_Memory.m_pMemory = nullptr;
  this->m_Groups.m_Memory.m_nAllocationCount = 0;
  this->m_Groups.m_Memory.m_nGrowSize = 0;
  this->m_Groups.m_Size = 0;
  this->m_Groups.m_pElements = nullptr;
  this->m_Layers.m_Memory.m_pMemory = nullptr;
  this->m_Layers.m_Memory.m_nAllocationCount = 0;
  this->m_Layers.m_Memory.m_nGrowSize = 0;
  this->m_Layers.m_Size = 0;
  this->m_Layers.m_pElements = nullptr;
  this->m_Scripts.m_Memory.m_pMemory = nullptr;
  this->m_Scripts.m_Memory.m_nAllocationCount = 0;
  this->m_Scripts.m_Memory.m_nGrowSize = 0;
  this->m_Scripts.m_Size = 0;
  this->m_Scripts.m_pElements = nullptr;
  this->m_pGameUISystem = pGameUISystem;
  CUtlString::operator=(this: p_m_pName, src: defaultValue);
  this->m_bVisible = true;
  this->bMouseFocusEqualsKeyboardFocus = true;
  this->m_bCanAcceptInput = false;
  this->m_hScheme = nullptr;
  this->m_pGameStage = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00419D40
// Name: public: virtual bool CGameUIDefinition::GetVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameUIDefinition::GetVisible(CGameUIDefinition *this)
{
  return this->m_bVisible;
}

//------------------------------------------------------------------------------
// Address: 0x00419D50
// Name: public: CGameUIDefinition::~CGameUIDefinition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIDefinition::~CGameUIDefinition(CGameUIDefinition *this)
{
  bool v2; // sf
  CUtlReference<CGameUIDefinition> *m_pHead; // eax
  CUtlReference<CGameUIDefinition> *m_pNext; // ecx
  bool v5; // zf

  this->__vftable = (CGameUIDefinition_vtbl *)&CGameUIDefinition::`vftable';
  CGameUIDefinition::Shutdown(this);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Scripts);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Layers);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Groups);
  v2 = this->m_pName.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_pName.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_pName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pName.m_Storage.m_Memory.m_pMemory);
      this->m_pName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_pName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  m_pHead = this->m_References.m_pHead;
  if ( m_pHead != nullptr )
  {
    do
    {
      m_pNext = m_pHead->m_pNext;
      v5 = m_pHead->m_pNext == nullptr;
      m_pHead->m_pNext = nullptr;
      m_pHead->m_pPrev = nullptr;
      m_pHead->m_pObject = nullptr;
      m_pHead = m_pNext;
    }
    while ( !v5 );
  }
  this->m_References.m_pHead = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00419E30
// Name: public: bool CGameUIDefinition::CreateDefault(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameUIDefinition::CreateDefault(CGameUIDefinition *this, CGameLayer *pName)
{
  CGameLayer *v3; // eax
  CGameLayer *v4; // eax
  CGameLayer *v5; // eax
  CGameLayer *v6; // eax
  int v7; // ecx
  CGameLayer *v8; // eax
  CGameLayer *v9; // eax
  CGameStage *v10; // eax
  CGameStage *v11; // eax
  int m_Size; // [esp-Ch] [ebp-10h]

  CUtlString::operator=(this: &this->m_pName, src: (const char *)pName);
  this->m_hScheme = (IGameUIScheme *)g_pGameUISchemeManager->LoadSchemeFromFile(
                                       this: g_pGameUISchemeManager,
                                       a2: "resource\\ClientScheme.res",
                                       a3: "nouiloadedscheme");
  v3 = (CGameLayer *)MemAlloc_Alloc(nSize: 0x50u);
  if ( v3 != nullptr )
    v4 = CGameLayer::CGameLayer(this: v3, layerType: SUBLAYER_STATIC);
  else
    v4 = nullptr;
  v4->m_LayerType = SUBLAYER_STATIC;
  m_Size = this->m_Layers.m_Size;
  pName = v4;
  CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Layers,
    elem: m_Size,
    src: (vgui::TreeNode **)&pName);
  v5 = (CGameLayer *)MemAlloc_Alloc(nSize: 0x50u);
  if ( v5 != nullptr )
    v6 = CGameLayer::CGameLayer(this: v5, layerType: SUBLAYER_STATIC);
  else
    v6 = nullptr;
  v6->m_LayerType = SUBLAYER_DYNAMIC;
  v7 = this->m_Layers.m_Size;
  pName = v6;
  CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Layers,
    elem: v7,
    src: (vgui::TreeNode **)&pName);
  v8 = (CGameLayer *)MemAlloc_Alloc(nSize: 0x50u);
  if ( v8 != nullptr )
    v9 = CGameLayer::CGameLayer(this: v8, layerType: SUBLAYER_STATIC);
  else
    v9 = nullptr;
  pName = v9;
  v9->m_LayerType = SUBLAYER_FONT;
  CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Layers,
    elem: this->m_Layers.m_Size,
    src: (vgui::TreeNode **)&pName);
  v10 = (CGameStage *)MemAlloc_Alloc(nSize: 0x240u);
  if ( v10 != nullptr )
    v11 = CGameStage::CGameStage(this: v10);
  else
    v11 = nullptr;
  this->m_pGameStage = v11;
  pName = (CGameLayer *)v11;
  CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Groups,
    elem: 0,
    src: (vgui::TreeNode **)&pName);
  this->m_bCanAcceptInput = false;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00419F40
// Name: public: void CGameUIDefinition::InitializeScripts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIDefinition::InitializeScripts(CGameUIDefinition *this)
{
  int v2; // ecx
  char *v3; // eax
  CUtlString *p_m_pName; // ebp
  const char *v5; // eax
  const char *v6; // eax
  const char *i; // edi
  CGameUIScript *v8; // eax
  CGameUIScript *v9; // esi
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // [esp-8h] [ebp-340h]
  int k; // [esp+Ch] [ebp-32Ch] BYREF
  CFmtStrN<256> scriptPath; // [esp+10h] [ebp-328h] BYREF
  CFmtStrN<256> path[2]; // [esp+11Ch] [ebp-21Ch] BYREF

  if ( this->m_Scripts.m_Size == 0 )
  {
    v2 = 1;
    v3 = &path[0].m_szBuf[4];
    do
    {
      *(_DWORD *)(v3 - 5) = &CFmtStrN<256>::`vftable';
      *(v3 - 1) = 1;
      *v3 = 0;
      *(_DWORD *)(v3 + 259) = 0;
      v3 += 268;
      --v2;
    }
    while ( v2 >= 0 );
    p_m_pName = &this->m_pName;
    v5 = CUtlString::Get(this: p_m_pName);
    CFmtStrN<256>::sprintf(this: (CFmtStrN<256> *)&path[0].m_bQuietTruncation, pszFormat: "vguiedit\\%s.lua", v5);
    v13 = CUtlString::Get(this: p_m_pName);
    v6 = CUtlString::Get(this: p_m_pName);
    CFmtStrN<256>::sprintf(
      this: (CFmtStrN<256> *)&path[1].m_bQuietTruncation,
      pszFormat: "vguiedit\\%s\\%s.lua",
      v6,
      v13);
    scriptPath.__vftable = nullptr;
    for ( i = &path[0].m_szBuf[4]; ; i += 268 )
    {
      *(_DWORD *)&scriptPath.m_bQuietTruncation = &CFmtStrN<256>::`vftable';
      scriptPath.m_szBuf[3] = 1;
      scriptPath.m_szBuf[4] = 0;
      path[0].__vftable = nullptr;
      CFmtStrN<256>::sprintf(this: (CFmtStrN<256> *)&scriptPath.m_bQuietTruncation, pszFormat: "scripts\\%s", i);
      if ( g_pFullFileSystem->FileExists(
             this: &g_pFullFileSystem->IBaseFileSystem,
             a2: &scriptPath.m_szBuf[4],
             a3: "MOD") )
      {
        v8 = (CGameUIScript *)MemAlloc_Alloc(nSize: 0x34u);
        if ( v8 != nullptr )
          v9 = CGameUIScript::CGameUIScript(this: v8);
        else
          v9 = nullptr;
        k = (int)v9;
        if ( CGameUIScript::SetScript(this: v9, pszFileName: i, pDef: this) )
        {
          CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
            this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Scripts,
            elem: this->m_Scripts.m_Size,
            src: (vgui::TreeNode **)&k);
          v12 = CUtlString::Get(this: p_m_pName);
          DevMsg(a1: "Loaded script %s for %s\n", &scriptPath.m_szBuf[4], v12);
          this->m_bCanAcceptInput = false;
          return;
        }
        v10 = CUtlString::Get(this: p_m_pName);
        _Warning(a1: "Invalid script %s for %s\n", &scriptPath.m_szBuf[4], v10);
        if ( v9 != nullptr )
        {
          CGameUIScript::~CGameUIScript(this: v9);
          free(pMem: v9);
        }
      }
      else
      {
        v11 = CUtlString::Get(this: p_m_pName);
        DevMsg(a1: "No default script %s found for %s\n", &scriptPath.m_szBuf[4], v11);
      }
      if ( ++scriptPath.__vftable >= (CFmtStrN<256>_vtbl *)2 )
      {
        this->m_bCanAcceptInput = false;
        return;
      }
    }
  }
  this->m_bCanAcceptInput = false;
}

//------------------------------------------------------------------------------
// Address: 0x0041A210
// Name: private: bool CGameUIDefinition::UnserializeLayer(class CDmxElement __near *,class CUtlDict<class CGameGraphic __near *,int> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameUIDefinition::UnserializeLayer(
        CGameUIDefinition *this,
        CGameLayer *pLayer,
        CUtlDict<CGameGraphic *,int> *unserializedGraphicMapping)
{
  CDmxElement *v3; // esi
  const CDmxAttribute *Attribute; // eax
  CUtlDict<CGameGraphic *,int> *v6; // ebp
  const CDmxAttribute *v7; // edi
  CDmxAttribute *v8; // eax
  CGameLayer *v9; // eax
  CGameLayer *v10; // eax
  CDmxAttribute *v11; // eax
  CGameLayer *v12; // eax
  CGameLayer *v13; // eax
  const CDmxAttribute *v14; // eax
  CDmxAttribute *v15; // eax
  CGameLayer *v16; // eax
  CGameLayer *v17; // eax

  v3 = (CDmxElement *)pLayer;
  Attribute = CDmxElement::GetAttribute(this: (CDmxElement *)pLayer, pAttributeName: "staticGraphics");
  v6 = unserializedGraphicMapping;
  v7 = Attribute;
  if ( Attribute != nullptr && Attribute->m_Type == AT_FIRST_ARRAY_TYPE )
  {
    v8 = (CDmxAttribute *)CDmxElement::GetAttribute(this: v3, pAttributeName: "staticGraphics");
    if ( CDmxAttribute::GetArray<CDmxElement *>(this: v8)->m_Size != 0 )
    {
      v9 = (CGameLayer *)MemAlloc_Alloc(nSize: 0x50u);
      if ( v9 != nullptr )
        v10 = CGameLayer::CGameLayer(this: v9, layerType: SUBLAYER_STATIC);
      else
        v10 = nullptr;
      pLayer = v10;
      v10->m_LayerType = SUBLAYER_STATIC;
      CGameLayer::Unserialize(this: v10, pLayer: v3, unserializedGraphicMapping: v6);
      CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
        this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Layers,
        elem: this->m_Layers.m_Size,
        src: (vgui::TreeNode **)&pLayer);
    }
    if ( v7->m_Type == AT_FIRST_ARRAY_TYPE )
    {
      v11 = (CDmxAttribute *)CDmxElement::GetAttribute(this: v3, pAttributeName: "dynamicGraphics");
      if ( CDmxAttribute::GetArray<CDmxElement *>(this: v11)->m_Size != 0 )
      {
        v12 = (CGameLayer *)MemAlloc_Alloc(nSize: 0x50u);
        if ( v12 != nullptr )
          v13 = CGameLayer::CGameLayer(this: v12, layerType: SUBLAYER_STATIC);
        else
          v13 = nullptr;
        pLayer = v13;
        v13->m_LayerType = SUBLAYER_DYNAMIC;
        CGameLayer::Unserialize(this: v13, pLayer: v3, unserializedGraphicMapping: v6);
        CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
          this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Layers,
          elem: this->m_Layers.m_Size,
          src: (vgui::TreeNode **)&pLayer);
      }
    }
  }
  v14 = CDmxElement::GetAttribute(this: v3, pAttributeName: "fontGraphics");
  if ( v14 != nullptr && v14->m_Type == AT_FIRST_ARRAY_TYPE )
  {
    v15 = (CDmxAttribute *)CDmxElement::GetAttribute(this: v3, pAttributeName: "fontGraphics");
    if ( CDmxAttribute::GetArray<CDmxElement *>(this: v15)->m_Size != 0 )
    {
      v16 = (CGameLayer *)MemAlloc_Alloc(nSize: 0x50u);
      if ( v16 != nullptr )
        v17 = CGameLayer::CGameLayer(this: v16, layerType: SUBLAYER_STATIC);
      else
        v17 = nullptr;
      pLayer = v17;
      v17->m_LayerType = SUBLAYER_FONT;
      CGameLayer::Unserialize(this: v17, pLayer: v3, unserializedGraphicMapping: v6);
      CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
        this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Layers,
        elem: this->m_Layers.m_Size,
        src: (vgui::TreeNode **)&pLayer);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041A430
// Name: public: bool CGameUIDefinition::Unserialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameUIDefinition::Unserialize(CGameUIDefinition *this, CDmxElement *pElement)
{
  const char *TypeString; // eax
  const CDmxAttribute *Attribute; // eax
  const char *v6; // esi
  IGameUIScheme *v7; // edi
  IGameUIScheme *v8; // eax
  const CDmxAttribute *v9; // eax
  CDmxAttribute *v10; // ebx
  CDmxAttribute *v11; // eax
  const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v12; // esi
  int v13; // edi
  int v14; // ebp
  const char *v15; // eax
  int v16; // ebp
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *v17; // edi
  int m_Size; // ebx
  const char *v19; // eax
  CGameLayer *v20; // eax
  CGameLayer *v21; // eax
  CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *v22; // esi
  CGameLayer *v23; // eax
  CGameLayer *v24; // eax
  int v25; // ecx
  CGameLayer *v26; // eax
  CGameLayer *v27; // eax
  CDmxAttribute *v28; // eax
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *v29; // ebp
  vgui::TreeNode *v30; // edi
  char *v31; // esi
  const char *v32; // eax
  int v33; // eax
  bool (__cdecl *m_LessFunc)(const char *const *, const char *const *); // edi
  int v35; // esi
  const char *v36; // eax
  CGraphicGroup *v37; // eax
  CGraphicGroup *v38; // ebx
  const UniqueId_t *Id; // eax
  int v40; // edi
  int v41; // eax
  int *v42; // esi
  int v43; // ecx
  int v44; // eax
  bool v45; // zf
  CGraphicGroup **v46; // eax
  const char *v47; // eax
  CGameStage *v48; // eax
  vgui::TreeNode *v49; // esi
  int v50; // edi
  bool (__cdecl *v51)(const char *const *, const char *const *); // ebx
  int v52; // esi
  const char *v53; // eax
  CDmxElement **m_pMemory; // eax
  bool v55; // al
  const char *v56; // eax
  int j; // esi
  void *v58; // eax
  void *m_nAllocationCount; // eax
  int v60; // [esp-Ch] [ebp-154h]
  vgui::TreeNode *src; // [esp+Ch] [ebp-13Ch] BYREF
  CUtlDict<CGameGraphic *,int> unserializedGraphicMapping; // [esp+10h] [ebp-138h] BYREF
  int i; // [esp+34h] [ebp-114h]
  int v64; // [esp+38h] [ebp-110h]
  vgui::TreeNode *v65; // [esp+3Ch] [ebp-10Ch] BYREF
  CUtlMap<char const *,CGameGraphic *,int>::Node_t insert; // [esp+40h] [ebp-108h] BYREF
  char v67[256]; // [esp+48h] [ebp-100h] BYREF

  unserializedGraphicMapping.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))this;
  TypeString = CDmxElement::GetTypeString(this: pElement);
  if ( _V_stricmp(s1: TypeString, s2: "VguiCompiledDoc") != 0 )
    return 0;
  CDmxElement::UnpackIntoStructure(this: pElement, pData: this, pUnpack: s_GameUIDefinitionUnpack);
  Attribute = CDmxElement::GetAttribute(this: pElement, pAttributeName: "scheme");
  if ( Attribute != nullptr )
  {
    if ( Attribute->m_Type == AT_STRING )
      v6 = CUtlString::operator char const *(this: (CUtlString *)Attribute->m_pData);
    else
      v6 = defaultValue;
  }
  else
  {
    v6 = defaultValue;
  }
  v7 = g_pGameUISchemeManager->GetDefaultScheme(this: g_pGameUISchemeManager);
  v8 = g_pGameUISchemeManager->GetScheme(this: g_pGameUISchemeManager, a2: v6);
  this->m_hScheme = v8;
  if ( v8 == v7 )
    this->m_hScheme = (IGameUIScheme *)g_pGameUISchemeManager->LoadSchemeFromFile(
                                         this: g_pGameUISchemeManager,
                                         a2: v6,
                                         a3: v6);
  CGameUISystemMgr::SetScheme(this: g_pGameUISystemMgrImpl, scheme: this->m_hScheme);
  v9 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "layers");
  v10 = (CDmxAttribute *)v9;
  if ( v9 == nullptr || v9->m_Type != AT_FIRST_ARRAY_TYPE )
    return 0;
  v11 = (CDmxAttribute *)CDmxElement::GetAttribute(this: pElement, pAttributeName: "dynamicimagelist");
  if ( v11 != nullptr )
  {
    v12 = CDmxAttribute::GetArray<CUtlString>(this: v11);
    v13 = 0;
    if ( v12->m_Size > 0 )
    {
      v14 = 0;
      do
      {
        v15 = CUtlString::operator char const *(this: &v12->m_Memory.m_pMemory[v14]);
        CGameUISystemMgr::LoadImageAliasTexture(
          this: g_pGameUISystemMgrImpl,
          pAlias: v15,
          pBaseTextureName: defaultValue);
        ++v13;
        ++v14;
      }
      while ( v13 < v12->m_Size );
    }
  }
  v16 = 0;
  memset(&unserializedGraphicMapping.m_Elements.m_Tree.m_Elements.m_nAllocationCount, 0, 12);
  unserializedGraphicMapping.m_Elements.m_Tree.m_NumElements = -1;
  unserializedGraphicMapping.m_Elements.m_Tree.m_FirstFree = 0;
  unserializedGraphicMapping.m_Elements.m_Tree.m_LastAlloc.index = -1;
  unserializedGraphicMapping.m_Elements.m_Tree.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int> *)-1;
  i = 0;
  unserializedGraphicMapping.m_Elements.m_Tree.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int> *)CaselessStringLessThan;
  v17 = CDmxAttribute::GetArray<CDmxElement *>(this: v10);
  m_Size = v17->m_Size;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      v19 = CDmxElement::GetTypeString(this: v17->m_Memory.m_pMemory[v16]);
      if ( _V_stricmp(s1: v19, s2: "DmeCompiledSubLayer") == 0
        && CGameUIDefinition::UnserializeLayer(
             this: (CGameUIDefinition *)unserializedGraphicMapping.m_Elements.m_Tree.m_LessFunc.m_LessFunc,
             pLayer: (CGameLayer *)v17->m_Memory.m_pMemory[v16],
             unserializedGraphicMapping: (CUtlDict<CGameGraphic *,int> *)&unserializedGraphicMapping.m_Elements.m_Tree.m_Elements) == 0 )
      {
        break;
      }
      if ( ++v16 >= m_Size )
        goto LABEL_20;
    }
LABEL_34:
    CUtlDict<CGameGraphic *,int>::RemoveAll(this: (CUtlDict<CGameGraphic *,int> *)&unserializedGraphicMapping.m_Elements.m_Tree.m_Elements);
    CUtlRBTree<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int,CUtlMap<char const *,CGameGraphic *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int,CUtlMap<char const *,CGameGraphic *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int>,int>>(this: (CUtlRBTree<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int,CUtlMap<char const *,CGameGraphic *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int>,int> > *)&unserializedGraphicMapping.m_Elements.m_Tree.m_Elements);
    return 0;
  }
LABEL_20:
  v20 = (CGameLayer *)MemAlloc_Alloc(nSize: 0x50u);
  if ( v20 != nullptr )
    v21 = CGameLayer::CGameLayer(this: v20, layerType: SUBLAYER_STATIC);
  else
    v21 = nullptr;
  v22 = (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)((char *)unserializedGraphicMapping.m_Elements.m_Tree.m_LessFunc.m_LessFunc
                                                                         + 48);
  v21->m_LayerType = SUBLAYER_STATIC;
  v60 = v22->m_Size;
  src = (vgui::TreeNode *)v21;
  CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(this: v22, elem: v60, &src);
  v23 = (CGameLayer *)MemAlloc_Alloc(nSize: 0x50u);
  if ( v23 != nullptr )
    v24 = CGameLayer::CGameLayer(this: v23, layerType: SUBLAYER_STATIC);
  else
    v24 = nullptr;
  v24->m_LayerType = SUBLAYER_DYNAMIC;
  v25 = v22->m_Size;
  src = (vgui::TreeNode *)v24;
  CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(this: v22, elem: v25, &src);
  v26 = (CGameLayer *)MemAlloc_Alloc(nSize: 0x50u);
  if ( v26 != nullptr )
    v27 = CGameLayer::CGameLayer(this: v26, layerType: SUBLAYER_STATIC);
  else
    v27 = nullptr;
  src = (vgui::TreeNode *)v27;
  v27->m_LayerType = SUBLAYER_FONT;
  CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(this: v22, elem: v22->m_Size, &src);
  v28 = (CDmxAttribute *)CDmxElement::GetAttribute(this: pElement, pAttributeName: "groups");
  if ( v28 == nullptr )
  {
    CUtlDict<CGameGraphic *,int>::RemoveAll(this: (CUtlDict<CGameGraphic *,int> *)&unserializedGraphicMapping.m_Elements.m_Tree.m_Elements);
    CUtlRBTree<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int,CUtlMap<char const *,CGameGraphic *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int,CUtlMap<char const *,CGameGraphic *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int>,int>>(this: (CUtlRBTree<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int,CUtlMap<char const *,CGameGraphic *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int>,int> > *)&unserializedGraphicMapping.m_Elements.m_Tree.m_Elements);
    return 1;
  }
  if ( v28->m_Type != AT_FIRST_ARRAY_TYPE )
    goto LABEL_34;
  v29 = CDmxAttribute::GetArray<CDmxElement *>(this: v28);
  src = (vgui::TreeNode *)v29->m_Size;
  v30 = src;
  if ( src == nullptr )
  {
    _Msg(a1: "Error: No stage found");
    goto LABEL_34;
  }
  v31 = (char *)&src[-1] + 407;
  if ( (int)&src[-1] + 407 < 0 )
    goto LABEL_34;
  while ( 1 )
  {
    v32 = CDmxElement::GetTypeString(this: v29->m_Memory.m_pMemory[(_DWORD)v31]);
    if ( _V_stricmp(s1: v32, s2: "DmeCompiledStage") == 0 )
      break;
    if ( (int)--v31 < 0 )
      goto LABEL_34;
  }
  v33 = 0;
  v64 = 0;
  if ( (int)v30 > 0 )
  {
    do
    {
      m_LessFunc = unserializedGraphicMapping.m_Elements.m_Tree.m_LessFunc.m_LessFunc;
      v35 = v33;
      v36 = CDmxElement::GetTypeString(this: v29->m_Memory.m_pMemory[v33]);
      if ( _V_stricmp(s1: v36, s2: "DmeCompiledGroup") != 0 )
      {
        v47 = CDmxElement::GetTypeString(this: v29->m_Memory.m_pMemory[v35]);
        if ( _V_stricmp(s1: v47, s2: "DmeCompiledStage") == 0 )
        {
          v48 = (CGameStage *)MemAlloc_Alloc(nSize: 0x240u);
          if ( v48 != nullptr )
            v49 = (vgui::TreeNode *)CGameStage::CGameStage(this: v48);
          else
            v49 = nullptr;
          v65 = v49;
          CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
            this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)((char *)m_LessFunc + 28),
            elem: 0,
            src: &v65);
          *((_DWORD *)m_LessFunc + 24) = v49;
        }
      }
      else
      {
        v37 = (CGraphicGroup *)MemAlloc_Alloc(nSize: 0x1B4u);
        if ( v37 != nullptr )
          v38 = CGraphicGroup::CGraphicGroup(this: v37);
        else
          v38 = nullptr;
        Id = CDmxElement::GetId(this: v29->m_Memory.m_pMemory[v35]);
        UniqueIdToString(id: Id, pBuf: v67, nMaxLen: 255);
        insert.key = MemAlloc_StrDup(pString: v67);
        insert.elem = v38;
        CUtlRBTree<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int,CUtlMap<char const *,CGameGraphic *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int>,int>>::Insert(
          this: (CUtlRBTree<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int,CUtlMap<char const *,CGameGraphic *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int>,int> > *)&unserializedGraphicMapping.m_Elements.m_Tree.m_Elements,
          &insert);
        v40 = *((_DWORD *)unserializedGraphicMapping.m_Elements.m_Tree.m_LessFunc.m_LessFunc + 10);
        v41 = *((_DWORD *)unserializedGraphicMapping.m_Elements.m_Tree.m_LessFunc.m_LessFunc + 8);
        v42 = (int *)((char *)unserializedGraphicMapping.m_Elements.m_Tree.m_LessFunc.m_LessFunc + 28);
        if ( v40 + 1 > v41 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)((char *)unserializedGraphicMapping.m_Elements.m_Tree.m_LessFunc.m_LessFunc + 28),
            num: v40 - v41 + 1);
        ++v42[3];
        v43 = *v42;
        v44 = v42[3] - v40 - 1;
        v45 = v42[3] - v40 == 1;
        v42[4] = *v42;
        if ( v44 >= 0 && !v45 )
          _V_memmove(dest: (void *)(v43 + 4 * v40 + 4), src: (const void *)(v43 + 4 * v40), count: 4 * v44);
        v46 = (CGraphicGroup **)(*v42 + 4 * v40);
        if ( v46 != nullptr )
          *v46 = v38;
      }
      v33 = ++v64;
    }
    while ( v64 < (int)src );
  }
  v50 = 0;
  if ( (int)src > 0 )
  {
    v51 = unserializedGraphicMapping.m_Elements.m_Tree.m_LessFunc.m_LessFunc;
    do
    {
      v52 = v50;
      v53 = CDmxElement::GetTypeString(this: v29->m_Memory.m_pMemory[v50]);
      v45 = _V_stricmp(s1: v53, s2: "DmeCompiledGroup") == 0;
      m_pMemory = v29->m_Memory.m_pMemory;
      if ( v45 )
      {
        v55 = CGraphicGroup::Unserialize(
                this: *(CGraphicGroup **)(v52 * 4 + *((_DWORD *)v51 + 7)),
                pElement: m_pMemory[v52],
                unserializedGraphicMapping: (CUtlDict<CGameGraphic *,int> *)&unserializedGraphicMapping.m_Elements.m_Tree.m_Elements);
      }
      else
      {
        v56 = CDmxElement::GetTypeString(this: m_pMemory[v50]);
        if ( _V_stricmp(s1: v56, s2: "DmeCompiledStage") != 0 )
          goto LABEL_64;
        v55 = CGameStage::Unserialize(
                this: *(CGameStage **)(v52 * 4 + *((_DWORD *)v51 + 7)),
                pElement: v29->m_Memory.m_pMemory[v52],
                unserializedGraphicMapping: (CUtlDict<CGameGraphic *,int> *)&unserializedGraphicMapping.m_Elements.m_Tree.m_Elements);
      }
      if ( !v55 )
      {
        CUtlDict<CGameGraphic *,int>::RemoveAll(this: (CUtlDict<CGameGraphic *,int> *)&unserializedGraphicMapping.m_Elements.m_Tree.m_Elements);
        CUtlRBTree<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int,CUtlMap<char const *,CGameGraphic *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int>,int>>::RemoveAll(this: (CUtlRBTree<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int,CUtlMap<char const *,CGameGraphic *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int>,int> > *)&unserializedGraphicMapping.m_Elements.m_Tree.m_Elements);
        m_nAllocationCount = (void *)unserializedGraphicMapping.m_Elements.m_Tree.m_Elements.m_nAllocationCount;
        unserializedGraphicMapping.m_Elements.m_Tree.m_LastAlloc.index = -1;
        if ( unserializedGraphicMapping.m_Elements.m_Tree.m_Root >= 0 )
        {
          if ( unserializedGraphicMapping.m_Elements.m_Tree.m_Elements.m_nAllocationCount != 0 )
          {
            _g_pMemAlloc->Free_2(
              this: _g_pMemAlloc,
              a2: (void *)unserializedGraphicMapping.m_Elements.m_Tree.m_Elements.m_nAllocationCount);
            m_nAllocationCount = nullptr;
            unserializedGraphicMapping.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
          }
          unserializedGraphicMapping.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
        }
        unserializedGraphicMapping.m_Elements.m_Tree.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int> *)-1;
        if ( unserializedGraphicMapping.m_Elements.m_Tree.m_Root >= 0 && m_nAllocationCount != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
          return 0;
        }
        return 0;
      }
LABEL_64:
      ++v50;
    }
    while ( v50 < (int)src );
  }
  for ( j = CUtlRBTree<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int,CUtlMap<char const *,CGameGraphic *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int>,int>>::FirstInorder(this: (CUtlRBTree<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int,CUtlMap<char const *,CGameGraphic *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int>,int> > *)&unserializedGraphicMapping.m_Elements.m_Tree.m_Elements);
        j != -1;
        j = CUtlRBTree<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int,CUtlMap<char const *,CGameGraphic *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int>,int>>::NextInorder(
              this: (CUtlRBTree<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int,CUtlMap<char const *,CGameGraphic *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int>,int> > *)&unserializedGraphicMapping.m_Elements.m_Tree.m_Elements,
              i: j) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: *(void **)(unserializedGraphicMapping.m_Elements.m_Tree.m_Elements.m_nAllocationCount + 24 * j + 16));
  }
  CUtlRBTree<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int,CUtlMap<char const *,CGameGraphic *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int>,int>>::RemoveAll(this: (CUtlRBTree<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int,CUtlMap<char const *,CGameGraphic *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int>,int> > *)&unserializedGraphicMapping.m_Elements.m_Tree.m_Elements);
  CUtlRBTree<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int,CUtlMap<char const *,CGameGraphic *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int>,int>>::RemoveAll(this: (CUtlRBTree<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int,CUtlMap<char const *,CGameGraphic *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int>,int> > *)&unserializedGraphicMapping.m_Elements.m_Tree.m_Elements);
  v58 = (void *)unserializedGraphicMapping.m_Elements.m_Tree.m_Elements.m_nAllocationCount;
  unserializedGraphicMapping.m_Elements.m_Tree.m_LastAlloc.index = -1;
  if ( unserializedGraphicMapping.m_Elements.m_Tree.m_Root >= 0 )
  {
    if ( unserializedGraphicMapping.m_Elements.m_Tree.m_Elements.m_nAllocationCount != 0 )
    {
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: (void *)unserializedGraphicMapping.m_Elements.m_Tree.m_Elements.m_nAllocationCount);
      v58 = nullptr;
      unserializedGraphicMapping.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
    }
    unserializedGraphicMapping.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  }
  unserializedGraphicMapping.m_Elements.m_Tree.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int> *)-1;
  if ( unserializedGraphicMapping.m_Elements.m_Tree.m_Root >= 0 && v58 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v58);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041AA70
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class CGameText>(class CGameText __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<CGameText>()
{
  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    dword_5B9FEC = 9;
    dword_5BA018 = 9;
    dword_5B9FF0 = 108;
    dword_5B9FF4 = 8;
    dword_5B9FF8 = -1;
    dword_5B9FFC = 0;
    dword_5BA000 = 0;
    dword_5BA004 = 0;
    dword_5BA008 = 0;
    dword_5BA00C = 0;
    dword_5BA010 = (int)"scale";
    dword_5BA014 = (int)"1 1";
    dword_5BA01C = 116;
    dword_5BA020 = 8;
    dword_5BA024 = -1;
    dword_5BA028 = 0;
    dword_5BA02C = 0;
    dword_5BA030 = 0;
    dword_5BA034 = 0;
    dword_5BA038 = 0;
    dword_5BA03C = (int)"rotation";
    dword_5BA040 = (int)"0";
    dword_5BA044 = 3;
    dword_5BA048 = 124;
    dword_5BA04C = 4;
    dword_5BA050 = -1;
    dword_5BA054 = 0;
    dword_5BA058 = 0;
    dword_5BA05C = 0;
    dword_5BA060 = 0;
    dword_5BA064 = 0;
    dword_5BA068 = (int)"maintainaspectratio";
    dword_5BA06C = (int)"0";
    dword_5BA070 = 4;
    dword_5BA074 = 156;
    dword_5BA078 = 1;
    dword_5BA07C = -1;
    dword_5BA080 = 0;
    dword_5BA084 = 0;
    dword_5BA088 = 0;
    dword_5BA08C = 0;
    dword_5BA090 = 0;
    dword_5BA094 = (int)"sublayertype";
    dword_5BA098 = (int)"0";
    dword_5BA09C = 2;
    dword_5BA0A0 = 152;
    dword_5BA0A4 = 4;
    dword_5BA0A8 = -1;
    dword_5BA0AC = 0;
    dword_5BA0B0 = 0;
    dword_5BA0B4 = 0;
    dword_5BA0B8 = 0;
    dword_5BA0BC = 0;
    dword_5BA0C0 = (int)"visible";
    dword_5BA0C4 = (int)"1";
    dword_5BA0C8 = 4;
    dword_5BA0CC = 157;
    dword_5BA0D0 = 1;
    dword_5BA0D4 = -1;
    dword_5BA0D8 = 0;
    dword_5BA0DC = 0;
    dword_5BA0E0 = 0;
    dword_5BA0E4 = 0;
    dword_5BA0E8 = 0;
    dword_5BA0EC = (int)"initialstate";
    dword_5BA0F0 = (int)"-1";
    dword_5BA0F4 = 2;
    dword_5BA0F8 = 352;
    dword_5BA0FC = 4;
    dword_5BA100 = -1;
    dword_5BA1A4 = 2;
    dword_5BA104 = 0;
    dword_5BA108 = 0;
    dword_5BA10C = 0;
    dword_5BA110 = 0;
    dword_5BA114 = 0;
    dword_5BA118 = (int)"unlocalizedtext";
    dword_5BA11C = (int)"NONE";
    dword_5BA120 = 5;
    dword_5BA124 = 372;
    dword_5BA128 = -1;
    dword_5BA12C = -1;
    dword_5BA130 = 0;
    dword_5BA134 = 0;
    dword_5BA138 = 0;
    dword_5BA13C = 0;
    dword_5BA140 = 0;
    dword_5BA144 = (int)"allcaps";
    dword_5BA148 = (int)"0";
    dword_5BA14C = 4;
    dword_5BA150 = 412;
    dword_5BA154 = 1;
    dword_5BA158 = -1;
    dword_5BA15C = 0;
    dword_5BA160 = 0;
    dword_5BA164 = 0;
    dword_5BA168 = 0;
    dword_5BA16C = 0;
    dword_5BA170 = (int)"fontname";
    dword_5BA174 = (int)"Default";
    dword_5BA178 = 5;
    dword_5BA17C = 392;
    dword_5BA180 = -1;
    dword_5BA184 = -1;
    dword_5BA188 = 0;
    dword_5BA18C = 0;
    dword_5BA190 = 0;
    dword_5BA194 = 0;
    dword_5BA198 = 0;
    dword_5BA19C = (int)"justfication";
    dword_5BA1A0 = (int)"0";
    dword_5BA1A8 = 416;
    dword_5BA1AC = 4;
    dword_5BA1B0 = -1;
    dword_5BA1B4 = 0;
    dword_5BA1B8 = 0;
    dword_5BA1BC = 0;
    dword_5BA1C0 = 0;
    dword_5BA1C4 = 0;
    dword_5BA1C8 = (int)"color";
    dword_5BA1CC = (int)"255 255 255 255";
    dword_5BA1D0 = 8;
    dword_5BA1D4 = 128;
    dword_5BA1D8 = 4;
    dword_5BA1DC = -1;
    dword_5BA1E0 = 0;
    dword_5BA1E4 = 0;
    dword_5BA1E8 = 0;
    dword_5BA1EC = 0;
    dword_5BA1F0 = 0;
    dword_5BA1F4 = (int)"topcolor";
    dword_5BA1F8 = (int)"255 255 255 255";
    dword_5BA1FC = 8;
    dword_5BA200 = 132;
    dword_5BA204 = 4;
    dword_5BA208 = -1;
    dword_5BA20C = 0;
    dword_5BA210 = 0;
    dword_5BA214 = 0;
    dword_5BA218 = 0;
    dword_5BA21C = 0;
    dword_5BA220 = (int)"bottomcolor";
    dword_5BA224 = (int)"255 255 255 255";
    dword_5BA228 = 8;
    dword_5BA22C = 136;
    dword_5BA230 = 4;
    dword_5BA234 = -1;
    dword_5BA238 = 0;
    dword_5BA23C = 0;
    dword_5BA240 = 0;
    dword_5BA250 = (int)"0";
    dword_5BA244 = 0;
    dword_5BA248 = 0;
    dword_5BA24C = (int)"horizgradient";
    dword_5BA254 = 4;
    dword_5BA258 = 140;
    dword_5BA25C = 1;
    dword_5BA260 = -1;
    dword_5BA264 = 0;
    dword_5BA268 = 0;
    dword_5BA26C = 0;
    dword_5BA270 = 0;
    dword_5BA274 = 0;
    dword_5BA278 = 0;
    dword_5BA27C = 0;
    dword_5BA280 = 0;
    dword_5BA284 = 0;
    dword_5BA288 = 0;
    dword_5BA28C = -1;
    dword_5BA290 = 0;
    dword_5BA294 = 0;
    dword_5BA298 = 0;
    dword_5BA29C = 0;
    dword_5BA2A0 = 0;
  }
  return unpack;
}
