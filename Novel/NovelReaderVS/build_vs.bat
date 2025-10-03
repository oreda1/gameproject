@echo off
echo Building Visual Studio project...
echo.

REM Initialize Visual Studio environment
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

echo Building solution...
msbuild NovelReaderVS.sln /p:Configuration=Release /p:Platform=x64

if %errorlevel% equ 0 (
    echo.
    echo Build successful!
    echo Executable location: NovelReaderVS\x64\Release\NovelReaderVS.exe
    echo.
    echo To run: NovelReaderVS\x64\Release\NovelReaderVS.exe
) else (
    echo.
    echo Build failed!
    echo Check the error messages above.
)

echo.
pause
