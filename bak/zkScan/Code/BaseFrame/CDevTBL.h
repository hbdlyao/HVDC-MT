#pragma once

#include "CDevBase.h"

#include "CObjTBL.h"

class CDevTBL : public CObjTBL
{
public:
	virtual ~CDevTBL();

	void Clear() override;
	void Release()  override;

public:	
	virtual CDevBase * NewDevice(int vDevType);
	virtual CDevBase * NewDevice(int vDevType, string vID);
	virtual CDevBase * NewDevice(int vDevType, string vID, string vName);

	virtual	CDevBase * Device(int vIndex);
	virtual CDevBase * Device(string vDevName);

	virtual void DeviceAdd(string vID, CDevBase* vItem);
	virtual void DeviceRemove(int vType, CDevBase * vItem);

protected:
	virtual CDevBase * doNewDevice(int vDevType);

public:

	virtual void ClearNodeID() ;
	virtual string TypeToName(int vDevType);
	virtual void NodeSort(NodeMap& vNodeMap) ;
	virtual void NodeGround(NodeMap& vNodeMap) ;
	virtual void NodeID(NodeMap& vNodeID) ;

};

typedef map<int, CDevTBL * >  pDevTBL;

