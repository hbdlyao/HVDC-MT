///////////////////////////////////////////////////////////
//  CxbRwDCF.h
//  Implementation of the Class CxbRwDCF
//  Created on:      18-4ÔÂ-2017 23:40:50
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_4E5E2E7C_3AAF_4c70_8173_4C8BCA4BB81C__INCLUDED_)
#define EA_4E5E2E7C_3AAF_4c70_8173_4C8BCA4BB81C__INCLUDED_

#include "CxbRwRLCs.h"

class CxbRwDCF : public CxbRwRLCs
{
protected:
	void doLoad(CDevBase* vRoot) override;
	void doSave(CDevBase * vLeaf) override;

	void doLoad_Leaf_Data(CxbDevBase* vLeaf) override;
	void doSave_Leaf_Data(CxbDevBase * vLeaf) override;

};
#endif // !defined(EA_4E5E2E7C_3AAF_4c70_8173_4C8BCA4BB81C__INCLUDED_)
