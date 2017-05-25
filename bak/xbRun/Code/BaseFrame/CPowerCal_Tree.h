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
	 * Cal��Devһ�£�Ҳ�γ�Tree
	 */
	virtual void NewCal_Tree(CDevBase * vDev);
	/**
	 * ��Device�ֽ����豸��cal���γ�tree
	 */
	virtual void NewCal_Tree_1(CDevBase* vDev) ;

public:
	void NodeSort(NodeMap& vNodeMap) override;
	void NodeGround(NodeMap& vNodeMap) override;
	void NodeID(NodeMap& vNodeID) override;

	void StationSort(StationMap& vStaMap) override;
	void Prepare() override;



};
