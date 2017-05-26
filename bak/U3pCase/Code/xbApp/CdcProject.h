///////////////////////////////////////////////////////////
//  CdcProject.h
//  Implementation of the Class CDcProject
//  Created on:      23-3月-2017 20:17:20
//  Original author: Administrator
///////////////////////////////////////////////////////////

#if !defined(EA_63D056D3_1C4F_45ff_87CB_6CFC1319D914__INCLUDED_)
#define EA_63D056D3_1C4F_45ff_87CB_6CFC1319D914__INCLUDED_

class CDcProject
{

public:
	CDcProject();
	CDcProject(CDcProject theCDcProject);
	/**
	 * 直流工程端数
	 */
	int ConvertorCount();
	/**
	 * 交流系统频率
	 */
	int Frequency();
	/**
	 * 接地类型
	 */
	int GroudType();
	int ID();
	/**
	 * 直流功率水平
	 */
	int PdLevel();
	/**
	 * 工程类型（单极/双极）
	 */
	int PoleType();
	/**
	 * 极线对大地/中性线电压
	 */
	int PoleVoltage();
	/**
	 * 直流工程名称
	 */
	int ProjectName();
	/**
	 * 直流工程类型
	 */
	int ProjectType();
	/**
	 * 分接头控制类型
	 */
	int TapCtrlType();
	/**
	 * 直流电压
	 */
	int Ud();
	/**
	 * 直流电压水平
	 */
	int UdcLevel();
	/**
	 * 额定直流电压
	 */
	int UdN();
	/**
	 * 每极12脉动换流组数
	 */
	int Valor12Count();
	/**
	 * 电阻类型（高阻/低阻）
	 */
	int ZrType();

private:
	~CDcProject();

};
#endif // !defined(EA_63D056D3_1C4F_45ff_87CB_6CFC1319D914__INCLUDED_)
