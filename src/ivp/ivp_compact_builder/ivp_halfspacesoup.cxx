// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_compact_builder/ivp_halfspacesoup.cxx
// Functions: 3
// ============================================================

#include "ivp\ivp_compact_builder\ivp_halfspacesoup.h"

//------------------------------------------------------------------------------
// Address: 0x10045810
// Name: public: IVP_Halfspacesoup::~IVP_Halfspacesoup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Halfspacesoup::~IVP_Halfspacesoup(IVP_Halfspacesoup *this)
{
  int v2; // edi
  void **elems; // eax
  void **v4; // eax

  v2 = this->n_elems - 1;
  if ( this->n_elems != 0 )
  {
    do
      free(data: this->elems[v2--]);
    while ( v2 >= 0 );
  }
  elems = this->elems;
  if ( elems != (void **)(this + 1) )
  {
    if ( elems != nullptr )
      free(data: this->elems);
    this->elems = nullptr;
    this->memsize = 0;
  }
  this->n_elems = 0;
  v4 = this->elems;
  if ( v4 == (void **)(this + 1) )
  {
    this->n_elems = 0;
  }
  else
  {
    if ( v4 != nullptr )
      free(data: this->elems);
    this->elems = nullptr;
    *(_DWORD *)&this->memsize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045890
// Name: public: IVP_Halfspacesoup::IVP_Halfspacesoup(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Halfspacesoup *__thiscall IVP_Halfspacesoup::IVP_Halfspacesoup(IVP_Halfspacesoup *this)
{
  *(_DWORD *)&this->memsize = 0;
  this->elems = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100458A0
// Name: public: void IVP_Halfspacesoup::add_halfspace(class IVP_U_Hesse const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Halfspacesoup::add_halfspace(IVP_Halfspacesoup *this, const IVP_U_Hesse *plane)
{
  int v3; // eax
  void **elems; // ecx
  float *v5; // edi
  int v6; // edx
  IVP_U_Hesse *v7; // eax
  IVP_U_Hesse *v8; // edi
  int n_elems; // ebx
  int j; // ebx
  unsigned __int16 v11; // dx
  void *v12; // edi
  int v13; // eax
  void **v14; // ecx
  IVP_U_Vector<IVP_U_Hesse> planes_to_delete; // [esp+Ch] [ebp-Ch] BYREF
  int i; // [esp+14h] [ebp-4h] BYREF

  v3 = 0;
  elems = nullptr;
  *(_DWORD *)&planes_to_delete.memsize = 0;
  planes_to_delete.elems = nullptr;
  i = 0;
  if ( this->n_elems == 0 )
  {
LABEL_8:
    v7 = (IVP_U_Hesse *)p_malloc(size: 0x10u);
    if ( v7 != nullptr )
    {
      *v7 = *plane;
      v8 = v7;
    }
    else
    {
      v8 = nullptr;
    }
    if ( this->n_elems >= this->memsize )
      IVP_U_Vector_Base::increment_mem(this);
    this->elems[this->n_elems] = v8;
    n_elems = planes_to_delete.n_elems;
    ++this->n_elems;
    for ( j = n_elems - 1; j >= 0; --j )
    {
      v11 = this->n_elems;
      v12 = planes_to_delete.elems[j];
      v13 = v11 - 1;
      if ( v11 != 0 )
      {
        v14 = &this->elems[v13];
        do
        {
          if ( *v14 == v12 )
            break;
          --v14;
          --v13;
        }
        while ( v13 >= 0 );
      }
      for ( this->n_elems = v11 - 1; v13 < this->n_elems; ++v13 )
        this->elems[v13] = this->elems[v13 + 1];
      free(data: v12);
    }
    if ( (int *)planes_to_delete.elems != &i && planes_to_delete.elems != nullptr )
      free(data: planes_to_delete.elems);
    return;
  }
  while ( 1 )
  {
    v5 = (float *)this->elems[v3];
    if ( (float)((float)((float)(v5[1] * plane->k[1]) + (float)(*v5 * plane->k[0])) + (float)(v5[2] * plane->k[2])) > 0.99989998 )
      break;
LABEL_7:
    v6 = this->n_elems;
    i = ++v3;
    if ( v3 >= v6 )
      goto LABEL_8;
  }
  if ( plane->hesse_val <= v5[3] )
  {
    if ( planes_to_delete.n_elems >= planes_to_delete.memsize )
    {
      IVP_U_Vector_Base::increment_mem(this: &planes_to_delete);
      elems = planes_to_delete.elems;
      v3 = i;
    }
    elems[planes_to_delete.n_elems++] = v5;
    elems = planes_to_delete.elems;
    goto LABEL_7;
  }
  if ( elems != (void **)&i && elems != nullptr )
    free(data: elems);
}
