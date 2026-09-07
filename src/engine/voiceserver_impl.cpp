// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/voiceserver_impl.cpp
// Functions: 4
// ============================================================

#include "engine\voiceserver_impl.h"

//------------------------------------------------------------------------------
// Address: 0x101EFBE0
// Name: public: void CBitVecT<class CFixedBitVecBase<64>>::Set(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitVecT<CFixedBitVecBase<64>>::Set(CBitVecT<CFixedBitVecBase<64> > *this, int bitNum, bool bNewVal)
{
  unsigned int *v3; // edx
  int v4; // eax

  v3 = &this->m_Ints[bitNum >> 5];
  v4 = 1 << (bitNum & 0x1F);
  if ( bNewVal )
    *v3 |= v4;
  else
    *v3 &= ~v4;
}

//------------------------------------------------------------------------------
// Address: 0x101EFC10
// Name: public: virtual bool CVoiceServer::GetClientListening(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVoiceServer::GetClientListening(CVoiceServer *this, int iReceiver, int iSender)
{
  int v3; // eax
  CBaseClient *v4; // eax

  v3 = iSender - 1;
  if ( iReceiver - 1 < 0 || iReceiver - 1 >= sv.m_Clients.m_Size || v3 < 0 || v3 >= sv.m_Clients.m_Size )
    return false;
  v4 = sv.m_Clients.m_Memory.m_pMemory[v3];
  if ( v4 != nullptr )
    return v4->IsHearingClient(this: &v4->IClient, a2: iReceiver - 1);
  else
    return (*(bool (__stdcall **)(int))(MEMORY[0] + 144))(a1: iReceiver - 1);
}

//------------------------------------------------------------------------------
// Address: 0x101EFC70
// Name: public: virtual bool CVoiceServer::SetClientListening(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVoiceServer::SetClientListening(CVoiceServer *this, int iReceiver, int iSender, bool bListen)
{
  int v4; // eax
  int v5; // esi
  CGameClient *v6; // edi
  char *v7; // ebx
  INetChannel *v8; // eax
  INetChannel *(__thiscall *GetNetChannel)(IClient *); // eax
  IClient *v10; // edi
  int v11; // eax
  int v12; // eax
  const char *v13; // eax
  const char *v15; // [esp-14h] [ebp-24h]
  const char *v16; // [esp-10h] [ebp-20h]
  const char *v17; // [esp-Ch] [ebp-1Ch]
  ConVarRef voice_verbose; // [esp+4h] [ebp-Ch] BYREF
  CGameClient *v19; // [esp+Ch] [ebp-4h]
  char *iReceivera; // [esp+18h] [ebp+8h]
  const char *iSendera; // [esp+1Ch] [ebp+Ch]

  v4 = iSender - 1;
  v5 = iReceiver - 1;
  if ( iReceiver - 1 < 0 || v5 >= sv.m_Clients.m_Size || v4 < 0 || v4 >= sv.m_Clients.m_Size )
    return 0;
  v6 = (CGameClient *)sv.m_Clients.m_Memory.m_pMemory[v4];
  v19 = v6;
  ConVarRef::ConVarRef(this: &voice_verbose, pName: "voice_verbose");
  if ( voice_verbose.m_pConVarState->m_Value.m_nValue != 0
    && ((v6->m_VoiceStreams.m_Ints[(unsigned int)v5 >> 5] & (1 << (v5 & 0x1F))) != 0) != bListen )
  {
    v7 = &args.m_pArgvBuffer[228];
    if ( sv.m_Clients.m_Memory.m_pMemory[v5]->GetNetChannel(this: &sv.m_Clients.m_Memory.m_pMemory[v5]->IClient) != nullptr )
    {
      v8 = sv.m_Clients.m_Memory.m_pMemory[v5]->GetNetChannel(this: &sv.m_Clients.m_Memory.m_pMemory[v5]->IClient);
      iReceivera = (char *)v8->GetAddress(this: v8);
    }
    else
    {
      iReceivera = &args.m_pArgvBuffer[228];
    }
    GetNetChannel = v6->GetNetChannel;
    v10 = &v6->IClient;
    if ( (int)GetNetChannel(this: v10) != 0 )
    {
      v11 = (int)v10->GetNetChannel(this: v10);
      v7 = (char *)(*(int (__thiscall **)(int))(*(_DWORD *)v11 + 4))(a1: v11);
    }
    iSendera = "Enable";
    if ( !bListen )
      iSendera = "Disable";
    v12 = ((int (__thiscall *)(IClient *, char *))sv.m_Clients.m_Memory.m_pMemory[v5]->GetClientName)(
            a1: &sv.m_Clients.m_Memory.m_pMemory[v5]->IClient,
            a2: iReceivera);
    v13 = (const char *)((int (__thiscall *)(IClient *, char *, int))v10->GetClientName)(a1: v10, a2: v7, a3: v12);
    _Msg(
      a1: "* CVoiceServer::SetClientListening:  %s m_VoiceStreams from %s (%s) to %s (%s)\n",
      iSendera,
      v13,
      v15,
      v16,
      v17);
    v6 = v19;
  }
  CBitVecT<CFixedBitVecBase<64>>::Set(this: &v6->m_VoiceStreams, bitNum: v5, bNewVal: bListen);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101EFDE0
// Name: public: virtual bool CVoiceServer::SetClientProximity(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVoiceServer::SetClientProximity(CVoiceServer *this, int iReceiver, int iSender, bool bUseProximity)
{
  int v4; // ecx

  v4 = iSender - 1;
  if ( iReceiver - 1 < 0 || iReceiver - 1 >= sv.m_Clients.m_Size || v4 < 0 || v4 >= sv.m_Clients.m_Size )
    return 0;
  CBitVecT<CFixedBitVecBase<64>>::Set(
    this: (CBitVecT<CFixedBitVecBase<64> > *)&sv.m_Clients.m_Memory.m_pMemory[v4][1].m_Name[16],
    bitNum: iReceiver - 1,
    bNewVal: bUseProximity);
  return 1;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101EFE90
// Name: public: void CBitVecT<class CFixedBitVecBase<64>>::Set(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitVecT<CFixedBitVecBase<64>>::Set(CBitVecT<CFixedBitVecBase<64> > *this, int bitNum, bool bNewVal)
{
  unsigned int *v3; // edx
  int v4; // eax

  v3 = &this->m_Ints[bitNum >> 5];
  v4 = 1 << (bitNum & 0x1F);
  if ( bNewVal )
    *v3 |= v4;
  else
    *v3 &= ~v4;
}

//------------------------------------------------------------------------------
// Address: 0x101EFEC0
// Name: public: virtual bool CVoiceServer::GetClientListening(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVoiceServer::GetClientListening(CVoiceServer *this, int iReceiver, int iSender)
{
  int v3; // eax
  CBaseClient *v4; // eax

  v3 = iSender - 1;
  if ( iReceiver - 1 < 0 || iReceiver - 1 >= sv.m_Clients.m_Size || v3 < 0 || v3 >= sv.m_Clients.m_Size )
    return false;
  v4 = sv.m_Clients.m_Memory.m_pMemory[v3];
  if ( v4 != nullptr )
    return v4->IsHearingClient(this: &v4->IClient, a2: iReceiver - 1);
  else
    return (*(bool (__stdcall **)(int))(MEMORY[0] + 144))(a1: iReceiver - 1);
}

//------------------------------------------------------------------------------
// Address: 0x101EFF20
// Name: public: virtual bool CVoiceServer::SetClientListening(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVoiceServer::SetClientListening(CVoiceServer *this, int iReceiver, int iSender, bool bListen)
{
  int v4; // eax
  int v5; // esi
  CGameClient *v6; // edi
  char *v7; // ebx
  INetChannel *v8; // eax
  INetChannel *(__thiscall *GetNetChannel)(IClient *); // eax
  IClient *v10; // edi
  int v11; // eax
  int v12; // eax
  const char *v13; // eax
  const char *v15; // [esp-14h] [ebp-24h]
  const char *v16; // [esp-10h] [ebp-20h]
  const char *v17; // [esp-Ch] [ebp-1Ch]
  ConVarRef voice_verbose; // [esp+4h] [ebp-Ch] BYREF
  CGameClient *v19; // [esp+Ch] [ebp-4h]
  char *iReceivera; // [esp+18h] [ebp+8h]
  const char *iSendera; // [esp+1Ch] [ebp+Ch]

  v4 = iSender - 1;
  v5 = iReceiver - 1;
  if ( iReceiver - 1 < 0 || v5 >= sv.m_Clients.m_Size || v4 < 0 || v4 >= sv.m_Clients.m_Size )
    return 0;
  v6 = (CGameClient *)sv.m_Clients.m_Memory.m_pMemory[v4];
  v19 = v6;
  ConVarRef::ConVarRef(this: &voice_verbose, pName: "voice_verbose");
  if ( voice_verbose.m_pConVarState->m_Value.m_nValue != 0
    && ((v6->m_VoiceStreams.m_Ints[(unsigned int)v5 >> 5] & (1 << (v5 & 0x1F))) != 0) != bListen )
  {
    v7 = &args.m_pArgvBuffer[228];
    if ( sv.m_Clients.m_Memory.m_pMemory[v5]->GetNetChannel(this: &sv.m_Clients.m_Memory.m_pMemory[v5]->IClient) != nullptr )
    {
      v8 = sv.m_Clients.m_Memory.m_pMemory[v5]->GetNetChannel(this: &sv.m_Clients.m_Memory.m_pMemory[v5]->IClient);
      iReceivera = (char *)v8->GetAddress(this: v8);
    }
    else
    {
      iReceivera = &args.m_pArgvBuffer[228];
    }
    GetNetChannel = v6->GetNetChannel;
    v10 = &v6->IClient;
    if ( (int)GetNetChannel(this: v10) != 0 )
    {
      v11 = (int)v10->GetNetChannel(this: v10);
      v7 = (char *)(*(int (__thiscall **)(int))(*(_DWORD *)v11 + 4))(a1: v11);
    }
    iSendera = "Enable";
    if ( !bListen )
      iSendera = "Disable";
    v12 = ((int (__thiscall *)(IClient *, char *))sv.m_Clients.m_Memory.m_pMemory[v5]->GetClientName)(
            a1: &sv.m_Clients.m_Memory.m_pMemory[v5]->IClient,
            a2: iReceivera);
    v13 = (const char *)((int (__thiscall *)(IClient *, char *, int))v10->GetClientName)(a1: v10, a2: v7, a3: v12);
    _Msg(
      a1: "* CVoiceServer::SetClientListening:  %s m_VoiceStreams from %s (%s) to %s (%s)\n",
      iSendera,
      v13,
      v15,
      v16,
      v17);
    v6 = v19;
  }
  CBitVecT<CFixedBitVecBase<64>>::Set(this: &v6->m_VoiceStreams, bitNum: v5, bNewVal: bListen);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F0090
// Name: public: virtual bool CVoiceServer::SetClientProximity(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVoiceServer::SetClientProximity(CVoiceServer *this, int iReceiver, int iSender, bool bUseProximity)
{
  int v4; // ecx

  v4 = iSender - 1;
  if ( iReceiver - 1 < 0 || iReceiver - 1 >= sv.m_Clients.m_Size || v4 < 0 || v4 >= sv.m_Clients.m_Size )
    return 0;
  CBitVecT<CFixedBitVecBase<64>>::Set(
    this: (CBitVecT<CFixedBitVecBase<64> > *)&sv.m_Clients.m_Memory.m_pMemory[v4][1].m_Name[16],
    bitNum: iReceiver - 1,
    bNewVal: bUseProximity);
  return 1;
}

} // namespace engine_xlsp
