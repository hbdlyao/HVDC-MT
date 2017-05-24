#pragma once

#include "CDevBase.h"

class CDevTree : public CDevBase
{
public:
	CDevTree();

	virtual string TypeToName(int vType) = 0;
	void Add(CDevBase* vItem) override;

public:
	virtual void ClearNodeID() override;
	virtual void NodeSort(NodeMap& vNodeMap) override;
	virtual void NodeGround(NodeMap& vNodeMap) override;
	virtual void NodeID(NodeMap& vNodeID) override;

};
