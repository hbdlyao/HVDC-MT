///////////////////////////////////////////////////////////
//  C3pRwOrderMvc.h
//  Implementation of the Class C3pRwOrderMvc
//  Created on:      18-5ÔÂ-2017 12:55:59
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_56BEBA14_5C5E_4e12_BA84_775885FECCDF__INCLUDED_)
#define EA_56BEBA14_5C5E_4e12_BA84_775885FECCDF__INCLUDED_

#include "CMyRwMvc.h"
#include "C3pOrder.h"

class C3pRwOrderMvc : public CMyRwMvcAccess
{
protected:
	C3pOrder * pOrder;
public:
	void Init(C3pOrder* vOrder);

	void OnLoad(string vdbf) override;

	void OnLoad()  override;

	void doLoad() override;
	void doSave() override;

	void doLoad_CaseID();
};

#endif // !defined(EA_56BEBA14_5C5E_4e12_BA84_775885FECCDF__INCLUDED_)
