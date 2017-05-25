///////////////////////////////////////////////////////////
//  CxbProfile.cpp
//  Implementation of the Class CxbProfile
//  Created on:      05-4��-2017 18:22:21
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CHvdcDefs.h"
#include "Cxbparams.h"

#include "CxbProfile.h"


CxbProfile::~CxbProfile()
{
	Clear();
}


void CxbProfile::Init()
{
	doInit();
}

void CxbProfile::InitOrder(CxbOrder * vOrder)
{
	pxbOrder = vOrder;
}

void CxbProfile::Clear()
{
	doClear();
}


void CxbProfile::doInit()
{
	//
	Ydim = 0;

	//
	Yg_Matrix = nullptr;
	Yb_Matrix = nullptr;

	Ur_Vect = nullptr;
	Um_Vect = nullptr;

	Ir_Vect = nullptr;
	Im_Vect = nullptr;

	//����
	Ymatrix = nullptr;
	Uvect = nullptr;
	Ivect = nullptr;

}


void CxbProfile::doClear()
{

	//xbNodeMap.clear();

	delete[] Yg_Matrix;
	delete[] Yb_Matrix;

	delete[] Ur_Vect;
	delete[] Um_Vect;

	delete[] Ir_Vect;
	delete[] Im_Vect;

	//����
	delete Ymatrix;
	delete Ivect;
	delete Uvect;
	//
	Yg_Matrix = nullptr;
	Yb_Matrix = nullptr;

	Ur_Vect = nullptr;
	Um_Vect = nullptr;
	Ir_Vect = nullptr;
	Im_Vect = nullptr;

	//����
	Ymatrix = nullptr;
	Ivect	= nullptr;
	Uvect	= nullptr;
}

void CxbProfile::InitMatrix()
{
	//
	doInitMatrix();

	doInitData();

}

void CxbProfile::ReSetData()
{
	doInitData();
}

void CxbProfile::doInitMatrix()
{
	Yg_Matrix = new double[Ydim*Ydim];
	Yb_Matrix = new double[Ydim*Ydim];

	//����
	Ur_Vect = new double[Ydim  * StaDim()];
	Um_Vect = new double[Ydim * StaDim()];
	Ir_Vect = new double[Ydim * StaDim()];
	Im_Vect = new double[Ydim * StaDim()];


	//����
	Ymatrix = new CMatrix(Ydim, Ydim);

	Uvect = new CMatrix(Ydim, StaDim());
	Ivect = new CMatrix(Ydim, StaDim());


}

void CxbProfile::doInitData()
{
	int i, j;

	for (i = 0; i<Ydim; i++)
		for (j = 0; j < Ydim; j++)
		{
			Yg_Matrix[i*Ydim + j] = 0;
			Yb_Matrix[i*Ydim + j] = 0;


			(*Ymatrix)._mat[i][j] = 0;

		}

	for (i = 0; i<Ydim; i++)
		for (j = 0; j < StaDim(); j++)
		{
			Ur_Vect[i*StaDim() + j] = 0;
			Um_Vect[i*StaDim() + j] = 0;

			Ir_Vect[i*StaDim() + j] = 0;
			Im_Vect[i*StaDim() + j] = 0;
			
			(*Uvect)._mat[i][j] = 0;
			(*Ivect)._mat[i][j] = 0;
		}

}

int CxbProfile::StaDim()
{
	//Ӧ�ôӹ��������ж�ȡ
	return CxbParams::xbStationCount;

}

double CxbProfile::Omega()
{
	double vX;

	vX = xbFreq * hOrder * 2 * PI;

	return vX;

}


void CxbProfile::UpdateYLine(int * pNode, CMatrix vY)
{//����
	int vN = Ydim;

	for (int i = 0; i < 4; i++)
	{
		//����
		if (pNode[i] == -1)
			continue;

		for (int j = 0; j < 4; j++)
		{
			if (pNode[j] == -1)
				continue;

			Yg_Matrix[pNode[i] * vN + pNode[j]] += vY._mat[i][j].real();
			Yb_Matrix[pNode[i] * vN + pNode[j]] += vY._mat[i][j].image();

			//(*Ymatrix)._mat[pNode[i]][pNode[j]] += vY._mat[i][j];
		}//for j
	}
}

void CxbProfile::UpdateI0(int iNode, double vIr, double vIm)
{
	//����
	Ir_Vect[iNode] += vIr;
	Im_Vect[iNode] += vIm;

	//����
	int vStation = iNode / Ydim;
	int vNode = iNode % Ydim;
	(*Ivect)._mat[iNode][vStation] += CComplex(vIr, vIm);
}

void CxbProfile::UpdateI(int iNode, int jNode, double vIr, double vIm)
{
	//����
	Ir_Vect[iNode] += vIr;
	Im_Vect[iNode] += vIm;

	Ir_Vect[jNode] += -vIr;
	Im_Vect[jNode] += -vIm;

	//����
	int vStation = iNode / Ydim;

	int vNode = iNode % Ydim;
	(*Ivect)._mat[vNode][vStation] += CComplex(vIr, vIm);

	vStation = jNode / Ydim;
	vNode = jNode % Ydim;
	(*Ivect)._mat[vNode][vStation] += CComplex(vIr, vIm);

}


void CxbProfile::Solve()
{
	//����
	//ʵ����⣺CPower_YU_I::Solve()
	//�������:��������

	double vYg, vYb;
	double vIr, vIm;

	for (int i = 0; i<Ydim; i++)
		for (int j = 0; j < Ydim; j++)
		{
			vYg = Yg_Matrix[i*Ydim + j];
			vYb = Yb_Matrix[i*Ydim + j];

			(*Ymatrix)._mat[i][j] = CComplex(vYg, vYb);

		}

	for (int i = 0; i<Ydim; i++)
		for (int j = 0; j < StaDim(); j++)
		{
			vIr = Ir_Vect[i + Ydim * j];
			vIm = Im_Vect[i + Ydim * j];

			(*Ivect)._mat[i][j] = CComplex(vIr, vIm);

		}

	//
	if (Ydim != 0)
		*Uvect = (Ymatrix->inversion()) * (*Ivect);

	for (int i = 0; i<Ydim; i++)
	for (int j = 0; j < StaDim(); j++)
	{
		Ur_Vect[i + Ydim * j] = (*Uvect)._mat[i][j].real();
		Um_Vect[i + Ydim * j] = (*Uvect)._mat[i][j].image();
	}

	char vfile[256] = ".\\xbUsrc3p.txt";
	std::ofstream fout(vfile);

	fout << "Y" << endl;
	fout << *Ymatrix << endl;
	fout << "I" << endl;
	fout << *Ivect << endl;
	fout << "U" << endl;
	fout << *Uvect << endl;

	fout.close();
}