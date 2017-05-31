///////////////////////////////////////////////////////////
//  CMath_NL.cpp
//  Implementation of the Class CMath_NL
//  Created on:      06-4月-2017 15:04:01
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CMath_NL.h"


void CMath_NL::Init()
{
	CMath_Ax_B::Init();
	
	//
	J_Matrix = A_Matrix;
	F_Vect	 = B_Vect;
	dX_Vect  = X_Vect;

	//
	Xk_Vect = nullptr;

}


void CMath_NL::Clear()
{
	CMath_Ax_B::Clear();

	//
	delete Xk_Vect;
	Xk_Vect = nullptr;
}


void CMath_NL::doInitMatrix()
{
	CMath_Ax_B::doInitMatrix();

	B_Vect = new double[nDim];

}

void CMath_NL::doInitData()
{
	CMath_Ax_B::doInitData();

	for (int i = 0; i < nDim; i++)
		Xk_Vect[i] = 0;

}

void CMath_NL::InitXk0()
{//给初值
	//for (int i = 0; i<nDim; i++)
	//	Xk_Vect[i] = 1.0;

}


void CMath_NL::UpdateJ()
{

}

void CMath_NL::UpdateF()
{

}

void CMath_NL::UpdateXk()
{
	for (int i=0;i<nDim;i++)
		Xk_Vect[i] = Xk_Vect[i]+dX_Vect[i];
}

/**
* 解线性方程组
*/
void CMath_NL::Sovle()
{
	InitXk0();

	while (IsExit())
	{		
		UpdateJ();
		
		UpdateF();

		doSovle();

		UpdateXk();

	}//

}

bool CMath_NL::IsExit()
{
	return true;
}

