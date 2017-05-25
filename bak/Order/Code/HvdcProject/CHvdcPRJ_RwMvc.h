#pragma once

#include "CMyRwMvc.h"

/**
 * ¹¤³Ì¶ÁÐ´
 */
class CHvdcPRJ_RwMvc : public CRwMvcAccess
{

public:
	virtual void InitAdo(string vDbf);

protected:
	virtual void doLoad();
	virtual void doSave();

};
