#include "XDMain.h"




int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	XDRenderer::Init();

	XDWindow::Create(hInstance, hPrevInstance, lpszCmdParam, nCmdShow);
	XDWindow::XDGetMessage();
	XDRenderer::Fin();

	return (int)XDWindow::Message.wParam;
	
	
}



