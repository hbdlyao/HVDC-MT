#pragma once

#include <string>

using namespace std;

class CmcMain
{
public:
	static void mcTest(int vGnd);
	static void mcCalculate(string vCalName);
	static void mcCalculateNormal();
	static void mcCreateGrid();

	static void mcMain();
};
