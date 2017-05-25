
#include "C3pSolveMvc.h"

#include "C3pParams.h"

#include "C3pRwOrderMvc.h"

#include <iostream>

C3pSolveMvc::~C3pSolveMvc()
{
	p3pSolves->Clear();
	delete p3pSolves;
	p3pSolves = nullptr;

	//
	p3pProfile->Clear();
	delete p3pProfile;
	p3pProfile = nullptr;


	p3pResult->Clear();
	delete p3pResult;
	p3pResult = nullptr;

}

void C3pSolveMvc::Clear()
{
	p3pSolves->Clear();

	p3pProfile->Clear();

	p3pResult->Clear();

}

void C3pSolveMvc::Init(C3pDevGrid* vGrid)
{
	p3pHvdc = vGrid;

	//
	p3pProfile = new C3pProfile();
	p3pProfile->Init();

	//
	p3pResult = new C3pResult();
	p3pResult->Init();

	p3pSolves = new C3pSolves();
	p3pSolves->Init(p3pProfile, p3pHvdc);

}

void C3pSolveMvc::InitOrder(C3pOrder * vOrder)
{
	//CalName = vOrder->CalName;

	p3pOrder = vOrder;

	p3pProfile->InitOrder(p3pOrder);
	p3pSolves->InitOrder(p3pOrder);
}

void C3pSolveMvc::Test(int vGNDType)
{
	////
	//p3pOrder->GroundType = vGNDType;
	////
	//p3pSolves->Init(p3pProfile, p3pHvdc);

	////
	//doNewSolves(vGNDType);

	////�ڵ���
	//doNodeID();

	//doStationSort();

	////��ʼ�������þ���
	//doInitMatrix();

	//doRun();

}

void C3pSolveMvc::doNewSolves(int vGNDType)
{
	//
	p3pSolves->Clear();
	//
	p3pSolves->NewSolves(vGNDType);
	//
}



int C3pSolveMvc::StaCount()
{
	//�ӹ��������ж�ȡ
	return C3pParams::StationCount;

}

void C3pSolveMvc::Run()
{

	doInitRun();

	//�๤������
	doRun_Ground(p3pOrder->Flag_Ground);
}


double C3pSolveMvc::Frequence()
{
	return C3pParams::Frequence;
}

double C3pSolveMvc::hMax()
{
	return C3pParams::hMax;
}

void C3pSolveMvc::doRun()
{
	//����

	//���ǹ���(����ˮƽ)��DCFƫ�����͡�г������
	//doPrepare_U3p(p3pOrder->CreateCaseID());

	p3pProfile->ReSetData();
	//г������1-hMax()
	for (int i = 1; i <= hMax(); i++)
		//int i = 1;
	{
		cout << "----г������:  " << i << "-----" << endl;

		p3pProfile->hIndex = i;

		p3pSolves->Run();
	}
	//

	//��¼���
	doRecordResult();


}


void C3pSolveMvc::doRecordResult()
{
	//������
	static int vN = 1;
	string vCaseID = p3pOrder->CreateCaseID();

	//p3pResult->mcResultMap[vCaseID]=

	cout << "г��:";
	cout << vCaseID;
	cout << "%";
	cout << p3pOrder->PdPer;

	cout << "======" << vN++;

	cout << endl;
}


void C3pSolveMvc::doInitRun()
{

	//
	p3pSolves->Init(p3pProfile, p3pHvdc);
	//
	int vStaCount = StaCount();

	//
	int vCaseCount = p3pOrder->CaseCount();
	p3pResult->Clear();
	//p3pResult->Init(vStaCount, vCaseCount, p3pOrder->PdSize);
}



void C3pSolveMvc::doRun_Ground(string vFlag) 
{

	int vN = static_cast<int> (vFlag.size());

	//�������/��������/˫��/˫������
	for (int i = 0; i < vN; i++)
	{
		if (vFlag[i] == '1') //"1111"
		{
			p3pOrder->GroundType = GndTypeArr[i];


			//���ݽӵ��������� mcCalculate,���豸һһ��Ӧ
			doNewSolves(GndTypeArr[i]);

			doStationSort();

			doSort3p();

			//��ʼ�������þ���
			p3pProfile->InitData();

			doRun_Rd(p3pOrder->Flag_Rd);

		}//if

	}//for
}

void C3pSolveMvc::doSort3p() {
	p3pSolves->Sort3p();
}
void C3pSolveMvc::doStationSort()
{
	p3pSolves->StationSort();
}
void C3pSolveMvc::doRun_Rd(string vFlag) {

	int vN = static_cast<int> (vFlag.size());

	//���衢����
	for (int i = 0; i < vN; i++)
	{
		if (vFlag[i] == '1') //
		{
			p3pOrder->RdLevel = RdLevelArr[i];

			//
			if (p3pOrder->IsUdCustom) //ָ��Ud
				doRun_UdCustom();
			else
				doRun_Ud(p3pOrder->Flag_Ud);

		}//if vFlag

	}//for
}


void C3pSolveMvc::doRun_Ud(string vFlag) {

	int vN = static_cast<int> (vFlag.size());
	int vStaCount = StaCount();

	//ȫѹ/80%/70%
	for (int i = 0; i < vN; i++)
	{
		if (vFlag[i] == '1')
		{
			p3pOrder->UdLevel = UdLevelArr[i];

			if (p3pOrder->IsUacSwap)
				doRun_UacSwap(p3pOrder->Flag_Uac, 0, vStaCount);
			else
				doRun_Uac(p3pOrder->Flag_Uac);

		}//if

	}//for
}


void C3pSolveMvc::doRun_UdCustom()
{

	int vStaCount = StaCount();

	p3pOrder->UdLevel = Ud_Custom;

	//Ud����

	//
	if (p3pOrder->IsUacSwap)
		doRun_UacSwap(p3pOrder->Flag_Uac, 0, vStaCount);
	else
		doRun_Uac(p3pOrder->Flag_Uac);
}


void C3pSolveMvc::doRun_Uac(string vFlag) 
{

	int vN = static_cast<int> (vFlag.size());
	int vStaCount = StaCount();

	//���/�/��С/��С
	for (int i = 0; i < vN; i++)
		if (vFlag[i] == '1')
		{
			for (int j = 0; j < vStaCount; j++)
				p3pOrder->UacLevel[j] = UacLevelArr[i];
			//
			doRun_Pd();
		}//if
}


void C3pSolveMvc::doRun_UacSwap(string vFlag, int vIndex, int vStaCount) {

	int vN = static_cast<int> (vFlag.size());


	//vIndex��0��ʼ,��vIndex==vStaCount,˵�����еĻ���վ��������Uac
	if (vIndex == vStaCount)
		doRun_Pd();
	else
	{//���/�/��С/��С
		for (int i = 0; i < vN; i++)
			if (vFlag[i] == '1')
			{
				p3pOrder->UacLevel[vIndex] = UacLevelArr[i];

				doRun_UacSwap(vFlag, vIndex + 1, vStaCount);
			}//if

	}//else
}


void C3pSolveMvc::doRun_Pd()
{

	int vPdSize;

	vPdSize = p3pOrder->PdSize;

	for (int i = 0; i < vPdSize; i++)
	{
		p3pOrder->UpdatePdPercent(i);

		//doRun_DCF();

		doRun();

	}//for
}
