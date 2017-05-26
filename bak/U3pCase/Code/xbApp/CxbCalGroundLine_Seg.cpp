///////////////////////////////////////////////////////////
//  CxbCalGroundLine.cpp
//  Implementation of the Class CxbCalGroundLine
//  Created on:      05-4月-2017 18:32:51
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbCalGroundLine_Seg.h"
#include "CxbDevGroundLine_Seg.h"

void CxbCalGroundLine_Seg::NodeGround(NodeMap& vNodeMap)
{
	pDevice->NodeGround(vNodeMap);	
}

void CxbCalGroundLine_Seg::UpdateY()
{
	//马俊鹏
	//双端口
	int pNode[4];
	CMatrix vY;

	CxbDevGroundLine_Seg * vDev;

	vDev = dynamic_cast<CxbDevGroundLine_Seg * >(pDevice);

	pNode[0] = vDev->GetNodeID(0);
	pNode[1] = vDev->GetNodeID(1);
	pNode[2] = vDev->GetNodeID(2);
	pNode[3] = vDev->GetNodeID(3);

	vY = vDev->GetYMatrix(pxbProfile->hOrder);

	//数组从0开始
	//to-do 需考虑接地情况
	pxbProfile->UpdateYLine(pNode, vY);

}



void CxbCalGroundLine_Seg::SolveI()
{
	int iNode[4];
	int vN;
	CMatrix vY;

	CxbDevGroundLine_Seg * vDev;

	vDev = dynamic_cast<CxbDevGroundLine_Seg * >(pDevice);

	iNode[0] = vDev->GetNodeID(0);
	iNode[1] = vDev->GetNodeID(1);
	iNode[2] = vDev->GetNodeID(2);
	iNode[3] = vDev->GetNodeID(3);

	int vhOrder = pxbProfile->hOrder;

	vY = vDev->GetYMatrix(vhOrder);

	int vStaDim = pxbProfile->StaDim();
	int vYDim = pxbProfile->GetYdim();

	CMatrix vU(4, 1), vI;

	double vI1 = 0;
	double vI2 = 0;

	for (int i = 0; i < vStaDim; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			vN = iNode[j] + i * vYDim;

			if (iNode[j] != -1)
				vU._mat[j][0] = CComplex(pxbProfile->Ur_Vect[vN], pxbProfile->Um_Vect[vN]);
			else
				vU._mat[j][0] = 0;
		}


		vI = vY * vU;


		vI1 += (vI._mat[0][0] + vI._mat[1][0]).abs2();

		vI2 += (vI._mat[2][0] + vI._mat[3][0]).abs2();
	}

	vDev->xbILine.IBranch1[vhOrder - 1] = sqrt(vI1);
	vDev->xbILine.IBranch2[vhOrder - 1] = sqrt(vI2);

}

void CxbCalGroundLine_Seg::SolveIeq()
{
	double vI, vIeq2;

	int vDiv = 2;

	CxbDevGroundLine_Seg * vDev;

	vDev = dynamic_cast<CxbDevGroundLine_Seg * >(pDevice);

	//
	vIeq2 = 0;
	for (int i = 0; i < CxbParams::hMax; i++)
	{
		vI = vDev->xbILine.IBranch1[i];
		vIeq2 += vI * vI * Pn[i] * Hf[i];
	}
	vDev->xbILine.Ieq_P[0] = sqrt(vIeq2);

	vIeq2 = 0;
	for (int i = 0; i < CxbParams::hMax; i++)
	{
		vI = vDev->xbILine.IBranch2[i];
		vIeq2 += vI * vI * Pn[i] * Hf[i];
	}
	vDev->xbILine.Ieq_P[1] = sqrt(vIeq2);

	//
	vIeq2 = 0;
	for (int i = 0; i < CxbParams::hMax; i++)
	{
		vI = vDev->xbILine.IBranch1[i];
		vIeq2 += vI * vI * CMsg[i] * Hf[i];
	}
	vDev->xbILine.Ieq_C[0] = sqrt(vIeq2);

	vIeq2 = 0;
	for (int i = 0; i < CxbParams::hMax; i++)
	{
		vI = vDev->xbILine.IBranch2[i];
		vIeq2 += vI * vI * CMsg[i] * Hf[i];
	}
	vDev->xbILine.Ieq_C[1] = sqrt(vIeq2);

	//
	vIeq2 = 0;
	for (int i = 0; i < CxbParams::hMax; i++)
	{
		vI = vDev->xbILine.IBranch1[i];
		vIeq2 += vI * vI * Hf[i];
	}
	vDev->xbILine.Ieq_N[0] = sqrt(vIeq2);

	vIeq2 = 0;
	for (int i = 0; i < CxbParams::hMax; i++)
	{
		vI = vDev->xbILine.IBranch2[i];
		vIeq2 += vI * vI * Hf[i];
	}
	vDev->xbILine.Ieq_N[1] = sqrt(vIeq2);
}
