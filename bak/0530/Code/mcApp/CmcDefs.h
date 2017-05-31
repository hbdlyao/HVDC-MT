#pragma once

#include <string>
#include <map>
#include <vector>

#include "CMyDefs.h"
#include "CHvdcDefs.h"

using namespace std;

struct struct_mcStationData
{
public:
	//结果集中的数据
	string StationName = "";//站名


	//控制参数
	int TapCtrlType;
	int WorkState;

	int StaCtrlType;
	int iNodeID;
	int jNodeID;
	int RefStaIndex;

	int J_Index;


	double PdPer = 0;//功率水平
	double Uac;//交流电压
	double Uv;//阀侧电压
	double Udio;//理想空载直流电压
	double Ud;//直流端口电压
	double UdL;//直流端口对地电压
	double Id;//直流电流
	double Pd;//直流功率
	double Pconv;//换流器有功
	double Qconv;//换流器无功
	int TC;//变压器分接头档位
	double alphaOrgamma;//触发角/关断角
	double miu;//换相角
	double Qf_max;//滤波器提供的最大无功
	double Qf_min;//滤波器提供的最小无功

	//计算中要用到的参数：来自HVDC设备集
	int nT;//6脉动桥数
	int nPoleNum;//极数（双极或单极）
	double UT;//6脉动桥的压降
	double dr;//阻性换相压降
	double dx;//感性换相压降
	double deltaK;//变压器每档的调压百分比
	double QacInMax;//交流系统可吸收的最大无功
	double QacOutMax;//交流系统可发出的最大无功

	//计算中要用到的参数：来自HVDC设备集，限值
	double AngCtrl_Max;//分接头控制中换流器触发角/关断角的上限
	double AngCtrl_Min;//分接头控制中换流器触发角/关断角的下限
	int Tap_Max;//分接头最大档位
	int Tap_Min;//分接头最小档位
	double Ang_Min;//换流器触发角/关断角的最小值
	double Uv_Max;//阀侧电压允许的最大值
	//计算中要用到的参数：计算产生
	double Nnom;//变压器额定变比

};

struct struct_mcResultData
{
public:
	string CalName = "";
	string CaseID = "";
	string StationName = "";//站名

	double PdPer = 0;//功率水平
	double Uac;//交流电压
	double Uv;//阀侧电压
	double Udio;//理想空载直流电压
	double Ud;//直流端口电压
	double UdL;//直流端口对地电压
	double Id;//直流电流
	double Pd;//直流功率
	double Pconv;//换流器有功
	double Qconv;//换流器无功

	int TC;//变压器分接头档位
	double alphaOrgamma;//触发角/关断角
	double miu;//换相角
	double Qf_max;//滤波器提供的最大无功
	double Qf_min;//滤波器提供的最小无功

	double Udio_N;//理想空载直流电压额定值
	double Uv_N;//阀侧电压额定值

	double Tk_N;//变压器额定变比
	double Tk;//变压器实际变比

	double Ud6Valve;//6脉动阀电压
	double Pd6Valve;//6脉动阀直流功率
	double Pac6Valve;//6脉动阀有功
	double Qac6Valve;//6脉动阀有功
};

typedef map<string, struct_mcResultData> mc_ResultMap;


/////////////////////////////////////////////////////////////
class CmcDefs
{
public:
	static const int	AcSys = 11;
	static const int	ACF = 12;
	static const int	Xf2 = 13;
	static const int 	Convertor = 14;
	static const int 	DcLine = 15;
	static const int 	GroundLine = 16;
	static const int 	MetalLine = 17;
	static const int 	Ground = 18;

};

enum Enum_mcStationCtrlType
{
	StaCtrl_ConstantPd = 0,
	StaCtrl_ConstantUd,
	StaCtrl_ConstantId,
	StaCtrl_ConstantAngle,
	StaCtrl_TrackId
};

enum Enum_mcTransformerCtrlType
{
	xfCtrl_FixedAngle = 0,
	xfCtrl_ConstantUv

};

//const string mcNodeNameACF[] =
//{
//
//};
//const string mcNodeNameAcSys[] =
//{
//
//};
const string mcNodeNameConvertor[] =
{
	"ConHigh",
	"ConLow"
};
//const string mcNodeNameXf2[] =
//{
//
//};
const string mcNodeNameGroundLine[] =
{
	"ConLow",
	"RdGnd"
};
const string mcNodeNameGround[] =
{
	"RdGnd"
};

struct RecUdCustom
{
	//崔康生20170528-直流电压预设
	int PdIndex;
	double Ud21; //双极单阀
	double Ud22;//双极双阀
	double Ud11;//单极单阀
	double Ud12;//单极双阀
};
typedef vector<RecUdCustom> UdDataVect;