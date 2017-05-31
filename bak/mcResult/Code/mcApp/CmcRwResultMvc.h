#pragma once

#include "CMyRwMvc.h"
#include "CmcResult.h"

class CmcRwResultMvc : public CMyRwMvcAccess
{
protected:
	CmcResult * pResult;

public:
	void Init(CmcResult* vRes);

protected:
	void doLoad() override;
	void doSave() override;

};
