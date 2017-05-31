///////////////////////////////////////////////////////////
//  CRand.h
//  Created on:      10-4��-2017 
//  Original author: ����
///////////////////////////////////////////////////////////

#pragma once

#include <time.h>
#include <random>

enum Enum_Distribution
{
	//����
	Const_Dis = -1,
	//���ȷֲ�
	Real_Dis = 0,
	//��̬�ֲ�
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