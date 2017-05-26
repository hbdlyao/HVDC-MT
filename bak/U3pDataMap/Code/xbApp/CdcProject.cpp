///////////////////////////////////////////////////////////
//  CdcProject.cpp
//  Implementation of the Class CDcProject
//  Created on:      23-3月-2017 20:17:20
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CdcProject.h"




CDcProject::CDcProject(){

}


CDcProject::CDcProject(CDcProject theCDcProject){

}


CDcProject::~CDcProject(){

}


/**
 * 直流工程端数
 */
int CDcProject::ConvertorCount(){

	get; set;
}


/**
 * 交流系统频率
 */
int CDcProject::Frequency(){

	get; set;
}


/**
 * 接地类型
 */
int CDcProject::GroudType(){

	get; set;
}


int CDcProject::ID(){

	get; set;
}


/**
 * 直流功率水平
 */
int CDcProject::PdLevel(){

	get; set;
}


/**
 * 工程类型（单极/双极）
 */
int CDcProject::PoleType(){

	get; set;
}


/**
 * 极线对大地/中性线电压
 */
int CDcProject::PoleVoltage(){

	get; set;
}


/**
 * 直流工程名称
 */
int CDcProject::ProjectName(){

	get; set;
}


/**
 * 直流工程类型
 */
int CDcProject::ProjectType(){

	get; set;
}


/**
 * 分接头控制类型
 */
int CDcProject::TapCtrlType(){

	get; set;
}


/**
 * 直流电压
 */
int CDcProject::Ud(){

	get; set;
}


/**
 * 直流电压水平
 */
int CDcProject::UdcLevel(){

	get; set;
}


/**
 * 额定直流电压
 */
int CDcProject::UdN(){

	get; set;
}


/**
 * 每极12脉动换流组数
 */
int CDcProject::Valor12Count(){

	get; set;
}


/**
 * 电阻类型（高阻/低阻）
 */
int CDcProject::ZrType(){

	get; set;
}