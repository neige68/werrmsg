// <pch.h>
//
// Project werrmsg
// Copyright (C) 2025 neige68
//
/// \file
/// \brief Precompile header
//
// Compiler: VC14.2
//

#ifndef pch_h
#define pch_h

#if defined(_OWLALLPCH)
// _OWLALLPCH を #define し <owl/pch.h> を #include して <winsock2.h> を使用する場合、
// <owl/pch.h> より先に <winsock2.h> を #include しなければならない
//
// <owl/owlall.h> から #include される <owl/winsock.h> が <winsock.h> または <winsock2.h> を必要とするので、
// WIN32_LEAN_AND_MEAN や _WINSOCKAPI_ の #define ではだめである
# include <winsock2.h>
#endif

#if defined(_OWLPCH) || defined(_OWLALLPCH) // for OWL
# include <owl/pch.h>
#elif defined(_WIN32)           // for Win32 Console
# ifndef STRICT
#  define STRICT
# endif
# ifndef NOMINMAX
#  define NOMINMAX
# endif
// <winsock2.h> を後で #include する場合、以下2行のどちらかが必要である
# define WIN32_LEAN_AND_MEAN // <windows.h> で間接的に #include されるファイルを削減
//# define _WINSOCKAPI_ // <windows.h> で <winsock.h> を #include しないようにする
# include <windows.h>
#else  // others
// nothing
#endif

// common
#include <bits/stdc++.h>

#endif // pch_h

// end of <pch.h>
