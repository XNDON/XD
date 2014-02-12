#include "XDWindow.h"
#include "XDRenderer.h"


LPCTSTR XDWindow::lpszClass = TEXT("GpDoubleBuffer");
HINSTANCE XDWindow::g_hInst;
HWND XDWindow::hWndMain;


WNDCLASS XDWindow::WndClass;
HWND XDWindow::hWnd;
MSG XDWindow::Message;

LRESULT CALLBACK XDWindow::WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage) {
	case WM_CREATE:
		XDWindow::hWndMain = hWnd;
		return 0;
	case WM_KEYDOWN:
		switch (wParam) {
		case VK_LEFT:
			XDRenderer::ex -= 5;
			XDRenderer::UpdateScreen();
			break;
		case VK_RIGHT:
			XDRenderer::ex += 5;
			XDRenderer::UpdateScreen();
			break;
		case VK_UP:
			XDRenderer::ey -= 5;
			XDRenderer::UpdateScreen();
			break;
		case VK_DOWN:
			XDRenderer::ey += 5;
			XDRenderer::UpdateScreen();
			break;
		}
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		XDRenderer::OnPaint(hdc);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		if (XDRenderer::pCBit) {
			delete XDRenderer::pCBit;
		}
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}