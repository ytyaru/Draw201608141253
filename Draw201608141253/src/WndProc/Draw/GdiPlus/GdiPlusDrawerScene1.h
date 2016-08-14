#pragma once
//#include <gdiplus.h>
#include "IGdiPlusDrawer.h"

class GdiPlusDrawerScene1 : public ytyaru::Framework::Graphics::Drawer::IGdiPlusDrawer
{
public:
	GdiPlusDrawerScene1(void);
	~GdiPlusDrawerScene1(void);
	virtual void Draw(Gdiplus::Graphics* g);
	virtual void Initialize();
	virtual void Finalize();
};

