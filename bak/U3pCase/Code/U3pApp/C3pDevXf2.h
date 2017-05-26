#pragma once

#include "C3pDevTwo.h"

class C3pDevXf2 : public C3pDevTwo
{

protected:
	/**
	* ��ѹ�������
	*/
	double SN;
	/**
	* ����������ѹ
	*/
	double UacN;
	/**
	* ����������ѹ
	*/
	double UvN;
	/**
	* ��·�迹�ٷֱ�
	*/
	double Ukp;
	/**
	* ����ѹ���ٷֱ�
	*/
	double Urp;
	/**
	* ����
	*/
	double TkN;
	/**
	* ����ƫ��
	*/
	double dTkN;
	/**
	* ��ѹ�����򷧲��ͺ�����Ƕ�
	*/
	double PhaseShift;
	/**
	* ��ѹ����Ч��е�б�׼��
	*/
	double Std_Lt;
	/**
	* ƫ��������ģʽ��ѹ����Ч���ƫ��
	*/
	double Dis_dLt;
	/**
	* ��ѹ����Ч���A��ƫ��
	*/
	double dLtA;
	/**
	* ��ѹ����Ч���B��ƫ��
	*/
	double dLtB;
	/**
	* ��ѹ����Ч���B��ƫ��
	*/
	double dLtC;

	//double LtNd//��ƫ��ĵ�ֵ�翹
	/**
	* ��ѹ����Ч���A��ƫ��
	*/
	double * dLtAVec;
	/**
	* ��ѹ����Ч���B��ƫ��
	*/
	double * dLtBVec;
	/**
	* ��ѹ����Ч���B��ƫ��
	*/
	double * dLtCVec;
	/**
	* ���������ͣ�������䣩
	*/
	int StationType;
	/**
	* ���߷�ʽ��YY YD��
	*/
	int ConMode;

	int DType;
public:
	double GetdTkN();
	void SetdTkN(double newVal);
	double GetStd_Lt();
	void SetStd_Lt(double newVal);
	double GetdLtA();
	void SetdLtA(double newVal);
	double GetdLtB();
	void SetdLtB(double newVal);
	double GetdLtC();
	void SetdLtC(double newVal);
	double GetTkN();
	void SetTkN(double newVal);
	double GetUacN();
	void SetUacN(double newVal);
	double GetUkp();
	void SetUkp(double newVal);
	double GetUrp();
	void SetUrp(double newVal);
	double GetUvN();
	void SetUvN(double newVal);
	double GetSN();
	void SetSN(double newVal);
	double GetPhaseShift();
	void SetPhaseShift(double newVal);
	double GetDis_dLt();
	void SetDis_dLt(double newVal);

public:
	virtual void Prepare3pData(int vDType, int vLoopTimes);

private:
	void doDFixed();

	void doDAutoDis();

	void doDRandom(int vLoopTimes);
};
