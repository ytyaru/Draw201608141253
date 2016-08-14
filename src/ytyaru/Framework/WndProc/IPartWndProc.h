#pragma once
#include <windows.h>
#include <tchar.h>

namespace ytyaru {
namespace Framework {
namespace WndProc {
class IPartWndProc
{
public:
	virtual ~IPartWndProc() = 0 {}
	virtual LRESULT CALLBACK PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn) = 0;
};
}
}
}
