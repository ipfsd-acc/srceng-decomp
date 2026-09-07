// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_utility/ivu_active_value.cxx
// Functions: 30
// ============================================================

#include "ivp\ivp_utility\ivu_active_value.h"

//------------------------------------------------------------------------------
// Address: 0x1009A7C0
// Name: public: virtual IVP_Active_Value_Hash::~IVP_Active_Value_Hash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Active_Value_Hash::~IVP_Active_Value_Hash(IVP_Active_Value_Hash *this)
{
  int size_mm; // esi
  void (__thiscall ***elem)(const void *, int); // ecx
  bool v4; // zf

  size_mm = this->size_mm;
  for ( this->__vftable = (IVP_Active_Value_Hash_vtbl *)&IVP_Active_Value_Hash::`vftable'; size_mm >= 0; --size_mm )
  {
    elem = (void (__thiscall ***)(const void *, int))this->elems[size_mm].elem;
    if ( elem != nullptr )
    {
      v4 = elem[2] == (void (__thiscall **)(const void *, int))1;
      elem[2] = (void (__thiscall **)(const void *, int))((char *)elem[2] - 1);
      if ( v4 )
        (**elem)(a1: elem, a2: 1);
    }
  }
  IVP_VHash::~IVP_VHash(this);
}

//------------------------------------------------------------------------------
// Address: 0x1009A800
// Name: protected: int IVP_Active_Value_Hash::object_to_index(class IVP_U_Active_Value __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall IVP_Active_Value_Hash::object_to_index(IVP_Active_Value_Hash *this, IVP_U_Active_Value *av)
{
  char *name; // edi
  unsigned int v3; // esi
  signed int i; // eax

  name = av->name;
  v3 = -1;
  for ( i = p_strlen(s: name) - 1; i >= 0; --i )
    v3 = IVP_Hash_crctab[(unsigned __int8)(v3 ^ *name++)] ^ (v3 >> 8);
  return v3 | 0x80000000;
}

//------------------------------------------------------------------------------
// Address: 0x1009A850
// Name: protected: virtual enum IVP_BOOL IVP_Active_Value_Hash::compare(void __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall IVP_Active_Value_Hash::compare(IVP_Active_Value_Hash *this, const char **elem0, const char **elem1)
{
  return p_strcmp(s1: elem0[1], s2: elem1[1]) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009A880
// Name: public: virtual void IVP_U_Active_Value_Manager::refresh_psi_active_values(class IVP_Environment __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Active_Value_Manager::refresh_psi_active_values(
        IVP_U_Active_Value_Manager *this,
        IVP_Environment *env)
{
  if ( this->mod_current_time != nullptr )
    ((void (__stdcall *)(_DWORD, _DWORD))this->mod_current_time->set_double)(a1: env->current_time.seconds, a2: 0);
  this->update_delayed_active_values(this);
}

//------------------------------------------------------------------------------
// Address: 0x1009A8C0
// Name: public: virtual void IVP_U_Active_Terminal_Double::set_double(float,enum IVP_BOOL)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Active_Terminal_Double::set_double(
        IVP_U_Active_Terminal_Double *this,
        float new_value,
        IVP_BOOL delayed_update)
{
  IVP_U_Active_Value_Manager *l_mod_manager; // ecx

  this->double_value = new_value;
  ++IVP_U_Active_Float::change_meter;
  if ( delayed_update != IVP_FALSE && (l_mod_manager = this->l_mod_manager) != nullptr )
    l_mod_manager->delay_active_float(this: l_mod_manager, a2: &this->IVP_U_Active_Float_Delayed);
  else
    this->update_float(this: &this->IVP_U_Active_Float_Delayed);
}

//------------------------------------------------------------------------------
// Address: 0x1009A900
// Name: public: virtual int IVP_U_Active_Terminal_Double::print(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_U_Active_Terminal_Double::print(IVP_U_Active_Terminal_Double *this)
{
  printf(format: "DoubleVal");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009A910
// Name: public: virtual void IVP_U_Active_Terminal_Int::set_int(int,enum IVP_BOOL)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Active_Terminal_Int::set_int(
        IVP_U_Active_Terminal_Int *this,
        int new_value,
        IVP_BOOL delayed_update)
{
  IVP_U_Active_Value_Manager *l_mod_manager; // ecx

  this->int_value = new_value;
  ++IVP_U_Active_Float::change_meter;
  if ( delayed_update != IVP_FALSE && (l_mod_manager = this->l_mod_manager) != nullptr )
    l_mod_manager->delay_active_int(this: l_mod_manager, a2: &this->IVP_U_Active_Int_Delayed);
  else
    this->update_int(this: &this->IVP_U_Active_Int_Delayed);
}

//------------------------------------------------------------------------------
// Address: 0x1009A950
// Name: public: virtual int IVP_U_Active_Terminal_Int::print(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_U_Active_Terminal_Int::print(IVP_U_Active_Terminal_Int *this)
{
  printf(format: "IntVal");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009A990
// Name: public: virtual IVP_U_Active_Value_Manager::~IVP_U_Active_Value_Manager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Active_Value_Manager::~IVP_U_Active_Value_Manager(IVP_U_Active_Value_Manager *this)
{
  IVP_Active_Value_Hash *floats_name_hash; // ecx
  IVP_Active_Value_Hash *ints_name_hash; // ecx
  IVP_U_Active_Value *search_active_value; // ecx
  IVP_U_Active_Value_Manager *elems; // eax
  IVP_U_Active_Value_Manager *v6; // eax

  floats_name_hash = this->floats_name_hash;
  this->__vftable = (IVP_U_Active_Value_Manager_vtbl *)&IVP_U_Active_Value_Manager::`vftable';
  if ( floats_name_hash != nullptr )
    ((void (__thiscall *)(IVP_Active_Value_Hash *, int))floats_name_hash->dtr_IVP_VHash)(a1: floats_name_hash, a2: 1);
  ints_name_hash = this->ints_name_hash;
  this->floats_name_hash = nullptr;
  if ( ints_name_hash != nullptr )
    ((void (__thiscall *)(IVP_Active_Value_Hash *, int))ints_name_hash->dtr_IVP_VHash)(a1: ints_name_hash, a2: 1);
  search_active_value = this->search_active_value;
  this->ints_name_hash = nullptr;
  if ( search_active_value != nullptr )
    ((void (__thiscall *)(IVP_U_Active_Value *, int))search_active_value->dtr_IVP_U_Active_Value)(
      a1: search_active_value,
      a2: 1);
  this->search_active_value = nullptr;
  elems = (IVP_U_Active_Value_Manager *)this->delayed_active_ints.elems;
  if ( elems != (IVP_U_Active_Value_Manager *)&this->mod_current_time )
  {
    if ( elems != nullptr )
      free(data: this->delayed_active_ints.elems);
    this->delayed_active_ints.elems = nullptr;
    this->delayed_active_ints.memsize = 0;
  }
  this->delayed_active_ints.n_elems = 0;
  v6 = (IVP_U_Active_Value_Manager *)this->delayed_active_floats.elems;
  if ( v6 == (IVP_U_Active_Value_Manager *)&this->delayed_active_ints )
  {
    this->delayed_active_floats.n_elems = 0;
  }
  else
  {
    if ( v6 != nullptr )
      free(data: this->delayed_active_floats.elems);
    this->delayed_active_floats.elems = nullptr;
    *(_DWORD *)&this->delayed_active_floats.memsize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009AA30
// Name: public: virtual void IVP_U_Active_Value_Manager::environment_will_be_deleted(class IVP_Environment __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Active_Value_Manager::environment_will_be_deleted(
        IVP_U_Active_Value_Manager *this,
        IVP_Environment *__formal)
{
  if ( this->delete_on_env_delete != IVP_FALSE )
    ((void (__thiscall *)(IVP_U_Active_Value_Manager *, int))this->dtr_IVP_U_Active_Value_Manager)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1009AA50
// Name: public: virtual void IVP_U_Active_Value_Manager::insert_active_float(class IVP_U_Active_Float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Active_Value_Manager::insert_active_float(
        IVP_U_Active_Value_Manager *this,
        IVP_U_Active_Float *mod)
{
  IVP_Active_Value_Hash *floats_name_hash; // ebx
  unsigned int v5; // eax
  IVP_Active_Value_Hash *v6; // ebx
  unsigned int v7; // eax
  char *name; // [esp+10h] [ebp+8h]

  name = mod->name;
  if ( p_strlen(s: name) != 0 )
  {
    floats_name_hash = this->floats_name_hash;
    v5 = IVP_Active_Value_Hash::object_to_index(this: floats_name_hash, av: mod);
    if ( IVP_VHash::find_elem(this: floats_name_hash, elem: mod, hash_index: v5) != nullptr )
    {
      printf(format: "insert_active_float: name '%s' already exists in name_hash!\n", name);
    }
    else
    {
      v6 = this->floats_name_hash;
      v7 = IVP_Active_Value_Hash::object_to_index(this: v6, av: mod);
      IVP_VHash::add_elem(this: v6, elem: mod, hash_index: v7);
      ++mod->reference_count;
      mod->l_mod_manager = this;
    }
  }
  else
  {
    printf(format: "insert_active_float: tried to insert active_IVP_FLOAT without name!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009AAE0
// Name: public: virtual void IVP_U_Active_Value_Manager::insert_active_int(class IVP_U_Active_Int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Active_Value_Manager::insert_active_int(IVP_U_Active_Value_Manager *this, IVP_U_Active_Int *mod)
{
  IVP_Active_Value_Hash *ints_name_hash; // ebx
  unsigned int v5; // eax
  IVP_Active_Value_Hash *v6; // ebx
  unsigned int v7; // eax
  char *name; // [esp+10h] [ebp+8h]

  name = mod->name;
  if ( p_strlen(s: name) != 0 )
  {
    ints_name_hash = this->ints_name_hash;
    v5 = IVP_Active_Value_Hash::object_to_index(this: ints_name_hash, av: mod);
    if ( IVP_VHash::find_elem(this: ints_name_hash, elem: mod, hash_index: v5) != nullptr )
    {
      printf(format: "insert_active_int: name '%s' already exists in name_hash!\n", name);
    }
    else
    {
      v6 = this->ints_name_hash;
      v7 = IVP_Active_Value_Hash::object_to_index(this: v6, av: mod);
      IVP_VHash::add_elem(this: v6, elem: mod, hash_index: v7);
      mod->reference_count += 2;
      mod->l_mod_manager = this;
    }
  }
  else
  {
    printf(format: "insert_active_int: tried to insert active_int without name!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009AB70
// Name: public: virtual void IVP_U_Active_Value_Manager::remove_active_float(class IVP_U_Active_Float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Active_Value_Manager::remove_active_float(
        IVP_U_Active_Value_Manager *this,
        IVP_U_Active_Float *mod)
{
  IVP_Active_Value_Hash *floats_name_hash; // esi
  unsigned int v3; // eax
  void (__thiscall ***v4)(void *, int); // eax
  bool v5; // zf

  floats_name_hash = this->floats_name_hash;
  v3 = IVP_Active_Value_Hash::object_to_index(this: floats_name_hash, av: mod);
  v4 = (void (__thiscall ***)(void *, int))IVP_VHash::remove_elem(this: floats_name_hash, elem: mod, hash_index: v3);
  v5 = v4[2] == (void (__thiscall **)(void *, int))1;
  v4[2] = (void (__thiscall **)(void *, int))((char *)v4[2] - 1);
  if ( v5 )
    (**v4)(a1: v4, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1009ABB0
// Name: public: virtual void IVP_U_Active_Value_Manager::remove_active_int(class IVP_U_Active_Int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Active_Value_Manager::remove_active_int(IVP_U_Active_Value_Manager *this, IVP_U_Active_Int *mod)
{
  IVP_Active_Value_Hash *ints_name_hash; // esi
  unsigned int v3; // eax
  void (__thiscall ***v4)(void *, int); // eax
  bool v5; // zf

  ints_name_hash = this->ints_name_hash;
  v3 = IVP_Active_Value_Hash::object_to_index(this: ints_name_hash, av: mod);
  v4 = (void (__thiscall ***)(void *, int))IVP_VHash::remove_elem(this: ints_name_hash, elem: mod, hash_index: v3);
  v5 = v4[2] == (void (__thiscall **)(void *, int))1;
  v4[2] = (void (__thiscall **)(void *, int))((char *)v4[2] - 1);
  if ( v5 )
    (**v4)(a1: v4, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1009ABF0
// Name: public: virtual void IVP_U_Active_Value_Manager::update_delayed_active_values(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Active_Value_Manager::update_delayed_active_values(IVP_U_Active_Value_Manager *this)
{
  int v2; // edi
  void *v3; // ecx
  IVP_U_Active_Value_Manager *elems; // eax
  int v5; // edi
  void *v6; // ecx
  IVP_U_Active_Value_Manager *v7; // eax

  v2 = 0;
  if ( this->delayed_active_floats.n_elems != 0 )
  {
    do
    {
      v3 = this->delayed_active_floats.elems[v2];
      (*(void (__thiscall **)(void *))(*(_DWORD *)v3 + 4))(a1: v3);
      ++v2;
    }
    while ( v2 < this->delayed_active_floats.n_elems );
  }
  elems = (IVP_U_Active_Value_Manager *)this->delayed_active_floats.elems;
  if ( elems != (IVP_U_Active_Value_Manager *)&this->delayed_active_ints )
  {
    if ( elems != nullptr )
      free(data: this->delayed_active_floats.elems);
    this->delayed_active_floats.elems = nullptr;
    this->delayed_active_floats.memsize = 0;
  }
  this->delayed_active_floats.n_elems = 0;
  v5 = 0;
  if ( this->delayed_active_ints.n_elems != 0 )
  {
    do
    {
      v6 = this->delayed_active_ints.elems[v5];
      (*(void (__thiscall **)(void *))(*(_DWORD *)v6 + 4))(a1: v6);
      ++v5;
    }
    while ( v5 < this->delayed_active_ints.n_elems );
  }
  v7 = (IVP_U_Active_Value_Manager *)this->delayed_active_ints.elems;
  if ( v7 == (IVP_U_Active_Value_Manager *)&this->mod_current_time )
  {
    this->delayed_active_ints.n_elems = 0;
  }
  else
  {
    if ( v7 != nullptr )
      free(data: v7);
    this->delayed_active_ints.elems = nullptr;
    *(_DWORD *)&this->delayed_active_ints.memsize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009ACE0
// Name: public: virtual void IVP_U_Active_Terminal_Double::update_float(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Active_Terminal_Double::update_float(IVP_U_Active_Terminal_Double *this)
{
  float v1; // xmm0_4
  char *v2; // edi
  int v3; // esi
  int v4; // ecx

  v1 = *((float *)this - 1);
  if ( v1 != *(float *)&this->name )
  {
    v2 = (char *)this - 32;
    *(float *)&this->name = v1;
    v3 = *(&this->derived_mods.n_elems - 16) - 1;
    if ( *(&this->derived_mods.n_elems - 16) != 0 )
    {
      do
      {
        v4 = *(_DWORD *)(*((_DWORD *)v2 + 4) + 4 * v3);
        (*(void (__thiscall **)(int, char *))(*(_DWORD *)v4 + 4))(a1: v4, a2: v2);
        --v3;
      }
      while ( v3 >= 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009AD20
// Name: public: virtual void IVP_U_Active_Terminal_Int::update_int(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Active_Terminal_Int::update_int(IVP_U_Active_Terminal_Int *this)
{
  char *v1; // eax
  char *v2; // edi
  int v3; // esi
  int v4; // ecx

  v1 = *((char **)this - 1);
  if ( v1 != this->name )
  {
    v2 = (char *)this - 32;
    this->name = v1;
    v3 = *(&this->derived_mods.n_elems - 16) - 1;
    if ( *(&this->derived_mods.n_elems - 16) != 0 )
    {
      do
      {
        v4 = *(_DWORD *)(*((_DWORD *)v2 + 4) + 4 * v3);
        (*(void (__thiscall **)(int, char *))(*(_DWORD *)v4 + 4))(a1: v4, a2: v2);
        --v3;
      }
      while ( v3 >= 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009AD80
// Name: public: virtual void IVP_U_Active_Value_Manager::delay_active_float(class IVP_U_Active_Float_Delayed __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Active_Value_Manager::delay_active_float(
        IVP_U_Active_Value_Manager *this,
        IVP_U_Active_Float_Delayed *mod)
{
  int v2; // eax
  IVP_U_Vector<IVP_U_Active_Float_Delayed> *p_delayed_active_floats; // esi
  IVP_U_Active_Float_Delayed **v4; // ecx

  v2 = this->delayed_active_floats.n_elems - 1;
  p_delayed_active_floats = &this->delayed_active_floats;
  if ( this->delayed_active_floats.n_elems != 0 )
  {
    v4 = (IVP_U_Active_Float_Delayed **)&this->delayed_active_floats.elems[v2];
    do
    {
      if ( *v4 == mod )
        break;
      --v4;
      --v2;
    }
    while ( v2 >= 0 );
  }
  if ( v2 == -1 )
  {
    if ( p_delayed_active_floats->n_elems >= p_delayed_active_floats->memsize )
      IVP_U_Vector_Base::increment_mem(this: p_delayed_active_floats);
    p_delayed_active_floats->elems[p_delayed_active_floats->n_elems++] = mod;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009ADD0
// Name: public: virtual void IVP_U_Active_Value_Manager::delay_active_int(class IVP_U_Active_Int_Delayed __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Active_Value_Manager::delay_active_int(
        IVP_U_Active_Value_Manager *this,
        IVP_U_Active_Int_Delayed *mod)
{
  int v2; // eax
  IVP_U_Vector<IVP_U_Active_Int_Delayed> *p_delayed_active_ints; // esi
  IVP_U_Active_Int_Delayed **v4; // ecx

  v2 = this->delayed_active_ints.n_elems - 1;
  p_delayed_active_ints = &this->delayed_active_ints;
  if ( this->delayed_active_ints.n_elems != 0 )
  {
    v4 = (IVP_U_Active_Int_Delayed **)&this->delayed_active_ints.elems[v2];
    do
    {
      if ( *v4 == mod )
        break;
      --v4;
      --v2;
    }
    while ( v2 >= 0 );
  }
  if ( v2 == -1 )
  {
    if ( p_delayed_active_ints->n_elems >= p_delayed_active_ints->memsize )
      IVP_U_Vector_Base::increment_mem(this: p_delayed_active_ints);
    p_delayed_active_ints->elems[p_delayed_active_ints->n_elems++] = mod;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009AE20
// Name: public: void IVP_U_Active_Float::add_dependency(class IVP_U_Active_Float_Listener __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Active_Float::add_dependency(
        IVP_U_Active_Float *this,
        IVP_U_Active_Float_Listener *derived_active_IVP_FLOAT)
{
  if ( this->derived_mods.n_elems >= this->derived_mods.memsize )
    IVP_U_Vector_Base::increment_mem(this: &this->derived_mods);
  this->derived_mods.elems[this->derived_mods.n_elems++] = derived_active_IVP_FLOAT;
  ++this->reference_count;
}

//------------------------------------------------------------------------------
// Address: 0x1009AE60
// Name: public: void IVP_U_Active_Float::remove_dependency(class IVP_U_Active_Float_Listener __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Active_Float::remove_dependency(
        IVP_U_Active_Float *this,
        IVP_U_Active_Float_Listener *derived_active_IVP_FLOAT)
{
  unsigned __int16 n_elems; // si
  int v3; // eax
  IVP_U_Active_Float_Listener **v4; // edx

  n_elems = this->derived_mods.n_elems;
  v3 = n_elems - 1;
  if ( n_elems != 0 )
  {
    v4 = (IVP_U_Active_Float_Listener **)&this->derived_mods.elems[v3];
    do
    {
      if ( *v4 == derived_active_IVP_FLOAT )
        break;
      --v4;
      --v3;
    }
    while ( v3 >= 0 );
  }
  for ( this->derived_mods.n_elems = n_elems - 1; v3 < this->derived_mods.n_elems; ++v3 )
    this->derived_mods.elems[v3] = this->derived_mods.elems[v3 + 1];
  if ( this->reference_count-- == 1 )
    ((void (__thiscall *)(IVP_U_Active_Float *, int))this->dtr_IVP_U_Active_Value)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1009AEC0
// Name: public: IVP_U_Active_Terminal_Double::IVP_U_Active_Terminal_Double(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
IVP_U_Active_Terminal_Double *__thiscall IVP_U_Active_Terminal_Double::IVP_U_Active_Terminal_Double(
        IVP_U_Active_Terminal_Double *this,
        char *i_name,
        float new_value)
{
  this->IVP_U_Active_Float::IVP_U_Active_Value::__vftable = (IVP_U_Active_Terminal_Double_vtbl *)&IVP_U_Active_Value::`vftable';
  this->name = p_strdup(s: i_name);
  this->reference_count = 0;
  this->derived_mods.elems = nullptr;
  *(_DWORD *)&this->derived_mods.memsize = 0;
  this->last_update = 0;
  this->l_mod_manager = nullptr;
  this->IVP_U_Active_Float_Delayed::__vftable = (IVP_U_Active_Float_Delayed_vtbl *)&IVP_U_Active_Float_Delayed::`vftable';
  this->IVP_U_Active_Float::IVP_U_Active_Value::__vftable = (IVP_U_Active_Terminal_Double_vtbl *)&IVP_U_Active_Terminal_Double::`vftable'{for `IVP_U_Active_Float'};
  this->IVP_U_Active_Float_Delayed::__vftable = (IVP_U_Active_Float_Delayed_vtbl *)&IVP_U_Active_Terminal_Double::`vftable'{for `IVP_U_Active_Float_Delayed'};
  this->double_value = new_value;
  this->old_value = new_value;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009AF20
// Name: public: IVP_U_Active_Terminal_Int::IVP_U_Active_Terminal_Int(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
IVP_U_Active_Terminal_Int *__thiscall IVP_U_Active_Terminal_Int::IVP_U_Active_Terminal_Int(
        IVP_U_Active_Terminal_Int *this,
        char *i_name,
        int new_value)
{
  this->IVP_U_Active_Int::IVP_U_Active_Value::__vftable = (IVP_U_Active_Terminal_Int_vtbl *)&IVP_U_Active_Value::`vftable';
  this->name = p_strdup(s: i_name);
  this->reference_count = 0;
  this->derived_mods.elems = nullptr;
  *(_DWORD *)&this->derived_mods.memsize = 0;
  this->last_update = 0;
  this->l_mod_manager = nullptr;
  this->IVP_U_Active_Int_Delayed::__vftable = (IVP_U_Active_Int_Delayed_vtbl *)&IVP_U_Active_Float_Delayed::`vftable';
  this->int_value = new_value;
  this->old_value = new_value;
  this->IVP_U_Active_Int::IVP_U_Active_Value::__vftable = (IVP_U_Active_Terminal_Int_vtbl *)&IVP_U_Active_Terminal_Int::`vftable'{for `IVP_U_Active_Int'};
  this->IVP_U_Active_Int_Delayed::__vftable = (IVP_U_Active_Int_Delayed_vtbl *)&IVP_U_Active_Terminal_Int::`vftable'{for `IVP_U_Active_Int_Delayed'};
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009AF90
// Name: public: virtual IVP_U_Active_Terminal_Double::~IVP_U_Active_Terminal_Double(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Active_Terminal_Double::~IVP_U_Active_Terminal_Double(IVP_U_Active_Terminal_Int *this)
{
  IVP_U_Active_Terminal_Int *elems; // eax
  char *name; // eax

  this->IVP_U_Active_Int_Delayed::__vftable = (IVP_U_Active_Int_Delayed_vtbl *)&IVP_U_Active_Float_Delayed::`vftable';
  this->IVP_U_Active_Int::IVP_U_Active_Value::__vftable = (IVP_U_Active_Terminal_Int_vtbl *)&IVP_U_Active_Float::`vftable';
  elems = (IVP_U_Active_Terminal_Int *)this->derived_mods.elems;
  if ( elems != (IVP_U_Active_Terminal_Int *)&this->l_mod_manager )
  {
    if ( elems != nullptr )
      free(data: elems);
    this->derived_mods.elems = nullptr;
    this->derived_mods.memsize = 0;
  }
  this->derived_mods.n_elems = 0;
  name = this->name;
  this->IVP_U_Active_Int::IVP_U_Active_Value::__vftable = (IVP_U_Active_Terminal_Int_vtbl *)&IVP_U_Active_Value::`vftable';
  if ( name != nullptr )
  {
    free(data: name);
    this->name = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009AFF0
// Name: public: virtual void IVP_U_Active_Value_Manager::init_active_values_generic(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Active_Value_Manager::init_active_values_generic(IVP_U_Active_Value_Manager *this)
{
  IVP_U_Active_Float *v1; // eax
  IVP_U_Active_Float *v2; // esi
  IVP_U_Active_Terminal_Double *v3; // ebx
  IVP_U_Active_Terminal_Double *v4; // eax
  IVP_U_Active_Terminal_Double *v5; // edi
  char *v6; // eax
  void (__thiscall *insert_active_float)(IVP_U_Active_Value_Manager *, IVP_U_Active_Float *); // eax

  v1 = (IVP_U_Active_Float *)p_malloc(size: 0x28u);
  v2 = v1;
  v3 = nullptr;
  if ( v1 != nullptr )
  {
    v1->__vftable = (IVP_U_Active_Float_vtbl *)&IVP_U_Active_Value::`vftable';
    v1->name = p_strdup(s: "double_null");
    v2->reference_count = 0;
    v2->derived_mods.elems = nullptr;
    *(_DWORD *)&v2->derived_mods.memsize = 0;
    v2->last_update = 0;
    v2->l_mod_manager = nullptr;
    v2[1].__vftable = (IVP_U_Active_Float_vtbl *)&IVP_U_Active_Float_Delayed::`vftable';
    v2->__vftable = (IVP_U_Active_Float_vtbl *)&IVP_U_Active_Terminal_Double::`vftable'{for `IVP_U_Active_Float'};
    v2[1].__vftable = (IVP_U_Active_Float_vtbl *)&IVP_U_Active_Terminal_Double::`vftable'{for `IVP_U_Active_Float_Delayed'};
    v2->double_value = 0.0;
    v2[1].name = nullptr;
  }
  else
  {
    v2 = nullptr;
  }
  v4 = (IVP_U_Active_Terminal_Double *)p_malloc(size: 0x28u);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->IVP_U_Active_Float::IVP_U_Active_Value::__vftable = (IVP_U_Active_Terminal_Double_vtbl *)&IVP_U_Active_Value::`vftable';
    v6 = p_strdup(s: "current_time");
    v5->reference_count = 0;
    v5->name = v6;
    v5->derived_mods.elems = nullptr;
    *(_DWORD *)&v5->derived_mods.memsize = 0;
    v5->last_update = 0;
    v5->l_mod_manager = nullptr;
    v5->IVP_U_Active_Float_Delayed::__vftable = (IVP_U_Active_Float_Delayed_vtbl *)&IVP_U_Active_Float_Delayed::`vftable';
    v5->IVP_U_Active_Float::IVP_U_Active_Value::__vftable = (IVP_U_Active_Terminal_Double_vtbl *)&IVP_U_Active_Terminal_Double::`vftable'{for `IVP_U_Active_Float'};
    v5->IVP_U_Active_Float_Delayed::__vftable = (IVP_U_Active_Float_Delayed_vtbl *)&IVP_U_Active_Terminal_Double::`vftable'{for `IVP_U_Active_Float_Delayed'};
    v5->double_value = 0.0;
    v5->old_value = 0.0;
    v3 = v5;
  }
  insert_active_float = this->insert_active_float;
  this->mod_current_time = v3;
  insert_active_float(this, a2: v2);
  this->insert_active_float(this, a2: this->mod_current_time);
}

//------------------------------------------------------------------------------
// Address: 0x1009B0E0
// Name: public: virtual class IVP_U_Active_Float __near * IVP_U_Active_Value_Manager::install_active_float(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
IVP_U_Active_Terminal_Double *__thiscall IVP_U_Active_Value_Manager::install_active_float(
        IVP_U_Active_Value_Manager *this,
        char *i_name,
        float value)
{
  IVP_Active_Value_Hash *floats_name_hash; // ebx
  IVP_U_Active_Value *search_active_value; // edi
  unsigned int v6; // eax
  IVP_U_Active_Terminal_Double *result; // eax
  IVP_U_Active_Terminal_Double *v8; // edi
  IVP_U_Active_Terminal_Double *v9; // eax

  this->search_active_value->name = i_name;
  floats_name_hash = this->floats_name_hash;
  search_active_value = this->search_active_value;
  v6 = IVP_Active_Value_Hash::object_to_index(this: floats_name_hash, av: search_active_value);
  result = (IVP_U_Active_Terminal_Double *)IVP_VHash::find_elem(
                                             this: floats_name_hash,
                                             elem: search_active_value,
                                             hash_index: v6);
  v8 = nullptr;
  this->search_active_value->name = nullptr;
  if ( result == nullptr )
  {
    v9 = (IVP_U_Active_Terminal_Double *)p_malloc(size: 0x28u);
    if ( v9 != nullptr )
      v8 = IVP_U_Active_Terminal_Double::IVP_U_Active_Terminal_Double(this: v9, i_name, new_value: value);
    this->insert_active_float(this, a2: v8);
    return v8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009B150
// Name: public: virtual class IVP_U_Active_Terminal_Double __near * IVP_U_Active_Value_Manager::create_active_float(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
IVP_U_Active_Terminal_Double *__thiscall IVP_U_Active_Value_Manager::create_active_float(
        IVP_U_Active_Value_Manager *this,
        char *i_name,
        float value)
{
  IVP_Active_Value_Hash *floats_name_hash; // ebx
  IVP_U_Active_Value *search_active_value; // edi
  unsigned int v6; // eax
  void *elem; // eax
  IVP_U_Active_Terminal_Double *v8; // edi
  IVP_U_Active_Terminal_Double *v10; // eax

  this->search_active_value->name = i_name;
  floats_name_hash = this->floats_name_hash;
  search_active_value = this->search_active_value;
  v6 = IVP_Active_Value_Hash::object_to_index(this: floats_name_hash, av: search_active_value);
  elem = IVP_VHash::find_elem(this: floats_name_hash, elem: search_active_value, hash_index: v6);
  v8 = nullptr;
  this->search_active_value->name = nullptr;
  if ( elem != nullptr )
    return nullptr;
  v10 = (IVP_U_Active_Terminal_Double *)p_malloc(size: 0x28u);
  if ( v10 != nullptr )
    v8 = IVP_U_Active_Terminal_Double::IVP_U_Active_Terminal_Double(this: v10, i_name, new_value: value);
  this->insert_active_float(this, a2: v8);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1009B1D0
// Name: public: virtual class IVP_U_Active_Terminal_Int __near * IVP_U_Active_Value_Manager::create_active_int(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
IVP_U_Active_Terminal_Int *__thiscall IVP_U_Active_Value_Manager::create_active_int(
        IVP_U_Active_Value_Manager *this,
        char *i_name,
        int value)
{
  IVP_Active_Value_Hash *ints_name_hash; // ebx
  IVP_U_Active_Value *search_active_value; // edi
  unsigned int v6; // eax
  void *elem; // eax
  IVP_U_Active_Terminal_Int *v8; // edi
  IVP_U_Active_Terminal_Int *v10; // eax

  this->search_active_value->name = i_name;
  ints_name_hash = this->ints_name_hash;
  search_active_value = this->search_active_value;
  v6 = IVP_Active_Value_Hash::object_to_index(this: ints_name_hash, av: search_active_value);
  elem = IVP_VHash::find_elem(this: ints_name_hash, elem: search_active_value, hash_index: v6);
  v8 = nullptr;
  this->search_active_value->name = nullptr;
  if ( elem != nullptr )
    return nullptr;
  v10 = (IVP_U_Active_Terminal_Int *)p_malloc(size: 0x28u);
  if ( v10 != nullptr )
    v8 = IVP_U_Active_Terminal_Int::IVP_U_Active_Terminal_Int(this: v10, i_name, new_value: value);
  this->insert_active_int(this, a2: v8);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1009B240
// Name: public: virtual class IVP_U_Active_Int __near * IVP_U_Active_Value_Manager::install_active_int(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
IVP_U_Active_Terminal_Int *__thiscall IVP_U_Active_Value_Manager::install_active_int(
        IVP_U_Active_Value_Manager *this,
        char *i_name,
        int value)
{
  IVP_Active_Value_Hash *ints_name_hash; // ebx
  IVP_U_Active_Value *search_active_value; // edi
  unsigned int v6; // eax
  IVP_U_Active_Terminal_Int *result; // eax
  IVP_U_Active_Terminal_Int *v8; // edi
  IVP_U_Active_Terminal_Int *v9; // eax

  this->search_active_value->name = i_name;
  ints_name_hash = this->ints_name_hash;
  search_active_value = this->search_active_value;
  v6 = IVP_Active_Value_Hash::object_to_index(this: ints_name_hash, av: search_active_value);
  result = (IVP_U_Active_Terminal_Int *)IVP_VHash::find_elem(
                                          this: ints_name_hash,
                                          elem: search_active_value,
                                          hash_index: v6);
  v8 = nullptr;
  this->search_active_value->name = nullptr;
  if ( result == nullptr )
  {
    v9 = (IVP_U_Active_Terminal_Int *)p_malloc(size: 0x28u);
    if ( v9 != nullptr )
      v8 = IVP_U_Active_Terminal_Int::IVP_U_Active_Terminal_Int(this: v9, i_name, new_value: value);
    this->insert_active_int(this, a2: v8);
    return v8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009B350
// Name: public: IVP_U_Active_Value_Manager::IVP_U_Active_Value_Manager(enum IVP_BOOL)
// Source: json
//------------------------------------------------------------------------------
IVP_U_Active_Value_Manager *__thiscall IVP_U_Active_Value_Manager::IVP_U_Active_Value_Manager(
        IVP_U_Active_Value_Manager *this,
        IVP_BOOL delete_on_env_delete_in)
{
  IVP_VHash *v3; // eax
  IVP_Active_Value_Hash *v4; // edi
  IVP_VHash *v5; // eax
  IVP_Active_Value_Hash *v6; // edi
  IVP_U_Active_Value *v7; // eax
  IVP_U_Active_Value *v8; // edi

  this->__vftable = (IVP_U_Active_Value_Manager_vtbl *)&IVP_U_Active_Value_Manager::`vftable';
  *(_DWORD *)&this->delayed_active_floats.memsize = 0;
  this->delayed_active_floats.elems = nullptr;
  *(_DWORD *)&this->delayed_active_ints.memsize = 0;
  this->delayed_active_ints.elems = nullptr;
  this->delete_on_env_delete = delete_on_env_delete_in;
  v3 = (IVP_VHash *)p_malloc(size: 0x10u);
  v4 = (IVP_Active_Value_Hash *)v3;
  if ( v3 != nullptr )
  {
    IVP_VHash::IVP_VHash(this: v3, size_i: 16);
    v4->__vftable = (IVP_Active_Value_Hash_vtbl *)&IVP_Active_Value_Hash::`vftable';
  }
  else
  {
    v4 = nullptr;
  }
  this->floats_name_hash = v4;
  v5 = (IVP_VHash *)p_malloc(size: 0x10u);
  v6 = (IVP_Active_Value_Hash *)v5;
  if ( v5 != nullptr )
  {
    IVP_VHash::IVP_VHash(this: v5, size_i: 16);
    v6->__vftable = (IVP_Active_Value_Hash_vtbl *)&IVP_Active_Value_Hash::`vftable';
  }
  else
  {
    v6 = nullptr;
  }
  this->ints_name_hash = v6;
  v7 = (IVP_U_Active_Value *)p_malloc(size: 0xCu);
  v8 = v7;
  if ( v7 != nullptr )
  {
    v7->__vftable = (IVP_U_Active_Value_vtbl *)&IVP_U_Active_Value::`vftable';
    v7->name = p_strdup(s: nullptr);
    v8->reference_count = 0;
  }
  else
  {
    v8 = nullptr;
  }
  this->search_active_value = v8;
  this->mod_current_time = nullptr;
  IVP_U_Active_Value_Manager::init_active_values_generic(this);
  return this;
}
