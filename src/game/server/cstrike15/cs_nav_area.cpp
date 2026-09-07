// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/cs_nav_area.cpp
// Functions: 14
// ============================================================

#include "game\server\cstrike15\cs_nav_area.h"

//------------------------------------------------------------------------------
// Address: 0x102DE990
// Name: public: virtual float CNavArea::GetDangerDecayRate(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNavArea::GetDangerDecayRate(CNavArea *this)
{
  return 0.0083333338;
}

//------------------------------------------------------------------------------
// Address: 0x102DE9A0
// Name: public: virtual void CCSNavArea::OnServerActivate(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CCSNavArea::OnServerActivate(CCSNavArea *this)
{
  CNavArea::OnServerActivate(this);
}

//------------------------------------------------------------------------------
// Address: 0x102DE9B0
// Name: public: virtual enum NavErrorType CCSNavArea::PostLoad(void)
// Source: json
//------------------------------------------------------------------------------
NavErrorType __thiscall CCSNavArea::PostLoad(CCSNavArea *this)
{
  NavErrorType result; // eax
  int v3; // ebx
  unsigned int *p_id; // esi
  CNavArea *NavAreaByID; // eax
  unsigned int v6; // ecx
  CNavArea *v7; // eax
  unsigned int v8; // edx
  NavErrorType error; // [esp+8h] [ebp-4h]

  result = CNavArea::PostLoad(this);
  v3 = 0;
  error = result;
  if ( this->m_approachCount != 0 )
  {
    p_id = &this->m_approach[0].prev.id;
    do
    {
      NavAreaByID = CNavMesh::GetNavAreaByID(this: TheNavMesh, id: *(p_id - 2));
      v6 = *p_id;
      *(p_id - 2) = (unsigned int)NavAreaByID;
      v7 = CNavMesh::GetNavAreaByID(this: TheNavMesh, id: v6);
      v8 = p_id[3];
      *p_id = (unsigned int)v7;
      p_id[3] = (unsigned int)CNavMesh::GetNavAreaByID(this: TheNavMesh, id: v8);
      ++v3;
      p_id += 8;
    }
    while ( v3 < this->m_approachCount );
    return error;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102DEA20
// Name: public: virtual void CCSNavArea::Draw(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CCSNavArea::Draw(CCSNavArea *this)
{
  CNavArea::Draw(this);
}

//------------------------------------------------------------------------------
// Address: 0x102DEA30
// Name: public: virtual void CCSNavArea::CustomAnalysis(bool)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CCSNavArea::CustomAnalysis(CCSNavArea *this, bool isIncremental)
{
  CCSNavArea::ComputeApproachAreas(this);
}

//------------------------------------------------------------------------------
// Address: 0x102DEA40
// Name: public: CCSNavArea::CCSNavArea(void)
// Source: json
//------------------------------------------------------------------------------
CCSNavArea *__thiscall CCSNavArea::CCSNavArea(CCSNavArea *this)
{
  CCSNavArea::ApproachInfo *m_approach; // ecx
  int v3; // edx
  float *p_length; // eax

  CNavArea::CNavArea(this);
  m_approach = this->m_approach;
  this->__vftable = (CCSNavArea_vtbl *)&CCSNavArea::`vftable';
  v3 = 15;
  p_length = &this->m_approach[0].next.length;
  do
  {
    m_approach->here.id = 0;
    *(p_length - 5) = -1.0;
    *(p_length - 4) = 0.0;
    *(p_length - 3) = -1.0;
    *(p_length - 1) = 0.0;
    *p_length = -1.0;
    ++m_approach;
    p_length += 8;
    --v3;
  }
  while ( v3 >= 0 );
  this->m_approachCount = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102DEAD0
// Name: protected: bool CUtlBuffer::GetTypeText<unsigned short>(unsigned short __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<unsigned short>(CUtlBuffer *this, unsigned __int16 *value, unsigned int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtoul(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102DEB40
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned short>(unsigned short __near *,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned short>(
        CByteswap *this,
        unsigned __int8 *outputBuffer,
        __int16 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int8 *v5; // esi
  int v6; // edi
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl

  v4 = count;
  if ( count > 0 && outputBuffer != nullptr )
  {
    v5 = (unsigned __int8 *)inputBuffer;
    if ( inputBuffer == nullptr )
      v5 = outputBuffer;
    if ( (*(_BYTE *)this & 1) != 0 )
    {
      v6 = outputBuffer - v5;
      do
      {
        v7 = v5[1];
        count = *(unsigned __int16 *)&v5[v6];
        v8 = *v5;
        LOBYTE(count) = v7;
        BYTE1(count) = v8;
        _V_memcpy(dest: &v5[v6], src: &count, count: 2);
        v5 += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
    else if ( v5 != nullptr && outputBuffer != v5 )
    {
      memcpy(dst: outputBuffer, src: v5, count: 2 * count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DEE30
// Name: public: unsigned short CUtlBuffer::GetUnsignedShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetUnsignedShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned __int8 *)&s,
          inputBuffer: (__int16 *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtoul(nptr: endptr, &endptr, ibase: 0xAu);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102DEED0
// Name: public: unsigned char CUtlBuffer::GetUnsignedChar(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlBuffer::GetUnsignedChar(CUtlBuffer *this)
{
  unsigned __int8 result; // al

  if ( (this->m_Flags & 1) != 0 )
    return CUtlBuffer::GetUnsignedShort(this);
  if ( !CUtlBuffer::CheckGet(this, nSize: 1) )
    return 0;
  result = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  ++this->m_Get;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102DEF10
// Name: public: void CUtlBuffer::PutUnsignedChar(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutUnsignedChar(CUtlBuffer *this, unsigned __int8 c)
{
  if ( (this->m_Flags & 1) != 0 )
  {
    CUtlBuffer::Printf(this, pFmt: "%hu", c);
  }
  else if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = c;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DEF60
// Name: public: virtual void CCSNavArea::Save(class CUtlBuffer __near &,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSNavArea::Save(CCSNavArea *this, CUtlBuffer *fileBuffer, signed int version)
{
  CUtlBuffer *v3; // esi
  unsigned __int8 m_approachCount; // bl
  bool v6; // zf
  NavConnect *p_prev; // edi
  unsigned int id; // eax
  int v9; // ebx
  unsigned int v10; // eax
  int v11; // ebx
  unsigned __int8 v12; // bl
  float length; // eax
  int v14; // ebx
  unsigned __int8 length_low; // bl
  signed int v16; // edx

  v3 = fileBuffer;
  CNavArea::Save(this, fileBuffer, version);
  m_approachCount = this->m_approachCount;
  if ( (v3->m_Flags & 1) != 0 )
  {
    CUtlBuffer::Printf(this: v3, pFmt: "%hu", m_approachCount);
  }
  else if ( CUtlBuffer::CheckPut(this: v3, nSize: 1) )
  {
    v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset] = m_approachCount;
    CUtlBuffer::AddNullTermination(this: v3, nPut: ++v3->m_Put);
  }
  v6 = this->m_approachCount == 0;
  version = 0;
  if ( !v6 )
  {
    p_prev = &this->m_approach[0].prev;
    do
    {
      id = p_prev[-1].id;
      if ( id != 0 )
      {
        v9 = *(_DWORD *)(id + 136);
        if ( (v3->m_Flags & 1) == 0 )
        {
          fileBuffer = *(CUtlBuffer **)(id + 136);
          if ( !CUtlBuffer::CheckPut(this: v3, nSize: 4) )
            goto LABEL_20;
          if ( (*(_BYTE *)&v3->m_Byteswap & 1) != 0 )
            goto LABEL_11;
          *(_DWORD *)&v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset] = v9;
          goto LABEL_12;
        }
        CUtlBuffer::Printf(this: v3, pFmt: "%u", *(_DWORD *)(id + 136));
      }
      else if ( (v3->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: v3, pFmt: "%u", 0);
      }
      else
      {
        fileBuffer = nullptr;
        if ( CUtlBuffer::CheckPut(this: v3, nSize: 4) )
        {
          if ( (*(_BYTE *)&v3->m_Byteswap & 1) == 0 )
          {
            *(_DWORD *)&v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset] = 0;
            goto LABEL_12;
          }
LABEL_11:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this: &v3->m_Byteswap,
            outputBuffer: (int *)&v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset],
            inputBuffer: (int *)&fileBuffer,
            count: 1);
LABEL_12:
          v3->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
        }
      }
LABEL_20:
      v10 = p_prev->id;
      if ( p_prev->id != 0 )
      {
        v11 = *(_DWORD *)(v10 + 136);
        if ( (v3->m_Flags & 1) == 0 )
        {
          fileBuffer = *(CUtlBuffer **)(v10 + 136);
          if ( !CUtlBuffer::CheckPut(this: v3, nSize: 4) )
            goto LABEL_33;
          if ( (*(_BYTE *)&v3->m_Byteswap & 1) != 0 )
            goto LABEL_24;
          *(_DWORD *)&v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset] = v11;
          goto LABEL_25;
        }
        CUtlBuffer::Printf(this: v3, pFmt: "%u", *(_DWORD *)(v10 + 136));
      }
      else if ( (v3->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: v3, pFmt: "%u", 0);
      }
      else
      {
        fileBuffer = nullptr;
        if ( CUtlBuffer::CheckPut(this: v3, nSize: 4) )
        {
          if ( (*(_BYTE *)&v3->m_Byteswap & 1) == 0 )
          {
            *(_DWORD *)&v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset] = 0;
            goto LABEL_25;
          }
LABEL_24:
          CByteswap::SwapBufferToTargetEndian<unsigned int>(
            this: &v3->m_Byteswap,
            outputBuffer: (int *)&v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset],
            inputBuffer: (int *)&fileBuffer,
            count: 1);
LABEL_25:
          v3->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
        }
      }
LABEL_33:
      v12 = p_prev[1].id;
      if ( (v3->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: v3, pFmt: "%hu", v12);
      }
      else if ( CUtlBuffer::CheckPut(this: v3, nSize: 1) )
      {
        v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset] = v12;
        CUtlBuffer::AddNullTermination(this: v3, nPut: ++v3->m_Put);
      }
      length = p_prev[1].length;
      if ( length == 0.0 )
      {
        if ( (v3->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v3, pFmt: "%u", 0);
          goto LABEL_50;
        }
        fileBuffer = nullptr;
        if ( CUtlBuffer::CheckPut(this: v3, nSize: 4) )
        {
          if ( (*(_BYTE *)&v3->m_Byteswap & 1) != 0 )
LABEL_41:
            CByteswap::SwapBufferToTargetEndian<unsigned int>(
              this: &v3->m_Byteswap,
              outputBuffer: (int *)&v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset],
              inputBuffer: (int *)&fileBuffer,
              count: 1);
          else
            *(_DWORD *)&v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset] = 0;
LABEL_42:
          v3->m_Put += 4;
          CUtlBuffer::AddNullTermination(this: v3, nPut: v3->m_Put);
        }
      }
      else
      {
        v14 = *(_DWORD *)(LODWORD(length) + 136);
        if ( (v3->m_Flags & 1) != 0 )
        {
          CUtlBuffer::Printf(this: v3, pFmt: "%u", *(_DWORD *)(LODWORD(length) + 136));
          goto LABEL_50;
        }
        fileBuffer = *(CUtlBuffer **)(LODWORD(length) + 136);
        if ( CUtlBuffer::CheckPut(this: v3, nSize: 4) )
        {
          if ( (*(_BYTE *)&v3->m_Byteswap & 1) != 0 )
            goto LABEL_41;
          *(_DWORD *)&v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset] = v14;
          goto LABEL_42;
        }
      }
LABEL_50:
      length_low = LOBYTE(p_prev[2].length);
      if ( (v3->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: v3, pFmt: "%hu", length_low);
      }
      else if ( CUtlBuffer::CheckPut(this: v3, nSize: 1) )
      {
        v3->m_Memory.m_pMemory[v3->m_Put - v3->m_nOffset] = length_low;
        CUtlBuffer::AddNullTermination(this: v3, nPut: ++v3->m_Put);
      }
      v16 = this->m_approachCount;
      p_prev += 4;
      ++version;
    }
    while ( version < v16 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DF360
// Name: protected: enum NavErrorType CCSNavArea::LoadLegacy(class CUtlBuffer __near &,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
NavErrorType __thiscall CCSNavArea::LoadLegacy(
        CCSNavArea *this,
        int fileBuffer,
        unsigned int version,
        unsigned int subVersion)
{
  CUtlBuffer *v4; // esi
  unsigned int UnsignedInt; // eax
  unsigned __int8 v7; // al
  float x; // xmm3_4
  float y; // xmm7_4
  float v10; // xmm4_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm4_4
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *m_connect; // edi
  CUtlBuffer *v18; // eax
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // ecx
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v20; // eax
  int v21; // eax
  int m_Size; // ecx
  char *v23; // eax
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v24; // eax
  unsigned __int8 UnsignedShort; // al
  HidingSpot *v26; // edi
  HidingSpot **v27; // ecx
  int v28; // eax
  CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *v29; // eax
  int v30; // eax
  CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *v31; // ecx
  int v32; // edi
  int v33; // eax
  CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *v34; // eax
  int v35; // eax
  unsigned __int8 v36; // al
  NavConnect *p_prev; // edi
  unsigned __int8 v38; // al
  unsigned __int8 v39; // al
  int m_approachCount; // ecx
  HidingSpot *v41; // eax
  unsigned __int8 v42; // al
  int v43; // edi
  SpotOrder *v44; // eax
  CUtlBuffer *v46; // eax
  CUtlBuffer *v47; // edi
  unsigned __int8 v48; // al
  unsigned __int8 v49; // al
  unsigned __int8 v50; // al
  CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *v51; // edi
  unsigned int v52; // eax
  bool v53; // zf
  unsigned __int8 v54; // al
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *m_pMemory; // ebx
  int v56; // ecx
  int m_nAllocationCount; // eax
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *v58; // ecx
  int v59; // eax
  CNavArea::AreaBindInfo *v60; // ebx
  CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *v61; // ecx
  int v62; // edi
  int v63; // eax
  CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *v64; // eax
  signed int v65; // ebx
  CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *v66; // eax
  CCSNavArea *v67; // eax
  unsigned int v68; // ebx
  unsigned __int16 v69; // ax
  unsigned int v70; // eax
  CCSNavArea *v71; // edi
  void **p_m_pData; // edi
  unsigned int v73; // eax
  unsigned int v74; // eax
  int *v75; // edx
  int v76; // ecx
  NavLadderConnect v77; // ebx
  int v78; // eax
  _DWORD *v79; // edx
  _DWORD *v80; // ecx
  int v81; // ebx
  int v82; // eax
  _DWORD *v83; // eax
  int v84; // eax
  int *m_earliestOccupyTime; // edi
  int i; // ebx
  int *m_lightIntensity; // edi
  int j; // ebx
  unsigned int v89; // eax
  CUtlVector<CNavArea::AreaBindInfo,CUtlMemoryConservative<CNavArea::AreaBindInfo> > *v90; // edi
  signed int v91; // ebx
  unsigned int v92; // eax
  unsigned int v93; // eax
  unsigned int v94; // eax
  CNavArea::AreaBindInfo *v95; // eax
  unsigned int v96; // eax
  unsigned __int8 v97; // al
  int v98; // ebx
  CNavArea::AreaBindInfo *v99; // eax
  unsigned int m_id; // [esp-4h] [ebp-88h]
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v101; // [esp+14h] [ebp-70h]
  CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *v102; // [esp+14h] [ebp-70h]
  SpotEncounter encounter; // [esp+24h] [ebp-60h] BYREF
  float pMem; // [esp+68h] [ebp-1Ch] BYREF
  CNavArea::AreaBindInfo info; // [esp+6Ch] [ebp-18h]
  int dest; // [esp+74h] [ebp-10h] BYREF
  HidingSpot *spot; // [esp+78h] [ebp-Ch] BYREF
  NavLadderConnect connect; // [esp+7Ch] [ebp-8h] BYREF
  CCSNavArea *v109; // [esp+80h] [ebp-4h]

  v4 = (CUtlBuffer *)fileBuffer;
  v109 = this;
  UnsignedInt = CUtlBuffer::GetUnsignedInt(this: (CUtlBuffer *)fileBuffer);
  this->m_id = UnsignedInt;
  if ( UnsignedInt >= CNavArea::m_nextID )
    CNavArea::m_nextID = UnsignedInt + 1;
  if ( version > 8 )
  {
    if ( version >= 0xD )
      this->m_attributeFlags = CUtlBuffer::GetInt(this: v4);
    else
      this->m_attributeFlags = (unsigned __int16)CUtlBuffer::GetUnsignedShort(this: v4);
  }
  else if ( (v4->m_Flags & 1) != 0 )
  {
    this->m_attributeFlags = (unsigned __int8)CUtlBuffer::GetUnsignedShort(this: v4);
  }
  else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
  {
    v7 = v4->m_Memory.m_pMemory[v4->m_Get++ - v4->m_nOffset];
    this->m_attributeFlags = v7;
  }
  else
  {
    this->m_attributeFlags = 0;
  }
  CUtlBuffer::Get(this: v4, pMem: &this->CNavAreaCriticalData, size: 12);
  CUtlBuffer::Get(this: v4, pMem: (void *)&this->m_seCorner, size: 12);
  x = this->m_seCorner.x;
  y = this->m_nwCorner.y;
  v10 = this->m_seCorner.y;
  v11 = this->m_nwCorner.x + x;
  v12 = x - this->m_nwCorner.x;
  v13 = v11 * 0.5;
  v14 = (float)(y + v10) * 0.5;
  v15 = (float)(this->m_seCorner.z + this->m_nwCorner.z) * 0.5;
  this->m_center.x = v13;
  this->m_center.y = v14;
  this->m_center.z = v15;
  if ( v12 <= 0.0 || (v16 = v10 - y) <= 0.0 )
  {
    m_id = this->m_id;
    *(_QWORD *)&this->m_invDxCorners = 0;
    DevWarning(a1: "Degenerate Navigation Area #%d at setpos %g %g %g\n", m_id, v13, v14, v15);
  }
  else
  {
    this->m_invDxCorners = 1.0 / v12;
    this->m_invDyCorners = 1.0 / v16;
  }
  CUtlBuffer::GetType<float>(this: v4, dest: (float *)&fileBuffer);
  LODWORD(this->m_neZ) = fileBuffer;
  CUtlBuffer::GetType<float>(this: v4, dest: (float *)&fileBuffer);
  LODWORD(this->m_swZ) = fileBuffer;
  CNavArea::CheckWaterLevel(this);
  m_connect = this->m_connect;
  for ( dest = 4; dest != 0; --dest )
  {
    v18 = (CUtlBuffer *)CUtlBuffer::GetUnsignedInt(this: v4);
    m_pData = m_connect->m_pData;
    fileBuffer = (int)v18;
    if ( (int)v18 > m_pData->m_Size )
    {
      if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
          & 1) == 0 )
        `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
      if ( m_connect->m_pData == (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
      {
        v20 = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)operator new(nSize: 8 * fileBuffer + 4);
        m_connect->m_pData = v20;
        v20->m_Size = 0;
      }
      else
      {
        v21 = _msize(pMem: m_connect->m_pData);
        if ( 8 * fileBuffer + 4 > v21 )
          m_connect->m_pData = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)_realloc_crt(ptr: m_connect->m_pData, size: 8 * fileBuffer + 4);
      }
    }
    if ( fileBuffer != 0 )
    {
      *(_DWORD *)&info.attributes = -1082130432;
      for ( spot = (HidingSpot *)fileBuffer; spot != nullptr; spot = (HidingSpot *)((char *)spot - 1) )
      {
        info.id = CUtlBuffer::GetUnsignedInt(this: v4);
        if ( info.id != this->m_id )
        {
          m_Size = m_connect->m_pData->m_Size;
          v23 = (char *)(m_Size + 1);
          fileBuffer = m_Size;
          if ( m_Size + 1 > m_Size )
          {
            if ( (`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard'
                & 1) == 0 )
              `CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::`local static guard' |= 1u;
            if ( m_connect->m_pData == (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
            {
              v24 = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)operator new(nSize: 8 * (_DWORD)v23 + 4);
              m_connect->m_pData = v24;
              v24->m_Size = 0;
            }
            else
            {
              v101 = m_connect->m_pData;
              connect.id = 8 * (_DWORD)v23 + 4;
              if ( (int)connect.id > (int)_msize(pMem: v101) )
                m_connect->m_pData = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *)_realloc_crt(ptr: m_connect->m_pData, size: connect.id);
            }
            m_Size = fileBuffer;
          }
          m_connect->m_pData->m_Elements[m_Size] = (NavConnect)info;
          ++m_connect->m_pData->m_Size;
        }
      }
    }
    ++m_connect;
  }
  if ( (v4->m_Flags & 1) != 0 )
  {
    UnsignedShort = CUtlBuffer::GetUnsignedShort(this: v4);
  }
  else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
  {
    UnsignedShort = v4->m_Memory.m_pMemory[v4->m_Get++ - v4->m_nOffset];
  }
  else
  {
    UnsignedShort = 0;
  }
  if ( version == 1 )
  {
    if ( UnsignedShort != 0 )
    {
      for ( dest = UnsignedShort; dest != 0; --dest )
      {
        CUtlBuffer::Get(this: v4, &pMem, size: 12);
        v26 = TheNavMesh->CreateHidingSpot(this: TheNavMesh);
        v26->m_pos.x = pMem;
        *(CNavArea::AreaBindInfo *)&v26->m_pos.y = info;
        v26->m_flags |= 1u;
        v27 = (HidingSpot **)this->m_hidingSpots.m_pData;
        v28 = (int)&(*v27)->__vftable + 1;
        spot = *v27;
        if ( v28 > (int)spot )
        {
          if ( v27 == (HidingSpot **)&`CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
          {
            v29 = (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)operator new(nSize: 4 * v28 + 4);
            this->m_hidingSpots.m_pData = v29;
            v29->m_Size = 0;
          }
          else
          {
            fileBuffer = 4 * v28 + 4;
            v30 = _msize(pMem: v27);
            if ( fileBuffer > v30 )
              this->m_hidingSpots.m_pData = (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)_realloc_crt(ptr: this->m_hidingSpots.m_pData, size: fileBuffer);
          }
        }
        this->m_hidingSpots.m_pData->m_Elements[(_DWORD)spot] = v26;
        ++this->m_hidingSpots.m_pData->m_Size;
      }
    }
LABEL_62:
    if ( (v4->m_Flags & 1) != 0 )
    {
      v36 = CUtlBuffer::GetUnsignedShort(this: v4);
    }
    else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
    {
      v36 = v4->m_Memory.m_pMemory[v4->m_Get++ - v4->m_nOffset];
    }
    else
    {
      v36 = 0;
    }
    this->m_approachCount = v36;
    fileBuffer = 0;
    if ( v36 != 0 )
    {
      p_prev = &this->m_approach[0].prev;
      do
      {
        p_prev[-1].id = CUtlBuffer::GetUnsignedInt(this: v4);
        p_prev->id = CUtlBuffer::GetUnsignedInt(this: v4);
        if ( (v4->m_Flags & 1) != 0 )
        {
          v38 = CUtlBuffer::GetUnsignedShort(this: v4);
        }
        else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
        {
          v38 = v4->m_Memory.m_pMemory[v4->m_Get++ - v4->m_nOffset];
        }
        else
        {
          v38 = 0;
        }
        p_prev[1].id = v38;
        LODWORD(p_prev[1].length) = CUtlBuffer::GetUnsignedInt(this: v4);
        if ( (v4->m_Flags & 1) != 0 )
        {
          v39 = CUtlBuffer::GetUnsignedShort(this: v4);
        }
        else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
        {
          v39 = v4->m_Memory.m_pMemory[v4->m_Get++ - v4->m_nOffset];
        }
        else
        {
          v39 = 0;
        }
        LODWORD(p_prev[2].length) = v39;
        m_approachCount = this->m_approachCount;
        p_prev += 4;
        ++fileBuffer;
      }
      while ( fileBuffer < m_approachCount );
    }
    goto LABEL_80;
  }
  if ( UnsignedShort != 0 )
  {
    for ( dest = UnsignedShort; dest != 0; --dest )
    {
      spot = TheNavMesh->CreateHidingSpot(this: TheNavMesh);
      HidingSpot::Load(this: spot, fileBuffer: v4, version);
      v31 = this->m_hidingSpots.m_pData;
      v32 = v31->m_Size;
      v33 = v31->m_Size + 1;
      if ( v33 > v31->m_Size )
      {
        if ( v31 == (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
        {
          v34 = (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)operator new(nSize: 4 * v33 + 4);
          this->m_hidingSpots.m_pData = v34;
          v34->m_Size = 0;
        }
        else
        {
          v102 = this->m_hidingSpots.m_pData;
          fileBuffer = 4 * v33 + 4;
          v35 = _msize(pMem: v102);
          if ( fileBuffer > v35 )
            this->m_hidingSpots.m_pData = (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)_realloc_crt(ptr: this->m_hidingSpots.m_pData, size: fileBuffer);
        }
      }
      this->m_hidingSpots.m_pData->m_Elements[v32] = spot;
      ++this->m_hidingSpots.m_pData->m_Size;
    }
  }
  if ( version < 0xF )
    goto LABEL_62;
LABEL_80:
  v41 = (HidingSpot *)CUtlBuffer::GetUnsignedInt(this: v4);
  if ( version >= 3 )
  {
    if ( v41 != nullptr )
    {
      for ( spot = v41; spot != nullptr; spot = (HidingSpot *)((char *)spot - 1) )
      {
        v46 = (CUtlBuffer *)operator new(nSize: 0x44u);
        if ( v46 != nullptr )
        {
          v46->m_Memory.m_pMemory = nullptr;
          v46->m_Memory.m_nAllocationCount = -1082130432;
          v46->m_Get = 0;
          v46->m_Put = -1082130432;
          v46[1].m_Memory.m_pMemory = nullptr;
          v46[1].m_Memory.m_nAllocationCount = 0;
          v46[1].m_Memory.m_nGrowSize = 0;
          v46[1].m_Get = 0;
          v46[1].m_Put = 0;
          v47 = v46;
          fileBuffer = (int)v46;
        }
        else
        {
          v47 = nullptr;
          fileBuffer = 0;
        }
        v47->m_Memory.m_pMemory = (unsigned __int8 *)CUtlBuffer::GetUnsignedInt(this: v4);
        if ( (v4->m_Flags & 1) != 0 )
        {
          v48 = CUtlBuffer::GetUnsignedShort(this: v4);
        }
        else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
        {
          v48 = v4->m_Memory.m_pMemory[v4->m_Get++ - v4->m_nOffset];
        }
        else
        {
          v48 = 0;
        }
        v47->m_Memory.m_nGrowSize = v48;
        v47->m_Get = CUtlBuffer::GetUnsignedInt(this: v4);
        if ( (v4->m_Flags & 1) != 0 )
        {
          v49 = CUtlBuffer::GetUnsignedShort(this: v4);
        }
        else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
        {
          v49 = v4->m_Memory.m_pMemory[v4->m_Get++ - v4->m_nOffset];
        }
        else
        {
          v49 = 0;
        }
        *(_DWORD *)&v47->m_Error = v49;
        if ( (v4->m_Flags & 1) != 0 )
        {
          v50 = CUtlBuffer::GetUnsignedShort(this: v4);
        }
        else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
        {
          v50 = v4->m_Memory.m_pMemory[v4->m_Get++ - v4->m_nOffset];
        }
        else
        {
          v50 = 0;
        }
        if ( v50 != 0 )
        {
          v51 = (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)fileBuffer;
          for ( dest = v50; dest != 0; --dest )
          {
            v52 = CUtlBuffer::GetUnsignedInt(this: v4);
            v53 = (v4->m_Flags & 1) == 0;
            *(_DWORD *)&info.attributes = v52;
            if ( v53 )
            {
              if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
                v54 = v4->m_Memory.m_pMemory[v4->m_Get++ - v4->m_nOffset];
              else
                v54 = 0;
            }
            else
            {
              v54 = CUtlBuffer::GetUnsignedShort(this: v4);
            }
            m_pMemory = v51[5].m_pMemory;
            v56 = v54;
            m_nAllocationCount = v51[4].m_nAllocationCount;
            *(float *)&info.area = (float)v56 * 0.0039215689;
            if ( (int)m_pMemory + 1 > m_nAllocationCount )
              CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
                this: v51 + 4,
                num: (int)m_pMemory - m_nAllocationCount + 1);
            ++v51[5].m_pMemory;
            v58 = v51[4].m_pMemory;
            v59 = (char *)v51[5].m_pMemory - (char *)m_pMemory - 1;
            v51[5].m_nAllocationCount = (int)v58;
            if ( v59 > 0 )
              _V_memmove(dest: &v58[(int)m_pMemory + 1], src: &v58[(_DWORD)m_pMemory], count: 8 * v59);
            v60 = (CNavArea::AreaBindInfo *)&v51[4].m_pMemory[(_DWORD)m_pMemory];
            if ( v60 != nullptr )
              *v60 = info;
          }
        }
        v61 = v109->m_spotEncounters.m_pData;
        v62 = v61->m_Size;
        v63 = v61->m_Size + 1;
        if ( v63 > v61->m_Size )
        {
          if ( v61 == (CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
          {
            v64 = (CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *)operator new(nSize: 4 * v63 + 4);
            v109->m_spotEncounters.m_pData = v64;
            v64->m_Size = 0;
          }
          else
          {
            v65 = 4 * v63 + 4;
            if ( v65 > (int)_msize(pMem: v109->m_spotEncounters.m_pData) )
            {
              v66 = (CUtlVectorUltraConservative<SpotEncounter *,CUtlVectorUltraConservativeAllocator>::Data_t *)_realloc_crt(ptr: v109->m_spotEncounters.m_pData, size: v65);
              v109->m_spotEncounters.m_pData = v66;
            }
          }
        }
        v67 = v109;
        v109->m_spotEncounters.m_pData->m_Elements[v62] = (SpotEncounter *)fileBuffer;
        ++v67->m_spotEncounters.m_pData->m_Size;
      }
    }
    v68 = version;
    if ( version >= 5 )
    {
      v69 = CUtlBuffer::GetUnsignedShort(this: v4);
      v70 = PlaceDirectory::IndexToPlace(this: &placeDirectory, entry: v69);
      v71 = v109;
      v109->m_place = v70;
      if ( v68 >= 7 )
      {
        p_m_pData = (void **)&v71->m_ladder[0].m_pData;
        for ( spot = (HidingSpot *)2; spot != nullptr; spot = (HidingSpot *)((char *)spot - 1) )
        {
          v73 = CUtlBuffer::GetUnsignedInt(this: v4);
          if ( v73 != 0 )
          {
            for ( dest = v73; dest != 0; --dest )
            {
              v74 = CUtlBuffer::GetUnsignedInt(this: v4);
              v75 = (int *)*p_m_pData;
              v76 = *(_DWORD *)*p_m_pData;
              v77.id = v74;
              v78 = 0;
              connect.id = v77.id;
              if ( v76 <= 0 )
              {
LABEL_148:
                v80 = *p_m_pData;
                v81 = *(_DWORD *)*p_m_pData;
                v82 = v81 + 1;
                if ( v81 + 1 > v81 )
                {
                  if ( v80 == (_DWORD *)&`CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
                  {
                    v83 = operator new(nSize: 4 * v82 + 4);
                    *p_m_pData = v83;
                    *v83 = 0;
                  }
                  else
                  {
                    fileBuffer = 4 * v82 + 4;
                    v84 = _msize(pMem: v80);
                    if ( fileBuffer > v84 )
                      *p_m_pData = _realloc_crt(ptr: *p_m_pData, size: fileBuffer);
                  }
                }
                *((NavLadderConnect *)*p_m_pData + v81 + 1) = connect;
                ++*(_DWORD *)*p_m_pData;
              }
              else
              {
                v79 = v75 + 1;
                while ( *v79 != v77.id )
                {
                  ++v78;
                  ++v79;
                  if ( v78 >= v76 )
                    goto LABEL_148;
                }
              }
            }
          }
          ++p_m_pData;
        }
        if ( version >= 8 )
        {
          m_earliestOccupyTime = (int *)v109->m_earliestOccupyTime;
          for ( i = 2; i != 0; --i )
          {
            CUtlBuffer::GetType<float>(this: v4, dest: (float *)&fileBuffer);
            *m_earliestOccupyTime++ = fileBuffer;
          }
          if ( version >= 0xB )
          {
            m_lightIntensity = (int *)v109->m_lightIntensity;
            for ( j = 4; j != 0; --j )
            {
              CUtlBuffer::GetType<float>(this: v4, dest: (float *)&fileBuffer);
              *m_lightIntensity++ = fileBuffer;
            }
            if ( version >= 0x10 )
            {
              v89 = CUtlBuffer::GetUnsignedInt(this: v4);
              v90 = (CUtlVector<CNavArea::AreaBindInfo,CUtlMemoryConservative<CNavArea::AreaBindInfo> > *)v109;
              v91 = v89;
              if ( v109->m_potentiallyVisibleAreas.m_Memory.m_pMemory != nullptr )
                v92 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: v109->m_potentiallyVisibleAreas.m_Memory.m_pMemory);
              else
                v92 = 0;
              if ( v91 <= (int)(v92 >> 3) )
              {
                if ( v90[24].m_Memory.m_pMemory != nullptr )
                  v94 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: v90[24].m_Memory.m_pMemory);
                else
                  v94 = 0;
                v93 = v94 >> 3;
              }
              else
              {
                v93 = v91;
              }
              v95 = (CNavArea::AreaBindInfo *)_g_pMemAlloc->Realloc_2(
                                                this: _g_pMemAlloc,
                                                a2: v90[24].m_Memory.m_pMemory,
                                                a3: 8 * v93);
              v90[24].m_Memory.m_pMemory = v95;
              v90[24].m_pElements = v95;
              if ( v91 != 0 )
              {
                for ( version = v91; version != 0; --version )
                {
                  v96 = CUtlBuffer::GetUnsignedInt(this: v4);
                  v53 = (v4->m_Flags & 1) == 0;
                  info.id = v96;
                  if ( v53 )
                  {
                    if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
                      v97 = v4->m_Memory.m_pMemory[v4->m_Get++ - v4->m_nOffset];
                    else
                      v97 = 0;
                  }
                  else
                  {
                    v97 = CUtlBuffer::GetUnsignedShort(this: v4);
                  }
                  v98 = v90[24].m_Size;
                  info.attributes = v97;
                  CUtlVector<CNavArea::AreaBindInfo,CUtlMemoryConservative<CNavArea::AreaBindInfo>>::GrowVector(
                    this: v90 + 24,
                    num: 1);
                  if ( v90[24].m_Size - v98 - 1 > 0 )
                    _V_memmove(
                      dest: &v90[24].m_Memory.m_pMemory[v98 + 1],
                      src: &v90[24].m_Memory.m_pMemory[v98],
                      count: 8 * (v90[24].m_Size - v98 - 1));
                  v99 = &v90[24].m_Memory.m_pMemory[v98];
                  if ( v99 != nullptr )
                    *v99 = info;
                }
              }
              v90[23].m_Size = CUtlBuffer::GetUnsignedInt(this: v4);
            }
          }
        }
      }
    }
  }
  else if ( v41 != nullptr )
  {
    for ( version = (unsigned int)v41; version != 0; --version )
    {
      memset(&encounter.spots, 0, sizeof(encounter.spots));
      CUtlBuffer::GetUnsignedInt(this: v4);
      CUtlBuffer::GetUnsignedInt(this: v4);
      CUtlBuffer::Get(this: v4, pMem: &encounter.path, size: 12);
      CUtlBuffer::Get(this: v4, pMem: (void *)&encounter.path.to, size: 12);
      if ( (v4->m_Flags & 1) != 0 )
      {
        v42 = CUtlBuffer::GetUnsignedShort(this: v4);
      }
      else if ( CUtlBuffer::CheckGet(this: v4, nSize: 1) )
      {
        v42 = v4->m_Memory.m_pMemory[v4->m_Get++ - v4->m_nOffset];
      }
      else
      {
        v42 = 0;
      }
      v43 = v42;
      if ( v42 != 0 )
      {
        do
        {
          CUtlBuffer::GetType<float>(this: v4, dest: (float *)&fileBuffer);
          CUtlBuffer::GetType<float>(this: v4, (float *)&dest);
          CUtlBuffer::GetType<float>(this: v4, dest: (float *)&spot);
          CUtlBuffer::GetType<float>(this: v4, dest: (float *)&connect.id);
          --v43;
        }
        while ( v43 != 0 );
      }
      v44 = encounter.spots.m_Memory.m_pMemory;
      encounter.spots.m_Size = 0;
      if ( encounter.spots.m_Memory.m_nGrowSize >= 0 )
      {
        if ( encounter.spots.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: encounter.spots.m_Memory.m_pMemory);
          v44 = nullptr;
          encounter.spots.m_Memory.m_pMemory = nullptr;
        }
        encounter.spots.m_Memory.m_nAllocationCount = 0;
      }
      encounter.spots.m_pElements = v44;
      if ( encounter.spots.m_Memory.m_nGrowSize >= 0 && v44 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v44);
    }
    return NAV_OK;
  }
  return NAV_OK;
}

//------------------------------------------------------------------------------
// Address: 0x102DFF30
// Name: public: virtual enum NavErrorType CCSNavArea::Load(class CUtlBuffer __near &,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
NavErrorType __thiscall CCSNavArea::Load(
        CCSNavArea *this,
        CUtlBuffer *fileBuffer,
        unsigned int version,
        NavErrorType subVersion)
{
  unsigned __int8 UnsignedShort; // al
  int v8; // ebx
  NavConnect *p_prev; // edi
  unsigned __int8 v10; // al
  unsigned __int8 v11; // al
  NavErrorType error; // [esp+18h] [ebp+10h]

  if ( version < 0xF )
    return CCSNavArea::LoadLegacy(this, (int)fileBuffer, version, subVersion);
  error = CNavArea::Load(this, fileBuffer, version, subVersion);
  if ( subVersion != NAV_OK )
  {
    if ( subVersion != NAV_CANT_ACCESS_FILE )
    {
      _Warning(a1: "Unknown NavArea sub-version number\n");
      return NAV_INVALID_FILE;
    }
    if ( (fileBuffer->m_Flags & 1) != 0 )
    {
      UnsignedShort = CUtlBuffer::GetUnsignedShort(this: fileBuffer);
    }
    else if ( CUtlBuffer::CheckGet(this: fileBuffer, nSize: 1) )
    {
      UnsignedShort = fileBuffer->m_Memory.m_pMemory[fileBuffer->m_Get++ - fileBuffer->m_nOffset];
    }
    else
    {
      UnsignedShort = 0;
    }
    this->m_approachCount = UnsignedShort;
    v8 = 0;
    if ( UnsignedShort != 0 )
    {
      p_prev = &this->m_approach[0].prev;
      do
      {
        p_prev[-1].id = CUtlBuffer::GetUnsignedInt(this: fileBuffer);
        p_prev->id = CUtlBuffer::GetUnsignedInt(this: fileBuffer);
        if ( (fileBuffer->m_Flags & 1) != 0 )
        {
          v10 = CUtlBuffer::GetUnsignedShort(this: fileBuffer);
        }
        else if ( CUtlBuffer::CheckGet(this: fileBuffer, nSize: 1) )
        {
          v10 = fileBuffer->m_Memory.m_pMemory[fileBuffer->m_Get++ - fileBuffer->m_nOffset];
        }
        else
        {
          v10 = 0;
        }
        p_prev[1].id = v10;
        LODWORD(p_prev[1].length) = CUtlBuffer::GetUnsignedInt(this: fileBuffer);
        if ( (fileBuffer->m_Flags & 1) != 0 )
        {
          v11 = CUtlBuffer::GetUnsignedShort(this: fileBuffer);
        }
        else if ( CUtlBuffer::CheckGet(this: fileBuffer, nSize: 1) )
        {
          v11 = fileBuffer->m_Memory.m_pMemory[fileBuffer->m_Get++ - fileBuffer->m_nOffset];
        }
        else
        {
          v11 = 0;
        }
        LODWORD(p_prev[2].length) = v11;
        ++v8;
        p_prev += 4;
      }
      while ( v8 < this->m_approachCount );
    }
    if ( fileBuffer->m_Error != 0 )
      return NAV_INVALID_FILE;
  }
  return error;
}
