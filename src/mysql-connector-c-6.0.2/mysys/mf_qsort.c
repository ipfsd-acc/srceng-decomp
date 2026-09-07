// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/mf_qsort.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00434E40
// Name: _my_qsort
// Source: json
//------------------------------------------------------------------------------
char *__thiscall my_qsort(void *base_ptr, char *base_ptra, char *count, unsigned int size, std::bad_typeid *cmp)
{
  char *result; // eax
  unsigned int v6; // ebx
  unsigned int v7; // edi
  void *v8; // esp
  unsigned int v9; // eax
  char *v10; // esi
  _DWORD *v11; // ecx
  int v12; // eax
  char *v13; // eax
  char v14; // dl
  char *v15; // esi
  int v16; // eax
  char *v17; // eax
  char *v18; // ecx
  char *v19; // eax
  int v20; // ecx
  char v21; // cl
  char *v22; // edi
  char *v23; // ecx
  int v24; // eax
  char *v25; // eax
  char *v26; // edi
  char v27; // cl
  char *v28; // edi
  int v29; // eax
  char *v30; // eax
  char *v31; // edi
  char v32; // cl
  int v33; // eax
  char *v34; // edi
  char *v35; // eax
  char v36; // cl
  char *v37; // edi
  int v38; // eax
  char *v39; // edi
  char *v40; // eax
  char v41; // cl
  char *v42; // edi
  char *v43; // eax
  int v44; // ecx
  char v45; // cl
  char *v46; // edi
  char *v47; // ecx
  int v48; // eax
  char *v49; // eax
  char *v50; // eax
  int v51; // ecx
  char *v52; // ecx
  char *v53; // eax
  _DWORD *v54; // ecx
  int v55; // eax
  char *v56; // eax
  _DWORD *v57; // ecx
  int v58; // eax
  char *v59; // edi
  char *v60; // esi
  char *v61; // edi
  char *v62; // eax
  char *v63; // esi
  char v64; // cl
  int v65; // eax
  char *v66; // eax
  char *v67; // esi
  char v68; // cl
  char *v69; // eax
  int v70; // ecx
  char *v71; // ecx
  int v72; // eax
  char *v73; // eax
  char *v74; // esi
  char v75; // cl
  char *v76; // edi
  int v77; // eax
  char *v78; // eax
  char *v79; // esi
  char v80; // cl
  int v81; // eax
  char *v82; // eax
  char *v83; // ecx
  char *v84; // edx
  char *v85; // ecx
  bool v86; // cc
  char *v87; // eax
  int v88; // [esp+0h] [ebp-13Ch] BYREF
  char v89; // [esp+Ch] [ebp-130h] BYREF
  char v90; // [esp+14h] [ebp-128h] BYREF
  char *mid; // [esp+10Ch] [ebp-30h]
  char *pivot; // [esp+110h] [ebp-2Ch]
  unsigned int step; // [esp+114h] [ebp-28h]
  char *v94; // [esp+118h] [ebp-24h]
  char *v95; // [esp+11Ch] [ebp-20h]
  char *end; // [esp+120h] [ebp-1Ch]
  _DWORD *v97; // [esp+124h] [ebp-18h]
  char *low_ptr; // [esp+128h] [ebp-14h]
  char *low; // [esp+12Ch] [ebp-10h]
  char *high; // [esp+130h] [ebp-Ch]
  char tmp; // [esp+136h] [ebp-6h]
  char ptr_cmp; // [esp+137h] [ebp-5h]

  result = count;
  if ( (unsigned int)count > 1 )
  {
    v6 = size;
    v7 = (unsigned int)base_ptra;
    high = &base_ptra[size * (_DWORD)(count - 1)];
    v94 = &v90;
    low = base_ptra;
    v8 = alloca(size);
    pivot = (char *)&v88;
    if ( size != 4 || (ptr_cmp = 1, ((unsigned __int8)base_ptra & 3) != 0) )
      ptr_cmp = 0;
    while ( 1 )
    {
      v9 = (unsigned int)&high[-v7] / v6 + 1;
      if ( v9 < 0xA )
      {
        low_ptr = (char *)(v7 + v6);
        if ( v7 + v6 <= (unsigned int)high )
        {
          step = v7;
          do
          {
            v10 = low_ptr;
            if ( (unsigned int)low_ptr > v7 )
            {
              v97 = (_DWORD *)step;
              do
              {
                if ( ((int (__cdecl *)(_DWORD *, char *))cmp)(a1: v97, a2: v10) <= 0 )
                  break;
                v11 = v97;
                if ( ptr_cmp != 0 )
                {
                  v12 = *(_DWORD *)v10;
                  *(_DWORD *)v10 = *v97;
                  *v11 = v12;
                }
                else
                {
                  v13 = v10;
                  do
                  {
                    v14 = *v13;
                    *v13++ = *(_BYTE *)v11;
                    *(_BYTE *)v11 = v14;
                    v11 = (_DWORD *)((char *)v11 + 1);
                  }
                  while ( v13 < &v10[v6] );
                  v6 = size;
                }
                v7 = (unsigned int)low;
                v97 = (_DWORD *)((char *)v97 - v6);
                v10 -= v6;
              }
              while ( v10 > low );
            }
            step += v6;
            low_ptr += v6;
          }
          while ( low_ptr <= high );
        }
        v7 = *((_DWORD *)v94 - 2);
        v94 -= 8;
        result = *((char **)v94 + 1);
        low = (char *)v7;
        high = result;
        goto LABEL_129;
      }
      v15 = (char *)(v7 + v6 * (v9 >> 1));
      mid = v15;
      if ( v9 <= 0x28 )
      {
        if ( ((int (__cdecl *)(char *, unsigned int))cmp)(a1: high, a2: v7) < 0 )
        {
          v69 = high;
          if ( ptr_cmp != 0 )
          {
            v70 = *(_DWORD *)high;
            *(_DWORD *)high = *(_DWORD *)v7;
            *(_DWORD *)v7 = v70;
          }
          else
          {
            v71 = (char *)v7;
            v95 = &high[v6];
            do
            {
              tmp = *v69;
              *v69++ = *v71;
              *v71++ = tmp;
            }
            while ( v69 < v95 );
          }
        }
        if ( ((int (__cdecl *)(char *, unsigned int))cmp)(a1: v15, a2: v7) >= 0 )
        {
          v76 = high;
          if ( ((int (__cdecl *)(char *, char *))cmp)(a1: high, a2: v15) < 0 )
          {
            if ( ptr_cmp != 0 )
            {
              v77 = *(_DWORD *)v15;
              *(_DWORD *)v15 = *(_DWORD *)v76;
              *(_DWORD *)v76 = v77;
            }
            else
            {
              v78 = v15;
              v79 = &v15[v6];
              do
              {
                v80 = *v78;
                *v78++ = *v76;
                *v76++ = v80;
              }
              while ( v78 < v79 );
            }
          }
        }
        else if ( ptr_cmp != 0 )
        {
          v72 = *(_DWORD *)v15;
          *(_DWORD *)v15 = *(_DWORD *)v7;
          *(_DWORD *)v7 = v72;
        }
        else
        {
          v73 = v15;
          v74 = &v15[v6];
          do
          {
            v75 = *v73;
            *v73++ = *(_BYTE *)v7;
            *(_BYTE *)v7++ = v75;
          }
          while ( v73 < v74 );
        }
        v60 = &low[v6];
        v59 = &high[-v6];
        goto LABEL_103;
      }
      step = v6 * (v9 >> 3);
      low_ptr = (char *)(v7 + 2 * step);
      if ( ((int (__cdecl *)(char *, unsigned int))cmp)(a1: low_ptr, a2: v7) < 0 )
      {
        if ( ptr_cmp != 0 )
        {
          v16 = *(_DWORD *)low_ptr;
          *(_DWORD *)low_ptr = *(_DWORD *)v7;
          *(_DWORD *)v7 = v16;
        }
        else
        {
          v17 = low_ptr;
          v18 = (char *)v7;
          end = &low_ptr[v6];
          do
          {
            tmp = *v17;
            *v17++ = *v18;
            *v18++ = tmp;
          }
          while ( v17 < end );
        }
      }
      v97 = (_DWORD *)(v7 + step);
      if ( ((int (__cdecl *)(unsigned int, unsigned int))cmp)(a1: v7 + step, a2: v7) >= 0 )
      {
        v22 = (char *)v97;
        if ( ((int (__cdecl *)(char *, _DWORD *))cmp)(a1: low_ptr, a2: v97) < 0 )
        {
          if ( ptr_cmp != 0 )
          {
            v23 = low_ptr;
            v24 = *(_DWORD *)v22;
            *(_DWORD *)v22 = *(_DWORD *)low_ptr;
            *(_DWORD *)v23 = v24;
          }
          else
          {
            v25 = v22;
            v26 = low_ptr;
            end = &v25[v6];
            do
            {
              v27 = *v25;
              *v25++ = *v26;
              *v26++ = v27;
            }
            while ( v25 < end );
          }
        }
      }
      else
      {
        v19 = (char *)v97;
        if ( ptr_cmp != 0 )
        {
          v20 = *v97;
          *v97 = *(_DWORD *)v7;
          *(_DWORD *)v7 = v20;
        }
        else
        {
          end = (char *)v97 + v6;
          do
          {
            v21 = *v19;
            *v19++ = *(_BYTE *)v7;
            *(_BYTE *)v7++ = v21;
          }
          while ( v19 < end );
        }
      }
      v28 = &v15[-step];
      end = &v15[-step];
      low_ptr = &v15[step];
      if ( ((int (__cdecl *)(char *, char *))cmp)(a1: &v15[step], a2: &v15[-step]) < 0 )
      {
        if ( ptr_cmp != 0 )
        {
          v29 = *(_DWORD *)low_ptr;
          *(_DWORD *)low_ptr = *(_DWORD *)v28;
          *(_DWORD *)v28 = v29;
        }
        else
        {
          v30 = low_ptr;
          v31 = end;
          v95 = &low_ptr[v6];
          do
          {
            v32 = *v30;
            *v30++ = *v31;
            *v31++ = v32;
          }
          while ( v30 < v95 );
        }
        v28 = end;
      }
      if ( ((int (__cdecl *)(char *, char *))cmp)(a1: v15, a2: v28) >= 0 )
      {
        v37 = low_ptr;
        if ( ((int (__cdecl *)(char *, char *))cmp)(a1: low_ptr, a2: v15) < 0 )
        {
          if ( ptr_cmp != 0 )
          {
            v38 = *(_DWORD *)v15;
            *(_DWORD *)v15 = *(_DWORD *)v37;
            *(_DWORD *)v37 = v38;
          }
          else
          {
            v39 = low_ptr;
            v40 = v15;
            do
            {
              v41 = *v40;
              *v40 = *v39;
              *v39 = v41;
              ++v40;
              ++v39;
            }
            while ( v40 < &v15[v6] );
          }
        }
      }
      else if ( ptr_cmp != 0 )
      {
        v33 = *(_DWORD *)v15;
        *(_DWORD *)v15 = *(_DWORD *)v28;
        *(_DWORD *)v28 = v33;
      }
      else
      {
        v34 = end;
        v35 = v15;
        do
        {
          v36 = *v35;
          *v35 = *v34;
          *v34 = v36;
          ++v35;
          ++v34;
        }
        while ( v35 < &v15[v6] );
      }
      v42 = &high[-2 * step];
      end = v42;
      if ( ((int (__cdecl *)(char *, char *))cmp)(a1: high, a2: v42) < 0 )
      {
        v43 = high;
        if ( ptr_cmp != 0 )
        {
          v44 = *(_DWORD *)high;
          *(_DWORD *)high = *(_DWORD *)v42;
          *(_DWORD *)v42 = v44;
        }
        else
        {
          v95 = &high[v6];
          do
          {
            v45 = *v43;
            *v43++ = *v42;
            *v42++ = v45;
          }
          while ( v43 < v95 );
        }
      }
      v46 = &high[-step];
      if ( ((int (__cdecl *)(char *, char *))cmp)(a1: &high[-step], a2: end) >= 0 )
      {
        if ( ((int (__cdecl *)(char *, char *))cmp)(a1: high, a2: v46) < 0 )
        {
          if ( ptr_cmp != 0 )
          {
            v50 = high;
            v51 = *(_DWORD *)v46;
            *(_DWORD *)v46 = *(_DWORD *)high;
            *(_DWORD *)v50 = v51;
          }
          else
          {
            v52 = high;
            v53 = v46;
            v95 = &v46[v6];
            do
            {
              tmp = *v53;
              *v53++ = *v52;
              *v52++ = tmp;
            }
            while ( v53 < v95 );
          }
        }
      }
      else
      {
        v47 = end;
        if ( ptr_cmp != 0 )
        {
          v48 = *(_DWORD *)v46;
          *(_DWORD *)v46 = *(_DWORD *)end;
          *(_DWORD *)v47 = v48;
        }
        else
        {
          v49 = v46;
          v95 = &v46[v6];
          do
          {
            tmp = *v49;
            *v49++ = *v47;
            *v47++ = tmp;
          }
          while ( v49 < v95 );
        }
      }
      if ( ((int (__cdecl *)(char *, _DWORD *))cmp)(a1: v46, a2: v97) < 0 )
      {
        v54 = v97;
        if ( ptr_cmp != 0 )
        {
          v55 = *(_DWORD *)v46;
          *(_DWORD *)v46 = *v97;
          *v54 = v55;
        }
        else
        {
          v56 = v46;
          v95 = &v46[v6];
          do
          {
            tmp = *v56;
            *v56++ = *(_BYTE *)v54;
            *(_BYTE *)v54 = tmp;
            v54 = (_DWORD *)((char *)v54 + 1);
          }
          while ( v56 < v95 );
        }
      }
      if ( ((int (__cdecl *)(char *, _DWORD *))cmp)(a1: v15, a2: v97) < 0 )
      {
        if ( ptr_cmp != 0 )
        {
          v57 = v97;
          v58 = *(_DWORD *)v15;
          v59 = high;
          *(_DWORD *)v15 = *v97;
          v60 = low;
          *v57 = v58;
        }
        else
        {
          v61 = (char *)v97;
          v62 = v15;
          v63 = &v15[v6];
          do
          {
            v64 = *v62;
            *v62++ = *v61;
            *v61++ = v64;
          }
          while ( v62 < v63 );
          v60 = low;
          v59 = high;
        }
        goto LABEL_103;
      }
      if ( ((int (__cdecl *)(char *, char *))cmp)(a1: v46, a2: v15) >= 0 )
        goto LABEL_85;
      if ( ptr_cmp == 0 )
        break;
      v65 = *(_DWORD *)v15;
      *(_DWORD *)v15 = *(_DWORD *)v46;
      v60 = low;
      *(_DWORD *)v46 = v65;
      v59 = high;
LABEL_103:
      memcpy(dst: (unsigned __int8 *)pivot, src: (unsigned __int8 *)mid, count: v6);
      while ( 1 )
      {
        for ( ; ((int (__cdecl *)(char *, char *))cmp)(a1: v60, a2: pivot) < 0; v60 += v6 )
          ;
        for ( ; ((int (__cdecl *)(char *, char *))cmp)(a1: pivot, a2: v59) < 0; v59 -= v6 )
          ;
        if ( v60 >= v59 )
          break;
        if ( ptr_cmp != 0 )
        {
          v81 = *(_DWORD *)v60;
          *(_DWORD *)v60 = *(_DWORD *)v59;
          *(_DWORD *)v59 = v81;
        }
        else
        {
          v82 = v60;
          v83 = v59;
          do
          {
            tmp = *v82;
            *v82 = *v83;
            *v83 = tmp;
            ++v82;
            ++v83;
          }
          while ( v82 < &v60[v6] );
        }
        v60 += v6;
        v59 -= v6;
        if ( v60 > v59 )
          goto LABEL_117;
      }
      if ( v60 == v59 )
      {
        v60 += v6;
        v59 -= v6;
      }
LABEL_117:
      if ( v59 - low > 0 )
      {
        v85 = high;
        result = (char *)(high - v60);
        if ( high - v60 > 0 )
        {
          v86 = v59 - low <= (int)result;
          v87 = v94;
          if ( v86 )
          {
            *(_DWORD *)v94 = v60;
            *((_DWORD *)v87 + 1) = v85;
            high = v59;
          }
          else
          {
            *(_DWORD *)v94 = low;
            *((_DWORD *)v87 + 1) = v59;
            low = v60;
          }
          result = v87 + 8;
          goto LABEL_127;
        }
        high = v59;
      }
      else
      {
        result = (char *)(high - v60);
        if ( high - v60 <= 0 )
        {
          v84 = *((char **)v94 - 1);
          result = v94 - 8;
          low = *((char **)v94 - 2);
          high = v84;
LABEL_127:
          v94 = result;
          goto LABEL_128;
        }
        low = v60;
      }
LABEL_128:
      v7 = (unsigned int)low;
LABEL_129:
      if ( v94 <= &v89 )
        return result;
    }
    v66 = v15;
    v67 = &v15[v6];
    do
    {
      v68 = *v66;
      *v66++ = *v46;
      *v46++ = v68;
    }
    while ( v66 < v67 );
LABEL_85:
    v60 = low;
    v59 = high;
    goto LABEL_103;
  }
  return result;
}
