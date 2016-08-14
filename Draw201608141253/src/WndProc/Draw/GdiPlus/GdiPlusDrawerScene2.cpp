#include "GdiPlusDrawerScene2.h"
#include <Windows.h>
#include <tchar.h>
#include <sti.h>
#include <gdiplus.h>
using Gdiplus::Graphics;
using Gdiplus::Color;
using Gdiplus::Bitmap;
using Gdiplus::Pen;
using Gdiplus::SolidBrush;
using Gdiplus::RectF;
using Gdiplus::Font;
using Gdiplus::StringFormat;
using Gdiplus::StringAlignmentCenter;

GdiPlusDrawerScene2::GdiPlusDrawerScene2(void)
{
}
GdiPlusDrawerScene2::~GdiPlusDrawerScene2(void)
{
}
void GdiPlusDrawerScene2::Initialize()
{
}
void GdiPlusDrawerScene2::Finalize()
{
}
void GdiPlusDrawerScene2::Draw(Graphics* g)
{
	g->Clear(Color::White);

	Gdiplus::Pen pen1(Color(255, 255, 0, 0), 5);
	g->DrawRectangle(&pen1, 0, 0, 200, 300);
	
	Gdiplus::Font font(L"‚l‚r ƒSƒVƒbƒN", 18);
	Gdiplus::SolidBrush blackBrush(Color(255, 0, 0, 0));
	Gdiplus::StringFormat format;
	format.SetAlignment(StringAlignmentCenter);
	g->DrawString(_T("GDI+‚Å•`‰æ’†BGdiPlusDrawerScene2"), -1, &font, RectF(0.0f, 0.0f, 200.0f, 300.0f), &format, &blackBrush);
}