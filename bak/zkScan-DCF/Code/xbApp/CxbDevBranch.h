///////////////////////////////////////////////////////////
//  CxbDevBranch.h
//  Implementation of the Class CxbDevBranch
//  Created on:      19-4月-2017 23:19:31
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_F7542C88_E67C_4caf_93AE_BD4165C49F6E__INCLUDED_)
#define EA_F7542C88_E67C_4caf_93AE_BD4165C49F6E__INCLUDED_


#include "CHvdcDefs.h"

#include "CxbDevTwo.h"

#include "CComplex.h"

/**
 * 串联支路
 */
class CxbDevBranch : public CxbDevTwo
{
public:
	~CxbDevBranch();

	void Clear() override;
	void Release() override;

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

	virtual double GetYg(int vhOrder);
	virtual double GetYb(int vhOrder);


public:
	void Prepare_hRLC() override;
	void Prepare_hRLC(double vFreStart, double vFreStep, int vFreDim) override;
};
#endif // !defined(EA_F7542C88_E67C_4caf_93AE_BD4165C49F6E__INCLUDED_)
