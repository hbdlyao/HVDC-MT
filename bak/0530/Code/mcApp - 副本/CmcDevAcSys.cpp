///////////////////////////////////////////////////////////
//  CmcDevAcSys.cpp
//  Implementation of the Class CmcDevAcSys
//  Created on:      22-4��-2017 14:51:16
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
 * ����ϵͳ��������޹�
 */
double CmcDevAcSys::GetQinMax(){

	return QinMax;
}


/**
 * ����ϵͳ��������޹�
 */
double CmcDevAcSys::GetQoutMax(){

	return QoutMax;
}


/**
 * ������ѹ��Сֵ
 */
double CmcDevAcSys::GetUacExMin(){

	return UacExMin;
}


/**
 * ������ѹ���ֵ
 */
double CmcDevAcSys::GetUacMax(){

	return UacMax;
}


/**
 * ������ѹ��Сֵ
 */
double CmcDevAcSys::GetUacMin(){

	return UacMin;
}


/**
 * ��������ѹ
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
 * ����ϵͳ��������޹�
 */
void CmcDevAcSys::SetQinMax(double newVal){

	QinMax = newVal;
}


/**
 * ����ϵͳ��������޹�
 */
void CmcDevAcSys::SetQoutMax(double newVal){

	QoutMax = newVal;
}


/**
 * ������ѹ��Сֵ
 */
void CmcDevAcSys::SetUacExMin(double newVal){

	UacExMin = newVal;
}


/**
 * ������ѹ���ֵ
 */
void CmcDevAcSys::SetUacMax(double newVal){

	UacMax = newVal;
}


/**
 * ������ѹ��Сֵ
 */
void CmcDevAcSys::SetUacMin(double newVal){

	UacMin = newVal;
}


/**
 * ��������ѹ
 */
void CmcDevAcSys::SetUacN(double newVal){

	UacN = newVal;
}