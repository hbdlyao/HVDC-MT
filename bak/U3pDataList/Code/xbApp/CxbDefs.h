#pragma once

#include "CMyDefs.h"
#include "CHvdcDefs.h"

#define LINE_GAMMA_MAX 0.00001	//��·�������㾫��
#define LINE_SEQ_SERIES_NUM 11 //��·���ֶμ��㼶��չ������
#define SINGLE_LINE_COE pow(0.1, 12)//��·���ֶγ������ݿ���ϵ��


class CxbDefs
{
public:
	static const int Usrc3p		= 1;
	static const int PbDKQ		= 2;
	static const int DCF		= 3;
	static const int DcLine_Seg = 4;
	static const int GroundLine_Seg = 5;
	static const int Ground		= 6;
	static const int MetalLine	= 7;
	static const int XfC		= 8;
	static const int CoupleC	= 9;
	static const int PulseC		= 10;
	static const int Shunt		= 11;
	static const int Branch		= 12;
	static const int Trap		= 13;
	static const int Monitor	= 14;
	static const int DCF_RLC	= 15;

	static const int DCLine		= 16;
	static const int GroundLine = 17;

};

enum Enum_xbPosOrNeg
{
	xb_Pos = 0,
	xb_Neg = 1
};

enum Enum_DCFType
{
	DCF_None,
	DCF_Single,
	DCF_Double,
	DCF_DoubleHighPass,
	DCF_Triple,
	DCF_TripleHighPass
};


//ֱ���˲���ƫ������
enum Enum_DCFOrder
{
	DCF_NoneDev = 0, //��ƫ��
	DCF_ConsDev = 1, //�㶨ƫ��
	DCF_RandDev = 2, //����ƫ��
	DCF_ConPDev = 3, //��ƫ��
	DCF_ConNDev = 4  //��ƫ��
};

enum Enum_LineResisType
{
	CondMeter = 0,
	ResisMeter = 1,
	ResisPerKilo = 2
};


//typedef vector<struct_xbBranchData> xbBranchDataVector;

struct struct_xbUI
{
	//��վ���÷�����
	double * IBranchRms;

	//��վ������������Чֵ
	double * IBranchVec;

	//
	double * UBranchRms;

	//
	double * UBranchVec;
};

struct struct_xbILine
{
	//��1����г������
	double * IBranch1;

	//��2����г������
	double * IBranch2;

	//P��Ȩ���
	double * Ieq_P;
	//C��Ȩ���
	double * Ieq_C;
	//�޼�Ȩ���
	double * Ieq_N;
};

struct struct_xbU3PData
{
public:
	string CalName;
	string CaseID;

	double PdPercent;

	double * Urms = nullptr;
	double * Angle = nullptr;

	double * Ire = nullptr;
	double * Iim = nullptr;

	double * Yb = nullptr;

};


//typedef map<string, struct_xbU3PData *> pxbU3PData_Map;
//typedef map<string, pxbU3PData_Map *> pxbU3PPowPre_Map;


enum Enum_xbNodePbDKQ
{
	xbNodeLd1N1 = 0,
	xbNodeLd1N2,
	xbNodeLd2N1,
	xbNodeLd2N2,
	xbNodeLd3N1,
	xbNodeLd3N2,
	xbNodeLd4N1,
	xbNodeLd4N2,
	xbNodeLd5N1,
	xbNodeLd5N2,
	xbNodeLd6N1,
	xbNodeLd6N2,
	xbNodeLd7N1,
	xbNodeLd7N2,
	xbNodeLd8N1,
	xbNodeLd8N2,
};


enum Enum_xbNodeDCF
{
	xbNodeDCF1N1 = 0,
	xbNodeDCF1N2,
	xbNodeDCF2N1,
	xbNodeDCF2N2,
	xbNodeDCF3N1,
	xbNodeDCF3N2,
	xbNodeDCF4N1,
	xbNodeDCF4N2
};

enum Enum_xbNodeCoupleC
{
	xbNodeCoupleC1N1 = 0,

	xbNodeCoupleC2N1,

};

enum Enum_xbNodePulseC
{
	xbNodePulseC1N1 = 0,

	xbNodePulseC2N1,

};

enum Enum_xbNodeTrap
{
	xbNodeTrap1N1 = 0,
	xbNodeTrap1N2,
	xbNodeTrap2N1,
	xbNodeTrap2N2,
	xbNodeTrap3N1,
	xbNodeTrap3N2,
	xbNodeTrap4N1,
	xbNodeTrap4N2
};

enum Enum_xbNodeMonitor
{
	xbNodeMonitor1N1 = 0,
	xbNodeMonitor1N2,
	xbNodeMonitor2N1,
	xbNodeMonitor2N2,
};


enum Enum_xbNodeGround
{
	xbNodeGround1N1 = 0,
};


enum Enum_xbNodeGroundLine
{
	xbNodeGroundLine1N1 = 0,
};


const string xbNodeNamePbDKQ[] =
{
	"PosValveTerm",
	"PosLdTerm",
	"PosLdTerm",
	"PosTerm",
	"PosValveGnd",
	"PosValve",
	"PosTrap1Gnd",
	"PosLdGnd",
	"PosTrap2Gnd",
	"NegValveTerm",
	"NegLdTerm",
	"NegLdTerm",
	"NegTerm",
	"NegValveGnd",
	"NegValve",
	"NegTrap1Gnd",
	"NegLdGnd",
	"NegTrap2Gnd"
};

const string xbNodeNameDCF[] =
{
	"PosLdTerm",
	"PosLdGnd",
	"PosTerm",
	"NodeShared",
	"NegLdTerm",
	"NegLdGnd",
	"NegTerm",
	"NodeShared"
};

const string xbNodeNameCoupleC[] =
{
	"PosTerm",
	"NegTerm"
};

const string xbNodeNamePulseC[] =
{
	"NodeShared",
	"NodeShared"
};

const string xbNodeNameTrap[] =
{
	"PosTrap1Gnd",
	"PosLdGnd",
	"PosTrap2Gnd",
	"NodeShared",
	"NegTrap1Gnd",
	"NegLdGnd",
	"NegTrap2Gnd",
	"NodeShared"
};

const string xbNodeNameMonitor[] =
{
	"NodeShared",
	"GLineInside",
	"GLineGround",
	"GndRe"
};

const string xbNodeNameGround[] =
{
	"GndRe"
};

const string xbNodeNameGroundLine[] =
{
	"GLineInside",
	"GLineInside",
	"GLineGround",
	"GLineGround"
};