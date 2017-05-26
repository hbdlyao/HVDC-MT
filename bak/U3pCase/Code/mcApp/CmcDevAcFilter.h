#pragma once


#include "CmcDevShunt.h"

/**
 * ����· �����˲���
 */
class CmcDevAcFilter : public CmcDevShunt
{

public:
	/**
	 * ������ѹ
	 */
	double GetQac();
	/**
	 * �˲����޹�
	 */
	double GetQacf();
	/**
	 * �˲�����޹�
	 */
	double GetQacfN();
	/**
	 * �������ѹ
	 */
	double GetQacN();
	/**
	 * ������ѹ
	 */
	void SetQac(double newVal);
	/**
	 * �˲����޹�
	 */
	void SetQacf(double newVal);
	/**
	 * �˲�����޹�
	 */
	void SetQacfN(double newVal);
	/**
	 * �������ѹ
	 */
	void SetQacN(double newVal);
	double GetUac();
	void SetUac(double newVal);
	double GetUacN();
	void SetUacN(double newVal);

protected:
	/**
	 * ���������޹�
	 */
	double Qac;
	/**
	 * �˲����޹�
	 */
	double Qacf;
	/**
	 * �˲�����޹�
	 */
	double QacfN;
	/**
	 * ����������޹�
	 */
	double QacN;
	/**
	 * ���ཻ����ѹ
	 */
	double Uac;
	/**
	 * ����������ѹ
	 */
	double UacN;

};

