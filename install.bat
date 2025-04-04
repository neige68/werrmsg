@rem install.bat -*- coding: cp932-dos -*-
@echo off
rem
rem Project werrmsg
rem Copyright (C) 2025 neige68
rem
rem Note: install
rem
rem Windows:   10 and later
rem

setlocal
title %~f0
pushd %~dp0

set @noendpause=
:optloop
if "%1"=="" goto optend
rem -b: 最後に pause しない
if "%1"=="-b" set @noendpause=-b
if "%1"=="-b" goto optnext
echo WARN: %~f0: 引数 %1 は無視しました.
:optnext
shift /1
goto optloop
:optend

rem ************************************************************

replace /a build\release\werrmsg.exe %LOCALBIN%\
replace /u build\release\werrmsg.exe %LOCALBIN%\

rem エラーの時
if errorlevel 1 goto end

rem コマンドを実行する前
title %~f0: piyo

rem ************************************************************

:end
popd
echo INFO: %~f0: end @%TIME%
title %~f0: end @%TIME%
if "%@noendpause%"=="" pause
@rem end of install.bat
