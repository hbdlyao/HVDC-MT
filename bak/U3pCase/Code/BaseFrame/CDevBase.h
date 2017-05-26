#pragma once

#include "CMyObjBase.h"
#include "gbHead_MyType.h"

class CDevBase : public CMyObjBase
{
public:
	virtual ~CDevBase();

	virtual void Init();
	virtual void Clear();
	virtual void Release();

private:
	string DeviceID;
	string DeviceName;
	int DeviceType;
	string ParentDeviceName;
	int dotCount;
	int staCount;
	int* NodeIDs;
	string* NodeNames;
	string* StaNames;

public:
	string GetDeviceID();

	void SetDeviceID(string newVal);
	string GetDeviceName();
	void SetDeviceName(string newVal);
	string GetParentDeviceName();
	void SetParentDeviceName(string newVal);
	int GetDeviceType();
	void SetDeviceType(int newVal);
	virtual string GetStationName();
	virtual string ShowName();
	int GetDotCount();
	void SetDotCount(int newVal);
	int GetStaCount();
	void SetStaCount(int newVal);
	virtual string GetStationName(int vIndex);
	virtual void SetStationName(int vIndex, string newVal);
	string GetNodeName(int vIndex);
	void SetNodeName(int vIndex, string vName);
	int GetNodeID(int vIndex);
	void SetNodeID(int vIndex, int vID);

protected:
	pObjVector pChildren;

public:
	virtual bool IsLeaf();

	virtual void Add(CDevBase* vItem);
	virtual void Remove(CDevBase* vItem);
	
	virtual int ChildCount();

	virtual CDevBase * Child(int vIndex);

	virtual pObjVector Children();

public:
	virtual string BusName(int vIndex);

	virtual void ClearNodeID();
	virtual void NodeSort(NodeMap& vNodeMap);
	virtual void NodeGround(NodeMap& vNodeMap);
	virtual void NodeID(NodeMap& vNodeID);


};
