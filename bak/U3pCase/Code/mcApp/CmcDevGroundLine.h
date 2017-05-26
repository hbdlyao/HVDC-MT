#pragma once

#include "CmcDevBranch.h"

/**
 * ����· �ӵؼ���
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

