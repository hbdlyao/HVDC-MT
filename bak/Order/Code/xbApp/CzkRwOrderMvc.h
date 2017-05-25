///////////////////////////////////////////////////////////
//  CzkRwOrderMvc.h
//  Implementation of the Class CzkRwOrderMvc
//  Created on:      24-5��-2017 14:07:16
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_20A6384A_51C7_4ee1_9162_1439031692F5__INCLUDED_)
#define EA_20A6384A_51C7_4ee1_9162_1439031692F5__INCLUDED_

#include "CMyRwMvc.h"
#include "CzkOrder.h"

class CzkRwOrderMvc : public CRwMvcAccess
{
protected:
	CzkOrder* pOrder;

	void doLoad() override;
	void doSave() override;

public:
	void Init(CzkOrder* vOrder);

};
#endif // !defined(EA_20A6384A_51C7_4ee1_9162_1439031692F5__INCLUDED_)
