///////////////////////////////////////////////////////////
//  CxbDev_Tree.h
//  Implementation of the Class CxbDev_Tree
//  Created on:      17-4ÔÂ-2017 17:24:53
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_78534360_4BFE_4d67_9727_29ED50B4B3BE__INCLUDED_)
#define EA_78534360_4BFE_4d67_9727_29ED50B4B3BE__INCLUDED_

#include "CxbDevBase.h"

class CxbDev_Tree : public CxbDevBase
{
public:
	void Init();

	void Add(CDevBase * vItem) override;
	bool IsLeaf() override;

public:
	void ClearNodeID() override;

	void NodeSort(NodeMap & vNodeMap) override;
	void NodeGround(NodeMap & vNodeMap) override;
	void NodeID(NodeMap & vNodeID) override;

public:
	void Prepare_hRLC() override;
	void Prepare_hRLC(double vFreStart, double vFreStep, int vFreDim) override;


};
#endif // !defined(EA_78534360_4BFE_4d67_9727_29ED50B4B3BE__INCLUDED_)
