///////////////////////////////////////////////////////////
//  CmcDevAcSys.h
//  Implementation of the Class CmcDevAcSys
//  Created on:      22-4��-2017 14:51:16
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_7FD34A0B_2B8F_48a2_859E_3CC74A935838__INCLUDED_)
#define EA_7FD34A0B_2B8F_48a2_859E_3CC74A935838__INCLUDED_

#include "CmcDevOne.h"

/**
 * ����· ����ϵͳ
 */
class CmcDevAcSys : public CmcDevOne
{

public:
	double GetQfMaxN();
	double GetQfMinN();
	/**
	 * ����ϵͳ��������޹�
	 */
	double GetQinMax();
	/**
	 * ����ϵͳ��������޹�
	 */
	double GetQoutMax();
	/**
	 * ������ѹ��Сֵ
	 */
	double GetUacExMin();
	/**
	 * ������ѹ���ֵ
	 */
	double GetUacMax();
	/**
	 * ������ѹ��Сֵ
	 */
	double GetUacMin();
	/**
	 * ��������ѹ
	 */
	double GetUacN();
	void SetQfMaxN(double newVal);
	void SetQfMinN(double newVal);
	/**
	 * ����ϵͳ��������޹�
	 */
	void SetQinMax(double newVal);
	/**
	 * ����ϵͳ��������޹�
	 */
	void SetQoutMax(double newVal);
	/**
	 * ������ѹ��Сֵ
	 */
	void SetUacExMin(double newVal);
	/**
	 * ������ѹ���ֵ
	 */
	void SetUacMax(double newVal);
	/**
	 * ������ѹ��Сֵ
	 */
	void SetUacMin(double newVal);
	/**
	 * ��������ѹ
	 */
	void SetUacN(double newVal);

protected:
	double QfMinN;
	double QfMaxN;
	/**
	 * ����ϵͳ��������޹�
	 */
	double QinMax;
	/**
	 * ����ϵͳ��������޹�
	 */
	double QoutMax;
	/**
	 * ������ѹ��Сֵ
	 */
	double UacExMin;
	/**
	 * ������ѹ���ֵ
	 */
	double UacMax;
	/**
	 * ������ѹ��Сֵ
	 */
	double UacMin;
	/**
	 * �������ߵ�ѹ
	 */
	double UacN;

};
#endif // !defined(EA_7FD34A0B_2B8F_48a2_859E_3CC74A935838__INCLUDED_)
