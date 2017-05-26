#pragma once

#include "CPowerCalculate.h"

class CPowerSolves
{
protected:
	CPowerProfile * pProfile = nullptr;
	CPowerGrid *pGrid = nullptr;
	pPowerCalVector pChildren;

public:
	virtual ~CPowerSolves();

	virtual void Init(CPowerProfile * vProfile, CPowerGrid * vGrid);
	virtual void Clear();
	virtual void Release();

public:
	virtual void Add(CPowerCalculate* vItem);
	virtual void Remove(CPowerCalculate* vItem);
	virtual int ChildCount();
	virtual CPowerCalculate * Child(int vIndex);
	virtual pPowerCalVector Children();

public:

	virtual void NewSolves();

protected:
	virtual void NewCal_Tree(CDevBase* vDev);
	virtual void NewCal_Tree_1(CDevBase* vDev);

	virtual void doNewItem(CDevTBL* vTBL);
	virtual void doNewItem(int vtblType);

	virtual CPowerCalculate* doNewCal(CDevBase * vDev) ;

public:	
	virtual void Run();

	virtual void StationSort() ;
	virtual void NodeID()  ;

protected:
	virtual void doPrepare();

	virtual void doStationSort(StationMap& vStaMap);

	virtual void doNodeSort(NodeMap& vNodeMap);
	virtual void doNodeGround(NodeMap& vNodeMap);
	virtual void doNodeID(NodeMap& vNodeID);

};
