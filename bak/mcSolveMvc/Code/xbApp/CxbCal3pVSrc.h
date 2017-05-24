///////////////////////////////////////////////////////////
//  CxbCal3pVSrc.h
//  Implementation of the Class CxbCal3pVSrc
//  Created on:      05-4ÔÂ-2017 18:32:38
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_1CDE9AD6_D5B5_444d_BF67_C79967A4C740__INCLUDED_)
#define EA_1CDE9AD6_D5B5_444d_BF67_C79967A4C740__INCLUDED_

#include "CxbCalTwoDot.h"

class CxbCal3pVSrc : public CxbCalTwoDot
{

public:
	void Prepare();

	virtual void UpdateY();
	virtual void UpdateI();

	virtual void Update_zkY();
	virtual void Update_zkI();

};
#endif // !defined(EA_1CDE9AD6_D5B5_444d_BF67_C79967A4C740__INCLUDED_)
