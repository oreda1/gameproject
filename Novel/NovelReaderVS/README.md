# Novel Reader - Visual Studio Project

This is a clean Visual Studio 2022 project for the Novel Reader application.

## How to Use

### Method 1: Open in Visual Studio
1. Double-click `NovelReaderVS.sln` to open in Visual Studio
2. Press `F5` to build and run the project
3. Or use Build → Build Solution (Ctrl+Shift+B) then run the executable

### Method 2: Build from Command Line
1. Open Developer Command Prompt for VS 2022
2. Navigate to this directory
3. Run: `msbuild NovelReaderVS.sln`

## Project Structure

- `NovelReaderVS.sln` - Visual Studio solution file
- `NovelReaderVS/` - Project directory
  - `main.cpp` - Main source code
  - `novel.txt` - Sample novel text file
  - `NovelReaderVS.vcxproj` - Project file
  - `NovelReaderVS.vcxproj.filters` - Solution explorer filters

## Features

- Console application
- UTF-8 text file support
- Line-by-line novel reading
- Auto mode with customizable speed
- Manual control options

## Build Configurations

- Debug|Win32 - Debug build for 32-bit
- Debug|x64 - Debug build for 64-bit
- Release|Win32 - Release build for 32-bit
- Release|x64 - Release build for 64-bit

## Requirements

- Visual Studio 2022 Community or higher
- Windows 10/11
- C++17 support

## Troubleshooting

### If project won't open:
- Make sure Visual Studio 2022 is installed
- Try opening the .vcxproj file directly

### If build fails:
- Check that you have the correct platform selected (x64 recommended)
- Make sure all files are present in the project directory

### If program crashes:
- Ensure novel.txt exists in the same directory as the executable
- Check that text files are in UTF-8 encoding
