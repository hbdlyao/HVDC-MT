///////////////////////////////////////////////////////////
//  CmcDevAcSys.cpp
//  Implementation of the Class CmcDevAcSys
//  Created on:      22-4月-2017 14:51:16
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcDevAcSys.h"

double CmcDevAcSys::GetQfMaxN(){

	return QfMaxN;
}


double CmcDevAcSys::GetQfMinN(){

	return QfMinN;
}


/**
 * 交流系统吸收最大无功
 */
double CmcDevAcSys::GetQinMax(){

	return QinMax;
}


/**
 * 交流系统发出最大无功
 */
double CmcDevAcSys::GetQoutMax(){

	return QoutMax;
}


/**
 * 交流电压极小值
 */
double CmcDevAcSys::GetUacExMin(){

	return UacExMin;
}


/**
 * 交流电压最大值
 */
double CmcDevAcSys::GetUacMax(){

	return UacMax;
}


/**
 * 交流电压最小值
 */
double CmcDevAcSys::GetUacMin(){

	return UacMin;
}


/**
 * 交流侧额定电压
 */
double CmcDevAcSys::GetUacN(){

	return UacN;
}


void CmcDevAcSys::SetQfMaxN(double newVal){

	QfMaxN = newVal;
}


void CmcDevAcSys::SetQfMinN(double newVal){

	QfMinN = newVal;
}


/**
 * 交流系统吸收最大无功
 */
void CmcDevAcSys::SetQinMax(double newVal){

	QinMax = newVal;
}


/**
 * 交流系统发出最大无功
 */
void CmcDevAcSys::SetQoutMax(double newVal){

	QoutMax = newVal;
}


/**
 * 交流电压极小值
 */
void CmcDevAcSys::SetUacExMin(double newVal){

	UacExMin = newVal;
}


/**
 * 交流电压最大值
 */
void CmcDevAcSys::SetUacMax(double newVal){

	UacMax = newVal;
}


/**
 * 交流电压最小值
 */
void CmcDevAcSys::SetUacMin(double newVal){

	UacMin = newVal;
}


/**
 * 交流侧额定电压
 */
void CmcDevAcSys::SetUacN(double newVal){

	UacN = newVal;
}