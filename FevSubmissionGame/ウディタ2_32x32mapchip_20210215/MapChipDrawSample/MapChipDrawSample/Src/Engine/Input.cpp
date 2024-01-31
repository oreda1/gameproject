﻿#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <Windows.h>
#include <stdio.h>
#include <math.h>
//#include <D3dx9math.h>
#include <math.h>
#include "../Utility/Vec.h"
#include "Window.h"
#include "Input.h"

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

#define MOUSE_ON_VALUE (0x80)					//!< オン状態の値

static LPDIRECTINPUT8 g_InputInterface;			//!< DIRECTINPUT8のポインタ
static LPDIRECTINPUTDEVICE8 g_MouseDevice;		//!< DIRECTINPUTDEVICE8のポインタ
static DIMOUSESTATE g_CurrentMouseState;		//!< マウスの現在の入力情報
static DIMOUSESTATE g_PrevMouseState;			//!< マウスの現在の入力情報
static Vec2 g_MousePos;							//!< マウス座標

//!< 入力インターフェースの作成
bool CreateInputInterface();

//!< マウスデバイスの作成
bool CreateMouseDevice();

//!< マウスの更新
void UpdateMouse();

//!< 協調レベルの設定
BOOL SetUpCooperativeLevel(LPDIRECTINPUTDEVICE8 device);

//!< マウスの制御起動
BOOL StartMouseControl();

bool InitInput()
{
	// インターフェース作成
	if (CreateInputInterface() == false)
	{
		return false;
	}

	// デバイス作成
	if (CreateMouseDevice() == false)
	{
		ReleaseInput();
		return false;
	}

	// 入力情報の初期化
	ZeroMemory(&g_CurrentMouseState, sizeof(DIMOUSESTATE));
	ZeroMemory(&g_PrevMouseState, sizeof(DIMOUSESTATE));

	return true;
}

void ReleaseInput()
{
	// デバイスの解放
	if (g_MouseDevice != nullptr)
	{
		// 制御を停止
		g_MouseDevice->Unacquire();
		g_MouseDevice->Release();
		g_MouseDevice = nullptr;
	}

	// インターフェースの解放
	if (g_InputInterface != nullptr)
	{
		g_InputInterface->Release();
		g_InputInterface = nullptr;
	}
}

void UpdateInput()
{
	UpdateMouse();
}

Vec2 GetMousePos()
{
	return g_MousePos;
}

Vec2 GetMouseVelocity()
{
	return Vec2((float)g_CurrentMouseState.lX, (float)g_CurrentMouseState.lY);
}


bool OnMouseDown(MouseButton button_type)
{
	if (!(g_PrevMouseState.rgbButtons[button_type] & MOUSE_ON_VALUE) &&
		g_CurrentMouseState.rgbButtons[button_type] & MOUSE_ON_VALUE)
	{
		return true;
	}

	return false;
}

bool OnMousePush(MouseButton button_type)
{
	if (g_PrevMouseState.rgbButtons[button_type] & MOUSE_ON_VALUE &&
		g_CurrentMouseState.rgbButtons[button_type] & MOUSE_ON_VALUE)
	{
		return true;
	}

	return false;
}

bool OnMouseUp(MouseButton button_type)
{
	if (g_PrevMouseState.rgbButtons[button_type] & MOUSE_ON_VALUE &&
		!(g_CurrentMouseState.rgbButtons[button_type] & MOUSE_ON_VALUE))
	{
		return true;
	}

	return false;
}

bool CreateInputInterface()
{
	// インターフェース作成
	HRESULT ret = DirectInput8Create(
		GetModuleHandle(nullptr),	// インスタンスハンドル
		DIRECTINPUT_VERSION,		// DirectInputのバージョン
		IID_IDirectInput8,			// 使用する機能
		(void**)&g_InputInterface,	// 作成されたインターフェース代入用
		NULL						// NULL固定
	);

	if (FAILED(ret))
	{
		return false;
	}

	return true;
}

bool CreateMouseDevice()
{
	g_MouseDevice = nullptr;

	// デバイス生成
	HRESULT hr = g_InputInterface->CreateDevice(
		GUID_SysMouse,
		&g_MouseDevice,
		NULL);

	if (FAILED(hr))
	{
		return false;
	}

	// 入力フォーマットの指定
	hr = g_MouseDevice->SetDataFormat(&c_dfDIMouse);
	if (FAILED(hr))
	{
		return false;
	}

	// 協調レベルの設定
	if (SetUpCooperativeLevel(g_MouseDevice) == false)
	{
		return false;
	}

	int count = 0;
	// 制御開始
	while (StartMouseControl() == false)
	{
		Sleep(100);
		count++;
		if (count >= 5)
		{
			break;
		}
	}

	return true;
}

void UpdateMouse()
{
	if (g_MouseDevice == nullptr)
	{
		return;
	}

	// 更新前に最新マウス情報を保存する
	g_PrevMouseState = g_CurrentMouseState;

	// マウスの状態を取得します
	HRESULT	hr = g_MouseDevice->GetDeviceState(sizeof(DIMOUSESTATE), &g_CurrentMouseState);
	if (FAILED(hr))
	{
		g_MouseDevice->Acquire();
		hr = g_MouseDevice->GetDeviceState(sizeof(DIMOUSESTATE), &g_CurrentMouseState);
	}

	Vec2 prev = g_MousePos;
	POINT p;
	// マウス座標(スクリーン座標)を取得する
	GetCursorPos(&p);

	// スクリーン座標にクライアント座標に変換する
	ScreenToClient(FindWindowA(WINDOW_CLASS_NAME, nullptr), &p);

	// 変換した座標を保存
	g_MousePos.X = (float)p.x;
	g_MousePos.Y = (float)p.y;
}

BOOL SetUpCooperativeLevel(LPDIRECTINPUTDEVICE8 device)
{
	// 協調モードの設定
	if (FAILED(device->SetCooperativeLevel(
		FindWindow(WINDOW_CLASS_NAME, nullptr),
		DISCL_NONEXCLUSIVE | DISCL_FOREGROUND)
	))
	{
		return false;
	}

	return true;
}

BOOL StartMouseControl()
{
	// デバイスが生成されてない
	if (g_MouseDevice == nullptr)
	{
		return false;
	}
	// 制御開始
	if (FAILED(g_MouseDevice->Acquire()))
	{
		return false;
	}

	DIDEVCAPS cap;
	g_MouseDevice->GetCapabilities(&cap);
	// ポーリング判定
	if (cap.dwFlags & DIDC_POLLEDDATAFORMAT)
	{
		DWORD error = GetLastError();
		// ポーリング開始
		/*
			PollはAcquireの前に行うとされていたが、
			Acquireの前で実行すると失敗したので
			後で実行するようにした
		*/
		if (FAILED(g_MouseDevice->Poll()))
		{
			return false;
		}
	}

	return true;
}
