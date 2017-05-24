#pragma once


#include "C3pRwTwo.h"

class C3pRwXf2 : public C3pRwTwo
{

protected:
	void doLoad(CDevBase* vDevice) override;
	void doSave(CDevBase* vDevice) override;

};
