#include "DrawWndProc.h"
using std::vector;
using std::pair;
using std::basic_string;
using ytyaru::Framework::WndProc::IPartWndProc;
using ytyaru::Framework::Container::Selector;

//DrawWndProc::DrawWndProc(GraphicsArchitectureSetter* graphicsArchitectureSetter)
//	: m_graphicsArchitectureSetter(graphicsArchitectureSetter) {}
//DrawWndProc::DrawWndProc(IDrawWndProc* selectedWndProc)
//	: m_selectedWndProc(selectedWndProc) {}
//DrawWndProc::DrawWndProc(Selector<IDrawWndProc*>* drawWndProcSelector)
//	: m_drawWndProcSelector(drawWndProcSelector) {}
DrawWndProc::DrawWndProc(GraphicsSelector* graphicsSelector)
	: m_graphicsSelector(graphicsSelector) {}
DrawWndProc::~DrawWndProc(void) {}
void DrawWndProc::Initialize() {}
void DrawWndProc::Finalize() {}
LRESULT CALLBACK DrawWndProc::PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn)
{
	//return m_graphicsArchitectureSetter->Get()->PartWndProc(hWnd, uMsg, wParam, lParam, pIsReturn);
	//return m_selectedWndProc->PartWndProc(hWnd, uMsg, wParam, lParam, pIsReturn);
	//return m_drawWndProcSelector->GetSelected()->PartWndProc(hWnd, uMsg, wParam, lParam, pIsReturn);
	return m_graphicsSelector->GetSelectedDrawWndProc()->PartWndProc(hWnd, uMsg, wParam, lParam, pIsReturn);
	
}