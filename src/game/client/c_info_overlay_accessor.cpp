// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_info_overlay_accessor.cpp
// Functions: 15
// ============================================================

#include "game\client\c_info_overlay_accessor.h"

//------------------------------------------------------------------------------
// Address: 0x10076D80
// Name: public: virtual class ClientClass __near * C_InfoOverlayAccessor::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_InfoOverlayAccessor::GetClientClass(C_InfoOverlayAccessor *this)
{
  return &__g_C_InfoOverlayAccessorClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10076E10
// Name: public: virtual void C_InfoOverlayAccessor::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_InfoOverlayAccessor::OnDataChanged(C_InfoOverlayAccessor *this, DataUpdateType_t updateType)
{
  IVEngineClient_vtbl *v3; // edi
  int v4; // eax

  if ( updateType == DATA_UPDATE_CREATED )
  {
    v3 = engine->__vftable;
    v4 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 2) + 20))(a1: (char *)this - 8);
    v3->SetOverlayBindProxy(this: engine, a2: *(_DWORD *)&this->m_bIsBlurred, a3: (void *)v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10076EC0
// Name: public: virtual void C_InfoOverlayAccessor::GetToolRecordingState(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_InfoOverlayAccessor::GetToolRecordingState(C_InfoOverlayAccessor *this, KeyValues *msg)
{
  KeyValues *NonConformantKeyValues; // edi
  const char *HandlerIDKeyString; // eax
  int TextureFrameIndex; // eax
  _BYTE *Ptr; // eax
  BaseEntityRecordingState_t dummyState; // [esp+Ch] [ebp-38h] BYREF

  C_BaseEntity::GetToolRecordingState(this, msg);
  NonConformantKeyValues = CIFM_EntityKeyValuesHandler_AutoRegister::FindOrCreateNonConformantKeyValues(pParentKV: msg);
  HandlerIDKeyString = CIFM_EntityKeyValuesHandler_AutoRegister::GetHandlerIDKeyString();
  KeyValues::SetString(this: NonConformantKeyValues, keyName: HandlerIDKeyString, value: "C_InfoOverlayAccessor");
  KeyValues::SetInt(this: NonConformantKeyValues, keyName: "entIndex", value: this->index);
  KeyValues::SetInt(this: NonConformantKeyValues, keyName: "overlayID", value: this->m_iOverlayID);
  TextureFrameIndex = C_BaseEntity::GetTextureFrameIndex(this);
  KeyValues::SetInt(this: NonConformantKeyValues, keyName: "textureFrame", value: TextureFrameIndex);
  *((_BYTE *)&dummyState + 16) &= 0xFCu;
  dummyState.m_flTime = 0.0;
  dummyState.m_pModelName = nullptr;
  dummyState.m_nOwner = -1;
  dummyState.m_fEffects = 0;
  dummyState.m_nFollowEntity = -1;
  dummyState.m_numEffects = 0;
  dummyState.m_pEffects = nullptr;
  memset((void *)&dummyState.m_vecRenderOrigin, 0, 24);
  Ptr = KeyValues::GetPtr(this: msg, keyName: "baseentity", defaultValue: &dummyState);
  Ptr[16] |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x10076F90
// Name: public: virtual void __near * C_InfoOverlayAccessor_NonConformantDataHandler::CreateInstance(void)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall C_InfoOverlayAccessor_NonConformantDataHandler::CreateInstance(
        C_InfoOverlayAccessor_NonConformantDataHandler *this)
{
  C_BaseEntity *v1; // eax
  _DWORD *v2; // esi

  v1 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x988u);
  v2 = &v1->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v1 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v1);
  *v2 = &C_InfoOverlayAccessor::`vftable'{for `IClientUnknown'};
  v2[1] = &C_InfoOverlayAccessor::`vftable'{for `IClientRenderable'};
  v2[2] = &C_InfoOverlayAccessor::`vftable'{for `IClientNetworkable'};
  v2[3] = &C_InfoOverlayAccessor::`vftable'{for `IClientThinkable'};
  v2[4] = &C_InfoOverlayAccessor::`vftable';
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10076FE0
// Name: public: virtual void C_InfoOverlayAccessor_NonConformantDataHandler::DestroyInstance(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_InfoOverlayAccessor_NonConformantDataHandler::DestroyInstance(
        C_InfoOverlayAccessor_NonConformantDataHandler *this,
        _DWORD *pEntity)
{
  engine->SetOverlayBindProxy(this: engine, a2: pEntity[608], a3: nullptr);
  (*(void (__thiscall **)(_DWORD *, int))*pEntity)(a1: pEntity, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10077010
// Name: public: virtual void C_InfoOverlayAccessor_NonConformantDataHandler::HandleInstance(void __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_InfoOverlayAccessor_NonConformantDataHandler::HandleInstance(
        C_InfoOverlayAccessor_NonConformantDataHandler *this,
        C_BaseEntity *pEntity,
        KeyValues *pKeyValues)
{
  unsigned __int8 Int; // al
  IVEngineClient_vtbl *v4; // edi
  int v5; // eax

  pEntity[1].IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseEntity_vtbl *)KeyValues::GetInt(
                                                                                              this: pKeyValues,
                                                                                              keyName: "overlayID",
                                                                                              defaultValue: 0);
  Int = KeyValues::GetInt(this: pKeyValues, keyName: "textureFrame", defaultValue: 0);
  C_BaseEntity::SetTextureFrameIndex(this: pEntity, iIndex: Int);
  v4 = engine->__vftable;
  v5 = (int)pEntity->GetClientRenderable(this: pEntity);
  v4->SetOverlayBindProxy(
    this: engine,
    a2: (int)pEntity[1].IClientEntity::IClientUnknown::IHandleEntity::__vftable,
    a3: (void *)v5);
}

//------------------------------------------------------------------------------
// Address: 0x10412760
// Name: DT_InfoOverlayAccessor::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_InfoOverlayAccessor::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_InfoOverlayAccessor::g_RecvTable);
  return atexit(func: DT_InfoOverlayAccessor::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412780
// Name: DT_InfoOverlayAccessor::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_InfoOverlayAccessor::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_InfoOverlayAccessor::ignored>();
  DT_InfoOverlayAccessor::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104305F0
// Name: DT_InfoOverlayAccessor::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_InfoOverlayAccessor::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_InfoOverlayAccessor::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10076E50
// Name: _C_InfoOverlayAccessor_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_InfoOverlayAccessor_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x988u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  *v3 = &C_InfoOverlayAccessor::`vftable'{for `IClientUnknown'};
  v3[1] = &C_InfoOverlayAccessor::`vftable'{for `IClientRenderable'};
  v3[2] = &C_InfoOverlayAccessor::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_InfoOverlayAccessor::`vftable'{for `IClientThinkable'};
  v3[4] = &C_InfoOverlayAccessor::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10412790
// Name: _dynamic_initializer_for__s_InfoOverlayAccessorEntityIFMHandler__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_InfoOverlayAccessorEntityIFMHandler__()
{
  CIFM_EntityKeyValuesHandler_RecreateEntities::CIFM_EntityKeyValuesHandler_RecreateEntities(
    this: &s_InfoOverlayAccessorEntityIFMHandler,
    szHandlerID: "C_InfoOverlayAccessor");
  s_InfoOverlayAccessorEntityIFMHandler.__vftable = (C_InfoOverlayAccessor_NonConformantDataHandler_vtbl *)&C_InfoOverlayAccessor_NonConformantDataHandler::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__s_InfoOverlayAccessorEntityIFMHandler__);
}

//------------------------------------------------------------------------------
// Address: 0x104127C0
// Name: _dynamic_initializer_for__g_KeyValueSaver__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KeyValueSaver__()
{
  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this: &g_KeyValueSaver, name: "C_KeyValueSaver");
  byte_10605DC4 = 0;
  dword_10605DC0 = 42;
  g_KeyValueSaver.__vftable = (CAutoGameSystemPerFrame_vtbl *)&C_KeyValueSaver::`vftable'{for `CAutoGameSystemPerFrame'};
  dword_10605DBC = (int)&C_KeyValueSaver::`vftable'{for `CGameEventListener'};
  dword_10605DC8 = 0;
  dword_10605DCC = 0;
  dword_10605DD0 = 0;
  dword_10605DD4 = 0;
  dword_10605DD8 = 0;
  dword_10605DDC = -1;
  return atexit(func: dynamic_atexit_destructor_for__g_KeyValueSaver__);
}

//------------------------------------------------------------------------------
// Address: 0x10412830
// Name: _dynamic_initializer_for____g_C_LightGlowClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_LightGlowClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_LightGlowClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_LightGlowClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430600
// Name: _dynamic_atexit_destructor_for__s_InfoOverlayAccessorEntityIFMHandler__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_InfoOverlayAccessorEntityIFMHandler__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_InfoOverlayAccessorEntityIFMHandler.m_PlaybackEntities);
}

//------------------------------------------------------------------------------
// Address: 0x10430610
// Name: _dynamic_atexit_destructor_for__g_KeyValueSaver__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_KeyValueSaver__()
{
  void *v0; // eax

  v0 = (void *)dword_10605DC8;
  dword_10605DD4 = 0;
  if ( dword_10605DD0 >= 0 )
  {
    if ( dword_10605DC8 != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)dword_10605DC8);
      v0 = nullptr;
      dword_10605DC8 = 0;
    }
    dword_10605DCC = 0;
  }
  dword_10605DD8 = (int)v0;
  if ( dword_10605DD0 >= 0 )
  {
    if ( v0 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v0);
      dword_10605DC8 = 0;
    }
    dword_10605DCC = 0;
  }
  dword_10605DBC = (int)&CGameEventListener::`vftable';
  dword_10605DC0 = 13;
  if ( byte_10605DC4 != 0 )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: (IGameEventListener2 *)&dword_10605DBC);
    byte_10605DC4 = 0;
  }
  dword_10605DBC = (int)&IGameEventListener2::`vftable';
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &g_KeyValueSaver);
}
