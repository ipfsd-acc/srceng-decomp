// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/editgameclass.cpp
// Functions: 31
// ============================================================

#include "hammer\editgameclass.h"

//------------------------------------------------------------------------------
// Address: 0x1002EC80
// Name: public: char const __near * GDinputvariable::GetName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall GDinputvariable::GetName(GDinputvariable *this)
{
  return this->m_szName;
}

//------------------------------------------------------------------------------
// Address: 0x1002EC90
// Name: public: int GDclass::GetVariableCount(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall GDclass::GetVariableCount(vgui::BuildGroup *this)
{
  return this->m_pBuildContext;
}

//------------------------------------------------------------------------------
// Address: 0x1002ECA0
// Name: public: MDkeyvalue::MDkeyvalue(void)
// Source: json
//------------------------------------------------------------------------------
MDkeyvalue *__thiscall MDkeyvalue::MDkeyvalue(MDkeyvalue *this)
{
  this->szKey[0] = 0;
  this->szValue[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002ECB0
// Name: public: void CEditGameClass::SetComments(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGameClass::SetComments(CEditGameClass *this, const char *pszComments)
{
  unsigned int v3; // eax
  char *v4; // eax
  const char *v5; // ecx
  char *v6; // edx
  char v7; // al

  operator delete(p: this->m_pszComments);
  if ( pszComments != nullptr && (v3 = strlen(pszComments)) != 0 )
  {
    v4 = (char *)operator new[](nSize: v3 + 1);
    this->m_pszComments = v4;
    v5 = pszComments;
    v6 = v4;
    do
    {
      v7 = *v5;
      *v6++ = *v5++;
    }
    while ( v7 != 0 );
  }
  else
  {
    this->m_pszComments = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002ED10
// Name: public: virtual void CEditGameClass::SetClass(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGameClass::SetClass(CEditGameClass *this, const char *pszClass, bool bLoading)
{
  const char *v3; // eax
  char *m_szClass; // esi
  int v6; // edx
  char v7; // cl

  v3 = pszClass;
  m_szClass = this->m_szClass;
  v6 = this->m_szClass - pszClass;
  do
  {
    v7 = *v3;
    v3[v6] = *v3;
    ++v3;
  }
  while ( v7 != 0 );
  StripEdgeWhiteSpace(psz: m_szClass);
  if ( pGD != nullptr )
    this->m_pClass = GameData::ClassForName(this: pGD, pszName: m_szClass, piIndex: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1002ED50
// Name: public: void CEditGameClass::GetDefaultKeys(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGameClass::GetDefaultKeys(CEditGameClass *this)
{
  GDclass *m_pClass; // eax
  int v3; // ebx
  GDinputvariable *VariableAt; // esi
  MDkeyvalue tmpkv; // [esp+4h] [ebp-264h] BYREF
  int iIndex; // [esp+254h] [ebp-14h] BYREF
  int nVariableCount; // [esp+258h] [ebp-10h]
  int v8; // [esp+264h] [ebp-4h]

  m_pClass = this->m_pClass;
  if ( m_pClass != nullptr )
  {
    v3 = 0;
    nVariableCount = m_pClass->m_nVariables;
    if ( nVariableCount > 0 )
    {
      do
      {
        VariableAt = GDclass::GetVariableAt(this: this->m_pClass, iIndex: v3);
        if ( VariableAt != nullptr
          && WCKeyValuesT<WCKVBase_Dict>::GetValue(
               this: &this->m_KeyValues,
               pszKey: VariableAt->m_szName,
               piIndex: &iIndex) == nullptr )
        {
          tmpkv.szKey[0] = 0;
          tmpkv.szValue[0] = 0;
          v8 = 0;
          GDinputvariable::ResetDefaults(this: VariableAt);
          GDinputvariable::ToKeyValue(this: VariableAt, pkv: &tmpkv);
          if ( tmpkv.szKey[0] != 0 && tmpkv.szValue[0] != 0 && _V_stricmp(s1: tmpkv.szValue, s2: "0") != 0 )
            this->SetKeyValue(this, a2: (const char *)&tmpkv, a3: tmpkv.szValue);
          v8 = -1;
          CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)&tmpkv);
        }
        ++v3;
      }
      while ( v3 < nVariableCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EE50
// Name: public: virtual void CEditGameClass::GetAngles(class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGameClass::GetAngles(CEditGameClass *this, QAngle *vecAngles)
{
  const char *Value; // eax

  *vecAngles = vec3_angle;
  Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_KeyValues, pszKey: "angles", piIndex: nullptr);
  if ( Value != nullptr )
    sscanf(string: Value, format: "%f %f %f", vecAngles, &vecAngles->y, &vecAngles->z);
}

//------------------------------------------------------------------------------
// Address: 0x1002EEB0
// Name: public: void CEditGameClass::ImportAngle(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGameClass::ImportAngle(CEditGameClass *this, int nAngle)
{
  void (__thiscall *SetAngles)(CEditGameClass *, const QAngle *); // eax
  void (__thiscall *v3)(CEditGameClass *, const QAngle *); // eax
  QAngle vecAngles; // [esp+0h] [ebp-Ch] BYREF

  memset(&vecAngles, 0, sizeof(vecAngles));
  if ( nAngle == -1 )
  {
    SetAngles = this->SetAngles;
    vecAngles.x = -90.0;
    SetAngles(this, a2: &vecAngles);
  }
  else
  {
    v3 = this->SetAngles;
    if ( nAngle == -2 )
      vecAngles.x = 90.0;
    else
      vecAngles.y = (float)nAngle;
    v3(this, a2: &vecAngles);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EF30
// Name: public: virtual void CEditGameClass::SetAngles(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CEditGameClass::SetAngles(CEditGameClass *this@<ecx>, int a2@<esi>, const QAngle *vecAngles)
{
  char string[28]; // [esp+1Ch] [ebp-50h] BYREF

  sprintf(string, format: "%g %g %g", vecAngles->x, vecAngles->y, vecAngles->z);
  ((void (__thiscall *)(CEditGameClass *, const char *, char *, int))this->SetKeyValue)(
    a1: this,
    a2: "angles",
    a3: string,
    a4: a2);
}

//------------------------------------------------------------------------------
// Address: 0x1002EFA0
// Name: public: unsigned long CEditGameClass::GetSpawnFlags(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CEditGameClass::GetSpawnFlags(CEditGameClass *this)
{
  const char *result; // eax
  unsigned int val; // [esp+0h] [ebp-4h] BYREF

  val = (unsigned int)this;
  result = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_KeyValues, pszKey: "spawnflags", piIndex: nullptr);
  if ( result != nullptr )
  {
    val = 0;
    sscanf(string: result, format: "%lu", &val);
    return (const char *)val;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002EFE0
// Name: public: bool CEditGameClass::GetSpawnFlag(unsigned long)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEditGameClass::GetSpawnFlag(CEditGameClass *this, unsigned int nFlags)
{
  const char *Value; // eax
  CEditGameClass *v4; // [esp+0h] [ebp-4h] BYREF

  v4 = this;
  Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_KeyValues, pszKey: "spawnflags", piIndex: nullptr);
  if ( Value == nullptr )
    return false;
  v4 = nullptr;
  sscanf(string: Value, format: "%lu", &v4);
  return (nFlags & (unsigned int)v4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002F040
// Name: public: void CEditGameClass::SetSpawnFlags(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGameClass::SetSpawnFlags(CEditGameClass *this, unsigned int nSpawnFlags)
{
  char szValue[80]; // [esp+8h] [ebp-50h] BYREF

  V_snprintf(pDest: szValue, maxLen: 80, pFormat: "%lu", nSpawnFlags);
  WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &this->m_KeyValues, pszKey: "spawnflags", iValue: nSpawnFlags);
}

//------------------------------------------------------------------------------
// Address: 0x1002F080
// Name: public: void CEditGameClass::SetSpawnFlag(unsigned long,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGameClass::SetSpawnFlag(CEditGameClass *this, unsigned int nFlags, bool bSet)
{
  WCKeyValuesT<WCKVBase_Dict> *p_m_KeyValues; // edi
  const char *Value; // eax
  int v5; // esi
  unsigned int v6; // esi
  char pDest[80]; // [esp+8h] [ebp-54h] BYREF
  int v8; // [esp+58h] [ebp-4h] BYREF

  p_m_KeyValues = &this->m_KeyValues;
  Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &this->m_KeyValues, pszKey: "spawnflags", piIndex: nullptr);
  if ( Value != nullptr )
  {
    v8 = 0;
    sscanf(string: Value, format: "%lu", &v8);
    v5 = v8;
  }
  else
  {
    v5 = 0;
  }
  if ( bSet )
    v6 = nFlags | v5;
  else
    v6 = ~nFlags & v5;
  V_snprintf(pDest, maxLen: 80, pFormat: "%lu", v6);
  WCKeyValuesT<WCKVBase_Dict>::SetValue(this: p_m_KeyValues, pszKey: "spawnflags", iValue: v6);
}

//------------------------------------------------------------------------------
// Address: 0x1002F1A0
// Name: public: void CEditGameClass::Connections_RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGameClass::Connections_RemoveAll(CEditGameClass *this)
{
  int m_Size; // eax
  int v3; // esi
  CEntityConnection **m_pMemory; // ecx
  CEntityConnection *v5; // edi
  int nConnectionsCount; // [esp+8h] [ebp-4h]

  m_Size = this->m_Connections.m_Size;
  v3 = 0;
  nConnectionsCount = m_Size;
  if ( m_Size <= 0 )
  {
    this->m_Connections.m_Size = 0;
  }
  else
  {
    do
    {
      m_pMemory = this->m_Connections.m_Memory.m_pMemory;
      v5 = m_pMemory[v3];
      if ( v5 != nullptr )
      {
        CEntityConnection::~CEntityConnection(this: m_pMemory[v3]);
        operator delete(p: v5);
        m_Size = nConnectionsCount;
      }
      ++v3;
    }
    while ( v3 < m_Size );
    this->m_Connections.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F1F0
// Name: public: void CEditGameClass::Upstream_FixBad(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGameClass::Upstream_FixBad(CEditGameClass *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_Upstream.m_Size;
  for ( i = 0; i < m_Size; ++i )
    CEntityConnection::LinkTargetEntities(this: this->m_Upstream.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x1002F280
// Name: public: bool CEditGameClass::Connections_Remove(class CEntityConnection __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEditGameClass::Connections_Remove(CEditGameClass *this, CEntityConnection *pConnection)
{
  int m_Size; // edx
  int v4; // eax
  CEntityConnection **i; // ecx

  m_Size = this->m_Connections.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  for ( i = this->m_Connections.m_Memory.m_pMemory; *i != pConnection; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  if ( m_Size - v4 - 1 > 0 )
    _V_memmove(
      dest: &this->m_Connections.m_Memory.m_pMemory[v4],
      src: &this->m_Connections.m_Memory.m_pMemory[v4 + 1],
      count: 4 * (m_Size - v4 - 1));
  --this->m_Connections.m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002F2E0
// Name: public: bool CEditGameClass::Upstream_Remove(class CEntityConnection __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEditGameClass::Upstream_Remove(CEditGameClass *this, CEntityConnection *pConnection)
{
  int m_Size; // edx
  int v4; // eax
  CEntityConnection **i; // ecx

  m_Size = this->m_Upstream.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  for ( i = this->m_Upstream.m_Memory.m_pMemory; *i != pConnection; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  if ( m_Size - v4 - 1 > 0 )
    _V_memmove(
      dest: &this->m_Upstream.m_Memory.m_pMemory[v4],
      src: &this->m_Upstream.m_Memory.m_pMemory[v4 + 1],
      count: 4 * (m_Size - v4 - 1));
  --this->m_Upstream.m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002F690
// Name: public: static int WCKVBase_Dict::GetInvalidIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl WCKVBase_Dict::GetInvalidIndex()
{
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1002F6A0
// Name: public: CEditGameClass::CEditGameClass(void)
// Source: json
//------------------------------------------------------------------------------
CEditGameClass *__thiscall CEditGameClass::CEditGameClass(CEditGameClass *this)
{
  CEntityConnection **m_pMemory; // edx
  CEntityConnection **v3; // edx

  this->__vftable = (CEditGameClass_vtbl *)&CEditGameClass::`vftable';
  WCKeyValuesT<WCKVBase_Dict>::WCKeyValuesT<WCKVBase_Dict>(this: &this->m_KeyValues);
  this->m_Connections.m_Memory.m_pMemory = nullptr;
  this->m_Connections.m_Memory.m_nAllocationCount = 0;
  this->m_Connections.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_Connections.m_Memory.m_pMemory;
  this->m_Connections.m_Size = 0;
  this->m_Connections.m_pElements = m_pMemory;
  this->m_Upstream.m_Memory.m_pMemory = nullptr;
  this->m_Upstream.m_Memory.m_nAllocationCount = 0;
  this->m_Upstream.m_Memory.m_nGrowSize = 0;
  v3 = this->m_Upstream.m_Memory.m_pMemory;
  this->m_Upstream.m_Size = 0;
  this->m_Upstream.m_pElements = v3;
  this->m_pClass = nullptr;
  this->m_szClass[0] = 0;
  this->m_pszComments = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002F740
// Name: public: virtual void CEditGameClass::SetKeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGameClass::SetKeyValue(CEditGameClass *this, const char *pszKey, const char *pszValue)
{
  WCKeyValuesT<WCKVBase_Dict>::SetValue(this: &this->m_KeyValues, pszKey, pszValue);
}

//------------------------------------------------------------------------------
// Address: 0x1002F750
// Name: public: virtual void CEditGameClass::DeleteKeyValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGameClass::DeleteKeyValue(CEditGameClass *this, const char *pszKey)
{
  WCKeyValuesT<WCKVBase_Dict>::RemoveKey(this: &this->m_KeyValues, pszKey);
}

//------------------------------------------------------------------------------
// Address: 0x1002F760
// Name: public: CEditGameClass::~CEditGameClass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGameClass::~CEditGameClass(CEditGameClass *this)
{
  CUtlVector<CEntityConnection *,CUtlMemory<CEntityConnection *,int> > *p_m_Upstream; // esi
  CUtlVector<CEntityConnection *,CUtlMemory<CEntityConnection *,int> > *p_m_Connections; // esi

  this->__vftable = (CEditGameClass_vtbl *)&CEditGameClass::`vftable';
  operator delete(p: this->m_pszComments);
  CEditGameClass::Connections_RemoveAll(this);
  p_m_Upstream = &this->m_Upstream;
  this->m_Upstream.m_Size = 0;
  this->m_Upstream.m_Size = 0;
  if ( this->m_Upstream.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Upstream->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Upstream->m_Memory.m_pMemory);
      p_m_Upstream->m_Memory.m_pMemory = nullptr;
    }
    this->m_Upstream.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Upstream.m_pElements = this->m_Upstream.m_Memory.m_pMemory;
  if ( this->m_Upstream.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Upstream->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Upstream->m_Memory.m_pMemory);
      p_m_Upstream->m_Memory.m_pMemory = nullptr;
    }
    this->m_Upstream.m_Memory.m_nAllocationCount = 0;
  }
  p_m_Connections = &this->m_Connections;
  this->m_Connections.m_Size = 0;
  if ( this->m_Connections.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Connections->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Connections->m_Memory.m_pMemory);
      p_m_Connections->m_Memory.m_pMemory = nullptr;
    }
    this->m_Connections.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Connections.m_pElements = this->m_Connections.m_Memory.m_pMemory;
  if ( this->m_Connections.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Connections->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_Connections->m_Memory.m_pMemory);
      p_m_Connections->m_Memory.m_pMemory = nullptr;
    }
    this->m_Connections.m_Memory.m_nAllocationCount = 0;
  }
  WCKeyValuesT<WCKVBase_Dict>::~WCKeyValuesT<WCKVBase_Dict>(this: &this->m_KeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x1002F860
// Name: public: void CEditGameClass::Connections_FixBad(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGameClass::Connections_FixBad(CEditGameClass *this, bool bRelink)
{
  int v2; // esi
  CEntityConnection *v3; // ebx
  CUtlReferenceVector<CMapEntity> *m_pTargetEntityList; // edx
  int v5; // edi
  CMapEntity *m_pObject; // esi
  int m_Size; // edx
  int v8; // eax
  CEntityConnection **m_pMemory; // ecx
  int nConnectionsCount; // [esp+4h] [ebp-14h]
  int nEntityCount; // [esp+8h] [ebp-10h]
  CUtlReferenceVector<CMapEntity> *pTargetEntities; // [esp+Ch] [ebp-Ch]
  CEditGameClass *v13; // [esp+10h] [ebp-8h]
  int nConnections; // [esp+14h] [ebp-4h]

  v2 = 0;
  v13 = this;
  nConnectionsCount = this->m_Connections.m_Size;
  nConnections = 0;
  if ( nConnectionsCount > 0 )
  {
    while ( 1 )
    {
      v3 = this->m_Connections.m_Memory.m_pMemory[v2];
      m_pTargetEntityList = v3->m_pTargetEntityList;
      v5 = 0;
      pTargetEntities = m_pTargetEntityList;
      nEntityCount = m_pTargetEntityList->m_Size;
      if ( nEntityCount > 0 )
      {
        while ( 1 )
        {
          m_pObject = m_pTargetEntityList->m_Memory.m_pMemory[v5 >> (*((int *)&m_pTargetEntityList->m_Memory + 2) >> 27)][v5 & ((32 * *((_DWORD *)&m_pTargetEntityList->m_Memory + 2)) >> 5)].m_pObject;
          if ( m_pObject != nullptr )
          {
            m_Size = m_pObject->m_Upstream.m_Size;
            v8 = 0;
            if ( m_Size > 0 )
            {
              m_pMemory = m_pObject->m_Upstream.m_Memory.m_pMemory;
              while ( *m_pMemory != v3 )
              {
                ++v8;
                ++m_pMemory;
                if ( v8 >= m_Size )
                  goto LABEL_17;
              }
              if ( v8 != -1 )
              {
                if ( m_Size - v8 - 1 > 0 )
                  _V_memmove(
                    dest: &m_pObject->m_Upstream.m_Memory.m_pMemory[v8],
                    src: &m_pObject->m_Upstream.m_Memory.m_pMemory[v8 + 1],
                    count: 4 * (m_Size - v8 - 1));
                --m_pObject->m_Upstream.m_Size;
              }
            }
          }
LABEL_17:
          if ( ++v5 >= nEntityCount )
            break;
          m_pTargetEntityList = pTargetEntities;
        }
        v2 = nConnections;
      }
      if ( bRelink )
        CEntityConnection::LinkTargetEntities(this: v3);
      nConnections = ++v2;
      if ( v2 >= nConnectionsCount )
        break;
      this = v13;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F950
// Name: public: void CEditGameClass::Connections_Add(class CEntityConnection __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGameClass::Connections_Add(CEditGameClass *this, CEntityConnection *pConnection)
{
  CUtlMemory<CCullTreeNode *,int> *p_m_Connections; // esi
  int m_Size; // ecx
  int v4; // eax
  CEntityConnection **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CCullTreeNode **v8; // ecx
  int v9; // eax
  CCullTreeNode **v10; // eax

  p_m_Connections = (CUtlMemory<CCullTreeNode *,int> *)&this->m_Connections;
  m_Size = this->m_Connections.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (CEntityConnection **)p_m_Connections->m_pMemory;
  while ( *m_pMemory != pConnection )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_Connections->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CVisGroup *,int>::Grow(this: p_m_Connections, num: m_Size - m_nAllocationCount + 1);
    ++p_m_Connections[1].m_pMemory;
    v8 = p_m_Connections->m_pMemory;
    v9 = (int)p_m_Connections[1].m_pMemory - v7 - 1;
    p_m_Connections[1].m_nAllocationCount = (int)p_m_Connections->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_Connections->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (CCullTreeNode *)pConnection;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F9D0
// Name: public: static enum ChunkFileResult_t CEditGameClass::LoadKeyCallback(char const __near *,char const __near *,class CEditGameClass __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CEditGameClass::LoadKeyCallback(
        const char *szKey,
        char *szValue,
        CEditGameClass *pEditGameClass)
{
  CEntityConnection *v3; // eax
  CEntityConnection *v4; // esi
  const char *Value; // eax
  char v6; // bl
  int v7; // eax
  unsigned __int8 v8; // al
  char *v9; // esi
  char *v10; // ecx
  unsigned __int8 *v11; // ebx
  bool v12; // zf
  unsigned __int8 v13; // al
  unsigned __int8 *v14; // esi
  char *v15; // edi
  unsigned __int8 *v16; // ebx
  unsigned __int8 v17; // al
  unsigned __int8 *v18; // esi
  char *v19; // edi
  unsigned __int8 *v20; // ebx
  CEntityConnection *v21; // edi
  unsigned __int8 v22; // al
  char v23; // dl
  unsigned __int8 *v24; // esi
  char *v25; // ecx
  unsigned __int8 v26; // cl
  unsigned __int8 *v27; // eax
  char *v28; // ebx
  int v29; // ebx
  char szToken[260]; // [esp+Ch] [ebp-11Ch] BYREF
  void *p; // [esp+110h] [ebp-18h]
  CEntityConnection *pConnection; // [esp+114h] [ebp-14h]
  char chDelim; // [esp+11Bh] [ebp-Dh]
  int v35; // [esp+124h] [ebp-4h]

  v3 = (CEntityConnection *)operator new(nSize: 0x510u);
  p = v3;
  v35 = 0;
  if ( v3 != nullptr )
  {
    v4 = CEntityConnection::CEntityConnection(this: v3);
    pConnection = v4;
  }
  else
  {
    pConnection = nullptr;
    v4 = nullptr;
  }
  v35 = -1;
  Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(
            this: &pEditGameClass->m_KeyValues,
            pszKey: "targetname",
            piIndex: nullptr);
  CEntityConnection::SetSourceName(this: v4, pszName: Value);
  lstrcpynA(lpString1: v4->m_szOutput, lpString2: szKey, iMaxLength: 256);
  v6 = 27;
  chDelim = 27;
  strchr(string: (unsigned __int8 *)szValue, chr: 0x1Bu);
  if ( v7 == 0 )
  {
    chDelim = 44;
    v6 = 44;
  }
  v8 = *szValue;
  v9 = szValue;
  v10 = szToken;
  if ( *szValue != 0 )
  {
    if ( v8 != v6 )
    {
      do
      {
        if ( v8 == 0 )
          break;
        v8 = *++v9;
      }
      while ( v8 != v6 );
      if ( szValue < v9 )
      {
        memcpy(dst: (unsigned __int8 *)szToken, src: (unsigned __int8 *)szValue, count: v9 - szValue);
        v10 = &szToken[v9 - szValue];
      }
    }
    v12 = *v9 == 0;
    *v10 = 0;
    v11 = (unsigned __int8 *)v9;
    if ( !v12 )
      v11 = (unsigned __int8 *)(v9 + 1);
  }
  else
  {
    v11 = nullptr;
  }
  if ( szToken[0] != 0 )
    CEntityConnection::SetTargetName(this: pConnection, pszName: szToken);
  v13 = *v11;
  v14 = v11;
  v15 = szToken;
  if ( *v11 != 0 )
  {
    if ( v13 != chDelim )
    {
      do
      {
        if ( v13 == 0 )
          break;
        v13 = *++v14;
      }
      while ( v13 != chDelim );
      if ( v11 < v14 )
      {
        memcpy(dst: (unsigned __int8 *)szToken, src: v11, count: v14 - v11);
        v15 = &szToken[v14 - v11];
      }
    }
    v12 = *v14 == 0;
    *v15 = 0;
    v16 = v14;
    if ( !v12 )
      v16 = v14 + 1;
  }
  else
  {
    v16 = nullptr;
  }
  if ( szToken[0] != 0 )
    lstrcpynA(lpString1: pConnection->m_szInput, lpString2: szToken, iMaxLength: 256);
  v17 = *v16;
  v18 = v16;
  v19 = szToken;
  if ( *v16 != 0 )
  {
    if ( v17 != chDelim )
    {
      do
      {
        if ( v17 == 0 )
          break;
        v17 = *++v18;
      }
      while ( v17 != chDelim );
      if ( v16 < v18 )
      {
        memcpy(dst: (unsigned __int8 *)szToken, src: v16, count: v18 - v16);
        v19 = &szToken[v18 - v16];
      }
    }
    v12 = *v18 == 0;
    *v19 = 0;
    v20 = v18;
    if ( !v12 )
      v20 = v18 + 1;
  }
  else
  {
    v20 = nullptr;
  }
  v21 = pConnection;
  if ( szToken[0] != 0 )
    lstrcpynA(lpString1: pConnection->m_szParam, lpString2: szToken, iMaxLength: 256);
  v22 = *v20;
  v23 = chDelim;
  v24 = v20;
  v25 = szToken;
  if ( *v20 != 0 )
  {
    if ( v22 != chDelim )
    {
      do
      {
        if ( v22 == 0 )
          break;
        v22 = *++v24;
      }
      while ( v22 != chDelim );
      if ( v20 < v24 )
      {
        memcpy(dst: (unsigned __int8 *)szToken, src: v20, count: v24 - v20);
        v23 = chDelim;
        v25 = &szToken[v24 - v20];
        v21 = pConnection;
      }
    }
    v12 = *v24 == 0;
    *v25 = 0;
    if ( !v12 )
      ++v24;
  }
  else
  {
    v24 = nullptr;
  }
  if ( szToken[0] != 0 )
  {
    v21->m_fDelay = atof(nptr: szToken);
    v23 = chDelim;
  }
  v26 = *v24;
  v27 = v24;
  v28 = szToken;
  if ( *v24 != 0 )
  {
    if ( v26 != v23 )
    {
      do
      {
        if ( v26 == 0 )
          break;
        v26 = *++v27;
      }
      while ( v26 != v23 );
      if ( v24 < v27 )
      {
        v29 = v27 - v24;
        memcpy(dst: (unsigned __int8 *)szToken, src: v24, count: v27 - v24);
        v28 = &szToken[v29];
      }
    }
    *v28 = 0;
  }
  if ( szToken[0] != 0 )
    v21->m_nTimesToFire = atoi(nptr: szToken);
  CEditGameClass::Connections_Add(this: pEditGameClass, pConnection: v21);
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x1002FCC0
// Name: public: static enum ChunkFileResult_t CEditGameClass::LoadConnectionsCallback(class CChunkFile __near *,class CEditGameClass __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CEditGameClass::LoadConnectionsCallback(CChunkFile *pFile, CEditGameClass *pEditGameClass)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CEditGameClass::LoadKeyCallback,
           pData: pEditGameClass);
}

//------------------------------------------------------------------------------
// Address: 0x1002FCE0
// Name: public: int WCKVBase_Dict::GetFirst(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall WCKVBase_Dict::GetFirst(WCKVBase_Dict *this)
{
  return CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_KeyValues.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1002FCF0
// Name: public: int WCKVBase_Dict::GetNext(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall WCKVBase_Dict::GetNext(WCKVBase_Dict *this, unsigned __int16 i)
{
  return CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
           this: &this->m_KeyValues.m_Elements.m_Tree,
           i);
}

//------------------------------------------------------------------------------
// Address: 0x1002FD10
// Name: public: class CEditGameClass __near * CEditGameClass::CopyFrom(class CEditGameClass __near *)
// Source: json
//------------------------------------------------------------------------------
CEditGameClass *__thiscall CEditGameClass::CopyFrom(CEditGameClass *this, CEditGameClass *pFrom)
{
  char *m_szClass; // eax
  int v4; // edx
  char v5; // cl
  unsigned __int16 i; // si
  UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short> *v7; // eax
  CEditGameClass *v8; // ebx
  int m_Size; // eax
  int v10; // esi
  CEntityConnection **m_pMemory; // ecx
  CEntityConnection *v12; // edi
  int v13; // esi
  const CEntityConnection *v14; // edi
  CEntityConnection *v15; // eax
  CEntityConnection *v16; // eax
  char *m_pszComments; // esi
  unsigned int v18; // eax
  char *v19; // eax
  char *v20; // ecx
  char *v21; // edx
  char v22; // al
  int nConnCount; // [esp+10h] [ebp-10h]
  int nConnCounta; // [esp+10h] [ebp-10h]

  this->m_pClass = pFrom->m_pClass;
  m_szClass = pFrom->m_szClass;
  v4 = (char *)this - pFrom->m_szClass;
  do
  {
    v5 = *m_szClass;
    m_szClass[v4 + 36] = *m_szClass;
    ++m_szClass;
  }
  while ( v5 != 0 );
  WCKeyValuesT<WCKVBase_Dict>::RemoveAll(this: &this->m_KeyValues);
  for ( i = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &pFrom->m_KeyValues.m_KeyValues.m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &pFrom->m_KeyValues.m_KeyValues.m_Elements.m_Tree,
              i) )
  {
    v7 = &pFrom->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[i];
    WCKeyValuesT<WCKVBase_Dict>::SetValue(
      this: &this->m_KeyValues,
      pszKey: v7->m_Data.elem.szKey,
      pszValue: v7->m_Data.elem.szValue);
  }
  v8 = this;
  m_Size = this->m_Connections.m_Size;
  v10 = 0;
  for ( nConnCount = m_Size; v10 < m_Size; ++v10 )
  {
    m_pMemory = v8->m_Connections.m_Memory.m_pMemory;
    v12 = m_pMemory[v10];
    if ( v12 != nullptr )
    {
      CEntityConnection::~CEntityConnection(this: m_pMemory[v10]);
      operator delete(p: v12);
      m_Size = nConnCount;
    }
  }
  v13 = 0;
  v8->m_Connections.m_Size = 0;
  nConnCounta = pFrom->m_Connections.m_Size;
  if ( nConnCounta > 0 )
  {
    do
    {
      v14 = pFrom->m_Connections.m_Memory.m_pMemory[v13];
      v15 = (CEntityConnection *)operator new(nSize: 0x510u);
      if ( v15 != nullptr )
        v16 = CEntityConnection::CEntityConnection(this: v15, Other: v14);
      else
        v16 = nullptr;
      CEditGameClass::Connections_Add(this: v8, pConnection: v16);
      ++v13;
    }
    while ( v13 < nConnCounta );
  }
  m_pszComments = pFrom->m_pszComments;
  if ( m_pszComments == nullptr )
    m_pszComments = CEditGameClass::g_pszEmpty;
  operator delete(p: v8->m_pszComments);
  if ( m_pszComments != nullptr && (v18 = strlen(m_pszComments)) != 0 )
  {
    v19 = (char *)operator new[](nSize: v18 + 1);
    v8->m_pszComments = v19;
    v20 = m_pszComments;
    v21 = v19;
    do
    {
      v22 = *v20;
      *v21++ = *v20++;
    }
    while ( v22 != 0 );
  }
  else
  {
    v8->m_pszComments = nullptr;
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1002FEA0
// Name: public: enum ChunkFileResult_t CEditGameClass::SaveVMF(class CChunkFile __near *,class CSaveInfo __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CEditGameClass::SaveVMF(CEditGameClass *this, CChunkFile *pFile, CSaveInfo *pSaveInfo)
{
  CEditGameClass *v3; // esi
  ChunkFileResult_t result; // eax
  ChunkFileResult_t v5; // ebx
  unsigned __int16 i; // di
  const char *szKey; // esi
  GDclass *v8; // ecx
  int v9; // edi
  int m_Size; // ebx
  int v11; // edi
  GDinputvariable *VariableAt; // esi
  CEntityConnection *v13; // esi
  MDkeyvalue pkv; // [esp+Ch] [ebp-26Ch] BYREF
  int piIndex; // [esp+25Ch] [ebp-1Ch] BYREF
  int m_nVariables; // [esp+260h] [ebp-18h]
  GDclass *v17; // [esp+264h] [ebp-14h]
  CEditGameClass *v18; // [esp+268h] [ebp-10h]
  GDclass *pGameDataClass; // [esp+274h] [ebp-4h]

  v3 = this;
  v18 = this;
  result = CChunkFile::WriteKeyValue(this: pFile, pszKey: "classname", pszValue: this->m_szClass);
  v5 = result;
  if ( result != ChunkFile_Ok )
    return result;
  v17 = nullptr;
  if ( pGD != nullptr )
    v17 = GameData::ClassForName(this: pGD, pszName: v3->m_szClass, piIndex: nullptr);
  for ( i = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &v3->m_KeyValues.m_KeyValues.m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &v18->m_KeyValues.m_KeyValues.m_Elements.m_Tree,
              i) )
  {
    szKey = v3->m_KeyValues.m_KeyValues.m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.elem.szKey;
    if ( _V_stricmp(s1: szKey, s2: "classname") != 0 )
    {
      v5 = CChunkFile::WriteKeyValue(this: pFile, pszKey: szKey, pszValue: szKey + 80);
      if ( v5 != ChunkFile_Ok )
        return v5;
    }
    v3 = v18;
  }
  v8 = v17;
  if ( v17 != nullptr )
  {
    v9 = 0;
    m_nVariables = v17->m_nVariables;
    if ( m_nVariables > 0 )
    {
      while ( 1 )
      {
        VariableAt = GDclass::GetVariableAt(this: v8, iIndex: v9);
        if ( VariableAt != nullptr
          && WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &v18->m_KeyValues, pszKey: VariableAt->m_szName, &piIndex) == nullptr )
        {
          pkv.szKey[0] = 0;
          pkv.szValue[0] = 0;
          pGameDataClass = nullptr;
          GDinputvariable::ResetDefaults(this: VariableAt);
          GDinputvariable::ToKeyValue(this: VariableAt, &pkv);
          if ( pkv.szKey[0] != 0 && pkv.szValue[0] != 0 && _V_stricmp(s1: pkv.szValue, s2: "0") != 0 )
          {
            v5 = CChunkFile::WriteKeyValue(this: pFile, pszKey: pkv.szKey, pszValue: pkv.szValue);
            if ( v5 != ChunkFile_Ok )
            {
              pGameDataClass = (GDclass *)-1;
              CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)&pkv);
              return v5;
            }
          }
          pGameDataClass = (GDclass *)-1;
          CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)&pkv);
        }
        if ( ++v9 >= m_nVariables )
        {
          v3 = v18;
          break;
        }
        v8 = v17;
      }
    }
  }
  if ( v3->m_Connections.m_Size <= 0 )
    return v5;
  v5 = CChunkFile::BeginChunk(this: pFile, pszChunkName: "connections");
  if ( v5 != ChunkFile_Ok )
    return v5;
  m_Size = v3->m_Connections.m_Size;
  v11 = 0;
  if ( m_Size <= 0 )
    return CChunkFile::EndChunk(this: pFile);
  while ( 1 )
  {
    v13 = v3->m_Connections.m_Memory.m_pMemory[v11];
    if ( v13 != nullptr )
    {
      sprintf(
        string: pkv.szValue,
        format: "%s%c%s%c%s%c%g%c%d",
        v13->m_szTargetEntity,
        27,
        v13->m_szInput,
        27,
        v13->m_szParam,
        27,
        v13->m_fDelay,
        27,
        v13->m_nTimesToFire);
      result = CChunkFile::WriteKeyValue(this: pFile, pszKey: v13->m_szOutput, pszValue: pkv.szValue);
      if ( result != ChunkFile_Ok )
        break;
    }
    if ( ++v11 >= m_Size )
      return CChunkFile::EndChunk(this: pFile);
    v3 = v18;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002F100
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CUtlMap<char const __near *,class MDkeyvalue,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,class MDkeyvalue,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    *(_DWORD *)&`CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MDkeyvalue,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MDkeyvalue,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}
