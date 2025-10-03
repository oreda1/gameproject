@echo off
echo Initializing Visual Studio environment...
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

echo Compiling English version...
cl /EHsc novel_reader_eng.cpp /Fe:novel_reader_eng.exe

if %errorlevel% equ 0 (
    echo Compilation completed successfully!
    echo Executable: novel_reader_eng.exe
    echo.
    echo To run: novel_reader_eng.exe
) else (
    echo Compilation error occurred.
)

pause
