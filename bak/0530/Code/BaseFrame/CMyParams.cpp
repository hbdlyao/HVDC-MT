///////////////////////////////////////////////////////////
//  CMyParams.cpp
//  Implementation of the Class CMyParams
//  Created on:      22-3月-2017 18:23:54
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include <Windows.h>    
#include <iostream>  
#include "CMyParams.h"

string CMyParams::ExeFilePath = "ExeFilePath";

string CMyParams::PRJFilePath = "ExeFilePath";
string CMyParams::PRJFile = "PRJFile";

string CMyParams::ProjectName = "myProject";
int CMyParams::ProjectID = 1;

void CMyParams::Init()
{
	GetExeFilePath();

	PRJFilePath = ExeFilePath;

	//PRJFile = ExeFilePath + "dbf.txt";


}


void CMyParams::GetExeFilePath()
{
	char szModuleFilePath[MAX_PATH];
	char SaveResult[MAX_PATH];

	//获得当前执行文件的路径  
	int n = GetModuleFileNameA(0, szModuleFilePath, MAX_PATH);

	//将最后一个"\\"后的字符置为0
	szModuleFilePath[strrchr(szModuleFilePath, '\\') - szModuleFilePath + 1] = 0;

	//
	strcpy_s(SaveResult, szModuleFilePath);

	//
	ExeFilePath = (string)SaveResult;


}