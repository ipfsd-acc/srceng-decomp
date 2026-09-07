// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/game_controls/hitarea.cpp
// Functions: 25
// ============================================================

#include "vgui2\game_controls\hitarea.h"

//------------------------------------------------------------------------------
// Address: 0x00421400
// Name: public: void CHitArea::OnCursorEnter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHitArea::OnCursorEnter(CHitArea *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi

  if ( this->m_pGroup != nullptr )
    this->m_pGroup->SetState_2(this: this->m_pGroup, a2: "AUTO_GAINMOUSEFOCUS");
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "OnMouseFocusGained");
  else
    v3 = nullptr;
  CGameUISystemMgr::OnGameGraphicScriptEvent(this: g_pGameUISystemMgrImpl, pGraphic: this, kvEvent: v3);
  CGameUISystemMgr::OnMouseFocusGained(this: g_pGameUISystemMgrImpl, mouseFocus: this);
  if ( v3 != nullptr )
    KeyValues::deleteThis(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00421470
// Name: public: void CHitArea::OnCursorExit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHitArea::OnCursorExit(CHitArea *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi

  if ( this->m_pGroup != nullptr )
    this->m_pGroup->SetState_2(this: this->m_pGroup, a2: "AUTO_LOSEMOUSEFOCUS");
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "OnMouseFocusLost");
  else
    v3 = nullptr;
  CGameUISystemMgr::OnGameGraphicScriptEvent(this: g_pGameUISystemMgrImpl, pGraphic: this, kvEvent: v3);
  CGameUISystemMgr::OnMouseFocusLost(this: g_pGameUISystemMgrImpl, mouseFocus: this);
  if ( v3 != nullptr )
    KeyValues::deleteThis(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x004214E0
// Name: public: void CHitArea::OnMouseDown(enum ButtonCode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHitArea::OnMouseDown(CHitArea *this, const ButtonCode_t *code)
{
  CGraphicGroup *m_pGroup; // ecx
  int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  const char *v7; // eax
  const char *Name; // eax

  if ( *code == KEY_COUNT && this->m_bDragEnabled )
  {
    this->m_bCanStartDragging = true;
    CInputGameUI::GetCursorPos(this: g_pInputGameUI, x: this->m_DragStartCursorPos, y: &this->m_DragStartCursorPos[1]);
  }
  m_pGroup = this->m_pGroup;
  if ( m_pGroup != nullptr )
  {
    v4 = *code;
    if ( *code == KEY_COUNT )
    {
      m_pGroup->SetState_2(this: m_pGroup, a2: "AUTO_MOUSELEFTDOWN");
    }
    else if ( v4 == 108 )
    {
      m_pGroup->SetState_2(this: m_pGroup, a2: "AUTO_MOUSERIGHTDOWN");
    }
    else if ( v4 == 109 )
    {
      m_pGroup->SetState_2(this: m_pGroup, a2: "AUTO_MOUSEMIDDLEDOWN");
    }
  }
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "OnMouseDown");
  else
    v6 = nullptr;
  KeyValues::SetInt(this: v6, keyName: "code", value: *code);
  KeyValues::SetName(this: v6, setName: "OnMouseClicked");
  CGameUISystemMgr::OnGameGraphicScriptEvent(this: g_pGameUISystemMgrImpl, pGraphic: this, kvEvent: v6);
  if ( *code == KEY_COUNT && CUtlString::Length(this: &this->m_OnMouseLeftClickedScriptCommand) != 0 )
  {
    v7 = CUtlString::operator char const *(this: &this->m_OnMouseLeftClickedScriptCommand);
    KeyValues::SetName(this: v6, setName: v7);
    if ( !CGameUISystemMgr::OnGameGraphicScriptEvent(this: g_pGameUISystemMgrImpl, pGraphic: this, kvEvent: v6) )
    {
      Name = KeyValues::GetName(this: v6);
      _Warning(a1: "Unable to find script function %s (assigned to OnMouseLeftClicked)\n", Name);
    }
  }
  if ( v6 != nullptr )
    KeyValues::deleteThis(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x004215F0
// Name: public: void CHitArea::OnMouseDoubleClick(enum ButtonCode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHitArea::OnMouseDoubleClick(CHitArea *this, const ButtonCode_t *code)
{
  if ( this->m_pGroup != nullptr )
    this->m_pGroup->SetState_2(this: this->m_pGroup, a2: "AUTO_MOUSEDOUBLECLICK");
}

//------------------------------------------------------------------------------
// Address: 0x00421610
// Name: public: void CHitArea::OnKeyDown(enum ButtonCode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHitArea::OnKeyDown(CHitArea *this, const ButtonCode_t *code)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi

  if ( (unsigned int)(*code - 114) > 0xBF )
  {
    if ( this->m_pGroup != nullptr )
      this->m_pGroup->SetState_2(this: this->m_pGroup, a2: "AUTO_KEYDOWN");
  }
  else
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "OnButtonPressed");
    else
      v4 = nullptr;
    KeyValues::SetInt(this: v4, keyName: "code", value: *code);
    CGameUISystemMgr::OnKeyCodeTyped(this: g_pGameUISystemMgrImpl, code);
    CGameUISystemMgr::OnGameGraphicScriptEvent(this: g_pGameUISystemMgrImpl, pGraphic: this, kvEvent: v4);
    if ( v4 != nullptr )
      KeyValues::deleteThis(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004216A0
// Name: public: void CHitArea::OnKeyUp(enum ButtonCode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHitArea::OnKeyUp(CHitArea *this, const ButtonCode_t *code)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi

  if ( (unsigned int)(*code - 114) > 0xBF )
  {
    if ( this->m_pGroup != nullptr )
      this->m_pGroup->SetState_2(this: this->m_pGroup, a2: "AUTO_KEYUP");
  }
  else
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "OnButtonReleased");
    else
      v4 = nullptr;
    KeyValues::SetInt(this: v4, keyName: "code", value: *code);
    CGameUISystemMgr::OnKeyCodeTyped(this: g_pGameUISystemMgrImpl, code);
    CGameUISystemMgr::OnGameGraphicScriptEvent(this: g_pGameUISystemMgrImpl, pGraphic: this, kvEvent: v4);
    if ( v4 != nullptr )
      KeyValues::deleteThis(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421730
// Name: public: void CHitArea::OnKeyCodeTyped(enum ButtonCode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHitArea::OnKeyCodeTyped(CHitArea *this, const ButtonCode_t *code)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "OnKeyTyped");
  else
    v4 = nullptr;
  KeyValues::SetInt(this: v4, keyName: "code", value: *code);
  CGameUISystemMgr::OnKeyCodeTyped(this: g_pGameUISystemMgrImpl, code);
  CGameUISystemMgr::OnGameGraphicScriptEvent(this: g_pGameUISystemMgrImpl, pGraphic: this, kvEvent: v4);
  if ( v4 != nullptr )
    KeyValues::deleteThis(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004217A0
// Name: public: void CHitArea::OnKeyTyped(wchar_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHitArea::OnKeyTyped(CHitArea *this, CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *unichar)
{
  CUtlBuffer::GetOverflow(this: (vgui::Panel *)g_pGameUISystemMgrImpl, msglist: unichar);
}

//------------------------------------------------------------------------------
// Address: 0x004217B0
// Name: public: void CHitArea::OnLoseKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHitArea::OnLoseKeyFocus(CHitArea *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi

  if ( this->m_pGroup != nullptr )
    this->m_pGroup->SetState_2(this: this->m_pGroup, a2: "AUTO_LOSEKEYFOCUS");
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "OnKeyFocusLost");
  else
    v3 = nullptr;
  CGameUISystemMgr::OnGameGraphicScriptEvent(this: g_pGameUISystemMgrImpl, pGraphic: this, kvEvent: v3);
  if ( v3 != nullptr )
    KeyValues::deleteThis(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00421810
// Name: public: void CHitArea::OnGainKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHitArea::OnGainKeyFocus(CHitArea *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi

  if ( this->m_pGroup != nullptr )
    this->m_pGroup->SetState_2(this: this->m_pGroup, a2: "AUTO_GAINKEYFOCUS");
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "OnKeyFocusGained");
  else
    v3 = nullptr;
  CGameUISystemMgr::OnGameGraphicScriptEvent(this: g_pGameUISystemMgrImpl, pGraphic: this, kvEvent: v3);
  if ( v3 != nullptr )
    KeyValues::deleteThis(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00421870
// Name: public: virtual void CHitArea::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHitArea::SetVisible(CHitArea *this, bool bVisible)
{
  this->m_Geometry.m_bVisible = bVisible;
  this->m_bCanAcceptInput = bVisible;
  this->m_bCanStartDragging = false;
  if ( bVisible )
    g_pGameUISystemMgrImpl->m_bForceFocusUpdate = true;
  else
    CInputGameUI::GraphicHidden(this: g_pInputGameUI, focus: this);
}

//------------------------------------------------------------------------------
// Address: 0x004218B0
// Name: public: virtual class KeyValues __near * CHitArea::HandleScriptCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CHitArea::HandleScriptCommand(CHitArea *this, KeyValues *args)
{
  const char *Name; // ebx
  const char *String; // eax

  Name = KeyValues::GetName(this: args);
  if ( _V_stricmp(s1: "SetDragEnabled", s2: Name) != 0 )
  {
    if ( _V_stricmp(s1: "SetMouseLeftClickedCommand", s2: Name) != 0 )
    {
      if ( _V_stricmp(s1: "RequestFocus", s2: Name) != 0 )
      {
        return CGameGraphic::HandleScriptCommand(this, args);
      }
      else
      {
        CGameUISystemMgr::RequestKeyFocus(this: g_pGameUISystemMgrImpl, pGraphic: (CGraphicGroup *)this, args);
        return nullptr;
      }
    }
    else
    {
      String = KeyValues::GetString(this: args, keyName: "command", defaultValue: defaultValue);
      CUtlString::operator=(this: &this->m_OnMouseLeftClickedScriptCommand, src: String);
      return nullptr;
    }
  }
  else
  {
    this->m_bDragEnabled = KeyValues::GetInt(this: args, keyName: "dragenabled", defaultValue: 0) != 0;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421960
// Name: public: void CHitArea::OnCursorMove(int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHitArea::OnCursorMove(CHitArea *this, int *cursorX, int *cursorY)
{
  int v3; // edx
  int v4; // eax
  int v5; // edx

  if ( this->m_bCanStartDragging )
  {
    v3 = *cursorX;
    this->m_DragCurrentCursorPos[0] = *cursorX;
    v4 = *cursorY;
    v5 = v3 - this->m_DragStartCursorPos[0];
    this->m_DragCurrentCursorPos[1] = *cursorY;
    if ( (float)((float)((float)(v4 - this->m_DragStartCursorPos[1]) * (float)(v4 - this->m_DragStartCursorPos[1]))
               + (float)((float)v5 * (float)v5)) > 16.0 )
    {
      this->m_bCanStartDragging = false;
      this->m_IsDragging = true;
    }
  }
  else if ( this->m_IsDragging )
  {
    this->m_DragCurrentCursorPos[0] = *cursorX;
    this->m_DragCurrentCursorPos[1] = *cursorY;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004219F0
// Name: public: void CHitArea::OnMouseUp(enum ButtonCode_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHitArea::OnMouseUp(CHitArea *this, const ButtonCode_t *code, bool bFireScripts)
{
  CGraphicGroup *m_pGroup; // ecx
  int v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // edi

  m_pGroup = this->m_pGroup;
  this->m_bCanStartDragging = false;
  if ( m_pGroup != nullptr )
  {
    v5 = *code;
    if ( *code == KEY_COUNT )
    {
      m_pGroup->SetState_2(this: m_pGroup, a2: "AUTO_MOUSELEFTUP");
    }
    else if ( v5 == 108 )
    {
      m_pGroup->SetState_2(this: m_pGroup, a2: "AUTO_MOUSERIGHTUP");
    }
    else if ( v5 == 109 )
    {
      m_pGroup->SetState_2(this: m_pGroup, a2: "AUTO_MOUSEMIDDLEUP");
    }
  }
  if ( this->m_IsDragging || !bFireScripts )
  {
    this->m_IsDragging = false;
  }
  else
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "OnMouseUp");
    else
      v7 = nullptr;
    KeyValues::SetInt(this: v7, keyName: "code", value: *code);
    CGameUISystemMgr::OnGameGraphicScriptEvent(this: g_pGameUISystemMgrImpl, pGraphic: this, kvEvent: v7);
    if ( v7 != nullptr )
      KeyValues::deleteThis(this: v7);
    this->m_IsDragging = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421AB0
// Name: public: virtual void CHitArea::UpdateGeometry(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHitArea::UpdateGeometry(CHitArea *this)
{
  DmeTime_t result; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_CurrentState != -1 )
  {
    CGameGraphic::GetAnimationTimePassed(this, &result);
    CTypedLog<Vector2D>::GetValue(
      this: &this->m_Anims.m_Memory.m_pMemory[this->m_CurrentState]->m_CenterPosAnim,
      time: result,
      pOutValue: &this->m_Geometry.m_Center);
    CTypedLog<Vector2D>::GetValue(
      this: &this->m_Anims.m_Memory.m_pMemory[this->m_CurrentState]->m_ScaleAnim,
      time: result,
      pOutValue: &this->m_Geometry.m_Scale);
    CTypedLog<float>::GetValue(
      this: &this->m_Anims.m_Memory.m_pMemory[this->m_CurrentState]->m_RotationAnim,
      time: result,
      pOutValue: &this->m_Geometry.m_Rotation);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421B30
// Name: public: virtual bool CHitArea::HitTest(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHitArea::HitTest(CHitArea *this, int x, int y)
{
  int v4; // ebx
  int i; // edi
  Vector2D *m_pMemory; // ecx
  int v7; // eax
  float *p_x; // eax
  Vector2D v10; // [esp-20h] [ebp-2Ch]
  Vector2D v11; // [esp-10h] [ebp-1Ch]
  float xa; // [esp+10h] [ebp+4h]
  float ya; // [esp+14h] [ebp+8h]

  if ( !this->m_bCanAcceptInput )
    return 0;
  if ( this->m_ScreenPositions.m_Size == 0 )
    return 0;
  v4 = 0;
  if ( this->m_Geometry.m_Triangles.m_Size <= 0 )
    return 0;
  xa = (float)x;
  ya = (float)y;
  for ( i = 0; ; ++i )
  {
    m_pMemory = this->m_ScreenPositions.m_Memory.m_pMemory;
    v7 = this->m_Geometry.m_Triangles.m_Memory.m_pMemory[i].m_PointIndex[2];
    v11.x = m_pMemory[v7].x;
    v11.y = m_pMemory[v7].y;
    p_x = &m_pMemory[this->m_Geometry.m_Triangles.m_Memory.m_pMemory[i].m_PointIndex[0]].x;
    v10.x = *p_x;
    v10.y = p_x[1];
    if ( PointTriangleHitTest(
           tringleVert0: v10,
           tringleVert1: m_pMemory[this->m_Geometry.m_Triangles.m_Memory.m_pMemory[i].m_PointIndex[1]],
           tringleVert2: v11,
           point: (Vector2D)__PAIR64__(LODWORD(ya), LODWORD(xa))) )
    {
      break;
    }
    if ( ++v4 >= this->m_Geometry.m_Triangles.m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00421C20
// Name: public: virtual CHitArea::~CHitArea(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHitArea::~CHitArea(CHitArea *this)
{
  bool v2; // sf

  this->__vftable = (CHitArea_vtbl *)&CHitArea::`vftable';
  CInputGameUI::PanelDeleted(this: g_pInputGameUI, focus: this);
  v2 = this->m_OnMouseLeftClickedScriptCommand.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_OnMouseLeftClickedScriptCommand.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_OnMouseLeftClickedScriptCommand.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_OnMouseLeftClickedScriptCommand.m_Storage.m_Memory.m_pMemory);
      this->m_OnMouseLeftClickedScriptCommand.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_OnMouseLeftClickedScriptCommand.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ScreenPositions);
  CGameGraphic::~CGameGraphic(this);
}

//------------------------------------------------------------------------------
// Address: 0x00421D00
// Name: public: CHitArea::CHitArea(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHitArea *__thiscall CHitArea::CHitArea(CHitArea *this, const char *pName)
{
  int v3; // ecx
  int v4; // edx
  int m_Size; // [esp-8h] [ebp-20h]
  int v7; // [esp-8h] [ebp-20h]
  int v8; // [esp-8h] [ebp-20h]
  int v9; // [esp-8h] [ebp-20h]
  CTriangle triangle; // [esp+8h] [ebp-10h] BYREF
  int v11; // [esp+14h] [ebp-4h]

  CGameGraphic::CGameGraphic(this);
  this->__vftable = (CHitArea_vtbl *)&CHitArea::`vftable';
  this->m_ScreenPositions.m_Memory.m_pMemory = nullptr;
  this->m_ScreenPositions.m_Memory.m_nAllocationCount = 0;
  this->m_ScreenPositions.m_Memory.m_nGrowSize = 0;
  this->m_ScreenPositions.m_Size = 0;
  this->m_ScreenPositions.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_OnMouseLeftClickedScriptCommand);
  this->m_bCanAcceptInput = true;
  this->m_bCanStartDragging = false;
  this->m_IsDragging = false;
  this->m_DragStartCursorPos[0] = 0;
  this->m_DragStartCursorPos[1] = 0;
  this->m_DragCurrentCursorPos[0] = 0;
  this->m_DragCurrentCursorPos[1] = 0;
  CUtlString::operator=(this: &this->m_pName, src: pName);
  this->m_Geometry.m_Center.x = 0.0;
  this->m_Geometry.m_Center.y = 0.0;
  this->m_Geometry.m_Scale.x = 0.0;
  this->m_Geometry.m_Scale.y = 0.0;
  this->m_Geometry.m_Rotation = 0.0;
  this->m_Geometry.m_bMaintainAspectRatio = false;
  this->m_Geometry.m_Sublayer = 0;
  this->m_Geometry.m_bVisible = true;
  this->m_CurrentState = -1;
  this->m_bDragEnabled = false;
  CUtlString::operator=(this: &this->m_OnMouseLeftClickedScriptCommand, src: nullptr);
  m_Size = this->m_Geometry.m_RelativePositions.m_Size;
  triangle.m_PointIndex[1] = -1090519040;
  triangle.m_PointIndex[2] = -1090519040;
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
    this: &this->m_Geometry.m_RelativePositions,
    elem: m_Size,
    src: (const Vector2D *)&triangle.m_PointIndex[1]);
  v3 = this->m_Geometry.m_RelativePositions.m_Size;
  triangle.m_PointIndex[1] = 1056964608;
  triangle.m_PointIndex[2] = -1090519040;
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
    this: &this->m_Geometry.m_RelativePositions,
    elem: v3,
    src: (const Vector2D *)&triangle.m_PointIndex[1]);
  v7 = this->m_Geometry.m_RelativePositions.m_Size;
  triangle.m_PointIndex[1] = 1056964608;
  triangle.m_PointIndex[2] = 1056964608;
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
    this: &this->m_Geometry.m_RelativePositions,
    elem: v7,
    src: (const Vector2D *)&triangle.m_PointIndex[1]);
  v4 = this->m_Geometry.m_RelativePositions.m_Size;
  triangle.m_PointIndex[1] = -1090519040;
  triangle.m_PointIndex[2] = 1056964608;
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
    this: &this->m_Geometry.m_RelativePositions,
    elem: v4,
    src: (const Vector2D *)&triangle.m_PointIndex[1]);
  triangle.m_PointIndex[1] = 0;
  triangle.m_PointIndex[2] = 1;
  v8 = this->m_Geometry.m_Triangles.m_Size;
  v11 = 2;
  CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
    this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Geometry.m_Triangles,
    elem: v8,
    src: (const CVTFTexture::ResourceMemorySection *)&triangle.m_PointIndex[1]);
  v9 = this->m_Geometry.m_Triangles.m_Size;
  triangle.m_PointIndex[1] = 0;
  triangle.m_PointIndex[2] = 2;
  v11 = 3;
  CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
    this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Geometry.m_Triangles,
    elem: v9,
    src: (const CVTFTexture::ResourceMemorySection *)&triangle.m_PointIndex[1]);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00421EC0
// Name: public: bool CHitArea::Unserialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHitArea::Unserialize(CHitArea *this, CDmxElement *pGraphic)
{
  CDmxElement *v2; // esi
  CDmxAttribute *Attribute; // eax
  int v5; // esi
  const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *v6; // ebx
  int m_Size; // ebp
  CGeometry *p_m_Geometry; // edi
  int *v9; // eax
  CDmxAttribute *v10; // eax
  int v11; // esi
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *v12; // ebx
  int v13; // ebp
  const CDmxAttribute *v14; // eax
  CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *m_pData; // eax
  int *p_m_nDataAllocSize; // eax
  int v17; // ecx
  int v18; // edx
  CDmxAttribute *v19; // eax
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *v20; // ebp
  int v21; // ebx
  int v22; // esi
  CAnimData *v23; // eax
  CDmxElement *v24; // edi
  int v26; // [esp-10h] [ebp-28h]
  int v27; // [esp-10h] [ebp-28h]
  CDmxElement *v28; // [esp-Ch] [ebp-24h]
  CTriangle triangle; // [esp+8h] [ebp-10h] BYREF
  int v30; // [esp+14h] [ebp-4h]

  v2 = pGraphic;
  triangle.m_PointIndex[0] = (int)this;
  CDmxElement::UnpackIntoStructure(this: pGraphic, pData: this, pUnpack: s_HitAreaUnpack);
  Attribute = (CDmxAttribute *)CDmxElement::GetAttribute(this: v2, pAttributeName: "relativepositions");
  v5 = 0;
  if ( Attribute == nullptr || Attribute->m_Type != AT_VECTOR2_ARRAY )
    return 0;
  v6 = CDmxAttribute::GetArray<Vector2D>(this: Attribute);
  m_Size = v6->m_Size;
  p_m_Geometry = &this->m_Geometry;
  p_m_Geometry->m_RelativePositions.m_Size = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v9 = (int *)&v6->m_Memory.m_pMemory[v5];
      triangle.m_PointIndex[1] = *v9;
      v26 = p_m_Geometry->m_RelativePositions.m_Size;
      triangle.m_PointIndex[2] = v9[1];
      CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
        this: &p_m_Geometry->m_RelativePositions,
        elem: v26,
        src: (const Vector2D *)&triangle.m_PointIndex[1]);
      ++v5;
    }
    while ( v5 < m_Size );
  }
  v10 = (CDmxAttribute *)CDmxElement::GetAttribute(this: pGraphic, pAttributeName: "triangles");
  v11 = 0;
  if ( v10 != nullptr && v10->m_Type == AT_FIRST_ARRAY_TYPE )
  {
    v12 = CDmxAttribute::GetArray<CDmxElement *>(this: v10);
    v13 = v12->m_Size;
    *(_DWORD *)(triangle.m_PointIndex[0] + 100) = 0;
    if ( v13 > 0 )
    {
      do
      {
        v14 = CDmxElement::GetAttribute(this: v12->m_Memory.m_pMemory[v11], pAttributeName: "positionindexes");
        if ( v14->m_Type == AT_INT_ARRAY )
        {
          m_pData = (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)v14->m_pData;
        }
        else
        {
          if ( (`CDmxAttribute::GetArray<int>'::`4'::`local static guard' & 1) == 0 )
          {
            `CDmxAttribute::GetArray<int>'::`4'::`local static guard' |= 1u;
            `CDmxAttribute::GetArray<int>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
            `CDmxAttribute::GetArray<int>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
            `CDmxAttribute::GetArray<int>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
            `CDmxAttribute::GetArray<int>'::`4'::defaultArray.m_Size = 0;
            `CDmxAttribute::GetArray<int>'::`4'::defaultArray.m_pElements = nullptr;
            atexit(func: `CDmxAttribute::GetArray<int>'::`4'::`dynamic atexit destructor for 'defaultArray'');
          }
          m_pData = &`CDmxAttribute::GetArray<int>'::`4'::defaultArray;
        }
        p_m_nDataAllocSize = &m_pData->m_Memory.m_pMemory->m_nDataAllocSize;
        v17 = p_m_nDataAllocSize[1];
        triangle.m_PointIndex[1] = *p_m_nDataAllocSize;
        v18 = p_m_nDataAllocSize[2];
        triangle.m_PointIndex[2] = v17;
        v27 = *(_DWORD *)(triangle.m_PointIndex[0] + 100);
        v30 = v18;
        CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
          this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)(triangle.m_PointIndex[0] + 88),
          elem: v27,
          src: (const CVTFTexture::ResourceMemorySection *)&triangle.m_PointIndex[1]);
        ++v11;
      }
      while ( v11 < v13 );
    }
    v19 = (CDmxAttribute *)CDmxElement::GetAttribute(this: pGraphic, pAttributeName: "imageanims");
    if ( v19 != nullptr && v19->m_Type == AT_FIRST_ARRAY_TYPE )
    {
      v20 = CDmxAttribute::GetArray<CDmxElement *>(this: v19);
      v21 = v20->m_Size;
      v22 = 0;
      if ( v21 <= 0 )
      {
LABEL_22:
        (*(void (__thiscall **)(int, const char *, int))(*(_DWORD *)triangle.m_PointIndex[0] + 24))(
          a1: triangle.m_PointIndex[0],
          a2: "default",
          a3: 1);
        return 1;
      }
      while ( 1 )
      {
        v23 = (CAnimData *)MemAlloc_Alloc(nSize: 0x140u);
        v24 = v23 != nullptr ? (CDmxElement *)CAnimData::CAnimData(this: v23) : nullptr;
        v28 = v20->m_Memory.m_pMemory[v22];
        pGraphic = v24;
        if ( !CAnimData::Unserialize(this: (CAnimData *)v24, pElement: v28) )
          break;
        CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
          this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)(triangle.m_PointIndex[0] + 332),
          elem: *(_DWORD *)(triangle.m_PointIndex[0] + 344),
          src: (vgui::TreeNode **)&pGraphic);
        if ( ++v22 >= v21 )
          goto LABEL_22;
      }
      if ( v24 != nullptr )
      {
        CAnimData::~CAnimData(this: (CAnimData *)v24);
        free(pMem: v24);
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004220E0
// Name: public: virtual class CGameGraphic __near * CHitAreaClassFactory::CreateNewGraphicClass(class KeyValues __near *,class CGameUIDefinition __near *)
// Source: json
//------------------------------------------------------------------------------
CHitArea *__thiscall CHitAreaClassFactory::CreateNewGraphicClass(
        CHitAreaClassFactory *this,
        KeyValues *kvRequest,
        CGameUIDefinition *pMenu)
{
  CHitArea *v3; // edi
  const char *String; // esi
  CHitArea *v5; // eax
  KeyValues *i; // esi

  v3 = nullptr;
  String = KeyValues::GetString(this: kvRequest, keyName: "name", defaultValue: nullptr);
  if ( String != nullptr )
  {
    v5 = (CHitArea *)MemAlloc_Alloc(nSize: 0x1A4u);
    if ( v5 != nullptr )
      v3 = CHitArea::CHitArea(this: v5, pName: String);
    else
      v3 = nullptr;
    ((void (__thiscall *)(CHitArea *, _DWORD, _DWORD))v3->SetScale)(a1: v3, a2: 100.0, a3: 100.0);
    CGameUIDefinition::AddGraphicToLayer(this: pMenu, pGraphic: v3, nLayerType: 0);
    for ( i = KeyValues::GetFirstSubKey(this: kvRequest); i != nullptr; i = KeyValues::GetNextKey(this: i) )
      v3->HandleScriptCommand(this: v3, a2: i);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00422170
// Name: public: virtual void CHitArea::UpdateRenderData(struct color32_s,class CUtlVector<class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>>,class CUtlMemory<class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>>,int>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHitArea::UpdateRenderData(
        CHitArea *this,
        color32_s parentColor,
        CUtlVector<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,CUtlMemory<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,int> > *renderGeometryLists,
        int firstListIndex)
{
  CGeometry *p_m_Geometry; // ebp
  int v6; // ebx
  CUtlMemory<ResourceEntryInfo,int> *p_m_ScreenPositions; // esi
  float x; // xmm1_4
  ResourceEntryInfo *m_pMemory; // edi
  int m_nAllocationCount; // eax
  ResourceEntryInfo *v11; // ecx
  int v12; // eax
  bool v13; // zf
  int v14; // eax
  matrix3x4_t *nCount; // [esp+8h] [ebp-28h]
  int m_Size; // [esp+Ch] [ebp-24h]
  float y; // [esp+10h] [ebp-20h]
  Vector relativePosition; // [esp+14h] [ebp-1Ch] BYREF
  Vector screenpos; // [esp+20h] [ebp-10h] BYREF

  p_m_Geometry = &this->m_Geometry;
  CGeometry::CalculateExtents(this: &this->m_Geometry);
  if ( this->m_Geometry.m_bVisible )
  {
    v6 = 0;
    p_m_ScreenPositions = (CUtlMemory<ResourceEntryInfo,int> *)&this->m_ScreenPositions;
    m_Size = this->m_Geometry.m_RelativePositions.m_Size;
    this->m_ScreenPositions.m_Size = 0;
    if ( m_Size > 0 )
    {
      nCount = &this->m_Geometry.m_RenderToScreen;
      do
      {
        x = p_m_Geometry->m_RelativePositions.m_Memory.m_pMemory[v6].x;
        relativePosition.z = p_m_Geometry->m_RelativePositions.m_Memory.m_pMemory[v6].y;
        relativePosition.y = x;
        screenpos.x = 0.0;
        VectorTransform(in1: &relativePosition.y, in2: nCount, out: &screenpos.y);
        m_pMemory = p_m_ScreenPositions[1].m_pMemory;
        m_nAllocationCount = p_m_ScreenPositions->m_nAllocationCount;
        y = screenpos.y;
        relativePosition.x = screenpos.z;
        if ( (int)&m_pMemory->eType + 1 > m_nAllocationCount )
          CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>::Grow(
            this: p_m_ScreenPositions,
            num: (int)&m_pMemory->___u0 - m_nAllocationCount + 1);
        ++p_m_ScreenPositions[1].m_pMemory;
        v11 = p_m_ScreenPositions->m_pMemory;
        v12 = (char *)p_m_ScreenPositions[1].m_pMemory - (char *)m_pMemory - 1;
        v13 = (char *)p_m_ScreenPositions[1].m_pMemory - (char *)m_pMemory == 1;
        p_m_ScreenPositions[1].m_nAllocationCount = (int)p_m_ScreenPositions->m_pMemory;
        if ( v12 >= 0 && !v13 )
          _V_memmove(dest: &v11[(int)m_pMemory + 1], src: &v11[(_DWORD)m_pMemory], count: 8 * v12);
        v14 = (int)&p_m_ScreenPositions->m_pMemory[(_DWORD)m_pMemory];
        if ( v14 != 0 )
        {
          *(float *)v14 = y;
          *(float *)(v14 + 4) = relativePosition.x;
        }
        ++v6;
      }
      while ( v6 < m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00533610
// Name: CHitArea_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *CHitArea_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<CHitArea>();
  s_pUnpack_4 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00533620
// Name: _dynamic_initializer_for__s_HitAreaUnpack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__s_HitAreaUnpack__()
{
  s_HitAreaUnpack = s_pUnpack_4;
  return s_pUnpack_4;
}

//------------------------------------------------------------------------------
// Address: 0x00533630
// Name: _dynamic_initializer_for__s_GameLayerUnpack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__s_GameLayerUnpack__()
{
  s_GameLayerUnpack = s_pUnpack_0;
  return s_pUnpack_0;
}

//------------------------------------------------------------------------------
// Address: 0x00533640
// Name: _dynamic_initializer_for__ui_script_error_path__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ui_script_error_path__()
{
  ConVar::ConVar(this: &ui_script_error_path, pName: "ui_script_error_path", pDefaultValue: defaultValue, flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__ui_script_error_path__);
}
