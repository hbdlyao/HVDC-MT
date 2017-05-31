#pragma once


#include "C3pRwTwo.h"

class C3pRwVsrc : public C3pRwTwo
{

public:
	void OnLoad() override;
	void OnSave() override;

protected:
	void doLoad(CDevBase* vDevice) override;
	void doSave(CDevBase* vDevice) override;

	void doLoad_hData();
	void doSave_hData();

	void doLoad_hData(C3pDevVSrc* vDev);
	void doSave_hData(C3pDevVSrc* vDev);

};
