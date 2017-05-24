///////////////////////////////////////////////////////////
//  CLineModel.h
// 
//  Created on:      27-4月-2017 17:24:53
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

	//计算线路总导纳矩阵
	void CalAllLine();
	//计算线路分段长度和分段数目
	void doCal_SegLength(unsigned int k);
	//计算单段线路的自导纳和互导纳矩阵
	void doCal_YsYm(unsigned int k);
	//计算级联用T矩阵
	void doCal_TMat(unsigned int k, CMatrix &v_TMat);


	//protected:

	double SegLength;//全长线路分段长度
	unsigned int SegCount;//全长线路分段数目
	CMatrix * Z;//不同频次的单长线路Z矩阵[谐波次数] 
	CMatrix * Y;//不同频次的单长线路Y矩阵[谐波次数]
	double L;//线路长度

	CMatrix * Ys;//线路分段自导纳阵
	CMatrix	* Ym;//线路分段互导纳阵
	CMatrix * Yss;//线路总自导纳阵
	CMatrix	* Ymm;//线路总互导纳阵

	CMatrix * AllLine_Y;//线路总导纳阵

public:

	//所需计算的起始频率
	double FreqStart;

	//频率增加的步长
	double FreqStep;

	//所需计算的频率数量
	int	FreqDim;

	//初始化谐波电流计算所需的参数
	void Init_xbCurrentY();

	//初始化阻抗扫描所需参数
	void Init_ImScanY(double vFreqStart, double vFreqStep, int vFreqDim);

	//
	void Clear();

	void doInitY();

	Cwire WireParam;

private:

	//返回第k个频率对应的Omega
	double Omega(int k);
};

