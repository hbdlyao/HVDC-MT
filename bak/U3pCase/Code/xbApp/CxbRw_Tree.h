///////////////////////////////////////////////////////////
//  CxbRw_Tree.h
//  Implementation of the Class CxbRw_Tree
//  Created on:      27-4ÔÂ-2017 1:32:12
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_029749EA_0EDC_4151_BE2E_04B94D827F43__INCLUDED_)
#define EA_029749EA_0EDC_4151_BE2E_04B94D827F43__INCLUDED_

#include "CxbRw.h"
#include "CxbDev_Tree.h"

#include <string>

using namespace std;

class CxbRw_Tree : public CxbRw
{
public:
	string tblName_Node;
	string tblName_Leaf;

public:
	void InitTable(string vtblName, string vtblName_Node, string vtblName_Leaf);

	void OnLoad() override;
	void OnSave() override;


protected:
	virtual string GetSQL_Load_Node(string vNodeName);
	virtual string GetSQL_Load_Leaf(string vLeafName);

	virtual string GetSQL_Delete_Leaf(string vLeafName);
	

	virtual void doLoad_Child(CxbDevBase* vDev);
	virtual void doSave_Child(CxbDevBase* vDev);

	virtual void doLoad_Node(CxbDev_Tree* vNode);
	virtual void doSave_Node(CxbDev_Tree* vNode);

	virtual void doLoad_Leaf(CxbDevBase* vLeaf);
	virtual void doSave_Leaf(CxbDevBase* vLeaf);

	virtual void doLoad_Node_Data(CxbDevBase * vDev);
	virtual void doSave_Node_Data(CxbDevBase * vDev);

	virtual void doLoad_Leaf_Data(CxbDevBase* vLeaf);
	virtual void doSave_Leaf_Data(CxbDevBase* vLeaf);

};
#endif // !defined(EA_029749EA_0EDC_4151_BE2E_04B94D827F43__INCLUDED_)
