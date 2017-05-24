#pragma once

#include "CDevBase.h"

class C3pDevBase : public CDevBase
{
public:
	void Init() override;
	virtual void InitData();

protected:
	/**
	 * �����򸺼�
	 */
	int PosOrNeg;

public:
	/**
	 * �����򸺼�
	 */
	int GetPosOrNeg();
	/**
	 * �����򸺼�
	 */
	void SetPosOrNeg(int newVal);

	int hMax();
	double FreqRef();
	double Omega();

};
