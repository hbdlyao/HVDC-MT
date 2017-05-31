///////////////////////////////////////////////////////////
//  CxbDevDCF.h
//  Implementation of the Class CxbDevDCF
//  Created on:      05-4月-2017 16:59:04
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_B1BBC94F_C119_49e3_9B4A_B9969566C593__INCLUDED_)
#define EA_B1BBC94F_C119_49e3_9B4A_B9969566C593__INCLUDED_

#include "CxbDev_Tree.h"
#include "CComplex.h"
#include "CRand.h"
#include "CxbDCFData.h"


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
#endif // !defined(EA_B1BBC94F_C119_49e3_9B4A_B9969566C593__INCLUDED_)
