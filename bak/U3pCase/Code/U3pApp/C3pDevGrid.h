#pragma once

#include "CPowerGrid.h"

class C3pDevGrid : public CPowerGrid
{

public:
	void Init() override;
	string TypeToName(int vType) override;

	void Prepare3pData(int vDType, int vLoopTimes);

	void NewGrid(StrVector vStaNames, int vValvePole);
	void NewConvetor(string vStaName, int vValveNum);
	void NewXf2(string vStaName, int vValveNum);
	void NewAcSys(string vStaName, int vValveNum);
	void NewSModeData(string vStaName, int vValveNum);
protected:
	CDevTBL * doNewDevTBL(int vType) override;

};
