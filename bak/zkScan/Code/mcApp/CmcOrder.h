///////////////////////////////////////////////////////////
//  CmcOrder.h
//  Implementation of the Class CmcOrder
//  Created on:      03-5ÔÂ-2017 19:32:53
//  Original author: Administrator
///////////////////////////////////////////////////////////

#if !defined(EA_2FA48820_3A50_4155_A87D_EED8F26D763B__INCLUDED_)
#define EA_2FA48820_3A50_4155_A87D_EED8F26D763B__INCLUDED_


#include "CHvdcOrder.h"

#include <string>
#include "gbHead_mcType.h"

using namespace std;

class CmcOrder : public CHvdcOrder
{
public:	
	int CaseCount() override;
	int StaCount() override;

	string CreateCaseID() override;

	UdMap UdCustomMap = UdMap();

	bool IsUdCustomPre = false;

	bool Is6Pulse = false;

	void Init();
	void InitNormal();
};

#endif // !defined(EA_2FA48820_3A50_4155_A87D_EED8F26D763B__INCLUDED_)
