///////////////////////////////////////////////////////////
//  CxbRwResultMvc.h
//  Implementation of the Class CxbRwResultMvc
//  Created on:      18-4ÔÂ-2017 22:56:21
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_8AC3F3E1_F017_411c_9F26_5F358C414CF8__INCLUDED_)
#define EA_8AC3F3E1_F017_411c_9F26_5F358C414CF8__INCLUDED_

#include "CMyRwMvc.h"
#include "CxbResult.h"


class CxbRwResultMvc : public CMyRwMvcAccess
{

public:
	void Init(CxbResult* vRes);
	void doLoad();
	void doSave();

protected:
	CxbResult* pResult;

};
#endif // !defined(EA_8AC3F3E1_F017_411c_9F26_5F358C414CF8__INCLUDED_)
