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
	//"DFBFH22" : 双阀，正向，双极，全压，高阻，两侧交流电压为额定

	//要计算的全部工况，来自输入
	int nValNum = 1;   //阀组数
	string Flag_Ground = "1111";  //单极大地/金属回线/双极/双极并联
	string Flag_Ud = "111";  //全压/80%/70%
	string Flag_Rd = "110";   //高阻/低阻（额定）
	string Flag_Uac = "1111";  //额定/最大/最小/极小
	bool IsUdCustom = false;//直流电压预设情况，如预设则使用UdCustom作为电压指令，否则使用UdLevel
	bool IsUacSwap = false;//是否交流电压交叉
	bool IsUdToGround = false;//直流电压对地或对中性线
	//string Flag_IsPdSingle = "0";//是否单功率水平，该成员可以不要，当成员BdSize取值为1时即为但功率水平
	double PdStartPer = 10;//起始功率水平
	double PdIncrePer = 5;//功率水平增量
	int PdSize = 29;//功率水平数

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