#pragma once

#include <string>
#include <map>

using namespace std;

#define M_PI 3.14159265358979323846
#define Epsilon 0.00001


//圆周率
#define PI 3.141592653589793

//真空介电常数
#define EPSILON (8.854187817/1000000000000)//真空介电常数

//真空磁导率
#define MU		(4*PI/10000000)		 


enum Enum_HvdcConvertorType
{
	Hvdc_Rectify = 0,
	Hvdc_Invertor = 1,

};


enum Enum_GroundType
{
	Ground10 = 10,
	Ground11 = 11,
	Ground20 = 20,
	Ground21 = 21

};

enum Enum_UdLevel
{
	Ud_Full = 0,
	Ud_Per80,
	Ud_Per70,
	Ud_Custom
};
enum Enum_RdLevel
{
	Rd_High = 0,
	Rd_Low,
	Rd_Normal
};

enum Enum_UacLevel
{
	Uac_Max = 0,
	Uac_Norm,
	Uac_Min,
	Uac_ExMin
};


const int GndTypeArr[] = { Ground10, Ground11, Ground20, Ground21 };
const int RdLevelArr[] = { Rd_High, Rd_Low, Rd_Normal };
const int UdLevelArr[] = { Ud_Full, Ud_Per80, Ud_Per70, Ud_Custom };
const int UacLevelArr[] = { Uac_Max, Uac_Norm, Uac_Min, Uac_ExMin };


struct struct_Branch
{

public:
	/**
	* 电阻
	*/
	double Zr=0;
	/**
	* 感抗
	*/
	double Zx_L=0;
	/**
	* 容抗
	*/
	double Zx_C=0;
	/**
	* 电感
	*/
	double Z_L=0;
	/**
	* 电容
	*/
	double Z_C=0;

};

/*
struct struct_LineParam
{
double Ys11re;
double Ys11im;

double Ys12re;
double Ys12im;

double Ym11re;
double Ym11im;

double Ym12re;
double Ym12im;
};
*/

