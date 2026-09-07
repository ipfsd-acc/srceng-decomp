// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/expression.cpp
// Functions: 25
// ============================================================

#include "utils\hlfaceposer\expression.h"

//------------------------------------------------------------------------------
// Address: 0x00447C40
// Name: public: bool CExpression::GetDirty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpression::GetDirty(CExpression *this)
{
  return this->m_bDirty;
}

//------------------------------------------------------------------------------
// Address: 0x00447C50
// Name: public: void CExpression::SetDirty(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpression::SetDirty(CExpression *this, bool dirty)
{
  this->m_bDirty = dirty;
}

//------------------------------------------------------------------------------
// Address: 0x00447C60
// Name: public: float __near * CExpression::GetSettings(void)
// Source: json
//------------------------------------------------------------------------------
float *__thiscall CExpression::GetSettings(CExpression *this)
{
  return this->setting;
}

//------------------------------------------------------------------------------
// Address: 0x00447C70
// Name: public: float __near * CExpression::GetWeights(void)
// Source: json
//------------------------------------------------------------------------------
float *__thiscall CExpression::GetWeights(CExpression *this)
{
  return this->weight;
}

//------------------------------------------------------------------------------
// Address: 0x00447C80
// Name: public: void CExpression::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpression::SetSelected(CExpression *this, bool selected)
{
  this->m_bSelected = selected;
}

//------------------------------------------------------------------------------
// Address: 0x00447C90
// Name: public: bool CExpression::GetSelected(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpression::GetSelected(CExpression *this)
{
  return this->m_bSelected;
}

//------------------------------------------------------------------------------
// Address: 0x00447CA0
// Name: public: int CExpression::UndoCurrent(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CExpression::UndoCurrent(CExpression *this)
{
  return this->m_nUndoCurrent;
}

//------------------------------------------------------------------------------
// Address: 0x00447CB0
// Name: public: void CExpression::SetExpressionClass(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpression::SetExpressionClass(CExpression *this, const char *classname)
{
  const char *v2; // eax
  int v3; // edx
  char v4; // cl

  v2 = classname;
  v3 = this->expressionclass - classname;
  do
  {
    v4 = *v2;
    v2[v3] = *v2;
    ++v2;
  }
  while ( v4 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x00447CD0
// Name: public: bool CExpression::CanRedo(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpression::CanRedo(CExpression *this)
{
  return this->undo.m_Size != 0 && this->m_nUndoCurrent != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00447CF0
// Name: public: bool CExpression::CanUndo(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpression::CanUndo(CExpression *this)
{
  int m_Size; // eax

  m_Size = this->undo.m_Size;
  return m_Size != 0 && this->m_nUndoCurrent < m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00447D10
// Name: public: int CExpression::UndoLevels(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CExpression::UndoLevels(CExpression *this)
{
  return this->undo.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00447D20
// Name: public: unsigned long CExpression::GetBitmapCRC(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CExpression::GetBitmapCRC(CExpression *this)
{
  CExpUndoInfo *setting; // eax
  float *weight; // edx
  unsigned int crc; // [esp+0h] [ebp-4h] BYREF

  crc = (unsigned int)this;
  setting = (CExpUndoInfo *)this->setting;
  weight = this->weight;
  if ( this->undo.m_Size >= 1 )
  {
    setting = this->undo.m_Memory.m_pMemory[this->undo.m_Size - 1];
    weight = setting->weight;
  }
  ChecksumFlexControllers(bSpew: false, name: this->name, &crc, settings: setting->setting, weights: weight);
  return crc;
}

//------------------------------------------------------------------------------
// Address: 0x00447D70
// Name: public: char const __near * CExpression::GetBitmapCheckSum(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CExpression::GetBitmapCheckSum(CExpression *this)
{
  CExpUndoInfo *setting; // eax
  float *weight; // edx
  unsigned int crc; // [esp+0h] [ebp-8h] BYREF
  unsigned int v5; // [esp+4h] [ebp-4h] BYREF

  setting = (CExpUndoInfo *)this->setting;
  weight = this->weight;
  if ( this->undo.m_Size >= 1 )
  {
    setting = this->undo.m_Memory.m_pMemory[this->undo.m_Size - 1];
    weight = setting->weight;
  }
  ChecksumFlexControllers(bSpew: false, name: this->name, crc: &v5, settings: setting->setting, weights: weight);
  crc = v5;
  V_binarytohex(in: (const unsigned __int8 *)&crc, inputbytes: 4, out: hex, outsize: 9);
  return hex;
}

//------------------------------------------------------------------------------
// Address: 0x00447DE0
// Name: public: char const __near * CExpression::GetBitmapFilename(int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CExpression::GetBitmapFilename(CExpression *this, int modelindex)
{
  CExpClass *(__thiscall *FindClass)(IExpressionManager *, const char *, bool); // eax
  CChoreoChannel *v4; // eax
  const char *v5; // eax
  char *v6; // esi
  char *i; // edi
  char v8; // al
  char *v9; // eax
  char modelName[512]; // [esp+Ch] [ebp-404h] BYREF
  char modelNameTemp[512]; // [esp+20Ch] [ebp-204h] BYREF
  const char *classname; // [esp+40Ch] [ebp-4h]

  FindClass = expressions->FindClass;
  classname = "error";
  v4 = (CChoreoChannel *)FindClass(this: expressions, a2: this->expressionclass, a3: false);
  if ( v4 != nullptr )
    classname = CChoreoChannel::GetName(this: v4);
  v5 = models->GetModelName(this: models, a2: modelindex);
  V_strncpy(pDest: modelNameTemp, pSrc: v5, maxLen: 512);
  v6 = modelNameTemp;
  for ( i = modelName; *v6 != 0; ++v6 )
  {
    if ( isalnum(c: *v6) == 0 )
    {
      v8 = *v6;
      if ( *v6 != 95 && v8 != 92 && v8 != 47 && v8 != 46 && v8 != 58 )
        continue;
    }
    *i++ = *v6;
  }
  *i = 0;
  v9 = CExpression::GetBitmapCheckSum(this);
  sprintf(string: filename, format: "expressions/%s/%s/%s.bmp", modelName, classname, v9);
  V_FixSlashes(pname: filename, separator: 92);
  strlwr(string: filename);
  CreatePath(relative: filename);
  return filename;
}

//------------------------------------------------------------------------------
// Address: 0x00447EE0
// Name: public: void CExpression::CreateNewBitmap(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpression::CreateNewBitmap(CExpression *this, int modelindex)
{
  char *BitmapFilename; // eax
  char *v4; // edx
  char v5; // cl
  char filename[256]; // [esp+4h] [ebp-100h] BYREF

  if ( g_pMatSysWindow != nullptr
    && models->GetStudioModel(this: models, a2: modelindex) != nullptr
    && models->GetStudioHeader(this: models, a2: modelindex) != nullptr )
  {
    BitmapFilename = CExpression::GetBitmapFilename(this, modelindex);
    v4 = (char *)(filename - BitmapFilename);
    do
    {
      v5 = *BitmapFilename;
      BitmapFilename[(_DWORD)v4] = *BitmapFilename;
      ++BitmapFilename;
    }
    while ( v5 != 0 );
    if ( _V_strstr(s1: filename, search: ".bmp") != nullptr )
      models->CreateNewBitmap(
        this: models,
        a2: modelindex,
        a3: filename,
        a4: 0,
        a5: 128,
        a6: true,
        a7: this,
        a8: &this->m_Bitmap[modelindex]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00447F90
// Name: public: void CExpression::PushRedoInformation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpression::PushRedoInformation(CExpression *this)
{
  CExpUndoInfo *v1; // edx

  v1 = *this->undo.m_Memory.m_pMemory;
  qmemcpy(v1->redosetting, this->setting, sizeof(v1->redosetting));
  qmemcpy(v1->redoweight, this->weight, sizeof(v1->redoweight));
}

//------------------------------------------------------------------------------
// Address: 0x00447FD0
// Name: public: void CExpression::Undo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpression::Undo(CExpression *this)
{
  int m_Size; // edx
  int m_nUndoCurrent; // ecx
  CExpUndoInfo *v4; // edx

  m_Size = this->undo.m_Size;
  if ( m_Size != 0 )
  {
    m_nUndoCurrent = this->m_nUndoCurrent;
    if ( m_nUndoCurrent < m_Size )
    {
      this->m_nUndoCurrent = m_nUndoCurrent + 1;
      v4 = this->undo.m_Memory.m_pMemory[m_nUndoCurrent];
      qmemcpy(this->setting, v4, sizeof(this->setting));
      qmemcpy(this->weight, v4->weight, sizeof(this->weight));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448020
// Name: public: void CExpression::Redo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpression::Redo(CExpression *this)
{
  int m_nUndoCurrent; // ecx
  CExpUndoInfo **m_pMemory; // edx
  int v4; // ecx
  CExpUndoInfo *v5; // edx

  if ( this->undo.m_Size != 0 )
  {
    m_nUndoCurrent = this->m_nUndoCurrent;
    if ( m_nUndoCurrent != 0 )
    {
      m_pMemory = this->undo.m_Memory.m_pMemory;
      v4 = m_nUndoCurrent - 1;
      this->m_nUndoCurrent = v4;
      v5 = m_pMemory[v4];
      qmemcpy(this->setting, v5->redosetting, sizeof(this->setting));
      qmemcpy(this->weight, v5->redoweight, sizeof(this->weight));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448070
// Name: public: void CExpression::ResetUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpression::ResetUndo(CExpression *this)
{
  int i; // edi

  for ( i = 0; i < this->undo.m_Size; ++i )
    free(pMem: this->undo.m_Memory.m_pMemory[i]);
  this->undo.m_Size = 0;
  this->m_nUndoCurrent = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004480C0
// Name: private: void CExpression::WipeRedoInformation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpression::WipeRedoInformation(CExpression *this)
{
  int v2; // ebx
  CExpUndoInfo *v3; // edi

  v2 = 0;
  if ( this->m_nUndoCurrent <= 0 )
  {
    this->m_nUndoCurrent = 0;
  }
  else
  {
    do
    {
      v3 = *this->undo.m_Memory.m_pMemory;
      if ( this->undo.m_Size - 1 > 0 )
        _V_memmove(
          dest: this->undo.m_Memory.m_pMemory,
          src: this->undo.m_Memory.m_pMemory + 1,
          count: 4 * (this->undo.m_Size - 1));
      --this->undo.m_Size;
      free(pMem: v3);
      ++v2;
    }
    while ( v2 < this->m_nUndoCurrent );
    this->m_nUndoCurrent = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448130
// Name: public: void CExpression::Revert(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpression::Revert(CExpression *this)
{
  int m_Size; // ecx
  CExpUndoInfo *v3; // edx

  m_Size = this->undo.m_Size;
  this->m_bDirty = false;
  if ( m_Size > 0 )
  {
    v3 = this->undo.m_Memory.m_pMemory[m_Size - 1];
    qmemcpy(this->setting, v3, sizeof(this->setting));
    qmemcpy(this->weight, v3->weight, sizeof(this->weight));
    CExpression::ResetUndo(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448180
// Name: public: CExpression::CExpression(void)
// Source: json
//------------------------------------------------------------------------------
CExpression *__thiscall CExpression::CExpression(CExpression *this)
{
  mxbitmapdata_t *m_Bitmap; // eax
  int i; // ecx
  mxbitmapdata_t *v4; // eax
  int j; // ecx

  m_Bitmap = this->m_Bitmap;
  for ( i = 15; i >= 0; --i )
  {
    m_Bitmap->valid = false;
    m_Bitmap->image = nullptr;
    m_Bitmap->width = 0;
    m_Bitmap->height = 0;
    ++m_Bitmap;
  }
  this->undo.m_Memory.m_pMemory = nullptr;
  this->undo.m_Memory.m_nAllocationCount = 0;
  this->undo.m_Memory.m_nGrowSize = 0;
  this->undo.m_Size = 0;
  this->undo.m_pElements = nullptr;
  this->name[0] = 0;
  this->index = 0;
  this->description[0] = 0;
  memset(dst: (unsigned __int8 *)this->setting, value: 0, count: sizeof(this->setting));
  v4 = this->m_Bitmap;
  for ( j = 16; j != 0; --j )
  {
    v4->valid = false;
    ++v4;
  }
  this->m_nUndoCurrent = 0;
  this->m_bModified = false;
  *(_WORD *)&this->m_bSelected = 0;
  this->expressionclass[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00448220
// Name: public: CExpression::~CExpression(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpression::~CExpression(CExpression *this)
{
  CExpression::ResetUndo(this);
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->undo);
}

//------------------------------------------------------------------------------
// Address: 0x00448240
// Name: public: CExpression::CExpression(class CExpression const __near &)
// Source: json
//------------------------------------------------------------------------------
CExpression *__thiscall CExpression::CExpression(CExpression *this, CExpUndoInfo *from)
{
  CExpression *v2; // edi
  mxbitmapdata_t *m_Bitmap; // ecx
  int j; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_undo; // esi
  char *v7; // ecx
  char v8; // dl
  mxbitmapdata_t *v9; // eax
  char *v10; // ecx
  int k; // edx
  unsigned __int8 *v12; // eax
  unsigned __int8 *v13; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v16; // ecx
  int v17; // eax
  unsigned __int8 **v18; // edi
  char *v19; // eax
  char v20; // cl
  int i; // [esp+10h] [ebp-4h]
  unsigned __int8 *newUndo; // [esp+1Ch] [ebp+8h]

  v2 = this;
  m_Bitmap = this->m_Bitmap;
  for ( j = 15; j >= 0; --j )
  {
    m_Bitmap->valid = false;
    m_Bitmap->image = nullptr;
    m_Bitmap->width = 0;
    m_Bitmap->height = 0;
    ++m_Bitmap;
  }
  p_undo = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v2->undo;
  v2->undo.m_Memory.m_pMemory = nullptr;
  v2->undo.m_Memory.m_nAllocationCount = 0;
  v2->undo.m_Memory.m_nGrowSize = 0;
  v2->undo.m_Size = 0;
  v2->undo.m_pElements = nullptr;
  strcpy(v2->name, (const char *)from);
  v2->index = LODWORD(from->setting[8]);
  v7 = (char *)&from->setting[9];
  do
  {
    v8 = *v7;
    v7[(char *)v2 - (char *)from] = *v7;
    ++v7;
  }
  while ( v8 != 0 );
  v9 = v2->m_Bitmap;
  v10 = (char *)((char *)from - (char *)v2);
  for ( k = 16; k != 0; --k )
  {
    *(_QWORD *)&v9->valid = *(_QWORD *)(&v9->valid + (_DWORD)v10);
    *(_QWORD *)&v9->width = *(_QWORD *)((char *)&v9->width + (_DWORD)v10);
    ++v9;
  }
  v2->m_bModified = LOBYTE(from->setting[105]);
  i = 0;
  if ( SLODWORD(from->setting[109]) > 0 )
  {
    do
    {
      v12 = (unsigned __int8 *)operator new(nSize: 0x1804u);
      v13 = v12;
      if ( v12 != nullptr )
      {
        memset(dst: v12, value: 0, count: 0x1804u);
        newUndo = v13;
      }
      else
      {
        newUndo = nullptr;
      }
      memcpy(dst: newUndo, src: *(unsigned __int8 **)(LODWORD(from->setting[106]) + 4 * i), count: 0x1804u);
      m_pMemory = p_undo[1].m_pMemory;
      m_nAllocationCount = p_undo->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IFacePoserToolWindow *,int>::Grow(this: p_undo, num: (int)m_pMemory - m_nAllocationCount + 1);
      ++p_undo[1].m_pMemory;
      v16 = p_undo->m_pMemory;
      v17 = (char *)p_undo[1].m_pMemory - (char *)m_pMemory - 1;
      p_undo[1].m_nAllocationCount = (int)p_undo->m_pMemory;
      if ( v17 > 0 )
        _V_memmove(dest: &v16[(_DWORD)m_pMemory + 1], src: &v16[(_DWORD)m_pMemory], count: 4 * v17);
      v18 = (unsigned __int8 **)&p_undo->m_pMemory[(_DWORD)m_pMemory];
      if ( v18 != nullptr )
        *v18 = newUndo;
      ++i;
    }
    while ( i < SLODWORD(from->setting[109]) );
    v2 = this;
  }
  v2->m_nUndoCurrent = LODWORD(from->setting[111]);
  v2->m_bSelected = LOBYTE(from->setting[112]);
  v19 = (char *)&from->redosetting[113];
  v2->m_bDirty = BYTE1(from->setting[112]);
  do
  {
    v20 = *v19;
    v19[(char *)v2 - (char *)from] = *v19;
    ++v19;
  }
  while ( v20 != 0 );
  qmemcpy(v2->setting, &from->setting[113], sizeof(v2->setting));
  qmemcpy(this->weight, &from->weight[113], sizeof(this->weight));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00448430
// Name: public: void CExpression::PushUndoInformation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpression::PushUndoInformation(CExpression *this)
{
  int v2; // eax
  int m_nAllocationCount; // ecx
  int m_Size; // eax
  CExpUndoInfo **m_pMemory; // eax
  int v6; // ecx
  CExpUndoInfo **v7; // esi
  CExpUndoInfo *newundo; // [esp+Ch] [ebp-4h]

  this->m_bModified = true;
  CExpression::WipeRedoInformation(this);
  newundo = (CExpUndoInfo *)operator new(nSize: 0x1804u);
  qmemcpy(newundo, this->setting, 0x600u);
  memset(dst: (unsigned __int8 *)newundo->redosetting, value: 0, count: sizeof(newundo->redosetting));
  qmemcpy(newundo->weight, this->weight, sizeof(newundo->weight));
  memset(dst: (unsigned __int8 *)newundo->redoweight, value: 0, count: sizeof(newundo->redoweight));
  v2 = g_counter;
  newundo->counter = g_counter;
  m_nAllocationCount = this->undo.m_Memory.m_nAllocationCount;
  g_counter = v2 + 1;
  m_Size = this->undo.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IFacePoserToolWindow *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->undo,
      num: m_Size - m_nAllocationCount + 1);
  ++this->undo.m_Size;
  m_pMemory = this->undo.m_Memory.m_pMemory;
  v6 = this->undo.m_Size - 1;
  this->undo.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: m_pMemory + 1, src: m_pMemory, count: 4 * v6);
  v7 = this->undo.m_Memory.m_pMemory;
  if ( v7 != nullptr )
    *v7 = newundo;
}
