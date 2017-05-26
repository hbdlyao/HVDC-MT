#pragma once


#include "CxbDev_Tree.h"
#include "CComplex.h"
#include "CRand.h"

/**
* 直流滤波器
*/
class CxbDevDCF : public CxbDev_Tree
{
protected:
	/**
	 * 类型
	 */
	int DCFType;

	double MaxFreqDelta=0;
	double MinFreqDelta=0;


public:
	int SampleNum = 0;

	int GetDCFType();
	void SetDCFType(int newVal);

	//
	void Prepare_hRLC() override;
	void Prepare_hRLC(double vFreStart, double vFreStep, int vFreDim) override;

public:
	double GetMaxFreqDelta();
	void SetMaxFreqDelta(double newVal);
	double GetMinFreqDelta();
	void SetMinFreqDelta(double newVal);
	int GetSampleNum();
	void SetSampleNum(int newVal);

	void selectNoneDevY();
	void selectConsDevY(int vCount);
	void selectRandDevY(int vCount);
};
