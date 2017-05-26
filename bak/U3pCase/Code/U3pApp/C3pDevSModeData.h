#pragma once

#include "C3pDevBase.h"

#include "C3pDefs.h"

class C3pDevSModeData : public C3pDevBase
{
public:
	~C3pDevSModeData();

	void Init() override;
	void Init(int vStaDim, int vCaseDim, int vPdPreDim);

	virtual void Prepare3pData(int vDType, int vLoopTimes);

	struct_U3pStaData * hData;

	p3pSModeDataMap pDataMap;

protected:	

	int nStaDim;
	int nCaseDim;
	int nPdPreDim;

	int DType;

	double kdU;

	double kdI;

};
