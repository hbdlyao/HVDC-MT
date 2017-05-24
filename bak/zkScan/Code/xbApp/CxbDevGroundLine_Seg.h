///////////////////////////////////////////////////////////
//  CxbDevGroundLine_Seg.h
//  Implementation of the Class CxbDevGroundLine
//  Created on:      05-4月-2017 16:58:43
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_8113989A_E55C_4a46_A27D_69B6F2ACC9B6__INCLUDED_)
#define EA_8113989A_E55C_4a46_A27D_69B6F2ACC9B6__INCLUDED_

#include "CxbDevTwo.h"
#include "CxbDefs.h"
#include "CLineModel.h"

/**
 * 接地极线
 */
class CxbDevGroundLine_Seg : public CxbDevTwo
{	
public:
	CLineModel pLineParam;

public:
	~CxbDevGroundLine_Seg();

	void Init() override;
	void Clear() override;


	
public:
	string BusName(int vIndex) override;
public:
	virtual void Prepare_hRLC();
	void Prepare_hRLC(double vFreStart, double vFreStep, int vFreDim) override;

public:
	CMatrix GetYMatrix(int hOrder);
	//
	double GetYs11re(int vhOrder);
	double GetYs11im(int vhOrder);
	double GetYs12re(int vhOrder);
	double GetYs12im(int vhOrder);
	double GetYm11re(int vhOrder);
	double GetYm11im(int vhOrder);
	double GetYm12re(int vhOrder);
	double GetYm12im(int vhOrder);

	void SetYs11re(int vhOrder, double vY);
	void SetYs11im(int vhOrder, double vY);
	void SetYs12re(int vhOrder, double vY);
	void SetYs12im(int vhOrder, double vY);
	void SetYm11re(int vhOrder, double vY);
	void SetYm11im(int vhOrder, double vY);
	void SetYm12re(int vhOrder, double vY);
	void SetYm12im(int vhOrder, double vY);

};


#endif // !defined(EA_8113989A_E55C_4a46_A27D_69B6F2ACC9B6__INCLUDED_)
