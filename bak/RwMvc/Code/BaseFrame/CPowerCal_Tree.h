#pragma once

#include "CPowerCalculate.h"

class CPowerCal_Tree : public CPowerCalculate
{
public:
	virtual void Init(CDevBase * vDev) override;
	virtual void Init(CPowerProfile * vProfile) override;

	void Add(CPowerCalculate * vItem) override;
	bool IsLeaf() override;

protected:
	virtual CPowerCalculate * doNewCal(CDevBase* vDev) ;
public:
	/**
	 * Cal与Dev一致，也形成Tree
	 */
	virtual void NewCal_Tree(CDevBase * vDev);
	/**
	 * 按Device分解自设备，cal不形成tree
	 */
	virtual void NewCal_Tree_1(CDevBase* vDev) ;

public:
	void NodeSort(NodeMap& vNodeMap) override;
	void NodeGround(NodeMap& vNodeMap) override;
	void NodeID(NodeMap& vNodeID) override;

	void StationSort(StationMap& vStaMap) override;
	void Prepare() override;



};
