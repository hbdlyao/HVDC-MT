///////////////////////////////////////////////////////////
//  ClmCalGroundLine_Seg.h
//  Implementation of the Class ClmCalGroundLine_Seg
//  Created on:      24-5月-2017 11:28:16
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_C1953544_E5F4_42b7_87F3_1FDD8AABBCC6__INCLUDED_)
#define EA_C1953544_E5F4_42b7_87F3_1FDD8AABBCC6__INCLUDED_

#include "CxbCalTwoDot.h"
#include "ClmCalTwoDot.h"

/**
 * 主回路 接地极线
 */
class ClmCalGroundLine_Seg : public ClmCalTwoDot
{
public:
	void Prepare() override;
};
#endif // !defined(EA_C1953544_E5F4_42b7_87F3_1FDD8AABBCC6__INCLUDED_)
