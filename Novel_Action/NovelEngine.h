#pragma once
#include <DxLib.h>
#include <string>
#include <vector>
#include <memory>


// シーン管理用の列挙型
enum class SceneType {
    TITLE,
    LOADING,
    NOVEL_READING,
    ENDING
};

// テキスト表示エフェクト用の列挙型
enum class TextEffect {
    NONE,
    TYPEWRITER,
    FADE_IN,
    WAVE
};

// フェードエフェクト用の列挙型
enum class FadeType {
    NONE,
    FADE_IN,
    FADE_OUT,
    FADE_IN_OUT
};

// フェード管理クラス
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
    int getFadeAlpha() const { return fadeAlpha; }
};

// テキストレンダリング管理クラス
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

// 背景管理クラス
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

// サウンド管理クラス
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

// 入力管理クラス
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

// 小説データ管理クラス
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

// 前方宣言
class NovelEngine;

// シーンマネージャー（抽象基底クラス）
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

// タイトルシーン
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

// ローディングシーン
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

// 小説読み込みシーン
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

// エンディングシーン
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

// メインエンジンクラス
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

    // エンジン初期化
    bool initializeEngine();
    void finalizeEngine();

    // シーン管理
    void changeScene(SceneType sceneType);
    void createScene(SceneType sceneType);
    void updateSceneTransition();

public:
    NovelEngine();
    ~NovelEngine();

    bool initialize(int width = 1024, int height = 768);
    void run();
    void shutdown();

    // シーン制御
    void requestSceneChange(SceneType sceneType);

    // ゲッター
    int getScreenWidth() const { return screenWidth; }
    int getScreenHeight() const { return screenHeight; }
    const std::string& getNovelFilename() const { return novelFilename; }
    void setNovelFilename(const std::string& filename) { novelFilename = filename; }
};
