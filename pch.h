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
// _OWLALLPCH �� #define �� <owl/pch.h> �� #include ���� <winsock2.h> ���g�p����ꍇ�A
// <owl/pch.h> ����� <winsock2.h> �� #include ���Ȃ���΂Ȃ�Ȃ�
//
// <owl/owlall.h> ���� #include ����� <owl/winsock.h> �� <winsock.h> �܂��� <winsock2.h> ��K�v�Ƃ���̂ŁA
// WIN32_LEAN_AND_MEAN �� _WINSOCKAPI_ �� #define �ł͂��߂ł���
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
// <winsock2.h> ����� #include ����ꍇ�A�ȉ�2�s�̂ǂ��炩���K�v�ł���
# define WIN32_LEAN_AND_MEAN // <windows.h> �ŊԐړI�� #include �����t�@�C�����팸
//# define _WINSOCKAPI_ // <windows.h> �� <winsock.h> �� #include ���Ȃ��悤�ɂ���
# include <windows.h>
#else  // others
// nothing
#endif

// common
#include <bits/stdc++.h>

#endif // pch_h

// end of <pch.h>
