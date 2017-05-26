#pragma once

#include "CMyDefs.h"
#include "CHvdcDefs.h"

#include <vector>

class C3pDefs
{
public:
	static const int	    AcSys = 11;
	static const int 	StaData = 12;
	static const int 	Xf2 = 13;
	static const int 	Convertor = 14;

	static const int 	SModeData = 15;



	static const int		Pos = 19;
	static const int		Neg = 20;

	static const int		DFixed = 21;	//手动输入
	static const int		DAutoDis = 22;	//程序分配
	static const int		DRandom = 23;	//概率分布
};

struct struct_AcSysXb
{
	int hIndex;
	double hUrms;
	double hAngle;

};

typedef vector<struct_AcSysXb> AcSysXbVector;

enum Enum_3pPhase
{
	Phase_A = 0,
	Phase_B,
	Phase_C,
};

enum Enum_3pPosOrNeg
{
	Position_Pos0 = 0,
	
	Position_Neg0 = 20
};


enum Enum_U3p_6pValvorIndex
{
	U3p_6pValvor_Pos11 = 11,
	U3p_6pValvor_Pos12 = 12,
	U3p_6pValvor_Pos21 = 13,
	U3p_6pValvor_Pos22 = 14,

	U3p_6pValvor_Neg11 = 51,
	U3p_6pValvor_Neg12 = 52,
	U3p_6pValvor_Neg21 = 53,
	U3p_6pValvor_Neg22 = 54

};

struct struct_3p_hUv
{
	int HOrder;

	double Urms;

	double PhaseRad;
};

struct struct_3p_hData
{
public:
	string CalName;
	string CaseID;
	double PdPercent;

	string StationName;//站名
	string ValName;//换流器名

	int StaIndex;
	int ValvorIndex;

	//原始参数
	//
	int Position;//

	double PhaseA;//基波A相相位

	double Lac;

	double kT;

	double LTNd;

	double dLT[3];

	double RabcNd;//

	double AngleNdRad;//无偏差触发角/熄弧角

	double dAngleRad[6];

	double MiuNd;
	//
	int StationType;//整流/逆变，对应触发角/熄弧角
	//
	int DimhUv;

	struct_AcSysXb * hUv;//网侧基波及各次谐波 相电压 幅值相位
					  
	double UvRms;//阀侧线电压有效值	

	double Id;

	double PhaseShift;

	//中间变量
	double Labc[3];

	double LabcNd;//无偏差换相电感

	double Umax1;

	double Umax2;

	double AngleRad[6];//触发角/关断角

	double Miu[6];//换相角

	//结果
	double L3p1;

	double L3p2;

	struct_3p_hUv * USrc3p1;

	struct_3p_hUv * USrc3p2;

};

struct struct_U3pStaData
{
public:
	string CaseID;
	string CalName;
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

typedef map<string, struct_U3pStaData *> p3pSModeDataMap;