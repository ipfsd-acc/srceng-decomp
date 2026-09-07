// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/saverestore.cpp
// Functions: 147
// ============================================================

#include "game\shared\saverestore.h"

//------------------------------------------------------------------------------
// Address: 0x10131F50
// Name: public: virtual char const __near * CSaveRestoreBlockSet::GetBlockName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSaveRestoreBlockSet::GetBlockName(CChoreoChannel *this)
{
  return this->m_szName;
}

//------------------------------------------------------------------------------
// Address: 0x101643B0
// Name: public: bool CSaveRestoreSegment::Read(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSaveRestoreSegment::Read(CSaveRestoreSegment *this, unsigned __int8 *pOutput, int nBytes)
{
  int bufferSize; // ecx

  bufferSize = this->bufferSize;
  if ( bufferSize == this->size )
    return 0;
  if ( nBytes <= bufferSize - this->size )
  {
    if ( pOutput != nullptr )
      memcpy(dst: pOutput, src: (unsigned __int8 *)this->pCurrentData, count: nBytes);
    this->pCurrentData += nBytes;
    this->size += nBytes;
    return 1;
  }
  else
  {
    this->size = bufferSize;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164400
// Name: char const __near * UTIL_FunctionToName(struct datamap_t __near *,void (CBaseEntity::*)(struct inputdata_t __near &))
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl UTIL_FunctionToName(
        datamap_t *pMap,
        void (__thiscall *function)(CBaseEntity *this, struct inputdata_t *))
{
  datamap_t *v2; // esi
  int dataNumFields; // edx
  int v4; // ecx
  void (__thiscall **p_inputFunc)(CBaseEntity *, struct inputdata_t *); // eax

  v2 = pMap;
  if ( pMap == nullptr )
    return nullptr;
  while ( 1 )
  {
    dataNumFields = v2->dataNumFields;
    v4 = 0;
    if ( dataNumFields > 0 )
      break;
LABEL_7:
    v2 = v2->baseMap;
    if ( v2 == nullptr )
      return nullptr;
  }
  p_inputFunc = &v2->dataDesc->inputFunc;
  while ( (*((_BYTE *)p_inputFunc - 10) & 0x20) == 0 || *p_inputFunc != function )
  {
    ++v4;
    p_inputFunc += 15;
    if ( v4 >= dataNumFields )
      goto LABEL_7;
  }
  return v2->dataDesc[v4].fieldName;
}

//------------------------------------------------------------------------------
// Address: 0x10164460
// Name: private: int CSave::DataEmpty(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSave::DataEmpty(CSave *this, const char *pdata, int size)
{
  const char *v3; // eax
  char v4; // dl

  if ( size == 4 )
    return *(_DWORD *)pdata == 0;
  v3 = pdata;
  if ( pdata >= &pdata[size] )
    return true;
  while ( 1 )
  {
    v4 = *v3++;
    if ( v4 != 0 )
      break;
    if ( v3 >= &pdata[size] )
      return true;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x101644A0
// Name: public: virtual void CSave::StartLogging(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::StartLogging(CSave *this, const char *pszLogName)
{
  this->m_hLogFile = filesystem->Open(this: &filesystem->IBaseFileSystem, a2: pszLogName, a3: "w", a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101644D0
// Name: public: virtual void CSave::EndLogging(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::EndLogging(CSave *this)
{
  void *m_hLogFile; // eax

  m_hLogFile = this->m_hLogFile;
  if ( m_hLogFile != nullptr )
    filesystem->Close(this: &filesystem->IBaseFileSystem, a2: m_hLogFile);
  this->m_hLogFile = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10164500
// Name: public: virtual bool CRestore::GetPrecacheMode(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRestore::GetPrecacheMode(CRestore *this)
{
  return this->m_precache;
}

//------------------------------------------------------------------------------
// Address: 0x10164510
// Name: public: virtual void CSave::SetWritePos(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::SetWritePos(CRestore *this, int pos)
{
  CSaveRestoreSegment *m_pData; // eax
  char *v3; // edx

  m_pData = this->m_pData;
  if ( pos >= 0 && pos < m_pData->bufferSize )
  {
    v3 = &m_pData->pBaseData[pos];
    m_pData->size = pos;
    m_pData->pCurrentData = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164530
// Name: public: virtual void CSave::WriteVector(char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteVector(CSave *this, const char *pname, const Vector *value)
{
  this->WriteVector(this, a2: pname, a3: value, a4: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10164550
// Name: public: virtual void CSave::WriteQuaternion(char const __near *,class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteQuaternion(CSave *this, const char *pname, const Quaternion *value)
{
  this->WriteQuaternion(this, a2: pname, a3: value, a4: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10164570
// Name: private: bool CSave::ShouldSaveField(void const __near *,struct typedescription_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSave::ShouldSaveField(CSave *this, char *pData, int pField)
{
  __int16 v5; // cx
  _fieldtypes v6; // edx
  char *v8; // ecx
  int v9; // eax
  ISaveRestoreOps *v10; // ecx
  char *v11; // eax
  __int16 v12; // ax
  datamap_t *v13; // ecx
  int v14; // ecx
  datamap_t *v15; // eax
  typedescription_t *dataDesc; // esi
  unsigned int v17; // ebx
  SaveRestoreFieldInfo_t fieldInfo; // [esp+8h] [ebp-10h] BYREF
  CSave *v19; // [esp+14h] [ebp-4h]
  int nFieldCount; // [esp+24h] [ebp+Ch]

  v5 = *(_WORD *)(pField + 14);
  v19 = this;
  if ( (v5 & 2) == 0 )
    return false;
  v6 = *(_DWORD *)pField;
  if ( *(_DWORD *)pField == 0 )
    return false;
  if ( v6 != FIELD_EMBEDDED )
  {
    if ( v6 == FIELD_CUSTOM )
    {
      v10 = *(ISaveRestoreOps **)(pField + 20);
      fieldInfo.pField = pData;
      v11 = &pData[-*(_DWORD *)(pField + 8)];
      fieldInfo.pTypeDesc = (typedescription_t *)pField;
      fieldInfo.pOwner = v11;
      return !v10->IsEmpty(this: v10, a2: &fieldInfo);
    }
    if ( v6 != FIELD_EHANDLE )
    {
      if ( *(_DWORD *)(pField + 32) != gSizes[v6] * *(unsigned __int16 *)(pField + 12) )
        _Warning(
          a1: "WARNING! Field %s is using the wrong FIELD_ type!\nFix this or you'll see a crash.\n",
          *(const char **)(pField + 4));
      return !CSave::DataEmpty(this, pdata: pData, size: gSizes[*(_DWORD *)pField] * *(unsigned __int16 *)(pField + 12));
    }
    if ( *(_DWORD *)(pField + 32) != gSizes[13] * *(unsigned __int16 *)(pField + 12) )
      _Warning(
        a1: "WARNING! Field %s is using the wrong FIELD_ type!\nFix this or you'll see a crash.\n",
        *(const char **)(pField + 4));
    v8 = pData;
    v9 = 0;
    if ( *(_WORD *)(pField + 12) != 0 )
    {
      while ( *(_DWORD *)v8 == -1 )
      {
        ++v9;
        v8 += 4;
        if ( v9 >= *(unsigned __int16 *)(pField + 12) )
          return false;
      }
      return true;
    }
    return false;
  }
  v12 = v5 & 0x40;
  if ( (v5 & 0x40) != 0 && *(_WORD *)(pField + 12) != 1 )
    return false;
  v13 = *(datamap_t **)(pField + 28);
  if ( v13 == nullptr || v12 != 0 && *(_DWORD *)pData == 0 )
    return false;
  if ( v13->baseMap != nullptr )
    return true;
  v14 = *(unsigned __int16 *)(pField + 12);
  if ( v12 != 0 )
    pData = *(char **)pData;
  nFieldCount = v14 - 1;
  if ( v14 - 1 < 0 )
    return false;
  while ( 1 )
  {
    v15 = *(datamap_t **)(pField + 28);
    dataDesc = v15->dataDesc;
    v17 = (unsigned int)&v15->dataDesc[v15->dataNumFields];
    if ( v15->dataDesc < (typedescription_t *)v17 )
      break;
LABEL_30:
    pData += *(_DWORD *)(pField + 32);
    if ( --nFieldCount < 0 )
      return false;
  }
  while ( !CSave::ShouldSaveField(this: v19, pData: &pData[dataDesc->fieldOffset], pField: dataDesc) )
  {
    if ( (unsigned int)++dataDesc >= v17 )
      goto LABEL_30;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10164720
// Name: private: bool CSave::WriteBasicField(char const __near *,void __near *,struct datamap_t __near *,struct typedescription_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSave::WriteBasicField(
        CSave *this,
        const char *pname,
        const Vector *pData,
        datamap_t *pRootMap,
        typedescription_t *pField)
{
  bool result; // al
  bool v8; // zf
  const Vector *x_low; // ebx
  ISaveRestoreOps *pSaveRestoreOps; // ecx
  char *v11; // eax
  SaveRestoreFieldInfo_t fieldInfo; // [esp+8h] [ebp-Ch] BYREF
  int nFieldCount; // [esp+28h] [ebp+14h]
  int nFieldCounta; // [esp+28h] [ebp+14h]

  switch ( pField->fieldType )
  {
    case FIELD_FLOAT:
      this->WriteFloat(this, a2: pField->fieldName, a3: (const float *)pData, a4: pField->fieldSize);
      result = true;
      break;
    case FIELD_STRING:
      this->WriteString(this, a2: pField->fieldName, a3: (const char *const *)pData, a4: pField->fieldSize);
      result = true;
      break;
    case FIELD_VECTOR:
      this->WriteVector(this, a2: pField->fieldName, a3: pData, a4: pField->fieldSize);
      result = true;
      break;
    case FIELD_QUATERNION:
      this->WriteQuaternion(this, a2: pField->fieldName, a3: (const Quaternion *)pData, a4: pField->fieldSize);
      result = true;
      break;
    case FIELD_INTEGER:
      this->WriteInt(this, a2: pField->fieldName, a3: (const int *)pData, a4: pField->fieldSize);
      result = true;
      break;
    case FIELD_BOOLEAN:
      this->WriteBool(this, a2: pField->fieldName, a3: (const bool *)pData, a4: pField->fieldSize);
      result = true;
      break;
    case FIELD_SHORT:
      this->WriteData(this, a2: pField->fieldName, a3: 2 * pField->fieldSize, a4: (const char *)pData);
      result = true;
      break;
    case FIELD_CHARACTER:
      this->WriteData(this, a2: pField->fieldName, a3: pField->fieldSize, a4: (const char *)pData);
      result = true;
      break;
    case FIELD_COLOR32:
      this->WriteData(this, a2: pField->fieldName, a3: 4 * pField->fieldSize, a4: (const char *)pData);
      result = true;
      break;
    case FIELD_EMBEDDED:
      v8 = (pField->flags & 0x40) == 0;
      nFieldCount = pField->fieldSize;
      if ( v8 )
        x_low = pData;
      else
        x_low = (const Vector *)LODWORD(pData->x);
      this->StartBlock_2(this, a2: pField->fieldName);
      for ( nFieldCounta = nFieldCount - 1; nFieldCounta >= 0; --nFieldCounta )
      {
        this->WriteAll(this, a2: x_low, a3: pField->td);
        x_low = (const Vector *)((char *)x_low + pField->fieldSizeInBytes);
      }
      this->EndBlock(this);
      result = true;
      break;
    case FIELD_CUSTOM:
      this->StartBlock_2(this, a2: pField->fieldName);
      pSaveRestoreOps = pField->pSaveRestoreOps;
      fieldInfo.pField = (void *)pData;
      v11 = (char *)pData - pField->fieldOffset;
      fieldInfo.pTypeDesc = pField;
      fieldInfo.pOwner = v11;
      pSaveRestoreOps->Save(this: pSaveRestoreOps, a2: &fieldInfo, a3: this);
      this->EndBlock(this);
      goto $LN16_9;
    case FIELD_INTEGER64:
$LN16_9:
      result = true;
      break;
    default:
      _Warning(a1: "Bad field type\n");
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10164970
// Name: private: int CSave::DoWriteAll(void const __near *,struct datamap_t __near *,struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSave::DoWriteAll(CSave *this, const void *pLeafObject, datamap_t *pLeafMap, datamap_t *pCurMap)
{
  int result; // eax

  if ( pCurMap->baseMap == nullptr )
    return this->WriteFields(
             this,
             a2: pCurMap->dataClassName,
             a3: pLeafObject,
             a4: pLeafMap,
             a5: pCurMap->dataDesc,
             a6: pCurMap->dataNumFields);
  result = CSave::DoWriteAll(this, pLeafObject, pLeafMap, pCurMap: pCurMap->baseMap);
  if ( result != 0 )
    return this->WriteFields(
             this,
             a2: pCurMap->dataClassName,
             a3: pLeafObject,
             a4: pLeafMap,
             a5: pCurMap->dataDesc,
             a6: pCurMap->dataNumFields);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101649C0
// Name: public: virtual void CSave::StartBlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::StartBlock(CSave *this)
{
  this->StartBlock_2(this, a2: prType);
}

//------------------------------------------------------------------------------
// Address: 0x101649D0
// Name: private: void CSave::BufferData(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSave::BufferData(CSave *this@<ecx>, const char *a2@<edi>, char *pdata, int size)
{
  CSaveRestoreSegment *m_pData; // esi
  CSaveRestoreSegment *v6; // eax
  int v7; // [esp-8h] [ebp-10h]

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    if ( size <= m_pData->bufferSize - m_pData->size )
    {
      memcpy(dst: (unsigned __int8 *)m_pData->pCurrentData, src: (unsigned __int8 *)pdata, count: size);
      m_pData->pCurrentData += size;
      m_pData->size += size;
      s_SaveOverflow = 0;
    }
    else
    {
      m_pData->size = m_pData->bufferSize;
      if ( (unsigned __int8)_Plat_IsInDebugSession() != 0 )
        __debugbreak();
      else
        _Error(this: (ISceneTokenProcessor *)&stru_1048B5D0, a2);
      v6 = this->m_pData;
      v7 = v6->bufferSize - v6->size;
      s_SaveOverflow += size;
      _Warning(a1: "Save/Restore overflow %d [%d, %d]!\n", s_SaveOverflow, v6->bufferSize, v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164A70
// Name: public: virtual void CSave::WriteTime(float const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteTime(CSave *this, const float *data, float count)
{
  float v3; // ebx
  int v4; // esi
  float v6; // xmm0_4

  v3 = count;
  v4 = 0;
  if ( SLODWORD(count) > 0 )
  {
    while ( 1 )
    {
      v6 = data[v4];
      if ( v6 == 0.0 )
        break;
      if ( v6 == -3.402823466385289e38 || v6 == 3.4028235e38 )
        goto LABEL_8;
      count = v6 - this->m_pGameInfo->levelInfo.time;
      if ( COERCE_FLOAT(LODWORD(count) & _mask__AbsFloat_) < 0.001 )
      {
        v6 = 0.001;
        goto LABEL_8;
      }
LABEL_9:
      this->WriteData_2(this, a2: (const char *)&count, a3: 4);
      if ( ++v4 >= SLODWORD(v3) )
        return;
    }
    v6 = -1.7014117e38;
LABEL_8:
    count = v6;
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164B30
// Name: public: virtual void CSave::WriteTick(int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteTick(CSave *this, const int *data, int count)
{
  int v3; // ebx
  int v5; // esi
  int v6; // eax
  int baseTick; // [esp+Ch] [ebp-4h]

  v3 = count;
  v5 = 0;
  for ( baseTick = (int)(float)((float)(this->m_pGameInfo->levelInfo.time / *(float *)(gpGlobals.m_Index + 28)) + 0.5);
        v5 < v3;
        ++v5 )
  {
    v6 = data[v5];
    if ( v6 == -1 )
      count = 2147483644;
    else
      count = v6 - baseTick;
    this->WriteData_2(this, a2: (const char *)&count, a3: 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164BA0
// Name: public: virtual void CSave::WriteEdictPtr(char const __near *,struct edict_t __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteEdictPtr(CSave *this, const char *pname, edict_t **ppEdict, int count)
{
  int i; // eax
  _DWORD v5[1024]; // [esp+0h] [ebp-1000h] BYREF

  for ( i = 0; i < count; v5[i++] = -1 )
  {
    if ( i >= 1024 )
      break;
  }
  this->WriteInt(this, a2: pname, a3: v5, a4: count);
}

//------------------------------------------------------------------------------
// Address: 0x10164BF0
// Name: public: virtual void CSave::WriteEdictPtr(struct edict_t __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteEdictPtr(CSave *this, edict_t **ppEdict, int count)
{
  int i; // eax
  _DWORD v4[1024]; // [esp+0h] [ebp-1000h] BYREF

  for ( i = 0; i < count; v4[i++] = -1 )
  {
    if ( i >= 1024 )
      break;
  }
  this->WriteInt_2(this, a2: v4, a3: count);
}

//------------------------------------------------------------------------------
// Address: 0x10164C40
// Name: public: virtual int CRestore::GetReadPos(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::GetReadPos(CRestore *this)
{
  return this->m_pData->size;
}

//------------------------------------------------------------------------------
// Address: 0x10164C50
// Name: public: virtual char const __near * CRestore::StringFromHeaderSymbol(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CRestore::StringFromHeaderSymbol(CRestore *this, int symbol)
{
  CSaveRestoreSegment *m_pData; // eax
  const char *result; // eax

  m_pData = this->m_pData;
  if ( symbol < 0 || symbol >= m_pData->tokenCount )
    return "<<illegal>>";
  result = m_pData->pTokens[symbol];
  if ( result == nullptr )
    return prType;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10164C80
// Name: private: void CRestore::ReadBasicField(struct SaveRestoreRecordHeader_t const __near &,void __near *,struct datamap_t __near *,struct typedescription_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRestore::ReadBasicField(
        CRestore *this,
        const SaveRestoreRecordHeader_t *header,
        Vector *pDest,
        datamap_t *pRootMap,
        typedescription_t *pField)
{
  float x; // ebx
  CRestore_vtbl *v7; // ebx
  int v8; // eax
  int v9; // eax
  int size; // ecx
  int v11; // ebx
  ISaveRestoreOps *pSaveRestoreOps; // ecx
  SaveRestoreFieldInfo_t fieldInfo; // [esp+Ch] [ebp-Ch] BYREF
  int nFieldCount; // [esp+20h] [ebp+8h]

  switch ( pField->fieldType )
  {
    case FIELD_FLOAT:
      this->ReadFloat(this, a2: (float *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_STRING:
      this->ReadString(this, a2: (const char **)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_VECTOR:
      this->ReadVector(this, a2: pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_QUATERNION:
      this->ReadQuaternion(this, a2: (Quaternion *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_INTEGER:
    case FIELD_COLOR32:
      this->ReadInt_2(this, a2: (int *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_BOOLEAN:
      this->ReadBool(this, a2: (bool *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_SHORT:
      this->ReadShort(this, a2: (__int16 *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_CHARACTER:
      this->ReadData(this, a2: (char *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_EMBEDDED:
      x = *(float *)&pDest;
      if ( (pField->flags & 0x40) == 0 || LODWORD(pDest->x) != 0 )
      {
        if ( (pField->flags & 0x40) != 0 )
          x = pDest->x;
        for ( nFieldCount = pField->fieldSize - 1; nFieldCount >= 0; --nFieldCount )
        {
          this->ReadAll(this, a2: (void *)LODWORD(x), a3: pField->td);
          LODWORD(x) += pField->fieldSizeInBytes;
        }
      }
      else
      {
        v7 = this->__vftable;
        v8 = this->GetReadPos(this);
        v7->SetReadPos(this, a2: header->size + v8);
        _Warning(
          a1: "Attempted to restore FIELD_EMBEDDEDBYREF %s but there is no destination memory\n",
          pField->fieldName);
      }
      break;
    case FIELD_CUSTOM:
      v9 = this->GetReadPos(this);
      size = header->size;
      fieldInfo.pField = (void *)pDest;
      v11 = size + v9;
      pSaveRestoreOps = pField->pSaveRestoreOps;
      fieldInfo.pOwner = (char *)pDest - pField->fieldOffset;
      fieldInfo.pTypeDesc = pField;
      pSaveRestoreOps->Restore(this: pSaveRestoreOps, a2: &fieldInfo, a3: this);
      this->SetReadPos(this, a2: v11);
      break;
    case FIELD_INTEGER64:
      return;
    default:
      _Warning(a1: "Bad field type\n");
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164EE0
// Name: private: struct typedescription_t __near * CRestore::FindField(char const __near *,struct typedescription_t __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
typedescription_t *__thiscall CRestore::FindField(
        CRestore *this,
        const char *pszFieldName,
        typedescription_t *pFields,
        int fieldCount,
        int *pCookie)
{
  int v6; // eax
  typedescription_t *v7; // ebx
  int i; // [esp+20h] [ebp+14h]

  if ( pszFieldName != nullptr && (i = 0, fieldCount > 0) )
  {
    while ( 1 )
    {
      v6 = *pCookie + 1;
      v7 = &pFields[*pCookie];
      *pCookie = v6;
      if ( v6 == fieldCount )
        *pCookie = 0;
      if ( _V_stricmp(s1: v7->fieldName, s2: pszFieldName) == 0 )
        return v7;
      if ( ++i >= fieldCount )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    *pCookie = 0;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164F60
// Name: public: virtual void CRestore::EmptyFields(void __near *,struct typedescription_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRestore::EmptyFields(CRestore *this, char *pBaseData, typedescription_t *pFields, int fieldCount)
{
  ISaveRestoreOps **p_pSaveRestoreOps; // esi
  __int16 v5; // ax
  _DWORD *v6; // edi
  ISaveRestoreOps *v7; // ecx
  int i; // ebx
  SaveRestoreFieldInfo_t fieldInfo; // [esp+0h] [ebp-10h] BYREF
  CRestore *v10; // [esp+Ch] [ebp-4h]

  v10 = this;
  if ( fieldCount > 0 )
  {
    p_pSaveRestoreOps = &pFields->pSaveRestoreOps;
    do
    {
      v5 = *((_WORD *)p_pSaveRestoreOps - 3);
      if ( (v5 & 2) != 0 && (v10->m_global == 0 || (v5 & 1) == 0) )
      {
        v6 = (ISaveRestoreOps_vtbl **)((char *)&(*(p_pSaveRestoreOps - 3))->__vftable + (_DWORD)pBaseData);
        if ( *(p_pSaveRestoreOps - 5) == (ISaveRestoreOps *)10 )
        {
          if ( (*((_WORD *)p_pSaveRestoreOps - 3) & 0x40) == 0 || *v6 != 0 )
          {
            if ( (*((_WORD *)p_pSaveRestoreOps - 3) & 0x40) != 0 )
              v6 = (_DWORD *)*v6;
            for ( i = *((unsigned __int16 *)p_pSaveRestoreOps - 4) - 1; i >= 0; --i )
            {
              v10->EmptyFields(
                this: v10,
                a2: v6,
                a3: (typedescription_t *)p_pSaveRestoreOps[2]->__vftable,
                a4: (int)p_pSaveRestoreOps[2][1].__vftable);
              v6 = (_DWORD *)((char *)v6 + (_DWORD)p_pSaveRestoreOps[3]);
            }
          }
        }
        else if ( *(p_pSaveRestoreOps - 5) == (ISaveRestoreOps *)11 )
        {
          v7 = *p_pSaveRestoreOps;
          fieldInfo.pOwner = pBaseData;
          fieldInfo.pField = v6;
          fieldInfo.pTypeDesc = (typedescription_t *)(p_pSaveRestoreOps - 5);
          v7->MakeEmpty(this: v7, a2: &fieldInfo);
        }
        else
        {
          if ( p_pSaveRestoreOps[3] != (ISaveRestoreOps *)(gSizes[(_DWORD)*(p_pSaveRestoreOps - 5)]
                                                         * *((unsigned __int16 *)p_pSaveRestoreOps - 4)) )
            _Warning(
              a1: "WARNING! Field %s is using the wrong FIELD_ type!\nFix this or you'll see a crash.\n",
              (const char *)*(p_pSaveRestoreOps - 4));
          memset(
            dst: (int)v6,
            value: (unsigned __int8 *)(unsigned __int8)((*(p_pSaveRestoreOps - 5) != (ISaveRestoreOps *)13) - 1),
            count: gSizes[(_DWORD)*(p_pSaveRestoreOps - 5)] * *((unsigned __int16 *)p_pSaveRestoreOps - 4));
        }
      }
      p_pSaveRestoreOps += 15;
      --fieldCount;
    }
    while ( fieldCount != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165070
// Name: public: virtual void CRestore::StartBlock(char __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRestore::StartBlock(CRestore *this, char *szBlockName)
{
  char *v3; // eax
  int symbol; // [esp-4h] [ebp-Ch]
  SaveRestoreRecordHeader_t header; // [esp+4h] [ebp-4h] BYREF

  this->StartBlock_3(this, a2: &header);
  symbol = header.symbol;
  v3 = (char *)((int (__thiscall *)(CRestore *))this->StringFromHeaderSymbol)(a1: this);
  V_strncpy(pDest: szBlockName, pSrc: v3, maxLen: symbol);
}

//------------------------------------------------------------------------------
// Address: 0x101650B0
// Name: public: virtual void CRestore::StartBlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRestore::StartBlock(CRestore *this)
{
  char szBlockName[32]; // [esp+0h] [ebp-20h] BYREF

  this->StartBlock_2(this, a2: szBlockName);
}

//------------------------------------------------------------------------------
// Address: 0x101650D0
// Name: public: virtual int CRestore::ScanAheadForHammerID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ScanAheadForHammerID(CRestore *this)
{
  int v2; // ebx
  int v3; // edi
  CSaveRestoreSegment *m_pData; // ecx
  const char *v5; // eax
  bool v6; // zf
  CSaveRestoreSegment *v7; // eax
  int size; // ecx
  int v9; // ecx
  int v10; // edi
  char *pCurrentData; // edx
  CSaveRestoreSegment *v12; // esi
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int oldPosition; // [esp+Ch] [ebp-Ch]
  int iHammerID; // [esp+10h] [ebp-8h]
  SaveRestoreRecordHeader_t header; // [esp+14h] [ebp-4h] BYREF

  oldPosition = this->m_pData->size;
  iHammerID = -1;
  this->ReadShort_2(this);
  this->ReadShort_2(this);
  v2 = this->ReadInt(this);
  v3 = 0;
  if ( v2 > 0 )
  {
    while ( 1 )
    {
      this->ReadHeader(this, a2: &header);
      m_pData = this->m_pData;
      v5 = header.symbol >= m_pData->tokenCount ? "<<illegal>>" : m_pData->pTokens[header.symbol];
      v6 = _V_stricmp(s1: "m_iHammerID", s2: v5) == 0;
      v7 = this->m_pData;
      if ( v6 )
        break;
      size = header.size;
      v7->pCurrentData += header.size;
      v7->size += size;
      if ( ++v3 >= v2 )
        goto LABEL_12;
    }
    v9 = v7->size;
    v10 = v7->bufferSize - v9;
    if ( v10 != 0 )
    {
      if ( v10 >= 4 )
      {
        pCurrentData = v7->pCurrentData;
        iHammerID = *(_DWORD *)pCurrentData;
        v7->pCurrentData = pCurrentData + 4;
        v7->size = v9 + 4;
      }
      else
      {
        v7->size = v7->bufferSize;
      }
    }
  }
LABEL_12:
  v12 = this->m_pData;
  v13 = v12->size - oldPosition;
  v14 = v12->size;
  if ( v14 < v13 )
    v13 = v12->size;
  v15 = -v13;
  v12->pCurrentData += v15;
  v16 = v15 + v14;
  v12->size = v16;
  return iHammerID;
}

//------------------------------------------------------------------------------
// Address: 0x101651B0
// Name: public: virtual void CRestore::SkipEntityData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRestore::SkipEntityData(CRestore *this)
{
  int v2; // eax
  int i; // edi
  int size; // ecx
  CSaveRestoreSegment *m_pData; // eax
  SaveRestoreRecordHeader_t header; // [esp+4h] [ebp-4h] BYREF

  v2 = this->ReadInt(this);
  if ( v2 > 0 )
  {
    for ( i = v2; i != 0; --i )
    {
      this->ReadHeader(this, a2: &header);
      size = header.size;
      m_pData = this->m_pData;
      m_pData->pCurrentData += header.size;
      m_pData->size += size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101651F0
// Name: private: int CRestore::DoReadAll(void __near *,struct datamap_t __near *,struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::DoReadAll(CRestore *this, void *pLeafObject, datamap_t *pLeafMap, datamap_t *pCurMap)
{
  int result; // eax

  if ( pCurMap->baseMap == nullptr )
    return this->ReadFields(
             this,
             a2: pCurMap->dataClassName,
             a3: pLeafObject,
             a4: pLeafMap,
             a5: pCurMap->dataDesc,
             a6: pCurMap->dataNumFields);
  result = CRestore::DoReadAll(this, pLeafObject, pLeafMap, pCurMap: pCurMap->baseMap);
  if ( result != 0 )
    return this->ReadFields(
             this,
             a2: pCurMap->dataClassName,
             a3: pLeafObject,
             a4: pLeafMap,
             a5: pCurMap->dataDesc,
             a6: pCurMap->dataNumFields);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10165240
// Name: public: virtual void CRestore::ReadString(char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRestore::ReadString(CRestore *this, char *pDest, int nSizeDest, int nBytesAvailable)
{
  CSaveRestoreSegment *m_pData; // ecx
  char *pCurrentData; // ebx
  signed int v6; // eax
  int size; // edx
  signed int v8; // esi

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
    pCurrentData = m_pData->pCurrentData;
  else
    pCurrentData = nullptr;
  v6 = nBytesAvailable;
  if ( nBytesAvailable == 0 )
    v6 = strlen(pCurrentData) + 1;
  if ( m_pData != nullptr && m_pData->bufferSize != m_pData->size )
  {
    size = m_pData->size;
    v8 = m_pData->bufferSize - size;
    if ( v8 != 0 )
    {
      if ( v6 <= v8 )
      {
        m_pData->pCurrentData += v6;
        m_pData->size = v6 + size;
        goto LABEL_12;
      }
      m_pData->size = m_pData->bufferSize;
    }
    _Warning(a1: "Restore underflow!\n");
  }
LABEL_12:
  V_strncpy(pDest, pSrc: pCurrentData, maxLen: nSizeDest);
}

//------------------------------------------------------------------------------
// Address: 0x101652C0
// Name: public: virtual int CRestore::ReadString(char const __near * __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadString(CRestore *this, const char **pValue, int nElems, int nBytesAvailable)
{
  CSaveRestoreSegment *m_pData; // eax
  const char *pCurrentData; // esi
  int v6; // edi
  CSaveRestoreSegment *v7; // eax
  int size; // ecx
  int v9; // edx
  char *pLimit; // [esp+10h] [ebp-4h]

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
    pCurrentData = m_pData->pCurrentData;
  else
    pCurrentData = nullptr;
  v6 = 0;
  for ( pLimit = (char *)&pCurrentData[nBytesAvailable]; v6 < nElems; ++pCurrentData )
  {
    if ( pCurrentData >= pLimit )
      break;
    for ( pValue[v6] = *pCurrentData != 0 ? AllocPooledString(pszValue: pCurrentData) : nullptr;
          *pCurrentData != 0;
          ++pCurrentData )
    {
      ;
    }
    ++v6;
  }
  v7 = this->m_pData;
  if ( v7 == nullptr || v7->bufferSize == v7->size )
    return v6;
  size = v7->size;
  v9 = v7->bufferSize - size;
  if ( v9 == 0 )
  {
LABEL_17:
    _Warning(a1: "Restore underflow!\n");
    return v6;
  }
  if ( nBytesAvailable > v9 )
  {
    v7->size = v7->bufferSize;
    goto LABEL_17;
  }
  v7->pCurrentData += nBytesAvailable;
  v7->size = nBytesAvailable + size;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10165380
// Name: public: virtual int CRestore::ReadVector(class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadVector(CRestore *this, Vector *pValue)
{
  CSaveRestoreSegment *m_pData; // ecx

  m_pData = this->m_pData;
  if ( m_pData != nullptr
    && m_pData->bufferSize != m_pData->size
    && CSaveRestoreSegment::Read(this: m_pData, pOutput: (unsigned __int8 *)pValue, nBytes: 12) == 0 )
  {
    _Warning(a1: "Restore underflow!\n");
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101653C0
// Name: public: virtual int CRestore::ReadQuaternion(class Quaternion __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadQuaternion(CRestore *this, Quaternion *pValue)
{
  CSaveRestoreSegment *m_pData; // ecx

  m_pData = this->m_pData;
  if ( m_pData != nullptr
    && m_pData->bufferSize != m_pData->size
    && CSaveRestoreSegment::Read(this: m_pData, pOutput: (unsigned __int8 *)pValue, nBytes: 16) == 0 )
  {
    _Warning(a1: "Restore underflow!\n");
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10165400
// Name: public: virtual int CRestore::ReadTime(float __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __userpurge CRestore::ReadTime@<eax>(
        CRestore *this@<ecx>,
        int a2@<edi>,
        float *pValue,
        int count,
        int nBytesAvailable)
{
  unsigned int result; // eax
  int v6; // edx
  unsigned int v7; // esi
  float *v8; // ecx
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float baseTime; // [esp+0h] [ebp-4h]

  baseTime = this->m_pGameInfo->levelInfo.time;
  result = ((int (__thiscall *)(CRestore *, float *, int, int, int))this->ReadFloat)(
             a1: this,
             a2: pValue,
             a3: count,
             a4: nBytesAvailable,
             a5: a2);
  v6 = result - 1;
  if ( (int)(result - 1) >= 0 )
  {
    if ( (int)result >= 4 )
    {
      v7 = result >> 2;
      v8 = &pValue[v6 - 2];
      v6 -= 4 * (result >> 2);
      do
      {
        v9 = v8[2];
        if ( v9 == -1.701411733192644e38 )
        {
          v8[2] = 0.0;
        }
        else if ( v9 != -3.402823466385289e38 && v9 != 3.4028235e38 )
        {
          v8[2] = v9 + baseTime;
        }
        v10 = v8[1];
        if ( v10 == -1.701411733192644e38 )
        {
          v8[1] = 0.0;
        }
        else if ( v10 != -3.402823466385289e38 && v10 != 3.4028235e38 )
        {
          v8[1] = v10 + baseTime;
        }
        v11 = *v8;
        if ( *v8 == -1.701411733192644e38 )
        {
          *v8 = 0.0;
        }
        else if ( v11 != -3.402823466385289e38 && v11 != 3.4028235e38 )
        {
          *v8 = v11 + baseTime;
        }
        v12 = *(v8 - 1);
        if ( v12 == -1.701411733192644e38 )
        {
          *(v8 - 1) = 0.0;
        }
        else if ( v12 != -3.402823466385289e38 && v12 != 3.4028235e38 )
        {
          *(v8 - 1) = v12 + baseTime;
        }
        v8 -= 4;
        --v7;
      }
      while ( v7 != 0 );
    }
    for ( ; v6 >= 0; --v6 )
    {
      v13 = pValue[v6];
      if ( v13 == -1.701411733192644e38 )
      {
        pValue[v6] = 0.0;
      }
      else if ( v13 != -3.402823466385289e38 && v13 != 3.4028235e38 )
      {
        pValue[v6] = v13 + baseTime;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101655B0
// Name: public: virtual int CRestore::ReadTick(int __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadTick(CRestore *this, int *pValue, int count, int nBytesAvailable)
{
  int v4; // edi
  int result; // eax
  int i; // ecx
  int v7; // edx

  v4 = (int)(float)((float)((float)(this->m_pGameInfo->levelInfo.time + 0.1) / *(float *)(gpGlobals.m_Index + 28)) + 0.5);
  result = this->ReadInt_2(this, a2: pValue, a3: count, a4: nBytesAvailable);
  for ( i = result - 1; i >= 0; --i )
  {
    v7 = pValue[i];
    if ( v7 == 2147483644 )
      pValue[i] = -1;
    else
      pValue[i] = v4 + v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10165630
// Name: public: virtual int CRestore::ReadPositionVector(class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadPositionVector(CRestore *this, Vector *pValue)
{
  return this->ReadPositionVector(this, a2: pValue, a3: 1, a4: 12);
}

//------------------------------------------------------------------------------
// Address: 0x10165650
// Name: public: virtual int CEntitySaveUtils::GetEntityDependencyCount(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEntitySaveUtils::GetEntityDependencyCount(CEntitySaveUtils *this, C_BaseEntity *pEntity)
{
  return this->m_pLevelAdjacencyDependencyHash->GetPairCountForObject(
           this: this->m_pLevelAdjacencyDependencyHash,
           a2: pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x10165660
// Name: public: virtual int CEntitySaveUtils::GetEntityDependencies(class C_BaseEntity __near *,int,class C_BaseEntity __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEntitySaveUtils::GetEntityDependencies(
        CEntitySaveUtils *this,
        C_BaseEntity *pEntity,
        int nCount,
        C_BaseEntity **ppEntList)
{
  return this->m_pLevelAdjacencyDependencyHash->GetPairListForObject(
           this: this->m_pLevelAdjacencyDependencyHash,
           a2: pEntity,
           a3: nCount,
           a4: (void **)ppEntList);
}

//------------------------------------------------------------------------------
// Address: 0x10165670
// Name: public: virtual void CEntitySaveUtils::AddLevelTransitionSaveDependency(class C_BaseEntity __near *,class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntitySaveUtils::AddLevelTransitionSaveDependency(
        CEntitySaveUtils *this,
        C_BaseEntity *pEntity1,
        C_BaseEntity *pEntity2)
{
  if ( pEntity1 != pEntity2 )
    this->m_pLevelAdjacencyDependencyHash->AddObjectPair(
      this: this->m_pLevelAdjacencyDependencyHash,
      a2: pEntity1,
      a3: pEntity2);
}

//------------------------------------------------------------------------------
// Address: 0x10165690
// Name: class ISaveRestoreBlockHandler __near * GetEntitySaveRestoreBlockHandler(void)
// Source: json
//------------------------------------------------------------------------------
CEntitySaveRestoreBlockHandler *__cdecl GetEntitySaveRestoreBlockHandler()
{
  return &g_EntitySaveRestoreBlockHandler;
}

//------------------------------------------------------------------------------
// Address: 0x101656A0
// Name: public: virtual char const __near * CEntitySaveRestoreBlockHandler::GetBlockName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CEntitySaveRestoreBlockHandler::GetBlockName(CEntitySaveRestoreBlockHandler *this)
{
  return "Entities";
}

//------------------------------------------------------------------------------
// Address: 0x101656B0
// Name: public: virtual void CEntitySaveRestoreBlockHandler::WriteSaveHeaders(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntitySaveRestoreBlockHandler::WriteSaveHeaders(CEntitySaveRestoreBlockHandler *this, ISave *pSave)
{
  CGameSaveRestoreInfo *v3; // eax
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  CGameSaveRestoreInfo *v5; // edi
  int v6; // ebx
  int nEntities; // [esp+Ch] [ebp-4h] BYREF
  ISave *pSavea; // [esp+18h] [ebp+8h]

  v3 = pSave->GetGameSaveRestoreInfo(this: pSave);
  WriteInt_2 = pSave->WriteInt_2;
  v5 = v3;
  nEntities = v3->tableCount;
  WriteInt_2(this: pSave, a2: &nEntities, a3: 1);
  v6 = 0;
  if ( v5->tableCount > 0 )
  {
    pSavea = nullptr;
    do
    {
      pSave->WriteFields(
        this: pSave,
        a2: "ETABLE",
        a3: (char *)pSavea + (unsigned int)v5->pTable,
        a4: nullptr,
        a5: entitytable_t::m_DataMap.dataDesc,
        a6: entitytable_t::m_DataMap.dataNumFields);
      pSavea += 14;
      ++v6;
    }
    while ( v6 < v5->tableCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165730
// Name: public: virtual void CEntitySaveRestoreBlockHandler::PostSave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntitySaveRestoreBlockHandler::PostSave(CEntitySaveRestoreBlockHandler *this)
{
  physics->DestroyObjectPairHash(this: physics, a2: this->m_EntitySaveUtils.m_pLevelAdjacencyDependencyHash);
  this->m_EntitySaveUtils.m_pLevelAdjacencyDependencyHash = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10165750
// Name: private: int CRestore::ReadSimple<short>(short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CRestore::ReadSimple<short>(CRestore *this, __int16 *pValue, int nElems, int nBytesAvailable)
{
  unsigned int v5; // ebx
  CSaveRestoreSegment *m_pData; // ecx
  CSaveRestoreSegment *v7; // eax
  int v8; // esi
  int size; // ecx
  int v10; // edx

  v5 = 2 * nElems;
  if ( nBytesAvailable != 0 && 2 * nElems >= nBytesAvailable )
    v5 = nBytesAvailable;
  m_pData = this->m_pData;
  if ( m_pData != nullptr
    && m_pData->bufferSize != m_pData->size
    && CSaveRestoreSegment::Read(this: m_pData, pOutput: (unsigned __int8 *)pValue, nBytes: v5) == 0 )
  {
    _Warning(a1: "Restore underflow!\n");
  }
  if ( (int)v5 >= nBytesAvailable )
    return v5 >> 1;
  v7 = this->m_pData;
  v8 = nBytesAvailable - v5;
  if ( v7 == nullptr || v7->bufferSize == v7->size )
    return v5 >> 1;
  size = v7->size;
  v10 = v7->bufferSize - size;
  if ( v10 == 0 )
  {
LABEL_14:
    _Warning(a1: "Restore underflow!\n");
    return v5 >> 1;
  }
  if ( v8 > v10 )
  {
    v7->size = v7->bufferSize;
    goto LABEL_14;
  }
  v7->pCurrentData += v8;
  v7->size = v8 + size;
  return v5 >> 1;
}

//------------------------------------------------------------------------------
// Address: 0x101657F0
// Name: private: int CRestore::ReadSimple<bool>(bool __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadSimple<bool>(CRestore *this, char *pValue, int nElems, int nBytesAvailable)
{
  int v4; // edi
  CSaveRestoreSegment *m_pData; // ecx
  CSaveRestoreSegment *v7; // eax
  int v8; // esi
  int size; // ecx
  int v10; // edx

  v4 = nElems;
  if ( nBytesAvailable != 0 && nElems >= nBytesAvailable )
    v4 = nBytesAvailable;
  m_pData = this->m_pData;
  if ( m_pData != nullptr
    && m_pData->bufferSize != m_pData->size
    && CSaveRestoreSegment::Read(this: m_pData, pOutput: (unsigned __int8 *)pValue, nBytes: v4) == 0 )
  {
    _Warning(a1: "Restore underflow!\n");
  }
  if ( v4 >= nBytesAvailable )
    return v4;
  v7 = this->m_pData;
  v8 = nBytesAvailable - v4;
  if ( v7 == nullptr || v7->bufferSize == v7->size )
    return v4;
  size = v7->size;
  v10 = v7->bufferSize - size;
  if ( v10 == 0 )
  {
LABEL_14:
    _Warning(a1: "Restore underflow!\n");
    return v4;
  }
  if ( v8 > v10 )
  {
    v7->size = v7->bufferSize;
    goto LABEL_14;
  }
  v7->pCurrentData += v8;
  v7->size = v8 + size;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10165890
// Name: private: int CRestore::ReadSimple<int>(int __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CRestore::ReadSimple<int>(CRestore *this, float *pValue, int nElems, int nBytesAvailable)
{
  unsigned int v5; // ebx
  CSaveRestoreSegment *m_pData; // ecx
  CSaveRestoreSegment *v7; // eax
  int v8; // esi
  int size; // ecx
  int v10; // edx

  v5 = 4 * nElems;
  if ( nBytesAvailable != 0 && 4 * nElems >= nBytesAvailable )
    v5 = nBytesAvailable;
  m_pData = this->m_pData;
  if ( m_pData != nullptr
    && m_pData->bufferSize != m_pData->size
    && CSaveRestoreSegment::Read(this: m_pData, pOutput: (unsigned __int8 *)pValue, nBytes: v5) == 0 )
  {
    _Warning(a1: "Restore underflow!\n");
  }
  if ( (int)v5 >= nBytesAvailable )
    return v5 >> 2;
  v7 = this->m_pData;
  v8 = nBytesAvailable - v5;
  if ( v7 == nullptr || v7->bufferSize == v7->size )
    return v5 >> 2;
  size = v7->size;
  v10 = v7->bufferSize - size;
  if ( v10 == 0 )
  {
LABEL_14:
    _Warning(a1: "Restore underflow!\n");
    return v5 >> 2;
  }
  if ( v8 > v10 )
  {
    v7->size = v7->bufferSize;
    goto LABEL_14;
  }
  v7->pCurrentData += v8;
  v7->size = v8 + size;
  return v5 >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x10165930
// Name: private: int CRestore::ReadSimple<class Vector>(class Vector __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CRestore::ReadSimple<Vector>(CRestore *this, Vector *pValue, int nElems, int nBytesAvailable)
{
  unsigned int v5; // ebx
  CSaveRestoreSegment *m_pData; // ecx
  CSaveRestoreSegment *v7; // eax
  int v8; // esi
  int size; // ecx
  int v10; // edx

  v5 = 12 * nElems;
  if ( nBytesAvailable != 0 && 12 * nElems >= nBytesAvailable )
    v5 = nBytesAvailable;
  m_pData = this->m_pData;
  if ( m_pData != nullptr
    && m_pData->bufferSize != m_pData->size
    && CSaveRestoreSegment::Read(this: m_pData, pOutput: (unsigned __int8 *)pValue, nBytes: v5) == 0 )
  {
    _Warning(a1: "Restore underflow!\n");
  }
  if ( (int)v5 >= nBytesAvailable )
    return v5 / 0xC;
  v7 = this->m_pData;
  v8 = nBytesAvailable - v5;
  if ( v7 == nullptr || v7->bufferSize == v7->size )
    return v5 / 0xC;
  size = v7->size;
  v10 = v7->bufferSize - size;
  if ( v10 == 0 )
  {
LABEL_14:
    _Warning(a1: "Restore underflow!\n");
    return v5 / 0xC;
  }
  if ( v8 > v10 )
  {
    v7->size = v7->bufferSize;
    goto LABEL_14;
  }
  v7->pCurrentData += v8;
  v7->size = v8 + size;
  return v5 / 0xC;
}

//------------------------------------------------------------------------------
// Address: 0x101659E0
// Name: private: int CRestore::ReadSimple<class Quaternion>(class Quaternion __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CRestore::ReadSimple<Quaternion>(
        CRestore *this,
        Quaternion *pValue,
        int nElems,
        int nBytesAvailable)
{
  unsigned int v5; // ebx
  CSaveRestoreSegment *m_pData; // ecx
  CSaveRestoreSegment *v7; // eax
  int v8; // esi
  int size; // ecx
  int v10; // edx

  v5 = 16 * nElems;
  if ( nBytesAvailable != 0 && 16 * nElems >= nBytesAvailable )
    v5 = nBytesAvailable;
  m_pData = this->m_pData;
  if ( m_pData != nullptr
    && m_pData->bufferSize != m_pData->size
    && CSaveRestoreSegment::Read(this: m_pData, pOutput: (unsigned __int8 *)pValue, nBytes: v5) == 0 )
  {
    _Warning(a1: "Restore underflow!\n");
  }
  if ( (int)v5 >= nBytesAvailable )
    return v5 >> 4;
  v7 = this->m_pData;
  v8 = nBytesAvailable - v5;
  if ( v7 == nullptr || v7->bufferSize == v7->size )
    return v5 >> 4;
  size = v7->size;
  v10 = v7->bufferSize - size;
  if ( v10 == 0 )
  {
LABEL_14:
    _Warning(a1: "Restore underflow!\n");
    return v5 >> 4;
  }
  if ( v8 > v10 )
  {
    v7->size = v7->bufferSize;
    goto LABEL_14;
  }
  v7->pCurrentData += v8;
  v7->size = v8 + size;
  return v5 >> 4;
}

//------------------------------------------------------------------------------
// Address: 0x10165A80
// Name: private: int CRestore::ReadSimple<class VMatrix>(class VMatrix __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CRestore::ReadSimple<VMatrix>(CRestore *this, VMatrix *pValue, int nElems, int nBytesAvailable)
{
  unsigned int v5; // ebx
  CSaveRestoreSegment *m_pData; // ecx
  CSaveRestoreSegment *v7; // eax
  int v8; // esi
  int size; // ecx
  int v10; // edx

  v5 = nElems << 6;
  if ( nBytesAvailable != 0 && nElems << 6 >= nBytesAvailable )
    v5 = nBytesAvailable;
  m_pData = this->m_pData;
  if ( m_pData != nullptr
    && m_pData->bufferSize != m_pData->size
    && CSaveRestoreSegment::Read(this: m_pData, pOutput: (unsigned __int8 *)pValue, nBytes: v5) == 0 )
  {
    _Warning(a1: "Restore underflow!\n");
  }
  if ( (int)v5 >= nBytesAvailable )
    return v5 >> 6;
  v7 = this->m_pData;
  v8 = nBytesAvailable - v5;
  if ( v7 == nullptr || v7->bufferSize == v7->size )
    return v5 >> 6;
  size = v7->size;
  v10 = v7->bufferSize - size;
  if ( v10 == 0 )
  {
LABEL_14:
    _Warning(a1: "Restore underflow!\n");
    return v5 >> 6;
  }
  if ( v8 > v10 )
  {
    v7->size = v7->bufferSize;
    goto LABEL_14;
  }
  v7->pCurrentData += v8;
  v7->size = v8 + size;
  return v5 >> 6;
}

//------------------------------------------------------------------------------
// Address: 0x10165B20
// Name: private: int CRestore::ReadSimple<struct interval_t>(struct interval_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CRestore::ReadSimple<interval_t>(
        CRestore *this,
        interval_t *pValue,
        int nElems,
        int nBytesAvailable)
{
  unsigned int v5; // ebx
  CSaveRestoreSegment *m_pData; // ecx
  CSaveRestoreSegment *v7; // eax
  int v8; // esi
  int size; // ecx
  int v10; // edx

  v5 = 8 * nElems;
  if ( nBytesAvailable != 0 && 8 * nElems >= nBytesAvailable )
    v5 = nBytesAvailable;
  m_pData = this->m_pData;
  if ( m_pData != nullptr
    && m_pData->bufferSize != m_pData->size
    && CSaveRestoreSegment::Read(this: m_pData, pOutput: (unsigned __int8 *)pValue, nBytes: v5) == 0 )
  {
    _Warning(a1: "Restore underflow!\n");
  }
  if ( (int)v5 >= nBytesAvailable )
    return v5 >> 3;
  v7 = this->m_pData;
  v8 = nBytesAvailable - v5;
  if ( v7 == nullptr || v7->bufferSize == v7->size )
    return v5 >> 3;
  size = v7->size;
  v10 = v7->bufferSize - size;
  if ( v10 == 0 )
  {
LABEL_14:
    _Warning(a1: "Restore underflow!\n");
    return v5 >> 3;
  }
  if ( v8 > v10 )
  {
    v7->size = v7->bufferSize;
    goto LABEL_14;
  }
  v7->pCurrentData += v8;
  v7->size = v8 + size;
  return v5 >> 3;
}

//------------------------------------------------------------------------------
// Address: 0x10165BD0
// Name: public: unsigned short CSaveRestoreSegment::FindCreateSymbol(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestoreSegment::FindCreateSymbol(CSaveRestoreSegment *this, const char *pszToken)
{
  const char *v2; // ebx
  char v3; // dl
  unsigned int v4; // eax
  const char *j; // esi
  int tokenCount; // esi
  int v7; // eax
  char **pTokens; // ecx
  int v9; // edi
  int result; // eax
  int v11; // [esp+Ch] [ebp-Ch]
  char **v12; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v2 = pszToken;
  v3 = *pszToken;
  v4 = 0;
  for ( j = pszToken; *j != 0; v3 = *j )
  {
    ++j;
    v4 = v3 ^ __ROR4__(v4, 4);
  }
  tokenCount = this->tokenCount;
  i = 0;
  v7 = (unsigned __int16)(v4 % tokenCount);
  if ( tokenCount <= 0 )
  {
LABEL_11:
    _Warning(a1: "CSaveRestoreBuffer::TokenHash() is COMPLETELY FULL!");
    return 0;
  }
  else
  {
    pTokens = this->pTokens;
    v12 = pTokens;
    v11 = v7;
    v9 = v7 - tokenCount;
    while ( 1 )
    {
      result = i + v7;
      if ( result >= tokenCount )
        result = v9;
      if ( pTokens[result] == nullptr )
        break;
      if ( strcmp(v2, pTokens[result]) == 0 )
      {
        v2 = pszToken;
        pTokens = v12;
        break;
      }
      ++v9;
      if ( ++i >= tokenCount )
        goto LABEL_11;
      v2 = pszToken;
      v7 = v11;
      pTokens = v12;
    }
    pTokens[result] = (char *)v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10165CA0
// Name: void UTIL_FunctionFromName(struct datamap_t __near *,char const __near *,void (CBaseEntity::*__near *)(struct inputdata_t __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_FunctionFromName(
        datamap_t *pMap,
        const char *pName,
        void (__thiscall **ppFunction)(CBaseEntity *this, struct inputdata_t *))
{
  const char *v3; // eax
  datamap_t *v4; // esi
  int v5; // edi
  int v6; // ebx

  v3 = pName;
  if ( pName != nullptr && *pName != 0 )
  {
    v4 = pMap;
    if ( pMap != nullptr )
    {
      while ( 1 )
      {
        v5 = 0;
        if ( v4->dataNumFields > 0 )
          break;
LABEL_9:
        v4 = v4->baseMap;
        if ( v4 == nullptr )
        {
          v3 = pName;
          goto LABEL_11;
        }
      }
      v6 = 0;
      while ( (v4->dataDesc[v6].flags & 0x20) == 0 || _V_stricmp(s1: pName, s2: v4->dataDesc[v6].fieldName) != 0 )
      {
        ++v5;
        ++v6;
        if ( v5 >= v4->dataNumFields )
          goto LABEL_9;
      }
      *ppFunction = v4->dataDesc[v5].inputFunc;
    }
    else
    {
LABEL_11:
      _Msg(a1: "Failed to find function %s\n", v3);
      *ppFunction = nullptr;
    }
  }
  else
  {
    *ppFunction = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165D40
// Name: public: virtual void CSave::WriteShort(short const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSave::WriteShort(CSave *this@<ecx>, const char *a2@<edi>, char *value, int count)
{
  CSave::BufferData(this, a2, pdata: value, size: 2 * count);
}

//------------------------------------------------------------------------------
// Address: 0x10165D60
// Name: public: virtual void CSave::WriteData(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSave::WriteData(CSave *this@<ecx>, const char *a2@<edi>, char *pdata, int size)
{
  CSave::BufferData(this, a2, pdata, size);
}

//------------------------------------------------------------------------------
// Address: 0x10165D70
// Name: public: virtual void CSave::WriteInt(int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSave::WriteInt(CSave *this@<ecx>, const char *a2@<edi>, float *value, int count)
{
  CSave::BufferData(this, a2, pdata: (char *)value, size: 4 * count);
}

//------------------------------------------------------------------------------
// Address: 0x10165D90
// Name: public: virtual void CSave::WriteString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteString(CSave *this, char *pstring)
{
  CSave::BufferData(this, a2: pstring + 1, pdata: pstring, size: strlen(pstring) + 1);
}

//------------------------------------------------------------------------------
// Address: 0x10165DC0
// Name: public: virtual void CSave::WriteString(char const __near * const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSave::WriteString(CSave *this@<ecx>, const char *a2@<edi>, const char *const *stringId, int count)
{
  CSaveRestoreSegment *m_pData; // esi
  signed int v5; // edi
  CSaveRestoreSegment *v6; // eax
  int v7; // [esp-10h] [ebp-18h]
  const char *v8; // [esp-Ch] [ebp-14h]
  int i; // [esp+4h] [ebp-4h]

  i = 0;
  if ( count > 0 )
  {
    v8 = a2;
    do
    {
      m_pData = this->m_pData;
      v5 = strlen(stringId[i]) + 1;
      if ( m_pData != nullptr )
      {
        if ( v5 <= m_pData->bufferSize - m_pData->size )
        {
          memcpy(dst: (unsigned __int8 *)m_pData->pCurrentData, src: (unsigned __int8 *)stringId[i], count: v5);
          m_pData->pCurrentData += v5;
          m_pData->size += v5;
          s_SaveOverflow = 0;
        }
        else
        {
          m_pData->size = m_pData->bufferSize;
          if ( (unsigned __int8)_Plat_IsInDebugSession() != 0 )
            __debugbreak();
          else
            _Error(this: (ISceneTokenProcessor *)&stru_1048B5D0, a2: v8);
          v6 = this->m_pData;
          v7 = v6->bufferSize - v6->size;
          s_SaveOverflow += v5;
          _Warning(a1: "Save/Restore overflow %d [%d, %d]!\n", s_SaveOverflow, v6->bufferSize, v7);
        }
      }
      ++i;
    }
    while ( i < count );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165EA0
// Name: public: virtual void CSave::WriteVector(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSave::WriteVector(CSave *this@<ecx>, const char *a2@<edi>, const Vector *value)
{
  CSave::BufferData(this, a2, pdata: (char *)value, size: 12);
}

//------------------------------------------------------------------------------
// Address: 0x10165EC0
// Name: public: virtual void CSave::WriteVector(class Vector const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSave::WriteVector(CSave *this@<ecx>, const char *a2@<edi>, const Vector *value, int count)
{
  CSave::BufferData(this, a2, pdata: (char *)value, size: 12 * count);
}

//------------------------------------------------------------------------------
// Address: 0x10165EE0
// Name: public: virtual void CSave::WriteQuaternion(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSave::WriteQuaternion(CSave *this@<ecx>, const char *a2@<edi>, const Quaternion *value)
{
  CSave::BufferData(this, a2, pdata: (char *)value, size: 16);
}

//------------------------------------------------------------------------------
// Address: 0x10165F00
// Name: public: virtual void CSave::WriteQuaternion(class Quaternion const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSave::WriteQuaternion(CSave *this@<ecx>, const char *a2@<edi>, const Quaternion *value, int count)
{
  CSave::BufferData(this, a2, pdata: (char *)value, size: 16 * count);
}

//------------------------------------------------------------------------------
// Address: 0x10165F20
// Name: public: void CSave::WriteVMatrixWorldspace(class VMatrix const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteVMatrixWorldspace(CSave *this, const VMatrix *value, int count)
{
  int v3; // ebx
  CGameSaveRestoreInfo *m_pGameInfo; // eax
  Vector *p_vecLandmarkOffset; // eax
  __int64 v8; // xmm0_8
  float z; // eax
  VMatrix tmp; // [esp+8h] [ebp-58h] BYREF
  __int64 v11; // [esp+48h] [ebp-18h]
  float v12; // [esp+50h] [ebp-10h]
  float v13; // [esp+54h] [ebp-Ch]
  float v14; // [esp+58h] [ebp-8h]
  float v15; // [esp+5Ch] [ebp-4h]

  v3 = count;
  if ( count > 0 )
  {
    do
    {
      m_pGameInfo = this->m_pGameInfo;
      if ( m_pGameInfo->levelInfo.fUseLandmark != 0 )
        p_vecLandmarkOffset = &m_pGameInfo->levelInfo.vecLandmarkOffset;
      else
        p_vecLandmarkOffset = &vec3_origin;
      v8 = *(_QWORD *)&p_vecLandmarkOffset->x;
      z = p_vecLandmarkOffset->z;
      v11 = v8;
      v13 = -*(float *)&v8;
      LODWORD(v14) = HIDWORD(v8) ^ 0x80000000;
      v12 = z;
      v15 = -z;
      VMatrix::operator=(this: &tmp, mOther: value);
      tmp.m[0][3] = tmp.m[0][3] + v13;
      tmp.m[1][3] = tmp.m[1][3] + v14;
      tmp.m[2][3] = tmp.m[2][3] + v15;
      CSave::BufferData(this, a2: (const char *)this, pdata: (char *)&tmp, size: 64);
      ++value;
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165FF0
// Name: public: void CSave::WriteMatrix3x4Worldspace(struct matrix3x4_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteMatrix3x4Worldspace(CSave *this, const matrix3x4_t *value, const char *count)
{
  CGameSaveRestoreInfo *m_pGameInfo; // eax
  bool v4; // zf
  Vector *p_vecLandmarkOffset; // eax
  __int64 v6; // xmm0_8
  float z; // eax
  const char *v8; // edi
  const matrix3x4_t *v9; // esi
  matrix3x4_t tmp; // [esp+0h] [ebp-4Ch] BYREF
  Vector offset; // [esp+30h] [ebp-1Ch]
  Vector out; // [esp+3Ch] [ebp-10h] BYREF
  CSave *v13; // [esp+48h] [ebp-4h]

  m_pGameInfo = this->m_pGameInfo;
  v4 = m_pGameInfo->levelInfo.fUseLandmark == 0;
  v13 = this;
  if ( v4 )
    p_vecLandmarkOffset = &vec3_origin;
  else
    p_vecLandmarkOffset = &m_pGameInfo->levelInfo.vecLandmarkOffset;
  v6 = *(_QWORD *)&p_vecLandmarkOffset->x;
  z = p_vecLandmarkOffset->z;
  *(_QWORD *)&out.x = v6;
  *(_QWORD *)&offset.x = v6 ^ 0x8000000080000000uLL;
  v8 = count;
  out.z = z;
  offset.z = -z;
  if ( (int)count > 0 )
  {
    v9 = value;
    do
    {
      MatrixCopy(in: v9, out: &tmp);
      MatrixGetColumn(in: v9, column: 3, &out);
      out.x = out.x + offset.x;
      out.y = out.y + offset.y;
      out.z = out.z + offset.z;
      MatrixSetColumn(in: &out, column: 3, out: &tmp);
      CSave::BufferData(this: v13, a2: v8, pdata: (char *)value, size: 48);
      ++v9;
      --v8;
    }
    while ( v8 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101660D0
// Name: public: virtual void CSave::WriteTime(char const __near *,float const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteTime(CSave *this, const char *pname, const float *data, float count)
{
  int v4; // ebx
  const char *v6; // edi
  CSaveRestoreSegment *m_pData; // ecx
  int v8; // edi
  float v9; // xmm0_4
  char pdata[4]; // [esp+Ch] [ebp-4h] BYREF

  v4 = LODWORD(count);
  v6 = (const char *)(4 * LODWORD(count));
  m_pData = this->m_pData;
  *(_DWORD *)pdata = (unsigned __int16)(4 * LOWORD(count));
  pname = (const char *)(unsigned __int16)CSaveRestoreSegment::FindCreateSymbol(this: m_pData, pszToken: pname);
  if ( (unsigned int)v6 >= 0x8000 )
    _Warning(a1: "CSave::WriteHeader() size parameter exceeds 'short'!\n");
  CSave::BufferData(this, a2: v6, pdata, size: 2);
  CSave::BufferData(this, a2: v6, pdata: (char *)&pname, size: 2);
  v8 = 0;
  if ( v4 > 0 )
  {
    while ( 1 )
    {
      v9 = data[v8];
      if ( v9 == 0.0 )
        break;
      if ( v9 == -3.402823466385289e38 || v9 == 3.4028235e38 )
        goto LABEL_10;
      count = v9 - this->m_pGameInfo->levelInfo.time;
      if ( COERCE_FLOAT(LODWORD(count) & _mask__AbsFloat_) < 0.001 )
      {
        v9 = 0.001;
        goto LABEL_10;
      }
LABEL_11:
      this->WriteData_2(this, a2: (const char *)&count, a3: 4);
      if ( ++v8 >= v4 )
        return;
    }
    v9 = -1.7014117e38;
LABEL_10:
    count = v9;
    goto LABEL_11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101661E0
// Name: public: virtual void CSave::WriteTick(char const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteTick(CSave *this, const char *pname, const int *data, int count)
{
  int v4; // ebx
  const char *v6; // edi
  CSaveRestoreSegment *m_pData; // ecx

  v4 = count;
  v6 = (const char *)(4 * count);
  m_pData = this->m_pData;
  count = (unsigned __int16)(4 * count);
  pname = (const char *)(unsigned __int16)CSaveRestoreSegment::FindCreateSymbol(this: m_pData, pszToken: pname);
  if ( (unsigned int)v6 >= 0x8000 )
    _Warning(a1: "CSave::WriteHeader() size parameter exceeds 'short'!\n");
  CSave::BufferData(this, a2: v6, pdata: (char *)&count, size: 2);
  CSave::BufferData(this, a2: v6, pdata: (char *)&pname, size: 2);
  this->WriteTick(this, a2: data, a3: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10166260
// Name: public: virtual void CSave::WritePositionVector(char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WritePositionVector(CSave *this, const char *pname, const Vector *value)
{
  float z; // eax
  float v4; // xmm1_4
  CGameSaveRestoreInfo *m_pGameInfo; // eax
  Vector *p_vecLandmarkOffset; // eax
  float v7; // xmm2_4
  float v8; // [esp+8h] [ebp-10h]
  Vector tmp; // [esp+Ch] [ebp-Ch] BYREF

  z = value->z;
  *(_QWORD *)&tmp.x = *(_QWORD *)&value->x;
  tmp.z = z;
  v4 = z;
  if ( vec3_invalid.x != tmp.x || vec3_invalid.y != tmp.y || vec3_invalid.z != z )
  {
    m_pGameInfo = this->m_pGameInfo;
    if ( m_pGameInfo->levelInfo.fUseLandmark != 0 )
      p_vecLandmarkOffset = &m_pGameInfo->levelInfo.vecLandmarkOffset;
    else
      p_vecLandmarkOffset = &vec3_origin;
    v7 = tmp.y - p_vecLandmarkOffset->y;
    v8 = p_vecLandmarkOffset->z;
    tmp.x = tmp.x - p_vecLandmarkOffset->x;
    tmp.y = v7;
    tmp.z = v4 - v8;
  }
  this->WriteVector_2(this, a2: pname, a3: &tmp);
}

//------------------------------------------------------------------------------
// Address: 0x10166320
// Name: public: virtual void CSave::WritePositionVector(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WritePositionVector(CSave *this, const Vector *value)
{
  float z; // eax
  float v3; // xmm1_4
  CGameSaveRestoreInfo *m_pGameInfo; // eax
  Vector *p_vecLandmarkOffset; // eax
  float v6; // xmm2_4
  float v7; // [esp+8h] [ebp-10h]
  Vector tmp; // [esp+Ch] [ebp-Ch] BYREF

  z = value->z;
  *(_QWORD *)&tmp.x = *(_QWORD *)&value->x;
  tmp.z = z;
  v3 = z;
  if ( vec3_invalid.x != tmp.x || vec3_invalid.y != tmp.y || vec3_invalid.z != z )
  {
    m_pGameInfo = this->m_pGameInfo;
    if ( m_pGameInfo->levelInfo.fUseLandmark != 0 )
      p_vecLandmarkOffset = &m_pGameInfo->levelInfo.vecLandmarkOffset;
    else
      p_vecLandmarkOffset = &vec3_origin;
    v6 = tmp.y - p_vecLandmarkOffset->y;
    v7 = p_vecLandmarkOffset->z;
    tmp.x = tmp.x - p_vecLandmarkOffset->x;
    tmp.y = v6;
    tmp.z = v3 - v7;
  }
  this->WriteVector_4(this, a2: &tmp);
}

//------------------------------------------------------------------------------
// Address: 0x101663D0
// Name: public: virtual void CSave::WritePositionVector(char const __near *,class Vector const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WritePositionVector(CSave *this, const char *pname, const Vector *value, int count)
{
  int v4; // ebx
  unsigned int v6; // edi
  CSaveRestoreSegment *m_pData; // ecx

  v4 = count;
  v6 = 12 * count;
  m_pData = this->m_pData;
  count = (unsigned __int16)(12 * count);
  pname = (const char *)(unsigned __int16)CSaveRestoreSegment::FindCreateSymbol(this: m_pData, pszToken: pname);
  if ( v6 >= 0x8000 )
    _Warning(a1: "CSave::WriteHeader() size parameter exceeds 'short'!\n");
  CSave::BufferData(this, a2: (const char *)v6, pdata: (char *)&count, size: 2);
  CSave::BufferData(this, a2: (const char *)v6, pdata: (char *)&pname, size: 2);
  this->WritePositionVector(this, a2: value, a3: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10166450
// Name: public: virtual void CSave::WritePositionVector(class Vector const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WritePositionVector(CSave *this, const Vector *value, int count)
{
  int i; // ebx
  float z; // eax
  float v7; // xmm1_4
  CGameSaveRestoreInfo *m_pGameInfo; // eax
  Vector *p_vecLandmarkOffset; // eax
  float v10; // xmm2_4
  float v11; // [esp+Ch] [ebp-10h]
  Vector tmp; // [esp+10h] [ebp-Ch] BYREF

  if ( count > 0 )
  {
    for ( i = count; i != 0; --i )
    {
      z = value->z;
      *(_QWORD *)&tmp.x = *(_QWORD *)&value->x;
      tmp.z = z;
      v7 = z;
      if ( vec3_invalid.x != tmp.x || vec3_invalid.y != tmp.y || vec3_invalid.z != z )
      {
        m_pGameInfo = this->m_pGameInfo;
        if ( m_pGameInfo->levelInfo.fUseLandmark != 0 )
          p_vecLandmarkOffset = &m_pGameInfo->levelInfo.vecLandmarkOffset;
        else
          p_vecLandmarkOffset = &vec3_origin;
        v10 = tmp.y - p_vecLandmarkOffset->y;
        v11 = p_vecLandmarkOffset->z;
        tmp.x = tmp.x - p_vecLandmarkOffset->x;
        tmp.y = v10;
        tmp.z = v7 - v11;
      }
      this->WriteData_2(this, a2: (const char *)&tmp, a3: 12);
      ++value;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10166530
// Name: public: virtual void CRestore::ReadHeader(struct SaveRestoreRecordHeader_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRestore::ReadHeader(CRestore *this, SaveRestoreRecordHeader_t *pheader)
{
  CSaveRestoreSegment *m_pData; // eax
  int size; // ecx
  int v5; // edx

  if ( pheader != nullptr )
  {
    pheader->size = this->ReadShort_2(this);
    pheader->symbol = this->ReadShort_2(this);
    return;
  }
  m_pData = this->m_pData;
  if ( m_pData != nullptr && m_pData->bufferSize != m_pData->size )
  {
    size = m_pData->size;
    v5 = m_pData->bufferSize - size;
    if ( v5 != 0 )
    {
      if ( v5 >= 4 )
      {
        m_pData->pCurrentData += 4;
        m_pData->size = size + 4;
        return;
      }
      m_pData->size = m_pData->bufferSize;
    }
    _Warning(a1: "Restore underflow!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101665B0
// Name: public: virtual short CRestore::ReadShort(void)
// Source: json
//------------------------------------------------------------------------------
__int16 __thiscall CRestore::ReadShort(CRestore *this)
{
  CSaveRestoreSegment *m_pData; // ecx
  int bufferSize; // eax
  int size; // esi
  __int16 result; // ax
  __int16 *pCurrentData; // edx

  m_pData = this->m_pData;
  if ( m_pData == nullptr || m_pData->bufferSize == m_pData->size )
    return 0;
  bufferSize = m_pData->bufferSize;
  size = m_pData->size;
  if ( bufferSize == size )
  {
LABEL_6:
    _Warning(a1: "Restore underflow!\n");
    return 0;
  }
  if ( bufferSize - size < 2 )
  {
    m_pData->size = bufferSize;
    goto LABEL_6;
  }
  pCurrentData = (__int16 *)m_pData->pCurrentData;
  result = *pCurrentData;
  m_pData->size = size + 2;
  m_pData->pCurrentData = (char *)(pCurrentData + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10166620
// Name: public: virtual int CRestore::ReadInt(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadInt(CRestore *this)
{
  CSaveRestoreSegment *m_pData; // ecx
  int bufferSize; // eax
  int size; // esi
  int result; // eax
  int *pCurrentData; // edx

  m_pData = this->m_pData;
  if ( m_pData == nullptr || m_pData->bufferSize == m_pData->size )
    return 0;
  bufferSize = m_pData->bufferSize;
  size = m_pData->size;
  if ( bufferSize == size )
  {
LABEL_6:
    _Warning(a1: "Restore underflow!\n");
    return 0;
  }
  if ( bufferSize - size < 4 )
  {
    m_pData->size = bufferSize;
    goto LABEL_6;
  }
  pCurrentData = (int *)m_pData->pCurrentData;
  result = *pCurrentData;
  m_pData->size = size + 4;
  m_pData->pCurrentData = (char *)(pCurrentData + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10166680
// Name: public: virtual int CRestore::ReadShort(short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CRestore::ReadShort(CRestore *this, __int16 *pValue, int nElems, int nBytesAvailable)
{
  return CRestore::ReadSimple<short>(this, pValue, nElems, nBytesAvailable);
}

//------------------------------------------------------------------------------
// Address: 0x10166690
// Name: public: virtual int CRestore::ReadData(char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadData(CRestore *this, char *pData, int size, int nBytesAvailable)
{
  return CRestore::ReadSimple<bool>(this, pValue: pData, nElems: size, nBytesAvailable);
}

//------------------------------------------------------------------------------
// Address: 0x101666A0
// Name: public: virtual int CRestore::ReadInt(int __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CRestore::ReadInt(CRestore *this, float *pValue, int nElems, int nBytesAvailable)
{
  return CRestore::ReadSimple<int>(this, pValue, nElems, nBytesAvailable);
}

//------------------------------------------------------------------------------
// Address: 0x101666B0
// Name: public: virtual int CRestore::ReadVector(class Vector __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CRestore::ReadVector(CRestore *this, Vector *pValue, int nElems, int nBytesAvailable)
{
  return CRestore::ReadSimple<Vector>(this, pValue, nElems, nBytesAvailable);
}

//------------------------------------------------------------------------------
// Address: 0x101666C0
// Name: public: virtual int CRestore::ReadQuaternion(class Quaternion __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CRestore::ReadQuaternion(CRestore *this, Quaternion *pValue, int nElems, int nBytesAvailable)
{
  return CRestore::ReadSimple<Quaternion>(this, pValue, nElems, nBytesAvailable);
}

//------------------------------------------------------------------------------
// Address: 0x101666D0
// Name: public: virtual int CRestore::ReadVMatrix(class VMatrix __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CRestore::ReadVMatrix(CRestore *this, VMatrix *pValue, int nElems, int nBytesAvailable)
{
  return CRestore::ReadSimple<VMatrix>(this, pValue, nElems, nBytesAvailable);
}

//------------------------------------------------------------------------------
// Address: 0x101666E0
// Name: public: virtual int CRestore::ReadVMatrixWorldspace(class VMatrix __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadVMatrixWorldspace(CRestore *this, VMatrix *pValue, int nElems, int nBytesAvailable)
{
  CGameSaveRestoreInfo *m_pGameInfo; // eax
  bool v5; // zf
  Vector *p_vecLandmarkOffset; // eax
  __int64 v7; // xmm0_8
  int result; // eax
  float *v9; // esi
  int v10; // ebx
  CSaveRestoreSegment *m_pData; // edi
  int v12; // eax
  VMatrix tmp; // [esp+0h] [ebp-50h] BYREF
  Vector basePosition; // [esp+40h] [ebp-10h]
  CRestore *v15; // [esp+4Ch] [ebp-4h]

  m_pGameInfo = this->m_pGameInfo;
  v5 = m_pGameInfo->levelInfo.fUseLandmark == 0;
  v15 = this;
  if ( v5 )
    p_vecLandmarkOffset = &vec3_origin;
  else
    p_vecLandmarkOffset = &m_pGameInfo->levelInfo.vecLandmarkOffset;
  v7 = *(_QWORD *)&p_vecLandmarkOffset->x;
  basePosition.z = p_vecLandmarkOffset->z;
  result = nElems;
  *(_QWORD *)&basePosition.x = v7;
  if ( nElems > 0 )
  {
    v9 = &pValue->m[1][3];
    v10 = nElems;
    while ( 1 )
    {
      m_pData = this->m_pData;
      if ( m_pData != nullptr && m_pData->bufferSize != m_pData->size )
      {
        v12 = m_pData->bufferSize - m_pData->size;
        if ( v12 == 0 )
          goto LABEL_12;
        if ( v12 < 64 )
        {
          m_pData->size = m_pData->bufferSize;
LABEL_12:
          _Warning(a1: "Restore underflow!\n");
          goto LABEL_13;
        }
        tmp = *(VMatrix *)m_pData->pCurrentData;
        m_pData->pCurrentData += 64;
        m_pData->size += 64;
      }
LABEL_13:
      VMatrix::operator=(this: (VMatrix *)(v9 - 7), mOther: &tmp);
      *(v9 - 4) = basePosition.x + *(v9 - 4);
      *v9 = basePosition.y + *v9;
      v9[4] = v9[4] + basePosition.z;
      v9 += 16;
      if ( --v10 == 0 )
        return nElems;
      this = v15;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101667D0
// Name: public: virtual int CRestore::ReadMatrix3x4Worldspace(struct matrix3x4_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadMatrix3x4Worldspace(CRestore *this, matrix3x4_t *pValue, int nElems, int nBytesAvailable)
{
  CGameSaveRestoreInfo *m_pGameInfo; // eax
  bool v5; // zf
  Vector *p_vecLandmarkOffset; // eax
  __int64 v7; // xmm0_8
  int result; // eax
  int v10; // ebx
  CSaveRestoreSegment *m_pData; // esi
  int v12; // eax
  matrix3x4_t tmp; // [esp+0h] [ebp-4Ch] BYREF
  Vector basePosition; // [esp+30h] [ebp-1Ch]
  Vector out; // [esp+3Ch] [ebp-10h] BYREF
  CRestore *v16; // [esp+48h] [ebp-4h]

  m_pGameInfo = this->m_pGameInfo;
  v5 = m_pGameInfo->levelInfo.fUseLandmark == 0;
  v16 = this;
  if ( v5 )
    p_vecLandmarkOffset = &vec3_origin;
  else
    p_vecLandmarkOffset = &m_pGameInfo->levelInfo.vecLandmarkOffset;
  v7 = *(_QWORD *)&p_vecLandmarkOffset->x;
  basePosition.z = p_vecLandmarkOffset->z;
  result = nElems;
  *(_QWORD *)&basePosition.x = v7;
  if ( nElems > 0 )
  {
    v10 = nElems;
    while ( 1 )
    {
      m_pData = this->m_pData;
      if ( m_pData != nullptr && m_pData->bufferSize != m_pData->size )
      {
        v12 = m_pData->bufferSize - m_pData->size;
        if ( v12 == 0 )
          goto LABEL_12;
        if ( v12 < 48 )
        {
          m_pData->size = m_pData->bufferSize;
LABEL_12:
          _Warning(a1: "Restore underflow!\n");
          goto LABEL_13;
        }
        tmp = *(matrix3x4_t *)m_pData->pCurrentData;
        m_pData->pCurrentData += 48;
        m_pData->size += 48;
      }
LABEL_13:
      MatrixCopy(in: &tmp, out: pValue);
      MatrixGetColumn(in: &tmp, column: 3, &out);
      out.x = basePosition.x + out.x;
      out.y = basePosition.y + out.y;
      out.z = basePosition.z + out.z;
      MatrixSetColumn(in: &out, column: 3, out: pValue++);
      if ( --v10 == 0 )
        return nElems;
      this = v16;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101668E0
// Name: public: virtual int CRestore::ReadEntityPtr(class C_BaseEntity __near * __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadEntityPtr(CRestore *this, C_BaseEntity **ppEntity, int count, int nBytesAvailable)
{
  int v4; // edi
  int v6; // esi
  C_BaseEntity **v7; // edi
  int v8; // eax
  CGameSaveRestoreInfo *m_pGameInfo; // ecx
  int v10; // esi
  int tableCount; // edx
  int v12; // eax
  entitytable_t *pTable; // ecx
  IHandleEntity *m_pEntity; // eax
  unsigned int m_Index; // ecx
  _BYTE v17[4096]; // [esp+Ch] [ebp-1008h] BYREF
  int v18; // [esp+100Ch] [ebp-8h]
  int v19; // [esp+1010h] [ebp-4h]
  int v20; // [esp+1024h] [ebp+10h]

  v4 = count;
  v6 = this->ReadInt_2(this, a2: (int *)v17, a3: count, a4: nBytesAvailable);
  v19 = v6;
  if ( v6 > 0 )
  {
    v7 = ppEntity;
    v8 = v17 - (_BYTE *)ppEntity;
    v18 = v17 - (_BYTE *)ppEntity;
    v20 = v6;
    while ( 1 )
    {
      m_pGameInfo = this->m_pGameInfo;
      v10 = *(int *)((char *)v7 + v8);
      if ( m_pGameInfo == nullptr )
        goto LABEL_10;
      if ( v10 < 0 )
        goto LABEL_10;
      tableCount = m_pGameInfo->tableCount;
      v12 = 0;
      if ( tableCount <= 0 )
        goto LABEL_10;
      pTable = m_pGameInfo->pTable;
      while ( pTable->id != v10 )
      {
        ++v12;
        ++pTable;
        if ( v12 >= tableCount )
          goto LABEL_10;
      }
      m_Index = pTable->hEnt.m_Index;
      if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      else
LABEL_10:
        m_pEntity = nullptr;
      *v7++ = (C_BaseEntity *)m_pEntity;
      if ( --v20 == 0 )
        break;
      v8 = v18;
    }
    v6 = v19;
    v4 = count;
  }
  if ( v6 < v4 )
    memset(dst: (int)&ppEntity[v6], value: nullptr, count: 4 * (v4 - v6));
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101669C0
// Name: private: void CRestore::ReadGameField(struct SaveRestoreRecordHeader_t const __near &,void __near *,struct datamap_t __near *,struct typedescription_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRestore::ReadGameField(
        CRestore *this,
        const SaveRestoreRecordHeader_t *header,
        C_BaseEntity **pDest,
        datamap_t *pRootMap,
        typedescription_t *pField)
{
  int fieldSize; // edi
  void *v6; // esp
  int v7; // eax
  C_BaseEntity **v8; // esi
  int v9; // ebx
  int i; // edi
  int v11; // edi
  void *v12; // esp
  int v13; // eax
  C_BaseEntity **v14; // esi
  int v15; // ebx
  int j; // edi
  _BYTE v17[12]; // [esp+0h] [ebp-Ch] BYREF

  switch ( pField->fieldType )
  {
    case FIELD_CLASSPTR:
      this->ReadEntityPtr(this, a2: pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_EHANDLE:
      this->ReadEHandle(this, a2: (CHandle<C_BaseEntity> *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_EDICT:
      return;
    case FIELD_POSITION_VECTOR:
      this->ReadPositionVector(this, a2: (Vector *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_TIME:
      this->ReadTime(this, a2: (float *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_TICK:
      this->ReadTick(this, a2: (int *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_MODELNAME:
    case FIELD_SOUNDNAME:
      this->ReadString(this, a2: (const char **)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_FUNCTION:
      this->ReadFunction(
        this,
        a2: pRootMap,
        a3: (void (__thiscall **)(CBaseEntity *, struct inputdata_t *))pDest,
        a4: pField->fieldSize,
        a5: header->size);
      break;
    case FIELD_VMATRIX:
      this->ReadVMatrix(this, a2: (VMatrix *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_VMATRIX_WORLDSPACE:
      this->ReadVMatrixWorldspace(this, a2: (VMatrix *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_MATRIX3X4_WORLDSPACE:
      this->ReadMatrix3x4Worldspace(this, a2: (matrix3x4_t *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_INTERVAL:
      CRestore::ReadSimple<interval_t>(
        this,
        pValue: (interval_t *)pDest,
        nElems: pField->fieldSize,
        nBytesAvailable: header->size);
      break;
    case FIELD_MODELINDEX:
      fieldSize = pField->fieldSize;
      v6 = alloca((4 * fieldSize + 15) & 0xFFFF0);
      v7 = this->ReadString(this, a2: (const char **)v17, a3: fieldSize, a4: header->size);
      if ( v7 > 0 )
      {
        v8 = pDest;
        v9 = v17 - (_BYTE *)pDest;
        for ( i = v7; i != 0; --i )
        {
          if ( *(C_BaseEntity **)((char *)v8 + v9) != nullptr )
            *v8 = (C_BaseEntity *)modelinfo->GetModelIndex(this: modelinfo, a2: *(const char **)((char *)v8 + v9));
          else
            *v8 = (C_BaseEntity *)-1;
          ++v8;
        }
      }
      break;
    case FIELD_MATERIALINDEX:
      v11 = pField->fieldSize;
      v12 = alloca((4 * v11 + 15) & 0xFFFF0);
      v13 = this->ReadString(this, a2: (const char **)v17, a3: v11, a4: header->size);
      if ( v13 > 0 )
      {
        v14 = pDest;
        v15 = v17 - (_BYTE *)pDest;
        for ( j = v13; j != 0; --j )
        {
          if ( *(C_BaseEntity **)((char *)v14 + v15) != nullptr )
            *v14 = (C_BaseEntity *)GetMaterialIndex(pMaterialName: *(const char **)((char *)v14 + v15));
          else
            *v14 = nullptr;
          ++v14;
        }
      }
      break;
    default:
      _Warning(a1: "Bad field type\n");
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10166C90
// Name: public: virtual int CRestore::ReadPositionVector(class Vector __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __userpurge CRestore::ReadPositionVector@<eax>(
        CRestore *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        Vector *pValue,
        int count,
        int nBytesAvailable)
{
  CGameSaveRestoreInfo *m_pGameInfo; // eax
  Vector *p_vecLandmarkOffset; // eax
  unsigned int result; // eax
  int v9; // edx
  unsigned int v10; // esi
  float *p_z; // ecx
  float *v12; // ecx
  __int64 basePosition; // [esp+0h] [ebp-Ch]
  float basePosition_8; // [esp+8h] [ebp-4h]

  m_pGameInfo = this->m_pGameInfo;
  if ( m_pGameInfo->levelInfo.fUseLandmark != 0 )
    p_vecLandmarkOffset = &m_pGameInfo->levelInfo.vecLandmarkOffset;
  else
    p_vecLandmarkOffset = &vec3_origin;
  basePosition_8 = p_vecLandmarkOffset->z;
  basePosition = *(_QWORD *)&p_vecLandmarkOffset->x;
  result = ((int (__thiscall *)(CRestore *, Vector *, int, int, int, int))this->ReadVector)(
             a1: this,
             a2: pValue,
             a3: count,
             a4: nBytesAvailable,
             a5: a3,
             a6: a2);
  v9 = result - 1;
  if ( (int)(result - 1) >= 0 )
  {
    if ( (int)result >= 4 )
    {
      v10 = result >> 2;
      p_z = &pValue[v9 - 1].z;
      v9 -= 4 * (result >> 2);
      do
      {
        if ( vec3_invalid.x != p_z[1] || vec3_invalid.y != p_z[2] || vec3_invalid.z != p_z[3] )
        {
          p_z[1] = p_z[1] + *(float *)&basePosition;
          p_z[2] = p_z[2] + *((float *)&basePosition + 1);
          p_z[3] = basePosition_8 + p_z[3];
        }
        if ( vec3_invalid.x != *(p_z - 2) || vec3_invalid.y != *(p_z - 1) || vec3_invalid.z != *p_z )
        {
          *(p_z - 2) = *(p_z - 2) + *(float *)&basePosition;
          *(p_z - 1) = *(p_z - 1) + *((float *)&basePosition + 1);
          *p_z = basePosition_8 + *p_z;
        }
        if ( vec3_invalid.x != *(p_z - 5) || vec3_invalid.y != *(p_z - 4) || vec3_invalid.z != *(p_z - 3) )
        {
          *(p_z - 5) = *(p_z - 5) + *(float *)&basePosition;
          *(p_z - 4) = *(p_z - 4) + *((float *)&basePosition + 1);
          *(p_z - 3) = basePosition_8 + *(p_z - 3);
        }
        if ( vec3_invalid.x != *(p_z - 8) || vec3_invalid.y != *(p_z - 7) || vec3_invalid.z != *(p_z - 6) )
        {
          *(p_z - 8) = *(p_z - 8) + *(float *)&basePosition;
          *(p_z - 7) = *(p_z - 7) + *((float *)&basePosition + 1);
          *(p_z - 6) = *(p_z - 6) + basePosition_8;
        }
        p_z -= 12;
        --v10;
      }
      while ( v10 != 0 );
    }
    if ( v9 >= 0 )
    {
      v12 = &pValue[v9].z;
      do
      {
        if ( vec3_invalid.x != *(v12 - 2) || vec3_invalid.y != *(v12 - 1) || vec3_invalid.z != *v12 )
        {
          *(v12 - 2) = *(v12 - 2) + *(float *)&basePosition;
          *(v12 - 1) = *(v12 - 1) + *((float *)&basePosition + 1);
          *v12 = *v12 + basePosition_8;
        }
        v12 -= 3;
        --v9;
      }
      while ( v9 >= 0 );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10166F10
// Name: public: virtual int CRestore::ReadFunction(struct datamap_t __near *,void (CBaseEntity::*__near *)(struct inputdata_t __near &),int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadFunction(
        CRestore *this,
        datamap_t *pMap,
        void (__thiscall **pValue)(CBaseEntity *this, struct inputdata_t *),
        int count,
        int nBytesAvailable)
{
  CSaveRestoreSegment *m_pData; // eax
  const char *pCurrentData; // ebx
  int size; // ecx
  int v8; // edx

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
    pCurrentData = m_pData->pCurrentData;
  else
    pCurrentData = nullptr;
  if ( m_pData != nullptr && m_pData->bufferSize != m_pData->size )
  {
    size = m_pData->size;
    v8 = m_pData->bufferSize - size;
    if ( v8 != 0 )
    {
      if ( nBytesAvailable <= v8 )
      {
        m_pData->pCurrentData += nBytesAvailable;
        m_pData->size = nBytesAvailable + size;
        goto LABEL_10;
      }
      m_pData->size = m_pData->bufferSize;
    }
    _Warning(a1: "Restore underflow!\n");
  }
LABEL_10:
  UTIL_FunctionFromName(pMap, pName: pCurrentData, ppFunction: pValue);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10166F80
// Name: public: virtual void CEntitySaveRestoreBlockHandler::Save(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntitySaveRestoreBlockHandler::Save(CEntitySaveRestoreBlockHandler *this, ISave *pSave)
{
  ISave *v2; // edi
  CGameSaveRestoreInfo *v3; // ebx
  entitytable_t *v4; // esi
  unsigned int m_Index; // eax
  CEntInfo *v6; // ecx
  C_BaseEntity *m_pEntity; // edi
  int v8; // eax
  IMDLCache *cacheCriticalSection; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  v2 = pSave;
  v3 = pSave->GetGameSaveRestoreInfo(this: pSave);
  i = 0;
  if ( v3->tableCount > 0 )
  {
    v11 = 0;
    do
    {
      v4 = &v3->pTable[v11];
      v4->location = v2->GetWritePos(this: v2);
      v4->size = 0;
      m_Index = v4->hEnt.m_Index;
      if ( m_Index != -1 )
      {
        v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
        {
          m_pEntity = (C_BaseEntity *)v6->m_pEntity;
          if ( v6->m_pEntity != nullptr && m_pEntity->ObjectCaps(this: (C_BaseEntity *)v6->m_pEntity) >= 0 )
          {
            cacheCriticalSection = mdlcache;
            ((void (*)(void))mdlcache->BeginLock)();
            v3->m_pCurrentEntity = m_pEntity;
            m_pEntity->Save(this: m_pEntity, a2: pSave);
            v3->m_pCurrentEntity = nullptr;
            v8 = pSave->GetWritePos(this: pSave) - v4->location;
            v4->size = v8;
            v3->m_nEntityDataSize += v8;
            v4->classname = m_pEntity->m_iClassname;
            cacheCriticalSection->EndLock(this: cacheCriticalSection);
          }
          v2 = pSave;
        }
      }
      ++v11;
      ++i;
    }
    while ( i < v3->tableCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167090
// Name: public: virtual void CSave::WriteString(char const __near *,char const __near * const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteString(CSave *this, const char *pname, const char *const *stringId, int count)
{
  int v4; // ebx
  unsigned int v6; // esi
  int v7; // ecx
  unsigned int v8; // kr00_4
  CSave *v9; // [esp+Ch] [ebp-4h]

  v4 = count;
  v6 = 0;
  v7 = 0;
  v9 = this;
  if ( count > 0 )
  {
    do
    {
      v8 = strlen(stringId[v7++]);
      v6 += v8 + 1;
    }
    while ( v7 < count );
    this = v9;
  }
  count = (unsigned __int16)v6;
  pname = (const char *)(unsigned __int16)CSaveRestoreSegment::FindCreateSymbol(this: this->m_pData, pszToken: pname);
  if ( v6 >= 0x8000 )
    _Warning(a1: "CSave::WriteHeader() size parameter exceeds 'short'!\n");
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)&count, size: 2);
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)&pname, size: 2);
  this->WriteString_3(this, a2: stringId, a3: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10167130
// Name: public: virtual void CSave::WriteVector(char const __near *,class Vector const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteVector(CSave *this, const char *pname, const Vector *value, int count)
{
  unsigned int v5; // esi
  CSaveRestoreSegment *m_pData; // ecx

  v5 = 12 * count;
  m_pData = this->m_pData;
  count = (unsigned __int16)(12 * count);
  pname = (const char *)(unsigned __int16)CSaveRestoreSegment::FindCreateSymbol(this: m_pData, pszToken: pname);
  if ( v5 >= 0x8000 )
    _Warning(a1: "CSave::WriteHeader() size parameter exceeds 'short'!\n");
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)&count, size: 2);
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)&pname, size: 2);
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)value, size: v5);
}

//------------------------------------------------------------------------------
// Address: 0x101671A0
// Name: public: virtual void CSave::WriteQuaternion(char const __near *,class Quaternion const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteQuaternion(CSave *this, const char *pname, const Quaternion *value, int count)
{
  unsigned int v5; // esi
  CSaveRestoreSegment *m_pData; // ecx

  v5 = 16 * count;
  m_pData = this->m_pData;
  count = (unsigned __int16)(16 * count);
  pname = (const char *)(unsigned __int16)CSaveRestoreSegment::FindCreateSymbol(this: m_pData, pszToken: pname);
  if ( v5 >= 0x8000 )
    _Warning(a1: "CSave::WriteHeader() size parameter exceeds 'short'!\n");
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)&count, size: 2);
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)&pname, size: 2);
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)value, size: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10167210
// Name: public: void CSave::WriteVMatrix(char const __near *,class VMatrix const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteVMatrix(CSave *this, const char *pname, VMatrix *value, int count)
{
  unsigned int v5; // esi
  CSaveRestoreSegment *m_pData; // ecx

  v5 = count << 6;
  m_pData = this->m_pData;
  count = (unsigned __int16)((_WORD)count << 6);
  pname = (const char *)(unsigned __int16)CSaveRestoreSegment::FindCreateSymbol(this: m_pData, pszToken: pname);
  if ( v5 >= 0x8000 )
    _Warning(a1: "CSave::WriteHeader() size parameter exceeds 'short'!\n");
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)&count, size: 2);
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)&pname, size: 2);
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)value, size: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10167280
// Name: public: void CSave::WriteVMatrixWorldspace(char const __near *,class VMatrix const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteVMatrixWorldspace(CSave *this, const char *pname, const VMatrix *value, int count)
{
  int v4; // ebx
  unsigned int v6; // esi
  CSaveRestoreSegment *m_pData; // ecx

  v4 = count;
  v6 = count << 6;
  m_pData = this->m_pData;
  count = (unsigned __int16)((_WORD)count << 6);
  pname = (const char *)(unsigned __int16)CSaveRestoreSegment::FindCreateSymbol(this: m_pData, pszToken: pname);
  if ( v6 >= 0x8000 )
    _Warning(a1: "CSave::WriteHeader() size parameter exceeds 'short'!\n");
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)&count, size: 2);
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)&pname, size: 2);
  CSave::WriteVMatrixWorldspace(this, value, count: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101672F0
// Name: public: void CSave::WriteMatrix3x4Worldspace(char const __near *,struct matrix3x4_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteMatrix3x4Worldspace(CSave *this, const char *pname, const matrix3x4_t *value, int count)
{
  const char *v4; // ebx
  unsigned int v6; // esi
  CSaveRestoreSegment *m_pData; // ecx

  v4 = (const char *)count;
  v6 = 48 * count;
  m_pData = this->m_pData;
  count = (unsigned __int16)(48 * count);
  pname = (const char *)(unsigned __int16)CSaveRestoreSegment::FindCreateSymbol(this: m_pData, pszToken: pname);
  if ( v6 >= 0x8000 )
    _Warning(a1: "CSave::WriteHeader() size parameter exceeds 'short'!\n");
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)&count, size: 2);
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)&pname, size: 2);
  CSave::WriteMatrix3x4Worldspace(this, value, count: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10167360
// Name: public: void CSave::WriteInterval(char const __near *,struct interval_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteInterval(CSave *this, const char *pname, interval_t *value, int count)
{
  const char *v5; // edi
  CSaveRestoreSegment *m_pData; // ecx

  v5 = (const char *)(8 * count);
  m_pData = this->m_pData;
  count = (unsigned __int16)(8 * count);
  pname = (const char *)(unsigned __int16)CSaveRestoreSegment::FindCreateSymbol(this: m_pData, pszToken: pname);
  if ( (unsigned int)v5 >= 0x8000 )
    _Warning(a1: "CSave::WriteHeader() size parameter exceeds 'short'!\n");
  CSave::BufferData(this, a2: v5, pdata: (char *)&count, size: 2);
  CSave::BufferData(this, a2: v5, pdata: (char *)&pname, size: 2);
  CSave::BufferData(this, a2: v5, pdata: (char *)value, size: (int)v5);
}

//------------------------------------------------------------------------------
// Address: 0x101673D0
// Name: private: void CSave::BufferField(char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::BufferField(CSave *this, const char *pname, int size, char *pdata)
{
  const char *v4; // edi
  CSaveRestoreSegment *m_pData; // ecx

  v4 = (const char *)size;
  m_pData = this->m_pData;
  size = (unsigned __int16)size;
  pname = (const char *)(unsigned __int16)CSaveRestoreSegment::FindCreateSymbol(this: m_pData, pszToken: pname);
  if ( (unsigned int)v4 >= 0x8000 )
    _Warning(a1: "CSave::WriteHeader() size parameter exceeds 'short'!\n");
  CSave::BufferData(this, a2: v4, pdata: (char *)&size, size: 2);
  CSave::BufferData(this, a2: v4, pdata: (char *)&pname, size: 2);
  CSave::BufferData(this, a2: v4, pdata, size: (int)v4);
}

//------------------------------------------------------------------------------
// Address: 0x10167440
// Name: public: virtual void CSave::WriteFunction(struct datamap_t __near *,char const __near *,void (CBaseEntity::*const __near *)(struct inputdata_t __near &),int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteFunction(
        CSave *this,
        datamap_t *pRootMap,
        const char *pname,
        void (__thiscall **ppData)(CBaseEntity *this, struct inputdata_t *),
        int count)
{
  char *v6; // eax

  v6 = (char *)UTIL_FunctionToName(pMap: pRootMap, function: *ppData);
  if ( v6 == nullptr )
  {
    _Warning(a1: "Invalid function pointer in entity!\n");
    v6 = "BADFUNCTIONPOINTER";
  }
  CSave::BufferField(this, pname, size: strlen(v6) + 1, pdata: v6);
}

//------------------------------------------------------------------------------
// Address: 0x101674A0
// Name: private: bool CSave::WriteGameField(char const __near *,void __near *,struct datamap_t __near *,struct typedescription_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSave::WriteGameField(
        CSave *this,
        const char *pname,
        char *pData,
        datamap_t *pRootMap,
        typedescription_t *pField)
{
  typedescription_t *v5; // esi
  bool result; // al
  C_BaseEntity *v8; // eax
  const struct model_t *v9; // eax
  const char *v10; // eax
  const char *MaterialNameFromIndex; // eax
  C_BaseEntity *v12; // [esp-4h] [ebp-Ch]

  v5 = pField;
  switch ( pField->fieldType )
  {
    case FIELD_CLASSPTR:
      this->WriteEntityPtr_2(this, a2: pField->fieldName, a3: (C_BaseEntity **)pData, a4: pField->fieldSize);
      result = true;
      break;
    case FIELD_EHANDLE:
      this->WriteEHandle_2(this, a2: pField->fieldName, a3: (const CHandle<C_BaseEntity> *)pData, a4: pField->fieldSize);
      result = true;
      break;
    case FIELD_EDICT:
      this->WriteEdictPtr_2(this, a2: pField->fieldName, a3: (edict_t **)pData, a4: pField->fieldSize);
      result = true;
      break;
    case FIELD_POSITION_VECTOR:
      this->WritePositionVector_3(this, a2: pField->fieldName, a3: (const Vector *)pData, a4: pField->fieldSize);
      result = true;
      break;
    case FIELD_TIME:
      this->WriteTime_2(this, a2: pField->fieldName, a3: (const float *)pData, a4: pField->fieldSize);
      result = true;
      break;
    case FIELD_TICK:
      this->WriteTick_2(this, a2: pField->fieldName, a3: (const int *)pData, a4: pField->fieldSize);
      result = true;
      break;
    case FIELD_MODELNAME:
    case FIELD_SOUNDNAME:
      this->WriteString(this, a2: pField->fieldName, a3: (const char *const *)pData, a4: pField->fieldSize);
      result = true;
      break;
    case FIELD_FUNCTION:
      this->WriteFunction(
        this,
        a2: pRootMap,
        a3: pField->fieldName,
        a4: (void (__thiscall *const *)(CBaseEntity *, struct inputdata_t *))pData,
        a5: pField->fieldSize);
      result = true;
      break;
    case FIELD_VMATRIX:
      CSave::WriteVMatrix(this, pname: pField->fieldName, value: (VMatrix *)pData, count: pField->fieldSize);
      result = true;
      break;
    case FIELD_VMATRIX_WORLDSPACE:
      CSave::WriteVMatrixWorldspace(
        this,
        pname: pField->fieldName,
        value: (const VMatrix *)pData,
        count: pField->fieldSize);
      result = true;
      break;
    case FIELD_MATRIX3X4_WORLDSPACE:
      CSave::WriteMatrix3x4Worldspace(
        this,
        pname: pField->fieldName,
        value: (const matrix3x4_t *)pData,
        count: pField->fieldSize);
      result = true;
      break;
    case FIELD_INTERVAL:
      CSave::WriteInterval(this, pname: pField->fieldName, value: (interval_t *)pData, count: pField->fieldSize);
      result = true;
      break;
    case FIELD_MODELINDEX:
      v8 = *(C_BaseEntity **)pData;
      pData = nullptr;
      v9 = modelinfo->GetModel(this: modelinfo, a2: v8);
      if ( v9 != nullptr )
      {
        v10 = modelinfo->GetModelName(this: modelinfo, a2: v9);
        pData = (char *)AllocPooledString(pszValue: v10);
      }
      goto LABEL_10;
    case FIELD_MATERIALINDEX:
      v12 = *(C_BaseEntity **)pData;
      pData = nullptr;
      MaterialNameFromIndex = GetMaterialNameFromIndex(nIndex: (int)v12);
      if ( MaterialNameFromIndex != nullptr )
        pData = (char *)MaterialNameFromIndex;
LABEL_10:
      this->WriteString(this, a2: v5->fieldName, a3: (const char *const *)&pData, a4: v5->fieldSize);
      result = true;
      break;
    default:
      _Warning(a1: "Bad field type\n");
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10167720
// Name: public: virtual int CRestore::ReadFields(char const __near *,void __near *,struct datamap_t __near *,struct typedescription_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadFields(
        CRestore *this,
        const char *pname,
        char *pBaseData,
        datamap_t *pRootMap,
        typedescription_t *pFields,
        int fieldCount)
{
  int Symbol; // edi
  int v8; // edx
  CSaveRestoreSegment *v9; // eax
  const char *v10; // edi
  const char *v11; // ecx
  CSaveRestoreSegment *v12; // esi
  int v13; // eax
  int v14; // ecx
  int v15; // ecx
  void (__thiscall *EmptyFields)(struct CRestore *, void *, typedescription_t *, int); // edx
  int v18; // eax
  CSaveRestoreSegment *m_pData; // ecx
  const char *v20; // eax
  typedescription_t *Field; // eax
  __int16 flags; // cx
  C_BaseEntity **v23; // ecx
  CSaveRestoreSegment *v24; // eax
  int size; // edi
  int v26; // ecx
  int v27; // edx
  int searchCookie; // [esp+Ch] [ebp-8h] BYREF
  SaveRestoreRecordHeader_t header; // [esp+10h] [ebp-4h] BYREF
  const char *pnamea; // [esp+1Ch] [ebp+8h]

  this->ReadShort_2(this);
  Symbol = (unsigned __int16)CSaveRestoreSegment::FindCreateSymbol(this: this->m_pData, pszToken: pname);
  v8 = this->ReadShort_2(this);
  if ( v8 == Symbol )
  {
    EmptyFields = this->EmptyFields;
    lastName = Symbol;
    EmptyFields(this, a2: pBaseData, a3: pFields, a4: fieldCount);
    v18 = this->ReadInt(this);
    searchCookie = 0;
    if ( v18 <= 0 )
      return 1;
    pnamea = (const char *)v18;
    while ( 1 )
    {
      this->ReadHeader(this, a2: &header);
      m_pData = this->m_pData;
      if ( header.symbol >= m_pData->tokenCount )
        v20 = "<<illegal>>";
      else
        v20 = m_pData->pTokens[header.symbol];
      Field = CRestore::FindField(this, pszFieldName: v20, pFields, fieldCount, pCookie: &searchCookie);
      if ( Field != nullptr )
      {
        flags = Field->flags;
        if ( (flags & 2) != 0 && (this->m_global == 0 || (flags & 1) == 0) )
        {
          v23 = (C_BaseEntity **)&pBaseData[Field->fieldOffset];
          if ( Field->fieldType > FIELD_CUSTOM )
            CRestore::ReadGameField(this, &header, pDest: v23, pRootMap, pField: Field);
          else
            CRestore::ReadBasicField(this, &header, pDest: (Vector *)v23, pRootMap, pField: Field);
          goto LABEL_33;
        }
      }
      v24 = this->m_pData;
      size = header.size;
      if ( v24 != nullptr && v24->bufferSize != v24->size )
      {
        v26 = v24->size;
        v27 = v24->bufferSize - v26;
        if ( v27 != 0 )
        {
          if ( header.size <= v27 )
          {
            v24->pCurrentData += header.size;
            v24->size = size + v26;
            goto LABEL_33;
          }
          v24->size = v24->bufferSize;
        }
        _Warning(a1: "Restore underflow!\n");
      }
LABEL_33:
      if ( --pnamea == nullptr )
        return 1;
    }
  }
  v9 = this->m_pData;
  if ( lastName < 0 || lastName >= v9->tokenCount )
    v10 = "<<illegal>>";
  else
    v10 = v9->pTokens[lastName];
  if ( v8 < 0 || v8 >= v9->tokenCount )
    v11 = "<<illegal>>";
  else
    v11 = v9->pTokens[v8];
  if ( v9 != nullptr )
    v9 = (CSaveRestoreSegment *)v9->pCurrentData;
  _Msg(a1: "Expected %s found %s ( raw '%s' )! (prev: %s)\n", pname, v11, (const char *)v9, v10);
  _Msg(a1: "Field type name may have changed or inheritance graph changed, save file is suspect\n");
  v12 = this->m_pData;
  v13 = v12->size;
  v14 = 4;
  if ( v13 < 4 )
    v14 = v12->size;
  v15 = -v14;
  v12->pCurrentData += v15;
  v12->size = v15 + v13;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101678E0
// Name: public: int CUtlHash<struct CGameSaveRestoreInfo::CHashElement,class CGameSaveRestoreInfo::CHashFuncs,class CGameSaveRestoreInfo::CHashFuncs>::Count(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>::Count(
        CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs> *this)
{
  int m_Size; // edx
  int v2; // ebx
  int v3; // esi
  int v4; // edi
  int *p_m_Size; // eax
  unsigned int v6; // edx
  int count; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Buckets.m_Size;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  count = 0;
  if ( m_Size >= 2 )
  {
    p_m_Size = &this->m_Buckets.m_Memory.m_pMemory[1].m_Size;
    v6 = ((unsigned int)(m_Size - 2) >> 1) + 1;
    v2 = 2 * v6;
    do
    {
      v3 += *(p_m_Size - 5);
      v4 += *p_m_Size;
      p_m_Size += 10;
      --v6;
    }
    while ( v6 != 0 );
  }
  if ( v2 < this->m_Buckets.m_Size )
    count = this->m_Buckets.m_Memory.m_pMemory[v2].m_Size;
  return count + v4 + v3;
}

//------------------------------------------------------------------------------
// Address: 0x10167930
// Name: protected: bool CUtlHash<struct CGameSaveRestoreInfo::CHashElement,class CGameSaveRestoreInfo::CHashFuncs,class CGameSaveRestoreInfo::CHashFuncs>::DoFind(struct CGameSaveRestoreInfo::CHashElement const __near &,unsigned int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>::DoFind(
        CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs> *this,
        const CGameSaveRestoreInfo::CHashElement *src,
        unsigned int *pBucket,
        int *pIndex)
{
  unsigned int v5; // eax
  unsigned int v6; // edx
  unsigned int v7; // edx
  int m_Size; // ecx
  CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int> > *v9; // edx
  int v10; // eax
  const C_BaseEntity **p_pEntity; // edx

  v5 = Hash4(pKey: src);
  if ( this->m_bPowerOfTwo )
    v6 = v5 & this->m_ModMask;
  else
    v6 = v5 % this->m_Buckets.m_Size;
  *pBucket = v6;
  v7 = v6;
  m_Size = this->m_Buckets.m_Memory.m_pMemory[v7].m_Size;
  v9 = &this->m_Buckets.m_Memory.m_pMemory[v7];
  v10 = 0;
  if ( m_Size > 0 )
  {
    p_pEntity = &v9->m_Memory.m_pMemory->pEntity;
    do
    {
      if ( *p_pEntity == src->pEntity )
        break;
      ++v10;
      p_pEntity += 2;
    }
    while ( v10 < m_Size );
  }
  if ( v10 == m_Size )
    return 0;
  *pIndex = v10;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101679A0
// Name: public: void CGameSaveRestoreInfo::InitEntityTable(struct entitytable_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameSaveRestoreInfo::InitEntityTable(CGameSaveRestoreInfo *this, entitytable_t *pNewTable, int size)
{
  int v3; // esi
  int v4; // edi
  entitytable_t *v5; // eax

  this->pTable = pNewTable;
  v3 = 0;
  this->tableCount = size;
  if ( size > 0 )
  {
    v4 = 0;
    do
    {
      v5 = &this->pTable[v4];
      v5->id = -1;
      v5->edictindex = -1;
      v5->saveentityindex = -1;
      v5->restoreentityindex = -1;
      v5->location = 0;
      v5->size = 0;
      v5->flags = 0;
      v5->classname = nullptr;
      v5->globalname = nullptr;
      v5->landmarkModelSpace.x = 0.0;
      v5->landmarkModelSpace.y = 0.0;
      v5->landmarkModelSpace.z = 0.0;
      v5->modelname = nullptr;
      ++v3;
      v5->hEnt.m_Index = -1;
      ++v4;
    }
    while ( v3 < this->tableCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167A20
// Name: public: virtual void CSave::WriteData(char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteData(CSave *this, const char *pname, int size, char *pdata)
{
  CSave::BufferField(this, pname, size, pdata);
}

//------------------------------------------------------------------------------
// Address: 0x10167A30
// Name: public: virtual void CSave::WriteShort(char const __near *,short const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteShort(CSave *this, const char *pname, char *data, int count)
{
  CSave::BufferField(this, pname, size: 2 * count, pdata: data);
}

//------------------------------------------------------------------------------
// Address: 0x10167A50
// Name: public: virtual void CSave::WriteBool(char const __near *,bool const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteBool(CSave *this, const char *pname, bool *data, int count)
{
  CSave::BufferField(this, pname, size: count, pdata: (char *)data);
}

//------------------------------------------------------------------------------
// Address: 0x10167A70
// Name: public: virtual void CSave::WriteInt(char const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteInt(CSave *this, const char *pname, float *data, int count)
{
  CSave::BufferField(this, pname, size: 4 * count, pdata: (char *)data);
}

//------------------------------------------------------------------------------
// Address: 0x10167A90
// Name: public: virtual void CSave::WriteString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteString(CSave *this, const char *pname, char *pdata)
{
  CSave::BufferField(this, pname, size: strlen(pdata) + 1, pdata);
}

//------------------------------------------------------------------------------
// Address: 0x10167AC0
// Name: public: virtual int CSave::WriteFields(char const __near *,void const __near *,struct datamap_t __near *,struct typedescription_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSave::WriteFields(
        CSave *this,
        const char *pname,
        char *pBaseData,
        datamap_t *pRootMap,
        typedescription_t *pFields,
        int fieldCount)
{
  void (__thiscall *WriteInt)(struct CSave *, const char *, const int *, int); // edx
  char *v9; // edi
  bool v10; // al
  CSaveRestoreSegment *m_pData; // eax
  int size; // edx
  int v13; // edi
  int v14; // ecx
  int v15; // ecx
  CSaveRestoreSegment *v16; // esi
  int v18; // edi
  int iHeaderPos; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  int count; // [esp+14h] [ebp-4h] BYREF

  WriteInt = this->WriteInt;
  iHeaderPos = this->m_pData->size;
  count = -1;
  WriteInt(this, a2: pname, a3: &count, a4: 1);
  count = 0;
  for ( i = 0; i < fieldCount; ++i )
  {
    v9 = &pBaseData[pFields->fieldOffset];
    if ( CSave::ShouldSaveField(this, pData: v9, pField: (int)pFields) )
    {
      if ( pFields->fieldType > FIELD_CUSTOM )
        v10 = CSave::WriteGameField(this, pname, pData: v9, pRootMap, pField: pFields);
      else
        v10 = CSave::WriteBasicField(this, pname, pData: (const Vector *)v9, pRootMap, pField: pFields);
      if ( !v10 )
        break;
      ++count;
    }
    ++pFields;
  }
  m_pData = this->m_pData;
  size = m_pData->size;
  v13 = size - iHeaderPos;
  v14 = size - iHeaderPos;
  if ( size < size - iHeaderPos )
    v14 = m_pData->size;
  v15 = -v14;
  m_pData->pCurrentData += v15;
  m_pData->size = v15 + size;
  this->WriteInt(this, a2: pname, a3: &count, a4: 1);
  v16 = this->m_pData;
  v18 = iHeaderPos + v13 - v16->size;
  v16->pCurrentData += v18;
  v16->size += v18;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10167BA0
// Name: public: virtual int CRestore::ReadEHandle(class CHandle<class C_BaseEntity> __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadEHandle(CRestore *this, CHandle<C_BaseEntity> *pEHandle, int count, int nBytesAvailable)
{
  int v4; // edi
  int v6; // esi
  CHandle<C_BaseEntity> *v7; // edi
  int v8; // eax
  CGameSaveRestoreInfo *m_pGameInfo; // ecx
  int v10; // esi
  int tableCount; // edx
  int v12; // eax
  entitytable_t *pTable; // ecx
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // ecx
  _BYTE v17[4096]; // [esp+Ch] [ebp-1008h] BYREF
  int v18; // [esp+100Ch] [ebp-8h]
  int v19; // [esp+1010h] [ebp-4h]
  int v20; // [esp+1024h] [ebp+10h]

  v4 = count;
  v6 = this->ReadInt_2(this, a2: (int *)v17, a3: count, a4: nBytesAvailable);
  v19 = v6;
  if ( v6 > 0 )
  {
    v7 = pEHandle;
    v8 = v17 - (_BYTE *)pEHandle;
    v18 = v17 - (_BYTE *)pEHandle;
    v20 = v6;
    while ( 1 )
    {
      m_pGameInfo = this->m_pGameInfo;
      v10 = *(unsigned int *)((char *)&v7->m_Index + v8);
      if ( m_pGameInfo == nullptr )
        goto LABEL_10;
      if ( v10 < 0 )
        goto LABEL_10;
      tableCount = m_pGameInfo->tableCount;
      v12 = 0;
      if ( tableCount <= 0 )
        goto LABEL_10;
      pTable = m_pGameInfo->pTable;
      while ( pTable->id != v10 )
      {
        ++v12;
        ++pTable;
        if ( v12 >= tableCount )
          goto LABEL_10;
      }
      m_Index = pTable->hEnt.m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( m_pEntity != nullptr )
        v7->m_Index = m_pEntity->GetRefEHandle(this: m_pEntity)->m_Index;
      else
LABEL_10:
        v7->m_Index = -1;
      ++v7;
      if ( --v20 == 0 )
        break;
      v8 = v18;
    }
    v4 = count;
    v6 = v19;
  }
  if ( v6 < v4 )
    memset(dst: (int)&pEHandle[v6], value: (unsigned __int8 *)0xFF, count: 4 * (v4 - v6));
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10167CA0
// Name: public: virtual void CEntitySaveRestoreBlockHandler::ReadRestoreHeaders(class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntitySaveRestoreBlockHandler::ReadRestoreHeaders(
        CEntitySaveRestoreBlockHandler *this,
        IRestore *pRestore)
{
  CGameSaveRestoreInfo *v3; // edi
  entitytable_t *v4; // eax
  int v5; // ebx
  int nEntities; // [esp+Ch] [ebp-4h] BYREF
  IRestore *pRestorea; // [esp+18h] [ebp+8h]

  v3 = pRestore->GetGameSaveRestoreInfo(this: pRestore);
  pRestore->ReadInt_2(this: pRestore, a2: &nEntities, a3: 1, a4: 0);
  v4 = (entitytable_t *)engine->SaveAllocMemory(this: engine, a2: 56 * nEntities, a3: 1);
  if ( v4 != nullptr )
  {
    CGameSaveRestoreInfo::InitEntityTable(this: v3, pNewTable: v4, size: nEntities);
    v5 = 0;
    if ( v3->tableCount > 0 )
    {
      pRestorea = nullptr;
      do
      {
        pRestore->ReadFields(
          this: pRestore,
          a2: "ETABLE",
          a3: (char *)pRestorea + (unsigned int)v3->pTable,
          a4: nullptr,
          a5: entitytable_t::m_DataMap.dataDesc,
          a6: entitytable_t::m_DataMap.dataNumFields);
        pRestorea += 14;
        ++v5;
      }
      while ( v5 < v3->tableCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167D50
// Name: void SaveEntityOnTable(class C_BaseEntity __near *,class CSaveRestoreData __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SaveEntityOnTable(C_BaseEntity *pEntity, CSaveRestoreData *pSaveData, int *iSlot)
{
  entitytable_t *v3; // esi
  int v4; // eax

  v3 = &pSaveData->pTable[*iSlot];
  v3->id = *iSlot;
  v3->edictindex = -1;
  v3->modelname = C_BaseEntity::GetModelName(this: pEntity);
  v4 = -1;
  v3->restoreentityindex = -1;
  if ( pEntity != nullptr )
    v4 = pEntity->entindex(this: &pEntity->IClientNetworkable);
  v3->saveentityindex = v4;
  if ( pEntity != nullptr )
    v3->hEnt.m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
  else
    v3->hEnt.m_Index = -1;
  v3->flags = 0;
  v3->location = 0;
  v3->size = 0;
  v3->classname = nullptr;
  ++*iSlot;
}

//------------------------------------------------------------------------------
// Address: 0x10167DF0
// Name: private: bool CEntitySaveRestoreBlockHandler::SaveInitEntities(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEntitySaveRestoreBlockHandler::SaveInitEntities(
        CEntitySaveRestoreBlockHandler *this,
        CSaveRestoreData *pSaveData)
{
  int v2; // esi
  entitytable_t *v3; // eax
  int v4; // edi
  CSaveRestoreData *v6; // esi
  int (__thiscall *v7)(unsigned int); // eax
  int v8; // ebx
  C_BaseEntity *BaseEntity; // eax
  int v10; // eax
  int v11; // ebx
  C_BaseEntity *BaseEntityFromHandle; // edi
  entitytable_t *v13; // esi
  unsigned int m_Index; // ecx
  int v15; // eax
  int v16; // ecx
  int v17; // [esp-4h] [ebp-18h]
  int v18; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h] BYREF

  v2 = (*(int (__thiscall **)(unsigned int, int))(*(_DWORD *)(cl_entitylist.m_Index + 131092) + 20))(
         a1: cl_entitylist.m_Index + 131092,
         a2: 1);
  v3 = (entitytable_t *)engine->SaveAllocMemory(this: engine, a2: 56 * v2, a3: 1);
  v4 = 0;
  if ( v3 == nullptr )
    return false;
  v17 = v2;
  v6 = pSaveData;
  CGameSaveRestoreInfo::InitEntityTable(this: &pSaveData->CGameSaveRestoreInfo, pNewTable: v3, size: v17);
  v7 = *(int (__thiscall **)(unsigned int))(*(_DWORD *)(cl_entitylist.m_Index + 131092) + 24);
  i = 0;
  v8 = v7(a1: cl_entitylist.m_Index + 131092);
  if ( v8 >= 0 )
  {
    do
    {
      BaseEntity = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: v4);
      if ( BaseEntity != nullptr )
        SaveEntityOnTable(pEntity: BaseEntity, pSaveData, iSlot: &i);
      ++v4;
    }
    while ( v4 <= v8 );
  }
  v10 = *(_DWORD *)(cl_entitylist.m_Index + 131076);
  if ( v10 != 0 )
  {
    v11 = ((signed int)(v10 - cl_entitylist.m_Index - 4) >> 4)
        | (*(_DWORD *)(cl_entitylist.m_Index + 16 * ((signed int)(v10 - cl_entitylist.m_Index - 4) >> 4) + 8) << 16);
    if ( v11 != -1 )
    {
      v18 = i;
      do
      {
        BaseEntityFromHandle = CClientEntityList::GetBaseEntityFromHandle(
                                 this: (CClientEntityList *)cl_entitylist.m_Index,
                                 hEnt: (CBaseHandle)v11);
        if ( BaseEntityFromHandle != nullptr
          && (BaseEntityFromHandle->ObjectCaps(this: BaseEntityFromHandle) & 0x400) != 0 )
        {
          v13 = &v6->pTable[v18];
          v13->id = i;
          v13->edictindex = -1;
          v13->modelname = C_BaseEntity::GetModelName(this: BaseEntityFromHandle);
          v13->restoreentityindex = -1;
          v13->saveentityindex = BaseEntityFromHandle->entindex(this: &BaseEntityFromHandle->IClientNetworkable);
          m_Index = BaseEntityFromHandle->GetRefEHandle(this: BaseEntityFromHandle)->m_Index;
          ++i;
          ++v18;
          v13->hEnt.m_Index = m_Index;
          v13->flags = 0;
          v13->location = 0;
          v13->size = 0;
          v13->classname = nullptr;
          v6 = pSaveData;
        }
        if ( v11 == -1 )
          v11 = 0x1FFF;
        else
          v11 = (unsigned __int16)v11;
        v15 = *(_DWORD *)(cl_entitylist.m_Index + 16 * (v11 + 1));
        if ( v15 != 0 )
          v16 = ((signed int)(v15 - cl_entitylist.m_Index - 4) >> 4)
              | (*(_DWORD *)(cl_entitylist.m_Index + 16 * ((signed int)(v15 - cl_entitylist.m_Index - 4) >> 4) + 8) << 16);
        else
          v16 = -1;
        v11 = v16;
      }
      while ( v16 != -1 );
    }
  }
  return i == v6->tableCount;
}

//------------------------------------------------------------------------------
// Address: 0x10167FC0
// Name: private: bool CEntitySaveRestoreBlockHandler::DoRestoreEntity(class C_BaseEntity __near *,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEntitySaveRestoreBlockHandler::DoRestoreEntity(
        CEntitySaveRestoreBlockHandler *this,
        C_BaseEntity *pEntity,
        IRestore *pRestore)
{
  unsigned int m_Index; // esi
  IHandleEntity *m_pEntity; // esi
  IMDLCache *cacheCriticalSection; // [esp+Ch] [ebp-4h]

  cacheCriticalSection = mdlcache;
  ((void (*)(void))mdlcache->BeginLock)();
  if ( pEntity != nullptr )
    m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
  else
    m_Index = -1;
  pRestore->GetGameSaveRestoreInfo(this: pRestore)->m_pCurrentEntity = pEntity;
  pEntity->Restore(this: pEntity, a2: pRestore);
  pRestore->GetGameSaveRestoreInfo(this: pRestore)->m_pCurrentEntity = nullptr;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  cacheCriticalSection->EndLock(this: cacheCriticalSection);
  return m_pEntity != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10168070
// Name: public: int CGameSaveRestoreInfo::GetEntityIndex(class C_BaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameSaveRestoreInfo::GetEntityIndex(CGameSaveRestoreInfo *this, const C_BaseEntity *pEntity)
{
  const C_BaseEntity *v2; // ebx
  unsigned int v4; // eax
  int tableCount; // edi
  int v7; // edx
  entitytable_t *i; // esi
  unsigned int m_Index; // ecx
  const C_BaseEntity *m_pEntity; // eax
  CGameSaveRestoreInfo::CHashElement src; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int pBucket; // [esp+14h] [ebp-4h] BYREF

  v2 = pEntity;
  if ( pEntity == nullptr )
    return -1;
  if ( CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>::Count(this: &this->m_EntityToIndex) != 0 )
  {
    src.pEntity = v2;
    pEntity = nullptr;
    if ( CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>::DoFind(
           this: &this->m_EntityToIndex,
           &src,
           &pBucket,
           pIndex: (int *)&pEntity) != 0 )
    {
      v4 = (unsigned int)pEntity | (pBucket << 16);
      if ( v4 != -1 )
        return this->m_EntityToIndex.m_Buckets.m_Memory.m_pMemory[HIWORD(v4)].m_Memory.m_pMemory[(unsigned __int16)pEntity].index;
    }
    return -1;
  }
  tableCount = this->tableCount;
  v7 = 0;
  if ( tableCount <= 0 )
    return -1;
  for ( i = this->pTable; ; ++i )
  {
    m_Index = i->hEnt.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (const C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity == pEntity )
      break;
    if ( ++v7 >= tableCount )
      return -1;
  }
  return i->id;
}

//------------------------------------------------------------------------------
// Address: 0x10168150
// Name: public: CSave::CSave(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
CSave *__thiscall CSave::CSave(CSave *this, CSaveRestoreData *pdata)
{
  CGameSaveRestoreInfo *v3; // ecx
  int *m_pMemory; // eax
  IMemAlloc_vtbl *v5; // edx
  int *v6; // eax

  this->__vftable = (CSave_vtbl *)&CSave::`vftable';
  this->m_BlockStartStack.m_Memory.m_pMemory = nullptr;
  this->m_BlockStartStack.m_Memory.m_nAllocationCount = 0;
  this->m_BlockStartStack.m_Memory.m_nGrowSize = 0;
  this->m_BlockStartStack.m_Size = 0;
  this->m_BlockStartStack.m_pElements = nullptr;
  this->m_pData = pdata;
  if ( pdata != nullptr )
    v3 = &pdata->CGameSaveRestoreInfo;
  else
    v3 = nullptr;
  this->m_pGameInfo = v3;
  this->m_bAsync = pdata->bAsync;
  if ( this->m_BlockStartStack.m_Memory.m_nAllocationCount < 32 && this->m_BlockStartStack.m_Memory.m_nGrowSize >= 0 )
  {
    this->m_BlockStartStack.m_Memory.m_nAllocationCount = 32;
    m_pMemory = this->m_BlockStartStack.m_Memory.m_pMemory;
    v5 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
    {
      v6 = (int *)((int (__stdcall *)(int *, int))v5->Realloc_2)(a1: m_pMemory, a2: 128);
      this->m_BlockStartStack.m_Memory.m_pMemory = v6;
      this->m_BlockStartStack.m_pElements = v6;
      this->m_hLogFile = nullptr;
      return this;
    }
    this->m_BlockStartStack.m_Memory.m_pMemory = (int *)((int (__stdcall *)(int))v5->Alloc_2)(a1: 128);
  }
  this->m_BlockStartStack.m_pElements = this->m_BlockStartStack.m_Memory.m_pMemory;
  this->m_hLogFile = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101681F0
// Name: public: virtual int CSave::WriteAll(void const __near *,struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSave::WriteAll(CSave *this, const void *pLeafObject, datamap_t *pLeafMap)
{
  int result; // eax

  if ( pLeafMap->baseMap == nullptr )
    return this->WriteFields(
             this,
             a2: pLeafMap->dataClassName,
             a3: pLeafObject,
             a4: pLeafMap,
             a5: pLeafMap->dataDesc,
             a6: pLeafMap->dataNumFields);
  result = CSave::DoWriteAll(this, pLeafObject, pLeafMap, pCurMap: pLeafMap->baseMap);
  if ( result != 0 )
    return this->WriteFields(
             this,
             a2: pLeafMap->dataClassName,
             a3: pLeafObject,
             a4: pLeafMap,
             a5: pLeafMap->dataDesc,
             a6: pLeafMap->dataNumFields);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10168240
// Name: public: virtual void CSave::EndBlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::EndBlock(CSave *this)
{
  const char *v2; // edi
  int v3; // ebx
  int sizeBlock; // [esp+Ch] [ebp-4h] BYREF

  v2 = (const char *)this->GetWritePos(this);
  v3 = this->m_BlockStartStack.m_Memory.m_pMemory[this->m_BlockStartStack.m_Size - 1];
  sizeBlock = (unsigned __int16)((_WORD)v2 - v3);
  --this->m_BlockStartStack.m_Size;
  this->SetWritePos(this, a2: v3 - 4);
  CSave::BufferData(this, a2: v2, pdata: (char *)&sizeBlock, size: 2);
  this->SetWritePos(this, a2: (int)v2);
}

//------------------------------------------------------------------------------
// Address: 0x101682C0
// Name: public: virtual void CSave::WriteEntityPtr(char const __near *,class C_BaseEntity __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteEntityPtr(CSave *this, const char *pname, C_BaseEntity **ppEntity, int count)
{
  int v4; // esi
  int i; // eax
  C_BaseEntity *pEntity[1024]; // [esp+Ch] [ebp-1000h] BYREF

  v4 = 0;
  if ( count > 0 )
  {
    for ( i = (char *)ppEntity - (char *)pEntity; v4 < 1024; i = (char *)ppEntity - (char *)pEntity )
    {
      pEntity[v4] = (C_BaseEntity *)CGameSaveRestoreInfo::GetEntityIndex(
                                      this: this->m_pGameInfo,
                                      pEntity: *(C_BaseEntity **)((char *)&pEntity[v4] + i));
      if ( ++v4 >= count )
        break;
    }
  }
  this->WriteInt(this, a2: pname, a3: (const int *)pEntity, a4: count);
}

//------------------------------------------------------------------------------
// Address: 0x10168340
// Name: public: virtual void CSave::WriteEntityPtr(class C_BaseEntity __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteEntityPtr(CSave *this, C_BaseEntity **ppEntity, int count)
{
  int v3; // esi
  int i; // eax
  C_BaseEntity *pEntity[1024]; // [esp+Ch] [ebp-1000h] BYREF

  v3 = 0;
  if ( count > 0 )
  {
    for ( i = (char *)ppEntity - (char *)pEntity; v3 < 1024; i = (char *)ppEntity - (char *)pEntity )
    {
      pEntity[v3] = (C_BaseEntity *)CGameSaveRestoreInfo::GetEntityIndex(
                                      this: this->m_pGameInfo,
                                      pEntity: *(C_BaseEntity **)((char *)&pEntity[v3] + i));
      if ( ++v3 >= count )
        break;
    }
  }
  this->WriteInt_2(this, a2: (const int *)pEntity, a3: count);
}

//------------------------------------------------------------------------------
// Address: 0x101683C0
// Name: public: virtual void CSave::WriteEHandle(char const __near *,class CHandle<class C_BaseEntity> const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteEHandle(CSave *this, const char *pname, const CHandle<C_BaseEntity> *pEHandle, int count)
{
  int v4; // edi
  const CHandle<C_BaseEntity> *v6; // esi
  unsigned int m_Index; // ecx
  const C_BaseEntity *m_pEntity; // eax
  _BYTE v9[4096]; // [esp+8h] [ebp-1000h] BYREF
  int v10; // [esp+1014h] [ebp+Ch]

  v4 = 0;
  if ( count > 0 )
  {
    v6 = pEHandle;
    v10 = v9 - (_BYTE *)pEHandle;
    do
    {
      if ( v4 >= 1024 )
        break;
      m_Index = v6->m_Index;
      if ( v6->m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = (const C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      }
      *(unsigned int *)((char *)&v6->m_Index + v10) = CGameSaveRestoreInfo::GetEntityIndex(
                                                        this: this->m_pGameInfo,
                                                        pEntity: m_pEntity);
      ++v4;
      ++v6;
    }
    while ( v4 < count );
  }
  this->WriteInt(this, a2: pname, a3: (const int *)v9, a4: count);
}

//------------------------------------------------------------------------------
// Address: 0x10168450
// Name: public: virtual void CSave::WriteEHandle(class CHandle<class C_BaseEntity> const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteEHandle(CSave *this, const CHandle<C_BaseEntity> *pEHandle, int count)
{
  int v3; // edi
  const CHandle<C_BaseEntity> *v5; // esi
  unsigned int m_Index; // ecx
  const C_BaseEntity *m_pEntity; // eax
  _BYTE v8[4096]; // [esp+8h] [ebp-1000h] BYREF
  int v9; // [esp+1010h] [ebp+8h]

  v3 = 0;
  if ( count > 0 )
  {
    v5 = pEHandle;
    v9 = v8 - (_BYTE *)pEHandle;
    do
    {
      if ( v3 >= 1024 )
        break;
      m_Index = v5->m_Index;
      if ( v5->m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = (const C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      }
      *(unsigned int *)((char *)&v5->m_Index + v9) = CGameSaveRestoreInfo::GetEntityIndex(
                                                       this: this->m_pGameInfo,
                                                       pEntity: m_pEntity);
      ++v3;
      ++v5;
    }
    while ( v3 < count );
  }
  this->WriteInt_2(this, a2: (const int *)v8, a3: count);
}

//------------------------------------------------------------------------------
// Address: 0x101684E0
// Name: public: CRestore::CRestore(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
CRestore *__thiscall CRestore::CRestore(CRestore *this, CSaveRestoreData *pdata)
{
  CGameSaveRestoreInfo *v3; // eax
  int *m_pMemory; // eax
  IMemAlloc_vtbl *v5; // edx
  int *v6; // eax

  this->__vftable = (CRestore_vtbl *)&CRestore::`vftable';
  this->m_BlockEndStack.m_Memory.m_pMemory = nullptr;
  this->m_BlockEndStack.m_Memory.m_nAllocationCount = 0;
  this->m_BlockEndStack.m_Memory.m_nGrowSize = 0;
  this->m_BlockEndStack.m_Size = 0;
  this->m_BlockEndStack.m_pElements = nullptr;
  this->m_pData = pdata;
  if ( pdata != nullptr )
    v3 = &pdata->CGameSaveRestoreInfo;
  else
    v3 = nullptr;
  this->m_pGameInfo = v3;
  this->m_global = 0;
  this->m_precache = true;
  if ( this->m_BlockEndStack.m_Memory.m_nAllocationCount < 32 && this->m_BlockEndStack.m_Memory.m_nGrowSize >= 0 )
  {
    this->m_BlockEndStack.m_Memory.m_nAllocationCount = 32;
    m_pMemory = this->m_BlockEndStack.m_Memory.m_pMemory;
    v5 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
    {
      v6 = (int *)((int (__stdcall *)(int *, int))v5->Realloc_2)(a1: m_pMemory, a2: 128);
      this->m_BlockEndStack.m_Memory.m_pMemory = v6;
      this->m_BlockEndStack.m_pElements = v6;
      return this;
    }
    this->m_BlockEndStack.m_Memory.m_pMemory = (int *)((int (__stdcall *)(int))v5->Alloc_2)(a1: 128);
  }
  this->m_BlockEndStack.m_pElements = this->m_BlockEndStack.m_Memory.m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10168570
// Name: public: virtual int CRestore::SkipHeader(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::SkipHeader(CRestore *this)
{
  SaveRestoreRecordHeader_t header; // [esp+0h] [ebp-4h] BYREF

  header = (SaveRestoreRecordHeader_t)this;
  this->ReadHeader(this, a2: &header);
  return header.size;
}

//------------------------------------------------------------------------------
// Address: 0x10168590
// Name: public: virtual class CGameSaveRestoreInfo __near * CRestore::GetGameSaveRestoreInfo(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::GetGameSaveRestoreInfo(CBaseAchievement *this)
{
  return this->m_iGoal;
}

//------------------------------------------------------------------------------
// Address: 0x101685A0
// Name: public: virtual int CRestore::ReadAll(void __near *,struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadAll(CRestore *this, void *pLeafObject, datamap_t *pLeafMap)
{
  int result; // eax

  if ( pLeafMap->baseMap == nullptr )
    return this->ReadFields(
             this,
             a2: pLeafMap->dataClassName,
             a3: pLeafObject,
             a4: pLeafMap,
             a5: pLeafMap->dataDesc,
             a6: pLeafMap->dataNumFields);
  result = CRestore::DoReadAll(this, pLeafObject, pLeafMap, pCurMap: pLeafMap->baseMap);
  if ( result != 0 )
    return this->ReadFields(
             this,
             a2: pLeafMap->dataClassName,
             a3: pLeafObject,
             a4: pLeafMap,
             a5: pLeafMap->dataDesc,
             a6: pLeafMap->dataNumFields);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101685F0
// Name: public: virtual void CRestore::EndBlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRestore::EndBlock(CRestore *this)
{
  int v1; // edi

  v1 = this->m_BlockEndStack.m_Memory.m_pMemory[--this->m_BlockEndStack.m_Size];
  this->SetReadPos(this, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10168630
// Name: public: virtual void CEntitySaveRestoreBlockHandler::PreSave(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntitySaveRestoreBlockHandler::PreSave(
        CEntitySaveRestoreBlockHandler *this,
        CSaveRestoreData *pSaveData)
{
  int v3; // eax
  CClientEntityList *m_Index; // ecx
  int v5; // ebx
  int v6; // eax
  int v7; // esi
  int v8; // edi
  C_BaseEntity *BaseEntity; // eax
  C_BaseEntity *BaseEntityFromHandle; // eax
  C_BaseEntity *v11; // edi
  int v12; // eax
  int v13; // ecx
  IMDLCache *cacheCriticalSection; // [esp+Ch] [ebp-Ch]
  C_BaseAnimating::AutoAllowBoneAccess boneaccess; // [esp+17h] [ebp-1h] BYREF

  cacheCriticalSection = mdlcache;
  ((void (*)(void))mdlcache->BeginLock)();
  IGameSystem::OnSaveAllSystems();
  this->m_EntitySaveUtils.m_pLevelAdjacencyDependencyHash = physics->CreateObjectPairHash(this: physics);
  C_BaseAnimating::AutoAllowBoneAccess::AutoAllowBoneAccess(
    this: &boneaccess,
    bAllowForNormalModels: true,
    bAllowForViewModels: true);
  v3 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)(cl_entitylist.m_Index + 131092) + 24))(a1: cl_entitylist.m_Index + 131092);
  m_Index = (CClientEntityList *)cl_entitylist.m_Index;
  v5 = v3;
  v6 = *(_DWORD *)(cl_entitylist.m_Index + 131076);
  if ( v6 != 0 )
    v7 = ((signed int)(v6 - cl_entitylist.m_Index - 4) >> 4)
       | (*(_DWORD *)(cl_entitylist.m_Index + 16 * ((signed int)(v6 - cl_entitylist.m_Index - 4) >> 4) + 8) << 16);
  else
    v7 = -1;
  v8 = 0;
  if ( v5 >= 0 )
  {
    while ( 1 )
    {
      BaseEntity = CClientEntityList::GetBaseEntity(this: m_Index, entnum: v8);
      if ( BaseEntity != nullptr )
        BaseEntity->OnSave(this: BaseEntity);
      if ( ++v8 > v5 )
        break;
      m_Index = (CClientEntityList *)cl_entitylist.m_Index;
    }
  }
  if ( v7 != -1 )
  {
    do
    {
      BaseEntityFromHandle = CClientEntityList::GetBaseEntityFromHandle(
                               this: (CClientEntityList *)cl_entitylist.m_Index,
                               hEnt: (CBaseHandle)v7);
      v11 = BaseEntityFromHandle;
      if ( BaseEntityFromHandle != nullptr
        && (BaseEntityFromHandle->ObjectCaps(this: BaseEntityFromHandle) & 0x400) != 0 )
      {
        v11->OnSave(this: v11);
      }
      if ( v7 == -1 )
        v7 = 0x1FFF;
      else
        v7 = (unsigned __int16)v7;
      v12 = *(_DWORD *)(cl_entitylist.m_Index + 16 * (v7 + 1));
      if ( v12 != 0 )
        v13 = ((signed int)(v12 - cl_entitylist.m_Index - 4) >> 4)
            | (*(_DWORD *)(cl_entitylist.m_Index + 16 * ((signed int)(v12 - cl_entitylist.m_Index - 4) >> 4) + 8) << 16);
      else
        v13 = -1;
      v7 = v13;
    }
    while ( v13 != -1 );
  }
  C_BaseAnimating::AutoAllowBoneAccess::~AutoAllowBoneAccess(this: &boneaccess);
  CEntitySaveRestoreBlockHandler::SaveInitEntities(this, pSaveData);
  cacheCriticalSection->EndLock(this: cacheCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x10168790
// Name: public: virtual void CEntitySaveRestoreBlockHandler::Restore(class IRestore __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntitySaveRestoreBlockHandler::Restore(
        CEntitySaveRestoreBlockHandler *this,
        IRestore *pRestore,
        bool createPlayers)
{
  CGameSaveRestoreInfo *v4; // edi
  entitytable_t *v5; // esi
  C_BaseEntity *BaseEntity; // eax
  entitytable_t *v7; // edi
  C_BaseEntity *v8; // esi
  C_BaseEntity *EntityByName; // esi
  CHud *Hud; // eax
  CGameSaveRestoreInfo *pSaveData; // [esp+10h] [ebp-8h]
  int v13; // [esp+14h] [ebp-4h]
  int v14; // [esp+14h] [ebp-4h]
  int i; // [esp+20h] [ebp+8h]
  int ia; // [esp+20h] [ebp+8h]

  v4 = pRestore->GetGameSaveRestoreInfo(this: pRestore);
  pSaveData = v4;
  i = 0;
  if ( v4->tableCount > 0 )
  {
    v13 = 0;
    do
    {
      v5 = &v4->pTable[v13];
      BaseEntity = CClientEntityList::GetBaseEntity(
                     this: (CClientEntityList *)cl_entitylist.m_Index,
                     entnum: v5->restoreentityindex);
      if ( BaseEntity != nullptr )
        v5->hEnt.m_Index = BaseEntity->GetRefEHandle(this: BaseEntity)->m_Index;
      else
        v5->hEnt.m_Index = -1;
      ++v13;
      ++i;
    }
    while ( i < v4->tableCount );
  }
  ia = 0;
  if ( v4->tableCount > 0 )
  {
    v14 = 0;
    while ( 1 )
    {
      v7 = &v4->pTable[v14];
      if ( v7->restoreentityindex < 0 )
      {
        if ( pSaveData->levelInfo.fUseLandmark == 0 && v7->classname != nullptr )
        {
          EntityByName = CreateEntityByName(className: v7->classname);
          EntityByName->InitializeAsClientEntity(this: EntityByName, a2: nullptr, a3: false);
          pRestore->SetReadPos(this: pRestore, a2: v7->location);
          CEntitySaveRestoreBlockHandler::DoRestoreEntity(this, pEntity: EntityByName, pRestore);
          v7->hEnt.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
          AddRestoredEntity(pEntity: EntityByName);
          goto LABEL_17;
        }
      }
      else
      {
        v8 = CClientEntityList::GetBaseEntity(
               this: (CClientEntityList *)cl_entitylist.m_Index,
               entnum: v7->restoreentityindex);
        pRestore->SetReadPos(this: pRestore, a2: v7->location);
        if ( v8 != nullptr )
        {
          CEntitySaveRestoreBlockHandler::DoRestoreEntity(this, pEntity: v8, pRestore);
          AddRestoredEntity(pEntity: v8);
          goto LABEL_17;
        }
      }
      v7->hEnt.m_Index = -1;
      v7->restoreentityindex = -1;
LABEL_17:
      ++v14;
      if ( ++ia >= pSaveData->tableCount )
        break;
      v4 = pSaveData;
    }
  }
  IGameSystem::OnRestoreAllSystems();
  Hud = GetHud(nSlot: -1);
  CHud::OnRestore(this: Hud);
}

//------------------------------------------------------------------------------
// Address: 0x10168970
// Name: public: virtual void CSaveRestoreBlockSet::Save(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreBlockSet::Save(CSaveRestoreBlockSet *this, ISave *pSave)
{
  SaveRestoreBlockHeader_t *v4; // esi
  ISaveRestoreBlockHandler *v5; // ecx
  int base; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]
  ISave *pSavea; // [esp+18h] [ebp+8h]

  base = pSave->GetWritePos(this: pSave);
  i = 0;
  if ( this->m_Handlers.m_Size > 0 )
  {
    pSavea = nullptr;
    do
    {
      v4 = (SaveRestoreBlockHeader_t *)((char *)pSavea + (unsigned int)this->m_BlockHeaders.m_Memory.m_pMemory);
      v4->locBody = pSave->GetWritePos(this: pSave) - base;
      v5 = this->m_Handlers.m_Memory.m_pMemory[i];
      v5->Save(this: v5, a2: pSave);
      pSavea += 10;
      ++i;
    }
    while ( i < this->m_Handlers.m_Size );
  }
  this->m_SizeBodies = pSave->GetWritePos(this: pSave) - base;
}

//------------------------------------------------------------------------------
// Address: 0x101689F0
// Name: public: virtual void CSaveRestoreBlockSet::PreRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreBlockSet::PreRestore(CSaveRestoreBlockSet *this)
{
  int i; // esi
  ISaveRestoreBlockHandler *v3; // ecx

  for ( i = 0; i < this->m_Handlers.m_Size; ++i )
  {
    v3 = this->m_Handlers.m_Memory.m_pMemory[i];
    v3->PreRestore(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168A20
// Name: public: virtual void CSaveRestoreBlockSet::Restore(class IRestore __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreBlockSet::Restore(CSaveRestoreBlockSet *this, IRestore *pRestore, BOOL fCreatePlayers)
{
  int v5; // edi
  int base; // [esp+14h] [ebp+8h]

  v5 = 0;
  for ( base = pRestore->GetReadPos(this: pRestore); v5 < this->m_Handlers.m_Size; ++v5 )
    this->CallBlockHandlerRestore(
      this,
      a2: this->m_Handlers.m_Memory.m_pMemory[v5],
      a3: base,
      a4: pRestore,
      a5: fCreatePlayers);
  pRestore->SetReadPos(this: pRestore, a2: base + this->m_SizeBodies);
}

//------------------------------------------------------------------------------
// Address: 0x10168A80
// Name: private: int CSaveRestoreBlockSet::GetBlockBodyLoc(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestoreBlockSet::GetBlockBodyLoc(CSaveRestoreBlockSet *this, const char *pszName)
{
  int m_Size; // ebx
  int v3; // esi
  const char *i; // edi
  SaveRestoreBlockHeader_t *m_pMemory; // [esp+Ch] [ebp-4h]

  m_Size = this->m_BlockHeaders.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return -1;
  m_pMemory = this->m_BlockHeaders.m_Memory.m_pMemory;
  for ( i = (const char *)m_pMemory; strcmp(i, pszName) != 0; i += 40 )
  {
    if ( ++v3 >= m_Size )
      return -1;
  }
  return m_pMemory[v3].locBody;
}

//------------------------------------------------------------------------------
// Address: 0x10168AF0
// Name: private: int CSaveRestoreBlockSet::GetBlockHeaderLoc(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestoreBlockSet::GetBlockHeaderLoc(CSaveRestoreBlockSet *this, const char *pszName)
{
  int m_Size; // ebx
  int v3; // esi
  const char *i; // edi
  SaveRestoreBlockHeader_t *m_pMemory; // [esp+Ch] [ebp-4h]

  m_Size = this->m_BlockHeaders.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return -1;
  m_pMemory = this->m_BlockHeaders.m_Memory.m_pMemory;
  for ( i = (const char *)m_pMemory; strcmp(i, pszName) != 0; i += 40 )
  {
    if ( ++v3 >= m_Size )
      return -1;
  }
  return m_pMemory[v3].locHeader;
}

//------------------------------------------------------------------------------
// Address: 0x10168C20
// Name: public: virtual void CSaveRestoreBlockSet::CallBlockHandlerRestore(class ISaveRestoreBlockHandler __near *,int,class IRestore __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreBlockSet::CallBlockHandlerRestore(
        CSaveRestoreBlockSet *this,
        ISaveRestoreBlockHandler *pHandler,
        int baseFilePos,
        IRestore *pRestore,
        BOOL fCreatePlayers)
{
  const char *v6; // eax
  int BlockBodyLoc; // eax

  v6 = (const char *)pHandler->GetBlockName(this: pHandler);
  BlockBodyLoc = CSaveRestoreBlockSet::GetBlockBodyLoc(this, pszName: v6);
  if ( BlockBodyLoc != -1 )
  {
    pRestore->SetReadPos(this: pRestore, a2: baseFilePos + BlockBodyLoc);
    pHandler->Restore(this: pHandler, a2: pRestore, a3: fCreatePlayers);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168CF0
// Name: public: virtual void CSaveRestoreBlockSet::PostSave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreBlockSet::PostSave(CSaveRestoreBlockSet *this)
{
  int i; // edi
  ISaveRestoreBlockHandler *v3; // ecx
  bool v4; // sf
  SaveRestoreBlockHeader_t *m_pMemory; // ecx

  for ( i = 0; i < this->m_Handlers.m_Size; ++i )
  {
    v3 = this->m_Handlers.m_Memory.m_pMemory[i];
    v3->PostSave(this: v3);
  }
  v4 = this->m_BlockHeaders.m_Memory.m_nGrowSize < 0;
  this->m_BlockHeaders.m_Size = 0;
  if ( v4 )
  {
    this->m_BlockHeaders.m_pElements = this->m_BlockHeaders.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_BlockHeaders.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_BlockHeaders.m_Memory.m_pMemory);
      this->m_BlockHeaders.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_BlockHeaders.m_Memory.m_pMemory;
    this->m_BlockHeaders.m_Memory.m_nAllocationCount = 0;
    this->m_BlockHeaders.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168D60
// Name: public: virtual void CSaveRestoreBlockSet::ReadRestoreHeaders(class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreBlockSet::ReadRestoreHeaders(CSaveRestoreBlockSet *this, IRestore *pRestore)
{
  int v4; // eax
  IRestore_vtbl *v5; // edx
  int v6; // ebx
  void (__thiscall *v7)(int *, _DWORD *, IRestore *); // eax
  ISaveRestoreBlockHandler *v8; // ecx
  const char *v9; // eax
  int BlockHeaderLoc; // eax
  ISaveRestoreBlockHandler *v11; // ecx
  _DWORD v12[3]; // [esp+Ch] [ebp-10h] BYREF
  int *p_m_SizeHeaders; // [esp+18h] [ebp-4h]
  int base; // [esp+24h] [ebp+8h]

  v4 = pRestore->GetReadPos(this: pRestore);
  v5 = pRestore->__vftable;
  v6 = 0;
  base = v4;
  p_m_SizeHeaders = &this->m_SizeHeaders;
  v5->ReadInt_2(this: pRestore, a2: &this->m_SizeHeaders, a3: 1, a4: 0);
  pRestore->ReadInt_2(this: pRestore, a2: &this->m_SizeBodies, a3: 1, a4: 0);
  if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::`local static guard' |= 1u;
    `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>,10>::`vftable';
  }
  v12[0] = &this->m_BlockHeaders;
  v7 = *(void (__thiscall **)(int *, _DWORD *, IRestore *))(`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::ops
                                                          + 4);
  v12[1] = 0;
  v12[2] = 0;
  v7(
    a1: &`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::ops,
    a2: v12,
    a3: pRestore);
  if ( this->m_Handlers.m_Size > 0 )
  {
    do
    {
      v8 = this->m_Handlers.m_Memory.m_pMemory[v6];
      v9 = (const char *)v8->GetBlockName(this: v8);
      BlockHeaderLoc = CSaveRestoreBlockSet::GetBlockHeaderLoc(this, pszName: v9);
      if ( BlockHeaderLoc != -1 )
      {
        pRestore->SetReadPos(this: pRestore, a2: base + BlockHeaderLoc);
        v11 = this->m_Handlers.m_Memory.m_pMemory[v6];
        v11->ReadRestoreHeaders(this: v11, a2: pRestore);
      }
      ++v6;
    }
    while ( v6 < this->m_Handlers.m_Size );
  }
  pRestore->SetReadPos(this: pRestore, a2: base + *p_m_SizeHeaders);
}

//------------------------------------------------------------------------------
// Address: 0x10168E40
// Name: public: virtual void CSaveRestoreBlockSet::PostRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreBlockSet::PostRestore(CSaveRestoreBlockSet *this)
{
  int i; // edi
  ISaveRestoreBlockHandler *v3; // ecx
  bool v4; // sf
  SaveRestoreBlockHeader_t *m_pMemory; // ecx

  for ( i = 0; i < this->m_Handlers.m_Size; ++i )
  {
    v3 = this->m_Handlers.m_Memory.m_pMemory[i];
    v3->PostRestore(this: v3);
  }
  v4 = this->m_BlockHeaders.m_Memory.m_nGrowSize < 0;
  this->m_BlockHeaders.m_Size = 0;
  if ( v4 )
  {
    this->m_BlockHeaders.m_pElements = this->m_BlockHeaders.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_BlockHeaders.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_BlockHeaders.m_Memory.m_pMemory);
      this->m_BlockHeaders.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_BlockHeaders.m_Memory.m_pMemory;
    this->m_BlockHeaders.m_Memory.m_nAllocationCount = 0;
    this->m_BlockHeaders.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10168EB0
// Name: public: virtual void CSaveRestoreBlockSet::RemoveBlockHandler(class ISaveRestoreBlockHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreBlockSet::RemoveBlockHandler(
        CSaveRestoreBlockSet *this,
        ISaveRestoreBlockHandler *pHandler)
{
  CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Handlers,
    src: (vgui::TreeNode **)&pHandler);
}

//------------------------------------------------------------------------------
// Address: 0x10168ED0
// Name: public: virtual void CSaveRestoreBlockSet::AddBlockHandler(class ISaveRestoreBlockHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreBlockSet::AddBlockHandler(CSaveRestoreBlockSet *this, ISaveRestoreBlockHandler *pHandler)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_Handlers; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  m_nAllocationCount = this->m_Handlers.m_Memory.m_nAllocationCount;
  p_m_Handlers = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Handlers;
  m_Size = this->m_Handlers.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Handlers, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Handlers[1].m_pMemory;
  m_pMemory = p_m_Handlers->m_pMemory;
  v6 = (int)p_m_Handlers[1].m_pMemory - m_Size - 1;
  p_m_Handlers[1].m_nAllocationCount = (int)p_m_Handlers->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &p_m_Handlers->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (vgui::TreeNode *)pHandler;
}

//------------------------------------------------------------------------------
// Address: 0x10169010
// Name: public: virtual void CSave::StartBlock(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSave::StartBlock(CSave *this@<ecx>, const char *a2@<edi>, const char *pszBlockName)
{
  CSaveRestoreSegment *m_pData; // ecx
  int v5; // eax
  int m_Size; // edi
  int v7; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v10; // eax
  int *v11; // eax
  char pdata[4]; // [esp+Ch] [ebp-4h] BYREF

  m_pData = this->m_pData;
  *(_DWORD *)pdata = 0;
  pszBlockName = (const char *)(unsigned __int16)CSaveRestoreSegment::FindCreateSymbol(
                                                   this: m_pData,
                                                   pszToken: pszBlockName);
  CSave::BufferData(this, a2, pdata, size: 2);
  CSave::BufferData(this, a2, pdata: (char *)&pszBlockName, size: 2);
  v5 = this->GetWritePos(this);
  m_Size = this->m_BlockStartStack.m_Size;
  v7 = v5;
  m_nAllocationCount = this->m_BlockStartStack.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_BlockStartStack,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_BlockStartStack.m_Size;
  m_pMemory = this->m_BlockStartStack.m_Memory.m_pMemory;
  v10 = this->m_BlockStartStack.m_Size - m_Size - 1;
  this->m_BlockStartStack.m_pElements = m_pMemory;
  if ( v10 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v10);
  v11 = &this->m_BlockStartStack.m_Memory.m_pMemory[m_Size];
  if ( v11 != nullptr )
    *v11 = v7;
}

//------------------------------------------------------------------------------
// Address: 0x101690B0
// Name: public: virtual void CRestore::StartBlock(struct SaveRestoreRecordHeader_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRestore::StartBlock(CRestore *this, SaveRestoreRecordHeader_t *pHeader)
{
  int v3; // ebx
  int m_Size; // edi
  int v5; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v8; // eax
  int *v9; // edi

  this->ReadHeader(this, a2: pHeader);
  v3 = this->GetReadPos(this);
  m_Size = this->m_BlockEndStack.m_Size;
  v5 = pHeader->size + v3;
  m_nAllocationCount = this->m_BlockEndStack.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_BlockEndStack,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_BlockEndStack.m_Size;
  m_pMemory = this->m_BlockEndStack.m_Memory.m_pMemory;
  v8 = this->m_BlockEndStack.m_Size - m_Size - 1;
  this->m_BlockEndStack.m_pElements = m_pMemory;
  if ( v8 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v8);
  v9 = &this->m_BlockEndStack.m_Memory.m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = v5;
}

//------------------------------------------------------------------------------
// Address: 0x101691B0
// Name: public: virtual void CSaveRestoreBlockSet::PreSave(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreBlockSet::PreSave(CSaveRestoreBlockSet *this, CSaveRestoreData *pData)
{
  int v3; // esi
  CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int> > *p_m_BlockHeaders; // ecx
  ISaveRestoreBlockHandler *v5; // ecx
  SaveRestoreBlockHeader_t *v6; // edi
  char *v7; // eax
  ISaveRestoreBlockHandler *v8; // ecx
  int m_Size; // [esp-4h] [ebp-10h]
  int v10; // [esp+8h] [ebp-4h]

  v3 = 0;
  m_Size = this->m_Handlers.m_Size;
  p_m_BlockHeaders = &this->m_BlockHeaders;
  p_m_BlockHeaders->m_Size = 0;
  CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>::InsertMultipleBefore(
    this: p_m_BlockHeaders,
    elem: 0,
    num: m_Size);
  if ( this->m_Handlers.m_Size > 0 )
  {
    v10 = 0;
    do
    {
      v5 = this->m_Handlers.m_Memory.m_pMemory[v3];
      v6 = &this->m_BlockHeaders.m_Memory.m_pMemory[v10];
      v7 = (char *)v5->GetBlockName(this: v5);
      V_strncpy(pDest: v6->szName, pSrc: v7, maxLen: 32);
      v8 = this->m_Handlers.m_Memory.m_pMemory[v3];
      v8->PreSave(this: v8, a2: pData);
      ++v10;
      ++v3;
    }
    while ( v3 < this->m_Handlers.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10169220
// Name: public: virtual void CSaveRestoreBlockSet::WriteSaveHeaders(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreBlockSet::WriteSaveHeaders(CSaveRestoreBlockSet *this, ISave *pSave)
{
  void (__thiscall *v4)(int *, CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int> > **, ISave *); // eax
  SaveRestoreBlockHeader_t *v5; // ebx
  int v6; // eax
  int v7; // ebx
  ISaveRestoreBlockHandler *v8; // ecx
  int v9; // eax
  void (__thiscall *v10)(int *, CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int> > **, ISave *); // eax
  SaveRestoreBlockHeader_t *m_pMemory; // eax
  int m_Size; // [esp-4h] [ebp-3Ch]
  CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int> > dummyArr; // [esp+Ch] [ebp-2Ch] BYREF
  CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int> > *p_dummyArr; // [esp+20h] [ebp-18h] BYREF
  int v15; // [esp+24h] [ebp-14h]
  int v16; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]
  int dummyInt; // [esp+30h] [ebp-8h] BYREF
  int base; // [esp+34h] [ebp-4h]
  int savedPos; // [esp+40h] [ebp+8h]
  int savedPosa; // [esp+40h] [ebp+8h]

  base = pSave->GetWritePos(this: pSave);
  m_Size = this->m_BlockHeaders.m_Size;
  dummyInt = -1;
  memset(&dummyArr, 0, sizeof(dummyArr));
  CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>::InsertMultipleBefore(
    this: &dummyArr,
    elem: 0,
    num: m_Size);
  memset(dst: (int)dummyArr.m_Memory.m_pMemory->szName, value: (unsigned __int8 *)0xFF, count: 40 * dummyArr.m_Size);
  pSave->WriteInt_2(this: pSave, a2: &dummyInt, a3: 1);
  pSave->WriteInt_2(this: pSave, a2: &dummyInt, a3: 1);
  if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::`local static guard' |= 1u;
    `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>,10>::`vftable';
  }
  p_dummyArr = &dummyArr;
  v4 = *(void (__thiscall **)(int *, CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int> > **, ISave *))`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::ops;
  v15 = 0;
  v16 = 0;
  v4(
    a1: &`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::ops,
    a2: &p_dummyArr,
    a3: pSave);
  i = 0;
  if ( this->m_Handlers.m_Size > 0 )
  {
    savedPos = 0;
    do
    {
      v5 = &this->m_BlockHeaders.m_Memory.m_pMemory[savedPos];
      v6 = pSave->GetWritePos(this: pSave);
      v5->locHeader = v6 - base;
      v7 = i;
      v8 = this->m_Handlers.m_Memory.m_pMemory[i];
      v8->WriteSaveHeaders(this: v8, a2: pSave);
      ++savedPos;
      i = v7 + 1;
    }
    while ( v7 + 1 < this->m_Handlers.m_Size );
  }
  v9 = pSave->GetWritePos(this: pSave);
  this->m_SizeHeaders = v9 - base;
  savedPosa = pSave->GetWritePos(this: pSave);
  pSave->SetWritePos(this: pSave, a2: base);
  pSave->WriteInt_2(this: pSave, a2: &this->m_SizeHeaders, a3: 1);
  pSave->WriteInt_2(this: pSave, a2: &this->m_SizeBodies, a3: 1);
  if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::`local static guard' |= 1u;
    `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>,10>::`vftable';
  }
  v10 = *(void (__thiscall **)(int *, CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int> > **, ISave *))`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::ops;
  p_dummyArr = &this->m_BlockHeaders;
  v15 = 0;
  v16 = 0;
  v10(
    a1: &`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::ops,
    a2: &p_dummyArr,
    a3: pSave);
  pSave->SetWritePos(this: pSave, a2: savedPosa);
  m_pMemory = dummyArr.m_Memory.m_pMemory;
  dummyArr.m_Size = 0;
  if ( dummyArr.m_Memory.m_nGrowSize >= 0 )
  {
    if ( dummyArr.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dummyArr.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      dummyArr.m_Memory.m_pMemory = nullptr;
    }
    dummyArr.m_Memory.m_nAllocationCount = 0;
  }
  dummyArr.m_pElements = m_pMemory;
  if ( dummyArr.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10169470
// Name: public: CUtlHash<struct CGameSaveRestoreInfo::CHashElement,class CGameSaveRestoreInfo::CHashFuncs,class CGameSaveRestoreInfo::CHashFuncs>::CUtlHash<struct CGameSaveRestoreInfo::CHashElement,class CGameSaveRestoreInfo::CHashFuncs,class CGameSaveRestoreInfo::CHashFuncs>(int,int,int,class CGameSaveRestoreInfo::CHashFuncs,class CGameSaveRestoreInfo::CHashFuncs)
// Source: json
//------------------------------------------------------------------------------
CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs> *__thiscall CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>::CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>(
        CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs> *this,
        int bucketCount,
        int growCount,
        int initCount,
        CGameSaveRestoreInfo::CHashFuncs compareFunc,
        CGameSaveRestoreInfo::CHashFuncs keyFunc)
{
  int v6; // esi
  int v8; // eax
  CUtlMemory<vgui::PropertySheet::Page_t,int> *v9; // esi
  int m_nAllocationCount; // eax
  vgui::PropertySheet::Page_t *m_pMemory; // ecx
  int v12; // eax
  bool v13; // zf
  int v15; // [esp+Ch] [ebp-8h]
  int v16; // [esp+10h] [ebp-4h]

  v6 = bucketCount;
  this->m_Buckets.m_Memory.m_pMemory = nullptr;
  this->m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_Buckets.m_Size = 0;
  this->m_Buckets.m_pElements = nullptr;
  if ( bucketCount >= 0x10000 )
  {
    bucketCount = 0x10000;
    v6 = 0x10000;
  }
  CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll((CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)this);
  CUtlVector<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,int>>::InsertMultipleBefore(
    (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)this,
    elem: this->m_Buckets.m_Size,
    num: v6);
  if ( v6 > 0 )
  {
    v8 = 0;
    v16 = 0;
    v15 = v6;
    do
    {
      v9 = (CUtlMemory<vgui::PropertySheet::Page_t,int> *)((char *)this->m_Buckets.m_Memory.m_pMemory + v8);
      v9[1].m_pMemory = nullptr;
      if ( initCount != 0 )
      {
        m_nAllocationCount = v9->m_nAllocationCount;
        if ( initCount > m_nAllocationCount )
          CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
            this: v9,
            num: initCount - m_nAllocationCount);
        v9[1].m_pMemory = (vgui::PropertySheet::Page_t *)((char *)v9[1].m_pMemory + initCount);
        m_pMemory = v9->m_pMemory;
        v12 = (int)v9[1].m_pMemory - initCount;
        v9[1].m_nAllocationCount = (int)v9->m_pMemory;
        if ( v12 > 0 && initCount > 0 )
          _V_memmove(dest: &m_pMemory[initCount], src: m_pMemory, count: 8 * v12);
      }
      this->m_Buckets.m_Memory.m_pMemory[v16].m_Memory.m_nGrowSize = growCount;
      v8 = v16 * 20 + 20;
      v13 = v15-- == 1;
      ++v16;
    }
    while ( !v13 );
    v6 = bucketCount;
  }
  this->m_bPowerOfTwo = ((v6 - 1) & v6) == 0;
  this->m_ModMask = ((v6 - 1) & v6) == 0 ? v6 - 1 : 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10169550
// Name: public: CSaveRestoreData::CSaveRestoreData(void)
// Source: json
//------------------------------------------------------------------------------
CSaveRestoreData *__thiscall CSaveRestoreData::CSaveRestoreData(CSaveRestoreData *this)
{
  CGameSaveRestoreInfo *v2; // esi
  CGameSaveRestoreInfo::CHashFuncs v4; // [esp-8h] [ebp-18h] BYREF
  CGameSaveRestoreInfo::CHashFuncs v5; // [esp-4h] [ebp-14h]
  CGameSaveRestoreInfo::CHashFuncs *v6; // [esp+Ch] [ebp-4h]

  v5 = (CGameSaveRestoreInfo::CHashFuncs)this;
  v4 = (CGameSaveRestoreInfo::CHashFuncs)this;
  v6 = &v4;
  *(_QWORD *)&this->pBaseData = 0;
  *(_QWORD *)&this->size = 0;
  v2 = &this->CGameSaveRestoreInfo;
  *(_QWORD *)&this->tokenCount = 0;
  this->m_nEntityDataSize = 0;
  this->tableCount = 0;
  this->pTable = nullptr;
  this->m_pCurrentEntity = nullptr;
  CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>::CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>(
    this: &this->m_EntityToIndex,
    bucketCount: 0,
    growCount: 0,
    initCount: 0,
    compareFunc: v4,
    keyFunc: v5);
  memset(dst: (int)v2, value: nullptr, count: 0x550u);
  v2->modelSpaceOffset.x = 0.0;
  v2->modelSpaceOffset.y = 0.0;
  v2->modelSpaceOffset.z = 0.0;
  this->bAsync = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101695E0
// Name: class CSaveRestoreData __near * SaveInit(int)
// Source: json
//------------------------------------------------------------------------------
CSaveRestoreData *__cdecl SaveInit(int size)
{
  int v1; // edi
  int v2; // eax
  CSaveRestoreData *v3; // eax
  CSaveRestoreData *v4; // esi
  char **v5; // eax

  v1 = size;
  if ( size <= 0 )
    v1 = 0x200000;
  v2 = (*(int (__thiscall **)(unsigned int, _DWORD))(*(_DWORD *)(cl_entitylist.m_Index + 131092) + 20))(
         a1: cl_entitylist.m_Index + 131092,
         a2: 0);
  v3 = (CSaveRestoreData *)engine->SaveAllocMemory(this: engine, a2: v1 + 56 * v2 + 1444, a3: 1);
  if ( v3 == nullptr )
    return nullptr;
  v4 = CSaveRestoreData::CSaveRestoreData(this: v3);
  v4->pBaseData = (char *)&v4[1];
  v4->pCurrentData = (char *)&v4[1];
  v4->size = 0;
  v4->bufferSize = v1;
  v5 = (char **)engine->SaveAllocMemory(this: engine, a2: 4095, a3: 4);
  if ( v5 == nullptr )
  {
    engine->SaveFreeMemory(this: engine, a2: nullptr);
    return nullptr;
  }
  v4->tokenCount = 4095;
  v4->pTokens = v5;
  memset(dst: (int)v5, value: nullptr, count: 0x3FFCu);
  v4->levelInfo.time = *(float *)(gpGlobals.m_Index + 12);
  v4->levelInfo.vecLandmarkOffset = vec3_origin;
  v4->levelInfo.fUseLandmark = 0;
  v4->levelInfo.connectionCount = 0;
  *(_DWORD *)(gpGlobals.m_Index + 44) = v4;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10237770
// Name: public: virtual int CRestore::ReadEdictPtr(struct edict_t __near * __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CRestore::ReadEdictPtr(CDragDropHelperPanel *this, int x, int y, bool traversePopups)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1041C220
// Name: entitytable_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *entitytable_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<entitytable_t>();
  entitytable_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C230
// Name: SaveRestoreBlockHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *SaveRestoreBlockHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<SaveRestoreBlockHeader_t>();
  SaveRestoreBlockHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C240
// Name: _dynamic_initializer_for__g_SaveRestoreBlockSet__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SaveRestoreBlockSet__()
{
  V_strncpy(pDest: g_SaveRestoreBlockSet.m_Name, pSrc: "Game", maxLen: 32);
  return atexit(func: dynamic_atexit_destructor_for__g_SaveRestoreBlockSet__);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10097A10
// Name: public: virtual class CGameSaveRestoreInfo __near * CRestore::GetGameSaveRestoreInfo(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::GetGameSaveRestoreInfo(CBaseAchievement *this)
{
  return this->m_iGoal;
}

//------------------------------------------------------------------------------
// Address: 0x101F7B30
// Name: public: bool CSaveRestoreSegment::Read(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSaveRestoreSegment::Read(CSaveRestoreSegment *this, unsigned __int8 *pOutput, int nBytes)
{
  int bufferSize; // ecx

  bufferSize = this->bufferSize;
  if ( bufferSize == this->size )
    return 0;
  if ( nBytes <= bufferSize - this->size )
  {
    if ( pOutput != nullptr )
      memcpy(dst: pOutput, src: (unsigned __int8 *)this->pCurrentData, count: nBytes);
    this->pCurrentData += nBytes;
    this->size += nBytes;
    return 1;
  }
  else
  {
    this->size = bufferSize;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F7B80
// Name: char const __near * UTIL_FunctionToName(struct datamap_t __near *,void (CBaseEntity::*)(struct inputdata_t __near &))
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl UTIL_FunctionToName(datamap_t *pMap, void (__thiscall *function)(CBaseEntity *this, inputdata_t *))
{
  datamap_t *v2; // esi
  int dataNumFields; // edx
  int v4; // ecx
  void (__thiscall **p_inputFunc)(CBaseEntity *, inputdata_t *); // eax

  v2 = pMap;
  if ( pMap == nullptr )
    return nullptr;
  while ( 1 )
  {
    dataNumFields = v2->dataNumFields;
    v4 = 0;
    if ( dataNumFields > 0 )
      break;
LABEL_7:
    v2 = v2->baseMap;
    if ( v2 == nullptr )
      return nullptr;
  }
  p_inputFunc = &v2->dataDesc->inputFunc;
  while ( (*((_BYTE *)p_inputFunc - 10) & 0x20) == 0 || *p_inputFunc != function )
  {
    ++v4;
    p_inputFunc += 15;
    if ( v4 >= dataNumFields )
      goto LABEL_7;
  }
  return v2->dataDesc[v4].fieldName;
}

//------------------------------------------------------------------------------
// Address: 0x101F7BE0
// Name: private: int CSave::DataEmpty(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSave::DataEmpty(CSave *this, const char *pdata, int size)
{
  const char *v3; // eax
  char v4; // dl

  if ( size == 4 )
    return *(_DWORD *)pdata == 0;
  v3 = pdata;
  if ( pdata >= &pdata[size] )
    return true;
  while ( 1 )
  {
    v4 = *v3++;
    if ( v4 != 0 )
      break;
    if ( v3 >= &pdata[size] )
      return true;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x101F7C20
// Name: public: virtual void CSave::StartLogging(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::StartLogging(CSave *this, const char *pszLogName)
{
  this->m_hLogFile = filesystem->Open(this: &filesystem->IBaseFileSystem, a2: pszLogName, a3: "w", a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101F7C50
// Name: public: virtual void CSave::EndLogging(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::EndLogging(CSave *this)
{
  void *m_hLogFile; // eax

  m_hLogFile = this->m_hLogFile;
  if ( m_hLogFile != nullptr )
    filesystem->Close(this: &filesystem->IBaseFileSystem, a2: m_hLogFile);
  this->m_hLogFile = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101F7C80
// Name: public: virtual bool CRestore::GetPrecacheMode(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRestore::GetPrecacheMode(CRestore *this)
{
  return this->m_precache;
}

//------------------------------------------------------------------------------
// Address: 0x101F7C90
// Name: public: virtual int CRestore::GetReadPos(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::GetReadPos(CRestore *this)
{
  return this->m_pData->size;
}

//------------------------------------------------------------------------------
// Address: 0x101F7CA0
// Name: public: virtual void CSave::SetWritePos(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::SetWritePos(CRestore *this, int pos)
{
  CSaveRestoreSegment *m_pData; // eax
  char *v3; // edx

  m_pData = this->m_pData;
  if ( pos >= 0 && pos < m_pData->bufferSize )
  {
    v3 = &m_pData->pBaseData[pos];
    m_pData->size = pos;
    m_pData->pCurrentData = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F7CC0
// Name: public: virtual void CSave::WriteVector(char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteVector(CSave *this, const char *pname, const Vector *value)
{
  this->WriteVector(this, a2: pname, a3: value, a4: 1);
}

//------------------------------------------------------------------------------
// Address: 0x101F7CE0
// Name: public: virtual void CSave::WriteQuaternion(char const __near *,class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteQuaternion(CSave *this, const char *pname, const Quaternion *value)
{
  this->WriteQuaternion(this, a2: pname, a3: value, a4: 1);
}

//------------------------------------------------------------------------------
// Address: 0x101F7D00
// Name: private: bool CSave::ShouldSaveField(void const __near *,struct typedescription_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSave::ShouldSaveField(CSave *this, char *pData, int pField)
{
  __int16 v5; // cx
  _fieldtypes v6; // edx
  char *v8; // ecx
  int v9; // eax
  ISaveRestoreOps *v10; // ecx
  char *v11; // eax
  __int16 v12; // ax
  datamap_t *v13; // ecx
  int v14; // ecx
  datamap_t *v15; // eax
  typedescription_t *dataDesc; // esi
  unsigned int v17; // ebx
  SaveRestoreFieldInfo_t fieldInfo; // [esp+8h] [ebp-10h] BYREF
  CSave *v19; // [esp+14h] [ebp-4h]
  int nFieldCount; // [esp+24h] [ebp+Ch]

  v5 = *(_WORD *)(pField + 14);
  v19 = this;
  if ( (v5 & 2) == 0 )
    return false;
  v6 = *(_DWORD *)pField;
  if ( *(_DWORD *)pField == 0 )
    return false;
  if ( v6 != FIELD_EMBEDDED )
  {
    if ( v6 == FIELD_CUSTOM )
    {
      v10 = *(ISaveRestoreOps **)(pField + 20);
      fieldInfo.pField = pData;
      v11 = &pData[-*(_DWORD *)(pField + 8)];
      fieldInfo.pTypeDesc = (typedescription_t *)pField;
      fieldInfo.pOwner = v11;
      return !v10->IsEmpty(this: v10, a2: &fieldInfo);
    }
    if ( v6 != FIELD_EHANDLE )
    {
      if ( *(_DWORD *)(pField + 32) != gSizes[v6] * *(unsigned __int16 *)(pField + 12) )
        _Warning(
          a1: "WARNING! Field %s is using the wrong FIELD_ type!\nFix this or you'll see a crash.\n",
          *(const char **)(pField + 4));
      return !CSave::DataEmpty(this, pdata: pData, size: gSizes[*(_DWORD *)pField] * *(unsigned __int16 *)(pField + 12));
    }
    if ( *(_DWORD *)(pField + 32) != gSizes[13] * *(unsigned __int16 *)(pField + 12) )
      _Warning(
        a1: "WARNING! Field %s is using the wrong FIELD_ type!\nFix this or you'll see a crash.\n",
        *(const char **)(pField + 4));
    v8 = pData;
    v9 = 0;
    if ( *(_WORD *)(pField + 12) != 0 )
    {
      while ( *(_DWORD *)v8 == -1 )
      {
        ++v9;
        v8 += 4;
        if ( v9 >= *(unsigned __int16 *)(pField + 12) )
          return false;
      }
      return true;
    }
    return false;
  }
  v12 = v5 & 0x40;
  if ( (v5 & 0x40) != 0 && *(_WORD *)(pField + 12) != 1 )
    return false;
  v13 = *(datamap_t **)(pField + 28);
  if ( v13 == nullptr || v12 != 0 && *(_DWORD *)pData == 0 )
    return false;
  if ( v13->baseMap != nullptr )
    return true;
  v14 = *(unsigned __int16 *)(pField + 12);
  if ( v12 != 0 )
    pData = *(char **)pData;
  nFieldCount = v14 - 1;
  if ( v14 - 1 < 0 )
    return false;
  while ( 1 )
  {
    v15 = *(datamap_t **)(pField + 28);
    dataDesc = v15->dataDesc;
    v17 = (unsigned int)&v15->dataDesc[v15->dataNumFields];
    if ( v15->dataDesc < (typedescription_t *)v17 )
      break;
LABEL_30:
    pData += *(_DWORD *)(pField + 32);
    if ( --nFieldCount < 0 )
      return false;
  }
  while ( !CSave::ShouldSaveField(this: v19, pData: &pData[dataDesc->fieldOffset], pField: dataDesc) )
  {
    if ( (unsigned int)++dataDesc >= v17 )
      goto LABEL_30;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x101F7EB0
// Name: private: bool CSave::WriteBasicField(char const __near *,void __near *,struct datamap_t __near *,struct typedescription_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSave::WriteBasicField(
        CSave *this,
        const char *pname,
        const Vector *pData,
        datamap_t *pRootMap,
        typedescription_t *pField)
{
  bool result; // al
  bool v8; // zf
  const Vector *x_low; // ebx
  ISaveRestoreOps *pSaveRestoreOps; // ecx
  char *v11; // eax
  SaveRestoreFieldInfo_t fieldInfo; // [esp+8h] [ebp-Ch] BYREF
  int nFieldCount; // [esp+28h] [ebp+14h]
  int nFieldCounta; // [esp+28h] [ebp+14h]

  switch ( pField->fieldType )
  {
    case FIELD_FLOAT:
      this->WriteFloat(this, a2: pField->fieldName, a3: (const float *)pData, a4: pField->fieldSize);
      result = true;
      break;
    case FIELD_STRING:
      this->WriteString(this, a2: pField->fieldName, a3: (const string_t *)pData, a4: pField->fieldSize);
      result = true;
      break;
    case FIELD_VECTOR:
      this->WriteVector(this, a2: pField->fieldName, a3: pData, a4: pField->fieldSize);
      result = true;
      break;
    case FIELD_QUATERNION:
      this->WriteQuaternion(this, a2: pField->fieldName, a3: (const Quaternion *)pData, a4: pField->fieldSize);
      result = true;
      break;
    case FIELD_INTEGER:
      this->WriteInt(this, a2: pField->fieldName, a3: (const int *)pData, a4: pField->fieldSize);
      result = true;
      break;
    case FIELD_BOOLEAN:
      this->WriteBool(this, a2: pField->fieldName, a3: (const bool *)pData, a4: pField->fieldSize);
      result = true;
      break;
    case FIELD_SHORT:
      this->WriteData(this, a2: pField->fieldName, a3: 2 * pField->fieldSize, a4: (const char *)pData);
      result = true;
      break;
    case FIELD_CHARACTER:
      this->WriteData(this, a2: pField->fieldName, a3: pField->fieldSize, a4: (const char *)pData);
      result = true;
      break;
    case FIELD_COLOR32:
      this->WriteData(this, a2: pField->fieldName, a3: 4 * pField->fieldSize, a4: (const char *)pData);
      result = true;
      break;
    case FIELD_EMBEDDED:
      v8 = (pField->flags & 0x40) == 0;
      nFieldCount = pField->fieldSize;
      if ( v8 )
        x_low = pData;
      else
        x_low = (const Vector *)LODWORD(pData->x);
      this->StartBlock_2(this, a2: pField->fieldName);
      for ( nFieldCounta = nFieldCount - 1; nFieldCounta >= 0; --nFieldCounta )
      {
        this->WriteAll(this, a2: x_low, a3: pField->td);
        x_low = (const Vector *)((char *)x_low + pField->fieldSizeInBytes);
      }
      this->EndBlock(this);
      result = true;
      break;
    case FIELD_CUSTOM:
      this->StartBlock_2(this, a2: pField->fieldName);
      pSaveRestoreOps = pField->pSaveRestoreOps;
      fieldInfo.pField = (void *)pData;
      v11 = (char *)pData - pField->fieldOffset;
      fieldInfo.pTypeDesc = pField;
      fieldInfo.pOwner = v11;
      pSaveRestoreOps->Save(this: pSaveRestoreOps, a2: &fieldInfo, a3: this);
      this->EndBlock(this);
      goto $LN16_6;
    case FIELD_INTEGER64:
$LN16_6:
      result = true;
      break;
    default:
      _Warning(a1: "Bad field type\n");
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F8100
// Name: private: int CSave::DoWriteAll(void const __near *,struct datamap_t __near *,struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSave::DoWriteAll(CSave *this, const void *pLeafObject, datamap_t *pLeafMap, datamap_t *pCurMap)
{
  int result; // eax

  if ( pCurMap->baseMap == nullptr )
    return this->WriteFields(
             this,
             a2: pCurMap->dataClassName,
             a3: pLeafObject,
             a4: pLeafMap,
             a5: pCurMap->dataDesc,
             a6: pCurMap->dataNumFields);
  result = CSave::DoWriteAll(this, pLeafObject, pLeafMap, pCurMap: pCurMap->baseMap);
  if ( result != 0 )
    return this->WriteFields(
             this,
             a2: pCurMap->dataClassName,
             a3: pLeafObject,
             a4: pLeafMap,
             a5: pCurMap->dataDesc,
             a6: pCurMap->dataNumFields);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F8150
// Name: public: virtual void CSave::StartBlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::StartBlock(CSave *this)
{
  this->StartBlock_2(this, a2: locale);
}

//------------------------------------------------------------------------------
// Address: 0x101F8160
// Name: private: void CSave::BufferData(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSave::BufferData(CSave *this@<ecx>, const char *a2@<edi>, char *pdata, int size)
{
  CSaveRestoreSegment *m_pData; // esi
  CSaveRestoreSegment *v6; // eax
  int v7; // [esp-8h] [ebp-10h]

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    if ( size <= m_pData->bufferSize - m_pData->size )
    {
      memcpy(dst: (unsigned __int8 *)m_pData->pCurrentData, src: (unsigned __int8 *)pdata, count: size);
      m_pData->pCurrentData += size;
      m_pData->size += size;
      s_SaveOverflow = 0;
    }
    else
    {
      m_pData->size = m_pData->bufferSize;
      if ( (unsigned __int8)_Plat_IsInDebugSession() != 0 )
        __debugbreak();
      else
        _Error(this: (ISceneTokenProcessor *)&stru_104B19E8, a2);
      v6 = this->m_pData;
      v7 = v6->bufferSize - v6->size;
      s_SaveOverflow += size;
      _Warning(a1: "Save/Restore overflow %d [%d, %d]!\n", s_SaveOverflow, v6->bufferSize, v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F8200
// Name: public: int CSave::EntityFlagsSet(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSave::EntityFlagsSet(CSave *this, int entityIndex, int flags)
{
  CGameSaveRestoreInfo *m_pGameInfo; // eax

  m_pGameInfo = this->m_pGameInfo;
  if ( m_pGameInfo == nullptr || entityIndex < 0 || entityIndex > m_pGameInfo->tableCount )
    return 0;
  this->m_pGameInfo->pTable[entityIndex].flags |= flags;
  return this->m_pGameInfo->pTable[entityIndex].flags;
}

//------------------------------------------------------------------------------
// Address: 0x101F8260
// Name: public: virtual void CSave::WriteTime(float const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteTime(CSave *this, const float *data, float count)
{
  float v3; // ebx
  int v4; // esi
  float v6; // xmm0_4

  v3 = count;
  v4 = 0;
  if ( SLODWORD(count) > 0 )
  {
    while ( 1 )
    {
      v6 = data[v4];
      if ( v6 == 0.0 )
        break;
      if ( v6 == -3.402823466385289e38 || v6 == 3.4028235e38 )
        goto LABEL_8;
      count = v6 - this->m_pGameInfo->levelInfo.time;
      if ( COERCE_FLOAT(LODWORD(count) & _mask__AbsFloat_) < 0.001 )
      {
        v6 = 0.001;
        goto LABEL_8;
      }
LABEL_9:
      this->WriteData_2(this, a2: (const char *)&count, a3: 4);
      if ( ++v4 >= SLODWORD(v3) )
        return;
    }
    v6 = -1.7014117e38;
LABEL_8:
    count = v6;
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F8320
// Name: public: virtual void CSave::WriteTick(int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteTick(CSave *this, const int *data, int count)
{
  int v3; // ebx
  int v5; // esi
  int v6; // eax
  int baseTick; // [esp+Ch] [ebp-4h]

  v3 = count;
  v5 = 0;
  for ( baseTick = (int)(float)((float)(this->m_pGameInfo->levelInfo.time / gpGlobals->interval_per_tick) + 0.5);
        v5 < v3;
        ++v5 )
  {
    v6 = data[v5];
    if ( v6 == -1 )
      count = 2147483644;
    else
      count = v6 - baseTick;
    this->WriteData_2(this, a2: (const char *)&count, a3: 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F8390
// Name: public: virtual char const __near * CRestore::StringFromHeaderSymbol(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CRestore::StringFromHeaderSymbol(CRestore *this, int symbol)
{
  CSaveRestoreSegment *m_pData; // eax
  const char *result; // eax

  m_pData = this->m_pData;
  if ( symbol < 0 || symbol >= m_pData->tokenCount )
    return "<<illegal>>";
  result = m_pData->pTokens[symbol];
  if ( result == nullptr )
    return locale;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F83C0
// Name: private: void CRestore::ReadBasicField(struct SaveRestoreRecordHeader_t const __near &,void __near *,struct datamap_t __near *,struct typedescription_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRestore::ReadBasicField(
        CRestore *this,
        const SaveRestoreRecordHeader_t *header,
        Vector *pDest,
        datamap_t *pRootMap,
        typedescription_t *pField)
{
  float x; // ebx
  CRestore_vtbl *v7; // ebx
  int v8; // eax
  int v9; // eax
  int size; // ecx
  int v11; // ebx
  ISaveRestoreOps *pSaveRestoreOps; // ecx
  SaveRestoreFieldInfo_t fieldInfo; // [esp+Ch] [ebp-Ch] BYREF
  int nFieldCount; // [esp+20h] [ebp+8h]

  switch ( pField->fieldType )
  {
    case FIELD_FLOAT:
      this->ReadFloat(this, a2: (float *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_STRING:
      this->ReadString(this, a2: (string_t *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_VECTOR:
      this->ReadVector(this, a2: pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_QUATERNION:
      this->ReadQuaternion(this, a2: (Quaternion *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_INTEGER:
    case FIELD_COLOR32:
      this->ReadInt_2(this, a2: (int *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_BOOLEAN:
      this->ReadBool(this, a2: (bool *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_SHORT:
      this->ReadShort(this, a2: (__int16 *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_CHARACTER:
      this->ReadData(this, a2: (char *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_EMBEDDED:
      x = *(float *)&pDest;
      if ( (pField->flags & 0x40) == 0 || LODWORD(pDest->x) != 0 )
      {
        if ( (pField->flags & 0x40) != 0 )
          x = pDest->x;
        for ( nFieldCount = pField->fieldSize - 1; nFieldCount >= 0; --nFieldCount )
        {
          this->ReadAll(this, a2: (void *)LODWORD(x), a3: pField->td);
          LODWORD(x) += pField->fieldSizeInBytes;
        }
      }
      else
      {
        v7 = this->__vftable;
        v8 = this->GetReadPos(this);
        v7->SetReadPos(this, a2: header->size + v8);
        _Warning(
          a1: "Attempted to restore FIELD_EMBEDDEDBYREF %s but there is no destination memory\n",
          pField->fieldName);
      }
      break;
    case FIELD_CUSTOM:
      v9 = this->GetReadPos(this);
      size = header->size;
      fieldInfo.pField = (void *)pDest;
      v11 = size + v9;
      pSaveRestoreOps = pField->pSaveRestoreOps;
      fieldInfo.pOwner = (char *)pDest - pField->fieldOffset;
      fieldInfo.pTypeDesc = pField;
      pSaveRestoreOps->Restore(this: pSaveRestoreOps, a2: &fieldInfo, a3: this);
      this->SetReadPos(this, a2: v11);
      break;
    case FIELD_INTEGER64:
      return;
    default:
      _Warning(a1: "Bad field type\n");
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F8620
// Name: private: struct typedescription_t __near * CRestore::FindField(char const __near *,struct typedescription_t __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
typedescription_t *__thiscall CRestore::FindField(
        CRestore *this,
        const char *pszFieldName,
        typedescription_t *pFields,
        int fieldCount,
        int *pCookie)
{
  int v6; // eax
  typedescription_t *v7; // ebx
  int i; // [esp+20h] [ebp+14h]

  if ( pszFieldName != nullptr && (i = 0, fieldCount > 0) )
  {
    while ( 1 )
    {
      v6 = *pCookie + 1;
      v7 = &pFields[*pCookie];
      *pCookie = v6;
      if ( v6 == fieldCount )
        *pCookie = 0;
      if ( _V_stricmp(s1: v7->fieldName, s2: pszFieldName) == 0 )
        return v7;
      if ( ++i >= fieldCount )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    *pCookie = 0;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F86A0
// Name: public: virtual void CRestore::EmptyFields(void __near *,struct typedescription_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRestore::EmptyFields(CRestore *this, char *pBaseData, typedescription_t *pFields, int fieldCount)
{
  ISaveRestoreOps **p_pSaveRestoreOps; // esi
  __int16 v5; // ax
  _DWORD *v6; // edi
  ISaveRestoreOps *v7; // ecx
  int i; // ebx
  SaveRestoreFieldInfo_t fieldInfo; // [esp+0h] [ebp-10h] BYREF
  CRestore *v10; // [esp+Ch] [ebp-4h]

  v10 = this;
  if ( fieldCount > 0 )
  {
    p_pSaveRestoreOps = &pFields->pSaveRestoreOps;
    do
    {
      v5 = *((_WORD *)p_pSaveRestoreOps - 3);
      if ( (v5 & 2) != 0 && (v10->m_global == 0 || (v5 & 1) == 0) )
      {
        v6 = (ISaveRestoreOps_vtbl **)((char *)&(*(p_pSaveRestoreOps - 3))->__vftable + (_DWORD)pBaseData);
        if ( *(p_pSaveRestoreOps - 5) == (ISaveRestoreOps *)10 )
        {
          if ( (*((_WORD *)p_pSaveRestoreOps - 3) & 0x40) == 0 || *v6 != 0 )
          {
            if ( (*((_WORD *)p_pSaveRestoreOps - 3) & 0x40) != 0 )
              v6 = (_DWORD *)*v6;
            for ( i = *((unsigned __int16 *)p_pSaveRestoreOps - 4) - 1; i >= 0; --i )
            {
              v10->EmptyFields(
                this: v10,
                a2: v6,
                a3: (typedescription_t *)p_pSaveRestoreOps[2]->__vftable,
                a4: (int)p_pSaveRestoreOps[2][1].__vftable);
              v6 = (_DWORD *)((char *)v6 + (_DWORD)p_pSaveRestoreOps[3]);
            }
          }
        }
        else if ( *(p_pSaveRestoreOps - 5) == (ISaveRestoreOps *)11 )
        {
          v7 = *p_pSaveRestoreOps;
          fieldInfo.pOwner = pBaseData;
          fieldInfo.pField = v6;
          fieldInfo.pTypeDesc = (typedescription_t *)(p_pSaveRestoreOps - 5);
          v7->MakeEmpty(this: v7, a2: &fieldInfo);
        }
        else
        {
          if ( p_pSaveRestoreOps[3] != (ISaveRestoreOps *)(gSizes[(_DWORD)*(p_pSaveRestoreOps - 5)]
                                                         * *((unsigned __int16 *)p_pSaveRestoreOps - 4)) )
            _Warning(
              a1: "WARNING! Field %s is using the wrong FIELD_ type!\nFix this or you'll see a crash.\n",
              (const char *)*(p_pSaveRestoreOps - 4));
          memset(
            dst: (int)v6,
            value: (unsigned __int8 *)(unsigned __int8)((*(p_pSaveRestoreOps - 5) != (ISaveRestoreOps *)13) - 1),
            count: gSizes[(_DWORD)*(p_pSaveRestoreOps - 5)] * *((unsigned __int16 *)p_pSaveRestoreOps - 4));
        }
      }
      p_pSaveRestoreOps += 15;
      --fieldCount;
    }
    while ( fieldCount != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F87B0
// Name: public: virtual void CRestore::StartBlock(char __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRestore::StartBlock(CRestore *this, char *szBlockName)
{
  const char *v3; // eax
  int symbol; // [esp-4h] [ebp-Ch]
  SaveRestoreRecordHeader_t header; // [esp+4h] [ebp-4h] BYREF

  this->StartBlock_3(this, a2: &header);
  symbol = header.symbol;
  v3 = (const char *)((int (__thiscall *)(CRestore *))this->StringFromHeaderSymbol)(a1: this);
  V_strncpy(pDest: szBlockName, pSrc: v3, maxLen: symbol);
}

//------------------------------------------------------------------------------
// Address: 0x101F87F0
// Name: public: virtual void CRestore::StartBlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRestore::StartBlock(CRestore *this)
{
  char szBlockName[32]; // [esp+0h] [ebp-20h] BYREF

  this->StartBlock_2(this, a2: szBlockName);
}

//------------------------------------------------------------------------------
// Address: 0x101F8810
// Name: public: virtual int CRestore::ScanAheadForHammerID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ScanAheadForHammerID(CRestore *this)
{
  int v2; // ebx
  int v3; // edi
  CSaveRestoreSegment *m_pData; // ecx
  const char *v5; // eax
  bool v6; // zf
  CSaveRestoreSegment *v7; // eax
  int size; // ecx
  int v9; // ecx
  int v10; // edi
  char *pCurrentData; // edx
  CSaveRestoreSegment *v12; // esi
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int oldPosition; // [esp+Ch] [ebp-Ch]
  int iHammerID; // [esp+10h] [ebp-8h]
  SaveRestoreRecordHeader_t header; // [esp+14h] [ebp-4h] BYREF

  oldPosition = this->m_pData->size;
  iHammerID = -1;
  this->ReadShort_2(this);
  this->ReadShort_2(this);
  v2 = this->ReadInt(this);
  v3 = 0;
  if ( v2 > 0 )
  {
    while ( 1 )
    {
      this->ReadHeader(this, a2: &header);
      m_pData = this->m_pData;
      v5 = header.symbol >= m_pData->tokenCount ? "<<illegal>>" : m_pData->pTokens[header.symbol];
      v6 = _V_stricmp(s1: "m_iHammerID", s2: v5) == 0;
      v7 = this->m_pData;
      if ( v6 )
        break;
      size = header.size;
      v7->pCurrentData += header.size;
      v7->size += size;
      if ( ++v3 >= v2 )
        goto LABEL_12;
    }
    v9 = v7->size;
    v10 = v7->bufferSize - v9;
    if ( v10 != 0 )
    {
      if ( v10 >= 4 )
      {
        pCurrentData = v7->pCurrentData;
        iHammerID = *(_DWORD *)pCurrentData;
        v7->pCurrentData = pCurrentData + 4;
        v7->size = v9 + 4;
      }
      else
      {
        v7->size = v7->bufferSize;
      }
    }
  }
LABEL_12:
  v12 = this->m_pData;
  v13 = v12->size - oldPosition;
  v14 = v12->size;
  if ( v14 < v13 )
    v13 = v12->size;
  v15 = -v13;
  v12->pCurrentData += v15;
  v16 = v15 + v14;
  v12->size = v16;
  return iHammerID;
}

//------------------------------------------------------------------------------
// Address: 0x101F88F0
// Name: public: virtual void CRestore::SkipEntityData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRestore::SkipEntityData(CRestore *this)
{
  int v2; // eax
  int i; // edi
  int size; // ecx
  CSaveRestoreSegment *m_pData; // eax
  SaveRestoreRecordHeader_t header; // [esp+4h] [ebp-4h] BYREF

  v2 = this->ReadInt(this);
  if ( v2 > 0 )
  {
    for ( i = v2; i != 0; --i )
    {
      this->ReadHeader(this, a2: &header);
      size = header.size;
      m_pData = this->m_pData;
      m_pData->pCurrentData += header.size;
      m_pData->size += size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F8930
// Name: private: int CRestore::DoReadAll(void __near *,struct datamap_t __near *,struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::DoReadAll(CRestore *this, void *pLeafObject, datamap_t *pLeafMap, datamap_t *pCurMap)
{
  int result; // eax

  if ( pCurMap->baseMap == nullptr )
    return this->ReadFields(
             this,
             a2: pCurMap->dataClassName,
             a3: pLeafObject,
             a4: pLeafMap,
             a5: pCurMap->dataDesc,
             a6: pCurMap->dataNumFields);
  result = CRestore::DoReadAll(this, pLeafObject, pLeafMap, pCurMap: pCurMap->baseMap);
  if ( result != 0 )
    return this->ReadFields(
             this,
             a2: pCurMap->dataClassName,
             a3: pLeafObject,
             a4: pLeafMap,
             a5: pCurMap->dataDesc,
             a6: pCurMap->dataNumFields);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F8980
// Name: public: virtual void CRestore::ReadString(char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRestore::ReadString(CRestore *this, char *pDest, int nSizeDest, int nBytesAvailable)
{
  CSaveRestoreSegment *m_pData; // ecx
  const char *pCurrentData; // ebx
  signed int v6; // eax
  int size; // edx
  signed int v8; // esi

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
    pCurrentData = m_pData->pCurrentData;
  else
    pCurrentData = nullptr;
  v6 = nBytesAvailable;
  if ( nBytesAvailable == 0 )
    v6 = strlen(pCurrentData) + 1;
  if ( m_pData != nullptr && m_pData->bufferSize != m_pData->size )
  {
    size = m_pData->size;
    v8 = m_pData->bufferSize - size;
    if ( v8 != 0 )
    {
      if ( v6 <= v8 )
      {
        m_pData->pCurrentData += v6;
        m_pData->size = v6 + size;
        goto LABEL_12;
      }
      m_pData->size = m_pData->bufferSize;
    }
    _Warning(a1: "Restore underflow!\n");
  }
LABEL_12:
  V_strncpy(pDest, pSrc: pCurrentData, maxLen: nSizeDest);
}

//------------------------------------------------------------------------------
// Address: 0x101F8A00
// Name: public: virtual int CRestore::ReadVector(class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadVector(CRestore *this, Vector *pValue)
{
  CSaveRestoreSegment *m_pData; // ecx

  m_pData = this->m_pData;
  if ( m_pData != nullptr
    && m_pData->bufferSize != m_pData->size
    && CSaveRestoreSegment::Read(this: m_pData, pOutput: (unsigned __int8 *)pValue, nBytes: 12) == 0 )
  {
    _Warning(a1: "Restore underflow!\n");
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F8A40
// Name: public: virtual int CRestore::ReadQuaternion(class Quaternion __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadQuaternion(CRestore *this, Quaternion *pValue)
{
  CSaveRestoreSegment *m_pData; // ecx

  m_pData = this->m_pData;
  if ( m_pData != nullptr
    && m_pData->bufferSize != m_pData->size
    && CSaveRestoreSegment::Read(this: m_pData, pOutput: (unsigned __int8 *)pValue, nBytes: 16) == 0 )
  {
    _Warning(a1: "Restore underflow!\n");
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F8A80
// Name: public: virtual int CRestore::ReadTime(float __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __userpurge CRestore::ReadTime@<eax>(
        CRestore *this@<ecx>,
        int a2@<edi>,
        float *pValue,
        int count,
        int nBytesAvailable)
{
  unsigned int result; // eax
  int v6; // edx
  unsigned int v7; // esi
  float *v8; // ecx
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float baseTime; // [esp+0h] [ebp-4h]

  baseTime = this->m_pGameInfo->levelInfo.time;
  result = ((int (__thiscall *)(CRestore *, float *, int, int, int))this->ReadFloat)(
             a1: this,
             a2: pValue,
             a3: count,
             a4: nBytesAvailable,
             a5: a2);
  v6 = result - 1;
  if ( (int)(result - 1) >= 0 )
  {
    if ( (int)result >= 4 )
    {
      v7 = result >> 2;
      v8 = &pValue[v6 - 2];
      v6 -= 4 * (result >> 2);
      do
      {
        v9 = v8[2];
        if ( v9 == -1.701411733192644e38 )
        {
          v8[2] = 0.0;
        }
        else if ( v9 != -3.402823466385289e38 && v9 != 3.4028235e38 )
        {
          v8[2] = v9 + baseTime;
        }
        v10 = v8[1];
        if ( v10 == -1.701411733192644e38 )
        {
          v8[1] = 0.0;
        }
        else if ( v10 != -3.402823466385289e38 && v10 != 3.4028235e38 )
        {
          v8[1] = v10 + baseTime;
        }
        v11 = *v8;
        if ( *v8 == -1.701411733192644e38 )
        {
          *v8 = 0.0;
        }
        else if ( v11 != -3.402823466385289e38 && v11 != 3.4028235e38 )
        {
          *v8 = v11 + baseTime;
        }
        v12 = *(v8 - 1);
        if ( v12 == -1.701411733192644e38 )
        {
          *(v8 - 1) = 0.0;
        }
        else if ( v12 != -3.402823466385289e38 && v12 != 3.4028235e38 )
        {
          *(v8 - 1) = v12 + baseTime;
        }
        v8 -= 4;
        --v7;
      }
      while ( v7 != 0 );
    }
    for ( ; v6 >= 0; --v6 )
    {
      v13 = pValue[v6];
      if ( v13 == -1.701411733192644e38 )
      {
        pValue[v6] = 0.0;
      }
      else if ( v13 != -3.402823466385289e38 && v13 != 3.4028235e38 )
      {
        pValue[v6] = v13 + baseTime;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F8C30
// Name: public: virtual int CRestore::ReadTick(int __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadTick(CRestore *this, int *pValue, int count, int nBytesAvailable)
{
  int v4; // edi
  int result; // eax
  int i; // ecx
  int v7; // edx

  v4 = (int)(float)((float)((float)(this->m_pGameInfo->levelInfo.time + 0.1) / gpGlobals->interval_per_tick) + 0.5);
  result = this->ReadInt_2(this, a2: pValue, a3: count, a4: nBytesAvailable);
  for ( i = result - 1; i >= 0; --i )
  {
    v7 = pValue[i];
    if ( v7 == 2147483644 )
      pValue[i] = -1;
    else
      pValue[i] = v4 + v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F8CB0
// Name: public: virtual int CRestore::ReadPositionVector(class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadPositionVector(CRestore *this, Vector *pValue)
{
  return this->ReadPositionVector(this, a2: pValue, a3: 1, a4: 12);
}

//------------------------------------------------------------------------------
// Address: 0x101F8CD0
// Name: public: virtual int CRestore::ReadPositionVector(class Vector __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __userpurge CRestore::ReadPositionVector@<eax>(
        CRestore *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        Vector *pValue,
        int count,
        int nBytesAvailable)
{
  CGameSaveRestoreInfo *m_pGameInfo; // eax
  Vector *p_vecLandmarkOffset; // eax
  unsigned int result; // eax
  int v9; // edx
  unsigned int v10; // esi
  float *p_z; // ecx
  float *v12; // ecx
  __int64 basePosition; // [esp+0h] [ebp-Ch]
  float basePosition_8; // [esp+8h] [ebp-4h]

  m_pGameInfo = this->m_pGameInfo;
  if ( m_pGameInfo->levelInfo.fUseLandmark != 0 )
    p_vecLandmarkOffset = &m_pGameInfo->levelInfo.vecLandmarkOffset;
  else
    p_vecLandmarkOffset = &vec3_origin;
  basePosition_8 = p_vecLandmarkOffset->z;
  basePosition = *(_QWORD *)&p_vecLandmarkOffset->x;
  result = ((int (__thiscall *)(CRestore *, Vector *, int, int, int, int))this->ReadVector)(
             a1: this,
             a2: pValue,
             a3: count,
             a4: nBytesAvailable,
             a5: a3,
             a6: a2);
  v9 = result - 1;
  if ( (int)(result - 1) >= 0 )
  {
    if ( (int)result >= 4 )
    {
      v10 = result >> 2;
      p_z = &pValue[v9 - 1].z;
      v9 -= 4 * (result >> 2);
      do
      {
        if ( vec3_invalid.x != p_z[1] || vec3_invalid.y != p_z[2] || vec3_invalid.z != p_z[3] )
        {
          p_z[1] = p_z[1] + *(float *)&basePosition;
          p_z[2] = p_z[2] + *((float *)&basePosition + 1);
          p_z[3] = basePosition_8 + p_z[3];
        }
        if ( vec3_invalid.x != *(p_z - 2) || vec3_invalid.y != *(p_z - 1) || vec3_invalid.z != *p_z )
        {
          *(p_z - 2) = *(p_z - 2) + *(float *)&basePosition;
          *(p_z - 1) = *(p_z - 1) + *((float *)&basePosition + 1);
          *p_z = basePosition_8 + *p_z;
        }
        if ( vec3_invalid.x != *(p_z - 5) || vec3_invalid.y != *(p_z - 4) || vec3_invalid.z != *(p_z - 3) )
        {
          *(p_z - 5) = *(p_z - 5) + *(float *)&basePosition;
          *(p_z - 4) = *(p_z - 4) + *((float *)&basePosition + 1);
          *(p_z - 3) = basePosition_8 + *(p_z - 3);
        }
        if ( vec3_invalid.x != *(p_z - 8) || vec3_invalid.y != *(p_z - 7) || vec3_invalid.z != *(p_z - 6) )
        {
          *(p_z - 8) = *(p_z - 8) + *(float *)&basePosition;
          *(p_z - 7) = *(p_z - 7) + *((float *)&basePosition + 1);
          *(p_z - 6) = *(p_z - 6) + basePosition_8;
        }
        p_z -= 12;
        --v10;
      }
      while ( v10 != 0 );
    }
    if ( v9 >= 0 )
    {
      v12 = &pValue[v9].z;
      do
      {
        if ( vec3_invalid.x != *(v12 - 2) || vec3_invalid.y != *(v12 - 1) || vec3_invalid.z != *v12 )
        {
          *(v12 - 2) = *(v12 - 2) + *(float *)&basePosition;
          *(v12 - 1) = *(v12 - 1) + *((float *)&basePosition + 1);
          *v12 = *v12 + basePosition_8;
        }
        v12 -= 3;
        --v9;
      }
      while ( v9 >= 0 );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F8F50
// Name: public: virtual int CEntitySaveUtils::GetEntityDependencyCount(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEntitySaveUtils::GetEntityDependencyCount(CEntitySaveUtils *this, CBaseEntity *pEntity)
{
  return this->m_pLevelAdjacencyDependencyHash->GetPairCountForObject(
           this: this->m_pLevelAdjacencyDependencyHash,
           a2: pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x101F8F60
// Name: public: virtual int CEntitySaveUtils::GetEntityDependencies(class CBaseEntity __near *,int,class CBaseEntity __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEntitySaveUtils::GetEntityDependencies(
        CEntitySaveUtils *this,
        CBaseEntity *pEntity,
        int nCount,
        CBaseEntity **ppEntList)
{
  return this->m_pLevelAdjacencyDependencyHash->GetPairListForObject(
           this: this->m_pLevelAdjacencyDependencyHash,
           a2: pEntity,
           a3: nCount,
           a4: (void **)ppEntList);
}

//------------------------------------------------------------------------------
// Address: 0x101F8F70
// Name: public: virtual void CEntitySaveUtils::AddLevelTransitionSaveDependency(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntitySaveUtils::AddLevelTransitionSaveDependency(
        CEntitySaveUtils *this,
        CBaseEntity *pEntity1,
        CBaseEntity *pEntity2)
{
  if ( pEntity1 != pEntity2 )
    this->m_pLevelAdjacencyDependencyHash->AddObjectPair(
      this: this->m_pLevelAdjacencyDependencyHash,
      a2: pEntity1,
      a3: pEntity2);
}

//------------------------------------------------------------------------------
// Address: 0x101F8F90
// Name: class ISaveRestoreBlockHandler __near * GetEntitySaveRestoreBlockHandler(void)
// Source: json
//------------------------------------------------------------------------------
CEntitySaveRestoreBlockHandler *__cdecl GetEntitySaveRestoreBlockHandler()
{
  return &g_EntitySaveRestoreBlockHandler;
}

//------------------------------------------------------------------------------
// Address: 0x101F8FA0
// Name: public: virtual char const __near * CEntitySaveRestoreBlockHandler::GetBlockName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CEntitySaveRestoreBlockHandler::GetBlockName(CEntitySaveRestoreBlockHandler *this)
{
  return "Entities";
}

//------------------------------------------------------------------------------
// Address: 0x101F8FB0
// Name: public: virtual void CEntitySaveRestoreBlockHandler::WriteSaveHeaders(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntitySaveRestoreBlockHandler::WriteSaveHeaders(CEntitySaveRestoreBlockHandler *this, ISave *pSave)
{
  CGameSaveRestoreInfo *v3; // eax
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  CGameSaveRestoreInfo *v5; // edi
  int v6; // ebx
  int nEntities; // [esp+Ch] [ebp-4h] BYREF
  ISave *pSavea; // [esp+18h] [ebp+8h]

  v3 = pSave->GetGameSaveRestoreInfo(this: pSave);
  WriteInt_2 = pSave->WriteInt_2;
  v5 = v3;
  nEntities = v3->tableCount;
  WriteInt_2(this: pSave, a2: &nEntities, a3: 1);
  v6 = 0;
  if ( v5->tableCount > 0 )
  {
    pSavea = nullptr;
    do
    {
      pSave->WriteFields(
        this: pSave,
        a2: "ETABLE",
        a3: (char *)pSavea + (unsigned int)v5->pTable,
        a4: nullptr,
        a5: entitytable_t::m_DataMap.dataDesc,
        a6: entitytable_t::m_DataMap.dataNumFields);
      pSavea += 14;
      ++v6;
    }
    while ( v6 < v5->tableCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F9030
// Name: public: virtual void CEntitySaveRestoreBlockHandler::PostSave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntitySaveRestoreBlockHandler::PostSave(CEntitySaveRestoreBlockHandler *this)
{
  physics->DestroyObjectPairHash(this: physics, a2: this->m_EntitySaveUtils.m_pLevelAdjacencyDependencyHash);
  this->m_EntitySaveUtils.m_pLevelAdjacencyDependencyHash = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101F9050
// Name: private: class Vector CEntitySaveRestoreBlockHandler::ModelSpaceLandmark(int)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CEntitySaveRestoreBlockHandler::ModelSpaceLandmark(
        CEntitySaveRestoreBlockHandler *this,
        Vector *result,
        int modelIndex)
{
  const struct model_t *v3; // esi
  Vector *v4; // eax
  float z; // ecx
  Vector maxs; // [esp+4h] [ebp-18h] BYREF
  Vector mins; // [esp+10h] [ebp-Ch] BYREF

  v3 = modelinfo->GetModel(this: modelinfo, a2: modelIndex);
  if ( modelinfo->GetModelType(this: modelinfo, a2: v3) == 1 )
  {
    modelinfo->GetModelBounds(this: modelinfo, a2: v3, a3: &mins, a4: &maxs);
    v4 = result;
    z = mins.z;
    *(_QWORD *)&result->x = *(_QWORD *)&mins.x;
  }
  else
  {
    v4 = result;
    z = vec3_origin.z;
    *(_QWORD *)&result->x = *(_QWORD *)&vec3_origin.x;
  }
  result->z = z;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101F90D0
// Name: bool ParseKeyvalue(void __near *,struct typedescription_t __near *,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ParseKeyvalue(
        _BYTE *pObject,
        typedescription_t *pFields,
        int iNumFields,
        const char *szKeyName,
        const char *szValue)
{
  unsigned __int16 *p_fieldSize; // eax
  int v6; // edi
  int v7; // esi
  typedescription_t *v8; // esi
  bool result; // al
  ISaveRestoreOps *pSaveRestoreOps; // ecx
  SaveRestoreFieldInfo_t fieldInfo; // [esp+Ch] [ebp-18h] BYREF
  char pszValue[4]; // [esp+18h] [ebp-Ch] BYREF
  int i; // [esp+1Ch] [ebp-8h]
  unsigned __int16 *v14; // [esp+20h] [ebp-4h]

  i = 0;
  if ( iNumFields <= 0 )
    return false;
  p_fieldSize = &pFields->fieldSize;
  v14 = &pFields->fieldSize;
  while ( 1 )
  {
    v6 = *((_DWORD *)p_fieldSize - 1);
    if ( *((_DWORD *)p_fieldSize - 3) == 10 && *p_fieldSize == 1 )
      break;
LABEL_9:
    v8 = (typedescription_t *)(p_fieldSize - 6);
    if ( (p_fieldSize[1] & 4) != 0 )
    {
      if ( _V_stricmp(s1: v8->externalName, s2: szKeyName) == 0 )
      {
        switch ( v8->fieldType )
        {
          case FIELD_FLOAT:
          case FIELD_TIME:
            *(float *)&pObject[v6] = atof(nptr: szValue);
            result = true;
            break;
          case FIELD_STRING:
          case FIELD_MODELNAME:
          case FIELD_SOUNDNAME:
            *(_DWORD *)&pObject[v6] = *(_DWORD *)AllocPooledString(pszValue).pszValue;
            return true;
          case FIELD_VECTOR:
          case FIELD_POSITION_VECTOR:
            UTIL_StringToVector(pVector: (float *)&pObject[v6], pString: szValue);
            result = true;
            break;
          case FIELD_INTEGER:
          case FIELD_TICK:
            *(_DWORD *)&pObject[v6] = atoi(nptr: szValue);
            result = true;
            break;
          case FIELD_BOOLEAN:
            pObject[v6] = atoi(nptr: szValue) != 0;
            result = true;
            break;
          case FIELD_SHORT:
            *(_WORD *)&pObject[v6] = atoi(nptr: szValue);
            result = true;
            break;
          case FIELD_CHARACTER:
            pObject[v6] = atoi(nptr: szValue);
            result = true;
            break;
          case FIELD_COLOR32:
            V_StringToColor32(color: (color32_s *)&pObject[v6], pString: szValue);
            result = true;
            break;
          case FIELD_CUSTOM:
            pSaveRestoreOps = v8->pSaveRestoreOps;
            fieldInfo.pOwner = pObject;
            fieldInfo.pField = &pObject[v6];
            fieldInfo.pTypeDesc = v8;
            pSaveRestoreOps->Parse(this: pSaveRestoreOps, a2: &fieldInfo, a3: szValue);
            result = true;
            break;
          case FIELD_VMATRIX:
          case FIELD_VMATRIX_WORLDSPACE:
            UTIL_StringToFloatArray(pVector: (float *)&pObject[v6], count: 16, pString: szValue);
            result = true;
            break;
          case FIELD_MATRIX3X4_WORLDSPACE:
            UTIL_StringToFloatArray(pVector: (float *)&pObject[v6], count: 12, pString: szValue);
            result = true;
            break;
          default:
            _Warning(a1: "Bad field in entity!!\n");
            goto LABEL_13;
        }
        return result;
      }
LABEL_13:
      p_fieldSize = v14;
    }
    p_fieldSize += 30;
    ++i;
    v14 = p_fieldSize;
    if ( i >= iNumFields )
      return false;
  }
  v7 = *((_DWORD *)p_fieldSize + 4);
  if ( v7 == 0 )
  {
LABEL_8:
    p_fieldSize = v14;
    goto LABEL_9;
  }
  while ( !ParseKeyvalue(
             pObject: &pObject[v6],
             pFields: *(typedescription_t **)v7,
             iNumFields: *(_DWORD *)(v7 + 4),
             szKeyName,
             szValue) )
  {
    v7 = *(_DWORD *)(v7 + 12);
    if ( v7 == 0 )
      goto LABEL_8;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x101F9310
// Name: bool ExtractKeyvalue(void __near *,struct typedescription_t __near *,int,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ExtractKeyvalue(
        const char *pObject,
        typedescription_t *pFields,
        int iNumFields,
        const char *szKeyName,
        char *szValue,
        int iMaxLen)
{
  unsigned __int16 *p_fieldSize; // esi
  int v7; // edi
  int v8; // esi
  bool result; // al
  int v10; // eax
  int i; // [esp+24h] [ebp-8h]
  unsigned __int16 *v12; // [esp+28h] [ebp-4h]

  i = 0;
  if ( iNumFields <= 0 )
    return false;
  p_fieldSize = &pFields->fieldSize;
  v12 = &pFields->fieldSize;
  while ( 1 )
  {
    v7 = *((_DWORD *)p_fieldSize - 1);
    if ( *((_DWORD *)p_fieldSize - 3) == 10 && *p_fieldSize == 1 )
      break;
LABEL_9:
    if ( (p_fieldSize[1] & 4) != 0 && _V_stricmp(s1: *((const char **)p_fieldSize + 1), s2: szKeyName) == 0 )
    {
      switch ( *((_DWORD *)p_fieldSize - 3) )
      {
        case 1:
        case 0x10:
          V_snprintf(pDest: szValue, maxLen: iMaxLen, pFormat: "%f", *(float *)&pObject[v7]);
          return true;
        case 2:
        case 0x12:
        case 0x13:
          V_strncpy(pDest: szValue, pSrc: &pObject[v7], maxLen: iMaxLen);
          return true;
        case 3:
        case 0xF:
          V_snprintf(
            pDest: szValue,
            maxLen: iMaxLen,
            pFormat: "%f %f %f",
            *(float *)&pObject[v7],
            *(float *)&pObject[v7 + 4],
            *(float *)&pObject[v7 + 8]);
          return true;
        case 5:
        case 0x11:
          v10 = *(_DWORD *)&pObject[v7];
          goto LABEL_19;
        case 6:
          v10 = pObject[v7] != 0;
          goto LABEL_19;
        case 7:
          v10 = *(__int16 *)&pObject[v7];
          goto LABEL_19;
        case 8:
          v10 = pObject[v7];
LABEL_19:
          V_snprintf(pDest: szValue, maxLen: iMaxLen, pFormat: "%d", v10);
          result = true;
          break;
        case 9:
          V_snprintf(
            pDest: szValue,
            maxLen: iMaxLen,
            pFormat: "%d %d %d %d",
            *(_DWORD *)&pObject[v7],
            *(_DWORD *)&pObject[v7 + 4],
            *(_DWORD *)&pObject[v7 + 8],
            *(_DWORD *)&pObject[v7 + 12]);
          result = true;
          break;
        case 0xB:
        case 0x16:
        case 0x17:
        case 0x18:
          return false;
        default:
          _Warning(a1: "Bad field in entity!!\n");
          goto LABEL_13;
      }
      return result;
    }
LABEL_13:
    p_fieldSize += 30;
    ++i;
    v12 = p_fieldSize;
    if ( i >= iNumFields )
      return false;
  }
  v8 = *((_DWORD *)p_fieldSize + 4);
  if ( v8 == 0 )
  {
LABEL_8:
    p_fieldSize = v12;
    goto LABEL_9;
  }
  while ( !ExtractKeyvalue(
             pObject: (void *)&pObject[v7],
             pFields: *(typedescription_t **)v8,
             iNumFields: *(_DWORD *)(v8 + 4),
             szKeyName,
             szValue,
             iMaxLen) )
  {
    v8 = *(_DWORD *)(v8 + 12);
    if ( v8 == 0 )
      goto LABEL_8;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x101F9520
// Name: private: int CRestore::ReadSimple<short>(short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CRestore::ReadSimple<short>(CRestore *this, __int16 *pValue, int nElems, int nBytesAvailable)
{
  unsigned int v5; // ebx
  CSaveRestoreSegment *m_pData; // ecx
  CSaveRestoreSegment *v7; // eax
  int v8; // esi
  int size; // ecx
  int v10; // edx

  v5 = 2 * nElems;
  if ( nBytesAvailable != 0 && 2 * nElems >= nBytesAvailable )
    v5 = nBytesAvailable;
  m_pData = this->m_pData;
  if ( m_pData != nullptr
    && m_pData->bufferSize != m_pData->size
    && CSaveRestoreSegment::Read(this: m_pData, pOutput: (unsigned __int8 *)pValue, nBytes: v5) == 0 )
  {
    _Warning(a1: "Restore underflow!\n");
  }
  if ( (int)v5 >= nBytesAvailable )
    return v5 >> 1;
  v7 = this->m_pData;
  v8 = nBytesAvailable - v5;
  if ( v7 == nullptr || v7->bufferSize == v7->size )
    return v5 >> 1;
  size = v7->size;
  v10 = v7->bufferSize - size;
  if ( v10 == 0 )
  {
LABEL_14:
    _Warning(a1: "Restore underflow!\n");
    return v5 >> 1;
  }
  if ( v8 > v10 )
  {
    v7->size = v7->bufferSize;
    goto LABEL_14;
  }
  v7->pCurrentData += v8;
  v7->size = v8 + size;
  return v5 >> 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F95C0
// Name: private: int CRestore::ReadSimple<int>(int __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CRestore::ReadSimple<int>(CRestore *this, float *pValue, int nElems, int nBytesAvailable)
{
  unsigned int v5; // ebx
  CSaveRestoreSegment *m_pData; // ecx
  CSaveRestoreSegment *v7; // eax
  int v8; // esi
  int size; // ecx
  int v10; // edx

  v5 = 4 * nElems;
  if ( nBytesAvailable != 0 && 4 * nElems >= nBytesAvailable )
    v5 = nBytesAvailable;
  m_pData = this->m_pData;
  if ( m_pData != nullptr
    && m_pData->bufferSize != m_pData->size
    && CSaveRestoreSegment::Read(this: m_pData, pOutput: (unsigned __int8 *)pValue, nBytes: v5) == 0 )
  {
    _Warning(a1: "Restore underflow!\n");
  }
  if ( (int)v5 >= nBytesAvailable )
    return v5 >> 2;
  v7 = this->m_pData;
  v8 = nBytesAvailable - v5;
  if ( v7 == nullptr || v7->bufferSize == v7->size )
    return v5 >> 2;
  size = v7->size;
  v10 = v7->bufferSize - size;
  if ( v10 == 0 )
  {
LABEL_14:
    _Warning(a1: "Restore underflow!\n");
    return v5 >> 2;
  }
  if ( v8 > v10 )
  {
    v7->size = v7->bufferSize;
    goto LABEL_14;
  }
  v7->pCurrentData += v8;
  v7->size = v8 + size;
  return v5 >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x101F9660
// Name: private: int CRestore::ReadSimple<bool>(bool __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadSimple<bool>(CRestore *this, char *pValue, int nElems, int nBytesAvailable)
{
  int v4; // edi
  CSaveRestoreSegment *m_pData; // ecx
  CSaveRestoreSegment *v7; // eax
  int v8; // esi
  int size; // ecx
  int v10; // edx

  v4 = nElems;
  if ( nBytesAvailable != 0 && nElems >= nBytesAvailable )
    v4 = nBytesAvailable;
  m_pData = this->m_pData;
  if ( m_pData != nullptr
    && m_pData->bufferSize != m_pData->size
    && CSaveRestoreSegment::Read(this: m_pData, pOutput: (unsigned __int8 *)pValue, nBytes: v4) == 0 )
  {
    _Warning(a1: "Restore underflow!\n");
  }
  if ( v4 >= nBytesAvailable )
    return v4;
  v7 = this->m_pData;
  v8 = nBytesAvailable - v4;
  if ( v7 == nullptr || v7->bufferSize == v7->size )
    return v4;
  size = v7->size;
  v10 = v7->bufferSize - size;
  if ( v10 == 0 )
  {
LABEL_14:
    _Warning(a1: "Restore underflow!\n");
    return v4;
  }
  if ( v8 > v10 )
  {
    v7->size = v7->bufferSize;
    goto LABEL_14;
  }
  v7->pCurrentData += v8;
  v7->size = v8 + size;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101F9700
// Name: private: int CRestore::ReadSimple<class Vector>(class Vector __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CRestore::ReadSimple<Vector>(CRestore *this, Vector *pValue, int nElems, int nBytesAvailable)
{
  unsigned int v5; // ebx
  CSaveRestoreSegment *m_pData; // ecx
  CSaveRestoreSegment *v7; // eax
  int v8; // esi
  int size; // ecx
  int v10; // edx

  v5 = 12 * nElems;
  if ( nBytesAvailable != 0 && 12 * nElems >= nBytesAvailable )
    v5 = nBytesAvailable;
  m_pData = this->m_pData;
  if ( m_pData != nullptr
    && m_pData->bufferSize != m_pData->size
    && CSaveRestoreSegment::Read(this: m_pData, pOutput: (unsigned __int8 *)pValue, nBytes: v5) == 0 )
  {
    _Warning(a1: "Restore underflow!\n");
  }
  if ( (int)v5 >= nBytesAvailable )
    return v5 / 0xC;
  v7 = this->m_pData;
  v8 = nBytesAvailable - v5;
  if ( v7 == nullptr || v7->bufferSize == v7->size )
    return v5 / 0xC;
  size = v7->size;
  v10 = v7->bufferSize - size;
  if ( v10 == 0 )
  {
LABEL_14:
    _Warning(a1: "Restore underflow!\n");
    return v5 / 0xC;
  }
  if ( v8 > v10 )
  {
    v7->size = v7->bufferSize;
    goto LABEL_14;
  }
  v7->pCurrentData += v8;
  v7->size = v8 + size;
  return v5 / 0xC;
}

//------------------------------------------------------------------------------
// Address: 0x101F97B0
// Name: private: int CRestore::ReadSimple<class Quaternion>(class Quaternion __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CRestore::ReadSimple<Quaternion>(
        CRestore *this,
        Quaternion *pValue,
        int nElems,
        int nBytesAvailable)
{
  unsigned int v5; // ebx
  CSaveRestoreSegment *m_pData; // ecx
  CSaveRestoreSegment *v7; // eax
  int v8; // esi
  int size; // ecx
  int v10; // edx

  v5 = 16 * nElems;
  if ( nBytesAvailable != 0 && 16 * nElems >= nBytesAvailable )
    v5 = nBytesAvailable;
  m_pData = this->m_pData;
  if ( m_pData != nullptr
    && m_pData->bufferSize != m_pData->size
    && CSaveRestoreSegment::Read(this: m_pData, pOutput: (unsigned __int8 *)pValue, nBytes: v5) == 0 )
  {
    _Warning(a1: "Restore underflow!\n");
  }
  if ( (int)v5 >= nBytesAvailable )
    return v5 >> 4;
  v7 = this->m_pData;
  v8 = nBytesAvailable - v5;
  if ( v7 == nullptr || v7->bufferSize == v7->size )
    return v5 >> 4;
  size = v7->size;
  v10 = v7->bufferSize - size;
  if ( v10 == 0 )
  {
LABEL_14:
    _Warning(a1: "Restore underflow!\n");
    return v5 >> 4;
  }
  if ( v8 > v10 )
  {
    v7->size = v7->bufferSize;
    goto LABEL_14;
  }
  v7->pCurrentData += v8;
  v7->size = v8 + size;
  return v5 >> 4;
}

//------------------------------------------------------------------------------
// Address: 0x101F9850
// Name: private: int CRestore::ReadSimple<class VMatrix>(class VMatrix __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CRestore::ReadSimple<VMatrix>(CRestore *this, VMatrix *pValue, int nElems, int nBytesAvailable)
{
  unsigned int v5; // ebx
  CSaveRestoreSegment *m_pData; // ecx
  CSaveRestoreSegment *v7; // eax
  int v8; // esi
  int size; // ecx
  int v10; // edx

  v5 = nElems << 6;
  if ( nBytesAvailable != 0 && nElems << 6 >= nBytesAvailable )
    v5 = nBytesAvailable;
  m_pData = this->m_pData;
  if ( m_pData != nullptr
    && m_pData->bufferSize != m_pData->size
    && CSaveRestoreSegment::Read(this: m_pData, pOutput: (unsigned __int8 *)pValue, nBytes: v5) == 0 )
  {
    _Warning(a1: "Restore underflow!\n");
  }
  if ( (int)v5 >= nBytesAvailable )
    return v5 >> 6;
  v7 = this->m_pData;
  v8 = nBytesAvailable - v5;
  if ( v7 == nullptr || v7->bufferSize == v7->size )
    return v5 >> 6;
  size = v7->size;
  v10 = v7->bufferSize - size;
  if ( v10 == 0 )
  {
LABEL_14:
    _Warning(a1: "Restore underflow!\n");
    return v5 >> 6;
  }
  if ( v8 > v10 )
  {
    v7->size = v7->bufferSize;
    goto LABEL_14;
  }
  v7->pCurrentData += v8;
  v7->size = v8 + size;
  return v5 >> 6;
}

//------------------------------------------------------------------------------
// Address: 0x101F98F0
// Name: private: int CRestore::ReadSimple<struct interval_t>(struct interval_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CRestore::ReadSimple<interval_t>(
        CRestore *this,
        interval_t *pValue,
        int nElems,
        int nBytesAvailable)
{
  unsigned int v5; // ebx
  CSaveRestoreSegment *m_pData; // ecx
  CSaveRestoreSegment *v7; // eax
  int v8; // esi
  int size; // ecx
  int v10; // edx

  v5 = 8 * nElems;
  if ( nBytesAvailable != 0 && 8 * nElems >= nBytesAvailable )
    v5 = nBytesAvailable;
  m_pData = this->m_pData;
  if ( m_pData != nullptr
    && m_pData->bufferSize != m_pData->size
    && CSaveRestoreSegment::Read(this: m_pData, pOutput: (unsigned __int8 *)pValue, nBytes: v5) == 0 )
  {
    _Warning(a1: "Restore underflow!\n");
  }
  if ( (int)v5 >= nBytesAvailable )
    return v5 >> 3;
  v7 = this->m_pData;
  v8 = nBytesAvailable - v5;
  if ( v7 == nullptr || v7->bufferSize == v7->size )
    return v5 >> 3;
  size = v7->size;
  v10 = v7->bufferSize - size;
  if ( v10 == 0 )
  {
LABEL_14:
    _Warning(a1: "Restore underflow!\n");
    return v5 >> 3;
  }
  if ( v8 > v10 )
  {
    v7->size = v7->bufferSize;
    goto LABEL_14;
  }
  v7->pCurrentData += v8;
  v7->size = v8 + size;
  return v5 >> 3;
}

//------------------------------------------------------------------------------
// Address: 0x101F99A0
// Name: public: void CGameSaveRestoreInfo::InitEntityTable(struct entitytable_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameSaveRestoreInfo::InitEntityTable(CGameSaveRestoreInfo *this, entitytable_t *pNewTable, int size)
{
  int v3; // esi
  int v4; // edi
  entitytable_t *v5; // eax

  this->pTable = pNewTable;
  v3 = 0;
  this->tableCount = size;
  if ( size > 0 )
  {
    v4 = 0;
    do
    {
      v5 = &this->pTable[v4];
      v5->id = -1;
      v5->edictindex = -1;
      v5->saveentityindex = -1;
      v5->restoreentityindex = -1;
      v5->location = 0;
      v5->size = 0;
      v5->flags = 0;
      v5->classname.pszValue = nullptr;
      v5->globalname.pszValue = nullptr;
      v5->landmarkModelSpace.x = 0.0;
      v5->landmarkModelSpace.y = 0.0;
      v5->landmarkModelSpace.z = 0.0;
      v5->modelname.pszValue = nullptr;
      ++v3;
      v5->hEnt.m_Index = -1;
      ++v4;
    }
    while ( v3 < this->tableCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F9A20
// Name: public: unsigned short CSaveRestoreSegment::FindCreateSymbol(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestoreSegment::FindCreateSymbol(CSaveRestoreSegment *this, const char *pszToken)
{
  const char *v2; // ebx
  char v3; // dl
  unsigned int v4; // eax
  const char *j; // esi
  int tokenCount; // esi
  int v7; // eax
  char **pTokens; // ecx
  int v9; // edi
  int result; // eax
  int v11; // [esp+Ch] [ebp-Ch]
  char **v12; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v2 = pszToken;
  v3 = *pszToken;
  v4 = 0;
  for ( j = pszToken; *j != 0; v3 = *j )
  {
    ++j;
    v4 = v3 ^ __ROR4__(v4, 4);
  }
  tokenCount = this->tokenCount;
  i = 0;
  v7 = (unsigned __int16)(v4 % tokenCount);
  if ( tokenCount <= 0 )
  {
LABEL_11:
    _Warning(a1: "CSaveRestoreBuffer::TokenHash() is COMPLETELY FULL!");
    return 0;
  }
  else
  {
    pTokens = this->pTokens;
    v12 = pTokens;
    v11 = v7;
    v9 = v7 - tokenCount;
    while ( 1 )
    {
      result = i + v7;
      if ( result >= tokenCount )
        result = v9;
      if ( pTokens[result] == nullptr )
        break;
      if ( strcmp(v2, pTokens[result]) == 0 )
      {
        v2 = pszToken;
        pTokens = v12;
        break;
      }
      ++v9;
      if ( ++i >= tokenCount )
        goto LABEL_11;
      v2 = pszToken;
      v7 = v11;
      pTokens = v12;
    }
    pTokens[result] = (char *)v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F9AF0
// Name: void UTIL_FunctionFromName(struct datamap_t __near *,char const __near *,void (CBaseEntity::*__near *)(struct inputdata_t __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_FunctionFromName(
        datamap_t *pMap,
        const char *pName,
        void (__thiscall **ppFunction)(CBaseEntity *this, inputdata_t *))
{
  const char *v3; // eax
  datamap_t *v4; // esi
  int v5; // edi
  int v6; // ebx

  v3 = pName;
  if ( pName != nullptr && *pName != 0 )
  {
    v4 = pMap;
    if ( pMap != nullptr )
    {
      while ( 1 )
      {
        v5 = 0;
        if ( v4->dataNumFields > 0 )
          break;
LABEL_10:
        v4 = v4->baseMap;
        if ( v4 == nullptr )
        {
          v3 = pName;
          goto LABEL_12;
        }
      }
      v6 = 0;
      while ( (v4->dataDesc[v6].flags & 0x20) == 0
           || pName != v4->dataDesc[v6].fieldName && _V_stricmp(s1: pName, s2: v4->dataDesc[v6].fieldName) != 0 )
      {
        ++v5;
        ++v6;
        if ( v5 >= v4->dataNumFields )
          goto LABEL_10;
      }
      *ppFunction = v4->dataDesc[v5].inputFunc;
    }
    else
    {
LABEL_12:
      _Msg(a1: "Failed to find function %s\n", v3);
      *ppFunction = nullptr;
    }
  }
  else
  {
    *ppFunction = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F9BA0
// Name: public: virtual void CSave::WriteShort(short const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSave::WriteShort(CSave *this@<ecx>, const char *a2@<edi>, char *value, int count)
{
  CSave::BufferData(this, a2, pdata: value, size: 2 * count);
}

//------------------------------------------------------------------------------
// Address: 0x101F9BC0
// Name: public: virtual void CSave::WriteInt(int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSave::WriteInt(CSave *this@<ecx>, const char *a2@<edi>, float *value, int count)
{
  CSave::BufferData(this, a2, pdata: (char *)value, size: 4 * count);
}

//------------------------------------------------------------------------------
// Address: 0x101F9BE0
// Name: public: virtual void CSave::WriteData(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSave::WriteData(CSave *this@<ecx>, const char *a2@<edi>, char *pdata, int size)
{
  CSave::BufferData(this, a2, pdata, size);
}

//------------------------------------------------------------------------------
// Address: 0x101F9BF0
// Name: public: virtual void CSave::WriteString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteString(CSave *this, char *pstring)
{
  CSave::BufferData(this, a2: pstring + 1, pdata: pstring, size: strlen(pstring) + 1);
}

//------------------------------------------------------------------------------
// Address: 0x101F9C20
// Name: public: virtual void CSave::WriteString(struct string_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteString(CSave *this, const string_t *stringId, int count)
{
  int i; // esi
  char *pszValue; // edx

  for ( i = 0; i < count; ++i )
  {
    pszValue = (char *)stringId[i].pszValue;
    if ( pszValue == nullptr )
      pszValue = (char *)locale;
    CSave::BufferData(this, a2: pszValue + 1, pdata: pszValue, size: strlen(pszValue) + 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F9C70
// Name: public: virtual void CSave::WriteVector(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSave::WriteVector(CSave *this@<ecx>, const char *a2@<edi>, const Vector *value)
{
  CSave::BufferData(this, a2, pdata: (char *)value, size: 12);
}

//------------------------------------------------------------------------------
// Address: 0x101F9C90
// Name: public: virtual void CSave::WriteVector(class Vector const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSave::WriteVector(CSave *this@<ecx>, const char *a2@<edi>, const Vector *value, int count)
{
  CSave::BufferData(this, a2, pdata: (char *)value, size: 12 * count);
}

//------------------------------------------------------------------------------
// Address: 0x101F9CB0
// Name: public: virtual void CSave::WriteQuaternion(class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSave::WriteQuaternion(CSave *this@<ecx>, const char *a2@<edi>, const Quaternion *value)
{
  CSave::BufferData(this, a2, pdata: (char *)value, size: 16);
}

//------------------------------------------------------------------------------
// Address: 0x101F9CD0
// Name: public: virtual void CSave::WriteQuaternion(class Quaternion const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSave::WriteQuaternion(CSave *this@<ecx>, const char *a2@<edi>, const Quaternion *value, int count)
{
  CSave::BufferData(this, a2, pdata: (char *)value, size: 16 * count);
}

//------------------------------------------------------------------------------
// Address: 0x101F9CF0
// Name: public: void CSave::WriteVMatrixWorldspace(class VMatrix const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteVMatrixWorldspace(CSave *this, const VMatrix *value, int count)
{
  int v3; // ebx
  CGameSaveRestoreInfo *m_pGameInfo; // eax
  Vector *p_vecLandmarkOffset; // eax
  __int64 v8; // xmm0_8
  float z; // eax
  VMatrix tmp; // [esp+8h] [ebp-58h] BYREF
  __int64 v11; // [esp+48h] [ebp-18h]
  float v12; // [esp+50h] [ebp-10h]
  float v13; // [esp+54h] [ebp-Ch]
  float v14; // [esp+58h] [ebp-8h]
  float v15; // [esp+5Ch] [ebp-4h]

  v3 = count;
  if ( count > 0 )
  {
    do
    {
      m_pGameInfo = this->m_pGameInfo;
      if ( m_pGameInfo->levelInfo.fUseLandmark != 0 )
        p_vecLandmarkOffset = &m_pGameInfo->levelInfo.vecLandmarkOffset;
      else
        p_vecLandmarkOffset = &vec3_origin;
      v8 = *(_QWORD *)&p_vecLandmarkOffset->x;
      z = p_vecLandmarkOffset->z;
      v11 = v8;
      v13 = -*(float *)&v8;
      LODWORD(v14) = HIDWORD(v8) ^ 0x80000000;
      v12 = z;
      v15 = -z;
      VMatrix::operator=(this: &tmp, mOther: value);
      tmp.m[0][3] = tmp.m[0][3] + v13;
      tmp.m[1][3] = tmp.m[1][3] + v14;
      tmp.m[2][3] = tmp.m[2][3] + v15;
      CSave::BufferData(this, a2: (const char *)this, pdata: (char *)&tmp, size: 64);
      ++value;
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F9DC0
// Name: public: void CSave::WriteMatrix3x4Worldspace(struct matrix3x4_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteMatrix3x4Worldspace(CSave *this, const matrix3x4_t *value, const char *count)
{
  CGameSaveRestoreInfo *m_pGameInfo; // eax
  bool v4; // zf
  Vector *p_vecLandmarkOffset; // eax
  __int64 v6; // xmm0_8
  float z; // eax
  const char *v8; // edi
  const matrix3x4_t *v9; // esi
  matrix3x4_t tmp; // [esp+0h] [ebp-4Ch] BYREF
  Vector offset; // [esp+30h] [ebp-1Ch]
  Vector out; // [esp+3Ch] [ebp-10h] BYREF
  CSave *v13; // [esp+48h] [ebp-4h]

  m_pGameInfo = this->m_pGameInfo;
  v4 = m_pGameInfo->levelInfo.fUseLandmark == 0;
  v13 = this;
  if ( v4 )
    p_vecLandmarkOffset = &vec3_origin;
  else
    p_vecLandmarkOffset = &m_pGameInfo->levelInfo.vecLandmarkOffset;
  v6 = *(_QWORD *)&p_vecLandmarkOffset->x;
  z = p_vecLandmarkOffset->z;
  *(_QWORD *)&out.x = v6;
  *(_QWORD *)&offset.x = v6 ^ 0x8000000080000000uLL;
  v8 = count;
  out.z = z;
  offset.z = -z;
  if ( (int)count > 0 )
  {
    v9 = value;
    do
    {
      MatrixCopy(in: v9, out: &tmp);
      MatrixGetColumn(in: v9, column: 3, &out);
      out.x = out.x + offset.x;
      out.y = out.y + offset.y;
      out.z = out.z + offset.z;
      MatrixSetColumn(in: &out, column: 3, out: &tmp);
      CSave::BufferData(this: v13, a2: v8, pdata: (char *)value, size: 48);
      ++v9;
      --v8;
    }
    while ( v8 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F9EA0
// Name: public: virtual void CSave::WriteTime(char const __near *,float const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteTime(CSave *this, const char *pname, const float *data, float count)
{
  int v4; // ebx
  const char *v6; // edi
  CSaveRestoreSegment *m_pData; // ecx
  int v8; // edi
  float v9; // xmm0_4
  char pdata[4]; // [esp+Ch] [ebp-4h] BYREF

  v4 = LODWORD(count);
  v6 = (const char *)(4 * LODWORD(count));
  m_pData = this->m_pData;
  *(_DWORD *)pdata = (unsigned __int16)(4 * LOWORD(count));
  pname = (const char *)(unsigned __int16)CSaveRestoreSegment::FindCreateSymbol(this: m_pData, pszToken: pname);
  if ( (unsigned int)v6 >= 0x8000 )
    _Warning(a1: "CSave::WriteHeader() size parameter exceeds 'short'!\n");
  CSave::BufferData(this, a2: v6, pdata, size: 2);
  CSave::BufferData(this, a2: v6, pdata: (char *)&pname, size: 2);
  v8 = 0;
  if ( v4 > 0 )
  {
    while ( 1 )
    {
      v9 = data[v8];
      if ( v9 == 0.0 )
        break;
      if ( v9 == -3.402823466385289e38 || v9 == 3.4028235e38 )
        goto LABEL_10;
      count = v9 - this->m_pGameInfo->levelInfo.time;
      if ( COERCE_FLOAT(LODWORD(count) & _mask__AbsFloat_) < 0.001 )
      {
        v9 = 0.001;
        goto LABEL_10;
      }
LABEL_11:
      this->WriteData_2(this, a2: (const char *)&count, a3: 4);
      if ( ++v8 >= v4 )
        return;
    }
    v9 = -1.7014117e38;
LABEL_10:
    count = v9;
    goto LABEL_11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F9FB0
// Name: public: virtual void CSave::WriteTick(char const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteTick(CSave *this, const char *pname, const int *data, int count)
{
  int v4; // ebx
  const char *v6; // edi
  CSaveRestoreSegment *m_pData; // ecx

  v4 = count;
  v6 = (const char *)(4 * count);
  m_pData = this->m_pData;
  count = (unsigned __int16)(4 * count);
  pname = (const char *)(unsigned __int16)CSaveRestoreSegment::FindCreateSymbol(this: m_pData, pszToken: pname);
  if ( (unsigned int)v6 >= 0x8000 )
    _Warning(a1: "CSave::WriteHeader() size parameter exceeds 'short'!\n");
  CSave::BufferData(this, a2: v6, pdata: (char *)&count, size: 2);
  CSave::BufferData(this, a2: v6, pdata: (char *)&pname, size: 2);
  this->WriteTick(this, a2: data, a3: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101FA030
// Name: public: virtual void CSave::WritePositionVector(char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WritePositionVector(CSave *this, const char *pname, const Vector *value)
{
  float z; // eax
  float v4; // xmm1_4
  CGameSaveRestoreInfo *m_pGameInfo; // eax
  Vector *p_vecLandmarkOffset; // eax
  float v7; // xmm2_4
  float v8; // [esp+8h] [ebp-10h]
  Vector tmp; // [esp+Ch] [ebp-Ch] BYREF

  z = value->z;
  *(_QWORD *)&tmp.x = *(_QWORD *)&value->x;
  tmp.z = z;
  v4 = z;
  if ( vec3_invalid.x != tmp.x || vec3_invalid.y != tmp.y || vec3_invalid.z != z )
  {
    m_pGameInfo = this->m_pGameInfo;
    if ( m_pGameInfo->levelInfo.fUseLandmark != 0 )
      p_vecLandmarkOffset = &m_pGameInfo->levelInfo.vecLandmarkOffset;
    else
      p_vecLandmarkOffset = &vec3_origin;
    v7 = tmp.y - p_vecLandmarkOffset->y;
    v8 = p_vecLandmarkOffset->z;
    tmp.x = tmp.x - p_vecLandmarkOffset->x;
    tmp.y = v7;
    tmp.z = v4 - v8;
  }
  this->WriteVector_2(this, a2: pname, a3: &tmp);
}

//------------------------------------------------------------------------------
// Address: 0x101FA0F0
// Name: public: virtual void CSave::WritePositionVector(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WritePositionVector(CSave *this, const Vector *value)
{
  float z; // eax
  float v3; // xmm1_4
  CGameSaveRestoreInfo *m_pGameInfo; // eax
  Vector *p_vecLandmarkOffset; // eax
  float v6; // xmm2_4
  float v7; // [esp+8h] [ebp-10h]
  Vector tmp; // [esp+Ch] [ebp-Ch] BYREF

  z = value->z;
  *(_QWORD *)&tmp.x = *(_QWORD *)&value->x;
  tmp.z = z;
  v3 = z;
  if ( vec3_invalid.x != tmp.x || vec3_invalid.y != tmp.y || vec3_invalid.z != z )
  {
    m_pGameInfo = this->m_pGameInfo;
    if ( m_pGameInfo->levelInfo.fUseLandmark != 0 )
      p_vecLandmarkOffset = &m_pGameInfo->levelInfo.vecLandmarkOffset;
    else
      p_vecLandmarkOffset = &vec3_origin;
    v6 = tmp.y - p_vecLandmarkOffset->y;
    v7 = p_vecLandmarkOffset->z;
    tmp.x = tmp.x - p_vecLandmarkOffset->x;
    tmp.y = v6;
    tmp.z = v3 - v7;
  }
  this->WriteVector_4(this, a2: &tmp);
}

//------------------------------------------------------------------------------
// Address: 0x101FA1A0
// Name: public: virtual void CSave::WritePositionVector(char const __near *,class Vector const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WritePositionVector(CSave *this, const char *pname, const Vector *value, int count)
{
  int v4; // ebx
  unsigned int v6; // edi
  CSaveRestoreSegment *m_pData; // ecx

  v4 = count;
  v6 = 12 * count;
  m_pData = this->m_pData;
  count = (unsigned __int16)(12 * count);
  pname = (const char *)(unsigned __int16)CSaveRestoreSegment::FindCreateSymbol(this: m_pData, pszToken: pname);
  if ( v6 >= 0x8000 )
    _Warning(a1: "CSave::WriteHeader() size parameter exceeds 'short'!\n");
  CSave::BufferData(this, a2: (const char *)v6, pdata: (char *)&count, size: 2);
  CSave::BufferData(this, a2: (const char *)v6, pdata: (char *)&pname, size: 2);
  this->WritePositionVector(this, a2: value, a3: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101FA220
// Name: public: virtual void CSave::WritePositionVector(class Vector const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WritePositionVector(CSave *this, const Vector *value, int count)
{
  int i; // ebx
  float z; // eax
  float v7; // xmm1_4
  CGameSaveRestoreInfo *m_pGameInfo; // eax
  Vector *p_vecLandmarkOffset; // eax
  float v10; // xmm2_4
  float v11; // [esp+Ch] [ebp-10h]
  Vector tmp; // [esp+10h] [ebp-Ch] BYREF

  if ( count > 0 )
  {
    for ( i = count; i != 0; --i )
    {
      z = value->z;
      *(_QWORD *)&tmp.x = *(_QWORD *)&value->x;
      tmp.z = z;
      v7 = z;
      if ( vec3_invalid.x != tmp.x || vec3_invalid.y != tmp.y || vec3_invalid.z != z )
      {
        m_pGameInfo = this->m_pGameInfo;
        if ( m_pGameInfo->levelInfo.fUseLandmark != 0 )
          p_vecLandmarkOffset = &m_pGameInfo->levelInfo.vecLandmarkOffset;
        else
          p_vecLandmarkOffset = &vec3_origin;
        v10 = tmp.y - p_vecLandmarkOffset->y;
        v11 = p_vecLandmarkOffset->z;
        tmp.x = tmp.x - p_vecLandmarkOffset->x;
        tmp.y = v10;
        tmp.z = v7 - v11;
      }
      this->WriteData_2(this, a2: (const char *)&tmp, a3: 12);
      ++value;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FA300
// Name: public: virtual void CRestore::ReadHeader(struct SaveRestoreRecordHeader_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRestore::ReadHeader(CRestore *this, SaveRestoreRecordHeader_t *pheader)
{
  CSaveRestoreSegment *m_pData; // eax
  int size; // ecx
  int v5; // edx

  if ( pheader != nullptr )
  {
    pheader->size = this->ReadShort_2(this);
    pheader->symbol = this->ReadShort_2(this);
    return;
  }
  m_pData = this->m_pData;
  if ( m_pData != nullptr && m_pData->bufferSize != m_pData->size )
  {
    size = m_pData->size;
    v5 = m_pData->bufferSize - size;
    if ( v5 != 0 )
    {
      if ( v5 >= 4 )
      {
        m_pData->pCurrentData += 4;
        m_pData->size = size + 4;
        return;
      }
      m_pData->size = m_pData->bufferSize;
    }
    _Warning(a1: "Restore underflow!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FA380
// Name: public: virtual short CRestore::ReadShort(void)
// Source: json
//------------------------------------------------------------------------------
__int16 __thiscall CRestore::ReadShort(CRestore *this)
{
  CSaveRestoreSegment *m_pData; // ecx
  int bufferSize; // eax
  int size; // esi
  __int16 result; // ax
  __int16 *pCurrentData; // edx

  m_pData = this->m_pData;
  if ( m_pData == nullptr || m_pData->bufferSize == m_pData->size )
    return 0;
  bufferSize = m_pData->bufferSize;
  size = m_pData->size;
  if ( bufferSize == size )
  {
LABEL_6:
    _Warning(a1: "Restore underflow!\n");
    return 0;
  }
  if ( bufferSize - size < 2 )
  {
    m_pData->size = bufferSize;
    goto LABEL_6;
  }
  pCurrentData = (__int16 *)m_pData->pCurrentData;
  result = *pCurrentData;
  m_pData->size = size + 2;
  m_pData->pCurrentData = (char *)(pCurrentData + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FA3F0
// Name: public: virtual int CRestore::ReadInt(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadInt(CRestore *this)
{
  CSaveRestoreSegment *m_pData; // ecx
  int bufferSize; // eax
  int size; // esi
  int result; // eax
  int *pCurrentData; // edx

  m_pData = this->m_pData;
  if ( m_pData == nullptr || m_pData->bufferSize == m_pData->size )
    return 0;
  bufferSize = m_pData->bufferSize;
  size = m_pData->size;
  if ( bufferSize == size )
  {
LABEL_6:
    _Warning(a1: "Restore underflow!\n");
    return 0;
  }
  if ( bufferSize - size < 4 )
  {
    m_pData->size = bufferSize;
    goto LABEL_6;
  }
  pCurrentData = (int *)m_pData->pCurrentData;
  result = *pCurrentData;
  m_pData->size = size + 4;
  m_pData->pCurrentData = (char *)(pCurrentData + 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FA450
// Name: public: virtual int CRestore::ReadShort(short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CRestore::ReadShort(CRestore *this, __int16 *pValue, int nElems, int nBytesAvailable)
{
  return CRestore::ReadSimple<short>(this, pValue, nElems, nBytesAvailable);
}

//------------------------------------------------------------------------------
// Address: 0x101FA460
// Name: public: virtual int CRestore::ReadInt(int __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CRestore::ReadInt(CRestore *this, float *pValue, int nElems, int nBytesAvailable)
{
  return CRestore::ReadSimple<int>(this, pValue, nElems, nBytesAvailable);
}

//------------------------------------------------------------------------------
// Address: 0x101FA470
// Name: public: virtual int CRestore::ReadData(char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadData(CRestore *this, char *pData, int size, int nBytesAvailable)
{
  return CRestore::ReadSimple<bool>(this, pValue: pData, nElems: size, nBytesAvailable);
}

//------------------------------------------------------------------------------
// Address: 0x101FA480
// Name: public: virtual int CRestore::ReadString(struct string_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadString(CRestore *this, string_t *pValue, int nElems, int nBytesAvailable)
{
  CSaveRestoreSegment *m_pData; // eax
  char *pCurrentData; // esi
  int v6; // edi
  string_t *v7; // ebx
  CSaveRestoreSegment *v8; // eax
  int size; // ecx
  int v10; // edx
  int v11; // ebx
  char *pLimit; // [esp+10h] [ebp-4h]

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
    pCurrentData = m_pData->pCurrentData;
  else
    pCurrentData = nullptr;
  v6 = 0;
  pLimit = &pCurrentData[nBytesAvailable];
  if ( nElems > 0 )
  {
    v7 = pValue;
    do
    {
      if ( pCurrentData >= pLimit )
        break;
      if ( *pCurrentData != 0 )
        v7[v6] = *(string_t *)AllocPooledString(pszValue: (const char *)&pValue).pszValue;
      else
        v7[v6].pszValue = nullptr;
      for ( ; *pCurrentData != 0; ++pCurrentData )
        ;
      ++v6;
      ++pCurrentData;
    }
    while ( v6 < nElems );
  }
  v8 = this->m_pData;
  if ( v8 == nullptr || v8->bufferSize == v8->size )
    return v6;
  size = v8->size;
  v10 = v8->bufferSize - size;
  if ( v10 == 0 )
  {
LABEL_18:
    _Warning(a1: "Restore underflow!\n");
    return v6;
  }
  v11 = nBytesAvailable;
  if ( nBytesAvailable > v10 )
  {
    v8->size = v8->bufferSize;
    goto LABEL_18;
  }
  v8->pCurrentData += nBytesAvailable;
  v8->size = v11 + size;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101FA550
// Name: public: virtual int CRestore::ReadVector(class Vector __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CRestore::ReadVector(CRestore *this, Vector *pValue, int nElems, int nBytesAvailable)
{
  return CRestore::ReadSimple<Vector>(this, pValue, nElems, nBytesAvailable);
}

//------------------------------------------------------------------------------
// Address: 0x101FA560
// Name: public: virtual int CRestore::ReadQuaternion(class Quaternion __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CRestore::ReadQuaternion(CRestore *this, Quaternion *pValue, int nElems, int nBytesAvailable)
{
  return CRestore::ReadSimple<Quaternion>(this, pValue, nElems, nBytesAvailable);
}

//------------------------------------------------------------------------------
// Address: 0x101FA570
// Name: public: virtual int CRestore::ReadVMatrix(class VMatrix __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CRestore::ReadVMatrix(CRestore *this, VMatrix *pValue, int nElems, int nBytesAvailable)
{
  return CRestore::ReadSimple<VMatrix>(this, pValue, nElems, nBytesAvailable);
}

//------------------------------------------------------------------------------
// Address: 0x101FA580
// Name: public: virtual int CRestore::ReadVMatrixWorldspace(class VMatrix __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadVMatrixWorldspace(CRestore *this, VMatrix *pValue, int nElems, int nBytesAvailable)
{
  CGameSaveRestoreInfo *m_pGameInfo; // eax
  bool v5; // zf
  Vector *p_vecLandmarkOffset; // eax
  __int64 v7; // xmm0_8
  int result; // eax
  float *v9; // esi
  int v10; // ebx
  CSaveRestoreSegment *m_pData; // edi
  int v12; // eax
  VMatrix tmp; // [esp+0h] [ebp-50h] BYREF
  Vector basePosition; // [esp+40h] [ebp-10h]
  CRestore *v15; // [esp+4Ch] [ebp-4h]

  m_pGameInfo = this->m_pGameInfo;
  v5 = m_pGameInfo->levelInfo.fUseLandmark == 0;
  v15 = this;
  if ( v5 )
    p_vecLandmarkOffset = &vec3_origin;
  else
    p_vecLandmarkOffset = &m_pGameInfo->levelInfo.vecLandmarkOffset;
  v7 = *(_QWORD *)&p_vecLandmarkOffset->x;
  basePosition.z = p_vecLandmarkOffset->z;
  result = nElems;
  *(_QWORD *)&basePosition.x = v7;
  if ( nElems > 0 )
  {
    v9 = &pValue->m[1][3];
    v10 = nElems;
    while ( 1 )
    {
      m_pData = this->m_pData;
      if ( m_pData != nullptr && m_pData->bufferSize != m_pData->size )
      {
        v12 = m_pData->bufferSize - m_pData->size;
        if ( v12 == 0 )
          goto LABEL_12;
        if ( v12 < 64 )
        {
          m_pData->size = m_pData->bufferSize;
LABEL_12:
          _Warning(a1: "Restore underflow!\n");
          goto LABEL_13;
        }
        tmp = *(VMatrix *)m_pData->pCurrentData;
        m_pData->pCurrentData += 64;
        m_pData->size += 64;
      }
LABEL_13:
      VMatrix::operator=(this: (VMatrix *)(v9 - 7), mOther: &tmp);
      *(v9 - 4) = basePosition.x + *(v9 - 4);
      *v9 = basePosition.y + *v9;
      v9[4] = v9[4] + basePosition.z;
      v9 += 16;
      if ( --v10 == 0 )
        return nElems;
      this = v15;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FA670
// Name: public: virtual int CRestore::ReadMatrix3x4Worldspace(struct matrix3x4_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadMatrix3x4Worldspace(CRestore *this, matrix3x4_t *pValue, int nElems, int nBytesAvailable)
{
  CGameSaveRestoreInfo *m_pGameInfo; // eax
  bool v5; // zf
  Vector *p_vecLandmarkOffset; // eax
  __int64 v7; // xmm0_8
  int result; // eax
  int v10; // ebx
  CSaveRestoreSegment *m_pData; // esi
  int v12; // eax
  matrix3x4_t tmp; // [esp+0h] [ebp-4Ch] BYREF
  Vector basePosition; // [esp+30h] [ebp-1Ch]
  Vector out; // [esp+3Ch] [ebp-10h] BYREF
  CRestore *v16; // [esp+48h] [ebp-4h]

  m_pGameInfo = this->m_pGameInfo;
  v5 = m_pGameInfo->levelInfo.fUseLandmark == 0;
  v16 = this;
  if ( v5 )
    p_vecLandmarkOffset = &vec3_origin;
  else
    p_vecLandmarkOffset = &m_pGameInfo->levelInfo.vecLandmarkOffset;
  v7 = *(_QWORD *)&p_vecLandmarkOffset->x;
  basePosition.z = p_vecLandmarkOffset->z;
  result = nElems;
  *(_QWORD *)&basePosition.x = v7;
  if ( nElems > 0 )
  {
    v10 = nElems;
    while ( 1 )
    {
      m_pData = this->m_pData;
      if ( m_pData != nullptr && m_pData->bufferSize != m_pData->size )
      {
        v12 = m_pData->bufferSize - m_pData->size;
        if ( v12 == 0 )
          goto LABEL_12;
        if ( v12 < 48 )
        {
          m_pData->size = m_pData->bufferSize;
LABEL_12:
          _Warning(a1: "Restore underflow!\n");
          goto LABEL_13;
        }
        tmp = *(matrix3x4_t *)m_pData->pCurrentData;
        m_pData->pCurrentData += 48;
        m_pData->size += 48;
      }
LABEL_13:
      MatrixCopy(in: &tmp, out: pValue);
      MatrixGetColumn(in: &tmp, column: 3, &out);
      out.x = basePosition.x + out.x;
      out.y = basePosition.y + out.y;
      out.z = basePosition.z + out.z;
      MatrixSetColumn(in: &out, column: 3, out: pValue++);
      if ( --v10 == 0 )
        return nElems;
      this = v16;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FA780
// Name: public: virtual int CRestore::ReadEntityPtr(class CBaseEntity __near * __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadEntityPtr(CRestore *this, CBaseEntity **ppEntity, int count, int nBytesAvailable)
{
  int v4; // edi
  int v6; // esi
  CBaseEntity **v7; // edi
  int v8; // eax
  CGameSaveRestoreInfo *m_pGameInfo; // ecx
  int v10; // esi
  int tableCount; // edx
  int v12; // eax
  entitytable_t *pTable; // ecx
  IHandleEntity *m_pEntity; // eax
  unsigned int m_Index; // eax
  _BYTE v17[4096]; // [esp+Ch] [ebp-1008h] BYREF
  int v18; // [esp+100Ch] [ebp-8h]
  int v19; // [esp+1010h] [ebp-4h]
  int v20; // [esp+1024h] [ebp+10h]

  v4 = count;
  v6 = this->ReadInt_2(this, a2: (int *)v17, a3: count, a4: nBytesAvailable);
  v19 = v6;
  if ( v6 > 0 )
  {
    v7 = ppEntity;
    v8 = v17 - (_BYTE *)ppEntity;
    v18 = v17 - (_BYTE *)ppEntity;
    v20 = v6;
    while ( 1 )
    {
      m_pGameInfo = this->m_pGameInfo;
      v10 = *(int *)((char *)v7 + v8);
      if ( m_pGameInfo == nullptr )
        goto LABEL_10;
      if ( v10 < 0 )
        goto LABEL_10;
      tableCount = m_pGameInfo->tableCount;
      v12 = 0;
      if ( tableCount <= 0 )
        goto LABEL_10;
      pTable = m_pGameInfo->pTable;
      while ( pTable->id != v10 )
      {
        ++v12;
        ++pTable;
        if ( v12 >= tableCount )
          goto LABEL_10;
      }
      m_Index = pTable->hEnt.m_Index;
      if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      else
LABEL_10:
        m_pEntity = nullptr;
      *v7++ = (CBaseEntity *)m_pEntity;
      if ( --v20 == 0 )
        break;
      v8 = v18;
    }
    v6 = v19;
    v4 = count;
  }
  if ( v6 < v4 )
    memset(dst: (int)&ppEntity[v6], value: nullptr, count: 4 * (v4 - v6));
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101FA860
// Name: public: virtual int CRestore::ReadEHandle(class CHandle<class CBaseEntity> __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadEHandle(CRestore *this, CHandle<CBaseEntity> *pEHandle, int count, int nBytesAvailable)
{
  int v4; // edi
  int v6; // esi
  CHandle<CBaseEntity> *v7; // edi
  int v8; // eax
  CGameSaveRestoreInfo *m_pGameInfo; // ecx
  int v10; // esi
  int tableCount; // edx
  int v12; // eax
  entitytable_t *pTable; // ecx
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  _BYTE v17[4096]; // [esp+Ch] [ebp-1008h] BYREF
  int v18; // [esp+100Ch] [ebp-8h]
  int v19; // [esp+1010h] [ebp-4h]
  int v20; // [esp+1024h] [ebp+10h]

  v4 = count;
  v6 = this->ReadInt_2(this, a2: (int *)v17, a3: count, a4: nBytesAvailable);
  v19 = v6;
  if ( v6 > 0 )
  {
    v7 = pEHandle;
    v8 = v17 - (_BYTE *)pEHandle;
    v18 = v17 - (_BYTE *)pEHandle;
    v20 = v6;
    while ( 1 )
    {
      m_pGameInfo = this->m_pGameInfo;
      v10 = *(unsigned int *)((char *)&v7->m_Index + v8);
      if ( m_pGameInfo == nullptr )
        goto LABEL_10;
      if ( v10 < 0 )
        goto LABEL_10;
      tableCount = m_pGameInfo->tableCount;
      v12 = 0;
      if ( tableCount <= 0 )
        goto LABEL_10;
      pTable = m_pGameInfo->pTable;
      while ( pTable->id != v10 )
      {
        ++v12;
        ++pTable;
        if ( v12 >= tableCount )
          goto LABEL_10;
      }
      m_Index = pTable->hEnt.m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( m_pEntity != nullptr )
        v7->m_Index = m_pEntity->GetRefEHandle(this: m_pEntity)->m_Index;
      else
LABEL_10:
        v7->m_Index = -1;
      ++v7;
      if ( --v20 == 0 )
        break;
      v8 = v18;
    }
    v4 = count;
    v6 = v19;
  }
  if ( v6 < v4 )
    memset(dst: (int)&pEHandle[v6], value: (unsigned __int8 *)0xFF, count: 4 * (v4 - v6));
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101FA960
// Name: private: void CRestore::ReadGameField(struct SaveRestoreRecordHeader_t const __near &,void __near *,struct datamap_t __near *,struct typedescription_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRestore::ReadGameField(
        CRestore *this,
        const SaveRestoreRecordHeader_t *header,
        CBaseEntity **pDest,
        datamap_t *pRootMap,
        typedescription_t *pField)
{
  bool (__cdecl *v5)(const char *); // edi
  int fieldSize; // ebx
  void *v8; // esp
  const char **v9; // edi
  int v10; // eax
  int v11; // ebx
  const char *v12; // eax
  int v13; // ebx
  void *v14; // esp
  const char **v15; // edi
  int v16; // eax
  int v17; // ebx
  const char *v18; // eax
  const char *v19; // eax
  const char *pszValue; // eax
  int i; // esi
  const char *v22; // eax
  _BYTE v23[12]; // [esp+0h] [ebp-110h] BYREF
  char buf[260]; // [esp+Ch] [ebp-104h] BYREF
  int nRead; // [esp+118h] [ebp+8h]
  int nReada; // [esp+118h] [ebp+8h]
  int nReadb; // [esp+118h] [ebp+8h]

  v5 = (bool (__cdecl *)(const char *))pField;
  switch ( pField->fieldType )
  {
    case FIELD_CLASSPTR:
      this->ReadEntityPtr(this, a2: pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_EHANDLE:
      this->ReadEHandle(this, a2: (CHandle<CBaseEntity> *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_EDICT:
      this->ReadEdictPtr(this, a2: (edict_t **)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_POSITION_VECTOR:
      this->ReadPositionVector(this, a2: (Vector *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_TIME:
      this->ReadTime(this, a2: (float *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_TICK:
      this->ReadTick(this, a2: (int *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_MODELNAME:
    case FIELD_SOUNDNAME:
      nReadb = this->ReadString(this, a2: (string_t *)pDest, a3: pField->fieldSize, a4: header->size);
      if ( this->m_precache )
      {
        if ( *(_DWORD *)v5 == 18 )
        {
          v19 = (const char *)*pDest;
          if ( *pDest == nullptr )
            v19 = locale;
          if ( V_stristr(pStr: v19, pSearch: ".bsp") != nullptr )
          {
            V_strncpy(pDest: buf, pSrc: "maps/", maxLen: 260);
            pszValue = gpGlobals->mapname.pszValue;
            if ( pszValue == nullptr )
              pszValue = locale;
            V_strncat(pDest: buf, pSrc: pszValue, destBufferSize: 0x104u, max_chars_to_copy: -1);
            V_strncat(pDest: buf, pSrc: ".bsp", destBufferSize: 0x104u, max_chars_to_copy: -1);
            *pDest = *(CBaseEntity **)AllocPooledString(pszValue: (const char *)&pField).pszValue;
          }
        }
        for ( i = 0; i < nReadb; ++i )
        {
          v22 = (const char *)pDest[i];
          if ( v22 != nullptr )
          {
            if ( *(_DWORD *)v5 == 18 )
            {
              CBaseEntity::PrecacheModel(a1: v5, name: v22, bPreload: true);
            }
            else if ( *(_DWORD *)v5 == 19 )
            {
              CBaseEntity::PrecacheScriptSound(soundname: (const char *)pDest[i]);
            }
          }
        }
      }
      break;
    case FIELD_FUNCTION:
      this->ReadFunction(
        this,
        a2: pRootMap,
        a3: (void (__thiscall **)(CBaseEntity *, inputdata_t *))pDest,
        a4: pField->fieldSize,
        a5: header->size);
      break;
    case FIELD_VMATRIX:
      this->ReadVMatrix(this, a2: (VMatrix *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_VMATRIX_WORLDSPACE:
      this->ReadVMatrixWorldspace(this, a2: (VMatrix *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_MATRIX3X4_WORLDSPACE:
      this->ReadMatrix3x4Worldspace(this, a2: (matrix3x4_t *)pDest, a3: pField->fieldSize, a4: header->size);
      break;
    case FIELD_INTERVAL:
      CRestore::ReadSimple<interval_t>(
        this,
        pValue: (interval_t *)pDest,
        nElems: pField->fieldSize,
        nBytesAvailable: header->size);
      break;
    case FIELD_MODELINDEX:
      fieldSize = pField->fieldSize;
      v8 = alloca((4 * fieldSize + 15) & 0xFFFF0);
      v9 = (const char **)v23;
      v10 = this->ReadString(this, a2: (string_t *)v23, a3: fieldSize, a4: header->size);
      if ( v10 > 0 )
      {
        v11 = (char *)pDest - v23;
        for ( nRead = v10; nRead != 0; --nRead )
        {
          if ( *v9 != nullptr )
          {
            *(const char **)((char *)v9 + v11) = (const char *)modelinfo->GetModelIndex(this: modelinfo, a2: *v9);
            if ( this->m_precache )
            {
              v12 = *v9;
              if ( *v9 == nullptr )
                v12 = locale;
              CBaseEntity::PrecacheModel(a1: (bool (__cdecl *)(const char *))v9, name: v12, bPreload: true);
            }
          }
          else
          {
            *(const char **)((char *)v9 + v11) = (const char *)-1;
          }
          ++v9;
        }
      }
      break;
    case FIELD_MATERIALINDEX:
      v13 = pField->fieldSize;
      v14 = alloca((4 * v13 + 15) & 0xFFFF0);
      v15 = (const char **)v23;
      v16 = this->ReadString(this, a2: (string_t *)v23, a3: v13, a4: header->size);
      if ( v16 > 0 )
      {
        v17 = (char *)pDest - v23;
        for ( nReada = v16; nReada != 0; --nReada )
        {
          if ( *v15 != nullptr )
          {
            *(const char **)((char *)v15 + v17) = (const char *)GetMaterialIndex(pMaterialName: *v15);
            if ( this->m_precache )
            {
              v18 = *v15;
              if ( *v15 == nullptr )
                v18 = locale;
              PrecacheMaterial(pMaterialName: v18);
            }
          }
          else
          {
            *(const char **)((char *)v15 + v17) = nullptr;
          }
          ++v15;
        }
      }
      break;
    default:
      _Warning(a1: "Bad field type\n");
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FADC0
// Name: public: virtual int CRestore::ReadFunction(struct datamap_t __near *,void (CBaseEntity::*__near *)(struct inputdata_t __near &),int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadFunction(
        CRestore *this,
        datamap_t *pMap,
        void (__thiscall **pValue)(CBaseEntity *this, inputdata_t *),
        int count,
        int nBytesAvailable)
{
  CSaveRestoreSegment *m_pData; // eax
  const char *pCurrentData; // ebx
  int size; // ecx
  int v8; // edx

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
    pCurrentData = m_pData->pCurrentData;
  else
    pCurrentData = nullptr;
  if ( m_pData != nullptr && m_pData->bufferSize != m_pData->size )
  {
    size = m_pData->size;
    v8 = m_pData->bufferSize - size;
    if ( v8 != 0 )
    {
      if ( nBytesAvailable <= v8 )
      {
        m_pData->pCurrentData += nBytesAvailable;
        m_pData->size = nBytesAvailable + size;
        goto LABEL_10;
      }
      m_pData->size = m_pData->bufferSize;
    }
    _Warning(a1: "Restore underflow!\n");
  }
LABEL_10:
  UTIL_FunctionFromName(pMap, pName: pCurrentData, ppFunction: pValue);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FAE30
// Name: public: virtual void CEntitySaveRestoreBlockHandler::ReadRestoreHeaders(class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntitySaveRestoreBlockHandler::ReadRestoreHeaders(
        CEntitySaveRestoreBlockHandler *this,
        IRestore *pRestore)
{
  CGameSaveRestoreInfo *v3; // edi
  entitytable_t *v4; // eax
  int v5; // ebx
  int nEntities; // [esp+Ch] [ebp-4h] BYREF
  IRestore *pRestorea; // [esp+18h] [ebp+8h]

  v3 = pRestore->GetGameSaveRestoreInfo(this: pRestore);
  pRestore->ReadInt_2(this: pRestore, a2: &nEntities, a3: 1, a4: 0);
  v4 = (entitytable_t *)engine->SaveAllocMemory(this: engine, a2: 56 * nEntities, a3: 1);
  if ( v4 != nullptr )
  {
    CGameSaveRestoreInfo::InitEntityTable(this: v3, pNewTable: v4, size: nEntities);
    v5 = 0;
    if ( v3->tableCount > 0 )
    {
      pRestorea = nullptr;
      do
      {
        pRestore->ReadFields(
          this: pRestore,
          a2: "ETABLE",
          a3: (char *)pRestorea + (unsigned int)v3->pTable,
          a4: nullptr,
          a5: entitytable_t::m_DataMap.dataDesc,
          a6: entitytable_t::m_DataMap.dataNumFields);
        pRestorea += 14;
        ++v5;
      }
      while ( v5 < v3->tableCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FAEE0
// Name: private: class CBaseEntity __near * CEntitySaveRestoreBlockHandler::FindGlobalEntity(struct string_t,struct string_t)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CEntitySaveRestoreBlockHandler::FindGlobalEntity(
        CEntitySaveRestoreBlockHandler *this,
        string_t classname,
        string_t globalname)
{
  CBaseEntity *result; // eax
  CBaseEntity *Ent; // esi
  const char *pszValue; // ecx
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // ecx
  const char *v9; // esi
  const char *v10; // eax

  result = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
  Ent = result;
  if ( result != nullptr )
  {
    while ( 1 )
    {
      pszValue = globalname.pszValue;
      if ( globalname.pszValue == nullptr )
        pszValue = locale;
      v6 = Ent->m_iGlobalname.pszValue;
      if ( v6 == nullptr )
        v6 = locale;
      if ( v6 == pszValue || _V_stricmp(s1: v6, s2: pszValue) == 0 )
        break;
      Ent = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: Ent);
      if ( Ent == nullptr )
        return Ent;
    }
    if ( Ent == nullptr )
      return Ent;
    v7 = classname.pszValue;
    if ( classname.pszValue == nullptr )
      v7 = locale;
    if ( Ent->m_iClassname.pszValue == v7 || CBaseEntity::ClassMatchesComplex(this: Ent, pszClassOrWildcard: v7) != 0 )
      return Ent;
    v8 = classname.pszValue;
    if ( classname.pszValue == nullptr )
      v8 = locale;
    v9 = Ent->m_iClassname.pszValue;
    if ( v9 == nullptr )
      v9 = locale;
    v10 = globalname.pszValue;
    if ( globalname.pszValue == nullptr )
      v10 = locale;
    _Warning(a1: "Global entity found %s, wrong class %s [expects class %s]\n", v10, v9, v8);
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FAFA0
// Name: void CreateEntitiesInTransitionList(class CSaveRestoreData __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateEntitiesInTransitionList(CSaveRestoreData *pSaveData, int levelMask)
{
  CSaveRestoreData *v2; // eax
  entitytable_t *v3; // edi
  int edictindex; // edx
  const char *pszValue; // esi
  int flags; // ebx
  CBasePlayer *EntityByName; // eax
  edict_t *v8; // esi
  const char *v9; // eax
  int v10; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]

  v2 = pSaveData;
  i = 0;
  if ( pSaveData->tableCount > 0 )
  {
    v10 = 0;
    do
    {
      v3 = &v2->pTable[v10];
      v3->hEnt.m_Index = -1;
      if ( v3->size != 0 )
      {
        edictindex = v3->edictindex;
        if ( edictindex != 0 )
        {
          pszValue = v3->classname.pszValue;
          if ( pszValue != nullptr )
          {
            flags = v3->flags;
            EntityByName = nullptr;
            if ( edictindex <= 0 || edictindex > gpGlobals->maxClients )
            {
              if ( (flags & levelMask) != 0 )
                EntityByName = (CBasePlayer *)CreateEntityByName(
                                                className: pszValue,
                                                iForceEdictIndex: -1,
                                                bNotify: true);
            }
            else
            {
              if ( gpGlobals->pEdicts != nullptr )
                v8 = (gpGlobals->pEdicts[edictindex].m_fStateFlags & 2) == 0 ? &gpGlobals->pEdicts[edictindex] : nullptr;
              else
                v8 = nullptr;
              if ( (flags & levelMask) != 0 && v8 != nullptr && (v8->m_fStateFlags & 2) == 0 )
              {
                if ( flags >= 0 )
                  _Warning(a1: "ENTITY IS NOT A PLAYER: %d\n", i);
                v9 = v3->classname.pszValue;
                if ( v9 == nullptr )
                  v9 = locale;
                EntityByName = CBasePlayer::CreatePlayer(className: v9, ed: v8);
              }
            }
            if ( EntityByName != nullptr )
              v3->hEnt.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
            else
              v3->hEnt.m_Index = -1;
          }
          else
          {
            _Warning(a1: "Entity with data saved, but with no classname\n");
          }
        }
      }
      v2 = pSaveData;
      ++v10;
      ++i;
    }
    while ( i < pSaveData->tableCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FB0D0
// Name: public: virtual void CSave::WriteString(char const __near *,struct string_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteString(CSave *this, const char *pname, const string_t *stringId, int count)
{
  int v4; // ebx
  unsigned int v6; // esi
  int v7; // ecx
  const char *pszValue; // eax
  CSave *v9; // [esp+Ch] [ebp-4h]

  v4 = count;
  v6 = 0;
  v7 = 0;
  v9 = this;
  if ( count > 0 )
  {
    do
    {
      pszValue = stringId[v7].pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      ++v7;
      v6 += strlen(pszValue) + 1;
    }
    while ( v7 < count );
    this = v9;
  }
  count = (unsigned __int16)v6;
  pname = (const char *)(unsigned __int16)CSaveRestoreSegment::FindCreateSymbol(this: this->m_pData, pszToken: pname);
  if ( v6 >= 0x8000 )
    _Warning(a1: "CSave::WriteHeader() size parameter exceeds 'short'!\n");
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)&count, size: 2);
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)&pname, size: 2);
  this->WriteString_3(this, a2: stringId, a3: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101FB180
// Name: public: virtual void CSave::WriteVector(char const __near *,class Vector const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteVector(CSave *this, const char *pname, const Vector *value, int count)
{
  unsigned int v5; // esi
  CSaveRestoreSegment *m_pData; // ecx

  v5 = 12 * count;
  m_pData = this->m_pData;
  count = (unsigned __int16)(12 * count);
  pname = (const char *)(unsigned __int16)CSaveRestoreSegment::FindCreateSymbol(this: m_pData, pszToken: pname);
  if ( v5 >= 0x8000 )
    _Warning(a1: "CSave::WriteHeader() size parameter exceeds 'short'!\n");
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)&count, size: 2);
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)&pname, size: 2);
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)value, size: v5);
}

//------------------------------------------------------------------------------
// Address: 0x101FB1F0
// Name: public: virtual void CSave::WriteQuaternion(char const __near *,class Quaternion const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteQuaternion(CSave *this, const char *pname, const Quaternion *value, int count)
{
  unsigned int v5; // esi
  CSaveRestoreSegment *m_pData; // ecx

  v5 = 16 * count;
  m_pData = this->m_pData;
  count = (unsigned __int16)(16 * count);
  pname = (const char *)(unsigned __int16)CSaveRestoreSegment::FindCreateSymbol(this: m_pData, pszToken: pname);
  if ( v5 >= 0x8000 )
    _Warning(a1: "CSave::WriteHeader() size parameter exceeds 'short'!\n");
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)&count, size: 2);
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)&pname, size: 2);
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)value, size: v5);
}

//------------------------------------------------------------------------------
// Address: 0x101FB260
// Name: public: void CSave::WriteVMatrix(char const __near *,class VMatrix const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteVMatrix(CSave *this, const char *pname, VMatrix *value, int count)
{
  unsigned int v5; // esi
  CSaveRestoreSegment *m_pData; // ecx

  v5 = count << 6;
  m_pData = this->m_pData;
  count = (unsigned __int16)((_WORD)count << 6);
  pname = (const char *)(unsigned __int16)CSaveRestoreSegment::FindCreateSymbol(this: m_pData, pszToken: pname);
  if ( v5 >= 0x8000 )
    _Warning(a1: "CSave::WriteHeader() size parameter exceeds 'short'!\n");
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)&count, size: 2);
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)&pname, size: 2);
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)value, size: v5);
}

//------------------------------------------------------------------------------
// Address: 0x101FB2D0
// Name: public: void CSave::WriteVMatrixWorldspace(char const __near *,class VMatrix const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteVMatrixWorldspace(CSave *this, const char *pname, const VMatrix *value, int count)
{
  int v4; // ebx
  unsigned int v6; // esi
  CSaveRestoreSegment *m_pData; // ecx

  v4 = count;
  v6 = count << 6;
  m_pData = this->m_pData;
  count = (unsigned __int16)((_WORD)count << 6);
  pname = (const char *)(unsigned __int16)CSaveRestoreSegment::FindCreateSymbol(this: m_pData, pszToken: pname);
  if ( v6 >= 0x8000 )
    _Warning(a1: "CSave::WriteHeader() size parameter exceeds 'short'!\n");
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)&count, size: 2);
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)&pname, size: 2);
  CSave::WriteVMatrixWorldspace(this, value, count: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101FB340
// Name: public: void CSave::WriteMatrix3x4Worldspace(char const __near *,struct matrix3x4_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteMatrix3x4Worldspace(CSave *this, const char *pname, const matrix3x4_t *value, int count)
{
  const char *v4; // ebx
  unsigned int v6; // esi
  CSaveRestoreSegment *m_pData; // ecx

  v4 = (const char *)count;
  v6 = 48 * count;
  m_pData = this->m_pData;
  count = (unsigned __int16)(48 * count);
  pname = (const char *)(unsigned __int16)CSaveRestoreSegment::FindCreateSymbol(this: m_pData, pszToken: pname);
  if ( v6 >= 0x8000 )
    _Warning(a1: "CSave::WriteHeader() size parameter exceeds 'short'!\n");
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)&count, size: 2);
  CSave::BufferData(this, a2: (const char *)this, pdata: (char *)&pname, size: 2);
  CSave::WriteMatrix3x4Worldspace(this, value, count: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101FB3B0
// Name: public: void CSave::WriteInterval(char const __near *,struct interval_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteInterval(CSave *this, const char *pname, interval_t *value, int count)
{
  const char *v5; // edi
  CSaveRestoreSegment *m_pData; // ecx

  v5 = (const char *)(8 * count);
  m_pData = this->m_pData;
  count = (unsigned __int16)(8 * count);
  pname = (const char *)(unsigned __int16)CSaveRestoreSegment::FindCreateSymbol(this: m_pData, pszToken: pname);
  if ( (unsigned int)v5 >= 0x8000 )
    _Warning(a1: "CSave::WriteHeader() size parameter exceeds 'short'!\n");
  CSave::BufferData(this, a2: v5, pdata: (char *)&count, size: 2);
  CSave::BufferData(this, a2: v5, pdata: (char *)&pname, size: 2);
  CSave::BufferData(this, a2: v5, pdata: (char *)value, size: (int)v5);
}

//------------------------------------------------------------------------------
// Address: 0x101FB420
// Name: private: void CSave::BufferField(char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::BufferField(CSave *this, const char *pname, int size, char *pdata)
{
  const char *v4; // edi
  CSaveRestoreSegment *m_pData; // ecx

  v4 = (const char *)size;
  m_pData = this->m_pData;
  size = (unsigned __int16)size;
  pname = (const char *)(unsigned __int16)CSaveRestoreSegment::FindCreateSymbol(this: m_pData, pszToken: pname);
  if ( (unsigned int)v4 >= 0x8000 )
    _Warning(a1: "CSave::WriteHeader() size parameter exceeds 'short'!\n");
  CSave::BufferData(this, a2: v4, pdata: (char *)&size, size: 2);
  CSave::BufferData(this, a2: v4, pdata: (char *)&pname, size: 2);
  CSave::BufferData(this, a2: v4, pdata, size: (int)v4);
}

//------------------------------------------------------------------------------
// Address: 0x101FB490
// Name: public: virtual void CSave::WriteFunction(struct datamap_t __near *,char const __near *,void (CBaseEntity::*const __near *)(struct inputdata_t __near &),int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteFunction(
        CSave *this,
        datamap_t *pRootMap,
        const char *pname,
        void (__thiscall **ppData)(CBaseEntity *this, inputdata_t *),
        int count)
{
  char *v6; // eax

  v6 = (char *)UTIL_FunctionToName(pMap: pRootMap, function: *ppData);
  if ( v6 == nullptr )
  {
    _Warning(a1: "Invalid function pointer in entity!\n");
    v6 = "BADFUNCTIONPOINTER";
  }
  CSave::BufferField(this, pname, size: strlen(v6) + 1, pdata: v6);
}

//------------------------------------------------------------------------------
// Address: 0x101FB4F0
// Name: private: bool CSave::WriteGameField(char const __near *,void __near *,struct datamap_t __near *,struct typedescription_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSave::WriteGameField(
        CSave *this,
        const char *pname,
        CBaseEntity **pData,
        datamap_t *pRootMap,
        typedescription_t *pField)
{
  typedescription_t *v5; // esi
  bool result; // al
  CBaseEntity *v8; // eax
  const struct model_t *v9; // eax
  const char *MaterialNameFromIndex; // eax
  CBaseEntity *v11; // [esp-4h] [ebp-Ch]

  v5 = pField;
  switch ( pField->fieldType )
  {
    case FIELD_CLASSPTR:
      this->WriteEntityPtr_2(this, a2: pField->fieldName, a3: pData, a4: pField->fieldSize);
      result = true;
      break;
    case FIELD_EHANDLE:
      this->WriteEHandle_2(this, a2: pField->fieldName, a3: (const CHandle<CBaseEntity> *)pData, a4: pField->fieldSize);
      result = true;
      break;
    case FIELD_EDICT:
      this->WriteEdictPtr_2(this, a2: pField->fieldName, a3: (edict_t **)pData, a4: pField->fieldSize);
      result = true;
      break;
    case FIELD_POSITION_VECTOR:
      this->WritePositionVector_3(this, a2: pField->fieldName, a3: (const Vector *)pData, a4: pField->fieldSize);
      result = true;
      break;
    case FIELD_TIME:
      this->WriteTime_2(this, a2: pField->fieldName, a3: (const float *)pData, a4: pField->fieldSize);
      result = true;
      break;
    case FIELD_TICK:
      this->WriteTick_2(this, a2: pField->fieldName, a3: (const int *)pData, a4: pField->fieldSize);
      result = true;
      break;
    case FIELD_MODELNAME:
    case FIELD_SOUNDNAME:
      this->WriteString(this, a2: pField->fieldName, a3: (const string_t *)pData, a4: pField->fieldSize);
      result = true;
      break;
    case FIELD_FUNCTION:
      this->WriteFunction(
        this,
        a2: pRootMap,
        a3: pField->fieldName,
        a4: (void (__thiscall *const *)(CBaseEntity *, inputdata_t *))pData,
        a5: pField->fieldSize);
      result = true;
      break;
    case FIELD_VMATRIX:
      CSave::WriteVMatrix(this, pname: pField->fieldName, value: (VMatrix *)pData, count: pField->fieldSize);
      result = true;
      break;
    case FIELD_VMATRIX_WORLDSPACE:
      CSave::WriteVMatrixWorldspace(
        this,
        pname: pField->fieldName,
        value: (const VMatrix *)pData,
        count: pField->fieldSize);
      result = true;
      break;
    case FIELD_MATRIX3X4_WORLDSPACE:
      CSave::WriteMatrix3x4Worldspace(
        this,
        pname: pField->fieldName,
        value: (const matrix3x4_t *)pData,
        count: pField->fieldSize);
      result = true;
      break;
    case FIELD_INTERVAL:
      CSave::WriteInterval(this, pname: pField->fieldName, value: (interval_t *)pData, count: pField->fieldSize);
      result = true;
      break;
    case FIELD_MODELINDEX:
      v8 = *pData;
      pData = nullptr;
      v9 = modelinfo->GetModel(this: modelinfo, a2: v8);
      if ( v9 != nullptr )
      {
        modelinfo->GetModelName(this: modelinfo, a2: v9);
        pData = *(CBaseEntity ***)AllocPooledString(pszValue: (const char *)&pField).pszValue;
      }
      goto LABEL_10;
    case FIELD_MATERIALINDEX:
      v11 = *pData;
      pData = nullptr;
      MaterialNameFromIndex = GetMaterialNameFromIndex(nMaterialIndex: (int)v11);
      if ( MaterialNameFromIndex != nullptr )
        pData = *MaterialNameFromIndex != 0 ? (CBaseEntity **)MaterialNameFromIndex : nullptr;
LABEL_10:
      this->WriteString(this, a2: v5->fieldName, a3: (const string_t *)&pData, a4: v5->fieldSize);
      result = true;
      break;
    default:
      _Warning(a1: "Bad field type\n");
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FB780
// Name: public: virtual int CRestore::ReadFields(char const __near *,void __near *,struct datamap_t __near *,struct typedescription_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadFields(
        CRestore *this,
        const char *pname,
        char *pBaseData,
        datamap_t *pRootMap,
        typedescription_t *pFields,
        int fieldCount)
{
  int Symbol; // edi
  int v8; // edx
  CSaveRestoreSegment *v9; // eax
  const char *v10; // edi
  const char *v11; // ecx
  CSaveRestoreSegment *v12; // esi
  int v13; // eax
  int v14; // ecx
  int v15; // ecx
  void (__thiscall *EmptyFields)(struct CRestore *, void *, typedescription_t *, int); // edx
  int v18; // eax
  CSaveRestoreSegment *m_pData; // ecx
  const char *v20; // eax
  typedescription_t *Field; // eax
  __int16 flags; // cx
  CBaseEntity **v23; // ecx
  CSaveRestoreSegment *v24; // eax
  int size; // edi
  int v26; // ecx
  int v27; // edx
  int searchCookie; // [esp+Ch] [ebp-8h] BYREF
  SaveRestoreRecordHeader_t header; // [esp+10h] [ebp-4h] BYREF
  const char *pnamea; // [esp+1Ch] [ebp+8h]

  this->ReadShort_2(this);
  Symbol = (unsigned __int16)CSaveRestoreSegment::FindCreateSymbol(this: this->m_pData, pszToken: pname);
  v8 = this->ReadShort_2(this);
  if ( v8 == Symbol )
  {
    EmptyFields = this->EmptyFields;
    lastName = Symbol;
    EmptyFields(this, a2: pBaseData, a3: pFields, a4: fieldCount);
    v18 = this->ReadInt(this);
    searchCookie = 0;
    if ( v18 <= 0 )
      return 1;
    pnamea = (const char *)v18;
    while ( 1 )
    {
      this->ReadHeader(this, a2: &header);
      m_pData = this->m_pData;
      if ( header.symbol >= m_pData->tokenCount )
        v20 = "<<illegal>>";
      else
        v20 = m_pData->pTokens[header.symbol];
      Field = CRestore::FindField(this, pszFieldName: v20, pFields, fieldCount, pCookie: &searchCookie);
      if ( Field != nullptr )
      {
        flags = Field->flags;
        if ( (flags & 2) != 0 && (this->m_global == 0 || (flags & 1) == 0) )
        {
          v23 = (CBaseEntity **)&pBaseData[Field->fieldOffset];
          if ( Field->fieldType > FIELD_CUSTOM )
            CRestore::ReadGameField(this, &header, pDest: v23, pRootMap, pField: Field);
          else
            CRestore::ReadBasicField(this, &header, pDest: (Vector *)v23, pRootMap, pField: Field);
          goto LABEL_33;
        }
      }
      v24 = this->m_pData;
      size = header.size;
      if ( v24 != nullptr && v24->bufferSize != v24->size )
      {
        v26 = v24->size;
        v27 = v24->bufferSize - v26;
        if ( v27 != 0 )
        {
          if ( header.size <= v27 )
          {
            v24->pCurrentData += header.size;
            v24->size = size + v26;
            goto LABEL_33;
          }
          v24->size = v24->bufferSize;
        }
        _Warning(a1: "Restore underflow!\n");
      }
LABEL_33:
      if ( --pnamea == nullptr )
        return 1;
    }
  }
  v9 = this->m_pData;
  if ( lastName < 0 || lastName >= v9->tokenCount )
    v10 = "<<illegal>>";
  else
    v10 = v9->pTokens[lastName];
  if ( v8 < 0 || v8 >= v9->tokenCount )
    v11 = "<<illegal>>";
  else
    v11 = v9->pTokens[v8];
  if ( v9 != nullptr )
    v9 = (CSaveRestoreSegment *)v9->pCurrentData;
  _Msg(a1: "Expected %s found %s ( raw '%s' )! (prev: %s)\n", pname, v11, (const char *)v9, v10);
  _Msg(a1: "Field type name may have changed or inheritance graph changed, save file is suspect\n");
  v12 = this->m_pData;
  v13 = v12->size;
  v14 = 4;
  if ( v13 < 4 )
    v14 = v12->size;
  v15 = -v14;
  v12->pCurrentData += v15;
  v12->size = v15 + v13;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FB940
// Name: public: virtual int CRestore::ReadEdictPtr(struct edict_t __near * __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadEdictPtr(CRestore *this, edict_t **ppEdict, int count, int nBytesAvailable)
{
  int v4; // edi
  int v6; // esi
  edict_t **v7; // edi
  int v8; // eax
  CGameSaveRestoreInfo *m_pGameInfo; // ecx
  int v10; // esi
  int tableCount; // edx
  int v12; // eax
  entitytable_t *pTable; // ecx
  IHandleEntity_vtbl *v14; // eax
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  _BYTE v18[4096]; // [esp+Ch] [ebp-1008h] BYREF
  int v19; // [esp+100Ch] [ebp-8h]
  int v20; // [esp+1010h] [ebp-4h]
  int v21; // [esp+1024h] [ebp+10h]

  v4 = count;
  v6 = this->ReadInt_2(this, a2: (int *)v18, a3: count, a4: nBytesAvailable);
  v20 = v6;
  if ( v6 > 0 )
  {
    v7 = ppEdict;
    v8 = v18 - (_BYTE *)ppEdict;
    v19 = v18 - (_BYTE *)ppEdict;
    v21 = v6;
    while ( 1 )
    {
      m_pGameInfo = this->m_pGameInfo;
      v10 = *(int *)((char *)v7 + v8);
      if ( m_pGameInfo == nullptr )
        goto LABEL_10;
      if ( v10 < 0 )
        goto LABEL_10;
      tableCount = m_pGameInfo->tableCount;
      v12 = 0;
      if ( tableCount <= 0 )
        goto LABEL_10;
      pTable = m_pGameInfo->pTable;
      while ( pTable->id != v10 )
      {
        ++v12;
        ++pTable;
        if ( v12 >= tableCount )
          goto LABEL_10;
      }
      m_Index = pTable->hEnt.m_Index;
      if ( m_Index != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
      {
        v14 = m_pEntity[6].__vftable;
      }
      else
      {
LABEL_10:
        v14 = nullptr;
      }
      *v7++ = (edict_t *)v14;
      if ( --v21 == 0 )
        break;
      v8 = v19;
    }
    v6 = v20;
    v4 = count;
  }
  if ( v6 < v4 )
    memset(dst: (int)&ppEdict[v6], value: nullptr, count: 4 * (v4 - v6));
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101FBA30
// Name: public: virtual void CEntitySaveRestoreBlockHandler::Save(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntitySaveRestoreBlockHandler::Save(CEntitySaveRestoreBlockHandler *this, ISave *pSave)
{
  ISave *v2; // edi
  CGameSaveRestoreInfo *(__thiscall *GetGameSaveRestoreInfo)(ISave *); // edx
  _DWORD *v4; // ebx
  int v5; // esi
  unsigned int v6; // eax
  CEntInfo *v7; // ecx
  IHandleEntity *m_pEntity; // edi
  void (*BeginLock)(void); // edx
  int v10; // eax
  int v11; // eax
  IHandleEntity_vtbl *v12; // edi
  signed int v13; // edi
  Vector result; // [esp+8h] [ebp-1Ch] BYREF
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+14h] [ebp-10h]
  CEntitySaveRestoreBlockHandler *v16; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  int v18; // [esp+20h] [ebp-4h]

  v2 = pSave;
  GetGameSaveRestoreInfo = pSave->GetGameSaveRestoreInfo;
  v16 = this;
  v4 = (_DWORD *)GetGameSaveRestoreInfo(this: pSave);
  i = 0;
  if ( (int)v4[344] > 0 )
  {
    v18 = 0;
    do
    {
      v5 = v18 + v4[345];
      *(_DWORD *)(v5 + 20) = v2->GetWritePos(this: v2);
      *(_DWORD *)(v5 + 24) = 0;
      v6 = *(_DWORD *)(v5 + 16);
      if ( v6 != -1 )
      {
        v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v6];
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber == HIWORD(v6) )
        {
          m_pEntity = v7->m_pEntity;
          if ( v7->m_pEntity != nullptr && (int)m_pEntity->__vftable[12].GetRefEHandle(this: v7->m_pEntity) >= 0 )
          {
            BeginLock = (void (*)(void))mdlcache->BeginLock;
            cacheCriticalSection.m_pCache = mdlcache;
            BeginLock();
            v4[346] = m_pEntity;
            m_pEntity->__vftable[14].SetRefEHandle(this: m_pEntity, a2: (const CBaseHandle *)pSave);
            v4[346] = 0;
            v10 = pSave->GetWritePos(this: pSave) - *(_DWORD *)(v5 + 20);
            *(_DWORD *)(v5 + 24) = v10;
            v4[343] += v10;
            *(IHandleEntity *)(v5 + 32) = m_pEntity[23];
            *(IHandleEntity *)(v5 + 36) = m_pEntity[127];
            v11 = ((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[2].dtr_IHandleEntity)(a1: m_pEntity);
            *(Vector *)(v5 + 40) = *CEntitySaveRestoreBlockHandler::ModelSpaceLandmark(
                                      this: v16,
                                      &result,
                                      modelIndex: v11);
            v12 = m_pEntity[6].__vftable;
            if ( v12 != nullptr )
              v13 = ((char *)v12 - (char *)gpGlobals->pEdicts) >> 4;
            else
              v13 = -1;
            if ( v13 >= 1 && v13 <= gpGlobals->maxClients )
              *(_DWORD *)(v5 + 28) |= 0x80000000;
            cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
          }
          v2 = pSave;
        }
      }
      v18 += 56;
      ++i;
    }
    while ( i < v4[344] );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FBBA0
// Name: private: bool CEntitySaveRestoreBlockHandler::DoRestoreEntity(class CBaseEntity __near *,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEntitySaveRestoreBlockHandler::DoRestoreEntity(
        CEntitySaveRestoreBlockHandler *this,
        CBaseEntity *pEntity,
        IRestore *pRestore)
{
  unsigned int m_Index; // edi
  bool v4; // zf
  CBaseEntity_vtbl *v5; // eax
  IHandleEntity *m_pEntity; // esi
  IMDLCache *cacheCriticalSection; // [esp+8h] [ebp-4h]

  cacheCriticalSection = mdlcache;
  ((void (*)(void))mdlcache->BeginLock)();
  if ( pEntity != nullptr )
    m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
  else
    m_Index = -1;
  pRestore->GetGameSaveRestoreInfo(this: pRestore)->m_pCurrentEntity = pEntity;
  pEntity->Restore(this: pEntity, a2: pRestore);
  pRestore->GetGameSaveRestoreInfo(this: pRestore)->m_pCurrentEntity = nullptr;
  v4 = (pEntity->ObjectCaps(this: pEntity) & 0x40) == 0;
  v5 = pEntity->__vftable;
  if ( v4 )
    ((void (__fastcall *)(CBaseEntity *))v5->Precache)(a1: pEntity);
  else
    ((void (__fastcall *)(CBaseEntity *))v5->Spawn)(a1: pEntity);
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  cacheCriticalSection->EndLock(this: cacheCriticalSection);
  return m_pEntity != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101FBC70
// Name: private: int CEntitySaveRestoreBlockHandler::RestoreEntity(class CBaseEntity __near *,class IRestore __near *,struct entitytable_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEntitySaveRestoreBlockHandler::RestoreEntity(
        CEntitySaveRestoreBlockHandler *this,
        CBaseEntity *pEntity,
        IRestore *pRestore,
        entitytable_t *pEntInfo)
{
  const char *pszValue; // eax
  int Index; // eax
  int v7; // edi
  const char *v8; // ebx
  const char *Map; // eax
  const char *v10; // ecx
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // esi

  if ( !CEntitySaveRestoreBlockHandler::DoRestoreEntity(this, pEntity, pRestore) )
    return 0;
  pszValue = pEntity->m_iGlobalname.pszValue;
  if ( pszValue != nullptr )
  {
    Index = GlobalEntity_GetIndex(pGlobalname: pszValue);
    v7 = Index;
    if ( Index < 0 )
    {
      v10 = pEntity->m_iClassname.pszValue;
      if ( v10 == nullptr )
        v10 = locale;
      v11 = pEntity->m_iGlobalname.pszValue;
      if ( v11 == nullptr )
        v11 = locale;
      _Warning(a1: "Global Entity %s (%s) not in table!!!\n", v11, v10);
      v12 = gpGlobals->mapname.pszValue;
      v13 = pEntity->m_iGlobalname.pszValue;
      if ( v12 == nullptr )
        v12 = locale;
      if ( v13 == nullptr )
        v13 = locale;
      GlobalEntity_Add(pGlobalname: v13, pMapName: v12, state: GLOBAL_ON);
    }
    else
    {
      if ( GlobalEntity_GetState(globalIndex: Index) == GLOBAL_DEAD )
        return -1;
      v8 = gpGlobals->mapname.pszValue;
      if ( v8 == nullptr )
        v8 = locale;
      Map = GlobalEntity_GetMap(globalIndex: v7);
      if ( !FStrEq(sz1: v8, sz2: Map) )
      {
        CBaseEntity::MakeDormant(this: pEntity);
        return 0;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FBD60
// Name: public: int CUtlHash<struct CGameSaveRestoreInfo::CHashElement,class CGameSaveRestoreInfo::CHashFuncs,class CGameSaveRestoreInfo::CHashFuncs>::Count(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>::Count(
        CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs> *this)
{
  int m_Size; // edx
  int v2; // ebx
  int v3; // esi
  int v4; // edi
  int *p_m_Size; // eax
  unsigned int v6; // edx
  int count; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Buckets.m_Size;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  count = 0;
  if ( m_Size >= 2 )
  {
    p_m_Size = &this->m_Buckets.m_Memory.m_pMemory[1].m_Size;
    v6 = ((unsigned int)(m_Size - 2) >> 1) + 1;
    v2 = 2 * v6;
    do
    {
      v3 += *(p_m_Size - 5);
      v4 += *p_m_Size;
      p_m_Size += 10;
      --v6;
    }
    while ( v6 != 0 );
  }
  if ( v2 < this->m_Buckets.m_Size )
    count = this->m_Buckets.m_Memory.m_pMemory[v2].m_Size;
  return count + v4 + v3;
}

//------------------------------------------------------------------------------
// Address: 0x101FBDB0
// Name: protected: bool CUtlHash<struct CGameSaveRestoreInfo::CHashElement,class CGameSaveRestoreInfo::CHashFuncs,class CGameSaveRestoreInfo::CHashFuncs>::DoFind(struct CGameSaveRestoreInfo::CHashElement const __near &,unsigned int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>::DoFind(
        CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs> *this,
        const CGameSaveRestoreInfo::CHashElement *src,
        unsigned int *pBucket,
        int *pIndex)
{
  unsigned int v5; // eax
  unsigned int v6; // edx
  unsigned int v7; // edx
  int m_Size; // ecx
  CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int> > *v9; // edx
  int v10; // eax
  const CBaseEntity **p_pEntity; // edx

  v5 = Hash4(pKey: src);
  if ( this->m_bPowerOfTwo )
    v6 = v5 & this->m_ModMask;
  else
    v6 = v5 % this->m_Buckets.m_Size;
  *pBucket = v6;
  v7 = v6;
  m_Size = this->m_Buckets.m_Memory.m_pMemory[v7].m_Size;
  v9 = &this->m_Buckets.m_Memory.m_pMemory[v7];
  v10 = 0;
  if ( m_Size > 0 )
  {
    p_pEntity = &v9->m_Memory.m_pMemory->pEntity;
    do
    {
      if ( *p_pEntity == src->pEntity )
        break;
      ++v10;
      p_pEntity += 2;
    }
    while ( v10 < m_Size );
  }
  if ( v10 == m_Size )
    return 0;
  *pIndex = v10;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101FBE20
// Name: public: virtual void CSave::WriteData(char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteData(CSave *this, const char *pname, int size, char *pdata)
{
  CSave::BufferField(this, pname, size, pdata);
}

//------------------------------------------------------------------------------
// Address: 0x101FBE30
// Name: public: virtual void CSave::WriteShort(char const __near *,short const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteShort(CSave *this, const char *pname, char *data, int count)
{
  CSave::BufferField(this, pname, size: 2 * count, pdata: data);
}

//------------------------------------------------------------------------------
// Address: 0x101FBE50
// Name: public: virtual void CSave::WriteBool(char const __near *,bool const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteBool(CSave *this, const char *pname, bool *data, int count)
{
  CSave::BufferField(this, pname, size: count, pdata: (char *)data);
}

//------------------------------------------------------------------------------
// Address: 0x101FBE70
// Name: public: virtual void CSave::WriteInt(char const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteInt(CSave *this, const char *pname, float *data, int count)
{
  CSave::BufferField(this, pname, size: 4 * count, pdata: (char *)data);
}

//------------------------------------------------------------------------------
// Address: 0x101FBE90
// Name: public: virtual void CSave::WriteString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteString(CSave *this, const char *pname, char *pdata)
{
  CSave::BufferField(this, pname, size: strlen(pdata) + 1, pdata);
}

//------------------------------------------------------------------------------
// Address: 0x101FBEC0
// Name: public: virtual int CSave::WriteFields(char const __near *,void const __near *,struct datamap_t __near *,struct typedescription_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSave::WriteFields(
        CSave *this,
        const char *pname,
        char *pBaseData,
        datamap_t *pRootMap,
        typedescription_t *pFields,
        int fieldCount)
{
  void (__thiscall *WriteInt)(struct CSave *, const char *, const int *, int); // edx
  CBaseEntity **v9; // edi
  bool v10; // al
  CSaveRestoreSegment *m_pData; // eax
  int size; // edx
  int v13; // edi
  int v14; // ecx
  int v15; // ecx
  CSaveRestoreSegment *v16; // esi
  int v18; // edi
  int iHeaderPos; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  int count; // [esp+14h] [ebp-4h] BYREF

  WriteInt = this->WriteInt;
  iHeaderPos = this->m_pData->size;
  count = -1;
  WriteInt(this, a2: pname, a3: &count, a4: 1);
  count = 0;
  for ( i = 0; i < fieldCount; ++i )
  {
    v9 = (CBaseEntity **)&pBaseData[pFields->fieldOffset];
    if ( CSave::ShouldSaveField(this, pData: (char *)v9, pField: (int)pFields) )
    {
      if ( pFields->fieldType > FIELD_CUSTOM )
        v10 = CSave::WriteGameField(this, pname, pData: v9, pRootMap, pField: pFields);
      else
        v10 = CSave::WriteBasicField(this, pname, pData: (const Vector *)v9, pRootMap, pField: pFields);
      if ( !v10 )
        break;
      ++count;
    }
    ++pFields;
  }
  m_pData = this->m_pData;
  size = m_pData->size;
  v13 = size - iHeaderPos;
  v14 = size - iHeaderPos;
  if ( size < size - iHeaderPos )
    v14 = m_pData->size;
  v15 = -v14;
  m_pData->pCurrentData += v15;
  m_pData->size = v15 + size;
  this->WriteInt(this, a2: pname, a3: &count, a4: 1);
  v16 = this->m_pData;
  v18 = iHeaderPos + v13 - v16->size;
  v16->pCurrentData += v18;
  v16->size += v18;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101FBFA0
// Name: public: virtual void CSave::EndBlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::EndBlock(CSave *this)
{
  const char *v2; // edi
  int v3; // ebx
  int sizeBlock; // [esp+Ch] [ebp-4h] BYREF

  v2 = (const char *)this->GetWritePos(this);
  v3 = this->m_BlockStartStack.m_Memory.m_pMemory[this->m_BlockStartStack.m_Size - 1];
  sizeBlock = (unsigned __int16)((_WORD)v2 - v3);
  --this->m_BlockStartStack.m_Size;
  this->SetWritePos(this, a2: v3 - 4);
  CSave::BufferData(this, a2: v2, pdata: (char *)&sizeBlock, size: 2);
  this->SetWritePos(this, a2: (int)v2);
}

//------------------------------------------------------------------------------
// Address: 0x101FC020
// Name: public: virtual void CRestore::EndBlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRestore::EndBlock(CRestore *this)
{
  int v1; // edi

  v1 = this->m_BlockEndStack.m_Memory.m_pMemory[--this->m_BlockEndStack.m_Size];
  this->SetReadPos(this, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x101FC060
// Name: public: virtual void CEntitySaveRestoreBlockHandler::Restore(class IRestore __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntitySaveRestoreBlockHandler::Restore(
        CEntitySaveRestoreBlockHandler *this,
        IRestore *pRestore,
        bool createPlayers)
{
  CGameSaveRestoreInfo *v3; // eax
  int v4; // edx
  entitytable_t *v5; // esi
  int flags; // ecx
  int edictindex; // eax
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // edi
  edict_t *v10; // eax
  const char *v11; // ecx
  CBasePlayer *Player; // eax
  const char *v13; // eax
  signed int m_pPev; // eax
  int v15; // ebx
  entitytable_t *v16; // esi
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // edi
  CGameSaveRestoreInfo *pSaveData; // [esp+Ch] [ebp-10h]
  int v21; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]
  int ia; // [esp+18h] [ebp-4h]

  v3 = pRestore->GetGameSaveRestoreInfo(this: pRestore);
  v4 = 0;
  pSaveData = v3;
  i = 0;
  if ( v3->tableCount > 0 )
  {
    v21 = 0;
    while ( 1 )
    {
      v5 = &v3->pTable[v21];
      if ( v5->classname.pszValue != nullptr && v5->size != 0 )
      {
        flags = v5->flags;
        if ( (flags & 0x40000000) == 0 )
          break;
      }
      v5->hEnt.m_Index = -1;
      v5->restoreentityindex = -1;
LABEL_37:
      v3 = pSaveData;
      ++v21;
      v4 = i + 1;
      i = v4;
      if ( v4 >= pSaveData->tableCount )
        goto LABEL_38;
    }
    edictindex = v5->edictindex;
    if ( edictindex == 0 )
    {
      pszValue = v5->classname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      EntityByName = CreateEntityByName(className: pszValue, iForceEdictIndex: -1, bNotify: true);
      pRestore->SetReadPos(this: pRestore, a2: v5->location);
      if ( CEntitySaveRestoreBlockHandler::RestoreEntity(this, pEntity: EntityByName, pRestore, pEntInfo: v5) >= 0 )
      {
        AddRestoredEntity(pEntity: EntityByName);
      }
      else
      {
        v5->hEnt.m_Index = -1;
        v5->restoreentityindex = -1;
        UTIL_RemoveImmediate(oldObj: EntityByName);
      }
      goto LABEL_26;
    }
    if ( edictindex <= 0 || edictindex > gpGlobals->maxClients )
    {
      v13 = v5->classname.pszValue;
      if ( v13 == nullptr )
        v13 = locale;
      Player = (CBasePlayer *)CreateEntityByName(className: v13, iForceEdictIndex: -1, bNotify: true);
    }
    else
    {
      if ( flags >= 0 )
        _Warning(a1: "ENTITY IS NOT A PLAYER: %d\n", v4);
      v10 = INDEXENT(iEdictNum: v5->edictindex);
      if ( v10 == nullptr || !createPlayers )
      {
        EntityByName = nullptr;
LABEL_26:
        if ( EntityByName != nullptr )
        {
          v5->hEnt.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
          m_pPev = (signed int)EntityByName->m_Network.m_pPev;
          if ( m_pPev != 0 )
            m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
        }
        else
        {
          m_pPev = -1;
          v5->hEnt.m_Index = -1;
        }
        v5->restoreentityindex = m_pPev;
        if ( EntityByName != nullptr
          && m_pPev == 0
          && EntityByName->m_iClassname.pszValue != "worldspawn"
          && CBaseEntity::ClassMatchesComplex(this: EntityByName, pszClassOrWildcard: "worldspawn") == 0 )
        {
          v5->restoreentityindex = -1;
        }
        goto LABEL_37;
      }
      v11 = v5->classname.pszValue;
      if ( v11 == nullptr )
        v11 = locale;
      Player = CBasePlayer::CreatePlayer(className: v11, ed: v10);
    }
    EntityByName = Player;
    goto LABEL_26;
  }
LABEL_38:
  v15 = 0;
  ia = 0;
  if ( v3->tableCount > 0 )
  {
    do
    {
      v16 = &v3->pTable[v15];
      if ( v16->edictindex != 0 )
      {
        m_Index = v16->hEnt.m_Index;
        if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
          m_pEntity = nullptr;
        else
          m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
        pRestore->SetReadPos(this: pRestore, a2: v16->location);
        if ( m_pEntity != nullptr )
        {
          if ( CEntitySaveRestoreBlockHandler::RestoreEntity(this, pEntity: m_pEntity, pRestore, pEntInfo: v16) >= 0 )
          {
            AddRestoredEntity(pEntity: m_pEntity);
          }
          else
          {
            v16->hEnt.m_Index = -1;
            v16->restoreentityindex = -1;
            UTIL_RemoveImmediate(oldObj: m_pEntity);
          }
        }
      }
      v3 = pSaveData;
      ++v15;
      ++ia;
    }
    while ( ia < pSaveData->tableCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FC2C0
// Name: public: int CGameSaveRestoreInfo::GetEntityIndex(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameSaveRestoreInfo::GetEntityIndex(CGameSaveRestoreInfo *this, const CBaseEntity *pEntity)
{
  const CBaseEntity *v2; // ebx
  unsigned int v4; // eax
  int tableCount; // edi
  int v7; // edx
  entitytable_t *i; // esi
  unsigned int m_Index; // eax
  const CBaseEntity *m_pEntity; // ecx
  CGameSaveRestoreInfo::CHashElement src; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int pBucket; // [esp+14h] [ebp-4h] BYREF

  v2 = pEntity;
  if ( pEntity == nullptr )
    return -1;
  if ( CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>::Count(this: &this->m_EntityToIndex) != 0 )
  {
    src.pEntity = v2;
    pEntity = nullptr;
    if ( CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>::DoFind(
           this: &this->m_EntityToIndex,
           &src,
           &pBucket,
           pIndex: (int *)&pEntity) != 0 )
    {
      v4 = (unsigned int)pEntity | (pBucket << 16);
      if ( v4 != -1 )
        return this->m_EntityToIndex.m_Buckets.m_Memory.m_pMemory[HIWORD(v4)].m_Memory.m_pMemory[(unsigned __int16)pEntity].index;
    }
    return -1;
  }
  tableCount = this->tableCount;
  v7 = 0;
  if ( tableCount <= 0 )
    return -1;
  for ( i = this->pTable; ; ++i )
  {
    m_Index = i->hEnt.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (const CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity == pEntity )
      break;
    if ( ++v7 >= tableCount )
      return -1;
  }
  return i->id;
}

//------------------------------------------------------------------------------
// Address: 0x101FC3A0
// Name: public: CSave::CSave(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
CSave *__thiscall CSave::CSave(CSave *this, CSaveRestoreData *pdata)
{
  CGameSaveRestoreInfo *v3; // ecx
  int *m_pMemory; // eax
  IMemAlloc_vtbl *v5; // edx
  int *v6; // eax

  this->__vftable = (CSave_vtbl *)&CSave::`vftable';
  this->m_BlockStartStack.m_Memory.m_pMemory = nullptr;
  this->m_BlockStartStack.m_Memory.m_nAllocationCount = 0;
  this->m_BlockStartStack.m_Memory.m_nGrowSize = 0;
  this->m_BlockStartStack.m_Size = 0;
  this->m_BlockStartStack.m_pElements = nullptr;
  this->m_pData = pdata;
  if ( pdata != nullptr )
    v3 = &pdata->CGameSaveRestoreInfo;
  else
    v3 = nullptr;
  this->m_pGameInfo = v3;
  this->m_bAsync = pdata->bAsync;
  if ( this->m_BlockStartStack.m_Memory.m_nAllocationCount < 32 && this->m_BlockStartStack.m_Memory.m_nGrowSize >= 0 )
  {
    this->m_BlockStartStack.m_Memory.m_nAllocationCount = 32;
    m_pMemory = this->m_BlockStartStack.m_Memory.m_pMemory;
    v5 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
    {
      v6 = (int *)((int (__stdcall *)(int *, int))v5->Realloc_2)(a1: m_pMemory, a2: 128);
      this->m_BlockStartStack.m_Memory.m_pMemory = v6;
      this->m_BlockStartStack.m_pElements = v6;
      this->m_hLogFile = nullptr;
      return this;
    }
    this->m_BlockStartStack.m_Memory.m_pMemory = (int *)((int (__stdcall *)(int))v5->Alloc_2)(a1: 128);
  }
  this->m_BlockStartStack.m_pElements = this->m_BlockStartStack.m_Memory.m_pMemory;
  this->m_hLogFile = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101FC440
// Name: public: virtual int CSave::WriteAll(void const __near *,struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSave::WriteAll(CSave *this, const void *pLeafObject, datamap_t *pLeafMap)
{
  int result; // eax

  if ( pLeafMap->baseMap == nullptr )
    return this->WriteFields(
             this,
             a2: pLeafMap->dataClassName,
             a3: pLeafObject,
             a4: pLeafMap,
             a5: pLeafMap->dataDesc,
             a6: pLeafMap->dataNumFields);
  result = CSave::DoWriteAll(this, pLeafObject, pLeafMap, pCurMap: pLeafMap->baseMap);
  if ( result != 0 )
    return this->WriteFields(
             this,
             a2: pLeafMap->dataClassName,
             a3: pLeafObject,
             a4: pLeafMap,
             a5: pLeafMap->dataDesc,
             a6: pLeafMap->dataNumFields);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FC490
// Name: public: int CSave::EntityIndex(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSave::EntityIndex(CSave *this, const CBaseEntity *pEntity)
{
  return CGameSaveRestoreInfo::GetEntityIndex(this: this->m_pGameInfo, pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x101FC4A0
// Name: public: virtual void CSave::WriteEntityPtr(char const __near *,class CBaseEntity __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteEntityPtr(CSave *this, const char *pname, CBaseEntity **ppEntity, int count)
{
  int v4; // esi
  int i; // eax
  CBaseEntity *pEntity[1024]; // [esp+Ch] [ebp-1000h] BYREF

  v4 = 0;
  if ( count > 0 )
  {
    for ( i = (char *)ppEntity - (char *)pEntity; v4 < 1024; i = (char *)ppEntity - (char *)pEntity )
    {
      pEntity[v4] = (CBaseEntity *)CGameSaveRestoreInfo::GetEntityIndex(
                                     this: this->m_pGameInfo,
                                     pEntity: *(CBaseEntity **)((char *)&pEntity[v4] + i));
      if ( ++v4 >= count )
        break;
    }
  }
  this->WriteInt(this, a2: pname, a3: (const int *)pEntity, a4: count);
}

//------------------------------------------------------------------------------
// Address: 0x101FC520
// Name: public: virtual void CSave::WriteEntityPtr(class CBaseEntity __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteEntityPtr(CSave *this, CBaseEntity **ppEntity, int count)
{
  int v3; // esi
  int i; // eax
  CBaseEntity *pEntity[1024]; // [esp+Ch] [ebp-1000h] BYREF

  v3 = 0;
  if ( count > 0 )
  {
    for ( i = (char *)ppEntity - (char *)pEntity; v3 < 1024; i = (char *)ppEntity - (char *)pEntity )
    {
      pEntity[v3] = (CBaseEntity *)CGameSaveRestoreInfo::GetEntityIndex(
                                     this: this->m_pGameInfo,
                                     pEntity: *(CBaseEntity **)((char *)&pEntity[v3] + i));
      if ( ++v3 >= count )
        break;
    }
  }
  this->WriteInt_2(this, a2: (const int *)pEntity, a3: count);
}

//------------------------------------------------------------------------------
// Address: 0x101FC5A0
// Name: public: virtual void CSave::WriteEHandle(char const __near *,class CHandle<class CBaseEntity> const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteEHandle(CSave *this, const char *pname, const CHandle<CBaseEntity> *pEHandle, int count)
{
  int v4; // edi
  const CHandle<CBaseEntity> *v6; // esi
  unsigned int m_Index; // eax
  const CBaseEntity *m_pEntity; // eax
  _BYTE v9[4096]; // [esp+8h] [ebp-1000h] BYREF
  int v10; // [esp+1014h] [ebp+Ch]

  v4 = 0;
  if ( count > 0 )
  {
    v6 = pEHandle;
    v10 = v9 - (_BYTE *)pEHandle;
    do
    {
      if ( v4 >= 1024 )
        break;
      m_Index = v6->m_Index;
      if ( v6->m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = (const CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      }
      *(unsigned int *)((char *)&v6->m_Index + v10) = CGameSaveRestoreInfo::GetEntityIndex(
                                                        this: this->m_pGameInfo,
                                                        pEntity: m_pEntity);
      ++v4;
      ++v6;
    }
    while ( v4 < count );
  }
  this->WriteInt(this, a2: pname, a3: (const int *)v9, a4: count);
}

//------------------------------------------------------------------------------
// Address: 0x101FC640
// Name: public: virtual void CSave::WriteEHandle(class CHandle<class CBaseEntity> const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteEHandle(CSave *this, const CHandle<CBaseEntity> *pEHandle, int count)
{
  int v3; // edi
  const CHandle<CBaseEntity> *v5; // esi
  unsigned int m_Index; // eax
  const CBaseEntity *m_pEntity; // eax
  _BYTE v8[4096]; // [esp+8h] [ebp-1000h] BYREF
  int v9; // [esp+1010h] [ebp+8h]

  v3 = 0;
  if ( count > 0 )
  {
    v5 = pEHandle;
    v9 = v8 - (_BYTE *)pEHandle;
    do
    {
      if ( v3 >= 1024 )
        break;
      m_Index = v5->m_Index;
      if ( v5->m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = (const CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      }
      *(unsigned int *)((char *)&v5->m_Index + v9) = CGameSaveRestoreInfo::GetEntityIndex(
                                                       this: this->m_pGameInfo,
                                                       pEntity: m_pEntity);
      ++v3;
      ++v5;
    }
    while ( v3 < count );
  }
  this->WriteInt_2(this, a2: (const int *)v8, a3: count);
}

//------------------------------------------------------------------------------
// Address: 0x101FC6D0
// Name: public: CRestore::CRestore(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
CRestore *__thiscall CRestore::CRestore(CRestore *this, CSaveRestoreData *pdata)
{
  CGameSaveRestoreInfo *v3; // eax
  int *m_pMemory; // eax
  IMemAlloc_vtbl *v5; // edx
  int *v6; // eax

  this->__vftable = (CRestore_vtbl *)&CRestore::`vftable';
  this->m_BlockEndStack.m_Memory.m_pMemory = nullptr;
  this->m_BlockEndStack.m_Memory.m_nAllocationCount = 0;
  this->m_BlockEndStack.m_Memory.m_nGrowSize = 0;
  this->m_BlockEndStack.m_Size = 0;
  this->m_BlockEndStack.m_pElements = nullptr;
  this->m_pData = pdata;
  if ( pdata != nullptr )
    v3 = &pdata->CGameSaveRestoreInfo;
  else
    v3 = nullptr;
  this->m_pGameInfo = v3;
  this->m_global = 0;
  this->m_precache = true;
  if ( this->m_BlockEndStack.m_Memory.m_nAllocationCount < 32 && this->m_BlockEndStack.m_Memory.m_nGrowSize >= 0 )
  {
    this->m_BlockEndStack.m_Memory.m_nAllocationCount = 32;
    m_pMemory = this->m_BlockEndStack.m_Memory.m_pMemory;
    v5 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
    {
      v6 = (int *)((int (__stdcall *)(int *, int))v5->Realloc_2)(a1: m_pMemory, a2: 128);
      this->m_BlockEndStack.m_Memory.m_pMemory = v6;
      this->m_BlockEndStack.m_pElements = v6;
      return this;
    }
    this->m_BlockEndStack.m_Memory.m_pMemory = (int *)((int (__stdcall *)(int))v5->Alloc_2)(a1: 128);
  }
  this->m_BlockEndStack.m_pElements = this->m_BlockEndStack.m_Memory.m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101FC760
// Name: public: virtual int CRestore::SkipHeader(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::SkipHeader(CRestore *this)
{
  SaveRestoreRecordHeader_t header; // [esp+0h] [ebp-4h] BYREF

  header = (SaveRestoreRecordHeader_t)this;
  this->ReadHeader(this, a2: &header);
  return header.size;
}

//------------------------------------------------------------------------------
// Address: 0x101FC780
// Name: public: virtual int CRestore::ReadAll(void __near *,struct datamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRestore::ReadAll(CRestore *this, void *pLeafObject, datamap_t *pLeafMap)
{
  int result; // eax

  if ( pLeafMap->baseMap == nullptr )
    return this->ReadFields(
             this,
             a2: pLeafMap->dataClassName,
             a3: pLeafObject,
             a4: pLeafMap,
             a5: pLeafMap->dataDesc,
             a6: pLeafMap->dataNumFields);
  result = CRestore::DoReadAll(this, pLeafObject, pLeafMap, pCurMap: pLeafMap->baseMap);
  if ( result != 0 )
    return this->ReadFields(
             this,
             a2: pLeafMap->dataClassName,
             a3: pLeafObject,
             a4: pLeafMap,
             a5: pLeafMap->dataDesc,
             a6: pLeafMap->dataNumFields);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FC7D0
// Name: private: int CEntitySaveRestoreBlockHandler::RestoreGlobalEntity(class CBaseEntity __near *,class CSaveRestoreData __near *,struct entitytable_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEntitySaveRestoreBlockHandler::RestoreGlobalEntity(
        CEntitySaveRestoreBlockHandler *this,
        CBaseEntity *pEntity,
        CSaveRestoreData *pSaveData,
        entitytable_t *pEntInfo)
{
  const char *pszValue; // esi
  const char *v7; // eax
  CSaveRestoreData *Map; // eax
  CBaseEntity *GlobalEntity; // eax
  CBaseEntity *v10; // esi
  int v11; // eax
  Vector *v12; // eax
  float v13; // xmm1_4
  float v14; // xmm2_4
  CBaseEntity *v15; // eax
  const char *v17; // eax
  CRestore restoreHelper; // [esp+0h] [ebp-3Ch] BYREF
  Vector v19; // [esp+28h] [ebp-14h] BYREF
  string_t globalName; // [esp+34h] [ebp-8h]
  CEntitySaveRestoreBlockHandler *v21; // [esp+38h] [ebp-4h]
  const char *className; // [esp+48h] [ebp+Ch]
  int globalIndex; // [esp+4Ch] [ebp+10h]

  v21 = this;
  if ( pEntity != nullptr )
    pEntity->GetRefEHandle(this: pEntity);
  CRestore::CRestore(this: &restoreHelper, pdata: pSaveData);
  pszValue = pEntInfo->globalname.pszValue;
  className = pEntInfo->classname.pszValue;
  globalName.pszValue = pszValue;
  v7 = pszValue;
  if ( pszValue == nullptr )
    v7 = locale;
  globalIndex = GlobalEntity_GetIndex(pGlobalname: v7);
  Map = (CSaveRestoreData *)GlobalEntity_GetMap(globalIndex);
  if ( pSaveData->levelInfo.szCurrentMapName == (char *)Map
    || _V_stricmp(s1: pSaveData->levelInfo.szCurrentMapName, s2: (const char *)Map) == 0 )
  {
    GlobalEntity = CEntitySaveRestoreBlockHandler::FindGlobalEntity(
                     this: v21,
                     classname: (string_t)className,
                     globalname: (string_t)pszValue);
    v10 = GlobalEntity;
    if ( GlobalEntity != nullptr )
    {
      restoreHelper.m_global = 1;
      v11 = GlobalEntity->GetModelIndex(this: GlobalEntity);
      v12 = CEntitySaveRestoreBlockHandler::ModelSpaceLandmark(this: v21, result: &v19, modelIndex: v11);
      v13 = pEntInfo->landmarkModelSpace.y - v12->y;
      v14 = pEntInfo->landmarkModelSpace.z - v12->z;
      pSaveData->modelSpaceOffset.x = pEntInfo->landmarkModelSpace.x - v12->x;
      pSaveData->modelSpaceOffset.y = v13;
      pSaveData->modelSpaceOffset.z = v14;
      UTIL_Remove(oldObj: pEntity);
      pEntInfo->hEnt.m_Index = v10->GetRefEHandle(this: v10)->m_Index;
      v10->VPhysicsDestroyObject(this: v10);
      GlobalEntity_SetMap(globalIndex, mapname: gpGlobals->mapname);
      if ( CEntitySaveRestoreBlockHandler::DoRestoreEntity(this: v21, pEntity: v10, pRestore: &restoreHelper) )
        v15 = v10;
      else
        v15 = nullptr;
      pSaveData->modelSpaceOffset.x = 0.0;
      pSaveData->modelSpaceOffset.y = 0.0;
      pSaveData->modelSpaceOffset.z = 0.0;
      if ( v15 != nullptr )
      {
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&restoreHelper.m_BlockEndStack);
        return 1;
      }
    }
    else
    {
      v17 = globalName.pszValue;
      if ( globalName.pszValue == nullptr )
        v17 = locale;
      DevMsg(a1: "Warning: No match for global entity %s found in destination level\n", v17);
    }
  }
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&restoreHelper.m_BlockEndStack);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FCA50
// Name: public: virtual void CSave::WriteEdictPtr(char const __near *,struct edict_t __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteEdictPtr(CSave *this, const char *pname, edict_t **ppEdict, int count)
{
  int v4; // esi
  int v6; // ecx
  int v7; // eax
  int EntityIndex; // eax
  int v9; // eax
  const CBaseEntity *v10; // eax
  _DWORD v11[1024]; // [esp+Ch] [ebp-1000h] BYREF

  v4 = 0;
  if ( count > 0 )
  {
    v6 = (char *)ppEdict - (char *)v11;
    do
    {
      if ( v4 >= 1024 )
        break;
      v7 = *(_DWORD *)((char *)&v11[v4] + v6);
      if ( v7 != 0 )
      {
        v9 = *(_DWORD *)(v7 + 12);
        v10 = v9 != 0 ? (const CBaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v9 + 20))(a1: v9) : nullptr;
        EntityIndex = CGameSaveRestoreInfo::GetEntityIndex(this: this->m_pGameInfo, pEntity: v10);
        v6 = (char *)ppEdict - (char *)v11;
      }
      else
      {
        EntityIndex = -1;
      }
      v11[v4++] = EntityIndex;
    }
    while ( v4 < count );
  }
  this->WriteInt(this, a2: pname, a3: v11, a4: count);
}

//------------------------------------------------------------------------------
// Address: 0x101FCAF0
// Name: public: virtual void CSave::WriteEdictPtr(struct edict_t __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSave::WriteEdictPtr(CSave *this, edict_t **ppEdict, int count)
{
  int v3; // esi
  int v5; // ecx
  int v6; // eax
  int EntityIndex; // eax
  int v8; // eax
  const CBaseEntity *v9; // eax
  _DWORD v10[1024]; // [esp+Ch] [ebp-1000h] BYREF

  v3 = 0;
  if ( count > 0 )
  {
    v5 = (char *)ppEdict - (char *)v10;
    do
    {
      if ( v3 >= 1024 )
        break;
      v6 = *(_DWORD *)((char *)&v10[v3] + v5);
      if ( v6 != 0 )
      {
        v8 = *(_DWORD *)(v6 + 12);
        v9 = v8 != 0 ? (const CBaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v8 + 20))(a1: v8) : nullptr;
        EntityIndex = CGameSaveRestoreInfo::GetEntityIndex(this: this->m_pGameInfo, pEntity: v9);
        v5 = (char *)ppEdict - (char *)v10;
      }
      else
      {
        EntityIndex = -1;
      }
      v10[v3++] = EntityIndex;
    }
    while ( v3 < count );
  }
  this->WriteInt_2(this, a2: v10, a3: count);
}

//------------------------------------------------------------------------------
// Address: 0x101FCBC0
// Name: public: virtual char const __near * CSaveRestoreBlockSet::GetBlockName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSaveRestoreBlockSet::GetBlockName(CChoreoChannel *this)
{
  return this->m_szName;
}

//------------------------------------------------------------------------------
// Address: 0x101FCBD0
// Name: public: virtual void CSaveRestoreBlockSet::Save(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreBlockSet::Save(CSaveRestoreBlockSet *this, ISave *pSave)
{
  SaveRestoreBlockHeader_t *v4; // esi
  ISaveRestoreBlockHandler *v5; // ecx
  int base; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]
  ISave *pSavea; // [esp+18h] [ebp+8h]

  base = pSave->GetWritePos(this: pSave);
  i = 0;
  if ( this->m_Handlers.m_Size > 0 )
  {
    pSavea = nullptr;
    do
    {
      v4 = (SaveRestoreBlockHeader_t *)((char *)pSavea + (unsigned int)this->m_BlockHeaders.m_Memory.m_pMemory);
      v4->locBody = pSave->GetWritePos(this: pSave) - base;
      v5 = this->m_Handlers.m_Memory.m_pMemory[i];
      v5->Save(this: v5, a2: pSave);
      pSavea += 10;
      ++i;
    }
    while ( i < this->m_Handlers.m_Size );
  }
  this->m_SizeBodies = pSave->GetWritePos(this: pSave) - base;
}

//------------------------------------------------------------------------------
// Address: 0x101FCC50
// Name: public: virtual void CSaveRestoreBlockSet::PreRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreBlockSet::PreRestore(CSaveRestoreBlockSet *this)
{
  int i; // esi
  ISaveRestoreBlockHandler *v3; // ecx

  for ( i = 0; i < this->m_Handlers.m_Size; ++i )
  {
    v3 = this->m_Handlers.m_Memory.m_pMemory[i];
    v3->PreRestore(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FCC80
// Name: public: virtual void CSaveRestoreBlockSet::Restore(class IRestore __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreBlockSet::Restore(CSaveRestoreBlockSet *this, IRestore *pRestore, BOOL fCreatePlayers)
{
  int v5; // edi
  int base; // [esp+14h] [ebp+8h]

  v5 = 0;
  for ( base = pRestore->GetReadPos(this: pRestore); v5 < this->m_Handlers.m_Size; ++v5 )
    this->CallBlockHandlerRestore(
      this,
      a2: this->m_Handlers.m_Memory.m_pMemory[v5],
      a3: base,
      a4: pRestore,
      a5: fCreatePlayers);
  pRestore->SetReadPos(this: pRestore, a2: base + this->m_SizeBodies);
}

//------------------------------------------------------------------------------
// Address: 0x101FCCE0
// Name: private: int CSaveRestoreBlockSet::GetBlockBodyLoc(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestoreBlockSet::GetBlockBodyLoc(CSaveRestoreBlockSet *this, const char *pszName)
{
  int m_Size; // ebx
  int v3; // esi
  const char *i; // edi
  SaveRestoreBlockHeader_t *m_pMemory; // [esp+Ch] [ebp-4h]

  m_Size = this->m_BlockHeaders.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return -1;
  m_pMemory = this->m_BlockHeaders.m_Memory.m_pMemory;
  for ( i = (const char *)m_pMemory; strcmp(i, pszName) != 0; i += 40 )
  {
    if ( ++v3 >= m_Size )
      return -1;
  }
  return m_pMemory[v3].locBody;
}

//------------------------------------------------------------------------------
// Address: 0x101FCD50
// Name: private: int CSaveRestoreBlockSet::GetBlockHeaderLoc(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSaveRestoreBlockSet::GetBlockHeaderLoc(CSaveRestoreBlockSet *this, const char *pszName)
{
  int m_Size; // ebx
  int v3; // esi
  const char *i; // edi
  SaveRestoreBlockHeader_t *m_pMemory; // [esp+Ch] [ebp-4h]

  m_Size = this->m_BlockHeaders.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return -1;
  m_pMemory = this->m_BlockHeaders.m_Memory.m_pMemory;
  for ( i = (const char *)m_pMemory; strcmp(i, pszName) != 0; i += 40 )
  {
    if ( ++v3 >= m_Size )
      return -1;
  }
  return m_pMemory[v3].locHeader;
}

//------------------------------------------------------------------------------
// Address: 0x101FCE80
// Name: public: virtual void CSaveRestoreBlockSet::CallBlockHandlerRestore(class ISaveRestoreBlockHandler __near *,int,class IRestore __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreBlockSet::CallBlockHandlerRestore(
        CSaveRestoreBlockSet *this,
        ISaveRestoreBlockHandler *pHandler,
        int baseFilePos,
        IRestore *pRestore,
        BOOL fCreatePlayers)
{
  const char *v6; // eax
  int BlockBodyLoc; // eax

  v6 = (const char *)pHandler->GetBlockName(this: pHandler);
  BlockBodyLoc = CSaveRestoreBlockSet::GetBlockBodyLoc(this, pszName: v6);
  if ( BlockBodyLoc != -1 )
  {
    pRestore->SetReadPos(this: pRestore, a2: baseFilePos + BlockBodyLoc);
    pHandler->Restore(this: pHandler, a2: pRestore, a3: fCreatePlayers);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FCF50
// Name: public: virtual void CSaveRestoreBlockSet::PostSave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreBlockSet::PostSave(CSaveRestoreBlockSet *this)
{
  int i; // edi
  ISaveRestoreBlockHandler *v3; // ecx
  bool v4; // sf
  SaveRestoreBlockHeader_t *m_pMemory; // ecx

  for ( i = 0; i < this->m_Handlers.m_Size; ++i )
  {
    v3 = this->m_Handlers.m_Memory.m_pMemory[i];
    v3->PostSave(this: v3);
  }
  v4 = this->m_BlockHeaders.m_Memory.m_nGrowSize < 0;
  this->m_BlockHeaders.m_Size = 0;
  if ( v4 )
  {
    this->m_BlockHeaders.m_pElements = this->m_BlockHeaders.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_BlockHeaders.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_BlockHeaders.m_Memory.m_pMemory);
      this->m_BlockHeaders.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_BlockHeaders.m_Memory.m_pMemory;
    this->m_BlockHeaders.m_Memory.m_nAllocationCount = 0;
    this->m_BlockHeaders.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FCFC0
// Name: public: virtual void CSaveRestoreBlockSet::ReadRestoreHeaders(class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreBlockSet::ReadRestoreHeaders(CSaveRestoreBlockSet *this, IRestore *pRestore)
{
  int v4; // eax
  IRestore_vtbl *v5; // edx
  int v6; // ebx
  void (__thiscall *v7)(int *, _DWORD *, IRestore *); // eax
  ISaveRestoreBlockHandler *v8; // ecx
  const char *v9; // eax
  int BlockHeaderLoc; // eax
  ISaveRestoreBlockHandler *v11; // ecx
  _DWORD v12[3]; // [esp+Ch] [ebp-10h] BYREF
  int *p_m_SizeHeaders; // [esp+18h] [ebp-4h]
  int base; // [esp+24h] [ebp+8h]

  v4 = pRestore->GetReadPos(this: pRestore);
  v5 = pRestore->__vftable;
  v6 = 0;
  base = v4;
  p_m_SizeHeaders = &this->m_SizeHeaders;
  v5->ReadInt_2(this: pRestore, a2: &this->m_SizeHeaders, a3: 1, a4: 0);
  pRestore->ReadInt_2(this: pRestore, a2: &this->m_SizeBodies, a3: 1, a4: 0);
  if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::`local static guard' |= 1u;
    `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>,10>::`vftable';
  }
  v12[0] = &this->m_BlockHeaders;
  v7 = *(void (__thiscall **)(int *, _DWORD *, IRestore *))(`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::ops
                                                          + 4);
  v12[1] = 0;
  v12[2] = 0;
  v7(
    a1: &`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::ops,
    a2: v12,
    a3: pRestore);
  if ( this->m_Handlers.m_Size > 0 )
  {
    do
    {
      v8 = this->m_Handlers.m_Memory.m_pMemory[v6];
      v9 = (const char *)v8->GetBlockName(this: v8);
      BlockHeaderLoc = CSaveRestoreBlockSet::GetBlockHeaderLoc(this, pszName: v9);
      if ( BlockHeaderLoc != -1 )
      {
        pRestore->SetReadPos(this: pRestore, a2: base + BlockHeaderLoc);
        v11 = this->m_Handlers.m_Memory.m_pMemory[v6];
        v11->ReadRestoreHeaders(this: v11, a2: pRestore);
      }
      ++v6;
    }
    while ( v6 < this->m_Handlers.m_Size );
  }
  pRestore->SetReadPos(this: pRestore, a2: base + *p_m_SizeHeaders);
}

//------------------------------------------------------------------------------
// Address: 0x101FD0A0
// Name: public: virtual void CSaveRestoreBlockSet::PostRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreBlockSet::PostRestore(CSaveRestoreBlockSet *this)
{
  int i; // edi
  ISaveRestoreBlockHandler *v3; // ecx
  bool v4; // sf
  SaveRestoreBlockHeader_t *m_pMemory; // ecx

  for ( i = 0; i < this->m_Handlers.m_Size; ++i )
  {
    v3 = this->m_Handlers.m_Memory.m_pMemory[i];
    v3->PostRestore(this: v3);
  }
  v4 = this->m_BlockHeaders.m_Memory.m_nGrowSize < 0;
  this->m_BlockHeaders.m_Size = 0;
  if ( v4 )
  {
    this->m_BlockHeaders.m_pElements = this->m_BlockHeaders.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_BlockHeaders.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_BlockHeaders.m_Memory.m_pMemory);
      this->m_BlockHeaders.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_BlockHeaders.m_Memory.m_pMemory;
    this->m_BlockHeaders.m_Memory.m_nAllocationCount = 0;
    this->m_BlockHeaders.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FD110
// Name: public: virtual void CSaveRestoreBlockSet::RemoveBlockHandler(class ISaveRestoreBlockHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreBlockSet::RemoveBlockHandler(
        CSaveRestoreBlockSet *this,
        ISaveRestoreBlockHandler *pHandler)
{
  CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Handlers,
    src: (vgui::TreeNode **)&pHandler);
}

//------------------------------------------------------------------------------
// Address: 0x101FD130
// Name: public: virtual void CSaveRestoreBlockSet::AddBlockHandler(class ISaveRestoreBlockHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreBlockSet::AddBlockHandler(CSaveRestoreBlockSet *this, ISaveRestoreBlockHandler *pHandler)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_Handlers; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  m_nAllocationCount = this->m_Handlers.m_Memory.m_nAllocationCount;
  p_m_Handlers = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Handlers;
  m_Size = this->m_Handlers.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(this: p_m_Handlers, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Handlers[1].m_pMemory;
  m_pMemory = p_m_Handlers->m_pMemory;
  v6 = (int)p_m_Handlers[1].m_pMemory - m_Size - 1;
  p_m_Handlers[1].m_nAllocationCount = (int)p_m_Handlers->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_Handlers->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (vgui::TreeNode *)pHandler;
}

//------------------------------------------------------------------------------
// Address: 0x101FD250
// Name: public: virtual void CSave::StartBlock(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSave::StartBlock(CSave *this@<ecx>, const char *a2@<edi>, const char *pszBlockName)
{
  CSaveRestoreSegment *m_pData; // ecx
  int v5; // eax
  int m_Size; // edi
  int v7; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v10; // eax
  int *v11; // eax
  char pdata[4]; // [esp+Ch] [ebp-4h] BYREF

  m_pData = this->m_pData;
  *(_DWORD *)pdata = 0;
  pszBlockName = (const char *)(unsigned __int16)CSaveRestoreSegment::FindCreateSymbol(
                                                   this: m_pData,
                                                   pszToken: pszBlockName);
  CSave::BufferData(this, a2, pdata, size: 2);
  CSave::BufferData(this, a2, pdata: (char *)&pszBlockName, size: 2);
  v5 = this->GetWritePos(this);
  m_Size = this->m_BlockStartStack.m_Size;
  v7 = v5;
  m_nAllocationCount = this->m_BlockStartStack.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_BlockStartStack,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_BlockStartStack.m_Size;
  m_pMemory = this->m_BlockStartStack.m_Memory.m_pMemory;
  v10 = this->m_BlockStartStack.m_Size - m_Size - 1;
  this->m_BlockStartStack.m_pElements = m_pMemory;
  if ( v10 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
  v11 = &this->m_BlockStartStack.m_Memory.m_pMemory[m_Size];
  if ( v11 != nullptr )
    *v11 = v7;
}

//------------------------------------------------------------------------------
// Address: 0x101FD2F0
// Name: public: virtual void CRestore::StartBlock(struct SaveRestoreRecordHeader_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRestore::StartBlock(CRestore *this, SaveRestoreRecordHeader_t *pHeader)
{
  int v3; // ebx
  int m_Size; // edi
  int v5; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v8; // eax
  int *v9; // edi

  this->ReadHeader(this, a2: pHeader);
  v3 = this->GetReadPos(this);
  m_Size = this->m_BlockEndStack.m_Size;
  v5 = pHeader->size + v3;
  m_nAllocationCount = this->m_BlockEndStack.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_BlockEndStack,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_BlockEndStack.m_Size;
  m_pMemory = this->m_BlockEndStack.m_Memory.m_pMemory;
  v8 = this->m_BlockEndStack.m_Size - m_Size - 1;
  this->m_BlockEndStack.m_pElements = m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
  v9 = &this->m_BlockEndStack.m_Memory.m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = v5;
}

//------------------------------------------------------------------------------
// Address: 0x101FD3F0
// Name: public: virtual void CSaveRestoreBlockSet::PreSave(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreBlockSet::PreSave(CSaveRestoreBlockSet *this, CSaveRestoreData *pData)
{
  int v3; // esi
  CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int> > *p_m_BlockHeaders; // ecx
  ISaveRestoreBlockHandler *v5; // ecx
  SaveRestoreBlockHeader_t *v6; // edi
  const char *v7; // eax
  ISaveRestoreBlockHandler *v8; // ecx
  int m_Size; // [esp-4h] [ebp-10h]
  int v10; // [esp+8h] [ebp-4h]

  v3 = 0;
  m_Size = this->m_Handlers.m_Size;
  p_m_BlockHeaders = &this->m_BlockHeaders;
  p_m_BlockHeaders->m_Size = 0;
  CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>::InsertMultipleBefore(
    this: p_m_BlockHeaders,
    elem: 0,
    num: m_Size);
  if ( this->m_Handlers.m_Size > 0 )
  {
    v10 = 0;
    do
    {
      v5 = this->m_Handlers.m_Memory.m_pMemory[v3];
      v6 = &this->m_BlockHeaders.m_Memory.m_pMemory[v10];
      v7 = (const char *)v5->GetBlockName(this: v5);
      V_strncpy(pDest: v6->szName, pSrc: v7, maxLen: 32);
      v8 = this->m_Handlers.m_Memory.m_pMemory[v3];
      v8->PreSave(this: v8, a2: pData);
      ++v10;
      ++v3;
    }
    while ( v3 < this->m_Handlers.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FD460
// Name: public: virtual void CSaveRestoreBlockSet::WriteSaveHeaders(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveRestoreBlockSet::WriteSaveHeaders(CSaveRestoreBlockSet *this, ISave *pSave)
{
  void (__thiscall *v4)(int *, CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int> > **, ISave *); // eax
  SaveRestoreBlockHeader_t *v5; // ebx
  int v6; // eax
  int v7; // ebx
  ISaveRestoreBlockHandler *v8; // ecx
  int v9; // eax
  void (__thiscall *v10)(int *, CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int> > **, ISave *); // eax
  SaveRestoreBlockHeader_t *m_pMemory; // eax
  int m_Size; // [esp-4h] [ebp-3Ch]
  CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int> > dummyArr; // [esp+Ch] [ebp-2Ch] BYREF
  CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int> > *p_dummyArr; // [esp+20h] [ebp-18h] BYREF
  int v15; // [esp+24h] [ebp-14h]
  int v16; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]
  int dummyInt; // [esp+30h] [ebp-8h] BYREF
  int base; // [esp+34h] [ebp-4h]
  int savedPos; // [esp+40h] [ebp+8h]
  int savedPosa; // [esp+40h] [ebp+8h]

  base = pSave->GetWritePos(this: pSave);
  m_Size = this->m_BlockHeaders.m_Size;
  dummyInt = -1;
  memset(&dummyArr, 0, sizeof(dummyArr));
  CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>::InsertMultipleBefore(
    this: &dummyArr,
    elem: 0,
    num: m_Size);
  memset(dst: (int)dummyArr.m_Memory.m_pMemory->szName, value: (unsigned __int8 *)0xFF, count: 40 * dummyArr.m_Size);
  pSave->WriteInt_2(this: pSave, a2: &dummyInt, a3: 1);
  pSave->WriteInt_2(this: pSave, a2: &dummyInt, a3: 1);
  if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::`local static guard' |= 1u;
    `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>,10>::`vftable';
  }
  p_dummyArr = &dummyArr;
  v4 = *(void (__thiscall **)(int *, CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int> > **, ISave *))`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::ops;
  v15 = 0;
  v16 = 0;
  v4(
    a1: &`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::ops,
    a2: &p_dummyArr,
    a3: pSave);
  i = 0;
  if ( this->m_Handlers.m_Size > 0 )
  {
    savedPos = 0;
    do
    {
      v5 = &this->m_BlockHeaders.m_Memory.m_pMemory[savedPos];
      v6 = pSave->GetWritePos(this: pSave);
      v5->locHeader = v6 - base;
      v7 = i;
      v8 = this->m_Handlers.m_Memory.m_pMemory[i];
      v8->WriteSaveHeaders(this: v8, a2: pSave);
      ++savedPos;
      i = v7 + 1;
    }
    while ( v7 + 1 < this->m_Handlers.m_Size );
  }
  v9 = pSave->GetWritePos(this: pSave);
  this->m_SizeHeaders = v9 - base;
  savedPosa = pSave->GetWritePos(this: pSave);
  pSave->SetWritePos(this: pSave, a2: base);
  pSave->WriteInt_2(this: pSave, a2: &this->m_SizeHeaders, a3: 1);
  pSave->WriteInt_2(this: pSave, a2: &this->m_SizeBodies, a3: 1);
  if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::`local static guard' |= 1u;
    `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>,10>::`vftable';
  }
  v10 = *(void (__thiscall **)(int *, CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int> > **, ISave *))`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::ops;
  p_dummyArr = &this->m_BlockHeaders;
  v15 = 0;
  v16 = 0;
  v10(
    a1: &`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<SaveRestoreBlockHeader_t,CUtlMemory<SaveRestoreBlockHeader_t,int>>>'::`2'::ops,
    a2: &p_dummyArr,
    a3: pSave);
  pSave->SetWritePos(this: pSave, a2: savedPosa);
  m_pMemory = dummyArr.m_Memory.m_pMemory;
  dummyArr.m_Size = 0;
  if ( dummyArr.m_Memory.m_nGrowSize >= 0 )
  {
    if ( dummyArr.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dummyArr.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      dummyArr.m_Memory.m_pMemory = nullptr;
    }
    dummyArr.m_Memory.m_nAllocationCount = 0;
  }
  dummyArr.m_pElements = m_pMemory;
  if ( dummyArr.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101FD6B0
// Name: int CreateEntityTransitionList(class CSaveRestoreData __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CreateEntityTransitionList(CSaveRestoreData *pSaveData, int levelMask)
{
  CSaveRestoreData *v2; // ebx
  CBaseEntity *m_pEntity; // edi
  entitytable_t *v4; // esi
  unsigned int m_Index; // eax
  int location; // eax
  char *v7; // ecx
  int flags; // eax
  const char *pszValue; // eax
  unsigned int v10; // eax
  IHandleEntity *v11; // ecx
  signed int v12; // eax
  unsigned int v13; // esi
  unsigned int v14; // esi
  edict_t *m_pPev; // eax
  signed int v16; // eax
  const char *v17; // ecx
  int m_Size; // eax
  int v19; // esi
  int *m_pMemory; // edi
  int v21; // eax
  int *v22; // eax
  int v23; // edx
  entitytable_t *v24; // esi
  unsigned int v25; // eax
  CBaseEntity **v26; // ecx
  CBaseEntity *v27; // edi
  IMDLCache *v28; // ebx
  const char *v29; // eax
  signed int v30; // eax
  CRestore restoreHelper; // [esp+Ch] [ebp-48h] BYREF
  CUtlVector<int,CUtlMemory<int,int> > checkList; // [esp+34h] [ebp-20h] BYREF
  unsigned int v34; // [esp+48h] [ebp-Ch]
  int i; // [esp+4Ch] [ebp-8h]
  int movedCount; // [esp+50h] [ebp-4h]

  v2 = pSaveData;
  CreateEntitiesInTransitionList(pSaveData, levelMask);
  m_pEntity = nullptr;
  memset(&checkList, 0, sizeof(checkList));
  movedCount = 0;
  i = 0;
  if ( pSaveData->tableCount > 0 )
  {
    v34 = 0;
    do
    {
      v4 = &pSaveData->pTable[v34 / 0x38];
      m_Index = v4->hEnt.m_Index;
      if ( m_Index != -1 )
      {
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
          m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
        else
          m_pEntity = nullptr;
      }
      location = v4->location;
      if ( location >= 0 && location < pSaveData->bufferSize )
      {
        v7 = &pSaveData->pBaseData[location];
        pSaveData->size = location;
        pSaveData->pCurrentData = v7;
      }
      pSaveData->modelSpaceOffset.x = 0.0;
      pSaveData->modelSpaceOffset.y = 0.0;
      pSaveData->modelSpaceOffset.z = 0.0;
      if ( m_pEntity != nullptr )
      {
        flags = v4->flags;
        if ( (flags & levelMask) != 0 )
        {
          if ( (flags & 0x10000000) != 0 )
          {
            pszValue = v4->classname.pszValue;
            if ( pszValue == nullptr )
              pszValue = locale;
            _DevMsg(a1: 2, a2: "Merging changes for global: %s\n", pszValue);
            if ( CEntitySaveRestoreBlockHandler::RestoreGlobalEntity(
                   this: &g_EntitySaveRestoreBlockHandler,
                   pEntity: m_pEntity,
                   pSaveData,
                   pEntInfo: v4) <= 0 )
            {
              v14 = v4->hEnt.m_Index;
              if ( v14 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_SerialNumber != HIWORD(v14) )
                UTIL_RemoveImmediate(oldObj: nullptr);
              else
                UTIL_RemoveImmediate(oldObj: (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_pEntity);
            }
            else
            {
              v10 = v4->hEnt.m_Index;
              ++movedCount;
              if ( v10 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
                v11 = nullptr;
              else
                v11 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
              v12 = (signed int)v11[6].__vftable;
              if ( v12 != 0 )
                v12 = (signed int)(v12 - (unsigned int)gpGlobals->pEdicts) >> 4;
              v4->restoreentityindex = v12;
              v13 = v4->hEnt.m_Index;
              if ( v13 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13) )
                AddRestoredEntity(pEntity: nullptr);
              else
                AddRestoredEntity(pEntity: (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity);
            }
          }
          else
          {
            m_pPev = m_pEntity->m_Network.m_pPev;
            if ( m_pPev != nullptr )
              v16 = m_pPev - gpGlobals->pEdicts;
            else
              v16 = -1;
            v17 = v4->classname.pszValue;
            if ( v17 == nullptr )
              v17 = locale;
            _DevMsg(a1: 2, a2: "Transferring %s (%d)\n", v17, v16);
            CRestore::CRestore(this: &restoreHelper, pdata: pSaveData);
            if ( CEntitySaveRestoreBlockHandler::RestoreEntity(
                   this: &g_EntitySaveRestoreBlockHandler,
                   pEntity: m_pEntity,
                   pRestore: &restoreHelper,
                   pEntInfo: v4) >= 0 )
            {
              m_Size = checkList.m_Size;
              v19 = checkList.m_Size;
              if ( checkList.m_Size + 1 > checkList.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<CNavLadder *,int>::Grow(
                  this: (CUtlMemory<vgui::TreeNode *,int> *)&checkList,
                  num: checkList.m_Size - checkList.m_Memory.m_nAllocationCount + 1);
                m_Size = checkList.m_Size;
              }
              m_pMemory = checkList.m_Memory.m_pMemory;
              checkList.m_Size = m_Size + 1;
              v21 = m_Size - v19;
              checkList.m_pElements = checkList.m_Memory.m_pMemory;
              if ( v21 > 0 )
                _V_memmove(
                  dest: &checkList.m_Memory.m_pMemory[v19 + 1],
                  src: &checkList.m_Memory.m_pMemory[v19],
                  count: 4 * v21);
              v22 = &m_pMemory[v19];
              if ( v22 != nullptr )
                *v22 = i;
            }
            else
            {
              UTIL_RemoveImmediate(oldObj: m_pEntity);
            }
            CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&restoreHelper.m_BlockEndStack);
          }
          CGlobalEntityList::CleanupDeleteList(this: &gEntList);
        }
      }
      v34 += 56;
      m_pEntity = nullptr;
      ++i;
    }
    while ( i < pSaveData->tableCount );
  }
  v23 = checkList.m_Size - 1;
  for ( i = checkList.m_Size - 1; v23 >= 0; i = v23 )
  {
    v24 = &v2->pTable[checkList.m_Memory.m_pMemory[v23]];
    v25 = v24->hEnt.m_Index;
    if ( v25 != -1 )
    {
      v26 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)v25];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v25].m_SerialNumber == HIWORD(v25) )
      {
        v27 = *v26;
        if ( *v26 != nullptr )
        {
          v28 = mdlcache;
          mdlcache->BeginLock(this: mdlcache);
          if ( v24->flags >= 0 && UTIL_EntityInSolid(ent: v27) != 0 )
          {
            v29 = v24->classname.pszValue;
            if ( v29 == nullptr )
              v29 = locale;
            _DevMsg(a1: 2, a2: "Suppressing %s\n", v29);
            UTIL_RemoveImmediate(oldObj: v27);
            CGlobalEntityList::CleanupDeleteList(this: &gEntList);
          }
          else
          {
            ++movedCount;
            v24->flags = 0x40000000;
            v30 = (signed int)v27->m_Network.m_pPev;
            if ( v30 != 0 )
              v30 = (signed int)(v30 - (unsigned int)gpGlobals->pEdicts) >> 4;
            v24->restoreentityindex = v30;
            AddRestoredEntity(pEntity: v27);
          }
          v28->EndLock(this: v28);
          v23 = i;
          v2 = pSaveData;
        }
      }
    }
    --v23;
  }
  if ( checkList.m_Memory.m_nGrowSize >= 0 && checkList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: checkList.m_Memory.m_pMemory);
  return movedCount;
}

//------------------------------------------------------------------------------
// Address: 0x101FDA70
// Name: public: void CGameSaveRestoreInfo::BuildEntityHash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameSaveRestoreInfo::BuildEntityHash(CGameSaveRestoreInfo *this)
{
  CGameSaveRestoreInfo *v1; // esi
  CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs> *p_m_EntityToIndex; // ebx
  int v3; // edx
  int v4; // eax
  unsigned int v5; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v7; // eax
  int v8; // edx
  int v9; // edx
  int m_Size; // ecx
  CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *v11; // esi
  int v12; // eax
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v15; // edi
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *v16; // ecx
  int v17; // eax
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *v18; // eax
  int v19; // [esp-8h] [ebp-2Ch] BYREF
  IHandleEntity *pKey; // [esp+Ch] [ebp-18h] BYREF
  int v21; // [esp+10h] [ebp-14h]
  int nEntities; // [esp+14h] [ebp-10h]
  CGameSaveRestoreInfo *v23; // [esp+18h] [ebp-Ch]
  int v24; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]

  v1 = this;
  p_m_EntityToIndex = &this->m_EntityToIndex;
  v23 = this;
  if ( this != (CGameSaveRestoreInfo *)-1388 )
  {
    nEntities = (int)&v19;
    CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>::CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>(
      this: (CUtlHash<EntsByStringList_t,CEntsByStringHashFuncs,CEntsByStringHashFuncs> *)&this->m_EntityToIndex,
      bucketCount: 1024,
      growCount: 0,
      initCount: 0,
      compareFunc: (CEntsByStringHashFuncs)this,
      keyFunc: (CEntsByStringHashFuncs)this);
  }
  v3 = 0;
  nEntities = v1->tableCount;
  i = 0;
  if ( nEntities > 0 )
  {
    v4 = 0;
    v24 = 0;
    while ( 1 )
    {
      v5 = *(unsigned int *)((char *)&v1->pTable->hEnt.m_Index + v4);
      if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
      pKey = m_pEntity;
      v21 = v3;
      v7 = Hash4(&pKey);
      if ( p_m_EntityToIndex->m_bPowerOfTwo )
        v8 = v7 & p_m_EntityToIndex->m_ModMask;
      else
        v8 = v7 % p_m_EntityToIndex->m_Buckets.m_Size;
      v9 = v8;
      m_Size = p_m_EntityToIndex->m_Buckets.m_Memory.m_pMemory[v9].m_Size;
      v11 = (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)&p_m_EntityToIndex->m_Buckets.m_Memory.m_pMemory[v9];
      v12 = 0;
      if ( m_Size > 0 )
      {
        m_pMemory = v11->m_pMemory;
        do
        {
          if ( *(IHandleEntity **)m_pMemory == pKey )
            break;
          ++v12;
          ++m_pMemory;
        }
        while ( v12 < m_Size );
      }
      if ( v12 == m_Size )
      {
        m_nAllocationCount = v11->m_nAllocationCount;
        v15 = m_Size;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
            this: v11,
            num: m_Size - m_nAllocationCount + 1);
        ++v11[1].m_pMemory;
        v16 = v11->m_pMemory;
        v17 = (int)v11[1].m_pMemory - v15 - 1;
        v11[1].m_nAllocationCount = (int)v11->m_pMemory;
        if ( v17 > 0 )
          _V_memmove(dest: &v16[v15 + 1], src: &v16[v15], count: 8 * v17);
        v18 = &v11->m_pMemory[v15];
        if ( v18 != nullptr )
        {
          *(_DWORD *)v18 = pKey;
          v18->m_pData = (vgui::BuildGroup *)v21;
        }
      }
      v3 = i + 1;
      v4 = v24 + 56;
      i = v3;
      v24 += 56;
      if ( v3 >= nEntities )
        break;
      v1 = v23;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FDBC0
// Name: private: bool CEntitySaveRestoreBlockHandler::SaveInitEntities(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEntitySaveRestoreBlockHandler::SaveInitEntities(
        CEntitySaveRestoreBlockHandler *this,
        CSaveRestoreData *pSaveData)
{
  int v2; // edi
  entitytable_t *v3; // eax
  int v4; // ebx
  CSaveRestoreData *v6; // esi
  CBaseEntity *Ent; // edi
  entitytable_t *v8; // esi
  signed int m_pPev; // eax
  unsigned int m_Index; // ecx
  char v11[4]; // [esp+8h] [ebp-8h] BYREF
  unsigned int v12; // [esp+Ch] [ebp-4h]

  v2 = CGlobalEntityList::NumberOfEntities(this: &gEntList);
  v3 = (entitytable_t *)engine->SaveAllocMemory(this: engine, a2: 56 * v2, a3: 1);
  v4 = 0;
  if ( v3 == nullptr )
    return false;
  v6 = pSaveData;
  CGameSaveRestoreInfo::InitEntityTable(this: &pSaveData->CGameSaveRestoreInfo, pNewTable: v3, size: v2);
  Ent = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
  if ( Ent != nullptr )
  {
    v12 = 0;
    do
    {
      v8 = &v6->pTable[v12 / 0x38];
      v8->id = v4;
      v8->edictindex = Ent->RequiredEdictIndex(this: Ent);
      v8->modelname.pszValue = *(const char **)((int (__thiscall *)(CBaseEntity *, char *))Ent->GetModelName)(
                                                 a1: Ent,
                                                 a2: v11);
      v8->restoreentityindex = -1;
      m_pPev = (signed int)Ent->m_Network.m_pPev;
      if ( m_pPev != 0 )
        m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
      v8->saveentityindex = m_pPev;
      m_Index = Ent->GetRefEHandle(this: Ent)->m_Index;
      v12 += 56;
      v8->hEnt.m_Index = m_Index;
      v8->flags = 0;
      v8->location = 0;
      v8->size = 0;
      v8->classname.pszValue = nullptr;
      ++v4;
      v6 = pSaveData;
      Ent = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: Ent);
    }
    while ( Ent != nullptr );
  }
  CGameSaveRestoreInfo::BuildEntityHash(this: &v6->CGameSaveRestoreInfo);
  return v4 == v6->tableCount;
}

//------------------------------------------------------------------------------
// Address: 0x101FDCD0
// Name: public: CSaveRestoreData::CSaveRestoreData(void)
// Source: json
//------------------------------------------------------------------------------
CSaveRestoreData *__thiscall CSaveRestoreData::CSaveRestoreData(CSaveRestoreData *this)
{
  CGameSaveRestoreInfo *v2; // esi
  CEntsByStringHashFuncs v4; // [esp-8h] [ebp-18h] BYREF
  CEntsByStringHashFuncs v5; // [esp-4h] [ebp-14h]
  CEntsByStringHashFuncs *v6; // [esp+Ch] [ebp-4h]

  v5 = (CEntsByStringHashFuncs)this;
  v4 = (CEntsByStringHashFuncs)this;
  v6 = &v4;
  *(_QWORD *)&this->pBaseData = 0;
  *(_QWORD *)&this->size = 0;
  v2 = &this->CGameSaveRestoreInfo;
  *(_QWORD *)&this->tokenCount = 0;
  this->m_nEntityDataSize = 0;
  this->tableCount = 0;
  this->pTable = nullptr;
  this->m_pCurrentEntity = nullptr;
  CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>::CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>(
    this: (CUtlHash<EntsByStringList_t,CEntsByStringHashFuncs,CEntsByStringHashFuncs> *)&this->m_EntityToIndex,
    bucketCount: 0,
    growCount: 0,
    initCount: 0,
    compareFunc: v4,
    keyFunc: v5);
  memset(dst: (int)v2, value: nullptr, count: 0x550u);
  v2->modelSpaceOffset.x = 0.0;
  v2->modelSpaceOffset.y = 0.0;
  v2->modelSpaceOffset.z = 0.0;
  this->bAsync = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101FDD60
// Name: public: virtual void CEntitySaveRestoreBlockHandler::PreSave(class CSaveRestoreData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntitySaveRestoreBlockHandler::PreSave(
        CEntitySaveRestoreBlockHandler *this,
        CSaveRestoreData *pSaveData)
{
  IMDLCache *v2; // edi
  CBaseEntity *i; // esi

  v2 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  IGameSystem::OnSaveAllSystems();
  this->m_EntitySaveUtils.m_pLevelAdjacencyDependencyHash = physics->CreateObjectPairHash(this: physics);
  for ( i = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
        i != nullptr;
        i = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: i) )
  {
    i->OnSave(this: i, a2: &this->m_EntitySaveUtils);
  }
  CEntitySaveRestoreBlockHandler::SaveInitEntities(this, pSaveData);
  v2->EndLock(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x101FDDE0
// Name: class CSaveRestoreData __near * SaveInit(int)
// Source: json
//------------------------------------------------------------------------------
CSaveRestoreData *__cdecl SaveInit(int size)
{
  int v1; // edi
  int v2; // eax
  CSaveRestoreData *v3; // eax
  CSaveRestoreData *v4; // esi
  char **v5; // eax

  v1 = size;
  if ( size <= 0 )
    v1 = 3145728;
  v2 = CGlobalEntityList::NumberOfEntities(this: &gEntList);
  v3 = (CSaveRestoreData *)engine->SaveAllocMemory(this: engine, a2: v1 + 56 * v2 + 1444, a3: 1);
  if ( v3 == nullptr )
    return nullptr;
  v4 = CSaveRestoreData::CSaveRestoreData(this: v3);
  v4->pBaseData = (char *)&v4[1];
  v4->pCurrentData = (char *)&v4[1];
  v4->size = 0;
  v4->bufferSize = v1;
  v5 = (char **)engine->SaveAllocMemory(this: engine, a2: 4095, a3: 4);
  if ( v5 == nullptr )
  {
    engine->SaveFreeMemory(this: engine, a2: nullptr);
    return nullptr;
  }
  v4->tokenCount = 4095;
  v4->pTokens = v5;
  memset(dst: (int)v5, value: nullptr, count: 0x3FFCu);
  v4->levelInfo.time = gpGlobals->curtime;
  v4->levelInfo.vecLandmarkOffset = vec3_origin;
  v4->levelInfo.fUseLandmark = 0;
  v4->levelInfo.connectionCount = 0;
  gpGlobals->pSaveData = v4;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10323220
// Name: public: CUtlHash<struct CGameSaveRestoreInfo::CHashElement,class CGameSaveRestoreInfo::CHashFuncs,class CGameSaveRestoreInfo::CHashFuncs>::CUtlHash<struct CGameSaveRestoreInfo::CHashElement,class CGameSaveRestoreInfo::CHashFuncs,class CGameSaveRestoreInfo::CHashFuncs>(int,int,int,class CGameSaveRestoreInfo::CHashFuncs,class CGameSaveRestoreInfo::CHashFuncs)
// Source: json
//------------------------------------------------------------------------------
CUtlHash<EntsByStringList_t,CEntsByStringHashFuncs,CEntsByStringHashFuncs> *__thiscall CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>::CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs>(
        CUtlHash<EntsByStringList_t,CEntsByStringHashFuncs,CEntsByStringHashFuncs> *this,
        int bucketCount,
        int growCount,
        int initCount,
        CEntsByStringHashFuncs compareFunc,
        CEntsByStringHashFuncs keyFunc)
{
  int v6; // esi
  int v8; // eax
  CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *v9; // esi
  int m_nAllocationCount; // eax
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *m_pMemory; // ecx
  int v12; // eax
  bool v13; // zf
  int v15; // [esp+Ch] [ebp-8h]
  int v16; // [esp+10h] [ebp-4h]

  v6 = bucketCount;
  this->m_Buckets.m_Memory.m_pMemory = nullptr;
  this->m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_Buckets.m_Size = 0;
  this->m_Buckets.m_pElements = nullptr;
  if ( bucketCount >= 0x10000 )
  {
    bucketCount = 0x10000;
    v6 = 0x10000;
  }
  CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll((CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)this);
  CUtlVector<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<touchlink_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<touchlink_t>::HashEntry,int>>,int>>::InsertMultipleBefore(
    (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)this,
    elem: this->m_Buckets.m_Size,
    num: v6);
  if ( v6 > 0 )
  {
    v8 = 0;
    v16 = 0;
    v15 = v6;
    do
    {
      v9 = (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)((char *)this->m_Buckets.m_Memory.m_pMemory
                                                                               + v8);
      v9[1].m_pMemory = nullptr;
      if ( initCount != 0 )
      {
        m_nAllocationCount = v9->m_nAllocationCount;
        if ( initCount > m_nAllocationCount )
          CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
            this: v9,
            num: initCount - m_nAllocationCount);
        v9[1].m_pMemory = (CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *)((char *)v9[1].m_pMemory + initCount);
        m_pMemory = v9->m_pMemory;
        v12 = (int)v9[1].m_pMemory - initCount;
        v9[1].m_nAllocationCount = (int)v9->m_pMemory;
        if ( v12 > 0 && initCount > 0 )
          _V_memmove(dest: &m_pMemory[initCount], src: m_pMemory, count: 8 * v12);
      }
      this->m_Buckets.m_Memory.m_pMemory[v16].m_Memory.m_nGrowSize = growCount;
      v8 = v16 * 20 + 20;
      v13 = v15-- == 1;
      ++v16;
    }
    while ( !v13 );
    v6 = bucketCount;
  }
  this->m_bPowerOfTwo = ((v6 - 1) & v6) == 0;
  this->m_ModMask = ((v6 - 1) & v6) == 0 ? v6 - 1 : 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104096D0
// Name: entitytable_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *entitytable_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<entitytable_t>();
  entitytable_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104096E0
// Name: SaveRestoreBlockHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *SaveRestoreBlockHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<SaveRestoreBlockHeader_t>();
  SaveRestoreBlockHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104096F0
// Name: _dynamic_initializer_for__g_SaveRestoreBlockSet__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SaveRestoreBlockSet__()
{
  V_strncpy(pDest: g_SaveRestoreBlockSet.m_Name, pSrc: "Game", maxLen: 32);
  return atexit(func: dynamic_atexit_destructor_for__g_SaveRestoreBlockSet__);
}

} // namespace server
