// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_compact_builder/ivp_templates_intern.cxx
// Functions: 8
// ============================================================

#include "ivp\ivp_compact_builder\ivp_templates_intern.h"

//------------------------------------------------------------------------------
// Address: 0x100487F0
// Name: public: IVP_Template_Polygon::IVP_Template_Polygon(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Template_Polygon *__thiscall IVP_Template_Polygon::IVP_Template_Polygon(IVP_Template_Polygon *this)
{
  this->n_lines = 0;
  this->n_surfaces = 0;
  this->n_points = 0;
  this->points = nullptr;
  this->surfaces = nullptr;
  this->lines = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10048810
// Name: public: IVP_Template_Surface::IVP_Template_Surface(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Template_Surface *__thiscall IVP_Template_Surface::IVP_Template_Surface(IVP_Template_Surface *this)
{
  *(_QWORD *)this->normal.k = 0;
  *(_QWORD *)&this->normal.k[2] = 0;
  *(_QWORD *)&this->templ_poly = 0;
  *(_QWORD *)&this->lines = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10048830
// Name: public: void IVP_Template_Surface::close_surface(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Template_Surface::close_surface(IVP_Template_Surface *this)
{
  if ( this->lines != nullptr )
  {
    free(data: this->lines);
    this->lines = nullptr;
  }
  free(data: this->revert_line);
  this->revert_line = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10048860
// Name: public: void IVP_Template_Surface::init_surface(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Template_Surface::init_surface(IVP_Template_Surface *this, int line_count)
{
  this->n_lines = line_count;
  this->lines = (unsigned __int16 *)_calloc_crt(nelem: 4, size: line_count);
  this->revert_line = (char *)p_malloc(size: line_count);
}

//------------------------------------------------------------------------------
// Address: 0x10048890
// Name: public: int IVP_Template_Surface::get_surface_index(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Template_Surface::get_surface_index(IVP_Template_Surface *this)
{
  return this - this->templ_poly->surfaces;
}

//------------------------------------------------------------------------------
// Address: 0x100488A0
// Name: public: IVP_Template_Surface::~IVP_Template_Surface(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall IVP_Template_Surface::~IVP_Template_Surface(IVP_Template_Surface *this)
{
  IVP_Template_Surface::close_surface(this);
}

//------------------------------------------------------------------------------
// Address: 0x100488B0
// Name: public: IVP_Template_Polygon::IVP_Template_Polygon(int,int,int)
// Source: json
//------------------------------------------------------------------------------
IVP_Template_Polygon *__thiscall IVP_Template_Polygon::IVP_Template_Polygon(
        IVP_Template_Polygon *this,
        int point_count,
        unsigned int line_count,
        int surface_count)
{
  IVP_Template_Point *v5; // eax
  int n_surfaces; // edi
  int v7; // ecx
  int *v8; // eax
  IVP_Template_Surface *v9; // ebx
  IVP_Template_Surface *v10; // ecx
  IVP_Template_Surface *v11; // ecx
  int v12; // edx
  int v13; // eax
  int v14; // ecx

  this->n_points = point_count;
  this->n_surfaces = surface_count;
  this->n_lines = line_count;
  this->lines = (IVP_Template_Line *)p_malloc(size: (unsigned __int64)line_count >> 30 != 0 ? -1 : 4 * line_count);
  v5 = (IVP_Template_Point *)p_malloc(size: (unsigned __int64)(unsigned int)this->n_points >> 28 != 0 ? -1 : 16 * this->n_points);
  n_surfaces = this->n_surfaces;
  this->points = v5;
  v7 = (unsigned __int64)(unsigned int)n_surfaces >> 27 != 0 ? -1 : 32 * n_surfaces;
  v8 = (int *)p_malloc(size: __CFADD__(v7, 16) ? -1 : v7 + 16);
  if ( v8 != nullptr )
  {
    v9 = (IVP_Template_Surface *)(v8 + 4);
    *v8 = n_surfaces;
    v10 = (IVP_Template_Surface *)(v8 + 4);
    if ( n_surfaces - 1 >= 0 )
    {
      do
      {
        IVP_Template_Surface::IVP_Template_Surface(this: v10);
        v10 = v11 + 1;
      }
      while ( v12 - 1 >= 0 );
    }
  }
  else
  {
    v9 = nullptr;
  }
  v13 = 0;
  this->surfaces = v9;
  if ( this->n_surfaces > 0 )
  {
    v14 = 0;
    do
    {
      this->surfaces[v14].templ_poly = this;
      ++v13;
      ++v14;
    }
    while ( v13 < this->n_surfaces );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10048980
// Name: public: IVP_Template_Polygon::~IVP_Template_Polygon(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Template_Polygon::~IVP_Template_Polygon(IVP_Template_Polygon *this)
{
  IVP_Template_Surface *surfaces; // eax
  IVP_Template_Polygon **p_templ_poly; // ecx
  IVP_Template_Surface *v4; // esi
  int v5; // edi
  IVP_Template_Point *points; // [esp-8h] [ebp-14h]
  IVP_Template_Polygon **v7; // [esp+8h] [ebp-4h]

  free(data: this->lines);
  points = this->points;
  this->lines = nullptr;
  free(data: points);
  surfaces = this->surfaces;
  this->points = nullptr;
  if ( surfaces != nullptr )
  {
    p_templ_poly = &surfaces[-1].templ_poly;
    v4 = &surfaces[(int)surfaces[-1].templ_poly];
    v5 = (int)&surfaces[-1].templ_poly[-1].surfaces + 3;
    v7 = &surfaces[-1].templ_poly;
    if ( v5 >= 0 )
    {
      do
      {
        IVP_Template_Surface::~IVP_Template_Surface(this: --v4);
        --v5;
      }
      while ( v5 >= 0 );
      p_templ_poly = v7;
    }
    free(data: p_templ_poly);
    this->surfaces = nullptr;
  }
  else
  {
    this->surfaces = nullptr;
  }
}
