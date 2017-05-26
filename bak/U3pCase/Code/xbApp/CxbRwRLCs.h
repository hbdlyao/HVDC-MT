///////////////////////////////////////////////////////////
//  CxbRwRLCs.h
//  Implementation of the Class CxbRwRLCs
//  Created on:      18-4ÔÂ-2017 23:39:58
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_9E4D5D2D_58F4_4450_8EC1_0BAB6C7DDBB6__INCLUDED_)
#define EA_9E4D5D2D_58F4_4450_8EC1_0BAB6C7DDBB6__INCLUDED_

#include "CxbRw_Tree.h"

class CxbRwRLCs : public CxbRw_Tree
{

protected:
	void doLoad_Leaf_Data(CxbDevBase* vLeaf) override;
	void doSave_Leaf_Data(CxbDevBase* vLeaf);
};
#endif // !defined(EA_9E4D5D2D_58F4_4450_8EC1_0BAB6C7DDBB6__INCLUDED_)
