///////////////////////////////////////////////////////////
//  CxbDev3pVSrc.h
//  Implementation of the Class CxbDev3pVSrc
//  Created on:      05-4月-2017 18:01:58
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_CD558F52_2A30_4c74_926D_B8EF9068AC59__INCLUDED_)
#define EA_CD558F52_2A30_4c74_926D_B8EF9068AC59__INCLUDED_

#include "CxbDevTwo.h"
#include "CxbDefs.h"
#include "CxbU3PData.h"

/**
* 三脉动电压源
*/
class CxbDev3pVSrc : public CxbDevTwo
{

protected:
	//数据DataMap[ConMethod+PowLevel]
	pxbU3PData_Map DataMap;

	//PowPreMap[Condition]=pxbU3PData_Map, pxbU3PData_Map[PowPre]=CxbU3PData
	//pxbU3PPowPre_Map PowPreMap;

	//
	struct_xbU3PData  pU3pData;

public:
	~CxbDev3pVSrc();

	void InitData() override;
	void Clear() override;

public:
	virtual void Prepare_hRLC();
	virtual void Prepare_hRLC(double vFreStart, double vFreStep, int vFreDim);

public:

	//马骏鹏
	//virtual void PrepareData(string vCondition, string vPowPre);
	virtual void PrepareData(string vCondition);

	double hUre(int vhOrder);
	double hUim(int vhOrder);

	double hIre(int vhOrder);
	double hIim(int vhOrder);

	double hYg(int vhOrder);
	double hYb(int vhOrder);

	double Get_hUrms(int vhOrder);
	void   Set_hUrms(int vhOrder,double vX);

	double Get_hAngle(int vhOrder);
	void   Set_hAngle(int vhOrder, double vX);

	double Get_hYb(int vhOrder);
	void   Set_hYb(int vhOrder, double vX);

};

#endif // !defined(EA_CD558F52_2A30_4c74_926D_B8EF9068AC59__INCLUDED_)
