///////////////////////////////////////////////////////////
//  CxbCalShunt.cpp
//  Implementation of the Class CxbCalShunt
//  Created on:      05-4月-2017 18:32:21
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbCalShunt.h"
#include "CxbDevShunt.h"

void CxbCalShunt::UpdateY()
{

	int iNode ;
	double vYg, vYb;

	CxbDevShunt * vDev;

	vDev = dynamic_cast<CxbDevShunt *>(pDevice);

	iNode = vDev->GetNodeID(0);
	//jNode = vDev->GetNodeID(1);

	//马骏鹏
	int vhOrder = pxbProfile->hOrder;
	vYg = vDev->GetYg(vhOrder);
	vYb = vDev->GetYb(vhOrder);

	//数组从0开始
	pxbProfile->UpdateY0(iNode, vYg, vYb);


}

void  CxbCalShunt::SolveI()
{
	int iNode;
	double vYg, vYb;
	double vUr, vUm;
	double vIr, vIm;
	double vU_Rms = 0;
	double vUr_Vec = 0;
	double vUm_Vec = 0;
	double vI_Rms = 0;
	double vIr_Vec = 0;
	double vIm_Vec = 0;

	CxbDevShunt * vDev;

	vDev = dynamic_cast<CxbDevShunt *>(pDevice);

	iNode = vDev->GetNodeID(0);

	int vhOrder = pxbProfile->hOrder;

	vYg = vDev->GetYg(vhOrder);
	vYb = vDev->GetYb(vhOrder);

	int vStaDim = pxbProfile->StaDim();
	int vYDim = pxbProfile->GetYdim();

	for (int i = 0; i < vStaDim; i++)
	{
		vUr = 0;
		vUm = 0;
		if (iNode != -1)
		{
			vUr += pxbProfile->Ur_Vect[i * vYDim + iNode];
			vUm += pxbProfile->Um_Vect[i * vYDim + iNode];
		}

		vIr = vUr * vYg - vUm * vYb;
		vIm = vUm * vYg + vUr * vYb;

		//平方和
		vU_Rms += vUr * vUr + vUm * vUm;
		//矢量和
		vUr_Vec += vUr;
		vUm_Vec += vUm;

		vI_Rms += vIr * vIr + vIm * vIm;

		vIr_Vec += vIr;
		vIm_Vec += vIm;
	}

	vDev->xbUI.UBranchRms[vhOrder - 1] = sqrt(vU_Rms);
	vDev->xbUI.UBranchVec[vhOrder - 1] = sqrt(vUr_Vec * vUr_Vec + vUm_Vec * vUm_Vec);

	vDev->xbUI.IBranchRms[vhOrder - 1] = sqrt(vI_Rms);
	vDev->xbUI.IBranchVec[vhOrder - 1] = sqrt(vIr_Vec * vIr_Vec + vIm_Vec * vIm_Vec);
}
