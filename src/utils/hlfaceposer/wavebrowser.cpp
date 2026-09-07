// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/wavebrowser.cpp
// Functions: 36
// ============================================================

#include "utils\hlfaceposer\wavebrowser.h"

//------------------------------------------------------------------------------
// Address: 0x0041D4F0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CMapEntityData,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapEntityData,int>::Node_t,int>,int>::Grow(
        CUtlMemory<HitboxSet_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  HitboxSet_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 44 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (HitboxSet_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (HitboxSet_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043D760
// Name: bool NameLessFunc(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl NameLessFunc(const char **name1, const char **name2)
{
  return _V_stricmp(s1: *name1, s2: *name2) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043EFA0
// Name: public: void CUtlDict<struct CMapEntityData,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CMapEntityData,int>::RemoveAll(CUtlDict<CMapEntityData,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CMapEntityData,int>::Node_t,int,CUtlMap<char const *,CMapEntityData,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapEntityData,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CMapEntityData,int>::Node_t,int,CUtlMap<char const *,CMapEntityData,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapEntityData,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CMapEntityData,int>::Node_t,int,CUtlMap<char const *,CMapEntityData,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapEntityData,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x0043F1E0
// Name: public: int CUtlDict<struct CMapEntityData,int>::Insert(char const __near *,struct CMapEntityData const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CMapEntityData,int>::Insert(
        CUtlDict<CMapEntityData,int> *this,
        const char *pName,
        const CMapEntityData *element)
{
  char *v4; // eax
  CUtlMap<char const *,CMapEntityData,int>::Node_t insert; // [esp+8h] [ebp-1Ch] BYREF

  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v4, pName);
  else
    v4 = nullptr;
  insert.key = v4;
  insert.elem = *element;
  return CUtlRBTree<CUtlMap<char const *,CMapEntityData,int>::Node_t,int,CUtlMap<char const *,CMapEntityData,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMapEntityData,int>::Node_t,int>,int>>::Insert(
           this: &this->m_Elements.m_Tree,
           a2: pName,
           &insert);
}

//------------------------------------------------------------------------------
// Address: 0x0044C960
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int> *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: 60 * m_nAllocationCount);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ExpressionTool::CColumnCopier::CTrackData,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 60 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00485FE0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlSymbolTree::FileTreePath,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTree::FileTreePath,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTree::FileTreePath,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlSymbolTree::FileTreePath,int> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 276 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTree::FileTreePath,int> *)_g_pMemAlloc->Realloc_2(
                                                                               this: _g_pMemAlloc,
                                                                               a2: m_pMemory,
                                                                               a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTree::FileTreePath,int> *)_g_pMemAlloc->Alloc_2(
                                                                               this: _g_pMemAlloc,
                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00488030
// Name: public: CWaveList::CWaveList(class mxWindow __near *,int)
// Source: json
//------------------------------------------------------------------------------
CWaveList *__thiscall CWaveList::CWaveList(CWaveList *this, mxWindow *parent, int id)
{
  mxListView::mxListView(this, parent, x: 0, y: 0, w: 0, h: 0, id);
  this->__vftable = (CWaveList_vtbl *)&CWaveList::`vftable';
  mxListView::insertTextColumn(this, column: 0, width: 300, label: "WAV");
  mxListView::insertTextColumn(this, column: 1, width: 50, label: "Ducked");
  mxListView::insertTextColumn(this, column: 2, width: 120, label: "Words [ Phonemes ]");
  mxListView::insertTextColumn(this, column: 3, width: 300, label: "Sentence Text");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004880C0
// Name: public: CWaveOptionsWindow::CWaveOptionsWindow(class CWaveBrowser __near *)
// Source: json
//------------------------------------------------------------------------------
CWaveOptionsWindow *__thiscall CWaveOptionsWindow::CWaveOptionsWindow(CWaveOptionsWindow *this, CWaveBrowser *browser)
{
  mxButton *v3; // [esp+0h] [ebp-24h]
  mxLineEdit *v4; // [esp+4h] [ebp-20h]
  mxButton *v5; // [esp+8h] [ebp-1Ch]
  mxButton *v6; // [esp+Ch] [ebp-18h]
  mxButton *v8; // [esp+14h] [ebp-10h]
  mxLineEdit *v9; // [esp+18h] [ebp-Ch]
  mxButton *v10; // [esp+1Ch] [ebp-8h]
  mxButton *v11; // [esp+20h] [ebp-4h]

  mxWindow::mxWindow(this, parent: browser, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
  this->__vftable = (CWaveOptionsWindow_vtbl *)&CWaveOptionsWindow::`vftable';
  this->m_pBrowser = browser;
  FacePoser_AddWindowStyle(w: this, addbits: 100663296);
  this->m_szSearchString[0] = 0;
  v11 = (mxButton *)operator new(nSize: 0xCu);
  if ( v11 != nullptr )
    v6 = mxButton::mxButton(this: v11, parent: this, x: 0, y: 0, w: 0, h: 0, label: "Play", id: 1000);
  else
    v6 = nullptr;
  this->m_pPlay = v6;
  v10 = (mxButton *)operator new(nSize: 0xCu);
  if ( v10 != nullptr )
    v5 = mxButton::mxButton(this: v10, parent: this, x: 0, y: 0, w: 0, h: 0, label: "Stop Sounds", id: 1001);
  else
    v5 = nullptr;
  this->m_pStopSounds = v5;
  v9 = (mxLineEdit *)operator new(nSize: 0xCu);
  if ( v9 != nullptr )
    v4 = mxLineEdit::mxLineEdit(this: v9, parent: this, x: 0, y: 0, w: 0, h: 0, label: defaultValue, id: 1002, style: 0);
  else
    v4 = nullptr;
  this->m_pSearch = v4;
  v8 = (mxButton *)operator new(nSize: 0xCu);
  if ( v8 != nullptr )
    v3 = mxButton::mxButton(this: v8, parent: this, x: 0, y: 0, w: 0, h: 0, label: "Cancel", id: 1003);
  else
    v3 = nullptr;
  this->m_pCancelSearch = v3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00488230
// Name: public: char const __near * CWaveOptionsWindow::GetSearchString(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CWaveOptionsWindow::GetSearchString(CWaveOptionsWindow *this)
{
  return this->m_szSearchString;
}

//------------------------------------------------------------------------------
// Address: 0x00488250
// Name: NameLessFunc
// Source: json
//------------------------------------------------------------------------------
bool __cdecl NameLessFunc(CWaveFile **name1, CWaveFile **name2)
{
  const char *v2; // eax
  const char *Name; // [esp-4h] [ebp-4h]

  Name = CWaveFile::GetName(this: *name2);
  v2 = CWaveFile::GetName(this: *name1);
  return _V_stricmp(s1: v2, s2: Name) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x00488280
// Name: public: void CWaveBrowser::SetCurrent(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveBrowser::SetCurrent(CWaveBrowser *this, const char *filename)
{
  const char *v2; // esi
  int ItemCount; // ebx
  int i; // esi
  CWaveFile *UserData; // eax
  const char *Name; // eax
  int v8; // eax
  CWaveList *m_pListView; // ecx
  char fixed[512]; // [esp+Ch] [ebp-400h] BYREF
  char fn[512]; // [esp+20Ch] [ebp-200h] BYREF

  v2 = filename;
  if ( filename != nullptr
    && (V_strnicmp(s1: filename, s2: "sound/", n: 6) == 0 || V_strnicmp(s1: filename, s2: "sound\\", n: 6) == 0) )
  {
    v2 = filename + 6;
  }
  V_strncpy(pDest: fn, pSrc: v2, maxLen: 512);
  V_FixSlashes(pname: fn, separator: 92);
  ItemCount = mxListView::getItemCount(this: this->m_pListView);
  for ( i = 0; i < ItemCount; ++i )
  {
    UserData = (CWaveFile *)mxListView::getUserData(this: this->m_pListView, item: i, column: 0);
    if ( UserData != nullptr )
    {
      Name = CWaveFile::GetName(this: UserData);
      V_strncpy(pDest: fixed, pSrc: Name, maxLen: 512);
      V_FixSlashes(pname: fixed, separator: 92);
      v8 = _V_stricmp(s1: fixed, s2: fn);
      m_pListView = this->m_pListView;
      if ( v8 != 0 )
      {
        mxListView::setSelected(this: m_pListView, item: i, b: false);
      }
      else
      {
        mxListView::scrollToItem(this: m_pListView, item: i);
        mxListView::setSelected(this: this->m_pListView, item: i, b: true);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00488380
// Name: public: virtual void CWaveOptionsWindow::redraw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveOptionsWindow::redraw(CVCDOptionsWindow *this)
{
  const Color *v1; // eax
  Color result; // [esp+4h] [ebp-60h] BYREF
  unsigned int clr; // [esp+8h] [ebp-5Ch] BYREF
  CChoreoWidgetDrawHelper drawHelper; // [esp+Ch] [ebp-58h] BYREF

  clr = GetSysColor(nIndex: 15);
  v1 = RGBToColor(&result, &clr);
  CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: this, bgColor: v1);
  CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
}

//------------------------------------------------------------------------------
// Address: 0x004883F0
// Name: public: void CWaveBrowser::SetEvent(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveBrowser::SetEvent(CWaveBrowser *this, CChoreoEvent *event)
{
  const char *Parameters; // eax
  const char *v4; // eax

  if ( CChoreoEvent::GetType(this: event) == SPEAK )
  {
    Parameters = CChoreoEvent::GetParameters(this: event);
    v4 = FacePoser_TranslateSoundName(soundname: Parameters, model: nullptr);
    CWaveBrowser::SetCurrent(this, filename: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00489910
// Name: public: char const __near * CWaveFileTree::GetSelectedPath(void)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolTree::FileTreePath *__thiscall CWaveFileTree::GetSelectedPath(CUtlSymbolTree *this)
{
  void **SelectedItem; // eax
  unsigned int UserData; // eax

  SelectedItem = mxTreeView::getSelectedItem(this);
  UserData = (unsigned int)mxTreeView::getUserData(this, item: SelectedItem);
  if ( UserData >= this->m_Paths.m_NumElements )
    return (CUtlSymbolTree::FileTreePath *)defaultValue;
  else
    return &this->m_Paths.m_Elements.m_pMemory[UserData].m_Data;
}

//------------------------------------------------------------------------------
// Address: 0x0048AFF0
// Name: bool SceneManager_LoadSentenceFromWavFileUsingIO(char const __near *,class CSentence __near &,class IFileReadBinary __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SceneManager_LoadSentenceFromWavFileUsingIO(const char *wavfile, CSentence *sentence, IFileReadBinary *io)
{
  char v4; // bl
  int NumEvents; // eax
  int v6; // eax
  CUtlBuffer v7; // [esp+4h] [ebp-58h] BYREF
  IterateRIFF walk; // [esp+34h] [ebp-28h] BYREF
  InFileRIFF riff; // [esp+4Ch] [ebp-10h] BYREF

  CSentence::Reset(this: sentence);
  InFileRIFF::InFileRIFF(this: &riff, pFileName: wavfile, io);
  if ( riff.m_riffName == 1163280727 )
  {
    IterateRIFF::IterateRIFF(this: &walk, &riff, size: riff.m_riffSize);
    v4 = 0;
    while ( IterateRIFF::ChunkAvailable(this: &walk) )
    {
      if ( v4 != 0 )
        break;
      if ( CAudioSourceMemWave::GetNumChannels(this: &walk) == 1413563478 )
      {
        v4 = 1;
        CUtlBuffer::CUtlBuffer(this: &v7, growSize: 0, initSize: 0, nFlags: 1);
        NumEvents = CChoreoScene::GetNumEvents(this: &walk);
        CUtlBuffer::EnsureCapacity(this: &v7, num: NumEvents);
        IterateRIFF::ChunkRead(this: &walk, pOutput: v7.m_Memory.m_pMemory);
        v6 = CChoreoScene::GetNumEvents(this: &walk);
        CUtlBuffer::SeekPut(this: &v7, type: SEEK_HEAD, offset: v6);
        CSentence::InitFromDataChunk(this: sentence, data: v7.m_Memory.m_pMemory, size: v7.m_Put);
        if ( v7.m_Memory.m_nGrowSize >= 0 && v7.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7.m_Memory.m_pMemory);
      }
      IterateRIFF::ChunkNext(this: &walk);
    }
    InFileRIFF::~InFileRIFF(this: &riff);
    return 1;
  }
  else
  {
    InFileRIFF::~InFileRIFF(this: &riff);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048B100
// Name: bool SceneManager_LoadSentenceFromWavFile(char const __near *,class CSentence __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SceneManager_LoadSentenceFromWavFile(const char *wavfile, CSentence *sentence)
{
  return SceneManager_LoadSentenceFromWavFileUsingIO(wavfile, sentence, io: &io_in_1);
}

//------------------------------------------------------------------------------
// Address: 0x0048B120
// Name: public: void CWaveFileTree::PopulateTree(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveFileTree::PopulateTree(CWaveFileTree *this)
{
  UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *i; // esi
  void **FirstChild; // eax

  for ( i = (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::FirstInorder(this: &this->m_Paths);
        i != (UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int> *)-1;
        i = CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::NextInorder(
              this: &this->m_Paths,
              (int)i) )
  {
    CUtlSymbolTree::_PopulateTree(
      (CUtlSymbolTree *)this,
      pathId: (int)i,
      path: this->m_Paths.m_Elements.m_pMemory[(_DWORD)i].m_Data.path);
  }
  FirstChild = mxTreeView::getFirstChild(this, item: nullptr);
  mxTreeView::setOpen(this, item: FirstChild, b: true);
}

//------------------------------------------------------------------------------
// Address: 0x0048B2B0
// Name: public: void CWaveBrowser::BuildSelectionList(class CUtlVector<class CWaveFile __near *,class CUtlMemory<class CWaveFile __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveBrowser::BuildSelectionList(
        CWaveBrowser *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *selected)
{
  int v3; // ebx
  int NextSelectedItem; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CWaveFile **v7; // ecx
  int v8; // eax
  CWaveFile **v9; // eax
  CWaveFile *wav; // [esp+18h] [ebp+8h]

  selected[1].m_pMemory = nullptr;
  v3 = -1;
  while ( 1 )
  {
    NextSelectedItem = mxListView::getNextSelectedItem(this: this->m_pListView, startitem: v3);
    v3 = NextSelectedItem;
    if ( NextSelectedItem == -1 )
      break;
    wav = (CWaveFile *)mxListView::getUserData(this: this->m_pListView, item: NextSelectedItem, column: 0);
    if ( wav != nullptr )
    {
      m_pMemory = (int)selected[1].m_pMemory;
      m_nAllocationCount = selected->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IFacePoserToolWindow *,int>::Grow(this: selected, num: m_pMemory - m_nAllocationCount + 1);
      ++selected[1].m_pMemory;
      v7 = (CWaveFile **)selected->m_pMemory;
      v8 = (int)selected[1].m_pMemory - m_pMemory - 1;
      selected[1].m_nAllocationCount = (int)selected->m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &v7[m_pMemory + 1], src: &v7[m_pMemory], count: 4 * v8);
      v9 = (CWaveFile **)&selected->m_pMemory[m_pMemory];
      if ( v9 != nullptr )
        *v9 = wav;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048B360
// Name: private: void CWaveBrowser::ShowContextMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveBrowser::ShowContextMenu(CWaveBrowser *this)
{
  IFacePoserToolWindow *v2; // eax
  HWND Handle; // eax
  mxPopupMenu *v4; // eax
  mxPopupMenu *v5; // edi
  tagPOINT pt; // [esp+4h] [ebp-8h] BYREF

  if ( this != nullptr )
    v2 = &this->IFacePoserToolWindow;
  else
    v2 = nullptr;
  IFacePoserToolWindow::SetActiveTool(tool: v2);
  CWaveBrowser::BuildSelectionList(
    this,
    selected: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_CurrentSelection);
  if ( this->m_CurrentSelection.m_Size > 0 )
  {
    GetCursorPos(lpPoint: &pt);
    Handle = (HWND)mxWidget::getHandle(this);
    ScreenToClient(hWnd: Handle, lpPoint: &pt);
    v4 = (mxPopupMenu *)operator new(nSize: 0xCu);
    if ( v4 != nullptr )
      v5 = mxPopupMenu::mxPopupMenu(this: v4);
    else
      v5 = nullptr;
    if ( this->m_CurrentSelection.m_Size == 1 )
      mxPopupMenu::add(this: v5, item: "&Play", id: 1000);
    mxPopupMenu::popup(this: v5, widget: this, x: pt.x, y: pt.y);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048B400
// Name: public: void CWaveBrowser::OnPlay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveBrowser::OnPlay(CWaveBrowser *this)
{
  IFacePoserToolWindow *v2; // eax
  CWaveFile *v3; // ecx

  if ( this != nullptr )
    v2 = &this->IFacePoserToolWindow;
  else
    v2 = nullptr;
  IFacePoserToolWindow::SetActiveTool(tool: v2);
  CWaveBrowser::BuildSelectionList(
    this,
    selected: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_CurrentSelection);
  if ( this->m_CurrentSelection.m_Size == 1 )
  {
    v3 = *this->m_CurrentSelection.m_Memory.m_pMemory;
    if ( v3 != nullptr )
      CWaveFile::Play(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048B450
// Name: public: void CUtlDict<class CWaveFile __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CWaveFile *,int>::RemoveAll(CUtlDict<CWaveFile *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x0048B4D0
// Name: private: void CWaveBrowser::RemoveAllSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveBrowser::RemoveAllSounds(CWaveBrowser *this)
{
  CWaveBrowser *v1; // ebx
  int v2; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *m_pMemory; // eax
  CWaveFile *elem; // esi
  CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int> > *p_m_Tree; // edi
  int Inorder; // esi
  CWaveFileTree *m_pFileTree; // ebx
  int m_NumElements; // [esp+10h] [ebp-4h]

  v1 = this;
  if ( this->m_AllSounds.m_Elements.m_Tree.m_NumElements > 0 )
  {
    v2 = 0;
    m_NumElements = this->m_AllSounds.m_Elements.m_Tree.m_NumElements;
    do
    {
      m_pMemory = v1->m_AllSounds.m_Elements.m_Tree.m_Elements.m_pMemory;
      elem = m_pMemory[v2].m_Data.elem;
      if ( elem != nullptr )
      {
        CWaveFile::~CWaveFile(this: m_pMemory[v2].m_Data.elem);
        free(pMem: elem);
      }
      ++v2;
      --m_NumElements;
    }
    while ( m_NumElements != 0 );
  }
  p_m_Tree = &v1->m_AllSounds.m_Elements.m_Tree;
  Inorder = CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::FirstInorder(this: &v1->m_AllSounds.m_Elements.m_Tree);
  if ( Inorder != -1 )
  {
    do
    {
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: (void *)v1->m_AllSounds.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.key);
      Inorder = CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::NextInorder(
                  this: p_m_Tree,
                  i: Inorder);
    }
    while ( Inorder != -1 );
    v1 = this;
  }
  CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::RemoveAll(this: p_m_Tree);
  v1->m_Scripts.m_Size = 0;
  v1->m_CurrentSelection.m_Size = 0;
  m_pFileTree = v1->m_pFileTree;
  mxTreeView::removeAll(this: m_pFileTree);
  CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::RemoveAll(this: &m_pFileTree->m_Paths);
}

//------------------------------------------------------------------------------
// Address: 0x0048B600
// Name: public: virtual void CWaveBrowser::OnDelete(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CWaveBrowser::OnDelete(CWaveBrowser *this)
{
  CWaveBrowser::RemoveAllSounds(this);
}

//------------------------------------------------------------------------------
// Address: 0x0048B610
// Name: private: void CWaveBrowser::PopulateTree(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveBrowser::PopulateTree(CWaveBrowser *this, const char *subdirectory)
{
  const char *v3; // esi
  int m_NumElements; // eax
  const char *Name; // esi
  const char *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<CWaveFile *,int> *m_pMemory; // ecx
  int v9; // edx
  unsigned int v10; // esi
  int v11; // edx
  CWaveFile **p_m_Data; // esi
  CWaveList *m_pListView; // ecx
  int NextSelectedItem; // eax
  const char *Label; // eax
  int v16; // esi
  int v17; // eax
  CWaveFile *m_Data; // esi
  const char *v19; // ebx
  int v20; // eax
  int v21; // ebx
  int m_Size; // eax
  int v23; // ebx
  CWaveFile **v24; // ecx
  int v25; // eax
  CWaveFile **v26; // ebx
  bool v27; // zf
  const char *v28; // eax
  const char *v29; // eax
  int WordCount; // eax
  CWaveFile **v31; // eax
  int v32; // [esp-4h] [ebp-264h]
  int PhonemeCount; // [esp-4h] [ebp-264h]
  const char *SentenceText; // [esp-4h] [ebp-264h]
  char prevSelectedName[512]; // [esp+Ch] [ebp-254h] BYREF
  CUtlRBTree<CWaveFile *,int,bool (__cdecl*)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int> > m_Sorted; // [esp+20Ch] [ebp-54h] BYREF
  int len; // [esp+230h] [ebp-30h]
  int parent; // [esp+234h] [ebp-2Ch] BYREF
  const char *texttofind; // [esp+238h] [ebp-28h]
  CWaveFile *wav; // [esp+23Ch] [ebp-24h] BYREF
  CUtlVector<CWaveFile *,CUtlMemory<CWaveFile *,int> > list; // [esp+240h] [ebp-20h] BYREF
  int selectedSlot; // [esp+254h] [ebp-Ch]
  int i; // [esp+258h] [ebp-8h]
  bool leftchild; // [esp+25Eh] [ebp-2h] BYREF
  bool check_load_sentence_data; // [esp+25Fh] [ebp-1h]
  int slot; // [esp+268h] [ebp+8h]

  m_Sorted.m_LessFunc = (bool (__cdecl *)(CWaveFile *const *, CWaveFile *const *))NameLessFunc;
  memset(&m_Sorted.m_Elements, 0, sizeof(m_Sorted.m_Elements));
  m_Sorted.m_Root = -1;
  m_Sorted.m_NumElements = 0;
  m_Sorted.m_FirstFree = -1;
  m_Sorted.m_LastAlloc.index = -1;
  m_Sorted.m_pElements = nullptr;
  check_load_sentence_data = false;
  texttofind = nullptr;
  if ( this->m_bTextSearch )
  {
    v3 = nullptr;
    subdirectory = nullptr;
    texttofind = CWaveOptionsWindow::GetSearchString(this: this->m_pOptions);
  }
  else
  {
    v3 = subdirectory;
  }
  len = 0;
  if ( v3 != nullptr )
  {
    len = _V_strlen(str: v3);
    if ( _V_strstr(s1: v3, search: "/") != nullptr || (check_load_sentence_data = false, *v3 != 0) )
      check_load_sentence_data = true;
  }
  m_NumElements = this->m_AllSounds.m_Elements.m_Tree.m_NumElements;
  if ( m_NumElements > 0 )
  {
    i = 0;
    for ( selectedSlot = m_NumElements; selectedSlot != 0; --selectedSlot )
    {
      wav = *(CWaveFile **)((char *)&this->m_AllSounds.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem + i);
      Name = CWaveFile::GetName(this: wav);
      if ( subdirectory == nullptr
        || (v32 = len, v6 = CWaveFile::GetName(this: wav), V_strnicmp(s1: subdirectory, s2: v6, n: v32) == 0) )
      {
        if ( !this->m_bTextSearch || texttofind == nullptr || V_stristr(pStr: Name, pSearch: texttofind) != nullptr )
        {
          parent = -1;
          leftchild = false;
          CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::FindInsertionPosition(
            this: &m_Sorted,
            insert: &wav,
            &parent,
            &leftchild);
          v7 = CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::NewNode(
                 this: (CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *)&m_Sorted,
                 a2: (const char *)this);
          m_pMemory = m_Sorted.m_Elements.m_pMemory;
          v9 = parent;
          v10 = v7;
          m_Sorted.m_Elements.m_pMemory[v10].m_Parent = parent;
          m_pMemory[v10].m_Right = -1;
          m_pMemory[v10].m_Left = -1;
          m_pMemory[v10].m_Tag = 0;
          if ( v9 == -1 )
          {
            m_Sorted.m_Root = v7;
          }
          else
          {
            v11 = v9;
            if ( leftchild )
              m_pMemory[v11].m_Left = v7;
            else
              m_pMemory[v11].m_Right = v7;
          }
          CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::InsertRebalance(
            this: &m_Sorted,
            elem: v7);
          ++m_Sorted.m_NumElements;
          p_m_Data = &m_Sorted.m_Elements.m_pMemory[v10].m_Data;
          if ( p_m_Data != nullptr )
            *p_m_Data = wav;
        }
      }
      i += 24;
    }
  }
  m_pListView = this->m_pListView;
  prevSelectedName[0] = 0;
  if ( mxListView::getNumSelected(this: m_pListView) == 1 )
  {
    NextSelectedItem = mxListView::getNextSelectedItem(this: this->m_pListView, startitem: 0);
    if ( NextSelectedItem >= 0 )
    {
      Label = mxListView::getLabel(this: this->m_pListView, item: NextSelectedItem, column: 0);
      _V_strcpy(dest: prevSelectedName, src: Label);
    }
  }
  mxListView::removeAll(this: this->m_pListView);
  mxListView::setDrawingEnabled(this: this->m_pListView, draw: false);
  v16 = -1;
  selectedSlot = -1;
  memset(&list, 0, sizeof(list));
  v17 = CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::FirstInorder(this: &m_Sorted);
  i = v17;
  if ( v17 != -1 )
  {
    while ( 1 )
    {
      m_Data = m_Sorted.m_Elements.m_pMemory[v17].m_Data;
      v19 = CWaveFile::GetName(this: m_Data);
      slot = mxListView::add(this: this->m_pListView, item: v19);
      v20 = _V_stricmp(s1: prevSelectedName, s2: v19);
      v21 = slot;
      if ( v20 == 0 )
        selectedSlot = slot;
      if ( (check_load_sentence_data || this->m_bTextSearch)
        && !CWaveFile::HasLoadedSentenceInfo(this: m_Data)
        && !m_Data->m_bAsyncLoading )
      {
        m_Data->m_bAsyncLoading = true;
        m_Size = list.m_Size;
        v23 = list.m_Size;
        if ( list.m_Size + 1 > list.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IFacePoserToolWindow *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&list,
            num: list.m_Size - list.m_Memory.m_nAllocationCount + 1);
          m_Size = list.m_Size;
        }
        v24 = list.m_Memory.m_pMemory;
        list.m_Size = m_Size + 1;
        v25 = m_Size - v23;
        list.m_pElements = list.m_Memory.m_pMemory;
        if ( v25 > 0 )
        {
          _V_memmove(dest: &list.m_Memory.m_pMemory[v23 + 1], src: &list.m_Memory.m_pMemory[v23], count: 4 * v25);
          v24 = list.m_Memory.m_pMemory;
        }
        v26 = &v24[v23];
        if ( v26 != nullptr )
          *v26 = m_Data;
        v21 = slot;
      }
      mxListView::setUserData(this: this->m_pListView, item: v21, column: 0, userData: m_Data);
      if ( CWaveFile::HasLoadedSentenceInfo(this: m_Data) )
      {
        v27 = !CWaveFile::GetVoiceDuck(this: m_Data);
        v28 = "yes";
        if ( v27 )
          v28 = "no";
        mxListView::setLabel(this: this->m_pListView, item: v21, column: 1, label: v28);
        if ( CWaveFile::GetPhonemeCount(this: m_Data) != 0 || CWaveFile::GetWordCount(this: m_Data) != 0 )
        {
          PhonemeCount = CWaveFile::GetPhonemeCount(this: m_Data);
          WordCount = CWaveFile::GetWordCount(this: m_Data);
          v29 = va(fmt: "%i [ %i ]", WordCount, PhonemeCount);
        }
        else
        {
          v29 = defaultValue;
        }
        mxListView::setLabel(this: this->m_pListView, item: v21, column: 2, label: v29);
        SentenceText = CWaveFile::GetSentenceText(this: m_Data);
        mxListView::setLabel(this: this->m_pListView, item: v21, column: 3, label: SentenceText);
      }
      else
      {
        mxListView::setLabel(this: this->m_pListView, item: v21, column: 3, label: "(loading...)");
      }
      i = CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::NextInorder(
            this: &m_Sorted,
            i);
      if ( i == -1 )
        break;
      v17 = i;
    }
    v16 = selectedSlot;
  }
  mxListView::setDrawingEnabled(this: this->m_pListView, draw: true);
  if ( v16 != -1 )
  {
    mxListView::setSelected(this: this->m_pListView, item: v16, b: true);
    mxListView::scrollToItem(this: this->m_pListView, item: v16);
  }
  if ( list.m_Size > 0 )
    fileloader->AddWaveFilesToThread(this: fileloader, a2: &list);
  v31 = list.m_Memory.m_pMemory;
  list.m_Size = 0;
  if ( list.m_Memory.m_nGrowSize >= 0 )
  {
    if ( list.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
      v31 = nullptr;
      list.m_Memory.m_pMemory = nullptr;
    }
    list.m_Memory.m_nAllocationCount = 0;
  }
  list.m_pElements = v31;
  if ( list.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v31 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v31);
      list.m_Memory.m_pMemory = nullptr;
    }
    list.m_Memory.m_nAllocationCount = 0;
  }
  CUtlRBTree<CWaveFile *,int,bool (__cdecl *)(CWaveFile * const &,CWaveFile * const &),CUtlMemory<UtlRBTreeNode_t<CWaveFile *,int>,int>>::RemoveAll(this: &m_Sorted);
  if ( m_Sorted.m_Elements.m_nGrowSize >= 0 && m_Sorted.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_Sorted.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0048BA70
// Name: public: void CWaveBrowser::OnSearch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveBrowser::OnSearch(CWaveBrowser *this)
{
  IFacePoserToolWindow *v2; // eax
  CWaveOptionsWindow *m_pOptions; // ecx
  char *SearchString; // eax

  if ( this != nullptr )
    v2 = &this->IFacePoserToolWindow;
  else
    v2 = nullptr;
  IFacePoserToolWindow::SetActiveTool(tool: v2);
  m_pOptions = this->m_pOptions;
  this->m_bTextSearch = true;
  SearchString = CWaveOptionsWindow::GetSearchString(this: m_pOptions);
  CWaveBrowser::PopulateTree(this, subdirectory: SearchString);
}

//------------------------------------------------------------------------------
// Address: 0x0048BAB0
// Name: public: void CWaveBrowser::OnCancelSearch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveBrowser::OnCancelSearch(CWaveBrowser *this)
{
  IFacePoserToolWindow *v2; // eax
  CWaveFileTree *m_pFileTree; // esi
  void **SelectedItem; // eax
  unsigned int UserData; // eax

  if ( this != nullptr )
    v2 = &this->IFacePoserToolWindow;
  else
    v2 = nullptr;
  IFacePoserToolWindow::SetActiveTool(tool: v2);
  m_pFileTree = this->m_pFileTree;
  this->m_bTextSearch = false;
  SelectedItem = mxTreeView::getSelectedItem(this: m_pFileTree);
  UserData = (unsigned int)mxTreeView::getUserData(this: m_pFileTree, item: SelectedItem);
  if ( UserData >= m_pFileTree->m_Paths.m_NumElements )
    CWaveBrowser::PopulateTree(this, subdirectory: defaultValue);
  else
    CWaveBrowser::PopulateTree(this, subdirectory: m_pFileTree->m_Paths.m_Elements.m_pMemory[UserData].m_Data.path);
}

//------------------------------------------------------------------------------
// Address: 0x0048BB20
// Name: public: virtual void CWaveBrowser::Think(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveBrowser::Think(CWaveBrowser *this, float dt)
{
  int v3; // eax
  CWaveBrowser *v4; // edi
  mxTreeView *m_Size; // esi
  void **SelectedItem; // eax
  mxTreeView_i *UserData; // eax
  const char *v8; // [esp-4h] [ebp-8h]

  v3 = fileloader->GetPendingLoadCount(this: fileloader);
  if ( v3 != this->m_CurrentSelection.m_Memory.m_nGrowSize )
  {
    this->m_CurrentSelection.m_Memory.m_nGrowSize = v3;
    if ( v3 != 0 )
    {
      v8 = va(fmt: " - %i", v3);
      IFacePoserToolWindow::SetSuffix((IFacePoserToolWindow *)this, suffix: v8);
    }
    else
    {
      IFacePoserToolWindow::SetSuffix((IFacePoserToolWindow *)this, suffix: defaultValue);
    }
  }
  if ( fileloader->ProcessCompleted(this: fileloader) > 0 )
  {
    v4 = (CWaveBrowser *)((char *)this - 12);
    m_Size = (mxTreeView *)this->m_Scripts.m_Size;
    SelectedItem = mxTreeView::getSelectedItem(this: m_Size);
    UserData = (mxTreeView_i *)mxTreeView::getUserData(this: m_Size, item: SelectedItem);
    if ( UserData >= m_Size[2].d_this )
      CWaveBrowser::PopulateTree(this: v4, subdirectory: defaultValue);
    else
      CWaveBrowser::PopulateTree(
        this: v4,
        subdirectory: (const char *)&m_Size[1].mxWidget::d_this[1] + 276 * (_DWORD)UserData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048BBC0
// Name: public: virtual int CWaveBrowser::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWaveBrowser::handleEvent(CWaveBrowser *this, mxEvent *event)
{
  IFacePoserToolWindow *v3; // edi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  CUtlSymbolTree::FileTreePath *SelectedPath; // eax
  int flags; // ebx
  int NextSelectedItem; // eax
  CWaveFile *UserData; // eax
  int v14; // [esp-4h] [ebp-14h]
  int iret; // [esp+Ch] [ebp-4h]

  v3 = &this->IFacePoserToolWindow;
  iret = 0;
  if ( this->HandleToolEvent(this: &this->IFacePoserToolWindow, a2: event) )
    return 0;
  v5 = event->event;
  if ( v5 != 0 )
  {
    v6 = v5 - 1;
    if ( v6 == 0 )
    {
      v7 = mxWidget::w2(this);
      mxWidget::setBounds(this: this->m_pOptions, x: 0, y: 0, w: v7, h: 20);
      v8 = mxWidget::h2(this);
      mxWidget::setBounds(this: this->m_pFileTree, x: 0, y: 20, w: 175, h: v8 - 20);
      v14 = mxWidget::h2(this) - 20;
      v9 = mxWidget::w2(this);
      mxWidget::setBounds(this: this->m_pListView, x: 175, y: 20, w: v9 - 175, h: v14);
      return 1;
    }
    if ( v6 == 18 )
      return 1;
    return iret;
  }
  iret = 1;
  switch ( event->action )
  {
    case 0x65:
      IFacePoserToolWindow::SetActiveTool(tool: v3);
      flags = event->flags;
      if ( flags == 1 )
      {
        CWaveBrowser::ShowContextMenu(this);
        return 1;
      }
      if ( flags == 2 && mxListView::getNumSelected(this: this->m_pListView) == 1 )
      {
        NextSelectedItem = mxListView::getNextSelectedItem(this: this->m_pListView, startitem: -1);
        if ( NextSelectedItem >= 0 )
        {
          UserData = (CWaveFile *)mxListView::getUserData(this: this->m_pListView, item: NextSelectedItem, column: 0);
          if ( UserData != nullptr )
            CWaveFile::Play(this: UserData);
        }
      }
      return iret;
    case 0x66:
      IFacePoserToolWindow::SetActiveTool(tool: v3);
      SelectedPath = CWaveFileTree::GetSelectedPath(this: (CUtlSymbolTree *)this->m_pFileTree);
      CWaveBrowser::PopulateTree(this, subdirectory: SelectedPath->path);
      return 1;
    case 0x3E8:
      CWaveBrowser::OnPlay(this);
      return 1;
    default:
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048BD70
// Name: public: virtual int CWaveOptionsWindow::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWaveOptionsWindow::handleEvent(CWaveOptionsWindow *this, mxEvent *event)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v7; // [esp+8h] [ebp-14h]
  int iret; // [esp+18h] [ebp-4h]

  iret = 0;
  v7 = event->event;
  if ( v7 != 0 )
  {
    if ( v7 == 1 )
    {
      iret = 1;
      v2 = mxWidget::h2(this);
      mxWidget::setBounds(this: this->m_pPlay, x: 1, y: 1, w: 120, h: v2 - 2);
      v3 = mxWidget::h2(this);
      mxWidget::setBounds(this: this->m_pStopSounds, x: 131, y: 1, w: 120, h: v3 - 2);
      v4 = mxWidget::h2(this);
      mxWidget::setBounds(this: this->m_pCancelSearch, x: 261, y: 1, w: 120, h: v4 - 2);
      v5 = mxWidget::h2(this);
      mxWidget::setBounds(this: this->m_pSearch, x: 391, y: 0, w: 360, h: v5 - 1);
    }
    else if ( v7 == 11 && event->action == 1002 )
    {
      if ( event->event == 11 )
      {
        mxLineEdit::getText(this: this->m_pSearch, buf: this->m_szSearchString, bufsize: 0x100u);
        CWaveBrowser::OnSearch(this: this->m_pBrowser);
      }
      return 1;
    }
  }
  else
  {
    switch ( event->action )
    {
      case 0x3E8:
        iret = 1;
        CWaveBrowser::OnPlay(this: this->m_pBrowser);
        break;
      case 0x3E9:
        iret = 1;
        sound->StopAll(this: sound);
        break;
      case 0x3EA:
        iret = 1;
        break;
      case 0x3EB:
        iret = 1;
        this->m_szSearchString[0] = 0;
        mxLineEdit::clear(this: this->m_pSearch);
        CWaveBrowser::OnCancelSearch(this: this->m_pBrowser);
        break;
      default:
        return iret;
    }
  }
  return iret;
}

//------------------------------------------------------------------------------
// Address: 0x0048BF70
// Name: private: bool CWaveBrowser::LoadWaveFilesInDirectory(class CUtlDict<class CWaveFile __near *,int> __near &,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWaveBrowser::LoadWaveFilesInDirectory(
        CWaveBrowser *this,
        CUtlDict<CWaveFile *,int> *soundlist,
        const char *pDirectoryName,
        int nDirectoryNameLen)
{
  int v4; // edi
  void *v5; // esp
  const char *v7; // ebx
  int v8; // esi
  void *v9; // esp
  CWaveFile *v10; // eax
  CWaveFile *v11; // ebx
  char *v12; // eax
  int v13; // eax
  int v14; // edx
  int v15; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *v16; // ecx
  int v17; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int> *v19; // eax
  CUtlMap<char const *,CWaveFile *,int>::Node_t *p_m_Data; // esi
  CWaveFileTree *m_pFileTree; // esi
  char v22; // [esp+0h] [ebp-128h] BYREF
  _BYTE v23[3]; // [esp+1h] [ebp-127h] BYREF
  CWaveFileTree::FileTreePath dest; // [esp+Ch] [ebp-11Ch] BYREF
  CWaveBrowser *v25; // [esp+110h] [ebp-18h]
  CUtlMap<char const *,CWaveFile *,int>::Node_t insert; // [esp+114h] [ebp-14h] BYREF
  int parent; // [esp+11Ch] [ebp-Ch] BYREF
  int v28; // [esp+120h] [ebp-8h] BYREF
  bool leftchild; // [esp+127h] [ebp-1h] BYREF

  v4 = nDirectoryNameLen;
  v25 = this;
  v5 = alloca(nDirectoryNameLen + 7);
  V_snprintf(pDest: &v22, maxLen: nDirectoryNameLen + 7, pFormat: "%s/*.wav", pDirectoryName);
  if ( filesystem == nullptr )
    return 0;
  v7 = filesystem->FindFirst(this: filesystem, a2: &v22, a3: &v28);
  if ( v7 != nullptr )
  {
    while ( 1 )
    {
      if ( !filesystem->FindIsDirectory(this: filesystem, a2: v28) )
      {
        v8 = _V_strlen(str: v7) + v4 + 2;
        v9 = alloca(v8);
        V_snprintf(pDest: &v22, maxLen: v8, pFormat: "%s/%s", pDirectoryName + 6, v7);
        V_strnlwr(s: &v22, count: v8);
        v10 = (CWaveFile *)operator new(nSize: 0x150u);
        v11 = v10 != nullptr ? CWaveFile::CWaveFile(this: v10, filename: &v22) : nullptr;
        if ( &v22 != nullptr
          && (v12 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: &v23[strlen(&v22)] - v23 + 1)) != nullptr )
        {
          strcpy(v12, &v22);
        }
        else
        {
          v12 = nullptr;
        }
        insert.key = v12;
        insert.elem = v11;
        parent = -1;
        leftchild = false;
        CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::FindInsertionPosition(
          this: &soundlist->m_Elements.m_Tree,
          &insert,
          &parent,
          &leftchild);
        v13 = CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::NewNode(
                this: (CUtlRBTree<CChoreoScene::ActiveList,int,bool (__cdecl*)(CChoreoScene::ActiveList const &,CChoreoScene::ActiveList const &),CUtlMemory<UtlRBTreeNode_t<CChoreoScene::ActiveList,int>,int> > *)soundlist,
                a2: (const char *)soundlist);
        v14 = parent;
        v15 = v13;
        v16 = &soundlist->m_Elements.m_Tree.m_Elements.m_pMemory[v13];
        v16->m_Parent = parent;
        v16->m_Right = -1;
        v16->m_Left = -1;
        v16->m_Tag = 0;
        if ( v14 == -1 )
        {
          soundlist->m_Elements.m_Tree.m_Root = v13;
        }
        else
        {
          v17 = v14;
          m_pMemory = soundlist->m_Elements.m_Tree.m_Elements.m_pMemory;
          if ( leftchild )
            m_pMemory[v17].m_Left = v13;
          else
            m_pMemory[v17].m_Right = v13;
        }
        CUtlRBTree<CUtlMap<char const *,CWaveFile *,int>::Node_t,int,CUtlMap<char const *,CWaveFile *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CWaveFile *,int>::Node_t,int>,int>>::InsertRebalance(
          this: &soundlist->m_Elements.m_Tree,
          elem: v13);
        v19 = soundlist->m_Elements.m_Tree.m_Elements.m_pMemory;
        ++soundlist->m_Elements.m_Tree.m_NumElements;
        p_m_Data = &v19[v15].m_Data;
        if ( p_m_Data != nullptr )
          *p_m_Data = insert;
      }
      v7 = filesystem->FindNext(this: filesystem, a2: v28);
      if ( v7 == nullptr )
        break;
      v4 = nDirectoryNameLen;
    }
  }
  m_pFileTree = v25->m_pFileTree;
  _V_strcpy(dest: dest.path, src: pDirectoryName + 6);
  if ( CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Find(
         this: &m_pFileTree->m_Paths,
         search: &dest) == -1 )
    CUtlRBTree<CWaveFileTree::FileTreePath,int,bool (__cdecl *)(CWaveFileTree::FileTreePath const &,CWaveFileTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CWaveFileTree::FileTreePath,int>,int>>::Insert(
      this: &m_pFileTree->m_Paths,
      insert: &dest);
  filesystem->FindClose(this: filesystem, a2: v28);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0048C1A0
// Name: private: bool CWaveBrowser::InitDirectoryRecursive(class CUtlDict<class CWaveFile __near *,int> __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWaveBrowser::InitDirectoryRecursive(
        CWaveBrowser *this,
        CUtlDict<CWaveFile *,int> *soundlist,
        const char *pDirectoryName)
{
  const char *v3; // esi
  int v5; // edi
  void *v7; // esp
  char *v8; // edi
  char v9; // al
  const char *(__thiscall *FindFirst)(IFileSystem *, const char *, int *); // edx
  unsigned int v11; // edi
  const char *i; // esi
  char v13; // al
  void *v14; // esp
  unsigned int v15; // eax
  char *v16; // edi
  char v17; // cl
  char v18; // [esp-1h] [ebp-19h] BYREF
  char v19[12]; // [esp+0h] [ebp-18h] BYREF
  CWaveBrowser *v20; // [esp+Ch] [ebp-Ch]
  char *pWildCard; // [esp+10h] [ebp-8h]
  int nDirectoryNameLen; // [esp+14h] [ebp-4h]

  v3 = pDirectoryName;
  v20 = this;
  v5 = _V_strlen(str: pDirectoryName);
  nDirectoryNameLen = v5;
  if ( CWaveBrowser::LoadWaveFilesInDirectory(this, soundlist, pDirectoryName: v3, nDirectoryNameLen: v5) == 0 )
    return 0;
  v7 = alloca(v5 + 4);
  pWildCard = v19;
  strcpy(v19, v3);
  v8 = &v18;
  do
    v9 = *++v8;
  while ( v9 != 0 );
  strcpy(v8, "/*.");
  FindFirst = filesystem->FindFirst;
  v11 = ++nDirectoryNameLen;
  for ( i = FindFirst(this: filesystem, a2: v19, a3: (int *)&pDirectoryName);
        i != nullptr;
        i = filesystem->FindNext(this: filesystem, a2: pDirectoryName) )
  {
    if ( *i == 46 )
    {
      v13 = i[1];
      if ( v13 == 46 || v13 == 0 )
        continue;
    }
    if ( filesystem->FindIsDirectory(this: filesystem, a2: (int)pDirectoryName) )
    {
      v14 = alloca(_V_strlen(str: i) + v11 + 1);
      memcpy(dst: (unsigned __int8 *)v19, src: (unsigned __int8 *)pWildCard, count: v11);
      v19[v11] = 0;
      v15 = strlen(i) + 1;
      v16 = &v18;
      do
        v17 = *++v16;
      while ( v17 != 0 );
      qmemcpy(v16, i, v15);
      if ( !CWaveBrowser::InitDirectoryRecursive(this: v20, soundlist, pDirectoryName: v19) )
        return 0;
      v11 = nDirectoryNameLen;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0048C300
// Name: public: CWaveBrowser::CWaveBrowser(class mxWindow __near *)
// Source: json
//------------------------------------------------------------------------------
CWaveBrowser *__thiscall CWaveBrowser::CWaveBrowser(CWaveBrowser *this, mxWindow *parent)
{
  CWaveList *v3; // eax
  CWaveList *v4; // eax
  CWaveOptionsWindow *v5; // eax
  CWaveOptionsWindow *v6; // eax
  mxTreeView *v7; // eax
  CWaveFileTree *v8; // edi

  mxWindow::mxWindow(this, parent, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
  IFacePoserToolWindow::IFacePoserToolWindow(
    this: &this->IFacePoserToolWindow,
    toolname: "WaveBrowser",
    displaynameroot: "Waves");
  this->mxWindow::mxWidget::__vftable = (CWaveBrowser_vtbl *)&CWaveBrowser::`vftable'{for `mxWindow'};
  this->IFacePoserToolWindow::__vftable = (IFacePoserToolWindow_vtbl *)&CWaveBrowser::`vftable'{for `IFacePoserToolWindow'};
  this->m_AllSounds.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_AllSounds.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_AllSounds.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_AllSounds.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_AllSounds.m_Elements.m_Tree.m_Root = -1;
  this->m_AllSounds.m_Elements.m_Tree.m_NumElements = 0;
  this->m_AllSounds.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_AllSounds.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_AllSounds.m_Elements.m_Tree.m_pElements = this->m_AllSounds.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_AllSounds.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_AllSounds.m_Elements.m_Tree.m_LessFunc.m_LessFunc = CaselessStringLessThan;
  CUtlSymbolTable::CUtlSymbolTable(this: &this->m_ScriptTable, growSize: 0, initSize: 16, caseInsensitive: false);
  this->m_Scripts.m_Memory.m_pMemory = nullptr;
  this->m_Scripts.m_Memory.m_nAllocationCount = 0;
  this->m_Scripts.m_Memory.m_nGrowSize = 0;
  this->m_Scripts.m_Size = 0;
  this->m_Scripts.m_pElements = nullptr;
  this->m_CurrentSelection.m_Memory.m_pMemory = nullptr;
  this->m_CurrentSelection.m_Memory.m_nAllocationCount = 0;
  this->m_CurrentSelection.m_Memory.m_nGrowSize = 0;
  this->m_CurrentSelection.m_Size = 0;
  this->m_CurrentSelection.m_pElements = nullptr;
  IFacePoserToolWindow::SetAutoProcess(this: &this->IFacePoserToolWindow, autoprocess: false);
  this->m_bTextSearch = false;
  this->m_nPrevProcessed = -1;
  v3 = (CWaveList *)operator new(nSize: 0xCu);
  if ( v3 != nullptr )
    v4 = CWaveList::CWaveList(this: v3, parent: this, id: 101);
  else
    v4 = nullptr;
  this->m_pListView = v4;
  v5 = (CWaveOptionsWindow *)operator new(nSize: 0x120u);
  if ( v5 != nullptr )
    v6 = CWaveOptionsWindow::CWaveOptionsWindow(this: v5, browser: this);
  else
    v6 = nullptr;
  this->m_pOptions = v6;
  v7 = (mxTreeView *)operator new(nSize: 0x30u);
  v8 = (CWaveFileTree *)v7;
  if ( v7 != nullptr )
  {
    mxTreeView::mxTreeView(this: v7, parent: this, x: 0, y: 0, w: 0, h: 0, id: 102);
    v8->__vftable = (CWaveFileTree_vtbl *)&CWaveFileTree::`vftable';
    v8->m_Paths.m_LessFunc = (bool (__cdecl *)(const CWaveFileTree::FileTreePath *, const CWaveFileTree::FileTreePath *))CUtlSymbolTree::FileTreeLessFunc;
    v8->m_Paths.m_Elements.m_pMemory = nullptr;
    v8->m_Paths.m_Elements.m_nAllocationCount = 0;
    v8->m_Paths.m_Elements.m_nGrowSize = 0;
    v8->m_Paths.m_Root = -1;
    v8->m_Paths.m_NumElements = 0;
    v8->m_Paths.m_FirstFree = -1;
    v8->m_Paths.m_LastAlloc.index = -1;
    v8->m_Paths.m_pElements = v8->m_Paths.m_Elements.m_pMemory;
  }
  else
  {
    v8 = nullptr;
  }
  this->m_pFileTree = v8;
  CWaveBrowser::RemoveAllSounds(this);
  Con_Printf(fmt: "Building list of all .wavs in sound/ folder\n");
  CWaveBrowser::InitDirectoryRecursive(this, soundlist: &this->m_AllSounds, pDirectoryName: "sound");
  CWaveFileTree::PopulateTree(this: this->m_pFileTree);
  CWaveBrowser::PopulateTree(this, subdirectory: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B45B0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 48 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: m_pMemory,
                                                                                               a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B5F00
// Name: public: int CUtlDict<struct EventGroup,int>::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<EventGroup,int>::Find(CUtlDict<EventGroup,int> *this, const char *pName)
{
  int v2; // esi
  CUtlMap<char const *,EventGroup,int>::Node_t search; // [esp+0h] [ebp-20h] BYREF

  if ( pName == nullptr )
    return -1;
  search.elem.timeSortedEvents.m_Root = -1;
  memset(&search.elem.timeSortedEvents.m_Elements, 0, sizeof(search.elem.timeSortedEvents.m_Elements));
  search.elem.timeSortedEvents.m_pElements = nullptr;
  search.elem.timeSortedEvents.m_NumElements = 0;
  search.elem.timeSortedEvents.m_LessFunc = ChoreEventStartTimeLessFunc;
  search.elem.timeSortedEvents.m_FirstFree = -1;
  search.elem.timeSortedEvents.m_LastAlloc.index = -1;
  search.key = pName;
  v2 = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Find(
         this: &this->m_Elements.m_Tree,
         &search);
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: &search.elem.timeSortedEvents);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004B60B0
// Name: public: void CUtlDict<struct EventGroup,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<EventGroup,int>::RemoveAll(CUtlDict<EventGroup,int> *this)
{
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *i; // esi

  for ( i = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        i = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              (int)i) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[(_DWORD)i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x004B6100
// Name: public: int CUtlDict<struct EventGroup,int>::Insert(char const __near *,struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<EventGroup,int>::Insert(
        CUtlDict<EventGroup,int> *this,
        const char *pName,
        const EventGroup *element)
{
  char *v3; // eax
  int v4; // esi
  CUtlMap<char const *,EventGroup,int>::Node_t insert; // [esp+Ch] [ebp-24h] BYREF
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *p_m_Tree; // [esp+2Ch] [ebp-4h]

  p_m_Tree = &this->m_Elements.m_Tree;
  if ( pName != nullptr && (v3 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v3, pName);
  else
    v3 = nullptr;
  insert.key = v3;
  insert.elem.timeSortedEvents.m_LessFunc = ChoreEventStartTimeLessFunc;
  memset(&insert.elem.timeSortedEvents.m_Elements, 0, sizeof(insert.elem.timeSortedEvents.m_Elements));
  *(_DWORD *)&insert.elem.timeSortedEvents.m_Root = 0xFFFF;
  *(_DWORD *)&insert.elem.timeSortedEvents.m_FirstFree = -1;
  insert.elem.timeSortedEvents.m_pElements = nullptr;
  EventGroup::operator=(this: &insert.elem, src: element);
  v4 = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Insert(
         this: p_m_Tree,
         a2: pName,
         &insert);
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: &insert.elem.timeSortedEvents);
  return v4;
}
