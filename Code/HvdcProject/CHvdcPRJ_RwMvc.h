#pragma once

#include "CMyRwMvc.h"

/**
 * ���̶�д
 */
class CHvdcPRJ_RwMvc : public CMyRwMvcAccess
{

public:
	virtual void InitAdo(string vDbf);

protected:
	virtual void doLoad();
	virtual void doSave();

};
