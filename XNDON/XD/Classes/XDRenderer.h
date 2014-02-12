#pragma once

#include "XDMain.h"
#include <gdiplus.h>
#pragma comment(lib, "gdiplus")

class XDRenderer
{

public:

	static void Init() {
		Gdiplus::GdiplusStartupInput gpsi;
		if (GdiplusStartup(&m_gpToken, &gpsi, NULL) != Gdiplus::Ok ) {
			MessageBox(NULL, TEXT("GDI+ 라이브러리를 초기화할 수 없습니다."),
				TEXT("알림"), MB_OK);
		}
		return ;
	}

	static void Fin() {
		Gdiplus::GdiplusShutdown(m_gpToken);
	}





	//* 더블 버퍼링
	static int ex, ey;
	static Gdiplus::CachedBitmap *pCBit;

	static void OnPaint(HDC hdc)
	{
		Gdiplus::Graphics G(hdc);

		if (pCBit == NULL) {
			UpdateScreen();
		}
		G.DrawCachedBitmap(pCBit, 0, 0);
	}



	static void UpdateScreen();


private:
	static ULONG_PTR m_gpToken;

private:
	XDRenderer();
	XDRenderer(XDRenderer&);
	~XDRenderer();

};