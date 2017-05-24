#pragma once

#include "C3pDevBase.h"

#include "C3pDefs.h"

class C3pDevhData : public C3pDevBase
{
public:
	~C3pDevhData();

	void Init() override;
	void Init(int vStaDim, int vCaseDim, int vPdPreDim);

protected:	
	int nStaDim;
	int nCaseDim;
	int nPdPreDim;

	struct_3p_hData * hData;

};
