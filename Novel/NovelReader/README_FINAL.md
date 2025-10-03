# Novel Reader - Complete Package

A complete C++ novel reading application with both English and Japanese versions.

## Quick Start

1. **Double-click `launch.bat`** to start the program
2. Choose between English or Japanese version
3. Enter the path to your novel text file (or press Enter for default `novel.txt`)

## Files Included

### Executables
- `novel_reader_eng.exe` - English version
- `novel_reader_jp.exe` - Japanese version
- `launch.bat` - Easy launcher script

### Source Code
- `novel_reader_eng.cpp` - English source code
- `novel_reader_jp.cpp` - Japanese source code

### Sample Content
- `novel.txt` - Sample Japanese novel text

### Build Scripts
- `compile_eng.bat` - Compile English version
- `compile_jp.bat` - Compile Japanese version
- `build.bat` - Generic build script
- `run.bat` - Generic run script

### Documentation
- `README.md` - Original documentation
- `README_FINAL.md` - This file
- `Makefile` - Make build configuration

## Features

- **File Reading**: Load external text files
- **Novel Display**: Line-by-line display for novel-like reading experience
- **Auto Mode**: Automatic progression with customizable speed
- **Manual Control**: Step-by-step reading with full control
- **Speed Adjustment**: Adjust reading speed from 500-5000ms
- **Progress Display**: Shows current line and total lines
- **UTF-8 Support**: Full Japanese character support

## Controls

- **Enter**: Next line
- **'a' + Enter**: Toggle auto mode ON/OFF
- **'s' + Enter**: Set reading speed
- **'r' + Enter**: Restart from beginning
- **'q' + Enter**: Quit program

## Requirements

- Windows 10/11
- Visual Studio 2022 (for compilation)
- Text files in UTF-8 encoding (for Japanese content)

## How to Use

1. **Using the Launcher** (Recommended):
   - Double-click `launch.bat`
   - Select version (English/Japanese)
   - Enter file path or use default `novel.txt`

2. **Direct Execution**:
   - Double-click `novel_reader_eng.exe` for English version
   - Double-click `novel_reader_jp.exe` for Japanese version

3. **Custom Text Files**:
   - Create your own text file in UTF-8 encoding
   - Run the program and enter the file path
   - Or rename your file to `novel.txt` for default usage

## Sample Novel

The included `novel.txt` contains a sample Japanese novel about a magical adventure. You can replace it with your own content.

## Technical Details

- Compiled with Visual Studio 2022 C++ compiler
- Uses Windows API for console management
- UTF-8 encoding support for international characters
- Multi-threading for auto mode timing
- Cross-platform C++ standard library usage

## Troubleshooting

### If programs don't start:
- Make sure you're running on Windows 10/11
- Try running from Command Prompt if double-click doesn't work

### If text appears garbled:
- Ensure your text files are saved in UTF-8 encoding
- Japanese content requires UTF-8 encoding

### If compilation fails:
- Install Visual Studio 2022 Community Edition
- Run build scripts from Command Prompt with admin privileges

## License

This program is free to use, modify, and distribute.

---

**Enjoy reading your novels!**
