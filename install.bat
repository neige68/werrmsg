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
rem -b: �Ō�� pause ���Ȃ�
if "%1"=="-b" set @noendpause=-b
if "%1"=="-b" goto optnext
echo WARN: %~f0: ���� %1 �͖������܂���.
:optnext
shift /1
goto optloop
:optend

rem ************************************************************

replace /a build\release\werrmsg.exe %LOCALBIN%\
replace /u build\release\werrmsg.exe %LOCALBIN%\

rem �G���[�̎�
if errorlevel 1 goto end

rem �R�}���h�����s����O
title %~f0: piyo

rem ************************************************************

:end
popd
echo INFO: %~f0: end @%TIME%
title %~f0: end @%TIME%
if "%@noendpause%"=="" pause
@rem end of install.bat
