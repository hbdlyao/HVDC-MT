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

	static const int		DFixed = 21;	//�ֶ�����
	static const int		DAutoDis = 22;	//�������
	static const int		DRandom = 23;	//���ʷֲ�
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

	string StationName;//վ��
	string ValName;//��������

	int StaIndex;
	int ValvorIndex;

	//ԭʼ����
	//
	int Position;//

	double PhaseA;//����A����λ

	double Lac;

	double kT;

	double LTNd;

	double dLT[3];

	double RabcNd;//

	double AngleNdRad;//��ƫ�����/Ϩ����

	double dAngleRad[6];

	double MiuNd;
	//
	int StationType;//����/��䣬��Ӧ������/Ϩ����
	//
	int DimhUv;

	struct_AcSysXb * hUv;//�������������г�� ���ѹ ��ֵ��λ
					  
	double UvRms;//�����ߵ�ѹ��Чֵ	

	double Id;

	double PhaseShift;

	//�м����
	double Labc[3];

	double LabcNd;//��ƫ�����

	double Umax1;

	double Umax2;

	double AngleRad[6];//������/�ضϽ�

	double Miu[6];//�����

	//���
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
	string StationName;//վ��

	//int WorkState;

	double PdPer;//����ˮƽ

	double Uac;//������ѹ
	double Uv;//�����ѹ
	double UvN;//�����ѹ�ֵ
	//double Udio;//�������ֱ����ѹ
	//double Udio_N;//�������ֱ����ѹ�ֵ
	//double Ud;//ֱ���˿ڵ�ѹ
	//double UdL;//ֱ���˿ڶԵص�ѹ
	double Id;//ֱ������
	//double Pd;//ֱ������
	//double Pconv;//�������й�
	//double Qconv;//�������޹�
	int TC;//��ѹ���ֽ�ͷ��λ
	double alphaOrgamma;//������/�ضϽ�
	double miu;//�����
	//double Qf_max;//�˲����ṩ������޹�
	//double Qf_min;//�˲����ṩ����С�޹�

	double Nnom;//��ѹ������
};

typedef map<string, struct_U3pStaData *> p3pSModeDataMap;