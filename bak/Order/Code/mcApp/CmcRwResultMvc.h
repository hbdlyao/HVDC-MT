///////////////////////////////////////////////////////////
//  CmcRwResultMvc.h
//  Implementation of the Class CmcRwResultMvc
//  Created on:      18-4ÔÂ-2017 22:36:27
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_11167C37_E871_41bd_84C9_811928AC7302__INCLUDED_)
#define EA_11167C37_E871_41bd_84C9_811928AC7302__INCLUDED_

#include "CMyRwMvc.h"
#include "CmcResult.h"

class CmcRwResultMvc : public CRwMvcAccess
{
protected:
	CmcResult * pResult;

public:
	void Init(CmcResult* vRes);

protected:
	void doLoad() override;
	void doSave() override;

	void doLoad(struct_mcResultData vResult);
	void doSave(struct_mcResultData vResult);
};
#endif // !defined(EA_11167C37_E871_41bd_84C9_811928AC7302__INCLUDED_)
