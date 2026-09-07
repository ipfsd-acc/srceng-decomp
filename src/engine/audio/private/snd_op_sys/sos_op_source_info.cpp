// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_op_sys/sos_op_source_info.cpp
// Functions: 6
// ============================================================

#include "engine\audio\private\snd_op_sys\sos_op_source_info.h"

//------------------------------------------------------------------------------
// Address: 0x1004D5F0
// Name: public: virtual void CSosOperatorSourceInfo::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSourceInfo::SetDefaults(CSosOperatorSourceInfo *this, _DWORD *pVoidMem)
{
  pVoidMem[3] = 0;
  pVoidMem[4] = 0;
  pVoidMem[5] = 0;
  pVoidMem[6] = 0;
  pVoidMem[7] = 0;
  pVoidMem[8] = 0;
  pVoidMem[9] = 0;
  pVoidMem[10] = 0;
  pVoidMem[11] = 0;
  pVoidMem[12] = 0;
  pVoidMem[13] = 1065353216;
  pVoidMem[14] = 0;
  pVoidMem[15] = -1;
  pVoidMem[16] = 1;
  *((_BYTE *)pVoidMem + 68) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004D660
// Name: public: virtual void CSosOperatorSourceInfo::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSourceInfo::Print(
        CSosOperatorSourceInfo *this,
        CSosOperator_t *pVoidMem,
        CSosOperatorStack *pStack,
        const char *nOpIndex,
        int nLevel)
{
  CSosOperator::PrintBaseParams(this, pVoidMem, pStack, nOpIndex, nLevel);
  if ( pVoidMem[5].m_flExecuteOffset[0] == 1 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
      LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: OpColor, a4: "%*sSource: emitter\n", nLevel, "    ");
  }
  else if ( pVoidMem[5].m_flExecuteOffset[0] == 2
         && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: OpColor, a4: "%*sSource: entity\n", nLevel, "    ");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004D6F0
// Name: public: virtual void CSosOperatorSourceInfo::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSourceInfo::ParseKV(
        CSosOperatorSourceInfo *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *FirstSubKey; // edi
  const char *Name; // esi
  const char *String; // eax
  const char *v7; // edi
  KeyValues *pParams; // [esp+18h] [ebp+10h]

  FirstSubKey = KeyValues::GetFirstSubKey(this: pOpKeys);
  pParams = FirstSubKey;
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstSubKey);
      String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: defaultValue);
      v7 = String;
      if ( Name != nullptr
        && *Name != 0
        && String != nullptr
        && *String != 0
        && CSosOperator::BaseParseKV(this, pStack, pStructMem: pVoidMem, pParamString: Name, pValueString: String) == 0 )
      {
        if ( V_strcasecmp(s1: Name, s2: "source") != 0 )
        {
          if ( V_strcasecmp(s1: Name, s2: "game_multi_origin") != 0 )
          {
            if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
              _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
          }
          else
          {
            pVoidMem[5].m_bExecuteOnce = V_strcasecmp(s1: v7, s2: "true") == 0;
          }
        }
        else if ( V_strcasecmp(s1: v7, s2: "none") != 0 )
        {
          if ( V_strcasecmp(s1: v7, s2: "emitter") != 0 )
          {
            if ( V_strcasecmp(s1: v7, s2: "entity") == 0 )
              pVoidMem[5].m_flExecuteOffset[0] = 2;
          }
          else
          {
            pVoidMem[5].m_flExecuteOffset[0] = 1;
          }
        }
        else
        {
          pVoidMem[5].m_flExecuteOffset[0] = 0;
        }
      }
      pParams = KeyValues::GetNextKey(this: pParams);
      if ( pParams == nullptr )
        break;
      FirstSubKey = pParams;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004D840
// Name: public: virtual void CSosOperatorSourceInfo::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CSosOperatorSourceInfo::Execute(
        CSosOperatorSourceInfo *this@<ecx>,
        _DWORD *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        __int128 nOpIndex)
{
  channel_t *v6; // esi
  CScratchPad *v7; // ebx
  float y; // edx
  float z; // eax
  float dist_mult; // xmm1_4
  const char *v12; // eax
  int soundsource; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int m_nSoundScriptHandle; // edx
  char *v18; // eax
  char v19[16]; // [esp+28h] [ebp-1BCh] BYREF
  char nameBuf[260]; // [esp+4Ch] [ebp-198h] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > utlVecMultiOrigins; // [esp+150h] [ebp-94h] BYREF
  CUtlVector<QAngle,CUtlMemory<QAngle,int> > utlVecMultiAngles; // [esp+164h] [ebp-80h] BYREF
  _BYTE v23[108]; // [esp+178h] [ebp-6Ch] OVERLAPPED BYREF
  float v24; // [esp+1ECh] [ebp+8h]

  v6 = pChannel;
  *(_DWORD *)&v23[80] = this;
  if ( pChannel != nullptr )
  {
    v7 = pScratchPad;
    HIBYTE(pChannel) = pVoidMem[16] == 2;
    if ( pScratchPad->m_UtlVecMultiOrigins.m_Size < 1 )
    {
      y = v6->origin.y;
      *(float *)&v23[96] = v6->origin.x;
      z = v6->origin.z;
      *(_DWORD *)&v23[8] = 1065353216;
      dist_mult = v6->dist_mult;
      *(float *)&v23[104] = z;
      memset(&v23[84], 0, 12);
      *(float *)&v23[100] = y;
      pScratchPad = nullptr;
      memset(&v23[12], 0, 16);
      *(_DWORD *)&v23[52] = 75;
      *(_DWORD *)&v23[32] = 100;
      *(_DWORD *)&v23[44] = -1;
      *(_DWORD *)&v23[28] = 6;
      *(_DWORD *)&v23[40] = 0;
      *(_DWORD *)&v23[36] = 0;
      *(_DWORD *)&v23[48] = 0;
      *(_DWORD *)&v23[4] = 0;
      v23[58] = 0;
      *(_WORD *)&v23[56] = 0;
      memset(&utlVecMultiOrigins.m_Memory.m_nGrowSize, 0, 12);
      memset(&utlVecMultiAngles, 0, sizeof(utlVecMultiAngles));
      *(_DWORD *)v23 = 0;
      if ( dist_mult == 0.0 )
        v24 = 0.0;
      else
        v24 = __FYL2X__(
                snd_refdb_dist_mult / (snd_refdist.m_pParent->m_Value.m_fValue * dist_mult),
                0.3010299956639811952)
            * 20.0;
      if ( v6->sfx != nullptr )
        v12 = v6->sfx->getname(this: v6->sfx, a2: v19, a3: 260u);
      else
        v12 = defaultValue;
      SoundInfo_t::Set(
        this: (SoundInfo_t *)&utlVecMultiOrigins.m_Memory.m_nGrowSize,
        newEntity: v6->soundsource,
        newChannel: v6->entchannel,
        pszNewName: v12,
        newOrigin: &v6->origin,
        newDirection: &v6->direction,
        newVolume: (float)v6->master_vol,
        newSoundLevel: (soundlevel_t)v24,
        newLooping: v7->m_bIsLooping,
        newPitch: (int)v6->pitch,
        vecListenerOrigin: &v7->m_vBlendedListenerOrigin,
        speakerentity: v6->speakerentity,
        nSeed: 0);
      *(_DWORD *)&v23[68] = &pScratchPad;
      *(_DWORD *)&v23[60] = &v23[96];
      *(_DWORD *)&v23[76] = 0;
      memset(&nameBuf[224], 0, 36);
      utlVecMultiOrigins.m_Memory.m_pMemory = nullptr;
      *(_DWORD *)&v23[72] = &v7->m_UtlVecMultiOrigins;
      *(_DWORD *)&v23[64] = &v23[84];
      soundsource = v6->soundsource;
      utlVecMultiOrigins.m_Memory.m_nAllocationCount = 1;
      if ( (g_pSoundServices->GetSoundSpatialization(
              this: g_pSoundServices,
              a2: soundsource,
              a3: (SpatializationInfo_t *)&utlVecMultiOrigins.m_Memory.m_nAllocationCount)
          & HIBYTE(pChannel)) == 0 )
        *(_DWORD *)&v23[60] = &utlVecMultiOrigins.m_Memory.m_nGrowSize;
      if ( *((_BYTE *)pVoidMem + 68) != 0 )
        g_ClientDLL->GetSoundSpatialization(
          this: g_ClientDLL,
          a2: (SpatializationInfo_t *)&utlVecMultiOrigins.m_Memory.m_nAllocationCount);
      v7->m_vEntityInfoAngle.x = *(float *)&v23[84];
      v7->m_vEntityInfoAngle.y = *(float *)&v23[88];
      v7->m_vEntityInfoAngle.z = *(float *)&v23[92];
      v7->m_vEntityInfoOrigin.x = *(float *)&v23[96];
      v7->m_vEntityInfoOrigin.y = *(float *)&v23[100];
      v7->m_vEntityInfoOrigin.z = *(float *)&v23[104];
      LODWORD(v7->m_flEntityInfoRadius) = pScratchPad;
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&nameBuf[244]);
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&nameBuf[224]);
    }
    v14 = (int)*((float *)pVoidMem + 14);
    *((float *)pVoidMem + 13) = (float)v7->m_UtlVecMultiOrigins.m_Size;
    if ( v14 != 0 )
    {
      v16 = v14;
      *((float *)pVoidMem + 3) = v7->m_UtlVecMultiOrigins.m_Memory.m_pMemory[v16 - 1].x;
      *((float *)pVoidMem + 4) = v7->m_UtlVecMultiOrigins.m_Memory.m_pMemory[v16 - 1].y;
      *((float *)pVoidMem + 5) = v7->m_UtlVecMultiOrigins.m_Memory.m_pMemory[v16 - 1].z;
    }
    else
    {
      v15 = pVoidMem[16];
      if ( v15 == 2 )
      {
        *((float *)pVoidMem + 3) = v7->m_vEntityInfoOrigin.x;
        *((float *)pVoidMem + 4) = v7->m_vEntityInfoOrigin.y;
        *((float *)pVoidMem + 5) = v7->m_vEntityInfoOrigin.z;
        *((float *)pVoidMem + 6) = v7->m_vEntityInfoAngle.x;
        *((float *)pVoidMem + 7) = v7->m_vEntityInfoAngle.y;
        *((float *)pVoidMem + 8) = v7->m_vEntityInfoAngle.z;
        *((float *)pVoidMem + 9) = v7->m_flEntityInfoRadius;
      }
      else if ( v15 == 1 )
      {
        *((float *)pVoidMem + 3) = v6->origin.x;
        *((float *)pVoidMem + 4) = v6->origin.y;
        *((float *)pVoidMem + 5) = v6->origin.z;
        VectorAngles(forward: &v6->direction, angles: (QAngle *)&v23[96]);
        pVoidMem[6] = *(_DWORD *)&v23[96];
        pVoidMem[7] = *(_DWORD *)&v23[100];
        pVoidMem[8] = *(_DWORD *)&v23[104];
        *((float *)pVoidMem + 9) = v6->radius;
      }
    }
    *((float *)pVoidMem + 10) = (double)v6->master_vol * 0.00392156862745098;
    *((float *)pVoidMem + 11) = v6->m_flSoundLevel;
    *((float *)pVoidMem + 12) = (double)v6->basePitch * 0.01;
    if ( snd_sos_show_source_info.m_pParent != nullptr && snd_sos_show_source_info.m_pParent->m_Value.m_nValue != 0 )
    {
      m_nSoundScriptHandle = v6->m_nSoundScriptHandle;
      *(_DWORD *)&v23[96] = pVoidMem[3];
      *(_DWORD *)&v23[100] = pVoidMem[4];
      *(_DWORD *)&v23[104] = pVoidMem[5];
      v18 = (char *)g_pSoundEmitterSystem->GetSoundName(this: g_pSoundEmitterSystem, a2: m_nSoundScriptHandle);
      CDebugOverlay::AddTextOverlay(textPos: (const Vector *)&v23[96], duration: 2.0, text: v18);
    }
    if ( snd_sos_show_operator_updates.m_pParent != nullptr
      && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
    {
      (*(void (__thiscall **)(_DWORD, _DWORD *, CSosOperatorStack *, _DWORD, _DWORD))(**(_DWORD **)&v23[80] + 16))(
        a1: *(_DWORD *)&v23[80],
        a2: pVoidMem,
        a3: pStack,
        a4: nOpIndex,
        a5: 0);
    }
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
  {
    _LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: 1,
      a3: "Error: Sound operator %s requires valid channel pointer, being called without one\n",
      pStack->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[nOpIndex].m_Data.key);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004DD00
// Name: public: CSosOperatorSourceInfo::CSosOperatorSourceInfo(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorSourceInfo *__thiscall CSosOperatorSourceInfo::CSosOperatorSourceInfo(CSosOperatorSourceInfo *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v8; // [esp-8h] [ebp-28h]
  int v9; // [esp-8h] [ebp-28h]
  int v10; // [esp-8h] [ebp-28h]
  int v11; // [esp-8h] [ebp-28h]
  CSosOperator::InputData_t src; // [esp+Ch] [ebp-14h] BYREF
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorSourceInfo_vtbl *)&CSosOperatorSourceInfo::`vftable';
  m_Size = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 12;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 3;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: m_Size,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_position", element: &nIndex);
  v2 = this->m_vOutputs.m_Size;
  src.m_nCount = 3;
  src.m_nOffsetOffset = 24;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v2,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_angles", element: &nIndex);
  v8 = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 36;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v8,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_radius", element: &nIndex);
  v9 = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 40;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v9,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_volume", element: &nIndex);
  v3 = this->m_vOutputs.m_Size;
  src.m_nCount = 1;
  src.m_nOffsetOffset = 44;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v3,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_level", element: &nIndex);
  v10 = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 48;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v10,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_pitch", element: &nIndex);
  v11 = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 52;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v11,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_source_count", element: &nIndex);
  v4 = this->m_vInputs.m_Size;
  src.m_nCount = 1;
  src.m_nOffset = 56;
  src.m_nOffsetOffset = 60;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v4,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_source_index", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "get_source_info",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004DF20
// Name: public: virtual unsigned int CSosOperatorSourceInfo::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorSourceInfo::GetSize(CSosOperatorSourceInfo *this)
{
  return 72;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1004D3E0
// Name: public: virtual void CSosOperatorSourceInfo::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSourceInfo::SetDefaults(CSosOperatorSourceInfo *this, _DWORD *pVoidMem)
{
  pVoidMem[3] = 0;
  pVoidMem[4] = 0;
  pVoidMem[5] = 0;
  pVoidMem[6] = 0;
  pVoidMem[7] = 0;
  pVoidMem[8] = 0;
  pVoidMem[9] = 0;
  pVoidMem[10] = 0;
  pVoidMem[11] = 0;
  pVoidMem[12] = 0;
  pVoidMem[13] = 1065353216;
  pVoidMem[14] = 0;
  pVoidMem[15] = -1;
  pVoidMem[16] = 1;
  *((_BYTE *)pVoidMem + 68) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004D450
// Name: public: virtual void CSosOperatorSourceInfo::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSourceInfo::Print(
        CSosOperatorSourceInfo *this,
        CSosOperator_t *pVoidMem,
        CSosOperatorStack *pStack,
        const char *nOpIndex,
        int nLevel)
{
  CSosOperator::PrintBaseParams(this, pVoidMem, pStack, nOpIndex, nLevel);
  if ( pVoidMem[5].m_flExecuteOffset[0] == 1 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
      LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: OpColor, a4: "%*sSource: emitter\n", nLevel, "    ");
  }
  else if ( pVoidMem[5].m_flExecuteOffset[0] == 2
         && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: OpColor, a4: "%*sSource: entity\n", nLevel, "    ");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004D4E0
// Name: public: virtual void CSosOperatorSourceInfo::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSourceInfo::ParseKV(
        CSosOperatorSourceInfo *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *FirstSubKey; // edi
  const char *Name; // esi
  const char *String; // eax
  const char *v7; // edi
  KeyValues *pParams; // [esp+18h] [ebp+10h]

  FirstSubKey = KeyValues::GetFirstSubKey(this: pOpKeys);
  pParams = FirstSubKey;
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstSubKey);
      String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: defaultValue);
      v7 = String;
      if ( Name != nullptr
        && *Name != 0
        && String != nullptr
        && *String != 0
        && CSosOperator::BaseParseKV(this, pStack, pStructMem: pVoidMem, pParamString: Name, pValueString: String) == 0 )
      {
        if ( V_strcasecmp(s1: Name, s2: "source") != 0 )
        {
          if ( V_strcasecmp(s1: Name, s2: "game_multi_origin") != 0 )
          {
            if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
              _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
          }
          else
          {
            pVoidMem[5].m_bExecuteOnce = V_strcasecmp(s1: v7, s2: "true") == 0;
          }
        }
        else if ( V_strcasecmp(s1: v7, s2: "none") != 0 )
        {
          if ( V_strcasecmp(s1: v7, s2: "emitter") != 0 )
          {
            if ( V_strcasecmp(s1: v7, s2: "entity") == 0 )
              pVoidMem[5].m_flExecuteOffset[0] = 2;
          }
          else
          {
            pVoidMem[5].m_flExecuteOffset[0] = 1;
          }
        }
        else
        {
          pVoidMem[5].m_flExecuteOffset[0] = 0;
        }
      }
      pParams = KeyValues::GetNextKey(this: pParams);
      if ( pParams == nullptr )
        break;
      FirstSubKey = pParams;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004D630
// Name: public: virtual void CSosOperatorSourceInfo::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSourceInfo::Execute(
        CSosOperatorSourceInfo *this,
        void *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  CScratchPad *v7; // ebx
  float y; // edx
  float z; // eax
  float dist_mult; // xmm1_4
  const char *v12; // eax
  int soundsource; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int m_nSoundScriptHandle; // edx
  const char *v18; // eax
  char nameBuf[260]; // [esp+28h] [ebp-1BCh] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > utlVecMultiOrigins; // [esp+12Ch] [ebp-B8h] BYREF
  CUtlVector<QAngle,CUtlMemory<QAngle,int> > utlVecMultiAngles; // [esp+140h] [ebp-A4h] BYREF
  SpatializationInfo_t v22; // [esp+154h] [ebp-90h] BYREF
  CSosOperatorSourceInfo *v23; // [esp+1C8h] [ebp-1Ch]
  QAngle source_angles; // [esp+1CCh] [ebp-18h] BYREF
  Vector vDebug; // [esp+1D8h] [ebp-Ch] BYREF
  float pVoidMema; // [esp+1ECh] [ebp+8h]
  bool bUseEntity_3; // [esp+1F3h] [ebp+Fh]

  v23 = this;
  if ( pChannel != nullptr )
  {
    v7 = pScratchPad;
    bUseEntity_3 = *((_DWORD *)pVoidMem + 16) == 2;
    if ( pScratchPad->m_UtlVecMultiOrigins.m_Size < 1 )
    {
      y = pChannel->origin.y;
      vDebug.x = pChannel->origin.x;
      z = pChannel->origin.z;
      v22.info.fVolume = 1.0;
      dist_mult = pChannel->dist_mult;
      vDebug.z = z;
      memset((void *)&source_angles, 0, sizeof(source_angles));
      vDebug.y = y;
      pScratchPad = nullptr;
      memset(&v22.info.fDelay, 0, 16);
      v22.info.Soundlevel = SNDLVL_NORM;
      v22.info.nPitch = 100;
      v22.info.nSpeakerEntity = -1;
      v22.info.nChannel = 6;
      v22.info.nSoundNum = 0;
      v22.info.nFlags = 0;
      v22.info.nRandomSeed = 0;
      v22.info.bLooping = false;
      *(_WORD *)&v22.info.bIsSentence = 0;
      memset(&v22.info, 0, 40);
      if ( dist_mult == 0.0 )
        pVoidMema = 0.0;
      else
        pVoidMema = __FYL2X__(
                      snd_refdb_dist_mult / (snd_refdist.m_pParent->m_Value.m_fValue * dist_mult),
                      0.3010299956639811952)
                  * 20.0;
      if ( pChannel->sfx != nullptr )
        v12 = pChannel->sfx->getname(this: pChannel->sfx, a2: nameBuf, a3: 260u);
      else
        v12 = defaultValue;
      SoundInfo_t::Set(
        this: &v22.info,
        newEntity: pChannel->soundsource,
        newChannel: pChannel->entchannel,
        pszNewName: v12,
        newOrigin: &pChannel->origin,
        newDirection: &pChannel->direction,
        newVolume: (float)pChannel->master_vol,
        newSoundLevel: (soundlevel_t)pVoidMema,
        newLooping: v7->m_bIsLooping,
        newPitch: (int)pChannel->pitch,
        vecListenerOrigin: &v7->m_vBlendedListenerOrigin,
        speakerentity: pChannel->speakerentity,
        nSeed: 0);
      v22.pflRadius = (float *)&pScratchPad;
      v22.pOrigin = &vDebug;
      v22.m_pUtlVecMultiAngles = nullptr;
      memset(&utlVecMultiOrigins, 0, sizeof(utlVecMultiOrigins));
      memset(&utlVecMultiAngles, 0, sizeof(utlVecMultiAngles));
      v22.m_pUtlVecMultiOrigins = &v7->m_UtlVecMultiOrigins;
      v22.pAngles = &source_angles;
      soundsource = pChannel->soundsource;
      v22.type = SI_INSPATIALIZATION;
      if ( !g_pSoundServices->GetSoundSpatialization(this: g_pSoundServices, a2: soundsource, a3: &v22) || !bUseEntity_3 )
        v22.pOrigin = &v22.info.vOrigin;
      if ( *((_BYTE *)pVoidMem + 68) != 0 )
        g_ClientDLL->GetSoundSpatialization(this: g_ClientDLL, a2: &v22);
      v7->m_vEntityInfoAngle = source_angles;
      v7->m_vEntityInfoOrigin = vDebug;
      LODWORD(v7->m_flEntityInfoRadius) = pScratchPad;
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&utlVecMultiAngles);
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&utlVecMultiOrigins);
    }
    v14 = (int)*((float *)pVoidMem + 14);
    *((float *)pVoidMem + 13) = (float)v7->m_UtlVecMultiOrigins.m_Size;
    if ( v14 != 0 )
    {
      v16 = v14;
      *((float *)pVoidMem + 3) = v7->m_UtlVecMultiOrigins.m_Memory.m_pMemory[v16 - 1].x;
      *((float *)pVoidMem + 4) = v7->m_UtlVecMultiOrigins.m_Memory.m_pMemory[v16 - 1].y;
      *((float *)pVoidMem + 5) = v7->m_UtlVecMultiOrigins.m_Memory.m_pMemory[v16 - 1].z;
    }
    else
    {
      v15 = *((_DWORD *)pVoidMem + 16);
      if ( v15 == 2 )
      {
        *((float *)pVoidMem + 3) = v7->m_vEntityInfoOrigin.x;
        *((float *)pVoidMem + 4) = v7->m_vEntityInfoOrigin.y;
        *((float *)pVoidMem + 5) = v7->m_vEntityInfoOrigin.z;
        *((float *)pVoidMem + 6) = v7->m_vEntityInfoAngle.x;
        *((float *)pVoidMem + 7) = v7->m_vEntityInfoAngle.y;
        *((float *)pVoidMem + 8) = v7->m_vEntityInfoAngle.z;
        *((float *)pVoidMem + 9) = v7->m_flEntityInfoRadius;
      }
      else if ( v15 == 1 )
      {
        *((float *)pVoidMem + 3) = pChannel->origin.x;
        *((float *)pVoidMem + 4) = pChannel->origin.y;
        *((float *)pVoidMem + 5) = pChannel->origin.z;
        VectorAngles(forward: &pChannel->direction, angles: (QAngle *)&vDebug);
        *((Vector *)pVoidMem + 2) = vDebug;
        *((float *)pVoidMem + 9) = pChannel->radius;
      }
    }
    *((float *)pVoidMem + 10) = (double)pChannel->master_vol * 0.00392156862745098;
    *((float *)pVoidMem + 11) = pChannel->m_flSoundLevel;
    *((float *)pVoidMem + 12) = (double)pChannel->basePitch * 0.01;
    if ( snd_sos_show_source_info.m_pParent != nullptr && snd_sos_show_source_info.m_pParent->m_Value.m_nValue != 0 )
    {
      m_nSoundScriptHandle = pChannel->m_nSoundScriptHandle;
      vDebug = *(Vector *)((_BYTE *)pVoidMem + 1);
      v18 = g_pSoundEmitterSystem->GetSoundName(this: g_pSoundEmitterSystem, a2: m_nSoundScriptHandle);
      CDebugOverlay::AddTextOverlay(textPos: &vDebug, duration: 2.0, text: v18);
    }
    if ( snd_sos_show_operator_updates.m_pParent != nullptr
      && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
    {
      v23->Print(this: v23, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
    }
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
  {
    _LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: 1,
      a3: "Error: Sound operator %s requires valid channel pointer, being called without one\n",
      pStack->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[nOpIndex].m_Data.key);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004DAF0
// Name: public: CSosOperatorSourceInfo::CSosOperatorSourceInfo(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorSourceInfo *__thiscall CSosOperatorSourceInfo::CSosOperatorSourceInfo(CSosOperatorSourceInfo *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v8; // [esp-8h] [ebp-28h]
  int v9; // [esp-8h] [ebp-28h]
  int v10; // [esp-8h] [ebp-28h]
  int v11; // [esp-8h] [ebp-28h]
  CSosOperator::InputData_t src; // [esp+Ch] [ebp-14h] BYREF
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorSourceInfo_vtbl *)&CSosOperatorSourceInfo::`vftable';
  m_Size = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 12;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 3;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: m_Size,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_position", element: &nIndex);
  v2 = this->m_vOutputs.m_Size;
  src.m_nCount = 3;
  src.m_nOffsetOffset = 24;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v2,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_angles", element: &nIndex);
  v8 = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 36;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v8,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_radius", element: &nIndex);
  v9 = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 40;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v9,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_volume", element: &nIndex);
  v3 = this->m_vOutputs.m_Size;
  src.m_nCount = 1;
  src.m_nOffsetOffset = 44;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v3,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_level", element: &nIndex);
  v10 = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 48;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v10,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_pitch", element: &nIndex);
  v11 = this->m_vOutputs.m_Size;
  src.m_nOffsetOffset = 52;
  src.m_Type = SO_FLOAT;
  src.m_nCount = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v11,
             src: (const Vector *)&src.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_source_count", element: &nIndex);
  v4 = this->m_vInputs.m_Size;
  src.m_nCount = 1;
  src.m_nOffset = 56;
  src.m_nOffsetOffset = 60;
  src.m_Type = SO_FLOAT;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v4,
             &src);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_source_index", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "get_source_info",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004DD10
// Name: public: virtual unsigned int CSosOperatorSourceInfo::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorSourceInfo::GetSize(CSosOperatorSourceInfo *this)
{
  return 72;
}

} // namespace engine_xlsp
