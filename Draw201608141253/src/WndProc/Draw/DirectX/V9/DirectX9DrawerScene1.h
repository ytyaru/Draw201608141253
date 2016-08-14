#pragma once
#include "IDirectX9Drawer.h"
#include <d3d9.h>
#include <d3dx9.h>

class DirectX9DrawerScene1 : public ytyaru::Framework::Graphics::Drawer::IDirectX9Drawer
{
public:
	DirectX9DrawerScene1(void);
	~DirectX9DrawerScene1(void);
	virtual void Draw(const LPDIRECT3DDEVICE9 lpD3DDev);
	virtual void Initialize();
	virtual void Finalize();
private:
	LPD3DXFONT m_pFont;
};
