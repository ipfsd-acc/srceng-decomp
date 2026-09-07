// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/wavefile.cpp
// Functions: 11
// ============================================================

#include "utils\hlfaceposer\wavefile.h"

//------------------------------------------------------------------------------
// Address: 0x0048C530
// Name: public: CWaveFile::CWaveFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWaveFile *__thiscall CWaveFile::CWaveFile(CWaveFile *this, const char *filename)
{
  CSentence::CSentence(this: &this->m_Sentence);
  *(_WORD *)&this->m_bSentenceLoaded = 0;
  CSentence::Reset(this: &this->m_Sentence);
  V_strncpy(pDest: this->m_szName, pSrc: filename, maxLen: 128);
  V_snprintf(pDest: this->m_szFileName, maxLen: 128, pFormat: "sound/%s", filename);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0048C580
// Name: public: CWaveFile::~CWaveFile(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CWaveFile::~CWaveFile(CWaveFile *this)
{
  CSentence::~CSentence(this: &this->m_Sentence);
}

//------------------------------------------------------------------------------
// Address: 0x0048C590
// Name: public: bool CWaveFile::HasLoadedSentenceInfo(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWaveFile::HasLoadedSentenceInfo(CWaveFile *this)
{
  return this->m_bSentenceLoaded;
}

//------------------------------------------------------------------------------
// Address: 0x0048C5A0
// Name: public: char const __near * CWaveFile::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CWaveFile::GetName(CWaveFile *this)
{
  return this->m_szName;
}

//------------------------------------------------------------------------------
// Address: 0x0048C5B0
// Name: public: char const __near * CWaveFile::GetFileName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CWaveFile::GetFileName(CWaveFile *this)
{
  return this->m_szFileName;
}

//------------------------------------------------------------------------------
// Address: 0x0048C5C0
// Name: public: char const __near * CWaveFile::GetSentenceText(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CWaveFile::GetSentenceText(CWaveFile *this)
{
  bool v2; // zf

  if ( !this->m_bSentenceLoaded )
  {
    v2 = this->m_szFileName[0] == 0;
    this->m_bSentenceLoaded = true;
    if ( !v2 )
      SceneManager_LoadSentenceFromWavFile(wavfile: this->m_szFileName, sentence: &this->m_Sentence);
  }
  return CSentence::GetText(this: &this->m_Sentence);
}

//------------------------------------------------------------------------------
// Address: 0x0048C600
// Name: public: int CWaveFile::GetPhonemeCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWaveFile::GetPhonemeCount(CWaveFile *this)
{
  bool v2; // zf

  if ( !this->m_bSentenceLoaded )
  {
    v2 = this->m_szFileName[0] == 0;
    this->m_bSentenceLoaded = true;
    if ( !v2 )
      SceneManager_LoadSentenceFromWavFile(wavfile: this->m_szFileName, sentence: &this->m_Sentence);
  }
  return CSentence::CountPhonemes(this: &this->m_Sentence);
}

//------------------------------------------------------------------------------
// Address: 0x0048C640
// Name: public: void CWaveFile::Play(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveFile::Play(CWaveFile *this)
{
  bool v2; // zf
  char *Text; // eax
  char *m_szFileName; // esi
  Color v5; // ecx

  if ( !this->m_bSentenceLoaded )
  {
    v2 = this->m_szFileName[0] == 0;
    this->m_bSentenceLoaded = true;
    if ( !v2 )
      SceneManager_LoadSentenceFromWavFile(wavfile: this->m_szFileName, sentence: &this->m_Sentence);
  }
  Text = CSentence::GetText(this: &this->m_Sentence);
  m_szFileName = this->m_szFileName;
  Con_Printf(a1: v5, fmt: "Playing '%s' : '%s'\n", m_szFileName, Text);
  PhonemeEditor::SetCurrentWaveFile(this: g_pPhonemeEditor, wavefile: m_szFileName, force: false, event: nullptr);
  PhonemeEditor::Play(this: g_pPhonemeEditor);
}

//------------------------------------------------------------------------------
// Address: 0x0048C6B0
// Name: public: bool CWaveFile::GetVoiceDuck(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWaveFile::GetVoiceDuck(CWaveFile *this)
{
  bool v2; // zf

  if ( !this->m_bSentenceLoaded )
  {
    v2 = this->m_szFileName[0] == 0;
    this->m_bSentenceLoaded = true;
    if ( !v2 )
      SceneManager_LoadSentenceFromWavFile(wavfile: this->m_szFileName, sentence: &this->m_Sentence);
  }
  return *((_BYTE *)&this->m_Sentence + 74);
}

//------------------------------------------------------------------------------
// Address: 0x0048C6F0
// Name: public: void CWaveFile::SetThreadLoadedSentence(class CSentence __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveFile::SetThreadLoadedSentence(CWaveFile *this, CSentence *sentence)
{
  if ( !this->m_bSentenceLoaded )
  {
    this->m_bSentenceLoaded = true;
    CSentence::operator=(this: &this->m_Sentence, src: sentence);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048C710
// Name: public: int CWaveFile::GetWordCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWaveFile::GetWordCount(CWaveFile *this)
{
  bool v2; // zf

  if ( !this->m_bSentenceLoaded )
  {
    v2 = this->m_szFileName[0] == 0;
    this->m_bSentenceLoaded = true;
    if ( !v2 )
      SceneManager_LoadSentenceFromWavFile(wavfile: this->m_szFileName, sentence: &this->m_Sentence);
  }
  return this->m_Sentence.m_Words.m_Size;
}
