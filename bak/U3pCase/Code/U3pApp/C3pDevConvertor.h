#pragma once

#include "C3pDevTwo.h"

class C3pDevConvertor : public C3pDevTwo
{
protected:
	/**
	* �����������ű۴����ǻ�Ϩ����ƫ��
	*/
	double dAngle[6];
	/**
	* �����ǻ�Ϩ���Ǳ�׼��
	*/
	double Std_Angle;
	/**
	* ƫ��������ģʽ�����ǻ�Ϩ����ƫ��
	*/
	double Dis_dAngle;
	/**
	* ���������ͣ�������䣩
	*/
	int StationType;
	/**
	* ���߷�ʽ��YY YD��
	*/
	int ConMode;
	/**
	* �Ƕ�ƫ������
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
