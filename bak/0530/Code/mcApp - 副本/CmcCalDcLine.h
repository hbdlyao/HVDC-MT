#pragma once

#include "CmcCalGroundLine.h"

/**
 * ����· ֱ������
 */
class CmcCalDcLine : public CmcCalGroundLine
{

public:
	void StationSort(StationMap & vStaMap) override;

};


