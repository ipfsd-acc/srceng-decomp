// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/cmaterialvar.cpp
// Functions: 73
// ============================================================

#include "materialsystem\cmaterialvar.h"

//------------------------------------------------------------------------------
// Address: 0x10019500
// Name: int ParseVectorFromKeyValueString(class KeyValues __near *,char const __near *,float __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ParseVectorFromKeyValueString(KeyValues *pKeyValue, const char *pMaterialName, float *vecVal)
{
  const char *String; // esi
  char *v4; // esi
  int v5; // edi
  char v6; // al
  const char *Name; // eax
  const char *v9; // eax
  char *pEnd; // [esp+Ch] [ebp-8h] BYREF
  bool divideBy255; // [esp+13h] [ebp-1h]

  String = KeyValues::GetString(this: pKeyValue, keyName: nullptr, defaultValue: (const char *)&pMem);
  divideBy255 = false;
  while ( *String == 32 || *String == 9 )
    ++String;
  if ( *String == 123 )
    divideBy255 = true;
  v4 = (char *)(String + 1);
  v5 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v6 = *v4;
      if ( *v4 != 32 && v6 != 9 )
        break;
      ++v4;
    }
    if ( v6 == 10 || v6 == 0 )
      break;
    if ( v6 == 93 )
      goto LABEL_22;
    if ( v6 == 125 )
      break;
    vecVal[v5] = strtod(nptr: v4, endptr: &pEnd);
    if ( v4 == pEnd )
    {
      Name = KeyValues::GetName(this: pKeyValue);
      _Warning(a1: "Error in .VMT file: error parsing vector element \"%s\" in \"%s\"\n", Name, pMaterialName);
      return 0;
    }
    ++v5;
    v4 = pEnd;
    if ( v5 >= 4 )
      goto LABEL_23;
  }
  if ( *v4 != 93 && *v4 != 125 )
  {
    v9 = KeyValues::GetName(this: pKeyValue);
    _Warning(
      a1: "Warning in .VMT file (%s): no ']' or '}' found in vector key \"%s\".\n"
      "Did you forget to surround the vector with \"s?\n",
      pMaterialName,
      v9);
  }
LABEL_22:
  vecVal[v5] = 0.0;
LABEL_23:
  if ( divideBy255 )
  {
    *vecVal = *vecVal * 0.0039215689;
    vecVal[1] = vecVal[1] * 0.0039215689;
    vecVal[2] = vecVal[2] * 0.0039215689;
    vecVal[3] = vecVal[3] * 0.0039215689;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10031AE0
// Name: public: class CUtlSymbol CUtlSymbolTableMT::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbol *__thiscall CUtlSymbolTableMT::Find(CUtlSymbolTableMT *this, CUtlSymbol *result, const char *pString)
{
  if ( (this->m_lock.m_lockInfo.m_i32 & 0x10000) != 0
    || _InterlockedCompareExchange((volatile signed __int32 *)&this->m_lock, 0x10000, 0) != 0 )
  {
    CThreadSpinRWLock::SpinLockForWrite(this: &this->m_lock);
  }
  else
  {
    this->m_lock.m_writerId = GetCurrentThreadId();
  }
  CUtlSymbolTable::Find(this, result, pString);
  this->m_lock.m_writerId = 0;
  this->m_lock.m_lockInfo.m_i32 = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10031B40
// Name: public: char const __near * CUtlSymbolTableMT::String(class CUtlSymbol)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUtlSymbolTableMT::String(CUtlSymbolTableMT *this, CUtlSymbol id)
{
  CThreadSpinRWLock *p_m_lock; // esi
  signed __int32 m_i32; // ecx
  const char *result; // eax

  p_m_lock = &this->m_lock;
  if ( (this->m_lock.m_lockInfo.m_i32 & 0x10000) != 0
    || (m_i32 = (unsigned __int16)p_m_lock->m_lockInfo.m_i32,
        _InterlockedCompareExchange((volatile signed __int32 *)p_m_lock, m_i32 + 1, m_i32) != m_i32) )
  {
    CThreadSpinRWLock::SpinLockForRead(this: p_m_lock);
  }
  result = CUtlSymbolTable::String(this, id);
  _InterlockedExchangeAdd((volatile signed __int32 *)p_m_lock, 0xFFFFFFFF);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10031BA0
// Name: public: bool VMatrix::IsIdentity(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall VMatrix::IsIdentity(VMatrix *this)
{
  return this->m[0][0] == 1.0
      && this->m[0][1] == 0.0
      && this->m[0][2] == 0.0
      && this->m[0][3] == 0.0
      && this->m[1][0] == 0.0
      && this->m[1][1] == 1.0
      && this->m[1][2] == 0.0
      && this->m[1][3] == 0.0
      && this->m[2][0] == 0.0
      && this->m[2][1] == 0.0
      && this->m[2][2] == 1.0
      && this->m[2][3] == 0.0
      && this->m[3][0] == 0.0
      && this->m[3][1] == 0.0
      && this->m[3][2] == 0.0
      && this->m[3][3] == 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10031CB0
// Name: public: static void CMaterialVar::operator delete(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMaterialVar::operator delete(void *p)
{
  CUtlMemoryPool::Free(this: &CMaterialVar::s_Allocator, memBlock: p);
}

//------------------------------------------------------------------------------
// Address: 0x10031CD0
// Name: public: static void IMaterialVar::DeleteUnreferencedTextures(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IMaterialVar::DeleteUnreferencedTextures(bool enable)
{
  g_bDeleteUnreferencedTexturesEnabled = enable;
}

//------------------------------------------------------------------------------
// Address: 0x10031CE0
// Name: public: static void IMaterialVar::Destroy(class IMaterialVar __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IMaterialVar::Destroy(IMaterialVar *pVar)
{
  if ( pVar != nullptr )
    ((void (__thiscall *)(IMaterialVar *, int))pVar->__vftable[1].IsTextureValueInternalEnvCubemap)(a1: pVar, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10031D00
// Name: public: static unsigned short IMaterialVar::GetSymbol(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __cdecl IMaterialVar::GetSymbol(const char *pName)
{
  char temp[1024]; // [esp+0h] [ebp-400h] BYREF

  if ( pName == nullptr )
    return -1;
  V_strncpy(pDest: temp, pSrc: pName, maxLen: 1024);
  _V_strlower(start: temp);
  if ( (s_MaterialVarSymbols.m_lock.m_lockInfo.m_i32 & 0x10000) != 0
    || _InterlockedCompareExchange((volatile signed __int32 *)&s_MaterialVarSymbols.m_lock, 0x10000, 0) != 0 )
  {
    CThreadSpinRWLock::SpinLockForWrite(this: &s_MaterialVarSymbols.m_lock);
  }
  else
  {
    s_MaterialVarSymbols.m_lock.m_writerId = GetCurrentThreadId();
  }
  CUtlSymbolTable::AddString(this: &s_MaterialVarSymbols, result: (CUtlSymbol *)&pName + 1, pString: temp);
  s_MaterialVarSymbols.m_lock.m_writerId = 0;
  s_MaterialVarSymbols.m_lock.m_lockInfo.m_i32 = 0;
  return HIWORD(pName);
}

//------------------------------------------------------------------------------
// Address: 0x10031DB0
// Name: public: static unsigned short IMaterialVar::FindSymbol(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __cdecl IMaterialVar::FindSymbol(const char *pName)
{
  if ( pName != nullptr )
    return CUtlSymbolTableMT::Find(this: &s_MaterialVarSymbols, result: (CUtlSymbol *)&pName + 1, pString: pName)->m_Id;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10031DE0
// Name: public: static bool IMaterialVar::SymbolMatches(char const __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IMaterialVar::SymbolMatches(const char *pName, unsigned __int16 symbol)
{
  int m_nReaders; // ecx
  const char *v3; // eax

  if ( (s_MaterialVarSymbols.m_lock.m_lockInfo.m_i32 & 0x10000) != 0
    || (m_nReaders = s_MaterialVarSymbols.m_lock.m_lockInfo.m_nReaders,
        _InterlockedCompareExchange(
          (volatile signed __int32 *)&s_MaterialVarSymbols.m_lock,
          s_MaterialVarSymbols.m_lock.m_lockInfo.m_nReaders + 1,
          s_MaterialVarSymbols.m_lock.m_lockInfo.m_nReaders) != m_nReaders) )
  {
    CThreadSpinRWLock::SpinLockForRead(this: &s_MaterialVarSymbols.m_lock);
  }
  v3 = CUtlSymbolTable::String(this: &s_MaterialVarSymbols, id: (CUtlSymbol)symbol);
  _InterlockedExchangeAdd((volatile signed __int32 *)&s_MaterialVarSymbols.m_lock, 0xFFFFFFFF);
  return _V_stricmp(s1: v3, s2: pName) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10031E50
// Name: public: CMaterialVar::CMaterialVar(class IMaterial __near *,char const __near *,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
CMaterialVar *__thiscall CMaterialVar::CMaterialVar(
        CMaterialVar *this,
        IMaterialInternal *pMaterial,
        const char *pKey,
        const VMatrix *matrix)
{
  char v5; // cl
  char v6; // dl
  IMaterialInternal *v7; // eax

  this->m_Name.m_Id = -1;
  v5 = *((_BYTE *)&this->IMaterialVar + 28) & 0xCF;
  this->__vftable = (CMaterialVar_vtbl *)&CMaterialVar::`vftable';
  *((_BYTE *)&this->IMaterialVar + 28) = v5 | 0x40;
  this->m_VecVal.x = 0.0;
  this->m_VecVal.y = 0.0;
  this->m_VecVal.z = 0.0;
  this->m_VecVal.w = 0.0;
  v6 = *((_BYTE *)&this->IMaterialVar + 28) & 0x70;
  this->m_pStringVal = nullptr;
  this->m_intVal = 0;
  this->m_nTempIndex = -1;
  *((_BYTE *)&this->IMaterialVar + 28) = v6 | 4;
  this->m_pMaterial = pMaterial;
  this->m_Name.m_Id = IMaterialVar::GetSymbol(pName: pKey);
  *((_BYTE *)&this->IMaterialVar + 28) = *((_BYTE *)&this->IMaterialVar + 28) & 0xF0 | 7;
  v7 = (IMaterialInternal *)MemAlloc_Alloc(nSize: 0x41u);
  this->m_pMaterialValue = v7;
  MatrixCopy(src: matrix, dst: (VMatrix *)v7);
  LOBYTE(this->m_pMaterialValue[16].__vftable) = VMatrix::IsIdentity(this: matrix);
  this->m_intVal = 0;
  this->m_VecVal.x = 0.0;
  this->m_VecVal.y = 0.0;
  this->m_VecVal.z = 0.0;
  this->m_VecVal.w = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10031F20
// Name: public: CMaterialVar::CMaterialVar(class IMaterial __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMaterialVar *__thiscall CMaterialVar::CMaterialVar(
        CMaterialVar *this,
        IMaterialInternal *pMaterial,
        const char *pKey,
        const char *pVal)
{
  char v5; // cl
  char v6; // dl
  int v7; // edi
  char *v8; // eax
  long double v9; // st7
  char *m_pStringVal; // [esp-28h] [ebp-28h]

  this->m_Name.m_Id = -1;
  v5 = *((_BYTE *)&this->IMaterialVar + 28) & 0xCF;
  this->__vftable = (CMaterialVar_vtbl *)&CMaterialVar::`vftable';
  *((_BYTE *)&this->IMaterialVar + 28) = v5 | 0x40;
  this->m_VecVal.x = 0.0;
  this->m_VecVal.y = 0.0;
  this->m_VecVal.z = 0.0;
  this->m_VecVal.w = 0.0;
  v6 = *((_BYTE *)&this->IMaterialVar + 28) & 0x70;
  this->m_pStringVal = nullptr;
  this->m_intVal = 0;
  this->m_nTempIndex = -1;
  *((_BYTE *)&this->IMaterialVar + 28) = v6 | 4;
  this->m_pMaterial = pMaterial;
  this->m_Name.m_Id = IMaterialVar::GetSymbol(pName: pKey);
  v7 = _V_strlen(str: pVal) + 1;
  v8 = (char *)MemAlloc_Alloc(nSize: v7);
  this->m_pStringVal = v8;
  V_strncpy(pDest: v8, pSrc: pVal, maxLen: v7);
  m_pStringVal = this->m_pStringVal;
  *((_BYTE *)&this->IMaterialVar + 28) = *((_BYTE *)&this->IMaterialVar + 28) & 0xF0 | 1;
  v9 = atof(nptr: m_pStringVal);
  this->m_VecVal.w = v9;
  this->m_VecVal.z = v9;
  this->m_VecVal.y = v9;
  this->m_VecVal.x = v9;
  this->m_intVal = (int)atof(nptr: this->m_pStringVal);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10031FF0
// Name: public: CMaterialVar::CMaterialVar(class IMaterial __near *,char const __near *,float __near *,int)
// Source: json
//------------------------------------------------------------------------------
CMaterialVar *__thiscall CMaterialVar::CMaterialVar(
        CMaterialVar *this,
        IMaterialInternal *pMaterial,
        const char *pKey,
        float *pVal,
        int numComps)
{
  char v6; // cl
  char v7; // dl
  int x; // edx

  this->m_Name.m_Id = -1;
  v6 = *((_BYTE *)&this->IMaterialVar + 28) & 0xCF;
  this->__vftable = (CMaterialVar_vtbl *)&CMaterialVar::`vftable';
  *((_BYTE *)&this->IMaterialVar + 28) = v6 | 0x40;
  this->m_VecVal.x = 0.0;
  this->m_VecVal.y = 0.0;
  this->m_VecVal.z = 0.0;
  this->m_VecVal.w = 0.0;
  v7 = *((_BYTE *)&this->IMaterialVar + 28);
  this->m_pStringVal = nullptr;
  this->m_intVal = 0;
  this->m_nTempIndex = -1;
  *((_BYTE *)&this->IMaterialVar + 28) = v7 & 0x70 | 4;
  this->m_pMaterial = pMaterial;
  this->m_Name.m_Id = IMaterialVar::GetSymbol(pName: pKey);
  *((_BYTE *)&this->IMaterialVar + 28) = *((_BYTE *)&this->IMaterialVar + 28) & 0xF0 | 2;
  memcpy(dst: (unsigned __int8 *)&this->m_VecVal, src: (unsigned __int8 *)pVal, count: 4 * numComps);
  if ( numComps < 4 )
    memset(&this->m_VecVal.x + numComps, 0, 4 * (4 - numComps));
  x = (int)this->m_VecVal.x;
  *((_BYTE *)&this->IMaterialVar + 28) ^= (*((_BYTE *)&this->IMaterialVar + 28) ^ (16 * numComps)) & 0x70;
  this->m_intVal = x;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100320B0
// Name: public: CMaterialVar::CMaterialVar(class IMaterial __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
CMaterialVar *__thiscall CMaterialVar::CMaterialVar(
        CMaterialVar *this,
        IMaterialInternal *pMaterial,
        const char *pKey,
        float val)
{
  char v5; // cl
  char v6; // dl

  this->m_Name.m_Id = -1;
  v5 = *((_BYTE *)&this->IMaterialVar + 28) & 0xCF;
  this->__vftable = (CMaterialVar_vtbl *)&CMaterialVar::`vftable';
  *((_BYTE *)&this->IMaterialVar + 28) = v5 | 0x40;
  this->m_VecVal.x = 0.0;
  this->m_VecVal.y = 0.0;
  this->m_VecVal.z = 0.0;
  this->m_VecVal.w = 0.0;
  v6 = *((_BYTE *)&this->IMaterialVar + 28) & 0x70;
  this->m_pStringVal = nullptr;
  this->m_intVal = 0;
  this->m_nTempIndex = -1;
  *((_BYTE *)&this->IMaterialVar + 28) = v6 | 4;
  this->m_pMaterial = pMaterial;
  this->m_Name.m_Id = IMaterialVar::GetSymbol(pName: pKey);
  *((_BYTE *)&this->IMaterialVar + 28) &= 0xF0u;
  this->m_VecVal.w = val;
  this->m_VecVal.z = val;
  this->m_VecVal.y = val;
  this->m_VecVal.x = val;
  this->m_intVal = (int)val;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10032150
// Name: public: CMaterialVar::CMaterialVar(class IMaterial __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CMaterialVar *__thiscall CMaterialVar::CMaterialVar(
        CMaterialVar *this,
        IMaterialInternal *pMaterial,
        const char *pKey,
        int val)
{
  char v5; // cl
  char v6; // dl

  this->m_Name.m_Id = -1;
  v5 = *((_BYTE *)&this->IMaterialVar + 28) & 0xCF;
  this->__vftable = (CMaterialVar_vtbl *)&CMaterialVar::`vftable';
  *((_BYTE *)&this->IMaterialVar + 28) = v5 | 0x40;
  this->m_VecVal.x = 0.0;
  this->m_VecVal.y = 0.0;
  this->m_VecVal.z = 0.0;
  this->m_VecVal.w = 0.0;
  v6 = *((_BYTE *)&this->IMaterialVar + 28) & 0x70;
  this->m_pStringVal = nullptr;
  this->m_intVal = 0;
  this->m_nTempIndex = -1;
  *((_BYTE *)&this->IMaterialVar + 28) = v6 | 4;
  this->m_pMaterial = pMaterial;
  this->m_Name.m_Id = IMaterialVar::GetSymbol(pName: pKey);
  *((_BYTE *)&this->IMaterialVar + 28) = *((_BYTE *)&this->IMaterialVar + 28) & 0xF0 | 4;
  this->m_VecVal.w = (float)val;
  this->m_VecVal.z = (float)val;
  this->m_VecVal.y = (float)val;
  this->m_VecVal.x = (float)val;
  this->m_intVal = val;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100321F0
// Name: public: CMaterialVar::CMaterialVar(class IMaterial __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMaterialVar *__thiscall CMaterialVar::CMaterialVar(CMaterialVar *this, IMaterialInternal *pMaterial, const char *pKey)
{
  char v4; // cl
  char v5; // dl

  this->m_Name.m_Id = -1;
  v4 = *((_BYTE *)&this->IMaterialVar + 28) & 0xCF;
  this->__vftable = (CMaterialVar_vtbl *)&CMaterialVar::`vftable';
  *((_BYTE *)&this->IMaterialVar + 28) = v4 | 0x40;
  this->m_VecVal.x = 0.0;
  this->m_VecVal.y = 0.0;
  this->m_VecVal.z = 0.0;
  this->m_VecVal.w = 0.0;
  v5 = *((_BYTE *)&this->IMaterialVar + 28) & 0x70;
  this->m_pStringVal = nullptr;
  this->m_intVal = 0;
  this->m_nTempIndex = -1;
  *((_BYTE *)&this->IMaterialVar + 28) = v5 | 4;
  this->m_pMaterial = pMaterial;
  this->m_Name.m_Id = IMaterialVar::GetSymbol(pName: pKey);
  *((_BYTE *)&this->IMaterialVar + 28) = *((_BYTE *)&this->IMaterialVar + 28) & 0xF0 | 6;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10032270
// Name: private: void CMaterialVar::CleanUpData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialVar::CleanUpData(CMaterialVar *this)
{
  switch ( *((_BYTE *)&this->IMaterialVar + 28) & 0xF )
  {
    case 1:
      free(pMem: this->m_pStringVal);
      break;
    case 3:
      if ( this->m_pMaterialValue != (IMaterialInternal *)-1 )
      {
        ((void (__thiscall *)(IMaterialInternal *))this->m_pMaterialValue->FindVar)(a1: this->m_pMaterialValue);
        if ( g_bDeleteUnreferencedTexturesEnabled )
          ((void (__thiscall *)(IMaterialInternal *))this->m_pMaterialValue->NeedsFullFrameBufferTexture)(a1: this->m_pMaterialValue);
      }
      break;
    case 5:
    case 7:
      free(pMem: this->m_pMaterialValue);
      break;
    case 8:
      if ( this->m_pMaterialValue != nullptr )
        this->m_pMaterialValue->DecrementReferenceCount(this: this->m_pMaterialValue);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032310
// Name: public: virtual unsigned short CMaterialVar::GetNameAsSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CMaterialVar::GetNameAsSymbol(CMaterialVar *this)
{
  return this->m_Name.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x10032320
// Name: public: virtual char const __near * CMaterialVar::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMaterialVar::GetName(CMaterialVar *this)
{
  const char *result; // eax
  int m_nReaders; // ecx
  unsigned __int16 m_Id; // [esp+6h] [ebp-2h]

  if ( this->m_Name.m_Id == 0xFFFF )
  {
    _Warning(a1: "m_pName is NULL for CMaterialVar\n");
    return (const char *)&pMem;
  }
  else
  {
    m_Id = this->m_Name.m_Id;
    if ( (s_MaterialVarSymbols.m_lock.m_lockInfo.m_i32 & 0x10000) != 0
      || (m_nReaders = s_MaterialVarSymbols.m_lock.m_lockInfo.m_nReaders,
          _InterlockedCompareExchange(
            (volatile signed __int32 *)&s_MaterialVarSymbols.m_lock,
            s_MaterialVarSymbols.m_lock.m_lockInfo.m_nReaders + 1,
            s_MaterialVarSymbols.m_lock.m_lockInfo.m_nReaders) != m_nReaders) )
    {
      CThreadSpinRWLock::SpinLockForRead(this: &s_MaterialVarSymbols.m_lock);
    }
    result = CUtlSymbolTable::String(this: &s_MaterialVarSymbols, id: (CUtlSymbol)m_Id);
    _InterlockedExchangeAdd((volatile signed __int32 *)&s_MaterialVarSymbols.m_lock, 0xFFFFFFFF);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100323B0
// Name: public: virtual int CMaterialVar::GetIntValueInternal(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialVar::GetIntValueInternal(CMaterialVar *this)
{
  unsigned __int8 m_nTempIndex; // al

  for ( ;
        g_pInternalMaterialSystem->GetRenderCallQueue(this: g_pInternalMaterialSystem) != nullptr;
        this = &s_pTempMaterialVar[m_nTempIndex] )
  {
    if ( *((char *)&this->IMaterialVar + 28) < 0 )
      break;
    m_nTempIndex = this->m_nTempIndex;
    if ( m_nTempIndex == 0xFF )
      break;
  }
  return this->m_intVal;
}

//------------------------------------------------------------------------------
// Address: 0x10032400
// Name: public: virtual float CMaterialVar::GetFloatValueInternal(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CMaterialVar::GetFloatValueInternal(CMaterialVar *this)
{
  unsigned __int8 m_nTempIndex; // al

  for ( ;
        g_pInternalMaterialSystem->GetRenderCallQueue(this: g_pInternalMaterialSystem) != nullptr;
        this = &s_pTempMaterialVar[m_nTempIndex] )
  {
    if ( *((char *)&this->IMaterialVar + 28) < 0 )
      break;
    m_nTempIndex = this->m_nTempIndex;
    if ( m_nTempIndex == 0xFF )
      break;
  }
  return this->m_VecVal.x;
}

//------------------------------------------------------------------------------
// Address: 0x10032450
// Name: public: virtual float const __near * CMaterialVar::GetVecValueInternal(void)const
// Source: json
//------------------------------------------------------------------------------
Vector4D *__thiscall CMaterialVar::GetVecValueInternal(CMaterialVar *this)
{
  unsigned __int8 m_nTempIndex; // al

  for ( ;
        g_pInternalMaterialSystem->GetRenderCallQueue(this: g_pInternalMaterialSystem) != nullptr;
        this = &s_pTempMaterialVar[m_nTempIndex] )
  {
    if ( *((char *)&this->IMaterialVar + 28) < 0 )
      break;
    m_nTempIndex = this->m_nTempIndex;
    if ( m_nTempIndex == 0xFF )
      break;
  }
  return &this->m_VecVal;
}

//------------------------------------------------------------------------------
// Address: 0x100324A0
// Name: public: virtual void CMaterialVar::GetVecValueInternal(float __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialVar::GetVecValueInternal(CMaterialVar *this, float *val, int numcomps)
{
  unsigned __int8 m_nTempIndex; // al
  int v5; // esi
  float *v6; // ecx
  unsigned int v7; // edx
  float *p_y; // eax
  double v9; // st7
  float *v10; // eax

  for ( ;
        g_pInternalMaterialSystem->GetRenderCallQueue(this: g_pInternalMaterialSystem) != nullptr;
        this = &s_pTempMaterialVar[m_nTempIndex] )
  {
    if ( (*((_BYTE *)&this->IMaterialVar + 28) & 0x80) != 0 )
      break;
    m_nTempIndex = this->m_nTempIndex;
    if ( m_nTempIndex == 0xFF )
      break;
  }
  v5 = 0;
  if ( numcomps >= 4 )
  {
    v6 = val + 2;
    v7 = ((unsigned int)(numcomps - 4) >> 2) + 1;
    p_y = &this->m_VecVal.y;
    v5 = 4 * v7;
    do
    {
      v9 = *(p_y - 1);
      p_y += 4;
      *(v6 - 2) = v9;
      v6 += 4;
      --v7;
      *(v6 - 5) = *(p_y - 4);
      *(v6 - 4) = *(p_y - 3);
      *(v6 - 3) = *(p_y - 2);
    }
    while ( v7 != 0 );
  }
  if ( v5 < numcomps )
  {
    v10 = &this->m_VecVal.x + v5;
    do
      val[v5++] = *v10++;
    while ( v5 < numcomps );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032560
// Name: public: virtual int CMaterialVar::VectorSizeInternal(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMaterialVar::VectorSizeInternal(CMaterialVar *this)
{
  unsigned __int8 m_nTempIndex; // al

  for ( ;
        g_pInternalMaterialSystem->GetRenderCallQueue(this: g_pInternalMaterialSystem) != nullptr;
        this = &s_pTempMaterialVar[m_nTempIndex] )
  {
    if ( *((char *)&this->IMaterialVar + 28) < 0 )
      break;
    m_nTempIndex = this->m_nTempIndex;
    if ( m_nTempIndex == 0xFF )
      break;
  }
  return (*((unsigned __int8 *)&this->IMaterialVar + 28) >> 4) & 7;
}

//------------------------------------------------------------------------------
// Address: 0x100325C0
// Name: public: virtual char const __near * CMaterialVar::GetStringValue(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMaterialVar::GetStringValue(CMaterialVar *this)
{
  unsigned __int8 m_nTempIndex; // al
  char *result; // eax
  unsigned int v4; // edi
  int v5; // ecx
  unsigned int v6; // esi
  int j; // edi
  int v8; // eax
  const char *v9; // [esp+4h] [ebp-18h]
  int i; // [esp+14h] [ebp-8h]
  int ia; // [esp+14h] [ebp-8h]
  Vector4D *p_m_VecVal; // [esp+18h] [ebp-4h]

  for ( ;
        g_pInternalMaterialSystem->GetRenderCallQueue(this: g_pInternalMaterialSystem) != nullptr;
        this = &s_pTempMaterialVar[m_nTempIndex] )
  {
    if ( *((char *)&this->IMaterialVar + 28) < 0 )
      break;
    m_nTempIndex = this->m_nTempIndex;
    if ( m_nTempIndex == 0xFF )
      break;
  }
  switch ( *((_BYTE *)&this->IMaterialVar + 28) & 0xF )
  {
    case 0:
      V_snprintf(pDest: CMaterialVar::s_CharBuf, maxLen: 512, pFormat: "%f", this->m_VecVal.x);
      result = CMaterialVar::s_CharBuf;
      break;
    case 1:
      result = this->m_pStringVal;
      break;
    case 2:
      *(_WORD *)CMaterialVar::s_CharBuf = 8283;
      v4 = 2;
      i = 0;
      if ( (*((_BYTE *)&this->IMaterialVar + 28) & 0x70) != 0 )
      {
        p_m_VecVal = &this->m_VecVal;
        do
        {
          if ( v4 < 0x200 )
          {
            V_snprintf(pDest: &CMaterialVar::s_CharBuf[v4], maxLen: 512 - v4, pFormat: "%f ", p_m_VecVal->x);
            v4 += strlen(&CMaterialVar::s_CharBuf[v4]);
          }
          p_m_VecVal = (Vector4D *)((char *)p_m_VecVal + 4);
          ++i;
        }
        while ( i < ((*((unsigned __int8 *)&this->IMaterialVar + 28) >> 4) & 7) );
        if ( v4 >= 0x1FF )
          goto LABEL_17;
      }
      CMaterialVar::s_CharBuf[v4] = 93;
      CMaterialVar::s_CharBuf[v4 + 1] = 0;
      result = CMaterialVar::s_CharBuf;
      break;
    case 3:
      if ( this->m_pMaterialValue != (IMaterialInternal *)-1 )
        goto $LN5_4;
      result = "env_cubemap";
      break;
    case 4:
      V_snprintf(pDest: CMaterialVar::s_CharBuf, maxLen: 512, pFormat: "%d", this->m_intVal);
      goto LABEL_8;
    case 6:
      result = "<UNDEFINED>";
      break;
    case 7:
      v5 = 0;
      *(_WORD *)CMaterialVar::s_CharBuf = 8283;
      v6 = 2;
      ia = 0;
      do
      {
        for ( j = 0; j < 16; j += 4 )
        {
          if ( v6 < 0x200 )
          {
            v8 = V_snprintf(
                   pDest: &CMaterialVar::s_CharBuf[v6],
                   maxLen: 512 - v6,
                   pFormat: "%.3f ",
                   *(float *)((char *)&this->m_pMaterialValue[j].__vftable + v5));
            v5 = ia;
            v6 += v8;
          }
        }
        v5 += 4;
        ia = v5;
      }
      while ( v5 < 16 );
      if ( v6 >= 0x1FF )
      {
LABEL_17:
        byte_10346567 = 0;
        result = CMaterialVar::s_CharBuf;
      }
      else
      {
        CMaterialVar::s_CharBuf[v6] = 93;
        CMaterialVar::s_CharBuf[v6 + 1] = 0;
        result = CMaterialVar::s_CharBuf;
      }
      break;
    case 8:
$LN5_4:
      v9 = this->m_pMaterialValue->GetName(this: this->m_pMaterialValue);
      V_snprintf(pDest: CMaterialVar::s_CharBuf, maxLen: 512, pFormat: "%s", v9);
LABEL_8:
      result = CMaterialVar::s_CharBuf;
      break;
    default:
      _Warning(a1: "CMaterialVar::GetStringValue: Unknown material var type\n");
      result = (char *)&pMem;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10032850
// Name: public: virtual void CMaterialVar::GetFourCCValue(unsigned long __near *,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialVar::GetFourCCValue(CMaterialVar *this, unsigned int *type, void **ppData)
{
  unsigned __int8 m_nTempIndex; // al
  bool v5; // cc
  const char *v6; // eax
  int v7; // [esp-4h] [ebp-8h]

  for ( ;
        g_pInternalMaterialSystem->GetRenderCallQueue(this: g_pInternalMaterialSystem) != nullptr;
        this = &s_pTempMaterialVar[m_nTempIndex] )
  {
    if ( *((char *)&this->IMaterialVar + 28) < 0 )
      break;
    m_nTempIndex = this->m_nTempIndex;
    if ( m_nTempIndex == 0xFF )
      break;
  }
  if ( (*((_BYTE *)&this->IMaterialVar + 28) & 0xF) == 5 )
  {
    *type = (unsigned int)this->m_pMaterialValue->$54E03890B2F65888F9B0BC4F208FAB89::__vftable;
    *ppData = this->m_pMaterialValue[1].__vftable;
  }
  else
  {
    v5 = bitchCount < 10;
    *type = 1313558101;
    *ppData = nullptr;
    if ( v5 )
    {
      v6 = (const char *)((int (__thiscall *)(CMaterialVar *, int))this->GetName)(
                           a1: this,
                           a2: *((_BYTE *)&this->IMaterialVar + 28) & 0xF);
      _Warning(a1: "CMaterialVar::GetVecValue: trying to get a vec value for %s which is of type %d\n", v6, v7);
      ++bitchCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032910
// Name: public: virtual bool CMaterialVar::IsTextureValueInternalEnvCubemap(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialVar::IsTextureValueInternalEnvCubemap(CMaterialVar *this)
{
  unsigned __int8 m_nTempIndex; // al

  for ( ;
        g_pInternalMaterialSystem->GetRenderCallQueue(this: g_pInternalMaterialSystem) != nullptr;
        this = &s_pTempMaterialVar[m_nTempIndex] )
  {
    if ( *((char *)&this->IMaterialVar + 28) < 0 )
      break;
    m_nTempIndex = this->m_nTempIndex;
    if ( m_nTempIndex == 0xFF )
      break;
  }
  if ( this->m_pMaterial != nullptr )
    this->m_pMaterial->Precache(this: this->m_pMaterial);
  return (*((_BYTE *)&this->IMaterialVar + 28) & 0xF) == 3 && this->m_pMaterialValue == (IMaterialInternal *)-1;
}

//------------------------------------------------------------------------------
// Address: 0x10032980
// Name: public: virtual class ITexture __near * CMaterialVar::GetTextureValue(void)
// Source: json
//------------------------------------------------------------------------------
ITextureInternal *__thiscall CMaterialVar::GetTextureValue(CMaterialVar *this)
{
  unsigned __int8 m_nTempIndex; // al
  ITextureInternal *result; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // [esp-4h] [ebp-8h]

  for ( ;
        g_pInternalMaterialSystem->GetRenderCallQueue(this: g_pInternalMaterialSystem) != nullptr;
        this = &s_pTempMaterialVar[m_nTempIndex] )
  {
    if ( *((char *)&this->IMaterialVar + 28) < 0 )
      break;
    m_nTempIndex = this->m_nTempIndex;
    if ( m_nTempIndex == 0xFF )
      break;
  }
  if ( this->m_pMaterial != nullptr )
    this->m_pMaterial->Precache(this: this->m_pMaterial);
  if ( (*((_BYTE *)&this->IMaterialVar + 28) & 0xF) != 3 )
  {
    if ( bitchCount_0 < 10 )
    {
      if ( this->m_pMaterial != nullptr )
        v4 = this->m_pMaterial->GetName(this: this->m_pMaterial);
      else
        v4 = "NULL material";
      v5 = (const char *)((int (__thiscall *)(CMaterialVar *, const char *))this->GetName)(a1: this, a2: v4);
      _Warning(a1: "Requesting texture value from var \"%s\" which is not a texture value (material: %s)\n", v5, v6);
      ++bitchCount_0;
    }
    return g_pTextureManager->ErrorTexture(this: g_pTextureManager);
  }
  result = this->m_pTexture;
  if ( result == (ITextureInternal *)-1 )
    result = (ITextureInternal *)g_pInternalMaterialSystem->GetLocalCubemap(this: g_pInternalMaterialSystem);
  if ( result == nullptr )
  {
    if ( bitchCount_1 < 10 )
    {
      _Warning(a1: "Invalid texture value in CMaterialVar::GetTextureValue\n");
      ++bitchCount_1;
    }
    return g_pTextureManager->ErrorTexture(this: g_pTextureManager);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10032A70
// Name: public: virtual class IMaterial __near * CMaterialVar::GetMaterialValue(void)
// Source: json
//------------------------------------------------------------------------------
IMaterialInternal *__thiscall CMaterialVar::GetMaterialValue(CMaterialVar *this)
{
  unsigned __int8 m_nTempIndex; // al
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // [esp-4h] [ebp-Ch]

  for ( ;
        g_pInternalMaterialSystem->GetRenderCallQueue(this: g_pInternalMaterialSystem) != nullptr;
        this = &s_pTempMaterialVar[m_nTempIndex] )
  {
    if ( *((char *)&this->IMaterialVar + 28) < 0 )
      break;
    m_nTempIndex = this->m_nTempIndex;
    if ( m_nTempIndex == 0xFF )
      break;
  }
  if ( this->m_pMaterial != nullptr )
    this->m_pMaterial->Precache(this: this->m_pMaterial);
  if ( (*((_BYTE *)&this->IMaterialVar + 28) & 0xF) == 8 )
    return this->m_pMaterialValue;
  if ( bitchCount_2 < 10 )
  {
    if ( this->m_pMaterial != nullptr )
      v4 = this->m_pMaterial->GetName(this: this->m_pMaterial);
    else
      v4 = "NULL material";
    v5 = (const char *)((int (__thiscall *)(CMaterialVar *, const char *))this->GetName)(a1: this, a2: v4);
    _Warning(a1: "Requesting material value from var \"%s\" which is not a material value (material: %s)\n", v5, v6);
    ++bitchCount_2;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10032B20
// Name: public: virtual void CMaterialVar::GetLinearVecValue(float __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialVar::GetLinearVecValue(CMaterialVar *this, float *pVal, int numComps)
{
  unsigned __int8 m_nTempIndex; // al
  int v5; // esi
  Vector4D *p_m_VecVal; // edi
  int j; // esi
  int i; // esi
  const char *v9; // eax
  int gamma; // [esp+0h] [ebp-10h]

  for ( ;
        g_pInternalMaterialSystem->GetRenderCallQueue(this: g_pInternalMaterialSystem) != nullptr;
        this = &s_pTempMaterialVar[m_nTempIndex] )
  {
    if ( (*((_BYTE *)&this->IMaterialVar + 28) & 0x80) != 0 )
      break;
    m_nTempIndex = this->m_nTempIndex;
    if ( m_nTempIndex == 0xFF )
      break;
  }
  switch ( *((_BYTE *)&this->IMaterialVar + 28) & 0xF )
  {
    case 0:
      for ( i = 0; i < numComps; ++i )
        pVal[i] = GammaToLinear(gamma: this->m_VecVal.x);
      break;
    case 2:
      v5 = 0;
      if ( numComps > 0 )
      {
        p_m_VecVal = &this->m_VecVal;
        do
        {
          pVal[v5++] = GammaToLinear(gamma: p_m_VecVal->x);
          p_m_VecVal = (Vector4D *)((char *)p_m_VecVal + 4);
        }
        while ( v5 < numComps );
      }
      break;
    case 4:
      for ( j = 0; j < numComps; ++j )
        pVal[j] = GammaToLinear(gamma: (float)this->m_intVal);
      break;
    case 6:
    case 7:
      if ( numComps > 0 )
        memset(pVal, 0, 4 * numComps);
      break;
    default:
      v9 = (const char *)((int (__thiscall *)(CMaterialVar *, int))this->GetName)(
                           a1: this,
                           a2: *((_BYTE *)&this->IMaterialVar + 28) & 0xF);
      _Warning(a1: "CMaterialVar::GetVecValue: trying to get a vec value for %s which is of type %d\n", v9, gamma);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032C80
// Name: public: virtual bool CMaterialVar::MatrixIsIdentity(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMaterialVar::MatrixIsIdentity(CMaterialVar *this)
{
  if ( (*((_BYTE *)&this->IMaterialVar + 28) & 0xF) == 7 )
    return (char)this->m_pMaterialValue[16].__vftable;
  else
    return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10032CA0
// Name: public: virtual bool CMaterialVar::IsDefined(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaterialVar::IsDefined(CMaterialVar *this)
{
  return (*((_BYTE *)&this->IMaterialVar + 28) & 0xF) != 6;
}

//------------------------------------------------------------------------------
// Address: 0x10032CB0
// Name: private: void CMaterialVar::RecordToolMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMaterialVar::RecordToolMessage(CMaterialVar *this@<ecx>, int a2@<ebx>)
{
  KeyValues *v3; // edi
  IClientMaterialSystem *v4; // ebx
  KeyValues *v5; // eax
  IMaterialInternal *m_pMaterial; // ecx
  const char *(__thiscall *GetName)(struct IMaterialInternal *); // edx
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  int v11; // eax
  const char *v12; // eax
  float *v13; // ebx
  int v14; // eax
  int v15; // eax
  const char *v16; // eax
  float *v17; // eax
  const char *v18; // eax
  char *v20; // [esp+80h] [ebp-224h]
  char pDest[256]; // [esp+8Ch] [ebp-218h] BYREF
  char str[256]; // [esp+18Ch] [ebp-118h] BYREF
  void *pMem; // [esp+28Ch] [ebp-18h]
  unsigned int hEntity; // [esp+290h] [ebp-14h]
  IClientMaterialSystem *pClientMaterialSystem; // [esp+294h] [ebp-10h]
  int v26; // [esp+2A0h] [ebp-4h]

  v3 = nullptr;
  if ( this->m_pMaterial != nullptr )
  {
    v4 = g_pInternalMaterialSystem->GetClientMaterialSystemInterface(this: g_pInternalMaterialSystem);
    pClientMaterialSystem = v4;
    if ( v4 != nullptr )
    {
      hEntity = v4->GetCurrentRecordingEntity(this: v4);
      if ( hEntity != 0 )
      {
        v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        pMem = v5;
        v26 = 0;
        if ( v5 != nullptr )
          v3 = KeyValues::KeyValues(this: v5, setName: "material_proxy_state");
        m_pMaterial = this->m_pMaterial;
        GetName = m_pMaterial->GetName;
        v26 = -1;
        v8 = GetName(this: m_pMaterial);
        KeyValues::SetString(this: v3, keyName: "mtlName", value: v8);
        v9 = this->m_pMaterial->GetTextureGroupName(this: this->m_pMaterial);
        KeyValues::SetString(this: v3, keyName: "groupName", value: v9);
        switch ( *((_BYTE *)&this->IMaterialVar + 28) & 0xF )
        {
          case 0:
            *(float *)&pClientMaterialSystem = this->GetFloatValueInternal(this);
            v10 = (const char *)((int (__thiscall *)(CMaterialVar *, IClientMaterialSystem *))this->GetName)(
                                  a1: this,
                                  a2: pClientMaterialSystem);
            KeyValues::SetFloat(this: v3, keyName: v10, value: *(float *)&a2);
            goto LABEL_20;
          case 1:
            v20 = (char *)((int (__thiscall *)(CMaterialVar *, int))this->GetStringValue)(a1: this, a2);
            goto LABEL_19;
          case 2:
            v13 = (float *)((int (__thiscall *)(CMaterialVar *, int))this->GetVecValueInternal_2)(a1: this, a2);
            v14 = this->VectorSizeInternal(this) - 2;
            if ( v14 != 0 )
            {
              v15 = v14 - 1;
              if ( v15 != 0 )
              {
                if ( v15 == 1 )
                  V_snprintf(pDest: str, maxLen: 256, pFormat: "vector4d: %f %f %f %f", *v13, v13[1], v13[2], v13[3]);
                else
                  str[0] = 0;
              }
              else
              {
                V_snprintf(pDest: str, maxLen: 256, pFormat: "vector3d: %f %f %f", *v13, v13[1], v13[2]);
              }
            }
            else
            {
              V_snprintf(pDest: str, maxLen: 256, pFormat: "vector2d: %f %f", *v13, v13[1]);
            }
            v16 = this->GetName(this);
            KeyValues::SetString(this: v3, keyName: v16, value: str);
            v4 = pClientMaterialSystem;
            goto LABEL_20;
          case 4:
            v11 = this->GetIntValueInternal(this);
            v12 = (const char *)((int (__thiscall *)(CMaterialVar *, int))this->GetName)(a1: this, a2: v11);
            KeyValues::SetInt(this: v3, keyName: v12, value: a2);
            goto LABEL_20;
          case 7:
            v17 = (float *)((int (__thiscall *)(CMaterialVar *, int))this->GetMatrixValue)(a1: this, a2);
            V_snprintf(
              pDest,
              maxLen: 256,
              pFormat: "matrix: %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f",
              *v17,
              v17[1],
              v17[2],
              v17[3],
              v17[4],
              v17[5],
              v17[6],
              v17[7],
              v17[8],
              v17[9],
              v17[10],
              v17[11],
              v17[12],
              v17[13],
              v17[14],
              v17[15]);
            v20 = pDest;
LABEL_19:
            v18 = this->GetName(this);
            KeyValues::SetString(this: v3, keyName: v18, value: v20);
LABEL_20:
            ((void (__thiscall *)(IClientMaterialSystem *, unsigned int))v4->PostToolMessage)(a1: v4, a2: hEntity);
            break;
          default:
            break;
        }
        KeyValues::deleteThis(this: v3);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033060
// Name: IsVector
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsVector(const char *v)
{
  char v1; // al
  char v3; // cl

  v1 = *v;
  while ( v1 == 32 || v1 == 9 )
  {
    v1 = *++v;
    if ( v1 == 10 || v1 == 0 )
      return false;
  }
  v3 = *v;
  return v3 == 91 || v3 == 123;
}

//------------------------------------------------------------------------------
// Address: 0x10033090
// Name: ParseVectorFromKeyValueString
// Source: json
//------------------------------------------------------------------------------
int __usercall ParseVectorFromKeyValueString@<eax>(const char *pString@<eax>, float *vecVal)
{
  char *v3; // esi
  int v4; // edi
  char v5; // al
  char *pEnd; // [esp+Ch] [ebp-8h] BYREF
  bool divideBy255; // [esp+13h] [ebp-1h]

  divideBy255 = false;
  while ( *pString == 32 || *pString == 9 )
    ++pString;
  if ( *pString == 123 )
    divideBy255 = true;
  v3 = (char *)(pString + 1);
  v4 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v5 = *v3;
      if ( *v3 != 32 && v5 != 9 )
        break;
      ++v3;
    }
    if ( v5 == 10 || v5 == 0 )
      break;
    if ( v5 == 93 )
      goto LABEL_22;
    if ( v5 == 125 )
      break;
    vecVal[v4] = strtod(nptr: v3, endptr: &pEnd);
    if ( v3 == pEnd )
    {
      _Warning(a1: "error parsing vector element in ParseVectorFromKeyValueString\n");
      return 0;
    }
    ++v4;
    v3 = pEnd;
    if ( v4 >= 4 )
      goto LABEL_23;
  }
  if ( *v3 != 93 && *v3 != 125 )
    _Warning(a1: "no ']' or '}' found in vector key in ParseVectorFromKeyValueString\n");
LABEL_22:
  vecVal[v4] = 0.0;
LABEL_23:
  if ( divideBy255 )
  {
    *vecVal = *vecVal * 0.0039215689;
    vecVal[1] = vecVal[1] * 0.0039215689;
    vecVal[2] = vecVal[2] * 0.0039215689;
    vecVal[3] = vecVal[3] * 0.0039215689;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10033190
// Name: public: virtual void CMaterialVar::SetValueAutodetectType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialVar::SetValueAutodetectType(CMaterialVar *this, char *val)
{
  const char *v2; // esi
  const char *v4; // edi
  int v5; // eax
  VMatrix temp; // [esp+18h] [ebp-B8h] BYREF
  float vecVal[4]; // [esp+58h] [ebp-78h] BYREF
  VMatrix mat; // [esp+68h] [ebp-68h] BYREF
  int ival; // [esp+A8h] [ebp-28h]
  char *pIEnd; // [esp+ACh] [ebp-24h] BYREF
  float angle; // [esp+B0h] [ebp-20h] BYREF
  Vector2D translation; // [esp+B4h] [ebp-1Ch] BYREF
  float fval; // [esp+BCh] [ebp-14h]
  Vector2D scale; // [esp+C0h] [ebp-10h] BYREF
  Vector2D center; // [esp+C8h] [ebp-8h] BYREF

  v2 = val;
  v4 = &v2[_V_strlen(str: val)];
  ival = strtol(nptr: v2, endptr: &pIEnd, ibase: 10);
  fval = strtod(nptr: v2, endptr: &val);
  if ( val > pIEnd && val == v4 )
  {
    ((void (__thiscall *)(CMaterialVar *, _DWORD))this->SetFloatValue)(a1: this, a2: LODWORD(fval));
    return;
  }
  if ( pIEnd == v4 )
  {
    this->SetIntValue(this, a2: ival);
    return;
  }
  if ( sscanf(
         string: v2,
         format: " [ %f %f %f %f  %f %f %f %f  %f %f %f %f  %f %f %f %f ]",
         &mat,
         &mat.m[0][1],
         &mat.m[0][2],
         &mat.m[0][3],
         mat.m[1],
         &mat.m[1][1],
         &mat.m[1][2],
         &mat.m[1][3],
         mat.m[2],
         &mat.m[2][1],
         &mat.m[2][2],
         &mat.m[2][3],
         mat.m[3],
         &mat.m[3][1],
         &mat.m[3][2],
         &mat.m[3][3]) == 16 )
    goto LABEL_9;
  if ( sscanf(
         string: v2,
         format: " center %f %f scale %f %f rotate %f translate %f %f",
         &center,
         &center.y,
         &scale,
         &scale.y,
         &angle,
         &translation,
         &translation.y) == 7 )
  {
    MatrixBuildTranslation(
      dst: &mat,
      x: COERCE_FLOAT(LODWORD(center.x) ^ _mask__NegFloat_),
      y: COERCE_FLOAT(LODWORD(center.y) ^ _mask__NegFloat_),
      z: 0.0);
    MatrixBuildScale(dst: &temp, x: scale.x, y: scale.y, z: 1.0);
    MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
    MatrixBuildRotateZ(dst: &temp, angleDegrees: angle);
    MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
    MatrixBuildTranslation(dst: &temp, x: translation.x + center.x, y: translation.y + center.y, z: 0.0);
    MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
LABEL_9:
    this->SetMatrixValue(this, a2: &mat);
    return;
  }
  if ( IsVector(v: v2) && (v5 = ParseVectorFromKeyValueString(pString: v2, vecVal)) > 0 )
    this->SetVecValue_4(this, a2: vecVal, a3: v5);
  else
    this->SetStringValue(this, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10033440
// Name: public: static class IMaterialVar __near * IMaterialVar::Create(class IMaterial __near *,char const __near *,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
CMaterialVar *__cdecl IMaterialVar::Create(IMaterialInternal *pMaterial, const char *pKey, const VMatrix *matrix)
{
  CMaterialVar *v3; // eax

  v3 = (CMaterialVar *)CUtlMemoryPool::Alloc(this: &CMaterialVar::s_Allocator, amount: 0x28u);
  if ( v3 != nullptr )
    return CMaterialVar::CMaterialVar(this: v3, pMaterial, pKey, matrix);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100334B0
// Name: public: static class IMaterialVar __near * IMaterialVar::Create(class IMaterial __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMaterialVar *__cdecl IMaterialVar::Create(IMaterialInternal *pMaterial, const char *pKey, const char *pVal)
{
  CMaterialVar *v3; // eax

  v3 = (CMaterialVar *)CUtlMemoryPool::Alloc(this: &CMaterialVar::s_Allocator, amount: 0x28u);
  if ( v3 != nullptr )
    return CMaterialVar::CMaterialVar(this: v3, pMaterial, pKey, pVal);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10033520
// Name: public: static class IMaterialVar __near * IMaterialVar::Create(class IMaterial __near *,char const __near *,float __near *,int)
// Source: json
//------------------------------------------------------------------------------
CMaterialVar *__cdecl IMaterialVar::Create(IMaterialInternal *pMaterial, const char *pKey, float *pVal, int numComps)
{
  CMaterialVar *v4; // eax

  v4 = (CMaterialVar *)CUtlMemoryPool::Alloc(this: &CMaterialVar::s_Allocator, amount: 0x28u);
  if ( v4 != nullptr )
    return CMaterialVar::CMaterialVar(this: v4, pMaterial, pKey, pVal, numComps);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10033590
// Name: public: static class IMaterialVar __near * IMaterialVar::Create(class IMaterial __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
CMaterialVar *__cdecl IMaterialVar::Create(IMaterialInternal *pMaterial, const char *pKey, float val)
{
  CMaterialVar *v3; // eax

  v3 = (CMaterialVar *)CUtlMemoryPool::Alloc(this: &CMaterialVar::s_Allocator, amount: 0x28u);
  if ( v3 != nullptr )
    return CMaterialVar::CMaterialVar(this: v3, pMaterial, pKey, val);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10033600
// Name: public: static class IMaterialVar __near * IMaterialVar::Create(class IMaterial __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CMaterialVar *__cdecl IMaterialVar::Create(IMaterialInternal *pMaterial, const char *pKey, int val)
{
  CMaterialVar *v3; // eax

  v3 = (CMaterialVar *)CUtlMemoryPool::Alloc(this: &CMaterialVar::s_Allocator, amount: 0x28u);
  if ( v3 != nullptr )
    return CMaterialVar::CMaterialVar(this: v3, pMaterial, pKey, val);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10033670
// Name: public: static class IMaterialVar __near * IMaterialVar::Create(class IMaterial __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMaterialVar *__cdecl IMaterialVar::Create(IMaterialInternal *pMaterial, const char *pKey)
{
  CMaterialVar *v2; // eax

  v2 = (CMaterialVar *)CUtlMemoryPool::Alloc(this: &CMaterialVar::s_Allocator, amount: 0x28u);
  if ( v2 != nullptr )
    return CMaterialVar::CMaterialVar(this: v2, pMaterial, pKey);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100336D0
// Name: public: CMaterialVar::CMaterialVar(void)
// Source: json
//------------------------------------------------------------------------------
CMaterialVar *__thiscall CMaterialVar::CMaterialVar(CMaterialVar *this)
{
  CMaterialVar *result; // eax
  char v2; // dl
  char v3; // cl

  result = this;
  this->m_Name.m_Id = -1;
  v2 = *((_BYTE *)&this->IMaterialVar + 28);
  this->__vftable = (CMaterialVar_vtbl *)&CMaterialVar::`vftable';
  *((_BYTE *)&this->IMaterialVar + 28) = v2 & 0x8F | 0x40;
  this->m_VecVal.x = 0.0;
  this->m_VecVal.y = 0.0;
  this->m_VecVal.z = 0.0;
  this->m_VecVal.w = 0.0;
  this->m_pStringVal = nullptr;
  this->m_intVal = 0;
  this->m_pMaterial = nullptr;
  v3 = *((_BYTE *)&this->IMaterialVar + 28) & 0x70 | 0x84;
  result->m_nTempIndex = -1;
  *((_BYTE *)&result->IMaterialVar + 28) = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10033720
// Name: public: virtual CMaterialVar::~CMaterialVar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialVar::~CMaterialVar(CMaterialVar *this)
{
  this->__vftable = (CMaterialVar_vtbl *)&CMaterialVar::`vftable';
  CMaterialVar::CleanUpData(this);
}

//------------------------------------------------------------------------------
// Address: 0x10033730
// Name: public: virtual class VMatrix const __near & CMaterialVar::GetMatrixValue(void)
// Source: json
//------------------------------------------------------------------------------
IMaterialInternal *__thiscall CMaterialVar::GetMatrixValue(CMaterialVar *this)
{
  unsigned __int8 m_nTempIndex; // al

  for ( ;
        g_pInternalMaterialSystem->GetRenderCallQueue(this: g_pInternalMaterialSystem) != nullptr;
        this = &s_pTempMaterialVar[m_nTempIndex] )
  {
    if ( *((char *)&this->IMaterialVar + 28) < 0 )
      break;
    m_nTempIndex = this->m_nTempIndex;
    if ( m_nTempIndex == 0xFF )
      break;
  }
  if ( (*((_BYTE *)&this->IMaterialVar + 28) & 0xF) == 7 )
    return this->m_pMaterialValue;
  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    *(_QWORD *)&identity.m[0][0] = 1065353216;
    *(_QWORD *)&identity.m[0][2] = 0;
    *(_QWORD *)&identity.m[1][0] = 0x3F80000000000000LL;
    *(_QWORD *)&identity.m[1][2] = 0;
    *(_QWORD *)&identity.m[2][0] = 0;
    *(_QWORD *)&identity.m[2][2] = 1065353216;
    *(_QWORD *)&identity.m[3][0] = 0;
    *(_QWORD *)&identity.m[3][2] = 0x3F80000000000000LL;
  }
  return (IMaterialInternal *)&identity;
}

//------------------------------------------------------------------------------
// Address: 0x10034550
// Name: public: virtual void CMaterialVar::SetFloatValue(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMaterialVar::SetFloatValue(CMaterialVar *this@<ecx>, int a2@<ebx>, float val)
{
  CMatCallQueue *v4; // edi
  char v5; // al
  int v6; // eax
  float v7; // xmm0_4
  IMaterialInternal *m_pMaterial; // ecx

  v4 = g_pInternalMaterialSystem->GetRenderCallQueue(this: g_pInternalMaterialSystem);
  v5 = *((_BYTE *)&this->IMaterialVar + 28);
  if ( v5 >= 0 && v4 != nullptr )
  {
    if ( s_bEnableThreadedAccess )
    {
      if ( this->m_nTempIndex == 0xFF )
      {
        v6 = s_nTempVarsUsed;
        this->m_nTempIndex = s_nTempVarsUsed;
        s_nTempVarsUsed = v6 + 1;
      }
      CMaterialVar::SetFloatValue(this: &s_pTempMaterialVar[this->m_nTempIndex], val);
    }
    CMatCallQueue::QueueCall<CMaterialVar *,CMaterialVar,void,float,float>(
      this: v4,
      pObject: this,
      pfnProxied: (unsigned int) __thiscall CMaterialVar::`vcall'{16,{flat}},
      arg1: &val);
  }
  else
  {
    if ( (v5 & 0xF) != 0 || this->m_VecVal.x != val )
    {
      CMaterialVar::CleanUpData(this);
      v7 = val;
      this->m_VecVal.w = val;
      this->m_VecVal.z = v7;
      this->m_VecVal.y = v7;
      this->m_VecVal.x = v7;
      *((_BYTE *)&this->IMaterialVar + 28) &= 0xF0u;
      this->m_intVal = (int)v7;
      m_pMaterial = this->m_pMaterial;
      if ( m_pMaterial == nullptr )
        return;
      m_pMaterial->ReportVarChanged(this: m_pMaterial, a2: this);
    }
    CMaterialVar::RecordToolMessage(this, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034670
// Name: public: virtual void CMaterialVar::SetIntValue(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMaterialVar::SetIntValue(CMaterialVar *this@<ecx>, int a2@<ebx>, int val)
{
  CMatCallQueue *v4; // edi
  char v5; // al
  int v6; // eax
  int v7; // edi
  IMaterialInternal *m_pMaterial; // ecx

  v4 = g_pInternalMaterialSystem->GetRenderCallQueue(this: g_pInternalMaterialSystem);
  v5 = *((_BYTE *)&this->IMaterialVar + 28);
  if ( v5 >= 0 && v4 != nullptr )
  {
    if ( s_bEnableThreadedAccess )
    {
      if ( this->m_nTempIndex == 0xFF )
      {
        v6 = s_nTempVarsUsed;
        this->m_nTempIndex = s_nTempVarsUsed;
        s_nTempVarsUsed = v6 + 1;
      }
      CMaterialVar::SetIntValue(this: &s_pTempMaterialVar[this->m_nTempIndex], val);
    }
    CMatCallQueue::QueueCall<CMaterialVar *,CMaterialVar,void,int,int>(
      this: v4,
      pObject: this,
      pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{20,{flat}},
      arg1: &val);
  }
  else
  {
    v7 = val;
    if ( (v5 & 0xF) != 4 || this->m_intVal != val )
    {
      CMaterialVar::CleanUpData(this);
      this->m_intVal = v7;
      this->m_VecVal.w = (float)v7;
      this->m_VecVal.z = (float)v7;
      this->m_VecVal.y = (float)v7;
      this->m_VecVal.x = (float)v7;
      m_pMaterial = this->m_pMaterial;
      *((_BYTE *)&this->IMaterialVar + 28) = *((_BYTE *)&this->IMaterialVar + 28) & 0xF0 | 4;
      if ( m_pMaterial == nullptr )
        return;
      m_pMaterial->ReportVarChanged(this: m_pMaterial, a2: this);
    }
    CMaterialVar::RecordToolMessage(this, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034780
// Name: public: virtual void CMaterialVar::SetFourCCValue(unsigned long,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialVar::SetFourCCValue(
        CMaterialVar *this,
        IMaterialInternal_vtbl *type,
        IMaterialInternal_vtbl *pData)
{
  CMatCallQueue *v4; // edi
  char v5; // al
  int v6; // eax
  IMaterialInternal_vtbl *v7; // ebx
  unsigned int v8; // edi
  IMaterialInternal *m_pMaterialValue; // eax
  IMaterialInternal *v10; // eax
  IMaterialInternal *m_pMaterial; // ecx

  v4 = g_pInternalMaterialSystem->GetRenderCallQueue(this: g_pInternalMaterialSystem);
  v5 = *((_BYTE *)&this->IMaterialVar + 28);
  if ( v5 >= 0 && v4 != nullptr )
  {
    if ( s_bEnableThreadedAccess )
    {
      if ( this->m_nTempIndex == 0xFF )
      {
        v6 = s_nTempVarsUsed;
        this->m_nTempIndex = s_nTempVarsUsed;
        s_nTempVarsUsed = v6 + 1;
      }
      CMaterialVar::SetFourCCValue(this: &s_pTempMaterialVar[this->m_nTempIndex], (unsigned int)type, pData);
    }
    CMatCallQueue::QueueCall<CMaterialVar *,CMaterialVar,void,unsigned long,void *,unsigned long,void *>(
      this: v4,
      pObject: this,
      pfnProxied: (unsigned int) __thiscall CMaterialVar::`vcall'{32,{flat}},
      arg1: (const unsigned int *)&type,
      arg2: (void *const *)&pData);
  }
  else
  {
    v7 = pData;
    v8 = (unsigned int)type;
    if ( (v5 & 0xF) != 5
      || (m_pMaterialValue = this->m_pMaterialValue)->__vftable != type
      || m_pMaterialValue[1].__vftable != pData )
    {
      CMaterialVar::CleanUpData(this);
      v10 = (IMaterialInternal *)MemAlloc_Alloc(nSize: 8u);
      this->m_pMaterialValue = v10;
      v10->__vftable = (IMaterialInternal_vtbl *)v8;
      this->m_pMaterialValue[1].__vftable = v7;
      *((_BYTE *)&this->IMaterialVar + 28) = *((_BYTE *)&this->IMaterialVar + 28) & 0xF0 | 5;
      this->m_VecVal.x = 0.0;
      this->m_VecVal.y = 0.0;
      this->m_VecVal.z = 0.0;
      this->m_VecVal.w = 0.0;
      m_pMaterial = this->m_pMaterial;
      this->m_intVal = 0;
      if ( m_pMaterial == nullptr )
        return;
      m_pMaterial->ReportVarChanged(this: m_pMaterial, a2: this);
    }
    CMaterialVar::RecordToolMessage(this, a2: (int)v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100348B0
// Name: public: virtual void CMaterialVar::SetTextureValue(class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialVar::SetTextureValue(CMaterialVar *this, ITextureInternal *texture)
{
  CMatCallQueue *v3; // edi
  char v4; // al
  int v5; // eax
  IMaterialInternal *v6; // edi
  IMaterialInternal *m_pMaterial; // ecx

  v3 = g_pInternalMaterialSystem->GetRenderCallQueue(this: g_pInternalMaterialSystem);
  v4 = *((_BYTE *)&this->IMaterialVar + 28);
  if ( v4 >= 0 && v3 != nullptr )
  {
    if ( s_bEnableThreadedAccess )
    {
      if ( this->m_nTempIndex == 0xFF )
      {
        v5 = s_nTempVarsUsed;
        this->m_nTempIndex = s_nTempVarsUsed;
        s_nTempVarsUsed = v5 + 1;
      }
      CMaterialVar::SetTextureValue(this: &s_pTempMaterialVar[this->m_nTempIndex], texture);
    }
    CMatCallQueue::QueueCall<CMaterialVar *,CMaterialVar,void,ITexture *,ITexture *>(
      this: v3,
      pObject: this,
      pfnProxied: (unsigned int) __thiscall CMaterialVar::`vcall'{60,{flat}},
      arg1: &texture);
    return;
  }
  v6 = (IMaterialInternal *)texture;
  if ( (v4 & 0xF) == 3 && this->m_pTexture == texture )
  {
LABEL_14:
    CMaterialVar::RecordToolMessage(this, a2: 0);
    return;
  }
  if ( texture != (ITextureInternal *)-1 )
    texture->IncrementReferenceCount(this: texture);
  CMaterialVar::CleanUpData(this);
  *((_BYTE *)&this->IMaterialVar + 28) = *((_BYTE *)&this->IMaterialVar + 28) & 0xF0 | 3;
  this->m_pMaterialValue = v6;
  this->m_intVal = 0;
  this->m_VecVal.x = 0.0;
  this->m_VecVal.y = 0.0;
  this->m_VecVal.z = 0.0;
  this->m_VecVal.w = 0.0;
  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr )
  {
    m_pMaterial->ReportVarChanged(this: m_pMaterial, a2: this);
    goto LABEL_14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100349C0
// Name: public: virtual void CMaterialVar::SetMaterialValue(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialVar::SetMaterialValue(CMaterialVar *this, IMaterialInternal *pMaterial)
{
  CMatCallQueue *v3; // eax
  CMatCallQueue *v4; // edi
  int v5; // eax
  IMaterialInternal *v6; // edi
  IMaterialInternal *m_pMaterial; // ecx

  v3 = g_pInternalMaterialSystem->GetRenderCallQueue(this: g_pInternalMaterialSystem);
  v4 = v3;
  if ( *((char *)&this->IMaterialVar + 28) >= 0 && v3 != nullptr )
  {
    if ( s_bEnableThreadedAccess )
    {
      if ( this->m_nTempIndex == 0xFF )
      {
        v5 = s_nTempVarsUsed;
        this->m_nTempIndex = s_nTempVarsUsed;
        s_nTempVarsUsed = v5 + 1;
      }
      CMaterialVar::SetMaterialValue(this: &s_pTempMaterialVar[this->m_nTempIndex], pMaterial);
    }
    CMatCallQueue::QueueCall<CMaterialVar *,CMaterialVar,void,IMaterial *,IMaterial *>(
      this: v4,
      pObject: this,
      pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{68,{flat}},
      arg1: &pMaterial);
    return;
  }
  v6 = pMaterial;
  if ( pMaterial != nullptr )
    v6 = pMaterial->GetRealTimeVersion(this: pMaterial);
  if ( (*((_BYTE *)&this->IMaterialVar + 28) & 0xF) == 8 && this->m_pMaterialValue == v6 )
  {
LABEL_16:
    CMaterialVar::RecordToolMessage(this, a2: 0);
    return;
  }
  if ( v6 != nullptr )
    v6->IncrementReferenceCount(this: v6);
  CMaterialVar::CleanUpData(this);
  *((_BYTE *)&this->IMaterialVar + 28) = *((_BYTE *)&this->IMaterialVar + 28) & 0xF0 | 8;
  this->m_pMaterialValue = v6;
  this->m_intVal = 0;
  this->m_VecVal.x = 0.0;
  this->m_VecVal.y = 0.0;
  this->m_VecVal.z = 0.0;
  this->m_VecVal.w = 0.0;
  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr )
  {
    m_pMaterial->ReportVarChanged(this: m_pMaterial, a2: this);
    goto LABEL_16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034AE0
// Name: public: void CMaterialVar::SetVecValueInternal(class Vector4D const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialVar::SetVecValueInternal(CMaterialVar *this, const Vector4D *vec, int nComps)
{
  CMatCallQueue *v4; // ebx
  char v5; // al
  int v6; // eax
  float w; // xmm0_4
  IMaterialInternal *m_pMaterial; // ecx
  Vector4D arg1; // [esp+Ch] [ebp-20h] BYREF
  __int64 v10; // [esp+1Ch] [ebp-10h]
  __int64 v11; // [esp+24h] [ebp-8h]

  v4 = g_pInternalMaterialSystem->GetRenderCallQueue(this: g_pInternalMaterialSystem);
  v5 = *((_BYTE *)&this->IMaterialVar + 28);
  if ( v5 < 0 || v4 == nullptr )
  {
    if ( (v5 & 0xF) == 2 )
    {
      if ( vec->x == this->m_VecVal.x
        && vec->y == this->m_VecVal.y
        && vec->z == this->m_VecVal.z
        && vec->w == this->m_VecVal.w )
      {
LABEL_17:
        CMaterialVar::RecordToolMessage(this, a2: (int)v4);
        return;
      }
    }
    else
    {
      CMaterialVar::CleanUpData(this);
      *((_BYTE *)&this->IMaterialVar + 28) = *((_BYTE *)&this->IMaterialVar + 28) & 0xF0 | 2;
    }
    *((_BYTE *)&this->IMaterialVar + 28) ^= (*((_BYTE *)&this->IMaterialVar + 28) ^ (16 * nComps)) & 0x70;
    m_pMaterial = this->m_pMaterial;
    this->m_VecVal = *vec;
    this->m_intVal = (int)this->m_VecVal.x;
    if ( m_pMaterial == nullptr )
      return;
    m_pMaterial->ReportVarChanged(this: m_pMaterial, a2: this);
    goto LABEL_17;
  }
  if ( s_bEnableThreadedAccess )
  {
    if ( this->m_nTempIndex == 0xFF )
    {
      v6 = s_nTempVarsUsed;
      this->m_nTempIndex = s_nTempVarsUsed;
      s_nTempVarsUsed = v6 + 1;
    }
    CMaterialVar::SetVecValueInternal(this: &s_pTempMaterialVar[this->m_nTempIndex], vec, nComps);
  }
  arg1.x = vec->x;
  arg1.y = vec->y;
  arg1.z = vec->z;
  w = vec->w;
  v11 = 0;
  arg1.w = w;
  v10 = (unsigned int)CMaterialVar::SetVecValueInternal;
  CMatCallQueue::QueueCall<CMaterialVar *,CMaterialVar,void,Vector4D const &,int,Vector4D,int>(
    this: v4,
    pObject: this,
    pfnProxied: (unsigned int)CMaterialVar::SetVecValueInternal,
    &arg1,
    arg2: &nComps);
}

//------------------------------------------------------------------------------
// Address: 0x10034C60
// Name: public: virtual void CMaterialVar::SetVecValue(float const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialVar::SetVecValue(CMaterialVar *this, float *pVal, int numComps)
{
  int v3; // ebx
  int v4; // edi
  CMatCallQueue *(__thiscall *GetRenderCallQueue)(IMaterialSystemInternal *); // eax
  CMatCallQueue *v7; // edi
  char v8; // al
  int v9; // eax
  IMaterialInternal *m_pMaterial; // ecx
  char v11; // bl
  __int64 v12; // xmm0_8
  Vector4D arg1; // [esp+Ch] [ebp-30h] BYREF
  __int64 v14; // [esp+1Ch] [ebp-20h]
  __int64 v15; // [esp+24h] [ebp-18h]
  Vector4D vec; // [esp+2Ch] [ebp-10h] BYREF

  v3 = numComps;
  v4 = 4 * numComps;
  memcpy(dst: (unsigned __int8 *)&vec, src: (unsigned __int8 *)pVal, count: 4 * numComps);
  if ( v3 < 4 )
    memset((char *)&vec + v4, 0, 4 * (4 - v3));
  GetRenderCallQueue = g_pInternalMaterialSystem->GetRenderCallQueue;
  numComps = v3;
  v7 = GetRenderCallQueue(this: g_pInternalMaterialSystem);
  v8 = *((_BYTE *)&this->IMaterialVar + 28);
  if ( v8 < 0 || v7 == nullptr )
  {
    if ( (v8 & 0xF) == 2 )
    {
      if ( vec.x == this->m_VecVal.x
        && vec.y == this->m_VecVal.y
        && vec.z == this->m_VecVal.z
        && vec.w == this->m_VecVal.w )
      {
LABEL_19:
        CMaterialVar::RecordToolMessage(this, a2: v3);
        return;
      }
    }
    else
    {
      CMaterialVar::CleanUpData(this);
      *((_BYTE *)&this->IMaterialVar + 28) = *((_BYTE *)&this->IMaterialVar + 28) & 0xF0 | 2;
    }
    m_pMaterial = this->m_pMaterial;
    v11 = *((_BYTE *)&this->IMaterialVar + 28) ^ (16 * v3);
    *(_QWORD *)&this->m_VecVal.x = *(_QWORD *)&vec.x;
    v12 = *(_QWORD *)&vec.z;
    LOBYTE(v3) = v11 & 0x70;
    *((_BYTE *)&this->IMaterialVar + 28) ^= v3;
    *(_QWORD *)&this->m_VecVal.z = v12;
    this->m_intVal = (int)this->m_VecVal.x;
    if ( m_pMaterial == nullptr )
      return;
    m_pMaterial->ReportVarChanged(this: m_pMaterial, a2: this);
    goto LABEL_19;
  }
  if ( s_bEnableThreadedAccess )
  {
    if ( this->m_nTempIndex == 0xFF )
    {
      v9 = s_nTempVarsUsed;
      this->m_nTempIndex = s_nTempVarsUsed;
      s_nTempVarsUsed = v9 + 1;
    }
    CMaterialVar::SetVecValueInternal(this: &s_pTempMaterialVar[this->m_nTempIndex], &vec, nComps: v3);
  }
  arg1 = vec;
  v15 = 0;
  v14 = (unsigned int)CMaterialVar::SetVecValueInternal;
  CMatCallQueue::QueueCall<CMaterialVar *,CMaterialVar,void,Vector4D const &,int,Vector4D,int>(
    this: v7,
    pObject: this,
    pfnProxied: (unsigned int)CMaterialVar::SetVecValueInternal,
    &arg1,
    arg2: &numComps);
}

//------------------------------------------------------------------------------
// Address: 0x10034E10
// Name: public: virtual void CMaterialVar::SetVecValue(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialVar::SetVecValue(CMaterialVar *this, float x, float y)
{
  Vector4D vec; // [esp+0h] [ebp-10h] BYREF

  vec.x = x;
  vec.y = y;
  vec.z = 0.0;
  vec.w = 0.0;
  CMaterialVar::SetVecValueInternal(this, &vec, nComps: 2);
}

//------------------------------------------------------------------------------
// Address: 0x10034E50
// Name: public: virtual void CMaterialVar::SetVecValue(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialVar::SetVecValue(CMaterialVar *this, float x, float y, float z)
{
  Vector4D vec; // [esp+0h] [ebp-10h] BYREF

  vec.x = x;
  vec.y = y;
  vec.z = z;
  vec.w = 0.0;
  CMaterialVar::SetVecValueInternal(this, &vec, nComps: 3);
}

//------------------------------------------------------------------------------
// Address: 0x10034E90
// Name: public: virtual void CMaterialVar::SetVecValue(float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialVar::SetVecValue(CMaterialVar *this, float x, float y, float z, float w)
{
  Vector4D vec; // [esp+0h] [ebp-10h] BYREF

  vec.x = x;
  vec.y = y;
  vec.z = z;
  vec.w = w;
  CMaterialVar::SetVecValueInternal(this, &vec, nComps: 4);
}

//------------------------------------------------------------------------------
// Address: 0x10034ED0
// Name: public: virtual void CMaterialVar::SetVecComponentValue(float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialVar::SetVecComponentValue(CMaterialVar *this, float fVal, unsigned int nComponent)
{
  int v3; // ebx
  CMatCallQueue *v5; // edi
  unsigned __int8 v6; // al
  int v7; // ecx
  int v8; // eax
  IMaterialInternal *m_pMaterial; // ecx
  IMaterial *v10; // eax
  int v11; // eax
  const char *v12; // eax
  const char *v13; // [esp+4h] [ebp-20h]

  v3 = nComponent;
  if ( nComponent > 3 )
  {
    v10 = this->GetOwningMaterial(this);
    v11 = v10->GetName(this: v10);
    v12 = (const char *)((int (__thiscall *)(CMaterialVar *, int))this->GetName)(a1: this, a2: v11);
    _Error(a1: "Invalid vector component (%d) of variable %s referenced in material %s", v3, v12, v13);
    return;
  }
  v5 = g_pInternalMaterialSystem->GetRenderCallQueue(this: g_pInternalMaterialSystem);
  v6 = *((_BYTE *)&this->IMaterialVar + 28);
  if ( (v6 & 0x80u) == 0 && v5 != nullptr )
  {
    if ( s_bEnableThreadedAccess )
    {
      if ( this->m_nTempIndex == 0xFF )
      {
        v7 = s_nTempVarsUsed;
        this->m_nTempIndex = s_nTempVarsUsed;
        s_nTempVarsUsed = v7 + 1;
        CMaterialVar::SetVecValue(
          this: &s_pTempMaterialVar[this->m_nTempIndex],
          pVal: &this->m_VecVal.x,
          numComps: (v6 >> 4) & 7);
      }
      CMaterialVar::SetVecComponentValue(this: &s_pTempMaterialVar[this->m_nTempIndex], fVal, nComponent: v3);
    }
    CMatCallQueue::QueueCall<CMaterialVar *,CMaterialVar,void,float,int,float,int>(
      this: v5,
      pObject: this,
      pfnProxied: (unsigned int) __thiscall IColorCorrectionSystem::`vcall'{104,{flat}},
      arg1: &fVal,
      arg2: (const int *)&nComponent);
    return;
  }
  if ( (v6 & 0xF) == 2 )
  {
    if ( *(&this->m_VecVal.x + v3) == fVal )
    {
LABEL_17:
      CMaterialVar::RecordToolMessage(this, a2: v3);
      return;
    }
  }
  else
  {
    CMaterialVar::CleanUpData(this);
    *((_BYTE *)&this->IMaterialVar + 28) = *((_BYTE *)&this->IMaterialVar + 28) & 0xF0 | 2;
  }
  v8 = (*((unsigned __int8 *)&this->IMaterialVar + 28) >> 4) & 7;
  if ( v8 < v3 )
  {
    memset(&this->m_VecVal.x + v8, 0, 4 * (v3 - v8));
    *((_BYTE *)&this->IMaterialVar + 28) ^= (*((_BYTE *)&this->IMaterialVar + 28) ^ (16 * v3)) & 0x70;
  }
  *(&this->m_VecVal.x + v3) = fVal;
  m_pMaterial = this->m_pMaterial;
  if ( m_pMaterial != nullptr )
  {
    m_pMaterial->ReportVarChanged(this: m_pMaterial, a2: this);
    goto LABEL_17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035070
// Name: public: virtual void CMaterialVar::SetMatrixValue(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialVar::SetMatrixValue(CMaterialVar *this, const VMatrix *matrix)
{
  CMatCallQueue *v3; // eax
  bool v4; // zf
  int v5; // eax
  IMaterialInternal *v6; // eax
  IMaterialInternal *m_pMaterial; // ecx
  VMatrix arg1; // [esp+Ch] [ebp-54h] BYREF
  __int64 v9; // [esp+4Ch] [ebp-14h]
  __int64 v10; // [esp+54h] [ebp-Ch]
  CMatCallQueue *pCallQueue; // [esp+5Ch] [ebp-4h]

  v3 = g_pInternalMaterialSystem->GetRenderCallQueue(this: g_pInternalMaterialSystem);
  v4 = *((_BYTE *)&this->IMaterialVar + 28) >= 0;
  pCallQueue = v3;
  if ( v4 && v3 != nullptr )
  {
    if ( s_bEnableThreadedAccess )
    {
      if ( this->m_nTempIndex == 0xFF )
      {
        v5 = s_nTempVarsUsed;
        this->m_nTempIndex = s_nTempVarsUsed;
        s_nTempVarsUsed = v5 + 1;
      }
      CMaterialVar::SetMatrixValue(this: &s_pTempMaterialVar[this->m_nTempIndex], matrix);
      v3 = pCallQueue;
    }
    v10 = 0;
    arg1 = *matrix;
    v9 = (unsigned int) __thiscall IMatRenderContext::`vcall'{80,{flat}};
    CMatCallQueue::QueueCall<CMaterialVar *,CMaterialVar,void,VMatrix const &,VMatrix>(
      this: v3,
      pObject: this,
      pfnProxied: (unsigned int) __thiscall IMatRenderContext::`vcall'{80,{flat}},
      &arg1);
  }
  else
  {
    CMaterialVar::CleanUpData(this);
    v6 = (IMaterialInternal *)MemAlloc_Alloc(nSize: 0x41u);
    this->m_pMaterialValue = v6;
    MatrixCopy(src: matrix, dst: (VMatrix *)v6);
    *((_BYTE *)&this->IMaterialVar + 28) = *((_BYTE *)&this->IMaterialVar + 28) & 0xF0 | 7;
    LOBYTE(this->m_pMaterialValue[16].__vftable) = VMatrix::IsIdentity(this: matrix);
    this->m_VecVal.x = 0.0;
    this->m_VecVal.y = 0.0;
    this->m_VecVal.z = 0.0;
    this->m_VecVal.w = 0.0;
    m_pMaterial = this->m_pMaterial;
    this->m_intVal = (int)0.0;
    if ( m_pMaterial != nullptr )
    {
      m_pMaterial->ReportVarChanged(this: m_pMaterial, a2: this);
      CMaterialVar::RecordToolMessage(this, a2: (int)this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100351A0
// Name: public: virtual void CMaterialVar::SetUndefined(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMaterialVar::SetUndefined(CMaterialVar *this@<ecx>, int a2@<ebx>)
{
  CMatCallQueue *v3; // edi
  char v4; // al
  int v5; // eax
  IMaterialInternal *m_pMaterial; // ecx

  v3 = g_pInternalMaterialSystem->GetRenderCallQueue(this: g_pInternalMaterialSystem);
  v4 = *((_BYTE *)&this->IMaterialVar + 28);
  if ( v4 >= 0 && v3 != nullptr )
  {
    if ( s_bEnableThreadedAccess )
    {
      if ( this->m_nTempIndex == 0xFF )
      {
        v5 = s_nTempVarsUsed;
        this->m_nTempIndex = s_nTempVarsUsed;
        s_nTempVarsUsed = v5 + 1;
      }
      CMaterialVar::SetUndefined(this: &s_pTempMaterialVar[this->m_nTempIndex]);
    }
    CMatCallQueue::QueueCall<CMaterialVar *,CMaterialVar,void>(
      this: v3,
      pObject: this,
      pfnProxied: (unsigned int) __thiscall CMaterialVar::`vcall'{76,{flat}});
  }
  else if ( (v4 & 0xF) != 6 )
  {
    CMaterialVar::CleanUpData(this);
    m_pMaterial = this->m_pMaterial;
    *((_BYTE *)&this->IMaterialVar + 28) = *((_BYTE *)&this->IMaterialVar + 28) & 0xF0 | 6;
    if ( m_pMaterial != nullptr )
    {
      m_pMaterial->ReportVarChanged(this: m_pMaterial, a2: this);
      CMaterialVar::RecordToolMessage(this, a2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035270
// Name: public: virtual void CMaterialVar::CopyFrom(class IMaterialVar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialVar::CopyFrom(CMaterialVar *this, float pMaterialVar)
{
  CMatCallQueue *v3; // eax
  CMatCallQueue *v4; // edi
  int v5; // eax
  float v6; // edi
  CMaterialVar_vtbl *v7; // ebx
  const char *v8; // eax
  int v9; // ebx
  const float *v10; // eax
  CMaterialVar_vtbl *v11; // ebx
  int v12; // eax
  int v13; // eax
  CMaterialVar_vtbl *v14; // ebx
  const VMatrix *v15; // eax
  CMaterialVar_vtbl *v16; // ebx
  IMaterial *v17; // eax
  unsigned int fourCC; // [esp+20h] [ebp-4h] BYREF

  v3 = g_pInternalMaterialSystem->GetRenderCallQueue(this: g_pInternalMaterialSystem);
  v4 = v3;
  if ( *((char *)&this->IMaterialVar + 28) >= 0 && v3 != nullptr )
  {
    if ( s_bEnableThreadedAccess )
    {
      if ( this->m_nTempIndex == 0xFF )
      {
        v5 = s_nTempVarsUsed;
        this->m_nTempIndex = s_nTempVarsUsed;
        s_nTempVarsUsed = v5 + 1;
      }
      CMaterialVar::CopyFrom(
        this: &s_pTempMaterialVar[this->m_nTempIndex],
        pMaterialVar: (IMaterialVar *)LODWORD(pMaterialVar));
    }
    CMatCallQueue::QueueCall<CMaterialVar *,CMaterialVar,void,IMaterialVar *,IMaterialVar *>(
      this: v4,
      pObject: this,
      pfnProxied: (unsigned int) __thiscall IColorCorrectionSystem::`vcall'{92,{flat}},
      arg1: (IMaterialVar *const *)&pMaterialVar);
  }
  else
  {
    v6 = pMaterialVar;
    switch ( *(_BYTE *)(LODWORD(pMaterialVar) + 28) & 0xF )
    {
      case 0:
        pMaterialVar = ((double (__thiscall *)(_DWORD))*(_DWORD *)(*(_DWORD *)LODWORD(pMaterialVar) + 112))(a1: LODWORD(pMaterialVar));
        ((void (__thiscall *)(CMaterialVar *, _DWORD))this->SetFloatValue)(a1: this, a2: LODWORD(pMaterialVar));
        break;
      case 1:
        v7 = this->__vftable;
        v8 = (const char *)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(pMaterialVar) + 28))(a1: LODWORD(pMaterialVar));
        v7->SetStringValue(this, a2: v8);
        break;
      case 2:
        v9 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(pMaterialVar) + 124))(a1: LODWORD(pMaterialVar));
        v10 = (const float *)(*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(v6) + 120))(a1: COERCE_FLOAT(LODWORD(v6)));
        this->SetVecValue_4(this, a2: v10, a3: v9);
        break;
      case 3:
        v11 = this->__vftable;
        v12 = (**(int (__thiscall ***)(_DWORD))LODWORD(pMaterialVar))(a1: LODWORD(pMaterialVar));
        v11->SetTextureValue(this, a2: (ITexture *)v12);
        break;
      case 4:
        v13 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(pMaterialVar) + 108))(a1: LODWORD(pMaterialVar));
        this->SetIntValue(this, a2: v13);
        break;
      case 5:
        (*(void (__thiscall **)(_DWORD, unsigned int *, float *))(*(_DWORD *)LODWORD(pMaterialVar) + 36))(
          a1: LODWORD(pMaterialVar),
          a2: &fourCC,
          a3: &pMaterialVar);
        this->SetFourCCValue(this, a2: fourCC, a3: (void *)LODWORD(pMaterialVar));
        break;
      case 6:
        this->SetUndefined(this);
        break;
      case 7:
        v14 = this->__vftable;
        v15 = (const VMatrix *)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(pMaterialVar) + 84))(a1: LODWORD(pMaterialVar));
        v14->SetMatrixValue(this, a2: v15);
        break;
      case 8:
        v16 = this->__vftable;
        v17 = (IMaterial *)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(pMaterialVar) + 64))(a1: LODWORD(pMaterialVar));
        v16->SetMaterialValue(this, a2: v17);
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035460
// Name: void EnableThreadedMaterialVarAccess(bool,class IMaterialVar __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EnableThreadedMaterialVarAccess(bool bEnable, IMaterialVar **ppParams, int nVarCount)
{
  int v3; // ebx
  char *v4; // esi
  CMatCallQueue *v5; // eax
  CMatCallQueue *v6; // edi
  int v7; // eax
  int v8; // ecx
  int i; // eax
  IMaterialVar *v10; // esi

  if ( s_bEnableThreadedAccess != bEnable )
  {
    s_bEnableThreadedAccess = bEnable;
    if ( !bEnable )
    {
      v3 = 0;
      if ( s_nTempVarsUsed > 0 )
      {
        v4 = (char *)&s_pTempMaterialVar[0].IMaterialVar + 28;
        do
        {
          v5 = g_pInternalMaterialSystem->GetRenderCallQueue(this: g_pInternalMaterialSystem);
          v6 = v5;
          if ( *v4 >= 0 && v5 != nullptr )
          {
            if ( s_bEnableThreadedAccess )
            {
              if ( v4[1] == -1 )
              {
                v7 = s_nTempVarsUsed;
                v4[1] = s_nTempVarsUsed;
                s_nTempVarsUsed = v7 + 1;
              }
              CMaterialVar::SetUndefined(this: &s_pTempMaterialVar[(unsigned __int8)v4[1]], a2: v3);
            }
            CMatCallQueue::QueueCall<CMaterialVar *,CMaterialVar,void>(
              this: v6,
              pObject: (CMaterialVar *)(v4 - 28),
              pfnProxied: (unsigned int) __thiscall CMaterialVar::`vcall'{76,{flat}});
          }
          else if ( (*v4 & 0xF) != 6 )
          {
            CMaterialVar::CleanUpData(this: (CMaterialVar *)(v4 - 28));
            *v4 = *v4 & 0xF0 | 6;
            v8 = *((_DWORD *)v4 + 1);
            if ( v8 != 0 )
            {
              (*(void (__thiscall **)(int, char *))(*(_DWORD *)v8 + 348))(a1: v8, a2: v4 - 28);
              CMaterialVar::RecordToolMessage(this: (CMaterialVar *)(v4 - 28), a2: v3);
            }
          }
          ++v3;
          v4 += 40;
        }
        while ( v3 < s_nTempVarsUsed );
      }
      for ( i = 0; i < nVarCount; v10->m_nTempIndex = -1 )
        v10 = ppParams[i++];
      s_nTempVarsUsed = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035690
// Name: public: virtual void CMaterialVar::SetStringValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialVar::SetStringValue(CMaterialVar *this, const char *val)
{
  CMatCallQueue *v3; // eax
  bool v4; // zf
  int v5; // eax
  int v6; // edi
  char *v7; // eax
  int v8; // eax
  long double v9; // st7
  IMaterialInternal *m_pMaterial; // ecx
  char *m_pStringVal; // [esp-1Ch] [ebp-58h]
  CUtlString v12; // [esp+Ch] [ebp-30h] BYREF
  __int128 v13; // [esp+1Ch] [ebp-20h]
  CMatCallQueue *pCallQueue; // [esp+2Ch] [ebp-10h]
  int v15; // [esp+38h] [ebp-4h]

  v3 = g_pInternalMaterialSystem->GetRenderCallQueue(this: g_pInternalMaterialSystem);
  v4 = *((_BYTE *)&this->IMaterialVar + 28) >= 0;
  pCallQueue = v3;
  if ( v4 && v3 != nullptr )
  {
    if ( s_bEnableThreadedAccess )
    {
      if ( this->m_nTempIndex == 0xFF )
      {
        v5 = s_nTempVarsUsed;
        this->m_nTempIndex = s_nTempVarsUsed;
        s_nTempVarsUsed = v5 + 1;
      }
      CMaterialVar::SetStringValue(this: &s_pTempMaterialVar[this->m_nTempIndex], val);
    }
    LODWORD(v13) =  __thiscall CMaterialVar::`vcall'{24,{flat}};
    DWORD1(v13) = 0;
    *((_QWORD *)&v13 + 1) = 0;
    CUtlString::CUtlString(this: &v12);
    v15 = 0;
    CUtlString::operator=(this: &v12, src: val);
    v15 = 1;
    CMatCallQueue::QueueCall<CMaterialVar *,CMaterialVar,void,char const *,CUtlEnvelope<char const *>>(
      this: pCallQueue,
      pObject: this,
      pfnProxied: v13,
      arg1: (const CUtlEnvelope<char const *> *)&v12);
    v15 = -1;
    v12.m_Storage.m_nActualLength = 0;
    if ( v12.m_Storage.m_Memory.m_nGrowSize >= 0 && v12.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12.m_Storage.m_Memory.m_pMemory);
  }
  else
  {
    CMaterialVar::CleanUpData(this);
    v6 = _V_strlen(str: val) + 1;
    v7 = (char *)MemAlloc_Alloc(nSize: v6);
    this->m_pStringVal = v7;
    V_strncpy(pDest: v7, pSrc: val, maxLen: v6);
    *((_BYTE *)&this->IMaterialVar + 28) = *((_BYTE *)&this->IMaterialVar + 28) & 0xF0 | 1;
    v8 = atoi(nptr: val);
    m_pStringVal = this->m_pStringVal;
    this->m_intVal = v8;
    v9 = atof(nptr: m_pStringVal);
    this->m_VecVal.w = v9;
    this->m_VecVal.z = v9;
    this->m_VecVal.y = v9;
    this->m_VecVal.x = v9;
    m_pMaterial = this->m_pMaterial;
    if ( m_pMaterial != nullptr )
    {
      m_pMaterial->ReportVarChanged(this: m_pMaterial, a2: this);
      CMaterialVar::RecordToolMessage(this, a2: (int)val);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028B150
// Name: _dynamic_initializer_for__CMaterialVar::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CMaterialVar::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CMaterialVar::s_Allocator,
    blockSize: 40,
    numElements: 1024,
    growMode: 1,
    pszAllocOwner: "CMaterialVar pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CMaterialVar::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x1028C570
// Name: _dynamic_atexit_destructor_for__CMaterialVar::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMaterialVar::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CMaterialVar::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x1028B180
// Name: _dynamic_initializer_for__s_MaterialVarSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_MaterialVarSymbols__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &s_MaterialVarSymbols, growSize: 0, initSize: 32, caseInsensitive: true);
  s_MaterialVarSymbols.m_lock.m_lockInfo.m_i32 = 0;
  s_MaterialVarSymbols.m_lock.m_writerId = 0;
  return atexit(func: dynamic_atexit_destructor_for__s_MaterialVarSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B1B0
// Name: _dynamic_initializer_for__s_pTempMaterialVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_pTempMaterialVar__()
{
  `eh vector constructor iterator'(
    ptr: s_pTempMaterialVar,
    size: 0x28u,
    count: 254,
    pCtor: (void (__thiscall *)(void *))CMaterialVar::CMaterialVar,
    pDtor: (void (__thiscall *)(void *))CMaterialVar::~CMaterialVar);
  return atexit(func: dynamic_atexit_destructor_for__s_pTempMaterialVar__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B1E0
// Name: _dynamic_initializer_for__mat_lightmap_pfms__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_lightmap_pfms__()
{
  ConVar::ConVar(
    this: &mat_lightmap_pfms,
    pName: "mat_lightmap_pfms",
    pDefaultValue: "0",
    flags: 0x800000,
    pHelpString: "Outputs .pfm files containing lightmap data for each lightmap page when a level exits.");
  return atexit(func: dynamic_atexit_destructor_for__mat_lightmap_pfms__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B210
// Name: _dynamic_initializer_for__mat_dynamiclightmaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_dynamiclightmaps__()
{
  ConVar::ConVar(this: &mat_dynamiclightmaps, pName: "mat_dynamiclightmaps", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_dynamiclightmaps__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B240
// Name: _dynamic_initializer_for__mat_dynamicPaintmaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_dynamicPaintmaps__()
{
  ConVar::ConVar(this: &mat_dynamicPaintmaps, pName: "mat_dynamicPaintmaps", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_dynamicPaintmaps__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B270
// Name: _dynamic_initializer_for__mat_report_queue_status__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_report_queue_status__()
{
  ConVar::ConVar(this: &mat_report_queue_status, pName: "mat_report_queue_status", pDefaultValue: "0", flags: 0x800000);
  return atexit(func: dynamic_atexit_destructor_for__mat_report_queue_status__);
}

//------------------------------------------------------------------------------
// Address: 0x1028C580
// Name: _dynamic_atexit_destructor_for__s_MaterialVarSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_MaterialVarSymbols__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &s_MaterialVarSymbols);
}

//------------------------------------------------------------------------------
// Address: 0x1028C590
// Name: _dynamic_atexit_destructor_for__s_pTempMaterialVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_pTempMaterialVar__()
{
  `eh vector destructor iterator'(
    ptr: s_pTempMaterialVar,
    size: 0x28u,
    count: 254,
    pDtor: (void (__thiscall *)(void *))CMaterialVar::~CMaterialVar);
}

//------------------------------------------------------------------------------
// Address: 0x1028C5B0
// Name: _dynamic_atexit_destructor_for__mat_lightmap_pfms__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_lightmap_pfms__()
{
  ConVar::~ConVar(this: &mat_lightmap_pfms);
}

//------------------------------------------------------------------------------
// Address: 0x1028C5C0
// Name: _dynamic_atexit_destructor_for__mat_dynamiclightmaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_dynamiclightmaps__()
{
  ConVar::~ConVar(this: &mat_dynamiclightmaps);
}
