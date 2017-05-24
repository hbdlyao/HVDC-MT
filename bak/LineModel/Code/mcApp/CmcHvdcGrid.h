///////////////////////////////////////////////////////////
//  CmcHvdcGrid.h
//  Implementation of the Class CmcHvdcGrid
//  Created on:      21-5��-2017 0:51:09
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
	// *�Ϸ���������·��г����������*
	// �Ķ�����:  NewGrid
	// �Ķ���:    �޿���
	// �Ķ�����:  �޸�
	// �Ķ�����:  1.ʵ��NewGrid��������
	// �Ķ�ʱ��:  2017/05/23
	//************************************
	void NewGrid(StrVector vStaNames) override;

protected:
	CDevTBL * doNewDevTBL(int vType) override;
	
	//************************************
	// *�Ϸ���������·��г����������*
	// �Ķ�����:  NewAcFilterTBL��NewXf2TBL
	// �Ķ���:    �޿���
	// �Ķ�����:  ����
	// �Ķ�����:  1.����һ������վ��Ӧ�豸���͵��豸
	// �Ķ�ʱ��:  2017/05/23
	//************************************
	void NewAcFilterTBL(string vStaName);
	void NewAcSysTBL(string vStaName);
	void NewConvertorTBL(string vStaName);
	void NewXf2TBL(string vStaName);

};
#endif // !defined(EA_2E6C5B36_5C59_4483_AB40_C1D34BA592F1__INCLUDED_)