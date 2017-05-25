///////////////////////////////////////////////////////////
//  CRand.h
//  Created on:      10-4月-2017 
//  Original author: 马骏鹏
///////////////////////////////////////////////////////////

#pragma once

#include <time.h>
#include <random>

enum Enum_Distribution
{
	//常数
	Const_Dis = -1,
	//均匀分布
	Real_Dis = 0,
	//正态分布
	Norm_Dis = 1
};
extern std::default_random_engine glseed;

class CRand
{
public:
	CRand(double va, double vb, Enum_Distribution vtype);
	~CRand();
	double getVal();

	std::uniform_real_distribution<double> * pRandreal;
	std::normal_distribution<double> * pRandnormal;

	int RandType;
	double buf;
};