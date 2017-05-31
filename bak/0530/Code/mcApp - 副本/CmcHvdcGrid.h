///////////////////////////////////////////////////////////
//  CmcHvdcGrid.h
//  Implementation of the Class CmcHvdcGrid
//  Created on:      21-5月-2017 0:51:09
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_2E6C5B36_5C59_4483_AB40_C1D34BA592F1__INCLUDED_)
#define EA_2E6C5B36_5C59_4483_AB40_C1D34BA592F1__INCLUDED_

#include "CPowerGrid.h"

class CmcHvdcGrid : public CPowerGrid
{
public:
	string TypeToName(int vType) override;
	void Init() override;
public:
	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  NewGrid
	// 改动者:    崔康生
	// 改动类型:  修改
	// 改动内容:  1.实现NewGrid方法功能
	// 改动时间:  2017/05/23
	//************************************
	void NewGrid(StrVector vStaNames) override;

protected:
	CDevTBL * doNewDevTBL(int vType) override;
	
	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  NewAcFilterTBL至NewXf2TBL
	// 改动者:    崔康生
	// 改动类型:  新增
	// 改动内容:  1.创建一个换流站对应设备类型的设备
	// 改动时间:  2017/05/23
	//************************************
	void NewAcFilterTBL(string vStaName);
	void NewAcSysTBL(string vStaName);
	void NewConvertorTBL(string vStaName);
	void NewXf2TBL(string vStaName);

};
#endif // !defined(EA_2E6C5B36_5C59_4483_AB40_C1D34BA592F1__INCLUDED_)
