#include "NovelEngine.h"
#include <iostream>
#include <fstream>
#include <algorithm>



// ========== FadeManager Implementation ==========
FadeManager::FadeManager() : fadeColor(0x000000), fadeAlpha(0), currentFade(FadeType::NONE), 
                             fadeSpeed(10), isFading(false), screenWidth(1024), screenHeight(768) {}

void FadeManager::startFade(FadeType type, int speed, int color) {
    currentFade = type;
    fadeSpeed = speed;
    fadeColor = color;
    isFading = true;
    
    switch (type) {
        case FadeType::FADE_IN:
            fadeAlpha = 255;
            break;
        case FadeType::FADE_OUT:
            fadeAlpha = 0;
            break;
        case FadeType::FADE_IN_OUT:
            fadeAlpha = 255;
            break;
        default:
            isFading = false;
            break;
    }
}

void FadeManager::update() {
    if (!isFading) return;
    
    switch (currentFade) {
        case FadeType::FADE_IN:
            fadeAlpha -= fadeSpeed;
            if (fadeAlpha <= 0) {
                fadeAlpha = 0;
                isFading = false;
            }
            break;
            
        case FadeType::FADE_OUT:
            fadeAlpha += fadeSpeed;
            if (fadeAlpha >= 255) {
                fadeAlpha = 255;
                isFading = false;
            }
            break;
            
        case FadeType::FADE_IN_OUT:
            // FADE_IN_OUTの場合は手動で制御する必要があります
            break;
    }
}

void FadeManager::draw() {
    if (fadeAlpha > 0) {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, fadeAlpha);
        DrawBox(0, 0, screenWidth, screenHeight, fadeColor, TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
}

bool FadeManager::isComplete() const {
    return !isFading;
}

void FadeManager::setFadeColor(int color) {
    fadeColor = color;
}

void FadeManager::setScreenSize(int width, int height) {
    screenWidth = width;
    screenHeight = height;
}

int FadeManager::getFadeAlpha() const {
    return fadeAlpha;
}

// ========== TextRenderer Implementation ==========
TextRenderer::TextRenderer() : fontHandle(-1), textColor(0xFFFFFF), backgroundColor(0x000000),
                               textSize(20), lineSpacing(5), maxCharactersPerLine(50),
                               maxLinesPerPage(10), typewriterSpeed(2), typewriterCounter(0),
                               isTextComplete(false) {}

TextRenderer::~TextRenderer() {
    if (fontHandle != -1) {
        DeleteFontToHandle(fontHandle);
    }
}

bool TextRenderer::initialize() {
    fontHandle = CreateFontToHandle("ＭＳ ゴシック", textSize, 3, DX_FONTTYPE_ANTIALIASING_4X4);
    return fontHandle != -1;
}

void TextRenderer::setText(const std::string& text) {
    currentText = text;
    displayedText = "";
    typewriterCounter = 0;
    isTextComplete = false;
    
    if (currentEffect == TextEffect::NONE || currentEffect == TextEffect::FADE_IN) {
        displayedText = currentText;
        isTextComplete = true;
    }
}

void TextRenderer::setEffect(TextEffect effect) {
    currentEffect = effect;
    if (effect == TextEffect::TYPEWRITER) {
        displayedText = "";
        typewriterCounter = 0;
        isTextComplete = false;
    }
}

void TextRenderer::setTypewriterSpeed(int speed) {
    typewriterSpeed = speed;
}

void TextRenderer::update() {
    if (isTextComplete) return;
    
    switch (currentEffect) {
        case TextEffect::TYPEWRITER:
            typewriterCounter++;
            if (typewriterCounter >= typewriterSpeed) {
                typewriterCounter = 0;
                if (displayedText.length() < currentText.length()) {
                    displayedText += currentText[displayedText.length()];
                } else {
                    isTextComplete = true;
                }
            }
            break;
            
        case TextEffect::FADE_IN:
        case TextEffect::WAVE:
            // これらのエフェクトは別途実装が必要
            isTextComplete = true;
            break;
    }
}

void TextRenderer::draw(int x, int y) {
    if (fontHandle == -1 || displayedText.empty()) return;
    
    // 複数行テキストの描画
    std::vector<std::string> lines;
    std::string currentLine = "";
    
    for (char c : displayedText) {
        if (c == '\n' || currentLine.length() >= maxCharactersPerLine) {
            lines.push_back(currentLine);
            currentLine = "";
            if (c != '\n') currentLine += c;
        } else {
            currentLine += c;
        }
    }
    if (!currentLine.empty()) {
        lines.push_back(currentLine);
    }
    
    // 最大行数制限
    int startLine = 0;
    if (lines.size() > maxLinesPerPage) {
        startLine = lines.size() - maxLinesPerPage;
    }
    
    for (int i = startLine; i < lines.size() && i - startLine < maxLinesPerPage; i++) {
        DrawStringToHandle(x, y + (i - startLine) * (textSize + lineSpacing), 
                          lines[i].c_str(), textColor, fontHandle, 0x000000);
    }
}

bool TextRenderer::isTextFullyDisplayed() const {
    return isTextComplete;
}

void TextRenderer::skipToEnd() {
    displayedText = currentText;
    isTextComplete = true;
}

void TextRenderer::clear() {
    currentText = "";
    displayedText = "";
    isTextComplete = false;
    typewriterCounter = 0;
}

// ========== BackgroundManager Implementation ==========
BackgroundManager::BackgroundManager() : backgroundHandle(-1), backgroundX(0), backgroundY(0) {}

BackgroundManager::~BackgroundManager() {
    if (backgroundHandle != -1) {
        DeleteGraph(backgroundHandle);
    }
}

bool BackgroundManager::loadBackground(const std::string& filename) {
    if (backgroundHandle != -1) {
        DeleteGraph(backgroundHandle);
    }
    
    backgroundHandle = LoadGraph(filename.c_str());
    currentBackground = filename;
    return backgroundHandle != -1;
}

void BackgroundManager::setBackgroundPosition(int x, int y) {
    backgroundX = x;
    backgroundY = y;
}

void BackgroundManager::update() {
    // 背景アニメーション処理があればここに実装
}

void BackgroundManager::draw() {
    if (backgroundHandle != -1) {
        DrawGraph(backgroundX, backgroundY, backgroundHandle, TRUE);
    }
}

void BackgroundManager::clear() {
    if (backgroundHandle != -1) {
        DeleteGraph(backgroundHandle);
        backgroundHandle = -1;
    }
    currentBackground = "";
}

// ========== SoundManager Implementation ==========
SoundManager::SoundManager() : bgmHandle(-1), seHandle(-1), isBgmPlaying(false) {}

SoundManager::~SoundManager() {
    if (bgmHandle != -1) {
        DeleteMusicMem(bgmHandle);
    }
    if (seHandle != -1) {
        DeleteSoundMem(seHandle);
    }
}

bool SoundManager::loadBGM(const std::string& filename) {
    if (bgmHandle != -1) {
        DeleteMusicMem(bgmHandle);
    }
    
    bgmHandle = LoadMusicMem(filename.c_str());
    return bgmHandle != -1;
}

bool SoundManager::loadSE(const std::string& filename) {
    if (seHandle != -1) {
        DeleteSoundMem(seHandle);
    }
    
    seHandle = LoadSoundMem(filename.c_str());
    return seHandle != -1;
}

void SoundManager::playBGM(bool loop) {
    if (bgmHandle != -1 && !isBgmPlaying) {
        PlayMusicMem(bgmHandle, DX_PLAYTYPE_LOOP);
        isBgmPlaying = true;
    }
}

void SoundManager::playSE() {
    if (seHandle != -1) {
        PlaySoundMem(seHandle, DX_PLAYTYPE_NORMAL);
    }
}

void SoundManager::stopBGM() {
    if (bgmHandle != -1 && isBgmPlaying) {
        StopMusicMem(bgmHandle);
        isBgmPlaying = false;
    }
}

void SoundManager::stopSE() {
    if (seHandle != -1) {
        StopSoundMem(seHandle);
    }
}

// BGMの音量を設定
void SoundManager::setBGMVolume(int volume) {
    if (bgmHandle != -1) {
        ChangeVolumeSoundMem(bgmHandle, volume);
    }
}

// 効果音の音量を設定
void SoundManager::setSEVolume(int volume) {
    if (seHandle != -1) {
        ChangeVolumeSoundMem(seHandle, volume);
    }
}




// ========== InputManager Implementation ==========
InputManager::InputManager() {
    for (int i = 0; i < 256; i++) {
        keyStates[i] = false;
        prevKeyStates[i] = false;
    }
}

void InputManager::update() {
    for (int i = 0; i < 256; i++) {
        prevKeyStates[i] = keyStates[i];
        keyStates[i] = (CheckHitKey(i) == 1);
    }
}

bool InputManager::isKeyPressed(int key) {
    return keyStates[key] && !prevKeyStates[key];
}

bool InputManager::isKeyReleased(int key) {
    return !keyStates[key] && prevKeyStates[key];
}

bool InputManager::isKeyDown(int key) {
    return keyStates[key];
}

// ========== NovelData Implementation ==========
NovelData::NovelData() : currentLine(0), currentChapter(0) {}

bool NovelData::loadFile(const std::string& file) {
    filename = file;
    lines.clear();
    chapters.clear();
    
    std::ifstream fileStream(filename);
    if (!fileStream.is_open()) {
        return false;
    }
    
    std::string line;
    while (std::getline(fileStream, line)) {
        lines.push_back(line);

        // 章タイトルの検出（例：第一章、第二章など）
        if (line.find("第") != std::string::npos && line.find("章") != std::string::npos)
        {
            chapters.push_back(line);
        }
    }
    
    fileStream.close();
    return true;
}

std::string NovelData::getCurrentLine() const {
    if (currentLine < lines.size()) {
        return lines[currentLine];
    }
    return "";
}

std::string NovelData::getCurrentChapter() const {
    if (currentChapter < chapters.size()) {
        return chapters[currentChapter];
    }
    return "";
}

bool NovelData::nextLine() {
    currentLine++;
    return currentLine < lines.size();
}

bool NovelData::nextChapter() {
    currentChapter++;
    return currentChapter < chapters.size();
}

void NovelData::restart() {
    currentLine = 0;
    currentChapter = 0;
}

void NovelData::restartChapter() {
    // 現在の章の最初の行を見つける
    // 実装は簡略化
    currentLine = 0;
}

bool NovelData::isEnd() const {
    return currentLine >= lines.size();
}

bool NovelData::isChapterEnd() const {
    // 簡略化された実装
    return currentLine >= lines.size();
}

int NovelData::getCurrentLineNumber() const {
    return currentLine + 1;
}

int NovelData::getTotalLines() const {
    return lines.size();
}

int NovelData::getCurrentChapterNumber() const {
    return currentChapter + 1;
}

int NovelData::getTotalChapters() const {
    return chapters.size();
}

// ========== TitleScene Implementation ==========
TitleScene::TitleScene(NovelEngine* engine) : Scene(engine), selectedMenuItem(0) {
    menuItems = {"小説を読む", "設定", "終了"};
}

void TitleScene::initialize() {
    titleFontHandle = CreateFontToHandle("ＭＳ ゴシック", 48, 3, DX_FONTTYPE_ANTIALIASING_4X4);
    menuFontHandle = CreateFontToHandle("ＭＳ ゴシック", 24, 3, DX_FONTTYPE_ANTIALIASING_4X4);
    fadeManager.startFade(FadeType::FADE_IN, 5);
}

void TitleScene::update() {
    fadeManager.update();
    
    InputManager input;
    input.update();
    
    if (input.isKeyPressed(KEY_INPUT_UP)) {
        selectedMenuItem = (selectedMenuItem - 1 + menuItems.size()) % menuItems.size();
    }
    if (input.isKeyPressed(KEY_INPUT_DOWN)) {
        selectedMenuItem = (selectedMenuItem + 1) % menuItems.size();
    }
    if (input.isKeyPressed(KEY_INPUT_RETURN)) {
        switch (selectedMenuItem) {
            case 0: // 小説を読む
                engine->requestSceneChange(SceneType::LOADING);
                break;
            case 1: // 設定
                // 設定画面の実装
                break;
            case 2: // 終了
                engine->shutdown();
                break;
        }
    }
}

void TitleScene::draw() {
    // 背景
    DrawBox(0, 0, 1024, 768, 0x000040, TRUE);
    
    // タイトル
    DrawStringToHandle(1024/2 - 200, 150, "Novel Reader", 0xFFFFFF, titleFontHandle, 0x000000);
    
    // メニュー
    for (int i = 0; i < menuItems.size(); i++) {
        int color = (i == selectedMenuItem) ? 0xFFFF00 : 0xFFFFFF;
        DrawStringToHandle(1024/2 - 100, 300 + i * 50, menuItems[i].c_str(), 
                          color, menuFontHandle, 0x000000);
    }
    
    fadeManager.draw();
}

void TitleScene::finalize() {
    if (titleFontHandle != -1) DeleteFontToHandle(titleFontHandle);
    if (menuFontHandle != -1) DeleteFontToHandle(menuFontHandle);
}

// ========== LoadingScene Implementation ==========
LoadingScene::LoadingScene(NovelEngine* engine) : Scene(engine), loadingCounter(0) {
    loadingText = "読み込み中";
}

void LoadingScene::initialize() {
    loadingFontHandle = CreateFontToHandle("ＭＳ ゴシック", 32, 3, DX_FONTTYPE_ANTIALIASING_4X4);
    fadeManager.startFade(FadeType::FADE_IN, 5);
}

void LoadingScene::update() {
    fadeManager.update();
    loadingCounter++;
    
    if (loadingCounter > 120) { // 2秒後に小説読み込み画面へ
        engine->requestSceneChange(SceneType::NOVEL_READING);
    }
}

void LoadingScene::draw() {
    DrawBox(0, 0, 1024, 768, 0x000020, TRUE);
    
    std::string displayText = loadingText;
    for (int i = 0; i < (loadingCounter / 20) % 4; i++) {
        displayText += ".";
    }
    
    DrawStringToHandle(1024/2 - 150, 768/2 - 50, displayText.c_str(), 
                     0xFFFFFF, loadingFontHandle, 0x000000);
    
    fadeManager.draw();
}

void LoadingScene::finalize() {
    if (loadingFontHandle != -1) DeleteFontToHandle(loadingFontHandle);
}

// ========== NovelReadingScene Implementation ==========
NovelReadingScene::NovelReadingScene(NovelEngine* engine) : Scene(engine), 
    autoMode(false), autoModeDelay(120), autoModeCounter(0), isPaused(false) {}

void NovelReadingScene::initialize() {
    textRenderer.initialize();
    textRenderer.setEffect(TextEffect::TYPEWRITER);
    textRenderer.setTypewriterSpeed(3);
    
    novelData.loadFile(engine->getNovelFilename());
    textRenderer.setText(novelData.getCurrentLine());
    currentChapterTitle = novelData.getCurrentChapter();
    
    fadeManager.startFade(FadeType::FADE_IN, 5);
}

void NovelReadingScene::update() {
    inputManager.update();
    textRenderer.update();
    fadeManager.update();
    
    if (!isPaused) {
        handleInput();
        
        if (autoMode) {
            autoModeCounter++;
            if (autoModeCounter >= autoModeDelay && textRenderer.isTextFullyDisplayed()) {
                if (novelData.nextLine()) {
                    textRenderer.setText(novelData.getCurrentLine());
                } else {
                    engine->requestSceneChange(SceneType::ENDING);
                }
                autoModeCounter = 0;
            }
        }
    }
}

void NovelReadingScene::draw() {
    // 背景
    DrawBox(0, 0, 1024, 768, 0x000000, TRUE);
    
    // 章タイトル
    drawChapterTitle();
    
    // テキスト
    textRenderer.draw(50, 150);
    
    // UI
    drawUI();
    
    fadeManager.draw();
}

void NovelReadingScene::finalize() {
    soundManager.stopBGM();
    soundManager.stopSE();
}

void NovelReadingScene::handleInput() {
    if (inputManager.isKeyPressed(KEY_INPUT_RETURN) || 
        inputManager.isKeyPressed(KEY_INPUT_SPACE)) {
        if (!textRenderer.isTextFullyDisplayed()) {
            textRenderer.skipToEnd();
        } else {
            if (novelData.nextLine()) {
                textRenderer.setText(novelData.getCurrentLine());
            } else {
                engine->requestSceneChange(SceneType::ENDING);
            }
        }
    }
    
    if (inputManager.isKeyPressed(KEY_INPUT_A)) {
        autoMode = !autoMode;
    }
    
    if (inputManager.isKeyPressed(KEY_INPUT_R)) {
        novelData.restart();
        textRenderer.setText(novelData.getCurrentLine());
        currentChapterTitle = novelData.getCurrentChapter();
    }
    
    if (inputManager.isKeyPressed(KEY_INPUT_ESCAPE)) {
        isPaused = !isPaused;
    }
}

void NovelReadingScene::drawUI() {
    // プログレスバー
    int progressWidth = 300;
    int progressHeight = 10;
    int progressX = 1024 - progressWidth - 20;
    int progressY = 768 - progressHeight - 20;
    
    // 背景
    DrawBox(progressX, progressY, progressX + progressWidth, progressY + progressHeight, 
           0x404040, TRUE);
    
    // プログレス
    int currentProgress = (int)((float)novelData.getCurrentLineNumber() / 
                               novelData.getTotalLines() * progressWidth);
    DrawBox(progressX, progressY, progressX + currentProgress, progressY + progressHeight, 
           0x00FF00, TRUE);
    
    // 情報表示
    std::string info = "行: " + std::to_string(novelData.getCurrentLineNumber()) + 
                      "/" + std::to_string(novelData.getTotalLines());
    DrawFormatString(progressX, progressY - 20, 0xFFFFFF, "%s", info.c_str());
    
    if (autoMode) {
        DrawFormatString(50, 768 - 50, 0xFFFF00, "自動読み込みモード");
    }

    if (isPaused) {
        int screenHeight = engine->getScreenHeight();
        DrawFormatString(50, screenHeight - 80, 0xFF0000, "一時停止中");
    }

}

void NovelReadingScene::drawChapterTitle() {
    if (!currentChapterTitle.empty()) {
        DrawFormatString(50, 50, 0xFFFF00, currentChapterTitle.c_str());
    }
}

// ========== EndingScene Implementation ==========
EndingScene::EndingScene(NovelEngine* engine) : Scene(engine), endingCounter(0) {
    endingText = "お疲れ様でした！";
}

void EndingScene::initialize() {
    endingFontHandle = CreateFontToHandle("ＭＳ ゴシック", 32, 3, DX_FONTTYPE_ANTIALIASING_4X4);
    fadeManager.setScreenSize(engine->getScreenWidth(), engine->getScreenHeight());
    fadeManager.startFade(FadeType::FADE_IN, 5);
}

void EndingScene::update() {
    fadeManager.update();
    endingCounter++;
    
    InputManager input;
    input.update();
    
    if (input.isKeyPressed(KEY_INPUT_RETURN) || input.isKeyPressed(KEY_INPUT_ESCAPE)) {
        engine->requestSceneChange(SceneType::TITLE);
    }
}

void EndingScene::draw() {
    int screenWidth = engine->getScreenWidth();
    int screenHeight = engine->getScreenHeight();
    
    DrawBox(0, 0, screenWidth, screenHeight, 0x400040, TRUE);
    
    DrawStringToHandle(screenWidth/2 - 200, screenHeight/2 - 50, endingText.c_str(), 
                     0xFFFFFF, endingFontHandle, 0x000000);
    
    DrawFormatString(screenWidth/2 - 150, screenHeight/2 + 50, 0xFFFFFF, "Enter または Esc でタイトルに戻る");
    
   
	fadeManager.draw();
}

void EndingScene::finalize() {
    if (endingFontHandle != -1) DeleteFontToHandle(endingFontHandle);
}

// ========== NovelEngine Implementation ==========
NovelEngine::NovelEngine() : screenWidth(1024), screenHeight(768), isRunning(false),
                             currentSceneType(SceneType::TITLE), sceneChangePending(false),
                             pendingSceneType(SceneType::TITLE) {}

NovelEngine::~NovelEngine() {
    finalizeEngine();
}

bool NovelEngine::initialize(int width, int height) {
    screenWidth = width;
    screenHeight = height;
    
    if (!initializeEngine()) {
        return false;
    }
    
    changeScene(SceneType::TITLE);
    return true;
}

bool NovelEngine::initializeEngine() {
    // ウィンドウモードに設定
    ChangeWindowMode(TRUE);
    
    // グラフィックモードを設定
    SetGraphMode(screenWidth, screenHeight, 32);
    
    // DxLibの初期化
    if (DxLib_Init() == -1) {
        return false;
    }
    
    // 描画先を裏画面に設定
    SetDrawScreen(DX_SCREEN_BACK);
    
    // 文字コード形式を設定
    SetUseCharCodeFormat(DX_CHARCODEFORMAT_UTF8);
    
    // フレームレート制御（60FPS）
    SetWaitVSyncFlag(TRUE);
    
    // FadeManagerに画面サイズを設定
    fadeManager.setScreenSize(screenWidth, screenHeight);
    
    return true;
}

void NovelEngine::finalizeEngine() {
    if (currentScene) {
        currentScene->finalize();
        currentScene.reset();
    }
    DxLib_End();
}

void NovelEngine::run() {
    isRunning = true;
    
    while (ProcessMessage() == 0 && isRunning) {
        // 画面をクリア
        ClearDrawScreen();
        
        // フェードの更新
        fadeManager.update();
        
        // シーン遷移の処理
        updateSceneTransition();
        
        // シーンの更新と描画
        if (currentScene) {
            currentScene->update();
            currentScene->draw();
        }
        
        // フェードの描画（最前面）
        fadeManager.draw();
        
        // 画面をフリップ
        ScreenFlip();
    }
}

void NovelEngine::shutdown() {
    isRunning = false;
}

void NovelEngine::requestSceneChange(SceneType sceneType) {
    if (!sceneChangePending) {
        sceneChangePending = true;
        pendingSceneType = sceneType;
        // フェードアウトを開始
        fadeManager.startFade(FadeType::FADE_OUT, 10);
    }
}

void NovelEngine::updateSceneTransition() {
    if (sceneChangePending) {
        // フェードアウトが完了したかチェック
        if (fadeManager.isComplete() && fadeManager.getFadeAlpha() >= 255) {
            // シーンを変更
            changeScene(pendingSceneType);
            // フェードインを開始
            fadeManager.startFade(FadeType::FADE_IN, 10);
            sceneChangePending = false;
        }
    }
}

void NovelEngine::changeScene(SceneType sceneType) {
    if (currentScene) {
        currentScene->finalize();
    }
    
    createScene(sceneType);
    currentSceneType = sceneType;
    
    if (currentScene) {
        currentScene->initialize();
    }
}

void NovelEngine::createScene(SceneType sceneType) {
    switch (sceneType) {
        case SceneType::TITLE:
            currentScene = std::make_unique<TitleScene>(this);
            break;
        case SceneType::LOADING:
            currentScene = std::make_unique<LoadingScene>(this);
            break;
        case SceneType::NOVEL_READING:
            currentScene = std::make_unique<NovelReadingScene>(this);
            break;
        case SceneType::ENDING:
            currentScene = std::make_unique<EndingScene>(this);
            break;
    }
}
