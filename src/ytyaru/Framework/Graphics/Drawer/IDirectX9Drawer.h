#pragma once
#include <windows.h>
#include <d3d9.h>

namespace ytyaru {
namespace Framework {
namespace Graphics {
namespace Drawer {
class IDirectX9Drawer
{
public:
	virtual void Draw(const LPDIRECT3DDEVICE9 lpD3DDev) = 0;
	virtual void Initialize() = 0;
	virtual void Finalize() = 0;
};
}
}
}
}
