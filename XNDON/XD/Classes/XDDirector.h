#pragma once
#include "XDWindow.h"
#include "XDScene.h"
#include "XDRenderer.h"

class XDDirector
{
public:
	static void CALLBACK Update(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);

private:
	static XDScene* m_pScene;
	static double m_frame;

private:
	XDDirector();
	XDDirector(XDDirector&);
	~XDDirector();
};