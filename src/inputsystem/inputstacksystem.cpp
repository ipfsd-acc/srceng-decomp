// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: inputsystem/inputstacksystem.cpp
// Functions: 12
// ============================================================

#include "inputsystem\inputstacksystem.h"

//------------------------------------------------------------------------------
// Address: 0x10001010
// Name: public: virtual struct AppSystemInfo_t const __near * CInputStackSystem::GetDependencies(void)
// Source: json
//------------------------------------------------------------------------------
const AppSystemInfo_t *__thiscall CInputStackSystem::GetDependencies(CInputStackSystem *this)
{
  return s_Dependencies;
}

//------------------------------------------------------------------------------
// Address: 0x10001020
// Name: public: virtual void CInputStackSystem::SetCursorPosition(struct InputContextHandle_t__ __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputStackSystem::SetCursorPosition(
        CInputStackSystem *this,
        InputContextHandle_t__ *hContext,
        int x,
        int y)
{
  if ( this->IsTopmostEnabledContext(this, a2: hContext) )
    g_pInputSystem->SetCursorPosition(this: g_pInputSystem, a2: x, a3: y);
}

//------------------------------------------------------------------------------
// Address: 0x100010E0
// Name: public: virtual bool CInputStackSystem::IsTopmostEnabledContext(struct InputContextHandle_t__ __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInputStackSystem::IsTopmostEnabledContext(CInputStackSystem *this, InputContextHandle_t__ *hContext)
{
  int m_Size; // edx
  InputContext_t *v3; // eax

  if ( hContext != nullptr )
  {
    m_Size = this->m_ContextStack.m_Size;
    while ( --m_Size >= 0 )
    {
      v3 = this->m_ContextStack.m_Memory.m_pMemory[m_Size];
      if ( v3->m_bEnabled )
        return v3 == (InputContext_t *)hContext;
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10001120
// Name: private: void CInputStackSystem::UpdateCursorState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputStackSystem::UpdateCursorState(CInputStackSystem *this)
{
  int m_Size; // eax
  InputContext_t *v2; // esi
  IInputSystem_vtbl *v3; // eax
  IInputSystem_vtbl *v4; // esi
  PlatWindow_t__ *v5; // eax

  m_Size = this->m_ContextStack.m_Size;
  while ( --m_Size >= 0 )
  {
    v2 = this->m_ContextStack.m_Memory.m_pMemory[m_Size];
    if ( v2->m_bEnabled )
    {
      v3 = g_pInputSystem->__vftable;
      if ( v2->m_bCursorVisible )
        ((void (__stdcall *)(InputCursorHandle_t__ *))v3->SetCursorIcon)(a1: v2->m_hCursorIcon);
      else
        ((void (__stdcall *)(_DWORD))v3->SetCursorIcon)(a1: 0);
      if ( v2->m_bMouseCaptureEnabled )
      {
        v4 = g_pInputSystem->__vftable;
        v5 = g_pInputSystem->GetAttachedWindow(this: g_pInputSystem);
        v4->EnableMouseCapture(this: g_pInputSystem, a2: v5);
      }
      else
      {
        g_pInputSystem->DisableMouseCapture(this: g_pInputSystem);
      }
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001190
// Name: public: virtual void CInputStackSystem::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputStackSystem::Shutdown(CInputStackSystem *this)
{
  int m_Size; // eax
  InputContext_t *v3; // ecx

  while ( this->m_ContextStack.m_Size != 0 )
  {
    m_Size = this->m_ContextStack.m_Size;
    v3 = this->m_ContextStack.m_Memory.m_pMemory[m_Size - 1];
    this->m_ContextStack.m_Size = m_Size - 1;
    free(pMem: v3);
  }
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x100011D0
// Name: public: virtual void CInputStackSystem::PopInputContext(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputStackSystem::PopInputContext(CInputStackSystem *this)
{
  int m_Size; // eax
  InputContext_t *v3; // ecx

  if ( this->m_ContextStack.m_Size != 0 )
  {
    m_Size = this->m_ContextStack.m_Size;
    v3 = this->m_ContextStack.m_Memory.m_pMemory[m_Size - 1];
    this->m_ContextStack.m_Size = m_Size - 1;
    free(pMem: v3);
    CInputStackSystem::UpdateCursorState(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001200
// Name: public: virtual void CInputStackSystem::EnableInputContext(struct InputContextHandle_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputStackSystem::EnableInputContext(
        CInputStackSystem *this,
        InputContextHandle_t__ *hContext,
        bool bEnable)
{
  if ( hContext != nullptr && *((_BYTE *)hContext + 4) != bEnable )
  {
    if ( !bEnable )
      this->SetMouseCapture(this, a2: hContext, a3: false);
    *((_BYTE *)hContext + 4) = bEnable;
    CInputStackSystem::UpdateCursorState(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001240
// Name: public: virtual void CInputStackSystem::SetCursorVisible(struct InputContextHandle_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputStackSystem::SetCursorVisible(
        CInputStackSystem *this,
        InputContextHandle_t__ *hContext,
        bool bVisible)
{
  if ( hContext != nullptr && *((_BYTE *)hContext + 5) != bVisible )
  {
    *((_BYTE *)hContext + 5) = bVisible;
    CInputStackSystem::UpdateCursorState(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001260
// Name: public: virtual void CInputStackSystem::SetCursorIcon(struct InputContextHandle_t__ __near *,struct InputCursorHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputStackSystem::SetCursorIcon(
        CInputStackSystem *this,
        InputContextHandle_t__ *hContext,
        InputCursorHandle_t__ *hCursor)
{
  if ( hContext != nullptr && *(InputCursorHandle_t__ **)hContext != hCursor )
  {
    *(_DWORD *)hContext = hCursor;
    CInputStackSystem::UpdateCursorState(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001280
// Name: public: virtual void CInputStackSystem::SetMouseCapture(struct InputContextHandle_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputStackSystem::SetMouseCapture(
        CInputStackSystem *this,
        InputContextHandle_t__ *hContext,
        bool bEnable)
{
  if ( hContext != nullptr && *((_BYTE *)hContext + 6) != bEnable )
  {
    *((_BYTE *)hContext + 6) = bEnable;
    CInputStackSystem::UpdateCursorState(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100012A0
// Name: public: virtual struct InputContextHandle_t__ __near * CInputStackSystem::PushInputContext(void)
// Source: json
//------------------------------------------------------------------------------
InputContextHandle_t__ *__thiscall CInputStackSystem::PushInputContext(CInputStackSystem *this)
{
  _WORD *v2; // edi
  InputContext_t **m_pMemory; // eax
  int m_Size; // ecx
  InputContext_t **v5; // eax

  v2 = operator new(nSize: 8u);
  v2[2] = 257;
  *((_BYTE *)v2 + 6) = 0;
  *(_DWORD *)v2 = g_pInputSystem->GetStandardCursor(this: g_pInputSystem, a2: 1);
  if ( this->m_ContextStack.m_Size >= this->m_ContextStack.m_Memory.m_nAllocationCount )
    CUtlMemory<CUtlSymbolTable::StringPool_t *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_ContextStack,
      num: 1);
  ++this->m_ContextStack.m_Size;
  m_pMemory = this->m_ContextStack.m_Memory.m_pMemory;
  m_Size = this->m_ContextStack.m_Size;
  this->m_ContextStack.m_pElements = m_pMemory;
  v5 = &m_pMemory[m_Size - 1];
  if ( v5 != nullptr )
    *v5 = (InputContext_t *)v2;
  CInputStackSystem::UpdateCursorState(this);
  return (InputContextHandle_t__ *)v2;
}

//------------------------------------------------------------------------------
// Address: 0x10001000
// Name: __CreateCInputStackSystemIInputStackSystem_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CInputStackSystem *__cdecl _CreateCInputStackSystemIInputStackSystem_interface()
{
  return &s_InputStackSystem;
}
