///////////////////////////////////////////////////////////
//  CWire.h
// 
//  Created on:      27-4月-2017 17:24:53
///////////////////////////////////////////////////////////
#pragma once

#include "gbHead_MyType.h"

#include "CxbDefs.h"
#include "CMatrix.h"
#include "CxbParams.h"


//#include "FacilitieBase.h"
//线路基类


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

	/************** 获取wire类参数值函数 **************/
	double get_Long() const{ return Long; }

	CMatrix get_Y() { return Y; }
	CMatrix get_Z() { return Z; }
	CMatrix get_C() { return C; }

public:

	/************** 设置wire类参数值函数 **************/
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





	/********计算初始参数相关函数**********/

	//计算导体分裂数目*******输入导体编号，返回分裂数目
	double doCal_SplitAmount(unsigned int vi);
	//计算镜像距离D矩阵********输入初始化的v_D矩阵容器
	void doCal_D(dbMatrix &v_D);

	//计算导线间距d矩阵*****************v_d存储数据
	void  doCal_d(dbMatrix &v_d);

	//计算导体间的水平距离矩阵**********v_Hspace存放数据
	void doCal_Hspace(dbMatrix &v_Hspace);
	//计算各导体间的镜像高度**********v_Height存放数据
	void doCal_Height(dbMatrix &v_Height);

	//计算各导体的平均高度********输入导体编号，返回高度值
	double doCal_AvHeight(unsigned int vWireNum);

	//计算各导线的等值半径**********输入导体编号，返回半径值
	double doCal_EqRadius(unsigned int vWireNum);

	//计算几何参数b矩阵*********输入初始化的b矩阵容器
	void  doCal_b(dbMatrix &v_b);

	//计算几何参数Theta矩阵*******输入初始化的v_Th矩阵容器
	void  doCal_Th(dbMatrix &v_Th);

	//计算r矩阵********输入频率w，初始化的v_Z_r矩阵容器
	void  doCal_r(double v_w, dbMatrix &v_Z_r);

	//计算各导线的磁导率*********输入导体编号，返回磁导率（默认为真空磁导率）
	double doCal_CondMU(unsigned int vWireNum);

	//选择导体的半径值*********输入导体编号，返回导体半径
	double doCal_CondRadius(unsigned int vWireNum);

	//计算导线电导率***********输入导体编号，返回导体电导率
	double doCal_CondDelta(unsigned int vWireNum);

	//返回计算导线电导率时需要的导线参数***********输入导体编号，返回导线参数
	void doCal_CondValue(unsigned int vWireNum, double &v_CondValue, unsigned int &v_CondType);





	/*************计算Y矩阵相关函数**************/

	//调用该函数可得到Y12矩阵
	void CalMatrix_Y(double vOmega);

	//Y=jwC，计算C12矩阵
	void doCalMatrix_C();

	//C=P求逆，计算P12矩阵（包含把P矩阵拆分为K、L、M、N四部分）
	void doCalMatrix_P(CMatrix &v_Y_P);

	void doCal_YK(CMatrix &v_YK, dbMatrix &v_b);
	void doCal_YL(CMatrix &v_YL, dbMatrix &v_b);
	void doCal_YM(CMatrix &v_YM, dbMatrix &v_b);
	void doCal_YN(CMatrix &v_YN, dbMatrix &v_b);





	/***************************计算Z矩阵相关函数*****************************/

	//调用该函数可得到Z12矩阵
	void CalMatrix_Z(double vOmega);

	//Z矩阵拆分为A、B、C、D四部分，计算Z12矩阵时需要
	//void doCal_Z_ABCD(double v_w, CMatrix &v_ZA, CMatrix &v_ZB, CMatrix &v_ZC, CMatrix &v_ZD);

	void doCal_Z_A(CMatrix &v_Z_A, dbMatrix &v_Z_R, dbMatrix &v_Z_L);
	void doCal_Z_B(CMatrix &v_Z_B, dbMatrix &v_Z_R, dbMatrix &v_Z_L);
	void doCal_Z_C(CMatrix &v_Z_C, dbMatrix &v_Z_R, dbMatrix &v_Z_L);
	void doCal_Z_D(CMatrix &v_Z_D, dbMatrix &v_Z_R, dbMatrix &v_Z_L);

	//Z=R+jwL,分别计算R和L矩阵，合成Z矩阵
	void doCal_Z_RL(double v_w, dbMatrix &v_Z_R, dbMatrix &v_Z_L);

	//L=Li+Le+Lc,R=Re+Rc
	void doCal_Z_Li(dbMatrix &v_Z_Li);
	void doCal_Z_ReLe(double v_w, dbMatrix &v_Z_Re, dbMatrix &v_Z_Le);
	void doCal_Z_RcLc(double v_w, doubleVector &v_Z_Rc, doubleVector &v_Z_Lc);

	//计算Rc和Lc时需要计算x的值
	double doCal_RcLc_x(unsigned int vWireNum, double v_w);
	/***************************计算Z矩阵相关函数*****************************/


	//protected:
public:
	CMatrix C;
	CMatrix Y;
	CMatrix Z;




	double Long;//线路长度
	int WireCount;//直流线路中输电线和避雷线总数

	double Hspace[3];//导线水平间距

	double Height[3];//导线高度


	double L_CondRadius; //传输线单根导体半径
	double G_CondRadius;//避雷线单导体半径

	double Sag[3];     //传输线弧垂


	int L_CondType;//传输线电导率给定方式
	double L_CondValue;//计算电导率对应方式的给定值

	int G_CondType;//避雷线电导率给定方式
	double G_CondValue;//计算电导率对应方式的给定值

	int L_SplitAmount;//传输线分裂数
	int G_SplitAmount;//避雷线分裂数


	double L_BundleSpace;//传输线分裂间距
	double G_BundleSpace;//避雷线分裂间距

	double SoilRe;  //土壤电阻率

};