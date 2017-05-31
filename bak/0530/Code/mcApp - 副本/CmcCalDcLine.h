#pragma once

#include "CmcCalGroundLine.h"

/**
 * 主回路 直流极线
 */
class CmcCalDcLine : public CmcCalGroundLine
{

public:
	void StationSort(StationMap & vStaMap) override;

};


