///////////////////////////////////////////////////////////
//  CdcProject.h
//  Implementation of the Class CDcProject
//  Created on:      23-3��-2017 20:17:20
//  Original author: Administrator
///////////////////////////////////////////////////////////

#if !defined(EA_63D056D3_1C4F_45ff_87CB_6CFC1319D914__INCLUDED_)
#define EA_63D056D3_1C4F_45ff_87CB_6CFC1319D914__INCLUDED_

class CDcProject
{

public:
	CDcProject();
	CDcProject(CDcProject theCDcProject);
	/**
	 * ֱ�����̶���
	 */
	int ConvertorCount();
	/**
	 * ����ϵͳƵ��
	 */
	int Frequency();
	/**
	 * �ӵ�����
	 */
	int GroudType();
	int ID();
	/**
	 * ֱ������ˮƽ
	 */
	int PdLevel();
	/**
	 * �������ͣ�����/˫����
	 */
	int PoleType();
	/**
	 * ���߶Դ��/�����ߵ�ѹ
	 */
	int PoleVoltage();
	/**
	 * ֱ����������
	 */
	int ProjectName();
	/**
	 * ֱ����������
	 */
	int ProjectType();
	/**
	 * �ֽ�ͷ��������
	 */
	int TapCtrlType();
	/**
	 * ֱ����ѹ
	 */
	int Ud();
	/**
	 * ֱ����ѹˮƽ
	 */
	int UdcLevel();
	/**
	 * �ֱ����ѹ
	 */
	int UdN();
	/**
	 * ÿ��12������������
	 */
	int Valor12Count();
	/**
	 * �������ͣ�����/���裩
	 */
	int ZrType();

private:
	~CDcProject();

};
#endif // !defined(EA_63D056D3_1C4F_45ff_87CB_6CFC1319D914__INCLUDED_)
