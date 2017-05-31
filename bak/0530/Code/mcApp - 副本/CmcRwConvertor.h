///////////////////////////////////////////////////////////
//  CmcRwConvertor.h
//  Implementation of the Class CmcRwConvertor
//  Created on:      22-4ÔÂ-2017 14:52:12
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_C23D69D2_F51C_44eb_BD31_8D56503D504E__INCLUDED_)
#define EA_C23D69D2_F51C_44eb_BD31_8D56503D504E__INCLUDED_

#include "CmcRwTwo.h"

class CmcRwConvertor : public CmcRwTwo
{

protected:
	void doLoad(CDevBase* vDevice) override;
	void doSave(CDevBase* vDevice) override;

};
#endif // !defined(EA_C23D69D2_F51C_44eb_BD31_8D56503D504E__INCLUDED_)
