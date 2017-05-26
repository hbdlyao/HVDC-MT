#pragma once

#include "C3pDevTwo.h"

class C3pDevConvertor : public C3pDevTwo
{
protected:
	/**
	* 六脉动发各桥臂触发角或熄弧角偏差
	*/
	double dAngle[6];
	/**
	* 触发角或熄弧角标准差
	*/
	double Std_Angle;
	/**
	* 偏差程序分配模式触发角或熄弧角偏差
	*/
	double Dis_dAngle;
	/**
	* 换流器类型（整流逆变）
	*/
	int StationType;
	/**
	* 结线方式（YY YD）
	*/
	int ConMode;
	/**
	* 角度偏差数组
	*/
	double * dAngleVec[6];

	int DType;
public:
	virtual void Prepare3pData(int vDType, int vLoopTimes);

	void doDFixed();

	void doDAutoDis();

	void doDRandom(int vLoopTimes);

	double GetdAngle(int i);
	void SetdAngle(int i, double newVal);

	double GetStd_Angle();
	void SetStd_Angle(double newVal);

	double GetDis_dAngle();
	void SetDis_dAngle(double newVal);

	int GetStationType();
	void SetStationType(int newVal);


};
