@echo off
echo ノベルリーダーをコンパイル中...
g++ -std=c++11 -Wall -O2 -o novel_reader.exe novel_reader.cpp

if %errorlevel% equ 0 (
    echo コンパイルが完了しました！
    echo 実行するには: novel_reader.exe
    echo または: novel_reader.exe novel.txt
) else (
    echo コンパイルエラーが発生しました。
    echo g++がインストールされているか確認してください。
)

pause
