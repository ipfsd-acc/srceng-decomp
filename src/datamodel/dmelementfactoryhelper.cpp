// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: datamodel/dmelementfactoryhelper.cpp
// Functions: 6
// ============================================================

#include "datamodel\dmelementfactoryhelper.h"

//------------------------------------------------------------------------------
// Address: 0x004441C0
// Name: public: CDmElementFactoryHelper::CDmElementFactoryHelper(char const __near *,class CDmElementFactoryInternal __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmElementFactoryHelper *__thiscall CDmElementFactoryHelper::CDmElementFactoryHelper(
        CDmElementFactoryHelper *this,
        const char *classname,
        CDmElementFactoryInternal *pFactory,
        bool bIsStandardFactory)
{
  this->m_pParent = nullptr;
  this->m_pChild = nullptr;
  this->m_pSibling = nullptr;
  this->m_pNext = CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory];
  CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory] = this;
  this->m_pFactory = pFactory;
  this->m_pszClassname = classname;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00444200
// Name: public: static void CDmElementFactoryHelper::InstallFactories(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmElementFactoryHelper::InstallFactories()
{
  CDmElementFactoryHelper *v0; // esi
  int *m_pFactory; // ebx
  const char *m_pszClassname; // eax
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int v4; // edi
  CDmElementFactoryHelper *i; // esi
  int *v6; // ebx
  const char *v7; // eax
  CUtlSymbolLarge *(__thiscall *v8)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int v9; // edi
  CDmElementFactoryHelper **v10; // eax
  CDmElementFactoryHelper *v11; // ebx
  CDmElementFactoryHelper *v12; // eax
  CDmElementFactoryHelper *v13; // esi
  CDmElementFactoryHelper *m_pChild; // edi
  const char *v15; // eax
  CDmElementFactoryHelper *j; // esi
  _DWORD v17[4]; // [esp-4h] [ebp-1Ch] BYREF
  const char *pClassName; // [esp+Ch] [ebp-Ch]
  CUtlSymbolLarge parentElementTypeSym; // [esp+10h] [ebp-8h] BYREF
  CDmElementFactoryHelper **v20; // [esp+14h] [ebp-4h]

  if ( !s_bInstalled )
  {
    v0 = CDmElementFactoryHelper::s_pHelpers[0];
    for ( s_bInstalled = true; v0 != nullptr; v0 = v0->m_pNext )
    {
      m_pFactory = (int *)v0->m_pFactory;
      g_pDataModel->AddElementFactory(this: g_pDataModel, a2: v0);
      m_pszClassname = v0->m_pszClassname;
      GetSymbol = g_pDataModel->GetSymbol;
      v4 = *m_pFactory;
      v17[0] = g_pDataModel;
      GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)v17, a3: m_pszClassname);
      (*(void (__thiscall **)(int *))(v4 + 20))(a1: m_pFactory);
    }
    for ( i = (CDmElementFactoryHelper *)dword_4B5A84; i != nullptr; i = i->m_pNext )
    {
      if ( !g_pDataModel->HasElementFactory(this: g_pDataModel, a2: i->m_pszClassname) )
      {
        v6 = (int *)i->m_pFactory;
        g_pDataModel->AddElementFactory(this: g_pDataModel, a2: i);
        if ( _V_stricmp(s1: i->m_pszClassname, s2: "DmeElement") != 0 )
        {
          v7 = i->m_pszClassname;
          v8 = g_pDataModel->GetSymbol;
          v9 = *v6;
          v17[0] = g_pDataModel;
          v8(this: g_pDataModel, result: (CUtlSymbolLarge *)v17, a3: v7);
          (*(void (__thiscall **)(int *))(v9 + 20))(a1: v6);
        }
      }
    }
    g_pDataModel->SetDefaultElementFactory(this: g_pDataModel, a2: g_CDmElement_Helper.m_pFactory);
    v10 = CDmElementFactoryHelper::s_pHelpers;
    v20 = CDmElementFactoryHelper::s_pHelpers;
    do
    {
      v11 = *v10;
      if ( *v10 != nullptr )
      {
        do
        {
          v11->m_pFactory->GetParentElementTypeSymbol(this: v11->m_pFactory, result: &parentElementTypeSym);
          if ( parentElementTypeSym.u.m_Id != -1 )
          {
            v12 = g_pDataModel->GetElementFactoryHelper(this: g_pDataModel, a2: parentElementTypeSym.u.m_Id);
            v13 = v12;
            if ( v12 != nullptr )
            {
              m_pChild = v12->m_pChild;
              v15 = v11->m_pszClassname;
              pClassName = v15;
              if ( m_pChild != nullptr && _V_stricmp(s1: v15, s2: m_pChild->m_pszClassname) >= 0 )
              {
                for ( j = m_pChild->m_pSibling; j != nullptr; j = j->m_pSibling )
                {
                  if ( _V_stricmp(s1: pClassName, s2: j->m_pszClassname) < 0 )
                    break;
                  m_pChild = j;
                }
                v11->m_pSibling = m_pChild->m_pSibling;
                m_pChild->m_pSibling = v11;
              }
              else
              {
                v13->m_pChild = v11;
                v11->m_pSibling = m_pChild;
              }
            }
          }
          v11 = v11->m_pNext;
        }
        while ( v11 != nullptr );
        v10 = v20;
      }
      v20 = ++v10;
    }
    while ( (int)v10 < (int)&vec2_origin_12 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004443C0
// Name: void InstallDmElementFactories(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl InstallDmElementFactories()
{
  CDmElementFactoryHelper::InstallFactories();
}

//------------------------------------------------------------------------------
// Address: 0x004443D0
// Name: public: virtual void CDmElementFactoryInternal::OnElementCreated(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::OnElementCreated(CDmElementFactoryInternal *this, CDmElement *pElement)
{
  int i; // esi
  IDmeElementCreated *v4; // ecx

  for ( i = 0; i < this->m_CallBackList.m_Size; ++i )
  {
    v4 = this->m_CallBackList.m_Memory.m_pMemory[i];
    v4->OnElementCreated(this: v4, a2: pElement);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444400
// Name: public: virtual void CDmElementFactoryInternal::RemoveOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::RemoveOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(
    this: (CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int> > *)&this->m_CallBackList,
    src: (IDmNotify **)&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x00444420
// Name: public: virtual void CDmElementFactoryInternal::AddOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::AddOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_CallBackList; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmeElementCreated **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax

  p_m_CallBackList = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_CallBackList;
  m_Size = this->m_CallBackList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (IDmeElementCreated **)p_m_CallBackList->m_pMemory;
  while ( *m_pMemory != pCallback )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_CallBackList->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_CallBackList, num: m_Size - m_nAllocationCount + 1);
    ++p_m_CallBackList[1].m_pMemory;
    v8 = p_m_CallBackList->m_pMemory;
    v9 = (int)p_m_CallBackList[1].m_pMemory - v7 - 1;
    p_m_CallBackList[1].m_nAllocationCount = (int)p_m_CallBackList->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_CallBackList->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (CUtlSymbolTable::StringPool_t *)pCallback;
  }
}

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x00452A40
// Name: public: CDmElementFactoryHelper::CDmElementFactoryHelper(char const __near *,class CDmElementFactoryInternal __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmElementFactoryHelper *__thiscall CDmElementFactoryHelper::CDmElementFactoryHelper(
        CDmElementFactoryHelper *this,
        const char *classname,
        CDmElementFactoryInternal *pFactory,
        bool bIsStandardFactory)
{
  this->m_pParent = nullptr;
  this->m_pChild = nullptr;
  this->m_pSibling = nullptr;
  this->m_pNext = CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory];
  CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory] = this;
  this->m_pFactory = pFactory;
  this->m_pszClassname = classname;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00452A80
// Name: public: static void CDmElementFactoryHelper::InstallFactories(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmElementFactoryHelper::InstallFactories()
{
  CDmElementFactoryHelper *v0; // esi
  int *m_pFactory; // ebx
  const char *m_pszClassname; // eax
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int v4; // edi
  CDmElementFactoryHelper *i; // esi
  int *v6; // ebx
  const char *v7; // eax
  CUtlSymbolLarge *(__thiscall *v8)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int v9; // edi
  CDmElementFactoryHelper **v10; // eax
  CDmElementFactoryHelper *v11; // ebx
  CDmElementFactoryHelper *v12; // eax
  CDmElementFactoryHelper *v13; // esi
  CDmElementFactoryHelper *m_pChild; // edi
  const char *v15; // eax
  CDmElementFactoryHelper *j; // esi
  _DWORD v17[4]; // [esp-4h] [ebp-1Ch] BYREF
  const char *pClassName; // [esp+Ch] [ebp-Ch]
  CUtlSymbolLarge parentElementTypeSym; // [esp+10h] [ebp-8h] BYREF
  CDmElementFactoryHelper **v20; // [esp+14h] [ebp-4h]

  if ( !s_bInstalled )
  {
    v0 = CDmElementFactoryHelper::s_pHelpers[0];
    for ( s_bInstalled = true; v0 != nullptr; v0 = v0->m_pNext )
    {
      m_pFactory = (int *)v0->m_pFactory;
      g_pDataModel->AddElementFactory(this: g_pDataModel, a2: v0);
      m_pszClassname = v0->m_pszClassname;
      GetSymbol = g_pDataModel->GetSymbol;
      v4 = *m_pFactory;
      v17[0] = g_pDataModel;
      GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)v17, a3: m_pszClassname);
      (*(void (__thiscall **)(int *))(v4 + 20))(a1: m_pFactory);
    }
    for ( i = (CDmElementFactoryHelper *)dword_60BA7C; i != nullptr; i = i->m_pNext )
    {
      if ( !g_pDataModel->HasElementFactory(this: g_pDataModel, a2: i->m_pszClassname) )
      {
        v6 = (int *)i->m_pFactory;
        g_pDataModel->AddElementFactory(this: g_pDataModel, a2: i);
        if ( _V_stricmp(s1: i->m_pszClassname, s2: "DmeElement") != 0 )
        {
          v7 = i->m_pszClassname;
          v8 = g_pDataModel->GetSymbol;
          v9 = *v6;
          v17[0] = g_pDataModel;
          v8(this: g_pDataModel, result: (CUtlSymbolLarge *)v17, a3: v7);
          (*(void (__thiscall **)(int *))(v9 + 20))(a1: v6);
        }
      }
    }
    g_pDataModel->SetDefaultElementFactory(this: g_pDataModel, a2: g_CDmElement_Helper.m_pFactory);
    v10 = CDmElementFactoryHelper::s_pHelpers;
    v20 = CDmElementFactoryHelper::s_pHelpers;
    do
    {
      v11 = *v10;
      if ( *v10 != nullptr )
      {
        do
        {
          v11->m_pFactory->GetParentElementTypeSymbol(this: v11->m_pFactory, result: &parentElementTypeSym);
          if ( parentElementTypeSym.u.m_Id != -1 )
          {
            v12 = g_pDataModel->GetElementFactoryHelper(this: g_pDataModel, a2: parentElementTypeSym.u.m_Id);
            v13 = v12;
            if ( v12 != nullptr )
            {
              m_pChild = v12->m_pChild;
              v15 = v11->m_pszClassname;
              pClassName = v15;
              if ( m_pChild != nullptr && _V_stricmp(s1: v15, s2: m_pChild->m_pszClassname) >= 0 )
              {
                for ( j = m_pChild->m_pSibling; j != nullptr; j = j->m_pSibling )
                {
                  if ( _V_stricmp(s1: pClassName, s2: j->m_pszClassname) < 0 )
                    break;
                  m_pChild = j;
                }
                v11->m_pSibling = m_pChild->m_pSibling;
                m_pChild->m_pSibling = v11;
              }
              else
              {
                v13->m_pChild = v11;
                v11->m_pSibling = m_pChild;
              }
            }
          }
          v11 = v11->m_pNext;
        }
        while ( v11 != nullptr );
        v10 = v20;
      }
      v20 = ++v10;
    }
    while ( (int)v10 < (int)&vec2_origin_16 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00452C40
// Name: void InstallDmElementFactories(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl InstallDmElementFactories()
{
  CDmElementFactoryHelper::InstallFactories();
}

//------------------------------------------------------------------------------
// Address: 0x00452C50
// Name: public: virtual void CDmElementFactoryInternal::OnElementCreated(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::OnElementCreated(CDmElementFactoryInternal *this, CDmElement *pElement)
{
  int i; // esi
  IDmeElementCreated *v4; // ecx

  for ( i = 0; i < this->m_CallBackList.m_Size; ++i )
  {
    v4 = this->m_CallBackList.m_Memory.m_pMemory[i];
    v4->OnElementCreated(this: v4, a2: pElement);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00452C80
// Name: public: virtual void CDmElementFactoryInternal::RemoveOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::RemoveOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(
    this: (CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int> > *)&this->m_CallBackList,
    src: (IDmNotify **)&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x00452CA0
// Name: public: virtual void CDmElementFactoryInternal::AddOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::AddOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_CallBackList; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmeElementCreated **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax

  p_m_CallBackList = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_CallBackList;
  m_Size = this->m_CallBackList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (IDmeElementCreated **)p_m_CallBackList->m_pMemory;
  while ( *m_pMemory != pCallback )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_CallBackList->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_CallBackList, num: m_Size - m_nAllocationCount + 1);
    ++p_m_CallBackList[1].m_pMemory;
    v8 = p_m_CallBackList->m_pMemory;
    v9 = (int)p_m_CallBackList[1].m_pMemory - v7 - 1;
    p_m_CallBackList[1].m_nAllocationCount = (int)p_m_CallBackList->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_CallBackList->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (CUtlSymbolTable::StringPool_t *)pCallback;
  }
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x0044CA70
// Name: public: CDmElementFactoryHelper::CDmElementFactoryHelper(char const __near *,class CDmElementFactoryInternal __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmElementFactoryHelper *__thiscall CDmElementFactoryHelper::CDmElementFactoryHelper(
        CDmElementFactoryHelper *this,
        const char *classname,
        CDmElementFactoryInternal *pFactory,
        bool bIsStandardFactory)
{
  this->m_pParent = nullptr;
  this->m_pChild = nullptr;
  this->m_pSibling = nullptr;
  this->m_pNext = CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory];
  CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory] = this;
  this->m_pFactory = pFactory;
  this->m_pszClassname = classname;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044CAB0
// Name: public: static void CDmElementFactoryHelper::InstallFactories(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmElementFactoryHelper::InstallFactories()
{
  CDmElementFactoryHelper *v0; // esi
  int *m_pFactory; // ebx
  const char *m_pszClassname; // eax
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int v4; // edi
  CDmElementFactoryHelper *i; // esi
  int *v6; // ebx
  const char *v7; // eax
  CUtlSymbolLarge *(__thiscall *v8)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int v9; // edi
  CDmElementFactoryHelper **v10; // eax
  CDmElementFactoryHelper *v11; // ebx
  CDmElementFactoryHelper *v12; // eax
  CDmElementFactoryHelper *v13; // esi
  CDmElementFactoryHelper *m_pChild; // edi
  const char *v15; // eax
  CDmElementFactoryHelper *j; // esi
  _DWORD v17[4]; // [esp-4h] [ebp-1Ch] BYREF
  const char *pClassName; // [esp+Ch] [ebp-Ch]
  CUtlSymbolLarge parentElementTypeSym; // [esp+10h] [ebp-8h] BYREF
  CDmElementFactoryHelper **v20; // [esp+14h] [ebp-4h]

  if ( !s_bInstalled )
  {
    v0 = CDmElementFactoryHelper::s_pHelpers[0];
    for ( s_bInstalled = true; v0 != nullptr; v0 = v0->m_pNext )
    {
      m_pFactory = (int *)v0->m_pFactory;
      g_pDataModel->AddElementFactory(this: g_pDataModel, a2: v0);
      m_pszClassname = v0->m_pszClassname;
      GetSymbol = g_pDataModel->GetSymbol;
      v4 = *m_pFactory;
      v17[0] = g_pDataModel;
      GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)v17, a3: m_pszClassname);
      (*(void (__thiscall **)(int *))(v4 + 20))(a1: m_pFactory);
    }
    for ( i = (CDmElementFactoryHelper *)dword_7630C8; i != nullptr; i = i->m_pNext )
    {
      if ( !g_pDataModel->HasElementFactory(this: g_pDataModel, a2: i->m_pszClassname) )
      {
        v6 = (int *)i->m_pFactory;
        g_pDataModel->AddElementFactory(this: g_pDataModel, a2: i);
        if ( _V_stricmp(s1: i->m_pszClassname, s2: "DmeElement") != 0 )
        {
          v7 = i->m_pszClassname;
          v8 = g_pDataModel->GetSymbol;
          v9 = *v6;
          v17[0] = g_pDataModel;
          v8(this: g_pDataModel, result: (CUtlSymbolLarge *)v17, a3: v7);
          (*(void (__thiscall **)(int *))(v9 + 20))(a1: v6);
        }
      }
    }
    g_pDataModel->SetDefaultElementFactory(this: g_pDataModel, a2: g_CDmElement_Helper.m_pFactory);
    v10 = CDmElementFactoryHelper::s_pHelpers;
    v20 = CDmElementFactoryHelper::s_pHelpers;
    do
    {
      v11 = *v10;
      if ( *v10 != nullptr )
      {
        do
        {
          v11->m_pFactory->GetParentElementTypeSymbol(this: v11->m_pFactory, result: &parentElementTypeSym);
          if ( parentElementTypeSym.u.m_Id != -1 )
          {
            v12 = g_pDataModel->GetElementFactoryHelper(this: g_pDataModel, a2: parentElementTypeSym.u.m_Id);
            v13 = v12;
            if ( v12 != nullptr )
            {
              m_pChild = v12->m_pChild;
              v15 = v11->m_pszClassname;
              pClassName = v15;
              if ( m_pChild != nullptr && _V_stricmp(s1: v15, s2: m_pChild->m_pszClassname) >= 0 )
              {
                for ( j = m_pChild->m_pSibling; j != nullptr; j = j->m_pSibling )
                {
                  if ( _V_stricmp(s1: pClassName, s2: j->m_pszClassname) < 0 )
                    break;
                  m_pChild = j;
                }
                v11->m_pSibling = m_pChild->m_pSibling;
                m_pChild->m_pSibling = v11;
              }
              else
              {
                v13->m_pChild = v11;
                v11->m_pSibling = m_pChild;
              }
            }
          }
          v11 = v11->m_pNext;
        }
        while ( v11 != nullptr );
        v10 = v20;
      }
      v20 = ++v10;
    }
    while ( (int)v10 < (int)&vec2_origin_19 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044CC70
// Name: void InstallDmElementFactories(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl InstallDmElementFactories()
{
  CDmElementFactoryHelper::InstallFactories();
}

//------------------------------------------------------------------------------
// Address: 0x0044CC80
// Name: public: virtual void CDmElementFactoryInternal::OnElementCreated(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::OnElementCreated(CDmElementFactoryInternal *this, CDmElement *pElement)
{
  int i; // esi
  IDmeElementCreated *v4; // ecx

  for ( i = 0; i < this->m_CallBackList.m_Size; ++i )
  {
    v4 = this->m_CallBackList.m_Memory.m_pMemory[i];
    v4->OnElementCreated(this: v4, a2: pElement);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044CCB0
// Name: public: virtual void CDmElementFactoryInternal::RemoveOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::RemoveOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_CallBackList,
    src: (vgui::TreeNode **)&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x0044CCD0
// Name: public: virtual void CDmElementFactoryInternal::AddOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::AddOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_CallBackList; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmeElementCreated **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  p_m_CallBackList = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_CallBackList;
  m_Size = this->m_CallBackList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (IDmeElementCreated **)p_m_CallBackList->m_pMemory;
  while ( *m_pMemory != pCallback )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_CallBackList->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_CallBackList, num: m_Size - m_nAllocationCount + 1);
    ++p_m_CallBackList[1].m_pMemory;
    v8 = p_m_CallBackList->m_pMemory;
    v9 = (int)p_m_CallBackList[1].m_pMemory - v7 - 1;
    p_m_CallBackList[1].m_nAllocationCount = (int)p_m_CallBackList->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_CallBackList->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)pCallback;
  }
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x101EC030
// Name: public: CDmElementFactoryHelper::CDmElementFactoryHelper(char const __near *,class CDmElementFactoryInternal __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmElementFactoryHelper *__thiscall CDmElementFactoryHelper::CDmElementFactoryHelper(
        CDmElementFactoryHelper *this,
        const char *classname,
        CDmElementFactoryInternal *pFactory,
        bool bIsStandardFactory)
{
  this->m_pParent = nullptr;
  this->m_pChild = nullptr;
  this->m_pSibling = nullptr;
  this->m_pNext = CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory];
  CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory] = this;
  this->m_pFactory = pFactory;
  this->m_pszClassname = classname;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101EC070
// Name: public: static void CDmElementFactoryHelper::InstallFactories(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmElementFactoryHelper::InstallFactories()
{
  CDmElementFactoryHelper *v0; // esi
  int *m_pFactory; // ebx
  const char *m_pszClassname; // eax
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int v4; // edi
  CDmElementFactoryHelper *i; // esi
  int *v6; // ebx
  const char *v7; // eax
  CUtlSymbolLarge *(__thiscall *v8)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int v9; // edi
  CDmElementFactoryHelper **v10; // eax
  CDmElementFactoryHelper *v11; // ebx
  CDmElementFactoryHelper *v12; // eax
  CDmElementFactoryHelper *v13; // esi
  CDmElementFactoryHelper *m_pChild; // edi
  const char *v15; // eax
  CDmElementFactoryHelper *j; // esi
  _DWORD v17[4]; // [esp-4h] [ebp-1Ch] BYREF
  const char *pClassName; // [esp+Ch] [ebp-Ch]
  CUtlSymbolLarge parentElementTypeSym; // [esp+10h] [ebp-8h] BYREF
  CDmElementFactoryHelper **v20; // [esp+14h] [ebp-4h]

  if ( !s_bInstalled )
  {
    v0 = CDmElementFactoryHelper::s_pHelpers[0];
    for ( s_bInstalled = true; v0 != nullptr; v0 = v0->m_pNext )
    {
      m_pFactory = (int *)v0->m_pFactory;
      g_pDataModel->AddElementFactory(this: g_pDataModel, a2: v0);
      m_pszClassname = v0->m_pszClassname;
      GetSymbol = g_pDataModel->GetSymbol;
      v4 = *m_pFactory;
      v17[0] = g_pDataModel;
      GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)v17, a3: m_pszClassname);
      (*(void (__thiscall **)(int *))(v4 + 20))(a1: m_pFactory);
    }
    for ( i = (CDmElementFactoryHelper *)dword_107C75BC; i != nullptr; i = i->m_pNext )
    {
      if ( !g_pDataModel->HasElementFactory(this: g_pDataModel, a2: i->m_pszClassname) )
      {
        v6 = (int *)i->m_pFactory;
        g_pDataModel->AddElementFactory(this: g_pDataModel, a2: i);
        if ( _V_stricmp(s1: i->m_pszClassname, s2: "DmeElement") != 0 )
        {
          v7 = i->m_pszClassname;
          v8 = g_pDataModel->GetSymbol;
          v9 = *v6;
          v17[0] = g_pDataModel;
          v8(this: g_pDataModel, result: (CUtlSymbolLarge *)v17, a3: v7);
          (*(void (__thiscall **)(int *))(v9 + 20))(a1: v6);
        }
      }
    }
    g_pDataModel->SetDefaultElementFactory(this: g_pDataModel, a2: g_CDmElement_Helper.m_pFactory);
    v10 = CDmElementFactoryHelper::s_pHelpers;
    v20 = CDmElementFactoryHelper::s_pHelpers;
    do
    {
      v11 = *v10;
      if ( *v10 != nullptr )
      {
        do
        {
          v11->m_pFactory->GetParentElementTypeSymbol(this: v11->m_pFactory, result: &parentElementTypeSym);
          if ( parentElementTypeSym.u.m_Id != -1 )
          {
            v12 = g_pDataModel->GetElementFactoryHelper(this: g_pDataModel, a2: parentElementTypeSym.u.m_Id);
            v13 = v12;
            if ( v12 != nullptr )
            {
              m_pChild = v12->m_pChild;
              v15 = v11->m_pszClassname;
              pClassName = v15;
              if ( m_pChild != nullptr && _V_stricmp(s1: v15, s2: m_pChild->m_pszClassname) >= 0 )
              {
                for ( j = m_pChild->m_pSibling; j != nullptr; j = j->m_pSibling )
                {
                  if ( _V_stricmp(s1: pClassName, s2: j->m_pszClassname) < 0 )
                    break;
                  m_pChild = j;
                }
                v11->m_pSibling = m_pChild->m_pSibling;
                m_pChild->m_pSibling = v11;
              }
              else
              {
                v13->m_pChild = v11;
                v11->m_pSibling = m_pChild;
              }
            }
          }
          v11 = v11->m_pNext;
        }
        while ( v11 != nullptr );
        v10 = v20;
      }
      v20 = ++v10;
    }
    while ( (int)v10 < (int)&vec2_origin_253 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EC230
// Name: void InstallDmElementFactories(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl InstallDmElementFactories()
{
  CDmElementFactoryHelper::InstallFactories();
}

//------------------------------------------------------------------------------
// Address: 0x101EC240
// Name: public: virtual void CDmElementFactoryInternal::OnElementCreated(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::OnElementCreated(CDmElementFactoryInternal *this, CDmElement *pElement)
{
  int i; // esi
  IDmeElementCreated *v4; // ecx

  for ( i = 0; i < this->m_CallBackList.m_Size; ++i )
  {
    v4 = this->m_CallBackList.m_Memory.m_pMemory[i];
    v4->OnElementCreated(this: v4, a2: pElement);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EC270
// Name: public: virtual void CDmElementFactoryInternal::RemoveOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::RemoveOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlVector<CMapView2D *,CUtlMemory<CMapView2D *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_CallBackList,
    src: (vgui::TreeNode *const *)&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x101EC290
// Name: public: virtual void CDmElementFactoryInternal::AddOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::AddOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_CallBackList; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmeElementCreated **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  p_m_CallBackList = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_CallBackList;
  m_Size = this->m_CallBackList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (IDmeElementCreated **)p_m_CallBackList->m_pMemory;
  while ( *m_pMemory != pCallback )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_CallBackList->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_CallBackList, num: m_Size - m_nAllocationCount + 1);
    ++p_m_CallBackList[1].m_pMemory;
    v8 = p_m_CallBackList->m_pMemory;
    v9 = (int)p_m_CallBackList[1].m_pMemory - v7 - 1;
    p_m_CallBackList[1].m_nAllocationCount = (int)p_m_CallBackList->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_CallBackList->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)pCallback;
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x00474800
// Name: public: CDmElementFactoryHelper::CDmElementFactoryHelper(char const __near *,class CDmElementFactoryInternal __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmElementFactoryHelper *__thiscall CDmElementFactoryHelper::CDmElementFactoryHelper(
        CDmElementFactoryHelper *this,
        const char *classname,
        CDmElementFactoryInternal *pFactory,
        bool bIsStandardFactory)
{
  this->m_pParent = nullptr;
  this->m_pChild = nullptr;
  this->m_pSibling = nullptr;
  this->m_pNext = CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory];
  CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory] = this;
  this->m_pFactory = pFactory;
  this->m_pszClassname = classname;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00474840
// Name: public: static void CDmElementFactoryHelper::InstallFactories(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmElementFactoryHelper::InstallFactories()
{
  CDmElementFactoryHelper *v0; // esi
  int *m_pFactory; // ebx
  const char *m_pszClassname; // eax
  void (__thiscall *v3)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD *, const char *); // edx
  int v4; // edi
  int i; // esi
  int *v6; // ebx
  int v7; // eax
  void (__thiscall *v8)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD *, int); // edx
  int v9; // edi
  CDmElementFactoryHelper **v10; // eax
  CDmElementFactoryHelper *v11; // ebx
  int v12; // eax
  int v13; // esi
  CDmElementFactoryHelper *v14; // edi
  const char *v15; // eax
  CDmElementFactoryHelper *j; // esi
  _DWORD v17[4]; // [esp-4h] [ebp-1Ch] BYREF
  const char *pClassName; // [esp+Ch] [ebp-Ch]
  CUtlSymbolLarge parentElementTypeSym; // [esp+10h] [ebp-8h] BYREF
  CDmElementFactoryHelper **v20; // [esp+14h] [ebp-4h]

  if ( !s_bInstalled )
  {
    v0 = CDmElementFactoryHelper::s_pHelpers[0];
    for ( s_bInstalled = true; v0 != nullptr; v0 = v0->m_pNext )
    {
      m_pFactory = (int *)v0->m_pFactory;
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmElementFactoryHelper *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 32))(
        a1: g_pDataModel.u,
        a2: v0);
      m_pszClassname = v0->m_pszClassname;
      v3 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 200);
      v4 = *m_pFactory;
      v17[0] = g_pDataModel.u.m_Id;
      ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v3)(
        a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
        a2: v17,
        a3: m_pszClassname);
      (*(void (__thiscall **)(int *))(v4 + 20))(a1: m_pFactory);
    }
    for ( i = dword_7D8A54; i != 0; i = *(_DWORD *)i )
    {
      if ( (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 472))(
             a1: g_pDataModel.u,
             a2: *(_DWORD *)(i + 20)) == 0 )
      {
        v6 = *(int **)(i + 16);
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 32))(
          a1: g_pDataModel.u,
          a2: i);
        if ( _V_stricmp(s1: *(const char **)(i + 20), s2: "DmeElement") != 0 )
        {
          v7 = *(_DWORD *)(i + 20);
          v8 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD *, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 200);
          v9 = *v6;
          v17[0] = g_pDataModel.u.m_Id;
          ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v8)(
            a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
            a2: v17,
            a3: v7);
          (*(void (__thiscall **)(int *))(v9 + 20))(a1: v6);
        }
      }
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmElementFactoryInternal *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 40))(
      a1: g_pDataModel.u,
      a2: g_CDmElement_Helper.m_pFactory);
    v10 = CDmElementFactoryHelper::s_pHelpers;
    v20 = CDmElementFactoryHelper::s_pHelpers;
    do
    {
      v11 = *v10;
      if ( *v10 != nullptr )
      {
        do
        {
          v11->m_pFactory->GetParentElementTypeSymbol(this: v11->m_pFactory, result: &parentElementTypeSym);
          if ( parentElementTypeSym.u.m_Id != -1 )
          {
            v12 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 36))(
                    a1: g_pDataModel.u,
                    a2: parentElementTypeSym.u);
            v13 = v12;
            if ( v12 != 0 )
            {
              v14 = *(CDmElementFactoryHelper **)(v12 + 8);
              v15 = v11->m_pszClassname;
              pClassName = v15;
              if ( v14 != nullptr && _V_stricmp(s1: v15, s2: v14->m_pszClassname) >= 0 )
              {
                for ( j = v14->m_pSibling; j != nullptr; j = j->m_pSibling )
                {
                  if ( _V_stricmp(s1: pClassName, s2: j->m_pszClassname) < 0 )
                    break;
                  v14 = j;
                }
                v11->m_pSibling = v14->m_pSibling;
                v14->m_pSibling = v11;
              }
              else
              {
                *(_DWORD *)(v13 + 8) = v11;
                v11->m_pSibling = v14;
              }
            }
          }
          v11 = v11->m_pNext;
        }
        while ( v11 != nullptr );
        v10 = v20;
      }
      v20 = ++v10;
    }
    while ( (int)v10 < (int)&vec2_origin_30 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474A00
// Name: void InstallDmElementFactories(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl InstallDmElementFactories()
{
  CDmElementFactoryHelper::InstallFactories();
}

//------------------------------------------------------------------------------
// Address: 0x00474A10
// Name: public: virtual void CDmElementFactoryInternal::OnElementCreated(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::OnElementCreated(CDmElementFactoryInternal *this, CDmElement *pElement)
{
  int i; // esi
  IDmeElementCreated *v4; // ecx

  for ( i = 0; i < this->m_CallBackList.m_Size; ++i )
  {
    v4 = this->m_CallBackList.m_Memory.m_pMemory[i];
    v4->OnElementCreated(this: v4, a2: pElement);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474AB0
// Name: public: virtual void CDmElementFactoryInternal::RemoveOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::RemoveOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(
    this: (CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int> > *)&this->m_CallBackList,
    src: (IDmNotify **)&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x00474AD0
// Name: public: virtual void CDmElementFactoryInternal::AddOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::AddOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_CallBackList; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmeElementCreated **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax

  p_m_CallBackList = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_CallBackList;
  m_Size = this->m_CallBackList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (IDmeElementCreated **)p_m_CallBackList->m_pMemory;
  while ( *m_pMemory != pCallback )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_CallBackList->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_CallBackList, num: m_Size - m_nAllocationCount + 1);
    ++p_m_CallBackList[1].m_pMemory;
    v8 = p_m_CallBackList->m_pMemory;
    v9 = (int)p_m_CallBackList[1].m_pMemory - v7 - 1;
    p_m_CallBackList[1].m_nAllocationCount = (int)p_m_CallBackList->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_CallBackList->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (CUtlSymbolTable::StringPool_t *)pCallback;
  }
}

} // namespace hlmv

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x005009B0
// Name: public: CDmElementFactoryHelper::CDmElementFactoryHelper(char const __near *,class CDmElementFactoryInternal __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmElementFactoryHelper *__thiscall CDmElementFactoryHelper::CDmElementFactoryHelper(
        CDmElementFactoryHelper *this,
        const char *classname,
        CDmElementFactoryInternal *pFactory,
        bool bIsStandardFactory)
{
  this->m_pParent = nullptr;
  this->m_pChild = nullptr;
  this->m_pSibling = nullptr;
  this->m_pNext = CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory];
  CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory] = this;
  this->m_pFactory = pFactory;
  this->m_pszClassname = classname;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005009F0
// Name: public: static void CDmElementFactoryHelper::InstallFactories(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmElementFactoryHelper::InstallFactories()
{
  CDmElementFactoryHelper *v0; // esi
  int *m_pFactory; // ebx
  const char *m_pszClassname; // eax
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int v4; // edi
  CDmElementFactoryHelper *i; // esi
  int *v6; // ebx
  const char *v7; // eax
  CUtlSymbolLarge *(__thiscall *v8)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int v9; // edi
  CDmElementFactoryHelper **v10; // eax
  CDmElementFactoryHelper *v11; // ebx
  CDmElementFactoryHelper *v12; // eax
  CDmElementFactoryHelper *v13; // esi
  CDmElementFactoryHelper *m_pChild; // edi
  const char *v15; // eax
  CDmElementFactoryHelper *j; // esi
  _DWORD v17[4]; // [esp-4h] [ebp-1Ch] BYREF
  const char *pClassName; // [esp+Ch] [ebp-Ch]
  CUtlSymbolLarge parentElementTypeSym; // [esp+10h] [ebp-8h] BYREF
  CDmElementFactoryHelper **v20; // [esp+14h] [ebp-4h]

  if ( !s_bInstalled )
  {
    v0 = CDmElementFactoryHelper::s_pHelpers[0];
    for ( s_bInstalled = true; v0 != nullptr; v0 = v0->m_pNext )
    {
      m_pFactory = (int *)v0->m_pFactory;
      g_pDataModel->AddElementFactory(this: g_pDataModel, a2: v0);
      m_pszClassname = v0->m_pszClassname;
      GetSymbol = g_pDataModel->GetSymbol;
      v4 = *m_pFactory;
      v17[0] = g_pDataModel;
      GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)v17, a3: m_pszClassname);
      (*(void (__thiscall **)(int *))(v4 + 20))(a1: m_pFactory);
    }
    for ( i = (CDmElementFactoryHelper *)dword_6909BC; i != nullptr; i = i->m_pNext )
    {
      if ( !g_pDataModel->HasElementFactory(this: g_pDataModel, a2: i->m_pszClassname) )
      {
        v6 = (int *)i->m_pFactory;
        g_pDataModel->AddElementFactory(this: g_pDataModel, a2: i);
        if ( _V_stricmp(s1: i->m_pszClassname, s2: "DmeElement") != 0 )
        {
          v7 = i->m_pszClassname;
          v8 = g_pDataModel->GetSymbol;
          v9 = *v6;
          v17[0] = g_pDataModel;
          v8(this: g_pDataModel, result: (CUtlSymbolLarge *)v17, a3: v7);
          (*(void (__thiscall **)(int *))(v9 + 20))(a1: v6);
        }
      }
    }
    g_pDataModel->SetDefaultElementFactory(this: g_pDataModel, a2: g_CDmElement_Helper.m_pFactory);
    v10 = CDmElementFactoryHelper::s_pHelpers;
    v20 = CDmElementFactoryHelper::s_pHelpers;
    do
    {
      v11 = *v10;
      if ( *v10 != nullptr )
      {
        do
        {
          v11->m_pFactory->GetParentElementTypeSymbol(this: v11->m_pFactory, result: &parentElementTypeSym);
          if ( parentElementTypeSym.u.m_Id != -1 )
          {
            v12 = g_pDataModel->GetElementFactoryHelper(this: g_pDataModel, a2: parentElementTypeSym.u.m_Id);
            v13 = v12;
            if ( v12 != nullptr )
            {
              m_pChild = v12->m_pChild;
              v15 = v11->m_pszClassname;
              pClassName = v15;
              if ( m_pChild != nullptr && _V_stricmp(s1: v15, s2: m_pChild->m_pszClassname) >= 0 )
              {
                for ( j = m_pChild->m_pSibling; j != nullptr; j = j->m_pSibling )
                {
                  if ( _V_stricmp(s1: pClassName, s2: j->m_pszClassname) < 0 )
                    break;
                  m_pChild = j;
                }
                v11->m_pSibling = m_pChild->m_pSibling;
                m_pChild->m_pSibling = v11;
              }
              else
              {
                v13->m_pChild = v11;
                v11->m_pSibling = m_pChild;
              }
            }
          }
          v11 = v11->m_pNext;
        }
        while ( v11 != nullptr );
        v10 = v20;
      }
      v20 = ++v10;
    }
    while ( (int)v10 < (int)&vec2_origin_40 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00500BB0
// Name: void InstallDmElementFactories(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl InstallDmElementFactories()
{
  CDmElementFactoryHelper::InstallFactories();
}

//------------------------------------------------------------------------------
// Address: 0x00500BC0
// Name: public: virtual void CDmElementFactoryInternal::OnElementCreated(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::OnElementCreated(CDmElementFactoryInternal *this, CDmElement *pElement)
{
  int i; // esi
  IDmeElementCreated *v4; // ecx

  for ( i = 0; i < this->m_CallBackList.m_Size; ++i )
  {
    v4 = this->m_CallBackList.m_Memory.m_pMemory[i];
    v4->OnElementCreated(this: v4, a2: pElement);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00500BF0
// Name: public: virtual void CDmElementFactoryInternal::RemoveOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::RemoveOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(
    this: (CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int> > *)&this->m_CallBackList,
    src: (IDmNotify **)&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x00500C10
// Name: public: virtual void CDmElementFactoryInternal::AddOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::AddOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlMemory<S3RGBA,int> *p_m_CallBackList; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmeElementCreated **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  S3RGBA *v8; // ecx
  int v9; // eax
  S3RGBA *v10; // eax

  p_m_CallBackList = (CUtlMemory<S3RGBA,int> *)&this->m_CallBackList;
  m_Size = this->m_CallBackList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (IDmeElementCreated **)p_m_CallBackList->m_pMemory;
  while ( *m_pMemory != pCallback )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_CallBackList->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_CallBackList, num: m_Size - m_nAllocationCount + 1);
    ++p_m_CallBackList[1].m_pMemory;
    v8 = p_m_CallBackList->m_pMemory;
    v9 = (int)p_m_CallBackList[1].m_pMemory - v7 - 1;
    p_m_CallBackList[1].m_nAllocationCount = (int)p_m_CallBackList->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_CallBackList->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (S3RGBA)pCallback;
  }
}

} // namespace makegamedata

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004C1570
// Name: public: CDmElementFactoryHelper::CDmElementFactoryHelper(char const __near *,class CDmElementFactoryInternal __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmElementFactoryHelper *__thiscall CDmElementFactoryHelper::CDmElementFactoryHelper(
        CDmElementFactoryHelper *this,
        const char *classname,
        CDmElementFactoryInternal *pFactory,
        bool bIsStandardFactory)
{
  this->m_pParent = nullptr;
  this->m_pChild = nullptr;
  this->m_pSibling = nullptr;
  this->m_pNext = CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory];
  CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory] = this;
  this->m_pFactory = pFactory;
  this->m_pszClassname = classname;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C15B0
// Name: public: static void CDmElementFactoryHelper::InstallFactories(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmElementFactoryHelper::InstallFactories()
{
  CDmElementFactoryHelper *v0; // esi
  int *m_pFactory; // ebx
  const char *m_pszClassname; // eax
  void (__thiscall *v3)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD *, const char *); // edx
  int v4; // edi
  int i; // esi
  int *v6; // ebx
  int v7; // eax
  void (__thiscall *v8)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD *, int); // edx
  int v9; // edi
  CDmElementFactoryHelper **v10; // eax
  CDmElementFactoryHelper *v11; // ebx
  int v12; // eax
  int v13; // esi
  CDmElementFactoryHelper *v14; // edi
  const char *v15; // eax
  CDmElementFactoryHelper *j; // esi
  _DWORD v17[4]; // [esp-4h] [ebp-1Ch] BYREF
  const char *pClassName; // [esp+Ch] [ebp-Ch]
  CUtlSymbolLarge parentElementTypeSym; // [esp+10h] [ebp-8h] BYREF
  CDmElementFactoryHelper **v20; // [esp+14h] [ebp-4h]

  if ( !s_bInstalled )
  {
    v0 = CDmElementFactoryHelper::s_pHelpers[0];
    for ( s_bInstalled = true; v0 != nullptr; v0 = v0->m_pNext )
    {
      m_pFactory = (int *)v0->m_pFactory;
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmElementFactoryHelper *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 32))(
        a1: g_pDataModel.u,
        a2: v0);
      m_pszClassname = v0->m_pszClassname;
      v3 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 200);
      v4 = *m_pFactory;
      v17[0] = g_pDataModel.u.m_Id;
      ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v3)(
        a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
        a2: v17,
        a3: m_pszClassname);
      (*(void (__thiscall **)(int *))(v4 + 20))(a1: m_pFactory);
    }
    for ( i = dword_3ADFA60; i != 0; i = *(_DWORD *)i )
    {
      if ( (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 472))(
             a1: g_pDataModel.u,
             a2: *(_DWORD *)(i + 20)) == 0 )
      {
        v6 = *(int **)(i + 16);
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 32))(
          a1: g_pDataModel.u,
          a2: i);
        if ( _V_stricmp(s1: *(const char **)(i + 20), s2: "DmeElement") != 0 )
        {
          v7 = *(_DWORD *)(i + 20);
          v8 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD *, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 200);
          v9 = *v6;
          v17[0] = g_pDataModel.u.m_Id;
          ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v8)(
            a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
            a2: v17,
            a3: v7);
          (*(void (__thiscall **)(int *))(v9 + 20))(a1: v6);
        }
      }
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmElementFactoryInternal *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 40))(
      a1: g_pDataModel.u,
      a2: g_CDmElement_Helper.m_pFactory);
    v10 = CDmElementFactoryHelper::s_pHelpers;
    v20 = CDmElementFactoryHelper::s_pHelpers;
    do
    {
      v11 = *v10;
      if ( *v10 != nullptr )
      {
        do
        {
          v11->m_pFactory->GetParentElementTypeSymbol(this: v11->m_pFactory, result: &parentElementTypeSym);
          if ( parentElementTypeSym.u.m_Id != -1 )
          {
            v12 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 36))(
                    a1: g_pDataModel.u,
                    a2: parentElementTypeSym.u);
            v13 = v12;
            if ( v12 != 0 )
            {
              v14 = *(CDmElementFactoryHelper **)(v12 + 8);
              v15 = v11->m_pszClassname;
              pClassName = v15;
              if ( v14 != nullptr && _V_stricmp(s1: v15, s2: v14->m_pszClassname) >= 0 )
              {
                for ( j = v14->m_pSibling; j != nullptr; j = j->m_pSibling )
                {
                  if ( _V_stricmp(s1: pClassName, s2: j->m_pszClassname) < 0 )
                    break;
                  v14 = j;
                }
                v11->m_pSibling = v14->m_pSibling;
                v14->m_pSibling = v11;
              }
              else
              {
                *(_DWORD *)(v13 + 8) = v11;
                v11->m_pSibling = v14;
              }
            }
          }
          v11 = v11->m_pNext;
        }
        while ( v11 != nullptr );
        v10 = v20;
      }
      v20 = ++v10;
    }
    while ( (int)v10 < (int)&vec2_origin_40 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C1770
// Name: void InstallDmElementFactories(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl InstallDmElementFactories()
{
  CDmElementFactoryHelper::InstallFactories();
}

//------------------------------------------------------------------------------
// Address: 0x004C1780
// Name: public: virtual void CDmElementFactoryInternal::OnElementCreated(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::OnElementCreated(CDmElementFactoryInternal *this, CDmElement *pElement)
{
  int i; // esi
  IDmeElementCreated *v4; // ecx

  for ( i = 0; i < this->m_CallBackList.m_Size; ++i )
  {
    v4 = this->m_CallBackList.m_Memory.m_pMemory[i];
    v4->OnElementCreated(this: v4, a2: pElement);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C17B0
// Name: public: virtual void CDmElementFactoryInternal::RemoveOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::RemoveOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(
    this: (CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int> > *)&this->m_CallBackList,
    src: (IDmNotify **)&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x004C17D0
// Name: public: virtual void CDmElementFactoryInternal::AddOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::AddOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_CallBackList; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmeElementCreated **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax

  p_m_CallBackList = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_CallBackList;
  m_Size = this->m_CallBackList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (IDmeElementCreated **)p_m_CallBackList->m_pMemory;
  while ( *m_pMemory != pCallback )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_CallBackList->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_CallBackList, num: m_Size - m_nAllocationCount + 1);
    ++p_m_CallBackList[1].m_pMemory;
    v8 = p_m_CallBackList->m_pMemory;
    v9 = (int)p_m_CallBackList[1].m_pMemory - v7 - 1;
    p_m_CallBackList[1].m_nAllocationCount = (int)p_m_CallBackList->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_CallBackList->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (CUtlSymbolTable::StringPool_t *)pCallback;
  }
}

} // namespace mdlcompile

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x00446000
// Name: public: CDmElementFactoryHelper::CDmElementFactoryHelper(char const __near *,class CDmElementFactoryInternal __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmElementFactoryHelper *__thiscall CDmElementFactoryHelper::CDmElementFactoryHelper(
        CDmElementFactoryHelper *this,
        const char *classname,
        CDmElementFactoryInternal *pFactory,
        bool bIsStandardFactory)
{
  this->m_pParent = nullptr;
  this->m_pChild = nullptr;
  this->m_pSibling = nullptr;
  this->m_pNext = CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory];
  CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory] = this;
  this->m_pFactory = pFactory;
  this->m_pszClassname = classname;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00446040
// Name: public: static void CDmElementFactoryHelper::InstallFactories(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmElementFactoryHelper::InstallFactories()
{
  CDmElementFactoryHelper *v0; // esi
  int *m_pFactory; // ebx
  const char *m_pszClassname; // eax
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int v4; // edi
  CDmElementFactoryHelper *i; // esi
  int *v6; // ebx
  const char *v7; // eax
  CUtlSymbolLarge *(__thiscall *v8)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int v9; // edi
  CDmElementFactoryHelper **v10; // eax
  CDmElementFactoryHelper *v11; // ebx
  CDmElementFactoryHelper *v12; // eax
  CDmElementFactoryHelper *v13; // esi
  CDmElementFactoryHelper *m_pChild; // edi
  const char *v15; // eax
  CDmElementFactoryHelper *j; // esi
  _DWORD v17[4]; // [esp-4h] [ebp-1Ch] BYREF
  const char *pClassName; // [esp+Ch] [ebp-Ch]
  CUtlSymbolLarge parentElementTypeSym; // [esp+10h] [ebp-8h] BYREF
  CDmElementFactoryHelper **v20; // [esp+14h] [ebp-4h]

  if ( !s_bInstalled )
  {
    v0 = CDmElementFactoryHelper::s_pHelpers[0];
    for ( s_bInstalled = true; v0 != nullptr; v0 = v0->m_pNext )
    {
      m_pFactory = (int *)v0->m_pFactory;
      g_pDataModel->AddElementFactory(this: g_pDataModel, a2: v0);
      m_pszClassname = v0->m_pszClassname;
      GetSymbol = g_pDataModel->GetSymbol;
      v4 = *m_pFactory;
      v17[0] = g_pDataModel;
      GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)v17, a3: m_pszClassname);
      (*(void (__thiscall **)(int *))(v4 + 20))(a1: m_pFactory);
    }
    for ( i = (CDmElementFactoryHelper *)dword_531B14; i != nullptr; i = i->m_pNext )
    {
      if ( !g_pDataModel->HasElementFactory(this: g_pDataModel, a2: i->m_pszClassname) )
      {
        v6 = (int *)i->m_pFactory;
        g_pDataModel->AddElementFactory(this: g_pDataModel, a2: i);
        if ( _V_stricmp(s1: i->m_pszClassname, s2: "DmeElement") != 0 )
        {
          v7 = i->m_pszClassname;
          v8 = g_pDataModel->GetSymbol;
          v9 = *v6;
          v17[0] = g_pDataModel;
          v8(this: g_pDataModel, result: (CUtlSymbolLarge *)v17, a3: v7);
          (*(void (__thiscall **)(int *))(v9 + 20))(a1: v6);
        }
      }
    }
    g_pDataModel->SetDefaultElementFactory(this: g_pDataModel, a2: g_CDmElement_Helper.m_pFactory);
    v10 = CDmElementFactoryHelper::s_pHelpers;
    v20 = CDmElementFactoryHelper::s_pHelpers;
    do
    {
      v11 = *v10;
      if ( *v10 != nullptr )
      {
        do
        {
          v11->m_pFactory->GetParentElementTypeSymbol(this: v11->m_pFactory, result: &parentElementTypeSym);
          if ( parentElementTypeSym.u.m_Id != -1 )
          {
            v12 = g_pDataModel->GetElementFactoryHelper(this: g_pDataModel, a2: parentElementTypeSym.u.m_Id);
            v13 = v12;
            if ( v12 != nullptr )
            {
              m_pChild = v12->m_pChild;
              v15 = v11->m_pszClassname;
              pClassName = v15;
              if ( m_pChild != nullptr && _V_stricmp(s1: v15, s2: m_pChild->m_pszClassname) >= 0 )
              {
                for ( j = m_pChild->m_pSibling; j != nullptr; j = j->m_pSibling )
                {
                  if ( _V_stricmp(s1: pClassName, s2: j->m_pszClassname) < 0 )
                    break;
                  m_pChild = j;
                }
                v11->m_pSibling = m_pChild->m_pSibling;
                m_pChild->m_pSibling = v11;
              }
              else
              {
                v13->m_pChild = v11;
                v11->m_pSibling = m_pChild;
              }
            }
          }
          v11 = v11->m_pNext;
        }
        while ( v11 != nullptr );
        v10 = v20;
      }
      v20 = ++v10;
    }
    while ( (int)v10 < (int)&vec2_origin_13 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00446200
// Name: void InstallDmElementFactories(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl InstallDmElementFactories()
{
  CDmElementFactoryHelper::InstallFactories();
}

//------------------------------------------------------------------------------
// Address: 0x004462A0
// Name: public: virtual void CDmElementFactoryInternal::OnElementCreated(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::OnElementCreated(CDmElementFactoryInternal *this, CDmElement *pElement)
{
  int i; // esi
  IDmeElementCreated *v4; // ecx

  for ( i = 0; i < this->m_CallBackList.m_Size; ++i )
  {
    v4 = this->m_CallBackList.m_Memory.m_pMemory[i];
    v4->OnElementCreated(this: v4, a2: pElement);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004462D0
// Name: public: virtual void CDmElementFactoryInternal::RemoveOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::RemoveOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(
    this: (CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int> > *)&this->m_CallBackList,
    src: (IDmNotify **)&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x004462F0
// Name: public: virtual void CDmElementFactoryInternal::AddOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::AddOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_CallBackList; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmeElementCreated **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax

  p_m_CallBackList = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_CallBackList;
  m_Size = this->m_CallBackList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (IDmeElementCreated **)p_m_CallBackList->m_pMemory;
  while ( *m_pMemory != pCallback )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_CallBackList->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_CallBackList, num: m_Size - m_nAllocationCount + 1);
    ++p_m_CallBackList[1].m_pMemory;
    v8 = p_m_CallBackList->m_pMemory;
    v9 = (int)p_m_CallBackList[1].m_pMemory - v7 - 1;
    p_m_CallBackList[1].m_nAllocationCount = (int)p_m_CallBackList->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_CallBackList->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (CUtlSymbolTable::StringPool_t *)pCallback;
  }
}

} // namespace mksheet

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0043F360
// Name: public: CDmElementFactoryHelper::CDmElementFactoryHelper(char const __near *,class CDmElementFactoryInternal __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmElementFactoryHelper *__thiscall CDmElementFactoryHelper::CDmElementFactoryHelper(
        CDmElementFactoryHelper *this,
        const char *classname,
        CDmElementFactoryInternal *pFactory,
        bool bIsStandardFactory)
{
  this->m_pParent = nullptr;
  this->m_pChild = nullptr;
  this->m_pSibling = nullptr;
  this->m_pNext = CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory];
  CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory] = this;
  this->m_pFactory = pFactory;
  this->m_pszClassname = classname;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043F3A0
// Name: public: static void CDmElementFactoryHelper::InstallFactories(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmElementFactoryHelper::InstallFactories()
{
  CDmElementFactoryHelper *v0; // esi
  int *m_pFactory; // ebx
  const char *m_pszClassname; // eax
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int v4; // edi
  CDmElementFactoryHelper *i; // esi
  int *v6; // ebx
  const char *v7; // eax
  CUtlSymbolLarge *(__thiscall *v8)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int v9; // edi
  CDmElementFactoryHelper **v10; // eax
  CDmElementFactoryHelper *v11; // ebx
  CDmElementFactoryHelper *v12; // eax
  CDmElementFactoryHelper *v13; // esi
  CDmElementFactoryHelper *m_pChild; // edi
  const char *v15; // eax
  CDmElementFactoryHelper *j; // esi
  _DWORD v17[4]; // [esp-4h] [ebp-1Ch] BYREF
  const char *pClassName; // [esp+Ch] [ebp-Ch]
  CUtlSymbolLarge parentElementTypeSym; // [esp+10h] [ebp-8h] BYREF
  CDmElementFactoryHelper **v20; // [esp+14h] [ebp-4h]

  if ( !s_bInstalled )
  {
    v0 = CDmElementFactoryHelper::s_pHelpers[0];
    for ( s_bInstalled = true; v0 != nullptr; v0 = v0->m_pNext )
    {
      m_pFactory = (int *)v0->m_pFactory;
      g_pDataModel->AddElementFactory(this: g_pDataModel, a2: v0);
      m_pszClassname = v0->m_pszClassname;
      GetSymbol = g_pDataModel->GetSymbol;
      v4 = *m_pFactory;
      v17[0] = g_pDataModel;
      GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)v17, a3: m_pszClassname);
      (*(void (__thiscall **)(int *))(v4 + 20))(a1: m_pFactory);
    }
    for ( i = (CDmElementFactoryHelper *)dword_5C8644; i != nullptr; i = i->m_pNext )
    {
      if ( !g_pDataModel->HasElementFactory(this: g_pDataModel, a2: i->m_pszClassname) )
      {
        v6 = (int *)i->m_pFactory;
        g_pDataModel->AddElementFactory(this: g_pDataModel, a2: i);
        if ( _V_stricmp(s1: i->m_pszClassname, s2: "DmeElement") != 0 )
        {
          v7 = i->m_pszClassname;
          v8 = g_pDataModel->GetSymbol;
          v9 = *v6;
          v17[0] = g_pDataModel;
          v8(this: g_pDataModel, result: (CUtlSymbolLarge *)v17, a3: v7);
          (*(void (__thiscall **)(int *))(v9 + 20))(a1: v6);
        }
      }
    }
    g_pDataModel->SetDefaultElementFactory(this: g_pDataModel, a2: g_CDmElement_Helper.m_pFactory);
    v10 = CDmElementFactoryHelper::s_pHelpers;
    v20 = CDmElementFactoryHelper::s_pHelpers;
    do
    {
      v11 = *v10;
      if ( *v10 != nullptr )
      {
        do
        {
          v11->m_pFactory->GetParentElementTypeSymbol(this: v11->m_pFactory, result: &parentElementTypeSym);
          if ( parentElementTypeSym.u.m_Id != -1 )
          {
            v12 = g_pDataModel->GetElementFactoryHelper(this: g_pDataModel, a2: parentElementTypeSym.u.m_Id);
            v13 = v12;
            if ( v12 != nullptr )
            {
              m_pChild = v12->m_pChild;
              v15 = v11->m_pszClassname;
              pClassName = v15;
              if ( m_pChild != nullptr && _V_stricmp(s1: v15, s2: m_pChild->m_pszClassname) >= 0 )
              {
                for ( j = m_pChild->m_pSibling; j != nullptr; j = j->m_pSibling )
                {
                  if ( _V_stricmp(s1: pClassName, s2: j->m_pszClassname) < 0 )
                    break;
                  m_pChild = j;
                }
                v11->m_pSibling = m_pChild->m_pSibling;
                m_pChild->m_pSibling = v11;
              }
              else
              {
                v13->m_pChild = v11;
                v11->m_pSibling = m_pChild;
              }
            }
          }
          v11 = v11->m_pNext;
        }
        while ( v11 != nullptr );
        v10 = v20;
      }
      v20 = ++v10;
    }
    while ( (int)v10 < (int)&vec2_origin_10 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043F560
// Name: void InstallDmElementFactories(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl InstallDmElementFactories()
{
  CDmElementFactoryHelper::InstallFactories();
}

//------------------------------------------------------------------------------
// Address: 0x0043F570
// Name: public: virtual void CDmElementFactoryInternal::OnElementCreated(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::OnElementCreated(CDmElementFactoryInternal *this, CDmElement *pElement)
{
  int i; // esi
  IDmeElementCreated *v4; // ecx

  for ( i = 0; i < this->m_CallBackList.m_Size; ++i )
  {
    v4 = this->m_CallBackList.m_Memory.m_pMemory[i];
    v4->OnElementCreated(this: v4, a2: pElement);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043F610
// Name: public: virtual void CDmElementFactoryInternal::RemoveOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::RemoveOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(
    this: (CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int> > *)&this->m_CallBackList,
    src: (IDmNotify **)&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x0043F630
// Name: public: virtual void CDmElementFactoryInternal::AddOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::AddOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_CallBackList; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmeElementCreated **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax

  p_m_CallBackList = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_CallBackList;
  m_Size = this->m_CallBackList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (IDmeElementCreated **)p_m_CallBackList->m_pMemory;
  while ( *m_pMemory != pCallback )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_CallBackList->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_CallBackList, num: m_Size - m_nAllocationCount + 1);
    ++p_m_CallBackList[1].m_pMemory;
    v8 = p_m_CallBackList->m_pMemory;
    v9 = (int)p_m_CallBackList[1].m_pMemory - v7 - 1;
    p_m_CallBackList[1].m_nAllocationCount = (int)p_m_CallBackList->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_CallBackList->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (CUtlSymbolTable::StringPool_t *)pCallback;
  }
}

} // namespace particle_import

// ============================================================
// Overlay from pcffix (Missing functions)
// ============================================================
namespace pcffix {

//------------------------------------------------------------------------------
// Address: 0x0043CFF0
// Name: public: CDmElementFactoryHelper::CDmElementFactoryHelper(char const __near *,class IDmElementFactoryInternal __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmElementFactoryHelper *__thiscall CDmElementFactoryHelper::CDmElementFactoryHelper(
        CDmElementFactoryHelper *this,
        const char *classname,
        IDmElementFactoryInternal *pFactory,
        bool bIsStandardFactory)
{
  this->m_pNext = CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory];
  CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory] = this;
  this->m_pFactory = pFactory;
  this->m_pszClassname = classname;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043D020
// Name: public: static void CDmElementFactoryHelper::InstallFactories(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmElementFactoryHelper::InstallFactories()
{
  CDmElementFactoryHelper *i; // esi
  IDmElementFactoryInternal *m_pFactory; // edi
  unsigned __int16 v2; // ax
  __int16 v3; // ecx^2
  int j; // esi
  int v5; // ecx
  int v6; // edi
  int v7; // [esp-4h] [ebp-10h]

  for ( i = CDmElementFactoryHelper::s_pHelpers[0]; i != nullptr; i = i->m_pNext )
  {
    if ( !i->m_pFactory->IsAbstract(this: i->m_pFactory) )
      g_pDataModel->AddElementFactory(this: g_pDataModel, a2: i->m_pszClassname, a3: i->m_pFactory);
    m_pFactory = i->m_pFactory;
    v2 = g_pDataModel->GetSymbol(this: g_pDataModel, a2: i->m_pszClassname);
    HIWORD(v7) = v3;
    LOWORD(v7) = v2;
    ((void (__thiscall *)(IDmElementFactoryInternal *, int))m_pFactory->SetElementTypeSymbol)(a1: m_pFactory, a2: v7);
  }
  for ( j = dword_48682C; j != 0; j = *(_DWORD *)j )
  {
    if ( !g_pDataModel->HasElementFactory(this: g_pDataModel, a2: *(const char **)(j + 8)) )
    {
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(j + 4) + 12))(a1: *(_DWORD *)(j + 4)) == 0 )
        g_pDataModel->AddElementFactory(
          this: g_pDataModel,
          a2: *(const char **)(j + 8),
          a3: *(IDmElementFactory **)(j + 4));
      if ( _stricmp(dst: *(const char **)(j + 8), src: "DmeElement") != 0 )
      {
        v6 = *(_DWORD *)(j + 4);
        ((void (__thiscall *)(IDataModel *, _DWORD, int))g_pDataModel->GetSymbol)(
          a1: g_pDataModel,
          a2: *(_DWORD *)(j + 8),
          a3: v5);
        (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
      }
    }
  }
  g_pDataModel->SetDefaultElementFactory(this: g_pDataModel, a2: g_CDmElement_Helper.m_pFactory);
}

//------------------------------------------------------------------------------
// Address: 0x0043D130
// Name: void InstallDmElementFactories(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl InstallDmElementFactories()
{
  CDmElementFactoryHelper::InstallFactories();
}

} // namespace pcffix

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x0043D770
// Name: public: CDmElementFactoryHelper::CDmElementFactoryHelper(char const __near *,class CDmElementFactoryInternal __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmElementFactoryHelper *__thiscall CDmElementFactoryHelper::CDmElementFactoryHelper(
        CDmElementFactoryHelper *this,
        const char *classname,
        CDmElementFactoryInternal *pFactory,
        bool bIsStandardFactory)
{
  this->m_pParent = nullptr;
  this->m_pChild = nullptr;
  this->m_pSibling = nullptr;
  this->m_pNext = CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory];
  CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory] = this;
  this->m_pFactory = pFactory;
  this->m_pszClassname = classname;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043D7B0
// Name: public: static void CDmElementFactoryHelper::InstallFactories(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmElementFactoryHelper::InstallFactories()
{
  CDmElementFactoryHelper *v0; // esi
  int *m_pFactory; // ebx
  const char *m_pszClassname; // eax
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int v4; // edi
  CDmElementFactoryHelper *i; // esi
  int *v6; // ebx
  const char *v7; // eax
  CUtlSymbolLarge *(__thiscall *v8)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int v9; // edi
  CDmElementFactoryHelper **v10; // eax
  CDmElementFactoryHelper *v11; // ebx
  CDmElementFactoryHelper *v12; // eax
  CDmElementFactoryHelper *v13; // esi
  CDmElementFactoryHelper *m_pChild; // edi
  const char *v15; // eax
  CDmElementFactoryHelper *j; // esi
  _DWORD v17[4]; // [esp-4h] [ebp-1Ch] BYREF
  const char *pClassName; // [esp+Ch] [ebp-Ch]
  CUtlSymbolLarge parentElementTypeSym; // [esp+10h] [ebp-8h] BYREF
  CDmElementFactoryHelper **v20; // [esp+14h] [ebp-4h]

  if ( !s_bInstalled )
  {
    v0 = CDmElementFactoryHelper::s_pHelpers[0];
    for ( s_bInstalled = true; v0 != nullptr; v0 = v0->m_pNext )
    {
      m_pFactory = (int *)v0->m_pFactory;
      g_pDataModel->AddElementFactory(this: g_pDataModel, a2: v0);
      m_pszClassname = v0->m_pszClassname;
      GetSymbol = g_pDataModel->GetSymbol;
      v4 = *m_pFactory;
      v17[0] = g_pDataModel;
      GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)v17, a3: m_pszClassname);
      (*(void (__thiscall **)(int *))(v4 + 20))(a1: m_pFactory);
    }
    for ( i = (CDmElementFactoryHelper *)dword_4BB91C; i != nullptr; i = i->m_pNext )
    {
      if ( !g_pDataModel->HasElementFactory(this: g_pDataModel, a2: i->m_pszClassname) )
      {
        v6 = (int *)i->m_pFactory;
        g_pDataModel->AddElementFactory(this: g_pDataModel, a2: i);
        if ( _V_stricmp(s1: i->m_pszClassname, s2: "DmeElement") != 0 )
        {
          v7 = i->m_pszClassname;
          v8 = g_pDataModel->GetSymbol;
          v9 = *v6;
          v17[0] = g_pDataModel;
          v8(this: g_pDataModel, result: (CUtlSymbolLarge *)v17, a3: v7);
          (*(void (__thiscall **)(int *))(v9 + 20))(a1: v6);
        }
      }
    }
    g_pDataModel->SetDefaultElementFactory(this: g_pDataModel, a2: g_CDmElement_Helper.m_pFactory);
    v10 = CDmElementFactoryHelper::s_pHelpers;
    v20 = CDmElementFactoryHelper::s_pHelpers;
    do
    {
      v11 = *v10;
      if ( *v10 != nullptr )
      {
        do
        {
          v11->m_pFactory->GetParentElementTypeSymbol(this: v11->m_pFactory, result: &parentElementTypeSym);
          if ( parentElementTypeSym.u.m_Id != -1 )
          {
            v12 = g_pDataModel->GetElementFactoryHelper(this: g_pDataModel, a2: parentElementTypeSym.u.m_Id);
            v13 = v12;
            if ( v12 != nullptr )
            {
              m_pChild = v12->m_pChild;
              v15 = v11->m_pszClassname;
              pClassName = v15;
              if ( m_pChild != nullptr && _V_stricmp(s1: v15, s2: m_pChild->m_pszClassname) >= 0 )
              {
                for ( j = m_pChild->m_pSibling; j != nullptr; j = j->m_pSibling )
                {
                  if ( _V_stricmp(s1: pClassName, s2: j->m_pszClassname) < 0 )
                    break;
                  m_pChild = j;
                }
                v11->m_pSibling = m_pChild->m_pSibling;
                m_pChild->m_pSibling = v11;
              }
              else
              {
                v13->m_pChild = v11;
                v11->m_pSibling = m_pChild;
              }
            }
          }
          v11 = v11->m_pNext;
        }
        while ( v11 != nullptr );
        v10 = v20;
      }
      v20 = ++v10;
    }
    while ( (int)v10 < (int)&vec2_origin_8 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043D970
// Name: void InstallDmElementFactories(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl InstallDmElementFactories()
{
  CDmElementFactoryHelper::InstallFactories();
}

//------------------------------------------------------------------------------
// Address: 0x0043D980
// Name: public: virtual void CDmElementFactoryInternal::OnElementCreated(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::OnElementCreated(CDmElementFactoryInternal *this, CDmElement *pElement)
{
  int i; // esi
  IDmeElementCreated *v4; // ecx

  for ( i = 0; i < this->m_CallBackList.m_Size; ++i )
  {
    v4 = this->m_CallBackList.m_Memory.m_pMemory[i];
    v4->OnElementCreated(this: v4, a2: pElement);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043D9B0
// Name: public: virtual void CDmElementFactoryInternal::RemoveOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::RemoveOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(
    this: (CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int> > *)&this->m_CallBackList,
    src: (IDmNotify **)&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x0043D9D0
// Name: public: virtual void CDmElementFactoryInternal::AddOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::AddOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_CallBackList; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmeElementCreated **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax

  p_m_CallBackList = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_CallBackList;
  m_Size = this->m_CallBackList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (IDmeElementCreated **)p_m_CallBackList->m_pMemory;
  while ( *m_pMemory != pCallback )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_CallBackList->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_CallBackList, num: m_Size - m_nAllocationCount + 1);
    ++p_m_CallBackList[1].m_pMemory;
    v8 = p_m_CallBackList->m_pMemory;
    v9 = (int)p_m_CallBackList[1].m_pMemory - v7 - 1;
    p_m_CallBackList[1].m_nAllocationCount = (int)p_m_CallBackList->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_CallBackList->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (CUtlSymbolTable::StringPool_t *)pCallback;
  }
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00442B10
// Name: public: CDmElementFactoryHelper::CDmElementFactoryHelper(char const __near *,class CDmElementFactoryInternal __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmElementFactoryHelper *__thiscall CDmElementFactoryHelper::CDmElementFactoryHelper(
        CDmElementFactoryHelper *this,
        const char *classname,
        CDmElementFactoryInternal *pFactory,
        bool bIsStandardFactory)
{
  this->m_pParent = nullptr;
  this->m_pChild = nullptr;
  this->m_pSibling = nullptr;
  this->m_pNext = CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory];
  CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory] = this;
  this->m_pFactory = pFactory;
  this->m_pszClassname = classname;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00442B50
// Name: public: static void CDmElementFactoryHelper::InstallFactories(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmElementFactoryHelper::InstallFactories()
{
  CDmElementFactoryHelper *v0; // esi
  int *m_pFactory; // ebx
  const char *m_pszClassname; // eax
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int v4; // edi
  CDmElementFactoryHelper *i; // esi
  int *v6; // ebx
  const char *v7; // eax
  CUtlSymbolLarge *(__thiscall *v8)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int v9; // edi
  CDmElementFactoryHelper **v10; // eax
  CDmElementFactoryHelper *v11; // ebx
  CDmElementFactoryHelper *v12; // eax
  CDmElementFactoryHelper *v13; // esi
  CDmElementFactoryHelper *m_pChild; // edi
  const char *v15; // eax
  CDmElementFactoryHelper *j; // esi
  _DWORD v17[4]; // [esp-4h] [ebp-1Ch] BYREF
  const char *pClassName; // [esp+Ch] [ebp-Ch]
  CUtlSymbolLarge parentElementTypeSym; // [esp+10h] [ebp-8h] BYREF
  CDmElementFactoryHelper **v20; // [esp+14h] [ebp-4h]

  if ( !s_bInstalled )
  {
    v0 = CDmElementFactoryHelper::s_pHelpers[0];
    for ( s_bInstalled = true; v0 != nullptr; v0 = v0->m_pNext )
    {
      m_pFactory = (int *)v0->m_pFactory;
      g_pDataModel->AddElementFactory(this: g_pDataModel, a2: v0);
      m_pszClassname = v0->m_pszClassname;
      GetSymbol = g_pDataModel->GetSymbol;
      v4 = *m_pFactory;
      v17[0] = g_pDataModel;
      GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)v17, a3: m_pszClassname);
      (*(void (__thiscall **)(int *))(v4 + 20))(a1: m_pFactory);
    }
    for ( i = (CDmElementFactoryHelper *)dword_5D47E0; i != nullptr; i = i->m_pNext )
    {
      if ( !g_pDataModel->HasElementFactory(this: g_pDataModel, a2: i->m_pszClassname) )
      {
        v6 = (int *)i->m_pFactory;
        g_pDataModel->AddElementFactory(this: g_pDataModel, a2: i);
        if ( _V_stricmp(s1: i->m_pszClassname, s2: "DmeElement") != 0 )
        {
          v7 = i->m_pszClassname;
          v8 = g_pDataModel->GetSymbol;
          v9 = *v6;
          v17[0] = g_pDataModel;
          v8(this: g_pDataModel, result: (CUtlSymbolLarge *)v17, a3: v7);
          (*(void (__thiscall **)(int *))(v9 + 20))(a1: v6);
        }
      }
    }
    g_pDataModel->SetDefaultElementFactory(this: g_pDataModel, a2: g_CDmElement_Helper.m_pFactory);
    v10 = CDmElementFactoryHelper::s_pHelpers;
    v20 = CDmElementFactoryHelper::s_pHelpers;
    do
    {
      v11 = *v10;
      if ( *v10 != nullptr )
      {
        do
        {
          v11->m_pFactory->GetParentElementTypeSymbol(this: v11->m_pFactory, result: &parentElementTypeSym);
          if ( parentElementTypeSym.u.m_Id != -1 )
          {
            v12 = g_pDataModel->GetElementFactoryHelper(this: g_pDataModel, a2: parentElementTypeSym.u.m_Id);
            v13 = v12;
            if ( v12 != nullptr )
            {
              m_pChild = v12->m_pChild;
              v15 = v11->m_pszClassname;
              pClassName = v15;
              if ( m_pChild != nullptr && _V_stricmp(s1: v15, s2: m_pChild->m_pszClassname) >= 0 )
              {
                for ( j = m_pChild->m_pSibling; j != nullptr; j = j->m_pSibling )
                {
                  if ( _V_stricmp(s1: pClassName, s2: j->m_pszClassname) < 0 )
                    break;
                  m_pChild = j;
                }
                v11->m_pSibling = m_pChild->m_pSibling;
                m_pChild->m_pSibling = v11;
              }
              else
              {
                v13->m_pChild = v11;
                v11->m_pSibling = m_pChild;
              }
            }
          }
          v11 = v11->m_pNext;
        }
        while ( v11 != nullptr );
        v10 = v20;
      }
      v20 = ++v10;
    }
    while ( (int)v10 < (int)&vec2_origin_11 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00442D10
// Name: void InstallDmElementFactories(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl InstallDmElementFactories()
{
  CDmElementFactoryHelper::InstallFactories();
}

//------------------------------------------------------------------------------
// Address: 0x00442D20
// Name: public: virtual void CDmElementFactoryInternal::OnElementCreated(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::OnElementCreated(CDmElementFactoryInternal *this, CDmElement *pElement)
{
  int i; // esi
  IDmeElementCreated *v4; // ecx

  for ( i = 0; i < this->m_CallBackList.m_Size; ++i )
  {
    v4 = this->m_CallBackList.m_Memory.m_pMemory[i];
    v4->OnElementCreated(this: v4, a2: pElement);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00442D50
// Name: public: virtual void CDmElementFactoryInternal::RemoveOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::RemoveOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(
    this: (CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int> > *)&this->m_CallBackList,
    src: (IDmNotify **)&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x00442D70
// Name: public: virtual void CDmElementFactoryInternal::AddOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::AddOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_CallBackList; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmeElementCreated **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax

  p_m_CallBackList = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_CallBackList;
  m_Size = this->m_CallBackList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (IDmeElementCreated **)p_m_CallBackList->m_pMemory;
  while ( *m_pMemory != pCallback )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_CallBackList->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_CallBackList, num: m_Size - m_nAllocationCount + 1);
    ++p_m_CallBackList[1].m_pMemory;
    v8 = p_m_CallBackList->m_pMemory;
    v9 = (int)p_m_CallBackList[1].m_pMemory - v7 - 1;
    p_m_CallBackList[1].m_nAllocationCount = (int)p_m_CallBackList->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_CallBackList->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (CUtlSymbolTable::StringPool_t *)pCallback;
  }
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0044FF80
// Name: public: CDmElementFactoryHelper::CDmElementFactoryHelper(char const __near *,class CDmElementFactoryInternal __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmElementFactoryHelper *__thiscall CDmElementFactoryHelper::CDmElementFactoryHelper(
        CDmElementFactoryHelper *this,
        const char *classname,
        CDmElementFactoryInternal *pFactory,
        bool bIsStandardFactory)
{
  this->m_pParent = nullptr;
  this->m_pChild = nullptr;
  this->m_pSibling = nullptr;
  this->m_pNext = CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory];
  CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory] = this;
  this->m_pFactory = pFactory;
  this->m_pszClassname = classname;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044FFC0
// Name: public: static void CDmElementFactoryHelper::InstallFactories(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmElementFactoryHelper::InstallFactories()
{
  CDmElementFactoryHelper *v0; // esi
  int *m_pFactory; // ebx
  const char *m_pszClassname; // eax
  void (__thiscall *v3)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD *, const char *); // edx
  int v4; // edi
  int i; // esi
  int *v6; // ebx
  int v7; // eax
  void (__thiscall *v8)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD *, int); // edx
  int v9; // edi
  CDmElementFactoryHelper **v10; // eax
  CDmElementFactoryHelper *v11; // ebx
  int v12; // eax
  int v13; // esi
  CDmElementFactoryHelper *v14; // edi
  const char *v15; // eax
  CDmElementFactoryHelper *j; // esi
  _DWORD v17[4]; // [esp-4h] [ebp-1Ch] BYREF
  const char *pClassName; // [esp+Ch] [ebp-Ch]
  CUtlSymbolLarge parentElementTypeSym; // [esp+10h] [ebp-8h] BYREF
  CDmElementFactoryHelper **v20; // [esp+14h] [ebp-4h]

  if ( !s_bInstalled )
  {
    v0 = CDmElementFactoryHelper::s_pHelpers[0];
    for ( s_bInstalled = true; v0 != nullptr; v0 = v0->m_pNext )
    {
      m_pFactory = (int *)v0->m_pFactory;
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmElementFactoryHelper *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 32))(
        a1: g_pDataModel.u,
        a2: v0);
      m_pszClassname = v0->m_pszClassname;
      v3 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 200);
      v4 = *m_pFactory;
      v17[0] = g_pDataModel.u.m_Id;
      ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v3)(
        a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
        a2: v17,
        a3: m_pszClassname);
      (*(void (__thiscall **)(int *))(v4 + 20))(a1: m_pFactory);
    }
    for ( i = dword_7A99B8; i != 0; i = *(_DWORD *)i )
    {
      if ( (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 472))(
             a1: g_pDataModel.u,
             a2: *(_DWORD *)(i + 20)) == 0 )
      {
        v6 = *(int **)(i + 16);
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 32))(
          a1: g_pDataModel.u,
          a2: i);
        if ( _V_stricmp(s1: *(const char **)(i + 20), s2: "DmeElement") != 0 )
        {
          v7 = *(_DWORD *)(i + 20);
          v8 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD *, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 200);
          v9 = *v6;
          v17[0] = g_pDataModel.u.m_Id;
          ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v8)(
            a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
            a2: v17,
            a3: v7);
          (*(void (__thiscall **)(int *))(v9 + 20))(a1: v6);
        }
      }
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmElementFactoryInternal *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 40))(
      a1: g_pDataModel.u,
      a2: g_CDmElement_Helper.m_pFactory);
    v10 = CDmElementFactoryHelper::s_pHelpers;
    v20 = CDmElementFactoryHelper::s_pHelpers;
    do
    {
      v11 = *v10;
      if ( *v10 != nullptr )
      {
        do
        {
          v11->m_pFactory->GetParentElementTypeSymbol(this: v11->m_pFactory, result: &parentElementTypeSym);
          if ( parentElementTypeSym.u.m_Id != -1 )
          {
            v12 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 36))(
                    a1: g_pDataModel.u,
                    a2: parentElementTypeSym.u);
            v13 = v12;
            if ( v12 != 0 )
            {
              v14 = *(CDmElementFactoryHelper **)(v12 + 8);
              v15 = v11->m_pszClassname;
              pClassName = v15;
              if ( v14 != nullptr && _V_stricmp(s1: v15, s2: v14->m_pszClassname) >= 0 )
              {
                for ( j = v14->m_pSibling; j != nullptr; j = j->m_pSibling )
                {
                  if ( _V_stricmp(s1: pClassName, s2: j->m_pszClassname) < 0 )
                    break;
                  v14 = j;
                }
                v11->m_pSibling = v14->m_pSibling;
                v14->m_pSibling = v11;
              }
              else
              {
                *(_DWORD *)(v13 + 8) = v11;
                v11->m_pSibling = v14;
              }
            }
          }
          v11 = v11->m_pNext;
        }
        while ( v11 != nullptr );
        v10 = v20;
      }
      v20 = ++v10;
    }
    while ( (int)v10 < (int)&vec2_origin_22 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00450180
// Name: void InstallDmElementFactories(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl InstallDmElementFactories()
{
  CDmElementFactoryHelper::InstallFactories();
}

//------------------------------------------------------------------------------
// Address: 0x00450190
// Name: public: virtual void CDmElementFactoryInternal::OnElementCreated(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::OnElementCreated(CDmElementFactoryInternal *this, CDmElement *pElement)
{
  int i; // esi
  IDmeElementCreated *v4; // ecx

  for ( i = 0; i < this->m_CallBackList.m_Size; ++i )
  {
    v4 = this->m_CallBackList.m_Memory.m_pMemory[i];
    v4->OnElementCreated(this: v4, a2: pElement);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00450230
// Name: public: virtual void CDmElementFactoryInternal::RemoveOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::RemoveOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_CallBackList,
    src: (vgui::TreeNode **)&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x00450250
// Name: public: virtual void CDmElementFactoryInternal::AddOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::AddOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_CallBackList; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmeElementCreated **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  p_m_CallBackList = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_CallBackList;
  m_Size = this->m_CallBackList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (IDmeElementCreated **)p_m_CallBackList->m_pMemory;
  while ( *m_pMemory != pCallback )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_CallBackList->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_CallBackList, num: m_Size - m_nAllocationCount + 1);
    ++p_m_CallBackList[1].m_pMemory;
    v8 = p_m_CallBackList->m_pMemory;
    v9 = (int)p_m_CallBackList[1].m_pMemory - v7 - 1;
    p_m_CallBackList[1].m_nAllocationCount = (int)p_m_CallBackList->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_CallBackList->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)pCallback;
  }
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00443680
// Name: public: CDmElementFactoryHelper::CDmElementFactoryHelper(char const __near *,class CDmElementFactoryInternal __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmElementFactoryHelper *__thiscall CDmElementFactoryHelper::CDmElementFactoryHelper(
        CDmElementFactoryHelper *this,
        const char *classname,
        CDmElementFactoryInternal *pFactory,
        bool bIsStandardFactory)
{
  this->m_pParent = nullptr;
  this->m_pChild = nullptr;
  this->m_pSibling = nullptr;
  this->m_pNext = CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory];
  CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory] = this;
  this->m_pFactory = pFactory;
  this->m_pszClassname = classname;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004436C0
// Name: public: static void CDmElementFactoryHelper::InstallFactories(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmElementFactoryHelper::InstallFactories()
{
  CDmElementFactoryHelper *v0; // esi
  int *m_pFactory; // ebx
  const char *m_pszClassname; // eax
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int v4; // edi
  CDmElementFactoryHelper *i; // esi
  int *v6; // ebx
  const char *v7; // eax
  CUtlSymbolLarge *(__thiscall *v8)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int v9; // edi
  CDmElementFactoryHelper **v10; // eax
  CDmElementFactoryHelper *v11; // ebx
  CDmElementFactoryHelper *v12; // eax
  CDmElementFactoryHelper *v13; // esi
  CDmElementFactoryHelper *m_pChild; // edi
  const char *v15; // eax
  CDmElementFactoryHelper *j; // esi
  _DWORD v17[4]; // [esp-4h] [ebp-1Ch] BYREF
  const char *pClassName; // [esp+Ch] [ebp-Ch]
  CUtlSymbolLarge parentElementTypeSym; // [esp+10h] [ebp-8h] BYREF
  CDmElementFactoryHelper **v20; // [esp+14h] [ebp-4h]

  if ( !s_bInstalled )
  {
    v0 = CDmElementFactoryHelper::s_pHelpers[0];
    for ( s_bInstalled = true; v0 != nullptr; v0 = v0->m_pNext )
    {
      m_pFactory = (int *)v0->m_pFactory;
      g_pDataModel->AddElementFactory(this: g_pDataModel, a2: v0);
      m_pszClassname = v0->m_pszClassname;
      GetSymbol = g_pDataModel->GetSymbol;
      v4 = *m_pFactory;
      v17[0] = g_pDataModel;
      GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)v17, a3: m_pszClassname);
      (*(void (__thiscall **)(int *))(v4 + 20))(a1: m_pFactory);
    }
    for ( i = (CDmElementFactoryHelper *)dword_5D68C0; i != nullptr; i = i->m_pNext )
    {
      if ( !g_pDataModel->HasElementFactory(this: g_pDataModel, a2: i->m_pszClassname) )
      {
        v6 = (int *)i->m_pFactory;
        g_pDataModel->AddElementFactory(this: g_pDataModel, a2: i);
        if ( _V_stricmp(s1: i->m_pszClassname, s2: "DmeElement") != 0 )
        {
          v7 = i->m_pszClassname;
          v8 = g_pDataModel->GetSymbol;
          v9 = *v6;
          v17[0] = g_pDataModel;
          v8(this: g_pDataModel, result: (CUtlSymbolLarge *)v17, a3: v7);
          (*(void (__thiscall **)(int *))(v9 + 20))(a1: v6);
        }
      }
    }
    g_pDataModel->SetDefaultElementFactory(this: g_pDataModel, a2: g_CDmElement_Helper.m_pFactory);
    v10 = CDmElementFactoryHelper::s_pHelpers;
    v20 = CDmElementFactoryHelper::s_pHelpers;
    do
    {
      v11 = *v10;
      if ( *v10 != nullptr )
      {
        do
        {
          v11->m_pFactory->GetParentElementTypeSymbol(this: v11->m_pFactory, result: &parentElementTypeSym);
          if ( parentElementTypeSym.u.m_Id != -1 )
          {
            v12 = g_pDataModel->GetElementFactoryHelper(this: g_pDataModel, a2: parentElementTypeSym.u.m_Id);
            v13 = v12;
            if ( v12 != nullptr )
            {
              m_pChild = v12->m_pChild;
              v15 = v11->m_pszClassname;
              pClassName = v15;
              if ( m_pChild != nullptr && _V_stricmp(s1: v15, s2: m_pChild->m_pszClassname) >= 0 )
              {
                for ( j = m_pChild->m_pSibling; j != nullptr; j = j->m_pSibling )
                {
                  if ( _V_stricmp(s1: pClassName, s2: j->m_pszClassname) < 0 )
                    break;
                  m_pChild = j;
                }
                v11->m_pSibling = m_pChild->m_pSibling;
                m_pChild->m_pSibling = v11;
              }
              else
              {
                v13->m_pChild = v11;
                v11->m_pSibling = m_pChild;
              }
            }
          }
          v11 = v11->m_pNext;
        }
        while ( v11 != nullptr );
        v10 = v20;
      }
      v20 = ++v10;
    }
    while ( (int)v10 < (int)&vec2_origin_11 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443880
// Name: void InstallDmElementFactories(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl InstallDmElementFactories()
{
  CDmElementFactoryHelper::InstallFactories();
}

//------------------------------------------------------------------------------
// Address: 0x00443890
// Name: public: virtual void CDmElementFactoryInternal::OnElementCreated(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::OnElementCreated(CDmElementFactoryInternal *this, CDmElement *pElement)
{
  int i; // esi
  IDmeElementCreated *v4; // ecx

  for ( i = 0; i < this->m_CallBackList.m_Size; ++i )
  {
    v4 = this->m_CallBackList.m_Memory.m_pMemory[i];
    v4->OnElementCreated(this: v4, a2: pElement);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004438C0
// Name: public: virtual void CDmElementFactoryInternal::RemoveOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::RemoveOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(
    this: (CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int> > *)&this->m_CallBackList,
    src: (IDmNotify **)&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x004438E0
// Name: public: virtual void CDmElementFactoryInternal::AddOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::AddOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_CallBackList; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmeElementCreated **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax

  p_m_CallBackList = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_CallBackList;
  m_Size = this->m_CallBackList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (IDmeElementCreated **)p_m_CallBackList->m_pMemory;
  while ( *m_pMemory != pCallback )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_CallBackList->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_CallBackList, num: m_Size - m_nAllocationCount + 1);
    ++p_m_CallBackList[1].m_pMemory;
    v8 = p_m_CallBackList->m_pMemory;
    v9 = (int)p_m_CallBackList[1].m_pMemory - v7 - 1;
    p_m_CallBackList[1].m_nAllocationCount = (int)p_m_CallBackList->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_CallBackList->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (CUtlSymbolTable::StringPool_t *)pCallback;
  }
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004BA830
// Name: public: CDmElementFactoryHelper::CDmElementFactoryHelper(char const __near *,class CDmElementFactoryInternal __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmElementFactoryHelper *__thiscall CDmElementFactoryHelper::CDmElementFactoryHelper(
        CDmElementFactoryHelper *this,
        const char *classname,
        CDmElementFactoryInternal *pFactory,
        bool bIsStandardFactory)
{
  this->m_pParent = nullptr;
  this->m_pChild = nullptr;
  this->m_pSibling = nullptr;
  this->m_pNext = CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory];
  CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory] = this;
  this->m_pFactory = pFactory;
  this->m_pszClassname = classname;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004BA870
// Name: public: static void CDmElementFactoryHelper::InstallFactories(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmElementFactoryHelper::InstallFactories()
{
  CDmElementFactoryHelper *v0; // esi
  int *m_pFactory; // ebx
  const char *m_pszClassname; // eax
  void (__thiscall *v3)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD *, const char *); // edx
  int v4; // edi
  int i; // esi
  int *v6; // ebx
  int v7; // eax
  void (__thiscall *v8)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD *, int); // edx
  int v9; // edi
  CDmElementFactoryHelper **v10; // eax
  CDmElementFactoryHelper *v11; // ebx
  int v12; // eax
  int v13; // esi
  CDmElementFactoryHelper *v14; // edi
  const char *v15; // eax
  CDmElementFactoryHelper *j; // esi
  _DWORD v17[4]; // [esp-4h] [ebp-1Ch] BYREF
  const char *pClassName; // [esp+Ch] [ebp-Ch]
  CUtlSymbolLarge parentElementTypeSym; // [esp+10h] [ebp-8h] BYREF
  CDmElementFactoryHelper **v20; // [esp+14h] [ebp-4h]

  if ( !s_bInstalled )
  {
    v0 = CDmElementFactoryHelper::s_pHelpers[0];
    for ( s_bInstalled = true; v0 != nullptr; v0 = v0->m_pNext )
    {
      m_pFactory = (int *)v0->m_pFactory;
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmElementFactoryHelper *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 32))(
        a1: g_pDataModel.u,
        a2: v0);
      m_pszClassname = v0->m_pszClassname;
      v3 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 200);
      v4 = *m_pFactory;
      v17[0] = g_pDataModel.u.m_Id;
      ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v3)(
        a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
        a2: v17,
        a3: m_pszClassname);
      (*(void (__thiscall **)(int *))(v4 + 20))(a1: m_pFactory);
    }
    for ( i = dword_3AD6A58; i != 0; i = *(_DWORD *)i )
    {
      if ( (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 472))(
             a1: g_pDataModel.u,
             a2: *(_DWORD *)(i + 20)) == 0 )
      {
        v6 = *(int **)(i + 16);
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 32))(
          a1: g_pDataModel.u,
          a2: i);
        if ( _V_stricmp(s1: *(const char **)(i + 20), s2: "DmeElement") != 0 )
        {
          v7 = *(_DWORD *)(i + 20);
          v8 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD *, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 200);
          v9 = *v6;
          v17[0] = g_pDataModel.u.m_Id;
          ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v8)(
            a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
            a2: v17,
            a3: v7);
          (*(void (__thiscall **)(int *))(v9 + 20))(a1: v6);
        }
      }
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmElementFactoryInternal *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 40))(
      a1: g_pDataModel.u,
      a2: g_CDmElement_Helper.m_pFactory);
    v10 = CDmElementFactoryHelper::s_pHelpers;
    v20 = CDmElementFactoryHelper::s_pHelpers;
    do
    {
      v11 = *v10;
      if ( *v10 != nullptr )
      {
        do
        {
          v11->m_pFactory->GetParentElementTypeSymbol(this: v11->m_pFactory, result: &parentElementTypeSym);
          if ( parentElementTypeSym.u.m_Id != -1 )
          {
            v12 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 36))(
                    a1: g_pDataModel.u,
                    a2: parentElementTypeSym.u);
            v13 = v12;
            if ( v12 != 0 )
            {
              v14 = *(CDmElementFactoryHelper **)(v12 + 8);
              v15 = v11->m_pszClassname;
              pClassName = v15;
              if ( v14 != nullptr && _V_stricmp(s1: v15, s2: v14->m_pszClassname) >= 0 )
              {
                for ( j = v14->m_pSibling; j != nullptr; j = j->m_pSibling )
                {
                  if ( _V_stricmp(s1: pClassName, s2: j->m_pszClassname) < 0 )
                    break;
                  v14 = j;
                }
                v11->m_pSibling = v14->m_pSibling;
                v14->m_pSibling = v11;
              }
              else
              {
                *(_DWORD *)(v13 + 8) = v11;
                v11->m_pSibling = v14;
              }
            }
          }
          v11 = v11->m_pNext;
        }
        while ( v11 != nullptr );
        v10 = v20;
      }
      v20 = ++v10;
    }
    while ( (int)v10 < (int)&vec2_origin_40 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BAA30
// Name: void InstallDmElementFactories(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl InstallDmElementFactories()
{
  CDmElementFactoryHelper::InstallFactories();
}

//------------------------------------------------------------------------------
// Address: 0x004BAA40
// Name: public: virtual void CDmElementFactoryInternal::OnElementCreated(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::OnElementCreated(CDmElementFactoryInternal *this, CDmElement *pElement)
{
  int i; // esi
  IDmeElementCreated *v4; // ecx

  for ( i = 0; i < this->m_CallBackList.m_Size; ++i )
  {
    v4 = this->m_CallBackList.m_Memory.m_pMemory[i];
    v4->OnElementCreated(this: v4, a2: pElement);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BAAE0
// Name: public: virtual void CDmElementFactoryInternal::RemoveOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::RemoveOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(
    this: (CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int> > *)&this->m_CallBackList,
    src: (IDmNotify **)&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x004BAB00
// Name: public: virtual void CDmElementFactoryInternal::AddOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::AddOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_CallBackList; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmeElementCreated **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax

  p_m_CallBackList = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_CallBackList;
  m_Size = this->m_CallBackList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (IDmeElementCreated **)p_m_CallBackList->m_pMemory;
  while ( *m_pMemory != pCallback )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_CallBackList->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_CallBackList, num: m_Size - m_nAllocationCount + 1);
    ++p_m_CallBackList[1].m_pMemory;
    v8 = p_m_CallBackList->m_pMemory;
    v9 = (int)p_m_CallBackList[1].m_pMemory - v7 - 1;
    p_m_CallBackList[1].m_nAllocationCount = (int)p_m_CallBackList->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_CallBackList->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (CUtlSymbolTable::StringPool_t *)pCallback;
  }
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0044DB70
// Name: public: CDmElementFactoryHelper::CDmElementFactoryHelper(char const __near *,class CDmElementFactoryInternal __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmElementFactoryHelper *__thiscall CDmElementFactoryHelper::CDmElementFactoryHelper(
        CDmElementFactoryHelper *this,
        const char *classname,
        CDmElementFactoryInternal *pFactory,
        bool bIsStandardFactory)
{
  this->m_pParent = nullptr;
  this->m_pChild = nullptr;
  this->m_pSibling = nullptr;
  this->m_pNext = CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory];
  CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory] = this;
  this->m_pFactory = pFactory;
  this->m_pszClassname = classname;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044DBB0
// Name: public: static void CDmElementFactoryHelper::InstallFactories(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmElementFactoryHelper::InstallFactories()
{
  CDmElementFactoryHelper *v0; // esi
  int *m_pFactory; // ebx
  const char *m_pszClassname; // eax
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int v4; // edi
  CDmElementFactoryHelper *i; // esi
  int *v6; // ebx
  const char *v7; // eax
  CUtlSymbolLarge *(__thiscall *v8)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int v9; // edi
  CDmElementFactoryHelper **v10; // eax
  CDmElementFactoryHelper *v11; // ebx
  CDmElementFactoryHelper *v12; // eax
  CDmElementFactoryHelper *v13; // esi
  CDmElementFactoryHelper *m_pChild; // edi
  const char *v15; // eax
  CDmElementFactoryHelper *j; // esi
  _DWORD v17[4]; // [esp-4h] [ebp-1Ch] BYREF
  const char *pClassName; // [esp+Ch] [ebp-Ch]
  CUtlSymbolLarge parentElementTypeSym; // [esp+10h] [ebp-8h] BYREF
  CDmElementFactoryHelper **v20; // [esp+14h] [ebp-4h]

  if ( !s_bInstalled )
  {
    v0 = CDmElementFactoryHelper::s_pHelpers[0];
    for ( s_bInstalled = true; v0 != nullptr; v0 = v0->m_pNext )
    {
      m_pFactory = (int *)v0->m_pFactory;
      g_pDataModel->AddElementFactory(this: g_pDataModel, a2: v0);
      m_pszClassname = v0->m_pszClassname;
      GetSymbol = g_pDataModel->GetSymbol;
      v4 = *m_pFactory;
      v17[0] = g_pDataModel;
      GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)v17, a3: m_pszClassname);
      (*(void (__thiscall **)(int *))(v4 + 20))(a1: m_pFactory);
    }
    for ( i = (CDmElementFactoryHelper *)dword_5D34EC; i != nullptr; i = i->m_pNext )
    {
      if ( !g_pDataModel->HasElementFactory(this: g_pDataModel, a2: i->m_pszClassname) )
      {
        v6 = (int *)i->m_pFactory;
        g_pDataModel->AddElementFactory(this: g_pDataModel, a2: i);
        if ( _V_stricmp(s1: i->m_pszClassname, s2: "DmeElement") != 0 )
        {
          v7 = i->m_pszClassname;
          v8 = g_pDataModel->GetSymbol;
          v9 = *v6;
          v17[0] = g_pDataModel;
          v8(this: g_pDataModel, result: (CUtlSymbolLarge *)v17, a3: v7);
          (*(void (__thiscall **)(int *))(v9 + 20))(a1: v6);
        }
      }
    }
    g_pDataModel->SetDefaultElementFactory(this: g_pDataModel, a2: g_CDmElement_Helper.m_pFactory);
    v10 = CDmElementFactoryHelper::s_pHelpers;
    v20 = CDmElementFactoryHelper::s_pHelpers;
    do
    {
      v11 = *v10;
      if ( *v10 != nullptr )
      {
        do
        {
          v11->m_pFactory->GetParentElementTypeSymbol(this: v11->m_pFactory, result: &parentElementTypeSym);
          if ( parentElementTypeSym.u.m_Id != -1 )
          {
            v12 = g_pDataModel->GetElementFactoryHelper(this: g_pDataModel, a2: parentElementTypeSym.u.m_Id);
            v13 = v12;
            if ( v12 != nullptr )
            {
              m_pChild = v12->m_pChild;
              v15 = v11->m_pszClassname;
              pClassName = v15;
              if ( m_pChild != nullptr && _V_stricmp(s1: v15, s2: m_pChild->m_pszClassname) >= 0 )
              {
                for ( j = m_pChild->m_pSibling; j != nullptr; j = j->m_pSibling )
                {
                  if ( _V_stricmp(s1: pClassName, s2: j->m_pszClassname) < 0 )
                    break;
                  m_pChild = j;
                }
                v11->m_pSibling = m_pChild->m_pSibling;
                m_pChild->m_pSibling = v11;
              }
              else
              {
                v13->m_pChild = v11;
                v11->m_pSibling = m_pChild;
              }
            }
          }
          v11 = v11->m_pNext;
        }
        while ( v11 != nullptr );
        v10 = v20;
      }
      v20 = ++v10;
    }
    while ( (int)v10 < (int)&vec2_origin_11 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044DD70
// Name: void InstallDmElementFactories(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl InstallDmElementFactories()
{
  CDmElementFactoryHelper::InstallFactories();
}

//------------------------------------------------------------------------------
// Address: 0x0044DD80
// Name: public: virtual void CDmElementFactoryInternal::OnElementCreated(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::OnElementCreated(CDmElementFactoryInternal *this, CDmElement *pElement)
{
  int i; // esi
  IDmeElementCreated *v4; // ecx

  for ( i = 0; i < this->m_CallBackList.m_Size; ++i )
  {
    v4 = this->m_CallBackList.m_Memory.m_pMemory[i];
    v4->OnElementCreated(this: v4, a2: pElement);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044DDB0
// Name: public: virtual void CDmElementFactoryInternal::RemoveOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::RemoveOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(
    this: (CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int> > *)&this->m_CallBackList,
    src: (IDmNotify **)&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x0044DDD0
// Name: public: virtual void CDmElementFactoryInternal::AddOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::AddOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_CallBackList; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmeElementCreated **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax

  p_m_CallBackList = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_CallBackList;
  m_Size = this->m_CallBackList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (IDmeElementCreated **)p_m_CallBackList->m_pMemory;
  while ( *m_pMemory != pCallback )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_CallBackList->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_CallBackList, num: m_Size - m_nAllocationCount + 1);
    ++p_m_CallBackList[1].m_pMemory;
    v8 = p_m_CallBackList->m_pMemory;
    v9 = (int)p_m_CallBackList[1].m_pMemory - v7 - 1;
    p_m_CallBackList[1].m_nAllocationCount = (int)p_m_CallBackList->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_CallBackList->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (CUtlSymbolTable::StringPool_t *)pCallback;
  }
}

} // namespace uvlightmap

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x0051FCE0
// Name: public: CDmElementFactoryHelper::CDmElementFactoryHelper(char const __near *,class CDmElementFactoryInternal __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmElementFactoryHelper *__thiscall CDmElementFactoryHelper::CDmElementFactoryHelper(
        CDmElementFactoryHelper *this,
        const char *classname,
        CDmElementFactoryInternal *pFactory,
        bool bIsStandardFactory)
{
  this->m_pParent = nullptr;
  this->m_pChild = nullptr;
  this->m_pSibling = nullptr;
  this->m_pNext = CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory];
  CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory] = this;
  this->m_pFactory = pFactory;
  this->m_pszClassname = classname;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0051FD20
// Name: public: virtual void CDmElementFactoryInternal::OnElementCreated(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::OnElementCreated(CDmElementFactoryInternal *this, CDmElement *pElement)
{
  int i; // esi
  IDmeElementCreated *v4; // ecx

  for ( i = 0; i < this->m_CallBackList.m_Size; ++i )
  {
    v4 = this->m_CallBackList.m_Memory.m_pMemory[i];
    v4->OnElementCreated(this: v4, a2: pElement);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051FD50
// Name: public: virtual void CDmElementFactoryInternal::RemoveOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::RemoveOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlVector<CHitArea *,CUtlMemory<CHitArea *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_CallBackList,
    src: (vgui::TreeNode **)&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x0051FD60
// Name: public: virtual void CDmElementFactoryInternal::AddOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::AddOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  int m_Size; // edx
  CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *p_m_CallBackList; // ecx
  int v4; // eax
  IDmeElementCreated **m_pMemory; // esi

  m_Size = this->m_CallBackList.m_Size;
  p_m_CallBackList = (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_CallBackList;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (IDmeElementCreated **)p_m_CallBackList->m_Memory.m_pMemory;
  while ( *m_pMemory != pCallback )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
LABEL_7:
    CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
      this: p_m_CallBackList,
      elem: m_Size,
      src: (vgui::TreeNode **)&pCallback);
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0054D800
// Name: public: CDmElementFactoryHelper::CDmElementFactoryHelper(char const __near *,class CDmElementFactoryInternal __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmElementFactoryHelper *__thiscall CDmElementFactoryHelper::CDmElementFactoryHelper(
        CDmElementFactoryHelper *this,
        const char *classname,
        CDmElementFactoryInternal *pFactory,
        bool bIsStandardFactory)
{
  this->m_pParent = nullptr;
  this->m_pChild = nullptr;
  this->m_pSibling = nullptr;
  this->m_pNext = CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory];
  CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory] = this;
  this->m_pFactory = pFactory;
  this->m_pszClassname = classname;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0054D840
// Name: public: static void CDmElementFactoryHelper::InstallFactories(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmElementFactoryHelper::InstallFactories()
{
  CDmElementFactoryHelper *v0; // esi
  int *m_pFactory; // ebx
  const char *m_pszClassname; // eax
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int v4; // edi
  CDmElementFactoryHelper *i; // esi
  int *v6; // ebx
  const char *v7; // eax
  CUtlSymbolLarge *(__thiscall *v8)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int v9; // edi
  CDmElementFactoryHelper **v10; // eax
  CDmElementFactoryHelper *v11; // ebx
  CDmElementFactoryHelper *v12; // eax
  CDmElementFactoryHelper *v13; // esi
  CDmElementFactoryHelper *m_pChild; // edi
  const char *v15; // eax
  CDmElementFactoryHelper *j; // esi
  _DWORD v17[4]; // [esp-4h] [ebp-1Ch] BYREF
  const char *pClassName; // [esp+Ch] [ebp-Ch]
  CUtlSymbolLarge parentElementTypeSym; // [esp+10h] [ebp-8h] BYREF
  CDmElementFactoryHelper **v20; // [esp+14h] [ebp-4h]

  if ( !s_bInstalled )
  {
    v0 = CDmElementFactoryHelper::s_pHelpers[0];
    for ( s_bInstalled = true; v0 != nullptr; v0 = v0->m_pNext )
    {
      m_pFactory = (int *)v0->m_pFactory;
      g_pDataModel->AddElementFactory(this: g_pDataModel, a2: v0);
      m_pszClassname = v0->m_pszClassname;
      GetSymbol = g_pDataModel->GetSymbol;
      v4 = *m_pFactory;
      v17[0] = g_pDataModel;
      GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)v17, a3: m_pszClassname);
      (*(void (__thiscall **)(int *))(v4 + 20))(a1: m_pFactory);
    }
    for ( i = (CDmElementFactoryHelper *)dword_74375E8; i != nullptr; i = i->m_pNext )
    {
      if ( !g_pDataModel->HasElementFactory(this: g_pDataModel, a2: i->m_pszClassname) )
      {
        v6 = (int *)i->m_pFactory;
        g_pDataModel->AddElementFactory(this: g_pDataModel, a2: i);
        if ( _V_stricmp(s1: i->m_pszClassname, s2: "DmeElement") != 0 )
        {
          v7 = i->m_pszClassname;
          v8 = g_pDataModel->GetSymbol;
          v9 = *v6;
          v17[0] = g_pDataModel;
          v8(this: g_pDataModel, result: (CUtlSymbolLarge *)v17, a3: v7);
          (*(void (__thiscall **)(int *))(v9 + 20))(a1: v6);
        }
      }
    }
    g_pDataModel->SetDefaultElementFactory(this: g_pDataModel, a2: g_CDmElement_Helper.m_pFactory);
    v10 = CDmElementFactoryHelper::s_pHelpers;
    v20 = CDmElementFactoryHelper::s_pHelpers;
    do
    {
      v11 = *v10;
      if ( *v10 != nullptr )
      {
        do
        {
          v11->m_pFactory->GetParentElementTypeSymbol(this: v11->m_pFactory, result: &parentElementTypeSym);
          if ( parentElementTypeSym.u.m_Id != -1 )
          {
            v12 = g_pDataModel->GetElementFactoryHelper(this: g_pDataModel, a2: parentElementTypeSym.u.m_Id);
            v13 = v12;
            if ( v12 != nullptr )
            {
              m_pChild = v12->m_pChild;
              v15 = v11->m_pszClassname;
              pClassName = v15;
              if ( m_pChild != nullptr && _V_stricmp(s1: v15, s2: m_pChild->m_pszClassname) >= 0 )
              {
                for ( j = m_pChild->m_pSibling; j != nullptr; j = j->m_pSibling )
                {
                  if ( _V_stricmp(s1: pClassName, s2: j->m_pszClassname) < 0 )
                    break;
                  m_pChild = j;
                }
                v11->m_pSibling = m_pChild->m_pSibling;
                m_pChild->m_pSibling = v11;
              }
              else
              {
                v13->m_pChild = v11;
                v11->m_pSibling = m_pChild;
              }
            }
          }
          v11 = v11->m_pNext;
        }
        while ( v11 != nullptr );
        v10 = v20;
      }
      v20 = ++v10;
    }
    while ( (int)v10 < (int)&vec2_origin_64 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0054DA00
// Name: void InstallDmElementFactories(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl InstallDmElementFactories()
{
  CDmElementFactoryHelper::InstallFactories();
}

//------------------------------------------------------------------------------
// Address: 0x0054DA10
// Name: public: virtual void CDmElementFactoryInternal::OnElementCreated(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::OnElementCreated(CDmElementFactoryInternal *this, CDmElement *pElement)
{
  int i; // esi
  IDmeElementCreated *v4; // ecx

  for ( i = 0; i < this->m_CallBackList.m_Size; ++i )
  {
    v4 = this->m_CallBackList.m_Memory.m_pMemory[i];
    v4->OnElementCreated(this: v4, a2: pElement);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0054DAB0
// Name: public: virtual void CDmElementFactoryInternal::RemoveOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::RemoveOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(
    this: (CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int> > *)&this->m_CallBackList,
    src: (IDmNotify *const *)&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x0054DAD0
// Name: public: virtual void CDmElementFactoryInternal::AddOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::AddOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlMemory<S3RGBA,int> *p_m_CallBackList; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmeElementCreated **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  S3RGBA *v8; // ecx
  int v9; // eax
  S3RGBA *v10; // eax

  p_m_CallBackList = (CUtlMemory<S3RGBA,int> *)&this->m_CallBackList;
  m_Size = this->m_CallBackList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (IDmeElementCreated **)p_m_CallBackList->m_pMemory;
  while ( *m_pMemory != pCallback )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_CallBackList->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<HemiLightData_t *,int>::Grow(this: p_m_CallBackList, num: m_Size - m_nAllocationCount + 1);
    ++p_m_CallBackList[1].m_pMemory;
    v8 = p_m_CallBackList->m_pMemory;
    v9 = (int)p_m_CallBackList[1].m_pMemory - v7 - 1;
    p_m_CallBackList[1].m_nAllocationCount = (int)p_m_CallBackList->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_CallBackList->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (S3RGBA)pCallback;
  }
}

} // namespace vmap

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x1006FE30
// Name: public: CDmElementFactoryHelper::CDmElementFactoryHelper(char const __near *,class CDmElementFactoryInternal __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmElementFactoryHelper *__thiscall CDmElementFactoryHelper::CDmElementFactoryHelper(
        CDmElementFactoryHelper *this,
        const char *classname,
        CDmElementFactoryInternal *pFactory,
        bool bIsStandardFactory)
{
  this->m_pParent = nullptr;
  this->m_pChild = nullptr;
  this->m_pSibling = nullptr;
  this->m_pNext = CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory];
  CDmElementFactoryHelper::s_pHelpers[bIsStandardFactory] = this;
  this->m_pFactory = pFactory;
  this->m_pszClassname = classname;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006FE70
// Name: public: static void CDmElementFactoryHelper::InstallFactories(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CDmElementFactoryHelper::InstallFactories()
{
  CDmElementFactoryHelper *v0; // esi
  int *m_pFactory; // ebx
  const char *m_pszClassname; // eax
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int v4; // edi
  CDmElementFactoryHelper *i; // esi
  int *v6; // ebx
  const char *v7; // eax
  CUtlSymbolLarge *(__thiscall *v8)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int v9; // edi
  CDmElementFactoryHelper **v10; // eax
  CDmElementFactoryHelper *v11; // ebx
  CDmElementFactoryHelper *v12; // eax
  CDmElementFactoryHelper *v13; // esi
  CDmElementFactoryHelper *m_pChild; // edi
  const char *v15; // eax
  CDmElementFactoryHelper *j; // esi
  _DWORD v17[4]; // [esp-4h] [ebp-1Ch] BYREF
  const char *pClassName; // [esp+Ch] [ebp-Ch]
  CUtlSymbolLarge parentElementTypeSym; // [esp+10h] [ebp-8h] BYREF
  CDmElementFactoryHelper **v20; // [esp+14h] [ebp-4h]

  if ( !s_bInstalled )
  {
    v0 = CDmElementFactoryHelper::s_pHelpers[0];
    for ( s_bInstalled = true; v0 != nullptr; v0 = v0->m_pNext )
    {
      m_pFactory = (int *)v0->m_pFactory;
      g_pDataModel->AddElementFactory(this: g_pDataModel, a2: v0);
      m_pszClassname = v0->m_pszClassname;
      GetSymbol = g_pDataModel->GetSymbol;
      v4 = *m_pFactory;
      v17[0] = g_pDataModel;
      GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)v17, a3: m_pszClassname);
      (*(void (__thiscall **)(int *))(v4 + 20))(a1: m_pFactory);
    }
    for ( i = (CDmElementFactoryHelper *)dword_10153B80; i != nullptr; i = i->m_pNext )
    {
      if ( !g_pDataModel->HasElementFactory(this: g_pDataModel, a2: i->m_pszClassname) )
      {
        v6 = (int *)i->m_pFactory;
        g_pDataModel->AddElementFactory(this: g_pDataModel, a2: i);
        if ( _V_stricmp(s1: i->m_pszClassname, s2: "DmeElement") != 0 )
        {
          v7 = i->m_pszClassname;
          v8 = g_pDataModel->GetSymbol;
          v9 = *v6;
          v17[0] = g_pDataModel;
          v8(this: g_pDataModel, result: (CUtlSymbolLarge *)v17, a3: v7);
          (*(void (__thiscall **)(int *))(v9 + 20))(a1: v6);
        }
      }
    }
    g_pDataModel->SetDefaultElementFactory(this: g_pDataModel, a2: g_CDmElement_Helper.m_pFactory);
    v10 = CDmElementFactoryHelper::s_pHelpers;
    v20 = CDmElementFactoryHelper::s_pHelpers;
    do
    {
      v11 = *v10;
      if ( *v10 != nullptr )
      {
        do
        {
          v11->m_pFactory->GetParentElementTypeSymbol(this: v11->m_pFactory, result: &parentElementTypeSym);
          if ( parentElementTypeSym.u.m_Id != -1 )
          {
            v12 = g_pDataModel->GetElementFactoryHelper(this: g_pDataModel, a2: parentElementTypeSym.u.m_Id);
            v13 = v12;
            if ( v12 != nullptr )
            {
              m_pChild = v12->m_pChild;
              v15 = v11->m_pszClassname;
              pClassName = v15;
              if ( m_pChild != nullptr && _V_stricmp(s1: v15, s2: m_pChild->m_pszClassname) >= 0 )
              {
                for ( j = m_pChild->m_pSibling; j != nullptr; j = j->m_pSibling )
                {
                  if ( _V_stricmp(s1: pClassName, s2: j->m_pszClassname) < 0 )
                    break;
                  m_pChild = j;
                }
                v11->m_pSibling = m_pChild->m_pSibling;
                m_pChild->m_pSibling = v11;
              }
              else
              {
                v13->m_pChild = v11;
                v11->m_pSibling = m_pChild;
              }
            }
          }
          v11 = v11->m_pNext;
        }
        while ( v11 != nullptr );
        v10 = v20;
      }
      v20 = ++v10;
    }
    while ( (int)v10 < (int)&vec2_origin_17 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10070030
// Name: void InstallDmElementFactories(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl InstallDmElementFactories()
{
  CDmElementFactoryHelper::InstallFactories();
}

//------------------------------------------------------------------------------
// Address: 0x10070040
// Name: public: virtual void CDmElementFactoryInternal::OnElementCreated(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::OnElementCreated(CDmElementFactoryInternal *this, CDmElement *pElement)
{
  int i; // esi
  IDmeElementCreated *v4; // ecx

  for ( i = 0; i < this->m_CallBackList.m_Size; ++i )
  {
    v4 = this->m_CallBackList.m_Memory.m_pMemory[i];
    v4->OnElementCreated(this: v4, a2: pElement);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10070070
// Name: public: virtual void CDmElementFactoryInternal::RemoveOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::RemoveOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(
    this: (CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int> > *)&this->m_CallBackList,
    src: (IDmNotify **)&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x10070090
// Name: public: virtual void CDmElementFactoryInternal::AddOnElementCreatedCallback(class IDmeElementCreated __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFactoryInternal::AddOnElementCreatedCallback(
        CDmElementFactoryInternal *this,
        IDmeElementCreated *pCallback)
{
  CUtlMemory<S3RGBA,int> *p_m_CallBackList; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmeElementCreated **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  S3RGBA *v8; // ecx
  int v9; // eax
  S3RGBA *v10; // eax

  p_m_CallBackList = (CUtlMemory<S3RGBA,int> *)&this->m_CallBackList;
  m_Size = this->m_CallBackList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (IDmeElementCreated **)p_m_CallBackList->m_pMemory;
  while ( *m_pMemory != pCallback )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_CallBackList->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_CallBackList, num: m_Size - m_nAllocationCount + 1);
    ++p_m_CallBackList[1].m_pMemory;
    v8 = p_m_CallBackList->m_pMemory;
    v9 = (int)p_m_CallBackList[1].m_pMemory - v7 - 1;
    p_m_CallBackList[1].m_nAllocationCount = (int)p_m_CallBackList->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_CallBackList->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (S3RGBA)pCallback;
  }
}

} // namespace vtex_dll
