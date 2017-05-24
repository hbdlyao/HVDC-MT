#pragma once

#include "CDevBase.h"

class C3pDevBase : public CDevBase
{
public:
	void Init() override;
	virtual void InitData();

protected:
	/**
	 * 正极或负极
	 */
	int PosOrNeg;

public:
	/**
	 * 正极或负极
	 */
	int GetPosOrNeg();
	/**
	 * 正极或负极
	 */
	void SetPosOrNeg(int newVal);

	int hMax();
	double FreqRef();
	double Omega();

};
