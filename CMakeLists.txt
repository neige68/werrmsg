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
# /UTF8: ソースおよび実行文字セットを UTF-8 とする
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP /W4 /UTF8")

add_compile_definitions(_CRT_RAND_S NOMINMAX)

add_executable(werrmsg werrmsg.cpp pch.cpp)

# /Yu: プリコンパイルヘッダを使用
add_compile_options("/Yu \"pch.h\"")
# /Yc: プリコンパイルヘッダを生成
set_source_files_properties(pch.cpp PROPERTIES COMPILE_FLAGS "/Yc\"pch.h\"")

# テスト対応
enable_testing()

# end of <CMakeLists.txt>
