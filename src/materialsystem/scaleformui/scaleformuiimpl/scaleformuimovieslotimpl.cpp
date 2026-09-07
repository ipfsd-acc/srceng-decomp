// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/scaleformui/scaleformuiimpl/scaleformuimovieslotimpl.cpp
// Functions: 26
// ============================================================

#include "materialsystem\scaleformui\scaleformuiimpl\scaleformuimovieslotimpl.h"

//------------------------------------------------------------------------------
// Address: 0x10012C00
// Name: protected: void ScaleformUIImpl::InitMovieSlotImpl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::InitMovieSlotImpl(ScaleformUIImpl *this)
{
  _V_memset(dest: this->m_SlotPtrs, fill: 0, count: 16);
}

//------------------------------------------------------------------------------
// Address: 0x10012C20
// Name: protected: class BaseSlot __near * ScaleformUIImpl::LockSlotPtr(int)
// Source: json
//------------------------------------------------------------------------------
BaseSlot *__thiscall ScaleformUIImpl::LockSlotPtr(ScaleformUIImpl *this, int slot)
{
  BaseSlot *v3; // esi

  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_SlotMutexes[slot]);
  v3 = this->m_SlotPtrs[slot];
  if ( v3 != nullptr )
    BaseSlot::AddRef(this: v3);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10012C60
// Name: protected: void ScaleformUIImpl::UnlockSlotPtr(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::UnlockSlotPtr(ScaleformUIImpl *this, int slotID)
{
  BaseSlot *v3; // ecx

  v3 = this->m_SlotPtrs[slotID];
  if ( v3 != nullptr && BaseSlot::Release(this: v3) )
    this->m_SlotPtrs[slotID] = nullptr;
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_SlotMutexes[slotID]);
}

//------------------------------------------------------------------------------
// Address: 0x10012CA0
// Name: public: virtual void ScaleformUIImpl::LockSlot(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::LockSlot(ScaleformUIImpl *this, int slot)
{
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_SlotMutexes[slot]);
}

//------------------------------------------------------------------------------
// Address: 0x10012CC0
// Name: public: virtual void ScaleformUIImpl::UnlockSlot(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::UnlockSlot(ScaleformUIImpl *this, int slot)
{
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_SlotMutexes[slot]);
}

//------------------------------------------------------------------------------
// Address: 0x10012CE0
// Name: public: virtual void ScaleformUIImpl::SlotAddRef(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::SlotAddRef(ScaleformUIImpl *this, int slot)
{
  _RTL_CRITICAL_SECTION *v3; // edi
  BaseSlot *v4; // ecx

  v3 = (_RTL_CRITICAL_SECTION *)&this->m_SlotMutexes[slot];
  EnterCriticalSection(lpCriticalSection: v3);
  v4 = this->m_SlotPtrs[slot];
  if ( v4 != nullptr )
    BaseSlot::AddRef(this: v4);
  LeaveCriticalSection(lpCriticalSection: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10012D20
// Name: public: virtual void ScaleformUIImpl::SlotRelease(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::SlotRelease(ScaleformUIImpl *this, int slot)
{
  _RTL_CRITICAL_SECTION *v3; // ebx
  BaseSlot *v4; // ecx

  v3 = (_RTL_CRITICAL_SECTION *)&this->m_SlotMutexes[slot];
  EnterCriticalSection(lpCriticalSection: v3);
  v4 = this->m_SlotPtrs[slot];
  if ( v4 != nullptr && BaseSlot::Release(this: v4) )
    this->m_SlotPtrs[slot] = nullptr;
  LeaveCriticalSection(lpCriticalSection: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10012D70
// Name: public: virtual void ScaleformUIImpl::InitSlot(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::InitSlot(ScaleformUIImpl *this, int slotID, const char *rootMovie)
{
  _RTL_CRITICAL_SECTION *v4; // ebx
  BaseSlot *v5; // ecx
  MovieSlot *v6; // eax
  MovieSlot *v7; // eax

  v4 = (_RTL_CRITICAL_SECTION *)&this->m_SlotMutexes[slotID];
  EnterCriticalSection(lpCriticalSection: v4);
  v5 = this->m_SlotPtrs[slotID];
  if ( v5 != nullptr )
  {
    BaseSlot::AddRef(this: v5);
  }
  else
  {
    v6 = (MovieSlot *)MemAlloc_Alloc(nSize: 0x40u);
    if ( v6 != nullptr )
      v7 = MovieSlot::MovieSlot(this: v6);
    else
      v7 = nullptr;
    this->m_SlotPtrs[slotID] = v7;
    BaseSlot::Init(
      this: v7,
      a2: slotID,
      movieName: rootMovie,
      slot: (const ScaleformUIFunctionHandlerDefinition *)slotID);
  }
  LeaveCriticalSection(lpCriticalSection: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10012E10
// Name: public: virtual void ScaleformUIImpl::RequestElement(int,char const __near *,class ScaleformUIFunctionHandlerObject __near *,class IScaleformUIFunctionHandlerDefinitionTable const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::RequestElement(
        ScaleformUIImpl *this,
        int slot,
        const char *elementName,
        ScaleformUIFunctionHandlerObject *object,
        const IScaleformUIFunctionHandlerDefinitionTable *tableObject)
{
  BaseSlot *v7; // ebx
  BaseSlot *v8; // ecx
  _RTL_CRITICAL_SECTION *slota; // [esp+14h] [ebp+8h]

  slota = (_RTL_CRITICAL_SECTION *)&this->m_SlotMutexes[slot];
  EnterCriticalSection(lpCriticalSection: slota);
  v7 = this->m_SlotPtrs[slot];
  if ( v7 != nullptr )
  {
    BaseSlot::AddRef(this: this->m_SlotPtrs[slot]);
    v7->RequestElement(this: v7, a2: elementName, a3: object, a4: tableObject);
  }
  v8 = this->m_SlotPtrs[slot];
  if ( v8 != nullptr && BaseSlot::Release(this: v8) )
    this->m_SlotPtrs[slot] = nullptr;
  LeaveCriticalSection(lpCriticalSection: slota);
}

//------------------------------------------------------------------------------
// Address: 0x10012E90
// Name: public: virtual void ScaleformUIImpl::RemoveElement(int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::RemoveElement(ScaleformUIImpl *this, int slot, void *element)
{
  BaseSlot *v5; // ebx
  BaseSlot *v6; // ecx
  _RTL_CRITICAL_SECTION *slota; // [esp+14h] [ebp+8h]

  slota = (_RTL_CRITICAL_SECTION *)&this->m_SlotMutexes[slot];
  EnterCriticalSection(lpCriticalSection: slota);
  v5 = this->m_SlotPtrs[slot];
  if ( v5 != nullptr )
  {
    BaseSlot::AddRef(this: this->m_SlotPtrs[slot]);
    v5->RemoveElement(this: v5, a2: element);
  }
  v6 = this->m_SlotPtrs[slot];
  if ( v6 != nullptr && BaseSlot::Release(this: v6) )
    this->m_SlotPtrs[slot] = nullptr;
  LeaveCriticalSection(lpCriticalSection: slota);
}

//------------------------------------------------------------------------------
// Address: 0x10012F00
// Name: public: virtual void ScaleformUIImpl::SetSlotViewport(int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::SetSlotViewport(ScaleformUIImpl *this, int slot, int x, int y, int width, int height)
{
  BaseSlot *v8; // edi
  int m_iScreenHeight; // edx
  int m_iScreenWidth; // ecx
  GFxMovieView *m_pMovieView; // edi
  void (__thiscall *SetViewport)(GFxMovieView *, const GViewport *); // edx
  BaseSlot *v13; // ecx
  _DWORD v14[13]; // [esp+Ch] [ebp-34h] BYREF
  _RTL_CRITICAL_SECTION *slota; // [esp+48h] [ebp+8h]

  slota = (_RTL_CRITICAL_SECTION *)&this->m_SlotMutexes[slot];
  EnterCriticalSection(lpCriticalSection: slota);
  v8 = this->m_SlotPtrs[slot];
  if ( v8 != nullptr )
  {
    BaseSlot::AddRef(this: this->m_SlotPtrs[slot]);
    m_iScreenHeight = this->m_iScreenHeight;
    m_iScreenWidth = this->m_iScreenWidth;
    m_pMovieView = v8->m_pMovieView;
    v14[2] = x;
    v14[1] = m_iScreenHeight;
    v14[5] = height;
    v14[0] = m_iScreenWidth;
    v14[4] = width;
    SetViewport = m_pMovieView->SetViewport;
    v14[12] = 0;
    memset(&v14[6], 0, 16);
    v14[3] = y;
    v14[11] = 1065353216;
    v14[10] = 1065353216;
    SetViewport(this: m_pMovieView, a2: (const GViewport *)v14);
  }
  v13 = this->m_SlotPtrs[slot];
  if ( v13 != nullptr && BaseSlot::Release(this: v13) )
    this->m_SlotPtrs[slot] = nullptr;
  LeaveCriticalSection(lpCriticalSection: slota);
}

//------------------------------------------------------------------------------
// Address: 0x10012FD0
// Name: public: virtual void ScaleformUIImpl::RenderSlot(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::RenderSlot(ScaleformUIImpl *this, int slot)
{
  unsigned int v4; // ecx
  BaseSlot *v5; // ebx
  GFxAmpServer *Instance; // eax
  BaseSlot *v7; // ecx
  void *(__cdecl **v8)(const char *, int *); // [esp+0h] [ebp-Ch]
  void *(__cdecl **v9)(const char *, int *); // [esp+0h] [ebp-Ch]
  void *(__cdecl **v10)(const char *, int *); // [esp+0h] [ebp-Ch]
  int v11; // [esp+4h] [ebp-8h]
  int v12; // [esp+4h] [ebp-8h]
  int v13; // [esp+4h] [ebp-8h]
  _RTL_CRITICAL_SECTION *slota; // [esp+14h] [ebp+8h]

  CDummyMaterialSystem::EndBatch(pFactoryList: v8, nFactoryCount: v11);
  CDummyMaterialSystem::EndBatch(pFactoryList: v9, nFactoryCount: v12);
  slota = (_RTL_CRITICAL_SECTION *)&this->m_SlotMutexes[slot];
  EnterCriticalSection(lpCriticalSection: slota);
  v5 = this->m_SlotPtrs[slot];
  if ( v5 != nullptr )
    BaseSlot::AddRef(this: this->m_SlotPtrs[slot]);
  if ( slot == 1 && this->m_bPumpScaleformStats )
  {
    Instance = (GFxAmpServer *)GFxAmpServer::GetInstance(a1: v4);
    GFxAmpServer::AdvanceFrame(this: Instance);
  }
  if ( v5 != nullptr )
    v5->m_pMovieView->Display(this: v5->m_pMovieView);
  v7 = this->m_SlotPtrs[slot];
  if ( v7 != nullptr && BaseSlot::Release(this: v7) )
    this->m_SlotPtrs[slot] = nullptr;
  LeaveCriticalSection(lpCriticalSection: slota);
  CDummyMaterialSystem::EndBatch(pFactoryList: v10, nFactoryCount: v13);
}

//------------------------------------------------------------------------------
// Address: 0x10013080
// Name: protected: void ScaleformUIImpl::AdvanceSlot(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::AdvanceSlot(ScaleformUIImpl *this, int slot, float time)
{
  BaseSlot *v5; // ebx
  BaseSlot *v6; // ecx
  _RTL_CRITICAL_SECTION *slota; // [esp+1Ch] [ebp+8h]

  slota = (_RTL_CRITICAL_SECTION *)&this->m_SlotMutexes[slot];
  EnterCriticalSection(lpCriticalSection: slota);
  v5 = this->m_SlotPtrs[slot];
  if ( v5 != nullptr )
  {
    BaseSlot::AddRef(this: this->m_SlotPtrs[slot]);
    ((void (__thiscall *)(GFxMovieView *, _DWORD, int))v5->m_pMovieView->Advance)(
      a1: v5->m_pMovieView,
      a2: LODWORD(time),
      a3: 2);
  }
  v6 = this->m_SlotPtrs[slot];
  if ( v6 != nullptr && BaseSlot::Release(this: v6) )
    this->m_SlotPtrs[slot] = nullptr;
  LeaveCriticalSection(lpCriticalSection: slota);
}

//------------------------------------------------------------------------------
// Address: 0x10013110
// Name: public: virtual bool ScaleformUIImpl::SlotConsumesInputEvents(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ScaleformUIImpl::SlotConsumesInputEvents(ScaleformUIImpl *this, int slot)
{
  BaseSlot *v4; // edi
  BaseSlot *v5; // ecx
  bool v7; // [esp+Fh] [ebp-1h]
  _RTL_CRITICAL_SECTION *slota; // [esp+18h] [ebp+8h]

  v7 = false;
  slota = (_RTL_CRITICAL_SECTION *)&this->m_SlotMutexes[slot];
  EnterCriticalSection(lpCriticalSection: slota);
  v4 = this->m_SlotPtrs[slot];
  if ( v4 != nullptr )
  {
    BaseSlot::AddRef(this: this->m_SlotPtrs[slot]);
    v7 = v4->ConsumesInputEvents(this: v4);
  }
  v5 = this->m_SlotPtrs[slot];
  if ( v5 != nullptr && BaseSlot::Release(this: v5) )
    this->m_SlotPtrs[slot] = nullptr;
  LeaveCriticalSection(lpCriticalSection: slota);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10013190
// Name: public: virtual bool ScaleformUIImpl::SlotDeniesInputToGame(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall ScaleformUIImpl::SlotDeniesInputToGame(ScaleformUIImpl *this, int slot)
{
  BaseSlot *v5; // edi
  BaseSlot *v6; // ecx
  bool v7; // [esp+7h] [ebp-1h]
  _RTL_CRITICAL_SECTION *slota; // [esp+10h] [ebp+8h]

  if ( this->m_bDenyAllInputToGame )
    return 1;
  v7 = false;
  slota = (_RTL_CRITICAL_SECTION *)&this->m_SlotMutexes[slot];
  EnterCriticalSection(lpCriticalSection: slota);
  v5 = this->m_SlotPtrs[slot];
  if ( v5 != nullptr )
  {
    BaseSlot::AddRef(this: this->m_SlotPtrs[slot]);
    v7 = v5->DenyInputToGame(this: v5);
  }
  v6 = this->m_SlotPtrs[slot];
  if ( v6 != nullptr && BaseSlot::Release(this: v6) )
    this->m_SlotPtrs[slot] = nullptr;
  LeaveCriticalSection(lpCriticalSection: slota);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10013220
// Name: protected: bool ScaleformUIImpl::AnalogStickNavigationDisabled(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ScaleformUIImpl::AnalogStickNavigationDisabled(ScaleformUIImpl *this, int slot)
{
  BaseSlot *v4; // edi
  MovieSlot *v5; // eax
  BaseSlot *v6; // ecx
  bool v8; // [esp+Fh] [ebp-1h]
  _RTL_CRITICAL_SECTION *slota; // [esp+18h] [ebp+8h]

  v8 = false;
  slota = (_RTL_CRITICAL_SECTION *)&this->m_SlotMutexes[slot];
  EnterCriticalSection(lpCriticalSection: slota);
  v4 = this->m_SlotPtrs[slot];
  if ( v4 != nullptr )
  {
    BaseSlot::AddRef(this: this->m_SlotPtrs[slot]);
    v5 = (MovieSlot *)__RTDynamicCast(
                        inptr: v4,
                        VfDelta: 0,
                        SrcType: &BaseSlot `RTTI Type Descriptor',
                        TargetType: &MovieSlot `RTTI Type Descriptor',
                        isReference: 0);
    if ( v5 != nullptr )
      v8 = MovieSlot::AnalogStickNavigationDisabled(this: v5);
  }
  v6 = this->m_SlotPtrs[slot];
  if ( v6 != nullptr && BaseSlot::Release(this: v6) )
    this->m_SlotPtrs[slot] = nullptr;
  LeaveCriticalSection(lpCriticalSection: slota);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x100132C0
// Name: public: void ScaleformUIImpl::UpdateSafeZone(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::UpdateSafeZone(ScaleformUIImpl *this)
{
  _RTL_CRITICAL_SECTION *v1; // edi
  BaseSlot **v2; // esi
  BaseSlot *v3; // ebx
  int i; // [esp+Ch] [ebp-4h]

  v1 = (_RTL_CRITICAL_SECTION *)&this->m_SlotMutexes[1];
  v2 = &this->m_SlotPtrs[1];
  for ( i = 3; i != 0; --i )
  {
    EnterCriticalSection(lpCriticalSection: v1);
    v3 = *v2;
    if ( *v2 != nullptr )
    {
      BaseSlot::AddRef(this: *v2);
      BaseSlot::UpdateSafeZone(this: v3);
    }
    if ( *v2 != nullptr && BaseSlot::Release(this: *v2) )
      *v2 = nullptr;
    LeaveCriticalSection(lpCriticalSection: v1);
    ++v2;
    v1 = (_RTL_CRITICAL_SECTION *)((char *)v1 + 32);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013330
// Name: public: void ScaleformUIImpl::UpdateTint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::UpdateTint(ScaleformUIImpl *this)
{
  _RTL_CRITICAL_SECTION *v1; // edi
  BaseSlot **v2; // esi
  BaseSlot *v3; // ebx
  int i; // [esp+Ch] [ebp-4h]

  v1 = (_RTL_CRITICAL_SECTION *)&this->m_SlotMutexes[1];
  v2 = &this->m_SlotPtrs[1];
  for ( i = 3; i != 0; --i )
  {
    EnterCriticalSection(lpCriticalSection: v1);
    v3 = *v2;
    if ( *v2 != nullptr )
    {
      BaseSlot::AddRef(this: *v2);
      BaseSlot::UpdateTint(this: v3);
    }
    if ( *v2 != nullptr && BaseSlot::Release(this: *v2) )
      *v2 = nullptr;
    LeaveCriticalSection(lpCriticalSection: v1);
    ++v2;
    v1 = (_RTL_CRITICAL_SECTION *)((char *)v1 + 32);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100133A0
// Name: public: virtual bool ScaleformUIImpl::ConsumesInputEvents(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ScaleformUIImpl::ConsumesInputEvents(ScaleformUIImpl *this)
{
  bool result; // al
  int v3; // esi

  if ( this->m_bDenyAllInputToGame )
    return true;
  v3 = 1;
  while ( 1 )
  {
    result = this->SlotConsumesInputEvents(this, a2: v3);
    if ( result )
      break;
    if ( ++v3 >= 4 )
      return result;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x100133E0
// Name: public: virtual void ScaleformUIImpl::DenyInputToGame(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::DenyInputToGame(ScaleformUIImpl *this, bool value)
{
  this->m_bDenyAllInputToGame = value;
}

//------------------------------------------------------------------------------
// Address: 0x100133F0
// Name: public: virtual void __near * ScaleformUIImpl::CreateNewObject(int)
// Source: json
//------------------------------------------------------------------------------
GFxValue *__thiscall ScaleformUIImpl::CreateNewObject(ScaleformUIImpl *this, int slot)
{
  int v2; // ebx
  BaseSlot *v4; // edi
  GFxMovieView *m_pMovieView; // edi
  GFxValue *GFxValue; // ebx
  GFxValue *v7; // edi
  BaseSlot *v8; // ecx
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+Ch] [ebp-8h]

  v2 = slot;
  lpCriticalSection = (_RTL_CRITICAL_SECTION *)&this->m_SlotMutexes[slot];
  EnterCriticalSection(lpCriticalSection);
  v4 = this->m_SlotPtrs[slot];
  if ( v4 != nullptr )
  {
    BaseSlot::AddRef(this: this->m_SlotPtrs[slot]);
    m_pMovieView = v4->m_pMovieView;
    GFxValue = ScaleformUIImpl::CreateGFxValue(this, pValue: nullptr);
    m_pMovieView->CreateObject(this: m_pMovieView, a2: GFxValue, a3: nullptr, a4: nullptr, a5: 0);
    v7 = GFxValue;
    v2 = slot;
  }
  else
  {
    v7 = nullptr;
  }
  v8 = this->m_SlotPtrs[v2];
  if ( v8 != nullptr && BaseSlot::Release(this: v8) )
    this->m_SlotPtrs[v2] = nullptr;
  LeaveCriticalSection(lpCriticalSection);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10013490
// Name: public: virtual void __near * ScaleformUIImpl::CreateNewArray(int,int)
// Source: json
//------------------------------------------------------------------------------
GFxValue *__thiscall ScaleformUIImpl::CreateNewArray(ScaleformUIImpl *this, int slot, unsigned int size)
{
  int v3; // ebx
  BaseSlot *v5; // edi
  GFxMovieView *m_pMovieView; // edi
  GFxValue *GFxValue; // ebx
  GFxValue *v8; // edi
  BaseSlot *v9; // ecx
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+Ch] [ebp-8h]

  v3 = slot;
  lpCriticalSection = (_RTL_CRITICAL_SECTION *)&this->m_SlotMutexes[slot];
  EnterCriticalSection(lpCriticalSection);
  v5 = this->m_SlotPtrs[slot];
  if ( v5 != nullptr )
  {
    BaseSlot::AddRef(this: this->m_SlotPtrs[slot]);
    m_pMovieView = v5->m_pMovieView;
    GFxValue = ScaleformUIImpl::CreateGFxValue(this, pValue: nullptr);
    m_pMovieView->CreateArray(this: m_pMovieView, a2: GFxValue);
    if ( size != -1 )
      GFxValue::ObjectInterface::SetArraySize(
        this: GFxValue->pObjectInterface,
        a2: GFxValue->Value.pStringManaged,
        a3: size);
    v8 = GFxValue;
    v3 = slot;
  }
  else
  {
    v8 = nullptr;
  }
  v9 = this->m_SlotPtrs[v3];
  if ( v9 != nullptr && BaseSlot::Release(this: v9) )
    this->m_SlotPtrs[v3] = nullptr;
  LeaveCriticalSection(lpCriticalSection);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10013540
// Name: public: virtual void __near * ScaleformUIImpl::CreateNewString(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
GFxValue *__thiscall ScaleformUIImpl::CreateNewString(ScaleformUIImpl *this, int slot, const char *value)
{
  int v3; // ebx
  BaseSlot *v5; // edi
  GFxMovieView *m_pMovieView; // edi
  GFxValue *GFxValue; // ebx
  GFxValue *v8; // edi
  BaseSlot *v9; // ecx
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+Ch] [ebp-8h]

  v3 = slot;
  lpCriticalSection = (_RTL_CRITICAL_SECTION *)&this->m_SlotMutexes[slot];
  EnterCriticalSection(lpCriticalSection);
  v5 = this->m_SlotPtrs[slot];
  if ( v5 != nullptr )
  {
    BaseSlot::AddRef(this: this->m_SlotPtrs[slot]);
    m_pMovieView = v5->m_pMovieView;
    GFxValue = ScaleformUIImpl::CreateGFxValue(this, pValue: nullptr);
    m_pMovieView->CreateString(this: m_pMovieView, a2: GFxValue, a3: value);
    v8 = GFxValue;
    v3 = slot;
  }
  else
  {
    v8 = nullptr;
  }
  v9 = this->m_SlotPtrs[v3];
  if ( v9 != nullptr && BaseSlot::Release(this: v9) )
    this->m_SlotPtrs[v3] = nullptr;
  LeaveCriticalSection(lpCriticalSection);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x100135E0
// Name: public: virtual void __near * ScaleformUIImpl::CreateNewString(int,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
GFxValue *__thiscall ScaleformUIImpl::CreateNewString(ScaleformUIImpl *this, int slot, const wchar_t *value)
{
  int v3; // ebx
  BaseSlot *v5; // edi
  GFxMovieView *m_pMovieView; // edi
  GFxValue *GFxValue; // ebx
  GFxValue *v8; // edi
  BaseSlot *v9; // ecx
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+Ch] [ebp-8h]

  v3 = slot;
  lpCriticalSection = (_RTL_CRITICAL_SECTION *)&this->m_SlotMutexes[slot];
  EnterCriticalSection(lpCriticalSection);
  v5 = this->m_SlotPtrs[slot];
  if ( v5 != nullptr )
  {
    BaseSlot::AddRef(this: this->m_SlotPtrs[slot]);
    m_pMovieView = v5->m_pMovieView;
    GFxValue = ScaleformUIImpl::CreateGFxValue(this, pValue: nullptr);
    m_pMovieView->CreateStringW(this: m_pMovieView, a2: GFxValue, a3: value);
    v8 = GFxValue;
    v3 = slot;
  }
  else
  {
    v8 = nullptr;
  }
  v9 = this->m_SlotPtrs[v3];
  if ( v9 != nullptr && BaseSlot::Release(this: v9) )
    this->m_SlotPtrs[v3] = nullptr;
  LeaveCriticalSection(lpCriticalSection);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10013680
// Name: public: virtual void ScaleformUIImpl::LockInputToSlot(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::LockInputToSlot(ScaleformUIImpl *this, unsigned int slot)
{
  _RTL_CRITICAL_SECTION *v3; // ebx
  BaseSlot *v4; // edi
  BaseSlot *v5; // ecx

  v3 = (_RTL_CRITICAL_SECTION *)&this->m_SlotMutexes[1];
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_SlotMutexes[1]);
  v4 = this->m_SlotPtrs[1];
  if ( v4 != nullptr )
  {
    BaseSlot::AddRef(this: this->m_SlotPtrs[1]);
    BaseSlot::LockInputToSlot(this: v4, slot);
  }
  v5 = this->m_SlotPtrs[1];
  if ( v5 != nullptr && BaseSlot::Release(this: v5) )
    this->m_SlotPtrs[1] = nullptr;
  LeaveCriticalSection(lpCriticalSection: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100136E0
// Name: public: virtual void ScaleformUIImpl::UnlockInput(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::UnlockInput(ScaleformUIImpl *this)
{
  _RTL_CRITICAL_SECTION *v2; // ebx
  BaseSlot *v3; // edi
  BaseSlot *v4; // ecx

  v2 = (_RTL_CRITICAL_SECTION *)&this->m_SlotMutexes[1];
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_SlotMutexes[1]);
  v3 = this->m_SlotPtrs[1];
  if ( v3 != nullptr )
  {
    BaseSlot::AddRef(this: this->m_SlotPtrs[1]);
    BaseSlot::UnlockInput(this: v3);
  }
  v4 = this->m_SlotPtrs[1];
  if ( v4 != nullptr && BaseSlot::Release(this: v4) )
    this->m_SlotPtrs[1] = nullptr;
  LeaveCriticalSection(lpCriticalSection: v2);
}
