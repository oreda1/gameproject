@echo off
echo Visual Studio環境を初期化中...
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

echo コンパイル中...
cl /EHsc /std:c++11 novel_reader.cpp

if %errorlevel% equ 0 (
    echo コンパイルが完了しました！
    echo 実行ファイル: novel_reader.exe
    echo.
    echo 実行するには: novel_reader.exe
) else (
    echo コンパイルエラーが発生しました。
)

pause
