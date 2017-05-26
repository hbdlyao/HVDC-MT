///////////////////////////////////////////////////////////
//  CmcDevXf2.cpp
//  Implementation of the Class CmcDevXf2
//  Created on:      04-4月-2017 7:26:45
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcDevXf2.h"

/**
* 额定变比
*/
double CmcDevXf2::GetTkN() {

	return TkN;
}

/**
* 网侧额定交流电压
*/
double CmcDevXf2::GetUacN() {

	return UacN;
}


/**
* 短路阻抗百分比
*/
double CmcDevXf2::GetUkp() {

	return Ukp;
}


/**
* 阻性压降百分比
*/
double CmcDevXf2::GetUrp() {

	return Urp;
}


/**
* 阀侧最大交流电压
*/
double CmcDevXf2::GetUvMax() {

	return UvMax;
}


/**
* 阀侧额定交流电压
*/
double CmcDevXf2::GetUvN() {

	return UvN;
}


/**
* 触发角/关断角最大值
*/
void CmcDevXf2::SetAngleMax(double newVal) {

	AngleMax = newVal;
}


/**
* 触发角/关断角最小值
*/
void CmcDevXf2::SetAngleMin(double newVal) {

	AngleMin = newVal;
}


/**
* 定电压参考值
*/
void CmcDevXf2::SetFixedURef(double newVal) {

	FixedURef = newVal;
}


/**
* 分接头控制类型
*/
void CmcDevXf2::SetTapCtrlType(int newVal) {

	TapCtrlType = newVal;
}


/**
* 分接头最大档位
*/
void CmcDevXf2::SetTapMax(int newVal) {

	TapMax = newVal;
}


/**
* 分接头最小档位
*/
void CmcDevXf2::SetTapMin(int newVal) {

	TapMin = newVal;
}


/**
* 分接头额定档位
*/
void CmcDevXf2::SetTapN(int newVal) {

	TapN = newVal;
}


/**
* 分解头调整步长
*/
void CmcDevXf2::SetTapSetup(double newVal) {

	TapSetup = newVal;
}


/**
* 额定变比
*/
void CmcDevXf2::SetTkN(double newVal) {

	TkN = newVal;
}


/**
* 网侧额定交流电压
*/
void CmcDevXf2::SetUacN(double newVal) {

	UacN = newVal;
}


/**
* 短路阻抗百分比
*/
void CmcDevXf2::SetUkp(double newVal) {

	Ukp = newVal;
}


/**
* 阻性压降百分比
*/
void CmcDevXf2::SetUrp(double newVal) {

	Urp = newVal;
}

/**
* 阀侧最大交流电压
*/
void CmcDevXf2::SetUvMax(double newVal) {

	UvMax = newVal;
}


/**
* 阀侧额定交流电压
*/
void CmcDevXf2::SetUvN(double newVal) {

	UvN = newVal;
}

int CmcDevXf2::GetFixedUType()
{
	return FixedUType;
}

void CmcDevXf2::SetFixedUType(int newValue)
{
	FixedUType = newValue;
}

/**
* 触发角/关断角最大值
*/
double CmcDevXf2::GetAngleMax() {

	return AngleMax;
}


/**
* 触发角/关断角最小值
*/
double CmcDevXf2::GetAngleMin() {

	return AngleMin;
}


/**
* 定电压参考值
*/
double CmcDevXf2::GetFixedURef() {

	return FixedURef;
}


/**
* 分接头控制类型
*/
int CmcDevXf2::GetTapCtrlType() {

	return TapCtrlType;
}


/**
* 分接头最大档位
*/
int CmcDevXf2::GetTapMax() {

	return TapMax;
}


/**
* 分接头最小档位
*/
int CmcDevXf2::GetTapMin() {

	return TapMin;
}


/**
* 分接头额定档位
*/
int CmcDevXf2::GetTapN() {

	return TapN;
}


/**
* 分解头调整步长
*/
double CmcDevXf2::GetTapSetup() {

	return TapSetup;
}