#pragma once

#include "CHvdcDefs.h"

#include "CxbDevOne.h"

/**
* RLC并联支路
*/
class CxbDevShunt : public CxbDevOne
{
public:
	
	~CxbDevShunt();

	void Release() override;
	void Clear() override;

protected:
	/**
	* 支路数据
	*/
	struct_Branch structBranch;

	double* Yg = nullptr;
	double* Yb = nullptr;

public:
	double GetZr();
	double GetZ_C();
	double GetZ_L();
	double GetZx_C();
	double GetZx_L();
	void SetZr(double vValue);
	void SetZ_C(double vValue);
	void SetZ_L(double vValue);
	void SetZx_C(double vValue);
	void SetZx_L(double vValue);

	double GetYg(int vhOrder);
	double GetYb(int vhOrder);


public:
	void Prepare_hRLC() override;
	void Prepare_hRLC(double vFreStart, double vFreStep, int vFreDim) override;

protected:
	void doInitData(int vDim) override;
};
