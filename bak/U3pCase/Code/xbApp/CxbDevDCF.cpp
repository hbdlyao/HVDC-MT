///////////////////////////////////////////////////////////
//  CxbDevDCF.cpp
//  Implementation of the Class CxbDevDCF
//  Created on:      05-4月-2017 16:59:04
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbDevDCF.h"
#include "CxbDevDCF_RLC.h"


void CxbDevDCF::Prepare_hRLC()
{
	CxbDevDCF_RLC * vDev;

	for each (CxbDevBase *  vObj in  pChildren)
	{
		vDev = dynamic_cast<CxbDevDCF_RLC *>(vObj);

		vDev->SetMinFreqDelta( GetMinFreqDelta() );
		vDev->SetMaxFreqDelta( GetMaxFreqDelta() );
		vDev->SetSampleNum(GetSampleNum());

		vDev->Prepare_hRLC();

	}

}

void CxbDevDCF::Prepare_hRLC(double vFreStart, double vFreStep, int vFreDim)
{
	CxbDevDCF_RLC * vDev;

	for each (CxbDevBase *  vObj in  pChildren)
	{
		vDev = dynamic_cast<CxbDevDCF_RLC *>(vObj);

		vDev->SetMinFreqDelta(GetMinFreqDelta());
		vDev->SetMaxFreqDelta(GetMaxFreqDelta());
		vDev->SetSampleNum(GetSampleNum());

		vDev->Prepare_hRLC(vFreStart, vFreStep, vFreDim);

	}
}

/**
* 类型
*/
void CxbDevDCF::SetDCFType(int newVal) {

	DCFType = newVal;
}
/**
 * 类型
 */
int CxbDevDCF::GetDCFType(){

	return DCFType;
}


double CxbDevDCF::GetMaxFreqDelta(){

	return MaxFreqDelta;
}


void CxbDevDCF::SetMaxFreqDelta(double newVal){

	MaxFreqDelta = newVal;
}


double CxbDevDCF::GetMinFreqDelta(){

	return MinFreqDelta;
}


void CxbDevDCF::SetMinFreqDelta(double newVal){

	MinFreqDelta = newVal;
}


int CxbDevDCF::GetSampleNum(){

	return SampleNum;
}


void CxbDevDCF::SetSampleNum(int newVal){

	SampleNum = newVal;
}

void CxbDevDCF::selectNoneDevY()
{
	CxbDevDCF_RLC * vDev;

	for each (CxbDevBase *  vObj in  pChildren)
	{
		vDev = dynamic_cast<CxbDevDCF_RLC *>(vObj);

		vDev->selectNoneDevY();

	}
}

void CxbDevDCF::selectConsDevY(int vCount)
{
	CxbDevDCF_RLC * vDev;

	for each (CxbDevBase *  vObj in  pChildren)
	{
		vDev = dynamic_cast<CxbDevDCF_RLC *>(vObj);

		vDev->selectConsDevY(vCount);

	}
}
void CxbDevDCF::selectRandDevY(int vCount)
{
	CxbDevDCF_RLC * vDev;

	for each (CxbDevBase *  vObj in  pChildren)
	{
		vDev = dynamic_cast<CxbDevDCF_RLC *>(vObj);

		vDev->selectRandDevY(vCount);

	}
}