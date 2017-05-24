///////////////////////////////////////////////////////////
//  C3pRwMvc.h
//  Implementation of the Class C3pRwMvc
//  Created on:      18-5ÔÂ-2017 8:45:12
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_8D488889_BB1A_4b19_9B08_F9C7D1767AFE__INCLUDED_)
#define EA_8D488889_BB1A_4b19_9B08_F9C7D1767AFE__INCLUDED_

#include "CMyRw.h"
#include "CMyRwMvc.h"
#include "C3pDevGrid.h"

class C3pRwMvc : public CRwMvc
{

public:
	void InitGrid(C3pDevGrid* vHvdc);
	void InitAdo(string vDbf) override;

protected:
	C3pDevGrid* pGrid;

	void doLoad() override;
	void doSave() override;
	CRwDev * doNewRw(int vtblType) override;

};
#endif // !defined(EA_8D488889_BB1A_4b19_9B08_F9C7D1767AFE__INCLUDED_)
