///////////////////////////////////////////////////////////
//  CmcRwShunt.h
//  Implementation of the Class CmcRwShunt
//  Created on:      18-4ÔÂ-2017 20:25:00
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_3C38C555_204F_44cc_84E2_3B962B99A68C__INCLUDED_)
#define EA_3C38C555_204F_44cc_84E2_3B962B99A68C__INCLUDED_

#include "CmcRwOne.h"

class CmcRwShunt : public CmcRwOne
{

protected:
	void doLoad(CDevBase * vDevice) override;
	void doSave(CDevBase * vDevice) override;

};
#endif // !defined(EA_3C38C555_204F_44cc_84E2_3B962B99A68C__INCLUDED_)
