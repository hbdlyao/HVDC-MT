#pragma once

#include "CmcRwMvc.h"

/**
* ���̶�д
*/
class CmcPRJ_RwMvc : public CMyRwMvcAccess
{

public:
	virtual void InitAdo(string vDbf);

protected:
	virtual void doLoad();
	virtual void doSave();

};
