///////////////////////////////////////////////////////////
//  CmcHvdcGrid.h
//  Implementation of the Class CmcHvdcGrid
//  Created on:      21-5ÔÂ-2017 0:51:09
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_2E6C5B36_5C59_4483_AB40_C1D34BA592F1__INCLUDED_)
#define EA_2E6C5B36_5C59_4483_AB40_C1D34BA592F1__INCLUDED_

#include "CPowerGrid.h"

class CmcHvdcGrid : public CPowerGrid
{
public:
	string TypeToName(int vType) override;
	void Init() override;
public:
	void NewGrid(StrVector vStaNames) override;

protected:
	CDevTBL * doNewDevTBL(int vType) override;
	
	void NewAcFilterTBL(string vStaName);
	void NewAcSysTBL(string vStaName);
	void NewConvertorTBL(string vStaName);
	void NewXf2TBL(string vStaName);
	
	//´Þ¿µÉú20170528-NewGrid
	void NewGroundLineTBL(string vStaName);
	void NewGroundTBL(string vStaName);

};
#endif // !defined(EA_2E6C5B36_5C59_4483_AB40_C1D34BA592F1__INCLUDED_)
