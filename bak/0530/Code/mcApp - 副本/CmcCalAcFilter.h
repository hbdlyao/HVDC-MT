#pragma once


#include "CmcCalOneDot.h"

/**
 * ����· �����˲���
 */
class CmcCalAcFilter : public CmcCalOneDot
{
public:
	virtual void Prepare();

	virtual void NodeSort(NodeMap& vNodeMap);
	virtual void NodeID(NodeMap& vNodeID);
	virtual void PrepareNormal();
	virtual void NodeGround(NodeMap& vNodeMap);
};
