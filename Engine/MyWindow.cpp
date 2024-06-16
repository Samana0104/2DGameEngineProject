#include "pch.h"
#include "MyWindow.h"
using namespace MyProject;

void MyWindow::CreateRegisterClass(HINSTANCE _hInstance) 
{
	WNDCLASS wc = {};
	wc.lpfnWndProc = [](HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM	lParam) -> LRESULT
	{
		switch (uMsg)
		{
		case WM_ACTIVATE:
			MyWindow::CallEventWMActivate(hwnd, uMsg, wParam, lParam);
			return 0;

		case WM_DESTROY:
			MyWindow::CallEventWMDestroy(hwnd, uMsg, wParam, lParam);
			return 0;

		case WM_SIZE:
			MyWindow::CallEventWMSize(hwnd, uMsg, wParam, lParam);
			return 0;
		}
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	};

	wc.hInstance = _hInstance;
	wc.lpszClassName = MY_WINDOW_CLASS_NAME;
	RegisterClass(&wc);
}

bool MyWindow::CreateWin(LONG _width, LONG _height) 
{
	mWindowSize = { _width, _height };
	RECT rt{ 0, 0, _width, _height };

	CreateRegisterClass(mHinstance);
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, FALSE);

	HWND hwnd = CreateWindowEx(
		0, // Optional window styles.
		MY_WINDOW_CLASS_NAME,
		MY_WINDOW_NAME,
		WS_OVERLAPPEDWINDOW,// Window style
		GetSystemMetrics(SM_CXSCREEN) / 2 - (rt.right-rt.left) / 2, // ���� �߾ӿ� ������ ����
		(GetSystemMetrics(SM_CYSCREEN)-45) / 2 - (rt.bottom-rt.top) / 2, // �ϴ� ���� 45px
		rt.right-rt.left, 
		rt.bottom-rt.top,
		NULL, // Parent window
		NULL, // Menu
		mHinstance, // Instance handle
		NULL // Additional application data
	);

	if (hwnd == NULL)
		return false;

	GetWindowRect(hwnd, &mWindowRect);
	GetClientRect(hwnd, &mClientWindowRect);

	mHwnd = hwnd;
	ShowWindow(hwnd, SW_SHOW);
	return true;
}


bool MyWindow::WindowRun() const
{
	MSG msg = { };
	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			return true;
		}
	}
	return false;
}

void MyWindow::CallEventWMActivate(HWND _hwnd, UINT _uMsg, WPARAM _wParam, LPARAM _lParam)
{
	if (LOWORD(_wParam) == WA_INACTIVE)
		MyWindow::mIsActivate = false;
	else
		MyWindow::mIsActivate = true;
}

void MyWindow::CallEventWMDestroy(HWND _hwnd, UINT _uMsg, WPARAM _wParam, LPARAM _lParam)
{
	PostQuitMessage(0);
}

void MyWindow::CallEventWMSize(HWND _hwnd, UINT _uMsg, WPARAM _wParam, LPARAM _lParam)
{
	//MyWindow::mWindowSize.x = LOWORD(lParam);
	//MyWindow::mWindowSize.y = HIWORD(wParam);
}

bool MyWindow::IsActivate() const
{
	return mIsActivate;
}

void MyWindow::SetHinstance(HINSTANCE _hinstance) 
{
	mHinstance = _hinstance;
}

POINT MyWindow::GetWindowSize() const
{
	return mWindowSize;
}

POINTFLOAT MyWindow::GetWindowSizeF() const
{
	return { static_cast<FLOAT>(mWindowSize.x), static_cast<FLOAT>(mWindowSize.y) };
}

glm::vec2 MyWindow::GetWindowSizeVec2() const
{
	return { static_cast<FLOAT>(mWindowSize.x), static_cast<FLOAT>(mWindowSize.y) };
}

HWND MyWindow::GetWindowHandle() const
{
	return mHwnd;
}
