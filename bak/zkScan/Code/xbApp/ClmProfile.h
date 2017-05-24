#pragma once

#include "CxbHvdcGrid.h"

#include "ClmResult.h"
#include "ClmOrder.h"

#include "CPowerProfile.h"

#include "CLineModel.h"

class ClmProfile : public CPowerProfile
{
public:
	ClmOrder * pOrder;

	CLineModel pLineModel;

public:
	void InitOrder(ClmOrder * vOrder);

public:
	int hOrder=1;
	double xbFreq=50;
	
public:
	double Omega();

};

