#pragma once
#include "CDevTBL.h"

/**
 * xb直流设备表
 */
class CxbDevTBL : public CDevTBL
{
protected:
	virtual CDevBase * doNewDevice(int vDevType);

public:
	virtual string TypeToName(int vDevType);
	static CDevBase * xbNewDevice(int vDevType);

public:
	void Prepare_hRLC();
	void Prepare_hRLC(double vFreStart, double vFreStep, int vFreDim);


};
