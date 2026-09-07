// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/amp/gfxampservercallbacks.cpp
// Functions: 3
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\amp\gfxampservercallbacks.h"

//------------------------------------------------------------------------------
// Address: 0x10101EE0
// Name: public: virtual bool GFxAmpSendThreadCallback::OnSendLoop(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxAmpSendThreadCallback::OnSendLoop(GFxAmpSendThreadCallback *this)
{
  GFxAmpServer *Instance; // eax

  Instance = (GFxAmpServer *)GFxAmpServer::GetInstance(this);
  return GFxAmpServer::HandleNextMessage(this: Instance);
}

//------------------------------------------------------------------------------
// Address: 0x10101EF0
// Name: public: virtual void GFxAmpStatusChangedCallback::OnStatusChanged(enum GFxAmpConnStatusInterface::StatusType,enum GFxAmpConnStatusInterface::StatusType,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall GFxAmpStatusChangedCallback::OnStatusChanged(
        CMatLightmaps *this,
        enum GFxAmpConnStatusInterface::StatusType a2,
        enum GFxAmpConnStatusInterface::StatusType a3,
        const char *a4)
{
  GFxAmpServer *Instance; // eax
  void *v6; // ecx
  GFxAmpServer *v7; // eax
  int m_nAllocationCount; // ecx
  const CDbgFmtMsg *v9; // [esp-4h] [ebp-Ch]

  if ( a2 != a3 )
  {
    if ( a2 == CS_OK )
    {
      Instance = (GFxAmpServer *)GFxAmpServer::GetInstance(this);
      GFxAmpServer::SendAppControlCaps(this: Instance);
      v7 = (GFxAmpServer *)GFxAmpServer::GetInstance(this: v6);
      GFxAmpServer::SendCurrentState(this: v7);
    }
    m_nAllocationCount = this->m_ImagePackers.m_Memory.m_nAllocationCount;
    if ( m_nAllocationCount != 0 )
    {
      if ( a2 == CS_OK )
        GEvent::SetEvent(a1: m_nAllocationCount, a2: this);
      else
        GEvent::ResetEvent(this: m_nAllocationCount, result: v9);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10101F40
// Name: public: GFxAmpStatusChangedCallback::GFxAmpStatusChangedCallback(class GEvent __near *)
// Source: json
//------------------------------------------------------------------------------
GFxAmpStatusChangedCallback *__thiscall GFxAmpStatusChangedCallback::GFxAmpStatusChangedCallback(
        GFxAmpStatusChangedCallback *this,
        struct GEvent *a2)
{
  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 2) = &GString::InitStruct::`vftable';
  *(_DWORD *)this = &GFxAmpSendThreadCallback::`vftable'{for `GRefCountBase<GFxAmpSendThreadCallback,2>'};
  *((_DWORD *)this + 2) = &GFxAmpStatusChangedCallback::`vftable'{for `GFxAmpConnStatusInterface'};
  *((_DWORD *)this + 3) = a2;
  return this;
}
