#include "GraphicsSelector.h"
#include "GdiWndProc.h"
#include "GdiPlusWndProc.h"
#include "DirectX9WndProc.h"
#include "GdiDrawerScene1.h"
#include "GdiDrawerScene2.h"
#include "GdiPlusDrawerScene1.h"
#include "GdiPlusDrawerScene2.h"
#include "DirectX9DrawerScene1.h"
#include "DirectX9DrawerScene2.h"

using ytyaru::Framework::Container::Selector;
//using ytyaru::Framework::Graphics::Drawer::IDrawer;
using ytyaru::Framework::Graphics::Drawer::IGdiDrawer;
using ytyaru::Framework::Graphics::Drawer::IGdiPlusDrawer;
using ytyaru::Framework::Graphics::Drawer::IDirectX9Drawer;

GraphicsSelector::GraphicsSelector(void)
{
}
GraphicsSelector::~GraphicsSelector(void)
{
}
void GraphicsSelector::Initialize()
{
	if (!m_gdiSelector.IsContain(_T("Scene1"))) {
		m_gdiSelector.Add(_T("Scene1"), (IGdiDrawer*) new GdiDrawerScene1());
	}
	if (!m_gdiSelector.IsContain(_T("Scene2"))) {
		m_gdiSelector.Add(_T("Scene2"), (IGdiDrawer*) new GdiDrawerScene2());
	}
	m_gdiSelector.Select(_T("Scene1"));

	if (!m_gdiPlusSelector.IsContain(_T("Scene1"))) {
		m_gdiPlusSelector.Add(_T("Scene1"), (IGdiPlusDrawer*) new GdiPlusDrawerScene1());
	}
	if (!m_gdiPlusSelector.IsContain(_T("Scene2"))) {
		m_gdiPlusSelector.Add(_T("Scene2"), (IGdiPlusDrawer*) new GdiPlusDrawerScene2());
	}
	m_gdiPlusSelector.Select(_T("Scene1"));

	if (!m_directX9Selector.IsContain(_T("Scene1"))) {
		m_directX9Selector.Add(_T("Scene1"), (IDirectX9Drawer*) new DirectX9DrawerScene1());
	}
	if (!m_directX9Selector.IsContain(_T("Scene2"))) {
		m_directX9Selector.Add(_T("Scene2"), (IDirectX9Drawer*) new DirectX9DrawerScene2());
	}
	m_directX9Selector.Select(_T("Scene1"));

	if (!m_drawWndProcSelector.IsContain(_T("GDI"))) {
		m_drawWndProcSelector.Add(_T("GDI"), (IDrawWndProc*) new GdiWndProc(&m_gdiSelector));
	}
	if (!m_drawWndProcSelector.IsContain(_T("GDI+"))) {
		m_drawWndProcSelector.Add(_T("GDI+"), (IDrawWndProc*) new GdiPlusWndProc(&m_gdiPlusSelector));
	}
	if (!m_drawWndProcSelector.IsContain(_T("DirectX9"))) {
		m_drawWndProcSelector.Add(_T("DirectX9"), (IDrawWndProc*) new DirectX9WndProc(&m_directX9Selector));
	}
	m_drawWndProcSelector.Select(_T("GDI"));

	this->Select(_T("GDI"), _T("Scene1"));



	
	//Selector<IDrawer<HDC>*> m_gdiDrawerSelector;
	//Selector<IDrawer<Gdiplus::Graphics*>*> m_gdiPlusDrawerSelector;
	//Selector<IDrawer<LPDIRECT3DDEVICE9>*> m_directX9DrawerSelector;
}
void GraphicsSelector::Finalize()
{
	delete m_drawWndProcSelector.Get(_T("GDI"));
	delete m_drawWndProcSelector.Get(_T("GDI+"));
	delete m_drawWndProcSelector.Get(_T("DirectX9"));
	m_drawWndProcSelector.Clear();

	delete m_gdiSelector.Get(_T("Scene1"));
	delete m_gdiSelector.Get(_T("Scene2"));
	m_gdiSelector.Clear();
	delete m_gdiPlusSelector.Get(_T("Scene1"));
	delete m_gdiPlusSelector.Get(_T("Scene2"));
	m_gdiPlusSelector.Clear();
	delete m_directX9Selector.Get(_T("Scene1"));
	delete m_directX9Selector.Get(_T("Scene2"));
	m_directX9Selector.Clear();
}
void GraphicsSelector::SelectDrawWndProc(const std::basic_string<TCHAR>& key)
{
	if (!m_drawWndProcSelector.IsContain(key)) { return; }
	if (m_drawWndProcSelector.Get(key) == m_drawWndProcSelector.GetSelected()) { return; }
	m_drawWndProcSelector.GetSelected()->Finalize();
	m_drawWndProcSelector.Select(key);
	m_drawWndProcSelector.GetSelected()->Initialize();
}
//void GraphicsSelector::SelectGdiDrawer(const std::basic_string<TCHAR>& key)
//{
//	if (!m_gdiSelector.IsContain(key)) { return; }
//	if (m_gdiSelector.Get(key) == m_gdiSelector.GetSelected()) { return; }
//	//m_gdiSelector.GetSelected()->Finalize();
//	m_gdiSelector.Select(key);
//	//m_gdiSelector.GetSelected()->Initialize();
//}
//void GraphicsSelector::SelectGdiPlusDrawer(const std::basic_string<TCHAR>& key)
//{
//	if (!m_gdiSelector.IsContain(key)) { return; }
//	if (m_gdiPlusSelector.Get(key) == m_gdiPlusSelector.GetSelected()) { return; }
//	//m_gdiPlusSelector.GetSelected()->Finalize();
//	m_gdiPlusSelector.Select(key);
//	//m_gdiPlusSelector.GetSelected()->Initialize();
//}
//void GraphicsSelector::SelectDirectX9Drawer(const std::basic_string<TCHAR>& key)
//{
//	if (!m_directX9Selector.IsContain(key)) { return; }
//	if (m_directX9Selector.Get(key) == m_directX9Selector.GetSelected()) { return; }
//	//m_directX9Selector.GetSelected()->Finalize();
//	m_directX9Selector.Select(key);
//	//m_directX9Selector.GetSelected()->Initialize();
//}
//void GraphicsSelector::Select(const std::basic_string<TCHAR>& wndProcKey, const std::basic_string<TCHAR>& drawerKey)
//{
//	if (_T("GDI") == wndProcKey) {
//		if (m_drawWndProcSelector.Get(_T("GDI")) == m_drawWndProcSelector.GetSelected()) {
//			// --------------------
//			if (m_gdiSelector.GetSelected() != m_gdiSelector.Get(drawerKey)) {
//				m_gdiSelector.GetSelected()->Finalize();
//				this->SelectGdiDrawer(drawerKey);
//				m_gdiSelector.GetSelected()->Initialize();
//			}
//		} else {
//			m_drawWndProcSelector.GetSelected()->Finalize();
//			m_drawWndProcSelector.Select(wndProcKey);
//			this->SelectGdiDrawer(drawerKey);
//			m_drawWndProcSelector.GetSelected()->Initialize();
//		}
//	} else if (_T("GDI+") == wndProcKey) {
//		if (m_drawWndProcSelector.Get(_T("GDI+")) == m_drawWndProcSelector.GetSelected()) {
//			if (m_gdiPlusSelector.GetSelected() != m_gdiPlusSelector.Get(drawerKey)) {
//				m_gdiPlusSelector.GetSelected()->Finalize();
//				this->SelectGdiPlusDrawer(drawerKey);
//				m_gdiPlusSelector.GetSelected()->Initialize();
//			}
//		} else {
//			m_drawWndProcSelector.GetSelected()->Finalize();
//			m_drawWndProcSelector.Select(wndProcKey);
//			this->SelectGdiPlusDrawer(drawerKey);
//			m_drawWndProcSelector.GetSelected()->Initialize();
//		}
//	} else if (_T("DirectX9") == wndProcKey) {
//		if (m_drawWndProcSelector.Get(_T("DirectX9")) == m_drawWndProcSelector.GetSelected()) {
//			if (m_directX9Selector.GetSelected() != m_directX9Selector.Get(drawerKey)) {
//				m_directX9Selector.GetSelected()->Finalize();
//				this->SelectDirectX9Drawer(drawerKey);
//				m_directX9Selector.GetSelected()->Initialize();
//			}
//		} else {
//			m_drawWndProcSelector.GetSelected()->Finalize();
//			m_drawWndProcSelector.Select(wndProcKey);
//			this->SelectDirectX9Drawer(drawerKey);
//			m_drawWndProcSelector.GetSelected()->Initialize();
//		}
//	} else {}
//}
void GraphicsSelector::SelectGdiDrawer(const std::basic_string<TCHAR>& key)
{
	if (!m_gdiSelector.IsContain(key)) { return; }
	if (m_gdiSelector.Get(key) == m_gdiSelector.GetSelected()) { return; }
	m_gdiSelector.GetSelected()->Finalize();
	m_gdiSelector.Select(key);
	m_gdiSelector.GetSelected()->Initialize();
}
void GraphicsSelector::SelectGdiPlusDrawer(const std::basic_string<TCHAR>& key)
{
	if (!m_gdiSelector.IsContain(key)) { return; }
	if (m_gdiPlusSelector.Get(key) == m_gdiPlusSelector.GetSelected()) { return; }
	m_gdiPlusSelector.GetSelected()->Finalize();
	m_gdiPlusSelector.Select(key);
	m_gdiPlusSelector.GetSelected()->Initialize();
}
void GraphicsSelector::SelectDirectX9Drawer(const std::basic_string<TCHAR>& key)
{
	if (!m_directX9Selector.IsContain(key)) { return; }
	if (m_directX9Selector.Get(key) == m_directX9Selector.GetSelected()) { return; }
	m_directX9Selector.GetSelected()->Finalize();
	m_directX9Selector.Select(key);
	m_directX9Selector.GetSelected()->Initialize();
}
void GraphicsSelector::Select(const std::basic_string<TCHAR>& wndProcKey, const std::basic_string<TCHAR>& drawerKey)
{
	if (_T("GDI") == wndProcKey) {
		this->SelectDrawWndProc(wndProcKey);
		this->SelectGdiDrawer(drawerKey);
	} else if (_T("GDI+") == wndProcKey) {
		this->SelectDrawWndProc(wndProcKey);
		this->SelectGdiPlusDrawer(drawerKey);
	} else if (_T("DirectX9") == wndProcKey) {
		this->SelectDrawWndProc(wndProcKey);
		this->SelectDirectX9Drawer(drawerKey);
	} else {}
}

IDrawWndProc* GraphicsSelector::GetSelectedDrawWndProc()
{
	return m_drawWndProcSelector.GetSelected();
}
IGdiDrawer* GraphicsSelector::GetSelectedGdiDrawer()
{
	return m_gdiSelector.GetSelected();
}
IGdiPlusDrawer* GraphicsSelector::GetSelectedGdiPlusDrawer()
{
	return m_gdiPlusSelector.GetSelected();
}
IDirectX9Drawer* GraphicsSelector::GetSelectedDirectX9Drawer()
{
	return m_directX9Selector.GetSelected();
}

Selector<IDrawWndProc*>* GraphicsSelector::GetDrawWndProcSelector()
{
	return &m_drawWndProcSelector;
}
Selector<IGdiDrawer*>* GraphicsSelector::GetGdiDrawerSelector()
{
	return &m_gdiSelector;
}
Selector<IGdiPlusDrawer*>* GraphicsSelector::GetGdiPlusDrawerSelector()
{
	return &m_gdiPlusSelector;
}
Selector<IDirectX9Drawer*>* GraphicsSelector::GetDirectX9DrawerSelector()
{
	return &m_directX9Selector;
}
