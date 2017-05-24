#pragma once

#include <string>
#include "CMyParams.h"

using namespace std;

class CxbParams : public CMyParams
{
protected:
	CxbParams(const CxbParams& theInstance) {};

	CxbParams() {};
	~CxbParams() {}

public:
	static void Init();
	//

	static string dbfFile;
	static int xbStationCount;

	static int hMax; //谐波最大次数
	static double Frequence; //基波频率

};




