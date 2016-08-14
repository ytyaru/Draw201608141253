#pragma once
#include <windows.h>
#include <tchar.h>

class IDrawWndProc
{
public:
	virtual ~IDrawWndProc() = 0 {}
	virtual LRESULT CALLBACK PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn) = 0;
	virtual void Initialize() = 0;
	virtual void Finalize() = 0;
};
