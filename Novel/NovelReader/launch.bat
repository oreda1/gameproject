@echo off
echo ==========================================
echo           NOVEL READER LAUNCHER
echo ==========================================
echo.
echo Choose version to run:
echo 1. English version
echo 2. Japanese version
echo 3. Exit
echo.
set /p choice="Enter your choice (1-3): "

if "%choice%"=="1" (
    echo.
    echo Starting English version...
    novel_reader_eng.exe
) else if "%choice%"=="2" (
    echo.
    echo Starting Japanese version...
    novel_reader_jp.exe
) else if "%choice%"=="3" (
    echo.
    echo Goodbye!
    exit /b 0
) else (
    echo.
    echo Invalid choice. Please run the launcher again.
)

echo.
pause
