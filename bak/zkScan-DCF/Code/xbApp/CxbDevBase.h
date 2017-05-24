#pragma once

#include "CDevBase.h"
#include "CxbDefs.h"

class CxbDevBase : public CDevBase
{
public:
	void Init() override;
	virtual void InitData() ;
protected:
	int FreqDim;
	virtual void doInitData(int vDim);

protected:	
	int PosOrNeg;

public:
	int GetPosOrNeg();
	void SetPosOrNeg(int newVal);
	virtual void Prepare_hRLC();
	virtual void Prepare_hRLC(double vFreStart, double vFreStep, int vFreDim);

	int hMax();
	double FreqRef();
	double Omega();
	virtual string BusName(int vIndex);
	
	struct_xbUI xbUI;
	struct_xbILine xbILine;

};
