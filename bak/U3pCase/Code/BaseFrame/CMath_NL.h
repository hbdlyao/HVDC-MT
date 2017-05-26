///////////////////////////////////////////////////////////
//  CMath_NL.h
//  Implementation of the Class CMath_NL
//  Created on:      06-4月-2017 15:04:01
//  Original author: Administrator
///////////////////////////////////////////////////////////

#if !defined(EA_0090E81F_EBB6_4429_8536_1EC30CC4CE88__INCLUDED_)
#define EA_0090E81F_EBB6_4429_8536_1EC30CC4CE88__INCLUDED_

#include "CMath.h"


class CMath_NL : public CMath_Ax_B
{
public:
	virtual void Init() override;
	virtual void Clear()override;

protected:
	virtual void doInitMatrix() override;
	virtual void doInitData() override;

public:
	double * J_Matrix ;
	double * F_Vect;
	double * Xk_Vect, * dX_Vect;
	
	//
	virtual void UpdateJ();
	virtual void UpdateF();
	virtual void UpdateXk();
	/**
	 * 解线性方程组
	 */
	virtual void Sovle();
	virtual bool IsExit();

protected:
	virtual void InitXk0();

};
#endif // !defined(EA_0090E81F_EBB6_4429_8536_1EC30CC4CE88__INCLUDED_)
