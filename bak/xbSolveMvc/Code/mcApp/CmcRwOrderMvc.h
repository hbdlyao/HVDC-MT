///////////////////////////////////////////////////////////
//  CmcRwOrderMvc.h
//  Implementation of the Class CmcRwOrderMvc
//  Created on:      18-4ÔÂ-2017 22:36:22
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_2329C3EB_F3AD_46e9_80FA_F0DBFD7B8ECE__INCLUDED_)
#define EA_2329C3EB_F3AD_46e9_80FA_F0DBFD7B8ECE__INCLUDED_

#include "CMyRwMvc.h"
#include "CmcOrder.h"

class CmcRwOrderMvc : public CRwMvcAccess
{
protected:
	CmcOrder * pOrder;
public:
	void Init(CmcOrder* vOrder);
protected:
	void doLoad() override;
	void doSave() override;
};
#endif // !defined(EA_2329C3EB_F3AD_46e9_80FA_F0DBFD7B8ECE__INCLUDED_)
