#pragma once

#include "C3pRwOne.h"

class C3pRwAcSys : public C3pRwOne
{

public:
	void OnLoad() override;
	void OnSave() override;

protected:
	void doLoad(CDevBase* vDevice) override;
	void doSave(CDevBase* vDevice) override;

	void doLoad_hData();
	void doSave_hData();

	void doLoad_hData(C3pDevAcSys* vDev);
	void doSave_hData(C3pDevAcSys* vDev);

};
