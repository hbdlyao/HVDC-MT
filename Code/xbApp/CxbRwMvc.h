///////////////////////////////////////////////////////////
//  CxbRwMvc.h
//  Implementation of the Class CxbRwMvc
//  Created on:      18-4ÔÂ-2017 18:50:05
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_BAA67435_F767_45ec_87D4_4B36E3085597__INCLUDED_)
#define EA_BAA67435_F767_45ec_87D4_4B36E3085597__INCLUDED_

#include "CxbHvdcGrid.h"
#include "CMyRwMvc.h"

class CxbRwMvc : public CMyRwMvcAccess
{

public:
	void InitGrid(CxbHvdcGrid* vHvdc);

protected:
	CxbHvdcGrid* pHvdc;

	virtual void doLoad();
	virtual void doSave();

protected:
	void doLoad_xbUsrc3p();
	void doLoad_xbPbDKQ();
	void doLoad_xbDCF();
	void doLoad_xbDcLine();
	void doLoad_xbGroundLine();
	void doLoad_xbGround();
	void doLoad_xbXfC();
	void doLoad_xbCoupleC();
	void doLoad_xbPulseC();
	void doLoad_xbShunt();
	void doLoad_xbBranch();
	void doLoad_xbMonitor();
	void doLoad_xbTrap();

	void doSave_xbUsrc3p();
	void doSave_xbPbDKQ();
	void doSave_xbDCF();
	void doSave_xbDcLine();
	void doSave_xbGroundLine();
	void doSave_xbGround();
	void doSave_xbXfC();
	void doSave_xbCoupleC();
	void doSave_xbPulseC();
	void doSave_xbShunt();
	void doSave_xbBranch();
	void doSave_xbMonitor();
	void doSave_xbTrap();

};
#endif // !defined(EA_BAA67435_F767_45ec_87D4_4B36E3085597__INCLUDED_)
