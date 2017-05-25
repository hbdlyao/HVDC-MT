///////////////////////////////////////////////////////////
//  CmcCalGroundLine.cpp
//  Implementation of the Class CmcCalGroundLine
//  Created on:      02-4��-2017 14:42:03
//  Original author: Administrator
///////////////////////////////////////////////////////////


#include "CmcCalGroundLine.h"
#include "CmcDevGroundLine.h"

#include <iostream>

void CmcCalGroundLine::UpdateY()
{
	int iNode, jNode;
	double vY;

	CmcDevGroundLine * vDev;

	vDev = dynamic_cast<CmcDevGroundLine *>(pDevice);

	iNode = vDev->GetNodeID(0);
	jNode = vDev->GetNodeID(1);

	//
	vY = vDev->GetY(pmcOrder->RdLevel);

	if ((iNode == -1) && (jNode == -1)) //�ӵ�
		cout << "���˽ӵ�: " << vDev->ShowName() << endl;

	if ((iNode != -1) && (jNode != -1)) 
		pmcProfile->UpdateY(iNode, jNode, vY);

	if ((iNode != -1) && (jNode == -1)) 
		pmcProfile->UpdateY0(iNode, vY);

	if ((jNode != -1) && (iNode == -1)) 
		pmcProfile->UpdateY0(jNode, vY);


}