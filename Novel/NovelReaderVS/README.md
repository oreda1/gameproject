# NovelReaderVS - DxLib版

DxLibを使用したグラフィカルな小説リーダーアプリケーションです。

## 新機能

### グラフィカルインターフェース
- 美しいタイトル画面
- 滑らかなシーン遷移
- 視覚的なプログレス表示

### エフェクト機能
- **フェードイン/アウト**: シーン遷移時の滑らかなフェード効果
- **タイプライター効果**: テキストが一文字ずつ表示される演出
- **背景エフェクト**: 背景画像やアニメーション対応

### シーン管理
- **タイトルシーン**: メニュー選択画面
- **ローディングシーン**: ファイル読み込み画面
- **小説読み込みシーン**: メインの小説表示画面
- **エンディングシーン**: 読み終了後の画面

### 操作方法
- **Enter/Space**: 次の行へ進む
- **A**: 自動読み込みモードの切り替え
- **R**: 最初から読み直す
- **Esc**: 一時停止/再開
- **矢印キー**: メニュー選択（タイトル画面）

## システム要件

- Windows 10/11
- Visual Studio 2022 (v143)
- DxLib SDK
- C++17以上

## セットアップ

### 1. DxLib SDKのインストール
1. [DxLib公式サイト](http://dxlib.o.oo7.jp/)からDxLib SDKをダウンロード
2. 適当な場所に解凍（例：`C:\DxLib`）
3. 環境変数`DXSDK_DIR`を設定

### 2. プロジェクトのビルド
1. Visual Studio 2022でソリューションを開く
2. プラットフォームをx64に設定
3. ビルド → ソリューションのビルド

## 使用方法

1. `novel.txt`ファイルに小説の内容を記述
2. アプリケーションを実行
3. タイトル画面で「小説を読む」を選択
4. 小説を楽しむ

## ファイル構造

```
NovelReaderVS/
├── main.cpp              # メインエントリーポイント
├── NovelEngine.h         # エンジンのヘッダーファイル
├── NovelEngine.cpp       # エンジンの実装
├── novel.txt            # 小説テキストファイル
└── README.md            # このファイル
```

## クラス構成

### メインクラス
- **NovelEngine**: メインエンジン、シーン管理
- **Scene**: シーンの基底クラス
- **TitleScene**: タイトル画面
- **LoadingScene**: ローディング画面
- **NovelReadingScene**: 小説読み込み画面
- **EndingScene**: エンディング画面

### ユーティリティクラス
- **TextRenderer**: テキスト表示とエフェクト管理
- **FadeManager**: フェードエフェクト管理
- **BackgroundManager**: 背景画像管理
- **SoundManager**: 音声管理
- **InputManager**: 入力管理
- **NovelData**: 小説データ管理

## カスタマイズ

### テキストエフェクトの変更
```cpp
textRenderer.setEffect(TextEffect::TYPEWRITER);
textRenderer.setTypewriterSpeed(3); // 速度調整
```

### フェードエフェクトの設定
```cpp
fadeManager.startFade(FadeType::FADE_IN, 5, 0x000000);
```

### 背景画像の設定
```cpp
backgroundManager.loadBackground("background.png");
```

## トラブルシューティング

### コンパイルエラー
- DxLib SDKが正しくインストールされているか確認
- 環境変数`DXSDK_DIR`が設定されているか確認
- プラットフォームがx64に設定されているか確認

### 実行時エラー
- `novel.txt`ファイルが存在するか確認
- ファイルの文字エンコーディングがUTF-8か確認

## 今後の拡張予定

- 背景音楽の再生
- セーブ/ロード機能
- 設定画面の実装
- より多くのテキストエフェクト
- 背景画像のアニメーション
- 音声効果音の追加