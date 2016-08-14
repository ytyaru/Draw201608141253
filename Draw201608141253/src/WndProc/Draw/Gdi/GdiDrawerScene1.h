#pragma once
#include "IGdiDrawer.h"

class GdiDrawerScene1 : public ytyaru::Framework::Graphics::Drawer::IGdiDrawer
{
public:
	GdiDrawerScene1(void);
	~GdiDrawerScene1(void);
	virtual void Draw(const HDC hdc);
	virtual void Initialize();
	virtual void Finalize();
};

