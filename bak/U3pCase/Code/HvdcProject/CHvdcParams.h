#pragma once

#include <string>

#include "CMyParams.h"

#include "CmcParams.h"
#include "CxbParams.h"
#include "C3pParams.h"

using namespace std;

class CHvdcParams : public CMyParams
{
protected:
	CHvdcParams(const CHvdcParams& theInstance) {};

	CHvdcParams() {};
	~CHvdcParams() {}

public:
	static void Init();
	//

};




