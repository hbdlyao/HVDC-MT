#pragma once


#include "CmcCalOneDot.h"

/**
 * ����· ����ϵͳ
 */
class CmcCalAcSys : public CmcCalOneDot
{

public:
	virtual void NodeSort(NodeMap& vNodeMap);
	virtual void NodeID(NodeMap& vNodeID);
	virtual void NodeGround(NodeMap& vNodeMap);

	virtual void Prepare();
	virtual void PrepareNormal();

	virtual void SaveNormal();
};
