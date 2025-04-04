# <CMakeLists.txt> -*- coding: utf-8 -*-
#
# Project werrmsg
# Copyright (C) 2025 neige68
#

cmake_minimum_required(VERSION 3.28)
set(CMAKE_VERBOSE_MAKEFILE ON)
cmake_policy(SET CMP0167 OLD)
# スタティックリンク
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

project(werrmsg CXX)

#------------------------------------------------------------

# C++20 使用
set(CMAKE_CXX_STANDARD "20")

# /MP: マルチプロセス
# /W4: 警告レベルを4とする
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP /W4")

# マップファイル生成
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /MAP")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /MAP")

# ローカルインクルードファイルの場所を追加
include_directories($ENV{LOCALINCLUDE})

add_compile_definitions(_CRT_RAND_S NOMINMAX)

#add_subdirectory(neige1)

add_executable(werrmsg werrmsg.cpp pch.cpp)

# /Yu: プリコンパイルヘッダを使用
add_compile_options("/Yu \"pch.h\"")
# /Yc: プリコンパイルヘッダを生成
set_source_files_properties(pch.cpp PROPERTIES COMPILE_FLAGS "/Yc\"pch.h\"")

# テスト対応
enable_testing()

# end of <CMakeLists.txt>
