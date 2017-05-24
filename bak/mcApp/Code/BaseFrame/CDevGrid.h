///////////////////////////////////////////////////////////
//  CDevGrid.h
//  Implementation of the Class CDevGrid
//  Created on:      20-5ÔÂ-2017 23:05:42
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_4130F545_C5A3_467c_A4E3_CC5B0685B426__INCLUDED_)
#define EA_4130F545_C5A3_467c_A4E3_CC5B0685B426__INCLUDED_

#include "CDevTBL.h"
#include "CMyDefs.h"

class CDevGrid
{
protected:
	pDevTBL pTables;

	pTBLVector pChildren;

public:
	virtual ~CDevGrid();
	virtual string TypeToName(int vType);
	virtual void Init();
	virtual void Clear();
	virtual void Release();

	void Add(CDevTBL* vItem);
	void Remove(CDevTBL* vItem);
	CObjTBL* Child(int vIndex);
	int ChildCount();
	pTBLVector Children();

protected:
	virtual CDevTBL * doNewDevTBL(int vType);

public:
	virtual void NewGrid(StrVector vStaNames);

	virtual CDevTBL * NewDevTBL(int vType);
	virtual CDevTBL * DeviceTBL(int vType);

	virtual CDevBase * Device(int vType, int vIndex);
	virtual CDevBase * Device(int vType, string vDeviceName);

	virtual void DeviceAdd(int vType, CDevBase* vItem);
	virtual void DeviceRemove(int vType, CDevBase* vItem);

public:

	virtual void ClearNodeID();
	virtual void NodeSort(NodeMap& vNodeMap);
	virtual void NodeGround(NodeMap& vNodeMap);
	virtual void NodeID(NodeMap& vNodeID);

};
#endif // !defined(EA_4130F545_C5A3_467c_A4E3_CC5B0685B426__INCLUDED_)
