// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/mm_extensions.cpp
// Functions: 6
// ============================================================

#include "matchmaking\mm_extensions.h"

//------------------------------------------------------------------------------
// Address: 0x10001D70
// Name: protected: void CMatchExtensions::OnExtensionInterfaceUpdated(char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchExtensions::OnExtensionInterfaceUpdated(
        CMatchExtensions *this,
        const char *szInterfaceString,
        vgui::ILocalize *pvInterface)
{
  CMatchExtensions::OnExtensionInterfaceUpdated::__l2::CachedInterfacePtr_t *i; // esi

  for ( i = s_table; i->m_szName != nullptr; ++i )
  {
    if ( _V_stricmp(s1: i->m_szName, s2: szInterfaceString) == 0 )
      *(void **)((char *)i->m_ppInterface + (unsigned int)this + 80) = pvInterface;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001DC0
// Name: public: void CUtlMemory<struct CMatchExtensions::RegisteredInterface_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CMatchExtensions::RegisteredInterface_t,int>::Grow(
        CUtlMemory<CMatchExtensions::RegisteredInterface_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CMatchExtensions::RegisteredInterface_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 4;
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
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CMatchExtensions::RegisteredInterface_t *)_g_pMemAlloc->Realloc_2(
                                                                     this: _g_pMemAlloc,
                                                                     a2: m_pMemory,
                                                                     a3: v7);
    else
      this->m_pMemory = (CMatchExtensions::RegisteredInterface_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001EF0
// Name: public: struct CMatchExtensions::RegisteredInterface_t __near & CUtlStringMap<struct CMatchExtensions::RegisteredInterface_t>::operator[](char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMatchExtensions::RegisteredInterface_t *__thiscall CUtlStringMap<CMatchExtensions::RegisteredInterface_t>::operator[](
        CUtlStringMap<CMatchExtensions::RegisteredInterface_t> *this,
        const char *pString)
{
  int v3; // edi
  int m_Size; // ecx

  CUtlSymbolTable::AddString(this: &this->m_SymbolTable, result: (CUtlSymbol *)&pString, pString);
  v3 = (unsigned __int16)pString;
  m_Size = this->m_Vector.m_Size;
  if ( m_Size <= (unsigned __int16)pString && m_Size < (unsigned __int16)pString + 1 )
    CUtlVector<CMatchExtensions::RegisteredInterface_t,CUtlMemory<CMatchExtensions::RegisteredInterface_t,int>>::InsertMultipleBefore(
      this: &this->m_Vector,
      elem: m_Size,
      num: (unsigned __int16)pString + 1 - m_Size);
  return &this->m_Vector.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x10001F30
// Name: public: virtual void CMatchExtensions::RegisterExtensionInterface(char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchExtensions::RegisterExtensionInterface(
        CMatchExtensions *this,
        const char *szInterfaceString,
        vgui::ILocalize *pvInterface)
{
  CMatchExtensions::RegisteredInterface_t *v4; // eax
  int m_nRefCount; // ecx

  if ( szInterfaceString != nullptr && pvInterface != nullptr )
  {
    v4 = CUtlStringMap<CMatchExtensions::RegisteredInterface_t>::operator[](
           this: &this->m_mapRegisteredInterfaces,
           pString: szInterfaceString);
    m_nRefCount = v4->m_nRefCount;
    if ( m_nRefCount <= 0 )
      v4->m_pvInterface = pvInterface;
    v4->m_nRefCount = m_nRefCount + 1;
    CMatchExtensions::OnExtensionInterfaceUpdated(this, szInterfaceString, pvInterface);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001F70
// Name: public: virtual void CMatchExtensions::UnregisterExtensionInterface(char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchExtensions::UnregisterExtensionInterface(
        CMatchExtensions *this,
        const char *szInterfaceString,
        void *pvInterface)
{
  CMatchExtensions::RegisteredInterface_t *v4; // eax
  int m_nRefCount; // ecx

  if ( szInterfaceString != nullptr && pvInterface != nullptr )
  {
    v4 = CUtlStringMap<CMatchExtensions::RegisteredInterface_t>::operator[](
           this: &this->m_mapRegisteredInterfaces,
           pString: szInterfaceString);
    m_nRefCount = v4->m_nRefCount;
    if ( m_nRefCount > 0 )
    {
      v4->m_nRefCount = m_nRefCount - 1;
      if ( m_nRefCount == 1 )
      {
        v4->m_pvInterface = nullptr;
        CMatchExtensions::OnExtensionInterfaceUpdated(this, szInterfaceString, pvInterface: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001FB0
// Name: public: virtual void __near * CMatchExtensions::GetRegisteredExtensionInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CMatchExtensions::GetRegisteredExtensionInterface(
        CMatchExtensions *this,
        const char *szInterfaceString)
{
  CUtlStringMap<CMatchExtensions::RegisteredInterface_t> *p_m_mapRegisteredInterfaces; // esi
  int v3; // edi
  int m_Size; // ecx
  void *result; // eax

  p_m_mapRegisteredInterfaces = &this->m_mapRegisteredInterfaces;
  CUtlSymbolTable::AddString(
    this: &this->m_mapRegisteredInterfaces.m_SymbolTable,
    result: (CUtlSymbol *)&szInterfaceString,
    pString: szInterfaceString);
  v3 = (unsigned __int16)szInterfaceString;
  m_Size = p_m_mapRegisteredInterfaces->m_Vector.m_Size;
  if ( m_Size <= (unsigned __int16)szInterfaceString && m_Size < (unsigned __int16)szInterfaceString + 1 )
    CUtlVector<CMatchExtensions::RegisteredInterface_t,CUtlMemory<CMatchExtensions::RegisteredInterface_t,int>>::InsertMultipleBefore(
      this: &p_m_mapRegisteredInterfaces->m_Vector,
      elem: m_Size,
      num: (unsigned __int16)szInterfaceString + 1 - m_Size);
  if ( p_m_mapRegisteredInterfaces->m_Vector.m_Memory.m_pMemory[v3].m_nRefCount <= 0 )
    return nullptr;
  result = p_m_mapRegisteredInterfaces->m_Vector.m_Memory.m_pMemory[v3].m_pvInterface;
  if ( result == nullptr )
    return nullptr;
  return result;
}

// ============================================================
// Overlay from matchmaking (Missing functions)
// ============================================================
namespace matchmaking {

//------------------------------------------------------------------------------
// Address: 0x100053C0
// Name: protected: void CMatchExtensions::OnExtensionInterfaceUpdated(char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchExtensions::OnExtensionInterfaceUpdated(
        CMatchExtensions *this,
        const char *szInterfaceString,
        vgui::ILocalize *pvInterface)
{
  CMatchExtensions::OnExtensionInterfaceUpdated::__l2::CachedInterfacePtr_t *i; // esi

  for ( i = s_table; i->m_szName != nullptr; ++i )
  {
    if ( _V_stricmp(s1: i->m_szName, s2: szInterfaceString) == 0 )
      *(void **)((char *)i->m_ppInterface + (unsigned int)this + 80) = pvInterface;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005540
// Name: public: virtual void CMatchExtensions::RegisterExtensionInterface(char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchExtensions::RegisterExtensionInterface(
        CMatchExtensions *this,
        const char *szInterfaceString,
        vgui::ILocalize *pvInterface)
{
  int m_Id; // edi
  int m_Size; // ecx
  CMatchExtensions::RegisteredInterface_t *v6; // eax
  int m_nRefCount; // ecx
  CUtlSymbol result; // [esp+4h] [ebp-4h] BYREF

  if ( szInterfaceString != nullptr && pvInterface != nullptr )
  {
    CUtlSymbolTable::AddString(
      this: &this->m_mapRegisteredInterfaces.m_SymbolTable,
      &result,
      pString: szInterfaceString);
    m_Id = result.m_Id;
    m_Size = this->m_mapRegisteredInterfaces.m_Vector.m_Size;
    if ( m_Size <= result.m_Id && m_Size < result.m_Id + 1 )
      CUtlVector<CMatchExtensions::RegisteredInterface_t,CUtlMemory<CMatchExtensions::RegisteredInterface_t,int>>::InsertMultipleBefore(
        this: &this->m_mapRegisteredInterfaces.m_Vector,
        elem: m_Size,
        num: result.m_Id + 1 - m_Size);
    v6 = &this->m_mapRegisteredInterfaces.m_Vector.m_Memory.m_pMemory[m_Id];
    m_nRefCount = v6->m_nRefCount;
    if ( m_nRefCount <= 0 )
      v6->m_pvInterface = pvInterface;
    v6->m_nRefCount = m_nRefCount + 1;
    CMatchExtensions::OnExtensionInterfaceUpdated(this, szInterfaceString, pvInterface);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100055B0
// Name: public: virtual void CMatchExtensions::UnregisterExtensionInterface(char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchExtensions::UnregisterExtensionInterface(
        CMatchExtensions *this,
        const char *szInterfaceString,
        void *pvInterface)
{
  int v4; // edi
  int m_Size; // ecx
  CMatchExtensions::RegisteredInterface_t *v6; // eax
  int m_nRefCount; // ecx
  int v8; // ecx

  if ( szInterfaceString != nullptr && pvInterface != nullptr )
  {
    CUtlSymbolTable::AddString(
      this: &this->m_mapRegisteredInterfaces.m_SymbolTable,
      result: (CUtlSymbol *)&pvInterface,
      pString: szInterfaceString);
    v4 = (unsigned __int16)pvInterface;
    m_Size = this->m_mapRegisteredInterfaces.m_Vector.m_Size;
    if ( m_Size <= (unsigned __int16)pvInterface && m_Size < (unsigned __int16)pvInterface + 1 )
      CUtlVector<CMatchExtensions::RegisteredInterface_t,CUtlMemory<CMatchExtensions::RegisteredInterface_t,int>>::InsertMultipleBefore(
        this: &this->m_mapRegisteredInterfaces.m_Vector,
        elem: m_Size,
        num: (unsigned __int16)pvInterface + 1 - m_Size);
    v6 = &this->m_mapRegisteredInterfaces.m_Vector.m_Memory.m_pMemory[v4];
    m_nRefCount = v6->m_nRefCount;
    if ( m_nRefCount > 0 )
    {
      v8 = m_nRefCount - 1;
      v6->m_nRefCount = v8;
      if ( v8 == 0 )
      {
        v6->m_pvInterface = nullptr;
        CMatchExtensions::OnExtensionInterfaceUpdated(this, szInterfaceString, pvInterface: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005620
// Name: public: virtual void __near * CMatchExtensions::GetRegisteredExtensionInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CMatchExtensions::GetRegisteredExtensionInterface(
        CMatchExtensions *this,
        const char *szInterfaceString)
{
  CUtlStringMap<CMatchExtensions::RegisteredInterface_t> *p_m_mapRegisteredInterfaces; // esi
  int v3; // edi
  int m_Size; // ecx
  void *result; // eax

  p_m_mapRegisteredInterfaces = &this->m_mapRegisteredInterfaces;
  CUtlSymbolTable::AddString(
    this: &this->m_mapRegisteredInterfaces.m_SymbolTable,
    result: (CUtlSymbol *)&szInterfaceString,
    pString: szInterfaceString);
  v3 = (unsigned __int16)szInterfaceString;
  m_Size = p_m_mapRegisteredInterfaces->m_Vector.m_Size;
  if ( m_Size <= (unsigned __int16)szInterfaceString && m_Size < (unsigned __int16)szInterfaceString + 1 )
    CUtlVector<CMatchExtensions::RegisteredInterface_t,CUtlMemory<CMatchExtensions::RegisteredInterface_t,int>>::InsertMultipleBefore(
      this: &p_m_mapRegisteredInterfaces->m_Vector,
      elem: m_Size,
      num: (unsigned __int16)szInterfaceString + 1 - m_Size);
  if ( p_m_mapRegisteredInterfaces->m_Vector.m_Memory.m_pMemory[v3].m_nRefCount <= 0 )
    return nullptr;
  result = p_m_mapRegisteredInterfaces->m_Vector.m_Memory.m_pMemory[v3].m_pvInterface;
  if ( result == nullptr )
    return nullptr;
  return result;
}

} // namespace matchmaking

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

//------------------------------------------------------------------------------
// Address: 0x10005400
// Name: protected: void CMatchExtensions::OnExtensionInterfaceUpdated(char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchExtensions::OnExtensionInterfaceUpdated(
        CMatchExtensions *this,
        const char *szInterfaceString,
        vgui::ILocalize *pvInterface)
{
  CMatchExtensions::OnExtensionInterfaceUpdated::__l2::CachedInterfacePtr_t *i; // esi

  for ( i = s_table; i->m_szName != nullptr; ++i )
  {
    if ( _V_stricmp(s1: i->m_szName, s2: szInterfaceString) == 0 )
      *(void **)((char *)i->m_ppInterface + (unsigned int)this + 80) = pvInterface;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005450
// Name: public: void CUtlMemory<struct CMatchExtensions::RegisteredInterface_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CMatchExtensions::RegisteredInterface_t,int>::Grow(
        CUtlMemory<CMatchExtensions::RegisteredInterface_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CMatchExtensions::RegisteredInterface_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 4;
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
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CMatchExtensions::RegisteredInterface_t *)_g_pMemAlloc->Realloc_2(
                                                                     this: _g_pMemAlloc,
                                                                     a2: m_pMemory,
                                                                     a3: v7);
    else
      this->m_pMemory = (CMatchExtensions::RegisteredInterface_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005580
// Name: public: virtual void CMatchExtensions::RegisterExtensionInterface(char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchExtensions::RegisterExtensionInterface(
        CMatchExtensions *this,
        const char *szInterfaceString,
        vgui::ILocalize *pvInterface)
{
  int m_Id; // edi
  int m_Size; // ecx
  CMatchExtensions::RegisteredInterface_t *v6; // eax
  int m_nRefCount; // ecx
  CUtlSymbol result; // [esp+4h] [ebp-4h] BYREF

  if ( szInterfaceString != nullptr && pvInterface != nullptr )
  {
    CUtlSymbolTable::AddString(
      this: &this->m_mapRegisteredInterfaces.m_SymbolTable,
      &result,
      pString: szInterfaceString);
    m_Id = result.m_Id;
    m_Size = this->m_mapRegisteredInterfaces.m_Vector.m_Size;
    if ( m_Size <= result.m_Id && m_Size < result.m_Id + 1 )
      CUtlVector<CMatchExtensions::RegisteredInterface_t,CUtlMemory<CMatchExtensions::RegisteredInterface_t,int>>::InsertMultipleBefore(
        this: &this->m_mapRegisteredInterfaces.m_Vector,
        elem: m_Size,
        num: result.m_Id + 1 - m_Size);
    v6 = &this->m_mapRegisteredInterfaces.m_Vector.m_Memory.m_pMemory[m_Id];
    m_nRefCount = v6->m_nRefCount;
    if ( m_nRefCount <= 0 )
      v6->m_pvInterface = pvInterface;
    v6->m_nRefCount = m_nRefCount + 1;
    CMatchExtensions::OnExtensionInterfaceUpdated(this, szInterfaceString, pvInterface);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100055F0
// Name: public: virtual void CMatchExtensions::UnregisterExtensionInterface(char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchExtensions::UnregisterExtensionInterface(
        CMatchExtensions *this,
        const char *szInterfaceString,
        void *pvInterface)
{
  int v4; // edi
  int m_Size; // ecx
  CMatchExtensions::RegisteredInterface_t *v6; // eax
  int m_nRefCount; // ecx
  int v8; // ecx

  if ( szInterfaceString != nullptr && pvInterface != nullptr )
  {
    CUtlSymbolTable::AddString(
      this: &this->m_mapRegisteredInterfaces.m_SymbolTable,
      result: (CUtlSymbol *)&pvInterface,
      pString: szInterfaceString);
    v4 = (unsigned __int16)pvInterface;
    m_Size = this->m_mapRegisteredInterfaces.m_Vector.m_Size;
    if ( m_Size <= (unsigned __int16)pvInterface && m_Size < (unsigned __int16)pvInterface + 1 )
      CUtlVector<CMatchExtensions::RegisteredInterface_t,CUtlMemory<CMatchExtensions::RegisteredInterface_t,int>>::InsertMultipleBefore(
        this: &this->m_mapRegisteredInterfaces.m_Vector,
        elem: m_Size,
        num: (unsigned __int16)pvInterface + 1 - m_Size);
    v6 = &this->m_mapRegisteredInterfaces.m_Vector.m_Memory.m_pMemory[v4];
    m_nRefCount = v6->m_nRefCount;
    if ( m_nRefCount > 0 )
    {
      v8 = m_nRefCount - 1;
      v6->m_nRefCount = v8;
      if ( v8 == 0 )
      {
        v6->m_pvInterface = nullptr;
        CMatchExtensions::OnExtensionInterfaceUpdated(this, szInterfaceString, pvInterface: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005660
// Name: public: virtual void __near * CMatchExtensions::GetRegisteredExtensionInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CMatchExtensions::GetRegisteredExtensionInterface(
        CMatchExtensions *this,
        const char *szInterfaceString)
{
  CUtlStringMap<CMatchExtensions::RegisteredInterface_t> *p_m_mapRegisteredInterfaces; // esi
  int v3; // edi
  int m_Size; // ecx
  void *result; // eax

  p_m_mapRegisteredInterfaces = &this->m_mapRegisteredInterfaces;
  CUtlSymbolTable::AddString(
    this: &this->m_mapRegisteredInterfaces.m_SymbolTable,
    result: (CUtlSymbol *)&szInterfaceString,
    pString: szInterfaceString);
  v3 = (unsigned __int16)szInterfaceString;
  m_Size = p_m_mapRegisteredInterfaces->m_Vector.m_Size;
  if ( m_Size <= (unsigned __int16)szInterfaceString && m_Size < (unsigned __int16)szInterfaceString + 1 )
    CUtlVector<CMatchExtensions::RegisteredInterface_t,CUtlMemory<CMatchExtensions::RegisteredInterface_t,int>>::InsertMultipleBefore(
      this: &p_m_mapRegisteredInterfaces->m_Vector,
      elem: m_Size,
      num: (unsigned __int16)szInterfaceString + 1 - m_Size);
  if ( p_m_mapRegisteredInterfaces->m_Vector.m_Memory.m_pMemory[v3].m_nRefCount <= 0 )
    return nullptr;
  result = p_m_mapRegisteredInterfaces->m_Vector.m_Memory.m_pMemory[v3].m_pvInterface;
  if ( result == nullptr )
    return nullptr;
  return result;
}

} // namespace matchmaking_ds
