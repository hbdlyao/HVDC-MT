#pragma once

#include "C3pCalTwo.h"

class C3pCalXf2 : public C3pCalTwo
{
	void Prepare();

	void Update3pData(int vLoop) override;
};