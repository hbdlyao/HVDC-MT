///////////////////////////////////////////////////////////
//  CmcDevTBL.h
//  Implementation of the Class CmcDevTBL
//  Created on:      21-5��-2017 0:51:41
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_C32FD0D1_7249_4385_A241_7387A4450BFE__INCLUDED_)
#define EA_C32FD0D1_7249_4385_A241_7387A4450BFE__INCLUDED_

#include "CDevTBL.h"

/**
 * ����·ֱ���豸��
 */
class CmcDevTBL : public CDevTBL
{

public:
	string TypeToName(int vDevType) override;
	static CDevBase * mcNewDevice(int vDevType);

protected:
	CDevBase * doNewDevice(int vDevType) override;

};
#endif // !defined(EA_C32FD0D1_7249_4385_A241_7387A4450BFE__INCLUDED_)
