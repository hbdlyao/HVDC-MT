///////////////////////////////////////////////////////////
//  CxbRwBranch.h
//  Implementation of the Class CxbRwBranch
//  Created on:      18-4ÔÂ-2017 17:11:24
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_5B65636C_CE6D_442b_9D7C_15F9C54230CA__INCLUDED_)
#define EA_5B65636C_CE6D_442b_9D7C_15F9C54230CA__INCLUDED_

#include "CxbRwTwo.h"

class CxbRwBranch : public CxbRwTwo
{
protected:
	void doLoad(CDevBase * vDevice) override;
	void doSave(CDevBase * vDevice) override;
};
#endif // !defined(EA_5B65636C_CE6D_442b_9D7C_15F9C54230CA__INCLUDED_)
