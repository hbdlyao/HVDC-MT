///////////////////////////////////////////////////////////
//  CmcRwResultMvc.h
//  Implementation of the Class CmcRwResultMvc
//  Created on:      18-4月-2017 22:36:27
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_11167C37_E871_41bd_84C9_811928AC7302__INCLUDED_)
#define EA_11167C37_E871_41bd_84C9_811928AC7302__INCLUDED_

#include "CMyRwMvc.h"
#include "CmcResult.h"

class CmcRwResultMvc : public CMyRwMvcAccess
{
protected:
	CmcResult * pResult;

public:
	void Init(CmcResult* vRes);

protected:
	void doLoad() override;
	void doLoad(struct_mcResultData *vResult);//

	//************************************
	// *南方电网主回路及谐波计算软件*
	// 改动对象:  doSave
	// 改动者:    崔康生[第二波]
	// 改动类型:  重写两个函数
	// 改动内容:  1.原有的两个doSave暂时更名为doSave1，新的doSave采用二进制Blob形式存储
	// 改动时间:  2017/05/27
	//************************************
	void doSave1();
	void doSave1(struct_mcResultData vResult);
	void doSave() override;
	void doSave(struct_mcResultData vResult);
};
#endif // !defined(EA_11167C37_E871_41bd_84C9_811928AC7302__INCLUDED_)
