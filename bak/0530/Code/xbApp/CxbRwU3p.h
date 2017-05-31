#pragma once
#include "CxbRwTwo.h"
#include "CxbDevU3p.h"

class CxbRwU3p : public CxbRwTwo
{
public:
	void OnLoad()override;
	void OnSave()override;

protected:
	void doLoad(CDevBase * vDevice) override;
	void doSave(CDevBase * vDevice) override;

	void doLoad_hData();
	void doSave_hData();

	void doLoad_hCase();

	void doLoad_hCase(CxbDevU3p * vDev);


	void doLoad_hData(CxbU3pData* vData);

	void doSave_hData(CxbDevU3p * vDev);

};
