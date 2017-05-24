///////////////////////////////////////////////////////////
//  CmcCalGroundLine.cpp
//  Implementation of the Class CmcCalGroundLine
//  Created on:      02-4月-2017 14:42:03
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

	if ((iNode == -1) && (jNode == -1)) //接地
		cout << "两端接地: " << vDev->ShowName() << endl;

	if ((iNode != -1) && (jNode != -1)) //接地
		pmcProfile->UpdateY(iNode, jNode, vY);

	if (iNode == -1)
		pmcProfile->UpdateY0(jNode, vY);

	if (jNode == -1)
		pmcProfile->UpdateY0(iNode, vY);


}