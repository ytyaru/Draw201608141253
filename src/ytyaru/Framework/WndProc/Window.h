#pragma once
#pragma comment(lib, "Rpcrt4.lib")
#include <windows.h>
#include <tchar.h>
#include <vector>
#include "IPartWndProc.h"

namespace ytyaru {
namespace Framework {
namespace WndProc {
class Window
{
public:
	~Window(void);
	static Window* CreateInstance();
	static void RemoveInstance(Window*);
	static void Add(IPartWndProc *pPartWndProc);
	static void Remove(IPartWndProc *pPartWndProc);
	static void Create(const HINSTANCE &hInstance);
protected:
private:
	Window(void);
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	static Window *m_pWindow;
	static std::vector<ytyaru::Framework::WndProc::IPartWndProc*>* m_pPartWndProcs;
};
}
}
}
