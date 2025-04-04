// <werrmsg.cpp>
char const FILE_TIME_STAMP[] = "Time-stamp: <2025-04-04 11:54:53 neige>";
//
// Project werrmsg
// Copyright (C) 2025 neige68
//
/// \file
/// \brief werrmsg
//
// Compiler: VC14.2
//

#include "pch.h"
#pragma hdrstop

#include "windows.h"

#include <exception>
#include <filesystem>
#include <iostream>

using namespace std;

//------------------------------------------------------------

// GetLastError の値を対応するメッセージに変換する
wstring ErrorMessageW(DWORD id, DWORD dwLanguageId = 0)
{
    wchar_t* retbuf = nullptr;
    FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS
                  | FORMAT_MESSAGE_MAX_WIDTH_MASK,
                  0, id, dwLanguageId, (LPWSTR)&retbuf, 1, 0);
    wstring result(retbuf ? retbuf : L"");
    LocalFree(retbuf);
    return result;
}

void process(const char* arg)
{
    DWORD ec = strtol(arg, nullptr, 0);
    wcout << L"Error Code: " << ec << endl;
    wcout << L"[Default Language Message] " << ErrorMessageW(ec) << endl;
    wcout << L"[English Message] " << ErrorMessageW(ec, MAKELANGID(LANG_ENGLISH, SUBLANG_DEFAULT)) << endl;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
    try {
        locale::global(locale{locale{}, "", locale::ctype});
        if (argc == 1) {
            wcout << L"werrmsg - Show Windows error message converted from code in default language & English"
                  << endl;
            wcout << endl;
            wcout << L"usage: werrmsg <Error-Code>..." << endl;
            wcout << endl;
            wcout << L"eg: werrmsg 2 10048" << endl;
            wcout << endl;
            wcout << L"<Error-Code> is a decimal or a 0x-prefixed hexadecimal etc." << endl;
            wcout << endl;
            wcout << filesystem::path(FILE_TIME_STAMP).wstring() << endl;
            return 0;
        }
        while (--argc)
            process(*++argv);
    }
    catch (const exception& x) {
        wcerr << L"ERROR: " << x.what() << endl;
    }
    return 0;
}

//------------------------------------------------------------

// end of <werrmsg.cpp>
