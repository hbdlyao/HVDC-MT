#pragma once

#include "C3pDefs.h"
#include "C3pDevOne.h"

class C3pDevAcSys : public C3pDevOne
{
private:
	int hCount;
	/**
	 * ����ϵͳ����
	 */
	double Rs;
	/**
	 * ����ϵͳ���
	 */
	double Ls;
	/**
	* �����˲���
	*/
	double Lf;

	double Leq;
public:

	~C3pDevAcSys();

	int GethCount();
	void SethCount(int newVal);
	/**
	 * ����ϵͳ����
	 */
	double GetRs();
	/**
	 * ����ϵͳ����
	 */
	void SetRs(double newVal);
	/**
	 * ����ϵͳ���
	 */
	double GetLs();
	/**
	 * ����ϵͳ���
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
