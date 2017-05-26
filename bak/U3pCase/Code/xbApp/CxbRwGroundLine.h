///////////////////////////////////////////////////////////
//  CxbRwGroundLine.h
//  Implementation of the Class CxbRwGroundLine
//  Created on:      26-4ÔÂ-2017 23:54:28
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_696C6AF7_3A28_4701_841E_CD545E5144DF__INCLUDED_)
#define EA_696C6AF7_3A28_4701_841E_CD545E5144DF__INCLUDED_

#include "CxbRw_Tree.h"

#include "CxbDevGroundLine_Seg.h"

class CxbRwGroundLine : public CxbRw_Tree
{
protected:
	void doLoad_Leaf_Data(CxbDevBase* vLeaf) override;

	void doSave_Leaf_Data(CxbDevBase* vLeaf) override;

};
#endif // !defined(EA_696C6AF7_3A28_4701_841E_CD545E5144DF__INCLUDED_)
