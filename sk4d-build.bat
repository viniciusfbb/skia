@echo off

rem #
rem # Copyright (c) 2011-2022 Google LLC.
rem # Copyright (c) 2021-2022 Skia4Delphi Project.
rem #
rem # Use of this source code is governed by a BSD-style license that can be
rem # found in the LICENSE file.
rem #

setlocal

python --version >nul 2>&1 && goto :RUN

echo Python not found.
echo.
echo Python can be installed in two ways:
echo   - Installation downloaded from official web site (https://www.python.org);
echo   - Using the chocolatey package manager: 'choco install -y python'.
echo.
echo * Make sure it has been added to the PATH environment variable and reopen the terminal.
goto :EOF

:RUN
set SCRIPT_DIR=%~dp0
pushd "%SCRIPT_DIR%"
set PATH=%SCRIPT_DIR%sk4d\bin;%PATH%
python "%SCRIPT_DIR%sk4d\scripts\build.py" %*
popd

endlocal
