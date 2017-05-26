#pragma once

#include "C3pCalTwo.h"

class C3pCalXf2 : public C3pCalTwo
{
	void Prepare();

	virtual void Sort3p(ValveMap& vValMap);

	void Update3pData(int vLoop) override;
};