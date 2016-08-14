#pragma once
#include <windows.h>

namespace ytyaru {
namespace Framework {
namespace Graphics {
namespace Drawer {
class IGdiDrawer
{
public:
	virtual void Draw(const HDC hdc) = 0;
	virtual void Initialize() = 0;
	virtual void Finalize() = 0;
};
}
}
}
}
