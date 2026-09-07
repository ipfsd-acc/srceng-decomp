// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/modelsoundscache.cpp
// Functions: 9
// ============================================================

#include "game\shared\modelsoundscache.h"

//------------------------------------------------------------------------------
// Address: 0x10173400
// Name: public: void CModelSoundsCache::PrecacheSoundList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelSoundsCache::PrecacheSoundList(CModelSoundsCache *this)
{
  int i; // esi
  const char *v3; // eax

  for ( i = 0; i < this->sounds.m_Size; ++i )
  {
    v3 = (const char *)((int (__stdcall *)(_DWORD))soundemitterbase->GetSoundName)(a1: this->sounds.m_Memory.m_pMemory[i]);
    ModelSoundsCache_PrecacheScriptSound(soundname: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10173440
// Name: public: CModelSoundsCache::CModelSoundsCache(void)
// Source: json
//------------------------------------------------------------------------------
CModelSoundsCache *__thiscall CModelSoundsCache::CModelSoundsCache(CModelSoundsCache *this)
{
  this->__vftable = (CModelSoundsCache_vtbl *)&CModelSoundsCache::`vftable';
  this->sounds.m_Memory.m_pMemory = nullptr;
  this->sounds.m_Memory.m_nAllocationCount = 0;
  this->sounds.m_Memory.m_nGrowSize = 0;
  this->sounds.m_Size = 0;
  this->sounds.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10173460
// Name: public: virtual void CModelSoundsCache::Save(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelSoundsCache::Save(CModelSoundsCache *this, CUtlBuffer *buf)
{
  int i; // esi
  const char *v4; // eax

  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%hd", (__int16)this->sounds.m_Size);
  else
    CUtlBuffer::PutTypeBin<short>(this: buf, src: this->sounds.m_Size);
  for ( i = 0; i < this->sounds.m_Size; ++i )
  {
    v4 = (const char *)((int (__stdcall *)(_DWORD))soundemitterbase->GetSoundName)(a1: this->sounds.m_Memory.m_pMemory[i]);
    CUtlBuffer::PutString(this: buf, pString: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101734D0
// Name: public: virtual void CModelSoundsCache::Restore(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelSoundsCache::Restore(CModelSoundsCache *this, CUtlBuffer *buf)
{
  unsigned __int16 Short; // ax
  int v3; // ebx
  _DWORD *v4; // esi
  int m_Size; // ecx
  int v6; // eax
  unsigned __int16 *m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v9; // edi
  int v10; // ecx
  int v11; // eax
  _WORD *v12; // eax
  char soundname[512]; // [esp+0h] [ebp-208h] BYREF
  CModelSoundsCache *v14; // [esp+200h] [ebp-8h]
  int i; // [esp+204h] [ebp-4h]

  v14 = this;
  Short = CUtlBuffer::GetShort(this: buf);
  if ( Short != 0 )
  {
    for ( i = Short; i != 0; --i )
    {
      CUtlBuffer::GetString(this: buf, pString: soundname, nMaxChars: 512);
      v3 = soundemitterbase->GetSoundIndex(this: soundemitterbase, a2: soundname);
      if ( v3 != -1 )
      {
        v4 = &v14->__vftable;
        m_Size = v14->sounds.m_Size;
        v6 = 0;
        if ( m_Size <= 0 )
          goto LABEL_10;
        m_pMemory = v14->sounds.m_Memory.m_pMemory;
        while ( *m_pMemory != (_WORD)v3 )
        {
          ++v6;
          ++m_pMemory;
          if ( v6 >= m_Size )
            goto LABEL_10;
        }
        if ( v6 == -1 )
        {
LABEL_10:
          m_nAllocationCount = v14->sounds.m_Memory.m_nAllocationCount;
          v9 = v14->sounds.m_Size;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<wchar_t,int>::Grow(
              this: (CUtlMemory<wchar_t,int> *)&v14->sounds,
              num: v9 - m_nAllocationCount + 1);
          ++v4[4];
          v10 = v4[1];
          v11 = v4[4] - v9 - 1;
          v4[5] = v10;
          if ( v11 > 0 )
            _V_memmove(dest: (void *)(v10 + 2 * v9 + 2), src: (const void *)(v10 + 2 * v9), count: 2 * v11);
          v12 = (_WORD *)(v4[1] + 2 * v9);
          if ( v12 != nullptr )
            *v12 = v3;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101735C0
// Name: public: static void CModelSoundsCache::FindOrAddScriptSound(class CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>> __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CModelSoundsCache::FindOrAddScriptSound(
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *sounds,
        const char *soundname)
{
  int v2; // eax
  unsigned __int16 v3; // bx
  int m_Size; // edi
  int v5; // eax
  unsigned __int16 *m_pMemory; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 *v8; // ecx
  int v9; // eax
  unsigned __int16 *v10; // eax

  v2 = soundemitterbase->GetSoundIndex(this: soundemitterbase, a2: soundname);
  v3 = v2;
  if ( v2 != -1 )
  {
    m_Size = sounds->m_Size;
    v5 = 0;
    if ( m_Size <= 0 )
      goto LABEL_8;
    m_pMemory = sounds->m_Memory.m_pMemory;
    while ( *m_pMemory != v3 )
    {
      ++v5;
      ++m_pMemory;
      if ( v5 >= m_Size )
        goto LABEL_8;
    }
    if ( v5 == -1 )
    {
LABEL_8:
      m_nAllocationCount = sounds->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<wchar_t,int>::Grow(this: (CUtlMemory<wchar_t,int> *)sounds, num: m_Size - m_nAllocationCount + 1);
      ++sounds->m_Size;
      v8 = sounds->m_Memory.m_pMemory;
      v9 = sounds->m_Size - m_Size - 1;
      sounds->m_pElements = sounds->m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &v8[m_Size + 1], src: &v8[m_Size], count: 2 * v9);
      v10 = &sounds->m_Memory.m_pMemory[m_Size];
      if ( v10 != nullptr )
        *v10 = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10173660
// Name: public: static void CModelSoundsCache::BuildAnimationEventSoundList(class CStudioHdr __near *,class CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CModelSoundsCache::BuildAnimationEventSoundList(
        CStudioHdr *hdr,
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *sounds)
{
  CStudioHdr *v2; // edi
  int i; // esi
  bool v4; // zf
  int v5; // eax
  const studiohdr_t *m_pStudioHdr; // ecx
  int v7; // eax
  mstudioseqdesc_t *v8; // edi
  int v9; // eax
  int v10; // edx
  char *v11; // eax
  int v12; // ecx
  const char *v13; // eax
  char *v14; // eax
  const char *v15; // esi
  const char *v16; // [esp-8h] [ebp-120h]
  int v17; // [esp-4h] [ebp-11Ch]
  char soundname[256]; // [esp+Ch] [ebp-10Ch] BYREF
  int iSeq; // [esp+10Ch] [ebp-Ch]
  int iEvent; // [esp+110h] [ebp-8h]
  int v21; // [esp+114h] [ebp-4h]

  v2 = hdr;
  VerifySequenceIndex(pstudiohdr: hdr);
  for ( i = 0; ; ++i )
  {
    v4 = v2->m_pVModel == nullptr;
    iSeq = i;
    v5 = v4 ? v2->m_pStudioHdr->numlocalseq : CStudioHdr::GetNumSeq_Internal(this: v2);
    if ( i >= v5 )
      break;
    if ( v2->m_pVModel != nullptr )
    {
      v8 = CStudioHdr::pSeqdesc_Internal(this: v2, i);
    }
    else
    {
      m_pStudioHdr = v2->m_pStudioHdr;
      v7 = i;
      if ( i < 0 || i >= m_pStudioHdr->numlocalseq )
        v7 = 0;
      v8 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v7 + m_pStudioHdr->localseqindex);
    }
    iEvent = 0;
    if ( v8->numevents > 0 )
    {
      v21 = 0;
      while ( 1 )
      {
        v9 = v21 + v8->eventindex;
        v10 = *(int *)((char *)&v8->szactivitynameindex + v9);
        v11 = (char *)v8 + v9;
        v12 = (v10 & 0x400) != 0 ? *((unsigned __int16 *)v11 + 3) : *((_DWORD *)v11 + 1);
        if ( v12 > 1008 )
          break;
        if ( v12 == 1008 )
          goto LABEL_23;
        if ( v12 != 15 )
        {
          if ( v12 != 1004 )
          {
LABEL_21:
            if ( (v10 & 0x400) == 0 || v12 != 16 )
              goto LABEL_25;
          }
          goto LABEL_23;
        }
        if ( (v10 & 0x10) != 0 )
        {
          v13 = v11 + 12;
          if ( *v13 == 0 )
          {
            v17 = iEvent + 1;
            v16 = (char *)v8 + v8->szlabelindex;
            v14 = CStudioHdr::name(this: hdr);
            _Warning(
              a1: "-- Error --:  empty soundname, .qc error on AE_CL_PLAYSOUND in model %s, sequence %s, animevent # %i\n",
              v14,
              v16,
              v17);
            goto LABEL_25;
          }
LABEL_24:
          CModelSoundsCache::FindOrAddScriptSound(sounds, soundname: v13);
        }
LABEL_25:
        v21 += 80;
        if ( ++iEvent >= v8->numevents )
        {
          i = iSeq;
          goto LABEL_27;
        }
      }
      if ( v12 != 5004 )
      {
        if ( (unsigned int)(v12 - 6004) <= 1 )
        {
          v15 = v11 + 12;
          if ( v11 == (char *)-12 || *v15 == 0 )
            v15 = "NPC_CombineS";
          V_snprintf(pDest: soundname, maxLen: 256, pFormat: "%s.RunFootstepLeft", v15);
          CModelSoundsCache::FindOrAddScriptSound(sounds, soundname);
          V_snprintf(pDest: soundname, maxLen: 256, pFormat: "%s.RunFootstepRight", v15);
          CModelSoundsCache::FindOrAddScriptSound(sounds, soundname);
          V_snprintf(pDest: soundname, maxLen: 256, pFormat: "%s.FootstepLeft", v15);
          CModelSoundsCache::FindOrAddScriptSound(sounds, soundname);
          V_snprintf(pDest: soundname, maxLen: 256, pFormat: "%s.FootstepRight", v15);
          CModelSoundsCache::FindOrAddScriptSound(sounds, soundname);
          goto LABEL_25;
        }
        goto LABEL_21;
      }
LABEL_23:
      v13 = v11 + 12;
      goto LABEL_24;
    }
LABEL_27:
    v2 = hdr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10173840
// Name: public: virtual void CModelSoundsCache::Rebuild(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelSoundsCache::Rebuild(CModelSoundsCache *this, const char *filename)
{
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *p_sounds; // edi
  CStudioHdr *Model; // eax
  CStudioHdr *v4; // esi

  p_sounds = &this->sounds;
  this->sounds.m_Size = 0;
  Model = ModelSoundsCache_LoadModel(filename);
  v4 = Model;
  if ( Model != nullptr )
  {
    CModelSoundsCache::BuildAnimationEventSoundList(hdr: Model, sounds: p_sounds);
    ModelSoundsCache_FinishModel(hdr: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10405190
// Name: _dynamic_initializer_for__model_studio__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__model_studio__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CGenericCycler> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &model_studio,
           a3: "model_studio");
}

//------------------------------------------------------------------------------
// Address: 0x104051B0
// Name: _dynamic_initializer_for__g_CWeaponCycler_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponCycler_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponCycler_ClassReg,
           pNetworkName: "CWeaponCycler",
           pTable: &DT_WeaponCycler::g_SendTable);
}
