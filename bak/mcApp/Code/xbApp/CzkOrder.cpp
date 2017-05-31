
#include "CzkOrder.h"
#include "CHvdcDefs.h"

void CzkOrder::Init()
{
	UacLevel = new int[StaCount()];

	//
	nValNum = 2;

	Flag_Ground = "100";  //�������/��������/˫��
	Flag_Ud = "100";  //ȫѹ/80%/70%
	Flag_Rd = "001";    //����/����
	Flag_Uac = "0100";  //���/�/��С/��С

	IsUdCustom = false;//ֱ����ѹԤ���������Ԥ����ʹ��UdCustom��Ϊ��ѹָ�����ʹ��UdLevel
	IsUacSwap = true;// �Ƿ�����ѹ����
	IsUdToGround = false;//ֱ����ѹ�Եػ��������
						 //string Flag_IsPdSingle = "0";//�Ƿ񵥹���ˮƽ���ó�Ա���Բ�Ҫ������ԱBdSizeȡֵΪ1ʱ��Ϊ������ˮƽ
	PdStartPer = 100;//��ʼ����ˮƽ
	PdIncrePer = 5;//����ˮƽ����
	PdSize = 1;//����ˮƽ��

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

	//������:
	switch (nValNum)
	{
	case 1:
		CaseID.append("S");
		break;
	case 2:
		CaseID.append("D");
		break;
	}

	//�ӵ�:������أ�����������˫����˫������
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

	//Ud:ȫѹ,80%,70%
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

	//Rd:���衢����
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

	//����Uac
	if (StaCount() > 0)
	{
		for (int i = 0; i < StaCount(); i++)
			CaseID = CaseID + ((char)(UacLevel[i] + 1 + '0'));
	}//if


	 //����
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
