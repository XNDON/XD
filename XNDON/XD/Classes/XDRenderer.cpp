#include "XDRenderer.h"


int XDRenderer::ex = 0;
int XDRenderer::ey = 0;
Gdiplus::CachedBitmap* XDRenderer::pCBit = nullptr;
ULONG_PTR XDRenderer::m_gpToken;

void XDRenderer::UpdateScreen()
{
	Gdiplus::Graphics G(XDWindow::hWndMain);
	RECT crt;
	GetClientRect(XDWindow::hWndMain, &crt);
	Gdiplus::Bitmap *pBit = new Gdiplus::Bitmap(crt.right, crt.bottom, &G);
	Gdiplus::Graphics *memG = new Gdiplus::Graphics(pBit);
	memG->FillRectangle(&Gdiplus::SolidBrush(Gdiplus::Color(255, 255, 255)), 0, 0, crt.right, crt.bottom);

	Gdiplus::SolidBrush S(Gdiplus::Color(0, 0, 255));
	int x, y;

	for (x = 0; x <= 800; x += 50) {
		for (y = 0; y <= 600; y += 50) {
			memG->FillRectangle(&S, x, y, 40, 40);
		}
	}

	Gdiplus::SolidBrush S2(Gdiplus::Color(128, 255, 0, 0));
	memG->FillEllipse(&S2, ex, ey, 150, 150);
	if (pCBit) {
		delete pCBit;
	}
	pCBit = new Gdiplus::CachedBitmap(pBit, &G);
	delete pBit;
	delete memG;
	InvalidateRect(XDWindow::hWndMain, NULL, FALSE);
}

