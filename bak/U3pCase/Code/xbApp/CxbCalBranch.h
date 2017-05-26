///////////////////////////////////////////////////////////
//  CxbCalBranch.h
//  Implementation of the Class CxbCalBranch
//  Created on:      05-4ÔÂ-2017 18:32:16
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_914F1015_A3CC_4b14_9189_CD5AFD40AEE3__INCLUDED_)
#define EA_914F1015_A3CC_4b14_9189_CD5AFD40AEE3__INCLUDED_

#include "CxbCalTwoDot.h"

class CxbCalBranch : public CxbCalTwoDot
{
protected:
	void UpdateY() override;
	void SolveI() override;

};
#endif // !defined(EA_914F1015_A3CC_4b14_9189_CD5AFD40AEE3__INCLUDED_)
