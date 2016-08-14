#pragma once
#include <windows.h>
#include <gdiplus.h>

namespace ytyaru {
namespace Framework {
namespace Graphics {
namespace Drawer {
class IGdiPlusDrawer
{
public:
	virtual void Draw(Gdiplus::Graphics* g) = 0;
	virtual void Initialize() = 0;
	virtual void Finalize() = 0;
};
}
}
}
}
