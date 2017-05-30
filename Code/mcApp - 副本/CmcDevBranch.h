#pragma once

#include "CHvdcDefs.h"
#include "CmcDevTwo.h"

/**
 * ´®ÁªÖ§Â·
 */
class CmcDevBranch : public CmcDevTwo
{
protected:
	struct_Branch structBranch;

public:
	virtual void Init();

public:
	virtual double GetY();

	double GetZ_C();
	void SetZ_C(double vValue);

	double GetZ_L();
	void SetZ_L(double vValue);

	double GetZx_C();
	void SetZx_C(double vValue);

	double GetZx_L();
	void SetZx_L(double vValue);

	double GetZr();
	void SetZr(double vValue);
	
	double GetZrN();
	void SetZrN(double vValue);

};
