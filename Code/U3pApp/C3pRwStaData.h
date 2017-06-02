#pragma once

#include "C3pRw.h"

class C3pRwStaData : public C3pRw
{
protected:
	void doLoad(CDevBase* vDevice) override;
	void doSave(CDevBase* vDevice) override;

};
