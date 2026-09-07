// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/phonemeeditor.cpp
// Functions: 170
// ============================================================

#include "utils\hlfaceposer\phonemeeditor.h"

//------------------------------------------------------------------------------
// Address: 0x004688B0
// Name: WriteBrownNoise
// Source: json
//------------------------------------------------------------------------------
void __usercall WriteBrownNoise(char *buffer@<eax>, int count)
{
  int v2; // ebx
  int i; // esi

  v2 = count - 1;
  for ( i = 127500; v2 >= 0; --v2 )
  {
    i += random->RandomInt(this: random, a2: -500, a3: 500);
    if ( i <= 129000 )
    {
      if ( i < 126000 )
        i = 126000;
    }
    else
    {
      i = 129000;
    }
    *buffer++ = (int)(float)((float)((float)i * 0.001) + 0.5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468920
// Name: private: void PhonemeEditor::ResampleChunk(class IterateOutputRIFF __near &,void __near *,int,char __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ResampleChunk(
        PhonemeEditor *this,
        IterateOutputRIFF *store,
        _DWORD *format,
        int chunkname,
        char *buffer,
        int buffersize,
        int start_silence,
        int end_silence)
{
  int v8; // esi
  unsigned __int8 *v9; // ebx
  int v10; // edi
  unsigned int v11; // ecx

  if ( *(_WORD *)format == 1 )
  {
    v8 = buffersize + format[1] * (end_silence + start_silence);
    v9 = (unsigned __int8 *)operator new(nSize: v8 + 4);
    memset(dst: v9, value: 0x80u, count: v8 + 4);
    v10 = start_silence * format[1];
    if ( v10 > 0 )
      WriteBrownNoise(buffer: (char *)v9, count: start_silence * format[1]);
    v11 = buffersize;
    if ( v10 + buffersize < v8 )
    {
      WriteBrownNoise(buffer: (char *)&v9[v10 + buffersize], count: v8 - v10 - buffersize);
      v11 = buffersize;
    }
    memcpy(dst: &v9[v10], src: (unsigned __int8 *)buffer, count: v11);
    IterateOutputRIFF::ChunkWriteData(this: store, pOutput: v9, size: v8);
  }
  else
  {
    IterateOutputRIFF::ChunkWriteData(this: store, pOutput: buffer, size: buffersize);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004689D0
// Name: private: void PhonemeEditor::ReadLinguisticTags(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall PhonemeEditor::ReadLinguisticTags(PhonemeEditor *this@<ecx>, int a2@<ebx>)
{
  CAudioSource *v3; // esi
  CSentence *p_m_Tags; // edi
  const CSentence *v5; // ebx

  if ( this->m_pWaveFile != nullptr )
  {
    v3 = sound->LoadSound(this: sound, a2: this->m_WorkFile.m_szWorkingFile);
    if ( v3 != nullptr )
    {
      p_m_Tags = &this->m_Tags;
      CSentence::Reset(this: p_m_Tags);
      v5 = (const CSentence *)((int (__thiscall *)(CAudioSource *, int))v3->GetSentence)(a1: v3, a2);
      if ( v5 != nullptr )
      {
        CSentence::Reset(this: p_m_Tags);
        CSentence::operator=(this: p_m_Tags, src: v5);
      }
      ((void (__thiscall *)(CAudioSource *, int))v3->dtr_CAudioSource)(a1: v3, a2: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468A40
// Name: private: void PhonemeEditor::MoveTimeSliderToPos(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::MoveTimeSliderToPos(PhonemeEditor *this, int x)
{
  mxScrollbar *m_pHorzScrollBar; // ecx
  HWND Handle; // eax

  m_pHorzScrollBar = this->m_pHorzScrollBar;
  this->m_nLeftOffset = x;
  mxScrollbar::setValue(this: m_pHorzScrollBar, ivalue: x);
  Handle = (HWND)mxWidget::getHandle(this: this->m_pHorzScrollBar);
  InvalidateRect(hWnd: Handle, lpRect: nullptr, bErase: true);
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x00468A80
// Name: private: void PhonemeEditor::GetWorkspaceRect(struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::GetWorkspaceRect(PhonemeEditor *this, tagRECT *rc)
{
  HWND Handle; // eax

  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: rc);
  rc->top += 60;
  rc->bottom -= 95;
  InflateRect(lprc: rc, dx: -1, dy: -1);
}

//------------------------------------------------------------------------------
// Address: 0x00468AB0
// Name: private: bool PhonemeEditor::CreateCroppedWave(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge PhonemeEditor::CreateCroppedWave@<al>(
        PhonemeEditor *this@<ecx>,
        int a2@<ebx>,
        CAudioMixer_vtbl *filename,
        int startsample,
        int endsample)
{
  struct CAudioOuput *v6; // edi
  CAudioSource *v8; // esi
  CAudioMixer *v9; // ebx
  unsigned int v10; // eax
  CAudioDeviceSWMix *v11; // edi
  int (__thiscall *SampleRate)(CAudioSource *); // edx
  int v13; // eax
  int v14; // eax
  CAudioMixer v15; // ebx
  int v16; // eax
  char v17; // al
  OutFileRIFF riffout; // [esp+8h] [ebp-6Ch] BYREF
  IterateOutputRIFF store; // [esp+24h] [ebp-50h] BYREF
  channel_s channel; // [esp+40h] [ebp-34h] BYREF
  tWAVEFORMATEX format; // [esp+54h] [ebp-20h] BYREF
  int currentsample; // [esp+68h] [ebp-Ch]
  __int16 samples[2]; // [esp+6Ch] [ebp-8h] BYREF
  CAudioMixer *pMixer; // [esp+70h] [ebp-4h]

  v6 = sound->GetAudioOutput(this: sound);
  if ( v6 == nullptr )
    return 0;
  v8 = sound->LoadSound(this: sound, a2: &this->m_WorkFile);
  if ( v8 == nullptr )
    return 0;
  v9 = v8->CreateMixer(this: v8);
  pMixer = v9;
  if ( v9 == nullptr )
    return 0;
  OutFileRIFF::OutFileRIFF(this: &riffout, pFileName: (const char *)filename, io: &io_out_0);
  IterateOutputRIFF::IterateOutputRIFF(this: &store, riff: &riffout);
  format.wFormatTag = 1;
  format.cbSize = 18;
  v10 = ((int (__thiscall *)(CAudioSource *, int))v8->SampleRate)(a1: v8, a2);
  format.nChannels = 1;
  format.wBitsPerSample = 8;
  format.nAvgBytesPerSec = v10;
  format.nSamplesPerSec = v8->SampleRate(this: v8);
  format.nBlockAlign = 1;
  IterateOutputRIFF::ChunkWrite(this: &store, chunkname: 0x20746D66u, pOutput: &format, size: 18);
  IterateOutputRIFF::ChunkStart(this: &store, chunkname: 0x61746164u);
  channel.leftvol = 255;
  channel.rightvol = 255;
  v11 = (CAudioDeviceSWMix *)((char *)v6 + 1112);
  channel.pitch = 1.0;
  v11->MixBegin(this: v11);
  SampleRate = v8->SampleRate;
  filename = v9->__vftable;
  v13 = ((int (__thiscall *)(CAudioSource *, int))SampleRate)(a1: v8, a2: 1);
  if ( ((unsigned __int8 (__thiscall *)(CAudioMixer *, CAudioDeviceSWMix *, channel_s *, _DWORD, int, int))filename->MixDataToDevice)(
         a1: v9,
         a2: v11,
         a3: &channel,
         a4: 0,
         a5: 1,
         a6: v13) != 0 )
  {
    do
    {
      CAudioDeviceSWMix::TransferBufferStereo16(this: v11, pOutput: samples, sampleCount: 1);
      v14 = v9->GetSamplePosition(this: v9);
      currentsample = v14;
      if ( v14 >= startsample && v14 <= endsample )
      {
        HIBYTE(filename) = (int)(float)((float)((float)((float)(samples[1] >> 8) + (float)(samples[0] >> 8)) * 0.5)
                                      + 127.0);
        IterateOutputRIFF::ChunkWriteData(this: &store, pOutput: (char *)&filename + 3, size: 1);
      }
      v11->MixBegin(this: v11);
      v15.__vftable = v9->__vftable;
      v16 = ((int (__thiscall *)(CAudioSource *, int))v8->SampleRate)(a1: v8, a2: 1);
      v17 = ((int (__thiscall *)(CAudioMixer *, CAudioDeviceSWMix *, channel_s *, int, int, int))v15.MixDataToDevice)(
              a1: pMixer,
              a2: v11,
              a3: &channel,
              a4: currentsample,
              a5: 1,
              a6: v16);
      v9 = pMixer;
    }
    while ( v17 != 0 );
  }
  IterateOutputRIFF::ChunkFinish(this: &store);
  ((void (__thiscall *)(CAudioMixer *, int))v9->dtr_CAudioMixer)(a1: v9, a2: 1);
  ((void (__thiscall *)(CAudioSource *, int))v8->dtr_CAudioSource)(a1: v8, a2: 1);
  OutFileRIFF::~OutFileRIFF(this: &riffout);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00468CC0
// Name: private: void PhonemeEditor::ITER_SelectSpanningWords(class CWordTag __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ITER_SelectSpanningWords(PhonemeEditor *this, CWordTag *word, float amount)
{
  CAudioSource *m_pWaveFile; // ecx
  double v6; // st7
  float starttime; // [esp+8h] [ebp-4h]
  float endtimea; // [esp+14h] [ebp+8h]
  float endtimeb; // [esp+14h] [ebp+8h]
  float endtime; // [esp+14h] [ebp+8h]

  word->m_bSelected = false;
  if ( this->m_bSelectionActive )
  {
    m_pWaveFile = this->m_pWaveFile;
    if ( m_pWaveFile != nullptr )
    {
      endtimea = (float)m_pWaveFile->SampleRate(this: m_pWaveFile);
      v6 = ((double (__thiscall *)(CAudioSource *))this->m_pWaveFile->GetRunningLength)(a1: this->m_pWaveFile)
         * endtimea;
      if ( v6 > 0.0 )
      {
        endtimeb = 1.0 / v6;
        starttime = ((double (__thiscall *)(CAudioSource *))this->m_pWaveFile->GetRunningLength)(a1: this->m_pWaveFile)
                  * ((double)this->m_nSelection[0]
                   * endtimeb);
        endtime = ((double (__thiscall *)(CAudioSource *))this->m_pWaveFile->GetRunningLength)(a1: this->m_pWaveFile)
                * ((double)this->m_nSelection[1]
                 * endtimeb);
        if ( word->m_flEndTime >= (double)starttime && endtime >= word->m_flStartTime )
        {
          word->m_bSelected = true;
          this->m_bWordsActive = true;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468D90
// Name: private: void PhonemeEditor::GetPhonemeTrayTopBottom(struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::GetPhonemeTrayTopBottom(PhonemeEditor *this, tagRECT *rc)
{
  HWND Handle; // eax
  int bottom; // eax
  tagRECT wkrc; // [esp+8h] [ebp-10h] BYREF

  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &wkrc);
  wkrc.top += 60;
  wkrc.bottom -= 95;
  InflateRect(lprc: &wkrc, dx: -1, dy: -1);
  bottom = wkrc.bottom;
  rc->top = wkrc.bottom - 2 * this->m_nTickHeight;
  rc->bottom = bottom - this->m_nTickHeight;
}

//------------------------------------------------------------------------------
// Address: 0x00468DF0
// Name: private: void PhonemeEditor::GetWordTrayTopBottom(struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::GetWordTrayTopBottom(PhonemeEditor *this, tagRECT *rc)
{
  HWND Handle; // eax
  int top; // eax
  tagRECT wkrc; // [esp+4h] [ebp-10h] BYREF

  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &wkrc);
  wkrc.top += 60;
  wkrc.bottom -= 95;
  InflateRect(lprc: &wkrc, dx: -1, dy: -1);
  top = wkrc.top;
  rc->top = wkrc.top;
  rc->bottom = top + this->m_nTickHeight;
}

//------------------------------------------------------------------------------
// Address: 0x00468E40
// Name: private: char const __near * PhonemeEditor::GetExtractionResultString(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall PhonemeEditor::GetExtractionResultString(PhonemeEditor *this, int resultCode)
{
  const char *result; // eax

  switch ( resultCode )
  {
    case 0:
      result = "no extraction info.";
      break;
    case 1:
      result = "an error occurred during extraction.";
      break;
    case 2:
      result = "successful.";
      break;
    case 3:
      result = "results retrieved, but full recognition failed.";
      break;
    default:
      result = "unknown result code.";
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00468E90
// Name: public: void PhonemeEditor::ClearEvent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ClearEvent(PhonemeEditor *this)
{
  void (*redraw)(void); // edx

  redraw = (void (*)(void))this->redraw;
  this->m_pEvent = nullptr;
  redraw();
}

//------------------------------------------------------------------------------
// Address: 0x00468EB0
// Name: private: void PhonemeEditor::ITER_MoveSelectedWords(class CWordTag __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ITER_MoveSelectedWords(PhonemeEditor *this, CWordTag *word, float amount)
{
  if ( word->m_bSelected )
  {
    word->m_flStartTime = word->m_flStartTime + amount;
    word->m_flEndTime = word->m_flEndTime + amount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468EE0
// Name: private: void PhonemeEditor::ITER_MoveSelectedPhonemes(class CPhonemeTag __near *,class CWordTag __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ITER_MoveSelectedPhonemes(
        PhonemeEditor *this,
        CPhonemeTag *phoneme,
        CWordTag *word,
        float amount)
{
  if ( phoneme->m_bSelected )
  {
    phoneme->m_flStartTime = phoneme->m_flStartTime + amount;
    phoneme->m_flEndTime = phoneme->m_flEndTime + amount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468F10
// Name: private: void PhonemeEditor::ITER_ExtendSelectedPhonemeEndTimes(class CPhonemeTag __near *,class CWordTag __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ITER_ExtendSelectedPhonemeEndTimes(
        PhonemeEditor *this,
        CPhonemeTag *phoneme,
        CWordTag *word,
        float amount)
{
  if ( phoneme->m_bSelected && phoneme->m_flStartTime < (float)(phoneme->m_flEndTime + amount) )
    phoneme->m_flEndTime = phoneme->m_flEndTime + amount;
}

//------------------------------------------------------------------------------
// Address: 0x00468F50
// Name: private: void PhonemeEditor::ITER_ExtendSelectedWordEndTimes(class CWordTag __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ITER_ExtendSelectedWordEndTimes(PhonemeEditor *this, CWordTag *word, float amount)
{
  float v3; // xmm0_4

  if ( word->m_bSelected )
  {
    v3 = amount + word->m_flEndTime;
    if ( word->m_flStartTime < v3 )
      word->m_flEndTime = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468F80
// Name: private: void PhonemeEditor::ITER_CountSelectedWords(class CWordTag __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ITER_CountSelectedWords(PhonemeEditor *this, CWordTag *word, float amount)
{
  if ( word->m_bSelected )
    ++this->m_nSelectedWordCount;
}

//------------------------------------------------------------------------------
// Address: 0x00468FA0
// Name: private: void PhonemeEditor::ITER_CountSelectedPhonemes(class CPhonemeTag __near *,class CWordTag __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ITER_CountSelectedPhonemes(
        PhonemeEditor *this,
        CPhonemeTag *phoneme,
        CWordTag *word,
        float amount)
{
  if ( phoneme->m_bSelected )
    ++this->m_nSelectedPhonemeCount;
}

//------------------------------------------------------------------------------
// Address: 0x00468FC0
// Name: private: void PhonemeEditor::LimitDrag(int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::LimitDrag(PhonemeEditor *this, int *mousex)
{
  int m_nStartX; // edi
  int v3; // esi
  int m_nRightLimit; // ecx
  int m_nLeftLimit; // ecx

  if ( this->m_nDragType != 0 && this->m_bLimitDrag )
  {
    m_nStartX = this->m_nStartX;
    v3 = *mousex - m_nStartX;
    if ( v3 <= 0 )
    {
      if ( v3 < 0 )
      {
        m_nLeftLimit = this->m_nLeftLimit;
        if ( m_nLeftLimit >= 0 && (int)abs32(v3) > (int)abs32(m_nLeftLimit) )
          *mousex = m_nStartX - m_nLeftLimit;
      }
    }
    else
    {
      m_nRightLimit = this->m_nRightLimit;
      if ( m_nRightLimit >= 0 && v3 > m_nRightLimit )
        *mousex = m_nStartX + m_nRightLimit;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00469030
// Name: private: void PhonemeEditor::SelectExpression(class CPhonemeTag __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::SelectExpression(PhonemeEditor *this, CPhonemeTag *tag)
{
  StudioModel *v2; // esi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // eax
  CStudioHdr *v5; // esi
  CStudioHdr *v6; // edi
  Color v7; // ecx
  CExpClass *v8; // esi
  const char *v9; // eax
  CExpression *Expression; // eax
  const char *v11; // eax
  Color v12; // ecx
  float *Settings; // ebx
  const studiohdr_t *v14; // eax
  LocalFlexController_t v15; // esi
  int v16; // edi
  StudioModel *v17; // eax
  float flValue; // [esp+10h] [ebp-10h]
  CStudioHdr *hdr; // [esp+1Ch] [ebp-4h]

  if ( ((int (__thiscall *)(IFaceposerModels *, PhonemeEditor *))models->GetActiveStudioModel)(a1: models, a2: this) != 0 )
  {
    v2 = models->GetActiveStudioModel(this: models);
    m_pStudioHdr = v2->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr != nullptr )
    {
      hdr = v2->m_pStudioHdr;
      v6 = hdr;
    }
    else
    {
      v4 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v2->m_MDLHandle);
      CStudioHdr::Init(this: v2->m_pStudioHdr, pStudioHdr: v4, mdlcache: nullptr);
      v5 = v2->m_pStudioHdr;
      if ( v5->m_pStudioHdr == nullptr )
        return;
      v6 = v5;
      hdr = v5;
    }
    if ( v6 != nullptr )
    {
      FacePoser_EnsurePhonemesLoaded();
      v8 = expressions->FindClass(this: expressions, a2: "phonemes", a3: 1);
      if ( v8 != nullptr )
      {
        if ( expressions->GetActiveClass(this: expressions) != v8 )
          expressions->ActivateExpressionClass(this: expressions, a2: v8);
        v9 = ConvertPhoneme(code: tag->m_nPhonemeCode);
        Expression = CExpClass::FindExpression(this: v8, name: v9);
        if ( Expression != nullptr )
        {
          Settings = CExpression::GetSettings(this: Expression);
          v14 = v6->m_pStudioHdr;
          v15 = DUMMY_NULL_FLEX_CONTROLLER;
          if ( v6->m_pStudioHdr->numflexcontrollers > 0 )
          {
            v16 = 0;
            do
            {
              flValue = Settings[*(int *)((char *)&v14->checksum + v16 + v14->flexcontrollerindex)];
              v17 = models->GetActiveStudioModel(this: models);
              StudioModel::SetFlexController(this: v17, iFlex: v15, flValue);
              v14 = hdr->m_pStudioHdr;
              ++v15;
              v16 += 20;
            }
            while ( v15 < hdr->m_pStudioHdr->numflexcontrollers );
          }
        }
        else
        {
          v11 = ConvertPhoneme(code: tag->m_nPhonemeCode);
          Con_Printf(a1: v12, fmt: "Couldn't find phoneme '%s'\n", v11);
        }
      }
      else
      {
        Con_Printf(a1: v7, fmt: "Couldn't load expressions/phonemes.txt!\n");
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004691A0
// Name: private: void PhonemeEditor::Emphasis_DeselectAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::Emphasis_DeselectAll(PhonemeEditor *this)
{
  int i; // esi

  if ( this->m_CurrentMode == MODE_EMPHASIS )
  {
    for ( i = 0; i < CSentence::GetNumSamples(this: &this->m_Tags); ++i )
      CSentence::GetSample(this: &this->m_Tags, index: i)->selected = false;
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004691F0
// Name: private: void PhonemeEditor::Emphasis_SelectAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::Emphasis_SelectAll(PhonemeEditor *this)
{
  int i; // esi

  if ( this->m_CurrentMode == MODE_EMPHASIS )
  {
    for ( i = 0; i < CSentence::GetNumSamples(this: &this->m_Tags); ++i )
      CSentence::GetSample(this: &this->m_Tags, index: i)->selected = true;
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00469240
// Name: private: void PhonemeEditor::Emphasis_CountSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::Emphasis_CountSelected(PhonemeEditor *this)
{
  int v2; // esi
  CEmphasisSample *Sample; // eax

  v2 = 0;
  for ( this->m_nNumSelected = 0; v2 < CSentence::GetNumSamples(this: &this->m_Tags); ++v2 )
  {
    Sample = CSentence::GetSample(this: &this->m_Tags, index: v2);
    if ( Sample != nullptr && Sample->selected )
      ++this->m_nNumSelected;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00469290
// Name: private: bool PhonemeEditor::IsMouseOverScrubArea(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall PhonemeEditor::IsMouseOverScrubArea(PhonemeEditor *this, mxEvent *event)
{
  int v3; // eax
  POINT v5; // [esp-8h] [ebp-1Ch]
  tagRECT rcArea; // [esp+4h] [ebp-10h] BYREF

  rcArea.left = 0;
  rcArea.right = mxWidget::w2(this);
  v3 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow);
  rcArea.top = v3 + 14;
  rcArea.bottom = v3 + 24;
  InflateRect(lprc: &rcArea, dx: 2, dy: 2);
  v5.y = SLOWORD(event->y);
  v5.x = SLOWORD(event->x);
  return PtInRect(lprc: &rcArea, pt: v5);
}

//------------------------------------------------------------------------------
// Address: 0x004692F0
// Name: private: float PhonemeEditor::GetTimeForSample(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall PhonemeEditor::GetTimeForSample(PhonemeEditor *this, int sample)
{
  float duration; // [esp+4h] [ebp-8h]
  int sampleCount; // [esp+8h] [ebp-4h]

  if ( this->m_pWaveFile != nullptr
    && (duration = this->m_pWaveFile->GetRunningLength(this: this->m_pWaveFile),
        (sampleCount = this->m_pWaveFile->SampleCount(this: this->m_pWaveFile)) > 0) )
  {
    return (double)sample / (double)sampleCount * duration;
  }
  else
  {
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00469400
// Name: public: void PhonemeEditor::SetupPhonemeEditorColors(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::SetupPhonemeEditorColors(PhonemeEditor *this)
{
  unsigned __int8 *v1; // esi
  int v2; // ecx
  int v3; // [esp+0h] [ebp-4h]

  v1 = (unsigned __int8 *)&g_PEColors[0].root_color + 2;
  do
  {
    if ( *(_DWORD *)(v1 - 6) == -1 )
    {
      *(_DWORD *)(v1 + 2) = *(_DWORD *)(v1 - 2);
    }
    else
    {
      v2 = (unsigned __int64)(1431655766LL * (*v1 + *(v1 - 1) + *(v1 - 2))) >> 32;
      LOBYTE(v3) = (int)((double)(int)(((unsigned __int64)(1431655766LL
                                                         * (g_PEColors[0].root_color._color[0]
                                                          + g_PEColors[0].root_color._color[2]
                                                          + g_PEColors[0].root_color._color[1])) >> 32)
                                     - v2)
                       * 0.4
                       + (double)v2);
      BYTE1(v3) = v3;
      HIWORD(v3) = (unsigned __int8)v3;
      *(_DWORD *)(v1 + 2) = v3;
    }
    v1 += 16;
  }
  while ( (int)v1 < (int)((unsigned __int8 *)&vec2_invalid_69.x + 2) );
}

//------------------------------------------------------------------------------
// Address: 0x004694B0
// Name: public: class Color PhonemeEditor::PEColor(int)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall PhonemeEditor::PEColor(PhonemeEditor *this, Color *result, unsigned int colornum)
{
  PhonemeEditorColor *v3; // eax
  int mode_number; // edx

  if ( colornum > 0x21 )
  {
    *result = 0;
    return result;
  }
  else
  {
    v3 = &g_PEColors[colornum];
    mode_number = v3->mode_number;
    if ( mode_number == -1 )
    {
      *result = v3->root_color;
      return result;
    }
    else
    {
      if ( mode_number == this->m_CurrentMode )
        *result = v3->root_color;
      else
        *result = v3->gray_color;
      return result;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00469520
// Name: private: float PhonemeEditor::GetTimeForPixel(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall PhonemeEditor::GetTimeForPixel(PhonemeEditor *this, int mx)
{
  HWND Handle; // eax
  double v4; // st7
  tagRECT rc; // [esp+4h] [ebp-10h] BYREF

  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &rc);
  rc.top += 60;
  rc.bottom -= 95;
  InflateRect(lprc: &rc, dx: -1, dy: -1);
  v4 = (double)this->m_nTimeZoom * 0.0099999998 * this->m_flPixelsPerSecond;
  return (double)mx / v4 + (double)this->m_nLeftOffset / v4;
}

//------------------------------------------------------------------------------
// Address: 0x00469580
// Name: private: float PhonemeEditor::GetTimePerPixel(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall PhonemeEditor::GetTimePerPixel(PhonemeEditor *this)
{
  HWND Handle; // eax
  float v3; // xmm0_4
  int v4; // eax
  double result; // st7
  tagRECT rc; // [esp+4h] [ebp-1Ch] BYREF
  int v7; // [esp+14h] [ebp-Ch]
  float endtime; // [esp+18h] [ebp-8h]
  float starttime; // [esp+1Ch] [ebp-4h]

  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &rc);
  rc.top += 60;
  rc.bottom -= 95;
  InflateRect(lprc: &rc, dx: -1, dy: -1);
  v3 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
  starttime = (float)this->m_nLeftOffset / v3;
  endtime = v3;
  v4 = mxWidget::w2(this);
  endtime = (float)((float)v4 / endtime) + starttime;
  v7 = rc.right - rc.left;
  result = endtime - starttime;
  if ( rc.right - rc.left > 0 )
    return result / (double)v7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469620
// Name: private: int PhonemeEditor::GetPixelForSample(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall PhonemeEditor::GetPixelForSample(PhonemeEditor *this, int sample)
{
  HWND Handle; // eax
  float v5; // eax
  CAudioSource *m_pWaveFile; // ecx
  CAudioSource_vtbl *v7; // edx
  double v8; // st7
  float (__thiscall *GetRunningLength)(CAudioSource *); // eax
  double v10; // st7
  float v11; // xmm0_4
  int v12; // eax
  CAudioSource *v13; // ecx
  float v14; // xmm0_4
  float (__thiscall *v15)(CAudioSource *); // eax
  double v16; // st7
  tagRECT rc; // [esp+4h] [ebp-1Ch] BYREF
  int totalsamples; // [esp+14h] [ebp-Ch]
  float endtime; // [esp+18h] [ebp-8h]
  float starttime; // [esp+1Ch] [ebp-4h]
  float sampleTime; // [esp+28h] [ebp+8h]

  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &rc);
  rc.top += 60;
  rc.bottom -= 95;
  InflateRect(lprc: &rc, dx: -1, dy: -1);
  if ( this->m_pWaveFile == nullptr )
    return rc.left;
  v5 = COERCE_FLOAT(this->m_pWaveFile->SampleRate(this: this->m_pWaveFile));
  m_pWaveFile = this->m_pWaveFile;
  v7 = m_pWaveFile->__vftable;
  starttime = v5;
  v8 = (double)SLODWORD(v5);
  GetRunningLength = v7->GetRunningLength;
  starttime = v8;
  v10 = ((double (__thiscall *)(CAudioSource *))GetRunningLength)(a1: m_pWaveFile);
  totalsamples = (int)(v10 * starttime);
  if ( totalsamples <= 0 )
    return rc.left;
  v11 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
  starttime = (float)this->m_nLeftOffset / v11;
  endtime = v11;
  v12 = mxWidget::w2(this);
  v13 = this->m_pWaveFile;
  v14 = (float)((float)v12 / endtime) + starttime;
  v15 = v13->GetRunningLength;
  endtime = v14;
  v16 = ((double (__thiscall *)(CAudioSource *))v15)(a1: v13);
  sampleTime = v16 * ((double)sample / (double)totalsamples);
  if ( (float)(endtime - starttime) >= 0.0 )
    return rc.left
         + (int)(float)((float)((float)(sampleTime - starttime) / (float)(endtime - starttime))
                      * (float)(rc.right - rc.left));
  else
    return rc.left;
}

//------------------------------------------------------------------------------
// Address: 0x00469750
// Name: private: int PhonemeEditor::GetSampleForMouse(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall PhonemeEditor::GetSampleForMouse(PhonemeEditor *this, int mx)
{
  HWND Handle; // eax
  float v5; // eax
  CAudioSource *m_pWaveFile; // ecx
  CAudioSource_vtbl *v7; // edx
  double v8; // st7
  float (__thiscall *GetRunningLength)(CAudioSource *); // eax
  double v10; // st7
  float v11; // xmm0_4
  float v12; // xmm0_4
  tagRECT rc; // [esp+4h] [ebp-18h] BYREF
  int totalsamples; // [esp+14h] [ebp-8h]
  float starttime; // [esp+18h] [ebp-4h]
  float clickTime; // [esp+24h] [ebp+8h]
  float clickTimea; // [esp+24h] [ebp+8h]

  if ( this->m_pWaveFile == nullptr )
    return 0;
  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &rc);
  rc.top += 60;
  rc.bottom -= 95;
  InflateRect(lprc: &rc, dx: -1, dy: -1);
  v5 = COERCE_FLOAT(this->m_pWaveFile->SampleRate(this: this->m_pWaveFile));
  m_pWaveFile = this->m_pWaveFile;
  v7 = m_pWaveFile->__vftable;
  starttime = v5;
  v8 = (double)SLODWORD(v5);
  GetRunningLength = v7->GetRunningLength;
  starttime = v8;
  v10 = ((double (__thiscall *)(CAudioSource *))GetRunningLength)(a1: m_pWaveFile);
  v11 = (float)this->m_nLeftOffset
      / (float)((float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond);
  totalsamples = (int)(v10 * starttime);
  starttime = v11;
  mxWidget::w2(this);
  v12 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
  if ( v12 <= 0.0 )
    return 0;
  clickTime = (float)((float)mx / v12) + starttime;
  if ( ((double (__thiscall *)(CAudioSource *))this->m_pWaveFile->GetRunningLength)(a1: this->m_pWaveFile) <= 0.0 )
    return 0;
  clickTimea = (double)totalsamples * clickTime;
  return (int)(clickTimea
             / ((double (__thiscall *)(CAudioSource *))this->m_pWaveFile->GetRunningLength)(a1: this->m_pWaveFile));
}

//------------------------------------------------------------------------------
// Address: 0x00469870
// Name: private: void PhonemeEditor::CreateEvenWordDistribution(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::CreateEvenWordDistribution(PhonemeEditor *this, const char *wordlist)
{
  float flSentenceDuration; // [esp+0h] [ebp-Ch]

  if ( this->m_CurrentMode == MODE_PHONEMES && this->m_pWaveFile != nullptr && wordlist != nullptr )
  {
    flSentenceDuration = this->m_pWaveFile->GetRunningLength(this: this->m_pWaveFile);
    CSentence::CreateEventWordDistribution(this: &this->m_Tags, pszText: wordlist, flSentenceDuration);
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004698C0
// Name: private: bool PhonemeEditor::IsMouseOverWordRow(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall PhonemeEditor::IsMouseOverWordRow(PhonemeEditor *this, int my)
{
  bool result; // al
  HWND Handle; // eax
  tagRECT Rect; // [esp+4h] [ebp-10h] BYREF

  result = this->m_CurrentMode == MODE_PHONEMES
        && (Handle = (HWND)mxWidget::getHandle(this),
            GetClientRect(hWnd: Handle, lpRect: &Rect),
            Rect.top += 60,
            Rect.bottom -= 95,
            InflateRect(lprc: &Rect, dx: -1, dy: -1),
            my >= Rect.top)
        && my <= Rect.top + this->m_nTickHeight;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469920
// Name: private: bool PhonemeEditor::IsMouseOverPhonemeRow(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall PhonemeEditor::IsMouseOverPhonemeRow(PhonemeEditor *this, int my)
{
  bool result; // al
  HWND Handle; // eax
  int m_nTickHeight; // edx
  tagRECT Rect; // [esp+4h] [ebp-10h] BYREF

  result = this->m_CurrentMode == MODE_PHONEMES
        && (Handle = (HWND)mxWidget::getHandle(this),
            GetClientRect(hWnd: Handle, lpRect: &Rect),
            Rect.top += 60,
            Rect.bottom -= 95,
            InflateRect(lprc: &Rect, dx: -1, dy: -1),
            m_nTickHeight = this->m_nTickHeight,
            my >= Rect.bottom - 2 * m_nTickHeight)
        && my <= Rect.bottom - m_nTickHeight;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469990
// Name: private: int PhonemeEditor::GetMouseForTime(float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall PhonemeEditor::GetMouseForTime(PhonemeEditor *this, float time)
{
  HWND Handle; // eax
  float v5; // xmm0_4
  int v6; // eax
  float v7; // xmm0_4
  tagRECT rc; // [esp+4h] [ebp-18h] BYREF
  float starttime; // [esp+14h] [ebp-8h]
  float v10; // [esp+18h] [ebp-4h]

  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &rc);
  rc.top += 60;
  rc.bottom -= 95;
  InflateRect(lprc: &rc, dx: -1, dy: -1);
  if ( (float)((float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond) < 0.0 )
    return rc.left;
  v5 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
  starttime = (float)this->m_nLeftOffset / v5;
  v10 = v5;
  v6 = mxWidget::w2(this);
  v7 = (float)((float)((float)v6 / v10) + starttime) - starttime;
  if ( v7 <= 0.0 )
    return rc.left;
  else
    return rc.left + (int)(float)((float)((float)(time - starttime) / v7) * (float)rc.right);
}

//------------------------------------------------------------------------------
// Address: 0x00469A70
// Name: private: void PhonemeEditor::GetWordRect(class CWordTag const __near *,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::GetWordRect(PhonemeEditor *this, const CWordTag *tag, tagRECT *rc)
{
  HWND Handle; // eax
  int top; // eax
  tagRECT Rect; // [esp+10h] [ebp-10h] BYREF

  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &Rect);
  Rect.top += 60;
  Rect.bottom -= 95;
  InflateRect(lprc: &Rect, dx: -1, dy: -1);
  top = Rect.top;
  rc->top = Rect.top;
  rc->bottom = top + this->m_nTickHeight;
  rc->left = PhonemeEditor::GetMouseForTime(this, time: tag->m_flStartTime);
  rc->right = PhonemeEditor::GetMouseForTime(this, time: tag->m_flEndTime);
}

//------------------------------------------------------------------------------
// Address: 0x00469AF0
// Name: private: void PhonemeEditor::GetPhonemeRect(class CPhonemeTag const __near *,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::GetPhonemeRect(PhonemeEditor *this, const CPhonemeTag *tag, tagRECT *rc)
{
  HWND Handle; // eax
  int bottom; // eax
  tagRECT Rect; // [esp+10h] [ebp-10h] BYREF

  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &Rect);
  Rect.top += 60;
  Rect.bottom -= 95;
  InflateRect(lprc: &Rect, dx: -1, dy: -1);
  bottom = Rect.bottom;
  rc->top = Rect.bottom - 2 * this->m_nTickHeight;
  rc->bottom = bottom - this->m_nTickHeight;
  rc->left = PhonemeEditor::GetMouseForTime(this, time: tag->m_flStartTime);
  rc->right = PhonemeEditor::GetMouseForTime(this, time: tag->m_flEndTime);
}

//------------------------------------------------------------------------------
// Address: 0x00469B80
// Name: private: void PhonemeEditor::ClearExtracted(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ClearExtracted(PhonemeEditor *this)
{
  if ( this->m_CurrentMode == MODE_PHONEMES )
  {
    this->m_nLastExtractionResult = 0;
    CSentence::Reset(this: &this->m_TagsExt);
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00469BB0
// Name: private: class CEventRelativeTag __near * PhonemeEditor::GetTagUnderMouse(int)
// Source: json
//------------------------------------------------------------------------------
CEventAbsoluteTag *__thiscall PhonemeEditor::GetTagUnderMouse(PhonemeEditor *this, int mx)
{
  HWND Handle; // eax
  float v5; // xmm0_4
  int v6; // eax
  int v7; // ebx
  CEventAbsoluteTag *RelativeTag; // edi
  double Percentage; // st7
  double v10; // st7
  int rcTags; // [esp+4h] [ebp-30h]
  int rcTags_8; // [esp+Ch] [ebp-28h]
  tagRECT rc; // [esp+14h] [ebp-20h] BYREF
  float v14; // [esp+24h] [ebp-10h]
  float endtime; // [esp+28h] [ebp-Ch]
  float tagtime; // [esp+2Ch] [ebp-8h]
  float starttime; // [esp+30h] [ebp-4h]

  if ( this->m_CurrentMode != MODE_PHONEMES )
    return nullptr;
  if ( this->m_pEvent == nullptr )
    return nullptr;
  if ( this->m_pWaveFile == nullptr )
    return nullptr;
  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &rc);
  rc.top += 60;
  rc.bottom -= 95;
  InflateRect(lprc: &rc, dx: -1, dy: -1);
  rcTags = rc.left;
  rcTags_8 = rc.right;
  if ( (float)((float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond) <= 0.0 )
    return nullptr;
  v5 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
  starttime = (float)this->m_nLeftOffset / v5;
  tagtime = v5;
  v6 = mxWidget::w2(this);
  endtime = (float)((float)v6 / tagtime) + starttime;
  v14 = endtime - starttime;
  if ( (float)(endtime - starttime) < 0.0 )
    return nullptr;
  v7 = 0;
  if ( CChoreoEvent::GetNumRelativeTags(this: this->m_pEvent) <= 0 )
    return nullptr;
  while ( 1 )
  {
    RelativeTag = (CEventAbsoluteTag *)CChoreoEvent::GetRelativeTag(this: this->m_pEvent, tagnum: v7);
    if ( RelativeTag != nullptr )
    {
      tagtime = this->m_pWaveFile->GetRunningLength(this: this->m_pWaveFile);
      Percentage = CEventAbsoluteTag::GetPercentage(this: RelativeTag);
      v10 = Percentage * tagtime;
      tagtime = v10;
      if ( starttime <= v10
        && tagtime <= endtime
        && (int)abs32(
                  mx
                - (int)(float)((float)((float)((float)(tagtime - starttime) / v14) * (float)(rcTags_8 - rcTags)) + 0.5)
                - rcTags) < 10 )
      {
        break;
      }
    }
    if ( ++v7 >= CChoreoEvent::GetNumRelativeTags(this: this->m_pEvent) )
      return nullptr;
  }
  return RelativeTag;
}

//------------------------------------------------------------------------------
// Address: 0x00469D70
// Name: private: void PhonemeEditor::FinishEventTagDrag(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::FinishEventTagDrag(PhonemeEditor *this, int startx, int endx)
{
  CEventAbsoluteTag *TagUnderMouse; // edi
  float v5; // xmm0_4
  double v6; // st7
  float percentage; // xmm0_4
  float clicktime; // [esp+14h] [ebp+8h]
  float clicktimea; // [esp+14h] [ebp+8h]

  if ( this->m_pWaveFile != nullptr
    && ((double (__thiscall *)(CAudioSource *))this->m_pWaveFile->GetRunningLength)(a1: this->m_pWaveFile) != 0.0 )
  {
    TagUnderMouse = PhonemeEditor::GetTagUnderMouse(this, mx: startx);
    if ( TagUnderMouse != nullptr
      && (float)((float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond) > 0.0 )
    {
      v5 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
      clicktime = (float)((float)this->m_nLeftOffset / v5) + (float)((float)endx / v5);
      v6 = clicktime
         / ((double (__thiscall *)(CAudioSource *))this->m_pWaveFile->GetRunningLength)(a1: this->m_pWaveFile);
      if ( v6 >= 0.0 )
      {
        percentage = v6;
        clicktimea = v6;
        if ( clicktimea > 1.0 )
          percentage = 1.0;
      }
      else
      {
        percentage = 0.0;
      }
      CEventAbsoluteTag::SetPercentage(this: TagUnderMouse, percentage);
      this->redraw(this);
      if ( g_pChoreoView != nullptr )
        CChoreoView::InvalidateLayout(this: g_pChoreoView);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00469E80
// Name: private: bool PhonemeEditor::IsMouseOverTagRow(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall PhonemeEditor::IsMouseOverTagRow(PhonemeEditor *this, int my)
{
  return this->m_CurrentMode == MODE_PHONEMES && (unsigned int)(my - 40) <= 0x14;
}

//------------------------------------------------------------------------------
// Address: 0x00469EB0
// Name: private: void PhonemeEditor::ShowTagMenu(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ShowTagMenu(PhonemeEditor *this, CEventRelativeTag *mx, int my)
{
  mxPopupMenu *v5; // eax
  mxPopupMenu *v6; // edi
  const char *Name; // eax
  const char *v8; // eax
  int v9; // [esp-Ch] [ebp-10h]
  CEventAbsoluteTag *tag; // [esp+Ch] [ebp+8h]

  if ( this->m_CurrentMode == MODE_PHONEMES
    && this->m_pEvent != nullptr
    && this->m_pWaveFile != nullptr
    && (unsigned int)(my - 40) <= 0x14 )
  {
    tag = PhonemeEditor::GetTagUnderMouse(this, (int)mx);
    v5 = (mxPopupMenu *)operator new(nSize: 0xCu);
    if ( v5 != nullptr )
      v6 = mxPopupMenu::mxPopupMenu(this: v5);
    else
      v6 = nullptr;
    if ( tag != nullptr )
    {
      v9 = 1024;
      Name = CEventAbsoluteTag::GetName(this: tag);
      v8 = va(fmt: "Delete tag '%s'", Name);
    }
    else
    {
      v9 = 1023;
      v8 = va(fmt: "Add tag...");
    }
    mxPopupMenu::add(this: v6, item: v8, id: v9);
    this->m_nClickX = (int)mx;
    mxPopupMenu::popup(this: v6, widget: this, x: (int)mx, y: my);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00469F70
// Name: private: void PhonemeEditor::DeleteTag(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::DeleteTag(PhonemeEditor *this)
{
  CEventAbsoluteTag *TagUnderMouse; // eax
  const char *Name; // eax

  if ( this->m_CurrentMode == MODE_PHONEMES && this->m_pEvent != nullptr )
  {
    TagUnderMouse = PhonemeEditor::GetTagUnderMouse(this, mx: this->m_nClickX);
    if ( TagUnderMouse != nullptr )
    {
      Name = CEventAbsoluteTag::GetName(this: TagUnderMouse);
      CChoreoEvent::RemoveRelativeTag(this: this->m_pEvent, tagname: Name);
      CChoreoView::InvalidateLayout(this: g_pChoreoView);
      this->redraw(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00469FC0
// Name: private: void PhonemeEditor::AddTag(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::AddTag(PhonemeEditor *this)
{
  Color v2; // ecx
  CAudioSource *m_pWaveFile; // ecx
  float (__thiscall *GetRunningLength)(CAudioSource *); // eax
  float v5; // xmm0_4
  double v6; // st7
  double v7; // st7
  float percentage; // xmm0_4
  HWND Handle; // eax
  CInputParams params; // [esp+8h] [ebp-590h] BYREF
  float clicktime; // [esp+594h] [ebp-4h]

  if ( this->m_CurrentMode == MODE_PHONEMES && this->m_pEvent != nullptr && this->m_pWaveFile != nullptr )
  {
    memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
    strcpy(params.m_szDialogTitle, "Event Tag Name");
    strcpy(params.m_szPrompt, "Name:");
    params.m_szInputText[0] = 0;
    if ( InputProperties(&params) != 0 )
    {
      if ( &params.m_szInputText[strlen(params.m_szInputText) + 1] == &params.m_szInputText[1] )
      {
        Con_ErrorPrintf(a1: v2, fmt: "Event Tag Name:  No name entered!\n");
      }
      else
      {
        m_pWaveFile = this->m_pWaveFile;
        GetRunningLength = m_pWaveFile->GetRunningLength;
        v5 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
        clicktime = (float)((float)this->m_nLeftOffset / v5) + (float)((float)this->m_nClickX / v5);
        v6 = ((double (__thiscall *)(CAudioSource *))GetRunningLength)(a1: m_pWaveFile);
        v7 = clicktime / v6;
        clicktime = v7;
        if ( v7 <= 1.0 )
        {
          percentage = clicktime;
          if ( clicktime < 0.0 )
            percentage = 0.0;
        }
        else
        {
          percentage = 1.0;
        }
        CChoreoEvent::AddRelativeTag(this: this->m_pEvent, tagname: params.m_szInputText, percentage);
        CChoreoView::InvalidateLayout(this: g_pChoreoView);
        Handle = (HWND)mxWidget::getHandle(this);
        SetFocus(hWnd: Handle);
        this->redraw(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046A160
// Name: private: void PhonemeEditor::ShowContextMenu_Emphasis(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ShowContextMenu_Emphasis(PhonemeEditor *this, int mx, int my)
{
  mxPopupMenu *v4; // eax
  mxPopupMenu *v5; // edi
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax

  PhonemeEditor::Emphasis_CountSelected(this);
  v4 = (mxPopupMenu *)operator new(nSize: 0xCu);
  if ( v4 != nullptr )
    v5 = mxPopupMenu::mxPopupMenu(this: v4);
  else
    v5 = nullptr;
  v6 = va(fmt: "Select All");
  mxPopupMenu::add(this: v5, item: v6, id: 1043);
  if ( this->m_nNumSelected > 0 )
  {
    v7 = va(fmt: "Deselect All");
    mxPopupMenu::add(this: v5, item: v7, id: 1042);
  }
  if ( this->m_nUndoLevel != 0 || this->m_UndoStack.m_Size != 0 )
  {
    mxMenu::addSeparator(this: v5);
    if ( this->m_nUndoLevel != 0 )
    {
      v8 = va(fmt: "Undo");
      mxPopupMenu::add(this: v5, item: v8, id: 5038);
    }
    if ( this->m_nUndoLevel != this->m_UndoStack.m_Size )
    {
      v9 = va(fmt: "Redo");
      mxPopupMenu::add(this: v5, item: v9, id: 5039);
    }
    v10 = va(fmt: "Clear Undo Info");
    mxPopupMenu::add(this: v5, item: v10, id: 1038);
  }
  mxPopupMenu::popup(this: v5, widget: this, x: mx, y: my);
}

//------------------------------------------------------------------------------
// Address: 0x0046A260
// Name: private: int PhonemeEditor::PixelsForDeltaTime(float)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall PhonemeEditor::PixelsForDeltaTime(PhonemeEditor *this, float dt)
{
  HWND Handle; // eax
  float v5; // xmm0_4
  int v6; // eax
  tagRECT rc; // [esp+0h] [ebp-18h] BYREF
  float starttime; // [esp+10h] [ebp-8h]
  float v9; // [esp+14h] [ebp-4h]

  if ( dt == 0.0 )
    return 0;
  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &rc);
  rc.top += 60;
  rc.bottom -= 95;
  InflateRect(lprc: &rc, dx: -1, dy: -1);
  v5 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
  starttime = (float)this->m_nLeftOffset / v5;
  v9 = v5;
  v6 = mxWidget::w2(this);
  return abs32((int)(float)(dt
                          / (float)((float)((float)((float)((float)v6 / v9) + starttime) - starttime)
                                  / (float)(rc.right - rc.left))));
}

//------------------------------------------------------------------------------
// Address: 0x0046A330
// Name: private: void PhonemeEditor::Emphasis_GetRect(struct tagRECT const __near &,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::Emphasis_GetRect(PhonemeEditor *this, const tagRECT *rcWorkSpace, tagRECT *rcEmphasis)
{
  int bottom; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // edx
  int v7; // eax

  *rcEmphasis = *rcWorkSpace;
  bottom = rcWorkSpace->bottom;
  v4 = bottom - (2 * this->m_nTickHeight + 2);
  v5 = (bottom - rcWorkSpace->top) / 2 + rcWorkSpace->top + 2;
  v6 = v5 + 20;
  rcEmphasis->top = v5;
  v7 = v5 + 60;
  if ( v7 >= v6 )
  {
    if ( v7 <= v4 )
      rcEmphasis->bottom = v7;
    else
      rcEmphasis->bottom = v4;
  }
  else
  {
    rcEmphasis->bottom = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046A3A0
// Name: private: struct CEmphasisSample __near * PhonemeEditor::Emphasis_GetSampleUnderMouse(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
CEmphasisSample *__thiscall PhonemeEditor::Emphasis_GetSampleUnderMouse(PhonemeEditor *this, mxEvent *event)
{
  float v4; // xmm0_4
  CSentence *p_m_Tags; // edi
  int NumSamples; // ebx
  double TimeForPixel; // st7
  int i; // esi
  CEmphasisSample *Sample; // eax
  CEmphasisSample *bestsample; // [esp+8h] [ebp-8h]
  float closest_dist; // [esp+Ch] [ebp-4h]
  float clickTime; // [esp+18h] [ebp+8h]

  if ( this->m_CurrentMode != MODE_EMPHASIS )
    return nullptr;
  if ( this->m_pWaveFile == nullptr )
    return nullptr;
  if ( mxWidget::w2(this) <= 0 )
    return nullptr;
  v4 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
  if ( v4 <= 0.0 )
    return nullptr;
  p_m_Tags = &this->m_Tags;
  closest_dist = 999999.0;
  bestsample = nullptr;
  NumSamples = CSentence::GetNumSamples(this: &this->m_Tags);
  TimeForPixel = PhonemeEditor::GetTimeForPixel(this, mx: SLOWORD(event->x));
  for ( i = 0; i < NumSamples; ++i )
  {
    Sample = CSentence::GetSample(this: p_m_Tags, index: i);
    clickTime = TimeForPixel;
    if ( closest_dist > COERCE_FLOAT(COERCE_UNSIGNED_INT(Sample->time - clickTime) & _mask__AbsFloat_) )
    {
      bestsample = Sample;
      LODWORD(closest_dist) = COERCE_UNSIGNED_INT(Sample->time - clickTime) & _mask__AbsFloat_;
    }
  }
  if ( closest_dist <= (float)((float)(1.0 / v4) * 5.0) )
    return bestsample;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0046A4A0
// Name: private: void PhonemeEditor::Emphasis_MouseDrag(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::Emphasis_MouseDrag(PhonemeEditor *this, int x, int y)
{
  HWND Handle; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // eax
  int v8; // ebx
  double TimePerPixel; // st7
  CSentence *p_m_Tags; // esi
  int i; // edi
  CEmphasisSample *Sample; // eax
  int v13; // xmm1_4
  float v14; // xmm0_4
  tagRECT rcWork; // [esp+4h] [ebp-14h] BYREF
  int v16; // [esp+14h] [ebp-4h]
  int dfdxa; // [esp+20h] [ebp+8h]
  float dfdx; // [esp+20h] [ebp+8h]
  float dfdy; // [esp+24h] [ebp+Ch]

  if ( this->m_nDragType == 11 )
  {
    Handle = (HWND)mxWidget::getHandle(this);
    GetClientRect(hWnd: Handle, lpRect: &rcWork);
    rcWork.top += 60;
    rcWork.bottom -= 95;
    InflateRect(lprc: &rcWork, dx: -1, dy: -1);
    v5 = rcWork.bottom - (2 * this->m_nTickHeight + 2);
    v6 = (rcWork.bottom - rcWork.top) / 2 + rcWork.top + 2;
    v7 = (rcWork.bottom - rcWork.top) / 2 + rcWork.top + 62;
    if ( v7 >= (rcWork.bottom - rcWork.top) / 2 + rcWork.top + 22 )
    {
      v16 = rcWork.bottom - (2 * this->m_nTickHeight + 2);
      if ( v7 <= v5 )
        v16 = (rcWork.bottom - rcWork.top) / 2 + rcWork.top + 62;
    }
    else
    {
      v16 = (rcWork.bottom - rcWork.top) / 2 + rcWork.top + 22;
    }
    v8 = y - this->m_nLastY;
    dfdxa = x - this->m_nLastX;
    TimePerPixel = PhonemeEditor::GetTimePerPixel(this);
    p_m_Tags = &this->m_Tags;
    dfdx = TimePerPixel * (double)dfdxa;
    dfdy = (float)v8 / (float)(v16 - v6);
    for ( i = 0; i < CSentence::GetNumSamples(this: p_m_Tags); ++i )
    {
      Sample = CSentence::GetSample(this: p_m_Tags, index: i);
      if ( Sample != nullptr && Sample->selected )
      {
        v13 = 0;
        Sample->time = dfdx + Sample->time;
        v14 = Sample->value - dfdy;
        Sample->value = v14;
        if ( v14 < 0.0 || (v13 = 1065353216, v14 > 1.0) )
          v14 = *(float *)&v13;
        Sample->value = v14;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046A5D0
// Name: private: void PhonemeEditor::Emphasis_Redraw(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::Emphasis_Redraw(
        PhonemeEditor *this,
        CChoreoWidgetDrawHelper *drawHelper,
        tagRECT *rcWorkSpace)
{
  PhonemeEditor::EditorMode m_CurrentMode; // eax
  int m_nTickHeight; // edx
  bool v6; // zf
  int bottom; // eax
  bool v8; // bl
  int v9; // edi
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // edi
  CSentence *p_m_Tags; // ebx
  int v15; // edi
  HWND Handle; // eax
  float v17; // xmm0_4
  int v18; // edi
  CEmphasisSample *Sample; // esi
  float time; // xmm0_4
  double Intensity; // st7
  double v22; // st7
  bool selected; // cl
  HBRUSH__ *v24; // edx
  Color *p_clrSelected; // ecx
  tagRECT rcText; // [esp+14h] [ebp-64h] BYREF
  tagRECT rcSpot; // [esp+24h] [ebp-54h] BYREF
  tagRECT rcClient; // [esp+34h] [ebp-44h] BYREF
  float timeperpixel; // [esp+44h] [ebp-34h]
  float starttime; // [esp+48h] [ebp-30h]
  Color clrSelected; // [esp+4Ch] [ebp-2Ch] BYREF
  Color clr; // [esp+50h] [ebp-28h] BYREF
  int x; // [esp+54h] [ebp-24h]
  int numsamples; // [esp+58h] [ebp-20h]
  int value; // [esp+5Ch] [ebp-1Ch]
  Color dotColorSelected; // [esp+60h] [ebp-18h]
  Color dotColor; // [esp+64h] [ebp-14h]
  float v38; // [esp+68h] [ebp-10h]
  Color lineColor; // [esp+6Ch] [ebp-Ch] BYREF
  Color gray; // [esp+70h] [ebp-8h] BYREF
  Color clr1; // [esp+74h] [ebp-4h] BYREF

  m_CurrentMode = this->m_CurrentMode;
  if ( (unsigned int)m_CurrentMode <= MODE_EMPHASIS )
  {
    m_nTickHeight = this->m_nTickHeight;
    v6 = m_CurrentMode == MODE_EMPHASIS;
    bottom = rcWorkSpace->bottom;
    v8 = v6;
    *(_QWORD *)&rcClient.left = *(_QWORD *)&rcWorkSpace->left;
    v9 = bottom - (2 * m_nTickHeight + 2);
    v10 = (bottom - rcWorkSpace->top) / 2 + rcWorkSpace->top + 2;
    v11 = v10 + 20;
    rcClient.top = v10;
    v12 = v10 + 60;
    *(_QWORD *)&rcClient.right = *(_QWORD *)&rcWorkSpace->right;
    if ( v12 >= v11 )
    {
      if ( v12 > v9 )
        v12 = v9;
    }
    else
    {
      v12 = v11;
    }
    rcClient.bottom = v12;
    rcText = rcClient;
    InflateRect(lprc: &rcText, dx: -15, dy: 0);
    OffsetRect(lprc: &rcText, dx: 0, dy: -20);
    rcText.bottom = rcText.top + 20;
    if ( v8 )
    {
      if ( g_PEColors[32].mode_number == -1 )
      {
        rcWorkSpace = (tagRECT *)g_PEColors[32].root_color;
      }
      else if ( g_PEColors[32].mode_number == this->m_CurrentMode )
      {
        rcWorkSpace = (tagRECT *)g_PEColors[32].root_color;
      }
      else
      {
        rcWorkSpace = (tagRECT *)g_PEColors[32].gray_color;
      }
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: drawHelper,
        font: "Arial",
        pointsize: 15,
        weight: 700,
        clr: (const Color *)&rcWorkSpace,
        &rcText,
        fmt: "Emphasis...");
    }
    v13 = (rcClient.bottom - rcClient.top) / 3;
    *(_QWORD *)&rcSpot.left = *(_QWORD *)&rcClient.left;
    rcSpot.right = _mm_loadl_epi64((const __m128i *)&rcClient.right).m128i_u32[0];
    rcSpot.bottom = v13 + rcClient.top;
    if ( g_PEColors[25].mode_number == -1 )
    {
      rcWorkSpace = (tagRECT *)g_PEColors[25].root_color;
    }
    else if ( g_PEColors[25].mode_number == this->m_CurrentMode )
    {
      rcWorkSpace = (tagRECT *)g_PEColors[25].root_color;
    }
    else
    {
      rcWorkSpace = (tagRECT *)g_PEColors[25].gray_color;
    }
    if ( g_PEColors[26].mode_number == -1 )
    {
      clr1 = g_PEColors[26].root_color;
    }
    else if ( g_PEColors[26].mode_number == this->m_CurrentMode )
    {
      clr1 = g_PEColors[26].root_color;
    }
    else
    {
      clr1 = g_PEColors[26].gray_color;
    }
    CChoreoWidgetDrawHelper::DrawGradientFilledRect(
      this: drawHelper,
      rc: &rcSpot,
      &clr1,
      clr2: (const Color *)&rcWorkSpace,
      vertical: true);
    OffsetRect(lprc: &rcSpot, dx: 0, dy: v13);
    if ( g_PEColors[25].mode_number == -1 )
    {
      rcWorkSpace = (tagRECT *)g_PEColors[25].root_color;
    }
    else if ( g_PEColors[25].mode_number == this->m_CurrentMode )
    {
      rcWorkSpace = (tagRECT *)g_PEColors[25].root_color;
    }
    else
    {
      rcWorkSpace = (tagRECT *)g_PEColors[25].gray_color;
    }
    CChoreoWidgetDrawHelper::DrawFilledRect(this: drawHelper, clr: (const Color *)&rcWorkSpace, rc: &rcSpot);
    OffsetRect(lprc: &rcSpot, dx: 0, dy: v13);
    if ( g_PEColors[27].mode_number == -1 )
    {
      rcWorkSpace = (tagRECT *)g_PEColors[27].root_color;
    }
    else if ( g_PEColors[27].mode_number == this->m_CurrentMode )
    {
      rcWorkSpace = (tagRECT *)g_PEColors[27].root_color;
    }
    else
    {
      rcWorkSpace = (tagRECT *)g_PEColors[27].gray_color;
    }
    if ( g_PEColors[25].mode_number == -1 )
    {
      clr1 = g_PEColors[25].root_color;
    }
    else if ( g_PEColors[25].mode_number == this->m_CurrentMode )
    {
      clr1 = g_PEColors[25].root_color;
    }
    else
    {
      clr1 = g_PEColors[25].gray_color;
    }
    CChoreoWidgetDrawHelper::DrawGradientFilledRect(
      this: drawHelper,
      rc: &rcSpot,
      &clr1,
      clr2: (const Color *)&rcWorkSpace,
      vertical: true);
    if ( g_PEColors[33].mode_number == -1 )
    {
      gray = g_PEColors[33].root_color;
    }
    else if ( g_PEColors[33].mode_number == this->m_CurrentMode )
    {
      gray = g_PEColors[33].root_color;
    }
    else
    {
      gray = g_PEColors[33].gray_color;
    }
    if ( g_PEColors[28].mode_number == -1 )
    {
      rcWorkSpace = (tagRECT *)g_PEColors[28].root_color;
    }
    else if ( g_PEColors[28].mode_number == this->m_CurrentMode )
    {
      rcWorkSpace = (tagRECT *)g_PEColors[28].root_color;
    }
    else
    {
      rcWorkSpace = (tagRECT *)g_PEColors[28].gray_color;
    }
    CChoreoWidgetDrawHelper::DrawOutlinedRect(
      this: drawHelper,
      clr: (Color *)&rcWorkSpace,
      style: 0,
      width: (HBRUSH__ *)1,
      rc: &rcClient);
    if ( g_PEColors[29].mode_number == -1 )
    {
      lineColor = g_PEColors[29].root_color;
    }
    else if ( g_PEColors[29].mode_number == this->m_CurrentMode )
    {
      lineColor = g_PEColors[29].root_color;
    }
    else
    {
      lineColor = g_PEColors[29].gray_color;
    }
    if ( g_PEColors[30].mode_number == -1 )
    {
      dotColor = g_PEColors[30].root_color;
    }
    else if ( g_PEColors[30].mode_number == this->m_CurrentMode )
    {
      dotColor = g_PEColors[30].root_color;
    }
    else
    {
      dotColor = g_PEColors[30].gray_color;
    }
    if ( g_PEColors[31].mode_number == -1 )
    {
      dotColorSelected = g_PEColors[31].root_color;
    }
    else if ( g_PEColors[31].mode_number == this->m_CurrentMode )
    {
      dotColorSelected = g_PEColors[31].root_color;
    }
    else
    {
      dotColorSelected = g_PEColors[31].gray_color;
    }
    CChoreoWidgetDrawHelper::DrawColoredLine(
      this: drawHelper,
      clr: (HPEN__ *)&gray,
      style: 0,
      width: 1,
      x1: rcClient.left,
      y1: (rcClient.top + rcClient.bottom) / 2,
      x2: rcClient.right,
      y2: (rcClient.top + rcClient.bottom) / 2);
    v6 = this->m_pWaveFile == nullptr;
    clrSelected = (Color)(rcClient.bottom - rcClient.top);
    clr = (Color)(rcClient.bottom - 1);
    if ( !v6 )
    {
      *(float *)&rcWorkSpace = this->m_pWaveFile->GetRunningLength(this: this->m_pWaveFile);
      timeperpixel = PhonemeEditor::GetTimePerPixel(this);
      starttime = (float)this->m_nLeftOffset
                / (float)((float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond);
      mxWidget::w2(this);
      p_m_Tags = &this->m_Tags;
      x = 0;
      *(float *)&numsamples = CSentence::GetIntensity(this: &this->m_Tags, time: starttime, endtime: (int)rcWorkSpace);
      v15 = 0;
      if ( mxWidget::w2(this) + 5 > 0 )
      {
        v38 = (float)(int)clr;
        *(float *)&clr1 = (float)(int)clrSelected;
        do
        {
          Handle = (HWND)mxWidget::getHandle(this);
          GetClientRect(hWnd: Handle, lpRect: &rcSpot);
          rcSpot.top += 60;
          rcSpot.bottom -= 95;
          InflateRect(lprc: &rcSpot, dx: -1, dy: -1);
          v17 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
          *(float *)&value = CSentence::GetIntensity(
                               this: &this->m_Tags,
                               time: (float)((float)this->m_nLeftOffset / v17) + (float)((float)v15 / v17),
                               endtime: (int)rcWorkSpace);
          CChoreoWidgetDrawHelper::DrawColoredLine(
            this: drawHelper,
            clr: (HPEN__ *)&lineColor,
            style: 0,
            width: 1,
            x1: x,
            y1: (int)(float)(v38 - (float)(*(float *)&clr1 * *(float *)&numsamples)),
            x2: v15,
            y2: (int)(float)(v38 - (float)(*(float *)&clr1 * *(float *)&value)));
          x = v15;
          numsamples = value;
          v15 += 5;
        }
        while ( v15 < mxWidget::w2(this) + 5 );
      }
      v18 = 0;
      *(float *)&numsamples = COERCE_FLOAT(CSentence::GetNumSamples(this: &this->m_Tags));
      if ( numsamples > 0 )
      {
        timeperpixel = 1.0 / timeperpixel;
        v38 = (float)(int)clr;
        *(float *)&clr1 = (float)(int)clrSelected;
        do
        {
          Sample = CSentence::GetSample(this: p_m_Tags, index: v18);
          time = Sample->time;
          x = (int)(float)((float)(Sample->time - starttime) * timeperpixel);
          Intensity = CSentence::GetIntensity(this: p_m_Tags, time, endtime: (int)rcWorkSpace);
          v22 = v38 - Intensity * *(float *)&clr1;
          clr = dotColor;
          clrSelected = dotColorSelected;
          selected = Sample->selected;
          v24 = (HBRUSH__ *)(selected + 4);
          v6 = !selected;
          p_clrSelected = &clrSelected;
          if ( v6 )
            p_clrSelected = &clr;
          CChoreoWidgetDrawHelper::DrawCircle(
            this: drawHelper,
            clr: p_clrSelected,
            (HPEN__ *)x,
            y: (HBRUSH__ *)(int)v22,
            radius: v24,
            filled: true);
          ++v18;
        }
        while ( v18 < numsamples );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046ABF0
// Name: private: void PhonemeEditor::Emphasis_SelectPoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::Emphasis_SelectPoints(PhonemeEditor *this)
{
  HWND Handle; // eax
  int v3; // edi
  int v4; // eax
  int m_nStartX; // ecx
  int m_nLastX; // edx
  int m_nStartY; // ecx
  int m_nLastY; // edx
  int v9; // ebx
  int v10; // ebx
  float v11; // xmm0_4
  float v12; // xmm1_4
  int i; // edi
  CEmphasisSample *Sample; // eax
  float v15; // xmm0_4
  tagRECT rcWork; // [esp+4h] [ebp-30h] BYREF
  tagRECT rcSelection; // [esp+14h] [ebp-20h] BYREF
  float fright; // [esp+24h] [ebp-10h]
  float fleft; // [esp+28h] [ebp-Ch]
  float v20; // [esp+2Ch] [ebp-8h]
  float v21; // [esp+30h] [ebp-4h]

  if ( this->m_CurrentMode == MODE_EMPHASIS )
  {
    Handle = (HWND)mxWidget::getHandle(this);
    GetClientRect(hWnd: Handle, lpRect: &rcWork);
    rcWork.top += 60;
    rcWork.bottom -= 95;
    InflateRect(lprc: &rcWork, dx: -1, dy: -1);
    v3 = (rcWork.bottom - rcWork.top) / 2 + rcWork.top + 2;
    v4 = (rcWork.bottom - rcWork.top) / 2 + rcWork.top + 62;
    if ( v4 >= (rcWork.bottom - rcWork.top) / 2 + rcWork.top + 22 )
    {
      if ( v4 > rcWork.bottom - (2 * this->m_nTickHeight + 2) )
        v4 = rcWork.bottom - (2 * this->m_nTickHeight + 2);
    }
    else
    {
      v4 = (rcWork.bottom - rcWork.top) / 2 + rcWork.top + 22;
    }
    m_nStartX = this->m_nStartX;
    m_nLastX = this->m_nLastX;
    rcSelection.left = m_nStartX;
    if ( m_nStartX < m_nLastX )
    {
      rcSelection.right = m_nLastX;
    }
    else
    {
      rcSelection.left = m_nLastX;
      rcSelection.right = m_nStartX;
    }
    m_nStartY = this->m_nStartY;
    m_nLastY = this->m_nLastY;
    v9 = m_nStartY;
    if ( m_nStartY >= m_nLastY )
      v9 = this->m_nLastY;
    rcSelection.top = v9;
    if ( m_nStartY < m_nLastY )
      m_nStartY = m_nLastY;
    rcSelection.bottom = m_nStartY;
    if ( v9 <= v3 )
      rcSelection.top = (rcWork.bottom - rcWork.top) / 2 + rcWork.top + 2;
    if ( m_nStartY >= v4 )
      rcSelection.bottom = v4;
    v10 = v4 - v3;
    InflateRect(lprc: &rcSelection, dx: 5, dy: 5);
    if ( mxWidget::w2(this) != 0 && mxWidget::h2(this) != 0 )
    {
      fleft = PhonemeEditor::GetTimeForPixel(this, mx: rcSelection.left);
      fright = PhonemeEditor::GetTimeForPixel(this, mx: rcSelection.right);
      v11 = (float)(rcSelection.top - v3) / (float)v10;
      v12 = (float)(rcSelection.bottom - v3) / (float)v10;
      if ( v11 >= 0.0 )
      {
        if ( v11 <= 1.0 )
          v21 = (float)(rcSelection.top - v3) / (float)v10;
        else
          v21 = 1.0;
      }
      else
      {
        v21 = 0.0;
      }
      if ( v12 >= 0.0 )
      {
        if ( v12 <= 1.0 )
          v20 = (float)(rcSelection.bottom - v3) / (float)v10;
        else
          v20 = 1.0;
      }
      else
      {
        v20 = 0.0;
      }
      for ( i = 0; i < CSentence::GetNumSamples(this: &this->m_Tags); ++i )
      {
        Sample = CSentence::GetSample(this: &this->m_Tags, index: i);
        if ( fleft <= (float)(Sample->time + 0.0049999999) && (float)(Sample->time - 0.0049999999) <= fright )
        {
          v15 = 1.0 - Sample->value;
          if ( v21 <= (float)(v15 + 0.0049999999) && (float)(v15 - 0.0049999999) <= v20 )
            Sample->selected = true;
        }
      }
      this->redraw(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046AE00
// Name: private: void PhonemeEditor::GetScrubHandleRect(struct tagRECT __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge PhonemeEditor::GetScrubHandleRect(
        PhonemeEditor *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        tagRECT *rcHandle,
        bool clipped)
{
  float v5; // xmm0_4
  float v7; // xmm0_4
  int v8; // eax
  int v9; // eax
  float screenfrac; // [esp+0h] [ebp-Ch]
  float screenfraca; // [esp+0h] [ebp-Ch]
  float screenfracb; // [esp+0h] [ebp-Ch]
  float starttime; // [esp+4h] [ebp-8h]

  v5 = 0.0;
  if ( this->m_pWaveFile != nullptr )
  {
    v7 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
    starttime = (float)this->m_nLeftOffset / v7;
    screenfraca = this->m_flScrub - starttime;
    screenfracb = screenfraca / (float)((float)((float)((float)mxWidget::w2(this) / v7) + starttime) - starttime);
    v5 = (float)mxWidget::w2(this) * screenfracb;
    screenfrac = v5;
    if ( clipped )
    {
      v8 = mxWidget::w2(this) - 20;
      if ( v5 >= 20.0 )
      {
        if ( v5 > (float)v8 )
          v5 = (float)v8;
      }
      else
      {
        v5 = 20.0;
      }
    }
  }
  rcHandle->right = (int)(float)(v5 + 20.0);
  rcHandle->left = (int)(float)(v5 - 20.0);
  v9 = ((int (__thiscall *)(IFacePoserToolWindow *, int, int, _DWORD))this->GetCaptionHeight)(
         a1: &this->IFacePoserToolWindow,
         a2,
         a3,
         a4: LODWORD(screenfrac))
     + 14;
  rcHandle->top = v9;
  rcHandle->bottom = v9 + 10;
}

//------------------------------------------------------------------------------
// Address: 0x0046AF30
// Name: private: void PhonemeEditor::DrawScrubHandle(class CChoreoWidgetDrawHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge PhonemeEditor::DrawScrubHandle(
        PhonemeEditor *this@<ecx>,
        int a2@<edi>,
        CChoreoWidgetDrawHelper *drawHelper)
{
  HBRUSH SolidBrush; // eax
  HBRUSH__ *v5; // ebx
  int v6; // eax
  CChoreoWidgetDrawHelper *v7; // edi
  int v8; // eax
  int v9; // eax
  int top; // [esp+4h] [ebp-54h]
  int bottom; // [esp+4h] [ebp-54h]
  char sz[32]; // [esp+14h] [ebp-44h] BYREF
  tagRECT rcText; // [esp+34h] [ebp-24h] BYREF
  tagRECT rcHandle; // [esp+44h] [ebp-14h] BYREF
  Color areaBorder; // [esp+54h] [ebp-4h] BYREF

  PhonemeEditor::GetScrubHandleRect(this, a2, a3: (int)this, &rcHandle, clipped: true);
  SolidBrush = CreateSolidBrush(color: (COLORREF)&g_flexedverts[1250].z);
  top = rcHandle.top;
  v5 = SolidBrush;
  areaBorder = (Color)14477030;
  v6 = mxWidget::w2(this);
  v7 = drawHelper;
  CChoreoWidgetDrawHelper::DrawColoredLine(
    this: drawHelper,
    clr: (HPEN__ *)&areaBorder,
    style: 0,
    width: 1,
    x1: 0,
    y1: rcHandle.top,
    x2: v6,
    y2: top);
  bottom = rcHandle.bottom;
  v8 = mxWidget::w2(this);
  CChoreoWidgetDrawHelper::DrawColoredLine(
    this: v7,
    clr: (HPEN__ *)&areaBorder,
    style: 0,
    width: 1,
    x1: 0,
    y1: rcHandle.bottom,
    x2: v8,
    y2: bottom);
  CChoreoWidgetDrawHelper::DrawFilledRect(this: v7, br: v5, rc: &rcHandle);
  sprintf(string: sz, format: "%.3f", this->m_flScrub);
  v9 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 500, fmt: sz);
  rcText.top = rcHandle.top;
  rcText.left = rcHandle.left + (rcHandle.right - rcHandle.left - v9) / 2;
  *(_QWORD *)&rcText.right = *(_QWORD *)&rcHandle.right;
  drawHelper = (CChoreoWidgetDrawHelper *)0xFFFFFF;
  CChoreoWidgetDrawHelper::DrawColoredText(
    this: v7,
    font: "Arial",
    pointsize: 9,
    weight: 500,
    clr: (const Color *)&drawHelper,
    &rcText,
    fmt: sz);
  DeleteObject(ho: v5);
}

//------------------------------------------------------------------------------
// Address: 0x0046B050
// Name: private: bool PhonemeEditor::IsMouseOverScrubHandle(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge PhonemeEditor::IsMouseOverScrubHandle@<al>(
        PhonemeEditor *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        mxEvent *event)
{
  POINT v5; // [esp-8h] [ebp-18h]
  tagRECT rcHandle; // [esp+0h] [ebp-10h] BYREF

  PhonemeEditor::GetScrubHandleRect(this, a2, a3, &rcHandle, clipped: true);
  InflateRect(lprc: &rcHandle, dx: 2, dy: 2);
  v5.y = SLOWORD(event->y);
  v5.x = SLOWORD(event->x);
  return PtInRect(lprc: &rcHandle, pt: v5);
}

//------------------------------------------------------------------------------
// Address: 0x0046B0A0
// Name: private: void PhonemeEditor::ClampTimeToSelectionInterval(float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ClampTimeToSelectionInterval(PhonemeEditor *this, float *timeval)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float endtime; // [esp+4h] [ebp-8h]
  float starttime; // [esp+8h] [ebp-4h]

  if ( this->m_pWaveFile != nullptr
    && this->m_pMixer != nullptr
    && sound->IsSoundPlaying(this: sound, a2: this->m_pMixer)
    && this->m_bSelectionActive )
  {
    starttime = PhonemeEditor::GetTimeForSample(this, sample: this->m_nSelection[0]);
    endtime = PhonemeEditor::GetTimeForSample(this, sample: this->m_nSelection[1]);
    v3 = *timeval;
    v4 = starttime;
    if ( starttime > *timeval || (v4 = endtime, v3 > endtime) )
      v3 = v4;
    *timeval = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046B130
// Name: private: void PhonemeEditor::DrawWords(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &,class CSentence __near &,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::DrawWords(
        PhonemeEditor *this,
        CChoreoWidgetDrawHelper *drawHelper,
        tagRECT *rcWorkSpace,
        CSentence *sentence,
        Color type,
        bool showactive)
{
  int v7; // xmm0_4
  float v8; // xmm1_4
  int v9; // eax
  float v10; // xmm3_4
  int m_nTickHeight; // esi
  int top; // ecx
  float v13; // xmm6_4
  int v14; // ebx
  int v15; // edx
  CSentence *v16; // eax
  int v17; // ecx
  CWordTag *v18; // eax
  int m_Size; // edi
  int v20; // esi
  float v21; // xmm0_4
  float right; // xmm4_4
  int v23; // esi
  float v24; // xmm2_4
  int v25; // edi
  bool v26; // zf
  PhonemeEditorColor *v27; // eax
  int mode_number; // ecx
  BOOL m_bSelected; // eax
  unsigned int v30; // eax
  PhonemeEditorColor *v31; // eax
  int v32; // ecx
  Color v33; // ecx
  Color gray_color; // eax
  Color root_color; // eax
  int v36; // eax
  char *v37; // eax
  int v38; // ecx
  int v39; // eax
  int v40; // edi
  int v41; // eax
  unsigned int v42; // eax
  PhonemeEditorColor *v43; // eax
  int v44; // edx
  Color v45; // eax
  char *v46; // eax
  tagRECT rcWord; // [esp+8h] [ebp-50h] BYREF
  tagRECT rcText; // [esp+18h] [ebp-40h] BYREF
  float endtime; // [esp+28h] [ebp-30h]
  int pass; // [esp+2Ch] [ebp-2Ch]
  int k; // [esp+30h] [ebp-28h]
  float starttime; // [esp+34h] [ebp-24h]
  CWordTag *word; // [esp+38h] [ebp-20h]
  Color v54; // [esp+3Ch] [ebp-1Ch]
  Color v55; // [esp+40h] [ebp-18h]
  Color clr; // [esp+44h] [ebp-14h] BYREF
  int v57; // [esp+48h] [ebp-10h]
  Color border; // [esp+4Ch] [ebp-Ch] BYREF
  PhonemeEditor *v59; // [esp+50h] [ebp-8h]
  bool drawselected; // [esp+57h] [ebp-1h]

  *(float *)&v7 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
  v8 = (float)this->m_nLeftOffset / *(float *)&v7;
  v59 = this;
  starttime = v8;
  pass = v7;
  v9 = mxWidget::w2(this);
  v10 = v8;
  m_nTickHeight = this->m_nTickHeight;
  top = rcWorkSpace->top;
  v13 = (float)((float)v9 / *(float *)&v7) + v8;
  endtime = v13;
  v14 = top + m_nTickHeight + 2;
  if ( type == 1 )
    v14 += m_nTickHeight + 5;
  v15 = 0;
  pass = 0;
  do
  {
    v16 = sentence;
    drawselected = v15 != 0;
    v17 = 0;
    k = 0;
    if ( sentence->m_Words.m_Size <= 0 )
      goto LABEL_58;
    do
    {
      v18 = v16->m_Words.m_Memory.m_pMemory[v17];
      word = v18;
      if ( v18 != nullptr && v18->m_bSelected == drawselected )
      {
        m_Size = v18->m_Phonemes.m_Size;
        v20 = 0;
        for ( type._color[3] = 0; v20 < m_Size; type._color[3] = v18->m_Phonemes.m_Memory.m_pMemory[v20++]->m_bSelected )
        {
          if ( type._color[3] != 0 )
            break;
        }
        v21 = (float)(v18->m_flStartTime - v10) / (float)(v13 - v10);
        right = (float)rcWorkSpace->right;
        v23 = (int)(float)(right * v21);
        if ( v21 <= 0.0 )
          v23 = 0;
        v24 = (float)(v18->m_flEndTime - v10) / (float)(v13 - v10);
        if ( v24 >= 0.0 )
        {
          rcWord.top = v14 - v59->m_nTickHeight + 1;
          v25 = (int)(float)(right * v24);
          rcWord.left = v23;
          rcWord.right = v25;
          rcWord.bottom = v14;
          v26 = !v18->m_bSelected;
          v57 = 0;
          v27 = &g_PEColors[!v26 + 14];
          mode_number = v27->mode_number;
          if ( mode_number == -1 )
          {
            clr = v27->root_color;
          }
          else if ( mode_number == v59->m_CurrentMode )
          {
            clr = v27->root_color;
          }
          else
          {
            clr = v27->gray_color;
          }
          CChoreoWidgetDrawHelper::DrawFilledRect(this: drawHelper, &clr, rc: &rcWord);
          m_bSelected = word->m_bSelected;
          v55 = 0;
          v30 = m_bSelected + 12;
          if ( v30 > 0x21 )
          {
            v33 = v55;
          }
          else
          {
            v31 = &g_PEColors[v30];
            v32 = v31->mode_number;
            if ( v32 == -1 )
            {
              border = v31->root_color;
LABEL_26:
              if ( !showactive || !v59->m_bWordsActive )
              {
LABEL_35:
                CChoreoWidgetDrawHelper::DrawColoredLine(
                  this: drawHelper,
                  clr: (HPEN__ *)&border,
                  style: 0,
                  width: 1,
                  x1: v23,
                  y1: v14,
                  x2: v25,
                  y2: v14);
                CChoreoWidgetDrawHelper::DrawColoredLine(
                  this: drawHelper,
                  clr: (HPEN__ *)&border,
                  style: 0,
                  width: 1,
                  x1: v23,
                  y1: v14,
                  x2: v23,
                  y2: v14 - v59->m_nTickHeight);
                CChoreoWidgetDrawHelper::DrawColoredLine(
                  this: drawHelper,
                  clr: (HPEN__ *)&border,
                  style: 0,
                  width: 1,
                  x1: v25,
                  y1: v14,
                  x2: v25,
                  y2: v14 - v59->m_nTickHeight);
                CChoreoWidgetDrawHelper::DrawColoredLine(
                  this: drawHelper,
                  clr: (HPEN__ *)&border,
                  style: 0,
                  width: 1,
                  x1: v23,
                  y1: v14 - v59->m_nTickHeight,
                  x2: v25,
                  y2: v14 - v59->m_nTickHeight);
                if ( type._color[3] == 0 )
                  goto LABEL_43;
                if ( g_PEColors[23].mode_number == -1 )
                {
                  root_color = g_PEColors[23].root_color;
                }
                else
                {
                  if ( g_PEColors[23].mode_number == v59->m_CurrentMode )
                  {
                    type = g_PEColors[23].root_color;
LABEL_42:
                    CChoreoWidgetDrawHelper::DrawFilledRect(
                      this: drawHelper,
                      clr: &type,
                      x1: v23,
                      y1: v14 - 3,
                      x2: v25,
                      y2: v14);
LABEL_43:
                    v36 = v14 - v59->m_nTickHeight + 4;
                    rcText.left = v23;
                    rcText.top = v36;
                    rcText.right = v23 + 500;
                    rcText.bottom = v36 + 11;
                    v37 = CWordTag::GetWord(this: word);
                    v38 = CChoreoWidgetDrawHelper::CalcTextWidth(
                            font: "Arial",
                            pointsize: (HFONT__ *)9,
                            weight: 400,
                            fmt: "%s",
                            v37);
                    v39 = v38 + rcText.left + 1;
                    v40 = v25 - 2;
                    if ( v40 > v39 )
                      v39 = v40;
                    rcText.right = v39;
                    v41 = v39 - rcText.left;
                    if ( v41 > v38 )
                      rcText.left += (v41 - v38) / 2;
                    v26 = !word->m_bSelected;
                    v54 = 0;
                    v42 = !v26 + 16;
                    if ( v42 > 0x21 )
                    {
                      v45 = v54;
                    }
                    else
                    {
                      v43 = &g_PEColors[v42];
                      v44 = v43->mode_number;
                      if ( v44 == -1 )
                      {
                        type = v43->root_color;
LABEL_55:
                        v46 = CWordTag::GetWord(this: word);
                        CChoreoWidgetDrawHelper::DrawColoredText(
                          this: drawHelper,
                          font: "Arial",
                          pointsize: 9,
                          weight: 400,
                          clr: &type,
                          &rcText,
                          fmt: "%s",
                          v46);
                        v13 = endtime;
                        v10 = starttime;
                        v17 = k;
                        goto LABEL_56;
                      }
                      if ( v44 != v59->m_CurrentMode )
                      {
                        type = v43->gray_color;
                        goto LABEL_55;
                      }
                      v45 = v43->root_color;
                    }
                    type = v45;
                    goto LABEL_55;
                  }
                  root_color = g_PEColors[23].gray_color;
                }
                type = root_color;
                goto LABEL_42;
              }
              if ( g_PEColors[22].mode_number == -1 )
              {
                gray_color = g_PEColors[22].root_color;
              }
              else
              {
                if ( g_PEColors[22].mode_number == v59->m_CurrentMode )
                {
                  clr = g_PEColors[22].root_color;
LABEL_34:
                  CChoreoWidgetDrawHelper::DrawFilledRect(
                    this: drawHelper,
                    &clr,
                    x1: v23,
                    y1: v14 - v59->m_nTickHeight,
                    x2: v25,
                    y2: v14 - v59->m_nTickHeight + 4);
                  goto LABEL_35;
                }
                gray_color = g_PEColors[22].gray_color;
              }
              clr = gray_color;
              goto LABEL_34;
            }
            if ( v32 != v59->m_CurrentMode )
            {
              border = v31->gray_color;
              goto LABEL_26;
            }
            v33 = v31->root_color;
          }
          border = v33;
          goto LABEL_26;
        }
      }
LABEL_56:
      v16 = sentence;
      k = ++v17;
    }
    while ( v17 < sentence->m_Words.m_Size );
    v15 = pass;
LABEL_58:
    pass = ++v15;
  }
  while ( v15 < 2 );
}

//------------------------------------------------------------------------------
// Address: 0x0046B560
// Name: private: void PhonemeEditor::DrawPhonemes(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &,class CSentence __near &,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::DrawPhonemes(
        PhonemeEditor *this,
        CChoreoWidgetDrawHelper *drawHelper,
        tagRECT *rcWorkSpace,
        CSentence *sentence,
        int type,
        bool showactive)
{
  int v7; // xmm0_4
  float v8; // xmm1_4
  int v9; // eax
  int m_nTickHeight; // esi
  float v11; // xmm4_4
  int v12; // edi
  float v13; // xmm3_4
  int v14; // ecx
  CSentence *v15; // esi
  int v16; // eax
  CWordTag *v17; // ecx
  int v18; // edx
  float v19; // xmm3_4
  CPhonemeTag *v20; // eax
  float m_flEndTime; // xmm1_4
  float v22; // xmm0_4
  float right; // xmm2_4
  int v24; // esi
  float v25; // xmm1_4
  int v26; // ebx
  bool v27; // zf
  PhonemeEditorColor *v28; // eax
  int mode_number; // ecx
  PhonemeEditorColor *v30; // eax
  int v31; // ecx
  Color gray_color; // eax
  int v33; // eax
  const char *v34; // eax
  int v35; // ecx
  int v36; // eax
  int v37; // ebx
  int v38; // eax
  int v39; // edx
  unsigned int v40; // eax
  PhonemeEditorColor *v41; // eax
  int v42; // ecx
  Color root_color; // ecx
  const char *v44; // eax
  int m_nPhonemeCode; // [esp-8h] [ebp-68h]
  tagRECT rcFrame; // [esp+8h] [ebp-58h] BYREF
  tagRECT rcText; // [esp+18h] [ebp-48h] BYREF
  float endtime; // [esp+28h] [ebp-38h]
  float v49; // [esp+2Ch] [ebp-34h]
  int pass; // [esp+30h] [ebp-30h]
  int i; // [esp+34h] [ebp-2Ch]
  int k; // [esp+38h] [ebp-28h]
  CWordTag *w; // [esp+3Ch] [ebp-24h]
  float starttime; // [esp+40h] [ebp-20h]
  CPhonemeTag *pPhoneme; // [esp+44h] [ebp-1Ch]
  Color v56; // [esp+48h] [ebp-18h]
  int v57; // [esp+4Ch] [ebp-14h]
  Color clr; // [esp+50h] [ebp-10h] BYREF
  int v59; // [esp+54h] [ebp-Ch]
  Color border; // [esp+58h] [ebp-8h] BYREF
  PhonemeEditor *v61; // [esp+5Ch] [ebp-4h]
  bool drawselected_3; // [esp+77h] [ebp+17h]

  *(float *)&v7 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
  v8 = (float)this->m_nLeftOffset / *(float *)&v7;
  v61 = this;
  starttime = v8;
  pass = v7;
  v9 = mxWidget::w2(this);
  m_nTickHeight = this->m_nTickHeight;
  v11 = v8;
  v12 = rcWorkSpace->bottom - m_nTickHeight - 2;
  v13 = (float)((float)v9 / *(float *)&v7) + v8;
  endtime = v13;
  if ( type == 1 )
    v12 += -5 - m_nTickHeight;
  v14 = 0;
  pass = 0;
  do
  {
    v15 = sentence;
    drawselected_3 = v14 != 0;
    v16 = 0;
    i = 0;
    if ( sentence->m_Words.m_Size <= 0 )
      goto LABEL_55;
    do
    {
      v17 = v15->m_Words.m_Memory.m_pMemory[v16];
      w = v17;
      if ( v17 != nullptr && v17->m_bSelected == drawselected_3 )
      {
        v18 = 0;
        k = 0;
        if ( v17->m_Phonemes.m_Size > 0 )
        {
          v19 = v13 - v11;
          v49 = v19;
          while ( 1 )
          {
            v20 = v17->m_Phonemes.m_Memory.m_pMemory[v18];
            m_flEndTime = v20->m_flEndTime;
            v22 = (float)(v20->m_flStartTime - v11) / v19;
            right = (float)rcWorkSpace->right;
            pPhoneme = v20;
            v24 = (int)(float)(right * v22);
            if ( v22 <= 0.0 )
              v24 = 0;
            v25 = (float)(m_flEndTime - v11) / v19;
            if ( v25 < 0.0 )
              goto LABEL_51;
            rcFrame.top = v12 - v61->m_nTickHeight + 1;
            v26 = (int)(float)(right * v25);
            rcFrame.left = v24;
            rcFrame.right = v26;
            rcFrame.bottom = v12;
            v27 = !v20->m_bSelected;
            v59 = 0;
            v28 = &g_PEColors[!v27 + 14];
            mode_number = v28->mode_number;
            if ( mode_number == -1 )
            {
              clr = v28->root_color;
            }
            else if ( mode_number == v61->m_CurrentMode )
            {
              clr = v28->root_color;
            }
            else
            {
              clr = v28->gray_color;
            }
            CChoreoWidgetDrawHelper::DrawFilledRect(this: drawHelper, &clr, rc: &rcFrame);
            v27 = !pPhoneme->m_bSelected;
            v57 = 0;
            v30 = &g_PEColors[!v27 + 12];
            v31 = v30->mode_number;
            if ( v31 == -1 )
            {
              border = v30->root_color;
            }
            else if ( v31 == v61->m_CurrentMode )
            {
              border = v30->root_color;
            }
            else
            {
              border = v30->gray_color;
            }
            if ( showactive && !v61->m_bWordsActive )
            {
              if ( g_PEColors[22].mode_number == -1 )
              {
                clr = g_PEColors[22].root_color;
              }
              else if ( g_PEColors[22].mode_number == v61->m_CurrentMode )
              {
                clr = g_PEColors[22].root_color;
              }
              else
              {
                clr = g_PEColors[22].gray_color;
              }
              CChoreoWidgetDrawHelper::DrawFilledRect(this: drawHelper, &clr, x1: v24, y1: v12 - 3, x2: v26, y2: v12);
            }
            CChoreoWidgetDrawHelper::DrawColoredLine(
              this: drawHelper,
              clr: (HPEN__ *)&border,
              style: 0,
              width: 1,
              x1: v24,
              y1: v12 - v61->m_nTickHeight,
              x2: v26,
              y2: v12 - v61->m_nTickHeight);
            CChoreoWidgetDrawHelper::DrawColoredLine(
              this: drawHelper,
              clr: (HPEN__ *)&border,
              style: 0,
              width: 1,
              x1: v24,
              y1: v12,
              x2: v24,
              y2: v12 - v61->m_nTickHeight);
            CChoreoWidgetDrawHelper::DrawColoredLine(
              this: drawHelper,
              clr: (HPEN__ *)&border,
              style: 0,
              width: 1,
              x1: v26,
              y1: v12,
              x2: v26,
              y2: v12 - v61->m_nTickHeight);
            CChoreoWidgetDrawHelper::DrawColoredLine(
              this: drawHelper,
              clr: (HPEN__ *)&border,
              style: 0,
              width: 1,
              x1: v24,
              y1: v12,
              x2: v26,
              y2: v12);
            if ( w->m_bSelected )
              break;
LABEL_38:
            v33 = v12 - v61->m_nTickHeight;
            rcText.left = v24;
            rcText.top = v33 + 4;
            rcText.bottom = v33 + 15;
            m_nPhonemeCode = pPhoneme->m_nPhonemeCode;
            rcText.right = v24 + 500;
            v34 = ConvertPhoneme(code: m_nPhonemeCode);
            v35 = CChoreoWidgetDrawHelper::CalcTextWidth(
                    font: "Arial",
                    pointsize: (HFONT__ *)9,
                    weight: 400,
                    fmt: "%s",
                    v34);
            v36 = v35 + rcText.left + 1;
            v37 = v26 - 2;
            if ( v37 > v36 )
              v36 = v37;
            rcText.right = v36;
            v38 = v36 - rcText.left;
            if ( v38 > v35 )
              rcText.left += (v38 - v35) / 2;
            v39 = pPhoneme->m_nPhonemeCode;
            v27 = !pPhoneme->m_bSelected;
            v56 = 0;
            v40 = !v27 + 16;
            if ( v40 > 0x21 )
            {
              root_color = v56;
              goto LABEL_49;
            }
            v41 = &g_PEColors[v40];
            v42 = v41->mode_number;
            if ( v42 == -1 )
            {
              clr = v41->root_color;
            }
            else
            {
              if ( v42 == v61->m_CurrentMode )
              {
                root_color = v41->root_color;
LABEL_49:
                clr = root_color;
                goto LABEL_50;
              }
              clr = v41->gray_color;
            }
LABEL_50:
            v44 = ConvertPhoneme(code: v39);
            CChoreoWidgetDrawHelper::DrawColoredText(
              this: drawHelper,
              font: "Arial",
              pointsize: 9,
              weight: 400,
              &clr,
              &rcText,
              fmt: "%s",
              v44);
            v19 = v49;
            v11 = starttime;
            v17 = w;
            v18 = k;
LABEL_51:
            k = ++v18;
            if ( v18 >= v17->m_Phonemes.m_Size )
            {
              v13 = endtime;
              v16 = i;
              v15 = sentence;
              goto LABEL_53;
            }
          }
          if ( g_PEColors[23].mode_number == -1 )
          {
            gray_color = g_PEColors[23].root_color;
          }
          else
          {
            if ( g_PEColors[23].mode_number == v61->m_CurrentMode )
            {
              clr = g_PEColors[23].root_color;
LABEL_37:
              CChoreoWidgetDrawHelper::DrawFilledRect(
                this: drawHelper,
                &clr,
                x1: v24,
                y1: v12 - v61->m_nTickHeight + 1,
                x2: v26,
                y2: v12 - v61->m_nTickHeight + 4);
              goto LABEL_38;
            }
            gray_color = g_PEColors[23].gray_color;
          }
          clr = gray_color;
          goto LABEL_37;
        }
      }
LABEL_53:
      i = ++v16;
    }
    while ( v16 < v15->m_Words.m_Size );
    v14 = pass;
LABEL_55:
    pass = ++v14;
  }
  while ( v14 < 2 );
}

//------------------------------------------------------------------------------
// Address: 0x0046B9C0
// Name: private: void PhonemeEditor::DrawRelativeTags(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::DrawRelativeTags(PhonemeEditor *this, CChoreoWidgetDrawHelper *drawHelper, tagRECT *rc)
{
  PhonemeEditor *v3; // esi
  bool v4; // zf
  int v6; // eax
  CChoreoEvent *m_pEvent; // ecx
  CEventAbsoluteTag *RelativeTag; // ebx
  double Percentage; // st7
  double v10; // st7
  int v11; // esi
  int bottom; // eax
  const char *Name; // eax
  int v14; // eax
  int v15; // esi
  Color gray_color; // ecx
  const char *v17; // eax
  CChoreoEvent *v18; // ecx
  int v19; // ebx
  tagRECT rcText; // [esp+4h] [ebp-30h] BYREF
  tagRECT rcMark; // [esp+14h] [ebp-20h] BYREF
  float endtime; // [esp+24h] [ebp-10h]
  int i; // [esp+28h] [ebp-Ch]
  PhonemeEditor *v24; // [esp+2Ch] [ebp-8h]
  Color tagtime; // [esp+30h] [ebp-4h] BYREF
  float starttime; // [esp+40h] [ebp+Ch]

  v3 = this;
  v4 = this->m_pEvent == nullptr;
  v24 = this;
  if ( !v4 && this->m_pWaveFile != nullptr )
  {
    if ( g_PEColors[24].mode_number == -1 )
      tagtime = g_PEColors[24].root_color;
    else
      tagtime = g_PEColors[24].mode_number == this->m_CurrentMode
              ? g_PEColors[24].root_color
              : g_PEColors[24].gray_color;
    CChoreoWidgetDrawHelper::DrawColoredText(
      this: drawHelper,
      font: "Arial",
      pointsize: 9,
      weight: 400,
      clr: &tagtime,
      rcText: rc,
      fmt: "Timing Tags:");
    starttime = (float)v3->m_nLeftOffset
              / (float)((float)((float)v3->m_nTimeZoom * 0.0099999998) * v3->m_flPixelsPerSecond);
    *(float *)&i = (float)((float)v3->m_nTimeZoom * 0.0099999998) * v3->m_flPixelsPerSecond;
    v6 = mxWidget::w2(this: v3);
    m_pEvent = v3->m_pEvent;
    endtime = (float)((float)v6 / *(float *)&i) + starttime;
    *(float *)&i = 0.0;
    if ( CChoreoEvent::GetNumRelativeTags(this: m_pEvent) > 0 )
    {
      while ( 1 )
      {
        RelativeTag = (CEventAbsoluteTag *)CChoreoEvent::GetRelativeTag(this: v3->m_pEvent, tagnum: i);
        if ( RelativeTag == nullptr )
          goto LABEL_24;
        *(float *)&tagtime = v3->m_pWaveFile->GetRunningLength(this: v3->m_pWaveFile);
        Percentage = CEventAbsoluteTag::GetPercentage(this: RelativeTag);
        v10 = Percentage * *(float *)&tagtime;
        *(float *)&tagtime = v10;
        if ( starttime > v10 || *(float *)&tagtime > endtime )
          goto LABEL_24;
        v11 = rc->left
            + (int)(float)((float)((float)((float)(*(float *)&tagtime - starttime) / (float)(endtime - starttime))
                                 * (float)(rc->right - rc->left))
                         + 0.5);
        rcMark.bottom = rc->bottom;
        rcMark.left = v11 - 4;
        rcMark.top = rcMark.bottom - 8;
        rcMark.right = v11 + 4;
        if ( g_PEColors[24].mode_number == -1 )
          tagtime = g_PEColors[24].root_color;
        else
          tagtime = g_PEColors[24].mode_number == v24->m_CurrentMode
                  ? g_PEColors[24].root_color
                  : g_PEColors[24].gray_color;
        CChoreoWidgetDrawHelper::DrawTriangleMarker(this: drawHelper, rc: &rcMark, fill: &tagtime, inverted: false);
        bottom = rc->bottom;
        *(_QWORD *)&rcText.left = *(_QWORD *)&rc->left;
        rcText.right = _mm_loadl_epi64((const __m128i *)&rc->right).m128i_u32[0];
        rcText.bottom = bottom - 10;
        rcText.top = bottom - 20;
        Name = CEventAbsoluteTag::GetName(this: RelativeTag);
        v14 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 400, fmt: Name);
        v15 = v11 - v14 / 2;
        rcText.right = v15 + v14 + 2;
        rcText.left = v15;
        if ( g_PEColors[24].mode_number == -1 )
          break;
        if ( g_PEColors[24].mode_number != v24->m_CurrentMode )
        {
          gray_color = g_PEColors[24].gray_color;
          goto LABEL_22;
        }
        tagtime = g_PEColors[24].root_color;
LABEL_23:
        v17 = CEventAbsoluteTag::GetName(this: RelativeTag);
        CChoreoWidgetDrawHelper::DrawColoredText(
          this: drawHelper,
          font: "Arial",
          pointsize: 9,
          weight: 400,
          clr: &tagtime,
          &rcText,
          fmt: v17);
        v3 = v24;
LABEL_24:
        v18 = v3->m_pEvent;
        v19 = ++i;
        if ( v19 >= CChoreoEvent::GetNumRelativeTags(this: v18) )
          return;
      }
      gray_color = g_PEColors[24].root_color;
LABEL_22:
      tagtime = gray_color;
      goto LABEL_23;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046BC80
// Name: private: void PhonemeEditor::RepositionHSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::RepositionHSlider(PhonemeEditor *this)
{
  CAudioSource *m_pWaveFile; // ecx
  int v3; // ebx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // [esp-8h] [ebp-18h]
  float v8; // [esp+Ch] [ebp-4h]

  m_pWaveFile = this->m_pWaveFile;
  v3 = 0;
  if ( m_pWaveFile != nullptr )
  {
    v8 = ((double (__thiscall *)(CAudioSource *))m_pWaveFile->GetRunningLength)(a1: m_pWaveFile) + 1.0;
    v3 = (int)(float)((float)((float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond) * v8);
  }
  v4 = mxWidget::w2(this);
  mxWidget::setVisible(this: this->m_pHorzScrollBar, b: v3 > v4);
  v7 = mxWidget::w2(this);
  v5 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow);
  mxWidget::setBounds(this: this->m_pHorzScrollBar, x: 0, y: v5, w: v7, h: 12);
  mxScrollbar::setRange(this: this->m_pHorzScrollBar, min: 0, max: v3);
  mxScrollbar::setValue(this: this->m_pHorzScrollBar, ivalue: 0);
  this->m_nLeftOffset = 0;
  v6 = mxWidget::w2(this);
  mxScrollbar::setPagesize(this: this->m_pHorzScrollBar, size: v6);
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x0046BD50
// Name: private: int PhonemeEditor::IsMouseOverBoundary(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall PhonemeEditor::IsMouseOverBoundary(PhonemeEditor *this, mxEvent *event)
{
  bool v3; // zf
  int y_low; // edi
  HWND Handle; // eax
  int v7; // eax
  float v8; // xmm2_4
  int v9; // ecx
  float v10; // xmm1_4
  CWordTag *v11; // eax
  int v12; // ebx
  float v13; // xmm1_4
  float *p_m_flStartTime; // eax
  int v15; // eax
  int v16; // edi
  int v17; // eax
  HWND v18; // eax
  int v19; // eax
  float v20; // xmm1_4
  int v21; // edi
  float v22; // xmm0_4
  int v23; // xmm2_4
  CWordTag *v24; // eax
  int v25; // eax
  int v26; // ebx
  int v27; // eax
  tagRECT rc; // [esp+8h] [ebp-40h] BYREF
  tagRECT Rect; // [esp+18h] [ebp-30h] BYREF
  int my; // [esp+28h] [ebp-20h]
  float endtime; // [esp+2Ch] [ebp-1Ch]
  float frac2; // [esp+30h] [ebp-18h]
  float frac1; // [esp+34h] [ebp-14h]
  float v34; // [esp+38h] [ebp-10h]
  int mx; // [esp+3Ch] [ebp-Ch]
  int i; // [esp+40h] [ebp-8h]
  CWordTag *word; // [esp+44h] [ebp-4h]
  float starttime; // [esp+50h] [ebp+8h]
  float starttimea; // [esp+50h] [ebp+8h]

  v3 = this->m_pWaveFile == nullptr;
  y_low = SLOWORD(event->y);
  mx = SLOWORD(event->x);
  my = y_low;
  if ( v3 || (event->modifiers & 1) == 0 )
    return 0;
  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &rc);
  rc.top += 60;
  rc.bottom -= 95;
  InflateRect(lprc: &rc, dx: -1, dy: -1);
  if ( !PhonemeEditor::IsMouseOverPhonemeRow(this, my: y_low) )
    goto LABEL_14;
  starttime = (float)this->m_nLeftOffset
            / (float)((float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond);
  *(float *)&i = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
  v7 = mxWidget::w2(this);
  v8 = starttime;
  *(float *)&v9 = 0.0;
  v10 = (float)((float)v7 / *(float *)&i) + starttime;
  endtime = v10;
  *(float *)&i = 0.0;
  if ( this->m_Tags.m_Words.m_Size > 0 )
  {
    while ( 1 )
    {
      v11 = this->m_Tags.m_Words.m_Memory.m_pMemory[v9];
      v12 = 0;
      word = v11;
      if ( v11->m_Phonemes.m_Size > 0 )
        break;
LABEL_13:
      i = ++v9;
      if ( v9 >= this->m_Tags.m_Words.m_Size )
        goto LABEL_14;
    }
    v13 = v10 - v8;
    v34 = v13;
    while ( 1 )
    {
      p_m_flStartTime = &v11->m_Phonemes.m_Memory.m_pMemory[v12]->m_flStartTime;
      frac1 = (float)(*p_m_flStartTime - v8) / v13;
      frac2 = (float)(p_m_flStartTime[1] - v8) / v13;
      v15 = mxWidget::w2(this);
      v16 = (int)(float)((float)v15 * frac1);
      v17 = mxWidget::w2(this);
      if ( (int)abs32(v16 - mx) <= 3 || (int)abs32((int)(float)((float)v17 * frac2) - mx) <= 3 )
        return 1;
      v8 = starttime;
      if ( ++v12 >= word->m_Phonemes.m_Size )
      {
        v10 = endtime;
        v9 = i;
        y_low = my;
        goto LABEL_13;
      }
      v13 = v34;
      v11 = word;
    }
  }
  else
  {
LABEL_14:
    if ( this->m_CurrentMode != MODE_PHONEMES )
      return 0;
    v18 = (HWND)mxWidget::getHandle(this);
    GetClientRect(hWnd: v18, lpRect: &Rect);
    Rect.top += 60;
    Rect.bottom -= 95;
    InflateRect(lprc: &Rect, dx: -1, dy: -1);
    if ( y_low < Rect.top )
      return 0;
    if ( y_low > Rect.top + this->m_nTickHeight )
      return 0;
    starttimea = (float)this->m_nLeftOffset
               / (float)((float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond);
    *(float *)&my = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
    v19 = mxWidget::w2(this);
    v20 = starttimea;
    v21 = 0;
    v22 = (float)((float)v19 / *(float *)&my) + starttimea;
    if ( this->m_Tags.m_Words.m_Size <= 0 )
    {
      return 0;
    }
    else
    {
      *(float *)&v23 = v22 - starttimea;
      *(float *)&my = v22 - starttimea;
      while ( 1 )
      {
        v24 = this->m_Tags.m_Words.m_Memory.m_pMemory[v21];
        endtime = (float)(v24->m_flStartTime - v20) / *(float *)&v23;
        frac2 = (float)(v24->m_flEndTime - v20) / *(float *)&v23;
        v25 = mxWidget::w2(this);
        v26 = (int)(float)((float)v25 * endtime);
        v27 = mxWidget::w2(this);
        if ( (int)abs32(v26 - mx) <= 3 || (int)abs32((int)(float)((float)v27 * frac2) - mx) <= 3 )
          break;
        if ( ++v21 >= this->m_Tags.m_Words.m_Size )
          return 0;
        v23 = my;
        v20 = starttimea;
      }
      return 2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046C080
// Name: private: void PhonemeEditor::DrawFocusRect(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::DrawFocusRect(PhonemeEditor *this, char *reason)
{
  int v3; // edi
  int v4; // ebx
  tagRECT rc; // [esp+8h] [ebp-14h] BYREF
  HDC__ *dc; // [esp+18h] [ebp-4h]

  v3 = 0;
  dc = GetDC(hWnd: nullptr);
  if ( this->m_FocusRects.m_Size > 0 )
  {
    v4 = 0;
    do
    {
      rc = this->m_FocusRects.m_Memory.m_pMemory[v4].m_rcFocus;
      DrawFocusRect(hDC: dc, lprc: &rc);
      ++v3;
      ++v4;
    }
    while ( v3 < this->m_FocusRects.m_Size );
  }
  ReleaseDC(hWnd: nullptr, hDC: dc);
}

//------------------------------------------------------------------------------
// Address: 0x0046C100
// Name: private: bool PhonemeEditor::FindSpanningPhonemes(float,class CPhonemeTag __near * __near *,class CPhonemeTag __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall PhonemeEditor::FindSpanningPhonemes(
        PhonemeEditor *this,
        float time,
        CPhonemeTag **pp1,
        CPhonemeTag **pp2)
{
  CPhonemeTag *v4; // eax
  int v5; // edx
  double v6; // xmm0_8
  CWordTag *v7; // ebx
  int v8; // edi
  CPhonemeTag *v9; // esi
  int v11; // edx
  int m_Size; // eax
  CWordTag *v13; // eax
  int v14; // edx
  CPhonemeTag *v15; // eax
  int w; // [esp+0h] [ebp-4h]

  *pp1 = nullptr;
  *pp2 = nullptr;
  v4 = nullptr;
  v5 = 0;
  v6 = (float)((float)(1.0 / (float)((float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond)) * 3.0);
  for ( w = 0; v5 < this->m_Tags.m_Words.m_Size; w = v5 )
  {
    v7 = this->m_Tags.m_Words.m_Memory.m_pMemory[v5];
    v8 = 0;
    if ( v7->m_Phonemes.m_Size > 0 )
    {
      do
      {
        v9 = v7->m_Phonemes.m_Memory.m_pMemory[v8];
        if ( v4 != nullptr )
        {
          v11 = 0;
          if ( v6 > fabs(v4->m_flEndTime - time) )
          {
            *pp1 = v4;
            v11 = 1;
          }
          if ( v6 > fabs(v9->m_flStartTime - time) )
          {
            *pp2 = v9;
            ++v11;
          }
          if ( v11 != 0 )
            return 1;
        }
        else if ( v6 > fabs(v9->m_flStartTime - time) )
        {
          *pp2 = v9;
          return 1;
        }
        ++v8;
        v4 = v9;
      }
      while ( v8 < v7->m_Phonemes.m_Size );
      v5 = w;
    }
    ++v5;
  }
  m_Size = this->m_Tags.m_Words.m_Size;
  if ( m_Size <= 0 )
    return 0;
  v13 = this->m_Tags.m_Words.m_Memory.m_pMemory[m_Size - 1];
  if ( v13 == nullptr )
    return 0;
  v14 = v13->m_Phonemes.m_Size;
  if ( v14 <= 0 )
    return 0;
  v15 = v13->m_Phonemes.m_Memory.m_pMemory[v14 - 1];
  if ( v6 <= fabs(v15->m_flEndTime - time) )
    return 0;
  *pp1 = v15;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046C270
// Name: private: bool PhonemeEditor::FindSpanningWords(float,class CWordTag __near * __near *,class CWordTag __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall PhonemeEditor::FindSpanningWords(PhonemeEditor *this, float time, CWordTag **pp1, CWordTag **pp2)
{
  CWordTag *v4; // eax
  int v5; // edi
  double v6; // xmm0_8
  CWordTag *v7; // edx
  int v9; // esi
  int m_Size; // eax
  CWordTag *v11; // eax

  *pp1 = nullptr;
  *pp2 = nullptr;
  v4 = nullptr;
  v5 = 0;
  v6 = (float)((float)(1.0 / (float)((float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond)) * 3.0);
  if ( this->m_Tags.m_Words.m_Size <= 0 )
  {
LABEL_12:
    m_Size = this->m_Tags.m_Words.m_Size;
    if ( m_Size <= 0 )
      return 0;
    v11 = this->m_Tags.m_Words.m_Memory.m_pMemory[m_Size - 1];
    if ( v6 <= fabs(v11->m_flEndTime - time) )
      return 0;
    *pp1 = v11;
    return 1;
  }
  while ( 1 )
  {
    v7 = this->m_Tags.m_Words.m_Memory.m_pMemory[v5];
    if ( v4 == nullptr )
      break;
    v9 = 0;
    if ( v6 > fabs(v4->m_flEndTime - time) )
    {
      *pp1 = v4;
      v9 = 1;
    }
    if ( v6 > fabs(v7->m_flStartTime - time) )
    {
      *pp2 = v7;
      ++v9;
    }
    if ( v9 != 0 )
      return 1;
LABEL_11:
    ++v5;
    v4 = v7;
    if ( v5 >= this->m_Tags.m_Words.m_Size )
      goto LABEL_12;
  }
  if ( v6 <= fabs(v7->m_flStartTime - time) )
    goto LABEL_11;
  *pp2 = v7;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046C3A0
// Name: private: bool PhonemeEditor::IsMouseOverSamples(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall PhonemeEditor::IsMouseOverSamples(PhonemeEditor *this, int mx, int my)
{
  bool result; // al
  HWND Handle; // eax
  tagRECT rcPhoneme; // [esp+4h] [ebp-30h] BYREF
  tagRECT rcWord; // [esp+14h] [ebp-20h] BYREF
  tagRECT rc; // [esp+24h] [ebp-10h] BYREF

  if ( this->m_CurrentMode != MODE_PHONEMES || this->m_pWaveFile == nullptr )
    return false;
  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &rc);
  rc.top += 60;
  rc.bottom -= 95;
  InflateRect(lprc: &rc, dx: -1, dy: -1);
  result = (unsigned int)(my - 40) > 0x14
        && !PhonemeEditor::IsMouseOverPhonemeRow(this, my)
        && !PhonemeEditor::IsMouseOverWordRow(this, my)
        && (PhonemeEditor::GetWordTrayTopBottom(this, rc: &rcWord),
            PhonemeEditor::GetPhonemeTrayTopBottom(this, rc: &rcPhoneme),
            my >= rcWord.bottom)
        && my <= rcPhoneme.top;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046C450
// Name: private: bool PhonemeEditor::IsMouseOverSelection(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall PhonemeEditor::IsMouseOverSelection(PhonemeEditor *this, int mx, int my)
{
  int SampleForMouse; // eax

  if ( this->m_CurrentMode != MODE_PHONEMES || this->m_pWaveFile == nullptr || !this->m_bSelectionActive )
    return 0;
  if ( PhonemeEditor::IsMouseOverSamples(this, mx, my) )
  {
    SampleForMouse = PhonemeEditor::GetSampleForMouse(this, mx);
    if ( SampleForMouse >= this->m_nSelection[0] - 3 && SampleForMouse <= this->m_nSelection[1] + 3 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0046C4C0
// Name: private: bool PhonemeEditor::IsMouseOverSelectionStartEdge(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall PhonemeEditor::IsMouseOverSelectionStartEdge(PhonemeEditor *this, mxEvent *event)
{
  int x_low; // edi
  int SampleForMouse; // edi
  tagRECT rc; // [esp+4h] [ebp-10h] BYREF
  float timeperpixel; // [esp+1Ch] [ebp+8h]

  if ( this->m_CurrentMode != MODE_PHONEMES || this->m_pWaveFile == nullptr )
    return false;
  x_low = SLOWORD(event->x);
  if ( (event->modifiers & 1) == 0 || PhonemeEditor::IsMouseOverSelection(this, mx: x_low, my: SLOWORD(event->y)) == 0 )
    return false;
  SampleForMouse = PhonemeEditor::GetSampleForMouse(this, mx: x_low);
  PhonemeEditor::GetWorkspaceRect(this, &rc);
  timeperpixel = PhonemeEditor::GetTimePerPixel(this);
  return (int)abs32(SampleForMouse - this->m_nSelection[0]) < 5
                                                            * (int)(float)((float)this->m_pWaveFile->SampleRate(this: this->m_pWaveFile)
                                                                         * timeperpixel);
}

//------------------------------------------------------------------------------
// Address: 0x0046C570
// Name: private: bool PhonemeEditor::IsMouseOverSelectionEndEdge(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall PhonemeEditor::IsMouseOverSelectionEndEdge(PhonemeEditor *this, mxEvent *event)
{
  int x_low; // edi
  int SampleForMouse; // edi
  float v6; // xmm0_4
  int v7; // eax
  tagRECT rc; // [esp+4h] [ebp-14h] BYREF
  float starttime; // [esp+14h] [ebp-4h]

  if ( this->m_CurrentMode != MODE_PHONEMES || this->m_pWaveFile == nullptr )
    return false;
  x_low = SLOWORD(event->x);
  if ( (event->modifiers & 1) == 0 )
    return false;
  if ( PhonemeEditor::IsMouseOverSelection(this, mx: x_low, my: SLOWORD(event->y)) == 0 )
    return false;
  SampleForMouse = PhonemeEditor::GetSampleForMouse(this, mx: x_low);
  PhonemeEditor::GetWorkspaceRect(this, &rc);
  if ( (float)((float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond) <= 0.0
    || rc.right - rc.left <= 0 )
  {
    return false;
  }
  v6 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
  starttime = (float)this->m_nLeftOffset / v6;
  v7 = mxWidget::w2(this);
  return (int)abs32(SampleForMouse - this->m_nSelection[1]) < 5
                                                            * (int)(float)((float)this->m_pWaveFile->SampleRate(this: this->m_pWaveFile)
                                                                         * (float)((float)((float)((float)((float)v7 / v6)
                                                                                                 + starttime)
                                                                                         - starttime)
                                                                                 / (float)(rc.right - rc.left)));
}

//------------------------------------------------------------------------------
// Address: 0x0046C6A0
// Name: private: void PhonemeEditor::ImportValveDataChunk(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ImportValveDataChunk(PhonemeEditor *this, const char *tempfile)
{
  void *v3; // eax
  Color v4; // ecx
  Color v5; // ecx
  int v6; // ebx
  void *v7; // edi
  void *fh; // [esp+8h] [ebp-4h]

  v3 = filesystem->Open(this: &filesystem->IBaseFileSystem, a2: tempfile, a3: "rb", a4: 0);
  fh = v3;
  if ( v3 != nullptr )
  {
    v6 = filesystem->Size_2(this: &filesystem->IBaseFileSystem, a2: v3);
    if ( v6 > 4 )
    {
      if ( this->m_CurrentMode == MODE_PHONEMES )
      {
        this->m_nLastExtractionResult = 0;
        CSentence::Reset(this: &this->m_TagsExt);
        this->redraw(this);
      }
      v7 = operator new(nSize: v6 + 1);
      filesystem->Read(this: &filesystem->IBaseFileSystem, a2: v7, a3: v6, a4: fh);
      filesystem->Close(this: &filesystem->IBaseFileSystem, a2: fh);
      CSentence::InitFromDataChunk(this: &this->m_TagsExt, data: v7, size: v6);
      free(pMem: v7);
      Con_Printf(a1: (Color)tempfile, fmt: "Imported %i words from %s\n", this->m_TagsExt.m_Words.m_Size, tempfile);
      this->redraw(this);
    }
    else
    {
      Con_ErrorPrintf(a1: v5, fmt: "PhonemeEditor::ImportValveDataChunk:  File %s has length 0\n", tempfile);
    }
  }
  else
  {
    Con_ErrorPrintf(a1: v4, fmt: "PhonemeEditor::ImportValveDataChunk:  Unable to read from %s\n", tempfile);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046C7B0
// Name: private: bool PhonemeEditor::StopPlayback(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall PhonemeEditor::StopPlayback(PhonemeEditor *this)
{
  char v2; // bl

  v2 = 0;
  if ( this->m_pWaveFile != nullptr )
  {
    this->m_flScrubTarget = this->m_flScrub;
    PhonemeEditor::ClampTimeToSelectionInterval(this, timeval: &this->m_flScrubTarget);
    if ( sound->IsSoundPlaying(this: sound, a2: this->m_pMixer) )
    {
      sound->StopAll(this: sound);
      v2 = 1;
    }
  }
  sound->Flush(this: sound);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0046C810
// Name: private: class CPhonemeTag __near * PhonemeEditor::GetPhonemeTagUnderMouse(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall PhonemeEditor::GetPhonemeTagUnderMouse(PhonemeEditor *this, int mx, int my)
{
  int result; // eax
  HWND Handle; // eax
  float v6; // xmm0_4
  int v7; // eax
  float v8; // xmm3_4
  float v9; // xmm4_4
  CWordTag *v10; // edi
  int v11; // ecx
  CPhonemeTag *v12; // eax
  float v13; // xmm0_4
  float v14; // xmm1_4
  int v15; // ebx
  int v16; // eax
  int v17; // eax
  tagRECT rc; // [esp+4h] [ebp-28h] BYREF
  CPhonemeTag *pPhoneme; // [esp+14h] [ebp-18h]
  float v20; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  int k; // [esp+20h] [ebp-Ch]
  float starttime; // [esp+24h] [ebp-8h]
  float frac2; // [esp+28h] [ebp-4h]
  float frac1; // [esp+38h] [ebp+Ch]

  if ( this->m_CurrentMode != MODE_PHONEMES )
    return 0;
  if ( this->m_pWaveFile == nullptr )
    return 0;
  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &rc);
  rc.top += 60;
  rc.bottom -= 95;
  InflateRect(lprc: &rc, dx: -1, dy: -1);
  if ( !PhonemeEditor::IsMouseOverPhonemeRow(this, my)
    || (float)((float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond) <= 0.0 )
  {
    return 0;
  }
  v6 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
  starttime = (float)this->m_nLeftOffset / v6;
  v7 = mxWidget::w2(this);
  v8 = starttime;
  v9 = (float)((float)((float)v7 / v6) + starttime) - starttime;
  result = 0;
  v20 = v9;
  if ( v9 > 0.0 )
  {
    i = 0;
    if ( this->m_Tags.m_Words.m_Size > 0 )
    {
      while ( 1 )
      {
        v10 = this->m_Tags.m_Words.m_Memory.m_pMemory[result];
        if ( v10 != nullptr )
        {
          v11 = 0;
          k = 0;
          if ( v10->m_Phonemes.m_Size > 0 )
            break;
        }
LABEL_27:
        i = ++result;
        if ( result >= this->m_Tags.m_Words.m_Size )
          return 0;
      }
      while ( 1 )
      {
        v12 = v10->m_Phonemes.m_Memory.m_pMemory[v11];
        pPhoneme = v12;
        if ( v12 == nullptr )
          goto LABEL_25;
        v13 = (float)(v12->m_flStartTime - v8) / v9;
        v14 = (float)(v12->m_flEndTime - v8) / v9;
        frac1 = v13;
        frac2 = v14;
        if ( v13 <= 1.0 )
        {
          if ( v13 >= 0.0 )
            goto LABEL_16;
          v13 = 0.0;
        }
        else
        {
          v13 = 1.0;
        }
        frac1 = v13;
LABEL_16:
        if ( v14 <= 1.0 )
        {
          if ( v14 >= 0.0 )
            goto LABEL_21;
          v14 = 0.0;
        }
        else
        {
          v14 = 1.0;
        }
        frac2 = v14;
LABEL_21:
        if ( v13 != v14 )
        {
          v15 = (int)(float)((float)mxWidget::w2(this) * frac1);
          v16 = mxWidget::w2(this);
          v17 = (int)(float)((float)v16 * frac2);
          if ( mx >= v15 && mx <= v17 )
            return (int)pPhoneme;
          v8 = starttime;
          v9 = v20;
          v11 = k;
        }
LABEL_25:
        k = ++v11;
        if ( v11 >= v10->m_Phonemes.m_Size )
        {
          result = i;
          goto LABEL_27;
        }
      }
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046CA30
// Name: private: class CWordTag __near * PhonemeEditor::GetWordTagUnderMouse(int,int)
// Source: json
//------------------------------------------------------------------------------
CWordTag *__thiscall PhonemeEditor::GetWordTagUnderMouse(PhonemeEditor *this, int mx, int my)
{
  HWND Handle; // eax
  float v6; // xmm0_4
  int v7; // eax
  float v8; // xmm2_4
  float v9; // xmm3_4
  int v10; // ecx
  CWordTag *v11; // ebx
  float v12; // xmm0_4
  float v13; // xmm1_4
  int v14; // edi
  int v15; // eax
  int v16; // eax
  tagRECT rc; // [esp+4h] [ebp-20h] BYREF
  float v18; // [esp+14h] [ebp-10h]
  int k; // [esp+18h] [ebp-Ch]
  float starttime; // [esp+1Ch] [ebp-8h]
  float frac2; // [esp+20h] [ebp-4h]
  float frac1; // [esp+30h] [ebp+Ch]

  if ( this->m_CurrentMode == MODE_PHONEMES && this->m_pWaveFile != nullptr )
  {
    Handle = (HWND)mxWidget::getHandle(this);
    GetClientRect(hWnd: Handle, lpRect: &rc);
    rc.top += 60;
    rc.bottom -= 95;
    InflateRect(lprc: &rc, dx: -1, dy: -1);
    if ( PhonemeEditor::IsMouseOverWordRow(this, my)
      && (float)((float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond) > 0.0 )
    {
      v6 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
      starttime = (float)this->m_nLeftOffset / v6;
      v7 = mxWidget::w2(this);
      v8 = starttime;
      v9 = (float)((float)((float)v7 / v6) + starttime) - starttime;
      v18 = v9;
      if ( v9 > 0.0 )
      {
        v10 = 0;
        k = 0;
        if ( this->m_Tags.m_Words.m_Size <= 0 )
          return nullptr;
        while ( 1 )
        {
          v11 = this->m_Tags.m_Words.m_Memory.m_pMemory[v10];
          if ( v11 != nullptr )
            break;
LABEL_23:
          k = ++v10;
          if ( v10 >= this->m_Tags.m_Words.m_Size )
            return nullptr;
        }
        v12 = (float)(v11->m_flStartTime - v8) / v9;
        v13 = (float)(v11->m_flEndTime - v8) / v9;
        frac1 = v12;
        frac2 = v13;
        if ( v12 <= 1.0 )
        {
          if ( v12 >= 0.0 )
            goto LABEL_14;
          v12 = 0.0;
        }
        else
        {
          v12 = 1.0;
        }
        frac1 = v12;
LABEL_14:
        if ( v13 <= 1.0 )
        {
          if ( v13 >= 0.0 )
            goto LABEL_19;
          v13 = 0.0;
        }
        else
        {
          v13 = 1.0;
        }
        frac2 = v13;
LABEL_19:
        if ( v12 == v13 )
          goto LABEL_23;
        v14 = (int)(float)((float)mxWidget::w2(this) * frac1);
        v15 = mxWidget::w2(this);
        v16 = (int)(float)((float)v15 * frac2);
        if ( mx < v14 || mx > v16 )
        {
          v8 = starttime;
          v9 = v18;
          v10 = k;
          goto LABEL_23;
        }
        return v11;
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0046CC20
// Name: private: void PhonemeEditor::DeselectWords(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::DeselectWords(PhonemeEditor *this)
{
  int i; // eax
  CWordTag *v2; // edx

  if ( this->m_CurrentMode == MODE_PHONEMES )
  {
    for ( i = 0; i < this->m_Tags.m_Words.m_Size; ++i )
    {
      v2 = this->m_Tags.m_Words.m_Memory.m_pMemory[i];
      if ( v2 != nullptr )
        v2->m_bSelected = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046CC50
// Name: private: void PhonemeEditor::DeselectPhonemes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::DeselectPhonemes(PhonemeEditor *this)
{
  int i; // edi
  CWordTag *v2; // eax
  int j; // edx
  CPhonemeTag *v4; // esi

  if ( this->m_CurrentMode == MODE_PHONEMES )
  {
    for ( i = 0; i < this->m_Tags.m_Words.m_Size; ++i )
    {
      v2 = this->m_Tags.m_Words.m_Memory.m_pMemory[i];
      if ( v2 != nullptr )
      {
        for ( j = 0; j < v2->m_Phonemes.m_Size; ++j )
        {
          v4 = v2->m_Phonemes.m_Memory.m_pMemory[j];
          if ( v4 != nullptr )
            v4->m_bSelected = false;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046CCB0
// Name: private: bool PhonemeEditor::IsMouseOverTag(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall PhonemeEditor::IsMouseOverTag(PhonemeEditor *this, int mx, int my)
{
  return this->m_CurrentMode == MODE_PHONEMES
      && (unsigned int)(my - 40) <= 0x14
      && PhonemeEditor::GetTagUnderMouse(this, mx) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0046CCE0
// Name: private: void PhonemeEditor::TraverseWords(void (PhonemeEditor::*)(class CWordTag __near *,float),float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::TraverseWords(
        PhonemeEditor *this,
        void (__thiscall *pfn)(char *, CWordTag *, int),
        float fparam,
        int fparama)
{
  int i; // edi
  CWordTag *v6; // eax

  for ( i = 0; i < this->m_Tags.m_Words.m_Size; ++i )
  {
    v6 = this->m_Tags.m_Words.m_Memory.m_pMemory[i];
    if ( v6 != nullptr )
      pfn(a1: (char *)this + LODWORD(fparam), a2: v6, a3: fparama);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046CD30
// Name: private: void PhonemeEditor::TraversePhonemes(void (PhonemeEditor::*)(class CPhonemeTag __near *,class CWordTag __near *,float),float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::TraversePhonemes(
        PhonemeEditor *this,
        void (__thiscall *pfn)(char *, CPhonemeTag *, CWordTag *, int),
        float fparam,
        int fparama)
{
  int v4; // eax
  CWordTag *v6; // esi
  int v7; // edi
  CPhonemeTag *v8; // eax
  int i; // [esp+10h] [ebp-4h]

  v4 = 0;
  for ( i = 0; v4 < this->m_Tags.m_Words.m_Size; i = v4 )
  {
    v6 = this->m_Tags.m_Words.m_Memory.m_pMemory[v4];
    if ( v6 != nullptr )
    {
      v7 = 0;
      if ( v6->m_Phonemes.m_Size > 0 )
      {
        do
        {
          v8 = v6->m_Phonemes.m_Memory.m_pMemory[v7];
          if ( v8 != nullptr )
            pfn(a1: (char *)this + LODWORD(fparam), a2: v8, a3: v6, a4: fparama);
          ++v7;
        }
        while ( v7 < v6->m_Phonemes.m_Size );
        v4 = i;
      }
    }
    ++v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046CDB0
// Name: private: void PhonemeEditor::CountSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::CountSelected(PhonemeEditor *this)
{
  int v1; // edx
  CWordTag *v2; // eax

  v1 = 0;
  this->m_nSelectedPhonemeCount = 0;
  for ( this->m_nSelectedWordCount = 0; v1 < this->m_Tags.m_Words.m_Size; ++v1 )
  {
    v2 = this->m_Tags.m_Words.m_Memory.m_pMemory[v1];
    if ( v2 != nullptr )
      PhonemeEditor::ITER_CountSelectedWords(this, word: v2, amount: 0.0);
  }
  PhonemeEditor::TraversePhonemes(
    this,
    pfn: (void (__thiscall *)(char *, CPhonemeTag *, CWordTag *, int))PhonemeEditor::ITER_CountSelectedPhonemes,
    fparam: 0.0,
    fparama: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0046CE10
// Name: private: void PhonemeEditor::Undo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::Undo(PhonemeEditor *this)
{
  int m_nUndoLevel; // eax
  PhonemeEditor::PEUndo **m_pMemory; // ecx
  int v4; // eax

  if ( this->m_UndoStack.m_Size > 0 )
  {
    m_nUndoLevel = this->m_nUndoLevel;
    if ( m_nUndoLevel > 0 )
    {
      m_pMemory = this->m_UndoStack.m_Memory.m_pMemory;
      v4 = m_nUndoLevel - 1;
      this->m_nUndoLevel = v4;
      CSentence::operator=(this: &this->m_Tags, src: m_pMemory[v4]->undo);
      this->m_nClickedPhoneme = -1;
      this->m_nClickedWord = -1;
    }
  }
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x0046CE60
// Name: private: void PhonemeEditor::Redo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::Redo(PhonemeEditor *this)
{
  int m_Size; // ecx
  int m_nUndoLevel; // eax

  m_Size = this->m_UndoStack.m_Size;
  if ( m_Size > 0 )
  {
    m_nUndoLevel = this->m_nUndoLevel;
    if ( m_nUndoLevel <= m_Size - 1 )
    {
      CSentence::operator=(this: &this->m_Tags, src: this->m_UndoStack.m_Memory.m_pMemory[m_nUndoLevel]->redo);
      ++this->m_nUndoLevel;
      this->m_nClickedPhoneme = -1;
      this->m_nClickedWord = -1;
    }
  }
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x0046CEB0
// Name: private: void PhonemeEditor::PushRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::PushRedo(PhonemeEditor *this)
{
  CSentence *v2; // eax
  CSentence *v3; // edi

  this->m_bRedoPending = false;
  v2 = (CSentence *)operator new(nSize: 0x4Cu);
  if ( v2 != nullptr )
    v3 = CSentence::CSentence(this: v2);
  else
    v3 = nullptr;
  CSentence::operator=(this: v3, src: &this->m_Tags);
  this->m_UndoStack.m_Memory.m_pMemory[this->m_nUndoLevel - 1]->redo = v3;
}

//------------------------------------------------------------------------------
// Address: 0x0046CF00
// Name: private: void PhonemeEditor::SelectNextWord(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::SelectNextWord(PhonemeEditor *this, int direction)
{
  CWordTag **m_pMemory; // ecx
  int m_nSelectedWordCount; // eax
  int m_Size; // eax
  int v6; // eax
  const char *v7; // eax
  CWordTag **v8; // ebx
  CWordTag *v9; // eax
  int v10; // edx
  CPhonemeTag *v11; // ecx
  int v12; // eax
  int v13; // ecx
  CPhonemeTag **v14; // edx
  CWordTag *v15; // eax
  int v16; // ecx
  CPhonemeTag *v17; // ecx
  void (__thiscall *redraw)(struct PhonemeEditor *); // eax
  int i; // [esp+4h] [ebp-4h]

  if ( this->m_CurrentMode == MODE_PHONEMES )
  {
    PhonemeEditor::CountSelected(this);
    m_nSelectedWordCount = this->m_nSelectedWordCount;
    if ( m_nSelectedWordCount != 1 && this->m_nSelectedPhonemeCount != 1 )
    {
      if ( m_nSelectedWordCount != 0 )
        return;
      m_Size = this->m_Tags.m_Words.m_Size;
      if ( m_Size <= 0 )
        return;
      if ( direction != 0 )
        v6 = m_Size - 1;
      else
        v6 = 0;
      m_pMemory = this->m_Tags.m_Words.m_Memory.m_pMemory;
      m_pMemory[v6]->m_bSelected = true;
      this->m_nSelectedWordCount = 1;
    }
    v7 = "left";
    if ( direction != -1 )
      v7 = "right";
    Con_Printf(a1: (Color)m_pMemory, fmt: "Move to next word %s\n", v7);
    i = 0;
    if ( this->m_Tags.m_Words.m_Size > 0 )
    {
      v8 = this->m_Tags.m_Words.m_Memory.m_pMemory;
      do
      {
        v9 = *v8;
        if ( *v8 != nullptr )
        {
          if ( this->m_nSelectedWordCount == 1 )
          {
            if ( v9->m_bSelected )
              goto LABEL_17;
          }
          else
          {
            v13 = 0;
            if ( v9->m_Phonemes.m_Size > 0 )
            {
              v14 = v9->m_Phonemes.m_Memory.m_pMemory;
              while ( *v14 == nullptr || !(*v14)->m_bSelected )
              {
                ++v13;
                ++v14;
                if ( v13 >= v9->m_Phonemes.m_Size )
                  goto LABEL_29;
              }
LABEL_17:
              v10 = 0;
              for ( v9->m_bSelected = false; v10 < v9->m_Phonemes.m_Size; ++v10 )
              {
                v11 = v9->m_Phonemes.m_Memory.m_pMemory[v10];
                if ( v11 != nullptr && v11->m_bSelected )
                  v11->m_bSelected = false;
              }
              v12 = direction + i;
              if ( direction + i >= 0 )
              {
                if ( v12 >= this->m_Tags.m_Words.m_Size )
                  v12 = 0;
              }
              else
              {
                v12 = this->m_Tags.m_Words.m_Size - 1;
              }
              v15 = this->m_Tags.m_Words.m_Memory.m_pMemory[v12];
              v16 = v15->m_Phonemes.m_Size;
              v15->m_bSelected = true;
              if ( v16 > 0 )
              {
                if ( direction <= 0 )
                  v17 = v15->m_Phonemes.m_Memory.m_pMemory[v16 - 1];
                else
                  v17 = *v15->m_Phonemes.m_Memory.m_pMemory;
                v17->m_bSelected = true;
              }
              redraw = this->redraw;
              this->m_bWordsActive = true;
              redraw(this);
              return;
            }
          }
        }
LABEL_29:
        ++v8;
        ++i;
      }
      while ( i < this->m_Tags.m_Words.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046D080
// Name: private: int PhonemeEditor::IndexOfWord(class CWordTag __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall PhonemeEditor::IndexOfWord(PhonemeEditor *this, CWordTag *word)
{
  int m_Size; // edx
  int result; // eax
  CWordTag **i; // ecx

  m_Size = this->m_Tags.m_Words.m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Tags.m_Words.m_Memory.m_pMemory; *i != word; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046D0C0
// Name: private: float PhonemeEditor::GetTimeGapToNextPhoneme(bool,class CPhonemeTag __near *,class CWordTag __near * __near *,class CPhonemeTag __near * __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall PhonemeEditor::GetTimeGapToNextPhoneme(
        PhonemeEditor *this,
        bool forward,
        CPhonemeTag *currentPhoneme,
        CWordTag **ppword,
        CPhonemeTag **ppphoneme)
{
  CWordTag *WordForPhoneme; // ebx
  int m_Size; // eax
  int v9; // esi
  CWordTag **m_pMemory; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // esi
  CWordTag **v14; // eax
  CWordTag *v15; // ecx
  CPhonemeTag *v16; // eax
  int v17; // esi
  int v18; // eax

  if ( ppword != nullptr )
    *ppword = nullptr;
  if ( ppphoneme != nullptr )
    *ppphoneme = nullptr;
  if ( currentPhoneme == nullptr )
    return 0.0;
  WordForPhoneme = CSentence::GetWordForPhoneme(this: &this->m_Tags, phoneme: currentPhoneme);
  if ( WordForPhoneme == nullptr )
    return 0.0;
  m_Size = this->m_Tags.m_Words.m_Size;
  v9 = 0;
  if ( m_Size <= 0 )
  {
LABEL_13:
    v9 = -1;
  }
  else
  {
    m_pMemory = this->m_Tags.m_Words.m_Memory.m_pMemory;
    while ( *m_pMemory != WordForPhoneme )
    {
      ++v9;
      ++m_pMemory;
      if ( v9 >= m_Size )
        goto LABEL_13;
    }
  }
  v11 = CWordTag::IndexOfPhoneme(this: WordForPhoneme, tag: currentPhoneme);
  if ( v11 < 0 )
    return 0.0;
  v12 = 2 * forward - 1 + v11;
  if ( v12 < 0 )
  {
    v13 = v9 - 1;
    if ( v13 >= 0 )
    {
      while ( 1 )
      {
        if ( ppword != nullptr )
          *ppword = this->m_Tags.m_Words.m_Memory.m_pMemory[v13];
        if ( this->m_Tags.m_Words.m_Size > 0 )
        {
          v14 = this->m_Tags.m_Words.m_Memory.m_pMemory;
          v15 = v14[v13];
          if ( v15->m_Phonemes.m_Size > 0 )
            break;
        }
        if ( --v13 < 0 )
          return 99999.898;
      }
      v16 = v14[v13]->m_Phonemes.m_Memory.m_pMemory[v15->m_Phonemes.m_Size - 1];
      goto LABEL_35;
    }
    return 99999.898;
  }
  if ( v12 < WordForPhoneme->m_Phonemes.m_Size )
  {
    v16 = WordForPhoneme->m_Phonemes.m_Memory.m_pMemory[v12];
    goto LABEL_35;
  }
  v17 = v9 + 1;
  if ( v17 >= this->m_Tags.m_Words.m_Size )
    return 99999.898;
  while ( 1 )
  {
    if ( ppword != nullptr )
      *ppword = this->m_Tags.m_Words.m_Memory.m_pMemory[v17];
    v18 = this->m_Tags.m_Words.m_Size;
    if ( v18 > 0 && this->m_Tags.m_Words.m_Memory.m_pMemory[v17]->m_Phonemes.m_Size > 0 )
      break;
    if ( ++v17 >= v18 )
      return 99999.898;
  }
  v16 = *this->m_Tags.m_Words.m_Memory.m_pMemory[v17]->m_Phonemes.m_Memory.m_pMemory;
LABEL_35:
  if ( v16 == nullptr )
    return 99999.898;
  if ( ppphoneme != nullptr )
    *ppphoneme = v16;
  if ( forward )
    return (float)(v16->m_flStartTime - currentPhoneme->m_flEndTime);
  else
    return (float)(currentPhoneme->m_flStartTime - v16->m_flEndTime);
}

//------------------------------------------------------------------------------
// Address: 0x0046D260
// Name: private: class CPhonemeTag __near * PhonemeEditor::GetSelectedPhoneme(void)
// Source: json
//------------------------------------------------------------------------------
CPhonemeTag *__thiscall PhonemeEditor::GetSelectedPhoneme(PhonemeEditor *this)
{
  CPhonemeTag *result; // eax
  int m_Size; // edx
  int v4; // edi
  CWordTag **i; // ebx
  CWordTag *v6; // eax
  int v7; // esi
  int v8; // ecx
  CPhonemeTag **m_pMemory; // edx
  int v10; // [esp+4h] [ebp-4h]

  PhonemeEditor::CountSelected(this);
  if ( this->m_nSelectedPhonemeCount != 1 )
    return nullptr;
  m_Size = this->m_Tags.m_Words.m_Size;
  v4 = 0;
  v10 = m_Size;
  if ( m_Size <= 0 )
    return nullptr;
  for ( i = this->m_Tags.m_Words.m_Memory.m_pMemory; ; ++i )
  {
    v6 = *i;
    if ( *i != nullptr )
    {
      v7 = v6->m_Phonemes.m_Size;
      v8 = 0;
      if ( v7 > 0 )
        break;
    }
LABEL_12:
    if ( ++v4 >= m_Size )
      return nullptr;
  }
  m_pMemory = v6->m_Phonemes.m_Memory.m_pMemory;
  while ( 1 )
  {
    result = *m_pMemory;
    if ( *m_pMemory != nullptr && result->m_bSelected )
      return result;
    ++v8;
    ++m_pMemory;
    if ( v8 >= v7 )
    {
      m_Size = v10;
      goto LABEL_12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046D2D0
// Name: private: class CWordTag __near * PhonemeEditor::GetSelectedWord(void)
// Source: json
//------------------------------------------------------------------------------
CWordTag *__thiscall PhonemeEditor::GetSelectedWord(PhonemeEditor *this)
{
  CWordTag *result; // eax
  int m_Size; // edi
  int v4; // ecx
  CWordTag **i; // edx

  PhonemeEditor::CountSelected(this);
  if ( this->m_nSelectedWordCount != 1 )
    return nullptr;
  m_Size = this->m_Tags.m_Words.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return nullptr;
  for ( i = this->m_Tags.m_Words.m_Memory.m_pMemory; ; ++i )
  {
    result = *i;
    if ( *i != nullptr && result->m_bSelected )
      break;
    if ( ++v4 >= m_Size )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046D320
// Name: private: void PhonemeEditor::SelectPhonemes(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::SelectPhonemes(PhonemeEditor *this, bool forward)
{
  CPhonemeTag *SelectedPhoneme; // eax
  CWordTag *WordForPhoneme; // eax
  CWordTag *v5; // esi
  int v6; // edi
  int v7; // eax
  int i; // eax
  CPhonemeTag *v9; // edx
  int j; // edi
  CWordTag *v11; // ecx
  int k; // eax
  CPhonemeTag *v13; // edx
  int m; // eax
  int n; // edi
  CWordTag *v16; // ecx
  int ii; // eax
  CPhonemeTag *v18; // edx
  CPhonemeTag *phoneme; // [esp+4h] [ebp-4h]

  if ( this->m_CurrentMode == MODE_PHONEMES )
  {
    PhonemeEditor::CountSelected(this);
    if ( this->m_nSelectedPhonemeCount == 1 )
    {
      SelectedPhoneme = PhonemeEditor::GetSelectedPhoneme(this);
      phoneme = SelectedPhoneme;
      if ( SelectedPhoneme != nullptr )
      {
        WordForPhoneme = CSentence::GetWordForPhoneme(this: &this->m_Tags, phoneme: SelectedPhoneme);
        v5 = WordForPhoneme;
        if ( WordForPhoneme != nullptr )
        {
          v6 = PhonemeEditor::IndexOfWord(this, word: WordForPhoneme);
          if ( v6 != -1 )
          {
            v7 = CWordTag::IndexOfPhoneme(this: v5, tag: phoneme);
            if ( v7 != -1 )
            {
              if ( forward )
              {
                for ( i = v7 + 1; i < v5->m_Phonemes.m_Size; v9->m_bSelected = true )
                  v9 = v5->m_Phonemes.m_Memory.m_pMemory[i++];
                for ( j = v6 + 1; j < this->m_Tags.m_Words.m_Size; ++j )
                {
                  v11 = this->m_Tags.m_Words.m_Memory.m_pMemory[j];
                  for ( k = 0; k < v11->m_Phonemes.m_Size; v13->m_bSelected = true )
                    v13 = v11->m_Phonemes.m_Memory.m_pMemory[k++];
                }
              }
              else
              {
                for ( m = v7 - 1; m >= 0; v5->m_Phonemes.m_Memory.m_pMemory[m + 1]->m_bSelected = true )
                  --m;
                for ( n = v6 - 1; n >= 0; --n )
                {
                  v16 = this->m_Tags.m_Words.m_Memory.m_pMemory[n];
                  for ( ii = 0; ii < v16->m_Phonemes.m_Size; v18->m_bSelected = true )
                    v18 = v16->m_Phonemes.m_Memory.m_pMemory[ii++];
                }
              }
              this->redraw(this);
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046D450
// Name: private: void PhonemeEditor::SelectWords(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::SelectWords(PhonemeEditor *this, bool forward)
{
  CWordTag *SelectedWord; // eax
  int v4; // eax
  int i; // eax
  CWordTag *v6; // edx
  int j; // eax
  CWordTag *v8; // edx

  if ( this->m_CurrentMode == MODE_PHONEMES )
  {
    PhonemeEditor::CountSelected(this);
    if ( this->m_nSelectedWordCount == 1 )
    {
      SelectedWord = PhonemeEditor::GetSelectedWord(this);
      if ( SelectedWord != nullptr )
      {
        v4 = PhonemeEditor::IndexOfWord(this, word: SelectedWord);
        if ( v4 != -1 )
        {
          if ( forward )
          {
            for ( i = v4 + 1; i < this->m_Tags.m_Words.m_Size; v6->m_bSelected = true )
              v6 = this->m_Tags.m_Words.m_Memory.m_pMemory[i++];
          }
          else
          {
            for ( j = v4 - 1; j >= 0; v8->m_bSelected = true )
              v8 = this->m_Tags.m_Words.m_Memory.m_pMemory[j--];
          }
          this->redraw(this);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046D4F0
// Name: private: bool PhonemeEditor::AreSelectedWordsContiguous(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall PhonemeEditor::AreSelectedWordsContiguous(PhonemeEditor *this)
{
  int m_nSelectedWordCount; // eax
  int m_Size; // eax
  int v5; // edi
  char v6; // cl
  CWordTag **m_pMemory; // esi
  int i; // edx

  PhonemeEditor::CountSelected(this);
  m_nSelectedWordCount = this->m_nSelectedWordCount;
  if ( m_nSelectedWordCount < 1 )
    return false;
  if ( m_nSelectedWordCount == 1 )
    return true;
  m_Size = this->m_Tags.m_Words.m_Size;
  v5 = 0;
  v6 = 0;
  if ( m_Size <= 0 )
    return false;
  m_pMemory = this->m_Tags.m_Words.m_Memory.m_pMemory;
  for ( i = m_Size; i != 0; --i )
  {
    if ( *m_pMemory != nullptr )
    {
      if ( (*m_pMemory)->m_bSelected )
      {
        if ( v6 == 0 )
        {
          v6 = 1;
          ++v5;
        }
      }
      else if ( v6 != 0 )
      {
        v6 = 0;
      }
    }
    ++m_pMemory;
  }
  return v5 == 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046D560
// Name: private: bool PhonemeEditor::AreSelectedPhonemesContiguous(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall PhonemeEditor::AreSelectedPhonemesContiguous(PhonemeEditor *this)
{
  int m_nSelectedPhonemeCount; // eax
  int m_Size; // eax
  int v5; // edi
  char v6; // bl
  CWordTag **m_pMemory; // esi
  CWordTag *v8; // eax
  int v9; // ecx
  CPhonemeTag **v10; // edx
  int i; // [esp+4h] [ebp-4h]

  PhonemeEditor::CountSelected(this);
  m_nSelectedPhonemeCount = this->m_nSelectedPhonemeCount;
  if ( m_nSelectedPhonemeCount < 1 )
    return false;
  if ( m_nSelectedPhonemeCount == 1 )
    return true;
  m_Size = this->m_Tags.m_Words.m_Size;
  v5 = 0;
  v6 = 0;
  if ( m_Size <= 0 )
    return false;
  m_pMemory = this->m_Tags.m_Words.m_Memory.m_pMemory;
  for ( i = m_Size; i != 0; --i )
  {
    v8 = *m_pMemory;
    if ( *m_pMemory != nullptr )
    {
      v9 = v8->m_Phonemes.m_Size;
      if ( v9 > 0 )
      {
        v10 = v8->m_Phonemes.m_Memory.m_pMemory;
        do
        {
          if ( *v10 != nullptr )
          {
            if ( (*v10)->m_bSelected )
            {
              if ( v6 == 0 )
              {
                v6 = 1;
                ++v5;
              }
            }
            else if ( v6 != 0 )
            {
              v6 = 0;
            }
          }
          ++v10;
          --v9;
        }
        while ( v9 != 0 );
      }
    }
    ++m_pMemory;
  }
  return v5 == 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046D5F0
// Name: private: float PhonemeEditor::ComputeMaxWordShift(bool,bool)
// Source: json
//------------------------------------------------------------------------------
double __thiscall PhonemeEditor::ComputeMaxWordShift(PhonemeEditor *this, bool forward, bool allowcrop)
{
  float v3; // xmm1_4
  int m_Size; // esi
  CWordTag **m_pMemory; // ebx
  int v6; // eax
  CWordTag *v7; // edi
  int v8; // ecx
  int *v9; // edx
  int v10; // eax
  float v11; // xmm0_4
  float v12; // xmm0_4
  bool v13; // zf
  int v15; // esi
  CWordTag **v16; // ebx
  CWordTag *v17; // edi
  int v18; // ecx
  CWordTag **v19; // edx
  CWordTag *v20; // eax
  float m_flStartTime; // xmm0_4
  float v22; // xmm0_4
  int v23; // [esp+0h] [ebp-8h]
  float maxshift; // [esp+4h] [ebp-4h]
  int forwarda; // [esp+10h] [ebp+8h]

  v3 = 99999.898;
  m_Size = this->m_Tags.m_Words.m_Size;
  maxshift = 99999.898;
  if ( !forward )
  {
    v15 = m_Size - 1;
    if ( v15 >= 0 )
    {
      v16 = &this->m_Tags.m_Words.m_Memory.m_pMemory[v15];
      do
      {
        v17 = *v16;
        if ( *v16 != nullptr && v17->m_bSelected )
        {
          v18 = v15 - 1;
          if ( v15 >= 1 )
          {
            v19 = v16 - 1;
            while ( 1 )
            {
              v20 = *v19;
              if ( *v19 != nullptr && !v20->m_bSelected )
                break;
              --v19;
              if ( --v18 < 0 )
                goto LABEL_34;
            }
            m_flStartTime = v17->m_flStartTime;
            if ( allowcrop )
              v22 = m_flStartTime - v20->m_flStartTime;
            else
              v22 = m_flStartTime - v20->m_flEndTime;
            if ( v3 > v22 )
            {
              v3 = v22;
              maxshift = v22;
            }
          }
        }
LABEL_34:
        --v16;
        --v15;
      }
      while ( v15 >= 0 );
    }
  }
  else if ( m_Size > 0 )
  {
    m_pMemory = this->m_Tags.m_Words.m_Memory.m_pMemory;
    v6 = 1;
    forwarda = 1;
    v23 = this->m_Tags.m_Words.m_Size;
    do
    {
      v7 = *m_pMemory;
      if ( *m_pMemory != nullptr && v7->m_bSelected )
      {
        v8 = v6;
        if ( v6 < m_Size )
        {
          v9 = (int *)(m_pMemory + 1);
          while ( 1 )
          {
            v10 = *v9;
            if ( *v9 != 0 && *(_BYTE *)(v10 + 28) == 0 )
              break;
            ++v8;
            ++v9;
            if ( v8 >= m_Size )
              goto LABEL_17;
          }
          if ( allowcrop )
            v11 = *(float *)(v10 + 4);
          else
            v11 = *(float *)v10;
          v12 = v11 - v7->m_flEndTime;
          if ( v3 > v12 )
            v3 = v12;
        }
      }
LABEL_17:
      v6 = forwarda + 1;
      ++m_pMemory;
      v13 = v23-- == 1;
      ++forwarda;
    }
    while ( !v13 );
    return v3;
  }
  return maxshift;
}

//------------------------------------------------------------------------------
// Address: 0x0046D710
// Name: private: float PhonemeEditor::ComputeMaxPhonemeShift(bool,bool)
// Source: json
//------------------------------------------------------------------------------
double __thiscall PhonemeEditor::ComputeMaxPhonemeShift(PhonemeEditor *this, BOOL forward, bool allowcrop)
{
  int v4; // edx
  CWordTag *v5; // eax
  int v6; // ecx
  CPhonemeTag *v7; // edi
  CPhonemeTag *v8; // eax
  float m_flEndTime; // xmm0_4
  float v10; // xmm0_4
  int v12; // edx
  CWordTag *v13; // ecx
  int v14; // eax
  CPhonemeTag *v15; // edi
  CPhonemeTag *v16; // eax
  float m_flStartTime; // xmm0_4
  float v18; // xmm0_4
  CWordTag *word; // [esp+0h] [ebp-14h]
  CWordTag *worda; // [esp+0h] [ebp-14h]
  int i; // [esp+4h] [ebp-10h]
  int ia; // [esp+4h] [ebp-10h]
  int j; // [esp+8h] [ebp-Ch]
  int ja; // [esp+8h] [ebp-Ch]
  CPhonemeTag *test; // [esp+Ch] [ebp-8h] BYREF
  float maxshift; // [esp+10h] [ebp-4h]

  maxshift = 99999.898;
  if ( !forward )
  {
    v12 = this->m_Tags.m_Words.m_Size - 1;
    for ( ja = v12; v12 >= 0; ja = v12 )
    {
      v13 = this->m_Tags.m_Words.m_Memory.m_pMemory[v12];
      worda = v13;
      if ( v13 != nullptr )
      {
        v14 = v13->m_Phonemes.m_Size - 1;
        ia = v14;
        if ( v14 >= 0 )
        {
          while ( 1 )
          {
            v15 = v13->m_Phonemes.m_Memory.m_pMemory[v14];
            if ( v15 != nullptr && v15->m_bSelected )
            {
              forward = false;
              PhonemeEditor::GetTimeGapToNextPhoneme(
                this,
                forward: false,
                currentPhoneme: v15,
                ppword: nullptr,
                ppphoneme: (CPhonemeTag **)&forward);
              v16 = (CPhonemeTag *)forward;
              if ( forward )
              {
                while ( v16->m_bSelected )
                {
                  forward = false;
                  PhonemeEditor::GetTimeGapToNextPhoneme(
                    this,
                    forward: false,
                    currentPhoneme: v16,
                    ppword: nullptr,
                    ppphoneme: (CPhonemeTag **)&forward);
                  v16 = (CPhonemeTag *)forward;
                  if ( !forward )
                    goto LABEL_36;
                }
                m_flStartTime = v15->m_flStartTime;
                if ( allowcrop )
                  v18 = m_flStartTime - v16->m_flStartTime;
                else
                  v18 = m_flStartTime - v16->m_flEndTime;
                if ( maxshift > v18 )
                  maxshift = v18;
              }
            }
LABEL_36:
            v14 = --ia;
            if ( ia < 0 )
              break;
            v13 = worda;
          }
          v12 = ja;
        }
      }
      --v12;
    }
    return maxshift;
  }
  v4 = 0;
  i = 0;
  if ( this->m_Tags.m_Words.m_Size <= 0 )
    return maxshift;
  do
  {
    v5 = this->m_Tags.m_Words.m_Memory.m_pMemory[v4];
    word = v5;
    if ( v5 != nullptr )
    {
      v6 = 0;
      j = 0;
      if ( v5->m_Phonemes.m_Size > 0 )
      {
        do
        {
          v7 = v5->m_Phonemes.m_Memory.m_pMemory[v6];
          if ( v7 != nullptr && v7->m_bSelected )
          {
            test = nullptr;
            PhonemeEditor::GetTimeGapToNextPhoneme(this, forward, currentPhoneme: v7, ppword: nullptr, ppphoneme: &test);
            v8 = test;
            if ( test != nullptr )
            {
              while ( v8->m_bSelected )
              {
                test = nullptr;
                PhonemeEditor::GetTimeGapToNextPhoneme(
                  this,
                  forward,
                  currentPhoneme: v8,
                  ppword: nullptr,
                  ppphoneme: &test);
                v8 = test;
                if ( test == nullptr )
                  goto LABEL_16;
              }
              if ( allowcrop )
                m_flEndTime = v8->m_flEndTime;
              else
                m_flEndTime = v8->m_flStartTime;
              v10 = m_flEndTime - v7->m_flEndTime;
              if ( maxshift > v10 )
                maxshift = v10;
            }
          }
LABEL_16:
          v5 = word;
          v6 = j + 1;
          j = v6;
        }
        while ( v6 < word->m_Phonemes.m_Size );
        v4 = i;
      }
    }
    i = ++v4;
  }
  while ( v4 < this->m_Tags.m_Words.m_Size );
  return maxshift;
}

//------------------------------------------------------------------------------
// Address: 0x0046D8E0
// Name: private: void PhonemeEditor::SetDragLimit(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::SetDragLimit(PhonemeEditor *this, int dragtype)
{
  unsigned int v3; // eax
  float dt; // xmm0_4
  float nextW; // [esp+Ch] [ebp-10h]
  float prevW; // [esp+10h] [ebp-Ch]
  float nextP; // [esp+14h] [ebp-8h]
  float prevP; // [esp+18h] [ebp-4h]

  this->m_bLimitDrag = false;
  this->m_nLeftLimit = -1;
  this->m_nRightLimit = -1;
  nextW = PhonemeEditor::ComputeMaxWordShift(this, forward: true, allowcrop: false);
  prevW = PhonemeEditor::ComputeMaxWordShift(this, forward: false, allowcrop: false);
  nextP = PhonemeEditor::ComputeMaxPhonemeShift(this, forward: true, allowcrop: false);
  prevP = PhonemeEditor::ComputeMaxPhonemeShift(this, forward: false, allowcrop: false);
  if ( dragtype == 7 )
  {
    this->m_bLimitDrag = true;
    v3 = PhonemeEditor::PixelsForDeltaTime(this, dt: prevW);
    dt = nextW;
  }
  else
  {
    if ( dragtype != 8 )
    {
      this->m_nLeftLimit = -1;
      this->m_nRightLimit = -1;
      this->m_bLimitDrag = false;
      return;
    }
    this->m_bLimitDrag = true;
    v3 = PhonemeEditor::PixelsForDeltaTime(this, dt: prevP);
    dt = nextP;
  }
  this->m_nLeftLimit = v3;
  this->m_nRightLimit = PhonemeEditor::PixelsForDeltaTime(this, dt);
}

//------------------------------------------------------------------------------
// Address: 0x0046D9C0
// Name: public: void PhonemeEditor::ValidateSpeechAPIIndex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ValidateSpeechAPIIndex(PhonemeEditor *this)
{
  int v1; // eax
  Extractor *i; // ecx

  v1 = 0;
  if ( g_Extractors.m_Size > 0 )
  {
    for ( i = g_Extractors.m_Memory.m_pMemory; i->apitype != g_viewerSettings.speechapiindex; ++i )
    {
      if ( ++v1 >= g_Extractors.m_Size )
      {
        if ( g_Extractors.m_Size > 0 )
          g_viewerSettings.speechapiindex = g_Extractors.m_Memory.m_pMemory->apitype;
        return;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046DA00
// Name: private: bool PhonemeEditor::CheckSpeechAPI(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall PhonemeEditor::CheckSpeechAPI(PhonemeEditor *this)
{
  int v3; // eax
  Extractor *m_pMemory; // ecx

  if ( this->m_CurrentMode != MODE_PHONEMES )
    return false;
  if ( this->m_pPhonemeExtractor == nullptr )
  {
    v3 = 0;
    if ( g_Extractors.m_Size > 0 )
    {
      m_pMemory = g_Extractors.m_Memory.m_pMemory;
      while ( m_pMemory->apitype != g_viewerSettings.speechapiindex )
      {
        ++v3;
        ++m_pMemory;
        if ( v3 >= g_Extractors.m_Size )
          goto LABEL_10;
      }
      this->m_pPhonemeExtractor = m_pMemory->extractor;
    }
LABEL_10:
    if ( this->m_pPhonemeExtractor == nullptr )
      Con_ErrorPrintf(
        a1: (Color)g_viewerSettings.speechapiindex,
        fmt: "Couldn't find phoneme extractor %i\n",
        g_viewerSettings.speechapiindex);
  }
  return this->m_pPhonemeExtractor != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0046DA80
// Name: private: void PhonemeEditor::DrawScrubHandle(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall PhonemeEditor::DrawScrubHandle(PhonemeEditor *this@<ecx>, int a2@<edi>)
{
  CChoreoWidgetDrawHelper drawHelper; // [esp+4h] [ebp-68h] BYREF
  tagRECT rcHandle; // [esp+5Ch] [ebp-10h] BYREF

  PhonemeEditor::GetScrubHandleRect(this, a2, a3: (int)this, &rcHandle, clipped: true);
  rcHandle.left = 0;
  rcHandle.right = mxWidget::w2(this);
  CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: this, bounds: &rcHandle);
  PhonemeEditor::DrawScrubHandle(this, a2, &drawHelper);
  CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
}

//------------------------------------------------------------------------------
// Address: 0x0046DAD0
// Name: public: virtual void PhonemeEditor::redraw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::redraw(PhonemeEditor *this)
{
  HDC NumChannels; // ebx
  HWND Handle; // eax
  float v4; // xmm0_4
  int v5; // eax
  double v6; // st7
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  int v10; // eax
  Color gray_color; // eax
  HBRUSH SolidBrush; // edi
  int m_nLastExtractionResult; // edi
  unsigned int v14; // xmm0_4
  const char *ExtractionResultString; // eax
  CChoreoEvent *m_pEvent; // ecx
  const char *v17; // eax
  Color *v18; // eax
  double v19; // st7
  bool v20; // zf
  CAudioSource *m_pWaveFile; // edi
  int v22; // eax
  CAudioSource_vtbl *v23; // edx
  double v24; // st7
  int (__thiscall *SampleSize)(CAudioSource *); // eax
  int v26; // eax
  int v27; // eax
  double v28; // st7
  int m_Size; // edi
  int v30; // eax
  const char *Name; // eax
  const char *v32; // eax
  Color v33; // ecx
  char *Text; // eax
  CWordTag *SelectedWord; // eax
  float m_flStartTime; // xmm1_4
  char *Word; // eax
  int v38; // edi
  CPhonemeTag *SelectedPhoneme; // eax
  float v40; // xmm3_4
  float v41; // xmm2_4
  const char *v42; // eax
  int v43; // edi
  int v44; // eax
  mxSlider *m_pPlaybackRate; // ecx
  int v46; // ebx
  int v47; // xmm0_4
  int v48; // edi
  int v49; // edi
  int v50; // eax
  unsigned int v51; // xmm0_4
  unsigned int v52; // ecx
  int v53; // eax
  Color v54; // ecx
  double v55; // st7
  double v56; // st7
  Color *v57; // eax
  double m_flEndTime; // [esp+30h] [ebp-1300h]
  const char *Parameters; // [esp+34h] [ebp-12FCh]
  int v60; // [esp+38h] [ebp-12F8h]
  double v61; // [esp+38h] [ebp-12F8h]
  int top; // [esp+38h] [ebp-12F8h]
  double input; // [esp+3Ch] [ebp-12F4h]
  int inputa; // [esp+3Ch] [ebp-12F4h]
  int inputb; // [esp+3Ch] [ebp-12F4h]
  const char *input_4; // [esp+40h] [ebp-12F0h]
  int input_4a; // [esp+40h] [ebp-12F0h]
  int input_4b; // [esp+40h] [ebp-12F0h]
  int input_4c; // [esp+40h] [ebp-12F0h]
  char fmt[4096]; // [esp+50h] [ebp-12E0h] BYREF
  char v71[512]; // [esp+1050h] [ebp-2E0h] BYREF
  char v72[16]; // [esp+1250h] [ebp-E0h] BYREF
  char string[32]; // [esp+1260h] [ebp-D0h] BYREF
  tagRECT v74; // [esp+1280h] [ebp-B0h] BYREF
  CChoreoWidgetDrawHelper drawHelper; // [esp+1290h] [ebp-A0h] BYREF
  tagRECT rc; // [esp+12E8h] [ebp-48h] BYREF
  Color v77; // [esp+12F8h] [ebp-38h] BYREF
  float v78; // [esp+12FCh] [ebp-34h]
  float v79; // [esp+1300h] [ebp-30h]
  tagRECT Rect; // [esp+1304h] [ebp-2Ch] BYREF
  Color result; // [esp+1314h] [ebp-1Ch] BYREF
  tagRECT rcText; // [esp+1318h] [ebp-18h] BYREF
  Color clr; // [esp+1328h] [ebp-8h] BYREF
  Color root_color; // [esp+132Ch] [ebp-4h] BYREF

  if ( IFacePoserToolWindow::ToolCanDraw(this: &this->IFacePoserToolWindow) != 0 )
  {
    CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: this);
    this->HandleToolRedraw(this: &this->IFacePoserToolWindow, a2: &drawHelper);
    if ( this->m_pWaveFile == nullptr )
    {
LABEL_113:
      CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
      return;
    }
    NumChannels = (HDC)CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)&drawHelper);
    Handle = (HWND)mxWidget::getHandle(this);
    GetClientRect(hWnd: Handle, lpRect: &Rect);
    Rect.top += 60;
    Rect.bottom -= 95;
    InflateRect(lprc: &Rect, dx: -1, dy: -1);
    v4 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
    v79 = (float)this->m_nLeftOffset / v4;
    *(float *)&root_color = v4;
    v5 = mxWidget::w2(this);
    v78 = (float)((float)v5 / *(float *)&root_color) + v79;
    if ( g_PEColors[5].mode_number == -1 )
    {
      clr = g_PEColors[5].root_color;
    }
    else if ( g_PEColors[5].mode_number == this->m_CurrentMode )
    {
      clr = g_PEColors[5].root_color;
    }
    else
    {
      clr = g_PEColors[5].gray_color;
    }
    CChoreoWidgetDrawHelper::DrawColoredLine(
      this: &drawHelper,
      (HPEN__ *)&clr,
      style: 0,
      width: 1,
      x1: Rect.left,
      y1: Rect.bottom - this->m_nTickHeight,
      x2: Rect.right,
      y2: Rect.bottom - this->m_nTickHeight);
    if ( this->m_CurrentMode != MODE_EMPHASIS )
      PhonemeEditor::Emphasis_Redraw(this, &drawHelper, rcWorkSpace: &Rect);
    if ( g_PEColors[4].mode_number == -1 )
    {
      clr = g_PEColors[4].root_color;
    }
    else if ( g_PEColors[4].mode_number == this->m_CurrentMode )
    {
      clr = g_PEColors[4].root_color;
    }
    else
    {
      clr = g_PEColors[4].gray_color;
    }
    ((void (__thiscall *)(IFacePoserSound *, HDC, tagRECT *, Color *, _DWORD, _DWORD, CAudioSource *, bool, int, int))sound->RenderWavToDC)(
      a1: sound,
      a2: NumChannels,
      a3: &Rect,
      a4: &clr,
      a5: LODWORD(v79),
      a6: LODWORD(v78),
      a7: this->m_pWaveFile,
      a8: this->m_bSelectionActive,
      a9: this->m_nSelection[0],
      a10: this->m_nSelection[1]);
    v6 = SnapTime(input: v79, granularity: 0.5);
    *(float *)&clr = v6;
    if ( v78 >= v6 )
    {
      v7 = v78 - v79;
      v8 = *(float *)&clr;
      *(float *)&result = v78 - v79;
      do
      {
        v9 = (float)(v8 - v79) / v7;
        *(float *)&v77 = v9;
        if ( v9 >= 0.0 && v9 <= 1.0 )
        {
          if ( g_PEColors[6].mode_number == -1 )
          {
            root_color = g_PEColors[6].root_color;
          }
          else if ( g_PEColors[6].mode_number == this->m_CurrentMode )
          {
            root_color = g_PEColors[6].root_color;
          }
          else
          {
            root_color = g_PEColors[6].gray_color;
          }
          CChoreoWidgetDrawHelper::DrawColoredLine(
            this: &drawHelper,
            clr: (HPEN__ *)&root_color,
            style: 0,
            width: 1,
            x1: (int)(float)((float)Rect.right * v9),
            y1: Rect.top,
            x2: (int)(float)((float)Rect.right * v9),
            y2: Rect.bottom - this->m_nTickHeight);
          rc.bottom = Rect.bottom;
          rc.left = (int)(float)((float)Rect.right * *(float *)&v77);
          rc.top = Rect.bottom - 10;
          sprintf(string, format: "%.2f", *(float *)&clr);
          v10 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 400, fmt: string);
          rc.right = v10 + rc.left;
          OffsetRect(lprc: &rc, dx: v10 / -2, dy: 0);
          if ( g_PEColors[1].mode_number == -1 || g_PEColors[1].mode_number == this->m_CurrentMode )
            strcpy((char *)&root_color, "???");
          else
            root_color = g_PEColors[1].gray_color;
          CChoreoWidgetDrawHelper::DrawColoredText(
            this: &drawHelper,
            font: "Arial",
            pointsize: 9,
            weight: 400,
            clr: &root_color,
            rcText: &rc,
            fmt: string);
          v7 = *(float *)&result;
          v8 = *(float *)&clr;
        }
        v8 = v8 + 0.5;
        *(float *)&clr = v8;
      }
      while ( v78 >= v8 );
    }
    if ( g_PEColors[1].mode_number == -1 )
    {
      gray_color = g_PEColors[1].root_color;
    }
    else
    {
      gray_color = g_PEColors[1].root_color;
      if ( g_PEColors[1].mode_number != this->m_CurrentMode )
        gray_color = g_PEColors[1].gray_color;
    }
    root_color = gray_color;
    SolidBrush = CreateSolidBrush(color: gray_color._color[0] | ((gray_color._color[1] | (gray_color._color[2] << 8)) << 8));
    FrameRect(hDC: NumChannels, lprc: &Rect, hbr: SolidBrush);
    DeleteObject(ho: SolidBrush);
    *(_QWORD *)&v74.left = *(_QWORD *)&Rect.left;
    v74.right = _mm_loadl_epi64((const __m128i *)&Rect.right).m128i_u32[0];
    v74.top = 40;
    v74.bottom = 60;
    PhonemeEditor::DrawRelativeTags(this, &drawHelper, rc: &v74);
    m_nLastExtractionResult = this->m_nLastExtractionResult;
    *(_QWORD *)&rcText.left = *(_QWORD *)&Rect.left;
    v14 = _mm_loadl_epi64((const __m128i *)&Rect.right).m128i_u32[0];
    rcText.left = Rect.left + 5;
    rcText.right = v14 - 5;
    rcText.top = Rect.bottom + 5;
    rcText.bottom = Rect.bottom + 15;
    if ( m_nLastExtractionResult != 0 )
    {
      if ( g_PEColors[11].mode_number == -1 || g_PEColors[11].mode_number == this->m_CurrentMode )
        strcpy((char *)&clr, "???");
      else
        clr = g_PEColors[11].gray_color;
      switch ( m_nLastExtractionResult )
      {
        case 1:
          clr = *PhonemeEditor::PEColor(this, result: &root_color, colornum: 0xAu);
          break;
        case 2:
          clr = *PhonemeEditor::PEColor(this, result: &v77, colornum: 9u);
          break;
        case 3:
          clr = *PhonemeEditor::PEColor(this, &result, colornum: 8u);
          break;
        default:
          break;
      }
      ExtractionResultString = PhonemeEditor::GetExtractionResultString(this, resultCode: m_nLastExtractionResult);
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: &drawHelper,
        font: "Arial",
        pointsize: 9,
        weight: 400,
        &clr,
        &rcText,
        fmt: "Last Extraction Result:  %s",
        ExtractionResultString);
      OffsetRect(lprc: &rcText, dx: 0, dy: 10);
    }
    m_pEvent = this->m_pEvent;
    if ( m_pEvent == nullptr
      || (v17 = CChoreoEvent::GetParameters(this: m_pEvent), V_stristr(pStr: v17, pSearch: ".wav") != nullptr) )
    {
      if ( g_PEColors[1].mode_number == -1 || g_PEColors[1].mode_number == this->m_CurrentMode )
        strcpy((char *)&root_color, "???");
      else
        root_color = g_PEColors[1].gray_color;
      v19 = ((double (__thiscall *)(CAudioSource *))this->m_pWaveFile->GetRunningLength)(a1: this->m_pWaveFile);
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: &drawHelper,
        font: "Arial",
        pointsize: 9,
        weight: 400,
        clr: &root_color,
        &rcText,
        fmt: "File: %s, length %.2f seconds",
        this->m_WorkFile.m_szWaveFile,
        v19);
    }
    else
    {
      input = ((double (__thiscall *)(CAudioSource *))this->m_pWaveFile->GetRunningLength)(a1: this->m_pWaveFile);
      Parameters = CChoreoEvent::GetParameters(this: this->m_pEvent);
      v18 = PhonemeEditor::PEColor(this, &result, colornum: 1u);
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: &drawHelper,
        font: "Arial",
        pointsize: 9,
        weight: 400,
        clr: v18,
        &rcText,
        fmt: "Sound: '%s', file: %s, length %.2f seconds",
        Parameters,
        this->m_WorkFile.m_szWaveFile,
        input);
    }
    OffsetRect(lprc: &rcText, dx: 0, dy: 10);
    v20 = *((_BYTE *)&this->m_Tags + 74) == 0;
    *(float *)&clr = COERCE_FLOAT("duck other audio");
    if ( v20 )
      *(float *)&clr = COERCE_FLOAT("no ducking");
    if ( g_PEColors[1].mode_number == -1 || g_PEColors[1].mode_number == this->m_CurrentMode )
      strcpy((char *)&root_color, "???");
    else
      root_color = g_PEColors[1].gray_color;
    m_pWaveFile = this->m_pWaveFile;
    v22 = m_pWaveFile->SampleRate(this: m_pWaveFile);
    v23 = m_pWaveFile->__vftable;
    result = (Color)v22;
    v24 = (double)v22;
    result = (Color)this->m_pWaveFile;
    SampleSize = v23->SampleSize;
    *(float *)&v77 = v24;
    v26 = ((int (__thiscall *)(_DWORD, _DWORD))SampleSize)(a1: m_pWaveFile, a2: clr);
    v27 = ((int (__thiscall *)(CAudioSource *, int))m_pWaveFile->SampleRate)(a1: m_pWaveFile, a2: 8 * v26);
    v28 = ((double (__thiscall *)(_DWORD, _DWORD))*(_DWORD *)(**(_DWORD **)&result + 36))(a1: result, a2: v27);
    CChoreoWidgetDrawHelper::DrawColoredText(
      this: &drawHelper,
      font: "Arial",
      pointsize: 9,
      weight: 400,
      clr: &root_color,
      &rcText,
      fmt: "Number of samples %i at %ikhz (%i bits/sample) %s",
      (int)(v28 * *(float *)&v77),
      v60,
      inputa,
      input_4);
    OffsetRect(lprc: &rcText, dx: 0, dy: 10);
    m_Size = this->m_Tags.m_Words.m_Size;
    if ( g_PEColors[1].mode_number == -1 || g_PEColors[1].mode_number == this->m_CurrentMode )
      strcpy((char *)&root_color, "???");
    else
      root_color = g_PEColors[1].gray_color;
    input_4a = this->m_nTimeZoom;
    v30 = CSentence::CountPhonemes(this: &this->m_Tags);
    CChoreoWidgetDrawHelper::DrawColoredText(
      this: &drawHelper,
      font: "Arial",
      pointsize: 9,
      weight: 400,
      clr: &root_color,
      &rcText,
      fmt: "[ %i ] Words [ %i ] Phonemes / Zoom %i %%",
      m_Size,
      v30,
      input_4a);
    if ( this->m_pEvent != nullptr )
    {
      OffsetRect(lprc: &rcText, dx: 0, dy: 10);
      if ( g_PEColors[1].mode_number == -1 || g_PEColors[1].mode_number == this->m_CurrentMode )
        strcpy((char *)&root_color, "???");
      else
        root_color = g_PEColors[1].gray_color;
      Name = CChoreoEvent::GetName(this: this->m_pEvent);
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: &drawHelper,
        font: "Arial",
        pointsize: 9,
        weight: 400,
        clr: &root_color,
        &rcText,
        fmt: "Event %s",
        Name);
    }
    OffsetRect(lprc: &rcText, dx: 0, dy: 10);
    PhonemeEditor::CheckSpeechAPI(this);
    if ( this->m_pPhonemeExtractor != nullptr )
      v32 = this->m_pPhonemeExtractor->GetName(this: this->m_pPhonemeExtractor);
    else
      v32 = "Unknown Speech API";
    if ( g_PEColors[1].mode_number == -1 )
    {
      v33 = g_PEColors[1].root_color;
    }
    else
    {
      if ( g_PEColors[1].mode_number == this->m_CurrentMode )
      {
        strcpy((char *)&root_color, "???");
LABEL_79:
        CChoreoWidgetDrawHelper::DrawColoredText(
          this: &drawHelper,
          font: "Arial",
          pointsize: 9,
          weight: 400,
          clr: &root_color,
          &rcText,
          fmt: "Using:  %s",
          v32);
        Text = CSentence::GetText(this: &this->m_Tags);
        sprintf(string: fmt, format: "Sentence Text:  %s", Text);
        rcText.bottom = Rect.bottom;
        rcText.top = Rect.bottom + 5;
        rcText.right = (int)((double)((Rect.right - Rect.left) / 2) * 1.6);
        rcText.left = (Rect.right - Rect.left) / 2;
        CChoreoWidgetDrawHelper::CalcTextRect(
          this: &drawHelper,
          font: "Arial",
          pointsize: (HFONT__ *)9,
          weight: 400,
          maxwidth: rcText.left,
          &rcText,
          fmt);
        if ( g_PEColors[1].mode_number == -1 || g_PEColors[1].mode_number == this->m_CurrentMode )
          strcpy((char *)&root_color, "???");
        else
          root_color = g_PEColors[1].gray_color;
        CChoreoWidgetDrawHelper::DrawColoredTextMultiline(
          this: &drawHelper,
          font: "Arial",
          pointsize: (Color)9,
          weight: 400,
          clr: &root_color,
          &rcText,
          fmt);
        SelectedWord = PhonemeEditor::GetSelectedWord(this);
        if ( SelectedWord != nullptr )
        {
          m_flStartTime = SelectedWord->m_flStartTime;
          input_4b = SelectedWord->m_Phonemes.m_Size;
          v61 = (float)((float)(SelectedWord->m_flEndTime - SelectedWord->m_flStartTime) * 1000.0);
          m_flEndTime = SelectedWord->m_flEndTime;
          Word = CWordTag::GetWord(this: SelectedWord);
          sprintf(
            string: v71,
            format: "Word:  %s, start %.2f end %.2f, duration %.2f ms phonemes %i",
            Word,
            m_flStartTime,
            m_flEndTime,
            v61,
            input_4b);
          v38 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 400, fmt: v71);
          OffsetRect(lprc: &rcText, dx: 0, dy: rcText.bottom - rcText.top + 2);
          rcText.left = rcText.right - v38 - 10;
          rcText.bottom = rcText.top + 10;
          if ( g_PEColors[1].mode_number == -1 || g_PEColors[1].mode_number == this->m_CurrentMode )
            strcpy((char *)&root_color, "???");
          else
            root_color = g_PEColors[1].gray_color;
          CChoreoWidgetDrawHelper::DrawColoredText(
            this: &drawHelper,
            font: "Arial",
            pointsize: 9,
            weight: 400,
            clr: &root_color,
            &rcText,
            fmt: v71);
        }
        SelectedPhoneme = PhonemeEditor::GetSelectedPhoneme(this);
        if ( SelectedPhoneme != nullptr )
        {
          v40 = SelectedPhoneme->m_flEndTime;
          v41 = SelectedPhoneme->m_flStartTime;
          v42 = ConvertPhoneme(code: SelectedPhoneme->m_nPhonemeCode);
          sprintf(
            string: v71,
            format: "Phoneme:  %s, start %.2f end %.2f, duration %.2f ms",
            v42,
            v41,
            v40,
            (float)((float)(v40 - v41) * 1000.0));
          v43 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 400, fmt: v71);
          OffsetRect(lprc: &rcText, dx: 0, dy: rcText.bottom - rcText.top + 2);
          rcText.left = rcText.right - v43 - 10;
          rcText.bottom = rcText.top + 10;
          if ( g_PEColors[1].mode_number == -1 || g_PEColors[1].mode_number == this->m_CurrentMode )
            strcpy((char *)&root_color, "???");
          else
            root_color = g_PEColors[1].gray_color;
          CChoreoWidgetDrawHelper::DrawColoredText(
            this: &drawHelper,
            font: "Arial",
            pointsize: 9,
            weight: 400,
            clr: &root_color,
            &rcText,
            fmt: v71);
        }
        sprintf(string: v72, format: "Speed: %.2fx", this->m_flPlaybackRate);
        v44 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 400, fmt: v72);
        m_pPlaybackRate = this->m_pPlaybackRate;
        v46 = v44;
        *(_QWORD *)&rcText.left = *(_QWORD *)&Rect.left;
        v47 = _mm_loadl_epi64((const __m128i *)&Rect.right).m128i_u32[0];
        rcText.top = Rect.bottom + 60;
        rcText.right = v47;
        rcText.bottom = Rect.bottom + 70;
        v48 = mxWidget::x(this: m_pPlaybackRate);
        v49 = v48 - mxWidget::x(this);
        rcText.left = v49 + mxWidget::w(this: this->m_pPlaybackRate);
        rcText.right = v46 + rcText.left + 2;
        if ( g_PEColors[1].mode_number == -1 || g_PEColors[1].mode_number == this->m_CurrentMode )
          strcpy((char *)&root_color, "???");
        else
          root_color = g_PEColors[1].gray_color;
        CChoreoWidgetDrawHelper::DrawColoredText(
          this: &drawHelper,
          font: "Arial",
          pointsize: 9,
          weight: 400,
          clr: &root_color,
          &rcText,
          fmt: v72);
        if ( this->m_UndoStack.m_Size <= 0 )
          goto LABEL_107;
        v50 = CChoreoWidgetDrawHelper::CalcTextWidth(
                font: "Arial",
                pointsize: (HFONT__ *)9,
                weight: 400,
                fmt: "Undo levels:  %i/%i",
                this->m_nUndoLevel,
                this->m_UndoStack.m_Size);
        *(_QWORD *)&rcText.left = *(_QWORD *)&Rect.left;
        v51 = _mm_loadl_epi64((const __m128i *)&Rect.right).m128i_u32[0];
        rcText.top = Rect.bottom + 60;
        rcText.bottom = Rect.bottom + 70;
        rcText.right = v51 - 5;
        v52 = v51 - 5 - v50;
        v53 = this->m_UndoStack.m_Size;
        rcText.left = v52 - 10;
        if ( g_PEColors[9].mode_number == -1 )
        {
          v54 = g_PEColors[9].root_color;
        }
        else
        {
          if ( g_PEColors[9].mode_number == this->m_CurrentMode )
          {
            root_color = g_PEColors[9].root_color;
LABEL_106:
            CChoreoWidgetDrawHelper::DrawColoredText(
              this: &drawHelper,
              font: "Arial",
              pointsize: 9,
              weight: 400,
              clr: &root_color,
              &rcText,
              fmt: "Undo levels:  %i/%i",
              this->m_nUndoLevel,
              v53);
LABEL_107:
            v55 = ((double (__thiscall *)(CAudioSource *))this->m_pWaveFile->GetRunningLength)(a1: this->m_pWaveFile);
            v56 = (v55 - v79) / (v78 - v79);
            *(float *)&result = v56;
            if ( v56 >= 0.0 && *(float *)&result <= 1.0 )
            {
              input_4c = Rect.bottom - this->m_nTickHeight;
              inputb = (int)(float)((float)Rect.right * *(float *)&result);
              top = Rect.top;
              v57 = PhonemeEditor::PEColor(this, &result, colornum: 0x12u);
              CChoreoWidgetDrawHelper::DrawColoredLine(
                this: &drawHelper,
                clr: (HPEN__ *)v57,
                style: 2,
                width: 2,
                x1: inputb,
                y1: top,
                x2: inputb,
                y2: input_4c);
            }
            PhonemeEditor::DrawPhonemes(
              this,
              &drawHelper,
              rcWorkSpace: &Rect,
              sentence: &this->m_Tags,
              type: 0,
              showactive: true);
            PhonemeEditor::DrawPhonemes(
              this,
              &drawHelper,
              rcWorkSpace: &Rect,
              sentence: &this->m_TagsExt,
              type: 1,
              showactive: false);
            PhonemeEditor::DrawWords(
              this,
              &drawHelper,
              rcWorkSpace: &Rect,
              sentence: &this->m_Tags,
              type: 0,
              showactive: true);
            PhonemeEditor::DrawWords(
              this,
              &drawHelper,
              rcWorkSpace: &Rect,
              sentence: &this->m_TagsExt,
              type: (Color)1,
              showactive: false);
            if ( this->m_CurrentMode == MODE_EMPHASIS )
              PhonemeEditor::Emphasis_Redraw(this, &drawHelper, rcWorkSpace: &Rect);
            PhonemeEditor::DrawScrubHandle(this, a2: (int)&this->m_TagsExt, &drawHelper);
            goto LABEL_113;
          }
          v54 = g_PEColors[9].gray_color;
        }
        root_color = v54;
        goto LABEL_106;
      }
      v33 = g_PEColors[1].gray_color;
    }
    root_color = v33;
    goto LABEL_79;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046E8F0
// Name: private: void PhonemeEditor::ShowWordMenu(class CWordTag __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ShowWordMenu(PhonemeEditor *this, CWordTag *word, int mx, int my)
{
  mxPopupMenu *v5; // eax
  mxPopupMenu *v6; // ebx
  const char *v7; // eax
  const char *v8; // eax
  char *v9; // eax
  const char *v10; // eax
  int v11; // eax
  char *v12; // eax
  const char *v13; // eax
  int m_Size; // edx
  float v15; // xmm0_4
  int v16; // eax
  CWordTag **m_pMemory; // ecx
  float v18; // xmm1_4
  int v19; // eax
  int v20; // eax
  CWordTag **v21; // ecx
  int v22; // eax
  char *v23; // eax
  const char *v24; // eax
  char *v25; // eax
  const char *v26; // eax
  char *v27; // eax
  const char *v28; // eax
  char *v29; // eax
  const char *v30; // eax
  char *v31; // eax
  const char *v32; // eax
  const char *v33; // eax
  const char *v34; // eax
  const char *v35; // eax
  const char *v36; // eax
  const char *v37; // eax

  PhonemeEditor::CountSelected(this);
  v5 = (mxPopupMenu *)operator new(nSize: 0xCu);
  if ( v5 != nullptr )
    v6 = mxPopupMenu::mxPopupMenu(this: v5);
  else
    v6 = nullptr;
  v7 = va(fmt: "Edit sentence text...");
  mxPopupMenu::add(this: v6, item: v7, id: 1015);
  if ( this->m_nSelectedWordCount > 0 && word != nullptr )
  {
    mxMenu::addSeparator(this: v6);
    if ( this->m_nSelectedWordCount <= 1 )
    {
      v9 = CWordTag::GetWord(this: word);
      v8 = va(fmt: "'%s'", v9);
    }
    else
    {
      v8 = "words";
    }
    v10 = va(fmt: "Delete %s", v8);
    mxPopupMenu::add(this: v6, item: v10, id: 1027);
    if ( this->m_nSelectedWordCount == 1 )
    {
      v11 = PhonemeEditor::IndexOfWord(this, word);
      if ( v11 != -1 )
      {
        this->m_nClickedPhoneme = -1;
        this->m_nClickedWord = v11;
        v12 = CWordTag::GetWord(this: word);
        v13 = va(fmt: "Edit word '%s'...", v12);
        mxPopupMenu::add(this: v6, item: v13, id: 1028);
        m_Size = this->m_Tags.m_Words.m_Size;
        v15 = 99999.898;
        v16 = 0;
        if ( m_Size <= 0 )
          goto LABEL_17;
        m_pMemory = this->m_Tags.m_Words.m_Memory.m_pMemory;
        while ( *m_pMemory != word )
        {
          ++v16;
          ++m_pMemory;
          if ( v16 >= m_Size )
          {
            v18 = 0.0;
            goto LABEL_23;
          }
        }
        if ( v16 == -1 )
        {
LABEL_17:
          v18 = 0.0;
        }
        else
        {
          v19 = v16 + 1;
          if ( v19 < m_Size )
          {
            if ( v19 >= 0 )
              v18 = this->m_Tags.m_Words.m_Memory.m_pMemory[v19]->m_flStartTime - word->m_flEndTime;
            else
              v18 = 99999.898;
          }
          else
          {
            v18 = 99999.898;
          }
        }
LABEL_23:
        v20 = 0;
        if ( m_Size <= 0 )
          goto LABEL_29;
        v21 = this->m_Tags.m_Words.m_Memory.m_pMemory;
        while ( *v21 != word )
        {
          ++v20;
          ++v21;
          if ( v20 >= m_Size )
          {
            v15 = 0.0;
            goto LABEL_33;
          }
        }
        if ( v20 == -1 )
        {
LABEL_29:
          v15 = 0.0;
        }
        else
        {
          v22 = v20 - 1;
          if ( v22 < m_Size && v22 >= 0 )
            v15 = word->m_flStartTime - this->m_Tags.m_Words.m_Memory.m_pMemory[v22]->m_flEndTime;
        }
LABEL_33:
        if ( v18 > 0.02 || v15 > 0.02 )
        {
          mxMenu::addSeparator(this: v6);
          if ( v15 > 0.02 )
          {
            v23 = CWordTag::GetWord(this: word);
            v24 = va(fmt: "Insert word before '%s'...", v23);
            mxPopupMenu::add(this: v6, item: v24, id: 1029);
          }
          if ( v18 > 0.02 )
          {
            v25 = CWordTag::GetWord(this: word);
            v26 = va(fmt: "Insert word after '%s'...", v25);
            mxPopupMenu::add(this: v6, item: v26, id: 1030);
          }
        }
        if ( word->m_Phonemes.m_Size == 0 )
        {
          mxMenu::addSeparator(this: v6);
          v27 = CWordTag::GetWord(this: word);
          v28 = va(fmt: "Add phoneme to '%s'...", v27);
          mxPopupMenu::add(this: v6, item: v28, id: 1031);
        }
        mxMenu::addSeparator(this: v6);
        v29 = CWordTag::GetWord(this: word);
        v30 = va(fmt: "Select all words after '%s'", v29);
        mxPopupMenu::add(this: v6, item: v30, id: 1032);
        v31 = CWordTag::GetWord(this: word);
        v32 = va(fmt: "Select all words before '%s'", v31);
        mxPopupMenu::add(this: v6, item: v32, id: 1033);
      }
    }
  }
  if ( PhonemeEditor::AreSelectedWordsContiguous(this) && this->m_nSelectedWordCount > 1 )
  {
    mxMenu::addSeparator(this: v6);
    v33 = va(fmt: "Merge words");
    mxPopupMenu::add(this: v6, item: v33, id: 1016);
    if ( this->m_nSelectedWordCount == 2 )
    {
      v34 = va(fmt: "Separate words");
      mxPopupMenu::add(this: v6, item: v34, id: 1017);
    }
  }
  if ( this->m_nSelectedWordCount > 0 )
  {
    mxMenu::addSeparator(this: v6);
    v35 = va(fmt: "Deselect all");
    mxPopupMenu::add(this: v6, item: v35, id: 1036);
  }
  if ( this->m_Tags.m_Words.m_Size > 0 )
  {
    mxMenu::addSeparator(this: v6);
    v36 = va(fmt: "Cleanup words/phonemes");
    mxPopupMenu::add(this: v6, item: v36, id: 1037);
    if ( this->m_Tags.m_Words.m_Size > 0 )
    {
      mxMenu::addSeparator(this: v6);
      v37 = va(fmt: "Realign phonemes to words");
      mxPopupMenu::add(this: v6, item: v37, id: 1045);
    }
  }
  mxPopupMenu::popup(this: v6, widget: this, x: mx, y: my);
}

//------------------------------------------------------------------------------
// Address: 0x0046EC70
// Name: private: void PhonemeEditor::ShowPhonemeMenu(class CPhonemeTag __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ShowPhonemeMenu(PhonemeEditor *this, CPhonemeTag *pho, int mx, int my)
{
  Color v6; // ecx
  mxPopupMenu *v7; // eax
  mxPopupMenu *v8; // ebx
  CWordTag *WordForPhoneme; // eax
  int v10; // eax
  bool v11; // zf
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // eax
  const char *v19; // eax
  const char *v20; // eax
  const char *v21; // eax
  const char *v22; // eax
  const char *v23; // eax
  int m_nSelectedPhonemeCount; // eax
  const char *v25; // eax
  const char *v26; // eax
  const char *v27; // eax
  const char *v28; // eax
  const char *v29; // eax
  const char *v30; // eax
  int nextGapa; // [esp+8h] [ebp-4h]
  float nextGap; // [esp+8h] [ebp-4h]
  CWordTag *prevGap; // [esp+14h] [ebp+8h]
  float prevGapa; // [esp+14h] [ebp+8h]

  PhonemeEditor::CountSelected(this);
  this->m_nClickedPhoneme = -1;
  this->m_nClickedWord = -1;
  if ( pho != nullptr )
  {
    if ( CSentence::CountPhonemes(this: &this->m_Tags) != 0 )
    {
      v7 = (mxPopupMenu *)operator new(nSize: 0xCu);
      if ( v7 != nullptr )
        v8 = mxPopupMenu::mxPopupMenu(this: v7);
      else
        v8 = nullptr;
      WordForPhoneme = CSentence::GetWordForPhoneme(this: &this->m_Tags, phoneme: pho);
      prevGap = WordForPhoneme;
      if ( WordForPhoneme != nullptr )
      {
        nextGapa = PhonemeEditor::IndexOfWord(this, word: WordForPhoneme);
        v10 = CWordTag::IndexOfPhoneme(this: prevGap, tag: pho);
        v11 = this->m_nSelectedPhonemeCount == 1;
        this->m_nClickedPhoneme = v10;
        this->m_nClickedWord = nextGapa;
        if ( v11 )
        {
          v12 = ConvertPhoneme(code: pho->m_nPhonemeCode);
          v13 = va(fmt: "Edit '%s'...", v12);
          mxPopupMenu::add(this: v8, item: v13, id: 1004);
          nextGap = PhonemeEditor::GetTimeGapToNextPhoneme(
                      this,
                      forward: true,
                      currentPhoneme: pho,
                      ppword: nullptr,
                      ppphoneme: nullptr);
          prevGapa = PhonemeEditor::GetTimeGapToNextPhoneme(
                       this,
                       forward: false,
                       currentPhoneme: pho,
                       ppword: nullptr,
                       ppphoneme: nullptr);
          if ( nextGap > 0.0099999998 || prevGapa > 0.0099999998 )
          {
            mxMenu::addSeparator(this: v8);
            if ( prevGapa > 0.0099999998 )
            {
              v14 = ConvertPhoneme(code: pho->m_nPhonemeCode);
              v15 = va(fmt: "Insert phoneme before '%s'...", v14);
              mxPopupMenu::add(this: v8, item: v15, id: 1005);
            }
            if ( nextGap > 0.0099999998 )
            {
              v16 = ConvertPhoneme(code: pho->m_nPhonemeCode);
              v17 = va(fmt: "Insert phoneme after '%s'...", v16);
              mxPopupMenu::add(this: v8, item: v17, id: 1006);
            }
          }
          mxMenu::addSeparator(this: v8);
          v18 = ConvertPhoneme(code: pho->m_nPhonemeCode);
          v19 = va(fmt: "Select all phonemes after '%s'", v18);
          mxPopupMenu::add(this: v8, item: v19, id: 1034);
          v20 = ConvertPhoneme(code: pho->m_nPhonemeCode);
          v21 = va(fmt: "Select all phonemes before '%s'", v20);
          mxPopupMenu::add(this: v8, item: v21, id: 1035);
          mxMenu::addSeparator(this: v8);
        }
        if ( PhonemeEditor::AreSelectedPhonemesContiguous(this) && this->m_nSelectedPhonemeCount > 1 )
        {
          v22 = va(fmt: "Merge phonemes");
          mxPopupMenu::add(this: v8, item: v22, id: 1019);
          if ( this->m_nSelectedPhonemeCount == 2 )
          {
            v23 = va(fmt: "Separate phonemes");
            mxPopupMenu::add(this: v8, item: v23, id: 1020);
          }
          mxMenu::addSeparator(this: v8);
        }
        m_nSelectedPhonemeCount = this->m_nSelectedPhonemeCount;
        if ( m_nSelectedPhonemeCount >= 1 )
        {
          if ( m_nSelectedPhonemeCount == 1 )
          {
            v25 = ConvertPhoneme(code: pho->m_nPhonemeCode);
            v26 = va(fmt: "'%s'", v25);
          }
          else
          {
            v26 = "phonemes";
          }
          v27 = va(fmt: "Delete %s", v26);
          mxPopupMenu::add(this: v8, item: v27, id: 1007);
          mxMenu::addSeparator(this: v8);
          v28 = va(fmt: "Deselect all");
          mxPopupMenu::add(this: v8, item: v28, id: 1036);
        }
      }
      if ( this->m_Tags.m_Words.m_Size > 0 )
      {
        mxMenu::addSeparator(this: v8);
        v29 = va(fmt: "Cleanup words/phonemes");
        mxPopupMenu::add(this: v8, item: v29, id: 1037);
        if ( this->m_Tags.m_Words.m_Size > 0 )
        {
          mxMenu::addSeparator(this: v8);
          v30 = va(fmt: "Realign words to phonemes");
          mxPopupMenu::add(this: v8, item: v30, id: 1046);
        }
      }
      mxPopupMenu::popup(this: v8, widget: this, x: mx, y: my);
    }
    else
    {
      Con_Printf(a1: v6, fmt: "No phonemes, try extracting from .wav first\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046EF80
// Name: private: void PhonemeEditor::SelectSamples(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::SelectSamples(PhonemeEditor *this, int start, int end)
{
  int v4; // eax
  int v5; // ecx
  int v6; // edi
  CWordTag *v7; // eax

  if ( this->m_pWaveFile != nullptr )
  {
    v4 = end;
    v5 = start;
    if ( end < start )
    {
      v4 = start;
      v5 = end;
    }
    v6 = 0;
    this->m_nSelection[0] = v5;
    this->m_nSelection[1] = v4;
    for ( this->m_bSelectionActive = true; v6 < this->m_Tags.m_Words.m_Size; ++v6 )
    {
      v7 = this->m_Tags.m_Words.m_Memory.m_pMemory[v6];
      if ( v7 != nullptr )
        PhonemeEditor::ITER_SelectSpanningWords(this, word: v7, amount: 0.0);
    }
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F000
// Name: private: void PhonemeEditor::FinishMoveSelection(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::FinishMoveSelection(PhonemeEditor *this, int startx, int mx)
{
  int SampleForMouse; // edi
  int v5; // eax
  int i; // edi
  CWordTag *v7; // eax

  if ( this->m_pWaveFile != nullptr )
  {
    SampleForMouse = PhonemeEditor::GetSampleForMouse(this, mx: startx);
    v5 = PhonemeEditor::GetSampleForMouse(this, mx) - SampleForMouse;
    this->m_nSelection[0] += v5;
    this->m_nSelection[1] += v5;
    for ( i = 0; i < this->m_Tags.m_Words.m_Size; ++i )
    {
      v7 = this->m_Tags.m_Words.m_Memory.m_pMemory[i];
      if ( v7 != nullptr )
        PhonemeEditor::ITER_SelectSpanningWords(this, word: v7, amount: 0.0);
    }
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F080
// Name: private: void PhonemeEditor::FinishMoveSelectionStart(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::FinishMoveSelectionStart(PhonemeEditor *this, int startx, int mx)
{
  int SampleForMouse; // edi
  int i; // edi
  CWordTag *v6; // eax

  if ( this->m_pWaveFile != nullptr )
  {
    SampleForMouse = PhonemeEditor::GetSampleForMouse(this, mx: startx);
    this->m_nSelection[0] += PhonemeEditor::GetSampleForMouse(this, mx) - SampleForMouse;
    if ( this->m_nSelection[0] >= this->m_nSelection[1] )
    {
      this->m_nSelection[1] = 0;
      this->m_nSelection[0] = 0;
      this->m_bSelectionActive = false;
    }
    for ( i = 0; i < this->m_Tags.m_Words.m_Size; ++i )
    {
      v6 = this->m_Tags.m_Words.m_Memory.m_pMemory[i];
      if ( v6 != nullptr )
        PhonemeEditor::ITER_SelectSpanningWords(this, word: v6, amount: 0.0);
    }
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F120
// Name: private: void PhonemeEditor::FinishMoveSelectionEnd(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::FinishMoveSelectionEnd(PhonemeEditor *this, int startx, int mx)
{
  int SampleForMouse; // edi
  int i; // edi
  CWordTag *v6; // eax

  if ( this->m_pWaveFile != nullptr )
  {
    SampleForMouse = PhonemeEditor::GetSampleForMouse(this, mx: startx);
    this->m_nSelection[1] += PhonemeEditor::GetSampleForMouse(this, mx) - SampleForMouse;
    if ( this->m_nSelection[1] <= this->m_nSelection[0] )
    {
      this->m_nSelection[1] = 0;
      this->m_nSelection[0] = 0;
      this->m_bSelectionActive = false;
    }
    for ( i = 0; i < this->m_Tags.m_Words.m_Size; ++i )
    {
      v6 = this->m_Tags.m_Words.m_Memory.m_pMemory[i];
      if ( v6 != nullptr )
        PhonemeEditor::ITER_SelectSpanningWords(this, word: v6, amount: 0.0);
    }
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F1C0
// Name: private: void PhonemeEditor::FinishSelect(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::FinishSelect(PhonemeEditor *this, int startx, int mx)
{
  int SampleForMouse; // edi
  int v5; // eax

  if ( this->m_pWaveFile != nullptr && (int)abs32(startx - mx) >= 2 )
  {
    SampleForMouse = PhonemeEditor::GetSampleForMouse(this, mx: startx);
    v5 = PhonemeEditor::GetSampleForMouse(this, mx);
    PhonemeEditor::SelectSamples(this, start: SampleForMouse, end: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F210
// Name: private: void PhonemeEditor::OnImport(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::OnImport(PhonemeEditor *this)
{
  char filename[512]; // [esp+4h] [ebp-200h] BYREF

  if ( FacePoser_ShowOpenFileNameDialog(relative: filename, bufsize: 0x200u, subdir: "sound", wildcard: "*.txt") != 0 )
    PhonemeEditor::ImportValveDataChunk(this, tempfile: filename);
}

//------------------------------------------------------------------------------
// Address: 0x0046F260
// Name: private: void PhonemeEditor::ExportValveDataChunk(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ExportValveDataChunk(PhonemeEditor *this, const char *tempfile)
{
  Color v3; // ecx
  void *v4; // esi
  Color v5; // ecx
  CUtlBuffer buf; // [esp+4h] [ebp-30h] BYREF

  if ( this->m_Tags.m_Words.m_Size > 0 )
  {
    v4 = filesystem->Open(this: &filesystem->IBaseFileSystem, a2: tempfile, a3: "wb", a4: 0);
    if ( v4 != nullptr )
    {
      CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
      CSentence::SaveToBuffer(this: &this->m_Tags, &buf);
      filesystem->Write(this: &filesystem->IBaseFileSystem, a2: buf.m_Memory.m_pMemory, a3: buf.m_Put, a4: v4);
      filesystem->Close(this: &filesystem->IBaseFileSystem, a2: v4);
      Con_Printf(a1: v5, fmt: "Exported %i words to %s\n", this->m_Tags.m_Words.m_Size, tempfile);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
    else
    {
      Con_ErrorPrintf(
        a1: v3,
        fmt: "PhonemeEditor::ExportValveDataChunk:  Unable to write to %s (read-only?)\n",
        tempfile);
    }
  }
  else
  {
    Con_ErrorPrintf(a1: (Color)this, fmt: "PhonemeEditor::ExportValveDataChunk:  Sentence has no word data\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F350
// Name: private: void PhonemeEditor::WipeUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::WipeUndo(PhonemeEditor *this)
{
  void ***m_pMemory; // eax
  CSentence **v3; // edi
  void *v4; // ebx
  CSentence *v5; // ebx

  for ( ; this->m_UndoStack.m_Size > 0; --this->m_UndoStack.m_Size )
  {
    m_pMemory = (void ***)this->m_UndoStack.m_Memory.m_pMemory;
    v3 = (CSentence **)*m_pMemory;
    v4 = **m_pMemory;
    if ( v4 != nullptr )
    {
      CSentence::~CSentence(this: (CSentence *)**m_pMemory);
      free(pMem: v4);
    }
    v5 = v3[1];
    if ( v5 != nullptr )
    {
      CSentence::~CSentence(this: v3[1]);
      free(pMem: v5);
    }
    free(pMem: v3);
    if ( this->m_UndoStack.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_UndoStack.m_Memory.m_pMemory,
        src: this->m_UndoStack.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_UndoStack.m_Size - 1));
  }
  this->m_nUndoLevel = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0046F3F0
// Name: private: void PhonemeEditor::WipeRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::WipeRedo(PhonemeEditor *this)
{
  int i; // eax
  PhonemeEditor::PEUndo *v3; // edi
  CSentence *undo; // ebx
  CSentence *redo; // ebx
  int m_nUndoLevel; // ecx

  for ( i = this->m_nUndoLevel; this->m_UndoStack.m_Size > i; i = this->m_nUndoLevel )
  {
    v3 = this->m_UndoStack.m_Memory.m_pMemory[i];
    undo = v3->undo;
    if ( v3->undo != nullptr )
    {
      CSentence::~CSentence(this: v3->undo);
      free(pMem: undo);
    }
    redo = v3->redo;
    if ( redo != nullptr )
    {
      CSentence::~CSentence(this: v3->redo);
      free(pMem: redo);
    }
    free(pMem: v3);
    m_nUndoLevel = this->m_nUndoLevel;
    if ( this->m_UndoStack.m_Size - m_nUndoLevel - 1 > 0 )
      _V_memmove(
        dest: &this->m_UndoStack.m_Memory.m_pMemory[m_nUndoLevel],
        src: &this->m_UndoStack.m_Memory.m_pMemory[m_nUndoLevel + 1],
        count: 4 * (this->m_UndoStack.m_Size - m_nUndoLevel - 1));
    --this->m_UndoStack.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F4A0
// Name: private: void PhonemeEditor::ShowContextMenu_Phonemes(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ShowContextMenu_Phonemes(PhonemeEditor *this, int mx, int my)
{
  mxPopupMenu *v4; // eax
  mxPopupMenu *v5; // ebx
  mxPopupMenu *v6; // eax
  mxPopupMenu *v7; // esi
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // eax
  const char *v19; // eax
  const char *v20; // eax
  const char *v21; // eax
  const char *v22; // eax
  int m_Size; // ecx
  mxPopupMenu *v24; // esi
  int v25; // eax
  Extractor *m_pMemory; // edx
  mxPopupMenu *v27; // eax
  int v28; // eax
  Extractor *v29; // edx
  mxPopupMenu *v30; // eax
  const char *v31; // eax
  const char *v32; // eax

  PhonemeEditor::CountSelected(this);
  v4 = (mxPopupMenu *)operator new(nSize: 0xCu);
  if ( v4 != nullptr )
    v5 = mxPopupMenu::mxPopupMenu(this: v4);
  else
    v5 = nullptr;
  if ( this->m_pWaveFile != nullptr )
  {
    v6 = (mxPopupMenu *)operator new(nSize: 0xCu);
    if ( v6 != nullptr )
      v7 = mxPopupMenu::mxPopupMenu(this: v6);
    else
      v7 = nullptr;
    v8 = va(fmt: "Original");
    mxPopupMenu::add(this: v7, item: v8, id: 1002);
    v9 = va(fmt: "Edited");
    mxPopupMenu::add(this: v7, item: v9, id: 1012);
    if ( this->m_bSelectionActive )
    {
      v10 = va(fmt: "Selection");
      mxPopupMenu::add(this: v7, item: v10, id: 1008);
    }
    mxMenu::addMenu(this: v5, item: "Play", menu: v7);
    if ( sound->IsSoundPlaying(this: sound, a2: this->m_pMixer) )
    {
      v11 = va(fmt: "Cancel playback");
      mxPopupMenu::add(this: v5, item: v11, id: 1014);
    }
    mxMenu::addSeparator(this: v5);
  }
  v12 = va(fmt: "Load...");
  mxPopupMenu::add(this: v5, item: v12, id: 1018);
  if ( this->m_pWaveFile != nullptr )
  {
    v13 = va(fmt: "Save");
    mxPopupMenu::add(this: v5, item: v13, id: 1013);
  }
  if ( this->m_bSelectionActive )
  {
    mxMenu::addSeparator(this: v5);
    v14 = va(fmt: "Deselect");
    mxPopupMenu::add(this: v5, item: v14, id: 1011);
  }
  if ( this->m_pWaveFile != nullptr )
  {
    mxMenu::addSeparator(this: v5);
    v15 = va(fmt: "Redo Extraction");
    mxPopupMenu::add(this: v5, item: v15, id: 1009);
    if ( this->m_nSelectedWordCount < 1 || PhonemeEditor::AreSelectedWordsContiguous(this) )
    {
      v16 = va(fmt: "Redo Extraction of selected words");
      mxPopupMenu::add(this: v5, item: v16, id: 1010);
    }
    if ( this->m_pWaveFile != nullptr && this->m_TagsExt.m_Words.m_Size != 0 )
    {
      mxMenu::addSeparator(this: v5);
      v17 = va(fmt: "Commit extraction");
      mxPopupMenu::add(this: v5, item: v17, id: 1021);
      v18 = va(fmt: "Clear extraction");
      mxPopupMenu::add(this: v5, item: v18, id: 1022);
    }
  }
  if ( this->m_nUndoLevel != 0 || this->m_UndoStack.m_Size != 0 )
  {
    mxMenu::addSeparator(this: v5);
    if ( this->m_nUndoLevel != 0 )
    {
      v19 = va(fmt: "Undo");
      mxPopupMenu::add(this: v5, item: v19, id: 5038);
    }
    if ( this->m_nUndoLevel != this->m_UndoStack.m_Size )
    {
      v20 = va(fmt: "Redo");
      mxPopupMenu::add(this: v5, item: v20, id: 5039);
    }
    v21 = va(fmt: "Clear Undo Info");
    mxPopupMenu::add(this: v5, item: v21, id: 1038);
  }
  if ( this->m_Tags.m_Words.m_Size > 0 )
  {
    mxMenu::addSeparator(this: v5);
    v22 = va(fmt: "Cleanup words/phonemes");
    mxPopupMenu::add(this: v5, item: v22, id: 1037);
  }
  m_Size = g_Extractors.m_Size;
  v24 = nullptr;
  v25 = 0;
  if ( g_Extractors.m_Size > 0 )
  {
    m_pMemory = g_Extractors.m_Memory.m_pMemory;
    while ( m_pMemory->apitype != SPEECH_API_SAPI )
    {
      ++v25;
      ++m_pMemory;
      if ( v25 >= g_Extractors.m_Size )
        goto LABEL_44;
    }
    v27 = (mxPopupMenu *)operator new(nSize: 0xCu);
    if ( v27 != nullptr )
      v24 = mxPopupMenu::mxPopupMenu(this: v27);
    else
      v24 = nullptr;
    mxPopupMenu::add(this: v24, item: "Microsoft Speech API", id: 1050);
    if ( g_viewerSettings.speechapiindex == 0 )
      mxMenu::setChecked(this: v24, id: 1050, b: true);
    m_Size = g_Extractors.m_Size;
  }
LABEL_44:
  v28 = 0;
  if ( m_Size > 0 )
  {
    v29 = g_Extractors.m_Memory.m_pMemory;
    while ( v29->apitype != SPEECH_API_LIPSINC )
    {
      ++v28;
      ++v29;
      if ( v28 >= m_Size )
        goto LABEL_55;
    }
    if ( v24 == nullptr )
    {
      v30 = (mxPopupMenu *)operator new(nSize: 0xCu);
      if ( v30 != nullptr )
        v24 = mxPopupMenu::mxPopupMenu(this: v30);
      else
        v24 = nullptr;
    }
    mxPopupMenu::add(this: v24, item: "Lipsinc Speech API", id: 1051);
    if ( g_viewerSettings.speechapiindex == 1 )
      mxMenu::setChecked(this: v24, id: 1051, b: true);
  }
LABEL_55:
  mxMenu::addSeparator(this: v5);
  mxMenu::addMenu(this: v5, item: "Change Speech API", menu: v24);
  if ( this->m_pWaveFile != nullptr )
  {
    mxMenu::addSeparator(this: v5);
    if ( this->m_Tags.m_Words.m_Size > 0 )
      mxPopupMenu::add(this: v5, item: "Export word data to .txt...", id: 1075);
    mxPopupMenu::add(this: v5, item: "Import word data from .txt...", id: 1076);
    v31 = "Disable";
    if ( *((_BYTE *)&this->m_Tags + 74) == 0 )
      v31 = "Enable";
    v32 = va(fmt: "%s Voice Duck", v31);
    mxPopupMenu::add(this: v5, item: v32, id: 1077);
  }
  mxPopupMenu::popup(this: v5, widget: this, x: mx, y: my);
}

//------------------------------------------------------------------------------
// Address: 0x0046F8B0
// Name: private: void PhonemeEditor::ShowContextMenu(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ShowContextMenu(PhonemeEditor *this, int mx, int my)
{
  if ( this->m_CurrentMode == MODE_EMPHASIS )
    PhonemeEditor::ShowContextMenu_Emphasis(this, mx, my);
  else
    PhonemeEditor::ShowContextMenu_Phonemes(this, mx, my);
}

//------------------------------------------------------------------------------
// Address: 0x0046F8D0
// Name: private: void PhonemeEditor::SelectNextPhoneme(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::SelectNextPhoneme(PhonemeEditor *this, int direction)
{
  Color v3; // ecx
  CWordTag *SelectedWord; // eax
  int v5; // ecx
  const char *v6; // eax
  CWordTag *v7; // edi
  int m_Size; // esi
  int v9; // eax
  CPhonemeTag **m_pMemory; // edx
  CPhonemeTag *v11; // ecx
  int v12; // eax
  void (__thiscall *redraw)(struct PhonemeEditor *); // edx
  int i; // [esp+4h] [ebp-8h]
  CWordTag **j; // [esp+8h] [ebp-4h]

  if ( this->m_CurrentMode == MODE_PHONEMES )
  {
    PhonemeEditor::CountSelected(this);
    if ( this->m_nSelectedPhonemeCount != 1 )
    {
      if ( this->m_nSelectedWordCount != 1 )
        return;
      SelectedWord = PhonemeEditor::GetSelectedWord(this);
      if ( SelectedWord == nullptr || SelectedWord->m_Phonemes.m_Size <= 0 )
        return;
      this->m_nSelectedPhonemeCount = 1;
      if ( direction != 0 )
        v5 = SelectedWord->m_Phonemes.m_Size - 1;
      else
        v5 = 0;
      v3 = (Color)SelectedWord->m_Phonemes.m_Memory.m_pMemory[v5];
      *(_BYTE *)(*(_DWORD *)&v3 + 12) = 1;
    }
    v6 = "left";
    if ( direction != -1 )
      v6 = "right";
    Con_Printf(a1: v3, fmt: "Move to next phoneme %s\n", v6);
    i = 0;
    if ( this->m_Tags.m_Words.m_Size > 0 )
    {
      for ( j = this->m_Tags.m_Words.m_Memory.m_pMemory; ; ++j )
      {
        v7 = *j;
        if ( *j != nullptr )
        {
          m_Size = v7->m_Phonemes.m_Size;
          v9 = 0;
          if ( m_Size > 0 )
            break;
        }
LABEL_20:
        if ( ++i >= this->m_Tags.m_Words.m_Size )
          return;
      }
      m_pMemory = v7->m_Phonemes.m_Memory.m_pMemory;
      while ( 1 )
      {
        v11 = *m_pMemory;
        if ( *m_pMemory != nullptr && v11->m_bSelected )
          break;
        ++v9;
        ++m_pMemory;
        if ( v9 >= m_Size )
          goto LABEL_20;
      }
      v12 = direction + v9;
      if ( v12 >= 0 )
      {
        if ( v12 >= m_Size )
          v12 = 0;
      }
      else
      {
        v12 = m_Size - 1;
      }
      v11->m_bSelected = false;
      v7->m_Phonemes.m_Memory.m_pMemory[v12]->m_bSelected = true;
      redraw = this->redraw;
      this->m_bWordsActive = false;
      redraw(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046FA00
// Name: private: void PhonemeEditor::OnSAPI(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::OnSAPI(PhonemeEditor *this)
{
  if ( this->m_CurrentMode == MODE_PHONEMES )
  {
    g_viewerSettings.speechapiindex = 0;
    this->m_pPhonemeExtractor = nullptr;
    PhonemeEditor::CheckSpeechAPI(this);
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046FA30
// Name: private: void PhonemeEditor::OnLipSinc(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::OnLipSinc(PhonemeEditor *this)
{
  if ( this->m_CurrentMode == MODE_PHONEMES )
  {
    g_viewerSettings.speechapiindex = 1;
    this->m_pPhonemeExtractor = nullptr;
    PhonemeEditor::CheckSpeechAPI(this);
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046FA70
// Name: private: void PhonemeEditor::UnloadPhonemeConverters(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::UnloadPhonemeConverters(PhonemeEditor *this)
{
  int v1; // esi
  int v2; // edi

  v1 = g_Extractors.m_Size - 1;
  if ( g_Extractors.m_Size - 1 < 0 )
  {
    g_Extractors.m_Size = 0;
    this->m_pPhonemeExtractor = nullptr;
  }
  else
  {
    v2 = v1;
    do
    {
      Sys_UnloadModule(pModule: g_Extractors.m_Memory.m_pMemory[v2].module);
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    g_Extractors.m_Size = 0;
    this->m_pPhonemeExtractor = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046FAE0
// Name: public: virtual void PhonemeEditor::OnDelete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::OnDelete(PhonemeEditor *this)
{
  CAudioSource *m_pWaveFile; // ecx
  char fn[512]; // [esp+4h] [ebp-200h] BYREF

  if ( this->m_pWaveFile != nullptr )
  {
    V_snprintf(pDest: fn, maxLen: 512, pFormat: "%s%s", this->m_WorkFile.m_szBasePath, this->m_WorkFile.m_szWorkingFile);
    filesystem->RemoveFile(this: filesystem, a2: fn, a3: "GAME");
  }
  m_pWaveFile = this->m_pWaveFile;
  if ( m_pWaveFile != nullptr )
    ((void (__thiscall *)(CAudioSource *, int))m_pWaveFile->dtr_CAudioSource)(a1: m_pWaveFile, a2: 1);
  this->m_pWaveFile = nullptr;
  CSentence::Reset(this: &this->m_Tags);
  CSentence::Reset(this: &this->m_TagsExt);
  PhonemeEditor::UnloadPhonemeConverters(this);
}

//------------------------------------------------------------------------------
// Address: 0x0046FB80
// Name: private: void PhonemeEditor::OnExport(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::OnExport(PhonemeEditor *this)
{
  char filename[512]; // [esp+4h] [ebp-200h] BYREF

  if ( this->m_pWaveFile != nullptr
    && FacePoser_ShowSaveFileNameDialog(relative: filename, bufsize: 0x200u, subdir: "sound", wildcard: "*.txt") != 0 )
  {
    V_SetExtension(path: filename, extension: ".txt", pathStringLength: 512);
    PhonemeEditor::ExportValveDataChunk(this, tempfile: filename);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046FBF0
// Name: private: void PhonemeEditor::StoreValveDataChunk(class IterateOutputRIFF __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::StoreValveDataChunk(PhonemeEditor *this, IterateOutputRIFF *store)
{
  CUtlBuffer buf; // [esp+4h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  CSentence::SaveToBuffer(this: &this->m_Tags, &buf);
  IterateOutputRIFF::ChunkWriteData(this: store, pOutput: buf.m_Memory.m_pMemory, size: buf.m_Put);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0046FC50
// Name: private: void PhonemeEditor::SaveLinguisticData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::SaveLinguisticData(PhonemeEditor *this)
{
  char v2; // bl
  unsigned int NumChannels; // eax
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned __int16 *v6; // esi
  int v7; // eax
  unsigned int NumEvents; // eax
  unsigned __int16 v9; // cx
  __int64 v10; // xmm0_8
  int v11; // eax
  int v12; // [esp-14h] [ebp-2BCh]
  char fullout[512]; // [esp+4h] [ebp-2A4h] BYREF
  OutFileRIFF riffout; // [esp+204h] [ebp-A4h] BYREF
  CUtlBuffer buf; // [esp+220h] [ebp-88h] BYREF
  tWAVEFORMATEX format; // [esp+250h] [ebp-58h] BYREF
  InFileRIFF riff; // [esp+264h] [ebp-44h] BYREF
  IterateOutputRIFF store; // [esp+274h] [ebp-34h] BYREF
  IterateRIFF walk; // [esp+290h] [ebp-18h] BYREF

  if ( this->m_pWaveFile == nullptr )
    return;
  InFileRIFF::InFileRIFF(this: &riff, pFileName: this->m_WorkFile.m_szWaveFile, io: &io_in_0);
  IterateRIFF::IterateRIFF(this: &walk, &riff, size: riff.m_riffSize);
  V_snprintf(
    pDest: fullout,
    maxLen: 512,
    pFormat: "%s%s",
    this->m_WorkFile.m_szBasePath,
    this->m_WorkFile.m_szWorkingFile);
  OutFileRIFF::OutFileRIFF(this: &riffout, pFileName: fullout, io: &io_out_0);
  IterateOutputRIFF::IterateOutputRIFF(this: &store, riff: &riffout);
  v2 = 0;
  if ( !IterateRIFF::ChunkAvailable(this: &walk) )
    goto LABEL_16;
  do
  {
    IterateOutputRIFF::ChunkGetPosition(this: &store);
    NumChannels = CAudioSourceMemWave::GetNumChannels(this: &walk);
    IterateOutputRIFF::ChunkStart(this: &store, chunkname: NumChannels);
    v4 = CAudioSourceMemWave::GetNumChannels(this: &walk);
    if ( v4 == 544501094 )
    {
      NumEvents = CChoreoScene::GetNumEvents(this: &walk);
      v6 = (unsigned __int16 *)operator new(nSize: NumEvents);
      IterateRIFF::ChunkRead(this: &walk, pOutput: v6);
      v9 = v6[8];
      *(_QWORD *)&format.wFormatTag = *(_QWORD *)v6;
      v10 = *((_QWORD *)v6 + 1);
      format.cbSize = v9;
      *(_QWORD *)&format.nAvgBytesPerSec = v10;
      v11 = CChoreoScene::GetNumEvents(this: &walk);
      IterateOutputRIFF::ChunkWriteData(this: &store, pOutput: v6, size: v11);
LABEL_13:
      free(pMem: v6);
      goto LABEL_14;
    }
    if ( v4 != 1413563478 )
    {
      if ( v4 != 1635017060 )
      {
        IterateOutputRIFF::CopyChunkData(this: &store, input: &walk);
        goto LABEL_14;
      }
      v5 = CChoreoScene::GetNumEvents(this: &walk);
      v6 = (unsigned __int16 *)operator new(nSize: v5);
      IterateRIFF::ChunkRead(this: &walk, pOutput: v6);
      v12 = CChoreoScene::GetNumEvents(this: &walk);
      v7 = CAudioSourceMemWave::GetNumChannels(this: &walk);
      PhonemeEditor::ResampleChunk(
        this,
        &store,
        &format,
        chunkname: v7,
        buffer: (char *)v6,
        buffersize: v12,
        start_silence: 0,
        end_silence: 0);
      goto LABEL_13;
    }
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
    CSentence::SaveToBuffer(this: &this->m_Tags, &buf);
    IterateOutputRIFF::ChunkWriteData(this: &store, pOutput: buf.m_Memory.m_pMemory, size: buf.m_Put);
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    v2 = 1;
LABEL_14:
    IterateOutputRIFF::ChunkFinish(this: &store);
    IterateRIFF::ChunkNext(this: &walk);
  }
  while ( IterateRIFF::ChunkAvailable(this: &walk) );
  if ( v2 == 0 )
  {
LABEL_16:
    IterateOutputRIFF::ChunkStart(this: &store, chunkname: 0x54414456u);
    PhonemeEditor::StoreValveDataChunk(this, &store);
    IterateOutputRIFF::ChunkFinish(this: &store);
  }
  OutFileRIFF::~OutFileRIFF(this: &riffout);
  InFileRIFF::~InFileRIFF(this: &riff);
}

//------------------------------------------------------------------------------
// Address: 0x0046FE90
// Name: private: void PhonemeEditor::CommitChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::CommitChanges(PhonemeEditor *this)
{
  const char *v2; // eax

  PhonemeEditor::SaveLinguisticData(this);
  MakeFileWriteable(filename: this->m_WorkFile.m_szWaveFile);
  if ( IsFileWriteable(filename: this->m_WorkFile.m_szWaveFile) )
  {
    FPCopyFile(source: this->m_WorkFile.m_szWorkingFile, dest: this->m_WorkFile.m_szWaveFile, bCheckOut: true);
    _Msg(a1: "Changes saved to '%s'\n", this->m_WorkFile.m_szWaveFile);
    this->m_WorkFile.m_bDirty = false;
    IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: defaultValue);
  }
  else
  {
    v2 = va(fmt: "Unable to save file '%s'. File is read-only or in use.", this->m_WorkFile.m_szWaveFile);
    mxMessageBox(parent: nullptr, msg: v2, title: g_appTitle, style: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046FF10
// Name: private: void PhonemeEditor::ClearUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ClearUndo(PhonemeEditor *this)
{
  PhonemeEditor::WipeUndo(this);
  PhonemeEditor::WipeRedo(this);
  this->m_WorkFile.m_bDirty = false;
  PhonemeEditor::WipeUndo(this);
  this->redraw(this);
  IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x0046FF60
// Name: private: void PhonemeEditor::ScrubThink(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ScrubThink(PhonemeEditor *this, float dt, bool scrubbing)
{
  float *p_m_flScrub; // ebx
  CAudioMixer **p_m_pMixer; // edi
  double v6; // st7
  float m_flScrubTarget; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  int v10; // eax
  float v11; // xmm2_4
  float v12; // xmm1_4
  int v13; // eax
  int v14; // ebx
  int v15; // eax
  int v16; // edi
  int v17; // eax
  CChoreoWidgetDrawHelper drawHelper; // [esp+1Ch] [ebp-6Ch] BYREF
  tagRECT rcArea; // [esp+74h] [ebp-14h] BYREF
  float duration; // [esp+84h] [ebp-4h]
  int cursample; // [esp+90h] [ebp+8h]

  p_m_flScrub = &this->m_flScrub;
  PhonemeEditor::ClampTimeToSelectionInterval(this, timeval: &this->m_flScrub);
  PhonemeEditor::ClampTimeToSelectionInterval(this, timeval: &this->m_flScrubTarget);
  if ( this->m_flScrubTarget == *p_m_flScrub && !scrubbing )
  {
    if ( sound->IsSoundPlaying(this: sound, a2: this->m_pMixer) )
      sound->StopSound(this: sound, a2: this->m_pMixer);
    return;
  }
  if ( this->m_pWaveFile != nullptr )
  {
    p_m_pMixer = &this->m_pMixer;
    if ( this->m_pMixer == nullptr || !sound->IsSoundPlaying(this: sound, a2: this->m_pMixer) )
    {
      *p_m_pMixer = nullptr;
      PhonemeEditor::SaveLinguisticData(this);
      ((void (__stdcall *)(_DWORD, int, char *, CAudioMixer **))sound->PlaySound_2)(
        a1: 0,
        a2: 1065353216,
        a3: this->m_WorkFile.m_szWorkingFile,
        a4: &this->m_pMixer);
    }
    if ( *p_m_pMixer != nullptr )
    {
      ((void (__stdcall *)(bool))(*p_m_pMixer)->SetDirection)(a1: *p_m_flScrub <= this->m_flScrubTarget);
      v6 = ((double (__thiscall *)(CAudioSource *))this->m_pWaveFile->GetRunningLength)(a1: this->m_pWaveFile);
      duration = v6;
      if ( v6 != 0.0 )
      {
        m_flScrubTarget = this->m_flScrubTarget;
        v8 = *p_m_flScrub;
        v9 = m_flScrubTarget - *p_m_flScrub;
        if ( v9 <= 0.0 )
          v10 = -1;
        else
          v10 = 1;
        v11 = this->m_flPlaybackRate * dt;
        if ( v10 <= 0 )
        {
          if ( v11 > COERCE_FLOAT(LODWORD(v9) ^ _mask__NegFloat_) )
          {
            *p_m_flScrub = m_flScrubTarget;
            goto LABEL_22;
          }
          v12 = v8 - v11;
        }
        else
        {
          if ( v11 > v9 )
          {
            *p_m_flScrub = m_flScrubTarget;
LABEL_22:
            v13 = (int)(*p_m_pMixer)->GetSource(this: *p_m_pMixer);
            cursample = (int)(float)((float)(*p_m_flScrub / duration)
                                   * (float)(*(int (__thiscall **)(int))(*(_DWORD *)v13 + 20))(a1: v13));
            v14 = cursample - (*p_m_pMixer)->GetSamplePosition(this: *p_m_pMixer);
            v15 = (int)(*p_m_pMixer)->GetSource(this: *p_m_pMixer);
            if ( (int)abs32(v14) > (int)(float)((float)(*(int (__thiscall **)(int))(*(_DWORD *)v15 + 12))(a1: v15)
                                              * 0.0099999998) )
              (*p_m_pMixer)->SetSamplePosition(this: *p_m_pMixer, a2: cursample, a3: true);
            v16 = (int)*p_m_pMixer;
            (*(void (__thiscall **)(int, int))(*(_DWORD *)v16 + 44))(a1: v16, a2: 1);
            rcArea.left = 0;
            rcArea.right = mxWidget::w2(this);
            v17 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow);
            rcArea.top = v17 + 14;
            rcArea.bottom = v17 + 25;
            CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: this, bounds: &rcArea);
            PhonemeEditor::DrawScrubHandle(this, a2: v16, &drawHelper);
            if ( scrubbing )
              MatSysWindow::Frame(this: g_pMatSysWindow);
            CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
            return;
          }
          v12 = v8 + v11;
        }
        *p_m_flScrub = v12;
        goto LABEL_22;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004701C0
// Name: public: virtual bool PhonemeEditor::CanClose(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall PhonemeEditor::CanClose(PhonemeEditor *this)
{
  const char *v2; // eax
  int v3; // eax

  if ( this->m_WorkFile.m_bDirty )
  {
    v2 = va(fmt: "Save current changes to %s", this->m_WorkFile.m_szWaveFile);
    v3 = mxMessageBox(parent: this, msg: v2, title: "Phoneme Editor", style: 34);
    if ( v3 == 2 )
      return 0;
    if ( v3 == 0 )
      PhonemeEditor::CommitChanges(this);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00470220
// Name: public: void PhonemeEditor::SetCurrentWaveFile(char const __near *,bool,class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::SetCurrentWaveFile(
        PhonemeEditor *this,
        const char *wavefile,
        bool force,
        CChoreoEvent *event)
{
  const char *v5; // eax
  int v6; // eax
  CAudioSource *m_pWaveFile; // ecx
  int v8; // edi
  int v9; // edi
  Color v10; // ecx
  PhonemeEditor::CWorkFile *p_m_WorkFile; // [esp-8h] [ebp-410h]
  char fn[512]; // [esp+8h] [ebp-400h] BYREF
  char fullpath[512]; // [esp+208h] [ebp-200h] BYREF

  if ( force || _V_stricmp(s1: this->m_WorkFile.m_szWaveFile, s2: wavefile) != 0 )
  {
    PhonemeEditor::StopPlayback(this);
    if ( this->m_WorkFile.m_bDirty )
    {
      v5 = va(fmt: "Save current changes to %s", this->m_WorkFile.m_szWaveFile);
      v6 = mxMessageBox(parent: this, msg: v5, title: "Phoneme Editor", style: 34);
      if ( v6 == 2 )
        return;
      if ( v6 == 0 )
        PhonemeEditor::CommitChanges(this);
    }
    if ( this->m_CurrentMode == MODE_PHONEMES )
    {
      this->m_nLastExtractionResult = 0;
      CSentence::Reset(this: &this->m_TagsExt);
      this->redraw(this);
    }
    CSentence::Reset(this: &this->m_Tags);
    CSentence::Reset(this: &this->m_TagsExt);
    this->m_nSelection[1] = 0;
    this->m_nSelection[0] = 0;
    this->m_bSelectionActive = false;
    if ( this->m_pWaveFile != nullptr )
    {
      V_snprintf(
        pDest: fn,
        maxLen: 512,
        pFormat: "%s%s",
        this->m_WorkFile.m_szBasePath,
        this->m_WorkFile.m_szWorkingFile);
      filesystem->RemoveFile(this: filesystem, a2: fn, a3: "GAME");
    }
    m_pWaveFile = this->m_pWaveFile;
    if ( m_pWaveFile != nullptr )
      ((void (__thiscall *)(CAudioSource *, int))m_pWaveFile->dtr_CAudioSource)(a1: m_pWaveFile, a2: 1);
    this->m_pWaveFile = nullptr;
    this->m_WorkFile.m_bDirty = false;
    PhonemeEditor::WipeUndo(this);
    this->redraw(this);
    IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: defaultValue);
    this->m_pEvent = event;
    this->m_pWaveFile = sound->LoadSound(this: sound, a2: wavefile);
    V_strncpy(pDest: this->m_WorkFile.m_szWaveFile, pSrc: wavefile, maxLen: 256);
    filesystem->RelativePathToFullPath(
      this: filesystem,
      a2: wavefile,
      a3: "GAME",
      a4: fullpath,
      a5: 512,
      a6: (PathTypeFilter_t)0,
      a7: nullptr);
    v8 = _V_strlen(str: fullpath);
    v9 = v8 - _V_strlen(str: wavefile) + 1;
    this->m_WorkFile.m_szBasePath[0] = 0;
    if ( v9 >= 0 )
    {
      V_strncpy(pDest: this->m_WorkFile.m_szBasePath, pSrc: fullpath, maxLen: v9);
      this->m_WorkFile.m_szBasePath[v9] = 0;
    }
    V_StripExtension(in: wavefile, out: this->m_WorkFile.m_szWorkingFile, outSize: 256);
    V_strncat(pDest: this->m_WorkFile.m_szWorkingFile, pSrc: "_work.wav", destBufferSize: 0x100u, max_chars_to_copy: -1);
    V_FixSlashes(pname: this->m_WorkFile.m_szWaveFile, separator: 92);
    V_FixSlashes(pname: this->m_WorkFile.m_szWorkingFile, separator: 92);
    V_FixSlashes(pname: this->m_WorkFile.m_szBasePath, separator: 92);
    p_m_WorkFile = &this->m_WorkFile;
    if ( this->m_pWaveFile != nullptr )
    {
      Con_Printf(a1: v10, fmt: "Current .wav file set to %s\n", p_m_WorkFile->m_szWaveFile);
      CWaveBrowser::SetCurrent(
        this: (CWaveBrowser *)`CUtlRBTree<CUtlSymbolTree::FileTreePath,int,bool (__cdecl *)(CUtlSymbolTree::FileTreePath const &,CUtlSymbolTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements,
        filename: this->m_WorkFile.m_szWaveFile);
      FPCopyFile(source: this->m_WorkFile.m_szWaveFile, dest: this->m_WorkFile.m_szWorkingFile, bCheckOut: false);
      MakeFileWriteable(filename: this->m_WorkFile.m_szWorkingFile);
      PhonemeEditor::ReadLinguisticTags(this, a2: (int)this->m_WorkFile.m_szWaveFile);
      this->m_nSelection[1] = 0;
      this->m_nSelection[0] = 0;
      this->m_bSelectionActive = false;
      PhonemeEditor::RepositionHSlider(this);
    }
    else
    {
      Con_ErrorPrintf(a1: v10, fmt: "Couldn't set current .wav file to %s\n", p_m_WorkFile->m_szWaveFile);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004704C0
// Name: public: virtual void PhonemeEditor::Think(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::Think(PhonemeEditor *this, float dt)
{
  if ( this->m_nTimeZoom != 0 )
  {
    PhonemeEditor::ScrubThink(this: (PhonemeEditor *)((char *)this - 12), dt, scrubbing: this->m_nStartY == 12);
    if ( this->m_nTimeZoomStep != 0 && !sound->IsSoundPlaying(this: sound, a2: (CAudioMixer *)this->m_nTimeZoomStep) )
      this->m_nTimeZoomStep = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470520
// Name: private: void PhonemeEditor::PlayEditedWave(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::PlayEditedWave(PhonemeEditor *this, bool selection)
{
  PhonemeEditor::StopPlayback(this);
  if ( this->m_pWaveFile != nullptr )
  {
    FacePoser_EnsurePhonemesLoaded();
    PhonemeEditor::SaveLinguisticData(this);
    this->m_flScrub = 0.0;
    PhonemeEditor::ClampTimeToSelectionInterval(this, timeval: &this->m_flScrub);
    this->m_flScrubTarget = this->m_pWaveFile->GetRunningLength(this: this->m_pWaveFile);
    PhonemeEditor::ClampTimeToSelectionInterval(this, timeval: &this->m_flScrubTarget);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470580
// Name: private: void PhonemeEditor::RedoPhonemeExtraction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::RedoPhonemeExtraction(PhonemeEditor *this)
{
  bool v2; // zf
  IPhonemeExtractor_vtbl *v3; // edi
  int v4; // eax
  CAudioSource *m_pWaveFile; // ecx
  CAudioSource_vtbl *v6; // edx
  double v7; // st7
  float (__thiscall *GetRunningLength)(CAudioSource *); // eax
  double v9; // st7
  CAudioSource *v10; // ecx
  CAudioSource_vtbl *v11; // eax
  double v12; // st7
  int v13; // eax
  CAudioSource *v14; // ecx
  int v15; // eax
  CAudioSource *v16; // ecx
  float (__thiscall *TrueSampleSize)(CAudioSource *); // edx
  double v18; // st7
  double v19; // st7
  int i; // edi
  CWordTag *v21; // eax
  double v22; // st5
  int m_uiEndByte; // edx
  double v24; // st4
  int v25; // edx
  CPhonemeTag *v26; // ecx
  int v27; // ebx
  double v28; // st4
  HWND Handle; // eax
  char filename[512]; // [esp+4h] [ebp-204h] BYREF
  float v31; // [esp+204h] [ebp-4h]

  if ( this->m_CurrentMode == MODE_PHONEMES && PhonemeEditor::CheckSpeechAPI(this) )
  {
    v2 = this->m_pWaveFile == nullptr;
    this->m_nLastExtractionResult = 0;
    if ( !v2 )
    {
      PhonemeEditor::SaveLinguisticData(this);
      CSentence::Reset(this: &this->m_TagsExt);
      V_snprintf(
        pDest: filename,
        maxLen: 512,
        pFormat: "%s%s",
        this->m_WorkFile.m_szBasePath,
        this->m_WorkFile.m_szWorkingFile);
      v3 = this->m_pPhonemeExtractor->__vftable;
      v4 = this->m_pWaveFile->SampleRate(this: this->m_pWaveFile);
      m_pWaveFile = this->m_pWaveFile;
      v6 = m_pWaveFile->__vftable;
      v31 = *(float *)&v4;
      v7 = (double)v4;
      GetRunningLength = v6->GetRunningLength;
      v31 = v7;
      v9 = ((double (__thiscall *)(CAudioSource *))GetRunningLength)(a1: m_pWaveFile);
      v10 = this->m_pWaveFile;
      v11 = v10->__vftable;
      v31 = v9 * v31;
      v12 = ((double (__thiscall *)(CAudioSource *, void (__usercall *)(Color@<ecx>, const char *, ...), CSentence *, CSentence *))v11->TrueSampleSize)(
              a1: v10,
              a2: Con_Printf,
              a3: &this->m_Tags,
              a4: &this->m_TagsExt);
      v13 = ((int (__thiscall *)(IPhonemeExtractor *, char *, int))v3->Extract)(
              a1: this->m_pPhonemeExtractor,
              a2: filename,
              a3: (int)(v12 * v31));
      v14 = this->m_pWaveFile;
      this->m_nLastExtractionResult = v13;
      v15 = v14->SampleRate(this: v14);
      v16 = this->m_pWaveFile;
      v31 = *(float *)&v15;
      TrueSampleSize = v16->TrueSampleSize;
      v31 = (float)v15;
      v18 = ((double (__thiscall *)(CAudioSource *))TrueSampleSize)(a1: v16);
      v19 = v18 * v31;
      for ( i = 0; i < this->m_TagsExt.m_Words.m_Size; ++i )
      {
        v21 = this->m_TagsExt.m_Words.m_Memory.m_pMemory[i];
        if ( v21 != nullptr )
        {
          v22 = 1.0 / v19;
          m_uiEndByte = v21->m_uiEndByte;
          v21->m_flStartTime = (double)v21->m_uiStartByte * (1.0 / v19);
          v24 = (double)(int)v21->m_uiEndByte;
          if ( m_uiEndByte < 0 )
            v24 = v24 + 4294967300.0;
          v25 = 0;
          for ( v21->m_flEndTime = v24 * v22; v25 < v21->m_Phonemes.m_Size; ++v25 )
          {
            v26 = v21->m_Phonemes.m_Memory.m_pMemory[v25];
            if ( v26 != nullptr )
            {
              v27 = v26->m_uiEndByte;
              v26->m_flStartTime = (double)v26->m_uiStartByte * v22;
              v28 = (double)(int)v26->m_uiEndByte;
              if ( v27 < 0 )
                v28 = v28 + 4294967300.0;
              v26->m_flEndTime = v28 * v22;
            }
          }
        }
      }
      Handle = (HWND)mxWidget::getHandle(this);
      SetFocus(hWnd: Handle);
      this->redraw(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470750
// Name: private: void PhonemeEditor::LoadWaveFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::LoadWaveFile(PhonemeEditor *this)
{
  char filename[512]; // [esp+4h] [ebp-200h] BYREF

  if ( FacePoser_ShowOpenFileNameDialog(relative: filename, bufsize: 0x200u, subdir: "sound", wildcard: "*.wav") != 0 )
  {
    PhonemeEditor::StopPlayback(this);
    PhonemeEditor::SetCurrentWaveFile(this, wavefile: filename, force: false, event: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004707A0
// Name: private: void PhonemeEditor::AddFocusRect(struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::AddFocusRect(PhonemeEditor *this, tagRECT *rc)
{
  __int64 v2; // xmm0_8
  HWND Handle; // eax
  int m_Size; // [esp-Ch] [ebp-44h]
  PhonemeEditor::CFocusRect fr; // [esp+0h] [ebp-38h] BYREF
  tagRECT rcFocus; // [esp+20h] [ebp-18h] BYREF
  tagPOINT offset; // [esp+30h] [ebp-8h] BYREF

  *(_QWORD *)&rcFocus.left = *(_QWORD *)&rc->left;
  v2 = *(_QWORD *)&rc->right;
  offset.x = 0;
  offset.y = 0;
  *(_QWORD *)&rcFocus.right = v2;
  Handle = (HWND)mxWidget::getHandle(this);
  ClientToScreen(hWnd: Handle, lpPoint: &offset);
  OffsetRect(lprc: &rcFocus, dx: offset.x, dy: offset.y);
  m_Size = this->m_FocusRects.m_Size;
  fr.m_rcFocus = rcFocus;
  fr.m_rcOrig = rcFocus;
  CUtlVector<PhonemeEditor::CFocusRect,CUtlMemory<PhonemeEditor::CFocusRect,int>>::InsertBefore(
    this: (CUtlVector<CChoreoView::CFocusRect,CUtlMemory<CChoreoView::CFocusRect,int> > *)&this->m_FocusRects,
    elem: m_Size,
    src: (const CChoreoView::CFocusRect *)&fr);
}

//------------------------------------------------------------------------------
// Address: 0x00470830
// Name: private: void PhonemeEditor::PushUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::PushUndo(PhonemeEditor *this)
{
  CSentence *v2; // eax
  CSentence *v3; // esi
  PhonemeEditor::PEUndo *v4; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  PhonemeEditor::PEUndo **m_pMemory; // edx
  int v8; // eax
  PhonemeEditor::PEUndo **v9; // edi
  PhonemeEditor::PEUndo *undo; // [esp+Ch] [ebp-4h]

  this->m_bRedoPending = true;
  PhonemeEditor::WipeRedo(this);
  v2 = (CSentence *)operator new(nSize: 0x4Cu);
  if ( v2 != nullptr )
    v3 = CSentence::CSentence(this: v2);
  else
    v3 = nullptr;
  CSentence::operator=(this: v3, src: &this->m_Tags);
  v4 = (PhonemeEditor::PEUndo *)operator new(nSize: 8u);
  v4->undo = v3;
  v4->redo = nullptr;
  m_Size = this->m_UndoStack.m_Size;
  m_nAllocationCount = this->m_UndoStack.m_Memory.m_nAllocationCount;
  undo = v4;
  if ( m_Size + 1 > m_nAllocationCount )
  {
    CUtlMemory<IFacePoserToolWindow *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_UndoStack,
      num: m_Size - m_nAllocationCount + 1);
    v4 = undo;
  }
  ++this->m_UndoStack.m_Size;
  m_pMemory = this->m_UndoStack.m_Memory.m_pMemory;
  v8 = this->m_UndoStack.m_Size - m_Size - 1;
  this->m_UndoStack.m_pElements = m_pMemory;
  if ( v8 > 0 )
  {
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
    v4 = undo;
  }
  v9 = &this->m_UndoStack.m_Memory.m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = v4;
  ++this->m_nUndoLevel;
}

//------------------------------------------------------------------------------
// Address: 0x00470900
// Name: private: void PhonemeEditor::ShiftSelectedPhoneme(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ShiftSelectedPhoneme(PhonemeEditor *this, int direction)
{
  Color v3; // ecx
  int m_nSelectedPhonemeCount; // eax
  HWND Handle; // eax
  float v6; // xmm0_4
  int v7; // eax
  Color v9; // ecx
  float v10; // xmm0_4
  void (__thiscall *redraw)(struct PhonemeEditor *); // eax
  Color v12; // ecx
  const char *v13; // eax
  BOOL v14; // [esp-4h] [ebp-28h]
  const char *v15; // [esp+0h] [ebp-24h]
  tagRECT rc; // [esp+Ch] [ebp-18h] BYREF
  float starttime; // [esp+1Ch] [ebp-8h]
  float maxmove; // [esp+20h] [ebp-4h]
  int movetime; // [esp+2Ch] [ebp+8h]

  if ( this->m_CurrentMode != MODE_PHONEMES )
    return;
  PhonemeEditor::CountSelected(this);
  m_nSelectedPhonemeCount = this->m_nSelectedPhonemeCount;
  if ( m_nSelectedPhonemeCount == 0 )
  {
    Con_Printf(a1: v3, fmt: "Can't shift phonemes, none selected\n");
    return;
  }
  if ( m_nSelectedPhonemeCount != 1 )
  {
    Con_Printf(a1: v3, fmt: "Can only shift one phoneme at a time via keyboard\n");
    return;
  }
  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &rc);
  rc.top += 60;
  rc.bottom -= 95;
  InflateRect(lprc: &rc, dx: -1, dy: -1);
  v6 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
  starttime = (float)this->m_nLeftOffset / v6;
  maxmove = v6;
  v7 = mxWidget::w2(this);
  v14 = direction > 0;
  *(float *)&movetime = (float)((float)((float)((float)((float)v7 / maxmove) + starttime) - starttime)
                              / (float)(rc.right - rc.left))
                      * (float)direction;
  maxmove = PhonemeEditor::ComputeMaxPhonemeShift(this, forward: v14, allowcrop: false);
  v10 = maxmove;
  if ( direction <= 0 )
  {
    LODWORD(v10) = LODWORD(maxmove) ^ _mask__NegFloat_;
    if ( COERCE_FLOAT(LODWORD(maxmove) ^ _mask__NegFloat_) <= *(float *)&movetime )
      goto LABEL_11;
    v15 = "Further shift is blocked on left\n";
  }
  else
  {
    if ( *(float *)&movetime <= maxmove )
      goto LABEL_11;
    v15 = "Further shift is blocked on right\n";
  }
  *(float *)&movetime = v10;
  Con_Printf(a1: v9, fmt: v15);
LABEL_11:
  if ( COERCE_FLOAT(movetime & _mask__AbsFloat_) >= 0.000099999997 )
  {
    this->m_WorkFile.m_bDirty = true;
    IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
    PhonemeEditor::PushUndo(this);
    PhonemeEditor::TraversePhonemes(
      this,
      pfn: (void (__thiscall *)(char *, CPhonemeTag *, CWordTag *, int))PhonemeEditor::ITER_MoveSelectedPhonemes,
      fparam: 0.0,
      fparama: movetime);
    PhonemeEditor::PushRedo(this);
    redraw = this->redraw;
    this->m_bWordsActive = false;
    redraw(this);
    v13 = "left";
    if ( direction != -1 )
      v13 = "right";
    Con_Printf(a1: v12, fmt: "Shift phoneme %s\n", v13);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470AD0
// Name: private: void PhonemeEditor::ExtendSelectedPhonemeEndTime(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ExtendSelectedPhonemeEndTime(PhonemeEditor *this, int direction)
{
  HWND Handle; // eax
  float v4; // xmm0_4
  int v5; // eax
  void (__thiscall *redraw)(struct PhonemeEditor *); // edx
  Color v8; // ecx
  const char *v9; // eax
  tagRECT rc; // [esp+Ch] [ebp-18h] BYREF
  float starttime; // [esp+1Ch] [ebp-8h]
  float v12; // [esp+20h] [ebp-4h]
  int movetime; // [esp+2Ch] [ebp+8h]

  if ( this->m_CurrentMode == MODE_PHONEMES )
  {
    PhonemeEditor::CountSelected(this);
    if ( this->m_nSelectedPhonemeCount == 1 )
    {
      Handle = (HWND)mxWidget::getHandle(this);
      GetClientRect(hWnd: Handle, lpRect: &rc);
      rc.top += 60;
      rc.bottom -= 95;
      InflateRect(lprc: &rc, dx: -1, dy: -1);
      v4 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
      starttime = (float)this->m_nLeftOffset / v4;
      v12 = v4;
      v5 = mxWidget::w2(this);
      *(float *)&movetime = (float)((float)((float)((float)((float)v5 / v12) + starttime) - starttime)
                                  / (float)(rc.right - rc.left))
                          * (float)direction;
      this->m_WorkFile.m_bDirty = true;
      IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
      PhonemeEditor::PushUndo(this);
      PhonemeEditor::TraversePhonemes(
        this,
        pfn: (void (__thiscall *)(char *, CPhonemeTag *, CWordTag *, int))PhonemeEditor::ITER_ExtendSelectedPhonemeEndTimes,
        fparam: 0.0,
        fparama: movetime);
      PhonemeEditor::PushRedo(this);
      redraw = this->redraw;
      this->m_bWordsActive = false;
      redraw(this);
      v9 = "left";
      if ( direction != -1 )
        v9 = "right";
      Con_Printf(a1: v8, fmt: "Extend phoneme end %s\n", v9);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470C10
// Name: private: void PhonemeEditor::ShiftSelectedWord(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ShiftSelectedWord(PhonemeEditor *this, int direction)
{
  Color v3; // ecx
  int m_nSelectedWordCount; // eax
  HWND Handle; // eax
  float v6; // xmm0_4
  int v7; // eax
  float v9; // xmm2_4
  Color v10; // ecx
  float v11; // xmm0_4
  void (__thiscall *redraw)(struct PhonemeEditor *); // eax
  Color v13; // ecx
  const char *v14; // eax
  bool v15; // [esp-4h] [ebp-28h]
  const char *v16; // [esp+0h] [ebp-24h]
  tagRECT rc; // [esp+Ch] [ebp-18h] BYREF
  float starttime; // [esp+1Ch] [ebp-8h]
  float maxmove; // [esp+20h] [ebp-4h]
  int movetime; // [esp+2Ch] [ebp+8h]

  if ( this->m_CurrentMode != MODE_PHONEMES )
    return;
  PhonemeEditor::CountSelected(this);
  m_nSelectedWordCount = this->m_nSelectedWordCount;
  if ( m_nSelectedWordCount == 0 )
  {
    Con_Printf(a1: v3, fmt: "Can't shift words, none selected\n");
    return;
  }
  if ( m_nSelectedWordCount != 1 )
  {
    Con_Printf(a1: v3, fmt: "Can only shift one word at a time via keyboard\n");
    return;
  }
  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &rc);
  rc.top += 60;
  rc.bottom -= 95;
  InflateRect(lprc: &rc, dx: -1, dy: -1);
  v6 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
  starttime = (float)this->m_nLeftOffset / v6;
  maxmove = v6;
  v7 = mxWidget::w2(this);
  v15 = direction > 0;
  v9 = (float)((float)((float)((float)((float)v7 / maxmove) + starttime) - starttime) / (float)(rc.right - rc.left))
     * (float)direction;
  *(float *)&movetime = v9;
  maxmove = PhonemeEditor::ComputeMaxWordShift(this, forward: v15, allowcrop: false);
  v11 = maxmove;
  if ( direction <= 0 )
  {
    LODWORD(v11) = LODWORD(maxmove) ^ _mask__NegFloat_;
    if ( COERCE_FLOAT(LODWORD(maxmove) ^ _mask__NegFloat_) <= v9 )
      goto LABEL_11;
    v16 = "Further shift is blocked on left\n";
  }
  else
  {
    if ( v9 <= maxmove )
      goto LABEL_11;
    v16 = "Further shift is blocked on right\n";
  }
  *(float *)&movetime = v11;
  Con_Printf(a1: v10, fmt: v16);
  v9 = v11;
LABEL_11:
  if ( COERCE_FLOAT(LODWORD(v9) & _mask__AbsFloat_) >= 0.000099999997 )
  {
    this->m_WorkFile.m_bDirty = true;
    IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
    PhonemeEditor::PushUndo(this);
    PhonemeEditor::TraverseWords(
      this,
      pfn: (void (__thiscall *)(char *, CWordTag *, int))PhonemeEditor::ITER_MoveSelectedWords,
      fparam: 0.0,
      fparama: movetime);
    PhonemeEditor::PushRedo(this);
    redraw = this->redraw;
    this->m_bWordsActive = true;
    redraw(this);
    v14 = "left";
    if ( direction != -1 )
      v14 = "right";
    Con_Printf(a1: v13, fmt: "Shift word %s\n", v14);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470DE0
// Name: private: void PhonemeEditor::ExtendSelectedWordEndTime(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ExtendSelectedWordEndTime(PhonemeEditor *this, int direction)
{
  HWND Handle; // eax
  float v4; // xmm0_4
  int v5; // eax
  void (__thiscall *redraw)(struct PhonemeEditor *); // edx
  Color v8; // ecx
  const char *v9; // eax
  tagRECT rc; // [esp+Ch] [ebp-18h] BYREF
  float starttime; // [esp+1Ch] [ebp-8h]
  float v12; // [esp+20h] [ebp-4h]
  int movetime; // [esp+2Ch] [ebp+8h]

  if ( this->m_CurrentMode == MODE_PHONEMES )
  {
    PhonemeEditor::CountSelected(this);
    if ( this->m_nSelectedWordCount == 1 )
    {
      Handle = (HWND)mxWidget::getHandle(this);
      GetClientRect(hWnd: Handle, lpRect: &rc);
      rc.top += 60;
      rc.bottom -= 95;
      InflateRect(lprc: &rc, dx: -1, dy: -1);
      v4 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
      starttime = (float)this->m_nLeftOffset / v4;
      v12 = v4;
      v5 = mxWidget::w2(this);
      *(float *)&movetime = (float)((float)((float)((float)((float)v5 / v12) + starttime) - starttime)
                                  / (float)(rc.right - rc.left))
                          * (float)direction;
      this->m_WorkFile.m_bDirty = true;
      IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
      PhonemeEditor::PushUndo(this);
      PhonemeEditor::TraverseWords(
        this,
        pfn: (void (__thiscall *)(char *, CWordTag *, int))PhonemeEditor::ITER_ExtendSelectedWordEndTimes,
        fparam: 0.0,
        fparama: movetime);
      PhonemeEditor::PushRedo(this);
      redraw = this->redraw;
      this->m_bWordsActive = true;
      redraw(this);
      v9 = "left";
      if ( direction != -1 )
        v9 = "right";
      Con_Printf(a1: v8, fmt: "Extend word end %s\n", v9);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470F20
// Name: private: void PhonemeEditor::OnMouseMove(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::OnMouseMove(PhonemeEditor *this, float event)
{
  mxEvent *v2; // edi
  char *v4; // ebx
  bool v5; // zf
  HWND Handle; // eax
  int v7; // edx
  int v8; // edi
  int v9; // eax
  int m_nStartX; // eax
  __int64 v11; // xmm0_8
  int v12; // ebx
  int m_nStartY; // ebx
  int v14; // ecx
  int v15; // eax
  HWND v16; // eax
  int IsMouseOverBoundary; // eax
  HCURSOR CursorA; // eax
  HICON__ *v19; // eax
  CPhonemeTag *PhonemeTagUnderMouse; // ebx
  HCURSOR v21; // eax
  int x_low; // ebx
  HWND v23; // eax
  float v24; // xmm0_4
  CChoreoWidgetDrawHelper drawHelper; // [esp+14h] [ebp-8Ch] BYREF
  tagPOINT offset; // [esp+6Ch] [ebp-34h] BYREF
  tagRECT rcFocus; // [esp+74h] [ebp-2Ch] BYREF
  int i; // [esp+84h] [ebp-1Ch]
  float dt; // [esp+88h] [ebp-18h]
  tagRECT rcWork; // [esp+8Ch] [ebp-14h] BYREF
  int mx; // [esp+9Ch] [ebp-4h] BYREF

  v2 = (mxEvent *)LODWORD(event);
  mx = *(__int16 *)(LODWORD(event) + 24);
  PhonemeEditor::LimitDrag(this, mousex: &mx);
  v2->x = (__int16)mx;
  if ( this->m_nDragType == 0 )
  {
    if ( this->m_hPrevCursor != nullptr )
    {
      SetCursor(hCursor: this->m_hPrevCursor);
      this->m_hPrevCursor = nullptr;
    }
    PhonemeEditor::CountSelected(this);
    IsMouseOverBoundary = PhonemeEditor::IsMouseOverBoundary(this, event: v2);
    if ( IsMouseOverBoundary == 1 )
    {
      if ( this->m_nSelectedPhonemeCount <= 1 )
      {
LABEL_34:
        CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
        v19 = SetCursor(hCursor: CursorA);
LABEL_50:
        this->m_hPrevCursor = v19;
        goto LABEL_51;
      }
    }
    else if ( IsMouseOverBoundary == 2 && this->m_nSelectedWordCount <= 1 )
    {
      goto LABEL_34;
    }
    if ( PhonemeEditor::IsMouseOverSelection(this, mx: SLOWORD(v2->x), my: SLOWORD(v2->y)) != 0 )
    {
      if ( PhonemeEditor::IsMouseOverSelectionStartEdge(this, event: v2)
        || PhonemeEditor::IsMouseOverSelectionEndEdge(this, event: v2) )
      {
        goto LABEL_34;
      }
      if ( (v2->modifiers & 2) == 0 )
        goto LABEL_51;
LABEL_49:
      v21 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F86);
      v19 = SetCursor(hCursor: v21);
      goto LABEL_50;
    }
    if ( this->m_CurrentMode == MODE_PHONEMES
      && (unsigned int)(SLOWORD(v2->y) - 40) <= 0x14
      && PhonemeEditor::GetTagUnderMouse(this, mx: SLOWORD(v2->x)) != nullptr )
    {
      goto LABEL_49;
    }
    PhonemeTagUnderMouse = (CPhonemeTag *)PhonemeEditor::GetPhonemeTagUnderMouse(
                                            this,
                                            mx: SLOWORD(v2->x),
                                            my: SLOWORD(v2->y));
    if ( PhonemeEditor::GetWordTagUnderMouse(this, mx: SLOWORD(v2->x), my: SLOWORD(v2->y)) != nullptr )
    {
      if ( PhonemeTagUnderMouse == nullptr )
        goto LABEL_48;
    }
    else if ( PhonemeTagUnderMouse == nullptr )
    {
      goto LABEL_51;
    }
    PhonemeEditor::SelectExpression(this, tag: PhonemeTagUnderMouse);
LABEL_48:
    if ( (v2->modifiers & 2) == 0 )
      goto LABEL_51;
    goto LABEL_49;
  }
  PhonemeEditor::DrawFocusRect(this, reason: "moving old");
  i = 0;
  if ( this->m_FocusRects.m_Size > 0 )
  {
    mx = 0;
    do
    {
      v4 = (char *)this->m_FocusRects.m_Memory.m_pMemory + mx;
      *((_QWORD *)v4 + 2) = *(_QWORD *)v4;
      *((_QWORD *)v4 + 3) = *((_QWORD *)v4 + 1);
      v5 = this->m_nDragType == 10;
      LODWORD(dt) = v4 + 16;
      if ( v5 )
      {
        Handle = (HWND)mxWidget::getHandle(this);
        GetClientRect(hWnd: Handle, lpRect: &rcWork);
        rcWork.top += 60;
        rcWork.bottom -= 95;
        InflateRect(lprc: &rcWork, dx: -1, dy: -1);
        v7 = (rcWork.bottom - rcWork.top) / 2 + rcWork.top + 2;
        v8 = (rcWork.bottom - rcWork.top) / 2 + rcWork.top + 22;
        v9 = (rcWork.bottom - rcWork.top) / 2 + rcWork.top + 62;
        if ( v9 >= v8 )
        {
          v8 = rcWork.bottom - (2 * this->m_nTickHeight + 2);
          if ( v9 <= v8 )
            v8 = (rcWork.bottom - rcWork.top) / 2 + rcWork.top + 62;
        }
        m_nStartX = this->m_nStartX;
        *(_QWORD *)&rcFocus.left = *(_QWORD *)v4;
        v11 = *((_QWORD *)v4 + 1);
        v12 = *(__int16 *)(LODWORD(event) + 24);
        *(_QWORD *)&rcFocus.right = v11;
        rcFocus.left = m_nStartX;
        if ( m_nStartX < v12 )
        {
          rcFocus.right = v12;
        }
        else
        {
          rcFocus.left = v12;
          rcFocus.right = m_nStartX;
        }
        m_nStartY = this->m_nStartY;
        v14 = m_nStartY;
        if ( m_nStartY < *(__int16 *)(LODWORD(event) + 28) )
          m_nStartY = *(__int16 *)(LODWORD(event) + 28);
        else
          v14 = *(__int16 *)(LODWORD(event) + 28);
        if ( v14 >= v7 )
        {
          v15 = v8;
          if ( v14 <= v8 )
            v15 = v14;
        }
        else
        {
          v15 = (rcWork.bottom - rcWork.top) / 2 + rcWork.top + 2;
        }
        rcFocus.top = v15;
        if ( m_nStartY >= v7 )
        {
          v7 = v8;
          if ( m_nStartY <= v8 )
            v7 = m_nStartY;
        }
        offset.x = 0;
        offset.y = 0;
        rcFocus.bottom = v7;
        v16 = (HWND)mxWidget::getHandle(this);
        ClientToScreen(hWnd: v16, lpPoint: &offset);
        OffsetRect(lprc: &rcFocus, dx: offset.x, dy: offset.y);
        v2 = (mxEvent *)LODWORD(event);
        *(tagRECT *)LODWORD(dt) = rcFocus;
      }
      else
      {
        OffsetRect(lprc: (LPRECT)v4 + 1, dx: SLOWORD(v2->x) - this->m_nStartX, dy: 0);
      }
      mx += 32;
      ++i;
    }
    while ( i < this->m_FocusRects.m_Size );
  }
  if ( this->m_nDragType == 11 )
    this->redraw(this);
  PhonemeEditor::DrawFocusRect(this, reason: "moving new");
LABEL_51:
  if ( this->m_nDragType == 11 )
  {
    PhonemeEditor::Emphasis_MouseDrag(this, x: SLOWORD(v2->x), y: SLOWORD(v2->y));
    CSentence::Resort(this: &this->m_Tags);
  }
  else if ( this->m_nDragType == 12 )
  {
    x_low = SLOWORD(v2->x);
    v23 = (HWND)mxWidget::getHandle(this);
    GetClientRect(hWnd: v23, lpRect: &rcWork);
    rcWork.top += 60;
    rcWork.bottom -= 95;
    InflateRect(lprc: &rcWork, dx: -1, dy: -1);
    v24 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
    event = (float)((float)((float)this->m_nLeftOffset / v24) + (float)((float)x_low / v24))
          + this->m_flScrubberTimeOffset;
    PhonemeEditor::ClampTimeToSelectionInterval(this, timeval: &event);
    dt = event - this->m_flScrub;
    this->m_flScrubTarget = event;
    PhonemeEditor::ClampTimeToSelectionInterval(this, timeval: &this->m_flScrubTarget);
    PhonemeEditor::ScrubThink(this, dt, scrubbing: true);
    this->m_flScrub = event;
    PhonemeEditor::ClampTimeToSelectionInterval(this, timeval: &this->m_flScrub);
    PhonemeEditor::GetScrubHandleRect(this, a2: (int)v2, a3: (int)this, rcHandle: &rcWork, clipped: true);
    rcWork.left = 0;
    rcWork.right = mxWidget::w2(this);
    CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: this, bounds: &rcWork);
    PhonemeEditor::DrawScrubHandle(this, a2: (int)v2, &drawHelper);
    CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
  }
  this->m_nLastX = SLOWORD(v2->x);
  this->m_nLastY = SLOWORD(v2->y);
}

//------------------------------------------------------------------------------
// Address: 0x004713C0
// Name: private: void PhonemeEditor::SortWords(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::SortWords(PhonemeEditor *this, bool prepareundo)
{
  int m_Size; // edx
  int v4; // eax
  CWordTag *v5; // ecx
  float m_flStartTime; // xmm0_4
  float m_flEndTime; // xmm1_4
  CWordTag *v8; // ecx
  float v9; // xmm0_4
  float v10; // xmm1_4
  CWordTag *v11; // ecx
  float v12; // xmm0_4
  float v13; // xmm1_4
  CWordTag *v14; // ecx
  float v15; // xmm0_4
  float v16; // xmm1_4
  CWordTag *v17; // ecx
  float v18; // xmm0_4
  float v19; // xmm1_4
  int v20; // ecx
  int v21; // eax
  CWordTag **m_pMemory; // edx
  float *p_m_flStartTime; // ebx
  CWordTag *v24; // edi
  CWordTag **v25; // edx
  float *v26; // ebx
  CWordTag *v27; // edi
  CWordTag **v28; // edx
  float *v29; // ebx
  CWordTag *v30; // edi
  CWordTag **v31; // edx
  float *v32; // ebx
  CWordTag *v33; // edi
  CWordTag **v34; // edx
  float *v35; // ebx
  CWordTag *v36; // edi
  bool v37; // zf
  CSentence *v38; // eax
  CSentence *v39; // edi
  int v40; // [esp+8h] [ebp-10h]
  int v41; // [esp+Ch] [ebp-Ch]
  int v42; // [esp+10h] [ebp-8h]
  int c; // [esp+14h] [ebp-4h]

  if ( prepareundo )
  {
    this->m_WorkFile.m_bDirty = true;
    IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
    PhonemeEditor::PushUndo(this);
  }
  m_Size = this->m_Tags.m_Words.m_Size;
  v4 = 0;
  c = m_Size;
  if ( m_Size >= 4 )
  {
    do
    {
      v5 = this->m_Tags.m_Words.m_Memory.m_pMemory[v4];
      m_flStartTime = v5->m_flStartTime;
      m_flEndTime = v5->m_flEndTime;
      if ( v5->m_flStartTime > m_flEndTime )
      {
        v5->m_flStartTime = m_flEndTime;
        v5->m_flEndTime = m_flStartTime;
      }
      v8 = this->m_Tags.m_Words.m_Memory.m_pMemory[v4 + 1];
      v9 = v8->m_flStartTime;
      v10 = v8->m_flEndTime;
      if ( v8->m_flStartTime > v10 )
      {
        v8->m_flStartTime = v10;
        v8->m_flEndTime = v9;
      }
      v11 = this->m_Tags.m_Words.m_Memory.m_pMemory[v4 + 2];
      v12 = v11->m_flStartTime;
      v13 = v11->m_flEndTime;
      if ( v11->m_flStartTime > v13 )
      {
        v11->m_flStartTime = v13;
        v11->m_flEndTime = v12;
      }
      v14 = this->m_Tags.m_Words.m_Memory.m_pMemory[v4 + 3];
      v15 = v14->m_flStartTime;
      v16 = v14->m_flEndTime;
      if ( v14->m_flStartTime > v16 )
      {
        v14->m_flStartTime = v16;
        v14->m_flEndTime = v15;
      }
      v4 += 4;
    }
    while ( v4 < m_Size - 3 );
  }
  for ( ; v4 < m_Size; ++v4 )
  {
    v17 = this->m_Tags.m_Words.m_Memory.m_pMemory[v4];
    v18 = v17->m_flStartTime;
    v19 = v17->m_flEndTime;
    if ( v17->m_flStartTime > v19 )
    {
      v17->m_flStartTime = v19;
      v17->m_flEndTime = v18;
    }
  }
  if ( m_Size > 0 )
  {
    v20 = 1;
    v21 = 0;
    v41 = 1;
    v42 = m_Size - 1;
    v40 = m_Size;
    do
    {
      if ( v20 < m_Size )
      {
        if ( v42 >= 4 )
        {
          do
          {
            m_pMemory = this->m_Tags.m_Words.m_Memory.m_pMemory;
            p_m_flStartTime = &m_pMemory[v20]->m_flStartTime;
            v24 = m_pMemory[v21];
            if ( *p_m_flStartTime <= v24->m_flStartTime )
            {
              m_pMemory[v21] = (CWordTag *)p_m_flStartTime;
              this->m_Tags.m_Words.m_Memory.m_pMemory[v20] = v24;
            }
            v25 = this->m_Tags.m_Words.m_Memory.m_pMemory;
            v26 = &v25[v20 + 1]->m_flStartTime;
            v27 = v25[v21];
            if ( *v26 <= v27->m_flStartTime )
            {
              v25[v21] = (CWordTag *)v26;
              this->m_Tags.m_Words.m_Memory.m_pMemory[v20 + 1] = v27;
            }
            v28 = this->m_Tags.m_Words.m_Memory.m_pMemory;
            v29 = &v28[v20 + 2]->m_flStartTime;
            v30 = v28[v21];
            if ( *v29 <= v30->m_flStartTime )
            {
              v28[v21] = (CWordTag *)v29;
              this->m_Tags.m_Words.m_Memory.m_pMemory[v20 + 2] = v30;
            }
            v31 = this->m_Tags.m_Words.m_Memory.m_pMemory;
            v32 = &v31[v20 + 3]->m_flStartTime;
            v33 = v31[v21];
            if ( *v32 <= v33->m_flStartTime )
            {
              v31[v21] = (CWordTag *)v32;
              this->m_Tags.m_Words.m_Memory.m_pMemory[v20 + 3] = v33;
            }
            m_Size = c;
            v20 += 4;
          }
          while ( v20 < c - 3 );
        }
        if ( v20 < m_Size )
        {
          do
          {
            v34 = this->m_Tags.m_Words.m_Memory.m_pMemory;
            v35 = &v34[v20]->m_flStartTime;
            v36 = v34[v21];
            if ( *v35 <= v36->m_flStartTime )
            {
              v34[v21] = (CWordTag *)v35;
              this->m_Tags.m_Words.m_Memory.m_pMemory[v20] = v36;
            }
            m_Size = c;
            ++v20;
          }
          while ( v20 < c );
        }
      }
      --v42;
      v20 = v41 + 1;
      ++v21;
      v37 = v40-- == 1;
      ++v41;
    }
    while ( !v37 );
  }
  if ( prepareundo )
  {
    this->m_bRedoPending = false;
    v38 = (CSentence *)operator new(nSize: 0x4Cu);
    if ( v38 != nullptr )
      v39 = CSentence::CSentence(this: v38);
    else
      v39 = nullptr;
    CSentence::operator=(this: v39, src: &this->m_Tags);
    this->m_UndoStack.m_Memory.m_pMemory[this->m_nUndoLevel - 1]->redo = v39;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471630
// Name: private: void PhonemeEditor::SortPhonemes(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::SortPhonemes(PhonemeEditor *this, bool prepareundo)
{
  PhonemeEditor *v2; // ebx
  int v3; // eax
  CWordTag *v4; // eax
  int m_Size; // edi
  int v6; // ecx
  float *p_m_flStartTime; // edx
  float v8; // xmm0_4
  float v9; // xmm1_4
  float *v10; // edx
  float v11; // xmm0_4
  float v12; // xmm1_4
  float *v13; // edx
  float v14; // xmm0_4
  float v15; // xmm1_4
  float *v16; // edx
  float v17; // xmm0_4
  float v18; // xmm1_4
  float *v19; // edx
  float v20; // xmm0_4
  float v21; // xmm1_4
  int v22; // edx
  int v23; // ecx
  CPhonemeTag **m_pMemory; // esi
  float *v25; // edi
  float *v26; // esi
  CPhonemeTag **v27; // esi
  float *v28; // edi
  float *v29; // esi
  CPhonemeTag **v30; // esi
  float *v31; // edi
  float *v32; // esi
  CPhonemeTag **v33; // esi
  float *v34; // edi
  float *v35; // esi
  CPhonemeTag **v36; // esi
  float *v37; // edi
  float *v38; // esi
  bool v39; // zf
  CSentence *v40; // eax
  CSentence *v41; // esi
  int wc; // [esp+8h] [ebp-1Ch]
  int w; // [esp+Ch] [ebp-18h]
  int v44; // [esp+10h] [ebp-14h]
  int v45; // [esp+14h] [ebp-10h]
  int c; // [esp+1Ch] [ebp-8h]
  int v48; // [esp+20h] [ebp-4h]

  v2 = this;
  if ( prepareundo )
  {
    this->m_WorkFile.m_bDirty = true;
    IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
    PhonemeEditor::PushUndo(this: v2);
  }
  v3 = 0;
  wc = v2->m_Tags.m_Words.m_Size;
  w = 0;
  if ( wc > 0 )
  {
    do
    {
      v4 = v2->m_Tags.m_Words.m_Memory.m_pMemory[v3];
      m_Size = v4->m_Phonemes.m_Size;
      v6 = 0;
      c = m_Size;
      if ( m_Size >= 4 )
      {
        do
        {
          p_m_flStartTime = &v4->m_Phonemes.m_Memory.m_pMemory[v6]->m_flStartTime;
          v8 = *p_m_flStartTime;
          v9 = p_m_flStartTime[1];
          if ( *p_m_flStartTime > v9 )
          {
            *p_m_flStartTime = v9;
            p_m_flStartTime[1] = v8;
          }
          v10 = &v4->m_Phonemes.m_Memory.m_pMemory[v6 + 1]->m_flStartTime;
          v11 = *v10;
          v12 = v10[1];
          if ( *v10 > v12 )
          {
            *v10 = v12;
            v10[1] = v11;
          }
          v13 = &v4->m_Phonemes.m_Memory.m_pMemory[v6 + 2]->m_flStartTime;
          v14 = *v13;
          v15 = v13[1];
          if ( *v13 > v15 )
          {
            *v13 = v15;
            v13[1] = v14;
          }
          v16 = &v4->m_Phonemes.m_Memory.m_pMemory[v6 + 3]->m_flStartTime;
          v17 = *v16;
          v18 = v16[1];
          if ( *v16 > v18 )
          {
            *v16 = v18;
            v16[1] = v17;
          }
          v6 += 4;
        }
        while ( v6 < m_Size - 3 );
      }
      for ( ; v6 < m_Size; ++v6 )
      {
        v19 = &v4->m_Phonemes.m_Memory.m_pMemory[v6]->m_flStartTime;
        v20 = *v19;
        v21 = v19[1];
        if ( *v19 > v21 )
        {
          *v19 = v21;
          v19[1] = v20;
        }
      }
      if ( m_Size > 0 )
      {
        v22 = 1;
        v23 = 0;
        v45 = 1;
        v48 = m_Size - 1;
        v44 = m_Size;
        do
        {
          if ( v22 < m_Size )
          {
            if ( v48 >= 4 )
            {
              do
              {
                m_pMemory = v4->m_Phonemes.m_Memory.m_pMemory;
                v25 = &m_pMemory[v23]->m_flStartTime;
                v26 = &m_pMemory[v22]->m_flStartTime;
                if ( *v26 <= *v25 )
                {
                  v4->m_Phonemes.m_Memory.m_pMemory[v23] = (CPhonemeTag *)v26;
                  v4->m_Phonemes.m_Memory.m_pMemory[v22] = (CPhonemeTag *)v25;
                }
                v27 = v4->m_Phonemes.m_Memory.m_pMemory;
                v28 = &v27[v23]->m_flStartTime;
                v29 = &v27[v22 + 1]->m_flStartTime;
                if ( *v29 <= *v28 )
                {
                  v4->m_Phonemes.m_Memory.m_pMemory[v23] = (CPhonemeTag *)v29;
                  v4->m_Phonemes.m_Memory.m_pMemory[v22 + 1] = (CPhonemeTag *)v28;
                }
                v30 = v4->m_Phonemes.m_Memory.m_pMemory;
                v31 = &v30[v23]->m_flStartTime;
                v32 = &v30[v22 + 2]->m_flStartTime;
                if ( *v32 <= *v31 )
                {
                  v4->m_Phonemes.m_Memory.m_pMemory[v23] = (CPhonemeTag *)v32;
                  v4->m_Phonemes.m_Memory.m_pMemory[v22 + 2] = (CPhonemeTag *)v31;
                }
                v33 = v4->m_Phonemes.m_Memory.m_pMemory;
                v34 = &v33[v23]->m_flStartTime;
                v35 = &v33[v22 + 3]->m_flStartTime;
                if ( *v35 <= *v34 )
                {
                  v4->m_Phonemes.m_Memory.m_pMemory[v23] = (CPhonemeTag *)v35;
                  v4->m_Phonemes.m_Memory.m_pMemory[v22 + 3] = (CPhonemeTag *)v34;
                }
                m_Size = c;
                v22 += 4;
              }
              while ( v22 < c - 3 );
              v2 = this;
            }
            if ( v22 < m_Size )
            {
              do
              {
                v36 = v4->m_Phonemes.m_Memory.m_pMemory;
                v37 = &v36[v23]->m_flStartTime;
                v38 = &v36[v22]->m_flStartTime;
                if ( *v38 <= *v37 )
                {
                  v4->m_Phonemes.m_Memory.m_pMemory[v23] = (CPhonemeTag *)v38;
                  v4->m_Phonemes.m_Memory.m_pMemory[v22] = (CPhonemeTag *)v37;
                }
                m_Size = c;
                ++v22;
              }
              while ( v22 < c );
              v2 = this;
            }
          }
          --v48;
          v22 = v45 + 1;
          ++v23;
          v39 = v44-- == 1;
          ++v45;
        }
        while ( !v39 );
      }
      v3 = w + 1;
      w = v3;
    }
    while ( v3 < wc );
  }
  if ( prepareundo )
  {
    v2->m_bRedoPending = false;
    v40 = (CSentence *)operator new(nSize: 0x4Cu);
    if ( v40 != nullptr )
      v41 = CSentence::CSentence(this: v40);
    else
      v41 = nullptr;
    CSentence::operator=(this: v41, src: &v2->m_Tags);
    v2->m_UndoStack.m_Memory.m_pMemory[v2->m_nUndoLevel - 1]->redo = v41;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004718C0
// Name: private: void PhonemeEditor::CleanupWordsAndPhonemes(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::CleanupWordsAndPhonemes(PhonemeEditor *this, bool prepareundo)
{
  int v3; // edi
  CWordTag **m_pMemory; // eax
  CWordTag *v5; // ecx
  CWordTag **v6; // eax
  float *v7; // edx
  float m_flEndTime; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  int v11; // esi
  CPhonemeTag **v12; // eax
  CPhonemeTag *v13; // edx
  CPhonemeTag **v14; // eax
  float *v15; // edi
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  CSentence *v19; // eax
  CSentence *v20; // esi
  float snap_epsilon; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  if ( this->m_CurrentMode == MODE_PHONEMES )
  {
    snap_epsilon = 2.49 / (float)((float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond);
    if ( prepareundo )
    {
      this->m_WorkFile.m_bDirty = true;
      IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
      PhonemeEditor::PushUndo(this);
    }
    PhonemeEditor::SortWords(this, prepareundo: false);
    PhonemeEditor::SortPhonemes(this, prepareundo: false);
    v3 = 0;
    for ( i = 0; v3 < this->m_Tags.m_Words.m_Size; i = v3 )
    {
      m_pMemory = this->m_Tags.m_Words.m_Memory.m_pMemory;
      v5 = m_pMemory[v3];
      v6 = &m_pMemory[v3];
      if ( v5 != nullptr )
      {
        if ( v3 < this->m_Tags.m_Words.m_Size - 1 )
        {
          v7 = (float *)v6[1];
          if ( v7 != nullptr )
          {
            m_flEndTime = v5->m_flEndTime;
            v9 = *v7 - m_flEndTime;
            if ( v9 != 0.0 && snap_epsilon >= v9 )
            {
              v10 = (float)(m_flEndTime + *v7) * 0.5;
              v5->m_flEndTime = v10;
              *v7 = v10;
            }
          }
        }
        v11 = 0;
        if ( v5->m_Phonemes.m_Size > 0 )
        {
          do
          {
            v12 = v5->m_Phonemes.m_Memory.m_pMemory;
            v13 = v12[v11];
            v14 = &v12[v11];
            if ( v13 != nullptr && v11 < v5->m_Phonemes.m_Size - 1 )
            {
              v15 = (float *)v14[1];
              if ( v15 != nullptr )
              {
                v16 = v13->m_flEndTime;
                v17 = *v15 - v16;
                if ( v17 != 0.0 && snap_epsilon >= v17 )
                {
                  v18 = (float)(v16 + *v15) * 0.5;
                  v13->m_flEndTime = v18;
                  *v15 = v18;
                }
              }
            }
            ++v11;
          }
          while ( v11 < v5->m_Phonemes.m_Size );
          v3 = i;
        }
      }
      ++v3;
    }
    if ( prepareundo )
    {
      this->m_bRedoPending = false;
      v19 = (CSentence *)operator new(nSize: 0x4Cu);
      if ( v19 != nullptr )
        v20 = CSentence::CSentence(this: v19);
      else
        v20 = nullptr;
      CSentence::operator=(this: v20, src: &this->m_Tags);
      this->m_UndoStack.m_Memory.m_pMemory[this->m_nUndoLevel - 1]->redo = v20;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471A80
// Name: private: void PhonemeEditor::RealignPhonemesToWords(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::RealignPhonemesToWords(PhonemeEditor *this, bool prepareundo)
{
  PhonemeEditor *v2; // ebx
  int v3; // edi
  CWordTag *v4; // eax
  float **m_pMemory; // ecx
  float *v6; // edx
  float v7; // xmm3_4
  int m_Size; // esi
  float *v9; // ecx
  float v10; // xmm2_4
  int v11; // edx
  float v12; // xmm1_4
  int v13; // edi
  float *v14; // ecx
  float *v15; // ebx
  float v16; // xmm0_4
  CSentence *v17; // eax
  CSentence *v18; // esi
  int i; // [esp+4h] [ebp-8h]

  v2 = this;
  if ( this->m_CurrentMode == MODE_PHONEMES )
  {
    if ( prepareundo )
    {
      this->m_WorkFile.m_bDirty = true;
      IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
      PhonemeEditor::PushUndo(this: v2);
    }
    PhonemeEditor::SortWords(this: v2, prepareundo: false);
    PhonemeEditor::SortPhonemes(this: v2, prepareundo: false);
    v3 = 0;
    for ( i = 0; v3 < v2->m_Tags.m_Words.m_Size; i = v3 )
    {
      v4 = v2->m_Tags.m_Words.m_Memory.m_pMemory[v3];
      if ( v4 != nullptr )
      {
        m_pMemory = (float **)v4->m_Phonemes.m_Memory.m_pMemory;
        v6 = *m_pMemory;
        v7 = v4->m_flEndTime - v4->m_flStartTime;
        if ( *m_pMemory != nullptr )
        {
          m_Size = v4->m_Phonemes.m_Size;
          v9 = m_pMemory[m_Size - 1];
          if ( v9 != nullptr )
          {
            v10 = *v6;
            v11 = 0;
            v12 = v9[1] - v10;
            if ( m_Size > 0 )
            {
              do
              {
                v13 = (int)&v4->m_Phonemes.m_Memory.m_pMemory[v11];
                v14 = *(float **)v13;
                if ( *(_DWORD *)v13 != 0 )
                {
                  v15 = nullptr;
                  if ( v11 < m_Size - 1 )
                    v15 = *(float **)(v13 + 4);
                  if ( v11 == 0 )
                    *v14 = (float)((float)(*v14 - v10) * (float)(v7 / v12)) + v4->m_flStartTime;
                  v16 = (float)((float)(v7 / v12) * (float)(v14[1] - v10)) + v4->m_flStartTime;
                  v14[1] = v16;
                  if ( v15 != nullptr )
                    *v15 = v16;
                  v2 = this;
                }
                m_Size = v4->m_Phonemes.m_Size;
                ++v11;
              }
              while ( v11 < m_Size );
              v3 = i;
            }
          }
        }
      }
      ++v3;
    }
    if ( prepareundo )
    {
      v2->m_bRedoPending = false;
      v17 = (CSentence *)operator new(nSize: 0x4Cu);
      if ( v17 != nullptr )
        v18 = CSentence::CSentence(this: v17);
      else
        v18 = nullptr;
      CSentence::operator=(this: v18, src: &v2->m_Tags);
      v2->m_UndoStack.m_Memory.m_pMemory[v2->m_nUndoLevel - 1]->redo = v18;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471C00
// Name: private: void PhonemeEditor::RealignWordsToPhonemes(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::RealignWordsToPhonemes(PhonemeEditor *this, bool prepareundo)
{
  int i; // edi
  CWordTag *v4; // eax
  float **m_pMemory; // ecx
  float *v6; // edx
  float *v7; // ecx
  CSentence *v8; // eax
  CSentence *v9; // edi

  if ( this->m_CurrentMode == MODE_PHONEMES )
  {
    if ( prepareundo )
    {
      this->m_WorkFile.m_bDirty = true;
      IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
      PhonemeEditor::PushUndo(this);
    }
    PhonemeEditor::SortWords(this, prepareundo: false);
    PhonemeEditor::SortPhonemes(this, prepareundo: false);
    for ( i = 0; i < this->m_Tags.m_Words.m_Size; ++i )
    {
      v4 = this->m_Tags.m_Words.m_Memory.m_pMemory[i];
      if ( v4 != nullptr )
      {
        m_pMemory = (float **)v4->m_Phonemes.m_Memory.m_pMemory;
        v6 = *m_pMemory;
        if ( *m_pMemory != nullptr )
        {
          v7 = m_pMemory[v4->m_Phonemes.m_Size - 1];
          if ( v7 != nullptr )
          {
            v4->m_flStartTime = *v6;
            v4->m_flEndTime = v7[1];
          }
        }
      }
    }
    if ( prepareundo )
    {
      this->m_bRedoPending = false;
      v8 = (CSentence *)operator new(nSize: 0x4Cu);
      if ( v8 != nullptr )
        v9 = CSentence::CSentence(this: v8);
      else
        v9 = nullptr;
      CSentence::operator=(this: v9, src: &this->m_Tags);
      this->m_UndoStack.m_Memory.m_pMemory[this->m_nUndoLevel - 1]->redo = v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471CE0
// Name: private: void PhonemeEditor::LoadPhonemeConverters(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::LoadPhonemeConverters(PhonemeEditor *this)
{
  const char *i; // eax
  Color v2; // ecx
  struct CSysModule *Module; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax
  IPhonemeExtractor *v5; // eax
  char fullpath[512]; // [esp+0h] [ebp-210h] BYREF
  Extractor e; // [esp+200h] [ebp-10h] BYREF
  int findHandle; // [esp+20Ch] [ebp-4h] BYREF

  this->m_pPhonemeExtractor = nullptr;
  for ( i = filesystem->FindFirstEx(
              this: filesystem,
              a2: "phonemeextractors/*.dll",
              a3: "EXECUTABLE_PATH",
              a4: &findHandle); i != nullptr; i = filesystem->FindNext(this: filesystem, a2: findHandle) )
  {
    V_snprintf(pDest: fullpath, maxLen: 512, pFormat: "phonemeextractors/%s", i);
    Con_Printf(a1: v2, fmt: "Loading extractor from %s\n", fullpath);
    Module = Sys_LoadModule(pModuleName: fullpath);
    e.module = Module;
    if ( Module != nullptr )
    {
      Factory = Sys_GetFactory(pModule: Module);
      if ( Factory != nullptr )
      {
        v5 = (IPhonemeExtractor *)Factory(a1: "PHONEME_EXTRACTOR_001", a2: nullptr);
        e.extractor = v5;
        if ( v5 != nullptr )
        {
          e.apitype = v5->GetAPIType(this: v5);
          CUtlVector<CEmphasisSample,CUtlMemory<CEmphasisSample,int>>::InsertBefore(
            this: (CUtlVector<CEmphasisSample,CUtlMemory<CEmphasisSample,int> > *)&g_Extractors,
            elem: g_Extractors.m_Size,
            src: (const CEmphasisSample *)&e);
        }
        else
        {
          _Warning(
            a1: "Unable to get IPhonemeExtractor interface version %s from %s\n",
            "PHONEME_EXTRACTOR_001",
            fullpath);
        }
      }
    }
  }
  filesystem->FindClose(this: filesystem, a2: findHandle);
}

//------------------------------------------------------------------------------
// Address: 0x00471E00
// Name: private: void PhonemeEditor::Emphasis_Delete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::Emphasis_Delete(PhonemeEditor *this)
{
  int v2; // edi
  int v3; // ebx
  CSentence *v4; // eax
  CSentence *v5; // edi

  if ( this->m_CurrentMode == MODE_EMPHASIS )
  {
    this->m_WorkFile.m_bDirty = true;
    IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
    PhonemeEditor::PushUndo(this);
    v2 = CSentence::GetNumSamples(this: &this->m_Tags) - 1;
    if ( v2 >= 0 )
    {
      v3 = v2;
      do
      {
        if ( CSentence::GetSample(this: &this->m_Tags, index: v2)->selected )
        {
          if ( this->m_Tags.m_EmphasisSamples.m_Size - v2 - 1 > 0 )
            _V_memmove(
              dest: &this->m_Tags.m_EmphasisSamples.m_Memory.m_pMemory[v3],
              src: &this->m_Tags.m_EmphasisSamples.m_Memory.m_pMemory[v3 + 1],
              count: 12 * (this->m_Tags.m_EmphasisSamples.m_Size - v2 - 1));
          --this->m_Tags.m_EmphasisSamples.m_Size;
          this->m_WorkFile.m_bDirty = true;
          IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
        }
        --v3;
        --v2;
      }
      while ( v2 >= 0 );
    }
    this->m_bRedoPending = false;
    v4 = (CSentence *)operator new(nSize: 0x4Cu);
    if ( v4 != nullptr )
      v5 = CSentence::CSentence(this: v4);
    else
      v5 = nullptr;
    CSentence::operator=(this: v5, src: &this->m_Tags);
    this->m_UndoStack.m_Memory.m_pMemory[this->m_nUndoLevel - 1]->redo = v5;
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471F00
// Name: private: void PhonemeEditor::OnToggleVoiceDuck(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::OnToggleVoiceDuck(PhonemeEditor *this)
{
  CSentence *v2; // eax
  CSentence *v3; // edi

  this->m_WorkFile.m_bDirty = true;
  IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
  PhonemeEditor::PushUndo(this);
  *((_BYTE *)&this->m_Tags + 74) = *((_BYTE *)&this->m_Tags + 74) == 0;
  this->m_bRedoPending = false;
  v2 = (CSentence *)operator new(nSize: 0x4Cu);
  if ( v2 != nullptr )
    v3 = CSentence::CSentence(this: v2);
  else
    v3 = nullptr;
  CSentence::operator=(this: v3, src: &this->m_Tags);
  this->m_UndoStack.m_Memory.m_pMemory[this->m_nUndoLevel - 1]->redo = v3;
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x00471F80
// Name: public: void PhonemeEditor::Play(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::Play(PhonemeEditor *this)
{
  PhonemeEditor::StopPlayback(this);
  if ( this->m_pWaveFile != nullptr )
  {
    FacePoser_EnsurePhonemesLoaded();
    PhonemeEditor::SaveLinguisticData(this);
    this->m_flScrub = 0.0;
    PhonemeEditor::ClampTimeToSelectionInterval(this, timeval: &this->m_flScrub);
    this->m_flScrubTarget = this->m_pWaveFile->GetRunningLength(this: this->m_pWaveFile);
    PhonemeEditor::ClampTimeToSelectionInterval(this, timeval: &this->m_flScrubTarget);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471FF0
// Name: public: PhonemeEditor::PhonemeEditor(class mxWindow __near *)
// Source: json
//------------------------------------------------------------------------------
PhonemeEditor *__thiscall PhonemeEditor::PhonemeEditor(PhonemeEditor *this, mxWindow *parent)
{
  mxScrollbar *v3; // eax
  mxScrollbar *v4; // eax
  mxButton *v5; // eax
  mxButton *v6; // eax
  mxButton *v7; // eax
  mxButton *v8; // eax
  mxButton *v9; // eax
  mxButton *v10; // eax
  mxButton *v11; // eax
  mxButton *v12; // eax
  mxSlider *v13; // eax
  mxSlider *v14; // eax
  CTabWindow *v15; // eax
  CPhonemeModeTab *v16; // edi

  mxWindow::mxWindow(this, parent, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
  IFacePoserToolWindow::IFacePoserToolWindow(
    this: &this->IFacePoserToolWindow,
    toolname: "PhonemeEditor",
    displaynameroot: "Phoneme Editor");
  this->mxWindow::mxWidget::__vftable = (PhonemeEditor_vtbl *)&PhonemeEditor::`vftable'{for `mxWindow'};
  this->IFacePoserToolWindow::__vftable = (IFacePoserToolWindow_vtbl *)&PhonemeEditor::`vftable'{for `IFacePoserToolWindow'};
  this->m_FocusRects.m_Memory.m_pMemory = nullptr;
  this->m_FocusRects.m_Memory.m_nAllocationCount = 0;
  this->m_FocusRects.m_Memory.m_nGrowSize = 0;
  this->m_FocusRects.m_Size = 0;
  this->m_FocusRects.m_pElements = nullptr;
  CSentence::CSentence(this: &this->m_Tags);
  CSentence::CSentence(this: &this->m_TagsExt);
  this->m_UndoStack.m_Memory.m_pMemory = nullptr;
  this->m_UndoStack.m_Memory.m_nAllocationCount = 0;
  this->m_UndoStack.m_Memory.m_nGrowSize = 0;
  this->m_UndoStack.m_Size = 0;
  this->m_UndoStack.m_pElements = nullptr;
  IFacePoserToolWindow::SetAutoProcess(this: &this->IFacePoserToolWindow, autoprocess: false);
  this->m_flPlaybackRate = 1.0;
  this->m_flScrub = 0.0;
  this->m_flScrubTarget = 0.0;
  this->m_CurrentMode = MODE_PHONEMES;
  this->m_nNumSelected = 0;
  PhonemeEditor::SetupPhonemeEditorColors(this);
  this->m_bRedoPending = false;
  this->m_nUndoLevel = 0;
  this->m_bWordsActive = false;
  this->m_pWaveFile = nullptr;
  this->m_pMixer = nullptr;
  this->m_pEvent = nullptr;
  this->m_nClickX = 0;
  this->m_WorkFile.m_bDirty = false;
  this->m_WorkFile.m_szWaveFile[0] = 0;
  this->m_WorkFile.m_szWorkingFile[0] = 0;
  this->m_WorkFile.m_szBasePath[0] = 0;
  this->m_nTickHeight = 20;
  this->m_flPixelsPerSecond = 500.0;
  this->m_nTimeZoom = 100;
  this->m_nTimeZoomStep = 2;
  v3 = (mxScrollbar *)operator new(nSize: 0xCu);
  if ( v3 != nullptr )
    v4 = mxScrollbar::mxScrollbar(this: v3, parent: this, x: 0, y: 0, w: 18, h: 100, id: 1001, style: 0);
  else
    v4 = nullptr;
  this->m_pHorzScrollBar = v4;
  this->m_hPrevCursor = nullptr;
  this->m_nStartX = 0;
  this->m_nStartY = 0;
  this->m_nLastX = 0;
  this->m_nLastY = 0;
  this->m_nDragType = 0;
  this->m_nClickedPhoneme = -1;
  this->m_nClickedWord = -1;
  this->m_nSelection[1] = 0;
  this->m_nSelection[0] = 0;
  this->m_bSelectionActive = false;
  this->m_nSelectedPhonemeCount = 0;
  this->m_nSelectedWordCount = 0;
  v5 = (mxButton *)operator new(nSize: 0xCu);
  if ( v5 != nullptr )
    v6 = mxButton::mxButton(this: v5, parent: this, x: 0, y: 0, w: 16, h: 16, label: "Save (Ctrl+S)", id: 1013);
  else
    v6 = nullptr;
  this->m_btnSave = v6;
  v7 = (mxButton *)operator new(nSize: 0xCu);
  if ( v7 != nullptr )
    v8 = mxButton::mxButton(this: v7, parent: this, x: 38, y: 14, w: 80, h: 16, label: "Re-extract (Ctrl+R)", id: 1009);
  else
    v8 = nullptr;
  this->m_btnRedoPhonemeExtraction = v8;
  v9 = (mxButton *)operator new(nSize: 0xCu);
  if ( v9 != nullptr )
    v10 = mxButton::mxButton(this: v9, parent: this, x: 0, y: 0, w: 0, h: 0, label: "Load (Ctrl+O)", id: 1018);
  else
    v10 = nullptr;
  this->m_btnLoad = v10;
  v11 = (mxButton *)operator new(nSize: 0xCu);
  if ( v11 != nullptr )
    v12 = mxButton::mxButton(this: v11, parent: this, x: 0, y: 0, w: 16, h: 16, label: "Play (Spacebar)", id: 1039);
  else
    v12 = nullptr;
  this->m_btnPlay = v12;
  v13 = (mxSlider *)operator new(nSize: 0x18u);
  if ( v13 != nullptr )
    v14 = mxSlider::mxSlider(this: v13, parent: this, x: 0, y: 0, w: 16, h: 16, id: 1044, style: 0);
  else
    v14 = nullptr;
  this->m_pPlaybackRate = v14;
  mxSlider::setRange(this: v14, min: 0.0, max: 2.0, ticks: 40);
  mxSlider::setValue(this: this->m_pPlaybackRate, value: this->m_flPlaybackRate);
  v15 = (CTabWindow *)operator new(nSize: 0x54u);
  v16 = (CPhonemeModeTab *)v15;
  if ( v15 != nullptr )
  {
    CTabWindow::CTabWindow(this: v15, parent: this, x: 0, y: 0, w: 500, h: 20, id: 1040, style: 0);
    v16->__vftable = (CPhonemeModeTab_vtbl *)&CPhonemeModeTab::`vftable';
    CTabWindow::SetInverted(this: v16, invert: true);
  }
  else
  {
    v16 = nullptr;
  }
  this->m_pModeTab = v16;
  v16->add(this: v16, a2: "Phonemes");
  v16->add(this: v16, a2: "Emphasis");
  v16->select(this: v16, a2: 0);
  this->m_nLastExtractionResult = 0;
  this->m_bLimitDrag = false;
  this->m_nLeftLimit = -1;
  this->m_nRightLimit = -1;
  IFacePoserToolWindow::SetSuffix(this: &this->IFacePoserToolWindow, suffix: " - Normal");
  this->m_flScrubberTimeOffset = 0.0;
  PhonemeEditor::LoadPhonemeConverters(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004723F0
// Name: private: void PhonemeEditor::EditWord(class CWordTag __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::EditWord(PhonemeEditor *this, CWordTag *pWord, bool positionDialog)
{
  char *Word; // eax
  char *v5; // edx
  char v6; // cl
  HWND Handle; // eax
  INT_PTR v8; // edi
  HWND v9; // eax
  Color v10; // ecx
  HWND v11; // eax
  CInputParams params; // [esp+8h] [ebp-5A4h] BYREF
  tagRECT rcWord; // [esp+594h] [ebp-18h] BYREF
  tagPOINT pt; // [esp+5A4h] [ebp-8h] BYREF

  if ( pWord != nullptr )
  {
    memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
    strcpy(params.m_szDialogTitle, "Edit Word");
    strcpy(params.m_szPrompt, "Current Word:");
    Word = CWordTag::GetWord(this: pWord);
    v5 = (char *)(params.m_szInputText - Word);
    do
    {
      v6 = *Word;
      Word[(_DWORD)v5] = *Word;
      ++Word;
    }
    while ( v6 != 0 );
    params.m_nLeft = -1;
    params.m_nTop = -1;
    params.m_bPositionDialog = positionDialog;
    if ( positionDialog )
    {
      PhonemeEditor::GetWordRect(this, tag: pWord, rc: &rcWord);
      pt.x = rcWord.left;
      pt.y = rcWord.top;
      Handle = (HWND)mxWidget::getHandle(this);
      ClientToScreen(hWnd: Handle, lpPoint: &pt);
      *(tagPOINT *)&params.m_nLeft = pt;
    }
    v8 = InputProperties(&params);
    v9 = (HWND)mxWidget::getHandle(this);
    SetFocus(hWnd: v9);
    if ( v8 != 0 )
    {
      if ( CSentence::CountWords(str: params.m_szInputText) == 1 )
      {
        v11 = (HWND)mxWidget::getHandle(this);
        SetFocus(hWnd: v11);
        this->m_WorkFile.m_bDirty = true;
        IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
        PhonemeEditor::PushUndo(this);
        CWordTag::SetWord(this: pWord, word: params.m_szInputText);
        PhonemeEditor::PushRedo(this);
        this->redraw(this);
      }
      else
      {
        Con_ErrorPrintf(a1: v10, fmt: "Edit word:  %s has multiple words in it!!!\n", params.m_szInputText);
      }
    }
  }
  else
  {
    Con_Printf(a1: (Color)this, fmt: "PhonemeEditor::EditWord:  pWord == NULL\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472590
// Name: private: void PhonemeEditor::EditPhoneme(class CPhonemeTag __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::EditPhoneme(PhonemeEditor *this, CPhonemeTag *pPhoneme, bool positionDialog)
{
  int m_nPhonemeCode; // eax
  char *v5; // eax
  char *v6; // edx
  char v7; // cl
  HWND Handle; // eax
  int v9; // edi
  HWND v10; // eax
  CPhonemeParams params; // [esp+8h] [ebp-1A8h] BYREF
  tagRECT rcPhoneme; // [esp+198h] [ebp-18h] BYREF
  tagPOINT pt; // [esp+1A8h] [ebp-8h] BYREF

  if ( pPhoneme != nullptr )
  {
    memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
    m_nPhonemeCode = pPhoneme->m_nPhonemeCode;
    strcpy(params.m_szDialogTitle, "Phoneme/Viseme Properties");
    v5 = (char *)ConvertPhoneme(code: m_nPhonemeCode);
    v6 = (char *)(params.m_szName - v5);
    do
    {
      v7 = *v5;
      v5[(_DWORD)v6] = *v5;
      ++v5;
    }
    while ( v7 != 0 );
    params.m_nLeft = -1;
    params.m_nTop = -1;
    params.m_bPositionDialog = positionDialog;
    if ( positionDialog )
    {
      PhonemeEditor::GetPhonemeRect(this, tag: pPhoneme, rc: &rcPhoneme);
      pt.y = rcPhoneme.top;
      pt.x = rcPhoneme.left;
      Handle = (HWND)mxWidget::getHandle(this);
      ClientToScreen(hWnd: Handle, lpPoint: &pt);
      *(tagPOINT *)&params.m_nLeft = pt;
    }
    v9 = PhonemeProperties(&params);
    v10 = (HWND)mxWidget::getHandle(this);
    SetFocus(hWnd: v10);
    if ( v9 != 0 )
    {
      this->m_WorkFile.m_bDirty = true;
      IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
      PhonemeEditor::PushUndo(this);
      pPhoneme->m_nPhonemeCode = TextToPhoneme(text: params.m_szName);
      PhonemeEditor::PushRedo(this);
      this->redraw(this);
    }
  }
  else
  {
    Con_Printf(a1: (Color)this, fmt: "PhonemeEditor::EditPhoneme:  pPhoneme == NULL\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x004726F0
// Name: private: void PhonemeEditor::EditPhoneme(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::EditPhoneme(PhonemeEditor *this)
{
  int m_nClickedPhoneme; // edx
  int m_nClickedWord; // eax
  CWordTag *v3; // eax
  CPhonemeTag *v4; // eax

  if ( this->m_CurrentMode == MODE_PHONEMES )
  {
    m_nClickedPhoneme = this->m_nClickedPhoneme;
    if ( m_nClickedPhoneme >= 0 )
    {
      m_nClickedWord = this->m_nClickedWord;
      if ( m_nClickedWord >= 0 && m_nClickedWord < this->m_Tags.m_Words.m_Size )
      {
        v3 = this->m_Tags.m_Words.m_Memory.m_pMemory[m_nClickedWord];
        if ( v3 != nullptr && m_nClickedPhoneme < v3->m_Phonemes.m_Size )
        {
          v4 = v3->m_Phonemes.m_Memory.m_pMemory[m_nClickedPhoneme];
          if ( v4 != nullptr )
            PhonemeEditor::EditPhoneme(this, pPhoneme: v4, positionDialog: false);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472740
// Name: private: void PhonemeEditor::EditWord(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::EditWord(PhonemeEditor *this)
{
  int m_nClickedWord; // eax
  CWordTag *v2; // eax

  if ( this->m_CurrentMode == MODE_PHONEMES )
  {
    m_nClickedWord = this->m_nClickedWord;
    if ( m_nClickedWord >= 0 && m_nClickedWord < this->m_Tags.m_Words.m_Size )
    {
      v2 = this->m_Tags.m_Words.m_Memory.m_pMemory[m_nClickedWord];
      if ( v2 != nullptr )
        PhonemeEditor::EditWord(this, pWord: v2, positionDialog: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472780
// Name: private: void PhonemeEditor::FinishWordDrag(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::FinishWordDrag(PhonemeEditor *this, int startx, int endx)
{
  HWND Handle; // eax
  float v5; // xmm0_4
  HWND v6; // eax
  float v7; // xmm0_4
  int i; // edx
  CWordTag *v9; // eax
  CSentence *v10; // eax
  CSentence *v11; // edi
  tagRECT Rect; // [esp+10h] [ebp-10h] BYREF
  float clicktimea; // [esp+28h] [ebp+8h]
  float clicktime; // [esp+28h] [ebp+8h]

  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &Rect);
  Rect.top += 60;
  Rect.bottom -= 95;
  InflateRect(lprc: &Rect, dx: -1, dy: -1);
  v5 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
  clicktimea = (float)((float)this->m_nLeftOffset / v5) + (float)((float)startx / v5);
  v6 = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: v6, lpRect: &Rect);
  Rect.top += 60;
  Rect.bottom -= 95;
  InflateRect(lprc: &Rect, dx: -1, dy: -1);
  v7 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
  clicktime = (float)((float)((float)this->m_nLeftOffset / v7) + (float)((float)endx / v7)) - clicktimea;
  this->m_WorkFile.m_bDirty = true;
  IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
  PhonemeEditor::PushUndo(this);
  for ( i = 0; i < this->m_Tags.m_Words.m_Size; ++i )
  {
    v9 = this->m_Tags.m_Words.m_Memory.m_pMemory[i];
    if ( v9 != nullptr )
      PhonemeEditor::ITER_MoveSelectedWords(this, word: v9, amount: clicktime);
  }
  PhonemeEditor::RealignPhonemesToWords(this, prepareundo: false);
  PhonemeEditor::CleanupWordsAndPhonemes(this, prepareundo: false);
  this->m_bRedoPending = false;
  v10 = (CSentence *)operator new(nSize: 0x4Cu);
  if ( v10 != nullptr )
    v11 = CSentence::CSentence(this: v10);
  else
    v11 = nullptr;
  CSentence::operator=(this: v11, src: &this->m_Tags);
  this->m_UndoStack.m_Memory.m_pMemory[this->m_nUndoLevel - 1]->redo = v11;
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x00472910
// Name: private: void PhonemeEditor::FinishWordMove(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::FinishWordMove(PhonemeEditor *this, int startx, int endx)
{
  HWND Handle; // eax
  float v5; // xmm0_4
  HWND v6; // eax
  float v7; // xmm0_4
  CWordTag *v8; // eax
  float v9; // xmm2_4
  float v10; // xmm0_4
  CSentence *v11; // eax
  CSentence *v12; // edi
  tagRECT Rect; // [esp+18h] [ebp-18h] BYREF
  CWordTag *current; // [esp+28h] [ebp-8h] BYREF
  CWordTag *next; // [esp+2Ch] [ebp-4h] BYREF
  float clicktime; // [esp+38h] [ebp+8h]
  float endtime; // [esp+3Ch] [ebp+Ch]

  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &Rect);
  Rect.top += 60;
  Rect.bottom -= 95;
  InflateRect(lprc: &Rect, dx: -1, dy: -1);
  v5 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
  clicktime = (float)((float)this->m_nLeftOffset / v5) + (float)((float)startx / v5);
  v6 = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: v6, lpRect: &Rect);
  Rect.top += 60;
  Rect.bottom -= 95;
  InflateRect(lprc: &Rect, dx: -1, dy: -1);
  v7 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
  endtime = (float)((float)this->m_nLeftOffset / v7) + (float)((float)endx / v7);
  if ( PhonemeEditor::FindSpanningWords(this, time: clicktime, pp1: &current, pp2: &next) == 0 )
    return;
  this->m_WorkFile.m_bDirty = true;
  IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
  PhonemeEditor::PushUndo(this);
  v8 = next;
  if ( current == nullptr )
  {
    if ( next != nullptr )
    {
      next->m_flStartTime = (float)(endtime - clicktime) + next->m_flStartTime;
      goto LABEL_12;
    }
LABEL_7:
    v9 = endtime;
    v10 = 1.0 / (float)((float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond);
    if ( (float)(next->m_flEndTime - v10) <= endtime )
      v9 = next->m_flEndTime - v10;
    if ( v9 <= (float)(current->m_flStartTime + v10) )
      v9 = current->m_flStartTime + v10;
    current->m_flEndTime = v9;
    v8->m_flStartTime = v9;
    goto LABEL_12;
  }
  if ( next != nullptr )
    goto LABEL_7;
  current->m_flEndTime = (float)(endtime - clicktime) + current->m_flEndTime;
LABEL_12:
  PhonemeEditor::RealignPhonemesToWords(this, prepareundo: false);
  PhonemeEditor::CleanupWordsAndPhonemes(this, prepareundo: false);
  this->m_bRedoPending = false;
  v11 = (CSentence *)operator new(nSize: 0x4Cu);
  if ( v11 != nullptr )
    v12 = CSentence::CSentence(this: v11);
  else
    v12 = nullptr;
  CSentence::operator=(this: v12, src: &this->m_Tags);
  this->m_UndoStack.m_Memory.m_pMemory[this->m_nUndoLevel - 1]->redo = v12;
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x00472B20
// Name: private: void PhonemeEditor::FinishPhonemeDrag(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::FinishPhonemeDrag(PhonemeEditor *this, int startx, int endx)
{
  HWND Handle; // eax
  float v5; // xmm0_4
  HWND v6; // eax
  float v7; // xmm0_4
  CSentence *v8; // eax
  CSentence *v9; // edi
  tagRECT Rect; // [esp+10h] [ebp-10h] BYREF
  float clicktime; // [esp+28h] [ebp+8h]
  int clicktimea; // [esp+28h] [ebp+8h]

  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &Rect);
  Rect.top += 60;
  Rect.bottom -= 95;
  InflateRect(lprc: &Rect, dx: -1, dy: -1);
  v5 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
  clicktime = (float)((float)this->m_nLeftOffset / v5) + (float)((float)startx / v5);
  v6 = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: v6, lpRect: &Rect);
  Rect.top += 60;
  Rect.bottom -= 95;
  InflateRect(lprc: &Rect, dx: -1, dy: -1);
  v7 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
  *(float *)&clicktimea = (float)((float)((float)this->m_nLeftOffset / v7) + (float)((float)endx / v7)) - clicktime;
  this->m_WorkFile.m_bDirty = true;
  IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
  PhonemeEditor::PushUndo(this);
  PhonemeEditor::TraversePhonemes(
    this,
    pfn: (void (__thiscall *)(char *, CPhonemeTag *, CWordTag *, int))PhonemeEditor::ITER_MoveSelectedPhonemes,
    fparam: 0.0,
    fparama: clicktimea);
  PhonemeEditor::RealignWordsToPhonemes(this, prepareundo: false);
  PhonemeEditor::CleanupWordsAndPhonemes(this, prepareundo: false);
  this->m_bRedoPending = false;
  v8 = (CSentence *)operator new(nSize: 0x4Cu);
  if ( v8 != nullptr )
    v9 = CSentence::CSentence(this: v8);
  else
    v9 = nullptr;
  CSentence::operator=(this: v9, src: &this->m_Tags);
  this->m_UndoStack.m_Memory.m_pMemory[this->m_nUndoLevel - 1]->redo = v9;
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x00472CA0
// Name: private: void PhonemeEditor::FinishPhonemeMove(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::FinishPhonemeMove(PhonemeEditor *this, int startx, int endx)
{
  HWND Handle; // eax
  float v5; // xmm0_4
  HWND v6; // eax
  float v7; // xmm0_4
  CPhonemeTag *v8; // eax
  float v9; // xmm2_4
  float v10; // xmm0_4
  CSentence *v11; // eax
  CSentence *v12; // edi
  tagRECT Rect; // [esp+18h] [ebp-18h] BYREF
  CPhonemeTag *current; // [esp+28h] [ebp-8h] BYREF
  CPhonemeTag *next; // [esp+2Ch] [ebp-4h] BYREF
  float clicktime; // [esp+38h] [ebp+8h]
  float endtime; // [esp+3Ch] [ebp+Ch]

  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &Rect);
  Rect.top += 60;
  Rect.bottom -= 95;
  InflateRect(lprc: &Rect, dx: -1, dy: -1);
  v5 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
  clicktime = (float)((float)this->m_nLeftOffset / v5) + (float)((float)startx / v5);
  v6 = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: v6, lpRect: &Rect);
  Rect.top += 60;
  Rect.bottom -= 95;
  InflateRect(lprc: &Rect, dx: -1, dy: -1);
  v7 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
  endtime = (float)((float)this->m_nLeftOffset / v7) + (float)((float)endx / v7);
  if ( PhonemeEditor::FindSpanningPhonemes(this, time: clicktime, pp1: &current, pp2: &next) == 0 )
    return;
  this->m_WorkFile.m_bDirty = true;
  IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
  PhonemeEditor::PushUndo(this);
  v8 = next;
  if ( current == nullptr )
  {
    if ( next != nullptr )
    {
      next->m_flStartTime = (float)(endtime - clicktime) + next->m_flStartTime;
      goto LABEL_12;
    }
LABEL_7:
    v9 = endtime;
    v10 = 1.0 / (float)((float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond);
    if ( (float)(next->m_flEndTime - v10) <= endtime )
      v9 = next->m_flEndTime - v10;
    if ( v9 <= (float)(current->m_flStartTime + v10) )
      v9 = current->m_flStartTime + v10;
    current->m_flEndTime = v9;
    v8->m_flStartTime = v9;
    goto LABEL_12;
  }
  if ( next != nullptr )
    goto LABEL_7;
  current->m_flEndTime = (float)(endtime - clicktime) + current->m_flEndTime;
LABEL_12:
  PhonemeEditor::RealignWordsToPhonemes(this, prepareundo: false);
  PhonemeEditor::CleanupWordsAndPhonemes(this, prepareundo: false);
  this->m_bRedoPending = false;
  v11 = (CSentence *)operator new(nSize: 0x4Cu);
  if ( v11 != nullptr )
    v12 = CSentence::CSentence(this: v11);
  else
    v12 = nullptr;
  CSentence::operator=(this: v12, src: &this->m_Tags);
  this->m_UndoStack.m_Memory.m_pMemory[this->m_nUndoLevel - 1]->redo = v12;
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x00472EB0
// Name: private: void PhonemeEditor::EditInsertPhonemeBefore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::EditInsertPhonemeBefore(PhonemeEditor *this)
{
  CPhonemeTag *SelectedPhoneme; // eax
  CPhonemeTag *v3; // edi
  Color v4; // ecx
  double TimeGapToNextPhoneme; // st7
  CWordTag *WordForPhoneme; // eax
  Color v7; // ecx
  CWordTag *v8; // ebx
  Color v9; // ecx
  HWND Handle; // eax
  CPhonemeTag *v11; // eax
  CPhonemeParams params; // [esp+10h] [ebp-1B8h] BYREF
  CPhonemeTag phoneme; // [esp+1A0h] [ebp-28h] BYREF
  int iret; // [esp+1BCh] [ebp-Ch]
  int clicked; // [esp+1C0h] [ebp-8h]
  float gap; // [esp+1C4h] [ebp-4h] BYREF

  if ( this->m_CurrentMode == MODE_PHONEMES )
  {
    SelectedPhoneme = PhonemeEditor::GetSelectedPhoneme(this);
    v3 = SelectedPhoneme;
    if ( SelectedPhoneme != nullptr )
    {
      TimeGapToNextPhoneme = PhonemeEditor::GetTimeGapToNextPhoneme(
                               this,
                               forward: false,
                               currentPhoneme: SelectedPhoneme,
                               ppword: nullptr,
                               ppphoneme: nullptr);
      gap = TimeGapToNextPhoneme;
      if ( TimeGapToNextPhoneme >= 0.0099999998 )
      {
        if ( gap >= 0.1 )
          gap = 0.1;
        WordForPhoneme = CSentence::GetWordForPhoneme(this: &this->m_Tags, phoneme: v3);
        v8 = WordForPhoneme;
        if ( WordForPhoneme != nullptr )
        {
          clicked = CWordTag::IndexOfPhoneme(this: WordForPhoneme, tag: v3);
          if ( clicked >= 0 )
          {
            CPhonemeTag::CPhonemeTag(this: &phoneme);
            memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
            strcpy(params.m_szDialogTitle, "Phoneme/Viseme Properties");
            params.m_szName[0] = 0;
            iret = PhonemeProperties(&params);
            Handle = (HWND)mxWidget::getHandle(this);
            SetFocus(hWnd: Handle);
            if ( iret != 0 )
            {
              this->m_WorkFile.m_bDirty = true;
              IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
              PhonemeEditor::PushUndo(this);
              phoneme.m_nPhonemeCode = TextToPhoneme(text: params.m_szName);
              CPhonemeTag::SetTag(this: &phoneme, phoneme: params.m_szName);
              phoneme.m_flEndTime = v3->m_flStartTime;
              phoneme.m_flStartTime = v3->m_flStartTime - gap;
              phoneme.m_bSelected = true;
              v3->m_bSelected = false;
              v11 = (CPhonemeTag *)operator new(nSize: 0x1Cu);
              if ( v11 != nullptr )
                gap = COERCE_FLOAT(CPhonemeTag::CPhonemeTag(this: v11, from: &phoneme));
              else
                gap = 0.0;
              CUtlVector<CPhonemeTag *,CUtlMemory<CPhonemeTag *,int>>::InsertBefore(
                this: (CUtlVector<CWordTag *,CUtlMemory<CWordTag *,int> > *)&v8->m_Phonemes,
                elem: clicked,
                src: (CWordTag **)&gap);
              PhonemeEditor::PushRedo(this);
              this->redraw(this);
            }
            CPhonemeTag::~CPhonemeTag(this: &phoneme);
          }
          else
          {
            Con_Printf(a1: v9, fmt: "EditInsertPhonemeBefore:  phoneme not a member of any specified word!!!\n");
          }
        }
        else
        {
          Con_Printf(a1: v7, fmt: "EditInsertPhonemeBefore:  phoneme not a member of any known word!!!\n");
        }
      }
      else
      {
        Con_Printf(a1: v4, fmt: "Can't insert before, gap of %.2f ms is too small\n", (float)(gap * 1000.0));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004730C0
// Name: private: void PhonemeEditor::EditInsertPhonemeAfter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::EditInsertPhonemeAfter(PhonemeEditor *this)
{
  CPhonemeTag *SelectedPhoneme; // eax
  CPhonemeTag *v3; // esi
  Color v4; // ecx
  double TimeGapToNextPhoneme; // st7
  CWordTag *WordForPhoneme; // eax
  Color v7; // ecx
  CWordTag *v8; // edi
  Color v9; // ecx
  HWND Handle; // eax
  CPhonemeTag *v11; // eax
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Phonemes; // esi
  int v15; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v17; // eax
  float *v18; // edi
  CPhonemeParams params; // [esp+10h] [ebp-1B8h] BYREF
  CPhonemeTag phoneme; // [esp+1A0h] [ebp-28h] BYREF
  int iret; // [esp+1BCh] [ebp-Ch]
  int clicked; // [esp+1C0h] [ebp-8h]
  float gap; // [esp+1C4h] [ebp-4h]

  if ( this->m_CurrentMode == MODE_PHONEMES )
  {
    SelectedPhoneme = PhonemeEditor::GetSelectedPhoneme(this);
    v3 = SelectedPhoneme;
    if ( SelectedPhoneme != nullptr )
    {
      TimeGapToNextPhoneme = PhonemeEditor::GetTimeGapToNextPhoneme(
                               this,
                               forward: true,
                               currentPhoneme: SelectedPhoneme,
                               ppword: nullptr,
                               ppphoneme: nullptr);
      gap = TimeGapToNextPhoneme;
      if ( TimeGapToNextPhoneme >= 0.0099999998 )
      {
        if ( gap >= 0.1 )
          gap = 0.1;
        WordForPhoneme = CSentence::GetWordForPhoneme(this: &this->m_Tags, phoneme: v3);
        v8 = WordForPhoneme;
        if ( WordForPhoneme != nullptr )
        {
          clicked = CWordTag::IndexOfPhoneme(this: WordForPhoneme, tag: v3);
          if ( clicked >= 0 )
          {
            CPhonemeTag::CPhonemeTag(this: &phoneme);
            memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
            strcpy(params.m_szDialogTitle, "Phoneme/Viseme Properties");
            params.m_szName[0] = 0;
            iret = PhonemeProperties(&params);
            Handle = (HWND)mxWidget::getHandle(this);
            SetFocus(hWnd: Handle);
            if ( iret != 0 )
            {
              this->m_WorkFile.m_bDirty = true;
              IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
              PhonemeEditor::PushUndo(this);
              phoneme.m_nPhonemeCode = TextToPhoneme(text: params.m_szName);
              CPhonemeTag::SetTag(this: &phoneme, phoneme: params.m_szName);
              phoneme.m_flEndTime = v3->m_flEndTime + gap;
              phoneme.m_flStartTime = v3->m_flEndTime;
              phoneme.m_bSelected = true;
              v3->m_bSelected = false;
              v11 = (CPhonemeTag *)operator new(nSize: 0x1Cu);
              if ( v11 != nullptr )
                gap = COERCE_FLOAT(CPhonemeTag::CPhonemeTag(this: v11, from: &phoneme));
              else
                gap = 0.0;
              m_Size = v8->m_Phonemes.m_Size;
              m_nAllocationCount = v8->m_Phonemes.m_Memory.m_nAllocationCount;
              p_m_Phonemes = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v8->m_Phonemes;
              v15 = clicked + 1;
              if ( m_Size + 1 > m_nAllocationCount )
                CUtlMemory<IFacePoserToolWindow *,int>::Grow(this: p_m_Phonemes, num: m_Size - m_nAllocationCount + 1);
              ++p_m_Phonemes[1].m_pMemory;
              m_pMemory = p_m_Phonemes->m_pMemory;
              v17 = (int)p_m_Phonemes[1].m_pMemory - v15 - 1;
              p_m_Phonemes[1].m_nAllocationCount = (int)p_m_Phonemes->m_pMemory;
              if ( v17 > 0 )
                _V_memmove(dest: &m_pMemory[v15 + 1], src: &m_pMemory[v15], count: 4 * v17);
              v18 = (float *)&p_m_Phonemes->m_pMemory[v15];
              if ( v18 != nullptr )
                *v18 = gap;
              PhonemeEditor::PushRedo(this);
              this->redraw(this);
            }
            CPhonemeTag::~CPhonemeTag(this: &phoneme);
          }
          else
          {
            Con_Printf(a1: v9, fmt: "EditInsertPhonemeAfter:  phoneme not a member of any specified word!!!\n");
          }
        }
        else
        {
          Con_Printf(a1: v7, fmt: "EditInsertPhonemeAfter:  phoneme not a member of any known word!!!\n");
        }
      }
      else
      {
        Con_Printf(a1: v4, fmt: "Can't insert after, gap of %.2f ms is too small\n", (float)(gap * 1000.0));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00473310
// Name: private: void PhonemeEditor::EditDeletePhoneme(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::EditDeletePhoneme(PhonemeEditor *this)
{
  int v2; // eax
  CWordTag *v3; // esi
  int v4; // edi
  CPhonemeTag **m_pMemory; // edx
  CPhonemeTag *v6; // eax
  CSentence *v7; // eax
  CSentence *v8; // esi
  int i; // [esp+4h] [ebp-4h]

  if ( this->m_CurrentMode == MODE_PHONEMES )
  {
    PhonemeEditor::CountSelected(this);
    if ( this->m_nSelectedPhonemeCount >= 1 )
    {
      this->m_WorkFile.m_bDirty = true;
      IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
      PhonemeEditor::PushUndo(this);
      v2 = this->m_Tags.m_Words.m_Size - 1;
      for ( i = v2; v2 >= 0; i = v2 )
      {
        v3 = this->m_Tags.m_Words.m_Memory.m_pMemory[v2];
        if ( v3 != nullptr )
        {
          v4 = v3->m_Phonemes.m_Size - 1;
          if ( v4 >= 0 )
          {
            do
            {
              m_pMemory = v3->m_Phonemes.m_Memory.m_pMemory;
              v6 = m_pMemory[v4];
              if ( v6 != nullptr && v6->m_bSelected )
              {
                if ( v3->m_Phonemes.m_Size - v4 - 1 > 0 )
                  _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 4 * (v3->m_Phonemes.m_Size - v4 - 1));
                --v3->m_Phonemes.m_Size;
              }
              --v4;
            }
            while ( v4 >= 0 );
            v2 = i;
          }
        }
        --v2;
      }
      this->m_bRedoPending = false;
      v7 = (CSentence *)operator new(nSize: 0x4Cu);
      if ( v7 != nullptr )
        v8 = CSentence::CSentence(this: v7);
      else
        v8 = nullptr;
      CSentence::operator=(this: v8, src: &this->m_Tags);
      this->m_UndoStack.m_Memory.m_pMemory[this->m_nUndoLevel - 1]->redo = v8;
      this->redraw(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00473410
// Name: private: void PhonemeEditor::EditDeleteWord(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::EditDeleteWord(PhonemeEditor *this)
{
  int i; // edi
  CWordTag *v3; // eax
  CSentence *v4; // eax
  CSentence *v5; // edi

  if ( this->m_CurrentMode == MODE_PHONEMES )
  {
    PhonemeEditor::CountSelected(this);
    if ( this->m_nSelectedWordCount >= 1 )
    {
      this->m_WorkFile.m_bDirty = true;
      IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
      PhonemeEditor::PushUndo(this);
      for ( i = this->m_Tags.m_Words.m_Size - 1; i >= 0; --i )
      {
        v3 = this->m_Tags.m_Words.m_Memory.m_pMemory[i];
        if ( v3 != nullptr && v3->m_bSelected )
        {
          if ( this->m_Tags.m_Words.m_Size - i - 1 > 0 )
            _V_memmove(
              dest: &this->m_Tags.m_Words.m_Memory.m_pMemory[i],
              src: &this->m_Tags.m_Words.m_Memory.m_pMemory[i + 1],
              count: 4 * (this->m_Tags.m_Words.m_Size - i - 1));
          --this->m_Tags.m_Words.m_Size;
        }
      }
      this->m_bRedoPending = false;
      v4 = (CSentence *)operator new(nSize: 0x4Cu);
      if ( v4 != nullptr )
        v5 = CSentence::CSentence(this: v4);
      else
        v5 = nullptr;
      CSentence::operator=(this: v5, src: &this->m_Tags);
      this->m_UndoStack.m_Memory.m_pMemory[this->m_nUndoLevel - 1]->redo = v5;
      this->redraw(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00473500
// Name: private: void PhonemeEditor::SentenceFromString(class CSentence __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::SentenceFromString(PhonemeEditor *this, CSentence *sentence, const char *str)
{
  CSentence *v3; // esi
  const char *v4; // ebx
  char *v5; // ecx
  char v6; // al
  CWordTag *v7; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CWordTag **m_pMemory; // ecx
  int v11; // eax
  CWordTag **v12; // eax
  CWordTag *v13; // eax
  CWordTag *v14; // ebx
  int v15; // edi
  int v16; // eax
  CWordTag **v17; // ecx
  int v18; // eax
  CWordTag **v19; // eax
  char word[256]; // [esp+8h] [ebp-104h] BYREF
  CWordTag *w; // [esp+108h] [ebp-4h]

  v3 = sentence;
  CSentence::Reset(this: sentence);
  v4 = str;
  if ( str != nullptr && *str != 0 && CSentence::CountWords(str) != 0 )
  {
    v5 = word;
    if ( *str != 0 )
    {
      do
      {
        v6 = *v4;
        if ( *v4 <= 0x20u )
        {
          for ( *v5 = 0; v6 != 0; v6 = *++v4 )
          {
            if ( (unsigned __int8)v6 > 0x20u )
              break;
          }
          if ( strlen(word) != 0 )
          {
            v7 = (CWordTag *)operator new(nSize: 0x2Cu);
            if ( v7 != nullptr )
            {
              w = CWordTag::CWordTag(this: v7, word);
              if ( w != nullptr )
              {
                m_Size = v3->m_Words.m_Size;
                m_nAllocationCount = v3->m_Words.m_Memory.m_nAllocationCount;
                if ( m_Size + 1 > m_nAllocationCount )
                  CUtlMemory<IFacePoserToolWindow *,int>::Grow(
                    this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v3->m_Words,
                    num: m_Size - m_nAllocationCount + 1);
                ++v3->m_Words.m_Size;
                m_pMemory = v3->m_Words.m_Memory.m_pMemory;
                v11 = v3->m_Words.m_Size - m_Size - 1;
                v3->m_Words.m_pElements = m_pMemory;
                if ( v11 > 0 )
                  _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
                v12 = &v3->m_Words.m_Memory.m_pMemory[m_Size];
                if ( v12 != nullptr )
                  *v12 = w;
              }
            }
          }
          v3 = sentence;
          v5 = word;
        }
        else
        {
          *v5++ = v6;
          ++v4;
        }
      }
      while ( *v4 != 0 );
    }
    *v5 = 0;
    if ( strlen(word) != 0 )
    {
      v13 = (CWordTag *)operator new(nSize: 0x2Cu);
      if ( v13 != nullptr )
      {
        v14 = CWordTag::CWordTag(this: v13, word);
        if ( v14 != nullptr )
        {
          v15 = v3->m_Words.m_Size;
          v16 = v3->m_Words.m_Memory.m_nAllocationCount;
          if ( v15 + 1 > v16 )
            CUtlMemory<IFacePoserToolWindow *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v3->m_Words,
              num: v15 - v16 + 1);
          ++v3->m_Words.m_Size;
          v17 = v3->m_Words.m_Memory.m_pMemory;
          v18 = v3->m_Words.m_Size - v15 - 1;
          v3->m_Words.m_pElements = v17;
          if ( v18 > 0 )
            _V_memmove(dest: &v17[v15 + 1], src: &v17[v15], count: 4 * v18);
          v19 = &v3->m_Words.m_Memory.m_pMemory[v15];
          if ( v19 != nullptr )
            *v19 = v14;
        }
      }
    }
    CSentence::SetText(this: sentence, text: str);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004736C0
// Name: private: void PhonemeEditor::RedoPhonemeExtractionSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall PhonemeEditor::RedoPhonemeExtractionSelected(
        PhonemeEditor *this@<ecx>,
        const char *a2@<edi>,
        int a3@<esi>)
{
  bool v4; // zf
  CAudioSource *m_pWaveFile; // ecx
  int v6; // eax
  CAudioSource *v7; // ecx
  float (__thiscall *GetRunningLength)(CAudioSource *); // edx
  Color v9; // ecx
  double v10; // st7
  double v11; // st7
  int v12; // eax
  char v13; // cl
  Color v14; // ecx
  Color v15; // ecx
  Color v16; // ecx
  char *Text; // eax
  int v18; // eax
  CWordTag *v19; // edi
  CWordTag *v20; // eax
  int m_Size; // eax
  int v22; // esi
  CWordTag **m_pMemory; // ecx
  int v24; // eax
  int *v25; // eax
  char *Word; // eax
  int v27; // eax
  Color v28; // ecx
  CAudioSource *v29; // esi
  IPhonemeExtractor_vtbl *v30; // edi
  int v31; // eax
  CAudioSource_vtbl *v32; // edx
  double v33; // st7
  float (__thiscall *v34)(CAudioSource *); // eax
  double v35; // st7
  CAudioSource_vtbl *v36; // eax
  double v37; // st7
  int v38; // eax
  int v39; // ecx
  int v40; // eax
  CAudioSource_vtbl *v41; // edx
  double v42; // st7
  float (__thiscall *TrueSampleSize)(CAudioSource *); // eax
  double v44; // st7
  IPhonemeExtractor *m_pPhonemeExtractor; // ecx
  PE_APITYPE (__thiscall *GetAPIType)(IPhonemeExtractor *); // eax
  int m_uiEndByte; // ecx
  int v48; // edi
  int i; // esi
  CWordTag *v50; // eax
  double v51; // st6
  double v52; // st5
  int v53; // edx
  int v54; // edi
  double v55; // st5
  float v56; // eax
  CWordTag *v57; // ebx
  float v58; // edi
  CPhonemeTag *v59; // esi
  CPhonemeTag **v60; // edx
  CPhonemeTag *v61; // eax
  CPhonemeTag *v62; // ebx
  float v63; // esi
  int v64; // edi
  int v65; // eax
  int v66; // ecx
  int v67; // eax
  CPhonemeTag **v68; // eax
  int v69; // ebx
  int v70; // eax
  const CWordTag *v71; // esi
  CWordTag *v72; // eax
  CWordTag *v73; // edi
  float v74; // xmm0_4
  int v75; // ecx
  float *p_m_flStartTime; // eax
  mxWidget *v77; // esi
  mxWidget_vtbl *v78; // eax
  mxWidget_vtbl *v79; // ecx
  mxWidget_i *d_this; // ecx
  int v81; // eax
  CWordTag **v82; // eax
  mxWidget *v83; // esi
  HWND Handle; // eax
  int v87; // [esp+0h] [ebp-2064h]
  char pDest[4096]; // [esp+4h] [ebp-2060h] BYREF
  _BYTE v89[1024]; // [esp+1004h] [ebp-1060h]
  char out[512]; // [esp+1404h] [ebp-C60h] BYREF
  CInputParams dst; // [esp+1604h] [ebp-A60h] BYREF
  char v92[512]; // [esp+1B90h] [ebp-4D4h] BYREF
  CAudioMixer_vtbl filename[6]; // [esp+1D90h] [ebp-2D4h] BYREF
  CPhonemeTag from; // [esp+1F90h] [ebp-D4h] BYREF
  CSentence v95; // [esp+1FACh] [ebp-B8h] BYREF
  CSentence sentence; // [esp+1FF8h] [ebp-6Ch] BYREF
  float v97; // [esp+2044h] [ebp-20h]
  mxWidget *v98; // [esp+2048h] [ebp-1Ch]
  int v99; // [esp+204Ch] [ebp-18h]
  CWordTag *v100; // [esp+2050h] [ebp-14h]
  float v101; // [esp+2054h] [ebp-10h]
  int v102; // [esp+2058h] [ebp-Ch]
  char v103; // [esp+205Eh] [ebp-6h]
  char v104; // [esp+205Fh] [ebp-5h]
  float v105; // [esp+2060h] [ebp-4h]

  v4 = this->m_CurrentMode == MODE_PHONEMES;
  v98 = this;
  if ( v4 && PhonemeEditor::CheckSpeechAPI(this) )
  {
    m_pWaveFile = this->m_pWaveFile;
    if ( m_pWaveFile == nullptr )
    {
      Con_Printf(a1: 0, fmt: "Can't redo extraction, no wavefile loaded!\n");
      return;
    }
    if ( !this->m_bSelectionActive )
    {
      Con_Printf(a1: (Color)m_pWaveFile, fmt: "Please select a portion of the .wav from which to re-extract phonemes\n");
      return;
    }
    *(float *)&v6 = COERCE_FLOAT(m_pWaveFile->SampleRate(this: m_pWaveFile));
    v7 = this->m_pWaveFile;
    v105 = *(float *)&v6;
    GetRunningLength = v7->GetRunningLength;
    v105 = (float)v6;
    v10 = ((double (__thiscall *)(CAudioSource *))GetRunningLength)(a1: v7) * v105;
    v105 = v10;
    if ( v10 <= 0.0 )
    {
      Con_Printf(a1: v9, fmt: "Original .wav file %s has no samples!!!\n", this->m_WorkFile.m_szWaveFile);
      return;
    }
    v11 = ((double (__thiscall *)(CAudioSource *))this->m_pWaveFile->GetRunningLength)(a1: this->m_pWaveFile)
        * ((double)this->m_nSelection[0]
         / v105);
    v97 = v11;
    if ( v11 < 0.0 )
      v97 = 0.0;
    CSentence::CSentence(this: &sentence);
    CSentence::CSentence(this: &v95);
    PhonemeEditor::CountSelected(this);
    v4 = this->m_nSelectedWordCount == 0;
    v104 = 1;
    if ( v4 )
    {
      v89[0] = 0;
      memset((unsigned __int8 *)&dst, value: 0, count: sizeof(dst));
      strcpy(dst.m_szDialogTitle, "Phrase Word List");
      strcpy(dst.m_szPrompt, "Phrase");
      v12 = 0;
      do
      {
        v13 = v89[v12];
        dst.m_szInputText[v12++] = v13;
      }
      while ( v13 != 0 );
      if ( InputProperties(params: &dst) == 0 )
        goto LABEL_109;
      if ( &dst.m_szInputText[strlen(dst.m_szInputText) + 1] == &dst.m_szInputText[1] )
      {
        Con_ErrorPrintf(a1: v14, fmt: "Edit word list:  No words entered!\n");
LABEL_109:
        CSentence::~CSentence(this: &v95);
        CSentence::~CSentence(this: &sentence);
        return;
      }
      PhonemeEditor::SentenceFromString(this, &sentence, str: dst.m_szInputText);
      if ( sentence.m_Words.m_Size == 0 )
      {
        Con_Printf(
          a1: v15,
          fmt: "You must either select words, or type in a set of words in order to extract phonemes!\n");
        goto LABEL_109;
      }
      v104 = 0;
    }
    else
    {
      if ( !PhonemeEditor::AreSelectedWordsContiguous(this) )
      {
        Con_Printf(a1: v16, fmt: "Can only redo extraction on a contiguous subset of words\n");
        goto LABEL_109;
      }
      v103 = 0;
      Text = CSentence::GetText(this: &sentence);
      V_strncpy(pDest, pSrc: Text, maxLen: 4096);
      v18 = 0;
      for ( *(float *)&v102 = 0.0; v18 < this->m_Tags.m_Words.m_Size; v102 = v18 )
      {
        v19 = this->m_Tags.m_Words.m_Memory.m_pMemory[v18];
        if ( v19 != nullptr && v19->m_bSelected )
        {
          v20 = (CWordTag *)operator new(nSize: 0x2Cu);
          if ( v20 != nullptr )
            v99 = (int)CWordTag::CWordTag(this: v20, from: v19);
          else
            v99 = 0;
          m_Size = sentence.m_Words.m_Size;
          v22 = sentence.m_Words.m_Size;
          if ( sentence.m_Words.m_Size + 1 > sentence.m_Words.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IFacePoserToolWindow *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&sentence.m_Words,
              num: sentence.m_Words.m_Size - sentence.m_Words.m_Memory.m_nAllocationCount + 1);
            m_Size = sentence.m_Words.m_Size;
          }
          m_pMemory = sentence.m_Words.m_Memory.m_pMemory;
          sentence.m_Words.m_Size = m_Size + 1;
          v24 = m_Size - v22;
          sentence.m_Words.m_pElements = sentence.m_Words.m_Memory.m_pMemory;
          if ( v24 > 0 )
          {
            _V_memmove(
              dest: &sentence.m_Words.m_Memory.m_pMemory[v22 + 1],
              src: &sentence.m_Words.m_Memory.m_pMemory[v22],
              count: 4 * v24);
            m_pMemory = sentence.m_Words.m_Memory.m_pMemory;
          }
          v25 = (int *)&m_pMemory[v22];
          if ( v25 != nullptr )
            *v25 = v99;
          Word = CWordTag::GetWord(this: v19);
          V_strncat(pDest, pSrc: Word, destBufferSize: 0x1000u, max_chars_to_copy: -1);
          V_strncat(pDest, pSrc: " ", destBufferSize: 0x1000u, max_chars_to_copy: -1);
          v18 = v102;
          v103 = 1;
        }
        ++v18;
      }
      v27 = _V_strlen(str: pDest);
      if ( v103 != 0 && v27 >= 1 )
        pDest[v27 - 1] = 0;
      CSentence::SetText(this: &sentence, text: pDest);
    }
    this->m_nLastExtractionResult = 0;
    V_StripExtension(in: this->m_WorkFile.m_szWaveFile, out, outSize: 512);
    V_snprintf(pDest: (char *)filename, maxLen: 512, pFormat: "%s%s_work1.wav", this->m_WorkFile.m_szBasePath, out);
    filesystem->RemoveFile(this: filesystem, a2: (const char *)filename, a3: "GAME");
    if ( PhonemeEditor::CreateCroppedWave(
           this,
           a2: (int)this,
           filename,
           startsample: this->m_nSelection[0],
           endsample: this->m_nSelection[1]) != 0 )
    {
      v29 = sound->LoadSound(this: sound, a2: filename);
      if ( v29 != nullptr )
      {
        PhonemeEditor::SaveLinguisticData(this);
        CSentence::operator=(this: &this->m_TagsExt, src: &this->m_Tags);
        V_snprintf(pDest: v92, maxLen: 512, pFormat: "%s%s", this->m_WorkFile.m_szBasePath, (const char *)filename);
        v30 = this->m_pPhonemeExtractor->__vftable;
        *(float *)&v31 = COERCE_FLOAT(((int (__thiscall *)(CAudioSource *, const char *, int))v29->SampleRate)(a1: v29, a2, a3));
        v32 = v29->__vftable;
        v105 = *(float *)&v31;
        v33 = (double)v31;
        v34 = v32->GetRunningLength;
        v105 = v33;
        v35 = ((double (__thiscall *)(CAudioSource *))v34)(a1: v29);
        v36 = v29->__vftable;
        v105 = v35 * v105;
        v37 = ((double (__thiscall *)(CAudioSource *, void (__usercall *)(Color@<ecx>, const char *, ...), CSentence *, CSentence *))v36->TrueSampleSize)(
                a1: v29,
                a2: Con_Printf,
                a3: &sentence,
                a4: &v95);
        v38 = ((int (__thiscall *)(IPhonemeExtractor *, char *, int))v30->Extract)(
                a1: this->m_pPhonemeExtractor,
                a2: v92,
                a3: (int)(v37 * v105));
        v39 = v95.m_Words.m_Size;
        this->m_nLastExtractionResult = v38;
        if ( sentence.m_Words.m_Size == v39 )
        {
          *(float *)&v40 = COERCE_FLOAT(v29->SampleRate(this: v29));
          v41 = v29->__vftable;
          v105 = *(float *)&v40;
          v42 = (double)v40;
          TrueSampleSize = v41->TrueSampleSize;
          v105 = v42;
          v44 = ((double (__thiscall *)(CAudioSource *))TrueSampleSize)(a1: v29);
          m_pPhonemeExtractor = this->m_pPhonemeExtractor;
          GetAPIType = m_pPhonemeExtractor->GetAPIType;
          v101 = v44 * v105;
          if ( GetAPIType(this: m_pPhonemeExtractor) == SPEECH_API_LIPSINC
            && v29->IsStereoWav(this: v29)
            && v29->SampleSize(this: v29) == 16 )
          {
            v101 = v101 * 2.0;
          }
          v48 = v95.m_Words.m_Size;
          for ( i = 0; i < v95.m_Words.m_Size; ++i )
          {
            m_uiEndByte = (int)v95.m_Words.m_Memory.m_pMemory;
            v50 = v95.m_Words.m_Memory.m_pMemory[i];
            if ( v50 != nullptr )
            {
              v51 = 1.0 / v101;
              m_uiEndByte = v50->m_uiEndByte;
              v50->m_flStartTime = (double)v50->m_uiStartByte * v51;
              v52 = (double)(int)v50->m_uiEndByte;
              if ( m_uiEndByte < 0 )
                v52 = v52 + 4294967300.0;
              v53 = 0;
              for ( v50->m_flEndTime = v52 * v51; v53 < v50->m_Phonemes.m_Size; ++v53 )
              {
                m_uiEndByte = (int)v50->m_Phonemes.m_Memory.m_pMemory[v53];
                if ( *(float *)&m_uiEndByte != 0.0 )
                {
                  v54 = *(_DWORD *)(m_uiEndByte + 20);
                  *(float *)m_uiEndByte = (double)*(unsigned int *)(m_uiEndByte + 16) * v51;
                  v55 = (double)*(int *)(m_uiEndByte + 20);
                  if ( v54 < 0 )
                    v55 = v55 + 4294967300.0;
                  *(float *)(m_uiEndByte + 4) = v55 * v51;
                }
              }
            }
            v48 = v95.m_Words.m_Size;
          }
          if ( v104 != 0 )
          {
            v99 = 0;
            *(float *)&v102 = 0.0;
            if ( this->m_TagsExt.m_Words.m_Size > 0 )
            {
              do
              {
                m_uiEndByte = v102;
                v56 = *((float *)&v98[202].d_this->d_parent_p + v102);
                v101 = v56;
                if ( v56 != 0.0 && *(_BYTE *)(LODWORD(v56) + 28) != 0 )
                {
                  if ( v99 >= v48 )
                    break;
                  v57 = v95.m_Words.m_Memory.m_pMemory[v99];
                  v100 = v57;
                  ++v99;
                  if ( v57 != nullptr )
                  {
                    if ( *(int *)(LODWORD(v56) + 20) > 0 )
                    {
                      v58 = v56;
                      do
                      {
                        v59 = **(CPhonemeTag ***)(LODWORD(v58) + 8);
                        CUtlVector<Color,CUtlMemory<Color,int>>::Remove(
                          this: (CUtlVector<CPhonemeTag *,CUtlMemory<CPhonemeTag *,int> > *)(LODWORD(v58) + 8),
                          elem: 0);
                        if ( v59 != nullptr )
                        {
                          CPhonemeTag::~CPhonemeTag(this: v59);
                          free(pMem: v59);
                        }
                      }
                      while ( *(int *)(LODWORD(v101) + 20) > 0 );
                    }
                    *(float *)&m_uiEndByte = 0.0;
                    v105 = 0.0;
                    if ( v57->m_Phonemes.m_Size > 0 )
                    {
                      do
                      {
                        v60 = v57->m_Phonemes.m_Memory.m_pMemory;
                        if ( v60[m_uiEndByte] != nullptr )
                        {
                          CPhonemeTag::CPhonemeTag(this: &from, from: v60[m_uiEndByte]);
                          from.m_flStartTime = from.m_flStartTime + v97;
                          from.m_flEndTime = from.m_flEndTime + v97;
                          v61 = (CPhonemeTag *)operator new(nSize: 0x1Cu);
                          if ( v61 != nullptr )
                          {
                            v62 = CPhonemeTag::CPhonemeTag(this: v61, &from);
                            if ( v62 != nullptr )
                            {
                              v63 = v101;
                              v64 = *(_DWORD *)(LODWORD(v101) + 20);
                              v65 = *(_DWORD *)(LODWORD(v101) + 12);
                              if ( v64 + 1 > v65 )
                                CUtlMemory<IFacePoserToolWindow *,int>::Grow(
                                  this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)(LODWORD(v101) + 8),
                                  num: v64 - v65 + 1);
                              ++*(_DWORD *)(LODWORD(v63) + 20);
                              v66 = *(_DWORD *)(LODWORD(v63) + 8);
                              v67 = *(_DWORD *)(LODWORD(v63) + 20) - v64 - 1;
                              *(_DWORD *)(LODWORD(v63) + 24) = v66;
                              if ( v67 > 0 )
                                _V_memmove(
                                  dest: (void *)(v66 + 4 * v64 + 4),
                                  src: (const void *)(v66 + 4 * v64),
                                  count: 4 * v67);
                              v68 = (CPhonemeTag **)(*(_DWORD *)(LODWORD(v63) + 8) + 4 * v64);
                              if ( v68 != nullptr )
                                *v68 = v62;
                            }
                          }
                          CPhonemeTag::~CPhonemeTag(this: &from);
                          v57 = v100;
                          *(float *)&m_uiEndByte = v105;
                        }
                        ++m_uiEndByte;
                        v105 = *(float *)&m_uiEndByte;
                      }
                      while ( m_uiEndByte < v57->m_Phonemes.m_Size );
                    }
                    v48 = v95.m_Words.m_Size;
                    if ( v99 >= v95.m_Words.m_Size )
                      break;
                  }
                }
                m_uiEndByte = (int)v98;
                ++v102;
              }
              while ( v102 < (int)v98[204].__vftable );
            }
          }
          else
          {
            v69 = 0;
            if ( (int)v98[204].__vftable > 0 )
            {
              m_uiEndByte = (int)v98[202].d_this;
              do
              {
                if ( *(_DWORD *)m_uiEndByte != 0
                  && **(float **)m_uiEndByte > (float)(**(float **)v95.m_Words.m_Memory.m_pMemory + v97) )
                {
                  break;
                }
                ++v69;
                m_uiEndByte += 4;
              }
              while ( v69 < (int)v98[204].__vftable );
            }
            v70 = 0;
            *(float *)&v102 = 0.0;
            if ( v48 > 0 )
            {
              do
              {
                m_uiEndByte = (int)v95.m_Words.m_Memory.m_pMemory;
                v71 = v95.m_Words.m_Memory.m_pMemory[v70];
                if ( v71 != nullptr )
                {
                  v72 = (CWordTag *)operator new(nSize: 0x2Cu);
                  if ( v72 != nullptr )
                    v73 = CWordTag::CWordTag(this: v72, from: v71);
                  else
                    v73 = nullptr;
                  v74 = v97;
                  v73->m_flStartTime = v73->m_flStartTime + v97;
                  v75 = 0;
                  for ( v73->m_flEndTime = v74 + v73->m_flEndTime; v75 < v73->m_Phonemes.m_Size; ++v75 )
                  {
                    p_m_flStartTime = &v73->m_Phonemes.m_Memory.m_pMemory[v75]->m_flStartTime;
                    if ( p_m_flStartTime != nullptr )
                    {
                      *p_m_flStartTime = *p_m_flStartTime + v74;
                      p_m_flStartTime[1] = p_m_flStartTime[1] + v74;
                    }
                  }
                  v77 = v98;
                  v78 = v98[204].__vftable;
                  v79 = v98[203].__vftable;
                  if ( (int)((char *)&v78->dtr_mxWidget + 1) > (int)v79 )
                    CUtlMemory<IFacePoserToolWindow *,int>::Grow(
                      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v98[202].d_this,
                      num: (char *)v78 - (char *)v79 + 1);
                  ++v77[204].__vftable;
                  d_this = v77[202].d_this;
                  v81 = (int)v77[204].__vftable - v69 - 1;
                  v77[204].d_this = d_this;
                  if ( v81 > 0 )
                    _V_memmove(dest: &d_this->d_hwnd + v69, src: &d_this->d_parent_p + v69, count: 4 * v81);
                  m_uiEndByte = (int)v77[202].d_this;
                  v82 = (CWordTag **)(m_uiEndByte + 4 * v69);
                  if ( v82 != nullptr )
                    *v82 = v73;
                  v70 = v102;
                  ++v69;
                }
                v102 = ++v70;
              }
              while ( v70 < v95.m_Words.m_Size );
            }
          }
          Con_Printf(a1: (Color)m_uiEndByte, fmt: "Cleaning up...\n");
          filesystem->RemoveFile(this: filesystem, a2: v92, a3: "GAME");
          v83 = v98;
          Handle = (HWND)mxWidget::getHandle(this: v98);
          SetFocus(hWnd: Handle);
          v83->__vftable[1].CanClose(this: v83);
        }
        else
        {
          Con_Printf(
            a1: (Color)v39,
            fmt: "Extraction returned %i words, source had %i, try adjusting selection\n",
            v39,
            sentence.m_Words.m_Size);
          filesystem->RemoveFile(this: filesystem, a2: v92, a3: "GAME");
          this->redraw(this);
        }
      }
      else
      {
        Con_Printf(a1: v28, fmt: "Unable to load cropped wave file %s from samples %i to %i\n", a2, a3, v87);
      }
    }
    else
    {
      Con_Printf(
        a1: (Color)this->m_nSelection[0],
        fmt: "Unable to create cropped wave file %s from samples %i to %i\n",
        (const char *)filename,
        this->m_nSelection[0],
        this->m_nSelection[1]);
    }
    goto LABEL_109;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474020
// Name: private: void PhonemeEditor::SnapWords(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::SnapWords(PhonemeEditor *this)
{
  int i; // edx
  CWordTag **v3; // eax
  CWordTag *v4; // ecx
  bool v5; // zf
  CWordTag *v6; // eax
  CSentence *v7; // eax
  CSentence *v8; // edi

  if ( this->m_CurrentMode == MODE_PHONEMES )
  {
    if ( this->m_Tags.m_Words.m_Size >= 2 )
    {
      this->m_WorkFile.m_bDirty = true;
      IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
      PhonemeEditor::PushUndo(this);
      for ( i = 0; i < this->m_Tags.m_Words.m_Size - 1; ++i )
      {
        v3 = &this->m_Tags.m_Words.m_Memory.m_pMemory[i];
        v4 = *v3;
        v5 = !(*v3)->m_bSelected;
        v6 = v3[1];
        if ( !v5 && v6->m_bSelected )
          v6->m_flStartTime = v4->m_flEndTime;
      }
      this->m_bRedoPending = false;
      v7 = (CSentence *)operator new(nSize: 0x4Cu);
      if ( v7 != nullptr )
        v8 = CSentence::CSentence(this: v7);
      else
        v8 = nullptr;
      CSentence::operator=(this: v8, src: &this->m_Tags);
      this->m_UndoStack.m_Memory.m_pMemory[this->m_nUndoLevel - 1]->redo = v8;
      this->redraw(this);
    }
    else
    {
      Con_Printf(a1: (Color)this, fmt: "Can't snap, need at least two contiguous selected words\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004740F0
// Name: private: void PhonemeEditor::SeparateWords(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::SeparateWords(PhonemeEditor *this)
{
  float v2; // xmm0_4
  int v3; // ebx
  CWordTag **m_pMemory; // ecx
  CWordTag *v5; // edi
  CWordTag *v6; // eax
  char *v7; // eax
  Color v8; // ecx
  CSentence *v9; // eax
  CSentence *v10; // edi
  char *Word; // [esp-Ch] [ebp-18h]
  double time_epsilon; // [esp+4h] [ebp-8h]

  if ( this->m_CurrentMode != MODE_PHONEMES )
    return;
  v2 = (float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond;
  if ( v2 <= 0.0 )
    return;
  if ( this->m_Tags.m_Words.m_Size < 2 )
  {
    Con_Printf(a1: (Color)this, fmt: "Can't separate, need at least two contiguous selected words\n");
    return;
  }
  time_epsilon = (float)((float)(1.0 / v2) * 6.0);
  this->m_WorkFile.m_bDirty = true;
  IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
  PhonemeEditor::PushUndo(this);
  v3 = 0;
  if ( this->m_Tags.m_Words.m_Size - 1 <= 0 )
    goto LABEL_13;
  while ( 1 )
  {
    m_pMemory = this->m_Tags.m_Words.m_Memory.m_pMemory;
    v5 = m_pMemory[v3];
    v6 = m_pMemory[v3 + 1];
    if ( v5->m_bSelected && v6->m_bSelected )
    {
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v5->m_flEndTime - v6->m_flStartTime) & _mask__AbsFloat_) <= time_epsilon )
        break;
      Word = CWordTag::GetWord(this: m_pMemory[v3 + 1]);
      v7 = CWordTag::GetWord(this: v5);
      Con_Printf(a1: v8, fmt: "Can't split %s and %s, already split apart\n", v7, Word);
    }
    if ( ++v3 >= this->m_Tags.m_Words.m_Size - 1 )
      goto LABEL_13;
  }
  v6->m_flStartTime = v6->m_flStartTime + time_epsilon;
LABEL_13:
  this->m_bRedoPending = false;
  v9 = (CSentence *)operator new(nSize: 0x4Cu);
  if ( v9 != nullptr )
    v10 = CSentence::CSentence(this: v9);
  else
    v10 = nullptr;
  CSentence::operator=(this: v10, src: &this->m_Tags);
  this->m_UndoStack.m_Memory.m_pMemory[this->m_nUndoLevel - 1]->redo = v10;
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x00474270
// Name: private: void PhonemeEditor::EditWordList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::EditWordList(PhonemeEditor *this)
{
  char *Text; // eax
  char *v3; // edx
  char v4; // cl
  int v5; // eax
  char v6; // cl
  HWND Handle; // eax
  char wordstring[1024]; // [esp+4h] [ebp-990h] BYREF
  CInputParams params; // [esp+404h] [ebp-590h] BYREF

  if ( this->m_CurrentMode == MODE_PHONEMES && this->m_pWaveFile != nullptr )
  {
    Text = CSentence::GetText(this: &this->m_Tags);
    v3 = (char *)(wordstring - Text);
    do
    {
      v4 = *Text;
      Text[(_DWORD)v3] = *Text;
      ++Text;
    }
    while ( v4 != 0 );
    memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
    strcpy(params.m_szDialogTitle, "Word List");
    strcpy(params.m_szPrompt, "Sentence:");
    v5 = 0;
    do
    {
      v6 = wordstring[v5];
      params.m_szInputText[v5++] = v6;
    }
    while ( v6 != 0 );
    if ( InputProperties(&params) != 0 )
    {
      if ( strlen(params.m_szInputText) == 0 )
        _Warning(a1: "Edit word list:  No words entered!\n");
      this->m_WorkFile.m_bDirty = true;
      IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
      PhonemeEditor::PushUndo(this);
      if ( this->m_CurrentMode == MODE_PHONEMES )
      {
        this->m_nLastExtractionResult = 0;
        CSentence::Reset(this: &this->m_TagsExt);
        this->redraw(this);
      }
      CSentence::SetText(this: &this->m_Tags, text: params.m_szInputText);
      if ( this->m_Tags.m_Words.m_Size == 0 )
      {
        PhonemeEditor::CreateEvenWordDistribution(this, wordlist: params.m_szInputText);
        PhonemeEditor::RedoPhonemeExtraction(this);
      }
      PhonemeEditor::PushRedo(this);
      Handle = (HWND)mxWidget::getHandle(this);
      SetFocus(hWnd: Handle);
      this->redraw(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474400
// Name: private: void PhonemeEditor::SnapPhonemes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::SnapPhonemes(PhonemeEditor *this)
{
  int v2; // ebx
  CPhonemeTag *i; // edi
  CWordTag *v4; // ecx
  int j; // edx
  CPhonemeTag *v6; // eax
  CSentence *v7; // eax
  CSentence *v8; // edi

  if ( this->m_CurrentMode == MODE_PHONEMES )
  {
    this->m_WorkFile.m_bDirty = true;
    IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
    PhonemeEditor::PushUndo(this);
    v2 = 0;
    for ( i = nullptr; v2 < this->m_Tags.m_Words.m_Size; ++v2 )
    {
      v4 = this->m_Tags.m_Words.m_Memory.m_pMemory[v2];
      if ( v4 != nullptr )
      {
        for ( j = 0; j < v4->m_Phonemes.m_Size; ++j )
        {
          v6 = v4->m_Phonemes.m_Memory.m_pMemory[j];
          if ( v6->m_bSelected )
          {
            if ( i != nullptr )
              i->m_flEndTime = v6->m_flStartTime;
            i = v6;
          }
          else
          {
            i = nullptr;
          }
        }
      }
    }
    this->m_bRedoPending = false;
    v7 = (CSentence *)operator new(nSize: 0x4Cu);
    if ( v7 != nullptr )
      v8 = CSentence::CSentence(this: v7);
    else
      v8 = nullptr;
    CSentence::operator=(this: v8, src: &this->m_Tags);
    this->m_UndoStack.m_Memory.m_pMemory[this->m_nUndoLevel - 1]->redo = v8;
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004744D0
// Name: private: void PhonemeEditor::SeparatePhonemes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::SeparatePhonemes(PhonemeEditor *this)
{
  int v2; // eax
  Color v3; // ecx
  double v4; // xmm1_8
  CWordTag *v5; // esi
  int v6; // edi
  CPhonemeTag *v7; // eax
  float v8; // xmm2_4
  CSentence *v9; // eax
  CSentence *v10; // esi
  double time_epsilon; // [esp+4h] [ebp-10h]
  int w; // [esp+Ch] [ebp-8h]
  CPhonemeTag *prev; // [esp+10h] [ebp-4h]

  if ( this->m_CurrentMode == MODE_PHONEMES )
  {
    this->m_WorkFile.m_bDirty = true;
    IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
    PhonemeEditor::PushUndo(this);
    v2 = 0;
    v3 = 0;
    v4 = (float)((float)(1.0 / (float)((float)((float)this->m_nTimeZoom * 0.0099999998) * this->m_flPixelsPerSecond))
               * 6.0);
    time_epsilon = v4;
    prev = nullptr;
    w = 0;
    if ( this->m_Tags.m_Words.m_Size > 0 )
    {
      while ( 1 )
      {
        v5 = this->m_Tags.m_Words.m_Memory.m_pMemory[v2];
        if ( v5 != nullptr )
        {
          v6 = 0;
          if ( v5->m_Phonemes.m_Size > 0 )
            break;
        }
LABEL_14:
        w = ++v2;
        if ( v2 >= this->m_Tags.m_Words.m_Size )
          goto LABEL_15;
      }
      while ( 1 )
      {
        v7 = v5->m_Phonemes.m_Memory.m_pMemory[v6];
        if ( !v7->m_bSelected )
        {
          prev = nullptr;
          goto LABEL_12;
        }
        if ( v3 == 0 )
          goto LABEL_10;
        if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)(*(_DWORD *)&v3 + 4) - v7->m_flStartTime) & _mask__AbsFloat_) <= v4 )
          break;
        Con_Printf(a1: v3, fmt: "Can't split already split apart\n");
        v4 = time_epsilon;
LABEL_12:
        v3 = (Color)prev;
        if ( ++v6 >= v5->m_Phonemes.m_Size )
        {
          v2 = w;
          goto LABEL_14;
        }
      }
      v8 = v4;
      v7->m_flStartTime = v8 + v7->m_flStartTime;
LABEL_10:
      prev = v7;
      goto LABEL_12;
    }
LABEL_15:
    this->m_bRedoPending = false;
    v9 = (CSentence *)operator new(nSize: 0x4Cu);
    if ( v9 != nullptr )
      v10 = CSentence::CSentence(this: v9);
    else
      v10 = nullptr;
    CSentence::operator=(this: v10, src: &this->m_Tags);
    this->m_UndoStack.m_Memory.m_pMemory[this->m_nUndoLevel - 1]->redo = v10;
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474630
// Name: private: void PhonemeEditor::CommitExtracted(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::CommitExtracted(PhonemeEditor *this)
{
  bool v2; // zf

  if ( this->m_CurrentMode == MODE_PHONEMES )
  {
    v2 = this->m_TagsExt.m_Words.m_Size == 0;
    this->m_nLastExtractionResult = 0;
    if ( !v2 )
    {
      this->m_WorkFile.m_bDirty = true;
      IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
      PhonemeEditor::PushUndo(this);
      CSentence::Reset(this: &this->m_Tags);
      CSentence::operator=(this: &this->m_Tags, src: &this->m_TagsExt);
      PhonemeEditor::PushRedo(this);
      if ( this->m_CurrentMode == MODE_PHONEMES )
      {
        this->m_nLastExtractionResult = 0;
        CSentence::Reset(this: &this->m_TagsExt);
        this->redraw(this);
      }
      this->redraw(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004746D0
// Name: private: void PhonemeEditor::ITER_AddFocusRectSelectedWords(class CWordTag __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ITER_AddFocusRectSelectedWords(PhonemeEditor *this, CWordTag *word, float amount)
{
  tagRECT wordRect; // [esp+4h] [ebp-10h] BYREF

  if ( word->m_bSelected )
  {
    PhonemeEditor::GetWordRect(this, tag: word, rc: &wordRect);
    PhonemeEditor::AddFocusRect(this, rc: &wordRect);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474700
// Name: private: void PhonemeEditor::ITER_AddFocusRectSelectedPhonemes(class CPhonemeTag __near *,class CWordTag __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::ITER_AddFocusRectSelectedPhonemes(
        PhonemeEditor *this,
        CPhonemeTag *phoneme,
        CWordTag *word,
        float amount)
{
  tagRECT phonemeRect; // [esp+4h] [ebp-10h] BYREF

  if ( phoneme->m_bSelected )
  {
    PhonemeEditor::GetPhonemeRect(this, tag: phoneme, rc: &phonemeRect);
    PhonemeEditor::AddFocusRect(this, rc: &phonemeRect);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474730
// Name: private: void PhonemeEditor::EditInsertFirstPhonemeOfWord(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::EditInsertFirstPhonemeOfWord(PhonemeEditor *this)
{
  bool v2; // zf
  CWordTag *SelectedWord; // eax
  CWordTag *v4; // esi
  char *Word; // eax
  Color v6; // ecx
  HWND Handle; // eax
  int v8; // ebx
  HWND v9; // eax
  int v10; // eax
  float m_flStartTime; // xmm0_4
  char *i; // ebx
  char v13; // al
  char *j; // ecx
  CPhonemeTag *v15; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CPhonemeTag **m_pMemory; // ecx
  int v19; // eax
  CPhonemeTag **v20; // edi
  CPhonemeTag *v21; // eax
  PhonemeEditor *v22; // esi
  PhonemeEditor *v23; // ecx
  char phonemeName[128]; // [esp+4h] [ebp-244h] BYREF
  CPhonemeParams params; // [esp+84h] [ebp-1C4h] BYREF
  CPhonemeTag from; // [esp+214h] [ebp-34h] BYREF
  float timePerPhoneme; // [esp+230h] [ebp-18h]
  PhonemeEditor *v28; // [esp+234h] [ebp-14h]
  CPhonemeTag *v29; // [esp+238h] [ebp-10h]
  int currentTime; // [esp+23Ch] [ebp-Ch]
  tagPOINT pt; // [esp+240h] [ebp-8h] BYREF

  v2 = this->m_CurrentMode == MODE_PHONEMES;
  v28 = this;
  if ( v2 )
  {
    SelectedWord = PhonemeEditor::GetSelectedWord(this);
    v4 = SelectedWord;
    if ( SelectedWord != nullptr )
    {
      if ( SelectedWord->m_Phonemes.m_Size != 0 )
      {
        Word = CWordTag::GetWord(this: SelectedWord);
        Con_Printf(a1: v6, fmt: "Can't insert first phoneme into %s, already has phonemes\n", Word);
      }
      else
      {
        memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
        strcpy(params.m_szDialogTitle, "Phoneme/Viseme Properties");
        params.m_szName[0] = 0;
        params.m_nLeft = -1;
        params.m_nTop = -1;
        params.m_bPositionDialog = true;
        params.m_bMultiplePhoneme = true;
        PhonemeEditor::GetWordRect(this, tag: v4, rc: (tagRECT *)&from.m_bSelected);
        pt = *(tagPOINT *)&from.m_bSelected;
        Handle = (HWND)mxWidget::getHandle(this);
        ClientToScreen(hWnd: Handle, lpPoint: &pt);
        *(tagPOINT *)&params.m_nLeft = pt;
        v8 = PhonemeProperties(&params);
        v9 = (HWND)mxWidget::getHandle(this);
        SetFocus(hWnd: v9);
        if ( v8 != 0 )
        {
          v10 = CSentence::CountWords(str: params.m_szName);
          if ( v10 > 0 )
          {
            m_flStartTime = v4->m_flStartTime;
            timePerPhoneme = (float)(v4->m_flEndTime - v4->m_flStartTime) / (float)v10;
            *(float *)&currentTime = m_flStartTime;
            this->m_WorkFile.m_bDirty = true;
            IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
            PhonemeEditor::PushUndo(this);
            for ( i = params.m_szName; ; ++i )
            {
              v13 = *i;
              for ( j = phonemeName; (unsigned __int8)*i > 0x20u; ++j )
              {
                ++i;
                *j = v13;
                v13 = *i;
              }
              *j = 0;
              CPhonemeTag::CPhonemeTag(this: &from);
              from.m_nPhonemeCode = TextToPhoneme(text: phonemeName);
              CPhonemeTag::SetTag(this: &from, phoneme: phonemeName);
              LODWORD(from.m_flStartTime) = currentTime;
              *(float *)&pt.y = *(float *)&currentTime + timePerPhoneme;
              from.m_flEndTime = *(float *)&currentTime + timePerPhoneme;
              from.m_bSelected = false;
              v15 = (CPhonemeTag *)operator new(nSize: 0x1Cu);
              if ( v15 != nullptr )
                v29 = CPhonemeTag::CPhonemeTag(this: v15, &from);
              else
                v29 = nullptr;
              m_Size = v4->m_Phonemes.m_Size;
              m_nAllocationCount = v4->m_Phonemes.m_Memory.m_nAllocationCount;
              if ( m_Size + 1 > m_nAllocationCount )
                CUtlMemory<IFacePoserToolWindow *,int>::Grow(
                  this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v4->m_Phonemes,
                  num: m_Size - m_nAllocationCount + 1);
              ++v4->m_Phonemes.m_Size;
              m_pMemory = v4->m_Phonemes.m_Memory.m_pMemory;
              v19 = v4->m_Phonemes.m_Size - m_Size - 1;
              v4->m_Phonemes.m_pElements = m_pMemory;
              if ( v19 > 0 )
                _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v19);
              v20 = &v4->m_Phonemes.m_Memory.m_pMemory[m_Size];
              if ( v20 != nullptr )
                *v20 = v29;
              v2 = *i == 0;
              currentTime = pt.y;
              if ( v2 )
                break;
              CPhonemeTag::~CPhonemeTag(this: &from);
            }
            CPhonemeTag::~CPhonemeTag(this: &from);
            v21 = *v4->m_Phonemes.m_Memory.m_pMemory;
            v22 = v28;
            v23 = v28;
            v21->m_bSelected = true;
            PhonemeEditor::PushRedo(this: v23);
            v22->redraw(this: v22);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004749E0
// Name: private: void PhonemeEditor::Emphasis_AddSample(struct CEmphasisSample const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::Emphasis_AddSample(PhonemeEditor *this, const CEmphasisSample *sample)
{
  CSentence *v3; // ebx
  CSentence *v4; // eax

  if ( this->m_CurrentMode == MODE_EMPHASIS )
  {
    this->m_WorkFile.m_bDirty = true;
    IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
    PhonemeEditor::PushUndo(this);
    CUtlVector<CEmphasisSample,CUtlMemory<CEmphasisSample,int>>::InsertBefore(
      this: &this->m_Tags.m_EmphasisSamples,
      elem: this->m_Tags.m_EmphasisSamples.m_Size,
      src: sample);
    CSentence::Resort(this: &this->m_Tags);
    v3 = nullptr;
    this->m_bRedoPending = false;
    v4 = (CSentence *)operator new(nSize: 0x4Cu);
    if ( v4 != nullptr )
      v3 = CSentence::CSentence(this: v4);
    CSentence::operator=(this: v3, src: &this->m_Tags);
    this->m_UndoStack.m_Memory.m_pMemory[this->m_nUndoLevel - 1]->redo = v3;
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474A80
// Name: private: void PhonemeEditor::StartDragging(int,int,int,struct HICON__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::StartDragging(
        PhonemeEditor *this,
        int dragtype,
        int startx,
        int starty,
        HICON__ *cursor)
{
  HICON__ *m_hPrevCursor; // eax
  bool v7; // sf
  HWND Handle; // eax
  int bottom; // eax
  int v10; // eax
  int PixelForSample; // eax
  int v12; // [esp+4h] [ebp-40h]
  tagRECT rcScrub; // [esp+14h] [ebp-30h] BYREF
  tagRECT rc; // [esp+24h] [ebp-20h] BYREF
  tagRECT rcStart; // [esp+34h] [ebp-10h] BYREF

  this->m_nStartY = starty;
  this->m_nLastY = starty;
  m_hPrevCursor = this->m_hPrevCursor;
  this->m_nDragType = dragtype;
  this->m_nStartX = startx;
  this->m_nLastX = startx;
  if ( m_hPrevCursor != nullptr )
  {
    SetCursor(hCursor: m_hPrevCursor);
    this->m_hPrevCursor = nullptr;
  }
  this->m_hPrevCursor = SetCursor(hCursor: cursor);
  v7 = this->m_FocusRects.m_Memory.m_nGrowSize < 0;
  this->m_FocusRects.m_Size = 0;
  if ( !v7 )
  {
    if ( this->m_FocusRects.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FocusRects.m_Memory.m_pMemory);
      this->m_FocusRects.m_Memory.m_pMemory = nullptr;
    }
    this->m_FocusRects.m_Memory.m_nAllocationCount = 0;
  }
  this->m_FocusRects.m_pElements = this->m_FocusRects.m_Memory.m_pMemory;
  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &rc);
  rc.top += 60;
  rc.bottom -= 95;
  InflateRect(lprc: &rc, dx: -1, dy: -1);
  rcStart.left = startx;
  rcStart.right = startx;
  switch ( dragtype )
  {
    case 1:
      PhonemeEditor::GetPhonemeTrayTopBottom(this, rc: &rcStart);
      this->m_bWordsActive = false;
      goto LABEL_19;
    case 2:
      PhonemeEditor::GetWordTrayTopBottom(this, rc: &rcStart);
      this->m_bWordsActive = true;
      goto LABEL_19;
    case 3:
    case 5:
    case 6:
      bottom = rc.bottom;
      rcStart.top = rc.top;
      goto LABEL_18;
    case 4:
      v10 = this->m_nSelection[0];
      rcStart.top = rc.top;
      rcStart.bottom = rc.bottom;
      PixelForSample = PhonemeEditor::GetPixelForSample(this, sample: v10);
      v12 = this->m_nSelection[1];
      rcStart.left = PixelForSample;
      rcStart.right = PhonemeEditor::GetPixelForSample(this, sample: v12);
      goto LABEL_19;
    case 7:
      PhonemeEditor::TraverseWords(
        this,
        pfn: (void (__thiscall *)(char *, CWordTag *, int))PhonemeEditor::ITER_AddFocusRectSelectedWords,
        fparam: 0.0,
        fparama: 0);
      this->m_bWordsActive = true;
      goto LABEL_20;
    case 8:
      PhonemeEditor::TraversePhonemes(
        this,
        pfn: (void (__thiscall *)(char *, CPhonemeTag *, CWordTag *, int))PhonemeEditor::ITER_AddFocusRectSelectedPhonemes,
        fparam: 0.0,
        fparama: 0);
      this->m_bWordsActive = false;
      goto LABEL_20;
    case 9:
      rcStart.top = 40;
      rcStart.bottom = 60;
      rcStart.left = startx - 10;
      rcStart.right = startx + 10;
      goto LABEL_19;
    case 10:
      bottom = starty;
      rcStart.top = starty;
      goto LABEL_18;
    case 11:
      this->m_WorkFile.m_bDirty = true;
      IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
      PhonemeEditor::PushUndo(this);
      PhonemeEditor::Emphasis_MouseDrag(this, x: startx, y: starty);
      CSentence::Resort(this: &this->m_Tags);
      goto LABEL_20;
    default:
      PhonemeEditor::GetScrubHandleRect(this, a2: startx, a3: (int)this, rcHandle: &rcScrub, clipped: true);
      rcStart.top = rcScrub.top;
      rcStart.bottom = rcScrub.bottom;
      rcStart.left = (rcScrub.left + rcScrub.right) / 2;
      rcStart.right = rcStart.left;
      bottom = mxWidget::h2(this) - 38;
LABEL_18:
      rcStart.bottom = bottom;
LABEL_19:
      PhonemeEditor::AddFocusRect(this, rc: &rcStart);
LABEL_20:
      PhonemeEditor::DrawFocusRect(this, reason: "start");
      PhonemeEditor::SetDragLimit(this, dragtype: this->m_nDragType);
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474D20
// Name: private: void PhonemeEditor::EditInsertWordBefore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::EditInsertWordBefore(PhonemeEditor *this)
{
  CWordTag **m_pMemory; // ecx
  CWordTag *SelectedWord; // edi
  int m_Size; // edx
  int v5; // eax
  float v6; // xmm0_4
  int v7; // eax
  Color v8; // ecx
  HWND Handle; // eax
  INT_PTR v10; // ebx
  HWND v11; // eax
  int v12; // eax
  CWordTag *v13; // eax
  CInputParams params; // [esp+14h] [ebp-5D8h] BYREF
  CWordTag newword; // [esp+5A0h] [ebp-4Ch] BYREF
  tagRECT rcWord; // [esp+5CCh] [ebp-20h] BYREF
  int clicked; // [esp+5DCh] [ebp-10h]
  tagPOINT pt; // [esp+5E0h] [ebp-Ch] BYREF
  float gap; // [esp+5E8h] [ebp-4h] BYREF

  if ( this->m_CurrentMode == MODE_PHONEMES )
  {
    SelectedWord = PhonemeEditor::GetSelectedWord(this);
    if ( SelectedWord != nullptr )
    {
      m_Size = this->m_Tags.m_Words.m_Size;
      v5 = 0;
      if ( m_Size <= 0 )
        goto LABEL_9;
      m_pMemory = this->m_Tags.m_Words.m_Memory.m_pMemory;
      while ( *m_pMemory != SelectedWord )
      {
        ++v5;
        ++m_pMemory;
        if ( v5 >= m_Size )
        {
          v6 = 0.0;
          goto LABEL_13;
        }
      }
      if ( v5 == -1 )
      {
LABEL_9:
        v6 = 0.0;
LABEL_13:
        Con_Printf(
          a1: (Color)m_pMemory,
          fmt: "Can't insert before, gap of %.2f ms is too small\n",
          (float)(v6 * 1000.0));
        return;
      }
      v7 = v5 - 1;
      if ( v7 >= m_Size || v7 < 0 )
        goto LABEL_15;
      m_pMemory = this->m_Tags.m_Words.m_Memory.m_pMemory;
      v6 = SelectedWord->m_flStartTime - m_pMemory[v7]->m_flEndTime;
      gap = v6;
      if ( v6 < 0.02 )
        goto LABEL_13;
      if ( v6 >= 0.25 )
LABEL_15:
        gap = 0.25;
      clicked = PhonemeEditor::IndexOfWord(this, word: SelectedWord);
      if ( clicked >= 0 )
      {
        memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
        *(_DWORD *)&params.m_szDialogTitle[8] = (char *)&g_flexedverts[491].z + 3;
        *(_QWORD *)params.m_szDialogTitle = *(_QWORD *)aInsertW;
        strcpy(params.m_szPrompt, "Word:");
        params.m_szInputText[0] = 0;
        params.m_nLeft = -1;
        params.m_nTop = -1;
        params.m_bPositionDialog = true;
        PhonemeEditor::GetWordRect(this, tag: SelectedWord, rc: &rcWord);
        pt.y = rcWord.top;
        pt.x = rcWord.left;
        Handle = (HWND)mxWidget::getHandle(this);
        ClientToScreen(hWnd: Handle, lpPoint: &pt);
        *(tagPOINT *)&params.m_nLeft = pt;
        v10 = InputProperties(&params);
        v11 = (HWND)mxWidget::getHandle(this);
        SetFocus(hWnd: v11);
        if ( v10 != 0 && strlen(params.m_szInputText) != 0 )
        {
          v12 = CSentence::CountWords(str: params.m_szInputText);
          if ( v12 <= 1 )
          {
            this->m_WorkFile.m_bDirty = true;
            IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
            PhonemeEditor::PushUndo(this);
            CWordTag::CWordTag(this: &newword);
            CWordTag::SetWord(this: &newword, word: params.m_szInputText);
            newword.m_flEndTime = SelectedWord->m_flStartTime;
            newword.m_flStartTime = SelectedWord->m_flStartTime - gap;
            newword.m_bSelected = true;
            SelectedWord->m_bSelected = false;
            v13 = (CWordTag *)operator new(nSize: 0x2Cu);
            if ( v13 != nullptr )
              gap = COERCE_FLOAT(CWordTag::CWordTag(this: v13, from: &newword));
            else
              gap = 0.0;
            CUtlVector<CPhonemeTag *,CUtlMemory<CPhonemeTag *,int>>::InsertBefore(
              this: &this->m_Tags.m_Words,
              elem: clicked,
              src: (CWordTag **)&gap);
            PhonemeEditor::PushRedo(this);
            this->redraw(this);
            PhonemeEditor::EditInsertFirstPhonemeOfWord(this);
            CWordTag::~CWordTag(this: &newword);
          }
          else
          {
            Con_Printf(
              a1: (Color)params.m_szInputText,
              fmt: "Can only insert one word at a time, %s has %i words in it!\n",
              params.m_szInputText,
              v12);
          }
        }
      }
      else
      {
        Con_Printf(a1: v8, fmt: "EditInsertWordBefore:  word not in sentence!!!\n");
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474FD0
// Name: private: void PhonemeEditor::EditInsertWordAfter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PhonemeEditor::EditInsertWordAfter(PhonemeEditor *this)
{
  CWordTag **m_pMemory; // ecx
  CWordTag *SelectedWord; // ebx
  int m_Size; // edx
  int v5; // eax
  float v6; // xmm0_4
  int v7; // eax
  Color v8; // ecx
  HWND Handle; // eax
  HWND v10; // eax
  int v11; // eax
  CWordTag *v12; // eax
  int v13; // eax
  int m_nAllocationCount; // ecx
  int v15; // ebx
  CWordTag **v16; // ecx
  int v17; // eax
  CWordTag **v18; // ebx
  CInputParams params; // [esp+14h] [ebp-5D8h] BYREF
  CWordTag newword; // [esp+5A0h] [ebp-4Ch] BYREF
  tagRECT rcWord; // [esp+5CCh] [ebp-20h] BYREF
  int clicked; // [esp+5DCh] [ebp-10h]
  float gap; // [esp+5E0h] [ebp-Ch]
  tagPOINT Point; // [esp+5E4h] [ebp-8h] BYREF

  if ( this->m_CurrentMode == MODE_PHONEMES )
  {
    SelectedWord = PhonemeEditor::GetSelectedWord(this);
    if ( SelectedWord != nullptr )
    {
      m_Size = this->m_Tags.m_Words.m_Size;
      v5 = 0;
      if ( m_Size <= 0 )
        goto LABEL_9;
      m_pMemory = this->m_Tags.m_Words.m_Memory.m_pMemory;
      while ( *m_pMemory != SelectedWord )
      {
        ++v5;
        ++m_pMemory;
        if ( v5 >= m_Size )
        {
          v6 = 0.0;
          goto LABEL_13;
        }
      }
      if ( v5 == -1 )
      {
LABEL_9:
        v6 = 0.0;
LABEL_13:
        Con_Printf(a1: (Color)m_pMemory, fmt: "Can't insert after, gap of %.2f ms is too small\n", (float)(v6 * 1000.0));
        return;
      }
      v7 = v5 + 1;
      if ( v7 >= m_Size || v7 < 0 )
        goto LABEL_15;
      m_pMemory = this->m_Tags.m_Words.m_Memory.m_pMemory;
      v6 = m_pMemory[v7]->m_flStartTime - SelectedWord->m_flEndTime;
      gap = v6;
      if ( v6 < 0.02 )
        goto LABEL_13;
      if ( v6 >= 0.25 )
LABEL_15:
        gap = 0.25;
      clicked = PhonemeEditor::IndexOfWord(this, word: SelectedWord);
      if ( clicked >= 0 )
      {
        memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
        *(_DWORD *)&params.m_szDialogTitle[8] = (char *)&g_flexedverts[491].z + 3;
        strcpy(params.m_szPrompt, "Word:");
        *(_QWORD *)params.m_szDialogTitle = *(_QWORD *)aInsertW;
        params.m_szInputText[0] = 0;
        params.m_nLeft = -1;
        params.m_nTop = -1;
        params.m_bPositionDialog = true;
        PhonemeEditor::GetWordRect(this, tag: SelectedWord, rc: &rcWord);
        Point.y = rcWord.top;
        Point.x = rcWord.left;
        Handle = (HWND)mxWidget::getHandle(this);
        ClientToScreen(hWnd: Handle, lpPoint: &Point);
        *(tagPOINT *)&params.m_nLeft = Point;
        Point.y = InputProperties(&params);
        v10 = (HWND)mxWidget::getHandle(this);
        SetFocus(hWnd: v10);
        if ( Point.y != 0 && strlen(params.m_szInputText) != 0 )
        {
          v11 = CSentence::CountWords(str: params.m_szInputText);
          if ( v11 <= 1 )
          {
            this->m_WorkFile.m_bDirty = true;
            IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
            PhonemeEditor::PushUndo(this);
            CWordTag::CWordTag(this: &newword);
            CWordTag::SetWord(this: &newword, word: params.m_szInputText);
            newword.m_flEndTime = SelectedWord->m_flEndTime + gap;
            newword.m_flStartTime = SelectedWord->m_flEndTime;
            newword.m_bSelected = true;
            SelectedWord->m_bSelected = false;
            v12 = (CWordTag *)operator new(nSize: 0x2Cu);
            if ( v12 != nullptr )
            {
              Point.y = (int)CWordTag::CWordTag(this: v12, from: &newword);
              if ( Point.y != 0 )
              {
                v13 = this->m_Tags.m_Words.m_Size;
                m_nAllocationCount = this->m_Tags.m_Words.m_Memory.m_nAllocationCount;
                v15 = clicked + 1;
                if ( v13 + 1 > m_nAllocationCount )
                  CUtlMemory<IFacePoserToolWindow *,int>::Grow(
                    this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Tags.m_Words,
                    num: v13 - m_nAllocationCount + 1);
                ++this->m_Tags.m_Words.m_Size;
                v16 = this->m_Tags.m_Words.m_Memory.m_pMemory;
                v17 = this->m_Tags.m_Words.m_Size - v15 - 1;
                this->m_Tags.m_Words.m_pElements = v16;
                if ( v17 > 0 )
                  _V_memmove(dest: &v16[v15 + 1], src: &v16[v15], count: 4 * v17);
                v18 = &this->m_Tags.m_Words.m_Memory.m_pMemory[v15];
                if ( v18 != nullptr )
                  *v18 = (CWordTag *)Point.y;
              }
            }
            PhonemeEditor::PushRedo(this);
            this->redraw(this);
            PhonemeEditor::EditInsertFirstPhonemeOfWord(this);
            CWordTag::~CWordTag(this: &newword);
          }
          else
          {
            Con_Printf(
              a1: (Color)params.m_szInputText,
              fmt: "Can only insert one word at a time, %s has %i words in it!\n",
              params.m_szInputText,
              v11);
          }
        }
      }
      else
      {
        Con_Printf(a1: v8, fmt: "EditInsertWordBefore:  word not in sentence!!!\n");
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004752E0
// Name: public: virtual int PhonemeEditor::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall PhonemeEditor::handleEvent(PhonemeEditor *this, float event)
{
  IMDLCache *v2; // ebx
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  mxEvent *v5; // edi
  bool (__thiscall *HandleToolEvent)(IFacePoserToolWindow *, mxEvent *); // edx
  int result; // eax
  int action; // eax
  PhonemeEditor::EditorMode v9; // eax
  bool v10; // zf
  IFacePoserToolWindow *v11; // ecx
  HWND v12; // eax
  int modifiers; // eax
  int MinValue; // edi
  HWND v15; // eax
  HWND Handle; // eax
  PhonemeEditor_vtbl *v17; // edx
  HWND v18; // eax
  HWND v19; // eax
  HWND v20; // eax
  PhonemeEditor *v21; // ecx
  HWND v22; // eax
  int m_nTimeZoomStep; // eax
  int v24; // edi
  int v25; // eax
  CPhonemeTag *PhonemeTagUnderMouse; // eax
  int v27; // edx
  CWordTag *WordTagUnderMouse; // eax
  bool v29; // cl
  char v30; // bl
  bool IsMouseOverWordRow; // al
  bool IsMouseOverPhonemeRow; // al
  int v33; // edx
  PhonemeEditor *v34; // ecx
  HCURSOR CursorA; // eax
  int v36; // ecx
  HCURSOR v37; // ebx
  int v38; // eax
  HICON__ *m_hPrevCursor; // eax
  HWND v40; // eax
  double v41; // st7
  __m128i v42; // xmm1
  int bottom; // xmm0_4
  CEmphasisSample *SampleUnderMouse; // eax
  mxEvent *v45; // eax
  int v46; // ebx
  int v47; // edi
  HICON__ *v48; // eax
  bool v49; // sf
  HWND v50; // eax
  int v51; // ebx
  int v52; // edi
  HICON__ *v53; // eax
  HWND v54; // eax
  int v55; // ecx
  HCURSOR v56; // eax
  HCURSOR v57; // eax
  HCURSOR v58; // eax
  HCURSOR v59; // eax
  HCURSOR v60; // eax
  HCURSOR v61; // eax
  HCURSOR v62; // ebx
  int v63; // eax
  int v64; // edi
  HICON__ *v65; // eax
  HWND v66; // eax
  HCURSOR v67; // eax
  PhonemeEditor *v68; // ecx
  HCURSOR v69; // eax
  PhonemeEditor *v70; // ecx
  double TimeForPixel; // st7
  float m_flScrubberTimeOffset; // xmm0_4
  SHORT AsyncKeyState; // ax
  int key; // edi
  Color v75; // ecx
  bool v76; // al
  HWND v77; // eax
  PhonemeEditor_vtbl *v78; // edx
  HWND v79; // eax
  int i; // edi
  CWordTag *v81; // eax
  bool v82; // cc
  CWordTag *v83; // edi
  int j; // ebx
  CPhonemeTag *v85; // eax
  HWND v86; // eax
  HWND v87; // eax
  HWND v88; // eax
  HWND v89; // eax
  PhonemeEditor *v90; // ecx
  PhonemeEditor *v91; // ecx
  HWND v92; // eax
  HWND v93; // eax
  HWND v94; // eax
  HWND v95; // eax
  HWND v96; // eax
  int v97; // edi
  int v98; // edi
  int v99; // [esp+4h] [ebp-64h]
  int x_low; // [esp+4h] [ebp-64h]
  int y_low; // [esp+8h] [ebp-60h]
  int v102; // [esp+8h] [ebp-60h]
  int v103; // [esp+8h] [ebp-60h]
  tagRECT rcWork; // [esp+18h] [ebp-50h] BYREF
  tagRECT rcEmphasis; // [esp+28h] [ebp-40h] BYREF
  tagRECT Rect; // [esp+38h] [ebp-30h] BYREF
  tagRECT rc; // [esp+48h] [ebp-20h] BYREF
  CWordTag *wt; // [esp+58h] [ebp-10h] BYREF
  CPhonemeTag *pt; // [esp+5Ch] [ebp-Ch]
  int iret; // [esp+60h] [ebp-8h]
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+64h] [ebp-4h]

  v2 = g_pMDLCache;
  BeginLock = g_pMDLCache->BeginLock;
  cacheCriticalSection.m_pCache = g_pMDLCache;
  BeginLock(this: g_pMDLCache);
  v5 = (mxEvent *)LODWORD(event);
  HandleToolEvent = this->HandleToolEvent;
  iret = 0;
  if ( HandleToolEvent(this: &this->IFacePoserToolWindow, a2: (mxEvent *)LODWORD(event)) )
  {
    v2->EndLock(this: v2);
    return 0;
  }
  switch ( v5->event )
  {
    case 0:
      action = v5->action;
      iret = 1;
      if ( action > 5038 )
      {
        if ( action == 5039 )
          PhonemeEditor::Redo(this);
      }
      else if ( action == 5038 )
      {
        PhonemeEditor::Undo(this);
      }
      else
      {
        switch ( action )
        {
          case 1001:
            modifiers = v5->modifiers;
            switch ( modifiers )
            {
              case 5:
                PhonemeEditor::MoveTimeSliderToPos(this, x: v5->height);
                goto LABEL_76;
              case 2:
                MinValue = mxScrollbar::getValue(this: this->m_pHorzScrollBar) - 10;
                if ( MinValue <= mxScrollbar::getMinValue(this: this->m_pHorzScrollBar) )
                  MinValue = mxScrollbar::getMinValue(this: this->m_pHorzScrollBar);
LABEL_47:
                PhonemeEditor::MoveTimeSliderToPos(this, x: MinValue);
                goto LABEL_76;
              case 3:
                MinValue = mxScrollbar::getValue(this: this->m_pHorzScrollBar) + 10;
                if ( MinValue >= mxScrollbar::getMaxValue(this: this->m_pHorzScrollBar) )
                  MinValue = mxScrollbar::getMaxValue(this: this->m_pHorzScrollBar);
                goto LABEL_47;
              default:
                break;
            }
            break;
          case 1002:
            PhonemeEditor::StopPlayback(this);
            if ( this->m_pWaveFile != nullptr )
            {
              FacePoser_EnsurePhonemesLoaded();
              ((void (__stdcall *)(CAudioSource *, int, CAudioMixer **))sound->PlaySound)(
                a1: this->m_pWaveFile,
                a2: 1065353216,
                a3: &this->m_pMixer);
            }
            break;
          case 1004:
            PhonemeEditor::EditPhoneme(this);
            break;
          case 1005:
            PhonemeEditor::EditInsertPhonemeBefore(this);
            break;
          case 1006:
            PhonemeEditor::EditInsertPhonemeAfter(this);
            break;
          case 1007:
            PhonemeEditor::EditDeletePhoneme(this);
            break;
          case 1008:
            PhonemeEditor::PlayEditedWave(this, selection: true);
            goto LABEL_54;
          case 1009:
            if ( this->m_Tags.m_Words.m_Size > 0 )
              PhonemeEditor::RedoPhonemeExtraction(this);
            else
              PhonemeEditor::EditWordList(this);
            goto LABEL_54;
          case 1010:
            PhonemeEditor::RedoPhonemeExtractionSelected(this, a2: (const char *)v5, a3: (int)this);
            Handle = (HWND)mxWidget::getHandle(this);
            SetFocus(hWnd: Handle);
            break;
          case 1011:
            v17 = this->mxWindow::mxWidget::__vftable;
            this->m_nSelection[1] = 0;
            this->m_nSelection[0] = 0;
            this->m_bSelectionActive = false;
            v17->redraw(this);
            break;
          case 1012:
            PhonemeEditor::PlayEditedWave(this, selection: false);
LABEL_54:
            v15 = (HWND)mxWidget::getHandle(this);
            SetFocus(hWnd: v15);
            break;
          case 1013:
            PhonemeEditor::CommitChanges(this);
            v18 = (HWND)mxWidget::getHandle(this);
            SetFocus(hWnd: v18);
            break;
          case 1014:
            PhonemeEditor::StopPlayback(this);
            v20 = (HWND)mxWidget::getHandle(this);
            SetFocus(hWnd: v20);
            break;
          case 1015:
            PhonemeEditor::EditWordList(this);
            break;
          case 1016:
            PhonemeEditor::SnapWords(this);
            break;
          case 1017:
            PhonemeEditor::SeparateWords(this);
            break;
          case 1018:
            PhonemeEditor::LoadWaveFile(this);
            v19 = (HWND)mxWidget::getHandle(this);
            SetFocus(hWnd: v19);
            break;
          case 1019:
            PhonemeEditor::SnapPhonemes(this);
            break;
          case 1020:
            PhonemeEditor::SeparatePhonemes(this);
            break;
          case 1021:
            PhonemeEditor::CommitExtracted(this);
            v12 = (HWND)mxWidget::getHandle(this);
            SetFocus(hWnd: v12);
            break;
          case 1022:
            PhonemeEditor::ClearExtracted(this);
            break;
          case 1023:
            PhonemeEditor::AddTag(this);
            break;
          case 1024:
            PhonemeEditor::DeleteTag(this);
            break;
          case 1027:
            PhonemeEditor::EditDeleteWord(this);
            break;
          case 1028:
            PhonemeEditor::EditWord(this);
            break;
          case 1029:
            PhonemeEditor::EditInsertWordBefore(this);
            break;
          case 1030:
            PhonemeEditor::EditInsertWordAfter(this);
            break;
          case 1031:
            PhonemeEditor::EditInsertFirstPhonemeOfWord(this);
            break;
          case 1032:
            PhonemeEditor::SelectWords(this, forward: true);
            break;
          case 1033:
            PhonemeEditor::SelectWords(this, forward: false);
            break;
          case 1034:
            PhonemeEditor::SelectPhonemes(this, forward: true);
            break;
          case 1035:
            PhonemeEditor::SelectPhonemes(this, forward: false);
            break;
          case 1036:
            PhonemeEditor::DeselectPhonemes(this);
            PhonemeEditor::DeselectWords(this: v21);
            ((void (*)(void))this->redraw)();
            break;
          case 1037:
            PhonemeEditor::CleanupWordsAndPhonemes(this, prepareundo: true);
            this->redraw(this);
            break;
          case 1038:
            PhonemeEditor::ClearUndo(this);
            break;
          case 1039:
            PhonemeEditor::Play(this);
            break;
          case 1040:
            v9 = this->m_pModeTab->getSelectedIndex(this: this->m_pModeTab);
            v10 = this->m_CurrentMode == v9;
            this->m_CurrentMode = v9;
            if ( !v10 )
            {
              v11 = &this->IFacePoserToolWindow;
              if ( v9 == MODE_EMPHASIS )
                IFacePoserToolWindow::SetSuffix(this: v11, suffix: " - Emphasis Track");
              else
                IFacePoserToolWindow::SetSuffix(this: v11, suffix: " - Normal");
              this->redraw(this);
            }
            break;
          case 1041:
            PhonemeEditor::Emphasis_Delete(this);
            break;
          case 1042:
            PhonemeEditor::Emphasis_DeselectAll(this);
            break;
          case 1043:
            PhonemeEditor::Emphasis_SelectAll(this);
            break;
          case 1044:
            this->m_flPlaybackRate = mxSlider::getValue(this: this->m_pPlaybackRate);
            this->redraw(this);
            break;
          case 1045:
            PhonemeEditor::RealignPhonemesToWords(this, prepareundo: true);
            this->redraw(this);
            break;
          case 1046:
            PhonemeEditor::RealignWordsToPhonemes(this, prepareundo: true);
            this->redraw(this);
            break;
          case 1050:
            PhonemeEditor::OnSAPI(this);
            break;
          case 1051:
            PhonemeEditor::OnLipSinc(this);
            break;
          case 1075:
            PhonemeEditor::OnExport(this);
            break;
          case 1076:
            PhonemeEditor::OnImport(this);
            break;
          case 1077:
            PhonemeEditor::OnToggleVoiceDuck(this);
            break;
          default:
            break;
        }
      }
LABEL_76:
      IFacePoserToolWindow::SetActiveTool(tool: &this->IFacePoserToolWindow);
      v22 = (HWND)mxWidget::getHandle(this);
      SetFocus(hWnd: v22);
      goto LABEL_85;
    case 1:
      v24 = mxWidget::h2(this) - 38;
      v99 = mxWidget::w2(this);
      v25 = mxWidget::h2(this);
      mxWidget::setBounds(this: this->m_pModeTab, x: 0, y: v25 - 20, w: v99, h: 20);
      mxWidget::setBounds(this: this->m_btnRedoPhonemeExtraction, x: 5, y: v24, w: 100, h: 16);
      mxWidget::setBounds(this: this->m_btnSave, x: 105, y: v24, w: 100, h: 16);
      mxWidget::setBounds(this: this->m_btnLoad, x: 205, y: v24, w: 100, h: 16);
      mxWidget::setBounds(this: this->m_btnPlay, x: 305, y: v24, w: 100, h: 16);
      mxWidget::setBounds(this: this->m_pPlaybackRate, x: 405, y: v24, w: 100, h: 16);
      goto LABEL_83;
    case 6:
      if ( this->m_nDragType != 0 )
      {
        LODWORD(event) = SLOWORD(v5->x);
        PhonemeEditor::LimitDrag(this, mousex: (int *)&event);
        v5->x = SLOWORD(event);
        PhonemeEditor::DrawFocusRect(this, reason: "finish");
        if ( this->m_hPrevCursor != nullptr )
        {
          SetCursor(hCursor: this->m_hPrevCursor);
          this->m_hPrevCursor = nullptr;
        }
        switch ( this->m_nDragType )
        {
          case 1:
            PhonemeEditor::FinishPhonemeMove(this, startx: this->m_nStartX, endx: SLOWORD(v5->x));
            this->m_nDragType = 0;
            break;
          case 2:
            PhonemeEditor::FinishWordMove(this, startx: this->m_nStartX, endx: SLOWORD(v5->x));
            this->m_nDragType = 0;
            break;
          case 3:
            PhonemeEditor::FinishSelect(this, startx: this->m_nStartX, mx: SLOWORD(v5->x));
            this->m_nDragType = 0;
            break;
          case 4:
            PhonemeEditor::FinishMoveSelection(this, startx: this->m_nStartX, mx: SLOWORD(v5->x));
            this->m_nDragType = 0;
            break;
          case 5:
            PhonemeEditor::FinishMoveSelectionStart(this, startx: this->m_nStartX, mx: SLOWORD(v5->x));
            this->m_nDragType = 0;
            break;
          case 6:
            PhonemeEditor::FinishMoveSelectionEnd(this, startx: this->m_nStartX, mx: SLOWORD(v5->x));
            this->m_nDragType = 0;
            break;
          case 7:
            PhonemeEditor::FinishWordDrag(this, startx: this->m_nStartX, endx: SLOWORD(v5->x));
            this->m_nDragType = 0;
            break;
          case 8:
            PhonemeEditor::FinishPhonemeDrag(this, startx: this->m_nStartX, endx: SLOWORD(v5->x));
            this->m_nDragType = 0;
            break;
          case 9:
            PhonemeEditor::FinishEventTagDrag(this, startx: this->m_nStartX, endx: SLOWORD(v5->x));
            this->m_nDragType = 0;
            break;
          case 0xA:
            PhonemeEditor::Emphasis_SelectPoints(this);
            this->redraw(this);
            this->m_nDragType = 0;
            break;
          case 0xB:
            PhonemeEditor::Emphasis_MouseDrag(this, x: SLOWORD(v5->x), y: SLOWORD(v5->y));
            CSentence::Resort(this: &this->m_Tags);
            PhonemeEditor::PushRedo(this);
            this->redraw(this);
            this->m_nDragType = 0;
            break;
          case 0xC:
            TimeForPixel = PhonemeEditor::GetTimeForPixel(this, mx: SLOWORD(v5->x));
            m_flScrubberTimeOffset = this->m_flScrubberTimeOffset;
            event = TimeForPixel;
            event = m_flScrubberTimeOffset + event;
            this->m_flScrubberTimeOffset = 0.0;
            PhonemeEditor::ClampTimeToSelectionInterval(this, timeval: &event);
            this->m_flScrub = event;
            PhonemeEditor::ClampTimeToSelectionInterval(this, timeval: &this->m_flScrub);
            this->m_flScrubTarget = event;
            PhonemeEditor::ClampTimeToSelectionInterval(this, timeval: &this->m_flScrubTarget);
            sound->Flush(this: sound);
            PhonemeEditor::DrawScrubHandle(this, a2: (int)v5);
            goto LABEL_190;
          default:
LABEL_190:
            this->m_nDragType = 0;
            break;
        }
      }
      goto LABEL_84;
    case 7:
      y_low = SLOWORD(v5->y);
      x_low = SLOWORD(v5->x);
      iret = 1;
      PhonemeTagUnderMouse = (CPhonemeTag *)PhonemeEditor::GetPhonemeTagUnderMouse(this, mx: x_low, my: y_low);
      v27 = SLOWORD(v5->y);
      pt = PhonemeTagUnderMouse;
      WordTagUnderMouse = PhonemeEditor::GetWordTagUnderMouse(this, mx: SLOWORD(v5->x), my: v27);
      v29 = (v5->modifiers & 2) != 0;
      v30 = v5->modifiers & 1;
      v10 = (v5->buttons & 2) == 0;
      wt = WordTagUnderMouse;
      HIBYTE(event) = v29;
      if ( !v10 )
      {
        PhonemeEditor::GetWorkspaceRect(this, rc: &rcWork);
        IsMouseOverWordRow = PhonemeEditor::IsMouseOverWordRow(this, my: SLOWORD(v5->y));
        v102 = SLOWORD(v5->y);
        if ( IsMouseOverWordRow )
        {
          PhonemeEditor::ShowWordMenu(this, word: wt, mx: SLOWORD(v5->x), my: v102);
          cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
          return 1;
        }
        else
        {
          IsMouseOverPhonemeRow = PhonemeEditor::IsMouseOverPhonemeRow(this, my: v102);
          v103 = SLOWORD(v5->y);
          if ( IsMouseOverPhonemeRow )
          {
            PhonemeEditor::ShowPhonemeMenu(this, pho: pt, mx: SLOWORD(v5->x), my: v103);
            cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
            return 1;
          }
          else if ( PhonemeEditor::IsMouseOverTagRow(this, my: v103) )
          {
            PhonemeEditor::ShowTagMenu(this: v34, mx: (CEventRelativeTag *)SLOWORD(v5->x), my: v33);
            cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
            return 1;
          }
          else
          {
            if ( PhonemeEditor::IsMouseOverScrubArea(this: v34, event: v5) )
            {
              event = PhonemeEditor::GetTimeForPixel(this, mx: SLOWORD(v5->x));
              PhonemeEditor::ClampTimeToSelectionInterval(this, timeval: &event);
              this->m_flScrub = event;
              PhonemeEditor::ClampTimeToSelectionInterval(this, timeval: &this->m_flScrub);
              this->m_flScrubTarget = event;
              PhonemeEditor::ClampTimeToSelectionInterval(this, timeval: &this->m_flScrubTarget);
              this->redraw(this);
            }
            else
            {
              PhonemeEditor::ShowContextMenu(this, mx: SLOWORD(v5->x), my: SLOWORD(v5->y));
            }
            cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
            return 1;
          }
        }
      }
      if ( this->m_nDragType != 0 )
        goto LABEL_85;
      PhonemeEditor::CountSelected(this);
      rc.bottom = PhonemeEditor::IsMouseOverBoundary(this, event: v5);
      if ( PhonemeEditor::IsMouseOverScrubArea(this, event: v5) )
      {
        if ( PhonemeEditor::IsMouseOverScrubHandle(this, a2: (int)v5, a3: (int)this, event: v5) )
        {
          CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
          v36 = SLOWORD(v5->x);
          v37 = CursorA;
          v38 = SLOWORD(v5->y);
          this->m_nStartY = v38;
          this->m_nLastY = v38;
          m_hPrevCursor = this->m_hPrevCursor;
          this->m_nDragType = 12;
          this->m_nStartX = v36;
          this->m_nLastX = v36;
          if ( m_hPrevCursor != nullptr )
          {
            SetCursor(hCursor: m_hPrevCursor);
            this->m_hPrevCursor = nullptr;
          }
          this->m_hPrevCursor = SetCursor(hCursor: v37);
          this->m_FocusRects.m_Size = 0;
          if ( this->m_FocusRects.m_Memory.m_nGrowSize >= 0 )
          {
            if ( this->m_FocusRects.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FocusRects.m_Memory.m_pMemory);
              this->m_FocusRects.m_Memory.m_pMemory = nullptr;
            }
            this->m_FocusRects.m_Memory.m_nAllocationCount = 0;
          }
          this->m_FocusRects.m_pElements = this->m_FocusRects.m_Memory.m_pMemory;
          v40 = (HWND)mxWidget::getHandle(this);
          GetClientRect(hWnd: v40, lpRect: &Rect);
          Rect.top += 60;
          Rect.bottom -= 95;
          InflateRect(lprc: &Rect, dx: -1, dy: -1);
          PhonemeEditor::GetScrubHandleRect(this, a2: (int)v5, a3: (int)this, rcHandle: &rcEmphasis, clipped: true);
          rc.top = rcEmphasis.top;
          rc.bottom = rcEmphasis.bottom;
          rc.left = (rcEmphasis.left + rcEmphasis.right) / 2;
          rc.right = rc.left;
          rc.bottom = mxWidget::h2(this) - 38;
          PhonemeEditor::AddFocusRect(this, &rc);
          PhonemeEditor::DrawFocusRect(this, reason: "start");
          PhonemeEditor::SetDragLimit(this, dragtype: this->m_nDragType);
          v41 = PhonemeEditor::GetTimeForPixel(this, mx: SLOWORD(v5->x));
          v42 = _mm_cvtsi32_si128(this->m_nTimeZoom);
          event = v41;
          *(float *)v42.m128i_i32 = (float)(_mm_cvtepi32_ps(v42).m128_f32[0] * 0.0099999998) * this->m_flPixelsPerSecond;
          this->m_flScrubberTimeOffset = this->m_flScrub - v41;
          *(float *)&rc.bottom = 20.0 / *(float *)v42.m128i_i32;
          wt = (CWordTag *)(COERCE_UNSIGNED_INT(20.0 / *(float *)v42.m128i_i32) ^ _mask__NegFloat_);
          *(float *)&rc.bottom = clamp<float,float,float>(
                                   val: &this->m_flScrubberTimeOffset,
                                   minVal: (const float *)&wt,
                                   maxVal: (const float *)&rc.bottom);
          bottom = rc.bottom;
          this->m_flScrubberTimeOffset = *(float *)&rc.bottom;
          event = *(float *)&bottom + event;
          PhonemeEditor::ClampTimeToSelectionInterval(this, timeval: &event);
          this->m_flScrub = event;
          PhonemeEditor::ClampTimeToSelectionInterval(this, timeval: &this->m_flScrub);
          this->m_flScrubTarget = event;
          PhonemeEditor::ClampTimeToSelectionInterval(this, timeval: &this->m_flScrubTarget);
          PhonemeEditor::DrawScrubHandle(this, a2: (int)&this->m_flScrub);
          cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
          return 1;
        }
        else
        {
          event = PhonemeEditor::GetTimeForPixel(this, mx: SLOWORD(v5->x));
          PhonemeEditor::ClampTimeToSelectionInterval(this, timeval: &event);
          this->m_flScrubTarget = event;
          PhonemeEditor::ClampTimeToSelectionInterval(this, timeval: &this->m_flScrubTarget);
          cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
          return 1;
        }
      }
      if ( this->m_CurrentMode == MODE_EMPHASIS )
      {
        SampleUnderMouse = PhonemeEditor::Emphasis_GetSampleUnderMouse(this, event: v5);
        if ( SampleUnderMouse != nullptr )
        {
          if ( HIBYTE(event) != 0 )
          {
            SampleUnderMouse->selected = !SampleUnderMouse->selected;
            this->redraw(this);
            cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
            return 1;
          }
          if ( SampleUnderMouse->selected )
          {
            v45 = (mxEvent *)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F86);
            v46 = SLOWORD(v5->y);
            v47 = SLOWORD(v5->x);
            event = *(float *)&v45;
            v48 = this->m_hPrevCursor;
            this->m_nDragType = 11;
            this->m_nStartX = v47;
            this->m_nLastX = v47;
            this->m_nStartY = v46;
            this->m_nLastY = v46;
            if ( v48 != nullptr )
            {
              SetCursor(hCursor: v48);
              this->m_hPrevCursor = nullptr;
            }
            this->m_hPrevCursor = SetCursor(hCursor: (HCURSOR)LODWORD(event));
            v49 = this->m_FocusRects.m_Memory.m_nGrowSize < 0;
            this->m_FocusRects.m_Size = 0;
            if ( !v49 )
            {
              if ( this->m_FocusRects.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FocusRects.m_Memory.m_pMemory);
                this->m_FocusRects.m_Memory.m_pMemory = nullptr;
              }
              this->m_FocusRects.m_Memory.m_nAllocationCount = 0;
            }
            this->m_FocusRects.m_pElements = this->m_FocusRects.m_Memory.m_pMemory;
            v50 = (HWND)mxWidget::getHandle(this);
            GetClientRect(hWnd: v50, lpRect: &Rect);
            Rect.top += 60;
            Rect.bottom -= 95;
            InflateRect(lprc: &Rect, dx: -1, dy: -1);
            this->m_WorkFile.m_bDirty = true;
            IFacePoserToolWindow::SetPrefix(this: &this->IFacePoserToolWindow, prefix: "* ");
            PhonemeEditor::PushUndo(this);
            PhonemeEditor::Emphasis_MouseDrag(this, x: v47, y: v46);
            CSentence::Resort(this: &this->m_Tags);
            PhonemeEditor::DrawFocusRect(this, reason: "start");
            PhonemeEditor::SetDragLimit(this, dragtype: this->m_nDragType);
            goto LABEL_129;
          }
        }
        else
        {
          if ( v30 != 0 )
          {
            event = PhonemeEditor::GetTimeForPixel(this, mx: SLOWORD(v5->x));
            PhonemeEditor::GetWorkspaceRect(this, rc: &rcWork);
            PhonemeEditor::Emphasis_GetRect(this, rcWorkSpace: &rcWork, &rcEmphasis);
            v55 = SLOWORD(v5->y);
            *(float *)&Rect.top = event;
            *(float *)&Rect.right = (float)(v55 - rcEmphasis.top) / (float)(rcEmphasis.bottom - rcEmphasis.top);
            event = 1.0;
            rc.bottom = 0;
            *(float *)&Rect.right = 1.0
                                  - clamp<float,float,float>(
                                      val: (const float *)&Rect.right,
                                      minVal: (const float *)&rc.bottom,
                                      maxVal: &event);
            LOBYTE(Rect.bottom) = 0;
            PhonemeEditor::Emphasis_AddSample(this, sample: (const CEmphasisSample *)&Rect.top);
            this->redraw(this);
            cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
            return 1;
          }
          if ( HIBYTE(event) != 0 )
            goto LABEL_122;
        }
        PhonemeEditor::Emphasis_DeselectAll(this);
        this->redraw(this);
LABEL_122:
        v51 = SLOWORD(v5->y);
        v52 = SLOWORD(v5->x);
        v53 = this->m_hPrevCursor;
        this->m_nLastY = v51;
        this->m_nStartY = v51;
        this->m_nLastX = v52;
        this->m_nStartX = v52;
        this->m_nDragType = 10;
        if ( v53 != nullptr )
        {
          SetCursor(hCursor: v53);
          this->m_hPrevCursor = nullptr;
        }
        this->m_hPrevCursor = SetCursor(hCursor: nullptr);
        v49 = this->m_FocusRects.m_Memory.m_nGrowSize < 0;
        this->m_FocusRects.m_Size = 0;
        if ( !v49 )
        {
          if ( this->m_FocusRects.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FocusRects.m_Memory.m_pMemory);
            this->m_FocusRects.m_Memory.m_pMemory = nullptr;
          }
          this->m_FocusRects.m_Memory.m_nAllocationCount = 0;
        }
        this->m_FocusRects.m_pElements = this->m_FocusRects.m_Memory.m_pMemory;
        v54 = (HWND)mxWidget::getHandle(this);
        GetClientRect(hWnd: v54, lpRect: &Rect);
        Rect.top += 60;
        Rect.bottom -= 95;
        InflateRect(lprc: &Rect, dx: -1, dy: -1);
        rcEmphasis.left = v52;
        rcEmphasis.right = v52;
        rcEmphasis.top = v51;
        rcEmphasis.bottom = v51;
        PhonemeEditor::AddFocusRect(this, rc: &rcEmphasis);
        PhonemeEditor::DrawFocusRect(this, reason: "start");
        PhonemeEditor::SetDragLimit(this, dragtype: this->m_nDragType);
        goto LABEL_129;
      }
      if ( rc.bottom == 1 )
      {
        if ( this->m_nSelectedPhonemeCount <= 1 )
        {
          v56 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
          PhonemeEditor::StartDragging(this, dragtype: 1, startx: SLOWORD(v5->x), starty: SLOWORD(v5->y), cursor: v56);
          cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
          return 1;
        }
      }
      else if ( rc.bottom == 2 && this->m_nSelectedWordCount <= 1 )
      {
        v57 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
        PhonemeEditor::StartDragging(this, dragtype: 2, startx: SLOWORD(v5->x), starty: SLOWORD(v5->y), cursor: v57);
LABEL_129:
        cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
        return 1;
      }
      if ( PhonemeEditor::IsMouseOverSamples(this, mx: SLOWORD(v5->x), my: SLOWORD(v5->y)) )
      {
        if ( this->m_bSelectionActive )
        {
          if ( PhonemeEditor::IsMouseOverSelection(this, mx: SLOWORD(v5->x), my: SLOWORD(v5->y)) != 0 )
          {
            if ( PhonemeEditor::IsMouseOverSelectionStartEdge(this, event: v5) )
            {
              v59 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
              PhonemeEditor::StartDragging(
                this,
                dragtype: 5,
                startx: SLOWORD(v5->x),
                starty: SLOWORD(v5->y),
                cursor: v59);
            }
            else if ( PhonemeEditor::IsMouseOverSelectionEndEdge(this, event: v5) )
            {
              v60 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
              PhonemeEditor::StartDragging(
                this,
                dragtype: 6,
                startx: SLOWORD(v5->x),
                starty: SLOWORD(v5->y),
                cursor: v60);
            }
            else if ( HIBYTE(event) != 0 )
            {
              v61 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F86);
              PhonemeEditor::StartDragging(
                this,
                dragtype: 4,
                startx: SLOWORD(v5->x),
                starty: SLOWORD(v5->y),
                cursor: v61);
            }
          }
          else
          {
            this->m_nSelection[1] = 0;
            this->m_nSelection[0] = 0;
            this->m_bSelectionActive = false;
            this->redraw(this);
          }
        }
        else
        {
          v58 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
          PhonemeEditor::StartDragging(this, dragtype: 3, startx: SLOWORD(v5->x), starty: SLOWORD(v5->y), cursor: v58);
        }
        goto LABEL_129;
      }
      if ( !PhonemeEditor::IsMouseOverTag(this, mx: SLOWORD(v5->x), my: SLOWORD(v5->y)) )
      {
        if ( pt != nullptr )
        {
          if ( HIBYTE(event) != 0 )
          {
            pt->m_bSelected = true;
            v67 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F86);
            PhonemeEditor::StartDragging(this, dragtype: 8, startx: SLOWORD(v5->x), starty: SLOWORD(v5->y), cursor: v67);
          }
          else
          {
            pt->m_bSelected = !pt->m_bSelected;
          }
          this->m_bWordsActive = false;
        }
        else
        {
          if ( wt == nullptr )
          {
            if ( rc.bottom != 0 )
            {
LABEL_85:
              cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
              return iret;
            }
            PhonemeEditor::DeselectPhonemes(this);
            PhonemeEditor::DeselectWords(this: v70);
            goto LABEL_165;
          }
          if ( HIBYTE(event) != 0 )
          {
            wt->m_bSelected = true;
            v69 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F86);
            PhonemeEditor::StartDragging(this, dragtype: 7, startx: SLOWORD(v5->x), starty: SLOWORD(v5->y), cursor: v69);
          }
          else
          {
            wt->m_bSelected = !wt->m_bSelected;
          }
          this->m_bWordsActive = true;
        }
        v68 = this;
LABEL_165:
        ((void (__fastcall *)(PhonemeEditor *))this->redraw)(a1: v68);
        cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
        return 1;
      }
      v62 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F86);
      v63 = SLOWORD(v5->y);
      v64 = SLOWORD(v5->x);
      this->m_nStartY = v63;
      this->m_nLastY = v63;
      v65 = this->m_hPrevCursor;
      this->m_nDragType = 9;
      this->m_nStartX = v64;
      this->m_nLastX = v64;
      if ( v65 != nullptr )
      {
        SetCursor(hCursor: v65);
        this->m_hPrevCursor = nullptr;
      }
      this->m_hPrevCursor = SetCursor(hCursor: v62);
      this->m_FocusRects.m_Size = 0;
      if ( this->m_FocusRects.m_Memory.m_nGrowSize >= 0 )
      {
        if ( this->m_FocusRects.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FocusRects.m_Memory.m_pMemory);
          this->m_FocusRects.m_Memory.m_pMemory = nullptr;
        }
        this->m_FocusRects.m_Memory.m_nAllocationCount = 0;
      }
      this->m_FocusRects.m_pElements = this->m_FocusRects.m_Memory.m_pMemory;
      v66 = (HWND)mxWidget::getHandle(this);
      GetClientRect(hWnd: v66, lpRect: &Rect);
      Rect.bottom -= 95;
      Rect.top += 60;
      InflateRect(lprc: &Rect, dx: -1, dy: -1);
      rcEmphasis.left = v64 - 10;
      rcEmphasis.top = 40;
      rcEmphasis.bottom = 60;
      rcEmphasis.right = v64 + 10;
      PhonemeEditor::AddFocusRect(this, rc: &rcEmphasis);
      PhonemeEditor::DrawFocusRect(this, reason: "start");
      PhonemeEditor::SetDragLimit(this, dragtype: this->m_nDragType);
      cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
      return 1;
    case 8:
    case 9:
      PhonemeEditor::OnMouseMove(this, event: *(float *)&v5);
      goto LABEL_84;
    case 0xA:
      HIBYTE(event) = GetAsyncKeyState(vKey: 16) != 0;
      AsyncKeyState = GetAsyncKeyState(vKey: 17);
      key = v5->key;
      v75 = (Color)(key - 9);
      v76 = AsyncKeyState != 0;
      switch ( key )
      {
        case 9:
          PhonemeEditor::SelectNextWord(this, direction: 2 * (HIBYTE(event) == 0) - 1);
          v77 = (HWND)mxWidget::getHandle(this);
          SetFocus(hWnd: v77);
          goto LABEL_84;
        case 13:
        case 38:
          if ( this->m_bWordsActive )
          {
            if ( key == 38 || v76 )
            {
              PhonemeEditor::CountSelected(this);
              if ( this->m_nSelectedWordCount == 1 )
              {
                for ( i = 0; i < this->m_Tags.m_Words.m_Size; ++i )
                {
                  v81 = this->m_Tags.m_Words.m_Memory.m_pMemory[i];
                  if ( v81 != nullptr && v81->m_bSelected )
                    PhonemeEditor::EditWord(this, pWord: v81, positionDialog: true);
                }
              }
            }
          }
          else if ( key == 38 || v76 )
          {
            PhonemeEditor::CountSelected(this);
            if ( this->m_nSelectedPhonemeCount == 1 )
            {
              v82 = this->m_Tags.m_Words.m_Size <= 0;
              event = 0.0;
              if ( !v82 )
              {
                do
                {
                  v83 = this->m_Tags.m_Words.m_Memory.m_pMemory[LODWORD(event)];
                  if ( v83 != nullptr )
                  {
                    for ( j = 0; j < v83->m_Phonemes.m_Size; ++j )
                    {
                      v85 = v83->m_Phonemes.m_Memory.m_pMemory[j];
                      if ( v85 != nullptr && v85->m_bSelected )
                        PhonemeEditor::EditPhoneme(this, pPhoneme: v85, positionDialog: true);
                    }
                  }
                  ++LODWORD(event);
                }
                while ( SLODWORD(event) < this->m_Tags.m_Words.m_Size );
              }
            }
          }
          goto LABEL_227;
        case 16:
        case 17:
          GetCursorPos(lpPoint: (LPPOINT)&rc.right);
          SetCursorPos(X: rc.right, Y: rc.bottom);
          cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
          return 0;
        case 27:
          if ( PhonemeEditor::StopPlayback(this) != 0 )
            goto LABEL_227;
          this->m_nSelection[1] = 0;
          this->m_nSelection[0] = 0;
          this->m_bSelectionActive = false;
          PhonemeEditor::DeselectPhonemes(this);
          PhonemeEditor::DeselectWords(this: v90);
          PhonemeEditor::Emphasis_DeselectAll(this: v91);
          this->redraw(this);
          v92 = (HWND)mxWidget::getHandle(this);
          SetFocus(hWnd: v92);
          break;
        case 32:
          if ( this->m_pWaveFile != nullptr && sound->IsSoundPlaying(this: sound, a2: this->m_pMixer) )
          {
            Con_Printf(a1: v75, fmt: "Stopping playback\n");
            mxWidget::setLabel(this: this->m_btnPlay, format: "Play (Spacebar)");
            PhonemeEditor::StopPlayback(this);
            v88 = (HWND)mxWidget::getHandle(this);
            SetFocus(hWnd: v88);
          }
          else
          {
            Con_Printf(a1: v75, fmt: "Playing .wav\n");
            mxWidget::setLabel(this: this->m_btnPlay, format: "Stop[ (Spacebar)");
            PhonemeEditor::PlayEditedWave(this, selection: this->m_bSelectionActive);
            v89 = (HWND)mxWidget::getHandle(this);
            SetFocus(hWnd: v89);
          }
          goto LABEL_84;
        case 33:
        case 34:
          v78 = this->mxWindow::mxWidget::__vftable;
          this->m_bWordsActive = key == 33;
          v78->redraw(this);
          v79 = (HWND)mxWidget::getHandle(this);
          SetFocus(hWnd: v79);
          goto LABEL_84;
        case 45:
          if ( this->m_bWordsActive )
          {
            if ( HIBYTE(event) != 0 )
              PhonemeEditor::EditInsertWordBefore(this);
            else
              PhonemeEditor::EditInsertWordAfter(this);
          }
          else if ( HIBYTE(event) != 0 )
          {
            PhonemeEditor::EditInsertPhonemeBefore(this);
          }
          else
          {
            PhonemeEditor::EditInsertPhonemeAfter(this);
          }
          goto LABEL_227;
        case 46:
          if ( this->m_CurrentMode == MODE_EMPHASIS )
          {
            PhonemeEditor::Emphasis_Delete(this);
            v86 = (HWND)mxWidget::getHandle(this);
            SetFocus(hWnd: v86);
          }
          else
          {
            if ( this->m_bWordsActive )
              PhonemeEditor::EditDeleteWord(this);
            else
              PhonemeEditor::EditDeletePhoneme(this);
LABEL_227:
            v87 = (HWND)mxWidget::getHandle(this);
            SetFocus(hWnd: v87);
          }
          break;
        case 71:
          if ( !v76 )
            goto LABEL_227;
          PhonemeEditor::CommitExtracted(this);
          v96 = (HWND)mxWidget::getHandle(this);
          SetFocus(hWnd: v96);
          break;
        case 79:
          if ( !v76 )
            goto LABEL_227;
          PhonemeEditor::LoadWaveFile(this);
          v93 = (HWND)mxWidget::getHandle(this);
          SetFocus(hWnd: v93);
          break;
        case 82:
          if ( v76 )
            PhonemeEditor::RedoPhonemeExtraction(this);
          goto LABEL_227;
        case 83:
          if ( !v76 )
            goto LABEL_227;
          PhonemeEditor::CommitChanges(this);
          v94 = (HWND)mxWidget::getHandle(this);
          SetFocus(hWnd: v94);
          break;
        case 84:
          if ( !v76 )
            goto LABEL_227;
          PhonemeEditor::EditWordList(this);
          v95 = (HWND)mxWidget::getHandle(this);
          SetFocus(hWnd: v95);
          break;
        default:
          goto LABEL_227;
      }
      goto LABEL_84;
    case 0xB:
      v97 = v5->key;
      switch ( v97 )
      {
        case 16:
        case 17:
          GetCursorPos(lpPoint: (LPPOINT)&rc.right);
          SetCursorPos(X: rc.right, Y: rc.bottom);
          v2->EndLock(this: v2);
          result = 0;
          break;
        case 37:
        case 39:
          v98 = 2 * (v97 != 37) - 1;
          if ( this->m_bWordsActive )
          {
            if ( GetAsyncKeyState(vKey: 17) != 0 )
            {
              PhonemeEditor::ExtendSelectedWordEndTime(this, direction: v98);
            }
            else if ( GetAsyncKeyState(vKey: 16) != 0 )
            {
              PhonemeEditor::ShiftSelectedWord(this, direction: v98);
            }
            else
            {
              PhonemeEditor::SelectNextWord(this, direction: v98);
            }
          }
          else if ( GetAsyncKeyState(vKey: 17) != 0 )
          {
            PhonemeEditor::ExtendSelectedPhonemeEndTime(this, direction: v98);
          }
          else if ( GetAsyncKeyState(vKey: 16) != 0 )
          {
            PhonemeEditor::ShiftSelectedPhoneme(this, direction: v98);
          }
          else
          {
            PhonemeEditor::SelectNextPhoneme(this, direction: v98);
          }
          goto LABEL_84;
        case 89:
          if ( GetAsyncKeyState(vKey: 17) != 0 )
            PhonemeEditor::Redo(this);
          goto LABEL_84;
        case 90:
          if ( GetAsyncKeyState(vKey: 17) != 0 )
            PhonemeEditor::Undo(this);
          goto LABEL_84;
        default:
          goto LABEL_84;
      }
      return result;
    case 0xC:
      m_nTimeZoomStep = this->m_nTimeZoomStep;
      if ( v5->height <= 0 )
      {
        if ( this->m_nTimeZoom - m_nTimeZoomStep > m_nTimeZoomStep )
          m_nTimeZoomStep = this->m_nTimeZoom - m_nTimeZoomStep;
      }
      else
      {
        m_nTimeZoomStep += this->m_nTimeZoom;
        if ( m_nTimeZoomStep >= 1000 )
          m_nTimeZoomStep = 1000;
      }
      this->m_nTimeZoom = m_nTimeZoomStep;
LABEL_83:
      PhonemeEditor::RepositionHSlider(this);
LABEL_84:
      iret = 1;
      goto LABEL_85;
    default:
      goto LABEL_85;
  }
}
