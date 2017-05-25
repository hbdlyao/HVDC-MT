#pragma once

#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

class CHvdcOrder
{
public:
	virtual ~CHvdcOrder();

	virtual void Init();
	virtual void InitNormal();

	virtual void Release();
	virtual void Clear();

public:
	string CalName;
	vector<string> CaseList;

	void AddCase(string vID);

	string CreateCaseID();
	void ParserOrder(string vCaseID);

	int CaseCount();

	virtual int StaCount() { return 0; };

public:
	//"DFBFH22" : ˫��������˫����ȫѹ�����裬���ཻ����ѹΪ�

	//Ҫ�����ȫ����������������
	int nValNum = 1;   //������
	string Flag_Ground = "1111";  //�������/��������/˫��/˫������
	string Flag_Ud = "111";  //ȫѹ/80%/70%
	string Flag_Rd = "110";   //����/���裨���
	string Flag_Uac = "1111";  //�/���/��С/��С
	bool IsUdCustom = false;//ֱ����ѹԤ���������Ԥ����ʹ��UdCustom��Ϊ��ѹָ�����ʹ��UdLevel
	bool IsUacSwap = false;//�Ƿ�����ѹ����
	bool IsUdToGround = false;//ֱ����ѹ�Եػ��������
	//string Flag_IsPdSingle = "0";//�Ƿ񵥹���ˮƽ���ó�Ա���Բ�Ҫ������ԱBdSizeȡֵΪ1ʱ��Ϊ������ˮƽ
	double PdStartPer = 10;//��ʼ����ˮƽ
	double PdIncrePer = 5;//����ˮƽ����
	int PdSize = 29;//����ˮƽ��

	int GroundType;
	int UdLevel;
	int RdLevel;
	int * UacLevel;
	double UdCustom;
	double PdPer;
	
	int IsNormal = false;

public:
	void UpdatePdPercent(int & vPdSize);


};