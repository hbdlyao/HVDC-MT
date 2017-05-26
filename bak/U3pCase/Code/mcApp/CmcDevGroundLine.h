#pragma once

#include "CmcDevBranch.h"

/**
 * 主回路 接地极线
 */
class CmcDevGroundLine : public CmcDevBranch
{
protected:
	double ZrMax;
	double ZrMin;

public:
	double GetY(int RLevel);

	double GetZrMax();
	double GetZrMin();

	void SetZrMax(double newVal);
	void SetZrMin(double newVal);
};

