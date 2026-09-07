// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/closecaptiontool.cpp
// Functions: 18
// ============================================================

#include "utils\hlfaceposer\closecaptiontool.h"

//------------------------------------------------------------------------------
// Address: 0x00439B60
// Name: public: void CCloseCaptionWorkUnit::SetStream(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCloseCaptionWorkUnit::SetStream(CCloseCaptionWorkUnit *this, const wchar_t *stream)
{
  unsigned int v3; // esi
  wchar_t *v4; // eax

  free(pMem: this->m_pszStream);
  this->m_pszStream = nullptr;
  v3 = wcslen(stream);
  v4 = (wchar_t *)operator new(nSize: 2 * (v3 + 1));
  this->m_pszStream = v4;
  wcsncpy(dest: v4, source: stream, count: v3);
  this->m_pszStream[v3] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00439BD0
// Name: public: virtual int CloseCaptionTool::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CloseCaptionTool::handleEvent(CloseCaptionTool *this, mxEvent *event)
{
  this->HandleToolEvent(this: &this->IFacePoserToolWindow, a2: event);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00439BF0
// Name: public: virtual bool CloseCaptionTool::LookupUnicodeText(int,char const __near *,wchar_t __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CloseCaptionTool::LookupUnicodeText(
        CloseCaptionTool *this,
        int languageId,
        const char *token,
        wchar_t *outbuf,
        unsigned int count)
{
  const wchar_t *v5; // eax

  v5 = g_pLocalize->Find(this: g_pLocalize, a2: token);
  if ( v5 != nullptr )
  {
    wcsncpy(dest: outbuf, source: v5, count);
    return 1;
  }
  else
  {
    wcsncpy(dest: outbuf, source: L"<can't find entry>", count);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439C40
// Name: private: bool CloseCaptionTool::SplitCommand(wchar_t const __near * __near *,wchar_t __near *,wchar_t __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CloseCaptionTool::SplitCommand(
        CloseCaptionTool *this,
        const wchar_t **ppIn,
        wchar_t *cmd,
        wchar_t *args)
{
  const wchar_t **v4; // edx
  const wchar_t *v5; // esi
  wchar_t *v7; // edi
  wchar_t *v8; // esi
  wchar_t v9; // ax
  wchar_t v10; // ax
  wchar_t v11; // ax
  wchar_t *v12; // ecx
  const wchar_t *oldin; // [esp+4h] [ebp-4h]

  v4 = ppIn;
  v5 = *ppIn;
  oldin = *ppIn;
  if ( **ppIn != 60 )
    return 0;
  v7 = cmd;
  *args = 0;
  v8 = (wchar_t *)(v5 + 1);
  *cmd = 0;
  v9 = *v8;
  if ( *v8 != 0 )
  {
    while ( v9 != 58 && v9 != 62 )
    {
      if ( isspace(c: v9) != 0 || (v10 = *v8, ++v8, *v7 = v10, v9 = *v8, ++v7, *v8 == 0) )
      {
        v4 = ppIn;
        break;
      }
      v4 = ppIn;
    }
  }
  *v7 = 0;
  if ( *v8 == 58 )
  {
    v11 = v8[1];
    ++v8;
    v12 = args;
    if ( v11 != 0 )
    {
      do
      {
        if ( v11 == 62 )
          break;
        ++v8;
        *v12 = v11;
        v11 = *v8;
        ++v12;
      }
      while ( *v8 != 0 );
    }
    *v12 = 0;
  }
  *v4 += v8 - oldin;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00439D00
// Name: public: void WorkUnitParams::Next(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall WorkUnitParams::Next(WorkUnitParams *this)
{
  bool v2; // zf

  _V_memset(dest: this, fill: 0, count: 2048);
  this->x += this->width;
  v2 = !this->newline;
  this->out = (wchar_t *)this;
  this->width = 0;
  if ( !v2 )
  {
    this->y += 14;
    this->newline = false;
    this->x = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439D60
// Name: public: virtual bool CloseCaptionTool::LookupStrippedUnicodeText(int,char const __near *,wchar_t __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CloseCaptionTool::LookupStrippedUnicodeText(
        CloseCaptionTool *this,
        int languageId,
        const char *token,
        wchar_t *outbuf,
        unsigned int count)
{
  const char *v5; // eax
  unsigned int v7; // ebx
  wchar_t *v8; // esi
  unsigned int v9; // edi
  bool v10; // zf
  const char *v11; // eax
  wchar_t cmd[256]; // [esp+0h] [ebp-404h] BYREF
  wchar_t args[256]; // [esp+200h] [ebp-204h] BYREF
  CloseCaptionTool *v14; // [esp+400h] [ebp-4h]

  v14 = this;
  v5 = (const char *)g_pLocalize->Find(this: g_pLocalize, a2: token);
  if ( v5 != nullptr )
  {
    v7 = count;
    v8 = outbuf;
    token = v5;
    v9 = 0;
    do
    {
      if ( *(_WORD *)v5 == 0 || v9 >= v7 )
        break;
      v10 = CloseCaptionTool::SplitCommand(
              this: (CloseCaptionTool *)((char *)v14 - 632),
              ppIn: (const wchar_t **)&token,
              cmd,
              args) == 0;
      v11 = token;
      if ( v10 )
      {
        *v8++ = *(_WORD *)token;
        ++v9;
      }
      v10 = v11 + 2 == nullptr;
      v5 = v11 + 2;
      token = v5;
    }
    while ( !v10 );
    *v8 = 0;
    return 1;
  }
  else
  {
    wcsncpy(dest: outbuf, source: L"<can't find entry>", count);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439E10
// Name: private: void CloseCaptionTool::DrawStream(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &,class CCloseCaptionItem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CloseCaptionTool::DrawStream(
        CloseCaptionTool *this,
        CChoreoWidgetDrawHelper *helper,
        tagRECT *rcText,
        CCloseCaptionItem *item)
{
  int m_Size; // eax
  int left; // ecx
  CCloseCaptionWorkUnit *v6; // esi
  bool m_bItalic; // al
  int v8; // eax
  HFONT__ *v9; // edi
  int m_nY; // edx
  int v11; // ecx
  int v12; // eax
  bool v13; // zf
  char *m_pszStream; // eax
  tagRECT rcOut; // [esp+4h] [ebp-24h] BYREF
  int c; // [esp+14h] [ebp-14h]
  CloseCaptionTool *v17; // [esp+18h] [ebp-10h]
  Color useColor; // [esp+1Ch] [ebp-Ch] BYREF
  int i; // [esp+20h] [ebp-8h]
  Color clr; // [esp+24h] [ebp-4h] BYREF

  m_Size = item->m_Work.m_Size;
  v17 = this;
  left = rcText->left;
  c = m_Size;
  rcOut.left = left;
  for ( i = 0; i < c; ++i )
  {
    v6 = item->m_Work.m_Memory.m_pMemory[i];
    m_bItalic = v6->m_bItalic;
    if ( v6->m_bBold )
      v8 = m_bItalic + 2;
    else
      v8 = m_bItalic;
    v9 = v17->m_hFonts[v8];
    m_nY = v6->m_nY;
    rcOut.left = v6->m_nX + rcText->left;
    v11 = rcOut.left + v6->m_nWidth;
    v12 = m_nY + rcText->top;
    rcOut.right = v11;
    rcOut.top = v12;
    rcOut.bottom = v12 + v6->m_nHeight;
    v13 = !item->m_bValid;
    useColor = v6->m_Color;
    if ( v13 )
    {
      rcOut.right = v11 + 2;
      useColor = (Color)0xFFFFFF;
      strcpy((char *)&clr, "dd(");
      CChoreoWidgetDrawHelper::DrawFilledRect(this: helper, &clr, rc: &rcOut);
    }
    m_pszStream = (char *)v6->m_pszStream;
    if ( m_pszStream == nullptr )
      m_pszStream = &byte_4F1FE4;
    CChoreoWidgetDrawHelper::DrawColoredTextW(
      this: helper,
      font: v9,
      clr: &useColor,
      rcText: &rcOut,
      fmt: L"%s",
      m_pszStream);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439F20
// Name: public: CCloseCaptionItem::CCloseCaptionItem(wchar_t __near *,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
CCloseCaptionItem *__thiscall CCloseCaptionItem::CCloseCaptionItem(
        CCloseCaptionItem *this,
        wchar_t *stream,
        float timetolive,
        float predisplay,
        bool valid)
{
  this->m_flTimeToLive = 0.0;
  this->m_bValid = false;
  this->m_nTotalWidth = 0;
  this->m_nTotalHeight = 0;
  this->m_bSizeComputed = false;
  this->m_Work.m_Memory.m_pMemory = nullptr;
  this->m_Work.m_Memory.m_nAllocationCount = 0;
  this->m_Work.m_Memory.m_nGrowSize = 0;
  this->m_Work.m_Size = 0;
  this->m_Work.m_pElements = nullptr;
  wcsncpy(dest: this->m_szStream, source: stream, count: 0x100u);
  this->m_flTimeToLive = timetolive;
  this->m_bSizeComputed = false;
  this->m_flPreDisplayTime = predisplay;
  this->m_bValid = valid;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00439FB0
// Name: public: CCloseCaptionItem::~CCloseCaptionItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCloseCaptionItem::~CCloseCaptionItem(CCloseCaptionItem *this)
{
  CCloseCaptionWorkUnit *v2; // edi

  while ( this->m_Work.m_Size > 0 )
  {
    v2 = *this->m_Work.m_Memory.m_pMemory;
    if ( this->m_Work.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_Work.m_Memory.m_pMemory,
        src: this->m_Work.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_Work.m_Size - 1));
    --this->m_Work.m_Size;
    if ( v2 != nullptr )
    {
      free(pMem: v2->m_pszStream);
      v2->m_pszStream = nullptr;
      free(pMem: v2);
    }
  }
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Work);
}

//------------------------------------------------------------------------------
// Address: 0x0043A030
// Name: public: CloseCaptionTool::CloseCaptionTool(class mxWindow __near *)
// Source: json
//------------------------------------------------------------------------------
CloseCaptionTool *__thiscall CloseCaptionTool::CloseCaptionTool(CloseCaptionTool *this, mxWindow *parent)
{
  mxWindow::mxWindow(this, parent, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
  IFacePoserToolWindow::IFacePoserToolWindow(
    this: &this->IFacePoserToolWindow,
    toolname: "CloseCaptionTool",
    displaynameroot: "Close Caption");
  this->ICloseCaptionManager::__vftable = (ICloseCaptionManager_vtbl *)&ICloseCaptionManager::`vftable';
  this->mxWindow::mxWidget::__vftable = (CloseCaptionTool_vtbl *)&CloseCaptionTool::`vftable'{for `mxWindow'};
  this->IFacePoserToolWindow::__vftable = (IFacePoserToolWindow_vtbl *)&CloseCaptionTool::`vftable'{for `IFacePoserToolWindow'};
  this->ICloseCaptionManager::__vftable = (ICloseCaptionManager_vtbl *)&CloseCaptionTool::`vftable'{for `ICloseCaptionManager'};
  this->m_Items.m_Memory.m_pMemory = nullptr;
  this->m_Items.m_Memory.m_nAllocationCount = 0;
  this->m_Items.m_Memory.m_nGrowSize = 0;
  this->m_Items.m_Size = 0;
  this->m_Items.m_pElements = nullptr;
  this->m_nLastItemCount = -1;
  closecaptionmanager = &this->ICloseCaptionManager;
  this->m_hFonts[0] = CreateFontA(
                        cHeight: -12,
                        cWidth: 0,
                        cEscapement: 0,
                        cOrientation: 0,
                        cWeight: 400,
                        bItalic: 0,
                        bUnderline: 0,
                        bStrikeOut: 0,
                        iCharSet: 1u,
                        iOutPrecision: 4u,
                        iClipPrecision: 0,
                        iQuality: 4u,
                        iPitchAndFamily: 0,
                        pszFaceName: "Tahoma");
  this->m_hFonts[1] = CreateFontA(
                        cHeight: -12,
                        cWidth: 0,
                        cEscapement: 0,
                        cOrientation: 0,
                        cWeight: 400,
                        bItalic: 1u,
                        bUnderline: 0,
                        bStrikeOut: 0,
                        iCharSet: 1u,
                        iOutPrecision: 4u,
                        iClipPrecision: 0,
                        iQuality: 4u,
                        iPitchAndFamily: 0,
                        pszFaceName: "Tahoma");
  this->m_hFonts[2] = CreateFontA(
                        cHeight: -12,
                        cWidth: 0,
                        cEscapement: 0,
                        cOrientation: 0,
                        cWeight: 700,
                        bItalic: 0,
                        bUnderline: 0,
                        bStrikeOut: 0,
                        iCharSet: 1u,
                        iOutPrecision: 4u,
                        iClipPrecision: 0,
                        iQuality: 4u,
                        iPitchAndFamily: 0,
                        pszFaceName: "Tahoma");
  this->m_hFonts[3] = CreateFontA(
                        cHeight: -12,
                        cWidth: 0,
                        cEscapement: 0,
                        cOrientation: 0,
                        cWeight: 700,
                        bItalic: 1u,
                        bUnderline: 0,
                        bStrikeOut: 0,
                        iCharSet: 1u,
                        iOutPrecision: 4u,
                        iClipPrecision: 0,
                        iQuality: 4u,
                        iPitchAndFamily: 0,
                        pszFaceName: "Tahoma");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043A160
// Name: public: virtual void CloseCaptionTool::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CloseCaptionTool::Reset(CloseCaptionTool *this)
{
  CCloseCaptionItem **d_this; // eax
  CCloseCaptionItem *v3; // edi

  for ( ; *(int *)this->m_szToolName > 0; --*(_DWORD *)this->m_szToolName )
  {
    d_this = (CCloseCaptionItem **)this->mxWindow::mxWidget::d_this;
    v3 = *d_this;
    if ( *d_this != nullptr )
    {
      CCloseCaptionItem::~CCloseCaptionItem(this: *d_this);
      free(pMem: v3);
    }
    if ( *(_DWORD *)this->m_szToolName - 1 > 0 )
      _V_memmove(
        dest: this->mxWindow::mxWidget::d_this,
        src: &this->mxWindow::mxWidget::d_this->d_hwnd,
        count: 4 * (*(_DWORD *)this->m_szToolName - 1));
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A1C0
// Name: public: void CCloseCaptionItem::AddWork(class CCloseCaptionWorkUnit __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCloseCaptionItem::AddWork(CCloseCaptionItem *this, CUtlSymbolTable::StringPool_t *unit)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Work; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_Work.m_Memory.m_nAllocationCount;
  p_m_Work = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Work;
  m_Size = this->m_Work.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IFacePoserToolWindow *,int>::Grow(this: p_m_Work, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Work[1].m_pMemory;
  m_pMemory = p_m_Work->m_pMemory;
  v6 = (int)p_m_Work[1].m_pMemory - m_Size - 1;
  p_m_Work[1].m_nAllocationCount = (int)p_m_Work->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_Work->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = unit;
}

//------------------------------------------------------------------------------
// Address: 0x0043A280
// Name: public: virtual void CloseCaptionTool::Think(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CloseCaptionTool::Think(CloseCaptionTool *this, float dt)
{
  int m_pMemory; // edx
  int v4; // eax
  int v5; // ecx
  float v6; // xmm1_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  int v9; // ecx
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  int v13; // ecx
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  int v17; // ecx
  float v18; // xmm1_4
  float v19; // xmm1_4
  float v20; // xmm1_4
  int v21; // ecx
  float v22; // xmm1_4
  float v23; // xmm1_4
  float v24; // xmm1_4
  int v25; // edi
  CCloseCaptionItem *v26; // ebx
  HFONT__ *v27; // ecx
  int c; // [esp+0h] [ebp-4h]
  char foundfirstnondeletion_3; // [esp+Fh] [ebp+Bh]

  m_pMemory = (int)this->m_Items.m_Memory.m_pMemory;
  v4 = 0;
  c = m_pMemory;
  if ( m_pMemory >= 4 )
  {
    do
    {
      v5 = *(_DWORD *)(*(_DWORD *)&this->m_bUseForMainWindowTitle + 4 * v4);
      v6 = *(float *)(v5 + 512);
      if ( v6 <= 0.0 )
      {
        v8 = *(float *)(v5 + 516) - dt;
        if ( v8 < 0.0 )
          v8 = 0.0;
        *(float *)(v5 + 516) = v8;
      }
      else
      {
        v7 = v6 - dt;
        if ( v7 < 0.0 )
          v7 = 0.0;
        *(float *)(v5 + 512) = v7;
      }
      v9 = *(_DWORD *)(*(_DWORD *)&this->m_bUseForMainWindowTitle + 4 * v4 + 4);
      v10 = *(float *)(v9 + 512);
      if ( v10 <= 0.0 )
      {
        v12 = *(float *)(v9 + 516) - dt;
        if ( v12 < 0.0 )
          v12 = 0.0;
        *(float *)(v9 + 516) = v12;
      }
      else
      {
        v11 = v10 - dt;
        if ( v11 < 0.0 )
          v11 = 0.0;
        *(float *)(v9 + 512) = v11;
      }
      v13 = *(_DWORD *)(*(_DWORD *)&this->m_bUseForMainWindowTitle + 4 * v4 + 8);
      v14 = *(float *)(v13 + 512);
      if ( v14 <= 0.0 )
      {
        v16 = *(float *)(v13 + 516) - dt;
        if ( v16 < 0.0 )
          v16 = 0.0;
        *(float *)(v13 + 516) = v16;
      }
      else
      {
        v15 = v14 - dt;
        if ( v15 < 0.0 )
          v15 = 0.0;
        *(float *)(v13 + 512) = v15;
      }
      v17 = *(_DWORD *)(*(_DWORD *)&this->m_bUseForMainWindowTitle + 4 * v4 + 12);
      v18 = *(float *)(v17 + 512);
      if ( v18 <= 0.0 )
      {
        v20 = *(float *)(v17 + 516) - dt;
        if ( v20 < 0.0 )
          v20 = 0.0;
        *(float *)(v17 + 516) = v20;
      }
      else
      {
        v19 = v18 - dt;
        if ( v19 < 0.0 )
          v19 = 0.0;
        *(float *)(v17 + 512) = v19;
      }
      v4 += 4;
    }
    while ( v4 < m_pMemory - 3 );
  }
  for ( ; v4 < m_pMemory; ++v4 )
  {
    v21 = *(_DWORD *)(*(_DWORD *)&this->m_bUseForMainWindowTitle + 4 * v4);
    v22 = *(float *)(v21 + 512);
    if ( v22 <= 0.0 )
    {
      v24 = *(float *)(v21 + 516) - dt;
      if ( v24 < 0.0 )
        v24 = 0.0;
      *(float *)(v21 + 516) = v24;
    }
    else
    {
      v23 = v22 - dt;
      if ( v23 < 0.0 )
        v23 = 0.0;
      *(float *)(v21 + 512) = v23;
    }
  }
  v25 = 0;
  for ( foundfirstnondeletion_3 = 0; v25 < m_pMemory; ++v25 )
  {
    v26 = *(CCloseCaptionItem **)(*(_DWORD *)&this->m_bUseForMainWindowTitle + 4 * v25);
    if ( v26->m_flPreDisplayTime <= 0.0 )
    {
      if ( v26->m_flTimeToLive <= 0.0 )
      {
        if ( foundfirstnondeletion_3 == 0 )
        {
          CCloseCaptionItem::~CCloseCaptionItem(this: v26);
          free(pMem: v26);
          if ( (int)this->m_Items.m_Memory.m_pMemory - v25 - 1 > 0 )
            _V_memmove(
              dest: (void *)(*(_DWORD *)&this->m_bUseForMainWindowTitle + 4 * v25),
              src: (const void *)(*(_DWORD *)&this->m_bUseForMainWindowTitle + 4 * v25 + 4),
              count: 4 * ((int)this->m_Items.m_Memory.m_pMemory - v25 - 1));
          --this->m_Items.m_Memory.m_pMemory;
          --v25;
          m_pMemory = --c;
        }
      }
      else
      {
        foundfirstnondeletion_3 = 1;
      }
    }
  }
  v27 = (HFONT__ *)this->m_Items.m_Memory.m_pMemory;
  if ( v27 == this->m_hFonts[1] )
  {
    this->m_hFonts[1] = v27;
  }
  else
  {
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 3) + 16))(a1: (char *)this - 12);
    this->m_hFonts[1] = (HFONT__ *)this->m_Items.m_Memory.m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A500
// Name: public: virtual void CloseCaptionTool::Process(char const __near *,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CloseCaptionTool::Process(CloseCaptionTool *this, wchar_t *tokenname, float duration, float languageid)
{
  const char *v4; // edi
  CloseCaptionTool *v5; // ebx
  void (__thiscall *OnDelete)(struct CloseCaptionTool *); // eax
  ILocalize_vtbl *v7; // esi
  char *v8; // eax
  wchar_t *v9; // esi
  CCloseCaptionItem *v10; // eax
  CCloseCaptionItem *v11; // ebx
  _DWORD *v12; // esi
  int v13; // edi
  mxWindow_i *d_this; // eax
  int v15; // ecx
  int v16; // eax
  CCloseCaptionItem **v17; // eax
  CCloseCaptionItem *v18; // eax
  CCloseCaptionItem *v19; // ebx
  _DWORD *v20; // esi
  int v21; // edi
  mxWindow_i *v22; // eax
  int v23; // ecx
  int v24; // eax
  CCloseCaptionItem **v25; // eax
  wchar_t phrase[1024]; // [esp+34h] [ebp-E0Ch] BYREF
  wchar_t cmd[256]; // [esp+834h] [ebp-60Ch] BYREF
  wchar_t args[256]; // [esp+A34h] [ebp-40Ch] BYREF
  wchar_t stream[258]; // [esp+C34h] [ebp-20Ch] BYREF
  CloseCaptionTool *v30; // [esp+E38h] [ebp-8h]
  BOOL valid; // [esp+E3Ch] [ebp-4h]

  v4 = (const char *)tokenname;
  v5 = this;
  OnDelete = this->OnDelete;
  v30 = this;
  LOBYTE(valid) = 1;
  if ( ((unsigned __int8 (__stdcall *)(_DWORD, wchar_t *, wchar_t *, int))OnDelete)(
         a1: LODWORD(languageid),
         a2: tokenname,
         a3: stream,
         a4: 256) == 0 )
  {
    v7 = g_pLocalize->__vftable;
    LOBYTE(valid) = 0;
    v8 = va(fmt: "--> Missing Caption[%s]", v4);
    v7->ConvertANSIToUnicode(this: g_pLocalize, a2: v8, a3: stream, a4: 512);
  }
  if ( wcsncmp(first: stream, last: L"!!!", count: 3u) == 0 )
    LOBYTE(valid) = 0;
  if ( wcslen(stream) != 0 )
  {
    languageid = 0.0;
    v9 = phrase;
    tokenname = stream;
    while ( *tokenname != 0 )
    {
      if ( CloseCaptionTool::SplitCommand(
             this: (CloseCaptionTool *)((char *)v5 - 632),
             ppIn: (const wchar_t **)&tokenname,
             cmd,
             args) != 0
        && wcscmp(cmd, L"delay") == 0 )
      {
        *v9 = 0;
        if ( wcslen(phrase) != 0 )
        {
          v10 = (CCloseCaptionItem *)operator new(nSize: 0x22Cu);
          if ( v10 != nullptr )
            v11 = CCloseCaptionItem::CCloseCaptionItem(
                    this: v10,
                    stream: phrase,
                    timetolive: duration + 1.5,
                    predisplay: languageid,
                    valid);
          else
            v11 = nullptr;
          v12 = &v30->mxWindow::mxWidget::__vftable;
          v13 = *(_DWORD *)v30->m_szToolName;
          d_this = v30->mxWindow::d_this;
          if ( v13 + 1 > (int)d_this )
            CUtlMemory<IFacePoserToolWindow *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v30->mxWindow::mxWidget::d_this,
              num: v13 - (_DWORD)d_this + 1);
          ++v12[4];
          v15 = v12[1];
          v16 = v12[4] - v13 - 1;
          v12[5] = v15;
          if ( v16 > 0 )
            _V_memmove(dest: (void *)(v15 + 4 * v13 + 4), src: (const void *)(v15 + 4 * v13), count: 4 * v16);
          v17 = (CCloseCaptionItem **)(v12[1] + 4 * v13);
          if ( v17 != nullptr )
            *v17 = v11;
        }
        v9 = phrase;
        languageid = wcstod(nptr: args, endptr: nullptr) >= 0.0 ? wcstod(nptr: args, endptr: nullptr) : 0.0;
      }
      else
      {
        *v9++ = *tokenname;
      }
      if ( ++tokenname == nullptr )
        break;
      v5 = v30;
    }
    *v9 = 0;
    if ( wcslen(phrase) != 0 )
    {
      v18 = (CCloseCaptionItem *)operator new(nSize: 0x22Cu);
      if ( v18 != nullptr )
        v19 = CCloseCaptionItem::CCloseCaptionItem(
                this: v18,
                stream: phrase,
                timetolive: duration + 1.5,
                predisplay: languageid,
                valid);
      else
        v19 = nullptr;
      v20 = &v30->mxWindow::mxWidget::__vftable;
      v21 = *(_DWORD *)v30->m_szToolName;
      v22 = v30->mxWindow::d_this;
      if ( v21 + 1 > (int)v22 )
        CUtlMemory<IFacePoserToolWindow *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v30->mxWindow::mxWidget::d_this,
          num: v21 - (_DWORD)v22 + 1);
      ++v20[4];
      v23 = v20[1];
      v24 = v20[4] - v21 - 1;
      v20[5] = v23;
      if ( v24 > 0 )
        _V_memmove(dest: (void *)(v23 + 4 * v21 + 4), src: (const void *)(v23 + 4 * v21), count: 4 * v24);
      v25 = (CCloseCaptionItem **)(v20[1] + 4 * v21);
      if ( v25 != nullptr )
        *v25 = v19;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A810
// Name: private: void CloseCaptionTool::AddWorkUnit(class CCloseCaptionItem __near *,struct WorkUnitParams __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CloseCaptionTool::AddWorkUnit(CloseCaptionTool *this, CCloseCaptionItem *item, WorkUnitParams *params)
{
  CCloseCaptionWorkUnit *v3; // eax
  CCloseCaptionWorkUnit *v4; // edi
  int y; // eax
  int m_nTotalHeight; // eax
  int m_nTotalWidth; // edx

  *params->out = 0;
  if ( wcslen(params->stream) != 0 )
  {
    v3 = (CCloseCaptionWorkUnit *)operator new(nSize: 0x1Cu);
    if ( v3 != nullptr )
    {
      v3->m_nWidth = 0;
      v3->m_nHeight = 0;
      *(_WORD *)&v3->m_bBold = 0;
      v3->m_pszStream = nullptr;
      v3->m_Color = (Color)0xFFFFFF;
      v4 = v3;
    }
    else
    {
      v4 = nullptr;
    }
    CCloseCaptionWorkUnit::SetStream(this: v4, stream: params->stream);
    v4->m_Color = params->clr;
    v4->m_bBold = params->bold;
    v4->m_bItalic = params->italic;
    v4->m_nWidth = params->width;
    v4->m_nHeight = 14;
    y = params->y;
    v4->m_nX = params->x;
    v4->m_nY = y;
    m_nTotalHeight = item->m_nTotalHeight;
    if ( m_nTotalHeight <= params->y + 14 )
      m_nTotalHeight = params->y + 14;
    m_nTotalWidth = item->m_nTotalWidth;
    if ( m_nTotalWidth <= params->width + params->x )
      m_nTotalWidth = params->width + params->x;
    item->m_nTotalHeight = m_nTotalHeight;
    item->m_nTotalWidth = m_nTotalWidth;
    CCloseCaptionItem::AddWork(this: item, unit: (CUtlSymbolTable::StringPool_t *)v4);
    WorkUnitParams::Next(this: params);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A910
// Name: private: void CloseCaptionTool::ComputeStreamWork(class CChoreoWidgetDrawHelper __near &,int,class CCloseCaptionItem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CloseCaptionTool::ComputeStreamWork(
        CloseCaptionTool *this,
        CChoreoWidgetDrawHelper *helper,
        int available_width,
        CCloseCaptionItem *item)
{
  CCloseCaptionItem *v4; // esi
  int m_Size; // edi
  int v6; // esi
  Color *m_pMemory; // ecx
  int v8; // eax
  Color *v9; // eax
  int v10; // esi
  Color *v11; // ecx
  int v12; // eax
  Color *v13; // eax
  int italic; // eax
  int v15; // esi
  wchar_t args[256]; // [esp+Ch] [ebp-C60h] BYREF
  wchar_t cmd[256]; // [esp+20Ch] [ebp-A60h] BYREF
  WorkUnitParams params; // [esp+40Ch] [ebp-860h] BYREF
  int pr; // [esp+C24h] [ebp-48h] BYREF
  int pb; // [esp+C28h] [ebp-44h] BYREF
  int pg; // [esp+C2Ch] [ebp-40h] BYREF
  int b; // [esp+C30h] [ebp-3Ch] BYREF
  int nr; // [esp+C34h] [ebp-38h] BYREF
  int nb; // [esp+C38h] [ebp-34h] BYREF
  int g; // [esp+C3Ch] [ebp-30h] BYREF
  int r; // [esp+C40h] [ebp-2Ch] BYREF
  int ng; // [esp+C44h] [ebp-28h] BYREF
  Color v28; // [esp+C48h] [ebp-24h]
  Color v29; // [esp+C4Ch] [ebp-20h]
  CUtlVector<Color,CUtlMemory<Color,int> > colorStack; // [esp+C50h] [ebp-1Ch] BYREF
  CloseCaptionTool *v31; // [esp+C64h] [ebp-8h]
  const wchar_t *curpos; // [esp+C68h] [ebp-4h] BYREF

  v31 = this;
  params.clr = 0;
  _V_memset(dest: &params, fill: 0, count: 2048);
  v4 = item;
  m_Size = 0;
  params.out = (wchar_t *)&params;
  memset(&params.x, 0, 14);
  params.clr = (Color)0xFFFFFF;
  params.newline = false;
  curpos = (const wchar_t *)item;
  memset(&colorStack, 0, sizeof(colorStack));
  if ( item != nullptr )
  {
    do
    {
      if ( *curpos == 0 )
        break;
      if ( CloseCaptionTool::SplitCommand(this: v31, ppIn: &curpos, cmd, args) == 0 )
      {
        if ( params.bold )
          italic = params.italic + 2;
        else
          italic = params.italic;
        v15 = CChoreoWidgetDrawHelper::CalcTextWidthW(fnt: v31->m_hFonts[italic], fmt: L"%c", *curpos);
        if ( v15 + params.x + params.width > available_width )
        {
          params.newline = true;
          CloseCaptionTool::AddWorkUnit(this: v31, item, &params);
        }
        *params.out++ = *curpos;
        params.width += v15;
        goto LABEL_39;
      }
      if ( wcscmp(cmd, L"cr") == 0 )
      {
        params.newline = true;
        CloseCaptionTool::AddWorkUnit(this: v31, item: v4, &params);
      }
      else if ( wcscmp(cmd, L"clr") == 0 )
      {
        CloseCaptionTool::AddWorkUnit(this: v31, item: v4, &params);
        if ( args[0] == 0 && m_Size >= 2 )
          goto LABEL_9;
        if ( swscanf(string: args, format: L"%i,%i,%i", &r, &g, &b) == 3 )
        {
          v29._color[0] = r;
          v29._color[1] = g;
          *(_WORD *)&v29._color[2] = (unsigned __int8)b;
          v6 = m_Size;
          if ( m_Size + 1 > colorStack.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IFacePoserToolWindow *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&colorStack,
              num: m_Size - colorStack.m_Memory.m_nAllocationCount + 1);
            m_Size = colorStack.m_Size;
          }
          m_pMemory = colorStack.m_Memory.m_pMemory;
          v8 = ++m_Size - v6 - 1;
          colorStack.m_Size = m_Size;
          colorStack.m_pElements = colorStack.m_Memory.m_pMemory;
          if ( v8 > 0 )
          {
            _V_memmove(
              dest: &colorStack.m_Memory.m_pMemory[v6 + 1],
              src: &colorStack.m_Memory.m_pMemory[v6],
              count: 4 * v8);
            m_pMemory = colorStack.m_Memory.m_pMemory;
          }
          v9 = &m_pMemory[v6];
          if ( v9 != nullptr )
            *v9 = v29;
          params.clr = m_pMemory[m_Size - 1];
LABEL_39:
          v4 = item;
        }
      }
      else
      {
        if ( wcscmp(cmd, L"playerclr") != 0 )
        {
          if ( wcscmp(cmd, L"I") == 0 )
          {
            CloseCaptionTool::AddWorkUnit(this: v31, item: v4, &params);
            params.italic = !params.italic;
          }
          else if ( wcscmp(cmd, L"B") == 0 )
          {
            CloseCaptionTool::AddWorkUnit(this: v31, item: v4, &params);
            params.bold = !params.bold;
          }
          goto LABEL_40;
        }
        CloseCaptionTool::AddWorkUnit(this: v31, item: v4, &params);
        if ( args[0] == 0 && m_Size >= 2 )
        {
LABEL_9:
          CUtlVector<Color,CUtlMemory<Color,int>>::Remove(
            this: (CUtlVector<CPhonemeTag *,CUtlMemory<CPhonemeTag *,int> > *)&colorStack,
            elem: m_Size - 1);
          m_Size = colorStack.m_Size;
          params.clr = colorStack.m_Memory.m_pMemory[colorStack.m_Size - 1];
          goto LABEL_40;
        }
        if ( swscanf(string: args, format: L"%i,%i,%i:%i,%i,%i", &pr, &pg, &pb, &nr, &ng, &nb) == 6 )
        {
          v28._color[0] = nr;
          v28._color[1] = ng;
          *(_WORD *)&v28._color[2] = (unsigned __int8)nb;
          v10 = m_Size;
          if ( m_Size + 1 > colorStack.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IFacePoserToolWindow *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&colorStack,
              num: m_Size - colorStack.m_Memory.m_nAllocationCount + 1);
            m_Size = colorStack.m_Size;
          }
          v11 = colorStack.m_Memory.m_pMemory;
          v12 = ++m_Size - v10 - 1;
          colorStack.m_Size = m_Size;
          colorStack.m_pElements = colorStack.m_Memory.m_pMemory;
          if ( v12 > 0 )
          {
            _V_memmove(
              dest: &colorStack.m_Memory.m_pMemory[v10 + 1],
              src: &colorStack.m_Memory.m_pMemory[v10],
              count: 4 * v12);
            v11 = colorStack.m_Memory.m_pMemory;
          }
          v13 = &v11[v10];
          if ( v13 != nullptr )
            *v13 = v28;
          params.clr = v11[m_Size - 1];
          goto LABEL_39;
        }
      }
LABEL_40:
      ++curpos;
    }
    while ( curpos != nullptr );
  }
  params.newline = true;
  CloseCaptionTool::AddWorkUnit(this: v31, item: v4, &params);
  v4->m_bSizeComputed = true;
  if ( colorStack.m_Memory.m_nGrowSize >= 0 && colorStack.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: colorStack.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0043ADC0
// Name: public: virtual void CloseCaptionTool::redraw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CloseCaptionTool::redraw(CloseCaptionTool *this)
{
  CloseCaptionTool *v1; // edi
  int v2; // esi
  int v3; // ecx
  int m_Size; // edx
  VisibleStreamItem *m_pMemory; // ebx
  int v6; // eax
  CCloseCaptionItem *v7; // eax
  float m_flPreDisplayTime; // xmm0_4
  int m_nTotalHeight; // eax
  int v10; // edi
  VisibleStreamItem *v11; // edi
  CCloseCaptionItem *v12; // ecx
  int top; // eax
  int v14; // edi
  CCloseCaptionItem *v15; // ecx
  CChoreoWidgetDrawHelper drawHelper; // [esp+8h] [ebp-A8h] BYREF
  tagRECT rcOutput; // [esp+60h] [ebp-50h] BYREF
  int avail_width; // [esp+70h] [ebp-40h]
  int itemheight; // [esp+74h] [ebp-3Ch]
  CUtlVector<VisibleStreamItem,CUtlMemory<VisibleStreamItem,int> > visibleitems; // [esp+78h] [ebp-38h] BYREF
  CCloseCaptionItem *item; // [esp+8Ch] [ebp-24h]
  int i; // [esp+90h] [ebp-20h]
  tagRECT rcText; // [esp+94h] [ebp-1Ch] BYREF
  int height; // [esp+A4h] [ebp-Ch]
  CloseCaptionTool *v25; // [esp+A8h] [ebp-8h]
  int totalheight; // [esp+ACh] [ebp-4h] BYREF

  v1 = this;
  v25 = this;
  if ( IFacePoserToolWindow::ToolCanDraw(this: &this->IFacePoserToolWindow) )
  {
    CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: v1);
    v1->HandleToolRedraw(this: &v1->IFacePoserToolWindow, a2: &drawHelper);
    CChoreoWidgetDrawHelper::GetClientRect(this: &drawHelper, rc: &rcOutput);
    rcText = rcOutput;
    totalheight = 0;
    CChoreoWidgetDrawHelper::DrawFilledRect(this: &drawHelper, clr: (const Color *)&totalheight, rc: &rcText);
    v2 = 0;
    totalheight = 9893320;
    CChoreoWidgetDrawHelper::DrawOutlinedRect(
      this: &drawHelper,
      clr: (Color *)&totalheight,
      style: 0,
      width: (HBRUSH__ *)2,
      rc: &rcText);
    InflateRect(lprc: &rcText, dx: -4, dy: 0);
    v3 = rcText.right - rcText.left;
    m_Size = v1->m_Items.m_Size;
    m_pMemory = nullptr;
    v6 = 0;
    avail_width = rcText.right - rcText.left;
    totalheight = 0;
    memset(&visibleitems, 0, sizeof(visibleitems));
    height = m_Size;
    i = 0;
    if ( m_Size > 0 )
    {
      while ( 1 )
      {
        v7 = v1->m_Items.m_Memory.m_pMemory[v6];
        m_flPreDisplayTime = v7->m_flPreDisplayTime;
        item = v7;
        if ( m_flPreDisplayTime <= 0.0 )
        {
          if ( !v7->m_bSizeComputed )
          {
            CloseCaptionTool::ComputeStreamWork(this: v1, helper: &drawHelper, available_width: v3, item: v7);
            v7 = item;
          }
          m_nTotalHeight = v7->m_nTotalHeight;
          totalheight += m_nTotalHeight;
          itemheight = m_nTotalHeight;
          v10 = v2;
          if ( v2 + 1 > visibleitems.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<VisibleStreamItem,int>::Grow(
              this: (CUtlMemory<CAudioMixerState,int> *)&visibleitems,
              num: v2 - visibleitems.m_Memory.m_nAllocationCount + 1);
            v2 = visibleitems.m_Size;
            m_pMemory = visibleitems.m_Memory.m_pMemory;
          }
          visibleitems.m_Size = ++v2;
          visibleitems.m_pElements = m_pMemory;
          if ( v2 - v10 - 1 > 0 )
            _V_memmove(dest: &m_pMemory[v10 + 1], src: &m_pMemory[v10], count: 8 * (v2 - v10 - 1));
          v11 = &m_pMemory[v10];
          if ( v11 != nullptr )
          {
            v12 = item;
            v11->height = itemheight;
            v11->item = v12;
          }
          v1 = v25;
        }
        v6 = i + 1;
        i = v6;
        if ( v6 >= height )
          break;
        v3 = avail_width;
      }
    }
    rcText.bottom -= 2;
    top = rcText.bottom - totalheight;
    v14 = 0;
    for ( rcText.top = rcText.bottom - totalheight; v14 < v2; ++v14 )
    {
      v15 = m_pMemory[v14].item;
      height = m_pMemory[v14].height;
      rcText.bottom = top + height;
      CloseCaptionTool::DrawStream(this: v25, helper: &drawHelper, &rcText, item: v15);
      OffsetRect(lprc: &rcText, dx: 0, dy: height);
      top = rcText.top;
      if ( rcText.top >= rcOutput.bottom )
        break;
    }
    if ( visibleitems.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466770
// Name: public: virtual bool CloseCaptionTool::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CloseCaptionTool::PaintBackground(AnimationBrowser *this)
{
  this->redraw(this);
  return false;
}
