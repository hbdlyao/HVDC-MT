#pragma once

#include "C3pRw.h"

#include "C3pCase.h"

class C3pRwStaData : public C3pRw
{

public:
	void OnLoad() override;
	void OnSave() override;

protected:
	string GetSQL_Load() override;

	void doLoad(CDevBase* vDevice) override;


	void doLoad_hData();
	void doSave_hData();
	void doLoad_hCase();

	void doLoad_hCase(C3pDevStaData* vDev);


	void doLoad_hData(C3pCase* vData);


};
