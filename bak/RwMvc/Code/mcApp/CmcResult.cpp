///////////////////////////////////////////////////////////
//  CmcResult.cpp
//  Implementation of the Class CmcResult
//  Created on:      03-4��-2017 18:54:55
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcResult.h"
#include "CHvdcFunc.h"


CmcResult::~CmcResult()
{
	Release();
}


void CmcResult::Release()
{
	delete[] pmcResultData;
	pmcResultData = nullptr;
}


void CmcResult::Clear()
{
	delete[] pmcResultData;
	pmcResultData = nullptr;

	CurrentOffset = 0;
}


void CmcResult::Init()
{

	nStaDim = 0;
	nCaseDim = 0;
	nPdPreDim = 0;

	pmcResultData = nullptr;
	CurrentOffset = 0;

}

void CmcResult::Init(int vStaDim, int vCaseDim, int vPdPreDim)
{
	CurrentOffset = 0;

	//
	nStaDim = vStaDim;
	nCaseDim = vCaseDim;
	nPdPreDim = vPdPreDim;

	//
	int vN = DataDim();
	pmcResultData = new struct_mcResultData[vN];

}

int CmcResult::DataDim()
{
	datDim = nStaDim*nCaseDim*nPdPreDim;

	return datDim;

}

void CmcResult::Record(string vCalName, string vCaseId, struct_mcStationData* vStaData, struct_mcStationData* vStaDataN)
{
	ResultName = vCalName;

	for (int i = 0; i < nStaDim; i++)
	{
		pmcResultData[CurrentOffset].CalName= vCalName;
		pmcResultData[CurrentOffset].CaseId = vCaseId;
		pmcResultData[CurrentOffset].PdPer	= vStaData[i].PdPer;
		pmcResultData[CurrentOffset].StationName = vStaData[i].StationName;

		pmcResultData[CurrentOffset].Pconv = vStaData[i].Pconv;
		pmcResultData[CurrentOffset].Qconv = vStaData[i].Qconv;
		pmcResultData[CurrentOffset].Qf_max = vStaData[i].Qf_max;
		pmcResultData[CurrentOffset].Qf_min = vStaData[i].Qf_min;

		pmcResultData[CurrentOffset].Pd = vStaData[i].Pd;
		pmcResultData[CurrentOffset].Id = vStaData[i].Id;
		pmcResultData[CurrentOffset].Ud = vStaData[i].Ud;
		pmcResultData[CurrentOffset].UdL = vStaData[i].UdL;

		pmcResultData[CurrentOffset].Uac = vStaData[i].Uac;
		pmcResultData[CurrentOffset].Uv = vStaData[i].Uv;
		pmcResultData[CurrentOffset].Udio = vStaData[i].Udio;
		
		pmcResultData[CurrentOffset].Uv_N = vStaDataN[i].Uv;
		pmcResultData[CurrentOffset].Udio_N = vStaDataN[i].Udio;
		
		//************************************
		// *�Ϸ���������·��г���������*
		// �Ķ�����:  ��������
		// �Ķ���:    �޿���
		// �Ķ�����:  ����Bug
		// �Ķ�����:  1.��ԭ�Ȼ����ϳ��Լ���nPoleNum
		// �Ķ�ʱ��:  2017/05/23
		//************************************
		pmcResultData[CurrentOffset].Pac6Valve = vStaData[i].Pconv / vStaData[i].nT / vStaData[i].nPoleNum;
		pmcResultData[CurrentOffset].Qac6Valve = vStaData[i].Qconv / vStaData[i].nT / vStaData[i].nPoleNum;

		pmcResultData[CurrentOffset].Pd6Valve = vStaData[i].Pd / vStaData[i].nT;
		pmcResultData[CurrentOffset].Ud6Valve = vStaData[i].Ud / vStaData[i].nT;

		pmcResultData[CurrentOffset].alphaOrgamma = CHvdcFunc::R2D(vStaData[i].alphaOrgamma);
		pmcResultData[CurrentOffset].miu = CHvdcFunc::R2D(vStaData[i].miu);

		pmcResultData[CurrentOffset].TC = vStaData[i].TC;
		pmcResultData[CurrentOffset].Tk = vStaData[i].Nnom*(1 + vStaData[i].TC*vStaData[i].deltaK / 100);
		pmcResultData[CurrentOffset].Tk_N = vStaData[i].Nnom;

		//
		CurrentOffset++;

	}
}

string CmcResult::GetResultName()
{
	return ResultName;
}
