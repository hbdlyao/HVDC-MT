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

	static int hMax; //г��������
	static double Frequence; //����Ƶ��

};




