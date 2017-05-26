///////////////////////////////////////////////////////////
//  CmcDevAcSys.h
//  Implementation of the Class CmcDevAcSys
//  Created on:      22-4月-2017 14:51:16
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_7FD34A0B_2B8F_48a2_859E_3CC74A935838__INCLUDED_)
#define EA_7FD34A0B_2B8F_48a2_859E_3CC74A935838__INCLUDED_

#include "CmcDevOne.h"

/**
 * 主回路 交流系统
 */
class CmcDevAcSys : public CmcDevOne
{

public:
	double GetQfMaxN();
	double GetQfMinN();
	/**
	 * 交流系统吸收最大无功
	 */
	double GetQinMax();
	/**
	 * 交流系统发出最大无功
	 */
	double GetQoutMax();
	/**
	 * 交流电压极小值
	 */
	double GetUacExMin();
	/**
	 * 交流电压最大值
	 */
	double GetUacMax();
	/**
	 * 交流电压最小值
	 */
	double GetUacMin();
	/**
	 * 交流侧额定电压
	 */
	double GetUacN();
	void SetQfMaxN(double newVal);
	void SetQfMinN(double newVal);
	/**
	 * 交流系统吸收最大无功
	 */
	void SetQinMax(double newVal);
	/**
	 * 交流系统发出最大无功
	 */
	void SetQoutMax(double newVal);
	/**
	 * 交流电压极小值
	 */
	void SetUacExMin(double newVal);
	/**
	 * 交流电压最大值
	 */
	void SetUacMax(double newVal);
	/**
	 * 交流电压最小值
	 */
	void SetUacMin(double newVal);
	/**
	 * 交流侧额定电压
	 */
	void SetUacN(double newVal);

protected:
	double QfMinN;
	double QfMaxN;
	/**
	 * 交流系统吸收最大无功
	 */
	double QinMax;
	/**
	 * 交流系统发出最大无功
	 */
	double QoutMax;
	/**
	 * 交流电压极小值
	 */
	double UacExMin;
	/**
	 * 交流电压最大值
	 */
	double UacMax;
	/**
	 * 交流电压最小值
	 */
	double UacMin;
	/**
	 * 交流侧额定线电压
	 */
	double UacN;

};
#endif // !defined(EA_7FD34A0B_2B8F_48a2_859E_3CC74A935838__INCLUDED_)
