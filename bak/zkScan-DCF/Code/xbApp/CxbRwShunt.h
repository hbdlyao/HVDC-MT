///////////////////////////////////////////////////////////
//  CxbRwShunt.h
//  Implementation of the Class CxbRwShunt
//  Created on:      18-4ÔÂ-2017 17:11:19
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_21439D4E_8E52_424d_B05A_0BBED77C718E__INCLUDED_)
#define EA_21439D4E_8E52_424d_B05A_0BBED77C718E__INCLUDED_

#include "CxbRwOne.h"

class CxbRwShunt : public CxbRwOne
{

protected:
	void doLoad(CDevBase * vDevice) override;
	void doSave(CDevBase * vDevice) override;
};
#endif // !defined(EA_21439D4E_8E52_424d_B05A_0BBED77C718E__INCLUDED_)
