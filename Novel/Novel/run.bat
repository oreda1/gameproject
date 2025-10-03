@echo off
echo ノベルリーダーを起動中...
echo.

if exist novel_reader.exe (
    echo 実行ファイルが見つかりました。
    echo.
    novel_reader.exe
) else (
    echo 実行ファイルが見つかりません。
    echo まず build.bat を実行してコンパイルしてください。
    echo.
    pause
)
