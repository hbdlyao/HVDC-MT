///////////////////////////////////////////////////////////
//  CmcRwMvc.h
//  Implementation of the Class CmcRwMvc
//  Created on:      18-4ÔÂ-2017 21:32:02
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_4402847C_542D_415f_B379_AE32A06E9F95__INCLUDED_)
#define EA_4402847C_542D_415f_B379_AE32A06E9F95__INCLUDED_

#include "CMyRwMvc.h"
#include "CMyRwDev.h"

#include "CmcHvdcGrid.h"

class CmcRwMvc : public CMyRwMvcAccess
{
public:
	void InitGrid(CmcHvdcGrid* vHvdc);

protected:
	CmcHvdcGrid* pGrid;

	void doLoad() override;
	void doSave() override;

	CMyRwDev * doNewRw(int vtblType) override;

};
#endif // !defined(EA_4402847C_542D_415f_B379_AE32A06E9F95__INCLUDED_)
