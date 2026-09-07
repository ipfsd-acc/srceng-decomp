// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cl_demoactionmanager.cpp
// Functions: 15
// ============================================================

#include "engine\cl_demoactionmanager.h"

//------------------------------------------------------------------------------
// Address: 0x1007A870
// Name: public: virtual void CDemoActionManager::StartPlaying(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionManager::StartPlaying(CDemoActionManager *this, const char *demfilename)
{
  int v4; // eax
  char metafile[512]; // [esp+Ch] [ebp-200h] BYREF
  bool changedfile_3; // [esp+217h] [ebp+Bh]

  this->StopPlaying(this);
  changedfile_3 = V_strcasecmp(s1: demfilename, s2: this->m_szCurrentFile) != 0;
  V_strncpy(pDest: this->m_szCurrentFile, pSrc: demfilename, maxLen: 260);
  V_StripExtension(in: demfilename, out: metafile, outSize: 512);
  V_DefaultExtension(path: metafile, extension: ".vdm", pathStringLength: 512);
  v4 = g_pFileSystem->GetFileTime(this: &g_pFileSystem->IBaseFileSystem, a2: metafile, a3: nullptr);
  if ( changedfile_3 || this->m_lFileTime != v4 )
  {
    if ( this->m_bDirty )
      this->SaveToFile(this);
    this->ReloadFromDisk(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007A920
// Name: public: virtual char const __near * CDemoActionManager::GetCurrentDemoFile(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CDemoActionManager::GetCurrentDemoFile(CDemoActionManager *this)
{
  return this->m_szCurrentFile;
}

//------------------------------------------------------------------------------
// Address: 0x1007A940
// Name: public: virtual void CDemoActionManager::SetDirty(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionManager::SetDirty(CDemoActionManager *this, bool dirty)
{
  this->m_bDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x1007A950
// Name: public: virtual void CDemoActionManager::Update(bool,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionManager::Update(CDemoActionManager *this, bool newframe, int demotick, float demotime)
{
  int m_Size; // ebx
  int m_nPrevTick; // eax
  int v7; // esi
  CBaseDemoAction *v8; // ecx
  DemoActionTimingContext ctx; // [esp+8h] [ebp-10h] BYREF

  m_Size = this->m_ActionStack.m_Size;
  if ( m_Size > 0 )
  {
    m_nPrevTick = this->m_nPrevTick;
    ctx.prevtime = this->m_flPrevTime;
    v7 = 0;
    ctx.prevtick = m_nPrevTick;
    ctx.curtick = demotick;
    ctx.curtime = demotime;
    do
    {
      v8 = this->m_ActionStack.m_Memory.m_pMemory[v7];
      if ( v8 != nullptr )
        v8->Update(this: v8, a2: &ctx);
      ++v7;
    }
    while ( v7 < m_Size );
    this->m_nPrevTick = demotick;
    this->m_flPrevTime = demotime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007A9C0
// Name: public: virtual void CDemoActionManager::SaveToBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionManager::SaveToBuffer(CDemoActionManager *this, CUtlBuffer *buf)
{
  int m_Size; // eax
  int v5; // esi
  CBaseDemoAction *v6; // ecx
  int count; // [esp+14h] [ebp+8h]

  CUtlBuffer::Printf(this: buf, pFmt: "demoactions\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  m_Size = this->m_ActionStack.m_Size;
  v5 = 0;
  for ( count = m_Size; v5 < m_Size; ++v5 )
  {
    v6 = this->m_ActionStack.m_Memory.m_pMemory[v5];
    if ( v6 != nullptr )
    {
      CBaseDemoAction::SaveToBuffer(this: v6, depth: 1, index: v5 + 1, buf);
      m_Size = count;
    }
  }
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
}

//------------------------------------------------------------------------------
// Address: 0x1007AA30
// Name: private: void CDemoActionManager::ClearAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionManager::ClearAll(CDemoActionManager *this)
{
  CBaseDemoAction *v2; // ecx

  for ( this->m_PendingFireActionStack.m_Size = 0; this->m_ActionStack.m_Size > 0; --this->m_ActionStack.m_Size )
  {
    v2 = *this->m_ActionStack.m_Memory.m_pMemory;
    if ( v2 != nullptr )
      ((void (__thiscall *)(CBaseDemoAction *, int))v2->dtr_CBaseDemoAction)(a1: v2, a2: 1);
    if ( this->m_ActionStack.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_ActionStack.m_Memory.m_pMemory,
        src: this->m_ActionStack.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_ActionStack.m_Size - 1));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007AA80
// Name: public: virtual void CDemoActionManager::StopPlaying(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionManager::StopPlaying(CDemoActionManager *this)
{
  int m_Size; // ebx
  int i; // esi
  CBaseDemoAction *v4; // ecx

  m_Size = this->m_ActionStack.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v4 = this->m_ActionStack.m_Memory.m_pMemory[i];
    v4->Reset(this: v4);
  }
  this->m_nPrevTick = 0;
  this->m_flPrevTime = 0.0;
  this->m_PendingFireActionStack.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1007AAC0
// Name: public: virtual void CDemoActionManager::RemoveAction(class CBaseDemoAction __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionManager::RemoveAction(CDemoActionManager *this, CBaseDemoAction *action)
{
  this->m_bDirty = true;
  CUtlVector<CNetChan *,CUtlMemory<CNetChan *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_ActionStack,
    src: (vgui::TreeNode *const *)&action);
  if ( action != nullptr )
    ((void (__thiscall *)(CBaseDemoAction *, int))action->dtr_CBaseDemoAction)(a1: action, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1007AAF0
// Name: public: virtual void CDemoActionManager::DispatchEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionManager::DispatchEvents(CDemoActionManager *this)
{
  int v2; // edi
  CBaseDemoAction *v3; // esi
  int c; // [esp+8h] [ebp-4h]

  v2 = 0;
  c = this->m_PendingFireActionStack.m_Size;
  if ( c <= 0 )
  {
    this->m_PendingFireActionStack.m_Size = 0;
  }
  else
  {
    do
    {
      v3 = this->m_PendingFireActionStack.m_Memory.m_pMemory[v2];
      v3->FireAction(this: v3);
      CBaseDemoAction::SetActionFired(this: v3, fired: true);
      ++v2;
    }
    while ( v2 < c );
    this->m_PendingFireActionStack.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007AB40
// Name: public: virtual void CDemoActionManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionManager::Shutdown(CDemoActionManager *this)
{
  CBaseDemoAction **m_pMemory; // ecx

  this->StopPlaying(this);
  CDemoActionManager::ClearAll(this);
  this->m_ActionStack.m_Size = 0;
  if ( this->m_ActionStack.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ActionStack.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ActionStack.m_Memory.m_pMemory);
      this->m_ActionStack.m_Memory.m_pMemory = nullptr;
    }
    this->m_ActionStack.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ActionStack.m_pElements = this->m_ActionStack.m_Memory.m_pMemory;
  this->m_PendingFireActionStack.m_Size = 0;
  if ( this->m_PendingFireActionStack.m_Memory.m_nGrowSize < 0 )
  {
    this->m_PendingFireActionStack.m_pElements = this->m_PendingFireActionStack.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_PendingFireActionStack.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_PendingFireActionStack.m_Memory.m_pMemory);
      this->m_PendingFireActionStack.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_PendingFireActionStack.m_Memory.m_pMemory;
    this->m_PendingFireActionStack.m_Memory.m_nAllocationCount = 0;
    this->m_PendingFireActionStack.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007ABC0
// Name: public: virtual void CDemoActionManager::SaveToFile(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDemoActionManager::SaveToFile(CDemoActionManager *this@<ecx>, int a2@<edi>)
{
  void *v3; // eax
  void *v4; // edi
  int v5; // eax
  bool v6; // sf
  char metafile[512]; // [esp+4h] [ebp-230h] BYREF
  CUtlBuffer buf; // [esp+204h] [ebp-30h] BYREF

  if ( this->m_szCurrentFile[0] != 0 && this->m_bDirty )
  {
    V_StripExtension(in: this->m_szCurrentFile, out: metafile, outSize: 512);
    V_DefaultExtension(path: metafile, extension: ".vdm", pathStringLength: 512);
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
    ((void (__thiscall *)(CDemoActionManager *, CUtlBuffer *, int))this->SaveToBuffer)(a1: this, a2: &buf, a3: a2);
    v3 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: metafile, a3: "w", a4: 0);
    v4 = v3;
    if ( v3 != nullptr )
    {
      g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: buf.m_Memory.m_pMemory, a3: buf.m_Put, a4: v3);
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v4);
    }
    this->m_bDirty = false;
    v5 = ((int (__thiscall *)(IBaseFileSystem *, char *))g_pFileSystem->GetFileTime)(
           a1: &g_pFileSystem->IBaseFileSystem,
           a2: metafile);
    v6 = buf.m_Memory.m_nGrowSize < 0;
    this->m_lFileTime = v5;
    if ( !v6 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007ACD0
// Name: public: virtual void CDemoActionManager::ReloadFromDisk(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionManager::ReloadFromDisk(CDemoActionManager *this)
{
  CDemoActionManager *v1; // edi
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IBaseFileSystem *v4; // eax
  KeyValues *FirstSubKey; // esi
  const char *Name; // eax
  const char *String; // eax
  DEMOACTION v8; // eax
  CBaseDemoAction *DemoAction; // eax
  CBaseDemoAction *v10; // ebx
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_ActionStack; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v15; // eax
  S3RGBA *v16; // ecx
  CBaseDemoAction **v17; // eax
  char factorytouse[512]; // [esp+4h] [ebp-408h] BYREF
  char metafile[512]; // [esp+204h] [ebp-208h] BYREF
  CDemoActionManager *v20; // [esp+404h] [ebp-8h]
  KeyValues *pIter; // [esp+408h] [ebp-4h]

  v1 = this;
  v20 = this;
  V_StripExtension(in: this->m_szCurrentFile, out: metafile, outSize: 512);
  V_DefaultExtension(path: metafile, extension: ".vdm", pathStringLength: 512);
  CDemoActionManager::ClearAll(this: v1);
  v1->m_lFileTime = g_pFileSystem->GetFileTime(this: &g_pFileSystem->IBaseFileSystem, a2: metafile, a3: nullptr);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: metafile);
    if ( v3 != nullptr )
    {
      if ( g_pFullFileSystem != nullptr )
        v4 = &g_pFullFileSystem->IBaseFileSystem;
      else
        v4 = nullptr;
      if ( KeyValues::LoadFromFile(
             this: v3,
             filesystem: v4,
             resourceName: metafile,
             pathID: nullptr,
             pfnEvaluateSymbolProc: nullptr) )
      {
        FirstSubKey = KeyValues::GetFirstSubKey(this: v3);
        pIter = FirstSubKey;
        if ( FirstSubKey != nullptr )
        {
          while ( 1 )
          {
            Name = KeyValues::GetName(this: FirstSubKey);
            V_strncpy(pDest: factorytouse, pSrc: Name, maxLen: 512);
            if ( atoi(nptr: factorytouse) > 0 )
            {
              String = KeyValues::GetString(this: FirstSubKey, keyName: "factory", defaultValue: defaultValue);
              V_strncpy(pDest: factorytouse, pSrc: String, maxLen: 512);
            }
            v8 = CBaseDemoAction::TypeForName(name: factorytouse);
            DemoAction = CBaseDemoAction::CreateDemoAction(actionType: v8);
            v10 = DemoAction;
            if ( DemoAction != nullptr )
            {
              if ( DemoAction->Init(this: DemoAction, a2: FirstSubKey) )
              {
                m_nAllocationCount = v1->m_ActionStack.m_Memory.m_nAllocationCount;
                p_m_ActionStack = (CUtlMemory<S3RGBA,int> *)&v1->m_ActionStack;
                m_Size = v1->m_ActionStack.m_Size;
                if ( m_Size + 1 > m_nAllocationCount )
                  CUtlMemory<INetMessage *,int>::Grow(this: p_m_ActionStack, num: m_Size - m_nAllocationCount + 1);
                ++p_m_ActionStack[1].m_pMemory;
                m_pMemory = p_m_ActionStack->m_pMemory;
                v15 = (int)p_m_ActionStack[1].m_pMemory - m_Size - 1;
                p_m_ActionStack[1].m_nAllocationCount = (int)p_m_ActionStack->m_pMemory;
                if ( v15 > 0 )
                  _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v15);
                v16 = p_m_ActionStack->m_pMemory;
                FirstSubKey = pIter;
                v17 = (CBaseDemoAction **)&v16[m_Size];
                v1 = v20;
                if ( v17 != nullptr )
                  *v17 = v10;
              }
              else
              {
                ((void (__thiscall *)(CBaseDemoAction *, int))v10->dtr_CBaseDemoAction)(a1: v10, a2: 1);
              }
            }
            pIter = KeyValues::GetNextKey(this: FirstSubKey);
            if ( pIter == nullptr )
              break;
            FirstSubKey = pIter;
          }
        }
      }
      else
      {
        v1->SaveToFile(this: v1);
      }
    }
  }
  if ( g_pDemoUI != nullptr )
    g_pDemoUI->OnVDMChanged(this: g_pDemoUI);
  if ( g_pDemoUI2 != nullptr )
    g_pDemoUI2->OnVDMChanged(this: g_pDemoUI2);
  v1->m_bDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x1007AED0
// Name: public: virtual void CDemoActionManager::AddAction(class CBaseDemoAction __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionManager::AddAction(CDemoActionManager *this, CBaseDemoAction *action)
{
  CUtlMemory<S3RGBA,int> *p_m_ActionStack; // esi
  int m_nAllocationCount; // eax
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v6; // eax
  S3RGBA *v7; // eax

  p_m_ActionStack = (CUtlMemory<S3RGBA,int> *)&this->m_ActionStack;
  this->m_bDirty = true;
  m_nAllocationCount = this->m_ActionStack.m_Memory.m_nAllocationCount;
  m_Size = this->m_ActionStack.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow(this: p_m_ActionStack, num: m_Size - m_nAllocationCount + 1);
  ++p_m_ActionStack[1].m_pMemory;
  m_pMemory = p_m_ActionStack->m_pMemory;
  v6 = (int)p_m_ActionStack[1].m_pMemory - m_Size - 1;
  p_m_ActionStack[1].m_nAllocationCount = (int)p_m_ActionStack->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_ActionStack->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (S3RGBA)action;
}

//------------------------------------------------------------------------------
// Address: 0x1007AF40
// Name: public: virtual void CDemoActionManager::InsertFireEvent(class CBaseDemoAction __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionManager::InsertFireEvent(CDemoActionManager *this, CBaseDemoAction *action)
{
  CUtlMemory<S3RGBA,int> *p_m_PendingFireActionStack; // esi
  int m_Size; // ecx
  int v4; // eax
  CBaseDemoAction **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  S3RGBA *v8; // ecx
  int v9; // eax
  S3RGBA *v10; // eax

  p_m_PendingFireActionStack = (CUtlMemory<S3RGBA,int> *)&this->m_PendingFireActionStack;
  m_Size = this->m_PendingFireActionStack.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (CBaseDemoAction **)p_m_PendingFireActionStack->m_pMemory;
  while ( *m_pMemory != action )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 < 0 )
  {
LABEL_7:
    m_nAllocationCount = p_m_PendingFireActionStack->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: p_m_PendingFireActionStack, num: m_Size - m_nAllocationCount + 1);
    ++p_m_PendingFireActionStack[1].m_pMemory;
    v8 = p_m_PendingFireActionStack->m_pMemory;
    v9 = (int)p_m_PendingFireActionStack[1].m_pMemory - v7 - 1;
    p_m_PendingFireActionStack[1].m_nAllocationCount = (int)p_m_PendingFireActionStack->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_PendingFireActionStack->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (S3RGBA)action;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10200F30
// Name: public: virtual class CBaseDemoAction __near * CDemoActionManager::GetAction(int)
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__thiscall CDemoActionManager::GetAction(CDemoActionManager *this, int index)
{
  if ( index < 0 || index >= this->m_ActionStack.m_Size )
    return nullptr;
  else
    return this->m_ActionStack.m_Memory.m_pMemory[index];
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1007A550
// Name: public: virtual void CDemoActionManager::StartPlaying(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionManager::StartPlaying(CDemoActionManager *this, const char *demfilename)
{
  int v4; // eax
  char metafile[512]; // [esp+Ch] [ebp-200h] BYREF
  bool changedfile_3; // [esp+217h] [ebp+Bh]

  this->StopPlaying(this);
  changedfile_3 = V_strcasecmp(s1: demfilename, s2: this->m_szCurrentFile) != 0;
  V_strncpy(pDest: this->m_szCurrentFile, pSrc: demfilename, maxLen: 260);
  V_StripExtension(in: demfilename, out: metafile, outSize: 512);
  V_DefaultExtension(path: metafile, extension: ".vdm", pathStringLength: 512);
  v4 = g_pFileSystem->GetFileTime(this: &g_pFileSystem->IBaseFileSystem, a2: metafile, a3: nullptr);
  if ( changedfile_3 || this->m_lFileTime != v4 )
  {
    if ( this->m_bDirty )
      this->SaveToFile(this);
    this->ReloadFromDisk(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007A600
// Name: public: virtual char const __near * CDemoActionManager::GetCurrentDemoFile(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CDemoActionManager::GetCurrentDemoFile(CDemoActionManager *this)
{
  return this->m_szCurrentFile;
}

//------------------------------------------------------------------------------
// Address: 0x1007A620
// Name: public: virtual void CDemoActionManager::SetDirty(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionManager::SetDirty(CDemoActionManager *this, bool dirty)
{
  this->m_bDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x1007A630
// Name: public: virtual void CDemoActionManager::Update(bool,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionManager::Update(CDemoActionManager *this, bool newframe, int demotick, float demotime)
{
  int m_Size; // ebx
  int m_nPrevTick; // eax
  int v7; // esi
  CBaseDemoAction *v8; // ecx
  DemoActionTimingContext ctx; // [esp+8h] [ebp-10h] BYREF

  m_Size = this->m_ActionStack.m_Size;
  if ( m_Size > 0 )
  {
    m_nPrevTick = this->m_nPrevTick;
    ctx.prevtime = this->m_flPrevTime;
    v7 = 0;
    ctx.prevtick = m_nPrevTick;
    ctx.curtick = demotick;
    ctx.curtime = demotime;
    do
    {
      v8 = this->m_ActionStack.m_Memory.m_pMemory[v7];
      if ( v8 != nullptr )
        v8->Update(this: v8, a2: &ctx);
      ++v7;
    }
    while ( v7 < m_Size );
    this->m_nPrevTick = demotick;
    this->m_flPrevTime = demotime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007A6A0
// Name: public: virtual void CDemoActionManager::SaveToBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionManager::SaveToBuffer(CDemoActionManager *this, CUtlBuffer *buf)
{
  int m_Size; // eax
  int v5; // esi
  CBaseDemoAction *v6; // ecx
  int count; // [esp+14h] [ebp+8h]

  CUtlBuffer::Printf(this: buf, pFmt: "demoactions\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  m_Size = this->m_ActionStack.m_Size;
  v5 = 0;
  for ( count = m_Size; v5 < m_Size; ++v5 )
  {
    v6 = this->m_ActionStack.m_Memory.m_pMemory[v5];
    if ( v6 != nullptr )
    {
      CBaseDemoAction::SaveToBuffer(this: v6, depth: 1, index: v5 + 1, buf);
      m_Size = count;
    }
  }
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
}

//------------------------------------------------------------------------------
// Address: 0x1007A710
// Name: public: virtual class CBaseDemoAction __near * CDemoActionManager::GetAction(int)
// Source: json
//------------------------------------------------------------------------------
CBaseDemoAction *__thiscall CDemoActionManager::GetAction(CDemoActionManager *this, int index)
{
  if ( index < 0 || index >= this->m_ActionStack.m_Size )
    return nullptr;
  else
    return this->m_ActionStack.m_Memory.m_pMemory[index];
}

//------------------------------------------------------------------------------
// Address: 0x1007A7A0
// Name: private: void CDemoActionManager::ClearAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionManager::ClearAll(CDemoActionManager *this)
{
  CBaseDemoAction *v2; // ecx

  for ( this->m_PendingFireActionStack.m_Size = 0; this->m_ActionStack.m_Size > 0; --this->m_ActionStack.m_Size )
  {
    v2 = *this->m_ActionStack.m_Memory.m_pMemory;
    if ( v2 != nullptr )
      ((void (__thiscall *)(CBaseDemoAction *, int))v2->dtr_CBaseDemoAction)(a1: v2, a2: 1);
    if ( this->m_ActionStack.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_ActionStack.m_Memory.m_pMemory,
        src: this->m_ActionStack.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_ActionStack.m_Size - 1));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007A7F0
// Name: public: virtual void CDemoActionManager::StopPlaying(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionManager::StopPlaying(CDemoActionManager *this)
{
  int m_Size; // ebx
  int i; // esi
  CBaseDemoAction *v4; // ecx

  m_Size = this->m_ActionStack.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v4 = this->m_ActionStack.m_Memory.m_pMemory[i];
    v4->Reset(this: v4);
  }
  this->m_nPrevTick = 0;
  this->m_flPrevTime = 0.0;
  this->m_PendingFireActionStack.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1007A830
// Name: public: virtual void CDemoActionManager::RemoveAction(class CBaseDemoAction __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionManager::RemoveAction(CDemoActionManager *this, CBaseDemoAction *action)
{
  this->m_bDirty = true;
  CUtlVector<CNetChan *,CUtlMemory<CNetChan *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_ActionStack,
    src: (vgui::TreeNode **)&action);
  if ( action != nullptr )
    ((void (__thiscall *)(CBaseDemoAction *, int))action->dtr_CBaseDemoAction)(a1: action, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1007A860
// Name: public: virtual void CDemoActionManager::DispatchEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionManager::DispatchEvents(CDemoActionManager *this)
{
  int v2; // edi
  CBaseDemoAction *v3; // esi
  int c; // [esp+8h] [ebp-4h]

  v2 = 0;
  c = this->m_PendingFireActionStack.m_Size;
  if ( c <= 0 )
  {
    this->m_PendingFireActionStack.m_Size = 0;
  }
  else
  {
    do
    {
      v3 = this->m_PendingFireActionStack.m_Memory.m_pMemory[v2];
      v3->FireAction(this: v3);
      CBaseDemoAction::SetActionFired(this: v3, fired: true);
      ++v2;
    }
    while ( v2 < c );
    this->m_PendingFireActionStack.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007A8B0
// Name: public: virtual void CDemoActionManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionManager::Shutdown(CDemoActionManager *this)
{
  CBaseDemoAction **m_pMemory; // ecx

  this->StopPlaying(this);
  CDemoActionManager::ClearAll(this);
  this->m_ActionStack.m_Size = 0;
  if ( this->m_ActionStack.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ActionStack.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ActionStack.m_Memory.m_pMemory);
      this->m_ActionStack.m_Memory.m_pMemory = nullptr;
    }
    this->m_ActionStack.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ActionStack.m_pElements = this->m_ActionStack.m_Memory.m_pMemory;
  this->m_PendingFireActionStack.m_Size = 0;
  if ( this->m_PendingFireActionStack.m_Memory.m_nGrowSize < 0 )
  {
    this->m_PendingFireActionStack.m_pElements = this->m_PendingFireActionStack.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_PendingFireActionStack.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_PendingFireActionStack.m_Memory.m_pMemory);
      this->m_PendingFireActionStack.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_PendingFireActionStack.m_Memory.m_pMemory;
    this->m_PendingFireActionStack.m_Memory.m_nAllocationCount = 0;
    this->m_PendingFireActionStack.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007A930
// Name: public: virtual void CDemoActionManager::SaveToFile(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDemoActionManager::SaveToFile(CDemoActionManager *this@<ecx>, int a2@<edi>)
{
  void *v3; // eax
  void *v4; // edi
  int v5; // eax
  bool v6; // sf
  char metafile[512]; // [esp+4h] [ebp-230h] BYREF
  CUtlBuffer buf; // [esp+204h] [ebp-30h] BYREF

  if ( this->m_szCurrentFile[0] != 0 && this->m_bDirty )
  {
    V_StripExtension(in: this->m_szCurrentFile, out: metafile, outSize: 512);
    V_DefaultExtension(path: metafile, extension: ".vdm", pathStringLength: 512);
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
    ((void (__thiscall *)(CDemoActionManager *, CUtlBuffer *, int))this->SaveToBuffer)(a1: this, a2: &buf, a3: a2);
    v3 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: metafile, a3: "w", a4: 0);
    v4 = v3;
    if ( v3 != nullptr )
    {
      g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: buf.m_Memory.m_pMemory, a3: buf.m_Put, a4: v3);
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v4);
    }
    this->m_bDirty = false;
    v5 = ((int (__thiscall *)(IBaseFileSystem *, char *))g_pFileSystem->GetFileTime)(
           a1: &g_pFileSystem->IBaseFileSystem,
           a2: metafile);
    v6 = buf.m_Memory.m_nGrowSize < 0;
    this->m_lFileTime = v5;
    if ( !v6 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007AA40
// Name: public: virtual void CDemoActionManager::ReloadFromDisk(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionManager::ReloadFromDisk(CDemoActionManager *this)
{
  CDemoActionManager *v1; // edi
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IBaseFileSystem *v4; // eax
  KeyValues *FirstSubKey; // esi
  const char *Name; // eax
  const char *String; // eax
  DEMOACTION v8; // eax
  CBaseDemoAction *DemoAction; // eax
  CBaseDemoAction *v10; // ebx
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_ActionStack; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v15; // eax
  S3RGBA *v16; // ecx
  CBaseDemoAction **v17; // eax
  char factorytouse[512]; // [esp+4h] [ebp-408h] BYREF
  char metafile[512]; // [esp+204h] [ebp-208h] BYREF
  CDemoActionManager *v20; // [esp+404h] [ebp-8h]
  KeyValues *pIter; // [esp+408h] [ebp-4h]

  v1 = this;
  v20 = this;
  V_StripExtension(in: this->m_szCurrentFile, out: metafile, outSize: 512);
  V_DefaultExtension(path: metafile, extension: ".vdm", pathStringLength: 512);
  CDemoActionManager::ClearAll(this: v1);
  v1->m_lFileTime = g_pFileSystem->GetFileTime(this: &g_pFileSystem->IBaseFileSystem, a2: metafile, a3: nullptr);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: metafile);
    if ( v3 != nullptr )
    {
      if ( g_pFullFileSystem != nullptr )
        v4 = &g_pFullFileSystem->IBaseFileSystem;
      else
        v4 = nullptr;
      if ( KeyValues::LoadFromFile(
             this: v3,
             filesystem: v4,
             resourceName: metafile,
             pathID: nullptr,
             pfnEvaluateSymbolProc: nullptr) )
      {
        FirstSubKey = KeyValues::GetFirstSubKey(this: v3);
        pIter = FirstSubKey;
        if ( FirstSubKey != nullptr )
        {
          while ( 1 )
          {
            Name = KeyValues::GetName(this: FirstSubKey);
            V_strncpy(pDest: factorytouse, pSrc: Name, maxLen: 512);
            if ( atoi(nptr: factorytouse) > 0 )
            {
              String = KeyValues::GetString(this: FirstSubKey, keyName: "factory", defaultValue: defaultValue);
              V_strncpy(pDest: factorytouse, pSrc: String, maxLen: 512);
            }
            v8 = CBaseDemoAction::TypeForName(name: factorytouse);
            DemoAction = CBaseDemoAction::CreateDemoAction(actionType: v8);
            v10 = DemoAction;
            if ( DemoAction != nullptr )
            {
              if ( DemoAction->Init(this: DemoAction, a2: FirstSubKey) )
              {
                m_nAllocationCount = v1->m_ActionStack.m_Memory.m_nAllocationCount;
                p_m_ActionStack = (CUtlMemory<S3RGBA,int> *)&v1->m_ActionStack;
                m_Size = v1->m_ActionStack.m_Size;
                if ( m_Size + 1 > m_nAllocationCount )
                  CUtlMemory<INetMessage *,int>::Grow(this: p_m_ActionStack, num: m_Size - m_nAllocationCount + 1);
                ++p_m_ActionStack[1].m_pMemory;
                m_pMemory = p_m_ActionStack->m_pMemory;
                v15 = (int)p_m_ActionStack[1].m_pMemory - m_Size - 1;
                p_m_ActionStack[1].m_nAllocationCount = (int)p_m_ActionStack->m_pMemory;
                if ( v15 > 0 )
                  _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v15);
                v16 = p_m_ActionStack->m_pMemory;
                FirstSubKey = pIter;
                v17 = (CBaseDemoAction **)&v16[m_Size];
                v1 = v20;
                if ( v17 != nullptr )
                  *v17 = v10;
              }
              else
              {
                ((void (__thiscall *)(CBaseDemoAction *, int))v10->dtr_CBaseDemoAction)(a1: v10, a2: 1);
              }
            }
            pIter = KeyValues::GetNextKey(this: FirstSubKey);
            if ( pIter == nullptr )
              break;
            FirstSubKey = pIter;
          }
        }
      }
      else
      {
        v1->SaveToFile(this: v1);
      }
    }
  }
  if ( g_pDemoUI != nullptr )
    g_pDemoUI->OnVDMChanged(this: g_pDemoUI);
  if ( g_pDemoUI2 != nullptr )
    g_pDemoUI2->OnVDMChanged(this: g_pDemoUI2);
  v1->m_bDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x1007AC40
// Name: public: virtual void CDemoActionManager::AddAction(class CBaseDemoAction __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionManager::AddAction(CDemoActionManager *this, CBaseDemoAction *action)
{
  CUtlMemory<S3RGBA,int> *p_m_ActionStack; // esi
  int m_nAllocationCount; // eax
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v6; // eax
  S3RGBA *v7; // eax

  p_m_ActionStack = (CUtlMemory<S3RGBA,int> *)&this->m_ActionStack;
  this->m_bDirty = true;
  m_nAllocationCount = this->m_ActionStack.m_Memory.m_nAllocationCount;
  m_Size = this->m_ActionStack.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow(this: p_m_ActionStack, num: m_Size - m_nAllocationCount + 1);
  ++p_m_ActionStack[1].m_pMemory;
  m_pMemory = p_m_ActionStack->m_pMemory;
  v6 = (int)p_m_ActionStack[1].m_pMemory - m_Size - 1;
  p_m_ActionStack[1].m_nAllocationCount = (int)p_m_ActionStack->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_ActionStack->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (S3RGBA)action;
}

//------------------------------------------------------------------------------
// Address: 0x1007ACB0
// Name: public: virtual void CDemoActionManager::InsertFireEvent(class CBaseDemoAction __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoActionManager::InsertFireEvent(CDemoActionManager *this, CBaseDemoAction *action)
{
  CUtlMemory<S3RGBA,int> *p_m_PendingFireActionStack; // esi
  int m_Size; // ecx
  int v4; // eax
  CBaseDemoAction **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  S3RGBA *v8; // ecx
  int v9; // eax
  S3RGBA *v10; // eax

  p_m_PendingFireActionStack = (CUtlMemory<S3RGBA,int> *)&this->m_PendingFireActionStack;
  m_Size = this->m_PendingFireActionStack.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (CBaseDemoAction **)p_m_PendingFireActionStack->m_pMemory;
  while ( *m_pMemory != action )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 < 0 )
  {
LABEL_7:
    m_nAllocationCount = p_m_PendingFireActionStack->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: p_m_PendingFireActionStack, num: m_Size - m_nAllocationCount + 1);
    ++p_m_PendingFireActionStack[1].m_pMemory;
    v8 = p_m_PendingFireActionStack->m_pMemory;
    v9 = (int)p_m_PendingFireActionStack[1].m_pMemory - v7 - 1;
    p_m_PendingFireActionStack[1].m_nAllocationCount = (int)p_m_PendingFireActionStack->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_PendingFireActionStack->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (S3RGBA)action;
  }
}

} // namespace engine_xlsp
