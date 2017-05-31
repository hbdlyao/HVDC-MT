///////////////////////////////////////////////////////////
//  CmcDevConvertor.h
//  Implementation of the Class CmcDevConvertor
//  Created on:      22-4��-2017 14:50:22
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_3944D79B_EBB3_4e20_A648_D87046C2B582__INCLUDED_)
#define EA_3944D79B_EBB3_4e20_A648_D87046C2B582__INCLUDED_

#include "CmcDevTwo.h"

/**
 * ������
 */
class CmcDevConvertor : public CmcDevTwo
{

public:
	/**
	 * �������/�ضϽ�
	 */
	double GetAlpha_gamaN();
	/**
	 * ������/�ضϽ����ֵ
	 */
	double GetAngleMax();
	/**
	 * ������/�ضϽ���Сֵ
	 */
	double GetAngleMin();
	/**
	 * �ֱ������
	 */
	double GetPdN();
	/**
	 * �ֱ����ѹ
	 */
	double GetUdN();
	/**
	 * 6��������ͨѹ��
	 */
	double GetUT();
	/**
	 * ÿ��12������������
	 */
	int GetValvor12Count();
	double GetUdioN();
	/**
	 * ������ѹ
	 */
	double GetUvN();
	/**
	 * ֱ������,������ó�
	 */
	double GetIdN();
	/**
	 * ���������ͣ�������䣩
	 */
	int GetStationType();
	/**
	 * �������������ͣ��������������ʣ�����ѹ��
	 */
	int GetStationCtrlType();
	int GetStationCtrlTypeN();
	int GetIsGround();
	double GetAngleRef();
	/**
	 * ����վ
	 */
	string GetMeasureStation();
	double GetPconvN();
	double GetQconvN();
	double GetmiuN();
	/**
	 * �������/�ضϽ�
	 */
	void SetAlpha_gamaN(double newVal);
	/**
	 * ������/�ضϽ����ֵ
	 */
	void SetAngleMax(double newVal);
	/**
	 * ������/�ضϽ���Сֵ
	 */
	void SetAngleMin(double newVal);
	/**
	 * �ֱ������
	 */
	void SetPdN(double newVal);
	/**
	 * �ֱ����ѹ
	 */
	void SetUdN(double newVal);
	/**
	 * 6��������ͨѹ��
	 */
	void SetUT(double newVal);
	/**
	 * ÿ��12������������
	 */
	void SetValvor12Count(int newVal);
	void SetUdioN(double newVal);
	/**
	 * ������ѹ
	 */
	void SetUvN(double newVal);
	/**
	 * ֱ������,������ó�
	 */
	void SetIdN(double newVal);
	/**
	 * ���������ͣ�������䣩
	 */
	void SetStationType(int newVal);
	/**
	 * �������������ͣ��������������ʣ�����ѹ��
	 */
	void SetStationCtrlType(int newVal);
	void SetStationCtrlTypeN(int newVal);
	void SetIsGround(int newVal);
	void SetAngleRef(double newVal);
	/**
	 * ����վ
	 */
	void SetMeasureStation(string newVal);
	void SetPconvN(double newVal);
	void SetQconvN(double newVal);
	void SetmiuN(double newVal);

protected:
	double PconvN;
	double QconvN;
	double miuN;
	/**
	 * �������/�ضϽ�
	 */
	double Alpha_gamaN;
	/**
	 * ������/�ضϽ����ֵ
	 */
	double AngleMax;
	/**
	 * ������/�ضϽ���Сֵ
	 */
	double AngleMin;
	/**
	 * �ֱ������
	 */
	double PdN;
	/**
	 * �ֱ����ѹ
	 */
	double UdN;
	/**
	 * 6��������ͨѹ��
	 */
	double UT;
	/**
	 * ÿ��12������������
	 */
	int Valvor12Count;
	double UdioN;
	/**
	 * ������ѹ
	 */
	double UvN;
	/**
	 * ֱ������,������ó�
	 */
	double IdN;
	/**
	 * ���������ͣ�������䣩
	 */
	int StationType;
	/**
	 * �������������ͣ��������������ʣ�����ѹ��
	 */
	int StationCtrlType;
	int StationCtrlTypeN;
	int IsGround;
	double AngleRef;
	string MeasureStation;

};
#endif // !defined(EA_3944D79B_EBB3_4e20_A648_D87046C2B582__INCLUDED_)
