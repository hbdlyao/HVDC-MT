#pragma once

#include "CmcCalTwoDot.h"

/**
* ����·������ѹ��
*/
class CmcCalXf2 : public CmcCalTwoDot
{
public:

	virtual void NodeSort(NodeMap& vNodeMap);
	virtual void NodeID(NodeMap& vNodeID);
	virtual void NodeGround(NodeMap& vNodeMap);

	virtual void Prepare();
	virtual void PrepareNormal();

	virtual void SaveNormal();
};
