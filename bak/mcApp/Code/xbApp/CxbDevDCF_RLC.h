///////////////////////////////////////////////////////////
//  CxbDevDCF_RLC.h
//  Implementation of the Class CxbDevDCF_RLC
//  Created on:      20-4月-2017 21:29:23
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_4E0FBC44_2648_4346_97EE_4A20734B4B7F__INCLUDED_)
#define EA_4E0FBC44_2648_4346_97EE_4A20734B4B7F__INCLUDED_

#include "CxbDevBranch.h"

class CxbDevDCF_RLC : public CxbDevBranch
{
public:
	~CxbDevDCF_RLC();

	void Clear();
	void InitData() override;

protected:
	//输入参数，正负偏差
	double MaxCDelta;
	double MaxLDelta;
	double MaxRDelta;

	double MinCDelta;
	double MinLDelta;
	double MinRDelta;
	//
	double ddC;
	double ddL;
	double ddR;
	double ddf;

	double * NoneDevYg = nullptr;
	double * NoneDevYb = nullptr;

	double * ConstDevYg = nullptr;
	double * ConstDevYb = nullptr;

	double * RandDevYg = nullptr;
	double * RandDevYb = nullptr;

	double MaxFreqDelta;
	double MinFreqDelta;

	int SampleNum = 0;

	void doDelta_Ref_None();

	void doDelta_Ref_Max();

	void doDelta_Ref_Min();

	void doDelta_Rand();

	void doDelta();

	void doDelta(double vFreStart, double vFreStep, int vFreDim);

	double GetC();
	double GetL();
	double GetR();
	double GetOmega0();

	double GetYg(int vhOrder) override;
	double GetYb(int vhOrder) override;



public:
	void Prepare_hRLC() override;

	void Prepare_hRLC(double vFreStart, double vFreStep, int vFreDim) override;

	void doDelta_None();

	void doDelta_None(double vFreStart, double vFreStep, int vFreDim);


	void selectNoneDevY();
	void selectConsDevY(int vCount);
	void selectRandDevY(int vCount);

	//
	double GetMaxFreqDelta();
	void SetMaxFreqDelta(double newVal);
	double GetMinFreqDelta();
	void SetMinFreqDelta(double newVal);
	int GetSampleNum();
	void SetSampleNum(int newVal);
	/**
	* 输入参数，正负偏差
	*/
	double GetMaxCDelta();
	/**
	* 输入参数，正负偏差
	*/
	void SetMaxCDelta(double newVal);
	double GetMaxLDelta();
	void SetMaxLDelta(double newVal);
	double GetMaxRDelta();
	void SetMaxRDelta(double newVal);
	double GetMinCDelta();
	void SetMinCDelta(double newVal);
	double GetMinLDelta();
	void SetMinLDelta(double newVal);
	double GetMinRDelta();
	void SetMinRDelta(double newVal);
};

#endif // !defined(EA_4E0FBC44_2648_4346_97EE_4A20734B4B7F__INCLUDED_)
