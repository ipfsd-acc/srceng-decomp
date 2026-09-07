// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/wavefile.cpp
// Functions: 21
// ============================================================

#include "utils\scenemanager\wavefile.h"

//------------------------------------------------------------------------------
// Address: 0x00418C60
// Name: public: CWaveFile::CWaveFile(class CVCDFile __near *,class CSoundEntry __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWaveFile *__thiscall CWaveFile::CWaveFile(CWaveFile *this, CVCDFile *vcd, CSoundEntry *se, const char *filename)
{
  this->m_bExpanded = false;
  this->m_nOrdinal = -1;
  this->__vftable = (CWaveFile_vtbl *)&CWaveFile::`vftable';
  CSentence::CSentence(this: &this->m_Sentence);
  this->m_pOwnerSE = se;
  this->m_pOwner = vcd;
  this->m_bSentenceLoaded = false;
  CSentence::Reset(this: &this->m_Sentence);
  V_strncpy(pDest: this->m_szName, pSrc: filename, maxLen: 128);
  this->m_pWaveFile = nullptr;
  V_snprintf(pDest: this->m_szFileName, maxLen: 128, pFormat: "sound/%s", filename);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00418CF0
// Name: public: CWaveFile::~CWaveFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveFile::~CWaveFile(CWaveFile *this)
{
  this->__vftable = (CWaveFile_vtbl *)&CWaveFile::`vftable';
  CSentence::~CSentence(this: &this->m_Sentence);
}

//------------------------------------------------------------------------------
// Address: 0x00418D00
// Name: public: void CWaveFile::EnsureSentence(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveFile::EnsureSentence(CWaveFile *this)
{
  bool v1; // zf

  if ( !this->m_bSentenceLoaded )
  {
    v1 = this->m_szFileName[0] == 0;
    this->m_bSentenceLoaded = true;
    if ( !v1 )
      SceneManager_LoadSentenceFromWavFile(wavfile: this->m_szFileName, sentence: &this->m_Sentence);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418D30
// Name: public: bool CWaveFile::HasLoadedSentenceInfo(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWaveFile::HasLoadedSentenceInfo(CWaveFile *this)
{
  return this->m_bSentenceLoaded;
}

//------------------------------------------------------------------------------
// Address: 0x00418D40
// Name: public: class CSoundEntry __near * CWaveFile::GetOwnerSoundEntry(void)
// Source: json
//------------------------------------------------------------------------------
CSoundEntry *__thiscall CWaveFile::GetOwnerSoundEntry(CWaveFile *this)
{
  return this->m_pOwnerSE;
}

//------------------------------------------------------------------------------
// Address: 0x00418D50
// Name: public: virtual char const __near * CWaveFile::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CWaveFile::GetName(CWaveFile *this)
{
  return this->m_szName;
}

//------------------------------------------------------------------------------
// Address: 0x00418D60
// Name: public: char const __near * CWaveFile::GetFileName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CWaveFile::GetFileName(CWaveFile *this)
{
  return this->m_szFileName;
}

//------------------------------------------------------------------------------
// Address: 0x00418D70
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
// Address: 0x00418DB0
// Name: public: void CWaveFile::Play(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveFile::Play(CWaveFile *this)
{
  CAudioSource *v2; // eax
  bool v3; // zf
  char *Text; // eax
  CAudioMixer *temp; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_pWaveFile != nullptr
    || (v2 = sound->FindOrAddSound(this: sound, a2: this->m_szFileName), this->m_pWaveFile = v2, v2 != nullptr) )
  {
    if ( !this->m_bSentenceLoaded )
    {
      v3 = this->m_szFileName[0] == 0;
      this->m_bSentenceLoaded = true;
      if ( !v3 )
        SceneManager_LoadSentenceFromWavFile(wavfile: this->m_szFileName, sentence: &this->m_Sentence);
    }
    Text = CSentence::GetText(this: &this->m_Sentence);
    Con_Printf(fmt: "Playing '%s' : '%s'\n", this->m_szFileName, Text);
    sound->PlaySoundA(this: sound, a2: this->m_pWaveFile, a3: &temp);
  }
  else
  {
    Con_Printf(fmt: "Can't play '%s', no wave file loaded\n", this->m_szFileName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418E60
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
// Address: 0x00418EA0
// Name: public: virtual int CWaveFile::GetIconIndex(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWaveFile::GetIconIndex(CWaveFile *this)
{
  return filesystem->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: this->m_szFileName, a3: nullptr) + 7;
}

//------------------------------------------------------------------------------
// Address: 0x00418ED0
// Name: public: virtual void CWaveFile::Checkout(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveFile::Checkout(CWaveFile *this, bool updatestateicons)
{
  VSS_Checkout(name: this->m_szFileName, updatestaticons: updatestateicons);
}

//------------------------------------------------------------------------------
// Address: 0x00418EF0
// Name: public: virtual void CWaveFile::Checkin(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveFile::Checkin(CWaveFile *this, bool updatestateicons)
{
  VSS_Checkin(name: this->m_szFileName, updatestaticons: updatestateicons);
}

//------------------------------------------------------------------------------
// Address: 0x00418F20
// Name: public: virtual void CWaveFile::SetDirty(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveFile::SetDirty(CWaveFile *this, BOOL dirty)
{
  CVCDFile *m_pOwner; // ecx

  m_pOwner = this->m_pOwner;
  if ( m_pOwner != nullptr )
    m_pOwner->SetDirty(this: m_pOwner, a2: dirty);
}

//------------------------------------------------------------------------------
// Address: 0x00418F50
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
// Address: 0x00418F70
// Name: public: void CWaveFile::GetPhonemeExportFile(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveFile::GetPhonemeExportFile(CWaveFile *this, char *path, int maxlen)
{
  char *m_szFileName; // eax
  int v4; // edx
  char v5; // cl
  char relative[512]; // [esp+0h] [ebp-200h] BYREF

  m_szFileName = this->m_szFileName;
  v4 = relative - this->m_szFileName;
  do
  {
    v5 = *m_szFileName;
    m_szFileName[v4] = *m_szFileName;
    ++m_szFileName;
  }
  while ( v5 != 0 );
  V_StripExtension(in: relative, out: relative, outSize: 512);
  V_DefaultExtension(path: relative, extension: ".txt", pathStringLength: 512);
  V_snprintf(pDest: path, maxLen: maxlen, pFormat: "phonemes/%s", relative);
  V_FixSlashes(pname: path, separator: 92);
}

//------------------------------------------------------------------------------
// Address: 0x00418FF0
// Name: public: void CWaveFile::SetSentenceText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveFile::SetSentenceText(CWaveFile *this, const char *newText)
{
  bool v3; // zf
  CSentence *p_m_Sentence; // edi
  char *Text; // eax
  char *m_szFileName; // esi
  const char *v7; // eax

  if ( !this->m_bSentenceLoaded )
  {
    v3 = this->m_szFileName[0] == 0;
    this->m_bSentenceLoaded = true;
    if ( !v3 )
      SceneManager_LoadSentenceFromWavFile(wavfile: this->m_szFileName, sentence: &this->m_Sentence);
    if ( !this->m_bSentenceLoaded )
    {
      v3 = this->m_szFileName[0] == 0;
      this->m_bSentenceLoaded = true;
      if ( !v3 )
        SceneManager_LoadSentenceFromWavFile(wavfile: this->m_szFileName, sentence: &this->m_Sentence);
    }
  }
  p_m_Sentence = &this->m_Sentence;
  Text = CSentence::GetText(this: &this->m_Sentence);
  if ( _V_stricmp(s1: Text, s2: newText) != 0 )
  {
    m_szFileName = this->m_szFileName;
    if ( !filesystem->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: m_szFileName, a3: nullptr) )
    {
      v7 = va(fmt: "Check out '%s'?", m_szFileName);
      if ( MultipleRequest(prompt: v7) != 0 )
        return;
      VSS_Checkout(name: m_szFileName, updatestaticons: true);
    }
    CSentence::SetText(this: p_m_Sentence, text: newText);
    SceneManager_SaveSentenceToWavFile(a1: (int)newText, wavfile: m_szFileName, sentence: p_m_Sentence);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004190D0
// Name: public: void CWaveFile::SetVoiceDuck(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CWaveFile::SetVoiceDuck(CWaveFile *this@<ecx>, int a2@<ebx>, bool duck)
{
  bool v4; // zf
  const char *v5; // eax

  if ( !this->m_bSentenceLoaded )
  {
    v4 = this->m_szFileName[0] == 0;
    this->m_bSentenceLoaded = true;
    if ( !v4 )
      SceneManager_LoadSentenceFromWavFile(wavfile: this->m_szFileName, sentence: &this->m_Sentence);
    if ( !this->m_bSentenceLoaded )
    {
      v4 = this->m_szFileName[0] == 0;
      this->m_bSentenceLoaded = true;
      if ( !v4 )
        SceneManager_LoadSentenceFromWavFile(wavfile: this->m_szFileName, sentence: &this->m_Sentence);
    }
  }
  if ( *((_BYTE *)&this->m_Sentence + 74) != duck )
  {
    *((_BYTE *)&this->m_Sentence + 74) = duck;
    if ( !filesystem->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: this->m_szFileName, a3: nullptr) )
    {
      v5 = va(fmt: "Check out '%s'?", this->m_szFileName);
      if ( MultipleRequest(prompt: v5) != 0 )
        return;
      VSS_Checkout(name: this->m_szFileName, updatestaticons: true);
    }
    SceneManager_SaveSentenceToWavFile(a1: a2, wavfile: this->m_szFileName, sentence: &this->m_Sentence);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419190
// Name: public: void CWaveFile::ToggleVoiceDucking(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CWaveFile::ToggleVoiceDucking(CWaveFile *this@<ecx>, int a2@<ebx>)
{
  bool v3; // zf
  const char *v4; // eax

  if ( !this->m_bSentenceLoaded )
  {
    v3 = this->m_szFileName[0] == 0;
    this->m_bSentenceLoaded = true;
    if ( !v3 )
      SceneManager_LoadSentenceFromWavFile(wavfile: this->m_szFileName, sentence: &this->m_Sentence);
  }
  *((_BYTE *)&this->m_Sentence + 74) = *((_BYTE *)&this->m_Sentence + 74) == 0;
  if ( !filesystem->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: this->m_szFileName, a3: nullptr) )
  {
    v4 = va(fmt: "Check out '%s'?", this->m_szFileName);
    if ( MultipleRequest(prompt: v4) != 0 )
      return;
    VSS_Checkout(name: this->m_szFileName, updatestaticons: true);
  }
  SceneManager_SaveSentenceToWavFile(a1: a2, wavfile: this->m_szFileName, sentence: &this->m_Sentence);
}

//------------------------------------------------------------------------------
// Address: 0x00419220
// Name: public: void CWaveFile::ImportValveDataChunk(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CWaveFile::ImportValveDataChunk(
        CWaveFile *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const char *tempfile)
{
  bool v5; // zf
  void *v6; // ebx
  int v7; // edi
  void *v8; // esi
  CWaveFile *v9; // edi
  const char *m_szFileName; // esi
  const char *v11; // eax
  CSentence *p_m_Sentence; // edi
  CSentence newSentence; // [esp+0h] [ebp-50h] BYREF
  CWaveFile *v14; // [esp+4Ch] [ebp-4h]

  v5 = !this->m_bSentenceLoaded;
  v14 = this;
  if ( v5 )
  {
    v5 = this->m_szFileName[0] == 0;
    this->m_bSentenceLoaded = true;
    if ( !v5 )
      SceneManager_LoadSentenceFromWavFile(wavfile: this->m_szFileName, sentence: &this->m_Sentence);
  }
  v6 = (void *)((int (__thiscall *)(IBaseFileSystem *, const char *, const char *, _DWORD, int, int))filesystem->Open)(
                 a1: &filesystem->IBaseFileSystem,
                 a2: tempfile,
                 a3: "rb",
                 a4: 0,
                 a5: a4,
                 a6: a2);
  if ( v6 == nullptr )
  {
    Con_ColorPrintf(r: 255, g: 102, b: 0, fmt: "CWaveFile::ImportValveDataChunk:  Unable to read from %s\n", tempfile);
    return;
  }
  v7 = ((int (__thiscall *)(IBaseFileSystem *, void *, int))filesystem->Size_2)(
         a1: &filesystem->IBaseFileSystem,
         a2: v6,
         a3);
  if ( v7 <= 4 )
  {
    Con_ColorPrintf(r: 255, g: 102, b: 0, fmt: "CWaveFile::ImportValveDataChunk:  File %s has length 0\n", tempfile);
    return;
  }
  CSentence::CSentence(this: &newSentence);
  v8 = operator new(nSize: v7 + 1);
  filesystem->Read(this: &filesystem->IBaseFileSystem, a2: v8, a3: v7, a4: v6);
  filesystem->Close(this: &filesystem->IBaseFileSystem, a2: v6);
  CSentence::InitFromDataChunk(this: &newSentence, data: v8, size: v7);
  free(pMem: v8);
  v9 = v14;
  m_szFileName = v14->m_szFileName;
  if ( filesystem->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: v14->m_szFileName, a3: nullptr) )
    goto LABEL_11;
  v11 = va(fmt: "Check out '%s'?", m_szFileName);
  if ( MultipleRequest(prompt: v11) == 0 )
  {
    VSS_Checkout(name: m_szFileName, updatestaticons: true);
LABEL_11:
    if ( !filesystem->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: m_szFileName, a3: nullptr) )
    {
      MakeFileWriteable(filename: m_szFileName);
      Con_Printf(fmt: "Unable to check out %s, forcing it to be writable instead!\n", m_szFileName);
    }
    Con_Printf(fmt: "Imported %i words from %s\n", newSentence.m_Words.m_Size, tempfile);
    p_m_Sentence = &v9->m_Sentence;
    CSentence::operator=(this: p_m_Sentence, src: &newSentence);
    SceneManager_SaveSentenceToWavFile(a1: (int)v6, wavfile: m_szFileName, sentence: p_m_Sentence);
  }
  CSentence::~CSentence(this: &newSentence);
}

//------------------------------------------------------------------------------
// Address: 0x004193D0
// Name: public: void CWaveFile::ExportValveDataChunk(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaveFile::ExportValveDataChunk(CWaveFile *this, const char *tempfile)
{
  bool v3; // zf
  char *GameDirectory; // eax
  char *v5; // eax
  void *v6; // edi
  CUtlBuffer buf; // [esp+4h] [ebp-30h] BYREF

  if ( !this->m_bSentenceLoaded )
  {
    v3 = this->m_szFileName[0] == 0;
    this->m_bSentenceLoaded = true;
    if ( !v3 )
      SceneManager_LoadSentenceFromWavFile(wavfile: this->m_szFileName, sentence: &this->m_Sentence);
  }
  if ( this->m_Sentence.m_Words.m_Size > 0 )
  {
    GameDirectory = SceneManager_GetGameDirectory();
    v5 = va(fmt: "%s%s", GameDirectory, tempfile);
    SafeCreatePath(path: v5);
    v6 = filesystem->Open(this: &filesystem->IBaseFileSystem, a2: tempfile, a3: "wb", a4: 0);
    if ( v6 != nullptr )
    {
      CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
      CSentence::SaveToBuffer(this: &this->m_Sentence, &buf);
      filesystem->Write(this: &filesystem->IBaseFileSystem, a2: buf.m_Memory.m_pMemory, a3: buf.m_Put, a4: v6);
      filesystem->Close(this: &filesystem->IBaseFileSystem, a2: v6);
      Con_Printf(fmt: "Exported %i words to %s\n", this->m_Sentence.m_Words.m_Size, tempfile);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
    else
    {
      Con_ColorPrintf(
        r: 255,
        g: 102,
        b: 0,
        fmt: "CWaveFile::ExportValveDataChunk:  Unable to write to %s (read-only?)\n",
        tempfile);
    }
  }
  else
  {
    Con_ColorPrintf(r: 255, g: 102, b: 0, fmt: "CWaveFile::ExportValveDataChunk:  Sentence has no word data\n");
  }
}
