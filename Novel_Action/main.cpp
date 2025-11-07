#include "NovelEngine.h"
#include <iostream>
#include <string>
#include <DxLib.h>
int main() {
    // DxLibを使用した新しい小説リーダーエンジンを初期化
    NovelEngine engine;
    
    // エンジンの初期化（1024x768のウィンドウサイズ）
    if (!engine.initialize(1024, 768)) {
        std::cerr << "Failed to initialize Novel Engine." << std::endl;
        return -1;
    }
    
    // デフォルトの小説ファイルを設定
    engine.setNovelFilename("novel.txt");
    
    //メインループの実行
    engine.run();
    
    return 0;
}
