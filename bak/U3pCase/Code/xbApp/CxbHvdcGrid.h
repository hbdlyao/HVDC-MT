#pragma once

#include "CMyDefs.h"
#include "CPowerGrid.h"

class CxbHvdcGrid : public CPowerGrid
{

protected:
	CDevTBL * doNewDevTBL(int vType) override;

public:
	virtual void Init();
	virtual string TypeToName(int vType);
public:
	void Prepare_hRLC();
	void Prepare_hRLC(double vFreStart, double vFreStep, int vFreDim);
public:
	void NewGrid(StrVector vStaNames, int vValvePole);
	void NewVSrc3pTBL(string vStaName, int vValvePole);
	void NewXfCTBL(string vStaName, int vValvePole);
	void NewPbDKQTBL(string vStaName);
	void NewDCFTBL(string vStaName);
	void NewGroundTBL(string vStaName);
	void NewCoupleCTBL(string vStaName);
	void NewPulseCTBL(string vStaName);
	void NewTrapTBL(string vStaName);
	void NewMonitorTBL(string vStaName);
	void NewGroundLineTBL(string vStaName);


};
