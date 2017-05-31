///////////////////////////////////////////////////////////
//  CLineModel.h
// 
//  Created on:      27-4��-2017 17:24:53
///////////////////////////////////////////////////////////
#pragma once

#include "CxbDefs.h"
#include "CWire.h"
#include "CxbParams.h"


class CLineModel
{
public:
	CLineModel(){}

	~CLineModel(){}

	CMatrix get_Z(unsigned int vk)const{ return Z[vk]; }
	CMatrix get_Y(unsigned int vk)const{ return Y[vk]; }
	CMatrix get_Yss(unsigned int vk)const{ return Yss[vk]; }
	CMatrix get_Ymm(unsigned int vk)const{ return Ymm[vk]; }

	double get_L() const{ return L; }

	double get_SegLength(){ return SegLength; }
	unsigned int get_SegCount(){ return SegCount; }

	CMatrix get_AllLine_Y(unsigned int vk) { return AllLine_Y[vk]; }

	//������·�ܵ��ɾ���
	void CalAllLine();
	//������·�ֶγ��Ⱥͷֶ���Ŀ
	void doCal_SegLength(unsigned int k);
	//���㵥����·���Ե��ɺͻ����ɾ���
	void doCal_YsYm(unsigned int k);
	//���㼶����T����
	void doCal_TMat(unsigned int k, CMatrix &v_TMat);


	//protected:

	double SegLength;//ȫ����·�ֶγ���
	unsigned int SegCount;//ȫ����·�ֶ���Ŀ
	CMatrix * Z;//��ͬƵ�εĵ�����·Z����[г������] 
	CMatrix * Y;//��ͬƵ�εĵ�����·Y����[г������]
	double L;//��·����

	CMatrix * Ys;//��·�ֶ��Ե�����
	CMatrix	* Ym;//��·�ֶλ�������
	CMatrix * Yss;//��·���Ե�����
	CMatrix	* Ymm;//��·�ܻ�������

	CMatrix * AllLine_Y;//��·�ܵ�����

public:

	//����������ʼƵ��
	double FreqStart;

	//Ƶ�����ӵĲ���
	double FreqStep;

	//��������Ƶ������
	int	FreqDim;

	//��ʼ��г��������������Ĳ���
	void Init_xbCurrentY();

	//��ʼ���迹ɨ���������
	void Init_ImScanY(double vFreqStart, double vFreqStep, int vFreqDim);

	//
	void Clear();

	void doInitY();

	Cwire WireParam;

private:

	//���ص�k��Ƶ�ʶ�Ӧ��Omega
	double Omega(int k);
};

