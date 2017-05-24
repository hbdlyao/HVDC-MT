#pragma once

#include "C3pRwTwo.h"

class C3pRwConvertor : public C3pRwTwo
{

protected:
	void doLoad(CDevBase* vDevice) override;
	void doSave(CDevBase* vDevice) override;

};
