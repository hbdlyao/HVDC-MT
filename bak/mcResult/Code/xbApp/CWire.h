///////////////////////////////////////////////////////////
//  CWire.h
// 
//  Created on:      27-4��-2017 17:24:53
///////////////////////////////////////////////////////////
#pragma once

#include "gbHead_MyType.h"

#include "CxbDefs.h"
#include "CMatrix.h"
#include "CxbParams.h"


//#include "FacilitieBase.h"
//��·����


class Cwire
{
public:
	Cwire()
	{
		//WireCount = 3;
		//Height[0] = 27;
		//Height[1] = 4;
		//Hspace[0] = 6;
		//Hspace[1] = 0;
		//Sag[0] = 15;
		//Sag[1] = 12;

		//G_BundleSpace = 0;
		//G_CondRadius = 0.0057;
		//G_CondType = 2;
		//G_CondValue = 2.42;

		//G_SplitAmount = 1;
		//Long = 28;
		//L_BundleSpace = 0.4;
		//L_CondRadius = 0.01197;
		//L_CondType = 2;
		//L_CondValue = 0.0977;

		//L_SplitAmount = 2;
		//SoilRe = 1500;
	};
	~Cwire(){};

	/************** ��ȡwire�����ֵ���� **************/
	double get_Long() const{ return Long; }

	CMatrix get_Y() { return Y; }
	CMatrix get_Z() { return Z; }
	CMatrix get_C() { return C; }

public:

	/************** ����wire�����ֵ���� **************/
	void set_Long(double vl) { Long = vl; }

	void set_WireCount(int vn) { WireCount = vn; }

	void set_Hspace(int vID, double vNewVal)
	{
		Hspace[vID] = vNewVal;
	}

	void set_Height(int vID, double vNewVal)
	{
		Height[vID] = vNewVal;
	}


	void set_L_CondRadius(double vl) { L_CondRadius = vl; }
	void set_G_CondRadius(double vl) { G_CondRadius = vl; }

	void set_L_CondType(unsigned int vl){ L_CondType = vl; }
	void set_L_CondValue(double vl) { L_CondValue = vl; }

	void set_G_CondType(unsigned int vl) { G_CondType = vl; }
	void set_G_CondValue(double vl) { G_CondValue = vl; }

	void set_Sag(int vID, double vNewVal)
	{
		Sag[vID] = vNewVal;
	}


	void set_L_SplitAmount(unsigned int vl) { L_SplitAmount = vl; }
	void set_G_SplitAmount(unsigned int vl) { G_SplitAmount = vl; }

	void set_L_BundleSpace(double vl) { L_BundleSpace = vl; }
	void set_G_BundleSpace(double vl) { G_BundleSpace = vl; }

	void set_SoilRe(double vl){ SoilRe = vl; }





	/********�����ʼ������غ���**********/

	//���㵼�������Ŀ*******���뵼���ţ����ط�����Ŀ
	double doCal_SplitAmount(unsigned int vi);
	//���㾵�����D����********�����ʼ����v_D��������
	void doCal_D(dbMatrix &v_D);

	//���㵼�߼��d����*****************v_d�洢����
	void  doCal_d(dbMatrix &v_d);

	//���㵼����ˮƽ�������**********v_Hspace�������
	void doCal_Hspace(dbMatrix &v_Hspace);
	//����������ľ���߶�**********v_Height�������
	void doCal_Height(dbMatrix &v_Height);

	//����������ƽ���߶�********���뵼���ţ����ظ߶�ֵ
	double doCal_AvHeight(unsigned int vWireNum);

	//��������ߵĵ�ֵ�뾶**********���뵼���ţ����ذ뾶ֵ
	double doCal_EqRadius(unsigned int vWireNum);

	//���㼸�β���b����*********�����ʼ����b��������
	void  doCal_b(dbMatrix &v_b);

	//���㼸�β���Theta����*******�����ʼ����v_Th��������
	void  doCal_Th(dbMatrix &v_Th);

	//����r����********����Ƶ��w����ʼ����v_Z_r��������
	void  doCal_r(double v_w, dbMatrix &v_Z_r);

	//��������ߵĴŵ���*********���뵼���ţ����شŵ��ʣ�Ĭ��Ϊ��մŵ��ʣ�
	double doCal_CondMU(unsigned int vWireNum);

	//ѡ����İ뾶ֵ*********���뵼���ţ����ص���뾶
	double doCal_CondRadius(unsigned int vWireNum);

	//���㵼�ߵ絼��***********���뵼���ţ����ص���絼��
	double doCal_CondDelta(unsigned int vWireNum);

	//���ؼ��㵼�ߵ絼��ʱ��Ҫ�ĵ��߲���***********���뵼���ţ����ص��߲���
	void doCal_CondValue(unsigned int vWireNum, double &v_CondValue, unsigned int &v_CondType);





	/*************����Y������غ���**************/

	//���øú����ɵõ�Y12����
	void CalMatrix_Y(double vOmega);

	//Y=jwC������C12����
	void doCalMatrix_C();

	//C=P���棬����P12���󣨰�����P������ΪK��L��M��N�Ĳ��֣�
	void doCalMatrix_P(CMatrix &v_Y_P);

	void doCal_YK(CMatrix &v_YK, dbMatrix &v_b);
	void doCal_YL(CMatrix &v_YL, dbMatrix &v_b);
	void doCal_YM(CMatrix &v_YM, dbMatrix &v_b);
	void doCal_YN(CMatrix &v_YN, dbMatrix &v_b);





	/***************************����Z������غ���*****************************/

	//���øú����ɵõ�Z12����
	void CalMatrix_Z(double vOmega);

	//Z������ΪA��B��C��D�Ĳ��֣�����Z12����ʱ��Ҫ
	//void doCal_Z_ABCD(double v_w, CMatrix &v_ZA, CMatrix &v_ZB, CMatrix &v_ZC, CMatrix &v_ZD);

	void doCal_Z_A(CMatrix &v_Z_A, dbMatrix &v_Z_R, dbMatrix &v_Z_L);
	void doCal_Z_B(CMatrix &v_Z_B, dbMatrix &v_Z_R, dbMatrix &v_Z_L);
	void doCal_Z_C(CMatrix &v_Z_C, dbMatrix &v_Z_R, dbMatrix &v_Z_L);
	void doCal_Z_D(CMatrix &v_Z_D, dbMatrix &v_Z_R, dbMatrix &v_Z_L);

	//Z=R+jwL,�ֱ����R��L���󣬺ϳ�Z����
	void doCal_Z_RL(double v_w, dbMatrix &v_Z_R, dbMatrix &v_Z_L);

	//L=Li+Le+Lc,R=Re+Rc
	void doCal_Z_Li(dbMatrix &v_Z_Li);
	void doCal_Z_ReLe(double v_w, dbMatrix &v_Z_Re, dbMatrix &v_Z_Le);
	void doCal_Z_RcLc(double v_w, doubleVector &v_Z_Rc, doubleVector &v_Z_Lc);

	//����Rc��Lcʱ��Ҫ����x��ֵ
	double doCal_RcLc_x(unsigned int vWireNum, double v_w);
	/***************************����Z������غ���*****************************/


	//protected:
public:
	CMatrix C;
	CMatrix Y;
	CMatrix Z;




	double Long;//��·����
	int WireCount;//ֱ����·������ߺͱ���������

	double Hspace[3];//����ˮƽ���

	double Height[3];//���߸߶�


	double L_CondRadius; //�����ߵ�������뾶
	double G_CondRadius;//�����ߵ�����뾶

	double Sag[3];     //�����߻���


	int L_CondType;//�����ߵ絼�ʸ�����ʽ
	double L_CondValue;//����絼�ʶ�Ӧ��ʽ�ĸ���ֵ

	int G_CondType;//�����ߵ絼�ʸ�����ʽ
	double G_CondValue;//����絼�ʶ�Ӧ��ʽ�ĸ���ֵ

	int L_SplitAmount;//�����߷�����
	int G_SplitAmount;//�����߷�����


	double L_BundleSpace;//�����߷��Ѽ��
	double G_BundleSpace;//�����߷��Ѽ��

	double SoilRe;  //����������

};