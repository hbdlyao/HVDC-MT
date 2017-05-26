///////////////////////////////////////////////////////////
//  CxbCalXf_C.h
//  Implementation of the Class CxbCalXf_C
//  Created on:      05-4ÔÂ-2017 18:33:05
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_8FBB4020_4E24_4901_BC68_B84C9347B9B3__INCLUDED_)
#define EA_8FBB4020_4E24_4901_BC68_B84C9347B9B3__INCLUDED_

#include "CxbCalShunt.h"

class CxbCalXf_C : public CxbCalShunt
{
public:
	void Update_zkY() override;
};
#endif // !defined(EA_8FBB4020_4E24_4901_BC68_B84C9347B9B3__INCLUDED_)
