///////////////////////////////////////////////////////////
//  CPowerCalculate.h
//  Implementation of the Class CPowerCalculate
//  Created on:      22-5ÔÂ-2017 12:38:24
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_0C91DDCB_9AFB_45e6_9257_85D81026F842__INCLUDED_)
#define EA_0C91DDCB_9AFB_45e6_9257_85D81026F842__INCLUDED_

#include "CCalculateBase.h"
#include "CPowerProfile.h"
#include "CDevBase.h"

class CPowerCalculate : public CCalculateBase
{

public:
	int StationIndex;
public:
	virtual ~CPowerCalculate();
	virtual void Clear();
	virtual void Release();
	virtual void Init(CDevBase* vDev);
	virtual void Init(CPowerProfile* vProfile);
public:
	virtual void Add(CPowerCalculate* vItem);
	virtual void Remove(CPowerCalculate* vItem);
	virtual bool IsLeaf();
	virtual int ChildCount();
	virtual CPowerCalculate * Child(int vIndex);
	virtual pCalVector Children();

	virtual void NewCal_Tree(CDevBase* vDev);

public:
	virtual void Prepare();
	virtual void StationSort(StationMap& vStaMap);
	virtual void NodeSort(NodeMap& vNodeMap);
	virtual void NodeGround(NodeMap& vNodeMap);
	virtual void NodeID(NodeMap& vNodeID);

protected:
	pCalVector pChildren;
	CPowerProfile* pProfile;
	CDevBase* pDevice;

};

typedef vector<CPowerCalculate*> pPowerCalVector;

#endif // !defined(EA_0C91DDCB_9AFB_45e6_9257_85D81026F842__INCLUDED_)
