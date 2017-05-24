///////////////////////////////////////////////////////////
//  CmcDevConvertor.cpp
//  Implementation of the Class CmcDevConvertor
//  Created on:      22-4月-2017 14:50:22
//  Original author: open2
///////////////////////////////////////////////////////////

#include "CmcDevConvertor.h"


/**
 * 额定触发角/关断角
 */
double CmcDevConvertor::GetAlpha_gamaN(){

	return Alpha_gamaN;
}


/**
 * 触发角/关断角最大值
 */
double CmcDevConvertor::GetAngleMax(){

	return AngleMax;
}


/**
 * 触发角/关断角最小值
 */
double CmcDevConvertor::GetAngleMin(){

	return AngleMin;
}


/**
 * 额定直流功率
 */
double CmcDevConvertor::GetPdN(){

	return PdN;
}


/**
 * 额定直流电压
 */
double CmcDevConvertor::GetUdN(){

	return UdN;
}


/**
 * 6脉动正向导通压降
 */
double CmcDevConvertor::GetUT(){

	return UT;
}


/**
 * 每极12脉动换流组数
 */
int CmcDevConvertor::GetValvor12Count(){

	return Valvor12Count;
}


double CmcDevConvertor::GetUdioN(){

	return UdioN;
}


/**
 * 阀侧额定电压
 */
double CmcDevConvertor::GetUvN(){

	return UvN;
}


/**
 * 直流电流,，计算得出
 */
double CmcDevConvertor::GetIdN(){

	return IdN;
}


/**
 * 换流器类型（整流逆变）
 */
int CmcDevConvertor::GetStationType(){

	return StationType;
}


/**
 * 换流器控制类型（定电流，定功率，定电压）
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
 * 测量站
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
 * 额定触发角/关断角
 */
void CmcDevConvertor::SetAlpha_gamaN(double newVal){

	Alpha_gamaN = newVal;
}


/**
 * 触发角/关断角最大值
 */
void CmcDevConvertor::SetAngleMax(double newVal){

	AngleMax = newVal;
}


/**
 * 触发角/关断角最小值
 */
void CmcDevConvertor::SetAngleMin(double newVal){

	AngleMin = newVal;
}


/**
 * 额定直流功率
 */
void CmcDevConvertor::SetPdN(double newVal){

	PdN = newVal;
}


/**
 * 额定直流电压
 */
void CmcDevConvertor::SetUdN(double newVal){

	UdN = newVal;
}


/**
 * 6脉动正向导通压降
 */
void CmcDevConvertor::SetUT(double newVal){

	UT = newVal;
}


/**
 * 每极12脉动换流组数
 */
void CmcDevConvertor::SetValvor12Count(int newVal){

	Valvor12Count = newVal;
}


void CmcDevConvertor::SetUdioN(double newVal){

	UdioN = newVal;
}


/**
 * 阀侧额定电压
 */
void CmcDevConvertor::SetUvN(double newVal){

	UvN = newVal;
}


/**
 * 直流电流,，计算得出
 */
void CmcDevConvertor::SetIdN(double newVal){

	IdN = newVal;
}


/**
 * 换流器类型（整流逆变）
 */
void CmcDevConvertor::SetStationType(int newVal){

	StationType = newVal;
}


/**
 * 换流器控制类型（定电流，定功率，定电压）
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
 * 测量站
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