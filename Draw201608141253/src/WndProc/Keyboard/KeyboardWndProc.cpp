#include "KeyboardWndProc.h"

using ytyaru::Framework::Container::Selector;
KeyboardWndProc::KeyboardWndProc(GraphicsSelector* graphicsSelector)
	: m_graphicsSelector(graphicsSelector) {}
KeyboardWndProc::~KeyboardWndProc(void) {}
LRESULT CALLBACK KeyboardWndProc::PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn)
{
	switch (uMsg) {
		case WM_KEYDOWN:
			switch (wParam)
			{
			case 0x31: //VK_1: ASCIIコードと同一
			case 0x61: //VK_NUMPAD1:
				m_graphicsSelector->Select(_T("GDI"), _T("Scene1"));
				::InvalidateRect(NULL, NULL, false);
				SetWindowText(::GetActiveWindow(), _T("GDI(1)描画中。1:GDI(1), 2:GDI(2), 3:GDI+(1), 4:GDI+(2), 5:DirectX9(1), 6:DirectX9(2)  1～6のいずれかのキーを入力して下さい。"));
				break;
			case 0x32: //VK_1: ASCIIコードと同一
			case 0x62: //VK_NUMPAD1:
				m_graphicsSelector->Select(_T("GDI"), _T("Scene2"));
				::InvalidateRect(NULL, NULL, false);
				SetWindowText(::GetActiveWindow(), _T("GDI(2)描画中。1:GDI(1), 2:GDI(2), 3:GDI+(1), 4:GDI+(2), 5:DirectX9(1), 6:DirectX9(2)  1～6のいずれかのキーを入力して下さい。"));
				break;
			case 0x33: //VK_2: ASCIIコードと同一
			case 0x63: //VK_NUMPAD2:
				m_graphicsSelector->Select(_T("GDI+"), _T("Scene1"));
				::InvalidateRect(NULL, NULL, false);
				SetWindowText(::GetActiveWindow(), _T("GDI+(1)描画中。1:GDI(1), 2:GDI(2), 3:GDI+(1), 4:GDI+(2), 5:DirectX9(1), 6:DirectX9(2)  1～6のいずれかのキーを入力して下さい。"));
				break;
			case 0x34: //VK_2: ASCIIコードと同一
			case 0x64: //VK_NUMPAD2:
				m_graphicsSelector->Select(_T("GDI+"), _T("Scene2"));
				::InvalidateRect(NULL, NULL, false);
				SetWindowText(::GetActiveWindow(), _T("GDI+(2)描画中。1:GDI(1), 2:GDI(2), 3:GDI+(1), 4:GDI+(2), 5:DirectX9(1), 6:DirectX9(2)  1～6のいずれかのキーを入力して下さい。"));
				break;
			case 0x35: //VK_3: ASCIIコードと同一
			case 0x65: //VK_NUMPAD3:
				m_graphicsSelector->Select(_T("DirectX9"), _T("Scene1"));
				::InvalidateRect(NULL, NULL, false);
				SetWindowText(::GetActiveWindow(), _T("DirectX9(1)描画中。1:GDI(1), 2:GDI(2), 3:GDI+(1), 4:GDI+(2), 5:DirectX9(1), 6:DirectX9(2)  1～6のいずれかのキーを入力して下さい。"));
				break;
			case 0x36: //VK_3: ASCIIコードと同一
			case 0x66: //VK_NUMPAD3:
				m_graphicsSelector->Select(_T("DirectX9"), _T("Scene2"));
				::InvalidateRect(NULL, NULL, false);
				SetWindowText(::GetActiveWindow(), _T("DirectX9(2)描画中。1:GDI(1), 2:GDI(2), 3:GDI+(1), 4:GDI+(2), 5:DirectX9(1), 6:DirectX9(2)  1～6のいずれかのキーを入力して下さい。"));
				break;
			default:
				MessageBox(hWnd, _T("Window1 KeyboardWndProc::PartWndProc"), _T("WM_KEYDOWN"), MB_OK);
				break;
			}
			break;
		default:
			break;
	}
	return (0L);
}
