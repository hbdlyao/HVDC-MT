///////////////////////////////////////////////////////////
//  CxbRwDcLine.h
//  Implementation of the Class CxbRwDcLine
//  Created on:      18-4ÔÂ-2017 17:11:13
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_3DEF9080_6497_4b20_B08D_02292F8ED324__INCLUDED_)
#define EA_3DEF9080_6497_4b20_B08D_02292F8ED324__INCLUDED_

#include "CxbRwGroundLine.h"
#include "CxbDevDcLine_Seg.h"

class CxbRwDcLine : public CxbRwGroundLine
{
protected:
	string GetSQL_Load_Leaf(string vLeafName) override;

};
#endif // !defined(EA_3DEF9080_6497_4b20_B08D_02292F8ED324__INCLUDED_)
