#pragma once

#include <string>
#include "CMyParams.h"

using namespace std;

class CmcParams : public CMyParams
{
protected:
	CmcParams(const CmcParams& theInstance) {};

	CmcParams() {};
	~CmcParams() {}

public:
	static void Init();
	//

	static string dbfFile;	
	static int mcStationCount;

};




