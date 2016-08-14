#pragma once
#include "tchar.h"
#include "string"
#include "Selector.h"
#include "Selector.cpp"
#include "IDrawWndProc.h"
#include "IGdiDrawer.h"
#include "IGdiPlusDrawer.h"
#include "IDirectX9Drawer.h"

template class ytyaru::Framework::Container::Selector<ytyaru::Framework::Graphics::Drawer::IGdiDrawer*>;
template class ytyaru::Framework::Container::Selector<ytyaru::Framework::Graphics::Drawer::IGdiPlusDrawer*>;
template class ytyaru::Framework::Container::Selector<ytyaru::Framework::Graphics::Drawer::IDirectX9Drawer*>;

class GraphicsSelector
{
public:
	GraphicsSelector(void);
	~GraphicsSelector(void);
	void Initialize();
	void Finalize();
	void Select(const std::basic_string<TCHAR>& wndProcKey, const std::basic_string<TCHAR>& drawerKey);
	//void SelectDrawWndProc(const std::basic_string<TCHAR>& key);
	void SelectDrawWndProc(const std::basic_string<TCHAR>& key);
	void SelectGdiDrawer(const std::basic_string<TCHAR>& key);
	void SelectGdiPlusDrawer(const std::basic_string<TCHAR>& key);
	void SelectDirectX9Drawer(const std::basic_string<TCHAR>& key);
	IDrawWndProc* GetSelectedDrawWndProc();
	ytyaru::Framework::Graphics::Drawer::IGdiDrawer* GetSelectedGdiDrawer();
	ytyaru::Framework::Graphics::Drawer::IGdiPlusDrawer* GetSelectedGdiPlusDrawer();
	ytyaru::Framework::Graphics::Drawer::IDirectX9Drawer* GetSelectedDirectX9Drawer();

	ytyaru::Framework::Container::Selector<IDrawWndProc*>* GetDrawWndProcSelector();
	ytyaru::Framework::Container::Selector<ytyaru::Framework::Graphics::Drawer::IGdiDrawer*>* GetGdiDrawerSelector();
	ytyaru::Framework::Container::Selector<ytyaru::Framework::Graphics::Drawer::IGdiPlusDrawer*>* GetGdiPlusDrawerSelector();
	ytyaru::Framework::Container::Selector<ytyaru::Framework::Graphics::Drawer::IDirectX9Drawer*>* GetDirectX9DrawerSelector();
private:
	ytyaru::Framework::Container::Selector<IDrawWndProc*> m_drawWndProcSelector;
	ytyaru::Framework::Container::Selector<ytyaru::Framework::Graphics::Drawer::IGdiDrawer*> m_gdiSelector;
	ytyaru::Framework::Container::Selector<ytyaru::Framework::Graphics::Drawer::IGdiPlusDrawer*> m_gdiPlusSelector;
	ytyaru::Framework::Container::Selector<ytyaru::Framework::Graphics::Drawer::IDirectX9Drawer*> m_directX9Selector;

	//ytyaru::Framework::Container::Selector<ytyaru::Framework::Graphics::Drawer::IDrawer<HDC>*> m_gdiDrawerSelector;
	//ytyaru::Framework::Container::Selector<ytyaru::Framework::Graphics::Drawer::IDrawer<Gdiplus::Graphics*>*> m_gdiPlusDrawerSelector;
	//ytyaru::Framework::Container::Selector<ytyaru::Framework::Graphics::Drawer::IDrawer<LPDIRECT3DDEVICE9>*> m_directX9DrawerSelector;
};

