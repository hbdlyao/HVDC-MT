#pragma once


#include "CmcDevTwo.h"

/**
* ����·������ѹ��
*/
class CmcDevXf2 : public CmcDevTwo
{

public:
	/**
	* ����
	*/
	double GetTkN();
	/**
	* ����������ѹ
	*/
	double GetUacN();
	/**
	* ��·�迹�ٷֱ�
	*/
	double GetUkp();
	/**
	* ����ѹ���ٷֱ�
	*/
	double GetUrp();
	/**
	* ���ཻ����ѹ
	*/
	//double GetUv();
	/**
	* �����������ѹ
	*/
	double GetUvMax();
	/**
	* ����������ѹ
	*/
	double GetUvN();
	/**
	* ������/�ضϽ����ֵ
	*/
	double GetAngleMax();
	/**
	* ������/�ضϽ���Сֵ
	*/
	double GetAngleMin();
	/**
	* ����ѹ�ο�ֵ
	*/
	double GetFixedURef();
	/**
	* �ֽ�ͷ��������
	*/
	int GetTapCtrlType();
	/**
	* �ֽ�ͷ���λ
	*/
	int GetTapMax();
	/**
	* �ֽ�ͷ��С��λ
	*/
	int GetTapMin();
	/**
	* �ֽ�ͷ���λ
	*/
	int GetTapN();
	/**
	* �ֽ�ͷ��������
	*/
	double GetTapSetup();
	/**
	* ������/�ضϽ����ֵ
	*/
	void SetAngleMax(double newVal);
	/**
	* ������/�ضϽ���Сֵ
	*/
	void SetAngleMin(double newVal);
	/**
	* ����ѹ�ο�ֵ
	*/
	void SetFixedURef(double newVal);
	/**
	* �ֽ�ͷ��������
	*/
	void SetTapCtrlType(int newVal);
	/**
	* �ֽ�ͷ���λ
	*/
	void SetTapMax(int newVal);
	/**
	* �ֽ�ͷ��С��λ
	*/
	void SetTapMin(int newVal);
	/**
	* �ֽ�ͷ���λ
	*/
	void SetTapN(int newVal);
	/**
	* �ֽ�ͷ��������
	*/
	void SetTapSetup(double newVal);
	/**
	* ����
	*/
	void SetTkN(double newVal);
	/**
	* ����������ѹ
	*/
	void SetUacN(double newVal);
	/**
	* ��·�迹�ٷֱ�
	*/
	void SetUkp(double newVal);
	/**
	* ����ѹ���ٷֱ�
	*/
	void SetUrp(double newVal);
	/**
	* ���ཻ����ѹ
	*/
	//void SetUv(double newVal);
	/**
	* �����������ѹ
	*/
	void SetUvMax(double newVal);
	/**
	* ����������ѹ
	*/
	void SetUvN(double newVal);

	int GetFixedUType();
	void SetFixedUType(int newValue);

protected:
	int FixedUType;

	/**
	* ������/�ضϽ����ֵ
	*/
	double AngleMax;
	/**
	* ������/�ضϽ���Сֵ
	*/
	double AngleMin;
	/**
	* ����ѹ�ο�ֵ
	*/
	double FixedURef;
	/**
	* �ֽ�ͷ��������
	*/
	int TapCtrlType;
	/**
	* �ֽ�ͷ���λ
	*/
	int TapMax;
	/**
	* �ֽ�ͷ��С��λ
	*/
	int TapMin;
	/**
	* �ֽ�ͷ���λ
	*/
	int TapN;
	/**
	* �ֽ�ͷ��������
	*/
	double TapSetup;
	/**
	* ����
	*/
	double TkN;
	/**
	* ����������ѹ
	*/
	double UacN;
	/**
	* ��·�迹�ٷֱ�
	*/
	double Ukp;
	/**
	* ����ѹ���ٷֱ�
	*/
	double Urp;
	/**
	* �����������ѹ
	*/
	double UvMax;
	/**
	* ����������ѹ
	*/
	double UvN;

};
