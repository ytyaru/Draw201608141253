#pragma once
#include "IPartWndProc.h"
//#include "GraphicsArchitectureSetter.h"
#include "GraphicsSelector.h"

class KeyboardWndProc : public ytyaru::Framework::WndProc::IPartWndProc
{
public:
	//explicit KeyboardWndProc(GraphicsArchitectureSetter* graphicsArchitectureSetter);
	//explicit KeyboardWndProc(const ytyaru::Framework::Container::Selector<IDrawWndProc*>& drawWndProcSelector);
	//explicit KeyboardWndProc(ytyaru::Framework::Container::Selector<IDrawWndProc*>* drawWndProcSelector);
	explicit KeyboardWndProc(GraphicsSelector* graphicsSelector);
	~KeyboardWndProc(void);
	virtual LRESULT CALLBACK PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn);
private:
	//GraphicsArchitectureSetter* m_graphicsArchitectureSetter;
	//ytyaru::Framework::Container::Selector<IDrawWndProc*> m_drawWndProcSelector;
	//ytyaru::Framework::Container::Selector<IDrawWndProc*>* m_drawWndProcSelector;
	GraphicsSelector* m_graphicsSelector;
};
