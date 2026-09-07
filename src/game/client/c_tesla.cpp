// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_tesla.cpp
// Functions: 8
// ============================================================

#include "game\client\c_tesla.h"

//------------------------------------------------------------------------------
// Address: 0x10091F30
// Name: public: virtual class ClientClass __near * C_Tesla::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_Tesla::GetClientClass(C_Tesla *this)
{
  return &__g_C_TeslaClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x100922C0
// Name: public: C_Tesla::C_Tesla(void)
// Source: json
//------------------------------------------------------------------------------
C_Tesla *__thiscall C_Tesla::C_Tesla(C_Tesla *this)
{
  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_Tesla_vtbl *)&C_Tesla::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_Tesla::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_Tesla::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_Tesla::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_Tesla::`vftable';
  this->m_QueuedCommands.m_Memory.m_pMemory = nullptr;
  this->m_QueuedCommands.m_Memory.m_nAllocationCount = 0;
  this->m_QueuedCommands.m_Memory.m_nGrowSize = 0;
  this->m_QueuedCommands.m_LastAlloc.index = -1;
  this->m_QueuedCommands.m_ElementCount = 0;
  this->m_QueuedCommands.m_NumAlloced = 0;
  this->m_QueuedCommands.m_pElements = this->m_QueuedCommands.m_Memory.m_pMemory;
  this->m_QueuedCommands.m_Head = -1;
  this->m_QueuedCommands.m_Tail = -1;
  this->m_QueuedCommands.m_FirstFree = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10092340
// Name: public: virtual void C_Tesla::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_Tesla::ClientThink(C_Tesla *this@<ecx>, int a2@<ebp>)
{
  UtlLinkedListElem_t<CTeslaInfo,int> *m_pMemory; // eax
  int m_depth; // ecx
  int v5; // esi

  m_pMemory = this->m_QueuedCommands.m_Memory.m_pMemory;
  if ( m_pMemory != (UtlLinkedListElem_t<CTeslaInfo,int> *)-1 )
  {
    m_depth = this->m_CalcAbsoluteVelocityMutex.m_depth;
    do
    {
      v5 = 68 * (_DWORD)m_pMemory;
      FX_Tesla(a1: a2, teslaInfo: (const CTeslaInfo *)(68 * (_DWORD)m_pMemory + m_depth));
      m_depth = this->m_CalcAbsoluteVelocityMutex.m_depth;
      m_pMemory = *(UtlLinkedListElem_t<CTeslaInfo,int> **)(m_depth + v5 + 64);
    }
    while ( m_pMemory != (UtlLinkedListElem_t<CTeslaInfo,int> *)-1 );
  }
  CUtlLinkedList<CTeslaInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTeslaInfo,int>,int>>::RemoveAll(this: (CUtlLinkedList<CTeslaInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTeslaInfo,int>,int> > *)&this->m_CalcAbsoluteVelocityMutex.m_depth);
  if ( *((int *)&this->m_bIsBlurred + 1) >= 0 )
  {
    if ( this->m_CalcAbsoluteVelocityMutex.m_depth != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_CalcAbsoluteVelocityMutex.m_depth);
      this->m_CalcAbsoluteVelocityMutex.m_depth = 0;
    }
    *(_DWORD *)&this->m_bIsBlurred = 0;
  }
  this->m_QueuedCommands.m_ElementCount = this->m_CalcAbsoluteVelocityMutex.m_depth;
  this->m_QueuedCommands.m_Memory.m_nGrowSize = -1;
  this->m_QueuedCommands.m_FirstFree = -1;
  this->m_QueuedCommands.m_Tail = 0;
  (*(void (__stdcall **)(int))(*((_DWORD *)this - 3) + 456))(a1: -1082130432);
}

//------------------------------------------------------------------------------
// Address: 0x10092540
// Name: public: virtual void C_Tesla::ReceiveMessage(int,class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Tesla::ReceiveMessage(C_Tesla *this, int classID, bf_read *msg)
{
  int m_nBitsAvail; // ecx
  unsigned int v5; // edx
  __int16 v6; // di
  unsigned int v7; // edx
  const unsigned int *v8; // eax
  const unsigned int *v9; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // edi
  int v12; // eax
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // edx
  unsigned int v15; // ebx
  int v16; // ecx
  unsigned int v17; // eax
  int v18; // ecx
  const unsigned int *v19; // ecx
  const unsigned int *v20; // edx
  const unsigned int *v21; // edx
  unsigned int v22; // edi
  int v23; // eax
  const unsigned int *v24; // ecx
  unsigned int v25; // edx
  unsigned int v26; // ebx
  int v27; // ecx
  unsigned int v28; // eax
  char v29; // dl
  int v30; // ecx
  const unsigned int *v31; // ecx
  unsigned int v32; // ecx
  const unsigned int *v33; // edx
  unsigned int v34; // edi
  const unsigned int *v35; // ecx
  unsigned int v36; // edx
  unsigned int v37; // ebx
  unsigned int v38; // edx
  int v39; // ecx
  unsigned int v40; // eax
  char v41; // dl
  int v42; // ecx
  const unsigned int *v43; // ecx
  unsigned int v44; // ecx
  const unsigned int *v45; // edx
  unsigned int v46; // edi
  const unsigned int *v47; // ecx
  unsigned int v48; // edx
  unsigned int v49; // ebx
  unsigned int v50; // edx
  int v51; // ecx
  unsigned int v52; // eax
  char v53; // dl
  int v54; // ecx
  const unsigned int *v55; // ecx
  unsigned int v56; // ecx
  const unsigned int *v57; // edx
  unsigned int v58; // edi
  const unsigned int *v59; // ecx
  unsigned int v60; // edx
  unsigned int v61; // ebx
  unsigned int v62; // edx
  int v63; // edx
  int v64; // eax
  int v65; // eax
  const unsigned int *v66; // eax
  const unsigned int *v67; // ecx
  const unsigned int *v68; // edx
  int v69; // ecx
  const unsigned int *v70; // eax
  int v71; // ecx
  unsigned int v72; // eax
  char v73; // dl
  int v74; // ecx
  const unsigned int *v75; // ecx
  unsigned int v76; // ecx
  const unsigned int *v77; // edx
  unsigned int v78; // edi
  const unsigned int *v79; // ecx
  unsigned int v80; // edx
  unsigned int v81; // ebx
  unsigned int v82; // edx
  int v83; // ecx
  unsigned int v84; // eax
  int v85; // ecx
  const unsigned int *v86; // ecx
  const unsigned int *v87; // edx
  const unsigned int *v88; // edx
  unsigned int v89; // edi
  int v90; // eax
  const unsigned int *v91; // ecx
  unsigned int v92; // edx
  unsigned int v93; // ebx
  int v94; // ecx
  unsigned int v95; // eax
  int v96; // ecx
  const unsigned int *v97; // ecx
  const unsigned int *v98; // edx
  const unsigned int *v99; // edx
  unsigned int v100; // edi
  int v101; // eax
  const unsigned int *v102; // ecx
  unsigned int v103; // edx
  unsigned int v104; // ebx
  C_Tesla *v105; // edi
  CTeslaInfo teslaInfo; // [esp+14h] [ebp-40h] BYREF
  C_Tesla *v107; // [esp+50h] [ebp-4h]
  bf_read *msga; // [esp+60h] [ebp+Ch]
  bf_read *msgb; // [esp+60h] [ebp+Ch]
  bf_read *msgc; // [esp+60h] [ebp+Ch]

  v107 = this;
  CBitRead::ReadBitVec3Coord(this: msg, fa: &teslaInfo.m_vPos);
  m_nBitsAvail = msg->m_nBitsAvail;
  memset((void *)&teslaInfo.m_vAngles, 0, sizeof(teslaInfo.m_vAngles));
  if ( m_nBitsAvail < 16 )
  {
    m_pBufferEnd = msg->m_pBufferEnd;
    m_nInBufWord = msg->m_nInBufWord;
    v12 = 16 - m_nBitsAvail;
    m_pDataIn = msg->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
LABEL_15:
        if ( msg->m_bOverflow )
        {
          v6 = 0;
          goto LABEL_19;
        }
        v14 = msg->m_nInBufWord;
        v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << msg->m_nBitsAvail;
        msg->m_nBitsAvail = 32 - v12;
        v6 = v15 | m_nInBufWord;
        v7 = v14 >> v12;
        goto LABEL_18;
      }
      msg->m_nInBufWord = *m_pDataIn;
    }
    msg->m_pDataIn = m_pDataIn + 1;
    goto LABEL_15;
  }
  v5 = msg->m_nInBufWord;
  v6 = v5;
  msg->m_nBitsAvail = m_nBitsAvail - 16;
  if ( m_nBitsAvail != 16 )
  {
    v7 = HIWORD(v5);
LABEL_18:
    msg->m_nInBufWord = v7;
    goto LABEL_19;
  }
  v8 = msg->m_pDataIn;
  v9 = msg->m_pBufferEnd;
  msg->m_nBitsAvail = 32;
  if ( v8 == v9 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_nInBufWord = 0;
    msg->m_pDataIn = v8 + 1;
  }
  else if ( v8 <= v9 )
  {
    msg->m_nInBufWord = *v8;
    msg->m_pDataIn = v8 + 1;
  }
  else
  {
    msg->m_bOverflow = true;
    msg->m_nInBufWord = 0;
  }
LABEL_19:
  v16 = msg->m_nBitsAvail;
  teslaInfo.m_nEntIndex = v6;
  if ( v16 < 32 )
  {
    v21 = msg->m_pBufferEnd;
    v22 = msg->m_nInBufWord;
    v23 = 32 - v16;
    v24 = msg->m_pDataIn;
    if ( v24 == v21 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v24 > v21 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_34;
      }
      msg->m_nInBufWord = *v24;
    }
    msg->m_pDataIn = v24 + 1;
LABEL_34:
    if ( msg->m_bOverflow )
    {
      msga = nullptr;
    }
    else
    {
      v25 = msg->m_nInBufWord;
      v26 = (v25 & CBitBuffer::s_nMaskTable[v23]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v23;
      msga = (bf_read *)(v26 | v22);
      msg->m_nInBufWord = v25 >> v23;
    }
    goto LABEL_37;
  }
  v17 = msg->m_nInBufWord;
  v18 = v16 - 32;
  msg->m_nBitsAvail = v18;
  if ( v18 != 0 )
  {
    msg->m_nInBufWord = 0;
    msga = (bf_read *)v17;
  }
  else
  {
    v19 = msg->m_pDataIn;
    v20 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v19 == v20 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v19 + 1;
      msga = (bf_read *)v17;
    }
    else
    {
      if ( v19 <= v20 )
      {
        msg->m_nInBufWord = *v19;
        msg->m_pDataIn = v19 + 1;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      msga = (bf_read *)v17;
    }
  }
LABEL_37:
  v27 = msg->m_nBitsAvail;
  LODWORD(teslaInfo.m_flRadius) = msga;
  if ( v27 < 8 )
  {
    v33 = msg->m_pBufferEnd;
    v34 = msg->m_nInBufWord;
    v28 = 8 - v27;
    v35 = msg->m_pDataIn;
    if ( v35 == v33 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v35 > v33 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_52;
      }
      msg->m_nInBufWord = *v35;
    }
    msg->m_pDataIn = v35 + 1;
LABEL_52:
    if ( msg->m_bOverflow )
    {
      LOBYTE(v28) = 0;
    }
    else
    {
      v36 = msg->m_nInBufWord;
      v37 = (v36 & CBitBuffer::s_nMaskTable[v28]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v28;
      v38 = v36 >> v28;
      LOBYTE(v28) = v37 | v34;
      msg->m_nInBufWord = v38;
    }
    goto LABEL_55;
  }
  v28 = msg->m_nInBufWord;
  v29 = v28;
  v30 = v27 - 8;
  msg->m_nBitsAvail = v30;
  if ( v30 != 0 )
  {
    msg->m_nInBufWord = v28 >> 8;
  }
  else
  {
    v28 = (unsigned int)msg->m_pDataIn;
    v31 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( (const unsigned int *)v28 == v31 )
    {
      msg->m_pDataIn = (const unsigned int *)(v28 + 4);
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      LOBYTE(v28) = v29;
    }
    else
    {
      if ( v28 <= (unsigned int)v31 )
      {
        v32 = *(_DWORD *)v28;
        msg->m_pDataIn = (const unsigned int *)(v28 + 4);
        msg->m_nInBufWord = v32;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      LOBYTE(v28) = v29;
    }
  }
LABEL_55:
  v39 = msg->m_nBitsAvail;
  teslaInfo.m_vColor.x = (float)(unsigned __int8)v28 * 0.0039215689;
  if ( v39 < 8 )
  {
    v45 = msg->m_pBufferEnd;
    v46 = msg->m_nInBufWord;
    v40 = 8 - v39;
    v47 = msg->m_pDataIn;
    if ( v47 == v45 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v47 > v45 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_70;
      }
      msg->m_nInBufWord = *v47;
    }
    msg->m_pDataIn = v47 + 1;
LABEL_70:
    if ( msg->m_bOverflow )
    {
      LOBYTE(v40) = 0;
    }
    else
    {
      v48 = msg->m_nInBufWord;
      v49 = (v48 & CBitBuffer::s_nMaskTable[v40]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v40;
      v50 = v48 >> v40;
      LOBYTE(v40) = v49 | v46;
      msg->m_nInBufWord = v50;
    }
    goto LABEL_73;
  }
  v40 = msg->m_nInBufWord;
  v41 = v40;
  v42 = v39 - 8;
  msg->m_nBitsAvail = v42;
  if ( v42 != 0 )
  {
    msg->m_nInBufWord = v40 >> 8;
  }
  else
  {
    v40 = (unsigned int)msg->m_pDataIn;
    v43 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( (const unsigned int *)v40 == v43 )
    {
      msg->m_pDataIn = (const unsigned int *)(v40 + 4);
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      LOBYTE(v40) = v41;
    }
    else
    {
      if ( v40 <= (unsigned int)v43 )
      {
        v44 = *(_DWORD *)v40;
        msg->m_pDataIn = (const unsigned int *)(v40 + 4);
        msg->m_nInBufWord = v44;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      LOBYTE(v40) = v41;
    }
  }
LABEL_73:
  v51 = msg->m_nBitsAvail;
  teslaInfo.m_vColor.y = (float)(unsigned __int8)v40 * 0.0039215689;
  if ( v51 < 8 )
  {
    v57 = msg->m_pBufferEnd;
    v58 = msg->m_nInBufWord;
    v52 = 8 - v51;
    v59 = msg->m_pDataIn;
    if ( v59 == v57 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v59 > v57 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_88;
      }
      msg->m_nInBufWord = *v59;
    }
    msg->m_pDataIn = v59 + 1;
LABEL_88:
    if ( msg->m_bOverflow )
    {
      LOBYTE(v52) = 0;
    }
    else
    {
      v60 = msg->m_nInBufWord;
      v61 = (v60 & CBitBuffer::s_nMaskTable[v52]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v52;
      v62 = v60 >> v52;
      LOBYTE(v52) = v61 | v58;
      msg->m_nInBufWord = v62;
    }
    goto LABEL_91;
  }
  v52 = msg->m_nInBufWord;
  v53 = v52;
  v54 = v51 - 8;
  msg->m_nBitsAvail = v54;
  if ( v54 != 0 )
  {
    msg->m_nInBufWord = v52 >> 8;
  }
  else
  {
    v52 = (unsigned int)msg->m_pDataIn;
    v55 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( (const unsigned int *)v52 == v55 )
    {
      msg->m_pDataIn = (const unsigned int *)(v52 + 4);
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      LOBYTE(v52) = v53;
    }
    else
    {
      if ( v52 <= (unsigned int)v55 )
      {
        v56 = *(_DWORD *)v52;
        msg->m_pDataIn = (const unsigned int *)(v52 + 4);
        msg->m_nInBufWord = v56;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      LOBYTE(v52) = v53;
    }
  }
LABEL_91:
  v63 = (unsigned __int8)v52;
  v64 = msg->m_nBitsAvail;
  teslaInfo.m_vColor.z = (float)v63 * 0.0039215689;
  if ( v64 >= 8 )
  {
    v65 = v64 - 8;
    msg->m_nBitsAvail = v65;
    if ( v65 != 0 )
    {
      msg->m_nInBufWord >>= 8;
    }
    else
    {
      v66 = msg->m_pDataIn;
      v67 = msg->m_pBufferEnd;
      msg->m_nBitsAvail = 32;
      if ( v66 == v67 )
      {
        msg->m_nBitsAvail = 1;
        msg->m_nInBufWord = 0;
        msg->m_pDataIn = v66 + 1;
      }
      else if ( v66 <= v67 )
      {
        msg->m_nInBufWord = *v66;
        msg->m_pDataIn = v66 + 1;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
    }
    goto LABEL_107;
  }
  v68 = msg->m_pBufferEnd;
  v69 = 8 - v64;
  v70 = msg->m_pDataIn;
  if ( v70 == v68 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_nInBufWord = 0;
    msg->m_bOverflow = true;
  }
  else
  {
    if ( v70 > v68 )
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
      goto LABEL_105;
    }
    msg->m_nInBufWord = *v70;
  }
  msg->m_pDataIn = v70 + 1;
LABEL_105:
  if ( !msg->m_bOverflow )
  {
    msg->m_nInBufWord >>= v69;
    msg->m_nBitsAvail = 32 - v69;
  }
LABEL_107:
  v71 = msg->m_nBitsAvail;
  if ( v71 < 8 )
  {
    v77 = msg->m_pBufferEnd;
    v78 = msg->m_nInBufWord;
    v72 = 8 - v71;
    v79 = msg->m_pDataIn;
    if ( v79 == v77 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v79 > v77 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_122;
      }
      msg->m_nInBufWord = *v79;
    }
    msg->m_pDataIn = v79 + 1;
LABEL_122:
    if ( msg->m_bOverflow )
    {
      LOBYTE(v72) = 0;
    }
    else
    {
      v80 = msg->m_nInBufWord;
      v81 = (v80 & CBitBuffer::s_nMaskTable[v72]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v72;
      v82 = v80 >> v72;
      LOBYTE(v72) = v81 | v78;
      msg->m_nInBufWord = v82;
    }
    goto LABEL_125;
  }
  v72 = msg->m_nInBufWord;
  v73 = v72;
  v74 = v71 - 8;
  msg->m_nBitsAvail = v74;
  if ( v74 != 0 )
  {
    msg->m_nInBufWord = v72 >> 8;
  }
  else
  {
    v72 = (unsigned int)msg->m_pDataIn;
    v75 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( (const unsigned int *)v72 == v75 )
    {
      msg->m_pDataIn = (const unsigned int *)(v72 + 4);
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      LOBYTE(v72) = v73;
    }
    else
    {
      if ( v72 <= (unsigned int)v75 )
      {
        v76 = *(_DWORD *)v72;
        msg->m_pDataIn = (const unsigned int *)(v72 + 4);
        msg->m_nInBufWord = v76;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      LOBYTE(v72) = v73;
    }
  }
LABEL_125:
  v83 = msg->m_nBitsAvail;
  teslaInfo.m_nBeams = (char)v72;
  if ( v83 < 32 )
  {
    v88 = msg->m_pBufferEnd;
    v89 = msg->m_nInBufWord;
    v90 = 32 - v83;
    v91 = msg->m_pDataIn;
    if ( v91 == v88 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v91 > v88 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_140;
      }
      msg->m_nInBufWord = *v91;
    }
    msg->m_pDataIn = v91 + 1;
LABEL_140:
    if ( msg->m_bOverflow )
    {
      msgb = nullptr;
    }
    else
    {
      v92 = msg->m_nInBufWord;
      v93 = (v92 & CBitBuffer::s_nMaskTable[v90]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v90;
      msgb = (bf_read *)(v93 | v89);
      msg->m_nInBufWord = v92 >> v90;
    }
    goto LABEL_143;
  }
  v84 = msg->m_nInBufWord;
  v85 = v83 - 32;
  msg->m_nBitsAvail = v85;
  if ( v85 != 0 )
  {
    msg->m_nInBufWord = 0;
    msgb = (bf_read *)v84;
  }
  else
  {
    v86 = msg->m_pDataIn;
    v87 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v86 == v87 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v86 + 1;
      msgb = (bf_read *)v84;
    }
    else
    {
      if ( v86 <= v87 )
      {
        msg->m_nInBufWord = *v86;
        msg->m_pDataIn = v86 + 1;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      msgb = (bf_read *)v84;
    }
  }
LABEL_143:
  v94 = msg->m_nBitsAvail;
  LODWORD(teslaInfo.m_flBeamWidth) = msgb;
  if ( v94 >= 32 )
  {
    v95 = msg->m_nInBufWord;
    v96 = v94 - 32;
    msg->m_nBitsAvail = v96;
    if ( v96 == 0 )
    {
      v97 = msg->m_pDataIn;
      v98 = msg->m_pBufferEnd;
      msg->m_nBitsAvail = 32;
      if ( v97 == v98 )
      {
        msg->m_nBitsAvail = 1;
        msg->m_nInBufWord = 0;
        msg->m_pDataIn = v97 + 1;
        msgc = (bf_read *)v95;
        goto LABEL_160;
      }
      if ( v97 <= v98 )
      {
        msg->m_nInBufWord = *v97;
        msg->m_pDataIn = v97 + 1;
        msgc = (bf_read *)v95;
        goto LABEL_160;
      }
      msg->m_bOverflow = true;
    }
    msg->m_nInBufWord = 0;
    msgc = (bf_read *)v95;
    goto LABEL_160;
  }
  v99 = msg->m_pBufferEnd;
  v100 = msg->m_nInBufWord;
  v101 = 32 - v94;
  v102 = msg->m_pDataIn;
  if ( v102 == v99 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_nInBufWord = 0;
    msg->m_bOverflow = true;
  }
  else
  {
    if ( v102 > v99 )
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
      goto LABEL_157;
    }
    msg->m_nInBufWord = *v102;
  }
  msg->m_pDataIn = v102 + 1;
LABEL_157:
  if ( msg->m_bOverflow )
  {
    msgc = nullptr;
  }
  else
  {
    v103 = msg->m_nInBufWord;
    v104 = (v103 & CBitBuffer::s_nMaskTable[v101]) << msg->m_nBitsAvail;
    msg->m_nBitsAvail = 32 - v101;
    msgc = (bf_read *)(v104 | v100);
    msg->m_nInBufWord = v103 >> v101;
  }
LABEL_160:
  v105 = v107;
  LODWORD(teslaInfo.m_flTimeVisible) = msgc;
  teslaInfo.m_pszSpriteName = &v107->m_SoundName[56];
  C_BaseEntity::EmitSound(
    this: (C_Tesla *)((char *)v107 - 8),
    soundname: (const char *)&v107->m_QueuedCommands.m_LastAlloc,
    soundtime: 0,
    duration: nullptr);
  CUtlLinkedList<CTeslaInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTeslaInfo,int>,int>>::AddToTail(
    this: (CUtlLinkedList<CTeslaInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTeslaInfo,int>,int> > *)&v105->m_bIsBlurred,
    src: &teslaInfo);
  (*(void (__thiscall **)(char *, int))(*(_DWORD *)&v105[-1].m_iszSpriteName[248] + 456))(
    a1: &v105[-1].m_iszSpriteName[248],
    a2: -996040704);
}

//------------------------------------------------------------------------------
// Address: 0x10413CC0
// Name: DT_Tesla::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Tesla::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_Tesla::g_RecvTable);
  return atexit(func: DT_Tesla::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10413CE0
// Name: DT_Tesla::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Tesla::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_Tesla::ignored>();
  DT_Tesla::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430C70
// Name: DT_Tesla::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Tesla::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_Tesla::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10092400
// Name: _C_Tesla_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_Tesla_CreateObject(int entnum, int serialNum)
{
  C_Tesla *v2; // eax
  C_Tesla *v3; // eax
  C_Tesla *v4; // esi

  v2 = (C_Tesla *)C_BaseEntity::operator new(stAllocateBlock: 0xAE8u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_Tesla::C_Tesla(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}
