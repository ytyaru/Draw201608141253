#include <locale.h>
#include <windows.h>
#include <tchar.h>
#include "IPartWndProc.h"
#include "Window.h"
//#include "GraphicsArchitectureSetter.h"
#include "InitializeWndProc.h"
#include "KeyboardWndProc.h"
#include "GdiWndProc.h"
#include "GdiPlusWndProc.h"
#include "DrawWndProc.h"
#include "GraphicsSelector.h"

using ytyaru::Framework::WndProc::Window;
using ytyaru::Framework::WndProc::IPartWndProc;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInst, LPSTR lpszCmdLine, int nCmdShow)
{
	setlocale(LC_ALL, ".ACP");

	Window *pWindow = Window::CreateInstance();
	
	GraphicsSelector graphicsSelector;
	graphicsSelector.Initialize();

	//GraphicsArchitectureSetter graphicsArchitectureSetter;
	//graphicsArchitectureSetter.Initialize();

	InitializeWndProc initializeWndProc;
	pWindow->Add((IPartWndProc*)&initializeWndProc);
	
	//KeyboardWndProc keyboardWndProc(&graphicsArchitectureSetter);
	//KeyboardWndProc keyboardWndProc(*graphicsSelector.GetDrawWndProcSelector());
	//KeyboardWndProc keyboardWndProc(graphicsSelector.GetDrawWndProcSelector());
	KeyboardWndProc keyboardWndProc(&graphicsSelector);
	pWindow->Add((IPartWndProc*)&keyboardWndProc);
	
	//DrawWndProc drawWndProc(&graphicsArchitectureSetter);
	//DrawWndProc drawWndProc(graphicsSelector.GetDrawWndProcSelector()->GetSelected());
	//DrawWndProc drawWndProc(graphicsSelector.GetDrawWndProcSelector());
	DrawWndProc drawWndProc(&graphicsSelector);
	pWindow->Add((IPartWndProc*)&drawWndProc);

	pWindow->Create(hInstance);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	//graphicsArchitectureSetter.Finalize();
	graphicsSelector.Finalize();
	Window::RemoveInstance(pWindow);

	return (msg.wParam);
}
