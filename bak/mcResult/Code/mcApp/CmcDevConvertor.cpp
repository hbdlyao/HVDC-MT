///////////////////////////////////////////////////////////
//  CmcDevConvertor.cpp
//  Implementation of the Class CmcDevConvertor
//  Created on:      22-4��-2017 14:50:22
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcDevConvertor.h"


/**
 * �������/�ضϽ�
 */
double CmcDevConvertor::GetAlpha_gamaN(){

	return Alpha_gamaN;
}


/**
 * ������/�ضϽ����ֵ
 */
double CmcDevConvertor::GetAngleMax(){

	return AngleMax;
}


/**
 * ������/�ضϽ���Сֵ
 */
double CmcDevConvertor::GetAngleMin(){

	return AngleMin;
}


/**
 * �ֱ������
 */
double CmcDevConvertor::GetPdN(){

	return PdN;
}


/**
 * �ֱ����ѹ
 */
double CmcDevConvertor::GetUdN(){

	return UdN;
}


/**
 * 6��������ͨѹ��
 */
double CmcDevConvertor::GetUT(){

	return UT;
}


/**
 * ÿ��12������������
 */
int CmcDevConvertor::GetValvor12Count(){

	return Valvor12Count;
}


double CmcDevConvertor::GetUdioN(){

	return UdioN;
}


/**
 * ������ѹ
 */
double CmcDevConvertor::GetUvN(){

	return UvN;
}


/**
 * ֱ������,������ó�
 */
double CmcDevConvertor::GetIdN(){

	return IdN;
}


/**
 * ���������ͣ�������䣩
 */
int CmcDevConvertor::GetStationType(){

	return StationType;
}


/**
 * �������������ͣ��������������ʣ�����ѹ��
 */
int CmcDevConvertor::GetStationCtrlType(){

	return StationCtrlType;
}
int CmcDevConvertor::GetStationCtrlTypeN(){

	return StationCtrlTypeN;
}

int CmcDevConvertor::GetIsGround(){

	return IsGround;
}


double CmcDevConvertor::GetAngleRef(){

	return AngleRef;
}


/**
 * ����վ
 */
string CmcDevConvertor::GetMeasureStation(){

	return MeasureStation;
}


double CmcDevConvertor::GetPconvN(){

	return PconvN;
}


double CmcDevConvertor::GetQconvN(){

	return QconvN;
}


double CmcDevConvertor::GetmiuN(){

	return miuN;
}


/**
 * �������/�ضϽ�
 */
void CmcDevConvertor::SetAlpha_gamaN(double newVal){

	Alpha_gamaN = newVal;
}


/**
 * ������/�ضϽ����ֵ
 */
void CmcDevConvertor::SetAngleMax(double newVal){

	AngleMax = newVal;
}


/**
 * ������/�ضϽ���Сֵ
 */
void CmcDevConvertor::SetAngleMin(double newVal){

	AngleMin = newVal;
}


/**
 * �ֱ������
 */
void CmcDevConvertor::SetPdN(double newVal){

	PdN = newVal;
}


/**
 * �ֱ����ѹ
 */
void CmcDevConvertor::SetUdN(double newVal){

	UdN = newVal;
}


/**
 * 6��������ͨѹ��
 */
void CmcDevConvertor::SetUT(double newVal){

	UT = newVal;
}


/**
 * ÿ��12������������
 */
void CmcDevConvertor::SetValvor12Count(int newVal){

	Valvor12Count = newVal;
}


void CmcDevConvertor::SetUdioN(double newVal){

	UdioN = newVal;
}


/**
 * ������ѹ
 */
void CmcDevConvertor::SetUvN(double newVal){

	UvN = newVal;
}


/**
 * ֱ������,������ó�
 */
void CmcDevConvertor::SetIdN(double newVal){

	IdN = newVal;
}


/**
 * ���������ͣ�������䣩
 */
void CmcDevConvertor::SetStationType(int newVal){

	StationType = newVal;
}


/**
 * �������������ͣ��������������ʣ�����ѹ��
 */
void CmcDevConvertor::SetStationCtrlType(int newVal){

	StationCtrlType = newVal;
}

void CmcDevConvertor::SetStationCtrlTypeN(int newVal){

	StationCtrlTypeN = newVal;
}

void CmcDevConvertor::SetIsGround(int newVal){

	IsGround = newVal;
}


void CmcDevConvertor::SetAngleRef(double newVal){

	AngleRef = newVal;
}


/**
 * ����վ
 */
void CmcDevConvertor::SetMeasureStation(string newVal){

	MeasureStation = newVal;
}


void CmcDevConvertor::SetPconvN(double newVal){

	PconvN = newVal;
}


void CmcDevConvertor::SetQconvN(double newVal){

	QconvN = newVal;
}


void CmcDevConvertor::SetmiuN(double newVal){

	miuN = newVal;
}