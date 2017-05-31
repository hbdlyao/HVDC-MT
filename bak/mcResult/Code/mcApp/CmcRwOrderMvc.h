///////////////////////////////////////////////////////////
//  CmcRwOrderMvc.h
//  Implementation of the Class CmcRwOrderMvc
//  Created on:      18-4ÔÂ-2017 22:36:22
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_2329C3EB_F3AD_46e9_80FA_F0DBFD7B8ECE__INCLUDED_)
#define EA_2329C3EB_F3AD_46e9_80FA_F0DBFD7B8ECE__INCLUDED_

#include "CMyRwMvc.h"
#include "CmcOrder.h"

class CmcRwOrderMvc : public CMyRwMvcAccess
{
protected:
	CmcOrder * pOrder;
public:
	void Init(CmcOrder* vOrder);

	void OnLoad(string vdbf) override;
	void OnLoad() override;

	void OnSave() override;

protected:
	void doLoad() override;
	void doLoad_UdCustom();
	//void doLoad_CaseID();

	void doSave() override;
	void doSave_UdCustom();
};
#endif // !defined(EA_2329C3EB_F3AD_46e9_80FA_F0DBFD7B8ECE__INCLUDED_)
