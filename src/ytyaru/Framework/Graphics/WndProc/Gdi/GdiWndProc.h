#pragma once
#include "IDrawWndProc.h"
#include "IGdiDrawer.h"
#include "Selector.h"
#include "Selector.cpp"

class GdiWndProc : public IDrawWndProc
{
public:
	//GdiWndProc(void);
	//explicit GdiWndProc(ytyaru::Framework::Graphics::Drawer::IGdiDrawer* drawer);
	//explicit GdiWndProc(const ytyaru::Framework::Container::Selector<ytyaru::Framework::Graphics::Drawer::IGdiDrawer*>& drawerSelector);
	explicit GdiWndProc(ytyaru::Framework::Container::Selector<ytyaru::Framework::Graphics::Drawer::IGdiDrawer*>* drawerSelector);
	~GdiWndProc(void);
	virtual void Initialize();
	virtual void Finalize();
	virtual LRESULT CALLBACK PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn);
private:
	//void OnPaint(HDC hdc);
	//ytyaru::Framework::Graphics::Drawer::IGdiDrawer* m_drawer;
	//ytyaru::Framework::Container::Selector<ytyaru::Framework::Graphics::Drawer::IGdiDrawer*> m_drawerSelector;
	ytyaru::Framework::Container::Selector<ytyaru::Framework::Graphics::Drawer::IGdiDrawer*>* m_drawerSelector;
};

