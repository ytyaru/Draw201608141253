#include "Window.h"
#include "Uuid.h"

namespace ytyaru {
namespace Framework {
namespace WndProc {
	
using std::vector;
using std::remove;
using std::basic_string;
using ytyaru::Framework::WndProc::Window;
using ytyaru::Framework::WndProc::IPartWndProc;

Window* Window::m_pWindow = NULL;
std::vector<IPartWndProc*>* Window::m_pPartWndProcs = NULL;

Window::Window(void) {}
Window::~Window(void) {}
Window* Window::CreateInstance()
{
	if (!Window::m_pPartWndProcs) {
		Window::m_pPartWndProcs = new vector<IPartWndProc*>();
	}
	if (!Window::m_pWindow) {
		Window::m_pWindow = new Window();
	}
	return Window::m_pWindow;
}
void Window::RemoveInstance(Window* p)
{
	if (!Window::m_pPartWndProcs) {
		Window::m_pPartWndProcs->clear();
		delete Window::m_pPartWndProcs;
		Window::m_pPartWndProcs = NULL;
	}
	if (!Window::m_pWindow) {
		if (Window::m_pWindow == p) { p = NULL; }
		delete Window::m_pWindow;
		Window::m_pWindow = NULL;
	}
}
void Window::Add(IPartWndProc *pPartWndProc)
{
	if (Window::m_pPartWndProcs) { Window::m_pPartWndProcs->push_back(pPartWndProc); }
}
void Window::Remove(IPartWndProc *pPartWndProc)
{
	std::vector<ytyaru::Framework::WndProc::IPartWndProc*>::iterator it = Window::m_pPartWndProcs->begin();
	while (it != Window::m_pPartWndProcs->end()) {
		if (*it == pPartWndProc) {
			it = Window::m_pPartWndProcs->erase(it);
		}
		else {
			++it;
		}
	}
}
void Window::Create(const HINSTANCE &hInstance)
{
	basic_string<TCHAR> className = ytyaru::Library::Uuid::Get();

	WNDCLASSEX wc;
	wc.cbSize			= sizeof(WNDCLASSEX); 
	wc.style			= CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc		= Window::WndProc;
	wc.cbClsExtra		= 0;
	wc.cbWndExtra		= 0;
	wc.hInstance		= hInstance;
	wc.hIcon			= NULL;
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszMenuName		= NULL;
	wc.lpszClassName	= className.c_str();
	wc.hIconSm			= LoadIcon(NULL, IDI_APPLICATION);
	if (!RegisterClassEx(&wc)) { throw "RegisterClassEx関数が失敗した。"; }

	HWND hWnd = CreateWindowEx(
		0,							// 拡張ウィンドウスタイル
		className.c_str(),			// class名
		_T("Window::Createで生成したWindowです。"),		// タイトル
		WS_OVERLAPPEDWINDOW,		// Style
		CW_USEDEFAULT,				// X
		CW_USEDEFAULT,				// Y
		CW_USEDEFAULT,				// Width
		CW_USEDEFAULT,				// Height
		NULL,						// 親ウィンドウまたはオーナーウィンドウのハンドル
		NULL,						// メニューハンドルまたは子ウィンドウ ID
		hInstance,					// アプリケーションインスタンスのハンドル
		NULL						// ウィンドウ作成データ
	);
	if (NULL == hWnd) { throw "CreateWindow関数が失敗した。"; }

	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);
}
LRESULT CALLBACK Window::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	BOOL isReturn = false;
	for (unsigned int i = 0; i < Window::m_pPartWndProcs->size(); i++) {
		LRESULT res = ((IPartWndProc*)(Window::m_pPartWndProcs->at(i)))->PartWndProc(hWnd, uMsg, wParam, lParam, &isReturn);
		if (isReturn) { return res; }
	}
	if (uMsg == WM_NCDESTROY) { PostQuitMessage(0); }
	return (DefWindowProc(hWnd, uMsg, wParam, lParam));
}

}
}
}
