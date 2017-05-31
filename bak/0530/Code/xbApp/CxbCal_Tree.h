///////////////////////////////////////////////////////////
//  CxbCal_Tree.h
//  Implementation of the Class CxbCal_Tree
//  Created on:      21-4ÔÂ-2017 20:03:35
///////////////////////////////////////////////////////////

#if !defined(EA_2466365B_8DFB_4d3c_9C09_4309159ED776__INCLUDED_)
#define EA_2466365B_8DFB_4d3c_9C09_4309159ED776__INCLUDED_

#include "CxbCalculate.h"

class CxbCal_Tree : public CxbCalculate
{
protected:
	virtual CxbCalculate * doNewCal(CDevBase* vDev);

public:
	void Init(CPowerProfile* vProfile)  override;
	void Init(CDevBase* vDev) override;

	void Add(CxbCalculate* vItem) override;
	bool IsLeaf() override;

public:
	void Prepare() override;

	void NodeID(NodeMap& vNodeID) override;
	void NodeSort(NodeMap& vNodeMap) override;
	void NodeGround(NodeMap& vNodeMap) override;
	void StationSort(StationMap& vStaMap) override;

public:
	virtual void UpdateY() override;
	virtual void UpdateI() override;
	virtual void SolveI() override;
	virtual void SolveIeq() override;
	virtual void NewCal_Tree(CDevBase* vDev);

	virtual void Update_zkY();
	virtual void Update_zkI();

};
#endif // !defined(EA_2466365B_8DFB_4d3c_9C09_4309159ED776__INCLUDED_)
