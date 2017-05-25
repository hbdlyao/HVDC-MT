///////////////////////////////////////////////////////////
//  C3pRwhDataMvc.h
//  Implementation of the Class C3pRwhDataMvc
//  Created on:      18-5ÔÂ-2017 12:45:03
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_21BA25EF_080A_49f0_BE8F_7B2AFC1A003B__INCLUDED_)
#define EA_21BA25EF_080A_49f0_BE8F_7B2AFC1A003B__INCLUDED_

#include "CMyRwMvc.h"
#include "C3pDevhData.h"


class C3pRwhDataMvc : public CMyRwMvcAccess
{
protected:
	C3pDevhData* pData;

public:
	void Init(C3pDevhData* vData);

protected:
	void doLoad();
	void doSave();

};
#endif // !defined(EA_21BA25EF_080A_49f0_BE8F_7B2AFC1A003B__INCLUDED_)
