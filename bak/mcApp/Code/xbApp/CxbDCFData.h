///////////////////////////////////////////////////////////
//  CxbDCFData.h
//  
//  Created on:      12-4月-2017 17:56:23
//  Original author: 马骏鹏
///////////////////////////////////////////////////////////

#pragma once


#include <string>
#include <map>
#include "CMydefs.h"
using namespace std;

struct CxbDCFOneTunedDev
{
	//实际偏差
	double ddC1 = 0;
	double ddL1 = 0;
	double ddR1 = 0;
	double ddf = 0;
};

struct CxbDCFTwoTunedDev
{
	//实际偏差
	double ddC1 = 0;
	double ddC2 = 0;
	double ddL1 = 0;
	double ddL2 = 0;
	double ddR1 = 0;
	double ddf = 0;
};

struct CxbDCFThreeTunedDev
{
	//实际偏差
	double ddC1 = 0;
	double ddC2 = 0;
	double ddC3 = 0;
	double ddL1 = 0;
	double ddL2 = 0;
	double ddL3 = 0;
	double ddR1 = 0;
	double ddR2 = 0;
	double ddf = 0;
};


struct CxbDCFOneTunedData
{
public:
	double C1;
	double L1;
	double R1;

	//输入偏差
	double PdC1;
	double PdL1;
	double PdR1;
	double Pdf;

	double NdC1;
	double NdL1;
	double NdR1;
	double Ndf;

	CxbDCFOneTunedDev * ConstDev;
	CxbDCFOneTunedDev * RandDev;

	double * ConstDevYg;
	double * ConstDevYb;

	double * RandDevYg;
	double * RandDevYb;
};



struct CxbDCFTwoTunedData
{
public:
	double C1;
	double C2;
	double L1;
	double L2;
	double R1;

	//输入偏差
	double PdC1;
	double PdC2;
	double PdL1;
	double PdL2;
	double PdR1;
	double Pdf;
	double NdC1;
	double NdC2;
	double NdL1;
	double NdL2;
	double NdR1;
	double Ndf;

	CxbDCFTwoTunedDev * ConstDev;
	CxbDCFTwoTunedDev * RandDev;

	double * ConstDevYg;
	double * ConstDevYb;

	double * RandDevYg;
	double * RandDevYb;
};




struct CxbDCFThreeTunedData
{
public:
	double C1;
	double C2;
	double C3;
	double L1;
	double L2;
	double L3;
	double R1;
	double R2;
	//输入偏差
	double PdC1;
	double PdC2;
	double PdC3;
	double PdL1;
	double PdL2;
	double PdL3;
	double PdR1;
	double PdR2;
	double Pdf;
	double NdC1;
	double NdC2;
	double NdC3;
	double NdL1;
	double NdL2;
	double NdL3;
	double NdR1;
	double NdR2;
	double Ndf;

	CxbDCFThreeTunedDev * ConstDev;
	CxbDCFThreeTunedDev * RandDev;

	double * ConstDevYg;
	double * ConstDevYb;

	double * RandDevYg;
	double * RandDevYb;
};




