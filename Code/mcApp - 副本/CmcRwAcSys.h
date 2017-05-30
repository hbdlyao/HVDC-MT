///////////////////////////////////////////////////////////
//  CmcRwAcSys.h
//  Implementation of the Class CmcRwAcSys
//  Created on:      18-4ÔÂ-2017 20:38:07
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_3122559D_5B08_4779_813D_B4880742E39D__INCLUDED_)
#define EA_3122559D_5B08_4779_813D_B4880742E39D__INCLUDED_

#include "CmcRwOne.h"

class CmcRwAcSys : public CmcRwOne
{
protected:
	void doLoad(CDevBase* vDevice) override;
	void doSave(CDevBase* vDevice) override;
};
#endif // !defined(EA_3122559D_5B08_4779_813D_B4880742E39D__INCLUDED_)
