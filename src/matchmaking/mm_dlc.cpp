// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/mm_dlc.cpp
// Functions: 5
// ============================================================

#include "matchmaking\mm_dlc.h"

//------------------------------------------------------------------------------
// Address: 0x10024EA0
// Name: public: void CDlcManager::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDlcManager::Update(CDlcManager *this)
{
  if ( this->m_eState == 0 && this->m_bNeedToUpdateFileSystem )
  {
    this->m_bNeedToUpdateFileSystem = false;
    g_pFullFileSystem->DiscoverDLC(this: g_pFullFileSystem, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024ED0
// Name: public: virtual bool CDlcManager::IsDlcUpdateFinished(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDlcManager::IsDlcUpdateFinished(CDlcManager *this, bool bWaitForFinish)
{
  double v4; // st7
  float flTimestamp; // [esp+14h] [ebp+8h]

  if ( this->m_eState != 0 )
  {
    if ( !bWaitForFinish )
      return 0;
    flTimestamp = _Plat_FloatTime();
    while ( this->m_eState != 0 )
      _ThreadSleep(a1: 1);
    v4 = _Plat_FloatTime();
    _Warning(a1: "DLCMANAGER: Forcing wait for update to finish stalled for %.3f sec\n", v4 - flTimestamp);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10024F40
// Name: protected: void CDlcManager::Steam_OnDLCInstalled(struct DlcInstalled_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDlcManager::Steam_OnDLCInstalled(CDlcManager *this, DlcInstalled_t *pParam)
{
  CDlcManager *v2; // ebx
  IMatchTitle *v3; // eax
  int v4; // esi
  IMatchTitle *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  IMatchSystem *v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  const TitleDataFieldsDescription_t *v13; // edi
  int m_numBytesOffset; // ebx
  int v15; // eax
  char v16; // cl
  unsigned __int64 v17; // rax
  unsigned __int64 Uint64; // rax
  void (__thiscall *UpdatePlayerTitleData)(IPlayerLocal *, const TitleDataFieldsDescription_t *, const void *, int); // eax
  unsigned __int64 v20; // kr08_8
  KeyValues *v21; // eax
  KeyValues *v22; // esi
  IMatchEventsSubscription *v23; // eax
  unsigned __int64 uiOldDlcMask; // [esp+8h] [ebp-20h]
  int uiNewDlcMask_4; // [esp+14h] [ebp-14h]
  const TitleDataFieldsDescription_t *fields; // [esp+18h] [ebp-10h]
  IPlayerLocal *pPlayerLocal; // [esp+1Ch] [ebp-Ch]
  char v29; // [esp+27h] [ebp-1h] BYREF

  v2 = this;
  this->m_bNeedToDiscoverAllDlcs = false;
  v3 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
  v4 = (int)v3->DescribeTitleDlcs(this: v3);
  if ( v4 != 0 )
  {
    v5 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
    fields = v5->DescribeTitleDataStorage(this: v5);
    uiOldDlcMask = KeyValues::GetUint64(this: v2->m_pDataInfo, keyName: "@info/installed", defaultValue: 0);
    if ( v2->m_pDataInfo == nullptr )
    {
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "DlcManager");
      else
        v7 = nullptr;
      v2->m_pDataInfo = v7;
      KeyValues::SetUint64(this: v7, keyName: "@info/installed", value: 0);
    }
    v8 = g_pMatchFramework->GetMatchSystem(this: g_pMatchFramework);
    v9 = v8->GetPlayerManager(this: v8);
    v10 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v9 + 4))(a1: v9, a2: 0);
    v11 = *(_DWORD *)(v4 + 4);
    pPlayerLocal = (IPlayerLocal *)v10;
    v12 = *(_DWORD *)v4;
    if ( *(_QWORD *)v4 != 0 )
    {
      do
      {
        if ( ((unsigned int)uiOldDlcMask & v12) != v12 || (HIDWORD(uiOldDlcMask) & v11) != v11 )
        {
          if ( *(_DWORD *)(v4 + 16) == 0 )
          {
            v13 = nullptr;
LABEL_16:
            if ( steamapicontext->m_pSteamApps->BIsSubscribedApp(
                   this: steamapicontext->m_pSteamApps,
                   a2: *(_DWORD *)(v4 + 8)) )
            {
              Uint64 = KeyValues::GetUint64(this: v2->m_pDataInfo, keyName: "@info/installed", defaultValue: 0);
              KeyValues::SetUint64(this: v2->m_pDataInfo, keyName: "@info/installed", value: *(_QWORD *)v4 | Uint64);
              if ( v13 != nullptr && pPlayerLocal != nullptr )
              {
                UpdatePlayerTitleData = pPlayerLocal->UpdatePlayerTitleData;
                v29 = -1;
                UpdatePlayerTitleData(this: pPlayerLocal, a2: v13, a3: &v29, a4: 1);
              }
            }
            goto LABEL_20;
          }
          v13 = TitleDataFieldsDescriptionFindByString(fields, szString: *(const char **)(v4 + 16));
          if ( v13 == nullptr )
            goto LABEL_16;
          if ( pPlayerLocal == nullptr )
            goto LABEL_16;
          m_numBytesOffset = v13->m_numBytesOffset;
          uiNewDlcMask_4 = (int)pPlayerLocal->GetPlayerTitleData(this: pPlayerLocal, a2: v13->m_iTitleDataBlock);
          v15 = m_numBytesOffset / 8;
          v16 = m_numBytesOffset % 8;
          v2 = this;
          if ( ((unsigned __int8)(1 << v16) & *(_BYTE *)(uiNewDlcMask_4 + v15)) == 0 )
            goto LABEL_16;
          v17 = KeyValues::GetUint64(this: this->m_pDataInfo, keyName: "@info/installed", defaultValue: 0);
          KeyValues::SetUint64(this: this->m_pDataInfo, keyName: "@info/installed", value: *(_QWORD *)v4 | v17);
        }
LABEL_20:
        v12 = *(_DWORD *)(v4 + 24);
        v11 = *(_DWORD *)(v4 + 28);
        v4 += 24;
      }
      while ( (v11 | v12) != 0 );
    }
    v20 = KeyValues::GetUint64(this: v2->m_pDataInfo, keyName: "@info/installed", defaultValue: 0);
    if ( v20 != uiOldDlcMask )
    {
      v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v21 != nullptr )
        v22 = KeyValues::KeyValues(this: v21, setName: "OnDowloadableContentInstalled");
      else
        v22 = nullptr;
      KeyValues::SetUint64(this: v22, keyName: "installed", value: v20);
      v23 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
      v23->BroadcastEvent(this: v23, a2: v22);
      v2->m_bNeedToUpdateFileSystem = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025220
// Name: mm_dlc_debugprint
// Source: json
//------------------------------------------------------------------------------
void __cdecl mm_dlc_debugprint()
{
  KeyValues *v0; // eax
  IKeyValuesDumpContext pDump; // [esp+0h] [ebp-8h] BYREF
  int v2; // [esp+4h] [ebp-4h]

  v0 = g_pDlcManager->GetDataInfo(this: g_pDlcManager);
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v2 = 1;
  KeyValues::Dump(this: v0, &pDump, nIndentLevel: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10025260
// Name: public: virtual void CDlcManager::RequestDlcUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDlcManager::RequestDlcUpdate(CDlcManager *this)
{
  CDlcManager::State_t m_eState; // eax
  int v3; // eax
  const char *v4; // eax

  m_eState = this->m_eState;
  if ( m_eState <= 0 )
  {
    if ( m_eState != 0 || this->m_bNeedToDiscoverAllDlcs )
    {
      v3 = _CommandLine();
      v4 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
      if ( V_stristr(pStr: v4, pSearch: "-dlc") != nullptr )
      {
        this->m_eState = 0;
        *(_WORD *)&this->m_bNeedToDiscoverAllDlcs = 256;
      }
      else
      {
        CCallback<CDlcManager,DlcInstalled_t,0>::Register(
          this: &this->m_CallbackOnDLCInstalled,
          pObj: this,
          func: (void (__thiscall *__ptr64)(CDlcManager *, DlcInstalled_t *))(unsigned int)CDlcManager::Steam_OnDLCInstalled);
        CDlcManager::Steam_OnDLCInstalled(this, pParam: nullptr);
      }
    }
    else
    {
      _Msg(a1: "DLCMANAGER: RequestDlcUpdate has no new content.\n");
    }
  }
}
