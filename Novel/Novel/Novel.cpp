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
            std::cerr << "Error: Could not open file '" << filename << "'" << std::endl;
            return false;
        }
        
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
        
        std::cout << "File loaded successfully. Lines: " << lines.size() << std::endl;
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
        std::cout << "           NOVEL READER" << std::endl;
        std::cout << "==========================================" << std::endl;
        std::cout << "File: " << filename << std::endl;
        std::cout << "Current line: " << (currentLine + 1) << " / " << lines.size() << std::endl;
        std::cout << "==========================================" << std::endl;
        std::cout << std::endl;
    }
    
    void displayControls() {
        std::cout << std::endl;
        std::cout << "==========================================" << std::endl;
        std::cout << "Controls:" << std::endl;
        std::cout << "  Enter: Next line" << std::endl;
        std::cout << "  'a' + Enter: Toggle auto mode" << std::endl;
        std::cout << "  's' + Enter: Set speed" << std::endl;
        std::cout << "  'r' + Enter: Restart from beginning" << std::endl;
        std::cout << "  'q' + Enter: Quit" << std::endl;
        std::cout << "==========================================" << std::endl;
    }
    
    void startReading() {
        if (lines.empty()) {
            std::cout << "No lines to read." << std::endl;
            return;
        }
        
        char input;
        bool running = true;
        
        while (running && currentLine < lines.size()) {
            clearScreen();
            displayHeader();
            
            std::cout << lines[currentLine] << std::endl;
            
            if (autoMode) {
                std::cout << std::endl << "[Auto mode - " << delayMs << "ms interval]" << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
                currentLine++;
            } else {
                displayControls();
                std::cout << "Enter command: ";
                std::cin >> input;
                std::cin.ignore();
                
                switch (input) {
                    case 'a':
                    case 'A':
                        autoMode = !autoMode;
                        std::cout << "Auto mode: " << (autoMode ? "ON" : "OFF") << std::endl;
                        break;
                    case 's':
                    case 'S':
                        setSpeed();
                        break;
                    case 'r':
                    case 'R':
                        currentLine = 0;
                        std::cout << "Restarting from the beginning." << std::endl;
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
            std::cout << "          Thank you for reading!" << std::endl;
            std::cout << "       Novel reading completed" << std::endl;
            std::cout << "==========================================" << std::endl;
        }
    }
    
private:
    void setSpeed() {
        std::cout << "Current speed: " << delayMs << "ms" << std::endl;
        std::cout << "Enter new speed (500-5000ms): ";
        int newDelay;
        std::cin >> newDelay;
        if (newDelay >= 500 && newDelay <= 5000) {
            delayMs = newDelay;
            std::cout << "Speed set to " << delayMs << "ms." << std::endl;
        } else {
            std::cout << "Invalid value. Please enter between 500-5000." << std::endl;
        }
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    std::string filename;
    std::cout << "Enter novel file path: ";
    std::getline(std::cin, filename);
    
    if (filename.empty()) {
        filename = "novel.txt";
        std::cout << "Using default file 'novel.txt'." << std::endl;
    }
    
    NovelReader reader(filename);
    
    if (!reader.loadFile()) {
        std::cout << "Program will exit." << std::endl;
        return 1;
    }
    
    reader.startReading();
    
    return 0;
}
