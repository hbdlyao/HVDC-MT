///////////////////////////////////////////////////////////
//  CmcResult.cpp
//  Implementation of the Class CmcResult
//  Created on:      03-4月-2017 18:54:55
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcResult.h"
#include "CHvdcFunc.h"
#include "CmcParams.h"

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
	datDim = nStaDim*nCaseDim*nPdPreDim;
	pmcResultData = new struct_mcResultData[datDim];

}

void CmcResult::NewData(int vDim)
{
	datDim = vDim;
	pmcResultData = new struct_mcResultData[datDim];
}

void CmcResult::NewData1(int vDim)
{
	datDim = vDim * PdSize()*StaCount();
	pmcResultData = new struct_mcResultData[datDim];
}

int CmcResult::DataDim()
{
	datDim = nStaDim*nCaseDim*nPdPreDim;

	return datDim;

}

int CmcResult::PdSize()
{
	return 29;

}

int CmcResult::StaCount()
{
	return CmcParams::mcStationCount;

}

string CmcResult::GetResultName()
{
	return ResultName;
}


void CmcResult::Record(string vCalName, string vCaseId, struct_mcStationData* vStaData, struct_mcStationData* vStaDataN)
{
	ResultName = vCalName;

	for (int i = 0; i < nStaDim; i++)
	{
		strcpy_s(pmcResultData[CurrentOffset].CalName, vCalName.c_str());
		strcpy_s(pmcResultData[CurrentOffset].CaseID, vCaseId.c_str());
		strcpy_s(pmcResultData[CurrentOffset].StationName, vStaData[i].StationName.c_str());

		pmcResultData[CurrentOffset].PdPer	= vStaData[i].PdPer;

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
		// *南方电网主回路及谐波计算软件*
		// 改动对象:  下面两句
		// 改动者:    崔康生
		// 改动类型:  修正Bug
		// 改动内容:  1.在原先基础上除以极数nPoleNum
		// 改动时间:  2017/05/23
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


void CmcResult::Serialize(Byte * vPacket)
{
	long vN,vRecByte, vPacketLeng;

	vN = sizeof(long);
	vRecByte = RecordByte();
	vPacketLeng = DataDim()*vRecByte;

	//
	memmove(vPacket, &vPacketLeng, vN);
	vPacket += sizeof(long);
	
	//
	memmove(vPacket, &vRecByte, vN);
	vPacket += sizeof(long);

	//
	for (int i = 0; i<DataDim(); i++)
	{
		memmove(vPacket, &pmcResultData[i], vRecByte);
		vPacket += vRecByte;
	}

	
}

void CmcResult::UnSerialize(Byte * vPacket)
{
	//
	long vN, vRecByte, vPacketLeng;

	vN = sizeof(long);

	memmove(&vPacketLeng, vPacket, vN);
	vPacket += sizeof(long);

	memmove(&vRecByte, vPacket, vN);
	vPacket += sizeof(long);

	long vDim = vPacketLeng / vRecByte;
	pmcResultData = new struct_mcResultData[vDim];
	
	for (int i = 0; i<vDim; i++)
	{
		memmove(&pmcResultData[i], vPacket,vRecByte);
		vPacket += vRecByte;

		NewCase(&pmcResultData[i]);

	}

}


long  CmcResult::PackedLeng()
{
	return DataDim()*RecordByte();
}

int  CmcResult::RecordByte()
{
	//int vN = 3 * sizeof(char) * 50 + sizeof(int) * 1 + sizeof(double) * 22;

	int vN=sizeof(struct_mcResultData);

	return vN;

}


CmcCase *  CmcResult::NewCase(struct_mcResultData * vData)
{	
	//
	CmcCase * vCase;

	StrVector vNames;

	vNames.push_back(vData->CalName);
	vNames.push_back(vData->CaseID);
	vNames.push_back(vData->StationName);
	//vNames.push_back(to_string(vData->PdPer));

	vCase = pPack.NewCase(0, vNames);

	vCase->CalName = vData->CalName;
	vCase->CaseID = vData->CaseID;
	vCase->StationName = vData->StationName;
	vCase->PdPer = vData->PdPer;

	vCase->pDataVect.push_back(vData);

	return vCase;

}
