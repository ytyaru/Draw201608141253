#pragma once
#include <Windows.h>
#include <gdiplus.h>
#include "IDrawWndProc.h"
#include "IGdiPlusDrawer.h"
#include "Selector.h"
#include "Selector.cpp"

class GdiPlusWndProc : public IDrawWndProc
{
public:
	//GdiPlusWndProc(void);
	//explicit GdiPlusWndProc(ytyaru::Framework::Graphics::Drawer::IGdiPlusDrawer* m_drawer);
	explicit GdiPlusWndProc(ytyaru::Framework::Container::Selector<ytyaru::Framework::Graphics::Drawer::IGdiPlusDrawer*>* drawerSelector);
	~GdiPlusWndProc(void);
	virtual void Initialize();
	virtual void Finalize();
	virtual LRESULT CALLBACK PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn);
private:
	//void OnPaint(HDC hdc);
	//ytyaru::Framework::Graphics::Drawer::IGdiPlusDrawer* m_drawer;
	ytyaru::Framework::Container::Selector<ytyaru::Framework::Graphics::Drawer::IGdiPlusDrawer*>* m_drawerSelector;
	Gdiplus::GdiplusStartupInput* m_gdiSI;
	ULONG_PTR m_gdiToken;
	Gdiplus::Bitmap* m_OffScreenBitmap;
	Gdiplus::Graphics* m_OffScreenGraphics;
};

