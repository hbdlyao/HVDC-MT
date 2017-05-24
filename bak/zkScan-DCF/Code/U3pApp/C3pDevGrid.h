#pragma once

#include "CPowerGrid.h"

class C3pDevGrid : public CPowerGrid
{

public:
	void Init() override;
	string TypeToName(int vType) override;
protected:
	CDevTBL * doNewDevTBL(int vType) override;

};
