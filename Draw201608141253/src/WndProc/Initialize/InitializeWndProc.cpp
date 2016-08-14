#include "InitializeWndProc.h"

InitializeWndProc::InitializeWndProc(void) {}
InitializeWndProc::~InitializeWndProc(void) {}
LRESULT CALLBACK InitializeWndProc::PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn)
{
	switch (uMsg) {
    	case WM_CREATE:
    		MessageBox(hWnd, _T("Window1 InitializeWndProc::PartWndProc"), _T("WM_CREATE"), MB_OK);
				SetWindowText(::GetActiveWindow(), _T("1Å`6ÇÃÇ¢Ç∏ÇÍÇ©ÇÃÉLÅ[Çì¸óÕÇµÇƒâ∫Ç≥Ç¢ÅB1:GDI(1), 2:GDI(2), 3:GDI+(1), 4:GDI+(2), 5:DirectX9(1), 6:DirectX9(2)"));
    		break;
		default:
			break;
	}
	return (0L);
}
