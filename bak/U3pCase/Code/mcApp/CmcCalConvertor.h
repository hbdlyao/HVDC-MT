#pragma once

#include "CmcCalTwoDot.h"
#include "CmcDevConvertor.h"

/**
* »»Á÷Æ÷
*/
class CmcCalConvertor : public CmcCalTwoDot
{

public:
	int  MeasureStationIndex;

	int GetNodeID(int vIndex);

	void StationSort(StationMap& vStaMap) override;
	void NodeGround(NodeMap & vNodeMap) override;

	virtual void Prepare();
	virtual void PrepareNormal();

	virtual void SaveNormal();
};
