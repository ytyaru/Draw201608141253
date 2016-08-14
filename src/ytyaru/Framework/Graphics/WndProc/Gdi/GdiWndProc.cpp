#include "GdiWndProc.h"
using ytyaru::Framework::Container::Selector;
using ytyaru::Framework::Graphics::Drawer::IGdiDrawer;

//GdiWndProc::GdiWndProc(void) {}
//GdiWndProc::GdiWndProc(IGdiDrawer* drawer) : m_drawer(drawer) {}
//GdiWndProc::GdiWndProc(const Selector<IGdiDrawer*>& drawerSelector) : m_drawerSelector(drawerSelector) {}
GdiWndProc::GdiWndProc(Selector<IGdiDrawer*>* drawerSelector) : m_drawerSelector(drawerSelector) {}
GdiWndProc::~GdiWndProc(void) {}
//void GdiWndProc::Initialize() { m_drawer->Initialize(); }
//void GdiWndProc::Finalize() { m_drawer->Finalize(); }
//void GdiWndProc::Initialize() { m_drawerSelector.GetSelected()->Initialize(); }
//void GdiWndProc::Finalize() { m_drawerSelector.GetSelected()->Finalize(); }
void GdiWndProc::Initialize() { m_drawerSelector->GetSelected()->Initialize(); }
void GdiWndProc::Finalize() { m_drawerSelector->GetSelected()->Finalize(); }
LRESULT CALLBACK GdiWndProc::PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn)
{
	switch (uMsg) {
		// ÉoÉOÇÈ
		//case WM_ERASEBKGND:
		//	*pIsReturn = TRUE;
		//	return TRUE;
		case WM_PAINT:
			HDC hdc;
			PAINTSTRUCT ps;
			hdc = BeginPaint(hWnd , &ps);
			//OnPaint(hdc);
			//m_drawer->Draw(hdc);
			//m_drawerSelector.GetSelected()->Draw(hdc);
			m_drawerSelector->GetSelected()->Draw(hdc);
			EndPaint(hWnd , &ps);
			break;
		default:
			break;
	}
	return (0L);
}
//void GdiWndProc::OnPaint(HDC hdc)
//{
//	LPTSTR lptStr = TEXT("Ç±ÇÃï∂éöóÒÇÕGDIÇ≈ï`âÊÇµÇƒÇ¢Ç‹Ç∑ÅB");
//	TextOut(hdc , 10 , 10 , lptStr , _tcslen(lptStr));
//}