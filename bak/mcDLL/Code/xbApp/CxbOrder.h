///////////////////////////////////////////////////////////
//  CxbOrder.h
//  Implementation of the Class CxbOrder
//  Created on:      05-4月-2017 18:22:10
//  Original author: Administrator
///////////////////////////////////////////////////////////

#if !defined(EA_06889A3F_2BCF_4c6b_8051_6C5BCC4067F9__INCLUDED_)
#define EA_06889A3F_2BCF_4c6b_8051_6C5BCC4067F9__INCLUDED_

#include "CHvdcOrder.h"
#include "CxbDefs.h"

#include <string>

using namespace std;

class CxbOrder : public CHvdcOrder
{
public:
	string U3pName;

	//马骏鹏
	string GroundStaiton;
	//马骏鹏
	//滤波器偏差类型
	int DCFDevType;
	int DCFRandTimes;

public:
	void Init();

	int StaCount() override;

};
#endif // !defined(EA_06889A3F_2BCF_4c6b_8051_6C5BCC4067F9__INCLUDED_)
