// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/makeprefablibrary.cpp
// Functions: 2
// ============================================================

#include "hammer\makeprefablibrary.h"

//------------------------------------------------------------------------------
// Address: 0x10058160
// Name: public: void ATL::CSimpleStringT<char,0>::ReleaseBuffer(int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100581B0
// Name: void MakePrefabLibrary(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MakePrefabLibrary(const char *pszName)
{
  CPrefabLibraryRMF *v1; // eax
  CPrefabLibrary *v2; // edi
  int i; // eax
  bool v4; // zf
  const char *v5; // eax
  int v6; // eax
  int v7; // eax
  CPrefabRMF *v8; // eax
  CPrefabRMF *v9; // esi
  CPrefabRMF *v10; // eax
  CObject *v11; // ebx
  CAfxStringMgr *StringManager; // eax
  char *m_pszData; // esi
  HINSTANCE__ *StringResourceHandle; // eax
  int v15; // edi
  int v16; // eax
  int v17; // eax
  char *v18; // esi
  char v19; // al
  char *v20; // ecx
  char *j; // edx
  char *v22; // eax
  char v23; // cl
  int v24; // edx
  int v25; // eax
  char *cFileName; // [esp-Ch] [ebp-A2Ch]
  int v27; // [esp-8h] [ebp-A28h]
  unsigned int v28; // [esp-4h] [ebp-A24h]
  char szBuffer2[1024]; // [esp+Ch] [ebp-A14h] BYREF
  char szBuffer[1024]; // [esp+40Ch] [ebp-614h] BYREF
  _WIN32_FIND_DATAA fd; // [esp+80Ch] [ebp-214h] BYREF
  std::ifstream tfile; // [esp+94Ch] [ebp-D4h] BYREF
  _BYTE *v33; // [esp+9FCh] [ebp-24h]
  void *hnd; // [esp+A00h] [ebp-20h]
  void *p; // [esp+A04h] [ebp-1Ch]
  int nPrefabs; // [esp+A08h] [ebp-18h]
  CPrefabLibrary *v37; // [esp+A0Ch] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strTextFile; // [esp+A10h] [ebp-10h] BYREF
  int v39; // [esp+A1Ch] [ebp-4h]

  v1 = (CPrefabLibraryRMF *)operator new(nSize: 0x300u);
  hnd = v1;
  v39 = 0;
  if ( v1 != nullptr )
    v37 = CPrefabLibraryRMF::CPrefabLibraryRMF(this: v1);
  else
    v37 = nullptr;
  v39 = -1;
  nPrefabs = 0;
  printf(format: "Making prefab library %s.ol\n", pszName);
  v2 = v37;
  v37->SetName(this: v37, a2: pszName);
  CPrefab::EnableCaching(b: 0);
  for ( i = bFirst_1; ; i = 0 )
  {
    v4 = i == 0;
    v5 = "*.rmf";
    if ( v4 )
      v5 = "*.map";
    hnd = FindFirstFileA(lpFileName: v5, lpFindFileData: &fd);
    if ( hnd != (void *)-1 )
    {
      while ( 1 )
      {
        v6 = CPrefab::CheckFileType(pszFilename: fd.cFileName);
        if ( v6 != 0 )
        {
          v7 = v6 - 1;
          if ( v7 != 0 )
          {
            if ( v7 != 1 )
              goto LABEL_54;
            v8 = (CPrefabRMF *)operator new(nSize: 0x22Cu);
            p = v8;
            v39 = 2;
            if ( v8 != nullptr )
              v9 = CPrefabRMF::CPrefabRMF(this: v8);
            else
              v9 = nullptr;
            v39 = -1;
            v28 = 1;
            v27 = 1;
            cFileName = fd.cFileName;
          }
          else
          {
            v10 = (CPrefabRMF *)operator new(nSize: 0x22Cu);
            p = v10;
            v39 = 1;
            if ( v10 != nullptr )
              v9 = CPrefabRMF::CPrefabRMF(this: v10);
            else
              v9 = nullptr;
            v39 = -1;
            v28 = 0;
            v27 = 1;
            cFileName = fd.cFileName;
          }
          v11 = (CObject *)v9;
          if ( CPrefabRMF::Init(this: v9, pszFilename: cFileName, bLoadNow: v27, dwFlags: v28) == -1 )
          {
            if ( v9 != nullptr )
              ((void (__stdcall *)(int))v9->dtr_CPrefab)(a1: 1);
          }
          else if ( v9 != nullptr )
          {
            printf(format: "  including %s\n", fd.cFileName);
            ++nPrefabs;
            StringManager = AfxGetStringManager();
            if ( StringManager == nullptr )
              ATL::AtlThrowImpl(hr: -2147467259);
            m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
            strTextFile.m_pszData = m_pszData;
            v39 = 3;
            if ( ((unsigned int)fd.cFileName & 0xFFFF0000) != 0 )
            {
              ATL::CSimpleStringT<char,0>::SetString(
                this: &strTextFile,
                pszSrc: fd.cFileName,
                nLength: strlen(fd.cFileName));
LABEL_28:
              m_pszData = strTextFile.m_pszData;
            }
            else
            {
              StringResourceHandle = AfxFindStringResourceHandle(__formal: (unsigned __int16)fd.cFileName);
              if ( StringResourceHandle != nullptr )
              {
                ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                  this: &strTextFile,
                  hInstance: StringResourceHandle,
                  nID: (unsigned __int16)fd.cFileName);
                goto LABEL_28;
              }
            }
            v39 = 4;
            if ( *((int *)m_pszData - 3) > 0 )
            {
              _mbschr(string: m_pszData, c: 0x2Eu);
              if ( v16 != 0 )
                v15 = v16 - (_DWORD)m_pszData;
              else
                v15 = -1;
            }
            else
            {
              v15 = -1;
            }
            if ( ((1 - *((_DWORD *)m_pszData - 1)) | *((_DWORD *)m_pszData - 2)) < 0 )
            {
              ATL::CSimpleStringT<char,0>::PrepareWrite2(this: &strTextFile, nLength: 0);
              m_pszData = strTextFile.m_pszData;
            }
            m_pszData[v15] = 0;
            v17 = strnlen(str: m_pszData, maxsize: *((_DWORD *)m_pszData - 2));
            if ( v17 < 0 || v17 > *((_DWORD *)m_pszData - 2) )
              ATL::AtlThrowImpl(hr: -2147024809);
            v28 = 4;
            *((_DWORD *)m_pszData - 3) = v17;
            v27 = (int)".txt";
            m_pszData[v17] = 0;
            ATL::CSimpleStringT<char,0>::Append(this: &strTextFile, pszSrc: (char *)v27, nLength: v28);
            v18 = strTextFile.m_pszData;
            if ( GetFileAttributesA(lpFileName: strTextFile.m_pszData) != -1 )
            {
              std::ifstream::ifstream(this: &tfile, _Filename: v18, _Mode: 1, _Prot: 64, a5: 1);
              LOBYTE(v39) = 5;
              memset(dst: (unsigned __int8 *)szBuffer, value: 0, count: sizeof(szBuffer));
              std::istream::read(this: &tfile, _Str: szBuffer, _Count: 1023);
              v19 = szBuffer[0];
              v20 = szBuffer;
              for ( j = szBuffer2; v19 != 0; ++v20 )
              {
                if ( v19 != 10 && v19 != 13 )
                  *j++ = v19;
                v19 = v20[1];
              }
              *j = 0;
              v22 = (char *)&v11[8].__vftable + 3;
              do
              {
                v23 = v22[szBuffer2 - ((char *)&v11[8].__vftable + 3)];
                *v22++ = v23;
              }
              while ( v23 != 0 );
              LOBYTE(v39) = 4;
              v24 = *(_DWORD *)(*(_DWORD *)tfile.gap0 + 4);
              p = tfile.gap68;
              *(_DWORD *)&tfile.gap0[v24] = &std::ifstream::`vftable';
              v33 = tfile.gap10;
              *(_DWORD *)tfile.gap10 = &std::filebuf::`vftable';
              LOBYTE(v39) = 8;
              if ( *(_DWORD *)&tfile._Filebuffer[12] != 0
                && **(std::ifstream ***)&tfile.gap10[16] == (std::ifstream *)tfile._Filebuffer )
              {
                v25 = *(_DWORD *)&tfile.gap10[64];
                **(_DWORD **)&tfile.gap10[16] = *(_DWORD *)&tfile.gap10[60];
                **(_DWORD **)&tfile.gap10[32] = v25;
                **(_DWORD **)&tfile.gap10[48] = 0;
              }
              if ( tfile._Filebuffer[8] != 0 )
                std::filebuf::close(this: (std::filebuf *)tfile.gap10);
              LOBYTE(v39) = 6;
              std::streambuf::~streambuf<char,std::char_traits<char>>(this: (std::streambuf *)tfile.gap10);
              LOBYTE(v39) = 4;
              *(_DWORD *)&tfile.gap0[*(_DWORD *)(*(_DWORD *)tfile.gap0 + 4)] = &std::istream::`vftable';
              v33 = tfile.gap68;
              LOBYTE(v39) = 4;
              *(_DWORD *)tfile.gap68 = &std::ios_base::`vftable';
              std::ios_base::_Ios_base_dtor(_This: (std::ios_base *)tfile.gap68);
            }
            CPrefabLibrary::Add(this: v37, pPrefab: v11);
            v39 = -1;
            if ( _InterlockedDecrement((volatile signed __int32 *)v18 - 1) <= 0 )
              (*(void (__stdcall **)(char *))(**((_DWORD **)v18 - 4) + 4))(a1: v18 - 16);
          }
        }
LABEL_54:
        if ( !FindNextFileA(hFindFile: hnd, lpFindFileData: &fd) )
        {
          v2 = v37;
          break;
        }
      }
    }
    if ( bFirst_1 == 0 )
      break;
    bFirst_1 = 0;
  }
  v2->Save(this: v2, a2: nullptr, a3: 0);
  CPrefab::FreeAllData();
  CPrefab::EnableCaching(b: 1);
  printf(format: "%d prefabs in library.\n", nPrefabs);
}
