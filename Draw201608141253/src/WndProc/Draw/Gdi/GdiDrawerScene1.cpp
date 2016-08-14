#include "GdiDrawerScene1.h"
#include <tchar.h>

GdiDrawerScene1::GdiDrawerScene1(void)
{
}
GdiDrawerScene1::~GdiDrawerScene1(void)
{
}
void GdiDrawerScene1::Initialize()
{
	::SetClassLong(::GetActiveWindow(), GCL_HBRBACKGROUND, (LONG)GetStockObject(WHITE_BRUSH));
}
void GdiDrawerScene1::Finalize()
{
}
void GdiDrawerScene1::Draw(const HDC hdc)
{
	LPTSTR lptStr = TEXT("GDIÇ…ÇÊÇÈScene1ÇÃï`âÊÇ≈Ç∑ÅB GdiDrawerScene1");
	TextOut(hdc , 10 , 10 , lptStr , _tcslen(lptStr));
}