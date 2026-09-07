// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/soundentry.cpp
// Functions: 20
// ============================================================

#include "utils\scenemanager\soundentry.h"

//------------------------------------------------------------------------------
// Address: 0x0040F430
// Name: public: class CVCDFile __near * CSoundEntry::GetOwnerVCDFile(void)
// Source: json
//------------------------------------------------------------------------------
CVCDFile *__thiscall CSoundEntry::GetOwnerVCDFile(CSoundEntry *this)
{
  return this->m_pOwner;
}

//------------------------------------------------------------------------------
// Address: 0x0040F440
// Name: public: void CSoundEntry::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEntry::SetName(CSoundEntry *this, const char *name)
{
  char *m_szName; // edi
  int v4; // esi
  const char *v5; // eax
  char filebase[64]; // [esp+Ch] [ebp-40h] BYREF

  m_szName = this->m_szName;
  if ( _V_stricmp(s1: this->m_szName, s2: name) != 0 )
  {
    V_strncpy(pDest: m_szName, pSrc: name, maxLen: 256);
    v4 = g_pSoundEmitterSystem->GetSoundIndex(this: g_pSoundEmitterSystem, a2: name);
    if ( g_pSoundEmitterSystem->IsValidIndex(this: g_pSoundEmitterSystem, a2: v4) )
    {
      v5 = g_pSoundEmitterSystem->GetSourceFileForSound(this: g_pSoundEmitterSystem, a2: v4);
      V_FileBase(in: v5, out: filebase, maxlen: 64);
      V_strncpy(pDest: this->m_szScriptFile, pSrc: filebase, maxLen: 64);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F4D0
// Name: public: virtual char const __near * CSoundEntry::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSoundEntry::GetName(CSoundEntry *this)
{
  return this->m_szName;
}

//------------------------------------------------------------------------------
// Address: 0x0040F4E0
// Name: public: char const __near * CSoundEntry::GetScriptFile(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSoundEntry::GetScriptFile(CSoundEntry *this)
{
  return this->m_szScriptFile;
}

//------------------------------------------------------------------------------
// Address: 0x0040F4F0
// Name: public: void CSoundEntry::SetScriptFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEntry::SetScriptFile(CSoundEntry *this, const char *scriptfile)
{
  ISoundEmitterSystemBase_vtbl *v3; // edi
  int v4; // eax
  const char *v5; // eax
  char *m_szScriptFile; // esi
  char *v7; // [esp-8h] [ebp-50h]
  char filebase[64]; // [esp+8h] [ebp-40h] BYREF

  v3 = g_pSoundEmitterSystem->__vftable;
  v4 = this->GetName(this);
  v7 = (char *)v3->GetSoundIndex(this: g_pSoundEmitterSystem, a2: (const char *)v4);
  v5 = (const char *)((int (__thiscall *)(ISoundEmitterSystemBase *))g_pSoundEmitterSystem->GetSourceFileForSound)(a1: g_pSoundEmitterSystem);
  V_FileBase(in: v5, out: v7, maxlen: (int)filebase);
  m_szScriptFile = this->m_szScriptFile;
  if ( _V_stricmp(s1: m_szScriptFile, s2: filebase) != 0 )
    V_strncpy(pDest: m_szScriptFile, pSrc: filebase, maxLen: 64);
}

//------------------------------------------------------------------------------
// Address: 0x0040F560
// Name: public: struct CSoundParametersInternal __near * CSoundEntry::GetSoundParameters(void)
// Source: json
//------------------------------------------------------------------------------
CSoundParametersInternal *__thiscall CSoundEntry::GetSoundParameters(CSoundEntry *this)
{
  ISoundEmitterSystemBase_vtbl *v1; // esi
  int v2; // eax
  int v3; // esi

  v1 = g_pSoundEmitterSystem->__vftable;
  v2 = this->GetName(this);
  v3 = v1->GetSoundIndex(this: g_pSoundEmitterSystem, a2: (const char *)v2);
  if ( g_pSoundEmitterSystem->IsValidIndex(this: g_pSoundEmitterSystem, a2: v3) )
    return g_pSoundEmitterSystem->InternalGetParametersForSound(this: g_pSoundEmitterSystem, a2: v3);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0040F5B0
// Name: public: virtual int CSoundEntry::GetIconIndex(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundEntry::GetIconIndex(CSoundEntry *this)
{
  return 9;
}

//------------------------------------------------------------------------------
// Address: 0x0040F5C0
// Name: public: virtual void CSoundEntry::SetDirty(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEntry::SetDirty(CSoundEntry *this, BOOL dirty)
{
  CVCDFile *m_pOwner; // ecx

  m_pOwner = this->m_pOwner;
  if ( m_pOwner != nullptr )
    m_pOwner->SetDirty(this: m_pOwner, a2: dirty);
}

//------------------------------------------------------------------------------
// Address: 0x0040F5E0
// Name: public: void CSoundEntry::GetCCText(wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEntry::GetCCText(CSoundEntry *this, wchar_t *out, unsigned int maxchars)
{
  vgui::ILocalize_vtbl *v3; // esi
  int v4; // eax
  const wchar_t *v5; // eax

  *out = 0;
  if ( g_pVGuiLocalize != nullptr )
  {
    v3 = g_pVGuiLocalize->__vftable;
    v4 = this->GetName(this);
    v5 = v3->Find(this: g_pVGuiLocalize, a2: (const char *)v4);
    if ( v5 != nullptr )
      wcsncpy(dest: out, source: v5, count: maxchars);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F630
// Name: public: int CSoundEntry::GetWaveCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundEntry::GetWaveCount(CSoundEntry *this)
{
  return this->m_Waves.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0040F640
// Name: public: class CWaveFile __near * CSoundEntry::GetWave(int)
// Source: json
//------------------------------------------------------------------------------
CWaveFile *__thiscall CSoundEntry::GetWave(CSoundEntry *this, int index)
{
  if ( index < 0 || index >= this->m_Waves.m_Size )
    return nullptr;
  else
    return this->m_Waves.m_Memory.m_pMemory[index];
}

//------------------------------------------------------------------------------
// Address: 0x0040F670
// Name: public: void CSoundEntry::Play(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEntry::Play(CSoundEntry *this)
{
  int m_Size; // esi
  int v2; // edx
  CWaveFile *v3; // ecx

  m_Size = this->m_Waves.m_Size;
  if ( m_Size != 0 )
  {
    v2 = (this->m_nLastPlay + 1) % m_Size;
    this->m_nLastPlay = v2;
    if ( v2 >= 0 && v2 < m_Size )
    {
      v3 = this->m_Waves.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
        CWaveFile::Play(this: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F6B0
// Name: public: char const __near * CSoundEntry::GetSentenceText(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSoundEntry::GetSentenceText(CSoundEntry *this, int wavindex)
{
  int m_Size; // edx
  CWaveFile *v4; // esi

  m_Size = this->m_Waves.m_Size;
  if ( m_Size == 0 )
    return &WindowName;
  if ( wavindex < 0 || wavindex >= m_Size )
    v4 = nullptr;
  else
    v4 = this->m_Waves.m_Memory.m_pMemory[wavindex];
  if ( CWaveFile::HasLoadedSentenceInfo(this: v4) )
    return CWaveFile::GetSentenceText(this: v4);
  else
    return "(loading...)";
}

//------------------------------------------------------------------------------
// Address: 0x0040F700
// Name: public: int CSoundEntry::FindWave(class CWaveFile __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundEntry::FindWave(CSoundEntry *this, CWaveFile *wave)
{
  int m_Size; // edx
  int result; // eax
  CWaveFile **i; // ecx

  m_Size = this->m_Waves.m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Waves.m_Memory.m_pMemory; *i != wave; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  if ( result == -1 )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040F750
// Name: public: CSoundEntry::~CSoundEntry(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEntry::~CSoundEntry(CSoundEntry *this)
{
  CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *p_m_Waves; // ecx

  this->__vftable = (ITreeItem_vtbl *)&CSoundEntry::`vftable';
  p_m_Waves = (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Waves;
  p_m_Waves->m_Size = 0;
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: p_m_Waves);
}

//------------------------------------------------------------------------------
// Address: 0x0040F770
// Name: public: void CSoundEntry::RemoveWave(class CWaveFile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEntry::RemoveWave(CSoundEntry *this, CWaveFile *wave)
{
  CUtlVector<CVCDFile *,CUtlMemory<CVCDFile *,int>>::FindAndRemove(
    this: (CUtlVector<CScene *,CUtlMemory<CScene *,int> > *)&this->m_Waves,
    src: (CScene **)&wave);
}

//------------------------------------------------------------------------------
// Address: 0x0040F790
// Name: public: void CSoundEntry::AddWave(class CWaveFile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEntry::AddWave(CSoundEntry *this, CWaveFile *wave)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Waves; // esi
  int m_Size; // ecx
  int v4; // eax
  CWaveFile **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax

  p_m_Waves = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Waves;
  m_Size = this->m_Waves.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (CWaveFile **)p_m_Waves->m_pMemory;
  while ( *m_pMemory != wave )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_Waves->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Waves, num: m_Size - m_nAllocationCount + 1);
    ++p_m_Waves[1].m_pMemory;
    v8 = p_m_Waves->m_pMemory;
    v9 = (int)p_m_Waves[1].m_pMemory - v7 - 1;
    p_m_Waves[1].m_nAllocationCount = (int)p_m_Waves->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_Waves->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (CUtlSymbolTable::StringPool_t *)wave;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F820
// Name: public: void CSoundEntry::ValidateTree(class mxTreeView __near *,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEntry::ValidateTree(CSoundEntry *this, mxTreeView *tree, void **parent)
{
  int m_Size; // edx
  void ***NextChild; // ebx
  int v5; // eax
  CWaveFile *v6; // esi
  const char *SentenceText; // eax
  void **Item; // edi
  int v9; // ebx
  int v10; // eax
  void ***m_pMemory; // ecx
  int v12; // eax
  void ***v13; // ebx
  int v14; // eax
  void **FirstChild; // esi
  int v16; // eax
  int v17; // [esp-8h] [ebp-134h]
  int v18; // [esp-4h] [ebp-130h]
  char sz[256]; // [esp+Ch] [ebp-120h] BYREF
  CSoundEntry *v20; // [esp+10Ch] [ebp-20h]
  int c; // [esp+110h] [ebp-1Ch]
  CUtlVector<void * *,CUtlMemory<void * *,int> > m_KnownItems; // [esp+114h] [ebp-18h] BYREF
  int i; // [esp+128h] [ebp-4h]

  m_Size = this->m_Waves.m_Size;
  NextChild = nullptr;
  v5 = 0;
  v20 = this;
  memset(&m_KnownItems, 0, sizeof(m_KnownItems));
  c = m_Size;
  i = 0;
  if ( m_Size > 0 )
  {
    do
    {
      if ( v5 >= 0 && v5 < this->m_Waves.m_Size )
      {
        v6 = this->m_Waves.m_Memory.m_pMemory[v5];
        if ( v6 != nullptr )
        {
          if ( CWaveFile::HasLoadedSentenceInfo(this: this->m_Waves.m_Memory.m_pMemory[v5]) )
          {
            SentenceText = CWaveFile::GetSentenceText(this: v6);
            v17 = ((int (__thiscall *)(CWaveFile *, const char *))v6->GetName)(a1: v6, a2: SentenceText);
          }
          else
          {
            v17 = ((int (__thiscall *)(CWaveFile *, const char *))v6->GetName)(a1: v6, a2: "(loading...)");
          }
          V_snprintf(pDest: sz, maxLen: 256, pFormat: "\"%s\" : '%s'", v17);
          Item = ITreeItem::FindItem(this: v6, tree, parent, recurse: false);
          if ( Item == nullptr )
            Item = mxTreeView::add(this: tree, parent, item: sz);
          v9 = m_KnownItems.m_Size;
          v10 = m_KnownItems.m_Size;
          if ( m_KnownItems.m_Size + 1 > m_KnownItems.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CChoreoActor *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&m_KnownItems,
              num: m_KnownItems.m_Size - m_KnownItems.m_Memory.m_nAllocationCount + 1);
            v10 = m_KnownItems.m_Size;
          }
          m_pMemory = m_KnownItems.m_Memory.m_pMemory;
          m_KnownItems.m_Size = v10 + 1;
          v12 = v10 - v9;
          m_KnownItems.m_pElements = m_KnownItems.m_Memory.m_pMemory;
          if ( v12 > 0 )
          {
            _V_memmove(
              dest: &m_KnownItems.m_Memory.m_pMemory[v9 + 1],
              src: &m_KnownItems.m_Memory.m_pMemory[v9],
              count: 4 * v12);
            m_pMemory = m_KnownItems.m_Memory.m_pMemory;
          }
          v13 = &m_pMemory[v9];
          if ( v13 != nullptr )
            *v13 = Item;
          v6->m_nOrdinal = i;
          mxTreeView::setLabel(this: tree, item: Item, label: sz);
          v18 = v6->GetIconIndex(this: v6);
          v14 = v6->GetIconIndex(this: v6);
          mxTreeView::setImages(this: tree, item: Item, imagenormal: v14, imageselected: v18);
          mxTreeView::setUserData(this: tree, item: Item, userData: v6);
          CSoundFilterTab::ShowRightClickMenu(this: (CSoundFilterTab *)v6, mx: (int)tree, my: (int)Item);
          this = v20;
          m_Size = c;
          v5 = i;
          NextChild = nullptr;
        }
      }
      i = ++v5;
    }
    while ( v5 < m_Size );
  }
  FirstChild = mxTreeView::getFirstChild(this: tree, item: parent);
  if ( FirstChild != nullptr )
  {
    do
    {
      NextChild = (void ***)mxTreeView::getNextChild(this: tree, item: FirstChild);
      v16 = 0;
      if ( m_KnownItems.m_Size <= 0 )
        goto LABEL_24;
      while ( m_KnownItems.m_Memory.m_pMemory[v16] != FirstChild )
      {
        if ( ++v16 >= m_KnownItems.m_Size )
          goto LABEL_24;
      }
      if ( v16 == -1 )
LABEL_24:
        mxTreeView::remove(this: tree, item: FirstChild);
      FirstChild = (void **)NextChild;
    }
    while ( NextChild != nullptr );
  }
  mxTreeView::sortTree(
    this: tree,
    parent,
    recurse: true,
    func: CWorkspaceBrowser::CompareFunc,
    parameter: (int)NextChild);
  if ( m_KnownItems.m_Memory.m_nGrowSize >= (int)NextChild && m_KnownItems.m_Memory.m_pMemory != NextChild )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_KnownItems.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0040FA30
// Name: public: CSoundEntry::CSoundEntry(class CVCDFile __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
CSoundEntry *__userpurge CSoundEntry::CSoundEntry@<eax>(
        CSoundEntry *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CVCDFile *vcd,
        CSoundParametersInternal *name)
{
  int v7; // edi
  const char *(__thiscall *GetSourceFileForSound)(ISoundEmitterSystemBase *, int); // eax
  const char *v9; // eax
  CSoundParametersInternal *v10; // edi
  CWorkspaceManager *WorkspaceManager; // eax
  SoundFile *SoundNames; // eax
  int v13; // edi
  char *v14; // eax
  CWaveFile *Entry; // eax
  char filebase[64]; // [esp+0h] [ebp-4Ch] BYREF
  int waveCount; // [esp+40h] [ebp-Ch]
  CWaveBrowser *wb; // [esp+44h] [ebp-8h]
  ISoundEmitterSystemBase_vtbl *v21; // [esp+48h] [ebp-4h]
  int wave; // [esp+54h] [ebp+8h]
  CSoundParametersInternal *p; // [esp+58h] [ebp+Ch]

  this->m_bExpanded = false;
  this->__vftable = (ITreeItem_vtbl *)&CSoundEntry::`vftable';
  this->m_nOrdinal = -1;
  this->m_Params.m_nRandomSeed = -1;
  this->m_Params.pitch = 100;
  this->m_Params.pitchlow = 100;
  this->m_Params.pitchhigh = 100;
  this->m_Params.channel = 0;
  this->m_Params.volume = 1.0;
  this->m_Params.soundlevel = SNDLVL_NORM;
  this->m_Params.soundname[0] = 0;
  this->m_Params.play_to_owner_only = false;
  this->m_Params.count = 0;
  this->m_Params.delay_msec = 0;
  this->m_Params.m_nSoundEntryVersion = 1;
  this->m_Params.m_pOperatorsKV = nullptr;
  this->m_Params.m_hSoundScriptHandle = -1;
  this->m_pOwner = vcd;
  this->m_Waves.m_Memory.m_pMemory = nullptr;
  this->m_Waves.m_Memory.m_nAllocationCount = 0;
  this->m_Waves.m_Memory.m_nGrowSize = 0;
  this->m_Waves.m_Size = 0;
  this->m_Waves.m_pElements = nullptr;
  _V_memset(dest: &this->m_Params, fill: 0, count: 180);
  this->m_szScriptFile[0] = 0;
  V_strncpy(pDest: this->m_szName, pSrc: (const char *)name, maxLen: 256);
  v7 = ((int (__thiscall *)(ISoundEmitterSystemBase *, CSoundParametersInternal *, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pSoundEmitterSystem->GetSoundIndex)(
         a1: g_pSoundEmitterSystem,
         a2: name,
         a3,
         a4,
         a5: a2,
         a6: *(_DWORD *)filebase,
         a7: *(_DWORD *)&filebase[4],
         a8: *(_DWORD *)&filebase[8],
         a9: *(_DWORD *)&filebase[12],
         a10: *(_DWORD *)&filebase[16],
         a11: *(_DWORD *)&filebase[20],
         a12: *(_DWORD *)&filebase[24],
         a13: *(_DWORD *)&filebase[28],
         a14: *(_DWORD *)&filebase[32],
         a15: *(_DWORD *)&filebase[36],
         a16: *(_DWORD *)&filebase[40],
         a17: *(_DWORD *)&filebase[44],
         a18: *(_DWORD *)&filebase[48],
         a19: *(_DWORD *)&filebase[52],
         a20: *(_DWORD *)&filebase[56],
         a21: *(_DWORD *)&filebase[60]);
  if ( g_pSoundEmitterSystem->IsValidIndex(this: g_pSoundEmitterSystem, a2: v7) )
  {
    *(_DWORD *)&filebase[60] = 64;
    *(_DWORD *)&filebase[56] = filebase;
    GetSourceFileForSound = g_pSoundEmitterSystem->GetSourceFileForSound;
    *(_DWORD *)&filebase[52] = v7;
    v9 = (const char *)((int (__thiscall *)(ISoundEmitterSystemBase *))GetSourceFileForSound)(a1: g_pSoundEmitterSystem);
    V_FileBase(in: v9, out: *(char **)&filebase[52], maxlen: *(int *)&filebase[56]);
    V_strncpy(pDest: this->m_szScriptFile, pSrc: filebase, maxLen: 64);
    v10 = (CSoundParametersInternal *)((int (__thiscall *)(ISoundEmitterSystemBase *, int, _DWORD))g_pSoundEmitterSystem->InternalGetParametersForSound)(
                                        a1: g_pSoundEmitterSystem,
                                        a2: v7,
                                        a3: *(_DWORD *)&filebase[60]);
    p = v10;
    if ( v10 != nullptr )
    {
      WorkspaceManager = GetWorkspaceManager();
      wb = CWorkspaceManager::GetWaveBrowser(this: WorkspaceManager);
      waveCount = v10->m_nSoundNames;
      wave = 0;
      if ( waveCount > 0 )
      {
        while ( 1 )
        {
          v21 = g_pSoundEmitterSystem->__vftable;
          SoundNames = CSoundParametersInternal::GetSoundNames(this: v10);
          v13 = wave;
          v14 = (char *)v21->GetWaveName(this: g_pSoundEmitterSystem, a2: (CUtlSymbol *)&SoundNames[wave]);
          if ( v14 != nullptr )
          {
            Entry = CWaveBrowser::FindEntry(this: wb, wavname: v14, jump: false);
            if ( Entry != nullptr )
              CSoundEntry::AddWave(this, wave: Entry);
          }
          ++wave;
          if ( v13 + 1 >= waveCount )
            break;
          v10 = p;
        }
      }
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00418F10
// Name: public: virtual void CSoundEntry::MoveChildDown(class ITreeItem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundEntry::MoveChildDown(CEmptyConVar *this, int nValue)
{
  ;
}
