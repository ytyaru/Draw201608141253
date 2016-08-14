#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "d3d9.lib")
#include "DirectX9WndProc.h"

using ytyaru::Framework::Graphics::Drawer::IDirectX9Drawer;
using ytyaru::Framework::Container::Selector;

//DirectX9WndProc::DirectX9WndProc(void)
//{
//	m_pD3D = NULL;
//	m_pD3DDev = NULL;
//}
//DirectX9WndProc::DirectX9WndProc(IDirectX9Drawer* drawer)
//	: m_drawer(drawer)
//{
//	m_pD3D = NULL;
//	m_pD3DDev = NULL;
//}
DirectX9WndProc::DirectX9WndProc(Selector<IDirectX9Drawer*>* drawerSelector)
	: m_drawerSelector(drawerSelector)
{
	m_pD3D = NULL;
	m_pD3DDev = NULL;
}
DirectX9WndProc::~DirectX9WndProc(void) { Finalize(); }
void DirectX9WndProc::Initialize()
{
	// 事前にCreateWindow()されていなければDirectX9を初期化できない
	HWND hWnd = GetActiveWindow();
	if (NULL == hWnd) { return; }

	if (NULL != m_pD3D) { return; }

	if( !(m_pD3D = Direct3DCreate9( D3D_SDK_VERSION )) )
	{
		throw "Direct3DCreate9関数に失敗しました。";
	}
	D3DPRESENT_PARAMETERS d3dpp = { 0, 0, D3DFMT_UNKNOWN, 0, D3DMULTISAMPLE_NONE, 0, D3DSWAPEFFECT_DISCARD, NULL, TRUE, 0, D3DFMT_UNKNOWN, 0, 0 };
	
	// HAL(ハードウェアアクセラレーション)
	if( FAILED( m_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &m_pD3DDev ) ) ) {
	// HEL(ソフトウェアエミュレーション)
	if( FAILED( m_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &m_pD3DDev ) ) )
	{
		m_pD3D->Release();
		throw "DIRECT3D9.CreateDevice関数に失敗しました。";
	}
	}
	//if (NULL != m_drawer) { m_drawer->Initialize(); }
	if (NULL != m_drawerSelector) { m_drawerSelector->GetSelected()->Initialize(); }
}
void DirectX9WndProc::Finalize()
{
	//if (NULL != m_drawer) { m_drawer->Finalize(); }
	if (NULL != m_drawerSelector) { m_drawerSelector->GetSelected()->Finalize(); }

	if (NULL != m_pD3DDev) {
		m_pD3DDev->Release();
		m_pD3DDev = NULL;
	}
	if (NULL != m_pD3D) {
		m_pD3D->Release();
		m_pD3D = NULL;
	}
}
LRESULT CALLBACK DirectX9WndProc::PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn)
{
	switch (uMsg) {
		case WM_CREATE:
			Initialize();
			break;
		case WM_DESTROY:
			Finalize();
			break;
		case WM_ERASEBKGND:
			*pIsReturn = TRUE;
			return TRUE;
		default:
			if (NULL == m_pD3DDev) { return (0L); }
			//m_drawer->Draw(m_pD3DDev);
			m_drawerSelector->GetSelected()->Draw(m_pD3DDev);
			//OnPaint();
			break;
	}
	return (0L);
}
//void DirectX9WndProc::OnPaint()
//{
//	m_pD3DDev->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0,0,255), 1.0f, 0 );
//	m_pD3DDev->BeginScene();
//
//	// 何か描画する
//
//	m_pD3DDev->EndScene();
//	m_pD3DDev->Present( NULL, NULL, NULL, NULL );
//}