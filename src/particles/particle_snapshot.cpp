// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: particles/particle_snapshot.cpp
// Functions: 11
// ============================================================

#include "particles\particle_snapshot.h"

//------------------------------------------------------------------------------
// Address: 0x0052F080
// Name: public: void CParticleSnapshot::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSnapshot::Purge(CParticleSnapshot *this)
{
  CSOAContainer::Purge(this: &this->m_Container);
  this->m_pContainer = nullptr;
  this->m_ParticleAttributeToContainerAttribute[0] = -1;
  this->m_ParticleAttributeToContainerAttribute[1] = -1;
  this->m_ParticleAttributeToContainerAttribute[2] = -1;
  this->m_ParticleAttributeToContainerAttribute[3] = -1;
  this->m_ParticleAttributeToContainerAttribute[4] = -1;
  this->m_ParticleAttributeToContainerAttribute[5] = -1;
  this->m_ParticleAttributeToContainerAttribute[6] = -1;
  this->m_ParticleAttributeToContainerAttribute[7] = -1;
  this->m_ParticleAttributeToContainerAttribute[8] = -1;
  this->m_ParticleAttributeToContainerAttribute[9] = -1;
  this->m_ParticleAttributeToContainerAttribute[10] = -1;
  this->m_ParticleAttributeToContainerAttribute[11] = -1;
  this->m_ParticleAttributeToContainerAttribute[12] = -1;
  this->m_ParticleAttributeToContainerAttribute[13] = -1;
  this->m_ParticleAttributeToContainerAttribute[14] = -1;
  this->m_ParticleAttributeToContainerAttribute[15] = -1;
  this->m_ParticleAttributeToContainerAttribute[16] = -1;
  this->m_ParticleAttributeToContainerAttribute[17] = -1;
  this->m_ParticleAttributeToContainerAttribute[18] = -1;
  this->m_ParticleAttributeToContainerAttribute[19] = -1;
  this->m_ParticleAttributeToContainerAttribute[20] = -1;
  this->m_ParticleAttributeToContainerAttribute[21] = -1;
  this->m_ParticleAttributeToContainerAttribute[22] = -1;
  this->m_ParticleAttributeToContainerAttribute[23] = -1;
  this->m_ContainerAttributeToParticleAttribute[0] = -1;
  this->m_ContainerAttributeToParticleAttribute[1] = -1;
  this->m_ContainerAttributeToParticleAttribute[2] = -1;
  this->m_ContainerAttributeToParticleAttribute[3] = -1;
  this->m_ContainerAttributeToParticleAttribute[4] = -1;
  this->m_ContainerAttributeToParticleAttribute[5] = -1;
  this->m_ContainerAttributeToParticleAttribute[6] = -1;
  this->m_ContainerAttributeToParticleAttribute[7] = -1;
  this->m_ContainerAttributeToParticleAttribute[8] = -1;
  this->m_ContainerAttributeToParticleAttribute[9] = -1;
  this->m_ContainerAttributeToParticleAttribute[10] = -1;
  this->m_ContainerAttributeToParticleAttribute[11] = -1;
  this->m_ContainerAttributeToParticleAttribute[12] = -1;
  this->m_ContainerAttributeToParticleAttribute[13] = -1;
  this->m_ContainerAttributeToParticleAttribute[14] = -1;
  this->m_ContainerAttributeToParticleAttribute[15] = -1;
  this->m_ContainerAttributeToParticleAttribute[16] = -1;
  this->m_ContainerAttributeToParticleAttribute[17] = -1;
  this->m_ContainerAttributeToParticleAttribute[18] = -1;
  this->m_ContainerAttributeToParticleAttribute[19] = -1;
  this->m_ContainerAttributeToParticleAttribute[20] = -1;
  this->m_ContainerAttributeToParticleAttribute[21] = -1;
  this->m_ContainerAttributeToParticleAttribute[22] = -1;
  this->m_ContainerAttributeToParticleAttribute[23] = -1;
  this->m_ContainerAttributeToParticleAttribute[24] = -1;
  this->m_ContainerAttributeToParticleAttribute[25] = -1;
  this->m_ContainerAttributeToParticleAttribute[26] = -1;
  this->m_ContainerAttributeToParticleAttribute[27] = -1;
  this->m_ContainerAttributeToParticleAttribute[28] = -1;
  this->m_ContainerAttributeToParticleAttribute[29] = -1;
  this->m_ContainerAttributeToParticleAttribute[30] = -1;
  this->m_ContainerAttributeToParticleAttribute[31] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052F1F0
// Name: private: bool CParticleSnapshot::AddAttributeMapping(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CParticleSnapshot::AddAttributeMapping(
        CParticleSnapshot *this,
        int nFieldNumber,
        int nParticleAttribute,
        const char *pFunc)
{
  int v5; // eax
  int v6; // eax

  v5 = this->m_ParticleAttributeToContainerAttribute[nParticleAttribute];
  if ( (v5 == -1 || v5 == nFieldNumber)
    && ((v6 = this->m_ContainerAttributeToParticleAttribute[nFieldNumber]) == -1 || v6 == nParticleAttribute) )
  {
    this->m_ParticleAttributeToContainerAttribute[nParticleAttribute] = nFieldNumber;
    this->m_ContainerAttributeToParticleAttribute[nFieldNumber] = nParticleAttribute;
    return 1;
  }
  else
  {
    _Warning(a1: "CParticleSnapshot::%s - Invalid attribute mapping specified (must be one-to-one)!\n", pFunc);
    CParticleSnapshot::Purge(this);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052F350
// Name: public: bool CParticleSnapshot::Init(int,int,int,class CUtlVector<struct CParticleSnapshot::AttributeMap,class CUtlMemory<struct CParticleSnapshot::AttributeMap,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CParticleSnapshot::Init(
        CParticleSnapshot *this,
        int nX,
        int nY,
        int nZ,
        const CUtlVector<CParticleSnapshot::AttributeMap,CUtlMemory<CParticleSnapshot::AttributeMap,int> > *attributeMaps)
{
  const CUtlVector<CParticleSnapshot::AttributeMap,CUtlMemory<CParticleSnapshot::AttributeMap,int> > *v5; // ebx
  int v8; // esi
  CParticleSnapshot::AttributeMap *m_pMemory; // eax
  int m_nContainerAttribute; // ebx
  EAttributeDataType ParticleAttributeDataType; // eax
  int nParticleAttribute; // [esp+8h] [ebp-4h]

  v5 = attributeMaps;
  if ( attributeMaps->m_Size <= 0 || nX < 1 || nY < 1 || nZ < 1 )
    return 0;
  CParticleSnapshot::Purge(this);
  v8 = 0;
  this->m_pContainer = &this->m_Container;
  if ( attributeMaps->m_Size > 0 )
  {
    while ( 1 )
    {
      m_pMemory = v5->m_Memory.m_pMemory;
      m_nContainerAttribute = v5->m_Memory.m_pMemory[v8].m_nContainerAttribute;
      nParticleAttribute = m_pMemory[v8].m_nParticleAttribute;
      if ( CParticleSnapshot::AddAttributeMapping(
             this,
             nFieldNumber: m_nContainerAttribute,
             nParticleAttribute,
             pFunc: "Init") == 0 )
        return 0;
      ParticleAttributeDataType = CParticleSystemMgr::GetParticleAttributeDataType(
                                    this: g_pParticleSystemMgr,
                                    nAttribute: nParticleAttribute);
      CSOAContainer::SetAttributeType(
        this: &this->m_Container,
        nAttrIdx: m_nContainerAttribute,
        nDataType: ParticleAttributeDataType,
        bAllocateMemory: true);
      if ( ++v8 >= attributeMaps->m_Size )
        goto LABEL_7;
      v5 = attributeMaps;
    }
  }
  else
  {
LABEL_7:
    CSOAContainer::AllocateData(this: &this->m_Container, nNCols: nX, nNRows: nY, nSlices: nZ);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052F460
// Name: public: class CDmxAttribute __near * CDmxElement::SetValue<int>(char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmxAttribute *__thiscall CDmxElement::SetValue<int>(CDmxElement *this, const char *pAttributeName, const int *value)
{
  CDmxAttribute *v4; // edi
  _DWORD *m_pData; // eax

  CDmxElement::LockForChanges(this, bLock: true);
  v4 = CDmxElement::AddAttribute(this, pAttributeName);
  CDmxAttribute::AllocateDataMemory(this: v4, type: AT_INT);
  m_pData = v4->m_pData;
  if ( m_pData != nullptr )
    *m_pData = *value;
  if ( this != nullptr )
    CDmxElement::LockForChanges(this, bLock: false);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0052F4B0
// Name: public: bool CParticleSnapshot::Serialize(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CParticleSnapshot::Serialize(CParticleSnapshot *this, const char *pFullPath, bool bTextMode)
{
  const char *FileExtension; // eax
  bool v5; // bl
  CDmxElement *DmxElement; // esi
  CDmxElement *v7; // edi
  CDmxElement *pContainerElement; // [esp+8h] [ebp-4h] BYREF

  BeginDMXContext();
  if ( this->m_pContainer == nullptr )
  {
    _Warning(
      a1: "ERROR: CParticleSnapshot::Serialize - cannot serialize an uninitialized CParticleSnapshot! (%s)\n",
      pFullPath);
LABEL_13:
    EndDMXContext(bDecommitMemory: true);
    return false;
  }
  FileExtension = V_GetFileExtension(path: pFullPath);
  if ( FileExtension == nullptr || _V_stricmp(s1: FileExtension, s2: "psf") != 0 )
  {
    _Warning(a1: "ERROR: CParticleSnapshot::Serialize - file extension should be '.psf' (%s)\n", pFullPath);
    goto LABEL_13;
  }
  v5 = true;
  DmxElement = CreateDmxElement(pType: "CDmeElement");
  CDmxElement::LockForChanges(this: DmxElement, bLock: true);
  v7 = CreateDmxElement(pType: "CDmeParticleSnapshot");
  pContainerElement = v7;
  CDmxElement::SetValue<CDmxElement *>(this: DmxElement, pAttributeName: "particle_snapshot", value: &pContainerElement);
  pContainerElement = (CDmxElement *)1;
  CDmxElement::SetValue<int>(this: v7, pAttributeName: "version", value: (const int *)&pContainerElement);
  CDmxElement::AddAttributesFromStructure(this: v7, pData: this, pUnpack: s_pParticleSnapshotUnpack);
  pContainerElement = CreateDmxElement(pType: "CDmeSOAContainer");
  CDmxElement::SetValue<CDmxElement *>(this: v7, pAttributeName: "container", value: &pContainerElement);
  if ( !SerializeCSOAContainer(pContainer: this->m_pContainer, pRootElement: pContainerElement) )
  {
    _Warning(
      a1: "ERROR: CParticleSnapshot::Serialize - error serializing embedded CSOAContainer for file %s\n",
      pFullPath);
    v5 = false;
  }
  if ( DmxElement != nullptr )
    CDmxElement::LockForChanges(this: DmxElement, bLock: false);
  if ( v5 )
    v5 = SerializeDMX(pFileName: pFullPath, pPathID: "GAME", bTextMode, pRoot: DmxElement);
  CleanupDMX(pRoot: DmxElement);
  EndDMXContext(bDecommitMemory: true);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0056D7A0
// Name: CParticleSnapshot_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *CParticleSnapshot_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<CParticleSnapshot>(__formal: nullptr);
  s_pUnpack = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052F260
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class CParticleSnapshot>(class CParticleSnapshot __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<CParticleSnapshot>()
{
  if ( (_S2_3 & 1) == 0 )
  {
    _S2_3 |= 1u;
    dword_5B47D8 = 16;
    dword_5B47DC = 808;
    dword_5B47E0 = 4;
    dword_5B47E4 = -1;
    dword_5B47E8 = 0;
    dword_5B47EC = 0;
    dword_5B47F0 = 0;
    dword_5B47F4 = 0;
    dword_5B47F8 = 24;
    dword_5B47FC = (int)"container_attribute_to_particle_attribute";
    dword_5B4800 = (int)"-1";
    dword_5B4804 = 16;
    dword_5B4808 = 904;
    dword_5B480C = 4;
    dword_5B4810 = -1;
    dword_5B4814 = 0;
    dword_5B4818 = 0;
    dword_5B481C = 0;
    dword_5B4820 = 0;
    dword_5B4824 = 32;
    dword_5B4828 = 0;
    dword_5B482C = 0;
    dword_5B4830 = 0;
    dword_5B4834 = 0;
    dword_5B4838 = 0;
    dword_5B483C = -1;
    dword_5B4840 = 0;
    dword_5B4844 = 0;
    dword_5B4848 = 0;
    dword_5B484C = 0;
    dword_5B4850 = 0;
  }
  return unpack;
}

//------------------------------------------------------------------------------
// Address: 0x0052F620
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<struct ParticleChildrenInfo_t>(struct ParticleChildrenInfo_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<ParticleChildrenInfo_t>()
{
  if ( (_S2_4 & 1) == 0 )
  {
    _S2_4 |= 1u;
    dword_5B8AE8 = 3;
    dword_5B8AEC = 24;
    dword_5B8AF0 = 4;
    dword_5B8AF4 = -1;
    dword_5B8AF8 = 0;
    dword_5B8AFC = 0;
    dword_5B8B00 = 0;
    dword_5B8B04 = 0;
    dword_5B8B08 = 0;
    dword_5B8B0C = (int)"end cap effect";
    dword_5B8B10 = (int)"0";
    dword_5B8B14 = 4;
    dword_5B8B18 = 28;
    dword_5B8B1C = 1;
    dword_5B8B20 = -1;
    dword_5B8B24 = 0;
    dword_5B8B28 = 0;
    dword_5B8B2C = 0;
    dword_5B8B30 = 0;
    dword_5B8B34 = 0;
    dword_5B8B38 = 0;
    dword_5B8B3C = 0;
    dword_5B8B40 = 0;
    dword_5B8B44 = 0;
    dword_5B8B48 = 0;
    dword_5B8B4C = -1;
    dword_5B8B50 = 0;
    dword_5B8B54 = 0;
    dword_5B8B58 = 0;
    dword_5B8B5C = 0;
    dword_5B8B60 = 0;
  }
  return unpack_0;
}

//------------------------------------------------------------------------------
// Address: 0x0052F710
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class CParticleSystemDefinition>(class CParticleSystemDefinition __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<CParticleSystemDefinition>()
{
  if ( (_S3_1 & 1) == 0 )
  {
    _S3_1 |= 1u;
    dword_5B8C24 = 12;
    dword_5B8C50 = 12;
    dword_5B8B98 = 2;
    dword_5B8B9C = 284;
    dword_5B8BA0 = 4;
    dword_5B8BA4 = -1;
    dword_5B8BA8 = 0;
    dword_5B8BAC = 0;
    dword_5B8BB0 = 0;
    dword_5B8BB4 = 0;
    dword_5B8BB8 = 0;
    dword_5B8BBC = (int)"initial_particles";
    dword_5B8BC0 = (int)"0";
    dword_5B8BC4 = 2;
    dword_5B8BC8 = 4;
    dword_5B8BCC = 4;
    dword_5B8BD0 = -1;
    dword_5B8BD4 = 0;
    dword_5B8BD8 = 0;
    dword_5B8BDC = 0;
    dword_5B8BE0 = 0;
    dword_5B8BE4 = 0;
    dword_5B8BE8 = (int)"material";
    dword_5B8BEC = (int)"vgui/white";
    dword_5B8BF0 = 5;
    dword_5B8BF4 = 64;
    dword_5B8BF8 = -1;
    dword_5B8BFC = -1;
    dword_5B8C00 = 0;
    dword_5B8C04 = (int)"vmtPicker";
    dword_5B8C08 = 0;
    dword_5B8C0C = 0;
    dword_5B8C10 = 0;
    dword_5B8C14 = (int)"bounding_box_min";
    dword_5B8C18 = (int)"-10 -10 -10";
    dword_5B8C1C = 10;
    dword_5B8C20 = 40;
    dword_5B8C28 = -1;
    dword_5B8C2C = 0;
    dword_5B8C30 = 0;
    dword_5B8C34 = 0;
    dword_5B8C38 = 0;
    dword_5B8C3C = 0;
    dword_5B8C40 = (int)"bounding_box_max";
    dword_5B8C44 = (int)"10 10 10";
    dword_5B8C48 = 10;
    dword_5B8C4C = 52;
    dword_5B8C54 = -1;
    dword_5B8C58 = 0;
    dword_5B8C5C = 0;
    dword_5B8C60 = 0;
    dword_5B8C64 = 0;
    dword_5B8C68 = 0;
    dword_5B8C6C = (int)"cull_radius";
    dword_5B8C70 = (int)"0";
    dword_5B8C74 = 3;
    dword_5B8C78 = 120;
    dword_5B8C7C = 4;
    dword_5B8C80 = -1;
    dword_5B8C84 = 0;
    dword_5B8C88 = 0;
    dword_5B8C8C = 0;
    dword_5B8C90 = 0;
    dword_5B8C94 = 0;
    dword_5B8C98 = (int)"cull_cost";
    dword_5B8C9C = (int)"1";
    dword_5B8CA0 = 3;
    dword_5B8CA4 = 124;
    dword_5B8CA8 = 4;
    dword_5B8CAC = -1;
    dword_5B8CB0 = 0;
    dword_5B8CB4 = 0;
    dword_5B8CB8 = 0;
    dword_5B8CBC = 0;
    dword_5B8CC0 = 0;
    dword_5B8CC4 = (int)"cull_control_point";
    dword_5B8CC8 = (int)"0";
    dword_5B8CCC = 2;
    dword_5B8CD0 = 128;
    dword_5B8CD4 = 4;
    dword_5B8CD8 = -1;
    dword_5B8CDC = 0;
    dword_5B8CE0 = 0;
    dword_5B8CE4 = 0;
    dword_5B8CE8 = 0;
    dword_5B8CEC = 0;
    dword_5B8CF0 = (int)"cull_replacement_definition";
    dword_5B8CF4 = (int)str;
    dword_5B8CF8 = 5;
    dword_5B8CFC = 104;
    dword_5B8D00 = -1;
    dword_5B8D04 = -1;
    dword_5B8D08 = 0;
    dword_5B8D0C = 0;
    dword_5B8D10 = 0;
    dword_5B8D14 = 0;
    dword_5B8D18 = 0;
    dword_5B8D1C = (int)"fallback replacement definition";
    dword_5B8D20 = (int)str;
    dword_5B8D24 = 5;
    dword_5B8D28 = 144;
    dword_5B8D2C = -1;
    dword_5B8D30 = -1;
    dword_5B8D34 = 0;
    dword_5B8D38 = 0;
    dword_5B8D3C = 0;
    dword_5B8D40 = 0;
    dword_5B8D44 = 0;
    dword_5B8D48 = (int)"fallback max count";
    dword_5B8D4C = (int)"-1";
    dword_5B8D50 = 2;
    dword_5B8D54 = 160;
    dword_5B8D58 = 4;
    dword_5B8D5C = -1;
    dword_5B8D60 = 0;
    dword_5B8D64 = 0;
    dword_5B8D68 = 0;
    dword_5B8D6C = 0;
    dword_5B8D70 = 0;
    dword_5B8D74 = (int)"radius";
    dword_5B8D78 = (int)"5";
    dword_5B8D7C = 3;
    dword_5B8D80 = 196;
    dword_5B8D84 = 4;
    dword_5B8D88 = -1;
    dword_5B8D8C = 0;
    dword_5B8D90 = 0;
    dword_5B8D94 = 0;
    dword_5B8D98 = 0;
    dword_5B8D9C = 0;
    dword_5B8DA0 = (int)"color";
    dword_5B8DA4 = (int)"255 255 255 255";
    dword_5B8DA8 = 8;
    dword_5B8DAC = 180;
    dword_5B8DB0 = 4;
    dword_5B8DB4 = -1;
    dword_5B8DB8 = 0;
    dword_5B8DBC = 0;
    dword_5B8DC0 = 0;
    dword_5B8DC4 = 0;
    dword_5B8DC8 = 0;
    dword_5B8DCC = (int)"rotation";
    dword_5B8DD0 = (int)"0";
    dword_5B8DD4 = 3;
    dword_5B8DD8 = 200;
    dword_5B8DDC = 4;
    dword_5B8DE0 = -1;
    dword_5B8DE4 = 0;
    dword_5B8DE8 = 0;
    dword_5B8DEC = 0;
    dword_5B8DF0 = 0;
    dword_5B8DF4 = 0;
    dword_5B8DF8 = (int)"rotation_speed";
    dword_5B8DFC = (int)"0";
    dword_5B8E00 = 3;
    dword_5B8E04 = 204;
    dword_5B8E08 = 4;
    dword_5B8E0C = -1;
    dword_5B8E10 = 0;
    dword_5B8E14 = 0;
    dword_5B8E18 = 0;
    dword_5B8E1C = 0;
    dword_5B8E20 = 0;
    dword_5B8E24 = (int)"normal";
    dword_5B8E28 = (int)"0 0 1";
    dword_5B8E2C = 10;
    dword_5B8E30 = 184;
    dword_5B8E34 = 12;
    dword_5B8E38 = -1;
    dword_5B8E3C = 0;
    dword_5B8E40 = 0;
    dword_5B8E44 = 0;
    dword_5B8E48 = 0;
    dword_5B8E4C = 0;
    dword_5B8E50 = (int)"sequence_number";
    dword_5B8E54 = (int)"0";
    dword_5B8E58 = 2;
    dword_5B8E5C = 208;
    dword_5B8E60 = 4;
    dword_5B8E64 = -1;
    dword_5B8E68 = 0;
    dword_5B8E6C = (int)"sheetsequencepicker";
    dword_5B8E70 = 0;
    dword_5B8E74 = 0;
    dword_5B8E78 = 0;
    dword_5B8E7C = (int)"sequence_number 1";
    dword_5B8E80 = (int)"0";
    dword_5B8E84 = 2;
    dword_5B8E88 = 212;
    dword_5B8E8C = 4;
    dword_5B8E90 = -1;
    dword_5B8E94 = 0;
    dword_5B8E98 = (int)"sheetsequencepicker_second";
    dword_5B8E9C = 0;
    dword_5B8EA0 = 0;
    dword_5B8EA4 = 0;
    dword_5B8EA8 = (int)"group id";
    dword_5B8EAC = (int)"0";
    dword_5B8EB0 = 2;
    dword_5B8EB4 = 216;
    dword_5B8EB8 = 4;
    dword_5B8EBC = -1;
    dword_5B8EC0 = 0;
    dword_5B8EC4 = 0;
    dword_5B8EC8 = 0;
    dword_5B8ECC = 0;
    dword_5B8ED0 = 0;
    dword_5B8ED4 = (int)"maximum time step";
    dword_5B8ED8 = (int)"0.1";
    dword_5B8EDC = 3;
    dword_5B8EE0 = 220;
    dword_5B8EE4 = 4;
    dword_5B8EE8 = -1;
    dword_5B8EEC = 0;
    dword_5B8EF0 = 0;
    dword_5B8EF4 = 0;
    dword_5B8EF8 = 0;
    dword_5B8EFC = 0;
    dword_5B8F00 = (int)"maximum sim tick rate";
    dword_5B8F04 = (int)"0.0";
    dword_5B8F08 = 3;
    dword_5B8F0C = 224;
    dword_5B8F10 = 4;
    dword_5B8F14 = -1;
    dword_5B8F18 = 0;
    dword_5B8F1C = 0;
    dword_5B8F20 = 0;
    dword_5B8F24 = 0;
    dword_5B8F28 = 0;
    dword_5B8F2C = (int)"minimum sim tick rate";
    dword_5B8F30 = (int)"0.0";
    dword_5B8F34 = 3;
    dword_5B8F38 = 228;
    dword_5B8F3C = 4;
    dword_5B8F40 = -1;
    dword_5B8F44 = 0;
    dword_5B8F48 = 0;
    dword_5B8F4C = 0;
    dword_5B8F50 = 0;
    dword_5B8F54 = 0;
    dword_5B8F58 = (int)"minimum rendered frames";
    dword_5B8F5C = (int)"0";
    dword_5B8F60 = 2;
    dword_5B8F64 = 236;
    dword_5B8F68 = 4;
    dword_5B8F6C = -1;
    dword_5B8F70 = 0;
    dword_5B8F74 = 0;
    dword_5B8F78 = 0;
    dword_5B8F7C = 0;
    dword_5B8F80 = 0;
    dword_5B8F84 = (int)"control point to disable rendering if it is the camera";
    dword_5B8F88 = (int)"-1";
    dword_5B8F8C = 2;
    dword_5B8F90 = 288;
    dword_5B8F94 = 4;
    dword_5B8F98 = -1;
    dword_5B8F9C = 0;
    dword_5B8FA0 = 0;
    dword_5B8FA4 = 0;
    dword_5B8FA8 = 0;
    dword_5B8FAC = 0;
    dword_5B8FB0 = (int)"control point to only enable rendering if it is the camera";
    dword_5B8FB4 = (int)"-1";
    dword_5B8FB8 = 2;
    dword_5B8FBC = 292;
    dword_5B8FC0 = 4;
    dword_5B8FC4 = -1;
    dword_5B8FC8 = 0;
    dword_5B8FCC = 0;
    dword_5B8FD0 = 0;
    dword_5B8FD4 = 0;
    dword_5B8FD8 = 0;
    dword_5B8FDC = (int)"maximum draw distance";
    dword_5B8FE0 = (int)"100000.0";
    dword_5B8FE4 = 3;
    dword_5B8FE8 = 276;
    dword_5B8FEC = 4;
    dword_5B8FF0 = -1;
    dword_5B8FF4 = 0;
    dword_5B8FF8 = 0;
    dword_5B8FFC = 0;
    dword_5B9000 = 0;
    dword_5B9004 = 0;
    dword_5B9008 = (int)"time to sleep when not drawn";
    dword_5B900C = (int)"8";
    dword_5B9010 = 3;
    dword_5B9014 = 280;
    dword_5B9018 = 4;
    dword_5B901C = -1;
    dword_5B9020 = 0;
    dword_5B9024 = 0;
    dword_5B9028 = 0;
    dword_5B902C = 0;
    dword_5B9030 = 0;
    dword_5B9034 = (int)"Sort particles";
    dword_5B9038 = (int)"1";
    dword_5B903C = 4;
    dword_5B9040 = 600;
    dword_5B9044 = 1;
    dword_5B9048 = -1;
    dword_5B904C = 0;
    dword_5B9050 = 0;
    dword_5B9054 = 0;
    dword_5B9058 = 0;
    dword_5B905C = 0;
    dword_5B9060 = (int)"batch particle systems";
    dword_5B9064 = (int)"0";
    dword_5B9068 = 4;
    dword_5B906C = 601;
    dword_5B9070 = 1;
    dword_5B9074 = -1;
    dword_5B9078 = 0;
    dword_5B907C = 0;
    dword_5B9080 = 0;
    dword_5B9084 = 0;
    dword_5B9088 = 0;
    dword_5B908C = (int)"view model effect";
    dword_5B9090 = (int)"0";
    dword_5B9094 = 4;
    dword_5B9098 = 248;
    dword_5B909C = 1;
    dword_5B90A0 = -1;
    dword_5B90A4 = 0;
    dword_5B90A8 = 0;
    dword_5B90AC = 0;
    dword_5B90B0 = 0;
    dword_5B90B4 = 0;
    dword_5B90B8 = (int)"screen space effect";
    dword_5B90BC = (int)"0";
    dword_5B90C0 = 4;
    dword_5B90C4 = 249;
    dword_5B90C8 = 1;
    dword_5B90CC = -1;
    dword_5B90D0 = 0;
    dword_5B90D4 = 0;
    dword_5B90D8 = 0;
    dword_5B90DC = 0;
    dword_5B90E0 = 0;
    dword_5B90E4 = (int)"draw through leafsystem";
    dword_5B90E8 = (int)"1";
    dword_5B90EC = 4;
    dword_5B90F0 = 250;
    dword_5B90F4 = 1;
    dword_5B90F8 = -1;
    dword_5B90FC = 0;
    dword_5B9100 = 0;
    dword_5B9104 = 0;
    dword_5B9108 = 0;
    dword_5B910C = 0;
    dword_5B9110 = (int)"maximum portal recursion depth";
    dword_5B9114 = (int)"8";
    dword_5B9118 = 2;
    dword_5B911C = 136;
    dword_5B9120 = 4;
    dword_5B9124 = -1;
    dword_5B9128 = 0;
    dword_5B912C = 0;
    dword_5B9130 = 0;
    dword_5B9134 = 0;
    dword_5B9138 = 0;
    dword_5B913C = (int)"aggregation radius";
    dword_5B9140 = (int)"0";
    dword_5B9144 = 3;
    dword_5B9148 = 300;
    dword_5B914C = 4;
    dword_5B9150 = -1;
    dword_5B9154 = 0;
    dword_5B9158 = 0;
    dword_5B915C = 0;
    dword_5B9160 = 0;
    dword_5B9164 = 0;
    dword_5B9168 = (int)"minimum free particles to aggregate";
    dword_5B916C = (int)"0";
    dword_5B9170 = 2;
    dword_5B9174 = 296;
    dword_5B9178 = 4;
    dword_5B917C = -1;
    dword_5B9180 = 0;
    dword_5B9184 = 0;
    dword_5B9188 = 0;
    dword_5B918C = 0;
    dword_5B9190 = 0;
    dword_5B9194 = (int)"minimum simulation time step";
    dword_5B9198 = (int)"0";
    dword_5B919C = 3;
    dword_5B91A0 = 232;
    dword_5B91A4 = 4;
    dword_5B91A8 = -1;
    dword_5B91AC = 0;
    dword_5B91B0 = 0;
    dword_5B91B4 = 0;
    dword_5B91B8 = 0;
    dword_5B91BC = 0;
    dword_5B91C8 = 2;
    dword_5B91F4 = 2;
    dword_5B91C4 = (int)"0";
    dword_5B91F0 = (int)"0";
    dword_5B9220 = 3;
    dword_5B91C0 = (int)"minimum CPU level";
    dword_5B91CC = 240;
    dword_5B91D0 = 4;
    dword_5B91D4 = -1;
    dword_5B91D8 = 0;
    dword_5B91DC = 0;
    dword_5B91E0 = 0;
    dword_5B91E4 = 0;
    dword_5B91E8 = 0;
    dword_5B91EC = (int)"minimum GPU level";
    dword_5B91F8 = 244;
    dword_5B91FC = 4;
    dword_5B9200 = -1;
    dword_5B9204 = 0;
    dword_5B9208 = 0;
    dword_5B920C = 0;
    dword_5B9210 = 0;
    dword_5B9214 = 0;
    dword_5B9218 = (int)"freeze simulation after time";
    dword_5B921C = (int)"1000000000";
    dword_5B9224 = 304;
    dword_5B9228 = 4;
    dword_5B922C = -1;
    dword_5B9230 = 0;
    dword_5B9234 = 0;
    dword_5B9238 = 0;
    dword_5B923C = 0;
    dword_5B9240 = 0;
    dword_5B9244 = 0;
    dword_5B9248 = 0;
    dword_5B924C = 0;
    dword_5B9250 = 0;
    dword_5B9254 = 0;
    dword_5B9258 = -1;
    dword_5B925C = 0;
    dword_5B9260 = 0;
    dword_5B9264 = 0;
    dword_5B9268 = 0;
    dword_5B926C = 0;
  }
  return unpack_1;
}

//------------------------------------------------------------------------------
// Address: 0x0056D7B0
// Name: _dynamic_initializer_for__s_pParticleSnapshotUnpack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__s_pParticleSnapshotUnpack__()
{
  s_pParticleSnapshotUnpack = s_pUnpack;
  return s_pUnpack;
}

//------------------------------------------------------------------------------
// Address: 0x0056D7C0
// Name: _dynamic_initializer_for__s_ParticleSystemMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ParticleSystemMgr__()
{
  CParticleSystemMgr::CParticleSystemMgr(this: &s_ParticleSystemMgr);
  return atexit(func: dynamic_atexit_destructor_for__s_ParticleSystemMgr__);
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x102D93C0
// Name: public: void CParticleSnapshot::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSnapshot::Purge(CParticleSnapshot *this)
{
  CSOAContainer::Purge(this: &this->m_Container);
  this->m_pContainer = nullptr;
  this->m_ParticleAttributeToContainerAttribute[0] = -1;
  this->m_ParticleAttributeToContainerAttribute[1] = -1;
  this->m_ParticleAttributeToContainerAttribute[2] = -1;
  this->m_ParticleAttributeToContainerAttribute[3] = -1;
  this->m_ParticleAttributeToContainerAttribute[4] = -1;
  this->m_ParticleAttributeToContainerAttribute[5] = -1;
  this->m_ParticleAttributeToContainerAttribute[6] = -1;
  this->m_ParticleAttributeToContainerAttribute[7] = -1;
  this->m_ParticleAttributeToContainerAttribute[8] = -1;
  this->m_ParticleAttributeToContainerAttribute[9] = -1;
  this->m_ParticleAttributeToContainerAttribute[10] = -1;
  this->m_ParticleAttributeToContainerAttribute[11] = -1;
  this->m_ParticleAttributeToContainerAttribute[12] = -1;
  this->m_ParticleAttributeToContainerAttribute[13] = -1;
  this->m_ParticleAttributeToContainerAttribute[14] = -1;
  this->m_ParticleAttributeToContainerAttribute[15] = -1;
  this->m_ParticleAttributeToContainerAttribute[16] = -1;
  this->m_ParticleAttributeToContainerAttribute[17] = -1;
  this->m_ParticleAttributeToContainerAttribute[18] = -1;
  this->m_ParticleAttributeToContainerAttribute[19] = -1;
  this->m_ParticleAttributeToContainerAttribute[20] = -1;
  this->m_ParticleAttributeToContainerAttribute[21] = -1;
  this->m_ParticleAttributeToContainerAttribute[22] = -1;
  this->m_ParticleAttributeToContainerAttribute[23] = -1;
  this->m_ContainerAttributeToParticleAttribute[0] = -1;
  this->m_ContainerAttributeToParticleAttribute[1] = -1;
  this->m_ContainerAttributeToParticleAttribute[2] = -1;
  this->m_ContainerAttributeToParticleAttribute[3] = -1;
  this->m_ContainerAttributeToParticleAttribute[4] = -1;
  this->m_ContainerAttributeToParticleAttribute[5] = -1;
  this->m_ContainerAttributeToParticleAttribute[6] = -1;
  this->m_ContainerAttributeToParticleAttribute[7] = -1;
  this->m_ContainerAttributeToParticleAttribute[8] = -1;
  this->m_ContainerAttributeToParticleAttribute[9] = -1;
  this->m_ContainerAttributeToParticleAttribute[10] = -1;
  this->m_ContainerAttributeToParticleAttribute[11] = -1;
  this->m_ContainerAttributeToParticleAttribute[12] = -1;
  this->m_ContainerAttributeToParticleAttribute[13] = -1;
  this->m_ContainerAttributeToParticleAttribute[14] = -1;
  this->m_ContainerAttributeToParticleAttribute[15] = -1;
  this->m_ContainerAttributeToParticleAttribute[16] = -1;
  this->m_ContainerAttributeToParticleAttribute[17] = -1;
  this->m_ContainerAttributeToParticleAttribute[18] = -1;
  this->m_ContainerAttributeToParticleAttribute[19] = -1;
  this->m_ContainerAttributeToParticleAttribute[20] = -1;
  this->m_ContainerAttributeToParticleAttribute[21] = -1;
  this->m_ContainerAttributeToParticleAttribute[22] = -1;
  this->m_ContainerAttributeToParticleAttribute[23] = -1;
  this->m_ContainerAttributeToParticleAttribute[24] = -1;
  this->m_ContainerAttributeToParticleAttribute[25] = -1;
  this->m_ContainerAttributeToParticleAttribute[26] = -1;
  this->m_ContainerAttributeToParticleAttribute[27] = -1;
  this->m_ContainerAttributeToParticleAttribute[28] = -1;
  this->m_ContainerAttributeToParticleAttribute[29] = -1;
  this->m_ContainerAttributeToParticleAttribute[30] = -1;
  this->m_ContainerAttributeToParticleAttribute[31] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x102D9530
// Name: private: bool CParticleSnapshot::ValidateAttributeMapping(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CParticleSnapshot::ValidateAttributeMapping(
        CParticleSnapshot *this,
        int nFieldNumber,
        int nParticleAttribute,
        const char *pFunc)
{
  EAttributeDataType ParticleAttributeDataType; // ebx
  CSOAContainer *m_pContainer; // eax
  const char *ParticleAttributeName; // eax

  ParticleAttributeDataType = CParticleSystemMgr::GetParticleAttributeDataType(
                                this: g_pParticleSystemMgr,
                                nAttribute: nParticleAttribute);
  m_pContainer = this->m_pContainer;
  if ( m_pContainer->m_nDataType[nFieldNumber] == ParticleAttributeDataType
    && ((1 << nFieldNumber) & m_pContainer->m_nFieldPresentMask) != 0 )
  {
    return 1;
  }
  _Warning(a1: "CParticleSnapshot::%s - Invalid attribute mapping specified for the provided container!\n", pFunc);
  if ( this->m_pContainer->m_nDataType[nFieldNumber] != ParticleAttributeDataType )
  {
    ParticleAttributeName = CParticleSystemMgr::GetParticleAttributeName(
                              this: g_pParticleSystemMgr,
                              nAttribute: nParticleAttribute);
    _Warning(
      a1: "  (data type of container field %d does not match particle attribute %s)\n",
      nFieldNumber,
      ParticleAttributeName);
  }
  if ( ((1 << nFieldNumber) & this->m_pContainer->m_nFieldPresentMask) == 0 )
    _Warning(a1: "  (container field %d has no allocated data)\n", nFieldNumber);
  CParticleSnapshot::Purge(this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102D96E0
// Name: public: bool CParticleSnapshot::Unserialize(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CParticleSnapshot::Unserialize(CParticleSnapshot *this, char *pFullPath)
{
  const CDmxAttribute *Attribute; // eax
  int *m_pData; // eax
  CDmxElement *v6; // ebx
  const CDmxAttribute *v7; // eax
  int *p_nReverseMaps; // eax
  int v9; // esi
  const CDmxAttribute *v10; // eax
  int *v11; // eax
  unsigned int v12; // esi
  int *m_ParticleAttributeToContainerAttribute; // ebx
  int v14; // eax
  int v15; // ecx
  unsigned int v16; // esi
  int *m_ContainerAttributeToParticleAttribute; // ebx
  int v18; // eax
  int v19; // ecx
  int nReverseMaps; // [esp+Ch] [ebp-10h] BYREF
  int nForwardMaps; // [esp+10h] [ebp-Ch]
  CDmxElement *pRootElement; // [esp+14h] [ebp-8h] BYREF
  bool bSuccess; // [esp+1Bh] [ebp-1h]

  BeginDMXContext();
  pRootElement = nullptr;
  if ( !UnserializeDMX(pFileName: pFullPath, pPathID: "GAME", bTextMode: true, ppRoot: &pRootElement)
    && !UnserializeDMX(pFileName: pFullPath, pPathID: "GAME", bTextMode: false, ppRoot: &pRootElement) )
  {
    _Warning(a1: "ERROR: CParticleSnapshot::Unserialize - could not load file %s!\n", pFullPath);
    EndDMXContext(bDecommitMemory: true);
    return false;
  }
  bSuccess = true;
  Attribute = CDmxElement::GetAttribute(this: pRootElement, pAttributeName: "particle_snapshot");
  if ( Attribute != nullptr )
  {
    if ( Attribute->m_Type == AT_FIRST_VALUE_TYPE )
    {
      m_pData = (int *)Attribute->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<CDmxElement *>'::`4'::defaultValue = 0;
      m_pData = &`CDmxAttribute::GetValue<CDmxElement *>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<CDmxElement *>'::`4'::defaultValue = 0;
    m_pData = &`CDmxElement::GetValue<CDmxElement *>'::`4'::defaultValue;
  }
  v6 = (CDmxElement *)*m_pData;
  if ( *m_pData == 0 )
  {
    _Warning(a1: "ERROR: CParticleSnapshot::Unserialize - %s is not a particle snapshot (.psf) file!\n", pFullPath);
    bSuccess = false;
LABEL_48:
    CParticleSnapshot::Purge(this);
    goto LABEL_49;
  }
  nReverseMaps = -1;
  v7 = CDmxElement::GetAttribute(this: v6, pAttributeName: "version");
  if ( v7 != nullptr )
  {
    if ( v7->m_Type == AT_INT )
    {
      p_nReverseMaps = (int *)v7->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<int>'::`4'::defaultValue = 0;
      p_nReverseMaps = &`CDmxAttribute::GetValue<int>'::`4'::defaultValue;
    }
  }
  else
  {
    p_nReverseMaps = &nReverseMaps;
  }
  v9 = *p_nReverseMaps;
  if ( *p_nReverseMaps == -1 )
  {
    _Warning(a1: "ERROR: CParticleSnapshot::Unserialize - missing version field in file %s\n", pFullPath);
    bSuccess = false;
    goto LABEL_48;
  }
  CParticleSnapshot::Purge(this);
  CDmxElement::UnpackIntoStructure(this: v6, pData: this, pUnpack: s_pParticleSnapshotUnpack);
  v10 = CDmxElement::GetAttribute(this: v6, pAttributeName: "container");
  if ( v10 != nullptr )
  {
    if ( v10->m_Type == AT_FIRST_VALUE_TYPE )
    {
      v11 = (int *)v10->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<CDmxElement *>'::`4'::defaultValue = 0;
      v11 = &`CDmxAttribute::GetValue<CDmxElement *>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<CDmxElement *>'::`4'::defaultValue = 0;
    v11 = &`CDmxElement::GetValue<CDmxElement *>'::`4'::defaultValue;
  }
  if ( !UnserializeCSOAContainer(
          pContainer: (CSOAContainer_Serializable *)this,
          pRootElement: (const CDmxElement *)*v11) )
  {
    _Warning(a1: "ERROR: CParticleSnapshot::Unserialize - error reading embedded CSOAContainer in file %s\n", pFullPath);
    bSuccess = false;
    goto LABEL_48;
  }
  if ( v9 != 1 )
  {
    bSuccess = false;
    goto LABEL_48;
  }
  nForwardMaps = 0;
  nReverseMaps = 0;
  this->m_pContainer = &this->m_Container;
  v12 = 0;
  m_ParticleAttributeToContainerAttribute = this->m_ParticleAttributeToContainerAttribute;
  while ( 1 )
  {
    v14 = *m_ParticleAttributeToContainerAttribute;
    if ( *m_ParticleAttributeToContainerAttribute != -1 )
    {
      v15 = this->m_ContainerAttributeToParticleAttribute[v14];
      if ( v15 != -1 && v15 != v12 )
        break;
      this->m_ContainerAttributeToParticleAttribute[v14] = v12;
      if ( CParticleSnapshot::ValidateAttributeMapping(
             this,
             nFieldNumber: v14,
             nParticleAttribute: v12,
             pFunc: "Unserialize") == 0 )
        goto LABEL_36;
      ++nForwardMaps;
    }
    ++v12;
    ++m_ParticleAttributeToContainerAttribute;
    if ( v12 >= 0x18 )
      goto LABEL_37;
  }
  _Warning(a1: "CParticleSnapshot::%s - Invalid attribute mapping specified (must be one-to-one)!\n", "Unserialize");
  CParticleSnapshot::Purge(this);
LABEL_36:
  bSuccess = false;
LABEL_37:
  v16 = 0;
  m_ContainerAttributeToParticleAttribute = this->m_ContainerAttributeToParticleAttribute;
  do
  {
    v18 = *m_ContainerAttributeToParticleAttribute;
    if ( *m_ContainerAttributeToParticleAttribute != -1 )
    {
      v19 = this->m_ParticleAttributeToContainerAttribute[v18];
      if ( v19 != -1 && v19 != v16 )
      {
        _Warning(
          a1: "CParticleSnapshot::%s - Invalid attribute mapping specified (must be one-to-one)!\n",
          "Unserialize");
        CParticleSnapshot::Purge(this);
LABEL_51:
        bSuccess = false;
        goto LABEL_48;
      }
      this->m_ParticleAttributeToContainerAttribute[v18] = v16;
      *m_ContainerAttributeToParticleAttribute = v18;
      if ( CParticleSnapshot::ValidateAttributeMapping(
             this,
             nFieldNumber: v16,
             nParticleAttribute: v18,
             pFunc: "Unserialize") == 0 )
        goto LABEL_51;
      ++nReverseMaps;
    }
    ++v16;
    ++m_ContainerAttributeToParticleAttribute;
  }
  while ( v16 < 0x20 );
  if ( !bSuccess )
    goto LABEL_48;
  if ( nForwardMaps == 0 || nReverseMaps == 0 )
  {
    bSuccess = false;
    _Warning(
      a1: "ERROR: CParticleSnapshot::Unserialize - error in data in file %s (no attribute mapping specified)\n",
      pFullPath);
    goto LABEL_48;
  }
LABEL_49:
  CleanupDMX(pRoot: pRootElement);
  EndDMXContext(bDecommitMemory: true);
  return bSuccess;
}

//------------------------------------------------------------------------------
// Address: 0x1042D850
// Name: CParticleSnapshot_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *CParticleSnapshot_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<CParticleSnapshot>();
  s_pUnpack_1 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102D95F0
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class CParticleSnapshot>(class CParticleSnapshot __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<CParticleSnapshot>()
{
  if ( (_S2_3 & 1) == 0 )
  {
    _S2_3 |= 1u;
    dword_105BEE30 = 16;
    dword_105BEE34 = 808;
    dword_105BEE38 = 4;
    dword_105BEE3C = -1;
    dword_105BEE40 = 0;
    dword_105BEE44 = 0;
    dword_105BEE48 = 0;
    dword_105BEE4C = 0;
    dword_105BEE50 = 24;
    dword_105BEE54 = (int)"container_attribute_to_particle_attribute";
    dword_105BEE58 = (int)"-1";
    dword_105BEE5C = 16;
    dword_105BEE60 = 904;
    dword_105BEE64 = 4;
    dword_105BEE68 = -1;
    dword_105BEE6C = 0;
    dword_105BEE70 = 0;
    dword_105BEE74 = 0;
    dword_105BEE78 = 0;
    dword_105BEE7C = 32;
    dword_105BEE80 = 0;
    dword_105BEE84 = 0;
    dword_105BEE88 = 0;
    dword_105BEE8C = 0;
    dword_105BEE90 = 0;
    dword_105BEE94 = -1;
    dword_105BEE98 = 0;
    dword_105BEE9C = 0;
    dword_105BEEA0 = 0;
    dword_105BEEA4 = 0;
    dword_105BEEA8 = 0;
  }
  return unpack_1;
}

//------------------------------------------------------------------------------
// Address: 0x1042D860
// Name: _dynamic_initializer_for__s_pParticleSnapshotUnpack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__s_pParticleSnapshotUnpack__()
{
  s_pParticleSnapshotUnpack = s_pUnpack_1;
  return s_pUnpack_1;
}

} // namespace client
