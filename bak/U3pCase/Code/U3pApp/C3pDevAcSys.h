#pragma once

#include "C3pDefs.h"
#include "C3pDevOne.h"

class C3pDevAcSys : public C3pDevOne
{
private:
	int hCount;
	/**
	 * 交流系统电阻
	 */
	double Rs;
	/**
	 * 交流系统电感
	 */
	double Ls;
	/**
	* 交流滤波器
	*/
	double Lf;

	double Leq;
public:

	~C3pDevAcSys();

	int GethCount();
	void SethCount(int newVal);
	/**
	 * 交流系统电阻
	 */
	double GetRs();
	/**
	 * 交流系统电阻
	 */
	void SetRs(double newVal);
	/**
	 * 交流系统电感
	 */
	double GetLs();
	/**
	 * 交流系统电感
	 */
	void SetLs(double newVal);

	virtual void Prepare3pData(int vDType, int vLoopTimes);

protected:
	struct_AcSysXb * pXb;

public:
	int Get_hIndex(int vIndex);
	void Set_hIndex(int vIndex, int vValue);

	double Get_hUrms(int vIndex);
	void Set_hUrms(int vIndex, double vValue);

	double Get_hAngle(int vIndex);
	void Set_hAngle(int vIndex, double vValue);

};
