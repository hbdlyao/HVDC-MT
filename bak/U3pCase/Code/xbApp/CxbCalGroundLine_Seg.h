///////////////////////////////////////////////////////////
//  CxbCalGroundLine_Seg.h
//  Implementation of the Class CxbCalGroundLine
//  Created on:      05-4月-2017 18:32:51
//  Original author: Administrator
///////////////////////////////////////////////////////////

#if !defined(EA_DB92C873_DE7D_45e1_AB38_217D0205DCF1__INCLUDED_)
#define EA_DB92C873_DE7D_45e1_AB38_217D0205DCF1__INCLUDED_

#include "CxbCalTwoDot.h"

/**
 * 主回路 接地极线
 */
class CxbCalGroundLine_Seg : public CxbCalTwoDot
{
public:
	void UpdateY() override;
	void SolveI() override;
	void SolveIeq() override;

public:
	virtual void NodeGround(NodeMap& vNodeMap);

};
#endif // !defined(EA_DB92C873_DE7D_45e1_AB38_217D0205DCF1__INCLUDED_)
