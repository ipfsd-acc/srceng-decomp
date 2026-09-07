// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/scaleformui/scaleformuiimpl/movieslot.cpp
// Functions: 63
// ============================================================

#include "materialsystem\scaleformui\scaleformuiimpl\movieslot.h"

//------------------------------------------------------------------------------
// Address: 0x100057F0
// Name: protected: void GFxValue::AcquireManagedValue(class GFxValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxValue::AcquireManagedValue(GFxValue *this, const GFxValue *src)
{
  CStringPool *pObjectInterface; // ecx

  pObjectInterface = (CStringPool *)src->pObjectInterface;
  this->pObjectInterface = src->pObjectInterface;
  GFxValue::ObjectInterface::ObjectAddRef(this: pObjectInterface, val: (StringPoolCase_t)this);
}

//------------------------------------------------------------------------------
// Address: 0x10005840
// Name: public: static unsigned __int64 DLCHelper::GetInstalledDLCMask(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DLCHelper::GetInstalledDLCMask()
{
  int (__thiscall *IsAnyDLCPresent)(IFileSystem *, bool *); // eax
  int v1; // edi
  int v2; // esi
  __int64 v3; // kr00_8
  __int64 uiDlcHeader; // [esp+Ch] [ebp-Ch] BYREF
  bool bSearchPath; // [esp+17h] [ebp-1h] BYREF

  bSearchPath = false;
  IsAnyDLCPresent = g_pFullFileSystem->IsAnyDLCPresent;
  uiDlcHeader = 0;
  v1 = IsAnyDLCPresent(this: g_pFullFileSystem, a2: &bSearchPath);
  if ( !bSearchPath )
    g_pFullFileSystem->AddDLCSearchPaths(this: g_pFullFileSystem);
  v2 = 0;
  if ( v1 <= 0 )
    return uiDlcHeader;
  v3 = uiDlcHeader;
  do
  {
    HIDWORD(uiDlcHeader) = 0;
    if ( g_pFullFileSystem->GetAnyDLCInfo(
           this: g_pFullFileSystem,
           a2: v2,
           a3: (unsigned int *)((char *)&uiDlcHeader + 4),
           a4: nullptr,
           a5: 0)
      && (unsigned int)(HIBYTE(HIDWORD(uiDlcHeader)) - 1) <= 0x1D )
    {
      v3 |= 1LL << SHIBYTE(uiDlcHeader);
    }
    ++v2;
  }
  while ( v2 < v1 );
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100058F0
// Name: public: static void DLCHelper::AppendDLCKeyValues(class KeyValues __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DLCHelper::AppendDLCKeyValues(KeyValues *pKeyValues, const char *fileName, const char *startDir)
{
  unsigned __int64 v3; // rax
  char *v4; // eax
  KeyValues *v5; // ebx
  int v6; // eax
  int v7; // esi
  bool v8; // zf
  int v9; // edi
  IBaseFileSystem *v10; // eax
  unsigned int v11; // et0
  char dlcFileName[128]; // [esp+0h] [ebp-A0h] BYREF
  unsigned __int64 i; // [esp+80h] [ebp-20h]
  unsigned __int64 installedDlc; // [esp+88h] [ebp-18h]
  const char *extension; // [esp+90h] [ebp-10h]
  int v16; // [esp+9Ch] [ebp-4h]

  LODWORD(v3) = DLCHelper::GetInstalledDLCMask();
  installedDlc = v3;
  if ( v3 != 0 )
  {
    v4 = (char *)KeyValues::operator new(iAllocSize: 0x24u);
    extension = v4;
    v16 = 0;
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: (KeyValues *)v4, setName: (const char *)&pMem);
    else
      v5 = nullptr;
    v16 = -1;
    memset(dlcFileName, 0, sizeof(dlcFileName));
    v6 = _V_strlen(str: fileName);
    v7 = v6 - 1;
    v8 = v6 == 1;
    if ( v6 - 1 > 0 )
    {
      do
      {
        if ( fileName[v7] == 46 )
          break;
        --v7;
      }
      while ( v7 > 0 );
      v8 = v7 == 0;
    }
    if ( v8 )
    {
      _Warning(a1: "Invalid file name passed to DLCHelper::AppendDLCKeyValues (%s)\n", fileName);
    }
    else
    {
      extension = &fileName[v7 + 1];
      V_strncpy(pDest: dlcFileName, pSrc: fileName, maxLen: 128);
      v9 = 1;
      HIDWORD(i) = 0;
      do
      {
        if ( (installedDlc & (1LL << v9)) != 0 )
        {
          V_snprintf(pDest: &dlcFileName[v7], maxLen: 128 - v7, pFormat: "_dlc%d.%s", v9, extension);
          KeyValues::Clear(this: v5);
          if ( g_pFullFileSystem != nullptr )
            v10 = &g_pFullFileSystem->IBaseFileSystem;
          else
            v10 = nullptr;
          if ( KeyValues::LoadFromFile(
                 this: v5,
                 filesystem: v10,
                 resourceName: dlcFileName,
                 pathID: startDir,
                 pfnEvaluateSymbolProc: nullptr) )
          {
            KeyValues::MergeFrom(this: pKeyValues, kvMerge: v5, eOp: MERGE_KV_UPDATE);
          }
          else
          {
            _Warning(a1: "Failed to load %s\n", dlcFileName);
          }
        }
        v11 = (__PAIR64__(HIDWORD(i), v9++) + 1) >> 32;
        HIDWORD(i) = v11;
      }
      while ( __PAIR64__(v11, v9) < 0x40 );
      if ( v5 != nullptr )
        KeyValues::deleteThis(this: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005AA0
// Name: public: virtual FlashObjectVisitor::~FlashObjectVisitor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FlashObjectVisitor::~FlashObjectVisitor(FlashObjectVisitor *this)
{
  this->__vftable = (FlashObjectVisitor_vtbl *)&GFxValue::ObjectInterface::ObjVisitor::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10005AB0
// Name: public: void BaseSlot::UpdateSafeZone(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BaseSlot::UpdateSafeZone(BaseSlot *this)
{
  GFxValue::ObjectInterface::Invoke(
    this: this->m_GlobalValue.pObjectInterface,
    a2: this->m_GlobalValue.Value.pStringManaged,
    a3: nullptr,
    a4: (const char *)&pMem.m_Memory.m_nAllocationCount,
    a5: nullptr,
    a6: 0,
    a7: (this->m_GlobalValue.Type & 0x8F) == 8);
}

//------------------------------------------------------------------------------
// Address: 0x10005AE0
// Name: public: void BaseSlot::UpdateTint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BaseSlot::UpdateTint(BaseSlot *this)
{
  GFxValue::ObjectInterface::Invoke(
    this: this->m_GlobalValue.pObjectInterface,
    a2: this->m_GlobalValue.Value.pStringManaged,
    a3: nullptr,
    a4: "UpdateTint",
    a5: nullptr,
    a6: 0,
    a7: (this->m_GlobalValue.Type & 0x8F) == 8);
}

//------------------------------------------------------------------------------
// Address: 0x10005B10
// Name: public: void BaseSlot::UnlockInput(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BaseSlot::UnlockInput(BaseSlot *this)
{
  GFxValue::ObjectInterface::Invoke(
    this: this->m_GlobalValue.pObjectInterface,
    a2: this->m_GlobalValue.Value.pStringManaged,
    a3: nullptr,
    a4: "UnlockInput",
    a5: nullptr,
    a6: 0,
    a7: (this->m_GlobalValue.Type & 0x8F) == 8);
}

//------------------------------------------------------------------------------
// Address: 0x10005B40
// Name: public: void BaseSlot::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BaseSlot::AddRef(BaseSlot *this)
{
  ++this->m_iRefCount;
}

//------------------------------------------------------------------------------
// Address: 0x10005B50
// Name: public: virtual struct ScaleformUIFunctionHandlerDefinition const __near * MovieSlot::GetSlotAPITable(void)
// Source: json
//------------------------------------------------------------------------------
const ScaleformUIFunctionHandlerDefinition *__thiscall MovieSlot::GetSlotAPITable(MovieSlot *this)
{
  return rootGameAPITable;
}

//------------------------------------------------------------------------------
// Address: 0x10005B60
// Name: public: void MovieSlot::AddInputConsumer(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MovieSlot::AddInputConsumer(MovieSlot *this, IScaleformUI *pui, IScaleformUI *params)
{
  ++this->m_iNumInputConsumers;
}

//------------------------------------------------------------------------------
// Address: 0x10005B70
// Name: public: void MovieSlot::RemoveInputConsumer(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MovieSlot::RemoveInputConsumer(MovieSlot *this, IScaleformUI *pui, IScaleformUI *params)
{
  int m_iNumInputConsumers; // eax

  m_iNumInputConsumers = this->m_iNumInputConsumers;
  if ( m_iNumInputConsumers <= 1 )
    m_iNumInputConsumers = 0;
  this->m_iNumInputConsumers = m_iNumInputConsumers;
}

//------------------------------------------------------------------------------
// Address: 0x10005B80
// Name: public: void MovieSlot::SetCursorShape(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MovieSlot::SetCursorShape(MovieSlot *this, IScaleformUI *pui, void *params)
{
  long double v3; // st7

  v3 = pui->Params_GetArgAsNumber(this: pui, a2: params, a3: 0);
  ScaleformUIImpl::SetCursorShape(this: &ScaleformUIImpl::m_Instance, shapeIndex: (int)v3);
}

//------------------------------------------------------------------------------
// Address: 0x10005BB0
// Name: public: void MovieSlot::ShowCursor(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MovieSlot::ShowCursor(MovieSlot *this, IScaleformUI *pui, IScaleformUI *params)
{
  ScaleformUIImpl::ShowCursor(this: &ScaleformUIImpl::m_Instance);
}

//------------------------------------------------------------------------------
// Address: 0x10005BC0
// Name: public: void MovieSlot::HideCursor(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MovieSlot::HideCursor(MovieSlot *this, IScaleformUI *pui, IScaleformUI *params)
{
  ScaleformUIImpl::HideCursor(this: &ScaleformUIImpl::m_Instance);
}

//------------------------------------------------------------------------------
// Address: 0x10005BD0
// Name: public: void MovieSlot::PlaySoundScaleform(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MovieSlot::PlaySoundScaleform(MovieSlot *this, IScaleformUI *pui, void *params)
{
  const char *v3; // eax

  v3 = pui->Params_GetArgAsString(this: pui, a2: params, a3: 0);
  g_pVGuiSurface->PlaySound(this: g_pVGuiSurface, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10005C00
// Name: public: void MovieSlot::DenyInputToGameFromFlash(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MovieSlot::DenyInputToGameFromFlash(MovieSlot *this, IScaleformUI *pui, void *params)
{
  this->m_bDenyInputToGame = ScaleformUIImpl::Params_GetArgAsBool(this: &ScaleformUIImpl::m_Instance, params, index: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10005C20
// Name: public: void MovieSlot::DisableAnalogStickNavigation(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MovieSlot::DisableAnalogStickNavigation(MovieSlot *this, IScaleformUI *pui, void *params)
{
  this->m_bDisableAnalogNavigation = ScaleformUIImpl::Params_GetNumArgs(this: &ScaleformUIImpl::m_Instance, params) == 0
                                  || ScaleformUIImpl::Params_GetArgAsBool(
                                       this: &ScaleformUIImpl::m_Instance,
                                       params,
                                       index: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10005C60
// Name: public: bool MovieSlot::AnalogStickNavigationDisabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall MovieSlot::AnalogStickNavigationDisabled(MovieSlot *this)
{
  return this->m_bDisableAnalogNavigation;
}

//------------------------------------------------------------------------------
// Address: 0x10005C70
// Name: public: virtual void MovieSlot::RemoveElement(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MovieSlot::RemoveElement(MovieSlot *this, const struct GFxValue *element)
{
  if ( this->m_pMovieView != nullptr )
    GFxValue::ObjectInterface::Invoke(
      this: this->m_GlobalValue.pObjectInterface,
      a2: this->m_GlobalValue.Value.pStringManaged,
      a3: nullptr,
      a4: "RemoveElement",
      a5: element,
      a6: 1u,
      a7: (this->m_GlobalValue.Type & 0x8F) == 8);
}

//------------------------------------------------------------------------------
// Address: 0x10005CB0
// Name: public: void CursorSlot::Hide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CursorSlot::Hide(CursorSlot *this)
{
  if ( !this->m_bUIHidden )
  {
    this->m_bUIHidden = true;
    GFxValue::ObjectInterface::Invoke(
      this: this->m_GlobalValue.pObjectInterface,
      a2: this->m_GlobalValue.Value.pStringManaged,
      a3: nullptr,
      a4: "Hide",
      a5: nullptr,
      a6: 0,
      a7: (this->m_GlobalValue.Type & 0x8F) == 8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005CE0
// Name: public: void CursorSlot::Show(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CursorSlot::Show(CursorSlot *this)
{
  if ( this->m_bUIHidden )
  {
    this->m_bUIHidden = false;
    GFxValue::ObjectInterface::Invoke(
      this: this->m_GlobalValue.pObjectInterface,
      a2: this->m_GlobalValue.Value.pStringManaged,
      a3: nullptr,
      a4: "Show",
      a5: nullptr,
      a6: 0,
      a7: (this->m_GlobalValue.Type & 0x8F) == 8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005D10
// Name: public: GFxValue::~GFxValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxValue::~GFxValue(GFxValue *this)
{
  if ( (this->Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)this->pObjectInterface, val: (StringPoolCase_t)this);
    this->pObjectInterface = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005D40
// Name: public: class GFxValue const __near & GFxValue::operator=(class GFxValue const __near &)
// Source: json
//------------------------------------------------------------------------------
const GFxValue *__thiscall GFxValue::operator=(GFxValue *this, const GFxValue *src)
{
  CStringPool *pObjectInterface; // ecx

  if ( this != src )
  {
    if ( (this->Type & 0x40) != 0 )
    {
      GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)this->pObjectInterface, val: (StringPoolCase_t)this);
      this->pObjectInterface = nullptr;
    }
    this->Type = src->Type;
    this->Value.NValue = src->Value.NValue;
    if ( (src->Type & 0x40) != 0 )
    {
      pObjectInterface = (CStringPool *)src->pObjectInterface;
      this->pObjectInterface = src->pObjectInterface;
      GFxValue::ObjectInterface::ObjectAddRef(this: pObjectInterface, val: (StringPoolCase_t)this);
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10005DA0
// Name: public: char const __near * GFxValue::GetString(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall GFxValue::GetString(GFxValue *this)
{
  if ( (this->Type & 0x40) != 0 )
    return *this->Value.pStringManaged;
  else
    return this->Value.pString;
}

//------------------------------------------------------------------------------
// Address: 0x10005DC0
// Name: protected: void GFxValue::ChangeType(enum GFxValue::ValueType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxValue::ChangeType(GFxValue *this, GFxValue::ValueType type)
{
  if ( (this->Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)this->pObjectInterface, val: (StringPoolCase_t)this);
    this->pObjectInterface = nullptr;
    this->Type = type;
  }
  else
  {
    this->Type = type;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005E00
// Name: public: void FlashObjectVisitor::AddArray(char const __near *,class GFxValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FlashObjectVisitor::AddArray(FlashObjectVisitor *this, const char *name, const GFxValue *val)
{
  KeyValues *NewKey; // esi
  GFxValue::ObjectInterface *pObjectInterface; // ecx
  char *pString; // [esp-10h] [ebp-30h]
  FlashArrayVisitor visitor; // [esp+8h] [ebp-18h] BYREF
  int v8; // [esp+1Ch] [ebp-4h]

  NewKey = KeyValues::CreateNewKey(this: this->m_pKV);
  KeyValues::SetName(this: NewKey, setName: "_array_");
  KeyValues::SetString(this: NewKey, keyName: "_name_", value: name);
  visitor.__vftable = (FlashArrayVisitor_vtbl *)&FlashArrayVisitor::`vftable';
  pObjectInterface = val->pObjectInterface;
  pString = (char *)val->Value.pString;
  v8 = 0;
  visitor.m_pKV = NewKey;
  visitor.m_pOriginalValue = val;
  GFxValue::ObjectInterface::VisitElements(this: pObjectInterface, a2: pString, a3: &visitor, a4: 0, a5: -1);
  if ( KeyValues::IsEmpty(this: NewKey, keyName: nullptr) )
    KeyValues::RemoveSubKey(this: this->m_pKV, subKey: NewKey);
}

//------------------------------------------------------------------------------
// Address: 0x10005EA0
// Name: public: void FlashArrayVisitor::AddObject(class GFxValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FlashArrayVisitor::AddObject(FlashArrayVisitor *this, const GFxValue *val)
{
  KeyValues *NewKey; // esi
  GFxValue::ObjectInterface *pObjectInterface; // ecx
  char *pString; // [esp-Ch] [ebp-2Ch]
  bool v6; // [esp-4h] [ebp-24h]
  FlashObjectVisitor visitor; // [esp+8h] [ebp-18h] BYREF
  int v8; // [esp+1Ch] [ebp-4h]

  NewKey = KeyValues::CreateNewKey(this: this->m_pKV);
  KeyValues::SetName(this: NewKey, setName: "_");
  visitor.__vftable = (FlashObjectVisitor_vtbl *)&FlashObjectVisitor::`vftable';
  v6 = (val->Type & 0x8F) == 8;
  pString = (char *)val->Value.pString;
  pObjectInterface = val->pObjectInterface;
  v8 = 0;
  visitor.m_pKV = NewKey;
  visitor.m_pOriginalValue = val;
  GFxValue::ObjectInterface::VisitMembers(this: pObjectInterface, a2: pString, a3: &visitor, a4: v6);
  if ( KeyValues::IsEmpty(this: NewKey, keyName: nullptr) )
    KeyValues::RemoveSubKey(this: this->m_pKV, subKey: NewKey);
}

//------------------------------------------------------------------------------
// Address: 0x10005F40
// Name: public: BaseSlot::BaseSlot(void)
// Source: json
//------------------------------------------------------------------------------
BaseSlot *__thiscall BaseSlot::BaseSlot(BaseSlot *this)
{
  this->__vftable = (BaseSlot_vtbl *)&BaseSlot::`vftable';
  this->m_GlobalValue.pObjectInterface = nullptr;
  this->m_GlobalValue.Type = VT_Undefined;
  this->m_GameAPI.pObjectInterface = nullptr;
  this->m_GameAPI.Type = VT_Undefined;
  this->m_pMovieDef = nullptr;
  this->m_pMovieView = nullptr;
  this->m_iRefCount = 1;
  this->m_iSlot = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10005F70
// Name: public: void BaseSlot::SaveKVFile(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BaseSlot::SaveKVFile(BaseSlot *this, IScaleformUI *pui, const char *obj)
{
  int v3; // esi
  unsigned int v4; // edi
  const char *v5; // ebx
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  GFxValue::ObjectInterface *v8; // ecx
  IBaseFileSystem *v9; // eax
  void *v10; // [esp-Ch] [ebp-38h]
  bool v11; // [esp-4h] [ebp-30h]
  FlashObjectVisitor visitor; // [esp+Ch] [ebp-20h] BYREF
  void *pMem; // [esp+18h] [ebp-14h]
  const char *filename; // [esp+1Ch] [ebp-10h]
  int v15; // [esp+28h] [ebp-4h]
  const char *where; // [esp+38h] [ebp+Ch]

  v3 = *((_DWORD *)obj + 4);
  if ( (*(_DWORD *)(v3 + 20) & 0x40) != 0 )
    filename = **(const char ***)(v3 + 24);
  else
    filename = *(const char **)(v3 + 24);
  v4 = *((_DWORD *)obj + 5);
  v5 = filename;
  if ( v4 > 2 )
  {
    if ( (*(_DWORD *)(v3 + 36) & 0x40) != 0 )
      v5 = **(const char ***)(v3 + 40);
    else
      v5 = *(const char **)(v3 + 40);
  }
  where = "GAME";
  if ( v4 > 3 )
  {
    if ( (*(_DWORD *)(v3 + 52) & 0x40) != 0 )
      where = **(const char ***)(v3 + 56);
    else
      where = *(const char **)(v3 + 56);
  }
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  pMem = v6;
  v7 = nullptr;
  v15 = 0;
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: v5);
  visitor.__vftable = (FlashObjectVisitor_vtbl *)&FlashObjectVisitor::`vftable';
  visitor.m_pKV = v7;
  visitor.m_pOriginalValue = (const GFxValue *)v3;
  v11 = (*(_DWORD *)(v3 + 4) & 0x8F) == 8;
  v8 = *(GFxValue::ObjectInterface **)v3;
  v10 = *(void **)(v3 + 8);
  v15 = 1;
  GFxValue::ObjectInterface::VisitMembers(this: v8, a2: v10, a3: &visitor, a4: v11);
  if ( g_pFullFileSystem != nullptr )
    v9 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v9 = nullptr;
  KeyValues::SaveToFile(this: v7, filesystem: v9, resourceName: filename, pathID: where);
  KeyValues::deleteThis(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10006090
// Name: public: void BaseSlot::SetConvar(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BaseSlot::SetConvar(BaseSlot *this, IScaleformUI *pui, _DWORD *obj)
{
  int v3; // eax
  const char *v4; // esi
  int v5; // edx
  IConVar *m_pConVar; // esi
  IConVar_vtbl *v7; // edi
  const char *String; // eax
  ConVarRef varref; // [esp+Ch] [ebp-8h] BYREF

  if ( obj[5] == 2 )
  {
    v3 = obj[4];
    if ( (*(_DWORD *)(v3 + 4) & 0x40) != 0 )
      v4 = **(const char ***)(v3 + 8);
    else
      v4 = *(const char **)(v3 + 8);
    if ( v4 != nullptr && *v4 != 0 )
    {
      ConVarRef::ConVarRef(this: &varref, pName: v4);
      v5 = obj[4];
      switch ( *(_DWORD *)(v5 + 20) & 0x8F )
      {
        case 2:
          varref.m_pConVar->SetValue_2(this: varref.m_pConVar, a2: *(_BYTE *)(v5 + 24) != 0);
          break;
        case 3:
          ((void (__stdcall *)(_DWORD))varref.m_pConVar->SetValue_3)(a1: *(double *)(v5 + 24));
          break;
        case 4:
          m_pConVar = varref.m_pConVar;
          v7 = varref.m_pConVar->__vftable;
          String = GFxValue::GetString(this: (GFxValue *)(v5 + 16));
          v7->SetValue_4(this: m_pConVar, a2: String);
          break;
        default:
          ScaleformUIImpl::LogPrintf(
            this: &ScaleformUIImpl::m_Instance,
            format: "scaleform: illegal attempt to set %s to type number# 0x%x\n",
            v4,
            *(_DWORD *)(v5 + 20) & 0x8F);
          break;
      }
    }
    else
    {
      ScaleformUIImpl::LogPrintf(
        this: &ScaleformUIImpl::m_Instance,
        format: "scaleform: script called setconver with bad first argument\n");
    }
  }
  else
  {
    ScaleformUIImpl::LogPrintf(
      this: &ScaleformUIImpl::m_Instance,
      format: "scaleform: script called setconver with %d args\n",
      obj[5]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100061A0
// Name: public: void BaseSlot::Translate(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BaseSlot::Translate(BaseSlot *this, IScaleformUI *pui, StringPoolCase_t *obj)
{
  int v3; // edi
  const char *v5; // eax
  GFxMovieView_vtbl *v6; // edi
  const wchar_t *v7; // eax
  StringPoolCase_t v8; // esi
  CStringPool *v9; // ecx

  v3 = *((_DWORD *)obj + 4);
  if ( (*(_DWORD *)(v3 + 4) & 0x40) != 0 )
    v5 = **(const char ***)(v3 + 8);
  else
    v5 = *(const char **)(v3 + 8);
  if ( v5 != nullptr && *v5 == 35 )
  {
    v6 = this->m_pMovieView->__vftable;
    v7 = ScaleformUIImpl::Translate(this: &ScaleformUIImpl::m_Instance, key: v5, pIsHTML: nullptr);
    v6->CreateStringW(this: this->m_pMovieView, a2: *(GFxValue **)obj, a3: v7);
  }
  else
  {
    v8 = *obj;
    if ( *obj != v3 )
    {
      if ( (*(_DWORD *)(v8 + 4) & 0x40) != 0 )
      {
        GFxValue::ObjectInterface::ObjectRelease(this: *(CStringPool **)v8, val: v8);
        *(_DWORD *)v8 = 0;
      }
      *(_DWORD *)(v8 + 4) = *(_DWORD *)(v3 + 4);
      *(_DWORD *)(v8 + 8) = *(_DWORD *)(v3 + 8);
      *(_DWORD *)(v8 + 12) = *(_DWORD *)(v3 + 12);
      if ( (*(_DWORD *)(v3 + 4) & 0x40) != 0 )
      {
        v9 = *(CStringPool **)v3;
        *(_DWORD *)v8 = *(_DWORD *)v3;
        GFxValue::ObjectInterface::ObjectAddRef(this: v9, val: v8);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006250
// Name: public: void BaseSlot::ReplaceGlyphs(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BaseSlot::ReplaceGlyphs(BaseSlot *this, IScaleformUI *pui, GFxValue **obj)
{
  GFxValue *v3; // eax
  const char *pString; // ecx
  const wchar_t *pStringW; // edi
  int NValue; // esi
  const wchar_t *v7; // eax

  v3 = obj[4];
  pString = nullptr;
  pStringW = nullptr;
  NValue = 0;
  if ( (v3->Type & 0x8F) == 5 )
  {
    pStringW = v3->Value.pStringW;
  }
  else if ( (v3->Type & 0x40) != 0 )
  {
    pString = *v3->Value.pStringManaged;
  }
  else
  {
    pString = v3->Value.pString;
  }
  if ( obj[5] == (GFxValue *)2 )
    NValue = (int)v3[1].Value.NValue;
  if ( pString != nullptr )
    v7 = ScaleformUIImpl::ReplaceGlyphKeywordsWithHTML(
           this: &ScaleformUIImpl::m_Instance,
           text: pString,
           fontSize: NValue);
  else
    v7 = ScaleformUIImpl::ReplaceGlyphKeywordsWithHTML(
           this: &ScaleformUIImpl::m_Instance,
           pin: pStringW,
           fontSize: NValue);
  this->m_pMovieView->CreateStringW(this: this->m_pMovieView, a2: *obj, a3: v7);
}

//------------------------------------------------------------------------------
// Address: 0x100062D0
// Name: public: void BaseSlot::ConsoleCommand(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BaseSlot::ConsoleCommand(BaseSlot *this, IScaleformUI *pui, _DWORD *obj)
{
  int v3; // eax

  v3 = obj[4];
  if ( (*(_DWORD *)(v3 + 4) & 0x40) != 0 )
    ScaleformUIImpl::m_Instance.m_pEngine->ClientCmd(
      this: ScaleformUIImpl::m_Instance.m_pEngine,
      a2: **(const char ***)(v3 + 8));
  else
    ScaleformUIImpl::m_Instance.m_pEngine->ClientCmd(
      this: ScaleformUIImpl::m_Instance.m_pEngine,
      a2: *(const char **)(v3 + 8));
}

//------------------------------------------------------------------------------
// Address: 0x10006310
// Name: public: void BaseSlot::SendUIEvent(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BaseSlot::SendUIEvent(BaseSlot *this, IScaleformUI *pui, _DWORD *obj)
{
  _DWORD *v3; // eax
  const char *v4; // edx
  int v6; // ecx
  const char *v7; // eax

  v3 = (_DWORD *)obj[4];
  v4 = (const char *)v3[6];
  if ( (v3[5] & 0x40) != 0 )
    v4 = *(const char **)v4;
  v6 = v3[1];
  v7 = (const char *)v3[2];
  if ( (v6 & 0x40) != 0 )
    v7 = *(const char **)v7;
  ScaleformUIImpl::SendUIEvent(this: &ScaleformUIImpl::m_Instance, action: v7, eventData: v4, slot: this->m_iSlot);
}

//------------------------------------------------------------------------------
// Address: 0x10006360
// Name: public: MovieSlot::MovieSlot(void)
// Source: json
//------------------------------------------------------------------------------
MovieSlot *__thiscall MovieSlot::MovieSlot(MovieSlot *this)
{
  this->m_GlobalValue.pObjectInterface = nullptr;
  this->m_GlobalValue.Type = VT_Undefined;
  this->m_GameAPI.pObjectInterface = nullptr;
  this->m_GameAPI.Type = VT_Undefined;
  this->m_pMovieDef = nullptr;
  this->m_pMovieView = nullptr;
  this->m_iRefCount = 1;
  this->m_iSlot = -1;
  this->__vftable = (MovieSlot_vtbl *)&MovieSlot::`vftable';
  this->m_iNumInputConsumers = 0;
  *(_WORD *)&this->m_bDisableAnalogNavigation = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100063A0
// Name: public: virtual bool MovieSlot::DenyInputToGame(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall MovieSlot::DenyInputToGame(MovieSlot *this)
{
  return this->m_bDenyInputToGame;
}

//------------------------------------------------------------------------------
// Address: 0x100063B0
// Name: public: virtual bool MovieSlot::ConsumesInputEvents(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall MovieSlot::ConsumesInputEvents(MovieSlot *this)
{
  return this->m_iNumInputConsumers > 0;
}

//------------------------------------------------------------------------------
// Address: 0x100063C0
// Name: public: virtual void MovieSlot::RequestElement(char const __near *,class ScaleformUIFunctionHandlerObject __near *,class IScaleformUIFunctionHandlerDefinitionTable const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MovieSlot::RequestElement(
        MovieSlot *this,
        const char *elementName,
        ScaleformUIFunctionHandlerObject *object,
        const IScaleformUIFunctionHandlerDefinitionTable *tableObject)
{
  GFxMovieView *m_pMovieView; // ecx
  void (__thiscall *CreateString)(struct GFxMovieView *, GFxValue *, const char *); // edx
  const ScaleformUIFunctionHandlerDefinition *i; // esi
  GFxValue args[2]; // [esp+4h] [ebp-2Ch] BYREF
  int v9; // [esp+2Ch] [ebp-4h]

  if ( this->m_pMovieView != nullptr )
  {
    `eh vector constructor iterator'(
      ptr: args,
      size: 0x10u,
      count: 2,
      pCtor: (void (__thiscall *)(void *))GFxResourceKey::GFxResourceKey,
      pDtor: (void (__thiscall *)(void *))GFxValue::~GFxValue);
    m_pMovieView = this->m_pMovieView;
    CreateString = m_pMovieView->CreateString;
    v9 = 0;
    CreateString(this: m_pMovieView, a2: args, a3: elementName);
    this->m_pMovieView->CreateObject(this: this->m_pMovieView, a2: &args[1], a3: nullptr, a4: nullptr, a5: 0);
    for ( i = (const ScaleformUIFunctionHandlerDefinition *)tableObject->GetTable(this: tableObject);
          i->m_pName != nullptr;
          ++i )
    {
      ScaleformUIImpl::AddAPIFunctionToObject(
        this: &ScaleformUIImpl::m_Instance,
        pAPI: &args[1],
        pMovie: this->m_pMovieView,
        object,
        pFunctionDef: i);
    }
    GFxValue::ObjectInterface::Invoke(
      this: this->m_GlobalValue.pObjectInterface,
      a2: this->m_GlobalValue.Value.pStringManaged,
      a3: nullptr,
      a4: "RequestElement",
      a5: args,
      a6: 2u,
      a7: (this->m_GlobalValue.Type & 0x8F) == 8);
    v9 = -1;
    `eh vector destructor iterator'(
      ptr: args,
      size: 0x10u,
      count: 2,
      pDtor: (void (__thiscall *)(void *))GFxValue::~GFxValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100064C0
// Name: public: bool GFxValue::operator==(class GFxValue const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxValue::operator==(GFxValue *this, const GFxValue *other)
{
  GFxValue::ValueType Type; // esi
  GFxValue::ValueType v3; // edi
  bool result; // al
  const char *pString; // eax
  const char *v6; // ecx
  int v7; // eax

  Type = this->Type;
  v3 = other->Type;
  if ( Type != v3 )
    return false;
  switch ( Type & 0xF )
  {
    case 2:
      result = this->Value.BValue == other->Value.BValue;
      break;
    case 3:
      result = this->Value.NValue == other->Value.NValue;
      break;
    case 4:
      pString = other->Value.pString;
      if ( (v3 & 0x40) != 0 )
        pString = *(const char **)pString;
      v6 = this->Value.pString;
      if ( (Type & 0x40) != 0 )
        v6 = *(const char **)v6;
      result = G_strcmp(s1: v6, s2: pString) == 0;
      break;
    case 5:
      LOBYTE(v7) = G_wcscmp(a: (unsigned __int16)this->Value.pString);
      result = v7 == 0;
      break;
    default:
      result = this->Value.pString == other->Value.pString;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100065A0
// Name: public: void GFxValue::SetBoolean(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxValue::SetBoolean(GFxValue *this, bool v)
{
  if ( (this->Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)this->pObjectInterface, val: (StringPoolCase_t)this);
    this->pObjectInterface = nullptr;
    this->Value.BValue = v;
    this->Type = VT_Boolean;
  }
  else
  {
    this->Value.BValue = v;
    this->Type = VT_Boolean;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100065F0
// Name: public: void GFxValue::SetNumber(double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxValue::SetNumber(GFxValue *this, long double v)
{
  if ( (this->Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)this->pObjectInterface, val: (StringPoolCase_t)this);
    this->pObjectInterface = nullptr;
  }
  this->Type = VT_Number;
  this->Value.NValue = v;
}

//------------------------------------------------------------------------------
// Address: 0x10006630
// Name: public: void GFxValue::SetString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxValue::SetString(GFxValue *this, const char *p)
{
  if ( (this->Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)this->pObjectInterface, val: (StringPoolCase_t)this);
    this->pObjectInterface = nullptr;
    this->Value.pString = p;
    this->Type = VT_String;
  }
  else
  {
    this->Value.pString = p;
    this->Type = VT_String;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006680
// Name: public: void FlashArrayVisitor::AddArray(class GFxValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FlashArrayVisitor::AddArray(FlashArrayVisitor *this, const GFxValue *val)
{
  KeyValues *NewKey; // esi
  GFxValue::ObjectInterface *pObjectInterface; // ecx
  char *pString; // [esp-10h] [ebp-30h]
  FlashArrayVisitor visitor; // [esp+8h] [ebp-18h] BYREF
  int v7; // [esp+1Ch] [ebp-4h]

  NewKey = KeyValues::CreateNewKey(this: this->m_pKV);
  KeyValues::SetName(this: NewKey, setName: "_array_");
  visitor.__vftable = (FlashArrayVisitor_vtbl *)&FlashArrayVisitor::`vftable';
  pObjectInterface = val->pObjectInterface;
  pString = (char *)val->Value.pString;
  v7 = 0;
  visitor.m_pKV = NewKey;
  visitor.m_pOriginalValue = val;
  GFxValue::ObjectInterface::VisitElements(this: pObjectInterface, a2: pString, a3: &visitor, a4: 0, a5: -1);
  if ( KeyValues::IsEmpty(this: NewKey, keyName: nullptr) )
    KeyValues::RemoveSubKey(this: this->m_pKV, subKey: NewKey);
}

//------------------------------------------------------------------------------
// Address: 0x10006710
// Name: public: virtual void FlashArrayVisitor::Visit(unsigned int,class GFxValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FlashArrayVisitor::Visit(FlashArrayVisitor *this, unsigned int idx, const GFxValue *val)
{
  KeyValues *NewKey; // esi
  double NValue; // xmm0_8
  KeyValues *v6; // eax

  if ( !GFxValue::operator==(this: (GFxValue *)this->m_pOriginalValue, other: val) )
  {
    switch ( val->Type & 0x8F )
    {
      case 2:
        NewKey = KeyValues::CreateNewKey(this: this->m_pKV);
        KeyValues::SetInt(this: NewKey, keyName: nullptr, value: val->Value.BValue);
        goto LABEL_4;
      case 3:
        NValue = val->Value.NValue;
        NewKey = KeyValues::CreateNewKey(this: this->m_pKV);
        if ( (double)(int)NValue == NValue )
          KeyValues::SetInt(this: NewKey, keyName: nullptr, value: (int)NValue);
        else
          KeyValues::SetFloat(this: NewKey, keyName: nullptr, value: NValue);
        goto LABEL_4;
      case 4:
        v6 = KeyValues::CreateNewKey(this: this->m_pKV);
        NewKey = v6;
        if ( (val->Type & 0x40) != 0 )
          KeyValues::SetString(this: v6, keyName: nullptr, value: *val->Value.pStringManaged);
        else
          KeyValues::SetString(this: v6, keyName: nullptr, value: val->Value.pString);
LABEL_4:
        if ( NewKey != nullptr )
          KeyValues::SetName(this: NewKey, setName: "_");
        break;
      case 6:
        FlashArrayVisitor::AddObject(this, val);
        break;
      case 7:
        FlashArrayVisitor::AddArray(this, val);
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006840
// Name: public: void FlashObjectVisitor::AddObject(char const __near *,class GFxValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FlashObjectVisitor::AddObject(FlashObjectVisitor *this, const char *name, const GFxValue *val)
{
  KeyValues *NewKey; // esi
  GFxValue::ObjectInterface *pObjectInterface; // ecx
  char *pString; // [esp-Ch] [ebp-2Ch]
  bool v7; // [esp-4h] [ebp-24h]
  FlashObjectVisitor visitor; // [esp+8h] [ebp-18h] BYREF
  int v9; // [esp+1Ch] [ebp-4h]

  NewKey = KeyValues::CreateNewKey(this: this->m_pKV);
  KeyValues::SetName(this: NewKey, setName: name);
  visitor.__vftable = (FlashObjectVisitor_vtbl *)&FlashObjectVisitor::`vftable';
  v7 = (val->Type & 0x8F) == 8;
  pString = (char *)val->Value.pString;
  pObjectInterface = val->pObjectInterface;
  v9 = 0;
  visitor.m_pKV = NewKey;
  visitor.m_pOriginalValue = val;
  GFxValue::ObjectInterface::VisitMembers(this: pObjectInterface, a2: pString, a3: &visitor, a4: v7);
  if ( KeyValues::IsEmpty(this: NewKey, keyName: nullptr) )
    KeyValues::RemoveSubKey(this: this->m_pKV, subKey: NewKey);
}

//------------------------------------------------------------------------------
// Address: 0x100068E0
// Name: public: virtual void FlashObjectVisitor::Visit(char const __near *,class GFxValue const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FlashObjectVisitor::Visit(FlashObjectVisitor *this, const char *name, const GFxValue *val)
{
  double NValue; // xmm0_8

  if ( !GFxValue::operator==(this: (GFxValue *)this->m_pOriginalValue, other: val) )
  {
    switch ( val->Type & 0x8F )
    {
      case 2:
        KeyValues::SetInt(this: this->m_pKV, keyName: name, value: val->Value.BValue);
        break;
      case 3:
        NValue = val->Value.NValue;
        if ( (double)(int)NValue == NValue )
          KeyValues::SetInt(this: this->m_pKV, keyName: name, value: (int)NValue);
        else
          KeyValues::SetFloat(this: this->m_pKV, keyName: name, value: NValue);
        break;
      case 4:
        if ( (val->Type & 0x40) != 0 )
          KeyValues::SetString(this: this->m_pKV, keyName: name, value: *val->Value.pStringManaged);
        else
          KeyValues::SetString(this: this->m_pKV, keyName: name, value: val->Value.pString);
        break;
      case 6:
        FlashObjectVisitor::AddObject(this, name, val);
        break;
      case 7:
        FlashObjectVisitor::AddArray(this, name, val);
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100069F0
// Name: protected: bool BaseSlot::ConvertValue(class GFxValue __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall BaseSlot::ConvertValue(BaseSlot *this, GFxValue *value, KeyValues *kv)
{
  const char *String; // eax
  bool result; // al
  long double v; // xmm0_8
  long double Float; // st7
  const wchar_t *WString; // eax
  KeyValues *kva; // [esp+28h] [ebp+Ch]
  KeyValues *kvb; // [esp+28h] [ebp+Ch]

  switch ( KeyValues::GetDataType(this: kv, keyName: nullptr) )
  {
    case TYPE_STRING:
      kva = (KeyValues *)this->m_pMovieView->__vftable;
      String = KeyValues::GetString(this: kv, keyName: nullptr, defaultValue: (const char *)&pMem);
      ((void (__thiscall *)(GFxMovieView *, GFxValue *, const char *))kva[1].m_wsValue)(
        a1: this->m_pMovieView,
        a2: value,
        a3: String);
      result = true;
      break;
    case TYPE_INT:
      v = (double)KeyValues::GetInt(this: kv, keyName: nullptr, defaultValue: 0);
      GFxValue::SetNumber(this: value, v);
      result = true;
      break;
    case TYPE_FLOAT:
      Float = KeyValues::GetFloat(this: kv, keyName: nullptr, defaultValue: 0.0);
      goto LABEL_5;
    case TYPE_WSTRING:
      kvb = (KeyValues *)this->m_pMovieView->__vftable;
      WString = KeyValues::GetWString(this: kv, keyName: nullptr, defaultValue: &word_1028F3E0);
      ((void (__thiscall *)(GFxMovieView *, GFxValue *, const wchar_t *))kvb[1].m_iValue)(
        a1: this->m_pMovieView,
        a2: value,
        a3: WString);
      result = true;
      break;
    case TYPE_UINT64:
      Float = (double)KeyValues::GetUint64(this: kv, keyName: nullptr, defaultValue: 0);
LABEL_5:
      GFxValue::SetNumber(this: value, v: Float);
      result = true;
      break;
    default:
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10006B40
// Name: protected: char const __near * BaseSlot::PopulateArray(class GFxValue __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall BaseSlot::PopulateArray(BaseSlot *this, GFxValue *value, KeyValues *kv)
{
  unsigned int v3; // edi
  KeyValues *i; // esi
  const char *Name; // eax
  unsigned int v6; // edi
  KeyValues *j; // esi
  const char *v8; // eax
  const char *v9; // eax
  const char *String; // esi
  GFxValue workValue; // [esp+Ch] [ebp-20h] BYREF
  BaseSlot *v13; // [esp+1Ch] [ebp-10h]
  int v14; // [esp+28h] [ebp-4h]

  v13 = this;
  this->m_pMovieView->CreateArray(this: this->m_pMovieView, a2: value);
  v3 = 0;
  workValue.pObjectInterface = nullptr;
  workValue.Type = VT_Undefined;
  v14 = 0;
  for ( i = KeyValues::GetFirstSubKey(this: kv); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    if ( V_strcasecmp(s1: "_name_", s2: Name) != 0 )
      ++v3;
  }
  GFxValue::ObjectInterface::SetArraySize(this: value->pObjectInterface, a2: value->Value.pStringManaged, a3: v3);
  v6 = 0;
  for ( j = KeyValues::GetFirstSubKey(this: kv); j != nullptr; j = KeyValues::GetNextKey(this: j) )
  {
    v8 = KeyValues::GetName(this: j);
    if ( V_strcasecmp(s1: "_name_", s2: v8) != 0 )
    {
      v9 = KeyValues::GetName(this: j);
      if ( V_strcasecmp(s1: "_array_", s2: v9) != 0 )
      {
        if ( !BaseSlot::ConvertValue(this: v13, value: &workValue, kv: j) )
          BaseSlot::PopulateObject(this: v13, value: &workValue, kv: j);
      }
      else
      {
        BaseSlot::PopulateArray(this: v13, value: &workValue, kv: j);
      }
      GFxValue::ObjectInterface::SetElement(
        this: value->pObjectInterface,
        a2: value->Value.pStringManaged,
        a3: v6,
        a4: &workValue);
      if ( (workValue.Type & 0x40) != 0 )
      {
        GFxValue::ObjectInterface::ObjectRelease(
          this: (CStringPool *)workValue.pObjectInterface,
          val: (StringPoolCase_t)&workValue);
        workValue.pObjectInterface = nullptr;
      }
      workValue.Type = VT_Null;
      ++v6;
    }
  }
  String = KeyValues::GetString(this: kv, keyName: "_name_", defaultValue: nullptr);
  v14 = -1;
  if ( (workValue.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(
      this: (CStringPool *)workValue.pObjectInterface,
      val: (StringPoolCase_t)&workValue);
  return String;
}

//------------------------------------------------------------------------------
// Address: 0x10006CD0
// Name: protected: void BaseSlot::PopulateObject(class GFxValue __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BaseSlot::PopulateObject(BaseSlot *this, GFxValue *value, KeyValues *kv)
{
  KeyValues *i; // edi
  KeyValues *j; // edi
  const char *Name; // eax
  GFxValue workValue; // [esp+Ch] [ebp-1Ch] BYREF
  int v8; // [esp+24h] [ebp-4h]

  this->m_pMovieView->CreateObject(this: this->m_pMovieView, a2: value, a3: nullptr, a4: nullptr, a5: 0);
  workValue.pObjectInterface = nullptr;
  workValue.Type = VT_Undefined;
  v8 = 0;
  for ( i = KeyValues::GetFirstValue(this: kv); i != nullptr; i = KeyValues::GetNextValue(this: i) )
  {
    if ( BaseSlot::ConvertValue(this, value: &workValue, kv: i) )
    {
      KeyValues::GetName(this: i);
      GFxValue::ObjectInterface::SetMember(
        this: (CStringPool *)value->pObjectInterface,
        pdata: (unsigned int)value->Value.pString);
      if ( (workValue.Type & 0x40) != 0 )
      {
        GFxValue::ObjectInterface::ObjectRelease(
          this: (CStringPool *)workValue.pObjectInterface,
          val: (StringPoolCase_t)&workValue);
        workValue.pObjectInterface = nullptr;
      }
      workValue.Type = VT_Null;
    }
  }
  for ( j = KeyValues::GetFirstTrueSubKey(this: kv); j != nullptr; j = KeyValues::GetNextTrueSubKey(this: j) )
  {
    Name = KeyValues::GetName(this: j);
    if ( V_strcasecmp(s1: "_array_", s2: Name) != 0 )
    {
      this->m_pMovieView->CreateObject(this: this->m_pMovieView, a2: &workValue, a3: nullptr, a4: nullptr, a5: 0);
      BaseSlot::PopulateObject(this, value: &workValue, kv: j);
      KeyValues::GetName(this: j);
    }
    else
    {
      BaseSlot::PopulateArray(this, value: &workValue, kv: j);
    }
    GFxValue::ObjectInterface::SetMember(
      this: (CStringPool *)value->pObjectInterface,
      pdata: (unsigned int)value->Value.pString);
    if ( (workValue.Type & 0x40) != 0 )
    {
      GFxValue::ObjectInterface::ObjectRelease(
        this: (CStringPool *)workValue.pObjectInterface,
        val: (StringPoolCase_t)&workValue);
      workValue.pObjectInterface = nullptr;
    }
    workValue.Type = VT_Null;
  }
  v8 = -1;
  if ( (workValue.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(
      this: (CStringPool *)workValue.pObjectInterface,
      val: (StringPoolCase_t)&workValue);
}

//------------------------------------------------------------------------------
// Address: 0x10006EA0
// Name: public: void BaseSlot::LoadKVFile(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BaseSlot::LoadKVFile(BaseSlot *this, IScaleformUI *pui, GFxValue **obj)
{
  GFxValue *v3; // eax
  const char *pString; // edx
  unsigned int v5; // ecx
  const char *v6; // esi
  const char *v7; // edi
  char BValue; // bl
  KeyValues *v9; // eax
  KeyValues *v10; // esi
  IBaseFileSystem *v11; // eax
  const char *filename; // [esp+18h] [ebp-10h]

  v3 = obj[4];
  pString = v3->Value.pString;
  if ( (v3->Type & 0x40) != 0 )
    pString = *(const char **)pString;
  v5 = (unsigned int)obj[5];
  filename = pString;
  v6 = pString;
  if ( v5 > 1 )
  {
    if ( (v3[1].Type & 0x40) != 0 )
      v6 = *v3[1].Value.pStringManaged;
    else
      v6 = v3[1].Value.pString;
  }
  v7 = "GAME";
  if ( v5 > 2 )
  {
    if ( (v3[2].Type & 0x40) != 0 )
      v7 = *v3[2].Value.pStringManaged;
    else
      v7 = v3[2].Value.pString;
  }
  BValue = 1;
  if ( v5 > 3 )
    BValue = v3[3].Value.BValue;
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
    v10 = KeyValues::KeyValues(this: v9, setName: v6);
  else
    v10 = nullptr;
  if ( v10 != nullptr )
  {
    if ( g_pFullFileSystem != nullptr )
      v11 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v11 = nullptr;
    KeyValues::LoadFromFile(
      this: v10,
      filesystem: v11,
      resourceName: filename,
      pathID: v7,
      pfnEvaluateSymbolProc: nullptr);
    if ( BValue != 0 )
      DLCHelper::AppendDLCKeyValues(pKeyValues: v10, fileName: filename, startDir: v7);
    BaseSlot::PopulateObject(this, value: *obj, kv: v10);
    KeyValues::deleteThis(this: v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006FE0
// Name: protected: void BaseSlot::GetConvar(class IScaleformUI __near *,struct GFxFunctionHandler::Params __near *,enum BaseSlot::CVAR_TYPE_WANTED)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BaseSlot::GetConvar(
        BaseSlot *this,
        IScaleformUI *pui,
        GFxFunctionHandler::Params *params,
        BaseSlot::CVAR_TYPE_WANTED typeWanted)
{
  GFxValue *pArgs; // eax
  const char *pString; // eax
  GFxValue *pRetVal; // esi
  ConVarRef convar; // [esp+10h] [ebp-8h] BYREF

  if ( params->ArgCount == 1 )
  {
    pArgs = params->pArgs;
    if ( (pArgs->Type & 0x40) != 0 )
      pString = *pArgs->Value.pStringManaged;
    else
      pString = pArgs->Value.pString;
    if ( pString != nullptr && *pString != 0 )
    {
      ConVarRef::ConVarRef(this: &convar, pName: pString);
      if ( ConVarRef::IsValid(this: &convar) )
      {
        switch ( typeWanted )
        {
          case CVAR_WANT_NUMBER:
            GFxValue::SetNumber(this: params->pRetVal, v: convar.m_pConVarState->m_Value.m_fValue);
            return;
          case CVAR_WANT_STRING:
            if ( !convar.m_pConVar->IsFlagSet(this: convar.m_pConVar, a2: 4096)
              && convar.m_pConVarState->m_Value.m_pszString != nullptr )
            {
              this->m_pMovieView->CreateString(
                this: this->m_pMovieView,
                a2: params->pRetVal,
                a3: convar.m_pConVarState->m_Value.m_pszString);
              return;
            }
            break;
          case CVAR_WANT_BOOL:
            GFxValue::SetBoolean(this: params->pRetVal, v: convar.m_pConVarState->m_Value.m_nValue != 0);
            return;
          default:
            break;
        }
      }
    }
    else
    {
      ScaleformUIImpl::LogPrintf(
        this: &ScaleformUIImpl::m_Instance,
        format: "scaleform: script called GetConvar* with bad first argument\n");
    }
  }
  else
  {
    ScaleformUIImpl::LogPrintf(
      this: &ScaleformUIImpl::m_Instance,
      format: "scaleform: script called GetConvar* with %d args\n",
      params->ArgCount);
  }
  pRetVal = params->pRetVal;
  if ( (params->pRetVal->Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(
      this: (CStringPool *)pRetVal->pObjectInterface,
      val: (StringPoolCase_t)pRetVal);
    pRetVal->pObjectInterface = nullptr;
  }
  pRetVal->Type = VT_Null;
}

//------------------------------------------------------------------------------
// Address: 0x10007120
// Name: public: void BaseSlot::GetConvarNumber(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BaseSlot::GetConvarNumber(BaseSlot *this, IScaleformUI *pui, GFxFunctionHandler::Params *obj)
{
  BaseSlot::GetConvar(this, pui, params: obj, typeWanted: CVAR_WANT_NUMBER);
}

//------------------------------------------------------------------------------
// Address: 0x10007140
// Name: public: void BaseSlot::GetConvarString(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BaseSlot::GetConvarString(BaseSlot *this, IScaleformUI *pui, GFxFunctionHandler::Params *obj)
{
  BaseSlot::GetConvar(this, pui, params: obj, typeWanted: CVAR_WANT_STRING);
}

//------------------------------------------------------------------------------
// Address: 0x10007160
// Name: public: void BaseSlot::GetConvarBoolean(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BaseSlot::GetConvarBoolean(BaseSlot *this, IScaleformUI *pui, StringPoolCase_t *obj)
{
  int v3; // eax
  const char *v4; // eax
  StringPoolCase_t v5; // esi
  ConVarRef v6; // [esp+4h] [ebp-8h] BYREF

  if ( *((_DWORD *)obj + 5) == 1 )
  {
    v3 = *((_DWORD *)obj + 4);
    if ( (*(_DWORD *)(v3 + 4) & 0x40) != 0 )
      v4 = **(const char ***)(v3 + 8);
    else
      v4 = *(const char **)(v3 + 8);
    if ( v4 != nullptr && *v4 != 0 )
    {
      ConVarRef::ConVarRef(this: &v6, pName: v4);
      if ( ConVarRef::IsValid(this: &v6) )
      {
        GFxValue::SetBoolean(this: *(GFxValue **)obj, v: v6.m_pConVarState->m_Value.m_nValue != 0);
        return;
      }
    }
    else
    {
      ScaleformUIImpl::LogPrintf(
        this: &ScaleformUIImpl::m_Instance,
        format: "scaleform: script called GetConvar* with bad first argument\n");
    }
  }
  else
  {
    ScaleformUIImpl::LogPrintf(
      this: &ScaleformUIImpl::m_Instance,
      format: "scaleform: script called GetConvar* with %d args\n",
      *((_DWORD *)obj + 5));
  }
  v5 = *obj;
  if ( (*(_DWORD *)(*obj + 4) & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: *(CStringPool **)v5, val: v5);
    *(_DWORD *)v5 = 0;
  }
  *(_DWORD *)(v5 + 4) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10007220
// Name: public: void BaseSlot::HandleKeyEvent(bool,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BaseSlot::HandleKeyEvent(BaseSlot *this, bool keyDown, int code, int slot)
{
  const char *v5; // eax
  GFxValue args[2]; // [esp+4h] [ebp-2Ch] BYREF
  int v7; // [esp+2Ch] [ebp-4h]

  `eh vector constructor iterator'(
    ptr: args,
    size: 0x10u,
    count: 2,
    pCtor: (void (__thiscall *)(void *))GFxResourceKey::GFxResourceKey,
    pDtor: (void (__thiscall *)(void *))GFxValue::~GFxValue);
  v7 = 0;
  if ( (args[0].Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)args[0].pObjectInterface, val: (StringPoolCase_t)args);
    args[0].pObjectInterface = nullptr;
  }
  args[0].Type = VT_Number;
  args[0].Value.NValue = (double)code;
  if ( (args[1].Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(
      this: (CStringPool *)args[1].pObjectInterface,
      val: (StringPoolCase_t)&args[1]);
    args[1].pObjectInterface = nullptr;
  }
  args[1].Type = VT_Number;
  args[1].Value.NValue = (double)slot;
  v5 = "KeyDownEvent";
  if ( !keyDown )
    v5 = "KeyUpEvent";
  GFxValue::ObjectInterface::Invoke(
    this: this->m_GlobalValue.pObjectInterface,
    a2: this->m_GlobalValue.Value.pStringManaged,
    a3: nullptr,
    a4: v5,
    a5: args,
    a6: 2u,
    a7: (this->m_GlobalValue.Type & 0x8F) == 8);
  v7 = -1;
  `eh vector destructor iterator'(
    ptr: args,
    size: 0x10u,
    count: 2,
    pDtor: (void (__thiscall *)(void *))GFxValue::~GFxValue);
}

//------------------------------------------------------------------------------
// Address: 0x10007330
// Name: public: void BaseSlot::LockInputToSlot(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BaseSlot::LockInputToSlot(BaseSlot *this, unsigned int slot)
{
  __m128i v3; // xmm0
  GFxValue::ObjectInterface *pObjectInterface; // ecx
  char *pString; // [esp-18h] [ebp-38h]
  GFxValue args[1]; // [esp+4h] [ebp-1Ch] BYREF
  int v7; // [esp+1Ch] [ebp-4h]
  bool slota; // [esp+28h] [ebp+8h]

  `eh vector constructor iterator'(
    ptr: args,
    size: 0x10u,
    count: 1,
    pCtor: (void (__thiscall *)(void *))GFxResourceKey::GFxResourceKey,
    pDtor: (void (__thiscall *)(void *))GFxValue::~GFxValue);
  v7 = 0;
  if ( (args[0].Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)args[0].pObjectInterface, val: (StringPoolCase_t)args);
    args[0].pObjectInterface = nullptr;
  }
  v3 = _mm_cvtsi32_si128(slot);
  slota = (this->m_GlobalValue.Type & 0x8F) == 8;
  pObjectInterface = this->m_GlobalValue.pObjectInterface;
  pString = (char *)this->m_GlobalValue.Value.pString;
  args[0].Type = VT_Number;
  args[0].Value.NValue = _mm_cvtepi32_pd(v3).m128d_f64[0];
  GFxValue::ObjectInterface::Invoke(
    this: pObjectInterface,
    a2: pString,
    a3: nullptr,
    a4: "LockInputToSlot",
    a5: args,
    a6: 2u,
    a7: slota);
  v7 = -1;
  `eh vector destructor iterator'(
    ptr: args,
    size: 0x10u,
    count: 1,
    pDtor: (void (__thiscall *)(void *))GFxValue::~GFxValue);
}

//------------------------------------------------------------------------------
// Address: 0x10007410
// Name: public: void BaseSlot::CreateKeyTable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BaseSlot::CreateKeyTable(BaseSlot *this)
{
  GFxMovieView *m_pMovieView; // ecx
  void (__thiscall *CreateObject)(struct GFxMovieView *, GFxValue *, const char *, const GFxValue *, unsigned int); // eax
  GFxValue gfxv; // [esp+8h] [ebp-3Ch] BYREF
  GFxValue keyTable; // [esp+18h] [ebp-2Ch] BYREF
  char numberAsString[12]; // [esp+28h] [ebp-1Ch] BYREF
  int v6; // [esp+34h] [ebp-10h]
  int v7; // [esp+40h] [ebp-4h]

  keyTable.pObjectInterface = nullptr;
  keyTable.Type = VT_Undefined;
  m_pMovieView = this->m_pMovieView;
  CreateObject = m_pMovieView->CreateObject;
  v7 = 0;
  CreateObject(this: m_pMovieView, a2: &keyTable, a3: nullptr, a4: nullptr, a5: 0);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 1;
  *((_DWORD *)&gfxv.Value.pStringManaged + 1) = 0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 0);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Type = VT_String;
  gfxv.Value.pString = "KEY_NONE";
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 2;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 1.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 1);
  if ( (gfxv.Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
    gfxv.pObjectInterface = nullptr;
  }
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Type = VT_String;
  gfxv.Value.pString = "KEY_0";
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 3;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 2.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 2);
  if ( (gfxv.Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
    gfxv.pObjectInterface = nullptr;
  }
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Type = VT_String;
  gfxv.Value.pString = "KEY_1";
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 4;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 3.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 3);
  if ( (gfxv.Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
    gfxv.pObjectInterface = nullptr;
  }
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Type = VT_String;
  gfxv.Value.pString = "KEY_2";
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 5;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 4.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 4);
  if ( (gfxv.Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
    gfxv.pObjectInterface = nullptr;
  }
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Type = VT_String;
  gfxv.Value.pString = "KEY_3";
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 6;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 5.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 5);
  if ( (gfxv.Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
    gfxv.pObjectInterface = nullptr;
  }
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Type = VT_String;
  gfxv.Value.pString = "KEY_4";
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 7;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 6.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 6);
  if ( (gfxv.Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
    gfxv.pObjectInterface = nullptr;
  }
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Type = VT_String;
  gfxv.Value.pString = "KEY_5";
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 8;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 7.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 7);
  if ( (gfxv.Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
    gfxv.pObjectInterface = nullptr;
  }
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Type = VT_String;
  gfxv.Value.pString = "KEY_6";
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 9;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 8.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 8);
  if ( (gfxv.Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
    gfxv.pObjectInterface = nullptr;
  }
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Type = VT_String;
  gfxv.Value.pString = "KEY_7";
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 10;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 9.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 9);
  if ( (gfxv.Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
    gfxv.pObjectInterface = nullptr;
  }
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Type = VT_String;
  gfxv.Value.pString = "KEY_8";
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 11;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 10.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 10);
  if ( (gfxv.Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
    gfxv.pObjectInterface = nullptr;
  }
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Type = VT_String;
  gfxv.Value.pString = "KEY_9";
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 12;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 11.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 11);
  if ( (gfxv.Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
    gfxv.pObjectInterface = nullptr;
  }
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Type = VT_String;
  gfxv.Value.pString = "KEY_A";
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 13;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 12.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 12);
  if ( (gfxv.Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
    gfxv.pObjectInterface = nullptr;
  }
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Type = VT_String;
  gfxv.Value.pString = "KEY_B";
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 14;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 13.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 13);
  if ( (gfxv.Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
    gfxv.pObjectInterface = nullptr;
  }
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Type = VT_String;
  gfxv.Value.pString = "KEY_C";
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 15;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 14.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 14);
  if ( (gfxv.Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
    gfxv.pObjectInterface = nullptr;
  }
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Type = VT_String;
  gfxv.Value.pString = "KEY_D";
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 16;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 15.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 15);
  if ( (gfxv.Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
    gfxv.pObjectInterface = nullptr;
  }
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Type = VT_String;
  gfxv.Value.pString = "KEY_E";
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 17;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 16.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 16);
  if ( (gfxv.Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
    gfxv.pObjectInterface = nullptr;
  }
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Type = VT_String;
  gfxv.Value.pString = "KEY_F";
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 18;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 17.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 17);
  if ( (gfxv.Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
    gfxv.pObjectInterface = nullptr;
  }
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Type = VT_String;
  gfxv.Value.pString = "KEY_G";
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 19;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 18.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 18);
  if ( (gfxv.Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
    gfxv.pObjectInterface = nullptr;
  }
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Type = VT_String;
  gfxv.Value.pString = "KEY_H";
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 20;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 19.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 19);
  if ( (gfxv.Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
    gfxv.pObjectInterface = nullptr;
  }
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Type = VT_String;
  gfxv.Value.pString = "KEY_I";
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 21;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 20.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 20);
  if ( (gfxv.Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
    gfxv.pObjectInterface = nullptr;
  }
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Type = VT_String;
  gfxv.Value.pString = "KEY_J";
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 22;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 21.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 21);
  if ( (gfxv.Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
    gfxv.pObjectInterface = nullptr;
  }
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Type = VT_String;
  gfxv.Value.pString = "KEY_K";
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 23;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 22.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 22);
  if ( (gfxv.Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
    gfxv.pObjectInterface = nullptr;
  }
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Type = VT_String;
  gfxv.Value.pString = "KEY_L";
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 24;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 23.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 23);
  if ( (gfxv.Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
    gfxv.pObjectInterface = nullptr;
  }
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Type = VT_String;
  gfxv.Value.pString = "KEY_M";
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 25;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 24.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 24);
  if ( (gfxv.Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
    gfxv.pObjectInterface = nullptr;
  }
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Type = VT_String;
  gfxv.Value.pString = "KEY_N";
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 26;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 25.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 25);
  if ( (gfxv.Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
    gfxv.pObjectInterface = nullptr;
  }
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Type = VT_String;
  gfxv.Value.pString = "KEY_O";
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 27;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 26.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 26);
  GFxValue::SetString(this: &gfxv, p: "KEY_P");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 28;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 27.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 27);
  GFxValue::SetString(this: &gfxv, p: "KEY_Q");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 29;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 28.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 28);
  GFxValue::SetString(this: &gfxv, p: "KEY_R");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 30;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 29.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 29);
  GFxValue::SetString(this: &gfxv, p: "KEY_S");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 31;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 30.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 30);
  GFxValue::SetString(this: &gfxv, p: "KEY_T");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 32;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 31.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 31);
  GFxValue::SetString(this: &gfxv, p: "KEY_U");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 33;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 32.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 32);
  GFxValue::SetString(this: &gfxv, p: "KEY_V");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 34;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 33.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 33);
  GFxValue::SetString(this: &gfxv, p: "KEY_W");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 35;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 34.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 34);
  GFxValue::SetString(this: &gfxv, p: "KEY_X");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 36;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 35.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 35);
  GFxValue::SetString(this: &gfxv, p: "KEY_Y");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 37;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 36.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 36);
  GFxValue::SetString(this: &gfxv, p: "KEY_Z");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 38;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 37.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 37);
  GFxValue::SetString(this: &gfxv, p: "KEY_PAD_0");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 39;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 38.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 38);
  GFxValue::SetString(this: &gfxv, p: "KEY_PAD_1");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 40;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 39.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 39);
  GFxValue::SetString(this: &gfxv, p: "KEY_PAD_2");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 41;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 40.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 40);
  GFxValue::SetString(this: &gfxv, p: "KEY_PAD_3");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 42;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 41.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 41);
  GFxValue::SetString(this: &gfxv, p: "KEY_PAD_4");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 43;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 42.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 42);
  GFxValue::SetString(this: &gfxv, p: "KEY_PAD_5");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 44;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 43.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 43);
  GFxValue::SetString(this: &gfxv, p: "KEY_PAD_6");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 45;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 44.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 44);
  GFxValue::SetString(this: &gfxv, p: "KEY_PAD_7");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 46;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 45.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 45);
  GFxValue::SetString(this: &gfxv, p: "KEY_PAD_8");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 47;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 46.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 46);
  GFxValue::SetString(this: &gfxv, p: "KEY_PAD_9");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 48;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 47.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 47);
  GFxValue::SetString(this: &gfxv, p: "KEY_PAD_DIVIDE");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 49;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 48.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 48);
  GFxValue::SetString(this: &gfxv, p: "KEY_PAD_MULTIPLY");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 50;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 49.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 49);
  GFxValue::SetString(this: &gfxv, p: "KEY_PAD_MINUS");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 51;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 50.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 50);
  GFxValue::SetString(this: &gfxv, p: "KEY_PAD_PLUS");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 52;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 51.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 51);
  GFxValue::SetString(this: &gfxv, p: "KEY_PAD_ENTER");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 53;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 52.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 52);
  GFxValue::SetString(this: &gfxv, p: "KEY_PAD_DECIMAL");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 54;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 53.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 53);
  GFxValue::SetString(this: &gfxv, p: "KEY_LBRACKET");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 55;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 54.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 54);
  GFxValue::SetString(this: &gfxv, p: "KEY_RBRACKET");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 56;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 55.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 55);
  GFxValue::SetString(this: &gfxv, p: "KEY_SEMICOLON");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 57;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 56.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 56);
  GFxValue::SetString(this: &gfxv, p: "KEY_APOSTROPHE");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 58;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 57.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 57);
  GFxValue::SetString(this: &gfxv, p: "KEY_BACKQUOTE");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 59;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 58.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 58);
  GFxValue::SetString(this: &gfxv, p: "KEY_COMMA");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 60;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 59.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 59);
  GFxValue::SetString(this: &gfxv, p: "KEY_PERIOD");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 61;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 60.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 60);
  GFxValue::SetString(this: &gfxv, p: "KEY_SLASH");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 62;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 61.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 61);
  GFxValue::SetString(this: &gfxv, p: "KEY_BACKSLASH");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 63;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 62.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 62);
  GFxValue::SetString(this: &gfxv, p: "KEY_MINUS");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 64;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 63.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 63);
  GFxValue::SetString(this: &gfxv, p: "KEY_EQUAL");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 65;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 64.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 64);
  GFxValue::SetString(this: &gfxv, p: "KEY_ENTER");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 66;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 65.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 65);
  GFxValue::SetString(this: &gfxv, p: "KEY_SPACE");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 67;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 66.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 66);
  GFxValue::SetString(this: &gfxv, p: "KEY_BACKSPACE");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 68;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 67.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 67);
  GFxValue::SetString(this: &gfxv, p: "KEY_TAB");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 69;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 68.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 68);
  GFxValue::SetString(this: &gfxv, p: "KEY_CAPSLOCK");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 70;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 69.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 69);
  GFxValue::SetString(this: &gfxv, p: "KEY_NUMLOCK");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 71;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 70.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 70);
  GFxValue::SetString(this: &gfxv, p: "KEY_ESCAPE");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 72;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 71.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 71);
  GFxValue::SetString(this: &gfxv, p: "KEY_SCROLLLOCK");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 73;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 72.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 72);
  GFxValue::SetString(this: &gfxv, p: "KEY_INSERT");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 74;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 73.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 73);
  GFxValue::SetString(this: &gfxv, p: "KEY_DELETE");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 75;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 74.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 74);
  GFxValue::SetString(this: &gfxv, p: "KEY_HOME");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 76;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 75.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 75);
  GFxValue::SetString(this: &gfxv, p: "KEY_END");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 77;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 76.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 76);
  GFxValue::SetString(this: &gfxv, p: "KEY_PAGEUP");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 78;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 77.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 77);
  GFxValue::SetString(this: &gfxv, p: "KEY_PAGEDOWN");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 79;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 78.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 78);
  GFxValue::SetString(this: &gfxv, p: "KEY_BREAK");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 80;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 79.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 79);
  GFxValue::SetString(this: &gfxv, p: "KEY_LSHIFT");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  LOBYTE(v7) = 81;
  gfxv.Type = VT_Number;
  gfxv.Value.NValue = 80.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 80);
  GFxValue::SetString(this: &gfxv, p: "KEY_RSHIFT");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 82;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 81.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 81);
  GFxValue::SetString(this: &gfxv, p: "KEY_LALT");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 83;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 82.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 82);
  GFxValue::SetString(this: &gfxv, p: "KEY_RALT");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 84;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 83.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 83);
  GFxValue::SetString(this: &gfxv, p: "KEY_LCONTROL");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 85;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 84.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 84);
  GFxValue::SetString(this: &gfxv, p: "KEY_RCONTROL");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 86;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 85.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 85);
  GFxValue::SetString(this: &gfxv, p: "KEY_LWIN");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 87;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 86.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 86);
  GFxValue::SetString(this: &gfxv, p: "KEY_RWIN");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 88;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 87.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 87);
  GFxValue::SetString(this: &gfxv, p: "KEY_APP");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 89;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 88.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 88);
  GFxValue::SetString(this: &gfxv, p: "KEY_UP");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 90;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 89.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 89);
  GFxValue::SetString(this: &gfxv, p: "KEY_LEFT");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 91;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 90.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 90);
  GFxValue::SetString(this: &gfxv, p: "KEY_DOWN");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 92;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 91.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 91);
  GFxValue::SetString(this: &gfxv, p: "KEY_RIGHT");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 93;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 92.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 92);
  GFxValue::SetString(this: &gfxv, p: "KEY_F1");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 94;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 93.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 93);
  GFxValue::SetString(this: &gfxv, p: "KEY_F2");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 95;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 94.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 94);
  GFxValue::SetString(this: &gfxv, p: "KEY_F3");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 96;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 95.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 95);
  GFxValue::SetString(this: &gfxv, p: "KEY_F4");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 97;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 96.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 96);
  GFxValue::SetString(this: &gfxv, p: "KEY_F5");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 98;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 97.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 97);
  GFxValue::SetString(this: &gfxv, p: "KEY_F6");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 99;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 98.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 98);
  GFxValue::SetString(this: &gfxv, p: "KEY_F7");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 100;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 99.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 99);
  GFxValue::SetString(this: &gfxv, p: "KEY_F8");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 101;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 100.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 100);
  GFxValue::SetString(this: &gfxv, p: "KEY_F9");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 102;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 101.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 101);
  GFxValue::SetString(this: &gfxv, p: "KEY_F10");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 103;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 102.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 102);
  GFxValue::SetString(this: &gfxv, p: "KEY_F11");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 104;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 103.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 103);
  GFxValue::SetString(this: &gfxv, p: "KEY_F12");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 105;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 104.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 104);
  GFxValue::SetString(this: &gfxv, p: "KEY_CAPSLOCKTOGGLE");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 106;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 105.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 105);
  GFxValue::SetString(this: &gfxv, p: "KEY_NUMLOCKTOGGLE");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 107;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 106.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 106);
  GFxValue::SetString(this: &gfxv, p: "KEY_SCROLLLOCKTOGGLE");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 108;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 107.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 107);
  GFxValue::SetString(this: &gfxv, p: "MOUSE_LEFT");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 109;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 108.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 108);
  GFxValue::SetString(this: &gfxv, p: "MOUSE_RIGHT");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 110;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 109.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 109);
  GFxValue::SetString(this: &gfxv, p: "MOUSE_MIDDLE");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 111;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 110.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 110);
  GFxValue::SetString(this: &gfxv, p: "MOUSE_4");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 112;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 111.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 111);
  GFxValue::SetString(this: &gfxv, p: "MOUSE_5");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 113;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 112.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 112);
  GFxValue::SetString(this: &gfxv, p: "MOUSE_WHEEL_UP");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 114;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 113.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 113);
  GFxValue::SetString(this: &gfxv, p: "MOUSE_WHEEL_DOWN");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 115;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 242.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 242);
  GFxValue::SetString(this: &gfxv, p: "KEY_XBUTTON_UP");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 116;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 243.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 243);
  GFxValue::SetString(this: &gfxv, p: "KEY_XBUTTON_RIGHT");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 117;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 244.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 244);
  GFxValue::SetString(this: &gfxv, p: "KEY_XBUTTON_DOWN");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 118;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 245.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 245);
  GFxValue::SetString(this: &gfxv, p: "KEY_XBUTTON_LEFT");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 119;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 114.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 114);
  GFxValue::SetString(this: &gfxv, p: "KEY_XBUTTON_A");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 120;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 115.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 115);
  GFxValue::SetString(this: &gfxv, p: "KEY_XBUTTON_B");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 121;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 116.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 116);
  GFxValue::SetString(this: &gfxv, p: "KEY_XBUTTON_X");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 122;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 117.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 117);
  GFxValue::SetString(this: &gfxv, p: "KEY_XBUTTON_Y");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 123;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 118.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 118);
  GFxValue::SetString(this: &gfxv, p: "KEY_XBUTTON_LEFT_SHOULDER");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 124;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 119.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 119);
  GFxValue::SetString(this: &gfxv, p: "KEY_XBUTTON_RIGHT_SHOULDER");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 125;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 120.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 120);
  GFxValue::SetString(this: &gfxv, p: "KEY_XBUTTON_BACK");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 126;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 121.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 121);
  GFxValue::SetString(this: &gfxv, p: "KEY_XBUTTON_START");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 127;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 122.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 122);
  GFxValue::SetString(this: &gfxv, p: "KEY_XBUTTON_STICK1");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = 0x80;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 123.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 123);
  GFxValue::SetString(this: &gfxv, p: "KEY_XBUTTON_STICK2");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = -127;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 124.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 124);
  GFxValue::SetString(this: &gfxv, p: "KEY_XBUTTON_INACTIVE_START");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = -126;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 258.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 258);
  GFxValue::SetString(this: &gfxv, p: "KEY_XSTICK1_RIGHT");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = -125;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 259.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 259);
  GFxValue::SetString(this: &gfxv, p: "KEY_XSTICK1_LEFT");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = -124;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 260.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 260);
  GFxValue::SetString(this: &gfxv, p: "KEY_XSTICK1_DOWN");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = -123;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 261.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 261);
  GFxValue::SetString(this: &gfxv, p: "KEY_XSTICK1_UP");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = -122;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 262.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 262);
  GFxValue::SetString(this: &gfxv, p: "KEY_XBUTTON_LTRIGGER");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = -121;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 263.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 263);
  GFxValue::SetString(this: &gfxv, p: "KEY_XBUTTON_RTRIGGER");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = -120;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 264.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 264);
  GFxValue::SetString(this: &gfxv, p: "KEY_XSTICK2_RIGHT");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = -119;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 265.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 265);
  GFxValue::SetString(this: &gfxv, p: "KEY_XSTICK2_LEFT");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = -118;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 266.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 266);
  GFxValue::SetString(this: &gfxv, p: "KEY_XSTICK2_DOWN");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
  gfxv.pObjectInterface = nullptr;
  gfxv.Type = VT_Undefined;
  LOBYTE(v7) = -117;
  GFxValue::ChangeType(this: &gfxv, type: VT_Number);
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  gfxv.Value.NValue = 267.0;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  V_snprintf(pDest: numberAsString, maxLen: 10, pFormat: "%d", 267);
  GFxValue::SetString(this: &gfxv, p: "KEY_XSTICK2_UP");
  LOBYTE(v6) = (keyTable.Type & 0x8F) == 8;
  GFxValue::ObjectInterface::SetMember(
    this: (CStringPool *)keyTable.pObjectInterface,
    pdata: (unsigned int)keyTable.Value.pString);
  LOBYTE(v7) = 0;
  if ( (gfxv.Type & 0x40) != 0 )
  {
    GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)gfxv.pObjectInterface, val: (StringPoolCase_t)&gfxv);
    gfxv.pObjectInterface = nullptr;
  }
  v7 = -1;
  if ( (keyTable.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(
      this: (CStringPool *)keyTable.pObjectInterface,
      val: (StringPoolCase_t)&keyTable);
}

//------------------------------------------------------------------------------
// Address: 0x1000D3A0
// Name: public: void BaseSlot::Init(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge BaseSlot::Init(
        BaseSlot *this@<ecx>,
        int a2@<edi>,
        const char *movieName,
        const ScaleformUIFunctionHandlerDefinition *slot)
{
  GFxMovieDef *MovieDef; // eax
  GFxMovieView *Instance; // eax
  CStringPool **p_m_GlobalValue; // edi
  CStringPool *v8; // ecx
  GFxMovieView *m_pMovieView; // ecx
  void (__thiscall *SetViewport)(GFxMovieView *, const GViewport *); // edx
  const char *pString; // [esp+20h] [ebp-78h]
  _DWORD v12[13]; // [esp+38h] [ebp-60h] BYREF
  GFxValue number; // [esp+6Ch] [ebp-2Ch] BYREF
  GFxValue platformCode; // [esp+7Ch] [ebp-1Ch] BYREF
  int v15; // [esp+94h] [ebp-4h]
  const ScaleformUIFunctionHandlerDefinition *table; // [esp+A4h] [ebp+Ch]

  this->m_iSlot = (int)slot;
  MovieDef = (GFxMovieDef *)ScaleformUIImpl::CreateMovieDef(
                              this: &ScaleformUIImpl::m_Instance,
                              pfilename: movieName,
                              loadConstants: 0,
                              memoryArena: 0);
  this->m_pMovieDef = MovieDef;
  if ( MovieDef != nullptr )
  {
    Instance = (GFxMovieView *)ScaleformUIImpl::MovieDef_CreateInstance(
                                 this: &ScaleformUIImpl::m_Instance,
                                 movieDef: MovieDef,
                                 initFirstFrame: true,
                                 memoryArena: 0);
    this->m_pMovieView = Instance;
    ((void (__thiscall *)(GFxMovieView *, _DWORD, int))Instance->SetViewScaleMode)(a1: Instance, a2: 0, a3: a2);
    this->m_pMovieView->SetViewAlignment(this: this->m_pMovieView, a2: Align_TopLeft);
    p_m_GlobalValue = (CStringPool **)&this->m_GlobalValue;
    this->m_pMovieView->GetVariable(this: this->m_pMovieView, a2: &this->m_GlobalValue, a3: "_global");
    platformCode.pObjectInterface = nullptr;
    platformCode.Type = VT_Undefined;
    v15 = 0;
    if ( ScaleformUIImpl::m_Instance.m_bForcePS3 )
    {
      platformCode.Type = VT_Number;
      platformCode.Value.NValue = 2.0;
    }
    else
    {
      GFxValue::SetNumber(this: &platformCode, v: 0.0);
    }
    GFxValue::ObjectInterface::SetMember(this: *p_m_GlobalValue, pdata: (unsigned int)this->m_GlobalValue.Value.pString);
    number.pObjectInterface = nullptr;
    pString = this->m_GlobalValue.Value.pString;
    v8 = *p_m_GlobalValue;
    LOBYTE(v15) = 1;
    number.Type = VT_Number;
    number.Value.NValue = (double)(int)slot;
    GFxValue::ObjectInterface::SetMember(this: v8, pdata: (unsigned int)pString);
    table = this->GetSlotAPITable(this);
    if ( table != nullptr )
    {
      this->m_pMovieView->CreateObject(this: this->m_pMovieView, a2: &this->m_GameAPI, a3: nullptr, a4: nullptr, a5: 0);
      for ( ; table->m_pName != nullptr; ++table )
        ScaleformUIImpl::AddAPIFunctionToObject(
          this: &ScaleformUIImpl::m_Instance,
          pAPI: &this->m_GameAPI,
          pMovie: this->m_pMovieView,
          object: (ScaleformUIFunctionHandlerObject *)this,
          pFunctionDef: table);
      GFxValue::ObjectInterface::SetMember(
        this: *p_m_GlobalValue,
        pdata: (unsigned int)this->m_GlobalValue.Value.pString);
    }
    BaseSlot::CreateKeyTable(this);
    ((void (__cdecl *)(_DWORD))this->m_pMovieView->SetBackgroundAlpha)(a1: 0);
    ((void (__stdcall *)(_DWORD, int))this->m_pMovieView->Advance)(a1: 0, a2: 2);
    m_pMovieView = this->m_pMovieView;
    v12[1] = ScaleformUIImpl::m_Instance.m_iScreenHeight;
    v12[5] = ScaleformUIImpl::m_Instance.m_iScreenHeight;
    SetViewport = m_pMovieView->SetViewport;
    v12[0] = ScaleformUIImpl::m_Instance.m_iScreenWidth;
    v12[4] = ScaleformUIImpl::m_Instance.m_iScreenWidth;
    v12[2] = 0;
    v12[3] = 0;
    v12[12] = 0;
    memset(&v12[6], 0, 16);
    v12[11] = 1065353216;
    v12[10] = 1065353216;
    SetViewport(this: m_pMovieView, a2: (const GViewport *)v12);
    GFxValue::ObjectInterface::Invoke(
      this: (GFxValue::ObjectInterface *)*p_m_GlobalValue,
      a2: this->m_GlobalValue.Value.pStringManaged,
      a3: nullptr,
      a4: "ForceResize",
      a5: nullptr,
      a6: 0,
      a7: (this->m_GlobalValue.Type & 0x8F) == 8);
    LOBYTE(v15) = 0;
    if ( (number.Type & 0x40) != 0 )
    {
      GFxValue::ObjectInterface::ObjectRelease(
        this: (CStringPool *)number.pObjectInterface,
        val: (StringPoolCase_t)&number);
      number.pObjectInterface = nullptr;
    }
    v15 = -1;
    if ( (platformCode.Type & 0x40) != 0 )
      GFxValue::ObjectInterface::ObjectRelease(
        this: (CStringPool *)platformCode.pObjectInterface,
        val: (StringPoolCase_t)&platformCode);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D630
// Name: protected: virtual void BaseSlot::Unload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BaseSlot::Unload(BaseSlot *this)
{
  CStringPool **p_m_GlobalValue; // edi
  CStringPool *pObjectInterface; // ecx
  CStringPool **p_m_GameAPI; // ebx
  unsigned int v5; // edx
  const char *pString; // [esp-18h] [ebp-3Ch]
  GFxValue value; // [esp+4h] [ebp-20h] BYREF
  int v8; // [esp+14h] [ebp-10h]
  int v9; // [esp+20h] [ebp-4h]

  if ( this->m_pMovieView != nullptr )
  {
    value.pObjectInterface = nullptr;
    v9 = 0;
    p_m_GlobalValue = (CStringPool **)&this->m_GlobalValue;
    LOBYTE(v8) = (this->m_GlobalValue.Type & 0x8F) == 8;
    pString = this->m_GlobalValue.Value.pString;
    pObjectInterface = (CStringPool *)this->m_GlobalValue.pObjectInterface;
    value.Type = VT_Null;
    GFxValue::ObjectInterface::SetMember(this: pObjectInterface, pdata: (unsigned int)pString);
    p_m_GameAPI = (CStringPool **)&this->m_GameAPI;
    if ( (this->m_GameAPI.Type & 0x40) != 0 )
    {
      GFxValue::ObjectInterface::ObjectRelease(this: *p_m_GameAPI, val: (StringPoolCase_t)&this->m_GameAPI);
      *p_m_GameAPI = nullptr;
    }
    this->m_GameAPI.Type = VT_Null;
    if ( (this->m_GlobalValue.Type & 0x40) != 0 )
    {
      GFxValue::ObjectInterface::ObjectRelease(this: *p_m_GlobalValue, val: (StringPoolCase_t)&this->m_GlobalValue);
      *p_m_GlobalValue = nullptr;
    }
    this->m_GlobalValue.Type = VT_Null;
    ScaleformUIImpl::ReleaseMovieView(this: &ScaleformUIImpl::m_Instance, movieView: this->m_pMovieView);
    ScaleformUIImpl::ReleaseMovieDef(this: &ScaleformUIImpl::m_Instance, movieDef: this->m_pMovieDef);
    v5 = (unsigned int)value.Type >> 6;
    this->m_pMovieView = nullptr;
    this->m_pMovieDef = nullptr;
    v9 = -1;
    if ( (v5 & 1) != 0 )
      GFxValue::ObjectInterface::ObjectRelease(
        this: (CStringPool *)value.pObjectInterface,
        val: (StringPoolCase_t)&value);
    this->m_iSlot = -1;
  }
  else
  {
    this->m_iSlot = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D750
// Name: public: bool BaseSlot::Release(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall BaseSlot::Release(BaseSlot *this)
{
  bool v2; // zf
  bool v3; // bl
  CStringPool **p_m_GameAPI; // edi
  CStringPool **p_m_GlobalValue; // edi

  v2 = this->m_iRefCount-- == 1;
  v3 = v2;
  if ( v2 )
  {
    this->Unload(this);
    p_m_GameAPI = (CStringPool **)&this->m_GameAPI;
    if ( (this->m_GameAPI.Type & 0x40) != 0 )
    {
      GFxValue::ObjectInterface::ObjectRelease(this: *p_m_GameAPI, val: (StringPoolCase_t)&this->m_GameAPI);
      *p_m_GameAPI = nullptr;
    }
    p_m_GlobalValue = (CStringPool **)&this->m_GlobalValue;
    if ( (this->m_GlobalValue.Type & 0x40) != 0 )
    {
      GFxValue::ObjectInterface::ObjectRelease(this: *p_m_GlobalValue, val: (StringPoolCase_t)&this->m_GlobalValue);
      *p_m_GlobalValue = nullptr;
    }
    free(pMem: this);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1000D7F0
// Name: public: void CursorSlot::SetCursorShape(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CursorSlot::SetCursorShape(CursorSlot *this, unsigned int shape)
{
  __m128i v2; // xmm0
  char *pString; // eax
  GFxValue::ObjectInterface *pObjectInterface; // ecx
  GFxValue newShape; // [esp+0h] [ebp-1Ch] BYREF
  int v6; // [esp+18h] [ebp-4h]
  bool shapea; // [esp+24h] [ebp+8h]

  newShape.pObjectInterface = nullptr;
  v2 = _mm_cvtsi32_si128(shape);
  shapea = (this->m_GlobalValue.Type & 0x8F) == 8;
  v6 = 0;
  pString = (char *)this->m_GlobalValue.Value.pString;
  pObjectInterface = this->m_GlobalValue.pObjectInterface;
  newShape.Type = VT_Number;
  newShape.Value.NValue = _mm_cvtepi32_pd(v2).m128d_f64[0];
  GFxValue::ObjectInterface::Invoke(
    this: pObjectInterface,
    a2: pString,
    a3: nullptr,
    a4: "SetCursorShape",
    a5: &newShape,
    a6: 1u,
    a7: shapea);
  v6 = -1;
  if ( (newShape.Type & 0x40) != 0 )
    GFxValue::ObjectInterface::ObjectRelease(
      this: (CStringPool *)newShape.pObjectInterface,
      val: (StringPoolCase_t)&newShape);
}

//------------------------------------------------------------------------------
// Address: 0x10013D50
// Name: public: virtual FlashArrayVisitor::~FlashArrayVisitor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FlashArrayVisitor::~FlashArrayVisitor(FlashArrayVisitor *this)
{
  this->__vftable = (FlashArrayVisitor_vtbl *)&GFxValue::ObjectInterface::ArrVisitor::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x102529E0
// Name: int G_strcmp(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl G_strcmp(const char *s1, const char *s2)
{
  return strcmp(s1, s2);
}
