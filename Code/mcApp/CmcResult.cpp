///////////////////////////////////////////////////////////
//  CmcResult.cpp
//  Implementation of the Class CmcResult
//  Created on:      03-4ÔÂ-2017 18:54:55
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcResult.h"
#include "CmcParams.h"

#include "CMyFunc.h"


CmcResult::~CmcResult()
{
	Release();
}


void CmcResult::Release()
{
	//
	pCasePack.Release();

	//
	for each (struct_mcResultData * vData in pDataVect)
	{
		delete vData;
		vData = nullptr;
	}

	//
	pDataVect.clear();

}

void CmcResult::Clear()
{
	Release();
}

void CmcResult::Init()
{
	nStaDim = 0;
	nCaseDim = 0;
	nPdPreDim = 0;


	pCasePack.DataName = "root";
	pCasePack.Init();

}

void CmcResult::Init(int vStaDim, int vCaseDim, int vPdPreDim)
{
	//
	nStaDim = vStaDim;
	nCaseDim = vCaseDim;
	nPdPreDim = vPdPreDim;

}

int CmcResult::DataDim()
{
	return static_cast<int>(pDataVect.size());
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
	return CalName;
}


void CmcResult::Record(string vCalName, string vCaseId, struct_mcStationData* vStaData, struct_mcStationData* vStaDataN)
{
	CalName = vCalName;

	struct_mcResultData* vData;
	for (int i = 0; i < nStaDim; i++)
	{
		vData = new struct_mcResultData;

		//
		strcpy_s(vData->CalName, vCalName.c_str());
		strcpy_s(vData->CaseID, vCaseId.c_str());
		strcpy_s(vData->StationName, vStaData[i].StationName.c_str());

		vData->PdPer	= vStaData[i].PdPer;

		vData->Pconv = vStaData[i].Pconv;
		vData->Qconv = vStaData[i].Qconv;
		vData->Qf_max = vStaData[i].Qf_max;
		vData->Qf_min = vStaData[i].Qf_min;

		vData->Pd = vStaData[i].Pd;
		vData->Id = vStaData[i].Id;
		vData->Ud = vStaData[i].Ud;
		vData->UdL = vStaData[i].UdL;

		vData->Uac = vStaData[i].Uac;
		vData->Uv = vStaData[i].Uv;
		vData->Udio = vStaData[i].Udio;
		
		vData->Uv_N = vStaDataN[i].Uv;
		vData->Udio_N = vStaDataN[i].Udio;
		
		vData->Pac6Valve = vStaData[i].Pconv / vStaData[i].nT / vStaData[i].nPoleNum;
		vData->Qac6Valve = vStaData[i].Qconv / vStaData[i].nT / vStaData[i].nPoleNum;

		vData->Pd6Valve = vStaData[i].Pd / vStaData[i].nT;
		vData->Ud6Valve = vStaData[i].Ud / vStaData[i].nT;

		vData->alphaOrgamma = CMyFunc::R2D(vStaData[i].alphaOrgamma);
		vData->miu = CMyFunc::R2D(vStaData[i].miu);

		vData->TC = vStaData[i].TC;
		vData->Tk = vStaData[i].Nnom*(1 + vStaData[i].TC*vStaData[i].deltaK / 100);
		vData->Tk_N = vStaData[i].Nnom;

		//
		pDataVect.push_back(vData);

	}
}


void CmcResult::NewCase()
{
	for each(struct_mcResultData* vData in pDataVect)
	{
		doNewCase(vData);
	}

}


CmcCase *  CmcResult::doNewCase(struct_mcResultData * vData)
{
	StrVector vNames;
	vNames.push_back(vData->CalName);
	vNames.push_back(vData->CaseID);
	vNames.push_back(vData->StationName);
	//vNames.push_back(to_string(vData->PdPer));

	//
	CmcCase * vCase;
	vCase = doNewCase(vNames, vData);

	return vCase;

}

void CmcResult::NewCaseU3p()
{
	for each(struct_mcResultData* vData in pDataVect)
	{
		doNewCaseU3p(vData);	
	}

}


CmcCase *  CmcResult::doNewCaseU3p(struct_mcResultData * vData)
{	
	StrVector vNames;
	vNames.push_back(vData->CalName);
	vNames.push_back(vData->CaseID);
	//vNames.push_back(vData->StationName);	
	vNames.push_back(CMyFunc::GetString(vData->PdPer,"%4.0f"));

	//
	CmcCase * vCase;
	vCase =doNewCase(vNames, vData);

	return vCase;

}



CmcCase * CmcResult::doNewCase(StrVector vNames, struct_mcResultData * vData)
{
	CmcCase * vCase;

	vCase = pCasePack.NewCase(0, vNames, vData);

	/*vCase->CalName = vData->CalName;
	vCase->CaseID = vData->CaseID;
	vCase->StationName = vData->StationName;
	vCase->PdPer = vData->PdPer;*/

	//vCase->pDataVect.push_back(vData);

	return vCase;

}


CmcCase * CmcResult::doFindCase(StrVector vNames)
{
	CmcCase * vCase = pCasePack.FindCase(0, vNames);

	return vCase;

}

long CmcResult::PacketBytes(vector<struct_mcResultData*> & vDataVect)
{
	long vHeadByte, vRecBytes, vDataDim, vPacketBytes;

	vHeadByte = sizeof(long);
	vRecBytes = RecordByte();
	vDataDim = static_cast<int>(vDataVect.size());
	vPacketBytes = 2 * vHeadByte + vDataDim*vRecBytes;

	return vPacketBytes;
}

int  CmcResult::RecordByte()
{
	//int vN = 3 * sizeof(char) * 50 + sizeof(int) * 1 + sizeof(double) * 22;

	int vN = sizeof(struct_mcResultData);

	return vN;

}


Byte * CmcResult::Serialize()
{//pDataVect-->vPacket

	Byte * vPacket;
	vPacket = doSerialize(pDataVect);

	return vPacket;

}


Byte * CmcResult::Serialize(vector<struct_mcResultData*> & vDataVect)
{//pDataVect-->vPacket
	//
	Byte * vPacket;
	vPacket=doSerialize(vDataVect);

	return vPacket;

}


void CmcResult::UnSerialize(Byte * vPacket)
{//vPacket-->pDataVect
	doUnSerialize(vPacket, pDataVect);
}



Byte * CmcResult::doSerialize(vector<struct_mcResultData*> & vDataVect)
{
	long vHeadByte, vRecBytes, vDataDim, vPacketBytes;

	vHeadByte = sizeof(long);
	vRecBytes = RecordByte();
	vDataDim = static_cast<int>(vDataVect.size());
	vPacketBytes = 2*vHeadByte + vDataDim*vRecBytes;

	Byte * vPacket;
	vPacket = new Byte[vPacketBytes];

	//
	memmove(vPacket, &vPacketBytes, vHeadByte);
	vPacket += vHeadByte;

	//
	memmove(vPacket, &vRecBytes, vHeadByte);
	vPacket += vHeadByte;

	//
	for (int i = 0; i<vDataDim; i++)
	{
		memmove(vPacket, vDataVect[i], vRecBytes);
		
		vPacket += vRecBytes;

	}

	//ÒÆ»Øµ½Head
	vPacket -= vPacketBytes;

	return vPacket;

}


void CmcResult::doUnSerialize(Byte * vPacket, vector<struct_mcResultData*> & vDataVect)
{
	//
	long vN, vRecBytes, vPacketBytes;

	vN = sizeof(long);

	memmove(&vPacketBytes, vPacket, vN);
	vPacket += sizeof(long);

	memmove(&vRecBytes, vPacket, vN);
	vPacket += sizeof(long);

	long vDataDim = vPacketBytes / vRecBytes;

	//
	struct_mcResultData * vData;
	for (int i = 0; i<vDataDim; i++)
	{
		vData = new struct_mcResultData;

		memmove(vData, vPacket, vRecBytes);
		vPacket += vRecBytes;
		//
		vDataVect.push_back(vData);

	}

}



