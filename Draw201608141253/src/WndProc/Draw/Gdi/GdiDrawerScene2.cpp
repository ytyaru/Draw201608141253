#include "GdiDrawerScene2.h"
#include <tchar.h>

GdiDrawerScene2::GdiDrawerScene2(void)
{
}
GdiDrawerScene2::~GdiDrawerScene2(void)
{
}
void GdiDrawerScene2::Initialize()
{
	//DWORD hbrBackGround = ::GetClassLong(::GetActiveWindow(), GCL_HBRBACKGROUND);
	//hbrBackGround = (HBRUSH)GetStockObject(BLACK_BRUSH);
	::SetClassLong(::GetActiveWindow(), GCL_HBRBACKGROUND, (LONG)GetStockObject(BLACK_BRUSH));
}
void GdiDrawerScene2::Finalize()
{
}
void GdiDrawerScene2::Draw(const HDC hdc)
{
	::SetTextColor(hdc, RGB(255,216,216));
	::SetBkColor(hdc, RGB(0,128,0));
	LPTSTR lptStr = TEXT("GDIÇ…ÇÊÇÈScene2ÇÃï`âÊÇ≈Ç∑ÅB GdiDrawerScene2");
	::TextOut(hdc , 10 , 10 , lptStr , _tcslen(lptStr));
}