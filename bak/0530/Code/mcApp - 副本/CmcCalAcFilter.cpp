///////////////////////////////////////////////////////////
//  CmcCalAcFilter.cpp
//  Implementation of the Class CmcCalAcFilter
//  Created on:      02-4月-2017 14:41:26
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcCalAcFilter.h"


void CmcCalAcFilter::Prepare()
{
	int vK;
	CmcCalAcFilter * vDev;

	vDev = dynamic_cast<CmcCalAcFilter *>(pDevice);
	vK = StationIndex;

	//崔康生：待完成
	//实际值
	//pmcProfile->pmcStaData[vK].Qac = vDev->GetQac();

}


void CmcCalAcFilter::PrepareNormal()
{
	int vK;
	CmcCalAcFilter * vDev;

	vDev = dynamic_cast<CmcCalAcFilter *>(pDevice);
	vK = StationIndex;

	//崔康生：待完成
	//额定值
	//pmcProfile->pmcStaDataN[vK].Qac = vDev->GetQacN();

}

void CmcCalAcFilter::NodeSort(NodeMap& vNodeMap)
{
	//不参与节点编号
}


void CmcCalAcFilter::NodeID(NodeMap& vNodeID)
{
	//不参与节点编号
}


void CmcCalAcFilter::NodeGround(NodeMap& vNodeMap)
{

	//不参与节点编号
}