///////////////////////////////////////////////////////////
//  CxbRw_Tree.cpp
//  Implementation of the Class CxbRw_Tree
//  Created on:      27-4月-2017 1:32:12
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbRw_Tree.h"
#include "CxbDevTBL.h"

#include <iostream>

void CxbRw_Tree::InitTable(string vtblName, string vtblName_Node, string vtblName_Leaf)
{
	tblName = vtblName;
	tblName_Node = vtblName_Node;
	tblName_Leaf = vtblName_Leaf;
}

string CxbRw_Tree::GetSQL_Load_Node(string vNodeName)
{
	string vSQL, vtbl1, vtbl2;

	vtbl1 = tblName;
	vtbl2 = tblName_Node;

	//select a.stationname1, a.stationname2,a.PosOrNeg, b.* from xbTrap as a, xbTrap_tree as b  
	//where b.ParentDeviceName = a.Devicename 
	//and b.ParentDeviceName = "Trap1"
	//order by b.ParentDeviceName , b.DeviceName
	//
	vSQL = "select b.* from ";
	vSQL = vSQL + vtbl1 + " as a , " + vtbl2 + " as b ";
	vSQL = vSQL + " where b.ParentDeviceName = a.devicename  ";
	vSQL = vSQL + " and b.ParentDeviceName = ";
	vSQL = vSQL + " '";
	vSQL = vSQL + vNodeName;
	vSQL = vSQL + "' ";
	vSQL = vSQL + " order by b.ParentDeviceName , b.DeviceName ";

	return vSQL;

}

string CxbRw_Tree::GetSQL_Load_Leaf(string vLeafName)
{
	string vSQL, vtbl1, vtbl2;

	vtbl1 = tblName;
	vtbl2 = tblName_Leaf;

	//select a.stationname1, a.stationname2,a.PosOrNeg, b.* 
	//from xbTrap as a, xbTrap_tree as b  
	//where b.ParentDeviceName = a.Devicename 
	//and b.ParentDeviceName = "Trap1"
	//order by b.ParentDeviceName , b.DeviceName

	vSQL = "select a.stationname, a.PosOrNeg, b.*  from ";
	vSQL = vSQL + vtbl1 + " as a , " + vtbl2 + " as b ";
	vSQL = vSQL + " where b.ParentDeviceName = a.devicename  ";
	vSQL = vSQL + " and b.DeviceName = ";
	vSQL = vSQL + "'";
	vSQL = vSQL + vLeafName;
	vSQL = vSQL + "'";
	vSQL = vSQL + " order by b.ParentDeviceName , b.DeviceName ";

	return vSQL;

}

string CxbRw_Tree::GetSQL_Delete_Leaf(string vLeafName)
{
	string vSQL, vtblName;

	//delete *  from xbTrap_tree 
	//where DeviceName = "Trap1"

	vtblName = tblName_Leaf;
	//
	vSQL = "delete   from  " + vtblName;
	vSQL = vSQL + " where DeviceName = ";
	vSQL = vSQL + "'";
	vSQL = vSQL + vLeafName;
	vSQL = vSQL + "'";

	return vSQL;

}


void CxbRw_Tree::OnLoad()
{
	CxbRw::OnLoad();
	
	//
	for each (CxbDevBase* vDev in pGrid->DeviceTBL(tblType)->Children())
		doLoad_Child(vDev);
}


void CxbRw_Tree::doLoad_Child(CxbDevBase* vDev)
{

	CxbDev_Tree * vNode;
	
	if (vDev->IsLeaf())
		doLoad_Leaf(vDev);
	
	//
	if (!vDev->IsLeaf())
	{	//广度优先
		vNode = dynamic_cast<CxbDev_Tree * >(vDev);
		doLoad_Node(vNode);
	
		//
		for each (CxbDevBase * vChild in vNode->Children())
		{
			doLoad_Child(vChild);
		}//for 
	
	}//else
}


void CxbRw_Tree::doLoad_Node(CxbDev_Tree* vNode)
{
	CxbDevBase * vDev;
	
	string  vSQL, vStr, vtbl1, vtbl2;
	_variant_t vValue;
	bool vOk;
	int vType;
	
	vSQL = GetSQL_Load_Node(vNode->GetDeviceName());
	vOk = RwAdo->OpenSQL(vSQL);
	
	if (vOk)
	{
		cout << "Load---" + vtbl2 + "----Node----" << vNode->GetDeviceName() << endl;
	
		while (!RwAdo->IsEOF())
		{
			RwAdo->GetFieldValue("DeviceType", vValue);
			if (vValue.vt != VT_NULL)
			{
				vType = vValue.iVal;
			};
	
			vDev = dynamic_cast<CxbDevBase *>(CxbDevTBL::xbNewDevice(vType));
				
			doLoad_Node_Data(vDev);
	
	
			//to-do
			vNode->Add(vDev);
	
			//
			RwAdo->Record_MoveNext();
	
			cout << "   --" << vDev->ShowName() << endl;
	
		}//while
	
	}//if
	
	RwAdo->CloseTBL();
	
	//
}

void CxbRw_Tree::doLoad_Leaf(CxbDevBase* vLeaf)
{

	string  vSQL, vStr, vtbl1, vtbl2;
	_variant_t vValue;
	bool vOk;
	
	vSQL = GetSQL_Load_Leaf(vLeaf->GetDeviceName());
	vOk = RwAdo->OpenSQL(vSQL);
	
	if (vOk)
	{
		cout << "Load------Leaf---" << endl;
		//
		doLoad_Leaf_Data(vLeaf);
		
		cout << "   --" << vLeaf->ShowName() << endl;
	
	}//if
	
	RwAdo->CloseTBL();
}


void CxbRw_Tree::doLoad_Node_Data(CxbDevBase* vDev)
{
	string vStr;
	_variant_t vValue;

	//
	RwAdo->GetFieldValue("ID", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetObjGUID(vValue.iVal);
	};

	RwAdo->GetFieldValue("DeviceID", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (_bstr_t)vValue; //字符型
		vDev->SetDeviceID(vStr);
	};

	RwAdo->GetFieldValue("DeviceName", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (_bstr_t)vValue;
		vDev->SetDeviceName(vStr);
	};

	RwAdo->GetFieldValue("DeviceType", vValue);
	if (vValue.vt != VT_NULL)
	{
		vDev->SetDeviceType(vValue.iVal);//整型
	};

}


void CxbRw_Tree::doLoad_Leaf_Data(CxbDevBase* vLeaf) 
{
	string vStr;
	_variant_t vValue;

	CxbRw::doLoad(vLeaf);

	RwAdo->GetFieldValue("ParentDeviceName", vValue);
	if (vValue.vt != VT_NULL)
	{
		vStr = (_bstr_t)vValue;
		vLeaf->SetParentDeviceName(vStr);
	};

}


void CxbRw_Tree::OnSave()
{
	CxbRw::OnSave();

	//
	for each (CxbDevBase* vDev in pGrid->DeviceTBL(tblType)->Children())
		doSave_Child(vDev);
}

void CxbRw_Tree::doSave_Child(CxbDevBase * vDev)
{
	CxbDev_Tree * vNode;

	if (vDev->IsLeaf())
		doSave_Leaf(vDev);

	//
	if (!vDev->IsLeaf())
	{   //广度优先
		vNode = dynamic_cast<CxbDev_Tree * >(vDev);
		doSave_Node(vNode);
		//
		for each(CxbDevBase * vChild in vNode->Children())
		{
			doSave_Child(vChild);
		}//for 

	}//else
}

void CxbRw_Tree::doSave_Node(CxbDev_Tree * vNode)
{
}

void CxbRw_Tree::doSave_Leaf(CxbDevBase* vLeaf)
{
	string vSQL, vtblName;

	cout << "Save------Leaf---" << endl;
	//
	vtblName = tblName_Leaf;
	vSQL = GetSQL_Delete_Leaf(vLeaf->GetDeviceName());
	RwAdo->ExecSQL(vSQL);

	//
	SqlStr = "Insert into " + vtblName;
	SqlParam = " ";
	//
	SqlStr = SqlStr + " (";
	SqlParam = SqlParam + " Values ( ";

	//
	doSave_Leaf_Data(vLeaf);

	//
	SqlStr = SqlStr + " ) ";
	SqlParam = SqlParam + " ) ";
	//
	SqlStr = SqlStr + SqlParam;

	//
	RwAdo->ExecSQL(SqlStr);

	cout << " ---" << vLeaf->ShowName() << endl;

	RwAdo->CloseTBL();
}

void CxbRw_Tree::doSave_Node_Data(CxbDevBase * vDev)
{
}

void CxbRw_Tree::doSave_Leaf_Data(CxbDevBase * vLeaf)
{
	int i;
	string vFieldName;

	for (i = 1; i <= vLeaf->GetDotCount(); i++)
	{
		vFieldName = NodeNameField(vLeaf->GetDotCount(), i);

		SqlStr = SqlStr + vFieldName + ",";
		SqlParam = SqlParam + GetString(vLeaf->GetNodeName(i - 1)) + ",";
	}


	for (i = 1; i <= vLeaf->GetDotCount(); i++)
	{
		vFieldName = NodeIDField(vLeaf->GetDotCount(), i);

		SqlStr = SqlStr + vFieldName + ",";
		SqlParam = SqlParam + GetString(vLeaf->GetNodeID(i - 1)) + ",";
	}

	SqlStr = SqlStr + "ID , ";
	SqlParam = SqlParam + GetString(vLeaf->GetObjGUID()) + " , ";
	//
	SqlStr = SqlStr + "DeviceID , ";
	SqlParam = SqlParam + GetString(vLeaf->GetDeviceID()) + " , ";

	SqlStr = SqlStr + "DeviceName , ";
	SqlParam = SqlParam + GetString(vLeaf->GetDeviceName()) + " , ";

	SqlStr = SqlStr + "DeviceType, ";
	SqlParam = SqlParam + GetString(vLeaf->GetDeviceType()) + " , ";

	SqlStr = SqlStr + "ParentDeviceName ";
	SqlParam = SqlParam + GetString(vLeaf->GetParentDeviceName());

}