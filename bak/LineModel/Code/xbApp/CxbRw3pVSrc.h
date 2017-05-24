///////////////////////////////////////////////////////////
//  CxbRw3pVSrc.h
//  Implementation of the Class CxbRw3pVSrc
//  Created on:      18-4ÔÂ-2017 17:17:11
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_F99112CF_15F9_4e2e_B322_7C519CBBBF17__INCLUDED_)
#define EA_F99112CF_15F9_4e2e_B322_7C519CBBBF17__INCLUDED_

#include "CxbRwTwo.h"
#include "CxbDev3pVSrc.h"

class CxbRw3pVSrc : public CxbRwTwo
{
public:
	void OnLoad()override;
	void OnSave()override;

protected:
	void doLoad(CDevBase * vDevice) override;
	void doSave(CDevBase * vDevice) override;

	void doLoad_hData();
	void doSave_hData();	
	
	void doLoad_hData(CxbDev3pVSrc * vDev);
	void doSave_hData(CxbDev3pVSrc * vDev);

};
#endif // !defined(EA_F99112CF_15F9_4e2e_B322_7C519CBBBF17__INCLUDED_)
