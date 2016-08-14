#pragma once
#include <Windows.h>
#include <tchar.h>
#include <vector>
#include <map>
#include <string>
#include "IPartWndProc.h"
//#include "GraphicsArchitectureSetter.h"
#include "GraphicsSelector.h"
#include "GdiWndProc.h"
#include "GdiPlusWndProc.h"
#include "DirectX9WndProc.h"

class DrawWndProc : public ytyaru::Framework::WndProc::IPartWndProc
{
public:
	//explicit DrawWndProc(GraphicsArchitectureSetter* graphicsArchitectureSetter);
	//explicit DrawWndProc(IDrawWndProc* selectedWndProc);
	//explicit DrawWndProc(ytyaru::Framework::Container::Selector<IDrawWndProc*>* drawWndProcSelector);
	explicit DrawWndProc(GraphicsSelector* graphicsSelector);
	~DrawWndProc(void);
	virtual LRESULT CALLBACK PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn);
	void Initialize();
	void Finalize();
private:
	//GraphicsArchitectureSetter* m_graphicsArchitectureSetter;
	//IDrawWndProc* m_selectedWndProc;
	//ytyaru::Framework::Container::Selector<IDrawWndProc*>* m_drawWndProcSelector;
	GraphicsSelector* m_graphicsSelector;
};

