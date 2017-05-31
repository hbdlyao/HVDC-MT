#pragma once

#include "gbHead_mcApp.h"
#include <string>

using namespace std;

class CmcMain
{
public:
	static void mcCalculate(string vCalName);
	static void mcCalculateNormal();
	static void mcCreateGrid(StrVector vStaNames);

	static void mcInit(string vDBFFile);
	static void mcLoad();
	static void mcClose();
	
	static void mcMain();
	static void DLLMain(string vDbfFile);
};