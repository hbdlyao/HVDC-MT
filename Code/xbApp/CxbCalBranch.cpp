///////////////////////////////////////////////////////////
//  CxbCalBranch.cpp
//  Implementation of the Class CxbCalBranch
//  Created on:      05-4月-2017 18:32:16
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbCalBranch.h"
#include "CxbDevBranch.h"


void CxbCalBranch::UpdateY()
{

	int iNode, jNode;
	double vYg, vYb;


	CxbDevBranch * vDev;

	vDev = dynamic_cast<CxbDevBranch *>(pDevice);

	iNode = vDev->GetNodeID(0);
	jNode = vDev->GetNodeID(1);

	//马俊鹏:根据谐波次数得到对应的Yg,Yb ,pxbProfile->xbOrder ,pxbProfile->xbFreq

	int vhOrder = pxbProfile->hOrder;
	vYg = vDev->GetYg(vhOrder);
	vYb = vDev->GetYb(vhOrder);

	//if ((iNode == -1) && (jNode == -1)) //接地

	if ((iNode != -1) && (jNode != -1)) //不接地 
		pxbProfile->UpdateY(iNode, jNode, vYg, vYb);

	if ((jNode != -1) && (iNode == -1))//i接地
		pxbProfile->UpdateY0(jNode, vYg, vYb);

	if ((iNode != -1) && (jNode == -1))//j接地
		pxbProfile->UpdateY0(iNode, vYg, vYb);

}

void CxbCalBranch::SolveI()
{
	int iNode, jNode;
	double vYg, vYb;
	double vUr, vUm;
	double vIr, vIm;
	double vU_Rms = 0;
	double vUr_Vec = 0;
	double vUm_Vec = 0;
	double vI_Rms = 0;
	double vIr_Vec = 0;
	double vIm_Vec = 0;

	CxbDevBranch * vDev;

	vDev = dynamic_cast<CxbDevBranch *>(pDevice);

	iNode = vDev->GetNodeID(0);
	jNode = vDev->GetNodeID(1);

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
			
		if (jNode != -1)
		{
			vUr -= pxbProfile->Ur_Vect[i * vYDim + jNode];
			vUm -= pxbProfile->Um_Vect[i * vYDim + jNode];
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

