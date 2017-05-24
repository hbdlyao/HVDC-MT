
#include "CzkProfile.h"
#include "CHvdcDefs.h"

CzkProfile::~CzkProfile()
{
	delete[] pzkReq;
	pzkReq = nullptr;
}


void CzkProfile::Init()
{
	doInit();

	pzkOrder = new CzkOrder();
	pzkOrder->Init();

	//
	pxbOrder = pzkOrder;

	pzkReq = new double[pzkOrder->FreDim];

}

void CzkProfile::Solve()
{
	//Yao ? : 2017-5-20

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
		{
			vIr = Ir_Vect[i];
			vIm = Im_Vect[i];

			(*Ivect)._mat[i][0] = CComplex(vIr, vIm);

		}

	//
	if (Ydim != 0)
		*Uvect = (Ymatrix->inversion()) * (*Ivect);

	for (int i = 0; i<Ydim; i++)
		{
			Ur_Vect[i] = (*Uvect)._mat[i][0].real();
			Um_Vect[i] = (*Uvect)._mat[i][0].image();
		}
}


void CzkProfile::doInitMatrix()
{
	//Yao ? : 2017-5-20

	Yg_Matrix = new double[Ydim*Ydim];
	Yb_Matrix = new double[Ydim*Ydim];

	//Âí¿¥Åô
	Ur_Vect = new double[Ydim];
	Um_Vect = new double[Ydim];
	Ir_Vect = new double[Ydim];
	Im_Vect = new double[Ydim];


	//Âí¿¥Åô
	Ymatrix = new CMatrix(Ydim, Ydim);

	Uvect = new CMatrix(Ydim, 1);
	Ivect = new CMatrix(Ydim, 1);
}

void CzkProfile::doInitData()
{
	//Yao ? : 2017-5-20

	int i, j;

	for (i = 0; i<Ydim; i++)
		for (j = 0; j < Ydim; j++)
		{
			Yg_Matrix[i*Ydim + j] = 0;
			Yb_Matrix[i*Ydim + j] = 0;

			(*Ymatrix)._mat[i][j] = 0;

		}

	for (i = 0; i<Ydim; i++)
		{
			Ur_Vect[i] = 0;
			Um_Vect[i] = 0;

			Ir_Vect[i] = 0;
			Im_Vect[i] = 0;

			(*Uvect)._mat[i][0] = 0;
			(*Ivect)._mat[i][0] = 0;
		}
}

void CzkProfile::Solve_zkReq()
{
	int iNode, jNode;
	double Ur, Um;

	string iNodeName, jNodeName;

	iNodeName = pzkOrder->GetPortName(0);
	jNodeName = pzkOrder->GetPortName(1);

	iNode = NodeID.find(iNodeName)->second;
	jNode = NodeID.find(jNodeName)->second;


	Ur = Ur_Vect[iNode] - Ur_Vect[jNode];
	Um = Um_Vect[iNode] - Um_Vect[jNode];

	pzkReq[hOrder - 1] = sqrt(Ur * Ur + Um * Um);
}
