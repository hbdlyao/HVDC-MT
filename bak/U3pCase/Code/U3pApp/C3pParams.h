#pragma once

#include "CMyParams.h"

class C3pParams : public CMyParams
{

public:
	static string dbfFile;
	static int    StationCount;

	static int hMax; //谐波最大次数
	static double Frequence; //基波频率

	static void Init();

protected:
	C3pParams(const C3pParams& theInstance){}
	C3pParams(){}
	~C3pParams(){}

};
