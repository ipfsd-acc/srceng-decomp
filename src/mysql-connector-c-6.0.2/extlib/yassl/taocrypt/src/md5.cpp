// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/taocrypt/src/md5.cpp
// Functions: 8
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\taocrypt\src\md5.h"

//------------------------------------------------------------------------------
// Address: 0x00424830
// Name: public: class yaSSL::MD5 __near & yaSSL::MD5::operator=(class yaSSL::MD5 const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::MD5::operator=(
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *this,
        int (__cdecl *that)(KeyValues *const *, KeyValues *const *))
{
  TaoCrypt::MD5::operator=(
    this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_Memory.m_nAllocationCount,
    that: *((_DWORD *)that + 1));
}

//------------------------------------------------------------------------------
// Address: 0x00426DE0
// Name: public: virtual void TaoCrypt::MD5::Init(void)
// Source: json
//------------------------------------------------------------------------------
const CUtlString *__thiscall TaoCrypt::MD5::Init(CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  this->m_pElements = (CUtlString *)1732584193;
  *((_DWORD *)this + 5) = -271733879;
  *((_DWORD *)this + 6) = -1732584194;
  *((_DWORD *)this + 7) = 271733878;
  this->m_Memory.m_nAllocationCount = 0;
  this->m_Memory.m_nGrowSize = 0;
  this->m_Size = 0;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00426E10
// Name: public: TaoCrypt::MD5::MD5(class TaoCrypt::MD5 const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::MD5::MD5(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this@<ecx>,
        CUtlString *that,
        int a3,
        int a4)
{
  TaoCrypt::HASHwithTransform::HASHwithTransform(
    (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)this,
    digSz: 4);
  this->m_Memory.m_pMemory = (CUtlString *)&TaoCrypt::MD5::`vftable';
  this->m_Memory.m_nAllocationCount = that->m_Storage.m_Memory.m_nAllocationCount;
  this->m_Memory.m_nGrowSize = that->m_Storage.m_Memory.m_nGrowSize;
  this->m_Size = that->m_Storage.m_nActualLength;
  *(CUtlString *)&this->m_pElements = that[1];
  qmemcpy((char *)this + 48, &that[3], 0x40u);
}

//------------------------------------------------------------------------------
// Address: 0x00426E70
// Name: private: void TaoCrypt::MD5::AsmTransform(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00427500
// Name: private: virtual void TaoCrypt::MD5::Transform(void)
// Source: json
//------------------------------------------------------------------------------
const CUtlString *__thiscall TaoCrypt::MD5::Transform(CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  int v1; // edx
  int v2; // esi
  int v3; // edi
  int v4; // eax
  int v5; // edx
  int v6; // esi
  int v7; // edi
  int v8; // eax
  int v9; // edx
  int v10; // esi
  int v11; // edi
  int v12; // eax
  int v13; // edx
  int v14; // esi
  int v15; // edi
  int v16; // eax
  int v17; // edx
  int v18; // esi
  int v19; // edi
  int v20; // eax
  int v21; // edx
  int v22; // esi
  int v23; // edi
  int v24; // eax
  int v25; // edx
  int v26; // esi
  int v27; // edi
  int v28; // eax
  int v29; // edx
  int v30; // esi
  int v31; // edi
  int v32; // eax
  int v33; // edx
  int v34; // esi
  int v35; // edi
  int v36; // eax
  int v37; // edx
  int v38; // ebx
  int v39; // esi
  int v40; // eax
  int v41; // edi
  int v42; // ebx
  int v43; // edx
  int v44; // eax
  int v45; // esi
  int v46; // edi
  int v47; // edx
  int v48; // eax
  int v49; // esi
  int v50; // ebx
  int v51; // edi
  int v52; // edx
  int v53; // eax
  int v54; // esi
  int v55; // edi
  int v56; // edx
  int v57; // eax
  int v58; // esi
  int v59; // edi
  int v60; // edx
  int v61; // eax
  int v62; // esi
  int v63; // edi
  int v64; // edx
  int v65; // eax
  int v66; // esi
  int v67; // edi
  CUtlString *v68; // ebx
  const CUtlString *result; // eax

  v1 = *((_DWORD *)this + 7);
  v2 = *((_DWORD *)this + 6);
  v3 = *((_DWORD *)this + 5);
  v4 = v3 + __ROL4__((char *)&this->m_pElements[-42554808] + (v1 ^ v3 & (v2 ^ v1)) + *((_DWORD *)this + 12) - 8, 7);
  v5 = v4 + __ROL4__(v1 + *((_DWORD *)this + 13) + (v2 ^ v4 & (v3 ^ v2)) - 389564586, 12);
  v6 = v5 + __ROL4__(v2 + *((_DWORD *)this + 14) + (v3 ^ v5 & (v4 ^ v3)) + 606105819, 17);
  v7 = v6 + __ROL4__(v3 + *((_DWORD *)this + 15) + (v4 ^ v6 & (v4 ^ v5)) - 1044525330, 22);
  v8 = v7 + __ROL4__(v4 + *((_DWORD *)this + 16) + (v5 ^ v7 & (v6 ^ v5)) - 176418897, 7);
  v9 = v8 + __ROL4__(v5 + *((_DWORD *)this + 17) + (v6 ^ v8 & (v7 ^ v6)) + 1200080426, 12);
  v10 = v9 + __ROL4__(v6 + *((_DWORD *)this + 18) + (v7 ^ v9 & (v8 ^ v7)) - 1473231341, 17);
  v11 = v10 + __ROL4__(v7 + *((_DWORD *)this + 19) + (v8 ^ v10 & (v8 ^ v9)) - 45705983, 22);
  v12 = v11 + __ROL4__(v8 + *((_DWORD *)this + 20) + (v9 ^ v11 & (v10 ^ v9)) + 1770035416, 7);
  v13 = v12 + __ROL4__(v9 + *((_DWORD *)this + 21) + (v10 ^ v12 & (v11 ^ v10)) - 1958414417, 12);
  v14 = v13 + __ROL4__(v10 + *((_DWORD *)this + 22) + (v11 ^ v13 & (v12 ^ v11)) - 42063, 17);
  v15 = v14 + __ROL4__(v11 + *((_DWORD *)this + 23) + (v12 ^ v14 & (v12 ^ v13)) - 1990404162, 22);
  v16 = v15 + __ROL4__(v12 + *((_DWORD *)this + 24) + (v13 ^ v15 & (v14 ^ v13)) + 1804603682, 7);
  v17 = v16 + __ROL4__(v13 + *((_DWORD *)this + 25) + (v14 ^ v16 & (v15 ^ v14)) - 40341101, 12);
  v18 = v17 + __ROL4__(v14 + *((_DWORD *)this + 26) + (v15 ^ v17 & (v16 ^ v15)) - 1502002290, 17);
  v19 = v18 + __ROL4__(v15 + *((_DWORD *)this + 27) + (v16 ^ v18 & (v16 ^ v17)) + 1236535329, 22);
  v20 = v19 + __ROL4__(*((_DWORD *)this + 13) + (v18 ^ v17 & (v19 ^ v18)) + v16 - 165796510, 5);
  v21 = v20 + __ROL4__(*((_DWORD *)this + 18) + (v19 ^ v18 & (v20 ^ v19)) + v17 - 1069501632, 9);
  v22 = v21 + __ROL4__(*((_DWORD *)this + 23) + (v20 ^ v19 & (v20 ^ v21)) + v18 + 643717713, 14);
  v23 = v22 + __ROL4__(*((_DWORD *)this + 12) + (v21 ^ v20 & (v22 ^ v21)) + v19 - 373897302, 20);
  v24 = v23 + __ROL4__(*((_DWORD *)this + 17) + (v22 ^ v21 & (v23 ^ v22)) + v20 - 701558691, 5);
  v25 = v24 + __ROL4__(*((_DWORD *)this + 22) + (v23 ^ v22 & (v24 ^ v23)) + v21 + 38016083, 9);
  v26 = v25 + __ROL4__(*((_DWORD *)this + 27) + (v24 ^ v23 & (v24 ^ v25)) + v22 - 660478335, 14);
  v27 = v26 + __ROL4__(*((_DWORD *)this + 16) + (v25 ^ v24 & (v26 ^ v25)) + v23 - 405537848, 20);
  v28 = v27 + __ROL4__(*((_DWORD *)this + 21) + (v26 ^ v25 & (v27 ^ v26)) + v24 + 568446438, 5);
  v29 = v28 + __ROL4__(*((_DWORD *)this + 26) + (v27 ^ v26 & (v28 ^ v27)) + v25 - 1019803690, 9);
  v30 = v29 + __ROL4__(*((_DWORD *)this + 15) + (v28 ^ v27 & (v28 ^ v29)) + v26 - 187363961, 14);
  v31 = v30 + __ROL4__(*((_DWORD *)this + 20) + (v29 ^ v28 & (v30 ^ v29)) + v27 + 1163531501, 20);
  v32 = v31 + __ROL4__(*((_DWORD *)this + 25) + (v30 ^ v29 & (v31 ^ v30)) + v28 - 1444681467, 5);
  v33 = v32 + __ROL4__(*((_DWORD *)this + 14) + (v31 ^ v30 & (v32 ^ v31)) + v29 - 51403784, 9);
  v34 = v33 + __ROL4__(*((_DWORD *)this + 19) + (v32 ^ v31 & (v32 ^ v33)) + v30 + 1735328473, 14);
  v35 = v34 + __ROL4__(*((_DWORD *)this + 24) + (v33 ^ v32 & (v34 ^ v33)) + v31 - 1926607734, 20);
  v36 = v35 + __ROL4__(*((_DWORD *)this + 17) + (v35 ^ v34 ^ v33) + v32 - 378558, 4);
  v37 = v36 + __ROL4__(*((_DWORD *)this + 20) + (v36 ^ v35 ^ v34) + v33 - 2022574463, 11);
  v38 = v37 + __ROL4__(*((_DWORD *)this + 23) + (v36 ^ v35 ^ v37) + v34 + 1839030562, 16);
  v39 = v38 + __ROL4__(*((_DWORD *)this + 26) + (v36 ^ v38 ^ v37) + v35 - 35309556, 23);
  v40 = v39 + __ROL4__(v36 + *((_DWORD *)this + 13) + (v39 ^ v38 ^ v37) - 1530992060, 4);
  v41 = v40 + __ROL4__(*((_DWORD *)this + 16) + (v40 ^ v39 ^ v38) + v37 + 1272893353, 11);
  v42 = v41 + __ROL4__(*((_DWORD *)this + 19) + (v40 ^ v39 ^ v41) + v38 - 155497632, 16);
  v43 = v42 + __ROL4__(*((_DWORD *)this + 22) + (v40 ^ v42 ^ v41) + v39 - 1094730640, 23);
  v44 = v43 + __ROL4__(v40 + *((_DWORD *)this + 25) + (v43 ^ v42 ^ v41) + 681279174, 4);
  v45 = v44 + __ROL4__(*((_DWORD *)this + 12) + (v44 ^ v43 ^ v42) + v41 - 358537222, 11);
  v46 = v45 + __ROL4__(*((_DWORD *)this + 15) + (v44 ^ v43 ^ v45) + v42 - 722521979, 16);
  v47 = v46 + __ROL4__(v43 + *((_DWORD *)this + 18) + (v44 ^ v46 ^ v45) + 76029189, 23);
  v48 = v47 + __ROL4__(*((_DWORD *)this + 21) + (v47 ^ v46 ^ v45) + v44 - 640364487, 4);
  v49 = v48 + __ROL4__(*((_DWORD *)this + 24) + (v48 ^ v47 ^ v46) + v45 - 421815835, 11);
  v50 = *((_DWORD *)this + 14);
  v51 = v49 + __ROL4__(*((_DWORD *)this + 27) + (v48 ^ v47 ^ v49) + v46 + 530742520, 16);
  v52 = v51 + __ROL4__(v47 + v50 + (v48 ^ v51 ^ v49) - 995338651, 23);
  v53 = v52 + __ROL4__(v48 + *((_DWORD *)this + 12) + (v51 ^ (v52 | ~v49)) - 198630844, 6);
  v54 = v53 + __ROL4__(v49 + *((_DWORD *)this + 19) + (v52 ^ (v53 | ~v51)) + 1126891415, 10);
  v55 = v54 + __ROL4__(v51 + *((_DWORD *)this + 26) + (v53 ^ (v54 | ~v52)) - 1416354905, 15);
  v56 = v55 + __ROL4__(v52 + *((_DWORD *)this + 17) + (v54 ^ (v55 | ~v53)) - 57434055, 21);
  v57 = v56 + __ROL4__(v53 + *((_DWORD *)this + 24) + (v55 ^ (v56 | ~v54)) + 1700485571, 6);
  v58 = v57 + __ROL4__(v54 + *((_DWORD *)this + 15) + (v56 ^ (v57 | ~v55)) - 1894986606, 10);
  v59 = v58 + __ROL4__(v55 + *((_DWORD *)this + 22) + (v57 ^ (v58 | ~v56)) - 1051523, 15);
  v60 = v59 + __ROL4__(v56 + *((_DWORD *)this + 13) + (v58 ^ (v59 | ~v57)) - 2054922799, 21);
  v61 = v60 + __ROL4__(v57 + *((_DWORD *)this + 20) + (v59 ^ (v60 | ~v58)) + 1873313359, 6);
  v62 = v61 + __ROL4__(v58 + *((_DWORD *)this + 27) + (v60 ^ (v61 | ~v59)) - 30611744, 10);
  v63 = v62 + __ROL4__(v59 + *((_DWORD *)this + 18) + (v61 ^ (v62 | ~v60)) - 1560198380, 15);
  v64 = v63 + __ROL4__(v60 + *((_DWORD *)this + 25) + (v62 ^ (v63 | ~v61)) + 1309151649, 21);
  v65 = v64 + __ROL4__(v61 + *((_DWORD *)this + 16) + (v63 ^ (v64 | ~v62)) - 145523070, 6);
  v66 = v65 + __ROL4__(v62 + *((_DWORD *)this + 23) + (v64 ^ (v65 | ~v63)) - 1120210379, 10);
  v67 = v66 + __ROL4__(v63 + v50 + (v65 ^ (v66 | ~v64)) + 718787259, 15);
  v68 = (CUtlString *)((char *)this->m_pElements + v65);
  *((_DWORD *)this + 5) += v67 + __ROL4__(*((_DWORD *)this + 21) + (v66 ^ (v67 | ~v65)) + v64 - 343485551, 21);
  *((_DWORD *)this + 6) += v67;
  result = (const CUtlString *)(v66 + *((_DWORD *)this + 7));
  this->m_pElements = v68;
  *((_DWORD *)this + 7) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00427B00
// Name: public: void TaoCrypt::MD5::Swap(class TaoCrypt::MD5 __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::MD5::Swap(TaoCrypt::MD5 *this, struct TaoCrypt::MD5 *a2)
{
  int v2; // edx
  int v3; // edx
  int v4; // edx

  v2 = *((_DWORD *)this + 2);
  *((_DWORD *)this + 2) = *((_DWORD *)a2 + 2);
  *((_DWORD *)a2 + 2) = v2;
  v3 = *((_DWORD *)this + 3);
  *((_DWORD *)this + 3) = *((_DWORD *)a2 + 3);
  *((_DWORD *)a2 + 3) = v3;
  v4 = *((_DWORD *)this + 1);
  *((_DWORD *)this + 1) = *((_DWORD *)a2 + 1);
  *((_DWORD *)a2 + 1) = v4;
  *((_DWORD *)this + 4) = *((_DWORD *)a2 + 4);
  *((_DWORD *)this + 5) = *((_DWORD *)a2 + 5);
  *((_DWORD *)this + 6) = *((_DWORD *)a2 + 6);
  *((_DWORD *)this + 7) = *((_DWORD *)a2 + 7);
  qmemcpy((char *)this + 48, (char *)a2 + 48, 0x40u);
}

//------------------------------------------------------------------------------
// Address: 0x00427B60
// Name: public: virtual void TaoCrypt::MD5::Update(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::MD5::Update(TaoCrypt::HASHwithTransform *this, unsigned __int8 *src, unsigned int a3)
{
  int v4; // eax
  unsigned int v5; // ebx
  TaoCrypt::HASHwithTransform *v6; // ecx
  unsigned int v7; // edi
  unsigned __int8 *v8; // ebp
  unsigned int v9; // edi

  if ( TaoCrypt::isMMX )
  {
    v4 = *((_DWORD *)this + 1);
    v5 = a3;
    v6 = this + 12;
    if ( v4 != 0 )
    {
      v7 = 64 - v4;
      if ( a3 < 64 - v4 )
        v7 = a3;
      memcpy(dst: (unsigned __int8 *)v6 + v4, src, count: v7);
      *((_DWORD *)this + 1) += v7;
      v8 = &src[v7];
      v5 = a3 - v7;
      if ( *((_DWORD *)this + 1) == 64 )
      {
        (*(void (__thiscall **)(TaoCrypt::HASHwithTransform *))(*this + 32))(a1: this);
        TaoCrypt::HASHwithTransform::AddLength(this, a2: 0x40u);
        *((_DWORD *)this + 1) = 0;
      }
    }
    else
    {
      v8 = src;
    }
    if ( *((_DWORD *)this + 1) == 0 && v5 >> 6 != 0 )
    {
      TaoCrypt::MD5::AsmTransform((TaoCrypt::MD5 *)this, a2: v8, a3: v5 >> 6);
      v9 = v5 >> 6 << 6;
      TaoCrypt::HASHwithTransform::AddLength(this, a2: v9);
      v5 -= v9;
      v8 += v9;
    }
    if ( v5 != 0 )
    {
      memcpy(dst: (unsigned __int8 *)this + *((_DWORD *)this + 1) + 48, src: v8, count: v5);
      *((_DWORD *)this + 1) += v5;
    }
  }
  else
  {
    TaoCrypt::HASHwithTransform::Update(this, src, a3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427C30
// Name: public: class TaoCrypt::MD5 __near & TaoCrypt::MD5::operator=(class TaoCrypt::MD5 const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *__thiscall TaoCrypt::MD5::operator=(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        CUtlString *that)
{
  int v4; // [esp+0h] [ebp-74h]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > v5; // [esp+4h] [ebp-70h] BYREF

  TaoCrypt::MD5::MD5(this: &v5, that, a3: v4, a4: (int)v5.m_Memory.m_pMemory);
  TaoCrypt::MD5::Swap((TaoCrypt::MD5 *)this, a2: (struct TaoCrypt::MD5 *)&v5);
  return this;
}
