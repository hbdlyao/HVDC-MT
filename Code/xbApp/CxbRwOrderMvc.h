///////////////////////////////////////////////////////////
//  CxbRwOrderMvc.h
//  Implementation of the Class CxbRwOrderMvc
//  Created on:      18-4ÔÂ-2017 22:56:16
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_84B118E1_A96D_43ea_8EBB_D569FEF43149__INCLUDED_)
#define EA_84B118E1_A96D_43ea_8EBB_D569FEF43149__INCLUDED_

#include "CMyRwMvc.h"
#include "CxbOrder.h"


class CxbRwOrderMvc : public CMyRwMvcAccess
{
protected:
	CxbOrder* pOrder;

public:
	void Init(CxbOrder* vOrder);
	void OnLoad(string vdbf) override;

	void OnLoad()  override;

	void doLoad() override;
	void doSave() override;

	void doLoad_CaseID();

};
#endif // !defined(EA_84B118E1_A96D_43ea_8EBB_D569FEF43149__INCLUDED_)
