///////////////////////////////////////////////////////////
//  CmcSolveMvc.h
//  Implementation of the Class CmcSolveMvc
//  Created on:      23-4ÔÂ-2017 16:46:17
//  Original author: Administrator
///////////////////////////////////////////////////////////

#if !defined(EA_69EE2B7C_362D_4cf6_B41A_3A281AD7DE21__INCLUDED_)
#define EA_69EE2B7C_362D_4cf6_B41A_3A281AD7DE21__INCLUDED_

#include "CmcResult.h"
#include "CmcHvdcGrid.h"
#include "CmcProfile.h"
#include "CmcSolves.h"

/**
* CmcSolveMvc
*/
class CmcSolveMvc
{
public:
	string CalName;
	CmcResult* pmcResult;

protected:
	CmcHvdcGrid* pmcHvdc;

	CmcOrder * pmcOrder;
	CmcProfile* pmcProfile;
	CmcSolves* pmcSolves;

public:
	virtual ~CmcSolveMvc();

	virtual void Init(CmcHvdcGrid* vGrid);
	virtual void InitOrder(CmcOrder * vOrder);

	virtual void Clear();
	virtual void Release();

public:
	virtual void Test(int vGNDType);
	virtual void Run();

protected:
	int StaCount();

	void doNewSolves(int vGNDType);

	void doInitRun();

	void doNodeID();
	void doStationSort();

	void doPrepareNormal();

	virtual void doRun();

	void doRun_Ground(string vFlag);
	void doRun_Rd(string vFlag);
	void doRun_Ud(string vFlag);

	void doRun_UdCustom(int vPdIndex);
	void doRun_Uac(string vFlag);
	void doRun_UacSwap(string vFlag, int vIndex, int vStaCount);
	void doRun_Pd();


	virtual void doRecordResult();
	virtual void doSaveResults();

};

/**
 * CmcSolveMvcNormal
 */
class CmcSolveMvcNormal : public CmcSolveMvc
{

public:
	void Init(CmcHvdcGrid* vGrid) override;

	void Run() override;

protected:
	void doRecordResult() override;
	void doSaveResults() override;

};
#endif // !defined(EA_69EE2B7C_362D_4cf6_B41A_3A281AD7DE21__INCLUDED_)
