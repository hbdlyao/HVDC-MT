#pragma once

#include "CMatrix.h"
#include "CPowerMath.h"


#include "CxbHvdcGrid.h"
#include "CxbResult.h"
#include "CxbOrder.h"

#include "CPowerProfile.h"


class CxbProfile : public CPowerProfile
{
public:
	CxbOrder * pxbvOrder;

public:
	//
	~CxbProfile();

	void Init()  override;
	virtual void InitOrder(CxbOrder * vOrder);
	
	void Clear() override;

protected:
	virtual void doInit();
	virtual void doClear();
	
public:
	virtual void InitMatrix();

	virtual void ReSetData();

protected:
	virtual void doInitMatrix();
	virtual void doInitData();

public:
	int Flag_DCFOver;

	/**
	 * 计算工况指令
	 */
	CxbOrder* pxbOrder;

	/**
	 * 谐波次数
	 */
	int hOrder=1;

	/**
	 * 系统频率
	 */
	double xbFreq=50;

	//马骏鹏
	CMatrix * Ymatrix;
	CMatrix * Ivect;
	CMatrix * Uvect;
	
public:
	int StaDim();
	virtual double Omega();

	virtual void Solve();

	void UpdateYLine(int * pNode, CMatrix vY);

	virtual void UpdateI0(int iNode, double vIr, double vIm);

	virtual void UpdateI(int iNode, int jNode, double vIr, double vIm);


};

