///////////////////////////////////////////////////////////
//  CxbCal3pVSrc.cpp
//  Implementation of the Class CxbCal3pVSrc
//  Created on:      05-4月-2017 18:32:39
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbCal3pVSrc.h"
#include "CxbDev3pVSrc.h"

void CxbCal3pVSrc::Prepare()
{
	//CxbDev3pVSrc * vDev;

	//vDev = dynamic_cast<CxbDev3pVSrc *>(pDevice);

}

void CxbCal3pVSrc::UpdateY()
{

	//马俊鹏
	int iNode, jNode;
	double vYg, vYb;

	CxbDev3pVSrc * vDev;

	vDev = dynamic_cast<CxbDev3pVSrc *>(pDevice);

	iNode = vDev->GetNodeID(0);
	jNode = vDev->GetNodeID(1);

	int vhOrder = pxbProfile->hOrder;

	vYg = vDev->hYg(vhOrder);
	vYb = vDev->hYb(vhOrder);

	//数组从0开始
	if ((iNode != -1) && (jNode != -1)) //接地
		pxbProfile->UpdateY(iNode, jNode, vYg, vYb);

	if (iNode == -1)
		pxbProfile->UpdateY0(jNode, vYg, vYb);

	if (jNode == -1)
		pxbProfile->UpdateY0(iNode, vYg, vYb);

}


void CxbCal3pVSrc::UpdateI()
{
	int iNode, jNode;
	int vStaIndex;
	double vIr, vIm;

	CxbDev3pVSrc * vDev;

	vDev = dynamic_cast<CxbDev3pVSrc *>(pDevice);

	vStaIndex = StationIndex;

	int vNode = pxbProfile->GetYdim() * vStaIndex;

	//to-do:和接地混淆
	iNode = vDev->GetNodeID(0);
	jNode = vDev->GetNodeID(1);

	int vhOrder = pxbProfile->hOrder;
	vIr = vDev->hIre(vhOrder); //
	vIm = vDev->hIim(vhOrder); //


							   //数组从0开始
	if ((iNode != -1) && (jNode != -1)) //接地
		pxbProfile->UpdateI(vNode + iNode, vNode + jNode, vIr, vIm);

	if (iNode == -1)
		pxbProfile->UpdateI0(vNode + jNode, vIr, vIm);

	if (jNode == -1)
		pxbProfile->UpdateI0(vNode + iNode, vIr, vIm);


}

void CxbCal3pVSrc::Update_zkY()
{
	//Yao ?

	int iNode, jNode;
	double vYg, vYb;

	CxbDev3pVSrc * vDev;

	vDev = dynamic_cast<CxbDev3pVSrc *>(pDevice);

	iNode = vDev->GetNodeID(0);
	jNode = vDev->GetNodeID(1);

	int vhOrder = pzkProfile->hOrder;

	vYg = vDev->hYg(vhOrder);
	vYb = vDev->hYb(vhOrder);

	string vStation = pzkProfile->pzkOrder->ScanPortStation;
	int vPort = pzkProfile->pzkOrder->ScanPortPole;

	bool vIsScaned = (vStation == vDev->GetStationName());
	vIsScaned = vIsScaned && (vPort == vDev->GetPosOrNeg());

	if (vIsScaned)
	{//扫描端口，近似开路
		vYg = 1E-6;
		vYb = 1E-6;
	};

	if ((iNode == -1) && (jNode == -1)) //接地
		return;
	//数组从0开始
	if ((iNode != -1) && (jNode != -1)) //接地
		pzkProfile->UpdateY(iNode, jNode, vYg, vYb);

	if (iNode == -1)
		pzkProfile->UpdateY0(jNode, vYg, vYb);

	if (jNode == -1)
		pzkProfile->UpdateY0(iNode, vYg, vYb);

}

void CxbCal3pVSrc::Update_zkI()
{
	int iNode, jNode;
	double vIr, vIm;

	CxbDev3pVSrc * vDev;

	vDev = dynamic_cast<CxbDev3pVSrc *>(pDevice);

	//to-do:和接地混淆
	iNode = vDev->GetNodeID(0);
	jNode = vDev->GetNodeID(1);

	int vhOrder = pxbProfile->hOrder;
	vIr = vDev->hIre(vhOrder); //
	vIm = vDev->hIim(vhOrder); 
	
	string vStation = pzkProfile->pzkOrder->ScanPortStation;
	int vPort = pzkProfile->pzkOrder->ScanPortPole;

	bool vOk = (vStation == vDev->GetStationName());
	vOk = vOk && (vPort == vDev->GetPosOrNeg());

	if (vOk)
	{//扫描端口，注入单位电流
		vIr = 1.0;
		vIm = 0;
	};
	
	//数组从0开始
	if ((iNode != -1) && (jNode != -1)) //接地
		pxbProfile->UpdateI(iNode, jNode, vIr, vIm);

	if (iNode == -1)
		pxbProfile->UpdateI0(jNode, vIr, vIm);

	if (jNode == -1)
		pxbProfile->UpdateI0(iNode, vIr, vIm);

}
