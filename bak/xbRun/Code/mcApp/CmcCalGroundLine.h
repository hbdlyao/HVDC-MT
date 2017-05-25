#pragma once


#include "CmcCalTwoDot.h"

/**
 * 主回路 接地极线
 */
class CmcCalGroundLine : public CmcCalTwoDot
{

protected:
	void UpdateY() override;
};
