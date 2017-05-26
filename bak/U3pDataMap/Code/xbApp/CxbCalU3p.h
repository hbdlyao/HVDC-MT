#pragma once
#include "CxbCalTwoDot.h"

class CxbCalU3p : public CxbCalTwoDot
{

public:
	void Prepare();

	virtual void UpdateY();
	virtual void UpdateI();

	virtual void Update_zkY();
	virtual void Update_zkI();

};
