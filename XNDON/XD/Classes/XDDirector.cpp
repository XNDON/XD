#include "XDDirector.h"

XDScene* XDDirector::m_pScene = nullptr;

void CALLBACK XDDirector::Update(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	XDRenderer::UpdateScreen();
	/*
	HDC hdc;
	int i;
	hdc = GetDC(hWnd);
	for (i = 0; i<100; i++)
		SetPixel(hdc, rand() % 500, rand() % 400,
		RGB(rand() % 256, rand() % 256, rand() % 256, ));
	ReleaseDC(hWnd, hdc);
	*/
}