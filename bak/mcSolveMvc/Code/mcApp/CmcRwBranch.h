///////////////////////////////////////////////////////////
//  CmcRwBranch.h
//  Implementation of the Class CmcRwBranch
//  Created on:      18-4ÔÂ-2017 20:25:05
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_D5655E1B_E9BE_4dfb_9F68_3BE7290AE400__INCLUDED_)
#define EA_D5655E1B_E9BE_4dfb_9F68_3BE7290AE400__INCLUDED_

#include "CmcRwTwo.h"
#include "CmcRwTwo.h"

class CmcRwBranch : public CmcRwTwo
{

protected:
	void doLoad(CDevBase* vDevice) override;
	void doSave(CDevBase* vDevice) override;

};
#endif // !defined(EA_D5655E1B_E9BE_4dfb_9F68_3BE7290AE400__INCLUDED_)
