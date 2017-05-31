///////////////////////////////////////////////////////////
//  CxbRwDcLine.cpp
//  Implementation of the Class CxbRwDcLine
//  Created on:      18-4ÔÂ-2017 17:11:13
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbRwDCLine.h"

string CxbRwDcLine::GetSQL_Load_Leaf(string vLeafName)
{
	string vSQL, vtbl1, vtbl2;

	vtbl1 = tblName;
	vtbl2 = tblName_Leaf;

	//select a.stationname1, a.stationname2,a.PosOrNeg, b.* 
	//from xbTrap as a, xbTrap_tree as b  
	//where b.ParentDeviceName = a.Devicename 
	//and b.ParentDeviceName = "Trap1"
	//order by b.ParentDeviceName , b.DeviceName

	vSQL = "select a.stationname1,a.stationname2, a.PosOrNeg, b.*  from ";
	vSQL = vSQL + vtbl1 + " as a , " + vtbl2 + " as b ";
	vSQL = vSQL + " where b.ParentDeviceName = a.devicename  ";
	vSQL = vSQL + " and b.DeviceName = ";
	vSQL = vSQL + "'";
	vSQL = vSQL + vLeafName;
	vSQL = vSQL + "'";
	vSQL = vSQL + " order by b.ParentDeviceName , b.DeviceName ";

	return vSQL;

}
