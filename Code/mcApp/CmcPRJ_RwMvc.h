#pragma once

#include "CmcRwMvc.h"

/**
* ¹¤³Ì¶ÁÐ´
*/
class CmcPRJ_RwMvc : public CMyRwMvcAccess
{

public:
	virtual void InitAdo(string vDbf);

protected:
	virtual void doLoad();
	virtual void doSave();

};
