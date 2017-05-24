///////////////////////////////////////////////////////////
//  CProjectRwMDB.h
//  Implementation of the Class CProjectRwMvc
//  Created on:      18-4ÔÂ-2017 22:23:47
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_31481FCB_DF22_47b8_9DE0_EAE3BCE8D4BB__INCLUDED_)
#define EA_31481FCB_DF22_47b8_9DE0_EAE3BCE8D4BB__INCLUDED_

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
#endif // !defined(EA_31481FCB_DF22_47b8_9DE0_EAE3BCE8D4BB__INCLUDED_)
