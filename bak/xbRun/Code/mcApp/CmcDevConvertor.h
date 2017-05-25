///////////////////////////////////////////////////////////
//  CmcDevConvertor.h
//  Implementation of the Class CmcDevConvertor
//  Created on:      22-4月-2017 14:50:22
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_3944D79B_EBB3_4e20_A648_D87046C2B582__INCLUDED_)
#define EA_3944D79B_EBB3_4e20_A648_D87046C2B582__INCLUDED_

#include "CmcDevTwo.h"

/**
 * 换流器
 */
class CmcDevConvertor : public CmcDevTwo
{

public:
	/**
	 * 额定触发角/关断角
	 */
	double GetAlpha_gamaN();
	/**
	 * 触发角/关断角最大值
	 */
	double GetAngleMax();
	/**
	 * 触发角/关断角最小值
	 */
	double GetAngleMin();
	/**
	 * 额定直流功率
	 */
	double GetPdN();
	/**
	 * 额定直流电压
	 */
	double GetUdN();
	/**
	 * 6脉动正向导通压降
	 */
	double GetUT();
	/**
	 * 每极12脉动换流组数
	 */
	int GetValvor12Count();
	double GetUdioN();
	/**
	 * 阀侧额定电压
	 */
	double GetUvN();
	/**
	 * 直流电流,，计算得出
	 */
	double GetIdN();
	/**
	 * 换流器类型（整流逆变）
	 */
	int GetStationType();
	/**
	 * 换流器控制类型（定电流，定功率，定电压）
	 */
	int GetStationCtrlType();
	int GetStationCtrlTypeN();
	int GetIsGround();
	double GetAngleRef();
	/**
	 * 测量站
	 */
	string GetMeasureStation();
	double GetPconvN();
	double GetQconvN();
	double GetmiuN();
	/**
	 * 额定触发角/关断角
	 */
	void SetAlpha_gamaN(double newVal);
	/**
	 * 触发角/关断角最大值
	 */
	void SetAngleMax(double newVal);
	/**
	 * 触发角/关断角最小值
	 */
	void SetAngleMin(double newVal);
	/**
	 * 额定直流功率
	 */
	void SetPdN(double newVal);
	/**
	 * 额定直流电压
	 */
	void SetUdN(double newVal);
	/**
	 * 6脉动正向导通压降
	 */
	void SetUT(double newVal);
	/**
	 * 每极12脉动换流组数
	 */
	void SetValvor12Count(int newVal);
	void SetUdioN(double newVal);
	/**
	 * 阀侧额定电压
	 */
	void SetUvN(double newVal);
	/**
	 * 直流电流,，计算得出
	 */
	void SetIdN(double newVal);
	/**
	 * 换流器类型（整流逆变）
	 */
	void SetStationType(int newVal);
	/**
	 * 换流器控制类型（定电流，定功率，定电压）
	 */
	void SetStationCtrlType(int newVal);
	void SetStationCtrlTypeN(int newVal);
	void SetIsGround(int newVal);
	void SetAngleRef(double newVal);
	/**
	 * 测量站
	 */
	void SetMeasureStation(string newVal);
	void SetPconvN(double newVal);
	void SetQconvN(double newVal);
	void SetmiuN(double newVal);

protected:
	double PconvN;
	double QconvN;
	double miuN;
	/**
	 * 额定触发角/关断角
	 */
	double Alpha_gamaN;
	/**
	 * 触发角/关断角最大值
	 */
	double AngleMax;
	/**
	 * 触发角/关断角最小值
	 */
	double AngleMin;
	/**
	 * 额定直流功率
	 */
	double PdN;
	/**
	 * 额定直流电压
	 */
	double UdN;
	/**
	 * 6脉动正向导通压降
	 */
	double UT;
	/**
	 * 每极12脉动换流组数
	 */
	int Valvor12Count;
	double UdioN;
	/**
	 * 阀侧额定电压
	 */
	double UvN;
	/**
	 * 直流电流,，计算得出
	 */
	double IdN;
	/**
	 * 换流器类型（整流逆变）
	 */
	int StationType;
	/**
	 * 换流器控制类型（定电流，定功率，定电压）
	 */
	int StationCtrlType;
	int StationCtrlTypeN;
	int IsGround;
	double AngleRef;
	string MeasureStation;

};
#endif // !defined(EA_3944D79B_EBB3_4e20_A648_D87046C2B582__INCLUDED_)
