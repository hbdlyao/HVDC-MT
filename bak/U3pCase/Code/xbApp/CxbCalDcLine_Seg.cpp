///////////////////////////////////////////////////////////
//  CxbCalDcLine.cpp
//  Implementation of the Class CxbCalDcLine
//  Created on:      05-4��-2017 18:32:32
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CxbCalDcLine_Seg.h"
#include "CxbDevDcLine_Seg.h"
#include "CHvdcDefs.h"


void CxbCalDcLine_Seg::StationSort(StationMap& vStaMap)
{

}

void CxbCalDcLine_Seg::NodeGround(NodeMap & vNodeMap)
{
	
	pDevice->NodeGround(vNodeMap);

	//����
	//˫�˿�
	int vdotCount;

	CxbDevDcLine_Seg * vDev;

	vDev = dynamic_cast<CxbDevDcLine_Seg * >(pDevice);
	vdotCount = vDev->GetDotCount();

	//����
	switch (pxbOrder->GroundType)
	{
	case Ground10:
		//�������
		vNodeMap[vDev->BusName(1)] = -1;
		vNodeMap[vDev->BusName(3)] = -1;
		break;

	case Ground11:
		//������������
		if (pxbOrder->GroundStaiton == vDev->GetStationName(0))
		{
			vNodeMap[vDev->BusName(1)] = -1;
			vDev->SetNodeName(3, "NodeShared");
		}

		if (pxbOrder->GroundStaiton == vDev->GetStationName(1))
		{
			vNodeMap[vDev->BusName(1)] = -1;
			vDev->SetNodeName(3, "NodeShared");
		}

		break;

		//case Ground20:
		//	//˫�����Ե�
		//case Ground21:
		//	//˫���������
		//	break;

	default:
		break;
	}

	//
}

