#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <thread>
#include <chrono>

class NovelReader {
private:
    std::string filename;
    std::vector<std::string> lines;
    int currentLine;
    bool autoMode;
    int delayMs;

public:
    NovelReader(const std::string& file) : filename(file), currentLine(0), autoMode(false), delayMs(1500) {}
    
    bool loadFile() {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "エラー: ファイル '" << filename << "' を開けませんでした。" << std::endl;
            return false;
        }
        
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
        
        std::cout << "ファイルが正常に読み込まれました。行数: " << lines.size() << std::endl;
        return true;
    }
    
    void setAutoMode(bool autoMode) {
        this->autoMode = autoMode;
    }
    
    void setDelay(int ms) {
        delayMs = ms;
    }
    
    void clearScreen() {
        system("cls");
    }
    
    void displayHeader() {
        std::cout << "==========================================" << std::endl;
        std::cout << "           ノベルリーダー" << std::endl;
        std::cout << "==========================================" << std::endl;
        std::cout << "ファイル: " << filename << std::endl;
        std::cout << "現在の行: " << (currentLine + 1) << " / " << lines.size() << std::endl;
        std::cout << "==========================================" << std::endl;
        std::cout << std::endl;
    }
    
    void displayControls() {
        std::cout << std::endl;
        std::cout << "==========================================" << std::endl;
        std::cout << "操作:" << std::endl;
        std::cout << "  Enter: 次の行" << std::endl;
        std::cout << "  'a' + Enter: 自動モードON/OFF" << std::endl;
        std::cout << "  's' + Enter: 速度設定" << std::endl;
        std::cout << "  'r' + Enter: 最初から再開" << std::endl;
        std::cout << "  'q' + Enter: 終了" << std::endl;
        std::cout << "==========================================" << std::endl;
    }
    
    void startReading() {
        if (lines.empty()) {
            std::cout << "読み込む行がありません。" << std::endl;
            return;
        }
        
        char input;
        bool running = true;
        
        while (running && currentLine < lines.size()) {
            clearScreen();
            displayHeader();
            
            std::cout << lines[currentLine] << std::endl;
            
            if (autoMode) {
                std::cout << std::endl << "[自動モード - " << delayMs << "ms間隔]" << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
                currentLine++;
            } else {
                displayControls();
                std::cout << "コマンドを入力してください: ";
                std::cin >> input;
                std::cin.ignore();
                
                switch (input) {
                    case 'a':
                    case 'A':
                        autoMode = !autoMode;
                        std::cout << "自動モード: " << (autoMode ? "ON" : "OFF") << std::endl;
                        break;
                    case 's':
                    case 'S':
                        setSpeed();
                        break;
                    case 'r':
                    case 'R':
                        currentLine = 0;
                        std::cout << "最初から再開します。" << std::endl;
                        break;
                    case 'q':
                    case 'Q':
                        running = false;
                        break;
                    default:
                        currentLine++;
                        break;
                }
            }
        }
        
        if (currentLine >= lines.size()) {
            clearScreen();
            std::cout << "==========================================" << std::endl;
            std::cout << "           お疲れ様でした！" << std::endl;
            std::cout << "        ノベルの読み込みが完了しました" << std::endl;
            std::cout << "==========================================" << std::endl;
        }
    }
    
private:
    void setSpeed() {
        std::cout << "現在の速度: " << delayMs << "ms" << std::endl;
        std::cout << "新しい速度を入力してください (500-5000ms): ";
        int newDelay;
        std::cin >> newDelay;
        if (newDelay >= 500 && newDelay <= 5000) {
            delayMs = newDelay;
            std::cout << "速度を " << delayMs << "ms に設定しました。" << std::endl;
        } else {
            std::cout << "無効な値です。500-5000の範囲で入力してください。" << std::endl;
        }
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    std::string filename;
    std::cout << "ノベルファイルのパスを入力してください: ";
    std::getline(std::cin, filename);
    
    if (filename.empty()) {
        filename = "novel.txt";
        std::cout << "デフォルトファイル 'novel.txt' を使用します。" << std::endl;
    }
    
    NovelReader reader(filename);
    
    if (!reader.loadFile()) {
        std::cout << "プログラムを終了します。" << std::endl;
        return 1;
    }
    
    reader.startReading();
    
    return 0;
}
