///////////////////////////////////////////////////////////
//  CxbRwMvc.cpp
//  Implementation of the Class CxbRwMvc
//  Created on:      18-4ÔÂ-2017 18:50:05
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CxbRwMvc.h"
#include "gbHead_xbRw.h"
#include "CxbRw_Tree.h"

void CxbRwMvc::InitGrid(CxbHvdcGrid* vHvdc)
{
	pHvdc = vHvdc;
}


void CxbRwMvc::InitAdo(string vDbf)
{
	dbfName = vDbf;
	
	RwAdo = new CRwAdo_Access();
	RwAdo->InitDbf(dbfName, "", "", "false");
}


void CxbRwMvc::doLoad()
{	
	doLoad_xbUsrc3p();
	doLoad_xbPbDKQ();
	doLoad_xbGround();
	doLoad_xbXfC();
	doLoad_xbCoupleC();
	doLoad_xbPulseC();

	doLoad_xbShunt();
	doLoad_xbBranch();

	doLoad_xbMonitor();
	doLoad_xbTrap();

	doLoad_xbDCF();

	doLoad_xbGroundLine();

	doLoad_xbDcLine();


}


void CxbRwMvc::doSave()
{
	doSave_xbUsrc3p();
	
	doSave_xbPbDKQ();
	doSave_xbGround();
	
	doSave_xbXfC();
	doSave_xbCoupleC();
	doSave_xbPulseC();
	
	doSave_xbShunt();
	doSave_xbBranch();
	
	doSave_xbMonitor();
	doSave_xbTrap();

	//

	doSave_xbDcLine();
	doSave_xbGroundLine();
	
	doSave_xbDCF();
	
}


void CxbRwMvc::doLoad_xbUsrc3p()
{
	CxbRw3pVSrc vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xb3pVsrc");
	vRw.InitType(CxbDefs::Usrc3p, CxbDefs::Usrc3p);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();
}

void CxbRwMvc::doLoad_xbPbDKQ()
{
	CxbRwBranch vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbPbDKQ");
	vRw.InitType(CxbDefs::PbDKQ, CxbDefs::PbDKQ);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();
}

void CxbRwMvc::doLoad_xbDCF()
{

	CxbRwDCF vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbDCF", "xbDCF_tree", "xbDCF_tree");
	vRw.InitType(CxbDefs::DCF, CxbDefs::DCF);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();
}

void CxbRwMvc::doLoad_xbDcLine()
{

	CxbRwDcLine vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbDcLine", "xbDcLine_tree", "xbDcLine_tree");
	vRw.InitType(CxbDefs::DCLine, CxbDefs::DCLine);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();
}

void CxbRwMvc::doLoad_xbGroundLine()
{

	CxbRwGroundLine vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbGroundLine", "xbGroundLine_tree", "xbGroundLine_tree");
	vRw.InitType(CxbDefs::GroundLine, CxbDefs::GroundLine);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();
}

void CxbRwMvc::doLoad_xbGround()
{

	CxbRwShunt vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbGround");
	vRw.InitType(CxbDefs::Ground, CxbDefs::Ground);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();
}

void CxbRwMvc::doLoad_xbXfC()
{

	CxbRwShunt vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbXf_C");
	vRw.InitType(CxbDefs::XfC, CxbDefs::XfC);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();
}

void CxbRwMvc::doLoad_xbCoupleC()
{

	CxbRwShunt vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbCouple_C");
	vRw.InitType(CxbDefs::CoupleC, CxbDefs::CoupleC);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();
}

void CxbRwMvc::doLoad_xbPulseC()
{

	CxbRwShunt vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbPulse_C");
	vRw.InitType(CxbDefs::PulseC, CxbDefs::PulseC);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();
}

void CxbRwMvc::doLoad_xbShunt()
{

	CxbRwShunt vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbShunt");
	vRw.InitType(CxbDefs::Shunt, CxbDefs::Shunt);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();
}

void CxbRwMvc::doLoad_xbBranch()
{

	CxbRwBranch vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbBranch");
	vRw.InitType(CxbDefs::Branch, CxbDefs::Branch);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();
}

void CxbRwMvc::doLoad_xbMonitor()
{

	CxbRwRLCs vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbMonitor", "xbMonitor_tree", "xbMonitor_tree");
	vRw.InitType(CxbDefs::Monitor, CxbDefs::Monitor);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();
}

void CxbRwMvc::doLoad_xbTrap()
{

	CxbRwRLCs vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbTrap", "xbTrap_tree", "xbTrap_tree");
	vRw.InitType(CxbDefs::Trap, CxbDefs::Trap);
	vRw.InitGrid(pHvdc);

	vRw.OnLoad();
}


void CxbRwMvc::doSave_xbUsrc3p()
{

	CxbRw3pVSrc vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xb3pVsrc");
	vRw.InitType(CxbDefs::Usrc3p, CxbDefs::Usrc3p);
	vRw.InitGrid(pHvdc);

	vRw.OnSave();
}

void CxbRwMvc::doSave_xbPbDKQ()
{
	CxbRwBranch vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbPbDKQ");
	vRw.InitType(CxbDefs::PbDKQ, CxbDefs::PbDKQ);
	vRw.InitGrid(pHvdc);

	vRw.OnSave();
}

void CxbRwMvc::doSave_xbDCF()
{

	CxbRwDCF vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbDCF", "xbDCF_tree", "xbDCF_tree");
	vRw.InitType(CxbDefs::DCF, CxbDefs::DCF);
	vRw.InitGrid(pHvdc);

	vRw.OnSave();
}

void CxbRwMvc::doSave_xbDcLine()
{

	CxbRwDcLine vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbDcLine", "xbDcLine_tree", "xbDcLine_tree");
	vRw.InitType(CxbDefs::DCLine, CxbDefs::DCLine);
	vRw.InitGrid(pHvdc);

	vRw.OnSave();
}

void CxbRwMvc::doSave_xbGroundLine()
{

	CxbRwGroundLine vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbGroundLine", "xbGroundLine_tree", "xbGroundLine_tree");
	vRw.InitType(CxbDefs::GroundLine, CxbDefs::GroundLine);
	vRw.InitGrid(pHvdc);

	vRw.OnSave();
}

void CxbRwMvc::doSave_xbGround()
{

	CxbRwShunt vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbGround");
	vRw.InitType(CxbDefs::Ground, CxbDefs::Ground);
	vRw.InitGrid(pHvdc);

	vRw.OnSave();
}

void CxbRwMvc::doSave_xbXfC()
{

	CxbRwShunt vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbXf_C");
	vRw.InitType(CxbDefs::XfC, CxbDefs::XfC);
	vRw.InitGrid(pHvdc);

	vRw.OnSave();
}

void CxbRwMvc::doSave_xbCoupleC()
{

	CxbRwShunt vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbCouple_C");
	vRw.InitType(CxbDefs::CoupleC, CxbDefs::CoupleC);
	vRw.InitGrid(pHvdc);

	vRw.OnSave();
}

void CxbRwMvc::doSave_xbPulseC()
{

	CxbRwShunt vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbPulse_C");
	vRw.InitType(CxbDefs::PulseC, CxbDefs::PulseC);
	vRw.InitGrid(pHvdc);

	vRw.OnSave();
}

void CxbRwMvc::doSave_xbShunt()
{

	CxbRwShunt vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbShunt");
	vRw.InitType(CxbDefs::Shunt, CxbDefs::Shunt);
	vRw.InitGrid(pHvdc);

	vRw.OnSave();
}

void CxbRwMvc::doSave_xbBranch()
{

	CxbRwBranch vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbBranch");
	vRw.InitType(CxbDefs::Branch, CxbDefs::Branch);
	vRw.InitGrid(pHvdc);

	vRw.OnSave();
}

void CxbRwMvc::doSave_xbMonitor()
{

	CxbRwRLCs vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbMonitor", "xbMonitor_tree", "xbMonitor_tree");
	vRw.InitType(CxbDefs::Monitor, CxbDefs::Monitor);
	vRw.InitGrid(pHvdc);

	vRw.OnSave();
}

void CxbRwMvc::doSave_xbTrap()
{

	CxbRwRLCs vRw;

	vRw.InitAdo(RwAdo);
	vRw.InitTable("xbTrap", "xbTrap_tree", "xbTrap_tree");
	vRw.InitType(CxbDefs::Trap, CxbDefs::Trap);
	vRw.InitGrid(pHvdc);

	vRw.OnSave();
}
	