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
			MessageBox(NULL, TEXT("GDI+ ���̺귯���� �ʱ�ȭ�� �� �����ϴ�."),
				TEXT("�˸�"), MB_OK);
		}
		return ;
	}

	static void Fin() {
		Gdiplus::GdiplusShutdown(m_gpToken);
	}





	//* ���� ���۸�
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