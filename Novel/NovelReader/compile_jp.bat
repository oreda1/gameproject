@echo off
echo Initializing Visual Studio environment...
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

echo Compiling Japanese version...
cl /EHsc /utf-8 novel_reader_jp.cpp /Fe:novel_reader_jp.exe

if %errorlevel% equ 0 (
    echo Compilation completed successfully!
    echo Executable: novel_reader_jp.exe
    echo.
    echo To run: novel_reader_jp.exe
) else (
    echo Compilation error occurred.
)

pause
