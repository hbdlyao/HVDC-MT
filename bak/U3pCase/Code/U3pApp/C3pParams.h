#pragma once

#include "CMyParams.h"

class C3pParams : public CMyParams
{

public:
	static string dbfFile;
	static int    StationCount;

	static int hMax; //г��������
	static double Frequence; //����Ƶ��

	static void Init();

protected:
	C3pParams(const C3pParams& theInstance){}
	C3pParams(){}
	~C3pParams(){}

};
