#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#include "DirectX9DrawerScene2.h"
#include <tchar.h>

DirectX9DrawerScene2::DirectX9DrawerScene2(void)
{
	m_pFont = NULL;
}
DirectX9DrawerScene2::~DirectX9DrawerScene2(void)
{
}
void DirectX9DrawerScene2::Initialize()
{
}
void DirectX9DrawerScene2::Finalize()
{
	if (NULL != m_pFont) {
		m_pFont->Release();
		m_pFont = NULL;
	}
}
void DirectX9DrawerScene2::Draw(const LPDIRECT3DDEVICE9 lpD3DDev)
{
	lpD3DDev->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0,255,0), 1.0f, 0 );
	lpD3DDev->BeginScene();
	
	RECT rect;
	SetRect(&rect, 0, 0, 50, 50);//•`‰æˆÊ’u

	if (NULL == m_pFont) {
		// https://msdn.microsoft.com/ja-jp/library/bb172773(v=vs.85).aspx
		HRESULT hr = D3DXCreateFont(
			lpD3DDev, 
			32,					// Height
			0,					// Width
			FW_HEAVY,			// Weight
			1,					// MipLevels
			false,				// Italic
			SHIFTJIS_CHARSET,	// 
			OUT_TT_ONLY_PRECIS, 
			ANTIALIASED_QUALITY, 
			FF_DONTCARE, 
			_T("‚l‚r ƒSƒVƒbƒN"), 
			&m_pFont);
		//if FAILED(hr){return(E_FAIL);}
	}
	else {
		this->m_pFont->DrawText(
			NULL, 
			_T("DirectX9‚Å•`‰æ’†BDirectX9DrawerScene2"), 
			-1, 
			&rect, 
			DT_LEFT | DT_NOCLIP, 
			D3DCOLOR_ARGB(255, 64, 64, 64));
	}

	lpD3DDev->EndScene();
	lpD3DDev->Present( NULL, NULL, NULL, NULL );
}