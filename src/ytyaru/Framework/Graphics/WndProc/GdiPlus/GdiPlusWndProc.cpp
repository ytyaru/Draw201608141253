#pragma comment(lib, "GdiPlus.lib")
#include "GdiPlusWndProc.h"
#include <sti.h>
//using namespace Gdiplus;
using Gdiplus::GdiplusStartupInput;
using Gdiplus::GdiplusStartup;
using Gdiplus::GdiplusShutdown;
using Gdiplus::Graphics;
using Gdiplus::Bitmap;
using Gdiplus::Pen;
using Gdiplus::SolidBrush;
using Gdiplus::Font;
using Gdiplus::StringFormat;
using ytyaru::Framework::Graphics::Drawer::IGdiPlusDrawer;

//GdiPlusWndProc::GdiPlusWndProc(void)
//{
//	m_OffScreenBitmap = NULL;
//	m_OffScreenGraphics = NULL;
//	m_gdiSI = NULL;
//}
//GdiPlusWndProc::GdiPlusWndProc(IGdiPlusDrawer* drawer)
//	: m_drawer(drawer)
//{
//	m_OffScreenBitmap = NULL;
//	m_OffScreenGraphics = NULL;
//	m_gdiSI = NULL;
//}
GdiPlusWndProc::GdiPlusWndProc(ytyaru::Framework::Container::Selector<ytyaru::Framework::Graphics::Drawer::IGdiPlusDrawer*>* drawerSelector)
	: m_drawerSelector(drawerSelector)
{
	m_OffScreenBitmap = NULL;
	m_OffScreenGraphics = NULL;
	m_gdiSI = NULL;
}
GdiPlusWndProc::~GdiPlusWndProc(void) {}
void GdiPlusWndProc::Initialize()
{
	if (NULL == m_gdiSI) {
		m_gdiSI = new Gdiplus::GdiplusStartupInput;
		GdiplusStartup(&m_gdiToken, m_gdiSI, NULL);
	}
	if (NULL == m_OffScreenBitmap) {
		m_OffScreenBitmap = new Bitmap(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
		m_OffScreenGraphics = Graphics::FromImage(m_OffScreenBitmap);
	}

	//if (NULL != m_drawer) { m_drawer->Initialize(); }
	if (NULL != m_drawerSelector) { m_drawerSelector->GetSelected()->Initialize(); }
}
void GdiPlusWndProc::Finalize()
{
	//if (NULL != m_drawer) { m_drawer->Finalize(); }
	if (NULL != m_drawerSelector) { m_drawerSelector->GetSelected()->Finalize(); }

	if (NULL != m_OffScreenGraphics) {
		m_OffScreenGraphics->Flush();
	}
	if (NULL != m_OffScreenBitmap) {;
		delete m_OffScreenBitmap;
		m_OffScreenBitmap = NULL;
	}
	if (NULL != m_OffScreenGraphics) {
		delete m_OffScreenGraphics;
		m_OffScreenGraphics = NULL;
	}
	if (NULL != m_gdiSI) {
		delete m_gdiSI;
		m_gdiSI = NULL;
		GdiplusShutdown(m_gdiToken);
	}
}
LRESULT CALLBACK GdiPlusWndProc::PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn)
{
	switch (uMsg) {
		case WM_CREATE:
			Initialize();
			break;
		case WM_DESTROY:
			Finalize();
			break;
		case WM_ERASEBKGND:
			*pIsReturn = TRUE;
			return TRUE;
		case WM_PAINT:
			{
			HDC hdc;
			PAINTSTRUCT ps;
			hdc = BeginPaint(hWnd , &ps);
			Graphics g(hdc);
			//m_drawer->Draw(m_OffScreenGraphics);
			m_drawerSelector->GetSelected()->Draw(m_OffScreenGraphics);
			g.DrawImage(m_OffScreenBitmap, 0, 0);
			//OnPaint(hdc);
			EndPaint(hWnd , &ps);
			}
			break;
		default:
			break;
	}
	return (0L);
}
//void GdiPlusWndProc::OnPaint(HDC hdc)
//{
//	Graphics g(hdc);
//
//	m_OffScreenGraphics->Clear(Color::White);
//
//	Gdiplus::Pen pen1(Color(255, 255, 0, 0), 5);
//	m_OffScreenGraphics->DrawRectangle(&pen1, 0, 0, 200, 300);
//	
//	Gdiplus::Font font(L"ÇlÇr ÉSÉVÉbÉN", 18);
//	Gdiplus::SolidBrush blackBrush(Color(255, 0, 0, 0));
//	Gdiplus::StringFormat format;
//	format.SetAlignment(StringAlignmentCenter);
//	m_OffScreenGraphics->DrawString(_T("Ç±ÇÃï∂éöóÒÇÕGDI+Ç≈ï`âÊÇµÇƒÇ¢Ç‹Ç∑ÅB"), -1, &font, RectF(0.0f, 0.0f, 200.0f, 300.0f), &format, &blackBrush);
//
//	g.DrawImage(m_OffScreenBitmap, 0, 0);
//}