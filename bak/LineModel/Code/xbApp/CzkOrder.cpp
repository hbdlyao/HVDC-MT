
#include "CzkOrder.h"
#include "CHvdcDefs.h"

void CzkOrder::Init()
{
	UacLevel = new int[StaCount()];

	//
	nValNum = 2;

	Flag_Ground = "100";  //单极大地/金属回线/双极
	Flag_Ud = "100";  //全压/80%/70%
	Flag_Rd = "001";    //高阻/低阻
	Flag_Uac = "0100";  //最大/额定/最小/极小

	IsUdCustom = false;//直流电压预设情况，如预设则使用UdCustom作为电压指令，否则使用UdLevel
	IsUacSwap = true;// 是否交流电压交叉
	IsUdToGround = false;//直流电压对地或对中性线
						 //string Flag_IsPdSingle = "0";//是否单功率水平，该成员可以不要，当成员BdSize取值为1时即为但功率水平
	PdStartPer = 100;//起始功率水平
	PdIncrePer = 5;//功率水平增量
	PdSize = 1;//功率水平数

	FreStart = 10;

	FreStep = 10;

	FreDim = 300;

	ScanPort = 0;

	ScanPortPole = 0;
}

string CzkOrder::CreateCaseID()
{

	//char buff[1];

	string CaseID = "";

	//阀组数:
	switch (nValNum)
	{
	case 1:
		CaseID.append("S");
		break;
	case 2:
		CaseID.append("D");
		break;
	}

	//接地:单极大地，单极金属，双极，双极并联
	switch (GroundType)
	{
	case Ground20:
		CaseID.append("B");
		break;
	case Ground11:
		CaseID.append("M");
		break;
	case Ground10:
		CaseID.append("G");
		break;
	case Ground21:
		CaseID.append("P");
		break;
	default:
		break;
	}

	//Ud:全压,80%,70%
	switch (UdLevel)
	{
	case Ud_Full:
		CaseID.append("F");
		break;
	case Ud_Per80:
		CaseID.append("R");
		break;
	case Ud_Per70:
		CaseID.append("S");
		break;

	case Ud_Custom:
		CaseID.append("C");
		break;

	default:
		break;
	}

	//Rd:高阻、低阻
	switch (RdLevel)
	{
	case Rd_High:
		CaseID.append("H");
		break;
	case Rd_Low:
		CaseID.append("L");
		break;
	default:
		break;
	}

	//交流Uac
	if (StaCount() > 0)
	{
		for (int i = 0; i < StaCount(); i++)
			CaseID = CaseID + ((char)(UacLevel[i] + 1 + '0'));
	}//if


	 //马骏鹏
	CaseID += "%" + to_string(PdPer);

	//
	return CaseID;
}

string CzkOrder::GetPortName(int i)
{
	string Pole = "";
	if (ScanPortPole == xb_Pos)
		Pole = "Pos";
	if (ScanPortPole == xb_Neg)
		Pole = "Neg";

	if (i = 0)
		return ScanPortStation + "---" + Pole + "ValveTerm";

	if(i=1)
		return ScanPortStation + "---" + Pole + "ValveGnd";

	return "";
}
