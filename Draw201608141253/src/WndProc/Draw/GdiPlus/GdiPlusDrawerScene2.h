#pragma once
//#include <gdiplus.h>
#include "IGdiPlusDrawer.h"

class GdiPlusDrawerScene2 : public ytyaru::Framework::Graphics::Drawer::IGdiPlusDrawer
{
public:
	GdiPlusDrawerScene2(void);
	~GdiPlusDrawerScene2(void);
	virtual void Draw(Gdiplus::Graphics* g);
	virtual void Initialize();
	virtual void Finalize();
};

