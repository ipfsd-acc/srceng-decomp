// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dmxloader/dmxattribute.cpp
// Functions: 22
// ============================================================

#include "dmxloader\dmxattribute.h"

//------------------------------------------------------------------------------
// Address: 0x102491D0
// Name: public: char const __near * CDmxAttribute::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxAttribute::GetName(CDmxAttribute *this)
{
  const char *result; // eax

  result = this->m_Name.u.m_pAsString;
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102491E0
// Name: private: void CDmxAttribute::SerializeType<int,int>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<int,int>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  int temp; // [esp+0h] [ebp-4h] BYREF

  temp = (int)this;
  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const int *)this->m_pData);
  }
  else
  {
    temp = 0;
    v3 = Serialize(buf, src: &temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10249210
// Name: private: void CDmxAttribute::SerializeType<float,float>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<float,float>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  CDmxAttribute *temp; // [esp+0h] [ebp-4h] BYREF

  temp = this;
  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const float *)this->m_pData);
  }
  else
  {
    temp = nullptr;
    v3 = Serialize(buf, src: (const float *)&temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10249250
// Name: private: void CDmxAttribute::SerializeType<bool,bool>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<bool,bool>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  bool temp; // [esp+1h] [ebp-1h] BYREF

  temp = HIBYTE(this);
  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const bool *)this->m_pData);
  }
  else
  {
    temp = false;
    v3 = Serialize(buf, src: &temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10249460
// Name: public: int CDmxAttribute::GetArrayCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxAttribute::GetArrayCount(CDmxAttribute *this)
{
  DmAttributeType_t m_Type; // edx
  int result; // eax
  _DWORD *m_pData; // ecx

  m_Type = this->m_Type;
  result = 0;
  if ( (unsigned int)(this->m_Type - 15) <= 0xD )
  {
    m_pData = this->m_pData;
    if ( m_pData != nullptr )
    {
      switch ( m_Type )
      {
        case AT_FIRST_ARRAY_TYPE:
        case AT_INT_ARRAY:
        case AT_FLOAT_ARRAY:
        case AT_BOOL_ARRAY:
        case AT_STRING_ARRAY:
        case AT_VOID_ARRAY:
        case AT_TIME_ARRAY:
        case AT_COLOR_ARRAY:
        case AT_VECTOR2_ARRAY:
        case AT_VECTOR3_ARRAY:
        case AT_VECTOR4_ARRAY:
        case AT_QANGLE_ARRAY:
        case AT_QUATERNION_ARRAY:
        case AT_VMATRIX_ARRAY:
          result = m_pData[3];
          break;
        default:
          return result;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102494C0
// Name: public: bool CDmxAttribute::SerializesOnMultipleLines(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::SerializesOnMultipleLines(CDmxAttribute *this)
{
  bool result; // al

  result = false;
  switch ( this->m_Type )
  {
    case AT_FIRST_VALUE_TYPE:
    case AT_INT:
    case AT_FLOAT:
    case AT_BOOL:
    case AT_STRING:
    case AT_TIME:
    case AT_COLOR:
    case AT_VECTOR2:
    case AT_VECTOR3:
    case AT_VECTOR4:
    case AT_QANGLE:
    case AT_QUATERNION:
    case AT_FIRST_ARRAY_TYPE:
    case AT_INT_ARRAY:
    case AT_FLOAT_ARRAY:
    case AT_BOOL_ARRAY:
    case AT_STRING_ARRAY:
    case AT_VOID_ARRAY:
    case AT_TIME_ARRAY:
    case AT_COLOR_ARRAY:
    case AT_VECTOR2_ARRAY:
    case AT_VECTOR3_ARRAY:
    case AT_VECTOR4_ARRAY:
    case AT_QANGLE_ARRAY:
    case AT_QUATERNION_ARRAY:
    case AT_VMATRIX_ARRAY:
      result = false;
      break;
    case AT_VOID:
    case AT_VMATRIX:
      result = true;
      break;
    default:
      return result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10249EE0
// Name: bool Serialize<int>(class CUtlBuffer __near &,class CUtlVector<int,class CUtlMemory<int,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Serialize<int>(CUtlBuffer *buf, const CUtlVector<int,CUtlMemory<int,int> > *src)
{
  int m_Size; // ebx
  int v3; // edi
  int i; // edi
  int m_Put; // eax

  m_Size = src->m_Size;
  if ( (buf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::PutChar(this: buf, c: 10);
    for ( i = 0; i < m_Size; ++i )
    {
      Serialize(buf, src: &src->m_Memory.m_pMemory[i]);
      if ( s_pUtlBufferUtilArrayDelim != nullptr && i != m_Size - 1 )
        CUtlBuffer::PutString(this: buf, pString: (char *)s_pUtlBufferUtilArrayDelim);
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
        CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
      }
    }
    return buf->m_Error == 0;
  }
  CUtlBuffer::PutTypeBin<int>(this: buf, src: src->m_Size);
  v3 = 0;
  if ( m_Size <= 0 )
    return buf->m_Error == 0;
  do
    Serialize(buf, src: &src->m_Memory.m_pMemory[v3++]);
  while ( v3 < m_Size );
  return buf->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10249FC0
// Name: bool Serialize<float>(class CUtlBuffer __near &,class CUtlVector<float,class CUtlMemory<float,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Serialize<float>(CUtlBuffer *buf, const CUtlVector<float,CUtlMemory<float,int> > *src)
{
  int m_Size; // ebx
  int v3; // edi
  int i; // edi
  int m_Put; // eax

  m_Size = src->m_Size;
  if ( (buf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::PutChar(this: buf, c: 10);
    for ( i = 0; i < m_Size; ++i )
    {
      Serialize(buf, src: &src->m_Memory.m_pMemory[i]);
      if ( s_pUtlBufferUtilArrayDelim != nullptr && i != m_Size - 1 )
        CUtlBuffer::PutString(this: buf, pString: (char *)s_pUtlBufferUtilArrayDelim);
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
        CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
      }
    }
    return buf->m_Error == 0;
  }
  CUtlBuffer::PutTypeBin<int>(this: buf, src: src->m_Size);
  v3 = 0;
  if ( m_Size <= 0 )
    return buf->m_Error == 0;
  do
    Serialize(buf, src: &src->m_Memory.m_pMemory[v3++]);
  while ( v3 < m_Size );
  return buf->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1024A0A0
// Name: bool Serialize<bool>(class CUtlBuffer __near &,class CUtlVector<bool,class CUtlMemory<bool,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Serialize<bool>(CUtlBuffer *buf, const CUtlVector<bool,CUtlMemory<bool,int> > *src)
{
  int m_Size; // ebx
  int v3; // edi
  int i; // edi
  int m_Put; // eax

  m_Size = src->m_Size;
  if ( (buf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::PutChar(this: buf, c: 10);
    for ( i = 0; i < m_Size; ++i )
    {
      Serialize(buf, src: &src->m_Memory.m_pMemory[i]);
      if ( s_pUtlBufferUtilArrayDelim != nullptr && i != m_Size - 1 )
        CUtlBuffer::PutString(this: buf, pString: (char *)s_pUtlBufferUtilArrayDelim);
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
        CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
      }
    }
    return buf->m_Error == 0;
  }
  CUtlBuffer::PutTypeBin<int>(this: buf, src: src->m_Size);
  v3 = 0;
  if ( m_Size <= 0 )
    return buf->m_Error == 0;
  do
    Serialize(buf, src: &src->m_Memory.m_pMemory[v3++]);
  while ( v3 < m_Size );
  return buf->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1024A8D0
// Name: public: bool CDmxAttribute::SerializeElement(int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::SerializeElement(CDmxAttribute *this, Color nIndex, CUtlBuffer *buf)
{
  DmAttributeType_t m_Type; // eax
  bool result; // al
  bool bSuccess; // [esp+1h] [ebp-1h] BYREF

  bSuccess = HIBYTE(this);
  m_Type = this->m_Type;
  if ( (unsigned int)(this->m_Type - 15) > 0xD )
    return false;
  bSuccess = false;
  switch ( m_Type )
  {
    case AT_INT_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<int,CUtlMemory<int,int>>,int>(
        this,
        &bSuccess,
        nIndex: *(_DWORD *)&nIndex,
        buf);
      result = bSuccess;
      break;
    case AT_FLOAT_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<float,CUtlMemory<float,int>>,float>(
        this,
        &bSuccess,
        nIndex: *(_DWORD *)&nIndex,
        buf);
      result = bSuccess;
      break;
    case AT_BOOL_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        this,
        &bSuccess,
        nIndex: *(_DWORD *)&nIndex,
        buf);
      result = bSuccess;
      break;
    case AT_STRING_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        this,
        &bSuccess,
        nIndex: *(_DWORD *)&nIndex,
        buf);
      result = bSuccess;
      break;
    case AT_VOID_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        this,
        &bSuccess,
        nIndex: *(_DWORD *)&nIndex,
        buf);
      result = bSuccess;
      break;
    case AT_TIME_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        this,
        &bSuccess,
        (DmeTime_t)nIndex,
        buf);
      result = bSuccess;
      break;
    case AT_COLOR_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(this, &bSuccess, nIndex, buf);
      result = bSuccess;
      break;
    case AT_VECTOR2_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        this,
        &bSuccess,
        nIndex: *(_DWORD *)&nIndex,
        buf);
      result = bSuccess;
      break;
    case AT_VECTOR3_ARRAY:
    case AT_QANGLE_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<QAngle,CUtlMemory<QAngle,int>>,QAngle>(
        this,
        &bSuccess,
        nIndex: *(_DWORD *)&nIndex,
        buf);
      result = bSuccess;
      break;
    case AT_VECTOR4_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>,Vector4D>(
        this,
        &bSuccess,
        nIndex: *(_DWORD *)&nIndex,
        buf);
      result = bSuccess;
      break;
    case AT_QUATERNION_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        this,
        &bSuccess,
        nIndex: *(_DWORD *)&nIndex,
        buf);
      result = bSuccess;
      break;
    case AT_VMATRIX_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        this,
        &bSuccess,
        nIndex: *(_DWORD *)&nIndex,
        buf);
      goto LABEL_16;
    default:
LABEL_16:
      result = bSuccess;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1024B390
// Name: bool Unserialize<int>(class CUtlBuffer __near &,class CUtlVector<int,class CUtlMemory<int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Unserialize<int>(CUtlBuffer *buf, CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *dest)
{
  CUtlBuffer *v2; // ebx
  int Int; // eax
  int v5; // edi
  int v6; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *p_m_tms; // ecx
  int v10; // eax
  int v12; // edi
  int v13; // eax
  int *v14; // ecx
  int v15; // eax
  int nCount; // [esp+18h] [ebp+Ch]

  v2 = buf;
  dest->m_Size = 0;
  if ( (buf->m_Flags & 1) == 0 )
  {
    Int = CUtlBuffer::GetInt(this: buf);
    v5 = Int;
    nCount = Int;
    if ( Int != 0 )
    {
      CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(this: dest, num: Int);
      v6 = 0;
      if ( v5 > 0 )
      {
        do
        {
          m_Size = dest->m_Size;
          m_nAllocationCount = dest->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<INetMessage *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)dest,
              num: m_Size - m_nAllocationCount + 1);
          ++dest->m_Size;
          p_m_tms = &dest->m_Memory.m_pMemory->m_tms;
          v10 = dest->m_Size - m_Size - 1;
          dest->m_pElements = dest->m_Memory.m_pMemory;
          if ( v10 > 0 )
            _V_memmove(dest: &p_m_tms[m_Size + 1], src: &p_m_tms[m_Size], count: 4 * v10);
          if ( !Unserialize(buf, dest: &dest->m_Memory.m_pMemory[v6].m_tms) )
            return false;
        }
        while ( ++v6 < nCount );
      }
      v2 = buf;
    }
    return v2->m_Error == 0;
  }
  CUtlBuffer::EatWhiteSpace(this: buf);
  if ( buf->m_Error != 0 )
    return true;
  while ( 1 )
  {
    v12 = dest->m_Size;
    v13 = dest->m_Memory.m_nAllocationCount;
    if ( v12 + 1 > v13 )
      CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)dest, num: v12 - v13 + 1);
    ++dest->m_Size;
    v14 = &dest->m_Memory.m_pMemory->m_tms;
    v15 = dest->m_Size - v12 - 1;
    dest->m_pElements = dest->m_Memory.m_pMemory;
    if ( v15 > 0 )
      _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 4 * v15);
    if ( !Unserialize(buf, dest: &dest->m_Memory.m_pMemory[v12].m_tms) )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    if ( buf->m_Error != 0 )
      return true;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1024B4D0
// Name: bool Unserialize<float>(class CUtlBuffer __near &,class CUtlVector<float,class CUtlMemory<float,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Unserialize<float>(CUtlBuffer *buf, CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *dest)
{
  CUtlBuffer *v2; // ebx
  int Int; // eax
  int v5; // edi
  int v6; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  float *p_m_tms; // ecx
  int v10; // eax
  int v12; // edi
  int v13; // eax
  float *v14; // ecx
  int v15; // eax
  int nCount; // [esp+18h] [ebp+Ch]

  v2 = buf;
  dest->m_Size = 0;
  if ( (buf->m_Flags & 1) == 0 )
  {
    Int = CUtlBuffer::GetInt(this: buf);
    v5 = Int;
    nCount = Int;
    if ( Int != 0 )
    {
      CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(this: dest, num: Int);
      v6 = 0;
      if ( v5 > 0 )
      {
        do
        {
          m_Size = dest->m_Size;
          m_nAllocationCount = dest->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<INetMessage *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)dest,
              num: m_Size - m_nAllocationCount + 1);
          ++dest->m_Size;
          p_m_tms = (float *)&dest->m_Memory.m_pMemory->m_tms;
          v10 = dest->m_Size - m_Size - 1;
          dest->m_pElements = dest->m_Memory.m_pMemory;
          if ( v10 > 0 )
            _V_memmove(dest: &p_m_tms[m_Size + 1], src: &p_m_tms[m_Size], count: 4 * v10);
          if ( !Unserialize(buf, dest: (float *)&dest->m_Memory.m_pMemory[v6].m_tms) )
            return false;
        }
        while ( ++v6 < nCount );
      }
      v2 = buf;
    }
    return v2->m_Error == 0;
  }
  CUtlBuffer::EatWhiteSpace(this: buf);
  if ( buf->m_Error != 0 )
    return true;
  while ( 1 )
  {
    v12 = dest->m_Size;
    v13 = dest->m_Memory.m_nAllocationCount;
    if ( v12 + 1 > v13 )
      CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)dest, num: v12 - v13 + 1);
    ++dest->m_Size;
    v14 = (float *)&dest->m_Memory.m_pMemory->m_tms;
    v15 = dest->m_Size - v12 - 1;
    dest->m_pElements = dest->m_Memory.m_pMemory;
    if ( v15 > 0 )
      _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 4 * v15);
    if ( !Unserialize(buf, dest: (float *)&dest->m_Memory.m_pMemory[v12].m_tms) )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    if ( buf->m_Error != 0 )
      return true;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1024B610
// Name: bool Unserialize<bool>(class CUtlBuffer __near &,class CUtlVector<bool,class CUtlMemory<bool,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Unserialize<bool>(CUtlBuffer *buf, CUtlVector<bool,CUtlMemory<bool,int> > *dest)
{
  CUtlBuffer *v2; // ebx
  int Int; // eax
  int v5; // edi
  int v6; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  bool *m_pMemory; // ecx
  int v10; // eax
  int v12; // edi
  int v13; // eax
  bool *v14; // ecx
  int v15; // eax
  int nCount; // [esp+18h] [ebp+Ch]

  v2 = buf;
  dest->m_Size = 0;
  if ( (buf->m_Flags & 1) == 0 )
  {
    Int = CUtlBuffer::GetInt(this: buf);
    v5 = Int;
    nCount = Int;
    if ( Int != 0 )
    {
      CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCapacity(this: dest, num: Int);
      v6 = 0;
      if ( v5 > 0 )
      {
        do
        {
          m_Size = dest->m_Size;
          m_nAllocationCount = dest->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<bool,int>::Grow(this: (CUtlMemory<char,int> *)dest, num: m_Size - m_nAllocationCount + 1);
          ++dest->m_Size;
          m_pMemory = dest->m_Memory.m_pMemory;
          v10 = dest->m_Size - m_Size - 1;
          dest->m_pElements = dest->m_Memory.m_pMemory;
          if ( v10 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: v10);
          if ( !Unserialize(buf, dest: &dest->m_Memory.m_pMemory[v6]) )
            return false;
        }
        while ( ++v6 < nCount );
      }
      v2 = buf;
    }
    return v2->m_Error == 0;
  }
  CUtlBuffer::EatWhiteSpace(this: buf);
  if ( buf->m_Error != 0 )
    return true;
  while ( 1 )
  {
    v12 = dest->m_Size;
    v13 = dest->m_Memory.m_nAllocationCount;
    if ( v12 + 1 > v13 )
      CUtlMemory<bool,int>::Grow(this: (CUtlMemory<char,int> *)dest, num: v12 - v13 + 1);
    ++dest->m_Size;
    v14 = dest->m_Memory.m_pMemory;
    v15 = dest->m_Size - v12 - 1;
    dest->m_pElements = dest->m_Memory.m_pMemory;
    if ( v15 > 0 )
      _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: v15);
    if ( !Unserialize(buf, dest: &dest->m_Memory.m_pMemory[v12]) )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    if ( buf->m_Error != 0 )
      return true;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1024C310
// Name: private: CDmxAttribute::CDmxAttribute(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxAttribute *__thiscall CDmxAttribute::CDmxAttribute(CDmxAttribute *this, const char *pAttributeName)
{
  const char *v4; // [esp-4h] [ebp-8h]

  v4 = pAttributeName;
  this->m_Name.u.m_Id = -1;
  this->m_Name = (CUtlSymbolLarge)CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
                                    this: &CDmxAttribute::s_AttributeNameSymbols,
                                    result: (CUtlSymbolLarge *)&pAttributeName,
                                    pString: v4)->u.m_Id;
  this->m_Type = AT_UNKNOWN;
  this->m_pData = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1024C490
// Name: public: bool CDmxAttribute::Serialize(class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::Serialize(CDmxAttribute *this, CUtlBuffer *buf)
{
  __int32 v2; // eax
  bool result; // al
  bool bSuccess; // [esp+3h] [ebp-1h] BYREF

  v2 = this->m_Type - 2;
  bSuccess = false;
  switch ( v2 )
  {
    case 0:
      CDmxAttribute::SerializeType<int,int>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 1:
      CDmxAttribute::SerializeType<float,float>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 2:
      CDmxAttribute::SerializeType<bool,bool>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 3:
      CDmxAttribute::SerializeType<CUtlString,CUtlString>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 4:
      CDmxAttribute::SerializeType<CUtlBinaryBlock,CUtlBinaryBlock>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 5:
      CDmxAttribute::SerializeType<DmeTime_t,DmeTime_t>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 6:
      CDmxAttribute::SerializeType<Color,Color>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 7:
      CDmxAttribute::SerializeType<Vector2D,Vector2D>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 8:
    case 10:
      CDmxAttribute::SerializeType<Vector,Vector>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 9:
      CDmxAttribute::SerializeType<Vector4D,Vector4D>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 11:
      CDmxAttribute::SerializeType<Quaternion,Quaternion>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 12:
      CDmxAttribute::SerializeType<VMatrix,VMatrix>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 14:
      CDmxAttribute::SerializeType<CUtlVector<int,CUtlMemory<int,int>>,int>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 15:
      CDmxAttribute::SerializeType<CUtlVector<float,CUtlMemory<float,int>>,float>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 16:
      CDmxAttribute::SerializeType<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 17:
      CDmxAttribute::SerializeType<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 18:
      CDmxAttribute::SerializeType<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        this,
        &bSuccess,
        buf);
      result = bSuccess;
      break;
    case 19:
      CDmxAttribute::SerializeType<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 20:
      CDmxAttribute::SerializeType<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 21:
      CDmxAttribute::SerializeType<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 22:
    case 24:
      CDmxAttribute::SerializeType<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 23:
    case 25:
      CDmxAttribute::SerializeType<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 26:
      CDmxAttribute::SerializeType<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(this, &bSuccess, buf);
      goto LABEL_25;
    default:
LABEL_25:
      result = bSuccess;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1024C760
// Name: private: void CDmxAttribute::FreeDataMemory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::FreeDataMemory(CDmxAttribute *this)
{
  if ( this->m_Type != AT_UNKNOWN )
  {
    switch ( this->m_Type )
    {
      case AT_STRING:
      case AT_VOID:
        CDmxAttribute::DestructDataMemory<CUtlBinaryBlock,CUtlBinaryBlock>(this);
        this->m_Type = AT_UNKNOWN;
        break;
      case AT_FIRST_ARRAY_TYPE:
        CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this->m_pData);
        goto $LN130_0;
      case AT_INT_ARRAY:
      case AT_FLOAT_ARRAY:
      case AT_BOOL_ARRAY:
      case AT_TIME_ARRAY:
      case AT_COLOR_ARRAY:
      case AT_VECTOR2_ARRAY:
      case AT_VECTOR3_ARRAY:
      case AT_VECTOR4_ARRAY:
      case AT_QANGLE_ARRAY:
      case AT_QUATERNION_ARRAY:
      case AT_VMATRIX_ARRAY:
        CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this->m_pData);
        this->m_Type = AT_UNKNOWN;
        break;
      case AT_STRING_ARRAY:
      case AT_VOID_ARRAY:
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData);
        this->m_Type = AT_UNKNOWN;
        break;
      default:
$LN130_0:
        this->m_Type = AT_UNKNOWN;
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024C8E0
// Name: private: CDmxAttribute::~CDmxAttribute(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDmxAttribute::~CDmxAttribute(CDmxAttribute *this)
{
  CDmxAttribute::FreeDataMemory(this);
}

//------------------------------------------------------------------------------
// Address: 0x1024C8F0
// Name: private: void CDmxAttribute::AllocateDataMemory(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::AllocateDataMemory(CDmxAttribute *this, DmAttributeType_t type)
{
  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = type;
  this->m_pData = DMXAlloc(size: s_pAttributeSize[type]);
}

//------------------------------------------------------------------------------
// Address: 0x1024C920
// Name: private: void CDmxAttribute::AllocateDataMemory_AndConstruct(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::AllocateDataMemory_AndConstruct(CDmxAttribute *this, DmAttributeType_t type)
{
  CUtlString *v3; // ecx
  __int32 v4; // eax

  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = type;
  v3 = (CUtlString *)DMXAlloc(size: s_pAttributeSize[type]);
  v4 = this->m_Type - 1;
  this->m_pData = v3;
  switch ( v4 )
  {
    case 4:
      if ( v3 != nullptr )
        CUtlString::CUtlString(this: v3);
      break;
    case 5:
      if ( v3 != nullptr )
        CUtlBinaryBlock::CUtlBinaryBlock(this: &v3->m_Storage, growSize: 0, initSize: 0);
      break;
    case 6:
      if ( v3 != nullptr )
        v3->m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)0x80000000;
      break;
    case 7:
      if ( v3 != nullptr )
        v3->m_Storage.m_Memory.m_pMemory = nullptr;
      break;
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
      CDmxAttribute::ConstructDataMemory<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(this);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024CAC0
// Name: public: bool CDmxAttribute::Unserialize(enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::Unserialize(CDmxAttribute *this, DmAttributeType_t type, CUtlBuffer *buf)
{
  bool result; // al

  CDmxAttribute::AllocateDataMemory_AndConstruct(this, type);
  result = false;
  switch ( this->m_Type )
  {
    case AT_INT:
      result = Unserialize(buf, dest: (int *)this->m_pData);
      break;
    case AT_FLOAT:
      result = Unserialize(buf, dest: (float *)this->m_pData);
      break;
    case AT_BOOL:
      result = Unserialize(buf, dest: (bool *)this->m_pData);
      break;
    case AT_STRING:
      result = Unserialize(buf, dest: (CUtlString *)this->m_pData);
      break;
    case AT_VOID:
      result = Unserialize(buf, dest: (CUtlBinaryBlock *)this->m_pData);
      break;
    case AT_TIME:
      result = Unserialize(buf, dest: (DmeTime_t *)this->m_pData);
      break;
    case AT_COLOR:
      result = Unserialize(buf, dest: (Color *)this->m_pData);
      break;
    case AT_VECTOR2:
      result = Unserialize(buf, dest: (Vector2D *)this->m_pData);
      break;
    case AT_VECTOR3:
    case AT_QANGLE:
      result = Unserialize(buf, dest: (QAngle *)this->m_pData);
      break;
    case AT_VECTOR4:
      result = Unserialize(buf, dest: (Vector4D *)this->m_pData);
      break;
    case AT_QUATERNION:
      result = Unserialize(buf, dest: (Quaternion *)this->m_pData);
      break;
    case AT_VMATRIX:
      result = Unserialize(buf, dest: (VMatrix *)this->m_pData);
      break;
    case AT_INT_ARRAY:
      result = Unserialize<int>(buf, dest: (CUtlVector<int,CUtlMemory<int,int> > *)this->m_pData);
      break;
    case AT_FLOAT_ARRAY:
      result = Unserialize<float>(buf, dest: (CUtlVector<float,CUtlMemory<float,int> > *)this->m_pData);
      break;
    case AT_BOOL_ARRAY:
      result = Unserialize<bool>(buf, dest: (CUtlVector<bool,CUtlMemory<bool,int> > *)this->m_pData);
      break;
    case AT_STRING_ARRAY:
      result = Unserialize<CUtlString>(buf, dest: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData);
      break;
    case AT_VOID_ARRAY:
      result = Unserialize<CUtlBinaryBlock>(
                 buf,
                 dest: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData);
      break;
    case AT_TIME_ARRAY:
      result = Unserialize<DmeTime_t>(buf, dest: (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)this->m_pData);
      break;
    case AT_COLOR_ARRAY:
      result = Unserialize<Color>(buf, dest: (CUtlVector<Color,CUtlMemory<Color,int> > *)this->m_pData);
      break;
    case AT_VECTOR2_ARRAY:
      result = Unserialize<Vector2D>(buf, dest: (CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)this->m_pData);
      break;
    case AT_VECTOR3_ARRAY:
    case AT_QANGLE_ARRAY:
      result = Unserialize<QAngle>(buf, dest: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)this->m_pData);
      break;
    case AT_VECTOR4_ARRAY:
      result = Unserialize<Vector4D>(buf, dest: (CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *)this->m_pData);
      break;
    case AT_QUATERNION_ARRAY:
      result = Unserialize<Quaternion>(buf, dest: (CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)this->m_pData);
      break;
    case AT_VMATRIX_ARRAY:
      result = Unserialize<VMatrix>(buf, dest: (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)this->m_pData);
      break;
    default:
      return result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1024CD80
// Name: public: bool CDmxAttribute::UnserializeElement(enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::UnserializeElement(CDmxAttribute *this, DmAttributeType_t type, CUtlBuffer *buf)
{
  bool result; // al
  __int32 v5; // eax

  if ( (unsigned int)(type - 15) > 0xD )
    return false;
  if ( this->m_Type != type )
    CDmxAttribute::AllocateDataMemory_AndConstruct(this, type);
  v5 = this->m_Type - 16;
  HIBYTE(type) = 0;
  switch ( v5 )
  {
    case 0:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<int,CUtlMemory<int,int>>,int>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 1:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<float,CUtlMemory<float,int>>,float>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 2:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 3:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 4:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 5:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 6:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 7:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 8:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 9:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>,Vector4D>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 10:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<QAngle,CUtlMemory<QAngle,int>>,QAngle>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 11:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 12:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      goto LABEL_19;
    default:
LABEL_19:
      result = HIBYTE(type);
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1024CF20
// Name: public: void CDmxAttribute::SetValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetValue(CDmxAttribute *this, const char *pString)
{
  CUtlString *v3; // eax
  CUtlString *v4; // edi

  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = AT_STRING;
  v3 = (CUtlString *)DMXAlloc(size: s_pAttributeSize[5]);
  v4 = v3;
  this->m_pData = v3;
  if ( v3 != nullptr )
    CUtlString::CUtlString(this: v3);
  CUtlString::Set(this: v4, pValue: pString);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00673AA0
// Name: public: static enum DmAttributeType_t CDmxAttribute::ArrayAttributeBasicType(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
DmAttributeType_t __cdecl CDmxAttribute::ArrayAttributeBasicType(DmAttributeType_t type)
{
  DmAttributeType_t result; // eax

  result = type;
  if ( (unsigned int)(type - 15) <= 0xD )
    return type - 14;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00673AC0
// Name: public: char const __near * CDmxAttribute::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxAttribute::GetName(CDmxAttribute *this)
{
  const char *result; // eax

  result = this->m_Name.u.m_pAsString;
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00673AD0
// Name: private: void CDmxAttribute::ConstructDataMemory<class CUtlVector<class Color,class CUtlMemory<class Color,int>>,class Color>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::ConstructDataMemory<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(CDmxAttribute *this)
{
  _DWORD *m_pData; // eax

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    *m_pData = 0;
    m_pData[1] = 0;
    m_pData[2] = 0;
    m_pData[3] = 0;
    m_pData[4] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00673AF0
// Name: private: void CDmxAttribute::DestructDataMemory<class CUtlBinaryBlock,class CUtlBinaryBlock>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::DestructDataMemory<CUtlBinaryBlock,CUtlBinaryBlock>(CDmxAttribute *this)
{
  int *m_pData; // esi
  bool v2; // sf

  m_pData = (int *)this->m_pData;
  v2 = m_pData[2] < 0;
  m_pData[3] = 0;
  if ( !v2 )
  {
    if ( *m_pData != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*m_pData);
      *m_pData = 0;
    }
    m_pData[1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00673B30
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<int,class CUtlMemory<int,int>>,int>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<int,CUtlMemory<int,int>>,int>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  char v4; // al
  CUtlMemory<vgui::TreeNode *,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  v4 = Unserialize(buf, dest: (int *)&buf);
  *bSuccess = v4;
  if ( v4 != 0 )
  {
    m_pData = (CUtlMemory<vgui::TreeNode *,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: m_pData, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
        count: 4 * v9);
    v10 = &m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)buf;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00673BB0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<float,class CUtlMemory<float,int>>,float>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<float,CUtlMemory<float,int>>,float>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  char v4; // al
  CUtlMemory<vgui::TreeNode *,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  v4 = Unserialize(buf, dest: (float *)&buf);
  *bSuccess = v4;
  if ( v4 != 0 )
  {
    m_pData = (CUtlMemory<vgui::TreeNode *,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: m_pData, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
        count: 4 * v9);
    v10 = &m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)buf;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00673C30
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<bool,class CUtlMemory<bool,int>>,bool>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  char v4; // al
  CUtlMemory<unsigned char,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // edi
  unsigned __int8 *v8; // ecx
  signed int v9; // eax
  unsigned __int8 *v10; // esi

  v4 = Unserialize(buf, dest: (bool *)&buf + 3);
  *bSuccess = v4;
  if ( v4 != 0 )
  {
    m_pData = (CUtlMemory<unsigned char,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)(m_pMemory + 1) > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow(this: m_pData, num: (int)&m_pMemory[-m_nAllocationCount + 1]);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = m_pData[1].m_pMemory - m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[(_DWORD)m_pMemory + 1], src: &v8[(_DWORD)m_pMemory], count: v9);
    v10 = &m_pMemory[(unsigned int)m_pData->m_pMemory];
    if ( v10 != nullptr )
      *v10 = HIBYTE(buf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00673CA0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,class CUtlString>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlString temp; // [esp+4h] [ebp-10h] BYREF

  CUtlString::CUtlString(this: &temp);
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
      this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
  temp.m_Storage.m_nActualLength = 0;
  if ( temp.m_Storage.m_Memory.m_nGrowSize >= 0 && temp.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00673D10
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>,class CUtlBinaryBlock>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlBinaryBlock temp; // [esp+4h] [ebp-10h] BYREF

  CUtlBinaryBlock::CUtlBinaryBlock(this: &temp, growSize: 0, initSize: 0);
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
      this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
  temp.m_nActualLength = 0;
  if ( temp.m_Memory.m_nGrowSize >= 0 && temp.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00673D80
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>,class DmeTime_t>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  char v4; // al
  CUtlMemory<vgui::TreeNode *,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  DmeTime_t *v10; // eax
  DmeTime_t temp; // [esp+4h] [ebp-4h] BYREF

  temp.m_tms = 0x80000000;
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 != 0 )
  {
    m_pData = (CUtlMemory<vgui::TreeNode *,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: m_pData, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
        count: 4 * v9);
    v10 = (DmeTime_t *)&m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      v10->m_tms = temp.m_tms;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00673E10
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Color,class CUtlMemory<class Color,int>>,class Color>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlMemory<vgui::TreeNode *,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  Color *v10; // eax
  Color temp; // [esp+4h] [ebp-4h] BYREF

  temp = 0;
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
  {
    m_pData = (CUtlMemory<vgui::TreeNode *,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: m_pData, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
        count: 4 * v9);
    v10 = (Color *)&m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      *v10 = temp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00673EA0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>,class Vector2D>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Vector2D temp; // [esp+4h] [ebp-8h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: (CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x00673EE0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>,class Vector4D>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>,Vector4D>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Vector4D temp; // [esp+4h] [ebp-10h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::InsertBefore(
      this: (CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x00673F20
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector,class CUtlMemory<class Vector,int>>,class Vector>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  QAngle temp; // [esp+4h] [ebp-Ch] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x00673F60
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>,class Quaternion>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Quaternion temp; // [esp+4h] [ebp-10h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertBefore(
      this: (CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x00673FA0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>,class VMatrix>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  VMatrix temp; // [esp+4h] [ebp-40h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x00674150
// Name: private: CDmxAttribute::CDmxAttribute(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxAttribute *__thiscall CDmxAttribute::CDmxAttribute(CDmxAttribute *this, char *pAttributeName)
{
  char *v4; // [esp-4h] [ebp-8h]

  v4 = pAttributeName;
  this->m_Name.u.m_Id = -1;
  this->m_Name = (CUtlSymbolLarge)CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
                                    this: &CDmxAttribute::s_AttributeNameSymbols,
                                    result: (CUtlSymbolLarge *)&pAttributeName,
                                    pString: v4)->u.m_Id;
  this->m_Type = AT_UNKNOWN;
  this->m_pData = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00674190
// Name: public: void CDmxAttribute::SetToDefaultValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetToDefaultValue(CDmxAttribute *this)
{
  _DWORD *m_pData; // ecx
  _DWORD *v2; // ecx
  _DWORD *v3; // ecx
  _DWORD *v4; // ecx

  switch ( this->m_Type )
  {
    case AT_FIRST_VALUE_TYPE:
      *(_DWORD *)this->m_pData = 0;
      break;
    case AT_INT:
    case AT_TIME:
      *(_DWORD *)this->m_pData = 0;
      break;
    case AT_FLOAT:
      *(_DWORD *)this->m_pData = 0;
      break;
    case AT_BOOL:
      *(_BYTE *)this->m_pData = 0;
      break;
    case AT_STRING:
      CUtlString::Set(this: (CUtlString *)this->m_pData, pValue: nullptr);
      break;
    case AT_VOID:
      CUtlBinaryBlock::Set(this: (CUtlBinaryBlock *)this->m_pData, pValue: nullptr, nLen: 0);
      break;
    case AT_COLOR:
      *(_DWORD *)this->m_pData = -16777216;
      break;
    case AT_VECTOR2:
      m_pData = this->m_pData;
      *m_pData = 0;
      m_pData[1] = 0;
      break;
    case AT_VECTOR3:
    case AT_QANGLE:
      v2 = this->m_pData;
      *v2 = 0;
      v2[1] = 0;
      v2[2] = 0;
      break;
    case AT_VECTOR4:
      v3 = this->m_pData;
      *v3 = 0;
      v3[1] = 0;
      v3[2] = 0;
      v3[3] = 0;
      break;
    case AT_QUATERNION:
      v4 = this->m_pData;
      *v4 = 0;
      v4[1] = 0;
      v4[2] = 0;
      v4[3] = 1065353216;
      break;
    case AT_VMATRIX:
      MatrixSetIdentity(dst: (VMatrix *)this->m_pData);
      break;
    case AT_FIRST_ARRAY_TYPE:
    case AT_INT_ARRAY:
    case AT_FLOAT_ARRAY:
    case AT_BOOL_ARRAY:
    case AT_TIME_ARRAY:
    case AT_COLOR_ARRAY:
    case AT_VECTOR2_ARRAY:
    case AT_VECTOR3_ARRAY:
    case AT_VECTOR4_ARRAY:
    case AT_QANGLE_ARRAY:
    case AT_QUATERNION_ARRAY:
    case AT_VMATRIX_ARRAY:
      *((_DWORD *)this->m_pData + 3) = 0;
      break;
    case AT_STRING_ARRAY:
    case AT_VOID_ARRAY:
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006742F0
// Name: private: void CDmxAttribute::FreeDataMemory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::FreeDataMemory(CDmxAttribute *this)
{
  if ( this->m_Type != AT_UNKNOWN )
  {
    switch ( this->m_Type )
    {
      case AT_STRING:
      case AT_VOID:
        CDmxAttribute::DestructDataMemory<CUtlBinaryBlock,CUtlBinaryBlock>(this);
        this->m_Type = AT_UNKNOWN;
        break;
      case AT_FIRST_ARRAY_TYPE:
        CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)this->m_pData);
        goto $LN130_2;
      case AT_INT_ARRAY:
      case AT_FLOAT_ARRAY:
      case AT_BOOL_ARRAY:
      case AT_TIME_ARRAY:
      case AT_COLOR_ARRAY:
      case AT_VECTOR2_ARRAY:
      case AT_VECTOR3_ARRAY:
      case AT_VECTOR4_ARRAY:
      case AT_QANGLE_ARRAY:
      case AT_QUATERNION_ARRAY:
      case AT_VMATRIX_ARRAY:
        CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)this->m_pData);
        this->m_Type = AT_UNKNOWN;
        break;
      case AT_STRING_ARRAY:
      case AT_VOID_ARRAY:
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData);
        this->m_Type = AT_UNKNOWN;
        break;
      default:
$LN130_2:
        this->m_Type = AT_UNKNOWN;
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00674470
// Name: private: CDmxAttribute::~CDmxAttribute(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDmxAttribute::~CDmxAttribute(CDmxAttribute *this)
{
  CDmxAttribute::FreeDataMemory(this);
}

//------------------------------------------------------------------------------
// Address: 0x00674480
// Name: private: void CDmxAttribute::AllocateDataMemory(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::AllocateDataMemory(CDmxAttribute *this, DmAttributeType_t type)
{
  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = type;
  this->m_pData = DMXAlloc(size: s_pAttributeSize[type]);
}

//------------------------------------------------------------------------------
// Address: 0x006744B0
// Name: private: void CDmxAttribute::AllocateDataMemory_AndConstruct(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::AllocateDataMemory_AndConstruct(CDmxAttribute *this, DmAttributeType_t type)
{
  CUtlString *v3; // ecx
  __int32 v4; // eax

  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = type;
  v3 = (CUtlString *)DMXAlloc(size: s_pAttributeSize[type]);
  v4 = this->m_Type - 1;
  this->m_pData = v3;
  switch ( v4 )
  {
    case 4:
      if ( v3 != nullptr )
        CUtlString::CUtlString(this: v3);
      break;
    case 5:
      if ( v3 != nullptr )
        CUtlBinaryBlock::CUtlBinaryBlock(this: &v3->m_Storage, growSize: 0, initSize: 0);
      break;
    case 6:
      if ( v3 != nullptr )
        v3->m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)0x80000000;
      break;
    case 7:
      if ( v3 != nullptr )
        v3->m_Storage.m_Memory.m_pMemory = nullptr;
      break;
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
      CDmxAttribute::ConstructDataMemory<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(this);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00674650
// Name: public: bool CDmxAttribute::Unserialize(enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::Unserialize(CDmxAttribute *this, DmAttributeType_t type, CUtlBuffer *buf)
{
  bool result; // al

  CDmxAttribute::AllocateDataMemory_AndConstruct(this, type);
  result = false;
  switch ( this->m_Type )
  {
    case AT_INT:
      result = Unserialize(buf, dest: (int *)this->m_pData);
      break;
    case AT_FLOAT:
      result = Unserialize(buf, dest: (float *)this->m_pData);
      break;
    case AT_BOOL:
      result = Unserialize(buf, dest: (bool *)this->m_pData);
      break;
    case AT_STRING:
      result = Unserialize(buf, dest: (CUtlString *)this->m_pData);
      break;
    case AT_VOID:
      result = Unserialize(buf, dest: (CUtlBinaryBlock *)this->m_pData);
      break;
    case AT_TIME:
      result = Unserialize(buf, dest: (DmeTime_t *)this->m_pData);
      break;
    case AT_COLOR:
      result = Unserialize(buf, dest: (Color *)this->m_pData);
      break;
    case AT_VECTOR2:
      result = Unserialize(buf, dest: (Vector2D *)this->m_pData);
      break;
    case AT_VECTOR3:
    case AT_QANGLE:
      result = Unserialize(buf, dest: (QAngle *)this->m_pData);
      break;
    case AT_VECTOR4:
      result = Unserialize(buf, dest: (Vector4D *)this->m_pData);
      break;
    case AT_QUATERNION:
      result = Unserialize(buf, dest: (Quaternion *)this->m_pData);
      break;
    case AT_VMATRIX:
      result = Unserialize(buf, dest: (VMatrix *)this->m_pData);
      break;
    case AT_INT_ARRAY:
      result = Unserialize<int>(
                 buf,
                 dest: (CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int> > *)this->m_pData);
      break;
    case AT_FLOAT_ARRAY:
      result = Unserialize<float>(
                 buf,
                 dest: (CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int> > *)this->m_pData);
      break;
    case AT_BOOL_ARRAY:
      result = Unserialize<bool>(
                 buf,
                 dest: (CDmaArrayBase<bool,CDmaDataInternal<CUtlVector<bool,CUtlMemory<bool,int> > > > *)this->m_pData);
      break;
    case AT_STRING_ARRAY:
      result = Unserialize<CUtlString>(buf, dest: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData);
      break;
    case AT_VOID_ARRAY:
      result = Unserialize<CUtlBinaryBlock>(
                 buf,
                 dest: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData);
      break;
    case AT_TIME_ARRAY:
      result = Unserialize<DmeTime_t>(
                 buf,
                 dest: (CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int> > *)this->m_pData);
      break;
    case AT_COLOR_ARRAY:
      result = Unserialize<Color>(
                 buf,
                 dest: (CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int> > *)this->m_pData);
      break;
    case AT_VECTOR2_ARRAY:
      result = Unserialize<Vector2D>(
                 buf,
                 dest: (CUtlVector<DmePickerInfo_t,CUtlMemory<DmePickerInfo_t,int> > *)this->m_pData);
      break;
    case AT_VECTOR3_ARRAY:
    case AT_QANGLE_ARRAY:
      result = Unserialize<QAngle>(
                 buf,
                 dest: (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this->m_pData);
      break;
    case AT_VECTOR4_ARRAY:
      result = Unserialize<Vector4D>(
                 buf,
                 dest: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this->m_pData);
      break;
    case AT_QUATERNION_ARRAY:
      result = Unserialize<Quaternion>(
                 buf,
                 dest: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this->m_pData);
      break;
    case AT_VMATRIX_ARRAY:
      result = Unserialize<VMatrix>(
                 buf,
                 dest: (CDmaArrayBase<VMatrix,CDmaDataInternal<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > > *)this->m_pData);
      break;
    default:
      return result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00674910
// Name: public: bool CDmxAttribute::UnserializeElement(enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::UnserializeElement(CDmxAttribute *this, DmAttributeType_t type, CUtlBuffer *buf)
{
  bool result; // al
  __int32 v5; // eax

  if ( (unsigned int)(type - 15) > 0xD )
    return false;
  if ( this->m_Type != type )
    CDmxAttribute::AllocateDataMemory_AndConstruct(this, type);
  v5 = this->m_Type - 16;
  HIBYTE(type) = 0;
  switch ( v5 )
  {
    case 0:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<int,CUtlMemory<int,int>>,int>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 1:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<float,CUtlMemory<float,int>>,float>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 2:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 3:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 4:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 5:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 6:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 7:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 8:
    case 10:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 9:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>,Vector4D>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 11:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 12:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      goto LABEL_18;
    default:
LABEL_18:
      result = HIBYTE(type);
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00674AB0
// Name: public: void CDmxAttribute::SetValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetValue(CDmxAttribute *this, char *pString)
{
  CUtlString *v3; // eax
  CUtlString *v4; // edi

  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = AT_STRING;
  v3 = (CUtlString *)DMXAlloc(size: s_pAttributeSize[5]);
  v4 = v3;
  this->m_pData = v3;
  if ( v3 != nullptr )
    CUtlString::CUtlString(this: v3);
  CUtlString::Set(this: v4, pValue: pString);
}

//------------------------------------------------------------------------------
// Address: 0x00674B00
// Name: public: void CDmxAttribute::SetValueFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetValueFromString(CDmxAttribute *this, char *pValue)
{
  unsigned int v3; // eax
  CUtlString *v4; // eax
  CUtlString *v5; // edi
  CUtlBuffer buf; // [esp+4h] [ebp-30h] BYREF

  if ( this->m_Type != AT_UNKNOWN )
  {
    if ( this->m_Type == AT_STRING )
    {
      CDmxAttribute::FreeDataMemory(this);
      this->m_Type = AT_STRING;
      v4 = (CUtlString *)DMXAlloc(size: s_pAttributeSize[5]);
      v5 = v4;
      this->m_pData = v4;
      if ( v4 != nullptr )
        CUtlString::CUtlString(this: v4);
      CUtlString::Set(this: v5, pValue);
    }
    else if ( pValue != nullptr && (v3 = _V_strlen(str: pValue)) != 0 )
    {
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: (unsigned __int8 *)pValue, nSize: v3, nFlags: 9u);
      if ( !CDmxAttribute::Unserialize(this, type: this->m_Type, &buf) )
        CDmxAttribute::SetToDefaultValue(this);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
    else
    {
      CDmxAttribute::SetToDefaultValue(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00674BD0
// Name: private: void CDmxAttribute::GetArrayValue(enum DmAttributeType_t,void __near *,int,int,char const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::GetArrayValue(
        CDmxAttribute *this,
        DmAttributeType_t type,
        __m128i *pDest,
        int nDataTypeSize,
        int nDestArrayLength,
        char *pDefaultString)
{
  DmAttributeType_t m_Type; // esi
  int v7; // ebx
  int v8; // edi
  _DWORD *m_pData; // eax
  const __m128i *v10; // eax
  __m128i *v11; // esi
  const __m128i *v12; // ebx
  __m128i *v13; // esi
  int v14; // ebx
  const __m128i *v15; // edi
  CDmxAttribute temp; // [esp+0h] [ebp-14h] BYREF
  DmAttributeType_t v17; // [esp+Ch] [ebp-8h]
  int nSrcStride; // [esp+10h] [ebp-4h]
  DmAttributeType_t typea; // [esp+1Ch] [ebp+8h]

  if ( (unsigned int)(type - 15) <= 0xD )
  {
    m_Type = this->m_Type;
    if ( this->m_Type == type )
    {
      v7 = s_pAttributeSize[type - 14];
      v17 = type - 14;
      nSrcStride = v7;
      if ( nDataTypeSize >= v7 )
        nDataTypeSize = v7;
      v8 = 0;
      if ( (unsigned int)(m_Type - 15) <= 0xD )
      {
        m_pData = this->m_pData;
        if ( m_pData != nullptr )
          v8 = m_pData[3];
      }
      v10 = nullptr;
      switch ( m_Type )
      {
        case AT_FIRST_ARRAY_TYPE:
        case AT_FLOAT_ARRAY:
        case AT_VOID_ARRAY:
        case AT_VECTOR2_ARRAY:
        case AT_QANGLE_ARRAY:
          v10 = *(const __m128i **)this->m_pData;
          break;
        case AT_INT_ARRAY:
        case AT_STRING_ARRAY:
        case AT_COLOR_ARRAY:
        case AT_VECTOR4_ARRAY:
        case AT_VMATRIX_ARRAY:
          v10 = *(const __m128i **)this->m_pData;
          break;
        case AT_BOOL_ARRAY:
        case AT_TIME_ARRAY:
        case AT_VECTOR3_ARRAY:
        case AT_QUATERNION_ARRAY:
          v10 = *(const __m128i **)this->m_pData;
          break;
        default:
          break;
      }
      if ( v8 != 0 && v10 != nullptr )
      {
        if ( v7 == nDataTypeSize )
        {
          memcpy(dst: pDest, src: v10, count: nDataTypeSize * v8);
        }
        else
        {
          v11 = pDest;
          v12 = v10;
          if ( v8 > 0 )
          {
            for ( typea = v8; typea != AT_UNKNOWN; --typea )
            {
              memcpy(dst: v11, src: v12, count: nDataTypeSize);
              v11 = (__m128i *)((char *)v11 + nDataTypeSize);
              v12 = (const __m128i *)((char *)v12 + nSrcStride);
            }
          }
        }
      }
      if ( v8 < nDestArrayLength && pDefaultString != nullptr )
      {
        temp.m_Name.u.m_Id = -1;
        temp.m_Type = AT_UNKNOWN;
        temp.m_pData = nullptr;
        CDmxAttribute::AllocateDataMemory_AndConstruct(this: &temp, type: v17);
        CDmxAttribute::SetValueFromString(this: &temp, pValue: pDefaultString);
        v13 = (__m128i *)((char *)pDest + nDataTypeSize * v8);
        v14 = nDestArrayLength - v8;
        v15 = (const __m128i *)temp.m_pData;
        do
        {
          memcpy(dst: v13, src: v15, count: nDataTypeSize);
          v13 = (__m128i *)((char *)v13 + nDataTypeSize);
          --v14;
        }
        while ( v14 != 0 );
        CDmxAttribute::FreeDataMemory(this: &temp);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00681660
// Name: _dynamic_initializer_for__CDmxAttribute::s_AttributeNameSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxAttribute::s_AttributeNameSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(this: &CDmxAttribute::s_AttributeNameSymbols);
  return atexit(func: dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x00683690
// Name: _dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(this: &CDmxAttribute::s_AttributeNameSymbols);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&CDmxAttribute::s_AttributeNameSymbols.m_StringPools);
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &CDmxAttribute::s_AttributeNameSymbols.m_Lookup);
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmxAttribute::s_AttributeNameSymbols.m_Lookup.m_EntryMemory);
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10249330
// Name: public: char const __near * CDmxAttribute::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxAttribute::GetName(CDmxAttribute *this)
{
  const char *result; // eax

  result = this->m_Name.u.m_pAsString;
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10249340
// Name: private: void CDmxAttribute::SerializeType<int,int>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<int,int>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  int temp; // [esp+0h] [ebp-4h] BYREF

  temp = (int)this;
  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const int *)this->m_pData);
  }
  else
  {
    temp = 0;
    v3 = Serialize(buf, src: &temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10249370
// Name: private: void CDmxAttribute::SerializeType<float,float>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<float,float>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  CDmxAttribute *temp; // [esp+0h] [ebp-4h] BYREF

  temp = this;
  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const float *)this->m_pData);
  }
  else
  {
    temp = nullptr;
    v3 = Serialize(buf, src: (const float *)&temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x102493B0
// Name: private: void CDmxAttribute::SerializeType<bool,bool>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<bool,bool>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  bool temp; // [esp+1h] [ebp-1h] BYREF

  temp = HIBYTE(this);
  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const bool *)this->m_pData);
  }
  else
  {
    temp = false;
    v3 = Serialize(buf, src: &temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x102495C0
// Name: public: int CDmxAttribute::GetArrayCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxAttribute::GetArrayCount(CDmxAttribute *this)
{
  DmAttributeType_t m_Type; // edx
  int result; // eax
  _DWORD *m_pData; // ecx

  m_Type = this->m_Type;
  result = 0;
  if ( (unsigned int)(this->m_Type - 15) <= 0xD )
  {
    m_pData = this->m_pData;
    if ( m_pData != nullptr )
    {
      switch ( m_Type )
      {
        case AT_FIRST_ARRAY_TYPE:
        case AT_INT_ARRAY:
        case AT_FLOAT_ARRAY:
        case AT_BOOL_ARRAY:
        case AT_STRING_ARRAY:
        case AT_VOID_ARRAY:
        case AT_TIME_ARRAY:
        case AT_COLOR_ARRAY:
        case AT_VECTOR2_ARRAY:
        case AT_VECTOR3_ARRAY:
        case AT_VECTOR4_ARRAY:
        case AT_QANGLE_ARRAY:
        case AT_QUATERNION_ARRAY:
        case AT_VMATRIX_ARRAY:
          result = m_pData[3];
          break;
        default:
          return result;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10249620
// Name: public: bool CDmxAttribute::SerializesOnMultipleLines(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::SerializesOnMultipleLines(CDmxAttribute *this)
{
  bool result; // al

  result = false;
  switch ( this->m_Type )
  {
    case AT_FIRST_VALUE_TYPE:
    case AT_INT:
    case AT_FLOAT:
    case AT_BOOL:
    case AT_STRING:
    case AT_TIME:
    case AT_COLOR:
    case AT_VECTOR2:
    case AT_VECTOR3:
    case AT_VECTOR4:
    case AT_QANGLE:
    case AT_QUATERNION:
    case AT_FIRST_ARRAY_TYPE:
    case AT_INT_ARRAY:
    case AT_FLOAT_ARRAY:
    case AT_BOOL_ARRAY:
    case AT_STRING_ARRAY:
    case AT_VOID_ARRAY:
    case AT_TIME_ARRAY:
    case AT_COLOR_ARRAY:
    case AT_VECTOR2_ARRAY:
    case AT_VECTOR3_ARRAY:
    case AT_VECTOR4_ARRAY:
    case AT_QANGLE_ARRAY:
    case AT_QUATERNION_ARRAY:
    case AT_VMATRIX_ARRAY:
      result = false;
      break;
    case AT_VOID:
    case AT_VMATRIX:
      result = true;
      break;
    default:
      return result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1024A040
// Name: bool Serialize<int>(class CUtlBuffer __near &,class CUtlVector<int,class CUtlMemory<int,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Serialize<int>(CUtlBuffer *buf, const CUtlVector<int,CUtlMemory<int,int> > *src)
{
  int m_Size; // ebx
  int v3; // edi
  int i; // edi
  int m_Put; // eax

  m_Size = src->m_Size;
  if ( (buf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::PutChar(this: buf, c: 10);
    for ( i = 0; i < m_Size; ++i )
    {
      Serialize(buf, src: &src->m_Memory.m_pMemory[i]);
      if ( s_pUtlBufferUtilArrayDelim != nullptr && i != m_Size - 1 )
        CUtlBuffer::PutString(this: buf, pString: s_pUtlBufferUtilArrayDelim);
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
      {
        buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
        CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
      }
    }
    return buf->m_Error == 0;
  }
  CUtlBuffer::PutTypeBin<int>(this: buf, src: src->m_Size);
  v3 = 0;
  if ( m_Size <= 0 )
    return buf->m_Error == 0;
  do
    Serialize(buf, src: &src->m_Memory.m_pMemory[v3++]);
  while ( v3 < m_Size );
  return buf->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1024A120
// Name: bool Serialize<float>(class CUtlBuffer __near &,class CUtlVector<float,class CUtlMemory<float,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Serialize<float>(CUtlBuffer *buf, const CUtlVector<float,CUtlMemory<float,int> > *src)
{
  int m_Size; // ebx
  int v3; // edi
  int i; // edi
  int m_Put; // eax

  m_Size = src->m_Size;
  if ( (buf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::PutChar(this: buf, c: 10);
    for ( i = 0; i < m_Size; ++i )
    {
      Serialize(buf, src: &src->m_Memory.m_pMemory[i]);
      if ( s_pUtlBufferUtilArrayDelim != nullptr && i != m_Size - 1 )
        CUtlBuffer::PutString(this: buf, pString: s_pUtlBufferUtilArrayDelim);
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
      {
        buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
        CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
      }
    }
    return buf->m_Error == 0;
  }
  CUtlBuffer::PutTypeBin<int>(this: buf, src: src->m_Size);
  v3 = 0;
  if ( m_Size <= 0 )
    return buf->m_Error == 0;
  do
    Serialize(buf, src: &src->m_Memory.m_pMemory[v3++]);
  while ( v3 < m_Size );
  return buf->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1024A200
// Name: bool Serialize<bool>(class CUtlBuffer __near &,class CUtlVector<bool,class CUtlMemory<bool,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Serialize<bool>(CUtlBuffer *buf, const CUtlVector<bool,CUtlMemory<bool,int> > *src)
{
  int m_Size; // ebx
  int v3; // edi
  int i; // edi
  int m_Put; // eax

  m_Size = src->m_Size;
  if ( (buf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::PutChar(this: buf, c: 10);
    for ( i = 0; i < m_Size; ++i )
    {
      Serialize(buf, src: &src->m_Memory.m_pMemory[i]);
      if ( s_pUtlBufferUtilArrayDelim != nullptr && i != m_Size - 1 )
        CUtlBuffer::PutString(this: buf, pString: s_pUtlBufferUtilArrayDelim);
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
      {
        buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
        CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
      }
    }
    return buf->m_Error == 0;
  }
  CUtlBuffer::PutTypeBin<int>(this: buf, src: src->m_Size);
  v3 = 0;
  if ( m_Size <= 0 )
    return buf->m_Error == 0;
  do
    Serialize(buf, src: &src->m_Memory.m_pMemory[v3++]);
  while ( v3 < m_Size );
  return buf->m_Error == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1024AA30
// Name: public: bool CDmxAttribute::SerializeElement(int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::SerializeElement(CDmxAttribute *this, DmeTime_t nIndex, CUtlBuffer *buf)
{
  DmAttributeType_t m_Type; // eax
  bool result; // al
  bool bSuccess; // [esp+1h] [ebp-1h] BYREF

  bSuccess = HIBYTE(this);
  m_Type = this->m_Type;
  if ( (unsigned int)(this->m_Type - 15) > 0xD )
    return false;
  bSuccess = false;
  switch ( m_Type )
  {
    case AT_INT_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<int,CUtlMemory<int,int>>,int>(
        this,
        &bSuccess,
        nIndex: nIndex.m_tms,
        buf);
      result = bSuccess;
      break;
    case AT_FLOAT_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<float,CUtlMemory<float,int>>,float>(
        this,
        &bSuccess,
        nIndex: nIndex.m_tms,
        buf);
      result = bSuccess;
      break;
    case AT_BOOL_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        this,
        &bSuccess,
        nIndex: nIndex.m_tms,
        buf);
      result = bSuccess;
      break;
    case AT_STRING_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        this,
        &bSuccess,
        nIndex: nIndex.m_tms,
        buf);
      result = bSuccess;
      break;
    case AT_VOID_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        this,
        &bSuccess,
        nIndex: nIndex.m_tms,
        buf);
      result = bSuccess;
      break;
    case AT_TIME_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        this,
        &bSuccess,
        nIndex,
        buf);
      result = bSuccess;
      break;
    case AT_COLOR_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        this,
        &bSuccess,
        nIndex: nIndex.m_tms,
        buf);
      result = bSuccess;
      break;
    case AT_VECTOR2_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        this,
        &bSuccess,
        nIndex: nIndex.m_tms,
        buf);
      result = bSuccess;
      break;
    case AT_VECTOR3_ARRAY:
    case AT_QANGLE_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<QAngle,CUtlMemory<QAngle,int>>,QAngle>(
        this,
        &bSuccess,
        nIndex: nIndex.m_tms,
        buf);
      result = bSuccess;
      break;
    case AT_VECTOR4_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>,Vector4D>(
        this,
        &bSuccess,
        nIndex: nIndex.m_tms,
        buf);
      result = bSuccess;
      break;
    case AT_QUATERNION_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        this,
        &bSuccess,
        nIndex: nIndex.m_tms,
        buf);
      result = bSuccess;
      break;
    case AT_VMATRIX_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        this,
        &bSuccess,
        nIndex: nIndex.m_tms,
        buf);
      goto LABEL_16;
    default:
LABEL_16:
      result = bSuccess;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1024B480
// Name: bool Unserialize<int>(class CUtlBuffer __near &,class CUtlVector<int,class CUtlMemory<int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Unserialize<int>(CUtlBuffer *buf, CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *dest)
{
  CUtlBuffer *v2; // ebx
  int Int; // eax
  int v5; // edi
  int v6; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *p_m_tms; // ecx
  int v10; // eax
  int v12; // edi
  int v13; // eax
  int *v14; // ecx
  int v15; // eax
  int nCount; // [esp+18h] [ebp+Ch]

  v2 = buf;
  dest->m_Size = 0;
  if ( (buf->m_Flags & 1) == 0 )
  {
    Int = CUtlBuffer::GetInt(this: buf);
    v5 = Int;
    nCount = Int;
    if ( Int != 0 )
    {
      CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(this: dest, num: Int);
      v6 = 0;
      if ( v5 > 0 )
      {
        do
        {
          m_Size = dest->m_Size;
          m_nAllocationCount = dest->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<INetMessage *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)dest,
              num: m_Size - m_nAllocationCount + 1);
          ++dest->m_Size;
          p_m_tms = &dest->m_Memory.m_pMemory->m_tms;
          v10 = dest->m_Size - m_Size - 1;
          dest->m_pElements = dest->m_Memory.m_pMemory;
          if ( v10 > 0 )
            _V_memmove(dest: &p_m_tms[m_Size + 1], src: &p_m_tms[m_Size], count: 4 * v10);
          if ( !Unserialize(buf, dest: &dest->m_Memory.m_pMemory[v6].m_tms) )
            return false;
        }
        while ( ++v6 < nCount );
      }
      v2 = buf;
    }
    return v2->m_Error == 0;
  }
  CUtlBuffer::EatWhiteSpace(this: buf);
  if ( buf->m_Error != 0 )
    return true;
  while ( 1 )
  {
    v12 = dest->m_Size;
    v13 = dest->m_Memory.m_nAllocationCount;
    if ( v12 + 1 > v13 )
      CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)dest, num: v12 - v13 + 1);
    ++dest->m_Size;
    v14 = &dest->m_Memory.m_pMemory->m_tms;
    v15 = dest->m_Size - v12 - 1;
    dest->m_pElements = dest->m_Memory.m_pMemory;
    if ( v15 > 0 )
      _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 4 * v15);
    if ( !Unserialize(buf, dest: &dest->m_Memory.m_pMemory[v12].m_tms) )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    if ( buf->m_Error != 0 )
      return true;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1024B5C0
// Name: bool Unserialize<float>(class CUtlBuffer __near &,class CUtlVector<float,class CUtlMemory<float,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Unserialize<float>(CUtlBuffer *buf, CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *dest)
{
  CUtlBuffer *v2; // ebx
  int Int; // eax
  int v5; // edi
  int v6; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  float *p_m_tms; // ecx
  int v10; // eax
  int v12; // edi
  int v13; // eax
  float *v14; // ecx
  int v15; // eax
  int nCount; // [esp+18h] [ebp+Ch]

  v2 = buf;
  dest->m_Size = 0;
  if ( (buf->m_Flags & 1) == 0 )
  {
    Int = CUtlBuffer::GetInt(this: buf);
    v5 = Int;
    nCount = Int;
    if ( Int != 0 )
    {
      CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(this: dest, num: Int);
      v6 = 0;
      if ( v5 > 0 )
      {
        do
        {
          m_Size = dest->m_Size;
          m_nAllocationCount = dest->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<INetMessage *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)dest,
              num: m_Size - m_nAllocationCount + 1);
          ++dest->m_Size;
          p_m_tms = (float *)&dest->m_Memory.m_pMemory->m_tms;
          v10 = dest->m_Size - m_Size - 1;
          dest->m_pElements = dest->m_Memory.m_pMemory;
          if ( v10 > 0 )
            _V_memmove(dest: &p_m_tms[m_Size + 1], src: &p_m_tms[m_Size], count: 4 * v10);
          if ( !Unserialize(buf, dest: (float *)&dest->m_Memory.m_pMemory[v6].m_tms) )
            return false;
        }
        while ( ++v6 < nCount );
      }
      v2 = buf;
    }
    return v2->m_Error == 0;
  }
  CUtlBuffer::EatWhiteSpace(this: buf);
  if ( buf->m_Error != 0 )
    return true;
  while ( 1 )
  {
    v12 = dest->m_Size;
    v13 = dest->m_Memory.m_nAllocationCount;
    if ( v12 + 1 > v13 )
      CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)dest, num: v12 - v13 + 1);
    ++dest->m_Size;
    v14 = (float *)&dest->m_Memory.m_pMemory->m_tms;
    v15 = dest->m_Size - v12 - 1;
    dest->m_pElements = dest->m_Memory.m_pMemory;
    if ( v15 > 0 )
      _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 4 * v15);
    if ( !Unserialize(buf, dest: (float *)&dest->m_Memory.m_pMemory[v12].m_tms) )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    if ( buf->m_Error != 0 )
      return true;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1024B700
// Name: bool Unserialize<bool>(class CUtlBuffer __near &,class CUtlVector<bool,class CUtlMemory<bool,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Unserialize<bool>(CUtlBuffer *buf, CUtlVector<bool,CUtlMemory<bool,int> > *dest)
{
  CUtlBuffer *v2; // ebx
  int Int; // eax
  int v5; // edi
  int v6; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  bool *m_pMemory; // ecx
  int v10; // eax
  int v12; // edi
  int v13; // eax
  bool *v14; // ecx
  int v15; // eax
  int nCount; // [esp+18h] [ebp+Ch]

  v2 = buf;
  dest->m_Size = 0;
  if ( (buf->m_Flags & 1) == 0 )
  {
    Int = CUtlBuffer::GetInt(this: buf);
    v5 = Int;
    nCount = Int;
    if ( Int != 0 )
    {
      CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCapacity(this: dest, num: Int);
      v6 = 0;
      if ( v5 > 0 )
      {
        do
        {
          m_Size = dest->m_Size;
          m_nAllocationCount = dest->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<bool,int>::Grow(this: (CUtlMemory<char,int> *)dest, num: m_Size - m_nAllocationCount + 1);
          ++dest->m_Size;
          m_pMemory = dest->m_Memory.m_pMemory;
          v10 = dest->m_Size - m_Size - 1;
          dest->m_pElements = dest->m_Memory.m_pMemory;
          if ( v10 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: v10);
          if ( !Unserialize(buf, dest: &dest->m_Memory.m_pMemory[v6]) )
            return false;
        }
        while ( ++v6 < nCount );
      }
      v2 = buf;
    }
    return v2->m_Error == 0;
  }
  CUtlBuffer::EatWhiteSpace(this: buf);
  if ( buf->m_Error != 0 )
    return true;
  while ( 1 )
  {
    v12 = dest->m_Size;
    v13 = dest->m_Memory.m_nAllocationCount;
    if ( v12 + 1 > v13 )
      CUtlMemory<bool,int>::Grow(this: (CUtlMemory<char,int> *)dest, num: v12 - v13 + 1);
    ++dest->m_Size;
    v14 = dest->m_Memory.m_pMemory;
    v15 = dest->m_Size - v12 - 1;
    dest->m_pElements = dest->m_Memory.m_pMemory;
    if ( v15 > 0 )
      _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: v15);
    if ( !Unserialize(buf, dest: &dest->m_Memory.m_pMemory[v12]) )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    if ( buf->m_Error != 0 )
      return true;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1024C400
// Name: private: CDmxAttribute::CDmxAttribute(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxAttribute *__thiscall CDmxAttribute::CDmxAttribute(CDmxAttribute *this, char *pAttributeName)
{
  char *v4; // [esp-4h] [ebp-8h]

  v4 = pAttributeName;
  this->m_Name.u.m_Id = -1;
  this->m_Name = (CUtlSymbolLarge)CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
                                    this: &CDmxAttribute::s_AttributeNameSymbols,
                                    result: (CUtlSymbolLarge *)&pAttributeName,
                                    pString: v4)->u.m_Id;
  this->m_Type = AT_UNKNOWN;
  this->m_pData = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1024C580
// Name: public: bool CDmxAttribute::Serialize(class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::Serialize(CDmxAttribute *this, CUtlBuffer *buf)
{
  __int32 v2; // eax
  bool result; // al
  bool bSuccess; // [esp+3h] [ebp-1h] BYREF

  v2 = this->m_Type - 2;
  bSuccess = false;
  switch ( v2 )
  {
    case 0:
      CDmxAttribute::SerializeType<int,int>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 1:
      CDmxAttribute::SerializeType<float,float>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 2:
      CDmxAttribute::SerializeType<bool,bool>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 3:
      CDmxAttribute::SerializeType<CUtlString,CUtlString>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 4:
      CDmxAttribute::SerializeType<CUtlBinaryBlock,CUtlBinaryBlock>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 5:
      CDmxAttribute::SerializeType<DmeTime_t,DmeTime_t>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 6:
      CDmxAttribute::SerializeType<Color,Color>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 7:
      CDmxAttribute::SerializeType<Vector2D,Vector2D>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 8:
    case 10:
      CDmxAttribute::SerializeType<Vector,Vector>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 9:
      CDmxAttribute::SerializeType<Vector4D,Vector4D>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 11:
      CDmxAttribute::SerializeType<Quaternion,Quaternion>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 12:
      CDmxAttribute::SerializeType<VMatrix,VMatrix>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 14:
      CDmxAttribute::SerializeType<CUtlVector<int,CUtlMemory<int,int>>,int>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 15:
      CDmxAttribute::SerializeType<CUtlVector<float,CUtlMemory<float,int>>,float>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 16:
      CDmxAttribute::SerializeType<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 17:
      CDmxAttribute::SerializeType<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 18:
      CDmxAttribute::SerializeType<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        this,
        &bSuccess,
        buf);
      result = bSuccess;
      break;
    case 19:
      CDmxAttribute::SerializeType<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 20:
      CDmxAttribute::SerializeType<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 21:
      CDmxAttribute::SerializeType<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 22:
    case 24:
      CDmxAttribute::SerializeType<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 23:
    case 25:
      CDmxAttribute::SerializeType<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 26:
      CDmxAttribute::SerializeType<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(this, &bSuccess, buf);
      goto LABEL_25;
    default:
LABEL_25:
      result = bSuccess;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1024C850
// Name: private: void CDmxAttribute::FreeDataMemory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::FreeDataMemory(CDmxAttribute *this)
{
  if ( this->m_Type != AT_UNKNOWN )
  {
    switch ( this->m_Type )
    {
      case AT_STRING:
      case AT_VOID:
        CDmxAttribute::DestructDataMemory<CUtlBinaryBlock,CUtlBinaryBlock>(this);
        this->m_Type = AT_UNKNOWN;
        break;
      case AT_FIRST_ARRAY_TYPE:
        CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this->m_pData);
        goto $LN130_0;
      case AT_INT_ARRAY:
      case AT_FLOAT_ARRAY:
      case AT_BOOL_ARRAY:
      case AT_TIME_ARRAY:
      case AT_COLOR_ARRAY:
      case AT_VECTOR2_ARRAY:
      case AT_VECTOR3_ARRAY:
      case AT_VECTOR4_ARRAY:
      case AT_QANGLE_ARRAY:
      case AT_QUATERNION_ARRAY:
      case AT_VMATRIX_ARRAY:
        CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this->m_pData);
        this->m_Type = AT_UNKNOWN;
        break;
      case AT_STRING_ARRAY:
      case AT_VOID_ARRAY:
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData);
        this->m_Type = AT_UNKNOWN;
        break;
      default:
$LN130_0:
        this->m_Type = AT_UNKNOWN;
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024C9D0
// Name: private: CDmxAttribute::~CDmxAttribute(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDmxAttribute::~CDmxAttribute(CDmxAttribute *this)
{
  CDmxAttribute::FreeDataMemory(this);
}

//------------------------------------------------------------------------------
// Address: 0x1024C9E0
// Name: private: void CDmxAttribute::AllocateDataMemory(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::AllocateDataMemory(CDmxAttribute *this, DmAttributeType_t type)
{
  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = type;
  this->m_pData = DMXAlloc(size: s_pAttributeSize[type]);
}

//------------------------------------------------------------------------------
// Address: 0x1024CA10
// Name: private: void CDmxAttribute::AllocateDataMemory_AndConstruct(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::AllocateDataMemory_AndConstruct(CDmxAttribute *this, DmAttributeType_t type)
{
  CUtlString *v3; // ecx
  __int32 v4; // eax

  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = type;
  v3 = (CUtlString *)DMXAlloc(size: s_pAttributeSize[type]);
  v4 = this->m_Type - 1;
  this->m_pData = v3;
  switch ( v4 )
  {
    case 4:
      if ( v3 != nullptr )
        CUtlString::CUtlString(this: v3);
      break;
    case 5:
      if ( v3 != nullptr )
        CUtlBinaryBlock::CUtlBinaryBlock(this: &v3->m_Storage, growSize: 0, initSize: 0);
      break;
    case 6:
      if ( v3 != nullptr )
        v3->m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)0x80000000;
      break;
    case 7:
      if ( v3 != nullptr )
        v3->m_Storage.m_Memory.m_pMemory = nullptr;
      break;
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
      CDmxAttribute::ConstructDataMemory<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(this);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024CBB0
// Name: public: bool CDmxAttribute::Unserialize(enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::Unserialize(CDmxAttribute *this, DmAttributeType_t type, CUtlBuffer *buf)
{
  bool result; // al

  CDmxAttribute::AllocateDataMemory_AndConstruct(this, type);
  result = false;
  switch ( this->m_Type )
  {
    case AT_INT:
      result = Unserialize(buf, dest: (int *)this->m_pData);
      break;
    case AT_FLOAT:
      result = Unserialize(buf, dest: (float *)this->m_pData);
      break;
    case AT_BOOL:
      result = Unserialize(buf, dest: (bool *)this->m_pData);
      break;
    case AT_STRING:
      result = Unserialize(buf, dest: (CUtlString *)this->m_pData);
      break;
    case AT_VOID:
      result = Unserialize(buf, dest: (CUtlBinaryBlock *)this->m_pData);
      break;
    case AT_TIME:
      result = Unserialize(buf, dest: (DmeTime_t *)this->m_pData);
      break;
    case AT_COLOR:
      result = Unserialize(buf, dest: (Color *)this->m_pData);
      break;
    case AT_VECTOR2:
      result = Unserialize(buf, dest: (Vector2D *)this->m_pData);
      break;
    case AT_VECTOR3:
    case AT_QANGLE:
      result = Unserialize(buf, dest: (QAngle *)this->m_pData);
      break;
    case AT_VECTOR4:
      result = Unserialize(buf, dest: (Vector4D *)this->m_pData);
      break;
    case AT_QUATERNION:
      result = Unserialize(buf, dest: (Quaternion *)this->m_pData);
      break;
    case AT_VMATRIX:
      result = Unserialize(buf, dest: (VMatrix *)this->m_pData);
      break;
    case AT_INT_ARRAY:
      result = Unserialize<int>(buf, dest: (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)this->m_pData);
      break;
    case AT_FLOAT_ARRAY:
      result = Unserialize<float>(buf, dest: (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)this->m_pData);
      break;
    case AT_BOOL_ARRAY:
      result = Unserialize<bool>(buf, dest: (CUtlVector<bool,CUtlMemory<bool,int> > *)this->m_pData);
      break;
    case AT_STRING_ARRAY:
      result = Unserialize<CUtlString>(buf, dest: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData);
      break;
    case AT_VOID_ARRAY:
      result = Unserialize<CUtlBinaryBlock>(
                 buf,
                 dest: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData);
      break;
    case AT_TIME_ARRAY:
      result = Unserialize<DmeTime_t>(buf, dest: (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)this->m_pData);
      break;
    case AT_COLOR_ARRAY:
      result = Unserialize<Color>(buf, dest: (CUtlVector<Color,CUtlMemory<Color,int> > *)this->m_pData);
      break;
    case AT_VECTOR2_ARRAY:
      result = Unserialize<Vector2D>(buf, dest: (CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)this->m_pData);
      break;
    case AT_VECTOR3_ARRAY:
    case AT_QANGLE_ARRAY:
      result = Unserialize<QAngle>(buf, dest: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)this->m_pData);
      break;
    case AT_VECTOR4_ARRAY:
      result = Unserialize<Vector4D>(buf, dest: (CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *)this->m_pData);
      break;
    case AT_QUATERNION_ARRAY:
      result = Unserialize<Quaternion>(buf, dest: (CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)this->m_pData);
      break;
    case AT_VMATRIX_ARRAY:
      result = Unserialize<VMatrix>(buf, dest: (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)this->m_pData);
      break;
    default:
      return result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1024CE70
// Name: public: bool CDmxAttribute::UnserializeElement(enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::UnserializeElement(CDmxAttribute *this, DmAttributeType_t type, CUtlBuffer *buf)
{
  bool result; // al
  __int32 v5; // eax

  if ( (unsigned int)(type - 15) > 0xD )
    return false;
  if ( this->m_Type != type )
    CDmxAttribute::AllocateDataMemory_AndConstruct(this, type);
  v5 = this->m_Type - 16;
  HIBYTE(type) = 0;
  switch ( v5 )
  {
    case 0:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<int,CUtlMemory<int,int>>,int>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 1:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<float,CUtlMemory<float,int>>,float>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 2:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 3:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 4:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 5:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 6:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 7:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 8:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 9:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>,Vector4D>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 10:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<QAngle,CUtlMemory<QAngle,int>>,QAngle>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 11:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 12:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      goto LABEL_19;
    default:
LABEL_19:
      result = HIBYTE(type);
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1024D010
// Name: public: void CDmxAttribute::SetValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetValue(CDmxAttribute *this, const char *pString)
{
  CUtlString *v3; // eax
  CUtlString *v4; // edi

  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = AT_STRING;
  v3 = (CUtlString *)DMXAlloc(size: s_pAttributeSize[5]);
  v4 = v3;
  this->m_pData = v3;
  if ( v3 != nullptr )
    CUtlString::CUtlString(this: v3);
  CUtlString::Set(this: v4, pValue: pString);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104C14F0
// Name: public: static enum DmAttributeType_t CDmxAttribute::ArrayAttributeBasicType(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
DmAttributeType_t __cdecl CDmxAttribute::ArrayAttributeBasicType(DmAttributeType_t type)
{
  DmAttributeType_t result; // eax

  result = type;
  if ( (unsigned int)(type - 15) <= 0xD )
    return type - 14;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104C1510
// Name: public: char const __near * CDmxAttribute::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxAttribute::GetName(CDmxAttribute *this)
{
  const char *result; // eax

  result = this->m_Name.u.m_pAsString;
  if ( result == (const char *)-1 )
    return &var;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104C1520
// Name: private: void CDmxAttribute::ConstructDataMemory<class CUtlVector<class Color,class CUtlMemory<class Color,int>>,class Color>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::ConstructDataMemory<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(CDmxAttribute *this)
{
  _DWORD *m_pData; // eax

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    *m_pData = 0;
    m_pData[1] = 0;
    m_pData[2] = 0;
    m_pData[3] = 0;
    m_pData[4] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C1540
// Name: private: void CDmxAttribute::DestructDataMemory<class CUtlBinaryBlock,class CUtlBinaryBlock>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::DestructDataMemory<CUtlBinaryBlock,CUtlBinaryBlock>(CDmxAttribute *this)
{
  int *m_pData; // esi
  bool v2; // sf

  m_pData = (int *)this->m_pData;
  v2 = m_pData[2] < 0;
  m_pData[3] = 0;
  if ( !v2 )
  {
    if ( *m_pData != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*m_pData);
      *m_pData = 0;
    }
    m_pData[1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C1580
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<int,class CUtlMemory<int,int>>,int>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<int,CUtlMemory<int,int>>,int>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  char v4; // al
  CUtlMemory<vgui::TreeNode *,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  v4 = Unserialize(buf, dest: (int *)&buf);
  *bSuccess = v4;
  if ( v4 != 0 )
  {
    m_pData = (CUtlMemory<vgui::TreeNode *,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: m_pData, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
        count: 4 * v9);
    v10 = &m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)buf;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C1600
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<float,class CUtlMemory<float,int>>,float>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<float,CUtlMemory<float,int>>,float>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  char v4; // al
  CUtlMemory<vgui::TreeNode *,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  v4 = Unserialize(buf, dest: (float *)&buf);
  *bSuccess = v4;
  if ( v4 != 0 )
  {
    m_pData = (CUtlMemory<vgui::TreeNode *,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: m_pData, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
        count: 4 * v9);
    v10 = &m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)buf;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C1680
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<bool,class CUtlMemory<bool,int>>,bool>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  char v4; // al
  CUtlMemory<char,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  char *m_pMemory; // edi
  char *v8; // ecx
  signed int v9; // eax
  char *v10; // esi

  v4 = Unserialize(buf, dest: (bool *)&buf + 3);
  *bSuccess = v4;
  if ( v4 != 0 )
  {
    m_pData = (CUtlMemory<char,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)(m_pMemory + 1) > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow(this: m_pData, num: (int)&m_pMemory[-m_nAllocationCount + 1]);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = m_pData[1].m_pMemory - m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
        count: v9);
    v10 = &m_pMemory[(unsigned int)m_pData->m_pMemory];
    if ( v10 != nullptr )
      *v10 = HIBYTE(buf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C16F0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,class CUtlString>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlString temp; // [esp+4h] [ebp-10h] BYREF

  CUtlString::CUtlString(this: &temp);
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
      this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
  temp.m_Storage.m_nActualLength = 0;
  if ( temp.m_Storage.m_Memory.m_nGrowSize >= 0 && temp.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x104C1760
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>,class CUtlBinaryBlock>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlBinaryBlock temp; // [esp+4h] [ebp-10h] BYREF

  CUtlBinaryBlock::CUtlBinaryBlock(this: &temp, growSize: 0, initSize: 0);
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
      this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
  temp.m_nActualLength = 0;
  if ( temp.m_Memory.m_nGrowSize >= 0 && temp.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x104C17D0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>,class DmeTime_t>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  char v4; // al
  CUtlMemory<vgui::TreeNode *,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  DmeTime_t *v10; // eax
  DmeTime_t temp; // [esp+4h] [ebp-4h] BYREF

  temp.m_tms = 0x80000000;
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 != 0 )
  {
    m_pData = (CUtlMemory<vgui::TreeNode *,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: m_pData, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
        count: 4 * v9);
    v10 = (DmeTime_t *)&m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      v10->m_tms = temp.m_tms;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C1860
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Color,class CUtlMemory<class Color,int>>,class Color>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlMemory<vgui::TreeNode *,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  Color *v10; // eax
  Color temp; // [esp+4h] [ebp-4h] BYREF

  temp = 0;
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
  {
    m_pData = (CUtlMemory<vgui::TreeNode *,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: m_pData, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
        count: 4 * v9);
    v10 = (Color *)&m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      *v10 = temp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C18F0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>,class Vector2D>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Vector2D temp; // [esp+4h] [ebp-8h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: (CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x104C1930
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector,class CUtlMemory<class Vector,int>>,class Vector>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Vector temp; // [esp+4h] [ebp-Ch] BYREF

  v4 = Unserialize(buf, dest: (QAngle *)&temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x104C1970
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>,class Vector4D>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>,Vector4D>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Vector4D temp; // [esp+4h] [ebp-10h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::InsertBefore(
      this: (CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x104C19B0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>>,class QAngle>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<QAngle,CUtlMemory<QAngle,int>>,QAngle>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  QAngle temp; // [esp+4h] [ebp-Ch] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertBefore(
      this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x104C19F0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>,class Quaternion>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Quaternion temp; // [esp+4h] [ebp-10h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertBefore(
      this: (CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x104C1A30
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>,class VMatrix>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  VMatrix temp; // [esp+4h] [ebp-40h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x104C1BE0
// Name: private: CDmxAttribute::CDmxAttribute(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxAttribute *__thiscall CDmxAttribute::CDmxAttribute(CDmxAttribute *this, char *pAttributeName)
{
  char *v4; // [esp-4h] [ebp-8h]

  v4 = pAttributeName;
  this->m_Name.u.m_Id = -1;
  this->m_Name = (CUtlSymbolLarge)CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
                                    this: &CDmxAttribute::s_AttributeNameSymbols,
                                    result: (CUtlSymbolLarge *)&pAttributeName,
                                    pString: v4)->u.m_Id;
  this->m_Type = AT_UNKNOWN;
  this->m_pData = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104C1C20
// Name: public: void CDmxAttribute::SetToDefaultValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetToDefaultValue(CDmxAttribute *this)
{
  _DWORD *m_pData; // ecx
  _DWORD *v2; // ecx
  _DWORD *v3; // ecx
  _DWORD *v4; // ecx

  switch ( this->m_Type )
  {
    case AT_FIRST_VALUE_TYPE:
      *(_DWORD *)this->m_pData = 0;
      break;
    case AT_INT:
    case AT_TIME:
      *(_DWORD *)this->m_pData = 0;
      break;
    case AT_FLOAT:
      *(_DWORD *)this->m_pData = 0;
      break;
    case AT_BOOL:
      *(_BYTE *)this->m_pData = 0;
      break;
    case AT_STRING:
      CUtlString::Set(this: (CUtlString *)this->m_pData, pValue: nullptr);
      break;
    case AT_VOID:
      CUtlBinaryBlock::Set(this: (CUtlBinaryBlock *)this->m_pData, pValue: nullptr, nLen: 0);
      break;
    case AT_COLOR:
      *(_DWORD *)this->m_pData = -16777216;
      break;
    case AT_VECTOR2:
      m_pData = this->m_pData;
      *m_pData = 0;
      m_pData[1] = 0;
      break;
    case AT_VECTOR3:
    case AT_QANGLE:
      v2 = this->m_pData;
      *v2 = 0;
      v2[1] = 0;
      v2[2] = 0;
      break;
    case AT_VECTOR4:
      v3 = this->m_pData;
      *v3 = 0;
      v3[1] = 0;
      v3[2] = 0;
      v3[3] = 0;
      break;
    case AT_QUATERNION:
      v4 = this->m_pData;
      *v4 = 0;
      v4[1] = 0;
      v4[2] = 0;
      v4[3] = 1065353216;
      break;
    case AT_VMATRIX:
      MatrixSetIdentity(dst: (VMatrix *)this->m_pData);
      break;
    case AT_FIRST_ARRAY_TYPE:
    case AT_INT_ARRAY:
    case AT_FLOAT_ARRAY:
    case AT_BOOL_ARRAY:
    case AT_TIME_ARRAY:
    case AT_COLOR_ARRAY:
    case AT_VECTOR2_ARRAY:
    case AT_VECTOR3_ARRAY:
    case AT_VECTOR4_ARRAY:
    case AT_QANGLE_ARRAY:
    case AT_QUATERNION_ARRAY:
    case AT_VMATRIX_ARRAY:
      *((_DWORD *)this->m_pData + 3) = 0;
      break;
    case AT_STRING_ARRAY:
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData);
      break;
    case AT_VOID_ARRAY:
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C1D80
// Name: private: void CDmxAttribute::FreeDataMemory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::FreeDataMemory(CDmxAttribute *this)
{
  if ( this->m_Type != AT_UNKNOWN )
  {
    switch ( this->m_Type )
    {
      case AT_STRING:
      case AT_VOID:
        CDmxAttribute::DestructDataMemory<CUtlBinaryBlock,CUtlBinaryBlock>(this);
        this->m_Type = AT_UNKNOWN;
        break;
      case AT_FIRST_ARRAY_TYPE:
        CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this->m_pData);
        goto $LN130_7;
      case AT_INT_ARRAY:
        CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::~CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>(this: (CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int> > *)this->m_pData);
        this->m_Type = AT_UNKNOWN;
        break;
      case AT_FLOAT_ARRAY:
      case AT_TIME_ARRAY:
      case AT_COLOR_ARRAY:
      case AT_VECTOR4_ARRAY:
      case AT_QANGLE_ARRAY:
      case AT_QUATERNION_ARRAY:
        CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this->m_pData);
        this->m_Type = AT_UNKNOWN;
        break;
      case AT_BOOL_ARRAY:
      case AT_VECTOR2_ARRAY:
      case AT_VECTOR3_ARRAY:
      case AT_VMATRIX_ARRAY:
        CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>(this: (CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *)this->m_pData);
        this->m_Type = AT_UNKNOWN;
        break;
      case AT_STRING_ARRAY:
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData);
        this->m_Type = AT_UNKNOWN;
        break;
      case AT_VOID_ARRAY:
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData);
        this->m_Type = AT_UNKNOWN;
        break;
      default:
$LN130_7:
        this->m_Type = AT_UNKNOWN;
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C1F00
// Name: private: CDmxAttribute::~CDmxAttribute(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDmxAttribute::~CDmxAttribute(CDmxAttribute *this)
{
  CDmxAttribute::FreeDataMemory(this);
}

//------------------------------------------------------------------------------
// Address: 0x104C1F10
// Name: private: void CDmxAttribute::AllocateDataMemory(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::AllocateDataMemory(CDmxAttribute *this, DmAttributeType_t type)
{
  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = type;
  this->m_pData = DMXAlloc(size: s_pAttributeSize[type]);
}

//------------------------------------------------------------------------------
// Address: 0x104C1F40
// Name: private: void CDmxAttribute::AllocateDataMemory_AndConstruct(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::AllocateDataMemory_AndConstruct(CDmxAttribute *this, DmAttributeType_t type)
{
  CUtlString *v3; // ecx
  __int32 v4; // eax

  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = type;
  v3 = (CUtlString *)DMXAlloc(size: s_pAttributeSize[type]);
  v4 = this->m_Type - 1;
  this->m_pData = v3;
  switch ( v4 )
  {
    case 4:
      if ( v3 != nullptr )
        CUtlString::CUtlString(this: v3);
      break;
    case 5:
      if ( v3 != nullptr )
        CUtlBinaryBlock::CUtlBinaryBlock(this: &v3->m_Storage, growSize: 0, initSize: 0);
      break;
    case 6:
      if ( v3 != nullptr )
        v3->m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)0x80000000;
      break;
    case 7:
      if ( v3 != nullptr )
        v3->m_Storage.m_Memory.m_pMemory = nullptr;
      break;
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
      CDmxAttribute::ConstructDataMemory<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(this);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C20E0
// Name: public: bool CDmxAttribute::Unserialize(enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::Unserialize(CDmxAttribute *this, DmAttributeType_t type, CUtlBuffer *buf)
{
  bool result; // al

  CDmxAttribute::AllocateDataMemory_AndConstruct(this, type);
  result = false;
  switch ( this->m_Type )
  {
    case AT_INT:
      result = Unserialize(buf, dest: (int *)this->m_pData);
      break;
    case AT_FLOAT:
      result = Unserialize(buf, dest: (float *)this->m_pData);
      break;
    case AT_BOOL:
      result = Unserialize(buf, dest: (bool *)this->m_pData);
      break;
    case AT_STRING:
      result = Unserialize(buf, dest: (CUtlString *)this->m_pData);
      break;
    case AT_VOID:
      result = Unserialize(buf, dest: (CUtlBinaryBlock *)this->m_pData);
      break;
    case AT_TIME:
      result = Unserialize(buf, dest: (DmeTime_t *)this->m_pData);
      break;
    case AT_COLOR:
      result = Unserialize(buf, dest: (Color *)this->m_pData);
      break;
    case AT_VECTOR2:
      result = Unserialize(buf, dest: (Vector2D *)this->m_pData);
      break;
    case AT_VECTOR3:
    case AT_QANGLE:
      result = Unserialize(buf, dest: (QAngle *)this->m_pData);
      break;
    case AT_VECTOR4:
      result = Unserialize(buf, dest: (Vector4D *)this->m_pData);
      break;
    case AT_QUATERNION:
      result = Unserialize(buf, dest: (Quaternion *)this->m_pData);
      break;
    case AT_VMATRIX:
      result = Unserialize(buf, dest: (VMatrix *)this->m_pData);
      break;
    case AT_INT_ARRAY:
      result = Unserialize<int>(
                 buf,
                 dest: (CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int> > *)this->m_pData);
      break;
    case AT_FLOAT_ARRAY:
      result = Unserialize<float>(
                 buf,
                 dest: (CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int> > *)this->m_pData);
      break;
    case AT_BOOL_ARRAY:
      result = Unserialize<bool>(
                 buf,
                 dest: (CDmaArrayBase<bool,CDmaDataInternal<CUtlVector<bool,CUtlMemory<bool,int> > > > *)this->m_pData);
      break;
    case AT_STRING_ARRAY:
      result = Unserialize<CUtlString>(buf, dest: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData);
      break;
    case AT_VOID_ARRAY:
      result = Unserialize<CUtlBinaryBlock>(
                 buf,
                 dest: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData);
      break;
    case AT_TIME_ARRAY:
      result = Unserialize<DmeTime_t>(
                 buf,
                 dest: (CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int> > *)this->m_pData);
      break;
    case AT_COLOR_ARRAY:
      result = Unserialize<Color>(
                 buf,
                 dest: (CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int> > *)this->m_pData);
      break;
    case AT_VECTOR2_ARRAY:
      result = Unserialize<Vector2D>(
                 buf,
                 dest: (CUtlVector<DmePickerInfo_t,CUtlMemory<DmePickerInfo_t,int> > *)this->m_pData);
      break;
    case AT_VECTOR3_ARRAY:
      result = Unserialize<Vector>(
                 buf,
                 dest: (CDmaArrayBase<QAngle,CDmaDataInternal<CUtlVector<QAngle,CUtlMemory<QAngle,int> > > > *)this->m_pData);
      break;
    case AT_VECTOR4_ARRAY:
      result = Unserialize<Vector4D>(
                 buf,
                 dest: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this->m_pData);
      break;
    case AT_QANGLE_ARRAY:
      result = Unserialize<QAngle>(
                 buf,
                 dest: (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this->m_pData);
      break;
    case AT_QUATERNION_ARRAY:
      result = Unserialize<Quaternion>(
                 buf,
                 dest: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this->m_pData);
      break;
    case AT_VMATRIX_ARRAY:
      result = Unserialize<VMatrix>(
                 buf,
                 dest: (CDmaArrayBase<VMatrix,CDmaDataInternal<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > > *)this->m_pData);
      break;
    default:
      return result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104C23A0
// Name: public: bool CDmxAttribute::UnserializeElement(enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::UnserializeElement(CDmxAttribute *this, DmAttributeType_t type, CUtlBuffer *buf)
{
  bool result; // al
  __int32 v5; // eax

  if ( (unsigned int)(type - 15) > 0xD )
    return false;
  if ( this->m_Type != type )
    CDmxAttribute::AllocateDataMemory_AndConstruct(this, type);
  v5 = this->m_Type - 16;
  HIBYTE(type) = 0;
  switch ( v5 )
  {
    case 0:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<int,CUtlMemory<int,int>>,int>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 1:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<float,CUtlMemory<float,int>>,float>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 2:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 3:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 4:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 5:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 6:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 7:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 8:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 9:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>,Vector4D>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 10:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<QAngle,CUtlMemory<QAngle,int>>,QAngle>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 11:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 12:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      goto LABEL_19;
    default:
LABEL_19:
      result = HIBYTE(type);
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104C2540
// Name: public: void CDmxAttribute::SetValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetValue(CDmxAttribute *this, char *pString)
{
  CUtlString *v3; // eax
  CUtlString *v4; // edi

  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = AT_STRING;
  v3 = (CUtlString *)DMXAlloc(size: s_pAttributeSize[5]);
  v4 = v3;
  this->m_pData = v3;
  if ( v3 != nullptr )
    CUtlString::CUtlString(this: v3);
  CUtlString::Set(this: v4, pValue: pString);
}

//------------------------------------------------------------------------------
// Address: 0x104C2590
// Name: public: void CDmxAttribute::SetValueFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetValueFromString(CDmxAttribute *this, char *pValue)
{
  unsigned int v3; // eax
  CUtlString *v4; // eax
  CUtlString *v5; // edi
  CUtlBuffer buf; // [esp+4h] [ebp-30h] BYREF

  if ( this->m_Type != AT_UNKNOWN )
  {
    if ( this->m_Type == AT_STRING )
    {
      CDmxAttribute::FreeDataMemory(this);
      this->m_Type = AT_STRING;
      v4 = (CUtlString *)DMXAlloc(size: s_pAttributeSize[5]);
      v5 = v4;
      this->m_pData = v4;
      if ( v4 != nullptr )
        CUtlString::CUtlString(this: v4);
      CUtlString::Set(this: v5, pValue);
    }
    else if ( pValue != nullptr && (v3 = std::char_traits<char>::length(str: pValue)) != 0 )
    {
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: (unsigned __int8 *)pValue, nSize: v3, nFlags: 9u);
      if ( !CDmxAttribute::Unserialize(this, type: this->m_Type, &buf) )
        CDmxAttribute::SetToDefaultValue(this);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
    else
    {
      CDmxAttribute::SetToDefaultValue(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C2660
// Name: private: void CDmxAttribute::GetArrayValue(enum DmAttributeType_t,void __near *,int,int,char const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::GetArrayValue(
        CDmxAttribute *this,
        DmAttributeType_t type,
        unsigned __int8 *pDest,
        int nDataTypeSize,
        int nDestArrayLength,
        char *pDefaultString)
{
  DmAttributeType_t m_Type; // esi
  int v7; // ebx
  int v8; // edi
  _DWORD *m_pData; // eax
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // esi
  unsigned __int8 *v12; // ebx
  unsigned __int8 *v13; // esi
  int v14; // ebx
  unsigned __int8 *v15; // edi
  CDmxAttribute temp; // [esp+0h] [ebp-14h] BYREF
  DmAttributeType_t v17; // [esp+Ch] [ebp-8h]
  int nSrcStride; // [esp+10h] [ebp-4h]
  DmAttributeType_t typea; // [esp+1Ch] [ebp+8h]

  if ( (unsigned int)(type - 15) <= 0xD )
  {
    m_Type = this->m_Type;
    if ( this->m_Type == type )
    {
      v7 = s_pAttributeSize[type - 14];
      v17 = type - 14;
      nSrcStride = v7;
      if ( nDataTypeSize >= v7 )
        nDataTypeSize = v7;
      v8 = 0;
      if ( (unsigned int)(m_Type - 15) <= 0xD )
      {
        m_pData = this->m_pData;
        if ( m_pData != nullptr )
          v8 = m_pData[3];
      }
      v10 = nullptr;
      switch ( m_Type )
      {
        case AT_FIRST_ARRAY_TYPE:
        case AT_FLOAT_ARRAY:
        case AT_VOID_ARRAY:
        case AT_VECTOR2_ARRAY:
        case AT_QANGLE_ARRAY:
          v10 = *(unsigned __int8 **)this->m_pData;
          break;
        case AT_INT_ARRAY:
        case AT_STRING_ARRAY:
        case AT_COLOR_ARRAY:
        case AT_VECTOR4_ARRAY:
        case AT_VMATRIX_ARRAY:
          v10 = *(unsigned __int8 **)this->m_pData;
          break;
        case AT_BOOL_ARRAY:
        case AT_TIME_ARRAY:
        case AT_VECTOR3_ARRAY:
        case AT_QUATERNION_ARRAY:
          v10 = *(unsigned __int8 **)this->m_pData;
          break;
        default:
          break;
      }
      if ( v8 != 0 && v10 != nullptr )
      {
        if ( v7 == nDataTypeSize )
        {
          memcpy(dst: pDest, src: v10, count: nDataTypeSize * v8);
        }
        else
        {
          v11 = pDest;
          v12 = v10;
          if ( v8 > 0 )
          {
            for ( typea = v8; typea != AT_UNKNOWN; --typea )
            {
              memcpy(dst: v11, src: v12, count: nDataTypeSize);
              v11 += nDataTypeSize;
              v12 += nSrcStride;
            }
          }
        }
      }
      if ( v8 < nDestArrayLength && pDefaultString != nullptr )
      {
        temp.m_Name.u.m_Id = -1;
        temp.m_Type = AT_UNKNOWN;
        temp.m_pData = nullptr;
        CDmxAttribute::AllocateDataMemory_AndConstruct(this: &temp, type: v17);
        CDmxAttribute::SetValueFromString(this: &temp, pValue: pDefaultString);
        v13 = &pDest[nDataTypeSize * v8];
        v14 = nDestArrayLength - v8;
        v15 = (unsigned __int8 *)temp.m_pData;
        do
        {
          memcpy(dst: v13, src: v15, count: nDataTypeSize);
          v13 += nDataTypeSize;
          --v14;
        }
        while ( v14 != 0 );
        CDmxAttribute::FreeDataMemory(this: &temp);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x105C6960
// Name: _dynamic_initializer_for__CDmxAttribute::s_AttributeNameSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxAttribute::s_AttributeNameSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(this: &CDmxAttribute::s_AttributeNameSymbols);
  return atexit(func: dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x105CCB20
// Name: _dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(this: &CDmxAttribute::s_AttributeNameSymbols);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CDmxAttribute::s_AttributeNameSymbols.m_StringPools);
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &CDmxAttribute::s_AttributeNameSymbols.m_Lookup);
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmxAttribute::s_AttributeNameSymbols.m_Lookup.m_EntryMemory);
}

} // namespace hammer_dll

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x0041E4F0
// Name: public: void CUtlMemory<bool,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<bool,int>::Grow(CUtlMemory<unsigned char,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned __int8 *m_pMemory; // edx

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
        m_nAllocationCount = 32;
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
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: m_nAllocationCount);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B0410
// Name: public: char const __near * CDmxAttribute::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxAttribute::GetName(CDmxAttribute *this)
{
  const char *result; // eax

  result = this->m_Name.u.m_pAsString;
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B0A70
// Name: private: void CDmxAttribute::ConstructDataMemory<class CUtlVector<class Color,class CUtlMemory<class Color,int>>,class Color>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::ConstructDataMemory<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(CDmxAttribute *this)
{
  _DWORD *m_pData; // eax

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    *m_pData = 0;
    m_pData[1] = 0;
    m_pData[2] = 0;
    m_pData[3] = 0;
    m_pData[4] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B0A90
// Name: private: void CDmxAttribute::DestructDataMemory<class CUtlBinaryBlock,class CUtlBinaryBlock>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::DestructDataMemory<CUtlBinaryBlock,CUtlBinaryBlock>(CDmxAttribute *this)
{
  int *m_pData; // esi
  bool v2; // sf

  m_pData = (int *)this->m_pData;
  v2 = m_pData[2] < 0;
  m_pData[3] = 0;
  if ( !v2 )
  {
    if ( *m_pData != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*m_pData);
      *m_pData = 0;
    }
    m_pData[1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B0AD0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<int,class CUtlMemory<int,int>>,int>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<int,CUtlMemory<int,int>>,int>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlMemory<vgui::TreeNode *,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  v4 = Unserialize(buf, dest: (int *)&buf);
  *bSuccess = v4;
  if ( v4 )
  {
    m_pData = (CUtlMemory<vgui::TreeNode *,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<unsigned long,int>::Grow(this: m_pData, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
        count: 4 * v9);
    v10 = &m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)buf;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B0B50
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<float,class CUtlMemory<float,int>>,float>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<float,CUtlMemory<float,int>>,float>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlMemory<vgui::TreeNode *,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  v4 = Unserialize(buf, dest: (float *)&buf);
  *bSuccess = v4;
  if ( v4 )
  {
    m_pData = (CUtlMemory<vgui::TreeNode *,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<unsigned long,int>::Grow(this: m_pData, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
        count: 4 * v9);
    v10 = &m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)buf;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B0BD0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<bool,class CUtlMemory<bool,int>>,bool>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlMemory<unsigned char,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // edi
  unsigned __int8 *v8; // ecx
  signed int v9; // eax
  unsigned __int8 *v10; // esi

  v4 = Unserialize(buf, dest: (bool *)&buf + 3);
  *bSuccess = v4;
  if ( v4 )
  {
    m_pData = (CUtlMemory<unsigned char,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)(m_pMemory + 1) > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow(this: m_pData, num: (int)&m_pMemory[-m_nAllocationCount + 1]);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = m_pData[1].m_pMemory - m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[(_DWORD)m_pMemory + 1], src: &v8[(_DWORD)m_pMemory], count: v9);
    v10 = &m_pMemory[(unsigned int)m_pData->m_pMemory];
    if ( v10 != nullptr )
      *v10 = HIBYTE(buf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B0C40
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,class CUtlString>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlString temp; // [esp+4h] [ebp-10h] BYREF

  CUtlString::CUtlString(this: &temp);
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
      this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
  temp.m_Storage.m_nActualLength = 0;
  if ( temp.m_Storage.m_Memory.m_nGrowSize >= 0 && temp.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004B0CB0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>,class CUtlBinaryBlock>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlBinaryBlock temp; // [esp+4h] [ebp-10h] BYREF

  CUtlBinaryBlock::CUtlBinaryBlock(this: &temp, growSize: 0, initSize: 0);
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
      this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
  temp.m_nActualLength = 0;
  if ( temp.m_Memory.m_nGrowSize >= 0 && temp.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004B0D20
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>,class DmeTime_t>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlMemory<vgui::TreeNode *,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  DmeTime_t *v10; // eax
  DmeTime_t temp; // [esp+4h] [ebp-4h] BYREF

  temp.m_tms = 0x80000000;
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
  {
    m_pData = (CUtlMemory<vgui::TreeNode *,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<unsigned long,int>::Grow(this: m_pData, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
        count: 4 * v9);
    v10 = (DmeTime_t *)&m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      v10->m_tms = temp.m_tms;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B0DB0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Color,class CUtlMemory<class Color,int>>,class Color>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlMemory<vgui::TreeNode *,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  Color *v10; // eax
  Color temp; // [esp+4h] [ebp-4h] BYREF

  temp = 0;
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
  {
    m_pData = (CUtlMemory<vgui::TreeNode *,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<unsigned long,int>::Grow(this: m_pData, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
        count: 4 * v9);
    v10 = (Color *)&m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      *v10 = temp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B0E40
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>,class Vector2D>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Vector2D temp; // [esp+4h] [ebp-8h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: (CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x004B0E80
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector,class CUtlMemory<class Vector,int>>,class Vector>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  QAngle temp; // [esp+4h] [ebp-Ch] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x004B0EC0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>,class Vector4D>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>,Vector4D>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Vector4D temp; // [esp+4h] [ebp-10h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::InsertBefore(
      this: (CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x004B0F00
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>,class Quaternion>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Quaternion temp; // [esp+4h] [ebp-10h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertBefore(
      this: (CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x004B0F40
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>,class VMatrix>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  VMatrix temp; // [esp+4h] [ebp-40h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x004B0F80
// Name: bool Unserialize<int>(class CUtlBuffer __near &,class CUtlVector<int,class CUtlMemory<int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Unserialize<int>(CUtlBuffer *buf, CUtlVector<int,CUtlMemory<int,int> > *dest)
{
  CUtlBuffer *v2; // ebx
  unsigned int Int; // eax
  int v5; // edi
  int v6; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v10; // eax
  int v12; // edi
  int v13; // eax
  int *v14; // ecx
  int v15; // eax
  int nCount; // [esp+18h] [ebp+Ch]

  v2 = buf;
  dest->m_Size = 0;
  if ( (buf->m_Flags & 1) == 0 )
  {
    Int = CUtlBuffer::GetInt(this: buf);
    v5 = Int;
    nCount = Int;
    if ( Int != 0 )
    {
      CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(this: dest, num: Int);
      v6 = 0;
      if ( v5 > 0 )
      {
        do
        {
          m_Size = dest->m_Size;
          m_nAllocationCount = dest->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<unsigned long,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)dest,
              num: m_Size - m_nAllocationCount + 1);
          ++dest->m_Size;
          m_pMemory = dest->m_Memory.m_pMemory;
          v10 = dest->m_Size - m_Size - 1;
          dest->m_pElements = dest->m_Memory.m_pMemory;
          if ( v10 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
              src: (unsigned __int8 *)&m_pMemory[m_Size],
              count: 4 * v10);
          if ( !Unserialize(buf, dest: &dest->m_Memory.m_pMemory[v6]) )
            return false;
        }
        while ( ++v6 < nCount );
      }
      v2 = buf;
    }
    return v2->m_Error == 0;
  }
  CUtlBuffer::EatWhiteSpace(this: buf);
  if ( buf->m_Error != 0 )
    return true;
  while ( 1 )
  {
    v12 = dest->m_Size;
    v13 = dest->m_Memory.m_nAllocationCount;
    if ( v12 + 1 > v13 )
      CUtlMemory<unsigned long,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)dest, num: v12 - v13 + 1);
    ++dest->m_Size;
    v14 = dest->m_Memory.m_pMemory;
    v15 = dest->m_Size - v12 - 1;
    dest->m_pElements = dest->m_Memory.m_pMemory;
    if ( v15 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v14[v12 + 1], src: (unsigned __int8 *)&v14[v12], count: 4 * v15);
    if ( !Unserialize(buf, dest: &dest->m_Memory.m_pMemory[v12]) )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    if ( buf->m_Error != 0 )
      return true;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x004B10C0
// Name: bool Unserialize<float>(class CUtlBuffer __near &,class CUtlVector<float,class CUtlMemory<float,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Unserialize<float>(CUtlBuffer *buf, CUtlVector<int,CUtlMemory<int,int> > *dest)
{
  CUtlBuffer *v2; // ebx
  unsigned int Int; // eax
  int v5; // edi
  int v6; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  float *m_pMemory; // ecx
  int v10; // eax
  int v12; // edi
  int v13; // eax
  float *v14; // ecx
  int v15; // eax
  int nCount; // [esp+18h] [ebp+Ch]

  v2 = buf;
  dest->m_Size = 0;
  if ( (buf->m_Flags & 1) == 0 )
  {
    Int = CUtlBuffer::GetInt(this: buf);
    v5 = Int;
    nCount = Int;
    if ( Int != 0 )
    {
      CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(this: dest, num: Int);
      v6 = 0;
      if ( v5 > 0 )
      {
        do
        {
          m_Size = dest->m_Size;
          m_nAllocationCount = dest->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<unsigned long,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)dest,
              num: m_Size - m_nAllocationCount + 1);
          ++dest->m_Size;
          m_pMemory = (float *)dest->m_Memory.m_pMemory;
          v10 = dest->m_Size - m_Size - 1;
          dest->m_pElements = dest->m_Memory.m_pMemory;
          if ( v10 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
              src: (unsigned __int8 *)&m_pMemory[m_Size],
              count: 4 * v10);
          if ( !Unserialize(buf, dest: (float *)&dest->m_Memory.m_pMemory[v6]) )
            return false;
        }
        while ( ++v6 < nCount );
      }
      v2 = buf;
    }
    return v2->m_Error == 0;
  }
  CUtlBuffer::EatWhiteSpace(this: buf);
  if ( buf->m_Error != 0 )
    return true;
  while ( 1 )
  {
    v12 = dest->m_Size;
    v13 = dest->m_Memory.m_nAllocationCount;
    if ( v12 + 1 > v13 )
      CUtlMemory<unsigned long,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)dest, num: v12 - v13 + 1);
    ++dest->m_Size;
    v14 = (float *)dest->m_Memory.m_pMemory;
    v15 = dest->m_Size - v12 - 1;
    dest->m_pElements = dest->m_Memory.m_pMemory;
    if ( v15 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v14[v12 + 1], src: (unsigned __int8 *)&v14[v12], count: 4 * v15);
    if ( !Unserialize(buf, dest: (float *)&dest->m_Memory.m_pMemory[v12]) )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    if ( buf->m_Error != 0 )
      return true;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x004B1200
// Name: bool Unserialize<bool>(class CUtlBuffer __near &,class CUtlVector<bool,class CUtlMemory<bool,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Unserialize<bool>(CUtlBuffer *buf, CUtlVector<bool,CUtlMemory<bool,int> > *dest)
{
  CUtlBuffer *v2; // ebx
  unsigned int Int; // eax
  int v5; // edi
  int v6; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  bool *m_pMemory; // ecx
  signed int v10; // eax
  int v12; // edi
  int v13; // eax
  bool *v14; // ecx
  signed int v15; // eax
  int nCount; // [esp+18h] [ebp+Ch]

  v2 = buf;
  dest->m_Size = 0;
  if ( (buf->m_Flags & 1) == 0 )
  {
    Int = CUtlBuffer::GetInt(this: buf);
    v5 = Int;
    nCount = Int;
    if ( Int != 0 )
    {
      CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCapacity(this: dest, num: Int);
      v6 = 0;
      if ( v5 > 0 )
      {
        do
        {
          m_Size = dest->m_Size;
          m_nAllocationCount = dest->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<bool,int>::Grow(
              this: (CUtlMemory<unsigned char,int> *)dest,
              num: m_Size - m_nAllocationCount + 1);
          ++dest->m_Size;
          m_pMemory = dest->m_Memory.m_pMemory;
          v10 = dest->m_Size - m_Size - 1;
          dest->m_pElements = dest->m_Memory.m_pMemory;
          if ( v10 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
              src: (unsigned __int8 *)&m_pMemory[m_Size],
              count: v10);
          if ( !Unserialize(buf, dest: &dest->m_Memory.m_pMemory[v6]) )
            return false;
        }
        while ( ++v6 < nCount );
      }
      v2 = buf;
    }
    return v2->m_Error == 0;
  }
  CUtlBuffer::EatWhiteSpace(this: buf);
  if ( buf->m_Error != 0 )
    return true;
  while ( 1 )
  {
    v12 = dest->m_Size;
    v13 = dest->m_Memory.m_nAllocationCount;
    if ( v12 + 1 > v13 )
      CUtlMemory<bool,int>::Grow(this: (CUtlMemory<unsigned char,int> *)dest, num: v12 - v13 + 1);
    ++dest->m_Size;
    v14 = dest->m_Memory.m_pMemory;
    v15 = dest->m_Size - v12 - 1;
    dest->m_pElements = dest->m_Memory.m_pMemory;
    if ( v15 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v14[v12 + 1], src: (unsigned __int8 *)&v14[v12], count: v15);
    if ( !Unserialize(buf, dest: &dest->m_Memory.m_pMemory[v12]) )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    if ( buf->m_Error != 0 )
      return true;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x004B1F00
// Name: private: CDmxAttribute::CDmxAttribute(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxAttribute *__thiscall CDmxAttribute::CDmxAttribute(CDmxAttribute *this, char *pAttributeName)
{
  char *v4; // [esp-4h] [ebp-8h]

  v4 = pAttributeName;
  this->m_Name.u.m_Id = -1;
  this->m_Name = (CUtlSymbolLarge)CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
                                    this: &CDmxAttribute::s_AttributeNameSymbols,
                                    result: (CUtlSymbolLarge *)&pAttributeName,
                                    pString: v4)->u.m_Id;
  this->m_Type = AT_UNKNOWN;
  this->m_pData = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B1F40
// Name: private: void CDmxAttribute::FreeDataMemory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::FreeDataMemory(CDmxAttribute *this)
{
  if ( this->m_Type != AT_UNKNOWN )
  {
    switch ( this->m_Type )
    {
      case AT_STRING:
      case AT_VOID:
        CDmxAttribute::DestructDataMemory<CUtlBinaryBlock,CUtlBinaryBlock>(this);
        this->m_Type = AT_UNKNOWN;
        break;
      case AT_FIRST_ARRAY_TYPE:
        CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this->m_pData);
        goto $LN130_2;
      case AT_INT_ARRAY:
      case AT_FLOAT_ARRAY:
      case AT_BOOL_ARRAY:
      case AT_TIME_ARRAY:
      case AT_COLOR_ARRAY:
      case AT_VECTOR2_ARRAY:
      case AT_VECTOR3_ARRAY:
      case AT_VECTOR4_ARRAY:
      case AT_QANGLE_ARRAY:
      case AT_QUATERNION_ARRAY:
      case AT_VMATRIX_ARRAY:
        CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this->m_pData);
        this->m_Type = AT_UNKNOWN;
        break;
      case AT_STRING_ARRAY:
      case AT_VOID_ARRAY:
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData);
        this->m_Type = AT_UNKNOWN;
        break;
      default:
$LN130_2:
        this->m_Type = AT_UNKNOWN;
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B20C0
// Name: private: CDmxAttribute::~CDmxAttribute(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDmxAttribute::~CDmxAttribute(CDmxAttribute *this)
{
  CDmxAttribute::FreeDataMemory(this);
}

//------------------------------------------------------------------------------
// Address: 0x004B20D0
// Name: private: void CDmxAttribute::AllocateDataMemory(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::AllocateDataMemory(CDmxAttribute *this, DmAttributeType_t type)
{
  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = type;
  this->m_pData = DMXAlloc(size: s_pAttributeSize[type]);
}

//------------------------------------------------------------------------------
// Address: 0x004B2100
// Name: private: void CDmxAttribute::AllocateDataMemory_AndConstruct(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::AllocateDataMemory_AndConstruct(CDmxAttribute *this, DmAttributeType_t type)
{
  CUtlString *v3; // ecx
  __int32 v4; // eax

  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = type;
  v3 = (CUtlString *)DMXAlloc(size: s_pAttributeSize[type]);
  v4 = this->m_Type - 1;
  this->m_pData = v3;
  switch ( v4 )
  {
    case 4:
      if ( v3 != nullptr )
        CUtlString::CUtlString(this: v3);
      break;
    case 5:
      if ( v3 != nullptr )
        CUtlBinaryBlock::CUtlBinaryBlock(this: &v3->m_Storage, growSize: 0, initSize: 0);
      break;
    case 6:
      if ( v3 != nullptr )
        v3->m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)0x80000000;
      break;
    case 7:
      if ( v3 != nullptr )
        v3->m_Storage.m_Memory.m_pMemory = nullptr;
      break;
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
      CDmxAttribute::ConstructDataMemory<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(this);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B22A0
// Name: public: bool CDmxAttribute::Unserialize(enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::Unserialize(CDmxAttribute *this, DmAttributeType_t type, CUtlBuffer *buf)
{
  bool result; // al

  CDmxAttribute::AllocateDataMemory_AndConstruct(this, type);
  result = false;
  switch ( this->m_Type )
  {
    case AT_INT:
      result = Unserialize(buf, dest: (int *)this->m_pData);
      break;
    case AT_FLOAT:
      result = Unserialize(buf, dest: (float *)this->m_pData);
      break;
    case AT_BOOL:
      result = Unserialize(buf, dest: (bool *)this->m_pData);
      break;
    case AT_STRING:
      result = Unserialize(buf, dest: (CUtlString *)this->m_pData);
      break;
    case AT_VOID:
      result = Unserialize(buf, dest: (CUtlBinaryBlock *)this->m_pData);
      break;
    case AT_TIME:
      result = Unserialize(buf, dest: (DmeTime_t *)this->m_pData);
      break;
    case AT_COLOR:
      result = Unserialize(buf, dest: (Color *)this->m_pData);
      break;
    case AT_VECTOR2:
      result = Unserialize(buf, dest: (Vector2D *)this->m_pData);
      break;
    case AT_VECTOR3:
    case AT_QANGLE:
      result = Unserialize(buf, dest: (QAngle *)this->m_pData);
      break;
    case AT_VECTOR4:
      result = Unserialize(buf, dest: (Vector4D *)this->m_pData);
      break;
    case AT_QUATERNION:
      result = Unserialize(buf, dest: (Quaternion *)this->m_pData);
      break;
    case AT_VMATRIX:
      result = Unserialize(buf, dest: (VMatrix *)this->m_pData);
      break;
    case AT_INT_ARRAY:
      result = Unserialize<int>(buf, dest: (CUtlVector<int,CUtlMemory<int,int> > *)this->m_pData);
      break;
    case AT_FLOAT_ARRAY:
      result = Unserialize<float>(buf, dest: (CUtlVector<int,CUtlMemory<int,int> > *)this->m_pData);
      break;
    case AT_BOOL_ARRAY:
      result = Unserialize<bool>(buf, dest: (CUtlVector<bool,CUtlMemory<bool,int> > *)this->m_pData);
      break;
    case AT_STRING_ARRAY:
      result = Unserialize<CUtlString>(buf, dest: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData);
      break;
    case AT_VOID_ARRAY:
      result = Unserialize<CUtlBinaryBlock>(
                 buf,
                 dest: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData);
      break;
    case AT_TIME_ARRAY:
      result = Unserialize<DmeTime_t>(buf, dest: (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)this->m_pData);
      break;
    case AT_COLOR_ARRAY:
      result = Unserialize<Color>(buf, dest: (CUtlVector<Color,CUtlMemory<Color,int> > *)this->m_pData);
      break;
    case AT_VECTOR2_ARRAY:
      result = Unserialize<Vector2D>(buf, dest: (CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)this->m_pData);
      break;
    case AT_VECTOR3_ARRAY:
    case AT_QANGLE_ARRAY:
      result = Unserialize<QAngle>(buf, dest: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)this->m_pData);
      break;
    case AT_VECTOR4_ARRAY:
      result = Unserialize<Vector4D>(buf, dest: (CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *)this->m_pData);
      break;
    case AT_QUATERNION_ARRAY:
      result = Unserialize<Quaternion>(buf, dest: (CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)this->m_pData);
      break;
    case AT_VMATRIX_ARRAY:
      result = Unserialize<VMatrix>(buf, dest: (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)this->m_pData);
      break;
    default:
      return result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B2560
// Name: public: bool CDmxAttribute::UnserializeElement(enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::UnserializeElement(CDmxAttribute *this, DmAttributeType_t type, CUtlBuffer *buf)
{
  bool result; // al
  __int32 v5; // eax

  if ( (unsigned int)(type - 15) > 0xD )
    return false;
  if ( this->m_Type != type )
    CDmxAttribute::AllocateDataMemory_AndConstruct(this, type);
  v5 = this->m_Type - 16;
  HIBYTE(type) = 0;
  switch ( v5 )
  {
    case 0:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<int,CUtlMemory<int,int>>,int>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 1:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<float,CUtlMemory<float,int>>,float>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 2:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 3:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 4:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 5:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 6:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 7:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 8:
    case 10:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 9:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>,Vector4D>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 11:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 12:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      goto LABEL_18;
    default:
LABEL_18:
      result = HIBYTE(type);
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B2700
// Name: public: void CDmxAttribute::SetValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetValue(CDmxAttribute *this, char *pString)
{
  CUtlString *v3; // eax
  CUtlString *v4; // edi

  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = AT_STRING;
  v3 = (CUtlString *)DMXAlloc(size: s_pAttributeSize[5]);
  v4 = v3;
  this->m_pData = v3;
  if ( v3 != nullptr )
    CUtlString::CUtlString(this: v3);
  CUtlString::Set(this: v4, pValue: pString);
}

//------------------------------------------------------------------------------
// Address: 0x004B8DD0
// Name: _dynamic_initializer_for__CDmxAttribute::s_AttributeNameSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxAttribute::s_AttributeNameSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(this: &CDmxAttribute::s_AttributeNameSymbols);
  return atexit(func: dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x004B9540
// Name: _dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(this: &CDmxAttribute::s_AttributeNameSymbols);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CDmxAttribute::s_AttributeNameSymbols.m_StringPools);
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &CDmxAttribute::s_AttributeNameSymbols.m_Lookup);
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmxAttribute::s_AttributeNameSymbols.m_Lookup.m_EntryMemory);
}

} // namespace modelbrowser

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00561460
// Name: public: static enum DmAttributeType_t CDmxAttribute::ArrayAttributeBasicType(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
DmAttributeType_t __cdecl CDmxAttribute::ArrayAttributeBasicType(DmAttributeType_t type)
{
  DmAttributeType_t result; // eax

  result = type;
  if ( (unsigned int)(type - 15) <= 0xD )
    return type - 14;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00561480
// Name: public: char const __near * CDmxAttribute::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxAttribute::GetName(CDmxAttribute *this)
{
  const char *result; // eax

  result = this->m_Name.u.m_pAsString;
  if ( result == (const char *)-1 )
    return str;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00561490
// Name: private: void CDmxAttribute::SerializeType<int,int>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<int,int>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  int temp; // [esp+0h] [ebp-4h] BYREF

  temp = (int)this;
  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (int *)this->m_pData);
  }
  else
  {
    temp = 0;
    v3 = Serialize(buf, src: &temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x005614C0
// Name: private: void CDmxAttribute::SerializeType<float,float>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<float,float>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  CDmxAttribute *temp; // [esp+0h] [ebp-4h] BYREF

  temp = this;
  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (float *)this->m_pData);
  }
  else
  {
    temp = nullptr;
    v3 = Serialize(buf, src: (float *)&temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x00561500
// Name: private: void CDmxAttribute::SerializeType<bool,bool>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<bool,bool>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  bool temp; // [esp+1h] [ebp-1h] BYREF

  temp = HIBYTE(this);
  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const bool *)this->m_pData);
  }
  else
  {
    temp = false;
    v3 = Serialize(buf, src: &temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x00561530
// Name: private: void CDmxAttribute::SerializeType<class DmeTime_t,class DmeTime_t>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<DmeTime_t,DmeTime_t>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  DmeTime_t temp; // [esp+0h] [ebp-4h] BYREF

  temp.m_tms = (int)this;
  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const DmeTime_t *)this->m_pData);
  }
  else
  {
    temp.m_tms = 0;
    v3 = Serialize(buf, src: &temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x00561560
// Name: private: void CDmxAttribute::SerializeType<class Color,class Color>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<Color,Color>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  const Color *m_pData; // eax
  bool v4; // al
  Color temp; // [esp+0h] [ebp-4h] BYREF

  temp = (Color)this;
  m_pData = (const Color *)this->m_pData;
  if ( m_pData != nullptr )
  {
    v4 = Serialize(buf, src: m_pData);
  }
  else
  {
    temp = (Color)-16777216;
    v4 = Serialize(buf, src: &temp);
  }
  *bSuccess = v4;
}

//------------------------------------------------------------------------------
// Address: 0x005615A0
// Name: private: void CDmxAttribute::SerializeType<class Vector2D,class Vector2D>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<Vector2D,Vector2D>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  Vector2D temp; // [esp+0h] [ebp-8h] BYREF

  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const Vector2D *)this->m_pData);
  }
  else
  {
    temp.x = 0.0;
    temp.y = 0.0;
    v3 = Serialize(buf, src: &temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x005615E0
// Name: private: void CDmxAttribute::SerializeType<class Vector4D,class Vector4D>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<Vector4D,Vector4D>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  Vector4D temp; // [esp+0h] [ebp-10h] BYREF

  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const Quaternion *)this->m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    v3 = Serialize(buf, src: (const Quaternion *)&temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x00561630
// Name: private: void CDmxAttribute::SerializeType<class Vector,class Vector>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<Vector,Vector>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  QAngle temp; // [esp+0h] [ebp-Ch] BYREF

  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const QAngle *)this->m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    v3 = Serialize(buf, src: &temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x00561670
// Name: private: void CDmxAttribute::SerializeType<class Quaternion,class Quaternion>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<Quaternion,Quaternion>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v3; // al
  Quaternion temp; // [esp+0h] [ebp-10h] BYREF

  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const Quaternion *)this->m_pData);
  }
  else
  {
    memset(&temp, 0, 12);
    temp.w = 1.0;
    v3 = Serialize(buf, src: &temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x005616C0
// Name: private: void CDmxAttribute::SerializeType<class VMatrix,class VMatrix>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<VMatrix,VMatrix>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  VMatrix temp; // [esp+0h] [ebp-40h] BYREF

  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const VMatrix *)this->m_pData);
  }
  else
  {
    MatrixSetIdentity(dst: &temp);
    v3 = Serialize(buf, src: &temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x00561710
// Name: public: int CDmxAttribute::GetArrayCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxAttribute::GetArrayCount(CDmxAttribute *this)
{
  DmAttributeType_t m_Type; // edx
  int result; // eax
  _DWORD *m_pData; // ecx

  m_Type = this->m_Type;
  result = 0;
  if ( (unsigned int)(this->m_Type - 15) <= 0xD )
  {
    m_pData = this->m_pData;
    if ( m_pData != nullptr )
    {
      switch ( m_Type )
      {
        case AT_FIRST_ARRAY_TYPE:
        case AT_INT_ARRAY:
        case AT_FLOAT_ARRAY:
        case AT_BOOL_ARRAY:
        case AT_STRING_ARRAY:
        case AT_VOID_ARRAY:
        case AT_TIME_ARRAY:
        case AT_COLOR_ARRAY:
        case AT_VECTOR2_ARRAY:
        case AT_VECTOR3_ARRAY:
        case AT_VECTOR4_ARRAY:
        case AT_QANGLE_ARRAY:
        case AT_QUATERNION_ARRAY:
        case AT_VMATRIX_ARRAY:
          result = m_pData[3];
          break;
        default:
          return result;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00561770
// Name: public: bool CDmxAttribute::SerializesOnMultipleLines(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::SerializesOnMultipleLines(CDmxAttribute *this)
{
  bool result; // al

  result = false;
  switch ( this->m_Type )
  {
    case AT_FIRST_VALUE_TYPE:
    case AT_INT:
    case AT_FLOAT:
    case AT_BOOL:
    case AT_STRING:
    case AT_TIME:
    case AT_COLOR:
    case AT_VECTOR2:
    case AT_VECTOR3:
    case AT_VECTOR4:
    case AT_QANGLE:
    case AT_QUATERNION:
    case AT_FIRST_ARRAY_TYPE:
    case AT_INT_ARRAY:
    case AT_FLOAT_ARRAY:
    case AT_BOOL_ARRAY:
    case AT_STRING_ARRAY:
    case AT_VOID_ARRAY:
    case AT_TIME_ARRAY:
    case AT_COLOR_ARRAY:
    case AT_VECTOR2_ARRAY:
    case AT_VECTOR3_ARRAY:
    case AT_VECTOR4_ARRAY:
    case AT_QANGLE_ARRAY:
    case AT_QUATERNION_ARRAY:
    case AT_VMATRIX_ARRAY:
      result = false;
      break;
    case AT_VOID:
    case AT_VMATRIX:
      result = true;
      break;
    default:
      return result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00561800
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<int,class CUtlMemory<int,int>>,int>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<int,CUtlMemory<int,int>>,int>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // eax
  bool v5; // al

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (int *)(*m_pData + 4 * nIndex));
  }
  else
  {
    nIndex = 0;
    v5 = Serialize(buf, src: &nIndex);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00561850
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<float,class CUtlMemory<float,int>>,float>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<float,CUtlMemory<float,int>>,float>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // eax
  bool v5; // al

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (float *)(*m_pData + 4 * nIndex));
  }
  else
  {
    nIndex = 0;
    v5 = Serialize(buf, src: (float *)&nIndex);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x005618A0
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<bool,class CUtlMemory<bool,int>>,bool>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // eax
  bool v5; // al

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const bool *)(nIndex + *m_pData));
  }
  else
  {
    HIBYTE(nIndex) = 0;
    v5 = Serialize(buf, src: (const bool *)&nIndex + 3);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x005618D0
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>,class DmeTime_t>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        CDmxAttribute *this,
        bool *bSuccess,
        DmeTime_t nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // eax
  bool v5; // al

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const DmeTime_t *)(*m_pData + 4 * nIndex.m_tms));
  }
  else
  {
    nIndex.m_tms = 0;
    v5 = Serialize(buf, src: &nIndex);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00561920
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<class Color,class CUtlMemory<class Color,int>>,class Color>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        CDmxAttribute *this,
        bool *bSuccess,
        Color nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // eax
  bool v5; // al

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const Color *)(*m_pData + 4 * *(_DWORD *)&nIndex));
  }
  else
  {
    nIndex = (Color)-16777216;
    v5 = Serialize(buf, src: &nIndex);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00561970
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>,class Vector2D>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // eax
  bool v5; // al
  Vector2D temp; // [esp+0h] [ebp-8h] BYREF

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const Vector2D *)(*m_pData + 8 * nIndex));
  }
  else
  {
    temp.x = 0.0;
    temp.y = 0.0;
    v5 = Serialize(buf, src: &temp);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x005619D0
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>,class Vector4D>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>,Vector4D>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // ecx
  bool v5; // al
  Vector4D temp; // [esp+0h] [ebp-10h] BYREF

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const Quaternion *)(*m_pData + 16 * nIndex));
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    v5 = Serialize(buf, src: (const Quaternion *)&temp);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00561A20
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>>,class QAngle>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<QAngle,CUtlMemory<QAngle,int>>,QAngle>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // ecx
  bool v5; // al
  QAngle temp; // [esp+0h] [ebp-Ch] BYREF

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const QAngle *)(*m_pData + 12 * nIndex));
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    v5 = Serialize(buf, src: &temp);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00561A80
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>,class Quaternion>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // ecx
  bool v5; // al
  Quaternion temp; // [esp+0h] [ebp-10h] BYREF

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const Quaternion *)(*m_pData + 16 * nIndex));
  }
  else
  {
    memset(&temp, 0, 12);
    temp.w = 1.0;
    v5 = Serialize(buf, src: &temp);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00561AE0
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>,class VMatrix>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // ecx
  bool v5; // al
  VMatrix temp; // [esp+0h] [ebp-40h] BYREF

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const VMatrix *)(*m_pData + (nIndex << 6)));
  }
  else
  {
    MatrixSetIdentity(dst: &temp);
    v5 = Serialize(buf, src: &temp);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00561B40
// Name: private: void CDmxAttribute::SerializeType<class CUtlBinaryBlock,class CUtlBinaryBlock>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlBinaryBlock,CUtlBinaryBlock>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v3; // al
  bool v4; // sf
  CUtlBinaryBlock temp; // [esp+0h] [ebp-10h] BYREF

  if ( this->m_pData != nullptr )
  {
    *bSuccess = Serialize(buf, src: (const CUtlBinaryBlock *)this->m_pData);
  }
  else
  {
    CUtlBinaryBlock::CUtlBinaryBlock(this: &temp, growSize: 0, initSize: 0);
    CUtlBinaryBlock::Set(this: &temp, pValue: nullptr, nLen: 0);
    v3 = Serialize(buf, src: &temp);
    v4 = temp.m_Memory.m_nGrowSize < 0;
    *bSuccess = v3;
    temp.m_nActualLength = 0;
    if ( !v4 && temp.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00561BC0
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>,class CUtlBinaryBlock>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // ecx
  bool v5; // al
  bool v6; // sf
  CUtlBinaryBlock temp; // [esp+0h] [ebp-10h] BYREF

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize(buf, src: (const CUtlBinaryBlock *)(*m_pData + 16 * nIndex));
  }
  else
  {
    CUtlBinaryBlock::CUtlBinaryBlock(this: &temp, growSize: 0, initSize: 0);
    CUtlBinaryBlock::Set(this: &temp, pValue: nullptr, nLen: 0);
    v5 = Serialize(buf, src: &temp);
    v6 = temp.m_Memory.m_nGrowSize < 0;
    *bSuccess = v5;
    temp.m_nActualLength = 0;
    if ( !v6 && temp.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00561CE0
// Name: private: void CDmxAttribute::SerializeType<class CUtlString,class CUtlString>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlString,CUtlString>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v3; // al
  bool v4; // sf
  CUtlString temp; // [esp+0h] [ebp-10h] BYREF

  if ( this->m_pData != nullptr )
  {
    *bSuccess = Serialize(buf, src: (CUtlString *)this->m_pData);
  }
  else
  {
    CUtlString::CUtlString(this: &temp);
    CUtlString::Set(this: &temp, pValue: nullptr);
    v3 = Serialize(buf, src: &temp);
    v4 = temp.m_Storage.m_Memory.m_nGrowSize < 0;
    *bSuccess = v3;
    temp.m_Storage.m_nActualLength = 0;
    if ( !v4 && temp.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Storage.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00561D60
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,class CUtlString>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // ecx
  bool v5; // al
  bool v6; // sf
  CUtlString temp; // [esp+0h] [ebp-10h] BYREF

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize(buf, src: (CUtlString *)(*m_pData + 16 * nIndex));
  }
  else
  {
    CUtlString::CUtlString(this: &temp);
    CUtlString::Set(this: &temp, pValue: nullptr);
    v5 = Serialize(buf, src: &temp);
    v6 = temp.m_Storage.m_Memory.m_nGrowSize < 0;
    *bSuccess = v5;
    temp.m_Storage.m_nActualLength = 0;
    if ( !v6 && temp.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Storage.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00561F50
// Name: public: bool CDmxAttribute::SerializeElement(int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::SerializeElement(CDmxAttribute *this, Color nIndex, CUtlBuffer *buf)
{
  DmAttributeType_t m_Type; // eax
  bool result; // al
  bool bSuccess; // [esp+1h] [ebp-1h] BYREF

  bSuccess = HIBYTE(this);
  m_Type = this->m_Type;
  if ( (unsigned int)(this->m_Type - 15) > 0xD )
    return false;
  bSuccess = false;
  switch ( m_Type )
  {
    case AT_INT_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<int,CUtlMemory<int,int>>,int>(
        this,
        &bSuccess,
        nIndex: *(_DWORD *)&nIndex,
        buf);
      result = bSuccess;
      break;
    case AT_FLOAT_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<float,CUtlMemory<float,int>>,float>(
        this,
        &bSuccess,
        nIndex: *(_DWORD *)&nIndex,
        buf);
      result = bSuccess;
      break;
    case AT_BOOL_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        this,
        &bSuccess,
        nIndex: *(_DWORD *)&nIndex,
        buf);
      result = bSuccess;
      break;
    case AT_STRING_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        this,
        &bSuccess,
        nIndex: *(_DWORD *)&nIndex,
        buf);
      result = bSuccess;
      break;
    case AT_VOID_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        this,
        &bSuccess,
        nIndex: *(_DWORD *)&nIndex,
        buf);
      result = bSuccess;
      break;
    case AT_TIME_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        this,
        &bSuccess,
        (DmeTime_t)nIndex,
        buf);
      result = bSuccess;
      break;
    case AT_COLOR_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(this, &bSuccess, nIndex, buf);
      result = bSuccess;
      break;
    case AT_VECTOR2_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        this,
        &bSuccess,
        nIndex: *(_DWORD *)&nIndex,
        buf);
      result = bSuccess;
      break;
    case AT_VECTOR3_ARRAY:
    case AT_QANGLE_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<QAngle,CUtlMemory<QAngle,int>>,QAngle>(
        this,
        &bSuccess,
        nIndex: *(_DWORD *)&nIndex,
        buf);
      result = bSuccess;
      break;
    case AT_VECTOR4_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>,Vector4D>(
        this,
        &bSuccess,
        nIndex: *(_DWORD *)&nIndex,
        buf);
      result = bSuccess;
      break;
    case AT_QUATERNION_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        this,
        &bSuccess,
        nIndex: *(_DWORD *)&nIndex,
        buf);
      result = bSuccess;
      break;
    case AT_VMATRIX_ARRAY:
      CDmxAttribute::SerializeTypedElement<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        this,
        &bSuccess,
        nIndex: *(_DWORD *)&nIndex,
        buf);
      goto LABEL_16;
    default:
LABEL_16:
      result = bSuccess;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00562110
// Name: private: void CDmxAttribute::DestructDataMemory<class CUtlBinaryBlock,class CUtlBinaryBlock>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::DestructDataMemory<CUtlBinaryBlock,CUtlBinaryBlock>(CDmxAttribute *this)
{
  int *m_pData; // esi
  bool v2; // sf

  m_pData = (int *)this->m_pData;
  v2 = m_pData[2] < 0;
  m_pData[3] = 0;
  if ( !v2 )
  {
    if ( *m_pData != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*m_pData);
      *m_pData = 0;
    }
    m_pData[1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00562150
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<int,class CUtlMemory<int,int>>,int>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<int,CUtlMemory<int,int>>,int>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<int,CUtlMemory<int,int> > *m_pData; // eax
  CUtlVector<int,CUtlMemory<int,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<int,CUtlMemory<int,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<int>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<int>(buf, src: &temp);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005621B0
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<float,class CUtlMemory<float,int>>,float>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<float,CUtlMemory<float,int>>,float>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<float,CUtlMemory<float,int> > *m_pData; // eax
  CUtlVector<float,CUtlMemory<float,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<float,CUtlMemory<float,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<float>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<float>(buf, src: &temp);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00562210
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<bool,class CUtlMemory<bool,int>>,bool>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<bool,CUtlMemory<bool,int> > *m_pData; // eax
  CUtlVector<bool,CUtlMemory<bool,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<bool,CUtlMemory<bool,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<bool>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<bool>(buf, src: &temp);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00562270
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>,class DmeTime_t>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *m_pData; // eax
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<DmeTime_t>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<DmeTime_t>(buf, src: &temp);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005622D0
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class Color,class CUtlMemory<class Color,int>>,class Color>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<Color,CUtlMemory<Color,int> > *m_pData; // eax
  CUtlVector<Color,CUtlMemory<Color,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<Color,CUtlMemory<Color,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<Color>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<Color>(buf, src: &temp);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00562330
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>,class Vector2D>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *m_pData; // eax
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<Vector2D>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<Vector2D>(buf, src: &temp);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00562390
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class Vector,class CUtlMemory<class Vector,int>>,class Vector>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<QAngle,CUtlMemory<QAngle,int> > *m_pData; // eax
  CUtlVector<QAngle,CUtlMemory<QAngle,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<Vector>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<Vector>(buf, src: &temp);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005623F0
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>,class Quaternion>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *m_pData; // eax
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<Quaternion>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<Quaternion>(buf, src: &temp);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00562450
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>,class VMatrix>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *m_pData; // eax
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<VMatrix>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<VMatrix>(buf, src: &temp);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00562520
// Name: private: CDmxAttribute::CDmxAttribute(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxAttribute *__thiscall CDmxAttribute::CDmxAttribute(CDmxAttribute *this, char *pAttributeName)
{
  char *v4; // [esp-4h] [ebp-8h]

  v4 = pAttributeName;
  this->m_Name.u.m_Id = -1;
  this->m_Name = (CUtlSymbolLarge)CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
                                    this: &CDmxAttribute::s_AttributeNameSymbols,
                                    result: (CUtlSymbolLarge *)&pAttributeName,
                                    pString: v4)->u.m_Id;
  this->m_Type = AT_UNKNOWN;
  this->m_pData = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00562560
// Name: private: void CDmxAttribute::SetArrayCount<class CUtlVector<int,class CUtlMemory<int,int>>,int>(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetArrayCount<CUtlVector<int,CUtlMemory<int,int>>,int>(
        CDmxAttribute *this,
        int nArrayCount)
{
  CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *m_pData; // ecx
  int m_Size; // edx

  m_pData = (CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *)this->m_pData;
  m_Size = m_pData->m_Size;
  if ( nArrayCount - m_Size <= 0 )
  {
    if ( nArrayCount - m_Size < 0 )
      m_pData->m_Size = nArrayCount;
  }
  else
  {
    CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
      this: m_pData,
      elem: m_Size,
      num: nArrayCount - m_Size);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00562590
// Name: private: void CDmxAttribute::SetArrayCount<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,class CUtlString>(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetArrayCount<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        CDmxAttribute *this,
        int nArrayCount)
{
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *m_pData; // ecx
  int m_Size; // edx

  m_pData = (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData;
  m_Size = m_pData->m_Size;
  if ( nArrayCount - m_Size <= 0 )
  {
    if ( nArrayCount - m_Size < 0 )
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveMultipleFromTail(
        this: m_pData,
        num: m_Size - nArrayCount);
  }
  else
  {
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertMultipleBefore(
      this: m_pData,
      elem: m_Size,
      num: nArrayCount - m_Size);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005625C0
// Name: private: void CDmxAttribute::SetArrayCount<class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>,class CUtlBinaryBlock>(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetArrayCount<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        CDmxAttribute *this,
        int nArrayCount)
{
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *m_pData; // ecx
  int m_Size; // edx

  m_pData = (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData;
  m_Size = m_pData->m_Size;
  if ( nArrayCount - m_Size <= 0 )
  {
    if ( nArrayCount - m_Size < 0 )
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveMultipleFromTail(
        this: m_pData,
        num: m_Size - nArrayCount);
  }
  else
  {
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertMultipleBefore(
      this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)m_pData,
      elem: m_Size,
      num: nArrayCount - m_Size);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005625F0
// Name: private: void CDmxAttribute::SetArrayCount<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>,class DmeTime_t>(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetArrayCount<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        CDmxAttribute *this,
        int nArrayCount)
{
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *m_pData; // ecx
  int m_Size; // edx

  m_pData = (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)this->m_pData;
  m_Size = m_pData->m_Size;
  if ( nArrayCount - m_Size <= 0 )
  {
    if ( nArrayCount - m_Size < 0 )
      m_pData->m_Size = nArrayCount;
  }
  else
  {
    CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>::InsertMultipleBefore(
      this: m_pData,
      elem: m_Size,
      num: nArrayCount - m_Size);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00562620
// Name: private: void CDmxAttribute::SetArrayCount<class CUtlVector<class Color,class CUtlMemory<class Color,int>>,class Color>(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetArrayCount<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        CDmxAttribute *this,
        int nArrayCount)
{
  CUtlVector<Color,CUtlMemory<Color,int> > *m_pData; // ecx
  int m_Size; // edx

  m_pData = (CUtlVector<Color,CUtlMemory<Color,int> > *)this->m_pData;
  m_Size = m_pData->m_Size;
  if ( nArrayCount - m_Size <= 0 )
  {
    if ( nArrayCount - m_Size < 0 )
      m_pData->m_Size = nArrayCount;
  }
  else
  {
    CUtlVector<Color,CUtlMemory<Color,int>>::InsertMultipleBefore(
      this: m_pData,
      elem: m_Size,
      num: nArrayCount - m_Size);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00562650
// Name: private: void CDmxAttribute::SetArrayCount<class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>,class Vector2D>(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetArrayCount<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        CDmxAttribute *this,
        int nArrayCount)
{
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *m_pData; // ecx
  int m_Size; // edx

  m_pData = (CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)this->m_pData;
  m_Size = m_pData->m_Size;
  if ( nArrayCount - m_Size <= 0 )
  {
    if ( nArrayCount - m_Size < 0 )
      m_pData->m_Size = nArrayCount;
  }
  else
  {
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
      this: m_pData,
      elem: m_Size,
      num: nArrayCount - m_Size);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00562680
// Name: private: void CDmxAttribute::SetArrayCount<class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>,class Quaternion>(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetArrayCount<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        CDmxAttribute *this,
        int nArrayCount)
{
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *m_pData; // ecx
  int m_Size; // edx

  m_pData = (CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)this->m_pData;
  m_Size = m_pData->m_Size;
  if ( nArrayCount - m_Size <= 0 )
  {
    if ( nArrayCount - m_Size < 0 )
      m_pData->m_Size = nArrayCount;
  }
  else
  {
    CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertMultipleBefore(
      this: m_pData,
      elem: m_Size,
      num: nArrayCount - m_Size);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005626B0
// Name: private: void CDmxAttribute::SetArrayCount<class CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>>,class QAngle>(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetArrayCount<CUtlVector<QAngle,CUtlMemory<QAngle,int>>,QAngle>(
        CDmxAttribute *this,
        int nArrayCount)
{
  CUtlVector<QAngle,CUtlMemory<QAngle,int> > *m_pData; // ecx
  int m_Size; // edx

  m_pData = (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)this->m_pData;
  m_Size = m_pData->m_Size;
  if ( nArrayCount - m_Size <= 0 )
  {
    if ( nArrayCount - m_Size < 0 )
      m_pData->m_Size = nArrayCount;
  }
  else
  {
    CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
      this: m_pData,
      elem: m_Size,
      num: nArrayCount - m_Size);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005626E0
// Name: private: void CDmxAttribute::SetArrayCount<class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>,class VMatrix>(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetArrayCount<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        CDmxAttribute *this,
        int nArrayCount)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *m_pData; // ecx
  int m_Size; // edx

  m_pData = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)this->m_pData;
  m_Size = m_pData->m_Size;
  if ( nArrayCount - m_Size <= 0 )
  {
    if ( nArrayCount - m_Size < 0 )
      m_pData->m_Size = nArrayCount;
  }
  else
  {
    CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::InsertMultipleBefore(
      this: m_pData,
      elem: m_Size,
      num: nArrayCount - m_Size);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00562710
// Name: private: void CDmxAttribute::SetArrayCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetArrayCount(CDmxAttribute *this, int nArrayCount)
{
  switch ( this->m_Type )
  {
    case AT_FIRST_ARRAY_TYPE:
    case AT_INT_ARRAY:
    case AT_FLOAT_ARRAY:
      CDmxAttribute::SetArrayCount<CUtlVector<int,CUtlMemory<int,int>>,int>(this, nArrayCount);
      break;
    case AT_BOOL_ARRAY:
      CUtlVector<bool,CUtlMemory<bool,int>>::SetCountNonDestructively(
        this: (CUtlVector<bool,CUtlMemory<bool,int> > *)this->m_pData,
        count: nArrayCount);
      break;
    case AT_STRING_ARRAY:
      CDmxAttribute::SetArrayCount<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(this, nArrayCount);
      break;
    case AT_VOID_ARRAY:
      CDmxAttribute::SetArrayCount<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        this,
        nArrayCount);
      break;
    case AT_TIME_ARRAY:
      CDmxAttribute::SetArrayCount<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(this, nArrayCount);
      break;
    case AT_COLOR_ARRAY:
      CDmxAttribute::SetArrayCount<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(this, nArrayCount);
      break;
    case AT_VECTOR2_ARRAY:
      CDmxAttribute::SetArrayCount<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(this, nArrayCount);
      break;
    case AT_VECTOR3_ARRAY:
    case AT_QANGLE_ARRAY:
      CDmxAttribute::SetArrayCount<CUtlVector<QAngle,CUtlMemory<QAngle,int>>,QAngle>(this, nArrayCount);
      break;
    case AT_VECTOR4_ARRAY:
    case AT_QUATERNION_ARRAY:
      CDmxAttribute::SetArrayCount<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(this, nArrayCount);
      break;
    case AT_VMATRIX_ARRAY:
      CDmxAttribute::SetArrayCount<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(this, nArrayCount);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005627C0
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,class CUtlString>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *m_pData; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<CUtlString>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &temp);
    *bSuccess = Serialize<CUtlString>(buf, src: &temp);
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: &temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00562830
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>,class CUtlBinaryBlock>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *m_pData; // eax
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<CUtlBinaryBlock>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)&temp);
    *bSuccess = Serialize<CUtlBinaryBlock>(buf, src: &temp);
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005628A0
// Name: public: bool CDmxAttribute::Serialize(class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::Serialize(CDmxAttribute *this, CUtlBuffer *buf)
{
  __int32 v2; // eax
  bool result; // al
  bool bSuccess; // [esp+3h] [ebp-1h] BYREF

  v2 = this->m_Type - 2;
  bSuccess = false;
  switch ( v2 )
  {
    case 0:
      CDmxAttribute::SerializeType<int,int>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 1:
      CDmxAttribute::SerializeType<float,float>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 2:
      CDmxAttribute::SerializeType<bool,bool>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 3:
      CDmxAttribute::SerializeType<CUtlString,CUtlString>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 4:
      CDmxAttribute::SerializeType<CUtlBinaryBlock,CUtlBinaryBlock>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 5:
      CDmxAttribute::SerializeType<DmeTime_t,DmeTime_t>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 6:
      CDmxAttribute::SerializeType<Color,Color>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 7:
      CDmxAttribute::SerializeType<Vector2D,Vector2D>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 8:
    case 10:
      CDmxAttribute::SerializeType<Vector,Vector>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 9:
      CDmxAttribute::SerializeType<Vector4D,Vector4D>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 11:
      CDmxAttribute::SerializeType<Quaternion,Quaternion>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 12:
      CDmxAttribute::SerializeType<VMatrix,VMatrix>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 14:
      CDmxAttribute::SerializeType<CUtlVector<int,CUtlMemory<int,int>>,int>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 15:
      CDmxAttribute::SerializeType<CUtlVector<float,CUtlMemory<float,int>>,float>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 16:
      CDmxAttribute::SerializeType<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 17:
      CDmxAttribute::SerializeType<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 18:
      CDmxAttribute::SerializeType<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        this,
        &bSuccess,
        buf);
      result = bSuccess;
      break;
    case 19:
      CDmxAttribute::SerializeType<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 20:
      CDmxAttribute::SerializeType<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 21:
      CDmxAttribute::SerializeType<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 22:
    case 24:
      CDmxAttribute::SerializeType<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 23:
    case 25:
      CDmxAttribute::SerializeType<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(this, &bSuccess, buf);
      result = bSuccess;
      break;
    case 26:
      CDmxAttribute::SerializeType<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(this, &bSuccess, buf);
      goto LABEL_25;
    default:
LABEL_25:
      result = bSuccess;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00562B70
// Name: private: void CDmxAttribute::FreeDataMemory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::FreeDataMemory(CDmxAttribute *this)
{
  if ( this->m_Type != AT_UNKNOWN )
  {
    switch ( this->m_Type )
    {
      case AT_STRING:
      case AT_VOID:
        CDmxAttribute::DestructDataMemory<CUtlBinaryBlock,CUtlBinaryBlock>(this);
        this->m_Type = AT_UNKNOWN;
        break;
      case AT_FIRST_ARRAY_TYPE:
        CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)this->m_pData);
        goto $LN130_0;
      case AT_INT_ARRAY:
      case AT_FLOAT_ARRAY:
      case AT_BOOL_ARRAY:
      case AT_TIME_ARRAY:
      case AT_COLOR_ARRAY:
      case AT_VECTOR2_ARRAY:
      case AT_VECTOR3_ARRAY:
      case AT_VECTOR4_ARRAY:
      case AT_QANGLE_ARRAY:
      case AT_QUATERNION_ARRAY:
      case AT_VMATRIX_ARRAY:
        CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)this->m_pData);
        this->m_Type = AT_UNKNOWN;
        break;
      case AT_STRING_ARRAY:
      case AT_VOID_ARRAY:
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData);
        this->m_Type = AT_UNKNOWN;
        break;
      default:
$LN130_0:
        this->m_Type = AT_UNKNOWN;
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00562CF0
// Name: private: CDmxAttribute::~CDmxAttribute(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDmxAttribute::~CDmxAttribute(CDmxAttribute *this)
{
  CDmxAttribute::FreeDataMemory(this);
}

//------------------------------------------------------------------------------
// Address: 0x00562D00
// Name: private: void CDmxAttribute::AllocateDataMemory(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::AllocateDataMemory(CDmxAttribute *this, DmAttributeType_t type)
{
  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = type;
  this->m_pData = DMXAlloc(size: s_pAttributeSize[type]);
}

//------------------------------------------------------------------------------
// Address: 0x00562D30
// Name: public: void CDmxAttribute::SetValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetValue(CDmxAttribute *this, char *pString)
{
  CUtlString *v3; // eax
  CUtlString *v4; // edi

  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = AT_STRING;
  v3 = (CUtlString *)DMXAlloc(size: s_pAttributeSize[5]);
  v4 = v3;
  this->m_pData = v3;
  if ( v3 != nullptr )
    CUtlString::CUtlString(this: v3);
  CUtlString::Set(this: v4, pValue: pString);
}

//------------------------------------------------------------------------------
// Address: 0x00562D80
// Name: private: void CDmxAttribute::SetValue(enum DmAttributeType_t,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetValue(CDmxAttribute *this, DmAttributeType_t type, const __m128i *pSrc, int nLen)
{
  unsigned int v5; // eax

  if ( this->m_Type != type )
  {
    CDmxAttribute::FreeDataMemory(this);
    this->m_Type = type;
    this->m_pData = DMXAlloc(size: s_pAttributeSize[type]);
  }
  v5 = nLen;
  if ( nLen > (int)s_pAttributeSize[type] )
    v5 = s_pAttributeSize[type];
  memcpy(dst: (__m128i *)this->m_pData, src: pSrc, count: v5);
}

//------------------------------------------------------------------------------
// Address: 0x00562DD0
// Name: private: void CDmxAttribute::SetArrayValue(enum DmAttributeType_t,void const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetArrayValue(
        CDmxAttribute *this,
        DmAttributeType_t type,
        const __m128i *pSrc,
        int nDataTypeSize,
        int nArrayLength,
        int nSrcStride)
{
  int v7; // ebx
  __m128i *v8; // esi
  const __m128i *v9; // edi
  char *pSrca; // [esp+14h] [ebp+Ch]

  if ( (unsigned int)(type - 15) <= 0xD )
  {
    if ( this->m_Type != type )
    {
      CDmxAttribute::FreeDataMemory(this);
      this->m_Type = type;
      this->m_pData = DMXAlloc(size: s_pAttributeSize[type]);
    }
    v7 = *((_DWORD *)&vec4_invalid_99.z + type);
    if ( nDataTypeSize >= v7 )
      nDataTypeSize = *((_DWORD *)&vec4_invalid_99.z + type);
    CDmxAttribute::SetArrayCount(this, nArrayCount: nArrayLength);
    switch ( this->m_Type )
    {
      case AT_FIRST_ARRAY_TYPE:
      case AT_FLOAT_ARRAY:
      case AT_VOID_ARRAY:
      case AT_VECTOR2_ARRAY:
      case AT_QANGLE_ARRAY:
        v8 = *(__m128i **)this->m_pData;
        goto LABEL_10;
      case AT_INT_ARRAY:
      case AT_STRING_ARRAY:
      case AT_COLOR_ARRAY:
      case AT_VECTOR4_ARRAY:
      case AT_VMATRIX_ARRAY:
        v8 = *(__m128i **)this->m_pData;
        goto LABEL_10;
      case AT_BOOL_ARRAY:
      case AT_TIME_ARRAY:
      case AT_VECTOR3_ARRAY:
      case AT_QUATERNION_ARRAY:
        v8 = *(__m128i **)this->m_pData;
LABEL_10:
        if ( v8 != nullptr )
        {
          if ( nDataTypeSize != v7 )
            _V_memset(dest: (unsigned __int8 *)v8, fill: 0, count: nArrayLength * v7);
          if ( nSrcStride == v7 && nDataTypeSize == nSrcStride )
          {
            memcpy(dst: v8, src: pSrc, count: nArrayLength * v7);
          }
          else
          {
            v9 = pSrc;
            if ( nArrayLength > 0 )
            {
              for ( pSrca = (char *)nArrayLength; pSrca != nullptr; --pSrca )
              {
                memcpy(dst: v8, src: v9, count: nDataTypeSize);
                v9 = (const __m128i *)((char *)v9 + nSrcStride);
                v8 = (__m128i *)((char *)v8 + v7);
              }
            }
          }
        }
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056DAE0
// Name: _dynamic_initializer_for__CDmxAttribute::s_AttributeNameSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxAttribute::s_AttributeNameSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(this: &CDmxAttribute::s_AttributeNameSymbols);
  return atexit(func: dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x0056F6A0
// Name: _dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(this: &CDmxAttribute::s_AttributeNameSymbols);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&CDmxAttribute::s_AttributeNameSymbols.m_StringPools);
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &CDmxAttribute::s_AttributeNameSymbols.m_Lookup);
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmxAttribute::s_AttributeNameSymbols.m_Lookup.m_EntryMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00562F00
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class CSOAContainer_Serializable>(class CSOAContainer_Serializable __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<CSOAContainer_Serializable>()
{
  if ( (_S1_5 & 1) == 0 )
  {
    _S1_5 |= 1u;
    dword_5BB240 = 2;
    dword_5BB244 = 0;
    dword_5BB248 = 4;
    dword_5BB24C = -1;
    dword_5BB250 = 0;
    dword_5BB254 = 0;
    dword_5BB258 = 0;
    dword_5BB25C = 0;
    dword_5BB260 = 0;
    dword_5BB264 = (int)"num_rows";
    dword_5BB268 = (int)"0";
    dword_5BB26C = 2;
    dword_5BB270 = 4;
    dword_5BB274 = 4;
    dword_5BB278 = -1;
    dword_5BB27C = 0;
    dword_5BB280 = 0;
    dword_5BB284 = 0;
    dword_5BB288 = 0;
    dword_5BB28C = 0;
    dword_5BB290 = (int)"num_slices";
    dword_5BB294 = (int)"0";
    dword_5BB298 = 2;
    dword_5BB29C = 8;
    dword_5BB2A0 = 4;
    dword_5BB2A4 = -1;
    dword_5BB2A8 = 0;
    dword_5BB2AC = 0;
    dword_5BB2B0 = 0;
    dword_5BB2B4 = 0;
    dword_5BB2B8 = 0;
    dword_5BB2BC = (int)"attribute_types";
    dword_5BB2C0 = (int)"-1";
    dword_5BB2C4 = 16;
    dword_5BB2C8 = 152;
    dword_5BB2CC = 4;
    dword_5BB2D0 = -1;
    dword_5BB2D4 = 0;
    dword_5BB2D8 = 0;
    dword_5BB2DC = 0;
    dword_5BB2E0 = 0;
    dword_5BB2E4 = 32;
    dword_5BB2E8 = (int)"field_present_mask";
    dword_5BB2EC = (int)"0";
    dword_5BB2F0 = 2;
    dword_5BB2F4 = 664;
    dword_5BB2F8 = 4;
    dword_5BB2FC = -1;
    dword_5BB300 = 0;
    dword_5BB304 = 0;
    dword_5BB308 = 0;
    dword_5BB30C = 0;
    dword_5BB310 = 0;
    dword_5BB314 = (int)"thread_mode";
    dword_5BB318 = (int)"-1";
    dword_5BB31C = 2;
    dword_5BB320 = 800;
    dword_5BB324 = 4;
    dword_5BB328 = -1;
    dword_5BB32C = 0;
    dword_5BB330 = 0;
    dword_5BB334 = 0;
    dword_5BB338 = 0;
    dword_5BB33C = 0;
    dword_5BB340 = 0;
    dword_5BB344 = 0;
    dword_5BB348 = 0;
    dword_5BB34C = 0;
    dword_5BB350 = 0;
    dword_5BB354 = -1;
    dword_5BB358 = 0;
    dword_5BB35C = 0;
    dword_5BB360 = 0;
    dword_5BB364 = 0;
    dword_5BB368 = 0;
  }
  return unpack_2;
}

//------------------------------------------------------------------------------
// Address: 0x0056F6D0
// Name: _dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__()
{
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::RemoveAll(this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools);
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::~CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>(this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup);
}

} // namespace particle_import

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x006A2890
// Name: public: static enum DmAttributeType_t CDmxAttribute::ArrayAttributeBasicType(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
DmAttributeType_t __cdecl CDmxAttribute::ArrayAttributeBasicType(DmAttributeType_t type)
{
  DmAttributeType_t result; // eax

  result = type;
  if ( (unsigned int)(type - 15) <= 0xD )
    return type - 14;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006A28B0
// Name: public: char const __near * CDmxAttribute::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxAttribute::GetName(CDmxAttribute *this)
{
  const char *result; // eax

  result = this->m_Name.u.m_pAsString;
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006A28C0
// Name: private: void CDmxAttribute::ConstructDataMemory<class CUtlVector<class Color,class CUtlMemory<class Color,int>>,class Color>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::ConstructDataMemory<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(CDmxAttribute *this)
{
  _DWORD *m_pData; // eax

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    *m_pData = 0;
    m_pData[1] = 0;
    m_pData[2] = 0;
    m_pData[3] = 0;
    m_pData[4] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A28E0
// Name: private: void CDmxAttribute::DestructDataMemory<class CUtlBinaryBlock,class CUtlBinaryBlock>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::DestructDataMemory<CUtlBinaryBlock,CUtlBinaryBlock>(CDmxAttribute *this)
{
  int *m_pData; // esi
  bool v2; // sf

  m_pData = (int *)this->m_pData;
  v2 = m_pData[2] < 0;
  m_pData[3] = 0;
  if ( !v2 )
  {
    if ( *m_pData != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*m_pData);
      *m_pData = 0;
    }
    m_pData[1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A2920
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<int,class CUtlMemory<int,int>>,int>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<int,CUtlMemory<int,int>>,int>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  char v4; // al
  CUtlMemory<vgui::TreeNode *,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  v4 = Unserialize(buf, dest: (int *)&buf);
  *bSuccess = v4;
  if ( v4 != 0 )
  {
    m_pData = (CUtlMemory<vgui::TreeNode *,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: m_pData, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
        count: 4 * v9);
    v10 = &m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)buf;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A29A0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<float,class CUtlMemory<float,int>>,float>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<float,CUtlMemory<float,int>>,float>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  char v4; // al
  CUtlMemory<vgui::TreeNode *,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  v4 = Unserialize(buf, dest: (float *)&buf);
  *bSuccess = v4;
  if ( v4 != 0 )
  {
    m_pData = (CUtlMemory<vgui::TreeNode *,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: m_pData, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
        count: 4 * v9);
    v10 = &m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)buf;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A2A20
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<bool,class CUtlMemory<bool,int>>,bool>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  char v4; // al
  CUtlMemory<unsigned char,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // edi
  unsigned __int8 *v8; // ecx
  signed int v9; // eax
  unsigned __int8 *v10; // esi

  v4 = Unserialize(buf, dest: (bool *)&buf + 3);
  *bSuccess = v4;
  if ( v4 != 0 )
  {
    m_pData = (CUtlMemory<unsigned char,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)(m_pMemory + 1) > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow(this: m_pData, num: (int)&m_pMemory[-m_nAllocationCount + 1]);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = m_pData[1].m_pMemory - m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[(_DWORD)m_pMemory + 1], src: &v8[(_DWORD)m_pMemory], count: v9);
    v10 = &m_pMemory[(unsigned int)m_pData->m_pMemory];
    if ( v10 != nullptr )
      *v10 = HIBYTE(buf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A2A90
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,class CUtlString>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlString temp; // [esp+4h] [ebp-10h] BYREF

  CUtlString::CUtlString(this: &temp);
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
      this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
  temp.m_Storage.m_nActualLength = 0;
  if ( temp.m_Storage.m_Memory.m_nGrowSize >= 0 && temp.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x006A2B00
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>,class CUtlBinaryBlock>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlBinaryBlock temp; // [esp+4h] [ebp-10h] BYREF

  CUtlBinaryBlock::CUtlBinaryBlock(this: &temp, growSize: 0, initSize: 0);
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
      this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
  temp.m_nActualLength = 0;
  if ( temp.m_Memory.m_nGrowSize >= 0 && temp.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x006A2B70
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>,class DmeTime_t>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  char v4; // al
  CUtlMemory<vgui::TreeNode *,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  DmeTime_t *v10; // eax
  DmeTime_t temp; // [esp+4h] [ebp-4h] BYREF

  temp.m_tms = 0x80000000;
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 != 0 )
  {
    m_pData = (CUtlMemory<vgui::TreeNode *,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: m_pData, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
        count: 4 * v9);
    v10 = (DmeTime_t *)&m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      v10->m_tms = temp.m_tms;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A2C00
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Color,class CUtlMemory<class Color,int>>,class Color>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlMemory<vgui::TreeNode *,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  Color *v10; // eax
  Color temp; // [esp+4h] [ebp-4h] BYREF

  temp = 0;
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
  {
    m_pData = (CUtlMemory<vgui::TreeNode *,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: m_pData, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
        count: 4 * v9);
    v10 = (Color *)&m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      *v10 = temp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A2C90
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>,class Vector2D>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Vector2D temp; // [esp+4h] [ebp-8h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: (CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x006A2CD0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector,class CUtlMemory<class Vector,int>>,class Vector>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  QAngle temp; // [esp+4h] [ebp-Ch] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x006A2D10
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>,class Vector4D>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>,Vector4D>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Vector4D temp; // [esp+4h] [ebp-10h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::InsertBefore(
      this: (CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x006A2D50
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>,class Quaternion>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Quaternion temp; // [esp+4h] [ebp-10h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertBefore(
      this: (CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x006A2D90
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>,class VMatrix>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  VMatrix temp; // [esp+4h] [ebp-40h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x006A2F40
// Name: private: CDmxAttribute::CDmxAttribute(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxAttribute *__thiscall CDmxAttribute::CDmxAttribute(CDmxAttribute *this, char *pAttributeName)
{
  char *v4; // [esp-4h] [ebp-8h]

  v4 = pAttributeName;
  this->m_Name.u.m_Id = -1;
  this->m_Name = (CUtlSymbolLarge)CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
                                    this: &CDmxAttribute::s_AttributeNameSymbols,
                                    result: (CUtlSymbolLarge *)&pAttributeName,
                                    pString: v4)->u.m_Id;
  this->m_Type = AT_UNKNOWN;
  this->m_pData = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x006A2F80
// Name: public: void CDmxAttribute::SetToDefaultValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetToDefaultValue(CDmxAttribute *this)
{
  _DWORD *m_pData; // ecx
  _DWORD *v2; // ecx
  _DWORD *v3; // ecx
  _DWORD *v4; // ecx

  switch ( this->m_Type )
  {
    case AT_FIRST_VALUE_TYPE:
      *(_DWORD *)this->m_pData = 0;
      break;
    case AT_INT:
    case AT_TIME:
      *(_DWORD *)this->m_pData = 0;
      break;
    case AT_FLOAT:
      *(_DWORD *)this->m_pData = 0;
      break;
    case AT_BOOL:
      *(_BYTE *)this->m_pData = 0;
      break;
    case AT_STRING:
      CUtlString::Set(this: (CUtlString *)this->m_pData, pValue: nullptr);
      break;
    case AT_VOID:
      CUtlBinaryBlock::Set(this: (CUtlBinaryBlock *)this->m_pData, pValue: nullptr, nLen: 0);
      break;
    case AT_COLOR:
      *(_DWORD *)this->m_pData = -16777216;
      break;
    case AT_VECTOR2:
      m_pData = this->m_pData;
      *m_pData = 0;
      m_pData[1] = 0;
      break;
    case AT_VECTOR3:
    case AT_QANGLE:
      v2 = this->m_pData;
      *v2 = 0;
      v2[1] = 0;
      v2[2] = 0;
      break;
    case AT_VECTOR4:
      v3 = this->m_pData;
      *v3 = 0;
      v3[1] = 0;
      v3[2] = 0;
      v3[3] = 0;
      break;
    case AT_QUATERNION:
      v4 = this->m_pData;
      *v4 = 0;
      v4[1] = 0;
      v4[2] = 0;
      v4[3] = 1065353216;
      break;
    case AT_VMATRIX:
      MatrixSetIdentity(dst: (VMatrix *)this->m_pData);
      break;
    case AT_FIRST_ARRAY_TYPE:
    case AT_INT_ARRAY:
    case AT_FLOAT_ARRAY:
    case AT_BOOL_ARRAY:
    case AT_TIME_ARRAY:
    case AT_COLOR_ARRAY:
    case AT_VECTOR2_ARRAY:
    case AT_VECTOR3_ARRAY:
    case AT_VECTOR4_ARRAY:
    case AT_QANGLE_ARRAY:
    case AT_QUATERNION_ARRAY:
    case AT_VMATRIX_ARRAY:
      *((_DWORD *)this->m_pData + 3) = 0;
      break;
    case AT_STRING_ARRAY:
    case AT_VOID_ARRAY:
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A30E0
// Name: private: void CDmxAttribute::FreeDataMemory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::FreeDataMemory(CDmxAttribute *this)
{
  if ( this->m_Type != AT_UNKNOWN )
  {
    switch ( this->m_Type )
    {
      case AT_STRING:
      case AT_VOID:
        CDmxAttribute::DestructDataMemory<CUtlBinaryBlock,CUtlBinaryBlock>(this);
        this->m_Type = AT_UNKNOWN;
        break;
      case AT_FIRST_ARRAY_TYPE:
        CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)this->m_pData);
        goto $LN130_2;
      case AT_INT_ARRAY:
      case AT_FLOAT_ARRAY:
      case AT_BOOL_ARRAY:
      case AT_TIME_ARRAY:
      case AT_COLOR_ARRAY:
      case AT_VECTOR2_ARRAY:
      case AT_VECTOR3_ARRAY:
      case AT_VECTOR4_ARRAY:
      case AT_QANGLE_ARRAY:
      case AT_QUATERNION_ARRAY:
      case AT_VMATRIX_ARRAY:
        CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)this->m_pData);
        this->m_Type = AT_UNKNOWN;
        break;
      case AT_STRING_ARRAY:
      case AT_VOID_ARRAY:
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData);
        this->m_Type = AT_UNKNOWN;
        break;
      default:
$LN130_2:
        this->m_Type = AT_UNKNOWN;
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A3260
// Name: private: CDmxAttribute::~CDmxAttribute(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDmxAttribute::~CDmxAttribute(CDmxAttribute *this)
{
  CDmxAttribute::FreeDataMemory(this);
}

//------------------------------------------------------------------------------
// Address: 0x006A3270
// Name: private: void CDmxAttribute::AllocateDataMemory(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::AllocateDataMemory(CDmxAttribute *this, DmAttributeType_t type)
{
  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = type;
  this->m_pData = DMXAlloc(size: s_pAttributeSize[type]);
}

//------------------------------------------------------------------------------
// Address: 0x006A32A0
// Name: private: void CDmxAttribute::AllocateDataMemory_AndConstruct(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::AllocateDataMemory_AndConstruct(CDmxAttribute *this, DmAttributeType_t type)
{
  CUtlString *v3; // ecx
  __int32 v4; // eax

  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = type;
  v3 = (CUtlString *)DMXAlloc(size: s_pAttributeSize[type]);
  v4 = this->m_Type - 1;
  this->m_pData = v3;
  switch ( v4 )
  {
    case 4:
      if ( v3 != nullptr )
        CUtlString::CUtlString(this: v3);
      break;
    case 5:
      if ( v3 != nullptr )
        CUtlBinaryBlock::CUtlBinaryBlock(this: &v3->m_Storage, growSize: 0, initSize: 0);
      break;
    case 6:
      if ( v3 != nullptr )
        v3->m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)0x80000000;
      break;
    case 7:
      if ( v3 != nullptr )
        v3->m_Storage.m_Memory.m_pMemory = nullptr;
      break;
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
      CDmxAttribute::ConstructDataMemory<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(this);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A3440
// Name: public: bool CDmxAttribute::Unserialize(enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::Unserialize(CDmxAttribute *this, DmAttributeType_t type, CUtlBuffer *buf)
{
  bool result; // al

  CDmxAttribute::AllocateDataMemory_AndConstruct(this, type);
  result = false;
  switch ( this->m_Type )
  {
    case AT_INT:
      result = Unserialize(buf, dest: (int *)this->m_pData);
      break;
    case AT_FLOAT:
      result = Unserialize(buf, dest: (float *)this->m_pData);
      break;
    case AT_BOOL:
      result = Unserialize(buf, dest: (bool *)this->m_pData);
      break;
    case AT_STRING:
      result = Unserialize(buf, dest: (CUtlString *)this->m_pData);
      break;
    case AT_VOID:
      result = Unserialize(buf, dest: (CUtlBinaryBlock *)this->m_pData);
      break;
    case AT_TIME:
      result = Unserialize(buf, dest: (DmeTime_t *)this->m_pData);
      break;
    case AT_COLOR:
      result = Unserialize(buf, dest: (Color *)this->m_pData);
      break;
    case AT_VECTOR2:
      result = Unserialize(buf, dest: (Vector2D *)this->m_pData);
      break;
    case AT_VECTOR3:
    case AT_QANGLE:
      result = Unserialize(buf, dest: (QAngle *)this->m_pData);
      break;
    case AT_VECTOR4:
      result = Unserialize(buf, dest: (Vector4D *)this->m_pData);
      break;
    case AT_QUATERNION:
      result = Unserialize(buf, dest: (Quaternion *)this->m_pData);
      break;
    case AT_VMATRIX:
      result = Unserialize(buf, dest: (VMatrix *)this->m_pData);
      break;
    case AT_INT_ARRAY:
      result = Unserialize<int>(
                 buf,
                 dest: (CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int> > *)this->m_pData);
      break;
    case AT_FLOAT_ARRAY:
      result = Unserialize<float>(
                 buf,
                 dest: (CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int> > *)this->m_pData);
      break;
    case AT_BOOL_ARRAY:
      result = Unserialize<bool>(
                 buf,
                 dest: (CDmaArrayBase<bool,CDmaDataInternal<CUtlVector<bool,CUtlMemory<bool,int> > > > *)this->m_pData);
      break;
    case AT_STRING_ARRAY:
      result = Unserialize<CUtlString>(buf, dest: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData);
      break;
    case AT_VOID_ARRAY:
      result = Unserialize<CUtlBinaryBlock>(
                 buf,
                 dest: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData);
      break;
    case AT_TIME_ARRAY:
      result = Unserialize<DmeTime_t>(
                 buf,
                 dest: (CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int> > *)this->m_pData);
      break;
    case AT_COLOR_ARRAY:
      result = Unserialize<Color>(
                 buf,
                 dest: (CUtlVector<CDmeHandle<CDmElement,0>,CUtlMemory<CDmeHandle<CDmElement,0>,int> > *)this->m_pData);
      break;
    case AT_VECTOR2_ARRAY:
      result = Unserialize<Vector2D>(
                 buf,
                 dest: (CUtlVector<DmePickerInfo_t,CUtlMemory<DmePickerInfo_t,int> > *)this->m_pData);
      break;
    case AT_VECTOR3_ARRAY:
    case AT_QANGLE_ARRAY:
      result = Unserialize<QAngle>(
                 buf,
                 dest: (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this->m_pData);
      break;
    case AT_VECTOR4_ARRAY:
      result = Unserialize<Vector4D>(
                 buf,
                 dest: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this->m_pData);
      break;
    case AT_QUATERNION_ARRAY:
      result = Unserialize<Quaternion>(
                 buf,
                 dest: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this->m_pData);
      break;
    case AT_VMATRIX_ARRAY:
      result = Unserialize<VMatrix>(
                 buf,
                 dest: (CDmaArrayBase<VMatrix,CDmaDataInternal<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > > *)this->m_pData);
      break;
    default:
      return result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006A3700
// Name: public: bool CDmxAttribute::UnserializeElement(enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::UnserializeElement(CDmxAttribute *this, DmAttributeType_t type, CUtlBuffer *buf)
{
  bool result; // al
  __int32 v5; // eax

  if ( (unsigned int)(type - 15) > 0xD )
    return false;
  if ( this->m_Type != type )
    CDmxAttribute::AllocateDataMemory_AndConstruct(this, type);
  v5 = this->m_Type - 16;
  HIBYTE(type) = 0;
  switch ( v5 )
  {
    case 0:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<int,CUtlMemory<int,int>>,int>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 1:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<float,CUtlMemory<float,int>>,float>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 2:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 3:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 4:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 5:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 6:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 7:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 8:
    case 10:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 9:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>,Vector4D>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 11:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 12:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      goto LABEL_18;
    default:
LABEL_18:
      result = HIBYTE(type);
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006A38A0
// Name: public: void CDmxAttribute::SetValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetValue(CDmxAttribute *this, char *pString)
{
  CUtlString *v3; // eax
  CUtlString *v4; // edi

  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = AT_STRING;
  v3 = (CUtlString *)DMXAlloc(size: s_pAttributeSize[5]);
  v4 = v3;
  this->m_pData = v3;
  if ( v3 != nullptr )
    CUtlString::CUtlString(this: v3);
  CUtlString::Set(this: v4, pValue: pString);
}

//------------------------------------------------------------------------------
// Address: 0x006A38F0
// Name: public: void CDmxAttribute::SetValueFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetValueFromString(CDmxAttribute *this, char *pValue)
{
  unsigned int v3; // eax
  CUtlString *v4; // eax
  CUtlString *v5; // edi
  CUtlBuffer buf; // [esp+4h] [ebp-30h] BYREF

  if ( this->m_Type != AT_UNKNOWN )
  {
    if ( this->m_Type == AT_STRING )
    {
      CDmxAttribute::FreeDataMemory(this);
      this->m_Type = AT_STRING;
      v4 = (CUtlString *)DMXAlloc(size: s_pAttributeSize[5]);
      v5 = v4;
      this->m_pData = v4;
      if ( v4 != nullptr )
        CUtlString::CUtlString(this: v4);
      CUtlString::Set(this: v5, pValue);
    }
    else if ( pValue != nullptr && (v3 = _V_strlen(str: pValue)) != 0 )
    {
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: (unsigned __int8 *)pValue, nSize: v3, nFlags: 9u);
      if ( !CDmxAttribute::Unserialize(this, type: this->m_Type, &buf) )
        CDmxAttribute::SetToDefaultValue(this);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
    else
    {
      CDmxAttribute::SetToDefaultValue(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A39C0
// Name: private: void CDmxAttribute::GetArrayValue(enum DmAttributeType_t,void __near *,int,int,char const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::GetArrayValue(
        CDmxAttribute *this,
        DmAttributeType_t type,
        __m128i *pDest,
        int nDataTypeSize,
        int nDestArrayLength,
        char *pDefaultString)
{
  DmAttributeType_t m_Type; // esi
  int v7; // ebx
  int v8; // edi
  _DWORD *m_pData; // eax
  const __m128i *v10; // eax
  __m128i *v11; // esi
  const __m128i *v12; // ebx
  __m128i *v13; // esi
  int v14; // ebx
  const __m128i *v15; // edi
  CDmxAttribute temp; // [esp+0h] [ebp-14h] BYREF
  DmAttributeType_t v17; // [esp+Ch] [ebp-8h]
  int nSrcStride; // [esp+10h] [ebp-4h]
  DmAttributeType_t typea; // [esp+1Ch] [ebp+8h]

  if ( (unsigned int)(type - 15) <= 0xD )
  {
    m_Type = this->m_Type;
    if ( this->m_Type == type )
    {
      v7 = s_pAttributeSize[type - 14];
      v17 = type - 14;
      nSrcStride = v7;
      if ( nDataTypeSize >= v7 )
        nDataTypeSize = v7;
      v8 = 0;
      if ( (unsigned int)(m_Type - 15) <= 0xD )
      {
        m_pData = this->m_pData;
        if ( m_pData != nullptr )
          v8 = m_pData[3];
      }
      v10 = nullptr;
      switch ( m_Type )
      {
        case AT_FIRST_ARRAY_TYPE:
        case AT_FLOAT_ARRAY:
        case AT_VOID_ARRAY:
        case AT_VECTOR2_ARRAY:
        case AT_QANGLE_ARRAY:
          v10 = *(const __m128i **)this->m_pData;
          break;
        case AT_INT_ARRAY:
        case AT_STRING_ARRAY:
        case AT_COLOR_ARRAY:
        case AT_VECTOR4_ARRAY:
        case AT_VMATRIX_ARRAY:
          v10 = *(const __m128i **)this->m_pData;
          break;
        case AT_BOOL_ARRAY:
        case AT_TIME_ARRAY:
        case AT_VECTOR3_ARRAY:
        case AT_QUATERNION_ARRAY:
          v10 = *(const __m128i **)this->m_pData;
          break;
        default:
          break;
      }
      if ( v8 != 0 && v10 != nullptr )
      {
        if ( v7 == nDataTypeSize )
        {
          memcpy(dst: pDest, src: v10, count: nDataTypeSize * v8);
        }
        else
        {
          v11 = pDest;
          v12 = v10;
          if ( v8 > 0 )
          {
            for ( typea = v8; typea != AT_UNKNOWN; --typea )
            {
              memcpy(dst: v11, src: v12, count: nDataTypeSize);
              v11 = (__m128i *)((char *)v11 + nDataTypeSize);
              v12 = (const __m128i *)((char *)v12 + nSrcStride);
            }
          }
        }
      }
      if ( v8 < nDestArrayLength && pDefaultString != nullptr )
      {
        temp.m_Name.u.m_Id = -1;
        temp.m_Type = AT_UNKNOWN;
        temp.m_pData = nullptr;
        CDmxAttribute::AllocateDataMemory_AndConstruct(this: &temp, type: v17);
        CDmxAttribute::SetValueFromString(this: &temp, pValue: pDefaultString);
        v13 = (__m128i *)((char *)pDest + nDataTypeSize * v8);
        v14 = nDestArrayLength - v8;
        v15 = (const __m128i *)temp.m_pData;
        do
        {
          memcpy(dst: v13, src: v15, count: nDataTypeSize);
          v13 = (__m128i *)((char *)v13 + nDataTypeSize);
          --v14;
        }
        while ( v14 != 0 );
        CDmxAttribute::FreeDataMemory(this: &temp);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006B33D0
// Name: _dynamic_initializer_for__CDmxAttribute::s_AttributeNameSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxAttribute::s_AttributeNameSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(this: &CDmxAttribute::s_AttributeNameSymbols);
  return atexit(func: dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x006B6110
// Name: _dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(this: &CDmxAttribute::s_AttributeNameSymbols);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&CDmxAttribute::s_AttributeNameSymbols.m_StringPools);
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &CDmxAttribute::s_AttributeNameSymbols.m_Lookup);
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmxAttribute::s_AttributeNameSymbols.m_Lookup.m_EntryMemory);
}

} // namespace sceneviewer

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00426FA0
// Name: public: class CUtlString const __near & CDmxAttribute::GetValue<class CUtlString>(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlString *__thiscall CDmxAttribute::GetValue<CUtlString>(CDmxAttribute *this)
{
  if ( this->m_Type == AT_STRING )
    return (const CUtlString *)this->m_pData;
  if ( (`CDmxAttribute::GetValue<CUtlString>'::`4'::`local static guard' & 1) == 0 )
  {
    `CDmxAttribute::GetValue<CUtlString>'::`4'::`local static guard' |= 1u;
    CUtlString::CUtlString(this: &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue);
    atexit(func: `CDmxAttribute::GetValue<CUtlString>'::`4'::`dynamic atexit destructor for 'defaultValue'');
  }
  CUtlString::Set(this: &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue, pValue: nullptr);
  return &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x0052D1A0
// Name: public: static enum DmAttributeType_t CDmxAttribute::ArrayAttributeBasicType(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
DmAttributeType_t __cdecl CDmxAttribute::ArrayAttributeBasicType(DmAttributeType_t type)
{
  DmAttributeType_t result; // eax

  result = type;
  if ( (unsigned int)(type - 15) <= 0xD )
    return type - 14;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052D1B0
// Name: public: char const __near * CDmxAttribute::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxAttribute::GetName(CDmxAttribute *this)
{
  const char *result; // eax

  result = this->m_Name.u.m_pAsString;
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052D1C0
// Name: private: void CDmxAttribute::SerializeType<int,int>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<int,int>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  int src; // [esp+4h] [ebp-4h] BYREF

  src = (int)this;
  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const int *)this->m_pData);
  }
  else
  {
    src = 0;
    v3 = Serialize(buf, &src);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x0052D1F0
// Name: private: void CDmxAttribute::SerializeType<float,float>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<float,float>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  CDmxAttribute *src; // [esp+4h] [ebp-4h] BYREF

  src = this;
  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const float *)this->m_pData);
  }
  else
  {
    src = nullptr;
    v3 = Serialize(buf, (const float *)&src);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x0052D220
// Name: private: void CDmxAttribute::SerializeType<bool,bool>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<bool,bool>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  bool src; // [esp+5h] [ebp-1h] BYREF

  src = HIBYTE(this);
  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const bool *)this->m_pData);
  }
  else
  {
    src = false;
    v3 = Serialize(buf, &src);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x0052D250
// Name: private: void CDmxAttribute::SerializeType<class DmeTime_t,class DmeTime_t>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<DmeTime_t,DmeTime_t>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  DmeTime_t src; // [esp+4h] [ebp-4h] BYREF

  src.m_tms = (int)this;
  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const DmeTime_t *)this->m_pData);
  }
  else
  {
    src.m_tms = 0;
    v3 = Serialize(buf, &src);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x0052D280
// Name: private: void CDmxAttribute::SerializeType<class Color,class Color>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<Color,Color>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  const Color *m_pData; // eax
  bool v4; // al
  Color src; // [esp+4h] [ebp-4h] BYREF

  src = (Color)this;
  m_pData = (const Color *)this->m_pData;
  if ( m_pData != nullptr )
  {
    v4 = Serialize(buf, src: m_pData);
  }
  else
  {
    src._color[0] = 0;
    src._color[1] = 0;
    src._color[2] = 0;
    src._color[3] = -1;
    v4 = Serialize(buf, &src);
  }
  *bSuccess = v4;
}

//------------------------------------------------------------------------------
// Address: 0x0052D2C0
// Name: private: void CDmxAttribute::SerializeType<class Vector2D,class Vector2D>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<Vector2D,Vector2D>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  Vector2D temp; // [esp+0h] [ebp-Ch] BYREF
  int v5; // [esp+8h] [ebp-4h]

  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const Vector2D *)this->m_pData);
  }
  else
  {
    temp.y = 0.0;
    v5 = 0;
    v3 = Serialize(buf, src: (Vector2D *)&temp.y);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x0052D300
// Name: private: void CDmxAttribute::SerializeType<class Vector,class Vector>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<Vector,Vector>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  QAngle temp; // [esp+0h] [ebp-10h] BYREF
  int v5; // [esp+Ch] [ebp-4h]

  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const QAngle *)this->m_pData);
  }
  else
  {
    temp.y = 0.0;
    temp.z = 0.0;
    v5 = 0;
    v3 = Serialize(buf, src: (QAngle *)&temp.y);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x0052D340
// Name: private: void CDmxAttribute::SerializeType<class Vector4D,class Vector4D>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<Vector4D,Vector4D>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  Vector4D temp; // [esp+0h] [ebp-14h] BYREF
  int v5; // [esp+10h] [ebp-4h]

  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const Quaternion *)this->m_pData);
  }
  else
  {
    memset(&temp.y, 0, 12);
    v5 = 0;
    v3 = Serialize(buf, src: (const Quaternion *)&temp.y);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x0052D390
// Name: private: void CDmxAttribute::SerializeType<class Quaternion,class Quaternion>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<Quaternion,Quaternion>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v3; // al
  Quaternion temp; // [esp+0h] [ebp-14h] BYREF
  int v5; // [esp+10h] [ebp-4h]

  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const Quaternion *)this->m_pData);
  }
  else
  {
    memset(&temp.y, 0, 12);
    v5 = 1065353216;
    v3 = Serialize(buf, src: (Quaternion *)&temp.y);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x0052D3E0
// Name: private: void CDmxAttribute::SerializeType<class VMatrix,class VMatrix>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<VMatrix,VMatrix>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  VMatrix temp; // [esp+0h] [ebp-44h] BYREF

  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const VMatrix *)this->m_pData);
  }
  else
  {
    MatrixSetIdentity(dst: (VMatrix *)&temp.m[0][1]);
    v3 = Serialize(buf, src: (VMatrix *)&temp.m[0][1]);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x0052D430
// Name: private: void CDmxAttribute::UnserializeType<int,int>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeType<int,int>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  *bSuccess = Unserialize(buf, dest: (int *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x0052D450
// Name: private: void CDmxAttribute::UnserializeType<float,float>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeType<float,float>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  *bSuccess = Unserialize(buf, dest: (float *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x0052D470
// Name: private: void CDmxAttribute::UnserializeType<bool,bool>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeType<bool,bool>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  *bSuccess = Unserialize(buf, dest: (bool *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x0052D490
// Name: private: void CDmxAttribute::UnserializeType<class CUtlString,class CUtlString>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeType<CUtlString,CUtlString>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  *bSuccess = Unserialize(buf, dest: (CUtlString *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x0052D4B0
// Name: private: void CDmxAttribute::UnserializeType<class CUtlBinaryBlock,class CUtlBinaryBlock>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeType<CUtlBinaryBlock,CUtlBinaryBlock>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  *bSuccess = Unserialize(buf, dest: (CUtlBinaryBlock *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x0052D4D0
// Name: private: void CDmxAttribute::UnserializeType<class DmeTime_t,class DmeTime_t>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeType<DmeTime_t,DmeTime_t>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  *bSuccess = Unserialize(buf, dest: (DmeTime_t *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x0052D4F0
// Name: private: void CDmxAttribute::UnserializeType<class Color,class Color>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeType<Color,Color>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  *bSuccess = Unserialize(buf, dest: (Color *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x0052D510
// Name: private: void CDmxAttribute::UnserializeType<class Vector2D,class Vector2D>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeType<Vector2D,Vector2D>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  *bSuccess = Unserialize(buf, dest: (Vector2D *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x0052D530
// Name: private: void CDmxAttribute::UnserializeType<class Vector,class Vector>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeType<Vector,Vector>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  *bSuccess = Unserialize(buf, dest: (QAngle *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x0052D550
// Name: private: void CDmxAttribute::UnserializeType<class Vector4D,class Vector4D>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeType<Vector4D,Vector4D>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  *bSuccess = Unserialize(buf, dest: (Vector4D *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x0052D570
// Name: private: void CDmxAttribute::UnserializeType<class Quaternion,class Quaternion>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeType<Quaternion,Quaternion>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  *bSuccess = Unserialize(buf, dest: (Quaternion *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x0052D590
// Name: private: void CDmxAttribute::UnserializeType<class VMatrix,class VMatrix>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeType<VMatrix,VMatrix>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  *bSuccess = Unserialize(buf, dest: (VMatrix *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x0052D5B0
// Name: private: void CDmxAttribute::ConstructDataMemory<class CUtlBinaryBlock,class CUtlBinaryBlock>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::ConstructDataMemory<CUtlBinaryBlock,CUtlBinaryBlock>(CDmxAttribute *this)
{
  CUtlBinaryBlock *m_pData; // ecx

  m_pData = (CUtlBinaryBlock *)this->m_pData;
  if ( m_pData != nullptr )
    CUtlBinaryBlock::CUtlBinaryBlock(this: m_pData, growSize: 0, initSize: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0052D5D0
// Name: public: int CDmxAttribute::GetArrayCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxAttribute::GetArrayCount(CDmxAttribute *this)
{
  DmAttributeType_t m_Type; // edx
  int result; // eax
  _DWORD *m_pData; // ecx

  m_Type = this->m_Type;
  result = 0;
  if ( (unsigned int)(this->m_Type - 15) <= 0xD )
  {
    m_pData = this->m_pData;
    if ( m_pData != nullptr )
    {
      switch ( m_Type )
      {
        case AT_FIRST_ARRAY_TYPE:
        case AT_INT_ARRAY:
        case AT_FLOAT_ARRAY:
        case AT_BOOL_ARRAY:
        case AT_STRING_ARRAY:
        case AT_VOID_ARRAY:
        case AT_TIME_ARRAY:
        case AT_COLOR_ARRAY:
        case AT_VECTOR2_ARRAY:
        case AT_VECTOR3_ARRAY:
        case AT_VECTOR4_ARRAY:
        case AT_QANGLE_ARRAY:
        case AT_QUATERNION_ARRAY:
        case AT_VMATRIX_ARRAY:
          result = m_pData[3];
          break;
        default:
          return result;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052D630
// Name: private: void const __near * CDmxAttribute::GetArrayBase(void)const
// Source: json
//------------------------------------------------------------------------------
const void *__thiscall CDmxAttribute::GetArrayBase(CDmxAttribute *this)
{
  const void *result; // eax

  result = nullptr;
  switch ( this->m_Type )
  {
    case AT_FIRST_ARRAY_TYPE:
    case AT_FLOAT_ARRAY:
    case AT_VOID_ARRAY:
    case AT_VECTOR2_ARRAY:
    case AT_QANGLE_ARRAY:
      result = *(const void **)this->m_pData;
      break;
    case AT_INT_ARRAY:
    case AT_STRING_ARRAY:
    case AT_COLOR_ARRAY:
    case AT_VECTOR4_ARRAY:
    case AT_VMATRIX_ARRAY:
      result = *(const void **)this->m_pData;
      break;
    case AT_BOOL_ARRAY:
    case AT_TIME_ARRAY:
    case AT_VECTOR3_ARRAY:
    case AT_QUATERNION_ARRAY:
      result = *(const void **)this->m_pData;
      break;
    default:
      return result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052D690
// Name: private: void CDmxAttribute::SerializeType<class CUtlBinaryBlock,class CUtlBinaryBlock>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlBinaryBlock,CUtlBinaryBlock>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v3; // al
  bool v4; // sf
  CUtlBinaryBlock temp; // [esp+0h] [ebp-14h] BYREF
  int v6; // [esp+10h] [ebp-4h]

  if ( this->m_pData != nullptr )
  {
    *bSuccess = Serialize(buf, src: (const CUtlBinaryBlock *)this->m_pData);
  }
  else
  {
    CUtlBinaryBlock::CUtlBinaryBlock(
      this: (CUtlBinaryBlock *)&temp.m_Memory.m_nAllocationCount,
      growSize: 0,
      initSize: 0);
    CUtlBinaryBlock::Set(this: (CUtlBinaryBlock *)&temp.m_Memory.m_nAllocationCount, pValue: nullptr, nLen: 0);
    v3 = Serialize(buf, src: (const CUtlBinaryBlock *)&temp.m_Memory.m_nAllocationCount);
    v4 = temp.m_nActualLength < 0;
    *bSuccess = v3;
    v6 = 0;
    if ( !v4 && temp.m_Memory.m_nAllocationCount != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)temp.m_Memory.m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052D790
// Name: private: void CDmxAttribute::ConstructDataMemory<class CUtlVector<class Color,class CUtlMemory<class Color,int>>,class Color>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::ConstructDataMemory<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(CDmxAttribute *this)
{
  _DWORD *m_pData; // eax

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    *m_pData = 0;
    m_pData[1] = 0;
    m_pData[2] = 0;
    m_pData[3] = 0;
    m_pData[4] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052D7B0
// Name: private: void CDmxAttribute::SerializeType<class CUtlString,class CUtlString>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlString,CUtlString>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v3; // al
  bool v4; // sf
  CUtlString temp; // [esp+0h] [ebp-14h] BYREF
  int v6; // [esp+10h] [ebp-4h]

  if ( this->m_pData != nullptr )
  {
    *bSuccess = Serialize(buf, src: (const CUtlString *)this->m_pData);
  }
  else
  {
    CUtlString::CUtlString(this: (CUtlString *)&temp.m_Storage.m_Memory.m_nAllocationCount);
    CUtlString::Set(this: (CUtlString *)&temp.m_Storage.m_Memory.m_nAllocationCount, pValue: nullptr);
    v3 = Serialize(buf, src: (const CUtlString *)&temp.m_Storage.m_Memory.m_nAllocationCount);
    v4 = temp.m_Storage.m_nActualLength < 0;
    *bSuccess = v3;
    v6 = 0;
    if ( !v4 && temp.m_Storage.m_Memory.m_nAllocationCount != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)temp.m_Storage.m_Memory.m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052D920
// Name: private: void CDmxAttribute::DestructDataMemory<class CUtlBinaryBlock,class CUtlBinaryBlock>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::DestructDataMemory<CUtlBinaryBlock,CUtlBinaryBlock>(CDmxAttribute *this)
{
  int *m_pData; // esi
  bool v2; // sf

  m_pData = (int *)this->m_pData;
  v2 = m_pData[2] < 0;
  m_pData[3] = 0;
  if ( !v2 )
  {
    if ( *m_pData != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*m_pData);
      *m_pData = 0;
    }
    m_pData[1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052D960
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<int,class CUtlMemory<int,int>>,int>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<int,CUtlMemory<int,int>>,int>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<int,CUtlMemory<int,int> > *m_pData; // eax
  CUtlVector<int,CUtlMemory<int,int> > temp; // [esp+0h] [ebp-18h] BYREF
  int v5; // [esp+14h] [ebp-4h]

  m_pData = (const CUtlVector<int,CUtlMemory<int,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<int>(buf, src: m_pData);
  }
  else
  {
    memset(&temp.m_Memory.m_nAllocationCount, 0, 16);
    v5 = 0;
    *bSuccess = Serialize<int>(
                  buf,
                  src: (const CUtlVector<int,CUtlMemory<int,int> > *)&temp.m_Memory.m_nAllocationCount);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp.m_Memory.m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052D9C0
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<float,class CUtlMemory<float,int>>,float>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<float,CUtlMemory<float,int>>,float>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<float,CUtlMemory<float,int> > *m_pData; // eax
  CUtlVector<float,CUtlMemory<float,int> > temp; // [esp+0h] [ebp-18h] BYREF
  int v5; // [esp+14h] [ebp-4h]

  m_pData = (const CUtlVector<float,CUtlMemory<float,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<float>(buf, src: m_pData);
  }
  else
  {
    memset(&temp.m_Memory.m_nAllocationCount, 0, 16);
    v5 = 0;
    *bSuccess = Serialize<float>(
                  buf,
                  src: (const CUtlVector<float,CUtlMemory<float,int> > *)&temp.m_Memory.m_nAllocationCount);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp.m_Memory.m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052DA20
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<bool,class CUtlMemory<bool,int>>,bool>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<bool,CUtlMemory<bool,int> > *m_pData; // eax
  CUtlVector<bool,CUtlMemory<bool,int> > temp; // [esp+0h] [ebp-18h] BYREF
  int v5; // [esp+14h] [ebp-4h]

  m_pData = (const CUtlVector<bool,CUtlMemory<bool,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<bool>(buf, src: m_pData);
  }
  else
  {
    memset(&temp.m_Memory.m_nAllocationCount, 0, 16);
    v5 = 0;
    *bSuccess = Serialize<bool>(
                  buf,
                  src: (const CUtlVector<bool,CUtlMemory<bool,int> > *)&temp.m_Memory.m_nAllocationCount);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp.m_Memory.m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052DA80
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>,class DmeTime_t>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *m_pData; // eax
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > temp; // [esp+0h] [ebp-18h] BYREF
  int v5; // [esp+14h] [ebp-4h]

  m_pData = (const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<DmeTime_t>(buf, src: m_pData);
  }
  else
  {
    memset(&temp.m_Memory.m_nAllocationCount, 0, 16);
    v5 = 0;
    *bSuccess = Serialize<DmeTime_t>(
                  buf,
                  src: (const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)&temp.m_Memory.m_nAllocationCount);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp.m_Memory.m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052DAE0
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class Color,class CUtlMemory<class Color,int>>,class Color>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<Color,CUtlMemory<Color,int> > *m_pData; // eax
  CUtlVector<Color,CUtlMemory<Color,int> > temp; // [esp+0h] [ebp-18h] BYREF
  int v5; // [esp+14h] [ebp-4h]

  m_pData = (const CUtlVector<Color,CUtlMemory<Color,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<Color>(buf, src: m_pData);
  }
  else
  {
    memset(&temp.m_Memory.m_nAllocationCount, 0, 16);
    v5 = 0;
    *bSuccess = Serialize<Color>(
                  buf,
                  src: (const CUtlVector<Color,CUtlMemory<Color,int> > *)&temp.m_Memory.m_nAllocationCount);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp.m_Memory.m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052DB40
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>,class Vector2D>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *m_pData; // eax
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > temp; // [esp+0h] [ebp-18h] BYREF
  int v5; // [esp+14h] [ebp-4h]

  m_pData = (const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<Vector2D>(buf, src: m_pData);
  }
  else
  {
    memset(&temp.m_Memory.m_nAllocationCount, 0, 16);
    v5 = 0;
    *bSuccess = Serialize<Vector2D>(
                  buf,
                  src: (const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)&temp.m_Memory.m_nAllocationCount);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp.m_Memory.m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052DBA0
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>,class Quaternion>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *m_pData; // eax
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > temp; // [esp+0h] [ebp-18h] BYREF
  int v5; // [esp+14h] [ebp-4h]

  m_pData = (const CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<Quaternion>(buf, src: m_pData);
  }
  else
  {
    memset(&temp.m_Memory.m_nAllocationCount, 0, 16);
    v5 = 0;
    *bSuccess = Serialize<Quaternion>(
                  buf,
                  src: (const CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)&temp.m_Memory.m_nAllocationCount);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp.m_Memory.m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052DC00
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class Vector,class CUtlMemory<class Vector,int>>,class Vector>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<QAngle,CUtlMemory<QAngle,int> > *m_pData; // eax
  CUtlVector<QAngle,CUtlMemory<QAngle,int> > temp; // [esp+0h] [ebp-18h] BYREF
  int v5; // [esp+14h] [ebp-4h]

  m_pData = (const CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<Vector>(buf, src: m_pData);
  }
  else
  {
    memset(&temp.m_Memory.m_nAllocationCount, 0, 16);
    v5 = 0;
    *bSuccess = Serialize<Vector>(
                  buf,
                  src: (const CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&temp.m_Memory.m_nAllocationCount);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp.m_Memory.m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052DC60
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>,class VMatrix>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *m_pData; // eax
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > temp; // [esp+0h] [ebp-18h] BYREF
  int v5; // [esp+14h] [ebp-4h]

  m_pData = (const CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<VMatrix>(buf, src: m_pData);
  }
  else
  {
    memset(&temp.m_Memory.m_nAllocationCount, 0, 16);
    v5 = 0;
    *bSuccess = Serialize<VMatrix>(
                  buf,
                  src: (const CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)&temp.m_Memory.m_nAllocationCount);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp.m_Memory.m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052DCC0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<int,class CUtlMemory<int,int>>,int>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<int,CUtlMemory<int,int>>,int>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al

  v4 = Unserialize(buf, dest: (int *)&buf);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: (vgui::TreeNode **)&buf);
}

//------------------------------------------------------------------------------
// Address: 0x0052DD00
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<float,class CUtlMemory<float,int>>,float>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<float,CUtlMemory<float,int>>,float>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al

  v4 = Unserialize(buf, dest: (float *)&buf);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<float,CUtlMemory<float,int>>::InsertBefore(
      this: (CUtlVector<float,CUtlMemory<float,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: (float *)&buf);
}

//------------------------------------------------------------------------------
// Address: 0x0052DD40
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<bool,class CUtlMemory<bool,int>>,bool>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al

  v4 = Unserialize(buf, dest: (bool *)&buf);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<bool,CUtlMemory<bool,int>>::InsertBefore(
      this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: (unsigned __int8 *)&buf);
}

//------------------------------------------------------------------------------
// Address: 0x0052DD80
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,class CUtlString>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlString temp; // [esp+0h] [ebp-14h] BYREF
  int v6; // [esp+10h] [ebp-4h]

  CUtlString::CUtlString(this: (CUtlString *)&temp.m_Storage.m_Memory.m_nAllocationCount);
  v4 = Unserialize(buf, dest: (CUtlString *)&temp.m_Storage.m_Memory.m_nAllocationCount);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
      this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: (const CUtlString *)&temp.m_Storage.m_Memory.m_nAllocationCount);
  v6 = 0;
  if ( temp.m_Storage.m_nActualLength >= 0 && temp.m_Storage.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)temp.m_Storage.m_Memory.m_nAllocationCount);
}

//------------------------------------------------------------------------------
// Address: 0x0052DDF0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>,class CUtlBinaryBlock>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlBinaryBlock temp; // [esp+0h] [ebp-14h] BYREF
  int v6; // [esp+10h] [ebp-4h]

  CUtlBinaryBlock::CUtlBinaryBlock(this: (CUtlBinaryBlock *)&temp.m_Memory.m_nAllocationCount, growSize: 0, initSize: 0);
  v4 = Unserialize(buf, dest: (CUtlBinaryBlock *)&temp.m_Memory.m_nAllocationCount);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
      this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: (const CUtlBinaryBlock *)&temp.m_Memory.m_nAllocationCount);
  v6 = 0;
  if ( temp.m_nActualLength >= 0 && temp.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)temp.m_Memory.m_nAllocationCount);
}

//------------------------------------------------------------------------------
// Address: 0x0052DE60
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>,class DmeTime_t>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  DmeTime_t dest; // [esp+4h] [ebp-4h] BYREF

  dest.m_tms = 0x80000000;
  v4 = Unserialize(buf, &dest);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: (vgui::TreeNode **)&dest);
}

//------------------------------------------------------------------------------
// Address: 0x0052DEA0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Color,class CUtlMemory<class Color,int>>,class Color>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Color dest; // [esp+4h] [ebp-4h] BYREF

  dest = 0;
  v4 = Unserialize(buf, &dest);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: (vgui::TreeNode **)&dest);
}

//------------------------------------------------------------------------------
// Address: 0x0052DEE0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>,class Vector2D>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Vector2D temp; // [esp+0h] [ebp-Ch] BYREF

  v4 = Unserialize(buf, dest: (Vector2D *)&temp.y);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: (CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: (Vector2D *)&temp.y);
}

//------------------------------------------------------------------------------
// Address: 0x0052DF20
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector,class CUtlMemory<class Vector,int>>,class Vector>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  QAngle temp; // [esp+0h] [ebp-10h] BYREF

  v4 = Unserialize(buf, dest: (QAngle *)&temp.y);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: (const CVTFTexture::ResourceMemorySection *)&temp.y);
}

//------------------------------------------------------------------------------
// Address: 0x0052DF60
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>,class Vector4D>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>,Vector4D>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Vector4D temp; // [esp+0h] [ebp-14h] BYREF

  v4 = Unserialize(buf, dest: (Vector4D *)&temp.y);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::InsertBefore(
      this: (CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: (Vector4D *)&temp.y);
}

//------------------------------------------------------------------------------
// Address: 0x0052DFA0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>,class Quaternion>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Quaternion temp; // [esp+0h] [ebp-14h] BYREF

  v4 = Unserialize(buf, dest: (Quaternion *)&temp.y);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertBefore(
      this: (CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: (Quaternion *)&temp.y);
}

//------------------------------------------------------------------------------
// Address: 0x0052DFE0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>,class VMatrix>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  VMatrix temp; // [esp+0h] [ebp-44h] BYREF

  v4 = Unserialize(buf, dest: (VMatrix *)&temp.m[0][1]);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: (CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: (const vgui::MessageMapItem_t *)&temp.m[0][1]);
}

//------------------------------------------------------------------------------
// Address: 0x0052E140
// Name: private: CDmxAttribute::CDmxAttribute(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxAttribute *__thiscall CDmxAttribute::CDmxAttribute(CDmxAttribute *this, const char *pAttributeName)
{
  const char *v4; // [esp-4h] [ebp-8h]

  v4 = pAttributeName;
  this->m_Name.u.m_Id = -1;
  this->m_Name = (CUtlSymbolLarge)CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
                                    this: &CDmxAttribute::s_AttributeNameSymbols,
                                    result: (CUtlSymbolLarge *)&pAttributeName,
                                    pString: v4)->u.m_Id;
  this->m_Type = AT_UNKNOWN;
  this->m_pData = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0052E180
// Name: private: void CDmxAttribute::UnserializeType<class CUtlVector<int,class CUtlMemory<int,int>>,int>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeType<CUtlVector<int,CUtlMemory<int,int>>,int>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  *bSuccess = Unserialize<int>(buf, dest: (CUtlVector<int,CUtlMemory<int,int> > *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x0052E1A0
// Name: private: void CDmxAttribute::UnserializeType<class CUtlVector<float,class CUtlMemory<float,int>>,float>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeType<CUtlVector<float,CUtlMemory<float,int>>,float>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  *bSuccess = Unserialize<float>(buf, dest: (CUtlVector<float,CUtlMemory<float,int> > *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x0052E1C0
// Name: private: void CDmxAttribute::UnserializeType<class CUtlVector<bool,class CUtlMemory<bool,int>>,bool>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeType<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  *bSuccess = Unserialize<bool>(buf, dest: (CUtlVector<bool,CUtlMemory<bool,int> > *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x0052E1E0
// Name: private: void CDmxAttribute::UnserializeType<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,class CUtlString>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeType<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  *bSuccess = Unserialize<CUtlString>(buf, dest: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x0052E200
// Name: private: void CDmxAttribute::UnserializeType<class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>,class CUtlBinaryBlock>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeType<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  *bSuccess = Unserialize<CUtlBinaryBlock>(
                buf,
                dest: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x0052E220
// Name: private: void CDmxAttribute::UnserializeType<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>,class DmeTime_t>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeType<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  *bSuccess = Unserialize<DmeTime_t>(buf, dest: (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x0052E240
// Name: private: void CDmxAttribute::UnserializeType<class CUtlVector<class Color,class CUtlMemory<class Color,int>>,class Color>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeType<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  *bSuccess = Unserialize<Color>(buf, dest: (CUtlVector<Color,CUtlMemory<Color,int> > *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x0052E260
// Name: private: void CDmxAttribute::UnserializeType<class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>,class Vector2D>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeType<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  *bSuccess = Unserialize<Vector2D>(buf, dest: (CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x0052E280
// Name: private: void CDmxAttribute::UnserializeType<class CUtlVector<class Vector,class CUtlMemory<class Vector,int>>,class Vector>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeType<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  *bSuccess = Unserialize<QAngle>(buf, dest: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x0052E2A0
// Name: private: void CDmxAttribute::UnserializeType<class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>,class Vector4D>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeType<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>,Vector4D>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  *bSuccess = Unserialize<Vector4D>(buf, dest: (CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x0052E2C0
// Name: private: void CDmxAttribute::UnserializeType<class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>,class Quaternion>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeType<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  *bSuccess = Unserialize<Quaternion>(buf, dest: (CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x0052E2E0
// Name: private: void CDmxAttribute::UnserializeType<class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>,class VMatrix>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeType<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  *bSuccess = Unserialize<VMatrix>(buf, dest: (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)this->m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x0052E300
// Name: public: void CDmxAttribute::SetToDefaultValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetToDefaultValue(CDmxAttribute *this)
{
  _BYTE *m_pData; // ecx
  _DWORD *v2; // ecx
  _DWORD *v3; // ecx
  _DWORD *v4; // ecx
  _DWORD *v5; // ecx

  switch ( this->m_Type )
  {
    case AT_FIRST_VALUE_TYPE:
      *(_DWORD *)this->m_pData = 0;
      break;
    case AT_INT:
    case AT_TIME:
      *(_DWORD *)this->m_pData = 0;
      break;
    case AT_FLOAT:
      *(_DWORD *)this->m_pData = 0;
      break;
    case AT_BOOL:
      *(_BYTE *)this->m_pData = 0;
      break;
    case AT_STRING:
      CUtlString::Set(this: (CUtlString *)this->m_pData, pValue: nullptr);
      break;
    case AT_VOID:
      CUtlBinaryBlock::Set(this: (CUtlBinaryBlock *)this->m_pData, pValue: nullptr, nLen: 0);
      break;
    case AT_COLOR:
      m_pData = this->m_pData;
      *m_pData = 0;
      m_pData[1] = 0;
      m_pData[2] = 0;
      m_pData[3] = -1;
      break;
    case AT_VECTOR2:
      v2 = this->m_pData;
      *v2 = 0;
      v2[1] = 0;
      break;
    case AT_VECTOR3:
    case AT_QANGLE:
      v3 = this->m_pData;
      *v3 = 0;
      v3[1] = 0;
      v3[2] = 0;
      break;
    case AT_VECTOR4:
      v4 = this->m_pData;
      *v4 = 0;
      v4[1] = 0;
      v4[2] = 0;
      v4[3] = 0;
      break;
    case AT_QUATERNION:
      v5 = this->m_pData;
      *v5 = 0;
      v5[1] = 0;
      v5[2] = 0;
      v5[3] = 1065353216;
      break;
    case AT_VMATRIX:
      MatrixSetIdentity(dst: (VMatrix *)this->m_pData);
      break;
    case AT_FIRST_ARRAY_TYPE:
    case AT_INT_ARRAY:
    case AT_FLOAT_ARRAY:
    case AT_BOOL_ARRAY:
    case AT_TIME_ARRAY:
    case AT_COLOR_ARRAY:
    case AT_VECTOR2_ARRAY:
    case AT_VECTOR3_ARRAY:
    case AT_VECTOR4_ARRAY:
    case AT_QANGLE_ARRAY:
    case AT_QUATERNION_ARRAY:
    case AT_VMATRIX_ARRAY:
      *((_DWORD *)this->m_pData + 3) = 0;
      break;
    case AT_STRING_ARRAY:
    case AT_VOID_ARRAY:
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052E460
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,class CUtlString>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *m_pData; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > temp; // [esp+0h] [ebp-18h] BYREF
  int v5; // [esp+14h] [ebp-4h]

  m_pData = (const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<CUtlString>(buf, src: m_pData);
  }
  else
  {
    memset(&temp.m_Memory.m_nAllocationCount, 0, 16);
    v5 = 0;
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&temp.m_Memory.m_nAllocationCount);
    *bSuccess = Serialize<CUtlString>(
                  buf,
                  src: (const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)&temp.m_Memory.m_nAllocationCount);
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&temp.m_Memory.m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052E4D0
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>,class CUtlBinaryBlock>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *m_pData; // eax
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > temp; // [esp+0h] [ebp-18h] BYREF
  int v5; // [esp+14h] [ebp-4h]

  m_pData = (const CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<CUtlBinaryBlock>(buf, src: m_pData);
  }
  else
  {
    memset(&temp.m_Memory.m_nAllocationCount, 0, 16);
    v5 = 0;
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&temp.m_Memory.m_nAllocationCount);
    *bSuccess = Serialize<CUtlBinaryBlock>(
                  buf,
                  src: (const CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&temp.m_Memory.m_nAllocationCount);
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&temp.m_Memory.m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052E540
// Name: public: bool CDmxAttribute::Serialize(class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::Serialize(CDmxAttribute *this, CUtlBuffer *buf)
{
  __int32 v2; // eax
  bool result; // al
  bool v4; // [esp+5h] [ebp-1h] BYREF

  v4 = HIBYTE(this);
  v2 = this->m_Type - 2;
  v4 = false;
  switch ( v2 )
  {
    case 0:
      CDmxAttribute::SerializeType<int,int>(this, bSuccess: &v4, buf);
      result = v4;
      break;
    case 1:
      CDmxAttribute::SerializeType<float,float>(this, bSuccess: &v4, buf);
      result = v4;
      break;
    case 2:
      CDmxAttribute::SerializeType<bool,bool>(this, bSuccess: &v4, buf);
      result = v4;
      break;
    case 3:
      CDmxAttribute::SerializeType<CUtlString,CUtlString>(this, bSuccess: &v4, buf);
      result = v4;
      break;
    case 4:
      CDmxAttribute::SerializeType<CUtlBinaryBlock,CUtlBinaryBlock>(this, bSuccess: &v4, buf);
      result = v4;
      break;
    case 5:
      CDmxAttribute::SerializeType<DmeTime_t,DmeTime_t>(this, bSuccess: &v4, buf);
      result = v4;
      break;
    case 6:
      CDmxAttribute::SerializeType<Color,Color>(this, bSuccess: &v4, buf);
      result = v4;
      break;
    case 7:
      CDmxAttribute::SerializeType<Vector2D,Vector2D>(this, bSuccess: &v4, buf);
      result = v4;
      break;
    case 8:
    case 10:
      CDmxAttribute::SerializeType<Vector,Vector>(this, bSuccess: &v4, buf);
      result = v4;
      break;
    case 9:
      CDmxAttribute::SerializeType<Vector4D,Vector4D>(this, bSuccess: &v4, buf);
      result = v4;
      break;
    case 11:
      CDmxAttribute::SerializeType<Quaternion,Quaternion>(this, bSuccess: &v4, buf);
      result = v4;
      break;
    case 12:
      CDmxAttribute::SerializeType<VMatrix,VMatrix>(this, bSuccess: &v4, buf);
      result = v4;
      break;
    case 14:
      CDmxAttribute::SerializeType<CUtlVector<int,CUtlMemory<int,int>>,int>(this, bSuccess: &v4, buf);
      result = v4;
      break;
    case 15:
      CDmxAttribute::SerializeType<CUtlVector<float,CUtlMemory<float,int>>,float>(this, bSuccess: &v4, buf);
      result = v4;
      break;
    case 16:
      CDmxAttribute::SerializeType<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(this, bSuccess: &v4, buf);
      result = v4;
      break;
    case 17:
      CDmxAttribute::SerializeType<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        this,
        bSuccess: &v4,
        buf);
      result = v4;
      break;
    case 18:
      CDmxAttribute::SerializeType<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        this,
        bSuccess: &v4,
        buf);
      result = v4;
      break;
    case 19:
      CDmxAttribute::SerializeType<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(this, bSuccess: &v4, buf);
      result = v4;
      break;
    case 20:
      CDmxAttribute::SerializeType<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(this, bSuccess: &v4, buf);
      result = v4;
      break;
    case 21:
      CDmxAttribute::SerializeType<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(this, bSuccess: &v4, buf);
      result = v4;
      break;
    case 22:
    case 24:
      CDmxAttribute::SerializeType<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(this, bSuccess: &v4, buf);
      result = v4;
      break;
    case 23:
    case 25:
      CDmxAttribute::SerializeType<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        this,
        bSuccess: &v4,
        buf);
      result = v4;
      break;
    case 26:
      CDmxAttribute::SerializeType<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(this, bSuccess: &v4, buf);
      goto LABEL_25;
    default:
LABEL_25:
      result = v4;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052E820
// Name: public: char const __near * CDmxAttribute::GetValueAsString(char __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CDmxAttribute::GetValueAsString(CDmxAttribute *this, char *pBuffer, unsigned int nBufLen)
{
  CUtlBuffer buf; // [esp+4h] [ebp-34h] BYREF

  CUtlBuffer::CUtlBuffer(this: (CUtlBuffer *)&buf.m_Memory.m_nAllocationCount, pBuffer, nSize: nBufLen, nFlags: 1);
  CDmxAttribute::Serialize(this, buf: (CUtlBuffer *)&buf.m_Memory.m_nAllocationCount);
  if ( buf.m_Get >= 0 && buf.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)buf.m_Memory.m_nAllocationCount);
  return pBuffer;
}

//------------------------------------------------------------------------------
// Address: 0x0052E880
// Name: private: void CDmxAttribute::FreeDataMemory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::FreeDataMemory(CDmxAttribute *this)
{
  if ( this->m_Type != AT_UNKNOWN )
  {
    switch ( this->m_Type )
    {
      case AT_STRING:
      case AT_VOID:
        CDmxAttribute::DestructDataMemory<CUtlBinaryBlock,CUtlBinaryBlock>(this);
        this->m_Type = AT_UNKNOWN;
        break;
      case AT_FIRST_ARRAY_TYPE:
        CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this->m_pData);
        goto $LN130_2;
      case AT_INT_ARRAY:
      case AT_FLOAT_ARRAY:
      case AT_BOOL_ARRAY:
      case AT_TIME_ARRAY:
      case AT_COLOR_ARRAY:
      case AT_VECTOR2_ARRAY:
      case AT_VECTOR3_ARRAY:
      case AT_VECTOR4_ARRAY:
      case AT_QANGLE_ARRAY:
      case AT_QUATERNION_ARRAY:
      case AT_VMATRIX_ARRAY:
        CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this->m_pData);
        this->m_Type = AT_UNKNOWN;
        break;
      case AT_STRING_ARRAY:
      case AT_VOID_ARRAY:
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData);
        this->m_Type = AT_UNKNOWN;
        break;
      default:
$LN130_2:
        this->m_Type = AT_UNKNOWN;
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052EA10
// Name: private: CDmxAttribute::~CDmxAttribute(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDmxAttribute::~CDmxAttribute(CDmxAttribute *this)
{
  CDmxAttribute::FreeDataMemory(this);
}

//------------------------------------------------------------------------------
// Address: 0x0052EA20
// Name: private: void CDmxAttribute::AllocateDataMemory(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::AllocateDataMemory(CDmxAttribute *this, DmAttributeType_t type)
{
  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = type;
  this->m_pData = DMXAlloc(size: s_pAttributeSize[type]);
}

//------------------------------------------------------------------------------
// Address: 0x0052EA50
// Name: private: void CDmxAttribute::AllocateDataMemory_AndConstruct(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::AllocateDataMemory_AndConstruct(CDmxAttribute *this, DmAttributeType_t type)
{
  CUtlString *v3; // eax
  __int32 v4; // ecx

  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = type;
  v3 = (CUtlString *)DMXAlloc(size: s_pAttributeSize[type]);
  v4 = this->m_Type - 1;
  this->m_pData = v3;
  switch ( v4 )
  {
    case 4:
      if ( v3 != nullptr )
        CUtlString::CUtlString(this: v3);
      break;
    case 5:
      CDmxAttribute::ConstructDataMemory<CUtlBinaryBlock,CUtlBinaryBlock>(this);
      break;
    case 6:
      if ( v3 != nullptr )
        v3->m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)0x80000000;
      break;
    case 7:
      if ( v3 != nullptr )
        v3->m_Storage.m_Memory.m_pMemory = nullptr;
      break;
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
      CDmxAttribute::ConstructDataMemory<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(this);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052EBE0
// Name: public: bool CDmxAttribute::Unserialize(enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::Unserialize(CDmxAttribute *this, DmAttributeType_t type, CUtlBuffer *buf)
{
  __int32 v4; // eax
  bool result; // al

  CDmxAttribute::AllocateDataMemory_AndConstruct(this, type);
  v4 = this->m_Type - 2;
  LOBYTE(type) = 0;
  switch ( v4 )
  {
    case 0:
      CDmxAttribute::UnserializeType<int,int>(this, bSuccess: (bool *)&type, buf);
      result = type;
      break;
    case 1:
      CDmxAttribute::UnserializeType<float,float>(this, bSuccess: (bool *)&type, buf);
      result = type;
      break;
    case 2:
      CDmxAttribute::UnserializeType<bool,bool>(this, bSuccess: (bool *)&type, buf);
      result = type;
      break;
    case 3:
      CDmxAttribute::UnserializeType<CUtlString,CUtlString>(this, bSuccess: (bool *)&type, buf);
      result = type;
      break;
    case 4:
      CDmxAttribute::UnserializeType<CUtlBinaryBlock,CUtlBinaryBlock>(this, bSuccess: (bool *)&type, buf);
      result = type;
      break;
    case 5:
      CDmxAttribute::UnserializeType<DmeTime_t,DmeTime_t>(this, bSuccess: (bool *)&type, buf);
      result = type;
      break;
    case 6:
      CDmxAttribute::UnserializeType<Color,Color>(this, bSuccess: (bool *)&type, buf);
      result = type;
      break;
    case 7:
      CDmxAttribute::UnserializeType<Vector2D,Vector2D>(this, bSuccess: (bool *)&type, buf);
      result = type;
      break;
    case 8:
    case 10:
      CDmxAttribute::UnserializeType<Vector,Vector>(this, bSuccess: (bool *)&type, buf);
      result = type;
      break;
    case 9:
      CDmxAttribute::UnserializeType<Vector4D,Vector4D>(this, bSuccess: (bool *)&type, buf);
      result = type;
      break;
    case 11:
      CDmxAttribute::UnserializeType<Quaternion,Quaternion>(this, bSuccess: (bool *)&type, buf);
      result = type;
      break;
    case 12:
      CDmxAttribute::UnserializeType<VMatrix,VMatrix>(this, bSuccess: (bool *)&type, buf);
      result = type;
      break;
    case 14:
      CDmxAttribute::UnserializeType<CUtlVector<int,CUtlMemory<int,int>>,int>(this, bSuccess: (bool *)&type, buf);
      result = type;
      break;
    case 15:
      CDmxAttribute::UnserializeType<CUtlVector<float,CUtlMemory<float,int>>,float>(this, bSuccess: (bool *)&type, buf);
      result = type;
      break;
    case 16:
      CDmxAttribute::UnserializeType<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(this, bSuccess: (bool *)&type, buf);
      result = type;
      break;
    case 17:
      CDmxAttribute::UnserializeType<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        this,
        bSuccess: (bool *)&type,
        buf);
      result = type;
      break;
    case 18:
      CDmxAttribute::UnserializeType<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        this,
        bSuccess: (bool *)&type,
        buf);
      result = type;
      break;
    case 19:
      CDmxAttribute::UnserializeType<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        this,
        bSuccess: (bool *)&type,
        buf);
      result = type;
      break;
    case 20:
      CDmxAttribute::UnserializeType<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(this, bSuccess: (bool *)&type, buf);
      result = type;
      break;
    case 21:
      CDmxAttribute::UnserializeType<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        this,
        bSuccess: (bool *)&type,
        buf);
      result = type;
      break;
    case 22:
    case 24:
      CDmxAttribute::UnserializeType<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(
        this,
        bSuccess: (bool *)&type,
        buf);
      result = type;
      break;
    case 23:
      CDmxAttribute::UnserializeType<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>,Vector4D>(
        this,
        bSuccess: (bool *)&type,
        buf);
      result = type;
      break;
    case 25:
      CDmxAttribute::UnserializeType<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        this,
        bSuccess: (bool *)&type,
        buf);
      result = type;
      break;
    case 26:
      CDmxAttribute::UnserializeType<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        this,
        bSuccess: (bool *)&type,
        buf);
      goto LABEL_26;
    default:
LABEL_26:
      result = type;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052EF00
// Name: public: bool CDmxAttribute::UnserializeElement(enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::UnserializeElement(CDmxAttribute *this, DmAttributeType_t type, CUtlBuffer *buf)
{
  bool result; // al
  __int32 v5; // eax

  if ( (unsigned int)(type - 15) > 0xD )
    return false;
  if ( this->m_Type != type )
    CDmxAttribute::AllocateDataMemory_AndConstruct(this, type);
  v5 = this->m_Type - 16;
  LOBYTE(type) = 0;
  switch ( v5 )
  {
    case 0:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<int,CUtlMemory<int,int>>,int>(
        this,
        bSuccess: (bool *)&type,
        buf);
      result = type;
      break;
    case 1:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<float,CUtlMemory<float,int>>,float>(
        this,
        bSuccess: (bool *)&type,
        buf);
      result = type;
      break;
    case 2:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        this,
        bSuccess: (bool *)&type,
        buf);
      result = type;
      break;
    case 3:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        this,
        bSuccess: (bool *)&type,
        buf);
      result = type;
      break;
    case 4:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        this,
        bSuccess: (bool *)&type,
        buf);
      result = type;
      break;
    case 5:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        this,
        bSuccess: (bool *)&type,
        buf);
      result = type;
      break;
    case 6:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        this,
        bSuccess: (bool *)&type,
        buf);
      result = type;
      break;
    case 7:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        this,
        bSuccess: (bool *)&type,
        buf);
      result = type;
      break;
    case 8:
    case 10:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(
        this,
        bSuccess: (bool *)&type,
        buf);
      result = type;
      break;
    case 9:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>,Vector4D>(
        this,
        bSuccess: (bool *)&type,
        buf);
      result = type;
      break;
    case 11:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        this,
        bSuccess: (bool *)&type,
        buf);
      result = type;
      break;
    case 12:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        this,
        bSuccess: (bool *)&type,
        buf);
      goto LABEL_18;
    default:
LABEL_18:
      result = type;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052F0C0
// Name: public: void CDmxAttribute::SetValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetValue(CDmxAttribute *this, const char *pString)
{
  CUtlString *v3; // eax
  CUtlString *v4; // edi

  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = AT_STRING;
  v3 = (CUtlString *)DMXAlloc(size: s_pAttributeSize[5]);
  v4 = v3;
  this->m_pData = v3;
  if ( v3 != nullptr )
    CUtlString::CUtlString(this: v3);
  CUtlString::Set(this: v4, pValue: pString);
}

//------------------------------------------------------------------------------
// Address: 0x0052F100
// Name: public: void CDmxAttribute::SetValueFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetValueFromString(CDmxAttribute *this, const char *pValue)
{
  int v3; // eax
  CUtlBuffer buf; // [esp+0h] [ebp-34h] BYREF

  if ( this->m_Type != AT_UNKNOWN )
  {
    if ( this->m_Type == AT_STRING )
    {
      CDmxAttribute::SetValue(this, pString: pValue);
    }
    else if ( pValue != nullptr && (v3 = _V_strlen(str: pValue)) != 0 )
    {
      CUtlBuffer::CUtlBuffer(
        this: (CUtlBuffer *)&buf.m_Memory.m_nAllocationCount,
        pBuffer: pValue,
        nSize: v3,
        nFlags: 9);
      if ( !CDmxAttribute::Unserialize(this, type: this->m_Type, buf: (CUtlBuffer *)&buf.m_Memory.m_nAllocationCount) )
        CDmxAttribute::SetToDefaultValue(this);
      CUtlBuffer::~CUtlBuffer(this: (CUtlBuffer *)&buf.m_Memory.m_nAllocationCount);
    }
    else
    {
      CDmxAttribute::SetToDefaultValue(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052F180
// Name: private: void CDmxAttribute::GetArrayValue(enum DmAttributeType_t,void __near *,int,int,char const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::GetArrayValue(
        CDmxAttribute *this,
        DmAttributeType_t type,
        unsigned __int8 *pDest,
        int nDataTypeSize,
        int nDestArrayLength,
        const char *pDefaultString)
{
  int v7; // ebp
  unsigned int v8; // edi
  int ArrayCount; // ebx
  unsigned __int8 *ArrayBase; // eax
  unsigned __int8 *v11; // esi
  unsigned __int8 *v12; // ebp
  unsigned __int8 *v13; // esi
  int v14; // ebp
  unsigned __int8 *v15; // ebx
  int v16; // [esp+4h] [ebp-14h]
  CDmxAttribute temp; // [esp+8h] [ebp-10h] BYREF
  unsigned __int8 *v18; // [esp+14h] [ebp-4h]
  DmAttributeType_t typea; // [esp+1Ch] [ebp+4h]

  if ( (unsigned int)(type - 15) <= 0xD && this->m_Type == type )
  {
    v7 = *((_DWORD *)&vec4_invalid_95.w + type);
    v8 = nDataTypeSize;
    temp.m_Type = type - 14;
    v16 = v7;
    if ( nDataTypeSize >= v7 )
      v8 = *((_DWORD *)&vec4_invalid_95.w + type);
    ArrayCount = CDmxAttribute::GetArrayCount(this);
    ArrayBase = (unsigned __int8 *)CDmxAttribute::GetArrayBase(this);
    if ( ArrayCount != 0 && ArrayBase != nullptr )
    {
      if ( v7 == v8 )
      {
        memcpy(dst: pDest, src: ArrayBase, count: v8 * ArrayCount);
      }
      else
      {
        v11 = pDest;
        v12 = ArrayBase;
        if ( ArrayCount > 0 )
        {
          for ( typea = ArrayCount; typea != AT_UNKNOWN; --typea )
          {
            memcpy(dst: v11, src: v12, count: v8);
            v12 += v16;
            v11 += v8;
          }
        }
      }
    }
    if ( ArrayCount < nDestArrayLength && pDefaultString != nullptr )
    {
      CDmxAttribute::CDmxAttribute(this: (CDmxAttribute *)&temp.m_Name, pAttributeName: nullptr);
      CDmxAttribute::AllocateDataMemory_AndConstruct(this: (CDmxAttribute *)&temp.m_Name, type: temp.m_Type);
      CDmxAttribute::SetValueFromString(this: (CDmxAttribute *)&temp.m_Name, pValue: pDefaultString);
      v13 = &pDest[v8 * ArrayCount];
      v14 = nDestArrayLength - ArrayCount;
      v15 = v18;
      do
      {
        memcpy(dst: v13, src: v15, count: v8);
        v13 += v8;
        --v14;
      }
      while ( v14 != 0 );
      CDmxAttribute::FreeDataMemory(this: (CDmxAttribute *)&temp.m_Name);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00534D60
// Name: _dynamic_initializer_for__CDmxAttribute::s_AttributeNameSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxAttribute::s_AttributeNameSymbols__()
{
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>(
    this: &CDmxAttribute::s_AttributeNameSymbols.m_Lookup,
    nAllocationCount: 32);
  CDmxAttribute::s_AttributeNameSymbols.m_StringPools.m_Memory.m_pMemory = nullptr;
  CDmxAttribute::s_AttributeNameSymbols.m_StringPools.m_Memory.m_nAllocationCount = 0;
  CDmxAttribute::s_AttributeNameSymbols.m_StringPools.m_Memory.m_nGrowSize = 8;
  CDmxAttribute::s_AttributeNameSymbols.m_StringPools.m_Size = 0;
  CDmxAttribute::s_AttributeNameSymbols.m_StringPools.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x005358B0
// Name: _dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(this: &CDmxAttribute::s_AttributeNameSymbols);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&CDmxAttribute::s_AttributeNameSymbols.m_StringPools);
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &CDmxAttribute::s_AttributeNameSymbols.m_Lookup);
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmxAttribute::s_AttributeNameSymbols.m_Lookup.m_EntryMemory);
}

} // namespace vgui_perftest

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10408720
// Name: public: static enum DmAttributeType_t CDmxAttribute::ArrayAttributeBasicType(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
DmAttributeType_t __cdecl CDmxAttribute::ArrayAttributeBasicType(DmAttributeType_t type)
{
  DmAttributeType_t result; // eax

  result = type;
  if ( (unsigned int)(type - 15) <= 0xD )
    return type - 14;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408740
// Name: public: char const __near * CDmxAttribute::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxAttribute::GetName(CDmxAttribute *this)
{
  const char *result; // eax

  result = this->m_Name.u.m_pAsString;
  if ( result == (const char *)-1 )
    return prType;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408BF0
// Name: private: void CDmxAttribute::ConstructDataMemory<class CUtlVector<class Color,class CUtlMemory<class Color,int>>,class Color>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::ConstructDataMemory<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(CDmxAttribute *this)
{
  _DWORD *m_pData; // eax

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    *m_pData = 0;
    m_pData[1] = 0;
    m_pData[2] = 0;
    m_pData[3] = 0;
    m_pData[4] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10408C10
// Name: private: void CDmxAttribute::DestructDataMemory<class CUtlBinaryBlock,class CUtlBinaryBlock>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::DestructDataMemory<CUtlBinaryBlock,CUtlBinaryBlock>(CDmxAttribute *this)
{
  int *m_pData; // esi
  bool v2; // sf

  m_pData = (int *)this->m_pData;
  v2 = m_pData[2] < 0;
  m_pData[3] = 0;
  if ( !v2 )
  {
    if ( *m_pData != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*m_pData);
      *m_pData = 0;
    }
    m_pData[1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10408C50
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<int,class CUtlMemory<int,int>>,int>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<int,CUtlMemory<int,int>>,int>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  char v4; // al
  CUtlMemory<vgui::TreeNode *,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  v4 = Unserialize(buf, dest: (int *)&buf);
  *bSuccess = v4;
  if ( v4 != 0 )
  {
    m_pData = (CUtlMemory<vgui::TreeNode *,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(this: m_pData, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
        count: 4 * v9);
    v10 = &m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)buf;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10408CD0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<float,class CUtlMemory<float,int>>,float>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<float,CUtlMemory<float,int>>,float>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  char v4; // al
  CUtlMemory<vgui::TreeNode *,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  v4 = Unserialize(buf, dest: (float *)&buf);
  *bSuccess = v4;
  if ( v4 != 0 )
  {
    m_pData = (CUtlMemory<vgui::TreeNode *,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(this: m_pData, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
        count: 4 * v9);
    v10 = &m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)buf;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10408D50
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<bool,class CUtlMemory<bool,int>>,bool>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  char v4; // al
  CUtlMemory<unsigned char,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // edi
  unsigned __int8 *v8; // ecx
  signed int v9; // eax
  unsigned __int8 *v10; // esi

  v4 = Unserialize(buf, dest: (bool *)&buf + 3);
  *bSuccess = v4;
  if ( v4 != 0 )
  {
    m_pData = (CUtlMemory<unsigned char,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)(m_pMemory + 1) > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow(this: m_pData, num: (int)&m_pMemory[-m_nAllocationCount + 1]);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = m_pData[1].m_pMemory - m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[(_DWORD)m_pMemory + 1], src: &v8[(_DWORD)m_pMemory], count: v9);
    v10 = &m_pMemory[(unsigned int)m_pData->m_pMemory];
    if ( v10 != nullptr )
      *v10 = HIBYTE(buf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10408DC0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,class CUtlString>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlString temp; // [esp+4h] [ebp-10h] BYREF

  CUtlString::CUtlString(this: &temp);
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
      this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
  temp.m_Storage.m_nActualLength = 0;
  if ( temp.m_Storage.m_Memory.m_nGrowSize >= 0 && temp.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10408E30
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>,class CUtlBinaryBlock>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlBinaryBlock temp; // [esp+4h] [ebp-10h] BYREF

  CUtlBinaryBlock::CUtlBinaryBlock(this: &temp, growSize: 0, initSize: 0);
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
      this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
  temp.m_nActualLength = 0;
  if ( temp.m_Memory.m_nGrowSize >= 0 && temp.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10408EA0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>,class DmeTime_t>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  char v4; // al
  CUtlMemory<vgui::TreeNode *,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  DmeTime_t *v10; // eax
  DmeTime_t temp; // [esp+4h] [ebp-4h] BYREF

  temp.m_tms = 0x80000000;
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 != 0 )
  {
    m_pData = (CUtlMemory<vgui::TreeNode *,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(this: m_pData, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
        count: 4 * v9);
    v10 = (DmeTime_t *)&m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      v10->m_tms = temp.m_tms;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10408F30
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Color,class CUtlMemory<class Color,int>>,class Color>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlMemory<vgui::TreeNode *,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  Color *v10; // eax
  Color temp; // [esp+4h] [ebp-4h] BYREF

  temp = 0;
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
  {
    m_pData = (CUtlMemory<vgui::TreeNode *,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(this: m_pData, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
        count: 4 * v9);
    v10 = (Color *)&m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      *v10 = temp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10408FC0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>,class Vector2D>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Vector2D temp; // [esp+4h] [ebp-8h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: (CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x10409000
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector,class CUtlMemory<class Vector,int>>,class Vector>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  QAngle temp; // [esp+4h] [ebp-Ch] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x10409040
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>,class Vector4D>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>,Vector4D>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Vector4D temp; // [esp+4h] [ebp-10h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::InsertBefore(
      this: (CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x10409080
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>,class Quaternion>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Quaternion temp; // [esp+4h] [ebp-10h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>::InsertBefore(
      this: (CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x104090C0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>,class VMatrix>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  VMatrix temp; // [esp+4h] [ebp-40h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(
      this: (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x10409100
// Name: bool Unserialize<int>(class CUtlBuffer __near &,class CUtlVector<int,class CUtlMemory<int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Unserialize<int>(CUtlBuffer *buf, CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *dest)
{
  CUtlBuffer *v2; // ebx
  int Int; // eax
  int v5; // edi
  int v6; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *p_m_tms; // ecx
  int v10; // eax
  int v12; // edi
  int v13; // eax
  int *v14; // ecx
  int v15; // eax
  int nCount; // [esp+18h] [ebp+Ch]

  v2 = buf;
  dest->m_Size = 0;
  if ( (buf->m_Flags & 1) == 0 )
  {
    Int = CUtlBuffer::GetInt(this: buf);
    v5 = Int;
    nCount = Int;
    if ( Int != 0 )
    {
      CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(this: dest, num: Int);
      v6 = 0;
      if ( v5 > 0 )
      {
        do
        {
          m_Size = dest->m_Size;
          m_nAllocationCount = dest->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<CChoreoActor *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)dest,
              num: m_Size - m_nAllocationCount + 1);
          ++dest->m_Size;
          p_m_tms = &dest->m_Memory.m_pMemory->m_tms;
          v10 = dest->m_Size - m_Size - 1;
          dest->m_pElements = dest->m_Memory.m_pMemory;
          if ( v10 > 0 )
            _V_memmove(dest: &p_m_tms[m_Size + 1], src: &p_m_tms[m_Size], count: 4 * v10);
          if ( !Unserialize(buf, dest: &dest->m_Memory.m_pMemory[v6].m_tms) )
            return false;
        }
        while ( ++v6 < nCount );
      }
      v2 = buf;
    }
    return v2->m_Error == 0;
  }
  CUtlBuffer::EatWhiteSpace(this: buf);
  if ( buf->m_Error != 0 )
    return true;
  while ( 1 )
  {
    v12 = dest->m_Size;
    v13 = dest->m_Memory.m_nAllocationCount;
    if ( v12 + 1 > v13 )
      CUtlMemory<CChoreoActor *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)dest, num: v12 - v13 + 1);
    ++dest->m_Size;
    v14 = &dest->m_Memory.m_pMemory->m_tms;
    v15 = dest->m_Size - v12 - 1;
    dest->m_pElements = dest->m_Memory.m_pMemory;
    if ( v15 > 0 )
      _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 4 * v15);
    if ( !Unserialize(buf, dest: &dest->m_Memory.m_pMemory[v12].m_tms) )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    if ( buf->m_Error != 0 )
      return true;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10409240
// Name: bool Unserialize<float>(class CUtlBuffer __near &,class CUtlVector<float,class CUtlMemory<float,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Unserialize<float>(CUtlBuffer *buf, CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *dest)
{
  CUtlBuffer *v2; // ebx
  int Int; // eax
  int v5; // edi
  int v6; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  float *p_m_tms; // ecx
  int v10; // eax
  int v12; // edi
  int v13; // eax
  float *v14; // ecx
  int v15; // eax
  int nCount; // [esp+18h] [ebp+Ch]

  v2 = buf;
  dest->m_Size = 0;
  if ( (buf->m_Flags & 1) == 0 )
  {
    Int = CUtlBuffer::GetInt(this: buf);
    v5 = Int;
    nCount = Int;
    if ( Int != 0 )
    {
      CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(this: dest, num: Int);
      v6 = 0;
      if ( v5 > 0 )
      {
        do
        {
          m_Size = dest->m_Size;
          m_nAllocationCount = dest->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<CChoreoActor *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)dest,
              num: m_Size - m_nAllocationCount + 1);
          ++dest->m_Size;
          p_m_tms = (float *)&dest->m_Memory.m_pMemory->m_tms;
          v10 = dest->m_Size - m_Size - 1;
          dest->m_pElements = dest->m_Memory.m_pMemory;
          if ( v10 > 0 )
            _V_memmove(dest: &p_m_tms[m_Size + 1], src: &p_m_tms[m_Size], count: 4 * v10);
          if ( !Unserialize(buf, dest: (float *)&dest->m_Memory.m_pMemory[v6].m_tms) )
            return false;
        }
        while ( ++v6 < nCount );
      }
      v2 = buf;
    }
    return v2->m_Error == 0;
  }
  CUtlBuffer::EatWhiteSpace(this: buf);
  if ( buf->m_Error != 0 )
    return true;
  while ( 1 )
  {
    v12 = dest->m_Size;
    v13 = dest->m_Memory.m_nAllocationCount;
    if ( v12 + 1 > v13 )
      CUtlMemory<CChoreoActor *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)dest, num: v12 - v13 + 1);
    ++dest->m_Size;
    v14 = (float *)&dest->m_Memory.m_pMemory->m_tms;
    v15 = dest->m_Size - v12 - 1;
    dest->m_pElements = dest->m_Memory.m_pMemory;
    if ( v15 > 0 )
      _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 4 * v15);
    if ( !Unserialize(buf, dest: (float *)&dest->m_Memory.m_pMemory[v12].m_tms) )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    if ( buf->m_Error != 0 )
      return true;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10409380
// Name: bool Unserialize<bool>(class CUtlBuffer __near &,class CUtlVector<bool,class CUtlMemory<bool,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Unserialize<bool>(CUtlBuffer *buf, CUtlVector<bool,CUtlMemory<bool,int> > *dest)
{
  CUtlBuffer *v2; // ebx
  int Int; // eax
  int v5; // edi
  int v6; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  bool *m_pMemory; // ecx
  int v10; // eax
  int v12; // edi
  int v13; // eax
  bool *v14; // ecx
  int v15; // eax
  int nCount; // [esp+18h] [ebp+Ch]

  v2 = buf;
  dest->m_Size = 0;
  if ( (buf->m_Flags & 1) == 0 )
  {
    Int = CUtlBuffer::GetInt(this: buf);
    v5 = Int;
    nCount = Int;
    if ( Int != 0 )
    {
      CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCapacity(this: dest, num: Int);
      v6 = 0;
      if ( v5 > 0 )
      {
        do
        {
          m_Size = dest->m_Size;
          m_nAllocationCount = dest->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<bool,int>::Grow(
              this: (CUtlMemory<unsigned char,int> *)dest,
              num: m_Size - m_nAllocationCount + 1);
          ++dest->m_Size;
          m_pMemory = dest->m_Memory.m_pMemory;
          v10 = dest->m_Size - m_Size - 1;
          dest->m_pElements = dest->m_Memory.m_pMemory;
          if ( v10 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: v10);
          if ( !Unserialize(buf, dest: &dest->m_Memory.m_pMemory[v6]) )
            return false;
        }
        while ( ++v6 < nCount );
      }
      v2 = buf;
    }
    return v2->m_Error == 0;
  }
  CUtlBuffer::EatWhiteSpace(this: buf);
  if ( buf->m_Error != 0 )
    return true;
  while ( 1 )
  {
    v12 = dest->m_Size;
    v13 = dest->m_Memory.m_nAllocationCount;
    if ( v12 + 1 > v13 )
      CUtlMemory<bool,int>::Grow(this: (CUtlMemory<unsigned char,int> *)dest, num: v12 - v13 + 1);
    ++dest->m_Size;
    v14 = dest->m_Memory.m_pMemory;
    v15 = dest->m_Size - v12 - 1;
    dest->m_pElements = dest->m_Memory.m_pMemory;
    if ( v15 > 0 )
      _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: v15);
    if ( !Unserialize(buf, dest: &dest->m_Memory.m_pMemory[v12]) )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    if ( buf->m_Error != 0 )
      return true;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1040A080
// Name: private: CDmxAttribute::CDmxAttribute(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxAttribute *__thiscall CDmxAttribute::CDmxAttribute(CDmxAttribute *this, char *pAttributeName)
{
  char *v4; // [esp-4h] [ebp-8h]

  v4 = pAttributeName;
  this->m_Name.u.m_Id = -1;
  this->m_Name = (CUtlSymbolLarge)CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
                                    this: &CDmxAttribute::s_AttributeNameSymbols,
                                    result: (CUtlSymbolLarge *)&pAttributeName,
                                    pString: v4)->u.m_Id;
  this->m_Type = AT_UNKNOWN;
  this->m_pData = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1040A120
// Name: public: void CDmxAttribute::SetToDefaultValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetToDefaultValue(CDmxAttribute *this)
{
  _DWORD *m_pData; // ecx
  _DWORD *v2; // ecx
  _DWORD *v3; // ecx
  _DWORD *v4; // ecx

  switch ( this->m_Type )
  {
    case AT_FIRST_VALUE_TYPE:
      *(_DWORD *)this->m_pData = 0;
      break;
    case AT_INT:
    case AT_TIME:
      *(_DWORD *)this->m_pData = 0;
      break;
    case AT_FLOAT:
      *(_DWORD *)this->m_pData = 0;
      break;
    case AT_BOOL:
      *(_BYTE *)this->m_pData = 0;
      break;
    case AT_STRING:
      CUtlString::Set(this: (CUtlString *)this->m_pData, pValue: nullptr);
      break;
    case AT_VOID:
      CUtlBinaryBlock::Set(this: (CUtlBinaryBlock *)this->m_pData, pValue: nullptr, nLen: 0);
      break;
    case AT_COLOR:
      *(_DWORD *)this->m_pData = -16777216;
      break;
    case AT_VECTOR2:
      m_pData = this->m_pData;
      *m_pData = 0;
      m_pData[1] = 0;
      break;
    case AT_VECTOR3:
    case AT_QANGLE:
      v2 = this->m_pData;
      *v2 = 0;
      v2[1] = 0;
      v2[2] = 0;
      break;
    case AT_VECTOR4:
      v3 = this->m_pData;
      *v3 = 0;
      v3[1] = 0;
      v3[2] = 0;
      v3[3] = 0;
      break;
    case AT_QUATERNION:
      v4 = this->m_pData;
      *v4 = 0;
      v4[1] = 0;
      v4[2] = 0;
      v4[3] = 1065353216;
      break;
    case AT_VMATRIX:
      MatrixSetIdentity(dst: (VMatrix *)this->m_pData);
      break;
    case AT_FIRST_ARRAY_TYPE:
    case AT_INT_ARRAY:
    case AT_FLOAT_ARRAY:
    case AT_BOOL_ARRAY:
    case AT_TIME_ARRAY:
    case AT_COLOR_ARRAY:
    case AT_VECTOR2_ARRAY:
    case AT_VECTOR3_ARRAY:
    case AT_VECTOR4_ARRAY:
    case AT_QANGLE_ARRAY:
    case AT_QUATERNION_ARRAY:
    case AT_VMATRIX_ARRAY:
      *((_DWORD *)this->m_pData + 3) = 0;
      break;
    case AT_STRING_ARRAY:
    case AT_VOID_ARRAY:
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040A280
// Name: private: void CDmxAttribute::FreeDataMemory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::FreeDataMemory(CDmxAttribute *this)
{
  if ( this->m_Type != AT_UNKNOWN )
  {
    switch ( this->m_Type )
    {
      case AT_STRING:
      case AT_VOID:
        CDmxAttribute::DestructDataMemory<CUtlBinaryBlock,CUtlBinaryBlock>(this);
        this->m_Type = AT_UNKNOWN;
        break;
      case AT_FIRST_ARRAY_TYPE:
        CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this->m_pData);
        goto $LN130_2;
      case AT_INT_ARRAY:
      case AT_FLOAT_ARRAY:
      case AT_BOOL_ARRAY:
      case AT_TIME_ARRAY:
      case AT_COLOR_ARRAY:
      case AT_VECTOR2_ARRAY:
      case AT_VECTOR3_ARRAY:
      case AT_VECTOR4_ARRAY:
      case AT_QANGLE_ARRAY:
      case AT_QUATERNION_ARRAY:
      case AT_VMATRIX_ARRAY:
        CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this->m_pData);
        this->m_Type = AT_UNKNOWN;
        break;
      case AT_STRING_ARRAY:
      case AT_VOID_ARRAY:
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData);
        this->m_Type = AT_UNKNOWN;
        break;
      default:
$LN130_2:
        this->m_Type = AT_UNKNOWN;
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040A400
// Name: private: CDmxAttribute::~CDmxAttribute(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDmxAttribute::~CDmxAttribute(CDmxAttribute *this)
{
  CDmxAttribute::FreeDataMemory(this);
}

//------------------------------------------------------------------------------
// Address: 0x1040A410
// Name: private: void CDmxAttribute::AllocateDataMemory(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::AllocateDataMemory(CDmxAttribute *this, DmAttributeType_t type)
{
  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = type;
  this->m_pData = DMXAlloc(size: s_pAttributeSize[type]);
}

//------------------------------------------------------------------------------
// Address: 0x1040A440
// Name: private: void CDmxAttribute::AllocateDataMemory_AndConstruct(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::AllocateDataMemory_AndConstruct(CDmxAttribute *this, DmAttributeType_t type)
{
  CUtlString *v3; // ecx
  __int32 v4; // eax

  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = type;
  v3 = (CUtlString *)DMXAlloc(size: s_pAttributeSize[type]);
  v4 = this->m_Type - 1;
  this->m_pData = v3;
  switch ( v4 )
  {
    case 4:
      if ( v3 != nullptr )
        CUtlString::CUtlString(this: v3);
      break;
    case 5:
      if ( v3 != nullptr )
        CUtlBinaryBlock::CUtlBinaryBlock(this: &v3->m_Storage, growSize: 0, initSize: 0);
      break;
    case 6:
      if ( v3 != nullptr )
        v3->m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)0x80000000;
      break;
    case 7:
      if ( v3 != nullptr )
        v3->m_Storage.m_Memory.m_pMemory = nullptr;
      break;
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
      CDmxAttribute::ConstructDataMemory<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(this);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040A5E0
// Name: public: bool CDmxAttribute::Unserialize(enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::Unserialize(CDmxAttribute *this, DmAttributeType_t type, CUtlBuffer *buf)
{
  bool result; // al

  CDmxAttribute::AllocateDataMemory_AndConstruct(this, type);
  result = false;
  switch ( this->m_Type )
  {
    case AT_INT:
      result = Unserialize(buf, dest: (int *)this->m_pData);
      break;
    case AT_FLOAT:
      result = Unserialize(buf, dest: (float *)this->m_pData);
      break;
    case AT_BOOL:
      result = Unserialize(buf, dest: (bool *)this->m_pData);
      break;
    case AT_STRING:
      result = Unserialize(buf, dest: (CUtlString *)this->m_pData);
      break;
    case AT_VOID:
      result = Unserialize(buf, dest: (CUtlBinaryBlock *)this->m_pData);
      break;
    case AT_TIME:
      result = Unserialize(buf, dest: (DmeTime_t *)this->m_pData);
      break;
    case AT_COLOR:
      result = Unserialize(buf, dest: (Color *)this->m_pData);
      break;
    case AT_VECTOR2:
      result = Unserialize(buf, dest: (Vector2D *)this->m_pData);
      break;
    case AT_VECTOR3:
    case AT_QANGLE:
      result = Unserialize(buf, dest: (QAngle *)this->m_pData);
      break;
    case AT_VECTOR4:
      result = Unserialize(buf, dest: (Vector4D *)this->m_pData);
      break;
    case AT_QUATERNION:
      result = Unserialize(buf, dest: (Quaternion *)this->m_pData);
      break;
    case AT_VMATRIX:
      result = Unserialize(buf, dest: (VMatrix *)this->m_pData);
      break;
    case AT_INT_ARRAY:
      result = Unserialize<int>(buf, dest: (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)this->m_pData);
      break;
    case AT_FLOAT_ARRAY:
      result = Unserialize<float>(buf, dest: (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)this->m_pData);
      break;
    case AT_BOOL_ARRAY:
      result = Unserialize<bool>(buf, dest: (CUtlVector<bool,CUtlMemory<bool,int> > *)this->m_pData);
      break;
    case AT_STRING_ARRAY:
      result = Unserialize<CUtlString>(buf, dest: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData);
      break;
    case AT_VOID_ARRAY:
      result = Unserialize<CUtlBinaryBlock>(
                 buf,
                 dest: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData);
      break;
    case AT_TIME_ARRAY:
      result = Unserialize<DmeTime_t>(buf, dest: (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)this->m_pData);
      break;
    case AT_COLOR_ARRAY:
      result = Unserialize<Color>(buf, dest: (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)this->m_pData);
      break;
    case AT_VECTOR2_ARRAY:
      result = Unserialize<Vector2D>(buf, dest: (CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)this->m_pData);
      break;
    case AT_VECTOR3_ARRAY:
    case AT_QANGLE_ARRAY:
      result = Unserialize<QAngle>(
                 buf,
                 dest: (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this->m_pData);
      break;
    case AT_VECTOR4_ARRAY:
      result = Unserialize<Vector4D>(
                 buf,
                 dest: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this->m_pData);
      break;
    case AT_QUATERNION_ARRAY:
      result = Unserialize<Quaternion>(
                 buf,
                 dest: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this->m_pData);
      break;
    case AT_VMATRIX_ARRAY:
      result = Unserialize<VMatrix>(buf, dest: (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)this->m_pData);
      break;
    default:
      return result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040A8A0
// Name: public: bool CDmxAttribute::UnserializeElement(enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::UnserializeElement(CDmxAttribute *this, DmAttributeType_t type, CUtlBuffer *buf)
{
  bool result; // al
  __int32 v5; // eax

  if ( (unsigned int)(type - 15) > 0xD )
    return false;
  if ( this->m_Type != type )
    CDmxAttribute::AllocateDataMemory_AndConstruct(this, type);
  v5 = this->m_Type - 16;
  HIBYTE(type) = 0;
  switch ( v5 )
  {
    case 0:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<int,CUtlMemory<int,int>>,int>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 1:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<float,CUtlMemory<float,int>>,float>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 2:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 3:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 4:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 5:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 6:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 7:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 8:
    case 10:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 9:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>,Vector4D>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 11:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 12:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      goto LABEL_18;
    default:
LABEL_18:
      result = HIBYTE(type);
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040AA40
// Name: public: void CDmxAttribute::SetValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetValue(CDmxAttribute *this, const char *pString)
{
  CUtlString *v3; // eax
  CUtlString *v4; // edi

  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = AT_STRING;
  v3 = (CUtlString *)DMXAlloc(size: s_pAttributeSize[5]);
  v4 = v3;
  this->m_pData = v3;
  if ( v3 != nullptr )
    CUtlString::CUtlString(this: v3);
  CUtlString::Set(this: v4, pValue: pString);
}

//------------------------------------------------------------------------------
// Address: 0x1040AA90
// Name: public: void CDmxAttribute::SetValueFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetValueFromString(CDmxAttribute *this, char *pValue)
{
  unsigned int v3; // eax
  CUtlString *v4; // eax
  CUtlString *v5; // edi
  CUtlBuffer buf; // [esp+4h] [ebp-30h] BYREF

  if ( this->m_Type != AT_UNKNOWN )
  {
    if ( this->m_Type == AT_STRING )
    {
      CDmxAttribute::FreeDataMemory(this);
      this->m_Type = AT_STRING;
      v4 = (CUtlString *)DMXAlloc(size: s_pAttributeSize[5]);
      v5 = v4;
      this->m_pData = v4;
      if ( v4 != nullptr )
        CUtlString::CUtlString(this: v4);
      CUtlString::Set(this: v5, pValue);
    }
    else if ( pValue != nullptr && (v3 = _V_strlen(str: pValue)) != 0 )
    {
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: (unsigned __int8 *)pValue, nSize: v3, nFlags: 9u);
      if ( !CDmxAttribute::Unserialize(this, type: this->m_Type, &buf) )
        CDmxAttribute::SetToDefaultValue(this);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
    else
    {
      CDmxAttribute::SetToDefaultValue(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040AB60
// Name: private: void CDmxAttribute::GetArrayValue(enum DmAttributeType_t,void __near *,int,int,char const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::GetArrayValue(
        CDmxAttribute *this,
        DmAttributeType_t type,
        unsigned __int8 *pDest,
        int nDataTypeSize,
        int nDestArrayLength,
        char *pDefaultString)
{
  DmAttributeType_t m_Type; // esi
  int v7; // ebx
  int v8; // edi
  _DWORD *m_pData; // eax
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // esi
  unsigned __int8 *v12; // ebx
  unsigned __int8 *v13; // esi
  int v14; // ebx
  unsigned __int8 *v15; // edi
  CDmxAttribute temp; // [esp+0h] [ebp-14h] BYREF
  DmAttributeType_t v17; // [esp+Ch] [ebp-8h]
  int nSrcStride; // [esp+10h] [ebp-4h]
  DmAttributeType_t typea; // [esp+1Ch] [ebp+8h]

  if ( (unsigned int)(type - 15) <= 0xD )
  {
    m_Type = this->m_Type;
    if ( this->m_Type == type )
    {
      v7 = s_pAttributeSize[type - 14];
      v17 = type - 14;
      nSrcStride = v7;
      if ( nDataTypeSize >= v7 )
        nDataTypeSize = v7;
      v8 = 0;
      if ( (unsigned int)(m_Type - 15) <= 0xD )
      {
        m_pData = this->m_pData;
        if ( m_pData != nullptr )
          v8 = m_pData[3];
      }
      v10 = nullptr;
      switch ( m_Type )
      {
        case AT_FIRST_ARRAY_TYPE:
        case AT_FLOAT_ARRAY:
        case AT_VOID_ARRAY:
        case AT_VECTOR2_ARRAY:
        case AT_QANGLE_ARRAY:
          v10 = *(unsigned __int8 **)this->m_pData;
          break;
        case AT_INT_ARRAY:
        case AT_STRING_ARRAY:
        case AT_COLOR_ARRAY:
        case AT_VECTOR4_ARRAY:
        case AT_VMATRIX_ARRAY:
          v10 = *(unsigned __int8 **)this->m_pData;
          break;
        case AT_BOOL_ARRAY:
        case AT_TIME_ARRAY:
        case AT_VECTOR3_ARRAY:
        case AT_QUATERNION_ARRAY:
          v10 = *(unsigned __int8 **)this->m_pData;
          break;
        default:
          break;
      }
      if ( v8 != 0 && v10 != nullptr )
      {
        if ( v7 == nDataTypeSize )
        {
          memcpy(dst: pDest, src: v10, count: nDataTypeSize * v8);
        }
        else
        {
          v11 = pDest;
          v12 = v10;
          if ( v8 > 0 )
          {
            for ( typea = v8; typea != AT_UNKNOWN; --typea )
            {
              memcpy(dst: v11, src: v12, count: nDataTypeSize);
              v11 += nDataTypeSize;
              v12 += nSrcStride;
            }
          }
        }
      }
      if ( v8 < nDestArrayLength && pDefaultString != nullptr )
      {
        temp.m_Name.u.m_Id = -1;
        temp.m_Type = AT_UNKNOWN;
        temp.m_pData = nullptr;
        CDmxAttribute::AllocateDataMemory_AndConstruct(this: &temp, type: v17);
        CDmxAttribute::SetValueFromString(this: &temp, pValue: pDefaultString);
        v13 = &pDest[nDataTypeSize * v8];
        v14 = nDestArrayLength - v8;
        v15 = (unsigned __int8 *)temp.m_pData;
        do
        {
          memcpy(dst: v13, src: v15, count: nDataTypeSize);
          v13 += nDataTypeSize;
          --v14;
        }
        while ( v14 != 0 );
        CDmxAttribute::FreeDataMemory(this: &temp);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042F580
// Name: _dynamic_initializer_for__CDmxAttribute::s_AttributeNameSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxAttribute::s_AttributeNameSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(this: &CDmxAttribute::s_AttributeNameSymbols);
  return atexit(func: dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x104374B0
// Name: _dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(this: &CDmxAttribute::s_AttributeNameSymbols);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CDmxAttribute::s_AttributeNameSymbols.m_StringPools);
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &CDmxAttribute::s_AttributeNameSymbols.m_Lookup);
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmxAttribute::s_AttributeNameSymbols.m_Lookup.m_EntryMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1040AD10
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class CSOAContainer_Serializable>(class CSOAContainer_Serializable __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<CSOAContainer_Serializable>()
{
  if ( (_S1_15 & 1) == 0 )
  {
    _S1_15 |= 1u;
    dword_105F4AA8 = 2;
    dword_105F4AAC = 0;
    dword_105F4AB0 = 4;
    dword_105F4AB4 = -1;
    dword_105F4AB8 = 0;
    dword_105F4ABC = 0;
    dword_105F4AC0 = 0;
    dword_105F4AC4 = 0;
    dword_105F4AC8 = 0;
    dword_105F4ACC = (int)"num_rows";
    dword_105F4AD0 = (int)"0";
    dword_105F4AD4 = 2;
    dword_105F4AD8 = 4;
    dword_105F4ADC = 4;
    dword_105F4AE0 = -1;
    dword_105F4AE4 = 0;
    dword_105F4AE8 = 0;
    dword_105F4AEC = 0;
    dword_105F4AF0 = 0;
    dword_105F4AF4 = 0;
    dword_105F4AF8 = (int)"num_slices";
    dword_105F4AFC = (int)"0";
    dword_105F4B00 = 2;
    dword_105F4B04 = 8;
    dword_105F4B08 = 4;
    dword_105F4B0C = -1;
    dword_105F4B10 = 0;
    dword_105F4B14 = 0;
    dword_105F4B18 = 0;
    dword_105F4B1C = 0;
    dword_105F4B20 = 0;
    dword_105F4B24 = (int)"attribute_types";
    dword_105F4B28 = (int)"-1";
    dword_105F4B2C = 16;
    dword_105F4B30 = 152;
    dword_105F4B34 = 4;
    dword_105F4B38 = -1;
    dword_105F4B3C = 0;
    dword_105F4B40 = 0;
    dword_105F4B44 = 0;
    dword_105F4B48 = 0;
    dword_105F4B4C = 32;
    dword_105F4B50 = (int)"field_present_mask";
    dword_105F4B54 = (int)"0";
    dword_105F4B58 = 2;
    dword_105F4B5C = 664;
    dword_105F4B60 = 4;
    dword_105F4B64 = -1;
    dword_105F4B68 = 0;
    dword_105F4B6C = 0;
    dword_105F4B70 = 0;
    dword_105F4B74 = 0;
    dword_105F4B78 = 0;
    dword_105F4B7C = (int)"thread_mode";
    dword_105F4B80 = (int)"-1";
    dword_105F4B84 = 2;
    dword_105F4B88 = 800;
    dword_105F4B8C = 4;
    dword_105F4B90 = -1;
    dword_105F4B94 = 0;
    dword_105F4B98 = 0;
    dword_105F4B9C = 0;
    dword_105F4BA0 = 0;
    dword_105F4BA4 = 0;
    dword_105F4BA8 = 0;
    dword_105F4BAC = 0;
    dword_105F4BB0 = 0;
    dword_105F4BB4 = 0;
    dword_105F4BB8 = 0;
    dword_105F4BBC = -1;
    dword_105F4BC0 = 0;
    dword_105F4BC4 = 0;
    dword_105F4BC8 = 0;
    dword_105F4BCC = 0;
    dword_105F4BD0 = 0;
  }
  return unpack_175;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10378630
// Name: public: void CUtlMemory<bool,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<bool,int>::Grow(CUtlMemory<unsigned char,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned __int8 *m_pMemory; // edx

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
        m_nAllocationCount = 32;
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
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: m_nAllocationCount);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F5910
// Name: public: static enum DmAttributeType_t CDmxAttribute::ArrayAttributeBasicType(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
DmAttributeType_t __cdecl CDmxAttribute::ArrayAttributeBasicType(DmAttributeType_t type)
{
  DmAttributeType_t result; // eax

  result = type;
  if ( (unsigned int)(type - 15) <= 0xD )
    return type - 14;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F5930
// Name: public: char const __near * CDmxAttribute::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmxAttribute::GetName(CDmxAttribute *this)
{
  const char *result; // eax

  result = this->m_Name.u.m_pAsString;
  if ( result == (const char *)-1 )
    return locale;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F5E70
// Name: private: void CDmxAttribute::ConstructDataMemory<class CUtlVector<class Color,class CUtlMemory<class Color,int>>,class Color>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::ConstructDataMemory<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(CDmxAttribute *this)
{
  _DWORD *m_pData; // eax

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    *m_pData = 0;
    m_pData[1] = 0;
    m_pData[2] = 0;
    m_pData[3] = 0;
    m_pData[4] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F5F00
// Name: private: void CDmxAttribute::DestructDataMemory<class CUtlBinaryBlock,class CUtlBinaryBlock>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::DestructDataMemory<CUtlBinaryBlock,CUtlBinaryBlock>(CDmxAttribute *this)
{
  int *m_pData; // esi
  bool v2; // sf

  m_pData = (int *)this->m_pData;
  v2 = m_pData[2] < 0;
  m_pData[3] = 0;
  if ( !v2 )
  {
    if ( *m_pData != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*m_pData);
      *m_pData = 0;
    }
    m_pData[1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F5F40
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<int,class CUtlMemory<int,int>>,int>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<int,CUtlMemory<int,int>>,int>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlMemory<vgui::TreeNode *,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  v4 = Unserialize(buf, dest: (int *)&buf);
  *bSuccess = v4;
  if ( v4 )
  {
    m_pData = (CUtlMemory<vgui::TreeNode *,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(this: m_pData, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
        count: 4 * v9);
    v10 = &m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)buf;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F5FC0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<float,class CUtlMemory<float,int>>,float>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<float,CUtlMemory<float,int>>,float>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlMemory<vgui::TreeNode *,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  v4 = Unserialize(buf, dest: (float *)&buf);
  *bSuccess = v4;
  if ( v4 )
  {
    m_pData = (CUtlMemory<vgui::TreeNode *,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(this: m_pData, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
        count: 4 * v9);
    v10 = &m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)buf;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F6040
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<bool,class CUtlMemory<bool,int>>,bool>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlMemory<unsigned char,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // edi
  unsigned __int8 *v8; // ecx
  signed int v9; // eax
  unsigned __int8 *v10; // esi

  v4 = Unserialize(buf, dest: (bool *)&buf + 3);
  *bSuccess = v4;
  if ( v4 )
  {
    m_pData = (CUtlMemory<unsigned char,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)(m_pMemory + 1) > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow(this: m_pData, num: (int)&m_pMemory[-m_nAllocationCount + 1]);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = m_pData[1].m_pMemory - m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[(_DWORD)m_pMemory + 1], src: &v8[(_DWORD)m_pMemory], count: v9);
    v10 = &m_pMemory[(unsigned int)m_pData->m_pMemory];
    if ( v10 != nullptr )
      *v10 = HIBYTE(buf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F60B0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,class CUtlString>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlString temp; // [esp+4h] [ebp-10h] BYREF

  CUtlString::CUtlString(this: &temp);
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
      this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
  temp.m_Storage.m_nActualLength = 0;
  if ( temp.m_Storage.m_Memory.m_nGrowSize >= 0 && temp.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x103F6120
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>,class CUtlBinaryBlock>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlBinaryBlock temp; // [esp+4h] [ebp-10h] BYREF

  CUtlBinaryBlock::CUtlBinaryBlock(this: &temp, growSize: 0, initSize: 0);
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
      this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
  temp.m_nActualLength = 0;
  if ( temp.m_Memory.m_nGrowSize >= 0 && temp.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x103F6190
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>,class DmeTime_t>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlMemory<vgui::TreeNode *,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  DmeTime_t *v10; // eax
  DmeTime_t temp; // [esp+4h] [ebp-4h] BYREF

  temp.m_tms = 0x80000000;
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
  {
    m_pData = (CUtlMemory<vgui::TreeNode *,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(this: m_pData, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
        count: 4 * v9);
    v10 = (DmeTime_t *)&m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      v10->m_tms = temp.m_tms;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F6220
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Color,class CUtlMemory<class Color,int>>,class Color>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlMemory<vgui::TreeNode *,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  Color *v10; // eax
  Color temp; // [esp+4h] [ebp-4h] BYREF

  temp = 0;
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
  {
    m_pData = (CUtlMemory<vgui::TreeNode *,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(this: m_pData, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
        count: 4 * v9);
    v10 = (Color *)&m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      *v10 = temp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F62B0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>,class Vector2D>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Vector2D temp; // [esp+4h] [ebp-8h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: (CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x103F62F0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector,class CUtlMemory<class Vector,int>>,class Vector>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  QAngle temp; // [esp+4h] [ebp-Ch] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x103F6330
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>,class Vector4D>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>,Vector4D>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Vector4D temp; // [esp+4h] [ebp-10h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::InsertBefore(
      this: (CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x103F6370
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>,class Quaternion>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Quaternion temp; // [esp+4h] [ebp-10h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>::InsertBefore(
      this: (CUtlVector<ResponseRules::CResponseSystem::ScriptEntry,CUtlMemory<ResponseRules::CResponseSystem::ScriptEntry,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: (const ResponseRules::CResponseSystem::ScriptEntry *)&temp);
}

//------------------------------------------------------------------------------
// Address: 0x103F63B0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>,class VMatrix>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  VMatrix temp; // [esp+4h] [ebp-40h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: (CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: (const vgui::MessageMapItem_t *)&temp);
}

//------------------------------------------------------------------------------
// Address: 0x103F63F0
// Name: bool Unserialize<int>(class CUtlBuffer __near &,class CUtlVector<int,class CUtlMemory<int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Unserialize<int>(CUtlBuffer *buf, CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *dest)
{
  CUtlBuffer *v2; // ebx
  unsigned int Int; // eax
  int v5; // edi
  int v6; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *p_m_tms; // ecx
  int v10; // eax
  int v12; // edi
  int v13; // eax
  int *v14; // ecx
  int v15; // eax
  int nCount; // [esp+18h] [ebp+Ch]

  v2 = buf;
  dest->m_Size = 0;
  if ( (buf->m_Flags & 1) == 0 )
  {
    Int = CUtlBuffer::GetInt(this: buf);
    v5 = Int;
    nCount = Int;
    if ( Int != 0 )
    {
      CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(this: dest, num: Int);
      v6 = 0;
      if ( v5 > 0 )
      {
        do
        {
          m_Size = dest->m_Size;
          m_nAllocationCount = dest->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<CNavLadder *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)dest,
              num: m_Size - m_nAllocationCount + 1);
          ++dest->m_Size;
          p_m_tms = &dest->m_Memory.m_pMemory->m_tms;
          v10 = dest->m_Size - m_Size - 1;
          dest->m_pElements = dest->m_Memory.m_pMemory;
          if ( v10 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&p_m_tms[m_Size + 1],
              src: (unsigned __int8 *)&p_m_tms[m_Size],
              count: 4 * v10);
          if ( !Unserialize(buf, dest: &dest->m_Memory.m_pMemory[v6].m_tms) )
            return false;
        }
        while ( ++v6 < nCount );
      }
      v2 = buf;
    }
    return v2->m_Error == 0;
  }
  CUtlBuffer::EatWhiteSpace(this: buf);
  if ( buf->m_Error != 0 )
    return true;
  while ( 1 )
  {
    v12 = dest->m_Size;
    v13 = dest->m_Memory.m_nAllocationCount;
    if ( v12 + 1 > v13 )
      CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)dest, num: v12 - v13 + 1);
    ++dest->m_Size;
    v14 = &dest->m_Memory.m_pMemory->m_tms;
    v15 = dest->m_Size - v12 - 1;
    dest->m_pElements = dest->m_Memory.m_pMemory;
    if ( v15 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v14[v12 + 1], src: (unsigned __int8 *)&v14[v12], count: 4 * v15);
    if ( !Unserialize(buf, dest: &dest->m_Memory.m_pMemory[v12].m_tms) )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    if ( buf->m_Error != 0 )
      return true;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x103F6530
// Name: bool Unserialize<float>(class CUtlBuffer __near &,class CUtlVector<float,class CUtlMemory<float,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Unserialize<float>(CUtlBuffer *buf, CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *dest)
{
  CUtlBuffer *v2; // ebx
  unsigned int Int; // eax
  int v5; // edi
  int v6; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  float *p_m_tms; // ecx
  int v10; // eax
  int v12; // edi
  int v13; // eax
  float *v14; // ecx
  int v15; // eax
  int nCount; // [esp+18h] [ebp+Ch]

  v2 = buf;
  dest->m_Size = 0;
  if ( (buf->m_Flags & 1) == 0 )
  {
    Int = CUtlBuffer::GetInt(this: buf);
    v5 = Int;
    nCount = Int;
    if ( Int != 0 )
    {
      CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(this: dest, num: Int);
      v6 = 0;
      if ( v5 > 0 )
      {
        do
        {
          m_Size = dest->m_Size;
          m_nAllocationCount = dest->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<CNavLadder *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)dest,
              num: m_Size - m_nAllocationCount + 1);
          ++dest->m_Size;
          p_m_tms = (float *)&dest->m_Memory.m_pMemory->m_tms;
          v10 = dest->m_Size - m_Size - 1;
          dest->m_pElements = dest->m_Memory.m_pMemory;
          if ( v10 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&p_m_tms[m_Size + 1],
              src: (unsigned __int8 *)&p_m_tms[m_Size],
              count: 4 * v10);
          if ( !Unserialize(buf, dest: (float *)&dest->m_Memory.m_pMemory[v6].m_tms) )
            return false;
        }
        while ( ++v6 < nCount );
      }
      v2 = buf;
    }
    return v2->m_Error == 0;
  }
  CUtlBuffer::EatWhiteSpace(this: buf);
  if ( buf->m_Error != 0 )
    return true;
  while ( 1 )
  {
    v12 = dest->m_Size;
    v13 = dest->m_Memory.m_nAllocationCount;
    if ( v12 + 1 > v13 )
      CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)dest, num: v12 - v13 + 1);
    ++dest->m_Size;
    v14 = (float *)&dest->m_Memory.m_pMemory->m_tms;
    v15 = dest->m_Size - v12 - 1;
    dest->m_pElements = dest->m_Memory.m_pMemory;
    if ( v15 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v14[v12 + 1], src: (unsigned __int8 *)&v14[v12], count: 4 * v15);
    if ( !Unserialize(buf, dest: (float *)&dest->m_Memory.m_pMemory[v12].m_tms) )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    if ( buf->m_Error != 0 )
      return true;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x103F6670
// Name: bool Unserialize<bool>(class CUtlBuffer __near &,class CUtlVector<bool,class CUtlMemory<bool,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Unserialize<bool>(CUtlBuffer *buf, CUtlVector<bool,CUtlMemory<bool,int> > *dest)
{
  CUtlBuffer *v2; // ebx
  unsigned int Int; // eax
  int v5; // edi
  int v6; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  bool *m_pMemory; // ecx
  signed int v10; // eax
  int v12; // edi
  int v13; // eax
  bool *v14; // ecx
  signed int v15; // eax
  int nCount; // [esp+18h] [ebp+Ch]

  v2 = buf;
  dest->m_Size = 0;
  if ( (buf->m_Flags & 1) == 0 )
  {
    Int = CUtlBuffer::GetInt(this: buf);
    v5 = Int;
    nCount = Int;
    if ( Int != 0 )
    {
      CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCapacity(this: dest, num: Int);
      v6 = 0;
      if ( v5 > 0 )
      {
        do
        {
          m_Size = dest->m_Size;
          m_nAllocationCount = dest->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<bool,int>::Grow(
              this: (CUtlMemory<unsigned char,int> *)dest,
              num: m_Size - m_nAllocationCount + 1);
          ++dest->m_Size;
          m_pMemory = dest->m_Memory.m_pMemory;
          v10 = dest->m_Size - m_Size - 1;
          dest->m_pElements = dest->m_Memory.m_pMemory;
          if ( v10 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
              src: (unsigned __int8 *)&m_pMemory[m_Size],
              count: v10);
          if ( !Unserialize(buf, dest: &dest->m_Memory.m_pMemory[v6]) )
            return false;
        }
        while ( ++v6 < nCount );
      }
      v2 = buf;
    }
    return v2->m_Error == 0;
  }
  CUtlBuffer::EatWhiteSpace(this: buf);
  if ( buf->m_Error != 0 )
    return true;
  while ( 1 )
  {
    v12 = dest->m_Size;
    v13 = dest->m_Memory.m_nAllocationCount;
    if ( v12 + 1 > v13 )
      CUtlMemory<bool,int>::Grow(this: (CUtlMemory<unsigned char,int> *)dest, num: v12 - v13 + 1);
    ++dest->m_Size;
    v14 = dest->m_Memory.m_pMemory;
    v15 = dest->m_Size - v12 - 1;
    dest->m_pElements = dest->m_Memory.m_pMemory;
    if ( v15 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v14[v12 + 1], src: (unsigned __int8 *)&v14[v12], count: v15);
    if ( !Unserialize(buf, dest: &dest->m_Memory.m_pMemory[v12]) )
      break;
    CUtlBuffer::EatWhiteSpace(this: buf);
    if ( buf->m_Error != 0 )
      return true;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x103F7370
// Name: private: CDmxAttribute::CDmxAttribute(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmxAttribute *__thiscall CDmxAttribute::CDmxAttribute(CDmxAttribute *this, const char *pAttributeName)
{
  const char *v4; // [esp-4h] [ebp-8h]

  v4 = pAttributeName;
  this->m_Name.u.m_Id = -1;
  this->m_Name = (CUtlSymbolLarge)CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::AddString(
                                    this: &CDmxAttribute::s_AttributeNameSymbols,
                                    result: (CUtlSymbolLarge *)&pAttributeName,
                                    pString: v4)->u.m_Id;
  this->m_Type = AT_UNKNOWN;
  this->m_pData = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103F73B0
// Name: public: void CDmxAttribute::SetToDefaultValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetToDefaultValue(CDmxAttribute *this)
{
  _DWORD *m_pData; // ecx
  _DWORD *v2; // ecx
  _DWORD *v3; // ecx
  _DWORD *v4; // ecx

  switch ( this->m_Type )
  {
    case AT_FIRST_VALUE_TYPE:
      *(_DWORD *)this->m_pData = 0;
      break;
    case AT_INT:
    case AT_TIME:
      *(_DWORD *)this->m_pData = 0;
      break;
    case AT_FLOAT:
      *(_DWORD *)this->m_pData = 0;
      break;
    case AT_BOOL:
      *(_BYTE *)this->m_pData = 0;
      break;
    case AT_STRING:
      CUtlString::Set(this: (CUtlString *)this->m_pData, pValue: nullptr);
      break;
    case AT_VOID:
      CUtlBinaryBlock::Set(this: (CUtlBinaryBlock *)this->m_pData, pValue: nullptr, nLen: 0);
      break;
    case AT_COLOR:
      *(_DWORD *)this->m_pData = -16777216;
      break;
    case AT_VECTOR2:
      m_pData = this->m_pData;
      *m_pData = 0;
      m_pData[1] = 0;
      break;
    case AT_VECTOR3:
    case AT_QANGLE:
      v2 = this->m_pData;
      *v2 = 0;
      v2[1] = 0;
      v2[2] = 0;
      break;
    case AT_VECTOR4:
      v3 = this->m_pData;
      *v3 = 0;
      v3[1] = 0;
      v3[2] = 0;
      v3[3] = 0;
      break;
    case AT_QUATERNION:
      v4 = this->m_pData;
      *v4 = 0;
      v4[1] = 0;
      v4[2] = 0;
      v4[3] = 1065353216;
      break;
    case AT_VMATRIX:
      MatrixSetIdentity(dst: (VMatrix *)this->m_pData);
      break;
    case AT_FIRST_ARRAY_TYPE:
    case AT_INT_ARRAY:
    case AT_FLOAT_ARRAY:
    case AT_BOOL_ARRAY:
    case AT_TIME_ARRAY:
    case AT_COLOR_ARRAY:
    case AT_VECTOR2_ARRAY:
    case AT_VECTOR3_ARRAY:
    case AT_VECTOR4_ARRAY:
    case AT_QANGLE_ARRAY:
    case AT_QUATERNION_ARRAY:
    case AT_VMATRIX_ARRAY:
      *((_DWORD *)this->m_pData + 3) = 0;
      break;
    case AT_STRING_ARRAY:
    case AT_VOID_ARRAY:
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F7510
// Name: private: void CDmxAttribute::FreeDataMemory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::FreeDataMemory(CDmxAttribute *this)
{
  if ( this->m_Type != AT_UNKNOWN )
  {
    switch ( this->m_Type )
    {
      case AT_STRING:
      case AT_VOID:
        CDmxAttribute::DestructDataMemory<CUtlBinaryBlock,CUtlBinaryBlock>(this);
        this->m_Type = AT_UNKNOWN;
        break;
      case AT_FIRST_ARRAY_TYPE:
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this->m_pData);
        goto $LN130_5;
      case AT_INT_ARRAY:
      case AT_FLOAT_ARRAY:
      case AT_BOOL_ARRAY:
      case AT_TIME_ARRAY:
      case AT_COLOR_ARRAY:
      case AT_VECTOR2_ARRAY:
      case AT_VECTOR3_ARRAY:
      case AT_VECTOR4_ARRAY:
      case AT_QANGLE_ARRAY:
      case AT_QUATERNION_ARRAY:
      case AT_VMATRIX_ARRAY:
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this->m_pData);
        this->m_Type = AT_UNKNOWN;
        break;
      case AT_STRING_ARRAY:
      case AT_VOID_ARRAY:
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData);
        this->m_Type = AT_UNKNOWN;
        break;
      default:
$LN130_5:
        this->m_Type = AT_UNKNOWN;
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F7690
// Name: private: CDmxAttribute::~CDmxAttribute(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDmxAttribute::~CDmxAttribute(CDmxAttribute *this)
{
  CDmxAttribute::FreeDataMemory(this);
}

//------------------------------------------------------------------------------
// Address: 0x103F76A0
// Name: private: void CDmxAttribute::AllocateDataMemory(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::AllocateDataMemory(CDmxAttribute *this, DmAttributeType_t type)
{
  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = type;
  this->m_pData = DMXAlloc(size: s_pAttributeSize[type]);
}

//------------------------------------------------------------------------------
// Address: 0x103F76D0
// Name: private: void CDmxAttribute::AllocateDataMemory_AndConstruct(enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::AllocateDataMemory_AndConstruct(CDmxAttribute *this, DmAttributeType_t type)
{
  CUtlString *v3; // ecx
  __int32 v4; // eax

  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = type;
  v3 = (CUtlString *)DMXAlloc(size: s_pAttributeSize[type]);
  v4 = this->m_Type - 1;
  this->m_pData = v3;
  switch ( v4 )
  {
    case 4:
      if ( v3 != nullptr )
        CUtlString::CUtlString(this: v3);
      break;
    case 5:
      if ( v3 != nullptr )
        CUtlBinaryBlock::CUtlBinaryBlock(this: &v3->m_Storage, growSize: 0, initSize: 0);
      break;
    case 6:
      if ( v3 != nullptr )
        v3->m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)0x80000000;
      break;
    case 7:
      if ( v3 != nullptr )
        v3->m_Storage.m_Memory.m_pMemory = nullptr;
      break;
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
      CDmxAttribute::ConstructDataMemory<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(this);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F7870
// Name: public: bool CDmxAttribute::Unserialize(enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::Unserialize(CDmxAttribute *this, DmAttributeType_t type, CUtlBuffer *buf)
{
  bool result; // al

  CDmxAttribute::AllocateDataMemory_AndConstruct(this, type);
  result = false;
  switch ( this->m_Type )
  {
    case AT_INT:
      result = Unserialize(buf, dest: (int *)this->m_pData);
      break;
    case AT_FLOAT:
      result = Unserialize(buf, dest: (float *)this->m_pData);
      break;
    case AT_BOOL:
      result = Unserialize(buf, dest: (bool *)this->m_pData);
      break;
    case AT_STRING:
      result = Unserialize(buf, dest: (CUtlString *)this->m_pData);
      break;
    case AT_VOID:
      result = Unserialize(buf, dest: (CUtlBinaryBlock *)this->m_pData);
      break;
    case AT_TIME:
      result = Unserialize(buf, dest: (DmeTime_t *)this->m_pData);
      break;
    case AT_COLOR:
      result = Unserialize(buf, dest: (Color *)this->m_pData);
      break;
    case AT_VECTOR2:
      result = Unserialize(buf, dest: (Vector2D *)this->m_pData);
      break;
    case AT_VECTOR3:
    case AT_QANGLE:
      result = Unserialize(buf, dest: (QAngle *)this->m_pData);
      break;
    case AT_VECTOR4:
      result = Unserialize(buf, dest: (Vector4D *)this->m_pData);
      break;
    case AT_QUATERNION:
      result = Unserialize(buf, dest: (Quaternion *)this->m_pData);
      break;
    case AT_VMATRIX:
      result = Unserialize(buf, dest: (VMatrix *)this->m_pData);
      break;
    case AT_INT_ARRAY:
      result = Unserialize<int>(buf, dest: (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)this->m_pData);
      break;
    case AT_FLOAT_ARRAY:
      result = Unserialize<float>(buf, dest: (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)this->m_pData);
      break;
    case AT_BOOL_ARRAY:
      result = Unserialize<bool>(buf, dest: (CUtlVector<bool,CUtlMemory<bool,int> > *)this->m_pData);
      break;
    case AT_STRING_ARRAY:
      result = Unserialize<CUtlString>(buf, dest: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData);
      break;
    case AT_VOID_ARRAY:
      result = Unserialize<CUtlBinaryBlock>(
                 buf,
                 dest: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData);
      break;
    case AT_TIME_ARRAY:
      result = Unserialize<DmeTime_t>(buf, dest: (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)this->m_pData);
      break;
    case AT_COLOR_ARRAY:
      result = Unserialize<Color>(buf, dest: (CUtlVector<Color,CUtlMemory<Color,int> > *)this->m_pData);
      break;
    case AT_VECTOR2_ARRAY:
      result = Unserialize<Vector2D>(buf, dest: (CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)this->m_pData);
      break;
    case AT_VECTOR3_ARRAY:
    case AT_QANGLE_ARRAY:
      result = Unserialize<QAngle>(buf, dest: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)this->m_pData);
      break;
    case AT_VECTOR4_ARRAY:
      result = Unserialize<Vector4D>(buf, dest: (CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *)this->m_pData);
      break;
    case AT_QUATERNION_ARRAY:
      result = Unserialize<Quaternion>(buf, dest: (CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)this->m_pData);
      break;
    case AT_VMATRIX_ARRAY:
      result = Unserialize<VMatrix>(buf, dest: (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)this->m_pData);
      break;
    default:
      return result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F7B30
// Name: public: bool CDmxAttribute::UnserializeElement(enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxAttribute::UnserializeElement(CDmxAttribute *this, DmAttributeType_t type, CUtlBuffer *buf)
{
  bool result; // al
  __int32 v5; // eax

  if ( (unsigned int)(type - 15) > 0xD )
    return false;
  if ( this->m_Type != type )
    CDmxAttribute::AllocateDataMemory_AndConstruct(this, type);
  v5 = this->m_Type - 16;
  HIBYTE(type) = 0;
  switch ( v5 )
  {
    case 0:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<int,CUtlMemory<int,int>>,int>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 1:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<float,CUtlMemory<float,int>>,float>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 2:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 3:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 4:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 5:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 6:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 7:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 8:
    case 10:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 9:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>,Vector4D>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 11:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      result = HIBYTE(type);
      break;
    case 12:
      CDmxAttribute::UnserializeTypedElement<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        this,
        bSuccess: (bool *)&type + 3,
        buf);
      goto LABEL_18;
    default:
LABEL_18:
      result = HIBYTE(type);
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F7CD0
// Name: public: void CDmxAttribute::SetValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetValue(CDmxAttribute *this, const char *pString)
{
  CUtlString *v3; // eax
  CUtlString *v4; // edi

  CDmxAttribute::FreeDataMemory(this);
  this->m_Type = AT_STRING;
  v3 = (CUtlString *)DMXAlloc(size: s_pAttributeSize[5]);
  v4 = v3;
  this->m_pData = v3;
  if ( v3 != nullptr )
    CUtlString::CUtlString(this: v3);
  CUtlString::Set(this: v4, pValue: pString);
}

//------------------------------------------------------------------------------
// Address: 0x103F7D20
// Name: public: void CDmxAttribute::SetValueFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SetValueFromString(CDmxAttribute *this, char *pValue)
{
  unsigned int v3; // eax
  CUtlString *v4; // eax
  CUtlString *v5; // edi
  CUtlBuffer buf; // [esp+4h] [ebp-30h] BYREF

  if ( this->m_Type != AT_UNKNOWN )
  {
    if ( this->m_Type == AT_STRING )
    {
      CDmxAttribute::FreeDataMemory(this);
      this->m_Type = AT_STRING;
      v4 = (CUtlString *)DMXAlloc(size: s_pAttributeSize[5]);
      v5 = v4;
      this->m_pData = v4;
      if ( v4 != nullptr )
        CUtlString::CUtlString(this: v4);
      CUtlString::Set(this: v5, pValue);
    }
    else if ( pValue != nullptr && (v3 = _V_strlen(str: pValue)) != 0 )
    {
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: (unsigned __int8 *)pValue, nSize: v3, nFlags: 9u);
      if ( !CDmxAttribute::Unserialize(this, type: this->m_Type, &buf) )
        CDmxAttribute::SetToDefaultValue(this);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
    else
    {
      CDmxAttribute::SetToDefaultValue(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F7DF0
// Name: private: void CDmxAttribute::GetArrayValue(enum DmAttributeType_t,void __near *,int,int,char const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::GetArrayValue(
        CDmxAttribute *this,
        DmAttributeType_t type,
        unsigned __int8 *pDest,
        int nDataTypeSize,
        int nDestArrayLength,
        char *pDefaultString)
{
  DmAttributeType_t m_Type; // esi
  int v7; // ebx
  int v8; // edi
  _DWORD *m_pData; // eax
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // esi
  unsigned __int8 *v12; // ebx
  unsigned __int8 *v13; // esi
  int v14; // ebx
  unsigned __int8 *v15; // edi
  CDmxAttribute temp; // [esp+0h] [ebp-14h] BYREF
  DmAttributeType_t v17; // [esp+Ch] [ebp-8h]
  int nSrcStride; // [esp+10h] [ebp-4h]
  DmAttributeType_t typea; // [esp+1Ch] [ebp+8h]

  if ( (unsigned int)(type - 15) <= 0xD )
  {
    m_Type = this->m_Type;
    if ( this->m_Type == type )
    {
      v7 = s_pAttributeSize[type - 14];
      v17 = type - 14;
      nSrcStride = v7;
      if ( nDataTypeSize >= v7 )
        nDataTypeSize = v7;
      v8 = 0;
      if ( (unsigned int)(m_Type - 15) <= 0xD )
      {
        m_pData = this->m_pData;
        if ( m_pData != nullptr )
          v8 = m_pData[3];
      }
      v10 = nullptr;
      switch ( m_Type )
      {
        case AT_FIRST_ARRAY_TYPE:
        case AT_FLOAT_ARRAY:
        case AT_VOID_ARRAY:
        case AT_VECTOR2_ARRAY:
        case AT_QANGLE_ARRAY:
          v10 = *(unsigned __int8 **)this->m_pData;
          break;
        case AT_INT_ARRAY:
        case AT_STRING_ARRAY:
        case AT_COLOR_ARRAY:
        case AT_VECTOR4_ARRAY:
        case AT_VMATRIX_ARRAY:
          v10 = *(unsigned __int8 **)this->m_pData;
          break;
        case AT_BOOL_ARRAY:
        case AT_TIME_ARRAY:
        case AT_VECTOR3_ARRAY:
        case AT_QUATERNION_ARRAY:
          v10 = *(unsigned __int8 **)this->m_pData;
          break;
        default:
          break;
      }
      if ( v8 != 0 && v10 != nullptr )
      {
        if ( v7 == nDataTypeSize )
        {
          memcpy(dst: pDest, src: v10, count: nDataTypeSize * v8);
        }
        else
        {
          v11 = pDest;
          v12 = v10;
          if ( v8 > 0 )
          {
            for ( typea = v8; typea != AT_UNKNOWN; --typea )
            {
              memcpy(dst: v11, src: v12, count: nDataTypeSize);
              v11 += nDataTypeSize;
              v12 += nSrcStride;
            }
          }
        }
      }
      if ( v8 < nDestArrayLength && pDefaultString != nullptr )
      {
        temp.m_Name.u.m_Id = -1;
        temp.m_Type = AT_UNKNOWN;
        temp.m_pData = nullptr;
        CDmxAttribute::AllocateDataMemory_AndConstruct(this: &temp, type: v17);
        CDmxAttribute::SetValueFromString(this: &temp, pValue: pDefaultString);
        v13 = &pDest[nDataTypeSize * v8];
        v14 = nDestArrayLength - v8;
        v15 = (unsigned __int8 *)temp.m_pData;
        do
        {
          memcpy(dst: v13, src: v15, count: nDataTypeSize);
          v13 += nDataTypeSize;
          --v14;
        }
        while ( v14 != 0 );
        CDmxAttribute::FreeDataMemory(this: &temp);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104186B0
// Name: _dynamic_initializer_for__CDmxAttribute::s_AttributeNameSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxAttribute::s_AttributeNameSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(this: &CDmxAttribute::s_AttributeNameSymbols);
  return atexit(func: dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x10422FF0
// Name: _dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(this: &CDmxAttribute::s_AttributeNameSymbols);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CDmxAttribute::s_AttributeNameSymbols.m_StringPools);
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &CDmxAttribute::s_AttributeNameSymbols.m_Lookup);
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmxAttribute::s_AttributeNameSymbols.m_Lookup.m_EntryMemory);
}

} // namespace server
