// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/scaleformui/scaleformuiimpl/scaleformuicursorimpl.cpp
// Functions: 10
// ============================================================

#include "materialsystem\scaleformui\scaleformuiimpl\scaleformuicursorimpl.h"

//------------------------------------------------------------------------------
// Address: 0x1000D890
// Name: public: virtual void ScaleformUIImpl::SetCursorViewport(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::SetCursorViewport(ScaleformUIImpl *this, int x, int y, int width, int height)
{
  this->SetSlotViewport(this, a2: 0, a3: x, a4: y, a5: width, a6: height);
}

//------------------------------------------------------------------------------
// Address: 0x1000D8B0
// Name: public: virtual void ScaleformUIImpl::ReleaseCursor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::ReleaseCursor(ScaleformUIImpl *this)
{
  this->SlotRelease(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000D8C0
// Name: public: virtual bool ScaleformUIImpl::IsCursorVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ScaleformUIImpl::IsCursorVisible(ScaleformUIImpl *this)
{
  bool v2; // bl
  BaseSlot *v3; // eax

  v2 = false;
  v3 = ScaleformUIImpl::LockSlotPtr(this, slot: 0);
  if ( v3 != nullptr )
    v2 = v3->__vftable[1].DenyInputToGame(this: v3);
  ScaleformUIImpl::UnlockSlotPtr(this, slotID: 0);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1000D8F0
// Name: public: virtual void ScaleformUIImpl::RenderCursor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::RenderCursor(ScaleformUIImpl *this)
{
  this->RenderSlot(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000D900
// Name: public: virtual void ScaleformUIImpl::SetCursorShape(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::SetCursorShape(ScaleformUIImpl *this, unsigned int shapeIndex)
{
  CursorSlot *v3; // eax

  v3 = (CursorSlot *)ScaleformUIImpl::LockSlotPtr(this, slot: 0);
  if ( v3 != nullptr )
    CursorSlot::SetCursorShape(this: v3, shape: shapeIndex);
  ScaleformUIImpl::UnlockSlotPtr(this, slotID: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000D930
// Name: public: virtual void ScaleformUIImpl::ShowCursor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::ShowCursor(ScaleformUIImpl *this)
{
  CursorSlot *v2; // eax

  v2 = (CursorSlot *)ScaleformUIImpl::LockSlotPtr(this, slot: 0);
  if ( v2 != nullptr )
    CursorSlot::Show(this: v2);
  ScaleformUIImpl::UnlockSlotPtr(this, slotID: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000D950
// Name: public: virtual void ScaleformUIImpl::HideCursor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::HideCursor(ScaleformUIImpl *this)
{
  CursorSlot *v2; // eax

  v2 = (CursorSlot *)ScaleformUIImpl::LockSlotPtr(this, slot: 0);
  if ( v2 != nullptr )
    CursorSlot::Hide(this: v2);
  ScaleformUIImpl::UnlockSlotPtr(this, slotID: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000D970
// Name: public: virtual bool CursorSlot::IsHidden(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CursorSlot::IsHidden(CursorSlot *this)
{
  return this->m_bUIHidden;
}

//------------------------------------------------------------------------------
// Address: 0x1000D980
// Name: public: virtual bool CursorSlot::IsVisible(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CursorSlot::IsVisible(CursorSlot *this)
{
  return !this->m_bUIHidden;
}

//------------------------------------------------------------------------------
// Address: 0x1000D990
// Name: public: virtual void ScaleformUIImpl::InitCursor(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::InitCursor(ScaleformUIImpl *this, const char *cursorMovie)
{
  _RTL_CRITICAL_SECTION *m_SlotMutexes; // ebx
  BaseSlot *v4; // ecx
  BaseSlot *v5; // eax
  CursorSlot *v6; // edi

  m_SlotMutexes = (_RTL_CRITICAL_SECTION *)this->m_SlotMutexes;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)this->m_SlotMutexes);
  v4 = this->m_SlotPtrs[0];
  if ( v4 != nullptr )
  {
    BaseSlot::AddRef(this: v4);
  }
  else
  {
    v5 = (BaseSlot *)MemAlloc_Alloc(nSize: 0x40u);
    v6 = (CursorSlot *)v5;
    if ( v5 != nullptr )
    {
      BaseSlot::BaseSlot(this: v5);
      v6->__vftable = (CursorSlot_vtbl *)&CursorSlot::`vftable';
      v6->m_bUIHidden = true;
    }
    else
    {
      v6 = nullptr;
    }
    this->m_SlotPtrs[0] = v6;
    BaseSlot::Init(this: v6, a2: (int)v6, movieName: cursorMovie, slot: nullptr);
    if ( this->ConsumesInputEvents(this) )
    {
      CursorSlot::Hide(this: v6);
      CursorSlot::Show(this: v6);
    }
    else
    {
      CursorSlot::Show(this: v6);
      CursorSlot::Hide(this: v6);
    }
  }
  LeaveCriticalSection(lpCriticalSection: m_SlotMutexes);
}
