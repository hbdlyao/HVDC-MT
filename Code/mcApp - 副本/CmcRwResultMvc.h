///////////////////////////////////////////////////////////
//  CmcRwResultMvc.h
//  Implementation of the Class CmcRwResultMvc
//  Created on:      18-4��-2017 22:36:27
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
	// *�Ϸ���������·��г���������*
	// �Ķ�����:  doSave
	// �Ķ���:    �޿���[�ڶ���]
	// �Ķ�����:  ��д��������
	// �Ķ�����:  1.ԭ�е�����doSave��ʱ����ΪdoSave1���µ�doSave���ö�����Blob��ʽ�洢
	// �Ķ�ʱ��:  2017/05/27
	//************************************
	void doSave1();
	void doSave1(struct_mcResultData vResult);
	void doSave() override;
	void doSave(struct_mcResultData vResult);
};
#endif // !defined(EA_11167C37_E871_41bd_84C9_811928AC7302__INCLUDED_)
