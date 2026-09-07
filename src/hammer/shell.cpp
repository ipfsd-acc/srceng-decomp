// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/shell.cpp
// Functions: 16
// ============================================================

#include "hammer\shell.h"

//------------------------------------------------------------------------------
// Address: 0x1014D1C0
// Name: private: bool CShell::EndSession(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShell::EndSession(CShell *this, const char *pszCommand, const char *pszArguments)
{
  CMapDoc *m_pDoc; // ecx

  m_pDoc = this->m_pDoc;
  if ( m_pDoc == nullptr || !CMapDoc::IsShellSessionActive(this: m_pDoc) )
    return 0;
  CMapDoc::EndShellSession(this: this->m_pDoc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014D1F0
// Name: private: bool CShell::EntityCreate(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShell::EntityCreate(CShell *this, const char *pszCommand, const char *pszArguments)
{
  CMapDoc *m_pDoc; // ecx
  char pszClassName[12]; // [esp+10h] [ebp-10Ch] BYREF
  char szClassName[260]; // [esp+1Ch] [ebp-100h] BYREF

  m_pDoc = this->m_pDoc;
  return m_pDoc != nullptr
      && CMapDoc::IsShellSessionActive(this: m_pDoc)
      && sscanf(
           string: pszArguments,
           format: "%s %f %f %f",
           pszClassName,
           &szClassName[252],
           &szClassName[248],
           &pszArguments) == 4
      && CMapDoc::CreateEntity(
           this: this->m_pDoc,
           pszClassName,
           x: *(float *)&szClassName[252],
           y: *(float *)&szClassName[248],
           z: *(float *)&pszArguments) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1014D280
// Name: private: bool CShell::EntityDelete(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShell::EntityDelete(CShell *this, const char *pszCommand, const char *pszArguments)
{
  CMapDoc *m_pDoc; // ecx
  char pszClassName[12]; // [esp+10h] [ebp-10Ch] BYREF
  char szClassName[260]; // [esp+1Ch] [ebp-100h] BYREF

  m_pDoc = this->m_pDoc;
  if ( m_pDoc != nullptr
    && CMapDoc::IsShellSessionActive(this: m_pDoc)
    && sscanf(
         string: pszArguments,
         format: "%s %f %f %f",
         pszClassName,
         &szClassName[252],
         &szClassName[248],
         &pszArguments) == 4 )
  {
    return CMapDoc::DeleteEntity(
             this: this->m_pDoc,
             pszClassName,
             x: __SPAIR64__(*(unsigned int *)&szClassName[248], *(unsigned int *)&szClassName[252]),
             z: *(float *)&pszArguments);
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014D310
// Name: RotateMapEntity
// Source: json
//------------------------------------------------------------------------------
void __usercall RotateMapEntity(CMapEntity *pEntity@<esi>, const QAngle *rotation@<edi>)
{
  float z; // xmm1_4
  float y; // xmm3_4
  void (__thiscall *DoTransform)(CMapAtom *, const VMatrix *); // edx
  float v5; // xmm6_4
  VMatrix v6; // [esp+0h] [ebp-58h] BYREF
  Vector origin; // [esp+40h] [ebp-18h] BYREF
  QAngle vAngles; // [esp+4Ch] [ebp-Ch] BYREF

  pEntity->GetOrigin(this: pEntity, a2: &origin);
  z = rotation->z;
  y = rotation->y;
  vAngles.x = rotation->x;
  vAngles.y = y;
  vAngles.z = z;
  VMatrix::SetupMatrixOrgAngles(this: &v6, origin: &vec3_origin, &vAngles);
  DoTransform = pEntity->DoTransform;
  v5 = 1.0
     / (float)((float)((float)((float)(origin.y * v6.m[3][1]) + (float)(origin.x * v6.m[3][0]))
                     + (float)(origin.z * v6.m[3][2]))
             + v6.m[3][3]);
  v6.m[0][3] = origin.x
             - (float)((float)((float)((float)((float)(v6.m[0][1] * origin.y) + (float)(v6.m[0][0] * origin.x))
                                     + (float)(v6.m[0][2] * origin.z))
                             + v6.m[0][3])
                     * v5);
  v6.m[1][3] = origin.y
             - (float)((float)((float)((float)((float)(v6.m[1][1] * origin.y) + (float)(v6.m[1][0] * origin.x))
                                     + (float)(v6.m[1][2] * origin.z))
                             + v6.m[1][3])
                     * v5);
  v6.m[2][3] = origin.z
             - (float)((float)((float)((float)((float)(v6.m[2][1] * origin.y) + (float)(v6.m[2][0] * origin.x))
                                     + (float)(v6.m[2][2] * origin.z))
                             + v6.m[2][3])
                     * v5);
  DoTransform(this: pEntity, a2: &v6);
  pEntity->PostUpdate(this: pEntity, a2: Notify_Transform);
}

//------------------------------------------------------------------------------
// Address: 0x1014D460
// Name: private: bool CShell::EntityRotateIncremental(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShell::EntityRotateIncremental(CShell *this, const char *pszCommand, char *pszArguments)
{
  CMapDoc *m_pDoc; // ecx
  char *v4; // ebx
  int v5; // esi
  char *i; // edi
  bool v7; // zf
  CMapEntity *Entity; // esi
  char pSrc[12]; // [esp+Ch] [ebp-1218h] BYREF
  char pszClassName[12]; // [esp+40Ch] [ebp-E18h] BYREF
  char v12[12]; // [esp+60Ch] [ebp-C18h] BYREF
  char v13[12]; // [esp+80Ch] [ebp-A18h] BYREF
  char v14[12]; // [esp+A0Ch] [ebp-818h] BYREF
  char v15[12]; // [esp+C0Ch] [ebp-618h] BYREF
  char v16[12]; // [esp+E0Ch] [ebp-418h] BYREF
  char v17[12]; // [esp+100Ch] [ebp-218h] BYREF
  QAngle v18; // [esp+120Ch] [ebp-18h] BYREF
  QAngle rotation; // [esp+1218h] [ebp-Ch]
  float v20; // [esp+1230h] [ebp+Ch]

  LODWORD(rotation.z) = this;
  m_pDoc = this->m_pDoc;
  if ( m_pDoc == nullptr )
    return 0;
  if ( !CMapDoc::IsShellSessionActive(this: m_pDoc) )
    return 0;
  v4 = pszArguments;
  v5 = 0;
  if ( pszArguments == nullptr )
    return 0;
  for ( i = pszClassName; ; i += 512 )
  {
    v7 = v5 == 7;
    if ( v5 >= 7 )
      break;
    v4 = ParseFile(pFileBytes: v4, pToken: pSrc, pWasQuoted: nullptr, pCharSet: nullptr);
    if ( v4 == nullptr )
    {
      v7 = v5 == 7;
      break;
    }
    V_strncpy(pDest: i, pSrc, maxLen: 512);
    ++v5;
  }
  if ( !v7 )
    return 0;
  rotation.y = atof(nptr: v12);
  rotation.x = atof(nptr: v13);
  v20 = atof(nptr: v14);
  Entity = CMapDoc::FindEntity(
             this: *(CMapDoc **)LODWORD(rotation.z),
             pszClassName,
             x: rotation.y,
             y: rotation.x,
             z: v20);
  if ( Entity == nullptr )
    return 0;
  v18.x = atof(nptr: v15);
  v18.y = atof(nptr: v16);
  v18.z = atof(nptr: v17);
  RotateMapEntity(pEntity: Entity, rotation: &v18);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014D5A0
// Name: private: bool CShell::EntitySetKeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShell::EntitySetKeyValue(CShell *this, const char *pszCommand, char *pszArguments)
{
  CMapDoc *m_pDoc; // ecx
  char *v4; // ebx
  int v5; // esi
  char *i; // edi
  bool v7; // zf
  CMapEntity *Entity; // esi
  char pSrc[12]; // [esp+18h] [ebp-1030h] BYREF
  char pszClassName[12]; // [esp+418h] [ebp-C30h] BYREF
  char v12[12]; // [esp+618h] [ebp-A30h] BYREF
  char v13[12]; // [esp+818h] [ebp-830h] BYREF
  char v14[12]; // [esp+A18h] [ebp-630h] BYREF
  char v15[12]; // [esp+C18h] [ebp-430h] BYREF
  char v16[12]; // [esp+E18h] [ebp-230h] BYREF
  float v17; // [esp+1018h] [ebp-30h]
  float v18; // [esp+101Ch] [ebp-2Ch]
  CShell *v19; // [esp+1020h] [ebp-28h]
  QAngle rotation; // [esp+1024h] [ebp-24h] BYREF
  QAngle out; // [esp+1030h] [ebp-18h] BYREF
  Vector Delta; // [esp+103Ch] [ebp-Ch] BYREF
  float v23; // [esp+1054h] [ebp+Ch]

  v19 = this;
  m_pDoc = this->m_pDoc;
  if ( m_pDoc == nullptr )
    return 0;
  if ( !CMapDoc::IsShellSessionActive(this: m_pDoc) )
    return 0;
  v4 = pszArguments;
  v5 = 0;
  if ( pszArguments == nullptr )
    return 0;
  for ( i = pszClassName; ; i += 512 )
  {
    v7 = v5 == 6;
    if ( v5 >= 6 )
      break;
    v4 = ParseFile(pFileBytes: v4, pToken: pSrc, pWasQuoted: nullptr, pCharSet: nullptr);
    if ( v4 == nullptr )
    {
      v7 = v5 == 6;
      break;
    }
    V_strncpy(pDest: i, pSrc, maxLen: 512);
    ++v5;
  }
  if ( !v7 )
    return 0;
  v17 = atof(nptr: v12);
  v18 = atof(nptr: v13);
  v23 = atof(nptr: v14);
  Entity = CMapDoc::FindEntity(this: v19->m_pDoc, pszClassName, x: v17, y: v18, z: v23);
  if ( Entity == nullptr )
    return 0;
  if ( _V_stricmp(s1: v15, s2: "origin") == 0 )
  {
    sscanf(string: v16, format: "%f %f %f", &Delta, &Delta.y, &Delta.z);
    Entity->GetOrigin(this: Entity, a2: (Vector *)&rotation);
    out.x = Delta.x - rotation.x;
    out.y = Delta.y - rotation.y;
    out.z = Delta.z - rotation.z;
    CMapAtom::TransMove(this: Entity, Delta: (const Vector *)&out);
    return 1;
  }
  if ( !CEditGameClass::IsSolidClass(this: &Entity->CEditGameClass) || _V_stricmp(s1: v15, s2: "angles") != 0 )
  {
    Entity->SetKeyValue(this: &Entity->CEditGameClass, a2: v15, a3: v16);
  }
  else
  {
    sscanf(string: v16, format: "%f %f %f", &Delta, &Delta.y, &Delta.z);
    Entity->GetAngles(this: &Entity->CEditGameClass, a2: &out);
    if ( Vector::operator!=(this: (Vector *)&out, src: &Delta) )
    {
      RotationDelta(srcAngles: &out, destAngles: (const QAngle *)&Delta, out: &rotation);
      RotateMapEntity(pEntity: Entity, &rotation);
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014D7F0
// Name: private: bool CShell::NodeCreate(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShell::NodeCreate(CShell *this, const char *pszCommand, const char *pszArguments)
{
  CMapDoc *m_pDoc; // ecx
  char pszClassName[12]; // [esp+10h] [ebp-110h] BYREF
  char szClassName[260]; // [esp+1Ch] [ebp-104h] BYREF

  m_pDoc = this->m_pDoc;
  if ( m_pDoc == nullptr
    || !CMapDoc::IsShellSessionActive(this: m_pDoc)
    || sscanf(
         string: pszArguments,
         format: "%s %d %f %f %f",
         pszClassName,
         &pszArguments,
         &szClassName[252],
         &szClassName[256],
         &szClassName[248]) != 5 )
  {
    return 0;
  }
  this->m_pDoc->m_nNextNodeID = (int)pszArguments;
  CMapDoc::CreateEntity(
    this: this->m_pDoc,
    pszClassName,
    x: *(float *)&szClassName[252],
    y: *(float *)&szClassName[256],
    z: *(float *)&szClassName[248]);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014D890
// Name: private: bool CShell::NodeLinkCreate(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShell::NodeLinkCreate(CShell *this, const char *pszCommand, const char *pszArguments)
{
  CMapDoc *m_pDoc; // ecx
  CMapEntity *Entity; // eax
  CEditGameClass *v6; // esi
  float y; // [esp+10h] [ebp-A0h] BYREF
  char szIDEnd[80]; // [esp+1Ch] [ebp-94h] BYREF

  m_pDoc = this->m_pDoc;
  if ( m_pDoc == nullptr )
    return 0;
  if ( !CMapDoc::IsShellSessionActive(this: m_pDoc) )
    return 0;
  if ( sscanf(string: pszArguments, format: "%s %s", &szIDEnd[68], &y) != 2 )
    return 0;
  Entity = CMapDoc::CreateEntity(this: this->m_pDoc, pszClassName: "info_node_link", x: 0.0, y: 0.0, z: 0.0);
  if ( Entity == nullptr )
    return 0;
  v6 = &Entity->CEditGameClass;
  Entity->SetKeyValue(this: &Entity->CEditGameClass, a2: "startnode", a3: &szIDEnd[68]);
  v6->SetKeyValue(this: v6, a2: "endnode", a3: (const char *)&y);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014D940
// Name: public: bool CShell::RunCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShell::RunCommand(CShell *this, const char *pszCommand)
{
  int v2; // edi
  unsigned int v3; // esi

  v2 = 0;
  while ( 1 )
  {
    v3 = strlen(CShell::m_DispatchTable[v2].pszCommand);
    if ( _strnicmp(dst: pszCommand, src: CShell::m_DispatchTable[v2].pszCommand, count: v3) == 0 )
      break;
    if ( (unsigned int)++v2 >= 0xD )
      return false;
  }
  return (*(&off_10731DFC + 2 * v2))(
           this,
           pszCommand: CShell::m_DispatchTable[v2].pszCommand,
           pszArguments: &pszCommand[v3]);
}

//------------------------------------------------------------------------------
// Address: 0x1014D9C0
// Name: private: bool CShell::DoVersionCheck(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShell::DoVersionCheck(CShell *this, const char *pszArguments)
{
  const char *m_nDocVersion; // esi
  bool result; // al
  char szDocName[260]; // [esp+4h] [ebp-30Ch] BYREF
  char szEngineMapPath[260]; // [esp+108h] [ebp-208h] BYREF
  char szEngineMapName[260]; // [esp+20Ch] [ebp-104h] BYREF

  result = false;
  if ( this->m_pDoc != nullptr && sscanf(string: pszArguments, format: "%s %d", szEngineMapPath, &pszArguments) == 2 )
  {
    _splitpath(path: szEngineMapPath, drive: nullptr, dir: nullptr, fname: szEngineMapName, ext: nullptr);
    _splitpath(
      path: this->m_pDoc->m_strPathName.m_pszData,
      drive: nullptr,
      dir: nullptr,
      fname: szDocName,
      ext: nullptr);
    m_nDocVersion = (const char *)this->m_pDoc->m_nDocVersion;
    if ( _V_stricmp(s1: szDocName, s2: szEngineMapName) == 0 && m_nDocVersion == pszArguments )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1014DA60
// Name: private: bool CShell::ReleaseVideoMemory(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShell::ReleaseVideoMemory(CShell *this, const char *pszCommand, const char *pszArguments)
{
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v4; // eax

  ModuleState = AfxGetModuleState();
  CHammer::ReleaseVideoMemory(this: (CHammer *)ModuleState->m_pCurrentWinApp);
  v4 = AfxGetModuleState();
  CHammer::SuppressVideoAllocation(this: (CHammer *)v4->m_pCurrentWinApp, bSuppress: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014DA90
// Name: private: bool CShell::GrabVideoMemory(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShell::GrabVideoMemory(CShell *this, const char *pszCommand, const char *pszArguments)
{
  AFX_MODULE_STATE *ModuleState; // eax

  ModuleState = AfxGetModuleState();
  CHammer::SuppressVideoAllocation(this: (CHammer *)ModuleState->m_pCurrentWinApp, bSuppress: false);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014DAB0
// Name: private: bool CShell::BeginSession(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShell::BeginSession(CShell *this, const char *pszCommand, const char *pszArguments)
{
  CMapDoc *m_pDoc; // ecx

  m_pDoc = this->m_pDoc;
  if ( m_pDoc == nullptr || CMapDoc::IsShellSessionActive(this: m_pDoc) || !CShell::DoVersionCheck(this, pszArguments) )
    return 0;
  CMapDoc::BeginShellSession(this: this->m_pDoc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014DAF0
// Name: private: bool CShell::CheckMapVersion(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShell::CheckMapVersion(CShell *this, const char *pszCommand, const char *pszArguments)
{
  CMapDoc *m_pDoc; // ecx

  m_pDoc = this->m_pDoc;
  return m_pDoc != nullptr && CMapDoc::IsShellSessionActive(this: m_pDoc) && CShell::DoVersionCheck(this, pszArguments);
}

//------------------------------------------------------------------------------
// Address: 0x1014DB20
// Name: private: bool CShell::NodeLinkDelete(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShell::NodeLinkDelete(CShell *this, const char *pszCommand, const char *pszArguments)
{
  CMapDoc *m_pDoc; // ecx
  bool result; // al
  int v6; // edx
  CMapEntity *m_pObject; // edi
  const char *Value; // ebx
  const char *v9; // eax
  const char *v10; // esi
  char szIDStart[80]; // [esp+8h] [ebp-C8h] BYREF
  char szIDEnd[80]; // [esp+58h] [ebp-78h] BYREF
  CShell *v13; // [esp+A8h] [ebp-28h]
  CUtlReferenceVector<CMapEntity> Found; // [esp+ACh] [ebp-24h] BYREF
  bool bFound; // [esp+C3h] [ebp-Dh]
  int v16; // [esp+CCh] [ebp-4h]
  int pos; // [esp+DCh] [ebp+Ch]

  m_pDoc = this->m_pDoc;
  result = false;
  v13 = this;
  bFound = false;
  if ( m_pDoc != nullptr )
  {
    if ( CMapDoc::IsShellSessionActive(this: m_pDoc)
      && sscanf(string: pszArguments, format: "%s %s", szIDStart, szIDEnd) == 2 )
    {
      memset(&Found, 0, 12);
      CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
        this: (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)&Found,
        nGrowSize: 0,
        nInitSize: 0);
      Found.m_Size = 0;
      Found.m_pElements = nullptr;
      v16 = 3;
      if ( CMapDoc::FindEntitiesByClassName(
             this: this->m_pDoc,
             &Found,
             pszClassName: "info_node_link",
             bVisiblesOnly: false) )
      {
        v6 = 0;
        pos = 0;
        if ( Found.m_Size > 0 )
        {
          while ( 1 )
          {
            m_pObject = Found.m_Memory.m_pMemory[v6 >> (*((int *)&Found.m_Memory + 2) >> 27)][v6
                                                                                            & ((32
                                                                                              * *((_DWORD *)&Found.m_Memory
                                                                                                + 2)) >> 5)].m_pObject;
            Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(
                      this: &m_pObject->m_KeyValues,
                      pszKey: "startnode",
                      piIndex: nullptr);
            v9 = WCKeyValuesT<WCKVBase_Dict>::GetValue(
                   this: &m_pObject->m_KeyValues,
                   pszKey: "endnode",
                   piIndex: nullptr);
            v10 = v9;
            if ( Value != nullptr
              && v9 != nullptr
              && (_V_stricmp(s1: Value, s2: szIDStart) == 0 && _V_stricmp(s1: v10, s2: szIDEnd) == 0
               || _V_stricmp(s1: Value, s2: szIDEnd) == 0 && _V_stricmp(s1: v10, s2: szIDStart) == 0) )
            {
              CMapDoc::DeleteObject(this: v13->m_pDoc, pObject: m_pObject);
              bFound = true;
            }
            if ( ++pos >= Found.m_Size )
              break;
            v6 = pos;
          }
        }
      }
      v16 = -1;
      CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(this: &Found);
      return bFound;
    }
    else
    {
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1014DCD0
// Name: private: bool CShell::NodeDelete(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShell::NodeDelete(CShell *this, const char *pszCommand, const char *pszArguments)
{
  CMapDoc *m_pDoc; // ecx
  char v5; // bl
  int v6; // esi
  char szID[80]; // [esp+8h] [ebp-70h] BYREF
  CUtlReferenceVector<CMapEntity> Found; // [esp+58h] [ebp-20h] BYREF
  int v10; // [esp+74h] [ebp-4h]

  m_pDoc = this->m_pDoc;
  v5 = 0;
  if ( m_pDoc != nullptr
    && CMapDoc::IsShellSessionActive(this: m_pDoc)
    && sscanf(string: pszArguments, format: "%s", szID) == 1 )
  {
    memset(&Found, 0, 12);
    CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
      this: (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)&Found,
      nGrowSize: 0,
      nInitSize: 0);
    Found.m_Size = 0;
    Found.m_pElements = nullptr;
    v10 = 3;
    if ( CMapDoc::FindEntitiesByKeyValue(
           this: this->m_pDoc,
           &Found,
           pszKey: "nodeid",
           pszValue: szID,
           bVisiblesOnly: false) )
    {
      v6 = 0;
      if ( Found.m_Size > 0 )
      {
        v5 = 1;
        do
        {
          CMapDoc::DeleteObject(
            this: this->m_pDoc,
            pObject: Found.m_Memory.m_pMemory[v6 >> (*((int *)&Found.m_Memory + 2) >> 27)][v6
                                                                                & ((32 * *((_DWORD *)&Found.m_Memory + 2)) >> 5)].m_pObject);
          ++v6;
        }
        while ( v6 < Found.m_Size );
      }
    }
    v10 = -1;
    CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(this: &Found);
  }
  return v5;
}
