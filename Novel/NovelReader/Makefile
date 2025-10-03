# Makefile for Novel Reader
# Windows用のコンパイル設定

CXX = g++
CXXFLAGS = -std=c++11 -Wall -O2
TARGET = novel_reader.exe
SOURCE = novel_reader.cpp

# デフォルトターゲット
all: $(TARGET)

# メインの実行ファイルをビルド
$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE)

# クリーンアップ
clean:
	del /Q $(TARGET) 2>nul || echo "ファイルが見つかりません"

# プログラムを実行
run: $(TARGET)
	./$(TARGET)

# ヘルプ
help:
	@echo "利用可能なコマンド:"
	@echo "  make        - プログラムをコンパイル"
	@echo "  make run    - プログラムをコンパイルして実行"
	@echo "  make clean  - 生成されたファイルを削除"
	@echo "  make help   - このヘルプを表示"

.PHONY: all clean run help
