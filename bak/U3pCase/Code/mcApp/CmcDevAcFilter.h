#pragma once


#include "CmcDevShunt.h"

/**
 * 主回路 交流滤波器
 */
class CmcDevAcFilter : public CmcDevShunt
{

public:
	/**
	 * 交流电压
	 */
	double GetQac();
	/**
	 * 滤波器无功
	 */
	double GetQacf();
	/**
	 * 滤波器额定无功
	 */
	double GetQacfN();
	/**
	 * 额定交流电压
	 */
	double GetQacN();
	/**
	 * 交流电压
	 */
	void SetQac(double newVal);
	/**
	 * 滤波器无功
	 */
	void SetQacf(double newVal);
	/**
	 * 滤波器额定无功
	 */
	void SetQacfN(double newVal);
	/**
	 * 额定交流电压
	 */
	void SetQacN(double newVal);
	double GetUac();
	void SetUac(double newVal);
	double GetUacN();
	void SetUacN(double newVal);

protected:
	/**
	 * 交流电网无功
	 */
	double Qac;
	/**
	 * 滤波器无功
	 */
	double Qacf;
	/**
	 * 滤波器额定无功
	 */
	double QacfN;
	/**
	 * 交流电网额定无功
	 */
	double QacN;
	/**
	 * 网侧交流电压
	 */
	double Uac;
	/**
	 * 网侧额定交流电压
	 */
	double UacN;

};

