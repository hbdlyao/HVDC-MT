#pragma once

#include "CxbCalculate.h"
#include "CPowerSolves.h"
#include "CxbHvdcGrid.h"

#include "CDeviceBase.h"

class CxbSolves : public CPowerSolves
{
protected:
	int GroundType;

	CxbProfile* pxbProfile;
	
	CxbHvdcGrid * pxbHvdc;

public:
	virtual void Init(CPowerProfile* vProfile, CPowerGrid* vGrid);

public:

	virtual string TypeToName(int vType);

	virtual void NewSolves(int vGndType);
	virtual void Run();

protected:
	void doNewXbSolvers10();
	void doNewXbSolvers11();
	void doNewXbSolvers20();
	void doNewXbSolvers21();

	virtual void doNewItem(int vtblType) override;
	virtual void doNewItem(CDeviceTBL * vTBL)override;

	virtual void doNewCal(CDeviceBase * vDev, int vIndex)override;

	virtual void doNewCal_Tree(CDeviceBase* vDev, int vIndex)override;

protected:
	virtual void doPrepare();


	//
	void doSovle();
	//
	void doSolveU();
	void doUpdateI();
	void doUpdateY();



};
