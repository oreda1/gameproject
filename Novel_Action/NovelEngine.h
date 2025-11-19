#ifndef NOVEL_ENGINE_H
#define NOVEL_ENGINE_H

#include <DxLib.h>
#include <string>
#include <vector>
#include <memory>

// Scene type enumeration
enum class SceneType {
    TITLE,
    LOADING,
    NOVEL_READING,
    ENDING
};

// Text effect enumeration
enum class TextEffect {
    NONE,
    TYPEWRITER,
    FADE_IN,
    WAVE
};

// Fade effect enumeration
enum class FadeType {
    NONE,
    FADE_IN,
    FADE_OUT,
    FADE_IN_OUT
};

// Fade manager class
class FadeManager {
private:
    int fadeColor;
    int fadeAlpha;
    FadeType currentFade;
    int fadeSpeed;
    bool isFading;
    int screenWidth;
    int screenHeight;

public:
    FadeManager();
    void startFade(FadeType type, int speed = 10, int color = 0x000000);
    void update();
    void draw();
    bool isComplete() const;
    void setFadeColor(int color);
    void setScreenSize(int width, int height);
    int getFadeAlpha() const;
};

// Text renderer class
class TextRenderer {
private:
    int fontHandle;
    int textColor;
    int backgroundColor;
    int textSize;
    int lineSpacing;
    int maxCharactersPerLine;
    int maxLinesPerPage;
    std::string currentText;
    std::string displayedText;
    TextEffect currentEffect;
    int typewriterSpeed;
    int typewriterCounter;
    bool isTextComplete;
    
public:
    TextRenderer();
    ~TextRenderer();
    bool initialize();
    void setText(const std::string& text);
    void setEffect(TextEffect effect);
    void setTypewriterSpeed(int speed);
    void update();
    void draw(int x, int y);
    bool isTextFullyDisplayed() const;
    void skipToEnd();
    void clear();
};

// Background manager class
class BackgroundManager {
private:
    int backgroundHandle;
    int backgroundX, backgroundY;
    std::string currentBackground;
    
public:
    BackgroundManager();
    ~BackgroundManager();
    bool loadBackground(const std::string& filename);
    void setBackgroundPosition(int x, int y);
    void update();
    void draw();
    void clear();
};

// Sound manager class
class SoundManager {
private:
    int bgmHandle;
    int seHandle;
    bool isBgmPlaying;
    
public:
    SoundManager();
    ~SoundManager();
    bool loadBGM(const std::string& filename);
    bool loadSE(const std::string& filename);
    void playBGM(bool loop = true);
    void playSE();
    void stopBGM();
    void stopSE();
    void setBGMVolume(int volume);
    void setSEVolume(int volume);
};

// Input manager class
class InputManager {
private:
    bool keyStates[256];
    bool prevKeyStates[256];
    
public:
    InputManager();
    void update();
    bool isKeyPressed(int key);
    bool isKeyReleased(int key);
    bool isKeyDown(int key);
};

// Novel data class
class NovelData {
private:
    std::vector<std::string> lines;
    std::vector<std::string> chapters;
    std::string filename;
    int currentLine;
    int currentChapter;
    
public:
    NovelData();
    bool loadFile(const std::string& file);
    std::string getCurrentLine() const;
    std::string getCurrentChapter() const;
    bool nextLine();
    bool nextChapter();
    void restart();
    void restartChapter();
    bool isEnd() const;
    bool isChapterEnd() const;
    int getCurrentLineNumber() const;
    int getTotalLines() const;
    int getCurrentChapterNumber() const;
    int getTotalChapters() const;
};

// Forward declaration
class NovelEngine;

// Scene manager (abstract base class)
class Scene {
protected:
    NovelEngine* engine;
    
public:
    Scene(NovelEngine* engine) : engine(engine) {}
    virtual ~Scene() = default;
    virtual void initialize() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void finalize() = 0;
};

// Title scene
class TitleScene : public Scene {
private:
    int titleFontHandle;
    int menuFontHandle;
    int selectedMenuItem;
    std::vector<std::string> menuItems;
    FadeManager fadeManager;
    
public:
    TitleScene(NovelEngine* engine);
    void initialize() override;
    void update() override;
    void draw() override;
    void finalize() override;
};

// Loading scene
class LoadingScene : public Scene {
private:
    int loadingFontHandle;
    std::string loadingText;
    int loadingCounter;
    FadeManager fadeManager;
    
public:
    LoadingScene(NovelEngine* engine);
    void initialize() override;
    void update() override;
    void draw() override;
    void finalize() override;
};

// Novel reading scene
class NovelReadingScene : public Scene {
private:
    TextRenderer textRenderer;
    BackgroundManager backgroundManager;
    SoundManager soundManager;
    InputManager inputManager;
    NovelData novelData;
    FadeManager fadeManager;
    bool autoMode;
    int autoModeDelay;
    int autoModeCounter;
    bool isPaused;
    std::string currentChapterTitle;
    
public:
    NovelReadingScene(NovelEngine* engine);
    void initialize() override;
    void update() override;
    void draw() override;
    void finalize() override;
    
private:
    void handleInput();
    void drawUI();
    void drawChapterTitle();
};

// Ending scene
class EndingScene : public Scene {
private:
    int endingFontHandle;
    FadeManager fadeManager;
    std::string endingText;
    int endingCounter;
    
public:
    EndingScene(NovelEngine* engine);
    void initialize() override;
    void update() override;
    void draw() override;
    void finalize() override;
};

// Main engine class
class NovelEngine {
private:
    int screenWidth;
    int screenHeight;
    bool isRunning;
    SceneType currentSceneType;
    std::unique_ptr<Scene> currentScene;
    std::string novelFilename;
    FadeManager fadeManager;
    bool sceneChangePending;
    SceneType pendingSceneType;

    // Engine initialization
    bool initializeEngine();
    void finalizeEngine();

    // Scene management
    void changeScene(SceneType sceneType);
    void createScene(SceneType sceneType);
    void updateSceneTransition();

public:
    NovelEngine();
    ~NovelEngine();

    bool initialize(int width = 1024, int height = 768);
    void run();
    void shutdown();

    // Scene control
    void requestSceneChange(SceneType sceneType);

    // Getters
    int getScreenWidth() const { return screenWidth; }
    int getScreenHeight() const { return screenHeight; }
    const std::string& getNovelFilename() const { return novelFilename; }
    void setNovelFilename(const std::string& filename) { novelFilename = filename; }
};

#endif // NOVEL_ENGINE_H
