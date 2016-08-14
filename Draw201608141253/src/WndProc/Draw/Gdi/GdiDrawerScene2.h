#pragma once
#include "IGdiDrawer.h"

class GdiDrawerScene2 : public ytyaru::Framework::Graphics::Drawer::IGdiDrawer
{
public:
	GdiDrawerScene2(void);
	~GdiDrawerScene2(void);
	virtual void Draw(const HDC hdc);
	virtual void Initialize();
	virtual void Finalize();
};

