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
	//������е�����
	string StationName = "";//վ��


	//���Ʋ���
	int TapCtrlType;
	int WorkState;

	int StaCtrlType;
	int iNodeID;
	int jNodeID;
	int RefStaIndex;

	int J_Index;


	double PdPer=0;//����ˮƽ
	double Uac;//������ѹ
	double Uv;//�����ѹ
	double Udio;//�������ֱ����ѹ
	double Ud;//ֱ���˿ڵ�ѹ
	double UdL;//ֱ���˿ڶԵص�ѹ
	double Id;//ֱ������
	double Pd;//ֱ������
	double Pconv;//�������й�
	double Qconv;//�������޹�
	int TC;//��ѹ���ֽ�ͷ��λ
	double alphaOrgamma;//������/�ضϽ�
	double miu;//�����
	double Qf_max;//�˲����ṩ������޹�
	double Qf_min;//�˲����ṩ����С�޹�

				  //������Ҫ�õ��Ĳ���������HVDC�豸��
	int nT;//6��������
	int nPoleNum;//������˫���򵥼���
	double UT;//6�����ŵ�ѹ��
	double dr;//���Ի���ѹ��
	double dx;//���Ի���ѹ��
	double deltaK;//��ѹ��ÿ���ĵ�ѹ�ٷֱ�
	double QacInMax;//����ϵͳ�����յ�����޹�
	double QacOutMax;//����ϵͳ�ɷ���������޹�

					 //������Ҫ�õ��Ĳ���������HVDC�豸������ֵ
	double AngCtrl_Max;//�ֽ�ͷ�����л�����������/�ضϽǵ�����
	double AngCtrl_Min;//�ֽ�ͷ�����л�����������/�ضϽǵ�����
	int Tap_Max;//�ֽ�ͷ���λ
	int Tap_Min;//�ֽ�ͷ��С��λ
	double Ang_Min;//������������/�ضϽǵ���Сֵ
	double Uv_Max;//�����ѹ��������ֵ
				  //������Ҫ�õ��Ĳ������������
	double Nnom;//��ѹ������

};

struct struct_mcResultData
{
public:
	string CalName;
	string CaseID;
	string StationName;//վ��

	double PdPer=0;//����ˮƽ
	double Uac;//������ѹ
	double Uv;//�����ѹ
	double Udio;//�������ֱ����ѹ
	double Ud;//ֱ���˿ڵ�ѹ
	double UdL;//ֱ���˿ڶԵص�ѹ
	double Id;//ֱ������
	double Pd;//ֱ������
	double Pconv;//�������й�
	double Qconv;//�������޹�

	int TC;//��ѹ���ֽ�ͷ��λ
	double alphaOrgamma;//������/�ضϽ�
	double miu;//�����
	double Qf_max;//�˲����ṩ������޹�
	double Qf_min;//�˲����ṩ����С�޹�

	double Udio_N;//�������ֱ����ѹ�ֵ
	double Uv_N;//�����ѹ�ֵ

	double Tk_N;//��ѹ������
	double Tk;//��ѹ��ʵ�ʱ��

	double Ud6Valve;//6��������ѹ
	double Pd6Valve;//6������ֱ������
	double Pac6Valve;//6�������й�
	double Qac6Valve;//6�������й�
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


//************************************
// *�Ϸ���������·��г���������*
// �Ķ�����:  mcNodeNameACF��xbNodeNameXf2
// �Ķ���:    �޿���
// �Ķ�����:  ����
// �Ķ�����:  1.�豸��Ĭ�Ͻڵ�����
// �Ķ�ʱ��:  2017/05/23
//************************************
//const string mcNodeNameACF[] =
//{
//
//};
//const string xbNodeNameAcSys[] =
//{
//
//};
const string xbNodeNameConvertor[] =
{
	"ConHigh",
	"ConLow",
};

//const string xbNodeNameXf2[] =
//{
//
//};