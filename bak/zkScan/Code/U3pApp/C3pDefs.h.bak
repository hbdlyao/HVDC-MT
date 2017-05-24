#pragma once

#include "CMyDefs.h"
#include "CHvdcDefs.h"

class C3pDefs
{
public:
	static const int	AcSys = 11;
	static const int	ACF = 12;
	static const int	Xf2 = 13;
	static const int 	Convertor = 14;

	static const int	Pos = 01;
	static const int	Neg = 02;

	static const int	DFixed = 21;	//手动输入
	static const int	DAutoDis = 22;	//程序分配
	static const int	DRandom = 23;	//概率分布
};

struct struct_AcSysXb
{
	int hIndex;
	double hUrms;
	double hAngle;

};

struct struct_3p_hData
{
public:
	string CalName;
	string CaseId;
	string StationName;//站名

	//int WorkState;

	double PdPer;//功率水平


	double Uac;//交流电压
	double Uv;//阀侧电压
	double UvN;//阀侧电压额定值
	//double Udio;//理想空载直流电压
	//double Udio_N;//理想空载直流电压额定值
	//double Ud;//直流端口电压
	//double UdL;//直流端口对地电压
	double Id;//直流电流
	//double Pd;//直流功率
	//double Pconv;//换流器有功
	//double Qconv;//换流器无功
	int TC;//变压器分接头档位
	double alphaOrgamma;//触发角/关断角
	double miu;//换相角
	//double Qf_max;//滤波器提供的最大无功
	//double Qf_min;//滤波器提供的最小无功

	double Nnom;//变压器额定变比
};