#pragma once

#include <windows.h>

class XDWindow
{
public:
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	static void Create(HINSTANCE hInstance, HINSTANCE hPrevInstance
		, LPSTR lpszCmdParam, int nCmdShow)
	{
		WndClass.cbClsExtra = 0;
		WndClass.cbWndExtra = 0;
		WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		WndClass.hInstance = hInstance;
		WndClass.lpfnWndProc = XDWindow::WndProc;
		WndClass.lpszClassName = XDWindow::lpszClass;
		WndClass.lpszMenuName = NULL;
		WndClass.style = CS_HREDRAW | CS_VREDRAW;
		RegisterClass(&WndClass);
		
		hWnd = CreateWindow(XDWindow::lpszClass, XDWindow::lpszClass, WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
			NULL, (HMENU)NULL, hInstance, NULL);
		ShowWindow(hWnd, nCmdShow);

	}

	static void XDGetMessage(){
		while (GetMessage(&Message, NULL, 0, 0)) {
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}
	}




public:
	static HINSTANCE g_hInst;
	static HWND hWndMain;
	static LPCTSTR lpszClass;

private:
	static WNDCLASS WndClass;
	static HWND hWnd;
public:
	static MSG Message;



};


