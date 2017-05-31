///////////////////////////////////////////////////////////
//  CxbDevDcLine_Seg.h
//  Implementation of the Class CxbDevDcLine_Seg
//  Created on:      26-4月-2017 17:43:36
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_3A4A5012_E0EA_4251_913F_314CB79A2C05__INCLUDED_)
#define EA_3A4A5012_E0EA_4251_913F_314CB79A2C05__INCLUDED_

#include "CxbDevGroundLine_Seg.h"

/**
 * 直流极线
 */

class CxbDevDcLine_Seg : public CxbDevGroundLine_Seg
{
public:	
	void Init() override;
	string BusName(int vIndex) override;
};
#endif // !defined(EA_3A4A5012_E0EA_4251_913F_314CB79A2C05__INCLUDED_)
